# UIAbilityContext

**UIAbilityContext**, inherited from [Context](js-apis-inner-application-context.md), provides the context environment for [UIAbility](js-apis-app-ability-uiAbility.md). **UIAbilityContext** provides UIAbility-related configuration and APIs for operating UIAbilities and ServiceExtensionAbilities. For example, you can use the APIs to start a UIAbility, terminate a UIAbility to which the UIAbilityContext belongs, and start, terminate, connect to, or disconnect from a ServiceExtensionAbility.

> **NOTE**
>
>  - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>  - The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import common from '@ohos.app.ability.common';
```

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| abilityInfo | [AbilityInfo](js-apis-bundleManager-abilityInfo.md) | Yes| No| UIAbility information.|
| currentHapModuleInfo | [HapModuleInfo](js-apis-bundleManager-hapModuleInfo.md) | Yes| No| HAP information.|
| config | [Configuration](js-apis-app-ability-configuration.md) | Yes| No| UIAbility configuration, such as the language and color mode.|

> **NOTE**
>
> In the sample code provided in this topic, **this.context** is used to obtain **UIAbilityContext**, where **this** indicates a UIAbility instance inherited from **UIAbility**. To use **UIAbilityContext** APIs on pages, see [Obtaining the Context of UIAbility](../../application-models/uiability-usage.md#obtaining-the-context-of-uiability).

## UIAbilityContext.startAbility

startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void;

Starts an ability. This API uses an asynchronous callback to return the result.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **exported** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).
 - If the ability to start is in another mission stack and the result needs to be returned to the caller, set the **want** parameter by following the description provided in [Want](js-apis-app-ability-want.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
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

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

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
  ```

## UIAbilityContext.startAbility

startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;): void;

Starts an ability with the start options specified. This API uses an asynchronous callback to return the result.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **exported** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md)  | Yes| Want information about the target ability.|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | Yes| Parameters used for starting the ability.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
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

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
import Want from '@ohos.app.ability.Want';
import StartOptions from '@ohos.app.ability.StartOptions';
import { BusinessError } from '@ohos.base';

let want: Want = {
  deviceId: '',
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let options: StartOptions = {
  windowMode: 0
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
  ```

## UIAbilityContext.startAbility

startAbility(want: Want, options?: StartOptions): Promise&lt;void&gt;;

Starts an ability. This API uses a promise to return the result.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **exported** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability.|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | No| Parameters used for starting the ability.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

| ID| Error Message|
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

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
import Want from '@ohos.app.ability.Want';
import StartOptions from '@ohos.app.ability.StartOptions';
import { BusinessError } from '@ohos.base';

let want: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let options: StartOptions = {
  windowMode: 0,
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
  ```

## UIAbilityContext.startAbilityForResult

startAbilityForResult(want: Want, callback: AsyncCallback&lt;AbilityResult&gt;): void;

Starts an ability. This API uses an asynchronous callback to return the result when the ability is terminated. The following situations may be possible for a started ability:
 - Normally, you can call [terminateSelfWithResult](#uiabilitycontextterminateselfwithresult) to terminate the ability. The result is returned to the caller.
 - If an exception occurs, for example, the ability is killed, an error message, in which **resultCode** is **-1**, is returned to the caller.
 - If different applications call this API to start an ability that uses the singleton mode and then call [terminateSelfWithResult](#uiabilitycontextterminateselfwithresult) to terminate the ability, the normal result is returned to the last caller, and an error message, in which **resultCode** is **-1**, is returned to others.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **exported** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability.|
| callback | AsyncCallback&lt;[AbilityResult](js-apis-inner-ability-abilityResult.md)&gt; | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
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

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import common from '@ohos.app.ability.common';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

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
    // Carry out normal service processing.
    console.info('startAbilityForResult succeed');
  });
} catch (err) {
  // Process input parameter errors.
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`startAbilityForResult failed, code is ${code}, message is ${message}`);
}
  ```

## UIAbilityContext.startAbilityForResult

startAbilityForResult(want: Want, options: StartOptions, callback: AsyncCallback&lt;AbilityResult&gt;): void;

Starts an ability with the start options specified. This API uses an asynchronous callback to return the result when the ability is terminated. The following situations may be possible for a started ability:
 - Normally, you can call [terminateSelfWithResult](#uiabilitycontextterminateselfwithresult) to terminate the ability. The result is returned to the caller.
 - If an exception occurs, for example, the ability is killed, an error message, in which **resultCode** is **-1**, is returned to the caller.
 - If different applications call this API to start an ability that uses the singleton mode and then call [terminateSelfWithResult](#uiabilitycontextterminateselfwithresult) to terminate the ability, the normal result is returned to the last caller, and an error message, in which **resultCode** is **-1**, is returned to others.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **exported** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability.|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | Yes| Parameters used for starting the ability.|
| callback | AsyncCallback&lt;[AbilityResult](js-apis-inner-ability-abilityResult.md)&gt; | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
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

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import common from '@ohos.app.ability.common';
import Want from '@ohos.app.ability.Want';
import StartOptions from '@ohos.app.ability.StartOptions';
import { BusinessError } from '@ohos.base';

let want: Want = {
  deviceId: '',
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let options: StartOptions = {
  windowMode: 0,
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
  ```


## UIAbilityContext.startAbilityForResult

startAbilityForResult(want: Want, options?: StartOptions): Promise&lt;AbilityResult&gt;;

