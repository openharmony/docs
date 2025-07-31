# 崩溃检测概述

广义上的进程崩溃是指应用或者系统进程非预期的退出。目前已知以下场景会发生进程非预期退出：

1. Native代码未处理崩溃异常信号时会生成CppCrash日志，详见[Cpp Crash（进程崩溃）检测](cppcrash-guidelines.md)。

2. JS/ArkTS代码未处理异常时会生成JsCrash日志，详见[JS Crash（进程崩溃）检测](jscrash-guidelines.md)。

3. 应用卡死后生成AppFreeze日志并被强制终止退出，详见[AppFreeze（应用冻屏）检测](appfreeze-guidelines.md)。
