# UIAbilityContext

The **UIAbilityContext** module, inherited from **Context**, implements the context for UIAbilities.

This module provides APIs for accessing UIAbility-specific resources. You can use the APIs to start and terminate a UIAbility, obtain the caller interface, and request permissions from users by displaying a dialog box.

> **NOTE**
>
>  - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>  - The APIs of this module can be used only in the stage model.

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| abilityInfo | [AbilityInfo](js-apis-bundleManager-abilityInfo.md) | Yes| No| UIAbility information.|
| currentHapModuleInfo | [HapModuleInfo](js-apis-bundleManager-hapModuleInfo.md) | Yes| No| Information about the current HAP.|
| config | [Configuration](js-apis-app-ability-configuration.md) | Yes| No| Configuration information.|

## UIAbilityContext.startAbility

startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void;

Starts a UIAbility. This API uses an asynchronous callback to return the result.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start a UIAbility, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **visible** of the target UIAbility is **false**, the initiator UIAbility must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target UIAbility.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Invalid input parameter. |
| 16000001 | Input error. The specified ability name does not exist. |
| 16000004 | Visibility verification failed. |
| 16000005 | Static permission denied. The specified process does not have the permission. |
| 16000007 | Service busyness. There are concurrent tasks, waiting for retry. |
| 16000008 | Crowdtest App Expiration. |
| 16000009 | Can not start ability in wukong mode. |
| 16000010 | Can not operation with continue flag.        |
| 16000011 | Context does not exist.        |
| 16000051 | Network error. The network is abnormal. |
| 16000052 | Free install not support. The application does not support freeinstall |
| 16000053 | Not top ability. The application is not top ability. |
| 16000054 | Free install busyness. There are concurrent tasks, waiting for retry. |
| 16000055 | Free install timeout. |
| 16000056 | Can not free install other ability. |
| 16000057 | Not support cross device free install. |
| 16200001 | Caller released. The caller has been released. |
| 16000050 | Internal Error. |

**Example**

  ```ts
  let want = {
    bundleName: 'com.example.myapp',
    abilityName: 'MyAbility'
  };

  try {
    this.context.startAbility(want, (error) => {
      if (error.code) {
        // Process service logic errors.
        console.log('startAbility failed, error.code: ' + JSON.stringify(error.code) +
          ' error.message: ' + JSON.stringify(error.message));
        return;
      }
      // Carry out normal service processing.
      console.log('startAbility succeed');
    });
  } catch (paramError) {
    // Process input parameter errors.
    console.log('error.code: ' + JSON.stringify(paramError.code) +
      ' error.message: ' + JSON.stringify(paramError.message));
  }
  ```


## UIAbilityContext.startAbility

startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;): void;

Starts a UIAbility with the start options specified. This API uses an asynchronous callback to return the result.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start a UIAbility, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **visible** of the target UIAbility is **false**, the initiator UIAbility must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md)  | Yes| Want information about the target UIAbility.|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | Yes| Parameters used for starting the UIAbility.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Invalid input parameter. |
| 16000001 | Input error. The specified ability name does not exist. |
| 16000004 | Visibility verification failed. |
| 16000005 | Static permission denied. The specified process does not have the permission. |
| 16000007 | Service busyness. There are concurrent tasks, waiting for retry. |
| 16000008 | Crowdtest App Expiration. |
| 16000009 | Can not start ability in wukong mode. |
| 16000010 | Can not operation with continue flag.        |
| 16000011 | Context does not exist.        |
| 16000051 | Network error. The network is abnormal. |
| 16000052 | Free install not support. The application does not support freeinstall |
| 16000053 | Not top ability. The application is not top ability. |
| 16000054 | Free install busyness. There are concurrent tasks, waiting for retry. |
| 16000055 | Free install timeout. |
| 16000056 | Can not free install other ability. |
| 16000057 | Not support cross device free install. |
| 16200001 | Caller released. The caller has been released. |
| 16000050 | Internal Error. |

**Example**

  ```ts
  let want = {
    deviceId: '',
    bundleName: 'com.extreme.test',
    abilityName: 'MainAbility'
  };
  let options = {
    windowMode: 0
  };

  try {
    this.context.startAbility(want, options, (error) => {
      if (error.code) {
        // Process service logic errors.
        console.log('startAbility failed, error.code: ' + JSON.stringify(error.code) +
          ' error.message: ' + JSON.stringify(error.message));
        return;
      }
      // Carry out normal service processing.
      console.log('startAbility succeed');
    });
  } catch (paramError) {
    // Process input parameter errors.
    console.log('error.code: ' + JSON.stringify(paramError.code) +
      ' error.message: ' + JSON.stringify(paramError.message));
  }
  ```

## UIAbilityContext.startAbility

startAbility(want: Want, options?: StartOptions): Promise&lt;void&gt;;

Starts a UIAbility. This API uses a promise to return the result.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start a UIAbility, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **visible** of the target UIAbility is **false**, the initiator UIAbility must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target UIAbility.|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | No| Parameters used for starting the UIAbility.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Invalid input parameter. |
| 16000001 | Input error. The specified ability name does not exist. |
| 16000004 | Visibility verification failed. |
| 16000005 | Static permission denied. The specified process does not have the permission. |
| 16000007 | Service busyness. There are concurrent tasks, waiting for retry. |
| 16000008 | Crowdtest App Expiration. |
| 16000009 | Can not start ability in wukong mode. |
| 16000010 | Can not operation with continue flag.        |
| 16000011 | Context does not exist.        |
| 16000051 | Network error. The network is abnormal. |
| 16000052 | Free install not support. The application does not support freeinstall |
| 16000053 | Not top ability. The application is not top ability. |
| 16000054 | Free install busyness. There are concurrent tasks, waiting for retry. |
| 16000055 | Free install timeout. |
| 16000056 | Can not free install other ability. |
| 16000057 | Not support cross device free install. |
| 16200001 | Caller released. The caller has been released. |
| 16000050 | Internal Error. |

**Example**

  ```ts
  let want = {
    bundleName: 'com.example.myapp',
    abilityName: 'MyAbility'
  };
  let options = {
  	windowMode: 0,
  };

  try {
    this.context.startAbility(want, options)
      .then((data) => {
        // Carry out normal service processing.
        console.log('startAbility succeed');
      })
      .catch((error) => {
        // Process service logic errors.
        console.log('startAbility failed, error.code: ' + JSON.stringify(error.code) +
          ' error.message: ' + JSON.stringify(error.message));
      });
  } catch (paramError) {
    // Process input parameter errors.
    console.log('error.code: ' + JSON.stringify(paramError.code) +
      ' error.message: ' + JSON.stringify(paramError.message));
  }
  ```


## UIAbilityContext.startAbilityForResult

startAbilityForResult(want: Want, callback: AsyncCallback&lt;AbilityResult&gt;): void;

