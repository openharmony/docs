# UIAbilityContext

UIAbilityContext是需要保存状态的[UIAbility](js-apis-app-ability-uiAbility.md)所对应的context，继承自[Context](js-apis-inner-application-context.md)，提供UIAbility的相关配置信息以及操作UIAbility和ServiceExtensionAbility的方法，如启动UIAbility，停止当前UIAbilityContext所属的UIAbility，启动、停止、连接、断开连接ServiceExtensionAbility等。

> **说明：**
>
>  - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>  - 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { common } from '@kit.AbilityKit';
```

## 属性

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| abilityInfo | [AbilityInfo](js-apis-bundleManager-abilityInfo.md) | 是 | 否 | UIAbility的相关信息。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| currentHapModuleInfo | [HapModuleInfo](js-apis-bundleManager-hapModuleInfo.md) | 是 | 否 | 当前HAP的信息。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| config | [Configuration](js-apis-app-ability-configuration.md) | 是 | 否 | 与UIAbility相关的配置信息，如语言、颜色模式等。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| windowStage<sup>12+</sup> | [window.WindowStage](../apis-arkui/js-apis-window.md#windowstage9) | 是 | 否 | 当前WindowStage对象。仅支持在主线程调用。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。|

> **关于示例代码的说明：**
>
> 在本文档的示例中，通过`this.context`来获取`UIAbilityContext`，其中`this`代表继承自`UIAbility`的`UIAbility`实例。如需要在页面中使用`UIAbilityContext`提供的能力，请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

## UIAbilityContext.startAbility

startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void

启动Ability。使用callback异步回调。仅支持在主线程调用。

> **说明：**
>
> 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | 启动Ability的want信息。 |
| callback | AsyncCallback&lt;void&gt; | 是 | callback形式返回启动结果。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Cannot start an invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation and prepare continuation flag is forbidden. |
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000018 | Redirection to a third-party application is not allowed in API version 11 or later. |
| 16000019 | No matching ability is found. |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16000071 | App clone is not supported. |
| 16000072 | App clone or multi-instance is not supported. |
| 16000073 | The app clone index is invalid. |
| 16000076 | The app instance key is invalid. |
| 16000077 | The number of app instances reaches the limit. |
| 16000078 | The multi-instance is not supported. |
| 16000079 | The APP_INSTANCE_KEY cannot be specified. |
| 16000080 | Creating a new instance is not supported. |
| 16200001 | The caller has been released. |

**示例：**

```ts
import { UIAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
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

## UIAbilityContext.startAbility

startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;): void

启动Ability。使用callback异步回调。仅支持在主线程调用。

> **说明：**
>
> 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md)  | 是 | 启动Ability的want信息。 |
| options | [StartOptions](js-apis-app-ability-startOptions.md) | 是 | 启动Ability所携带的参数。 |
| callback | AsyncCallback&lt;void&gt; | 是 | callback形式返回启动结果。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 801 | Capability not support. |
| 16000001 | The specified ability does not exist. |
| 16000004 | Cannot start an invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000018 | Redirection to a third-party application is not allowed in API version 11 or later. |
| 16000019 | No matching ability is found. |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16000067 | The StartOptions check failed. |
| 16000068 | The ability is already running. |
| 16300003 | The target application is not the current application. |
| 16000071 | App clone is not supported. |
| 16000072 | App clone or multi-instance is not supported. |
| 16000073 | The app clone index is invalid. |
| 16000076 | The app instance key is invalid. |
| 16000077 | The number of app instances reaches the limit. |
| 16000078 | The multi-instance is not supported. |
| 16000079 | The APP_INSTANCE_KEY cannot be specified. |
| 16000080 | Creating a new instance is not supported. |
| 16200001 | The caller has been released. |

**示例：**

