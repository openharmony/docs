# 性能打点跟踪开发指导

## 简介

hiTraceMeter为开发者提供系统性能打点接口。开发者通过在自己的业务逻辑中的关键代码位置调用HiTraceMeter接口提供的API接口，能够有效跟踪进程轨迹、查看系统性能。

## 基本概念

- **hiTraceMeter Tag**

  跟踪数据使用类别分类，称作hiTraceMeter Tag或hiTraceMeter Category，一般每个软件子系统对应一个Tag，该Tag在打点API中以类别Tag参数传入。hiTraceMeter命令行工具采集跟踪数据时，只采集给定的Tag类别选项指定的跟踪数据。

## 实现原理

- 应用程序通过hiTraceMeter函数接口进行打点，hiTraceMeter函数将跟踪数据通过内核sysfs文件接口输出到内核的ftrace数据缓冲区。
- hiTraceMeter命令行工具读取内核ftrace缓冲区中的跟踪数据，将文本格式的跟踪数据保存到设备侧的文件中。

## 约束与限制

- 由于JS程序的异步IO特性，现在hiTraceMeter只提供了异步接口。

## 接口说明

性能打点跟踪接口由hiTraceMeter模块提供，详细API请参考[性能打点跟踪API参考](../reference/apis/js-apis-hitracemeter.md)。

**性能打点跟踪接口功能介绍：**

| 接口名                                                                       | 返回值    | 描述         |
| ---------------------------------------------------------------------------- | --------- | ------------ |
| hiTraceMeter.startTrace(name: string, taskId: number) | void      | 标记一个预跟踪耗时任务的开始。taskId是trace中用来表示关联的ID,如果有多个name相同的任务是并行执行的，则每次调用startTrace的taskId不同。如果具有相同name的任务是串行执行的，则taskId可以相同。 |
| hiTraceMeter.finishTrace(name: string, taskId: number)                       | void      | name和taskId必须与流程开始的hiTraceMeter.startTrace对应参数值保持一致。 |
| hiTraceMeter.traceByValue(name: string, value: number)                       | void      | 用来标记一个预跟踪的数值变量，该变量的数值会不断变化。|

## 开发步骤

在应用启动执行页面加载后，开始分布式跟踪，完成业务之后，停止分布式跟踪。

