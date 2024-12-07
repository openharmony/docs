# @ohos.arkui.uiExtension (uiExtension)

The **uiExtension** module provides APIs for the EmbeddedUIExtensionAbility (or UIExtensionAbility) to obtain the host application window information or the information about the corresponding **EmbeddedComponent**<!--Del--> (or **UIExtensionComponent**)<!--DelEnd--> component.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Updates will be marked with a superscript to indicate their earliest API version.
>

## Modules to Import

```
import { uiExtension } from '@kit.ArkUI'
```

## WindowProxy

### getWindowAvoidArea

getWindowAvoidArea(type: window.AvoidAreaType): window.AvoidArea

Obtains the area where this window cannot be displayed, for example, the system bar area, notch, gesture area, and soft keyboard area.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type |[window.AvoidAreaType](./js-apis-window.md#avoidareatype7) | Yes| Type of the area.|

**Return value**

| Type| Description|
| -------- | -------- |
|[window.AvoidArea](./js-apis-window.md#avoidarea7) | Area where the window cannot be displayed.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |

**Example**

```ts
// ExtensionProvider.ts
import { EmbeddedUIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends EmbeddedUIExtensionAbility {
  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    const extensionWindow = session.getUIExtensionWindowProxy();
    // Obtain the information about the area where the window cannot be displayed.
    let avoidArea: window.AvoidArea | undefined = extensionWindow?.getWindowAvoidArea(window.AvoidAreaType.TYPE_SYSTEM);
    console.info(`avoidArea: ${JSON.stringify(avoidArea)}`);
  }
}
```

### on('avoidAreaChange')

on(type: 'avoidAreaChange', callback: Callback&lt;AvoidAreaInfo&gt;): void

Subscribes to the event indicating changes to the area where the window cannot be displayed.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Mandatory| Description|
| ------ | ---- | ---- | ---- |
| type   | string | Yes| Event type. The value is fixed at **'avoidAreaChange'**, indicating the event of changes to the area where the window cannot be displayed.|
| callback | [Callback](../apis-basic-services-kit/js-apis-base.md#callback)<[AvoidAreaInfo](#avoidareainfo)> | Yes| Callback used to return the area information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |

**Example**

```ts
// ExtensionProvider.ts
import { EmbeddedUIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';
import { uiExtension } from '@kit.ArkUI';

export default class EntryAbility extends EmbeddedUIExtensionAbility {
  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    const extensionWindow = session.getUIExtensionWindowProxy();
    // Subscribe to the event indicating changes to the area where the window cannot be displayed.
    extensionWindow.on('avoidAreaChange', (info: uiExtension.AvoidAreaInfo) => {
      console.info(`The avoid area of the host window is: ${JSON.stringify(info.area)}.`);
    });
  }
}
```

### off('avoidAreaChange')

off(type: 'avoidAreaChange', callback?: Callback&lt;AvoidAreaInfo&gt;): void

Unsubscribes from the event indicating changes to the area where the window cannot be displayed.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name  | Type| Mandatory| Description|
| -------- | ---- | ---- | ---  |
| type     | string | Yes| Event type. The value is fixed at **'avoidAreaChange'**, indicating the event of changes to the area where the window cannot be displayed.|
| callback | [Callback](../apis-basic-services-kit/js-apis-base.md#callback)<[AvoidAreaInfo](#avoidareainfo)> | No| Callback used for unsubscription. If a value is passed in, the corresponding subscription is canceled. If no value is passed in, all subscriptions to the specified event are canceled.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed. |

**Example**

```ts
// ExtensionProvider.ts
import { EmbeddedUIExtensionAbility, UIExtensionContentSession } from '@kit.AbilityKit';

export default class EntryAbility extends EmbeddedUIExtensionAbility {
  onSessionDestroy(session: UIExtensionContentSession) {
    const extensionWindow = session.getUIExtensionWindowProxy();
    // Cancel all subscriptions to the event indicating changes to the area where the window cannot be displayed.
    extensionWindow.off('avoidAreaChange');
  }
}
```

### on('windowSizeChange')

on(type: 'windowSizeChange', callback: Callback<window.Size>): void

Subscribes to the window size change event of the host application.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name  | Type                 | Mandatory| Description                  |
| -------- | --------------------- | ---- | ---------------------- |
| type     | string                | Yes  | Event type. The value is fixed at **'windowSizeChange'**, indicating the window size change event.|
| callback | [Callback](../apis-basic-services-kit/js-apis-base.md#callback)<[window.Size](js-apis-window.md#size7)> | Yes  | Callback used to return the window size.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |

**Example**

```ts
// ExtensionProvider.ts
import { EmbeddedUIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends EmbeddedUIExtensionAbility {
  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    const extensionWindow = session.getUIExtensionWindowProxy();
    // Subscribe to the window size change event of the host application.
    extensionWindow.on('windowSizeChange', (size: window.Size) => {
      console.info(`The avoid area of the host window is: ${JSON.stringify(size)}.`);
    });
  }
}
```

### off('windowSizeChange')

off(type: 'windowSizeChange', callback?: Callback<window.Size>): void

Unsubscribes from the window size change event of the host application.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name  | Type                 | Mandatory| Description                  |
| -------- | --------------------- | ---- | ---------------------- |
| type     | string                | Yes  | Event type. The value is fixed at **'windowSizeChange'**, indicating the window size change event.|
| callback | [Callback](../apis-basic-services-kit/js-apis-base.md#callback)<[window.Size](js-apis-window.md#size7)> | No  | Callback used for unsubscription. If a value is passed in, the corresponding subscription is canceled. If no value is passed in, all subscriptions to the specified event are canceled.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |

**Example**

```ts
// ExtensionProvider.ts
import { EmbeddedUIExtensionAbility, UIExtensionContentSession } from '@kit.AbilityKit';

export default class EntryAbility extends EmbeddedUIExtensionAbility {
  onSessionDestroy(session: UIExtensionContentSession) {
    const extensionWindow = session.getUIExtensionWindowProxy();
    // Unsubscribe from the window size change event of the host application.
    extensionWindow.off('windowSizeChange');
  }
}
```

### createSubWindowWithOptions

createSubWindowWithOptions(name: string, subWindowOptions: window.SubWindowOptions): Promise&lt;window.Window&gt;

Creates a subwindow for this window proxy. This API uses a promise to return the result.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Atomic service API**: This API can be used in atomic services since API version 12.

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type  | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| name   | string | Yes  | Name of the subwindow.|
| subWindowOptions | [window.SubWindowOptions](js-apis-window.md#subwindowoptions11) | Yes  | Parameters used for creating the subwindow. |

**Return value**

| Type                            | Description                                            |
| -------------------------------- | ------------------------------------------------ |
| Promise&lt;[window.Window](js-apis-window.md#window)&gt; | Promise used to return the subwindow created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md). and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 801 | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300005 | This window proxy is abnormal. |

**Example:**

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
    // Create a subwindow.
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

Describes the information about the area where the window cannot be displayed.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type                | Mandatory| Description       |
| ------ | -------------------- | ------------------ | ------------------ |
| type   | [window.AvoidAreaType](js-apis-window.md#avoidareatype7) | Yes| Type of the area where the window cannot be displayed.  |
| area   | [window.AvoidArea](js-apis-window.md#avoidarea7)     | Yes| Area where the window cannot be displayed.|

## Example

This example shows how to use all the available APIs in the EmbeddedUIExtensionAbility. The bundle name of the sample application is **com.example.embeddeddemo**, and the EmbeddedUIExtensionAbility to start is **ExampleEmbeddedAbility**.

- The EntryAbility (UIAbility) of the sample application loads the **pages/Index.ets** file, whose content is as follows:

  ```ts
  // The UIAbility loads pages/Index.ets when started.
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

- The EmbeddedUIExtensionAbility to start by the **EmbeddedComponent** is implemented in the **ets/extensionAbility/ExampleEmbeddedAbility** file. The file content is as follows:

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

- The entry page file of the EmbeddedUIExtensionAbility is **pages/extension.ets**, whose content is as follows:

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
      this.extensionWindow?.on('avoidAreaChange', (info: uiExtension.AvoidAreaInfo) => {
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
    "name": "ExampleEmbeddedAbility",
    "srcEntry": "./ets/extensionAbility/ExampleEmbeddedAbility.ets",
    "type": "embeddedUI"
  }
  ```
