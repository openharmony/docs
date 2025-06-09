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

| 接口名                                                       | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| startSyncTrace(level: HiTraceOutputLevel, name: string, customArgs?: string): void | 开启一个同步时间片跟踪事件，分级控制跟踪输出。<br>**说明**：从API version 19开始，支持该接口。 |
| finishSyncTrace(level: HiTraceOutputLevel): void             | 结束一个同步时间片跟踪事件，分级控制跟踪输出。level必须与流程开始的startSyncTrace对应参数值保持一致。<br/>**说明**：从API version 19开始，支持该接口。 |
| startAsyncTrace(level: HiTraceOutputLevel, name: string, taskId: number, customCategory: string, customArgs?: string): void | 开启一个异步时间片跟踪事件，分级控制跟踪输出。taskId是trace中用来表示关联的ID，如果有多个name相同的任务并行执行，则开发者每次调用startAsyncTrace时传入的taskId需不同；如果具有相同name的任务是串行执行的，则taskId可以相同。<br/>**说明**：从API version 19开始，支持该接口。 |
| finishAsyncTrace(level: HiTraceOutputLevel, name: string, taskId: number): void | 结束一个异步时间片跟踪事件，分级控制跟踪输出。level、name和taskId必须与流程开始的startAsyncTrace对应参数值保持一致。<br/>**说明**：从API version 19开始，支持该接口。 |
| traceByValue(level: HiTraceOutputLevel, name: string, count: number): void | 整数跟踪事件，分级控制跟踪输出。name、count两个参数分别用来标记一个预跟踪的整数变量名及整数值。<br/>**说明**：从API version 19开始，支持该接口。 |
| isTraceEnabled(): boolean                                    | 判断当前是否开启应用trace捕获。应用trace捕获未开启时，HiTraceMeter性能跟踪打点无效。<br/>**说明**：从API version 19开始，支持该接口。 |

> **注意：**
>
> [用户态trace格式](./hitracemeter-view.md#用户态trace格式说明)使用竖线 `|` 作为分隔符，所以通过HiTraceMeter接口传递的字符串类型参数应避免包含该字符，防止trace解析异常。

HiTraceMeter打点接口按功能/行为分类，主要分三类：同步时间片跟踪接口、异步时间片跟踪接口和整数跟踪接口。无论同步时间片跟踪接口还是异步时间片跟踪接口，接口本身都是同步接口，不是异步接口。HiTraceMeter打点接口可与[HiTraceChain](./hitracechain-guidelines-arkts.md)一起使用，进行跨设备/跨进程/跨线程的打点关联与分析。

- 同步时间片跟踪接口用于顺序执行的打点场景。
- 异步时间片跟踪接口用于在异步操作执行前进行开始打点，在异步操作完成后进行结束打点。异步跟踪的开始和结束由于不是顺序发生的，解析trace时需要通过name与taskId参数进行识别，name与taskId参数相同的异步跟踪开始与结束打点相匹配。
- 整数跟踪接口用于跟踪整数变量。

**参数解析**

| 参数名         | 类型   | 必填 | 说明                                                         |
| -------------- | ------ | ---- | ------------------------------------------------------------ |
| level          | enum   | 是   | 跟踪输出级别，低于系统阈值的跟踪将不会被输出。<br>log版本阈值为INFO，nolog版本阈值为COMMERCIAL。 |
| name           | string | 是   | 要跟踪的任务名称或整数变量名称。                             |
| taskId         | number | 是   | 用来表示关联的ID，如果有多个name相同的任务是并行执行的，则开发者每次调用startAsyncTrace时传入的taskId需不同。 |
| count          | number | 是   | 整数变量的值。                                               |
| customCategory | string | 是   | 自定义聚类名称，用于聚合同一类异步跟踪打点。<br>若不需要聚类，可传入一个空字符串。 |
| customArgs     | string | 否   | 自定义键值对，若有多组键值对，使用逗号进行分隔，例"key1=value1,key2=value2"。<br>若不需要该参数，可不传入该参数或传入一个空字符串。 |

> **说明：**
>
> [用户态trace](./hitracemeter-view.md#用户态trace格式说明)总长度限制512字符，超过的部分将会被截断，因此建议name、customCategory和customArgs三个字段的总长度不超过420字符，避免输出的用户态trace被截断。

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
   <...>-39945   (-------) [010] .... 347921.342267: tracing_mark_write: S|39945|H:myTestAsyncTrace|1001|M62|categoryTest|key=value
   <...>-39945   (-------) [010] .... 347921.342280: tracing_mark_write: C|39945|H:myTestCountTrace|1|M62
   <...>-39945   (-------) [010] .... 347921.342327: tracing_mark_write: S|39945|H:myTestAsyncTrace|1002|M62|categoryTest|key=value
   <...>-39945   (-------) [010] .... 347921.342333: tracing_mark_write: C|39945|H:myTestCountTrace|2|M62
   <...>-39945   (-------) [010] .... 347921.342358: tracing_mark_write: F|39945|H:myTestAsyncTrace|1001|M62
   <...>-39945   (-------) [010] .... 347921.342365: tracing_mark_write: F|39945|H:myTestAsyncTrace|1002|M62
   <...>-39945   (-------) [010] .... 347921.342387: tracing_mark_write: B|39945|H:myTestSyncTrace|M62|key=value
   <...>-39945   (-------) [010] .... 347921.342586: tracing_mark_write: S|39945|H:myTestAsyncTrace|1003|M62|categoryTest|key0=value0,key1=value1,key2=value2,key3=value3,key4=value4,key5=value5,key6=value6,key7=value7,key8=value8,key9=value9
   <...>-39945   (-------) [010] .... 347921.342615: tracing_mark_write: F|39945|H:myTestAsyncTrace|1003|M62
   ```

5. 执行如下命令，结束应用trace捕获：

   ```shell
   $ hitrace --trace_finish
   ```

6. 再次点击屏幕中间的字符串，此时应用trace捕获已关闭，isTraceEnabled返回false，DevEco Studio Log窗口使用关键字"enable"进行过滤，出现如下打印：

   ```text
   myTraceTest running, trace is not enabled
   ```

   



