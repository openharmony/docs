# @ohos.application.appManager (appManager) (System API)

The **appManager** module implements application management. You can use the APIs of this module to query whether the application is undergoing a stability test, whether the application is running on a RAM constrained device, the memory size of the application, and information about the running process.

> **NOTE**
> 
> The APIs of this module are supported since API version 8 and deprecated since API version 9. You are advised to use [@ohos.app.ability.appManager](js-apis-app-ability-appManager.md) instead. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.application.appManager (appManager)](js-apis-app-ability-wantConstant.md).

## Modules to Import

```ts
import appManager from '@ohos.application.appManager';
```

## appManager.registerApplicationStateObserver

registerApplicationStateObserver(observer: ApplicationStateObserver): number

Registers an observer to listen for the state changes of all applications.

**Required permissions**: ohos.permission.RUNNING_STATE_OBSERVER

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| observer | [ApplicationStateObserver (System API)](js-apis-inner-application-applicationStateObserver-sys.md)| Yes| Application state observer, which is used to observe the lifecycle change of an application.|

**Return value**

| Type| Description|
| --- | --- |
| number | Digital code of the observer.|

**Example**
    
  ```ts
  import appManager from '@ohos.application.appManager';

  const observerCode = appManager.registerApplicationStateObserver({
    onForegroundApplicationChanged(appStateData) {
        console.log('------------ onForegroundApplicationChanged -----------', appStateData);
    },
    onAbilityStateChanged(abilityStateData) {
        console.log('------------ onAbilityStateChanged -----------', abilityStateData);
    },
    onProcessCreated(processData) {
        console.log('------------ onProcessCreated -----------', processData);
    },
    onProcessDied(processData) {
        console.log('------------ onProcessDied -----------', processData);
    },
    onProcessStateChanged(processData) {
        console.log('------------ onProcessStateChanged -----------', processData);
    }
  });
  console.log('-------- observerCode: ---------', observerCode);
  ```

## appManager.unregisterApplicationStateObserver

unregisterApplicationStateObserver(observerId: number,  callback: AsyncCallback\<void>): void

Deregisters the application state observer. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.RUNNING_STATE_OBSERVER

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| observerId | number | Yes| Numeric code of the observer.|
| callback | AsyncCallback\<void> | Yes| Callback used to return the result.|

**Example**
    
  ```ts
  import appManager from '@ohos.application.appManager';
  import { BusinessError } from '@ohos.base';

  let observerId = 100;

  function unregisterApplicationStateObserverCallback(err: BusinessError) {
    if (err) {
        console.error('------------ unregisterApplicationStateObserverCallback ------------', err);
    }
  }
  appManager.unregisterApplicationStateObserver(observerId, unregisterApplicationStateObserverCallback);
  ```

## appManager.unregisterApplicationStateObserver

unregisterApplicationStateObserver(observerId: number): Promise\<void>

Deregisters the application state observer. This API uses a promise to return the result.

**Required permissions**: ohos.permission.RUNNING_STATE_OBSERVER

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| observerId | number | Yes| Numeric code of the observer.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<void> | Promise that returns no value.|

**Example**
    
  ```ts
  import appManager from '@ohos.application.appManager';
  import { BusinessError } from '@ohos.base';

  let observerId = 100;

  appManager.unregisterApplicationStateObserver(observerId)
  .then((data) => {
      console.log('----------- unregisterApplicationStateObserver success ----------', data);
  })
  .catch((err: BusinessError) => {
      console.error('----------- unregisterApplicationStateObserver fail ----------', err);
  });
  ```

## appManager.getForegroundApplications

getForegroundApplications(callback: AsyncCallback\<Array\<AppStateData>>): void

Obtains information about the applications that are running in the foreground. The application information is defined by [AppStateData](js-apis-inner-application-appStateData-sys.md). This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_RUNNING_INFO

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback\<Array\<[AppStateData](js-apis-inner-application-appStateData-sys.md)>> | Yes| Callback used to return the application information.|

**Example**
    
  ```ts
  import appManager from '@ohos.application.appManager';

  appManager.getForegroundApplications((err, data) => {
    if (err) {
        console.error('--------- getForegroundApplicationsCallback fail ---------', err);
    } else {
        console.log('--------- getForegroundApplicationsCallback success ---------', data);
    }
  });
  ```

## appManager.getForegroundApplications

getForegroundApplications(): Promise\<Array\<AppStateData>>

Obtains information about the applications that are running in the foreground. The application information is defined by [AppStateData](js-apis-inner-application-appStateData-sys.md). This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_RUNNING_INFO

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<Array\<[AppStateData](js-apis-inner-application-appStateData-sys.md)>> | Promise used to return the application information.|

