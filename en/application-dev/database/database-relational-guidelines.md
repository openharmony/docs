# RDB Development

## When to Use

On the basis of the SQLite database, the relational database (RDB) allows you to operate data with or without native SQL statements. In OpenHarmony, an RDB is also called RDB store.


## Available APIs

### Creating or Deleting an RDB Store

The following table describes the APIs available for creating and deleting an RDB store.

**Table 1** APIs for creating and deleting an RDB store

| API| Description|
| -------- | -------- |
|getRdbStore(config:&nbsp;StoreConfig,&nbsp;version:&nbsp;number,&nbsp;callback:&nbsp;AsyncCallback&lt;RdbStore&gt;):&nbsp;void | Obtains an RDB store. This method uses a callback to return the result. You can set parameters for the RDB store based on service requirements, and then call APIs to perform data operations.<br>-&nbsp;**config**: configuration of the RDB store.<br>-&nbsp;**version**: RDB version.<br>-&nbsp;**callback**: callback invoked to return the RDB store obtained.|
|getRdbStore(config:&nbsp;StoreConfig,&nbsp;version:&nbsp;number):&nbsp;Promise&lt;RdbStore&gt; | Obtains an RDB store. This method uses a promise to return the result. You can set parameters for the RDB store based on service requirements, and then call APIs to perform data operations.<br>-&nbsp;**config**: configuration of the RDB store.<br>-&nbsp;**version**: RDB version.|
|deleteRdbStore(name:&nbsp;string,&nbsp;callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void | Deletes an RDB store. This method uses a callback to return the result. <br>-&nbsp;**name**: RDB store to delete.<br>-&nbsp;**callback**: callback invoked to return the result.|
| deleteRdbStore(name:&nbsp;string):&nbsp;Promise&lt;void&gt; | Deletes an RDB store. This method uses a promise to return the result.<br>-&nbsp;**name**: RDB store to delete.|

### Managing Data in an RDB Store

The RDB provides APIs for inserting, deleting, updating, and querying data in the local RDB store.

- **Inserting data**
  
  The RDB provides APIs for inserting data through a **ValuesBucket** in a data table. If the data is inserted, the row ID of the data inserted will be returned; otherwise, **-1** will be returned.
  
  **Table 2** APIs for inserting data
  
  | Class| API| Description|
  | -------- | -------- | -------- |
  | RdbStore | insert(name:&nbsp;string,&nbsp;values:&nbsp;ValuesBucket,&nbsp;callback:&nbsp;AsyncCallback&lt;number&gt;):void | Inserts a row of data into a table. This method uses a callback to return the result.<br>-&nbsp;**name**: name of the target table.<br>-&nbsp;**values**: data to be inserted into the table.<br>-&nbsp;**callback**: callback invoked to return the result. If the operation is successful, the row ID will be returned. Otherwise, **-1** will be returned.|
  | RdbStore | insert(name:&nbsp;string,&nbsp;values:&nbsp;ValuesBucket):&nbsp;Promise&lt;number&gt; | Inserts a row of data into a table. This method uses a promise to return the result.<br>-&nbsp;**name**: name of the target table.<br>-&nbsp;**values**: data to be inserted into the table.|
  
- **Updating data**
  
  Call the **update()** method to pass new data and specify the update conditions by using **RdbPredicates**. If the data is updated, the number of rows of the updated data will be returned; otherwise, **0** will be returned.
  
  **Table 3** APIs for updating data
  
  | Class| API| Description|
  | -------- | -------- | -------- |
  | RdbStore | update(values:&nbsp;ValuesBucket,&nbsp;rdbPredicates:&nbsp;RdbPredicates,&nbsp;callback:&nbsp;AsyncCallback&lt;number&gt;):void | Updates data in the RDB store based on the specified **RdbPredicates** object. This method uses a callback to return the result.<br>-&nbsp;**values**: data to update, which is stored in a **ValuesBucket**.<br>-&nbsp;**rdbPredicates**: conditions for updating data.<br>-&nbsp;**callback**: callback invoked to return the number of rows updated.|
  | RdbStore | update(values:&nbsp;ValuesBucket,&nbsp;rdbPredicates:&nbsp;RdbPredicates):&nbsp;Promise\<number> | Updates data in the RDB store based on the specified **RdbPredicates** object. This method uses a promise to return the result.<br>-&nbsp;**values**: data to update, which is stored in a **ValuesBucket**.<br>-&nbsp;**rdbPredicates**: conditions for updating data.|
  
- **Deleting data**
  
  Call the **delete()** method to delete data meeting the conditions specified by **RdbPredicates**. If the data is deleted, the number of rows of the deleted data will be returned; otherwise, **0** will be returned.
  
  **Table 4** APIs for deleting data
  
  | Class| API| Description|
  | -------- | -------- | -------- |
  | RdbStore | delete(rdbPredicates:&nbsp;RdbPredicates,&nbsp;callback:&nbsp;AsyncCallback&lt;number&gt;):void | Deletes data from the RDB store based on the specified **RdbPredicates** object. This method uses a callback to return the result.<br>-&nbsp;**rdbPredicates**: conditions for deleting data.<br>-&nbsp;**callback**: callback invoked to return the number of rows deleted.|
  | RdbStore | delete(rdbPredicates:&nbsp;RdbPredicates):&nbsp;Promise | Deletes data from the RDB store based on the specified **RdbPredicates** object. This method uses a promise to return the result.<br>-&nbsp;**rdbPredicates**: conditions for deleting data.|
  
- **Querying data**

  You can query data in an RDB store in either of the following ways:

  - Call the **query()** method to query data based on the predicates, without passing any SQL statement.
  - Run the native SQL statement.

  **Table 5** APIs for querying data

  | Class| API| Description|
  | -------- | -------- | -------- |
  | RdbStore | query(rdbPredicates:&nbsp;RdbPredicates,&nbsp;columns:&nbsp;Array,&nbsp;callback:&nbsp;AsyncCallback&lt;ResultSet&gt;):&nbsp;void | Queries data in the RDB store based on the specified **RdbPredicates** object. This method uses a callback to return the result.<br>-&nbsp;**rdbPredicates**: conditions for querying data.<br>-&nbsp;**columns**: columns to query. If this parameter is not specified, the query applies to all columns.<br>-&nbsp;**callback**: callback invoked to return the result. If the operation is successful, a **ResultSet** object will be returned.|
  | RdbStore | query(rdbPredicates:&nbsp;RdbPredicates,&nbsp;columns:&nbsp;Array):&nbsp;Promise&lt;ResultSet&gt; | Queries data in the RDB store based on the specified **RdbPredicates** object. This method uses a promise to return the result.<br>-&nbsp;**rdbPredicates**: conditions for querying data.<br>-&nbsp;**columns**: columns to query. If this parameter is not specified, the query applies to all columns.|
  | RdbStore | querySql(sql:&nbsp;string,&nbsp;bindArgs:&nbsp;Array&lt;ValueType&gt;,&nbsp;callback:&nbsp;AsyncCallback&lt;ResultSet&gt;):void | Queries data in the RDB store using the specified SQL statement. This method uses a callback to return the result.<br>-&nbsp;**sql**: SQL statement.<br>-&nbsp;**bindArgs**: arguments in the SQL statement.<br>-&nbsp;**callback**: callback invoked to return the result. If the operation is successful, a **ResultSet** object will be returned.|
  | RdbStore | querySql(sql:&nbsp;string,&nbsp;bindArgs?:&nbsp;Array&lt;ValueType&gt;):Promise&lt;ResultSet&gt; | Queries data in the RDB store using the specified SQL statement. This method uses a promise to return the result.<br>-&nbsp;**sql**: SQL statement.<br>-&nbsp;**bindArgs**: arguments in the SQL statement.|

### Using Predicates

The RDB provides **RdbPredicates** for you to set database operation conditions.

**Table 6** APIs for using RDB store predicates

| Class| API| Description|
| -------- | -------- | -------- |
| RdbPredicates |inDevices(devices: Array\<string>): RdbPredicates | Specifies remote devices on the network with RDB stores to be synchronized.<br>-&nbsp;**devices**: IDs of the remote devices on the network.<br>-&nbsp;**RdbPredicates**: returns a **RdbPredicates** object that matches the specified field.|
| RdbPredicates |inAllDevices(): RdbPredicates | Connects to all remote devices on the network with RDB stores to be synchronized.<br>-&nbsp;**RdbPredicates**: returns a **RdbPredicates** object that matches the specified field.|
| RdbPredicates | equalTo(field:&nbsp;string,&nbsp;value:&nbsp;ValueType):&nbsp;RdbPredicates | Sets the **RdbPredicates** to match the field with data type **ValueType** and value equal to the specified value.<br>-&nbsp;**field**: column name in the database table.<br>-&nbsp;**value**: value specified.<br>-&nbsp;**RdbPredicates**: returns a **RdbPredicates** object that matches the specified field.|
| RdbPredicates | notEqualTo(field:&nbsp;string,&nbsp;value:&nbsp;ValueType):&nbsp;RdbPredicates | Sets the **RdbPredicates** to match the field with data type **ValueType** and value not equal to the specified value.<br>-&nbsp;**field**: column name in the database table.<br>-&nbsp;**value**: value specified.<br>-&nbsp;**RdbPredicates**: returns a **RdbPredicates** object that matches the specified field.|
| RdbPredicates | beginWrap():&nbsp;RdbPredicates | Adds a left parenthesis to the **RdbPredicates**.<br>-&nbsp;**RdbPredicates**: returns a **RdbPredicates** with a left parenthesis.|
| RdbPredicates | endWrap():&nbsp;RdbPredicates | Adds a right parenthesis to the **RdbPredicates**.<br>-&nbsp;**RdbPredicates**: returns a **RdbPredicates** with a right parenthesis.|
| RdbPredicates | or():&nbsp;RdbPredicates | Adds the OR condition to the **RdbPredicates**.<br>-&nbsp;**RdbPredicates**: returns a **RdbPredicates** with the OR condition.|
| RdbPredicates | and():&nbsp;RdbPredicates | Adds the AND condition to the **RdbPredicates**.<br>-&nbsp;**RdbPredicates**: returns a **RdbPredicates** with the AND condition.|
| RdbPredicates | contains(field:&nbsp;string,&nbsp;value:&nbsp;string):&nbsp;RdbPredicats | Sets the **RdbPredicates** to match a string containing the specified value.<br>-&nbsp;**field**: column name in the database table.<br>-&nbsp;**value**: value specified.<br>-&nbsp;**RdbPredicates**: returns a **RdbPredicates** object that matches the specified string.|
| RdbPredicates | beginsWith(field:&nbsp;string,&nbsp;value:&nbsp;string):&nbsp;RdbPredicates | Sets the **RdbPredicates** to match a string that starts with the specified value.<br>-&nbsp;**field**: column name in the database table.<br>-&nbsp;**value**: value specified.<br>-&nbsp;**RdbPredicates**: returns a **RdbPredicates** object that matches the specified field.|
| RdbPredicates | endsWith(field:&nbsp;string,&nbsp;value:&nbsp;string):&nbsp;RdbPredicates | Sets the **RdbPredicates** to match a string that ends with the specified value.<br>-&nbsp;**field**: column name in the database table.<br>-&nbsp;**value**: value specified.<br>-&nbsp;**RdbPredicates**: returns a **RdbPredicates** object that matches the specified field.|
| RdbPredicates | isNull(field:&nbsp;string):&nbsp;RdbPredicates | Sets the **RdbPredicates** to match the field whose value is null.<br>-&nbsp;**field**: column name in the database table.<br>-&nbsp;**RdbPredicates**: returns a **RdbPredicates** object that matches the specified field.|
| RdbPredicates | isNotNull(field:&nbsp;string):&nbsp;RdbPredicates | Sets the **RdbPredicates** to match the field whose value is not null.<br>-&nbsp;**field**: column name in the database table.<br>-&nbsp;**RdbPredicates**: returns a **RdbPredicates** object that matches the specified field.|
| RdbPredicates | like(field:&nbsp;string,&nbsp;value:&nbsp;string):&nbsp;RdbPredicates | Sets the **RdbPredicates** to match a string that is similar to the specified value.<br>-&nbsp;**field**: column name in the database table.<br>-&nbsp;**value**: value specified.<br>-&nbsp;**RdbPredicates**: returns a **RdbPredicates** object that matches the specified field.|
| RdbPredicates | glob(field:&nbsp;string,&nbsp;value:&nbsp;string):&nbsp;RdbPredicates | Sets the **RdbPredicates** to match the specified string.<br>-&nbsp;**field**: column name in the database table.<br>-&nbsp;**value**: value specified.<br>-&nbsp;**RdbPredicates**: returns a **RdbPredicates** object that matches the specified field.|
| RdbPredicates | between(field:&nbsp;string,&nbsp;low:&nbsp;ValueType,&nbsp;high:&nbsp;ValueType):&nbsp;RdbPredicates | Sets the **RdbPredicates** to match the field with data type **ValueType** and value within the specified range.<br>-&nbsp;**field**: column name in the database table.<br>-&nbsp;**low**: minimum value that matches the **RdbPredicates**.<br>-&nbsp;**high**: maximum value that matches the **RdbPredicates**.<br>-&nbsp;**RdbPredicates**: returns a **RdbPredicates** object that matches the specified field.|
| RdbPredicates | notBetween(field:&nbsp;string,&nbsp;low:&nbsp;ValueType,&nbsp;high:&nbsp;ValueType):&nbsp;RdbPredicates | Sets the **RdbPredicates** to match the field with data type **ValueType** and value out of the specified range.<br>-&nbsp;**field**: column name in the database table.<br>-&nbsp;**low**: minimum value that matches the **RdbPredicates**.<br>-&nbsp;**high**: maximum value that matches the **RdbPredicates**.<br>-&nbsp;**RdbPredicates**: returns a **RdbPredicates** object that matches the specified field.|
| RdbPredicates | greaterThan(field:&nbsp;string,&nbsp;value:&nbsp;ValueType):&nbsp;RdbPredicatesgr | Sets the **RdbPredicates** to match the field with data type **ValueType** and value greater than the specified value.<br>-&nbsp;**field**: column name in the database table.<br>-&nbsp;**value**: value specified.<br>-&nbsp;**RdbPredicates**: returns a **RdbPredicates** object that matches the specified field.|
| RdbPredicates | lessThan(field:&nbsp;string,&nbsp;value:&nbsp;ValueType):&nbsp;RdbPredicates | Sets the **RdbPredicates** to match the field with data type **ValueType** and value less than the specified value.<br>-&nbsp;**field**: column name in the database table.<br>-&nbsp;**value**: value specified.<br>-&nbsp;**RdbPredicates**: returns a **RdbPredicates** object that matches the specified field.|
| RdbPredicates | greaterThanOrEqualTo(field:&nbsp;string,&nbsp;value:&nbsp;ValueType):&nbsp;RdbPredicates | Sets the **RdbPredicates** to match the field with data type **ValueType** and value greater than or equal to the specified value.<br>-&nbsp;**field**: column name in the database table.<br>-&nbsp;**value**: value specified.<br>-&nbsp;**RdbPredicates**: returns a **RdbPredicates** object that matches the specified field.|
| RdbPredicates | lessThanOrEqualTo(field:&nbsp;string,&nbsp;value:&nbsp;ValueType):&nbsp;RdbPredicates | Sets the **RdbPredicates** to match the field with data type **ValueType** and value less than or equal to the specified value.<br>-&nbsp;**field**: column name in the database table.<br>-&nbsp;**value**: value specified.<br>-&nbsp;**RdbPredicates**: returns a **RdbPredicates** object that matches the specified field.|
| RdbPredicates | orderByAsc(field:&nbsp;string):&nbsp;RdbPredicates | Sets the **RdbPredicates** to match the column with values sorted in ascending order.<br>-&nbsp;**field**: column name in the database table.<br>-&nbsp;**RdbPredicates**: returns a **RdbPredicates** object that matches the specified field.|
| RdbPredicates | orderByDesc(field:&nbsp;string):&nbsp;RdbPredicates | Sets the **RdbPredicates** to match the column with values sorted in descending order.<br>-&nbsp;**field**: column name in the database table.<br>-&nbsp;**RdbPredicates**: returns a **RdbPredicates** object that matches the specified field.|
| RdbPredicates | distinct():&nbsp;RdbPredicates | Sets the **RdbPredicates** to filter out duplicate records.<br>-&nbsp;**RdbPredicates**: returns a **RdbPredicates** object that can filter out duplicate records.|
| RdbPredicates | limitAs(value:&nbsp;number):&nbsp;RdbPredicates | Sets the **RdbPredicates** to specify the maximum number of records.<br>-&nbsp;**value**: maximum number of records.<br>-&nbsp;**RdbPredicates**: returns a **RdbPredicates** object that can be used to set the maximum number of records.|
| RdbPredicates | offsetAs(rowOffset:&nbsp;number):&nbsp;RdbPredicates | Sets the **RdbPredicates** to specify the start position of the returned result.<br>-&nbsp;**rowOffset**: start position of the returned result. The value is a positive integer.<br>-&nbsp;**RdbPredicates**: returns a **RdbPredicates** object that specifies the start position of the returned result.|
| RdbPredicates | groupBy(fields:&nbsp;Array&lt;string&gt;):&nbsp;RdbPredicates | Sets the **RdbPredicates** to group rows that have the same value into summary rows.<br>-&nbsp;**fields**: names of the columns grouped for querying data.<br>-&nbsp;**RdbPredicates**: returns a **RdbPredicates** object that groups rows with the same value.|
| RdbPredicates | indexedBy(indexName:&nbsp;string):&nbsp;RdbPredicates | Sets the **RdbPredicates** to specify the index column.<br>-&nbsp;**indexName**: name of the index column.<br>-&nbsp;**RdbPredicates**: returns a **RdbPredicates** object that specifies the index column.|
| RdbPredicates | in(field:&nbsp;string,&nbsp;value:&nbsp;Array&lt;ValueType&gt;):&nbsp;RdbPredicates | Sets the **RdbPredicates** to match the field with data type **Array&#60;ValueType&#62;** and value within the specified range.<br>-&nbsp;**field**: column name in the database table.<br>-&nbsp;**value**: array of **ValueType** to match.<br>-&nbsp;**RdbPredicates**: returns a **RdbPredicates** object that matches the specified field.|
| RdbPredicates | notIn(field:&nbsp;string,&nbsp;value:&nbsp;Array&lt;ValueType&gt;):&nbsp;RdbPredicates | Sets the **RdbPredicates** to match the field with data type **Array&#60;ValueType&#62;** and value out of the specified range.<br>-&nbsp;**field**: column name in the database table.<br>-&nbsp;**value**: array of **ValueType** to match.<br>-&nbsp;**RdbPredicates**: returns a **RdbPredicates** object that matches the specified field.|

### Using the Result Set

A result set can be regarded as a row of data in the queried results. It allows you to traverse and access the data you have queried. The following table describes the external APIs of **ResultSet**.

> **NOTICE**<br>
> After a result set is used, you must call the **close()** method to close it explicitly.

**Table 7** APIs for using the result set

| Class| API| Description|
| -------- | -------- | -------- |
| ResultSet | goTo(offset:number):&nbsp;boolean | Moves the result set forwards or backwards by the specified offset relative to its current position.|
| ResultSet | goToRow(position:&nbsp;number):&nbsp;boolean | Moves the result set to the specified row.|
| ResultSet | goToNextRow():&nbsp;boolean | Moves the result set to the next row.|
| ResultSet | goToPreviousRow():&nbsp;boolean | Moves the result set to the previous row.|
| ResultSet | getColumnIndex(columnName:&nbsp;string):&nbsp;number | Obtains the column index based on the specified column name.|
| ResultSet | getColumnName(columnIndex:&nbsp;number):&nbsp;string | Obtains the column name based on the specified column index.|
| ResultSet | goToFirstRow():&nbsp;boolean | Checks whether the result set is located in the first row.|
| ResultSet | goToLastRow():&nbsp;boolean | Checks whether the result set is located in the last row.|
| ResultSet | getString(columnIndex:&nbsp;number):&nbsp;string | Obtains the value in the specified column of the current row, in a string.|
| ResultSet | getBlob(columnIndex:&nbsp;number):&nbsp;Uint8Array | Obtains the values in the specified column of the current row, in a byte array.|
| ResultSet | getDouble(columnIndex:&nbsp;number):&nbsp;number | Obtains the values in the specified column of the current row, in double.|
| ResultSet | isColumnNull(columnIndex:&nbsp;number):&nbsp;boolean | Checks whether the value in the specified column of the current row is null.|
| ResultSet | close():&nbsp;void | Closes the result set.|



### Setting Distributed Tables

**Setting Distributed Tables**

**Table 8** APIs for setting distributed tables

| Class| API| Description|
| -------- | -------- | -------- |
| RdbStore | setDistributedTables(tables: Array\<string>, callback: AsyncCallback\<void>): void | Sets a list of distributed tables. This method uses a callback to return the result.<br>- &nbsp;**tables**: names of the distributed tables to set.<br>-&nbsp;**callback**: callback invoked to return the result.|
| RdbStore | setDistributedTables(tables: Array\<string>): Promise\<void> | Sets a list of distributed tables. This method uses a promise to return the result.<br>- &nbsp;**tables**: names of the distributed tables to set.|

**Obtaining the Distributed Table Name for a Remote Device**

You can obtain the distributed table name for a remote device based on the local table name. The distributed table name can be used to query the RDB store of the remote device.

**Table 9** APIs for obtaining the distributed table name of a remote device

| Class| API| Description|
| -------- | -------- | -------- |
| RdbStore | obtainDistributedTableName(device: string, table: string, callback: AsyncCallback\<string>): void | Obtains the distributed table name for a remote device based on the local table name. The distributed table name is used to query the RDB store of the remote device. This method uses a callback to return the result.<br>-&nbsp;**device**: remote device.<br>- &nbsp;**table**: local table name.<br>- &nbsp;**callback**: callback used to return the result. If the operation is successful, the distributed table name of the remote device will be returned. |
| RdbStore | obtainDistributedTableName(device: string, table: string): Promise\<string> | Obtains the distributed table name for a remote device based on the local table name. The distributed table name is used to query the RDB store of the remote device. This method uses a promise to return the result.<br>-&nbsp;**device**: remote device.<br>- &nbsp;**table**: local table name.|

**Synchronizing Data Between Devices**

**Table 10** APIs for synchronizing data between devices

| Class| API| Description|
| -------- | -------- | -------- |
| RdbStore | sync(mode: SyncMode, predicates: RdbPredicates, callback: AsyncCallback<Array<[string, number]>>): void | Synchronizes data between devices. This method uses a callback to return the result.<br>-&nbsp;**mode**: data synchronization mode.  **SYNC\_MODE\_PUSH** means to push data from the local device to a remote device. **SYNC\_MODE\_PULL** means to pull data from a remote device to the local device.<br>-&nbsp;**predicates**: data and devices to be synchronized.<br>-&nbsp;**callback**: callback invoked to return the result. In the result, **string** indicates the device ID, and **number** indicates the synchronization status of each device. The value **0** indicates a success, and other values indicate a failure.|
| RdbStore | sync(mode: SyncMode, predicates: RdbPredicates): Promise<Array<[string, number]>> | Synchronizes data between devices. This method uses a promise to return the result.<br>-&nbsp;**mode**: data synchronization mode.  **SYNC\_MODE\_PUSH** means to push data from the local device to a remote device. **SYNC\_MODE\_PULL** means to pull data from a remote device to the local device.<br>-&nbsp;**predicates**: data and devices to be synchronized. |

**Registering an RDB Store Observer**

**Table 11** API for registering an observer

| Class| API| Description|
| -------- | -------- | -------- |
| RdbStore |on(event: 'dataChange', type: SubscribeType, observer: Callback<Array\<string>>): void| Registers an observer for this RDB store to subscribe to distributed data changes. When data in the RDB store changes, a callback will be invoked to return the data changes.<br>-&nbsp;**type**: subscription type. **SUBSCRIBE\_TYPE\_REMOTE** means to subscribe to remote data changes.<br>-&nbsp;**observer**: observer that listens for data changes in the RDB store.|

**Unregistering an RDB Store Observer**

**Table 12** API for unregistering an observer

| Class| API| Description|
| -------- | -------- | -------- |
| RdbStore |off(event:'dataChange', type: SubscribeType, observer: Callback<Array\<string>>): void| Unregisters the observer of the specified type for the RDB store. This method uses a callback to return the result.<br>- &nbsp;**type**: subscription type. **SUBSCRIBE\_TYPE\_REMOTE** means to subscribe to remote data changes.<br>- &nbsp;**observer**: observer to unregister.|


## How to Develop

1. Create an RDB store.
   1. Configure the RDB store attributes, including the RDB store name, storage mode, and whether read-only mode is used.
   2. Initialize the table structure and related data in the RDB store.
   3. Create the RDB store.

   The sample code is as follows:

   ```js
   import data_rdb from '@ohos.data.rdb'
   
   const CREATE_TABLE_TEST = "CREATE TABLE IF NOT EXISTS test (" + "id INTEGER PRIMARY KEY AUTOINCREMENT, " + "name TEXT NOT NULL, " + "age INTEGER, " + "salary REAL, " + "blobType BLOB)";
   const STORE_CONFIG = {name: "rdbstore.db",}
   data_rdb.getRdbStore(STORE_CONFIG, 1, function (err, rdbStore) {
       rdbStore.executeSql(SQL_CREATE_TABLE)
       console.info('create table done.')
   })
   ```

2. Insert data.
   1. Create a **ValuesBucket** to store the data you need to insert.
   2. Call the **insert()** method to insert data into the RDB store.

   The sample code is as follows:

   ```js
   var u8 = new Uint8Array([1, 2, 3])
   const valueBucket = {"name": "Tom", "age": 18, "salary": 100.5, "blobType": u8,}
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
       console.info("setDistributedTables failed.")
   })
   ```

 5. Synchronize data across devices.
    1. Constructs an **RdbPredicates** object to specify remote devices within the network to be synchronized.
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
            console.log('device=' + device[i] + ' data changed')
        }
    }
    try {
        rdbStore.on('dataChange', rdb.SubscribeType.SUBSCRIBE_TYPE_REMOTE, storeObserver)
    } catch (err) {
        console.log('register observer failed')
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
