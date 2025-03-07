# @ohos.pluginComponent (PluginComponentManager) (System API)

The **PluginComponentManager** module provides APIs for the **PluginComponent** user to request components and data and send component templates and data. For details about how to display the **PluginComponent** template, see [PluginComponent](arkui-ts/ts-basic-components-plugincomponent-sys.md).

>  **NOTE**
>
>  - The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
>  - This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.pluginComponent (PluginComponentManager)](js-apis-plugincomponent.md).

## Modules to Import

```ts
import { pluginComponentManager } from '@kit.ArkUI'
```

### PushParameterForStage

Sets the parameters to be passed in the **PluginManager.Push** API in the stage model.

**Model restriction**: This API can be used only in the [stage model](arkui-ts/ts-basic-components-plugincomponent-sys.md#stage-model).

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name       | Type                                 | Mandatory  | Description                                      |
| --------- | ----------------------------------- | ---- | ---------------------------------------- |
| owner     | [Want](../apis-ability-kit/js-apis-application-want.md) | Yes   | Ability information of the component provider.                         |
| target    | [Want](../apis-ability-kit/js-apis-application-want.md) | Yes   | Ability information of the component user.                         |
| name      | string                              | Yes   | Component name.                                   |
| data      | [KVObject](js-apis-plugincomponent.md#kvobject)               | Yes   | Component data value.                                  |
| extraData | [KVObject](js-apis-plugincomponent.md#kvobject)               | Yes   | Additional data value.                                  |
| jsonPath  | string                              | No   | Path to the [external.json](#about-the-externaljson-file) file that stores the template path. |

### RequestParameterForStage

Sets the parameters to be passed in the **PluginManager.Request** API in the stage model.

**System API**: This is a system API.

**Model restriction**: This API can be used only in the [stage model](arkui-ts/ts-basic-components-plugincomponent-sys.md#stage-model).

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name      | Type                                 | Mandatory  | Description                                      |
| -------- | ----------------------------------- | ---- | ---------------------------------------- |
| owner    | [Want](../apis-ability-kit/js-apis-application-want.md) | Yes   | Ability information of the component user.                         |
| target   | [Want](../apis-ability-kit/js-apis-application-want.md) | Yes   | Ability information of the component provider.                         |
| name     | string                              | Yes   | Name of the requested component.                                 |
| data     | [KVObject](js-apis-plugincomponent.md#kvobject)               | Yes   | Additional data.                                   |
| jsonPath | string                              | No   | Path to the [external.json](#about-the-externaljson-file) file that stores the template path. Request communication is not triggered when **jsonPath** is not empty or not set. |

### push

push(param: PushParameterForStage, callback: AsyncCallback&lt;void&gt;): void

Pushes the component and data to the component user.

**System API**: This is a system API.

**Model restriction**: This API can be used only in the [stage model](arkui-ts/ts-basic-components-plugincomponent-sys.md#stage-model).

**Parameters**
| Name     | Type                                      | Mandatory  | Description          |
| -------- | ---------------------------------------- | ---- | ------------ |
| param    | [PushParameterForStage](#pushparameterforstage) | Yes   | Information about the component user. |
| callback | AsyncCallback&lt;void&gt;                | Yes   | Asynchronous callback used to return the result. |

**Example**

```ts
import { pluginComponentManager } from '@kit.ArkUI'
pluginComponentManager.push(
  {
    owner: {
      bundleName: "com.example.provider",
      abilityName: "com.example.provider.MainAbility"
    },
    target: {
      bundleName: "com.example.user",
      abilityName: "com.example.user.MainAbility",
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

request(param: RequestParameterForStage, callback: AsyncCallback&lt;RequestCallbackParameters&gt;): void

Requests the component from the component provider.

**System API**: This is a system API.

**Model restriction**: This API can be used only in the [stage model](arkui-ts/ts-basic-components-plugincomponent-sys.md#stage-model).

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                 |
| -------- | ---------------------------------------- | ---- | ----------------------------------- |
| param    | [RequestParameterForStage](js-apis-plugincomponent-sys.md#requestparameterforstage) | Yes   | Information about the component request.                       |
| callback | AsyncCallback&lt;[RequestCallbackParameters](js-apis-plugincomponent.md#requestcallbackparameters) \| void&gt; | Yes   | Asynchronous callback used to return the requested data. |

**Example**

```ts
import { pluginComponentManager } from '@kit.ArkUI'
pluginComponentManager.request(
  {
    owner: {
      bundleName: "com.example.user",
      abilityName: "com.example.user.MainAbility"
    },
    target: {
      bundleName: "com.example.provider",
      abilityName: "com.example.provider.MainAbility",
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

## About the external.json File

The **external.json** file is created by developers. It stores component names and template paths in key-value pairs. The component name is used as the keyword, and the corresponding template path is used as the value.

**Example**

```json
{
  "PluginProviderExample": "ets/pages/PluginProviderExample.js",
  "plugintemplate2": "ets/pages/plugintemplate2.js"
}

```
