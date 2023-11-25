# @ohos.app.ability.appManager (appManager)

The **appManager** module implements application management. You can use the APIs of this module to query whether the application is undergoing a stability test, whether the application is running on a RAM constrained device, the memory size of the application, and information about the running process.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import appManager from '@ohos.app.ability.appManager';
```

## appManager.isRunningInStabilityTest

isRunningInStabilityTest(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether this application is undergoing a stability test. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | Yes|Callback used to return the API call result and the result **true** or **false**. You can perform error handling or custom processing in this callback. The value **true** means that the application is undergoing a stability test, and **false** means the opposite. | 

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import appManager from '@ohos.app.ability.appManager';

appManager.isRunningInStabilityTest((err, flag) => {
    if (err) {
        console.error(`isRunningInStabilityTest fail, err: ${JSON.stringify(err)}`);
    } else {
        console.log(`The result of isRunningInStabilityTest is: ${JSON.stringify(flag)}`);
    }
});  
```


## appManager.isRunningInStabilityTest

isRunningInStabilityTest(): Promise&lt;boolean&gt;

Checks whether this application is undergoing a stability test. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

  | Type| Description| 
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Promise used to return the API call result and the result **true** or **false**. You can perform error handling or custom processing in this callback. The value **true** means that the application is undergoing a stability test, and **false** means the opposite.| 

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import appManager from '@ohos.app.ability.appManager';
import { BusinessError } from '@ohos.base';

appManager.isRunningInStabilityTest().then((flag) => {
    console.log(`The result of isRunningInStabilityTest is: ${JSON.stringify(flag)}`);
}).catch((error: BusinessError) => {
    console.error(`error: ${JSON.stringify(error)}`);
});
```


## appManager.isRamConstrainedDevice

isRamConstrainedDevice(): Promise\<boolean>;

Checks whether this application is running on a RAM constrained device. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

  | Type| Description| 
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Promise used to return the API call result and the result **true** or **false**. You can perform error handling or custom processing in this callback. The value **true** means that the application is running on a RAM constrained device, and **false** means the opposite.| 

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import appManager from '@ohos.app.ability.appManager';
import { BusinessError } from '@ohos.base';

appManager.isRamConstrainedDevice().then((data) => {
    console.log(`The result of isRamConstrainedDevice is: ${JSON.stringify(data)}`);
}).catch((error: BusinessError) => {
    console.error(`error: ${JSON.stringify(error)}`);
});
```

## appManager.isRamConstrainedDevice

isRamConstrainedDevice(callback: AsyncCallback\<boolean>): void;

Checks whether this application is running on a RAM constrained device. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | Yes|Callback used to return the API call result and the result **true** or **false**. You can perform error handling or custom processing in this callback. The value **true** means that the application is running on a RAM constrained device, and **false** means the opposite. | 

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import appManager from '@ohos.app.ability.appManager';

appManager.isRamConstrainedDevice((err, data) => {
    if (err) {
        console.error(`isRamConstrainedDevice fail, err: ${JSON.stringify(err)}`);
    } else {
        console.log(`The result of isRamConstrainedDevice is: ${JSON.stringify(data)}`);
    }
});
```

## appManager.getAppMemorySize

getAppMemorySize(): Promise\<number>;

Obtains the memory size of this application. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

  | Type| Description| 
  | -------- | -------- |
  | Promise&lt;number&gt; | Promise used to return the API call result and the memory size. You can perform error handling or custom processing in this callback.| 

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import appManager from '@ohos.app.ability.appManager';
import { BusinessError} from '@ohos.base'

appManager.getAppMemorySize().then((data) => {
    console.log(`The size of app memory is: ${JSON.stringify(data)}`);
}).catch((error: BusinessError) => {
    console.error(`error: ${JSON.stringify(error)}`);
});
```

## appManager.getAppMemorySize

getAppMemorySize(callback: AsyncCallback\<number>): void;

Obtains the memory size of this application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;number&gt; | Yes|Callback used to return the API call result and the memory size. You can perform error handling or custom processing in this callback.| 

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import appManager from '@ohos.app.ability.appManager';

