# @ohos.runningLock (RunningLock锁)

<!--Kit: Basic Services Kit-->
<!--Subsystem: PowerManager-->
<!--Owner: @zhang-yinglie; @volcano_wang-->
<!--Designer: @wangyantian0-->
<!--Tester: @alien0208-->
<!--Adviser: @w_Machine_cc-->

该模块主要提供RunningLock锁相关操作的接口，包括创建、查询、持锁、释放锁等操作。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import {runningLock} from '@kit.BasicServicesKit';
```

## runningLock.isSupported<sup>9+</sup>

isSupported(type: RunningLockType): boolean

查询系统是否支持该类型的锁。

**系统能力：** SystemCapability.PowerManager.PowerManager.Core

**参数：**

| 参数名 | 类型                                | 必填 | 说明                 |
| ------ | ----------------------------------- | ---- | -------------------- |
| type   | [RunningLockType](#runninglocktype) | 是   | 需要查询的锁的类型；该参数必须是一个枚举类。 |

**返回值：**

| 类型    | 说明                                    |
| ------- | --------------------------------------- |
| boolean | 返回true表示支持，返回false表示不支持。 |

**错误码：**

以下错误码的详细介绍请参见[RunningLock锁错误码](errorcode-runninglock.md)。

| 错误码ID   | 错误信息    |
|---------|---------|
| 401     | Parameter error. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed. |

**示例：**

```js
try {
    let isSupported = runningLock.isSupported(runningLock.RunningLockType.PROXIMITY_SCREEN_CONTROL);
    console.info('BACKGROUND type supported: ' + isSupported);
} catch(err) {
    console.error('check supported failed, err: ' + err);
}
```

## runningLock.create<sup>9+</sup>

create(name: string, type: RunningLockType, callback: AsyncCallback&lt;RunningLock&gt;): void

创建RunningLock锁。

**系统能力：** SystemCapability.PowerManager.PowerManager.Core

**需要权限：** ohos.permission.RUNNING_LOCK

**参数：**

| 参数名   | 类型                                       | 必填 | 说明                                                         |
| -------- | ------------------------------------------ | ---- | ------------------------------------------------------------ |
| name     | string                                     | 是   | 锁的名字；该参数必须为字符串类型。                                                   |
| type     | [RunningLockType](#runninglocktype)        | 是   | 要创建的锁的类型；该参数必须是一个枚举类。                                           |
| callback | AsyncCallback<[RunningLock](#runninglock)> | 是   | 回调函数。当创建锁成功，err为undefined，data为创建的RunningLock；否则为错误对象；AsyncCallback封装了一个RunningLock类型的类。 |

**错误码：**

以下错误码的详细介绍请参见[RunningLock锁错误码](errorcode-runninglock.md)。

| 错误码ID   | 错误信息    |
|---------|---------|
| 401     | Parameter error. Possible causes: 1.Parameter verification failed. |
| 201     | If the permission is denied.|

**示例：**

```js

runningLock.create('running_lock_test', runningLock.RunningLockType.PROXIMITY_SCREEN_CONTROL, (err: Error, lock: runningLock.RunningLock) => {
    if (typeof err === 'undefined') {
        console.info('created running lock: ' + lock);
    } else {
        console.error('create running lock failed, err: ' + err);
    }
});
```

## runningLock.create<sup>9+</sup>

create(name: string, type: RunningLockType): Promise&lt;RunningLock&gt;

创建RunningLock锁。

**系统能力：** SystemCapability.PowerManager.PowerManager.Core

**需要权限：** ohos.permission.RUNNING_LOCK

**参数：**

| 参数名 | 类型                                | 必填 | 说明               |
| ------ | ----------------------------------- | ---- | ------------------ |
| name   | string                              | 是   | 锁的名字；该参数必须为字符串类型。 |
| type   | [RunningLockType](#runninglocktype) | 是   | 要创建的锁的类型；该参数必须是一个枚举类。 |

**返回值：**

| 类型                                       | 说明                                 |
| ------------------------------------------ | ------------------------------------ |
| Promise&lt;[RunningLock](#runninglock)&gt; | Promise对象，返回RunningLock锁对象。 |

**错误码：**

以下错误码的详细介绍请参见[RunningLock锁错误码](errorcode-runninglock.md)。

| 错误码ID   | 错误信息    |
|---------|---------|
| 401     | Parameter error. Possible causes: 1.Parameter verification failed. |
| 201     | If the permission is denied.|

**示例：**

```js

