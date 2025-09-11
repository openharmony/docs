# Persisting RDB Store Data (C/C++)
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @baijidong-->
<!--Designer: @widecode; @htt1997-->
<!--Tester: @yippo; @logic42-->
<!--Adviser: @ge-yafang-->

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

## Available APIs

For details about the APIs, see [RDB](../reference/apis-arkdata/capi-rdb.md).

| API| Description|
| -------- | -------- |
| OH_Rdb_ConfigV2 *OH_Rdb_CreateConfig() | Creates an **OH_Rdb_ConfigV2** instance.|
| int OH_Rdb_SetDatabaseDir(OH_Rdb_ConfigV2 *config, const char *databaseDir) | Sets the database file path for an **OH_Rdb_ConfigV2** instance.|
| int OH_Rdb_SetStoreName(OH_Rdb_ConfigV2 *config, const char *storeName) | Sets the RDB store name for an **OH_Rdb_ConfigV2** instance.|
| int OH_Rdb_SetBundleName(OH_Rdb_ConfigV2 *config, const char *bundleName) | Sets the application bundle name for an **OH_Rdb_ConfigV2** instance.|
| int OH_Rdb_SetModuleName(OH_Rdb_ConfigV2 *config, const char *moduleName) | Sets the module name for an **OH_Rdb_ConfigV2** instance.|
| int OH_Rdb_SetSecurityLevel(OH_Rdb_ConfigV2 *config, int securityLevel) | Sets the security level for an **OH_Rdb_ConfigV2** instance.|
| int OH_Rdb_SetEncrypted(OH_Rdb_ConfigV2 *config, bool isEncrypted) | Sets whether to encrypt the database for an **OH_Rdb_ConfigV2** instance.|
| int OH_Rdb_SetArea(OH_Rdb_ConfigV2 *config, int area) | Sets the security area for an **OH_Rdb_ConfigV2** instance.|
| OH_Rdb_Store *OH_Rdb_CreateOrOpen(const OH_Rdb_ConfigV2 *config, int *errCode) | Creates an **OH_Rdb_ConfigV2** instance to obtain an **OH_Rdb_Store** instance.|
| OH_Rdb_Execute(OH_Rdb_Store *store, const char *sql) | Executes an SQL statement that contains specified arguments but returns no value.|
| OH_Rdb_Insert(OH_Rdb_Store *store, const char *table, OH_VBucket *valuesBucket) | Inserts a row of data into a table.|
| int OH_Rdb_InsertWithConflictResolution(OH_Rdb_Store *store, const char *table, OH_VBucket *row, Rdb_ConflictResolution resolution, int64_t *rowId) | Inserts a row of data into a table with conflict resolutions.|
| int OH_Rdb_UpdateWithConflictResolution(OH_Rdb_Store *store, OH_VBucket *row, OH_Predicates *predicates, Rdb_ConflictResolution resolution, int64_t *changes) | Updates a row of data into a table with conflict resolutions.|
| OH_Rdb_Update(OH_Rdb_Store *store, OH_VBucket *valuesBucket, OH_Predicates *predicates) | Updates data in an RDB store.|
| OH_Rdb_Delete(OH_Rdb_Store *store, OH_Predicates *predicates) | Deletes data from an RDB store.|
| int OH_Predicates_NotLike(OH_Predicates *predicates, const char *field, const char *pattern) | Sets an **OH_Predicates** object to match a string that is not similar to the specified value.|
| int OH_Predicates_Glob(OH_Predicates *predicates, const char *field, const char *pattern) | Sets an **OH_Predicates** object to match a string containing a wildcard.|
| int OH_Predicates_NotGlob(OH_Predicates *predicates, const char *field, const char *pattern) | Sets an **OH_Predicates** object not to match a string containing a wildcard.|
| OH_Rdb_Query(OH_Rdb_Store *store, OH_Predicates *predicates, const char *const *columnNames, int length) | Queries data in an RDB store.|
| OH_Rdb_DeleteStore(const OH_Rdb_Config *config) | Deletes an RDB store.|
| OH_VBucket_PutAsset(OH_VBucket *bucket, const char *field, Rdb_Asset *value) | Puts an RDB asset into an **OH_VBucket** object.|
| OH_VBucket_PutAssets(OH_VBucket *bucket, const char *field, Rdb_Asset *value, uint32_t count) | Puts RDB assets into an **OH_VBucket** object.|
| OH_Rdb_FindModifyTime(OH_Rdb_Store *store, const char *tableName, const char *columnName, OH_VObject *values) | Obtains the last modification time of the data in the specified column of a table.|
| OH_RDB_TransOptions *OH_RdbTrans_CreateOptions(void) | Creates an **OH_RDB_TransOptions** instance to configure the transaction object. |
| OH_Cursor *OH_RdbTrans_Query(OH_Rdb_Transaction *trans, const OH_Predicates *predicates, const char *columns[], int len) | Queries data in the database based on specified conditions.|
| OH_Data_Values *OH_Values_Create(void) | Creates an **OH_Data_Values** instance.|
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
| int OH_Rdb_CreateTransaction(OH_Rdb_Store *store, const OH_RDB_TransOptions *options, OH_Rdb_Transaction **trans) | Creates an **OH_Rdb_Transaction** instance to start a transaction.|
| int OH_RdbTransOption_SetType(OH_RDB_TransOptions *options, OH_RDB_TransType type) | Sets the transaction object type.|
| int OH_RdbTrans_Insert(OH_Rdb_Transaction *trans, const char *table, const OH_VBucket *row, int64_t *rowId) | Inserts a row of data into a table.|
| int OH_RdbTrans_InsertWithConflictResolution(OH_Rdb_Transaction *trans, const char *table, const OH_VBucket *row, Rdb_ConflictResolution resolution, int64_t *rowId) | Inserts a row of data into a table with conflict resolutions.|
| int OH_RdbTrans_UpdateWithConflictResolution(OH_Rdb_Transaction *trans, const OH_VBucket *row, const OH_Predicates *predicates, Rdb_ConflictResolution resolution, int64_t *changes) | Updates data with conflict resolutions in the database based on specified conditions.|
| int OH_RdbTrans_Delete(OH_Rdb_Transaction *trans, const OH_Predicates *predicates, int64_t *changes) | Deletes data from an RDB store.|
| int OH_Value_Destroy(OH_Data_Value *value) | Destroys an **OH_Data_Value** object.|
| int OH_Values_Destroy(OH_Data_Values *values) | Destroys an **OH_Values_Destroy** object.|
| int OH_RdbTrans_Execute(OH_Rdb_Transaction *trans, const char *sql, const OH_Data_Values *args, OH_Data_Value **result) | Executes an SQL statement that contains specified parameters.|
| int OH_RdbTrans_Commit(OH_Rdb_Transaction *trans) | Commits a transaction.|
| int OH_RdbTrans_Rollback(OH_Rdb_Transaction *trans) | Rolls back a transaction.|
| int OH_RdbTrans_Destroy(OH_Rdb_Transaction *trans) | Destroys an **OH_Rdb_Transaction** instance.|
| int OH_Rdb_Attach(OH_Rdb_Store *store, const OH_Rdb_ConfigV2 *config, const char *attachName, int64_t waitTime, size_t *attachedNumber) | Attaches a database file to the database that is currently connected.|
| int OH_Rdb_Detach(OH_Rdb_Store *store, const char *attachName, int64_t waitTime, size_t *attachedNumber) | Detaches a specified store from the current database.|
| int OH_Rdb_SetCustomDir(OH_Rdb_ConfigV2 *config, const char *customDir) | Sets the custom directory of the database.|
| int OH_Rdb_SetLocale(OH_Rdb_Store *store, const char *locale) | Sets locale.|
| int OH_Rdb_SetPlugins(OH_Rdb_ConfigV2 *config, const char **plugins, int32_t length) | Sets the dynamic library with specific capabilities (such as full-text search).|

