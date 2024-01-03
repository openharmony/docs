# ServiceExtensionContext

The ServiceExtensionContext module, inherited from **ExtensionContext**, provides context for the ServiceExtensionAbility.

You can use the APIs of this module to start, terminate, connect, and disconnect an Ability.

> **NOTE**
> 
>  - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>  - The APIs of this module can be used only in the stage model.
>  - The APIs of this module must be used in the main thread, but not in sub-threads such as Worker and TaskPool.

## Modules to Import

```ts
import common from '@ohos.app.ability.common';
```

## Usage

Before using the **ServiceExtensionContext** module, you must define a child class that inherits from **ServiceExtensionAbility**.

**Example**

```ts
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';
import rpc from '@ohos.rpc';

let commRemote: rpc.IRemoteObject; // Release the instance when the connection is disconnected.
class EntryAbility extends ServiceExtensionAbility {
  onCreate() {
      let context = this.context; // Obtain a ServiceExtensionContext instance.
  }
}
```

## ServiceExtensionContext.startAbility

startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void;

Starts an ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md)  | Yes| Want information about the target ability, such as the ability name and bundle name.|
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
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

class EntryAbility extends ServiceExtensionAbility {
  onCreate() {
    let want: Want = {
      bundleName: 'com.example.myapp',
      abilityName: 'MyAbility'
    };

    try {
      this.context.startAbility(want, (error: BusinessError) => {
        if (error.code) {
          // Process service logic errors.
          console.error(`startAbility failed, error.code: ${error.code}, error.message: ${error.message}`);
          return;
        }
        // Carry out normal service processing.
        console.log('startAbility succeed');
      });
    } catch (paramError) {
      // Process input parameter errors.
      console.error(`error.code: ${paramError.code}, error.message: ${paramError.message}`);
    }
  }
}
```

## ServiceExtensionContext.startAbility

startAbility(want: Want, options?: StartOptions): Promise\<void>;

Starts an ability. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md)  | Yes| Want information about the target ability, such as the ability name and bundle name.|
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
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';
import Want from '@ohos.app.ability.Want';
import StartOptions from '@ohos.app.ability.StartOptions';
import { BusinessError } from '@ohos.base';

class EntryAbility extends ServiceExtensionAbility {
  onCreate() {
    let want: Want = {
      bundleName: 'com.example.myapp',
      abilityName: 'MyAbility'
    };
    let options: StartOptions = {
      windowMode: 0,
    };

    try {
      this.context.startAbility(want, options)
        .then((data: void) => {
          // Carry out normal service processing.
          console.log('startAbility succeed');
        })
        .catch((error: BusinessError) => {
          // Process service logic errors.
          console.error('startAbility failed, error.code: ${error.code}, error.message: ${error.message}');
        });
    } catch (paramError) {
      // Process input parameter errors.
      console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');
    }
  }
}
```

## ServiceExtensionContext.startAbility

startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;): void

Starts an ability with the start options specified. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

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
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';
import Want from '@ohos.app.ability.Want';
import StartOptions from '@ohos.app.ability.StartOptions';
import { BusinessError } from '@ohos.base';

class EntryAbility extends ServiceExtensionAbility {
  onCreate() {
    let want: Want = {
      deviceId: '',
      bundleName: 'com.example.myapplication',
      abilityName: 'EntryAbility'
    };
    let options: StartOptions = {
      windowMode: 0
    };

    try {
      this.context.startAbility(want, options, (error: BusinessError) => {
        if (error.code) {
          // Process service logic errors.
          console.error('startAbility failed, error.code: ${error.code}, error.message: ${error.message}');
          return;
        }
        // Carry out normal service processing.
        console.log('startAbility succeed');
      });
    } catch (paramError) {
      // Process input parameter errors.
      console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');
    }
  }
}
```

## ServiceExtensionContext.startAbilityWithAccount

startAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void;

Starts an ability with the account ID specified. This API uses an asynchronous callback to return the result.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **exported** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getcreatedosaccountscountdeprecated).|
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
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

class EntryAbility extends ServiceExtensionAbility {
  onCreate() {
    let want: Want = {
      deviceId: '',
      bundleName: 'com.example.myapplication',
      abilityName: 'EntryAbility'
    };
    let accountId = 100;

    try {
      this.context.startAbilityWithAccount(want, accountId, (error: BusinessError) => {
        if (error.code) {
          // Process service logic errors.
          console.error('startAbilityWithAccount failed, error.code: ${error.code}, error.message: ${error.message}');
          return;
        }
        // Carry out normal service processing.
        console.log('startAbilityWithAccount succeed');
      });
    } catch (paramError) {
      // Process input parameter errors.
      console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');
    }
  }
}
```

