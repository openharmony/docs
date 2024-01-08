# @ohos.app.ability.autoFillManager (autoFillManager)

autoFillManager模块提供手动保存账号密码等功能。

> **说明：**
> 
> 本模块首批接口从API version 11 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import autoFillManager from '@ohos.app.ability.autoFillManager';
```

## AutoSaveCallback

当保存请求完成时所触发的回调接口。

### AutoSaveCallback.onSuccess

onSuccess(): void

当保存请求成功时，该回调被调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**示例：**

参见[AutoSaveCallback.onFailure](#autosavecallbackonfailure)。

### AutoSaveCallback.onFailure

onFailure(): void

当保存请求失败时，该回调被调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**示例：**

  ```ts
  // Index.ets, 含有账号、密码框等组件的页面
  import autoFillManager from '@ohos.app.ability.autoFillManager';
  import { UIContext } from '@ohos.arkui.UIContext';
  import Base from '@ohos.base';

  let uiContext = AppStorage.get<UIContext>("uiContext");
  let callback : autoFillManager.AutoSaveCallback = {
    onSuccess: () => {
      console.log("save request on success");
    },
    onFailure: () => {
      console.log("save request on failure");
    }
  }
  ...
  Button('requestAutoSave')
    .onClick(() => {
      try {
        // 手动触发保存请求
        autoFillManager.requestAutoSave(uiContext, callback);
      } catch (error) {
        console.error(`catch error, code: ${(error as Base.BusinessError).code}, message: ${(error as Base.BusinessError).message}`);
      }
  }
  ...
  ```

> **说明：**
>
> 示例中从AppStorage中取得的UiContext为预先在EntryAbility（拉起此页面的Ability）中OnWindowStageCreate生命周期获得，并存储到AppStorage中，具体可参考[requestAutoSave](#requestautosave)。

## requestAutoSave

requestAutoSave(context: UIContext, callback?: AutoSaveCallback): void

手动触发保存请求。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| context | [UIContext](js-apis-arkui-UIContext.md) | 是 | 将在其中执行保存操作的UI上下文。 |
| callback | [AutoSaveCallback](#autosavecallback)  | 否 | 保存请求的回调函数。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000050 | Internal error. |

**示例：**

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
      // Main window is created, set main page for this ability
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
              // 手动触发保存请求
              autoFillManager.requestAutoSave(uiContext);
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