appManager.getAppMemorySize((err, data) => {
    if (err) {
        console.error(`getAppMemorySize fail, err: ${JSON.stringify(err)}`);
    } else {
        console.log(`The size of app memory is: ${JSON.stringify(data)}`);
    }
});
```

## appManager.getRunningProcessInformation

getRunningProcessInformation(): Promise\<Array\<ProcessInformation>>;

Obtains information about the running processes. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_RUNNING_INFO

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<Array\<[ProcessInformation](js-apis-inner-application-processInformation.md)>> | Promise used to return the API call result and the process running information. You can perform error handling or custom processing in this callback.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import appManager from '@ohos.app.ability.appManager';
import { BusinessError } from '@ohos.base';

appManager.getRunningProcessInformation().then((data) => {
    console.log(`The running process information is: ${JSON.stringify(data)}`);
}).catch((error: BusinessError) => {
    console.error(`error: ${JSON.stringify(error)}`);
});
```

## appManager.getRunningProcessInformation<sup>9+</sup>

getRunningProcessInformation(callback: AsyncCallback\<Array\<ProcessInformation>>): void;

Obtains information about the running processes. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_RUNNING_INFO

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback\<Array\<[ProcessInformation](js-apis-inner-application-processInformation.md)>>  | Yes|Callback used to return the API call result and the process running information. You can perform error handling or custom processing in this callback.| 

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import appManager from '@ohos.app.ability.appManager';

appManager.getRunningProcessInformation((err, data) => {
    if (err) {
        console.error(`getRunningProcessInformation fail, err: ${JSON.stringify(err)}`);
    } else {
        console.log(`The process running information is: ${JSON.stringify(data)}`);
    }
});
```

## appManager.isSharedBundleRunning<sup>10+</sup>

isSharedBundleRunning(bundleName: string, versionCode: number): Promise\<boolean>;

Checks whether the shared library is in use. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_RUNNING_INFO

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| bundleName    | string   | Yes   | Bundle name of the shared library.|
| versionCode   | number   | Yes   | Version number of the shared library.     |

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the shared library is in use, and **false** means the opposite.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import appManager from '@ohos.app.ability.appManager';
import { BusinessError } from '@ohos.base';

const bundleName = "this is a bundleName";
const versionCode = 1;
appManager.isSharedBundleRunning(bundleName, versionCode).then((data) => {
    console.log(`The shared bundle running is: ${JSON.stringify(data)}`);
}).catch((error: BusinessError) => {
    console.error(`error: ${JSON.stringify(error)}`);
});
```

## appManager.isSharedBundleRunning<sup>10+</sup>

isSharedBundleRunning(bundleName: string, versionCode: number, callback: AsyncCallback\<boolean>): void;

Checks whether the shared library is in use. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_RUNNING_INFO

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| bundleName    | string   | Yes   | Bundle name of the shared library.|
| versionCode   | number   | Yes   | Version number of the shared library.     |
| callback    | syncCallback\<boolean>> | Yes   | Callback used to return the result. The value **true** means that the shared library is in use, and **false** means the opposite.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import appManager from '@ohos.app.ability.appManager';

