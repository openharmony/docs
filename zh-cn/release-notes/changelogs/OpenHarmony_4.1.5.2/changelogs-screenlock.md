# 主题框架子系统-锁屏管理服务ChangeLog

## cl.screenlock.1  接口异常抛出变更

从API11开始，unlock接口增加错误码返回13200002，此次属于兼容性变更，开发者无需适配。

**变更影响**

相较于之前，当非焦点应用调用unlock()时返回的错误码不同。

- 涉及接口

```js
  function unlock(callback: AsyncCallback<boolean>): void;
  function unlock():Promise<boolean>;
```

- 变更前：

非焦点应用调用unlock()时返回201表示权限校验失败。

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

- 变更后：

非焦点应用调用unlock()时返回13200003表示非法调用。

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


**适配指导**

本次修改仅涉及错误码修改，其余行为不变。
