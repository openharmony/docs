# RelationalStore Development (C/C++)


## When to Use

The **RelationalStore** module provides a complete mechanism for local database management. You can use the APIs to add, delete, modify, and query data, and execute SQL statements in complex scenarios.


## Basic Concepts

- **Predicates**: a representation of the property or feature of a data entity, or the relationship between data entities, used to define operation conditions.

- **ResultSet**: a set of query results, which allows access to the required data in flexible modes.


## Constraints

- By default, the Write Ahead Log (WAL) and the **FULL** flushing mode are used.

- A maximum of four connection pools are used for read operations.

- To ensure data accuracy, only one write operation is allowed at a time.

- Once an application is uninstalled, related database files and temporary files are automatically deleted from the device.

- Before using the device-cloud sync APIs added in API version 11, ensure that the cloud service is available.


## Available APIs

For details about the interfaces, see [RDB](../reference/apis-arkdata/_r_d_b.md).

| API| Description|
| -------- | -------- |
| OH_Rdb_GetOrOpen(const OH_Rdb_Config *config, int *errCode) | Obtains an **OH_Rdb_Store** instance for RDB store operations.|
| OH_Rdb_Execute(OH_Rdb_Store *store, const char *sql) | Executes an SQL statement that contains specified arguments but returns no value.|
| OH_Rdb_Insert(OH_Rdb_Store *store, const char *table, OH_VBucket *valuesBucket) | Inserts a row of data into a table.|
| OH_Rdb_Update(OH_Rdb_Store *store, OH_VBucket *valuesBucket, OH_Predicates *predicates) | Updates data in an RDB store. |
| OH_Rdb_Delete(OH_Rdb_Store *store, OH_Predicates *predicates) | Deletes data from an RDB store. |
| OH_Rdb_Query(OH_Rdb_Store *store, OH_Predicates *predicates, const char *const *columnNames, int length) | Queries data in an RDB store. |
| OH_Rdb_DeleteStore(const OH_Rdb_Config *config) | Deletes an RDB store.|
| OH_VBucket_PutAsset(OH_VBucket *bucket, const char *field, Rdb_Asset *value) | Puts an RDB asset into an **OH_VBucket** object.|
| OH_VBucket_PutAssets(OH_VBucket *bucket, const char *field, Rdb_Asset *value, uint32_t count) | Puts RDB assets into an **OH_VBucket** object.|
| OH_Rdb_SetDistributedTables(OH_Rdb_Store *store, const char *tables[], uint32_t count, Rdb_DistributedType type, const Rdb_DistributedConfig *config) | Sets distributed database tables.|
| OH_Rdb_FindModifyTime(OH_Rdb_Store *store, const char *tableName, const char *columnName, OH_VObject *values) | Obtains the last modification time of the data in the specified column of a table. |
| OH_Rdb_CloudSync(OH_Rdb_Store *store, Rdb_SyncMode mode, const char *tables[], uint32_t count, const Rdb_ProgressObserver *observer) | Manually performs device-cloud sync for a table. The cloud service must be available. |
| int OH_Data_Asset_SetName(Data_Asset *asset, const char *name) | Sets the name for a data asset.|
| int OH_Data_Asset_SetUri(Data_Asset *asset, const char *uri) | Sets the absolute path for a data asset.|
| int OH_Data_Asset_SetPath(Data_Asset *asset, const char *path) | Sets the relative path in the application sandbox directory for a data asset.|
| int OH_Data_Asset_SetCreateTime(Data_Asset *asset, int64_t createTime) | Sets the creation time for a data asset.|
| int OH_Data_Asset_SetModifyTime(Data_Asset *asset, int64_t modifyTime) | Sets the last modification time for a data asset.|
| int OH_Data_Asset_SetSize(Data_Asset *asset, size_t size) | Sets the size of a data asset.|
| int OH_Data_Asset_SetStatus(Data_Asset *asset, Data_AssetStatus status) | Sets the status for a data asset.|
| int OH_Data_Asset_GetName(Data_Asset *asset, char *name, size_t *length) | Obtains the name of a data asset.|
| int OH_Data_Asset_GetUri(Data_Asset *asset, char *uri, size_t *length) | Obtains the absolute path of a data asset.|
| int OH_Data_Asset_GetPath(Data_Asset *asset, char *path, size_t *length) | Obtains the relative path of a data asset.|
| int OH_Data_Asset_GetCreateTime(Data_Asset *asset, int64_t *createTime) | Obtains the creation time of a data asset.|
| int OH_Data_Asset_GetModifyTime(Data_Asset *asset, int64_t *modifyTime) | Obtains the last modification time of a data asset.|
| int OH_Data_Asset_GetSize(Data_Asset *asset, size_t *size) | Obtains the size of a data asset.|
| int OH_Data_Asset_GetStatus(Data_Asset *asset, Data_AssetStatus *status) | Obtains the status of a data asset.|
| Data_Asset *OH_Data_Asset_CreateOne() | Creates a data asset instance. When this data asset is no longer needed, call **OH_Data_Asset_DestroyOne** to destroy it.|
| int OH_Data_Asset_DestroyOne(Data_Asset *asset) | Destroys a data asset instance to reclaim memory.|
| Data_Asset **OH_Data_Asset_CreateMultiple(uint32_t count) | Creates an instance for multiple data assets. When the instance is no longer required, call **OH_Data_Asset_DestroyMultiple** to destroy it.|
| int OH_Data_Asset_DestroyMultiple(Data_Asset **assets, uint32_t count) | Destroys multiple data assets to reclaim memory.|
| int OH_Rdb_Subscribe(OH_Rdb_Store *store, Rdb_SubscribeType type, const Rdb_DataObserver *observer) | Registers an observer for an RDB store. When the data in the distributed database changes, a callback will be invoked to return the data change.|
| int OH_Rdb_Unsubscribe(OH_Rdb_Store *store, Rdb_SubscribeType type, const Rdb_DataObserver *observer) | Unregisters the observer of the specified type.|
| int OH_Rdb_SubscribeAutoSyncProgress(OH_Rdb_Store *store, const Rdb_ProgressObserver *observer) | Subscribes to the auto sync process of an RDB store. The registered callback will be invoked to return the auto sync progress received.|
| int OH_Rdb_UnsubscribeAutoSyncProgress(OH_Rdb_Store *store, const Rdb_ProgressObserver *observer) | Unsubscribes from the auto sync process of an RDB store.|


