# DataShareExtensionAbility

**DataShareExtensionAbility** 作为一种扩展能力提供基础生命周期管理，支持基于场景（比如卡片、Workscheduler）的Ability的生命周期管理，提供相应的回调接口（启动、接口调用、连接、断开连接、销毁等）

>**说明：** 
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```js
import Extension from '@ohos.application.DataShareExtensionAbility'
```

## onCreate

onCreate?(want: Want, callback: AsyncCallback<void>): void;

DataShareExtAbility生命周期回调，在创建时回调，执行初始化业务逻辑操作

**系统能力**：以下各项对应的系统能力均为SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| 参数名 | 参数类型 | 必填 | 说明 |
| ----- | ------ | ------ | ------ |
| want | Want | 是  | Want类型信息，包括ability名称、bundle名称等。 |

**返回值**： 无

**示例：**

```js
import rdb from '@ohos.data.rdb';

onCreate(want) {
    console.log('DataShareExtAbility onCreate, want:' + want.abilityName);
    console.log('this.context:' + this.context);
    rdb.getRdbStore(this.context, {name: DB_NAME}, 1, function (err, data) {
        console.log('DataShareExtAbility onCreate, getRdbStore done err:' + JSON.stringify(err));
        console.log('DataShareExtAbility onCreate, getRdbStore done data:' + JSON.stringify(data));
        rdbStore = data;
        rdbStore.executeSql(DDL_TBL_CREATE, [], function (err) {
            console.log('DataShareExtAbility onCreate, executeSql done err:' + JSON.stringify(err));
        });
    });
}
```

## insert

insert?(uri: string, valueBucket: ValuesBucket, callback: AsyncCallback<number>): void;

insert生命周期回调，在数据库插入时回调

**参数：**

| 参数名 | 参数类型 | 必填 | 说明 |
| ----- | ------ | ------ | ------ |
| uri |string | 是  | 指示要插入的数据的路径 |
| valuesBucket |ValuesBucket | 是 | 指示要插入的数据记录 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回插入数据记录的索引 |

**示例：**

```js
import rdb from '@ohos.data.rdb';
let TBL_NAME = "TBL00";

insert(uri, value, callback) {
	if (value == null) {
		console.info('invalid valueBuckets');
		return;
	}
	await rdbStore.insert(TBL_NAME, value, function (err, ret) {
		console.info('callback ret:' + ret);
		if (callback != undefined) {
			callback(err, ret);
		}
    });
}
```

### update

update?(uri: string, predicates: DataSharePredicates, valueBucket: ValuesBucket,callback: AsyncCallback<number>): void;

update生命周期回调，在数据库更新时回调

| 参数名 | 参数类型 | 必填 | 说明 |
| ----- | ------ | ------ | ------ |
| uri | string | 是  | 指示要更新的数据的路径 |
| predicates | DataSharePredicates | 是  | 指示要更新的数据 |
| valueBucket | ValuesBucket | 是 | 指示筛选条件 |

**返回值：**

| 类型   | 说明                 |
| ------ | -------------------- |
| number | 返回更新的数据记录数 |

**示例：**

```js
import rdb from '@ohos.data.rdb';
let TBL_NAME = "TBL00";

update(uri, predicates, value, callback) {
	if (predicates == null || predicates == undefined) {
		return;
	}
	rdbStore.update(TBL_NAME,value, predicates, function (err, ret) {
		if (callback != undefined) {
			callback(err, ret);
		}
	});
}
```

### query

query?(uri: string, predicates: DataSharePredicates, columns: Array<string>,callback: AsyncCallback<Object>): void;

query生命周期回调，在数据库查询时回调

| 名称 | 参数类型 | 必填 | 说明 |
| ----- | ------ | ------ | ------ |
| uri | string | 是  | 指示要查询的数据的路径 |
| predicates | DataSharePredicates | 是  | 指示筛选条件 |
| columns | Array<string> | 是 | 指示要查询的列。如果此参数为空，则查询所有列 |

**返回值：**

| 类型      | 说明           |
| --------- | -------------- |
| ResultSet | 返回查询结果集 |

**示例：**

```js
import rdb from '@ohos.data.rdb';
let TBL_NAME = "TBL00";

query(uri, predicates, columns,  callback) {
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

### delete

delete?(uri: string, predicates: DataSharePredicates, callback: AsyncCallback<number>): void;

delete生命周期回调，在删除数据库记录时回调

| 名称       | 参数类型            | 必填 | 说明                   |
| ---------- | ------------------- | ---- | ---------------------- |
| uri        | string              | 是   | 指示要查询的数据的路径 |
| predicates | DataSharePredicates | 是   | 指示筛选条件           |

**返回值：**

| 类型   | 说明                   |
| ------ | ---------------------- |
| number | 返回已删除的数据记录数 |

**示例：**

```js
import rdb from '@ohos.data.rdb';
let TBL_NAME = "TBL00";

