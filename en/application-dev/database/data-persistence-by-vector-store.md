# Persisting Vector Store Data (ArkTS)


## When to Use

Vector stores are designed to store, manage, and retrieve vector data while also supporting relational data processing for scalar values. The data type **floatvector** is used to store data vectorization results, enabling rapid retrieval and similarity searches for such data.<br>
Since API version 18, data in vector stores can be persisted.

## Basic Concepts

- **ResultSet**: a set of query results, which allows access to the required data in flexible modes.
- **floatvector**: vector data, for example, **[1.0, 3.0, 2.4, 5.1, 6.2, 11.7]**.

## Constraints

- The default log mode is Write Ahead Log ([WAL](data-terminology.md#write-ahead-log-wal)), and the default flush mode is [FULL](data-terminology.md#full).

- A vector store supports a maximum of four read connections and one write connection at a time by default. A thread can perform the read operation when acquiring an idle read connection. If there is no idle read connection, a new read connection will be created.

- To ensure data accuracy, the database supports only one write operation at a time. Concurrent write operations are performed in serial mode.

- Once an application is uninstalled, related database files and temporary files are automatically deleted from the device.

- ArkTS supports basic data types such as number, string, binary, and boolean, and the special data type ValueType.

- To ensure successful data access, limit the size of a data record to 2 MB. If a single data record exceeds the size limit, the data record may fail to be read even if it is successfully inserted.

## Specifications

### Data Types

Types of database table fields are as follows.

| Type| Description| Supported|
| -------- | -------- | -------- |
| NULL | Null.| Yes|
| INTEGER | Integer.| Yes|
| DOUBLE | Floating point.| Yes|
| TEXT | String.| Yes|
| BLOB | Binary.| Yes|
| FLOATVECTOR | Vector data.| Yes|

### Field Constraints

Constraints on database table fields are as follows.

| Function| SQL Syntax| Supported|
| -------- | -------- | -------- |
| Not null| NOT NULL | Yes|
| Default value| DEFAULT  | Yes|
| Unique index| UNIQUE | Yes|
| Primary key index| PRIMARY KEY | Yes|
| Foreign key index| FOREIGN | No|
| CHECK constraint| CHECK | No|

### Clauses

Clauses in a query statement are as follows.

| Keyword| Description| Supported|
| -------- | -------- | -------- |
| WHERE | Obtains data from one or more tables.| Yes|
| LIMIT | Restricts the data to return. | Yes|
| ORDER BY | Sorts data based on one or more columns.| Yes|
| ORDER BY vector distance| **<->** indicates the Euclidean distance, and **<=>** indicates the cosine distance.| Yes|
| GROUP BY | Groups the same data.| Yes|
| HAVING | Filters the results of aggregate functions.| Yes|
| INDEXED BY | Uses a specific index during query.| Yes|
| DISTINCT | Eliminates duplicate records.| No|

### Sets

Set statements in a query statement are as follows.

| Keyword| Description| Supported|
| -------- | -------- | -------- |
| UNION | Merges the results of two or more query statements and deduplicates the results.| Yes|
| UNION ALL | Merges the results of two or more query statements.| Yes|

### Operators

The following lists the operators used to filter data based on a condition. Generally, they are used in query statements.  

| Type| Operator| Supported|
| -------- | -------- | -------- |
| Arithmetic operation| +, -, *, /, %| Yes|
| Comparison operation| ==, =, !=, >, >=, <, <=| Yes|
| Logical operation| AND, BETWEEN, EXISTS, IN, NOT IN, NOT, OR, IS NULL, IS, IS NOT, LIKE, GLOB| Yes|
| String concatenation operation| \|\| | Yes|
| Bitwise operation| &, \|, ~, <<, >>| Yes|
| Vector distance operation| <->, <=>| Yes (used in the aggregate functions **max** and **min**)|

### Time and Date

The following lists the functions used to return dates in different formats based on different time functions. Generally, these functions are used in query statements.  

| Keyword| Description| Supported|
| -------- | -------- | -------- |
| DATE | Returns a date in the format of YYYY-MM-DD.| Yes|
| TIME | Returns a time in the format of HH:MM:SS.| Yes|
| DATETIME | Returns date and time in the format of YYYY-MM-DD HH:MM:SS.| Yes|
| JULIANDAY | Returns the number of days since noon on November 24, 4714 BC in Greenwich Mean Time (GMT).| Yes|
| STRFTIME | Returns a formatted date based on the format string specified by the first parameter.| Yes|

### Functions

Functions in SQL statements are as follows.

| Keyword| Description| Supported|
| -------- | -------- | -------- |
| COUNT | Calculates the number of rows returned after a query.| Yes|
| MAX/MIN | Selects the maximum or minimum value in a column.| Yes|
| AVG | Calculates the average value of a column.| Yes|
| SUM | Calculates the sum of a column.| Yes|
| RANDOM | Returns a pseudo-random integer ranging from -9223372036854775808 to 9223372036854775807.| Yes|
| ABS | Calculates the absolute value.| Yes|
| UPPER/LOWER | Converts a string to uppercase or lowercase letters.| Yes|
| LENGTH | Returns the length of a string.| Yes|

## Available APIs

The following lists only the APIs for persisting vector store data. For details about more APIs and their usage, see [RDB Store](../reference/apis-arkdata/arkts-apis-data-relationalStore.md).

| API| Description|
| -------- | -------- |
| getRdbStore(context: Context, config: StoreConfig): Promise&lt;RdbStore&gt; | Obtains an **RdbStore** instance for data operations.|
| execute(sql: string, txId: number, args?: Array&lt;ValueType&gt;): Promise&lt;ValueType&gt; | Executes SQL statements that contain specified parameters. The number of operators (such as =, >, and <) in the SQL statements cannot exceed 1000.|
| querySql(sql: string, bindArgs?: Array&lt;ValueType&gt;):Promise&lt;ResultSet&gt; | Queries data in the RDB store using the specified SQL statement. The number of operators (such as =, >, and <) in the SQL statements cannot exceed 1000.|
| beginTrans(): Promise&lt;number&gt; | Starts the transaction before executing the SQL statements.|
| commit(txId : number):Promise&lt;void&gt; | Commits the executed SQL statements. This API must be used together with **beginTrans**.|
| rollback(txId : number):Promise&lt;void&gt; | Rolls back the executed SQL statements. This API must be used together with **beginTrans**.|
| deleteRdbStore(context: Context, config: StoreConfig): Promise&lt;void&gt; | Deletes a database.|
| isVectorSupported(): boolean | Checks whether the system supports vector stores.|

## How to Develop

1. Check whether the current system supports vector stores. The sample code is as follows:

   ```ts
   import { relationalStore } from '@kit.ArkData'; // Import the relationalStore module.
   import { UIAbility } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { window } from '@kit.ArkUI';     
   // In this example, Ability is used to obtain an RdbStore instance. You can use other implementations as required.
   class EntryAbility extends UIAbility {
     async onWindowStageCreate(windowStage: window.WindowStage) {
        // Check whether the current system supports vector stores.
       let ret = relationalStore.isVectorSupported();
       if (!ret) {
         console.error(`vectorDB is not supported .`);
         return;
       }
       // Open the database, and add, delete, and modify data.
     }
   }
   ```

2. If the system supports vector stores, obtain an **RdbStore** instance. Call **getRdbStore()** to create a database and create a table.

   > **NOTE**
   >
   > - The RDB store created by an application varies with the context. Multiple RDB stores are created for the same database name with different application contexts. For example, each UIAbility has its own context.
   > 
   > - When an application calls **getRdbStore()** to obtain an RDB store instance for the first time, the corresponding database file is generated in the application sandbox. When the RDB store is used, temporary files ended with **-wal** and **-shm** may be generated in the same directory as the database file. If you want to move the database files to other places, you must also move these temporary files. After the application is uninstalled, the database files and temporary files generated on the device are also removed.
   > 
   > - For details about the error codes, see [Universal Error Codes](../reference/errorcode-universal.md) and [RDB Store Error Codes](../reference/apis-arkdata/errorcode-data-rdb.md).

   The sample code is as follows:

   ```ts
   let store: relationalStore.RdbStore | undefined = undefined;
   const STORE_CONFIG :relationalStore.StoreConfig= {
     name: 'VectorTest.db', // Database file name.
     securityLevel: relationalStore.SecurityLevel.S1, // Database security level.
     vector: true // Optional. This parameter must be true for a vector store.
   };   
   
   relationalStore.getRdbStore(this.context, STORE_CONFIG).then(async (rdbStore: relationalStore.RdbStore) => {
     store = rdbStore;
     // Create a table. floatvector (2) indicates that repr is 2-dimensional.
     const SQL_CREATE_TABLE = 'CREATE TABLE IF NOT EXISTS test (id INTEGER PRIMARY KEY, repr floatvector(2));';
     // The second parameter indicates that transaction is not enabled. The third parameter undefined indicates that parameter binding is not used.
     await store!.execute(SQL_CREATE_TABLE, 0, undefined); 
   }).catch((err: BusinessError) => {
     console.error(`Get RdbStore failed, code is ${err.code}, message is ${err.message}`);
   });  
   ```

3. Call **execute()** to insert data to the vector store.

   > **NOTE**
   >
   > **RelationalStore** does not provide explicit flush operations for data persistence. The data inserted is persisted.
   
   The sample code is as follows:

   ```ts
   try {
     // Use parameter binding.
     const vectorValue: Float32Array = Float32Array.from([1.2, 2.3]);
     await store!.execute("insert into test VALUES(?, ?);", 0, [0, vectorValue]);
     // Do not use parameter binding.
     await store!.execute("insert into test VALUES(1, '[1.3, 2.4]');", 0, undefined);
   } catch (err) {
     console.error(`execute insert failed, code is ${err.code}, message is ${err.message}`);
   }
   ```

4. Call **execute()** to modify or delete data. The sample code is as follows:

   ```ts
   // Modify data.
   try {
     // Use parameter binding.
     const vectorValue1: Float32Array = Float32Array.from([2.1, 3.2]);
     await store!.execute("update test set repr = ? where id = ?", 0, [vectorValue1, 0]);
     // Do not use parameter binding.
     await store!.execute("update test set repr = '[5.1, 6.1]' where id = 0", 0, undefined);
   } catch (err) {
     console.error(`execute update failed, code is ${err.code}, message is ${err.message}`);
   }

   // Delete data.
   try {
     // Use parameter binding.
     await store!.execute("delete from test where id = ?", 0, [0]);
     // Do not use parameter binding.
     await store!.execute("delete from test where id = 0", 0, undefined);
   } catch (err) {
     console.error(`execute delete failed, code is ${err.code}, message is ${err.message}`);
   }
   ```

5. Call **querySql()** to query data. A **ResultSet** instance is returned.

   > **NOTE**
   >
   > Use **close()** to close the **ResultSet** that is no longer used in a timely manner so that the memory allocated can be released.

   The sample code is as follows:

   ```ts
   // Perform single-table queries.
   try {
     // Use parameter binding.
     const QUERY_SQL = "select id, repr <-> ? as distance from test where id > ? order by repr <-> ? limit 5;";
     const vectorValue2: Float32Array = Float32Array.from([6.2, 7.3]);
     let resultSet = await store!.querySql(QUERY_SQL, [vectorValue2, 0, vectorValue2]);
     while (resultSet!.goToNextRow()) {
        let id = resultSet.getValue(0);
        let dis = resultSet.getValue(1);
     }
     resultSet!.close();

     // Do not use parameter binding.
     const QUERY_SQL1 = "select id, repr <-> '[6.2, 7.3]' as distance from test where id > 0 order by repr <-> '[6.2, 7.3]' limit 5;";
     resultSet = await store!.querySql(QUERY_SQL1);
     resultSet!.close();
   } catch (err) {
     console.error(`query failed, code is ${err.code}, message is ${err.message}`);
   }

   // Perform subqueries.
   try {
     // Create the second table.
     let CREATE_SQL = "CREATE TABLE IF NOT EXISTS test1(id text PRIMARY KEY);";
     await store!.execute(CREATE_SQL);
     let resultSet = await store!.querySql("select * from test where id in (select id from test1);");
     resultSet!.close();
   } catch (err) {
     console.error(`query failed, code is ${err.code}, message is ${err.message}`);
   }

   // Perform aggregate queries.
   try {
     let resultSet = await store!.querySql("select * from test where repr <-> '[1.0, 1.0]' > 0 group by id having max(repr <=> '[1.0, 1.0]');");
     resultSet!.close();
   } catch (err) {
     console.error(`query failed, code is ${err.code}, message is ${err.message}`);
   }

   // Perform multi-table queries.
   try {
     // Different union all, union will delete duplicate data.
     let resultSet = await store!.querySql("select id, repr <-> '[1.5, 5.6]' as distance from test union select id, repr <-> '[1.5, 5.6]' as distance from test order by distance limit 5;");
     resultSet!.close();
   } catch (err) {
     console.error(`query failed, code is ${err.code}, message is ${err.message}`);
   }
   ```

6. Create a view and query data. The sample code is as follows:

   ```ts
   // Perform view queries.
   try {
     // Create a view.
     await store!.execute("CREATE VIEW v1 as select * from test where id > 0;");
     let resultSet = await store!.querySql("select * from v1;");
     resultSet!.close();
   } catch (err) {
     console.error(`query failed, code is ${err.code}, message is ${err.message}`);
   }
   ```
   
7. Query data using vector indexes.

   The vector store uses vectors as keys to provide efficient and fast search capabilities.
   
   It supports the basic syntax and extended syntax as follows:

   - Basic syntax:

     ```sql
     // index_name indicates the index name, index_type indicates the index type, and dist_function indicates the type of distance function for similarity measurement.
     CREATE INDEX [IF NOT EXISTS] index_name ON table_name USING index_type (column_name dist_function);

     DROP INDEX table_name.index_name;
     ```
   - Extended syntax:

     ```sql
     CREATE INDEX [Basic syntax] [WITH(parameter = value [, ...])];
     ```

   **Table 1** index_type

   | Type     | Description                                                    |
   | --------- | ------------------------------------------------------------ |
   | gsdiskann | Index for processing high-dimensional dense vector data, such as text embedding and image features.        |

   **Table 2** dist_function

   | Type  | Operator| Description  |
   | ------ | -------- | ---------- |
   | L2     | <->      | Euclidean distance.|
   | COSINE | <=>      | Cosine distance.|

   **Table 3** parameter (extended syntax parameters)

   | Parameter  | Value Range| Description  |
   | ------ | -------- | ---------- |
   | QUEUE_SIZE | Value range: [10, 1000]<br>Default value: **20**    | Size of the candidate queue when an index is created for nearest neighbor search. A larger value indicates a lower construction speed and a slightly higher recall rate.|
   | OUT_DEGREE | Value range: [1, 1200]<br>Default value: **60**     | Number of outgoing edges of a node in the graph. The value of **OUT_DEGREE** cannot exceed **pageSize**. Otherwise, the error GRD_INVALID_ARGS will be thrown.|

   > **NOTE**
   >
   > - When deleting an index, you need to specify the table name, that is, **Drop Index table.index_name**.
   > 
   > - The index created with a table cannot be deleted, for example, the primary key cannot be deleted.
   > 
   > - When querying data based on vector indexes, you must use **ORDER BY** and **LIMIT**. **ORDER BY** has only one sorting condition, that is, the vector distance condition. If **ORDER BY** is used with **DESC**, vector indexes will not be used. The distance metric used for querying must match the metric used when the index is created. For example, if the vector index is created using **L2**, <-> must be used for the query. Otherwise, the index cannot be hit.

   The sample code is as follows:

   ```ts
   // Basic syntax
   try {
     // Create an index using the basic syntax. The index name is diskann_l2_idx, index column is repr, type is gsdiskann, and the distance metric is L2.
     await store!.execute("CREATE INDEX diskann_l2_idx ON test USING GSDISKANN(repr L2);");
     // Delete the diskann_l2_idx index from the test table.
     await store!.execute("DROP INDEX test.diskann_l2_idx;");
   } catch (err) {
     console.error(`create index failed, code is ${err.code}, message is ${err.message}`);
   }

   // Extended syntax
   try {
     // Set QUEUE_SIZE to 20 and OUT_DEGREE to 50.
     await store!.execute("CREATE INDEX diskann_l2_idx ON test USING GSDISKANN(repr L2) WITH (queue_size=20, out_degree=50);");
   } catch (err) {
     console.error(`create ext index failed, code is ${err.code}, message is ${err.message}`);
   }
   ```

8. Manually reclaim disk fragmentation generated during index deletion. This function is supported since API version 20.

    After the vector store deletes vectors on the table where the GSDiskANN index has been created, disk defragmentation is automatically performed. However, automatic disk defragmentation may not be triggered in the following scenarios:
    - After vectors are deleted from the GSDiskANN index, the vector store is closed immediately.
    - After vectors are deleted in batches from the GSDiskANN index, no operation is performed on the table.

   Therefore, the following statement is provided for you to trigger the disk defragmentation from the GSDiskANN index:
   ```sql
   PRAGMA DISKANN_ASYNC_COLLECTING;
   ```
  
   > **NOTE**
   >
   > - This statement is triggered to reclaim disk fragmentation from GSDiskANN indexes in all tables of the vector store at a time.
   > 
   > - The disk defragmentation task is a background task and does not block the execution of subsequent statements.
   > 
   > - The disk defragmentation task is automatically scheduled by the background based on the load. Generally, the task is executed only in low-load scenarios. The time required for successful execution depends on the load.

    The sample code is as follows:

   ```ts
   try {
     // Manually trigger asynchronous deletion and sorting to execute disk defragmentation for all GSDiskANN indexes in the vector store.
     await store!.execute("PRAGMA DISKANN_ASYNC_COLLECTING;");
   } catch (err) {
     console.error(`diskann async collecting failed, code is ${err.code}, message is ${err.message}`);
   }
   ```

9. Configure the data aging policy, which allows the application data to be automatically deleted by time or space.
   
   The syntax is as follows:

   ```sql
   CREATE TABLE table_name(column_name type [, ...]) [WITH(parameter = value [, ...])];
   ```

   **parameter** specifies the parameter to set, and **value** specifies the value of the parameter. The following table describes the fields contained in **parameter**.

   **Table 4** parameter (data aging policy parameters)

   | Parameter| Mandatory| Value Range|
   | ------ | -------- | ---------- |
   | time_col | Yes| Column name. The value must be an integer and cannot be empty.|
   | interval | No| Interval for executing the aging task thread. If a write operation is performed after the interval, an aging task will be triggered to delete the data that meets the aging conditions. If the write operation is performed within the interval, no aging task will be triggered. <br>Value range: [5 second, 1 year]<br>Default value: **1 day**<br>Time units supported include **second**, **minute**, **hour**, **day**, **month** and **year**. The value is case-insensitive and supports both singular and plural forms (for example, **2 hour** and **2 hours** are acceptable).|
   | ttl | No| Data retention period. <br>Value range: [1 hour, 1 year]<br>Default value: **3 month**<br>Time units supported include **second**, **minute**, **hour**, **day**, **month** and **year**. The value is case-insensitive and supports both singular and plural forms (for example, **2 hour** and **2 hours** are acceptable).|
   | max_num | No| Maximum data volume allowed. <br>Value range: [100, 1024]<br>Default value: **1024**<br> After the aging task deletes expired data, if the remaining data in the table exceeds the value of **max_num**, data tied to the nearest expiration-adjacent time point will be deleted until the total row count falls below **max_num**.|

   Time-related parameters are converted into seconds as follows.

   | Unit| Value in Seconds|
   | ------ | -------- |
   | year | 365 * 24 * 60 * 60 |
   | month | 30 * 24 * 60 * 60 |
   | day | 24 * 60 * 60 |
   | hour | 60 * 60 |
   | minute | 60 |

   For example, if **ttl** is set to **3 months**, the value will be converted into 7,776,000 seconds (3 x (30 * 24 * 60 * 60)).

   The sample code is as follows:

   ```ts
   try {
     // The write operation performed every 5 minutes will trigger a data aging task.
     await store!.execute("CREATE TABLE test2(rec_time integer not null) WITH (time_col = 'rec_time', interval = '5 minute');");
   } catch (err) {
     console.error(`configure data aging failed, code is ${err.code}, message is ${err.message}`);
   }
   ```

10. Configure data compression. This feature is configured when a table is created to compress column data of the text type.

    Data compression is supported since API version 20.

    The syntax is as follows:

    ```sql
    CREATE TABLE table_name(content text [, ...]) [WITH(compress_col = 'content')];
    ```

    In this syntax, **compress_col** is mandatory, and value is the name of the data column of the text type. This parameter can be configured together with the data aging policy.

    The sample code is as follows:

    ```ts
    try {
      // Data compression and data aging are configured for the content column.
      await store!.execute("CREATE TABLE IF NOT EXISTS test3 (time integer not null, content text) with (time_col = 'time', interval = '5 minute', compress_col = 'content');");
    } catch (err) {
       console.error(`configure data compress failed, code is ${err.code}, message is ${err.message}`);
    }
    ```

11. Delete the database.

    Call **deleteRdbStore()** to delete the vector store and related database files. The sample code is as follows:

    ```ts
    try {
      await relationalStore.deleteRdbStore(this.context, STORE_CONFIG);
    } catch (err) {
      console.error(`delete rdbStore failed, code is ${err.code},message is ${err.message}`);
    }
    ```

   