## How to Develop

**Adding the Dynamic Link Library**

Add the following library to **CMakeLists.txt**:

```txt
libnative_rdb_ndk.z.so
```

**Including Header Files**

```c++
#include <database/data/data_asset.h>
#include <database/rdb/oh_cursor.h>
#include <database/rdb/oh_predicates.h>
#include <database/rdb/oh_value_object.h>
#include <database/rdb/oh_values_bucket.h>
#include <database/rdb/relational_store.h>
#include <database/rdb/relational_store_error_code.h>
```

1. Obtain an **OH_Rdb_Store** instance and create a database file. 

   The **dataBaseDir** variable specifies the application sandbox path. In the stage model, you are advised to use the database directory. For details, see the **databaseDir** attribute of [Context](../reference/apis-ability-kit/js-apis-inner-application-context.md). The FA model does not provide any API for obtaining the database sandbox path. Use the application directory instead. For details, see **getFilesDir** of [Context](../reference/apis-ability-kit/js-apis-inner-app-context.md). 

   **area** indicates the security level of the directory for database files. For details, see [contextConstant](../reference/apis-ability-kit/js-apis-app-ability-contextConstant.md). During development, you need to implement the conversion from **AreaMode** to **Rdb_SecurityArea**. <br>Example:

   ```c
   // Create an OH_Rdb_Config object.
   OH_Rdb_Config config;
   // The path is the application sandbox path.
   config.dataBaseDir = "xxx";
   // Database file name.
   config.storeName = "RdbTest.db";
   // Application bundle name.
   config.bundleName = "xxx";
   // Module name. 
   config.moduleName = "xxx";
   // Security level of the database file.
   config.securityLevel = OH_Rdb_SecurityLevel::S1;
   // Whether the database is encrypted.
   config.isEncrypt = false;
   // Memory size occupied by config.
   config.selfSize = sizeof(OH_Rdb_Config);
   // Security level of the directory for storing the database file.
   config.area = RDB_SECURITY_AREA_EL1;
   
   int errCode = 0;
   // Obtain an OH_Rdb_Store instance.
   OH_Rdb_Store *store_ = OH_Rdb_GetOrOpen(&config, &errCode);
   ```

