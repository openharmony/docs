# Screen Lock Management

The **screenlock** module is a system module in OpenHarmony. It provides APIs for screen lock applications to subscribe to screen lock status changes as well as callbacks for them to receive the results. It also provides APIs for third-party applications to unlock the screen, obtain the screen locked status, and check whether a lock screen password has been set.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```js
import screenlock from '@ohos.screenLock';
```


## screenlock.isScreenLocked

isScreenLocked(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether the screen is locked. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes| Returns **true** if the screen is locked; returns **false** otherwise.|

**Example**

  ```js
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

Checks whether the screen is locked. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Return value**
| Type| Description|
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise used to return the result.|

**Example**

  ```js
  screenlock.isScreenLocked().then((data) => {
      console.log('isScreenLocked success: data -> ${JSON.stringify(data)}');
  }).catch((err) => {
      console.error('isScreenLocked fail, promise: err -> ${JSON.stringify(err)}');
  });
  ```


## screenlock.isSecureMode

isSecureMode(callback: AsyncCallback&lt;boolean&gt;): void


Checks whether a device is in secure mode. This API uses an asynchronous callback to return the result.


**System capability**: SystemCapability.MiscServices.ScreenLock


**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes| Returns **true** if the device is in secure mode; returns **false** otherwise.|

**Example**

  ```js
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

Checks whether a device is in secure mode. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Return value**
| Type| Description|
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise used to return the result.|

**Example**

  ```js
  screenlock.isSecureMode().then((data) => {
      console.log('isSecureMode success: data->${JSON.stringify(data)}');
  }).catch((err) => {
      console.error('isSecureMode fail, promise: err->${JSON.stringify(err)}');
  });
  ```


## screenlock.unlockScreen

unlockScreen(callback: AsyncCallback&lt;void&gt;): void


Unlocks the screen. This API uses an asynchronous callback to return the result.


**System capability**: SystemCapability.MiscServices.ScreenLock


**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation failed, an error message is returned.|

**Example**

  ```js
  screenlock.unlockScreen((err) => {      
     if (err) {
          console.error('unlockScreen callback error -> ${JSON.stringify(err)}');
          return;    
     }
     console.info('unlockScreen callback success');
  });
  ```


## screenlock.unlockScreen

unlockScreen(): Promise&lt;void&gt;

Unlocks the screen. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Return value**
| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

  ```js
  screenlock.unlockScreen().then(() => {
      console.log('unlockScreen success');
  }).catch((err) => {
      console.error('unlockScreen fail, promise: err->${JSON.stringify(err)}');
  });
  ```
