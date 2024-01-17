# @ohos.app.ability.autoFillManager (autoFillManager)

The autoFillManager module provides APIs for manually saving accounts and passwords.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import autoFillManager from '@ohos.app.ability.autoFillManager';
```

## AutoSaveCallback

Implements callbacks triggered when manual saving is complete.

### AutoSaveCallback.onSuccess

onSuccess(): void

Called when manual saving is successful.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Example**

See [AutoSaveCallback.onFailure](#autosavecallbackonfailure).

### AutoSaveCallback.onFailure

onFailure(): void

Called when manual saving fails.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Example**

  ```ts
  // Custom page displayed for auto saving.
  import autoFillManager from '@ohos.app.ability.autoFillManager';

  @Entry
  @Component
  struct SavePage {
    private storage = LocalStorage.getShared();
    private callback = this.storage.get<autoFillManager.AutoSaveCallback>('callback')
    @State message: string = 'Save Account?'

    build() {
      Row() {
        Column() {
          Text(this.message)
            .fontSize(35)
            .fontWeight(FontWeight.Bold)
          Row() {
            Button("OK")
              .type(ButtonType.Capsule)
              .fontSize(20)
              .margin({ top:30 ,right: 30})
              .onClick(()=>{
                // In this example, the onFailure callback is triggered manually and the saving operation is canceled. Write the code based on your service logic.
                this.callback.onSuccess();
              })
            Button("No")
              .type(ButtonType.Capsule)
              .fontSize(20)
              .margin({ top:30 ,left:30})
              .onClick(()=>{
                // In this example, the onFailure callback is triggered manually and the saving operation is canceled. Write the code based on your service logic.
                this.callback.onFailure();
              })
          }
        }
        .width('100%')
      }
      .height('100%')
    }
  }
  ```

> **NOTE**
>
> In the example, the AutoSaveCallback obtained from the Local Storage is obtained from the OnSaveRequest lifecycle in the AutoFillAbility (customized AutoFillExtensionAbility) and stored in the Local Storage. For details, see [SaveRequestCallback](js-apis-inner-application-autoFillRequest.md#saverequestcallbackonsuccess).

## requestAutoSave

requestAutoSave(context: UIContext, callback?: AutoSaveCallback): void

Triggers a manual saving request. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| context | [UIContext](js-apis-arkui-UIContext.md) | Yes| UI context in which the saving operation will be performed.|
| callback | [AutoSaveCallback](#autosavecallback)  | No| Callback used for the manual saving request.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000050 | Internal error. |

**Example**

  ```ts
  // EntryAbility.ts
  import UIAbility from '@ohos.app.ability.UIAbility';
  import hilog from '@ohos.hilog';
  import window from '@ohos.window';
  import { BusinessError } from '@ohos.base';
  import { UIContext } from '@ohos.arkui.UIContext';
  import common from '@ohos.app.ability.common';
  
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
  import autoFillManager from '@ohos.app.ability.autoFillManager';
  import { UIContext } from '@ohos.arkui.UIContext';
  import Base from '@ohos.base';
  
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
              // Pass in the UIContext and onSuccess and onFailure callbacks to trigger a manual saving request.
              autoFillManager.requestAutoSave(uiContext, {
                onSuccess: () => {
                  console.log("save request on success");
                },
                onFailure: () => {
                  console.log("save request on failure");
                }
              });
            } catch (error) {
              console.error(`catch error, code: ${(error as Base.BusinessError).code}, message: ${(error as Base.BusinessError).message}`);
            }
          })
          .width('100%')
      }
      .height('100%')
    }
  }
  ```