Starts an ability. This API uses a promise to return the result when the ability is terminated. The following situations may be possible for a started ability:
 - Normally, you can call [terminateSelfWithResult](#uiabilitycontextterminateselfwithresult) to terminate the ability. The result is returned to the caller.
 - If an exception occurs, for example, the ability is killed, an error message, in which **resultCode** is **-1**, is returned to the caller.
 - If different applications call this API to start an ability that uses the singleton mode and then call [terminateSelfWithResult](#uiabilitycontextterminateselfwithresult) to terminate the ability, the normal result is returned to the last caller, and an error message, in which **resultCode** is **-1**, is returned to others.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **exported** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

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

| ID| Error Message|
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

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import common from '@ohos.app.ability.common';
import Want from '@ohos.app.ability.Want';
import StartOptions from '@ohos.app.ability.StartOptions';
import { BusinessError } from '@ohos.base';

let want: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let options: StartOptions = {
  windowMode: 0,
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
  ```

## UIAbilityContext.startAbilityForResultWithAccount

startAbilityForResultWithAccount(want: Want, accountId: number, callback: AsyncCallback\<AbilityResult>): void;

Starts an ability with the account ID specified. This API uses an asynchronous callback to return the result when the ability is terminated.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **exported** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

> **NOTE**
> 
> The **ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS** permission is not required when **accountId** specifies the current user.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getCreatedOsAccountsCount).|
| callback | AsyncCallback&lt;[AbilityResult](js-apis-inner-ability-abilityResult.md)&gt; | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
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

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import common from '@ohos.app.ability.common';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

let want: Want = {
  deviceId: '',
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let accountId = 100;

try {
  this.context.startAbilityForResultWithAccount(want, accountId, (err: BusinessError, result: common.AbilityResult) => {
    if (err.code) {
      // Process service logic errors.
      console.error(`startAbilityForResultWithAccount failed, code is ${err.code}, message is ${err.message}`);
      return;
    }
    // Carry out normal service processing.
    console.info('startAbilityForResultWithAccount succeed');
  });
} catch (err) {
  // Process input parameter errors.
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`startAbilityForResultWithAccount failed, code is ${code}, message is ${message}`);
}
  ```


## UIAbilityContext.startAbilityForResultWithAccount

startAbilityForResultWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback\<void\>): void;

Starts an ability with the start options and account ID specified. This API uses an asynchronous callback to return the result when the ability is terminated.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **exported** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

> **NOTE**
> 
> The **ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS** permission is not required when **accountId** specifies the current user.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getCreatedOsAccountsCount).|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | Yes| Parameters used for starting the ability.|
| callback | AsyncCallback\<void\> | Yes| Callback invoked when the ability is terminated.|

**Error codes**

| ID| Error Message|
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

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
import Want from '@ohos.app.ability.Want';
import StartOptions from '@ohos.app.ability.StartOptions';
import { BusinessError } from '@ohos.base';

let want: Want = {
  deviceId: '',
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let accountId = 100;
let options: StartOptions = {
  windowMode: 0
};

try {
  this.context.startAbilityForResultWithAccount(want, accountId, options, (err: BusinessError) => {
    if (err.code) {
      // Process service logic errors.
      console.error(`startAbilityForResultWithAccount failed, code is ${err.code}, message is ${err.message}`);
      return;
    }
    // Carry out normal service processing.
    console.info('startAbilityForResultWithAccount succeed');
  });
} catch (err) {
  // Process input parameter errors.
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`startAbilityForResultWithAccount failed, code is ${code}, message is ${message}`);
}
  ```


## UIAbilityContext.startAbilityForResultWithAccount

startAbilityForResultWithAccount(want: Want, accountId: number, options?: StartOptions): Promise\<AbilityResult\>;

Starts an ability with the account ID specified. This API uses a promise to return the result when the ability is terminated.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **exported** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

> **NOTE**
> 
> The **ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS** permission is not required when **accountId** specifies the current user.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getCreatedOsAccountsCount).|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | No| Parameters used for starting the ability.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[AbilityResult](js-apis-inner-ability-abilityResult.md)&gt; | Promise used to return the ability result when the ability is terminated.|

**Error codes**

| ID| Error Message|
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

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import common from '@ohos.app.ability.common';
import Want from '@ohos.app.ability.Want';
import StartOptions from '@ohos.app.ability.StartOptions';
import { BusinessError } from '@ohos.base';

let want: Want = {
  deviceId: '',
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let accountId = 100;
let options: StartOptions = {
  windowMode: 0
};

try {
  this.context.startAbilityForResultWithAccount(want, accountId, options)
    .then((result: common.AbilityResult) => {
      // Carry out normal service processing.
      console.info('startAbilityForResultWithAccount succeed');
    })
    .catch((err: BusinessError) => {
      // Process service logic errors.
      console.error(`startAbilityForResultWithAccount failed, code is ${err.code}, message is ${err.message}`);
    });
} catch (err) {
  // Process input parameter errors.
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`startAbilityForResultWithAccount failed, code is ${code}, message is ${message}`);
}
  ```
## UIAbilityContext.startServiceExtensionAbility

startServiceExtensionAbility(want: Want, callback: AsyncCallback\<void>): void;

Starts a ServiceExtensionAbility. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ServiceExtensionAbility.|
| callback | AsyncCallback\<void\> | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

let want: Want = {
  deviceId: '',
  bundleName: 'com.example.myapplication',
  abilityName: 'ServiceExtensionAbility'
};

try {
  this.context.startServiceExtensionAbility(want)
    .then(() => {
      // Carry out normal service processing.
      console.info('startServiceExtensionAbility succeed');
    })
    .catch((err: BusinessError) => {
      // Process service logic errors.
      console.error(`startServiceExtensionAbility failed, code is ${err.code}, message is ${err.message}`);
    });
} catch (err) {
  // Process input parameter errors.
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`startServiceExtensionAbility failed, code is ${code}, message is ${message}`);
}
  ```

## UIAbilityContext.startServiceExtensionAbility

startServiceExtensionAbility(want: Want): Promise\<void>;

Starts a ServiceExtensionAbility. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ServiceExtensionAbility.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

let want: Want = {
  deviceId: '',
  bundleName: 'com.example.myapplication',
  abilityName: 'ServiceExtensionAbility'
};

try {
  this.context.startServiceExtensionAbility(want)
    .then(() => {
      // Carry out normal service processing.
      console.info('startServiceExtensionAbility succeed');
    })
    .catch((err: BusinessError) => {
      // Process service logic errors.
      console.error(`startServiceExtensionAbility failed, code is ${err.code}, message is ${err.message}`);
    });
} catch (err) {
  // Process input parameter errors.
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`startServiceExtensionAbility failed, code is ${code}, message is ${message}`);
}
  ```

