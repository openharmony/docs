# UIAbilityContext

The **UIAbilityContext** module, inherited from **Context**, implements the context for abilities.

This module provides APIs for accessing ability-specific resources. You can use the APIs to start and terminate an ability, obtain the caller interface, and request permissions from users by displaying a dialog box.

> **NOTE**
>
>  - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>  - The APIs of this module can be used only in the stage model.

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| abilityInfo | [AbilityInfo](js-apis-bundleManager-abilityInfo.md) | Yes| No| Ability information.|
| currentHapModuleInfo | [HapModuleInfo](js-apis-bundleManager-hapModuleInfo.md) | Yes| No| Information about the current HAP.|
| config | [Configuration](js-apis-app-ability-configuration.md) | Yes| No| Configuration information.|

## AbilityContext.startAbility

startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void;

Starts an ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target ability.|
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
  var want = {
    bundleName: "com.example.myapp",
    abilityName: "MyAbility"
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


## AbilityContext.startAbility

startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;): void;

Starts an ability with the start options specified. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md)  | Yes| Want information about the target ability.|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | Yes| Parameters used for starting the ability.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message
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
  var want = {
    deviceId: "",
    bundleName: "com.extreme.test",
    abilityName: "MainAbility"
  };
  var options = {
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

## AbilityContext.startAbility

startAbility(want: Want, options?: StartOptions): Promise&lt;void&gt;;

Starts an ability. This API uses a promise to return the result.

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
  var want = {
    bundleName: "com.example.myapp",
    abilityName: "MyAbility"
  };
  var options = {
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


## AbilityContext.startAbilityForResult

startAbilityForResult(want: Want, callback: AsyncCallback&lt;AbilityResult&gt;): void;

Starts an ability. This API uses an asynchronous callback to return the result when the ability is terminated.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-application-want.md) | Yes| Want information about the target ability.|
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
  var want = {
    deviceId: "",
    bundleName: "com.extreme.test",
    abilityName: "MainAbility"
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
      console.log("startAbilityForResult succeed, result.resultCode = " +
        result.resultCode)
    });
  } catch (paramError) {
    // Process input parameter errors.
    console.log('error.code: ' + JSON.stringify(paramError.code) +
      ' error.message: ' + JSON.stringify(paramError.message));
  }
  ```

## AbilityContext.startAbilityForResult

startAbilityForResult(want: Want, options: StartOptions, callback: AsyncCallback&lt;AbilityResult&gt;): void;

Starts an ability with the start options specified. This API uses an asynchronous callback to return the result when the ability is terminated.

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
  var want = {
    deviceId: "",
    bundleName: "com.extreme.test",
    abilityName: "MainAbility"
  };
  var options = {
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
      console.log("startAbilityForResult succeed, result.resultCode = " +
        result.resultCode)
    });
  } catch (paramError) {
    // Process input parameter errors.
    console.log('error.code: ' + JSON.stringify(paramError.code) +
      ' error.message: ' + JSON.stringify(paramError.message));
  }
  ```


## AbilityContext.startAbilityForResult

startAbilityForResult(want: Want, options?: StartOptions): Promise&lt;AbilityResult&gt;;