## How to Develop

**Adding the Dynamic Link Library**

Add the following library to **CMakeLists.txt**:

```txt
libnative_rdb_ndk.z.so
```

**Including Header Files**

```c
#include <database/data/data_asset.h>
#include <database/rdb/oh_cursor.h>
#include <database/rdb/oh_predicates.h>
#include <database/rdb/oh_value_object.h>
#include <database/rdb/oh_values_bucket.h>
#include <database/rdb/relational_store.h>
#include <database/rdb/relational_store_error_code.h>
```

1. Obtain an **OH_Rdb_Store** instance and create a database file. <br>The **dataBaseDir** variable specifies the application sandbox path. In the stage model, you are advised to use the database directory. For details, see the **databaseDir** attribute of [Context](../reference/apis-ability-kit/js-apis-inner-application-context.md). The FA model does not provide any API for obtaining the database sandbox path. Use the application directory instead. For details, see **getFilesDir** of [Context](../reference/apis-ability-kit/js-apis-inner-app-context.md). <br>**area** indicates the security level of the directory for database files. For details, see [contextConstant](../reference/apis-ability-kit/js-apis-app-ability-contextConstant.md). During development, you need to implement the conversion from **AreaMode** to **Rdb_SecurityArea**. <br>Example:

   ```c
   // Create an OH_Rdb_ConfigV2 object.
   OH_Rdb_ConfigV2* config = OH_Rdb_CreateConfig();
   // The path is the application sandbox path.
   // The database file will be created in the sandbox path /data/storage/el2/database/rdb/RdbTest.db.
   OH_Rdb_SetDatabaseDir(config, "/data/storage/el2/database");
   // Database file name.
   OH_Rdb_SetStoreName(config, "RdbTest.db");
   // Application bundle name.
   OH_Rdb_SetBundleName(config, "com.example.nativedemo");
   // Module name. 
   OH_Rdb_SetModuleName(config, "entry");
   // Security level of the database file.
   OH_Rdb_SetSecurityLevel(config, OH_Rdb_SecurityLevel::S3);
   // Whether the database is encrypted.
   OH_Rdb_SetEncrypted(config, false);
   // Security level of the directory for storing the database file.
   OH_Rdb_SetArea(config, RDB_SECURITY_AREA_EL2);

   int errCode = 0;
   // Obtain an OH_Rdb_Store instance.
   OH_Rdb_Store *store_ = OH_Rdb_CreateOrOpen(config, &errCode);
   ```

   ```c
    // You can set a custom database path.
    // The database file will be created in the sandbox path /data/storage/el2/database/a/b/RdbTest.db.
    OH_Rdb_SetCustomDir(config, "../a/b");
    // Set the database to the read-only mode.
    OH_Rdb_SetReadOnly(config, true);
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

   OH_VBucket *valueBucket2 = OH_Rdb_CreateValuesBucket();
   valueBucket2->putInt64(valueBucket2, "ID", 1);
   valueBucket2->putText(valueBucket2, "NAME", "zhangsan");
   valueBucket2->putInt64(valueBucket2, "AGE", 24);
   valueBucket2->putReal(valueBucket2, "SALARY", 120.4);
   int64_t rowId2 = -1;
   // Configure conflict resolutions when data is inserted.
   int result = OH_Rdb_InsertWithConflictResolution(store_, "EMPLOYEE", valueBucket2,
                                                    Rdb_ConflictResolution::RDB_CONFLICT_REPLACE, &rowId2);
   // Destroy the KV pair instance.
   valueBucket->destroy(valueBucket);
   valueBucket2->destroy(valueBucket2);
   ```

   > **NOTE**
   >
   > **RelationalStore** does not provide explicit flush operations for data persistence. The **insert()** API stores data persistently.

