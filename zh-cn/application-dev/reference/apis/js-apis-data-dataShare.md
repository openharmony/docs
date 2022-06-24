# DataShare

**DataShare**用于应用管理其自身数据，同时支持同个设备上不同应用间的数据共享。

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

创建DataShareHelper实例。使用callback异步回调。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 参数名   | 参数类型                                                 | 必填 | 说明                                        |
| -------- | -------------------------------------------------------- | ---- | ------------------------------------------- |
| context  | [Context](js-apis-application-context.md#context)        | 是   | 应用的上下文环境。                          |
| uri      | string                                                   | 是   | 指示要连接的服务端应用的路径。              |
| callback | AsyncCallback&lt;[DataShareHelper](#datasharehelper)&gt; | 是   | 回调函数。返回创建后的DataShareHelper实例。 |

**示例：**

```ts
import dataShare from '@ohos.data.dataShare'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let dataShareHelper;
dataShare.createDataShareHelper(this.context, uri, (err, data) => {
    if (err != undefined) {
        console.info("createDataShareHelper failed, error message : " + err);
    } else {
        console.info("createDataShareHelper succeed, data : " + data);
        dataShareHelper = data;
    }
});
```

## dataShare.createDataShareHelper

createDataShareHelper(context: Context, uri: string): Promise&lt;DataShareHelper&gt;

创建DataShareHelper实例。使用Promise异步回调。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 参数名  | 参数类型                                          | 必填 | 说明                           |
| ------- | ------------------------------------------------- | ---- | ------------------------------ |
| context | [Context](js-apis-application-context.md#context) | 是   | 应用的上下文环境。             |
| uri     | string                                            | 是   | 指示要连接的服务端应用的路径。 |

**返回值：**

| 类型                                               | 说明                                           |
| -------------------------------------------------- | ---------------------------------------------- |
| Promise&lt;[DataShareHelper](#datasharehelper)&gt; | Promise对象。返回创建后的DataShareHelper实例。 |

**示例：**

```ts
import dataShare from '@ohos.data.dataShare'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let dataShareHelper;
dataShare.createDataShareHelper(this.context, uri).then((data) => {
    console.info("createDataShareHelper succeed, data : " + data);
    dataShareHelper = data;
}).catch((err) => {
	console.info("createDataShareHelper failed, error message : " + err); 
})
```

## DataShareHelper

DataShare管理工具实例，可使用此实例访问或管理服务端的数据。在调用DataShareHelper提供的方法前，需要先通过[createDataShareHelper](#datasharecreatedatasharehelper)构建一个实例。

### openFile

openFile(uri: string, mode: string, callback: AsyncCallback&lt;number&gt;): void

打开指定路径的文件。使用callback异步回调。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称     | 类型                  | 必填 | 描述                               |
| -------- | --------------------- | ---- | ---------------------------------- |
| uri      | string                | 是   | 指示要打开的文件的路径。           |
| mode     | string                | 是   | 指示文件打开模式，如“r”表示只读访问，“w”表示只写访问（擦除文件中当前的任何数据），“wa”表示附加到任何现有数据的写访问，“rw”表示对任何现有数据的读写访问。 |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数。返回文件描述符。 |

**示例：**

```ts
let uri = ("datashare:///com.samples.datasharetest.DataShare");
dataShareHelper.openFile(uri, "rwt", (err, data) => {
    if (err != undefined) {
        console.info("openFile failed, error message : " + err);
    }erse {
        console.info("openFile succeed, data : " + data);
        let fd = data;
    }
});
```

### openFile

openFile(uri: string, mode: string): Promise&lt;number&gt;

打开指定路径的文件。使用Promise异步回调。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称 | 类型   | 必填 | 描述                                                         |
| ---- | ------ | ---- | ------------------------------------------------------------ |
| uri  | string | 是   | 指示要打开的文件的路径                                       |
| mode | string | 是   | 指示文件打开模式，如“r”表示只读访问，“w”表示只写访问（擦除文件中当前的任何数据），“wa”表示附加到任何现有数据的写访问，“rw”表示对任何现有数据的读写访问。 |

**返回值：**

| 类型            | 说明             |
| --------------- | ---------------- |
| Promise&lt;number&gt; | Promise对象。返回文件描述符。 |

**示例：**

```ts
let uri = ("datashare:///com.samples.datasharetest.DataShare");
dataShareHelper.openFile(uri, "rwt").then((data) => {
    console.info("openFile succeed, data : " + data);
    let fd = data;
}).catch((err) => {
	console.info("openFile failed, error message : " + err); 
})
```

### on('dataChange')

on(type: 'dataChange', uri: string, callback: AsyncCallback&lt;void&gt;): void

订阅指定URI对应数据的数据变更事件。若用户（订阅者）已注册了观察者，当有其他用户触发了变更通知时（调用了下文中的notifyChange方法），订阅者将会接收到callback通知。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称     | 类型                 | 必填 | 描述                     |
| -------- | -------------------- | ---- | ------------------------ |
| type     | string               | 是   | 订阅的事件/回调类型，支持的事件为'dataChange'，当数据更改时，触发该事件。 |
| uri      | string               | 是   | 表示指定的数据路径。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。本调用无返回值，当有其他用户触发了变更通知时调用。 |

**示例：**

```ts
function onCallback() {
    console.info("**** Observer on callback ****");
}
let uri = ("datashare:///com.samples.datasharetest.DataShare");
dataShareHelper.on("dataChange", uri, onCallback);
```

### off('dataChange')

off(type: 'dataChange', uri: string, callback?: AsyncCallback&lt;void&gt;): void

取消订阅指定URI对应的数据资源的变更通知。使用callback异步回调。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称     | 类型                 | 必填 | 描述                     |
| -------- | -------------------- | ---- | ------------------------ |
| type     | string               | 是   | 取消订阅的事件/回调类型，支持的事件为'dataChange'。 |
| uri      | string               | 是   | 表示指定的数据路径。 |
| callback | AsyncCallback&lt;void&gt; | 否   | 回调函数。本调用无返回值。 |

**示例：**

```ts
function offCallback() {
    console.info("**** Observer off callback ****");
}
let uri = ("datashare:///com.samples.datasharetest.DataShare");
dataShareHelper.off("dataChange", uri, offCallback);
```

### notifyChange

notifyChange(uri: string, callback: AsyncCallback&lt;void&gt;): void

通知已注册的观察者指定URI对应的数据资源已发生变更。使用callback异步回调。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称     | 类型                 | 必填 | 描述                     |
| -------- | -------------------- | ---- | ------------------------ |
| uri      | string               | 是   | 表示指定的数据路径。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。本调用无返回值。  |

**示例：**

```ts
let uri = ("datashare:///com.samples.datasharetest.DataShare");
dataShareHelper.notifyChange(uri, () => {
    console.log("***** notifyChange *****");
});
```

### notifyChange

notifyChange(uri: string): Promise&lt;void&gt;

通知已注册的观察者指定URI对应的数据资源已发生变更。使用Promise异步回调。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称 | 类型   | 必填 | 描述                 |
| ---- | ------ | ---- | -------------------- |
| uri  | string | 是   | 表示指定的数据路径。 |

**返回值：**

| 类型           | 说明                  |
| -------------- | --------------------- |
| Promise&lt;void&gt; | Promise对象。无返回值。 |

**示例：**

```ts
let uri = ("datashare:///com.samples.datasharetest.DataShare");
dataShareHelper.notifyChange(uri);
```

### getType

getType(uri: string, callback: AsyncCallback&lt;string&gt;): void

获取URI所指定的数据的MIME类型。使用callback异步回调。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称     | 类型                   | 必填 | 描述                                          |
| -------- | ---------------------- | ---- | --------------------------------------------- |
| uri      | string                 | 是   | 表示指定的数据路径。                      |
| callback | AsyncCallback&lt;string&gt; | 是   | 回调函数。返回与URI指定的数据匹配的MIME类型。 |

**示例：**

```ts
let uri = ("datashare:///com.samples.datasharetest.DataShare");
dataShareHelper.getType(uri, (err, data)=>{
    if (err != undefined) {
        console.log("getType failed, error message : " + err);
    }else{
        console.log("getType succeed, data : " + data);
        let result = data;
    }
});
```

### getType

getType(uri: string): Promise&lt;string&gt;

获取URI所指定数据的MIME类型。使用Promise异步回调。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称 | 类型   | 必填 | 描述                 |
| ---- | ------ | ---- | -------------------- |
| uri  | string | 是   | 表示指定的数据路径。 |

**返回值：**

| 类型             | 说明                                |
| ---------------- | ----------------------------------- |
| Promise&lt;string&gt; | Promise对象。返回与URI指定的数据匹配的MIME类型。 |

**示例：**

```ts
let uri = ("datashare:///com.samples.datasharetest.DataShare");
dataShareHelper.getType(uri).then((data) => {
    console.log("getType succeed, data : " + data);
}).catch((err) => {
    console.log("getType failed, error message : " + err);
});
```

### getFileTypes

getFileTypes(uri: string, mimeTypeFilter: string, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

获取支持的文件的MIME类型。使用callback异步回调。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称           | 类型                                     | 必填 | 描述                                                         |
| -------------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| uri            | string                                   | 是   | 指示要获取的文件的路径。                                     |
| mimeTypeFilter | string                                   | 是   | 指示要筛选的MIME类型。例如：<br />“\*/\*”：获取支持的所有类型。<br/>“image/\*”：获取主类型image，子类型为任何类型的MIME。<br />”\*/jpg”：获取子类型为jpg，主类型为任何类型的MIME。 |
| callback       | AsyncCallback&lt;Array&lt;string&gt;&gt; | 是   | 回调函数。返回匹配的MIME类型数组。                           |

**示例：**

```ts
let uri = ("datashare:///com.samples.datasharetest.DataShare");
let mimeTypeFilter = "image/*";
dataShareHelper.getFileTypes(uri, mimeTypeFilter, (err,data) => {
    if (err != undefined) {
        console.log("getFileTypes failed, error message : " + err);
    }else{
        console.log("getFileTypes succeed, data : " + data);
    }
});
```

### getFileTypes

getFileTypes(uri: string, mimeTypeFilter: string): Promise&lt;Array&lt;string&gt;&gt;

获取支持的文件的MIME类型。使用Promise异步回调。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称           | 类型   | 必填 | 描述                                                         |
| -------------- | ------ | ---- | ------------------------------------------------------------ |
| uri            | string | 是   | 指示要获取的文件的路径。                                     |
| mimeTypeFilter | string | 是   | 指示要筛选的MIME类型。例如：<br />“\*/\*”：获取支持的所有类型。<br/>“image/\*”：获取主类型image，子类型为任何类型的MIME。<br />”\*/jpg”：获取子类型为jpg，主类型为任何类型的MIME。 |

**返回值：**

| 类型                     | 说明                     |
| ------------------------ | ------------------------ |
| Promise&lt;Array&lt;string&gt;&gt; | Promise对象。返回匹配的MIME类型数组。 |

**示例：**

```ts
let uri = ("datashare:///com.samples.datasharetest.DataShare");
let mimeTypeFilter = "image/*";
dataShareHelper.getFileTypes(uri, mimeTypeFilter).then((data) => {
	console.log("getFileTypes succeed, data : " + data);
}).catch((err) => {
	console.log("getFileTypes failed, error message : " + err);
});
```

### normalizeUri

normalizeUri(uri: string, callback: AsyncCallback&lt;string&gt;): void

将给定的DataShare URI转换为规范化URI，规范化URI可供跨设备使用，DataShare  URI仅供本地环境中使用。使用callback异步回调。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称     | 类型                   | 必填 | 描述                                                     |
| -------- | ---------------------- | ---- | -------------------------------------------------------- |
| uri      | string                 | 是   | 指示要规范化的[URI](js-apis-uri.md#uri)。      |
| callback | AsyncCallback&lt;string&gt; | 是   | 回调函数。如果支持URI规范化，则返回规范化URI，否则返回空。 |

**示例：**

```ts
let uri = ("datashare:///com.samples.datasharetest.DataShare");
dataShareHelper.normalizeUri(uri, (err, data) => {
    if (err != undefined) {
        console.log("normalizeUri failed, error message : " + err);
    }else{
        console.log("normalizeUri = " + data);
    }
});
```

### normalizeUri

normalizeUri(uri: string): Promise&lt;string&gt;

将给定的DataShare URI转换为规范化URI，规范化URI可供跨设备使用，DataShare  URI仅供本地环境中使用。使用Promise异步回调。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称 | 类型   | 必填 | 描述                                      |
| ---- | ------ | ---- | ----------------------------------------- |
| uri  | string | 是   | 指示要规范化的[URI](js-apis-uri.md#uri)。 |

**返回值：**

| 类型             | 说明                                           |
| ---------------- | ---------------------------------------------- |
| Promise&lt;string&gt; | Promise对象。如果支持URI规范化，则返回规范化URI，否则返回空。 |

**示例：**

```ts
let uri = ("datashare:///com.samples.datasharetest.DataShare");
dataShareHelper.normalizeUri(uri).then((data) => {
    console.log("normalizeUri = " + data);
}).catch((err) => {
    console.log("normalizeUri failed, error message : " + err);
});
```

### denormalizeUri

denormalizeUri(uri: string, callback: AsyncCallback&lt;string&gt;): void

将指定的URI转换为非规范化URI。使用callback异步回调。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称     | 类型                   | 必填 | 描述                                                |
| -------- | ---------------------- | ---- | --------------------------------------------------- |
| uri      | string                 | 是   | 指示要反规范化的[URI](js-apis-uri.md#uri)。 |
| callback | AsyncCallback&lt;string&gt; | 是   | 回调函数。如果反规范化成功，则返回反规范化的URI；如果无需进行反规范化，则返回原始URI；若不支持则返回空。 |

**示例：**

```ts
let uri = ("datashare:///com.samples.datasharetest.DataShare");
dataShareHelper.denormalizeUri(uri, (err, data) => {
    if (err != undefined) {
        console.log("denormalizeUri failed, error message : " + err);
    }else{
        console.log("denormalizeUri = " + data);
    }
});
```

### denormalizeUri

denormalizeUri(uri: string): Promise&lt;string&gt;

将指定的URI转换为非规范化URI。使用Promise异步回调。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称 | 类型   | 必填 | 描述                                        |
| ---- | ------ | ---- | ------------------------------------------- |
| uri  | string | 是   | 指示要反规范化的[URI](js-apis-uri.md#uri)。 |

**返回值：**

| 类型             | 说明                                      |
| ---------------- | ----------------------------------------- |
| Promise&lt;string&gt; | Promise对象。如果反规范化成功，则返回反规范化的URI；如果无需执行任何操作，则返回原始URI；若不支持则返回空。 |

**示例：**

```ts
let uri = ("datashare:///com.samples.datasharetest.DataShare");
dataShareHelper.denormalizeUri(uri).then((data) => {
    console.log("denormalizeUri = " + data);
}).catch((err) => {
    console.log("denormalizeUri failed, error message : " + err);
});
```

### insert

insert(uri: string, value: ValuesBucket, callback: AsyncCallback&lt;number&gt;): void

将单条数据插入数据库。使用callback异步回调。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称     | 类型                                                      | 必填 | 描述                                                         |
| -------- | --------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| uri      | string                                                    | 是   | 指示要插入的数据的路径。                                     |
| value    | [ValuesBucket](js-apis-data-ValuesBucket.md#valuesbucket) | 是   | 指示要插入的数据。如果此参数为空，将插入一个空行。           |
| callback | AsyncCallback&lt;number&gt;                               | 是   | 回调函数。返回插入数据记录的索引。<br />因部分数据库（如KVDB）的相应接口并不支持返回索引，故若服务端使用了不支持索引的数据库，则此callback也无法返回索引值。 |

**示例：**

```ts
let uri = ("datashare:///com.samples.datasharetest.DataShare");
const valueBucket = {
    "name": "rose",
    "age": 22,
    "salary": 200.5,
}
dataShareHelper.insert(uri, valueBucket, (err, data) => {
    if (err != undefined) {
        console.log("insert failed, error message : " + err);
    }else{
        console.log("insert succeed, data : " + data);
    }
});
```

### insert

insert(uri: string, value: ValuesBucket): Promise&lt;number&gt;

将单条数据插入数据库。使用Promise异步回调。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称  | 类型                                                      | 必填 | 描述                                               |
| ----- | --------------------------------------------------------- | ---- | -------------------------------------------------- |
| uri   | string                                                    | 是   | 指示要插入的数据的路径。                           |
| value | [ValuesBucket](js-apis-data-ValuesBucket.md#valuesbucket) | 是   | 指示要插入的数据。如果此参数为空，将插入一个空行。 |

**返回值：**

| 类型             | 说明                                                         |
| ---------------- | ------------------------------------------------------------ |
| Promise&lt;number&gt; | Promise对象。返回插入数据记录的索引。<br />因部分数据库（如KVDB）的相应接口并不支持返回索引，故若服务端使用了不支持索引的数据库，则此Promise也无法返回索引值。 |

**示例：**

```ts
let uri = ("datashare:///com.samples.datasharetest.DataShare");
const valueBucket = {
    "name": "rose1",
    "age": 221,
    "salary": 20.5,
}
dataShareHelper.insert(uri, valueBucket).then((data) => {
    console.log("insert succeed, data : " + data);
}).catch((err) => {
    console.log("insert failed, error message : " + err);
});
```

### batchInsert

batchInsert(uri: string, values: Array&lt;ValuesBucket&gt;, callback: AsyncCallback&lt;number&gt;): void

将批量数据插入数据库。使用callback异步回调。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称     | 类型                                                         | 必填 | 描述                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| uri      | string                                                       | 是   | 指示要插入的数据的路径。                                     |
| values   | Array&lt;[ValuesBucket](js-apis-data-ValuesBucket.md#valuesbucket)&gt; | 是   | 指示要插入的数据。                                           |
| callback | AsyncCallback&lt;number&gt;                                  | 是   | 回调函数。返回插入的数据记录数。<br />因部分数据库（如KVDB）的相应接口并不提供相应支持，故若服务端使用此数据库，则此Promise也无法返回插入的数据记录数。 |

**示例：**

```ts
let uri = ("datashare:///com.samples.datasharetest.DataShare");
let vbs = new Array({"name": "roe11", "age": 21, "salary": 20.5,},
                     {"name": "roe12", "age": 21, "salary": 20.5,},
                     {"name": "roe13", "age": 21, "salary": 20.5,})
dataShareHelper.batchInsert(uri, vbs, (err, data) => {
    if (err != undefined) {
        console.log("batchInsert failed, error message : " + err);
    }else{
        console.log("batchInsert succeed, data : " + data);
    }
});
```

### batchInsert

batchInsert(uri: string, values: Array&lt;ValuesBucket&gt;): Promise&lt;number&gt;

将批量数据插入数据库。使用Promise异步回调。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称   | 类型                                                         | 必填 | 描述                     |
| ------ | ------------------------------------------------------------ | ---- | ------------------------ |
| uri    | string                                                       | 是   | 指示要插入的数据的路径。 |
| values | Array&lt;[ValuesBucket](js-apis-data-ValuesBucket.md#valuesbucket)&gt; | 是   | 指示要插入的数据。       |

**返回值：**

| 类型             | 说明                                                         |
| ---------------- | ------------------------------------------------------------ |
| Promise&lt;number&gt; | Promise对象。返回插入的数据记录数。<br />因部分数据库（如KVDB）的相应接口并不提供相应支持，故若服务端使用此数据库，则此Promise也无法返回插入的数据记录数。 |

**示例：**

```ts
let uri = ("datashare:///com.samples.datasharetest.DataShare");
let vbs = new Array({"name": "roe11", "age": 21, "salary": 20.5,},
                     {"name": "roe12", "age": 21, "salary": 20.5,},
                     {"name": "roe13", "age": 21, "salary": 20.5,})
dataShareHelper.batchInsert(uri, vbs).then((data) => {
    console.log("batchInsert succeed, data : " + data);
}).catch((err) => {
    console.log("batchInsert failed, error message : " + err);
});
```

### delete

delete(uri: string, predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback&lt;number&gt;): void

从数据库中删除一条或多条数据记录。使用callback异步回调。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称       | 类型                                                         | 必填 | 描述                                                         |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| uri        | string                                                       | 是   | 指示要删除的数据的路径。                                     |
| predicates | [DataSharePredicates](js-apis-data-DataSharePredicates.md#datasharepredicates) | 是   | 指示筛选条件。<br />delete接口所支持的谓词方法取决于服务端所选用的数据库，如KVDB的删除目前仅支持inKeys谓词。 |
| callback   | AsyncCallback&lt;number&gt;                                  | 是   | 回调函数。返回已删除的数据记录数。<br />因部分数据库（如KVDB）的相应接口并不提供相应支持，故若服务端使用此数据库，则此callback也无法返回删除的数据记录数。 |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let da = new dataSharePredicates.DataSharePredicates();
da.equalTo("name", "ZhangSan");
dataShareHelper.delete(uri, da, (err, data) => {
    if (err != undefined) {
        console.log("delete failed, error message : " + err);
    }else{
        console.log("delete succeed, data : " + data);
    }
});
```

### delete

delete(uri: string, predicates: dataSharePredicates.DataSharePredicates): Promise&lt;number&gt;

从数据库中删除一条或多条数据记录。使用Promise异步回调。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称       | 类型                                                         | 必填 | 描述                                                         |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| uri        | string                                                       | 是   | 指示要删除的数据的路径。                                     |
| predicates | [DataSharePredicates](js-apis-data-DataSharePredicates.md#datasharepredicates) | 是   | 指示筛选条件。<br />delete接口所支持的谓词方法取决于服务端所选用的数据库，如KVDB的删除目前仅支持inKeys谓词。 |

**返回值：**

| 类型             | 说明                                                         |
| ---------------- | ------------------------------------------------------------ |
| Promise&lt;number&gt; | Promise对象。返回已删除的数据记录数。<br />因部分数据库（如KVDB）的相应接口并不提供相应支持，故若服务端使用此数据库，则此Promise也无法返回删除的数据记录数。 |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let da = new dataSharePredicates.DataSharePredicates();
da.equalTo("name", "ZhangSan");
dataShareHelper.delete(uri, da).then((data) => {
    console.log("delete succeed, data : " + data);
}).catch((err) => {
    console.log("delete failed, error message : " + err);
});
```

### update

update(uri: string, predicates: dataSharePredicates.DataSharePredicates, value: ValuesBucket, callback: AsyncCallback&lt;number&gt;): void

更新数据库中的数据记录。使用callback异步回调。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称       | 类型                                                         | 必填 | 描述                                                         |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| uri        | string                                                       | 是   | 指示要更新的数据的路径。                                     |
| predicates | [DataSharePredicates](js-apis-data-DataSharePredicates.md#datasharepredicates) | 是   | 指示筛选条件。<br />update接口是否支持谓词筛选条件取决于服务端所选用的数据库，如KVDB目前并不支持谓词筛选条件，仅RDB支持。 |
| value      | [ValuesBucket](js-apis-data-ValuesBucket.md#valuesbucket)    | 是   | 指示要更新的数据。                                           |
| callback   | AsyncCallback&lt;number&gt;                                  | 是   | 回调函数。返回更新的数据记录数。<br />因部分数据库（如KVDB）的相应接口并不提供相应支持，故若服务端使用此数据库，则此callback也无法返回更新的数据记录数。 |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let da = new dataSharePredicates.DataSharePredicates();
da.equalTo("name", "ZhangSan");
const va = {
    "name": "roe1",
    "age": 21,
    "salary": 20.5,
   
}
dataShareHelper.update(uri, da, va, (err, data) => {
    if (err != undefined) {
        console.log("update failed, error message : " + err);
    }else{
        console.log("update succeed, data : " + data);
    }
});
```

### update

update(uri: string, predicates: dataSharePredicates.DataSharePredicates, value: ValuesBucket): Promise&lt;number&gt;

更新数据库中的数据记录。使用Promise异步回调。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称       | 类型                                                         | 必填 | 描述                                                         |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| uri        | string                                                       | 是   | 指示要更新的数据的路径。                                     |
| predicates | [DataSharePredicates](js-apis-data-DataSharePredicates.md#datasharepredicates) | 是   | 指示筛选条件。<br />update接口是否支持谓词筛选条件取决于服务端所选用的数据库，如KVDB目前并不支持谓词筛选条件，仅RDB支持。 |
| value      | [ValuesBucket](js-apis-data-ValuesBucket.md#valuesbucket)    | 是   | 指示要更新的数据。                                           |

**返回值：**

| 类型             | 说明                                                         |
| ---------------- | ------------------------------------------------------------ |
| Promise&lt;number&gt; | Promise对象。返回更新的数据记录数。<br />因部分数据库（如KVDB）的相应接口并不提供相应支持，故若服务端使用此数据库，则此Promise也无法返回更新的数据记录数。 |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let da = new dataSharePredicates.DataSharePredicates();
da.equalTo("name", "ZhangSan");
const va = {
    "name": "roe1",
    "age": 21,
    "salary": 20.5,
   
}
dataShareHelper.update(uri, da, va).then((data) => {
    console.log("update succeed, data : " + data);
}).catch((err) => {
    console.log("update failed, error message : " + err);
});
```

### query

query(uri: string, predicates: dataSharePredicates.DataSharePredicates, columns: Array&lt;string&gt;, callback: AsyncCallback&lt;DataShareResultSet&gt;): void

查询数据库中的数据。使用callback异步回调。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称       | 类型                                                         | 必填 | 描述                                                         |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| uri        | string                                                       | 是   | 指示要查询的数据的路径。                                     |
| predicates | [DataSharePredicates](js-apis-data-DataSharePredicates.md#datasharepredicates) | 是   | 指示筛选条件。<br />query接口所支持的谓词方法取决于服务端所选用的数据库，如KVDB目前仅支持inKeys和prefixKey。 |
| columns    | Array&lt;string&gt;                                          | 是   | 指示要查询的列。如果此参数为空，则查询所有列。               |
| callback   | AsyncCallback&lt;[DataShareResultSet](js-apis-data-DataShareResultSet.md#datashareresultset)&gt; | 是   | 回调函数。返回查询到的结果集。                               |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let columns = ["*"];
let da = new dataSharePredicates.DataSharePredicates();
da.equalTo("name", "ZhangSan");
dataShareHelper.query(uri, da, columns, (err, data) => {
    if (err != undefined) {
        console.log("query failed, error message : " + err);
    }else{
        console.log("query succeed, rowCount : " + data.rowCount);
    }
});
```

### query

query(uri: string, predicates: dataSharePredicates.DataSharePredicates, columns: Array&lt;string&gt;): Promise&lt;DataShareResultSet&gt;

查询数据库中的数据。使用Promise异步回调。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 名称       | 类型                                                         | 必填 | 描述                                                         |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| uri        | string                                                       | 是   | 指示要查询的数据的路径。                                     |
| predicates | [DataSharePredicates](js-apis-data-DataSharePredicates.md#datasharepredicates) | 是   | 指示筛选条件。<br />query接口所支持的谓词方法取决于服务端所选用的数据库，如KVDB目前仅支持inKeys和prefixKey。 |
| columns    | Array&lt;string&gt;                                          | 是   | 指示要查询的列。如果此参数为空，则查询所有列。               |

**返回值：**

| 类型                                                         | 说明                              |
| ------------------------------------------------------------ | --------------------------------- |
| Promise&lt;[DataShareResultSet](js-apis-data-DataShareResultSet.md#datashareresultset)&gt; | Promise对象。返回查询到的结果集。 |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let columns = ["*"];
let da = new dataSharePredicates.DataSharePredicates();
da.equalTo("name", "ZhangSan");
dataShareHelper.query(uri, da, columns).then((data) => {
    console.log("query succeed, rowCount : " + data.rowCount);
}).catch((err) => {
    console.log("query failed, error message : " + err);
});
```
