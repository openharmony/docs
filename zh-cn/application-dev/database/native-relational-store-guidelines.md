# 通过关系型数据库实现数据持久化 (C/C++)

## 场景介绍

RelationalStore提供了一套完整的对本地数据库进行管理的机制，对外提供了一系列的增、删、改、查等接口，也可以直接运行用户输入的SQL语句来满足复杂的场景需要。


## 基本概念

- **谓词**：数据库中用来代表数据实体的性质、特征或者数据实体之间关系的词项，主要用来定义数据库的操作条件。

- **结果集**：指用户查询之后的结果集合，可以对数据进行访问。结果集提供了灵活的数据访问方式，可以更方便地拿到用户想要的数据。


## 约束限制

- 系统默认日志方式是WAL（Write Ahead Log）模式，系统默认落盘方式是FULL模式。

- 数据库中连接池的最大数量是4个，用以管理用户的读操作。

- 为保证数据的准确性，数据库同一时间仅支持一个写操作。

- 当应用被卸载完成后，设备上的相关数据库文件及临时文件会被自动清除。

## 接口说明

详细的接口说明请参考[RDB](../reference/apis-arkdata/capi-rdb.md)。

| 接口名称 | 描述 |
| -------- | -------- |
 OH_Rdb_ConfigV2 *OH_Rdb_CreateConfig() | 创建一个OH_Rdb_ConfigV2实例，并返回指向该实例的指针。 |
 int OH_Rdb_SetDatabaseDir(OH_Rdb_ConfigV2 *config, const char *databaseDir) | 给指定的数据库文件配置OH_Rdb_ConfigV2，设置数据库文件路径。 |
 int OH_Rdb_SetStoreName(OH_Rdb_ConfigV2 *config, const char *storeName) | 给指定的数据库文件配置OH_Rdb_ConfigV2，设置数据库名称。 |
 int OH_Rdb_SetBundleName(OH_Rdb_ConfigV2 *config, const char *bundleName) | 给指定的数据库文件配置OH_Rdb_ConfigV2，设置应用包名。 |
 int OH_Rdb_SetModuleName(OH_Rdb_ConfigV2 *config, const char *moduleName) | 给指定的数据库文件配置OH_Rdb_ConfigV2，设置应用模块名。 |
 int OH_Rdb_SetSecurityLevel(OH_Rdb_ConfigV2 *config, int securityLevel) | 给指定的数据库文件配置OH_Rdb_ConfigV2，设置数据库安全级别OH_Rdb_SecurityLevel。 |
 int OH_Rdb_SetEncrypted(OH_Rdb_ConfigV2 *config, bool isEncrypted) | 给指定的数据库文件配置OH_Rdb_ConfigV2，设置数据库是否加密。 |
 int OH_Rdb_SetArea(OH_Rdb_ConfigV2 *config, int area) | 给指定的数据库文件配置OH_Rdb_ConfigV2，设置数据库安全区域等级Rdb_SecurityArea。 |
