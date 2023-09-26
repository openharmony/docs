# 主题框架子系统锁屏管理ChangeLog

## cl.screenlock.1 代码实例名称变更

锁屏管理的包名为'@ohos.screenLock'，在导入时，使用的代码实例应为screenLock，而不是screenlock。

**变更影响**

无。

**关键的接口/组件变更**

修改前的接口调用：

 ```js
screenlock.isLocked();
screenlock.unlock();
screenlock.lock();
screenlock.onSystemEvent(event=>{});
screenlock.sendScreenLockEvent('unlockScreenResult', 0);
screenlock.isScreenLocked()
screenlock.isSecureMode();
screenlock.unlockScreen();
 ```

修改后的接口调用：

 ```js
screenLock.isLocked();
screenLock.unlock();
screenLock.lock();
screenLock.onSystemEvent(event=>{});
screenLock.sendScreenLockEvent('unlockScreenResult', 0);
screenLock.isScreenLocked()
screenLock.isSecureMode();
screenLock.unlockScreen();
 ```

**适配指导**

导入时使用screenLock，例如：：

修改前

```js
import screenlock from '@ohos.screenLock';
```

修改后

```js
import screenLock from '@ohos.screenLock';
```

