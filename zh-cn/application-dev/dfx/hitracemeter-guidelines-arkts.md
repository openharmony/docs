# 使用HiTraceMeter跟踪性能（ArkTS）

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @qq_437963121-->
<!--Designer: @kutcherzhou1; @MontSaintMichel-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

## 简介

HiTraceMeter提供系统性能打点接口。开发者在关键代码位置调用这些API，能够有效跟踪进程轨迹，查看系统和应用性能。


## 接口说明

性能打点跟踪接口由HiTraceMeter模块提供，详细API请参考[@ohos.hiTraceMeter (性能打点) ArkTS API参考](../reference/apis-performance-analysis-kit/js-apis-hitracemeter.md)。

| 接口名 | 描述 |
| -------- | -------- |
| hiTraceMeter.startSyncTrace(level: HiTraceOutputLevel, name: string, customArgs?: string): void | 开启一个同步时间片跟踪事件，分级控制跟踪输出。<br/>**说明**：从API version 19开始，支持该接口。 |
| hiTraceMeter.finishSyncTrace(level: HiTraceOutputLevel): void | 结束一个同步时间片跟踪事件，分级控制跟踪输出。<br/>level必须与流程开始的startSyncTrace()对应参数值保持一致。<br/>**说明**：从API version 19开始，支持该接口。 |
| hiTraceMeter.startAsyncTrace(level: HiTraceOutputLevel, name: string, taskId: number, customCategory: string, customArgs?: string): void | 开启一个异步时间片跟踪事件，分级控制跟踪输出。<br/>taskId是trace中用来表示关联的ID，如果有多个name相同的任务并行执行，则开发者每次调用startAsyncTrace()时，传入的taskId需不同；如果具有相同name的任务是串行执行的，则taskId可以相同。<br/>**说明**：从API version 19开始，支持该接口。 |
| hiTraceMeter.finishAsyncTrace(level: HiTraceOutputLevel, name: string, taskId: number): void | 结束一个异步时间片跟踪事件，分级控制跟踪输出。<br/>level、name和taskId必须与流程开始的startAsyncTrace()对应参数值保持一致。<br/>**说明**：从API version 19开始，支持该接口。 |
| hiTraceMeter.traceByValue(level: HiTraceOutputLevel, name: string, count: number): void | 整数跟踪事件，分级控制跟踪输出。<br/>name和count两个参数分别用来标记一个跟踪的整数变量名及整数值。<br/>**说明**：从API version 19开始，支持该接口。 |
| hiTraceMeter.isTraceEnabled(): boolean | 判断当前是否开启应用trace捕获。<br/>使用hitrace命令行工具等方式开启采集时返回true。未开启采集或停止采集后返回false，此时调用HiTraceMeter性能跟踪打点接口无效。<br/>**说明**：从API version 19开始，支持该接口。 |

