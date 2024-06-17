# UIExtensionContext

UIExtensionContext是[UIExtensionAbility](js-apis-app-ability-uiExtensionAbility.md)的上下文环境，继承自[ExtensionContext](js-apis-inner-application-extensionContext.md)，提供UIExtensionAbility的相关配置信息以及操作UIAbility的方法，如启动UIAbility等。

> **说明：**
>
>  - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>  - 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import common from '@ohos.app.ability.common';
```

## UIExtensionContext.startAbility

startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void

启动Ability。使用callback异步回调。

> **说明：**
>
> 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

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
import UIExtensionAbility from '@ohos.app.ability.UIExtensionAbility';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends UIExtensionAbility {
  
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

## UIExtensionContext.startAbility

startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;): void

启动Ability。使用callback异步回调。

> **说明：**
>
> 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md)  | 是 | 启动Ability的want信息。 |
| options | [StartOptions](js-apis-app-ability-startOptions.md) | 是 | 启动Ability所携带的参数。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当启动Ability成功，err为undefined，否则为错误对象。 |

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
| 16200001 | The caller has been released. |

错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**

```ts
import UIExtensionAbility from '@ohos.app.ability.UIExtensionAbility';
import Want from '@ohos.app.ability.Want';
import StartOptions from '@ohos.app.ability.StartOptions';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends UIExtensionAbility {

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

## UIExtensionContext.startAbility

startAbility(want: Want, options?: StartOptions): Promise&lt;void&gt;

启动Ability。使用Promise异步回调。

> **说明：**
>
> 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

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
| 16200001 | The caller has been released. |

错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**

```ts
import UIExtensionAbility from '@ohos.app.ability.UIExtensionAbility';
import Want from '@ohos.app.ability.Want';
import StartOptions from '@ohos.app.ability.StartOptions';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends UIExtensionAbility {

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

## UIExtensionContext.startAbilityForResult

startAbilityForResult(want: Want, callback: AsyncCallback&lt;AbilityResult&gt;): void

启动一个Ability。使用callback异步回调。Ability被启动后，有如下情况:
 - 正常情况下可通过调用[terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult)接口使之终止并且返回结果给调用方。
 - 异常情况下比如杀死Ability会返回异常信息给调用方, 异常信息中resultCode为-1。
 - 如果被启动的Ability模式是单实例模式, 不同应用多次调用该接口启动这个Ability，当这个Ability调用[terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult)接口使之终止时，只将正常结果返回给最后一个调用方, 其它调用方返回异常信息, 异常信息中resultCode为-1。

> **说明：**
>
> 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-app-ability-want.md) | 是 | 启动Ability的want信息。 |
| callback | AsyncCallback&lt;[AbilityResult](js-apis-inner-ability-abilityResult.md)&gt; | 是 | 回调函数，返回启动Ability的结果。 |

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
import UIExtensionAbility from '@ohos.app.ability.UIExtensionAbility';
import common from '@ohos.app.ability.common';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends UIExtensionAbility {

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

## UIExtensionContext.startAbilityForResult

startAbilityForResult(want: Want, options: StartOptions, callback: AsyncCallback&lt;AbilityResult&gt;): void

启动一个Ability。使用callback异步回调。Ability被启动后，有如下情况:
 - 正常情况下可通过调用[terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult)接口使之终止并且返回结果给调用方。
 - 异常情况下比如杀死Ability会返回异常信息给调用方，异常信息中resultCode为-1。
 - 如果被启动的Ability模式是单实例模式, 不同应用多次调用该接口启动这个Ability，当这个Ability调用[terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult)接口使之终止时，只将正常结果返回给最后一个调用方，其它调用方返回异常信息, 异常信息中resultCode为-1。

> **说明：**
>
> 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-app-ability-want.md) | 是 | 启动Ability的want信息。 |
| options | [StartOptions](js-apis-app-ability-startOptions.md) | 是 | 启动Ability所携带的参数。 |
| callback | AsyncCallback&lt;[AbilityResult](js-apis-inner-ability-abilityResult.md)&gt; | 是 | 回调函数，返回启动Ability的结果。 |

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
import UIExtensionAbility from '@ohos.app.ability.UIExtensionAbility';
import common from '@ohos.app.ability.common';
import Want from '@ohos.app.ability.Want';
import StartOptions from '@ohos.app.ability.StartOptions';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends UIExtensionAbility {

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

## UIExtensionContext.startAbilityForResult

startAbilityForResult(want: Want, options?: StartOptions): Promise&lt;AbilityResult&gt;

启动一个Ability。使用Promise异步回调。Ability被启动后，有如下情况:
 - 正常情况下可通过调用[terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult)接口使之终止并且返回结果给调用方。
 - 异常情况下比如杀死Ability会返回异常信息给调用方, 异常信息中resultCode为-1。
 - 如果被启动的Ability模式是单实例模式, 不同应用多次调用该接口启动这个Ability，当这个Ability调用[terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult)接口使之终止时，只将正常结果返回给最后一个调用方, 其它调用方返回异常信息, 异常信息中resultCode为-1。

> **说明：**
>
> 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | 启动Ability的want信息。 |
| options | [StartOptions](js-apis-app-ability-startOptions.md) | 否 | 启动Ability所携带的参数。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[AbilityResult](js-apis-inner-ability-abilityResult.md)&gt; | Promise对象，返回启动Ability的结果。 |

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
import UIExtensionAbility from '@ohos.app.ability.UIExtensionAbility';
import common from '@ohos.app.ability.common';
import Want from '@ohos.app.ability.Want';
import StartOptions from '@ohos.app.ability.StartOptions';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends UIExtensionAbility {

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


## UIExtensionContext.connectServiceExtensionAbility

connectServiceExtensionAbility(want: Want, options: ConnectOptions): number

将当前Ability连接到一个ServiceExtensionAbility。

> **说明：**
>
> 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。

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
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16000011 | The context does not exist.        |
| 16000050 | Internal error. |

错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**

```ts
import UIExtensionAbility from '@ohos.app.ability.UIExtensionAbility';
import common from '@ohos.app.ability.common';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';
import rpc from '@ohos.rpc';

export default class EntryAbility extends UIExtensionAbility {

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

## UIExtensionContext.disconnectServiceExtensionAbility

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
import UIExtensionAbility from '@ohos.app.ability.UIExtensionAbility';
import { BusinessError } from '@ohos.base';
import rpc from '@ohos.rpc';

export default class EntryAbility extends UIExtensionAbility {

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

## UIExtensionContext.disconnectServiceExtensionAbility

disconnectServiceExtensionAbility(connection: number, callback: AsyncCallback\<void>): void

断开与ServiceExtensionAbility的连接，断开连接之后需要将连接成功时返回的remote对象置空。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| connection | number | 是 | 连接的ServiceExtensionAbility的数字代码，即connectServiceExtensionAbility返回的connectionId。 |
| callback | AsyncCallback\<void> | 是 | 回调函数。当断开与ServiceExtensionAbility的连接成功，err为undefined，否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**

```ts
import UIExtensionAbility from '@ohos.app.ability.UIExtensionAbility';
import { BusinessError } from '@ohos.base';
import rpc from '@ohos.rpc';

export default class EntryAbility extends UIExtensionAbility {

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
