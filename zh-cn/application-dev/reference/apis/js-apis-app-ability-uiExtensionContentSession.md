# @ohos.app.ability.UIExtensionContentSession (带界面扩展能力界面操作类)

UIExtensionContentSession是[UIExtensionAbility](js-apis-app-ability-uiExtensionAbility.md)加载界面内容时创建的实例对象，当UIExtensionComponent控件拉起指定的UIExtensionAbility时，UIExtensionAbility会创建UIExtensionContentSession对象，并通过[onSessionCreate](js-apis-app-ability-uiExtensionAbility.md#uiextensionabilityonsessioncreate)回调传递给开发者。一个UIExtensionComponent控件对应一个UIExtensionContentSession对象，提供界面加载，结果通知等方法。每个UIExtensionAbility的UIExtensionContentSession之间互不影响，可以各自进行操作。

> **说明：**
> 
> 本模块首批接口从API version 10 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import UIExtensionContentSession from '@ohos.app.ability.UIExtensionContentSession';
```

## UIExtensionContentSession.sendData

sendData(data: { [key: string]: Object }): void

发送数据给UIExtensionComponent控件。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| data | {[key:&nbsp;string]:&nbsp;Object} | 是 | 发送给UIExtensionComponent控件的数据参数。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000050 | Internal error. |

错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

## UIExtensionContentSession.setReceiveDataCallback

setReceiveDataCallback(callback: (data: { [key: string]: Object }) => void): void

设置从UIExtensionComponent控件接收数据的回调方法。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | (data: { [key: string]: Object }) => void | 是 | 接收数据的回调方法。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000050 | Internal error. |

错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

## UIExtensionContentSession.setReceiveDataForResultCallback<sup>11+</sup>

setReceiveDataForResultCallback(callback: (data: { [key: string]: Object }) => { [key: string]: Object }): void

设置从UIExtensionComponent控件接收数据带返回值的回调方法。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core


**参数：**

| 参数名 | 类型 | 必填 | 说明             |
| -------- | -------- | -------- |----------------|
| callback | (data: { [key: string]: Object }) => { [key: string]: Object } | 是 | 接收数据带返回值的回调方法。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000050 | Internal error. |

错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

## UIExtensionContentSession.loadContent

loadContent(path: string, storage?: LocalStorage): void;

为当前UIExtensionComponent控件对应的窗口加载与LocalStorage相关联的具体页面内容。

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名  | 类型                                            | 必填 | 说明                                                         |
| ------- | ----------------------------------------------- | ---- | ------------------------------------------------------------ |
| path    | string                                          | 是   | 设置加载页面的路径。                                         |
| storage | [LocalStorage](../../quick-start/arkts-localstorage.md) | 否   | 存储单元，为应用程序范围内的可变状态属性和非可变状态属性提供存储。默认为空。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000050 | Internal error. |

错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

## UIExtensionContentSession.startAbility

startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void;

启动Ability（callback形式）。

使用规则：
 - 对应UIExtensionComponent控件所在的应用需要处于前台获焦状态。
 - 调用方应用位于后台时，使用该接口启动Ability需申请`ohos.permission.START_ABILITIES_FROM_BACKGROUND`权限。
 - 跨应用场景下，目标Ability的exported属性若配置为false，调用方应用需申请`ohos.permission.START_INVISIBLE_ABILITY`权限。
 - 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | 启动Ability的want信息。 |
| callback | AsyncCallback&lt;void&gt; | 是 | callback形式返回启动结果。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation flag is forbidden.        |
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

## UIExtensionContentSession.startAbility

startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;): void;

启动Ability（callback形式）。

使用规则：
 - 对应UIExtensionComponent控件所在的应用需要处于前台获焦状态。
 - 调用方应用位于后台时，使用该接口启动Ability需申请`ohos.permission.START_ABILITIES_FROM_BACKGROUND`权限。
 - 跨应用场景下，目标Ability的exported属性若配置为false，调用方应用需申请`ohos.permission.START_INVISIBLE_ABILITY`权限。
 - 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md)  | 是 | 启动Ability的want信息。 |
| options | [StartOptions](js-apis-app-ability-startOptions.md) | 是 | 启动Ability所携带的参数。 |
| callback | AsyncCallback&lt;void&gt; | 是 | callback形式返回启动结果。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

## UIExtensionContentSession.startAbility

startAbility(want: Want, options?: StartOptions): Promise&lt;void&gt;;

启动Ability（promise形式）。

使用规则：
 - 对应UIExtensionComponent控件所在的应用需要处于前台获焦状态。
 - 调用方应用位于后台时，使用该接口启动Ability需申请`ohos.permission.START_ABILITIES_FROM_BACKGROUND`权限。
 - 跨应用场景下，目标Ability的exported属性若配置为false，调用方应用需申请`ohos.permission.START_INVISIBLE_ABILITY`权限。
 - 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | 启动Ability的want信息。 |
| options | [StartOptions](js-apis-app-ability-startOptions.md) | 否 | 启动Ability所携带的参数。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise形式返回启动结果。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation flag is forbidden.        |
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

## UIExtensionContentSession.startAbilityForResult

startAbilityForResult(want: Want, callback: AsyncCallback&lt;AbilityResult&gt;): void;

启动一个Ability，在Ability终止后返回结果给调用方(callback形式)。Ability的终止方式包括以下几种情况:
 - 正常情况下可通过调用[terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult)接口使之终止并且返回结果给调用方。
 - 异常情况下比如杀死Ability会返回异常信息给调用方, 异常信息中resultCode为-1。
 - 如果被启动的Ability模式是单实例模式, 不同应用多次调用该接口启动这个Ability，当这个Ability调用[terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult)接口使之终止时，只将正常结果返回给最后一个调用方, 其它调用方返回异常信息, 异常信息中resultCode为-1。

使用规则：
 - 对应UIExtensionComponent控件所在的应用需要处于前台获焦状态。
 - 调用方应用位于后台时，使用该接口启动Ability需申请`ohos.permission.START_ABILITIES_FROM_BACKGROUND`权限。
 - 跨应用场景下，目标Ability的exported属性若配置为false，调用方应用需申请`ohos.permission.START_INVISIBLE_ABILITY`权限。
 - 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-app-ability-want.md) | 是 | 启动Ability的want信息。 |
| callback | AsyncCallback&lt;[AbilityResult](js-apis-inner-ability-abilityResult.md)&gt; | 是 | 执行结果回调函数。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation flag is forbidden. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

## UIExtensionContentSession.startAbilityForResult

startAbilityForResult(want: Want, options: StartOptions, callback: AsyncCallback&lt;AbilityResult&gt;): void;

启动一个Ability，在Ability终止后返回结果给调用方(callback形式)。Ability的终止方式包括以下几种情况:
 - 正常情况下可通过调用[terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult)接口使之终止并且返回结果给调用方。
 - 异常情况下比如杀死Ability会返回异常信息给调用方，异常信息中resultCode为-1。
 - 如果被启动的Ability模式是单实例模式, 不同应用多次调用该接口启动这个Ability，当这个Ability调用[terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult)接口使之终止时，只将正常结果返回给最后一个调用方，其它调用方返回异常信息, 异常信息中resultCode为-1。

使用规则：
 - 对应UIExtensionComponent控件所在的应用需要处于前台获焦状态。
 - 调用方应用位于后台时，使用该接口启动Ability需申请`ohos.permission.START_ABILITIES_FROM_BACKGROUND`权限。
 - 跨应用场景下，目标Ability的exported属性若配置为false，调用方应用需申请`ohos.permission.START_INVISIBLE_ABILITY`权限。
 - 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-app-ability-want.md) | 是 | 启动Ability的want信息。 |
| options | [StartOptions](js-apis-app-ability-startOptions.md) | 是 | 启动Ability所携带的参数。 |
| callback | AsyncCallback&lt;[AbilityResult](js-apis-inner-ability-abilityResult.md)&gt; | 是 | 执行结果回调函数。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

## UIExtensionContentSession.startAbilityForResult

startAbilityForResult(want: Want, options?: StartOptions): Promise&lt;AbilityResult&gt;;

启动一个Ability，在Ability终止后返回结果给调用方(promise形式)。Ability的终止方式包括以下几种情况:
 - 正常情况下可通过调用[terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult)接口使之终止并且返回结果给调用方。
 - 异常情况下比如杀死Ability会返回异常信息给调用方, 异常信息中resultCode为-1。
 - 如果被启动的Ability模式是单实例模式, 不同应用多次调用该接口启动这个Ability，当这个Ability调用[terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult)接口使之终止时，只将正常结果返回给最后一个调用方, 其它调用方返回异常信息, 异常信息中resultCode为-1。

使用规则：
 - 对应UIExtensionComponent控件所在的应用需要处于前台获焦状态。
 - 调用方应用位于后台时，使用该接口启动Ability需申请`ohos.permission.START_ABILITIES_FROM_BACKGROUND`权限。
 - 跨应用场景下，目标Ability的exported属性若配置为false，调用方应用需申请`ohos.permission.START_INVISIBLE_ABILITY`权限。
 - 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | 启动Ability的want信息。 |
| options | [StartOptions](js-apis-app-ability-startOptions.md) | 否 | 启动Ability所携带的参数。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[AbilityResult](js-apis-inner-ability-abilityResult.md)&gt; | Promise形式返回执行结果。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation flag is forbidden. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

## UIExtensionContentSession.terminateSelf

terminateSelf(callback: AsyncCallback&lt;void&gt;): void;

停止UIExtensionContentSession对应的窗口界面对象（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | 是 | 停止UIExtensionContentSession对应的窗口界面对象的回调函数。 |

## UIExtensionContentSession.terminateSelf

terminateSelf(): Promise&lt;void&gt;;

停止UIExtensionContentSession对应的窗口界面对象（promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | promise形式返回停止UIExtensionContentSession对应的窗口界面对象。 |

## UIExtensionContentSession.terminateSelfWithResult

terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback&lt;void&gt;): void;

停止UIExtensionContentSession对应的窗口界面对象，并将结果返回给UIExtensionComponent控件（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| parameter | [AbilityResult](js-apis-inner-ability-abilityResult.md) | 是 | 返回给UIExtensionComponent控件的信息。 |
| callback | AsyncCallback&lt;void&gt; | 是 | callback形式返回停止结果。 |

## UIExtensionContentSession.terminateSelfWithResult

terminateSelfWithResult(parameter: AbilityResult): Promise&lt;void&gt;;

停止UIExtensionContentSession对应的窗口界面对象，并将结果返回给UIExtensionComponent控件（promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| parameter | [AbilityResult](js-apis-inner-ability-abilityResult.md) | 是 | 返回给UIExtensionComponent控件的信息。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | promise形式返回停止结果。 |

## UIExtensionContentSession.setWindowBackgroundColor

setWindowBackgroundColor(color: string): void

设置UIExtensionAbility加载界面的背景色。该接口需要在[loadContent()](#uiextensioncontentsessionloadcontent)调用生效后使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| color | string | 是 | 需要设置的背景色，为十六进制RGB或ARGB颜色，不区分大小写，例如`#00FF00`或`#FF00FF00`。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000050 | Internal error. |

错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

## UIExtensionContentSession.setWindowPrivacyMode

setWindowPrivacyMode(isPrivacyMode: boolean): Promise&lt;void&gt;

设置窗口是否为隐私模式，使用Promise异步回调。设置为隐私模式的窗口，窗口内容将无法被截屏或录屏。

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**需要权限：** ohos.permission.PRIVACY_WINDOW

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------------- | ------- | -- | ----------------------------------------------------- |
| isPrivacyMode | boolean | 是 | 窗口是否为隐私模式。true表示模式开启；false表示模式关闭。 |

**返回值：**

| 类型 | 说明 |
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

## UIExtensionContentSession.setWindowPrivacyMode

setWindowPrivacyMode(isPrivacyMode: boolean, callback: AsyncCallback&lt;void&gt;): void

设置窗口是否为隐私模式，使用callback异步回调。设置为隐私模式的窗口，窗口内容将无法被截屏或录屏。

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**需要权限：** ohos.permission.PRIVACY_WINDOW

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------------- | ------------------------- | -- | ------------------------------------------------------ |
| isPrivacyMode | boolean                   | 是 | 窗口是否为隐私模式。true表示模式开启；false表示模式关闭。  |
| callback      | AsyncCallback&lt;void&gt; | 是 | 回调函数。                                              |

## UIAbilityContext.startAbilityByType<sup>11+</sup>

startAbilityByType(type: string, wantParam: Record<string, Object>,
    abilityStartCallback: AbilityStartCallback, callback: AsyncCallback\<void>) : void;

通过type隐式启动UIExtensionAbility。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 显示拉起的UIExtensionAbility类型。 |
| wantParam | {[key: string]: any} | 是 | 表示扩展参数。 |
| abilityStartCallback | [AbilityStartCallback](js-apis-inner-application-abilityStartCallback.md) | 是 | 启动失败后的回调。 |
| callback | AsyncCallback<void> | 是 | 回调函数，返回接口调用是否成功的结果。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000050 | Internal error. |
| 16200001 | The caller has been released. |

错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

## UIAbilityContext.startAbilityByType<sup>11+</sup>

startAbilityByType(type: string, wantParam: Record<string, Object>,
    abilityStartCallback: AbilityStartCallback) : Promise\<void>;

通过type隐式启动UIExtensionAbility。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 显示拉起的UIExtensionAbility类型。 |
| wantParam | {[key: string]: Object} | 是 | 表示扩展参数。 |
| abilityStartCallback | [AbilityStartCallback](js-apis-inner-application-abilityStartCallback.md) | 是 | 启动失败后的回调。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000050 | Internal error. |
| 16200001 | The caller has been released. |

错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

## UIExtensionContentSession.startAbilityAsCaller<sup>11+</sup>

startAbilityAsCaller(want: Want, callback: AsyncCallback\<void>): void

初始Ability将自己的caller信息（如BundleName、AbilityName等）置于want参数中，传递给中间层的ExtensionABility。当ExtensionABility通过该接口拉起另外一个Ability，被拉起的Abiltiy可以从onCreate生命周期获取到初始Abiltiy的caller信息。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | 启动Ability的want信息。 |
| callback | AsyncCallback\<void> | 是 | 回调函数。当启动Ability成功，err为undefined，否则为错误对象。 |


**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation flag is forbidden. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled. |
| 16000013 | The application is controlled by EDM. |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

## UIExtensionContentSession.startAbilityAsCaller<sup>11+</sup>

startAbilityAsCaller(want: Want, options: StartOptions, callback: AsyncCallback\<void>): void

初始Ability将自己的caller信息（如BundleName、AbilityName等）置于want参数中，传递给中间层的ExtensionABility。当ExtensionABility通过该接口拉起另外一个Ability，被拉起的Abiltiy可以从onCreate生命周期获取到初始Abiltiy的caller信息。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | 启动Ability的want信息。 |
| options | [StartOptions](js-apis-app-ability-startOptions.md) | 是 | 启动Ability所携带的参数。 |
| callback | AsyncCallback\<void> | 是 | 回调函数。当启动Ability成功，err为undefined，否则为错误对象。 |


**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled. |
| 16000013 | The application is controlled by EDM. |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

## UIExtensionContentSession.startAbilityAsCaller<sup>11+</sup>

startAbilityAsCaller(want: Want, options?: StartOptions): Promise\<void>

初始Ability将自己的caller信息（如BundleName、AbilityName等）置于want参数中，传递给中间层的ExtensionABility。当ExtensionABility通过该接口拉起另外一个Ability，被拉起的Abiltiy可以从onCreate生命周期获取到初始Abiltiy的caller信息。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | 启动Ability的want信息。 |
| options | [StartOptions](js-apis-app-ability-startOptions.md) | 是 | 启动Ability所携带的参数。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation flag is forbidden. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled. |
| 16000013 | The application is controlled by EDM. |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。