const bundleName = "this is a bundleName";
const versionCode = 1;
appManager.isSharedBundleRunning(bundleName, versionCode, (err, data) => {
    if (err) {
        console.error(`err: ${JSON.stringify(err)}`);
    } else {
        console.log(`The shared bundle running is: ${JSON.stringify(data)}`);
    }
});
```

## appManager.on

on(type: 'applicationState', observer: ApplicationStateObserver): number;

Registers an observer to listen for the state changes of all applications.

**Required permissions**: ohos.permission.RUNNING_STATE_OBSERVER

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Type of the API to call. It is fixed at **'applicationState'**.|
| observer | [ApplicationStateObserver](./js-apis-inner-application-applicationStateObserver.md) | Yes| Application state observer, which is used to observe the lifecycle change of an application.|

**Return value**

| Type| Description|
| --- | --- |
| number | Digital code of the observer, which will be used in **off()** to deregister the observer.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import appManager from '@ohos.app.ability.appManager';
import { BusinessError } from '@ohos.base';

let applicationStateObserver: appManager.ApplicationStateObserver = {
    onForegroundApplicationChanged(appStateData) {
        console.log(`[appManager] onForegroundApplicationChanged: ${JSON.stringify(appStateData)}`);
    },
    onAbilityStateChanged(abilityStateData) {
        console.log(`[appManager] onAbilityStateChanged: ${JSON.stringify(abilityStateData)}`);
    },
    onProcessCreated(processData) {
        console.log(`[appManager] onProcessCreated: ${JSON.stringify(processData)}`);
    },
    onProcessDied(processData) {
        console.log(`[appManager] onProcessDied: ${JSON.stringify(processData)}`);
    },
    onProcessStateChanged(processData) {
        console.log(`[appManager] onProcessStateChanged: ${JSON.stringify(processData)}`);
    }
};
try {
    const observerId = appManager.on('applicationState', applicationStateObserver);
    console.log(`[appManager] observerCode: ${observerId}`);
} catch (paramError) {
    let code = (paramError as BusinessError).code;
    let message = (paramError as BusinessError).message;
    console.error(`[appManager] error: ${code}, ${message} `);
}
```

## appManager.on

on(type: 'applicationState', observer: ApplicationStateObserver, bundleNameList: Array\<string>): number;

Registers an observer to listen for the state changes of a specified application.

**Required permissions**: ohos.permission.RUNNING_STATE_OBSERVER

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Type of the API to call. It is fixed at **'applicationState'**.|
| observer | [ApplicationStateObserver](./js-apis-inner-application-applicationStateObserver.md) | Yes| Application state observer, which is used to observe the lifecycle change of an application.|
| bundleNameList | `Array<string>` | Yes| **bundleName** array of the application. A maximum of 128 bundle names can be passed.|

**Return value**

| Type| Description|
| --- | --- |
| number | Digital code of the observer, which will be used in **off()** to deregister the observer.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import appManager from '@ohos.app.ability.appManager';
import { BusinessError } from '@ohos.base';

let applicationStateObserver: appManager.ApplicationStateObserver = {
    onForegroundApplicationChanged(appStateData) {
        console.log(`[appManager] onForegroundApplicationChanged: ${JSON.stringify(appStateData)}`);
    },
    onAbilityStateChanged(abilityStateData) {
        console.log(`[appManager] onAbilityStateChanged: ${JSON.stringify(abilityStateData)}`);
    },
    onProcessCreated(processData) {
        console.log(`[appManager] onProcessCreated: ${JSON.stringify(processData)}`);
    },
    onProcessDied(processData) {
        console.log(`[appManager] onProcessDied: ${JSON.stringify(processData)}`);
    },
    onProcessStateChanged(processData) {
        console.log(`[appManager] onProcessStateChanged: ${JSON.stringify(processData)}`);
    }
};
let bundleNameList = ['bundleName1', 'bundleName2'];
try {
    const observerId = appManager.on('applicationState', applicationStateObserver, bundleNameList);
    console.log(`[appManager] observerCode: ${observerId}`);
} catch (paramError) {
    let code = (paramError as BusinessError).code;
    let message = (paramError as BusinessError).message;
    console.error(`[appManager] error: ${code}, ${message} `);
}
```

## appManager.off

off(type: 'applicationState', observerId: number,  callback: AsyncCallback\<void>): void;

Deregisters the application state observer. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.RUNNING_STATE_OBSERVER

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Type of the API to call. It is fixed at **'applicationState'**.|
| observerId | number | Yes| Digital code of the observer.|
| callback | AsyncCallback\<void> | Yes| Callback used to return the API call result. You can perform error handling or custom processing in this callback.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import appManager from '@ohos.app.ability.appManager';
import { BusinessError } from '@ohos.base';

let observerId = 0;

// 1. Register an application state observer.
let applicationStateObserver: appManager.ApplicationStateObserver = {
    onForegroundApplicationChanged(appStateData) {
        console.log(`[appManager] onForegroundApplicationChanged: ${JSON.stringify(appStateData)}`);
    },
    onAbilityStateChanged(abilityStateData) {
        console.log(`[appManager] onAbilityStateChanged: ${JSON.stringify(abilityStateData)}`);
    },
    onProcessCreated(processData) {
        console.log(`[appManager] onProcessCreated: ${JSON.stringify(processData)}`);
    },
    onProcessDied(processData) {
        console.log(`[appManager] onProcessDied: ${JSON.stringify(processData)}`);
    },
    onProcessStateChanged(processData) {
        console.log(`[appManager] onProcessStateChanged: ${JSON.stringify(processData)}`);
    }
};
let bundleNameList = ['bundleName1', 'bundleName2'];
try {
    observerId = appManager.on('applicationState', applicationStateObserver, bundleNameList);
    console.log(`[appManager] observerCode: ${observerId}`);
} catch (paramError) {
    let code = (paramError as BusinessError).code;
    let message = (paramError as BusinessError).message;
    console.error(`[appManager] error: ${code}, ${message} `);
}

// 2. Deregister the application state observer.
function unregisterApplicationStateObserverCallback(err: BusinessError) {
    if (err) {
        console.error(`unregisterApplicationStateObserverCallback fail, err: ${JSON.stringify(err)}`);
    } else {
        console.log('unregisterApplicationStateObserverCallback success.');
    }
}
try {
    appManager.off('applicationState', observerId, unregisterApplicationStateObserverCallback);
} catch (paramError) {
    let code = (paramError as BusinessError).code;
    let message = (paramError as BusinessError).message;
    console.error(`[appManager] error: ${code}, ${message} `);
}
```

