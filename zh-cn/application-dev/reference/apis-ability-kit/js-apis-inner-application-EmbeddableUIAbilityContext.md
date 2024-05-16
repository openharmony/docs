# EmbeddableUIAbilityContext

EmbeddableUIAbilityContext是需要保存状态的[EmbeddableUIAbility](js-apis-app-ability-embeddableUIAbility.md)所对应的context，继承自[UIAbilityContext](js-apis-inner-application-uiAbilityContext.md)，提供EmbeddableUIAbility的相关配置信息以及操作EmbeddableUIAbility和ServiceExtensionAbility的方法，如启动EmbeddableUIAbility，停止当前EmbeddableUIAbilityContext所属的EmbeddableUIAbility，启动、停止、连接、断开连接ServiceExtensionAbility等。

> **说明：**
>
>  - 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>  - 本模块接口仅可在Stage模型下使用。
>  - 本模块接口需要在主线程中使用，不要在Worker、TaskPool等子线程中使用。

## 导入模块

```ts
import common from '@ohos.app.ability.common';
```

## 属性

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| abilityInfo | [AbilityInfo](js-apis-bundleManager-abilityInfo.md) | 是 | 否 | UIAbility的相关信息。 |
| currentHapModuleInfo | [HapModuleInfo](js-apis-bundleManager-hapModuleInfo.md) | 是 | 否 | 当前HAP的信息。 |
| config | [Configuration](js-apis-app-ability-configuration.md) | 是 | 否 | 与UIAbility相关的配置信息，如语言、颜色模式等。 |

> **说明：**
>
> 在本文档的示例中，通过`this.context`来获取`EmbeddableUIAbilityContext`，其中`this`代表继承自`EmbeddableUIAbility`的`EmbeddableUIAbility`实例。

## EmbeddableUIAbilityContext.startAbility

startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void

启动Ability。使用callback异步回调。

> **说明：**
>
> 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | 启动Ability的want信息。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当启动Ability成功，err为undefined，否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation flag is forbidden.        |
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**

