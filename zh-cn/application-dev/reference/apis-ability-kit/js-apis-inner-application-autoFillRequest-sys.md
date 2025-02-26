# AutoFillRequest (系统接口)

当AutoFillExtensionAbility触发回调函数时，提供给开发者的页面数据和回调接口。

> **说明：**
> 
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口均为系统接口。
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { autoFillManager } from '@kit.AbilityKit';
```

## FillRequest

自动填充信息。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

| 名称        | 类型                 | 必填 | 说明                                                         |
| ----------- | -------------------- | ---- | ------------------------------------------------------------ |
| type        | [AutoFillType](js-apis-inner-application-autoFillType-sys.md)       | 是   | 自动填充类型。          |
| viewData    | [ViewData](js-apis-inner-application-viewData-sys.md)               | 是   | 页面数据。              |
| customData<sup>13+</sup>    | [CustomData](js-apis-inner-application-customData-sys.md)               | 是   | 自定义数据。             |
| isPopup<sup>12+</sup>    | boolean               | 是   | 自动填充服务是否拉起popup窗口。<br>true：当前拉起popup窗口。<br>false：当前拉起模态窗。              |

## SaveRequest

自动保存请求信息。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

| 名称        | 类型                 | 必填 | 说明                                                         |
| ----------- | -------------------- | ---- | ------------------------------------------------------------ |
| viewData    | [ViewData](js-apis-inner-application-viewData-sys.md)               | 是   | 页面数据。              |

## UpdateRequest<sup>12+</sup>

自动填充更新信息。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

| 名称        | 类型                 | 必填 | 说明                                                         |
| ----------- | -------------------- | ---- | ------------------------------------------------------------ |
| viewData    | [ViewData](js-apis-inner-application-viewData-sys.md)               | 是   | 页面数据。              |

## FillResponse

自动填充响应。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

| 名称        | 类型                 | 必填 | 说明                                                         |
| ----------- | -------------------- | ---- | ------------------------------------------------------------ |
| viewData    | [ViewData](js-apis-inner-application-viewData-sys.md)               | 是   | 页面数据。              |

## FillRequestCallback

自动填充或者生成密码时的回调对象，可以通过此回调通知客户端成功或者失败。

### FillRequestCallback.onSuccess

onSuccess(response: FillResponse): void

通知自动填充请求已成功完成。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | ------------------------------ |
| response | [FillResponse](#fillresponse)  | 是 | 自动填充响应信息。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 202  | Permission denied, non-system app called system api. |
| 401  | Mandatory parameters are left unspecified. |
| 16000050 | Internal error. |

**示例：**

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

let storage: LocalStorage = LocalStorage.getShared();
let fillCallback: autoFillManager.FillRequestCallback | undefined =
  storage.get<autoFillManager.FillRequestCallback>('fillCallback');
let viewData: autoFillManager.ViewData | undefined = storage.get<autoFillManager.ViewData>('viewData');

@Entry
@Component
struct AutoFillPage {
  build() {
    Row() {
      Column() {
        Text('AutoFill Page')
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }

      Button('onSuccess')
        .onClick(() => {
          if (viewData) {
            viewData.pageNodeInfos[0].value = 'user1';
            viewData.pageNodeInfos[1].value = 'user1 password';
            viewData.pageNodeInfos[2].value = 'user1 generate new password';
            hilog.info(0x0000, 'testTag', 'autofill success with viewData: %{public}s', JSON.stringify(viewData));
            try {
              fillCallback?.onSuccess({ viewData: viewData });
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

通知自动填充请求已失败。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 202 | Permission denied, non-system app called system api. |
| 16000050 | Internal error. |

**示例：**

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

let storage: LocalStorage = LocalStorage.getShared();
let fillCallback: autoFillManager.FillRequestCallback | undefined =
  storage.get<autoFillManager.FillRequestCallback>('fillCallback');

@Entry
@Component
struct AutoFillPage {
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
            fillCallback?.onFailure();
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

### FillRequestCallback.onCancel<sup>12+</sup>

onCancel(fillContent?: string): void

通知自动填充已被取消。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

| 参数名                    | 类型   | 必填 | 说明                 |
| ------------------------- | ------ | ---- | -------------------- |
| fillContent | string | 否   | 表示通知自动填充取消后，返回给输入法框架的填充内容。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 202  | Permission denied, non-system app called system api. |
| 401  | Parameter error. Possible causes: 1. The input parameter is not valid parameter;2. Mandatory parameters are left unspecified. |
| 16000050 | Internal error. |

**示例：**

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

let storage: LocalStorage = LocalStorage.getShared();
let fillCallback: autoFillManager.FillRequestCallback | undefined =
  storage.get<autoFillManager.FillRequestCallback>('fillCallback');

@Entry
@Component
struct AutoFillPage {
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
            fillCallback?.onCancel();
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

动态调整气泡弹窗的尺寸和位置。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | ------------------------------ |
| autoFillPopupConfig | [AutoFillPopupConfig](js-apis-inner-application-autoFillPopupConfig-sys.md) | 是 | 气泡弹窗尺寸和位置信息。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 202  | Permission denied, non-system app called system api. |
| 401  | Mandatory parameters are left unspecified. |
| 16000050 | Internal error. |

**示例：**

```ts
// MyAutoFillExtensionAbility.ts
import { AutoFillExtensionAbility, UIExtensionContentSession, autoFillManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

export default class AutoFillAbility extends AutoFillExtensionAbility {
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
    let storage = LocalStorage.getShared();
    let fillCallback = storage.get<autoFillManager.FillRequestCallback>('fillCallback');

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

自动保存或者手动保存请求回调。

### SaveRequestCallback.onSuccess

onSuccess(): void

通知保存请求已成功处理。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 202 | Permission denied, non-system app called system api. |
| 16000050 | Internal error. |

**示例：**

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

let storage: LocalStorage = LocalStorage.getShared();
let saveCallback: autoFillManager.SaveRequestCallback | undefined =
  storage.get<autoFillManager.SaveRequestCallback>('saveCallback');

@Entry
@Component
struct SavePage {
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
            saveCallback?.onSuccess();
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

通知保存请求处理失败。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 202 | Permission denied, non-system app called system api. |
| 16000050 | Internal error. |

**示例：**

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

let storage: LocalStorage = LocalStorage.getShared();
let saveCallback: autoFillManager.SaveRequestCallback | undefined =
  storage.get<autoFillManager.SaveRequestCallback>('saveCallback');

@Entry
@Component
struct SavePage {
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
            saveCallback?.onFailure();
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
