# App Killed（应用查杀）检测

## 简介

应用闪退指应用在使用过程中突然异常终止。当应用行为异常，比如消耗过多CPU、内存等系统资源时，系统为了保持整机健康状态，会按照规则挑选应用进行查杀，通常通过服务进程向应用发送SIGKILL信号（信号值是9）来实现查杀的。操作系统对SIGKILL的默认行为是不生成栈日志等维测信息的，导致应用闪退时faultlogger中无日志。

## 基本概念

应用退出通常包含以下几种情况：

1. 应用自身发生异常或主动抛出异常，例如因SIGSEGV、SIGABRT触发的CPP_CRASH异常，系统可监控并记录维测日志。

2. 用户主动终止应用，例如在任务列表中点击清理按钮以清除所有应用，或上划清除单个应用，不会生成栈等维测日志。

3. 应用开发者主动调用exit系统调用时，不会生成栈等维测日志。

4. 应用发生主线程堵塞，导致界面冻结，通常会生成APP_FREEZE日志。

5. 资源使用过度将导致系统进行管控查杀，并提供详细的维测信息。例如，应用发生内存泄漏时，通常会生成资源泄漏类的维测日志。开发者可以通过HiAppEvent订阅RESOURCE_OVERLIMIT获取这些信息。

6. 系统管控查杀时，无法提供详细的维测信息，比如LowMemoryKiller、应用的RSS内存超过4G、快速泄漏等，不会生成RESOURCE_OVERLIMIT维测日志。

本节主要覆盖在场景5和6中因SIGKILL信号导致的管控查杀。

## 实现原理

1. 内核和服务进程都会监控系统资源。

2. 发现异常后，选择应用进行查杀。

3. 系统在触发应用查杀时会添加系统事件打点。

4. 打点事件中包含uid、包名、前后台信息、查杀原因和维测信息。

## 约束和限制

1. 应用需先通过HiAppEvent订阅，才能接收查杀事件。

2. 查杀事件发布给应用是异步的，应用需在下次启动时才能接收到。

3. 目前系统的查杀行为会随着版本演进而不断新增，因此不能保证当前的查杀机制是系统的全部。

## 触发场景

系统中可能有以下触发应用查杀的场景:

1. 应用的内存、CPU和IO类负载超过一定限额，文件句柄和线程数量超标。

2. 整机低内存时，会根据内存使用情况和优先级对应用进行查杀。

3. 功耗类检查，包括应用Binder调用导致频繁唤醒、音频播放或录音导致系统无法冻结、GPS或蓝牙等外设使用异常问题。

## 感知方式

应用可以通过两种方式感知到被异常查杀。

1. 从元能力的Ability的onCreate回调参数中获取查杀原因。具体为LaunchParam启动参数中的LastExitReason字段，请参考[元能力LastExitReason章节](../reference/apis-ability-kit/js-apis-app-ability-abilityConstant.md)。

2. 通过HiAppEvent订阅APP_KILLED事件。订阅方式请参考[HiAppEvent章节](hiappevent-watcher-app-killed-events.md)。

## 分析思路和分析步骤

1. 从Ability的onCreate回调参数中获取查杀原因。

    可以参考下表进行处理。

    | lastExitReason(enum) | lastExitMessage(string)  | 产生原因                                             | 处理策略                                                     |
    | -------------------- | ------------------------ | ---------------------------------------------------- | ------------------------------------------------------------ |
    | APP_FREEZE           | APP_FREEZE               | 由于watchdog检测出应用Freeze故障，导致应用程序退出。 | 通过HiAppEvent订阅APP_FREEZE事件，到APP_FREEZE事件中去匹配。 |
    | RESOURCE_CONTROL     | CPU Highload             | CPU高负载。                                          | 尝试降低应用自身的CPU负载。                                  |
    | RESOURCE_CONTROL     | CPU_EXT Highload         | 快速CPU负载检测。                                    | 尝试降低应用自身的CPU负载。                                  |
    | RESOURCE_CONTROL     | IO Manager Control       | I/O管控。                                            | 尝试降低应用自身的I/O。                                      |
    | RESOURCE_CONTROL     | App Memory Deterioration | 应用内存超限劣化。                                   | 尝试通过HiAppEvent订阅RESOURCE_OVERLIMIT获取更多日志。       |
    | RESOURCE_CONTROL     | Temperature Control      | 温度管控。                                           | 尝试降低应用自身的CPU负载。                                  |
    | RESOURCE_CONTROL     | Memory Pressure          | 整机低内存触发按优先级由低到高查杀。                 | 尝试降低应用自身的内存占用，以减少被整机查杀策略选中的概率。 |

