# Persisting Temporary Permissions (C/C++)

<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @lvzhenjie; @hongjin-li_admin-->
<!--Designer: @chenxi0605; @JerryH1011-->
<!--Tester: @zsyztt; @yue-ye2; @fuwei-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=a4bb221ea8dcccf781d5793faa6c8f62723e3e12 translatedAt=2026-08-01T07:27:07.885Z pushedAt=2026-08-01T10:19:01.673Z -->

## When to Use

If an application accesses a file by using Picker, the permission for accessing the file will be automatically invalidated after the application exits or the device restarts. To retain the permission for accessing the file, you need to [persist the permission](file-persistPermission.md#when-to-use). You can use the **FileShare** module to manage persistent permissions on files or directories based on their URIs, including activating, deactivating, and checking these permissions.

## Available APIs

For details about the APIs, see [oh_file_uri.h](../reference/apis-core-file-kit/capi-oh-file-share-h.md).

| API| Description|
| -------- | -------- |
| OH_FileShare_PersistPermission(const FileShare_PolicyInfo *policies, unsigned int policyNum, FileShare_PolicyErrorResult **result, unsigned int *resultNum) | Persists the permissions on files or directories.|
| OH_FileShare_RevokePermission(const FileShare_PolicyInfo *policies, unsigned int policyNum, FileShare_PolicyErrorResult **result, unsigned int *resultNum) | Revokes the permissions from files or directories.|
| OH_FileShare_ActivatePermission(const FileShare_PolicyInfo *policies, unsigned int policyNum, FileShare_PolicyErrorResult **result, unsigned int *resultNum) | Enables multiple persistently authorized file or directory URIs. |
| OH_FileShare_DeactivatePermission(const FileShare_PolicyInfo *policies, unsigned int policyNum, FileShare_PolicyErrorResult **result, unsigned int *resultNum) | Deactivates the persistent permissions on files or directories.|
| OH_FileShare_CheckPersistentPermission(const FileShare_PolicyInfo *policies, unsigned int policyNum, bool **result, unsigned int *resultNum) | Checks the persistent permissions on files or directories.|
| OH_FileShare_ReleasePolicyErrorResult(FileShare_PolicyErrorResult *errorResult, unsigned int resultNum) | Releases the memory allocated for **FileShare_PolicyErrorResult**.|

## Constraints

- Before using the **FileShare** APIs, check that your device has SystemCapability.FileManagement.AppFileService.FolderAuthorization.

- Before calling file sharing APIs, you must request the permission: [ohos.permission.FILE_ACCESS_PERSIST](../security/AccessToken/restricted-permissions.md#ohospermissionfile_access_persist). For details about how to request permissions, see [Workflow for Requesting Permissions](../security/AccessToken/determine-application-mode.md).

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

1. Create a **FileShare_PolicyInfo** instance, call the **OH_FileShare_PersistPermission** API, and set the persistence permission for the URI. The maximum limit of the input parameter **policyNum** is 500.

   <!-- @[persist_permission_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/UserFile/FileShareDevelopment_C/entry/src/main/cpp/napi_init.cpp) -->    

   ``` C++
   static const uint32_t policyNum = 2;
   char strTestPath1[] = "file://com.example.fileshare/data/storage/el2/base/files/test1.txt";
   char strTestPath2[] = "file://com.example.fileshare/data/storage/el2/base/files/test2.txt";
   FileShare_PolicyInfo policy[policyNum] = {
       {strTestPath1, static_cast<unsigned int>(strlen(strTestPath1)), FileShare_OperationMode::READ_MODE},
       {strTestPath2, static_cast<unsigned int>(strlen(strTestPath2)), FileShare_OperationMode::WRITE_MODE}};
   FileShare_PolicyErrorResult* result = nullptr;
   uint32_t resultNum = 0;
   napi_value napiResult;
   std::string resultStr;
   auto ret = OH_FileShare_PersistPermission(policy, policyNum, &result, &resultNum);
   if (ret != ERR_OK) {
       if (ret == ERR_EPERM && result != nullptr) {
           for (uint32_t i = 0; i < resultNum; i++) {
               std::cout << "error uri: " <<  result[i].uri << std::endl;
               std::cout << "error code: " <<  result[i].code << std::endl;
               std::cout << "error message: " << result[i].message << std::endl;
               // ...
           }
       }
   }
   OH_FileShare_ReleasePolicyErrorResult(result, resultNum);
   ```

2. Call **OH_FileShare_ActivatePermission** to activate the persistent permissions on files. The maximum value of **policyNum** is **500**.

   <!-- @[activate_permission_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/UserFile/FileShareDevelopment_C/entry/src/main/cpp/napi_init.cpp) -->    

   ``` C++
   auto ret = OH_FileShare_ActivatePermission(policy, policyNum, &result, &resultNum);
   if (ret != ERR_OK) {
       if (ret == ERR_EPERM && result != nullptr) {
           for (uint32_t i = 0; i < resultNum; i++) {
               std::cout << "error uri: " <<  result[i].uri << std::endl;
               std::cout << "error code: " <<  result[i].code << std::endl;
               std::cout << "error message: " << result[i].message << std::endl;
               // ...
           }
       }
   }
   OH_FileShare_ReleasePolicyErrorResult(result, resultNum);
   ```

3. Call **OH_FileShare_DeactivatePermission** to deactivate the persistent permissions on files. The maximum value of **policyNum** is **500**.

   <!-- @[deactivate_permission_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/UserFile/FileShareDevelopment_C/entry/src/main/cpp/napi_init.cpp) -->    

   ``` C++
   auto ret = OH_FileShare_DeactivatePermission(policy, policyNum, &result, &resultNum);
   if (ret != ERR_OK) {
       if (ret == ERR_EPERM && result != nullptr) {
           for (uint32_t i = 0; i < resultNum; i++) {
               std::cout << "error uri: " <<  result[i].uri << std::endl;
               std::cout << "error code: " <<  result[i].code << std::endl;
               std::cout << "error message: " << result[i].message << std::endl;
               // ...
           }
       }
   }
   OH_FileShare_ReleasePolicyErrorResult(result, resultNum);
   ```

4. Call **OH_FileShare_RevokePermission** to revoke the persistent permissions from files. The maximum value of **policyNum** is **500**.

   <!-- @[revoke_permission_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/UserFile/FileShareDevelopment_C/entry/src/main/cpp/napi_init.cpp) -->    

   ``` C++
   auto ret = OH_FileShare_RevokePermission(policy, policyNum, &result, &resultNum);
   if (ret != ERR_OK) {
       if (ret == ERR_EPERM && result != nullptr) {
           for (uint32_t i = 0; i < resultNum; i++) {
               std::cout << "error uri: " <<  result[i].uri << std::endl;
               std::cout << "error code: " <<  result[i].code << std::endl;
               std::cout << "error message: " << result[i].message << std::endl;
               // ...
           }
       }
   }
   OH_FileShare_ReleasePolicyErrorResult(result, resultNum);
   ```

5. Call **OH_FileShare_CheckPersistentPermission** to check the persistent permissions on files. The maximum value of **policyNum** is **500**.

   <!-- @[check_persistent_permission_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/UserFile/FileShareDevelopment_C/entry/src/main/cpp/napi_init.cpp) -->    

   ``` C++
   bool *result = nullptr;
   auto ret = OH_FileShare_CheckPersistentPermission(policy, policyNum, &result, &resultNum);
   if (ret != ERR_OK) {
       if (ret == ERR_EPERM && result != nullptr) {
           for (uint32_t i = 0; i < resultNum && resultNum <= policyNum; i++) {
               std::cout << "uri: " <<  policy[i].uri << std::endl;
               std::cout << "result: " <<  result[i] << std::endl;
               // ...
           }
       }
   }
   std::cout << "retCode: " <<  ret << std::endl;
   free(result);
   ```