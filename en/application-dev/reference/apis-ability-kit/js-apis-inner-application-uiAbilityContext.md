# UIAbilityContext

UIAbilityContext provides the context environment for a [UIAbility](./js-apis-app-ability-uiAbility.md). It inherits from [Context](./js-apis-inner-application-context.md). For details about the relationships and differences between various types of contexts, see [Context](../../application-models/application-context-stage.md).

When a UIAbility component is instantiated, the system automatically creates the corresponding UIAbilityContext. You can use the APIs provided by UIAbilityContext to obtain the ability information (AbilityInfo), application information (ApplicationInfo), and other information, start another UIAbility, connect to system services, and destroy a UIAbility.

> **NOTE**
>
>  - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>  - The APIs of this module can be used only in the stage model.
>  - In the sample code provided in this topic, **this.context** is used to obtain UIAbilityContext, where **this** indicates an instance that inherits from UIAbility.

## Modules to Import

```ts
import { common } from '@kit.AbilityKit';
```

## UIAbilityContext

### Properties

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| abilityInfo | [AbilityInfo](js-apis-bundleManager-abilityInfo.md) | No| No| UIAbility information.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| currentHapModuleInfo | [HapModuleInfo](js-apis-bundleManager-hapModuleInfo.md) | No| No| Information about the HAP to which the UIAbility belongs.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| config | [Configuration](js-apis-app-ability-configuration.md) | No| No| UIAbility configuration, such as the language and color mode.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| windowStage<sup>12+</sup> | [window.WindowStage](../apis-arkui/arkts-apis-window-WindowStage.md) | No| No| WindowStage object. It can be called only by the main thread.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|

### startAbility

startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void

Starts an ability. This API uses an asynchronous callback to return the result. It can be called only by the main thread.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Mandatory information for starting the ability.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
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
| 16000018 | Redirection to a third-party application is not allowed in API version greater than 11. |
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

**Example**

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
          // Process service logic errors.
          console.error(`startAbility failed, code is ${err.code}, message is ${err.message}`);
          return;
        }
        // Carry out normal service processing.
        console.info('startAbility succeed');
      });
    } catch (err) {
      // Process input parameter errors.
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`startAbility failed, code is ${code}, message is ${message}`);
    }
  }
}
```

### startAbility

startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;): void

Starts an ability. This API uses an asynchronous callback to return the result. It can be called only by the main thread.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md)  | Yes| Mandatory information for starting the ability.|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | Yes| Parameters used for starting the ability.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
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
| 16000018 | Redirection to a third-party application is not allowed in API version greater than 11. |
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

**Example**

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
          // Process service logic errors.
          console.error(`startAbility failed, code is ${err.code}, message is ${err.message}`);
          return;
        }
        // Carry out normal service processing.
        console.info('startAbility succeed');
      });
    } catch (err) {
      // Process input parameter errors.
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`startAbility failed, code is ${code}, message is ${message}`);
    }
  }
}
```

### startAbility

startAbility(want: Want, options?: StartOptions): Promise&lt;void&gt;

Starts an ability. This API uses a promise to return the result. It can be called only by the main thread.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Mandatory information for starting the ability.|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | No| Parameters used for starting the ability.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
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
| 16000018 | Redirection to a third-party application is not allowed in API version greater than 11. |
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

**Example**

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
          // Carry out normal service processing.
          console.info('startAbility succeed');
        })
        .catch((err: BusinessError) => {
          // Process service logic errors.
          console.error(`startAbility failed, code is ${err.code}, message is ${err.message}`);
        });
    } catch (err) {
      // Process input parameter errors.
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`startAbility failed, code is ${code}, message is ${message}`);
    }
  }
}
```

### startAbilityForResult

startAbilityForResult(want: Want, callback: AsyncCallback&lt;AbilityResult&gt;): void

Starts a UIAbility and returns the exit result of the launched UIAbility via a callback. This API uses an asynchronous callback to return the result. It can be called only by the main thread.

The following situations may be possible for a started UIAbility:
 - Normally, you can call [terminateSelfWithResult](#terminateselfwithresult) to terminate the UIAbility. The result is returned to the caller.
 - If an exception occurs, for example, the UIAbility is killed, an error message, in which **resultCode** is **-1**, is returned to the initiator UIAbility.
 - If different applications call this API to start a UIAbility that uses the singleton mode and then call [terminateSelfWithResult](#terminateselfwithresult) to terminate the UIAbility, the normal result is returned to the last initiator UIAbility, and an error message, in which **resultCode** is **-1**, is returned to others.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-app-ability-want.md) | Yes| Mandatory information for starting the ability.|
| callback | AsyncCallback&lt;[AbilityResult](js-apis-inner-ability-abilityResult.md)&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
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
| 16000018 | Redirection to a third-party application is not allowed in API version greater than 11. |
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

**Example**

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
          // Process service logic errors.
          console.error(`startAbilityForResult failed, code is ${err.code}, message is ${err.message}`);
          return;
        }
        // Carry out normal service processing.
        console.info('startAbilityForResult succeed');
      });
    } catch (err) {
      // Process input parameter errors.
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`startAbilityForResult failed, code is ${code}, message is ${message}`);
    }
  }
}
```

### startAbilityForResult

startAbilityForResult(want: Want, options: StartOptions, callback: AsyncCallback&lt;AbilityResult&gt;): void

Starts a UIAbility and returns the exit result of the launched UIAbility via a callback. This API uses an asynchronous callback to return the result. It can be called only by the main thread.

The following situations may be possible for a started UIAbility:
 - Normally, you can call [terminateSelfWithResult](#terminateselfwithresult) to terminate the UIAbility. The result is returned to the caller.
 - If an exception occurs, for example, the UIAbility is killed, an error message, in which **resultCode** is **-1**, is returned to the initiator UIAbility.
 - If different applications call this API to start a UIAbility that uses the singleton mode and then call [terminateSelfWithResult](#terminateselfwithresult) to terminate the UIAbility, the normal result is returned to the last initiator UIAbility, and an error message, in which **resultCode** is **-1**, is returned to others.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-app-ability-want.md) | Yes| Mandatory information for starting the ability.|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | Yes| Parameters used for starting the ability.|
| callback | AsyncCallback&lt;[AbilityResult](js-apis-inner-ability-abilityResult.md)&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
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
| 16000018 | Redirection to a third-party application is not allowed in API version greater than 11. |
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

**Example**

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
          // Process service logic errors.
          console.error(`startAbilityForResult failed, code is ${err.code}, message is ${err.message}`);
          return;
        }
        // Carry out normal service processing.
        console.info('startAbilityForResult succeed');
      });
    } catch (err) {
      // Process input parameter errors.
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`startAbilityForResult failed, code is ${code}, message is ${message}`);
    }
  }
}
```


### startAbilityForResult

startAbilityForResult(want: Want, options?: StartOptions): Promise&lt;AbilityResult&gt;

Starts a UIAbility and returns the exit result of the launched UIAbility via a callback. This API uses a promise to return the result. It can be called only by the main thread.

The following situations may be possible for a started UIAbility:
 - Normally, you can call [terminateSelfWithResult](#terminateselfwithresult) to terminate the UIAbility. The result is returned to the caller.
 - If an exception occurs, for example, the UIAbility is killed, an error message, in which **resultCode** is **-1**, is returned to the initiator UIAbility.
 - If different applications call this API to start a UIAbility that uses the singleton mode and then call [terminateSelfWithResult](#terminateselfwithresult) to terminate the UIAbility, the normal result is returned to the last initiator UIAbility, and an error message, in which **resultCode** is **-1**, is returned to others.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Mandatory information for starting the ability.|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | No| Parameters used for starting the ability.|


**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[AbilityResult](js-apis-inner-ability-abilityResult.md)&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
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
| 16000018 | Redirection to a third-party application is not allowed in API version greater than 11. |
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

**Example**

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
          // Carry out normal service processing.
          console.info('startAbilityForResult succeed');
        })
        .catch((err: BusinessError) => {
          // Process service logic errors.
          console.error(`startAbilityForResult failed, code is ${err.code}, message is ${err.message}`);
        });
    } catch (err) {
      // Process input parameter errors.
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`startAbilityForResult failed, code is ${code}, message is ${message}`);
    }
  }
}
```

