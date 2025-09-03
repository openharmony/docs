# @ohos.arkui.uiExtension (uiExtension)(系统接口)
<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @waterwin-->
<!--Designer: @nyankomiya-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->

用于EmbeddedUIExtensionAbility（或UIExtensionAbility）中获取宿主应用的窗口信息或对应的EmbeddedComponent（或UIExtensionComponent）组件的信息。

> **说明**
>
> 从API version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> 本文仅介绍当前模块的系统接口，其他公开接口参见[@ohos.arkui.uiExtension (uiExtension)](js-apis-arkui-uiExtension.md)。

## 导入模块

```
import { uiExtension } from '@kit.ArkUI';
```

## WindowProxy

UIExtension宿主窗代理。

### hideNonSecureWindows

hideNonSecureWindows(shouldHide: boolean): Promise\<void>

设置是否隐藏不安全窗口，使用Promise异步回调。

> **说明：**
>
> - 不安全窗口是指可能遮挡[EmbeddedComponent](arkui-ts/ts-container-embedded-component.md)（或[UIExtensionComponent](arkui-ts/ts-container-ui-extension-component-sys.md)）组件的窗口，如全局悬浮窗、宿主子窗口和宿主创建的Dialog窗口（不包括系统应用创建的上述类型窗口）。
> - 当EmbeddedComponent（或UIExtensionComponent）组件被用来显示敏感操作提示内容时，可以选择隐藏不安全窗口，保护敏感操作提示内容不会被遮挡。当EmbeddedComponent（或UIExtensionComponent）组件不显示或销毁时，不安全窗口会重新显示。
> - 针对PC/2in1设备，当调用hideNonSecureWindows(true)时，不安全窗口中的全局悬浮窗不会被隐藏。

**需要权限**：ohos.permission.ALLOW_SHOW_NON_SECURE_WINDOWS

**系统能力**：SystemCapability.ArkUI.ArkUI.Full

**系统接口**：此接口为系统接口。

**参数：**

| 参数名      | 类型                      | 必填 | 说明       |
| ----------- | ------------------------- | ---- | ---------- |
| shouldHide  | boolean                   | 是   | 指示是否隐藏不安全窗口，true表示隐藏，false表示不隐藏。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：** 

| 错误码ID | 错误信息                          |
| -------- | --------------------------------- |
| 202      | Permission verification failed. A non-system application calls a system API. |
| 401      | Parameter error. Possible causes: <br> 1. Mandatory parameters are left unspecified. <br> 2. Incorrect parameters types. <br> 3. Parameter verification failed. |
| 1300002  | Abnormal state. Possible causes: <br> 1. Permission denied. Interface caller does not have permission "ohos.permission.ALLOW_SHOW_NON_SECURE_WINDOWS". <br> 2. The UIExtension window proxy is abnormal. |
| 1300003  | This window manager service works abnormally. |

**示例**

```ts
// ExtensionProvider.ts

import { UIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIExtensionAbility {
  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    const extensionHostWindow = session.getUIExtensionHostWindowProxy();
    // 隐藏非安全窗口
    extensionHostWindow.hideNonSecureWindows(true).then(()=> {
      console.info(`Succeeded in hiding the non-secure windows.`);
    }).catch((err: BusinessError)=> {
      console.error(`Failed to hide the non-secure windows. Cause:${JSON.stringify(err)}`);
    })
  }
  onSessionDestroy(session: UIExtensionContentSession) {
    const extensionHostWindow = session.getUIExtensionHostWindowProxy();
    // 取消隐藏非安全窗口
    extensionHostWindow.hideNonSecureWindows(false).then(()=> {
      console.info(`Succeeded in showing the non-secure windows.`);
    }).catch((err: BusinessError)=> {
      console.error(`Failed to show the non-secure windows. Cause:${JSON.stringify(err)}`);
    })
  }
}
```

### setWaterMarkFlag

setWaterMarkFlag(enable: boolean): Promise&lt;void&gt;

为当前窗口添加或删除安全水印标志，使用Promise异步回调。
> **说明：**
>
> 添加安全水印标志后，窗口在前台时会将当前全屏幕覆盖水印。全屏、悬浮窗、分屏等场景下只要有添加了安全水印标志的窗口在前台，就会显示全屏水印。

**系统能力**：SystemCapability.ArkUI.ArkUI.Full

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型     | 必填 | 说明                                            |
| ------ | ------- | --- | ------------------------------------------------ |
| enable | boolean | 是   | 是否对窗口添加标志位。true表示添加，false表示删除。 |

**返回值：** 

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | ---------------------------------------------- |
| 1300002 | The UIExtension window proxy is abnormal.                 |
| 1300003 | This window manager service works abnormally.  |
| 1300008 | The display device is abnormal. |

**示例** 

```ts
// ExtensionProvider.ts
import { UIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIExtensionAbility {
  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    const extensionHostWindow = session.getUIExtensionHostWindowProxy();
    // 添加安全水印标志
    extensionHostWindow.setWaterMarkFlag(true).then(() => {
      console.info(`Succeeded in setting water mark flag of window.`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to setting water mark flag of window. Cause:${JSON.stringify(err)}`);
    })
  }
  onSessionDestroy(session: UIExtensionContentSession) {
    const extensionHostWindow = session.getUIExtensionHostWindowProxy();
    // 删除安全水印标志
    extensionHostWindow.setWaterMarkFlag(false).then(() => {
      console.info(`Succeeded in deleting water mark flag of window.`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to deleting water mark flag of window. Cause:${JSON.stringify(err)}`);
    })
  }
}
```