Starts an ability. This API uses a promise to return the result when the ability is terminated.

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
  var want = {
    bundleName: "com.example.myapp",
    abilityName: "MyAbility"
  };
  var options = {
  	windowMode: 0,
  };

  try {
    this.context.startAbilityForResult(want, options)
      .then((result) => {
        // Carry out normal service processing.
        console.log("startAbilityForResult succeed, result.resultCode = " + result.resultCode);
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

## AbilityContext.startAbilityForResultWithAccount

startAbilityForResultWithAccount(want: Want, accountId: number, callback: AsyncCallback\<AbilityResult>): void;

Starts an ability. This API uses an asynchronous callback to return the result when the account of the ability is destroyed.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target ability.|
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
  var want = {
    deviceId: "",
    bundleName: "com.extreme.test",
    abilityName: "MainAbility"
  };
  var accountId = 100;

  try {
    this.context.startAbilityForResultWithAccount(want, accountId, (error, result) => {
      if (error.code) {
        // Process service logic errors.
        console.log('startAbilityForResultWithAccount failed, error.code: ' + JSON.stringify(error.code) +
          ' error.message: ' + JSON.stringify(error.message));
        return;
      }
      // Carry out normal service processing.
      console.log("startAbilityForResultWithAccount succeed, result.resultCode = " +
        result.resultCode)
    });
  } catch (paramError) {
    // Process input parameter errors.
    console.log('error.code: ' + JSON.stringify(paramError.code) +
      ' error.message: ' + JSON.stringify(paramError.message));
  }
  ```


## AbilityContext.startAbilityForResultWithAccount

startAbilityForResultWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback\<void\>): void;

Starts an ability with the start options specified. This API uses an asynchronous callback to return the result when the account of the ability is destroyed.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target ability.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess).|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | Yes| Parameters used for starting the ability.|
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
  var want = {
    deviceId: "",
    bundleName: "com.extreme.test",
    abilityName: "MainAbility"
  };
  var accountId = 100;
  var options = {
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
      console.log("startAbilityForResultWithAccount succeed, result.resultCode = " +
        result.resultCode)
    });
  } catch (paramError) {
    // Process input parameter errors.
    console.log('error.code: ' + JSON.stringify(paramError.code) +
      ' error.message: ' + JSON.stringify(paramError.message));
  }
  ```


## AbilityContext.startAbilityForResultWithAccount

startAbilityForResultWithAccount(want: Want, accountId: number, options?: StartOptions): Promise\<AbilityResult\>;

Starts an ability with the start options specified. This API uses a promise to return the result when the account of the ability is destroyed.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target ability.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess).|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | No| Parameters used for starting the ability.|

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
  var want = {
    deviceId: "",
    bundleName: "com.extreme.test",
    abilityName: "MainAbility"
  };
  var accountId = 100;
  var options = {
    windowMode: 0
  };

  try {
    this.context.startAbilityForResultWithAccount(want, accountId, options)
      .then((result) => {
        // Carry out normal service processing.
        console.log("startAbilityForResultWithAccount succeed, result.resultCode = " +
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
## AbilityContext.startServiceExtensionAbility

startServiceExtensionAbility(want: Want, callback: AsyncCallback\<void>): void;

Starts a new Service Extension ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target ability.|
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
  var want = {
    deviceId: "",
    bundleName: "com.extreme.test",
    abilityName: "MainAbility"
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

## AbilityContext.startServiceExtensionAbility

startServiceExtensionAbility(want: Want): Promise\<void>;

Starts a new Service Extension ability. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target ability.|

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
  var want = {
    deviceId: "",
    bundleName: "com.extreme.test",
    abilityName: "MainAbility"
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

## AbilityContext.startServiceExtensionAbilityWithAccount

startServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void;

Starts a new Service Extension ability with the account ID specified. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target ability.|
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
  var want = {
    deviceId: "",
    bundleName: "com.extreme.test",
    abilityName: "MainAbility"
  };
  var accountId = 100;

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

## AbilityContext.startServiceExtensionAbilityWithAccount

startServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise\<void>;

Starts a new Service Extension ability with the account ID specified. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target ability.|
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
  var want = {
    deviceId: "",
    bundleName: "com.extreme.test",
    abilityName: "MainAbility"
  };
  var accountId = 100;

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
## AbilityContext.stopServiceExtensionAbility

stopServiceExtensionAbility(want: Want, callback: AsyncCallback\<void>): void;

Stops a Service Extension ability in the same application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target ability.|
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
  var want = {
    deviceId: "",
    bundleName: "com.extreme.test",
    abilityName: "MainAbility"
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

## AbilityContext.stopServiceExtensionAbility

stopServiceExtensionAbility(want: Want): Promise\<void>;

Stops a Service Extension ability in the same application. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target ability.|

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
  var want = {
    deviceId: "",
    bundleName: "com.extreme.test",
    abilityName: "MainAbility"
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

## AbilityContext.stopServiceExtensionAbilityWithAccount

stopServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void;

Stops a Service Extension ability in the same application with the account ID specified. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target ability.|
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
  var want = {
    deviceId: "",
    bundleName: "com.extreme.test",
    abilityName: "MainAbility"
  };
  var accountId = 100;

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

## AbilityContext.stopServiceExtensionAbilityWithAccount

stopServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise\<void>;

Stops a Service Extension ability in the same application with the account ID specified. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target ability.|
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
  var want = {
    deviceId: "",
    bundleName: "com.extreme.test",
    abilityName: "MainAbility"
  };
  var accountId = 100;

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

## AbilityContext.terminateSelf

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


## AbilityContext.terminateSelf

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


## AbilityContext.terminateSelfWithResult

terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback&lt;void&gt;): void;

Terminates this ability. This API uses an asynchronous callback to return the ability result information. It is used together with **startAbilityForResult**.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| parameter | [AbilityResult](js-apis-inner-ability-abilityResult.md) | Yes| Information returned to the caller.|
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
  var want = {
    bundleName: "com.extreme.myapplication",
    abilityName: "SecondAbility"
  }
  var resultCode = 100;
  // AbilityResult information returned to the caller.
  var abilityResult = {
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


## AbilityContext.terminateSelfWithResult

terminateSelfWithResult(parameter: AbilityResult): Promise&lt;void&gt;;

Terminates this ability. This API uses a promise to return the ability result information. It is used together with **startAbilityForResult**.

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
| 201 | The application does not have permission to call the interface. |
| 401 | Invalid input parameter. |
| 16000001 | Input error. The specified ability name does not exist. |
| 16000007 | Service busyness. There are concurrent tasks, waiting for retry. |
| 16000011 | Context does not exist.        |
| 16000050 | Internal Error. |


**Example**

  ```ts
  var want = {
    bundleName: "com.extreme.myapplication",
    abilityName: "SecondAbility"
  }
  var resultCode = 100;
  // AbilityResult information returned to the caller.
  var abilityResult = {
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

## AbilityContext.connectServiceExtensionAbility

connectServiceExtensionAbility(want: Want, options: ConnectOptions): number;

Uses the **AbilityInfo.AbilityType.SERVICE** template to connect this ability to another ability.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target ability.|
| options | [ConnectOptions](js-apis-inner-ability-connectOptions.md) | No| Parameters for the connection.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Result code of the ability connection.|

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
  var want = {
    deviceId: "",
    bundleName: "com.extreme.test",
    abilityName: "MainAbility"
  };
  var options = {
    onConnect(elementName, remote) { console.log('----------- onConnect -----------') },
    onDisconnect(elementName) { console.log('----------- onDisconnect -----------') },
    onFailed(code) { console.log('----------- onFailed -----------') }
  }

  var connection = null;
  try {
    connection = this.context.connectServiceExtensionAbility(want, options);
  } catch (paramError) {
    // Process input parameter errors.
    console.log('error.code: ' + JSON.stringify(paramError.code) +
      ' error.message: ' + JSON.stringify(paramError.message));
  }
  ```


## AbilityContext.connectServiceExtensionAbilityWithAccount

connectServiceExtensionAbilityWithAccount(want: Want, accountId: number, options: ConnectOptions): number;

Uses the **AbilityInfo.AbilityType.SERVICE** template and account ID to connect this ability to another ability with the account ID specified.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target ability.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess).|
| options | [ConnectOptions](js-apis-inner-ability-connectOptions.md) | No| Parameters for the connection.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Result code of the ability connection.|

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
  var want = {
    deviceId: "",
    bundleName: "com.extreme.test",
    abilityName: "MainAbility"
  };
  var accountId = 100;
  var options = {
    onConnect(elementName, remote) { console.log('----------- onConnect -----------') },
    onDisconnect(elementName) { console.log('----------- onDisconnect -----------') },
    onFailed(code) { console.log('----------- onFailed -----------') }
  }

  var connection = null;
  try {
    connection = this.context.connectServiceExtensionAbilityWithAccount(want, accountId, options);
  } catch (paramError) {
    // Process input parameter errors.
    console.log('error.code: ' + JSON.stringify(paramError.code) +
      ' error.message: ' + JSON.stringify(paramError.message));
  }
  ```

## AbilityContext.disconnectServiceExtensionAbility

disconnectServiceExtensionAbility(connection: number): Promise\<void>;

Disconnects a connection. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| connection | number | Yes| Result code of the ability connection.|

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
  var connection = 1;

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

## AbilityContext.disconnectServiceExtensionAbility

disconnectServiceExtensionAbility(connection: number, callback:AsyncCallback\<void>): void;

Disconnects a connection. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| connection | number | Yes| Result code of the ability connection.|
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
  var connection = 1;

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

## AbilityContext.startAbilityByCall

startAbilityByCall(want: Want): Promise&lt;Caller&gt;;

Starts an ability in the foreground or background and obtains the caller object for communicating with the ability.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Information about the ability to start, including **abilityName**, **moduleName**, **bundleName**, **deviceId** (optional), and **parameters** (optional). If **deviceId** is left blank or null, the local ability is started. If **parameters** is left blank or null, the ability is started in the background.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;Caller&gt; | Promise used to return the caller object to communicate with.|

**Example**

  Start an ability in the background.

  ```ts
  var caller = undefined;

  // Start an ability in the background by not passing parameters.
  var wantBackground = {
      bundleName: "com.example.myservice",
      moduleName: "entry",
      abilityName: "MainAbility",
      deviceId: ""
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

  Start an ability in the foreground.

  ```ts
  var caller = undefined;

  // Start an ability in the foreground with ohos.aafwk.param.callAbilityToForeground in parameters set to true.
  var wantForeground = {
      bundleName: "com.example.myservice",
      moduleName: "entry",
      abilityName: "MainAbility",
      deviceId: "",
      parameters: {
        "ohos.aafwk.param.callAbilityToForeground": true
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

## AbilityContext.startAbilityWithAccount

startAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void\>): void;

Starts an ability with the account ID specified. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target ability.|
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
  var want = {
    deviceId: "",
    bundleName: "com.extreme.test",
    abilityName: "MainAbility"
  };
  var accountId = 100;

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


## AbilityContext.startAbilityWithAccount

startAbilityWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback\<void\>): void;

Starts an ability with the account ID and start options specified. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target ability.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess).|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | No| Parameters used for starting the ability.|
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
  var want = {
    deviceId: "",
    bundleName: "com.extreme.test",
    abilityName: "MainAbility"
  };
  var accountId = 100;
  var options = {
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


## AbilityContext.startAbilityWithAccount

startAbilityWithAccount(want: Want, accountId: number, options?: StartOptions): Promise\<void\>;

Starts an ability with the account ID specified. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Want information about the target ability.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess).|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | No| Parameters used for starting the ability.|

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
  var want = {
    deviceId: "",
    bundleName: "com.extreme.test",
    abilityName: "MainAbility"
  };
  var accountId = 100;
  var options = {
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

## AbilityContext.requestPermissionsFromUser

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
       var permissions=['com.example.permission']
       this.context.requestPermissionsFromUser(permissions,(result) => {
       console.log('requestPermissionsFromUserresult:' + JSON.stringify(result));
  });

  ```


## AbilityContext.requestPermissionsFromUser

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
   var permissions=['com.example.permission']
       this.context.requestPermissionsFromUser(permissions).then((data) => {
      console.log('success:' + JSON.stringify(data));
  }).catch((error) => {
      console.log('failed:' + JSON.stringify(error));
  });

  ```


## AbilityContext.setMissionLabel

setMissionLabel(label: string, callback:AsyncCallback&lt;void&gt;): void;

Sets a label for this ability in the mission. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| label | string | Yes| Label of the ability to set.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Example**

  ```ts
  this.context.setMissionLabel("test",(result) => {
      console.log('requestPermissionsFromUserresult:' + JSON.stringify(result));
  });
  ```


## AbilityContext.setMissionLabel

setMissionLabel(label: string): Promise&lt;void&gt;;

Sets a label for this ability in the mission. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| label | string | Yes| Label of the ability to set.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

  ```ts
  this.context.setMissionLabel("test").then(() => {
      console.log('success');
  }).catch((error) => {
      console.log('failed:' + JSON.stringify(error));
  });
  ```
## AbilityContext.setMissionIcon

setMissionIcon(icon: image.PixelMap, callback:AsyncCallback\<void>): void;

Sets an icon for this ability in the mission. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| icon | image.PixelMap | Yes| Icon of the ability to set.|
| callback | AsyncCallback\<void> | Yes| Callback used to return the result.|

**Example**

  ```ts
    import image from '@ohos.multimedia.image';
    var imagePixelMap;
    var color = new ArrayBuffer(0);
    var initializationOptions = {
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


## AbilityContext.setMissionIcon

setMissionIcon(icon: image.PixelMap): Promise\<void>;

Sets an icon for this ability in the mission. This API uses a promise to return the result.

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

**Example**

  ```ts
    import image from '@ohos.multimedia.image';
    var imagePixelMap;
    var color = new ArrayBuffer(0);
    var initializationOptions = {
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
## AbilityContext.restoreWindowStage

restoreWindowStage(localStorage: LocalStorage) : void;

Restores the window stage data for this ability.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| localStorage | image.LocalStorage | Yes| Storage used to store the restored window stage.|

**Example**

  ```ts
    var storage = new LocalStorage();
    this.context.restoreWindowStage(storage);
  ```

## AbilityContext.isTerminating

isTerminating(): boolean;

Checks whether this ability is in the terminating state.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type| Description|
| -------- | -------- |
| boolean| The value **true** means that the ability is in the terminating state, and **false** means the opposite.|

**Example**

  ```ts
  var isTerminating = this.context.isTerminating();
  console.log('ability state :' + isTerminating);
  ```
