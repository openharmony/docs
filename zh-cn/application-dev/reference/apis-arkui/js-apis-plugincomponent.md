# @ohos.pluginComponent (PluginComponentManager)

用于给插件组件的使用者请求组件与数据，使用者发送组件模板和数据。

>  **说明：**
>
>  - 本模块首批接口从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 导入模块

```ts
import { pluginComponentManager } from '@kit.ArkUI'
```

## PluginComponentTemplate

Plugin组件模板参数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 参数    | 类型   | 必填 | 描述                        |
| ------- | ------ | ---- | --------------------------- |
| source  | string | 是   | 组件模板名。                |
| ability | string | 是   | 提供者Ability的bundleName。 |

## PluginComponentManager

插件组件管理器。

### KVObject

type KVObject = { [key: string]: number | string | boolean | [] | KVObject }

以键值对形式存储信息，符合json格式。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

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

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称        | 类型                                  | 必填   | 说明                                       |
| --------- | ----------------------------------- | ---- | ---------------------------------------- |
| want      | [Want](../apis-ability-kit/js-apis-application-want.md) | 是    | 组件使用者Ability信息。                          |
| name      | string                              | 是    | 组件名称。                                    |
| data      | [KVObject](#kvobject)               | 是    | 组件数据值。                                   |
| extraData | [KVObject](#kvobject)               | 是    | 附加数据值。                                   |
| jsonPath  | string                              | 否    | 存放模板路径的[external.json](#externaljson文件说明)件的路径。 |

### RequestParameters

用于设置FA模型下使用PluginManager.Request方法时候的需要传递的参数。

**模型约束：** 此接口仅适用于FA模型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称       | 类型                                  | 必填   | 说明                                       |
| -------- | ----------------------------------- | ---- | ---------------------------------------- |
| want     | [Want](../apis-ability-kit/js-apis-application-want.md) | 是    | 组件提供者Ability信息。                          |
| name     | string                              | 是    | 请求组件名称。                                  |
| data     | [KVObject](#kvobject)               | 是    | 附加数据。                                    |
| jsonPath | string                              | 否    | 存放模板路径的[external.json](#externaljson文件说明)文件的路径。jsonPath字段不为空或者未设置的时候不触发Request通信。 |

### RequestCallbackParameters

PluginManager.Request方法时候接收到的回调结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称                | 类型                                       | 必填   | 说明    |
| ----------------- | ---------------------------------------- | ---- | ----- |
| componentTemplate | [PluginComponentTemplate](#plugincomponenttemplate) | 是    | 组件模板。 |
| data              | [KVObject](#kvobject)                    | 是    | 组件数据。 |
| extraData         | [KVObject](#kvobject)                    | 是    | 附加数据。 |

### RequestEventResult

注册Request监听方法后，接受到的请求事件时候回应请求的数据类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称        | 类型                    | 必填   | 说明    |
| --------- | --------------------- | ---- | ----- |
| template  | string                | 否    | 组件模板。 |
| data      | [KVObject](#kvobject) | 否    | 组件数据。 |
| extraData | [KVObject](#kvobject) | 否    | 附加数据。 |

### OnPushEventCallback

type OnPushEventCallback = (source: Want, template: PluginComponentTemplate, data: KVObject,
    extraData: KVObject) => void

对应Push事件的监听回调函数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数        | 类型                                       | 必填   | 说明                     |
| --------- | ---------------------------------------- | ---- | ---------------------- |
| source    | [Want](../apis-ability-kit/js-apis-application-want.md)      | 是    | Push请求发送方相关信息。         |
| template  | [PluginComponentTemplate](#plugincomponenttemplate) | 是    | Push请求发送方相关信息请求组件模板名称。 |
| data      | [KVObject](#kvobject)                    | 是    | 数据。                    |
| extraData | [KVObject](#kvobject)                    | 是    | 附加数据。                  |

**示例：**

```ts
import { pluginComponentManager, PluginComponentTemplate } from '@kit.ArkUI'
import { Want } from '@kit.AbilityKit';

function onPushListener(source: Want, template: PluginComponentTemplate, data: pluginComponentManager.KVObject, extraData: pluginComponentManager.KVObject) {
  console.log("onPushListener template.source=" + template.source)
  console.log("onPushListener source=" + JSON.stringify(source))
  console.log("onPushListener template=" + JSON.stringify(template))
  console.log("onPushListener data=" + JSON.stringify(data))
  console.log("onPushListener extraData=" + JSON.stringify(extraData))
}
```


### OnRequestEventCallback

type OnRequestEventCallback = (source: Want, name: string, data: KVObject) => RequestEventResult

对应request事件的监听回调函数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数        | 类型                                  | 必填   | 说明                |
| --------- | ----------------------------------- | ---- | ----------------- |
| source    | [Want](../apis-ability-kit/js-apis-application-want.md) | 是    | request请求发送方相关信息。 |
| name      | string                              | 是    | 模板名称。             |
| extraData | [KVObject](#kvobject)               | 是    | 附加数据。             |

**示例：**

```ts
import { pluginComponentManager } from '@kit.ArkUI'
import { Want } from '@kit.AbilityKit';

function onRequestListener(source: Want, name: string, data: pluginComponentManager.KVObject) {
  console.error("onRequestListener");
  console.log("onRequestListener source=" + JSON.stringify(source));
  console.log("onRequestListener name=" + name);
  console.log("onRequestListener data=" + JSON.stringify(data));
  let RtnData: Record<string, string | pluginComponentManager.KVObject> = {
    'template': "ets/pages/plugin.js",
    'data': data
  }
  return RtnData;
}
```

### push

push(param: PushParameters , callback: AsyncCallback&lt;void&gt;): void

组件提供者向组件使用者主动发送组件与数据。

**模型约束：** 此接口仅适用于FA模型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**
| 参数名      | 类型                                | 必填   | 说明           |
| -------- | --------------------------------- | ---- | ------------ |
| param    | [PushParameters](#pushparameters) | 是    | 组件使用者的详细信息。  |
| callback | AsyncCallback&lt;void&gt;         | 是    | 此次接口调用的异步回调。 |

**示例：**

```ts
import { pluginComponentManager } from '@kit.ArkUI'
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

### request

request(param: RequestParameters, callback: AsyncCallback&lt;RequestCallbackParameters&gt;): void

组件使用者向组件提供者主动请求组件。

**模型约束：** 此接口仅适用于FA模型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full


**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| param    | [RequestParameters](#requestparameters)                      | 是   | 组件模板的详细请求信息。                                     |
| callback | AsyncCallback&lt;[RequestCallbackParameters](#requestcallbackparameters)&gt; | 是   | 此次请求的异步回调，&nbsp;通过回调接口的参数返回接受请求的数据。 |

**示例：**

```ts
import { pluginComponentManager } from '@kit.ArkUI'
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

### on

on(eventType: string, callback: OnPushEventCallback | OnRequestEventCallback ): void

提供者监听"request"类型的事件，给使用者返回通过request接口主动请求的数据；使用者监听"push"类型的事件，接收提供者通过push接口主动推送的数据。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名       | 类型                                       | 必填   | 说明                                       |
| --------- | ---------------------------------------- | ---- | ---------------------------------------- |
| eventType | string                                   | 是    | 监听的事件类型，&nbsp;可选值为："push"&nbsp;、"request"。<br/>"push”：指组件提供者向使用者主动推送数据。<br/>"request”：指组件使用者向提供者主动请求数据。 |
| callback  | [OnPushEventCallback](#onpusheventcallback)&nbsp;\|&nbsp;[OnRequestEventCallback](#onrequesteventcallback) | 是    | 对应监听回调，push事件对应回调类型为[OnPushEventCallback](#onpusheventcallback)，request事件对应回调类型为[OnRequestEventCallback](#onrequesteventcallback) 。 |

**示例：**

```ts
import { pluginComponentManager, PluginComponentTemplate } from '@kit.ArkUI'
import { Want } from '@kit.AbilityKit';
function onPushListener(source:Want, template:PluginComponentTemplate, data:pluginComponentManager.KVObject, extraData:pluginComponentManager.KVObject) {
  console.log("onPushListener template.source=" + template.source)
  console.log("onPushListener source=" + JSON.stringify(source))
  console.log("onPushListener template=" + JSON.stringify(template))
  console.log("onPushListener data=" + JSON.stringify(data))
  console.log("onPushListener extraData=" + JSON.stringify(extraData))
}
function onRequestListener(source:Want, name:string, data:pluginComponentManager.KVObject) {
  console.error("onRequestListener");
  console.log("onRequestListener source=" + JSON.stringify(source));
  console.log("onRequestListener name=" + name);
  console.log("onRequestListener data=" + JSON.stringify(data));
  let RtnData:Record<string,string|pluginComponentManager.KVObject> = { 'template': "ets/pages/plugin.js", 'data': data }
  return RtnData;
}
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