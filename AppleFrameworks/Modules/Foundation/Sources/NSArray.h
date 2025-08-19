//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Foundation/NSArray.hpp
//
// Copyright 2020-2024 Apple Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#pragma once

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#include "NSObject.hpp"
#include "NSEnumerator.h"

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

namespace NS
{
    class Array : public Copying<Array>
    {
    public:
        static Array* array();
        static Array* array(const Object* pObject);
        static Array* array(const Object* const* pObjects, UInteger count);

        static Array* alloc();

        Array*        init();
        Array*        init(const Object* const* pObjects, UInteger count);
        Array*        init(const class Coder* pCoder);

        template <class _Object = Object>
        _Object*            object(UInteger index) const;
        UInteger            count() const;
        Enumerator<Object>* objectEnumerator() const;
    };
}