## UIAbilityContext.startServiceExtensionAbilityWithAccount

startServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void;

Starts a ServiceExtensionAbility with the account ID specified. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> The **ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS** permission is not required when **accountId** specifies the current user.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ServiceExtensionAbility.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getCreatedOsAccountsCount).|
| callback | AsyncCallback\<void\> | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

let want: Want = {
  deviceId: '',
  bundleName: 'com.example.myapplication',
  abilityName: 'ServiceExtensionAbility'
};
let accountId = 100;

try {
  this.context.startServiceExtensionAbilityWithAccount(want, accountId, (err: BusinessError) => {
    if (err.code) {
      // Process service logic errors.
      console.error(`startServiceExtensionAbilityWithAccount failed, code is ${err.code}, message is ${err.message}`);
      return;
    }
    // Carry out normal service processing.
    console.info('startServiceExtensionAbilityWithAccount succeed');
  });
} catch (err) {
  // Process input parameter errors.
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`startServiceExtensionAbilityWithAccount failed, code is ${code}, message is ${message}`);
}
  ```

## UIAbilityContext.startServiceExtensionAbilityWithAccount

startServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise\<void>;

Starts a ServiceExtensionAbility with the account ID specified. This API uses a promise to return the result.

> **NOTE**
> 
> The **ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS** permission is not required when **accountId** specifies the current user.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getCreatedOsAccountsCount).|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

let want: Want = {
  deviceId: '',
  bundleName: 'com.example.myapplication',
  abilityName: 'ServiceExtensionAbility'
};
let accountId = 100;

try {
  this.context.startServiceExtensionAbilityWithAccount(want, accountId)
    .then(() => {
      // Carry out normal service processing.
      console.info('startServiceExtensionAbilityWithAccount succeed');
    })
    .catch((err: BusinessError) => {
      // Process service logic errors.
      console.error(`startServiceExtensionAbilityWithAccount failed, code is ${err.code}, message is ${err.message}`);
    });
} catch (err) {
  // Process input parameter errors.
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`startServiceExtensionAbilityWithAccount failed, code is ${code}, message is ${message}`);
}
  ```
## UIAbilityContext.stopServiceExtensionAbility

stopServiceExtensionAbility(want: Want, callback: AsyncCallback\<void>): void;

Stops a ServiceExtensionAbility in the same application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ServiceExtensionAbility.|
| callback | AsyncCallback\<void\> | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

let want: Want = {
  deviceId: '',
  bundleName: 'com.example.myapplication',
  abilityName: 'ServiceExtensionAbility'
};

try {
  this.context.stopServiceExtensionAbility(want, (err: BusinessError) => {
    if (err.code) {
      // Process service logic errors.
      console.error(`stopServiceExtensionAbility failed, code is ${err.code}, message is ${err.message}`);
      return;
    }
    // Carry out normal service processing.
    console.info('stopServiceExtensionAbility succeed');
  });
} catch (err) {
  // Process input parameter errors.
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`stopServiceExtensionAbility failed, code is ${code}, message is ${message}`);
}
  ```

## UIAbilityContext.stopServiceExtensionAbility

stopServiceExtensionAbility(want: Want): Promise\<void>;

Stops a ServiceExtensionAbility in the same application. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ServiceExtensionAbility.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

let want: Want = {
  deviceId: '',
  bundleName: 'com.example.myapplication',
  abilityName: 'ServiceExtensionAbility'
};

try {
  this.context.stopServiceExtensionAbility(want)
    .then(() => {
      // Carry out normal service processing.
      console.info('stopServiceExtensionAbility succeed');
    })
    .catch((err: BusinessError) => {
      // Process service logic errors.
      console.error(`stopServiceExtensionAbility failed, code is ${err.code}, message is ${err.message}`);
    });
} catch (err) {
  // Process input parameter errors.
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`stopServiceExtensionAbility failed, code is ${code}, message is ${message}`);
}
  ```

## UIAbilityContext.stopServiceExtensionAbilityWithAccount

stopServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void;

