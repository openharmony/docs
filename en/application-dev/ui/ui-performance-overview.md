# High-Performance UI Development

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zjucx1-->
<!--Designer: @zjucx1-->
<!--Tester: @liujiang077-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=39f66a31c4cd77f8015af575d95ace022de7992b translatedAt=2026-08-05T10:15:16.352Z pushedAt=2026-08-06T07:22:03.097Z -->

Optimizing application performance is crucial for enhancing user experience. When performance issues are detected, the analysis can generally follow these steps:

1. Reproduce the issue: Obtain the scenarios and reproduction steps by contacting users for feedback or adding performance instrumentation within the application.

2. Identify performance bottlenecks using tools: After the issue is reproduced, the CPU Profiler tool provided in DevEco Studio can be used to capture traces during the issue occurrence, making it easy to locate time-consuming points in the trace.

3. Determine solutions: Once bottlenecks are identified, you can use ArkTS CallStack information in the trace or review related service code to locate the implementation causing the bottleneck. Core optimization strategies can then be applied to the problematic code.

4. Verify results: After optimizing the code, reproduce the issue scenario again to verify the effect. Use the CPU Profiler to capture traces and confirm that the modification resolves the problem as expected.

## Core Strategies for UI Performance Optimization

### Tool-Driven Optimization

During performance optimization, using data rather than intuition to guide the optimization direction is key to improving optimization efficiency. DevEco Studio currently provides two performance analysis tools for UI performance analysis, helping to efficiently locate performance issues:

1. CPU Profiler: captures traces and call stacks during runtime to analyze bottlenecks. For details about the usage instructions, see <!--RP1-->[CPU Profiler](../performance/application-performance-analysis.md)<!--RP1End-->. For details about the trace interpretation, see <!--RP2-->[Typical Traces](../performance/common-trace-using-instructions.md)<!--RP2End-->.

2. ArkUI Inspector: visualizes the UI component tree and analyzes layout hierarchy and parameters. For details about the usage instructions, see <!--RP3-->ArkUI Inspector<!--RP3End-->.

   When analyzing performance issues, actual performance bottlenecks should first be identified using the CPU Profiler tool, and then targeted optimizations should be applied.

### Lazy Loading Prioritization

Deferring resource consumption in non-visible areas can significantly speed up application startup and page transitions. ArkUI provides the [LazyForEach](rendering-control/arkts-rendering-control-lazyforeach.md) component to facilitate lazy data loading in applications.

### Layout Computation Simplification

UI layout is a critical part of user interaction. More complex or nested layouts increase the time required for view creation, layout, and rendering. Reducing nesting levels or using high-performance layout nodes can minimize frame drops and stuttering. For guidance, see <!--RP4-->[Improving Layout Performance](../performance/reduce-view-nesting-levels.md)<!--RP4End-->.

### Update Instead of Rebuild

For components that are used repeatedly, they can be cached and updated instead of being rebuilt to improve performance. For example, during scrolling in a scroll container, components on one side are released as they scroll out of the visible area, while components on the other side need to be created as they scroll into view. Repeatedly releasing and creating the same ListItem is clearly redundant. To address this scenario where specific components need to be cached and reused, ArkUI provides the [component reuse capability](state-management/arkts-reusable.md), which allows custom components to be marked so that they are placed into a cache pool when released and retrieved from the cache pool when they need to be created again, using updates instead of creation. For usage scenarios, see <!--RP5-->Basic Principles and Usage Tips for Component Reuse<!--RP5End-->.

### Precise State Control

[State management](state-management/arkts-state-management-overview.md) is the core declarative mechanism in ArkUI, linking data with the UI. During UI refresh, state management logic is executed repeatedly. The creation of state variables and their binding to UI components is crucial for refresh efficiency. Therefore, it is recommended that you refer to the [state management FAQs](state-management/arkts-state-management-faq.md) during development.