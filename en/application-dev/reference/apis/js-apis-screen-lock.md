# Screen Lock Management


> ![icon-note.gif](public_sys-resources/icon-note.gif) **Note：**
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```
import screenlock from '@ohos.screenLock';
```


## screenlock.isScreenLocked

isScreenLocked(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether the screen is locked. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.ScreenLock

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | Yes | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;result.&nbsp;If&nbsp;**true**&nbsp;is&nbsp;returned,&nbsp;the&nbsp;screen&nbsp;is&nbsp;locked.&nbsp;If&nbsp;**false**&nbsp;is&nbsp;returned,&nbsp;the&nbsp;screen&nbsp;is&nbsp;not&nbsp;locked. |

- Example
  
  ```
  screenlock.isScreenLocked((err, data)=>{      
     if (err) {
          console.error('isScreenLocked callback error -> ${JSON.stringify(err)}');
          return;    
     }
     console.info('isScreenLocked callback success data -> ${JSON.stringify(data)}');
  });
  ```


## screenlock.isScreenLocked

isScreenLocked(): Promise&lt;boolean&gt;

Checks whether the screen is locked. This method uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.ScreenLock

- Return Values
    | Type | Description |
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;result. |

- Example
  
  ```
  screenlock.isScreenLocked().then((data) => {
      console.log('isScreenLocked success: data -> ${JSON.stringify(data)}');
  }).catch((err) => {
      console.error('isScreenLocked fail, promise: err -> ${JSON.stringify(err)}');
  });
  ```


## screenlock.isSecureMode

isSecureMode(callback: AsyncCallback&lt;boolean&gt;): void


Checks whether a device is in secure mode. This method uses an asynchronous callback to return the result.


**System capability**: SystemCapability.MiscServices.ScreenLock


- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | Yes | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;result.&nbsp;If&nbsp;**true**&nbsp;is&nbsp;returned,&nbsp;the&nbsp;device&nbsp;is&nbsp;in&nbsp;secure&nbsp;mode.&nbsp;If&nbsp;**false**&nbsp;is&nbsp;returned,&nbsp;the&nbsp;device&nbsp;is&nbsp;not&nbsp;in&nbsp;secure&nbsp;mode. |

- Example
  
  ```
  screenlock.isSecureMode((err, data)=>{      
     if (err) {
          console.error('isSecureMode callback error -> ${JSON.stringify(err)}');
          return;    
     }
     console.info('isSecureMode callback success data -> ${JSON.stringify(err)}');
  });
  ```


## screenlock.isSecureMode

isSecureMode(): Promise&lt;boolean&gt;

Checks whether a device is in secure mode. This method uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.ScreenLock

- Return Values
    | Type | Description |
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;result. |

- Example
  
  ```
  screenlock.isSecureMode().then((data) => {
      console.log('isSecureMode success: data->${JSON.stringify(data)}');
  }).catch((err) => {
      console.error('isSecureMode fail, promise: err->${JSON.stringify(err)}');
  });
  ```


## screenlock.unlockScreen

unlockScreen(callback: AsyncCallback&lt;void&gt;): void


Unlocks the screen. This method uses an asynchronous callback to return the result.


**System capability**: SystemCapability.MiscServices.ScreenLock


- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | Yes | Callback&nbsp;function.&nbsp;If&nbsp;the&nbsp;callback&nbsp;fails,&nbsp;an&nbsp;error&nbsp;message&nbsp;is&nbsp;returned. |

- Example
  
  ```
  screenlock.unlockScreen((err)=>{      
     if (err) {
          console.error('unlockScreen callback error -> ${JSON.stringify(err)}');
          return;    
     }
     console.info('unlockScreen callback success');
  });
  ```


## screenlock.unlockScreen

unlockScreen(): Promise&lt;void&gt;

Unlocks the screen. This method uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.ScreenLock

- Return Values
    | Type | Description |
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;result. |

- Example
  
  ```
  screenlock.unlockScreen().then(() => {
      console.log('unlockScreen success');
  }).catch((err) => {
      console.error('unlockScreen fail, promise: err->${JSON.stringify(err)}');
  });
  ```
