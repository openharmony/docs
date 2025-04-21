# Persisting Vector Store Data (C/C++)


## When to Use

Vector stores are designed to store, manage, and retrieve vector data while also supporting relational data processing for scalar values. The data type **floatvector** is used to store data vectorization results, enabling rapid retrieval and similarity searches for such data.

## Basic Concepts

- **ResultSet**: a set of query results, which allows access to the required data in flexible modes.
- **floatvector**: vector data, for example, **[1.0, 3.0, 2.4, 5.1, 6.2, 11.7]**.

## Constraints

- By default, the Write Ahead Log (WAL) and the **FULL** flushing mode are used.

- A vector store supports a maximum of four read connections and one write connection at a time by default. A thread can perform the read operation when acquiring an idle read connection. If there is no idle read connection, a new read connection will be created.

- To ensure data accuracy, the database supports only one write operation at a time. Concurrent write operations are performed in serial mode.

- Once an application is uninstalled, related database files and temporary files are automatically deleted from the device.

- To ensure successful data access, limit the size of a data record to 2 MB. Data records larger than this may be inserted correctly but fail to read.

## Available APIs

For details about the APIs, see [RDB](../reference/apis-arkdata/_r_d_b.md).

| API| Description|
| -------- | -------- |
| int OH_Rdb_SetDbType(OH_Rdb_ConfigV2 *config, int dbType) | Sets the database type.|
| OH_Rdb_Store *OH_Rdb_CreateOrOpen(const OH_Rdb_ConfigV2 *config, int *errCode) | Obtains an **OH_Rdb_Store** instance (**dbType** is set to **RDB_CAYLEY** by using **OH_Rdb_SetDbType**) for vector operations.|
| int OH_Rdb_ExecuteV2(OH_Rdb_Store *store, const char *sql, const OH_Data_Values *args, OH_Data_Value **result) | Executes SQL statements with a return value to perform write operations. Parameter binding is supported. The number of operators (such as =, >, and <) in the SQL statements cannot exceed 1000.|
| int OH_Rdb_ExecuteByTrxId(OH_Rdb_Store *store, int64_t trxId, const char *sql) | Executes the SQL statement that does not return a value with the specified transaction ID. If the transaction ID is **0**, no transaction is used.|
| OH_Cursor *OH_Rdb_ExecuteQuery(OH_Rdb_Store *store, const char *sql) | Queries data in a store using the specified SQL statements.|
| OH_Cursor *OH_Rdb_ExecuteQueryV2(OH_Rdb_Store *store, const char *sql, const OH_Data_Values *args) | Queries data in a store using the specified SQL statements. Parameter binding is supported. The number of operators (such as =, >, and <) in the SQL statements cannot exceed 1000.|
| int OH_Rdb_DeleteStoreV2(const OH_Rdb_ConfigV2 *config) | Deletes a vector store.|
| int OH_Cursor_GetFloatVectorCount(OH_Cursor *cursor, int32_t columnIndex, size_t *length) | Obtains the length of the floating-point array in the specified column of the current row.|
| int OH_Cursor_GetFloatVector(OH_Cursor *cursor, int32_t columnIndex, float *val, size_t inLen, size_t *outLen) | Obtains the value in the specified column of the current row as a floating-point array. The value of **inLen** cannot be less than the actual array size.|

## How to Develop

**Adding Dynamic Link Libraries**

Add the following libraries to **CMakeLists.txt**.

```txt
libnative_rdb_ndk.z.so
```

**Including Header Files**

```c++
#include <database/data/oh_data_values.h>
#include <database/rdb/oh_cursor.h>
#include <database/rdb/relational_store.h>
```

1. Check whether the system supports vector stores. The sample code is as follows:

   ```c
   int numType = 0;
   // If numType is 2, the system supports vector stores. If numType 1, the system does not support vector stores.
   OH_Rdb_GetSupportedDbType(&numType);
   ```