Starts a UIAbility. This API uses an asynchronous callback to return the result when the UIAbility is terminated. The following situations may be possible for a started UIAbility:
 - Normally, you can call [terminateSelfWithResult](#uiabilitycontextterminateselfwithresult) to terminate the UIAbility. The result is returned to the initiator UIAbility.
 - If an exception occurs, for example, the UIAbility is killed, an error message, in which **resultCode** is **-1**, is returned to the initiator UIAbility.
 - If different applications call this API to start a UIAbility that uses the singleton mode and then call [terminateSelfWithResult](#uiabilitycontextterminateselfwithresult) to terminate the UIAbility, the normal result is returned to the last initiator UIAbility, and an error message, in which **resultCode** is **-1**, is returned to others.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start a UIAbility, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **visible** of the target UIAbility is **false**, the initiator UIAbility must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-application-want.md) | Yes| Want information about the target UIAbility.|
| callback | AsyncCallback&lt;[AbilityResult](js-apis-inner-ability-abilityResult.md)&gt; | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Invalid input parameter. |
| 16000001 | Input error. The specified ability name does not exist. |
| 16000004 | Visibility verification failed. |
| 16000005 | Static permission denied. The specified process does not have the permission. |
| 16000007 | Service busyness. There are concurrent tasks, waiting for retry. |
| 16000008 | Crowdtest App Expiration. |
| 16000009 | Can not start ability in wukong mode. |
| 16000010 | Can not operation with continue flag.        |
| 16000011 | Context does not exist.        |
| 16000051 | Network error. The network is abnormal. |
| 16000052 | Free install not support. The application does not support freeinstall |
| 16000053 | Not top ability. The application is not top ability. |
| 16000054 | Free install busyness. There are concurrent tasks, waiting for retry. |
| 16000055 | Free install timeout. |
| 16000056 | Can not free install other ability. |
| 16000057 | Not support cross device free install. |
| 16200001 | Caller released. The caller has been released. |
| 16000050 | Internal Error. |

**Example**

  ```ts
  let want = {
    deviceId: '',
    bundleName: 'com.extreme.test',
    abilityName: 'MainAbility'
  };

  try {
    this.context.startAbilityForResult(want, (error, result) => {
      if (error.code) {
        // Process service logic errors.
        console.log('startAbilityForResult failed, error.code: ' + JSON.stringify(error.code) +
          ' error.message: ' + JSON.stringify(error.message));
        return;
      }
      // Carry out normal service processing.
      console.log('startAbilityForResult succeed, result.resultCode = ' +
        result.resultCode)
    });
  } catch (paramError) {
    // Process input parameter errors.
    console.log('error.code: ' + JSON.stringify(paramError.code) +
      ' error.message: ' + JSON.stringify(paramError.message));
  }
  ```

## UIAbilityContext.startAbilityForResult

startAbilityForResult(want: Want, options: StartOptions, callback: AsyncCallback&lt;AbilityResult&gt;): void;

Starts a UIAbility with the start options specified. This API uses an asynchronous callback to return the result when the UIAbility is terminated. The following situations may be possible for a started UIAbility:
 - Normally, you can call [terminateSelfWithResult](#uiabilitycontextterminateselfwithresult) to terminate the UIAbility. The result is returned to the initiator UIAbility.
 - If an exception occurs, for example, the UIAbility is killed, an error message, in which **resultCode** is **-1**, is returned to the initiator UIAbility.
 - If different applications call this API to start a UIAbility that uses the singleton mode and then call [terminateSelfWithResult](#uiabilitycontextterminateselfwithresult) to terminate the UIAbility, the normal result is returned to the last initiator UIAbility, and an error message, in which **resultCode** is **-1**, is returned to others.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start a UIAbility, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **visible** of the target UIAbility is **false**, the initiator UIAbility must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-application-want.md) | Yes| Want information about the target UIAbility.|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | Yes| Parameters used for starting the UIAbility.|
| callback | AsyncCallback&lt;[AbilityResult](js-apis-inner-ability-abilityResult.md)&gt; | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Invalid input parameter. |
| 16000001 | Input error. The specified ability name does not exist. |
| 16000004 | Visibility verification failed. |
| 16000005 | Static permission denied. The specified process does not have the permission. |
| 16000007 | Service busyness. There are concurrent tasks, waiting for retry. |
| 16000008 | Crowdtest App Expiration. |
| 16000009 | Can not start ability in wukong mode. |
| 16000010 | Can not operation with continue flag.        |
| 16000011 | Context does not exist.        |
| 16000051 | Network error. The network is abnormal. |
| 16000052 | Free install not support. The application does not support freeinstall |
| 16000053 | Not top ability. The application is not top ability. |
| 16000054 | Free install busyness. There are concurrent tasks, waiting for retry. |
| 16000055 | Free install timeout. |
| 16000056 | Can not free install other ability. |
| 16000057 | Not support cross device free install. |
| 16200001 | Caller released. The caller has been released. |
| 16000050 | Internal Error. |

**Example**

  ```ts
  let want = {
    deviceId: '',
    bundleName: 'com.extreme.test',
    abilityName: 'MainAbility'
  };
  let options = {
    windowMode: 0,
  };

  try {
    this.context.startAbilityForResult(want, options, (error, result) => {
      if (error.code) {
        // Process service logic errors.
        console.log('startAbilityForResult failed, error.code: ' + JSON.stringify(error.code) +
          ' error.message: ' + JSON.stringify(error.message));
        return;
      }
      // Carry out normal service processing.
      console.log('startAbilityForResult succeed, result.resultCode = ' +
        result.resultCode)
    });
  } catch (paramError) {
    // Process input parameter errors.
    console.log('error.code: ' + JSON.stringify(paramError.code) +
      ' error.message: ' + JSON.stringify(paramError.message));
  }
  ```


## UIAbilityContext.startAbilityForResult

startAbilityForResult(want: Want, options?: StartOptions): Promise&lt;AbilityResult&gt;;

Starts a UIAbility. This API uses a promise to return the result when the UIAbility is terminated. The following situations may be possible for a started UIAbility:
 - Normally, you can call [terminateSelfWithResult](#uiabilitycontextterminateselfwithresult) to terminate the UIAbility. The result is returned to the initiator UIAbility.
 - If an exception occurs, for example, the UIAbility is killed, an error message, in which **resultCode** is **-1**, is returned to the initiator UIAbility.
 - If different applications call this API to start a UIAbility that uses the singleton mode and then call [terminateSelfWithResult](#uiabilitycontextterminateselfwithresult) to terminate the UIAbility, the normal result is returned to the last initiator UIAbility, and an error message, in which **resultCode** is **-1**, is returned to others.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start a UIAbility, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **visible** of the target UIAbility is **false**, the initiator UIAbility must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target UIAbility.|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | No| Parameters used for starting the UIAbility.|


**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[AbilityResult](js-apis-inner-ability-abilityResult.md)&gt; | Promise used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Invalid input parameter. |
| 16000001 | Input error. The specified ability name does not exist. |
| 16000004 | Visibility verification failed. |
| 16000005 | Static permission denied. The specified process does not have the permission. |
| 16000007 | Service busyness. There are concurrent tasks, waiting for retry. |
| 16000008 | Crowdtest App Expiration. |
| 16000009 | Can not start ability in wukong mode. |
| 16000010 | Can not operation with continue flag.        |
| 16000011 | Context does not exist.        |
| 16000051 | Network error. The network is abnormal. |
| 16000052 | Free install not support. The application does not support freeinstall |
| 16000053 | Not top ability. The application is not top ability. |
| 16000054 | Free install busyness. There are concurrent tasks, waiting for retry. |
| 16000055 | Free install timeout. |
| 16000056 | Can not free install other ability. |
| 16000057 | Not support cross device free install. |
| 16200001 | Caller released. The caller has been released. |
| 16000050 | Internal Error. |

**Example**

  ```ts
  let want = {
    bundleName: 'com.example.myapp',
    abilityName: 'MyAbility'
  };
  let options = {
  	windowMode: 0,
  };

  try {
    this.context.startAbilityForResult(want, options)
      .then((result) => {
        // Carry out normal service processing.
        console.log('startAbilityForResult succeed, result.resultCode = ' + result.resultCode);
      })
      .catch((error) => {
        // Process service logic errors.
        console.log('startAbilityForResult failed, error.code: ' + JSON.stringify(error.code) +
          ' error.message: ' + JSON.stringify(error.message));
      });
  } catch (paramError) {
    // Process input parameter errors.
    console.log('error.code: ' + JSON.stringify(paramError.code) +
      ' error.message: ' + JSON.stringify(paramError.message));
  }
  ```

## UIAbilityContext.startAbilityForResultWithAccount

startAbilityForResultWithAccount(want: Want, accountId: number, callback: AsyncCallback\<AbilityResult>): void;

Starts a UIAbility with the account ID specified. This API uses an asynchronous callback to return the result when the UIAbility is terminated.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target UIAbility.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess).|
| callback | AsyncCallback\<AbilityResult\> | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Invalid input parameter. |
| 16000001 | Input error. The specified ability name does not exist. |
| 16000004 | Visibility verification failed. |
| 16000005 | Static permission denied. The specified process does not have the permission. |
| 16000006 | Can not cross user operations. |
| 16000007 | Service busyness. There are concurrent tasks, waiting for retry. |
| 16000008 | Crowdtest App Expiration. |
| 16000009 | Can not start ability in wukong mode. |
| 16000010 | Can not operation with continue flag.        |
| 16000011 | Context does not exist.        |
| 16000051 | Network error. The network is abnormal. |
| 16000052 | Free install not support. The application does not support freeinstall |
| 16000053 | Not top ability. The application is not top ability. |
| 16000054 | Free install busyness. There are concurrent tasks, waiting for retry. |
| 16000055 | Free install timeout. |
| 16000056 | Can not free install other ability. |
| 16000057 | Not support cross device free install. |
| 16200001 | Caller released. The caller has been released. |
| 16000050 | Internal Error. |

**Example**

  ```ts
  let want = {
    deviceId: '',
    bundleName: 'com.extreme.test',
    abilityName: 'MainAbility'
  };
  let accountId = 100;

  try {
    this.context.startAbilityForResultWithAccount(want, accountId, (error, result) => {
      if (error.code) {
        // Process service logic errors.
        console.log('startAbilityForResultWithAccount failed, error.code: ' + JSON.stringify(error.code) +
          ' error.message: ' + JSON.stringify(error.message));
        return;
      }
      // Carry out normal service processing.
      console.log('startAbilityForResultWithAccount succeed, result.resultCode = ' +
        result.resultCode)
    });
  } catch (paramError) {
    // Process input parameter errors.
    console.log('error.code: ' + JSON.stringify(paramError.code) +
      ' error.message: ' + JSON.stringify(paramError.message));
  }
  ```


## UIAbilityContext.startAbilityForResultWithAccount

startAbilityForResultWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback\<void\>): void;

Starts a UIAbility with the start options and account ID specified. This API uses an asynchronous callback to return the result when the UIAbility is terminated.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target UIAbility.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess).|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | Yes| Parameters used for starting the UIAbility.|
| callback | AsyncCallback\<void\> | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Invalid input parameter. |
| 16000001 | Input error. The specified ability name does not exist. |
| 16000004 | Visibility verification failed. |
| 16000005 | Static permission denied. The specified process does not have the permission. |
| 16000006 | Can not cross user operations. |
| 16000007 | Service busyness. There are concurrent tasks, waiting for retry. |
| 16000008 | Crowdtest App Expiration. |
| 16000009 | Can not start ability in wukong mode. |
| 16000010 | Can not operation with continue flag.        |
| 16000011 | Context does not exist.        |
| 16000051 | Network error. The network is abnormal. |
| 16000052 | Free install not support. The application does not support freeinstall |
| 16000053 | Not top ability. The application is not top ability. |
| 16000054 | Free install busyness. There are concurrent tasks, waiting for retry. |
| 16000055 | Free install timeout. |
| 16000056 | Can not free install other ability. |
| 16000057 | Not support cross device free install. |
| 16200001 | Caller released. The caller has been released. |
| 16000050 | Internal Error. |

**Example**

  ```ts
  let want = {
    deviceId: '',
    bundleName: 'com.extreme.test',
    abilityName: 'MainAbility'
  };
  let accountId = 100;
  let options = {
    windowMode: 0
  };

  try {
    this.context.startAbilityForResultWithAccount(want, accountId, options, (error, result) => {
      if (error.code) {
        // Process service logic errors.
        console.log('startAbilityForResultWithAccount failed, error.code: ' + JSON.stringify(error.code) +
          ' error.message: ' + JSON.stringify(error.message));
        return;
      }
      // Carry out normal service processing.
      console.log('startAbilityForResultWithAccount succeed, result.resultCode = ' +
        result.resultCode)
    });
  } catch (paramError) {
    // Process input parameter errors.
    console.log('error.code: ' + JSON.stringify(paramError.code) +
      ' error.message: ' + JSON.stringify(paramError.message));
  }
  ```


## UIAbilityContext.startAbilityForResultWithAccount

startAbilityForResultWithAccount(want: Want, accountId: number, options?: StartOptions): Promise\<AbilityResult\>;

Starts a UIAbility with the account ID specified. This API uses a promise to return the result when the UIAbility is terminated.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target UIAbility.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess).|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | No| Parameters used for starting the UIAbility.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;AbilityResult&gt; | Promise used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Invalid input parameter. |
| 16000001 | Input error. The specified ability name does not exist. |
| 16000004 | Visibility verification failed. |
| 16000005 | Static permission denied. The specified process does not have the permission. |
| 16000006 | Can not cross user operations. |
| 16000007 | Service busyness. There are concurrent tasks, waiting for retry. |
| 16000008 | Crowdtest App Expiration. |
| 16000009 | Can not start ability in wukong mode. |
| 16000010 | Can not operation with continue flag.        |
| 16000011 | Context does not exist.        |
| 16000051 | Network error. The network is abnormal. |
| 16000052 | Free install not support. The application does not support freeinstall |
| 16000053 | Not top ability. The application is not top ability. |
| 16000054 | Free install busyness. There are concurrent tasks, waiting for retry. |
| 16000055 | Free install timeout. |
| 16000056 | Can not free install other ability. |
| 16000057 | Not support cross device free install. |
| 16200001 | Caller released. The caller has been released. |
| 16000050 | Internal Error. |

**Example**

  ```ts
  let want = {
    deviceId: '',
    bundleName: 'com.extreme.test',
    abilityName: 'MainAbility'
  };
  let accountId = 100;
  let options = {
    windowMode: 0
  };

  try {
    this.context.startAbilityForResultWithAccount(want, accountId, options)
      .then((result) => {
        // Carry out normal service processing.
        console.log('startAbilityForResultWithAccount succeed, result.resultCode = ' +
          result.resultCode)
      })
      .catch((error) => {
        // Process service logic errors.
        console.log('startAbilityForResultWithAccount failed, error.code: ' + JSON.stringify(error.code) +
          ' error.message: ' + JSON.stringify(error.message));
      });
  } catch (paramError) {
    // Process input parameter errors.
    console.log('error.code: ' + JSON.stringify(paramError.code) +
      ' error.message: ' + JSON.stringify(paramError.message));
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
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target UIAbility.|
| callback | AsyncCallback\<void\> | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Invalid input parameter. |
| 16000001 | Input error. The specified ability name does not exist. |
| 16000002 | Ability type error. The specified ability type is wrong. |
| 16000004 | Visibility verification failed. |
| 16000005 | Static permission denied. The specified process does not have the permission. |
| 16000007 | Service busyness. There are concurrent tasks, waiting for retry. |
| 16000008 | Crowdtest App Expiration. |
| 16000009 | Can not start ability in wukong mode. |
| 16000011 | Context does not exist.        |
| 16200001 | Caller released. The caller has been released. |
| 16000050 | Internal Error. |

**Example**

  ```ts
  let want = {
    deviceId: '',
    bundleName: 'com.extreme.test',
    abilityName: 'MainAbility'
  };

  try {
    this.context.startServiceExtensionAbility(want, (error) => {
      if (error.code) {
        // Process service logic errors.
        console.log('startServiceExtensionAbility failed, error.code: ' + JSON.stringify(error.code) +
          ' error.message: ' + JSON.stringify(error.message));
        return;
      }
      // Carry out normal service processing.
      console.log('startServiceExtensionAbility succeed');
    });
  } catch (paramError) {
    // Process input parameter errors.
    console.log('error.code: ' + JSON.stringify(paramError.code) +
      ' error.message: ' + JSON.stringify(paramError.message));
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
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target UIAbility.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Invalid input parameter. |
| 16000001 | Input error. The specified ability name does not exist. |
| 16000002 | Ability type error. The specified ability type is wrong. |
| 16000004 | Visibility verification failed. |
| 16000005 | Static permission denied. The specified process does not have the permission. |
| 16000007 | Service busyness. There are concurrent tasks, waiting for retry. |
| 16000008 | Crowdtest App Expiration. |
| 16000009 | Can not start ability in wukong mode. |
| 16000011 | Context does not exist.        |
| 16200001 | Caller released. The caller has been released. |
| 16000050 | Internal Error. |

**Example**

  ```ts
  let want = {
    deviceId: '',
    bundleName: 'com.extreme.test',
    abilityName: 'MainAbility'
  };

  try {
    this.context.startServiceExtensionAbility(want)
      .then((data) => {
        // Carry out normal service processing.
        console.log('startServiceExtensionAbility succeed');
      })
      .catch((error) => {
        // Process service logic errors.
        console.log('startServiceExtensionAbility failed, error.code: ' + JSON.stringify(error.code) +
          ' error.message: ' + JSON.stringify(error.message));
      });
  } catch (paramError) {
    // Process input parameter errors.
    console.log('error.code: ' + JSON.stringify(paramError.code) +
      ' error.message: ' + JSON.stringify(paramError.message));
  }
  ```

## UIAbilityContext.startServiceExtensionAbilityWithAccount

startServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void;

Starts a ServiceExtensionAbility with the account ID specified. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target UIAbility.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess).|
| callback | AsyncCallback\<void\> | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Invalid input parameter. |
| 16000001 | Input error. The specified ability name does not exist. |
| 16000002 | Ability type error. The specified ability type is wrong. |
| 16000004 | Visibility verification failed. |
| 16000007 | Service busyness. There are concurrent tasks, waiting for retry. |
| 16000011 | Context does not exist.        |
| 16200001 | Caller released. The caller has been released. |
| 16000050 | Internal Error. |

**Example**

  ```ts
  let want = {
    deviceId: '',
    bundleName: 'com.extreme.test',
    abilityName: 'MainAbility'
  };
  let accountId = 100;

  try {
    this.context.startServiceExtensionAbilityWithAccount(want, accountId, (error) => {
      if (error.code) {
        // Process service logic errors.
        console.log('startServiceExtensionAbilityWithAccount failed, error.code: ' + JSON.stringify(error.code) +
          ' error.message: ' + JSON.stringify(error.message));
        return;
      }
      // Carry out normal service processing.
      console.log('startServiceExtensionAbilityWithAccount succeed');
    });
  } catch (paramError) {
    // Process input parameter errors.
    console.log('error.code: ' + JSON.stringify(paramError.code) +
      ' error.message: ' + JSON.stringify(paramError.message));
  }
  ```

## UIAbilityContext.startServiceExtensionAbilityWithAccount

startServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise\<void>;

Starts a ServiceExtensionAbility with the account ID specified. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target UIAbility.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess).|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Invalid input parameter. |
| 16000001 | Input error. The specified ability name does not exist. |
| 16000002 | Ability type error. The specified ability type is wrong. |
| 16000004 | Visibility verification failed. |
| 16000005 | Static permission denied. The specified process does not have the permission. |
| 16000006 | Can not cross user operations. |
| 16000007 | Service busyness. There are concurrent tasks, waiting for retry. |
| 16000008 | Crowdtest App Expiration. |
| 16000009 | Can not start ability in wukong mode. |
| 16000011 | Context does not exist.        |
| 16200001 | Caller released. The caller has been released. |
| 16000050 | Internal Error. |

**Example**

  ```ts
  let want = {
    deviceId: '',
    bundleName: 'com.extreme.test',
    abilityName: 'MainAbility'
  };
  let accountId = 100;

  try {
    this.context.startServiceExtensionAbilityWithAccount(want, accountId)
      .then((data) => {
        // Carry out normal service processing.
        console.log('startServiceExtensionAbilityWithAccount succeed');
      })
      .catch((error) => {
        // Process service logic errors.
        console.log('startServiceExtensionAbilityWithAccount failed, error.code: ' + JSON.stringify(error.code) +
          ' error.message: ' + JSON.stringify(error.message));
      });
  } catch (paramError) {
    // Process input parameter errors.
    console.log('error.code: ' + JSON.stringify(paramError.code) +
      ' error.message: ' + JSON.stringify(paramError.message));
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
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target UIAbility.|
| callback | AsyncCallback\<void\> | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Invalid input parameter. |
| 16000001 | Input error. The specified ability name does not exist. |
| 16000002 | Ability type error. The specified ability type is wrong. |
| 16000004 | Visibility verification failed. |
| 16000007 | Service busyness. There are concurrent tasks, waiting for retry. |
| 16000011 | Context does not exist.        |
| 16200001 | Caller released. The caller has been released. |
| 16000050 | Internal Error. |

**Example**

  ```ts
  let want = {
    deviceId: '',
    bundleName: 'com.extreme.test',
    abilityName: 'MainAbility'
  };

  try {
    this.context.stopServiceExtensionAbility(want, (error) => {
      if (error.code) {
        // Process service logic errors.
        console.log('stopServiceExtensionAbility failed, error.code: ' + JSON.stringify(error.code) +
          ' error.message: ' + JSON.stringify(error.message));
        return;
      }
      // Carry out normal service processing.
      console.log('stopServiceExtensionAbility succeed');
    });
  } catch (paramError) {
    // Process input parameter errors.
    console.log('error.code: ' + JSON.stringify(paramError.code) +
      ' error.message: ' + JSON.stringify(paramError.message));
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
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target UIAbility.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Invalid input parameter. |
| 16000001 | Input error. The specified ability name does not exist. |
| 16000002 | Ability type error. The specified ability type is wrong. |
| 16000004 | Visibility verification failed. |
| 16000007 | Service busyness. There are concurrent tasks, waiting for retry. |
| 16000011 | Context does not exist.        |
| 16200001 | Caller released. The caller has been released. |
| 16000050 | Internal Error. |

**Example**

  ```ts
  let want = {
    deviceId: '',
    bundleName: 'com.extreme.test',
    abilityName: 'MainAbility'
  };

  try {
    this.context.stopServiceExtensionAbility(want)
      .then((data) => {
        // Carry out normal service processing.
        console.log('stopServiceExtensionAbility succeed');
      })
      .catch((error) => {
        // Process service logic errors.
        console.log('stopServiceExtensionAbility failed, error.code: ' + JSON.stringify(error.code) +
          ' error.message: ' + JSON.stringify(error.message));
      });
  } catch (paramError) {
    // Process input parameter errors.
    console.log('error.code: ' + JSON.stringify(paramError.code) +
      ' error.message: ' + JSON.stringify(paramError.message));
  }
  ```

## UIAbilityContext.stopServiceExtensionAbilityWithAccount

stopServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void;

Stops a ServiceExtensionAbility with the account ID specified in the same application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target UIAbility.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess).|
| callback | AsyncCallback\<void\> | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Invalid input parameter. |
| 16000001 | Input error. The specified ability name does not exist. |
| 16000002 | Ability type error. The specified ability type is wrong. |
| 16000004 | Visibility verification failed. |
| 16000006 | Can not cross user operations. |
| 16000007 | Service busyness. There are concurrent tasks, waiting for retry. |
| 16000011 | Context does not exist.        |
| 16200001 | Caller released. The caller has been released. |
| 16000050 | Internal Error. |

**Example**

  ```ts
  let want = {
    deviceId: '',
    bundleName: 'com.extreme.test',
    abilityName: 'MainAbility'
  };
  let accountId = 100;

  try {
    this.context.stopServiceExtensionAbilityWithAccount(want, accountId, (error) => {
      if (error.code) {
        // Process service logic errors.
        console.log('stopServiceExtensionAbilityWithAccount failed, error.code: ' + JSON.stringify(error.code) +
          ' error.message: ' + JSON.stringify(error.message));
        return;
      }
      // Carry out normal service processing.
      console.log('stopServiceExtensionAbilityWithAccount succeed');
    });
  } catch (paramError) {
    // Process input parameter errors.
    console.log('error.code: ' + JSON.stringify(paramError.code) +
      ' error.message: ' + JSON.stringify(paramError.message));
  }
  ```

## UIAbilityContext.stopServiceExtensionAbilityWithAccount

stopServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise\<void>;

Stops a ServiceExtensionAbility with the account ID specified in the same application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target UIAbility.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess).|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Invalid input parameter. |
| 16000001 | Input error. The specified ability name does not exist. |
| 16000002 | Ability type error. The specified ability type is wrong. |
| 16000004 | Visibility verification failed. |
| 16000006 | Can not cross user operations. |
| 16000007 | Service busyness. There are concurrent tasks, waiting for retry. |
| 16000011 | Context does not exist.        |
| 16200001 | Caller released. The caller has been released. |
| 16000050 | Internal Error. |

