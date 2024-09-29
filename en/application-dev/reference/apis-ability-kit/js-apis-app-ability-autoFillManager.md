# @ohos.app.ability.autoFillManager (autoFillManager)

The autoFillManager module provides APIs for saving accounts and passwords.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { AutoFillExtensionAbility } from '@kit.AbilityKit';
```

## AutoSaveCallback

Implements callbacks triggered when auto-save is complete.

### AutoSaveCallback.onSuccess

onSuccess(): void

Called when auto-save is successful.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Example**

See [AutoSaveCallback.onFailure](#autosavecallbackonfailure).

### AutoSaveCallback.onFailure

onFailure(): void

Called when auto-save fails.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Example**

  ```ts
// Index.ets, a page containing components such as the account and password text boxes.
import { autoFillManager } from '@kit.AbilityKit';
import { UIContext } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

let uiContext = AppStorage.get<UIContext>("uiContext");
let callback: autoFillManager.AutoSaveCallback = {
  onSuccess: () => {
    console.log("save request on success");
  },
  onFailure: () => {
    console.log("save request on failure");
  }
};

@Entry
@Component
struct Index {
  build() {
    Button('requestAutoSave')
      .onClick(() => {
        try {
          // Initiate an auto-save request.
          autoFillManager.requestAutoSave(uiContext, callback);
        } catch (error) {
          console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
        }
      })
  }
}
  ```

> **NOTE**
>
> In the example, the UiContext obtained from the AppStorage is obtained from the **OnWindowStageCreate** lifecycle of the EntryAbility (ability that starts the page) and stored in the AppStorage. For details, see [requestAutoSave](#requestautosave).

## requestAutoSave

requestAutoSave(context: UIContext, callback?: AutoSaveCallback): void

Requests to automatically save the widget data. This API uses an asynchronous callback to return the result.

If the current widget does not support widget switching, you can call this API to save historical widget input data. The callback is triggered when the auto-save request is complete.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| context | [UIContext](../apis-arkui/js-apis-arkui-UIContext.md) | Yes| UI context in which the auto-save operation will be performed.|
| callback | [AutoSaveCallback](#autosavecallback)  | No| Callback used for the auto-save request.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 401      | The parameter check failed. Possible causes: 1. Get instance id failed; 2. Parse instance id failed; 3. The second parameter is not of type callback. |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](errorcode-ability.md).

**Example**

  ```ts
// EntryAbility.ets
import { UIAbility, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window, UIContext } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage): void {
    // Main window is created. Set a main page for this ability.
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageCreate');
    let localStorageData: Record<string, string | common.UIAbilityContext> = {
      'message': "AutoFill Page",
      'context': this.context,
    };
    let storage = new LocalStorage(localStorageData);
    windowStage.loadContent('pages/Index', storage, (err, data) => {
      if (err.code) {
        hilog.error(0x0000, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err) ?? '');
        return;
      }
      // Obtain the main window.
      windowStage.getMainWindow((err: BusinessError, data: window.Window) => {
        let errCode: number = err.code;
        if (errCode) {
          console.error('Failed to obtain the main window. Cause: ' + JSON.stringify(err));
          return;
        }
        console.info('Succeeded in obtaining the main window. Data: ' + JSON.stringify(data));
        // get UIContext instance.
        let uiContext: UIContext = windowStage.getMainWindowSync().getUIContext();
        PersistentStorage.persistProp("uiContext", uiContext);
      })
      hilog.info(0x0000, 'testTag', 'Succeeded in loading the content. Data: %{public}s', JSON.stringify(data) ?? '');
    });
  }
}
  ```

  ```ts
  // Index.ets
import { autoFillManager } from '@kit.AbilityKit';
import { UIContext } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Text('Hello World')
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }

      Button('requestAutoSave')
        .onClick(() => {
          let uiContext = AppStorage.get<UIContext>("uiContext");
          console.log("uiContext: ", JSON.stringify(uiContext));
          try {
            // Initiate an auto-save request.
            autoFillManager.requestAutoSave(uiContext, {
              onSuccess: () => {
                console.log("save request on success");
              },
              onFailure: () => {
                console.log("save request on failure");
              }
            });
          } catch (error) {
            console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
          }
        })
        .width('100%')
    }
    .height('100%')
  }
}
  ```