### terminateSelf

terminateSelf(callback: AsyncCallback&lt;void&gt;): void

Terminates this UIAbility. This API uses an asynchronous callback to return the result. It can be called only by the main thread.

> **NOTE**
>
> After this API is called, missions in the task center are not cleared by default. To clear missions, set [removeMissionAfterTerminate](../../quick-start/module-configuration-file.md#abilities) to **true**.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

**Example**

1. The following is an example of calling **terminateSelf** to terminate a UIAbility. By default, the application retains the snapshot in the recent tasks list.

    ```ts
    import { UIAbility } from '@kit.AbilityKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    export default class EntryAbility extends UIAbility {
      onForeground() {
        try {
          this.context.terminateSelf((err: BusinessError) => {
            if (err.code) {
              // Process service logic errors.
              console.error(`terminateSelf failed, code is ${err.code}, message is ${err.message}`);
              return;
            }
            // Carry out normal service processing.
            console.info('terminateSelf succeed');
          });
        } catch (err) {
          // Capture the synchronization parameter error.
          let code = (err as BusinessError).code;
          let message = (err as BusinessError).message;
          console.error(`terminateSelf failed, code is ${code}, message is ${message}`);
        }
      }
    }
    ```

2. (Optional) To remove the mission from the task center (that is, not to retain the snapshot in the recent tasks list) when terminating the UIAbility, set the **removeMissionAfterTerminate** field to **true** in the [module.json5](../../quick-start/module-configuration-file.md) file.

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

### terminateSelf

terminateSelf(): Promise&lt;void&gt;

Terminates this UIAbility. This API uses a promise to return the result. It can be called only by the main thread.

> **NOTE**
>
> After this API is called, missions in the task center are not cleared by default. To clear missions, set [removeMissionAfterTerminate](../../quick-start/module-configuration-file.md#abilities) to **true**.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |


**Example**

1. The following is an example of calling **terminateSelf** to terminate a UIAbility. By default, the application retains the snapshot in the recent tasks list.

    ```ts
    import { UIAbility } from '@kit.AbilityKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    export default class EntryAbility extends UIAbility {
      onForeground() {
        try {
          this.context.terminateSelf()
            .then(() => {
              // Carry out normal service processing.
              console.info('terminateSelf succeed');
            })
            .catch((err: BusinessError) => {
              // Process service logic errors.
              console.error(`terminateSelf failed, code is ${err.code}, message is ${err.message}`);
            });
        } catch (err) {
          // Capture the synchronization parameter error.
          let code = (err as BusinessError).code;
          let message = (err as BusinessError).message;
          console.error(`terminateSelf failed, code is ${code}, message is ${message}`);
        }
      }
    }
    ```

2. (Optional) To remove the mission from the task center (that is, not to retain the snapshot in the recent tasks list) when terminating the UIAbility, set the **removeMissionAfterTerminate** field to **true** in the [module.json5](../../quick-start/module-configuration-file.md) file.

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

### terminateSelfWithResult

terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback&lt;void&gt;): void

Terminates this UIAbility. This API uses an asynchronous callback to return the result. It can be called only by the main thread.

The result is returned to the caller when **terminateSelfWithResult** is called to terminate the UIAbility that is started by calling [startAbilityForResult](#startabilityforresult).

> **NOTE**
>
> After this API is called, missions in the task center are not cleared by default. To clear missions, set [removeMissionAfterTerminate](../../quick-start/module-configuration-file.md#abilities) to **true**.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| parameter | [AbilityResult](js-apis-inner-ability-abilityResult.md) | Yes| Information returned to the caller.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |


**Example**

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
    // AbilityResult information returned to the caller.
    let abilityResult: common.AbilityResult = {
      want,
      resultCode
    };

    try {
      this.context.terminateSelfWithResult(abilityResult, (err: BusinessError) => {
        if (err.code) {
          // Process service logic errors.
          console.error(`terminateSelfWithResult failed, code is ${err.code}, message is ${err.message}`);
          return;
        }
        // Carry out normal service processing.
        console.info('terminateSelfWithResult succeed');
      });
    } catch (err) {
      // Process input parameter errors.
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`terminateSelfWithResult failed, code is ${code}, message is ${message}`);
    }
  }
}
```


### terminateSelfWithResult

terminateSelfWithResult(parameter: AbilityResult): Promise&lt;void&gt;

Terminates this UIAbility. This API uses a promise to return the result. It can be called only by the main thread.

The result is returned to the caller when **terminateSelfWithResult** is called to terminate the UIAbility that is started by calling [startAbilityForResult](#startabilityforresult).

> **NOTE**
>
> After this API is called, missions in the task center are not cleared by default. To clear missions, set [removeMissionAfterTerminate](../../quick-start/module-configuration-file.md#abilities) to **true**.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| parameter | [AbilityResult](js-apis-inner-ability-abilityResult.md) | Yes| Information returned to the caller.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |


**Example**

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
    // AbilityResult information returned to the caller.
    let abilityResult: common.AbilityResult = {
      want,
      resultCode
    };

    try {
      this.context.terminateSelfWithResult(abilityResult)
        .then(() => {
          // Carry out normal service processing.
          console.info('terminateSelfWithResult succeed');
        })
        .catch((err: BusinessError) => {
          // Process service logic errors.
          console.error(`terminateSelfWithResult failed, code is ${err.code}, message is ${err.message}`);
        });
    } catch (err) {
      // Process input parameter errors.
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`terminateSelfWithResult failed, code is ${code}, message is ${message}`);
    }
  }
}
```

### connectServiceExtensionAbility

connectServiceExtensionAbility(want: Want, options: ConnectOptions): number

