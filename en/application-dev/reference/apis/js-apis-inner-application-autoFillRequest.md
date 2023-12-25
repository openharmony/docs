# AutoFillRequest

AutoFillRequest provides page data and callbacks when a callback is triggered for the AutoFillExtensionAbility.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import autoFillManager from '@ohos.app.ability.autoFillManager';
```

## FillRequest

Defines the information about an auto-fill request.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

| Name       | Type                | Mandatory| Description                                                        |
| ----------- | -------------------- | ---- | ------------------------------------------------------------ |
| type        | [AutoFillType](js-apis-inner-application-autoFillType.md)       | Yes  | Type of the element to be automatically filled in.         |
| viewData    | [ViewData](js-apis-inner-application-viewData.md)               | Yes  | Page data.             |

## SaveRequest

Defines the information about an auto-saving request.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

| Name       | Type                | Mandatory| Description                                                        |
| ----------- | -------------------- | ---- | ------------------------------------------------------------ |
| viewData    | [ViewData](js-apis-inner-application-viewData.md)               | Yes  | Page data.             |

## FillResponse

Defines the information about the response to an auto-fill request.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

| Name       | Type                | Mandatory| Description                                                        |
| ----------- | -------------------- | ---- | ------------------------------------------------------------ |
| viewData    | [ViewData](js-apis-inner-application-viewData.md)               | Yes  | Page data.             |

## FillRequestCallback

Implements callbacks for an auto-fill request, which is used to automatically fill in or generate a password. The callbacks can be used to notify the client of the success or failure of the request.

### FillRequestCallback.onSuccess

onSuccess(response: FillResponse): void

Called when an auto-fill request is successfully processed.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | ------------------------------ |
| response | [FillResponse](#fillresponse)  | Yes| Information about the response to the auto-fill response.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000050 | Internal error. |

**Example**

  ```ts
  // MyAutoFillExtensionAbility.ts
  import AutoFillExtensionAbility from '@ohos.app.ability.AutoFillExtensionAbility';
  import UIExtensionContentSession from '@ohos.app.ability.UIExtensionContentSession';
  import autoFillManager from '@ohos.app.ability.autoFillManager';
  import hilog from '@ohos.hilog';
  
  class MyAutoFillExtensionAbility extends AutoFillExtensionAbility {
    onFillRequest(session: UIExtensionContentSession,
                  request: autoFillManager.FillRequest,
                  callback: autoFillManager.FillRequestCallback) {
      hilog.info(0x0000, 'testTag', '%{public}s', 'autofill onFillRequest');
      hilog.info(0x0000, 'testTag', 'fill requestCallback: %{public}s', JSON.stringify(callback));
      hilog.info(0x0000, 'testTag', "get request viewData: ", JSON.stringify(request.viewData));
      try {
        let storage_fill = new LocalStorage(
          {
            'session': session,
            'message': "AutoFill Page",
            'fillCallback': callback,
            'viewData': request.viewData,
            'context': this.context,
          });
        if (session) {
          session.loadContent('pages/SelectorList', storage_fill);
        } else {
          hilog.error(0x0000, 'testTag', '%{public}s', 'session is null');
        }
      } catch (err) {
        hilog.error(0x0000, 'testTag', '%{public}s', 'failed to load content');
      }
    }
  }
  ```

  ```ts
  // SelectorList.ets
  import autoFillManager from '@ohos.app.ability.autoFillManager';
  import Base from '@ohos.base';
  import hilog from '@ohos.hilog';
  
  @Entry
  @Component
  struct SelectorList {
    private fillCallback: autoFillManager.FillRequestCallback = storage.get<FillRequestCallback>('fillCallback');
    private viewData: autoFillManager.ViewData = storage.get<ViewData>('viewData');
  
    build() {
      Row() {
        Column() {
          Text('Hello World')
            .fontSize(50)
            .fontWeight(FontWeight.Bold)
        }
  
        Button('onSuccess')
          .onClick(() => {
            this.viewData.pageNodeInfos[0].value = "user1";
            this.viewData.pageNodeInfos[1].value = "user1 password";
            this.viewData.pageNodeInfos[2].value = "user1 new password";
            hilog.info(0x0000, 'testTag', 'autofill success with viewData: %{public}s', JSON.stringify(this.viewData));
            try {
              this.fillCallback.onSuccess({ viewData: this.viewData });
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

### FillRequestCallback.onFailure

onFailure(): void

Called when an auto-fill request fails to be processed.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000050 | Internal error. |

**Example**

  ```ts
  // MyAutoFillExtensionAbility.ts
  import AutoFillExtensionAbility from '@ohos.app.ability.AutoFillExtensionAbility';
  import UIExtensionContentSession from '@ohos.app.ability.UIExtensionContentSession';
  import autoFillManager from '@ohos.app.ability.autoFillManager';
  import hilog from '@ohos.hilog';

  class MyAutoFillExtensionAbility extends AutoFillExtensionAbility {
    onFillRequest(session : UIExtensionContentSession,
                  request : autoFillManager.FillRequest,
                  callback : autoFillManager.FillRequestCallback) {
      hilog.info(0x0000, 'testTag', '%{public}s', 'autofill onFillRequest');
      hilog.info(0x0000, 'testTag', 'fill requestCallback: %{public}s', JSON.stringify(callback));
      hilog.info(0x0000, 'testTag', "get request viewData: ", JSON.stringify(request.viewData));
      try {
        let storage_fill = new LocalStorage(
          {
            'session': session,
            'message': "AutoFill Page",
            'fillCallback': callback,
            'viewData': request.viewData,
            'context': this.context,
          });
        if (session) {
          session.loadContent('pages/SelectorList', storage_fill);
        } else {
          hilog.error(0x0000, 'testTag', '%{public}s', 'session is null');
        }
      } catch (err) {
        hilog.error(0x0000, 'testTag', '%{public}s', 'failed to load content');
      }
    }
  }
  ```

  ```ts
  // SelectorList.ets
  import autoFillManager from '@ohos.app.ability.autoFillManager';
  import Base from '@ohos.base';
  import hilog from '@ohos.hilog';

  @Entry
  @Component
  struct SelectorList {
    private fillCallback: autoFillManager.FillRequestCallback = storage.get<FillRequestCallback>('fillCallback');

    build() {
      Row() {
        Column() {
          Text('Hello World')
            .fontSize(50)
            .fontWeight(FontWeight.Bold)
        }
        Button('onFailure')
          .onClick(() => {
            hilog.info(0x0000, 'testTag', 'autofill failure');
            try {
              this.fillCallback.onFailure();
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

### FillRequestCallback.onCancel

onCancel(): void

Called when an auto-fill request is canceled.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000050 | Internal error. |

**Example**

  ```ts
  // MyAutoFillExtensionAbility.ts
  import AutoFillExtensionAbility from '@ohos.app.ability.AutoFillExtensionAbility';
  import UIExtensionContentSession from '@ohos.app.ability.UIExtensionContentSession';
  import autoFillManager from '@ohos.app.ability.autoFillManager';
  import hilog from '@ohos.hilog';
  
  class MyAutoFillExtensionAbility extends AutoFillExtensionAbility {
    onFillRequest(session: UIExtensionContentSession,
                  request: autoFillManager.FillRequest,
                  callback: autoFillManager.FillRequestCallback) {
      hilog.info(0x0000, 'testTag', '%{public}s', 'autofill onFillRequest');
      hilog.info(0x0000, 'testTag', 'fill requestCallback: %{public}s', JSON.stringify(callback));
      hilog.info(0x0000, 'testTag', "get request viewData: ", JSON.stringify(request.viewData));
      try {
        let storage_fill = new LocalStorage(
          {
            'session': session,
            'message': "AutoFill Page",
            'fillCallback': callback,
            'viewData': request.viewData,
            'context': this.context,
          });
        if (session) {
          session.loadContent('pages/SelectorList', storage_fill);
        } else {
          hilog.error(0x0000, 'testTag', '%{public}s', 'session is null');
        }
      } catch (err) {
        hilog.error(0x0000, 'testTag', '%{public}s', 'failed to load content');
      }
    }
  }
  ```

  ```ts
  // SelectorList.ets
  import autoFillManager from '@ohos.app.ability.autoFillManager';
  import Base from '@ohos.base';
  import hilog from '@ohos.hilog';
  
  @Entry
  @Component
  struct SelectorList {
    private fillCallback: autoFillManager.FillRequestCallback = storage.get<FillRequestCallback>('fillCallback');
  
    build() {
      Row() {
        Column() {
          Text('Hello World')
            .fontSize(50)
            .fontWeight(FontWeight.Bold)
        }
  
        Button('onCancel')
          .onClick(() => {
            hilog.info(0x0000, 'testTag', 'autofill cancel');
            try {
              this.fillCallback.onCancel();
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

## SaveRequestCallback

Implements callbacks for an automatic or a manual saving request.

### SaveRequestCallback.onSuccess

onSuccess(): void

Called when a saving request is successfully processed.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000050 | Internal error. |

**Example**

  ```ts
  // MyAutoFillExtensionAbility.ts
  import AutoFillExtensionAbility from '@ohos.app.ability.AutoFillExtensionAbility';
  import UIExtensionContentSession from '@ohos.app.ability.UIExtensionContentSession';
  import autoFillManager from '@ohos.app.ability.autoFillManager';
  import hilog from '@ohos.hilog';

  class MyAutoFillExtensionAbility extends AutoFillExtensionAbility {
    onSaveRequest(session: UIExtensionContentSession,
                  request: autoFillManager.SaveRequest,
                  callback: autoFillManager.SaveRequestCallback) {
      hilog.info(0x0000, 'testTag', '%{public}s', 'onSaveRequest');
      try {
        let storage_save = new LocalStorage(
          {
            'session': session,
            'message': "AutoFill Page",
            'callback': callback,
            'viewData': request.viewData
          });
        if (session) {
          session.loadContent('pages/SavePage', storage_save);
        } else {
          hilog.error(0x0000, 'testTag', '%{public}s', 'session is null');
        }
      } catch (err) {
        hilog.error(0x0000, 'testTag', '%{public}s', 'failed to load content');
      }
    }
  }
  ```

  ```ts
  // SelectorList.ets
  import autoFillManager from '@ohos.app.ability.autoFillManager';
  import Base from '@ohos.base';
  import hilog from '@ohos.hilog';
  
  @Entry
  @Component
  struct SelectorList {
    private saveCallback: autoFillManager.SaveRequestCallback = storage.get<SaveRequestCallback>('saveCallback');
  
    build() {
      Row() {
        Column() {
          Text('Hello World')
            .fontSize(50)
            .fontWeight(FontWeight.Bold)
        }
  
        Button('onSuccess')
          .onClick(() => {
            hilog.info(0x0000, 'testTag', 'autofill success');
            try {
              this.saveCallback.onSuccess();
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

### SaveRequestCallback.onFailure

onFailure(): void

Called when a saving request fails to be processed.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000050 | Internal error. |

**Example**

  ```ts
  // MyAutoFillExtensionAbility.ts
  import AutoFillExtensionAbility from '@ohos.app.ability.AutoFillExtensionAbility';
  import UIExtensionContentSession from '@ohos.app.ability.UIExtensionContentSession';
  import autoFillManager from '@ohos.app.ability.autoFillManager';
  import hilog from '@ohos.hilog';
  
  class MyAutoFillExtensionAbility extends AutoFillExtensionAbility {
    onSaveRequest(session: UIExtensionContentSession,
                  request: autoFillManager.SaveRequest,
                  callback: autoFillManager.SaveRequestCallback) {
      hilog.info(0x0000, 'testTag', '%{public}s', 'onSaveRequest');
      try {
        let storage_save = new LocalStorage(
          {
            'session': session,
            'message': "AutoFill Page",
            'callback': callback,
            'viewData': request.viewData
          });
        if (session) {
          session.loadContent('pages/SavePage', storage_save);
        } else {
          hilog.error(0x0000, 'testTag', '%{public}s', 'session is null');
        }
      } catch (err) {
        hilog.error(0x0000, 'testTag', '%{public}s', 'failed to load content');
      }
    }
  }
  ```

  ```ts
  // SelectorList.ets
  import autoFillManager from '@ohos.app.ability.autoFillManager';
  import Base from '@ohos.base';
  import hilog from '@ohos.hilog';
  
  @Entry
  @Component
  struct SelectorList {
    private saveCallback: autoFillManager.SaveRequestCallback = storage.get<SaveRequestCallback>('saveCallback');
  
    build() {
      Row() {
        Column() {
          Text('Hello World')
            .fontSize(50)
            .fontWeight(FontWeight.Bold)
        }
  
        Button('onFailure') {
          // ...
        }.onClick(() => {
          hilog.info(0x0000, 'testTag', 'autofill failure');
          try {
            this.saveCallback.onFailure();
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