```ts
import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends EmbeddableUIAbility {

  onForeground() {
    let want: Want = {
      bundleName: 'com.example.myapplication',
      abilityName: 'EntryAbility'
    };

    try {
      this.context.startAbility(want, (err: BusinessError) => {
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

## EmbeddableUIAbilityContext.startAbility

startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;): void

启动Ability跳转启动。使用callback异步回调。

> **说明：**
>
> 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md)  | 是 | 启动Ability的want信息。 |
| options | [StartOptions](js-apis-app-ability-startOptions.md) | 是 | 启动Ability所携带的参数。 |
| callback | AsyncCallback&lt;void&gt; | 是 |  回调函数。当启动Ability成功，err为undefined，否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16000067 | Start options check failed. |
| 16000068 | Ability already running. |
| 16200001 | The caller has been released. |
| 16200003 | The target application is not self application. |

错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**

```ts
import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';
import Want from '@ohos.app.ability.Want';
import StartOptions from '@ohos.app.ability.StartOptions';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends EmbeddableUIAbility {

  onForeground() {
    let want: Want = {
      deviceId: '',
      bundleName: 'com.example.myapplication',
      abilityName: 'EntryAbility'
    };
    let options: StartOptions = {
      displayId: 0
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

## EmbeddableUIAbilityContext.startAbility

startAbility(want: Want, options?: StartOptions): Promise&lt;void&gt;

启动Ability。使用Promise异步回调。

> **说明：**
>
> 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | 启动Ability的want信息。 |
| options | [StartOptions](js-apis-app-ability-startOptions.md) | 否 | 启动Ability所携带的参数。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation flag is forbidden.        |
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16000067 | Start options check failed. |
| 16000068 | Ability already running. |
| 16200001 | The caller has been released. |
| 16200003 | The target application is not self application. |

错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**

```ts
import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';
import Want from '@ohos.app.ability.Want';
import StartOptions from '@ohos.app.ability.StartOptions';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends EmbeddableUIAbility {

  onForeground() {
    let want: Want = {
      bundleName: 'com.example.myapplication',
      abilityName: 'EntryAbility'
    };
    let options: StartOptions = {
      displayId: 0,
    };

    try {
      this.context.startAbility(want, options)
        .then(() => {
          // 执行正常业务
          console.info('startAbility succeed');
        })
        .catch((err: BusinessError) => {
          // 处理业务逻辑错误
          console.error(`startAbility failed, code is ${err.code}, message is ${err.message}`);
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

## EmbeddableUIAbilityContext.startAbilityForResult

startAbilityForResult(want: Want, callback: AsyncCallback&lt;AbilityResult&gt;): void

启动一个Ability。使用callback异步回调。
Ability被启动后，有如下情况:
 - 正常情况下可通过调用[terminateSelfWithResult](#embeddableuiabilitycontextterminateselfwithresult)接口使之终止并且返回结果给调用方。
 - 异常情况下比如杀死Ability会返回异常信息给调用方, 异常信息中resultCode为-1。
 - 如果被启动的Ability模式是单实例模式, 不同应用多次调用该接口启动这个Ability，当这个Ability调用[terminateSelfWithResult](#embeddableuiabilitycontextterminateselfwithresult)接口使之终止时，只将正常结果返回给最后一个调用方, 其它调用方返回异常信息, 异常信息中resultCode为-1。

> **说明：**
>
> 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-app-ability-want.md) | 是 | 启动Ability的want信息。 |
| callback | AsyncCallback&lt;[AbilityResult](js-apis-inner-ability-abilityResult.md)&gt; | 是 | 回调函数，返回执行结果。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation flag is forbidden. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**

```ts
import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';
import common from '@ohos.app.ability.common';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends EmbeddableUIAbility {

  onForeground() {
    let want: Want = {
      deviceId: '',
      bundleName: 'com.example.myapplication',
      abilityName: 'EntryAbility'
    };

    try {
      this.context.startAbilityForResult(want, (err: BusinessError, result: common.AbilityResult) => {
        if (err.code) {
          // 处理业务逻辑错误
          console.error(`startAbilityForResult failed, code is ${err.code}, message is ${err.message}`);
          return;
        }
        // 执行正常业务
        console.info('startAbilityForResult succeed');
      });
    } catch (err) {
      // 处理入参错误异常
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`startAbilityForResult failed, code is ${code}, message is ${message}`);
    }
  }
}
```

## EmbeddableUIAbilityContext.startAbilityForResult

startAbilityForResult(want: Want, options: StartOptions, callback: AsyncCallback&lt;AbilityResult&gt;): void

启动一个Ability。使用callback异步回调。
Ability被启动后，有如下情况(callback形式):
 - 正常情况下可通过调用[terminateSelfWithResult](#embeddableuiabilitycontextterminateselfwithresult)接口使之终止并且返回结果给调用方。
 - 异常情况下比如杀死Ability会返回异常信息给调用方，异常信息中resultCode为-1。
 - 如果被启动的Ability模式是单实例模式, 不同应用多次调用该接口启动这个Ability，当这个Ability调用[terminateSelfWithResult](#embeddableuiabilitycontextterminateselfwithresult)接口使之终止时，只将正常结果返回给最后一个调用方，其它调用方返回异常信息, 异常信息中resultCode为-1。

> **说明：**
>
> 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-app-ability-want.md) | 是 | 启动Ability的want信息。 |
| options | [StartOptions](js-apis-app-ability-startOptions.md) | 是 | 启动Ability所携带的参数。 |
| callback | AsyncCallback&lt;[AbilityResult](js-apis-inner-ability-abilityResult.md)&gt; | 是 | 回调函数，返回执行结果。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**

```ts
import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';
import common from '@ohos.app.ability.common';
import Want from '@ohos.app.ability.Want';
import StartOptions from '@ohos.app.ability.StartOptions';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends EmbeddableUIAbility {

  onForeground() {
    let want: Want = {
      deviceId: '',
      bundleName: 'com.example.myapplication',
      abilityName: 'EntryAbility'
    };
    let options: StartOptions = {
      displayId: 0,
    };

    try {
      this.context.startAbilityForResult(want, options, (err: BusinessError, result: common.AbilityResult) => {
        if (err.code) {
          // 处理业务逻辑错误
          console.error(`startAbilityForResult failed, code is ${err.code}, message is ${err.message}`);
          return;
        }
        // 执行正常业务
        console.info('startAbilityForResult succeed');
      });
    } catch (err) {
      // 处理入参错误异常
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`startAbilityForResult failed, code is ${code}, message is ${message}`);
    }
  }
}
```


## EmbeddableUIAbilityContext.startAbilityForResult

startAbilityForResult(want: Want, options?: StartOptions): Promise&lt;AbilityResult&gt;

启动一个Ability。使用Promise异步回调。
Ability被启动后，有如下情况:
 - 正常情况下可通过调用[terminateSelfWithResult](#embeddableuiabilitycontextterminateselfwithresult)接口使之终止并且返回结果给调用方。
 - 异常情况下比如杀死Ability会返回异常信息给调用方, 异常信息中resultCode为-1。
 - 如果被启动的Ability模式是单实例模式, 不同应用多次调用该接口启动这个Ability，当这个Ability调用[terminateSelfWithResult](#embeddableuiabilitycontextterminateselfwithresult)接口使之终止时，只将正常结果返回给最后一个调用方, 其它调用方返回异常信息, 异常信息中resultCode为-1。

> **说明：**
>
> 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | 启动Ability的want信息。 |
| options | [StartOptions](js-apis-app-ability-startOptions.md) | 否 | 启动Ability所携带的参数。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[AbilityResult](js-apis-inner-ability-abilityResult.md)&gt; | Promise对象，返回执行结果。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation flag is forbidden. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**

```ts
import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';
import common from '@ohos.app.ability.common';
import Want from '@ohos.app.ability.Want';
import StartOptions from '@ohos.app.ability.StartOptions';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends EmbeddableUIAbility {

  onForeground() {
    let want: Want = {
      bundleName: 'com.example.myapplication',
      abilityName: 'EntryAbility'
    };
    let options: StartOptions = {
      displayId: 0,
    };

    try {
      this.context.startAbilityForResult(want, options)
        .then((result: common.AbilityResult) => {
          // 执行正常业务
          console.info('startAbilityForResult succeed');
        })
        .catch((err: BusinessError) => {
          // 处理业务逻辑错误
          console.error(`startAbilityForResult failed, code is ${err.code}, message is ${err.message}`);
        });
    } catch (err) {
      // 处理入参错误异常
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`startAbilityForResult failed, code is ${code}, message is ${message}`);
    }
  }
}
```

## EmbeddableUIAbilityContext.terminateSelf

terminateSelf(callback: AsyncCallback&lt;void&gt;): void

停止Ability自身跳转启动。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当停止Ability成功，err为undefined，否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**

```ts
import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends EmbeddableUIAbility {

  onForeground() {
    try {
      this.context.terminateSelf((err: BusinessError) => {
        if (err.code) {
          // 处理业务逻辑错误
          console.error(`terminateSelf failed, code is ${err.code}, message is ${err.message}`);
          return;
        }
        // 执行正常业务
        console.info('terminateSelf succeed');
      });
    } catch (err) {
      // 捕获同步的参数错误
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`terminateSelf failed, code is ${code}, message is ${message}`);
    }
  }
}
```


## EmbeddableUIAbilityContext.terminateSelf

terminateSelf(): Promise&lt;void&gt;

停止Ability自身。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**

```ts
import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends EmbeddableUIAbility {

  onForeground() {
    try {
      this.context.terminateSelf()
        .then(() => {
          // 执行正常业务
          console.info('terminateSelf succeed');
        })
        .catch((err: BusinessError) => {
          // 处理业务逻辑错误
          console.error(`terminateSelf failed, code is ${err.code}, message is ${err.message}`);
        });
    } catch (err) {
      // 捕获同步的参数错误
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`terminateSelf failed, code is ${code}, message is ${message}`);
    }
  }
}
```


## EmbeddableUIAbilityContext.terminateSelfWithResult

terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback&lt;void&gt;): void

停止当前的Ability。如果该Ability是通过调用[startAbilityForResult](#embeddableuiabilitycontextstartabilityforresult)接口被拉起的，调用terminateSelfWithResult接口时会将结果返回给调用者，如果该Ability不是通过调用[startAbilityForResult](#embeddableuiabilitycontextstartabilityforresult)接口被拉起的，调用terminateSelfWithResult接口时不会有结果返回给调用者跳转启动。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| parameter | [AbilityResult](js-apis-inner-ability-abilityResult.md) | 是 | 返回给调用startAbilityForResult&nbsp;接口调用方的相关信息。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当停止Ability成功，err为undefined，否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**

```ts
import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';
import common from '@ohos.app.ability.common';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends EmbeddableUIAbility {

  onForeground() {
    let want: Want = {
      bundleName: 'com.example.myapplication',
      abilityName: 'EntryAbility'
    };
    let resultCode = 100;
    // 返回给接口调用方AbilityResult信息
    let abilityResult: common.AbilityResult = {
      want,
      resultCode
    };

    try {
      this.context.terminateSelfWithResult(abilityResult, (err: BusinessError) => {
        if (err.code) {
          // 处理业务逻辑错误
          console.error(`terminateSelfWithResult failed, code is ${err.code}, message is ${err.message}`);
          return;
        }
        // 执行正常业务
        console.info('terminateSelfWithResult succeed');
      });
    } catch (err) {
      // 处理入参错误异常
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`terminateSelfWithResult failed, code is ${code}, message is ${message}`);
    }
  }
}
```


## EmbeddableUIAbilityContext.terminateSelfWithResult

terminateSelfWithResult(parameter: AbilityResult): Promise&lt;void&gt;

停止当前的Ability。如果该Ability是通过调用[startAbilityForResult](#embeddableuiabilitycontextstartabilityforresult)接口被拉起的，调用terminateSelfWithResult接口时会将结果返回给调用者，如果该Ability不是通过调用[startAbilityForResult](#embeddableuiabilitycontextstartabilityforresult)接口被拉起的，调用terminateSelfWithResult接口时不会有结果返回给调用者。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| parameter | [AbilityResult](js-apis-inner-ability-abilityResult.md) | 是 | 返回给startAbilityForResult&nbsp;调用方的信息。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**

```ts
import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';
import common from '@ohos.app.ability.common';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends EmbeddableUIAbility {

  onForeground() {
    let want: Want = {
      bundleName: 'com.example.myapplication',
      abilityName: 'EntryAbility'
    };
    let resultCode = 100;
    // 返回给接口调用方AbilityResult信息
    let abilityResult: common.AbilityResult = {
      want,
      resultCode
    };

    try {
      this.context.terminateSelfWithResult(abilityResult)
        .then(() => {
          // 执行正常业务
          console.info('terminateSelfWithResult succeed');
        })
        .catch((err: BusinessError) => {
          // 处理业务逻辑错误
          console.error(`terminateSelfWithResult failed, code is ${err.code}, message is ${err.message}`);
        });
    } catch (err) {
      // 处理入参错误异常
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`terminateSelfWithResult failed, code is ${code}, message is ${message}`);
    }
  }
}
```

## EmbeddableUIAbilityContext.connectServiceExtensionAbility

connectServiceExtensionAbility(want: Want, options: ConnectOptions): number

将当前Ability连接到一个使用AbilityInfo.AbilityType.SERVICE模板的Ability。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | 连接ServiceExtensionAbility的want信息。 |
| options | [ConnectOptions](js-apis-inner-ability-connectOptions.md) | 是 | 与ServiceExtensionAbility建立连接后回调函数的实例。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回Ability连接的结果code。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000011 | The context does not exist.        |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |

错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**

```ts
import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';
import common from '@ohos.app.ability.common';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';
import rpc from '@ohos.rpc';

