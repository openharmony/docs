# 资源调度子系统ChangeLog

## ohos.resourceschedule.backgroundTaskManager.1  

能效资源申请接口支持系统特权应用申请RunningLock和Sensor的能效资源。

**变更影响**

基于OpenHarmony4.0.8.1及之后的SDK版本开发的系统特权应用，可以申请RunningLock和Sensor的能效资源，保障后台持锁和使用Sensor的能力。

**关键接口/组件变更**

| 模块名                | 类名         | 方法/属性/枚举/常量 | 变更类型 |
| --------------------- | ------------ | ------------------- | -------- |
| backgroundTaskManager | ResourceType | RUNNING_LOCK = 128  | 新增     |
| backgroundTaskManager | ResourceType | SENSOR = 256        | 新增     |

**适配指导**<br>

```ts
import backgroundTaskManager from '@ohos.resourceschedule.backgroundTaskManager';

let request = {
    resourceTypes: backgroundTaskManager.ResourceType.RUNNING_LOCK |
        backgroundTaskManager.ResourceType.SENSOR,
    isApply: true,
    timeOut: 0,
    reason: "apply runninglock and sensor resource",
    isPersist: true
};
let res;
try {
    res = backgroundTaskManager.applyEfficiencyResources(request);
    console.info("the result of request is: " + res);
} catch (error) {
    console.error(`Operation applyEfficiencyResources failed. code is ${error.code} message is ${error.message}`);
}
```