Stops a ServiceExtensionAbility with the account ID specified in the same application. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> The **ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS** permission is not required when **accountId** specifies the current user.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ServiceExtensionAbility.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getCreatedOsAccountsCount).|
| callback | AsyncCallback\<void\> | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

let want: Want = {
  deviceId: '',
  bundleName: 'com.example.myapplication',
  abilityName: 'ServiceExtensionAbility'
};
let accountId = 100;

try {
  this.context.stopServiceExtensionAbilityWithAccount(want, accountId, (err: BusinessError) => {
    if (err.code) {
      // Process service logic errors.
      console.error(`stopServiceExtensionAbilityWithAccount failed, code is ${err.code}, message is ${err.message}`);
      return;
    }
    // Carry out normal service processing.
    console.info('stopServiceExtensionAbilityWithAccount succeed');
  });
} catch (err) {
  // Process input parameter errors.
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`stopServiceExtensionAbilityWithAccount failed, code is ${code}, message is ${message}`);
}
  ```

## UIAbilityContext.stopServiceExtensionAbilityWithAccount

stopServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise\<void>;

Stops a ServiceExtensionAbility with the account ID specified in the same application. This API uses a promise to return the result.

> **NOTE**
> 
> The **ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS** permission is not required when **accountId** specifies the current user.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ServiceExtensionAbility.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getCreatedOsAccountsCount).|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

let want: Want = {
  deviceId: '',
  bundleName: 'com.example.myapplication',
  abilityName: 'ServiceExtensionAbility'
};
let accountId = 100;

try {
  this.context.stopServiceExtensionAbilityWithAccount(want, accountId)
    .then(() => {
      // Carry out normal service processing.
      console.info('stopServiceExtensionAbilityWithAccount succeed');
    })
    .catch((err: BusinessError) => {
      // Process service logic errors.
      console.error(`stopServiceExtensionAbilityWithAccount failed, code is ${err.code}, message is ${err.message}`);
    });
} catch (err) {
  // Process input parameter errors.
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`stopServiceExtensionAbilityWithAccount failed, code is ${code}, message is ${message}`);
}
  ```

## UIAbilityContext.terminateSelf

terminateSelf(callback: AsyncCallback&lt;void&gt;): void;

Terminates this ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';

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
  ```


## UIAbilityContext.terminateSelf

terminateSelf(): Promise&lt;void&gt;;

Terminates this ability. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';

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
  ```


## UIAbilityContext.terminateSelfWithResult

terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback&lt;void&gt;): void;

Terminates this ability. If the ability is started by calling [startAbilityForResult](#uiabilitycontextstartabilityforresult), the result is returned to the caller in the form of an asynchronous callback when **terminateSelfWithResult** is called. Otherwise, no result is returned to the caller when **terminateSelfWithResult** is called.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| parameter | [AbilityResult](js-apis-inner-ability-abilityResult.md) | Yes| Information returned to the caller.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import common from '@ohos.app.ability.common'; 
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

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
  ```


## UIAbilityContext.terminateSelfWithResult

terminateSelfWithResult(parameter: AbilityResult): Promise&lt;void&gt;;

Terminates this ability. If the ability is started by calling [startAbilityForResult](#uiabilitycontextstartabilityforresult), the result is returned to the caller in the form of a promise when **terminateSelfWithResult** is called. Otherwise, no result is returned to the caller when **terminateSelfWithResult** is called.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| parameter | [AbilityResult](js-apis-inner-ability-abilityResult.md) | Yes| Information returned to the caller.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import common from '@ohos.app.ability.common';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

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
  ```

## UIAbilityContext.connectServiceExtensionAbility

connectServiceExtensionAbility(want: Want, options: ConnectOptions): number;

Connects this ability to an ability that uses the **AbilityInfo.AbilityType.SERVICE** template.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information for connecting to the ServiceExtensionAbility.|
| options | [ConnectOptions](js-apis-inner-ability-connectOptions.md) | Yes| Instance of the callback function after the connection to the ServiceExtensionAbility is set up.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Result code of the ability connection.|

**Error codes**

| ID| Error Message|
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

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import common from '@ohos.app.ability.common';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';
import rpc from '@ohos.rpc';

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
  ```


## UIAbilityContext.connectServiceExtensionAbilityWithAccount

connectServiceExtensionAbilityWithAccount(want: Want, accountId: number, options: ConnectOptions): number;

Connects this ability to an ability that uses the **AbilityInfo.AbilityType.SERVICE** template, with the account ID specified.

> **NOTE**
> 
> The **ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS** permission is not required when **accountId** specifies the current user.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getCreatedOsAccountsCount).|
| options | [ConnectOptions](js-apis-inner-ability-connectOptions.md) | Yes| Instance of the callback function after the connection to the ServiceExtensionAbility is set up.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Result code of the ability connection.|

**Error codes**

| ID| Error Message|
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

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import common from '@ohos.app.ability.common';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';
import rpc from '@ohos.rpc';

let want: Want = {
  deviceId: '',
  bundleName: 'com.example.myapplication',
  abilityName: 'ServiceExtensionAbility'
};
let accountId = 100;
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
  connection = this.context.connectServiceExtensionAbilityWithAccount(want, accountId, options);
} catch (err) {
  // Process input parameter errors.
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`connectServiceExtensionAbility failed, code is ${code}, message is ${message}`);
}
  ```

## UIAbilityContext.disconnectServiceExtensionAbility

disconnectServiceExtensionAbility(connection: number): Promise\<void>;

Disconnects this ability from a ServiceExtensionAbility and after the successful disconnection, sets the remote object returned upon the connection to void. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| connection | number | Yes| Digital code of the connected ServiceExtensionAbility, that is, connectionId returned by **connectServiceExtensionAbility**.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
import { BusinessError } from '@ohos.base';

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
  ```

## UIAbilityContext.disconnectServiceExtensionAbility

disconnectServiceExtensionAbility(connection: number, callback:AsyncCallback\<void>): void;

Disconnects this ability from a ServiceExtensionAbility and after the successful disconnection, sets the remote object returned upon the connection to void. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| connection | number | Yes| Digital code of the connected ServiceExtensionAbility, that is, connectionId returned by **connectServiceExtensionAbility**.|
| callback | AsyncCallback\<void> | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
import { BusinessError } from '@ohos.base';

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
  ```

## UIAbilityContext.startAbilityByCall

startAbilityByCall(want: Want): Promise&lt;Caller&gt;;

Starts an ability in the foreground or background and obtains the caller object for communicating with the ability.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **exported** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - The rules for using this API in the same-device and cross-device scenarios are different. For details, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**Required permissions**: ohos.permission.ABILITY_BACKGROUND_COMMUNICATION

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Information about the ability to start, including **abilityName**, **moduleName**, **bundleName**, **deviceId** (optional), and **parameters** (optional). If **deviceId** is left blank or null, the local ability is started. If **parameters** is left blank or null, the ability is started in the background.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;Caller&gt; | Promise used to return the caller object to communicate with.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  Start an ability in the background.

  ```ts
import { Caller } from '@ohos.app.ability.UIAbility';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

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
  ```

Start an ability in the foreground.

  ```ts
import { Caller } from '@ohos.app.ability.UIAbility';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

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
  ```

## UIAbilityContext.startAbilityWithAccount

startAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void\>): void;

