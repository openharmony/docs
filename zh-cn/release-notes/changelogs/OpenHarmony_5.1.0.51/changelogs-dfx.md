# DFX子系统ChangeLog

## cl.hiviewdfx.1 HiAppEvent模块onReceive、OH_HiAppEvent_OnReceive、takeNext接口支持应用分身故障日志订阅隔离

**访问级别**

公开接口

**变更原因**

应用分身从设计原则上要求数据隔离，当前应用分身的故障日志和主应用未进行隔离，不易于对分身应用的日志维护。

**变更影响**

此变更不涉及应用适配

变更前：hiappevent在主应用、分身应用可以同时获取到主应用和分身应用的故障日志。

变更后：hiappevent在主应用仅可以获取到主应用的故障日志，分身应用仅可以获取到分身应用的故障日志。

**起始API Level**

- takeNext接口起始API 9
- onReceive接口起始API 11
- OH_HiAppEvent_OnReceive接口起始API 12

**变更发生版本**

从OpenHarmony SDK 5.1.0.51 版本开始。

**变更的接口/组件**

@ohos.hiviewdfx.hiAppEvent.d.ts中的[onReceive](../../../application-dev/reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md#watcher)、[takeNext](../../../application-dev/reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md#takenext)接口。
hiappevent.h中的[OH_HiAppEvent_OnReceive](../../../application-dev/reference/apis-performance-analysis-kit/_hi_app_event.md#oh_hiappevent_onreceive)接口。

**适配指导**

默认行为变更，无需适配。