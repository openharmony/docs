# @ohos.app.ability.CompletionHandler (拉起应用结果的操作类)
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @littlejerry1; @yangxuguang-huawei; @Luobniz21-->
<!--Designer: @ccllee1-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

CompletionHandler作为[StartOptions](js-apis-app-ability-startOptions.md#startoptions)和[OpenLinkOptions](js-apis-app-ability-openLinkOptions.md#openlinkoptions)的可选参数，用于处理拉起应用请求的结果。


> **说明：**
>
> - 本模块首批接口从API version 20 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口仅可在Stage模型下使用。


## 约束限制

当前支持使用该模块的接口包括：
- [startAbility](js-apis-inner-application-uiAbilityContext.md#startability-2)
- [startAbilityForResult](js-apis-inner-application-uiAbilityContext.md#startabilityforresult-2)

<!--Del-->
- [startAbilityForResultWithAccount](js-apis-inner-application-uiAbilityContext-sys.md#startabilityforresultwithaccount-2)
- [startAbilityWithAccount](js-apis-inner-application-uiAbilityContext-sys.md#startabilitywithaccount-2)
- [startRecentAbility](js-apis-inner-application-uiAbilityContext-sys.md#startrecentability-2)
- [startAbilityAsCaller](js-apis-inner-application-uiAbilityContext-sys.md#startabilityascaller10-2)
<!--DelEnd-->
- [openLink](js-apis-inner-application-uiAbilityContext.md#openlink12)
## 导入模块

```ts
import { CompletionHandler } from '@kit.AbilityKit';
```

## CompletionHandler

CompletionHandler提供了[onRequestSuccess](#onrequestsuccess)和[onRequestFailure](#onrequestfailure)两个回调函数，分别用来处理拉起应用成功和失败时的结果。

### onRequestSuccess

onRequestSuccess(elementName: ElementName, message: string): void

拉起应用成功时的回调函数。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| elementName | [ElementName](js-apis-bundleManager-elementName.md) | 是 | ElementName信息用于标识被拉起应用。通常，ElementName仅包含abilityName和bundleName。moduleName和deviceId信息是否存在取决于调用方是否传入。shortName和uri为空。|
| message | string | 是 | 成功拉起应用时的信息。该信息采用JSON格式，样式如下：<br>{<br>&emsp;"errMsg": "Succeeded."<br>}</br> |

**示例：**

参见[CompletionHandler使用](#completionhandler使用)。

### onRequestFailure

onRequestFailure(elementName: ElementName, message: string): void

拉起应用失败时的回调函数。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| elementName | [ElementName](js-apis-bundleManager-elementName.md) | 是 | ElementName信息用于标识被拉起应用。<br>- 通常，ElementName仅包含abilityName和bundleName。moduleName和deviceId信息是否存在取决于调用方是否传入。shortName和uri为空。<br>- 隐式启动失败时，无法获取ElementName信息。 |
| message | string | 是 | 拉起应用失败时的信息。该信息采用JSON格式，样式如下：<br>{<br>&emsp;"errMsg": "xxx"<br>}<br>其中，"xxx"的取值说明如下：<br>Failed to call \<api-name\>：表示调用接口出错。其中，\<api-name\>为具体的接口名，比如startAbility。<br>User refused redirection：表示用户关闭了应用跳转弹框。<br>User closed the implicit startup picker：表示用户关闭了隐式启动时的应用选择弹框。<br>User closed the app clone picker：表示用户关闭了分身应用选择弹框。<br>Free installation failed：表示免安装失败。</br> |

**示例：**

参见[CompletionHandler使用](#completionhandler使用)。

### CompletionHandler使用

  ```ts
  import { UIAbility, Want, StartOptions, CompletionHandler, bundleManager } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  export default class EntryAbility extends UIAbility {
    onForeground() {
      let want: Want = {
        deviceId: '',
        bundleName: 'com.example.myapplication',
        abilityName: 'EntryAbility'
      };

      let completionHandler: CompletionHandler = {
        onRequestSuccess: (elementName: bundleManager.ElementName, message: string): void => {
          console.info(`${elementName.bundleName}-${elementName.moduleName}-${elementName.abilityName} start succeeded: ${message}`);
        },
        onRequestFailure: (elementName: bundleManager.ElementName, message: string): void => {
          console.error(`${elementName.bundleName}-${elementName.moduleName}-${elementName.abilityName} start failed: ${message}`);
        }
      };

      let options: StartOptions = {
        completionHandler: completionHandler
      };

      try {
        this.context.startAbility(want, options, (err: BusinessError) => {
          if (err.code) {
            // 处理业务逻辑错误
            console.error(`startAbility failed, code is ${err.code}, message is ${err.message}`);
            return;
          }
          // 执行正常业务
          console.info('startAbility succeed');
        });
      } catch (err) {
        // 处理入参错误异常
        let code = (err as BusinessError).code;
        let message = (err as BusinessError).message;
        console.error(`startAbility failed, code is ${code}, message is ${message}`);
      }
    }
  }
  ```
