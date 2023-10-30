# WindowExtensionContext

WindowExtensionContext模块是WindowExtensionAbility的上下文环境，继承自[ExtensionContext](js-apis-inner-application-extensionContext.md)。

WindowExtensionContext模块提供[WindowExtensionAbility](js-apis-application-windowExtensionAbility.md)具有的能力，包括启动Ability。

> **说明：**
>
>  - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
>  - 本模块接口为系统接口。
>
>  - 本模块接口仅可在Stage模型下使用。

## 使用说明

在使用WindowExtensionContext的功能前，需要通过WindowExtensionAbility子类实例获取。

```ts
import WindowExtensionAbility from '@ohos.application.WindowExtensionAbility';
import WindowExtensionContext from 'application/WindowExtensionContext';

let context: WindowExtensionContext | null = null;

class WindowExtAbility extends WindowExtensionAbility {
  onConnect() {
    context = this.context; // 获取WindowExtensionContext
  }
}
```

## WindowExtensionContext.startAbility

startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;): void

启动Ability，使用callback异步回调。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md)  | 是 | 启动Ability的want信息。 |
| options | [StartOptions](js-apis-app-ability-startOptions.md) | 是 | 启动Ability所携带的参数。 |
| callback | AsyncCallback&lt;void&gt; | 是 | callback形式返回启动结果。 |

**示例：**

```ts
import WindowExtensionAbility from '@ohos.application.WindowExtensionAbility';
import { BusinessError } from '@ohos.base';
import Want from '@ohos.app.ability.Want';
import StartOptions from '@ohos.app.ability.StartOptions';

class WindowExtAbility extends WindowExtensionAbility {
  
  onConnect() {
    let want: Want = {
      bundleName: 'com.example.myapplication',
      abilityName: 'MainAbility'
    };
    let options: StartOptions = {
      windowMode: 102
    };

    try {
      this.context.startAbility(want, options, (error: BusinessError) => {
        let message = (error as BusinessError).message;
        let errCode = (error as BusinessError).code;
        if (errCode) {
          // 处理业务逻辑错误
          console.error(`startAbility failed, error.code: ${errCode}, error.message: ${message}`);
          return;
        }
        // 执行正常业务
        console.log('startAbility succeed');
      });
    } catch (paramError) {
      // 处理入参错误异常
      let message = (paramError as BusinessError).message;
      let errCode = (paramError as BusinessError).code;
      console.error(`error.code: ${errCode}, error.message: ${message}`);
    }
  }
}
```

## WindowExtensionContext.startAbility

startAbility(want: Want, options?: StartOptions): Promise\<void>

启动Ability，使用Promise异步回调。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md)  | 是 | Want类型参数，传入需要启动的ability的信息，如Ability名称，Bundle名称等。 |
| options | [StartOptions](js-apis-app-ability-startOptions.md) | 否 | 启动Ability所携带的参数。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```ts
import WindowExtensionAbility from '@ohos.application.WindowExtensionAbility';
import { BusinessError } from '@ohos.base';
import Want from '@ohos.app.ability.Want';
import StartOptions from '@ohos.app.ability.StartOptions';

class WindowExtAbility extends WindowExtensionAbility {

  onConnect() {
    let want: Want = {
      bundleName: 'com.example.myapp',
      abilityName: 'MainAbility'
    };
    let options: StartOptions = {
      windowMode: 102,
    };

    try {
      this.context.startAbility(want, options)
        .then(() => {
          // 执行正常业务
          console.log('startAbility succeed');
        })
        .catch((error: BusinessError) => {
          // 处理业务逻辑错误
          let message = (error as BusinessError).message;
          let errCode = (error as BusinessError).code;
          console.error(`startAbility failed, error.code: ${errCode}, error.message: ${message}`);
        });
    } catch (paramError) {
      // 处理入参错误异常
      let message = (paramError as BusinessError).message;
      let errCode = (paramError as BusinessError).code;
      console.error(`error.code: ${errCode}, error.message: ${message}`);
    }
  }
}
```