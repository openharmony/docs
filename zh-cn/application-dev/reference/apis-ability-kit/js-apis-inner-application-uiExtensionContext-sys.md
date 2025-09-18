# UIExtensionContext (系统接口)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @zhangyafei-echo-->
<!--Designer: @li-weifeng2-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

UIExtensionContext是[UIExtensionAbility](js-apis-app-ability-uiExtensionAbility.md)的上下文环境，继承自[ExtensionContext](js-apis-inner-application-extensionContext.md)，提供UIExtensionAbility的相关配置信息以及操作UIAbility的方法，如启动UIAbility等。

> **说明：**
>
>  - 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>  - 本模块接口仅可在Stage模型下使用。
>  - 本模块接口为系统接口。

## 导入模块

```ts
import { common } from '@kit.AbilityKit';
```

## UIExtensionContext

### startAbilityForResultAsCaller

startAbilityForResultAsCaller(want: Want, options?: StartOptions): Promise&lt;AbilityResult&gt;

使用设置的caller信息启动一个Ability，caller信息由want携带，在系统服务层识别，Ability可以在onCreate生命周期的want参数中获取到caller信息。使用该接口启动一个Ability时，want的caller信息不会被当前自身的应用信息覆盖，系统服务层可获取到初始caller的信息。使用Promise异步回调。

 - 正常情况下可通过调用[terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#terminateselfwithresult)接口使之终止并且返回结果给调用方。
 - 异常情况下比如杀死Ability会返回异常信息给调用方，异常信息中resultCode为-1。
 - 如果被启动的Ability模式是单实例模式，不同应用多次调用该接口启动这个Ability，当这个Ability调用[terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#terminateselfwithresult)接口使之终止时，只将正常结果返回给最后一个调用方，其它调用方返回异常信息，异常信息中resultCode为-1。

> **说明：**
>
> 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名  | 类型                                                | 必填 | 说明                      |
| ------- | --------------------------------------------------- | ---- | ------------------------- |
| want    | [Want](js-apis-app-ability-want.md)                 | 是   | 启动Ability的want信息。   |
| options | [StartOptions](js-apis-app-ability-startOptions.md) | 否   | 启动Ability所携带的参数。 |

**返回值：**

| 类型                                                         | 说明                      |
| ------------------------------------------------------------ | ------------------------- |
| Promise&lt;[AbilityResult](js-apis-inner-ability-abilityResult.md)&gt; | Promise对象，返回Ability结果对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------- |
| 401| Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000001 | The specified ability does not exist.                   |
| 16000004 | Cannot start an invisible component.                    |
| 16000050 | Internal error.                                         |
| 16000073 | The app clone index is invalid. |

**示例：**

```ts
import { UIExtensionAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class UIExtension extends UIExtensionAbility {
  onForeground() {
    this.context.startAbilityForResultAsCaller({
      bundleName: 'com.example.startabilityforresultascaller',
      abilityName: 'EntryAbility',
      moduleName: 'entry'
    }).then((data) => {
      console.log(`StartAbilityForResultAsCaller success, data: ${JSON.stringify(data)}.`);
    }).catch((error: BusinessError) => {
      console.error(`StartAbilityForResultAsCaller failed, err code: ${error.code}, err msg: ${error.message}.`);
    });
  }
}
```

### startServiceExtensionAbility<sup>18+</sup>

startServiceExtensionAbility(want: Want): Promise\<void>

启动一个ServiceExtensionAbility。使用Promise异步回调。

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ------ | ------ | ------ |
| want | [Want](js-apis-app-ability-want.md) | 是 | 启动ServiceExtensionAbility的Want信息。 |

**返回值：**

| 类型 | 说明 |
| ------ | ------ |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------ | ------ |
| 201 | The application does not have permission to call the interface. |
| 202 | The application is not system-app, can not use system-api. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Cannot start an invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled. |
| 16000013 | The application is controlled by EDM. |
| 16000019 | No matching ability is found. |
| 16000050 | Internal error. |
| 16200001 | The caller has been released. |

**示例：**

```ts
import { UIExtensionAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class UIExtAbility extends UIExtensionAbility {
  onForeground() {
    let want: Want = {
      bundleName: 'com.example.myapplication',
      moduleName: 'entry',
      abilityName: 'ServiceExtensionAbility'
    };

    try {
      this.context.startServiceExtensionAbility(want)
        .then(() => {
          // 执行正常业务
          console.info('startServiceExtensionAbility succeed');
        })
        .catch((err: BusinessError) => {
          // 处理业务逻辑错误
          console.error(`startServiceExtensionAbility failed, code is ${err.code}, message is ${err.message}`);
        });
    } catch (err) {
      // 处理入参错误异常
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`startServiceExtensionAbility failed, code is ${code}, message is ${message}`);
    }
  }
}
```

### startServiceExtensionAbilityWithAccount<sup>18+</sup>

startServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise\<void>

启动一个指定系统账号下的ServiceExtensionAbility。使用Promise异步回调。

> **说明：**
>
> 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。
>
> 当accountId为当前用户时，无需进行权限校验。

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ------ | ------ | ------ |
| want | [Want](js-apis-app-ability-want.md) | 是 | 启动ServiceExtensionAbility的Want信息。 |
| accountId | number | 是 | 系统账号的ID，详情参考[getCreatedOsAccountsCount](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountcount9)。 |

**返回值：**

| 类型 | 说明 |
| ------ | ------ |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------ | ------ |
| 201 | The application does not have permission to call the interface. |
| 202 | The application is not system-app, can not use system-api. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Cannot start an invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled. |
| 16000013 | The application is controlled by EDM. |
| 16000019 | No matching ability is found. |
| 16000050 | Internal error. |
| 16200001 | The caller has been released. |

**示例：**

```ts
import { UIExtensionAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class UIExtAbility extends UIExtensionAbility {
  onForeground() {
    let want: Want = {
      bundleName: 'com.example.myapplication',
      moduleName: 'entry',
      abilityName: 'ServiceExtensionAbility'
    };
    let accountId = 100;

    try {
      this.context.startServiceExtensionAbilityWithAccount(want, accountId)
        .then(() => {
          // 执行正常业务
          console.info('startServiceExtensionAbilityWithAccount succeed');
        })
        .catch((err: BusinessError) => {
          // 处理业务逻辑错误
          console.error(`startServiceExtensionAbilityWithAccount failed, code is ${err.code}, message is ${err.message}`);
        });
    } catch (err) {
      // 处理入参错误异常
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`startServiceExtensionAbilityWithAccount failed, code is ${code}, message is ${message}`);
    }
  }
}
```

### setHostPageOverlayForbidden<sup>15+</sup>

setHostPageOverlayForbidden(isForbidden: boolean) : void

是否允许[UIExtensionAbility](../apis-ability-kit/js-apis-app-ability-uiExtensionAbility.md)拉起的页面被使用方的页面覆盖。

> **说明：**
>
> 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。
>
> 该接口需要在窗口创建之前调用。建议在[UIExtensionAbility](../apis-ability-kit/js-apis-app-ability-uiExtensionAbility.md)的[onCreate](../apis-ability-kit/js-apis-app-ability-uiExtensionAbility.md#oncreate)生命周期内调用。

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ------ | ------ | ------ |
| isForbidden | boolean | 是 | 是否允许[UIExtensionAbility](../apis-ability-kit/js-apis-app-ability-uiExtensionAbility.md)拉起的页面被使用方的页面覆盖。true表示不允许，false表示允许。 |


**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------ | ------ |
| 202 | The application is not system-app, can not use system-api. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**示例**：

```ts
import { UIExtensionAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class UIExtAbility extends UIExtensionAbility {
  OnCreate() {
    try {
      this.context.setHostPageOverlayForbidden(true)
    } catch (err) {
      // 处理入参错误异常
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`setHostPageOverlayForbidden failed, code is ${code}, message is ${message}`);
    }
  }
}
```

### startUIAbilities<sup>20+</sup>

startUIAbilities(wantList: Array\<Want>): Promise\<void>

同时启动多个UIAbility。使用Promise异步回调。

开发者可以传入多个UIAbility对应的Want信息，这些UIAbility可以指向一个或多个应用。当所有的UIAbility都能启动成功时，系统会通过多个窗口同时展示这些UIAbility。根据窗口的处理，不同设备上可能会有不同的展示效果（包括窗口形态、数量和排版布局）。

> **说明：**
> 
> 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**设备行为差异**：该接口仅在Phone和Tablet设备中可正常调用，在其他设备中返回801错误码。

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ------ | ------ | ------ |
| wantList | Array\<[Want](js-apis-app-ability-want.md)> | 是 | 需要被同时拉起的多个UIAbility的启动参数列表，最多支持传入4个Want。启动参数Want不支持隐式启动、跨用户启动、分布式、免安装和按需加载，不指明分身的情况下默认启动主应用。|

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。|

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------ | ------ |
| 201 | The application does not have permission to call the interface. |
| 202 | Not system application. |
| 801 | Capability not supported. |
| 16000001 | The specified ability does not exist. |
| 16000004 | Cannot start an invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |
| 16200001 | The caller has been released. |
| 16000073 | The app clone index is invalid. |
| 16000076 | The app instance key is invalid. |
| 16000080 | Creating a new instance is not supported. |
| 16000120 | A maximum of four UIAbility instances can be started simultaneously. The current parameter exceeds the maximum number or is less than 1.|
| 16000121 | The target component type is not a UIAbility. |
| 16000122 | The target component is blocked by the system module and does not support startup. |
| 16000123 | Implicit startup is not supported. |
| 16000124 | Starting a remote UIAbility is not supported. |
| 16000125 | Starting a plugin UIAbility is not supported. |
| 16000126 | Starting DLP files is not supported. |

**示例**：

```ts
import { UIExtensionAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryUIExtAbility extends UIExtensionAbility {
  onForeground() {
    let want1: Want = {
      bundleName: 'com.example.myapplication1',
      abilityName: 'EntryAbility'
    };
    let want2: Want = {
      bundleName: 'com.example.myapplication2',
      abilityName: 'EntryAbility'
    };
    let wantList: Array<Want> = [want1, want2];
    try {
      this.context.startUIAbilities(wantList).then(() => {
        console.info(`TestTag:: start succeeded.`);
      }).catch((error: BusinessError) => {
        console.info(`TestTag:: startUIAbilities failed: ${JSON.stringify(error)}`);
      });
    } catch (paramError) {
      // 处理入参错误异常
      console.error(`error.code: ${paramError.code}, error.message: ${paramError.message}`);
    }
  }
}
```
### startUIAbilitiesInSplitWindowMode<sup>20+</sup>

startUIAbilitiesInSplitWindowMode(primaryWindowId: number, secondaryWant: Want): Promise\<void>

当第一个UIAbility实例被创建后，启动第二个UIAbility，并以分屏模式进行显示。使用Promise异步回调。

> **说明：**
>
> 如果第一个UIAbility实例被销毁，那么第二个UIAbility将以全屏模式启动。
> 
> 第二个UIAbility仅支持[显示启动](../../application-models/explicit-implicit-want-mappings.md#显式want匹配原理)。
> 
> 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**设备行为差异**：该接口仅在Phone设备中可正常调用，在其他设备中返回801错误码。

**参数**：

| 参数名 | 类型 | 必填 | 说明                                                                                                                                                                                                                     |
| ------ |--------| ------ |------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| primaryWindowId | number | 是| 启动第一个UIAbility的主窗的窗口ID。窗口ID是[WindowProperties](../apis-arkui/arkts-apis-window-i.md#windowproperties)的属性，WindowProperties可通过[getWindowProperties()](../apis-arkui/arkts-apis-window-Window.md#getwindowproperties9)获取。 |
| secondaryWant | [Want](js-apis-app-ability-want.md) | 是| 启动第二个UIAbility所需的Want信息。                                                                                                                                                                                               |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。|

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------ | ------ |
| 201 | The application does not have permission to call the interface. |
| 202 | Not system application. |
| 801 | Capability not supported. |
| 16000001 | Target UIAbility does not exist. |
| 16000004 | Cannot start an invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist. |
| 16000050 | Failed to connect to the system service or system server handle failed. |
| 16000073 | The app clone index is invalid. |
| 16000076 | The app instance key is invalid. |
| 16000080 | Creating a new instance is not supported. |
| 16000122 | The target component is blocked by the system module and does not support startup. |
| 16000123 | Implicit startup is not supported. |
| 16000124 | Starting a remote UIAbility is not supported. |
| 16000125 | Starting a plugin UIAbility is not supported. |
| 16000126 | Starting DLP files is not supported. |

**示例**

```ts
import { UIExtensionAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryUIExtAbility extends UIExtensionAbility {
  onForeground() {
    // 启动第一个UIAbility的主窗ID，实际使用需替换为第一个UIAbility实际主窗ID
    let primaryWindowId = 123;
    let secdonaryWant: Want = {
      bundleName: 'com.example.myapplication1',
      abilityName: 'EntryAbility'
    };
    try {
      this.context.startUIAbilitiesInSplitWindowMode(primaryWindowId, secdonaryWant).then(() => {
        console.info(`TestTag:: start succeeded.`);
      }).catch((error: BusinessError) => {
        console.error(`TestTag:: startUIAbilitiesInSplitWindowMode failed: ${JSON.stringify(error)}`);
      });
    } catch (paramError) {
      // 处理入参错误异常
      console.error(`error.code: ${paramError.code}, error.message: ${paramError.message}`);
    }
  }
}
```