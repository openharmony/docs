# AutoFillRequest (System API)

AutoFillRequest provides page data and callbacks when a callback is triggered for the AutoFillExtensionAbility.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs provided by this module are system APIs.
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { autoFillManager } from '@kit.AbilityKit';
```

## FillRequest

Defines the information about an auto-fill request.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

| Name       | Type                | Mandatory| Description                                                        |
| ----------- | -------------------- | ---- | ------------------------------------------------------------ |
| type        | [AutoFillType](js-apis-inner-application-autoFillType-sys.md)       | Yes  | Type of the element to be automatically filled in.         |
| viewData    | [ViewData](js-apis-inner-application-viewData-sys.md)               | Yes  | Page data.             |
| customData<sup>13+</sup>    | [CustomData](js-apis-inner-application-customData-sys.md)               | Yes  | Custom data.            |
| isPopup<sup>12+</sup>    | boolean               | Yes  | Whether a dialog box is displayed for the auto-fill request.<br>**true**: A dialog box is displayed<br>**false**: A modal window is displayed             |

## SaveRequest

Defines the information about an auto-saving request.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

| Name       | Type                | Mandatory| Description                                                        |
| ----------- | -------------------- | ---- | ------------------------------------------------------------ |
| viewData    | [ViewData](js-apis-inner-application-viewData-sys.md)               | Yes  | Page data.             |

## UpdateRequest<sup>12+</sup>

Defines the information about an auto-update request.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

| Name       | Type                | Mandatory| Description                                                        |
| ----------- | -------------------- | ---- | ------------------------------------------------------------ |
| viewData    | [ViewData](js-apis-inner-application-viewData-sys.md)               | Yes  | Page data.             |

## FillResponse

Defines the information about the response to an auto-fill request.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

| Name       | Type                | Mandatory| Description                                                        |
| ----------- | -------------------- | ---- | ------------------------------------------------------------ |
| viewData    | [ViewData](js-apis-inner-application-viewData-sys.md)               | Yes  | Page data.             |

## FillRequestCallback

Implements callbacks for an auto-fill request, which is used to automatically fill in or generate a password. The callbacks can be used to notify the client of the success or failure of the request.

### FillRequestCallback.onSuccess

onSuccess(response: FillResponse): void

Called when an auto-fill request is successfully processed.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | ------------------------------ |
| response | [FillResponse](#fillresponse)  | Yes| Information about the response to the auto-fill request.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 202  | Permission denied, non-system app called system api. |
| 401  | Mandatory parameters are left unspecified. |
| 16000050 | Internal error. |

**Example**

```ts
// MyAutoFillExtensionAbility.ts
import { AutoFillExtensionAbility, UIExtensionContentSession, autoFillManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

class MyAutoFillExtensionAbility extends AutoFillExtensionAbility {
  onFillRequest(session: UIExtensionContentSession,
                request: autoFillManager.FillRequest,
                callback: autoFillManager.FillRequestCallback) {
    hilog.info(0x0000, 'testTag', '%{public}s', 'autofill onFillRequest');
    try {
      let storageData: Record<string, string | autoFillManager.FillRequestCallback | autoFillManager.ViewData> = {
        'fillCallback': callback,
        'message': 'AutoFill Page',
        'viewData': request.viewData,
      }
      let storage_fill = new LocalStorage(storageData);
      if (session) {
        session.loadContent('pages/AutoFillPage', storage_fill);
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
// AutoFillPage.ets
import { autoFillManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

@Entry
@Component
struct AutoFillPage {
  storage: LocalStorage | undefined = this.getUIContext().getSharedLocalStorage();
  fillCallback: autoFillManager.FillRequestCallback | undefined =
    this.storage?.get<autoFillManager.FillRequestCallback>('fillCallback');
  viewData: autoFillManager.ViewData | undefined = this.storage?.get<autoFillManager.ViewData>('viewData');

  build() {
    Row() {
      Column() {
        Text('AutoFill Page')
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }

      Button('onSuccess')
        .onClick(() => {
          if (this.viewData) {
            this.viewData.pageNodeInfos[0].value = 'user1';
            this.viewData.pageNodeInfos[1].value = 'user1 password';
            this.viewData.pageNodeInfos[2].value = 'user1 generate new password';
            hilog.info(0x0000, 'testTag', 'autofill success with viewData: %{public}s', JSON.stringify(this.viewData));
            try {
              this.fillCallback?.onSuccess({ viewData: this.viewData });
            } catch (error) {
              console.error(`catch error, code: ${(error as BusinessError).code},
                  message: ${(error as BusinessError).message}`);
            }
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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 202 | Permission denied, non-system app called system api. |
| 16000050 | Internal error. |

**Example**

```ts
// MyAutoFillExtensionAbility.ts
import { AutoFillExtensionAbility, UIExtensionContentSession, autoFillManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

class MyAutoFillExtensionAbility extends AutoFillExtensionAbility {
  onFillRequest(session: UIExtensionContentSession,
                request: autoFillManager.FillRequest,
                callback: autoFillManager.FillRequestCallback) {
    hilog.info(0x0000, 'testTag', '%{public}s', 'autofill onFillRequest');
    try {
      let storageData: Record<string, string | autoFillManager.FillRequestCallback | autoFillManager.ViewData> = {
        'fillCallback': callback,
        'message': 'AutoFill Page',
        'viewData': request.viewData,
      }
      let storage_fill = new LocalStorage(storageData);
      if (session) {
        session.loadContent('pages/AutoFill Page', storage_fill);
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
// AutoFillPage.ets
import { autoFillManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

@Entry
@Component
struct AutoFillPage {
  storage: LocalStorage | undefined = this.getUIContext().getSharedLocalStorage();
  fillCallback: autoFillManager.FillRequestCallback | undefined =
    this.storage?.get<autoFillManager.FillRequestCallback>('fillCallback');
  
  build() {
    Row() {
      Column() {
        Text('AutoFill Page')
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }

      Button('onFailure')
        .onClick(() => {
          hilog.info(0x0000, 'testTag', 'autofill failure');
          try {
            this.fillCallback?.onFailure();
          } catch (error) {
            console.error(`catch error, code: ${(error as BusinessError).code},
              message: ${(error as BusinessError).message}`);
          }
        })
        .width('100%')
    }
    .height('100%')
  }
}
```

### FillRequestCallback.onCancel<sup>11+</sup>

onCancel(fillContent?: string): void

Called when an auto-fill request is canceled.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name                   | Type  | Mandatory| Description                |
| ------------------------- | ------ | ---- | -------------------- |
| fillContent | string | No  | Content returned to the input method framework when the auto-fill request is canceled.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 202  | Permission denied, non-system app called system api. |
| 401  | Parameter error. Possible causes: 1. The input parameter is not valid parameter;2. Mandatory parameters are left unspecified. |
| 16000050 | Internal error. |

**Example**

```ts
// MyAutoFillExtensionAbility.ts
import { AutoFillExtensionAbility, UIExtensionContentSession, autoFillManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

class MyAutoFillExtensionAbility extends AutoFillExtensionAbility {
  onFillRequest(session: UIExtensionContentSession,
                request: autoFillManager.FillRequest,
                callback: autoFillManager.FillRequestCallback) {
    hilog.info(0x0000, 'testTag', '%{public}s', 'autofill onFillRequest');
    try {
      let storageData: Record<string, string | autoFillManager.FillRequestCallback | autoFillManager.ViewData> = {
        'fillCallback': callback,
        'message': 'AutoFill Page',
        'viewData': request.viewData,
      }
      let storage_fill = new LocalStorage(storageData);
      if (session) {
        session.loadContent('pages/AutoFillPage', storage_fill);
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
// AutoFillPage.ets
import { autoFillManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

@Entry
@Component
struct AutoFillPage {
  storage: LocalStorage | undefined = this.getUIContext().getSharedLocalStorage();
  fillCallback: autoFillManager.FillRequestCallback | undefined =
    this.storage?.get<autoFillManager.FillRequestCallback>('fillCallback');
  
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
            this.fillCallback?.onCancel();
          } catch (error) {
            console.error(`catch error, code: ${(error as BusinessError).code},
                message: ${(error as BusinessError).message}`);
          }
        })
        .width('100%')
    }
    .height('100%')
  }
}
```

### FillRequestCallback.setAutoFillPopupConfig<sup>12+</sup>

setAutoFillPopupConfig(autoFillPopupConfig: AutoFillPopupConfig ): void

Sets the size and position of an auto-fill pop-up.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | ------------------------------ |
| autoFillPopupConfig | [AutoFillPopupConfig](js-apis-inner-application-autoFillPopupConfig-sys.md) | Yes| Size and position of the auto-fill pop-up.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 202  | Permission denied, non-system app called system api. |
| 401  | Mandatory parameters are left unspecified. |
| 16000050 | Internal error. |

**Example**

```ts
// MyAutoFillExtensionAbility.ts
// MyAutoFillExtensionAbility.ts
import { AutoFillExtensionAbility, UIExtensionContentSession, autoFillManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

export default class AutoFillAbility extends AutoFillExtensionAbility {
  storage: LocalStorage = new LocalStorage();

  onCreate(): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'autofill onCreate');
  }

  onDestroy(): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'autofill onDestroy');
  }

  onSessionDestroy(session: UIExtensionContentSession) {
    hilog.info(0x0000, 'testTag', '%{public}s', 'autofill onSessionDestroy');
    hilog.info(0x0000, 'testTag', 'session content: %{public}s', JSON.stringify(session));
  }

  onForeground(): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'autofill onForeground');
  }

  onBackground(): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'autofill onBackground');
  }

  onUpdateRequest(request: autoFillManager.UpdateRequest): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'autofill onUpdateRequest');
    console.log(`get fill request viewData: ${JSON.stringify(request.viewData)}.`);
    let fillCallback = this.storage.get<autoFillManager.FillRequestCallback>('fillCallback');

    if (fillCallback) {
      try {
        hilog.info(0x0000, 'testTag', 'pageNodeInfos.value: ' + JSON.stringify(request.viewData.pageNodeInfos[0].value));
        fillCallback.setAutoFillPopupConfig({
          popupSize: {
            width: 400 + request.viewData.pageNodeInfos[0].value.length * 10,
            height: 200 + request.viewData.pageNodeInfos[0].value.length * 10
          },
          placement: autoFillManager.PopupPlacement.TOP
        });
      } catch (err) {
        hilog.info(0x0000, 'testTag', 'autoFillPopupConfig err: ' + err.code);
      }
    }
  }

  onFillRequest(session: UIExtensionContentSession, request: autoFillManager.FillRequest, callback: autoFillManager.FillRequestCallback) {
    hilog.info(0x0000, 'testTag', '%{public}s', 'autofill onFillRequest');
    hilog.info(0x0000, 'testTag', 'Fill RequestCallback: %{public}s ', JSON.stringify(callback));
    console.log(`testTag. Get fill request viewData: ${JSON.stringify(request.viewData)}.`);
    console.log(`testTag. Get fill request type: ${JSON.stringify(request.type)}.`);

    try {
      let localStorageData: Record<string, string | autoFillManager.FillRequestCallback | autoFillManager.ViewData | autoFillManager.AutoFillType> = {
        'message': 'AutoFill Page',
        'fillCallback': callback,
        'viewData': request.viewData,
        'autoFillType': request.type
      }
      let storage_fill = new LocalStorage(localStorageData);
      console.info(`testTag. Session: ${JSON.stringify(session)}.`);
      let size: autoFillManager.PopupSize = {
        width: 400,
        height: 200
      };
      callback.setAutoFillPopupConfig({
        popupSize: size
      });
      session.loadContent('pages/SelectorList', storage_fill);
    } catch (err) {
      hilog.error(0x0000, 'testTag', '%{public}s', 'autofill failed to load content: ' + JSON.stringify(err));
    }
  }

  onSaveRequest(session: UIExtensionContentSession, request: autoFillManager.SaveRequest, callback: autoFillManager.SaveRequestCallback) {
    hilog.info(0x0000, 'testTag', '%{public}s', 'autofill onSaveRequest');
    try {
      let localStorageData: Record<string, string | autoFillManager.SaveRequestCallback> = {
        'message': 'AutoFill Page',
        'saveCallback': callback
      };
      let storage_save = new LocalStorage(localStorageData);
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

## SaveRequestCallback

Implements callbacks for an automatic or a manual saving request.

### SaveRequestCallback.onSuccess

onSuccess(): void

Called when a saving request is successfully processed.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 202 | Permission denied, non-system app called system api. |
| 16000050 | Internal error. |

**Example**

```ts
// MyAutoFillExtensionAbility.ts
import { AutoFillExtensionAbility, UIExtensionContentSession, autoFillManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
class MyAutoFillExtensionAbility extends AutoFillExtensionAbility {
  onSaveRequest(session: UIExtensionContentSession,
                request: autoFillManager.SaveRequest,
                callback: autoFillManager.SaveRequestCallback) {
    hilog.info(0x0000, 'testTag', '%{public}s', 'onSaveRequest');
    try {
      let storageData: Record<string, string | autoFillManager.SaveRequestCallback | autoFillManager.ViewData> = {
        'message': 'AutoFill Page',
        'saveCallback': callback,
        'viewData': request.viewData
      };
      let storage_save = new LocalStorage(storageData);
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
// SavePage.ets
import { autoFillManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

@Entry
@Component
struct SavePage {
  storage: LocalStorage | undefined = this.getUIContext().getSharedLocalStorage();
  saveCallback: autoFillManager.SaveRequestCallback | undefined =
    this.storage?.get<autoFillManager.SaveRequestCallback>('saveCallback');

  build() {
    Row() {
      Column() {
        Text('SavePage')
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }

      Button('onSuccess')
        .onClick(() => {
          hilog.info(0x0000, 'testTag', 'autosave success');
          try {
            this.saveCallback?.onSuccess();
          } catch (error) {
            console.error(`catch error, code: ${(error as BusinessError).code},
                message: ${(error as BusinessError).message}`);
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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 202 | Permission denied, non-system app called system api. |
| 16000050 | Internal error. |

**Example**

```ts
// MyAutoFillExtensionAbility.ts
import { AutoFillExtensionAbility, UIExtensionContentSession, autoFillManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

class MyAutoFillExtensionAbility extends AutoFillExtensionAbility {
  onSaveRequest(session: UIExtensionContentSession,
                request: autoFillManager.SaveRequest,
                callback: autoFillManager.SaveRequestCallback) {
    hilog.info(0x0000, 'testTag', '%{public}s', 'onSaveRequest');
    try {
      let storageData: Record<string, string | autoFillManager.SaveRequestCallback | autoFillManager.ViewData> = {
        'message': 'AutoFill Page',
        'saveCallback': callback,
        'viewData': request.viewData
      }
      let storage_save = new LocalStorage(storageData);
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
// SavePage.ets
import { autoFillManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

@Entry
@Component
struct SavePage {
  storage: LocalStorage | undefined = this.getUIContext().getSharedLocalStorage();
  saveCallback: autoFillManager.SaveRequestCallback | undefined =
    this.storage?.get<autoFillManager.SaveRequestCallback>('saveCallback');
  
  build() {
    Row() {
      Column() {
        Text('Save Page')
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }

      Button('onFailure')
        .onClick(() => {
          hilog.info(0x0000, 'testTag', 'autofill failure');
          try {
            this.saveCallback?.onFailure();
          } catch (error) {
            console.error(`catch error, code: ${(error as BusinessError).code},
              message: ${(error as BusinessError).message}`);
          }
        })
        .width('100%')
    }
    .height('100%')
  }
}
```
