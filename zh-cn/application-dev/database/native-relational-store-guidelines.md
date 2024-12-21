# RelationalStore开发指导 (C/C++)


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

- 使用API11新增的端云同步等接口时，需要确保已实现云服务功能。


## 接口说明

详细的接口说明请参考[RDB](../reference/apis-arkdata/_r_d_b.md)。

| 接口名称 | 描述 |
| -------- | -------- |
| OH_Rdb_GetOrOpen(const OH_Rdb_Config *config, int *errCode) | 获得一个相关的OH_Rdb_Store实例，操作关系型数据库。 |
| OH_Rdb_Execute(OH_Rdb_Store *store, const char *sql) | 执行包含指定参数但不返回值的SQL语句。 |
| OH_Rdb_Insert(OH_Rdb_Store *store, const char *table, OH_VBucket *valuesBucket) | 向目标表中插入一行数据。 |
| OH_Rdb_Update(OH_Rdb_Store *store, OH_VBucket *valuesBucket, OH_Predicates *predicates) | 根据OH_Predicates的指定实例对象更新数据库中的数据。 |
| OH_Rdb_Delete(OH_Rdb_Store *store, OH_Predicates *predicates) | 根据OH_Predicates的指定实例对象从数据库中删除数据。 |
| OH_Rdb_Query(OH_Rdb_Store *store, OH_Predicates *predicates, const char *const *columnNames, int length) | 根据指定条件查询数据库中的数据。 |
| OH_Rdb_DeleteStore(const OH_Rdb_Config *config) | 删除数据库。 |
| OH_VBucket_PutAsset(OH_VBucket *bucket, const char *field, Rdb_Asset *value) | 把Rdb_Asset类型的数据放到指定的OH_VBucket对象中。 |
| OH_VBucket_PutAssets(OH_VBucket *bucket, const char *field, Rdb_Asset *value, uint32_t count) | 把Rdb_Asset数组类型的数据放到指定的OH_VBucket对象中。 |
| OH_Rdb_SetDistributedTables(OH_Rdb_Store *store, const char *tables[], uint32_t count, Rdb_DistributedType type, const Rdb_DistributedConfig *config) | 设置分布式数据库表。 |
| OH_Rdb_FindModifyTime(OH_Rdb_Store *store, const char *tableName, const char *columnName, OH_VObject *values) | 获取数据库指定表中指定列的数据的最后修改时间。 |
| OH_Rdb_CloudSync(OH_Rdb_Store *store, Rdb_SyncMode mode, const char *tables[], uint32_t count, const Rdb_ProgressObserver *observer) | 手动执行对指定表的端云同步，使用该接口需要实现云服务功能。 |
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
| int OH_Rdb_Subscribe(OH_Rdb_Store *store, Rdb_SubscribeType type, const Rdb_DataObserver *observer) | 为数据库注册观察者, 当分布式数据库中的数据发生更改时，将调用回调。 |
| int OH_Rdb_Unsubscribe(OH_Rdb_Store *store, Rdb_SubscribeType type, const Rdb_DataObserver *observer) | 从数据库中删除指定类型的指定观察者。 |
| int OH_Rdb_SubscribeAutoSyncProgress(OH_Rdb_Store *store, const Rdb_ProgressObserver *observer) | 订阅RDB存储的自动同步进程, 当收到自动同步进度的通知时，将调用回调。 |
| int OH_Rdb_UnsubscribeAutoSyncProgress(OH_Rdb_Store *store, const Rdb_ProgressObserver *observer) | 取消订阅RDB存储的自动同步进程。 |


## 开发步骤

**添加动态链接库**

CMakeLists.txt中添加以下lib。

```txt
libnative_rdb_ndk.z.so
```

**头文件**

