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

错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)

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

错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)

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

错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)

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
| Promise&lt;void&gt; | 停止UIExtensionContentSession对应的窗口界面对象的回调函数。 |

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

错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)

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
