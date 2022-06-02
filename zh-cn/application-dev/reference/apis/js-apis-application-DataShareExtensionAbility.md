# DataShareExtensionAbility

**DataShareExtensionAbility** 是基于元能力提供的ExtensionAbility框架，提供支持数据共享业务的能力。

>**说明：** 
>
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。仅限系统应用。


## 导入模块

```ts
import DataShareExtensionAbility from '@ohos.application.DataShareExtensionAbility'
```

## onCreate

onCreate?(want: Want, callback: AsyncCallback<void>): void;

DataShareExtAbility生命周期回调，在创建时回调，执行初始化业务逻辑操作。

此接口为可选的。可以被重写，也可以不进行重写。

此接口为系统接口，三方应用不支持调用。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Provider。

**参数：**

| 参数名 | 参数类型 | 必填 | 说明 |
| ----- | ------ | ------ | ------ |
| want | [Want](js-apis-application-Want.md#want) | 是  | Want类型信息，包括ability名称、bundle名称等。 |
| callback | AsyncCallback<void> | 是 | 表示被指定的回调方法。 |

**示例：**

```ts
import rdb from '@ohos.data.rdb';

let DB_NAME = "DB00.db";
let TBL_NAME = "TBL00";
let DDL_TBL_CREATE = "CREATE TABLE IF NOT EXISTS "
+ TBL_NAME
+ " (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, age INTEGER, phoneNumber DOUBLE, isStudent BOOLEAN, Binary BINARY)";

// All of the input parameters are passed from the native side
onCreate(want, callback) {
	// Specific functions need to be implemented by the user
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

insert?(uri: string, valueBucket: ValuesBucket, callback: AsyncCallback<number>): void;

insert生命周期回调，在数据库插入时回调。

此接口为可选的。可以被重写，也可以不进行重写。

此接口为系统接口，三方应用不支持调用。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Provider。

**参数：**

| 参数名 | 参数类型 | 必填 | 说明 |
| ----- | ------ | ------ | ------ |
| uri |string | 是  | 指示要插入的数据的路径。 |
| valueBucket |[ValuesBucket](js-apis-data-ValuesBucket.md#valuesbucket) | 是 | 指示要插入的数据记录。 |
| callback |AsyncCallback<number> | 是 | 表示被指定的回调方法。 |

**示例：**

```ts
import rdb from '@ohos.data.rdb';
let TBL_NAME = "TBL00";
// Refer to the onCreate for the method of obtaining rdbStore
let rdbStore;

// All of the input parameters are passed from the native side
insert(uri, value, callback) {
    // Specific functions need to be implemented by the user
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

update?(uri: string, predicates: DataSharePredicates, valueBucket: ValuesBucket, callback: AsyncCallback<number>): void;

update生命周期回调，在数据库更新时回调。

此接口为可选的。可以被重写，也可以不进行重写。

此接口为系统接口，三方应用不支持调用。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Provider。

**参数：**

| 参数名 | 参数类型 | 必填 | 说明 |
| ----- | ------ | ------ | ------ |
| uri | string | 是  | 指示要更新的数据的路径。 |
| predicates | [DataSharePredicates](js-apis-data-DataSharePredicates.md#datasharepredicates) | 是  | 指示筛选条件。 |
| valueBucket | [ValuesBucket](js-apis-data-ValuesBucket.md#valuesbucket) | 是 | 指示要更新的数据。 |
| callback | AsyncCallback<number> | 是 | 表示被指定的回调方法。 |

**示例：**

```ts
import rdb from '@ohos.data.rdb';
let TBL_NAME = "TBL00";
// Refer to the onCreate for the method of obtaining rdbStore
let rdbStore;

// All of the input parameters are passed from the native side
update(uri, predicates, value, callback) {
    // Specific functions need to be implemented by the user
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

query?(uri: string, predicates: DataSharePredicates, columns: Array<string>, callback: AsyncCallback<Object>): void;

query生命周期回调，在数据库查询时回调。

此接口为可选的。可以被重写，也可以不进行重写。

此接口为系统接口，三方应用不支持调用。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Provider。

**参数：**

| 名称 | 参数类型 | 必填 | 说明 |
| ----- | ------ | ------ | ------ |
| uri | string | 是  | 指示要查询的数据的路径。 |
| predicates | [DataSharePredicates](js-apis-data-DataSharePredicates.md#datasharepredicates) | 是  | 指示筛选条件。 |
| columns | Array<string> | 是 | 指示要查询的列。如果此参数为空，则查询所有列。 |
| callback | AsyncCallback<Object> | 是 | 表示被指定的回调方法。 |

**示例：**

```ts
import rdb from '@ohos.data.rdb';
let TBL_NAME = "TBL00";
// Refer to the onCreate for the method of obtaining rdbStore
let rdbStore;

// All of the input parameters are passed from the native side
query(uri, predicates, columns, callback) {
    // Specific functions need to be implemented by the user
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

delete?(uri: string, predicates: DataSharePredicates, callback: AsyncCallback<number>): void;

delete生命周期回调，在删除数据库记录时回调。

此接口为可选的。可以被重写，也可以不进行重写。

此接口为系统接口，三方应用不支持调用。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Provider。

**参数：**

| 名称       | 参数类型                                                     | 必填 | 说明                     |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------ |
| uri        | string                                                       | 是   | 指示要查询的数据的路径。 |
| predicates | [DataSharePredicates](js-apis-data-DataSharePredicates.md#datasharepredicates) | 是   | 指示筛选条件。           |
| callback   | AsyncCallback<number>                                        | 是   | 表示被指定的回调方法。   |

**示例：**

```ts
import rdb from '@ohos.data.rdb';
let TBL_NAME = "TBL00";
// Refer to the onCreate for the method of obtaining rdbStore
let rdbStore;

// All of the input parameters are passed from the native side
delete(uri, predicates, callback) {
    // Specific functions need to be implemented by the user
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

## batchInsert

batchInsert?(uri: string, valueBuckets: Array<ValuesBucket>, callback: AsyncCallback<number>): void;

batchinsert生命周期回调，在数据库批量插入时回调。

此接口为可选的。可以被重写，也可以不进行重写。

此接口为系统接口，三方应用不支持调用。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Provider。

**参数：**

| 名称         | 参数类型                                                     | 必填 | 说明                     |
| ------------ | ------------------------------------------------------------ | ---- | ------------------------ |
| uri          | string                                                       | 是   | 指示要插入的数据的路径。 |
| valueBuckets | Array<[ValuesBucket](js-apis-data-ValuesBucket.md#valuesbucket)> | 是   | 指示要插入的数据记录。   |
| callback     | AsyncCallback<number>                                        | 是   | 表示被指定的回调方法。   |

**示例：**

```ts
import rdb from '@ohos.data.rdb';
let TBL_NAME = "TBL00";
// Refer to the onCreate for the method of obtaining rdbStore
let rdbStore;

// All of the input parameters are passed from the native side
batchInsert(uri: string, valueBuckets, callback) {
    // Specific functions need to be implemented by the user
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

getType?(uri: string, callback: AsyncCallback<string>): void;

getType生命周期回调函数，获取给定URI对应的MIME类型时回调。

此接口为可选的。可以被重写，也可以不进行重写。

此接口为系统接口，三方应用不支持调用。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Provider。

**参数：**

| 参数名 | 参数类型 | 必填 | 说明 |
| ----- | ------ | ------ | ------ |
| uri | string | 是  | 指示要操作的数据的路径。 |
| callback | AsyncCallback<string> | 是 | 表示被指定的回调方法。 |

**示例：**

```ts
// All of the input parameters are passed from the native side
getType(uri: string, callback) {
    // Specific functions need to be implemented by the user
    let err;
    let ret = "image";
    callback(err, ret);
}
```

## getFileTypes

getFileTypes?(uri: string, mimeTypeFilter: string, callback: AsyncCallback<Array<string>>): void;

getFileTypes生命周期回调，获取支持文件的MIME类型时回调。

此接口为可选的。可以被重写，也可以不进行重写。

此接口为系统接口，三方应用不支持调用。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Provider。

**参数：**

| 名称           | 类型                         | 必填 | 描述                         |
| -------------- | ---------------------------- | ---- | ---------------------------- |
| uri            | string                       | 是   | 指示要获取的文件的路径。     |
| mimeTypeFilter | string                       | 是   | 指示要获取的文件的MIME类型。 |
| callback       | AsyncCallback<Array<string>> | 是   | 表示被指定的回调方法。       |

**示例：**

```ts
// All of the input parameters are passed from the native side
getFileTypes(uri: string, mimeTypeFilter: string,callback) {
    // Specific functions need to be implemented by the user
    let err;
    let ret = new Array("type01", "type02", "type03");
    callback(err, ret);
}
```

## normalizeUri

normalizeUri?(uri: string, callback: AsyncCallback<string>): void;

normalizeUri生命周期回调，给定uri转换为规范化uri时回调。

此接口为可选的。可以被重写，也可以不进行重写。

此接口为系统接口，三方应用不支持调用。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Provider。

**参数：**

| 名称     | 类型                  | 必填 | 描述                    |
| -------- | --------------------- | ---- | ----------------------- |
| uri      | string                | 是   | 指示要规范化的uri对象。 |
| callback | AsyncCallback<string> | 是   | 表示被指定的回调方法。  |

**示例：**

```ts
// All of the input parameters are passed from the native side
normalizeUri(uri: string, callback) {
    // Specific functions need to be implemented by the user
    let err;
    let ret = "normalize+" + uri;
    callback(err, ret);
}
```

## denormalizeUri

denormalizeUri?(uri: string, callback: AsyncCallback<string>): void;

将由denormalizeUri生命周期回调，给定规范化uri转换为非规范化uri时回调。

此接口为可选的。可以被重写，也可以不进行重写。

此接口为系统接口，三方应用不支持调用。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Provider。

**参数：**

| 名称     | 类型                  | 必填 | 描述                    |
| -------- | --------------------- | ---- | ----------------------- |
| uri      | string                | 是   | 指示要规范化的uri对象。 |
| callback | AsyncCallback<string> | 是   | 表示被指定的回调方法。  |

**示例：**

```ts
// All of the input parameters are passed from the native side
denormalizeUri(uri: string, callback) {
	// Specific functions need to be implemented by the user
    let err;
	let ret = "denormalize+" + uri;
	callback(err, ret);
}
```

## openFile

openFile?(uri: string, mode: string, callback: AsyncCallback<number>): void;

将由openFile生命周期回调，在打开文件时回调。

此接口为可选的。可以被重写，也可以不进行重写。

此接口为系统接口，三方应用不支持调用。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Provider。

**参数：**

| 名称     | 类型                  | 必填 | 描述                                       |
| -------- | --------------------- | ---- | ------------------------------------------ |
| uri      | string                | 是   | 指示要规范化的uri对象。                    |
| mode     | string                | 是   | 指示文件打开模式，包括只读模式，读写模式。 |
| callback | AsyncCallback<number> | 是   | 表示被指定的回调方法。                     |

**示例：**

```ts
// All of the input parameters are passed from the native side
openFile(uri: string, mode, callback) {
    // Specific functions need to be implemented by the user
    let err;
    let fd = 0;
    callback(err,fd);
}
```