Starts an ability with the account ID specified. This API uses an asynchronous callback to return the result.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **exported** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

> **NOTE**
> 
> The **ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS** permission is not required when **accountId** specifies the current user.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getCreatedOsAccountsCount).|
| callback | AsyncCallback\<void\> | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
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

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

let want: Want = {
  deviceId: '',
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let accountId = 100;

try {
  this.context.startAbilityWithAccount(want, accountId, (err: BusinessError) => {
    if (err.code) {
      // Process service logic errors.
      console.error(`startAbilityWithAccount failed, code is ${err.code}, message is ${err.message}`);
      return;
    }
    // Carry out normal service processing.
    console.info('startAbilityWithAccount succeed');
  });
} catch (err) {
  // Process input parameter errors.
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`startAbilityWithAccount failed, code is ${code}, message is ${message}`);
}
  ```


## UIAbilityContext.startAbilityWithAccount

startAbilityWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback\<void\>): void;

Starts an ability with the account ID and start options specified. This API uses an asynchronous callback to return the result.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **exported** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

> **NOTE**
> 
> The **ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS** permission is not required when **accountId** specifies the current user.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getCreatedOsAccountsCount).|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | Yes| Parameters used for starting the ability.|
| callback | AsyncCallback\<void\> | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
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

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
import Want from '@ohos.app.ability.Want';
import StartOptions from '@ohos.app.ability.StartOptions';
import { BusinessError } from '@ohos.base';

let want: Want = {
  deviceId: '',
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let accountId = 100;
let options: StartOptions = {
  windowMode: 0
};

try {
  this.context.startAbilityWithAccount(want, accountId, options, (err: BusinessError) => {
    if (err.code) {
      // Process service logic errors.
      console.error(`startAbilityWithAccount failed, code is ${err.code}, message is ${err.message}`);
      return;
    }
    // Carry out normal service processing.
    console.info('startAbilityWithAccount succeed');
  });
} catch (err) {
  // Process input parameter errors.
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`startAbilityWithAccount failed, code is ${code}, message is ${message}`);
}
  ```


## UIAbilityContext.startAbilityWithAccount

startAbilityWithAccount(want: Want, accountId: number, options?: StartOptions): Promise\<void\>;

Starts an ability with the account ID specified. This API uses a promise to return the result.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **exported** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

> **NOTE**
> 
> The **ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS** permission is not required when **accountId** specifies the current user.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getCreatedOsAccountsCount).|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | No| Parameters used for starting the ability.|

**Error codes**

| ID| Error Message|
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

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
import Want from '@ohos.app.ability.Want';
import StartOptions from '@ohos.app.ability.StartOptions';
import { BusinessError } from '@ohos.base';

let want: Want = {
  deviceId: '',
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let accountId = 100;
let options: StartOptions = {
  windowMode: 0
};

try {
  this.context.startAbilityWithAccount(want, accountId, options)
    .then(() => {
      // Carry out normal service processing.
      console.info('startAbilityWithAccount succeed');
    })
    .catch((err: BusinessError) => {
      // Process service logic errors.
      console.error(`startAbilityWithAccount failed, code is ${err.code}, message is ${err.message}`);
    });
} catch (err) {
  // Process input parameter errors.
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`startAbilityWithAccount failed, code is ${code}, message is ${message}`);
}
  ```

## UIAbilityContext.setMissionLabel

setMissionLabel(label: string, callback:AsyncCallback&lt;void&gt;): void;

Sets a label for this UIAbility in the mission. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| label | string | Yes| Label of the ability to set.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';

  this.context.setMissionLabel('test', (result: BusinessError) => {
    console.info(`setMissionLabel: ${JSON.stringify(result)}`);
  });
  ```

