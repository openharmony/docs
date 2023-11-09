# RelationalStore开发指导


## 场景介绍

RelationalStore提供了一套完整的对本地数据库进行管理的机制，对外提供了一系列的增、删、改、查等接口，也可以直接运行用户输入的SQL语句来满足复杂的场景需要。


## 基本概念

- **谓词**：数据库中用来代表数据实体的性质、特征或者数据实体之间关系的词项，主要用来定义数据库的操作条件。

- **结果集**：指用户查询之后的结果集合，可以对数据进行访问。结果集提供了灵活的数据访问方式，可以更方便地拿到用户想要的数据。


## 约束限制

- 系统默认日志方式是WAL（Write Ahead Log）模式，系统默认落盘方式是FULL模式。

- 数据库中连接池的最大数量是4个，用以管理用户的读操作。

- 为保证数据的准确性，数据库同一时间只能支持一个写操作。

- 当应用被卸载完成后，设备上的相关数据库文件及临时文件会被自动清除。


## 接口说明

详细的接口说明请参考[RDB](../reference/native-apis/_r_d_b.md)。

| 接口名称 | 描述 |
| -------- | -------- |
| OH_Rdb_GetOrOpen(const OH_Rdb_Config *config, int *errCode) | 获得一个相关的OH_Rdb_Store实例，操作关系型数据库。 |
| OH_Rdb_Execute(OH_Rdb_Store *store, const char *sql) | 执行包含指定参数但不返回值的SQL语句。 |
| OH_Rdb_Insert(OH_Rdb_Store *store, const char *table, OH_VBucket *valuesBucket) | 向目标表中插入一行数据。 |
| OH_Rdb_Update(OH_Rdb_Store *store, OH_VBucket *valuesBucket, OH_Predicates *predicates); | 根据OH_Predicates的指定实例对象更新数据库中的数据。 |
| OH_Rdb_Delete(OH_Rdb_Store *store, OH_Predicates *predicates) | 根据OH_Predicates的指定实例对象从数据库中删除数据。 |
| OH_Rdb_Query(OH_Rdb_Store *store, OH_Predicates *predicates, const char *const *columnNames, int length) | 根据指定条件查询数据库中的数据。 |
| OH_Rdb_DeleteStore(const OH_Rdb_Config *config) | 删除数据库。 |


## 开发步骤

**添加动态链接库**

CMakeLists.txt中添加以下lib。

```txt
libnative_rdb_ndk.z.so
```

**头文件**
```c++
#include <oh_cursor.h>
#include <oh_predicates.h>
#include <oh_value_object.h>
#include <oh_values_bucket.h>
#include <relational_store.h>
#include <relational_store_error_code.h>

```

1. 获取OH_Rdb_Store实例，创建数据库文件。其中dataBaseDir变量为应用沙箱路径，Stage模式下建议使用数据库目录，参考[Context](../reference/apis/js-apis-inner-application-context.md)的databaseDir属性。FA模式下，由于没有接口获取数据库沙箱路径，可使用应用程序的文件目录，可参考[Context](../reference/apis/js-apis-inner-app-context.md)的getFilesDir接口。示例代码如下所示：

   ```c
   // 创建OH_Rdb_Config对象
   OH_Rdb_Config config;
   // 该路径为应用沙箱路径
   config.dataBaseDir = "xxx";
   // 数据库文件名
   config.storeName = "RdbTest.db";
   // 应用包名
   config.bundleName = "xxx";
   // 应用模块名
   config.moduleName = "xxx";
   // 数据库文件安全等级
   config.securityLevel = OH_Rdb_SecurityLevel::S1;
   // 数据库是否加密
   config.isEncrypt = false;
   // config所占内存大小
   config.selfSize = sizeof(OH_Rdb_Config);
   
   int errCode = 0;
   // 获取获取OH_Rdb_Store实例
   OH_Rdb_Store *store_ = OH_Rdb_GetOrOpen(&config, &errCode);
   ```

2. 获取到OH_Rdb_Store后，调用OH_Rdb_Execute接口创建表，并调用OH_Rdb_Insert接口插入数据。示例代码如下所示：

   ```c
   char createTableSql[] = "CREATE TABLE IF NOT EXISTS EMPLOYEE (ID INTEGER PRIMARY KEY AUTOINCREMENT, NAME TEXT NOT NULL, "
                           "AGE INTEGER, SALARY REAL, CODES BLOB)";
   // 执行建表语句
   OH_Rdb_Execute(store_, createTableSql);
   
   // 创建键值对实例
   OH_VBucket *valueBucket = OH_Rdb_CreateValuesBucket();
   valueBucket->putText(valueBucket, "NAME", "Lisa");
   valueBucket->putInt64(valueBucket, "AGE", 18);
   valueBucket->putReal(valueBucket, "SALARY", 100.5);
   uint8_t arr[] = {1, 2, 3, 4, 5};
   int len = sizeof(arr) / sizeof(arr[0]);
   valueBucket->putBlob(valueBucket, "CODES", arr, len);
   // 插入数据
   int rowId = OH_Rdb_Insert(store_, "EMPLOYEE", valueBucket);
   // 销毁键值对实例
   valueBucket->destroy(valueBucket);
   ```

   > **说明：**
   >
   > 关系型数据库没有显式的flush操作实现持久化，数据插入即保存在持久化文件。

3. 根据谓词指定的实例对象，对数据进行修改或删除。

   调用OH_Rdb_Update方法修改数据，调用OH_Rdb_Delete方法删除数据。示例代码如下所示：

   ```c
   // 修改数据
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
   // 删除数据
   OH_Predicates *predicates = OH_Rdb_CreatePredicates("EMPLOYEE");
   OH_VObject *valueObject = OH_Rdb_CreateValueObject();
   const char *name = "Lisa";
   valueObject->putText(valueObject, name);
   predicates->equalTo(predicates, "NAME", valueObject);
   int deleteRows = OH_Rdb_Delete(store_, predicates);
   valueObject->destroy(valueObject);
   predicates->destroy(predicates);
   ```

4. 根据谓词指定的查询条件查找数据。

   调用OH_Rdb_Query方法查找数据，返回一个OH_Cursor结果集。示例代码如下所示：

   ```c
   OH_Predicates *predicates = OH_Rdb_CreatePredicates("EMPLOYEE");
   
   const char *columnNames[] = {"NAME", "AGE"};
   int len = sizeof(columnNames) / sizeof(columnNames[0]);
   OH_Cursor *cursor = OH_Rdb_Query(store_, predicates, columnNames, len);
   
   int columnCount = 0;
   cursor->getColumnCount(cursor, &columnCount);
   
   // OH_Cursor是一个数据集合的游标，默认指向第-1个记录，有效的数据从0开始
   int64_t age;
   while (cursor->goToNextRow(cursor) == OH_Rdb_ErrCode::RDB_OK) {
       cursor->getInt64(cursor, 1, &age);
   }
   
   // 释放谓词实例
   predicates->destroy(predicates);
   // 释放结果集
   cursor->destroy(cursor);
   ```

5. 删除数据库。

   调用OH_Rdb_DeleteStore方法，删除数据库及数据库相关文件。示例代码如下：


   ```c
   // 释放数据库实例
   OH_Rdb_CloseStore(store_);
   // 删除数据库文件
   OH_Rdb_DeleteStore(&config);
   ```

   

