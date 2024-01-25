# Application Performance Improvement Overview

Performance is a crucial factor of application development. Users expect applications to perform seamlessly and smoothly. As application performance largely relies on programming, frame rate, launch and response times, we can optimize these aspects to improve user experience. This document offers a few steps you can follow to improve your application performance, as well as a lineup of useful performance profiling tools.

## ArkTS High-Performance Programming

To drive code execution speed – a key facet of application performance, try the following:
- **Follow the [ArkTS high-performance programming practices](high-performance-programming.md).**
  
    Following these practices can bring in better compilation optimization by ArkCompiler, greater performant machine code, and faster program running.
    
- **Use the AOT mode to compile and optimize applications.**
  
    ArkCompiler uses Profile-Guided-Optimization (PGO) to generate performant machine code ahead of time (AOT), speeding up applications.
## Reducing Frame Freezing

When frame freezing occurs, the user experiences stutters and lags in the application. To reduce frame freezing and [frame loss](reduce-animation-frame-loss.md), you can take the following measures:

- **Avoid long-running tasks on the main thread.**
  
  The main thread, also called UI thread, is one of the most important threads in an application. Long-running tasks on the main thread can block UI rendering and result in overloading of the main thread. To minimize main thread work, execute long-running tasks on background threads such as [TaskPool or Worker](../arkts-utils/taskpool-vs-worker.md).
  
- **Reduce the redundant overhead of the rendering process.**
  
  To lower the rendering overhead, use resource diagrams instead of drawing, properly use **renderGroup**, and set the size and position to integers.
  
- **Avoid frequent UI updates.**
  
  Reduce unnecessary UI update operations, such as excessive UI refresh and layout calculation.
  
- **[Improving layout performance](reduce-view-nesting-levels.md).**
  
  Layouts in the user interface (UI) are a key part of interactions between users and your application. Poorly designed layouts can lead to a slow UI, from component creation and layout to rendering. To improve layout performance, reduce nesting and prioritize high-performance layout nodes.
  
- **Reuse components with LazyForEach.**
  
  Combine ArkUI's [component reuse](component-recycle.md) mechanism and **LazyForEach** syntax to efficiently reuse component objects that have been created and cached. In this way you can have lower overhead in frequent component creation and destruction, faster component loading, and less UI thread load.
  
- **[Precisely control the number of associated components for state variables](precisely-control-render-scope.md).**
  
  When components are associated with state variables (such as @State decorated variables), they are re-rendered when the state data changes. The more components associated, the more components re-rendered, and the heavier the UI thread load. By precisely controlling the number of associated components, you can create a better responsive UI.
  
- **[Carefully use state variable associated objects](proper_state_management.md).**
  
  If any member variable in an object changes, the components associated with the object are updated. Therefore, it is better to minimize objects associated with state variables.
## Improving Application Startup and Response Times

Users expect applications to be loading fast and highly responsive. To improve the [application startup](improve-application-cold-start-speed.md) and [response times](improve-application-response.md), you can take the following measures:

- **Delay loading.**
  
  Delaying loading of unnecessary resources can speed up application startup. When using container components such as [\<List>](../reference/arkui-ts/ts-container-list.md), [\<Grid>](../reference/arkui-ts/ts-container-grid.md), and [\<Swiper>](../reference/arkui-ts/ts-container-swiper.md), make sure of the provided [LazyForEach](../quick-start/arkts-rendering-control-lazyforeach.md) capability to effectively reduce the application startup time and memory usage.
  
- **Use cache.**
  
  Adoption of a proper [cache policy](list-perf-improvment.md#caching-list-items) can improve the performance and responsiveness of applications.
  
- **Adopt asynchronous concurrency.**
  
  [Asynchronous concurrency](../arkts-utils/async-concurrency-overview.md) allows an application to process time-consuming operations in background threads, thereby improving application responsiveness.

## Using Performance Profiling Tools

With performance profiling tools, you can identify performance issues in applications and make informed improvements. DevEco Studio provides the following powerful performance profiling tools:

- **ArkUI Inspector**
  
  Use to inspect and debug the page layout of an application.
  
- **Launch Profiler**
  

Use to identify performance issues with each phase of the launch process.

- **Frame Profiler**
  
  Use to take a deep dive into the root causes of frame freezing in the application or service.
  
- **Time Profiler**
  
  Use to gain visibility into the call stacks in hotspot areas based on CPU and process time consumption analysis during running of the application or service.
  
- **Allocation Profiler**
  
  Use to monitor in real time memory usage of the application or service.
  
- **Snapshot Profiler**
  
  Use to analyze the memory usage of the application.
  
- **[CPU Profiler](application-performance-analysis.md)**
  
  Use to monitor CPU usage of the application.

 <!--no_check--> 