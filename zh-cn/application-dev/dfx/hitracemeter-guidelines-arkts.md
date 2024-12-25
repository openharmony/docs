# 使用HiTraceMeter跟踪性能（ArkTS/JS）

## 简介

HiTraceMeter提供系统性能打点接口。开发者通过在关键代码位置调用HiTraceMeter接口提供的API接口，能够有效跟踪进程轨迹、查看系统性能。

## 基本概念

**HiTraceMeter Tag**：跟踪数据使用类别分类，称作HiTraceMeter Tag或HiTraceMeter Category。一般每个软件子系统对应一个Tag，该Tag在打点API中以类别Tag参数传入。HiTraceMeter命令行工具采集跟踪数据时，只采集给定的Tag类别选项指定的跟踪数据。

## 实现原理

1. 应用程序通过HiTraceMeter函数接口进行打点，HiTraceMeter函数将跟踪数据通过内核sysfs文件接口输出到内核的ftrace数据缓冲区。

2. HiTraceMeter命令行工具读取内核ftrace缓冲区中的跟踪数据，将文本格式的跟踪数据保存到设备侧的文件中。

## 接口说明

性能打点跟踪接口由HiTraceMeter模块提供，详细API请参考[性能打点跟踪API参考](../reference/apis-performance-analysis-kit/js-apis-hitracemeter.md)。

| 接口名 | 描述 | 
| -------- | -------- |
| hiTraceMeter.startTrace(name: string, taskId: number) | 异步时间片跟踪接口，标记一个预跟踪耗时任务的开始。taskId是trace中用来表示关联的ID,如果有多个name相同的任务并行执行，则每次调用startTrace的taskId不同；如果具有相同name的任务是串行执行的，则taskId可以相同。 | 
| hiTraceMeter.finishTrace(name: string, taskId: number) | 异步时间片跟踪接口，name和taskId必须与流程开始的hiTraceMeter.startTrace对应参数值保持一致。 | 
| hiTraceMeter.traceByValue(name: string, value: number) | 整数跟踪接口，用来标记一个预跟踪的数值变量，该变量的数值会不断变化。 | 

HiTraceMeter打点接口按功能/行为分类，主要分三类：同步时间片跟踪接口、异步时间片跟踪接口和整数跟踪接口。无论同步时间片跟踪接口还是异步时间片跟踪接口，接口本身都是同步接口，不是异步接口，都用在同一线程中，不支持跨线程打点和分析。

- 同步时间片跟踪接口用于顺序执行的打点场景，目前ArkTS/JS暂未提供相关接口。
- 异步时间片跟踪接口用于在操作调用前开始打点，在操作完成后进行结束打点。异步跟踪的开始和结束由于不是顺序发生的，解析trace时需要通过唯一的taskid进行识别，taskid作为异步跟踪trace接口的参数传入。
- 整数跟踪接口用于跟踪数值变量。

## 开发步骤

在应用启动执行页面加载后，开始分布式跟踪；完成业务之后，停止分布式跟踪。

1. 新建一个ArkTS应用工程，在“Project”窗口点击“entry &gt; src &gt; main &gt; ets &gt; pages &gt; index”，打开工程中的“index.ets”文件；在页面执行加载后，在自己的业务中调用hiTraceMeter的接口，进行性能打点跟踪，以任务名name为myTraceTest为例， 示例代码如下：

   ```ts
   import hiTraceMeter from '@ohos.hiTraceMeter';
   
   @Entry
   @Component
   struct Index {
     @State message: string = 'Hello World';
   
     build() {
       Row() {
         Column() {
           Text(this.message)
             .fontSize(50)
             .fontWeight(FontWeight.Bold)
             .onClick(() => {
               this.message = 'Hello Hitrace';
                
               let traceCount = 0;
               // 第一个跟踪任务开始
               hiTraceMeter.startTrace("myTraceTest", 1001);
               // 开始计数任务
               traceCount++;
               hiTraceMeter.traceByValue("myTestCount", traceCount);
               // 业务流程
               console.log(`myTraceTest running, taskid: 1001`);
                 
               // 第二个跟踪任务开始，同时第一个跟踪的同名任务还没结束，出现了并行执行，对应接口的taskId需要不同。
               hiTraceMeter.startTrace("myTraceTest", 1002);
               // 开始计数任务
               traceCount++;
               hiTraceMeter.traceByValue("myTestCount", traceCount);
               // 业务流程
               console.log(`myTraceTest running, taskid: 1002`);
   
               // 结束taskId为1001的跟踪任务
               hiTraceMeter.finishTrace("myTraceTest", 1001);
               // 结束taskId为1002的跟踪任务
               hiTraceMeter.finishTrace("myTraceTest", 1002);

             })
          }
          .width('100%')
        }
        .height('100%')
      }
   }
   ```

2. 运行项目，单击DevEco Studio界面上的运行按钮，然后可通过[hitrace](hitrace.md)命令获取跟踪任务的相关日志。
   
   在 DevEco Studio Terminal 中执行如下命令：

   ```shell
   PS D:\xxx\xxx> hdc shell
   $ hitrace --trace_begin app
   ```

   执行抓取trace命令后，先在设备中执行自己的业务调用逻辑，继续依次执行如下命令：

   ```shell
   $ hitrace --trace_dump | grep tracing_mark_write
   $ hitrace --trace_finish
   ```

   抓取trace成功的数据如下所示：

   ```text
   <...>-3310    (-------) [005] .... 351382.921936: tracing_mark_write: S|3310|H:myTraceTest 1001
   <...>-3310    (-------) [005] .... 351382.922233: tracing_mark_write: C|3310|H:myTestCount 1
   <...>-3310    (-------) [005] .... 351382.922138: tracing_mark_write: S|3310|H:myTraceTest 1002
   <...>-3310    (-------) [005] .... 351382.922233: tracing_mark_write: C|3310|H:myTestCount 2
   <...>-3310    (-------) [005] .... 351382.922165: tracing_mark_write: F|3310|H:myTestCount 1001
   <...>-3310    (-------) [005] .... 351382.922175: tracing_mark_write: F|3310|H:myTestCount 1002
   ```
