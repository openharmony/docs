# RelationalStore Development


## When to Use

RelationalStore provides a complete mechanism for local database management. It offers a series of interfaces for adding, deleting, modifying, and querying data in an RDB store. To satisfy different needs in complicated scenarios, RelationalStore also supports direct execution of SQL statements.


## Basic concepts

- **OH_Predicates**: A representation of the property or feature of a data entity, or the relationship between data entities. It is used to define operation conditions.

- **OH_Cursor**: A set of query results, which allows access to the required data in flexible modes.


## Restrictions

- The default logging mode is Write Ahead Log (WAL), and the default flushing mode is **FULL** mode.

- RelationalStore supports a maximum of four connection pools to manage read and write operations.

- To ensure data accuracy, only one write operation is allowed at a time.

- Once an application is uninstalled, related database files and temporary files on the device are automatically deleted.

- Before using the device-cloud synchronization APIs added in API version 11, ensure that the cloud service is available.


## Available APIs

For details about the APIs, see [RDB](../reference/native-apis/_r_d_b.md).

| API| Description|
| -------- | -------- |
| OH_Rdb_GetOrOpen(const OH_Rdb_Config *config, int *errCode) | Obtains an OH_Rdb_Store instance for RDB store operations.|
| OH_Rdb_Execute(OH_Rdb_Store *store, const char *sql) | Executes an SQL statement that contains specified arguments but returns no value.|
| OH_Rdb_Insert(OH_Rdb_Store *store, const char *table, OH_VBucket *valuesBucket) | Inserts a row of data into a table.|
| OH_Rdb_Update(OH_Rdb_Store *store, OH_VBucket *valuesBucket, OH_Predicates *predicates) | Updates data in the RDB store based on the specified OH_Predicates instance.|
| OH_Rdb_Delete(OH_Rdb_Store *store, OH_Predicates *predicates) | Deletes data from the RDB store based on the specified OH_Predicates instance.|
| OH_Rdb_Query(OH_Rdb_Store *store, OH_Predicates *predicates, const char *const *columnNames, int length) | Queries data in the RDB store based on specified conditions.|
| OH_Rdb_DeleteStore(const OH_Rdb_Config *config) | Deletes an RDB store.|
| OH_VBucket_PutAsset(OH_VBucket *bucket, const char *field, Rdb_Asset *value) | Puts data of the **Rdb_Asset** type into an **OH_VBucket** object.|
| OH_VBucket_PutAssets(OH_VBucket *bucket, const char *field, Rdb_Asset *value, uint32_t count) | Puts data of the **Rdb_Assets** type into an **OH_VBucket** object.|
| OH_Rdb_SetDistributedTables(OH_Rdb_Store *store, const char *tables[], uint32_t count, Rdb_DistributedType type, const Rdb_DistributedConfig *config) | Sets distributed database tables.|
| OH_Rdb_FindModifyTime(OH_Rdb_Store *store, const char *tableName, const char *columnName, OH_VObject *values) | Obtains the last modification time of the data in the specified column of a database table.|
| OH_Rdb_CloudSync(OH_Rdb_Store *store, Rdb_SyncMode mode, const char *tables[], uint32_t count, OH_Rdb_SyncCallback *progress) | Manually performs device-cloud synchronization for a table. The cloud service must be available.|
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
| int OH_Data_Asset_GetSize(Data_Asset *asset, size_t *size) | Obtains the space occupied by a data asset.|
| int OH_Data_Asset_GetStatus(Data_Asset *asset, Data_AssetStatus *status) | Obtains the status of a data asset.|
| Data_Asset *OH_Data_Asset_CreateOne() | Creates a data asset instance. Call **OH_Data_Asset_DestroyOne** to release the memory after the use of this data asset.|
| int OH_Data_Asset_DestroyOne(Data_Asset *asset) | Destroys a data asset instance to reclaim the memory.|
| Data_Asset **OH_Data_Asset_CreateMultiple(uint32_t count) | Creates multiple data asset instances. Call **OH_Data_Asset_DestroyMultiple** to release the memory after the use of the data assets.|
| int OH_Data_Asset_DestroyMultiple(Data_Asset **assets, uint32_t count) | Destroys multiple data asset instances to reclaim memory.|


## How to Develop

**Adding the Dynamic Library**

Add the following lib to **CMakeLists.txt**.

```txt
libnative_rdb_ndk.z.so
```

**Including Header Files**

```c++
#include <data_asset.h>
#include <oh_cursor.h>
#include <oh_predicates.h>
#include <oh_value_object.h>
#include <oh_values_bucket.h>
#include <relational_store.h>
#include <relational_store_error_code.h>
```

