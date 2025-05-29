# @ohos.backgroundTaskManager (后台任务管理)(系统接口)

本模块提供后台任务管理能力。

当应用或业务模块处于后台（无可见界面）时，如果有需要继续执行或者后续执行的业务，可基于业务类型，申请短时任务延迟挂起（Suspend）或者长时任务避免进入挂起状态。

应用有不可中断且短时间能完成的任务时（如，用户在文件管理器上点击垃圾文件清理，若清理未完成时退到后台，文件管理器需要申请短时任务完成清理），可以使用短时任务机制。

应用中存在用户能够直观感受到的且需要一直在后台运行的业务时（如，后台播放音乐），可以使用长时任务机制。

对于系统特权应用，提供独立的能效资源申请接口。系统特权应用如果需要使用特定的系统资源，例如需要在被挂起期间仍然能够收到系统公共事件，可以使用能效资源申请接口。

>  **说明：**
>
> - 从API Version 9 开始，该接口不再维护，推荐使用新接口[@ohos.resourceschedule.backgroundTaskManager (后台任务管理)](js-apis-resourceschedule-backgroundTaskManager-sys.md)。
>
> - 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块为系统接口，其他公开接口请参见[@ohos.backgroundTaskManager (后台任务管理)](js-apis-backgroundTaskManager.md)。


## 导入模块

```ts
import backgroundTaskManager from '@ohos.backgroundTaskManager';  
```

## BackgroundMode<sup>8+</sup>

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

| 名称                     | 值  | 说明                    |
| ----------------------- | ---- | --------------------- |
| WIFI_INTERACTION        | 7    | WLAN相关<br />此接口为系统接口。 |
| VOIP                    | 8    | 音视频通话<br />此接口为系统接口。  |
