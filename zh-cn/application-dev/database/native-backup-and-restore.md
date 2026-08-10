# 数据库备份与恢复 (C/C++)
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @baijidong-->
<!--Designer: @htt1997-->
<!--Tester: @logic42-->
<!--Adviser: @ge-yafang-->

## 场景介绍

如果操作或存储的过程中出现问题，开发者可以使用恢复功能，将数据库恢复到之前的状态，重新对数据库进行操作。

在数据库被篡改、删除、或者设备断电场景下，数据库可能会因为数据丢失、数据损坏、脏数据等而不可用，可以通过数据库的备份恢复能力将数据库恢复至可用状态。

当前仅支持使用关系型数据库（C/C++）进行备份与恢复。

## 开发步骤

数据库操作或者存储过程中，有可能会因为各种原因发生非预期的数据库异常的情况，可以根据需要使用关系型数据库的备份能力，以便在数据库异常时，可靠高效地恢复数据保证业务数据正常使用。

1. CMakeLists.txt中添加以下lib。

    ```txt
    libnative_rdb_ndk.z.so
    ```

2. 导入头文件。

    <!-- @[encryption_include](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkData/RelationalStore/NativeDataEncryption/entry/src/main/cpp/napi_init.cpp) --> 
    
    ``` C++
    #include <cstring>
    #include "database/rdb/relational_store.h"
    #include "hilog/log.h"
    ```


3. 调用OH_Rdb_Backup接口实现数据库备份。

    <!-- @[BackupRdbStore](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkData/RelationalStore/NativeDataEncryption/entry/src/main/cpp/napi_init.cpp) -->
    
    ``` C++
    OH_Rdb_ConfigV2 *config = OH_Rdb_CreateConfig();
    OH_Rdb_SetDatabaseDir(config, "/data/storage/el2/database");
    OH_Rdb_SetArea(config, RDB_SECURITY_AREA_EL2);
    OH_Rdb_SetStoreName(config, "RdbTest.db");
    OH_Rdb_SetSecurityLevel(config, OH_Rdb_SecurityLevel::S3);
    OH_Rdb_SetBundleName(config, "com.example.nativedemo");
    int errCode = 0;
    OH_Rdb_Store *store = OH_Rdb_CreateOrOpen(config, &errCode);
    // 备份数据库
    int result = OH_Rdb_Backup(store, "/data/storage/el2/database/RdbTest_bak.db");
    OH_Rdb_CloseStore(store);
    store = nullptr;
    OH_Rdb_DestroyConfig(config);
    config = nullptr;
    ```



4. 调用OH_Rdb_Restore接口实现数据库恢复。

    <!-- @[rdb_OH_Rdb_Restore](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkData/RelationalStore/NativeDataEncryption/entry/src/main/cpp/napi_init.cpp) -->
    
    ``` C++
    OH_Rdb_ConfigV2 *config = OH_Rdb_CreateConfig();
    OH_Rdb_SetDatabaseDir(config, "/data/storage/el2/database");
    OH_Rdb_SetArea(config, RDB_SECURITY_AREA_EL2);
    OH_Rdb_SetStoreName(config, "RdbRestoreTest.db");
    OH_Rdb_SetSecurityLevel(config, OH_Rdb_SecurityLevel::S3);
    OH_Rdb_SetBundleName(config, "com.example.nativedemo");
    int errCode = 0;
    OH_Rdb_Store *store = OH_Rdb_CreateOrOpen(config, &errCode);
    // 恢复数据库
    int result2 =
        OH_Rdb_Restore(store, "/data/storage/el2/database/RdbTest_bak.db");
    OH_Rdb_CloseStore(store);
    store = nullptr;
    OH_Rdb_DestroyConfig(config);
    config = nullptr;
    ```