2. Call **OH_Rdb_Execute** to create a table, and call **OH_Rdb_Insert** to insert data to the table. <br>Example:

   ```c
   char createTableSql[] = "CREATE TABLE IF NOT EXISTS EMPLOYEE (ID INTEGER PRIMARY KEY AUTOINCREMENT, NAME TEXT NOT NULL, "
                           "AGE INTEGER, SALARY REAL, CODES BLOB)";
   // Create a table.
   OH_Rdb_Execute(store_, createTableSql);
   
   // Create a key-value (KV) pair instance.
   OH_VBucket *valueBucket = OH_Rdb_CreateValuesBucket();
   valueBucket->putText(valueBucket, "NAME", "Lisa");
   valueBucket->putInt64(valueBucket, "AGE", 18);
   valueBucket->putReal(valueBucket, "SALARY", 100.5);
   uint8_t arr[] = {1, 2, 3, 4, 5};
   int len = sizeof(arr) / sizeof(arr[0]);
   valueBucket->putBlob(valueBucket, "CODES", arr, len);
   // Insert data.
   int rowId = OH_Rdb_Insert(store_, "EMPLOYEE", valueBucket);
   // Destroy the KV pair instance.
   valueBucket->destroy(valueBucket);
   ```

   > **NOTE**
   >
   > **RelationalStore** does not provide explicit flush operations for data persistence. The **insert()** API stores data persistently.

3. Modify or delete data based on the conditions specified by **OH_Predicates**.

   Call **OH_Rdb_Update** to modify data, and call **OH_Rdb_Delete** to delete data. <br>Example:

   ```c
   // Modify data.
   OH_VBucket *valueBucket = OH_Rdb_CreateValuesBucket();
   valueBucket->putText(valueBucket, "NAME", "Rose");
   valueBucket->putInt64(valueBucket, "AGE", 22);
   valueBucket->putReal(valueBucket, "SALARY", 200.5);
   uint8_t arr[] = {1, 2, 3, 4, 5};
   int len = sizeof(arr) / sizeof(arr[0]);
   valueBucket->putBlob(valueBucket, "CODES", arr, len);
   
   OH_Predicates *predicates = OH_Rdb_CreatePredicates("EMPLOYEE");
   OH_VObject *valueObject = OH_Rdb_CreateValueObject();
   const char *name = "Lisa";
   valueObject->putText(valueObject, name);
   predicates->equalTo(predicates, "NAME", valueObject)->andOperate(predicates);
   uint32_t count = 1;
   double salary = 100.5;
   valueObject->putDouble(valueObject, &salary, count);
   predicates->equalTo(predicates, "SALARY", valueObject);
       
   int changeRows = OH_Rdb_Update(store_, valueBucket, predicates);
   valueObject->destroy(valueObject);
   valueBucket->destroy(valueBucket);
   predicates->destroy(predicates);
   ```

   ```c
   // Delete data.
   OH_Predicates *predicates = OH_Rdb_CreatePredicates("EMPLOYEE");
   OH_VObject *valueObject = OH_Rdb_CreateValueObject();
   const char *name = "Lisa";
   valueObject->putText(valueObject, name);
   predicates->equalTo(predicates, "NAME", valueObject);
   int deleteRows = OH_Rdb_Delete(store_, predicates);
   valueObject->destroy(valueObject);
   predicates->destroy(predicates);
   ```

