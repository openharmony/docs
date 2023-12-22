# AutoFillRequest

当AutoFillExtensionAbility触发回调函数时，提供给开发者的页面数据和回调接口。

> **说明：**
> 
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import autoFillManager from '@ohos.app.ability.autoFillManager';
```

## FillRequest

自动填充信息。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

| 名称        | 类型                 | 必填 | 说明                                                         |
| ----------- | -------------------- | ---- | ------------------------------------------------------------ |
| type        | [AutoFillType](js-apis-inner-application-autoFillType.md)       | 是   | 自动填充类型。          |
| viewData    | [ViewData](js-apis-inner-application-viewData.md)               | 是   | 页面数据。              |

## SaveRequest

自动保存请求信息。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

| 名称        | 类型                 | 必填 | 说明                                                         |
| ----------- | -------------------- | ---- | ------------------------------------------------------------ |
| viewData    | [ViewData](js-apis-inner-application-viewData.md)               | 是   | 页面数据。              |

## FillResponse

自动填充响应。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

| 名称        | 类型                 | 必填 | 说明                                                         |
| ----------- | -------------------- | ---- | ------------------------------------------------------------ |
| viewData    | [ViewData](js-apis-inner-application-viewData.md)               | 是   | 页面数据。              |

## FillRequestCallback

自动填充或者生成密码时的回调对象，可以通过此回调通知客户端成功或者失败。

### FillRequestCallback.onSuccess

onSuccess(response: FillResponse): void

通知自动填充请求已成功完成。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | ------------------------------ |
| response | [FillResponse](#fillresponse)  | 是 | 自动填充响应信息。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000050 | Internal error. |

**示例：**

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
      try {
        let storage_fill = new LocalStorage(
          {
            'fillCallback': callback,
            'message': "AutoFill Page",
            'viewData': request.viewData,
          });
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
  import autoFillManager from '@ohos.app.ability.autoFillManager';
  import Base from '@ohos.base';
  import hilog from '@ohos.hilog';
  
  let storage = LocalStorage.getShared();
  let fillCallback = storage.get<autoFillManager.FillRequestCallback>('fillCallback');
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
            viewData.pageNodeInfos[0].value = "user1";
            viewData.pageNodeInfos[1].value = "user1 password";
            viewData.pageNodeInfos[2].value = "user1 generate new password";
            hilog.info(0x0000, 'testTag', 'autofill success with viewData: %{public}s', JSON.stringify(viewData));
            try {
              fillCallback.onSuccess({ viewData: viewData });
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

通知自动填充请求已失败。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000050 | Internal error. |

**示例：**

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
      try {
        let storage_fill = new LocalStorage(
          {
            'fillCallback': callback,
            'message': "AutoFill Page",
            'viewData': request.viewData,
          });
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
  import autoFillManager from '@ohos.app.ability.autoFillManager';
  import Base from '@ohos.base';
  import hilog from '@ohos.hilog';

  let storage = LocalStorage.getShared();
  let fillCallback = storage.get<autoFillManager.FillRequestCallback>('fillCallback');

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
              fillCallback.onFailure();
            } catch (error) {
              console.error(`catch error, code: ${(error as Base.BusinessError).code},
                            message: ${(error as Base.BusinessError).message}`);
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

通知自动填充已被取消。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000050 | Internal error. |

**示例：**

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
      try {
        let storage_fill = new LocalStorage(
          {
            'fillCallback': callback,
            'message': "AutoFill Page",
            'viewData': request.viewData,
          });
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
  import autoFillManager from '@ohos.app.ability.autoFillManager';
  import Base from '@ohos.base';
  import hilog from '@ohos.hilog';
 
  let storage = LocalStorage.getShared();
  let fillCallback = storage.get<autoFillManager.FillRequestCallback>('fillCallback');

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
              fillCallback.onCancel();
            } catch (error) {
              console.error(`catch error, code: ${(error as Base.BusinessError).code},
                            message: ${(error as Base.BusinessError).message}`);
            }
          })
          .width('100%')
      }
      .height('100%')
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

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000050 | Internal error. |

**示例：**

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
            'message': "AutoFill Page",
            'saveCallback': callback,
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
  // SavePage.ets
  import autoFillManager from '@ohos.app.ability.autoFillManager';
  import Base from '@ohos.base';
  import hilog from '@ohos.hilog';

  let storage = LocalStorage.getShared();
  let saveCallback = storage.get<autoFillManager.SaveRequestCallback>('saveCallback');

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
              saveCallback.onSuccess();
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

通知保存请求处理失败。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000050 | Internal error. |

**示例：**

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
            'message': "AutoFill Page",
            'saveCallback': callback,
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
  // SavePage.ets
  import autoFillManager from '@ohos.app.ability.autoFillManager';
  import Base from '@ohos.base';
  import hilog from '@ohos.hilog';

  let storage = LocalStorage.getShared();
  let saveCallback = storage.get<autoFillManager.SaveRequestCallback>('saveCallback');  

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
              saveCallback.onFailure();
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
