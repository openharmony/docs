# 使用HiTraceMeter跟踪性能（ArkTS）

## 简介

HiTraceMeter提供系统性能打点接口。开发者通过在关键代码位置调用HiTraceMeter接口提供的API接口，能够有效跟踪进程轨迹、查看系统性能。

## 基本概念

**HiTraceMeter Tag**：跟踪数据使用类别，称作HiTraceMeter Tag，一般每个软件子系统对应一个tag。[hitrace](hitrace.md)命令行工具采集跟踪数据时，只采集给定的tag类别选项指定的跟踪数据。应用中的HiTraceMeter打点的tag是HITRACE_TAG_APP，对应[hitrace](hitrace.md)命令`hitrace -l`列出的tag列表中的app。

## 实现原理

1. 应用程序通过HiTraceMeter函数接口进行打点，HiTraceMeter函数将跟踪数据通过内核sysfs文件接口输入到内核的ftrace数据缓冲区。
2. [hitrace](hitrace.md)命令行工具读取内核ftrace缓冲区中的跟踪数据，将跟踪数据输出到设备侧的文件中。

## 接口说明

性能打点跟踪接口由HiTraceMeter模块提供，详细API请参考[性能打点跟踪API参考](../reference/apis-performance-analysis-kit/js-apis-hitracemeter.md)。

| 接口名                                                 | 描述                                                         |
| ------------------------------------------------------ | ------------------------------------------------------------ |
| hiTraceMeter.startTrace(name: string, taskId: number)  | 异步时间片跟踪接口，标记一个预跟踪耗时任务的开始。taskId是trace中用来表示关联的ID，如果有多个name相同的任务并行执行，则每次调用startTrace的taskId不同；如果具有相同name的任务是串行执行的，则taskId可以相同。 |
| hiTraceMeter.finishTrace(name: string, taskId: number) | 异步时间片跟踪接口，name和taskId必须与流程开始的hiTraceMeter.startTrace对应参数值保持一致。 |
| hiTraceMeter.traceByValue(name: string, value: number) | 整数跟踪接口，用来标记一个预跟踪的数值变量，该变量的数值会不断变化。 |

> **注意：**
>
> 用户态tarce格式使用竖线 `|` 作为分隔符，所以通过HiTraceMeter接口传递的字符串类型参数应避免包含该字符，防止trace解析异常。

HiTraceMeter打点接口按功能/行为分类，主要分三类：同步时间片跟踪接口、异步时间片跟踪接口和整数跟踪接口。无论同步时间片跟踪接口还是异步时间片跟踪接口，接口本身都是同步接口，不是异步接口。HiTraceMeter打点接口可与[HiTraceChain](./hitracechain-guidelines-arkts.md)一起使用，进行跨设备/跨进程/跨线程打点与分析。

- 同步时间片跟踪接口用于顺序执行的打点场景，目前ArkTS/JS暂未提供相关接口。
- 异步时间片跟踪接口用于在异步操作执行前进行开始打点，在异步操作完成后进行结束打点。异步跟踪的开始和结束由于不是顺序发生的，解析trace时需要通过name与taskId参数进行识别，name与taskId参数相同的异步跟踪开始与结束打点相匹配。
- 整数跟踪接口用于跟踪整数变量。

**参数解析**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| name   | string | 是   | 要跟踪的任务名称或整数变量名称。                             |
| taskId | number | 是   | 用来表示关联的ID，如果有多个name相同的任务是并行执行的，则开发者每次调用startAsyncTrace时传入的taskId需不同。 |
| count  | number | 是   | 整数变量的值。                                               |

## 开发示例

在应用启动执行页面加载后，开始分布式跟踪；完成业务之后，停止分布式跟踪。以下为一个使用HiTraceMeter打点接口的ArkTS应用示例。

1. 新建一个ArkTS应用工程，工程目录结构如下：

   ```text
   ├── entry
   │   ├── src
   │       ├── main
   │       │   ├── ets
   │       │   │   ├── entryability
   │       │   │   │   └── EntryAbility.ets
   │       │   │   ├── entrybackupability
   │       │   │   │   └── EntryBackupAbility.ets
   │       │   │   └── pages
   │       │   │       └── Index.ets
   ```

2. 编辑"Index.ets"文件，在文本点击事件处理业务中使用hiTraceMeter性能跟踪打点接口，示例代码如下：

   ```ts
   import { hiTraceMeter, hilog } from '@kit.PerformanceAnalysisKit';
   
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
               this.message = (this.message == 'Hello HiTrace') ? 'Hello World' : 'Hello HiTrace';
   
               let traceCount = 0;
               // 第一个跟踪任务开始
               hiTraceMeter.startTrace("myTestAsyncTrace", 1001);
               // 开始计数任务
               traceCount++;
               hiTraceMeter.traceByValue("myTestCountTrace", traceCount);
               // 业务流程
               console.log(`myTraceTest running, taskid: 1001`);
   
               // 第二个跟踪任务开始，同时第一个跟踪的同名任务还没结束，出现了并行执行，对应接口的taskId需要不同。
               hiTraceMeter.startTrace("myTestAsyncTrace", 1002);
               // 开始计数任务
               traceCount++;
               hiTraceMeter.traceByValue("myTestCountTrace", traceCount);
               // 业务流程
               console.log(`myTraceTest running, taskid: 1002`);
   
               // 结束taskId为1001的跟踪任务
               hiTraceMeter.finishTrace("myTestAsyncTrace", 1001);
               // 结束taskId为1002的跟踪任务
               hiTraceMeter.finishTrace("myTestAsyncTrace", 1002);
             })
          }
          .width('100%')
        }
        .height('100%')
      }
   }
   ```
   
3. 在DevEco Studio Terminal窗口中执行如下命令，开启应用trace捕获：

   ```shell
   PS D:\xxx\xxx> hdc shell
   $ hitrace --trace_begin app
   ```

4. 单击DevEco Studio界面上的运行按钮，启动应用，点击屏幕中间的字符串，执行包含HiTraceMeter打点的业务逻辑，然后执行如下命令抓取trace数据：

   ```shell
   $ hitrace --trace_dump | grep myTest
   ```

   成功抓取的trace数据如下所示：

   ```text
   <...>-24812   (-------) [010] .... 372550.749599: tracing_mark_write: S|24812|H:myTestAsyncTrace|1001
   <...>-24812   (-------) [010] .... 372550.749622: tracing_mark_write: C|24812|H:myTestCountTrace|1
   <...>-24812   (-------) [010] .... 372550.750118: tracing_mark_write: S|24812|H:myTestAsyncTrace|1002
   <...>-24812   (-------) [010] .... 372550.750131: tracing_mark_write: C|24812|H:myTestCountTrace|2
   <...>-24812   (-------) [010] .... 372550.750177: tracing_mark_write: F|24812|H:myTestAsyncTrace|1001
   <...>-24812   (-------) [010] .... 372550.750188: tracing_mark_write: F|24812|H:myTestAsyncTrace|1002
   ```
   
5. 执行如下命令，结束应用trace捕获：

   ```shell
   $ hitrace --trace_finish
   ```