**Example**

  ```ts
  let want = {
    deviceId: '',
    bundleName: 'com.extreme.test',
    abilityName: 'MainAbility'
  };
  let accountId = 100;

  try {
    this.context.stopServiceExtensionAbilityWithAccount(want, accountId)
      .then((data) => {
        // Carry out normal service processing.
        console.log('stopServiceExtensionAbilityWithAccount succeed');
      })
      .catch((error) => {
        // Process service logic errors.
        console.log('stopServiceExtensionAbilityWithAccount failed, error.code: ' + JSON.stringify(error.code) +
          ' error.message: ' + JSON.stringify(error.message));
      });
  } catch (paramError) {
    // Process input parameter errors.
    console.log('error.code: ' + JSON.stringify(paramError.code) +
      ' error.message: ' + JSON.stringify(paramError.message));
  }
  ```

## UIAbilityContext.terminateSelf

terminateSelf(callback: AsyncCallback&lt;void&gt;): void;

Terminates this UIAbility. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Invalid input parameter. |
| 16000001 | Input error. The specified ability name does not exist. |
| 16000007 | Service busyness. There are concurrent tasks, waiting for retry. |
| 16000011 | Context does not exist.        |
| 16000050 | Internal Error. |

**Example**

  ```ts
  this.context.terminateSelf((error) => {
    if (error.code) {
      // Process service logic errors.
      console.log('terminateSelf failed, error.code: ' + JSON.stringify(error.code) +
        ' error.message: ' + JSON.stringify(error.message));
      return;
    }
    // Carry out normal service processing.
    console.log('terminateSelf succeed');
  });
  ```


