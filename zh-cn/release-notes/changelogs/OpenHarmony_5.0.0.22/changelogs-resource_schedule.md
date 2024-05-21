# 资源调度子系统变更说明

## c1.resource schedule.1 后台应用管控变更

**访问级别**

其他

**变更原因**

播放音频的应用在后台停止长时任务之后，仍在执行音频流播放，影响系统运行。

**变更影响**

后台不合理使用音频的应用，会被系统强制终止。

**起始 API Level**

9

**变更发生版本**

从OpenHarmony SDK 5.0.0.22版本开始。

**变更的接口/组件**

变更前：如果音频流类型为STREAM_USAGE_MEDIA或SREAM_USAGE_UNKNOWN，应用会被系统强制终止。
变更后：不论应用使用何种音频流类型，均会被系统强制终止。
变更计划：本版本会提示日志"Audio cannot be used after being frozen. The system will kill the UID"，下个版本开始执行查杀。

**适配指导**

后台使用音频资源时需要申请长时任务，不需要使用音频资源时需要及时释放长时任务和音频资源。
长时任务使用指导：
https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/task-management/continuous-task.md
