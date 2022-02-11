# 后台任务开发指导

## 场景介绍

应用或业务模块处于后台（无可见界面）时，如果有需要继续执行或者后续执行的业务，可基于业务类型，申请短时任务延迟挂起（Suspend）或者长时任务避免进入挂起状态。


## 接口说明

```
import backgroundTaskManager from '@ohos.backgroundTaskManager';
```

**表1** backgroundTaskManager主要接口

| 接口名 | 描述 |
| -------- | -------- |
| function&nbsp;requestSuspendDelay(reason:&nbsp;string,&nbsp;callback:&nbsp;Callback&lt;void&gt;):&nbsp;**DelaySuspendInfo**; | 后台应用申请延迟挂起。<br/>延迟挂起时间一般情况下默认值为180000，低电量（依据系统低电量广播）时默认值为60000。 |
| function&nbsp;getRemainingDelayTime(requestId:&nbsp;number,&nbsp;callback:&nbsp;AsyncCallback&lt;number&gt;):&nbsp;void;<br/>function&nbsp;getRemainingDelayTime(requestId:&nbsp;number):&nbsp;Promise&lt;number&gt;; | 获取应用程序进入挂起状态前的剩余时间。(requestId从requestSuspendDelay的返回值获取)<br/>提供两种异步方法，使用Callback形式其任务执行结果以参数形式提供给回调函数，Promise形式则返回一个Promise对象。 |
| function&nbsp;cancelSuspendDelay(requestId:&nbsp;number):&nbsp;void; | 取消延迟挂起。(requestId从requestSuspendDelay的返回值获取) |

**表2** DelaySuspendInfo包含参数

| 参数名 | 类型 | 是否必选 | 描述 |
| -------- | -------- | -------- | -------- |
| requestId | number | 是 | 延迟挂起的请求ID。 |
| actualDelayTime | number | 是 | 应用的实际挂起延迟时间，以毫秒为单位。 |


## 开发步骤

1. 申请延迟挂起
   ```
   import backgroundTaskManager from '@ohos.backgroundTaskManager';
   let myReason = 'test requestSuspendDelay';
   let delayInfo = backgroundTaskManager.requestSuspendDelay(myReason, () => {
       console.info("Request suspension delay will time out.");
   });
   var id = delayInfo.requestId;console.info("requestId is: " + id);
   ```

2. 获取进入挂起前的剩余时间
   ```
   backgroundTaskManager.getRemainingDelayTime(id).then( res => {
       console.log('promise => Operation succeeded. Data: ' + JSON.stringify(res));
   }).catch( err => {
       console.log('promise => Operation failed. Cause: ' + err.data);
   });
   ```

3. 取消延迟挂起
   ```
   backgroundTaskManager.cancelSuspendDelay(id);
   ```


## 开发实例

```
import backgroundTaskManager from '@ohos.backgroundTaskManager';
let myReason = 'test requestSuspendDelay';
// 申请延迟挂起
let delayInfo = backgroundTaskManager.requestSuspendDelay(myReason, () => {
    console.info("Request suspension delay will time out.");
});
// 打印延迟挂起信息
var id = delayInfo.requestId;
var time = delayInfo.actualDelayTime;
console.info("The requestId is: " + id);
console.info("The actualDelayTime is: " + time);
// 获取应用程序进入挂起状态前的剩余时间
backgroundTaskManager.getRemainingDelayTime(id).then( res => {
    console.log('promise => Operation succeeded. Data: ' + JSON.stringify(res));
}).catch( err => {
    console.log('promise => Operation failed. Cause: ' + err.data);
});
// 取消延迟挂起
backgroundTaskManager.cancelSuspendDelay(id);
```