## ServiceExtensionContext.startAbilityWithAccount

startAbilityWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback\<void\>): void;

Starts an ability with the account ID and start options specified. This API uses an asynchronous callback to return the result.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **exported** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getcreatedosaccountscountdeprecated).|
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
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';
import Want from '@ohos.app.ability.Want';
import StartOptions from '@ohos.app.ability.StartOptions';
import { BusinessError } from '@ohos.base';

class EntryAbility extends ServiceExtensionAbility {
  onCreate() {
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
      this.context.startAbilityWithAccount(want, accountId, options, (error: BusinessError) => {
        if (error.code) {
          // Process service logic errors.
          console.error('startAbilityWithAccount failed, error.code: ${error.code}, error.message: ${error.message}');
          return;
        }
        // Carry out normal service processing.
        console.log('startAbilityWithAccount succeed');
      });
    } catch (paramError) {
      // Process input parameter errors.
      console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');
    }
  }
}
```


## ServiceExtensionContext.startAbilityWithAccount

startAbilityWithAccount(want: Want, accountId: number, options?: StartOptions): Promise\<void>;

Starts an ability with the account ID specified. This API uses a promise to return the result.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **exported** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getcreatedosaccountscountdeprecated-1).|
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
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';
import Want from '@ohos.app.ability.Want';
import StartOptions from '@ohos.app.ability.StartOptions';
import { BusinessError } from '@ohos.base';

class EntryAbility extends ServiceExtensionAbility {
  onCreate() {
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
        .then((data: void) => {
          // Carry out normal service processing.
          console.log('startAbilityWithAccount succeed');
        })
        .catch((error: BusinessError) => {
          // Process service logic errors.
          console.error('startAbilityWithAccount failed, error.code: ${error.code}, error.message: ${error.message}');
        });
    } catch (paramError) {
      // Process input parameter errors.
      console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');
    }
  }
}
```

## ServiceExtensionContext.startServiceExtensionAbility

startServiceExtensionAbility(want: Want, callback: AsyncCallback\<void>): void;

Starts a new ServiceExtensionAbility. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability.|
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
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

class EntryAbility extends ServiceExtensionAbility {
  onCreate() {
    let want: Want = {
      deviceId: '',
      bundleName: 'com.example.myapplication',
      abilityName: 'EntryAbility'
    };

    try {
      this.context.startServiceExtensionAbility(want, (error: BusinessError) => {
        if (error.code) {
          // Process service logic errors.
          console.error('startServiceExtensionAbility failed, error.code: ${error.code}, error.message: ${error.message}');
          return;
        }
        // Carry out normal service processing.
        console.log('startServiceExtensionAbility succeed');
      });
    } catch (paramError) {
      // Process input parameter errors.
      console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');
    }
  }
}
```

## ServiceExtensionContext.startServiceExtensionAbility

startServiceExtensionAbility(want: Want): Promise\<void>;

Starts a new ServiceExtensionAbility. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability.|

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
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

class EntryAbility extends ServiceExtensionAbility {
  onCreate() {
    let want: Want = {
      deviceId: '',
      bundleName: 'com.example.myapplication',
      abilityName: 'EntryAbility'
    };

    try {
      this.context.startServiceExtensionAbility(want)
        .then((data: void) => {
          // Carry out normal service processing.
          console.log('startServiceExtensionAbility succeed');
        })
        .catch((error: BusinessError) => {
          // Process service logic errors.
          console.error('startServiceExtensionAbility failed, error.code: ${error.code}, error.message: ${error.message}');
        });
    } catch (paramError) {
      // Process input parameter errors.
      console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');
    }
  }
}
```

## ServiceExtensionContext.startServiceExtensionAbilityWithAccount

startServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void;

Starts a new ServiceExtensionAbility with the account ID specified. This API uses an asynchronous callback to return the result.

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
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getcreatedosaccountscountdeprecated).|
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
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).


**Example**

