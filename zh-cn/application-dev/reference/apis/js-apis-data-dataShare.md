# DataShare

**DataShare** 用于应用管理其自身数据，也提供了其他应用共享以及管理其数据的方法，支持同个设备上应用之间的数据共享。

>**说明：** 
>
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import Ability from '@ohos.application.Ability'
import dataShare from '@ohos.data.dataShare'
```


## dataShare.createDataShareHelper

createDataShareHelper(context: Context, uri: string, callback: AsyncCallback&lt;DataShareHelper&gt;): void
createDataShareHelper(context: Context, uri: string): Promise&lt;DataShareHelper&gt;

创建DataShare工具类，创建helper对象时将连接服务端，与服务端取得连接后或超时后将返回helper实例，此方法为异步方法。在与服务端取得连接后可使用DataShare工具类提供的方法访问或管理服务端的数据，若未连接上服务端，调用工具类提供的方法时将返回error code。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 参数名   | 参数类型                                                 | 必填 | 说明                                                         |
| -------- | -------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| context  | [Context](js-apis-application-context.md#context)        | 是   | 应用的上下文环境。                                           |
| uri      | string                                                   | 是   | 指示要打开的文件的路径。                                     |
| callback | AsyncCallback&lt;[DataShareHelper](#datasharehelper)&gt; | 是   | DataShareHelper实例创建完成后调用的回调，返回DataShareHelper对象实例。 |

**示例：**

```ts
import dataShare from '@ohos.data.dataShare'

let dseUri = ("datashare:///com.samples.datasharetest.DataShare");
dataShare.createDataShareHelper(this.context, dseUri, (err, data) => {
    if (err != undefined) {
        console.info("createDataShareHelper fail, error message : " + err);
    } else {
        console.info("createDataShareHelper end, data : " + data);
        let dataShareHelper = data;
    }
});
```

## DataShareHelper

### openFile

openFile(uri: string, mode: string, callback: AsyncCallback&lt;number&gt;): void

打开URI所指定的远程路径中的文件（callback形式）。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称     | 类型                  | 必填 | 描述                               |
| -------- | --------------------- | ---- | ---------------------------------- |
| uri      | string                | 是   | 指示要打开的文件的路径。           |
| mode     | string                | 是   | 指示文件打开模式‘rwt’。            |
| callback | AsyncCallback&lt;number&gt; | 是   | 被指定的回调方法，返回文件描述符。 |

**示例：**

```ts
let dataShareHelper;
let uri = ("datashare:///com.samples.datasharetest.DataShare");
dataShareHelper.openFile(uri, "rwt", (err, data) => {
    if (err != undefined) {
        console.info("openFile fail, error message : " + err);
    }erse {
        console.info("openFile end, data : " + data);
        let fd = data;
    }
});
```

### openFile

openFile(uri: string, mode: string): Promise&lt;number&gt;

打开URI所指定的远程路径中的文件（Promise形式）。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称 | 类型   | 必填 | 描述                    |
| ---- | ------ | ---- | ----------------------- |
| uri  | string | 是   | 指示要打开的文件的路径  |
| mode | string | 是   | 指示文件打开模式‘rwt’。 |

**返回值：**

| 类型            | 说明             |
| --------------- | ---------------- |
| Promise&lt;number&gt; | 返回文件描述符。 |

**示例：**

```ts
let dataShareHelper;
let uri = ("datashare:///com.samples.datasharetest.DataShare");
dataShareHelper.openFile(uri, "rwt").then((data) => {
    console.info("openFile end, data : " + data);
    let fd = data;
}).catch((err) => {
	console.info("openFile fail, error message : " + err); 
})
```

### on('dataChange')

on(type: 'dataChange', uri: string, callback: AsyncCallback&lt;void&gt;): void

注册观察者以订阅给定uri指定的数据callback通知。若用户（订阅者）已注册了观察者，当有其他用户触发了变更通知时（调用了下文中的notifyChange方法），订阅者将会接受到callback通知。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称     | 类型                 | 必填 | 描述                     |
| -------- | -------------------- | ---- | ------------------------ |
| type     | string               | 是   | 数据更改。               |
| uri      | string               | 是   | 指示要操作的数据的路径。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 指示数据更改时的回调。   |

**示例：**

```ts
let dataShareHelper;
let uri = ("datashare:///com.samples.datasharetest.DataShare");
dataShareHelper.on("dataChange", uri, onCallback);

