# @ohos.uiExtensionHost (System API)

Intended only for the **UIExtensionComponent** that has process isolation requirements, the **uiExtensionHost** module provides APIs for obtaining the host application window information and information about the component itself.

> **NOTE**
>
> No new function will be added to this module. Related functions will be provided in the [uiExtension](js-apis-arkui-uiExtension.md) interface.
>
> The initial APIs of this module are supported since API version 11. Updates will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## Modules to Import

```
import { uiExtensionHost } from '@kit.ArkUI'
```

## UIExtensionHostWindowProxy

### getWindowAvoidArea

getWindowAvoidArea(type: window.AvoidAreaType): window.AvoidArea

Obtains the area where this window cannot be displayed, for example, the system bar area, notch, gesture area, and soft keyboard area.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**System API**: This is a system API and cannot be called by third-party applications.

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | [window.AvoidAreaType](js-apis-window.md#avoidareatype7) | Yes| Type of the area.|

**Return value**

| Type| Description|
| -------- | -------- |
| [window.AvoidArea](js-apis-window.md#avoidarea7) | Area where the window cannot be displayed.|

**Return value**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```ts
// ExtensionProvider.ts

import { UIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIExtensionAbility {
  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    const extensionHostWindow = session.getUIExtensionHostWindowProxy();
    // Obtain the information about the area where the window cannot be displayed.
    const avoidArea = extensionHostWindow.getWindowAvoidArea(window.AvoidAreaType.TYPE_SYSTEM);
    console.log(`avoidArea: ${JSON.stringify(avoidArea)}`);
  }
}
```

### on('avoidAreaChange')

on(type: 'avoidAreaChange', callback: Callback<{ type: window.AvoidAreaType, area: window.AvoidArea }>): void

Subscribes to the event indicating changes to the area where the window cannot be displayed.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**System API**: This is a system API and cannot be called by third-party applications.

| Name  | Type  | Mandatory| Description                  |
| -------- | ------ | ---- | ---------------------- |
| type     | string | Yes  | Event type. The value is fixed at **'avoidAreaChange'**, indicating the event of changes to the area where the window cannot be displayed.|
| callback | [Callback](../apis-basic-services-kit/js-apis-base.md#callback)<{ type: [window.AvoidAreaType](js-apis-window.md#avoidareatype7), area: [window.AvoidArea](js-apis-window.md#avoidarea7) }> | Yes| Callback used to return the area information. **type** indicates the type of the area where the window cannot be displayed, and **area** indicates the area.|

**Error codes**

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: <br> 1. Mandatory parameters are left unspecified.<br> 2. Incorrect parameters types.<br> 3. Parameter verification failed. |

**Example**

```ts
// ExtensionProvider.ts
import { UIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';

export default class EntryAbility extends UIExtensionAbility {
  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    const extensionHostWindow = session.getUIExtensionHostWindowProxy();
    // Subscribe to the event indicating changes to the area where the window cannot be displayed.
    extensionHostWindow.on('avoidAreaChange', (info) => {
      console.info(`The avoid area of the host window is: ${JSON.stringify(info.area)}.`);
    });
  }
}
```

### off('avoidAreaChange')

off(type: 'avoidAreaChange', callback?: Callback<{ type: window.AvoidAreaType, area: window.AvoidArea }>): void

Unsubscribes from the event indicating changes to the area where the window cannot be displayed.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**System API**: This is a system API and cannot be called by third-party applications.

| Name  | Type  | Mandatory| Description                  |
| -------- | ------ | ---- | ---------------------- |
| type     | string | Yes  | Event type. The value is fixed at **'avoidAreaChange'**, indicating the event of changes to the area where the window cannot be displayed.|
| callback | [Callback](../apis-basic-services-kit/js-apis-base.md#callback)<{ type: [window.AvoidAreaType](js-apis-window.md#avoidareatype7), area: [window.AvoidArea](js-apis-window.md#avoidarea7) }> | No| Callback used for unsubscription. If a value is passed in, the corresponding subscription is canceled. If no value is passed in, all subscriptions to the specified event are canceled.|

**Error codes**

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: <br> 1. Mandatory parameters are left unspecified.<br> 2. Incorrect parameters types.<br> 3. Parameter verification failed. |

**Example**

```ts
// ExtensionProvider.ts
import { UIExtensionAbility, UIExtensionContentSession} from '@kit.AbilityKit';

export default class EntryAbility extends UIExtensionAbility {
  onSessionDestroy(session: UIExtensionContentSession) {
    const extensionHostWindow = session.getUIExtensionHostWindowProxy();
    // Cancel all subscriptions to the event indicating changes to the area where the window cannot be displayed.
    extensionHostWindow.off('avoidAreaChange');
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
| type     | string                | Yes  | Event type. The value is fixed at **'windowSizeChange'**, indicating the window size change event.|
| callback | [Callback](../apis-basic-services-kit/js-apis-base.md#callback)<[window.Size](js-apis-window.md#size7)> | Yes  | Callback used to return the window size.|

**Error codes**

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: <br> 1. Mandatory parameters are left unspecified.<br> 2. Incorrect parameters types.<br> 3. Parameter verification failed. |

**Example**

```ts
// ExtensionProvider.ts
import { UIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';

export default class EntryAbility extends UIExtensionAbility {
  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    const extensionHostWindow = session.getUIExtensionHostWindowProxy();
    // Subscribe to the window size change event of the host application.
    extensionHostWindow.on('windowSizeChange', (size) => {
      console.info(`The avoid area of the host window is: ${JSON.stringify(size)}.`);
    });
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
| type     | string                | Yes  | Event type. The value is fixed at **'windowSizeChange'**, indicating the window size change event.|
| callback | [Callback](../apis-basic-services-kit/js-apis-base.md#callback)<[window.Size](js-apis-window.md#size7)> | No  | Callback used for unsubscription. If a value is passed in, the corresponding subscription is canceled. If no value is passed in, all subscriptions to the specified event are canceled.|

**Error codes**

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: <br> 1. Mandatory parameters are left unspecified.<br> 2. Incorrect parameters types.<br> 3. Parameter verification failed. |

**Example**

```ts
// ExtensionProvider.ts
import { UIExtensionAbility, UIExtensionContentSession } from '@kit.AbilityKit';

export default class EntryAbility extends UIExtensionAbility {
  onSessionDestroy(session: UIExtensionContentSession) {
    const extensionHostWindow = session.getUIExtensionHostWindowProxy();
    // Unsubscribe from the window size change event of the host application.
    extensionHostWindow.off('windowSizeChange');
  }
}
```

### properties

properties: UIExtensionHostWindowProxyProperties

Provides the information about the host application window and the **UIExtensionComponent**.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**System API**: This is a system API and cannot be called by third-party applications.

| Name    | Type                                | Description                            |
| ---------- | ------------------------------------ | -------------------------------- |
| properties | [UIExtensionHostWindowProxyProperties](#uiextensionhostwindowproxyproperties) | Information about the host application window and the **UIExtensionComponent**.|

**Example**

```ts
// ExtensionProvider.ts
import { UIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';

export default class EntryAbility extends UIExtensionAbility {
  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    const extensionHostWindow = session.getUIExtensionHostWindowProxy();
    // Obtain the position and size of the <UIExtensionComponent>.
    const rect = extensionHostWindow.properties.uiExtensionHostWindowProxyRect;
    console.log(`Rect Info: ${JSON.stringify(rect)}`);
  }
}
```

### hideNonSecureWindows

hideNonSecureWindows(shouldHide: boolean): Promise&lt;void&gt;

Sets whether to hide insecure windows.
> **NOTE**
>
> Insecure windows refer to the windows that may block the **UIExtensionComponent**, such as global floating windows, host subwindows, and dialog box windows created by the host application, excluding the aforementioned types of windows created by system applications. When the **UIExtensionComponent** is used to present important information, you can hide insecure windows to prevent such information from being obscured. When the **UIExtensionComponent** is not displayed or is destroyed, you must unhide the insecure windows. By default, the **UIExtensionComponent** created using the **CreateModalUIExtension** API hides insecure windows. To cancel this behavior and show insecure windows, apply for the **ohos.permission.ALLOW_SHOW_NON_SECURE_WINDOWS** permission and call this API to set **shouldHide** to **false**.

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

**Error codes**

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 202      | Permission verification failed. A non-system application calls a system API. |
| 401      | Parameter error. Possible causes: <br> 1. Mandatory parameters are left unspecified. <br> 2. Incorrect parameters types. <br> 3. Parameter verification failed. |
| 1300002  | Abnormal state. Possible causes: <br> 1. Permission denied. Interface caller does not have permission "ohos.permission.ALLOW_SHOW_NON_SECURE_WINDOWS". <br> 2. The UIExtension window proxy is abnormal. |
| 1300003  | This window manager service works abnormally. |

**Example**

```ts
// ExtensionProvider.ts

import { UIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIExtensionAbility {
  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    const extensionHostWindow = session.getUIExtensionHostWindowProxy();
    // Hide insecure windows.
    extensionHostWindow.hideNonSecureWindows(true).then(()=> {
      console.log(`Succeeded in hiding the non-secure windows.`);
    }).catch((err: BusinessError)=> {
      console.log(`Failed to hide the non-secure windows. Cause:${JSON.stringify(err)}`);
    })
  }
  onSessionDestroy(session: UIExtensionContentSession) {
    const extensionHostWindow = session.getUIExtensionHostWindowProxy();
    // Unhide insecure windows.
    extensionHostWindow.hideNonSecureWindows(false).then(()=> {
      console.log(`Succeeded in showing the non-secure windows.`);
    }).catch((err: BusinessError)=> {
      console.log(`Failed to show the non-secure windows. Cause:${JSON.stringify(err)}`);
    })
  }
}
```

### createSubWindowWithOptions<sup>12+</sup>

createSubWindowWithOptions(name: string, subWindowOptions: window.SubWindowOptions): Promise&lt;window.Window&gt;

Creates a subwindow for this **UIExtensionHostWindowProxy** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**System API**: This is a system API and cannot be called by third-party applications.

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type  | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| name   | string | Yes  | Name of the subwindow.|
| subWindowOptions | [window.SubWindowOptions](js-apis-window.md#subwindowoptions11) | Yes| Parameters used for creating the subwindow.|

**Return value**

| Type                            | Description                                            |
| -------------------------------- | ------------------------------------------------ |
| Promise&lt;[window.Window](js-apis-window.md#window)&gt; | Promise used to return the subwindow created.|

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 401 | Parameter error. Possible causes: <br> 1. Mandatory parameters are left unspecified.<br> 2. Incorrect parameters types.<br> 3. Parameter verification failed. |
| 801 | Capability not supported on this device. |
| 1300002 | This window state is abnormal. |
| 1300005 | This window proxy is abnormal. |

**Example:**

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
    // Create a subwindow.
    extensionHostWindow.createSubWindowWithOptions('subWindowForHost', subWindowOpts)
      .then((subWindow: window.Window) => {
        subWindow.loadContent('pages/Index', (err, data) =>{
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

Adds or deletes the watermark flag for this window. This API uses a promise to return the result.
> **NOTE**
>
> With the watermark flag added, the watermark is applied on the full screen when the window is in the foreground, regardless of whether the window is displayed in full screen, floating, and split screen mode.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type    | Mandatory| Description                                           |
| ------ | ------- | --- | ------------------------------------------------ |
| enable | boolean | Yes  | Whether to add or delete the flag. The value **true** means to add the watermark flag, and **false** means to delete the watermark flag.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

| ID| Error Message|
| ------- | ---------------------------------------------- |
| 1300002 | This window state is abnormal.                 |
| 1300003 | This window manager service works abnormally.  |
| 1300008 | The operation is on invalid display. |

**Example**

```ts
// ExtensionProvider.ts
import { UIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIExtensionAbility {
  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    const extensionHostWindow = session.getUIExtensionHostWindowProxy();
    // Add the watermark flag.
    extensionHostWindow.setWaterMarkFlag(true).then(() => {
      console.log(`Succeeded in setting water mark flag of window.`);
    }).catch((err: BusinessError) => {
      console.log(`Failed to setting water mark flag of window. Cause:${JSON.stringify(err)}`);
    })
  }
  onSessionDestroy(session: UIExtensionContentSession) {
    const extensionHostWindow = session.getUIExtensionHostWindowProxy();
    // Delete the watermark flag.
    extensionHostWindow.setWaterMarkFlag(false).then(() => {
      console.log(`Succeeded in deleting water mark flag of window.`);
    }).catch((err: BusinessError) => {
      console.log(`Failed to deleting water mark flag of window. Cause:${JSON.stringify(err)}`);
    })
  }
}
```
### hidePrivacyContentForHost<sup>13+</sup>

hidePrivacyContentForHost(shouldHide: boolean): Promise&lt;void&gt;

Sets whether to enable privacy protection for the UIExtension component during non-system screenshots. This API uses a promise to return the result.
> **NOTE**
>
> When privacy protection is enabled, using [window.snapshot](js-apis-window.md#snapshot9) or [UIContext.getComponentSnapshot](js-apis-arkui-UIContext.md#getcomponentsnapshot12) will not capture the content of the current component (excluding child windows created under this component).
 

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type    | Mandatory| Description                                           |
| ------ | ------- | --- | ------------------------------------------------ |
| shouldHide | boolean | Yes  | Whether to enable privacy protection for screenshots. The value **true** means to enable privacy protection for screenshots, and **false** means the opposite.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 202      | Permission verification failed. A non-system application calls a system API. |
| 401      | Parameter error. Possible causes: <br> 1. Mandatory parameters are left unspecified. <br> 2. Incorrect parameters types. <br> 3. Parameter verification failed. |
| 1300002  | The UIExtension window proxy is abnormal.                    |

**Example**

```ts
// ExtensionProvider.ts
import { UIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIExtensionAbility {
  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    const extensionHostWindow = session.getUIExtensionHostWindowProxy();
    // Enable privacy protection for screenshots.
    extensionHostWindow.hidePrivacyContentForHost(true).then(() => {
      console.log(`Successfully enabled privacy protection for non-system screenshots.`);
    }).catch((err: BusinessError) => {
      console.log(`Failed enabled privacy protection for non-system screenshots. Cause:${JSON.stringify(err)}`);
    })
  }
}
```

## UIExtensionHostWindowProxyProperties

Defines information about the host application window and **UIExtensionComponent**.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**System API**: This is a system API.

| Name                        | Type       | Mandatory     | Description                            |
| ------------------------------ | ----------- | -------------------------------- | -------------------------------- |
| uiExtensionHostWindowProxyRect | [window.Rect](js-apis-window.md#rect7) | Yes| Position, width, and height of the **UIExtensionComponent**.|

## Example

This example shows how to use all the available APIs in the UIExtensionAbility. The bundle name of the sample application, which requires a system signature, is **com.example.uiextensiondemo**, and the UIExtensionAbility to start is **ExampleUIExtensionAbility**.

- The EntryAbility (UIAbility) of the sample application loads the **pages/Index.ets** file, whose content is as follows:

  ```ts
  // The UIAbility loads pages/Index.ets when started.
  import { Want } from '@kit.AbilityKit';

  @Entry
  @Component
  struct Index {
    @State message: string = 'Message: '
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

- The UIExtensionAbility to start by the **UIExtensionComponent** is implemented in the **ets/extensionAbility/ExampleUIExtensionAbility** file. The file content is as follows:

  ```ts
  import { UIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';

  const TAG: string = '[ExampleUIExtensionAbility]'
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

- The entry page file of the UIExtensionAbility is **pages/extension.ets**, whose content is as follows:

  ```ts
  import { UIExtensionContentSession } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  import { uiExtensionHost, window } from '@kit.ArkUI';

  let storage = LocalStorage.getShared()

  @Entry(storage)
  @Component
  struct Extension {
    @State message: string = 'UIExtensionAbility Index';
    private session: UIExtensionContentSession | undefined = storage.get<UIExtensionContentSession>('session');
    private extensionWindow: uiExtensionHost.UIExtensionHostWindowProxy | undefined = this.session?.getUIExtensionHostWindowProxy();
    private subWindow: window.Window | undefined = undefined;

    aboutToAppear(): void {
      this.extensionWindow?.on('windowSizeChange', (size) => {
          console.info(`size = ${JSON.stringify(size)}`);
      });
      this.extensionWindow?.on('avoidAreaChange', (info) => {
          console.info(`type = ${JSON.stringify(info.type)}, area = ${JSON.stringify(info.area)}`);
      });
      let promise = this.extensionWindow?.hideNonSecureWindows(true);
      promise?.then(()=> {
        console.log(`Succeeded in hiding the non-secure windows.`);
      }).catch((err: BusinessError)=> {
        console.log(`Failed to hide the non-secure windows. Cause:${JSON.stringify(err)}`);
      })
      extensionHostWindow.hidePrivacyContentForHost(true).then(() => {
        console.log(`Successfully enabled privacy protection for non-system screenshots.`);
      }).catch((err: BusinessError) => {
        console.log(`Failed enabled privacy protection for non-system screenshots. Cause:${JSON.stringify(err)}`);
      })
    }

    aboutToDisappear(): void {
      this.extensionWindow?.off('windowSizeChange');
      this.extensionWindow?.off('avoidAreaChange');
      let promise = this.extensionWindow?.hideNonSecureWindows(false);
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
        Button("Obtain Component Size").width('90%').margin({top: 5, bottom: 5}).fontSize(16).onClick(() => {
          let rect = this.extensionWindow?.properties.uiExtensionHostWindowProxyRect;
          console.info(`Width, height, and position of the UIExtensionComponent: ${JSON.stringify(rect)}`);
        })
        Button("Obtain Avoid Area Info").width('90%').margin({top: 5, bottom: 5}).fontSize(16).onClick(() => {
          let avoidArea: window.AvoidArea | undefined = this.extensionWindow?.getWindowAvoidArea(window.AvoidAreaType.TYPE_SYSTEM);
          console.info(`System avoid area: ${JSON.stringify(avoidArea)}`);
        })
        Button("Create Subwindow").width('90%').margin({top: 5, bottom: 5}).fontSize(16).onClick(() => {
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

- Add an item to **extensionAbilities** in the **module.json5** file of the sample application. The details are as follows:
  ```json
  {
    "name": "ExampleUIExtensionAbility",
    "srcEntry": "./ets/extensionAbility/ExampleUIExtensionAbility.ets",
    "type": "sys/commonUI",
  }
  ```
