# 数据共享扩展能力

**DataShareExtensionAbility**基于ExtensionAbility框架，提供支持数据共享业务的能力。

>**说明：** 
>
> 本模块首批接口从API version 9开始支持，后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口为系统接口。
>
> 本模块接口仅可在Stage模型下使用。


## 导入模块

```ts
import DataShareExtensionAbility from '@ohos.application.DataShareExtensionAbility'
```

## 属性

**系统能力**：SystemCapability.DistributedDataManager.DataShare.Provider

| 名称 | 类型 | 可读 | 可写 | 说明 | 
| -------- | -------- | -------- | -------- | -------- |
| context | [ExtensionContext](js-apis-inner-application-extensionContext.md)  | 是 | 否 |表示数据共享扩展能力上下文。 | 

## onCreate

onCreate?(want: Want, callback: AsyncCallback&lt;void&gt;): void

DataShare客户端连接DataShareExtensionAbility服务端时，服务端回调此接口，执行初始化业务逻辑操作。该方法可以选择性重写。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Provider

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ------ | ------ | ------ |
| want | [Want](js-apis-application-want.md#want) | 是  | Want类型信息，包括ability名称、bundle名称等。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。无返回值。 |

**示例：**

```ts
import rdb from '@ohos.data.rdb';

let DB_NAME = "DB00.db";
let TBL_NAME = "TBL00";
let DDL_TBL_CREATE = "CREATE TABLE IF NOT EXISTS "
    + TBL_NAME
    + " (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, age INTEGER, phoneNumber DOUBLE, isStudent BOOLEAN, Binary BINARY)";
let rdbStore;

export default class DataShareExtAbility extends DataShareExtensionAbility {
    onCreate(want, callback) {
        rdb.getRdbStore(this.context, {
            name: DB_NAME
        }, 1, function (err, data) {
            console.log('getRdbStore done, data : ' + data);
            rdbStore = data;
            rdbStore.executeSql(DDL_TBL_CREATE, [], function (err) {
                console.log('executeSql done, error message : ' + err);
            });
            if (callback) {
                callback();
            }
        });
    }
};
```

## insert

insert?(uri: string, valueBucket: ValuesBucket, callback: AsyncCallback&lt;number&gt;): void

在数据库插入时回调此接口，该方法可以选择性重写。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Provider

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ------ | ------ | ------ |
| uri |string | 是  | 指示要插入的数据的路径。 |
| valueBucket |[ValuesBucket](js-apis-data-valuesBucket.md#valuesbucket) | 是 | 指示要插入的数据。 |
| callback |AsyncCallback&lt;number&gt; | 是 | 回调函数。返回插入数据记录的索引。 |

**示例：**

```ts
import rdb from '@ohos.data.rdb';

let DB_NAME = "DB00.db";
let TBL_NAME = "TBL00";
let DDL_TBL_CREATE = "CREATE TABLE IF NOT EXISTS "
    + TBL_NAME
    + " (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, age INTEGER, phoneNumber DOUBLE, isStudent BOOLEAN, Binary BINARY)";
let rdbStore;

export default class DataShareExtAbility extends DataShareExtensionAbility {
    insert(uri, valueBucket, callback) {
        if (valueBucket == null) {
            console.info('invalid valueBuckets');
            return;
        }
        rdbStore.insert(TBL_NAME, valueBucket, function (err, ret) {
            console.info('callback ret:' + ret);
            if (callback != undefined) {
                callback(err, ret);
            }
        });
    }
};
```

## update

update?(uri: string, predicates: dataSharePredicates.DataSharePredicates, valueBucket: ValuesBucket, callback: AsyncCallback&lt;number&gt;): void

在数据库更新时服务端回调此接口，该方法可以选择性重写。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Provider

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ------ | ------ | ------ |
| uri | string | 是  | 指示要更新的数据的路径。 |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | 是  | 指示筛选条件。 |
| valueBucket | [ValuesBucket](js-apis-data-valuesBucket.md#valuesbucket) | 是 | 指示要更新的数据。 |
| callback | AsyncCallback&lt;number&gt; | 是 | 回调函数。返回更新的数据记录数。 |

**示例：**

```ts
import rdb from '@ohos.data.rdb';

let DB_NAME = "DB00.db";
let TBL_NAME = "TBL00";
let DDL_TBL_CREATE = "CREATE TABLE IF NOT EXISTS "
    + TBL_NAME
    + " (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, age INTEGER, phoneNumber DOUBLE, isStudent BOOLEAN, Binary BINARY)";
let rdbStore;

export default class DataShareExtAbility extends DataShareExtensionAbility {
    update(uri, predicates, valueBucket, callback) {
        if (predicates == null || predicates == undefined) {
            return;
        }
        rdbStore.update(TBL_NAME, valueBucket, predicates, function (err, ret) {
            if (callback != undefined) {
                callback(err, ret);
            }
        });
    }
};
```

## delete

delete?(uri: string, predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback&lt;number&gt;): void

在删除数据库记录时服务端回调此接口，该方法可以选择性重写。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Provider

**参数：**

| 参数名       | 类型                                                     | 必填 | 说明                               |
| ---------- | ------------------------------------------------------------ | ---- | ---------------------------------- |
| uri        | string                                                       | 是   | 指示要删除的数据的路径。           |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | 是   | 指示筛选条件。                     |
| callback   | AsyncCallback&lt;number&gt;                                  | 是   | 回调函数。返回已删除的数据记录数。 |

**示例：**

```ts
import rdb from '@ohos.data.rdb';

let DB_NAME = "DB00.db";
let TBL_NAME = "TBL00";
let DDL_TBL_CREATE = "CREATE TABLE IF NOT EXISTS "
    + TBL_NAME
    + " (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, age INTEGER, phoneNumber DOUBLE, isStudent BOOLEAN, Binary BINARY)";
let rdbStore;

export default class DataShareExtAbility extends DataShareExtensionAbility {
    delete(uri, predicates, callback) {
        if (predicates == null || predicates == undefined) {
            return;
        }
        rdbStore.delete(TBL_NAME, predicates, function (err, ret) {
            if (callback != undefined) {
                callback(err, ret);
            }
        });
    }
};
```

## query

query?(uri: string, predicates: dataSharePredicates.DataSharePredicates, columns: Array&lt;string&gt;, callback: AsyncCallback&lt;Object&gt;): void

在查询数据库时服务端回调此接口，该方法可以选择性重写。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Provider

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ------ | ------ | ------ |
| uri | string | 是  | 指示要查询的数据的路径。 |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | 是  | 指示筛选条件。 |
| columns | Array&lt;string&gt; | 是 | 指示要查询的列。如果此参数为空，则查询所有列。 |
| callback | AsyncCallback&lt;Object&gt; | 是 | 回调函数。返回查询到的结果集。 |

**示例：**

```ts
import rdb from '@ohos.data.rdb';

let DB_NAME = "DB00.db";
let TBL_NAME = "TBL00";
let DDL_TBL_CREATE = "CREATE TABLE IF NOT EXISTS "
    + TBL_NAME
    + " (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, age INTEGER, phoneNumber DOUBLE, isStudent BOOLEAN, Binary BINARY)";
let rdbStore;

export default class DataShareExtAbility extends DataShareExtensionAbility {
    query(uri, predicates, columns, callback) {
        if (predicates == null || predicates == undefined) {
            return;
        }
        rdbStore.query(TBL_NAME, predicates, columns, function (err, resultSet) {
            if (resultSet != undefined) {
                console.info('resultSet.rowCount: ' + resultSet.rowCount);
            }
            if (callback != undefined) {
                callback(err, resultSet);
            }
        });
    }
};
```

## batchInsert

batchInsert?(uri: string, valueBuckets: Array&lt;ValuesBucket&gt;, callback: AsyncCallback&lt;number&gt;): void

在数据库批量插入时服务端回调此接口，该方法可以选择性重写。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Provider

**参数：**

| 参数名        | 类型                                                     | 必填 | 说明                             |
| ------------ | ------------------------------------------------------------ | ---- | -------------------------------- |
| uri          | string                                                       | 是   | 指示要批量插入的数据的路径。     |
| valueBuckets | Array&lt;[ValuesBucket](js-apis-data-valuesBucket.md#valuesbucket)&gt; | 是   | 指示要批量插入的数据。           |
| callback     | AsyncCallback&lt;number&gt;                                  | 是   | 回调函数。返回插入的数据记录数。 |

**示例：**

```ts
import rdb from '@ohos.data.rdb';

let DB_NAME = "DB00.db";
let TBL_NAME = "TBL00";
let DDL_TBL_CREATE = "CREATE TABLE IF NOT EXISTS "
    + TBL_NAME
    + " (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, age INTEGER, phoneNumber DOUBLE, isStudent BOOLEAN, Binary BINARY)";
let rdbStore;

export default class DataShareExtAbility extends DataShareExtensionAbility {
    batchInsert(uri, valueBuckets, callback) {
        if (valueBuckets == null || valueBuckets.length == undefined) {
            console.info('invalid valueBuckets');
            return;
        }
        let resultNum = valueBuckets.length
        valueBuckets.forEach(vb => {
            rdbStore.insert(TBL_NAME, vb, function (err, ret) {
                if (callback != undefined) {
                    callback(err, resultNum);
                }
            });
        });
    }
};
```

## normalizeUri

normalizeUri?(uri: string, callback: AsyncCallback&lt;string&gt;): void

用户给定的URI转换为服务端使用的URI时回调此接口，该方法可以选择性重写。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Provider

**参数：**

| 参数名     | 类型                  | 必填 | 说明                    |
| -------- | --------------------- | ---- | ----------------------- |
| uri      | string                | 是   | 指示用户传入的[URI](js-apis-uri.md#uri)。 |
| callback | AsyncCallback&lt;string&gt; | 是   | 回调函数。如果支持URI规范化，则返回规范化URI，否则返回空。 |

**示例：**

```ts
export default class DataShareExtAbility extends DataShareExtensionAbility {
    normalizeUri(uri, callback) {
        let err = {"code":0};
        let ret = "normalize+" + uri;
        callback(err, ret);
    }
};
```

## denormalizeUri

denormalizeUri?(uri: string, callback: AsyncCallback&lt;string&gt;): void

服务端使用的URI转换为用户传入的初始URI时服务端回调此接口，该方法可以选择性重写。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Provider

**参数：**

| 参数名     | 类型                  | 必填 | 说明                    |
| -------- | --------------------- | ---- | ----------------------- |
| uri      | string                | 是   | 指示服务端使用的[URI](js-apis-uri.md#uri)。 |
| callback | AsyncCallback&lt;string&gt; | 是   | 回调函数。如果反规范化成功，则返回反规范化的URI；如果无需进行反规范化，则返回原始URI；若不支持则返回空。 |

**示例：**

```ts
export default class DataShareExtAbility extends DataShareExtensionAbility {
    denormalizeUri(uri, callback) {
        let err = {"code":0};
        let ret = "denormalize+" + uri;
        callback(err, ret);
    }
};
```
