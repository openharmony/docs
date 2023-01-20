# commonlibrary<a name="EN-US_TOPIC_0000001092539399"></a>


## Introduction<a name="section11660541593"></a>

The **commonlibrary** subsystem stores basic OpenHarmony components which provides common enhanced APIs for development in C, C++ and JS that are commonly used by OpenHarmony service subsystems and upper-layer applications. Including repositories:
```
/commonlibrary
    ├── c_utils                  # Enhanced basic C/C++ library for developers 
    ├── ets_utils                # Enhanced basic JS library for developers
    └── utils_lite               # Basic tools for liteOS, including C and JS.
```
 Features provided by every repositories are listed here:

**c_utils**

-   Enhanced APIs for operations related to files, paths, and strings
-   APIs related to the read-write lock, semaphore, timer, thread, and thread pool
-   APIs related to the security data container and data serialization
-   Error codes for each subsystem
-   Safe functions in C

**ets_utils**

-   JSAPIs for operation of URI, URL and xml
-   JSAPIs for character encoder and decoder
-   JSAPIs for operation of process
-   Multithreading ability in JS

**utils_lite**

-   Hardware Abstraction Layer (HAL) APIs for performing operations on standard files
-   APIs for internal functions, such as the timer
## Related Documents<a name="section17271017133915"></a>
[Commonlibrary Development Guidelines](https://gitee.com/openharmony/docs/blob/master/en/device-dev/subsystems/subsys-utils-guide.md)

## Repositories Involved<a name="section1249817110914"></a>

**commonlibrary subsystem**

[commonlibrary\_c\_utils](https://gitee.com/openharmony/commonlibrary_c_utils)

[commonlibrary\_ets\_utils](https://gitee.com/openharmony/commonlibrary_ets_utils)

[commonlibrary\_utils\_lite](https://gitee.com/openharmony/commonlibrary_utils_lite)
