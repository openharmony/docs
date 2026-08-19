# @ohos.pluginComponent (PluginComponentManager)(系统接口)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @dutie123-->
<!--Designer: @dutie123-->
<!--Tester: @fredyuan0912-->
<!--Adviser: @Brilliantry_Rui-->

用于组件使用方向组件提供方请求组件与数据，组件提供方向组件使用方发送组件模板和数据。该模块适用于跨Ability或跨应用插件化组件展示的场景，可实现组件模板与业务数据的动态分发与加载，支持组件提供方与使用方之间的解耦。如需实现组件模板的显示，请参考[PluginComponent](arkui-ts/ts-basic-components-plugincomponent-sys.md)。

> **说明：**
>
> - 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.pluginComponent (PluginComponentManager)](js-apis-plugincomponent.md)。

## 导入模块

```ts
import { pluginComponentManager } from '@kit.ArkUI';
```

### PushParameterForStage<sup>9+</sup>

用于设置Stage模型下使用pluginComponentManager.push方法时需要传递的参数。

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅适用于[Stage模型](arkui-ts/ts-basic-components-plugincomponent-sys.md#stage模型)。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称        | 类型                                  | 只读 | 可选   | 说明                                       |
| --------- | ----------------------------------- | ---- | ---- | ---------------------------------------- |
| owner     | [Want](../apis-ability-kit/js-apis-application-want.md) | 否 | 否    | 组件提供方Ability信息。                          |
| target    | [Want](../apis-ability-kit/js-apis-application-want.md) | 否 | 否    | 组件使用方Ability信息。                          |
| name      | string                              | 否 | 否    | 组件名称，当jsonPath不为空时需与[external.json](#externaljson文件说明)文件中的键名一致。                                    |
| data      | [KVObject](js-apis-plugincomponent.md#kvobject)      |    否     | 否    | 组件数据，以键值对形式存储。用于向组件使用方传递业务数据，如页面路径（key为'js'，value为模板路径字符串）及自定义数据字段。                                   |
| extraData | [KVObject](js-apis-plugincomponent.md#kvobject)          | 否    | 否    | 附加数据，用于在发送组件时传递额外的自定义数据，与组件数据（data）区分，可根据业务需要设置。                                   |
| jsonPath  | string                         |  否   | 是    | 存放模板路径的[external.json](#externaljson文件说明)文件的路径。当jsonPath不为空时，不触发Push通信，组件模板路径从external.json文件中读取；当jsonPath为空（默认）时，通过Push通信向组件使用方发送组件模板。 |

### RequestParameterForStage<sup>9+</sup>

用于设置Stage模型下使用pluginComponentManager.request方法时需要传递的参数。

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅适用于[Stage模型](arkui-ts/ts-basic-components-plugincomponent-sys.md#stage模型)。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称       | 类型                           |   只读    | 可选   | 说明                                       |
| -------- | ----------------------------------- | ---- | ---- | ---------------------------------------- |
| owner    | [Want](../apis-ability-kit/js-apis-application-want.md)| 否 | 否    | 组件使用方Ability信息。                          |
| target   | [Want](../apis-ability-kit/js-apis-application-want.md) | 否 | 否    | 组件提供方Ability信息。                          |
| name     | string                         |  否   | 否    | 请求组件名称，当jsonPath不为空时需与[external.json](#externaljson文件说明)文件中的键名一致。                                  |
| data     | [KVObject](js-apis-plugincomponent.md#kvobject)        |   否    | 否    | 附加数据，以键值对形式存储。用于向组件提供方传递请求时的自定义业务参数，以便提供方根据这些数据返回合适的组件模板。                                    |
| jsonPath | string | 否 | 是 | 存放模板路径的[external.json](#externaljson文件说明)文件的路径。当需要从external.json文件加载模板路径而非通过Request通信获取模板时传入此参数。当jsonPath字段不为空时不触发Request通信；当jsonPath为空（默认）时，通过Request通信向组件提供方请求组件模板。 |

### push<sup>9+</sup>

push(param: PushParameterForStage, callback: AsyncCallback&lt;void&gt;): void

组件提供方向组件使用方主动发送组件与数据。适用于需要主动推送插件组件模板的场景，例如跨应用内容分享、桌面卡片主动刷新等。push 由组件提供方主动发起推送，request 由组件使用方主动发起请求；注意两者参数结构相近但 owner/target 含义相反，请勿混用。组件使用方需通过onPush事件监听接收数据，事件监听接口请参见[@ohos.pluginComponent (PluginComponentManager)](js-apis-plugincomponent.md#plugincomponentmanageron)。

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅适用于[Stage模型](arkui-ts/ts-basic-components-plugincomponent-sys.md#stage模型)。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**
| 参数名      | 类型                                       | 必填   | 说明           |
| -------- | ---------------------------------------- | ---- | ------------ |
| param    | [PushParameterForStage](#pushparameterforstage9) | 是    | 组件提供方要发送的参数。  |
| callback | AsyncCallback&lt;void&gt;                | 是    | 此次接口调用的异步回调。 |

**示例：**

```ts
import { pluginComponentManager } from '@kit.ArkUI';

pluginComponentManager.push(
  {
    owner: {
      bundleName: "com.example.provider",
      abilityName: "com.example.provider.MainAbility",
    },
    target: {
      bundleName: "com.example.user",
      abilityName: "com.example.user.MainAbility",
    },
    name: "ets/pages/plugin2.js",
    data: {
      "js": "ets/pages/plugin.js",
      "key1": 1111,
    },
    extraData: {
      "extraStr": "this is push event"
    },
    jsonPath: "",
  },
  (err, data) => {
    if (err) {
      console.error(`Failed to push. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info("push_callback:data: ", JSON.stringify(data));
    console.info("push_callback: push ok!");
  }
);
```

### request<sup>9+</sup>

request(param: RequestParameterForStage, callback: AsyncCallback&lt;RequestCallbackParameters&gt;): void

组件使用方向组件提供方主动请求组件。适用于使用方需要按需动态获取插件组件模板的场景，例如动态加载其他应用提供的插件内容、按需展示跨应用组件等。组件提供方需通过onRequest事件监听响应请求，并通过回调返回组件模板信息，事件监听接口请参见[@ohos.pluginComponent (PluginComponentManager)](js-apis-plugincomponent.md#plugincomponentmanageron)。

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅适用于[Stage模型](arkui-ts/ts-basic-components-plugincomponent-sys.md#stage模型)。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                  |
| -------- | ---------------------------------------- | ---- | ----------------------------------- |
| param    | [RequestParameterForStage](#requestparameterforstage9) | 是    | 组件模板的详细请求信息。                        |
| callback | AsyncCallback&lt;[RequestCallbackParameters](js-apis-plugincomponent.md#requestcallbackparameters)&gt; | 是    | 此次请求的异步回调，通过回调接口的参数返回请求响应的数据。 |

**示例：**

```ts
import { pluginComponentManager } from '@kit.ArkUI';

pluginComponentManager.request(
  {
    owner: {
      bundleName: "com.example.user",
      abilityName: "com.example.user.MainAbility",
    },
    target: {
      bundleName: "com.example.provider",
      abilityName: "com.example.provider.MainAbility",
    },
    name: "plugintemplate",
    data: {
      "key1": "myapplication plugin component test",
    },
    jsonPath: "",
  },
  (err, data) => {
    if (err) {
      console.error(`Failed to request. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    if (!data) {
      return;
    }
    console.info("request_callback: componentTemplate.ability=" + data.componentTemplate.ability);
    console.info("request_callback: componentTemplate.source=" + data.componentTemplate.source);
  }
);
```

## external.json文件说明

external.json文件由开发者创建。external.json中以组件名称name作为关键字，对应模板路径作为值，以键值对形式存放。

**示例：**

```json
{
  "PluginProviderExample": "ets/pages/PluginProviderExample.js",
  "plugintemplate2": "ets/pages/plugintemplate2.js"
}

```