## UIAbilityContext.setMissionLabel

setMissionLabel(label: string): Promise&lt;void&gt;;

Sets a label for this UIAbility in the mission. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| label | string | Yes| Label of the ability to set.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';

  this.context.setMissionLabel('test').then(() => {
    console.info('success');
  }).catch((err: BusinessError) => {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error(`setMissionLabel failed, code is ${code}, message is ${message}`);
  });
  ```
## UIAbilityContext.setMissionIcon

setMissionIcon(icon: image.PixelMap, callback:AsyncCallback\<void>): void;

Sets an icon for this ability in the mission. This API uses an asynchronous callback to return the result. The maximum size of the icon is 600 MB.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| icon | image.PixelMap | Yes| Icon of the ability to set.|
| callback | AsyncCallback\<void> | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
  import UIAbility from '@ohos.app.ability.UIAbility';
  import { BusinessError } from '@ohos.base';
  import image from '@ohos.multimedia.image';
  
  export default class EntryAbility extends UIAbility {
    onForeground() {
      let imagePixelMap: image.PixelMap;
      let color = new ArrayBuffer(0);
      image.createPixelMap(color, {
        size: {
          height: 100,
          width: 100
        }
      }).then((data) => {
        imagePixelMap = data;
        this.context.setMissionIcon(imagePixelMap, (err: BusinessError) => {
          console.error(`setMissionLabel failed, code is ${err.code}, message is ${err.message}`);
        })
      })
        .catch((err: BusinessError) => {
          console.error(`createPixelMap failed, code is ${err.code}, message is ${err.message}`);
        });
    }
  }
  ```


## UIAbilityContext.setMissionIcon

setMissionIcon(icon: image.PixelMap): Promise\<void>;

Sets an icon for this ability in the mission. This API uses a promise to return the result. The maximum size of the icon is 600 MB.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| icon | image.PixelMap | Yes| Icon of the ability to set.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
  import UIAbility from '@ohos.app.ability.UIAbility';
  import { BusinessError } from '@ohos.base';
  import image from '@ohos.multimedia.image';

  export default class EntryAbility extends UIAbility {
    onForeground() {
      let imagePixelMap: image.PixelMap;
      let color = new ArrayBuffer(0);
      image.createPixelMap(color, {
        size: {
          height: 100,
          width: 100
        }
      }).then((data) => {
          imagePixelMap = data;
          this.context.setMissionIcon(imagePixelMap)
            .then(() => {
              console.info('setMissionIcon succeed');
            })
            .catch((err: BusinessError) => {
              console.error(`setMissionLabel failed, code is ${err.code}, message is ${err.message}`);
            });
        })
        .catch((err: BusinessError) => {
          console.error(`createPixelMap failed, code is ${err.code}, message is ${err.message}`);
        });
    }
  }
  ```

## UIAbilityContext.setMissionContinueState<sup>10+</sup>

setMissionContinueState(state: AbilityConstant.ContinueState, callback:AsyncCallback&lt;void&gt;): void;

Sets the mission continuation state of this UIAbility. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| state | [AbilityConstant.ContinueState](js-apis-app-ability-abilityConstant.md#abilityconstantcontinuestate10) | Yes| Mission continuation state.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
  import AbilityConstant from '@ohos.app.ability.AbilityConstant';
  import { BusinessError } from '@ohos.base';

  this.context.setMissionContinueState(AbilityConstant.ContinueState.INACTIVE, (result: BusinessError) => {
    console.info(`setMissionContinueState: ${JSON.stringify(result)}`);
  });
  ```

## UIAbilityContext.setMissionContinueState<sup>10+</sup>

setMissionContinueState(state: AbilityConstant.ContinueState): Promise&lt;void&gt;;