## appManager.off

off(type: 'applicationState', observerId: number): Promise\<void>;

Deregisters the application state observer. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.RUNNING_STATE_OBSERVER

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Type of the API to call. It is fixed at **'applicationState'**.|
| observerId | number | Yes| Digital code of the observer.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<void> | Promise used to return the API call result. You can perform error handling or custom processing in this callback.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import appManager from '@ohos.app.ability.appManager';
import { BusinessError } from '@ohos.base';

let observerId = 0;

// 1. Register an application state observer.
let applicationStateObserver: appManager.ApplicationStateObserver = {
    onForegroundApplicationChanged(appStateData) {
        console.log(`[appManager] onForegroundApplicationChanged: ${JSON.stringify(appStateData)}`);
    },
    onAbilityStateChanged(abilityStateData) {
        console.log(`[appManager] onAbilityStateChanged: ${JSON.stringify(abilityStateData)}`);
    },
    onProcessCreated(processData) {
        console.log(`[appManager] onProcessCreated: ${JSON.stringify(processData)}`);
    },
    onProcessDied(processData) {
        console.log(`[appManager] onProcessDied: ${JSON.stringify(processData)}`);
    },
    onProcessStateChanged(processData) {
        console.log(`[appManager] onProcessStateChanged: ${JSON.stringify(processData)}`);
    }
};
let bundleNameList = ['bundleName1', 'bundleName2'];
try {
    observerId = appManager.on('applicationState', applicationStateObserver, bundleNameList);
} catch (paramError) {
    let code = (paramError as BusinessError).code;
    let message = (paramError as BusinessError).message;
    console.error(`[appManager] error: ${code}, ${message} `);
}
    