## UIAbilityContext.terminateSelf

terminateSelf(): Promise&lt;void&gt;;

Terminates this UIAbility. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Invalid input parameter. |
| 16000001 | Input error. The specified ability name does not exist. |
| 16000007 | Service busyness. There are concurrent tasks, waiting for retry. |
| 16000011 | Context does not exist.        |
| 16000050 | Internal Error. |

**Example**

  ```ts
  this.context.terminateSelf().then((data) => {
    // Carry out normal service processing.
    console.log('terminateSelf succeed');
  }).catch((error) => {
    // Process service logic errors.
    console.log('terminateSelf failed, error.code: ' + JSON.stringify(error.code) +
      ' error.message: ' + JSON.stringify(error.message));
  });
  ```


## UIAbilityContext.terminateSelfWithResult

terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback&lt;void&gt;): void;

Terminates this UIAbility. If the UIAbility is started by calling [startAbilityForResult](#uiabilitycontextstartabilityforresult), the result is returned to the initiator UIAbility in the form of an asynchronous callback when **terminateSelfWithResult** is called. Otherwise, no result is returned to the initiator UIAbility when **terminateSelfWithResult** is called.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| parameter | [AbilityResult](js-apis-inner-ability-abilityResult.md) | Yes| Information returned to the initiator UIAbility.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Invalid input parameter. |
| 16000001 | Input error. The specified ability name does not exist. |
| 16000007 | Service busyness. There are concurrent tasks, waiting for retry. |
| 16000011 | Context does not exist.        |
| 16000050 | Internal Error. |

**Example**

  ```ts
  let want = {
    bundleName: 'com.extreme.myapplication',
    abilityName: 'SecondAbility'
  }
  let resultCode = 100;
  // AbilityResult information returned to the initiator UIAbility.
  let abilityResult = {
    want,
    resultCode
  }

  try {
    this.context.terminateSelfWithResult(abilityResult, (error) => {
      if (error.code) {
        // Process service logic errors.
        console.log('terminateSelfWithResult failed, error.code: ' + JSON.stringify(error.code) +
          ' error.message: ' + JSON.stringify(error.message));
        return;
      }
      // Carry out normal service processing.
      console.log('terminateSelfWithResult succeed');
    });
  } catch (paramError) {
      // Process input parameter errors.
      console.log('error.code: ' + JSON.stringify(paramError.code) +
        ' error.message: ' + JSON.stringify(paramError.message));
  }
  ```


## UIAbilityContext.terminateSelfWithResult

terminateSelfWithResult(parameter: AbilityResult): Promise&lt;void&gt;;

Terminates this UIAbility. If the UIAbility is started by calling [startAbilityForResult](#uiabilitycontextstartabilityforresult), the result is returned to the initiator UIAbility in the form of a promise when **terminateSelfWithResult** is called. Otherwise, no result is returned to the initiator UIAbility when **terminateSelfWithResult** is called.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| parameter | [AbilityResult](js-apis-inner-ability-abilityResult.md) | Yes| Information returned to the initiator UIAbility.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Invalid input parameter. |
| 16000001 | Input error. The specified ability name does not exist. |
| 16000007 | Service busyness. There are concurrent tasks, waiting for retry. |
| 16000011 | Context does not exist.        |
| 16000050 | Internal Error. |


**Example**

  ```ts
  let want = {
    bundleName: 'com.extreme.myapplication',
    abilityName: 'SecondAbility'
  }
  let resultCode = 100;
  // AbilityResult information returned to the initiator UIAbility.
  let abilityResult = {
    want,
    resultCode
  }

  try {
    this.context.terminateSelfWithResult(abilityResult)
      .then((data) => {
        // Carry out normal service processing.
        console.log('terminateSelfWithResult succeed');
      })
      .catch((error) => {
        // Process service logic errors.
        console.log('terminateSelfWithResult failed, error.code: ' + JSON.stringify(error.code) +
          ' error.message: ' + JSON.stringify(error.message));
      });
  } catch (paramError) {
    // Process input parameter errors.
    console.log('error.code: ' + JSON.stringify(paramError.code) +
      ' error.message: ' + JSON.stringify(paramError.message));
  }
  ```

## UIAbilityContext.connectServiceExtensionAbility

connectServiceExtensionAbility(want: Want, options: ConnectOptions): number;

Connects this UIAbility to a UIAbility that uses the **AbilityInfo.AbilityType.SERVICE** template.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target UIAbility.|
| options | [ConnectOptions](js-apis-inner-ability-connectOptions.md) | No| Parameters for the connection.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Result code of the UIAbility connection.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Invalid input parameter. |
| 16000001 | Input error. The specified ability name does not exist. |
| 16000002 | Ability type error. The specified ability type is wrong. |
| 16000004 | Visibility verification failed. |
| 16000011 | Context does not exist.        |
| 16000050 | Internal Error. |

**Example**

  ```ts
  let want = {
    deviceId: '',
    bundleName: 'com.extreme.test',
    abilityName: 'MainAbility'
  };
  let options = {
    onConnect(elementName, remote) { console.log('----------- onConnect -----------') },
    onDisconnect(elementName) { console.log('----------- onDisconnect -----------') },
    onFailed(code) { console.log('----------- onFailed -----------') }
  }

  let connection = null;
  try {
    connection = this.context.connectServiceExtensionAbility(want, options);
  } catch (paramError) {
    // Process input parameter errors.
    console.log('error.code: ' + JSON.stringify(paramError.code) +
      ' error.message: ' + JSON.stringify(paramError.message));
  }
  ```


## UIAbilityContext.connectServiceExtensionAbilityWithAccount

connectServiceExtensionAbilityWithAccount(want: Want, accountId: number, options: ConnectOptions): number;

Connects this UIAbility to a UIAbility that uses the **AbilityInfo.AbilityType.SERVICE** template, with the account ID specified.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target UIAbility.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess).|
| options | [ConnectOptions](js-apis-inner-ability-connectOptions.md) | No| Parameters for the connection.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Result code of the UIAbility connection.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Invalid input parameter. |
| 16000001 | Input error. The specified ability name does not exist. |
| 16000002 | Ability type error. The specified ability type is wrong. |
| 16000004 | Visibility verification failed. |
| 16000006 | Can not cross user operations. |
| 16000011 | Context does not exist.        |
| 16000050 | Internal Error. |

**Example**

  ```ts
  let want = {
    deviceId: '',
    bundleName: 'com.extreme.test',
    abilityName: 'MainAbility'
  };
  let accountId = 100;
  let options = {
    onConnect(elementName, remote) { console.log('----------- onConnect -----------') },
    onDisconnect(elementName) { console.log('----------- onDisconnect -----------') },
    onFailed(code) { console.log('----------- onFailed -----------') }
  }

  let connection = null;
  try {
    connection = this.context.connectServiceExtensionAbilityWithAccount(want, accountId, options);
  } catch (paramError) {
    // Process input parameter errors.
    console.log('error.code: ' + JSON.stringify(paramError.code) +
      ' error.message: ' + JSON.stringify(paramError.message));
  }
  ```

## UIAbilityContext.disconnectServiceExtensionAbility

disconnectServiceExtensionAbility(connection: number): Promise\<void>;

Disconnects a connection. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| connection | number | Yes| Result code of the UIAbility connection.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Invalid input parameter. |
| 16000001 | Input error. The specified ability name does not exist. |
| 16000003 | Input error. The specified id does not exist. |
| 16000011 | Context does not exist.        |
| 16000050 | Internal Error. |

**Example**

  ```ts
  // connection is the return value of connectServiceExtensionAbility.
  let connection = 1;

  try {
    this.context.disconnectServiceExtensionAbility(connection)
      .then((data) => {
        // Carry out normal service processing.
        console.log('disconnectServiceExtensionAbility succeed');
      })
      .catch((error) => {
        // Process service logic errors.
        console.log('disconnectServiceExtensionAbility failed, error.code: ' + JSON.stringify(error.code) +
          ' error.message: ' + JSON.stringify(error.message));
      });
  } catch (paramError) {
    // Process input parameter errors.
    console.log('error.code: ' + JSON.stringify(paramError.code) +
      ' error.message: ' + JSON.stringify(paramError.message));
  }
  ```

## UIAbilityContext.disconnectServiceExtensionAbility

disconnectServiceExtensionAbility(connection: number, callback:AsyncCallback\<void>): void;

Disconnects a connection. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| connection | number | Yes| Result code of the UIAbility connection.|
| callback | AsyncCallback\<void> | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Invalid input parameter. |
| 16000001 | Input error. The specified ability name does not exist. |
| 16000003 | Input error. The specified id does not exist. |
| 16000011 | Context does not exist.        |
| 16000050 | Internal Error. |

**Example**

  ```ts
  // connection is the return value of connectServiceExtensionAbility.
  let connection = 1;

  try {
    this.context.disconnectServiceExtensionAbility(connection, (error) => {
      if (error.code) {
        // Process service logic errors.
        console.log('disconnectServiceExtensionAbility failed, error.code: ' + JSON.stringify(error.code) +
          ' error.message: ' + JSON.stringify(error.message));
        return;
      }
      // Carry out normal service processing.
      console.log('disconnectServiceExtensionAbility succeed');
    });
  } catch (paramError) {
    // Process input parameter errors.
    console.log('error.code: ' + JSON.stringify(paramError.code) +
      ' error.message: ' + JSON.stringify(paramError.message));
  }
  ```

## UIAbilityContext.startAbilityByCall

startAbilityByCall(want: Want): Promise&lt;Caller&gt;;

Starts a UIAbility in the foreground or background and obtains the caller object for communicating with the UIAbility.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start a UIAbility, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **visible** of the target UIAbility is **false**, the initiator UIAbility must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Information about the UIAbility to start, including **abilityName**, **moduleName**, **bundleName**, **deviceId** (optional), and **parameters** (optional). If **deviceId** is left blank or null, the local UIAbility is started. If **parameters** is left blank or null, the UIAbility is started in the background.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;Caller&gt; | Promise used to return the caller object to communicate with.|

**Example**

  Start a UIAbility in the background.

  ```ts
  let caller = undefined;

  // Start a UIAbility in the background by not passing parameters.
  let wantBackground = {
      bundleName: 'com.example.myservice',
      moduleName: 'entry',
      abilityName: 'MainAbility',
      deviceId: ''
  };

  try {
    this.context.startAbilityByCall(wantBackground)
      .then((obj) => {
        // Carry out normal service processing.
        caller = obj;
        console.log('startAbilityByCall succeed');
      }).catch((error) => {
        // Process service logic errors.
        console.log('startAbilityByCall failed, error.code: ' + JSON.stringify(error.code) +
          ' error.message: ' + JSON.stringify(error.message));
      });
  } catch (paramError) {
    // Process input parameter errors.
    console.log('error.code: ' + JSON.stringify(paramError.code) +
      ' error.message: ' + JSON.stringify(paramError.message));
  }
  ```

  Start a UIAbility in the foreground.

  ```ts
  let caller = undefined;

  // Start a UIAbility in the foreground with ohos.aafwk.param.callAbilityToForeground in parameters set to true.
  let wantForeground = {
      bundleName: 'com.example.myservice',
      moduleName: 'entry',
      abilityName: 'MainAbility',
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
        console.log('startAbilityByCall succeed');
      }).catch((error) => {
        // Process service logic errors.
        console.log('startAbilityByCall failed, error.code: ' + JSON.stringify(error.code) +
          ' error.message: ' + JSON.stringify(error.message));
      });
  } catch (paramError) {
    // Process input parameter errors.
    console.log('error.code: ' + JSON.stringify(paramError.code) +
      ' error.message: ' + JSON.stringify(paramError.message));
  }
  ```

## UIAbilityContext.startAbilityWithAccount

startAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void\>): void;

