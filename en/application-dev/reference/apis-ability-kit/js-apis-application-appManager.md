# @ohos.application.appManager (appManager)

The **appManager** module implements application management. You can use the APIs of this module to query whether the application is undergoing a stability test, whether the application is running on a RAM constrained device, the memory size of the application, and information about the running process.

> **NOTE**
> 
> The APIs of this module are supported since API version 8 and deprecated since API version 9. You are advised to use [@ohos.app.ability.appManager](js-apis-app-ability-appManager.md) instead. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import appManager from '@ohos.application.appManager';
```

## appManager.isRunningInStabilityTest

isRunningInStabilityTest(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether this application is undergoing a stability test. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. The value **true** means that the application is undergoing a stability test, and **false** means the opposite.| 

**Example**
    
  ```ts
  import appManager from '@ohos.application.appManager';

  appManager.isRunningInStabilityTest((error, flag) => {
    if (error && error.code !== 0) {
        console.error(`isRunningInStabilityTest fail, error: ${JSON.stringify(error)}`);
    } else {
        console.log(`isRunningInStabilityTest success, the result is: ${JSON.stringify(flag)}`);
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
  | Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means that the application is undergoing a stability test, and **false** means the opposite.| 

**Example**
    
  ```ts
  import appManager from '@ohos.application.appManager';
  import { BusinessError } from '@ohos.base';

  appManager.isRunningInStabilityTest().then((flag) => {
      console.log(`The result of isRunningInStabilityTest is: ${JSON.stringify(flag)}`);
  }).catch((error: BusinessError) => {
      console.error(`error: ${JSON.stringify(error)}`);
  });
  ```


## appManager.isRamConstrainedDevice<sup>7+<sup>

isRamConstrainedDevice(): Promise\<boolean>

Checks whether this application is running on a RAM constrained device. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

  | Type| Description| 
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means that the application is running on a RAM constrained device, and **false** means the opposite.| 

**Example**
    
  ```ts
  import appManager from '@ohos.application.appManager';
  import { BusinessError } from '@ohos.base';

  appManager.isRamConstrainedDevice().then((data) => {
      console.log(`The result of isRamConstrainedDevice is: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
      console.error(`error: ${JSON.stringify(error)}`);
  });
  ```

## appManager.isRamConstrainedDevice<sup>7+<sup>

isRamConstrainedDevice(callback: AsyncCallback\<boolean>): void

Checks whether this application is running on a RAM constrained device. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. The value **true** means that the application is running on a RAM constrained device, and **false** means the opposite.| 

**Example**
    
  ```ts
  import appManager from '@ohos.application.appManager';

  appManager.isRamConstrainedDevice((error, data) => {
      if (error && error.code !== 0) {
          console.error(`isRamConstrainedDevice fail, error: ${JSON.stringify(error)}`);
      } else {
          console.log(`The result of isRamConstrainedDevice is: ${JSON.stringify(data)}`);
      }
  });
  ```

## appManager.getAppMemorySize<sup>7+<sup>

getAppMemorySize(): Promise\<number>

Obtains the memory size of this application. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

  | Type| Description| 
  | -------- | -------- |
  | Promise&lt;number&gt; | Promise used to return the memory size, in MB. You can perform error processing or other custom processing based on the size.  | 

**Example**
    
  ```ts
  import appManager from '@ohos.application.appManager';
  import { BusinessError } from '@ohos.base';

  appManager.getAppMemorySize().then((data) => {
      console.log(`The size of app memory is: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
      console.error(`error: ${JSON.stringify(error)}`);
  });
  ```

## appManager.getAppMemorySize<sup>7+<sup>

getAppMemorySize(callback: AsyncCallback\<number>): void

Obtains the memory size of this application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the memory size, in MB. You can perform error processing or other custom processing based on the size.  | 

**Example**
    
  ```ts
  import appManager from '@ohos.application.appManager';

  appManager.getAppMemorySize((error, data) => {
      if (error && error.code !== 0) {
          console.error(`getAppMemorySize fail, error: ${JSON.stringify(error)}`);
      } else {
          console.log(`The size of app memory is: ${JSON.stringify(data)}`);
      }
  });
  ```
## appManager.getProcessRunningInfos<sup>(deprecated)</sup>

getProcessRunningInfos(): Promise\<Array\<ProcessRunningInfo>>

Obtains information about the running processes. This API uses a promise to return the result.

> This API is deprecated since API version 9. You are advised to use [appManager.getRunningProcessInformation](js-apis-app-ability-appManager.md#appmanagergetrunningprocessinformation) instead.

**Required permissions**: ohos.permission.GET_RUNNING_INFO (available only for system applications)

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<Array\<[ProcessRunningInfo](js-apis-inner-application-processRunningInfo.md)>> | Promise used to return the information about the running processes.|

**Example**
    
  ```ts
  import appManager from '@ohos.application.appManager';
  import { BusinessError } from '@ohos.base';

  appManager.getProcessRunningInfos().then((data) => {
      console.log(`The process running infos is: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
      console.error(`error: ${JSON.stringify(error)}`);
  });
  ```

## appManager.getProcessRunningInfos<sup>(deprecated)</sup>

getProcessRunningInfos(callback: AsyncCallback\<Array\<ProcessRunningInfo>>): void

Obtains information about the running processes. This API uses an asynchronous callback to return the result.

> This API is deprecated since API version 9. You are advised to use [appManager.getRunningProcessInformation](js-apis-app-ability-appManager.md#appmanagergetrunningprocessinformation) instead.

**Required permissions**: ohos.permission.GET_RUNNING_INFO (available only for system applications)

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback\<Array\<[ProcessRunningInfo](js-apis-inner-application-processRunningInfo.md)>> | Yes| Callback used to return the information about the running processes.|

**Example**
    
  ```ts
  import appManager from '@ohos.application.appManager';

  appManager.getProcessRunningInfos((error, data) => {
      if (error && error.code !== 0) {
          console.error(`getProcessRunningInfos fail, error: ${JSON.stringify(error)}`);
      } else {
          console.log(`getProcessRunningInfos success, data: ${JSON.stringify(data)}`);
      }
  });
  ```
