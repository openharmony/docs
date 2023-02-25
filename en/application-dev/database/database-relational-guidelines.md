# RDB Development

## When to Use

A relational database (RDB) store allows you to manage local data with or without native SQL statements based on SQLite.


## Available APIs
Most of the RDB store APIs are asynchronous interfaces, which can use a callback or promise to return the result. This document uses the promise-based APIs as an example. For details about the APIs, see [Relational Database](../reference/apis/js-apis-data-rdb.md).

### Creating or Deleting an RDB Store

The following table describes the APIs available for creating and deleting an RDB store.

**Table 1** APIs for creating and deleting an RDB store

| API| Description|
| -------- | -------- |
|getRdbStore(config: StoreConfig, version: number): Promise&lt;RdbStore&gt; | Obtains an RDB store. This API uses a promise to return the result. You can set parameters for the RDB store based on service requirements and call APIs to perform data operations.<br>- **config**: configuration of the RDB store.<br>- **version**: version of the RDB store.|
| deleteRdbStore(name: string): Promise&lt;void&gt; | Deletes an RDB store. This API uses a promise to return the result.<br>- **name**: name of the RDB store to delete.|

### Managing Data in an RDB Store

The **RDB** module provides APIs for inserting, deleting, updating, and querying data in a local RDB store.

- **Inserting Data**
  
  The **RDB** module provides APIs for inserting data through a **ValuesBucket** in a data table. If the data is inserted, the row ID of the data inserted will be returned; otherwise, **-1** will be returned.
  
  **Table 2** API for inserting data
  
  | Class| API| Description|
  | -------- | -------- | -------- |
  | RdbStore | insert(name: string, values: ValuesBucket): Promise&lt;number&gt; | Inserts a row of data into a table. This API uses a promise to return the result.<br>If the operation is successful, the row ID will be returned; otherwise, **-1** will be returned.<br>- **name**: name of the target table.<br>- **values**: data to be inserted into the table.|
  
- **Updating Data**
  
  Call the **update()** method to pass new data and specify the update conditions by using **RdbPredicates**. If the data is updated, the number of rows of the updated data will be returned; otherwise, **0** will be returned.
  
  **Table 3** API for updating data
  
  | Class| API| Description|
  | -------- | -------- | -------- |
  | RdbStore | update(values: ValuesBucket, rdbPredicates: RdbPredicates): Promise\<number> | Updates data based on the specified **RdbPredicates** object. This API uses a promise to return the result.<br>Return value: number of rows updated.<br>- **values**: data to update, which is stored in **ValuesBucket**.<br>- **rdbPredicates**: conditions for updating data.|
  
- **Deleting Data**
  
  Call the **delete()** method to delete data meeting the conditions specified by **RdbPredicates**. If the data is deleted, the number of rows of the deleted data will be returned; otherwise, **0** will be returned.
  
  **Table 4** API for deleting data
  
  | Class| API| Description|
  | -------- | -------- | -------- |
  | RdbStore | delete(rdbPredicates: RdbPredicates): Promise\<number> | Deletes data from the RDB store based on the specified **RdbPredicates** object. This API uses a promise to return the result.<br>Return value: number of rows updated.<br>- **rdbPredicates**: conditions for deleting data.|
  
- **Querying data**

  You can query data in an RDB store in either of the following ways:

  - Call the **query()** method to query data based on the predicates, without passing any SQL statement.
  - Run the native SQL statement.

  **Table 5** APIs for querying data

  | Class| API| Description|
  | -------- | -------- | -------- |
  | RdbStore | query(rdbPredicates: RdbPredicates, columns: Array): Promise&lt;ResultSet&gt; | Queries data from the RDB store based on specified conditions. This API uses a promise to return the result.<br>- **rdbPredicates**: conditions for querying data.<br>- **columns**: columns to query. If this parameter is not specified, the query applies to all columns.|
  | RdbStore | querySql(sql: string, bindArgs?: Array&lt;ValueType&gt;): Promise&lt;ResultSet&gt; | Queries data using the specified SQL statement. This API uses a promise to return the result.<br>- **sql**: SQL statement.<br>- **bindArgs**: arguments in the SQL statement.|

### Using Predicates

The **RDB** module provides **RdbPredicates** for you to set database operation conditions.