```ts
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

class EntryAbility extends ServiceExtensionAbility {
  onCreate() {
    let want: Want = {
      deviceId: '',
      bundleName: 'com.example.myapplication',
      abilityName: 'EntryAbility'
    };
    let accountId = 100;

    try {
      this.context.startServiceExtensionAbilityWithAccount(want, accountId, (error: BusinessError) => {
        if (error.code) {
          // Process service logic errors.
          console.error('startServiceExtensionAbilityWithAccount failed, error.code: ${error.code}, error.message: ${error.message}');
          return;
        }
        // Carry out normal service processing.
        console.log('startServiceExtensionAbilityWithAccount succeed');
      });
    } catch (paramError) {
      // Process input parameter errors.
      console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');
    }
  }
}
```

## ServiceExtensionContext.startServiceExtensionAbilityWithAccount

startServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise\<void>;

Starts a new ServiceExtensionAbility with the account ID specified. This API uses a promise to return the result.

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
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getcreatedosaccountscountdeprecated-1).|

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
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

class EntryAbility extends ServiceExtensionAbility {
  onCreate() {
    let want: Want = {
      deviceId: '',
      bundleName: 'com.example.myapplication',
      abilityName: 'EntryAbility'
    };
    let accountId = 100;

    try {
      this.context.startServiceExtensionAbilityWithAccount(want, accountId)
        .then((data: void) => {
          // Carry out normal service processing.
          console.log('startServiceExtensionAbilityWithAccount succeed');
        })
        .catch((error: BusinessError) => {
          // Process service logic errors.
          console.error('startServiceExtensionAbilityWithAccount failed, error.code: ${error.code}, error.message: ${error.message}');
        });
    } catch (paramError) {
      // Process input parameter errors.
      console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');
    }
  }
}
```

## ServiceExtensionContext.startAbilityAsCaller<sup>10+<sup>

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
import extension from '@ohos.app.ability.ServiceExtensionAbility';
import Want from '@ohos.app.ability.Want';

export default class EntryAbility extends extension {
  onCreate(want: Want) {
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

## ServiceExtensionContext.startAbilityAsCaller<sup>10+<sup>

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
import extension from '@ohos.app.ability.ServiceExtensionAbility';
import Want from '@ohos.app.ability.Want';
import StartOptions from '@ohos.app.ability.StartOptions';

export default class EntryAbility extends extension {
  onCreate(want: Want) {
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

## ServiceExtensionContext.startAbilityAsCaller<sup>10+<sup>

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
import extension from '@ohos.app.ability.ServiceExtensionAbility';
import Want from '@ohos.app.ability.Want';
import StartOptions from '@ohos.app.ability.StartOptions';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends extension {
  onCreate(want: Want) {
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

## ServiceExtensionContext.stopServiceExtensionAbility

stopServiceExtensionAbility(want: Want, callback: AsyncCallback\<void>): void;

Stops a ServiceExtensionAbility in the same application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability.|
| callback | AsyncCallback\<void\> | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000011 | The context does not exist.        |
| 16000050 | Internal error. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

class EntryAbility extends ServiceExtensionAbility {
  onCreate() {
    let want: Want = {
      deviceId: '',
      bundleName: 'com.example.myapplication',
      abilityName: 'EntryAbility'
    };

    try {
      this.context.stopServiceExtensionAbility(want, (error: BusinessError) => {
        if (error.code) {
          // Process service logic errors.
          console.error('stopServiceExtensionAbility failed, error.code: ${error.code}, error.message: ${error.message}');
          return;
        }
        // Carry out normal service processing.
        console.log('stopServiceExtensionAbility succeed');
      });
    } catch (paramError) {
      // Process input parameter errors.
      console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');
    }
  }
}
```

## ServiceExtensionContext.stopServiceExtensionAbility

stopServiceExtensionAbility(want: Want): Promise\<void>;

Stops a ServiceExtensionAbility in the same application. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability.|

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
| 16000011 | The context does not exist.        |
| 16000050 | Internal error. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

