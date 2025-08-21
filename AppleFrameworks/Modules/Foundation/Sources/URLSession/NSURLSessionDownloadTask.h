#pragma once

#include "NSObject.hpp"

#include "NSURLSessionDataTask.h"

namespace NS
{
    class URLSessionDownloadTask : public Copying<URLSessionDownloadTask, URLSessionTask>
    {

    };
}