Starts a UIAbility with the account ID specified. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target UIAbility.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess).|
| callback | AsyncCallback\<void\> | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Invalid input parameter. |
| 16000001 | Input error. The specified ability name does not exist. |
| 16000004 | Visibility verification failed. |
| 16000005 | Static permission denied. The specified process does not have the permission. |
| 16000006 | Can not cross user operations. |
| 16000007 | Service busyness. There are concurrent tasks, waiting for retry. |
| 16000008 | Crowdtest App Expiration. |
| 16000009 | Can not start ability in wukong mode. |
| 16000010 | Can not operation with continue flag.        |
| 16000011 | Context does not exist.        |
| 16000051 | Network error. The network is abnormal. |
| 16000052 | Free install not support. The application does not support freeinstall |
| 16000053 | Not top ability. The application is not top ability. |
| 16000054 | Free install busyness. There are concurrent tasks, waiting for retry. |
| 16000055 | Free install timeout. |
| 16000056 | Can not free install other ability. |
| 16000057 | Not support cross device free install. |
| 16200001 | Caller released. The caller has been released. |
| 16000050 | Internal Error. |

**Example**

  ```ts
  let want = {
    deviceId: '',
    bundleName: 'com.extreme.test',
    abilityName: 'MainAbility'
  };
  let accountId = 100;

  try {
    this.context.startAbilityWithAccount(want, accountId, (error) => {
      if (error.code) {
        // Process service logic errors.
        console.log('startAbilityWithAccount failed, error.code: ' + JSON.stringify(error.code) +
          ' error.message: ' + JSON.stringify(error.message));
        return;
      }
      // Carry out normal service processing.
      console.log('startAbilityWithAccount succeed');
    });
  } catch (paramError) {
    // Process input parameter errors.
    console.log('error.code: ' + JSON.stringify(paramError.code) +
      ' error.message: ' + JSON.stringify(paramError.message));
  }
  ```