2. If the system supports vector stores, obtain an **OH_Rdb_Store** instance. The sample code is as follows:

   ```c
   // Create an OH_Rdb_Config instance.
   OH_Rdb_ConfigV2 *config = OH_Rdb_CreateConfig();
   // The path must be an application sandbox path.
   OH_Rdb_SetDatabaseDir(config, "xxx");
   // Set the store name, which is the database file name.
   OH_Rdb_SetStoreName(config, "rdb_vector_test.db");
   // Set the application bundle name.
   OH_Rdb_SetBundleName(config, "xxx");
   // Specify whether the database is encrypted.
   OH_Rdb_SetEncrypted(config, false);
   // Set the security level of the database files.
   OH_Rdb_SetSecurityLevel(config,   OH_Rdb_SecurityLevel::S1);
   // Set the encryption level for the directory holding the database files.
   OH_Rdb_SetArea(config, RDB_SECURITY_AREA_EL1);
   // Set the storage type.
   OH_Rdb_SetDbType(config, RDB_CAYLEY);
   
   // Create an OH_Rdb_Store instance.
   int errCode = 0;
   OH_Rdb_Store *store_ = OH_Rdb_CreateOrOpen(config, &errCode);
   ```

3. Create a table and insert data into the table.

   > **NOTE**
   >
   > **VectorStore** does not provide explicit flush operations for data persistence. The data inserted is persisted.

   The sample code is as follows:

   ```c
   char createTableSql[] = "CREATE TABLE test (id INTEGER PRIMARY KEY AUTOINCREMENT, data1 floatvector(2));";
   // Create a table.
   OH_Rdb_ExecuteByTrxId(store_, 0, createTableSql);

   // Insert data without parameter binding.
   OH_Rdb_ExecuteV2(store_, "INSERT INTO test (id, data1) VALUES (0, '[3.4, 4.5]');", nullptr, nullptr);
   // Insert data with parameter binding.
   OH_Data_Values *values = OH_Values_Create();
   OH_Values_PutInt(values, 1);
   float test[] = { 1.2, 2.3 };
   size_t len = sizeof(test) / sizeof(test[0]);
   OH_Values_PutFloatVector(values, test, len);
   char insertSql[] = "INSERT INTO test (id, data1)   VALUES (?, ?);";
   OH_Rdb_ExecuteV2(store_, insertSql, values, nullptr);
   OH_Values_Destroy(values);
   ```

4. Modify or delete data. The sample code is as follows:

   ```c
   // Modify data without parameter binding.
   OH_Rdb_ExecuteV2(store_, "update test set data1 = '[5.1, 6.1] where id = 0;", nullptr, nullptr);

   // Modify data with parameter binding.
   float test1[2] = { 5.5, 6.6 };
   OH_Data_Values *values1 = OH_Values_Create();
   OH_Values_PutFloatVector(values1, test1, 2);
   OH_Values_PutInt(values1, 1);
   OH_Rdb_ExecuteV2(store_, "update test set data1 = ? where id = ?", values1, nullptr);
   OH_Values_Destroy(values1);

   // Delete data without parameter binding.
   OH_Rdb_ExecuteV2(store_, "delete from test where id = 0", nullptr, nullptr);

   // Delete data with parameter binding.
   OH_Data_Values *values2 = OH_Values_Create();
   OH_Values_PutInt(values2, 01);
   OH_Rdb_ExecuteV2(store_, "delete from test where id = ?", values2, nullptr);
   OH_Values_Destroy(values2);
   ```