Connects this UIAbility to a [ServiceExtensionAbility](../../application-models/extensionability-overview.md). It enables communication with the ServiceExtensionAbility via a proxy, allowing access to the capabilities exposed by the ServiceExtensionAbility. It can be called only by the main thread.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information for connecting to the ServiceExtensionAbility.|
| options | [ConnectOptions](js-apis-inner-ability-connectOptions.md) | Yes| Callback used to return the information indicating that the connection is successful, failed, or interrupted.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Connection ID. A caller can call [disconnectServiceExtensionAbility](#disconnectserviceextensionability) with this ID for disconnection.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
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

**Example**

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
      // Process input parameter errors.
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`connectServiceExtensionAbility failed, code is ${code}, message is ${message}`);
    }
  }
}
```

### disconnectServiceExtensionAbility

disconnectServiceExtensionAbility(connection: number): Promise\<void>

Disconnects from a [ServiceExtensionAbility](../../application-models/extensionability-overview.md). Once the connection is terminated, set the remote object, which is returned when the connection is established, to null. This API uses a promise to return the result. It can be called only by the main thread.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| connection | number | Yes| ID of the connected ServiceExtensionAbility, that is, **connectionId** returned by [connectServiceExtensionAbility](#connectserviceextensionability).|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { rpc } from '@kit.IPCKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onForeground() {
    // connection is the return value of connectServiceExtensionAbility.
    let connection = 1;
    let commRemote: rpc.IRemoteObject | null;

    try {
      this.context.disconnectServiceExtensionAbility(connection).then(() => {
        commRemote = null;
        // Carry out normal service processing.
        console.info('disconnectServiceExtensionAbility succeed');
      }).catch((err: BusinessError) => {
        // Process service logic errors.
        console.error(`disconnectServiceExtensionAbility failed, code is ${err.code}, message is ${err.message}`);
      });
    } catch (err) {
      commRemote = null;
      // Process input parameter errors.
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`disconnectServiceExtensionAbility failed, code is ${code}, message is ${message}`);
    }
  }
}
```

### disconnectServiceExtensionAbility

disconnectServiceExtensionAbility(connection: number, callback: AsyncCallback\<void>): void

Disconnects from a [ServiceExtensionAbility](../../application-models/extensionability-overview.md). Once the connection is terminated, set the remote object, which is returned when the connection is established, to null. This API uses an asynchronous callback to return the result. It can be called only by the main thread.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| connection | number | Yes| ID of the connected ServiceExtensionAbility, that is, **connectionId** returned by [connectServiceExtensionAbility](#connectserviceextensionability).|
| callback | AsyncCallback\<void> | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { rpc } from '@kit.IPCKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onForeground() {
    // connection is the return value of connectServiceExtensionAbility.
    let connection = 1;
    let commRemote: rpc.IRemoteObject | null;

    try {
      this.context.disconnectServiceExtensionAbility(connection, (err: BusinessError) => {
        commRemote = null;
        if (err.code) {
          // Process service logic errors.
          console.error(`disconnectServiceExtensionAbility failed, code is ${err.code}, message is ${err.message}`);
          return;
        }
        // Carry out normal service processing.
        console.info('disconnectServiceExtensionAbility succeed');
      });
    } catch (err) {
      commRemote = null;
      // Process input parameter errors.
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`disconnectServiceExtensionAbility failed, code is ${code}, message is ${message}`);
    }
  }
}
```

### startAbilityByCall

startAbilityByCall(want: Want): Promise&lt;Caller&gt;

Obtains a [Caller](./js-apis-app-ability-uiAbility.md#caller) object for communicating with a [Callee](./js-apis-app-ability-uiAbility.md#callee) object. If the specified UIAbility is not started, the UIAbility will be started in the foreground or background. This API uses a promise to return the result. It can be called only by the main thread.

This API cannot be used to start the UIAbility with the launch type set to [specified](../../application-models/uiability-launch-type.md#specified).

> **NOTE**
>
> - For a successful launch in cross-device scenarios, the caller and target must be the same application and have the ohos.permission.DISTRIBUTED_DATASYNC permission.
>
> - For a successful launch in the same device scenario, the caller and target must be different applications and have the ohos.permission.ABILITY_BACKGROUND_COMMUNICATION permission (available only for system applications).
>
> - If the caller is running in the background, the ohos.permission.START_ABILITIES_FROM_BACKGROUND permission is required (available only for system applications). For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

> **NOTE**
>
> In versions earlier than API version 11, this API requires the ohos.permission.ABILITY_BACKGROUND_COMMUNICATION permission, which is available only for system applications. Since API version 11, this API requires the ohos.permission.DISTRIBUTED_DATASYNC permission.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Information about the UIAbility to start, including the ability name, module name, bundle name, device ID, and parameters (optional). If **'ohos.aafwk.param.callAbilityToForeground'** in **parameters** is set to **true**, the UIAbility is brought to the foreground. Otherwise, the UIAbility is brought to the background.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[Caller](js-apis-app-ability-uiAbility.md#caller)&gt; | Promise used to return the Caller object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
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
| 16000018 | Redirection to a third-party application is not allowed in API version greater than 11. |
| 16000050 | Internal error. |
| 16000071 | App clone is not supported. |
| 16000072 | App clone or multi-instance is not supported. |
| 16000073 | The app clone index is invalid. |
| 16000076 | The app instance key is invalid. |
| 16000077 | The number of app instances reaches the limit. |
| 16000078 | The multi-instance is not supported. |
| 16000079 | The APP_INSTANCE_KEY cannot be specified. |
| 16000080 | Creating a new instance is not supported. |

**Example**

Start an ability in the background.

```ts
import { UIAbility, Caller, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onForeground() {
    let caller: Caller;
    // Start an ability in the background by not passing parameters.
    let wantBackground: Want = {
      bundleName: 'com.example.myapplication',
      moduleName: 'entry',
      abilityName: 'EntryAbility',
      deviceId: ''
    };

    try {
      this.context.startAbilityByCall(wantBackground)
        .then((obj: Caller) => {
          // Carry out normal service processing.
          caller = obj;
          console.info('startAbilityByCall succeed');
        }).catch((err: BusinessError) => {
        // Process service logic errors.
        console.error(`startAbilityByCall failed, code is ${err.code}, message is ${err.message}`);
      });
    } catch (err) {
      // Process input parameter errors.
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`startAbilityByCall failed, code is ${code}, message is ${message}`);
    }
  }
}
```

Start an ability in the foreground.

```ts
import { UIAbility, Caller, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onForeground() {
    let caller: Caller;
    // Start an ability in the foreground with 'ohos.aafwk.param.callAbilityToForeground' in parameters set to true.
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
          // Carry out normal service processing.
          caller = obj;
          console.info('startAbilityByCall succeed');
        }).catch((err: BusinessError) => {
        // Process service logic errors.
        console.error(`startAbilityByCall failed, code is ${err.code}, message is ${err.message}`);
      });
    } catch (err) {
      // Process input parameter errors.
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`startAbilityByCall failed, code is ${code}, message is ${message}`);
    }
  }
}
```

### setMissionLabel

setMissionLabel(label: string, callback: AsyncCallback&lt;void&gt;): void

Sets a mission label for this UIAbility on the multitasking screen. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| label | string | Yes| Mission label.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

**Example**

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

### setMissionLabel

setMissionLabel(label: string): Promise&lt;void&gt;

Sets a mission label for this UIAbility on the multitasking screen. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| label | string | Yes| Mission label.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

**Example**

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

### setMissionContinueState<sup>10+</sup>

setMissionContinueState(state: AbilityConstant.ContinueState, callback: AsyncCallback&lt;void&gt;): void

Sets the mission continuation state of this UIAbility. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| state | [AbilityConstant.ContinueState](js-apis-app-ability-abilityConstant.md#continuestate10) | Yes| Mission continuation state.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

**Example**

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

### setMissionContinueState<sup>10+</sup>

setMissionContinueState(state: AbilityConstant.ContinueState): Promise&lt;void&gt;

Sets the mission continuation state of this UIAbility. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| state | [AbilityConstant.ContinueState](js-apis-app-ability-abilityConstant.md#continuestate10) | Yes| Mission continuation state.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

**Example**

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

### restoreWindowStage

restoreWindowStage(localStorage: LocalStorage): void

Restores the WindowStage data in the ability. It can be called only by the main thread.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| localStorage | LocalStorage | Yes| Storage used to store the restored window stage.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  onForeground() {
    let storage = new LocalStorage();
    this.context.restoreWindowStage(storage);
  }
}
```