## UIAbilityContext.startAbilityWithAccount

startAbilityWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback\<void\>): void;

Starts a UIAbility with the start options and account ID specified. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target UIAbility.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess).|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | No| Parameters used for starting the UIAbility.|
| callback | AsyncCallback\<void\> | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Invalid input parameter. |
| 16000001 | Input error. The specified ability name does not exist. |
| 16000004 | Visibility verification failed. |
| 16000005 | Static permission denied. The specified process does not have the permission. |
| 16000006 | Can not cross user operations. |
| 16000007 | Service busyness. There are concurrent tasks, waiting for retry. |
| 16000008 | Crowdtest App Expiration. |
| 16000009 | Can not start ability in wukong mode. |
| 16000010 | Can not operation with continue flag.        |
| 16000011 | Context does not exist.        |
| 16000051 | Network error. The network is abnormal. |
| 16000052 | Free install not support. The application does not support freeinstall |
| 16000053 | Not top ability. The application is not top ability. |
| 16000054 | Free install busyness. There are concurrent tasks, waiting for retry. |
| 16000055 | Free install timeout. |
| 16000056 | Can not free install other ability. |
| 16000057 | Not support cross device free install. |
| 16200001 | Caller released. The caller has been released. |
| 16000050 | Internal Error. |

**Example**

  ```ts
  let want = {
    deviceId: '',
    bundleName: 'com.extreme.test',
    abilityName: 'MainAbility'
  };
  let accountId = 100;
  let options = {
    windowMode: 0
  };

  try {
    this.context.startAbilityWithAccount(want, accountId, options, (error) => {
      if (error.code) {
        // Process service logic errors.
        console.log('startAbilityWithAccount failed, error.code: ' + JSON.stringify(error.code) +
          ' error.message: ' + JSON.stringify(error.message));
        return;
      }
      // Carry out normal service processing.
      console.log('startAbilityWithAccount succeed');
    });
  } catch (paramError) {
    // Process input parameter errors.
    console.log('error.code: ' + JSON.stringify(paramError.code) +
      ' error.message: ' + JSON.stringify(paramError.message));
  }
  ```


