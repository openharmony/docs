# 应用性能最佳实践

本文简要介绍了用于在OpenHarmony上提升应用性能的最佳实践。

用户期望应用能够快速启动、及时响应、无卡顿，本文将提供提升应用启动和响应速度、减少丢帧卡顿的一些方法和案例供应用开发者参考。

- 提升应用启动和响应速度

  - [提升应用冷启动速度](http://gitee.com/sqsyqqy/docs/blob/master/zh-cn/application-dev/performance/improve-application-startup-and-response/improve-application-cold-start-speed.md)

      应用启动时延是影响用户体验的关键要素。提升应用冷启动速度，建议在以下四个阶段进行优化：

      ​	1、应用进程创建&初始化阶段

      ​	2、Application&Ability初始化阶段

      ​	3、Ability生命周期阶段

      ​	4、加载绘制首页阶段

  - [提升应用响应速度](http://gitee.com/sqsyqqy/docs/blob/master/zh-cn/application-dev/performance/improve-application-startup-and-response/improve-application-response.md)

     应用对用户的输入需要快速反馈，以提升交互体验。建议通过避免主线程被非UI任务阻塞、减少组件刷新的数量的方法来提升应用响应速度。

- 减少丢帧卡顿

  - [减少视图嵌套层次](http://gitee.com/sqsyqqy/docs/blob/master/zh-cn/application-dev/performance/reduce-frame-loss-and-frame-freezing/reduce-view-nesting-levels.md)

     应用将布局渲染到屏幕上的流畅度影响用户对质量的感知。建议移除多余的嵌套层次减少视图嵌套层次。

  - [减少动画丢帧](http://gitee.com/sqsyqqy/docs/blob/master/zh-cn/application-dev/performance/reduce-frame-loss-and-frame-freezing/reduce-animation-frame-loss.md)
  
      应用播放动画的流畅度是影响用户体验的重要因素。建议通过使用系统提供的动效API来减少动画丢帧。
