# OpenHarmony SELinux APIs

## Introduction

This topic describes the APIs provided to update the SELinux labels of files or directories, and how to use the APIs.

## Available APIs

All the SELinux APIs are native C APIs that provide underlying capabilities only. These APIs are not available to applications.  

| API| Description| Parameter Description|
| --------- | ---------- | ---------- |
| int **Restorecon**(const char *path); | Updates the label of a single file or directory without recursively traversing subdirectories.<br>If **0** is returned, the operation is successful. Otherwise, the operation fails.| **path** indicates the pointer to the absolute path of the target file or directory.|
| int **RestoreconRecurse**(const char *path); | Updates the file or directory label for a single thread, and recursively traverses and updates the labels of subdirectories and their files.<br>If **0** is returned, the operation is successful. Otherwise, the operation fails.| **path** indicates the pointer to the absolute path of the target file or directory.|
| int **RestoreconRecurseParallel**(const char *path, unsigned int nthreads); | Updates the file or directory labels for multiple threads, and recursively traverses and updates the labels of subdirectories and their files.<br>If **0** is returned, the operation is successful. Otherwise, the operation fails.| **path** indicates the pointer to the absolute path of the target file or directory.<br>**nthreads** indicates the number of threads. |
| int **RestoreconRecurseForce**(const char *path); | Forcibly updates the file or directory label for a single thread, and recursively traverses and updates the labels of subdirectories and their files.<br>If **0** is returned, the operation is successful. Otherwise, the operation fails.| **path** indicates the pointer to the absolute path of the target file or directory.|
| int **RestoreconFromParentDir**(const char *path); | Updates the label of the directory based on its parent directory for a single thread, and recursively traverses and updates the entire directory.<br>If **0** is returned, the operation is successful. Otherwise, the operation fails.| **path** indicates the pointer to the absolute path of the parent directory.|

## How to Develop

1. Add the dependency for compilation.

    ```text
    external_deps += [ "selinux_adapter:librestorecon" ]
    ```

2. Include the header file.

    ```cpp
    #include "policycoreutils.h"
    ```

3. Call the APIs.

    For example, call **Restorecon** to update the labe of **/data**.
    ```cpp
    // Update the label of /data.
    int ret = Restorecon("/data");
    ```