### isTerminating

isTerminating(): boolean

Checks whether this UIAbility is in the terminating state.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Check result. The value **true** means that the UIAbility is in the terminating state, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 16000011 | The context does not exist. |

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  onForeground() {
    let isTerminating: boolean = this.context.isTerminating();
    console.info(`ability state is ${isTerminating}`);
  }
}
```

### requestDialogService

requestDialogService(want: Want, result: AsyncCallback&lt;dialogRequest.RequestResult&gt;): void

Starts a ServiceExtensionAbility that supports modal dialog boxes. After the ServiceExtensionAbility is started, the application displays a modal dialog box. You can call [setRequestResult](js-apis-app-ability-dialogRequest.md#requestcallbacksetrequestresult) to obtain the result. This API uses an asynchronous callback to return the result. It can be called only by the main thread.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-app-ability-want.md) | Yes| Want information for starting the ServiceExtensionAbility.|
| result | AsyncCallback&lt;[dialogRequest.RequestResult](js-apis-app-ability-dialogRequest.md#requestresult)&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
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

**Example**

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
          // Process service logic errors.
          console.error(`requestDialogService failed, code is ${err.code}, message is ${err.message}`);
          return;
        }
        // Carry out normal service processing.
        console.info(`requestDialogService succeed, result = ${JSON.stringify(result)}`);
      });
    } catch (err) {
      // Process input parameter errors.
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`requestDialogService failed, code is ${code}, message is ${message}`);
    }
  }
}
```

### requestDialogService

requestDialogService(want: Want): Promise&lt;dialogRequest.RequestResult&gt;

Starts a ServiceExtensionAbility that supports modal dialog boxes. After the ServiceExtensionAbility is started, the application displays a modal dialog box. You can call [setRequestResult](js-apis-app-ability-dialogRequest.md#requestcallbacksetrequestresult) to obtain the result. This API uses a promise to return the result. It can be called only by the main thread.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information for starting the ServiceExtensionAbility.|


**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[dialogRequest.RequestResult](js-apis-app-ability-dialogRequest.md#requestresult)&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
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

**Example**

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
          // Carry out normal service processing.
          console.info(`requestDialogService succeed, result = ${JSON.stringify(result)}`);
        })
        .catch((err: BusinessError) => {
          // Process service logic errors.
          console.error(`requestDialogService failed, code is ${err.code}, message is ${err.message}`);
        });
    } catch (err) {
      // Process input parameter errors.
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`requestDialogService failed, code is ${code}, message is ${message}`);
    }
  }
}
```

### reportDrawnCompleted<sup>10+</sup>

reportDrawnCompleted(callback: AsyncCallback\<void>): void

Called when the window content associated with the UIAbility finishes drawing. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

**Example**

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
            // Process service logic errors.
            console.error(`reportDrawnCompleted failed, code is ${err.code}, message is ${err.message}`);
            return;
          }
          // Carry out normal service processing.
          console.info('reportDrawnCompleted succeed');
        });
      } catch (err) {
        // Capture the synchronization parameter error.
        let code = (err as BusinessError).code;
        let message = (err as BusinessError).message;
        console.error(`reportDrawnCompleted failed, code is ${code}, message is ${message}`);
      }
    });
    console.info("MainAbility onWindowStageCreate");
  }
};
```

### startAbilityByType<sup>11+</sup>

startAbilityByType(type: string, wantParam: Record<string, Object>,
    abilityStartCallback: AbilityStartCallback, callback: AsyncCallback\<void>) : void

Implicitly starts a given type of UIExtensionAbility. This API uses an asynchronous callback to return the result. It can be called only in the main thread and by applications running in the foreground.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Type of the UIExtensionAbility to start. For details, see [Starting an Application of the Specified Type](../../application-models/start-intent-panel.md#matching-rules).|
| wantParam | Record&lt;string,&nbsp;Object&gt; | Yes| Extended parameter.|
| abilityStartCallback | [AbilityStartCallback](js-apis-inner-application-abilityStartCallback.md) | Yes| Callback used to return the detailed error information if the startup fails.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000050 | Internal error. |

**Example**

```ts
import { UIAbility, common } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  onForeground() {
    let wantParam: Record<string, Object> = {
      'time': '2023-10-23 20:45'
    };
    let abilityStartCallback: common.AbilityStartCallback = {
      onError: (code: number, name: string, message: string) => {
        console.info(`code:` + code + `name:` + name + `message:` + message);
      },
      onResult: (abilityResult: common.AbilityResult) => {
        console.info(`resultCode:` + abilityResult.resultCode + `bundleName:` + abilityResult.want?.bundleName);
      }
    };

    this.context.startAbilityByType("photoEditor", wantParam, abilityStartCallback, (err) => {
      if (err) {
        console.error(`startAbilityByType fail, err: ${JSON.stringify(err)}`);
      } else {
        console.info(`success`);
      }
    });
  }
}
```

### startAbilityByType<sup>11+</sup>

startAbilityByType(type: string, wantParam: Record<string, Object>,
    abilityStartCallback: AbilityStartCallback) : Promise\<void>

Implicitly starts a given type of UIExtensionAbility. This API uses a promise to return the result. It can be called only in the main thread and by applications running in the foreground.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Type of the UIExtensionAbility to start. For details, see [Starting an Application of the Specified Type](../../application-models/start-intent-panel.md#matching-rules).|
| wantParam | Record&lt;string,&nbsp;Object&gt; | Yes| Extended parameter.|
| abilityStartCallback | [AbilityStartCallback](js-apis-inner-application-abilityStartCallback.md) | Yes| Callback used to return the detailed error information if the startup fails.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000050 | Internal error. |

**Example**

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
        console.info(`code:` + code + `name:` + name + `message:` + message);
      },
      onResult: (abilityResult: common.AbilityResult) => {
        console.info(`resultCode:` + abilityResult.resultCode + `bundleName:` + abilityResult.want?.bundleName);
      }
    };

    this.context.startAbilityByType("photoEditor", wantParam, abilityStartCallback).then(() => {
      console.info(`startAbilityByType success`);
    }).catch((err: BusinessError) => {
      console.error(`startAbilityByType fail, err: ${JSON.stringify(err)}`);
    });
  }
}
```

### showAbility<sup>12+</sup>

showAbility(): Promise\<void>

Shows this UIAbility. This API uses a promise to return the result. It takes effect only on 2-in-1 devices and tablets. It can be called only by the main thread.

Before calling this API, ensure that the application has been added to the status bar.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 801 | Capability not support. |
| 16000050 | Internal error. |
| 16000067 | The StartOptions check failed. |

**Example**

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
              console.info(`showAbility success`);
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
          // Process service logic errors.
          console.error(`startAbility failed, code is ${err.code}, message is ${err.message}`);
          return;
        }
        // Carry out normal service processing.
        console.info('startAbility succeed');
      });
    } catch (err) {
      // Process input parameter errors.
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`startAbility failed, code is ${code}, message is ${message}`);
    }
  }
}
```