export default class EntryAbility extends EmbeddableUIAbility {

  onForeground() {
    let want: Want = {
      deviceId: '',
      bundleName: 'com.example.myapplication',
      abilityName: 'ServiceExtensionAbility'
    };
    let commRemote: rpc.IRemoteObject;
    let options: common.ConnectOptions = {
      onConnect(elementName, remote) {
        commRemote = remote;
        console.info('onConnect...')
      },
      onDisconnect(elementName) {
        console.info('onDisconnect...')
      },
      onFailed(code) {
        console.info('onFailed...')
      }
    };
    let connection: number;
    try {
      connection = this.context.connectServiceExtensionAbility(want, options);
    } catch (err) {
      // 处理入参错误异常
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`connectServiceExtensionAbility failed, code is ${code}, message is ${message}`);
    }
  }
}
```

## EmbeddableUIAbilityContext.disconnectServiceExtensionAbility

disconnectServiceExtensionAbility(connection: number): Promise\<void>

断开与ServiceExtensionAbility的连接，断开连接之后需要将连接成功时返回的remote对象置空。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| connection | number | 是 | 连接的ServiceExtensionAbility的数字代码，即connectServiceExtensionAbility返回的connectionId。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**

```ts
import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';
import { BusinessError } from '@ohos.base';
import rpc from '@ohos.rpc';