| OH_Rdb_Store *OH_Rdb_CreateOrOpen(const OH_Rdb_ConfigV2 *config, int *errCode) | 使用数据库配置OH_Rdb_ConfigV2，获得一个对应的OH_Rdb_Store实例，用来操作关系型数据库。 |
| OH_Rdb_Execute(OH_Rdb_Store *store, const char *sql) | 执行包含指定参数但不返回值的SQL语句。 |
| OH_Rdb_Insert(OH_Rdb_Store *store, const char *table, OH_VBucket *valuesBucket) | 向目标表中插入一行数据。 |
| int OH_Rdb_InsertWithConflictResolution(OH_Rdb_Store *store, const char *table, OH_VBucket *row, Rdb_ConflictResolution resolution, int64_t *rowId) | 向目标表中插入一行数据，支持配置冲突解决策略。 |
| int OH_Rdb_UpdateWithConflictResolution(OH_Rdb_Store *store, OH_VBucket *row, OH_Predicates *predicates, Rdb_ConflictResolution resolution, int64_t *changes) | 向目标表中插入一行数据，支持配置冲突解决策略。 |
| OH_Rdb_Update(OH_Rdb_Store *store, OH_VBucket *valuesBucket, OH_Predicates *predicates) | 根据OH_Predicates的指定实例对象更新数据库中的数据。 |
| OH_Rdb_Delete(OH_Rdb_Store *store, OH_Predicates *predicates) | 根据OH_Predicates的指定实例对象从数据库中删除数据。 |
| int OH_Predicates_NotLike(OH_Predicates *predicates, const char *field, const char *pattern) | 设置OH_Predicates以匹配数据类型为字符串且值不类似于指定值的字段。 |
| int OH_Predicates_Glob(OH_Predicates *predicates, const char *field, const char *pattern) | 设置OH_Predicates以匹配指定字段（数据类型为字符串）且值包含通配符的字段。 |
| int OH_Predicates_NotGlob(OH_Predicates *predicates, const char *field, const char *pattern) | 设置OH_Predicates以不匹配指定字段（数据类型为字符串）且值包含通配符的字段。 |
| OH_Rdb_Query(OH_Rdb_Store *store, OH_Predicates *predicates, const char *const *columnNames, int length) | 根据指定条件查询数据库中的数据。 |
| OH_Rdb_DeleteStore(const OH_Rdb_Config *config) | 删除数据库。 |
| OH_VBucket_PutAsset(OH_VBucket *bucket, const char *field, Rdb_Asset *value) | 把Rdb_Asset类型的数据放到指定的OH_VBucket对象中。 |
| OH_VBucket_PutAssets(OH_VBucket *bucket, const char *field, Rdb_Asset *value, uint32_t count) | 把Rdb_Asset数组类型的数据放到指定的OH_VBucket对象中。 |
| OH_Rdb_FindModifyTime(OH_Rdb_Store *store, const char *tableName, const char *columnName, OH_VObject *values) | 获取数据库指定表中指定列的数据的最后修改时间。 |
| OH_RDB_TransOptions *OH_RdbTrans_CreateOptions(void) | 创建一个OH_RDB_TransOptions实例，配置事务对象。 |
| OH_Cursor *OH_RdbTrans_Query(OH_Rdb_Transaction *trans, const OH_Predicates *predicates, const char *columns[], int len) | 根据指定的条件查询数据库中的数据。 |
| OH_Data_Values *OH_Values_Create(void) | 创建OH_Data_Values实例。 |
| int OH_Data_Asset_SetName(Data_Asset *asset, const char *name) | 为资产类型数据设置名称。 |
| int OH_Data_Asset_SetUri(Data_Asset *asset, const char *uri) | 为资产类型数据设置绝对路径。 |
| int OH_Data_Asset_SetPath(Data_Asset *asset, const char *path) | 为资产类型数据设置应用沙箱里的相对路径。 |
| int OH_Data_Asset_SetCreateTime(Data_Asset *asset, int64_t createTime) | 为资产类型数据设置创建时间。 |
| int OH_Data_Asset_SetModifyTime(Data_Asset *asset, int64_t modifyTime) | 为资产类型数据设置最后修改时间。 |
| int OH_Data_Asset_SetSize(Data_Asset *asset, size_t size) | 为资产类型数据设置占用空间大小。 |
| int OH_Data_Asset_SetStatus(Data_Asset *asset, Data_AssetStatus status) | 为资产类型数据设置状态码。 |
| int OH_Data_Asset_GetName(Data_Asset *asset, char *name, size_t *length) | 获取资产类型数据的名称。 |
| int OH_Data_Asset_GetUri(Data_Asset *asset, char *uri, size_t *length) | 获取资产类型数据的绝对路径。 |
| int OH_Data_Asset_GetPath(Data_Asset *asset, char *path, size_t *length) | 获取资产类型数据在应用沙箱内的相对路径。 |
| int OH_Data_Asset_GetCreateTime(Data_Asset *asset, int64_t *createTime) | 获取资产类型数据的创建时间。 |
| int OH_Data_Asset_GetModifyTime(Data_Asset *asset, int64_t *modifyTime) | 获取资产类型数据的最后修改时间。 |
| int OH_Data_Asset_GetSize(Data_Asset *asset, size_t *size) | 获取资产类型数据的占用空间大小。 |
| int OH_Data_Asset_GetStatus(Data_Asset *asset, Data_AssetStatus *status) | 获取资产类型数据的状态码。 |
| Data_Asset *OH_Data_Asset_CreateOne() | 创造一个资产类型实例。使用完毕后需要调用OH_Data_Asset_DestroyOne释放内存。 |
| int OH_Data_Asset_DestroyOne(Data_Asset *asset) | 销毁一个资产类型实例并回收内存。 |
| Data_Asset **OH_Data_Asset_CreateMultiple(uint32_t count) | 创造指定数量的资产类型实例。使用完毕后需要调用OH_Data_Asset_DestroyMultiple释放内存。 |
| int OH_Data_Asset_DestroyMultiple(Data_Asset **assets, uint32_t count) | 销毁指定数量的资产类型实例并回收内存。 |
| int OH_Rdb_CreateTransaction(OH_Rdb_Store *store, const OH_RDB_TransOptions *options, OH_Rdb_Transaction **trans) | 创建一个相关的OH_Rdb_Transaction实例，开启事务。 |
| int OH_RdbTransOption_SetType(OH_RDB_TransOptions *opitons, OH_RDB_TransType type) | 设置事务对象类型。 |
| int OH_RdbTrans_Insert(OH_Rdb_Transaction *trans, const char *table, const OH_VBucket *row, int64_t *rowId) | 向目标表中插入一行数据。 |
| int OH_RdbTrans_InsertWithConflictResolution(OH_Rdb_Transaction *trans, const char *table, const OH_VBucket *row, Rdb_ConflictResolution resolution, int64_t *rowId) | 将一行数据插入到目标表中，支持冲突解决。 |
| int OH_RdbTrans_UpdateWithConflictResolution(OH_Rdb_Transaction *trans, const OH_VBucket *row, const OH_Predicates *predicates, Rdb_ConflictResolution resolution, int64_t *changes) | 根据指定条件更新数据库中的数据，并支持冲突解决。 |
| int OH_RdbTrans_Delete(OH_Rdb_Transaction *trans, const OH_Predicates *predicates, int64_t *changes) | 根据OH_Predicates的指定实例对象从数据库中删除数据。 |
| int OH_Value_Destroy(OH_Data_Value *value) | 销毁OH_Data_Value对象。 |
| int OH_Values_Destroy(OH_Data_Values *values) | 销毁OH_Values_Destroy对象。 |
| int OH_RdbTrans_Execute(OH_Rdb_Transaction *trans, const char *sql, const OH_Data_Values *args, OH_Data_Value **result) | 执行包含指定参数的SQL语句。 |
| int OH_RdbTrans_Commit(OH_Rdb_Transaction *trans) | 提交事务。 |
| int OH_RdbTrans_Rollback(OH_Rdb_Transaction *trans) | 回滚事务。 |
| int OH_RdbTrans_Destroy(OH_Rdb_Transaction *trans) | 销毁OH_Rdb_Transaction实例。 |
| int OH_Rdb_Attach(OH_Rdb_Store *store, const OH_Rdb_ConfigV2 *config, const char *attachName, int64_t waitTime, size_t *attachedNumber) | 将数据库文件附加到当前连接的数据库。 |
| int OH_Rdb_Detach(OH_Rdb_Store *store, const char *attachName, int64_t waitTime, size_t *attachedNumber) | 从当前数据库中分离指定的数据库。 |
| int OH_Rdb_SetCustomDir(OH_Rdb_ConfigV2 *config, const char *customDir) | 设置数据库的自定义目录。 |
| int OH_Rdb_SetLocale(OH_Rdb_Store *store, const char *locale) | 支持不同语言的排序规则。 |
| int OH_Rdb_SetPlugins(OH_Rdb_ConfigV2 *config, const char **plugins, int32_t length) | 设置具有特定功能（如全文检索）的动态库。 |