### hideAbility<sup>12+</sup>

hideAbility(): Promise\<void>

Hides this UIAbility. This API uses a promise to return the result. It takes effect only on 2-in-1 devices and tablets. It can be called only by the main thread.

Before calling this API, ensure that the application has been added to the status bar.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 801 | Capability not support. |
| 16000050 | Internal error. |
| 16000067 | The StartOptions check failed. |

**Example**

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
              console.info(`hideAbility success`);
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
          // Process service logic errors.
          console.error(`startAbility failed, code is ${err.code}, message is ${err.message}`);
          return;
        }
        // Carry out normal service processing.
        console.info('startAbility succeed');
      });
    } catch (err) {
      // Process input parameter errors.
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`startAbility failed, code is ${code}, message is ${message}`);
    }
  }
}
```

### moveAbilityToBackground<sup>12+<sup>
moveAbilityToBackground(): Promise\<void>

Moves this UIAbility from the foreground to the background. This API uses a promise to return the result. It can be called only by the main thread.<br><!--RP1--><!--RP1End-->

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |
| 16000061 | Operation not supported. |
| 16000065 | The API can be called only when the ability is running in the foreground. |
| 16000066 | An ability cannot switch to the foreground or background in Wukong mode. |

**Example**

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
              console.info(`moveAbilityToBackground success.`);
            }).catch((err: BusinessError) => {
              console.info(`moveAbilityToBackground error: ${JSON.stringify(err)}.`);
            });
          });
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### openAtomicService<sup>12+<sup>

openAtomicService(appId: string, options?: AtomicServiceOptions): Promise&lt;AbilityResult&gt;

Opens an atomic service in an independent window and returns the result. This API uses a promise to return the result. It can be called only by the main thread.

After an atomic service is started, the following situations may occur:
 - Normally, you can call [terminateSelfWithResult](#terminateselfwithresult) to terminate the atomic service. The result is returned to the caller.
 - If an exception occurs, for example, the atomic service is killed, an error message, in which **resultCode** is **-1**, is returned to the caller.
 - If different applications call this API to start an atomic service and then call [terminateSelfWithResult](#terminateselfwithresult) to terminate the atomic service, the normal result is returned to the last caller, and an exception message, in which **resultCode** is **-1**, is returned to others.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| appId | string | Yes| Unique ID of the application, which is allocated by the cloud.|
| options | [AtomicServiceOptions](js-apis-app-ability-atomicServiceOptions.md) | No| Parameter carried in the request for starting the atomic service.|


**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[AbilityResult](js-apis-inner-ability-abilityResult.md)&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
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

**Example**

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
          // Carry out normal service processing.
          console.info('openAtomicService succeed');
        })
        .catch((err: BusinessError) => {
          // Process service logic errors.
          console.error(`openAtomicService failed, code is ${err.code}, message is ${err.message}`);
        });
    } catch (err) {
      // Process input parameter errors.
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`openAtomicService failed, code is ${code}, message is ${message}`);
    }
  }
}
```

### openLink<sup>12+<sup>

openLink(link: string, options?: OpenLinkOptions, callback?: AsyncCallback&lt;AbilityResult&gt;): Promise&lt;void&gt;

Starts a UIAbility by using <!--RP2-->[App Linking](../../application-models/app-linking-startup.md)<!--RP2End--> or [Deep Linking](../../application-models/deep-linking-startup.md), and returns the exit result of the launched UIAbility via a callback. This API uses a promise to return the result. It can be called only by the main thread.

A URL in the standard format is passed in to the **link** field to start the target UIAbility based on the implicit Want matching rules. The target UIAbility must have the following filter characteristics to process links of App Linking:
- The **actions** field contains **ohos.want.action.viewData**.
- The **entities** field contains **entity.system.browsable**.
- The **uris** field contains elements whose **scheme** is **https** and **domainVerify** is **true**.