export default class EntryAbility extends EmbeddableUIAbility {

  onForeground() {
    // connection为connectServiceExtensionAbility中的返回值
    let connection = 1;
    let commRemote: rpc.IRemoteObject | null;

    try {
      this.context.disconnectServiceExtensionAbility(connection).then(() => {
        commRemote = null;
        // 执行正常业务
        console.info('disconnectServiceExtensionAbility succeed');
      }).catch((err: BusinessError) => {
        // 处理业务逻辑错误
        console.error(`disconnectServiceExtensionAbility failed, code is ${err.code}, message is ${err.message}`);
      })
    } catch (err) {
      commRemote = null;
      // 处理入参错误异常
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`disconnectServiceExtensionAbility failed, code is ${code}, message is ${message}`);
    }
  }
}
```

## EmbeddableUIAbilityContext.disconnectServiceExtensionAbility

disconnectServiceExtensionAbility(connection: number, callback: AsyncCallback\<void>): void

断开与ServiceExtensionAbility的连接，断开连接之后需要将连接成功时返回的remote对象置空跳转启动。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| connection | number | 是 | 连接的ServiceExtensionAbility的数字代码，即connectServiceExtensionAbility返回的connectionId。 |
| callback | AsyncCallback\<void> | 是 | 回调函数。当断开连接成功，err为undefined，否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**

```ts
import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';
import { BusinessError } from '@ohos.base';
import rpc from '@ohos.rpc';

