# @ohos.uiExtensionHost (系统接口)
<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @Pakoo007-->
<!--Designer: @stupidb-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->

仅用于在有进程隔离诉求的UIExtensionComponent组件中为提供方应用提供宿主应用的窗口信息和组件本身的信息。

> **说明**
>
> - 后续此接口不再新增功能，相关功能在接口[uiExtension](js-apis-arkui-uiExtension.md)中提供。
>
> - 从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口为系统接口。

## 导入模块

```ts
import { uiExtensionHost } from '@kit.ArkUI';
```

## UIExtensionHostWindowProxy

### 属性

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| properties          | [UIExtensionHostWindowProxyProperties](#uiextensionhostwindowproxyproperties) |  否  |  否  | UIExtensionComponent组件以及宿主窗口的信息。<br/>**约束：** 由于架构约束，不建议在[onSessionCreate](../apis-ability-kit/js-apis-app-ability-uiExtensionAbility.md#onsessioncreate)阶段同步获取该值，建议在收到[on('windowSizeChange')](../apis-arkui/js-apis-uiExtensionHost-sys.md#onwindowsizechange)回调之后获取。 |

### getWindowAvoidArea

getWindowAvoidArea(type: window.AvoidAreaType): window.AvoidArea

获取宿主应用窗口内容避让的区域；如系统栏区域、刘海屏区域、手势区域、软键盘区域等与宿主窗口内容重叠时，需要宿主窗口内容避让的区域。

**系统能力**：SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | [window.AvoidAreaType](arkts-apis-window-e.md#avoidareatype7) | 是 | 表示避让区类型。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [window.AvoidArea](arkts-apis-window-i.md#avoidarea7) | 宿主窗口内容避让区域。 |

**错误码：**

| 错误码ID | 错误信息         |
| -------- | ---------------- |
| 401      | Parameter error. |

**示例：**

```ts
// ExtensionProvider.ets

import { UIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIExtensionAbility {
  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    const extensionHostWindow = session.getUIExtensionHostWindowProxy();
    // 获取宿主应用窗口的避让信息
    const avoidArea = extensionHostWindow.getWindowAvoidArea(window.AvoidAreaType.TYPE_SYSTEM);
    console.info(`avoidArea: ${JSON.stringify(avoidArea)}`);
  }
}
```

### on('avoidAreaChange')

on(type: 'avoidAreaChange', callback: Callback<{ type: window.AvoidAreaType, area: window.AvoidArea }>): void

注册宿主应用窗口避让区变化的监听。

**系统能力**：SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型   | 必填 | 说明                   |
| -------- | ------ | ---- | ---------------------- |
| type     | string | 是   | 监听的事件类型，固定为'avoidAreaChange'，即系统避让区变化事件。 |
| callback | [Callback](../apis-basic-services-kit/js-apis-base.md#callback)<{ type: [window.AvoidAreaType](arkts-apis-window-e.md#avoidareatype7), area: [window.AvoidArea](arkts-apis-window-i.md#avoidarea7) }> | 是 | 回调函数：入参用于接收当前避让区的信息，其中，"type"表示窗口避让区类型，"area"表示窗口内容避让区域。 |

**错误码：** 

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: <br/> 1. Mandatory parameters are left unspecified.<br/> 2. Incorrect parameters types.<br/> 3. Parameter verification failed. |
| 1300002  | Abnormal state. Possible causes: <br/> 1. The listening type is not supported. <br/> 2. The listener has been registered. <br/> 3. The UIExtension window proxy is abnormal. |

**示例：**

```ts
// ExtensionProvider.ets
import { UIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';

export default class EntryAbility extends UIExtensionAbility {
  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    const extensionHostWindow = session.getUIExtensionHostWindowProxy();
    // 注册避让区变化的监听
    extensionHostWindow.on('avoidAreaChange', (info) => {
      console.info(`The avoid area of the host window is: ${JSON.stringify(info.area)}.`);
    });
  }
}
```

### off('avoidAreaChange')

off(type: 'avoidAreaChange', callback?: Callback<{ type: window.AvoidAreaType, area: window.AvoidArea }>): void

注销宿主应用窗口避让区变化的监听。

**系统能力**：SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型   | 必填 | 说明                   |
| -------- | ------ | ---- | ---------------------- |
| type     | string | 是   | 注销的事件类型，固定为'avoidAreaChange'，即系统避让区变化事件。 |
| callback | [Callback](../apis-basic-services-kit/js-apis-base.md#callback)<{ type: [window.AvoidAreaType](arkts-apis-window-e.md#avoidareatype7), area: [window.AvoidArea](arkts-apis-window-i.md#avoidarea7) }> | 否 | 回调函数：如果传入该参数，则关闭该监听。如果未传入参数，则关闭所有系统避让区变化的监听。 |

**错误码：** 

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: <br/> 1. Mandatory parameters are left unspecified.<br/> 2. Incorrect parameters types.<br/> 3. Parameter verification failed. |
| 1300002  | Abnormal state. Possible causes: <br/> 1. The listening type is not supported. <br/> 2. The listening type is not registered. <br/> 3. The listener has not been registered. <br/> 4. The UIExtension window proxy is abnormal. |

**示例：**

```ts
// ExtensionProvider.ets
import { UIExtensionAbility, UIExtensionContentSession} from '@kit.AbilityKit';

export default class EntryAbility extends UIExtensionAbility {
  onSessionDestroy(session: UIExtensionContentSession) {
    const extensionHostWindow = session.getUIExtensionHostWindowProxy();
    // 注销所有避让区变化的监听
    extensionHostWindow.off('avoidAreaChange');
  }
}
```

### on('windowSizeChange')

on(type: 'windowSizeChange', callback: Callback<window.Size>): void

注册组件（EmbeddedComponent或UIExtensionComponent）尺寸变化的监听。

**系统能力**：SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型                  | 必填 | 说明                   |
| -------- | --------------------- | ---- | ---------------------- |
| type     | string                | 是   | 监听的事件类型，固定为'windowSizeChange'，即组件（EmbeddedComponent或UIExtensionComponent）尺寸变化事件。 |
| callback | [Callback](../apis-basic-services-kit/js-apis-base.md#callback)<[window.Size](arkts-apis-window-i.md#size7)> | 是   | 回调函数：入参用于接收当前组件（EmbeddedComponent或UIExtensionComponent）的尺寸。 |

**错误码：** 

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: <br/> 1. Mandatory parameters are left unspecified.<br/> 2. Incorrect parameters types.<br/> 3. Parameter verification failed. |
| 1300002  | Abnormal state. Possible causes: <br/> 1. The listening type is not supported. <br/> 2. The listener has been registered. <br/> 3. The UIExtension window proxy is abnormal. |

**示例：**

```ts
// ExtensionProvider.ets
import { UIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';

export default class EntryAbility extends UIExtensionAbility {
  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    const extensionHostWindow = session.getUIExtensionHostWindowProxy();
    // 注册组件（EmbeddedComponent或UIExtensionComponent）大小变化的监听
    extensionHostWindow.on('windowSizeChange', (size) => {
      console.info(`The size of the component is: ${JSON.stringify(size)}.`);
    });
  }
}
```

### off('windowSizeChange')

off(type: 'windowSizeChange', callback?: Callback<window.Size>): void

注销组件（EmbeddedComponent或UIExtensionComponent）尺寸变化的监听。

**系统能力**：SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型                  | 必填 | 说明                   |
| -------- | --------------------- | ---- | ---------------------- |
| type     | string                | 是   | 注销的事件类型，固定值：'windowSizeChange'，即组件（EmbeddedComponent或UIExtensionComponent）尺寸变化事件。 |
| callback | [Callback](../apis-basic-services-kit/js-apis-base.md#callback)<[window.Size](arkts-apis-window-i.md#size7)> | 否   | 回调函数。返回当前的组件（EmbeddedComponent或UIExtensionComponent）尺寸。如果传入该参数，则关闭该监听。如果未传入参数，则关闭组件（EmbeddedComponent或UIExtensionComponent）尺寸变化的监听。 |

**错误码：** 

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: <br/> 1. Mandatory parameters are left unspecified.<br/> 2. Incorrect parameters types.<br/> 3. Parameter verification failed. |
| 1300002  | Abnormal state. Possible causes: <br/> 1. The listening type is not supported. <br/> 2. The listening type is not registered. <br/> 3. The listener has not been registered. <br/> 4. The UIExtension window proxy is abnormal. |

**示例：**

```ts
// ExtensionProvider.ets
import { UIExtensionAbility, UIExtensionContentSession } from '@kit.AbilityKit';

export default class EntryAbility extends UIExtensionAbility {
  onSessionDestroy(session: UIExtensionContentSession) {
    const extensionHostWindow = session.getUIExtensionHostWindowProxy();
    // 注销组件（EmbeddedComponent或UIExtensionComponent）大小变化的监听
    extensionHostWindow.off('windowSizeChange');
  }
}
```

### hideNonSecureWindows

hideNonSecureWindows(shouldHide: boolean): Promise&lt;void&gt;

设置是否隐藏不安全窗口，使用Promise异步回调。
> **说明：**
>
> - 不安全窗口是指可能遮挡[EmbeddedComponent](arkui-ts/ts-container-embedded-component.md)（或[UIExtensionComponent](arkui-ts/ts-container-ui-extension-component-sys.md)）组件的窗口，如全局悬浮窗、宿主子窗口和宿主创建的Dialog窗口（不包括系统应用创建的上述类型窗口）。
> - 当EmbeddedComponent（或UIExtensionComponent）组件用于显示敏感操作提示内容时，可以选择隐藏不安全窗口，保护其不会被遮挡。当EmbeddedComponent（或UIExtensionComponent）组件不显示或销毁时，不安全窗口会重新显示。
> - 针对PC/2in1设备，当调用hideNonSecureWindows(true)时，不安全窗口中的全局悬浮窗不会被隐藏。

**需要权限**：ohos.permission.ALLOW_SHOW_NON_SECURE_WINDOWS

**系统能力**：SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

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

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 202      | Permission verification failed. A non-system application calls a system API.<br>适用版本：12+ |
| 401      | Parameter error. Possible causes: <br> 1. Mandatory parameters are left unspecified. <br> 2. Incorrect parameters types. <br> 3. Parameter verification failed. |
| 1300002  | Abnormal state. Possible causes: <br> 1. Permission denied. Interface caller does not have permission "ohos.permission.ALLOW_SHOW_NON_SECURE_WINDOWS". <br> 2. The UIExtension window proxy is abnormal.<br>适用版本：12+ |
| 1300003  | This window manager service works abnormally.<br>适用版本：12+ |

**示例：**

```ts
// ExtensionProvider.ets

import { UIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIExtensionAbility {
  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    const extensionHostWindow = session.getUIExtensionHostWindowProxy();
    // 隐藏非安全窗口
    extensionHostWindow.hideNonSecureWindows(true).then(() => {
      console.info(`Succeeded in hiding the non-secure windows.`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to hide the non-secure windows. Code: ${err.code}, message: ${err.message}`);
    })
  }
  onSessionDestroy(session: UIExtensionContentSession) {
    const extensionHostWindow = session.getUIExtensionHostWindowProxy();
    // 取消隐藏非安全窗口
    extensionHostWindow.hideNonSecureWindows(false).then(() => {
      console.info(`Succeeded in showing the non-secure windows.`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to show the non-secure windows. Code: ${err.code}, message: ${err.message}`);
    })
  }
}
```

### createSubWindowWithOptions<sup>12+</sup>

createSubWindowWithOptions(name: string, subWindowOptions: window.SubWindowOptions): Promise&lt;window.Window&gt;

创建该UIExtensionHostWindowProxy实例下的子窗口，使用Promise异步回调。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**设备行为差异：** 当[subWindowOptions](arkts-apis-window-i.md#subwindowoptions11)中isModal为true且[modalityType](arkts-apis-window-e.md#modalitytype14)为APPLICATION_MODALITY时，该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备及不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用返回801错误码。

**参数：**

| 参数名 | 类型   | 必填 | 说明           |
| ------ | ------ | ---- | -------------- |
| name   | string | 是   | 子窗口的名字。 |
| subWindowOptions | [window.SubWindowOptions](arkts-apis-window-i.md#subwindowoptions11) | 是 | 子窗口参数。 |

**返回值：**

| 类型                             | 说明                                             |
| -------------------------------- | ------------------------------------------------ |
| Promise&lt;[window.Window](arkts-apis-window-Window.md)&gt; | Promise对象。返回当前UIExtensionHostWindowProxy下创建的子窗口对象。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 401 | Parameter error. Possible causes: <br/> 1. Mandatory parameters are left unspecified.<br/> 2. Incorrect parameters types.<br/> 3. Parameter verification failed. |
| 801 | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. Possible causes: 1. The window is not created or destroyed. 2. Internal task error. 3. The subWindow has been created and can not be created again. 4. It is not allowed to create non-secure window when secure extension exists. |
| 1300035 | Creating a subwindow is not allowed in the current context. Possible cause: 1. An AgentUIExtensionAbility cannot create a subwindow. |

**示例：**

```ts
// ExtensionProvider.ets
import { UIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIExtensionAbility {
  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    const extensionHostWindow = session.getUIExtensionHostWindowProxy();
    const subWindowOpts: window.SubWindowOptions = {
      title: 'This is a subwindow',
      decorEnabled: true
    };
    // 创建子窗口
    extensionHostWindow.createSubWindowWithOptions('subWindowForHost', subWindowOpts)
      .then((subWindow: window.Window) => {
        subWindow.setUIContent('pages/Index', (err, data) =>{
          if (err && err.code) {
            return;
          }
          subWindow?.resize(300, 300, (err, data) =>{
            if (err && err.code) {
              return;
            }
            subWindow?.moveWindowTo(100, 100, (err, data) =>{
              if (err && err.code) {
                return;
              }
              subWindow?.showWindow((err, data) => {
                if (err && err.code) {
                  console.error(`Failed to show the subwindow. Code: ${err.code}, message: ${err.message}`);
                } else {
                  console.info(`The subwindow has been shown!`);
                }
              });
            });
          });
        });
      }).catch((error: BusinessError) => {
        console.error(`Create subwindow failed. Code: ${error.code}, message: ${error.message}`);
      })
  }
}
```

### createSubWindowWithOptions<sup>22+</sup>

createSubWindowWithOptions(name: string, subWindowConfig: window.SubWindowOptions, followCreatorLifecycle: boolean): Promise&lt;window.Window&gt;

创建该UIExtensionHostWindowProxy实例下的子窗口，可通过设置followCreatorLifecycle，决定子窗是否跟随组件（EmbeddedComponent或UIExtensionComponent）的生命周期，使用Promise异步回调。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**设备行为差异：** 当[subWindowOptions](arkts-apis-window-i.md#subwindowoptions11)中isModal为true且[modalityType](arkts-apis-window-e.md#modalitytype14)为APPLICATION_MODALITY时，该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备及不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用返回801错误码。

**参数：**

| 参数名 | 类型   | 必填 | 说明           |
| ------ | ------ | ---- | -------------- |
| name   | string | 是   | 子窗口的名字。 |
| subWindowConfig | [window.SubWindowOptions](arkts-apis-window-i.md#subwindowoptions11) | 是 | 子窗口参数。 |
| followCreatorLifecycle | boolean | 是   | 子窗生命周期是否跟组件（EmbeddedComponent或UIExtensionComponent）保持同步。true表示该组件隐藏时，子窗隐藏，该组件显示时子窗显示，false表示子窗的显隐不跟随该组件变化。|

**返回值：**

| 类型                             | 说明                                             |
| -------------------------------- | ------------------------------------------------ |
| Promise&lt;[window.Window](arkts-apis-window-Window.md)&gt; | Promise对象。返回当前UIExtensionHostWindowProxy下创建的子窗口对象。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 801 | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed. 2. Internal task error. 3. The subWindow has been created and can not be created again. 4. It is not allowed to create non-secure window when secure extension exists. |
| 1300035 | Creating a subwindow is not allowed in the current context. Possible cause: 1. An AgentUIExtensionAbility cannot create a subwindow. |

**示例：**

```ts
// ExtensionProvider.ets
import { UIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIExtensionAbility {
  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    const extensionHostWindow = session.getUIExtensionHostWindowProxy();
    const subWindowConfig: window.SubWindowOptions = {
      title: 'This is a subwindow',
      decorEnabled: true
    };
    // 创建子窗口
    extensionHostWindow.createSubWindowWithOptions('subWindowForHost', subWindowConfig, true)
      .then((subWindow: window.Window) => {
        subWindow.setUIContent('pages/Index', (err, data) =>{
          if (err && err.code) {
            return;
          }
          subWindow?.resize(300, 300, (err, data) =>{
            if (err && err.code) {
              return;
            }
            subWindow?.moveWindowTo(100, 100, (err, data) =>{
              if (err && err.code) {
                return;
              }
              subWindow?.showWindow((err, data) => {
                if (err && err.code) {
                  console.error(`Failed to show the subwindow. Code: ${err.code}, message: ${err.message}`);
                } else {
                  console.info(`The subwindow has been shown!`);
                }
              });
            });
          });
        });
      }).catch((error: BusinessError) => {
        console.error(`Create subwindow failed. Code: ${error.code}, message: ${error.message}`);
      })
  }
}
```

### setWaterMarkFlag<sup>12+</sup>

setWaterMarkFlag(enable: boolean): Promise&lt;void&gt;

为当前窗口添加或删除安全水印标志，使用Promise异步回调。
> **说明：**
>
> 添加安全水印标志后，窗口在前台时会将当前全屏幕覆盖水印。全屏、悬浮窗、分屏等场景下只要有添加了安全水印标志的窗口在前台，就会显示全屏水印。

**系统能力**：SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

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
| 1300002 | The UIExtension window proxy is abnormal.      |
| 1300003 | This window manager service works abnormally.  |
| 1300008 | The display device is abnormal. |

**示例：**

```ts
// ExtensionProvider.ets
import { UIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIExtensionAbility {
  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    const extensionHostWindow = session.getUIExtensionHostWindowProxy();
    // 添加安全水印标志
    extensionHostWindow.setWaterMarkFlag(true).then(() => {
      console.info(`Succeeded in setting water mark flag of window.`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to set water mark flag of window. Code: ${err.code}, message: ${err.message}`);
    })
  }
  onSessionDestroy(session: UIExtensionContentSession) {
    const extensionHostWindow = session.getUIExtensionHostWindowProxy();
    // 删除安全水印标志
    extensionHostWindow.setWaterMarkFlag(false).then(() => {
      console.info(`Succeeded in deleting water mark flag of window.`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to delete water mark flag of window. Code: ${err.code}, message: ${err.message}`);
    })
  }
}
```
### hidePrivacyContentForHost<sup>13+</sup>

hidePrivacyContentForHost(shouldHide: boolean): Promise&lt;void&gt;

设置UIExtension组件在非系统截图时的隐私内容保护开关，使用Promise异步回调。

> **说明：**
>
> 开启截图隐私内容保护后，使用窗口截图[window.snapshot](arkts-apis-window-Window.md#snapshot9)或者组件截图[UIContext.getComponentSnapshot](arkts-apis-uicontext-uicontext.md#getcomponentsnapshot12)
将无法截取到当前组件的内容（不包括该组件下创建的子窗）。

**系统能力**：SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型     | 必填 | 说明                                            |
| ------ | ------- | --- | ------------------------------------------------ |
| shouldHide | boolean | 是   | 是否开启截图隐私保护。true表示开启，false表示不开启。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 202      | Permission verification failed. A non-system application calls a system API. |
| 401      | Parameter error. Possible causes: <br> 1. Mandatory parameters are left unspecified. <br> 2. Incorrect parameters types. <br> 3. Parameter verification failed. |
| 1300002  | Abnormal state. Possible causes: <br> 1. The UIExtension window proxy is abnormal. <br> 2. Not the UIExtensionAbility process calling.                    |

**示例：**

```ts
// ExtensionProvider.ets
import { UIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIExtensionAbility {
  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    const extensionHostWindow = session.getUIExtensionHostWindowProxy();
    // 开启截图隐私内容保护
    extensionHostWindow.hidePrivacyContentForHost(true).then(() => {
      console.info(`Succeeded in enabling privacy protection for non-system screenshots.`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to enable privacy protection for non-system screenshots.  Code: ${err.code}, message: ${err.message}`);
    })
  }
}
```

## UIExtensionHostWindowProxyProperties

用于表示宿主应用窗口和UIExtensionComponent组件的信息。

**系统能力**：SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

| 名称                         | 类型        | 只读  | 可选    | 说明                             |
| ------------------------------ | ----------- | --------------- | ----------------- | -------------------------------- |
| uiExtensionHostWindowProxyRect | [window.Rect](arkts-apis-window-i.md#rect7) | 是 | 否 |UIExtensionComponent的位置和宽高。 |

## 完整示例

本示例展示文档中所有API在UIExtensionAbility中的基础使用方式，示例应用需采用系统签名，且`bundleName`为"com.example.uiextensiondemo", 被拉起的`UIExtensionAbility`为"ExampleUIExtensionAbility"。

- 示例应用中的EntryAbility(UIAbility)加载首页文件：`pages/Index.ets`，其中内容如下：

  ```ts
  // pages/Index.ets -- UIAbility启动时加载此页面
  import { Want } from '@kit.AbilityKit';

  @Entry
  @Component
  struct Index {
    @State message: string = 'Message: ';
    private want: Want = {
      bundleName: 'com.example.uiextensiondemo',
      abilityName: 'ExampleUIExtensionAbility',
      parameters: {
        'ability.want.params.uiExtensionType': 'sys/commonUI'
      }
    }

    build() {
      Row() {
        Column() {
          Text(this.message).fontSize(30)
          UIExtensionComponent(this.want)
            .width('100%')
            .height('90%')
        }
        .width('100%')
      }
      .height('100%')
    }
  }
  ```

- UIExtensionComponent拉起的UIExtensionAbility在`ets/extensionAbility/ExampleUIExtensionAbility`文件中实现，内容如下：

  ```ts
  import { UIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';

  const TAG: string = '[ExampleUIExtensionAbility]';
  export default class ExampleUIExtensionAbility extends UIExtensionAbility {
    onCreate() {
      console.info(TAG, `onCreate`);
    }

    onForeground() {
      console.info(TAG, `onForeground`);
    }

    onBackground() {
      console.info(TAG, `onBackground`);
    }

    onDestroy() {
      console.info(TAG, `onDestroy`);
    }

    onSessionCreate(want: Want, session: UIExtensionContentSession) {
      console.info(TAG, `onSessionCreate, want: ${JSON.stringify(want)}`);
      let param: Record<string, UIExtensionContentSession> = {
        'session': session
      };
      let storage: LocalStorage = new LocalStorage(param);
      session.loadContent('pages/extension', storage);
    }
  }
  ```

- UIExtensionAbility的入口页面文件`pages/extension.ets`内容如下：

  ```ts
  import { UIExtensionContentSession } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  import { uiExtensionHost, window } from '@kit.ArkUI';

  @Entry()
  @Component
  struct Extension {
    @State message: string = 'UIExtensionAbility Index';
    private storage: LocalStorage | undefined = this.getUIContext()?.getSharedLocalStorage();
    private session: UIExtensionContentSession | undefined = this.storage?.get<UIExtensionContentSession>('session');
    private extensionHostWindow: uiExtensionHost.UIExtensionHostWindowProxy | undefined = this.session?.getUIExtensionHostWindowProxy();
    private subWindow: window.Window | undefined = undefined;

    aboutToAppear(): void {
      this.extensionHostWindow?.on('windowSizeChange', (size) => {
          console.info(`size = ${JSON.stringify(size)}`);
      });
      this.extensionHostWindow?.on('avoidAreaChange', (info) => {
          console.info(`type = ${JSON.stringify(info.type)}, area = ${JSON.stringify(info.area)}`);
      });
      let promise = this.extensionHostWindow?.hideNonSecureWindows(true);
      promise?.then(() => {
        console.info(`Succeeded in hiding the non-secure windows.`);
      }).catch((err: BusinessError) => {
        console.error(`Failed to hide the non-secure windows. Code: ${err.code}, message: ${err.message}`);
      })
      this.extensionHostWindow?.hidePrivacyContentForHost(true)?.then(() => {
        console.info(`Succeeded in enabling privacy protection for non-system screenshots.`);
      }).catch((err: BusinessError) => {
        console.error(`Failed to enable privacy protection for non-system screenshots.  Code: ${err.code}, message: ${err.message}`);
      })
    }

    aboutToDisappear(): void {
      this.extensionHostWindow?.off('windowSizeChange');
      this.extensionHostWindow?.off('avoidAreaChange');
      let promise = this.extensionHostWindow?.hideNonSecureWindows(false);
      promise?.then(() => {
        console.info(`Succeeded in showing the non-secure windows.`);
      }).catch((err: BusinessError) => {
        console.error(`Failed to show the non-secure windows. Code: ${err.code}, message: ${err.message}`);
      })
    }

    build() {
      Column() {
        Text(this.message)
          .fontSize(20)
          .fontWeight(FontWeight.Bold)
        Button("获取组件大小").width('90%').margin({top: 5, bottom: 5}).fontSize(16).onClick(() => {
          let rect = this.extensionHostWindow?.properties.uiExtensionHostWindowProxyRect;
          console.info(`UIExtensionComponent的宽高和位置信息: ${JSON.stringify(rect)}`);
        })
        Button("获取系统避让区信息").width('90%').margin({top: 5, bottom: 5}).fontSize(16).onClick(() => {
          let avoidArea: window.AvoidArea | undefined = this.extensionHostWindow?.getWindowAvoidArea(window.AvoidAreaType.TYPE_SYSTEM);
          console.info(`系统避让区: ${JSON.stringify(avoidArea)}`);
        })
        Button("创建子窗口").width('90%').margin({top: 5, bottom: 5}).fontSize(16).onClick(() => {
          let subWindowOpts: window.SubWindowOptions = {
            'title': 'This is a subwindow',
            decorEnabled: true
          };
          this.extensionHostWindow?.createSubWindowWithOptions('subWindowForHost', subWindowOpts)
            .then((subWindow: window.Window) => {
              this.subWindow = subWindow;
              this.subWindow.loadContent('pages/Index', this.storage, (err, data) =>{
                if (err && err.code) {
                  return;
                }
                this.subWindow?.resize(300, 300, (err, data) =>{
                  if (err && err.code) {
                    return;
                  }
                  this.subWindow?.moveWindowTo(100, 100, (err, data) =>{
                    if (err && err.code) {
                      return;
                    }
                    this.subWindow?.showWindow((err, data) => {
                      if (err && err.code) {
                        console.error(`Failed to show the subwindow. Code: ${err.code}, message: ${err.message}`);
                      } else {
                        console.info(`The subwindow has been shown!`);
                      }
                    });
                  });
                });
              });
            }).catch((error: BusinessError) => {
              console.error(`Create subwindow failed. Code: ${error.code}, message: ${error.message}`);
            })
        })
      }.width('100%').height('100%')
    }
  }
  ```

- 最后，示例应用的`module.json5`中的"extensionAbilities"中需要增加一项，具体内容如下：
  ```json
  {
    "name": "ExampleUIExtensionAbility",
    "srcEntry": "./ets/extensionAbility/ExampleUIExtensionAbility.ets",
    "type": "sys/commonUI"
  }
  ```