Sets the mission continuation state of this UIAbility. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| state | [AbilityConstant.ContinueState](js-apis-app-ability-abilityConstant.md#abilityconstantcontinuestate10) | Yes| Mission continuation state.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
  import AbilityConstant from '@ohos.app.ability.AbilityConstant';
  import { BusinessError } from '@ohos.base';

  this.context.setMissionContinueState(AbilityConstant.ContinueState.INACTIVE).then(() => {
    console.info('success');
  }).catch((err: BusinessError) => {
    console.error(`setMissionContinueState failed, code is ${err.code}, message is ${err.message}`);
  });
  ```

## UIAbilityContext.restoreWindowStage

restoreWindowStage(localStorage: LocalStorage) : void;

Restores the WindowStage data in the UIAbility.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| localStorage | LocalStorage | Yes| Storage used to store the restored window stage.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
  let storage = new LocalStorage();
  this.context.restoreWindowStage(storage);
  ```

## UIAbilityContext.isTerminating

isTerminating(): boolean;

Checks whether this UIAbility is in the terminating state.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type| Description|
| -------- | -------- |
| boolean| The value **true** means that the UIAbility is in the terminating state, and **false** means the opposite.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000011 | The context does not exist. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
  let isTerminating: boolean = this.context.isTerminating();
  console.info(`ability state is ${isTerminating}`);
  ```

## UIAbilityContext.requestDialogService

requestDialogService(want: Want, result: AsyncCallback&lt;dialogRequest.RequestResult&gt;): void;

Starts a ServiceExtensionAbility that supports modal dialog boxes. After the ServiceExtensionAbility is started, the application displays a modal dialog box. You can call [setRequestResult](js-apis-app-ability-dialogRequest.md#requestcallbacksetrequestresult) to obtain the result.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **exported** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-app-ability-want.md) | Yes| Want information about the target ServiceExtensionAbility.|
| result | AsyncCallback&lt;[dialogRequest.RequestResult](js-apis-app-ability-dialogRequest.md)&gt; | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
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

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
import dialogRequest from '@ohos.app.ability.dialogRequest';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

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
  ```

  ## UIAbilityContext.requestDialogService

requestDialogService(want: Want): Promise&lt;dialogRequest.RequestResult&gt;;

Starts a ServiceExtensionAbility that supports modal dialog boxes. After the ServiceExtensionAbility is started, the application displays a modal dialog box. You can call [setRequestResult](js-apis-app-ability-dialogRequest.md#requestcallbacksetrequestresult) to obtain the result, which is returned to the caller in promise mode.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **exported** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ServiceExtensionAbility.|


**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[dialogRequest.RequestResult](js-apis-app-ability-dialogRequest.md)&gt; | Promise used to return the result.

**Error codes**

| ID| Error Message|
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

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
import dialogRequest from '@ohos.app.ability.dialogRequest';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

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
  ```
  ## UIAbilityContext.startRecentAbility

startRecentAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void;

Starts an ability. If the ability has multiple instances, the latest instance is started. This API uses an asynchronous callback to return the result.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **exported** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability.|
| callback | AsyncCallback\<void> | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

| ID| Error Message|
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

**Example**

  ```ts
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

let want: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

try {
  this.context.startRecentAbility(want, (err: BusinessError) => {
    if (err.code) {
      // Process service logic errors.
      console.error(`startRecentAbility failed, code is ${err.code}, message is ${err.message}`);
      return;
    }
    // Carry out normal service processing.
    console.info('startRecentAbility succeed');
  });
} catch (err) {
  // Process input parameter errors.
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`startRecentAbility failed, code is ${code}, message is ${message}`);
}
  ```
## UIAbilityContext.startRecentAbility

startRecentAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;): void;

Starts an ability with the start options specified. If the ability has multiple instances, the latest instance is started. This API uses an asynchronous callback to return the result.
You can use this API to carry start options.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **exported** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability.|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | Yes| Parameters used for starting the ability.|
| callback | AsyncCallback\<void> | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

| ID| Error Message|
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

**Example**

  ```ts
import Want from '@ohos.app.ability.Want';
import StartOptions from '@ohos.app.ability.StartOptions';
import { BusinessError } from '@ohos.base';

let want: Want = {
  deviceId: '',
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let options: StartOptions = {
  windowMode: 0
};

try {
  this.context.startRecentAbility(want, options, (err: BusinessError) => {
    if (err.code) {
      // Process service logic errors.
      console.error(`startRecentAbility failed, code is ${err.code}, message is ${err.message}`);
      return;
    }
    // Carry out normal service processing.
    console.info('startRecentAbility succeed');
  });
} catch (err) {
  // Process input parameter errors.
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`startRecentAbility failed, code is ${code}, message is ${message}`);
}
  ```
## UIAbilityContext.startRecentAbility

startRecentAbility(want: Want, options?: StartOptions): Promise&lt;void&gt;;

Starts an ability. If the ability has multiple instances, the latest instance is started.
This API uses a promise to return the result.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **exported** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability.|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | No| Parameters used for starting the ability.|

**Error codes**

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

| ID| Error Message|
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

**Example**

  ```ts
import Want from '@ohos.app.ability.Want';
import StartOptions from '@ohos.app.ability.StartOptions';
import { BusinessError } from '@ohos.base';

let want: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let options: StartOptions = {
  windowMode: 0,
};

try {
  this.context.startRecentAbility(want, options)
    .then(() => {
      // Carry out normal service processing.
      console.info('startRecentAbility succeed');
    })
    .catch((err: BusinessError) => {
      // Process service logic errors.
      console.error(`startRecentAbility failed, code is ${err.code}, message is ${err.message}`);
    });
} catch (err) {
  // Process input parameter errors.
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`startRecentAbility failed, code is ${code}, message is ${message}`);
}
  ```

## UIAbilityContext.startAbilityByCallWithAccount<sup>10+</sup>

startAbilityByCallWithAccount(want: Want, accountId: number): Promise&lt;Caller&gt;;

Starts an ability with the account ID specified and obtains the caller object for communicating with the ability.

Observe the following when using this API:
 - If an application needs to call this API to start an ability that belongs to another user, it must have the **ohos.permission.ABILITY_BACKGROUND_COMMUNICATION** and **ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS** permissions.
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **exported** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - The rules for using this API in the same-device and cross-device scenarios are different. For details, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**Required permissions**: ohos.permission.ABILITY_BACKGROUND_COMMUNICATION and ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Information about the ability to start, including **abilityName**, **moduleName**, **bundleName**, **deviceId** (optional), and **parameters** (optional). If **deviceId** is left blank or null, the local ability is started. If **parameters** is left blank or null, the ability is started in the background.|
| accountId | number | Yes| ID of a system account. The value **-1** indicates the current user. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess).|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;Caller&gt; | Promise used to return the caller object to communicate with.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | Static permission denied. The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16200001 | The caller has been released.        |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
  import { Caller } from '@ohos.app.ability.UIAbility';
  import Want from '@ohos.app.ability.Want';
  import { BusinessError } from '@ohos.base';

  let caller: Caller;

  // ID of a system account. The value -1 indicates the current user.
  let accountId = -1;

  // Specify the ability to start.
  let want: Want = {
      bundleName: 'com.acts.actscalleeabilityrely',
      moduleName: 'entry',
      abilityName: 'EntryAbility',
      deviceId: '',
      parameters: {
        // If the value of 'ohos.aafwk.param.callAbilityToForeground' is true, the ability is started in the foreground. If the value is false or not set, the ability is started in the background.
        'ohos.aafwk.param.callAbilityToForeground': true
      }
  };

  try {
    this.context.startAbilityByCallWithAccount(want, accountId)
      .then((obj: Caller) => {
        // Carry out normal service processing.
        caller = obj;
        console.log('startAbilityByCallWithAccount succeed');
      }).catch((error: BusinessError) => {
        // Process service logic errors.
        console.error('startAbilityByCallWithAccount failed, error.code: ${error.code}, error.message: ${error.message}');
      });
  } catch (paramError) {
    // Process input parameter errors.
    console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');
  }
  ```

