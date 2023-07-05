# @ohos.pluginComponent (PluginComponentManager)

用于给插件组件的使用者请求组件与数据，使用者发送组件模板和数据。如需实现插件模板的显示，请参考[PluginComponent](../arkui-ts/ts-basic-components-plugincomponent.md)。

>  **说明：**
>
> - 本模块首批接口从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 导入模块

```js
import pluginComponentManager from '@ohos.pluginComponent'
```

## PluginComponentTemplate

Plugin组件模板参数。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 参数       | 类型   | 必填 | 描述                        |
| ---------- | ------ | ---- | --------------------------- |
| source     | string | 是   | 组件模板名。                |
| bundleName | string | 是   | 提供者Ability的bundleName。 |


## PluginComponentManager

### KVObject

以键值对形式存储信息，符合json格式。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full


| 取值范围              | 说明                                     |
| --------------------- | ---------------------------------------- |
| [key: string]         | 关键字，数据类型为字符串，可取空字符串。 |
| number                | 键值，表示值类型为数字。                 |
| string                | 键值，表示值类型为字符串，可取空字符串。 |
| boolean               | 键值，表示值类型为布尔值。               |
| []                    | 键值，可取值为[]。                       |
| [KVObject](#kvobject) | 键值，表示值类型为KVObject。             |


### PushParameters

用于设置FA模型下使用PluginManager.Push方法时候的需要传递的参数。

**模型约束：** 此接口仅适用于FA模型。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称      | 类型                                | 必填 | 说明                                                           |
| --------- | ----------------------------------- | ---- | -------------------------------------------------------------- |
| want      | [Want](js-apis-application-want.md) | 是   | 组件使用者Ability信息。                                        |
| name      | string                              | 是   | 组件名称。                                                     |
| data      | [KVObject](#kvobject)               | 是   | 组件数据值。                                                   |
| extraData | [KVObject](#kvobject)               | 是   | 附加数据值。                                                   |
| jsonPath  | string                              | 否   | 存放模板路径的[external.json](#externaljson文件说明)件的路径。 |

### PushParameterForStage

用于设置Stage模型下使用PluginManager.Push方法时候的需要传递的参数。

**模型约束：** 此接口仅适用于Stage模型。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称      | 类型                                | 必填 | 说明                                                             |
| --------- | ----------------------------------- | ---- | ---------------------------------------------------------------- |
| owner     | [Want](js-apis-application-want.md) | 是   | 组件提供方Ability信息。                                          |
| target    | [Want](js-apis-application-want.md) | 是   | 组件使用者Ability信息。                                          |
| name      | string                              | 是   | 组件名称。                                                       |
| data      | [KVObject](#kvobject)               | 是   | 组件数据值。                                                     |
| extraData | [KVObject](#kvobject)               | 是   | 附加数据值。                                                     |
| jsonPath  | string                              | 否   | 存放模板路径的[external.json](#externaljson文件说明)文件的路径。 |

### RequestParameters

用于设置FA模型下使用PluginManager.Request方法时候的需要传递的参数。

**模型约束：** 此接口仅适用于FA模型。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称     | 类型                                | 必填 | 说明                                                                                                                  |
| -------- | ----------------------------------- | ---- | --------------------------------------------------------------------------------------------------------------------- |
| want     | [Want](js-apis-application-want.md) | 是   | 组件提供者Ability信息。                                                                                               |
| name     | string                              | 是   | 请求组件名称。                                                                                                        |
| data     | [KVObject](#kvobject)               | 是   | 附加数据。                                                                                                            |
| jsonPath | string                              | 否   | 存放模板路径的[external.json](#externaljson文件说明)文件的路径。jsonPath字段不为空或者未设置的时候不触发Request通信。 |

### RequestParameterForStage

用于设置Stage模型下使用PluginManager.Request方法时候的需要传递的参数。

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅适用于Stage模型。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称     | 类型                                | 必填 | 说明                                                                                                                  |
| -------- | ----------------------------------- | ---- | --------------------------------------------------------------------------------------------------------------------- |
| owner    | [Want](js-apis-application-want.md) | 是   | 组件使用者Ability信息。                                                                                               |
| target   | [Want](js-apis-application-want.md) | 是   | 组件提供者Ability信息。                                                                                               |
| name     | string                              | 是   | 请求组件名称。                                                                                                        |
| data     | [KVObject](#kvobject)               | 是   | 附加数据。                                                                                                            |
| jsonPath | string                              | 否   | 存放模板路径的[external.json](#externaljson文件说明)文件的路径。jsonPath字段不为空或者未设置的时候不触发Request通信。 |

### RequestCallbackParameters

PluginManager.Request方法时候接收到的回调结果。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称              | 类型                                                | 必填 | 说明       |
| ----------------- | --------------------------------------------------- | ---- | ---------- |
| componentTemplate | [PluginComponentTemplate](#plugincomponenttemplate) | 是   | 组件模板。 |
| data              | [KVObject](#kvobject)                               | 是   | 组件数据。 |
| extraData         | [KVObject](#kvobject)                               | 是   | 附加数据。 |

### RequestEventResult

注册Request监听方法后，接受到的请求事件时候回应请求的数据类型。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称      | 类型                  | 必填 | 说明       |
| --------- | --------------------- | ---- | ---------- |
| template  | string                | 否   | 组件模板。 |
| data      | [KVObject](#kvobject) | 否   | 组件数据。 |
| extraData | [KVObject](#kvobject) | 否   | 附加数据。 |

### OnPushEventCallback

OnPushEventCallback = (source: Want, template: PluginComponentTemplate, data: KVObject,
    extraData: KVObject) => void

对应Push事件的监听回调函数。

**参数：**

| 参数      | 类型                                                | 必填 | 说明                                     |
| --------- | --------------------------------------------------- | ---- | ---------------------------------------- |
| source    | [Want](js-apis-application-want.md)                 | 是   | Push请求发送方相关信息。                 |
| template  | [PluginComponentTemplate](#plugincomponenttemplate) | 是   | Push请求发送方相关信息请求组件模板名称。 |
| data      | [KVObject](#kvobject)                               | 是   | 数据。                                   |
| extraData | [KVObject](#kvobject)                               | 是   | 附加数据。                               |

**示例：**

```js
function onPushListener(source, template, data, extraData) {
  console.log("onPushListener template.source=" + template.source)
  console.log("onPushListener source=" + JSON.stringify(source))
  console.log("onPushListener template=" + JSON.stringify(template))
  console.log("onPushListener data=" + JSON.stringify(data))
  console.log("onPushListener extraData=" + JSON.stringify(extraData))
}
```


### OnRequestEventCallback

OnRequestEventCallback = (source: Want, name: string, data: KVObject) => RequestEventResult

对应request事件的监听回调函数。

**参数：**

| 参数      | 类型                                | 必填 | 说明                        |
| --------- | ----------------------------------- | ---- | --------------------------- |
| source    | [Want](js-apis-application-want.md) | 是   | request请求发送方相关信息。 |
| name      | string                              | 是   | 模板名称。                  |
| extraData | [KVObject](#kvobject)               | 是   | 附加数据。                  |

**示例：**

```js
function onRequestListener(source, name, data) {
  console.error("onRequestListener");
  console.log("onRequestListener source=" + JSON.stringify(source));
  console.log("onRequestListener name=" + name);
  console.log("onRequestListener data=" + JSON.stringify(data));

  return { template: "ets/pages/plugin.js", data: data };
}
```

### push

push(param: PushParameters , callback: AsyncCallback&lt;void&gt;): void

组件提供者向组件使用者主动发送组件与数据。

**模型约束：** 此接口仅适用于FA模型。

**参数：**
| 参数名   | 类型                              | 必填 | 说明                     |
| -------- | --------------------------------- | ---- | ------------------------ |
| param    | [PushParameters](#pushparameters) | 是   | 组件使用者的详细信息。   |
| callback | AsyncCallback&lt;void&gt;         | 是   | 此次接口调用的异步回调。 |

**示例：**

```js
pluginComponentManager.push(
  {
    want: {
      bundleName: "com.example.provider",
      abilityName: "com.example.provider.MainAbility",
    },
    name: "plugintemplate",
    data: {
      "key_1": "plugin component test",
      "key_2": 34234
    },
    extraData: {
      "extra_str": "this is push event"
    },
    jsonPath: "",
  },
  (err, data) => {
    console.log("push_callback: push ok!");
  }
)
```

### push

push(param: PushParameterForStage, callback: AsyncCallback&lt;void&gt;): void

组件提供者向组件使用者主动发送组件与数据。

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅适用于Stage模型。

**参数：**
| 参数名   | 类型                                            | 必填 | 说明                     |
| -------- | ----------------------------------------------- | ---- | ------------------------ |
| param    | [PushParameterForStage](#pushparameterforstage) | 是   | 组件使用者的详细信息。   |
| callback | AsyncCallback&lt;void&gt;                       | 是   | 此次接口调用的异步回调。 |

**示例：**

```js
pluginComponentManager.push(
  {
    owner: {
      bundleName: "com.example.provider",
      abilityName: "com.example.provider.MainAbility"
    },
    target: {
      bundleName: "com.example.provider",
      abilityName: "com.example.provider.MainAbility",
    },
    name: "ets/pages/plugin2.js",
    data: {
      "js": "ets/pages/plugin.js",
      "key_1": 1111, 
    },
    extraData: {
      "extra_str": "this is push event"
    },
    jsonPath: "",
  },
  (err, data) => {
    console.log("push_callback:err: ", JSON.stringify(err));
    console.log("push_callback:data: ", JSON.stringify(data));
    console.log("push_callback: push ok!");
  }
)
```


### request

request(param: RequestParameters, callback: AsyncCallback&lt;RequestCallbackParameters&gt;): void

组件使用者向组件提供者主动请求组件。

**模型约束：** 此接口仅适用于FA模型。


**参数：**

| 参数名   | 类型                                                                                           | 必填 | 说明                                                             |
| -------- | ---------------------------------------------------------------------------------------------- | ---- | ---------------------------------------------------------------- |
| param    | [RequestParameters](#requestparameters)                                                        | 是   | 组件模板的详细请求信息。                                         |
| callback | AsyncCallback&lt;[RequestCallbackParameters](#requestcallbackparameters)&nbsp;\|&nbsp;void&gt; | 是   | 此次请求的异步回调，&nbsp;通过回调接口的参数返回接受请求的数据。 |

**示例：**

```js
pluginComponentManager.request(
  {
    want: {
      bundleName: "com.example.provider",
      abilityName: "com.example.provider.MainAbility",
    },
    name: "plugintemplate",
    data: {
      "key_1": "plugin component test",
      "key_2": 1111111
    },
    jsonPath: "",
  },
  (err, data) => {
    console.log("request_callback: componentTemplate.ability=" + data.componentTemplate.ability)
    console.log("request_callback: componentTemplate.source=" + data.componentTemplate.source)
    console.log("request_callback: data=" + JSON.stringify(data.data))
    console.log("request_callback: extraData=" + JSON.stringify(data.extraData))
  }
)
```


### request

request(param: RequestParameterForStage, callback: AsyncCallback&lt;RequestCallbackParameters&gt;): void

组件使用者向组件提供者主动请求组件。

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅适用于Stage模型。

**参数：**

| 参数名   | 类型                                                                                           | 必填 | 说明                                                             |
| -------- | ---------------------------------------------------------------------------------------------- | ---- | ---------------------------------------------------------------- |
| param    | [RequestParameterForStage](#requestparameterforstage)                                          | 是   | 组件模板的详细请求信息。                                         |
| callback | AsyncCallback&lt;[RequestCallbackParameters](#requestcallbackparameters)&nbsp;\|&nbsp;void&gt; | 是   | 此次请求的异步回调，&nbsp;通过回调接口的参数返回接受请求的数据。 |

**示例：**

```js
pluginComponentManager.request(
  {
    owner: {
      bundleName: "com.example.provider",
      abilityName: "com.example.provider.MainAbility"
    },
    target: {
      bundleName: "com.example.provider",
      abilityName: "ets/pages/plugin2.js",
    },
    name: "plugintemplate",
    data: {
      "key_1": " myapplication plugin component test",
    },
    jsonPath: "",
  },
  (err, data) => {
    console.log("request_callback: componentTemplate.ability=" + data.componentTemplate.ability)
    console.log("request_callback: componentTemplate.source=" + data.componentTemplate.source)
  }
)
```

### on

on(eventType: string, callback: OnPushEventCallback | OnRequestEventCallback ): void

提供者监听"request"类型的事件，给使用者返回通过request接口主动请求的数据；使用者监听"push"类型的事件，接收提供者通过push接口主动推送的数据。

**参数：**

| 参数名    | 类型                                                                                                       | 必填 | 说明                                                                                                                                                           |
| --------- | ---------------------------------------------------------------------------------------------------------- | ---- | -------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| eventType | string                                                                                                     | 是   | 监听的事件类型，&nbsp;可选值为："push"&nbsp;、"request"。<br/>"push”：指组件提供者向使用者主动推送数据。<br/>"request”：指组件使用者向提供者主动请求数据。     |
| callback  | [OnPushEventCallback](#onpusheventcallback)&nbsp;\|&nbsp;[OnRequestEventCallback](#onrequesteventcallback) | 是   | 对应监听回调，push事件对应回调类型为[OnPushEventCallback](#onpusheventcallback)，request事件对应回调类型为[OnRequestEventCallback](#onrequesteventcallback) 。 |


**示例：**

```js
pluginComponentManager.on("push", onPushListener)
pluginComponentManager.on("request", onRequestListener)
```

## external.json文件说明

external.json文件由开发者创建。external.json中以键值对形式存放组件名称以及对应模板路径。以组件名称name作为关键字，对应模板路径作为值。

**示例**

```json
{
  "PluginProviderExample": "ets/pages/PluginProviderExample.js",
  "plugintemplate2": "ets/pages/plugintemplate2.js"
}

```