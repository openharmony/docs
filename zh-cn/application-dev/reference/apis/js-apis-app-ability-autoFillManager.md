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

当手动保存完成时所触发的回调接口。

### AutoSaveCallback.onSuccess

onSuccess(): void

当手动保存成功时，该回调被调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**示例：**

  ```ts
// EntryAbility.ts
  import UIAbility from '@ohos.app.ability.UIAbility';
  import hilog from '@ohos.hilog';
  import window from '@ohos.window';
  import { BusinessError } from '@ohos.base';

  onWindowStageCreate(windowStage: window.WindowStage): void {
    // Main window is created, set main page for this ability
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageCreate');
    let storage = new LocalStorage(
      {
        'message': "Index Page",
        'context': this.context,
      });
    windowStage.loadContent('pages/Index', storage, (err, data) => {
      if (err.code) {
        hilog.error(0x0000, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err) ?? '');
        return;
      }

      // 获取应用主窗口。
      windowStage.getMainWindow((err: BusinessError, data: window.Window) => {
        let errCode: number = err.code;
        if (errCode) {
          console.error('Failed to obtain the main window. Cause: ' + JSON.stringify(err));
          return;
        }
        console.info('Succeeded in obtaining the main window. Data: ' + JSON.stringify(data));
        // get UIContext instance
        let uiContext: UIContext = windowStage.getMainWindowSync().getUIContext();
        PersistentStorage.PersistProp("uiContext", uiContext);
      })
      hilog.info(0x0000, 'testTag', 'Succeeded in loading the content. Data: %{public}s', JSON.stringify(data) ?? '');
    });
  }
  ```

  ```ts
  // Index.ets
  import autoFillManager from '@ohos.app.ability.autoFillManager';
  import { UIContext } from '@ohos.arkui.UIContext';
  
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
  
        Button('onSuccess')
          .onClick(() => {
            let uiContext = AppStorage.Get<UIContext>("uiContext");
            console.log("uiContext: ", JSON.stringify(uiContext));
            autoFillManager.requestAutoSave(uiContext, {
              onSuccess: () => {
                console.log("save request on success");
              }
            });
          })
          .width('100%')
      }
      .height('100%')
    }
  }
  ```

### AutoSaveCallback.onFailure

onFailure(): void

当手动保存失败时，该回调被调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**示例：**

  ```ts
// EntryAbility.ts
  import UIAbility from '@ohos.app.ability.UIAbility';
  import hilog from '@ohos.hilog';
  import window from '@ohos.window';
  import { BusinessError } from '@ohos.base';

  onWindowStageCreate(windowStage: window.WindowStage): void {
    // Main window is created, set main page for this ability
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageCreate');
    let storage = new LocalStorage(
      {
        'message': "Index Page",
        'context': this.context,
      });
    windowStage.loadContent('pages/Index', storage, (err, data) => {
      if (err.code) {
        hilog.error(0x0000, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err) ?? '');
        return;
      }

      // 获取应用主窗口。
      windowStage.getMainWindow((err: BusinessError, data: window.Window) => {
        let errCode: number = err.code;
        if (errCode) {
          console.error('Failed to obtain the main window. Cause: ' + JSON.stringify(err));
          return;
        }
        console.info('Succeeded in obtaining the main window. Data: ' + JSON.stringify(data));
        // get UIContext instance
        let uiContext: UIContext = windowStage.getMainWindowSync().getUIContext();
        PersistentStorage.PersistProp("uiContext", uiContext);
      })
      hilog.info(0x0000, 'testTag', 'Succeeded in loading the content. Data: %{public}s', JSON.stringify(data) ?? '');
    });
  }
  ```

  ```ts
  // Index.ets
  import autoFillManager from '@ohos.app.ability.autoFillManager';
  import { UIContext } from '@ohos.arkui.UIContext';
  
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
  
        Button('onFailure')
          .onClick(() => {
            let uiContext = AppStorage.Get<UIContext>("uiContext");
            console.log("uiContext: ", JSON.stringify(uiContext));
            autoFillManager.requestAutoSave(uiContext, {
              onFailure: () => {
                console.log("save request on failure");
              }
            });
          })
          .width('100%')
      }
      .height('100%')
    }
  }
  ```

## requestAutoSave

requestAutoSave(context: UIContext, callback?: AutoSaveCallback): void

触发手动保存请求。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| context | [UIContext](js-apis-arkui-UIContext.md) | 是 | 将在其中执行保存操作的UI上下文。 |
| callback | [AutoSaveCallback](#autosavecallback)  | 否 | 手动保存的回调函数。 |

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

  onWindowStageCreate(windowStage: window.WindowStage): void {
    // Main window is created, set main page for this ability
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageCreate');
    let storage = new LocalStorage(
      {
        'message': "Index Page",
        'context': this.context,
      });
    windowStage.loadContent('pages/Index', storage, (err, data) => {
      if (err.code) {
        hilog.error(0x0000, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err) ?? '');
        return;
      }

      // 获取应用主窗口。
      windowStage.getMainWindow((err: BusinessError, data: window.Window) => {
        let errCode: number = err.code;
        if (errCode) {
          console.error('Failed to obtain the main window. Cause: ' + JSON.stringify(err));
          return;
        }
        console.info('Succeeded in obtaining the main window. Data: ' + JSON.stringify(data));
        // get UIContext instance
        let uiContext: UIContext = windowStage.getMainWindowSync().getUIContext();
        PersistentStorage.PersistProp("uiContext", uiContext);
      })
      hilog.info(0x0000, 'testTag', 'Succeeded in loading the content. Data: %{public}s', JSON.stringify(data) ?? '');
    });
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
            let uiContext = AppStorage.Get<UIContext>("uiContext");
            console.log("uiContext: ", JSON.stringify(uiContext));
            try {
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