## 开发步骤

**添加动态链接库**

CMakeLists.txt中添加以下lib。

```txt
libnative_rdb_ndk.z.so
```

**头文件**

```c
#include <database/data/data_asset.h>
#include <database/rdb/oh_cursor.h>
#include <database/rdb/oh_predicates.h>
#include <database/rdb/oh_value_object.h>
#include <database/rdb/oh_values_bucket.h>
#include <database/rdb/relational_store.h>
#include <database/rdb/relational_store_error_code.h>
```

1. 获取OH_Rdb_Store实例，创建数据库文件。其中dataBaseDir变量为应用沙箱路径，Stage模式下建议使用数据库目录，参考[Context](../reference/apis-ability-kit/js-apis-inner-application-context.md)的databaseDir属性。FA模式下，由于没有接口获取数据库沙箱路径，可使用应用程序的文件目录，可参考[Context](../reference/apis-ability-kit/js-apis-inner-app-context.md)的getFilesDir接口。area为数据库文件存放的安全区域，详见[contextConstant](../reference/apis-ability-kit/js-apis-app-ability-contextConstant.md)，开发时需要实现由AreaMode枚举值对Rdb_SecurityArea枚举值的转换。示例代码如下所示：

   ```c
   // 创建OH_Rdb_ConfigV2对象
   OH_Rdb_ConfigV2* config = OH_Rdb_CreateConfig();
   // 该路径为应用沙箱路径
   // 数据库文件创建位置将位于沙箱路径 /data/storeage/el2/database/rdb/RdbTest.db
   OH_Rdb_SetDatabaseDir(config, "/data/storage/el2/database");
   // 数据库文件名
   OH_Rdb_SetStoreName(config, "RdbTest.db");
   // 应用包名
   OH_Rdb_SetBundleName(config, "com.example.nativedemo");
   // 应用模块名
   OH_Rdb_SetModuleName(config, "entry");
   // 数据库文件安全等级
   OH_Rdb_SetSecurityLevel(config, OH_Rdb_SecurityLevel::S3);
   // 数据库是否加密
   OH_Rdb_SetEncrypted(config, false);
   // 数据库文件存放的安全区域
   OH_Rdb_SetArea(config, RDB_SECURITY_AREA_EL2);

   int errCode = 0;
   // 获取OH_Rdb_Store实例
   OH_Rdb_Store *store_ = OH_Rdb_CreateOrOpen(config, &errCode);
   ```

   ```c
    // 可设置自定义数据库路径
    // 数据库文件创建位置将位于沙箱路径 /data/storeage/el2/database/a/b/RdbTest.db
    OH_Rdb_SetCustomDir(config, "../a/b");
    // 可设置为只读模式打开数据库
    OH_Rdb_SetReadOnly(config, true);
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

   OH_VBucket *valueBucket2 = OH_Rdb_CreateValuesBucket();
   valueBucket2->putInt64(valueBucket2, "ID", 1);
   valueBucket2->putText(valueBucket2, "NAME", "zhangsan");
   valueBucket2->putInt64(valueBucket2, "AGE", 24);
   valueBucket2->putReal(valueBucket2, "SALARY", 120.4);
   int64_t rowId2 = -1;
   // 支持插入数据时配置冲突策略
   int result = OH_Rdb_InsertWithConflictResolution(store_, "EMPLOYEE", valueBucket2,
                                                    Rdb_ConflictResolution::RDB_CONFLICT_REPLACE, &rowId2);
   // 销毁键值对实例
   valueBucket->destroy(valueBucket);
   valueBucket2->destroy(valueBucket2);
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
   int rowId = OH_Rdb_Insert(store_, "EMPLOYEE", valueBucket);
   OH_Predicates *predicates2 = OH_Rdb_CreatePredicates("EMPLOYEE");
   OH_VObject *valueObject2 = OH_Rdb_CreateValueObject();
   valueObject2->putText(valueObject2, "Rose");
   predicates2->equalTo(predicates2, "NAME", valueObject2);
   valueBucket->putInt64(valueBucket, "ID", 1);
   valueBucket->putText(valueBucket, "NAME", "zhangsan");
   int64_t changeRows2 = -1;

   // 支持更新数据时配置冲突策略
   int result = OH_Rdb_UpdateWithConflictResolution(store_, valueBucket, predicates2,
                                                    Rdb_ConflictResolution::RDB_CONFLICT_REPLACE, &changeRows2);
   valueObject->destroy(valueObject);
   valueObject2->destroy(valueObject2);
   valueBucket->destroy(valueBucket);
   predicates->destroy(predicates);
   predicates2->destroy(predicates2);
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
   
   配置谓词以LIKE模式或NOTLIKE模式匹配进行数据查询。示例代码如下：

   ```c
   OH_Predicates *likePredicates = OH_Rdb_CreatePredicates("EMPLOYEE");
   
   OH_VObject *likePatten = OH_Rdb_CreateValueObject();
   likePatten->putText(likePatten, "zh%");
   // 配置谓词以LIKE模式匹配
   likePredicates->like(likePredicates, "NAME", likePatten);

   char *colName[] = { "NAME", "AGE" };
   auto *likeQueryCursor = OH_Rdb_Query(store_, likePredicates, colName, 2);
   likeQueryCursor->goToNextRow(likeQueryCursor);
   size_t dataLength = 0;
   int colIndex = -1;
   likeQueryCursor->getColumnIndex(likeQueryCursor, "NAME", &colIndex);
   likeQueryCursor->getSize(likeQueryCursor, colIndex, &dataLength);
   char name[dataLength + 1];
   likeQueryCursor->getText(likeQueryCursor, colIndex, name, dataLength + 1);

   likeQueryCursor->destroy(likeQueryCursor);
   likePredicates->destroy(likePredicates);
   likePatten->destroy(likePatten);

   OH_Predicates *notLikePredicates = OH_Rdb_CreatePredicates("EMPLOYEE");
   
   // 配置谓词以NOT LIKE模式匹配
   OH_Predicates_NotLike(notLikePredicates, "NAME", "zh%");
   auto *notLikeQueryCursor = OH_Rdb_Query(store_, notLikePredicates, colName, 2);
   notLikeQueryCursor->goToNextRow(notLikeQueryCursor);
   dataLength = 0;
   colIndex = -1;
   notLikeQueryCursor->getColumnIndex(notLikeQueryCursor, "NAME", &colIndex);
   notLikeQueryCursor->getSize(notLikeQueryCursor, colIndex, &dataLength);
   char name2[dataLength + 1];
   notLikeQueryCursor->getText(notLikeQueryCursor, colIndex, name2, dataLength + 1);
   
   notLikeQueryCursor->destroy(notLikeQueryCursor);
   notLikeQueryCursor->destroy(notLikeQueryCursor);
   ```

   配置谓词以GLOB模式或NOTGLOB模式匹配进行数据查询。示例代码如下：

   ```c
   OH_Predicates *globPredicates = OH_Rdb_CreatePredicates("EMPLOYEE");
   // 配置谓词以GLOB模式匹配
   OH_Predicates_Glob(globPredicates, "NAME", "zh*");
   
   char *colName[] = { "NAME", "AGE" };
   auto *globQueryCursor = OH_Rdb_Query(store_, globPredicates, colName, 2);
   globQueryCursor->goToNextRow(globQueryCursor);
   size_t dataLength = 0;
   int colIndex = -1;
   globQueryCursor->getColumnIndex(globQueryCursor, "NAME", &colIndex);
   globQueryCursor->getSize(globQueryCursor, colIndex, &dataLength);
   char name[dataLength + 1];
   globQueryCursor->getText(globQueryCursor, colIndex, name, dataLength + 1);
   
   globQueryCursor->destroy(globQueryCursor);
   globPredicates->destroy(globPredicates);
   
   OH_Predicates *notGlobPredicates = OH_Rdb_CreatePredicates("EMPLOYEE");
   // 配置谓词以NOT GLOB模式匹配
   OH_Predicates_NotGlob(notGlobPredicates, "NAME", "zh*");
   auto *notGlobQueryCursor = OH_Rdb_Query(store_, notGlobPredicates, colName, 2);
   notGlobQueryCursor->goToNextRow(notGlobQueryCursor);
   dataLength = 0;
   colIndex = -1;
   notGlobQueryCursor->getColumnIndex(notGlobQueryCursor, "NAME", &colIndex);
   notGlobQueryCursor->getSize(notGlobQueryCursor, colIndex, &dataLength);
   char name2[dataLength + 1];
   notGlobQueryCursor->getText(notGlobQueryCursor, colIndex, name2, dataLength + 1);
   
   notGlobQueryCursor->destroy(notGlobQueryCursor);
   notGlobPredicates->destroy(notGlobPredicates);
   ```

   如需指定排序时使用的语言规则，例如zh_CN表示中文，tr_TR表示土耳其语等。可调用OH_Rdb_SetLocale配置相应规则。

    ```c
    OH_Rdb_SetLocale(store_, "zh_CN");
    ```

    如需配置fts（Full-Text Search，即全文搜索引擎）动态库，可使用OH_Rdb_SetPlugins接口进行配置。
    
    使用约束详见[StoreConfig](../reference/apis-arkdata/arkts-apis-data-relationalStore-i.md#storeconfig)中pluginLibs配置项。

    ```c
    const char *plugins[] = {
        "/data/storage/el1/bundle/libs/arm64/libtokenizer.so"
    };
    
    int32_t count = sizeof(plugins) / sizeof(plugins[0]);
    auto setResult = OH_Rdb_SetPlugins(config, plugins, count);
    ```
5. 使用事务对象进行插入、删除或更新数据操作。

   调用OH_RdbTransOption_SetType方法，配置要创建的事务类型，
   支持配置的事务类型有DEFERRED、IMMEDIATE和EXCLUSIVE，默认为DEFERRED。

   调用OH_Rdb_CreateTransaction方法创建事务对象，使用该事务对象执行相应事务操作。

    ```c
    OH_RDB_TransOptions *options;
    options = OH_RdbTrans_CreateOptions();
    // 配置事务类型
    OH_RdbTransOption_SetType(options, RDB_TRANS_DEFERRED);
    OH_Rdb_Transaction *trans = nullptr;
    // 创建事务对象
    int ret = OH_Rdb_CreateTransaction(store_, options, &trans);

    OH_RdbTrans_DestroyOptions(options);

    char transCreateTableSql[] =
        "CREATE TABLE IF NOT EXISTS transaction_table (id INTEGER PRIMARY KEY AUTOINCREMENT, data1 INTEGER, "
        "data2 INTEGER, data3 FLOAT, data4 TEXT, data5 BLOB, data6 ASSET, data7 ASSETS, data8 UNLIMITED INT, "
        "data9 FLOATVECTOR);";

    auto *execResult = OH_Value_Create();

    // 通过事务对象执行创建数据库表SQL语句
    ret = OH_RdbTrans_Execute(trans, transCreateTableSql, nullptr, &execResult);

    // 创建OH_Data_Values实例
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

    // 通过事务对象执行数据插入SQL语句
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
    // 通过事务对象执行OH_VBucket数据插入
    int insertRet = OH_RdbTrans_Insert(trans, "transaction_table", transValueBucket, &insertRowId);
    transValueBucket->destroy(transValueBucket);

    OH_VBucket *transValueBucket2 = OH_Rdb_CreateValuesBucket();
    transValueBucket2->putInt64(transValueBucket2, "id", 1);
    transValueBucket2->putInt64(transValueBucket2, "data2", 2);
    transValueBucket2->putReal(transValueBucket2, "data3", 1.2);

    int64_t transInsertRow = -1;
    // 支持插入数据时配置冲突策略
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
    // 支持更新数据时配置冲突策略
    OH_RdbTrans_UpdateWithConflictResolution(trans, transValueBucket3, transUpdatePredicates,
                                             Rdb_ConflictResolution::RDB_CONFLICT_REPLACE, &updateRows);
    targetValue->destroy(targetValue);
    transValueBucket3->destroy(transValueBucket3);
    transUpdatePredicates->destroy(transUpdatePredicates);

    OH_Predicates *predicates = OH_Rdb_CreatePredicates("transaction_table");
    const char *columns[] = {"data1", "data2", "data3"};
    // 通过事务对象执行数据查询
    OH_Cursor *cursor = OH_RdbTrans_Query(trans, predicates, columns, sizeof(columns) / sizeof(columns[0]));
    int columnCount = 0;
    cursor->getColumnCount(cursor, &columnCount);

    predicates->destroy(predicates);
    cursor->destroy(cursor);

    OH_Predicates *predicates2 = OH_Rdb_CreatePredicates("transaction_table");
    OH_VObject *valueObject = OH_Rdb_CreateValueObject();
    valueObject->putText(valueObject, "1");
    predicates->equalTo(predicates, "data4", valueObject);
    int64_t changes = -1;
    // 通过事务对象执行数据删除
    int deleteRet = OH_RdbTrans_Delete(trans, predicates2, &changes);
    predicates->destroy(predicates);
    valueObject->destroy(valueObject);

    // 提交事务
    OH_RdbTrans_Commit(trans);
    // 销毁事务
    OH_RdbTrans_Destroy(trans);
    ```

    ```c
    OH_RDB_TransOptions *options2;
    options2 = OH_RdbTrans_CreateOptions();
    OH_RdbTransOption_SetType(options, RDB_TRANS_DEFERRED);
    OH_Rdb_Transaction *trans2 = nullptr;
    int transCreateRet = OH_Rdb_CreateTransaction(store_, options2, &trans2);
    OH_RdbTrans_DestroyOptions(options2);

    // 回滚事务
    OH_RdbTrans_Rollback(trans2);
    OH_RdbTrans_Destroy(trans2);

    ```

6. 附加数据库。
   
    调用OH_Rdb_Attach将一个数据库文件附加到当前数据库中，以便在SQL语句中可以直接访问附加数据库中的数据。
    此API不支持附加加密数据库。

    调用attach接口后，数据库切换为非WAL模式，性能会存在一定的劣化。切换模式需要确保所有的OH_Cursor都已经销毁，所有的写操作已经结束，否则会报错14800015。
    
    attach不能并发调用，可能出现未响应情况，报错14800015，需要重试。
    
    当不再使用附加数据时，可调用OH_Rdb_Detach分离附加数据库。

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

    // 创建示例 RdbAttach.db 
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

    // 附加数据库
    size_t attachedCount = 0;
    int result = OH_Rdb_Attach(store_, configAttach, "attach", 10, &attachedCount);
    auto predicates = OH_Rdb_CreatePredicates("attach.EMPLOYEE");
    char *colName[] = {};
    auto cursor = OH_Rdb_Query(store_, predicates, colName, 0);
    int rowCount = -1;
    result = cursor->getRowCount(cursor, &rowCount);
    cursor->destroy(cursor);
    
    // 分离数据库
    result = OH_Rdb_Detach(store_, "attach", 10, &attachedCount);
    ```