4. Query data based on the conditions specified by **OH_Predicates**.

   Call **OH_Rdb_Query** to query data. The data obtained is returned in an **OH_Cursor** object. <br>Example:

   ```c
   OH_Predicates *predicates = OH_Rdb_CreatePredicates("EMPLOYEE");
   
   const char *columnNames[] = {"NAME", "AGE"};
   int len = sizeof(columnNames) / sizeof(columnNames[0]);
   OH_Cursor *cursor = OH_Rdb_Query(store_, predicates, columnNames, len);
   
   int columnCount = 0;
   cursor->getColumnCount(cursor, &columnCount);
   
   // OH_Cursor is a cursor of a data set. By default, the cursor points to the -1st record. Valid data starts from 0.
   int64_t age;
   while (cursor->goToNextRow(cursor) == OH_Rdb_ErrCode::RDB_OK) {
       cursor->getInt64(cursor, 1, &age);
   }
   
   // Destroy the OH_Predicates instance.
   predicates->destroy(predicates);
   // Destroy the result set.
   cursor->destroy(cursor);
   ```

5. Insert data assets into a table.

   ```c
   // If the column attribute is a single asset, use asset in the SQL statements. If the column attribute is multiple assets, use assets in the SQL statements.
   char createAssetTableSql[] = "CREATE TABLE IF NOT EXISTS asset_table (id INTEGER PRIMARY KEY AUTOINCREMENT, data1 asset, data2 assets );";
   errCode = OH_Rdb_Execute(store_, createAssetTableSql);
   Data_Asset *asset = OH_Data_Asset_CreateOne();
   OH_Data_Asset_SetName(asset, "name0");
   OH_Data_Asset_SetUri(asset, "uri0");
   OH_Data_Asset_SetPath(asset, "path0");
   OH_Data_Asset_SetCreateTime(asset, 1);
   OH_Data_Asset_SetModifyTime(asset, 1);
   OH_Data_Asset_SetSize(asset, 1);
   OH_Data_Asset_SetStatus(asset, Data_AssetStatus::ASSET_NORMAL);
   errCode = OH_VBucket_PutAsset(valueBucket, "data1", asset);
   
   Data_Asset **assets = OH_Data_Asset_CreateMultiple(2);
   
   OH_Data_Asset_SetName(assets[0], "name0");
   OH_Data_Asset_SetUri(assets[0], "uri0");
   OH_Data_Asset_SetPath(assets[0], "path0");
   OH_Data_Asset_SetCreateTime(assets[0], 1);
   OH_Data_Asset_SetModifyTime(assets[0], 1);
   OH_Data_Asset_SetSize(assets[0], 1);
   OH_Data_Asset_SetStatus(assets[0], Data_AssetStatus::ASSET_NORMAL);
   
   OH_Data_Asset_SetName(assets[1], "name1");
   OH_Data_Asset_SetUri(assets[1], "uri1");
   OH_Data_Asset_SetPath(assets[1], "path1");
   OH_Data_Asset_SetCreateTime(assets[1], 1);
   OH_Data_Asset_SetModifyTime(assets[1], 1);
   OH_Data_Asset_SetSize(assets[1], 1);
   OH_Data_Asset_SetStatus(assets[1], Data_AssetStatus::ASSET_NORMAL);
   
   errCode = OH_VBucket_PutAssets(valueBucket, "data2", assets, assetsCount);
   int rowID = OH_Rdb_Insert(cursorTestRdbStore_, table, valueBucket);
   // Destroy Data_Asset* and Data_Asset**.
   OH_Data_Asset_DestroyMultiple(assets, 2);
   OH_Data_Asset_DestroyOne(asset);
   ```

6. Read data assets from the result set.

   ```c
   OH_Predicates *predicates = OH_Rdb_CreatePredicates("asset_table");
   
   OH_Cursor *cursor = OH_Rdb_Query(cursorTestRdbStore_, predicates, NULL, 0);
   cursor->goToNextRow(cursor);
   
   uint32_t assetCount = 0;
   // assetCount is an output parameter that indicates the number of assets in this column.
   errCode = cursor->getAssets(cursor, 2, nullptr, &assetCount);
   Data_Asset **assets = OH_Data_Asset_CreateMultiple(assetCount);
   errCode = cursor->getAssets(cursor, 2, assets, &assetCount);
   Data_Asset *asset = assets[1];
   
   char name[10] = "";
   size_t nameLength = 10;
   errCode = OH_Data_Asset_GetName(asset, name, &nameLength);
   
   char uri[10] = "";
   size_t uriLength = 10;
   errCode = OH_Data_Asset_GetUri(asset, uri, &uriLength);
   
   char path[10] = "";
   size_t pathLength = 10;
   errCode = OH_Data_Asset_GetPath(asset, path, &pathLength);
   
   int64_t createTime = 0;
   errCode = OH_Data_Asset_GetCreateTime(asset, &createTime);
   
   int64_t modifyTime = 0;
   errCode = OH_Data_Asset_GetModifyTime(asset, &modifyTime);
   
   size_t size = 0;
   errCode = OH_Data_Asset_GetSize(asset, &size);
   
   Data_AssetStatus status = Data_AssetStatus::ASSET_NULL;
   errCode = OH_Data_Asset_GetStatus(asset, &status);
   
   predicates->destroy(predicates);
   OH_Data_Asset_DestroyMultiple(assets, assetCount);
   cursor->destroy(cursor);
   ```