export function onCallback() {
    console.info("**** Observer on callback ****");
}
```

### off('dataChange')

off(type: 'dataChange', uri: string, callback?: AsyncCallback&lt;void&gt;): void

注消观察者以停止观察给定uri指定的数据callback通知。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称     | 类型                 | 必填 | 描述                     |
| -------- | -------------------- | ---- | ------------------------ |
| type     | string               | 是   | 数据更改。               |
| uri      | string               | 是   | 指示要操作的数据的路径。 |
| callback | AsyncCallback&lt;void&gt; | 否   | 指示已注册的回调。       |

**示例：**

```ts
let dataShareHelper;
let uri = ("datashare:///com.samples.datasharetest.DataShare");
dataShareHelper.off("dataChange", uri, offCallback);

export function offCallback() {
    console.info("**** Observer off callback ****");
}
```

### notifyChange

notifyChange(uri: string, callback: AsyncCallback&lt;void&gt;): void

通知已注册的观察者uri指定的数据资源的更改（callback形式）。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称     | 类型                 | 必填 | 描述                     |
| -------- | -------------------- | ---- | ------------------------ |
| uri      | string               | 是   | 指示要操作的数据的路径。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调方法。               |

**示例：**

```ts
let dataShareHelper;
let uri = ("datashare:///com.samples.datasharetest.DataShare");
dataShareHelper.notifyChange(uri, () => {
    console.log("***** notifyChange *****");
});
```

### notifyChange

notifyChange(uri: string): Promise&lt;void&gt;

通知已注册的观察者uri指定的数据资源的更改（Promise形式）。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称 | 类型   | 必填 | 描述                     |
| ---- | ------ | ---- | ------------------------ |
| uri  | string | 是   | 指示要操作的数据的路径。 |

**返回值：**

| 类型           | 说明                  |
| -------------- | --------------------- |
| Promise&lt;void&gt; | 返回值为Promise对象。 |

**示例：**

```ts
let dataShareHelper;
let uri = ("datashare:///com.samples.datasharetest.DataShare");
dataShare.createDataShareHelper(this.context, uri, (err, data) => {
    if (err != undefined) {
        console.info("createDataShareHelper fail, error message : " + err);
    } else {
        console.info("createDataShareHelper end, data : " + data);
        dataShareHelper = data;
    }
});

