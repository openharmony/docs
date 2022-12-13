# @ohos.screenLock (锁屏管理)

锁屏管理服务是OpenHarmony中的系统服务，为锁屏应用提供注册亮屏、灭屏、开启屏幕、结束休眠、退出动画、请求解锁结果监听，并提供回调结果给锁屏应用。锁屏管理服务向三方应用提供请求解锁、查询锁屏状态、查询是否设置锁屏密码的能力。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import screenlock from '@ohos.screenLock';
```

## EventType

定义系统事件类型。

**系统能力：** SystemCapability.MiscServices.ScreenLock

| 事件类型            | 说明                     |
| ------------------ | ------------------------ |
| beginWakeUp        | 表示设备开始唤醒。 |
| endWakeUp          | 表示设备结束唤醒。 |
| beginScreenOn      | 表示设备开始亮屏。 |
| endScreenOn        | 表示设备结束亮屏。 |
| beginScreenOff     | 表示设备开始灭屏。 |
| endScreenOff       | 表示设备结束灭屏。 |
| unlockScreen       | 表示请求屏幕解锁。       |
| lockScreen         | 表示请求屏幕锁定。       |
| beginExitAnimation | 表示开始退场动画。       |
| beginSleep         | 表示设备开始休眠。           |
| endSleep           | 表示设备结束休眠。           |
| changeUser         | 表示切换用户。           |
| screenlockEnabled  | 表示锁屏是否启用。       |
| serviceRestart     | 表示锁屏服务进行重启。   |

## SystemEvent

定义系统事件回调参数结构。

**系统能力：** SystemCapability.MiscServices.ScreenLock

| 名称    | 类型   | 必填 |       说明        |
| --------- | ------ | ---- | ------------- |
| eventType   | [EventType](#eventtype) | 是   | 系统事件类型。 |
| params | string | 是   | 系统事件参数。 |

## screenlock.isLocked<sup>9+</sup>

isLocked(): boolean

判断屏幕是否锁屏。

**系统能力：** SystemCapability.MiscServices.ScreenLock

**返回值：** 

| 类型    | 说明                                              |
| ------- | ------------------------------------------------- |
| boolean | 返回true表示屏幕已锁屏；返回false表示屏幕未锁屏。 |

**示例：** 

```js
let isLocked = screenlock.isLocked();
```

## screenlock.isSecure<sup>9+</sup>

isSecure(): boolean

判断当前设备的屏幕锁定是否安全（安全屏幕锁定意味着解锁屏幕需要密码、图案或其他用户身份识别）。

**系统能力：** SystemCapability.MiscServices.ScreenLock

**返回值：** 

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 返回true表示当前设备的屏幕锁定安全；返回false表示当前设备的屏幕锁定不安全。 |

**示例：** 

```js
let isSecure = screenlock.isSecure();
```

## screenlock.unlock<sup>9+</sup>

unlock(callback: AsyncCallback&lt;boolean&gt;): void

解锁屏幕。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.ScreenLock

**参数：** 

| 参数名   | 类型          | 必填 | 说明                                 |
| -------- | --------------------- | ---- | ------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。返回true表示屏幕解锁成功；返回false表示屏幕解锁失败。 |

**示例：** 

```js
screenlock.unlock((err, data) => {      
    if (err) {
        console.error(`Failed to unlock the screen, because: ${err.message}`);
        return;    
    }
    console.info(`unlock the screen successfully. result: ${data}`);
});
```

## screenlock.unlock<sup>9+</sup>

unlock(): Promise&lt;boolean&gt;

解锁屏幕。使用Promise异步回调。

**系统能力：** SystemCapability.MiscServices.ScreenLock

**返回值：** 

| 类型                | 说明                                                         |
| ------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise对象。返回true表示屏幕解锁成功；返回false表示屏幕解锁失败。 |

**示例：** 

```js
screenlock.unlock().then((data) => {
    console.info(`unlock the screen successfully. result: ${data}`);
}).catch((err) => {
    console.error(`Failed to unlock the screen, because: ${err.message}`);
});
```

## screenlock.lock<sup>9+</sup>

lock(callback: AsyncCallback&lt;boolean&gt;): void

锁定屏幕。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.ScreenLock

**系统接口**：此接口为系统接口。

**参数：** 

| 参数名   | 类型          | 必填 | 说明                      |
| -------- | ---------------------- | ---- | ---------------- |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。返回true表示屏幕锁定成功；返回false表示屏幕锁定失败。 |

**示例：** 

```js
screenlock.lock((err, data) => {      
    if (err) {
        console.error(`Failed to lock the screen, because: ${err.message}`);
        return;    
    }
    console.info(`lock the screen successfully. result: ${data}`);
});
```

## screenlock.lock<sup>9+</sup>

lock(): Promise&lt;boolean&gt;

锁定屏幕。使用Promise异步回调。

**系统能力：** SystemCapability.MiscServices.ScreenLock

**系统接口**：此接口为系统接口。

**返回值：** 

| 类型                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise对象。返回true表示屏幕锁定成功；返回false表示屏幕锁定失败。 |

**示例：** 

```js
screenlock.lock().then((data) => {
    console.info(`lock the screen successfully. result: ${data}`);
}).catch((err) => {
    console.error(`Failed to lock the screen, because: ${err.message}`);
});
```

## screenlock.onSystemEvent<sup>9+</sup>

onSystemEvent(callback: Callback&lt;SystemEvent&gt;): boolean

注册锁屏相关的系统事件。

**系统能力：** SystemCapability.MiscServices.ScreenLock

**系统接口**：此接口为系统接口。

**参数：** 

| 参数名   | 类型                        | 必填 | 说明               |
| -------- | ------------------------- | ---- | ----------------- |
| callback | Callback\<[SystemEvent](#systemevent)> | 是   | 锁屏相关的系统事件回调函数。 |

**返回值：** 

| 类型    | 说明                                              |
| ------- | ------------------------------------------------- |
| boolean | 返回true表示锁屏相关系统事件注册成功；返回false表示锁屏相关系统事件注册失败。 |

**示例：** 

```js
try {
    let isSuccess = screenLock.onSystemEvent((event) => {
        console.log(`Register the system event which related to screenlock successfully. eventType: ${event.eventType}`)
    });
} catch (err) {
    console.error(`Failed to register the system event which related to screenlock, because: ${err.message}`)
}
```

## screenlock.sendScreenLockEvent<sup>9+</sup>

sendScreenLockEvent(event: String, parameter: number, callback: AsyncCallback&lt;boolean&gt;): void

应用发送事件到锁屏服务。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.ScreenLock

**系统接口**：此接口为系统接口。

**参数：** 

| 参数名    | 类型            | 必填 | 说明                             |
| --------- | ------------------------ | ---- | -------------------- |
| event     | String                   | 是   | 事件类型，支持如下取值:<br/>- "unlockScreenResult"，表示解锁结果。<br/>- "lockScreenResult"，表示锁屏结果。<br/>- "screenDrawDone"，表示屏幕绘制完成。 |
| parameter | number                   | 是   | 事件结果。<br/>- parameter为0，表示成功。例如解锁成功或锁屏成功。<br/>- parameter为1，表示失败。例如解锁失败或锁屏失败。<br/>- parameter为2，表示取消。例如锁屏取消或解锁取消。 |
| callback  | AsyncCallback\<boolean> | 是   | 回调函数。返回true表示发送事件成功；返回false表示发送事件失败。                 |

**示例：** 

```js
screenlock.sendScreenLockEvent('unlockScreenResult', 0, (err, result) => {
    if (err) {
        console.error(`Failed to send screenlock event, because: ${err.message}`);
        return;
    }
    console.info(`Send screenlock event successfully. result: ${result}`);
});
```

## screenlock.sendScreenLockEvent<sup>9+</sup>

sendScreenLockEvent(event: String, parameter: number): Promise&lt;boolean&gt;

应用发送事件到锁屏服务。使用Promise异步回调。

**系统能力：** SystemCapability.MiscServices.ScreenLock

**系统接口**：此接口为系统接口。

**参数：** 

| 参数名    | 类型   | 必填 | 说明                                       |
| --------- | ------ | ---- | --------------------------------------- |
| event     | String | 是   | 事件类型，支持如下取值:<br/>- "unlockScreenResult"，表示解锁结果。<br/>- "lockScreenResult"，表示锁屏结果。<br/>- "screenDrawDone"，表示屏幕绘制完成。 |
| parameter | number | 是   | 事件结果。<br/>- parameter为0，表示成功。例如解锁成功或锁屏成功。<br/>- parameter为1，表示失败。例如解锁失败或锁屏失败。<br/>- parameter为2，表示取消。例如锁屏取消或解锁取消。 |

**返回值：** 

| 类型               | 说明                                           |
| ----------------- | ---------------------------------------------- |
| Promise\<boolean> | Promise对象。返回true表示发送事件成功；返回false表示发送事件失败。 |

**示例：** 

```js
screenlock.sendScreenLockEvent('unlockScreenResult', 0).then((result) => {
    console.info(`Send screenlock event successfully. result: ${result}`);
}).catch((err) => {
    console.error(`Failed to send screenlock event, because: ${err.message}`);
});
```

## screenlock.isScreenLocked<sup>(deprecated)</sup>

isScreenLocked(callback: AsyncCallback&lt;boolean&gt;): void

判断屏幕是否锁屏。使用callback异步回调。

> **说明：**
> 
>从 API version 7开始支持，从API version 9开始废弃。建议使用[screenlock.isLocked<sup>9+</sup>](#screenlockislocked9)代替。

**系统能力：** SystemCapability.MiscServices.ScreenLock

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                                        |
| -------- | ---------------------------- | ---- | ----------------------------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。返回true表示屏幕已锁屏；返回false表示屏幕未锁屏。 |

**示例：**

```js
screenlock.isScreenLocked((err, data)=>{      
    if (err) {
        console.error(`Failed to obtain whether the screen is locked, because: ${err.message}`);
        return;    
    }
    console.info(`Obtain whether the screen is locked successfully. result: ${data}`);
});
```

## screenlock.isScreenLocked<sup>(deprecated)</sup>

isScreenLocked(): Promise&lt;boolean&gt;

判断屏幕是否锁屏。使用Promise异步回调。

> **说明：**
> 
> 从API version 7开始支持，从API version 9开始废弃。建议使用[screenlock.isLocked<sup>9+</sup>](#screenlockislocked9)代替。

**系统能力：** SystemCapability.MiscServices.ScreenLock

**返回值：** 

| 类型                   | 说明                                         |
| ---------------------- | ------------------------------------------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示屏幕已锁屏；返回false表示屏幕未锁屏。 |

**示例：** 

```js
screenlock.isScreenLocked().then((data) => {
    console.info(`Obtain whether the screen is locked successfully. result: ${data}`);
}).catch((err) => {
    console.error(`Failed to obtain whether the screen is locked, because: ${err.message}`);
});
```

## screenlock.isSecureMode<sup>(deprecated)</sup>

isSecureMode(callback: AsyncCallback&lt;boolean&gt;): void

判断当前设备的屏幕锁定是否安全（安全屏幕锁定意味着解锁屏幕需要密码、图案或其他用户身份识别）。使用callback异步回调。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[screenlock.isSecure<sup>9+</sup>](#screenlockissecure9)代替。

**系统能力：** SystemCapability.MiscServices.ScreenLock

**参数：** 

| 参数名   | 类型            | 必填 | 说明                              |
| -------- | --------------------- | ---- | ------------------------ |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。返回true表示当前设备的屏幕锁定安全；返回false表示当前设备的屏幕锁定不安全。 |

**示例：** 

```js
screenlock.isSecureMode((err, data)=>{
    if (err) {
        console.error(`Failed to obtain whether the device is in secure mode, because: ${err.message}`);
        return;
    }
    console.info(`Obtain whether the device is in secure mode successfully. result: ${data}`);
});
```

## screenlock.isSecureMode<sup>(deprecated)</sup>

isSecureMode(): Promise&lt;boolean&gt;

判断当前设备的屏幕锁定是否安全（安全屏幕锁定意味着解锁屏幕需要密码、图案或其他用户身份识别）。使用Promise异步回调。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[screenlock.isSecure<sup>9+</sup>](#screenlockissecure9)代替。

**系统能力：** SystemCapability.MiscServices.ScreenLock

**返回值：** 

| 类型                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise对象。返回true表示当前设备的屏幕锁定安全；返回false表示当前设备的屏幕锁定不安全。 |

**示例：** 

```js
screenlock.isSecureMode().then((data) => {
    console.info(`Obtain whether the device is in secure mode successfully. result: ${data}`);
}).catch((err) => {
    console.error(`Failed to obtain whether the device is in secure mode, because: ${err.message}`);
});
```
## screenlock.unlockScreen<sup>(deprecated)</sup>

unlockScreen(callback: AsyncCallback&lt;void&gt;): void

解锁屏幕。使用callback异步回调。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[screenlock.unlock<sup>9+</sup>](#screenlockunlock9)代替。

**系统能力：** SystemCapability.MiscServices.ScreenLock

**参数：** 

| 参数名   | 类型              | 必填 | 说明             |
| -------- | ------------- | ---- | --------------- |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。解锁屏幕成功，err为undefined，否则为错误对象。 |

**示例：** 

```js
screenlock.unlockScreen((err) => {      
    if (err) {
        console.error(`Failed to unlock the screen, because: ${err.message}`);
        return;    
    }
    console.info('unlock the screen successfully.');
});
```

## screenlock.unlockScreen<sup>(deprecated)</sup>

unlockScreen(): Promise&lt;void&gt;

解锁屏幕。使用Promise异步回调。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[screenlock.unlock<sup>9+</sup>](#screenlockunlock9)代替。

**系统能力：** SystemCapability.MiscServices.ScreenLock

**返回值：** 

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**示例：** 

```js
screenlock.unlockScreen().then(() => {
    console.info('unlock the screen successfully.');
}).catch((err) => {
    console.error(`Failed to unlock the screen, because: ${err.message}`);
});
```