export default class EntryAbility extends EmbeddableUIAbility {

  onForeground() {
    // connection为connectServiceExtensionAbility中的返回值
    let connection = 1;
    let commRemote: rpc.IRemoteObject | null;

    try {
      this.context.disconnectServiceExtensionAbility(connection, (err: BusinessError) => {
        commRemote = null;
        if (err.code) {
          // 处理业务逻辑错误
          console.error(`disconnectServiceExtensionAbility failed, code is ${err.code}, message is ${err.message}`);
          return;
        }
        // 执行正常业务
        console.info('disconnectServiceExtensionAbility succeed');
      });
    } catch (err) {
      commRemote = null;
      // 处理入参错误异常
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`disconnectServiceExtensionAbility failed, code is ${code}, message is ${message}`);
    }
  }
}
```

## EmbeddableUIAbilityContext.startAbilityByCall

startAbilityByCall(want: Want): Promise&lt;Caller&gt;

跨设备场景下，启动指定Ability至前台或后台，同时获取其Caller通信接口，调用方可使用Caller与被启动的Ability进行通信。使用Promise异步回调。

> **说明：**
>
> 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。
>
> EmbeddableUIAbilityContext仅在跳转启动时具备该方法。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | 传入需要启动的Ability的信息，包含abilityName、moduleName、bundleName、deviceId、parameters(可选)，parameters缺省或为空表示后台启动Ability。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[Caller](js-apis-app-ability-uiAbility.md#caller)&gt; | Promise对象，返回要通讯的caller对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |

错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**

后台启动：

```ts
import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';
import { Caller } from '@ohos.app.ability.UIAbility';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends EmbeddableUIAbility {

  onForeground() {
    let caller: Caller;

    // 后台启动Ability，不配置parameters
    let wantBackground: Want = {
      bundleName: 'com.example.myapplication',
      moduleName: 'entry',
      abilityName: 'EntryAbility',
      deviceId: ''
    };

    try {
      this.context.startAbilityByCall(wantBackground)
        .then((obj: Caller) => {
          // 执行正常业务
          caller = obj;
          console.info('startAbilityByCall succeed');
        }).catch((err: BusinessError) => {
        // 处理业务逻辑错误
        console.error(`startAbilityByCall failed, code is ${err.code}, message is ${err.message}`);
      });
    } catch (err) {
      // 处理入参错误异常
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`startAbilityByCall failed, code is ${code}, message is ${message}`);
    }
  }
}
```

前台启动：

```ts
import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';
import { Caller } from '@ohos.app.ability.UIAbility';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends EmbeddableUIAbility {

  onForeground() {
    let caller: Caller;

    // 前台启动Ability，将parameters中的'ohos.aafwk.param.callAbilityToForeground'配置为true
    let wantForeground: Want = {
      bundleName: 'com.example.myapplication',
      moduleName: 'entry',
      abilityName: 'EntryAbility',
      deviceId: '',
      parameters: {
        'ohos.aafwk.param.callAbilityToForeground': true
      }
    };

    try {
      this.context.startAbilityByCall(wantForeground)
        .then((obj: Caller) => {
          // 执行正常业务
          caller = obj;
          console.info('startAbilityByCall succeed');
        }).catch((err: BusinessError) => {
        // 处理业务逻辑错误
        console.error(`startAbilityByCall failed, code is ${err.code}, message is ${err.message}`);
      });
    } catch (err) {
      // 处理入参错误异常
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`startAbilityByCall failed, code is ${code}, message is ${message}`);
    }
  }
}
```

## EmbeddableUIAbilityContext.setMissionLabel

setMissionLabel(label: string, callback: AsyncCallback&lt;void&gt;): void

设置UIAbility在任务中显示的名称跳转启动。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

> **说明：**
>
> EmbeddableUIAbilityContext仅在跳转启动时具备该方法。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| label | string | 是 | 显示名称。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当接口调用成功，err为undefined，否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**

```ts
import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';
import Want from '@ohos.app.ability.Want';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends EmbeddableUIAbility {

  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    this.context.setMissionLabel('test', (result: BusinessError) => {
      console.info(`setMissionLabel: ${JSON.stringify(result)}`);
    });
  }
}
```

## EmbeddableUIAbilityContext.setMissionLabel

setMissionLabel(label: string): Promise&lt;void&gt;

设置UIAbility在任务中显示的名称。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

> **说明：**
>
> EmbeddableUIAbilityContext仅在跳转启动时具备该方法。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| label | string | 是 | 显示名称。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**

  ```ts
