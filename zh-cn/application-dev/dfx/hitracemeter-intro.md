# HiTraceMeter介绍

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @qq_437963121-->
<!--Designer: @MontSaintMichel-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

本文介绍HitraceMeter接口的使用方法。开发者可以在代码中调用HitraceMeter接口进行trace打点，然后使用[hitrace命令行工具](hitrace.md)获取程序运行时产生的打点信息，了解程序运行的进程、线程、时间戳、CPU等信息，以帮助开发者进行问题分析和性能调优。


HitraceMeter提供ArkTs和C/C++两种接口，按需选择。


- [使用HiTraceMeter跟踪性能（ArkTS）](hitracemeter-guidelines-arkts.md)

- [使用HiTraceMeter跟踪性能（C/C++）](hitracemeter-guidelines-ndk.md)


## 实现原理

内核设置了一个缓冲区用于记录设备运行时产生的打点记录，并在sysfs中提供了trace_marker和trace节点：

trace_marker节点为只写节点，程序将打点信息写入到trace_marker节点后，打点信息会被存储到内核的缓冲区。HiTraceMeter提供的接口封装了写操作，应用可以调用这些接口将打点数据写入内核节点。

trace节点为只读节点，可从中读取系统当前缓冲区内的所有记录。hitrace命令行工具封装了对该节点的读取操作，开发者可使用命令将采集的打点信息显示在命令行或保存到设备文件中。

调用HitraceMeter接口生成的打点信息格式可查看[用户态trace格式说明](hitracemeter-view.md#用户态trace格式说明)。

**HiTraceMeter Tag**：跟踪数据使用类别，每个软件子系统对应一个tag。可以在hdc命令行中用“hitrace -l”命令查看所有的tag名及其简介。使用[hitrace](hitrace.md)命令行工具采集跟踪数据时，需要指定tag，采集结果仅包含指定tag类别的跟踪数据。应用中调用HiTraceMeter打点使用的tag是app。
