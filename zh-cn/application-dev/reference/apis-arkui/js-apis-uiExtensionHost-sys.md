# @ohos.uiExtensionHost

仅用于在有进程隔离诉求的UIExtensionComponent组件中为提供方应用提供宿主应用的窗口信息和组件本身的信息。

> **说明**
>
> 从API Version 11开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> 本模块接口为系统接口。

## 导入模块

```
import uiExtensionHost from '@ohos.uiExtensionHost'
```

## UIExtensionHostWindowProxyProperties

uiExtensionHostWindowProxyRect: window.Rect

获取UIExtensionComponent的位置和宽高信息。

**系统能力**：SystemCapability.ArkUI.ArkUI.Full

**系统接口**：此接口为系统接口

| 属性名                         | 类型        | 说明                             |
| ------------------------------ | ----------- | -------------------------------- |
| uiExtensionHostWindowProxyRect | [window.Rect](js-apis-window.md) | UIExtensionComponent的位置和宽高。 |

**示例**

```ts
@Entry(storage)
@Component
struct Hello {
  private extensionWindow: uiExtensionHost.UIExtensionHostWindowProxy = storage.get<uiExtensionHost.UIExtensionHostWindowProxy>('extensionWindow')
  private extensionWindowRect = this.extensionWindow.properties.uiExtensionHostWindowProxyRect

  build() {
    Row() {
      Column() {
        Text("Hello world")
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## UIExtensionHostWindowProxy

### getWindowAvoidArea

getWindowAvoidArea(type: window.AvoidAreaType): window.AvoidArea

获取窗口具体避让类型的避让区信息。

**系统能力**：SystemCapability.ArkUI.ArkUI.Full

**系统API**：此接口为系统接口，三方应用不支持调用。

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type |[window.AvoidAreaType](js-apis-window.md) | 是 | 获取的避让区类型 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
|[window.AvoidArea](js-apis-window.md) | 避让区信息 |

**示例**

```ts
@Entry(storage)
@Component
struct Hello {
  private extensionWindow: uiExtensionHost.UIExtensionHostWindowProxy = storage.get<uiExtensionHost.UIExtensionHostWindowProxy>('extensionWindow')

