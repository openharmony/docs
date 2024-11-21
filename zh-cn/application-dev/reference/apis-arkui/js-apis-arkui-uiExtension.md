# @ohos.arkui.uiExtension (uiExtension)

用于EmbeddedUIExtensionAbility（或UIExtensionAbility）中获取宿主应用的窗口信息或对应的EmbeddedComponent<!--Del-->（或UIExtensionComponent）<!--DelEnd-->组件的信息。

> **说明**
>
> 从API Version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>

## 导入模块

```
import { uiExtension } from '@kit.ArkUI'
```

## WindowProxy

### getWindowAvoidArea

getWindowAvoidArea(type: window.AvoidAreaType): window.AvoidArea

获取宿主应用窗口内容规避的区域；如系统栏区域、刘海屏区域、手势区域、软键盘区域等与宿主窗口内容重叠时，需要宿主窗口内容避让的区域。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.ArkUI.ArkUI.Full

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type |[window.AvoidAreaType](./js-apis-window.md#avoidareatype7) | 是 | 表示规避区类型。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
|[window.AvoidArea](./js-apis-window.md#avoidarea7) | 宿主窗口内容规避区域。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |

**示例**

```ts
// ExtensionProvider.ts
import { EmbeddedUIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends EmbeddedUIExtensionAbility {
  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    const extensionWindow = session.getUIExtensionWindowProxy();
    // 获取宿主应用窗口的避让信息
    let avoidArea: window.AvoidArea | undefined = extensionWindow?.getWindowAvoidArea(window.AvoidAreaType.TYPE_SYSTEM);
    console.info(`avoidArea: ${JSON.stringify(avoidArea)}`);
  }
}
```

### on('avoidAreaChange')

on(type: 'avoidAreaChange', callback: Callback&lt;AvoidAreaInfo&gt;): void

注册系统规避区变化的监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.ArkUI.ArkUI.Full

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ---- | ---- | ---- |
| type   | string | 是 | 监听的事件类型，固定为'avoidAreaChange'，即系统规避区变化事件。 |
| callback | [Callback](../apis-basic-services-kit/js-apis-base.md#callback)<[AvoidAreaInfo](#avoidareainfo)> | 是 | 回调函数：入参用于接收当前规避区的信息。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |

**示例**

```ts
// ExtensionProvider.ts
import { EmbeddedUIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';
import { uiExtension } from '@kit.ArkUI';

export default class EntryAbility extends EmbeddedUIExtensionAbility {
  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    const extensionWindow = session.getUIExtensionWindowProxy();
    // 注册避让区变化的监听
    extensionWindow.on('avoidAreaChange', (info: uiExtension.AvoidAreaInfo) => {
      console.info(`The avoid area of the host window is: ${JSON.stringify(info.area)}.`);
    });
  }
}
```

### off('avoidAreaChange')

off(type: 'avoidAreaChange', callback?: Callback&lt;AvoidAreaInfo&gt;): void

注销系统规避区变化的监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.ArkUI.ArkUI.Full

| 参数名   | 类型 | 必填 | 说明 |
| -------- | ---- | ---- | ---  |
| type     | string | 是 | 注销的事件类型，固定为'avoidAreaChange'，即系统规避区变化事件。 |
| callback | [Callback](../apis-basic-services-kit/js-apis-base.md#callback)<[AvoidAreaInfo](#avoidareainfo)> | 否 | 回调函数：如果传入该参数，则关闭该监听。如果未传入参数，则关闭所有系统规避区变化的监听。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed. |

**示例**

```ts
// ExtensionProvider.ts
import { EmbeddedUIExtensionAbility, UIExtensionContentSession } from '@kit.AbilityKit';

export default class EntryAbility extends EmbeddedUIExtensionAbility {
  onSessionDestroy(session: UIExtensionContentSession) {
    const extensionWindow = session.getUIExtensionWindowProxy();
    // 注销所有避让区变化的监听
    extensionWindow.off('avoidAreaChange');
  }
}
```

### on('windowSizeChange')

on(type: 'windowSizeChange', callback: Callback<window.Size>): void

注册宿主应用窗口尺寸变化的监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.ArkUI.ArkUI.Full

| 参数名   | 类型                  | 必填 | 说明                   |
| -------- | --------------------- | ---- | ---------------------- |
| type     | string                | 是   | 监听的事件类型，固定为'windowSizeChange'，即窗口尺寸变化事件。 |
| callback | [Callback](../apis-basic-services-kit/js-apis-base.md#callback)<[window.Size](js-apis-window.md#size7)> | 是   | 回调函数：入参用于接收当前窗口的尺寸。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |

**示例**

```ts
// ExtensionProvider.ts
import { EmbeddedUIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends EmbeddedUIExtensionAbility {
  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    const extensionWindow = session.getUIExtensionWindowProxy();
    // 注册宿主应用窗口大小变化的监听
    extensionWindow.on('windowSizeChange', (size: window.Size) => {
      console.info(`The avoid area of the host window is: ${JSON.stringify(size)}.`);
    });
  }
}
```

### off('windowSizeChange')

off(type: 'windowSizeChange', callback?: Callback<window.Size>): void

注销宿主应用窗口尺寸变化的监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.ArkUI.ArkUI.Full

| 参数名   | 类型                  | 必填 | 说明                   |
| -------- | --------------------- | ---- | ---------------------- |
| type     | string                | 是   | 注销的事件类型，固定值：'windowSizeChange'，即窗口尺寸变化事件。 |
| callback | [Callback](../apis-basic-services-kit/js-apis-base.md#callback)<[window.Size](js-apis-window.md#size7)> | 否   | 回调函数：如果传入该参数，则关闭该监听。如果未传入参数，则关闭所有系统规避区变化的监听。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |

**示例**

```ts
// ExtensionProvider.ts
import { EmbeddedUIExtensionAbility, UIExtensionContentSession } from '@kit.AbilityKit';

export default class EntryAbility extends EmbeddedUIExtensionAbility {
  onSessionDestroy(session: UIExtensionContentSession) {
    const extensionWindow = session.getUIExtensionWindowProxy();
    // 注销宿主应用窗口大小变化的监听
    extensionWindow.off('windowSizeChange');
  }
}
```

### on('windowRectChange')

on(type: 'windowRectChange', callback: Callback<window.RectChangeOptions>): void

注册 EmbeddedComponent 位置及大小变化的监听。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                           | 必填 | 说明                                                     |
| -------- | ------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                         | 是   | 监听事件，固定为'windowRectChange'，即EmbeddedComponent 矩形变化事件。 |
| callback | [Callback](../apis-basic-services-kit/js-apis-base.md#callback)<[window.RectChangeOptions](js-apis-window.md#rectchangeoptions12)> | 是   | 回调函数。返回当前 EmbeddedComponent 矩形变化值及变化原因。                           |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
// ExtensionProvider.ts
import { EmbeddedUIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends EmbeddedUIExtensionAbility {
  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    const extensionWindow = session.getUIExtensionWindowProxy();
    // 注册 EmbeddedComponent 位置及大小变化的监听
    extensionWindow.on('windowRectChange', (data: window.RectChangeOptions) => {
        console.info('Succeeded window rect changes. Data: ' + JSON.stringify(data));
    });
  }
}
```

### off('windowRectChange')

off(type: 'windowRectChange', callback?: Callback<window.RectChangeOptions>): void

注销 EmbeddedComponent 位置及大小变化的监听。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                           | 必填 | 说明                                                         |
| -------- | ------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                         | 是   | 监听事件，固定为'windowRectChange'，即EmbeddedComponent 矩形变化事件。 |
| callback | [Callback](../apis-basic-services-kit/js-apis-base.md#callback)<[window.RectChangeOptions](js-apis-window.md#rectchangeoptions12)> | 否   | 回调函数。返回当前 EmbeddedComponent 矩形变化值及变化原因。如果传入参数，则关闭该监听。如果未传入参数，则关闭所有 EmbeddedComponent 矩形变化的监听。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
// ExtensionProvider.ts
import { EmbeddedUIExtensionAbility, UIExtensionContentSession } from '@kit.AbilityKit';

export default class EntryAbility extends EmbeddedUIExtensionAbility {
  onSessionDestroy(session: UIExtensionContentSession) {
    const extensionWindow = session.getUIExtensionWindowProxy();
    // 注销 EmbeddedComponent 位置及大小变化的监听
    extensionWindow.off('windowRectChange');
  }
}
```

### createSubWindowWithOptions

createSubWindowWithOptions(name: string, subWindowOptions: window.SubWindowOptions): Promise&lt;window.Window&gt;

创建该WindowProxy实例下的子窗口，使用Promise异步回调。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型   | 必填 | 说明           |
| ------ | ------ | ---- | -------------- |
| name   | string | 是   | 子窗口的名字。 |
| subWindowOptions | [window.SubWindowOptions](js-apis-window.md#subwindowoptions12) | 是   | 子窗口参数。  |

**返回值：**

| 类型                             | 说明                                             |
| -------------------------------- | ------------------------------------------------ |
| Promise&lt;[window.Window](js-apis-window.md#window)&gt; | Promise对象。返回当前WindowProxy下创建的子窗口对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 801 | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300005 | This window proxy is abnormal. |

**示例：**

```ts
// ExtensionProvider.ts
import { EmbeddedUIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends EmbeddedUIExtensionAbility {
  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    const extensionWindow = session.getUIExtensionWindowProxy();
    const subWindowOpts: window.SubWindowOptions = {
      title: 'This is a subwindow',
      decorEnabled: true
    };
    // 创建子窗口
    extensionWindow.createSubWindowWithOptions('subWindowForHost', subWindowOpts)
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

## AvoidAreaInfo

用于表示窗口规避区的信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型                 | 必填 | 说明        |
| ------ | -------------------- | ------------------ | ------------------ |
| type   | [window.AvoidAreaType](js-apis-window.md#avoidareatype7) | 是 | 窗口规避区类型。   |
| area   | [window.AvoidArea](js-apis-window.md#avoidarea7)     | 是| 窗口内容规避区域。 |


## 完整示例

本示例展示文档中所有API在EmbeddedUIExtensionAbility中的基础使用方式，示例应用的`bundleName`为"com.example.embeddeddemo", 被拉起的`EmbeddedUIExtensionAbility`为"ExampleEmbeddedAbility".

- 示例应用中的EntryAbility(UIAbility)加载首页文件：`pages/Index.ets`，其中内容如下：

  ```ts
  // pages/Index.ets -- UIAbility启动时加载此页面
  import { Want } from '@kit.AbilityKit';

  @Entry
  @Component
  struct Index {
    @State message: string = 'Message: '
    private want: Want = {
      bundleName: "com.example.embeddeddemo",
      abilityName: "ExampleEmbeddedAbility",
    }

    build() {
      Row() {
        Column() {
          Text(this.message).fontSize(30)
          EmbeddedComponent(this.want, EmbeddedType.EMBEDDED_UI_EXTENSION)
            .width('100%')
            .height('90%')
            .onTerminated((info)=>{
              this.message = 'Termination: code = ' + info.code + ', want = ' + JSON.stringify(info.want);
            })
            .onError((error)=>{
              this.message = 'Error: code = ' + error.code;
            })
        }
        .width('100%')
      }
      .height('100%')
    }
  }
  ```

- EmbeddedComponent拉起的EmbeddedUIExtensionAbility在`ets/extensionAbility/ExampleEmbeddedAbility`文件中实现，内容如下：

  ```ts
  import { EmbeddedUIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';

  const TAG: string = '[ExampleEmbeddedAbility]'
  export default class ExampleEmbeddedAbility extends EmbeddedUIExtensionAbility {
    
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

- EmbeddedUIExtensionAbility的入口页面文件`pages/extension.ets`内容如下：

  ```ts
  import { UIExtensionContentSession } from '@kit.AbilityKit';
  import { uiExtension, window } from '@kit.ArkUI';
  import { BusinessError } from '@kit.BasicServicesKit';
  let storage = LocalStorage.getShared()

  @Entry(storage)
  @Component
  struct Extension {
    @State message: string = 'EmbeddedUIExtensionAbility Index';
    private session: UIExtensionContentSession | undefined = storage.get<UIExtensionContentSession>('session');
    private extensionWindow: uiExtension.WindowProxy | undefined = this.session?.getUIExtensionWindowProxy();
    private subWindow: window.Window | undefined = undefined;

    aboutToAppear(): void {
      this.extensionWindow?.on('windowSizeChange', (size: window.Size) => {
          console.info(`size = ${JSON.stringify(size)}`);
      });
      this.extensionWindow?.on('windowRectChange', (data: window.RectChangeOptions) => {
          console.info('Succeeded window rect changes. Data: ' + JSON.stringify(data));
      });
      this.extensionWindow?.on('avoidAreaChange', (info: uiExtension.AvoidAreaInfo) => {
          console.info(`type = ${JSON.stringify(info.type)}, area = ${JSON.stringify(info.area)}`);
      });
    }

    aboutToDisappear(): void {
      this.extensionWindow?.off('windowSizeChange');
      this.extensionWindow?.off('windowRectChange');
      this.extensionWindow?.off('avoidAreaChange');
    }

    build() {
      Column() {
        Text(this.message)
          .fontSize(20)
          .fontWeight(FontWeight.Bold)
        Button("获取系统规避区信息").width('90%').margin({top: 5, bottom: 5}).fontSize(16).onClick(() => {
          let avoidArea: window.AvoidArea | undefined = this.extensionWindow?.getWindowAvoidArea(window.AvoidAreaType.TYPE_SYSTEM);
          console.info(`系统规避区: ${JSON.stringify(avoidArea)}`);
        })
        Button("创建子窗口").width('90%').margin({top: 5, bottom: 5}).fontSize(16).onClick(() => {
          let subWindowOpts: window.SubWindowOptions = {
              'title': 'This is a subwindow',
              decorEnabled: true
          };
          this.extensionWindow?.createSubWindowWithOptions('subWindowForHost', subWindowOpts)
              .then((subWindow: window.Window) => {
                  this.subWindow = subWindow;
                  this.subWindow.loadContent('pages/Index', storage, (err, data) =>{
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
    "name": "ExampleEmbeddedAbility",
    "srcEntry": "./ets/extensionAbility/ExampleEmbeddedAbility.ets",
    "type": "embeddedUI"
  }
  ```