dataShareHelper.notifyChange(uri);
```

### getType

getType(uri: string, callback: AsyncCallback&lt;string&gt;): void

获取URI所指定的数据的MIME类型（callback形式）。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称     | 类型                   | 必填 | 描述                                          |
| -------- | ---------------------- | ---- | --------------------------------------------- |
| uri      | string                 | 是   | 指示要操作的数据的路径。                      |
| callback | AsyncCallback&lt;string&gt; | 是   | 回调方法，返回与uri指定的数据匹配的MIME类型。 |

**示例：**

```ts
let dataShareHelper;
let uri = ("datashare:///com.samples.datasharetest.DataShare");
dataShareHelper.getType(uri, (err, data)=>{
    if (err != undefined) {
        console.log("getType fail, error message : " + err);
    }else{
        console.log("getType end, data : " + data);
        let result = data;
    }         
});
```

### getType

getType(uri: string): Promise&lt;string&gt;

获取URI所指定数据的MIME类型（Promise形式）。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称 | 类型   | 必填 | 描述                     |
| ---- | ------ | ---- | ------------------------ |
| uri  | string | 是   | 指示要操作的数据的路径。 |

**返回值：**

| 类型             | 说明                                |
| ---------------- | ----------------------------------- |
| Promise&lt;string&gt; | 返回与uri指定的数据匹配的MIME类型。 |

**示例：**

```ts
let dataShareHelper;
let uri = ("datashare:///com.samples.datasharetest.DataShare");
dataShareHelper.getType(uri).then((data) => {
    console.log("getType end, data : " + data);
}).catch((err) => {
    console.log("getType fail, error message : " + err);
});
```

### getFileTypes

getFileTypes(uri: string, mimeTypeFilter: string, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

获取支持的文件的MIME类型（callback形式）。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称           | 类型                           | 必填 | 描述                               |
| -------------- | ------------------------------ | ---- | ---------------------------------- |
| uri            | string                         | 是   | 指示要获取的文件的路径。           |
| mimeTypeFilter | string                         | 是   | 指示要获取的文件的MIME类型。       |
| callback       | AsyncCallback&lt;Array&lt;string&gt;&gt; | 是   | 回调方法，返回匹配的MIME类型数组。 |

**示例：**

```ts
let dataShareHelper;
let uri = ("datashare:///com.samples.datasharetest.DataShare");
let mimeTypeFilter = "image/*";
dataShareHelper.getFileTypes(uri, mimeTypeFilter, (err,data) => {
    if (err != undefined) {
        console.log("dataShareHelper fail, error message : " + err);
    }else{
        console.log("dataShareHelper end, data : " + data);
    }
});
```



### getFileTypes

getFileTypes(uri: string, mimeTypeFilter: string): Promise&lt;Array&lt;string&gt;&gt;

获取支持的文件的MIME类型（Promise形式）。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称           | 类型   | 必填 | 描述                         |
| -------------- | ------ | ---- | ---------------------------- |
| uri            | string | 是   | 指示要获取的文件的路径。     |
| mimeTypeFilter | string | 是   | 指示要获取的文件的MIME类型。 |

**返回值：**

| 类型                     | 说明                     |
| ------------------------ | ------------------------ |
| Promise&lt;Array&lt;string&gt;&gt; | 返回匹配的MIME类型数组。 |

**示例：**

```ts
let dataShareHelper;
let uri = ("datashare:///com.samples.datasharetest.DataShare");
let mimeTypeFilter = "image/*";
dataShareHelper.getFileTypes(uri, mimeTypeFilter).then((data) => {
	console.log("dataShareHelper end, data : " + data);
}).catch((err) => {
	console.log("dataShareHelper fail, error message : " + err);
});
```

### normalizeUri

normalizeUri(uri: string, callback: AsyncCallback&lt;string&gt;): void

将给定的DataShare uri转换为规范化uri（callback形式）。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称     | 类型                   | 必填 | 描述                                                     |
| -------- | ---------------------- | ---- | -------------------------------------------------------- |
| uri      | string                 | 是   | 指示要规范化的uri对象。                                  |
| callback | AsyncCallback&lt;string&gt; | 是   | 回调方法。如果支持uri规范化或null，则返回规范化uri对象。 |

**示例：**

```ts
let dataShareHelper;
let uri = ("datashare:///com.samples.datasharetest.DataShare");
dataShareHelper.normalizeUri(uri, (err, data) => {
    if (err != undefined) {
        console.log("normalizeUri fail, error message : " + err);
    }else{
        console.log("normalizeUri = " + data);
    }
});
```

### normalizeUri

normalizeUri(uri: string): Promise&lt;string&gt;

将给定的DataShare uri转换为规范化uri（Promise形式）。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称 | 类型   | 必填 | 描述                    |
| ---- | ------ | ---- | ----------------------- |
| uri  | string | 是   | 指示要规范化的uri对象。 |

**返回值：**

| 类型             | 说明                                           |
| ---------------- | ---------------------------------------------- |
| Promise&lt;string&gt; | 如果支持uri规范化或null，则返回规范化uri对象。 |

**示例：**

```ts
let dataShareHelper;
let uri = ("datashare:///com.samples.datasharetest.DataShare");
dataShareHelper.normalizeUri(uri).then((data) => {
    console.log("normalizeUri = " + data);
}).catch((err) => {
    console.log("normalizeUri fail, error message : " + err);
});
```

### denormalizeUri

denormalizeUri(uri: string, callback: AsyncCallback&lt;string&gt;): void

将由normalizeUri（uri）生成的规范化uri转换为非规范化uri（callback形式）。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称     | 类型                   | 必填 | 描述                                                |
| -------- | ---------------------- | ---- | --------------------------------------------------- |
| uri      | string                 | 是   | 指示要规范化的uri对象。                             |
| callback | AsyncCallback&lt;string&gt; | 是   | 回调方法。如果反规范化成功，则返回反规范化uri对象。 |

**示例：**

```ts
let dataShareHelper;
let uri = ("datashare:///com.samples.datasharetest.DataShare");
dataShareHelper.denormalizeUri(uri, (err, data) => {
    if (err != undefined) {
        console.log("denormalizeUri fail, error message : " + err);
    }else{
        console.log("denormalizeUri = " + data);
    }
});
```

### denormalizeUri

denormalizeUri(uri: string): Promise&lt;string&gt;

将由normalizeUri（uri）生成的规范化uri转换为非规范化uri（Promise形式）。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称 | 类型   | 必填 | 描述                    |
| ---- | ------ | ---- | ----------------------- |
| uri  | string | 是   | 指示要规范化的uri对象。 |

**返回值：**

| 类型             | 说明                                      |
| ---------------- | ----------------------------------------- |
| Promise&lt;string&gt; | 如果反规范化成功，则返回反规范化uri对象。 |

**示例：**

```ts
let dataShareHelper;
let uri = ("datashare:///com.samples.datasharetest.DataShare");
dataShareHelper.denormalizeUri(uri).then((data) => {
    console.log("denormalizeUri = " + data);
}).catch((err) => {
    console.log("denormalizeUri fail, error message : " + err);
});
```

### insert

insert(uri: string, value: ValuesBucket, callback: AsyncCallback&lt;number&gt;): void

将单条数据记录插入数据库（callback形式）。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称     | 类型                                                      | 必填 | 描述                                                         |
| -------- | --------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| uri      | string                                                    | 是   | 指示要插入的数据的路径。                                     |
| value    | [ValuesBucket](js-apis-data-ValuesBucket.md#valuesbucket) | 是   | 指示要插入的数据记录。如果此参数为空，将插入一个空行。       |
| callback | AsyncCallback&lt;number&gt;                                    | 是   | 回调方法，返回插入数据记录的索引。（能否返回索引取决于服务端所使用的数据库） |

**示例：**

```ts
let dataShareHelper;
let uri = ("datashare:///com.samples.datasharetest.DataShare");
const valueBucket = {
    "name": "rose",
    "age": 22,
    "salary": 200.5,
    "blobType": u8,
}
dataShareHelper.insert(uri, valueBucket, (err, data) => {
    if (err != undefined) {
        console.log("insert fail, error message : " + err);
    }else{
        console.log("insert end, data : " + data);
    }
});
```

### insert

insert(uri: string, value: ValuesBucket): Promise&lt;number&gt;

将单条数据记录插入数据库（Promise形式）。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称  | 类型                                                      | 必填 | 描述                                                   |
| ----- | --------------------------------------------------------- | ---- | ------------------------------------------------------ |
| uri   | string                                                    | 是   | 指示要插入的数据的路径。                               |
| value | [ValuesBucket](js-apis-data-ValuesBucket.md#valuesbucket) | 是   | 指示要插入的数据记录。如果此参数为空，将插入一个空行。 |

**返回值：**

| 类型             | 说明                                                         |
| ---------------- | ------------------------------------------------------------ |
| Promise&lt;number&gt; | 返回插入数据记录的索引。（能否返回索引取决于服务端所使用的数据库） |

**示例：**

```ts
let dataShareHelper;
let uri = ("datashare:///com.samples.datasharetest.DataShare");
const valueBucket = {
    "name": "rose1",
    "age": 221,
    "salary": 20.5,
    "blobType": u8,
}
dataShareHelper.insert(uri, valueBucket).then((data) => {
    console.log("insert end, data : " + data);
}).catch((err) => {
    console.log("insert fail, error message : " + err);
});
```

### batchInsert

batchInsert(uri: string, values: Array&lt;ValuesBucket&gt;, callback: AsyncCallback&lt;number&gt;): void

将批量数据插入数据库（callback形式）。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称     | 类型                                                         | 必填 | 描述                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| uri      | string                                                       | 是   | 指示要插入的数据的路径。                                     |
| values   | Array&lt;[ValuesBucket](js-apis-data-ValuesBucket.md#valuesbucket)&gt; | 是   | 指示要插入的数据记录。                                       |
| callback | AsyncCallback&lt;number&gt;                                       | 是   | 回调方法，返回插入的数据记录数。（能否返回记录数取决于服务端所使用的数据库） |

**示例：**

```ts
let dataShareHelper;
let uri = ("datashare:///com.samples.datasharetest.DataShare");
let vbs = new Array({"name": "roe11", "age": 21, "salary": 20.5, "blobType": u8,},
                     {"name": "roe12", "age": 21, "salary": 20.5, "blobType": u8,},
                     {"name": "roe13", "age": 21, "salary": 20.5, "blobType": u8,})