The following table lists common predicates. For more information about predicates, see [**RdbPredicates**](../reference/apis/js-apis-data-rdb.md#rdbpredicates).

**Table 6** APIs for using RDB store predicates

| Class| API| Description|
| -------- | -------- | -------- |
| RdbPredicates | equalTo(field: string, value: ValueType): RdbPredicates | Sets an **RdbPredicates** object to match the field with data type **ValueType** and value equal to the specified value.<br>- **field**: column name in the database table.<br>- **value**: value to match the **RdbPredicates**.<br>- **RdbPredicates**: **RdbPredicates** object created.|
| RdbPredicates | notEqualTo(field: string, value: ValueType): RdbPredicates | Sets an **RdbPredicates** object to match the field with data type **ValueType** and value not equal to the specified value.<br>- **field**: column name in the database table.<br>- **value**: value to match the **RdbPredicates**.<br>- **RdbPredicates**: **RdbPredicates** object created.|
| RdbPredicates | or(): RdbPredicates | Adds the OR condition to the **RdbPredicates** object.<br>- **RdbPredicates**: **RdbPredicates** with the OR condition.|
| RdbPredicates | and(): RdbPredicates | Adds the AND condition to the **RdbPredicates** object.<br>- **RdbPredicates**: **RdbPredicates** with the AND condition.|
| RdbPredicates | contains(field: string, value: string): RdbPredicats | Sets an **RdbPredicates** object to match a string that contains the specified value.<br>- **field**: column name in the database table.<br>- **value**: value to match the **RdbPredicates**.<br>- **RdbPredicates**: **RdbPredicates** object created.|


### Using the Result Set

A result set can be regarded as a row of data in the queried results. It allows you to traverse and access the data you have queried.

For details about how to use result set APIs, see [Result Set](../reference/apis/js-apis-data-resultset.md).

> **NOTICE**<br>
> After a result set is used, you must call the **close()** method to close it explicitly.

**Table 7** APIs for using the result set

| Class| API| Description|
| -------- | -------- | -------- |
| ResultSet | goToFirstRow(): boolean | Moves to the first row of the result set.|
| ResultSet | getString(columnIndex:number): string | Obtains the value in the form of a string based on the specified column and current row.|
| ResultSet | getBlob(columnIndex:number): Uint8Array | Obtains the value in the form of a byte array based on the specified column and the current row.|
| ResultSet | getDouble(columnIndex:number): number | Obtains the value in the form of double based on the specified column and current row.|
| ResultSet | getLong(columnIndex:number): number     | Obtains the value in the form of a long integer based on the specified column and current row.    |
| ResultSet | close(): void | Closes the result set.|



### Setting Distributed Tables

**Setting Distributed Tables**

**Table 8** API for setting distributed tables

| Class| API| Description|
| -------- | -------- | -------- |
| RdbStore | setDistributedTables(tables: Array\<string>): Promise\<void>; | Sets distributed tables. This API uses a promise to return the result.<br>- **tables**: names of the distributed tables to set.|

**Obtaining the Distributed Table Name for a Remote Device**

You can obtain the distributed table name for a remote device based on the local table name. The distributed table name can be used to query the RDB store of the remote device.

**Table 9** API for obtaining the distributed table name of a remote device

| Class| API| Description|
| -------- | -------- | -------- |
| RdbStore | obtainDistributedTableName(device: string, table: string): Promise\<string>; | Obtains the distributed table name for a remote device based on the local table name. The distributed table name is required when the RDB store of a remote device is queried.<br>- **device**: remote device.<br>- **table**: local table name.|

**Synchronizing Data Between Devices**

**Table 10** API for synchronizing data between devices

| Class| API| Description|
| -------- | -------- | -------- |
| RdbStore | sync(mode: SyncMode, predicates: RdbPredicates): Promise<Array<[string, number]>>;| Synchronizes data between devices. This API uses a promise to return the result.<br>- **mode**: synchronization mode.  **SYNC_MODE_PUSH** means to push data from the local device to a remote device. **SYNC_MODE_PULL** means to pull data from a remote device to the local device.<br>- **predicates**: specifies the data and devices to synchronize.<br>- **string**: device ID. <br>- **number**: synchronization status of that device. The value **0** indicates a successful synchronization. Other values indicate a synchronization failure. |

**Registering an RDB Store Observer**

**Table 11** API for registering an observer

| Class| API| Description|
| -------- | -------- | -------- |
| RdbStore |on(event: 'dataChange', type: SubscribeType, observer: Callback<Array\<string>>): void;| Registers an observer for this RDB store to subscribe to distributed data changes. When data in the RDB store changes, a callback will be invoked to return the data changes.<br>- **type**: subscription type. **SUBSCRIBE_TYPE_REMOTE** means to subscribe to remote data changes.<br>- **observer**: observer that listens for data changes in the RDB store.|

**Unregistering an RDB Store Observer**

**Table 12** API for unregistering an observer

| Class| API| Description|
| -------- | -------- | -------- |
| RdbStore |off(event:'dataChange', type: SubscribeType, observer: Callback<Array\<string>>): void;| Unregisters the observer of the specified type for the RDB store. This method uses a callback to return the result.<br>- **type**: subscription type. **SUBSCRIBE_TYPE_REMOTE** means to subscribe to remote data changes.<br>- **observer**: observer to unregister.|


## How to Develop

1. Create an RDB store.
   1. Configure the RDB store attributes, including the RDB store name, storage mode, and whether read-only mode is used.
   2. Initialize the table structure and related data in the RDB store.
   3. Create an RDB store.

   The sample code is as follows:

   ```js
   import data_rdb from '@ohos.data.rdb'
   
   const CREATE_TABLE_TEST = "CREATE TABLE IF NOT EXISTS test (" + "id INTEGER PRIMARY KEY AUTOINCREMENT, " + "name TEXT NOT NULL, " + "age INTEGER, " + "salary REAL, " + "blobType BLOB)";
   const STORE_CONFIG = {name: "rdbstore.db"}
   data_rdb.getRdbStore(STORE_CONFIG, 1, function (err, rdbStore) {
       rdbStore.executeSql(CREATE_TABLE_TEST )
       console.info('create table done.')
   })
   ```

2. Insert data.
   1. Create a **ValuesBucket** to store the data you need to insert.
   2. Call the **insert()** method to insert data into the RDB store.

   The sample code is as follows:

   ```js
   var u8 = new Uint8Array([1, 2, 3])
   const valueBucket = {"name": "Tom", "age": 18, "salary": 100.5, "blobType": u8}
   let insertPromise = rdbStore.insert("test", valueBucket)
   ```

3. Query data.
   1. Create an **RdbPredicates** object to specify query conditions.
   2. Call the **query()** method to query data.
   3. Call the **ResultSet()** method to obtain the query result.

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
   1. Set the distributed tables.
   2. Check whether the setting is successful.

   The sample code is as follows:

   ```js
   let promise = rdbStore.setDistributedTables(["test"])
   promise.then(() => {
       console.info("setDistributedTables success.")
   }).catch((err) => {
       console.info("Failed to set distributed tables.")
   })
   ```

 5. Synchronize data across devices.
    1. Construct an **RdbPredicates** object to specify remote devices within the network to be synchronized.
    2. Call the **sync()** method to synchronize data.
    3. Check whether the data synchronization is successful.

    The sample code is as follows:

    ```js
    let predicate = new data_rdb.RdbPredicates('test')
    predicate.inDevices(['12345678abcde'])
    let promise = rdbStore.sync(rdb.SyncMode.SYNC_MODE_PUSH, predicate)
    promise.then((result) => {
        console.log('sync done.')
        for (let i = 0; i < result.length; i++) {
            console.log('device=' + result[i][0] + ' status=' + result[i][1])
        }
    }).catch((err) => {
        console.log('sync failed')
    })
    ```

6. Subscribe to distributed data.
    1. Register an observer to listen for distributed data changes.
    2. When data in the RDB store changes, a callback will be invoked to return the data changes.

    The sample code is as follows:

    ```js
    function storeObserver(devices) {
        for (let i = 0; i < devices.length; i++) {
            console.log('device=' + devices[i] + ' data changed')
        }
    }
    try {
        rdbStore.on('dataChange', rdb.SubscribeType.SUBSCRIBE_TYPE_REMOTE, storeObserver)
    } catch (err) {
        console.log('Failed to register observer')
    }
    ```

7. Query data across devices.
    1. Obtain the distributed table name for a remote device based on the local table name.
    2. Call the **ResultSet()** method to obtain the query result.

    The sample code is as follows:

    ```js
    let tableName = rdbStore.obtainDistributedTableName(deviceId, "test");
    let resultSet = rdbStore.querySql("SELECT * FROM " + tableName)
    ```
