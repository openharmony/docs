# 使用HiTraceMeter跟踪性能（ArkTS/JS）

## 简介

HiTraceMeter提供系统性能打点接口。开发者通过在关键代码位置调用HiTraceMeter接口提供的API接口，能够有效跟踪进程轨迹、查看系统性能。

## 基本概念

**HiTraceMeter Tag**：跟踪数据使用类别，称作HiTraceMeter Tag，一般每个软件子系统对应一个tag。[hitrace](hitrace.md)命令行工具采集跟踪数据时，只采集给定的tag类别选项指定的跟踪数据。应用中的HiTraceMeter打点的tag是HITRACE_TAG_APP，对应[hitrace](hitrace.md)命令`hitrace -l`列出的tag列表中的app。

## 实现原理

1. 应用程序通过HiTraceMeter函数接口进行打点，HiTraceMeter函数将跟踪数据通过内核sysfs文件接口输入到内核的ftrace数据缓冲区。
2. [hitrace](hitrace.md)命令行工具读取内核ftrace缓冲区中的跟踪数据，将跟踪数据输出到设备侧的文件中。

## 接口说明

性能打点跟踪接口由HiTraceMeter模块提供，详细API请参考[性能打点跟踪API参考](../reference/apis-performance-analysis-kit/js-apis-hitracemeter.md)。

| 接口名                                                       | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| startSyncTrace(level: HiTraceOutputLevel, name: string, customArgs?: string): void | 开启一个同步时间片跟踪事件，分级控制跟踪输出。               |
| finishSyncTrace(level: HiTraceOutputLevel): void             | 结束一个同步时间片跟踪事件，分级控制跟踪输出。level必须与流程开始的startSyncTrace对应参数值保持一致。 |
| startAsyncTrace(level: HiTraceOutputLevel, name: string, taskId: number, customCategory: string, customArgs?: string): void | 开启一个异步时间片跟踪事件，分级控制跟踪输出。taskId是trace中用来表示关联的ID，如果有多个name相同的任务并行执行，则开发者每次调用startAsyncTrace时传入的taskId需不同；如果具有相同name的任务是串行执行的，则taskId可以相同。 |
| finishAsyncTrace(level: HiTraceOutputLevel, name: string, taskId: number): void | 结束一个异步时间片跟踪事件，分级控制跟踪输出。level、name和taskId必须与流程开始的startAsyncTrace对应参数值保持一致。 |
| traceByValue(level: HiTraceOutputLevel, name: string, count: number): void | 整数跟踪事件，分级控制跟踪输出。用来标记一个预跟踪的整数变量名及整数值。 |
| isTraceEnabled(): boolean                                    | 判断当前是否开启应用trace捕获。应用trace捕获未开启时，HiTraceMeter性能跟踪打点无效。 |

HiTraceMeter打点接口按功能/行为分类，主要分三类：同步时间片跟踪接口、异步时间片跟踪接口和整数跟踪接口。无论同步时间片跟踪接口还是异步时间片跟踪接口，接口本身都是同步接口，不是异步接口。HiTraceMeter打点接口可与[HiTraceChain](./hitracechain-guidelines-arkts)一起使用，进行跨设备/跨进程/跨线程打点与分析。

- 同步时间片跟踪接口用于顺序执行的打点场景。
- 异步时间片跟踪接口用于在异步操作执行前进行开始打点，在异步操作完成后进行结束打点。异步跟踪的开始和结束由于不是顺序发生的，解析trace时需要通过name与taskId参数进行识别，name与taskId参数相同的异步跟踪开始与结束打点相匹配。
- 整数跟踪接口用于跟踪整数变量。

**参数解析**

| 参数名         | 类型   | 必填 | 说明                                                         |
| -------------- | ------ | ---- | ------------------------------------------------------------ |
| level          | enum   | 是   | 跟踪输出级别，低于系统阈值的跟踪将不会被输出。<br>log版本阈值为INFO，nolog版本阈值为COMMERCIAL。 |
| name           | string | 是   | 要跟踪的任务名称或整数变量名称。该字段长度限制320字符，超过的部分将会被截断。 |
| taskId         | number | 是   | 用来表示关联的ID，如果有多个name相同的任务是并行执行的，则开发者每次调用startAsyncTrace时传入的taskId需不同。 |
| count          | number | 是   | 整数变量的值。                                               |
| customCategory | string | 是   | 自定义聚类名称，用于聚合同一类异步跟踪打点。该字段长度限制64字符，超过的部分将会被截断。<br>若不需要聚类，可传入一个空字符串。 |
| customArgs     | string | 否   | 自定义键值对，若有多组键值对，使用逗号进行分隔，例"key1=value1,key2=value2"。<br>跟踪输出总长度限制512字符，若name和customCategory参数占用过多字符，可能导致customArgs被截断。<br/>若不需要该参数，可不传入该参数或传入一个空字符串。 |