7. Obtain the last modification time of data. 

   Call **OH_Rdb_FindModifyTime** to obtain the last modification time of data in the specified column of a table. This API returns an **OH_Cursor** object with two columns of data. The first column is the input primary key or row ID, and the second column is the last modification time. <br>Example:

   ```c
   OH_VObject *values = OH_Rdb_CreateValueObject();
   int64_t keys[] = { 1 };
   values->putInt64(values, keys, 1);
   OH_Cursor *cursor;
   cursor = OH_Rdb_FindModifyTime(store_, "EMPLOYEE", "ROWID", values);
   ```

8. Create distributed tables. 

   Call **OH_Rdb_SetDistributedTables** to set distributed tables for the table (created by using **OH_Rdb_Execute**). Before using this API, ensure that the cloud service is available. <br>Example:

   ```c
   constexpr int TABLE_COUNT = 1;
   const char *table[TABLE_COUNT];
   table[0] = "EMPLOYEE";
   int errcode = OH_Rdb_SetDistributedTables(store_, table, TABLE_COUNT, Rdb_DistributedType::DISTRIBUTED_CLOUD, &config);
   ```

9. Manually perform device-cloud sync for the distributed tables. 

   Call **OH_Rdb_CloudSync** to perform device-cloud sync for the tables. Before using this API, ensure that the cloud service is available. <br>Example:

   ```c
   // Define a callback.
   void CloudSyncObserverCallback(void *context, Rdb_ProgressDetails *progressDetails)
   {
    // Do something.
   }
   const Rdb_ProgressObserver observer = { .context = nullptr, .callback = CloudSyncObserverCallback };
   OH_Rdb_CloudSync(store_, Rdb_SyncMode::SYNC_MODE_TIME_FIRST, table, TABLE_COUNT, &observer);
   ```

10. Register a data observer for the specified event type for an RDB store. When the data changes, the registered callback will be invoked to process the observation. Call **OH_Rdb_Subscribe** to subscribe to data changes. Before using this API, ensure that the cloud service is available. <br>Example:

    ```c
    // Define a callback.
    void RdbSubscribeBriefCallback(void *context, const char *values[], uint32_t count)
    {
    // Do something.
    }
    Rdb_BriefObserver briefObserver;
    const Rdb_BriefObserver briefObserver = { .context = nullptr, .callback = RdbSubscribeBriefCallback };
    // Subscribe to data changes.
    OH_Rdb_Subscribe(store_, Rdb_SubscribeType::RDB_SUBSCRIBE_TYPE_CLOUD, &briefObserver);
    ```

    Call **OH_Rdb_Subscribe** to subscribe to local database data changes. <br>Example:

    ```c
    // Define a callback.
    void LocalDataChangeObserverCallback1(void *context, const Rdb_ChangeInfo **changeInfo, uint32_t count)
    {
       for (uint32_t i = 0; i < count; i++) {
          EXPECT_EQ(DISTRIBUTED_CHANGE_INFO_VERSION, changeInfo[i]->version);
          // The table name is employee.
          changeInfo[i]->tableName;
          changeInfo[i]->ChangeType;
          // The number of added rows is 1.
          changeInfo[i]->inserted.count;
          // The number of updated rows is 0.
          changeInfo[i]->updated.count;
          // The number of deleted rows is 0.
          changeInfo[i]->deleted.count;
       }
    }
    Rdb_DetailsObserver callback = LocalDataChangeObserverCallback1;
    Rdb_DataObserver observer = { nullptr, { callback } };
    // Subscribe to the local database data changes.
    OH_Rdb_Subscribe(store_, Rdb_SubscribeType::RDB_SUBSCRIBE_TYPE_LOCAL_DETAILS, &observer);
     
    OH_VBucket* valueBucket = OH_Rdb_CreateValuesBucket();
    valueBucket->putText(valueBucket, "NAME", "Lisa");
    valueBucket->putInt64(valueBucket, "AGE", 18);
    valueBucket->putReal(valueBucket, "SALARY", 100.5);
    uint8_t arr[] = {1, 2, 3, 4, 5};
    int len = sizeof(arr) / sizeof(arr[0]);
    valueBucket->putBlob(valueBucket, "CODES", arr, len);
    // Insert data.
    int rowId = OH_Rdb_Insert(store_, "EMPLOYEE", valueBucket);
    // Destroy the KV pair instance.
    valueBucket->destroy(valueBucket);
    ```

