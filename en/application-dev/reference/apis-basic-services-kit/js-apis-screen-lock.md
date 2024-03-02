# @ohos.screenLock (Screen Lock)

The **screenlock** module is a system module in OpenHarmony. It provides APIs for screen lock applications to subscribe to screen lock status changes as well as callbacks for them to receive the results. It also provides APIs for third-party applications to unlock the screen, obtain the screen locked status, and check whether a lock screen password has been set.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import screenLock from '@ohos.screenLock';
```

## screenLock.isScreenLocked<sup>(deprecated)</sup>

isScreenLocked(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether the screen is locked. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Parameters**

| Name  | Type                        | Mandatory| Description                                                       |
| -------- | ---------------------------- | ---- | ----------------------------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. The value **true** means that the screen is locked, and **false** means the opposite.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';

  screenLock.isScreenLocked((err: BusinessError, data: Boolean)=>{      
    if (err) {
      console.error(`Failed to obtain whether the screen is locked, Code: ${err.code}, message: ${err.message}`);
      return;    
    }
    console.info(`Succeeded in Obtaining whether the screen is locked. result: ${data}`);
  });
  ```

## screenLock.isScreenLocked<sup>(deprecated)</sup>

isScreenLocked(): Promise&lt;boolean&gt;

Checks whether the screen is locked. This API uses a promise to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Return value**

| Type                  | Description                                        |
| ---------------------- | ------------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means that the screen is locked, and **false** means the opposite.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';

  screenLock.isScreenLocked().then((data: Boolean) => {
    console.info(`Succeeded in Obtaining whether the screen is locked. result: ${data}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to obtain whether the screen is locked, Code: ${err.code}, message: ${err.message}`);
  });
  ```

## screenLock.isSecureMode<sup>(deprecated)</sup>

isSecureMode(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether the device is in secure mode. When the device is in secure mode, its screen requires a password, unlock pattern, or other user credentials to unlock. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Parameters**

| Name  | Type           | Mandatory| Description                             |
| -------- | --------------------- | ---- | ------------------------ |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. The value **true** means that the device is in secure mode, and **false** means the opposite.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';

  screenLock.isSecureMode((err: BusinessError, data: Boolean)=>{
    if (err) {
      console.error(`Failed to obtain whether the device is in secure mode, Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info(`Succeeded in Obtaining whether the device is in secure mode. result: ${data}`);
  });
  ```

## screenLock.isSecureMode<sup>(deprecated)</sup>

isSecureMode(): Promise&lt;boolean&gt;

Checks whether the device is in secure mode. When the device is in secure mode, its screen requires a password, unlock pattern, or other user credentials to unlock. This API uses a promise to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Return value**

| Type                  | Description                                                        |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means that the device is in secure mode, and **false** means the opposite.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';

  screenLock.isSecureMode().then((data: Boolean) => {
    console.info(`Succeeded in Obtaining whether the device is in secure mode. result: ${data}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to obtain whether the device is in secure mode, Code: ${err.code}, message: ${err.message}`);
  });
  ```

## screenLock.unlockScreen<sup>(deprecated)</sup>

unlockScreen(callback: AsyncCallback&lt;void&gt;): void

Unlocks the screen. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Parameters**

| Name  | Type             | Mandatory| Description            |
| -------- | ------------- | ---- | --------------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the screen is unlocked successfully, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';

  screenLock.unlockScreen((err: BusinessError) => {      
    if (err) {
      console.error(`Failed to unlock the screen, Code: ${err.code}, message: ${err.message}`);
      return;    
    }
    console.info(`Succeeded unlocking the screen.`);
  });
  ```

## screenLock.unlockScreen<sup>(deprecated)</sup>

unlockScreen(): Promise&lt;void&gt;

Unlocks the screen. This API uses a promise to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9.

**System capability**: SystemCapability.MiscServices.ScreenLock

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';

  screenLock.unlockScreen().then(() => {
    console.info('Succeeded unlocking the screen.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to unlock the screen, Code: ${err.code}, message: ${err.message}`);
  });
  ```
