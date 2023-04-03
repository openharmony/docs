# Utils

## Introduction

Utils provides OpenHarmony basic components, which provide enhanced C, C++, and JS APIs for OpenHarmony service subsystems and upper-layer applications. Utils provides the following components in **/commonlibrary**:
```
/commonlibrary
    ├── c_utils                  # c and c++ utils.
    ├── ets_utils                # extended TypeScript (eTS) utils.
    └── utils_lite               # Utils in c and JS for LiteOS.
```
The following lists the functions provided by each utils.

**c_utils**

-   Enhanced APIs for operations related to files, paths, and strings
-   APIs for read/write locks, semaphores, timers, threads, and thread pools
-   APIs for security data containers and data serialization
-   Error codes for each subsystem

**ets_utils**

-   JS APIs for URI, URL, and XML operations
-   JS APIs for string encoding and decoding
-   JS APIs for process-related operations
-   Multithreading capability in JS

**utils_lite**

-   Hardware Abstraction Layer (HAL) APIs for file operations
-   APIs for internal functions, such as the timer

## Related Documents
[Utils Development Guide](https://gitee.com/openharmony/docs/blob/master/en/device-dev/subsystems/subsys-utils-guide.md)

## Repositories Involved

**Utils**


[commonlibrary\_c\_utils](https://gitee.com/openharmony/commonlibrary_c_utils)

[commonlibrary\_ets\_utils](https://gitee.com/openharmony/commonlibrary_ets_utils)

[commonlibrary\_utils\_lite](https://gitee.com/openharmony/commonlibrary_utils_lite)
