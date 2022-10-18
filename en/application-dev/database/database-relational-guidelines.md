# RDB Development

## When to Use

A relational database (RDB) store allows you to operate local data with or without native SQL statements based on SQLite.


## Available APIs

Most of the RDB store APIs are asynchronous interfaces, which can use a callback or promise to return the result. This document uses the promise-based APIs as an example. For details about the APIs, see [Relational Database](../reference/apis/js-apis-data-rdb.md).

### Creating or Deleting an RDB Store

The table below describes the APIs available for creating and deleting an RDB store.

**Table 1** APIs for creating and deleting an RDB store

| API                                                      | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| getRdbStore(context: Context, config: StoreConfig, version: number): Promise&lt;RdbStore&gt; | Obtains an RDB store. This API uses a promise to return the result. You can set parameters for the RDB store based on service requirements and call APIs to perform data operations.<br>- **context**: context of the application or function.<br>- **config**: configuration of the RDB store.<br>- **version**: version of the RDB store.|
| deleteRdbStore(context: Context, name: string): Promise&lt;void&gt; | Deletes an RDB store. This API uses a promise to return the result.<br>- **context**: context of the application or function.<br>- **name**: name of the RDB store to delete.|

### Managing Data in an RDB Store

The RDB provides APIs for inserting, deleting, updating, and querying data in the local RDB store.

- **Inserting Data**
  
  The RDB provides APIs for inserting data through a **ValuesBucket** in a data table. If the data is inserted, the row ID of the data inserted will be returned; otherwise, **-1** will be returned.
  
  **Table 2** API for inserting data
  

  | Class    | API                                                      | Description                                                        |
  | -------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
  | RdbStore | insert(table: string, values: ValuesBucket): Promise&lt;number&gt; | Inserts a row of data into a table. This API uses a promise to return the result.<br>If the operation is successful, the row ID will be returned; otherwise, **-1** will be returned.<br>- **table**: name of the target table.<br>- **values**: data to be inserted into the table.|
  
- **Updating Data**
  
  Call the **update()** method to pass new data and specify the update conditions by using **RdbPredicates**. If the data is updated, the number of rows of the updated data will be returned; otherwise, **0** will be returned.
  
  **Table 3** API for updating data
  

  | Class    | API                                                      | Description                                                        |
  | -------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
  | RdbStore | update(values: ValuesBucket, predicates: RdbPredicates): Promise&lt;number&gt; | Updates data based on the specified **RdbPredicates** object. This API uses a promise to return the result.<br>the number of rows updated.<br>- **values**: data to update, which is stored in **ValuesBucket**.<br>- **predicates**: conditions for updating data.|
  
- **Deleting Data**
  
  Call the **delete()** method to delete data meeting the conditions specified by **RdbPredicates**. If the data is deleted, the number of rows of the deleted data will be returned; otherwise, **0** will be returned.
  
  **Table 4** API for deleting data
  

  | Class    | API                                                      | Description                                                        |
  | -------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
  | RdbStore | delete(predicates: RdbPredicates): Promise&lt;number&gt; | Deletes data from the RDB store based on the specified **RdbPredicates** object. This API uses a promise to return<br>the number of rows updated.<br>- **predicates**: conditions for deleting data.|
  
- **Querying Data**

  You can query data in an RDB store in either of the following ways:

  - Call the **query()** method to query data based on the predicates, without passing any SQL statement.
  - Run the native SQL statement.

  **Table 5** APIs for querying data


  | Class    | API                                                      | Description                                                        |
  | -------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
  | RdbStore | query(predicates: RdbPredicates, columns?: Array&lt;string&gt;): Promise&lt;ResultSet&gt; | Queries data from the RDB store based on specified conditions. This API uses a promise to return the result.<br>- **predicates**: conditions for querying data.<br>- **columns**: columns to query. If this parameter is not specified, the query applies to all columns.|
  | RdbStore | querySql(sql: string, bindArgs?: Array&lt;ValueType&gt;): Promise&lt;ResultSet&gt; | Queries data using the specified SQL statement. This API uses a promise to return the result.<br>- **sql**: SQL statement.<br>- **bindArgs**: arguments in the SQL statement.|
  | RdbStore | remoteQuery(device: string, table: string, predicates: RdbPredicates, columns: Array&lt;string&gt;): Promise&lt;ResultSet&gt; | Queries data from the database of a remote device based on specified conditions. This API uses a promise to return the result.<br>- **device**: network ID of the remote device.<br>- **table**: name of the table to be queried.<br>- **predicates**: **RdbPredicates** that specifies the query condition.<br>- **columns**: columns to query. If this parameter is not specified, the query applies to all columns.|

### Using Predicates

