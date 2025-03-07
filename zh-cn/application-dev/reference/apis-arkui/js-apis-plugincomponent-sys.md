# @ohos.pluginComponent (PluginComponentManager)(系统接口)

用于给插件组件的使用方请求组件与数据，使用方发送组件模板和数据。如需实现插件模板的显示，请参考[PluginComponent](arkui-ts/ts-basic-components-plugincomponent-sys.md)。

>  **说明：**
>
>  - 本模块首批接口从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
>  - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.pluginComponent (PluginComponentManager)](js-apis-plugincomponent.md)。

## 导入模块

```ts
import { pluginComponentManager } from '@kit.ArkUI'
```

### PushParameterForStage

用于设置Stage模型下使用PluginManager.Push方法时候的需要传递的参数。

**模型约束：** 此接口仅适用于[Stage模型](arkui-ts/ts-basic-components-plugincomponent-sys.md#stage模型)。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称        | 类型                                  | 必填   | 说明                                       |
| --------- | ----------------------------------- | ---- | ---------------------------------------- |
| owner     | [Want](../apis-ability-kit/js-apis-application-want.md) | 是    | 组件提供方Ability信息。                          |
| target    | [Want](../apis-ability-kit/js-apis-application-want.md) | 是    | 组件使用方Ability信息。                          |
| name      | string                              | 是    | 组件名称。                                    |
| data      | [KVObject](js-apis-plugincomponent.md#kvobject)               | 是    | 组件数据值。                                   |
| extraData | [KVObject](js-apis-plugincomponent.md#kvobject)               | 是    | 附加数据值。                                   |
| jsonPath  | string                              | 否    | 存放模板路径的[external.json](#externaljson文件说明)文件的路径。 |

### RequestParameterForStage

用于设置Stage模型下使用PluginManager.Request方法时候的需要传递的参数。

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅适用于[Stage模型](arkui-ts/ts-basic-components-plugincomponent-sys.md#stage模型)。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称       | 类型                                  | 必填   | 说明                                       |
| -------- | ----------------------------------- | ---- | ---------------------------------------- |
| owner    | [Want](../apis-ability-kit/js-apis-application-want.md) | 是    | 组件使用方Ability信息。                          |
| target   | [Want](../apis-ability-kit/js-apis-application-want.md) | 是    | 组件提供方Ability信息。                          |
| name     | string                              | 是    | 请求组件名称。                                  |
| data     | [KVObject](js-apis-plugincomponent.md#kvobject)               | 是    | 附加数据。                                    |
| jsonPath | string                              | 否    | 存放模板路径的[external.json](#externaljson文件说明)文件的路径。jsonPath字段不为空或者未设置的时候不触发Request通信。 |

### push

push(param: PushParameterForStage, callback: AsyncCallback&lt;void&gt;): void

组件提供方向组件使用方主动发送组件与数据。

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅适用于[Stage模型](arkui-ts/ts-basic-components-plugincomponent-sys.md#stage模型)。

**参数：**
| 参数名      | 类型                                       | 必填   | 说明           |
| -------- | ---------------------------------------- | ---- | ------------ |
| param    | [PushParameterForStage](#pushparameterforstage) | 是    | 组件使用方的详细信息。  |
| callback | AsyncCallback&lt;void&gt;                | 是    | 此次接口调用的异步回调。 |

**示例：**

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

组件使用方向组件提供方主动请求组件。

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅适用于[Stage模型](arkui-ts/ts-basic-components-plugincomponent-sys.md#stage模型)。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                  |
| -------- | ---------------------------------------- | ---- | ----------------------------------- |
| param    | [RequestParameterForStage](js-apis-plugincomponent-sys.md#requestparameterforstage) | 是    | 组件模板的详细请求信息。                        |
| callback | AsyncCallback&lt;[RequestCallbackParameters](js-apis-plugincomponent.md#requestcallbackparameters)&nbsp;\|&nbsp;void&gt; | 是    | 此次请求的异步回调，&nbsp;通过回调接口的参数返回接受请求的数据。 |

**示例：**

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

## external.json文件说明

external.json文件由开发者创建。external.json中以键值对形式存放组件名称以及对应模板路径。以组件名称name作为关键字，对应模板路径作为值。

**示例**

```json
{
  "PluginProviderExample": "ets/pages/PluginProviderExample.js",
  "plugintemplate2": "ets/pages/plugintemplate2.js"
}

```