2. 通过HiAppEvent订阅APP_KILLED事件。

    通过APP_KILLED事件，可以获取查杀原因、应用前后台等关键信息，对照下表进行处理：

    | reason(string)                | 产生原因                                                     | 处理策略                                                     | 是否应用自身异常触发管控 | 是否有关联事件 |
    | ----------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------ | -------------- |
    | LowMemoryKill                 | 同前面的lastExitMessage值为Memory Pressure场景，即整机低内存触发按优先级由低到高查杀。 | 尝试降低应用自身的内存占用，以减少被整机查杀策略选中的概率。 | 否                       | 否             |
    | SwapFull                      | Swap交换空间接近占满，可能存在个别进程内存泄漏，或者是后台进程个数太多。 | 尝试降低应用自身的内存占用，以减少被整机查杀策略选中的概率。 | 否                       | 否             |
    | ResourceLeak(IonLeak)         | 应用占用的ION内存超标。                                      | 尝试通过HiAppEvent订阅RESOURCE_OVERLIMIT获取更多的ION内存日志，找到泄漏点后，降低应用自身的ION内存占用，一般来说是Image组件或者Pixmap泄漏导致。 | 是                       | 是             |
    | ResourceLeak(GpuRsLeak)       | 应用的ArkUI组件在render_service服务进程占用的GPU内存超标。   | 尝试降低应用ArkUI组件的GPU内存占用。                         | 是                       | 否             |
    | ResourceLeak(GpuLeak)         | 应用在本进程内占用的GPU内存（即自渲染产生的GPU内存）超标。   | 尝试通过HiAppEvent订阅RESOURCE_OVERLIMIT获取更多的GPU内存日志，找到泄漏点后，降低应用自渲染（使用XComponent组件）的GPU内存占用。 | 是                       | 是             |
    | ResourceLeak(AshmemLeak)      | 应用占用的ashmem内存超标。                                   | 尝试通过HiAppEvent订阅RESOURCE_OVERLIMIT获取更多的ashmem内存日志，找到泄漏点后，降低应用自身的ashmem内存占用，一般来说是Image组件或者Pixmap泄漏导致。 | 是                       | 是             |
    | IllegalAudioRendererBySuspend | 未申请合理的后台任务，但是后台有大量音频播放。               | 应用退至后台时，应避免不必要的后台音频播放，或者合理使用后台任务，具体参考[后台任务开发服务](../task-management/background-task-overview.md)。 | 是                       | 否             |
    | PowerSaveClean                | 整机切换到省电模式或应急模式。                               | 无需处理。                                                   | 否                       | 否             |
    | RssThresholdKiller            | 应用的RSS内存超一定阈值。                                    | 尝试降低应用自身的内存占用，避免出现RSS内存超过阈值的情况。  | 是                       | 否             |
    | OomKiller                     | 整机低内存触发了内核按一定策略进行应用查杀。                 | 尝试降低应用自身的内存占用，以减少被整机查杀策略选中的概率。 | 否                       | 否             |
    | CpaKiller                     | DRM(Digital Right Management)业务申请内存但是内存不足时，会按照一定策略查杀进程以回收内存。 | 尝试降低应用自身的内存占用，以减少被整机查杀策略选中的概率。 | 否                       | 否             |