3. Modify or delete data based on the conditions specified by **OH_Predicates**.<br>Call **OH_Rdb_Update** to modify data, and call **OH_Rdb_Delete** to delete data. <br>Example:

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
   int rowId = OH_Rdb_Insert(store_, "EMPLOYEE", valueBucket);
   OH_Predicates *predicates2 = OH_Rdb_CreatePredicates("EMPLOYEE");
   OH_VObject *valueObject2 = OH_Rdb_CreateValueObject();
   valueObject2->putText(valueObject2, "Rose");
   predicates2->equalTo(predicates2, "NAME", valueObject2);
   valueBucket->putInt64(valueBucket, "ID", 1);
   valueBucket->putText(valueBucket, "NAME", "zhangsan");
   int64_t changeRows2 = -1;

   // Configure conflict resolutions when data is updated.
   int result = OH_Rdb_UpdateWithConflictResolution(store_, valueBucket, predicates2,
                                                    Rdb_ConflictResolution::RDB_CONFLICT_REPLACE, &changeRows2);
   valueObject->destroy(valueObject);
   valueObject2->destroy(valueObject2);
   valueBucket->destroy(valueBucket);
   predicates->destroy(predicates);
   predicates2->destroy(predicates2);
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

4. Query data based on the conditions specified by **OH_Predicates**.<br>Call **OH_Rdb_Query** to query data. The data obtained is returned in an **OH_Cursor** object. <br>Example:

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
       int32_t ageColumnIndex = -1;
	   cursor->getColumnIndex(cursor, "AGE", &ageColumnIndex);
       if (ageColumnIndex != -1) {
           cursor->getInt64(cursor, ageColumnIndex, &age);
       }
   }
   
   // Destroy the OH_Predicates instance.
   predicates->destroy(predicates);
   // Destroy the result set.
   cursor->destroy(cursor);
   ```
   
   Configure predicates to match data in LIKE or NOT LIKE mode. <br>Example:
   
   ```c
   OH_Predicates *likePredicates = OH_Rdb_CreatePredicates("EMPLOYEE");
   
   OH_VObject *likePattern = OH_Rdb_CreateValueObject();
   likePattern->putText(likePattern, "zh%");
   // Configure predicates to match data in LIKE mode.
   likePredicates->like(likePredicates, "NAME", likePattern);

   char *colName[] = { "NAME", "AGE" };
   auto *likeQueryCursor = OH_Rdb_Query(store_, likePredicates, colName, 2);
   likeQueryCursor->goToNextRow(likeQueryCursor);
   size_t dataLength = 0;
   int colIndex = -1;
   likeQueryCursor->getColumnIndex(likeQueryCursor, "NAME", &colIndex);
   likeQueryCursor->getSize(likeQueryCursor, colIndex, &dataLength);
   char *name = (char*)malloc((dataLength + 1) * sizeof(char)); 
   likeQueryCursor->getText(likeQueryCursor, colIndex, name, dataLength + 1);

   likeQueryCursor->destroy(likeQueryCursor);
   likePredicates->destroy(likePredicates);
   likePattern->destroy(likePattern);
   free(name);
   
   OH_Predicates *notLikePredicates = OH_Rdb_CreatePredicates("EMPLOYEE");
   
   // Configure predicates to match data in NOT LIKE mode.
   OH_Predicates_NotLike(notLikePredicates, "NAME", "zh%");
   auto *notLikeQueryCursor = OH_Rdb_Query(store_, notLikePredicates, colName, 2);
   notLikeQueryCursor->goToNextRow(notLikeQueryCursor);
   dataLength = 0;
   colIndex = -1;
   notLikeQueryCursor->getColumnIndex(notLikeQueryCursor, "NAME", &colIndex);
   notLikeQueryCursor->getSize(notLikeQueryCursor, colIndex, &dataLength);
   char *name2 = (char*)malloc((dataLength + 1) * sizeof(char)); 
   notLikeQueryCursor->getText(notLikeQueryCursor, colIndex, name2, dataLength + 1);
   
   notLikeQueryCursor->destroy(notLikeQueryCursor);
   free(name2);
   ```
   Configure predicates to match data in GLOB or NOT GLOB mode. <br>Example:
   ```c
   OH_Predicates *globPredicates = OH_Rdb_CreatePredicates("EMPLOYEE");
   // Configure predicates to match in GLOB mode.
   OH_Predicates_Glob(globPredicates, "NAME", "zh*");
   
   char *colName[] = { "NAME", "AGE" };
   auto *globQueryCursor = OH_Rdb_Query(store_, globPredicates, colName, 2);
   globQueryCursor->goToNextRow(globQueryCursor);
   size_t dataLength = 0;
   int colIndex = -1;
   globQueryCursor->getColumnIndex(globQueryCursor, "NAME", &colIndex);
   globQueryCursor->getSize(globQueryCursor, colIndex, &dataLength);
   char* name = (char*)malloc((dataLength + 1) * sizeof(char)); 
   globQueryCursor->getText(globQueryCursor, colIndex, name, dataLength + 1);
   
   globQueryCursor->destroy(globQueryCursor);
   globPredicates->destroy(globPredicates);
   free(name);
   
   OH_Predicates *notGlobPredicates = OH_Rdb_CreatePredicates("EMPLOYEE");
   // Configure predicates to match in NOT GLOB mode.
   OH_Predicates_NotGlob(notGlobPredicates, "NAME", "zh*");
   auto *notGlobQueryCursor = OH_Rdb_Query(store_, notGlobPredicates, colName, 2);
   notGlobQueryCursor->goToNextRow(notGlobQueryCursor);
   dataLength = 0;
   colIndex = -1;
   notGlobQueryCursor->getColumnIndex(notGlobQueryCursor, "NAME", &colIndex);
   notGlobQueryCursor->getSize(notGlobQueryCursor, colIndex, &dataLength);
   char* name2 = (char*)malloc((dataLength + 1) * sizeof(char)); 
   notGlobQueryCursor->getText(notGlobQueryCursor, colIndex, name2, dataLength + 1);
   
   notGlobQueryCursor->destroy(notGlobQueryCursor);
   notGlobPredicates->destroy(notGlobPredicates);
   free(name2);
   ```
   You can set locale used for sorting. For example, **zh_CN** indicates Chinese, and **tr_TR** indicates Turkish. Call **OH_Rdb_SetLocale** to configure the rule.
    ```c
    OH_Rdb_SetLocale(store_, "zh_CN");
    ```
   
    To configure the full-text search (FTS) dynamic library, use **OH_Rdb_SetPlugins**.

    For details about the constraints, see the **pluginLibs** configuration item in [StoreConfig](../reference/apis-arkdata/arkts-apis-data-relationalStore-i.md#storeconfig).
   
    ```c
    const char *plugins[] = {
        "/data/storage/el1/bundle/libs/arm64/libtokenizer.so"
    };
    
    int32_t count = sizeof(plugins) / sizeof(plugins[0]);
    auto setResult = OH_Rdb_SetPlugins(config, plugins, count);
    ```
5. Insert, delete, or update data using a transaction object.

   Call **OH_RdbTransOption_SetType** to configure the transaction type to be created.
   The supported transaction types are **DEFERRED** (default), **IMMEDIATE**, and **EXCLUSIVE**.

   Call **OH_Rdb_CreateTransaction** to create a transaction object and use this object to execute the corresponding transaction operation.

    ```c
    OH_RDB_TransOptions *options;
    options = OH_RdbTrans_CreateOptions();
    // Configure the transaction type.
    OH_RdbTransOption_SetType(options, RDB_TRANS_DEFERRED);
    OH_Rdb_Transaction *trans = nullptr;
    // Create a transaction object.
    int ret = OH_Rdb_CreateTransaction(store_, options, &trans);

    OH_RdbTrans_DestroyOptions(options);

    char transCreateTableSql[] =
        "CREATE TABLE IF NOT EXISTS transaction_table (id INTEGER PRIMARY KEY AUTOINCREMENT, data1 INTEGER, "
        "data2 INTEGER, data3 FLOAT, data4 TEXT, data5 BLOB, data6 ASSET, data7 ASSETS, data8 UNLIMITED INT, "
        "data9 FLOATVECTOR);";

    auto *execResult = OH_Value_Create();

    // Execute SQL statements to create a database table through the transaction object.
    ret = OH_RdbTrans_Execute(trans, transCreateTableSql, nullptr, &execResult);

    // Create an OH_Data_Values instance.
    OH_Data_Values *values = OH_Values_Create();
    ret = OH_Values_PutInt(values, 1);
    ret = OH_Values_PutInt(values, 2);
    ret = OH_Values_PutReal(values, 1.1);
    ret = OH_Values_PutText(values, "1");
    unsigned char val[] = {1, 2};
    ret = OH_Values_PutBlob(values, val, sizeof(val) / sizeof(val[0]));

    Data_Asset *asset = OH_Data_Asset_CreateOne();
    ret = OH_Data_Asset_SetName(asset, "name");
    ret = OH_Values_PutAsset(values, asset);
    OH_Data_Asset_DestroyOne(asset);

    Data_Asset **assets = OH_Data_Asset_CreateMultiple(2);
    ret = OH_Data_Asset_SetName(assets[0], "name1");
    ret = OH_Data_Asset_SetName(assets[1], "name2");
    ret = OH_Values_PutAssets(values, assets, 2);
    ret = OH_Data_Asset_DestroyMultiple(assets, 2);

    uint64_t bigInt[] = {1, 2, 3, 4, 5};
    ret = OH_Values_PutUnlimitedInt(values, 0, bigInt, sizeof(bigInt) / sizeof(bigInt[0]));

    const char *insertSql = "INSERT INTO transaction_table "
                            "(data1, data2, data3, data4, data5, data6, data7, data8) VALUES (?, ?, ?, ?, ?, ?, ?, ?)";
    OH_Data_Value *outValue = nullptr;

    // Execute SQL statements to insert data through the transaction object.
    ret = OH_RdbTrans_Execute(trans, insertSql, values, &outValue);
    OH_Value_Destroy(outValue);
    OH_Values_Destroy(values);

    OH_VBucket *transValueBucket = OH_Rdb_CreateValuesBucket();
    transValueBucket->putInt64(transValueBucket, "data1", 1);
    transValueBucket->putInt64(transValueBucket, "data2", 2);
    transValueBucket->putReal(transValueBucket, "data3", 1.1);
    transValueBucket->putText(transValueBucket, "data4", "1");
    transValueBucket->putBlob(transValueBucket, "data5", val, sizeof(val) / sizeof(val[0]));
    int64_t insertRowId = -1;
    // Insert the OH_VBucket data through the transaction object.
    int insertRet = OH_RdbTrans_Insert(trans, "transaction_table", transValueBucket, &insertRowId);
    transValueBucket->destroy(transValueBucket);

    OH_VBucket *transValueBucket2 = OH_Rdb_CreateValuesBucket();
    transValueBucket2->putInt64(transValueBucket2, "id", 1);
    transValueBucket2->putInt64(transValueBucket2, "data2", 2);
    transValueBucket2->putReal(transValueBucket2, "data3", 1.2);

    int64_t transInsertRow = -1;
    // Configure conflict resolutions when data is inserted.
    int result = OH_RdbTrans_InsertWithConflictResolution(
        trans, "transaction_table", transValueBucket2, Rdb_ConflictResolution::RDB_CONFLICT_REPLACE, &transInsertRow);

    transValueBucket2->destroy(transValueBucket2);

    OH_VBucket *transValueBucket3 = OH_Rdb_CreateValuesBucket();
    transValueBucket3->putInt64(transValueBucket3, "id", 1);
    transValueBucket3->putInt64(transValueBucket3, "data2", 3);
    transValueBucket3->putReal(transValueBucket3, "data3", 1.2);

    OH_Predicates *transUpdatePredicates = OH_Rdb_CreatePredicates("transaction_table");
    auto targetValue = OH_Rdb_CreateValueObject();
    int64_t two = 2;
    targetValue->putInt64(targetValue, &two, 1);
    transUpdatePredicates->equalTo(transUpdatePredicates, "data2", targetValue);

    int64_t updateRows = -1;
    // Configure conflict resolutions when data is updated.
    OH_RdbTrans_UpdateWithConflictResolution(trans, transValueBucket3, transUpdatePredicates,
                                             Rdb_ConflictResolution::RDB_CONFLICT_REPLACE, &updateRows);
    targetValue->destroy(targetValue);
    transValueBucket3->destroy(transValueBucket3);
    transUpdatePredicates->destroy(transUpdatePredicates);

    OH_Predicates *predicates = OH_Rdb_CreatePredicates("transaction_table");
    const char *columns[] = {"data1", "data2", "data3"};
    // Query data through the transaction object.
    OH_Cursor *cursor = OH_RdbTrans_Query(trans, predicates, columns, sizeof(columns) / sizeof(columns[0]));
    int columnCount = 0;
    cursor->getColumnCount(cursor, &columnCount);

    predicates->destroy(predicates);
    cursor->destroy(cursor);

    OH_Predicates *predicates2 = OH_Rdb_CreatePredicates("transaction_table");
    OH_VObject *valueObject = OH_Rdb_CreateValueObject();
    valueObject->putText(valueObject, "1");
    predicates2->equalTo(predicates2, "data4", valueObject);
    int64_t changes = -1;
    // Delete data through the transaction object.
    int deleteRet = OH_RdbTrans_Delete(trans, predicates2, &changes);
    predicates2->destroy(predicates2);
    valueObject->destroy(valueObject);

    // Commit a transaction.
    OH_RdbTrans_Commit(trans);
    // Destroy the transaction.
    OH_RdbTrans_Destroy(trans);
    ```

    ```c
    OH_RDB_TransOptions *options2;
    options2 = OH_RdbTrans_CreateOptions();
    OH_RdbTransOption_SetType(options2, RDB_TRANS_DEFERRED);
    OH_Rdb_Transaction *trans2 = nullptr;
    int transCreateRet = OH_Rdb_CreateTransaction(store_, options2, &trans2);
    OH_RdbTrans_DestroyOptions(options2);

    // Roll back the transaction.
    OH_RdbTrans_Rollback(trans2);
    OH_RdbTrans_Destroy(trans2);

    ```

6. Attach a database.
   
    Call **OH_Rdb_Attach** to attach an RDB store file to an RDB store so that the data in the attached RDB store can be directly accessed using the SQL statement.
    This API does not support encrypted databases.

    After the **attach** API is called, the RDB store is switched to the non-WAL mode, which may undermine the performance. Before switching the mode, ensure that all **OH_Cursor** objects have been destroyed and all write operations have been completed. Otherwise, error 14800015 is reported.
    
    The **attach** API cannot be called concurrently. Concurrent calls may cause the system to become unresponsive and trigger 14800015. If this occurs, try to call **attach()** again later.
    
    When the attached database is no longer used, call **OH_Rdb_Detach** to detach it.

    ```c
    char attachStoreTableCreateSql[] = "CREATE TABLE IF NOT EXISTS EMPLOYEE (ID INTEGER PRIMARY KEY AUTOINCREMENT, NAME TEXT NOT NULL, "
                           "AGE INTEGER, SALARY REAL, CODES BLOB)";
    OH_Rdb_ConfigV2* configAttach = OH_Rdb_CreateConfig();
    OH_Rdb_SetModuleName(configAttach, "entry");
    OH_Rdb_SetDatabaseDir(configAttach, "/data/storage/el2/database");
    OH_Rdb_SetArea(configAttach, RDB_SECURITY_AREA_EL2);
    OH_Rdb_SetStoreName(configAttach, "RdbAttach.db");
    OH_Rdb_SetSecurityLevel(configAttach, OH_Rdb_SecurityLevel::S3);
    OH_Rdb_SetBundleName(configAttach, "com.example.nativedemo");

    // Create an RdbAttach.db (example).
    int attachStoreCreateErrCode = 0;
    OH_Rdb_Store *attachStore = OH_Rdb_CreateOrOpen(configAttach, &attachStoreCreateErrCode);
    OH_Rdb_Execute(attachStore, attachStoreTableCreateSql);
    OH_VBucket *valueBucket = OH_Rdb_CreateValuesBucket();
    valueBucket->putText(valueBucket, "NAME", "Lisa");
    valueBucket->putInt64(valueBucket, "AGE", 18);
    valueBucket->putReal(valueBucket, "SALARY", 100.5);
    uint8_t arr[] = {1, 2, 3, 4, 5};
    int len = sizeof(arr) / sizeof(arr[0]);
    valueBucket->putBlob(valueBucket, "CODES", arr, len);
    int rowId = OH_Rdb_Insert(attachStore, "EMPLOYEE", valueBucket);
    valueBucket->destroy(valueBucket);
    OH_Rdb_CloseStore(attachStore);

    // Attach databases.
    size_t attachedCount = 0;
    int result = OH_Rdb_Attach(store_, configAttach, "attach", 10, &attachedCount);
    auto predicates = OH_Rdb_CreatePredicates("attach.EMPLOYEE");
    char *colName[] = {};
    auto cursor = OH_Rdb_Query(store_, predicates, colName, 0);
    int rowCount = -1;
    result = cursor->getRowCount(cursor, &rowCount);
    cursor->destroy(cursor);
    
    // Detach databases.
    result = OH_Rdb_Detach(store_, "attach", 10, &attachedCount);
    ```

7. Insert data assets into a table.

   ```c
   // If the column attribute is a single asset, use asset in the SQL statements. If the column attribute is multiple assets, use assets in the SQL statements.
   char createAssetTableSql[] = "CREATE TABLE IF NOT EXISTS asset_table (id INTEGER PRIMARY KEY AUTOINCREMENT, data1 asset, data2 assets );";
   const char *table = "asset_table";
   int errCode = OH_Rdb_Execute(store_, createAssetTableSql);
   OH_VBucket *valueBucket = OH_Rdb_CreateValuesBucket();
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
   
   uint32_t assetsCount = 1;
   errCode = OH_VBucket_PutAssets(valueBucket, "data2", assets, assetsCount);
   int rowID = OH_Rdb_Insert(store_, table, valueBucket);
   // Destroy Data_Asset* and Data_Asset**.
   OH_Data_Asset_DestroyMultiple(assets, 2);
   OH_Data_Asset_DestroyOne(asset);
   valueBucket->destroy(valueBucket);
   ```

8. Read data assets from the result set.

   ```c
   OH_Predicates *predicates = OH_Rdb_CreatePredicates("asset_table");
   
   OH_Cursor *cursor = OH_Rdb_Query(store_, predicates, NULL, 0);
   cursor->goToNextRow(cursor);
   
   uint32_t assetCount = 0;
   // assetCount is an output parameter that indicates the number of assets in this column.
   int errCode = cursor->getAssets(cursor, 2, nullptr, &assetCount);
   Data_Asset **assets = OH_Data_Asset_CreateMultiple(assetCount);
   errCode = cursor->getAssets(cursor, 2, assets, &assetCount);
   if (assetCount < 2) {
       predicates->destroy(predicates);
       cursor->destroy(cursor);
       return;
   }
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

9. Obtain the last modification time of data. <br>Call **OH_Rdb_FindModifyTime** to obtain the last modification time of data in the specified column of a table. This API returns an **OH_Cursor** object with two columns of data. The first column is the input primary key or row ID, and the second column is the last modification time. <br>Example:

   ```c
   OH_VObject *values = OH_Rdb_CreateValueObject();
   int64_t keys[] = { 1 };
   values->putInt64(values, keys, 1);
   OH_Cursor *cursor;
   cursor = OH_Rdb_FindModifyTime(store_, "EMPLOYEE", "ROWID", values);
   ```

10. Delete the database. Call **OH_Rdb_DeleteStore** to delete the RDB store and related database file. <br>Example:
    
    ```c
    // Close the database instance.
    OH_Rdb_CloseStore(store_);
    // Delete the database file.
    OH_Rdb_DeleteStoreV2(config);
    ```