5. 调用OH_Rdb_RegisterCorruptedHandler接口注册数据库异常处理。

    从API version 22开始，支持注册数据库异常处理，开发者可根据需要调用OH_Rdb_RegisterCorruptedHandler接口注册数据库异常处理。

    ```c
    // 数据库异常后处理的回调函数。
    // context为OH_Rdb_RegisterCorruptedHandler调用时传入的指针，生命周期由业务自身管理
    // config为OH_Rdb_RegisterCorruptedHandler调用时拷贝的临时变量，不可在回调函数外部使用
    // store为发生异常的DB句柄，如果DB无法打开则为空指针，注意判空。该指针由系统产生，回调函数结束后即刻释放，不可在回调函数外部使用
    void CorruptedHandler(void *context, OH_Rdb_ConfigV2 *config, OH_Rdb_Store *store)
    {
        const char* restorePath = "/data/storage/el2/database/RdbTest_bak.db";
        // store为空代表非DB文件或者DB文件彻底异常无法打开
        if (store == nullptr) {
            OH_Rdb_DeleteStoreV2(config);
            // 重新创建数据库，如果有备库可以重建后调用恢复接口
            return;
        }
        // 通过store句柄使用备库进行数据库恢复
        int errCode = OH_Rdb_Restore(store, restorePath);
        // restore在有其它接口占用写连接时会失败，建议等待其它调用结束后再调用
        if (errCode != 0) {
            OH_LOG_ERROR(LOG_APP, "restore failed! errCode is: %{public}d", errCode);
            // 等待其它线程调用结束，进行重试。不建议重试次数过多或等待时间过长，避免占用太多系统资源。
            errCode = OH_Rdb_Restore(store, restorePath);
            // 或采用标记的方式标记数据库异常，后续在进程重启或业务空闲时进行恢复
        }
    }
    OH_Rdb_ConfigV2* config3 = OH_Rdb_CreateConfig();
    OH_Rdb_SetDatabaseDir(config3, "/data/storage/el2/database");
    OH_Rdb_SetArea(config3, RDB_SECURITY_AREA_EL2);
    OH_Rdb_SetStoreName(config3, "RdbRestoreTest.db");
    OH_Rdb_SetSecurityLevel(config3, OH_Rdb_SecurityLevel::S3);
    OH_Rdb_SetBundleName(config3, "com.example.nativedemo");
    int errCode3 = 0;
    OH_Rdb_Store *store3 = OH_Rdb_CreateOrOpen(config3, &errCode3);

    // 备份数据库
    int result = OH_Rdb_Backup(store3, "/data/storage/el2/database/RdbTest_bak.db");

    void *context = nullptr;
    Rdb_CorruptedHandler handler = CorruptedHandler;
    // 注册数据库异常处理
    OH_Rdb_RegisterCorruptedHandler(config3, context, handler);
    ```

6. 调用OH_Rdb_UnregisterCorruptedHandler接口取消注册数据库异常处理。

    从API version 22开始，支持取消注册数据库异常处理，开发者可根据需要调用OH_Rdb_UnregisterCorruptedHandler接口取消注册数据库异常处理。

    ```c
    OH_Rdb_ConfigV2* config4 = OH_Rdb_CreateConfig();
    OH_Rdb_SetDatabaseDir(config4, "/data/storage/el2/database");
    OH_Rdb_SetArea(config4, RDB_SECURITY_AREA_EL2);
    OH_Rdb_SetStoreName(config4, "RdbRestoreTest.db");
    OH_Rdb_SetSecurityLevel(config4, OH_Rdb_SecurityLevel::S3);
    OH_Rdb_SetBundleName(config4, "com.example.nativedemo");
    int errCode4 = 0;
    OH_Rdb_Store *store4 = OH_Rdb_CreateOrOpen(config4, &errCode4);

    void *context = nullptr;
    Rdb_CorruptedHandler handler = CorruptedHandler;
    // 取消注册数据库异常处理，handler和context必须要和订阅时保持一致，否则取消失败
    OH_Rdb_UnregisterCorruptedHandler(config4, context, handler);
    ```