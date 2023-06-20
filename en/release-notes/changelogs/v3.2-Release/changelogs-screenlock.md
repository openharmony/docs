# Theme Framework Subsystem – Screenlock Management Service Changelog


## cl.screenlock.1 Permission Change of isLocked and unlock
Changed the **isLocked** and **unlock** APIs to system APIs since API version 9.

You need to adapt your application based on the following information.

**Change Impact**

The JS API needs to be adapted for applications developed based on earlier versions. Otherwise, relevant functions will be affected.

- Involved APIs:

```js
  function isLocked(): boolean;
  function unlock(callback: AsyncCallback<boolean>): void;
  function unlock():Promise<boolean>;
```

- Before change:

```js
   * Checks whether the screen is currently locked.
   *
   * @returns Returns {@code true} if the screen is currently locked; returns {@code false} otherwise.
   * @syscap SystemCapability.MiscServices.ScreenLock
   * @since 9
   */
  function isLocked(): boolean;

  /**
   * Unlock the screen.
   *
   * @returns Returns {@code true} if the screen is unlocked successfully; returns {@code false} otherwise.
   * @throws {BusinessError} 401 - parameter error.
   * @throws {BusinessError} 202 - permission verification failed, application which is not a system application uses system API.
   * @throws {BusinessError} 13200002 - the screenlock management service is abnormal.
   * @syscap SystemCapability.MiscServices.ScreenLock
   * @systemapi Hide this for inner system use.
   * @since 9
   */
  function unlock(callback: AsyncCallback<boolean>): void;

  /**
   * Unlock the screen.
   *
   * @returns Returns {@code true} if the screen is unlocked successfully; returns {@code false} otherwise.
   * @throws {BusinessError} 401 - parameter error.
   * @throws {BusinessError} 202 - permission verification failed, application which is not a system application uses system API.
   * @throws {BusinessError} 13200002 - the screenlock management service is abnormal.
   * @syscap SystemCapability.MiscServices.ScreenLock
   * @systemapi Hide this for inner system use.
   * @since 9
   */
  function unlock():Promise<boolean>;
```

- After change:

```js
   * Checks whether the screen is currently locked.
   *
   * @returns Returns {@code true} if the screen is currently locked; returns {@code false} otherwise.
   * @throws {BusinessError} 202 - permission verification failed, application which is not a system application uses system API.
   * @syscap SystemCapability.MiscServices.ScreenLock
   * @systemapi Hide this for inner system use.
   * @since 9
   */
  function isLocked(): boolean;

  /**
   * Unlock the screen.
   *
   * @returns Returns {@code true} if the screen is unlocked successfully; returns {@code false} otherwise.
   * @throws {BusinessError} 401 - parameter error.
   * @throws {BusinessError} 13200002 - the screenlock management service is abnormal.
   * @syscap SystemCapability.MiscServices.ScreenLock
   * @since 9
   */
  function unlock(callback: AsyncCallback<boolean>): void;

  /**
   * Unlock the screen.
   *
   * @returns Returns {@code true} if the screen is unlocked successfully; returns {@code false} otherwise.
   * @throws {BusinessError} 13200002 - the screenlock management service is abnormal.
   * @syscap SystemCapability.MiscServices.ScreenLock
   * @since 9
   */
  function unlock():Promise<boolean>;
```


**Adaptation Guide**

Make sure the APIs are only invoked by system applications.

The code snippet is as follows:

```js
    try {
      let ret = screenLock.isLocked();
      console.error(`Obtain whether the screen is locked successfully , ret is: ${ret}`);
    } catch (error) {
      console.error(`Failed to obtain whether the screen is locked, error is : ${error.code}, ${error.message}`);
    }
```

```js
    screenlock.unlock((err, data) => {      
        if (err) {
            console.error(`Failed to unlock the screen, because: ${err.message}`);
            return;    
        }
        console.info(`unlock the screen successfully. result: ${data}`);
    });
```

```js
    screenlock.unlock().then((data) => {
        console.info(`unlock the screen successfully. result: ${data}`);
    }).catch((err) => {
        console.error(`Failed to unlock the screen, because: ${err.message}`);
    });
```


## cl.screenlock.2 Deprecation of isSecure
Deprecated the **isSecure** API since API version 9.

You need to adapt your application based on the following information.

**Change Impact**

The API can no longer be used after being deleted.

- Involved APIs:

```js
  function isSecure(): boolean;
```

- Before change:

```js
  function isSecure(): boolean;
```

- After change:

  The API is deleted.


**Adaptation Guide**

Update the code so that the deprecated API is not used.