// 2. Deregister the application state observer.
try {
    appManager.off('applicationState', observerId).then((data) => {
        console.log(`unregisterApplicationStateObserver success, data: ${JSON.stringify(data)}`);
    }).catch((err: BusinessError) => {
        console.error(`unregisterApplicationStateObserver fail, err: ${JSON.stringify(err)}`);
    });
} catch (paramError) {
    let code = (paramError as BusinessError).code;
    let message = (paramError as BusinessError).message;
    console.error(`[appManager] error: ${code}, ${message} `);
}
```

## appManager.getForegroundApplications

getForegroundApplications(callback: AsyncCallback\<Array\<AppStateData>>): void;

Obtains applications that are running in the foreground. This API uses an asynchronous callback to return the result. The application information is defined by [AppStateData](js-apis-inner-application-appStateData.md).

**Required permissions**: ohos.permission.GET_RUNNING_INFO

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback\<Array\<[AppStateData](js-apis-inner-application-appStateData.md)>> | Yes| Callback used to return the API call result and an array holding the application state data. You can perform error handling or custom processing in this callback.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import appManager from '@ohos.app.ability.appManager';
import { BusinessError } from '@ohos.base';

function getForegroundApplicationsCallback(err: BusinessError, data: Array<appManager.AppStateData>) {
    if (err) {
        console.error(`getForegroundApplicationsCallback fail, err: ${JSON.stringify(err)}`);
    } else {
        console.log(`getForegroundApplicationsCallback success, data: ${JSON.stringify(data)}`);
    }
}
try {
    appManager.getForegroundApplications(getForegroundApplicationsCallback);
} catch (paramError) {
    let code = (paramError as BusinessError).code;
    let message = (paramError as BusinessError).message;
    console.error(`[appManager] error: ${code}, ${message} `);
}
```

## appManager.getForegroundApplications

getForegroundApplications(): Promise\<Array\<AppStateData>>;

Obtains applications that are running in the foreground. This API uses a promise to return the result. The application information is defined by [AppStateData](js-apis-inner-application-appStateData.md).

**Required permissions**: ohos.permission.GET_RUNNING_INFO

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<Array\<[AppStateData](js-apis-inner-application-appStateData.md)>> | Promise used to return an array holding the application state data.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import appManager from '@ohos.app.ability.appManager';
import { BusinessError } from '@ohos.base';

appManager.getForegroundApplications().then((data) => {
    console.log(`getForegroundApplications success, data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getForegroundApplications fail, err: ${JSON.stringify(err)}`);
});
```

## appManager.killProcessWithAccount

killProcessWithAccount(bundleName: string, accountId: number): Promise\<void\>

Kills a process by bundle name and account ID. This API uses a promise to return the result.

> **NOTE**
>
> The **ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS** permission is not required when **accountId** specifies the current user.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS and ohos.permission.CLEAN_BACKGROUND_PROCESSES

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| bundleName | string | Yes| Bundle name.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess).|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import appManager from '@ohos.app.ability.appManager';
import { BusinessError } from '@ohos.base';

let bundleName = 'bundleName';
let accountId = 0;
try {
    appManager.killProcessWithAccount(bundleName, accountId).then(() => {
        console.log('killProcessWithAccount success');
    }).catch((err: BusinessError) => {
        console.error(`killProcessWithAccount fail, err: ${JSON.stringify(err)}`);
    });
} catch (paramError) {
    let code = (paramError as BusinessError).code;
    let message = (paramError as BusinessError).message;
    console.error(`[appManager] error: ${code}, ${message} `);
}
```


## appManager.killProcessWithAccount

killProcessWithAccount(bundleName: string, accountId: number, callback: AsyncCallback\<void\>): void

Kills a process by bundle name and account ID. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> The **ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS** permission is not required when **accountId** specifies the current user.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS and ohos.permission.CLEAN_BACKGROUND_PROCESSES

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | bundleName | string | Yes| Bundle name.| 
  | accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess).| 
  | callback | AsyncCallback\<void\> | Yes| Callback used to return the API call result. You can perform error handling or custom processing in this callback.| 

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import appManager from '@ohos.app.ability.appManager';
import { BusinessError } from '@ohos.base';

