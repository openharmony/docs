# Performance Analysis Kit<!--performance-analysis-kit-->

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @mzyan-->
<!--Designer: @liyueric-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

- [Introduction to Performance Analysis Kit](performance-analysis-kit-overview.md)
- Fault Detection<!--fault-analysis-->
  - [Overview](fault-detection-overview.md)
  - Crash Detection<!--crash-detection-->
    - [Crash Detection Overview](crash-detection-overview.md)
    - [JS Crash (Process Crash) Detection](jscrash-guidelines.md)
    - [C++ Crash (Process Crash) Detection](cppcrash-guidelines.md)
  - [Address Sanitizer detection](address-sanitizer-guidelines.md)
  - [Application Freeze Detection](appfreeze-guidelines.md)
  - [Task Timeout Detection](apptask-timeout-guidelines.md)
  - [Application Killed Detection](appkilled-guidelines.md)
- Log Printing<!--hilog-dev-->
  - [Using HiLog (ArkTS)](hilog-guidelines-arkts.md)
  - [Using HiLog (C/C++)](hilog-guidelines-ndk.md)
- Event Subscription<!--event-subscription-->
  - [Introduction to HiAppEvent](hiappevent-intro.md)
  - Using HiAppEvent to Subscribe to Events<!--event-subscription-->
    - [Event Subscription Overview](event-subscription-overview.md)
    - [Event Subscription (ArkTS)](hiappevent-watcher-app-events-arkts.md)
    - [Event Subscription (C/C++)](hiappevent-watcher-app-events-ndk.md)
    - System Events<!--system-events-->
      - Crash Events<!--crash-events-->
        - [Crash Event Overview](hiappevent-watcher-crash-events.md)
        - [Subscribing to Crash Events (ArkTS)](hiappevent-watcher-crash-events-arkts.md)
        - [Subscribing to Crash Events (C/C++)](hiappevent-watcher-crash-events-ndk.md)
      - Application Freeze Events<!--freeze-events-->
        - [Application Freeze Event Overview](hiappevent-watcher-freeze-events.md)
        - [Subscribing to Application Freeze Events (ArkTS)](hiappevent-watcher-freeze-events-arkts.md)
        - [Subscribing to Application Freeze Events (C/C++)](hiappevent-watcher-freeze-events-ndk.md)
      - Resource Leak Events<!--resource-leak-events-->
        - [Resource Leak Event Overview](hiappevent-watcher-resourceleak-events.md)
        - [Subscribing to Resource Leak Events (ArkTS)](hiappevent-watcher-resourceleak-events-arkts.md)
        - [Subscribing to Resource Leak Events (C/C++)](hiappevent-watcher-resourceleak-events-ndk.md)
      - Address Sanitizer Events<!--address-sanitizer-events-->
        - [Address Sanitizer Event Overview](hiappevent-watcher-address-sanitizer-events.md)
        - [Subscribing to Address Sanitizer Events (ArkTS)](hiappevent-watcher-address-sanitizer-events-arkts.md)
        - [Subscribing to Address Sanitizer Events (C/C++)](hiappevent-watcher-address-sanitizer-events-ndk.md)
      - Main Thread Jank Events<!--main-thread-jank-events-->
        - [Main Thread Jank Event Overview](hiappevent-watcher-mainthreadjank-events.md)
        - [Subscribing to Main Thread Jank Events (ArkTS)](hiappevent-watcher-mainthreadjank-events-arkts.md)
        - [Subscribing to Main Thread Jank Events (C/C++)](hiappevent-watcher-mainthreadjank-events-ndk.md)
      - Task Execution Timeout Events<!--app-hicollie-events-->
        - [Task Execution Timeout Event Overview](hiappevent-watcher-apphicollie-events.md)
        - [Subscribing to Task Execution Timeout Events (ArkTS)](hiappevent-watcher-apphicollie-events-arkts.md)
        - [Subscribing to Task Execution Timeout Events (C/C++)](hiappevent-watcher-apphicollie-events-ndk.md)
      - Application Killed Events<!--app-killed-events-->
        - [Application Killed Event Overview](hiappevent-watcher-app-killed-events.md)
        - [Subscribing to Application Killed Events (ArkTS)](hiappevent-watcher-app-killed-events-arkts.md)
        - [Subscribing to Application Killed Events (C/C++)](hiappevent-watcher-app-killed-events-ndk.md)
  <!--Del-->
  - [Event Reporting](hiappevent-event-reporting.md)
  <!--DelEnd-->
  - [HiAppEvent FAQs](hiappevent-faq.md)
- Performance Tracing<!--hitracemeter-->
  - [Introduction to HiTraceMeter](hitracemeter-intro.md)
  - [Using HiTraceMeter (ArkTS)](hitracemeter-guidelines-arkts.md)
  - [Using HiTraceMeter (C/C++)](hitracemeter-guidelines-ndk.md)
  - [Viewing HiTraceMeter Logs](hitracemeter-view.md)
- Distributed Call Chain Tracing<!--hitracechain-->
  - [Introduction to HiTraceChain](hitracechain-intro.md)
  - [Using HiTraceChain (ArkTS)](hitracechain-guidelines-arkts.md)
  - [Using HiTraceChain (C/C++)](hitracechain-guidelines-ndk.md)
- Check Mode<!--hichecker-->
  - [Using HiChecker(ArkTS)](hichecker-guidelines-arkts.md)
- Obtaining System Debugging Information<!--hidebug-->
  - [Introduction to HiDebug](hidebug-guidelines.md)
  - [Using HiDebug APIs (ArkTS)](hidebug-guidelines-arkts.md)
  - [Using HiDebug APIs (C/C++)](hidebug-guidelines-ndk.md)
- Service Thread Timeout Detection<!--hicollie-->
  - [Using HiCollie to Detect Service Thread Stuck and Jank Events](hicollie-guidelines-ndk.md)
  - [Using HiCollie to Monitor the Function Execution Time (C/C++)](hicollie-settimer-guidelines-ndk.md)
- Error Manager and Application Recovery<!--error-manager-->
  - [Development of Error Manager](errormanager-guidelines.md)
  - [Development of Application Recovery](apprecovery-guidelines.md)
- [Performance Analysis Kit Terminology](performance-analysis-kit-terminology.md)
- Command Line Tools<!--perform-command-line-utilities-->
  - [hdc](hdc.md)
  - [hilog](hilog.md)
  - [hidumper](hidumper.md)
  - [hitrace](hitrace.md)
  - [hiperf](hiperf.md)
  - [hiprofiler](hiprofiler.md)
  - [uinput](uinput.md)
  <!--Del-->
  - [hisysevent](hisysevent.md)
  <!--DelEnd-->
