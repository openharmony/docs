# UIExtensionContext

**UIExtensionContext**, inherited from [ExtensionContext](js-apis-inner-application-extensionContext.md), provides the context environment for the [UIExtensionAbility](js-apis-app-ability-uiExtensionAbility.md). It provides UIExtensionAbility-related configurations and APIs for operating the [UIAbility](js-apis-app-ability-uiAbility.md). For example, you can use the APIs to start a UIAbility.

> **NOTE**
>
>  - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>  - The APIs of this module can be used only in the stage model.
>  - The APIs of this module must be used in the main thread, but not in sub-threads such as Worker and TaskPool.

## Modules to Import

```ts
import { common } from '@kit.AbilityKit';
```

## UIExtensionContext.startAbility

startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void

Starts an ability. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the ability is started, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
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
| 16000018 | The application is not allow jumping to other applications. |
| 16000019 | Can not match any component. |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16000069 | The extension cannot start the third party application. |
| 16000070 | The extension cannot start the service. |
| 16200001 | The caller has been released. |
| 16000073 | The app clone index is invalid. |

**Example**

```ts
import { UIExtensionAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIExtensionAbility {

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

## UIExtensionContext.startAbility

startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;): void

Starts an ability with the start options specified. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md)  | Yes| Want information about the target ability.|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | Yes| Parameters used for starting the ability.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the ability is started, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000001 | The specified ability does not exist. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000018 | The application is not allow jumping to other applications. |
| 16000019 | Can not match any component. |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16000069 | The extension cannot start the third party application. |
| 16000070 | The extension cannot start the service. |
| 16200001 | The caller has been released. |
| 16000073 | The app clone index is invalid. |

**Example**

```ts
import { UIExtensionAbility, Want, StartOptions } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

## UIExtensionContext.startAbility

startAbility(want: Want, options?: StartOptions): Promise&lt;void&gt;

Starts an ability. This API uses a promise to return the result.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability.|
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
| 16000018 | The application is not allow jumping to other applications. |
| 16000019 | Can not match any component. |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16000069 | The extension cannot start the third party application. |
| 16000070 | The extension cannot start the service. |
| 16200001 | The caller has been released. |
| 16000073 | The app clone index is invalid. |

**Example**

