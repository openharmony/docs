# Theme Framework Subsystem – Screenlock Management Service Changelog

## cl.screenlock.1 API Error Change

Since API version 11, error code 13200002 is added to the **unlock()** API. This change is a compatible change and does not require adaptation.

**Access Level**

System API

**Reason for Change**

When an application not in focus calls the **unlock()** API, the previous error code returned – 201 "Permission denied" – does not signify the actual error. To rectify this issue, error code 13200002 is added.

**Change Impact**

This change is a compatible change and does not require adaptation.

**Change Since**

OpenHarmony SDK 4.1.5.2

**Key API/Component Changes**

The error code returned when an application not in focus calls **unlock()** is changed.

- Involved API:

```js
  function unlock(callback: AsyncCallback<boolean>): void;
  function unlock():Promise<boolean>;
```

- Before change:

When an application not in focus calls **unlock()**, error code 201 is returned.

```js
  /**
   * Unlock the screen.
   *
   * @param { AsyncCallback<boolean> } callback - the callback of unlock.
   * @throws { BusinessError } 401 - parameter error.
   * @throws { BusinessError } 202 - permission verification failed, application which is not a system application uses system API.
   * @throws { BusinessError } 13200002 - the screenlock management service is abnormal.
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

When an application not in focus calls **unlock()**, error code 13200003 is returned.

```js
  /**
   * Unlock the screen.
   *
   * @param { AsyncCallback<boolean> } callback - the callback of unlock.
   * @throws { BusinessError } 401 - parameter error.
   * @throws { BusinessError } 202 - permission verification failed, application which is not a system application uses system API.
   * @throws { BusinessError } 13200002 - the screenlock management service is abnormal.
   * @syscap SystemCapability.MiscServices.ScreenLock
   * @systemapi Hide this for inner system use.
   * @since 9
   */
  /**
   * Unlock the screen.
   *
   * @param { AsyncCallback<boolean> } callback - the callback of unlock.
   * @throws { BusinessError } 401 - parameter error.
   * @throws { BusinessError } 202 - permission verification failed, application which is not a system application uses system API.
   * @throws { BusinessError } 13200002 - the screenlock management service is abnormal.
   * @throws { BusinessError } 13200003 - illegal use.
   * @syscap SystemCapability.MiscServices.ScreenLock
   * @systemapi Hide this for inner system use.
   * @since 11
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
  /**
   * Unlock the screen.
   *
   * @returns { Promise<boolean> } the promise returned by the function.
   * @throws { BusinessError } 202 - permission verification failed, application which is not a system application uses system API.
   * @throws { BusinessError } 13200002 - the screenlock management service is abnormal.
   * @throws { BusinessError } 13200003 - illegal use.
   * @syscap SystemCapability.MiscServices.ScreenLock
   * @systemapi Hide this for inner system use.
   * @since 11
   */
  function unlock():Promise<boolean>;
```


**Adaptation Guide**

This change only involves error codes, and no adaptation is required.