```c++
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
   // 数据库文件存放的安全区域
   config.area = RDB_SECURITY_AREA_EL1;
   
   int errCode = 0;
   // 获取OH_Rdb_Store实例
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

5. 向数据库表中插入资产类型数据。

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

6. 从结果集中读取资产类型数据。

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

7. 查询数据的最后修改时间。调用OH_Rdb_FindModifyTime查询指定表中指定列的数据的最后修改时间，该接口返回一个有两列数据的OH_Cursor对象，第一列为传入的主键/RowId，第二列为最后修改时间。示例代码如下所示：

   ```c
   OH_VObject *values = OH_Rdb_CreateValueObject();
   int64_t keys[] = { 1 };
   values->putInt64(values, keys, 1);
   OH_Cursor *cursor;
   cursor = OH_Rdb_FindModifyTime(store_, "EMPLOYEE", "ROWID", values);
   ```

8. 创建分布式表。调用OH_Rdb_Execute接口创建表之后，可以将已创建的表设置成分布式表，并配置相关的分布式选项。使用该接口需要实现云服务功能。示例代码如下所示：

   ```c
   constexpr int TABLE_COUNT = 1;
   const char *table[TABLE_COUNT];
   table[0] = "EMPLOYEE";
   int errcode = OH_Rdb_SetDistributedTables(store_, table, TABLE_COUNT, Rdb_DistributedType::DISTRIBUTED_CLOUD, &config);
   ```

9. 对分布式表手动执行端云同步。调用OH_Rdb_SetDistributedTables创建分布式表之后，可以对该表进行手动端云同步。使用该接口需要实现云服务功能。示例代码如下所示：
   
    ```c
   // 定义回调函数
   void CloudSyncObserverCallback(void *context, Rdb_ProgressDetails *progressDetails)
   {
    // do something
   }
   const Rdb_ProgressObserver observer = { .context = nullptr, .callback = CloudSyncObserverCallback };
   OH_Rdb_CloudSync(store_, Rdb_SyncMode::SYNC_MODE_TIME_FIRST, table, TABLE_COUNT, &observer);
   ```

10. 将数据观察者注册到指定的存储对象(store)上，并订阅指定类型(type)的事件。在数据发生变化时，系统会调用相应的回调函数来处理进度观察。调用OH_Rdb_Subscribe接口订阅数据变化事件。使用该接口需要实现云服务功能。示例代码如下所示：
    
    ```c
    // 定义回调函数
    void RdbSubscribeBriefCallback(void *context, const char *values[], uint32_t count)
    {
    // do something
    }
    Rdb_BriefObserver briefObserver;
    const Rdb_BriefObserver briefObserver = { .context = nullptr, .callback = RdbSubscribeBriefCallback };
    // 订阅数据变化
    OH_Rdb_Subscribe(store_, Rdb_SubscribeType::RDB_SUBSCRIBE_TYPE_CLOUD, &briefObserver);
    ```

    调用OH_Rdb_Subscribe接口订阅本地数据库数据变更的事件。示例代码如下所示：

    ```c
    // 定义回调函数
    void LocalDataChangeObserverCallback1(void *context, const Rdb_ChangeInfo **changeInfo, uint32_t count)
    {
       for (uint32_t i = 0; i < count; i++) {
          EXPECT_EQ(DISTRIBUTED_CHANGE_INFO_VERSION, changeInfo[i]->version);
          // 表名为employee
          changeInfo[i]->tableName;
          changeInfo[i]->ChangeType;
          // 添加行数为1
          changeInfo[i]->inserted.count;
          // 修改行数为0
          changeInfo[i]->updated.count;
          // 删除行数为0
          changeInfo[i]->deleted.count;
       }
    }
    Rdb_DetailsObserver callback = LocalDataChangeObserverCallback1;
    Rdb_DataObserver observer = { nullptr, { callback } };
    // 订阅本地数据库数据变更的事件
    OH_Rdb_Subscribe(store_, Rdb_SubscribeType::RDB_SUBSCRIBE_TYPE_LOCAL_DETAILS, &observer);
 
    OH_VBucket* valueBucket = OH_Rdb_CreateValuesBucket();
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

11. 从指定的存储对象(store)中取消对指定类型(type)的事件的订阅。取消后，系统将不再调用相应的回调函数来处理进度观察。调用OH_Rdb_Unsubscribe接口取消订阅数据变化事件。使用该接口需要实现云服务功能。示例代码如下所示：
    
    ```c
    // 定义回调函数
    void RdbSubscribeBriefCallback(void *context, const char *values[], uint32_t count)
    {
    // do something
    }
    Rdb_BriefObserver briefObserver = RdbSubscribeBriefCallback;
    const Rdb_DataObserver briefObs = { .context = nullptr, .callback.briefObserver = briefObserver };
    // 取消订阅数据变化事件
    OH_Rdb_Unsubscribe(store_, Rdb_SubscribeType::RDB_SUBSCRIBE_TYPE_CLOUD, &briefObs);
    ```
    调用OH_Rdb_Unsubscribe接口取消订阅本地数据库数据变更的事件。示例代码如下所示：
    ```c
    // 定义回调函数
    void LocalDataChangeObserverCallback1(void *context, const Rdb_ChangeInfo **changeInfo, uint32_t count)
    {
    // do something
    }
    Rdb_DetailsObserver callback = LocalDataChangeObserverCallback1;
    Rdb_DataObserver observer = { nullptr, { callback } };
    // 取消订阅本地数据库数据变更的事件
    OH_Rdb_Unsubscribe(store_, Rdb_SubscribeType::RDB_SUBSCRIBE_TYPE_LOCAL_DETAILS, &observer);
    ```


12. 将进度观察者注册到指定的存储对象(store)上，以便订阅自动同步进度的事件。当存储对象进行自动同步时，系统会调用相应的回调函数处理进度观察。调用OH_Rdb_SubscribeAutoSyncProgress接口订阅自动同步进度事件。使用该接口需要实现云服务功能。示例代码如下所示：
    
    ```c
    // 定义回调函数
    void RdbProgressObserverCallback(void *context, Rdb_ProgressDetails *progressDetails)
    {
    // do something
    }
    const Rdb_ProgressObserver observer = { .context = nullptr, .callback = RdbProgressObserverCallback };
    OH_Rdb_SubscribeAutoSyncProgress(store_, &observer);
    ```

13. 从指定的存储对象(store)中取消订阅自动同步进度的事件。取消后，系统将不再调用相应的回调函数来处理进度观察。调用OH_Rdb_UnsubscribeAutoSyncProgress接口取消订阅自动同步进度事件。使用该接口需要实现云服务功能。示例代码如下所示：
    
    ```c
    // 定义回调函数
    void RdbProgressObserverCallback(void *context, Rdb_ProgressDetails *progressDetails)
    {
    // do something
    }
    const Rdb_ProgressObserver observer = { .context = nullptr, .callback = RdbProgressObserverCallback };
    OH_Rdb_UnsubscribeAutoSyncProgress(store_, &observer);
    ```

14. 删除数据库。调用OH_Rdb_DeleteStore方法，删除数据库及数据库相关文件。示例代码如下：
    
    ```c
    // 释放数据库实例
    OH_Rdb_CloseStore(store_);
    // 删除数据库文件
    OH_Rdb_DeleteStore(&config);
    ```

    



  
