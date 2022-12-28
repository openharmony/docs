# RDB Development

## When to Use

A relational database (RDB) store allows you to operate local data with or without native SQL statements based on SQLite.


## Available APIs

Most of the RDB store APIs are asynchronous interfaces, which can use a callback or promise to return the result. This document uses the promise-based APIs as an example. For details about the APIs, see [Relational Database](../reference/apis/js-apis-data-rdb.md).

### Creating or Deleting an RDB Store

The following table describes the APIs for creating and deleting an RDB store.

**Table 1** APIs for creating and deleting an RDB store

| API                                                      | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| getRdbStoreV9(context: Context, config: StoreConfigV9, version: number): Promise&lt;RdbStoreV9&gt; | Obtains an **RdbStoreV9** instance. This API uses a promise to return the result. You can set parameters for the RDB store based on service requirements and call APIs to perform data operations.<br>- **context**: context of the application or function.<br>- **config**: configuration of the RDB store.<br>- **version**: version of the RDB store. Currently, automatic RDB upgrades and downgrades performed based on **version** is not supported.|
| deleteRdbStoreV9(context: Context, name: string): Promise&lt;void&gt; | Deletes an RDB store. This API uses a promise to return the result.<br>- **context**: context of the application or function.<br>- **name**: name of the RDB store to delete.|

### Managing Data in an RDB Store

The RDB provides APIs for inserting, deleting, updating, and querying data in the local RDB store.

- **Inserting Data**
  
  The RDB provides APIs for inserting data through a **ValuesBucket** in a data table. If the data is inserted, the row ID of the data inserted will be returned; otherwise, **-1** will be returned.
  
  **Table 2** API for inserting data
  

  | Class      | API                                                      | Description                                                        |
  | ---------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
  | RdbStoreV9 | insert(table: string, values: ValuesBucket): Promise&lt;number&gt; | Inserts a row of data into a table. This API uses a promise to return the result.<br>If the operation is successful, the row ID will be returned; otherwise, **-1** will be returned.<br>- **table**: name of the target table.<br>- **values**: data to be inserted into the table.|
  
- **Updating Data**
  
  Call **update()** to update data based on the passed data and the conditions specified by **RdbPredicatesV9**. If the data is updated, the number of rows of the updated data will be returned; otherwise, **0** will be returned.
  
  **Table 3** API for updating data
  

  | Class      | API                                                          | Description                                                  |
  | ---------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
  | RdbStoreV9 | update(values: ValuesBucket, predicates: RdbPredicatesV9): Promise&lt;number&gt; | Updates data based on the specified **RdbPredicatesV9** object. This API uses a promise to return the number of rows updated.<br>- **values**: data to update, which is stored in **ValuesBucket**.<br>- **predicates**: conditions for updating data. |
  
- **Deleting Data**
  
  Call **delete()** to delete the data that meets the conditions specified by **RdbPredicatesV9**. If the data is deleted, the number of rows of the deleted data will be returned; otherwise, **0** will be returned.
  
  **Table 4** API for deleting data
  

  | Class      | API                                                        | Description                                                  |
  | ---------- | ---------------------------------------------------------- | ------------------------------------------------------------ |
  | RdbStoreV9 | delete(predicates: RdbPredicatesV9): Promise&lt;number&gt; | Deletes data from the RDB store based on the specified **RdbPredicatesV9** object. This API uses a promise to return the number of rows updated.<br>- **predicates**: conditions for deleting data. |
  
- **Querying Data**

  You can query data in an RDB store in either of the following ways:

  - Call the **query()** method to query data based on the predicates, without passing any SQL statement.
  - Run the native SQL statement.

  **Table 5** APIs for querying data


