# @ohos.app.ability.AutoFillExtensionAbility (AutoFillExtensionAbility)

AutoFillExtensionAbility模块提供账号和密码的自动填充和保存功能, 继承自[ExtensionAbility](js-apis-app-ability-extensionAbility.md)。

> **说明：**
> 
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import AutoFillExtensionAbility from '@ohos.app.ability.AutoFillExtensionAbility';
```

## 属性

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| context | [AutoFillExtensionContext](js-apis-inner-application-autoFillExtensionContext.md)  | 是 | 否 | AutoFillExtension的上下文环境，继承自ExtensionContext。 |


## AutoFillExtensionAbility.onCreate

onCreate(): void

AutoFillExtensionAbility创建时触发回调函数。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**示例：**

  ```ts
  import AutoFillExtensionAbility from '@ohos.app.ability.AutoFillExtensionAbility';
  import hilog from '@ohos.hilog';

  class MyAutoFillExtensionAbility extends AutoFillExtensionAbility {
    onCreate() {
      hilog.info(0x0000, 'testTag', '%{public}s', 'onCreate');
    }
  }
  ```

## AutoFillExtensionAbility.onFillRequest

onFillRequest(session: UIExtensionContentSession, request: FillRequest, callback: FillRequestCallback): void

当发起自动填充请求或者生成密码时触发此回调函数。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| session | [UIExtensionContentSession](js-apis-app-ability-uiExtensionContentSession.md)  | 是 | 否 | AutoFillExtensionAbility界面内容相关信息。 |
| request | [FillRequest](js-apis-inner-application-autoFillRequest.md#fillrequest)  | 是 | 否 | 自动填充数据。 |
| callback | [FillRequestCallback](js-apis-inner-application-autoFillRequest.md#fillrequestcallback)  | 是 | 否 | 自动填充请求回调。 |

**示例：**

  ```ts
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

## AutoFillExtensionAbility.onSaveRequest

onSaveRequest(session: UIExtensionContentSession, request: SaveRequest, callback: SaveRequestCallback): void

当发起自动保存或者手动保存时触发此回调函数。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| session | [UIExtensionContentSession](js-apis-app-ability-uiExtensionContentSession.md)  | 是 | 否 | AutoFillExtensionAbility界面内容相关信息。 |
| request | [SaveRequest](js-apis-inner-application-autoFillRequest.md#saverequest)  | 是 | 否 | 保存请求数据。 |
| callback | [SaveRequestCallback](js-apis-inner-application-autoFillRequest.md#saverequestcallback)  | 是 | 否 | 保存请求回调。 |

**示例：**

  ```ts
  import AutoFillExtensionAbility from '@ohos.app.ability.AutoFillExtensionAbility';
  import UIExtensionContentSession from '@ohos.app.ability.UIExtensionContentSession';
  import autoFillManager from '@ohos.app.ability.autoFillManager';
  import hilog from '@ohos.hilog';

  class MyAutoFillExtensionAbility extends AutoFillExtensionAbility {
    onSaveRequest(session : UIExtensionContentSession,
                  request : autoFillManager.SaveRequest,
                  callback : autoFillManager.SaveRequestCallback) {
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

## AutoFillExtensionAbility.onSessionDestroy

onSessionDestroy(session: UIExtensionContentSession): void

当AutoFillExtensionAbility界面内容对象销毁后调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| session | [UIExtensionContentSession](js-apis-app-ability-uiExtensionContentSession.md) | 是 | AutoFillExtensionAbility界面内容相关信息。 |

**示例：**

  ```ts
  import AutoFillExtensionAbility from '@ohos.app.ability.AutoFillExtensionAbility';
  import UIExtensionContentSession from '@ohos.app.ability.UIExtensionContentSession';
  import hilog from '@ohos.hilog';

  class MyAutoFillExtensionAbility extends AutoFillExtensionAbility {
    onSessionDestroy(session : UIExtensionContentSession) {
      hilog.info(0x0000, 'testTag', '%{public}s', 'onSessionDestroy');
    }
  }
  ```

## AutoFillExtensionAbility.onForeground

onForeground(): void

当AutoFillExtensionAbility从后台转到前台时触发。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**示例：**

  ```ts
  import AutoFillExtensionAbility from '@ohos.app.ability.AutoFillExtensionAbility';
  import hilog from '@ohos.hilog';

  class MyAutoFillExtensionAbility extends AutoFillExtensionAbility {
    onForeground() {
      hilog.info(0x0000, 'testTag', '%{public}s', 'onForeground');
    }
  }
  ```

## AutoFillExtensionAbility.onBackground

onBackground(): void

当AutoFillExtensionAbility从前台转到后台时触发。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**示例：**

  ```ts
  import AutoFillExtensionAbility from '@ohos.app.ability.AutoFillExtensionAbility';
  import hilog from '@ohos.hilog';

  class MyAutoFillExtensionAbility extends AutoFillExtensionAbility {
    onBackground() {
      hilog.info(0x0000, 'testTag', '%{public}s', 'onBackground');
    }
  }
  ```

## AutoFillExtensionAbility.onDestroy

onDestroy(): void | Promise&lt;void&gt;

在AutoFillExtensionAbility销毁时回调，执行资源清理等操作。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**返回值：**

| 类型                                  | 说明                            |
| ------------------------------------- | ------------------------------- |
| void&nbsp;\|&nbsp;Promise&lt;void&gt; | 无返回值或者以Promise形式返回。 |

**示例：**

  ```ts
  import AutoFillExtensionAbility from '@ohos.app.ability.AutoFillExtensionAbility';
  import hilog from '@ohos.hilog';

  class MyAutoFillExtensionAbility extends AutoFillExtensionAbility {
    onDestroy() {
      hilog.info(0x0000, 'testTag', '%{public}s', 'onDestroy');
    }
  }
  ```