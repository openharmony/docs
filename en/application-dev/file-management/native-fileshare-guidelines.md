# Persisting Temporary Permissions (C/C++)

## When to Use

If an application accesses a file by using a Picker, the permission for accessing the file will be automatically revoked after the application exits or the device restarts. To retain the permission for accessing the file, you need to [persistent the authorization](file-persistPermission.md#when-to-use). You can use the **FileShare** module to persist permissions on files or folders based on their URI, activate or deactivate persistent permissions on files or folders, and check the persistent permissions.

## Available APIs

For details about the APIs, see [FileShare](../reference/apis-core-file-kit/file_share.md).

| API| Description|
| -------- | -------- |
| OH_FileShare_PersistPermission(const FileShare_PolicyInfo *policies, unsigned int policyNum, FileShare_PolicyErrorResult **result, unsigned int *resultNum) | Persists the permissions on files or folders.|
| OH_FileShare_RevokePermission(const FileShare_PolicyInfo *policies, unsigned int policyNum, FileShare_PolicyErrorResult **result, unsigned int *resultNum) | Revokes the permissions from files or folders.|
| OH_FileShare_ActivatePermission(const FileShare_PolicyInfo *policies, unsigned int policyNum, FileShare_PolicyErrorResult **result, unsigned int *resultNum) | Activates the persistent permissions on files or folders.|
| OH_FileShare_DeactivatePermission(const FileShare_PolicyInfo *policies, unsigned int policyNum, FileShare_PolicyErrorResult **result, unsigned int *resultNum) | Deactivates the persistent permissions on files or folders.|
| OH_FileShare_CheckPersistentPermission(const FileShare_PolicyInfo *policies, unsigned int policyNum, bool **result, unsigned int *resultNum) | Checks the persistent permissions on files or folders.|
| OH_FileShare_ReleasePolicyErrorResult(FileShare_PolicyErrorResult *errorResult, unsigned int resultNum) | Releases the memory allocated for **FileShare_PolicyErrorResult**.|

## Constraints

- Before using the **FileShare** APIs, check that your device has SystemCapability.FileManagement.AppFileService.FolderAuthorization.

- To call **FileShare** APIs, the application must have the ohos.permission.FILE_ACCESS_PERSIST permission. For details about how to request the permission, see [Workflow for Using Permissions](../security/AccessToken/determine-application-mode.md).

## How to Develop

The following example describes how to use the `FileShare` APIs.

**Adding the Dynamic Link Library**

Add the following library to **CMakeLists.txt**.

```txt
target_link_libraries(sample PUBLIC libohfileshare.so)
```

**Including Header Files**

```c++
#include <filemanagement/fileshare/oh_file_share.h>
#include <iostream>
```
1. Create a **FileShare_PolicyInfo** instance, and use **OH_FileShare_PersistPermission** to persist the permissions on files based on their URI. The maximum value of **policyNum** is **500**.
    ```c++
    static const uint32_t POLICY_NUM = 2;
    char strTestPath1[] = "file://com.example.fileshare/data/storage/el2/base/files/test1.txt";
    char strTestPath2[] = "file://com.example.fileshare/data/storage/el2/base/files/test2.txt";
    FileShare_PolicyInfo policy[POLICY_NUM] = {
        {strTestPath1, static_cast<unsigned int>(strlen(strTestPath1)), FileShare_OperationMode::READ_MODE},
        {strTestPath2, static_cast<unsigned int>(strlen(strTestPath2)), FileShare_OperationMode::WRITE_MODE}};
    FileShare_PolicyErrorResult* result = nullptr;
    uint32_t resultNum = 0;
    auto ret = OH_FileShare_PersistPermission(policy, POLICY_NUM, &result, &resultNum);
    if (ret != ERR_OK) {
        if (ret == ERR_EPERM && result != nullptr) {
            for(uint32_t i = 0; i < resultNum; i++) {
                std::cout << "error uri: " <<  result[i].uri << std::endl;
                std::cout << "error code: " <<  result[i].code << std::endl;
                std::cout << "error message: " << result[i].message << std::endl;
            }
        }
    }
    OH_FileShare_ReleasePolicyErrorResult(result, resultNum);
    ```
2. Call **OH_FileShare_ActivatePermission** to activate the persistent permissions on files. The maximum value of **policyNum** is **500**.
    ```c++
    auto ret = OH_FileShare_ActivatePermission(policy, POLICY_NUM, &result, &resultNum);
    if (ret != ERR_OK) {
        if (ret == ERR_EPERM && result != nullptr) {
            for(uint32_t i = 0; i < resultNum; i++) {
                std::cout << "error uri: " <<  result[i].uri << std::endl;
                std::cout << "error code: " <<  result[i].code << std::endl;
                std::cout << "error message: " << result[i].message << std::endl;
            }
        }
    }
    OH_FileShare_ReleasePolicyErrorResult(result, resultNum);
    ```
3. Call **OH_FileShare_DeactivatePermission** to deactivate the persistent permissions on files. The maximum value of **policyNum** is **500**.
    ```c++
    auto ret = OH_FileShare_DeactivatePermission(policy, POLICY_NUM, &result, &resultNum);
    if (ret != ERR_OK) {
        if (ret == ERR_EPERM && result != nullptr) {
            for(uint32_t i = 0; i < resultNum; i++) {
                std::cout << "error uri: " <<  result[i].uri << std::endl;
                std::cout << "error code: " <<  result[i].code << std::endl;
                std::cout << "error message: " << result[i].message << std::endl;
            }
        }
    }
    OH_FileShare_ReleasePolicyErrorResult(result, resultNum);
    ```
4. Call **OH_FileShare_RevokePermission** to revoke the persistent permissions from files. The maximum value of **policyNum** is **500**.
    ```c++
    auto ret = OH_FileShare_RevokePermission(policy, POLICY_NUM, &result, &resultNum);
    if (ret != ERR_OK) {
        if (ret == ERR_EPERM && result != nullptr) {
            for(uint32_t i = 0; i < resultNum; i++) {
                std::cout << "error uri: " <<  result[i].uri << std::endl;
                std::cout << "error code: " <<  result[i].code << std::endl;
                std::cout << "error message: " << result[i].message << std::endl;
            }
        }
    }
    OH_FileShare_ReleasePolicyErrorResult(result, resultNum);
    ```
5. Call **OH_FileShare_CheckPersistentPermission** to check the persistent permissions on files. The maximum value of **policyNum** is **500**.
    ```c++
    bool *result = nullptr;
    auto ret = OH_FileShare_CheckPersistentPermission(policy, POLICY_NUM, &result, &resultNum);
    if (result != nullptr && resultNum > 0) {
        for(uint32_t i = 0; i < resultNum && resultNum <= POLICY_NUM; i++) {
            std::cout << "uri: " <<  policy[i].uri << std::endl;
            std::cout << "result: " <<  result[i] << std::endl;
        }
    }
    std::cout << "retCode: " <<  ret << std::endl;
    free(result);
    ```
