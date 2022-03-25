# Runninglock锁

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

该模块主要提供Runninglock锁相关操作的接口，包括创建、查询、持锁、释放锁等操作。


## 导入模块

```
import runningLock from '@ohos.runningLock';
```


## RunningLockType

RunningLock锁的类型。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.PowerManager.PowerManager.Core

| 名称                       | 默认值  | 描述                  |
| ------------------------ | ---- | ------------------- |
| BACKGROUND               | 1    | 阻止系统休眠的锁。           |
| PROXIMITY_SCREEN_CONTROL | 2    | 通过接近或者远离状态来控制亮灭屏的锁。 |


## isRunningLockTypeSupported

isRunningLockTypeSupported(type: RunningLockType, callback: AsyncCallback&lt;boolean&gt;): void

查询系统是否支持该类型的锁。

**系统能力：** SystemCapability.PowerManager.PowerManager.Core

**参数：**

| 参数名      | 类型                           | 必填   | 说明                                       |
| -------- | ---------------------------- | ---- | ---------------------------------------- |
| type     | RunningLockType              | 是    | 需要查询的锁的类型。                               |
| callback | AsyncCallback&lt;boolean&gt; | 是    | 指定的callback回调方法，用于获取返回值。<br/>callback返回值：支持返回true，不支持返回false。 |

**示例：**

```
runningLock.isRunningLockTypeSupported(runningLock.RunningLockType.BACKGROUND, (error, supported) => {
    if (typeof error === "undefined") {
        console.info('BACKGROUND support status is ' + supported);
    } else {
        console.log('error: ' + error);
    }
})
```


## isRunningLockTypeSupported

isRunningLockTypeSupported(type: RunningLockType): Promise&lt;boolean&gt;

查询系统是否支持该类型的锁。

**系统能力：** SystemCapability.PowerManager.PowerManager.Core

**参数：**

| 参数名  | 类型              | 必填   | 说明         |
| ---- | --------------- | ---- | ---------- |
| type | RunningLockType | 是    | 需要查询的锁的类型。 |

**返回值：**

| 类型                     | 说明                                       |
| ---------------------- | ---------------------------------------- |
| Promise&lt;boolean&gt; | Promise实例，用于异步获取返回值，支持返回true，不支持返回false。 |

**示例：**

```
runningLock.isRunningLockTypeSupported(runningLock.RunningLockType.PROXIMITY_SCREEN_CONTROL)
.then(supported => {
    console.info('PROXIMITY_SCREEN_CONTROL support status is ' + supported);
})
.catch(error => {
    console.log('error: ' + error);
});
```


## createRunningLock

createRunningLock(name: string, type: RunningLockType, callback: AsyncCallback&lt;RunningLock&gt;): void

创建RunningLock锁。

**系统能力：** SystemCapability.PowerManager.PowerManager.Core

**需要权限：** ohos.permission.RUNNING_LOCK

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                     |
| -------- | ---------------------------------------- | ---- | -------------------------------------- |
| name     | string                                   | 是    | 锁的名字。                                  |
| type     | RunningLockType                          | 是    | 要创建的锁的类型。                              |
| callback | AsyncCallback&lt;[RunningLock](#runninglock)&gt; | 是    | 指定的callback回调方法，用于获取返回的RunningLock锁对象。 |

**示例：**

```
runningLock.createRunningLock("running_lock_test", runningLock.RunningLockType.BACKGROUND, (error, lockIns) => {
    if (typeof error === "undefined") {
        console.log('create runningLock test error: ' + error);
    } else {
        var used = lockIns.isUsed();
        console.info('runninglock is used: ' + used);
        lockIns.lock(500);
        used = lockIns.isUsed();
        console.info('after lock runninglock is used ' + used);
    }
})
```


## createRunningLock

createRunningLock(name: string, type: RunningLockType): Promise&lt;RunningLock&gt;

创建Runninglock锁。

**系统能力：** SystemCapability.PowerManager.PowerManager.Core

**需要权限：** ohos.permission.RUNNING_LOCK

**参数：**

| 参数名  | 类型              | 必填   | 说明        |
| ---- | --------------- | ---- | --------- |
| name | string          | 是    | 锁的名字。     |
| type | RunningLockType | 是    | 要创建的锁的类型。 |

**返回值：**

| 类型                                       | 说明                                 |
| ---------------------------------------- | ---------------------------------- |
| Promise&lt;[RunningLock](#runninglock)&gt; | Promise实例，用于异步获取返回的RunningLock锁对象。 |

**示例：**

```
runningLock.createRunningLock("running_lock_test", runningLock.RunningLockType.BACKGROUND)
.then(runninglock => {
    console.info('create runningLock success');
})
.catch(error => {
    console.log('create runningLock test error: ' + error);
})
```


## RunningLock

阻止系统休眠的锁。


### lock

lock(timeout: number): void

锁定和持有RunningLock。

**系统能力：** SystemCapability.PowerManager.PowerManager.Core

**需要权限：** ohos.permission.RUNNING_LOCK

**参数：**

| 参数名     | 类型     | 必填   | 说明                         |
| ------- | ------ | ---- | -------------------------- |
| timeout | number | 否    | 锁定和持有RunningLock的时长，单位：毫秒。 |

**示例：**

```
runningLock.createRunningLock("running_lock_test", runningLock.RunningLockType.BACKGROUND)
.then(runningLock => {
    runningLock.lock(100)
    console.info('create runningLock success')
})
.catch(error => {
    console.log('create runningLock test error: ' + error)
});
```


### unlock

unlock(): void

释放Runninglock锁。

**系统能力：** SystemCapability.PowerManager.PowerManager.Core

**需要权限：** ohos.permission.RUNNING_LOCK

**示例：**

```
runningLock.createRunningLock("running_lock_test", runningLock.RunningLockType.BACKGROUND)
.then(runningLock => {
    runningLock.unlock()
    console.info('create and unLock runningLock success')
})
.catch(error => {
    console.log('create runningLock test error: ' + error)
});
```


### isUsed

isUsed(): boolean

查询当前Runninglock是持有状态还是释放状态。

**系统能力：** SystemCapability.PowerManager.PowerManager.Core

**返回值：**
| 类型      | 说明                                    |
| ------- | ------------------------------------- |
| boolean | 当前RunningLock是持有状态返回true，释放状态返回false。 |

**示例：**

```
runningLock.createRunningLock("running_lock_test", runningLock.RunningLockType.BACKGROUND)
.then(runningLock => {
    var used = runningLock.isUsed()
    console.info('runningLock used status: ' + used)
})
.catch(error => {
    console.log('runningLock isUsed test error: ' + error)
});
```