## UIAbilityContext.startAbilityAsCaller<sup>10+<sup>

startAbilityAsCaller(want: Want, callback: AsyncCallback\<void>): void;

Starts an ability with the caller information specified. The caller information is carried in **want** and identified at the system service layer. The ability can obtain the caller information from the **want** parameter in the **onCreate** lifecycle callback. When this API is used to start an ability, the caller information carried in **want** is not overwritten by the current application information. The system service layer can obtain the initial caller information. This API uses an asynchronous callback to return the result.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **exported** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md)  | Yes| Want information about the target ability.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the ability is started, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message|
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

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import Want from '@ohos.app.ability.Want';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    // want contains the information about the caller who starts the application.
    let localWant: Want = want;
    localWant.bundleName = 'com.example.demo';
    localWant.moduleName = 'entry';
    localWant.abilityName = 'TestAbility';

    // Start a new ability using the caller information.
    this.context.startAbilityAsCaller(localWant, (err) => {
      if (err && err.code != 0) {
        console.error('startAbilityAsCaller failed, err:' + JSON.stringify(err));
      } else {
        console.log('startAbilityAsCaller success.');
      }
    })
  }
}

```

## UIAbilityContext.startAbilityAsCaller<sup>10+<sup>

startAbilityAsCaller(want: Want, options: StartOptions, callback: AsyncCallback\<void>): void;

Starts an ability with the caller information and start options specified. The caller information is carried in **want** and identified at the system service layer. The ability can obtain the caller information from the **want** parameter in the **onCreate** lifecycle callback. When this API is used to start an ability, the caller information carried in **want** is not overwritten by the current application information. The system service layer can obtain the initial caller information. This API uses an asynchronous callback to return the result.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **exported** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md)  | Yes| Want information about the target ability.|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | Yes| Parameters used for starting the ability.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the ability is started, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message|
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

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import StartOptions from '@ohos.app.ability.StartOptions';
import Want from '@ohos.app.ability.Want';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    // want contains the information about the caller who starts the application.
    let localWant: Want = want;
    localWant.bundleName = 'com.example.demo';
    localWant.moduleName = 'entry';
    localWant.abilityName = 'TestAbility';

    let option: StartOptions = {
      displayId: 0
    }

    // Start a new ability using the caller information.
    this.context.startAbilityAsCaller(localWant, option, (err) => {
      if (err && err.code != 0) {
        console.error('startAbilityAsCaller failed, err:' + JSON.stringify(err));
      } else {
        console.log('startAbilityAsCaller success.');
      }
    })
  }
}

```

## UIAbilityContext.startAbilityAsCaller<sup>10+<sup>

startAbilityAsCaller(want: Want, options?: StartOptions): Promise\<void>;

Starts an ability with the caller information specified. The caller information is carried in **want** and identified at the system service layer. The ability can obtain the caller information from the **want** parameter in the **onCreate** lifecycle callback. When this API is used to start an ability, the caller information carried in **want** is not overwritten by the current application information. The system service layer can obtain the initial caller information. This API uses a promise to return the result.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **exported** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md)  | Yes| Want information about the target ability.|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | No| Parameters used for starting the ability.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

| ID| Error Message|
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

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import StartOptions from '@ohos.app.ability.StartOptions';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    // want contains the information about the caller who starts the application.
    let localWant: Want = want;
    localWant.bundleName = 'com.example.demo';
    localWant.moduleName = 'entry';
    localWant.abilityName = 'TestAbility';

    let option: StartOptions = {
      displayId: 0
    }

    // Start a new ability using the caller information.
    this.context.startAbilityAsCaller(localWant, option)
      .then(() => {
        console.log('startAbilityAsCaller success.');
      })
      .catch((err: BusinessError) => {
        console.error('startAbilityAsCaller failed, err:' + JSON.stringify(err));
      })
  }
}

```

## UIAbilityContext.reportDrawnCompleted<sup>10+</sup>

reportDrawnCompleted(callback: AsyncCallback\<void>): void;

Reports an event indicating that page loading is complete (**loadContent()** is successfully called). This API uses an asynchronous callback to return the result.
 **System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to report that page loading is complete.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.window';
import { BusinessError } from '@ohos.base';

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
    console.log("MainAbility onWindowStageCreate")
  }
};
  ```
