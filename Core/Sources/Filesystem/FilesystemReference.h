#pragma once

#include "Process/Process.h"
#include "Templates/SmartPointer/SharedPointer.h"
#include "Templates/String/String.h"
#include "Templates/Map.h"
#include "Filesystem/Path.h"
#include "Threading/CriticalSection.h"
#include "Threading/ScopeLock.h"
#include <type_traits>

template<
    typename TItem,
    typename TItemPtr = TSharedPtr<TItem>
>
class TFilesystemReference
{
    inline static SCriticalSection _allReferencesCS;
    inline static TMap<CString, TItemPtr> _allReferences;
    
protected:
    CString _path;
    CString _relativePath;
    CString _name;
    bool _bExists;

    inline TFilesystemReference(const CString& InPath)
    {
        _path = GPath.GetFullPath(InPath);

        CString WorkingPath = GProcess.GetExecutableContainerPath();

        if (_path == WorkingPath)
        {
            _relativePath = ".";
        }
        else if (_path.StartsWith(WorkingPath))
        {
            _relativePath = _path.Replace(*WorkingPath, "");
            _relativePath = _relativePath.SubString(1, _relativePath.Len());
        }
        else
        {
            _relativePath = _path;
        }

        _name = GPath.LastPathComponent(_path);
    }

    inline virtual ~TFilesystemReference() = default;

    inline virtual void UpdateExistance() = 0;

    inline static TItemPtr Get(const CString& InPath, const TFunction<TItemPtr(const CString&)>& FactoryFunction)
    {
        CString Path = InPath;

        if (GPath.GetPathRoot(InPath) == "")
        {
            Path = GPath.Combine({ GProcess.GetExecutableContainerPath(), Path });
        }

        Path = GPath.GetFullPath(Path);

        {
            SScopeLock Lock(_allReferencesCS);

            if (TItemPtr* Item = _allReferences.Find(Path))
            {
                return *Item;
            }

            TItemPtr NewReference = FactoryFunction(Path);
            _allReferences.Add(Path, NewReference);
            return NewReference;
        }
    }

public:
    inline const CString& Path() const
    {
        return _path;
    }

    inline const CString& RelativePath() const
    {
        return _relativePath;
    }

    inline const CString& Name() const
    {
        return _name;
    }

    inline bool Exists() const
    {
        return _bExists;
    }

    friend struct SDirectoryRef;
    friend struct SFileRef;
};