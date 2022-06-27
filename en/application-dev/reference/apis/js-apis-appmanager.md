# appManager

> **NOTE**
> 
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


Implements application management.


## Modules to Import


```js
import app from '@ohos.application.appManager';
```


## appManager.isRunningInStabilityTest<sup>8+</sup>

static isRunningInStabilityTest(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether this application is undergoing a stability test. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | No| Callback used to return the result. If the application is undergoing a stability test, **true** will be returned; otherwise, **false** will be returned.| 

**Example**
    
  ```js
  import app from '@ohos.application.appManager';
  app.isRunningInStabilityTest((err, flag) => {
      console.log('startAbility result:' + JSON.stringify(err));
  })  
  ```


## appManager.isRunningInStabilityTest<sup>8+</sup>

static isRunningInStabilityTest(): Promise&lt;boolean&gt;

Checks whether this application is undergoing a stability test. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

  | Type| Description| 
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Promise used to return the result. If the application is undergoing a stability test, **true** will be returned; otherwise, **false** will be returned.| 

**Example**
    
  ```js
  import app from '@ohos.application.appManager';
  app.isRunningInStabilityTest().then((flag) => {
      console.log('success:' + JSON.stringify(flag));
  }).catch((error) => {
      console.log('failed:' + JSON.stringify(error));
  });
  ```


## appManager.isRamConstrainedDevice

isRamConstrainedDevice(): Promise\<boolean>;

Checks whether this application is running on a RAM constrained device. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

  | Type| Description| 
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Promise used to return whether the application is running on a RAM constrained device. If the application is running on a RAM constrained device, **true** will be returned; otherwise, **false** will be returned.| 

**Example**
    
  ```js
        app.isRamConstrainedDevice().then((data) => {
            console.log('success:' + JSON.stringify(data));
        }).catch((error) => {
            console.log('failed:' + JSON.stringify(error));
        });
  ```

## appManager.isRamConstrainedDevice

isRamConstrainedDevice(callback: AsyncCallback\<boolean>): void;

Checks whether this application is running on a RAM constrained device. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | No| Callback used to return whether the application is running on a RAM constrained device. If the application is running on a RAM constrained device, **true** will be returned; otherwise, **false** will be returned.| 

**Example**
    
  ```js
        app.isRamConstrainedDevice((err, data) => {
            console.log('startAbility result failed:' + JSON.stringify(err));
            console.log('startAbility result success:' + JSON.stringify(data));
        })
  ```

## appManager.getAppMemorySize

getAppMemorySize(): Promise\<number>;

Obtains the memory size of this application. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

  | Type| Description| 
  | -------- | -------- |
  | Promise&lt;number&gt; | Size of the application memory.| 

**Example**
    
  ```js
        app.getAppMemorySize().then((data) => {
            console.log('success:' + JSON.stringify(data));
        }).catch((error) => {
            console.log('failed:' + JSON.stringify(error));
        });
  ```

## appManager.getAppMemorySize

getAppMemorySize(callback: AsyncCallback\<number>): void;

Obtains the memory size of this application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;number&gt; | No| Size of the application memory.| 

**Example**
    
  ```js
        app.getAppMemorySize((err, data) => {
            console.log('startAbility result failed :' + JSON.stringify(err));
            console.log('startAbility result success:' + JSON.stringify(data));
        })
  ```
## appManager.getProcessRunningInfos<sup>8+</sup>

getProcessRunningInfos(): Promise\<Array\<ProcessRunningInfo>>;

Obtains information about the running processes. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<Array\<ProcessRunningInfo>> | Promise used to return the process information.|

**Example**
    
  ```js
        app.getProcessRunningInfos().then((data) => {
            console.log('success:' + JSON.stringify(data));
        }).catch((error) => {
            console.log('failed:' + JSON.stringify(error));
        });
  ```

## appManager.getProcessRunningInfos<sup>8+</sup>

getProcessRunningInfos(callback: AsyncCallback\<Array\<ProcessRunningInfo>>): void;

Obtains information about the running processes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback\<Array\<ProcessRunningInfo>> | No| Callback used to return the process information.|

**Example**
    
  ```js
        app.getProcessRunningInfos((err, data) => {
            console.log('startAbility result failed :' + JSON.stringify(err));
            console.log('startAbility result success:' + JSON.stringify(data));
        })
  ```

## ProcessRunningInfo

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name       | Readable/Writable| Type                | Mandatory| Description                                                        |
| ----------- | -------- | -------------------- | ---- | ------------------------------------------------------------ |
| pid<sup>8+</sup>     | Read only    | number               | No  | Process ID.                               |
| uid<sup>8+</sup>   | Read only    | number               | No  | User ID.|
| processName<sup>8+</sup>  | Read only    | string               | No  | Process name.|
| bundleNames<sup>8+</sup>          | Read only    | Array\<string>              | No  | **bundleName** array in the running processes.|