1. 新建工程，并在业务中调用hiTraceMeter接口，进行性能打点跟踪。
 
   - **ArkTS应用工程**

      新建一个ArkTS应用工程，在“Project”窗口点击“entry > src > main > ets > pages > index”，打开工程中的“index.ets”文件，在页面执行加载后，在自己的业务中调用hiTraceMeter的接口，进行性能打点跟踪，以任务名name为HITRACE_TAG_APP为例 示例代码如下：
    
      ```ts
      import hitrace from '@ohos.hiTraceMeter';
      
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
                  this.message = 'Hello ArkUI';

                  // 跟踪并行执行的同名任务
                  hitrace.startTrace("HITRACE_TAG_APP", 1001);
                  // 业务流程
                  console.log(`HITRACE_TAG_APP running`);
      
                  // 第二个跟踪任务开始，同时第一个跟踪的同名任务还没结束，出现了并行执行，对应接口的taskId需要不同。
                  hitrace.startTrace("HITRACE_TAG_APP", 1002);
                  // 业务流程
                  console.log(`HITRACE_TAG_APP running`);
      
                  hitrace.finishTrace("HITRACE_TAG_APP", 1001);
                  hitrace.finishTrace("HITRACE_TAG_APP", 1002);
      
                  // 跟踪串行执行的同名任务，taskId可以不同，也可以相同
                  hitrace.startTrace("HITRACE_TAG_APP", 1003);
                  // 业务流程
                  console.log(`HITRACE_TAG_APP running`);
                  //第一个跟踪的任务结束
                  hitrace.finishTrace("HITRACE_TAG_APP", 1003);
      
                  // 第二个跟踪任务开始，同名的待跟踪任务串行执行，且taskId不同
                  hitrace.startTrace("HITRACE_TAG_APP", 1004);
                  // 业务流程
                  console.log(`HITRACE_TAG_APP running`);
                  let traceCount = 3;
                  hitrace.traceByValue("myTestCount", traceCount);
                  hitrace.finishTrace("HITRACE_TAG_APP", 1004);
      
                  // 第三个跟踪任务开始，同名的待跟踪任务串行执行，且taskId与上一个相同
                  hitrace.startTrace("HITRACE_TAG_APP", 1004);
                  // 业务流程
                  console.log(`HITRACE_TAG_APP running`);
                  //第三个跟踪的任务结束
                  hitrace.finishTrace("HITRACE_TAG_APP", 1004);
      
                })
              }
              .width('100%')
            }
            .height('100%')
          }
      }
      ```

   - **JS应用工程**

      新建一个JS应用工程，在“Project”窗口点击“entry > src > main > js > default > pages > index”，打开工程中的“index.js”文件，在页面执行加载后，在自己的业务中调用hiTraceMeter的接口，进行性能打点跟踪，示例代码如下：

      ```js
      import hiTraceMeter from '@ohos.hiTraceMeter'

      export default {
          data: {
              title: ""
          },
          onInit() {
              this.title = this.$t('strings.world');

              // 跟踪并行执行的同名任务
              hiTraceMeter.startTrace("business", 1);
              // 业务流程
              console.log(`business running`);
              hiTraceMeter.startTrace("business", 2);  // 第二个跟踪任务开始，同时第一个跟踪的同名任务还没结束，出现了并行执行，对应接口的taskId需要不同。
              // 业务流程
              console.log(`business running`);
              hiTraceMeter.finishTrace("business", 1);
              // 业务流程
              console.log(`business running`);
              hiTraceMeter.finishTrace("business", 2);

              // 跟踪串行执行的同名任务
              hiTraceMeter.startTrace("business", 1);
              // 业务流程
              console.log(`business running`);
              hiTraceMeter.finishTrace("business", 1);  // 第一个跟踪的任务结束
              // 业务流程
              console.log(`business running`);
              hiTraceMeter.startTrace("business", 1);   // 第二个跟踪的同名任务开始，同名的待跟踪任务串行执行。
              // 业务流程
              console.log(`business running`);

              let traceCount = 3;
              hiTraceMeter.traceByValue("myTestCount", traceCount);
              traceCount = 4;
              hiTraceMeter.traceByValue("myTestCount", traceCount);
              hiTraceMeter.finishTrace("business", 1);
          }
      }
      ```
 
2. 运行项目，点击应用界面上的运行按钮，在shell中依次执行如下命令：
 
   ```shell
   hdc shell
   hitrace --trace_begin app
   ```
   
   执行抓取trace命令后，先在设备中自己的业务里面调用接口，继续依次执行如下命令：
  
   ```shell
   hitrace --trace_dump | grep tracing_mark_write
   hitrace --trace_finish
   ```
  
   抓取trace成功的数据如下所示
  
   ```
   <...>-3310    (-------) [005] .... 351382.921936: tracing_mark_write: S|3310|H:HITRACE_TAG_APP 1001
   <...>-3310    (-------) [005] .... 351382.922138: tracing_mark_write: S|3310|H:HITRACE_TAG_APP 1002
   <...>-3310    (-------) [005] .... 351382.922165: tracing_mark_write: F|3310|H:HITRACE_TAG_APP 1001
   <...>-3310    (-------) [005] .... 351382.922175: tracing_mark_write: F|3310|H:HITRACE_TAG_APP 1002
   <...>-3310    (-------) [005] .... 351382.922182: tracing_mark_write: S|3310|H:HITRACE_TAG_APP 1003
   <...>-3310    (-------) [005] .... 351382.922203: tracing_mark_write: F|3310|H:HITRACE_TAG_APP 1003
   <...>-3310    (-------) [005] .... 351382.922210: tracing_mark_write: S|3310|H:HITRACE_TAG_APP 1004
   <...>-3310    (-------) [005] .... 351382.922233: tracing_mark_write: C|3310|H:myTestCount 3
   <...>-3310    (-------) [005] .... 351382.922240: tracing_mark_write: F|3310|H:HITRACE_TAG_APP 1004
   <...>-3310    (-------) [005] .... 351382.922247: tracing_mark_write: S|3310|H:HITRACE_TAG_APP 1004
   <...>-3310    (-------) [005] .... 351382.922266: tracing_mark_write: F|3310|H:HITRACE_TAG_APP 1004
   ```
