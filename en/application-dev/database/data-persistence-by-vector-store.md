# Persisting Vector Store Data (ArkTS)


## When to Use

Vector stores are designed to store, manage, and retrieve vector data while also supporting relational data processing for scalar values. The data type **floatvector** is used to store data vectorization results, enabling rapid retrieval and similarity searches for such data.<br>
Since API version 18, data in vector stores can be persisted.

## Basic Concepts

- **ResultSet**: a set of query results, which allows access to the required data in flexible modes.
- **floatvector**: vector data, for example, **[1.0, 3.0, 2.4, 5.1, 6.2, 11.7]**.

## Constraints

- By default, the Write Ahead Log (WAL) and the **FULL** flushing mode are used.

- A vector store supports a maximum of four read connections and one write connection at a time by default. A thread can perform the read operation when acquiring an idle read connection. If there is no idle read connection, a new read connection will be created.

- To ensure data accuracy, the database supports only one write operation at a time. Concurrent write operations are performed in serial mode.

- Once an application is uninstalled, related database files and temporary files are automatically deleted from the device.

- ArkTS supports basic data types such as number, string, binary, and boolean, and the special data type ValueType.

- To ensure successful data access, limit the size of a data record to 2 MB. Data records larger than this may be inserted correctly but fail to read.

## Available APIs

The following lists only the APIs for persisting vector store data. For details about more APIs and their usage, see [RDB Store](../reference/apis-arkdata/js-apis-data-relationalStore.md).

| API| Description|
| -------- | -------- |
| getRdbStore(context: Context, config: StoreConfig): Promise&lt;RdbStore&gt; | Obtains an **RdbStore** instance for data operations.|
| execute(sql: string, txId: number, args?: Array&lt;ValueType&gt;): Promise&lt;ValueType&gt; | Executes SQL statements that contain specified parameters. The number of operators (such as =, >, and <) in the SQL statements cannot exceed 1000.|
| querySql(sql: string, bindArgs?: Array&lt;ValueType&gt;):Promise&lt;ResultSet&gt; | Queries data in the RDB store using the specified SQL statement. The number of operators (such as =, >, and <) in the SQL statements cannot exceed 1000.|
| beginTrans(): Promise&lt;number&gt; | Starts the transaction before executing the SQL statements.|
| commit(txId : number):Promise&lt;void&gt; | Commits the executed SQL statements. This API must be used together with **beginTrans**.|
| rollback(txId : number):Promise&lt;void&gt; | Rolls back the executed SQL statements. This API must be used together with **beginTrans**.|
| deleteRdbStore(context: Context, config: StoreConfig): Promise&lt;void&gt; | Deletes an RDB store.|
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
     securityLevel: relationalStore.SecurityLevel.S1 // Database security level.
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
   > Call **close()** to close the **ResultSet** that is no longer used in a timely manner so that the memory allocated can be released.

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

8. Configure the data aging policy, which allows the application data to be automatically deleted by time or space.
   
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

9. Delete the database.

   Call **deleteRdbStore()** to delete the vector store and related database files. The sample code is as follows:

   ```ts
   try {
     await relationalStore.deleteRdbStore(this.context, STORE_CONFIG);
   } catch (err) {
     console.error(`delete rdbStore failed, code is ${err.code},message is ${err.message}`);
   }
   ```

   
