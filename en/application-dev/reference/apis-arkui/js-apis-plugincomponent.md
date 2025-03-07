# @ohos.pluginComponent (PluginComponentManager)

The **PluginComponentManager** module provides APIs for the **PluginComponent** user to request components and data and send component templates and data.

>  **NOTE**
>
>  - The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { pluginComponentManager } from '@kit.ArkUI'
```

## PluginComponentTemplate

Describes the **PluginComponent** template parameters.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name   | Type  | Mandatory | Description                       |
| ------- | ------ | ---- | --------------------------- |
| source  | string | Yes  | Component template name.               |
| ability | string | Yes  | Bundle name of the provider ability. |

## PluginComponentManager

Implements a plugin component manager.

### KVObject

type KVObject = { [key: string]: number | string | boolean | [] | KVObject }

Stores information in key-value pairs in JSON format.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full


| Value Range             | Description                                    |
| --------------------- | ---------------------------------------- |
| [key: string]         | Keyword. The value is a string and can be an empty string. |
| number                | Key value of the number type.                |
| string                | Key value of the string type. The value can be an empty string. |
| boolean               | Key value of the Boolean type.              |
| []                    | Key value. The value can be [].                      |
| [KVObject](#kvobject) | Key value of the KVObject type.            |


### PushParameters

Sets the parameters to be passed in the **PluginManager.Push** API in the FA model.

**Model restriction**: This API can be used only in the FA model.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name       | Type                                 | Mandatory  | Description                                      |
| --------- | ----------------------------------- | ---- | ---------------------------------------- |
| want      | [Want](../apis-ability-kit/js-apis-application-want.md) | Yes   | Ability information of the component user.                         |
| name      | string                              | Yes   | Component name.                                   |
| data      | [KVObject](#kvobject)               | Yes   | Component data value.                                  |
| extraData | [KVObject](#kvobject)               | Yes   | Additional data value.                                  |
| jsonPath  | string                              | No   | Path to the [external.json](#about-the-externaljson-file) file that stores the template path. |

### RequestParameters

Sets the parameters to be passed in the **PluginManager.Request** API in the FA model.

**Model restriction**: This API can be used only in the FA model.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name      | Type                                 | Mandatory  | Description                                      |
| -------- | ----------------------------------- | ---- | ---------------------------------------- |
| want     | [Want](../apis-ability-kit/js-apis-application-want.md) | Yes   | Ability information of the component provider.                         |
| name     | string                              | Yes   | Name of the requested component.                                 |
| data     | [KVObject](#kvobject)               | Yes   | Additional data.                                   |
| jsonPath | string                              | No   | Path to the [external.json](#about-the-externaljson-file) file that stores the template path. Request communication is not triggered when **jsonPath** is not empty or not set. |

### RequestCallbackParameters

Provides the result returned after the **PluginManager.Request** API is called.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name               | Type                                      | Mandatory  | Description   |
| ----------------- | ---------------------------------------- | ---- | ----- |
| componentTemplate | [PluginComponentTemplate](#plugincomponenttemplate) | Yes   | Component template. |
| data              | [KVObject](#kvobject)                    | Yes   | Component data. |
| extraData         | [KVObject](#kvobject)                    | Yes   | Additional data. |

### RequestEventResult

Provides the result returned after the request listener is registered and the requested event is received.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name       | Type                   | Mandatory  | Description   |
| --------- | --------------------- | ---- | ----- |
| template  | string                | No   | Component template. |
| data      | [KVObject](#kvobject) | No   | Component data. |
| extraData | [KVObject](#kvobject) | No   | Additional data. |

### OnPushEventCallback

type OnPushEventCallback = (source: Want, template: PluginComponentTemplate, data: KVObject,
    extraData: KVObject) => void

Registers the listener for the push event.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name       | Type                                      | Mandatory  | Description                    |
| --------- | ---------------------------------------- | ---- | ---------------------- |
| source    | [Want](../apis-ability-kit/js-apis-application-want.md)      | Yes   | Information about the push request sender.        |
| template  | [PluginComponentTemplate](#plugincomponenttemplate) | Yes   | Name of the request component template for the push request sender. |
| data      | [KVObject](#kvobject)                    | Yes   | Data.                   |
| extraData | [KVObject](#kvobject)                    | Yes   | Additional data.                 |

**Example**

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

Registers the listener for the request event.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name       | Type                                 | Mandatory  | Description               |
| --------- | ----------------------------------- | ---- | ----------------- |
| source    | [Want](../apis-ability-kit/js-apis-application-want.md) | Yes   | Information about the request sender. |
| name      | string                              | Yes   | Template name.            |
| extraData | [KVObject](#kvobject)               | Yes   | Additional data.            |

**Example**

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

Pushes the component and data to the component user.

**Model restriction**: This API can be used only in the FA model.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**
| Name     | Type                               | Mandatory  | Description          |
| -------- | --------------------------------- | ---- | ------------ |
| param    | [PushParameters](#pushparameters) | Yes   | Information about the component user. |
| callback | AsyncCallback&lt;void&gt;         | Yes   | Asynchronous callback used to return the result. |

**Example**

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

Requests the component from the component provider.

**Model restriction**: This API can be used only in the FA model.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full


**Parameters**

| Name  | Type                                                        | Mandatory | Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| param    | [RequestParameters](#requestparameters)                      | Yes  | Information about the component request.                                    |
| callback | AsyncCallback&lt;[RequestCallbackParameters](#requestcallbackparameters)&gt; | Yes  | Asynchronous callback used to return the requested data. |

**Example**

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

Listens for events of the request type and returns the requested data, or listens for events of the push type and receives the data pushed by the provider.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name      | Type                                      | Mandatory  | Description                                      |
| --------- | ---------------------------------------- | ---- | ---------------------------------------- |
| eventType | string                                   | Yes   | Type of the event to listen for. The options are as follows:<br>**"push"**: The component provider pushes data to the component user.<br>**"request"**: The component user proactively requests data from the component provider.|
| callback  | [OnPushEventCallback](#onpusheventcallback) \| [OnRequestEventCallback](#onrequesteventcallback) | Yes   | Callback used to return the result. The type is [OnPushEventCallback](#onpusheventcallback) for the push event and [OnRequestEventCallback](#onrequesteventcallback) for the request event. |

**Example**

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

## About the external.json File

The **external.json** file is created by developers. It stores component names and template paths in key-value pairs. The component name is used as the keyword, and the corresponding template path is used as the value.

**Example**

```json
{
  "PluginProviderExample": "ets/pages/PluginProviderExample.js",
  "plugintemplate2": "ets/pages/plugintemplate2.js"
}

```