dataShareHelper.batchInsert(uri, vbs, (err, data) => {
    if (err != undefined) {
        console.log("batchInsert fail, error message : " + err);
    }else{
        console.log("batchInsert end, data : " + data);
    }
});
```

### batchInsert

batchInsert(uri: string, values: Array&lt;ValuesBucket&gt;): Promise&lt;number&gt;

将批量数据插入数据库（Promise形式）。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称   | 类型                                                         | 必填 | 描述                     |
| ------ | ------------------------------------------------------------ | ---- | ------------------------ |
| uri    | string                                                       | 是   | 指示要插入的数据的路径。 |
| values | Array&lt;[ValuesBucket](js-apis-data-ValuesBucket.md#valuesbucket)&gt; | 是   | 指示要插入的数据记录。   |

**返回值：**

| 类型             | 说明                                                         |
| ---------------- | ------------------------------------------------------------ |
| Promise&lt;number&gt; | 返回插入的数据记录数。（能否返回记录数取决于服务端所使用的数据库） |

**示例：**

```ts
let dataShareHelper;
let uri = ("datashare:///com.samples.datasharetest.DataShare");
let vbs = new Array({"name": "roe11", "age": 21, "salary": 20.5, "blobType": u8,},
                     {"name": "roe12", "age": 21, "salary": 20.5, "blobType": u8,},
                     {"name": "roe13", "age": 21, "salary": 20.5, "blobType": u8,})
