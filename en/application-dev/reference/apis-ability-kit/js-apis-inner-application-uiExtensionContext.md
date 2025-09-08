# UIExtensionContext

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @zhangyafei-echo-->
<!--Designer: @zhangyafei-echo-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

UIExtensionContext provides the context environment for the [UIExtensionAbility](js-apis-app-ability-uiExtensionAbility.md). It inherits from [ExtensionContext](js-apis-inner-application-extensionContext.md) and provides UIExtensionAbility-related configurations and APIs for operating the [UIAbility](js-apis-app-ability-uiAbility.md). For example, you can use the APIs to start a UIAbility.

> **NOTE**
>
>  - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>  - The APIs of this module can be used only in the stage model.
>  - The APIs of this module must be used in the main thread, but not in child threads such as Worker and TaskPool.

## Modules to Import

```ts
import { common } from '@kit.AbilityKit';
```

## UIExtensionContext

### startAbility

startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void

Starts a UIAbility. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want required for starting the UIAbility, which contains information such as the name of the UIAbility to start.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the UIAbility is started, **err** is **undefined**; otherwise, **err** is an error object.|

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
| 16000069 | The extension cannot start the third party application. |
| 16000070 | The extension cannot start the service. |
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
// The UIExtensionAbility class does not allow direct inheritance by third-party applications. The child class ShareExtensionAbility is used here as an example.
import { ShareExtensionAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class ShareExtAbility extends ShareExtensionAbility {

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

Starts a UIAbility. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md)  | Yes| Want required for starting the UIAbility, which contains information such as the name of the UIAbility to start.|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | Yes| Extra parameters used for starting the UIAbility.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the UIAbility is started, **err** is **undefined**; otherwise, **err** is an error object.|

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
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000018 | Redirection to a third-party application is not allowed in API version greater than 11. |
| 16000019 | No matching ability is found. |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16000069 | The extension cannot start the third party application. |
| 16000070 | The extension cannot start the service. |
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
// The UIExtensionAbility class does not allow direct inheritance by third-party applications. The child class ShareExtensionAbility is used here as an example.
import { ShareExtensionAbility, Want, StartOptions } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class ShareExtAbility extends ShareExtensionAbility {
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

Starts a UIAbility. This API uses a promise to return the result.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want required for starting the UIAbility, which contains information such as the name of the UIAbility to start.|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | No| Extra parameters used for starting the UIAbility.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | that returns no value.|

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
| 16000010 | The call with the continuation and prepare continuation flag is forbidden.  |
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000018 | Redirection to a third-party application is not allowed in API version greater than 11. |
| 16000019 | No matching ability is found. |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16000069 | The extension cannot start the third party application. |
| 16000070 | The extension cannot start the service. |
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
// The UIExtensionAbility class does not allow direct inheritance by third-party applications. The child class ShareExtensionAbility is used here as an example.
import { ShareExtensionAbility, Want, StartOptions } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class ShareExtAbility extends ShareExtensionAbility {
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

Starts a UIAbility and returns the exit result of the launched UIAbility via a callback. This API uses an asynchronous callback to return the result. The following situations may be possible for a started UIAbility:
 - Normally, you can call [terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#terminateselfwithresult) to terminate the UIAbility. The result is returned to the caller.
 - If an exception occurs, for example, the UIAbility is killed, an error message, in which **resultCode** is **-1**, is returned to the initiator UIAbility.
 - If different applications call this API to start a UIAbility that uses the singleton mode and then call [terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#terminateselfwithresult) to terminate the UIAbility, the normal result is returned to the last caller, and an exception message, in which **resultCode** is **-1**, is returned to others.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-app-ability-want.md) | Yes| Want required for starting the UIAbility, which contains information such as the name of the UIAbility to start.|
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
| 16000069 | The extension cannot start the third party application. |
| 16000070 | The extension cannot start the service. |
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
// The UIExtensionAbility class does not allow direct inheritance by third-party applications. The child class ShareExtensionAbility is used here as an example.
import { ShareExtensionAbility, Want, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class ShareExtAbility extends ShareExtensionAbility {
  onForeground() {
    let want: Want = {
      deviceId: '',
      bundleName: 'com.example.myapplication',
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

Starts a UIAbility and returns the exit result of the launched UIAbility via a callback. This API uses an asynchronous callback to return the result. The following situations may be possible for a started UIAbility:
 - Normally, you can call [terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#terminateselfwithresult) to terminate the UIAbility. The result is returned to the caller.
 - If an exception occurs, for example, the UIAbility is killed, an error message, in which **resultCode** is **-1**, is returned to the initiator UIAbility.
 - If different applications call this API to start a UIAbility that uses the singleton mode and then call [terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#terminateselfwithresult) to terminate the UIAbility, the normal result is returned to the last caller, and an exception message, in which **resultCode** is **-1**, is returned to others.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-app-ability-want.md) | Yes| Want required for starting the UIAbility, which contains information such as the name of the UIAbility to start.|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | Yes| Extra parameters used for starting the UIAbility.|
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
| 16000069 | The extension cannot start the third party application. |
| 16000070 | The extension cannot start the service. |
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
// The UIExtensionAbility class does not allow direct inheritance by third-party applications. The child class ShareExtensionAbility is used here as an example.
import { ShareExtensionAbility, Want, common, StartOptions } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class ShareExtAbility extends ShareExtensionAbility {
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

Starts a UIAbility and returns the exit result of the launched UIAbility via a callback. This API uses a promise to return the result. The following situations may be possible for a started UIAbility:
 - Normally, you can call [terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#terminateselfwithresult) to terminate the UIAbility. The result is returned to the caller.
 - If an exception occurs, for example, the UIAbility is killed, an error message, in which **resultCode** is **-1**, is returned to the initiator UIAbility.
 - If different applications call this API to start a UIAbility that uses the singleton mode and then call [terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#terminateselfwithresult) to terminate the UIAbility, the normal result is returned to the last caller, and an exception message, in which **resultCode** is **-1**, is returned to others.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want required for starting the UIAbility, which contains information such as the name of the UIAbility to start.|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | No| Extra parameters used for starting the UIAbility.|


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
| 16000069 | The extension cannot start the third party application. |
| 16000070 | The extension cannot start the service. |
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
// The UIExtensionAbility class does not allow direct inheritance by third-party applications. The child class ShareExtensionAbility is used here as an example.
import { ShareExtensionAbility, Want, common, StartOptions } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class ShareExtAbility extends ShareExtensionAbility {
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


### connectServiceExtensionAbility

connectServiceExtensionAbility(want: Want, options: ConnectOptions): number

Connects this UIExtensionAbility to a ServiceExtensionAbility. It enables communication with the ServiceExtensionAbility via a proxy, allowing access to the capabilities exposed by the ServiceExtensionAbility.

ServiceExtensionAbility is a special type of [ExtensionAbility](../../application-models/extensionability-overview.md) provided by the system. It is designed to offer background services for specific scenarios and is not customizable by developers. It can be connected to by other components and handles requests in the background based on the caller information.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information required for connecting to the ServiceExtensionAbility, including the ability name and bundle name.|
| options | [ConnectOptions](js-apis-inner-ability-connectOptions.md) | Yes| Callback used to return the information indicating that the connection is successful, failed, or interrupted.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Connection ID. The client can call [disconnectServiceExtensionAbility](#disconnectserviceextensionability) with this ID for disconnection.|

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
| 16000070 | The extension cannot start the service. |

**Example**

```ts
// The UIExtensionAbility class does not allow direct inheritance by third-party applications. The child class ShareExtensionAbility is used here as an example.
import { ShareExtensionAbility, Want, common } from '@kit.AbilityKit';
import { rpc } from '@kit.IPCKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class ShareExtAbility extends ShareExtensionAbility {
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
        console.error(`onFailed, err code: ${code}.`);
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

Disconnects from a ServiceExtensionAbility. Once the connection is terminated, set the remote object, which is returned when the connection is established, to null. This API uses a promise to return the result.

ServiceExtensionAbility is a special type of [ExtensionAbility](../../application-models/extensionability-overview.md) provided by the system. It is designed to offer background services for specific scenarios and is not customizable by developers. It can be connected to by other components and handles requests in the background based on the caller information.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| connection | number | Yes| ID of the connected ServiceExtensionAbility, that is, **connectionId** returned by [connectServiceExtensionAbility](#connectserviceextensionability).|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<void> | that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

**Example**

```ts
// The UIExtensionAbility class does not allow direct inheritance by third-party applications. The child class ShareExtensionAbility is used here as an example.
import { ShareExtensionAbility } from '@kit.AbilityKit';
import { rpc } from '@kit.IPCKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class ShareExtAbility extends ShareExtensionAbility {
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
      })
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

Disconnects from a ServiceExtensionAbility. Once the connection is terminated, set the remote object, which is returned when the connection is established, to null. This API uses an asynchronous callback to return the result.

ServiceExtensionAbility is a special type of [ExtensionAbility](../../application-models/extensionability-overview.md) provided by the system. It is designed to offer background services for specific scenarios and is not customizable by developers. It can be connected to by other components and handles requests in the background based on the caller information.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| connection | number | Yes| ID of the connected ServiceExtensionAbility, that is, **connectionId** returned by **connectServiceExtensionAbility**.|
| callback | AsyncCallback\<void> | Yes| Callback used to return the result. If the disconnection is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

**Example**

```ts
// The UIExtensionAbility class does not allow direct inheritance by third-party applications. The child class ShareExtensionAbility is used here as an example.
import { ShareExtensionAbility } from '@kit.AbilityKit';
import { rpc } from '@kit.IPCKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class ShareExtAbility extends ShareExtensionAbility {
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

### terminateSelf<sup>12+</sup>

terminateSelf(callback: AsyncCallback&lt;void&gt;): void

Destroys this UIExtensionAbility and closes the corresponding window. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**Example**

```ts
// The UIExtensionAbility class does not allow direct inheritance by third-party applications. The child class ShareExtensionAbility is used here as an example.
import { ShareExtensionAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class ShareExtAbility extends ShareExtensionAbility {
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

### terminateSelf<sup>12+</sup>

terminateSelf(): Promise&lt;void&gt;

Destroys this UIExtensionAbility and closes the corresponding window. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type               | Description                                  |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | that returns no value.|

**Example**

```ts
// The UIExtensionAbility class does not allow direct inheritance by third-party applications. The child class ShareExtensionAbility is used here as an example.
import { ShareExtensionAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class ShareExtAbility extends ShareExtensionAbility {
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

### terminateSelfWithResult<sup>12+</sup>

terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback&lt;void&gt;): void

Destroys this UIExtensionAbility, closes the corresponding window, and returns the result to the caller of the UIExtensionAbility (usually a system service). This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                  |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------ |
| parameter | [AbilityResult](js-apis-inner-ability-abilityResult.md) | Yes  | Information returned to the caller of the UIExtensionAbility.                |
| callback  | AsyncCallback&lt;void&gt;                               | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**Example**

```ts
// The UIExtensionAbility class does not allow direct inheritance by third-party applications. The child class ShareExtensionAbility is used here as an example.
import { ShareExtensionAbility, Want, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class ShareExtAbility extends ShareExtensionAbility {
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

### terminateSelfWithResult<sup>12+</sup>

terminateSelfWithResult(parameter: AbilityResult): Promise&lt;void&gt;

Destroys this UIExtensionAbility, closes the corresponding window, and returns the result to the caller of the UIExtensionAbility (usually a system service). This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                  |
| --------- | ------------------------------------------------------- | ---- | -------------------------------------- |
| parameter | [AbilityResult](js-apis-inner-ability-abilityResult.md) | Yes  | Information returned to the caller of the UIExtensionAbility.|

**Return value**

| Type               | Description                                  |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

```ts
// The UIExtensionAbility class does not allow direct inheritance by third-party applications. The child class ShareExtensionAbility is used here as an example.
import { ShareExtensionAbility, Want, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class ShareExtAbility extends ShareExtensionAbility {
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

### reportDrawnCompleted<sup>12+<sup>

reportDrawnCompleted(callback: AsyncCallback\<void>): void

Called when the window content associated with the UIExtensionAbility finishes drawing. The system uses the information to optimize resource allocation, thereby enhancing the efficiency of application startup and display. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the event is reported, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

**Example**

```ts
// The UIExtensionAbility class does not allow direct inheritance by third-party applications. The child class ShareExtensionAbility is used here as an example.
import { ShareExtensionAbility, Want, UIExtensionContentSession } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

const TAG: string = '[testTag] ShareExtAbility';

export default class ShareExtAbility extends ShareExtensionAbility {
  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    console.info(TAG, `onSessionCreate, want: ${JSON.stringify(want)}`);
    let data: Record<string, UIExtensionContentSession> = {
      'session': session
    };
    let storage: LocalStorage = new LocalStorage(data);
    session.loadContent('pages/extension', storage);
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
  }
}
```

### openAtomicService<sup>12+<sup>

openAtomicService(appId: string, options?: AtomicServiceOptions): Promise&lt;AbilityResult&gt;

Opens an atomic service in an independent window and returns the result. This API uses a promise to return the result.
The following situations may be possible for a started atomic service:
 - Normally, you can call [terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#terminateselfwithresult) to terminate the atomic service. The result is returned to the caller.
 - If an exception occurs, for example, the atomic service is killed, an error message, in which **resultCode** is **-1**, is returned to the caller.
 - If different applications call this API to start an atomic service and then call [terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#terminateselfwithresult) to terminate the atomic service, the normal result is returned to the last caller, and an exception message, in which **resultCode** is **-1**, is returned to others.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| appId | string | Yes| Unique ID of the application, which is allocated by the cloud.|
| options | [AtomicServiceOptions](js-apis-app-ability-atomicServiceOptions.md) | No| Parameter carried in the request for starting the atomic service.|


**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[AbilityResult](js-apis-inner-ability-abilityResult.md)&gt; | Promise used to return the information to the caller.|

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
| 16000069 | The extension cannot start the third party application. |
| 16200001 | The caller has been released. |


**Example**

```ts
// The UIExtensionAbility class does not allow direct inheritance by third-party applications. The child class ShareExtensionAbility is used here as an example.
import { ShareExtensionAbility, common, AtomicServiceOptions } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class ShareExtAbility extends ShareExtensionAbility {
  onForeground() {
    let appId: string = '6918661953712445909';
    let options: AtomicServiceOptions = {
      displayId: 0,
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

openLink(link:string, options?: OpenLinkOptions, callback?: AsyncCallback&lt;AbilityResult&gt;): Promise&lt;void&gt;

Starts a UIAbility by using App Linking or Deep Linking. This API uses a promise to return the result.

A URL in the standard format is passed in to the **link** field to start the target UIAbility based on the implicit Want matching rules. The target UIAbility must have the following filter characteristics to process links of App Linking:
- The **actions** field contains **ohos.want.action.viewData**.
- The **entities** field contains **entity.system.browsable**.
- The **uris** field contains elements whose **scheme** is **https** and **domainVerify** is **true**.

If you want to obtain the result after the started UIAbility is terminated, set the **callback** parameter. For details about how to use this parameter, see [startAbilityForResult](#startabilityforresult).
If an input parameter is invalid, for example, a mandatory parameter is not set or the URL set in **link** is not in the standard format, an exception is thrown. If the parameter verification is successful but an error occurs when starting the target UIAbility, the error information is returned through promise.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

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
| Promise&lt;void&gt; | that returns no value.|

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
| 16000019 | No matching ability is found. |
| 16000069 | The extension cannot start the third party application. |
| 16200001 | The caller has been released. |
| 16000053 | The ability is not on the top of the UI. |

**Example**

```ts
// The UIExtensionAbility class does not allow direct inheritance by third-party applications. The child class ShareExtensionAbility is used here as an example.
import { ShareExtensionAbility, Want, UIExtensionContentSession, OpenLinkOptions } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class ShareExtAbility extends ShareExtensionAbility {
  onCreate() {
    console.info(`UIExtAbility onCreate`);
  }

  onForeground() {
    console.info(`UIExtAbility onForeground`);
  }

  onBackground() {
    console.info(`UIExtAbility onBackground`);
  }

  onDestroy() {
    console.info(`UIExtAbility onDestroy`);
  }

  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    console.info(`UIExtAbility onSessionCreate`);
    console.info(`UIExtAbility onSessionCreate, want: ${JSON.stringify(want)}`);
    let record: Record<string, UIExtensionContentSession> = {
      'session': session
    };
    let storage: LocalStorage = new LocalStorage(record);
    session.loadContent('pages/UIExtensionIndex', storage);

    let link: string = 'https://www.example.com';
    let openLinkOptions: OpenLinkOptions = {
      appLinkingOnly: true
    };
    try {
      this.context.openLink(
        link,
        openLinkOptions,
        (err, result) => {
          if (err) {
            console.error(`openLink callback failed, err code: ${err.code}, err msg: ${err.message}.`);
            return;
          }
          console.info(`openLink success, result code: ${result.resultCode} result data: ${result.want}.`);
        }
      ).then(() => {
        console.info(`open link success.`);
      }).catch((err: BusinessError) => {
        console.error(`open link failed, err code: ${err.code}, err msg: ${err.message}.`);
      });
    } catch (err) {
      let code = (err as BusinessError).code;
      let msg = (err as BusinessError).message;
      console.error(`openLink failed, err code: ${code}, err msg: ${msg}.`);
    }
  }

  onSessionDestroy(session: UIExtensionContentSession) {
    console.info(`UIExtAbility onSessionDestroy`);
  }
}
```

### startUIServiceExtensionAbility<sup>14+<sup>

startUIServiceExtensionAbility(want: Want): Promise&lt;void&gt;

Starts a UIServiceExtensionAbility.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).
>

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name  | Type                                                                        | Mandatory| Description                     |
| -------- | --------------------------------------------------------------------------- | --- |------------------------- |
| want     | [Want](js-apis-app-ability-want.md)                                        | Yes| Want for starting the UIServiceExtensionAbility.|

**Return value**

| Type               | Description                                  |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message                                                                                                   |
| -------- | ----------------------------------------------------------------------------------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801 | Capability not supported. |
| 16000001 | The specified ability does not exist.                                                                       |
| 16000002 | Incorrect ability type.                                                                                     |
| 16000004 | Cannot start an invisible component.                                                                      |
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
            let context = this.getUIContext().getHostContext() as common.UIExtensionContext;
            let startWant: Want = {
              bundleName: 'com.acts.uiserviceextensionability',
              abilityName: 'UiServiceExtAbility',
            };
            try {
              // Start the UIServiceExtensionAbility.
              context.startUIServiceExtensionAbility(startWant).then(() => {
                console.info(`startUIServiceExtensionAbility success.`);
              }).catch((error: BusinessError) => {
                console.error(`startUIServiceExtensionAbility failed, err code: ${error.code}, err msg: ${error.message}.`);
              })
            } catch (err) {
              let code = (err as BusinessError).code;
              let msg = (err as BusinessError).message;
              console.error(`startUIServiceExtensionAbility failed, err code: ${code}, err msg: ${msg}.`);
            }
          })
      }
    }
  }
}
```

### connectUIServiceExtensionAbility<sup>14+<sup>

connectUIServiceExtensionAbility(want: Want, callback: UIServiceExtensionConnectCallback) : Promise&lt;UIServiceProxy&gt;

Connects to a UIServiceExtensionAbility.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).
>

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name              | Type                            | Mandatory| Description                |
| -------------------- | -------------------------------- | ---- |  -------------------- |
| want                 | Want                             | Yes| Want information used for connection.|
| callback | [UIServiceExtensionConnectCallback](js-apis-inner-application-uiServiceExtensionconnectcallback.md) | Yes| Callback for connecting to the UIServiceExtensionAbility.    |

**Return value**

| Type                   | Description                |
| ----------------------- | -------------------- |
| Promise&lt;UIServiceProxy&gt; | When the UIServiceExtensionAbility is connected, a [UIServiceProxy](js-apis-inner-application-uiserviceproxy.md) object is returned, which can be used to send data to the UIServiceExtensionAbility.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message                                |
| -------- | ---------------------------------- |
| 201      | The application does not have permission to call the interface.        |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801      | Capability not supported.                                              |
| 16000001 | The specified ability does not exist.                                  |
| 16000002 | Incorrect ability type.                                                |
| 16000004 | Cannot start an invisible component.                                 |
| 16000005 | The specified process does not have the permission.                    |
| 16000008 | The crowdtesting application expires.                                  |
| 16000011 | The context does not exist.                                            |
| 16000013 | The application is controlled by EDM.                                  |
| 16000050 | Internal error.                                                        |
| 16000055 | Installation-free timed out.                                           |

**Example**

```ts
import { common, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Page_UIServiceExtensionAbility {
  @State uiServiceProxy: common.UIServiceProxy | null = null;

  build() {
    Column() {
      //...
      Row() {
        //...
      }.onClick(() => {
        const context = this.getUIContext().getHostContext() as common.UIExtensionContext;
        const want: Want = {
          deviceId: '',
          bundleName: 'com.example.myapplication',
          abilityName: ''
        };
        // Define a callback.
        const callback: common.UIServiceExtensionConnectCallback = {
          onData: (data: Record<string, Object>): void => {
            console.info(`onData, data: ${JSON.stringify(data)}.`);
          },
          onDisconnect: (): void => {
            console.info(`onDisconnect`);
          }
        };
        // Connect to the UIServiceExtensionAbility.
        context.connectUIServiceExtensionAbility(want, callback).then((uiServiceProxy: common.UIServiceProxy) => {
          this.uiServiceProxy = uiServiceProxy;
          console.info(`connectUIServiceExtensionAbility success`);
        }).catch((error: BusinessError) => {
          console.error(`connectUIServiceExtensionAbility failed, err code: ${error.code}, err msg: ${error.message}.`);
        })
      })
    }
  }
}
```

### disconnectUIServiceExtensionAbility<sup>14+<sup>

disconnectUIServiceExtensionAbility(proxy: UIServiceProxy): Promise&lt;void&gt;

Disconnects from a UIServiceExtensionAbility.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name              | Type                            | Mandatory| Description                |
| -------------------- | -------------------------------- | ---- | -------------------- |
| proxy  | [UIServiceProxy](js-apis-inner-application-uiserviceproxy.md)  | Yes | Proxy used returned by calling [connectUIServiceExtensionAbility](#connectuiserviceextensionability14).|

**Return value**

| Type                   | Description                |
| ----------------------- | -------------------- |
| Promise&lt;void&gt; | that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message                                                                                         |
| -------- | ------------------------------------------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000011 | The context does not exist.                                                                      |
| 16000050 | Internal error.                                                                                  |

**Example**

```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Page_UIServiceExtensionAbility {
  @State uiServiceProxy: common.UIServiceProxy | null = null;

  build() {
    Column() {
      //...
      Row() {
        //...
      }.onClick(() => {
        const context = this.getUIContext().getHostContext() as common.UIExtensionContext;
        // this.uiServiceProxy is the proxy object saved during connection.
        context.disconnectUIServiceExtensionAbility(this.uiServiceProxy).then(() => {
          console.info(`disconnectUIServiceExtensionAbility success.`);
        }).catch((error: BusinessError) => {
          console.info(`disconnectUIServiceExtensionAbility failed, err code: ${error.code}, err msg: ${error.message}.`);
        })
      })
    }
  }
}
```

### setColorMode<sup>18+</sup>

setColorMode(colorMode: ConfigurationConstant.ColorMode): void

Sets the dark/light color mode for this UIExtensionAbility. Before calling this API, ensure that the page corresponding to the UIExtensionContext has been loaded. This API can be called only by the main thread.

> **NOTE**
> - After this API is called, a new resource manager object is created. If a resource manager was previously cached, it should be updated accordingly.
> - The priority of the dark/light color mode is as follows: UIExtensionAbility dark/light color mode > Application dark/light color mode (set via [ApplicationContext.setColorMode](js-apis-inner-application-applicationContext.md#applicationcontextsetcolormode11)) > System dark/light color mode.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type         | Mandatory| Description                |
| ------ | ------------- | ---- | -------------------- |
| colorMode | [ConfigurationConstant.ColorMode](js-apis-app-ability-configurationConstant.md#colormode) | Yes  | Color mode. The options are as follows:<br> - **COLOR_MODE_DARK**: dark mode.<br> - **COLOR_MODE_LIGHT**: light mode.<br> - **COLOR_MODE_NOT_SET**: not set (following the system or application).|

**Error codes**

For details about the error codes, see [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 16000011 | The context does not exist. |

**Example**

```ts
// The UIExtensionAbility class does not allow direct inheritance by third-party applications. The child class ShareExtensionAbility is used here as an example.
import { ShareExtensionAbility, ConfigurationConstant } from '@kit.AbilityKit';

export default class MyAbility extends ShareExtensionAbility {
  onForeground() {
    let uiExtensionContext = this.context;
    uiExtensionContext.setColorMode(ConfigurationConstant.ColorMode.COLOR_MODE_DARK);
  }
}
```
