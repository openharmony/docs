# 资源调度子系统ChangeLog

## ohos.resourceschedule.runningLock.1  

提醒代理支持系统应用设置自定义按钮，并且自定义按钮可申请RunningLock锁。

**变更影响**

基于OpenHarmony4.0.8.1及之后的SDK版本开发的系统应用，冻结后RunningLock锁释放，提高进入休眠概率。

**关键接口/组件变更**

| 模块名                | 类名         | 方法/属性/枚举/常量 | 变更类型 |
| --------------------- | ------------ | ------------------- | -------- |
| backgroundTaskManager | ResourceType | RUNNING_LOCK = 128  | 新增     |

**适配指导**<br>

```ts
import runningLock from '@ohos.runningLock';

let request = {
    resourceTypes: backgroundTaskManager.ResourceType.RUNNING_LOCK,
    isApply: true,
    timeOut: 0,
    reason: "apply",
    isPersist: true
};
let res;
try {
    res = backgroundTaskManager.applyEfficiencyResources(request);//申请RUNNING_LOCK能效资源
    console.info("the result of request is: " + res);
} catch (error) {
    console.error(`Operation applyEfficiencyResources failed. code is ${error.code} message is ${error.message}`);
}

runningLock.create('running_lock_test', runningLock.RunningLockType.BACKGROUND)
    .then(lock => {
    console.info('xuhanyang create running lock success');
    try {
        lock.hold(500000);//RUNNING_LOCK持锁500s
        console.info('hold running lock success');
    } catch(err) {
        console.error('hold running lock failed, err: ' + err);
    }
})
    .catch(err => {
    console.error('create running lock failed, err: ' + err);
});
```

## ohos.resourceschedule.sensor.2  

冻结后Sensor处理，降低系统功耗。

**变更影响**

基于OpenHarmony4.0.8.1及之后的SDK版本开发的系统应用，可设置提醒自动消失。

**关键接口/组件变更**

| 模块名                | 类名         | 方法/属性/枚举/常量 | 变更类型 |
| --------------------- | ------------ | ------------------- | -------- |
| backgroundTaskManager | ResourceType | SENSOR = 256        | 新增     |

**适配指导**<br>

```ts
import sensor from '@ohos.sensor';
import backgroundTaskManager from '@ohos.resourceschedule.backgroundTaskManager';

let request = {
    resourceTypes: backgroundTaskManager.ResourceType.SENSOR,
    isApply: true,
    timeOut: 0,
    reason: "apply",
    isPersist: true
};
let res;
try {
    res = backgroundTaskManager.applyEfficiencyResources(request);//申请Sensor能效资源
    console.info("xuhanyang the result of request is: " + res);
} catch (error) {
    console.error(`Operation applyEfficiencyResources failed. code is ${error.code} message is ${error.message}`);
}

try {
    sensor.on(sensor.SensorId.ACCELEROMETER, function(data){
        console.info("Data obtained successfully. x: " + data.x + "y: " + data.y + "z: " + data.z); // 获取数据成功
    });//开启sensor获取数据
}
catch (error) {
    console.error(`apply SENSOR fail. code is ${error.code} message is ${error.message}`);
}
```