5. Query data.

   > **NOTE**
   >
   > Use **destroy()** to destroy the **ResultSet** that is no longer used in a timely manner so that the memory allocated can be released.

   The sample code is as follows:

   ```c
   // Query data without parameter binding.
   OH_Cursor *cursor = OH_Rdb_ExecuteQueryV2(store_, "select * from test where id = 1;", nullptr);
   int rowCount = 0;
   cursor->getRowCount(cursor, &rowCount);
   cursor->goToNextRow(cursor);
   size_t count = 0;
   // The floatvector array is the second column of data.
   OH_Cursor_GetFloatVectorCount(cursor, 1, &count);
   float test2[count];
   size_t outLen;
   OH_Cursor_GetFloatVector(cursor, 1, test2, count, &outLen);
   cursor->destroy(cursor);

   // Query data with parameter binding.
   char querySql[] = "select * from test where id = ?;";
   OH_Data_Values *values3 = OH_Values_Create();
   OH_Values_PutInt(values3, 1);
   cursor = OH_Rdb_ExecuteQueryV2(store_, querySql, values3);
   OH_Values_Destroy(values3);
   cursor->destroy(cursor);

   // Query data in another table, and create the table if it does not exist.
   OH_Rdb_ExecuteV2(store_, "CREATE TABLE IF NOT EXISTS test1(id text PRIMARY KEY);", nullptr, nullptr);
   cursor = OH_Rdb_ExecuteQueryV2(store_, "select * from test where id in (select id from test1);", nullptr);
   cursor->destroy(cursor);

   // Perform aggregate query.
   cursor = OH_Rdb_ExecuteQueryV2(store_, "select * from test where data1 <-> '[1.0, 1.0]' > 0 group by id having max(data1 <=> '[1.0, 1.0]');", nullptr);
   cursor->destroy(cursor);

   // Perform multi-table query.
   cursor = OH_Rdb_ExecuteQueryV2(store_, "select id, data1 <-> '[1.5, 5.6]' as distance from test union select id, data1 <-> '[1.5, 5.6]' as distance from test order by distance limit 5;", nullptr);
   cursor->destroy(cursor);
   ```

6. Create a view and query data. The sample code is as follows:

   ```c
   OH_Rdb_ExecuteV2(store_, "CREATE VIEW v1 as select * from test where id > 0;", nullptr, nullptr);
   OH_Cursor *cursor = OH_Rdb_ExecuteQueryV2(store_, "select * from v1;", nullptr);
   cursor->destroy(cursor);
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

   | Name  | Value Range| Description  |
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

   ```c
   // Create an index using the basic syntax. The index name is diskann_l2_idx, index column is repr, type is gsdiskann, and the distance metric is L2.
   OH_Rdb_ExecuteV2(store_, "CREATE INDEX diskann_l2_idx ON test USING GSDISKANN(data1 L2);", nullptr, nullptr);

   // Delete the diskann_l2_idx index from the test table.
   OH_Rdb_ExecuteV2(store_, "DROP INDEX test.diskann_l2_idx;", nullptr, nullptr);

   // Set QUEUE_SIZE to 20 and OUT_DEGREE to 50 using the extended syntax.
   OH_Rdb_ExecuteV2(store_, "CREATE INDEX diskann_l2_idx ON test USING GSDISKANN(repr L2) WITH (queue_size=20, out_degree=50);", nullptr, nullptr);
   ```

8. Configure the data aging policy, which allows the application data to be automatically deleted by time or space.
   
   The syntax is as follows:

   ```sql
   CREATE TABLE table_name(column_name type [, ...]) [WITH(parameter = value [, ...])];
   ```

   **parameter** specifies the parameter to set, and **value** specifies the value of the parameter. The following table describes the fields contained in **parameter**.

   **Table 4** parameter (data aging policy parameters)

   | Name| Mandatory| Description|
   | ------ | -------- | ---------- |
   | time_col | Yes| Column name The value must be an integer and cannot be empty.|
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

   For example, if **ttl** is set to **3 months**, the value will be converted into 7,776,000 seconds (3 x (30 x 24 x 60 x 60)).

   The sample code is as follows:

   ```c
   // The write operation performed every 5 minutes will trigger a data aging task.
   OH_Rdb_ExecuteV2(store_, "CREATE TABLE test2(rec_time integer not null) WITH (time_col = 'rec_time', interval = '5 minute');", nullptr, nullptr);
   ```

9. Delete the database. The sample code is as follows:

   ```c
   OH_Rdb_CloseStore(store_);
   OH_Rdb_DeleteStoreV2(config);
   ```