**Example**
    
  ```ts
  import appManager from '@ohos.application.appManager';
  import { BusinessError } from '@ohos.base';

  appManager.getForegroundApplications()
  .then((data) => {
      console.log('--------- getForegroundApplications success -------', data);
  })
  .catch((err: BusinessError) => {
      console.error('--------- getForegroundApplications fail -------', err);
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

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| bundleName | string | Yes| Bundle name.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalidfromprocess).|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<void> | Promise that returns no value.|

**Example**

```ts
import appManager from '@ohos.application.appManager';
import { BusinessError } from '@ohos.base';

let bundleName = 'bundleName';
let accountId = 0;
appManager.killProcessWithAccount(bundleName, accountId)
   .then((data) => {
       console.log('------------ killProcessWithAccount success ------------', data);
   })
   .catch((err: BusinessError) => {
       console.error('------------ killProcessWithAccount fail ------------', err);
   });
```


## appManager.killProcessWithAccount

killProcessWithAccount(bundleName: string, accountId: number, callback: AsyncCallback\<void\>): void

Kills a process by bundle name and account ID. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> The **ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS** permission is not required when **accountId** specifies the current user.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS and ohos.permission.CLEAN_BACKGROUND_PROCESSES

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| bundleName | string | Yes| Bundle name.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalidfromprocess).|
| callback | AsyncCallback\<void\> | Yes| Callback used to return the result. If the process is killed, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import appManager from '@ohos.application.appManager';
import { BusinessError } from '@ohos.base';

let bundleName = 'bundleName';
let accountId = 0;
function killProcessWithAccountCallback(err: BusinessError, data: void) {
   if (err) {
       console.error('------------- killProcessWithAccountCallback fail, err: --------------', err);
   } else {
       console.log('------------- killProcessWithAccountCallback success, data: --------------', data);
   }
}
appManager.killProcessWithAccount(bundleName, accountId, killProcessWithAccountCallback);
```

## appManager.killProcessesByBundleName

killProcessesByBundleName(bundleName: string, callback: AsyncCallback\<void>)

Kills a process by bundle name. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CLEAN_BACKGROUND_PROCESSES

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| bundleName | string | Yes| Bundle name.|
| callback | AsyncCallback\<void> | Yes| Callback used to return the result. If the process is killed, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**
    
  ```ts
  import appManager from '@ohos.application.appManager';
import { BusinessError } from '@ohos.base';

  let bundleName = 'bundleName';
  function killProcessesByBundleNameCallback(err: BusinessError, data: void) {
    if (err) {
        console.error('------------- killProcessesByBundleNameCallback fail, err: --------------', err);
    } else {
        console.log('------------- killProcessesByBundleNameCallback success, data: --------------', data);
    }
  }
  appManager.killProcessesByBundleName(bundleName, killProcessesByBundleNameCallback);
  ```

## appManager.killProcessesByBundleName

killProcessesByBundleName(bundleName: string): Promise\<void>

Kills a process by bundle name. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CLEAN_BACKGROUND_PROCESSES

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| bundleName | string | Yes| Bundle name.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<void> | Promise that returns no value.|

**Example**

  ```ts
  import appManager from '@ohos.application.appManager';
  import { BusinessError } from '@ohos.base';

  let bundleName = 'com.example.myapplication';
  appManager.killProcessesByBundleName(bundleName)
    .then((data) => {
        console.log('------------ killProcessesByBundleName success ------------', data);
    })
    .catch((err: BusinessError) => {
        console.error('------------ killProcessesByBundleName fail ------------', err);
    });
  ```

## appManager.clearUpApplicationData

clearUpApplicationData(bundleName: string, callback: AsyncCallback\<void>)

Clears application data by bundle name. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CLEAN_APPLICATION_DATA

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| bundleName | string | Yes| Bundle name.|
| callback | AsyncCallback\<void> | Yes| Callback used to return the result. If the application data is cleared, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**
    
  ```ts
  import appManager from '@ohos.application.appManager';
  import { BusinessError } from '@ohos.base';

  let bundleName = 'bundleName';
  function clearUpApplicationDataCallback(err: BusinessError, data: void) {
    if (err) {
        console.error('------------- clearUpApplicationDataCallback fail, err: --------------', err);
    } else {
        console.log('------------- clearUpApplicationDataCallback success, data: --------------', data);
    }
  }
  appManager.clearUpApplicationData(bundleName, clearUpApplicationDataCallback);
  ```

## appManager.clearUpApplicationData

clearUpApplicationData(bundleName: string): Promise\<void>

Clears application data by bundle name. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CLEAN_APPLICATION_DATA

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| bundleName | string | Yes| Bundle name.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<void> | Promise that returns no value.|

**Example**
    
  ```ts
  import appManager from '@ohos.application.appManager';
  import { BusinessError } from '@ohos.base';

  let bundleName = 'bundleName';
  appManager.clearUpApplicationData(bundleName)
    .then((data) => {
        console.log('------------ clearUpApplicationData success ------------', data);
    })
    .catch((err: BusinessError) => {
        console.error('------------ clearUpApplicationData fail ------------', err);
    });
  ```