  build() {
    Row() {
      Column() {
        Button("TYPE_SYSTEM").onClick(() => {
          if (this.extensionWindow != undefined) {
            let avoidArea: window.AvoidArea = this.extensionWindow.getWindowAvoidArea(window.AvoidAreaType.TYPE_SYSTEM)
            console.log(`${JSON.stringify(avoidArea)}`)
          }
        })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### on('avoidAreaChange')

on(type: 'avoidAreaChange', callback: Callback<{ type: window.AvoidAreaType, area: window.AvoidArea }>): void

注册避让区域变更回调方法

**系统能力**：SystemCapability.ArkUI.ArkUI.Full

**系统API**：此接口为系统接口，三方应用不支持调用。

| 参数名   | 类型                                                         | 必填 | 说明                   |
| -------- | ------------------------------------------------------------ | ---- | ---------------------- |
| type     | string                                                       | 是   | 注册的回调方法类型说明。 |
| callback | Callback<{ type: window.AvoidAreaType, area: window.AvoidArea }> | 是   | 注册的回调方法。        |

**示例**

```ts
@Entry(storage)
@Component
struct Hello {
  private extensionWindow: uiExtensionHost.UIExtensionHostWindowProxy = storage.get<uiExtensionHost.UIExtensionHostWindowProxy>('extensionWindow')

  aboutToAppear() {
    this.extensionWindow.on('avoidAreaChange', (avoid) => {
      console.info(`${JSON.stringify(avoid.type)}`)
      console.info(`${JSON.stringify(avoid.area)}`)
    })
  }

  build() {
    Row() {
      Column() {
        Text("Hello world")
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### off('avoidAreaChange')

off(type: 'avoidAreaChange', callback?: Callback<{ type: window.AvoidAreaType, area: window.AvoidArea }>): void

注销避让区域变更回调方法

**系统能力**：SystemCapability.ArkUI.ArkUI.Full

**系统API**：此接口为系统接口，三方应用不支持调用。

| 参数名   | 类型                                                         | 必填 | 说明                   |
| -------- | ------------------------------------------------------------ | ---- | ---------------------- |
| type     | string                                                       | 是   | 注销的回调方法类型说明。 |
| callback | Callback<{ type: window.AvoidAreaType, area: window.AvoidArea }> | 是   | 注销的回调方法。   |

**示例**

```ts
@Entry(storage)
@Component
struct Hello {
  private extensionWindow: uiExtensionHost.UIExtensionHostWindowProxy = storage.get<uiExtensionHost.UIExtensionHostWindowProxy>('extensionWindow')
  private avoidAreaChangeCallback: Callback<{ type: window.AvoidAreaType, area: window.AvoidArea }> = (avoid) => {
    console.info(`${JSON.stringify(avoid.area)}`)
    console.info(`${JSON.stringify(avoid.type)}`)
  }

  aboutToAppear() {
    this.extensionWindow.on('avoidAreaChange', this.avoidAreaChangeCallback)
  }

  build() {
    Row() {
      Column() {
        Button("注销回调").onClick(() => {
          this.extensionWindow.off('avoidAreaChange', this.avoidAreaChangeCallback)
        })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### on('windowSizeChange')

on(type: 'windowSizeChange', callback: Callback<window.Size>): void

注册窗口信息变更回调方法

**系统能力**：SystemCapability.ArkUI.ArkUI.Full

**系统API**：此接口为系统接口，三方应用不支持调用。

| 参数名   | 类型                  | 必填 | 说明                   |
| -------- | --------------------- | ---- | ---------------------- |
| type     | string                | 是   | 注册的回调方法类型说明。 |
| callback | Callback<window.Size> | 是   | 注册的回调方法。         |

**示例**

```ts
@Entry(storage)
@Component
struct Hello {
  private extensionWindow: uiExtensionHost.UIExtensionHostWindowProxy = storage.get<uiExtensionHost.UIExtensionHostWindowProxy>('extensionWindow')

  aboutToAppear() {
    this.extensionWindow.on('windowSizeChange', (size) => {
      console.info(`${JSON.stringify(size)}`)
    })
  }

  build() {
    Row() {
      Column() {
        Text("Hello world")
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### off('windowSizeChange')

off(type: 'windowSizeChange', callback?: Callback<window.Size>): void

注销窗口信息变更回调方法

**系统能力**：SystemCapability.ArkUI.ArkUI.Full

**系统API**：此接口为系统接口，三方应用不支持调用。

| 参数名   | 类型                  | 必填 | 说明                   |
| -------- | --------------------- | ---- | ---------------------- |
| type     | string                | 是   | 注销的回调方法类型说明。 |
| callback | Callback<window.Size> | 是   | 注销的回调方法。         |

**示例**

```ts
@Entry(storage)
@Component
struct Hello {
  private extensionWindow: uiExtensionHost.UIExtensionHostWindowProxy = storage.get<uiExtensionHost.UIExtensionHostWindowProxy>('extensionWindow')
  private windowSizeChangeCallback: Callback<window.Size> = (size) => {
    console.info(`${JSON.stringify(size)}`)
  }

  aboutToAppear() {
    this.extensionWindow.on('windowSizeChange', this.windowSizeChangeCallback)
  }


  build() {
    Row() {
      Column() {
        Button("注销回调").onClick(() => {
          this.extensionWindow.off('windowSizeChange', this.windowSizeChangeCallback)
        })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### properties

properties: UIExtensionHostWindowProxyProperties

UIExtensionComponent组件以及宿主窗口的信息

**系统能力**：SystemCapability.ArkUI.ArkUI.Full

**系统API**：此接口为系统接口，三方应用不支持调用。

| 参数名     | 类型                                 | 说明                             |
| ---------- | ------------------------------------ | -------------------------------- |
| properties | UIExtensionHostWindowProxyProperties | UIExtensionComponent的位置和宽高。 |

**示例**

```ts
@Entry(storage)
@Component
struct Hello {
  private extensionWindow: uiExtensionHost.UIExtensionHostWindowProxy = storage.get<uiExtensionHost.UIExtensionHostWindowProxy>('extensionWindow')
  private properties = this.extensionWindow.properties

  build() {
    Row() {
      Column() {
        Text(`UIExtensionWindowRect: ${JSON.stringify(this.properties.uiExtensionHostWindowProxyRect)}`)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## 示例

在提供方中应用中，首先通过[UIExtensionContentSession](../apis-ability-kit/js-apis-app-ability-uiExtensionContentSession.md)接口获取到UIExtensionHostWindowProxy对象。

```ts
import UIExtensionAbility from '@ohos.app.ability.UIExtensionAbility'
import UIExtensionContentSession from '@ohos.app.ability.UIExtensionContentSession'
import Want from '@ohos.app.ability.Want';
const TAG: string = '[UIExtAbility]'
export default class UIExtAbility extends UIExtensionAbility {

  onCreate() {
    console.log(TAG, `UIExtAbility onCreate`)
  }

  onForeground() {
    console.log(TAG, `UIExtAbility onForeground`)
  }

  onBackground() {
    console.log(TAG, `UIExtAbility onBackground`)
  }

  onDestroy() {
    console.log(TAG, `UIExtAbility onDestroy`)
  }

  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    let extensionHostWindow = session.getUIExtensionHostWindowProxy();
    let storage: LocalStorage = new LocalStorage({
        'session': session,
        'extensionHostWindow': extensionHostWindow
    });
    session.loadContent('pages/extension', storage);
  }

  onSessionDestroy(session: UIExtensionContentSession) {
    console.log(TAG, `UIExtAbility onSessionDestroy`)
  }
}
```

在具体的页面中

```ts
import UIExtensionContentSession from '@ohos.app.ability.UIExtensionContentSession'
import uiExtensionHost from '@ohos.uiExtensionHost'
import window from '@ohos.window'


let storage = LocalStorage.getShared()

@Entry(storage)
@Component
struct Hello {
  private extensionWindow: uiExtensionHost.UIExtensionHostWindowProxy = storage.get<uiExtensionHost.UIExtensionHostWindowProxy>('extensionWindow');
  private extensionWindowRect = this.extensionWindow.properties.uiExtensionHostWindowProxyRect;

  build() {
    Row() {
      Column() {
        Button("TYPE_SYSTEM").onClick(() => {
          let avoidArea: window.AvoidArea = this.extensionWindow.getWindowAvoidArea(window.AvoidAreaType.TYPE_SYSTEM)
          console.log(`${JSON.stringify(avoidArea)}`)
        })
        Button("TYPE_CUTOUT").onClick(() => {
          let avoidArea: window.AvoidArea = this.extensionWindow.getWindowAvoidArea(window.AvoidAreaType.TYPE_CUTOUT)
          console.log(`${JSON.stringify(avoidArea)}`)
        })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```