# Runninglock锁

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```
import runninglock from '@ohos.runningLock';
```


## 系统能力

SystemCapability.PowerManager.PowerManager


## RunningLockType

RunningLock锁的类型。

| 名称 | 默认值 | 描述 |
| -------- | -------- | -------- |
| BACKGROUND | 1 | 阻止系统休眠的锁。 |
| PROXIMITY_SCREEN_CONTROL | 2 | 通过接近或者远离状态来控制亮灭屏的锁。 |


## isRunningLockTypeSupported

isRunningLockTypeSupported(type: RunningLockType, callback: AsyncCallback&lt;boolean&gt;): void

查询系统是否支持该类型的锁。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | RunningLockType | 是 | 需要查询的锁的类型。 |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 指定的callback回调方法，用于获取返回值。<br/>callback返回值：支持返回true，不支持返回false。 |

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

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | RunningLockType | 是 | 需要查询的锁的类型。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
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

需要权限：ohos.permission.RUNNING_LOCK

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 锁的名字。 |
| type | RunningLockType | 是 | 要创建的锁的类型。 |
| callback | AsyncCallback&lt;[RunningLock](#runninglock)&gt; | 是 | 指定的callback回调方法，用于获取返回的RunningLock锁对象。 |

**示例：**

```
runningLock.createRunningLock("running_lock_test", runningLock.RunningLockType.BACKGROUND)
.then(runninglock => {
    var used = runninglock.isUsed();
    console.info('runninglock is used: ' + used);
    runninglock.lock(500);
    used = runninglock.isUsed();
    console.info('after lock runninglock is used ' + used);
})
.catch(error => {
    console.log('create runningLock test error: ' + error);
})
```


## createRunningLock

createRunningLock(name: string, type: RunningLockType): Promise&lt;RunningLock&gt;

创建Runninglock锁。

需要权限：ohos.permission.RUNNING_LOCK

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 锁的名字。 |
| type | RunningLockType | 是 | 要创建的锁的类型。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
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

锁定和持有RunningLock

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| timeout | number | 否 | 锁定和持有RunningLock的时长。 |

**示例：**

```
runningLock.createRunningLock("running_lock_test", runningLock.RunningLockType.BACKGROUND)
.then(runningLock => {
    runningLock.lock(100)
    console.info('create runningLock success')
})
.catch(error => {
    console.log('Lock runningLock test error: ' + error)
});
```


### unlock

unlock(): void

释放Runninglock锁。

**示例：**

```
runningLock.createRunningLock("running_lock_test", runningLock.RunningLockType.BACKGROUND)
.then(runningLock => {
    runningLock.unlock()
    console.info('unLock runningLock success')
})
.catch(error => {
    console.log('unLock runningLock test error: ' + error)
});
```


### isUsed

isUsed(): boolean

查询当前Runninglock是持有状态，还是释放状态。

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
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