If you want to obtain the result after the started UIAbility is terminated, set the **callback** parameter. For details about how to use this parameter, see [startAbilityForResult](#startabilityforresult).
If an input parameter is invalid, for example, a mandatory parameter is not set or the URL set in **link** is not in the standard format, an exception is thrown. If the parameter verification is successful but an error occurs when starting the target UIAbility, the error information is returned through promise.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| link | string | Yes| URL to open, which must be in the standard format.|
| options | [OpenLinkOptions](js-apis-app-ability-openLinkOptions.md) | No| Options of the URL.|
| callback | AsyncCallback&lt;[AbilityResult](js-apis-inner-ability-abilityResult.md)&gt; | No| Callback used to return the result.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
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

**Example**

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

### backToCallerAbilityWithResult<sup>12+<sup>

backToCallerAbilityWithResult(abilityResult: AbilityResult, requestCode: string): Promise&lt;void&gt;

Returns the startup result to the caller of [startAbilityForResult](#startabilityforresult) or [openLink](#openlink12). Different from [terminateSelfWithResult](#terminateselfwithresult), this API does not destroy the current ability (target ability) when it returns the result. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| abilityResult | [AbilityResult](js-apis-inner-ability-abilityResult.md) | Yes| Result returned to the caller.|
| requestCode  |  string | Yes| Request code generated by the system when the target ability is started using [startAbilityForResult](#startabilityforresult) or [openLink](#openlink12). The value can be obtained from the [CALLER_REQUEST_CODE](js-apis-app-ability-wantConstant.md) field in **want**.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201  | The application does not have permission to call the interface. |
| 401  | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011  | The context does not exist. |
| 16000050 | Internal error. |
| 16000074 | The caller does not exist. |
| 16000075 | BackToCaller is not supported. |

**Example**
The caller uses **startAbilityForResult** to start an ability, and the target ability calls **backToCallerAbilityWithResult** to return the result to the caller.

```ts
// Caller
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
              // Use startAbilityForResult to start the target ability.
              context.startAbilityForResult(want, (err: BusinessError, result: common.AbilityResult) => {
                if (err.code) {
                  // Process service logic errors.
                  hilog.error(0x0000, 'testTag', `startAbilityForResult failed, code is ${err.code}, message is ${err.message}`);
                  this.message = `startAbilityForResult failed: code is ${err.code}, message is ${err.message}`
                  return;
                }
                // Carry out normal service processing.
                hilog.info(0x0000, 'testTag', `startAbilityForResult succeed`);
                hilog.info(0x0000, 'testTag', `AbilityResult is ${JSON.stringify(result)}`);
                this.message = `AbilityResult.resultCode: ${JSON.stringify(result.resultCode)}`
              });
            } catch (err) {
              // Process input parameter errors.
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
// Target ability
// EntryAbility.ets
import { AbilityConstant, common, UIAbility, Want, wantConstant } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    // Obtain the CALLER_REQUEST_CODE of the caller from want and save it.
    let callerRequestCode: string = want?.parameters?.[wantConstant.Params.CALLER_REQUEST_CODE] as string;
    AppStorage.setOrCreate<string>("callerRequestCode", callerRequestCode)
  }

  onNewWant(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    let callerRequestCode: string = want?.parameters?.[wantConstant.Params.CALLER_REQUEST_CODE] as string;
    AppStorage.setOrCreate<string>("callerRequestCode", callerRequestCode)
  }

  onForeground(): void {
    // Obtain the saved CALLER_REQUEST_CODE.
    let callerRequestCode: string = AppStorage.get<string>("callerRequestCode") as string;
    hilog.info(0x0000, 'testTag', `callerRequestCode is ${callerRequestCode}`);
    let want: Want = {};
    let resultCode = 100;
    let abilityResult: common.AbilityResult = {
      want,
      resultCode
    };
    try {
      // Return the result to the caller.
      this.context.backToCallerAbilityWithResult(abilityResult, callerRequestCode)
        .then(() => {
          // Carry out normal service processing.
          hilog.info(0x0000, 'testTag', 'backToCallerAbilityWithResult succeed');
        })
        .catch((err: BusinessError) => {
          // Process service logic errors.
          hilog.error(0x0000, 'testTag', `backToCallerAbilityWithResult failed, code is ${err.code}, message is ${err.message}`);
        });
    } catch (err) {
      // Capture the synchronization parameter error.
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      hilog.error(0x0000, 'testTag', `backToCallerAbilityWithResult failed, code is ${code}, message is ${message}`);
    }
  }
}
```

### setRestoreEnabled<sup>14+</sup>

setRestoreEnabled(enabled: boolean): void

Sets whether to enable backup and restore for this UIAbility.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| enabled | boolean | Yes| Whether to enable backup and restore. The value **true** means to enable backup and restore, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401 | If the input parameter is not valid parameter. |
| 16000011 | The context does not exist. |

**Example**

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

### startUIServiceExtensionAbility<sup>14+<sup>

startUIServiceExtensionAbility(want: Want): Promise&lt;void&gt;

Starts a [UIServiceExtensionAbility](../../application-models/uiserviceextension.md). This API uses a promise to return the result.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name  | Type                                    | Mandatory| Description                    |
| -------- | --------------------------------------- | ---- | ------------------------ |
| want     | [Want](js-apis-app-ability-want.md)     | Yes| Mandatory information for starting the UIServiceExtensionAbility.|

**Return value**

| Type               | Description                                  |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message                                                                                                   |
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

**Example**

```ts
import { common, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    Column() {
      Row() {
        // Create a Start button.
        Button('start ability')
          .enabled(true)
          .onClick(() => {
            let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
            let startWant: Want = {
              bundleName: 'com.acts.uiserviceextensionability',
              abilityName: 'UiServiceExtAbility',
            };
            try {
              // Start the UIServiceExtensionAbility.
              context.startUIServiceExtensionAbility(startWant).then(() => {
                console.info('startUIServiceExtensionAbility success');
              }).catch((error: BusinessError) => {
                console.info('startUIServiceExtensionAbility error', JSON.stringify(error));
              })
            } catch (err) {
              console.info('startUIServiceExtensionAbility failed', JSON.stringify(err));
            }
          })
      }
    }
  }
}
```

### connectUIServiceExtensionAbility<sup>14+<sup>

connectUIServiceExtensionAbility(want: Want, callback: UIServiceExtensionConnectCallback) : Promise&lt;UIServiceProxy&gt;

Connects to a [UIServiceExtensionAbility](../../application-models/uiserviceextension.md). This API uses a promise to return the result.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).
>

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description                |
| ------ | ---- | ---- | ---- |
| want   |[Want](js-apis-app-ability-want.md) | Yes | Mandatory information for connecting to the UIServiceExtensionAbility.|
| callback | [UIServiceExtensionConnectCallback](js-apis-inner-application-uiServiceExtensionconnectcallback.md) | Yes | Callback for connecting to the UIServiceExtensionAbility.|

**Return value**

| Type               | Description                                  |
| ------------------- | -------------------------------------- |
| Promise&lt;UIServiceProxy&gt; | Promise used to return the result, which is a [UIServiceProxy](js-apis-inner-application-uiserviceproxy.md) object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message                                                                            |
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

**Example**

```ts
import { common, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

const TAG: string = '[Extension] ';

@Entry
@Component
struct UIServiceExtensionAbility {
  dataCallBack : common.UIServiceExtensionConnectCallback = {
    // Receive data
    onData: (data: Record<string, Object>) => {
      console.info(`dataCallBack received data`, JSON.stringify(data));
    },
    // Disconnect from the UIServiceExtensionAbility.
    onDisconnect: () => {
      console.info(`dataCallBack onDisconnect`);
    }
  }

  async myConnect() {
    // Obtain the context.
    let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
    let startWant: Want = {
      deviceId: '',
      bundleName: 'com.example.myapplication',
      abilityName: 'UiServiceExtAbility'
    };

    try {
      // Connect to the UIServiceExtensionAbility.
      context.connectUIServiceExtensionAbility(startWant, this.dataCallBack)
        .then((proxy: common.UIServiceProxy) => {
          console.info(TAG + `try to connectUIServiceExtensionAbility`, JSON.stringify(proxy));
        }).catch((err: Error) => {
        let code = (err as BusinessError).code;
        let message = (err as BusinessError).message;
        console.info(TAG + `connectUIServiceExtensionAbility failed, code is ${code}, message is ${message}`);
      });
    } catch (err) {
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.info(TAG + `connectUIServiceExtensionAbility failed, code is ${code}, message is ${message}`);
    };
  }

  build() {
    RelativeContainer() {
      // Create a Connect button.
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

### disconnectUIServiceExtensionAbility<sup>14+<sup>

disconnectUIServiceExtensionAbility(proxy: UIServiceProxy): Promise&lt;void&gt;

Disconnects from a [UIServiceExtensionAbility](../../application-models/uiserviceextension.md). This API uses a promise to return the result.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).
>

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description                |
| ------ | ---- | ---- | -------------------- |
| proxy   | [UIServiceProxy](js-apis-inner-application-uiserviceproxy.md) | Yes| Proxy returned after [connectUIServiceExtensionAbility](#connectuiserviceextensionability14) is called.|

**Return value**

| Type               | Description                                  |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message                                                                               |
| -------- | ------------------------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000011 | The context does not exist.                                                                  |
| 16000050 | Internal error.                                                                                 |

**Example**

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
        // Create a Disconnect button.
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
      // Disconnect from the UIServiceExtensionAbility.
      context.disconnectUIServiceExtensionAbility(this.comProxy)
        .then(() => {
          console.info(TAG + `disconnectUIServiceExtensionAbility succeed ${this.comProxy}}`);
        }).catch((err: Error) => {
        let code = (err as BusinessError).code;
        let message = (err as BusinessError).message;
        console.info(TAG + `disconnectUIServiceExtensionAbility failed, code is ${code}, message is ${message}`);
      });
    } catch (err) {
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.info(TAG + `disconnectUIServiceExtensionAbility failed, code is ${code}, message is ${message}`);
    }
  }
}
```

### setAbilityInstanceInfo<sup>15+<sup>

setAbilityInstanceInfo(label: string, icon: image.PixelMap) : Promise&lt;void&gt;

Sets the icon and label for this UIAbility. The icon and label can be displayed in the task center and the shortcut bar. This API uses a promise to return the result.


> **NOTE**
>
> This API is available only for 2-in-1 devices.

**Required permissions**: ohos.permission.SET_ABILITY_INSTANCE_INFO

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type                                                           | Mandatory| Description                                              |
| ------ | -------------------------------------------------------------- | ---- | -------------------------------------------------- |
| label  |string                                                          | Yes  | Label. The label cannot be an empty string, and can contain a maximum of 1024 bytes. |
| icon   | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | Yes  | Icon. The recommended icon size is 512 px * 512 px.               |

**Return value**

| Type               | Description                                  |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message                                                                            |
| -------- | ----------------------------------------------------------------------------------- |
| 201      | The application does not have permission to call the interface.                     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801      | Capability not supported.                                                           |
| 16000011 | The context does not exist.                                                         |
| 16000050 | Internal error.                                                                     |

**Example**

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

### revokeDelegator<sup>17+</sup>

revokeDelegator() : Promise&lt;void&gt;

When the first UIAbility launched under a module needs to redirect to another UIAbility, the target UIAbility is known as the DelegatorAbility. For details about how to set up the DelegatorAbility, see step 1 in the example provided for this API.

Once the DelegatorAbility has completed its specific operations, you can use this API to revert to the first UIAbility. This API uses a promise to return the result.

> **NOTE**
>
> After the API is successfully called, the [Window](../apis-arkui/arkts-apis-window.md) API within the DelegatorAbility becomes invalid.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type               | Description                                  |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 801 | Capability not support. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |
| 16000065 | The API can be called only when the ability is running in the foreground. |
| 16000084 | Only DelegatorAbility is allowed to call this API, and only once. |
| 16000085 | An error occurred during the interaction between the ability and window. |

**Example**

1. Set a DelegatorAbility.

    Configure **abilitySrcEntryDelegator** and **abilityStageSrcEntryDelegator** in the [module.json5](../../quick-start/module-configuration-file.md) file. When the first UIAbility of the module is cold started, the system preferentially starts the UIAbility specified by **abilitySrcEntryDelegator**.
    > **NOTE**
    >
    >  - If the UIAbility is started by calling [startAbilityByCall](#startabilitybycall), the system ignores **abilitySrcEntryDelegator** and **abilityStageSrcEntryDelegator** configured in the [module.json5](../../quick-start/module-configuration-file.md) file.
    >  - The module name specified by **abilityStageSrcEntryDelegator** must be different from the current module name.
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

2. Revoke the DelegatorAbility.

    ```ts
    import { UIAbility } from '@kit.AbilityKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    export default class DelegatorAbility extends UIAbility {
      onForeground() {
        // After the DelegatorAbility completes the specific operation, call revokeDelegator to revert to the first UIAbility.
        this.context.revokeDelegator().then(() => {
          console.info('revokeDelegator success');
        }).catch((err: BusinessError) => {
          console.error(`revokeDelegator failed, code is ${err.code}, message is ${err.message}`);
        });
      }
    }
    ```

### setColorMode<sup>18+</sup>

setColorMode(colorMode: ConfigurationConstant.ColorMode): void

Sets the dark/light color mode for this UIAbility. Before calling this API, ensure that the page corresponding to the UIAbility has been loaded. This API can be called only by the main thread.

> **NOTE**
> - Before calling this API, ensure that the window has been created and the page corresponding to the UIAbility has been loaded (using the [loadContent](../apis-arkui/arkts-apis-window-WindowStage.md#loadcontent9) API in the [onWindowStageCreate()](js-apis-app-ability-uiAbility.md#onwindowstagecreate) lifecycle).
> - After this API is called, a new resource manager object is created. If a resource manager was previously cached, it should be updated accordingly.
> - The priority of the dark/light color mode is as follows: UIAbility dark/light color mode > Application dark/light color mode (set via [ApplicationContext.setColorMode](js-apis-inner-application-applicationContext.md#applicationcontextsetcolormode11)) > System dark/light color mode.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type         | Mandatory| Description                |
| ------ | ------------- | ---- | -------------------- |
| colorMode | [ConfigurationConstant.ColorMode](js-apis-app-ability-configurationConstant.md) | Yes  | Color mode. The options are as follows:<br> - **COLOR_MODE_DARK**: dark mode.<br> - **COLOR_MODE_LIGHT**: light mode.<br> - **COLOR_MODE_NOT_SET**: not set (following the system or application).|

**Error codes**

For details about the error codes, see [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 16000011 | The context does not exist. |

**Example**

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

### startAppServiceExtensionAbility<sup>20+</sup>

startAppServiceExtensionAbility(want: Want): Promise\<void>

Starts an [AppServiceExtensionAbility](js-apis-app-ability-appServiceExtensionAbility.md) instance. This API uses a promise to return the result.

> **NOTE**
>
> - This API is valid only for 2-in-1 devices.
> - The caller of this API must be the application to which the [AppServiceExtensionAbility](js-apis-app-ability-appServiceExtensionAbility.md) instance belongs or an application in the application list supported by the AppServiceExtensionAbility instance (configured in the **appIdentifierAllowList** property of [extensionAbilities](../../quick-start/module-configuration-file.md#extensionabilities)).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information for starting the [AppServiceExtensionAbility](js-apis-app-ability-appServiceExtensionAbility.md).|

**Return value**

| Type               | Description                                  |
| ------------------- | -------------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 801 | Capability not supported. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Cannot start an invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000019 | No matching ability is found. |
| 16000050 | Internal error. |
| 16000200 | The caller is not in the appIdentifierAllowList of the target application. |

**Example**

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
          // Carry out normal service processing.
          console.info('startAppServiceExtensionAbility succeed');
        })
        .catch((err: BusinessError) => {
          // Process service logic errors.
          console.error(`startAppServiceExtensionAbility failed, code is ${err.code}, message is ${err.message}`);
        });
    } catch (err) {
      // Process input parameter errors.
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`startAppServiceExtensionAbility failed, code is ${code}, message is ${message}`);
    }
  }
}
```

### stopAppServiceExtensionAbility<sup>20+</sup>

stopAppServiceExtensionAbility(want: Want): Promise\<void>

Stops an [AppServiceExtensionAbility](js-apis-app-ability-appServiceExtensionAbility.md) instance. This API uses a promise to return the result.

> **NOTE**
>
> - This API is valid only for 2-in-1 devices.
> - The caller of this API must be the application to which the [AppServiceExtensionAbility](js-apis-app-ability-appServiceExtensionAbility.md) instance belongs or an application in the application list supported by the AppServiceExtensionAbility instance (configured in the **appIdentifierAllowList** property of [extensionAbilities](../../quick-start/module-configuration-file.md#extensionabilities)).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information for stoping the [AppServiceExtensionAbility](js-apis-app-ability-appServiceExtensionAbility.md).|

**Return value**

| Type               | Description                                  |
| ------------------- | -------------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 801 | Capability not supported. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Cannot start an invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |
| 16000200 | The caller is not in the appIdentifierAllowList of the target application. |

**Example**

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
          // Carry out normal service processing.
          console.info('stopAppServiceExtensionAbility succeed');
        })
        .catch((err: BusinessError) => {
          // Process service logic errors.
          console.error(`stopAppServiceExtensionAbility failed, code is ${err.code}, message is ${err.message}`);
        });
    } catch (err) {
      // Process input parameter errors.
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`stopAppServiceExtensionAbility failed, code is ${code}, message is ${message}`);
    }
  }
}
```

### connectAppServiceExtensionAbility<sup>20+</sup>

connectAppServiceExtensionAbility(want: Want, callback: ConnectOptions): number

Connects this UIAbility to an [AppServiceExtensionAbility](js-apis-app-ability-appServiceExtensionAbility.md). It enables communication with the AppServiceExtensionAbility via a proxy, allowing access to the capabilities exposed by the AppServiceExtensionAbility. It can be called only by the main thread.

> **NOTE**
>
> - This API is valid only for 2-in-1 devices.
> - If the [AppServiceExtensionAbility](js-apis-app-ability-appServiceExtensionAbility.md) instance is not started, the caller of this API must be the application to which the [AppServiceExtensionAbility](js-apis-app-ability-appServiceExtensionAbility.md) instance belongs or an application in the application list supported by the AppServiceExtensionAbility instance (configured in the **appIdentifierAllowList** property of [extensionAbilities](../../quick-start/module-configuration-file.md#extensionabilities)).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information for connecting to the [AppServiceExtensionAbility](js-apis-app-ability-appServiceExtensionAbility.md).|
| callback | [ConnectOptions](js-apis-inner-ability-connectOptions.md) | Yes| Callback used to return the information indicating that the connection is successful, failed, or interrupted.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Connection ID. A caller can call [disconnectAppServiceExtensionAbility](#disconnectappserviceextensionability20) with this ID for disconnection.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 801 | Capability not supported. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Cannot start an invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000011 | The context does not exist.        |
| 16000050 | Internal error. |
| 16000201 | The target service has not been started yet. |

**Example**

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
    let callback: common.ConnectOptions = {
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
      connection = this.context.connectAppServiceExtensionAbility(want, callback);
    } catch (err) {
      // Process input parameter errors.
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`connectAppServiceExtensionAbility failed, code is ${code}, message is ${message}`);
    }
  }
}
```

### disconnectAppServiceExtensionAbility<sup>20+</sup>

disconnectAppServiceExtensionAbility(connection: number): Promise\<void>

Disconnects from an [AppServiceExtensionAbility](js-apis-app-ability-appServiceExtensionAbility.md). It can be called only by the main thread. This API uses a promise to return the result.

Once the connection is terminated, you are advised to set the remote object returned when the connection is established to null, so as to prevent communication using the remote object that may become invalid.

> **NOTE**
>
> - This API is valid only for 2-in-1 devices.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| connection | number | Yes| Connection ID returned by [connectAppServiceExtensionAbility](#connectappserviceextensionability20).|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 801 | Capability not supported. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { rpc } from '@kit.IPCKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onForeground() {
    // connection is the return value of connectAppServiceExtensionAbility.
    let connection = 1;
    let commRemote: rpc.IRemoteObject | null;

    try {
      this.context.disconnectAppServiceExtensionAbility(connection).then(() => {
        commRemote = null;
        // Carry out normal service processing.
        console.info('disconnectAppServiceExtensionAbility succeed');
      }).catch((err: BusinessError) => {
        // Process service logic errors.
        console.error(`disconnectAppServiceExtensionAbility failed, code is ${err.code}, message is ${err.message}`);
      });
    } catch (err) {
      commRemote = null;
      // Process input parameter errors.
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`disconnectAppServiceExtensionAbility failed, code is ${code}, message is ${message}`);
    }
  }
}
```

### setOnNewWantSkipScenarios<sup>20+</sup>

setOnNewWantSkipScenarios(scenarios: number): Promise\<void>

Sets whether to trigger the [onNewWant](./js-apis-app-ability-uiAbility.md#onnewwant) lifecycle callback when a UIAbility is started in a specific scenario. It can be called only by the main thread. This API uses a promise to return the result.

> **NOTE**
>
> This API is usually used within the [onCreate](./js-apis-app-ability-uiAbility.md#oncreate) lifecycle callback. You are advised to include all the enumerated values of [Scenarios](js-apis-app-ability-contextConstant.md#scenarios20) when specifying the **scenarios** parameter. For details, see the sample code below.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| scenarios | number | Yes| Scenarios. For details about the available options, see [Scenarios](./js-apis-app-ability-contextConstant.md#scenarios20).|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 16000050 | Internal error. Possible causes: Connection to service failed. |

**Example**

```ts
import { AbilityConstant, contextConstant, UIAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    let scenarios: number = contextConstant.Scenarios.SCENARIO_MOVE_MISSION_TO_FRONT |
      contextConstant.Scenarios.SCENARIO_SHOW_ABILITY |
      contextConstant.Scenarios.SCENARIO_BACK_TO_CALLER_ABILITY_WITH_RESULT;

    try {
      this.context.setOnNewWantSkipScenarios(scenarios).then(() => {
        // Carry out normal service processing.
        console.info('setOnNewWantSkipScenarios succeed');
      }).catch((err: BusinessError) => {
        // Process service logic errors.
        console.error(`setOnNewWantSkipScenarios failed, code is ${err.code}, message is ${err.message}`);
      });
    } catch (err) {
      // Process input parameter errors.
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`setOnNewWantSkipScenarios failed, code is ${code}, message is ${message}`);
    }
  }
}
```
