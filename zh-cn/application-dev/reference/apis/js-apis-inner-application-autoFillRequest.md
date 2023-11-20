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
