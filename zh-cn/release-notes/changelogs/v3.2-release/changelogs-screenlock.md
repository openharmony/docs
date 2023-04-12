# 主题框架子系统-锁屏管理服务ChangeLog


## cl.screenlock.1  isLocked、unlock接口使用权限变更
从API9开始，变更为systemapi，停止对三方应用开放。

开发者需要根据以下说明对应用进行适配。

**变更影响**

基于此前版本开发的应用，需适配变更的js接口，变更前的接口已经不能正常使用了，否则会影响原有功能。

- 涉及接口

```js
  function isLocked(): boolean;
  function unlock(callback: AsyncCallback<boolean>): void;
  function unlock():Promise<boolean>;
```

- 变更前：

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

- 变更后：

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


**适配指导**

该接口变更为系统应用后，三方应用已无法使用。
系统应用可正常使用。
示例代码如下：

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


## cl.screenlock.2  isSecure接口废弃变更
从API9开始，废弃此接口。

开发者需要根据以下说明对应用进行适配。

**变更影响**

该接口删除无法再使用，请使用进行更新使用，否则会影响原有功能。

- 涉及接口

```js
  function isSecure(): boolean;
```

- 变更前：

```js
  function isSecure(): boolean;
```

- 变更后：删除接口，停止对外开放。


**适配指导**

该接口删除后无法再使用，请适配更新。
