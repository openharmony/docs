# appManager

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> The initial APIs of this module are supported since API 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


Implements application management.


## Modules to Import

  
```
import app from '@ohos.application.appManager';
```


## isRunningInStabilityTest

static isRunningInStabilityTest(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether this application is undergoing a stability test. This API uses a callback to return the result.

- Parameters
    | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | No| Callback used to return the result.| 

- Example
    
  ```
  import app from '@ohos.application.appManager';
  app.isRunningInStabilityTest((err, flag) => {
      console.log('startAbility result:' + JSON.stringfy(err);
  }  
  ```


## isRunningInStabilityTest

static isRunningInStabilityTest(): Promise&lt;boolean&gt;

Checks whether this application is undergoing a stability test. This method uses a promise to return the result.

- Return value
    | Type| Description| 
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Promise used to return the result.| 

- Example
    
  ```
  import app from '@ohos.application.appManager';
  app.isRunningInStabilityTest().then((flag) => {
      console.log('success:' + JSON.stringfy(flag));
  )).catch((error) => {
      console.log('failed:' + JSON.stringfy(error));
  });
  ```
