# 数据共享

**数据共享（Data Share）** 是应用管理自身和其他应用存储数据的访问，提供与其他应用共享数据的方法，既支持同个设备上应用之间的数据共享，也支持跨设备上应用之间的数据共享。

>**说明：** 
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```js
import Ability from '@ohos.application.Ability'
import dataShare from '@ohos.data.dataShare'
```


## dataShare.createDataShareHelper

createDataShareHelper(context: Context, uri: string, callback: AsyncCallback&lt;DataShareHelper&gt;): void;
createDataShareHelper(context: Context, uri: string): Promise&lt;DataShareHelper&gt;;

创建DataShare工具类，返回helper对象，用于连接服务端，并通过callback方式返回，此方法为异步方法。

**系统能力：**  以下各项对应的系统能力均为SystemCapability.DistributedDataManager.DataShare.Consumer。

**参数：**

| 参数名   | 参数类型                                                 | 必填 | 说明                                                         |
| -------- | -------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                                                  | 是   | 应用的上下文环境。                                           |
| uri      | string                                                   | 是   | 指示要打开的文件的路径。                                     |
| callback | AsyncCallback&lt;[DataShareHelper](#DataShareHelper)&gt; | 是   | DataShareHelper实例创建时调用的回调，返回KVManager对象实例。 |

**示例：**

```js
let context = this.context;
let dseUri = ("datashare:///com.samples.datasharetest.DataShare");
await dataShare.createDataShareHelper(this.context, dseUri, (err,data)=>{
	if(err.code != 0) {
        console.info("createDataShareHelper fail, err = " + err);
    }erse {
        let dataShareHelper = data;
    }
});
```

## DataShareHelper

### openFile

openFile(uri: string, mode: string, callback: AsyncCallback<number>): void

在指定的远程路径中打开文件（callback形式）。

**参数：**

| 名称     | 类型                  | 必填 | 描述                               |
| -------- | --------------------- | ---- | ---------------------------------- |
| uri      | string                | 是   | 指示要打开的文件的路径。           |
| mode     | string                | 是   | 指示文件打开模式‘rwt’。            |
| callback | AsyncCallback<number> | 是   | 被指定的回调方法，返回文件描述符。 |

**示例：**

```js
import dataShare from '@ohos.data.dataShare';
let uri = "datashare:///com.samples.datasharetest.DataShare";
dataShareHelper.openFile(uri, "rwt", (err,data) => {
    if(err.code != 0) {
        console.info("createDataShareHelper fail, err = " + err);
    }erse {
        let fd = data;
    }
});
```

### openFile

openFile(uri: string, mode: string): Promise<number>

在指定的远程路径中打开文件（Promise形式）。

**参数：**

| 名称 | 类型   | 必填 | 描述                    |
| ---- | ------ | ---- | ----------------------- |
| uri  | string | 是   | 指示要打开的文件的路径  |
| mode | string | 是   | 指示文件打开模式‘rwt’。 |

**返回值：**

| 类型            | 说明             |
| --------------- | ---------------- |
| Promise<number> | 返回文件描述符。 |

**示例：**

```js
import dataShare from '@ohos.data.dataShare';
let uri = "datashare:///com.samples.datasharetest.DataShare";
dataShareHelper.openFile(uri, "rwt").then((data)=>{
	let fd = data;
}).catch((err) => {
	console.info("createDataShareHelper fail, err = " + err); 
})
```

### on('dataChange')

on(type: 'dataChange', uri: string, callback: AsyncCallback\<void>): void

注册观察者以观察给定uri指定的数据callback通知。

**参数：**

| 名称     | 类型                 | 必填 | 描述                     |
| -------- | -------------------- | ---- | ------------------------ |
| type     | string               | 是   | 数据更改。               |
| uri      | string               | 是   | 指示要操作的数据的路径。 |
| callback | AsyncCallback\<void> | 是   | 指示数据更改时的回调。   |

**示例：**

```js
import dataShare from '@ohos.data.dataShare';
let uri = "datashare:///com.samples.datasharetest.DataShare";
dataShareHelper.on("dataChange", uri, onCallback);

export function onCallback() {
    console.info("**** Observer on callback ****");
}
```

### off('dataChange')

off(type: 'dataChange', uri: string, callback?: AsyncCallback\<void>): void

注消观察者以停止观察给定uri指定的数据callback通知。

**参数：**

| 名称     | 类型                 | 必填 | 描述                     |
| -------- | -------------------- | ---- | ------------------------ |
| type     | string               | 是   | 数据更改。               |
| uri      | string               | 是   | 指示要操作的数据的路径。 |
| callback | AsyncCallback\<void> | 否   | 指示已注册的回调。       |

**示例：**

```js
import dataShare from '@ohos.data.dataShare';
let uri = "datashare:///com.samples.datasharetest.DataShare";
dataShareHelper.off("dataChange", uri, offCallback);

export function offCallback() {
    console.info("**** Observer off callback ****");
}
```

### getType

getType(uri: string, callback: AsyncCallback\<string>): void

获取给定URI指定数据的MIME类型（callback形式）。

**参数：**

| 名称     | 类型                   | 必填 | 描述                                          |
| -------- | ---------------------- | ---- | --------------------------------------------- |
| uri      | string                 | 是   | 指示要操作的数据的路径。                      |
| callback | AsyncCallback\<string> | 是   | 回调方法，返回与uri指定的数据匹配的MIME类型。 |

**示例：**

```js
import dataShare from '@ohos.data.dataShare'
let uri = "datashare:///com.samples.datasharetest.DataShare";
dataShareHelper.getType(uri,(err,data)=>{
	if(err.code != 0){
		console.log("getType err, err:" + JSON.stringify(err));
	}else{
		console.log("getType end, data:" + JSON.stringify(data));
		let result = data;
	}         
});
```

### getType

getType(uri: string): Promise\<string>

获取给定URI指定数据的MIME类型（Promise形式）。

**参数：**

| 名称 | 类型   | 必填 | 描述                     |
| ---- | ------ | ---- | ------------------------ |
| uri  | string | 是   | 指示要操作的数据的路径。 |

**返回值：**

| 类型             | 说明                                |
| ---------------- | ----------------------------------- |
| Promise\<string> | 返回与uri指定的数据匹配的MIME类型。 |

**示例：**

```js
import dataShare from '@ohos.data.dataShare'
let uri = "datashare:///com.samples.datasharetest.DataShare";
dataShareHelper.getType(uri).then((data) => {
	console.log("getType end, data:" + data);
}).catch((err) => {
	console.log("getType end, err:" + err);
});
```

### getFileTypes

getFileTypes(uri: string, mimeTypeFilter: string, callback: AsyncCallback<Array\<string>>): void

获取支持的文件的MIME类型（callback形式）。

**参数：**

| 名称           | 类型                           | 必填 | 描述                               |
| -------------- | ------------------------------ | ---- | ---------------------------------- |
| uri            | string                         | 是   | 指示要获取的文件的路径。           |
| mimeTypeFilter | string                         | 是   | 指示要获取的文件的MIME类型。       |
| callback       | AsyncCallback\<Array\<string>> | 是   | 回调方法，返回匹配的MIME类型数组。 |

**示例：**

```js
import dataShare from '@ohos.data.dataShare';
let uri = "datashare:///com.samples.datasharetest.DataShare";
let mimeTypeFilter = "image/*";
dataShareHelper.getFileTypes(uri, mimeTypeFilter, (err,data) => {
	if(err.code != 0){
		console.log("dataShareHelper end, err:" + err);
	}else{
		console.log("dataShareHelper end, data:" + data);
	}
});
```



### getFileTypes

getFileTypes(uri: string, mimeTypeFilter: string): Promise\<Array\<string>>

获取支持的文件的MIME类型（Promise形式）。

**参数：**

| 名称           | 类型   | 必填 | 描述                         |
| -------------- | ------ | ---- | ---------------------------- |
| uri            | string | 是   | 指示要获取的文件的路径。     |
| mimeTypeFilter | string | 是   | 指示要获取的文件的MIME类型。 |

**返回值：**

| 类型                     | 说明                     |
| ------------------------ | ------------------------ |
| Promise\<Array\<string>> | 返回匹配的MIME类型数组。 |

**示例：**

```js
import dataShare from '@ohos.data.dataShare';
let uri = "datashare:///com.samples.datasharetest.DataShare";
let mimeTypeFilter = "image/*";
dataShareHelper.getFileTypes(uri, mimeTypeFilter).then((data) => {
	console.log("dataShareHelper end, data:" + data);
}).catch((err) => {
	console.log("dataShareHelper end, err:" + err);
});
```

### normalizeUri

normalizeUri(uri: string, callback: AsyncCallback\<string>): void

将引用数据功能的给定uri转换为规范化uri（callback形式）。

**参数：**

| 名称     | 类型                   | 必填 | 描述                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| uri      | string                 | 是   | 指示要规范化的uri对象。                                      |
| callback | AsyncCallback\<string> | 是   | 回调方法。如果数据功能支持uri规范化或null，则返回规范化uri对象。 |

**示例：**

```js
import dataShare from '@ohos.data.dataShare';
let uri = "datashare:///com.samples.datasharetest.DataShare";
dataShareHelper.normalizeUri(uri,(err,data) => {
	if(err.code != 0){
		console.log("normalizeUri end, err:" + err);
	}else{
		console.log("normalizeUri = " + data);
	}
});
```

### normalizeUri

normalizeUri(uri: string): Promise\<string>

将引用数据功能的给定uri转换为规范化uri（Promise形式）。

**参数：**

| 名称 | 类型   | 必填 | 描述                    |
| ---- | ------ | ---- | ----------------------- |
| uri  | string | 是   | 指示要规范化的uri对象。 |

**返回值：**

| 类型             | 说明                                                   |
| ---------------- | ------------------------------------------------------ |
| Promise\<string> | 如果数据功能支持uri规范化或null，则返回规范化uri对象。 |

**示例：**

```js
import dataShare from '@ohos.data.dataShare';
let uri = "datashare:///com.samples.datasharetest.DataShare";
dataShareHelper.normalizeUri(uri).then((data) => {
	console.log("normalizeUri = " + data);
}).catch((err) => {
	console.log("normalizeUri end, err:" + err);
});
```

### denormalizeUri

denormalizeUri(uri: string, callback: AsyncCallback\<string>): void

将由normalizeUri（uri）生成的给定规范化uri转换为非规范化uri（callback形式）。

**参数：**

| 名称     | 类型                   | 必填 | 描述                                                |
| -------- | ---------------------- | ---- | --------------------------------------------------- |
| uri      | string                 | 是   | 指示要规范化的uri对象。                             |
| callback | AsyncCallback\<string> | 是   | 回调方法。如果反规范化成功，则返回反规范化uri对象。 |

**示例：**

```js
import dataShare from '@ohos.data.dataShare'；
let uri = "datashare:///com.samples.datasharetest.DataShare";
dataShareHelper.denormalizeUri(uri,(err,data) => {
	if(err.code != 0){
		console.log("denormalizeUri end, err:" + err);
	}else{
		console.log("denormalizeUri = " + data);
	}
});
```

### denormalizeUri

denormalizeUri(uri: string): Promise\<string>

将由normalizeUri（uri）生成的给定规范化uri转换为非规范化uri（Promise形式）。

**参数：**

| 名称 | 类型   | 必填 | 描述                    |
| ---- | ------ | ---- | ----------------------- |
| uri  | string | 是   | 指示要规范化的uri对象。 |

**返回值：**

| 类型             | 说明                                      |
| ---------------- | ----------------------------------------- |
| Promise\<string> | 如果反规范化成功，则返回反规范化uri对象。 |

**示例：**

```js
import dataShare from '@ohos.data.dataShare';
let uri = "datashare:///com.samples.datasharetest.DataShare";
dataShareHelper.denormalizeUri(uri).then((data) => {
	console.log("denormalizeUri = " + data);
}).catch((err) => {
	console.log("denormalizeUri end, err:" + err);
});
```

### notifyChange

notifyChange(uri: string, callback: AsyncCallback\<void>): void

通知已注册的观察者uri指定的数据资源的更改（callback形式）。

**参数：**

| 名称     | 类型                 | 必填 | 描述                     |
| -------- | -------------------- | ---- | ------------------------ |
| uri      | string               | 是   | 指示要操作的数据的路径。 |
| callback | AsyncCallback\<void> | 是   | 回调方法。               |

**示例：**

```js
import dataShare from '@ohos.data.dataShare';
let uri = "datashare:///com.samples.datasharetest.DataShare";
dataShareHelper.notifyChange(uri,() => {
	console.log("notifyChange!!!!!!!");
});
```

### notifyChange

notifyChange(uri: string): Promise\<void>

通知已注册的观察者uri指定的数据资源的更改（Promise形式）。

**参数：**

| 名称 | 类型   | 必填 | 描述                     |
| ---- | ------ | ---- | ------------------------ |
| uri  | string | 是   | 指示要操作的数据的路径。 |

**返回值：**

| 类型           | 说明                  |
| -------------- | --------------------- |
| Promise\<void> | 返回值为Promise对象。 |

**示例：**

```js
import dataShare from '@ohos.data.dataShare';
let uri = "datashare:///com.samples.datasharetest.DataShare";
await dataShareHelper.notifyChange(uri);
```

### insert

insert(uri: string, value: ValuesBucket, callback: AsyncCallback\<number>): void

将单个数据记录插入数据库（callback形式）。

**参数：**

| 名称     | 类型                   | 必填 | 描述                                                   |
| -------- | ---------------------- | ---- | ------------------------------------------------------ |
| uri      | string                 | 是   | 指示要插入的数据的路径。                               |
| value    | ValuesBucket           | 是   | 指示要插入的数据记录。如果此参数为空，将插入一个空行。 |
| callback | AsyncCallback\<number> | 是   | 回调方法，返回插入数据记录的索引。                     |

**示例：**

```js
import dataShare from '@ohos.data.dataShare';
let uri = "datashare:///com.samples.datasharetest.DataShare";

const valueBucket = {
    "name": "rose",
    "age": 22,
    "salary": 200.5,
    "blobType": u8,
}
dataShareHelper.insert(
    uri,
    valueBucket,
    (err, data) => {
        console.info("==========================>Called=======================>");
});
```

### insert

insert(uri: string, value: ValuesBucket): Promise\<number>

将单个数据记录插入数据库（Promise形式）。

**参数：**

| 名称  | 类型         | 必填 | 描述                                                   |
| ----- | ------------ | ---- | ------------------------------------------------------ |
| uri   | string       | 是   | 指示要插入的数据的路径。                               |
| value | ValuesBucket | 是   | 指示要插入的数据记录。如果此参数为空，将插入一个空行。 |

**返回值：**

| 类型             | 说明                     |
| ---------------- | ------------------------ |
| Promise\<number> | 返回插入数据记录的索引。 |

**示例：**

```js
import dataShare from '@ohos.data.dataShare'；
let uri = "datashare:///com.samples.datasharetest.DataShare";

const valueBucket = {
    "name": "rose1",
    "age": 221,
    "salary": 20.5,
    "blobType": u8,
}
dataShareHelper.insert(
    uri,
    valueBucket
    ).then((data) => {
        console.info("==========================>insertCallback=======================>");
}).catch((err) => {
	console.log("insert end, err:" + err);
});
```

### batchInsert

batchInsert(uri: string, values: Array\<ValuesBucket>, callback: AsyncCallback\<number>): void

插入数据库（callback形式）。

**参数：**

| 名称     | 类型                   | 必填 | 描述                             |
| -------- | ---------------------- | ---- | -------------------------------- |
| uri      | string                 | 是   | 指示要插入的数据的路径。         |
| values   | Array\<ValuesBucket>   | 是   | 指示要插入的数据记录。           |
| callback | AsyncCallback\<number> | 是   | 回调方法。返回插入的数据记录数。 |

**示例：**

```js
import dataShare from '@ohos.data.dataShare';
let uri = "datashare:///com.samples.datasharetest.DataShare";

let cars = new Array({"name": "roe11", "age": 21, "salary": 20.5, "blobType": u8,},
                     {"name": "roe12", "age": 21, "salary": 20.5, "blobType": u8,},
                     {"name": "roe13", "age": 21, "salary": 20.5, "blobType": u8,})
dataShareHelper.batchInsert(
    uri,
    cars,
    (err, data) => {
        console.info("==========================>Called=======================>");
});
```

### batchInsert

batchInsert(uri: string, values: Array\<ValuesBucket>): Promise\<number>

将多个数据记录插入数据库（Promise形式）。

**参数：**

| 名称   | 类型                 | 必填 | 描述                     |
| ------ | -------------------- | ---- | ------------------------ |
| uri    | string               | 是   | 指示要插入的数据的路径。 |
| values | Array\<ValuesBucket> | 是   | 指示要插入的数据记录。   |

**返回值：**

| 类型             | 说明                   |
| ---------------- | ---------------------- |
| Promise\<number> | 返回插入的数据记录数。 |

**示例：**

```js
import dataShare from '@ohos.data.dataShare';
let uri = "datashare:///com.samples.datasharetest.DataShare";

let cars = new Array({"name": "roe11", "age": 21, "salary": 20.5, "blobType": u8,},
                     {"name": "roe12", "age": 21, "salary": 20.5, "blobType": u8,},
                     {"name": "roe13", "age": 21, "salary": 20.5, "blobType": u8,})
dataShareHelper.batchInsert(
    uri,
    cars
    ).then((data) => {
        console.info("==========================>batchInsertCallback=======================>");
}).catch((err) => {
	console.log("batchInsert end, err:" + err);
});
```

### delete

delete(uri: string, predicates: DataSharePredicates, callback: AsyncCallback\<number>): void

从数据库中删除一个或多个数据记录（callback形式）。

**参数：**

| 名称       | 类型                   | 必填 | 描述                                             |
| ---------- | ---------------------- | ---- | ------------------------------------------------ |
| uri        | string                 | 是   | 指示要删除的数据的路径。                         |
| predicates | DataSharePredicates    | 是   | 指示筛选条件。当此参数为null时，应定义处理逻辑。 |
| callback   | AsyncCallback\<number> | 是   | 回调方法。返回已删除的数据记录数。               |

**示例：**

```js
import dataShare from '@ohos.data.dataShare';
let uri = "datashare:///com.samples.datasharetest.DataShare";

let da = new dataShare.DataSharePredicates();
da.equalTo("name", "ZhangSan");
dataShareHelper.delete(
    uri,
    da,
    (err, data) => {
        console.info("==========================>Called=======================>");
});
```

### delete

delete(uri: string, predicates: DataSharePredicates): Promise\<number>

从数据库中删除一个或多个数据记录（Promise形式）。

**参数：**

| 名称       | 类型                | 必填 | 描述                                             |
| ---------- | ------------------- | ---- | ------------------------------------------------ |
| uri        | string              | 是   | 指示要删除的数据的路径。                         |
| predicates | DataSharePredicates | 是   | 指示筛选条件。当此参数为null时，应定义处理逻辑。 |

**返回值：**

| 类型             | 说明                     |
| ---------------- | ------------------------ |
| Promise\<number> | 返回已删除的数据记录数。 |

**示例：**

```js
import dataShare from '@ohos.data.dataShare';
let uri = "datashare:///com.samples.datasharetest.DataShare";

let da = new dataShare.DataSharePredicates();
da.equalTo("name", "ZhangSan");
dataShareHelper.delete(
    uri,
    da
    ).then((data) => {
        console.info("==========================>deleteCallback=======================>");
}).catch((err) => {
	console.log("delete end, err:" + err);
});
```

### update

update(uri: string, predicates: DataSharePredicates, value: ValuesBucket, callback: AsyncCallback<number>): void

更新数据库中的数据记录（callback形式）。

**参数：**

| 名称       | 类型                   | 必填 | 描述                                             |
| ---------- | ---------------------- | ---- | ------------------------------------------------ |
| uri        | string                 | 是   | 指示要更新的数据的路径。                         |
| predicates | DataSharePredicates    | 是   | 指示筛选条件。当此参数为null时，应定义处理逻辑。 |
| value      | ValuesBucket           | 是   | 指示要更新的数据。                               |
| callback   | AsyncCallback\<number> | 是   | 回调方法，返回更新的数据记录数。                 |

**示例：**

```js
import dataShare from '@ohos.data.dataShare';
let uri = "datashare:///com.samples.datasharetest.DataShare";

let da = new dataShare.DataSharePredicates();
da.equalTo("name", "ZhangSan");
const va = {
    "name": "roe1",
    "age": 21,
    "salary": 20.5,
    "blobType": u8,
}
dataShareHelper.update(
    uri,
    da,
    va,
    (err, data) => {
        console.info("==========================>Called=======================>");
});
```

### update

update(uri: string, predicates: DataSharePredicates, value: ValuesBucket): Promise<number>

更新数据库中的数据记录（Promise形式）。

**参数：**

| 名称       | 类型                | 必填 | 描述                                             |
| ---------- | ------------------- | ---- | ------------------------------------------------ |
| uri        | string              | 是   | 指示要更新的数据的路径。                         |
| predicates | DataSharePredicates | 是   | 指示要更新的数据。                               |
| value      | ValuesBucket        | 是   | 指示筛选条件。当此参数为null时，应定义处理逻辑。 |

**返回值：**

| 类型             | 说明                                         |
| ---------------- | -------------------------------------------- |
| Promise\<number> | 返回值为Promise对象，Promise中包含应用信息。 |

**示例：**

```js
import dataShare from '@ohos.data.dataShare';
let uri = "datashare:///com.samples.datasharetest.DataShare";

let da = new dataShare.DataSharePredicates();
da.equalTo("name", "ZhangSan");
const va = {
    "name": "roe1",
    "age": 21,
    "salary": 20.5,
    "blobType": u8,
}
dataShareHelper.update(
    uri,
    da,
    va,
    ).then((data) => {
        console.info("==========================>updateCallback=======================>");
}).catch((err) => {
	console.log("update end, err:" + err);
});
```

### query

query(uri: string, predicates: DataSharePredicates, columns: Array<string>, callback: AsyncCallback<DataShareResultSet>): void

查询数据库中的数据（callback形式）。

**参数：**

| 名称       | 类型                               | 必填 | 描述                                             |
| ---------- | ---------------------------------- | ---- | ------------------------------------------------ |
| uri        | string                             | 是   | 指示要查询的数据的路径。                         |
| predicates | DataSharePredicates                | 是   | 指示筛选条件。当此参数为null时，应定义处理逻辑。 |
| columns    | Array<string>                      | 是   | 指示要查询的列。如果此参数为空，则查询所有列。   |
| callback   | AsyncCallback\<DataShareResultSet> | 是   | 回调方法，返回查询结果。                         |

**示例：**

```js
import dataShare from '@ohos.data.dataShare';
let uri = "datashare:///com.samples.datasharetest.DataShare";

let columns = ["*"]；
let da = new dataShare.DataSharePredicates();
da.equalTo("name", "ZhangSan");
dataShareHelper.query(
    uri,
	da,
    columns,
    (err, data) => {
        console.info("==========================>Called=======================>");
});
```



### query

query(uri: string, predicates: DataSharePredicates, columns: Array<string>): Promise<DataShareResultSet>

查询数据库中的数据（Promise形式）。

**参数：**

| 名称       | 类型                | 必填 | 描述                                             |
| ---------- | ------------------- | ---- | ------------------------------------------------ |
| uri        | string              | 是   | 指示要查询的数据的路径。                         |
| predicates | DataSharePredicates | 是   | 指示筛选条件。当此参数为null时，应定义处理逻辑。 |
| columns    | Array<string>       | 是   | 指示要查询的列。如果此参数为空，则查询所有列。   |

**返回值：**

| 类型                         | 说明           |
| ---------------------------- | -------------- |
| Promise\<DataShareResultSet> | 返回查询结果。 |

**示例：**

```js
import dataShare from '@ohos.data.dataShare';
let uri = "datashare:///com.samples.datasharetest.DataShare";

let columns = ["*"]；
let da = new dataShare.DataSharePredicates();
da.equalTo("name", "ZhangSan");
dataShareHelper.query(
    uri,
	da,
    columns,
    ).then((data) => {
        console.info("==========================>queryCallback=======================>");
}).catch((err) => {
	console.log("query end, err:" + err);
});
```
