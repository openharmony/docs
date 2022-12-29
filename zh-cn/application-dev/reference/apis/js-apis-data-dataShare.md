# @ohos.data.dataShare (数据共享)

**DataShare**用于应用管理其自身数据，同时支持同个设备上不同应用间的数据共享。

> **说明：** 
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口为系统接口。
>
> 本模块接口仅可在Stage模型下使用。


## 导入模块

```ts
import dataShare from '@ohos.data.dataShare'
```


## dataShare.createDataShareHelper

createDataShareHelper(context: Context, uri: string, callback: AsyncCallback&lt;DataShareHelper&gt;): void

创建DataShareHelper实例。使用callback异步回调。

使用规则：
 - 调用方应用位于后台时，使用该接口访问DataShareExtension需申请`ohos.permission.START_ABILITIES_FROM_BACKGROUND`权限
 - 跨应用场景下，目标DataShareExtension的visible属性若配置为false，调用方应用需申请`ohos.permission.START_INVISIBLE_ABILITY`权限
 - 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                                         |
| -------- | -------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| context  | [Context](js-apis-application-context.md#context)        | 是   | 应用的上下文环境。                                           |
| uri      | string                                                   | 是   | 指示要连接的服务端应用的路径。                               |
| callback | AsyncCallback&lt;[DataShareHelper](#datasharehelper)&gt; | 是   | 回调函数。当创建DataShareHelper实例成功，err为undefined，data为获取到的DataShareHelper实例；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[数据共享错误码](../errorcodes/errorcode-datashare.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 15700010 | The dataShareHelper is not initialized successfully. |

**示例：**

```ts
import Ability from '@ohos.application.Ability'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let dataShareHelper;
try {
    dataShare.createDataShareHelper(this.context, uri, (err, data) => {
        if (err != undefined) {
            console.error(`createDataShareHelper error: code: ${err.code}, message: ${err.message} `);
            return;
        }
        console.info("createDataShareHelper succeed, data : " + data);
        dataShareHelper = data;
    });
} catch (err) {
    console.error(`createDataShareHelper error: code: ${err.code}, message: ${err.message} `);
};
```

## dataShare.createDataShareHelper

createDataShareHelper(context: Context, uri: string): Promise&lt;DataShareHelper&gt;

创建DataShareHelper实例。使用Promise异步回调。

使用规则：
 - 调用方应用位于后台时，使用该接口访问DataShareExtension需申请`ohos.permission.START_ABILITIES_FROM_BACKGROUND`权限
 - 跨应用场景下，目标DataShareExtension的visible属性若配置为false，调用方应用需申请`ohos.permission.START_INVISIBLE_ABILITY`权限
 - 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 参数名  | 类型                                          | 必填 | 说明                           |
| ------- | ------------------------------------------------- | ---- | ------------------------------ |
| context | [Context](js-apis-application-context.md#context) | 是   | 应用的上下文环境。             |
| uri     | string                                            | 是   | 指示要连接的服务端应用的路径。 |

**返回值：**

| 类型                                               | 说明                                   |
| -------------------------------------------------- | -------------------------------------- |
| Promise&lt;[DataShareHelper](#datasharehelper)&gt; | Promise对象。返回DataShareHelper实例。 |

**错误码：**

以下错误码的详细介绍请参见[数据共享错误码](../errorcodes/errorcode-datashare.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 15700010 | The dataShareHelper is not initialized successfully. |

**示例：**

```ts
import Ability from '@ohos.application.Ability'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let dataShareHelper;
try {
    dataShare.createDataShareHelper(this.context, uri).then((data) => {
        console.info("createDataShareHelper succeed, data : " + data);
        dataShareHelper = data;
    }). catch((err) => {
        console.error(`createDataShareHelper error: code: ${err.code}, message: ${err.message} `);
    });
} catch (err) {
    console.error(`createDataShareHelper error: code: ${err.code}, message: ${err.message} `);
};
```

## DataShareHelper

DataShare管理工具实例，可使用此实例访问或管理服务端的数据。在调用DataShareHelper提供的方法前，需要先通过[createDataShareHelper](#datasharecreatedatasharehelper)构建一个实例。

### on('dataChange')

on(type: 'dataChange', uri: string, callback: AsyncCallback&lt;void&gt;): void

订阅指定URI对应数据的数据变更事件。若用户（订阅者）已注册了观察者，当有其他用户触发了变更通知时（调用了下文中的notifyChange方法），订阅者将会接收到callback通知。使用callback异步回调。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 参数名     | 类型                 | 必填 | 说明                    |
| -------- | -------------------- | ---- | ------------------------ |
| type     | string               | 是   | 订阅的事件/回调类型，支持的事件为'dataChange'，当数据更改时，触发该事件。 |
| uri      | string               | 是   | 表示指定的数据路径。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。当有其他用户触发了变更通知时调用，err为undefined；否则不被触发或为错误对象。 |

**示例：**

```ts
import Ability from '@ohos.application.Ability'
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

| 参数名     | 类型                 | 必填 | 说明                    |
| -------- | -------------------- | ---- | ------------------------ |
| type     | string               | 是   | 取消订阅的事件/回调类型，支持的事件为'dataChange'。 |
| uri      | string               | 是   | 表示指定的数据路径。 |
| callback | AsyncCallback&lt;void&gt; | 否   | 回调函数。当取消订阅指定URI对应的数据资源的变更通知成功，err为undefined；否则为错误对象。 |

**示例：**

```ts
import Ability from '@ohos.application.Ability'
function offCallback() {
    console.info("**** Observer off callback ****");
}
let uri = ("datashare:///com.samples.datasharetest.DataShare");
dataShareHelper.off("dataChange", uri, offCallback);
```

### insert

insert(uri: string, value: ValuesBucket, callback: AsyncCallback&lt;number&gt;): void

将单条数据插入数据库。使用callback异步回调。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 参数名     | 类型                                                      | 必填 | 说明                                                        |
| -------- | --------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| uri      | string                                                    | 是   | 指示要插入的数据的路径。                                     |
| value    | [ValuesBucket](js-apis-data-valuesBucket.md#valuesbucket) | 是   | 指示要插入的数据。如果此参数为空，将插入一个空行。           |
| callback | AsyncCallback&lt;number&gt;                               | 是   | 回调函数。当将单条数据插入数据库成功，err为undefined，data为获取到的插入数据记录的索引；否则为错误对象。<br />因部分数据库（如KVDB）的相应接口并不支持返回索引，故若服务端使用了不支持索引的数据库，则此callback也无法返回索引值。 |

**示例：**

```ts
import Ability from '@ohos.application.Ability'
let uri = ("datashare:///com.samples.datasharetest.DataShare");
const valueBucket = {
    "name": "rose",
    "age": 22,
    "salary": 200.5,
}
try {
    dataShareHelper.insert(uri, valueBucket, (err, data) => {
        if (err != undefined) {
            console.error(`insert error: code: ${err.code}, message: ${err.message} `);
            return;
        }
        console.info("insert succeed, data : " + data);
    });
} catch (err) {
    console.error(`insert error: code: ${err.code}, message: ${err.message} `);
};
```

### insert

insert(uri: string, value: ValuesBucket): Promise&lt;number&gt;

将单条数据插入数据库。使用Promise异步回调。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 参数名  | 类型                                                      | 必填 | 说明                                               |
| ----- | --------------------------------------------------------- | ---- | -------------------------------------------------- |
| uri   | string                                                    | 是   | 指示要插入的数据的路径。                           |
| value | [ValuesBucket](js-apis-data-valuesBucket.md#valuesbucket) | 是   | 指示要插入的数据。如果此参数为空，将插入一个空行。 |

**返回值：**

| 类型             | 说明                                                         |
| ---------------- | ------------------------------------------------------------ |
| Promise&lt;number&gt; | Promise对象。返回插入数据记录的索引。<br />因部分数据库（如KVDB）的相应接口并不支持返回索引，故若服务端使用了不支持索引的数据库，则此Promise也无法返回索引值。 |

**示例：**

```ts
import Ability from '@ohos.application.Ability'
let uri = ("datashare:///com.samples.datasharetest.DataShare");
const valueBucket = {
    "name": "rose1",
    "age": 221,
    "salary": 20.5,
}
try {
    dataShareHelper.insert(uri, valueBucket).then((data) => {
        console.log("insert succeed, data : " + data);
    }). catch((err) => {
        console.error(`insert error: code: ${err.code}, message: ${err.message} `);
    });
} catch (err) {
    console.error(`insert error: code: ${err.code}, message: ${err.message} `);
};
```

### delete

delete(uri: string, predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback&lt;number&gt;): void

从数据库中删除一条或多条数据记录。使用callback异步回调。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 参数名       | 类型                                                         | 必填 | 说明                                                         |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| uri        | string                                                       | 是   | 指示要删除的数据的路径。                                     |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | 是   | 指示筛选条件。<br />delete接口所支持的谓词方法取决于服务端所选用的数据库，如KVDB的删除目前仅支持inKeys谓词。 |
| callback   | AsyncCallback&lt;number&gt;                                  | 是   | 回调函数。当从数据库中删除一条或多条数据记录成功，err为undefined，data为获取到的已删除的数据记录数；否则为错误对象。<br />因部分数据库（如KVDB）的相应接口并不提供相应支持，故若服务端使用此数据库，则此callback也无法返回删除的数据记录数。 |

**示例：**

```ts
import Ability from '@ohos.application.Ability'
import dataSharePredicates from '@ohos.data.dataSharePredicates'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let da = new dataSharePredicates.DataSharePredicates();
da.equalTo("name", "ZhangSan");
try {
    dataShareHelper.delete(uri, da, (err, data) => {
        if (err != undefined) {
            console.error(`delete error: code: ${err.code}, message: ${err.message} `);
            return;
        }
        console.info("delete succeed, data : " + data);
    });
} catch (err) {
    console.error(`delete error: code: ${err.code}, message: ${err.message} `);
};
```

### delete

delete(uri: string, predicates: dataSharePredicates.DataSharePredicates): Promise&lt;number&gt;

从数据库中删除一条或多条数据记录。使用Promise异步回调。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 参数名       | 类型                                                         | 必填 | 说明                                                         |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| uri        | string                                                       | 是   | 指示要删除的数据的路径。                                     |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | 是   | 指示筛选条件。<br />delete接口所支持的谓词方法取决于服务端所选用的数据库，如KVDB的删除目前仅支持inKeys谓词。 |

**返回值：**

| 类型             | 说明                                                         |
| ---------------- | ------------------------------------------------------------ |
| Promise&lt;number&gt; | Promise对象。返回已删除的数据记录数。<br />因部分数据库（如KVDB）的相应接口并不提供相应支持，故若服务端使用此数据库，则此Promise也无法返回删除的数据记录数。 |

**示例：**

```ts
import Ability from '@ohos.application.Ability'
import dataSharePredicates from '@ohos.data.dataSharePredicates'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let da = new dataSharePredicates.DataSharePredicates();
da.equalTo("name", "ZhangSan");
try {
    dataShareHelper.delete(uri, da).then((data) =>  {
        console.log("delete succeed, data : " + data);
    }). catch((err) => {
        console.error(`delete error: code: ${err.code}, message: ${err.message} `);
    });
} catch (err) {
    console.error(`delete error: code: ${err.code}, message: ${err.message} `);
};
```

### query

query(uri: string, predicates: dataSharePredicates.DataSharePredicates, columns: Array&lt;string&gt;, callback: AsyncCallback&lt;DataShareResultSet&gt;): void

查询数据库中的数据。使用callback异步回调。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 参数名       | 类型                                                         | 必填 | 说明                                                         |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| uri        | string                                                       | 是   | 指示要查询的数据的路径。                                     |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | 是   | 指示筛选条件。<br />query接口所支持的谓词方法取决于服务端所选用的数据库，如KVDB目前仅支持inKeys和prefixKey。 |
| columns    | Array&lt;string&gt;                                          | 是   | 指示要查询的列。如果此参数为空，则查询所有列。               |
| callback   | AsyncCallback&lt;[DataShareResultSet](js-apis-data-DataShareResultSet.md#datashareresultset)&gt; | 是   | 回调函数。当查询数据库中的数据成功，err为undefined，data为获取到的查询到的结果集；否则为错误对象。 |

**示例：**

```ts
import Ability from '@ohos.application.Ability'
import dataSharePredicates from '@ohos.data.dataSharePredicates'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let columns = ["*"];
let da = new dataSharePredicates.DataSharePredicates();
da.equalTo("name", "ZhangSan");
try {
    dataShareHelper.query(uri, da, columns, (err, data) => {
        if (err != undefined) {
            console.error(`query error: code: ${err.code}, message: ${err.message} `);
            return;
        }
        console.log("query succeed, rowCount : " + data.rowCount);
    });
} catch (err) {
    console.error(`query error: code: ${err.code}, message: ${err.message} `);
};
```

### query

query(uri: string, predicates: dataSharePredicates.DataSharePredicates, columns: Array&lt;string&gt;): Promise&lt;DataShareResultSet&gt;

查询数据库中的数据。使用Promise异步回调。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 参数名       | 类型                                                         | 必填 | 说明                                                         |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| uri        | string                                                       | 是   | 指示要查询的数据的路径。                                     |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | 是   | 指示筛选条件。<br />query接口所支持的谓词方法取决于服务端所选用的数据库，如KVDB目前仅支持inKeys和prefixKey。 |
| columns    | Array&lt;string&gt;                                          | 是   | 指示要查询的列。如果此参数为空，则查询所有列。               |

**返回值：**

| 类型                                                         | 说明                              |
| ------------------------------------------------------------ | --------------------------------- |
| Promise&lt;[DataShareResultSet](js-apis-data-DataShareResultSet.md#datashareresultset)&gt; | Promise对象。返回查询到的结果集。 |

**示例：**

```ts
import Ability from '@ohos.application.Ability'
import dataSharePredicates from '@ohos.data.dataSharePredicates'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let columns = ["*"];
let da = new dataSharePredicates.DataSharePredicates();
da.equalTo("name", "ZhangSan");
try {
    dataShareHelper.query(uri, da, columns).then((data) =>  {
        console.log("query succeed, rowCount : " + data.rowCount);
    }). catch((err) => {
        console.error(`query error: code: ${err.code}, message: ${err.message} `);
    });
} catch (err) {
    console.error(`query error: code: ${err.code}, message: ${err.message} `);
};
```

### update

update(uri: string, predicates: dataSharePredicates.DataSharePredicates, value: ValuesBucket, callback: AsyncCallback&lt;number&gt;): void

更新数据库中的数据记录。使用callback异步回调。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 参数名       | 类型                                                         | 必填 | 说明                                                         |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| uri        | string                                                       | 是   | 指示要更新的数据的路径。                                     |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | 是   | 指示筛选条件。<br />update接口是否支持谓词筛选条件取决于服务端所选用的数据库，如KVDB目前并不支持谓词筛选条件，仅RDB支持。 |
| value      | [ValuesBucket](js-apis-data-valuesBucket.md#valuesbucket)    | 是   | 指示要更新的数据。                                           |
| callback   | AsyncCallback&lt;number&gt;                                  | 是   | 回调函数。当更新数据库中的数据记录成功，err为undefined，data为获取到的更新的数据记录数；否则为错误对象。<br />因部分数据库（如KVDB）的相应接口并不提供相应支持，故若服务端使用此数据库，则此callback也无法返回更新的数据记录数。 |

**示例：**

```ts
import Ability from '@ohos.application.Ability'
import dataSharePredicates from '@ohos.data.dataSharePredicates'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let da = new dataSharePredicates.DataSharePredicates();
da.equalTo("name", "ZhangSan");
const va = {
    "name": "roe1",
    "age": 21,
    "salary": 20.5,
   
}
try {
    dataShareHelper.update(uri, da, va, (err, data) => {
        if (err != undefined) {
            console.error(`update error: code: ${err.code}, message: ${err.message} `);
            return;
        }
        console.log("update succeed, data : " + data);
    });
} catch (err) {
    console.error(`update error: code: ${err.code}, message: ${err.message} `);
};
```

### update

update(uri: string, predicates: dataSharePredicates.DataSharePredicates, value: ValuesBucket): Promise&lt;number&gt;

更新数据库中的数据记录。使用Promise异步回调。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 参数名       | 类型                                                         | 必填 | 说明                                                         |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| uri        | string                                                       | 是   | 指示要更新的数据的路径。                                     |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | 是   | 指示筛选条件。<br />update接口是否支持谓词筛选条件取决于服务端所选用的数据库，如KVDB目前并不支持谓词筛选条件，仅RDB支持。 |
| value      | [ValuesBucket](js-apis-data-valuesBucket.md#valuesbucket)    | 是   | 指示要更新的数据。                                           |

**返回值：**

| 类型             | 说明                                                         |
| ---------------- | ------------------------------------------------------------ |
| Promise&lt;number&gt; | Promise对象。返回更新的数据记录数。<br />因部分数据库（如KVDB）的相应接口并不提供相应支持，故若服务端使用此数据库，则此Promise也无法返回更新的数据记录数。 |

**示例：**

```ts
import Ability from '@ohos.application.Ability'
import dataSharePredicates from '@ohos.data.dataSharePredicates'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let da = new dataSharePredicates.DataSharePredicates();
da.equalTo("name", "ZhangSan");
const va = {
    "name": "roe1",
    "age": 21,
    "salary": 20.5,
   
}
try {
    dataShareHelper.update(uri, da, va).then((data) =>  {
        console.log("update succeed, data : " + data);
    }). catch((err) => {
        console.error(`update error: code: ${err.code}, message: ${err.message} `);
    });
} catch (err) {
    console.error(`update error: code: ${err.code}, message: ${err.message} `);
};
```

### batchInsert

batchInsert(uri: string, values: Array&lt;ValuesBucket&gt;, callback: AsyncCallback&lt;number&gt;): void

将批量数据插入数据库。使用callback异步回调。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| uri      | string                                                       | 是   | 指示要插入的数据的路径。                                     |
| values   | Array&lt;[ValuesBucket](js-apis-data-valuesBucket.md#valuesbucket)&gt; | 是   | 指示要插入的数据。                                           |
| callback | AsyncCallback&lt;number&gt;                                  | 是   | 回调函数。当将批量数据插入数据库成功，err为undefined，data为获取到的插入的数据记录数；否则为错误对象。<br />因部分数据库（如KVDB）的相应接口并不提供相应支持，故若服务端使用此数据库，则此Promise也无法返回插入的数据记录数。 |

**示例：**

```ts
import Ability from '@ohos.application.Ability'
let uri = ("datashare:///com.samples.datasharetest.DataShare");
let vbs = new Array({"name": "roe11", "age": 21, "salary": 20.5,},
                     {"name": "roe12", "age": 21, "salary": 20.5,},
                     {"name": "roe13", "age": 21, "salary": 20.5,})
try {
    dataShareHelper.batchInsert(uri, vbs, (err, data) => {
        if (err != undefined) {
            console.error(`batchInsert error: code: ${err.code}, message: ${err.message} `);
            return;
        }
        console.log("batchInsert succeed, data : " + data);
    });
} catch (err) {
    console.error(`batchInsert error: code: ${err.code}, message: ${err.message} `);
};
```

### batchInsert

batchInsert(uri: string, values: Array&lt;ValuesBucket&gt;): Promise&lt;number&gt;

将批量数据插入数据库。使用Promise异步回调。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                     |
| ------ | ------------------------------------------------------------ | ---- | ------------------------ |
| uri    | string                                                       | 是   | 指示要插入的数据的路径。 |
| values | Array&lt;[ValuesBucket](js-apis-data-valuesBucket.md#valuesbucket)&gt; | 是   | 指示要插入的数据。       |

**返回值：**

| 类型             | 说明                                                         |
| ---------------- | ------------------------------------------------------------ |
| Promise&lt;number&gt; | Promise对象。返回插入的数据记录数。<br />因部分数据库（如KVDB）的相应接口并不提供相应支持，故若服务端使用此数据库，则此Promise也无法返回插入的数据记录数。 |

**示例：**

```ts
import Ability from '@ohos.application.Ability'
let uri = ("datashare:///com.samples.datasharetest.DataShare");
let vbs = new Array({"name": "roe11", "age": 21, "salary": 20.5,},
                     {"name": "roe12", "age": 21, "salary": 20.5,},
                     {"name": "roe13", "age": 21, "salary": 20.5,})
try {
    dataShareHelper.batchInsert(uri, vbs).then((data) =>  {
        console.log("batchInsert succeed, data : " + data);
    }). catch((err) => {
        console.error(`batchInsert error: code: ${err.code}, message: ${err.message} `);
    });
} catch (err) {
    console.error(`batchInsert error: code: ${err.code}, message: ${err.message} `);
};
```

### normalizeUri

normalizeUri(uri: string, callback: AsyncCallback&lt;string&gt;): void

将给定的DataShare URI转换为规范化URI，规范化URI可供跨设备使用，DataShare  URI仅供本地环境中使用。使用callback异步回调。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 参数名     | 类型                   | 必填 | 说明                                                     |
| -------- | ---------------------- | ---- | -------------------------------------------------------- |
| uri      | string                 | 是   | 指示要规范化的[URI](js-apis-uri.md#uri)。      |
| callback | AsyncCallback&lt;string&gt; | 是   | 回调函数。当将给定的DataShare URI转换为规范化URI成功，err为undefined，data为获取到的规范化URI（如果支持URI规范化，则返回规范化URI，否则返回空）；否则为错误对象。 |

**示例：**

```ts
import Ability from '@ohos.application.Ability'
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

| 参数名 | 类型   | 必填 | 说明                                      |
| ---- | ------ | ---- | ----------------------------------------- |
| uri  | string | 是   | 指示要规范化的[URI](js-apis-uri.md#uri)。 |

**返回值：**

| 类型             | 说明                                           |
| ---------------- | ---------------------------------------------- |
| Promise&lt;string&gt; | Promise对象。如果支持URI规范化，则返回规范化URI，否则返回空。 |

**示例：**

```ts
import Ability from '@ohos.application.Ability'
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

| 参数名     | 类型                   | 必填 | 说明                                                |
| -------- | ---------------------- | ---- | --------------------------------------------------- |
| uri      | string                 | 是   | 指示要反规范化的[URI](js-apis-uri.md#uri)。 |
| callback | AsyncCallback&lt;string&gt; | 是   | 回调函数。当将指定的URI转换为非规范化URI，err为undefined，data为获取到的反规范化URI（如果反规范化成功，则返回反规范化的URI；如果无需进行反规范化，则返回原始URI；若不支持则返回空）；否则为错误对象。 |

**示例：**

```ts
import Ability from '@ohos.application.Ability'
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

| 参数名 | 类型   | 必填 | 说明                                        |
| ---- | ------ | ---- | ------------------------------------------- |
| uri  | string | 是   | 指示要反规范化的[URI](js-apis-uri.md#uri)。 |

**返回值：**

| 类型             | 说明                                      |
| ---------------- | ----------------------------------------- |
| Promise&lt;string&gt; | Promise对象。如果反规范化成功，则返回反规范化的URI；如果无需执行任何操作，则返回原始URI；若不支持则返回空。 |

**示例：**

```ts
import Ability from '@ohos.application.Ability'
let uri = ("datashare:///com.samples.datasharetest.DataShare");
dataShareHelper.denormalizeUri(uri).then((data) => {
    console.log("denormalizeUri = " + data);
}).catch((err) => {
    console.log("denormalizeUri failed, error message : " + err);
});
```

### notifyChange

notifyChange(uri: string, callback: AsyncCallback&lt;void&gt;): void

通知已注册的观察者指定URI对应的数据资源已发生变更。使用callback异步回调。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 参数名    | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| uri      | string               | 是   | 表示指定的数据路径。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。当通知已注册的观察者指定URI对应的数据资源已发生变更成功，err为undefined；否则为错误对象。 |

**示例：**

```ts
import Ability from '@ohos.application.Ability'
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

| 参数名 | 类型   | 必填 | 说明                 |
| ---- | ------ | ---- | -------------------- |
| uri  | string | 是   | 表示指定的数据路径。 |

**返回值：**

| 类型           | 说明                  |
| -------------- | --------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**示例：**

```ts
import Ability from '@ohos.application.Ability'
let uri = ("datashare:///com.samples.datasharetest.DataShare");
dataShareHelper.notifyChange(uri);
```