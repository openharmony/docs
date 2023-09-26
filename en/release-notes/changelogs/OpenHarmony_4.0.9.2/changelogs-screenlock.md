# Theme Framework Subsystem – Screen Lock Management Service Changelog

## cl.screenlock.1 Instance Name Change

Changed the name of the instance for importing the **@ohos.screenLock** module from **screenlock** to **screenLock**.

**Change Impact**

None.

**Key API/Component Changes**

Before change:

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

After change:

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

**Adaptation Guide**

Use **screenLock** in the **import** statement.

Before change:

```js
import screenlock from '@ohos.screenLock';
```

After change:

```js
import screenLock from '@ohos.screenLock';
```