runningLock.create('running_lock_test', runningLock.RunningLockType.PROXIMITY_SCREEN_CONTROL)
.then((lock: runningLock.RunningLock) => {
    console.info('created running lock: ' + lock);
})
.catch((err: Error) => {
    console.error('create running lock failed, err: ' + err);
});
```

## runningLock.isRunningLockTypeSupported<sup>(deprecated)</sup>

isRunningLockTypeSupported(type: RunningLockType, callback: AsyncCallback&lt;boolean&gt;): void

> **说明：**<br>从API version 9开始不再维护，建议使用[runningLock.isSupported](#runninglockissupported9)替代。

查询系统是否支持该类型的锁。使用callback异步回调。

**系统能力：** SystemCapability.PowerManager.PowerManager.Core

**参数：**

| 参数名   | 类型                                | 必填 | 说明                                                         |
| -------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| type     | [RunningLockType](#runninglocktype) | 是   | 需要查询的锁的类型。                                         |
| callback | AsyncCallback&lt;boolean&gt;        | 是   | 回调函数。当查询成功，err为undefined，data为获取到的支持情况，返回true表示支持，返回false表示不支持；否则为错误对象。 |

**示例：**

```js
runningLock.isRunningLockTypeSupported(runningLock.RunningLockType.BACKGROUND, (err: Error, data: boolean) => {
    if (typeof err === 'undefined') {
        console.info('BACKGROUND lock support status: ' + data);
    } else {
        console.log('check BACKGROUND lock support status failed, err: ' + err);
    }
});
```

## runningLock.isRunningLockTypeSupported<sup>(deprecated)</sup>

isRunningLockTypeSupported(type: RunningLockType): Promise&lt;boolean>

> **说明：**<br>从API version 9开始不再维护，建议使用[runningLock.isSupported](#runninglockissupported9)替代。

查询系统是否支持该类型的锁。使用Promise异步回调。

**系统能力：** SystemCapability.PowerManager.PowerManager.Core

**参数：**

| 参数名 | 类型                                | 必填 | 说明                 |
| ------ | ----------------------------------- | ---- | -------------------- |
| type   | [RunningLockType](#runninglocktype) | 是   | 需要查询的锁的类型。 |

**返回值：**

| 类型                   | 说明                                                 |
| ---------------------- | ---------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示支持；返回false表示不支持。 |

**示例：**

```js
runningLock.isRunningLockTypeSupported(runningLock.RunningLockType.BACKGROUND)
.then((data: boolean) => {
    console.info('BACKGROUND lock support status: ' + data);
})
.catch((err: Error) => {
    console.log('check BACKGROUND lock support status failed, err: ' + err);
});
```

## runningLock.createRunningLock<sup>(deprecated)</sup>

createRunningLock(name: string, type: RunningLockType, callback: AsyncCallback&lt;RunningLock&gt;): void

> **说明：**<br>从API version 9开始不再维护，建议使用[runningLock.create](#runninglockcreate9)替代。

创建RunningLock锁。

**系统能力：** SystemCapability.PowerManager.PowerManager.Core

**需要权限：** ohos.permission.RUNNING_LOCK

**参数：**

| 参数名   | 类型                                       | 必填 | 说明                                                         |
| -------- | ------------------------------------------ | ---- | ------------------------------------------------------------ |
| name     | string                                     | 是   | 锁的名字。                                                   |
| type     | [RunningLockType](#runninglocktype)        | 是   | 要创建的锁的类型。                                           |
| callback | AsyncCallback<[RunningLock](#runninglock)> | 是   | 回调函数。当创建锁成功，err为undefined，data为创建的RunningLock；否则为错误对象。 |

**示例：**

```js
runningLock.createRunningLock('running_lock_test', runningLock.RunningLockType.BACKGROUND, (err: Error, lock: runningLock.RunningLock) => {
    if (typeof err === 'undefined') {
        console.info('created running lock: ' + lock);
    } else {
        console.error('create running lock failed, err: ' + err);
    }
});
```

## runningLock.createRunningLock<sup>(deprecated)</sup>

createRunningLock(name: string, type: RunningLockType): Promise&lt;RunningLock&gt;

> **说明：**<br>从API version 9开始不再维护，建议使用[runningLock.create](#runninglockcreate9)替代。

创建RunningLock锁。

**系统能力：** SystemCapability.PowerManager.PowerManager.Core

**需要权限：** ohos.permission.RUNNING_LOCK

**参数：**

| 参数名 | 类型                                | 必填 | 说明               |
| ------ | ----------------------------------- | ---- | ------------------ |
| name   | string                              | 是   | 锁的名字。         |
| type   | [RunningLockType](#runninglocktype) | 是   | 要创建的锁的类型。 |

**返回值：**

| 类型                                       | 说明                                 |
| ------------------------------------------ | ------------------------------------ |
| Promise&lt;[RunningLock](#runninglock)&gt; | Promise对象，返回RunningLock锁对象。 |

**示例：**

```js
runningLock.createRunningLock('running_lock_test', runningLock.RunningLockType.BACKGROUND)
.then((lock: runningLock.RunningLock) => {
    console.info('created running lock: ' + lock);
})
.catch((err: Error) => {
    console.log('create running lock failed, err: ' + err);
});
```

## RunningLock

阻止系统休眠的锁。

### hold<sup>9+</sup>

hold(timeout: number): void

锁定和持有RunningLock。

**系统能力：** SystemCapability.PowerManager.PowerManager.Core

**需要权限：** ohos.permission.RUNNING_LOCK

**参数：**

| 参数名  | 类型   | 必填 | 说明                                      |
| ------- | ------ | ---- | ----------------------------------------- |
| timeout | number | 是   | 锁定和持有RunningLock的时长，单位：毫秒。<br>该参数必须为数字类型：<br>**-1**：永久持锁，需要主动释放。<br>**0**：默认3s后超时释放。<br>**>0**：按传入值超时释放。|

**错误码：**

以下错误码的详细介绍请参见[RunningLock锁错误码](errorcode-runninglock.md)。

| 错误码ID   | 错误信息     |
|---------|----------|
| 401     | Parameter error. Possible causes: 1. Incorrect parameter types. |
| 201     | If the permission is denied.|

**示例：**

```ts
// RunningLockTest.ets
class RunningLockTest {
    public static recordLock: runningLock.RunningLock;