class EntryAbility extends ServiceExtensionAbility {
  onCreate() {
    let want: Want = {
      deviceId: '',
      bundleName: 'com.example.myapplication',
      abilityName: 'EntryAbility'
    };

    try {
      this.context.stopServiceExtensionAbility(want)
        .then(() => {
          // Carry out normal service processing.
          console.log('stopServiceExtensionAbility succeed');
        })
        .catch((error: BusinessError) => {
          // Process service logic errors.
          console.error('stopServiceExtensionAbility failed, error.code: ${error.code}, error.message: ${error.message}');
        });
    } catch (paramError) {
      // Process input parameter errors.
      console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');
    }
  }
}
```

## ServiceExtensionContext.stopServiceExtensionAbilityWithAccount

stopServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void;

Stops a ServiceExtensionAbility in the same application with the account ID specified. This API uses an asynchronous callback to return the result.

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
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getcreatedosaccountscountdeprecated).|
| callback | AsyncCallback\<void\> | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000011 | The context does not exist.        |
| 16000050 | Internal error. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

class EntryAbility extends ServiceExtensionAbility {
  onCreate() {
    let want: Want = {
      deviceId: '',
      bundleName: 'com.example.myapplication',
      abilityName: 'EntryAbility'
    };
    let accountId = 100;

    try {
      this.context.stopServiceExtensionAbilityWithAccount(want, accountId, (error: BusinessError) => {
        if (error.code) {
          // Process service logic errors.
          console.error('stopServiceExtensionAbilityWithAccount failed, error.code: ${error.code, error.message: ${error.message}');
          return;
        }
        // Carry out normal service processing.
        console.log('stopServiceExtensionAbilityWithAccount succeed');
      });
    } catch (paramError) {
      // Process input parameter errors.
      console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');
    }
  }
}
```

## ServiceExtensionContext.stopServiceExtensionAbilityWithAccount

stopServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise\<void>;

Stops a ServiceExtensionAbility in the same application with the account ID specified. This API uses a promise to return the result.

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
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getcreatedosaccountscountdeprecated-1).|

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
| 16000011 | The context does not exist.        |
| 16000050 | Internal error. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

class EntryAbility extends ServiceExtensionAbility {
  onCreate() {
    let want: Want = {
      deviceId: '',
      bundleName: 'com.example.myapplication',
      abilityName: 'EntryAbility'
    };
    let accountId = 100;

    try {
      this.context.stopServiceExtensionAbilityWithAccount(want, accountId)
        .then(() => {
          // Carry out normal service processing.
          console.log('stopServiceExtensionAbilityWithAccount succeed');
        })
        .catch((error: BusinessError) => {
          // Process service logic errors.
          console.error('stopServiceExtensionAbilityWithAccount failed, error.code: ${error.code}, error.message: ${error.message}');
        });
    } catch (paramError) {
      // Process input parameter errors.
      console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');
    }
  }
}
```

## ServiceExtensionContext.terminateSelf

terminateSelf(callback: AsyncCallback&lt;void&gt;): void;

Terminates this ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

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
| 16000011 | The context does not exist.        |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';
import { BusinessError } from '@ohos.base';

class EntryAbility extends ServiceExtensionAbility {
  onCreate() {
    this.context.terminateSelf((error: BusinessError) => {
      if (error.code) {
        // Process service logic errors.
        console.error('terminateSelf failed, error.code: ${error.code}, error.message: ${error.message}');
        return;
      }
      // Carry out normal service processing.
      console.log('terminateSelf succeed');
    });
  }
}
```

## ServiceExtensionContext.terminateSelf

terminateSelf(): Promise&lt;void&gt;;

Terminates this ability. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

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
| 16000011 | The context does not exist.        |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';
import { BusinessError } from '@ohos.base';

class EntryAbility extends ServiceExtensionAbility {
  onCreate() {
    this.context.terminateSelf().then(() => {
      // Carry out normal service processing.
      console.log('terminateSelf succeed');
    }).catch((error: BusinessError) => {
      // Process service logic errors.
      console.error('terminateSelf failed, error.code: ${error.code}, error.message: ${error.message}');
    });
  }
}
```

## ServiceExtensionContext.connectServiceExtensionAbility

connectServiceExtensionAbility(want: Want, options: ConnectOptions): number;

Connects this ability to a ServiceExtensionAbility.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md)  | Yes| Want information about the target ability, such as the ability name and bundle name.|
| options | [ConnectOptions](js-apis-inner-ability-connectOptions.md) | Yes| Callback used to return the information indicating that the connection is successful, interrupted, or failed.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | A number, based on which the connection will be interrupted.|

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
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';
import rpc from '@ohos.rpc';
import common from '@ohos.app.ability.common';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

let commRemote: rpc.IRemoteObject; // Release the instance when the connection is disconnected.
class EntryAbility extends ServiceExtensionAbility {
  onCreate() {
    let want: Want = {
      bundleName: 'com.example.myapp',
      abilityName: 'MyAbility'
    };
    let options: common.ConnectOptions = {
      onConnect(elementName, remote) {
        commRemote = remote;
        console.log('----------- onConnect -----------');
      },
      onDisconnect(elementName) { console.log('----------- onDisconnect -----------') },
      onFailed(code) { console.error('----------- onFailed -----------') }
    };
    let connection: number;
    try {
      connection = this.context.connectServiceExtensionAbility(want, options);
    } catch (paramError) {
      // Process input parameter errors.
      console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');
    }
  }
}
```

