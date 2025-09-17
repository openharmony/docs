# Performance Analysis Kit（性能分析服务）<!--performance-analysis-api-->

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @mzyan-->
<!--Designer: @liyueric-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

- ArkTS API<!--performance-analysis-arkts-->
  - [@ohos.hichecker (检测模式)](js-apis-hichecker.md)
  - [@ohos.hidebug (Debug调试)](js-apis-hidebug.md)
  - [@ohos.hilog (HiLog日志打印)](js-apis-hilog.md)
  - [@ohos.hiTraceChain (分布式跟踪)](js-apis-hitracechain.md)
  - [@ohos.hiTraceMeter (性能打点)](js-apis-hitracemeter.md)
  - [@ohos.hiviewdfx.FaultLogExtensionAbility (故障延迟通知)](js-apis-hiviewdfx-FaultLogExtensionAbility.md)
  - [@ohos.hiviewdfx.FaultLogExtensionContext (故障延迟通知上下文)](js-apis-hiviewdfx-FaultLogExtensionContext.md)
  - [@ohos.hiviewdfx.hiAppEvent (应用事件打点)](js-apis-hiviewdfx-hiappevent.md)
  - [@ohos.hiviewdfx.jsLeakWatcher (js泄露检测)](js-apis-jsleakwatcher.md)
  <!--Del-->
  - [@ohos.hiSysEvent (系统事件打点)(系统接口)](js-apis-hisysevent-sys.md)
  - [@ohos.logLibrary (维测日志获取)(系统接口)](js-apis-loglibrary-sys.md)
  <!--DelEnd-->
  - 已停止维护的接口<!--performance-analysis-arkts-dep-->
    - [@ohos.bytrace (性能打点)](js-apis-bytrace.md)
    - [@ohos.hiAppEvent (应用打点)](js-apis-hiappevent.md)
    - [@ohos.faultLogger (故障日志获取)](js-apis-faultLogger.md)
- C API<!--performance-analysis-c-->
  - 模块<!--performance-analysis-module-->
    - [HiAppEvent](capi-hiappevent.md)
    - [HiCollie](capi-hicollie.md)
    - [HiDebug](capi-hidebug.md)
    - [HiLog](capi-hilog.md)
    - [Hitrace](capi-hitrace.md)
  - 头文件<!--performance-analysis-headerfile-->
    - [hiappevent.h](capi-hiappevent-h.md)
    - [hiappevent_cfg.h](capi-hiappevent-cfg-h.md)
    - [hiappevent_event.h](capi-hiappevent-event-h.md)
    - [hiappevent_param.h](capi-hiappevent-param-h.md)
    - [hicollie.h](capi-hicollie-h.md)
    - [hidebug.h](capi-hidebug-h.md)
    - [hidebug_type.h](capi-hidebug-type-h.md)
    - [log.h](capi-log-h.md)
    - [trace.h](capi-trace-h.md)
  - 结构体<!--performance-analysis-struct-->
    - [HiAppEvent_AppEventInfo](capi-hiappevent-hiappevent-appeventinfo.md)
    - [HiAppEvent_AppEventGroup](capi-hiappevent-hiappevent-appeventgroup.md)
    - [ParamListNode*](capi-hiappevent-paramlistnode8h.md)
    - [HiAppEvent_Watcher](capi-hiappevent-hiappevent-watcher.md)
    - [HiAppEvent_Processor](capi-hiappevent-hiappevent-processor.md)
    - [HiAppEvent_Config](capi-hiappevent-hiappevent-config.md)
    - [HiCollie_DetectionParam](capi-hicollie-hicollie-detectionparam.md)
    - [HiCollie_SetTimerParam](capi-hicollie-hicollie-settimerparam.md)
    - [HiDebug_ThreadCpuUsage](capi-hidebug-hidebug-threadcpuusage.md)
    - [HiDebug_SystemMemInfo](capi-hidebug-hidebug-systemmeminfo.md)
    - [HiDebug_NativeMemInfo](capi-hidebug-hidebug-nativememinfo.md)
    - [HiDebug_MemoryLimit](capi-hidebug-hidebug-memorylimit.md)
    - [HiDebug_JsStackFrame](capi-hidebug-hidebug-jsstackframe.md)
    - [HiDebug_NativeStackFrame](capi-hidebug-hidebug-nativestackframe.md)
    - [HiDebug_StackFrame](capi-hidebug-hidebug-stackframe.md)
    - [HiDebug_MallocDispatch](capi-hidebug-hidebug-mallocdispatch.md)
    - [HiDebug_Backtrace_Object__*](capi-hidebug-hidebug-backtrace-object--8h.md)
    - [HiDebug_GraphicsMemorySummary](capi-hidebug-hidebug-graphicsmemorysummary.md)
    - [HiTraceId](capi-hitrace-hitraceid.md)
- 错误码<!--performance-analysis-errcode-->
  - [Faultlogger错误码](errorcode-faultlogger.md)
  - [应用事件打点错误码](errorcode-hiappevent.md)
  - [HiDebug错误码](errorcode-hiviewdfx-hidebug.md)
  - [HiDebug CpuUsage错误码](errorcode-hiviewdfx-hidebug-cpuusage.md)
  - [HiDebug Trace错误码](errorcode-hiviewdfx-hidebug-trace.md)
  - [HiCollie错误码](errorcode-hiviewdfx-hicollie.md)
  - [JsLeakWatcher错误码](errorcode-jsleakwatcher.md)
    <!--Del-->
  - [系统事件错误码](errorcode-hisysevent-sys.md)
  - [维测日志错误码](errorcode-loglibrary-sys.md)
    <!--DelEnd-->