import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';
import Want from '@ohos.app.ability.Want';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends EmbeddableUIAbility {

  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    this.context.setMissionLabel('test').then(() => {
      console.info('success');
    }).catch((err: BusinessError) => {
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`setMissionLabel failed, code is ${code}, message is ${message}`);
    });
  }
}
  ```

## EmbeddableUIAbilityContext.setMissionContinueState

setMissionContinueState(state: AbilityConstant.ContinueState, callback: AsyncCallback&lt;void&gt;): void

设置UIAbility任务中流转状态跳转启动。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

> **说明：**
>
> EmbeddableUIAbilityContext仅在跳转启动时具备该方法。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| state | [AbilityConstant.ContinueState](js-apis-app-ability-abilityConstant.md#abilityconstantcontinuestate10) | 是 | 流转状态。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当接口调用成功，err为undefined，否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**

```ts
import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends EmbeddableUIAbility {
  onForeground() {
    this.context.setMissionContinueState(AbilityConstant.ContinueState.INACTIVE, (result: BusinessError) => {
      console.info(`setMissionContinueState: ${JSON.stringify(result)}`);
    });
  }
}
```

## EmbeddableUIAbilityContext.setMissionContinueState

setMissionContinueState(state: AbilityConstant.ContinueState): Promise&lt;void&gt;

设置UIAbility任务中流转状态。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

> **说明：**
>
> EmbeddableUIAbilityContext仅在跳转启动时具备该方法。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| state | [AbilityConstant.ContinueState](js-apis-app-ability-abilityConstant.md#abilityconstantcontinuestate10) | 是 | 流转状态。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**

```ts
import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends EmbeddableUIAbility {
  onForeground() {
    this.context.setMissionContinueState(AbilityConstant.ContinueState.INACTIVE).then(() => {
      console.info('success');
    }).catch((err: BusinessError) => {
      console.error(`setMissionContinueState failed, code is ${err.code}, message is ${err.message}`);
    });
  }
}
```

## EmbeddableUIAbilityContext.restoreWindowStage

restoreWindowStage(localStorage: LocalStorage): void

恢复UIAbility中的WindowStage数据。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

> **说明：**
>
> EmbeddableUIAbilityContext仅在跳转启动时具备该方法。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| localStorage | LocalStorage | 是 | 用于恢复window stage的存储数据。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**

```ts
import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';

export default class EntryAbility extends EmbeddableUIAbility {
  onForeground() {
    let storage = new LocalStorage();
    this.context.restoreWindowStage(storage);
  }
}
```

## EmbeddableUIAbilityContext.isTerminating

isTerminating(): boolean

查询UIAbility是否在terminating状态。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

> **说明：**
>
> EmbeddableUIAbilityContext仅在跳转启动时具备该方法。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | true：ability当前处于terminating状态；false：不处于terminating状态。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000011 | The context does not exist. |

错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**

```ts
import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';

