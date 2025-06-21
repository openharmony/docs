# 数据库备份与恢复（C/C++）

## 场景介绍

当应用在处理一项重要的操作，不能被打断的。例如：写入多个表关联的事务。此时，每个表的写入都是单独的，但是表与表之间的事务关联性不能被分割。

如果操作过程中出现问题，使用恢复功能将数据库恢复到之前状态，重新操作数据库。

在数据库被篡改、删除、或者设备断电场景下，数据库可能会因为数据丢失、数据损坏、脏数据等而不可用，可以通过数据库的备份恢复能力将数据库恢复至可用状态。

当前仅支持使用关系型数据库（C/C++）进行备份与恢复。

## 开发步骤

数据库操作或者存储过程中，有可能会因为各种原因发生非预期的数据库异常的情况，可以根据需要使用关系型数据库的备份能力，以便在数据库异常时，可靠高效地恢复数据保证业务数据正常使用。

1. CMakeLists.txt中添加以下lib。

    ```txt
    libnative_rdb_ndk.z.so
    ```

2. 导入头文件。

    ```c
    #include "database/rdb/relational_store.h"
    ```

3. 调用OH_Rdb_Backup接口实现数据库备份。

    ```c
    OH_Rdb_ConfigV2* config = OH_Rdb_CreateConfig();
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
    ```

4. 调用OH_Rdb_Restore接口实现数据库恢复。

    ```c
    OH_Rdb_ConfigV2* config2 = OH_Rdb_CreateConfig();
    OH_Rdb_SetDatabaseDir(config2, "/data/storage/el2/database");
    OH_Rdb_SetArea(config2, RDB_SECURITY_AREA_EL2);
    OH_Rdb_SetStoreName(config2, "RdbRestoreTest.db");
    OH_Rdb_SetSecurityLevel(config2, OH_Rdb_SecurityLevel::S3);
    OH_Rdb_SetBundleName(config2, "com.example.nativedemo");
    int errCode2 = 0;
    OH_Rdb_Store *store2 = OH_Rdb_CreateOrOpen(config2, &errCode2);
    
    // 恢复数据库
    int result2 = OH_Rdb_Restore(store2, "/data/storage/el2/database/RdbTest_bak.db");
    OH_Rdb_CloseStore(store2);
    ```