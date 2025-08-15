# UI高性能开发
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @wild-mucor-->
<!--Designer: @wild-mucor-->
<!--Tester: @sally__-->
<!--Adviser: @ge-yafang-->

优化应用的性能对于提升用户体验至关重要。当发现性能问题后，一般可按照以下步骤进行分析：
1. 复现问题：开发者根据用户的反馈复现性能问题是分析的第一步，开发者可在通过回访用户或在应用中增加自己的性能监测埋点来获得性能问题的发生场景和复现步骤。
2. 利用工具找到性能瓶颈点：问题复现后可使用DevEco Studio中提供的CPU Profiler工具获取问题发生过程中的Trace，通过Trace可以方便的找到耗时点针对性优化。
3. 确定解决方案：找到耗时点后可以根据Trace中的ArkTS CallStack信息或Review流程相关业务代码来找到瓶颈点相关的实现，根据下面的核心优化思路对问题代码进行优化。
4. 验证解决效果：优化代码修改后，应重新复现问题场景体验效果，并使用CPU Profiler工具抓取Trace，确认修改符合预期，问题解决。

## UI性能优化的核心思路

### 工具驱动优化
性能优化的过程中使用数据而非直觉指导优化方向是提升优化效率的关键。当前DevEco Studio中提供了两个性能分析工具，可以进行UI的性能分析，帮助我们高效的进行性能问题定位：
1. CPU Profiler：用于在运行过程中抓取trace和调用栈对耗时点进行分析，使用方法可以参考<!--RP1-->[CPU Profiler的使用指导](../performance/application-performance-analysis.md)<!--RP1End-->分析的思路可以参考<!--RP2-->[常用Trace的含义](../performance/common-trace-using-instructions.md)<!--RP2End-->。
2. ArkUI Inspector：用于可视化的展示UI组件树，分析UI的布局层次和参数，使用方法可以参考<!--RP3-->[ArkUI Inspector使用说明](../performance/arkUI-inspector.md)<!--RP3End-->。
在分析性能问题的过程中，应当先通过CPU Profiler工具确实的发现性能瓶颈点，再针对性的进行优化。

### 惰性加载优先
推迟非可视区域的资源消耗可有效的加快应用启动和页面的切换速度。ArkUI提供了[LazyForEach](state-management/arkts-rendering-control-lazyforeach.md)组件来支持应用方便的进行数据的懒加载。

### 布局计算简化
应用开发中的UI布局是用户与应用程序交互的关键部分。不合理的布局越多，视图的创建、布局、渲染等流程所需的时间就越长。因此，减少嵌套层次或者使用高性能布局节点，可以减少丢帧卡顿。可以参考这些<!--RP4-->[布局技巧](../performance/reduce-view-nesting-levels.md)来优化布局性能<!--RP4End-->。

### 更新代替重建
对于会反复使用的组件，可将其缓存起来，用更新代替重建来提升性能。例如，在滚动容器的滑动过程中，一边的组件划出可视范围被释放，另一边的组件划入可视范围需要创建，反复的释放和创建相同的ListItem显然是冗余的。针对这一需要对特定组件进行缓存、复用的场景，ArkUI提供了[组件复用能力](state-management/arkts-reusable.md)，可以对自定义组件进行标记，在被标记的自定义组件释放时将其放入缓存池，再下次需要创建时从缓存池中拿出，用刷新代替创建。使用场景可以参考<!--RP5-->[组件复用的基本原理和使用技巧](../performance/component-reuse-overview.md)<!--RP5End-->。

### 状态精确控制
[状态管理](state-management/arkts-state-management-overview.md)是ArkUI声明式的核心机制，它负责将数据与UI联系起来，在UI刷新的过程中会反复执行状态管理的相关逻辑，状态变量的创建和与UI组件的绑定关系是影响刷新效率的关键。开发者需要根据实际的场景[正确使用状态管理](state-management/properly-use-state-management-to-develope.md)，同时在使用的过程中应注意[状态管理的使用技巧](state-management/arkts-state-management-best-practices.md)。