## ServiceExtensionContext.connectServiceExtensionAbilityWithAccount

connectServiceExtensionAbilityWithAccount(want: Want, accountId: number, options: ConnectOptions): number;

Uses the **AbilityInfo.AbilityType.SERVICE** template and account ID to connect this ability to another ability.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getcreatedosaccountscountdeprecated).|
| options | ConnectOptions | Yes| Remote object instance.|

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
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';
import rpc from '@ohos.rpc';
import common from '@ohos.app.ability.common';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

let commRemote: rpc.IRemoteObject; // Release the instance when the connection is disconnected.
class EntryAbility extends ServiceExtensionAbility {
  onCreate() {
    let want: Want = {
      deviceId: '',
      bundleName: 'com.example.myapplication',
      abilityName: 'EntryAbility'
    };
    let accountId = 100;
    let options: common.ConnectOptions = {
      onConnect(elementName, remote) {
        commRemote = remote;
        console.log('----------- onConnect -----------');
      },
      onDisconnect(elementName) { console.log('----------- onDisconnect -----------'); },
      onFailed(code) { console.log('----------- onFailed -----------'); }
    };
    let connection: number;
    try {
      connection = this.context.connectServiceExtensionAbilityWithAccount(want, accountId, options);
    } catch (paramError) {
      // Process input parameter errors.
      console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');
    }
  }
}
```

## ServiceExtensionContext.disconnectServiceExtensionAbility

disconnectServiceExtensionAbility(connection: number, callback:AsyncCallback&lt;void&gt;): void;

Disconnects this ability from a ServiceExtensionAbility and after the successful disconnection, sets the remote object returned upon the connection to void. This API uses an asynchronous callback to return the result. 

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| connection | number | Yes| Number returned after **connectServiceExtensionAbility** is called.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000011 | The context does not exist.        |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';
import rpc from '@ohos.rpc';
import { BusinessError } from '@ohos.base';

let commRemote: rpc.IRemoteObject | null; // Release the instance when the connection is disconnected.
class EntryAbility extends ServiceExtensionAbility {
  onCreate() {
    // connection is the return value of connectServiceExtensionAbility.
    let connection = 1;
    try {
      this.context.disconnectServiceExtensionAbility(connection, (error: BusinessError) => {
        commRemote = null;
        if (error.code) {
          // Process service logic errors.
          console.error(`disconnectServiceExtensionAbility failed, error.code: ${error.code}, error.message: ${error.message}`);
          return;
        }
        // Carry out normal service processing.
        console.log('disconnectServiceExtensionAbility succeed');
      });
    } catch (paramError) {
      commRemote = null;
      // Process input parameter errors.
      console.error(`error.code: ${paramError.code}, error.message: ${paramError.message}`);
    }
  }
}
```

## ServiceExtensionContext.disconnectServiceExtensionAbility

disconnectServiceExtensionAbility(connection: number): Promise&lt;void&gt;;

Disconnects this ability from a ServiceExtensionAbility and after the successful disconnection, sets the remote object returned upon the connection to void. This API uses a promise to return the result. 

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| connection | number | Yes| Number returned after **connectServiceExtensionAbility** is called.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000011 | The context does not exist.        |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';
import rpc from '@ohos.rpc';
import { BusinessError } from '@ohos.base';