export default class EntryAbility extends EmbeddableUIAbility {
  onForeground() {
    let isTerminating: boolean = this.context.isTerminating();
    console.info(`ability state is ${isTerminating}`);
  }
}
```

## EmbeddableUIAbilityContext.requestDialogService

requestDialogService(want: Want, result: AsyncCallback&lt;dialogRequest.RequestResult&gt;): void

启动一个支持模态弹框的ServiceExtensionAbility。ServiceExtensionAbility被启动后，应用弹出模态弹框，通过调用[setRequestResult](js-apis-app-ability-dialogRequest.md#requestcallbacksetrequestresult)接口返回结果给调用者。使用callback异步回调。

> **说明：**
>
> 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

> **说明：**
>
> EmbeddableUIAbilityContext仅在跳转启动时具备该方法。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-app-ability-want.md) | 是 | 启动ServiceExtensionAbility的want信息。 |
| result | AsyncCallback&lt;[dialogRequest.RequestResult](js-apis-app-ability-dialogRequest.md#requestresult)&gt; | 是 | 回调函数。当接口调用成功，err为undefined，data为获取到的模态弹框请求结果，否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation flag is forbidden. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**

```ts
import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';
import dialogRequest from '@ohos.app.ability.dialogRequest';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends EmbeddableUIAbility {
  onForeground() {
    let want: Want = {
      deviceId: '',
      bundleName: 'com.example.myapplication',
      abilityName: 'AuthAccountServiceExtension'
    };

    try {
      this.context.requestDialogService(want, (err: BusinessError, result: dialogRequest.RequestResult) => {
        if (err.code) {
          // 处理业务逻辑错误
          console.error(`requestDialogService failed, code is ${err.code}, message is ${err.message}`);
          return;
        }
        // 执行正常业务
        console.info(`requestDialogService succeed, result = ${JSON.stringify(result)}`);
      });
    } catch (err) {
      // 处理入参错误异常
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`requestDialogService failed, code is ${code}, message is ${message}`);
    }
  }
}
```

  ## EmbeddableUIAbilityContext.requestDialogService

requestDialogService(want: Want): Promise&lt;dialogRequest.RequestResult&gt;

启动一个支持模态弹框的ServiceExtensionAbility。ServiceExtensionAbility被启动后，应用弹出模态弹框，通过调用[setRequestResult](js-apis-app-ability-dialogRequest.md#requestcallbacksetrequestresult)接口返回结果给调用者。使用Promise异步回调。

> **说明：**
>
> 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

> **说明：**
>
> EmbeddableUIAbilityContext仅在跳转启动时具备该方法。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | 启动ServiceExtensionAbility的want信息。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[dialogRequest.RequestResult](js-apis-app-ability-dialogRequest.md)&gt; | Promise对象，返回模态弹框请求结果。|

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation flag is forbidden. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**

```ts
import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';
import dialogRequest from '@ohos.app.ability.dialogRequest';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends EmbeddableUIAbility {

  onForeground() {
    let want: Want = {
      bundleName: 'com.example.myapplication',
      abilityName: 'AuthAccountServiceExtension'
    };

    try {
      this.context.requestDialogService(want)
        .then((result: dialogRequest.RequestResult) => {
          // 执行正常业务
          console.info(`requestDialogService succeed, result = ${JSON.stringify(result)}`);
        })
        .catch((err: BusinessError) => {
          // 处理业务逻辑错误
          console.error(`requestDialogService failed, code is ${err.code}, message is ${err.message}`);
        });
    } catch (err) {
      // 处理入参错误异常
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`requestDialogService failed, code is ${code}, message is ${message}`);
    }
  }
}
```

## EmbeddableUIAbilityContext.reportDrawnCompleted

reportDrawnCompleted(callback: AsyncCallback\<void>): void

当页面加载完成（loadContent成功）时，为开发者提供打点功能跳转启动。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当打点成功，err为undefined，否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**

  ```ts
