# FileShare开发指导

## 场景介绍

FileShare提供了支持基于URI的文件及目录授权及权限持久化、权限激活、权限查询等接口

## 接口说明

| 接口名称 | 描述 |
| -------- | -------- |
| OH_FileShare_PersistPermission(const FileShare_PolicyInfo *policies, unsigned int policyNum, FileShare_PolicyErrorResult **result, unsigned int *resultNum) | 设置URI的持久化授权|
| OH_FileShare_RevokePermission(const FileShare_PolicyInfo *policies, unsigned int policyNum, FileShare_PolicyErrorResult **result, unsigned int *resultNum) | 撤销已经授权的URI持久化权限 |
| OH_FileShare_ActivatePermission(const FileShare_PolicyInfo *policies, unsigned int policyNum, FileShare_PolicyErrorResult **result, unsigned int *resultNum) | 激活启用已授权过的URI |
| OH_FileShare_DeactivatePermission(const FileShare_PolicyInfo *policies, unsigned int policyNum, FileShare_PolicyErrorResult **result, unsigned int *resultNum) | 停止已启用授权URI的访问权限 |
| OH_FileShare_CheckPersistentPermission(const FileShare_PolicyInfo *policies, unsigned int policyNum, bool **result, unsigned int *resultNum) | 检查URI持久化权限 |
| OH_FileShare_ReleasePolicyErrorResult(FileShare_PolicyErrorResult *errorResult, unsigned int resultNum) | 释放FileShare_PolicyErrorResult内存 |
## 开发步骤

以下步骤描述了如何使用`FileShare`提供的Native API接口

**添加动态链接库**

CMakeLists.txt中添加以下lib。

```txt
liboh_file_share.so
```

**头文件**

```c++
#include "filemanagement/fileshare/oh_file_share.h"
#include "filemanagement/common/errorcode.h"
#include <iostream>
#include <string.h>
```
1. **创建FileShare_PolicyInfo实例,调用OH_FileShare_PersistPermission接口，设置URI的持久化授权**。
    ```c++
    static const uint32_t POLICY_NUM = 2;
    char strTestPath1[] = "file://com.example.fileshare/data/storage/el2/base/files/test1.txt";
    char strTestPath2[] = "file://com.example.fileshare/data/storage/el2/base/files/test2.txt";
    FileShare_PolicyInfo policy[POLICY_NUM] = { 
        {strTestPath1, strlen(strTestPath1), FileShare_OperationMode::READ_MODE},
        {strTestPath2, strlen(strTestPath2), FileShare_OperationMode::WRITE_MODE}};
    FileShare_PolicyErrorResult* result;
    uint32_t resultNum = 0;
    auto ret = OH_FileShare_PersistPermission(policy, POLICY_NUM, &result, &resultNum);
    if (ret != ERR_OK) {
        if (ret == 13900001 && result != nullptr) {
            for(uint32_t i = 0; i < resultNum; i++) {
                std::cout << "error uri: " <<  result[i].uri << std::endl;
                std::cout << "error code: " <<  result[i].code << std::endl;
                std::cout << "error message: " << result[i].message << std::endl;
            }
        }
        OH_FileShare_ReleasePolicyErrorResult(result, resultNum);
    }
    ```
2. **调用OH_FileShare_ActivatePermission接口，激活启用已授权过的URI**。
    ```c++
    int ret = OH_FileShare_ActivatePermission(policy, POLICY_NUM, &result, &resultNum);
    if (ret != ERR_OK) {
        if (ret == 13900001 && result != nullptr) {
            for(uint32_t i = 0; i < resultNum; i++) {
                std::cout << "error uri: " <<  result[i].uri << std::endl;
                std::cout << "error code: " <<  result[i].code << std::endl;
                std::cout << "error message: " << result[i].message << std::endl;
            }
        }
        OH_FileShare_ReleasePolicyErrorResult(result, resultNum);
    }
    ```
3. **调用OH_FileShare_DeactivatePermission接口，停止已启用授权过URI的访问权限**。
    ```c++
    int ret = OH_FileShare_DeactivatePermission(policy, POLICY_NUM, &result, &resultNum);
    if (ret != ERR_OK) {
        if (ret == 13900001 && result != nullptr) {
            for(uint32_t i = 0; i < resultNum; i++) {
                std::cout << "error uri: " <<  result[i].uri << std::endl;
                std::cout << "error code: " <<  result[i].code << std::endl;
                std::cout << "error message: " << result[i].message << std::endl;
            }
        }
        OH_FileShare_ReleasePolicyErrorResult(result, resultNum);
    }
    ```
4. **调用OH_FileShare_RevokePermission接口，撤销已经授权的URI持久化权限**。
    ```c++
    int ret = OH_FileShare_RevokePermission(policy, POLICY_NUM, &result, &resultNum);
    if (ret != ERR_OK) {
        if (ret == 13900001 && result != nullptr) {
            for(uint32_t i = 0; i < resultNum; i++) {
                std::cout << "error uri: " <<  result[i].uri << std::endl;
                std::cout << "error code: " <<  result[i].code << std::endl;
                std::cout << "error message: " << result[i].message << std::endl;
            }
        }
        OH_FileShare_ReleasePolicyErrorResult(result, resultNum);
    }
    ```
5. **调用OH_FileShare_CheckPersistentPermission接口，检查URI持久化权限**。
    ```c++
    bool *result;
    int ret = OH_FileShare_CheckPersistentPermission(policy, POLICY_NUM, &result, &resultNum);
    if (ret != ERR_OK && result != nullptr) {
        for(uint32_t i = 0; i < resultNum && resultNum <= POLICY_NUM; i++) {
            std::cout << "uri: " <<  policy[i].uri << std::endl;
            std::cout << "result: " <<  result[i] << std::endl;
        }
    }
    free(result);
    ```