dataShareHelper.batchInsert(uri, vbs).then((data) => {
    console.log("batchInsert end, data : " + data);
}).catch((err) => {
    console.log("batchInsert fail, error message : " + err);
});
```

### delete

delete(uri: string, predicates: DataSharePredicates, callback: AsyncCallback&lt;number&gt;): void

从数据库中删除一条或多条数据记录（callback形式）。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称       | 类型                                                         | 必填 | 描述                                                         |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| uri        | string                                                       | 是   | 指示要删除的数据的路径。                                     |
| predicates | [DataSharePredicates](js-apis-data-DataSharePredicates.md#datasharepredicates) | 是   | 指示筛选条件。当此参数为null时，应定义处理逻辑。（具体所支持的谓词方法取决于服务端所选用的数据库,如KVDB的删除目前仅支持inKeys谓词） |
| callback   | AsyncCallback&lt;number&gt;                                       | 是   | 回调方法，返回已删除的数据记录数。（能否返回已删除的数目取决于服务端所使用的数据库） |

**示例：**

```ts
let dataShareHelper;
let uri = ("datashare:///com.samples.datasharetest.DataShare");
let da = new dataShare.DataSharePredicates();
da.equalTo("name", "ZhangSan");
dataShareHelper.delete(uri, da, (err, data) => {
    if (err != undefined) {
        console.log("delete fail, error message : " + err);
    }else{
        console.log("delete end, data : " + data);
    }
});
```

### delete

delete(uri: string, predicates: DataSharePredicates): Promise&lt;number&gt;

从数据库中删除一条或多条数据记录（Promise形式）。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称       | 类型                                                         | 必填 | 描述                                                         |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| uri        | string                                                       | 是   | 指示要删除的数据的路径。                                     |
| predicates | [DataSharePredicates](js-apis-data-DataSharePredicates.md#datasharepredicates) | 是   | 指示筛选条件。当此参数为null时，应定义处理逻辑。（具体所支持的谓词方法取决于服务端所选用的数据库,如KVDB的删除目前仅支持inKeys谓词） |

**返回值：**

| 类型             | 说明                                                         |
| ---------------- | ------------------------------------------------------------ |
| Promise&lt;number&gt; | 返回已删除的数据记录数。（能否返回已删除的数目取决于服务端所使用的数据库） |

**示例：**

```ts
let dataShareHelper;
let uri = ("datashare:///com.samples.datasharetest.DataShare");
let da = new dataShare.DataSharePredicates();
da.equalTo("name", "ZhangSan");
dataShareHelper.delete(uri, da).then((data) => {
    console.log("delete end, data : " + data);
}).catch((err) => {
    console.log("delete fail, error message : " + err);
});
```

### update

update(uri: string, predicates: DataSharePredicates, value: ValuesBucket, callback: AsyncCallback&lt;number&gt;): void

更新数据库中的数据记录（callback形式）。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称       | 类型                                                         | 必填 | 描述                                                         |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| uri        | string                                                       | 是   | 指示要更新的数据的路径。                                     |
| predicates | [DataSharePredicates](js-apis-data-DataSharePredicates.md#datasharepredicates) | 是   | 指示筛选条件。当此参数为null时，应定义处理逻辑。（是否支持谓词取决于服务端所选用的数据库，如KVDB并不支持谓词，仅RDB支持） |
| value      | [ValuesBucket](js-apis-data-ValuesBucket.md#valuesbucket)    | 是   | 指示要更新的数据。                                           |
| callback   | AsyncCallback&lt;number&gt;                                       | 是   | 回调方法，返回更新的数据记录数。（能否返回更新的数据记录数取决于服务端所使用的数据库） |

**示例：**

```ts
let dataShareHelper;
let uri = ("datashare:///com.samples.datasharetest.DataShare");
let da = new dataShare.DataSharePredicates();
da.equalTo("name", "ZhangSan");
const va = {
    "name": "roe1",
    "age": 21,
    "salary": 20.5,
    "blobType": u8,
}
dataShareHelper.update(uri, da, va, (err, data) => {
    if (err != undefined) {
        console.log("update fail, error message : " + err);
    }else{
        console.log("update end, data : " + data);
    }
});
```

### update

update(uri: string, predicates: DataSharePredicates, value: ValuesBucket): Promise&lt;number&gt;

更新数据库中的数据记录（Promise形式）。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称       | 类型                                                         | 必填 | 描述                                                         |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| uri        | string                                                       | 是   | 指示要更新的数据的路径。                                     |
| predicates | [DataSharePredicates](js-apis-data-DataSharePredicates.md#datasharepredicates) | 是   | 指示筛选条件。当此参数为null时，应定义处理逻辑。（是否支持谓词取决于服务端所选用的数据库，如KVDB并不支持谓词，仅RDB支持） |
| value      | [ValuesBucket](js-apis-data-ValuesBucket.md#valuesbucket)    | 是   | 指示要更新的数据。                                           |

**返回值：**

| 类型             | 说明                                                         |
| ---------------- | ------------------------------------------------------------ |
| Promise&lt;number&gt; | 返回更新的数据记录数。（能否返回更新的数据记录数取决于服务端所使用的数据库） |

**示例：**

```ts
let dataShareHelper;
let uri = ("datashare:///com.samples.datasharetest.DataShare");
let da = new dataShare.DataSharePredicates();
da.equalTo("name", "ZhangSan");
const va = {
    "name": "roe1",
    "age": 21,
    "salary": 20.5,
    "blobType": u8,
}
dataShareHelper.update(uri, da, va).then((data) => {
    console.log("update end, data : " + data);
}).catch((err) => {
    console.log("update fail, error message : " + err);
});
```

### query

query(uri: string, predicates: DataSharePredicates, columns: Array&lt;string&gt;, callback: AsyncCallback&lt;DataShareResultSet&gt;): void

查询数据库中的数据（callback形式）。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称       | 类型                                                         | 必填 | 描述                                                         |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| uri        | string                                                       | 是   | 指示要查询的数据的路径。                                     |
| predicates | [DataSharePredicates](js-apis-data-DataSharePredicates.md#datasharepredicates) | 是   | 指示筛选条件。当此参数为null时，应定义处理逻辑。（具体所支持的谓词方法取决于服务端所选用的数据库，如KVDB目前仅支持inKeys和prefixKey） |
| columns    | Array&lt;string&gt;                                                | 是   | 指示要查询的列。如果此参数为空，则查询所有列。               |
| callback   | AsyncCallback&lt;[DataShareResultSet](js-apis-data-DataShareResultSet.md#datashareresultset)&gt; | 是   | 回调方法，返回查询结果。                                     |

**示例：**

```ts
let dataShareHelper;
let uri = ("datashare:///com.samples.datasharetest.DataShare");
let columns = ["*"]；
let da = new dataShare.DataSharePredicates();
da.equalTo("name", "ZhangSan");
dataShareHelper.query(uri, da, columns, (err, data) => {
    if (err != undefined) {
        console.log("query fail, error message : " + err);
    }else{
        console.log("query end, data : " + data);
    }
});
```



### query

query(uri: string, predicates: DataSharePredicates, columns: Array&lt;string&gt;): Promise&lt;DataShareResultSet&gt;

查询数据库中的数据（Promise形式）。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称       | 类型                                                         | 必填 | 描述                                                         |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| uri        | string                                                       | 是   | 指示要查询的数据的路径。                                     |
| predicates | [DataSharePredicates](js-apis-data-DataSharePredicates.md#datasharepredicates) | 是   | 指示筛选条件。当此参数为null时，应定义处理逻辑。（具体所支持的谓词方法取决于服务端所选用的数据库，如KVDB目前仅支持inKeys和prefixKey） |
| columns    | Array&lt;string&gt;                                                | 是   | 指示要查询的列。如果此参数为空，则查询所有列。               |

**返回值：**

| 类型                                                         | 说明           |
| ------------------------------------------------------------ | -------------- |
| Promise&lt;[DataShareResultSet](js-apis-data-DataShareResultSet.md#datashareresultset)&gt; | 返回查询结果。 |

**示例：**

```ts
let dataShareHelper;
let uri = ("datashare:///com.samples.datasharetest.DataShare");
let columns = ["*"]；
let da = new dataShare.DataSharePredicates();
da.equalTo("name", "ZhangSan");
dataShareHelper.query(uri, da, columns).then((data) => {
    console.log("query end, data : " + data);
}).catch((err) => {
    console.log("query fail, error message : " + err);
});
```