let bundleName = 'bundleName';
let accountId = 0;
function killProcessWithAccountCallback(err: BusinessError) {
    if (err) {
        console.error(`killProcessWithAccountCallback fail, err: ${JSON.stringify(err)}`);
    } else {
        console.log('killProcessWithAccountCallback success.');
    }
}
appManager.killProcessWithAccount(bundleName, accountId, killProcessWithAccountCallback);
```

## appManager.killProcessesByBundleName

killProcessesByBundleName(bundleName: string, callback: AsyncCallback\<void>);

Kills a process by bundle name. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CLEAN_BACKGROUND_PROCESSES

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| bundleName | string | Yes| Bundle name.|
| callback | AsyncCallback\<void> | Yes| Callback used to return the API call result. You can perform error handling or custom processing in this callback.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import appManager from '@ohos.app.ability.appManager';
import { BusinessError } from '@ohos.base';

let bundleName = 'bundleName';
function killProcessesByBundleNameCallback(err: BusinessError) {
    if (err) {
        console.error(`killProcessesByBundleNameCallback fail, err: ${JSON.stringify(err)}`);
    } else {
        console.log('killProcessesByBundleNameCallback success.');
    }
}
try {
    appManager.killProcessesByBundleName(bundleName, killProcessesByBundleNameCallback);
} catch (paramError) {
    let code = (paramError as BusinessError).code;
    let message = (paramError as BusinessError).message;
    console.error(`[appManager] error: ${code}, ${message} `);
}
```

## appManager.killProcessesByBundleName

killProcessesByBundleName(bundleName: string): Promise\<void>;

Kills a process by bundle name. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CLEAN_BACKGROUND_PROCESSES

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| bundleName | string | Yes| Bundle name.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import appManager from '@ohos.app.ability.appManager';
import { BusinessError } from '@ohos.base';

let bundleName = 'bundleName';
try {
    appManager.killProcessesByBundleName(bundleName).then((data) => {
        console.log('killProcessesByBundleName success.');
    }).catch((err: BusinessError) => {
        console.error(`killProcessesByBundleName fail, err: ${JSON.stringify(err)}`);
    });
} catch (paramError) {
    let code = (paramError as BusinessError).code;
    let message = (paramError as BusinessError).message;
    console.error(`[appManager] error: ${code}, ${message} `);
}
```

## appManager.clearUpApplicationData

clearUpApplicationData(bundleName: string, callback: AsyncCallback\<void>);

Clears application data by bundle name. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CLEAN_APPLICATION_DATA

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| bundleName | string | Yes| Bundle name.|
| callback | AsyncCallback\<void> | Yes| Callback used to return the API call result. You can perform error handling or custom processing in this callback.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import appManager from '@ohos.app.ability.appManager';
import { BusinessError } from '@ohos.base';

let bundleName = 'bundleName';
function clearUpApplicationDataCallback(err: BusinessError) {
    if (err) {
        console.error(`clearUpApplicationDataCallback fail, err: ${JSON.stringify(err)}`);
    } else {
        console.log('clearUpApplicationDataCallback success.');
    }
}
try {
    appManager.clearUpApplicationData(bundleName, clearUpApplicationDataCallback);
} catch (paramError) {
    let code = (paramError as BusinessError).code;
    let message = (paramError as BusinessError).message;
    console.error(`[appManager] error: ${code}, ${message} `);
}
```

## appManager.clearUpApplicationData

clearUpApplicationData(bundleName: string): Promise\<void>;

Clears application data by bundle name. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CLEAN_APPLICATION_DATA

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| bundleName | string | Yes| Bundle name.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<void> | Promise used to return the API call result. You can perform error handling or custom processing in this callback.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import appManager from '@ohos.app.ability.appManager';
import { BusinessError } from '@ohos.base';

let bundleName = 'bundleName';
try {
    appManager.clearUpApplicationData(bundleName).then((data) => {
        console.log('clearUpApplicationData success.');
    }).catch((err: BusinessError) => {
        console.error(`clearUpApplicationData fail, err: ${JSON.stringify(err)}`);
    });
} catch (paramError) {
    let code = (paramError as BusinessError).code;
    let message = (paramError as BusinessError).message;
    console.error(`[appManager] error: ${code}, ${message} `);
}
```

## appManager.getProcessMemoryByPid<sup>10+</sup>

getProcessMemoryByPid(pid: number, callback: AsyncCallback\<number>): void;

Obtains the memory size of a process. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| pid | number | Yes| Process ID. For details, see [getRunningProcessInfoByBundleName](js-apis-app-ability-appManager.md#appmanagergetrunningprocessinfobybundlename10).|
| callback | AsyncCallback\<number> | Yes| Callback used to return the API call result and the memory size (in KB). You can perform error handling or custom processing in this callback.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import appManager from '@ohos.app.ability.appManager';
import { BusinessError } from '@ohos.base';

let pid = 0;
function getProcessMemoryByPidCallback(err: BusinessError, data: number) {
    if (err) {
        console.error(`getProcessMemoryByPidCallback fail, err: ${JSON.stringify(err)}`);
    } else {
        console.log('getProcessMemoryByPidCallback success.');
    }
}
try {
    appManager.getProcessMemoryByPid(pid, getProcessMemoryByPidCallback);
} catch (paramError) {
    let code = (paramError as BusinessError).code;
    let message = (paramError as BusinessError).message;
    console.error(`[appManager] error: ${code}, ${message} `);
}
```