## UIAbilityContext.startAbilityWithAccount

startAbilityWithAccount(want: Want, accountId: number, options?: StartOptions): Promise\<void\>;

Starts a UIAbility with the account ID specified. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target UIAbility.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess).|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | No| Parameters used for starting the UIAbility.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Invalid input parameter. |
| 16000001 | Input error. The specified ability name does not exist. |
| 16000004 | Visibility verification failed. |
| 16000005 | Static permission denied. The specified process does not have the permission. |
| 16000006 | Can not cross user operations. |
| 16000007 | Service busyness. There are concurrent tasks, waiting for retry. |
| 16000008 | Crowdtest App Expiration. |
| 16000009 | Can not start ability in wukong mode. |
| 16000010 | Can not operation with continue flag.        |
| 16000011 | Context does not exist.        |
| 16000051 | Network error. The network is abnormal. |
| 16000052 | Free install not support. The application does not support freeinstall |
| 16000053 | Not top ability. The application is not top ability. |
| 16000054 | Free install busyness. There are concurrent tasks, waiting for retry. |
| 16000055 | Free install timeout. |
| 16000056 | Can not free install other ability. |
| 16000057 | Not support cross device free install. |
| 16200001 | Caller released. The caller has been released. |
| 16000050 | Internal Error. |