import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';
import window from '@ohos.window';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends EmbeddableUIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    windowStage.loadContent('pages/Index', (err, data) => {
      if (err.code) {
        return;
      }
      try {
        this.context.reportDrawnCompleted((err) => {
          if (err.code) {
            // 处理业务逻辑错误
            console.error(`reportDrawnCompleted failed, code is ${err.code}, message is ${err.message}`);
            return;
          }
          // 执行正常业务
          console.info('reportDrawnCompleted succeed');
        });
      } catch (err) {
        // 捕获同步的参数错误
        let code = (err as BusinessError).code;
        let message = (err as BusinessError).message;
        console.error(`reportDrawnCompleted failed, code is ${code}, message is ${message}`);
      }
    });
    console.log("MainAbility onWindowStageCreate")
  }
};
  ```

## EmbeddableUIAbilityContext.startAbilityByType

startAbilityByType(type: string, wantParam: Record<string, Object>,
    abilityStartCallback: AbilityStartCallback, callback: AsyncCallback\<void>): void

通过type隐式启动UIExtensionAbility。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

> **说明：**
>
> EmbeddableUIAbilityContext仅在跳转启动时具备该方法。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 显示拉起的UIExtensionAbility类型。 |
| wantParam | Record&lt;string,&nbsp;Object&gt; | 是 | 表示扩展参数。 |
| abilityStartCallback | [AbilityStartCallback](js-apis-inner-application-abilityStartCallback.md) | 是 | 启动失败后的回调。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当启动成功，err为undefined，否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000050 | Internal error. |

错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**

  ```ts
  import common from '@ohos.app.ability.common';
  let context = getContext(this) as common.EmbeddableUIAbilityContext;
  let wantParam: Record<string, Object> = {
    'time':'2023-10-23 20:45',
  };
  let abilityStartCallback: common.AbilityStartCallback = {
    onError: (code: number, name: string, message: string) => {
      console.log(`code:` + code + `name:` + name + `message:` + message);
    }
  }
  context.startAbilityByType("photoEditor", wantParam, abilityStartCallback, (err) => {
    if (err) {
      console.error(`startAbilityByType fail, err: ${JSON.stringify(err)}`);
    } else {
      console.log(`success`);
    }
  });
  ```

## EmbeddableUIAbilityContext.startAbilityByType

startAbilityByType(type: string, wantParam: Record<string, Object>,
    abilityStartCallback: AbilityStartCallback): Promise\<void>

通过type隐式启动UIExtensionAbility。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

> **说明：**
>
> EmbeddableUIAbilityContext仅在跳转启动时具备该方法。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 显示拉起的UIExtensionAbility类型。 |
| wantParam | Record&lt;string,&nbsp;Object&gt; | 是 | 表示扩展参数。 |
| abilityStartCallback | [AbilityStartCallback](js-apis-inner-application-abilityStartCallback.md) | 是 | 启动失败后的回调。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000050 | Internal error. |

错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**

  ```ts
  import common from '@ohos.app.ability.common';
  import { BusinessError } from '@ohos.base';
  let context = getContext(this) as common.EmbeddableUIAbilityContext;
  let wantParam: Record<string, Object> = {
    'time':'2023-10-23 20:45',
  };
  let abilityStartCallback: common.AbilityStartCallback = {
    onError: (code: number, name: string, message: string) => {
      console.log(`code:` + code + `name:` + name + `message:` + message);
    }
  }
  context.startAbilityByType("photoEditor", wantParam, abilityStartCallback).then(() => {
    console.log(`startAbilityByType success`);
  }).catch((err: BusinessError) => {
    console.error(`startAbilityByType fail, err: ${JSON.stringify(err)}`);
  })
  ```
## EmbeddableUIAbilityContext.showAbility

showAbility(): Promise\<void>

显示当前Ability。使用Promise异步回调。仅在平板类设备上生效。

调用此接口要求当前Ability必须通过[EmbeddableUIAbilityContext.startAbility](#embeddableuiabilitycontextstartability)启动，且启动入参中[options.processMode](js-apis-app-ability-contextConstant.md#contextconstantprocessmode12)必须设置为NEW_PROCESS_ATTACH_TO_STATUS_BAR_ITEM。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

> **说明：**
>
> EmbeddableUIAbilityContext仅在跳转启动时具备该方法。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000050 | Internal error. |
| 16000067 | Start options check failed. |

错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**

  ```ts
  import common from '@ohos.app.ability.common';
  import { BusinessError } from '@ohos.base';
  let context = getContext(this) as common.EmbeddableUIAbilityContext;
  context.showAbility().then(() => {
    console.log(`showAbility success`);
  }).catch((err: BusinessError) => {
    console.error(`showAbility fail, err: ${JSON.stringify(err)}`);
  })
  ```
## EmbeddableUIAbilityContext.hideAbility

hideAbility(): Promise\<void>

隐藏当前Ability。使用Promise异步回调。仅在平板类设备上生效。

调用此接口要求当前Ability必须通过[EmbeddableUIAbilityContext.startAbility](#embeddableuiabilitycontextstartability)启动，且启动入参中[options.processMode](js-apis-app-ability-contextConstant.md#contextconstantprocessmode12)必须设置为NEW_PROCESS_ATTACH_TO_STATUS_BAR_ITEM。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

> **说明：**
>
> EmbeddableUIAbilityContext仅在跳转启动时具备该方法。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000050 | Internal error. |
| 16000067 | Start options check failed. |

错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**

  ```ts
  import common from '@ohos.app.ability.common';
  import { BusinessError } from '@ohos.base';
  let context = getContext(this) as common.EmbeddableUIAbilityContext;
  context.hideAbility().then(() => {
    console.log(`hideAbility success`);
  }).catch((err: BusinessError) => {
    console.error(`hideAbility fail, err: ${JSON.stringify(err)}`);
  })
  ```

## EmbeddableUIAbilityContext.moveAbilityToBackground
moveAbilityToBackground(): Promise\<void>

将处于前台的Ability移动到后台。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

> **说明：**
>
> EmbeddableUIAbilityContext仅在跳转启动时具备该方法。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |
| 16000061 | Operation not supported. |
| 16000065 | The interface can be called only when ability is foreground. |
| 16000066 | An ability cannot move to foreground or background in Wukong mode. |

以上错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**

```ts
import common from '@ohos.app.ability.common';
import { BusinessError } from '@ohos.base';

@Entry
@Component
struct Index {
  @State moveAbilityToBackground: string = 'Move To Background'

  build() {
    Row() {
      Column() {
        Text(this.moveAbilityToBackground)
          .fontSize(30)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            let context = getContext(this) as common.EmbeddableUIAbilityContext;
            context.moveAbilityToBackground().then(() => {
              console.log(`moveAbilityToBackground success.`);
            }).catch((err: BusinessError) => {
              console.log(`moveAbilityToBackground error: ${JSON.stringify(err)}.`)
            });
          });
      }
      .width('100%')
    }
    .height('100%')
  }
}
```