11. Unsubscribe from the events of the specified type for an RDB store. After that, the callback will not be invoked to process the observation. Call **OH_Rdb_Unsubscribe** to unsubscribe from data changes. Before using this API, ensure that the cloud service is available. <br>Example:

     ```c
     // Define a callback.
     void RdbSubscribeBriefCallback(void *context, const char *values[], uint32_t count)
     {
     // Do something.
     }
     Rdb_BriefObserver briefObserver = RdbSubscribeBriefCallback;
     const Rdb_DataObserver briefObs = { .context = nullptr, .callback.briefObserver = briefObserver };
     // Unsubscribe from data changes.
     OH_Rdb_Unsubscribe(store_, Rdb_SubscribeType::RDB_SUBSCRIBE_TYPE_CLOUD, &briefObs);
     ```
    Call **OH_Rdb_Unsubscribe** to unsubscribe from local database data changes. <br>Example:
     ```c
     // Define a callback.
     void LocalDataChangeObserverCallback1(void *context, const Rdb_ChangeInfo **changeInfo, uint32_t count)
     {
     // Do something.
     }
     Rdb_DetailsObserver callback = LocalDataChangeObserverCallback1;
     Rdb_DataObserver observer = { nullptr, { callback } };
     // Unsubscribe from the local database data changes.
     OH_Rdb_Unsubscribe(store_, Rdb_SubscribeType::RDB_SUBSCRIBE_TYPE_LOCAL_DETAILS, &observer);
     ```


12. Register an observer for auto sync progress of an RDB store. When auto sync is performed on the RDB store, the registered callback will be invoked to process the observation. Call **OH_Rdb_SubscribeAutoSyncProgress** to subscribe to the auto sync progress. Before using this API, ensure that the cloud service is available. <br>Example:
    
    ```c
    // Define a callback.
    void RdbProgressObserverCallback(void *context, Rdb_ProgressDetails *progressDetails)
    {
    // Do something.
    }
    const Rdb_ProgressObserver observer = { .context = nullptr, .callback = RdbProgressObserverCallback };
    OH_Rdb_SubscribeAutoSyncProgress(store_, &observer);
    ```

13. Unsubscribe from the auto sync progress from an RDB store. After that, the callback will not be invoked to process the observation. Call **OH_Rdb_UnsubscribeAutoSyncProgress** to unsubscribe from the auto sync progress. Before using this API, ensure that the cloud service is available. <br>Example:
    
    ```c
    // Define a callback.
    void RdbProgressObserverCallback(void *context, Rdb_ProgressDetails *progressDetails)
    {
    // Do something.
    }
    const Rdb_ProgressObserver observer = { .context = nullptr, .callback = RdbProgressObserverCallback };
    OH_Rdb_UnsubscribeAutoSyncProgress(store_, &observer);
    ```

14. Delete an RDB store. 
    
    Call **OH_Rdb_DeleteStore** to delete the RDB store and related database file. <br>Example:
    
    ```c
    // Close the database instance.
    OH_Rdb_CloseStore(store_);
    // Delete the database file.
OH_Rdb_DeleteStore(&config);
    ```
    
    



  
