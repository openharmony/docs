# ApplicationContext(系统接口)

ApplicationContext模块继承自[Context](js-apis-inner-application-context.md)，提供开发者应用级别的的上下文的能力，包括提供注册及取消注册应用内组件生命周期的监听接口。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 当前页面仅包含本模块的系统接口，其他公开接口参见[ApplicationContext](js-apis-inner-application-applicationContext.md)。

## 导入模块

```ts
import common from '@ohos.app.ability.common';
```

## 使用说明

在使用ApplicationContext的功能前，需要通过context的实例获取。

## ApplicationContext.preloadUIExtensionAbility<sup>12+</sup>

preloadUIExtensionAbility(want: Want): Promise\<void\>

预加载指定UIExtensionAbility实例。
被预加载的UIExtensionAbility实例会执行到UIExtensionAbility的OnCreate生命周期，然后等待被当前应用正式加载。支持多次预加载UIExtensionAbility实例，每次正式加载时，会使一个预加载的UIExtensionAbility实例从OnCreate继续完成UIExtensionAbility的生命周期。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md)  | 是 | 预加载UIExtensionAbility的want信息。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16200011 | The context does not exist. |
| 16000050 | Internal error. |

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends UIAbility {

  onCreate() {
    let want: Want = {
      bundleName: 'com.ohos.uiextensionprovider',
      abilityName: 'UIExtensionProvider',
      moduleName: 'entry',
      parameters: {
        //与UIExtensionAbility在module.json5中"type"字段配置一致
        'ability.want.params.uiExtensionType': 'sys/commonUI'
      }
    };
    try {
        let applicationContext = this.context.getApplicationConext();
        applicationContext.preloadUIExtensionAbility(want)
        .then(() => {
          // 执行正常业务
          console.info('preloadUIExtensionAbility succeed');
        })
        .catch((err: BusinessError) => {
          // 处理业务逻辑错误
          console.error('preloadUIExtensionAbility failed');
        });
    } catch (err) {
      // 处理入参错误异常
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error('preloadUIExtensionAbility failed');
    }
  }
}
```

## ApplicationContext.setSupportedProcessCache<sup>12+</sup>

setSupportedProcessCache(isSupported : boolean): void

应用设置自身是否支持缓存后快速启动。

> **说明：**
>
> 该接口设置的缓存支持状态对单个应用进程实例生效，不同进程实例互不影响，且一个进程实例只允许设置一次。应用进程实例销毁后，设置过的状态不保留，可以重新设置。

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.SET_PROCESS_CACHE_STATE

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**
| 参数名        | 类型     | 必填 | 说明                       |
| ------------- | -------- | ---- | -------------------------- |
| isSupported | boolean | 是 | 表示应用是否支持缓存后快速启动。true表示支持，false表示不支持。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)、[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not system App. |
| 401 | The input parameter is not a valid parameter. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |
| 16000200 | The supported process cache state cannot be set more than once. |

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import type AbilityConstant from '@ohos.app.ability.AbilityConstant';
import type Want from '@ohos.app.ability.Want';

export default class MyAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    let applicationContext = this.context.getApplicationContext();
    try {
      applicationContext.setSupportedProcessCache(false);
    } catch (error) {
      console.error(`setSupportedProcessCache fail, error: ${JSON.stringify(error)}`);
    }
  }
}
```