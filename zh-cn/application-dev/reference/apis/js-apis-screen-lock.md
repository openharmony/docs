# 锁屏管理

锁屏管理服务是OpenHarmony中的系统服务，为锁屏应用提供注册亮屏、灭屏、开启屏幕、结束休眠、退出动画、请求解锁结果监听，并提供回调结果给锁屏应用。锁屏管理服务向三方应用提供请求解锁、查询锁屏状态、查询是否设置锁屏密码的能力。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import screenlock from '@ohos.screenLock';
```

## screenlock.isScreenLocked

isScreenLocked(callback: AsyncCallback&lt;boolean&gt;): void

判断屏幕是否锁屏，使用callback异步回调。

> **说明：**
> 
>从 API version 7开始支持，从API version 9开始废弃。建议使用[screenlock.isLocked<sup>9+</sup>](#screenlockislocked9)代替。

**系统能力：** SystemCapability.MiscServices.ScreenLock

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                                        |
| -------- | ---------------------------- | ---- | ----------------------------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数，返回true表示屏幕已锁屏，返回false表示屏幕未锁屏。 |

**示例：**

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

判断屏幕是否锁屏，使用Promise异步回调。

> **说明：**
> 
> 从API version 7开始支持，从API version 9开始废弃。建议使用[screenlock.isLocked<sup>9+</sup>](#screenlockislocked9)代替。

**系统能力：** SystemCapability.MiscServices.ScreenLock

**返回值：** 

| 类型                   | 说明                                         |
| ---------------------- | ------------------------------------------- |
| Promise&lt;boolean&gt; | Promise对象，返回判断结果。返回true表示屏幕已锁屏，返回false表示屏幕未锁屏。 |

**示例：** 

```js
screenlock.isScreenLocked().then((data) => {
    console.log('isScreenLocked success: data -> ${JSON.stringify(data)}');
}).catch((err) => {
    console.error('isScreenLocked fail, promise: err -> ${JSON.stringify(err)}');
});
```

## screenlock.isLocked<sup>9+</sup>

isLocked(): boolean

判断屏幕是否锁屏，使用同步方法。

**系统能力：** SystemCapability.MiscServices.ScreenLock

**返回值：** 

| 类型    | 说明                                              |
| ------- | ------------------------------------------------- |
| boolean | 返回true表示屏幕已锁屏，返回false表示屏幕未锁屏。 |

**示例：** 

```js
let isLocked = screenlock.isLocked();
```

## screenlock.isSecureMode

isSecureMode(callback: AsyncCallback&lt;boolean&gt;): void

判断设备是否处于安全模式下，使用callback异步回调。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[screenlock.isSecure<sup>9+</sup>](#screenlockissecure9)代替。

**系统能力：** SystemCapability.MiscServices.ScreenLock

**参数：** 

| 参数名   | 类型            | 必填 | 说明                              |
| -------- | --------------------- | ---- | ------------------------ |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。返回true表示屏幕处于安全模式下，返回false表示屏幕当前不在安全模式下。 |

**示例：** 

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

判断设备是否处于安全模式下，使用Promise异步回调。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[screenlock.isSecure<sup>9+</sup>](#screenlockissecure9)代替。

**系统能力：** SystemCapability.MiscServices.ScreenLock

**返回值：** 

| 类型                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise对象。返回true表示屏幕处于安全模式下，返回false表示屏幕当前不在安全模式下。 |

**示例：** 

```js
screenlock.isSecureMode().then((data) => {
    console.log('isSecureMode success: data->${JSON.stringify(data)}');
}).catch((err) => {
    console.error('isSecureMode fail, promise: err->${JSON.stringify(err)}');
});
```

## screenlock.isSecure<sup>9+</sup>

isSecure(): boolean

判断设备是否处于安全模式下。

**系统能力：** SystemCapability.MiscServices.ScreenLock

**返回值：** 

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 返回true表示屏幕处于安全模式下，返回false表示屏幕当前不在安全模式下。 |

**示例：** 

```js
let isSecure = screenlock.isSecure();
```

## screenlock.unlockScreen

unlockScreen(callback: AsyncCallback&lt;void&gt;): void

解锁屏幕，使用callback异步回调。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[screenlock.unlock<sup>9+</sup>](#screenlockunlock9)代替。

**系统能力：** SystemCapability.MiscServices.ScreenLock

**参数：** 

| 参数名   | 类型              | 必填 | 说明             |
| -------- | ------------- | ---- | --------------- |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，失败时返回错误信息。 |

**示例：** 

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

解锁屏幕，使用Promise异步回调。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[screenlock.unlock<sup>9+</sup>](#screenlockunlock9)代替。

**系统能力：** SystemCapability.MiscServices.ScreenLock

**返回值：** 

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：** 

```js
screenlock.unlockScreen().then(() => {
    console.log('unlockScreen success');
}).catch((err) => {
    console.error('unlockScreen fail, promise: err->${JSON.stringify(err)}');
});
```

## screenlock.unlock<sup>9+</sup>

unlock(callback: AsyncCallback&lt;boolean&gt;): void

解锁屏幕，使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.ScreenLock

**参数：** 

| 参数名   | 类型          | 必填 | 说明                                 |
| -------- | --------------------- | ---- | ------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。返回true表示屏幕解锁成功，返回false表示屏幕解锁失败。 |

**示例：** 

```js
screenlock.unlock((err,data) => {      
    if (err) {
        console.error('unlock  error -> ${JSON.stringify(err)}');
        return;    
    }
    console.info('unlock  success data -> ${JSON.stringify(data)}');
});
```

## screenlock.unlock<sup>9+</sup>

unlock(): Promise&lt;boolean&gt;

解锁屏幕，使用Promise异步回调。

**系统能力：** SystemCapability.MiscServices.ScreenLock

**返回值：** 

| 类型                | 说明                                                         |
| ------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise对象。返回true表示屏幕解锁成功，返回false表示屏幕解锁失败。 |

**示例：** 

```js
screenlock.unlock().then((data) => {
    console.log('unlock success');
}).catch((err) => {
    console.error('unlock fail, : err->${JSON.stringify(err)}');
});
```

## screenlock.lock<sup>9+</sup>

lock(callback: AsyncCallback&lt;boolean&gt;): void

锁定屏幕，使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.ScreenLock

**系统接口**：此接口为系统接口。

**参数：** 

| 参数名   | 类型          | 必填 | 说明                      |
| -------- | ---------------------- | ---- | ---------------- |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。返回true表示屏幕锁定成功，返回false表示屏幕锁定失败。 |

**示例：** 

```js
screenlock.lock((err,data) => {      
    if (err) {
        console.error('lock callback error -> ${JSON.stringify(err)}');
        return;    
    }
    console.info('lock callback success');
});
```

## screenlock.lock<sup>9+</sup>

lock(): Promise&lt;boolean&gt;

锁定屏幕，使用Promise异步回调。

**系统能力：** SystemCapability.MiscServices.ScreenLock

**系统接口**：此接口为系统接口。

**返回值：** 

| 类型                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise对象。返回true表示屏幕锁定成功，返回false表示屏幕锁定失败。 |

**示例：** 

```js
screenlock.lock().then((data) => {
    console.log('lock success');
}).catch((err) => {
    console.error('lock fail, promise: err->${JSON.stringify(err)}');
});
```

## EventType

定义系统事件类型。

**系统能力：** SystemCapability.MiscServices.ScreenLock

| 事件类型            | 说明                     |
| ------------------ | ------------------------ |
| beginWakeUp        | 表示事件开始时开始唤醒。 |
| endWakeUp          | 表示事件结束时结束唤醒。 |
| beginScreenOn      | 表示事件开始时开始亮屏。 |
| endScreenOn        | 表示事件结束时结束亮屏。 |
| beginScreenOff     | 表示事件开始时开始灭屏。 |
| endScreenOff       | 表示事件结束时结束灭屏。 |
| unlockScreen       | 表示请求解锁屏幕。       |
| lockScreen         | 表示请求锁定屏幕。       |
| beginExitAnimation | 表示动画开始退场。       |
| beginSleep         | 表示开始休眠。           |
| endSleep           | 表示结束休眠。           |
| changeUser         | 表示切换用户。           |
| screenlockEnabled  | 表示锁屏是否启用。       |
| serviceRestart     | 表示锁屏服务进行重启。   |


## SystemEvent

定义系统事件回调参数结构。

**系统能力：** SystemCapability.MiscServices.ScreenLock

| 名称    | 类型   | 必填 |       说明        |
| --------- | ------ | ---- | ------------- |
| eventType   | [EventType](#eventtype) | 是   | 系统事件类型。 |
| params | string | 是   | 系统事件的事件参数。 |

## screenlock.onSystemEvent<sup>9+</sup>

onSystemEvent(callback: Callback\<SystemEvent\>): boolean

注册锁屏相关的系统事件。

**系统能力：** SystemCapability.MiscServices.ScreenLock

**系统接口**：此接口为系统接口。

**参数：** 

| 参数名   | 类型                                   | 必填 | 说明                         |
| -------- | -------------------------------------- | ---- | ---------------------------- |
| callback | Callback\<[SystemEvent](#systemevent)> | 是   | 锁屏相关的系统事件回调函数。 |

**返回值：** 

| 类型    | 说明                                              |
| ------- | ------------------------------------------------- |
| boolean | 返回true表示锁屏系统事件注册成功，否则返回false。 |

**示例：** 

```js
let isSuccess = screenlock.onSystemEvent((event)=>{
    console.log(`onSystemEvent:callback:${event.eventType}`)
});
if (!isSuccess) {
    console.log(`onSystemEvent result is false`)
}
```

## screenlock.sendScreenLockEvent<sup>9+</sup>

sendScreenLockEvent(event: String, parameter: number, callback: AsyncCallback\<boolean>): void

应用发送事件到锁屏服务，使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.ScreenLock

**系统接口**：此接口为系统接口。

**参数：** 

| 参数名    | 类型            | 必填 | 说明                             |
| --------- | ------------------------ | ---- | -------------------- |
| event     | String                   | 是   | 事件类型，支持如下取值:<br/>- "unlockScreenResult"，表示解锁结果。<br/>- "screenDrawDone"，表示屏幕绘制完成。 |
| parameter | number                   | 是   | 解锁状态。<br/>- parameter为0，表示解锁成功。<br/>- parameter为1，表示解锁失败。<br/>- parameter为2，表示解锁取消。 |
| callback  | AsyncCallback\<boolean> | 是   | 回调函数，返回执行的结果。true表示执行成功，false表示执行失败。                 |

**示例：** 

```js
screenlock.sendScreenLockEvent('unlockScreenResult', 0, (err, result) => {
    console.log('sending result:' + result);
});
```

## screenlock.sendScreenLockEvent<sup>9+</sup>

sendScreenLockEvent(event: String, parameter: number): Promise\<boolean>

应用发送事件到锁屏服务，使用Promise异步回调。

**系统能力：** SystemCapability.MiscServices.ScreenLock

**系统接口**：此接口为系统接口。

**参数：** 

| 参数名    | 类型   | 必填 | 说明                                       |
| --------- | ------ | ---- | --------------------------------------- |
| event     | String | 是   | 事件类型，支持如下取值:<br/>- "unlockScreenResult"，表示解锁结果。<br/>- "screenDrawDone"，表示屏幕绘制完成。 |
| parameter | number | 是   | 解锁状态。<br/>- parameter为0，表示解锁成功。<br/>- parameter为1，表示解锁失败。<br/>- parameter为2，表示解锁取消。 |

**返回值：** 

| 类型               | 说明                                                         |
| ------------------ | ------------------------------------------------------------ |
| Promise\<boolean> | Promise对象，返回执行的结果。true表示执行成功，false表示执行失败。 |

**示例：** 

```js
screenlock.sendScreenLockEvent('unlockScreenResult', 0).then((result) => {
    console.log('sending result:' + result);
});
```