| Class      | API                                                      | Description                                                        |
| ---------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| RdbStoreV9 | query(predicates: RdbPredicatesV9, columns?: Array&lt;string&gt;): Promise&lt;ResultSetV9&gt; | Queries data from the RDB store based on specified conditions. This API uses a promise to return the result.<br>- **predicates**: conditions for querying data.<br>- **columns**: columns to query. If this parameter is not specified, the query applies to all columns.|
| RdbStoreV9 | querySql(sql: string, bindArgs?: Array&lt;ValueType&gt;): Promise&lt;ResultSetV9&gt; | Queries data using the specified SQL statement. This API uses a promise to return the result.<br>- **sql**: SQL statement.<br>- **bindArgs**: arguments in the SQL statement.|
| RdbStoreV9 | remoteQuery(device: string, table: string, predicates: RdbPredicatesV9, columns: Array&lt;string&gt;): Promise&lt;ResultSetV9&gt; | Queries data from the database of a remote device based on specified conditions. This API uses a promise to return the result.<br>- **device**: network ID of the remote device.<br>- **table**: name of the table to be queried.<br>- **predicates**: **RdbPredicatesV9** that specifies the query conditions.<br>- **columns**: columns to query. If this parameter is not specified, the query applies to all columns.|

### Using Predicates

The **RDB** module provides **RdbPredicatesV9** for you to set database operation conditions.

