# 性能打点跟踪概述

hiTraceMeter是用于追踪进程轨迹，度量程序执行性能的一种工具，基于内核的ftrace机制，提供给用户态应用代码执行时长度量打点的能力。开发者通过使用hiTraceMeter API在程序中打点，并使用hiTraceMeter提供的命令行工具采集跟踪数据。

## 基本概念

- **hiTraceMeter Tag**

  跟踪数据使用类别分类，称作hiTraceMeter Tag或hiTraceMeter Category，一般每个软件子系统对应一个Tag，该Tag在打点API中以类别Tag参数传入。hiTraceMeter命令行工具采集跟踪数据时，只采集给定的Tag类别选项指定的跟踪数据。

## 运作机制

- 应用程序通过hiTraceMeter函数接口进行打点，hiTraceMeter函数将跟踪数据通过内核sysfs文件接口输出到内核的ftrace数据缓冲区。
- hiTraceMeter命令行工具读取内核ftrace缓冲区中的跟踪数据，将文本格式的跟踪数据保存到设备侧的文件中。

## 约束与限制

由于JS程序的异步IO特性，现在hiTraceMeter只提供了异步接口。