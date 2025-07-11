# Performance Analysis Kit（性能分析服务）<!--performance-analysis-kit-->

- [Performance Analysis Kit简介](performance-analysis-kit-overview.md)
- HiLog使用指导<!--hilog-dev-->
  - [使用HiLog打印日志（ArkTS）](hilog-guidelines-arkts.md)
  - [使用HiLog打印日志（C/C++）](hilog-guidelines-ndk.md)
- HiAppEvent使用指导<!--hiappevent-->
  - [HiAppEvent介绍](hiappevent-intro.md)
  - 事件订阅<!--event-subscription-->
    - 应用事件<!--app-event-->
      - [订阅应用事件（ArkTS）](hiappevent-watcher-app-events-arkts.md)
      - [订阅应用事件（C/C++）](hiappevent-watcher-app-events-ndk.md)
    - 系统事件<!--system-events-->
      - 崩溃事件<!--crash-events-->
        - [崩溃事件介绍](hiappevent-watcher-crash-events.md)
        - [订阅崩溃事件（ArkTS）](hiappevent-watcher-crash-events-arkts.md)
        - [订阅崩溃事件（C/C++）](hiappevent-watcher-crash-events-ndk.md)
      - 卡死事件<!--freeze-events-->
        - [卡死事件介绍](hiappevent-watcher-freeze-events.md)
        - [订阅卡死事件（ArkTS）](hiappevent-watcher-freeze-events-arkts.md)
        - [订阅卡死事件（C/C++）](hiappevent-watcher-freeze-events-ndk.md)
      - 资源泄漏事件<!--resource-leak-events-->
        - [资源泄漏事件介绍](hiappevent-watcher-resourceleak-events.md)
        - [订阅资源泄漏事件（ArkTS）](hiappevent-watcher-resourceleak-events-arkts.md)
        - [订阅资源泄漏事件（C/C++）](hiappevent-watcher-resourceleak-events-ndk.md)
      - 踩内存事件<!--address-sanitizer-events-->
        - [踩内存事件介绍](hiappevent-watcher-address-sanitizer-events.md)
        - [订阅踩内存事件（ArkTS）](hiappevent-watcher-address-sanitizer-events-arkts.md)
        - [订阅踩内存事件（C/C++）](hiappevent-watcher-address-sanitizer-events-ndk.md)
      - 主线程超时事件<!--main-thread-jank-events-->
        - [主线程超时事件介绍](hiappevent-watcher-mainthreadjank-events.md)
        - [订阅主线程超时事件（ArkTS）](hiappevent-watcher-mainthreadjank-events-arkts.md)
        - [订阅主线程超时事件（C/C++）](hiappevent-watcher-mainthreadjank-events-ndk.md)
      - 任务执行超时事件
        - [任务执行超时事件介绍](hiappevent-watcher-apphicollie-events.md)
        - [订阅任务执行超时事件（C/C++）](hiappevent-watcher-apphicollie-events-ndk.md)
      - 应用查杀事件<!--app-killed-events-->
        - [应用查杀事件介绍](hiappevent-watcher-app-killed-events.md)
        - [订阅应用查杀事件（ArkTS）](hiappevent-watcher-app-killed-events-arkts.md)
        - [订阅应用查杀事件（C/C++）](hiappevent-watcher-app-killed-events-ndk.md)
  <!--Del-->
  - [事件上报](hiappevent-event-reporting.md)
  <!--DelEnd-->
- HiTraceMeter使用指导<!--hitracemeter-->
  - [使用HiTraceMeter跟踪性能（ArkTS）](hitracemeter-guidelines-arkts.md)
  - [使用HiTraceMeter跟踪性能（C/C++）](hitracemeter-guidelines-ndk.md)
  - [查看HiTraceMeter日志](hitracemeter-view.md)
- HiTraceChain使用指导<!--hitracechain-->
  - [使用HiTraceChain打点（ArkTS）](hitracechain-guidelines-arkts.md)
  - [使用HiTraceChain打点（C/C++）](hitracechain-guidelines-ndk.md)
- HiChecker使用指导<!--hichecker-->
  - [使用HiChecker检测问题（ArkTS/JS）](hichecker-guidelines-arkts.md)
- HiDebug使用指导<!--hidebug-->
  - [使用HiDebug获取调试信息（ArkTS）](hidebug-guidelines-arkts.md)
  - [使用HiDebug获取调试信息（C/C++）](hidebug-guidelines-ndk.md)
- HiCollie使用指导<!--hicollie-->
  - [使用HiCollie检测业务线程卡死卡顿问题（C/C++）](hicollie-guidelines-ndk.md)
  - [使用HiCollie监控函数执行时间超长问题（C/C++）](hicollie-settimer-guidelines-ndk.md)
- 错误管理<!--error-manager-->
  - [错误管理开发指导](errormanager-guidelines.md)
  - [应用恢复开发指导](apprecovery-guidelines.md)
- 故障分析<!--fault-analysis-->
  - [分析JS Crash（进程崩溃）](jscrash-guidelines.md)
  - [分析CppCrash（进程崩溃）](cppcrash-guidelines.md)
  - [分析AppFreeze（应用无响应）](appfreeze-guidelines.md)
- 命令行工具<!--perform-command-line-utilities-->
  - [hdc](hdc.md)
  - [hilog](hilog.md)
  - [hidumper](hidumper.md)
  - [hitrace](hitrace.md)
  - [hiperf](hiperf.md)
  <!--Del-->
  - [hisysevent](hisysevent.md)
  - [uinput](uinput.md)
  <!--DelEnd-->
