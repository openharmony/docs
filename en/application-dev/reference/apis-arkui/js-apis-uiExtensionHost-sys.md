# @ohos.uiExtensionHost (System API)

Intended only for the **\<UIExtensionComponent>** that has process isolation requirements, the **uiExtensionHost** module provides APIs for obtaining the host application window information and information about the component itself.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Updates will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## Modules to Import

```
import uiExtensionHost from '@ohos.uiExtensionHost'
```

## UIExtensionHostWindowProxyProperties

uiExtensionHostWindowProxyRect: window.Rect

Obtains the position, width, and height of this **\<UIExtensionComponent>**.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**System API**: This is a system API.

| Name                        | Type       | Description                            |
| ------------------------------ | ----------- | -------------------------------- |
| uiExtensionHostWindowProxyRect | [window.Rect](js-apis-window.md) | Position, width, and height of the **\<UIExtensionComponent>**.|

**Example**

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

Obtains the area where this window cannot be displayed.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**System API**: This is a system API and cannot be called by third-party applications.

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type |[window.AvoidAreaType](js-apis-window.md) | Yes| Type of the area where the window cannot be displayed.|

**Return value**

| Type| Description|
| -------- | -------- |
|[window.AvoidArea](js-apis-window.md) | Information about the area where the window cannot be displayed.|

**Example**

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

Subscribes to the event indicating changes to the area where the window cannot be displayed.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**System API**: This is a system API and cannot be called by third-party applications.

| Name  | Type                                                        | Mandatory| Description                  |
| -------- | ------------------------------------------------------------ | ---- | ---------------------- |
| type     | string                                                       | Yes  | Event type.|
| callback | Callback<{ type: window.AvoidAreaType, area: window.AvoidArea }> | Yes  | Callback used to return the area information.       |

**Example**

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

Unsubscribes from the event indicating changes to the area where the window cannot be displayed.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**System API**: This is a system API and cannot be called by third-party applications.

| Name  | Type                                                        | Mandatory| Description                  |
| -------- | ------------------------------------------------------------ | ---- | ---------------------- |
| type     | string                                                       | Yes  | Event type.|
| callback | Callback<{ type: window.AvoidAreaType, area: window.AvoidArea }> | Yes  | Callback used for unsubscription.  |

**Example**

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
        Button ("Unsubscribe").onClick () => {
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

Subscribes to the window size change event.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**System API**: This is a system API and cannot be called by third-party applications.

| Name  | Type                 | Mandatory| Description                  |
| -------- | --------------------- | ---- | ---------------------- |
| type     | string                | Yes  | Event type.|
| callback | Callback<window.Size> | Yes  | Callback used to return the window size.        |

**Example**

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

Unsubscribes from the window size change event.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**System API**: This is a system API and cannot be called by third-party applications.

| Name  | Type                 | Mandatory| Description                  |
| -------- | --------------------- | ---- | ---------------------- |
| type     | string                | Yes  | Event type.|
| callback | Callback<window.Size> | Yes  | Callback used for unsubscription.        |

**Example**

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
        Button ("Unsubscribe").onClick () => {
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

Information about the host application window and the **\<UIExtensionComponent>**.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**System API**: This is a system API and cannot be called by third-party applications.

| Name    | Type                                | Description                            |
| ---------- | ------------------------------------ | -------------------------------- |
| properties | UIExtensionHostWindowProxyProperties | Position, width, and height of the **\<UIExtensionComponent>**.|

**Example**

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

### hideNonSecureWindows

hideNonSecureWindows(shouldHide: boolean): Promise\<void>

Sets whether to hide insecure windows.
Insecure windows refer to the windows that may block the **\<UIExtensionComponent>**, such as non-system global floating windows and host subwindows. When the **\<UIExtensionComponent>** is used to present important information, you can hide insecure windows to prevent such information from being blocked. When the **\<UIExtensionComponent>** is not displayed or is destroyed, you must unhide the insecure windows.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name     | Type                     | Mandatory| Description      |
| ----------- | ------------------------- | ---- | ---------- |
| shouldHide  | boolean                   | Yes  | Whether to hide insecure windows. The value **true** means to hide insecure windows, and **false** means the opposite.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

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
    console.log(TAG, `UIExtAbility onSessionCreate`)
    session.loadContent('pages/extension');

    let extensionHostWindow = session.getUIExtensionHostWindowProxy();
    let promise = extensionHostWindow.hideNonSecureWindows(true);
    promise.then(()=> {
      console.log(TAG, `Succeeded in hiding the non-secure windows.`);
    }).catch((err: BusinessError)=> {
      console.log(TAG, `Failed to hide the non-secure windows. Cause:${JSON.stringify(err)}`);
    })
  }

  onSessionDestroy(session: UIExtensionContentSession) {
    console.log(TAG, `UIExtAbility onSessionDestroy`)

    let extensionHostWindow = session.getUIExtensionHostWindowProxy();
    let promise = extensionHostWindow.hideNonSecureWindows(false);
    promise.then(()=> {
      console.log(TAG, `Succeeded in showing the non-secure windows.`);
    }).catch((err: BusinessError)=> {
      console.log(TAG, `Failed to show the non-secure windows. Cause:${JSON.stringify(err)}`);
    })
  }
}
```

## Example

In the provider application, a **UIExtensionHostWindowProxy** object is obtained through the [UIExtensionContentSession](../apis-ability-kit/js-apis-app-ability-uiExtensionContentSession.md) API.

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
        'extensionWindow': extensionHostWindow
    });
    session.loadContent('pages/extension', storage);
  }

  onSessionDestroy(session: UIExtensionContentSession) {
    console.log(TAG, `UIExtAbility onSessionDestroy`)
  }
}
```

In the specific page file:

```ts
import UIExtensionContentSession from '@ohos.app.ability.UIExtensionContentSession'
import uiExtensionHost from '@ohos.uiExtensionHost'
import window from '@ohos.window'


let storage = LocalStorage.getShared()

@Entry(storage)
@Component
struct Hello {
  private extensionWindow: uiExtensionHost.UIExtensionHostWindowProxy | undefined = storage.get<uiExtensionHost.UIExtensionHostWindowProxy>('extensionWindow');

  build() {
    Row() {
      Column() {
        Button("TYPE_SYSTEM").onClick(() => {
          if (this.extensionWindow != undefined) {
            let avoidArea: window.AvoidArea = this.extensionWindow.getWindowAvoidArea(window.AvoidAreaType.TYPE_SYSTEM)
            console.log(`${JSON.stringify(avoidArea)}`)
          }
        })
        Button("TYPE_CUTOUT").onClick(() => {
          if (this.extensionWindow != undefined) {
            let avoidArea: window.AvoidArea = this.extensionWindow.getWindowAvoidArea(window.AvoidAreaType.TYPE_CUTOUT)
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