## appManager.getProcessMemoryByPid<sup>10+</sup>

getProcessMemoryByPid(pid: number): Promise\<number>;

Obtains the memory size of a process. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| pid | number | Yes| Process ID. For details, see [getRunningProcessInfoByBundleName](js-apis-app-ability-appManager.md#appmanagergetrunningprocessinfobybundlename10). |

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<number> | Promise used to return the API call result and the memory size (in KB). You can perform error handling or custom processing in this callback.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import appManager from '@ohos.app.ability.appManager';
import { BusinessError } from '@ohos.base';

let pid = 0;
try {
    appManager.getProcessMemoryByPid(pid).then((data) => {
        console.log('getProcessMemoryByPid success.');
    }).catch((err: BusinessError) => {
        console.error(`getProcessMemoryByPid fail, err: ${JSON.stringify(err)}`);
    });
} catch (paramError) {
    let code = (paramError as BusinessError).code;
    let message = (paramError as BusinessError).message;
    console.error(`[appManager] error: ${code}, ${message} `);
}
```

## appManager.getRunningProcessInfoByBundleName<sup>10+</sup>

getRunningProcessInfoByBundleName(bundleName: string, callback: AsyncCallback\<Array\<ProcessInformation>>): void;

Obtains information about the running processes by bundle name. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| bundleName | string | Yes| Bundle name.|
| callback | AsyncCallback\<Array\<[ProcessInformation](js-apis-inner-application-processInformation.md)>> | Yes| Callback used to return the API call result and the process running information. You can perform error handling or custom processing in this callback.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import appManager from '@ohos.app.ability.appManager';
import { BusinessError } from '@ohos.base';

let bundleName = "bundleName";
function getRunningProcessInfoByBundleNameCallback(err: BusinessError, data: Array<appManager.ProcessInformation>) {
    if (err) {
        console.error(`getRunningProcessInfoByBundleNameCallback fail, err: ${JSON.stringify(err)}`);
    } else {
        console.log('getRunningProcessInfoByBundleNameCallback success.');
    }
}
try {
    appManager.getRunningProcessInfoByBundleName(bundleName, getRunningProcessInfoByBundleNameCallback);
} catch (paramError) {
    let code = (paramError as BusinessError).code;
    let message = (paramError as BusinessError).message;
    console.error(`[appManager] error: ${code}, ${message} `);
}
```

## appManager.getRunningProcessInfoByBundleName<sup>10+</sup>

getRunningProcessInfoByBundleName(bundleName: string): Promise\<Array\<ProcessInformation>>;

Obtains information about the running processes by bundle name. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| bundleName | string | Yes| Bundle name.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<Array\<[ProcessInformation](js-apis-inner-application-processInformation.md)>> | Promise used to return the API call result and the process running information. You can perform error handling or custom processing in this callback.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import appManager from '@ohos.app.ability.appManager';
import { BusinessError } from '@ohos.base';

let bundleName = "bundleName";
try {
    appManager.getRunningProcessInfoByBundleName(bundleName).then((data) => {
        console.log('getRunningProcessInfoByBundleName success.');
    }).catch((err: BusinessError) => {
        console.error(`getRunningProcessInfoByBundleName fail, err: ${JSON.stringify(err)}`);
    });
} catch (paramError) {
    let code = (paramError as BusinessError).code;
    let message = (paramError as BusinessError).message;
    console.error(`[appManager] error: ${code}, ${message} `);
}
```

## appManager.getRunningProcessInfoByBundleName<sup>10+</sup>

getRunningProcessInfoByBundleName(bundleName: string, userId: number, callback: AsyncCallback\<Array\<ProcessInformation>>): void;

Obtains information about the running processes by bundle name and user ID. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| bundleName | string | Yes| Bundle name.|
| userId | number | Yes| User ID.|
| callback | AsyncCallback\<Array\<[ProcessInformation](js-apis-inner-application-processInformation.md)>> | Yes| Callback used to return the API call result and the process running information. You can perform error handling or custom processing in this callback.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import appManager from '@ohos.app.ability.appManager';
import { BusinessError } from '@ohos.base';

let bundleName = "bundleName";
let userId = 0;
function getRunningProcessInfoByBundleNameCallback(err: BusinessError, data: Array<appManager.ProcessInformation>) {
    if (err) {
        console.error(`getRunningProcessInfoByBundleNameCallback fail, err: ${JSON.stringify(err)}`);
    } else {
        console.log('getRunningProcessInfoByBundleNameCallback success.');
    }
}
try {
    appManager.getRunningProcessInfoByBundleName(bundleName, userId, getRunningProcessInfoByBundleNameCallback);
} catch (paramError) {
    let code = (paramError as BusinessError).code;
    let message = (paramError as BusinessError).message;
    console.error(`[appManager] error: ${code}, ${message} `);
}
```

## appManager.getRunningProcessInfoByBundleName<sup>10+</sup>

getRunningProcessInfoByBundleName(bundleName: string, userId: number): Promise\<Array\<ProcessInformation>>;

Obtains information about the running processes by bundle name and user ID. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| bundleName | string | Yes| Bundle name.|
| userId | number | Yes| User ID.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<Array\<[ProcessInformation](js-apis-inner-application-processInformation.md)>> | Promise used to return the API call result and the process running information. You can perform error handling or custom processing in this callback.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import appManager from '@ohos.app.ability.appManager';
import { BusinessError } from '@ohos.base';

let bundleName = "bundleName";
let userId = 0;
try {
    appManager.getRunningProcessInfoByBundleName(bundleName, userId).then((data) => {
        console.log('getRunningProcessInfoByBundleName success.');
    }).catch((err: BusinessError) => {
        console.error(`getRunningProcessInfoByBundleName fail, err: ${JSON.stringify(err)}`);
    });
} catch (paramError) {
    let code = (paramError as BusinessError).code;
    let message = (paramError as BusinessError).message;
    console.error(`[appManager] error: ${code}, ${message} `);
}
```

## ApplicationState

Enumerates the application states. This enum can be used together with [AbilityStateData](js-apis-inner-application-appStateData.md) to return the application state.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

| Name                | Value | Description                              |
| -------------------- | --- | --------------------------------- |
| STATE_CREATE    | 1   |   State indicating that the application is being created.        |
| STATE_FOREGROUND          | 2   |      State indicating that the application is running in the foreground.           |
| STATE_ACTIVE  | 3   |         State indicating that the application is active.    |
| STATE_BACKGROUND        | 4   |       State indicating that the application is running in the background.          |
| STATE_DESTROY        | 5   |           State indicating that the application is destroyed.      |

## ProcessState<sup>10+</sup>

Enumerates the process states. This enum can be used together with [ProcessData](js-apis-inner-application-processData.md) to return the process state.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                | Value | Description                              |
| -------------------- | --- | --------------------------------- |
| STATE_CREATE    | 0   |      State indicating that the process is being created.      |
| STATE_FOREGROUND          | 1   |            State indicating that the process is running in the foreground.     |
| STATE_ACTIVE  | 2   |          State indicating that the process is active.  |
| STATE_BACKGROUND        | 3   |       State indicating that the process is running in the background.          |
| STATE_DESTROY        | 4   |         State indicating that the process is destroyed.        |