## 开发示例

在应用启动执行页面加载后，开始分布式跟踪；完成业务之后，停止分布式跟踪。以下为一个使用HiTraceMeter打点接口的ArkTS应用示例，该示例中使用了异步跟踪打点接口startAsyncTrace和finishAsyncTrace，以及整数跟踪打点接口traceByValue。

1. 新建一个ArkTS应用工程，在“Project”窗口点击“entry &gt; src &gt; main &gt; ets &gt; pages &gt; index”，打开工程中的“index.ets”文件；在页面执行加载后，在自己的业务中调用hiTraceMeter的接口，进行性能打点跟踪，以任务名name为myTestAsyncTrace为例， 示例代码如下：

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
               const COMMERCIAL = hiTraceMeter.HiTraceOutputLevel.COMMERCIAL;
   
               let traceCount = 0;
               // 第一个跟踪任务开始
               hiTraceMeter.startAsyncTrace(COMMERCIAL, "myTestAsyncTrace", 1001, "categoryTest", "key=value");
               // 开始计数任务
               traceCount++;
               hiTraceMeter.traceByValue(COMMERCIAL, "myTestCountTrace", traceCount);
               // 业务流程
               console.log(`myTraceTest running, taskid: 1001`);
   
               // 第二个跟踪任务开始，同时第一个跟踪的同名任务还没结束，出现了并行执行，对应接口的taskId需要不同
               hiTraceMeter.startAsyncTrace(COMMERCIAL, "myTestAsyncTrace", 1002, "categoryTest", "key=value");
               // 开始计数任务
               traceCount++;
               hiTraceMeter.traceByValue(COMMERCIAL, "myTestCountTrace", traceCount);
               // 业务流程
               console.log(`myTraceTest running, taskid: 1002`);
   
               // 结束taskId为1001的跟踪任务
               hiTraceMeter.finishAsyncTrace(COMMERCIAL, "myTestAsyncTrace", 1001);
               // 结束taskId为1002的跟踪任务
               hiTraceMeter.finishAsyncTrace(COMMERCIAL, "myTestAsyncTrace", 1002);
             })
          }
          .width('100%')
        }
        .height('100%')
      }
   }
   ```
2. 运行项目，单击DevEco Studio界面上的运行按钮，然后可通过[hitrace](hitrace.md)命令获取跟踪任务的相关日志。

   在 DevEco Studio Terminal 中执行如下命令，开启应用trace捕获：

   ```shell
   PS D:\xxx\xxx> hdc shell
   $ hitrace --trace_begin app
   ```
   启动应用，执行自己的业务调用逻辑（包含HiTraceMeter打点接口），然后依次执行如下命令：

   ```shell
   $ hitrace --trace_dump | grep myTest
   $ hitrace --trace_finish
   ```
   抓取trace成功的数据如下所示：

   ```text
   <...>-23649   (-------) [007] ....  2078.630872: tracing_mark_write: S|23649|H:myTestAsyncTrace|1001|M62|categoryTest|key=value
   <...>-23649   (-------) [007] ....  2078.630887: tracing_mark_write: C|23649|H:myTestCountTrace|1|M62
   <...>-23649   (-------) [007] ....  2078.630989: tracing_mark_write: S|23649|H:myTestAsyncTrace|1002|M62|categoryTest|key=value
   <...>-23649   (-------) [007] ....  2078.630996: tracing_mark_write: C|23649|H:myTestCountTrace|2|M62
   <...>-23649   (-------) [007] ....  2078.631027: tracing_mark_write: F|23649|H:myTestAsyncTrace|1001|M62
   <...>-23649   (-------) [007] ....  2078.631033: tracing_mark_write: F|23649|H:myTestAsyncTrace|1002|M62
   ```