**Example**

  ```ts
  let want = {
    deviceId: '',
    bundleName: 'com.extreme.test',
    abilityName: 'MainAbility'
  };
  let accountId = 100;
  let options = {
    windowMode: 0
  };

  try {
    this.context.startAbilityWithAccount(want, accountId, options)
      .then((data) => {
        // Carry out normal service processing.
        console.log('startAbilityWithAccount succeed');
      })
      .catch((error) => {
        // Process service logic errors.
        console.log('startAbilityWithAccount failed, error.code: ' + JSON.stringify(error.code) +
          ' error.message: ' + JSON.stringify(error.message));
      });
  } catch (paramError) {
    // Process input parameter errors.
    console.log('error.code: ' + JSON.stringify(paramError.code) +
      ' error.message: ' + JSON.stringify(paramError.message));
  }
  ```

## UIAbilityContext.requestPermissionsFromUser

requestPermissionsFromUser(permissions: Array&lt;string&gt;, requestCallback: AsyncCallback&lt;PermissionRequestResult&gt;) : void;

Requests permissions from the user by displaying a dialog box. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| permissions | Array&lt;string&gt; | Yes| Permissions to request.|
| callback | AsyncCallback&lt;[PermissionRequestResult](js-apis-inner-application-permissionRequestResult.md)&gt; | Yes| Callback used to return the result.|

**Example**

  ```ts
       let permissions=['com.example.permission']
       this.context.requestPermissionsFromUser(permissions,(result) => {
       console.log('requestPermissionsFromUserresult:' + JSON.stringify(result));
  });

  ```


## UIAbilityContext.requestPermissionsFromUser

requestPermissionsFromUser(permissions: Array&lt;string&gt;) : Promise&lt;PermissionRequestResult&gt;;

Requests permissions from the user by displaying a dialog box. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| permissions | Array&lt;string&gt; | Yes| Permissions to request.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[PermissionRequestResult](js-apis-inner-application-permissionRequestResult.md)&gt; | Promise used to return the result.|

**Example**

  ```ts
   let permissions=['com.example.permission']
       this.context.requestPermissionsFromUser(permissions).then((data) => {
      console.log('success:' + JSON.stringify(data));
  }).catch((error) => {
      console.log('failed:' + JSON.stringify(error));
  });

  ```


## UIAbilityContext.setMissionLabel

setMissionLabel(label: string, callback:AsyncCallback&lt;void&gt;): void;

Sets a label for this UIAbility in the mission. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| label | string | Yes| Label of the UIAbility to set.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Example**

  ```ts
  this.context.setMissionLabel('test',(result) => {
      console.log('requestPermissionsFromUserresult:' + JSON.stringify(result));
  });
  ```


## UIAbilityContext.setMissionLabel

setMissionLabel(label: string): Promise&lt;void&gt;;

Sets a label for this UIAbility in the mission. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| label | string | Yes| Label of the UIAbility to set.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

  ```ts
  this.context.setMissionLabel('test').then(() => {
      console.log('success');
  }).catch((error) => {
      console.log('failed:' + JSON.stringify(error));
  });
  ```
## UIAbilityContext.setMissionIcon

setMissionIcon(icon: image.PixelMap, callback:AsyncCallback\<void>): void;

Sets an icon for this UIAbility in the mission. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| icon | image.PixelMap | Yes| Icon of the UIAbility to set.|
| callback | AsyncCallback\<void> | Yes| Callback used to return the result.|

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
           console.log('--------- createPixelMap fail, err: ---------', err)
       });
    this.context.setMissionIcon(imagePixelMap, (err) => {
       console.log('---------- setMissionIcon fail, err: -----------', err);
    })
  ```


## UIAbilityContext.setMissionIcon

setMissionIcon(icon: image.PixelMap): Promise\<void>;

Sets an icon for this UIAbility in the mission. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| icon | image.PixelMap | Yes| Icon of the UIAbility to set.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

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
          console.log('--------- createPixelMap fail, err: ---------', err)
      });
    this.context.setMissionIcon(imagePixelMap)
      .then(() => {
          console.log('-------------- setMissionIcon success -------------');
      })
      .catch((err) => {
          console.log('-------------- setMissionIcon fail, err: -------------', err);
      });
  ```
## UIAbilityContext.restoreWindowStage

restoreWindowStage(localStorage: LocalStorage) : void;

Restores the window stage data for this UIAbility.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| localStorage | image.LocalStorage | Yes| Storage used to store the restored window stage.|

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

**Example**

  ```ts
  let isTerminating = this.context.isTerminating();
  console.log('ability state :' + isTerminating);
  ```
