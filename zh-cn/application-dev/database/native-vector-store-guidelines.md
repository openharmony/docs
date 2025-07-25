# 通过向量数据库实现数据持久化 (C/C++)


## 场景介绍

向量数据库是一种支持存储、管理和检索向量数据的数据库，也支持标量的关系型数据处理。数据类型"floatvector"用来存储数据向量化的结果，从而实现对这些数据的快速检索和相似性搜索‌。</br>
从API version 18开始，支持通过向量数据库实现数据持久化。

## 基本概念

- **结果集**：指用户查询之后的结果集合，可以对数据进行访问。结果集提供了灵活的数据访问方式，可以更方便地拿到用户想要的数据。
- **floatvector**：该数据类型表示向量数据，例如[1.0, 3.0, 2.4, 5.1, 6.2, 11.7]。

## 约束限制

- 系统默认日志方式是[WAL](data-terminology.md#wal模式)（Write Ahead Log）模式，系统默认落盘方式是[FULL模式](data-terminology.md#full模式)。

- 数据库中默认有4个读连接和1个写连接，线程获取到空闲读连接时，即可进行读取操作。当没有空闲读连接时，会创建新的读连接。

- 为保证数据的准确性，数据库同一时间只能支持一个写操作，并发的写操作会串行执行。

- 当应用被卸载完成后，设备上的相关数据库文件及临时文件会被自动清除。

- 为保证插入并读取数据成功，建议一条数据不要超过2M。超出该大小，插入成功，读取失败。

## 规格限制

详情见[规格限制](data-persistence-by-vector-store.md#规格限制)。

## 接口说明

详细的接口说明请参考[RDB](../reference/apis-arkdata/capi-rdb.md)。

| 接口名称 | 描述 |
| -------- | -------- |
| int OH_Rdb_SetDbType(OH_Rdb_ConfigV2 *config, int dbType) | 设置数据库类型。 |
| OH_Rdb_Store *OH_Rdb_CreateOrOpen(const OH_Rdb_ConfigV2 *config, int *errCode) | 获得一个相关的OH_Rdb_Store实例(调用OH_Rdb_SetDbType设置dbType为RDB_CAYLEY)，操作向量数据库。 |
| int OH_Rdb_ExecuteV2(OH_Rdb_Store *store, const char *sql, const OH_Data_Values *args, OH_Data_Value **result) | 执行有返回值的SQL语句，用来执行写操作，支持参数绑定，语句中的各种表达式和操作符之间的关系操作符号(例如=、>、<)不超过1000个。|
| int OH_Rdb_ExecuteByTrxId(OH_Rdb_Store *store, int64_t trxId, const char *sql) | 使用指定的事务ID执行无返回值的SQL语句，事务ID为0时不使用事务。 |
| OH_Cursor *OH_Rdb_ExecuteQuery(OH_Rdb_Store *store, const char *sql) | 根据指定SQL语句查询数据库中的数据。 |
| OH_Cursor *OH_Rdb_ExecuteQueryV2(OH_Rdb_Store *store, const char *sql, const OH_Data_Values *args) | 根据指定SQL语句查询数据库中的数据，支持参数绑定，语句中的各种表达式和操作符之间的关系操作符号(例如=、>、<)不超过1000个。 |
| int OH_Rdb_DeleteStoreV2(const OH_Rdb_ConfigV2 *config) | 删除数据库。 |
| int OH_Cursor_GetFloatVectorCount(OH_Cursor *cursor, int32_t columnIndex, size_t *length) | 获取当前行中指定列的浮点数数组大小。 |
| int OH_Cursor_GetFloatVector(OH_Cursor *cursor, int32_t columnIndex, float *val, size_t inLen, size_t *outLen) | 以浮点数数组的形式获取当前行中指定列的值，其中inLen不能小于实际的数组大小。 |

## 开发步骤

**添加动态链接库**

CMakeLists.txt中添加以下lib。

```txt
libnative_rdb_ndk.z.so
```

**头文件**

```c++
#include <database/data/oh_data_values.h>
#include <database/rdb/oh_cursor.h>
#include <database/rdb/relational_store.h>
```

1. 判断当前系统是否支持向量数据库，若不支持，则表示当前系统不具备向量数据库能力。示例代码如下：

   ```c
   int numType = 0;
   // 如果numType为2则支持向量数据库，为1则不支持向量数据库
   OH_Rdb_GetSupportedDbType(&numType);
   ```

2. 当前系统支持向量数据库时，获取OH_Rdb_Store实例。示例代码如下：

   ```c
   // 创建OH_Rdb_Config对象
   OH_Rdb_ConfigV2 *config = OH_Rdb_CreateConfig();
   // 该路径为应用沙箱路径
   OH_Rdb_SetDatabaseDir(config, "xxx");
   // 数据库文件名
   OH_Rdb_SetStoreName(config, "rdb_vector_test.db");
   // 应用包名
   OH_Rdb_SetBundleName(config, "xxx");
   // 数据库是否加密
   OH_Rdb_SetEncrypted(config, false);
   // 数据库文件安全等级
   OH_Rdb_SetSecurityLevel(config,   OH_Rdb_SecurityLevel::S1);
   // 数据库文件存放的安全区域
   OH_Rdb_SetArea(config, RDB_SECURITY_AREA_EL1);
   // 数据库类型
   OH_Rdb_SetDbType(config, RDB_CAYLEY);
   
   // 获取OH_Rdb_Store实例
   int errCode = 0;
   OH_Rdb_Store *store_ = OH_Rdb_CreateOrOpen(config, &errCode);
   ```

3. 获取到OH_Rdb_Store后，建表并插入数据。

   > **说明：**
   >
   > 向量数据库没有显式的flush操作实现持久化，数据插入即保存在持久化文件。

   示例代码如下：

   ```c
   char createTableSql[] = "CREATE TABLE test (id INTEGER PRIMARY KEY AUTOINCREMENT, data1 floatvector(2));";
   // 执行建表语句
   OH_Rdb_ExecuteByTrxId(store_, 0, createTableSql);

   // 不使用参数绑定插入数据
   OH_Rdb_ExecuteV2(store_, "INSERT INTO test (id, data1) VALUES (0, '[3.4, 4.5]');", nullptr, nullptr);
   // 使用参数绑定插入数据
   OH_Data_Values *values = OH_Values_Create();
   OH_Values_PutInt(values, 1);
   float test[] = { 1.2, 2.3 };
   size_t len = sizeof(test) / sizeof(test[0]);
   OH_Values_PutFloatVector(values, test, len);
   char insertSql[] = "INSERT INTO test (id, data1)   VALUES (?, ?);";
   OH_Rdb_ExecuteV2(store_, insertSql, values, nullptr);
   OH_Values_Destroy(values);
   ```

4. 获取到OH_Rdb_Store后，修改或删除数据。示例代码如下：

   ```c
   // 不使用参数绑定修改数据
   OH_Rdb_ExecuteV2(store_, "update test set data1 = '[5.1, 6.1]' where id = 0;", nullptr, nullptr);

   // 使用参数绑定修改数据
   float test1[2] = { 5.5, 6.6 };
   OH_Data_Values *values1 = OH_Values_Create();
   OH_Values_PutFloatVector(values1, test1, 2);
   OH_Values_PutInt(values1, 1);
   OH_Rdb_ExecuteV2(store_, "update test set data1 = ? where id = ?", values1, nullptr);
   OH_Values_Destroy(values1);

   // 不使用参数绑定删除数据
   OH_Rdb_ExecuteV2(store_, "delete from test where id = 0", nullptr, nullptr);

   // 使用参数绑定删除数据
   OH_Data_Values *values2 = OH_Values_Create();
   OH_Values_PutInt(values2, 1);
   OH_Rdb_ExecuteV2(store_, "delete from test where id = ?", values2, nullptr);
   OH_Values_Destroy(values2);
   ```

5. 获取到OH_Rdb_Store后，查询数据。

   > **说明：**
   >
   > 当应用完成查询数据操作，不再使用结果集（OH_Cursor）时，请及时调用destroy方法关闭结果集，释放系统为其分配的内存。

   示例代码如下：

   ```c
   // 不使用参数绑定查询数据
   OH_Cursor *cursor = OH_Rdb_ExecuteQueryV2(store_, "select * from test where id = 1;", nullptr);
   int rowCount = 0;
   cursor->getRowCount(cursor, &rowCount);
   cursor->goToNextRow(cursor);
   size_t count = 0;
   // floatvector数组是第二列数据
   OH_Cursor_GetFloatVectorCount(cursor, 1, &count);
   float test2[count];
   size_t outLen;
   OH_Cursor_GetFloatVector(cursor, 1, test2, count, &outLen);
   cursor->destroy(cursor);

   // 使用参数绑定查询数据
   char querySql[] = "select * from test where id = ?;";
   OH_Data_Values *values3 = OH_Values_Create();
   OH_Values_PutInt(values3, 1);
   cursor = OH_Rdb_ExecuteQueryV2(store_, querySql, values3);
   OH_Values_Destroy(values3);
   cursor->destroy(cursor);

   // 子查询，创建第二张表
   OH_Rdb_ExecuteV2(store_, "CREATE TABLE IF NOT EXISTS test1(id text PRIMARY KEY);", nullptr, nullptr);
   cursor = OH_Rdb_ExecuteQueryV2(store_, "select * from test where id in (select id from test1);", nullptr);
   cursor->destroy(cursor);

   // 聚合查询
   cursor = OH_Rdb_ExecuteQueryV2(store_, "select * from test where data1 <-> '[1.0, 1.0]' > 0 group by id having max(data1 <=> '[1.0, 1.0]');", nullptr);
   cursor->destroy(cursor);

   // 多表查询
   cursor = OH_Rdb_ExecuteQueryV2(store_, "select id, data1 <-> '[1.5, 5.6]' as distance from test union select id, data1 <-> '[1.5, 5.6]' as distance from test order by distance limit 5;", nullptr);
   cursor->destroy(cursor);
   ```

6. 创建视图并执行查询。示例代码如下：

   ```c
   OH_Rdb_ExecuteV2(store_, "CREATE VIEW v1 as select * from test where id > 0;", nullptr, nullptr);
   OH_Cursor *cursor = OH_Rdb_ExecuteQueryV2(store_, "select * from v1;", nullptr);
   cursor->destroy(cursor);
   ```

7. ‌使用向量索引进行查询，提升查询效率。

   向量数据库索引‌是一种以向量作为键的索引机制，旨在提供高效且快速的搜索能力。
   
   当前支持的向量索引基础语法和扩展语法如下：

   - 基础语法如下：

     ```sql
     // index_name为索引名称，index_type是索引类型，dist_function是索引距离度量类型
     CREATE INDEX [IF NOT EXISTS] index_name ON table_name USING index_type (column_name dist_function);

     DROP INDEX table_name.index_name;
     ```
   - 扩展语法如下：

     ```sql
     CREATE INDEX [基础语法] [WITH(parameter = value [, ...])];
     ```

   **表1** 索引类型(index_type)

   | 类型      | 备注说明                                                     |
   | --------- | ------------------------------------------------------------ |
   | gsdiskann | 适用于处理高维稠密向量数据，如文本嵌入、图像特征等。         |

   **表2** 索引距离度量类型(dist_function)

   | 类型   | 计算符号 | 备注说明   |
   | ------ | -------- | ---------- |
   | L2     | <->      | 欧式距离。|
   | COSINE | <=>      | 余弦距离。|

   **表3** 扩展语法参数(parameter)

   | 参数名称   | 取值范围和约束 | 备注说明   |
   | ------ | -------- | ---------- |
   | QUEUE_SIZE | 设置范围是[10, 1000]，默认值 20。     | 代表创建索引搜索近邻的时候候选队列的长度，queue_size越大，构建速度降低，召回率有略微提升。 |
   | OUT_DEGREE | 设置范围是[1, 1200] ，默认值 60。      | 邻居节点出度数量。out_degree与pageSize也有关系，out_degree的数量超过pageSize的存储范围将报错GRD_INVALID_ARGS。|

   > **说明：**
   >
   > - 删除索引的时候需要指定表名称，即Drop Index table.index_name。
   > 
   > - 随表一起创建的索引不能删除，如建表时创建的主键。
   > 
   > - 向量索引的命中条件。必须是ORDER BY + LIMIT类型的查询，ORDER BY只有一个排序条件，这个条件是向量距离条件；ORDER BY与DESC连用，不会使用向量索引；查询距离度量与创建索引时的度量需要保持一致，例如创建向量索引时使用L2，在查询时使用<->进行度量才可以命中索引。

   示例代码如下：

   ```c
   // 基础用法，创建的索引名称为diskann_l2_idx，索引列为repr，类型为gsdiskann，距离度量类型为L2
   OH_Rdb_ExecuteV2(store_, "CREATE INDEX diskann_l2_idx ON test USING GSDISKANN(data1 L2);", nullptr, nullptr);

   // 删除表test中的diskann_l2_idx索引
   OH_Rdb_ExecuteV2(store_, "DROP INDEX test.diskann_l2_idx;", nullptr, nullptr);

   // 扩展语法，设置QUEUE_SIZE为20，OUT_DEGREE为50
   OH_Rdb_ExecuteV2(store_, "CREATE INDEX diskann_l2_idx ON test USING GSDISKANN(repr L2) WITH (queue_size=20, out_degree=50);", nullptr, nullptr);
   ```

8. 配置数据老化功能。当应用的数据需要定期清理时，可以按时间或空间配置数据老化策略，从而实现数据的自动化清理。
   
   语法如下所示：

   ```sql
   CREATE TABLE table_name(column_name type [, ...]) [WITH(parameter = value [, ...])];
   ```

   其中，parameter为可配置的参数，value为对应取值，具体情况见下表。

   **表4** 数据老化策略参数(parameter)

   | 参数名称 | 必填 | 取值范围和使用说明 |
   | ------ | -------- | ---------- |
   | time_col | 是 | 列名。类型必须为整数且不为空。 |
   | interval | 否 | 老化任务线程的执行间隔时间，超过该时间后执行写操作，触发老化任务，删除符合老化条件的数据；若在间隔时间内执行写操作，不会触发老化任务。取值范围是[5 second, 1 year]，时间单位支持second、minute、hour、day、month、year，不区分大小写或复数形式(1 hour和1 hours均可)，默认是1 day。 |
   | ttl | 否 | 数据保留时间。取值范围是[1 hour, 1 year]，时间单位支持second、minute、hour、day、month、year，不区分大小写或复数形式(1 hour和1 hours均可)，默认是3 month。 |
   | max_num | 否 | 数据量限制。取值范围是[100, 1024]，默认是1024。老化任务在执行完过期数据删除后，如剩余表内数据超过max_num行，则会找到距离过期时间最近的时间点，删除该时间点对应的所有数据，直到数据量少于max_num。 |

   时间相关参数会按数值换算为秒作为原子单位，取值规则如下所示：

   | 单位 | 向下换算为秒取值 |
   | ------ | -------- |
   | year | 365 * 24 * 60 * 60 |
   | month | 30 * 24 * 60 * 60 |
   | day | 24 * 60 * 60 |
   | hour | 60 * 60 |
   | minute | 60 |

   例如配置`ttl = '3 months'`，实际ttl会被换算为`3 * (30 * 24 * 60 * 60) = 7776000 seconds`。

   示例代码如下：

   ```c
   // 每隔五分钟执行写操作后，会触发数据老化任务
   OH_Rdb_ExecuteV2(store_, "CREATE TABLE test2(rec_time integer not null) WITH (time_col = 'rec_time', interval = '5 minute');", nullptr, nullptr);
   ```

9. 配置数据压缩功能。该功能在建表时配置，可以压缩数据类型为text的列数据。

   从API version 20开始，支持数据压缩功能。

   语法如下所示：

   ```sql
   CREATE TABLE table_name(content text [, ...]) [WITH(compress_col = 'content')];
   ```

   其中，compress_col为必填参数，value是类型为text的数据列名，可以与数据老化功能同时配置。

   示例代码如下：

   ```c
   // content列配置了数据压缩，并且配置了数据老化。
   OH_Rdb_ExecuteV2(store_, "CREATE TABLE IF NOT EXISTS test3 (time integer not null, content text) with (time_col = 'time', interval = '5 minute', compress_col = 'content');", nullptr, nullptr);
   ```

10. 删除数据库。示例代码如下：

    ```c
    OH_Rdb_CloseStore(store_);
    OH_Rdb_DeleteStoreV2(config);
    ```