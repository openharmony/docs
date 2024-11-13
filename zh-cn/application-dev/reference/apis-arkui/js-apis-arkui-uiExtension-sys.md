# @ohos.arkui.uiExtension (uiExtension)(系统接口)

用于EmbeddedUIExtensionAbility（或UIExtensionAbility）中获取宿主应用的窗口信息或对应的EmbeddedComponent（或UIExtensionComponent）组件的信息。

> **说明**
>
> 从API Version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> 本文仅介绍当前模块的系统接口，其他公开接口参见[@ohos.arkui.uiExtension (uiExtension)](js-apis-arkui-uiExtension.md)

## 导入模块

```
import { uiExtension } from '@kit.ArkUI'
```

## WindowProxy

### hideNonSecureWindows

hideNonSecureWindows(shouldHide: boolean): Promise\<void>

设置是否隐藏不安全窗口。

> **说明：**
>
> 不安全窗口是指可能遮挡EmbeddedComponent（或UIExtensionComponent）组件的窗口，如全局悬浮窗、宿主子窗口和宿主创建的Dialog窗口（不包括系统应用创建的上述类型窗口）。当EmbeddedComponent（或UIExtensionComponent）组件被用来显示敏感操作提示内容时，可以选择隐藏不安全窗口，保护敏感操作提示内容不会被遮挡。当EmbeddedComponent（或UIExtensionComponent）组件不显示或销毁时需要让不安全窗口重新显示。使用CreateModalUIExtension接口创建的UIExtensionComponent会默认隐藏不安全窗口，若要取消隐藏，需要申请ohos.permission.ALLOW_SHOW_NON_SECURE_WINDOWS权限，并调用本接口将shouldHide设为false。

**系统能力**：SystemCapability.ArkUI.ArkUI.Full

**系统接口**：此接口为系统接口，三方应用不支持调用。

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
      console.log(`Succeeded in hiding the non-secure windows.`);
    }).catch((err: BusinessError)=> {
      console.log(`Failed to hide the non-secure windows. Cause:${JSON.stringify(err)}`);
    })
  }
  onSessionDestroy(session: UIExtensionContentSession) {
    const extensionHostWindow = session.getUIExtensionHostWindowProxy();
    // 取消隐藏非安全窗口
    extensionHostWindow.hideNonSecureWindows(false).then(()=> {
      console.log(`Succeeded in showing the non-secure windows.`);
    }).catch((err: BusinessError)=> {
      console.log(`Failed to show the non-secure windows. Cause:${JSON.stringify(err)}`);
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

**系统接口**：此接口为系统接口，三方应用不支持调用。

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
| 1300002 | This window state is abnormal.                 |
| 1300003 | This window manager service works abnormally.  |
| 1300008 | The operation is on invalid display. |

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
      console.log(`Succeeded in setting water mark flag of window.`);
    }).catch((err: BusinessError) => {
      console.log(`Failed to setting water mark flag of window. Cause:${JSON.stringify(err)}`);
    })
  }
  onSessionDestroy(session: UIExtensionContentSession) {
    const extensionHostWindow = session.getUIExtensionHostWindowProxy();
    // 删除安全水印标志
    extensionHostWindow.setWaterMarkFlag(false).then(() => {
      console.log(`Succeeded in deleting water mark flag of window.`);
    }).catch((err: BusinessError) => {
      console.log(`Failed to deleting water mark flag of window. Cause:${JSON.stringify(err)}`);
    })
  }
}
```