7. 向数据库表中插入资产类型数据。

   ```c
   // 列的属性为单个资产类型时，sql语句中应指定为asset，多个资产类型应指定为assets。
   char createAssetTableSql[] = "CREATE TABLE IF NOT EXISTS asset_table (id INTEGER PRIMARY KEY AUTOINCREMENT, data1 asset, data2 assets );";
   errCode = OH_Rdb_Execute(store_, createAssetTableSql);
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
   
   errCode = OH_VBucket_PutAssets(valueBucket, "data2", assets, assetsCount);
   int rowID = OH_Rdb_Insert(cursorTestRdbStore_, table, valueBucket);
   // 释放Data_Asset*和Data_Asset**
   OH_Data_Asset_DestroyMultiple(assets, 2);
   OH_Data_Asset_DestroyOne(asset);
   ```

8. 从结果集中读取资产类型数据。

   ```c
   OH_Predicates *predicates = OH_Rdb_CreatePredicates("asset_table");
   
   OH_Cursor *cursor = OH_Rdb_Query(cursorTestRdbStore_, predicates, NULL, 0);
   cursor->goToNextRow(cursor);
   
   uint32_t assetCount = 0;
   // assetCount作为出参获取该列资产类型数据的数量
   errCode = cursor->getAssets(cursor, 2, nullptr, &assetCount);
   Data_Asset **assets = OH_Data_Asset_CreateMultiple(assetCount);
   errCode = cursor->getAssets(cursor, 2, assets, &assetCount);
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

9. 查询数据的最后修改时间。调用OH_Rdb_FindModifyTime查询指定表中指定列的数据的最后修改时间，该接口返回一个有两列数据的OH_Cursor对象，第一列为传入的主键/RowId，第二列为最后修改时间。示例代码如下所示：

   ```c
   OH_VObject *values = OH_Rdb_CreateValueObject();
   int64_t keys[] = { 1 };
   values->putInt64(values, keys, 1);
   OH_Cursor *cursor;
   cursor = OH_Rdb_FindModifyTime(store_, "EMPLOYEE", "ROWID", values);
   ```

10. 删除数据库。调用OH_Rdb_DeleteStore方法，删除数据库及数据库相关文件。示例代码如下：
    
    ```c
    // 释放数据库实例
    OH_Rdb_CloseStore(store_);
    // 删除数据库文件
    OH_Rdb_DeleteStoreV2(config);
    ```
