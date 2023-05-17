# UIAbilityContext

**UIAbilityContext**, inherited from [Context](js-apis-inner-application-context.md), provides the context environment for [UIAbility](js-apis-app-ability-uiAbility.md). **UIAbilityContext** provides UIAbility-related configuration and APIs for operating UIAbilities and ServiceExtensionAbilities. For example, you can use the APIs to start a UIAbility, terminate a UIAbility to which the UIAbilityContext belongs, and start, terminate, connect to, or disconnect from a ServiceExtensionAbility.

> **NOTE**
>
>  - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>  - The APIs of this module can be used only in the stage model.

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

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target ability.|
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
| 16000010 | The call with the continuation flag is forbidden. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
let want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

try {
  this.context.startAbility(want, (err) => {
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
  console.error(`startAbility failed failed, code is ${err.code}, message is ${err.message}`);
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
| want | [Want](js-apis-application-want.md)  | Yes| Want information about the target ability.|
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
| 16000010 | The call with the continuation flag is forbidden. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
let want = {
  deviceId: '',
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let options = {
  windowMode: 0
};

try {
  this.context.startAbility(want, options, (err) => {
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
  console.error(`startAbility failed failed, code is ${err.code}, message is ${err.message}`);
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
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target ability.|
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
| 16000010 | The call with the continuation flag is forbidden. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
let want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let options = {
  windowMode: 0,
};

try {
  this.context.startAbility(want, options)
    .then(() => {
      // Carry out normal service processing.
      console.info('startAbility succeed');
    })
    .catch((err) => {
      // Process service logic errors.
      console.error(`startAbility failed, code is ${err.code}, message is ${err.message}`);
    });
} catch (err) {
  // Process input parameter errors.
  console.error(`startAbility failed, code is ${err.code}, message is ${err.message}`);
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
| want |[Want](js-apis-application-want.md) | Yes| Want information about the target ability.|
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
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
let want = {
  deviceId: '',
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

try {
  this.context.startAbilityForResult(want, (err, result) => {
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
  console.error(`startAbilityForResult failed, code is ${err.code}, message is ${err.message}`);
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
| want |[Want](js-apis-application-want.md) | Yes| Want information about the target ability.|
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
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
let want = {
  deviceId: '',
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let options = {
  windowMode: 0,
};

try {
  this.context.startAbilityForResult(want, options, (err, result) => {
    if (err.code) {
      // Process service logic errors.
      console.error(`startAbilityForResult failed, code is ${err.code}, message is ${err.message}`);
      return;
    }
    // Carry out normal service processing.
    console.info('startAbilityForResult succeed');
  });
} catch (paramError) {
  // Process input parameter errors.
  console.error(`startAbilityForResult failed, code is ${err.code}, message is ${err.message}`);
}
  ```


## UIAbilityContext.startAbilityForResult

startAbilityForResult(want: Want, options?: StartOptions): Promise&lt;AbilityResult&gt;;

Starts an ability. This API uses a promise to return the result when the ability is terminated. The following situations may be possible to an ability after it is started:
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
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target ability.|
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
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
let want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let options = {
  windowMode: 0,
};

try {
  this.context.startAbilityForResult(want, options)
    .then((result) => {
      // Carry out normal service processing.
      console.info('startAbilityForResult succeed');
    })
    .catch((err) => {
      // Process service logic errors.
      console.error(`startAbilityForResult failed, code is ${err.code}, message is ${err.message}`);
    });
} catch (err) {
  // Process input parameter errors.
  console.error(`startAbilityForResult failed, code is ${err.code}, message is ${err.message}`);
}
  ```

## UIAbilityContext.startAbilityForResultWithAccount

startAbilityForResultWithAccount(want: Want, accountId: number, callback: AsyncCallback\<AbilityResult>): void;

Starts an ability with the account ID specified. This API uses an asynchronous callback to return the result when the ability is terminated.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **exported** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS (required only when the account ID is not the current user)

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target ability.|
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
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
let want = {
  deviceId: '',
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let accountId = 100;

try {
  this.context.startAbilityForResultWithAccount(want, accountId, (err, result) => {
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
  console.error(`startAbilityForResultWithAccount failed, code is ${err.code}, message is ${err.message}`);
}
  ```


## UIAbilityContext.startAbilityForResultWithAccount

startAbilityForResultWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback\<void\>): void;

Starts an ability with the start options and account ID specified. This API uses an asynchronous callback to return the result when the ability is terminated.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **exported** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS (required only when the account ID is not the current user)

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target ability.|
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
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
let want = {
  deviceId: '',
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let accountId = 100;
let options = {
  windowMode: 0
};

try {
  this.context.startAbilityForResultWithAccount(want, accountId, options, (err) => {
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
  console.error(`startAbilityForResultWithAccount failed, code is ${err.code}, message is ${err.message}`);
}
  ```


## UIAbilityContext.startAbilityForResultWithAccount

startAbilityForResultWithAccount(want: Want, accountId: number, options?: StartOptions): Promise\<AbilityResult\>;

Starts an ability with the account ID specified. This API uses a promise to return the result when the ability is terminated.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **exported** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS (required only when the account ID is not the current user)

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target ability.|
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
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
let want = {
  deviceId: '',
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let accountId = 100;
let options = {
  windowMode: 0
};

try {
  this.context.startAbilityForResultWithAccount(want, accountId, options)
    .then((result) => {
      // Carry out normal service processing.
      console.info('startAbilityForResultWithAccount succeed');
    })
    .catch((err) => {
      // Process service logic errors.
      console.error(`startAbilityForResultWithAccount failed, code is ${err.code}, message is ${err.message}`);
    });
} catch (err) {
  // Process input parameter errors.
  console.error(`startAbilityForResultWithAccount failed, code is ${err.code}, message is ${err.message}`);
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
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target ServiceExtensionAbility.|
| callback | AsyncCallback\<void\> | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
let want = {
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
    .catch((err) => {
      // Process service logic errors.
      console.error(`startServiceExtensionAbility failed, code is ${err.code}, message is ${err.message}`);
    });
} catch (err) {
  // Process input parameter errors.
  console.error(`startServiceExtensionAbility failed, code is ${err.code}, message is ${err.message}`);
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
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target ServiceExtensionAbility.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
let want = {
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
    .catch((err) => {
      // Process service logic errors.
      console.error(`startServiceExtensionAbility failed, code is ${err.code}, message is ${err.message}`);
    });
} catch (paramError) {
  // Process input parameter errors.
  console.error(`startServiceExtensionAbility failed, code is ${err.code}, message is ${err.message}`);
}
  ```

## UIAbilityContext.startServiceExtensionAbilityWithAccount

startServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void;

Starts a ServiceExtensionAbility with the account ID specified. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS (required only when the account ID is not the current user)

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target ServiceExtensionAbility.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getCreatedOsAccountsCount).|
| callback | AsyncCallback\<void\> | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
let want = {
  deviceId: '',
  bundleName: 'com.example.myapplication',
  abilityName: 'ServiceExtensionAbility'
};
let accountId = 100;

try {
  this.context.startServiceExtensionAbilityWithAccount(want, accountId, (err) => {
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
  console.error(`startServiceExtensionAbilityWithAccount failed, code is ${err.code}, message is ${err.message}`);
}
  ```

## UIAbilityContext.startServiceExtensionAbilityWithAccount

startServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise\<void>;

Starts a ServiceExtensionAbility with the account ID specified. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS (required only when the account ID is not the current user)

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target ability.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getCreatedOsAccountsCount).|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
let want = {
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
    .catch((err) => {
      // Process service logic errors.
      console.error(`startServiceExtensionAbilityWithAccount failed, code is ${err.code}, message is ${err.message}`);
    });
} catch (err) {
  // Process input parameter errors.
  console.error(`startServiceExtensionAbilityWithAccount failed, code is ${err.code}, message is ${err.message}`);
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
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target ServiceExtensionAbility.|
| callback | AsyncCallback\<void\> | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
let want = {
  deviceId: '',
  bundleName: 'com.example.myapplication',
  abilityName: 'ServiceExtensionAbility'
};

try {
  this.context.stopServiceExtensionAbility(want, (err) => {
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
  console.error(`stopServiceExtensionAbility failed, code is ${err.code}, message is ${err.message}`);
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
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target ServiceExtensionAbility.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
let want = {
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
    .catch((err) => {
      // Process service logic errors.
      console.error(`stopServiceExtensionAbility failed, code is ${err.code}, message is ${err.message}`);
    });
} catch (err) {
  // Process input parameter errors.
  console.error(`stopServiceExtensionAbility failed, code is ${err.code}, message is ${err.message}`);
}
  ```

## UIAbilityContext.stopServiceExtensionAbilityWithAccount

stopServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void;

Stops a ServiceExtensionAbility with the account ID specified in the same application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS (required only when the account ID is not the current user)

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target ServiceExtensionAbility.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getCreatedOsAccountsCount).|
| callback | AsyncCallback\<void\> | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
let want = {
  deviceId: '',
  bundleName: 'com.example.myapplication',
  abilityName: 'ServiceExtensionAbility'
};
let accountId = 100;

try {
  this.context.stopServiceExtensionAbilityWithAccount(want, accountId, (err) => {
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
  console.error(`stopServiceExtensionAbilityWithAccount failed, code is ${err.code}, message is ${err.message}`);
}
  ```

## UIAbilityContext.stopServiceExtensionAbilityWithAccount

stopServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise\<void>;

Stops a ServiceExtensionAbility with the account ID specified in the same application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS (required only when the account ID is not the current user)

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target ServiceExtensionAbility.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getCreatedOsAccountsCount).|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
let want = {
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
    .catch((err) => {
      // Process service logic errors.
      console.error(`stopServiceExtensionAbilityWithAccount failed, code is ${err.code}, message is ${err.message}`);
    });
} catch (err) {
  // Process input parameter errors.
  console.error(`stopServiceExtensionAbilityWithAccount failed, code is ${err.code}, message is ${err.message}`);
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
  try {
    this.context.terminateSelf((err) => {
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
    console.error(`terminateSelf failed, code is ${err.code}, message is ${err.message}`);
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
  try {
    this.context.terminateSelf()
      .then(() => {
        // Carry out normal service processing.
        console.info('terminateSelf succeed');
      })
      .catch((err) => {
        // Process service logic errors.
        console.error(`terminateSelf failed, code is ${err.code}, message is ${err.message}`);
      });
  } catch (error) {
    // Capture the synchronization parameter error.
    console.error(`terminateSelf failed, code is ${err.code}, message is ${err.message}`);
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
let want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let resultCode = 100;
// AbilityResult information returned to the caller.
let abilityResult = {
  want,
  resultCode
};

try {
  this.context.terminateSelfWithResult(abilityResult, (err) => {
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
  console.error(`terminateSelfWithResult failed, code is ${err.code}, message is ${err.message}`);
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
let want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let resultCode = 100;
// AbilityResult information returned to the caller.
let abilityResult = {
  want,
  resultCode
};

try {
  this.context.terminateSelfWithResult(abilityResult)
    .then(() => {
      // Carry out normal service processing.
      console.info('terminateSelfWithResult succeed');
    })
    .catch((err) => {
      // Process service logic errors.
      console.error(`terminateSelfWithResult failed, code is ${err.code}, message is ${err.message}`);
    });
} catch (err) {
  // Process input parameter errors.
  console.error(`terminateSelfWithResult failed, code is ${err.code}, message is ${err.message}`);
}
  ```

## UIAbilityContext.connectServiceExtensionAbility

connectServiceExtensionAbility(want: Want, options: ConnectOptions): number;

Connects this ability to an ability that uses the **AbilityInfo.AbilityType.SERVICE** template.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information for connecting to the ServiceExtensionAbility.|
| options | [ConnectOptions](js-apis-inner-ability-connectOptions.md) | Yes| Instance of the callback function after the connection to the ServiceExtensionAbility is set up.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Result code of the ability connection.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000005 | The specified process does not have the permission. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
let want = {
  deviceId: '',
  bundleName: 'com.example.myapplication',
  abilityName: 'ServiceExtensionAbility'
};
let options = {
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

let connection = null;
try {
  connection = this.context.connectServiceExtensionAbility(want, options);
} catch (err) {
  // Process input parameter errors.
  console.error(`connectServiceExtensionAbility failed, code is ${err.code}, message is ${err.message}`);
}
  ```


## UIAbilityContext.connectServiceExtensionAbilityWithAccount

connectServiceExtensionAbilityWithAccount(want: Want, accountId: number, options: ConnectOptions): number;

Connects this ability to an ability that uses the **AbilityInfo.AbilityType.SERVICE** template, with the account ID specified.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS (required only when the account ID is not the current user)

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target ability.|
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
| 16000005 | The specified process does not have the permission. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
let want = {
  deviceId: '',
  bundleName: 'com.example.myapplication',
  abilityName: 'ServiceExtensionAbility'
};
let accountId = 100;
let options = {
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

let connection = null;
try {
  connection = this.context.connectServiceExtensionAbilityWithAccount(want, accountId, options);
} catch (err) {
  // Process input parameter errors.
  console.error(`connectServiceExtensionAbility failed, code is ${err.code}, message is ${err.message}`);
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
// connection is the return value of connectServiceExtensionAbility.
let connection = 1;

try {
  this.context.disconnectServiceExtensionAbility(connection, (err) => {
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
  console.error(`disconnectServiceExtensionAbility failed, code is ${err.code}, message is ${err.message}`);
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
// connection is the return value of connectServiceExtensionAbility.
let connection = 1;

try {
  this.context.disconnectServiceExtensionAbility(connection, (err) => {
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
  console.error(`disconnectServiceExtensionAbility failed, code is ${err.code}, message is ${err.message}`);
}
  ```

## UIAbilityContext.startAbilityByCall

startAbilityByCall(want: Want): Promise&lt;Caller&gt;;

Starts an ability in the foreground or background and obtains the caller object for communicating with the ability.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **exported** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - The rules for using this API in the same-device and cross-device scenarios are different. For details, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Information about the ability to start, including **abilityName**, **moduleName**, **bundleName**, **deviceId** (optional), and **parameters** (optional). If **deviceId** is left blank or null, the local ability is started. If **parameters** is left blank or null, the ability is started in the background.|

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
| 16000050 | Internal error. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  Start an ability in the background.

  ```ts
let caller;

// Start an ability in the background by not passing parameters.
let wantBackground = {
  bundleName: 'com.example.myapplication',
  moduleName: 'entry',
  abilityName: 'EntryAbility',
  deviceId: ''
};

try {
  this.context.startAbilityByCall(wantBackground)
    .then((obj) => {
      // Carry out normal service processing.
      caller = obj;
      console.info('startAbilityByCall succeed');
    }).catch((err) => {
    // Process service logic errors.
    console.error(`startAbilityByCall failed, code is ${err.code}, message is ${err.message}`);
  });
} catch (err) {
  // Process input parameter errors.
  console.error(`startAbilityByCall failed, code is ${err.code}, message is ${err.message}`);
}
  ```

Start an ability in the foreground.

  ```ts
let caller;

// Start an ability in the foreground with ohos.aafwk.param.callAbilityToForeground in parameters set to true.
let wantForeground = {
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
    .then((obj) => {
      // Carry out normal service processing.
      caller = obj;
      console.info('startAbilityByCall succeed');
    }).catch((error) => {
    // Process service logic errors.
    console.error(`startAbilityByCall failed, code is ${err.code}, message is ${err.message}`);
  });
} catch (paramError) {
  // Process input parameter errors.
  console.error(`startAbilityByCall failed, code is ${err.code}, message is ${err.message}`);
}
  ```

## UIAbilityContext.startAbilityWithAccount

startAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void\>): void;

Starts an ability with the account ID specified. This API uses an asynchronous callback to return the result.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **exported** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS (required only when the account ID is not the current user)

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target ability.|
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
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
let want = {
  deviceId: '',
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let accountId = 100;

try {
  this.context.startAbilityWithAccount(want, accountId, (err) => {
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
  console.error(`startAbilityWithAccount failed, code is ${err.code}, message is ${err.message}`);
}
  ```


## UIAbilityContext.startAbilityWithAccount

startAbilityWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback\<void\>): void;

Starts an ability with the account ID and start options specified. This API uses an asynchronous callback to return the result.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **exported** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS (required only when the account ID is not the current user)

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target ability.|
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
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
let want = {
  deviceId: '',
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let accountId = 100;
let options = {
  windowMode: 0
};

try {
  this.context.startAbilityWithAccount(want, accountId, options, (err) => {
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
  console.error(`startAbilityWithAccount failed, code is ${err.code}, message is ${err.message}`);
}
  ```


## UIAbilityContext.startAbilityWithAccount

startAbilityWithAccount(want: Want, accountId: number, options?: StartOptions): Promise\<void\>;

Starts an ability with the account ID specified. This API uses a promise to return the result.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **exported** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS (required only when the account ID is not the current user)

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target ability.|
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
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
let want = {
  deviceId: '',
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let accountId = 100;
let options = {
  windowMode: 0
};

try {
  this.context.startAbilityWithAccount(want, accountId, options)
    .then(() => {
      // Carry out normal service processing.
      console.info('startAbilityWithAccount succeed');
    })
    .catch((err) => {
      // Process service logic errors.
      console.error(`startAbilityWithAccount failed, code is ${err.code}, message is ${err.message}`);
    });
} catch (err) {
  // Process input parameter errors.
  console.error(`startAbilityWithAccount failed, code is ${err.code}, message is ${err.message}`);
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
  this.context.setMissionLabel('test', (result) => {
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
  this.context.setMissionLabel('test').then(() => {
    console.info('success');
  }).catch((err) => {
    console.error(`setMissionLabel failed, code is ${err.code}, message is ${err.message}`);
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
  import image from '@ohos.multimedia.image';
  
  let imagePixelMap;
  let color = new ArrayBuffer(0);
  let initializationOptions = {
    size: {
      height: 100,
      width: 100
    }
  };
  image.createPixelMap(color, initializationOptions)
    .then((data) => {
      imagePixelMap = data;
    })
    .catch((err) => {
      console.error(`createPixelMap failed, code is ${err.code}, message is ${err.message}`);
    });
  this.context.setMissionIcon(imagePixelMap, (err) => {
    console.error(`setMissionLabel failed, code is ${err.code}, message is ${err.message}`);
  })
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
  let imagePixelMap;
  let color = new ArrayBuffer(0);
  let initializationOptions = {
    size: {
      height: 100,
      width: 100
    }
  };
  image.createPixelMap(color, initializationOptions)
    .then((data) => {
      imagePixelMap = data;
    })
    .catch((err) => {
      console.error(`createPixelMap failed, code is ${err.code}, message is ${err.message}`);
    });
  this.context.setMissionIcon(imagePixelMap)
    .then(() => {
      console.info('setMissionIcon succeed');
    })
    .catch((err) => {
      console.error(`setMissionLabel failed, code is ${err.code}, message is ${err.message}`);
    });
  ```
## UIAbilityContext.restoreWindowStage

restoreWindowStage(localStorage: LocalStorage) : void;

Restores the WindowStage data in the UIAbility.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| localStorage | image.LocalStorage | Yes| Storage used to store the restored window stage.|

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
  let isTerminating = this.context.isTerminating();
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
| want |[Want](js-apis-application-want.md) | Yes| Want information about the target ServiceExtensionAbility.|
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
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
import dialogRequest from '@ohos.app.ability.dialogRequest';

let want = {
  deviceId: '',
  bundleName: 'com.example.myapplication',
  abilityName: 'AuthAccountServiceExtension'
};

try {
  this.context.requestDialogService(want, (err, result) => {
    if (err.code) {
      // Process service logic errors.
      console.error(`requestDialogService failed, code is ${err.code}, message is ${err.message}`);
      return;
    }
    // Carry out normal service processing.
    console.info('requestDialogService succeed, result = ${JSON.stringify(result)}');
  });
} catch (err) {
  // Process input parameter errors.
  console.error(`requestDialogService failed, code is ${err.code}, message is ${err.message}`);
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
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target ServiceExtensionAbility.|


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
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
import dialogRequest from '@ohos.app.ability.dialogRequest';

let want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'AuthAccountServiceExtension'
};

try {
  this.context.requestDialogService(want)
    .then((result) => {
      // Carry out normal service processing.
      console.info('requestDialogService succeed, result = ${JSON.stringify(result)}');
    })
    .catch((err) => {
      // Process service logic errors.
      console.error(`requestDialogService failed, code is ${err.code}, message is ${err.message}`);
    });
} catch (err) {
  // Process input parameter errors.
  console.error(`requestDialogService failed, code is ${err.code}, message is ${err.message}`);
}
  ```