    public static holdRunningLock(): void {
        if (RunningLockTest.recordLock) {
            RunningLockTest.recordLock.hold(500);
            console.info('hold running lock success');
        } else {
            runningLock.create('running_lock_test', runningLock.RunningLockType.PROXIMITY_SCREEN_CONTROL, (err: Error, lock: runningLock.RunningLock) => {
                if (typeof err === 'undefined') {
                    console.info('create running lock: ' + lock);
                    RunningLockTest.recordLock = lock;
                    try {
                        lock.hold(500);
                        console.info('hold running lock success');
                    } catch(err) {
                        console.error('hold running lock failed, err: ' + err);
                    }
                } else {
                    console.error('create running lock failed, err: ' + err);
                }
            });
        }
    }
}
```

### unhold<sup>9+</sup>

unhold(): void

释放RunningLock锁。

**系统能力：** SystemCapability.PowerManager.PowerManager.Core

**需要权限：** ohos.permission.RUNNING_LOCK

**错误码：**

以下错误码的详细介绍请参见[RunningLock锁错误码](errorcode-runninglock.md)。

| 错误码ID   | 错误信息     |
|---------|----------|
| 201     | If the permission is denied.|


**示例：**

```ts
// RunningLockTest.ets
class RunningLockTest {
    public static recordLock: runningLock.RunningLock;

    public static unholdRunningLock(): void {
        if (RunningLockTest.recordLock) {
            RunningLockTest.recordLock.unhold();
            console.info('unhold running lock success');
        } else {
            runningLock.create('running_lock_test', runningLock.RunningLockType.PROXIMITY_SCREEN_CONTROL, (err: Error, lock: runningLock.RunningLock) => {
                if (typeof err === 'undefined') {
                    console.info('create running lock: ' + lock);
                    RunningLockTest.recordLock = lock;
                    try {
                        lock.unhold();
                        console.info('unhold running lock success');
                    } catch(err) {
                        console.error('unhold running lock failed, err: ' + err);
                    }
                } else {
                    console.error('create running lock failed, err: ' + err);
                }
            });
        }
    }
}
```

### isHolding<sup>9+</sup>

isHolding(): boolean

查询当前RunningLock是持有状态还是释放状态。

**系统能力：** SystemCapability.PowerManager.PowerManager.Core

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 返回true表示当前RunningLock是持有状态，返回false表示当前RunningLock是释放状态。 |

**示例：**

```ts
// RunningLockTest.ets
class RunningLockTest {
    public static recordLock: runningLock.RunningLock;

