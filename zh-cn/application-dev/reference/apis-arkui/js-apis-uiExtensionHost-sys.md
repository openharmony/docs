# @ohos.uiExtensionHost (系统接口)

仅用于在有进程隔离诉求的UIExtensionComponent组件中为提供方应用提供宿主应用的窗口信息和组件本身的信息。

> **说明**
>
> 后续此接口不再新增功能，相关功能在接口[uiExtension](js-apis-arkui-uiExtension.md)中提供。
>
> 从API Version 11开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> 本模块接口为系统接口。

## 导入模块

```
import { uiExtensionHost } from '@kit.ArkUI';
```

## UIExtensionHostWindowProxy

### getWindowAvoidArea

getWindowAvoidArea(type: window.AvoidAreaType): window.AvoidArea

获取宿主应用窗口内容规避的区域；如系统栏区域、刘海屏区域、手势区域、软键盘区域等与宿主窗口内容重叠时，需要宿主窗口内容避让的区域。

**系统能力**：SystemCapability.ArkUI.ArkUI.Full

**系统接口**：此接口为系统接口，三方应用不支持调用。

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | [window.AvoidAreaType](arkts-apis-window-e.md#avoidareatype7) | 是 | 表示规避区类型。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [window.AvoidArea](arkts-apis-window-i.md#avoidarea7) | 宿主窗口内容规避区域。 |

**错误码：**

| 错误码ID | 错误信息         |
| -------- | ---------------- |
| 401      | Parameter error. |

**示例：**

```ts
// ExtensionProvider.ts

import { UIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIExtensionAbility {
  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    const extensionHostWindow = session.getUIExtensionHostWindowProxy();
    // 获取宿主应用窗口的避让信息
    const avoidArea = extensionHostWindow.getWindowAvoidArea(window.AvoidAreaType.TYPE_SYSTEM);
    console.log(`avoidArea: ${JSON.stringify(avoidArea)}`);
  }
}
```

### on('avoidAreaChange')

on(type: 'avoidAreaChange', callback: Callback<{ type: window.AvoidAreaType, area: window.AvoidArea }>): void

注册系统规避区变化的监听。

**系统能力**：SystemCapability.ArkUI.ArkUI.Full

**系统接口**：此接口为系统接口，三方应用不支持调用。

| 参数名   | 类型   | 必填 | 说明                   |
| -------- | ------ | ---- | ---------------------- |
| type     | string | 是   | 监听的事件类型，固定为'avoidAreaChange'，即系统规避区变化事件。 |
| callback | [Callback](../apis-basic-services-kit/js-apis-base.md#callback)<{ type: [window.AvoidAreaType](arkts-apis-window-e.md#avoidareatype7), area: [window.AvoidArea](arkts-apis-window-i.md#avoidarea7) }> | 是 | 回调函数：入参用于接收当前规避区的信息，其中，"type"表示窗口规避区类型，"area"表示窗口内容规避区域。 |

**错误码：** 

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: <br/> 1. Mandatory parameters are left unspecified.<br/> 2. Incorrect parameters types.<br/> 3. Parameter verification failed. |

**示例：**

```ts
// ExtensionProvider.ts
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

注销系统规避区变化的监听。

**系统能力**：SystemCapability.ArkUI.ArkUI.Full

**系统接口**：此接口为系统接口，三方应用不支持调用。

| 参数名   | 类型   | 必填 | 说明                   |
| -------- | ------ | ---- | ---------------------- |
| type     | string | 是   | 注销的事件类型，固定为'avoidAreaChange'，即系统规避区变化事件。 |
| callback | [Callback](../apis-basic-services-kit/js-apis-base.md#callback)<{ type: [window.AvoidAreaType](arkts-apis-window-e.md#avoidareatype7), area: [window.AvoidArea](arkts-apis-window-i.md#avoidarea7) }> | 否 | 回调函数：如果传入该参数，则关闭该监听。如果未传入参数，则关闭所有系统规避区变化的监听。 |

**错误码：** 

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: <br/> 1. Mandatory parameters are left unspecified.<br/> 2. Incorrect parameters types.<br/> 3. Parameter verification failed. |

**示例：**

```ts
// ExtensionProvider.ts
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

注册宿主应用窗口尺寸变化的监听。

**系统能力**：SystemCapability.ArkUI.ArkUI.Full

**系统接口**：此接口为系统接口，三方应用不支持调用。

| 参数名   | 类型                  | 必填 | 说明                   |
| -------- | --------------------- | ---- | ---------------------- |
| type     | string                | 是   | 监听的事件类型，固定为'windowSizeChange'，即窗口尺寸变化事件。 |
| callback | [Callback](../apis-basic-services-kit/js-apis-base.md#callback)<[window.Size](arkts-apis-window-i.md#size7)> | 是   | 回调函数：入参用于接收当前窗口的尺寸。 |

**错误码：** 

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: <br/> 1. Mandatory parameters are left unspecified.<br/> 2. Incorrect parameters types.<br/> 3. Parameter verification failed. |

**示例：**

```ts
// ExtensionProvider.ts
import { UIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';

export default class EntryAbility extends UIExtensionAbility {
  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    const extensionHostWindow = session.getUIExtensionHostWindowProxy();
    // 注册宿主应用窗口大小变化的监听
    extensionHostWindow.on('windowSizeChange', (size) => {
      console.info(`The avoid area of the host window is: ${JSON.stringify(size)}.`);
    });
  }
}
```

### off('windowSizeChange')

off(type: 'windowSizeChange', callback?: Callback<window.Size>): void

注销宿主应用窗口尺寸变化的监听。

**系统能力**：SystemCapability.ArkUI.ArkUI.Full

**系统接口**：此接口为系统接口，三方应用不支持调用。

| 参数名   | 类型                  | 必填 | 说明                   |
| -------- | --------------------- | ---- | ---------------------- |
| type     | string                | 是   | 注销的事件类型，固定值：'windowSizeChange'，即窗口尺寸变化事件。 |
| callback | [Callback](../apis-basic-services-kit/js-apis-base.md#callback)<[window.Size](arkts-apis-window-i.md#size7)> | 否   | 回调函数：如果传入该参数，则关闭该监听。如果未传入参数，则关闭所有系统规避区变化的监听。 |

**错误码：** 

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: <br/> 1. Mandatory parameters are left unspecified.<br/> 2. Incorrect parameters types.<br/> 3. Parameter verification failed. |

**示例：**

```ts
// ExtensionProvider.ts
import { UIExtensionAbility, UIExtensionContentSession } from '@kit.AbilityKit';

export default class EntryAbility extends UIExtensionAbility {
  onSessionDestroy(session: UIExtensionContentSession) {
    const extensionHostWindow = session.getUIExtensionHostWindowProxy();
    // 注销宿主应用窗口大小变化的监听
    extensionHostWindow.off('windowSizeChange');
  }
}
```

### properties

properties: UIExtensionHostWindowProxyProperties

宿主应用窗口和UIExtensionComponent组件的信息。

**系统能力**：SystemCapability.ArkUI.ArkUI.Full

**系统接口**：此接口为系统接口，三方应用不支持调用。

| 参数名     | 类型                                 | 说明                             |
| ---------- | ------------------------------------ | -------------------------------- |
| properties | [UIExtensionHostWindowProxyProperties](#uiextensionhostwindowproxyproperties) | UIExtensionComponent组件以及宿主窗口的信息。 |

**示例：**

```ts
// ExtensionProvider.ts
import { UIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';

export default class EntryAbility extends UIExtensionAbility {
  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    const extensionHostWindow = session.getUIExtensionHostWindowProxy();
    // 获取UIExtensionComponent位置和大小信息
    const rect = extensionHostWindow.properties.uiExtensionHostWindowProxyRect;
    console.log(`Rect Info: ${JSON.stringify(rect)}`);
  }
}
```

### hideNonSecureWindows

hideNonSecureWindows(shouldHide: boolean): Promise&lt;void&gt;

设置是否隐藏不安全窗口。
> **说明：**
>
> 不安全窗口是指可能遮挡UIExtensionComponent的窗口类型，如全局悬浮窗、宿主子窗口和宿主创建的Dialog窗口（不包括系统应用创建的上述类型窗口）。当UIExtensionComponent组件被用来显示敏感操作提示内容时，可以选择隐藏不安全窗口，保护敏感操作提示内容不会被遮挡。当UIExtensionComponent不显示或销毁时需要让不安全窗口重新显示。使用CreateModalUIExtension接口创建的UIExtensionComponent会默认隐藏不安全窗口，若要取消隐藏，需要申请ohos.permission.ALLOW_SHOW_NON_SECURE_WINDOWS权限，并调用本接口将shouldHide设为false。

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

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 202      | Permission verification failed. A non-system application calls a system API. |
| 401      | Parameter error. Possible causes: <br> 1. Mandatory parameters are left unspecified. <br> 2. Incorrect parameters types. <br> 3. Parameter verification failed. |
| 1300002  | Abnormal state. Possible causes: <br> 1. Permission denied. Interface caller does not have permission "ohos.permission.ALLOW_SHOW_NON_SECURE_WINDOWS". <br> 2. The UIExtension window proxy is abnormal. |
| 1300003  | This window manager service works abnormally. |

**示例：**

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

### createSubWindowWithOptions<sup>12+</sup>

createSubWindowWithOptions(name: string, subWindowOptions: window.SubWindowOptions): Promise&lt;window.Window&gt;

创建该UIExtensionHostWindowProxy实例下的子窗口，使用Promise异步回调。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**系统接口：** 此接口为系统接口，三方应用不支持调用。

**模型约束：** StageModelOnly

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
| 801 | Capability not supported on this device. |
| 1300002 | This window state is abnormal. |

**示例：**

```ts
// ExtensionProvider.ts
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
          if (err && err.code != 0) {
            return;
          }
          subWindow?.resize(300, 300, (err, data)=>{
            if (err && err.code != 0) {
              return;
            }
            subWindow?.moveWindowTo(100, 100, (err, data)=>{
              if (err && err.code != 0) {
                return;
              }
              subWindow?.showWindow((err, data) => {
                if (err && err.code == 0) {
                  console.info(`The subwindow has been shown!`);
                } else {
                  console.error(`Failed to show the subwindow!`);
                }
              });
            });
          });
        });
      }).catch((error: BusinessError) => {
        console.error(`Create subwindow failed: ${JSON.stringify(error)}`);
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

**示例：**

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
### hidePrivacyContentForHost<sup>13+</sup>

hidePrivacyContentForHost(shouldHide: boolean): Promise&lt;void&gt;

设置UIExtension组件在非系统截图时的隐私内容保护开关，使用Promise异步回调。
> **说明：**
>
> 开启截图隐私内容保护后，使用窗口截图[window.snapshot](arkts-apis-window-Window.md#snapshot9)或者组件截图[UIContext.getComponentSnapshot](arkts-apis-uicontext-uicontext.md#getcomponentsnapshot12)
将无法截取到当前组件的内容（不包括该组件下创建的子窗）。

**系统能力**：SystemCapability.ArkUI.ArkUI.Full

**系统接口**：此接口为系统接口，三方应用不支持调用。

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
| 1300002  | The UIExtension window proxy is abnormal.                    |

**示例：**

```ts
// ExtensionProvider.ts
import { UIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIExtensionAbility {
  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    const extensionHostWindow = session.getUIExtensionHostWindowProxy();
    // 开启截图隐私内容保护
    extensionHostWindow.hidePrivacyContentForHost(true).then(() => {
      console.info(`Successfully enabled privacy protection for non-system screenshots.`);
    }).catch((err: BusinessError) => {
      console.error(`Failed enabled privacy protection for non-system screenshots. Cause:${JSON.stringify(err)}`);
    })
  }
}
```

## UIExtensionHostWindowProxyProperties

用于表示宿主应用窗口和UIExtensionComponent组件的信息。

**系统能力**：SystemCapability.ArkUI.ArkUI.Full

**系统接口**：此接口为系统接口

| 名称                         | 类型        | 必填      | 说明                             |
| ------------------------------ | ----------- | -------------------------------- | -------------------------------- |
| uiExtensionHostWindowProxyRect | [window.Rect](arkts-apis-window-i.md#rect7) | 是 | UIExtensionComponent的位置和宽高。 |

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
      bundleName: "com.example.uiextensiondemo",
      abilityName: "ExampleUIExtensionAbility",
      parameters: {
        "ability.want.params.uiExtensionType": "sys/commonUI"
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
      console.log(TAG, `onCreate`);
    }

    onForeground() {
      console.log(TAG, `onForeground`);
    }

    onBackground() {
      console.log(TAG, `onBackground`);
    }

    onDestroy() {
      console.log(TAG, `onDestroy`);
    }

    onSessionCreate(want: Want, session: UIExtensionContentSession) {
      console.log(TAG, `onSessionCreate, want: ${JSON.stringify(want)}`);
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
    private storage: LocalStorage | undefined = this.getUIContext().getSharedLocalStorage();
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
      promise?.then(()=> {
        console.log(`Succeeded in hiding the non-secure windows.`);
      }).catch((err: BusinessError)=> {
        console.log(`Failed to hide the non-secure windows. Cause:${JSON.stringify(err)}`);
      })
      this.extensionHostWindow?.hidePrivacyContentForHost(true)?.then(() => {
        console.log(`Successfully enabled privacy protection for non-system screenshots.`);
      }).catch((err: BusinessError) => {
        console.log(`Failed enabled privacy protection for non-system screenshots. Cause:${JSON.stringify(err)}`);
      })
    }

    aboutToDisappear(): void {
      this.extensionHostWindow?.off('windowSizeChange');
      this.extensionHostWindow?.off('avoidAreaChange');
      let promise = this.extensionHostWindow?.hideNonSecureWindows(false);
      promise?.then(()=> {
        console.log(`Succeeded in showing the non-secure windows.`);
      }).catch((err: BusinessError)=> {
        console.log(`Failed to show the non-secure windows. Cause:${JSON.stringify(err)}`);
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
        Button("获取系统规避区信息").width('90%').margin({top: 5, bottom: 5}).fontSize(16).onClick(() => {
          let avoidArea: window.AvoidArea | undefined = this.extensionHostWindow?.getWindowAvoidArea(window.AvoidAreaType.TYPE_SYSTEM);
          console.info(`系统规避区: ${JSON.stringify(avoidArea)}`);
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
                if (err && err.code != 0) {
                  return;
                }
                this.subWindow?.resize(300, 300, (err, data)=>{
                  if (err && err.code != 0) {
                    return;
                  }
                  this.subWindow?.moveWindowTo(100, 100, (err, data)=>{
                    if (err && err.code != 0) {
                      return;
                    }
                    this.subWindow?.showWindow((err, data) => {
                      if (err && err.code == 0) {
                        console.info(`The subwindow has been shown!`);
                      } else {
                        console.error(`Failed to show the subwindow!`);
                      }
                    });
                  });
                });
              });
            }).catch((error: BusinessError) => {
              console.error(`Create subwindow failed: ${JSON.stringify(error)}`);
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
    "type": "sys/commonUI",
  }
  ```