```ts
import { UIAbility, Want, StartOptions } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
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

## UIAbilityContext.startAbility

startAbility(want: Want, options?: StartOptions): Promise&lt;void&gt;

启动Ability。使用Promise异步回调。仅支持在主线程调用。

> **说明：**
>
> 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | 启动Ability的want信息。 |
| options | [StartOptions](js-apis-app-ability-startOptions.md) | 否 | 启动Ability所携带的参数。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise形式返回启动结果。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 801 | Capability not support. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Cannot start an invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation and prepare continuation flag is forbidden.  |
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000018 | Redirection to a third-party application is not allowed in API version 11 or later. |
| 16000019 | No matching ability is found. |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16000067 | The StartOptions check failed. |
| 16000068 | The ability is already running. |
| 16300003 | The target application is not the current application. |
| 16000071 | App clone is not supported. |
| 16000072 | App clone or multi-instance is not supported. |
| 16000073 | The app clone index is invalid. |
| 16000076 | The app instance key is invalid. |
| 16000077 | The number of app instances reaches the limit. |
| 16000078 | The multi-instance is not supported. |
| 16000079 | The APP_INSTANCE_KEY cannot be specified. |
| 16000080 | Creating a new instance is not supported. |
| 16200001 | The caller has been released. |

**示例：**

```ts
import { UIAbility, Want, StartOptions } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onForeground() {
    let want: Want = {
      bundleName: 'com.example.myapplication',
      abilityName: 'EntryAbility'
    };
    let options: StartOptions = {
      displayId: 0
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

## UIAbilityContext.startAbilityForResult

startAbilityForResult(want: Want, callback: AsyncCallback&lt;AbilityResult&gt;): void

启动一个Ability。使用callback异步回调。仅支持在主线程调用。

Ability被启动后，有如下情况：
 - 正常情况下可通过调用[terminateSelfWithResult](#uiabilitycontextterminateselfwithresult)接口使之终止并且返回结果给调用方。
 - 异常情况下比如杀死Ability会返回异常信息给调用方, 异常信息中resultCode为-1。
 - 如果被启动的Ability模式是单实例模式, 不同应用多次调用该接口启动这个Ability，当这个Ability调用[terminateSelfWithResult](#uiabilitycontextterminateselfwithresult)接口使之终止时，只将正常结果返回给最后一个调用方, 其它调用方返回异常信息, 异常信息中resultCode为-1。

> **说明：**
>
> 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-app-ability-want.md) | 是 | 启动Ability的want信息。 |
| callback | AsyncCallback&lt;[AbilityResult](js-apis-inner-ability-abilityResult.md)&gt; | 是 | 执行结果回调函数。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Cannot start an invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation and prepare continuation flag is forbidden. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000018 | Redirection to a third-party application is not allowed in API version 11 or later. |
| 16000019 | No matching ability is found. |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16000071 | App clone is not supported. |
| 16000072 | App clone or multi-instance is not supported. |
| 16000073 | The app clone index is invalid. |
| 16000076 | The app instance key is invalid. |
| 16000077 | The number of app instances reaches the limit. |
| 16000078 | The multi-instance is not supported. |
| 16000079 | The APP_INSTANCE_KEY cannot be specified. |
| 16000080 | Creating a new instance is not supported. |
| 16200001 | The caller has been released. |

**示例：**

```ts
import { UIAbility, Want, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
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

## UIAbilityContext.startAbilityForResult

startAbilityForResult(want: Want, options: StartOptions, callback: AsyncCallback&lt;AbilityResult&gt;): void

启动一个Ability。使用callback异步回调。仅支持在主线程调用。

Ability被启动后，有如下情况：
 - 正常情况下可通过调用[terminateSelfWithResult](#uiabilitycontextterminateselfwithresult)接口使之终止并且返回结果给调用方。
 - 异常情况下比如杀死Ability会返回异常信息给调用方，异常信息中resultCode为-1。
 - 如果被启动的Ability模式是单实例模式, 不同应用多次调用该接口启动这个Ability，当这个Ability调用[terminateSelfWithResult](#uiabilitycontextterminateselfwithresult)接口使之终止时，只将正常结果返回给最后一个调用方，其它调用方返回异常信息, 异常信息中resultCode为-1。

> **说明：**
>
> 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-app-ability-want.md) | 是 | 启动Ability的want信息。 |
| options | [StartOptions](js-apis-app-ability-startOptions.md) | 是 | 启动Ability所携带的参数。 |
| callback | AsyncCallback&lt;[AbilityResult](js-apis-inner-ability-abilityResult.md)&gt; | 是 | 执行结果回调函数。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000001 | The specified ability does not exist. |
| 16000004 | Cannot start an invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000018 | Redirection to a third-party application is not allowed in API version 11 or later. |
| 16000019 | No matching ability is found. |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16000071 | App clone is not supported. |
| 16000072 | App clone or multi-instance is not supported. |
| 16000073 | The app clone index is invalid. |
| 16000076 | The app instance key is invalid. |
| 16000077 | The number of app instances reaches the limit. |
| 16000078 | The multi-instance is not supported. |
| 16000079 | The APP_INSTANCE_KEY cannot be specified. |
| 16000080 | Creating a new instance is not supported. |
| 16200001 | The caller has been released. |

**示例：**

```ts
import { UIAbility, Want, common, StartOptions } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
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


## UIAbilityContext.startAbilityForResult

startAbilityForResult(want: Want, options?: StartOptions): Promise&lt;AbilityResult&gt;

启动一个Ability。使用Promise异步回调。仅支持在主线程调用。

Ability被启动后，有如下情况：
 - 正常情况下可通过调用[terminateSelfWithResult](#uiabilitycontextterminateselfwithresult)接口使之终止并且返回结果给调用方。
 - 异常情况下比如杀死Ability会返回异常信息给调用方, 异常信息中resultCode为-1。
 - 如果被启动的Ability模式是单实例模式, 不同应用多次调用该接口启动这个Ability，当这个Ability调用[terminateSelfWithResult](#uiabilitycontextterminateselfwithresult)接口使之终止时，只将正常结果返回给最后一个调用方, 其它调用方返回异常信息, 异常信息中resultCode为-1。

> **说明：**
>
> 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | 启动Ability的want信息。 |
| options | [StartOptions](js-apis-app-ability-startOptions.md) | 否 | 启动Ability所携带的参数。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[AbilityResult](js-apis-inner-ability-abilityResult.md)&gt; | Promise形式返回执行结果。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Cannot start an invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation and prepare continuation flag is forbidden. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000018 | Redirection to a third-party application is not allowed in API version 11 or later. |
| 16000019 | No matching ability is found. |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16000071 | App clone is not supported. |
| 16000072 | App clone or multi-instance is not supported. |
| 16000073 | The app clone index is invalid. |
| 16000076 | The app instance key is invalid. |
| 16000077 | The number of app instances reaches the limit. |
| 16000078 | The multi-instance is not supported. |
| 16000079 | The APP_INSTANCE_KEY cannot be specified. |
| 16000080 | Creating a new instance is not supported. |
| 16200001 | The caller has been released. |

**示例：**

```ts
import { UIAbility, Want, common, StartOptions } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onForeground() {
    let want: Want = {
      bundleName: 'com.example.myapplication',
      abilityName: 'EntryAbility'
    };
    let options: StartOptions = {
      displayId: 0
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

## UIAbilityContext.terminateSelf

terminateSelf(callback: AsyncCallback&lt;void&gt;): void

停止Ability自身。使用callback异步回调。仅支持在主线程调用。

> **说明：**
>
> 调用该接口后，任务中心的任务默认不会清理，如需清理，需要配置[removeMissionAfterTerminate](../../quick-start/module-configuration-file.md#abilities标签)为true。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | 是 | 停止Ability自身的回调函数。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

**示例：**

1. 使用terminateSelf接口停止UIAbility示例代码如下，默认情况下应用会在最近任务列表中保留快照。

    ```ts
    import { UIAbility } from '@kit.AbilityKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    export default class EntryAbility extends UIAbility {
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

2. （可选）如果需要在停止UIAbility时，清理任务中心的相关任务（即不保留最近任务列表中的快照），需要在[module.json5](../../quick-start/module-configuration-file.md)配置文件中将removeMissionAfterTerminate字段取值配置为true。

    ```json
    { 
      "module": { 
        // ... 
        "abilities": [
          {
            // ...
            "removeMissionAfterTerminate": true
          }
        ]
      }
    }
    ```

## UIAbilityContext.terminateSelf

terminateSelf(): Promise&lt;void&gt;

停止Ability自身。使用Promise异步回调。仅支持在主线程调用。

> **说明：**
>
> 调用该接口后，任务中心的任务默认不会清理，如需清理，需要配置[removeMissionAfterTerminate](../../quick-start/module-configuration-file.md#abilities标签)为true。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 停止Ability自身的回调函数。 |

**错误码：**

以下错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |


**示例：**

1. 使用terminateSelf接口停止UIAbility示例代码如下，默认情况下应用会在最近任务列表中保留快照。

    ```ts
    import { UIAbility } from '@kit.AbilityKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    export default class EntryAbility extends UIAbility {
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

2. （可选）如果需要在停止UIAbility时，清理任务中心的相关任务（即不保留最近任务列表中的快照），需要在[module.json5](../../quick-start/module-configuration-file.md)配置文件中将removeMissionAfterTerminate字段取值配置为true。

    ```json
    {
      "module": {
        // ...
        "abilities": [
          {
            // ...
            "removeMissionAfterTerminate": true
          }
        ]
      }
    }
    ```

## UIAbilityContext.terminateSelfWithResult

terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback&lt;void&gt;): void

停止当前的Ability。使用callback异步回调。仅支持在主线程调用。

如果该Ability是通过调用[startAbilityForResult](#uiabilitycontextstartabilityforresult)接口被拉起的，调用terminateSelfWithResult接口时会将结果返回给调用者，如果该Ability不是通过调用[startAbilityForResult](#uiabilitycontextstartabilityforresult)接口被拉起的，调用terminateSelfWithResult接口时不会有结果返回给调用者。

> **说明：**
>
> 调用该接口后，任务中心的任务默认不会清理，如需清理，需要配置[removeMissionAfterTerminate](../../quick-start/module-configuration-file.md#abilities标签)为true。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| parameter | [AbilityResult](js-apis-inner-ability-abilityResult.md) | 是 | 返回给调用startAbilityForResult&nbsp;接口调用方的相关信息。 |
| callback | AsyncCallback&lt;void&gt; | 是 | callback形式返回停止结果。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |


**示例：**

```ts
import { UIAbility, Want, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
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


## UIAbilityContext.terminateSelfWithResult

terminateSelfWithResult(parameter: AbilityResult): Promise&lt;void&gt;

停止当前的Ability。使用Promise异步回调。仅支持在主线程调用。

如果该Ability是通过调用[startAbilityForResult](#uiabilitycontextstartabilityforresult)接口被拉起的，调用terminateSelfWithResult接口时会将结果返回给调用者，如果该Ability不是通过调用[startAbilityForResult](#uiabilitycontextstartabilityforresult)接口被拉起的，调用terminateSelfWithResult接口时不会有结果返回给调用者。

> **说明：**
>
> 调用该接口后，任务中心的任务默认不会清理，如需清理，需要配置[removeMissionAfterTerminate](../../quick-start/module-configuration-file.md#abilities标签)为true。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| parameter | [AbilityResult](js-apis-inner-ability-abilityResult.md) | 是 | 返回给startAbilityForResult&nbsp;调用方的信息。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | promise形式返回停止结果。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |


**示例：**

```ts
import { UIAbility, Want, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
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

## UIAbilityContext.connectServiceExtensionAbility

connectServiceExtensionAbility(want: Want, options: ConnectOptions): number

将当前Ability连接到一个ServiceExtensionAbility。仅支持在主线程调用。

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

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Cannot start an invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000011 | The context does not exist.        |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |

**示例：**

```ts
import { UIAbility, Want, common } from '@kit.AbilityKit';
import { rpc } from '@kit.IPCKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
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
        console.info('onConnect...');
      },
      onDisconnect(elementName) {
        console.info('onDisconnect...');
      },
      onFailed(code) {
        console.info('onFailed...');
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

## UIAbilityContext.disconnectServiceExtensionAbility

disconnectServiceExtensionAbility(connection: number): Promise\<void>

断开与ServiceExtensionAbility的连接，断开连接之后需要将连接成功时返回的remote对象置空。使用Promise异步回调。仅支持在主线程调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| connection | number | 是 | 连接的ServiceExtensionAbility的数字代码，即connectServiceExtensionAbility返回的connectionId。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | 返回执行结果。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { rpc } from '@kit.IPCKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
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

## UIAbilityContext.disconnectServiceExtensionAbility

disconnectServiceExtensionAbility(connection: number, callback: AsyncCallback\<void>): void

断开与ServiceExtensionAbility的连接，断开连接之后需要将连接成功时返回的remote对象置空。使用callback异步回调。仅支持在主线程调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| connection | number | 是 | 连接的ServiceExtensionAbility的数字代码，即connectServiceExtensionAbility返回的connectionId。 |
| callback | AsyncCallback\<void> | 是 | callback形式返回断开连接的结果。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { rpc } from '@kit.IPCKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
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

## UIAbilityContext.startAbilityByCall

startAbilityByCall(want: Want): Promise&lt;Caller&gt;

启动指定Ability至前台或后台，同时获取其Caller通信接口，调用方可使用Caller与被启动的Ability进行通信。使用Promise异步回调。仅支持在主线程调用。
该接口不支持拉起启动模式为[specified模式](../../application-models/uiability-launch-type.md#specified启动模式)的UIAbility。

> **说明：**
>
> - 跨设备场景下，调用方与目标方必须为同一应用，且具备ohos.permission.DISTRIBUTED_DATASYNC权限，才能启动成功。
>
> - 同设备场景下，调用方与目标方必须为不同应用，且具备ohos.permission.ABILITY_BACKGROUND_COMMUNICATION权限（该权限仅系统应用可申请），才能启动成功。
>
> - 如果调用方位于后台，还需要具备ohos.permission.START_ABILITIES_FROM_BACKGROUND（该权限仅系统应用可申请）。更多的组件启动规则详见[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。

**需要权限**：ohos.permission.DISTRIBUTED_DATASYNC

> **说明：**
>
> API version 11之前的版本，该接口需要申请权限ohos.permission.ABILITY_BACKGROUND_COMMUNICATION（该权限仅系统应用可申请）。从API version 11开始，该接口需要申请的权限变更为ohos.permission.DISTRIBUTED_DATASYNC权限。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | 传入需要启动的Ability的信息，包含abilityName、moduleName、bundleName、deviceId、parameters(可选)，parameters缺省或为空表示后台启动Ability。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[Caller](js-apis-app-ability-uiAbility.md#caller)&gt; | 获取要通讯的caller对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Cannot start an invisible component. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000018 | Redirection to a third-party application is not allowed in API version 11 or later. |
| 16000050 | Internal error. |
| 16000071 | App clone is not supported. |
| 16000072 | App clone or multi-instance is not supported. |
| 16000073 | The app clone index is invalid. |
| 16000076 | The app instance key is invalid. |
| 16000077 | The number of app instances reaches the limit. |
| 16000078 | The multi-instance is not supported. |
| 16000079 | The APP_INSTANCE_KEY cannot be specified. |
| 16000080 | Creating a new instance is not supported. |

**示例：**

后台启动：

```ts
import { UIAbility, Caller, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
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
import { UIAbility, Caller, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
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

## UIAbilityContext.setMissionLabel

setMissionLabel(label: string, callback: AsyncCallback&lt;void&gt;): void

设置UIAbility在任务中显示的名称。使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| label | string | 是 | 显示名称。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，返回接口调用是否成功的结果。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

**示例：**

```ts
import { UIAbility, AbilityConstant, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    this.context.setMissionLabel('test', (result: BusinessError) => {
      console.info(`setMissionLabel: ${JSON.stringify(result)}`);
    });
  }
}
```

## UIAbilityContext.setMissionLabel

setMissionLabel(label: string): Promise&lt;void&gt;

设置UIAbility在任务中显示的名称。使用Promise异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| label | string | 是 | 显示名称。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 返回一个Promise，包含接口的结果。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

**示例：**

```ts
import { UIAbility, AbilityConstant, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
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

## UIAbilityContext.setMissionContinueState<sup>10+</sup>

setMissionContinueState(state: AbilityConstant.ContinueState, callback: AsyncCallback&lt;void&gt;): void

设置UIAbility任务中流转状态。使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| state | [AbilityConstant.ContinueState](js-apis-app-ability-abilityConstant.md#continuestate10) | 是 | 流转状态。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，返回接口调用是否成功的结果。 |

**错误码：**

错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

**示例：**

```ts
import { UIAbility, AbilityConstant } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onForeground() {
    this.context.setMissionContinueState(AbilityConstant.ContinueState.INACTIVE, (result: BusinessError) => {
      console.info(`setMissionContinueState: ${JSON.stringify(result)}`);
    });
  }
}
```

## UIAbilityContext.setMissionContinueState<sup>10+</sup>

setMissionContinueState(state: AbilityConstant.ContinueState): Promise&lt;void&gt;

设置UIAbility任务中流转状态。使用Promise异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| state | [AbilityConstant.ContinueState](js-apis-app-ability-abilityConstant.md#continuestate10) | 是 | 流转状态。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 返回一个Promise，包含接口的结果。 |

**错误码：**

错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

**示例：**

```ts
import { UIAbility, AbilityConstant } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onForeground() {
    this.context.setMissionContinueState(AbilityConstant.ContinueState.INACTIVE).then(() => {
      console.info('success');
    }).catch((err: BusinessError) => {
      console.error(`setMissionContinueState failed, code is ${err.code}, message is ${err.message}`);
    });
  }
}
```

## UIAbilityContext.restoreWindowStage

restoreWindowStage(localStorage: LocalStorage): void

恢复UIAbility中的WindowStage数据。仅支持在主线程调用。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| localStorage | LocalStorage | 是 | 用于恢复window stage的存储数据。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  onForeground() {
    let storage = new LocalStorage();
    this.context.restoreWindowStage(storage);
  }
}
```

## UIAbilityContext.isTerminating

isTerminating(): boolean

查询UIAbility是否在terminating状态。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | true：ability当前处于terminating状态；false：不处于terminating状态。 |

**错误码：**

以下错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000011 | The context does not exist. |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  onForeground() {
    let isTerminating: boolean = this.context.isTerminating();
    console.info(`ability state is ${isTerminating}`);
  }
}
```

## UIAbilityContext.requestDialogService

requestDialogService(want: Want, result: AsyncCallback&lt;dialogRequest.RequestResult&gt;): void

启动一个支持模态弹框的ServiceExtensionAbility。ServiceExtensionAbility被启动后，应用弹出模态弹框，通过调用[setRequestResult](js-apis-app-ability-dialogRequest.md#requestcallbacksetrequestresult)接口返回结果给调用者。使用callback异步回调。仅支持在主线程调用。

> **说明：**
>
> 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-app-ability-want.md) | 是 | 启动ServiceExtensionAbility的want信息。 |
| result | AsyncCallback&lt;[dialogRequest.RequestResult](js-apis-app-ability-dialogRequest.md#requestresult)&gt; | 是 | 执行结果回调函数。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Cannot start an invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation and prepare continuation flag is forbidden. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

**示例：**

```ts
import { UIAbility, Want, dialogRequest } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
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

  ## UIAbilityContext.requestDialogService

requestDialogService(want: Want): Promise&lt;dialogRequest.RequestResult&gt;

启动一个支持模态弹框的ServiceExtensionAbility。ServiceExtensionAbility被启动后，应用弹出模态弹框，通过调用[setRequestResult](js-apis-app-ability-dialogRequest.md#requestcallbacksetrequestresult)接口返回结果给调用者。使用Promise异步回调。仅支持在主线程调用。

> **说明：**
>
> 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | 启动ServiceExtensionAbility的want信息。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[dialogRequest.RequestResult](js-apis-app-ability-dialogRequest.md)&gt; | Promise形式返回执行结果。

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Cannot start an invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation and prepare continuation flag is forbidden. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

**示例：**

```ts
import { UIAbility, Want, dialogRequest } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
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

## UIAbilityContext.reportDrawnCompleted<sup>10+</sup>

reportDrawnCompleted(callback: AsyncCallback\<void>): void

当页面加载完成（loadContent成功）时，为开发者提供打点功能。使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | 是 | 页面加载完成打点的回调函数。 |

**错误码：**

以下错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
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
    console.log("MainAbility onWindowStageCreate");
  }
};
```

## UIAbilityContext.startAbilityByType<sup>11+</sup>

startAbilityByType(type: string, wantParam: Record<string, Object>,
    abilityStartCallback: AbilityStartCallback, callback: AsyncCallback\<void>) : void

通过type隐式启动UIExtensionAbility。使用callback异步回调。仅支持在主线程调用，仅支持处于前台的应用调用。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 显示拉起的UIExtensionAbility类型，取值详见[通过startAbilityByType接口拉起垂类面板](../../application-models/start-intent-panel.md#匹配规则)。 |
| wantParam | Record&lt;string,&nbsp;Object&gt; | 是 | 表示扩展参数。 |
| abilityStartCallback | [AbilityStartCallback](js-apis-inner-application-abilityStartCallback.md) | 是 | 执行结果回调函数。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，返回接口调用是否成功的结果。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000050 | Internal error. |

**示例：**

```ts
import { UIAbility, common } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  onForeground() {
    let wantParam: Record<string, Object> = {
      'time': '2023-10-23 20:45'
    };
    let abilityStartCallback: common.AbilityStartCallback = {
      onError: (code: number, name: string, message: string) => {
        console.log(`code:` + code + `name:` + name + `message:` + message);
      },
      onResult: (abilityResult: common.AbilityResult) => {
        console.log(`resultCode:` + abilityResult.resultCode + `bundleName:` + abilityResult.want?.bundleName);
      }
    };

    this.context.startAbilityByType("photoEditor", wantParam, abilityStartCallback, (err) => {
      if (err) {
        console.error(`startAbilityByType fail, err: ${JSON.stringify(err)}`);
      } else {
        console.log(`success`);
      }
    });
  }
}
```

## UIAbilityContext.startAbilityByType<sup>11+</sup>

startAbilityByType(type: string, wantParam: Record<string, Object>,
    abilityStartCallback: AbilityStartCallback) : Promise\<void>

通过type隐式启动UIExtensionAbility。使用Promise异步回调。仅支持在主线程调用，仅支持处于前台的应用调用。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 显示拉起的UIExtensionAbility类型，取值详见[通过startAbilityByType接口拉起垂类面板](../../application-models/start-intent-panel.md#匹配规则)。 |
| wantParam | Record&lt;string,&nbsp;Object&gt; | 是 | 表示扩展参数。 |
| abilityStartCallback | [AbilityStartCallback](js-apis-inner-application-abilityStartCallback.md) | 是 | 执行结果回调函数。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000050 | Internal error. |

**示例：**

```ts
import { UIAbility, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onForeground() {
    let wantParam: Record<string, Object> = {
      'time': '2023-10-23 20:45'
    };
    let abilityStartCallback: common.AbilityStartCallback = {
      onError: (code: number, name: string, message: string) => {
        console.log(`code:` + code + `name:` + name + `message:` + message);
      },
      onResult: (abilityResult: common.AbilityResult) => {
        console.log(`resultCode:` + abilityResult.resultCode + `bundleName:` + abilityResult.want?.bundleName);
      }
    };

    this.context.startAbilityByType("photoEditor", wantParam, abilityStartCallback).then(() => {
      console.log(`startAbilityByType success`);
    }).catch((err: BusinessError) => {
      console.error(`startAbilityByType fail, err: ${JSON.stringify(err)}`);
    });
  }
}
```

## UIAbilityContext.showAbility<sup>12+</sup>

showAbility(): Promise\<void>

显示当前Ability。使用Promise异步回调。仅在2in1和tablet设备上生效。仅支持在主线程调用。

调用此接口前要求确保应用已添加至状态栏。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 801 | Capability not support. |
| 16000050 | Internal error. |
| 16000067 | The StartOptions check failed. |

**示例：**

```ts
// Index.ets
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  @State showAbility: string = 'showAbility'

  build() {
    Row() {
      Column() {
        Text(this.showAbility)
          .fontSize(30)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            let context = this.getUIContext().getHostContext() as common.UIAbilityContext;

            context.showAbility().then(() => {
              console.log(`showAbility success`);
            }).catch((err: BusinessError) => {
              console.error(`showAbility fail, err: ${JSON.stringify(err)}`);
            });
          });
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
```ts
// EntryAbility.ts
import { UIAbility, Want, StartOptions, contextConstant } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onForeground() {
    let want: Want = {
      deviceId: '',
      bundleName: 'com.example.myapplication',
      abilityName: 'EntryAbility'
    };
    let options: StartOptions = {
      displayId: 0,
      processMode: contextConstant.ProcessMode.NEW_PROCESS_ATTACH_TO_STATUS_BAR_ITEM,
      startupVisibility: contextConstant.StartupVisibility.STARTUP_SHOW
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

## UIAbilityContext.hideAbility<sup>12+</sup>

hideAbility(): Promise\<void>

隐藏当前Ability。使用Promise异步回调。仅在2in1和tablet设备上生效。仅支持在主线程调用。

调用此接口前要求确保应用已添加至状态栏。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 801 | Capability not support. |
| 16000050 | Internal error. |
| 16000067 | The StartOptions check failed. |

**示例：**

```ts
// Index.ets
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  @State hideAbility: string = 'hideAbility'

  build() {
    Row() {
      Column() {
        Text(this.hideAbility)
          .fontSize(30)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            let context = this.getUIContext().getHostContext() as common.UIAbilityContext;

            context.hideAbility().then(() => {
              console.log(`hideAbility success`);
            }).catch((err: BusinessError) => {
              console.error(`hideAbility fail, err: ${JSON.stringify(err)}`);
            });
          });
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
```ts
// EntryAbility.ts
import { UIAbility, Want, StartOptions, contextConstant } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onForeground() {
    let want: Want = {
      deviceId: '',
      bundleName: 'com.example.myapplication',
      abilityName: 'EntryAbility'
    };
    let options: StartOptions = {
      displayId: 0,
      processMode: contextConstant.ProcessMode.NEW_PROCESS_ATTACH_TO_STATUS_BAR_ITEM,
      startupVisibility: contextConstant.StartupVisibility.STARTUP_HIDE
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

## UIAbilityContext.moveAbilityToBackground<sup>12+<sup>
moveAbilityToBackground(): Promise\<void>

将处于前台的Ability移动到后台。使用Promise异步回调。仅支持在主线程调用。<br/><!--RP1--><!--RP1End-->

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码详细介绍请参考[元能力子系统错误码]。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |
| 16000061 | Operation not supported. |
| 16000065 | The API can be called only when the ability is running in the foreground. |
| 16000066 | An ability cannot switch to the foreground or background in Wukong mode. |

**示例：**

```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
            let context = this.getUIContext().getHostContext() as common.UIAbilityContext;

            context.moveAbilityToBackground().then(() => {
              console.log(`moveAbilityToBackground success.`);
            }).catch((err: BusinessError) => {
              console.log(`moveAbilityToBackground error: ${JSON.stringify(err)}.`);
            });
          });
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## UIAbilityContext.openAtomicService<sup>12+<sup>

openAtomicService(appId: string, options?: AtomicServiceOptions): Promise&lt;AbilityResult&gt;

跳出式启动[EmbeddableUIAbility](js-apis-app-ability-embeddableUIAbility.md)，并返回结果。使用Promise异步回调。仅支持在主线程调用。

分为以下几种情况：
 - 正常情况下可通过调用[terminateSelfWithResult](#uiabilitycontextterminateselfwithresult)接口使之终止并且返回结果给调用方。
 - 异常情况下比如杀死EmbeddableUIAbility会返回异常信息给调用方，异常信息中resultCode为-1。
 - 如果不同应用多次调用该接口启动同一个EmbeddableUIAbility，当这个EmbeddableUIAbility调用[terminateSelfWithResult](#uiabilitycontextterminateselfwithresult)接口使之终止时，只将正常结果返回给最后一个调用方, 其它调用方返回异常信息，异常信息中resultCode为-1。

> **说明：**
>
> 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| appId | string | 是 | 应用的唯一标识，由云端统一分配。 |
| options | [AtomicServiceOptions](js-apis-app-ability-atomicServiceOptions.md) | 否 | 跳出式启动原子化服务所携带的参数。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[AbilityResult](js-apis-inner-ability-abilityResult.md)&gt; | Promise对象。返回[AbilityResult](js-apis-inner-ability-abilityResult.md)对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000002 | Incorrect ability type. |
| 16000003 | The specified ID does not exist. |
| 16000004 | Cannot start an invisible component. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled.        |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

**示例：**

```ts
import { UIAbility, common, AtomicServiceOptions } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onForeground() {
    let appId: string = '6918661953712445909';
    let options: AtomicServiceOptions = {
      displayId: 0
    };

    try {
      this.context.openAtomicService(appId, options)
        .then((result: common.AbilityResult) => {
          // 执行正常业务
          console.info('openAtomicService succeed');
        })
        .catch((err: BusinessError) => {
          // 处理业务逻辑错误
          console.error(`openAtomicService failed, code is ${err.code}, message is ${err.message}`);
        });
    } catch (err) {
      // 处理入参错误异常
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`openAtomicService failed, code is ${code}, message is ${message}`);
    }
  }
}
```

## UIAbilityContext.openLink<sup>12+<sup>

openLink(link: string, options?: OpenLinkOptions, callback?: AsyncCallback&lt;AbilityResult&gt;): Promise&lt;void&gt;

通过AppLinking启动UIAbility，使用Promise异步回调。仅支持在主线程调用。

通过在link字段中传入标准格式的URL，基于隐式want匹配规则拉起目标UIAbility。目标方必须具备以下过滤器特征，才能处理AppLinking链接：
- "actions"列表中包含"ohos.want.action.viewData"。
- "entities"列表中包含"entity.system.browsable"。
- "uris"列表中包含"scheme"为"https"且"domainVerify"为true的元素。

如果希望获取被拉起方终止后的结果，可以设置callback参数，此参数的使用可参照[startAbilityForResult](#uiabilitycontextstartabilityforresult)接口。
传入的参数不合法时，如未设置必选参数或link字符串不是标准格式的URL，接口会直接抛出异常。参数校验通过，拉起目标方时出现的错误通过promise返回错误信息。

> **说明：**
>
> 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| link | string | 是 | 指示要打开的标准格式URL。 |
| options | [OpenLinkOptions](js-apis-app-ability-openLinkOptions.md) | 否 | 打开URL的选项参数。 |
| callback | AsyncCallback&lt;[AbilityResult](js-apis-inner-ability-abilityResult.md)&gt; | 否 | 执行结果回调函数。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Cannot start an invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation and prepare continuation flag is forbidden.        |
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000019 | No matching ability is found. |
| 16200001 | The caller has been released. |
| 16000053 | The ability is not on the top of the UI. |

**示例：**

```ts
import { common, OpenLinkOptions } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

const DOMAIN = 0xeeee;
const TAG: string = '[openLinkDemo]';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Button("Call StartAbilityForResult")
        .onClick(() => {
          let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
          let link: string = 'https://www.example.com';
          let openLinkOptions: OpenLinkOptions = {
            appLinkingOnly: true,
            parameters: { demo_key: 'demo_value' }
          };

          try {
            context.openLink(
              link,
              openLinkOptions,
              (err, result) => {
                hilog.error(DOMAIN, TAG, `openLink callback error.code: ${JSON.stringify(err)}`);
                hilog.info(DOMAIN, TAG, `openLink callback result: ${JSON.stringify(result.resultCode)}`);
                hilog.info(DOMAIN, TAG, `openLink callback result data: ${JSON.stringify(result.want)}`);
              }
            ).then(() => {
              hilog.info(DOMAIN, TAG, `open link success.`);
            }).catch((err: BusinessError) => {
              hilog.error(DOMAIN, TAG, `open link failed, errCode ${JSON.stringify(err.code)}`);
            });
          }
          catch (e) {
            hilog.error(DOMAIN, TAG, `exception occured, errCode ${JSON.stringify(e.code)}`);
          }
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

## UIAbilityContext.backToCallerAbilityWithResult<sup>12+<sup>

backToCallerAbilityWithResult(abilityResult: AbilityResult, requestCode: string): Promise&lt;void&gt;

当通过[startAbilityForResult](#uiabilitycontextstartabilityforresult)或[openLink](#uiabilitycontextopenlink12)拉起目标方Ability，且需要目标方返回结果时，目标方可以通过该接口将结果返回并拉起调用方。与[terminateSelfWithResult](#uiabilitycontextterminateselfwithresult)不同的是，本接口在返回时不会销毁当前Ability。使用Promise异步回调。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| abilityResult | [AbilityResult](js-apis-inner-ability-abilityResult.md) | 是 | 指示目标方返回给拉起方的结果。 |
| requestCode  |  string | 是 | 通过[startAbilityForResult](#uiabilitycontextstartabilityforresult)或[openLink](#uiabilitycontextopenlink12)拉起目标方Ability且需要目标方返回结果时，系统生成的用于标识本次调用的requestCode。该值可以通过want中的[CALLER_REQUEST_CODE](js-apis-app-ability-wantConstant.md)字段获取。|

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201  | The application does not have permission to call the interface. |
| 401  | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011  | The context does not exist. |
| 16000050 | Internal error. |
| 16000074 | The caller does not exist. |
| 16000075 | BackToCaller is not supported. |

**示例：**
调用方通过startAbilityForResult接口拉起目标方, 目标方再调用backToCallerAbilityWithResult接口返回到调用方。

```ts
// 调用方
// index.ets
import { common, Want } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';
import { hilog } from '@kit.PerformanceAnalysisKit';

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(30)
          .fontWeight(FontWeight.Bold)

        Button("Call StartAbilityForResult")
          .onClick(() => {
            let context: common.UIAbilityContext = this.getUIContext().getHostContext() as common.UIAbilityContext;
            let want: Want = {
              bundleName: 'com.example.demo2',
              abilityName: 'EntryAbility'
            };

            try {
              // 通过startAbilityForResult拉起目标应用
              context.startAbilityForResult(want, (err: BusinessError, result: common.AbilityResult) => {
                if (err.code) {
                  // 处理业务逻辑错误
                  hilog.error(0x0000, 'testTag', `startAbilityForResult failed, code is ${err.code}, message is ${err.message}`);
                  this.message = `startAbilityForResult failed: code is ${err.code}, message is ${err.message}`
                  return;
                }
                // 执行正常业务
                hilog.info(0x0000, 'testTag', `startAbilityForResult succeed`);
                hilog.info(0x0000, 'testTag', `AbilityResult is ${JSON.stringify(result)}`);
                this.message = `AbilityResult.resultCode: ${JSON.stringify(result.resultCode)}`
              });
            } catch (err) {
              // 处理入参错误异常
              let code = (err as BusinessError).code;
              let message = (err as BusinessError).message;
              hilog.error(0x0000, 'testTag', `startAbilityForResult failed, code is ${code}, message is ${message}`);
              this.message = `startAbilityForResult failed, code is ${code}, message is ${message}`;
            }
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

```ts
// 目标方
// EntryAbility.ets
import { AbilityConstant, common, UIAbility, Want, wantConstant } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    // 从want中获取调用方的CALLER_REQUEST_CODE，并保存
    let callerRequestCode: string = want?.parameters?.[wantConstant.Params.CALLER_REQUEST_CODE] as string;
    AppStorage.setOrCreate<string>("callerRequestCode", callerRequestCode)
  }

  onNewWant(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    let callerRequestCode: string = want?.parameters?.[wantConstant.Params.CALLER_REQUEST_CODE] as string;
    AppStorage.setOrCreate<string>("callerRequestCode", callerRequestCode)
  }

  onForeground(): void {
    // 获取保存的CALLER_REQUEST_CODE
    let callerRequestCode: string = AppStorage.get<string>("callerRequestCode") as string;
    hilog.info(0x0000, 'testTag', `callerRequestCode is ${callerRequestCode}`);
    let want: Want = {};
    let resultCode = 100;
    let abilityResult: common.AbilityResult = {
      want,
      resultCode
    };
    try {
      // 将结果信息返回给调用方
      this.context.backToCallerAbilityWithResult(abilityResult, callerRequestCode)
        .then(() => {
          // 执行正常业务
          hilog.info(0x0000, 'testTag', 'backToCallerAbilityWithResult succeed');
        })
        .catch((err: BusinessError) => {
          // 处理业务逻辑错误
          hilog.error(0x0000, 'testTag', `backToCallerAbilityWithResult failed, code is ${err.code}, message is ${err.message}`);
        });
    } catch (err) {
      // 捕获同步的参数错误
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      hilog.error(0x0000, 'testTag', `backToCallerAbilityWithResult failed, code is ${code}, message is ${message}`);
    }
  }
}
```

## UIAbilityContext.setRestoreEnabled<sup>14+</sup>

setRestoreEnabled(enabled: boolean): void

设置UIAbility是否启用备份恢复。

**原子化服务API**：从API version 14开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| enabled | boolean | 是 | 表示是否启用恢复。true表示启用，false表示不启用。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401 | If the input parameter is not valid parameter. |
| 16000011 | The context does not exist. |

**示例：**

```ts
import { UIAbility, AbilityConstant, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    let enabled = true;
    try {
      this.context.setRestoreEnabled(enabled);
    } catch (paramError) {
      let code = (paramError as BusinessError).code;
      let message = (paramError as BusinessError).message;
      console.error(`setRestoreEnabled failed, err code: ${code}, err msg: ${message}`);
    }
  }
}
```

## UIAbilityContext.startUIServiceExtensionAbility<sup>14+<sup>

startUIServiceExtensionAbility(want: Want): Promise&lt;void&gt;

启动一个UIServiceExtensionAbility。使用Promise异步回调。

> **说明：**
>
> 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。

**原子化服务API**：从API version 14开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                                     | 必填 | 说明                     |
| -------- | --------------------------------------- | ---- | ------------------------ |
| want     | [Want](js-apis-app-ability-want.md)     | 是 | 启动需要的Want信息。 |

**返回值：**

| 类型                | 说明                                   |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息                                                                                                    |
| -------- | ----------------------------------------------------------------------------------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801 | Capability not supported. |
| 16000001 | The specified ability does not exist.                                                                       |
| 16000002 | Incorrect ability type.                                                                                     |
| 16000004 | Cannot start an invisible component.                                                                          |
| 16000005 | The specified process does not have the permission.                                                         |
| 16000008 | The crowdtesting application expires.                                                                       |
| 16000011 | The context does not exist.                                                                                 |
| 16000012 | The application is controlled.                                                                              |
| 16000013 | The application is controlled by EDM.                                                                       |
| 16000019 | No matching ability is found.                                                                               |
| 16000050 | Internal error.                                                                                             |
| 16200001 | The caller has been released.                                                                               |

**示例：**

```ts
import { common, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    Column() {
      Row() {
        // 创建启动按钮
        Button('start ability')
          .enabled(true)
          .onClick(() => {
            let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
            let startWant: Want = {
              bundleName: 'com.acts.uiserviceextensionability',
              abilityName: 'UiServiceExtAbility',
            };
            try {
              // 启动UIServiceExtensionAbility
              context.startUIServiceExtensionAbility(startWant).then(() => {
                console.log('startUIServiceExtensionAbility success');
              }).catch((error: BusinessError) => {
                console.log('startUIServiceExtensionAbility error', JSON.stringify(error));
              })
            } catch (err) {
              console.log('startUIServiceExtensionAbility failed', JSON.stringify(err));
            }
          })
      }
    }
  }
}
```

## UIAbilityContext.connectUIServiceExtensionAbility<sup>14+<sup>

connectUIServiceExtensionAbility(want: Want, callback: UIServiceExtensionConnectCallback) : Promise&lt;UIServiceProxy&gt;

连接一个UIServiceExtensionAbility。使用Promise异步回调。

> **说明：**
>
> 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。
>

**原子化服务API**：从API version 14开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明                 |
| ------ | ---- | ---- | ---- |
| want   |[Want](js-apis-app-ability-want.md) | 是  | 连接需要的Want信息。 |
| callback | [UIServiceExtensionConnectCallback](js-apis-inner-application-uiServiceExtensionconnectcallback.md) | 是  | 连接UIServiceExtensionAbility回调。 |

**返回值：**

| 类型                | 说明                                   |
| ------------------- | -------------------------------------- |
| Promise&lt;UIServiceProxy&gt; | [connectUIServiceExtensionAbility](js-apis-inner-application-uiExtensionContext.md#uiextensioncontextconnectuiserviceextensionability13)执行后返回的[UIServiceProxy](js-apis-inner-application-uiserviceproxy.md)对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息                                                                             |
| -------- | ----------------------------------------------------------------------------------- |
| 201      | The application does not have permission to call the interface.                     |
| 801      | Capability not supported.                                                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000001 | The specified ability does not exist.                                               |
| 16000002 | Incorrect ability type.                                                             |
| 16000004 | Cannot start an invisible component.                                              |
| 16000005 | The specified process does not have the permission.                                 |
| 16000008 | The crowdtesting application expires.                                               |
| 16000011 | The context does not exist.                                                         |
| 16000013 | The application is controlled by EDM.                                               |
| 16000050 | Internal error.                                                                     |
| 16000055 | Installation-free timed out.                                                        |

**示例：**

```ts
import { common, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

const TAG: string = '[Extension] ';

@Entry
@Component
struct UIServiceExtensionAbility {
  dataCallBack : common.UIServiceExtensionConnectCallback = {
    // 接收数据
    onData: (data: Record<string, Object>) => {
      console.log(`dataCallBack received data`, JSON.stringify(data));
    },
    // 连接断开
    onDisconnect: () => {
      console.log(`dataCallBack onDisconnect`);
    }
  }

  async myConnect() {
    // 获取上下文
    let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
    let startWant: Want = {
      deviceId: '',
      bundleName: 'com.example.myapplication',
      abilityName: 'UiServiceExtAbility'
    };

    try {
      // 连接服务
      context.connectUIServiceExtensionAbility(startWant, this.dataCallBack)
        .then((proxy: common.UIServiceProxy) => {
          console.log(TAG + `try to connectUIServiceExtensionAbility`, JSON.stringify(proxy));
        }).catch((err: Error) => {
        let code = (err as BusinessError).code;
        let message = (err as BusinessError).message;
        console.log(TAG + `connectUIServiceExtensionAbility failed, code is ${code}, message is ${message}`);
      });
    } catch (err) {
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.log(TAG + `connectUIServiceExtensionAbility failed, code is ${code}, message is ${message}`);
    };
  }

  build() {
    RelativeContainer() {
      // 创建连接按钮
      Button('connectServiceExtensionAbility', { type: ButtonType.Capsule, stateEffect: true })
        .alignRules({
          center: { anchor: '__container__', align: VerticalAlign.Center },
          middle: { anchor: '__container__', align: HorizontalAlign.Center }
        })
        .onClick(() => {
          this.myConnect()
        });
    }
    .height('100%')
    .width('100%')
  }
}
```

## UIAbilityContext.disconnectUIServiceExtensionAbility<sup>14+<sup>

disconnectUIServiceExtensionAbility(proxy: UIServiceProxy): Promise&lt;void&gt;

断开与UIServiceExtensionAbility的连接。使用Promise异步回调。

> **说明：**
>
> 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。
>

**原子化服务API**：从API version 14开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明                 |
| ------ | ---- | ---- | -------------------- |
| proxy   | [UIServiceProxy](js-apis-inner-application-uiserviceproxy.md) | 是 | [connectUIServiceExtensionAbility](#uiabilitycontextconnectuiserviceextensionability13)执行返回的Proxy。 |

**返回值：**

| 类型                | 说明                                   |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息                                                                                |
| -------- | ------------------------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000011 | The context does not exist.                                                                  |
| 16000050 | Internal error.                                                                                 |

**示例：**

```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

const TAG: string = '[Extension] ';

@Entry
@Component
struct UIServiceExtensionAbility {
  comProxy: common.UIServiceProxy | null = null;

  build() {
    Scroll() {
      Column() {
        // 创建断开连接的按钮
        Button('disconnectUIServiceExtensionAbility', { type: ButtonType.Capsule, stateEffect: true })
          .margin({
            top: 5,
            left: 10,
            right: 10,
            bottom: 5
          })
          .alignRules({
            center: { anchor: '__container__', align: VerticalAlign.Center },
            middle: { anchor: '__container__', align: HorizontalAlign.Center }
          })
          .onClick(() => {
            this.myDisconnectUIServiceExtensionAbility()
          });
      }
      .width('100%')
    }
    .height('100%')
  }

  myDisconnectUIServiceExtensionAbility() {
    let context = this.getUIContext().getHostContext() as common.UIAbilityContext;

    try {
      // 断开UIServiceExtension连接
      context.disconnectUIServiceExtensionAbility(this.comProxy)
        .then(() => {
          console.log(TAG + `disconnectUIServiceExtensionAbility succeed ${this.comProxy}}`);
        }).catch((err: Error) => {
        let code = (err as BusinessError).code;
        let message = (err as BusinessError).message;
        console.log(TAG + `disconnectUIServiceExtensionAbility failed, code is ${code}, message is ${message}`);
      });
    } catch (err) {
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.log(TAG + `disconnectUIServiceExtensionAbility failed, code is ${code}, message is ${message}`);
    }
  }
}
```

## UIAbilityContext.setAbilityInstanceInfo<sup>15+<sup>

setAbilityInstanceInfo(label: string, icon: image.PixelMap) : Promise&lt;void&gt;

设置当前UIAbility实例的图标和标签信息。图标与标签信息可在任务中心和快捷栏的界面中显示。使用Promise异步回调。


> **说明**：
>
> 仅支持2in1设备。

**需要权限**： ohos.permission.SET_ABILITY_INSTANCE_INFO

**系统能力**： SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名 | 类型                                                            | 必填 | 说明                                               |
| ------ | -------------------------------------------------------------- | ---- | -------------------------------------------------- |
| label  |string                                                          | 是   | 新的标题。标题长度不超过1024字节，标题不可为空字符串。  |
| icon   | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) | 是   | 新的图标。建议图标大小为512px*512px。                |

**返回值**：

| 类型                | 说明                                   |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息                                                                             |
| -------- | ----------------------------------------------------------------------------------- |
| 201      | The application does not have permission to call the interface.                     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801      | Capability not supported.                                                           |
| 16000011 | The context does not exist.                                                         |
| 16000050 | Internal error.                                                                     |

**示例**：

```ts
import { UIAbility } from '@kit.AbilityKit';
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage): void {
    windowStage.loadContent('pages/Index', async (err, data) => {
      if (err.code) {
        console.error(`loadContent failed, code is ${err.code}`);
        return;
      }

      let newLabel: string = 'instance label';
      let color = new ArrayBuffer(0);
      let imagePixelMap: image.PixelMap = await image.createPixelMap(color, {
        size: {
          height: 100,
          width: 100
        }
      });
      this.context.setAbilityInstanceInfo(newLabel, imagePixelMap)
        .then(() => {
          console.info('setAbilityInstanceInfo success');
        }).catch((err: BusinessError) => {
          console.error(`setAbilityInstanceInfo failed, code is ${err.code}, message is ${err.message}`);
        });
      });
  }
}
```

## UIAbilityContext.revokeDelegator<sup>17+</sup>

revokeDelegator() : Promise&lt;void&gt;

如果Module下首个UIAbility启动时期望重定向到另一个UIAbility，该重定向的UIAbility被称为“DelegatorAbility”。DelegatorAbility的设置详见当前接口示例的步骤1。

当DelegatorAbility完成特定操作时，可以使用该接口回到首个UIAbility。使用Promise异步回调。

> **说明**：
>
> 当接口调用成功后，DelegatorAbility中的[Window](../apis-arkui/js-apis-window.md)方法会失效。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值**：

| 类型                | 说明                                   |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 801 | Capability not support. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |
| 16000065 | The API can be called only when the ability is running in the foreground. |
| 16000084 | Only DelegatorAbility is allowed to call this API, and only once. |
| 16000085 | An error occurred during the interaction between the ability and window. |

**示例**：

1. 设置DelegatorAbility。

    在[module.json5](../../quick-start/module-configuration-file.md#modulejson5配置文件)配置文件标签中配置abilitySrcEntryDelegator和abilityStageSrcEntryDelegator。当Module下首个UIAbility冷启动时，系统优先启动abilitySrcEntryDelegator指向的UIAbility。
    > **说明**：
    >
    >  - 当UIAbility是通过[startAbilityByCall](#uiabilitycontextstartabilitybycall)启动时，系统会忽略在[module.json5](../../quick-start/module-configuration-file.md#modulejson5配置文件)配置文件标签中配置的abilitySrcEntryDelegator和abilityStageSrcEntryDelegator。
    >  - abilityStageSrcEntryDelegator指定的ModuleName不能与当前ModuleName相同。
    ```json
    {
      "module": {
        // ...
        "abilityStageSrcEntryDelegator": "xxxModuleName",
        "abilitySrcEntryDelegator": "xxxAbilityName",
        // ...
      }
    }
    ```

2. 取消DelegatorAbility。

    ```ts
    import { UIAbility } from '@kit.AbilityKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    export default class DelegatorAbility extends UIAbility {
      onForeground() {
        // DelegatorAbility完成特定操作后，调用revokeDelegator回到首个UIAbility
        this.context.revokeDelegator().then(() => {
          console.info('revokeDelegator success');
        }).catch((err: BusinessError) => {
          console.error(`revokeDelegator failed, code is ${err.code}, message is ${err.message}`);
        });
      }
    }
    ```

## UIAbilityContext.setColorMode<sup>18+</sup>

setColorMode(colorMode: ConfigurationConstant.ColorMode): void

设置UIAbility的颜色模式。调用该接口前需要保证该UIAbility对应页面已完成加载。仅支持主线程调用。

> **说明**：
> - 调用该接口后会创建新的资源管理器对象，如果此前有缓存资源管理器，需要进行更新。
> - 颜色模式生效的优先级：UIAbility的颜色模式 > 应用的颜色模式（[ApplicationContext.setColorMode](js-apis-inner-application-applicationContext.md)）> 系统的颜色模式。

**原子化服务API**：从API version 18开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名 | 类型          | 必填 | 说明                 |
| ------ | ------------- | ---- | -------------------- |
| colorMode | [ConfigurationConstant.ColorMode](js-apis-app-ability-configurationConstant.md) | 是   | 设置颜色模式，包括: <br> - COLOR_MODE_DARK：深色模式 <br> - COLOR_MODE_LIGHT：浅色模式 <br> - COLOR_MODE_NOT_SET：不设置（跟随系统或应用）|

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |

**示例**：

```ts
import { UIAbility, ConfigurationConstant } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';

export default class MyAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    windowStage.loadContent('pages/Index', (err, data) => {
      if (err.code) {
        hilog.error(0x0000, 'testTag', 'Failed to load the content.');
        return;
      }
      let uiAbilityContext = this.context;
      uiAbilityContext.setColorMode(ConfigurationConstant.ColorMode.COLOR_MODE_DARK);
    });
  }
}
```

## UIAbilityContext.startAppServiceExtensionAbility<sup>20+</sup>

startAppServiceExtensionAbility(want: Want): Promise\<void>

启动[AppServiceExtensionAbility](js-apis-app-ability-appServiceExtensionAbility.md)实例。使用Promise异步回调。

> **说明：**
>
> - 当前仅支持2in1设备。
> - 该接口的调用方必须为[AppServiceExtensionAbility](js-apis-app-ability-appServiceExtensionAbility.md)所属应用或者在AppServiceExtensionAbility支持的应用清单（即[extensionAbilities标签](../../quick-start/module-configuration-file.md#extensionabilities标签)的appIdentifierAllowList属性）中的应用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | 启动[AppServiceExtensionAbility](js-apis-app-ability-appServiceExtensionAbility.md)的Want信息。 |

**返回值**：

| 类型                | 说明                                   |
| ------------------- | -------------------------------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 801 | Capability not support. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Failed to start the invisible ability. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000019 | No matching ability is found. |
| 16000050 | Internal error. |
| 16000200 | The caller not in target app identifier allow list. |

**示例：**

```ts
import { UIAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onForeground() {
    let want: Want = {
      deviceId: '',
      bundleName: 'com.example.myapplication',
      abilityName: 'AppServiceExtensionAbility'
    };

    try {
      this.context.startAppServiceExtensionAbility(want)
        .then(() => {
          // 执行正常业务
          console.info('startAppServiceExtensionAbility succeed');
        })
        .catch((err: BusinessError) => {
          // 处理业务逻辑错误
          console.error(`startAppServiceExtensionAbility failed, code is ${err.code}, message is ${err.message}`);
        });
    } catch (err) {
      // 处理入参错误异常
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`startAppServiceExtensionAbility failed, code is ${code}, message is ${message}`);
    }
  }
}
```

## UIAbilityContext.stopAppServiceExtensionAbility<sup>20+</sup>

stopAppServiceExtensionAbility(want: Want): Promise\<void>

停止[AppServiceExtensionAbility](js-apis-app-ability-appServiceExtensionAbility.md)实例。使用Promise异步回调。

> **说明：**
>
> - 当前仅支持2in1设备。
> - 该接口的调用方必须为[AppServiceExtensionAbility](js-apis-app-ability-appServiceExtensionAbility.md)所属应用或者在AppServiceExtensionAbility支持的应用清单（即[extensionAbilities标签](../../quick-start/module-configuration-file.md#extensionabilities标签)的appIdentifierAllowList属性）中的应用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | 停止[AppServiceExtensionAbility](js-apis-app-ability-appServiceExtensionAbility.md)的Want信息。 |

**返回值**：

| 类型                | 说明                                   |
| ------------------- | -------------------------------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 801 | Capability not support. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Failed to start the invisible ability. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |
| 16000200 | The caller not in target app identifier allow list. |

**示例：**

```ts
import { UIAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onForeground() {
    let want: Want = {
      deviceId: '',
      bundleName: 'com.example.myapplication',
      abilityName: 'AppServiceExtensionAbility'
    };

    try {
      this.context.stopAppServiceExtensionAbility(want)
        .then(() => {
          // 执行正常业务
          console.info('stopAppServiceExtensionAbility succeed');
        })
        .catch((err: BusinessError) => {
          // 处理业务逻辑错误
          console.error(`stopAppServiceExtensionAbility failed, code is ${err.code}, message is ${err.message}`);
        });
    } catch (err) {
      // 处理入参错误异常
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`stopAppServiceExtensionAbility failed, code is ${code}, message is ${message}`);
    }
  }
}
```

## UIAbilityContext.connectAppServiceExtensionAbility<sup>20+</sup>

connectAppServiceExtensionAbility(want: Want, options: ConnectOptions): number

将当前UIAbility连接到[AppServiceExtensionAbility](js-apis-app-ability-appServiceExtensionAbility.md)。通过返回的proxy与AppServiceExtensionAbility进行通信，以使用AppServiceExtensionAbility对外提供的能力。仅支持在主线程调用。

> **说明：**
>
> - 当前仅支持2in1设备。
> - 如果[AppServiceExtensionAbility](js-apis-app-ability-appServiceExtensionAbility.md)实例未启动，该接口的调用方必须为AppServiceExtensionAbility所属应用或者在AppServiceExtensionAbility支持的应用清单（即[extensionAbilities标签](../../quick-start/module-configuration-file.md#extensionabilities标签)的appIdentifierAllowList属性）中的应用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | 连接[AppServiceExtensionAbility](js-apis-app-ability-appServiceExtensionAbility.md)的Want信息。 |
| options | [ConnectOptions](js-apis-inner-ability-connectOptions.md) | 是 | ConnectOptions类型的回调函数，返回服务连接成功、连接失败、断开的信息。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回连接id，[disconnectAppServiceExtensionAbility](#uiabilitycontextdisconnectappserviceextensionability20)根据该连接id断开连接。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 801 | Capability not support. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Failed to start the invisible ability. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000011 | The context does not exist.        |
| 16000050 | Internal error. |
| 16000201 | The target has not been started yet. |

**示例：**

```ts
import { UIAbility, Want, common } from '@kit.AbilityKit';
import { rpc } from '@kit.IPCKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onForeground() {
    let want: Want = {
      deviceId: '',
      bundleName: 'com.example.myapplication',
      abilityName: 'AppServiceExtensionAbility'
    };
    let commRemote: rpc.IRemoteObject;
    let options: common.ConnectOptions = {
      onConnect(elementName, remote) {
        commRemote = remote;
        console.info('onConnect...');
      },
      onDisconnect(elementName) {
        console.info('onDisconnect...');
      },
      onFailed(code) {
        console.info('onFailed...');
      }
    };
    let connection: number;

    try {
      connection = this.context.connectAppServiceExtensionAbility(want, options);
    } catch (err) {
      // 处理入参错误异常
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`connectAppServiceExtensionAbility failed, code is ${code}, message is ${message}`);
    }
  }
}
```

## UIAbilityContext.disconnectAppServiceExtensionAbility<sup>20+</sup>

disconnectAppServiceExtensionAbility(connection: number): Promise\<void>

断开与[AppServiceExtensionAbility](js-apis-app-ability-appServiceExtensionAbility.md)的连接。仅支持在主线程调用。使用Promise异步回调。

断开连接之后，为了防止使用可能失效的remote对象进行通信，建议将连接成功时返回的remote对象设置为null。

> **说明：**
>
> - 当前仅支持2in1设备。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| connection | number | 是 | 在[connectAppServiceExtensionAbility](#uiabilitycontextconnectappserviceextensionability20)返回的连接id。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 801 | Capability not support. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { rpc } from '@kit.IPCKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onForeground() {
    // connection为connectAppServiceExtensionAbility中的返回值
    let connection = 1;
    let commRemote: rpc.IRemoteObject | null;

    try {
      this.context.disconnectAppServiceExtensionAbility(connection).then(() => {
        commRemote = null;
        // 执行正常业务
        console.info('disconnectAppServiceExtensionAbility succeed');
      }).catch((err: BusinessError) => {
        // 处理业务逻辑错误
        console.error(`disconnectAppServiceExtensionAbility failed, code is ${err.code}, message is ${err.message}`);
      });
    } catch (err) {
      commRemote = null;
      // 处理入参错误异常
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`disconnectAppServiceExtensionAbility failed, code is ${code}, message is ${message}`);
    }
  }
}
```