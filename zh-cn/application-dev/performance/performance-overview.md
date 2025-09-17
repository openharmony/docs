# 应用性能优化概览

优化应用性能对于应用开发至关重要。通过高性能编程、减少丢帧卡顿、提升应用启动和响应速度，可以有效提升用户体验。本文将介绍一些优化应用性能的方法，以及常用的性能调优工具。

## ArkTS高性能编程

为了提升代码执行速度，进而提升应用整体性能，可以采取以下措施：
- **[使用ArkTS高性能编程实践](high-performance-programming.md)：**
    更有利于方舟编译运行时进行编译优化，生成更高性能的机器码，保障程序运行得更快。
    
- **使用AOT模式对应用进行编译优化：**
    方舟编译运行时通过采用PGO(Profile-Guided-Optimization，配置文件引导型优化)方式，提前生成高性能机器码，从而提升程序运行速度。
## 减少丢帧卡顿

丢帧卡顿是指应用在运行时出现卡顿或者画面不流畅的现象。为了[合理使用动画](reasonable-using-animation.md)，可以采取以下措施：

- **避免在主线程上执行耗时操作：**
  UI主线程是应用中最重要的线程之一，在主线程上执行耗时操作会阻塞UI渲染，从而导致UI主线程的负载过高。因此，可以将耗时操作放在[TaskPool或者Worker](../arkts-utils/taskpool-vs-worker.md)等后台线程中执行。
  
- **减少渲染进程的冗余开销：**
  使用资源图代替绘制、合理使用renderGroup、尺寸位置设置尽量使用整数，可以减少渲染所需的时间，从而减少丢帧卡顿。
  
- **避免频繁更新UI：**
  减少不必要的UI更新操作，例如过多的界面刷新或布局计算。
  
- **[优化布局性能](reduce-view-nesting-levels.md)：**
   应用开发中的用户界面（UI）布局是用户与应用程序交互的关键部分。不合理的布局越多，视图的创建、布局、渲染等流程所需的时间就越长。因此，减少嵌套层次或者使用高性能布局节点，可以减少丢帧卡顿。
  
- **组件复用配合LazyForEach：**
  使用ArkUI开发范式提供的[组件复用](component-recycle.md)机制，通过重复利用已经创建过并缓存的组件对象，降低组件短时间内频繁创建和销毁的开销，提升组件加载效率，降低UI线程负载，从而减少丢帧卡顿。
  
- **[精确控制状态变量的关联组件数](precisely-control-render-scope.md)：**
  @State等状态变量关联组件越多，状态数据变更时刷新的组件越多，UI线程负载越重，因此移除冗余的组件关联可以减少丢帧卡顿。
  
- **在对象上谨慎使用状态变量关联（[合理进行状态管理](proper_state_management.md)）：**
  对象中的任何一个成员变量发生变更均会引起对象关联组件的刷新，因此应对有状态变量关联的对象进行最小化处理，从而减少丢帧卡顿。
  
## 提升应用启动和响应速度

应用启动和响应速度是用户体验的重要组成部分。为了[提升应用启动](improve-application-cold-start-speed.md)和[响应速度](improve-application-response.md)，可以采取以下措施：

- **延迟加载：**
  将不必要的资源延迟加载可以减少应用启动时间。使用[List](../reference/apis-arkui/arkui-ts/ts-container-list.md)、[Grid](../reference/apis-arkui/arkui-ts/ts-container-grid.md)以及[Swiper](../reference/apis-arkui/arkui-ts/ts-container-swiper.md)等容器组件时，配合系统提供的[LazyForEach数据懒加载](../ui/rendering-control/arkts-rendering-control-lazyforeach.md)能力，可以有效减少应用启动时间和内存占用。
  
- **使用缓存：**
  选择合适的[缓存策略](list-perf-improvment.md#缓存列表项)可以提高应用程序的性能和响应速度，从而提升应用响应速度。
  
- **使用异步加载：**
  使用异步加载([异步并发概述](../arkts-utils/async-concurrency-overview.md))可以在后台线程中处理耗时操作，从而提升应用响应速度。

## 使用性能调优工具

使用性能调优工具可以帮助开发者找出应用中的性能问题。以下是DevEco Studio提供的一些常用性能调优工具：

- **ArkUI Inspector：**
  用于检查和调试应用程序页面布局的情况。
  
- **Launch Profiler：**
  分析启动过程中各阶段的性能问题。

- **Frame Profiler：**
  用于深度分析应用或服务卡顿丢帧的原因。
  
- **Time Profiler：**
  在应用/服务运行时， 展示热点区域内基于 CPU 和进程耗时分析的调用栈情况。
  
- **Allocation Profiler：**
  实时监测应用或服务内存使用情况。
  
- **Snapshot Profiler：**
  用于分析应用程序内存使用情况。
  
- **[CPU Profiler](application-performance-analysis.md)：**
  可以监测应用的CPU使用情况。