1. Obtain an **OH_Rdb_Store** instance and create the database file.<br>The **dataBaseDir** variable specifies the application sandbox path. In the stage model, you are advised to use the database directory. For details, see **databaseDir** of [Context](../reference/apis/js-apis-inner-application-context.md). In the FA model, there is no interface for obtaining the database sandbox path. Use the directory of the application. For details, see **getFilesDir** of [Context](../reference/apis/js-apis-inner-app-context.md).<br>**area** specifies the security level of the directory for storing the database file. For details, see [contextConstant](../reference/apis/js-apis-app-ability-contextConstant.md). During development, you need to implement the conversion from **AreaMode** to **Rdb_SecurityArea**.<br>Example:

   ```c
   // Create an OH_Rdb_Config instance.
   OH_Rdb_Config config;
   // The path is the application sandbox path.
   config.dataBaseDir = "xxx";
   // Database file name.
   config.storeName = "RdbTest.db";
   // Bundle name.
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
   // Obtain the OH_Rdb_Store instance.
   OH_Rdb_Store *store_ = OH_Rdb_GetOrOpen(&config, &errCode);
   ```

2. Use **OH_Rdb_Execute** to create a table, and use **OH_Rdb_Insert** to insert data to the table created. <br>Example:

   ```c
   char createTableSql[] = "CREATE TABLE IF NOT EXISTS EMPLOYEE (ID INTEGER PRIMARY KEY AUTOINCREMENT, NAME TEXT NOT NULL, "
                           "AGE INTEGER, SALARY REAL, CODES BLOB)";
   // Create a table.
   OH_Rdb_Execute(store_, createTableSql);
   
   // Create a KV pair instance.
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
   > **RelationalStore** does not provide explicit flush operations for data persistence. The **insert()** method stores data persistently.

3. Modify or delete data based on the specified **Predicates** instance.

   Call **OH_Rdb_Update** to modify data, and call **OH_Rdb_Delete** to delete data.<br>Example:

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

4. Query data based on the conditions specified by **Predicates**.

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
   
   // Destroy the Predicates instance.
   predicates->destroy(predicates);
   // Destroy the result set.
   cursor->destroy(cursor);
   ```

5. Insert data assets into a database table.

   ```c
   // If the column attribute is a single asset, use asset in the SQL statements. If the column attribute is multiple assets, use assets in the SQL statements.
   char createAssetTableSql[] = "CREATE TABLE IF NOT EXISTS asset_table (id INTEGER PRIMARY KEY AUTOINCREMENT, data1 asset, data2 assets );";
   errCode = OH_Rdb_Execute(storeTestRdbStore_, createAssetTableSql);
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
   // Release Data_Asset* and Data_Asset**.
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

7. Obtain the last modification time of the data.<br>Call **OH_Rdb_FindModifyTime** to obtain the last modification time of data in the specified column of a table. This method returns an **OH_Cursor** object with two columns of data. The first column is the input primary key or row number, and the second column is the last modification time. <br>Example:

   ```c
   OH_VObject *values = OH_Rdb_CreateValueObject();
   int64_t keys[] = { 1 };
   values->putInt64(values, keys, 1);
   OH_Cursor *cursor;
   cursor = OH_Rdb_FindModifyTime(storeTestRdbStore_, "EMPLOYEE", "ROWID", values);
   ```

8. Create distributed tables. Call **OH_Rdb_SetDistributedTables** to set distributed tables for the table (created by using **OH_Rdb_Execute**). Before using this API, ensure that the cloud service is available. <br>Example:

   ```c
   constexpr int TABLE_COUNT = 1;
   const char *table[TABLE_COUNT];
   table[0] = "EMPLOYEE";
   int errcode = OH_Rdb_SetDistributedTables(storeTestRdbStore_, table, TABLE_COUNT, Rdb_DistributedType::DISTRIBUTED_CLOUD, &config);
   ```

9. Manually perform device-cloud synchronization for distributed tables. After setting distributed tables by using **OH_Rdb_SetDistributedTables**, call **OH_Rdb_CloudSync** to perform device-cloud synchronization for the tables. Before using this API, ensure that the cloud service is available. <br>Example:

   ```c
   // Define a callback.
   void CloudSyncCallback(Rdb_ProgressDetails *progressDetails)
   {
       // Do something.
   }
   OH_Rdb_SyncCallback callback = CloudSyncCallback;
   OH_Rdb_CloudSync(storeTestRdbStore_, Rdb_SyncMode::SYNC_MODE_TIME_FIRST, table, TABLE_COUNT, &callback);
   ```

10. Delete the database. <br>Call **OH_Rdb_DeleteStore** to delete the RDB store and related database files.<br>Example:

      ```c
      // Close the database instance.
      OH_Rdb_CloseStore(store_);
      // Delete the database file.
      OH_Rdb_DeleteStore(&config);
      ```

    



  