The RDB provides **RdbPredicates** for you to set database operation conditions.

The following lists common predicates. For more information about predicates, see [**RdbPredicates**](../reference/apis/js-apis-data-rdb.md#rdbpredicates).

**Table 6** APIs for using RDB store predicates

| Class         | API                                                      | Description                                                        |
| ------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| RdbPredicates | equalTo(field: string, value: ValueType): RdbPredicates | Sets an **RdbPredicates** to match the field with data type **ValueType** and value equal to the specified value.<br>- **field**: column name in the database table.<br>- **value**: value to match the **RdbPredicates**.<br>- **RdbPredicates**: **RdbPredicates** object that matches the specified field.|
| RdbPredicates | notEqualTo(field: string, value: ValueType): RdbPredicates | Sets an **RdbPredicates** to match the field with data type **ValueType** and value not equal to the specified value.<br>- **field**: column name in the database table.<br>- **value**: value to match the **RdbPredicates**.<br>- **RdbPredicates**: **RdbPredicates** object that matches the specified field.|
| RdbPredicates | or(): RdbPredicates                                     | Adds the OR condition to the **RdbPredicates**.<br>- **RdbPredicates**: **RdbPredicates** with the OR condition.|
| RdbPredicates | and(): RdbPredicates                                    | Adds the AND condition to the **RdbPredicates**.<br>- **RdbPredicates**: **RdbPredicates** with the AND condition.|
| RdbPredicates | contains(field: string, value: string): RdbPredicates | Sets an **RdbPredicates** to match a string containing the specified value.<br>- **field**: column name in the database table.<br>- **value**: value to match the **RdbPredicates**.<br>- **RdbPredicates**: **RdbPredicates** object that matches the specified field.|


### Using the Result Set

A result set can be regarded as a row of data in the queried results. It allows you to traverse and access the data you have queried.

For details about how to use result set APIs, see [Result Set](../reference/apis/js-apis-data-resultset.md).

> **NOTICE**<br>
> After a result set is used, you must call the **close()** method to close it explicitly.

**Table 7** APIs for using the result set

| Class     | API                                              | Description                                      |
| --------- | ---------------------------------------------------- | ------------------------------------------ |
| ResultSet | goToFirstRow(): boolean                         | Moves to the first row of the result set.                    |
| ResultSet | getString(columnIndex: number): string     | Obtains the value in the form of a string based on the specified column and current row.  |
| ResultSet | getBlob(columnIndex: number): Uint8Array   | Obtains the value in the form of a byte array based on the specified column and the current row.|
| ResultSet | getDouble(columnIndex: number): number     | Obtains the value in the form of double based on the specified column and current row.    |
| ResultSet | getLong(columnIndex: number): number     | Obtains the value in the form of a long integer based on the specified column and current row.    |
| ResultSet | close(): void                                   | Closes the result set.                              |



### Setting Distributed Tables

>**CAUTION**<br>ohos.permission.DISTRIBUTED_DATASYNC is required for using the **setDistributedTables**, **obtainDistributedTableName**, **sync**, **on**, and **off** APIs of **RdbStore**.

**Setting Distributed Tables**

**Table 8** API for setting distributed tables

| Class    | API                                                      | Description                                                        |
| -------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| RdbStore | setDistributedTables(tables: Array\<string>): Promise\<void> | Sets distributed tables. This API uses a promise to return the result.<br>- **tables**: names of the distributed tables to set.|

**Obtaining the Distributed Table Name for a Remote Device**

You can obtain the distributed table name for a remote device based on the local table name. The distributed table name can be used to query the RDB store of the remote device.

**Table 9** API for obtaining the distributed table name of a remote device

| Class    | API                                                      | Description                                                        |
| -------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| RdbStore | obtainDistributedTableName(device: string, table: string): Promise\<string> | Obtains the distributed table name for a remote device based on the local table name. The distributed table name is required when the RDB store of a remote device is queried. This API uses a promise to return the result.<br>- **device**: remote device.<br>- **table**: local table name.|

**Synchronizing Data Between Devices**

**Table 10** API for synchronizing data between devices

| Class    | API                                                      | Description                                                        |
| -------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| RdbStore | sync(mode: SyncMode, predicates: RdbPredicates): Promise\<Array\<[string, number]>> | Synchronizes data between devices. This API uses a promise to return the result.<br>- **mode**: synchronization mode.  **SYNC_MODE_PUSH** means to push data from the local device to a remote device. **SYNC_MODE_PULL** means to pull data from a remote device to the local device.<br>- **predicates**: specifies the data and devices to synchronize.<br>- **string**: device ID. <br>- **number**: synchronization status of each device. The value **0** indicates a successful synchronization. Other values indicate a synchronization failure.|

**Registering an RDB Store Observer**

**Table 11** API for registering an observer

| Class    | API                                                      | Description                                                        |
| -------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| RdbStore | on(event: 'dataChange', type: SubscribeType, observer: Callback\<Array\<string>>): void | Registers an observer for this RDB store to subscribe to distributed data changes. When data in the RDB store changes, a callback will be invoked to return the data changes.<br>- **type**: subscription type. **SUBSCRIBE_TYPE_REMOTE** means to subscribe to remote data changes.<br>- **observer**: observer that listens for data changes in the RDB store.|

**Unregistering an RDB Store Observer**

**Table 12** API for unregistering an observer

| Class    | API                                                      | Description                                                        |
| -------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| RdbStore | off(event:'dataChange', type: SubscribeType, observer: Callback\<Array\<string>>): void; | Unregisters the observer of the specified type from the RDB store. This API uses an asynchronous callback to return the result.<br>- **type**: subscription type. **SUBSCRIBE_TYPE_REMOTE** means to subscribe to remote data changes.<br>- **observer**: observer to unregister.|

### Backing Up and Restoring an RDB Store

**Backing Up an RDB Store**

**Table 13** API for backing up an RDB store

| Class    | API                                                      | Description                                                        |
| -------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| RdbStore | backup(destName: string): Promise&lt;void&gt;                 | Backs up an RDB store. This API uses a promise to return the result.<br>- **destName**: name of the RDB backup file.|

**Restoring an RDB Store**

**Table 14** API for restoring an RDB store

| Class    | API                                                      | Description                                                        |
| -------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| RdbStore | restore(srcName: string): Promise&lt;void&gt;                 | Restores an RDB store from a backup file. This API uses a promise to return the result.<br>- **srcName**: name of the backup file used to restore the RDB store.|

**Transaction**

Table 15 Transaction APIs

| Class    | API                 | Description                             |
| -------- | ----------------------- | --------------------------------- |
| RdbStore | beginTransaction(): void | Starts the transaction before executing SQL statements.|
| RdbStore | commit(): void           | Commits the executed SQL statements.            |
| RdbStore | rollBack(): void         | Rolls back the SQL statements that have been executed.          |

## How to Develop

1. Create an RDB store.

   (1) Configure the RDB store attributes, including the RDB store name, storage mode, and whether read-only mode is used.

   (2) Initialize the table structure and related data in the RDB store.

   (3) Create an RDB store.

   FA model:

    ```js
   import data_rdb from '@ohos.data.rdb'
    // Obtain the context.
   import featureAbility from '@ohos.ability.featureAbility'
   let context = featureAbility.getContext()

   const CREATE_TABLE_TEST = "CREATE TABLE IF NOT EXISTS test (" + "id INTEGER PRIMARY KEY AUTOINCREMENT, " + "name TEXT NOT NULL, " + "age INTEGER, " + "salary REAL, " + "blobType BLOB)";

   const STORE_CONFIG = { name: "RdbTest.db" }
   data_rdb.getRdbStore(context, STORE_CONFIG, 1, function (err, rdbStore) {
      rdbStore.executeSql(CREATE_TABLE_TEST)
      console.info('create table done.')
   })
    ```
    Stage model:
     ```ts
   import data_rdb from '@ohos.data.rdb'
    // Obtain the context.
   import Ability from '@ohos.application.Ability'
   let context = null
   class MainAbility extends Ability {
       onWindowStageCreate(windowStage) {
         context = this.context
       }
   }

   const CREATE_TABLE_TEST = "CREATE TABLE IF NOT EXISTS test (" + "id INTEGER PRIMARY KEY AUTOINCREMENT, " + "name TEXT NOT NULL, " + "age INTEGER, " + "salary REAL, " + "blobType BLOB)";

   const STORE_CONFIG = { name: "rdbstore.db" }
   data_rdb.getRdbStore(context, STORE_CONFIG, 1, function (err, rdbStore) {
       rdbStore.executeSql(CREATE_TABLE_TEST)
       console.info('create table done.')
   })
    ```

2. Insert data.

   (1) Create a **ValuesBucket** to store the data you need to insert.

   (2) Call the **insert()** method to insert data into the RDB store.

   The sample code is as follows:

    ```js
    var u8 = new Uint8Array([1, 2, 3])
    const valueBucket = { "name": "Tom", "age": 18, "salary": 100.5, "blobType": u8 }
    let insertPromise = rdbStore.insert("test", valueBucket)
    ```

3. Query data.

   (1) Create an **RdbPredicates** object to specify query conditions.

   (2) Call the **query()** API to query data.

   (3) Call the **resultSet()** API to obtain the result.

   The sample code is as follows:

    ```js
    let predicates = new data_rdb.RdbPredicates("test");
    predicates.equalTo("name", "Tom")
    let promisequery = rdbStore.query(predicates)
    promisequery.then((resultSet) => {
        resultSet.goToFirstRow()
        const id = resultSet.getLong(resultSet.getColumnIndex("id"))
        const name = resultSet.getString(resultSet.getColumnIndex("name"))
        const age = resultSet.getLong(resultSet.getColumnIndex("age"))
        const salary = resultSet.getDouble(resultSet.getColumnIndex("salary"))
        const blobType = resultSet.getBlob(resultSet.getColumnIndex("blobType"))
        resultSet.close()
    })
    ```

4. Set the distributed tables to be synchronized.

    (1) Add the following permission to the permission configuration file:   

    ```json
    "requestPermissions": 
      {
        "name": "ohos.permission.DISTRIBUTED_DATASYNC"
      }
    ```

    (2) Obtain the required permissions.

    (3) Set the distributed tables.

    (4) Check whether the setting is successful.

   The sample code is as follows:

    ```js
    let context = featureAbility.getContext();
    context.requestPermissionsFromUser(['ohos.permission.DISTRIBUTED_DATASYNC'], 666, function (result) {
        console.info(`result.requestCode=${result.requestCode}`)
    })
    let promise = rdbStore.setDistributedTables(["test"])
    promise.then(() => {
        console.info("setDistributedTables success.")
    }).catch((err) => {
        console.info("setDistributedTables failed.")
    })
    ```

5. Synchronize data across devices.

    (1) Construct an **RdbPredicates** object to specify remote devices within the network to be synchronized.

    (2) Call **rdbStore.sync()** to synchronize data.

    (3) Check whether the data synchronization is successful.

    The sample code is as follows:

    ```js
    let predicate = new data_rdb.RdbPredicates('test')
    predicate.inDevices(['12345678abcde'])
    let promise = rdbStore.sync(data_rdb.SyncMode.SYNC_MODE_PUSH, predicate)
    promise.then((result) => {
        console.log('sync done.')
        for (let i = 0; i < result.length; i++) {
            console.log('device=' + result[i][0] + 'status=' + result[i][1])
        }
    }).catch((err) => {
        console.log('sync failed')
    })
    ```

6. Subscribe to distributed data.
  
    (1) Register an observer to listen for distributed data changes.

    (2) When data in the RDB store changes, a callback will be invoked to return the data changes.

    The sample code is as follows:

    ```js
    function storeObserver(devices) {
        for (let i = 0; i < devices.length; i++) {
            console.log('device=' + device[i] + 'data changed')
        }
    }

    try {
        rdbStore.on('dataChange', data_rdb.SubscribeType.SUBSCRIBE_TYPE_REMOTE, storeObserver)
    } catch (err) {
        console.log('register observer failed')
    }
    ```

7. Query data across devices.
   
    (1) Obtain the distributed table name for a remote device based on the local table name.

    (2) Call the resultSet() API to obtain the result.

    The sample code is as follows:

    ```js
    let tableName = rdbStore.obtainDistributedTableName(deviceId, "test");
    let resultSet = rdbStore.querySql("SELECT * FROM " + tableName)
    ```
    
8. Query data of a remote device.
   
   
   (1) Construct a predicate object for querying distributed tables, and specify the remote distributed table name and the remote device.
   
   (2) Call the resultSet() API to obtain the result.
   
   The sample code is as follows:
   
    ```js
    let rdbPredicate = new data_rdb.RdbPredicates('employee')
    predicates.greaterThan("id", 0) 
    let promiseQuery = rdbStore.remoteQuery('12345678abcde', 'employee', rdbPredicate)
    promiseQuery.then((resultSet) => {
        while (resultSet.goToNextRow()) {
            let idx = resultSet.getLong(0);
            let name = resultSet.getString(1);
            let age = resultSet.getLong(2);
            console.info(idx + " " + name + " " + age);
        }
        resultSet.close();
    }).catch((err) => {
        console.info("failed to remoteQuery, err: " + err)
    })
    ```
   
9. Back up and restore an RDB store.

   (1) Back up the current RDB store.

    The sample code is as follows:

    ```js
    let promiseBackup = rdbStore.backup("dbBackup.db")
    promiseBackup.then(() => {
        console.info('Backup success.')
    }).catch((err) => {
        console.info('Backup failed, err: ' + err)
    })
    ```
   (2) Restore the RDB store using the backup file.
   
    The sample code is as follows:

    ```js
    let promiseRestore = rdbStore.restore("dbBackup.db")
    promiseRestore.then(() => {
        console.info('Restore success.')
    }).catch((err) => {
        console.info('Restore failed, err: ' + err)
    })
    ```
