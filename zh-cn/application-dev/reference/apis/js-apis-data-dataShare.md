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
 - 跨应用场景下，目标DataShareExtension的exported属性若配置为false，调用方应用需申请`ohos.permission.START_INVISIBLE_ABILITY`权限
 - 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                                         |
| -------- | -------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| context  | [Context](js-apis-inner-application-context.md#context)        | 是   | 应用的上下文环境。                                           |
| uri      | string                                                   | 是   | 指示要连接的服务端应用的路径。                               |
| callback | AsyncCallback&lt;[DataShareHelper](#datasharehelper)&gt; | 是   | 回调函数。当创建DataShareHelper实例成功，err为undefined，data为获取到的DataShareHelper实例；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[数据共享错误码](../errorcodes/errorcode-datashare.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 15700010 | The DataShareHelper is not initialized successfully. |

**示例：**

```ts
import { BusinessError } from '@ohos.base'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let dataShareHelper: dataShare.DataShareHelper | undefined = undefined;
try {
  dataShare.createDataShareHelper(this.context, uri, (err, data) => {
    if (err !== undefined) {
      console.error(`createDataShareHelper error: code: ${err.code}, message: ${err.message} `);
      return;
    }
    console.info("createDataShareHelper succeed, data : " + data);
    dataShareHelper = data;
  });
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`createDataShareHelper error: code: ${code}, message: ${message} `);
};
```

## dataShare.createDataShareHelper<sup>10+</sup>
createDataShareHelper(context: Context, uri: string, options: DataShareHelperOptions, callback: AsyncCallback&lt;DataShareHelper&gt;): void 

创建DataShareHelper实例。使用callback异步回调。

使用规则：
 - 调用方应用位于后台时，使用该接口访问DataShareExtension需申请`ohos.permission.START_ABILITIES_FROM_BACKGROUND`权限
 - 跨应用场景下，目标DataShareExtension的exported属性若配置为false，调用方应用需申请`ohos.permission.START_INVISIBLE_ABILITY`权限
 - 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer


| 参数名   | 类型                                                 | 必填 | 说明                                                         |
| -------- | -------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| context  | [Context](js-apis-inner-application-context.md#context)        | 是   | 应用的上下文环境。                                           |
| uri      | string                                                   | 是   | 指示要连接的服务端应用的路径。                               |
| options | [DataShareHelperOptions](#datasharehelperoptions10)| 是   | 可选配置。指定[DataShareHelper](#datasharehelper)是否在代理模式下。|
| callback | AsyncCallback&lt;[DataShareHelper](#datasharehelper)&gt; | 是   | 回调函数。当创建DataShareHelper实例成功，err为undefined，data为获取到的DataShareHelper实例；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[数据共享错误码](../errorcodes/errorcode-datashare.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 15700010 | The DataShareHelper is not initialized successfully. |

**示例：**

```ts
import { BusinessError } from '@ohos.base'

let uri = ("datashareproxy://com.samples.datasharetest.DataShare");
let dataShareHelper: dataShare.DataShareHelper | undefined = undefined;
try {
  dataShare.createDataShareHelper(this.context, uri, {isProxy : true}, (err, data) => {
    if (err !== undefined) {
      console.error(`createDataShareHelper error: code: ${err.code}, message: ${err.message} `);
      return;
    }
    console.info("createDataShareHelper succeed, data : " + data);
    dataShareHelper = data;
  });
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`createDataShareHelper error: code: ${code}, message: ${message} `);
};
```
## dataShare.createDataShareHelper

createDataShareHelper(context: Context, uri: string, options?: DataShareHelperOptions): Promise&lt;DataShareHelper&gt;

创建DataShareHelper实例。使用Promise异步回调。

使用规则：
 - 调用方应用位于后台时，使用该接口访问DataShareExtension需申请`ohos.permission.START_ABILITIES_FROM_BACKGROUND`权限
 - 跨应用场景下，目标DataShareExtension的exported属性若配置为false，调用方应用需申请`ohos.permission.START_INVISIBLE_ABILITY`权限
 - 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 参数名  | 类型                                          | 必填 | 说明                           |
| ------- | ------------------------------------------------- | ---- | ------------------------------ |
| context | [Context](js-apis-inner-application-context.md#context) | 是   | 应用的上下文环境。             |
| uri     | string                                            | 是   | 指示要连接的服务端应用的路径。 |
| options<sup>10+</sup> | [DataShareHelperOptions](#datasharehelperoptions10) | 否 | 可选配置。从API version 10开始支持此参数，如果不设置，则表示[DataShareHelper](#datasharehelper)不在代理模式下。|

**返回值：**

| 类型                                               | 说明                                   |
| -------------------------------------------------- | -------------------------------------- |
| Promise&lt;[DataShareHelper](#datasharehelper)&gt; | Promise对象。返回DataShareHelper实例。 |

**错误码：**

以下错误码的详细介绍请参见[数据共享错误码](../errorcodes/errorcode-datashare.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 15700010 | The DataShareHelper is not initialized successfully. |

**示例：**

```ts
import { BusinessError } from '@ohos.base'

let uri = ("datashareproxy://com.samples.datasharetest.DataShare");
let dataShareHelper: dataShare.DataShareHelper | undefined = undefined;
try {
  dataShare.createDataShareHelper(this.context, uri, {isProxy : true}).then((data: dataShare.DataShareHelper) => {
    console.info("createDataShareHelper succeed, data : " + data);
    dataShareHelper = data;
  }). catch((err: BusinessError) => {
    console.error(`createDataShareHelper error: code: ${err.code}, message: ${err.message} `);
  });
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`createDataShareHelper error: code: ${code}, message: ${message} `);
};
```

## DataShareHelperOptions<sup>10+</sup>

指定[DataShareHelper](#datasharehelper)是否在代理模式下。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| isProxy | boolean | 否 | 默认为false，如果为true，则要创建的[DataShareHelper](#datasharehelper)处于代理模式，所有操作都不会打开数据提供者APP，除非数据库不存在，当数据库不存在时，[createDataShareHelper](#datasharecreatedatasharehelper10)会拉起数据提供者创建数据库。 |

## TemplateId<sup>10+</sup>

标记模板的数据结构，TemplateId是在[addTemplate](#addtemplate10)中自动生成的，在[addTemplate](#addtemplate10)后，可以使用模板id来标记模板。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| subscriberId | string | 是 | 指定处理回调的订阅者的id，与[addTemplate](#addtemplate10)中的subscriberId相同，每个订阅者的ID是唯一的。 |
| bundleNameOfOwner | string | 是 | 指定创建模板的模板所有者的bundleName，与[addTemplate](#addtemplate10)中的bundleName相同。 |

## PublishedItem<sup>10+</sup>

指定发布的数据类型。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | string | 是 | 指定发布数据的键。 |
| data | string \| ArrayBuffer | 是 | 指定发布的数据。如果发布数据大小超过20KB，建议使用ArrayBuffer。 |
| subscriberId | string | 是 | 指定订阅者id。 |

## RdbDataChangeNode<sup>10+</sup>

订阅/取消订阅RDB数据变更的结果。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| uri | string | 是 | 指定回调的uri。 |
| templateId | [TemplateId](#templateid10) | 是 | 处理回调的templateId。 |
| data | Array&lt;string&gt; | 是 | 指定回调的数据。 |

## PublishedDataChangeNode<sup>10+</sup>

订阅/取消订阅已发布数据变更的结果。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | 指定回调的bundleName。 |
| data | Array&lt;[PublishedItem](#publisheditem10)&gt; | 是 | 指定回调的数据。 |

## Template<sup>10+</sup>

指定订阅中的模板结构。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| predicates | { [key: string]: string } | 是 | 指定模板的谓词。当调用[on](#onrdbdatachange10)的回调时，谓词用于生成数据。仅适用于rdb存储数据。 |
| scheduler | string | 是 | 指定模板的调度程序sql。其中嵌入自定义函数处理，目前预置自定义函数remindTimer处理。remindTimer在指定场景触发一次订阅刷新。<br/>触发场景：<br/>1. 修改数据时且有订阅的情况下触发对应的调度程序sql语句。<br/>2. 添加对应库第一个订阅的情况下触发对应的调度程序sql语句。 |

## OperationResult<sup>10+</sup>

订阅/取消订阅数据变更和发布数据的操作结果。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | ----- | -------- |
| key | string | 是 | 指定运算结果的键。 |
| result | number | 是 | 指定运算结果。正常情况下返回0，异常情况下返回错误码。  |
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
let onCallback: () => void = (): void => {
  console.info("**** Observer on callback ****");
}
let uri = ("datashare:///com.samples.datasharetest.DataShare");
if (dataShareHelper !== undefined) {
  (dataShareHelper as dataShare.DataShareHelper).on("dataChange", uri, onCallback);
}
```

### off('dataChange')

off(type: 'dataChange', uri: string, callback?: AsyncCallback&lt;void&gt;): void

取消订阅指定URI下指定callback对应的数据资源的变更通知。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 参数名     | 类型                 | 必填 | 说明                    |
| -------- | -------------------- | ---- | ------------------------ |
| type     | string               | 是   | 取消订阅的事件/回调类型，支持的事件为'dataChange'。 |
| uri      | string               | 是   | 表示指定的数据路径。 |
| callback | AsyncCallback&lt;void&gt; | 否   | 表示指定取消订阅的callback通知，如果为空，则取消订阅该uri下所有的通知事件。 |

**示例：**

```ts
let callback: () => void = (): void => {
  console.info("**** Observer on callback ****");
}
let uri = ("datashare:///com.samples.datasharetest.DataShare");
if (dataShareHelper != undefined) {
  (dataShareHelper as dataShare.DataShareHelper).on("dataChange", uri, callback);
  (dataShareHelper as dataShare.DataShareHelper).off("dataChange", uri, callback);
}
```

### addTemplate<sup>10+</sup>

addTemplate(uri: string, subscriberId: string, template: Template): void

添加一个指定订阅者的数据模板。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 参数名     | 类型                    | 必填 | 说明                     |
| -------- | ------------------------ | ---- | -------------------------|
| uri      | string                   | 是   | 指示要插入的数据的路径。  |
| subscriberId | string               | 是   | 要添加模板的订阅者ID，每个订阅者的ID是唯一的。 |
| template    | [Template](#template10) | 是   | 要添加的数据模板。        |

**错误码：**

以下错误码的详细介绍请参见[数据共享错误码](../errorcodes/errorcode-datashare.md)。

| 错误码ID | 错误信息              |
| -------- | -------------------- |
| 15700011 | The uri is not exist.|

**示例：**

```ts
let uri = ("datashareproxy://com.samples.datasharetest.DataShare");
let subscriberId = '11';
let key1: string = "p1";
let value1: string = "select cityColumn as city_1, visitedCilumn as visited_1 from citys where like = true";
let key2: string = "p2";
let value2: string = "select cityColumn as city_2, visitedCilumn as visited_2 from citys where like = false";
let template: dataShare.Template = {
  predicates : {
    key1 : value1,
    key2 : value2,
  },
  scheduler : "select remindTimer(time) from TBL00"
}
if (dataShareHelper != undefined) {
  (dataShareHelper as dataShare.DataShareHelper).addTemplate(uri, subscriberId, template);
}
```

### delTemplate<sup>10+</sup>

delTemplate(uri: string, subscriberId: string): void

删除一个指定订阅者的数据模板。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 参数名     | 类型        | 必填 | 说明                       |
| -------- | -------------| ---- | ------------------------- |
| uri      | string       | 是   | 指示要删除的数据的路径。     |
| subscriberId | string   | 是   | 订阅者ID，每个订阅者的ID是唯一的。          |

**错误码：**

以下错误码的详细介绍请参见[数据共享错误码](../errorcodes/errorcode-datashare.md)。

| 错误码ID | 错误信息              |
| -------- | -------------------- |
| 15700011 | The uri is not exist.|

**示例：**

```ts
let uri = ("datashareproxy://com.samples.datasharetest.DataShare");
let subscriberId = '11';
let key1: string = "p1";
let value1: string = "select cityColumn as city_1, visitedCilumn as visited_1 from citys where like = true";
let key2: string = "p2";
let value2: string = "select cityColumn as city_2, visitedCilumn as visited_2 from citys where like = false";
let template: dataShare.Template = {
  predicates : {
    key1 : value1,
    key2 : value2,
  },
  scheduler : "select remindTimer(time) from TBL00"
}
if (dataShareHelper != undefined) {
  (dataShareHelper as dataShare.DataShareHelper).addTemplate(uri, subscriberId, template);
  (dataShareHelper as dataShare.DataShareHelper).delTemplate(uri, subscriberId);
}
```

### on('rdbDataChange')<sup>10+</sup>

on(type: 'rdbDataChange', uris: Array&lt;string&gt;, templateId: TemplateId, callback: AsyncCallback&lt;RdbDataChangeNode&gt;): Array&lt;OperationResult&gt;

订阅指定URI和模板对应的数据变更事件。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 参数名     | 类型                            | 必填 | 说明                                                         |
| -------- | ----------------------------------| ---- | ------------------------------------------------------------ |
| type      | string                           | 是   | 订阅的事件类型，支持的事件为'rdbDataChange'，表示rdb数据的变更事件。type是固定值以外时，接口无响应。  |
| uris    | Array&lt;string&gt;                | 是   | 要操作的数据的路径。           |
| templateId | [TemplateId](#templateid10)       | 是   | 处理回调的templateId。           |
| callback | AsyncCallback&lt;[RdbDataChangeNode](#rdbdatachangenode10)&gt;   | 是   | 回调函数。当触发变更通知时调用，err为undefined，node为订阅数据变更结果；否则不被触发或为错误对象。  |

**返回值：**

| 类型             | 说明                                                         |
| ---------------- | ------------------------------------------------------------ |
| Array&lt;[OperationResult](#operationresult10)&gt; | 返回操作结果。|

**示例：**

```ts
import { BusinessError } from '@ohos.base'

let onCallback: (err: BusinessError, node: dataShare.RdbDataChangeNode) => void = (err: BusinessError, node:dataShare.RdbDataChangeNode): void => {
  console.info("onCallback " + JSON.stringify(node.uri));
  console.info("onCallback " + JSON.stringify(node.templateId));
  console.info("onCallback " + node.data.length);
  for (let i = 0; i < node.data.length; i++) {
    console.info("onCallback " + typeof node.data[i] + " " + node.data[i]);
  }
}

let uri = ("datashareproxy://com.samples.datasharetest.DataShare");
let templateId:dataShare.TemplateId = {subscriberId:"11", bundleNameOfOwner:"com.acts.ohos.data.datasharetest"};
if (dataShareHelper != undefined) {
  let result: Array<dataShare.OperationResult> = (dataShareHelper as dataShare.DataShareHelper).on("rdbDataChange", [uri], templateId, onCallback);
}
```

### off('rdbDataChange')<sup>10+</sup>

off(type: 'rdbDataChange', uris: Array&lt;string&gt;, templateId: TemplateId, callback?: AsyncCallback&lt;RdbDataChangeNode&gt;): Array&lt;OperationResult&gt;

取消订阅指定URI和模板对应的数据变更事件。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 参数名     | 类型                                        | 必填 | 说明                                                        |
| -------- | -------------------------------------------- | ---- | ---------------------------------------------------------- |
| type      | string                                      | 是   | 取消订阅的事件类型，支持的事件为'rdbDataChange'，表示rdb数据的变更事件。   |
| uris    | Array&lt;string&gt;                           | 是   | 要操作的数据的路径。           |
| templateId | [TemplateId](#templateid10)                | 是   | 处理回调的templateId。        |
| callback | AsyncCallback&lt;[RdbDataChangeNode](#rdbdatachangenode10)&gt; | 否   | 回调函数。表示指定取消订阅的callback通知，如果为空，则取消订阅该uri下所有的通知事件。 |

**返回值：**

| 类型             | 说明                                                         |
| ---------------- | ------------------------------------------------------------ |
| Array&lt;[OperationResult](#operationresult10)&gt; | 返回操作结果。|

**示例：**

```ts
let uri = ("datashareproxy://com.samples.datasharetest.DataShare");
let templateId:dataShare.TemplateId = {subscriberId:"11", bundleNameOfOwner:"com.acts.ohos.data.datasharetest"};
if (dataShareHelper != undefined) {
  let result: Array<dataShare.OperationResult> = (dataShareHelper as dataShare.DataShareHelper).off("rdbDataChange", [uri], templateId);
}
```

### on('publishedDataChange')<sup>10+</sup>

on(type: 'publishedDataChange', uris: Array&lt;string&gt;, subscriberId: string, callback: AsyncCallback&lt;PublishedDataChangeNode&gt;): Array&lt;OperationResult&gt;

订阅已发布数据的数据变更通知。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 参数名     | 类型                            | 必填 | 说明                                                         |
| -------- | ----------------------------------| ---- | ------------------------------------------------------------ |
| type      | string                           | 是   | 订阅的事件类型，支持的事件为'publishedDataChange'，表示已发布数据的变更事件。 |
| uris    | Array&lt;string&gt;                | 是   | 要操作的数据的路径。           |
| subscriberId | string                        | 是   | 指定处理回调的用户ID。           |
| callback | AsyncCallback&lt;[PublishedDataChangeNode](#publisheddatachangenode10)&gt;   | 是   | 回调函数。当触发变更通知时调用，err为undefined，node为订阅数据变更结果；否则不被触发或为错误对象。  |

**返回值：**

| 类型             | 说明                                                         |
| ---------------- | ------------------------------------------------------------ |
| Array&lt;[OperationResult](#operationresult10)&gt; | 返回操作结果。|

**示例：**

```ts
import { BusinessError } from '@ohos.base'

let onPublishCallback: (err: BusinessError, node: dataShare.PublishedDataChangeNode) => void = (err: BusinessError, node:dataShare.PublishedDataChangeNode): void => {
  console.info("onPublishCallback node bundleName " + JSON.stringify(node.bundleName));
  console.info("onPublishCallback node data size" + node.data.length);
  for (let i = 0; i < node.data.length; i++) {
    console.info("onPublishCallback node " + typeof node.data[i].data);
    if (typeof node.data[i].data != 'string') {
      let array: ArrayBuffer = node.data[i].data as ArrayBuffer;
      let data: Uint8Array = new Uint8Array(array);
      console.info("onPublishCallback " + i + " " + JSON.stringify(data));
    }
    console.info("onPublishCallback data " + i + " " + JSON.stringify(node.data[i]));
  }
}
let uris:Array<string> = ['city', 'datashareproxy://com.acts.ohos.data.datasharetest/appInfo', 'key2'];
let subscriberId = '11';
if (dataShareHelper != undefined) {
  let result: Array<dataShare.OperationResult> = (dataShareHelper as dataShare.DataShareHelper).on('publishedDataChange', uris, subscriberId, onPublishCallback);
}
```

### off('publishedDataChange')<sup>10+</sup>

off(type: 'publishedDataChange', uris: Array&lt;string&gt;, subscriberId: string, callback?: AsyncCallback&lt;PublishedDataChangeNode&gt;): Array&lt;OperationResult&gt;

取消订阅已发布数据的数据变更通知。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 参数名     | 类型                                        | 必填 | 说明                                                       |
| -------- | -------------------------------------------- | ---- | ---------------------------------------------------------- |
| type      | string                                      | 是   | 取消订阅的事件类型，支持的事件为'publishedDataChange'，表示已发布数据的变更事件。|
| uris    | Array&lt;string&gt;                           | 是   | 要操作的数据的路径。           |
| subscriberId | string                                   | 是   | 指定处理回调的用户ID。           |
| callback | AsyncCallback&lt;[PublishedDataChangeNode](#publisheddatachangenode10)&gt; | 否   | 回调函数。表示指定取消订阅的callback通知，如果为空，则取消订阅该uri下所有的通知事件。 |

**返回值：**

| 类型             | 说明                                                         |
| ---------------- | ------------------------------------------------------------ |
| Array&lt;[OperationResult](#operationresult10)&gt; | 返回操作结果。|

**示例：**

```ts
import { BusinessError } from '@ohos.base'

let offCallback: (err: BusinessError, node: dataShare.PublishedDataChangeNode) => void = (err: BusinessError, node:dataShare.PublishedDataChangeNode): void => {
  console.info("**** Observer off callback ****");
}
let uris:Array<string> = ["city", "datashareproxy://com.acts.ohos.data.datasharetest/appInfo", "key2"];
let subscriberId = '11';
if (dataShareHelper != undefined) {
  let result: Array<dataShare.OperationResult> = (dataShareHelper as dataShare.DataShareHelper).off("publishedDataChange", uris, subscriberId, offCallback);
}
```

### publish<sup>10+</sup>

publish(data: Array&lt;PublishedItem&gt;, bundleName: string, version: number, callback: AsyncCallback&lt;Array&lt;OperationResult&gt;&gt;): void

发布数据，将数据更新至数据库。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 参数名     | 类型                                                      | 必填 | 说明      |
| --------- | -------------------------------------------------| ---- | ------------------- |
| data      | Array&lt;[PublishedItem](#publisheditem10)&gt;     | 是   | 指示要发布的数据。   |
| bundleName | string                                          | 是   | 表示要发布数据所属的APP，对发布的私有数据生效，仅该app可以读取数据。           |
| version | number                                             | 是   | 指示要发布的数据版本，越大表示数据版本越新。如果发布的版本号小于数据库中的记录，则更新失败。 |
| callback | AsyncCallback&lt;Array&lt;[OperationResult](#operationresult10)&gt;&gt; | 是   | 回调函数。当发布数据时调用，err为undefined，result为发布数据结果；否则不被触发或为错误对象。    |

**错误码：**

以下错误码的详细介绍请参见[数据共享错误码](../errorcodes/errorcode-datashare.md)。

| 错误码ID | 错误信息                    |
| -------- | -------------------------- |
| 15700012 | The data area is not exist.|

**示例：**

```ts
import { BusinessError } from '@ohos.base'

let arrayBuffer = new ArrayBuffer(1);
let version = 1;
let dataArray : Array<dataShare.PublishedItem> = [{key:"key2", subscriberId:"11", data:arrayBuffer}];
let publishCallback: (err: BusinessError, result: Array<dataShare.OperationResult>) => void = (err: BusinessError, result: Array<dataShare.OperationResult>): void => {
  console.info("publishCallback " + JSON.stringify(result));
}
try {
  console.info("dataArray length is:", dataArray.length);
  if (dataShareHelper != undefined) {
    (dataShareHelper as dataShare.DataShareHelper).publish(dataArray, "com.acts.ohos.data.datasharetest", version, publishCallback);
  }
} catch (e) {
  console.error("publish error " + JSON.stringify(e));
}
```

### publish<sup>10+</sup>

publish(data: Array&lt;PublishedItem&gt;, bundleName: string, callback: AsyncCallback&lt;Array&lt;OperationResult&gt;&gt;): void

发布数据，将数据更新至数据库。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 参数名     | 类型                                            | 必填 | 说明                                 |
| -------- | ------------------------------------------------- | ---- | ---------------------------------- |
| data      | Array&lt;[PublishedItem](#publisheditem10)&gt;                        | 是   | 指示要发布的数据。   |
| bundleName | string                                          | 是   | 表示要发布数据所属的APP，对发布的私有数据生效，仅该app可以读取数据。       |
| callback | AsyncCallback&lt;Array&lt;[OperationResult](#operationresult10)&gt;&gt; | 是   | 回调函数。当发布数据时调用，err为undefined，result为发布数据结果；否则不被触发或为错误对象。 |

**示例：**

**错误码：**

以下错误码的详细介绍请参见[数据共享错误码](../errorcodes/errorcode-datashare.md)。

| 错误码ID | 错误信息                    |
| -------- | -------------------------- |
| 15700012 | The data area is not exist.|

```ts
import { BusinessError } from '@ohos.base'

let publishCallback: (err: BusinessError, result: Array<dataShare.OperationResult>) => void = (err: BusinessError, result: Array<dataShare.OperationResult>): void => {
  console.info("publishCallback " + JSON.stringify(result));
}
let dataArray : Array<dataShare.PublishedItem> = [
  {key:"city", subscriberId:"11", data:"xian"},
  {key:"datashareproxy://com.acts.ohos.data.datasharetest/appInfo", subscriberId:"11", data:"appinfo is just a test app"},
  {key:"empty", subscriberId:"11", data:"nobody sub"}];
if (dataShareHelper != undefined) {
  (dataShareHelper as dataShare.DataShareHelper).publish(dataArray, "com.acts.ohos.data.datasharetest", publishCallback);
}
```

### publish<sup>10+</sup>

publish(data: Array&lt;PublishedItem&gt;, bundleName: string, version?: number): Promise&lt;Array&lt;OperationResult&gt;&gt;

发布数据，将数据更新至数据库。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 参数名     | 类型                        | 必填 | 说明                            |
| -------- | ----------------------------- | ---- | ------------------------------ |
| data      | Array&lt;[PublishedItem](#publisheditem10)&gt;    | 是   | 指示要发布的数据。|
| bundleName | string                      | 是   | 表示要发布数据所属的APP，对发布的私有数据生效，仅该app可以读取数据。  |
| version | number                         | 否   | 指示要发布的数据版本，越大表示数据版本越新。如果发布的版本号小于数据库中的记录，则更新失败。<br/> 如果不检查要发布的数据版本，则不填。 |

**返回值：**

| 类型             | 说明                                                         |
| ---------------- | ------------------------------------------------------------ |
| Promise&lt;Array&lt;[OperationResult](#operationresult10)&gt;&gt; | 发布数据结果。|

**错误码：**

以下错误码的详细介绍请参见[数据共享错误码](../errorcodes/errorcode-datashare.md)。

| 错误码ID | 错误信息                    |
| -------- | -------------------------- |
| 15700012 | The data area is not exist.|

**示例：**

```ts
let dataArray: Array<dataShare.PublishedItem> = [
  {key:"city", subscriberId:"11", data:"xian"},
  {key:"datashareproxy://com.acts.ohos.data.datasharetest/appInfo", subscriberId:"11", data:"appinfo is just a test app"},
  {key:"empty", subscriberId:"11", data:"nobody sub"}];
if (dataShareHelper != undefined) {
  let result: Promise<Array<dataShare.OperationResult>> = (dataShareHelper as dataShare.DataShareHelper).publish(dataArray, "com.acts.ohos.data.datasharetest");
}
```

### getPublishedData<sup>10+</sup>

getPublishedData(bundleName: string, callback: AsyncCallback&lt;Array&lt;PublishedItem&gt;&gt;): void

获取给定的APP和模板指定的数据。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 参数名    | 类型             | 必填 | 说明                           |
| -------- | -----------------| ---- | ----------------------------- |
| bundleName | string         | 是   | 表示数据所属的APP。  |
| callback | AsyncCallback&lt;Array&lt;[PublishedItem](#publisheditem10)&gt;&gt; | 是   | 回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[数据共享错误码](../errorcodes/errorcode-datashare.md)。

| 错误码ID | 错误信息                    |
| -------- | -------------------------- |
| 15700012 | The data area is not exist.|

**示例：**

```ts
import { BusinessError } from '@ohos.base'

let publishCallback: (err: BusinessError, data: Array<dataShare.PublishedItem>) => void = (err: BusinessError, result: Array<dataShare.PublishedItem>): void => {
  console.info("**** Observer publish callback ****");
}
if (dataShareHelper != undefined) {
  (dataShareHelper as dataShare.DataShareHelper).getPublishedData("com.acts.ohos.data.datasharetest", publishCallback);
}
```

### getPublishedData<sup>10+</sup>

getPublishedData(bundleName: string): Promise&lt;Array&lt;PublishedItem&gt;&gt;

获取给定的APP和模板指定的数据。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 参数名     | 类型         | 必填 | 说明                                    |
| -------- | --------------| ---- | -------------------------------------- |
| bundleName | string      | 是   | 表示数据所属的APP。           |

**返回值：**

| 类型             | 说明                                                         |
| ---------------- | ------------------------------------------------------------ |
| Promise&lt;Array&lt;[PublishedItem](#publisheditem10)&gt;&gt; | Promise对象。返回给定的APP和模板指定的数据。|

**错误码：**

以下错误码的详细介绍请参见[数据共享错误码](../errorcodes/errorcode-datashare.md)。

| 错误码ID | 错误信息                    |
| -------- | -------------------------- |
| 15700012 | The data area is not exist.|

**示例：**

```ts 
if (dataShareHelper != undefined) {
  let publishedData: Promise<Array<dataShare.PublishedItem>> = (dataShareHelper as dataShare.DataShareHelper).getPublishedData("com.acts.ohos.data.datasharetest");
}
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
import { ValuesBucket } from '@ohos.data.ValuesBucket'
import { BusinessError } from '@ohos.base'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let key1: string = "name";
let value1: string = "rose";
let key2: string = "age";
let value2: number = 22;
let key3: string = "salary";
let value3: number = 200.5;
const valueBucket: ValuesBucket = {
  key1: value1,
  key2: value2,
  key3: value3,
}
try {
  if (dataShareHelper != undefined) {
    (dataShareHelper as dataShare.DataShareHelper).insert(uri, valueBucket, (err: BusinessError, data: number) => {
      if (err !== undefined) {
        console.error(`insert error: code: ${err.code}, message: ${err.message} `);
        return;
      }
      console.info("insert succeed, data : " + data);
    });
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`insert error: code: ${code}, message: ${message} `);
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
import { BusinessError } from '@ohos.base'
import { ValuesBucket } from '@ohos.data.ValuesBucket'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let key1: string = "name";
let value1: string = "rose1";
let key2: string = "age";
let value2: number = 21;
let key3: string = "salary";
let value3: number = 20.5;
const valueBucket: ValuesBucket = {
  key1: value1,
  key2: value2,
  key3: value3,
}
try {
  if (dataShareHelper != undefined) {
    (dataShareHelper as dataShare.DataShareHelper).insert(uri, valueBucket).then((data: number) => {
      console.info("insert succeed, data : " + data);
    }).catch((err: BusinessError) => {
      console.error(`insert error: code: ${err.code}, message: ${err.message} `);
    });
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`insert error: code: ${code}, message: ${message} `);
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
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import { BusinessError } from '@ohos.base'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let da = new dataSharePredicates.DataSharePredicates();
da.equalTo("name", "ZhangSan");
try {
  if (dataShareHelper != undefined) {
    (dataShareHelper as dataShare.DataShareHelper).delete(uri, da, (err: BusinessError, data: number) => {
      if (err !== undefined) {
        console.error(`delete error: code: ${err.code}, message: ${err.message} `);
        return;
      }
      console.info("delete succeed, data : " + data);
    });
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`delete error: code: ${code}, message: ${message} `);
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
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import { BusinessError } from '@ohos.base'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let da = new dataSharePredicates.DataSharePredicates();
da.equalTo("name", "ZhangSan");
try {
  if (dataShareHelper != undefined) {
    (dataShareHelper as dataShare.DataShareHelper).delete(uri, da).then((data: number) => {
      console.info("delete succeed, data : " + data);
    }).catch((err: BusinessError) => {
      console.error(`delete error: code: ${err.code}, message: ${err.message} `);
    });
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`delete error: code: ${code}, message: ${message} `);
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
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import { BusinessError } from '@ohos.base'
import DataShareResultSet from '@ohos.data.DataShareResultSet'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let columns = ["*"];
let da = new dataSharePredicates.DataSharePredicates();
da.equalTo("name", "ZhangSan");
try {
  if (dataShareHelper != undefined) {
    (dataShareHelper as dataShare.DataShareHelper).query(uri, da, columns, (err: BusinessError, data: DataShareResultSet) => {
      if (err !== undefined) {
        console.error(`query error: code: ${err.code}, message: ${err.message} `);
        return;
      }
      console.info("query succeed, rowCount : " + data.rowCount);
    });
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`query error: code: ${code}, message: ${message} `);
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
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import { BusinessError } from '@ohos.base'
import DataShareResultSet from '@ohos.data.DataShareResultSet'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let columns = ["*"];
let da = new dataSharePredicates.DataSharePredicates();
da.equalTo("name", "ZhangSan");
try {
  if (dataShareHelper != undefined) {
    (dataShareHelper as dataShare.DataShareHelper).query(uri, da, columns).then((data: DataShareResultSet) => {
      console.info("query succeed, rowCount : " + data.rowCount);
    }).catch((err: BusinessError) => {
      console.error(`query error: code: ${err.code}, message: ${err.message} `);
    });
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`query error: code: ${code}, message: ${message} `);
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
| value      | [ValuesBucket](js-apis-data-valuesBucket.md#valuesbucket)    | 是   | 指示要更新的数据。可以为null。                                  |
| callback   | AsyncCallback&lt;number&gt;                                  | 是   | 回调函数。当更新数据库中的数据记录成功，err为undefined，data为获取到的更新的数据记录数；否则为错误对象。<br />因部分数据库（如KVDB）的相应接口并不提供相应支持，故若服务端使用此数据库，则此callback也无法返回更新的数据记录数。 |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import { BusinessError } from '@ohos.base'
import { ValuesBucket } from '@ohos.data.ValuesBucket'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let da = new dataSharePredicates.DataSharePredicates();
da.equalTo("name", "ZhangSan");
let key1: string = "name";
let value1: string = "roe1"
let key2: string = "age";
let value2: number = 21
let key3: string = "salary";
let value3: number = 20.5;
const va: ValuesBucket = {
  key1: value1,
  key2: value2,
  key3: value3,
}
try {
  if (dataShareHelper != undefined) {
    (dataShareHelper as dataShare.DataShareHelper).update(uri, da, va, (err: BusinessError, data: number) => {
      if (err !== undefined) {
        console.error(`update error: code: ${err.code}, message: ${err.message} `);
        return;
      }
      console.info("update succeed, data : " + data);
    });
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`update error: code: ${code}, message: ${message} `);
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
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import { ValuesBucket } from '@ohos.data.ValuesBucket'
import { BusinessError } from '@ohos.base'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let da = new dataSharePredicates.DataSharePredicates();
da.equalTo("name", "ZhangSan");
let key1: string = "name";
let value1: string = "roe1"
let key2: string = "age";
let value2: number = 21
let key3: string = "salary";
let value3: number = 20.5;
const va: ValuesBucket = {
  key1: value1,
  key2: value2,
  key3: value3,
}
try {
  if (dataShareHelper != undefined) {
    (dataShareHelper as dataShare.DataShareHelper).update(uri, da, va).then((data: number) => {
      console.info("update succeed, data : " + data);
    }).catch((err: BusinessError) => {
      console.error(`update error: code: ${err.code}, message: ${err.message} `);
    });
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`update error: code: ${code}, message: ${message} `);
};
```

### batchInsert

batchInsert(uri: string, values: Array&lt;ValuesBucket&gt;, callback: AsyncCallback&lt;number&gt;): void

将批量数据插入数据库。使用callback异步回调。暂不支持静默访问。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| uri      | string                                                       | 是   | 指示要插入的数据的路径。                                     |
| values   | Array&lt;[ValuesBucket](js-apis-data-valuesBucket.md#valuesbucket)&gt; | 是   | 指示要插入的数据。                                           |
| callback | AsyncCallback&lt;number&gt;                                  | 是   | 回调函数。当将批量数据插入数据库成功，err为undefined，data为获取到的插入的数据记录数；否则为错误对象。<br />因部分数据库（如KVDB）的相应接口并不提供相应支持，故若服务端使用此数据库，则此Promise也无法返回插入的数据记录数。 |

**示例：**

```ts
import { ValuesBucket } from '@ohos.data.ValuesBucket'
import { BusinessError } from '@ohos.base'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let key1: string = "name";
let value11: string = "roe11"
let key2: string = "age";
let value21: number = 21;
let key3: string = "salary";
let value31: number = 20.5;
let valuesBucket1: ValuesBucket = {
  key1: value11,
  key2: value21,
  key3: value31,
}
let vbs = new Array(valuesBucket1);
try {
  if (dataShareHelper != undefined) {
    (dataShareHelper as dataShare.DataShareHelper).batchInsert(uri, vbs, (err, data) => {
      if (err !== undefined) {
        console.error(`batchInsert error: code: ${err.code}, message: ${err.message} `);
        return;
      }
      console.info("batchInsert succeed, data : " + data);
    });
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`batchInsert error: code: ${code}, message: ${message} `);
};
```

### batchInsert

batchInsert(uri: string, values: Array&lt;ValuesBucket&gt;): Promise&lt;number&gt;

将批量数据插入数据库。使用Promise异步回调。暂不支持静默访问。

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
import { ValuesBucket } from '@ohos.data.ValuesBucket'
import { BusinessError } from '@ohos.base'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let key1: string = "name";
let value11: string = "roe11"
let key2: string = "age";
let value21: number = 21;
let key3: string = "salary";
let value31: number = 20.5;
let valuesBucket1: ValuesBucket = {
  key1: value11,
  key2: value21,
  key3: value31,
}
let vbs = new Array(valuesBucket1);
try {
  if (dataShareHelper != undefined) {
    (dataShareHelper as dataShare.DataShareHelper).batchInsert(uri, vbs).then((data: number) => {
      console.info("batchInsert succeed, data : " + data);
    }).catch((err: BusinessError) => {
      console.error(`batchInsert error: code: ${err.code}, message: ${err.message} `);
    });
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message
  console.error(`batchInsert error: code: ${code}, message: ${message} `);
};
```

### normalizeUri

normalizeUri(uri: string, callback: AsyncCallback&lt;string&gt;): void

将给定的DataShare URI转换为规范化URI，规范化URI可供跨设备使用，DataShare  URI仅供本地环境中使用。使用callback异步回调。暂不支持静默访问。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 参数名     | 类型                   | 必填 | 说明                                                     |
| -------- | ---------------------- | ---- | -------------------------------------------------------- |
| uri      | string                 | 是   | 指示要规范化的[URI](js-apis-uri.md#uri)。      |
| callback | AsyncCallback&lt;string&gt; | 是   | 回调函数。当将给定的DataShare URI转换为规范化URI成功，err为undefined，data为获取到的规范化URI（如果支持URI规范化，则返回规范化URI，否则返回空）；否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
if (dataShareHelper != undefined) {
  (dataShareHelper as dataShare.DataShareHelper).normalizeUri(uri, (err: BusinessError, data: string) => {
    if (err !== undefined) {
      console.info("normalizeUri failed, error message : " + err);
    } else {
      console.info("normalizeUri = " + data);
    }
  });
}
```

### normalizeUri

normalizeUri(uri: string): Promise&lt;string&gt;

将给定的DataShare URI转换为规范化URI，规范化URI可供跨设备使用，DataShare  URI仅供本地环境中使用。使用Promise异步回调。暂不支持静默访问。

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
import { BusinessError } from '@ohos.base'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
if (dataShareHelper != undefined) {
  (dataShareHelper as dataShare.DataShareHelper).normalizeUri(uri).then((data: string) => {
    console.info("normalizeUri = " + data);
  }).catch((err: BusinessError) => {
    console.info("normalizeUri failed, error message : " + err);
  });
}
```

### denormalizeUri

denormalizeUri(uri: string, callback: AsyncCallback&lt;string&gt;): void

将指定的URI转换为非规范化URI。使用callback异步回调。暂不支持静默访问。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 参数名     | 类型                   | 必填 | 说明                                                |
| -------- | ---------------------- | ---- | --------------------------------------------------- |
| uri      | string                 | 是   | 指示要反规范化的[URI](js-apis-uri.md#uri)。 |
| callback | AsyncCallback&lt;string&gt; | 是   | 回调函数。当将指定的URI转换为非规范化URI，err为undefined，data为获取到的反规范化URI（如果反规范化成功，则返回反规范化的URI；如果无需进行反规范化，则返回原始URI；若不支持则返回空）；否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
if (dataShareHelper != undefined) {
  (dataShareHelper as dataShare.DataShareHelper).denormalizeUri(uri, (err: BusinessError, data: string) => {
    if (err !== undefined) {
      console.error("denormalizeUri failed, error message : " + err);
    } else {
      console.info("denormalizeUri = " + data);
    }
  });
}
```

### denormalizeUri

denormalizeUri(uri: string): Promise&lt;string&gt;

将指定的URI转换为非规范化URI。使用Promise异步回调。暂不支持静默访问。

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
import { BusinessError } from '@ohos.base'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
if (dataShareHelper != undefined) {
  (dataShareHelper as dataShare.DataShareHelper).denormalizeUri(uri).then((data: string) => {
    console.info("denormalizeUri = " + data);
  }).catch((err: BusinessError) => {
    console.error("denormalizeUri failed, error message : " + err);
  });
}
```

### notifyChange

notifyChange(uri: string, callback: AsyncCallback&lt;void&gt;): void

通知已注册的观察者指定URI对应的数据资源已发生变更。使用callback异步回调。暂不支持静默访问。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

**参数：**

| 参数名    | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| uri      | string               | 是   | 表示指定的数据路径。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。当通知已注册的观察者指定URI对应的数据资源已发生变更成功，err为undefined；否则为错误对象。 |

**示例：**

```ts
let uri = ("datashare:///com.samples.datasharetest.DataShare");
if (dataShareHelper != undefined) {
  (dataShareHelper as dataShare.DataShareHelper).notifyChange(uri, () => {
    console.info("***** notifyChange *****");
  });
}
```

### notifyChange

notifyChange(uri: string): Promise&lt;void&gt;

通知已注册的观察者指定URI对应的数据资源已发生变更。使用Promise异步回调。暂不支持静默访问。

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
let uri = ("datashare:///com.samples.datasharetest.DataShare");
if (dataShareHelper != undefined) {
  (dataShareHelper as dataShare.DataShareHelper).notifyChange(uri);
}
```