let commRemote: rpc.IRemoteObject | null; // Release the instance when the connection is disconnected.
class EntryAbility extends ServiceExtensionAbility {
  onCreate() {
    // connection is the return value of connectServiceExtensionAbility.
    let connection = 1;
    try {
      this.context.disconnectServiceExtensionAbility(connection)
        .then(() => {
          commRemote = null;
          // Carry out normal service processing.
          console.log('disconnectServiceExtensionAbility succeed');
        })
        .catch((error: BusinessError) => {
          commRemote = null;
          // Process service logic errors.
          console.error(`disconnectServiceExtensionAbility failed, error.code: ${error.code}, error.message: ${error.message}`);
        });
    } catch (paramError) {
      commRemote = null;
      // Process input parameter errors.
      console.error(`error.code: ${paramError.code}, error.message: ${paramError.message}`);
    }
  }
}
```

## ServiceExtensionContext.startAbilityByCall

startAbilityByCall(want: Want): Promise&lt;Caller&gt;;

Starts an ability in the foreground or background and obtains the caller object for communicating with the ability.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **exported** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - The rules for using this API in the same-device and cross-device scenarios are different. For details, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**Required permissions**: ohos.permission.ABILITY_BACKGROUND_COMMUNICATION

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

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
| 16000005 | Static permission denied. The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |
| 16200001 | The caller has been released.        |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

Start an ability in the background.

```ts
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';
import { Caller } from '@ohos.app.ability.UIAbility';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

class EntryAbility extends ServiceExtensionAbility {
  onCreate() {
    let caller: Caller;

    // Start an ability in the background by not passing parameters.
    let wantBackground: Want = {
      bundleName: 'com.example.myservice',
      moduleName: 'entry',
      abilityName: 'EntryAbility',
      deviceId: ''
    };

    try {
      this.context.startAbilityByCall(wantBackground)
        .then((obj: Caller) => {
          // Carry out normal service processing.
          caller = obj;
          console.log('startAbilityByCall succeed');
        }).catch((error: BusinessError) => {
        // Process service logic errors.
        console.error('startAbilityByCall failed, error.code: ${error.code}, error.message: ${error.message}');
      });
    } catch (paramError) {
      // Process input parameter errors.
      console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');
    }
  }
}
```

Start an ability in the foreground.

```ts
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';
import { Caller } from '@ohos.app.ability.UIAbility';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

class EntryAbility extends ServiceExtensionAbility {
  onCreate() {
    let caller: Caller;

    // Start an ability in the foreground with 'ohos.aafwk.param.callAbilityToForeground' in parameters set to true.
    let wantForeground: Want = {
      bundleName: 'com.example.myservice',
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
          console.log('startAbilityByCall succeed');
        }).catch((error: BusinessError) => {
        // Process service logic errors.
        console.error('startAbilityByCall failed, error.code: ${error.code}, error.message: ${error.message}');
      });
    } catch (paramError) {
      // Process input parameter errors.
      console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');
    }
  }
}
```
## ServiceExtensionContext.startRecentAbility

startRecentAbility(want: Want, callback: AsyncCallback\<void>): void;

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
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

**Example**

```ts
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

class EntryAbility extends ServiceExtensionAbility {
  onCreate() {
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
  }
}
```
## ServiceExtensionContext.startRecentAbility

startRecentAbility(want: Want, options: StartOptions, callback: AsyncCallback\<void>): void;

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
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

**Example**

```ts
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';
import Want from '@ohos.app.ability.Want';
import StartOptions from '@ohos.app.ability.StartOptions';
import { BusinessError } from '@ohos.base';

class EntryAbility extends ServiceExtensionAbility {
  onCreate() {
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
  }
}
```
## ServiceExtensionContext.startRecentAbility

startRecentAbility(want: Want, options?: StartOptions): Promise\<void>;

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
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

**Example**

```ts
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';
import Want from '@ohos.app.ability.Want';
import StartOptions from '@ohos.app.ability.StartOptions';
import { BusinessError } from '@ohos.base';

class EntryAbility extends ServiceExtensionAbility {
  onCreate() {
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
  }
}
```

## ServiceExtensionContext.startAbilityByCallWithAccount<sup>10+</sup>

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
| accountId | number | Yes| ID of a system account. The value **-1** indicates the current user. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getcreatedosaccountscountdeprecated-1).|

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
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';
import { Caller } from '@ohos.app.ability.UIAbility';
import Want from '@ohos.app.ability.Want';
import StartOptions from '@ohos.app.ability.StartOptions';
import { BusinessError } from '@ohos.base';

class EntryAbility extends ServiceExtensionAbility {
  onCreate() {
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
  }
}
```