The following table lists common predicates. For more information about predicates, see [**RdbPredicates**](../reference/apis/js-apis-data-rdb.md#rdbpredicates).

**Table 6** APIs for using RDB store predicates

| Class           | API                                                          | Description                                                  |
| --------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| RdbPredicatesV9 | equalTo(field: string, value: ValueType): RdbPredicatesV9    | Sets an **RdbPredicatesV9** to search for the data that is equal to the specified value.<br>- **field**: column name in the database table.<br>- **value**: value to match.<br>- **RdbPredicatesV9**: **RdbPredicatesV9** object created. |
| RdbPredicatesV9 | notEqualTo(field: string, value: ValueType): RdbPredicatesV9 | Sets an **RdbPredicatesV9** to search for the data that is not equal to the specified value.<br>- **field**: column name in the database table.<br>- **value**: value to match.<br>- **RdbPredicatesV9**: **RdbPredicatesV9** object created. |
| RdbPredicatesV9 | or(): RdbPredicatesV9                                        | Adds the OR condition to the **RdbPredicatesV9**.<br>- **RdbPredicatesV9**: **RdbPredicatesV9** with the OR condition. |
| RdbPredicatesV9 | and(): RdbPredicatesV9                                       | Adds the AND condition to the **RdbPredicatesV9**.<br>- **RdbPredicatesV9**: **RdbPredicatesV9** with the AND condition. |
| RdbPredicatesV9 | contains(field: string, value: string): RdbPredicatesV9      | Sets an **RdbPredicatesV9** to search for the data that contains the specified value.<br>- **field**: column name in the database table.<br>- **value**: value to match.<br>- **RdbPredicatesV9**: **RdbPredicatesV9** object created. |


### Using the Result Set

You can use the APIs provided by **ResultSetV9** to traverse and access the data you have queried. A result set can be regarded as a row of data in the queried result.

For details about how to use result set APIs, see [Result Set](../reference/apis/js-apis-data-resultset.md).

> **NOTICE**
>
> After a result set is used, you must call the **close()** method to close it explicitly.

**Table 7** APIs for using the result set

| Class       | API                                  | Description                                      |
| ----------- | ---------------------------------------- | ------------------------------------------ |
| ResultSetV9 | goToFirstRow(): boolean                  | Moves to the first row of the result set.                    |
| ResultSetV9 | getString(columnIndex: number): string   | Obtains the value in the form of a string based on the specified column and current row.  |
| ResultSetV9 | getBlob(columnIndex: number): Uint8Array | Obtains the value in the form of a byte array based on the specified column and the current row.|
| ResultSetV9 | getDouble(columnIndex: number): number   | Obtains the value in the form of double based on the specified column and current row.    |
| ResultSetV9 | getLong(columnIndex: number): number     | Obtains the value in the form of a long integer based on the specified column and current row.    |
| ResultSetV9 | close(): void                            | Closes the result set.                              |



### Setting Distributed Tables

> **NOTE** 
>
> - The **ohos.permission.DISTRIBUTED_DATASYNC** permission is required for calling the **setDistributedTables**, **obtainDistributedTableName**, **sync**, **on** and **off** APIs of **RdbStore V9**.
> - The devices must be connected over network before the distributed tables are used. For details about the APIs and usage, see [Device Management](../reference/apis/js-apis-device-manager.md).

**Setting Distributed Tables**

**Table 8** API for setting distributed tables

| Class      | API                                                      | Description                                                        |
| ---------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| RdbStoreV9 | setDistributedTables(tables: Array\<string>): Promise\<void> | Sets distributed tables. This API uses a promise to return the result.<br>- **tables**: names of the distributed tables to set.|

**Obtaining the Distributed Table Name for a Remote Device**

You can obtain the distributed table name for a remote device based on the local table name. The distributed table name can be used to query the RDB store of the remote device.

**Table 9** API for obtaining the distributed table name of a remote device

| Class      | API                                                      | Description                                                        |
| ---------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| RdbStoreV9 | obtainDistributedTableName(device: string, table: string): Promise\<string> | Obtains the distributed table name for a remote device based on the local table name. The distributed table name is required when the RDB store of a remote device is queried. This API uses a promise to return the result.<br>- **device**: remote device.<br>- **table**: local table name.|

**Synchronizing Data Between Devices**

**Table 10** API for synchronizing data between devices

| Class      | API                                                      | Description                                                        |
| ---------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| RdbStoreV9 | sync(mode: SyncMode, predicates: RdbPredicatesV9): Promise\<Array\<[string, number]>> | Synchronizes data between devices. This API uses a promise to return the result.<br>- **mode**: synchronization mode.  **SYNC_MODE_PUSH** means to push data from the local device to a remote device. **SYNC_MODE_PULL** means to pull data from a remote device to the local device.<br>- **predicates**: specifies the data and devices to synchronize.<br>- **string**: device ID. <br>- **number**: synchronization status of each device. The value **0** indicates a successful synchronization. Other values indicate a synchronization failure.|

**Registering an RDB Store Observer**

**Table 11** API for registering an observer

| Class      | API                                                      | Description                                                        |
| ---------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| RdbStoreV9 | on(event: 'dataChange', type: SubscribeType, observer: Callback\<Array\<string>>): void | Registers an observer for this RDB store to subscribe to distributed data changes. When data in the RDB store changes, a callback will be invoked to return the data changes.<br>- **type**: subscription type. **SUBSCRIBE_TYPE_REMOTE**: subscribes to remote data changes.<br>- **observer**: observer that listens for data changes in the RDB store.|

**Unregistering an RDB Store Observer**

**Table 12** API for unregistering an observer

| Class      | API                                                      | Description                                                        |
| ---------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| RdbStoreV9 | off(event:'dataChange', type: SubscribeType, observer: Callback\<Array\<string>>): void; | Unregisters the observer of the specified type from the RDB store. This API uses an asynchronous callback to return the result.<br>- **type**: subscription type. **SUBSCRIBE_TYPE_REMOTE**: subscribes to remote data changes.<br>- **observer**: observer to unregister.|

### Backing Up and Restoring an RDB Store

**Backing Up an RDB Store**

**Table 13** API for backing up an RDB store

| Class      | API                                       | Description                                                        |
| ---------- | --------------------------------------------- | ------------------------------------------------------------ |
| RdbStoreV9 | backup(destName: string): Promise&lt;void&gt; | Backs up an RDB store. This API uses a promise to return the result.<br>- **destName**: name of the RDB backup file.|

**Restoring an RDB Store**

**Table 14** API for restoring an RDB store

| Class      | API                                       | Description                                                        |
| ---------- | --------------------------------------------- | ------------------------------------------------------------ |
| RdbStoreV9 | restore(srcName: string): Promise&lt;void&gt; | Restores an RDB store from a backup file. This API uses a promise to return the result.<br>- **srcName**: name of the backup file used to restore the RDB store.|

**Transaction**

Table 15 Transaction APIs

| Class    | API                 | Description                             |
| -------- | ----------------------- | --------------------------------- |
| RdbStoreV9 | beginTransaction(): void | Starts the transaction before executing SQL statements.|
| RdbStoreV9 | commit(): void           | Commits the executed SQL statements.            |
| RdbStoreV9 | rollBack(): void         | Rolls back the SQL statements that have been executed.          |

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
   
   const STORE_CONFIGV9 = { name: "RdbTest.db",
                         securityLevel: data_rdb.SecurityLevel.S1}
   data_rdb.getRdbStoreV9(context, STORE_CONFIGV9, 1, function (err, rdbStoreV9) {
      rdbStoreV9.executeSql(CREATE_TABLE_TEST)
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
   
   const STORE_CONFIGV9 = { name: "rdbstore.db",
                          securityLevel: data_rdb.SecurityLevel.S1}
   data_rdb.getRdbStoreV9(context, STORE_CONFIGV9, 1, function (err, rdbStoreV9) {
       rdbStoreV9.executeSql(CREATE_TABLE_TEST)
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
    let insertPromise = rdbStoreV9.insert("test", valueBucket)
    ```

3. Query data.

   (1) Create an **RdbPredicatesV9** object to specify query conditions.

   (2) Call the **query()** API to query data.

   (3) Call the **resultSet()** API to obtain the result.

   The sample code is as follows:

    ```js
    let predicatesV9 = new data_rdb.RdbPredicatesV9("test");
    predicatesV9.equalTo("name", "Tom")
    let promisequery = rdbStoreV9.query(predicatesV9)
    promisequery.then((resultSetV9) => {
        resultSetV9.goToFirstRow()
        const id = resultSetV9.getLong(resultSetV9.getColumnIndex("id"))
        const name = resultSetV9.getString(resultSetV9.getColumnIndex("name"))
        const age = resultSetV9.getLong(resultSetV9.getColumnIndex("age"))
        const salary = resultSetV9.getDouble(resultSetV9.getColumnIndex("salary"))
        const blobType = resultSetV9.getBlob(resultSetV9.getColumnIndex("blobType"))
        resultSetV9.close()
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
    let promise = rdbStoreV9.setDistributedTables(["test"])
    promise.then(() => {
        console.info("setDistributedTables success.")
    }).catch((err) => {
        console.info("setDistributedTables failed.")
    })
    ```

5. Synchronize data across devices.

    (1) Construct an **RdbPredicatesV9** object to specify remote devices within the network to be synchronized.

    (2) Call **rdbStore.sync()** to synchronize data.

    (3) Check whether the data synchronization is successful.

    The sample code is as follows:

    ```js
    let predicateV9 = new data_rdb.RdbPredicatesV9('test')
    predicateV9.inDevices(['12345678abcde'])
    let promise = rdbStoreV9.sync(data_rdb.SyncMode.SYNC_MODE_PUSH, predicateV9)
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
        rdbStoreV9.on('dataChange', data_rdb.SubscribeType.SUBSCRIBE_TYPE_REMOTE, storeObserver)
    } catch (err) {
        console.log('register observer failed')
    }
    ```

7. Query data across devices.
   
    (1) Obtain the distributed table name for a remote device based on the local table name.

    (2) Call the resultSet() API to obtain the result.

    The sample code is as follows:

    ```js
    let tableName = rdbStoreV9.obtainDistributedTableName(deviceId, "test");
    let resultSetV9 = rdbStoreV9.querySql("SELECT * FROM " + tableName)
    ```
    
8. Query data of a remote device.
   
   
   (1) Construct a predicate object for querying distributed tables, and specify the remote distributed table name and the remote device.
   
   (2) Call the resultSet() API to obtain the result.
   
   The sample code is as follows:
   
    ```js
    let rdbPredicateV9 = new data_rdb.RdbPredicatesV9('employee')
    predicatesV9.greaterThan("id", 0) 
    let promiseQuery = rdbStoreV9.remoteQuery('12345678abcde', 'employee', rdbPredicateV9)
    promiseQuery.then((resultSetV9) => {
        while (resultSetV9.goToNextRow()) {
            let idx = resultSetV9.getLong(0);
            let name = resultSetV9.getString(1);
            let age = resultSetV9.getLong(2);
            console.info(idx + " " + name + " " + age);
        }
        resultSetV9.close();
    }).catch((err) => {
        console.info("failed to remoteQuery, err: " + err)
    })
    ```
   
9. Back up and restore an RDB store.

   (1) Back up the current RDB store.

    The sample code is as follows:

    ```js
    let promiseBackup = rdbStoreV9.backup("dbBackup.db")
    promiseBackup.then(() => {
        console.info('Backup success.')
    }).catch((err) => {
        console.info('Backup failed, err: ' + err)
    })
    ```
   (2) Restore the RDB store using the backup file.
   
    The sample code is as follows:

    ```js
    let promiseRestore = rdbStoreV9.restore("dbBackup.db")
    promiseRestore.then(() => {
        console.info('Restore success.')
    }).catch((err) => {
        console.info('Restore failed, err: ' + err)
    })
    ```