```ts
import { UIExtensionAbility, Want, StartOptions } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

## UIExtensionContext.startAbilityForResult

startAbilityForResult(want: Want, callback: AsyncCallback&lt;AbilityResult&gt;): void

Starts an ability and obtains the result when the ability is terminated. This API uses an asynchronous callback to return the result. The following situations may be possible for a started ability:
 - Normally, you can call [terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult) to terminate the ability. The result is returned to the caller.
 - If an exception occurs, for example, the ability is killed, an error message, in which **resultCode** is **-1**, is returned to the caller.
 - If different applications call this API to start an ability that uses the singleton mode and then call [terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult) to terminate the ability, the normal result is returned to the last caller, and an exception message, in which **resultCode** is **-1**, is returned to others.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability.|
| callback | AsyncCallback&lt;[AbilityResult](js-apis-inner-ability-abilityResult.md)&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
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
| 16000018 | The application is not allow jumping to other applications. |
| 16000019 | Can not match any component. |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16000069 | The extension cannot start the third party application. |
| 16000070 | The extension cannot start the service. |
| 16200001 | The caller has been released. |
| 16000073 | The app clone index is invalid. |

**Example**

```ts
import { UIExtensionAbility, Want, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIExtensionAbility {
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

## UIExtensionContext.startAbilityForResult

startAbilityForResult(want: Want, options: StartOptions, callback: AsyncCallback&lt;AbilityResult&gt;): void

Starts an ability with the start options specified and obtains the result when the ability is terminated. This API uses an asynchronous callback to return the result. The following situations may be possible for a started ability:
 - Normally, you can call [terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult) to terminate the ability. The result is returned to the caller.
 - If an exception occurs, for example, the ability is killed, an error message, in which **resultCode** is **-1**, is returned to the caller.
 - If different applications call this API to start an ability that uses the singleton mode and then call [terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult) to terminate the ability, the normal result is returned to the last caller, and an exception message, in which **resultCode** is **-1**, is returned to others.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability.|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | Yes| Parameters used for starting the ability.|
| callback | AsyncCallback&lt;[AbilityResult](js-apis-inner-ability-abilityResult.md)&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000001 | The specified ability does not exist. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000018 | The application is not allow jumping to other applications. |
| 16000019 | Can not match any component. |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16000069 | The extension cannot start the third party application. |
| 16000070 | The extension cannot start the service. |
| 16200001 | The caller has been released. |
| 16000073 | The app clone index is invalid. |

**Example**

```ts
import { UIExtensionAbility, Want, common, StartOptions } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

## UIExtensionContext.startAbilityForResult

startAbilityForResult(want: Want, options?: StartOptions): Promise&lt;AbilityResult&gt;

Starts an ability and obtains the result when the ability is terminated. This API uses a promise to return the result. The following situations may be possible for a started ability:
 - Normally, you can call [terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult) to terminate the ability. The result is returned to the caller.
 - If an exception occurs, for example, the ability is killed, an error message, in which **resultCode** is **-1**, is returned to the caller.
 - If different applications call this API to start an ability that uses the singleton mode and then call [terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult) to terminate the ability, the normal result is returned to the last caller, and an exception message, in which **resultCode** is **-1**, is returned to others.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability.|
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
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation flag is forbidden. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000018 | The application is not allow jumping to other applications. |
| 16000019 | Can not match any component. |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16000069 | The extension cannot start the third party application. |
| 16000070 | The extension cannot start the service. |
| 16200001 | The caller has been released. |
| 16000073 | The app clone index is invalid. |

**Example**

```ts
import { UIExtensionAbility, Want, common, StartOptions } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

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


## UIExtensionContext.connectServiceExtensionAbility

connectServiceExtensionAbility(want: Want, options: ConnectOptions): number

Connects this ability to a ServiceExtensionAbility.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information for connecting to the ServiceExtensionAbility.|
| options | [ConnectOptions](js-apis-inner-ability-connectOptions.md) | Yes| Instance of the callback function after the connection to the ServiceExtensionAbility is set up.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Result code of the connection.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
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
| 16000070 | The extension cannot start the service. |

**Example**

```ts
import { UIExtensionAbility, Want, common } from '@kit.AbilityKit';
import { rpc } from '@kit.IPCKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
      // Process input parameter errors.
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`connectServiceExtensionAbility failed, code is ${code}, message is ${message}`);
    }
  }
}
```

## UIExtensionContext.disconnectServiceExtensionAbility

disconnectServiceExtensionAbility(connection: number): Promise\<void>

Disconnects this ability from a ServiceExtensionAbility and after the successful disconnection, sets the remote object returned upon the connection to void. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| connection | number | Yes| Digital code of the connected ServiceExtensionAbility, that is, connectionId returned by **connectServiceExtensionAbility**.|

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
import { UIExtensionAbility } from '@kit.AbilityKit';
import { rpc } from '@kit.IPCKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIExtensionAbility {
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

## UIExtensionContext.disconnectServiceExtensionAbility

disconnectServiceExtensionAbility(connection: number, callback: AsyncCallback\<void>): void

Disconnects this ability from a ServiceExtensionAbility and after the successful disconnection, sets the remote object returned upon the connection to void. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| connection | number | Yes| Digital code of the connected ServiceExtensionAbility, that is, connectionId returned by **connectServiceExtensionAbility**.|
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
import { UIExtensionAbility } from '@kit.AbilityKit';
import { rpc } from '@kit.IPCKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIExtensionAbility {
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

## UIExtensionContext.terminateSelf<sup>12+</sup>

terminateSelf(callback: AsyncCallback&lt;void&gt;): void

Stops the window object corresponding to this UIExtensionContext. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If the window object is stopped, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**Example**

```ts
import { UIExtensionAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIExtensionAbility {
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

## UIExtensionContext.terminateSelf<sup>12+</sup>

terminateSelf(): Promise&lt;void&gt;

Stops the window object corresponding to this UIExtensionContext. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type               | Description                                  |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
import { UIExtensionAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIExtensionAbility {
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

## UIExtensionContext.terminateSelfWithResult<sup>12+</sup>

terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback&lt;void&gt;): void

Stops the window object corresponding to this UIExtensionContext and returns the result to the UIExtensionComponent. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                  |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------ |
| parameter | [AbilityResult](js-apis-inner-ability-abilityResult.md) | Yes  | Result returned to the UIExtensionComponent.                |
| callback  | AsyncCallback&lt;void&gt;                               | Yes  | Callback used to return the result. If the window object is stopped, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**Example**

```ts
import { UIExtensionAbility, Want, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIExtensionAbility {
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

## UIExtensionContext.terminateSelfWithResult<sup>12+</sup>

terminateSelfWithResult(parameter: AbilityResult): Promise&lt;void&gt;

Stops the window object corresponding to this UIExtensionContext and returns the result to the UIExtensionComponent. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                  |
| --------- | ------------------------------------------------------- | ---- | -------------------------------------- |
| parameter | [AbilityResult](js-apis-inner-ability-abilityResult.md) | Yes  | Result returned to the UIExtensionComponent.|

**Return value**

| Type               | Description                                  |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

```ts
import { UIExtensionAbility, Want, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIExtensionAbility {
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

## UIExtensionContext.reportDrawnCompleted<sup>12+<sup>

reportDrawnCompleted(callback: AsyncCallback\<void>): void

Reports an event indicating that page loading is complete (**onSessionCreate()** is successfully called). This API uses an asynchronous callback to return the result.

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
import { UIExtensionAbility, Want, UIExtensionContentSession } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

const TAG: string = '[testTag] UIExtAbility';

export default class UIExtAbility extends UIExtensionAbility {
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

## UIExtensionContext.openAtomicService<sup>12+<sup>
openAtomicService(appId: string, options?: AtomicServiceOptions): Promise&lt;AbilityResult&gt;

Starts an [EmbeddableUIAbility](js-apis-app-ability-embeddableUIAbility.md) in jump-out mode and returns the result. This API uses a promise to return the result.
The following situations may be possible for a started EmbeddableUIAbility:
 - Normally, you can call [terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult) to terminate the EmbeddableUIAbility. The result is returned to the caller.
 - If an exception occurs, for example, the EmbeddableUIAbility is killed, an error message, in which **resultCode** is **-1**, is returned to the caller.
 - If different applications call this API to start an EmbeddableUIAbility and then call [terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult) to terminate the EmbeddableUIAbility, the normal result is returned to the last caller, and an exception message, in which **resultCode** is **-1**, is returned to others.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| appId | string | Yes| Unique ID of the application, which is allocated by the cloud.|
| options | [AtomicServiceOptions](js-apis-app-ability-atomicServiceOptions.md) | No| Parameter carried in the request for starting the atomic service in jump-out mode.|


**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[AbilityResult](js-apis-inner-ability-abilityResult.md)&gt; | Promise used to return the result, which is an [AbilityResult](js-apis-inner-ability-abilityResult.md) object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000002 | Incorrect ability type. |
| 16000003 | The appId does not exist. |
| 16000004 | Can not start invisible component. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled.        |
| 16000050 | Internal error. |
| 16000069 | The extension cannot start the third party application. |
| 16200001 | The caller has been released. |


**Example**

```ts
import { UIExtensionAbility, common, AtomicServiceOptions } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIExtensionAbility {
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

## UIExtensionContext.openLink<sup>12+<sup>
openLink(link:string, options?: OpenLinkOptions, callback?: AsyncCallback&lt;AbilityResult&gt;): Promise&lt;void&gt;

Starts a UIAbility through App Linking. This API uses a promise to return the result.

A URL in the standard format is passed in to the **link** field to start the target UIAbility based on the implicit Want matching rules. The target UIAbility must have the following filter characteristics to process links of App Linking:
- The **actions** field contains **ohos.want.action.viewData**.
- The **entities** field contains **entity.system.browsable**.
- The **uris** field contains elements whose **scheme** is **https** and **domainVerify** is **true**.

If you want to obtain the result after the started UIAbility is terminated, set the **callback** parameter. For details about how to use this parameter, see [startAbilityForResult](#uiextensioncontextstartabilityforresult).
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
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
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
| 16000019 | Can not match any component. |
| 16000069 | The extension cannot start the third party application. |
| 16200001 | The caller has been released. |
| 16000053 | The ability is not on the top of the UI. |

**Example**

```ts
import { UIExtensionAbility, Want, UIExtensionContentSession, OpenLinkOptions } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

function log(info: string) {
  console.error(`MyUIExtension:: ${JSON.stringify(info)}`);
}

export default class UIExtAbility extends UIExtensionAbility {
  onCreate() {
    log(`UIExtAbility onCreate`);
  }

  onForeground() {
    log(`UIExtAbility onForeground`);
  }

  onBackground() {
    log(`UIExtAbility onBackground`);
  }

  onDestroy() {
    log(`UIExtAbility onDestroy`);
  }

  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    log(`UIExtAbility onSessionCreate`);
    log(`UIExtAbility onSessionCreate, want: ${JSON.stringify(want)}`);
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
          log(`openLink callback error.code: ${JSON.stringify(err)}`);
          log(`openLink callback result: ${JSON.stringify(result.resultCode)}`);
          log(`openLink callback result data: ${JSON.stringify(result.want)}`);
        }
      ).then(() => {
        log(`open link success.`);
      }).catch((err: BusinessError) => {
        log(`open link failed, errCode ${JSON.stringify(err.code)}`);
      });
    }
    catch (e) {
      log(`exception occured, errCode ${JSON.stringify(e.code)}`);
    }

  }

  onSessionDestroy(session: UIExtensionContentSession) {
    log(`UIExtAbility onSessionDestroy`);
  }
}
```

## UIExtensionContext.startUIServiceExtensionAbility<sup>13+<sup>
startUIServiceExtensionAbility(want: Want): Promise&lt;void&gt;

Starts a UIServiceExtensionAbility.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).
>


**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name  | Type                                                                        |Read Only| Optional| Description                     |
| -------- | ---------------------------------------------------------------------------- | ---- |  ---- |------------------------- |
| want     | [Want](js-apis-app-ability-want.md)                                        | Yes| No | Want information for starting the UIServiceExtensionAbility.|

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
| 801 | The Ability is not supported. |
| 16000001 | The specified ability does not exist.                                                                       |
| 16000002 | Incorrect ability type.                                                                                     |
| 16000004 | Can not start invisible component.                                                                          |
| 16000005 | The specified process does not have the permission.                                                         |
| 16000006 | Cross-user operations are not allowed.                                                                      |
| 16000008 | The crowdtesting application expires.                                                                       |
| 16000011 | The context does not exist.                                                                                 |
| 16000012 | The application is controlled.                                                                              |
| 16000013 | The application is controlled by EDM.                                                                       |
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
            let context = getContext(this) as common.UIExtensionContext;
            let startWant: Want = {
              bundleName: 'com.acts.uiserviceextensionability',
              abilityName: 'UiServiceExtAbility',
            };
            try {
              // Start the UIServiceExtensionAbility.
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

## UIExtensionContext.connectUIServiceExtensionAbility<sup>13+<sup>
connectUIServiceExtensionAbility(want: Want, callback: UIServiceExtensionConnectCallback) : Promise&lt;UIServiceProxy&gt;

Connects to a UIServiceExtensionAbility.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).
>


**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name              | Type                            | Read Only| Optional| Description                |
| -------------------- | -------------------------------- | ---- | -------------------- |  -------------------- |
| want                 | Want                             | Yes | No| Want information used for connection.|
| callback | [UIServiceExtensionConnectCallback](js-apis-inner-application-uiServiceExtensionconnectcallback.md) | Yes|No | Callback for connecting to the UIServiceExtensionAbility.    |

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
| 16000001 | The specified ability does not  |
| 16000002 | Incorrect ability type.                                                |
| 16000004 | Can not start invisible component.                                     |
| 16000005 | The specified process does not have the permission.                    |
| 16000006 | Cross-user operations are not allowed.                                 |
| 16000008 | The crowdtesting application expires.                                  |
| 16000011 | The context does not exist.                                            |
| 16000050 | Internal error.                                                        |
| 16000053 | The ability is not on the top of the UI.                               |
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
        const context = getContext(this) as common.UIExtensionContext;
        const want: Want = {
          deviceId: '',
          bundleName: 'com.example.myapplication',
          abilityName: ''
        };
        // Define a callback.
        const callback: common.UIServiceExtensionConnectCallback = {
          onData: (data: Record<string, Object>): void => {
            console.log('onData:', JSON.stringify(data));
          },
          onDisconnect: (): void => {
            console.log('onDisconnect');
          }
        };
        // Connect to the UIServiceExtensionAbility.
        context.connectUIServiceExtensionAbility(want, callback).then((uiServiceProxy: common.UIServiceProxy) => {
          this.uiServiceProxy = uiServiceProxy;
          console.log('connectUIServiceExtensionAbility success');
        }).catch((error: BusinessError) => {
          console.log('connectUIServiceExtensionAbility failed', JSON.stringify(error));
        })
      })
    }
  }
}
```

## UIExtensionContext.disconnectUIServiceExtensionAbility<sup>13+<sup>
disconnectUIServiceExtensionAbility(proxy: UIServiceProxy): Promise&lt;void&gt;

Disconnects a UIServiceExtensionAbility.


**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name              | Type                            | Read Only| Optional| Description                |
| -------------------- | -------------------------------- | ---- | -------------------- | -------------------- |
| proxy  | [UIServiceProxy](js-apis-inner-application-uiserviceproxy.md)  | Yes| No | Proxy used returned by calling [connectUIServiceExtensionAbility](#uiextensioncontextconnectuiserviceextensionability13).|

**Return value**

| Type                   | Description                |
| ----------------------- | -------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

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
        const context = getContext(this) as common.UIExtensionContext;
        // this.uiServiceProxy is the proxy object saved during connection.
        context.disconnectUIServiceExtensionAbility(this.uiServiceProxy).then(() => {
          console.log('disconnectUIServiceExtensionAbility success');
        }).catch((error: BusinessError) => {
          console.log('disconnectUIServiceExtensionAbility failed', JSON.stringify(error));
        })
      })
    }
  }
}
```
