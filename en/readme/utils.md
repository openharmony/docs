# utils<a name="EN-US_TOPIC_0000001092539399"></a>


## Introduction<a name="section11660541593"></a>

The **utils** repository provides common enhanced APIs for development in C and C++.

**C++**

-   Enhanced APIs for operations related to files, paths, and strings
-   APIs related to the read-write lock, semaphore, timer, thread, and thread pool
-   APIs related to the security data container and data serialization
-   Error codes for each subsystem
-   Safe functions in C

**C**

-   Hardware Abstraction Layer (HAL) APIs for performing operations on standard files
-   APIs for internal functions, such as the timer

## Directory Structure<a name="section17271017133915"></a>

```
/utils
    ├── native                  # Utility class implementation at the native layer
    └── system                  # System-related predefined values and security policy configuration
```

## Repositories Involved<a name="section1249817110914"></a>

**utils subsystem**

utils

[utils\_native](https://gitee.com/openharmony/utils_native)

[utils\_native\_lite](https://gitee.com/openharmony/utils_native_lite)
