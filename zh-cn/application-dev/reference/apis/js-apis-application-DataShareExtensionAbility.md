# DataShareExtensionAbility

**DataShareExtensionAbility**基于ExtensionAbility框架，提供支持数据共享业务的能力。

>**说明：** 
>
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。仅限系统应用。
>以下接口全部为系统接口，三方应用不支持调用。


## 导入模块

```ts
import DataShareExtensionAbility from '@ohos.application.DataShareExtensionAbility'
```

## onCreate

onCreate?(want: Want, callback: AsyncCallback&lt;void&gt;): void

DataShare客户端连接DataShareExtensionAbility服务端时，服务端回调此接口，执行初始化业务逻辑操作。该方法可以选择性重写。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Provider

**参数：**

| 参数名 | 参数类型 | 必填 | 说明 |
| ----- | ------ | ------ | ------ |
| want | [Want](js-apis-application-Want.md#want) | 是  | Want类型信息，包括ability名称、bundle名称等。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 表示被指定的回调方法。 |

**示例：**

```ts
import rdb from '@ohos.data.rdb';

let DB_NAME = "DB00.db";
let TBL_NAME = "TBL00";
let DDL_TBL_CREATE = "CREATE TABLE IF NOT EXISTS "
+ TBL_NAME
+ " (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, age INTEGER, phoneNumber DOUBLE, isStudent BOOLEAN, Binary BINARY)";

onCreate(want, callback) {
    console.log('DataShareExtAbility onCreate, want:' + want.abilityName);
    console.log('DataShareExtAbility onCreate, this.context:' + this.context);
    rdb.getRdbStore(this.context, {
        name: DB_NAME
    }, 1, function (err, data) {
        console.log('getRdbStore fail, error message : ' + err);
        console.log('getRdbStore done, data : ' + data);
        let rdbStore = data;
        rdbStore.executeSql(DDL_TBL_CREATE, [], function (err) {
            console.log('executeSql fail, error message : ' + err);
        });
    });
    callback();
}
```

## insert

insert?(uri: string, valueBucket: ValuesBucket, callback: AsyncCallback&lt;number&gt;): void

在数据库插入时回调此接口，该方法可以选择性重写。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Provider。

**参数：**

| 参数名 | 参数类型 | 必填 | 说明 |
| ----- | ------ | ------ | ------ |
| uri |string | 是  | 指示要插入的数据的路径。 |
| valueBucket |[ValuesBucket](js-apis-data-ValuesBucket.md#valuesbucket) | 是 | 指示要插入的数据记录。 |
| callback |AsyncCallback&lt;number&gt; | 是 | 表示被指定的回调方法。 |

**示例：**

```ts
import rdb from '@ohos.data.rdb';
let TBL_NAME = "TBL00";
let rdbStore;

insert(uri, value, callback) {
    if (value == null) {
        console.info('invalid valueBuckets');
        return;
    }
    rdbStore.insert(TBL_NAME, value, function (err, ret) {
        console.info('callback ret:' + ret);
        if (callback != undefined) {
            callback(err, ret);
        }
    });
}
```

## update

update?(uri: string, predicates: DataSharePredicates, valueBucket: ValuesBucket, callback: AsyncCallback&lt;number&gt;): void

在数据库更新时服务端回调此接口，该方法可以选择性重写。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Provider。

**参数：**

| 参数名 | 参数类型 | 必填 | 说明 |
| ----- | ------ | ------ | ------ |
| uri | string | 是  | 指示要更新的数据的路径。 |
| predicates | [DataSharePredicates](js-apis-data-DataSharePredicates.md#datasharepredicates) | 是  | 指示筛选条件。 |
| valueBucket | [ValuesBucket](js-apis-data-ValuesBucket.md#valuesbucket) | 是 | 指示要更新的数据。 |
| callback | AsyncCallback&lt;number&gt; | 是 | 表示被指定的回调方法。 |

**示例：**

```ts
import rdb from '@ohos.data.rdb';
let TBL_NAME = "TBL00";
let rdbStore;

update(uri, predicates, value, callback) {
    if (predicates == null || predicates == undefined) {
        return;
    }
    rdbStore.update(TBL_NAME, value, predicates, function (err, ret) {
        if (callback != undefined) {
            callback(err, ret);
        }
    });
}
```

## query

query?(uri: string, predicates: DataSharePredicates, columns: Array&lt;string&gt;, callback: AsyncCallback&lt;Object&gt;): void

在查询数据库时服务端回调此接口。

此接口为可选的。可以被重写，也可以不进行重写。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Provider。

**参数：**

| 名称 | 参数类型 | 必填 | 说明 |
| ----- | ------ | ------ | ------ |
| uri | string | 是  | 指示要查询的数据的路径。 |
| predicates | [DataSharePredicates](js-apis-data-DataSharePredicates.md#datasharepredicates) | 是  | 指示筛选条件。 |
| columns | Array&lt;string&gt; | 是 | 指示要查询的列。如果此参数为空，则查询所有列。 |
| callback | AsyncCallback&lt;Object&gt; | 是 | 表示被指定的回调方法。 |

**示例：**

```ts
import rdb from '@ohos.data.rdb';
let TBL_NAME = "TBL00";
let rdbStore;

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
```

## delete

delete?(uri: string, predicates: DataSharePredicates, callback: AsyncCallback&lt;number&gt;): void

在删除数据库记录时服务端回调此接口。

此接口为可选的。可以被重写，也可以不进行重写。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Provider。

**参数：**

| 名称       | 参数类型                                                     | 必填 | 说明                     |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------ |
| uri        | string                                                       | 是   | 指示要删除的数据的路径。 |
| predicates | [DataSharePredicates](js-apis-data-DataSharePredicates.md#datasharepredicates) | 是   | 指示筛选条件。           |
| callback   | AsyncCallback&lt;number&gt;                                        | 是   | 表示被指定的回调方法。   |

**示例：**

```ts
import rdb from '@ohos.data.rdb';
let TBL_NAME = "TBL00";
let rdbStore;

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
```

## BatchInsert

BatchInsert?(uri: string, valueBuckets: Array&lt;ValuesBucket&gt;, callback: AsyncCallback&lt;number&gt;): void

在数据库批量插入时服务端回调此接口。

此接口为可选的。可以被重写，也可以不进行重写。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Provider。

**参数：**

| 名称         | 参数类型                                                     | 必填 | 说明                     |
| ------------ | ------------------------------------------------------------ | ---- | ------------------------ |
| uri          | string                                                       | 是   | 指示要插入的数据的路径。 |
| valueBuckets | Array&lt;[ValuesBucket](js-apis-data-ValuesBucket.md#valuesbucket)&gt; | 是   | 指示要批量插入的数据记录。   |
| callback     | AsyncCallback&lt;number&gt;                                        | 是   | 表示被指定的回调方法。   |

**示例：**

```ts
import rdb from '@ohos.data.rdb';
let TBL_NAME = "TBL00";
let rdbStore;

batchInsert(uri: string, valueBuckets, callback) {
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
```

## getType

getType?(uri: string, callback: AsyncCallback&lt;string&gt;): void

获取给定uri对应的MIME类型时服务端回调此接口。

此接口为可选的。可以被重写，也可以不进行重写。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Provider。

**参数：**

| 参数名 | 参数类型 | 必填 | 说明 |
| ----- | ------ | ------ | ------ |
| uri | string | 是  | 指示要获取MIME类型的数据的路径。 |
| callback | AsyncCallback&lt;string&gt; | 是 | 表示被指定的回调方法。 |

**示例：**

```ts
getType(uri: string, callback) {
    let err;
    let ret = "image";
    callback(err, ret);
}
```

## getFileTypes

getFileTypes?(uri: string, mimeTypeFilter: string, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

获取支持文件的MIME类型时服务端回调此接口。

此接口为可选的。可以被重写，也可以不进行重写。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Provider。

**参数：**

| 名称           | 类型                         | 必填 | 描述                         |
| -------------- | ---------------------------- | ---- | ---------------------------- |
| uri            | string                       | 是   | 指示要获取的文件的路径。     |
| mimeTypeFilter | string                       | 是   | 指示要获取的文件的MIME类型。 |
| callback       | AsyncCallback&lt;Array&lt;string&gt;&gt; | 是   | 表示被指定的回调方法。       |

**示例：**

```ts
getFileTypes(uri: string, mimeTypeFilter: string,callback) {
    let err;
    let ret = new Array("type01", "type02", "type03");
    callback(err, ret);
}
```

## normalizeUri

normalizeUri?(uri: string, callback: AsyncCallback&lt;string&gt;): void

用户给定Uri转换为服务端使用的Uri时进行回调服务端回调此接口。

此接口为可选的。可以被重写，也可以不进行重写。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Provider。

**参数：**

| 名称     | 类型                  | 必填 | 描述                    |
| -------- | --------------------- | ---- | ----------------------- |
| uri      | string                | 是   | 指示用户传入的uri。 |
| callback | AsyncCallback&lt;string&gt; | 是   | 表示被指定的回调方法。  |

**示例：**

```ts
normalizeUri(uri: string, callback) {
    let err;
    let ret = "normalize+" + uri;
    callback(err, ret);
}
```

## denormalizeUri

denormalizeUri?(uri: string, callback: AsyncCallback&lt;string&gt;): void

服务端使用的Uri转换为用户传入的初始Uri时服务端回调此接口。

此接口为可选的。可以被重写，也可以不进行重写。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Provider。

**参数：**

| 名称     | 类型                  | 必填 | 描述                    |
| -------- | --------------------- | ---- | ----------------------- |
| uri      | string                | 是   | 指示服务端使用的uri。 |
| callback | AsyncCallback&lt;string&gt; | 是   | 表示被指定的回调方法。  |

**示例：**

```ts
denormalizeUri(uri: string, callback) {
    let err;
	let ret = "denormalize+" + uri;
	callback(err, ret);
}
```

## openFile

openFile?(uri: string, mode: string, callback: AsyncCallback&lt;number&gt;): void

在打开文件时服务端回调此接口。

此接口为可选的。可以被重写，也可以不进行重写。


**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Provider。

**参数：**

| 名称     | 类型                  | 必填 | 描述                                       |
| -------- | --------------------- | ---- | ------------------------------------------ |
| uri      | string                | 是   | 指示要规范化的uri对象。                    |
| mode     | string                | 是   | 指示文件打开模式，包括只读模式，读写模式。 |
| callback | AsyncCallback&lt;number&gt; | 是   | 表示被指定的回调方法。                     |

**示例：**

```ts
openFile(uri: string, mode, callback) {
    let err;
    let fd = 0;
    callback(err,fd);
}
```
