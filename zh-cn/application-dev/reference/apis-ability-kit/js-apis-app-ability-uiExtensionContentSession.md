# @ohos.app.ability.UIExtensionContentSession (带界面扩展能力界面操作类)

UIExtensionContentSession是[UIExtensionAbility](js-apis-app-ability-uiExtensionAbility.md)加载界面内容时创建的实例对象，当UIExtensionComponent控件拉起指定的UIExtensionAbility时，UIExtensionAbility会创建UIExtensionContentSession对象，并通过[onSessionCreate](js-apis-app-ability-uiExtensionAbility.md#uiextensionabilityonsessioncreate)回调传递给开发者。一个UIExtensionComponent控件对应一个UIExtensionContentSession对象，提供界面加载，结果通知等方法。每个UIExtensionAbility的UIExtensionContentSession之间互不影响，可以各自进行操作。

> **说明：**
>
> 本模块首批接口从API version 10 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { UIExtensionContentSession } from '@kit.AbilityKit';
```

## UIExtensionContentSession.loadContent

loadContent(path: string, storage?: LocalStorage): void

为当前UIExtensionComponent控件对应的窗口加载与LocalStorage相关联的具体页面内容。

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名  | 类型                                            | 必填 | 说明                                                         |
| ------- | ----------------------------------------------- | ---- | ------------------------------------------------------------ |
| path    | string                                          | 是   | 设置加载页面的路径。                                         |
| storage | [LocalStorage](../../quick-start/arkts-localstorage.md) | 否   | 存储单元，为应用程序范围内的可变状态属性和非可变状态属性提供存储。默认为空。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000050 | Internal error. |

## UIExtensionContentSession.terminateSelf

terminateSelf(callback: AsyncCallback&lt;void&gt;): void

停止UIExtensionContentSession对应的窗口界面对象。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当停止UIExtensionContentSession对应的窗口界面对象成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

## UIExtensionContentSession.terminateSelf

terminateSelf(): Promise&lt;void&gt;

停止UIExtensionContentSession对应的窗口界面对象。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

## UIExtensionContentSession.terminateSelfWithResult

terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback&lt;void&gt;): void

停止UIExtensionContentSession对应的窗口界面对象，并将结果返回给UIExtensionComponent控件。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| parameter | [AbilityResult](js-apis-inner-ability-abilityResult.md) | 是 | 返回给UIExtensionComponent控件的信息。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当停止成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

## UIExtensionContentSession.terminateSelfWithResult

terminateSelfWithResult(parameter: AbilityResult): Promise&lt;void&gt;

停止UIExtensionContentSession对应的窗口界面对象，并将结果返回给UIExtensionComponent控件。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| parameter | [AbilityResult](js-apis-inner-ability-abilityResult.md) | 是 | 返回给UIExtensionComponent控件的信息。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

## UIExtensionContentSession.setWindowPrivacyMode

setWindowPrivacyMode(isPrivacyMode: boolean): Promise&lt;void&gt;

设置窗口是否为隐私模式。设置为隐私模式的窗口，窗口内容将无法被截屏或录屏。使用Promise异步回调。

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**需要权限：** ohos.permission.PRIVACY_WINDOW

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------------- | ------- | -- | ----------------------------------------------------- |
| isPrivacyMode | boolean | 是 | 窗口是否为隐私模式。true表示模式开启；false表示模式关闭。 |

**返回值：**

| 类型 | 说明 |
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201      | The application does not have permission to call the interface. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

## UIExtensionContentSession.setWindowPrivacyMode

setWindowPrivacyMode(isPrivacyMode: boolean, callback: AsyncCallback&lt;void&gt;): void

设置窗口是否为隐私模式。设置为隐私模式的窗口，窗口内容将无法被截屏或录屏。使用callback异步回调。

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**需要权限：** ohos.permission.PRIVACY_WINDOW

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------------- | ------------------------- | -- | ------------------------------------------------------ |
| isPrivacyMode | boolean                   | 是 | 窗口是否为隐私模式。true表示模式开启；false表示模式关闭。  |
| callback      | AsyncCallback&lt;void&gt; | 是 | 回调函数。当设置成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201      | The application does not have permission to call the interface. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

## UIExtensionContentSession.startAbilityByType<sup>11+</sup>

startAbilityByType(type: string, wantParam: Record<string, Object>,
    abilityStartCallback: AbilityStartCallback, callback: AsyncCallback\<void>): void

通过type隐式启动UIExtensionAbility。使用callback异步回调。仅支持处于前台的应用调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 显示拉起的UIExtensionAbility类型<!--Del-->，取值详见[通过startAbilityByType接口拉起垂类面板](../../application-models/start-intent-panel.md#匹配规则)<!--DelEnd-->。 |
| wantParam | Record<string, Object> | 是 | 表示扩展参数。 |
| abilityStartCallback | [AbilityStartCallback](js-apis-inner-application-abilityStartCallback.md) | 是 | 回调函数，返回启动失败后的详细错误信息。 |
| callback | AsyncCallback\<void> | 是 |回调函数。当启动Ability成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000050 | Internal error. |

## UIExtensionContentSession.startAbilityByType<sup>11+</sup>

startAbilityByType(type: string, wantParam: Record<string, Object>,
    abilityStartCallback: AbilityStartCallback): Promise\<void>

通过type隐式启动UIExtensionAbility。使用Promise异步回调。仅支持处于前台的应用调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 显示拉起的UIExtensionAbility类型<!--Del-->，取值详见[通过startAbilityByType接口拉起垂类面板](../../application-models/start-intent-panel.md#匹配规则)<!--DelEnd-->。 |
| wantParam | Record<string, Object> | 是 | 表示扩展参数。 |
| abilityStartCallback | [AbilityStartCallback](js-apis-inner-application-abilityStartCallback.md) | 是 | 回调函数，返回启动失败后的详细错误信息。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000050 | Internal error. |

## UIExtensionContentSession.getUIExtensionWindowProxy<sup>12+</sup>

getUIExtensionWindowProxy(): uiExtension.WindowProxy

获取UIExtension窗口代理。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| uiExtension.WindowProxy | 返回UIExtension的窗口代理。 |

**错误码：**

以下错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000050 | Internal error. |

**示例：**

```ts
// Index.ets
import { UIExtensionContentSession } from '@kit.AbilityKit';
import uiExtension from '@ohos.arkui.uiExtension';

let storage = LocalStorage.getShared();

@Entry(storage)
@Component
struct Extension {
  @State message: string = 'EmbeddedUIExtensionAbility Index';
  private session: UIExtensionContentSession | undefined = storage.get<UIExtensionContentSession>('session');
  private extensionWindow: uiExtension.WindowProxy | undefined = this.session?.getUIExtensionWindowProxy();

  aboutToAppear(): void {
    this.extensionWindow?.on('windowSizeChange', (size) => {
      console.info(`size = ${JSON.stringify(size)}`);
    });
    this.extensionWindow?.on('avoidAreaChange', (info) => {
      console.info(`type = ${JSON.stringify(info.type)}, area = ${JSON.stringify(info.area)}`);
    });
  }

  aboutToDisappear(): void {
    this.extensionWindow?.off('windowSizeChange');
    this.extensionWindow?.off('avoidAreaChange');
  }

  build() {
    Column() {
      Text(this.message)
        .fontSize(20)
        .fontWeight(FontWeight.Bold)
    }
    .width('100%')
  }
}
```