    public static isHoldingRunningLock(): void {
        if (RunningLockTest.recordLock) {
            let isHolding = RunningLockTest.recordLock.isHolding();
            console.info('check running lock holding status: ' + isHolding);
        } else {
            runningLock.create('running_lock_test', runningLock.RunningLockType.PROXIMITY_SCREEN_CONTROL, (err: Error, lock: runningLock.RunningLock) => {
                if (typeof err === 'undefined') {
                    console.info('create running lock: ' + lock);
                    RunningLockTest.recordLock = lock;
                    let isHolding = lock.isHolding();
                    console.info('check running lock holding status: ' + isHolding);
                } else {
                    console.error('create running lock failed, err: ' + err);
                }
            });
        }
    }
}
```

### lock<sup>(deprecated)</sup>

lock(timeout: number): void

> **说明：**<br>从API version 9开始不再维护，建议使用[RunningLock.hold](#hold9)替代。

锁定和持有RunningLock。

**系统能力：** SystemCapability.PowerManager.PowerManager.Core

**需要权限：** ohos.permission.RUNNING_LOCK

**参数：**

| 参数名  | 类型   | 必填 | 说明                                      |
| ------- | ------ | ---- | ----------------------------------------- |
| timeout | number | 是   | 锁定和持有RunningLock的时长，单位：毫秒。 |

**示例：**

```js
runningLock.createRunningLock('running_lock_test', runningLock.RunningLockType.BACKGROUND)
.then((lock: runningLock.RunningLock) => {
    lock.lock(500);
    console.info('create running lock and lock success');
})
.catch((err: Error) => {
    console.error('create running lock failed, err: ' + err);
});
```

### unlock<sup>(deprecated)</sup>

unlock(): void

> **说明：**<br>从API version 9开始不再维护，建议使用[RunningLock.unhold](#unhold9)替代。

释放RunningLock锁。

**系统能力：** SystemCapability.PowerManager.PowerManager.Core

**需要权限：** ohos.permission.RUNNING_LOCK

**示例：**

```js
runningLock.createRunningLock('running_lock_test', runningLock.RunningLockType.BACKGROUND)
.then((lock: runningLock.RunningLock) => {
    lock.unlock();
    console.info('create running lock and unlock success');
})
.catch((err: Error) => {
    console.error('create running lock failed, err: ' + err);
});
```

### isUsed<sup>(deprecated)</sup>

isUsed(): boolean

> **说明：**<br>从API version 9开始不再维护，建议使用[RunningLock.isHolding](#isholding9)替代。

查询当前RunningLock是持有状态还是释放状态。

**系统能力：** SystemCapability.PowerManager.PowerManager.Core

**返回值：**
| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 返回true表示当前RunningLock是持有状态，返回false表示当前RunningLock是释放状态。 |

**示例：**

```js
runningLock.createRunningLock('running_lock_test', runningLock.RunningLockType.BACKGROUND)
.then((lock: runningLock.RunningLock) => {
    let isUsed = lock.isUsed();
    console.info('check running lock used status: ' + isUsed);
})
.catch((err: Error) => {
    console.error('check running lock used status failed, err: ' + err);
});
```

## RunningLockType

RunningLock锁的类型。

**系统能力：** SystemCapability.PowerManager.PowerManager.Core

| 名称                              | 值   | 说明                                                         |
| --------------------------------- | ---- | ------------------------------------------------------------ |
| BACKGROUND<sup>(deprecated)</sup> | 1    | 阻止系统休眠的锁。<br>**说明：** 从API version 7开始支持，从API version 10开始废弃。 |
| PROXIMITY_SCREEN_CONTROL          | 2    | 接近光锁，使能接近光传感器，并根据传感器与障碍物的距离远近发起亮灭屏流程。  |