> **注意：**
>
> [用户态trace格式](hitracemeter-view.md#用户态trace格式说明)使用竖线 | 作为分隔符，所以通过HiTraceMeter接口传递的字符串类型参数应避免包含该字符，防止trace解析异常。


### 接口分类

HiTraceMeter打点接口分为三类：同步时间片跟踪、异步时间片跟踪和整数跟踪。HiTraceMeter接口实现均为同步，同步和异步针对的是被跟踪的业务。同步业务使用同步时间片跟踪接口，异步业务使用异步时间片跟踪接口。HiTraceMeter打点接口可与[HiTraceChain](hitracechain-guidelines-arkts.md)一起使用，进行跨设备、跨进程或跨线程的打点关联与分析。


### 接口使用场景

- 同步时间片跟踪接口
  用于顺序执行的打点场景，需按序成对使用startSyncTrace()接口和finishSyncTrace()接口，否则会导致trace文件在smartperf等可视化工具上显示异常。

- 异步时间片跟踪接口
  在异步操作执行前调用startAsyncTrace()接口进行开始打点，在异步操作完成后调用finishAsyncTrace()接口进行结束打点。  
  解析trace时，通过name和taskId参数识别不同的异步跟踪。这两个接口必须按序成对使用，并传入相同的name和taskId。  
  不同的异步流程中应使用不同的name和taskId，但在异步跟踪流程不会同时发生的情况下，可以使用相同的name和taskId。  
  调用错误会导致trace文件在smartperf等可视化工具上显示异常。

- 整数跟踪接口
  用于跟踪整数变量。整数值变动时调用traceByValue()接口，可在smartperf的泳道图中观察变动情况。由于从开始采集到首次打点存在时间差，这段时间的数值无法查看。


### 参数解析

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| level | enum | 是 | 跟踪输出级别。低于系统阈值的跟踪将不会被输出。<br/>log版本阈值默认为INFO，nolog版本阈值默认为COMMERCIAL。 |
| name | string | 是 | 要跟踪的任务名称或整数变量名称。 |
| taskId | number | 是 | 用来表示关联的ID，如果有多个name相同的任务并行执行，则开发者每次调用startAsyncTrace()时，传入的taskId需不同。 |
| count | number | 是 | 整数变量的值。 |
| customCategory | string | 是 | 自定义聚类名称，用于聚合同一类异步跟踪打点。<br/>若不需要聚类，可传入一个空字符串。 |
| customArgs | string | 否 | 自定义键值对，若有多组键值对，使用逗号进行分隔，例"key1=value1,key2=value2"。<br/>若不需要该参数，可不传入该参数或传入一个空字符串。 |

> **说明：**
>
> [用户态trace](hitracemeter-view.md#用户态trace格式说明)总长度限制为512字符，超过部分将会被截断。建议name、customCategory和customArgs三个字段的总长度不超过420字符，以避免trace被截断。


## 开发步骤

以下为一个使用HiTraceMeter打点接口的ArkTS应用示例。


### 步骤一：创建项目

1. 在DevEco Studio中新建工程，选择“Empty Ability”，工程的目录结构如下。

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

2. 编辑“entry &gt; src &gt; main &gt; ets &gt; pages &gt; Index.ets”文件，在文本点击事件处理业务中使用HiTraceMeter性能跟踪打点接口，完整的示例代码如下。

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
               const COMMERCIAL = hiTraceMeter.HiTraceOutputLevel.COMMERCIAL;
   
               let traceCount = 0;
               // 第一个异步跟踪任务开始
               hiTraceMeter.startAsyncTrace(COMMERCIAL, 'myTestAsyncTrace', 1001, 'categoryTest', 'key=value');
               // 开始计数任务
               traceCount++;
               hiTraceMeter.traceByValue(COMMERCIAL, 'myTestCountTrace', traceCount);
               // 业务流程
               hilog.info(0x0000, 'testTrace', 'myTraceTest running, taskId: 1001');
   
               // 第二个异步跟踪任务开始，同时第一个跟踪的同名任务还没结束，出现了并行执行，对应接口的taskId需要不同
               hiTraceMeter.startAsyncTrace(COMMERCIAL, 'myTestAsyncTrace', 1002, 'categoryTest', 'key=value');
               // 开始计数任务
               traceCount++;
               hiTraceMeter.traceByValue(COMMERCIAL, 'myTestCountTrace', traceCount);
               // 业务流程
               hilog.info(0x0000, 'testTrace', 'myTraceTest running, taskId: 1002');
   
               // 结束taskId为1001的异步跟踪任务
               hiTraceMeter.finishAsyncTrace(COMMERCIAL, 'myTestAsyncTrace', 1001);
               // 结束taskId为1002的异步跟踪任务
               hiTraceMeter.finishAsyncTrace(COMMERCIAL, 'myTestAsyncTrace', 1002);
               
               // 开始同步跟踪任务
               hiTraceMeter.startSyncTrace(COMMERCIAL, 'myTestSyncTrace', 'key=value');
               // 业务流程
               hilog.info(0x0000, 'testTrace', 'myTraceTest running, synchronizing trace');
               // 结束同步跟踪任务
               hiTraceMeter.finishSyncTrace(COMMERCIAL);
               
               // 若通过HiTraceMeter性能打点接口传递的参数的生成过程比较复杂，此时可以通过isTraceEnabled判断当前是否开启应用trace捕获，
               // 在未开启应用trace捕获时，避免该部分性能损耗
               if (hiTraceMeter.isTraceEnabled()) {
                   let customArgs = 'key0=value0';
                   for(let index = 1; index < 10; index++) {
                       customArgs += `,key${index}=value${index}`
                   }
                   hiTraceMeter.startAsyncTrace(COMMERCIAL, 'myTestAsyncTrace', 1003, 'categoryTest', customArgs);
                   hilog.info(0x0000, 'testTrace', 'myTraceTest running, taskId: 1003');
                   hiTraceMeter.finishAsyncTrace(COMMERCIAL, 'myTestAsyncTrace', 1003);
               } else {
                   hilog.info(0x0000, 'testTrace', 'myTraceTest running, trace is not enabled');
               }
             })
          }
          .width('100%')
        }
        .height('100%')
      }
   }
   ```


### 步骤二：采集trace信息并查看

1. 在DevEco Studio Terminal窗口中执行以下命令，开启应用的trace捕获。

   ```shell
   PS D:\xxx\xxx> hdc shell
   $ hitrace --trace_begin app
   ```

2. 单击DevEco Studio界面上的运行按钮，启动应用。点击应用界面的“Hello World”文本，执行包含HiTraceMeter打点的业务逻辑。然后执行如下命令抓取trace数据，并使用“myTest”关键字过滤trace数据（示例打点接口传递的name字段前缀均为“myTest”）。

   ```shell
   $ hitrace --trace_dump | grep myTest
   ```

   成功抓取的trace数据如下所示：

   ```text
   e.myapplication-39945   (  39945) [010] .... 347921.342267: tracing_mark_write: S|39945|H:myTestAsyncTrace|1001|M62|categoryTest|key=value
   e.myapplication-39945   (  39945) [010] .... 347921.342280: tracing_mark_write: C|39945|H:myTestCountTrace|1|M62
   e.myapplication-39945   (  39945) [010] .... 347921.342327: tracing_mark_write: S|39945|H:myTestAsyncTrace|1002|M62|categoryTest|key=value
   e.myapplication-39945   (  39945) [010] .... 347921.342333: tracing_mark_write: C|39945|H:myTestCountTrace|2|M62
   e.myapplication-39945   (  39945) [010] .... 347921.342358: tracing_mark_write: F|39945|H:myTestAsyncTrace|1001|M62
   e.myapplication-39945   (  39945) [010] .... 347921.342365: tracing_mark_write: F|39945|H:myTestAsyncTrace|1002|M62
   e.myapplication-39945   (  39945) [010] .... 347921.342387: tracing_mark_write: B|39945|H:myTestSyncTrace|M62|key=value
   e.myapplication-39945   (  39945) [010] .... 347921.342586: tracing_mark_write: S|39945|H:myTestAsyncTrace|1003|M62|categoryTest|key0=value0,key1=value1,key2=value2,key3=value3,key4=value4,key5=value5,key6=value6,key7=value7,key8=value8,key9=value9
   e.myapplication-39945   (  39945) [010] .... 347921.342615: tracing_mark_write: F|39945|H:myTestAsyncTrace|1003|M62
   ```

   每一行trace数据中，tracing_mark_write为打点事件类型，应用程序中调用HiTraceMeter接口打点使用的均为此事件。打点事件类型前面的数据分别为线程名-线程ID、进程ID、CPU和打点时间（从开机到当前的时间，单位为秒）；打点事件类型后面的数据可查看[用户态trace格式](hitracemeter-view.md#用户态trace格式说明)。


### 步骤三：停止采集trace


1. 执行以下命令，停止应用的trace捕获。

   ```shell
   $ hitrace --trace_finish
   ```

2. 再次点击应用界面的“Hello World”文本，此时应用trace捕获已关闭，isTraceEnabled()接口返回false。在DevEco Studio Log窗口使用关键字“not enabled”进行过滤，会打印如下日志。

   ```text
   myTraceTest running, trace is not enabled
   ```

   > **说明：**
   >
   > log版本在使用hitrace --trace_finish命令停止采集后会自动拉起快照模式，打开trace捕获，此时isTraceEnabled()接口返回true，不会打印上述日志。