delete(uri, predicates, callback) {
	if (predicates == null || predicates == undefined) {
		return;
	}
	rdbStore.delete(TBL_NAME,predicates, function (err, ret) {
		if (callback != undefined) {
			callback(err, ret);
		}
	});
}
```

### batchInsert

batchInsert?(uri: string, valueBuckets: Array<ValuesBucket>, callback: AsyncCallback<number>): void;

insert生命周期回调，在数据库插入时回调

| 名称         | 参数类型            | 必填 | 说明                   |
| ------------ | ------------------- | ---- | ---------------------- |
| uri          | string              | 是   | 指示要插入的数据的路径 |
| valueBuckets | Array<ValuesBucket> | 是   | 指示要插入的数据记录   |

**返回值：**

| 类型   | 说明                 |
| ------ | -------------------- |
| number | 返回插入的数据记录数 |

**示例：**

```js
import rdb from '@ohos.data.rdb';
let TBL_NAME = "TBL00";

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

### getType

getType?(uri: string, callback: AsyncCallback<string>): void;

getType生命周期回调函数，获取给定URI对应的MIME类型时回调

**参数：**

| 参数名 | 参数类型 | 必填 | 说明 |
| ----- | ------ | ------ | ------ |
| uri | string | 是  | 指示要操作的数据的路径 |

**返回值：**

| 类型   | 说明                                |
| ------ | ----------------------------------- |
| string | 返回与uri指定的数据匹配的MIME类型。 |

**示例：**

```js
getType(uri: string,callback) {
	// Specific functions need to be implemented by the user
	let ret = "image";
	callback(err,ret);
}
```

### getFileTypes

getFileTypes?(uri: string, mimeTypeFilter: string, callback: AsyncCallback<Array<string>>): void;

getFileTypes生命周期回调，获取支持文件的MIME类型时回调

**参数：**

| 名称           | 类型   | 必填 | 描述                       |
| -------------- | ------ | ---- | -------------------------- |
| uri            | string | 是   | 指示要获取的文件的路径     |
| mimeTypeFilter | string | 是   | 指示要获取的文件的MIME类型 |

**返回值：**

| 类型                                    | 说明        |
| -------------------------------------- | ------------------------ |
| Array<string> | 返回匹配的MIME类型数组 |

**示例：**

```js
getFileTypes(uri: string, mimeTypeFilter: string,callback) {
	// Specific functions need to be implemented by the user
	let ret = new Array("type01", "type02", "type03");
	callback(err,ret);
}
```

### normalizeUri

normalizeUri?(uri: string, callback: AsyncCallback<string>): void;

normalizeUri生命周期回调，给定uri转换为规范化uri时回调

**参数：**

| 名称 | 类型   | 必填 | 描述                  |
| ---- | ------ | ---- | --------------------- |
| uri  | string | 是   | 指示要规范化的uri对象 |

**返回值：**

| 类型   | 说明                                                 |
| ------ | ---------------------------------------------------- |
| string | 如果数据功能支持uri规范化或null，则返回规范化uri对象 |

**示例：**

```js
normalizeUri(uri: string,callback) {
	// Specific functions need to be implemented by the user
	let ret = "normalize+" + uri;
	callback(err,ret);
}
```

### denormalizeUri

denormalizeUri?(uri: string, callback: AsyncCallback<string>): void;

将由denormalizeUri生命周期回调，给定规范化uri转换为非规范化uri时回调

**参数：**

| 名称 | 类型   | 必填 | 描述                  |
| ---- | ------ | ---- | --------------------- |
| uri  | string | 是   | 指示要规范化的uri对象 |

**返回值：**

| 类型   | 说明                                    |
| ------ | --------------------------------------- |
| string | 如果反规范化成功，则返回反规范化uri对象 |

**示例：**

```js
denormalizeUri(uri: string,callback) {
	// Specific functions need to be implemented by the user
	let ret = "denormalize+" + uri;
	callback(err,ret);
}
```

### openFile

openFile?(uri: string, mode: string, callback: AsyncCallback<number>): void;

将由openFile生命周期回调，在打开文件时回调

**参数：**

| 名称 | 类型   | 必填 | 描述                  |
| ---- | ------ | ---- | --------------------- |
| uri  | string | 是   | 指示要规范化的uri对象 |
| mode | string | 是   | 指示文件打开模式‘rwt’ |

**返回值：**

| 类型   | 说明           |
| ------ | -------------- |
| number | 返回文件描述符 |

**示例：**

```js
openFile(uri: string, mode, callback) {
    // Specific functions need to be implemented by the user
    let fd = 0;
    callback(err,fd);
}
```
