# 性能打点跟踪开发指导

## 场景介绍

HiTraceMeter为开发者提供系统性能打点接口。开发者通过在自己的业务逻辑中的关键代码位置调用HiTraceMeter提供的API接口，能够有效追踪进程轨迹、查看系统性能。

## 接口说明
 
性能打点跟踪接口由hiTraceMeter模块提供，详细API请参考[性能打点跟踪API参考](../reference/apis/js-apis-hitracemeter.md)。

**表1** 性能打点跟踪接口功能介绍

| 接口名                                                                       | 返回值    | 描述         |
| ---------------------------------------------------------------------------- | --------- | ------------ |
| hiTraceMeter.startTrace(name: string, taskId: number, expectedTime?: number) | void      | 标记一个预追踪耗时任务的开始。如果有多个相同name的任务需要追踪或者对同一个任务要追踪多次，并且任务同时被执行，则每次调用startTrace的taskId不相同。如果具有相同name的任务是串行执行的，则taskId可以相同。 |
| hiTraceMeter.finishTrace(name: string, taskId: number)                       | void      | name和taskId必须与流程开始的hiTraceMeter.startTrace对应参数值保持一致。 |
| hiTraceMeter.traceByValue(name: string, value: number)                       | void      | 用来标记一个预追踪的数值变量，该变量的数值会不断变化。|

## 开发步骤

在应用启动执行页面加载后，开始分布式跟踪，完成业务之后，停止分布式跟踪。

1. 新建一个JS应用工程，在“Project”窗口点击“entry > src > main > js > default > pages > index”，打开工程中的“index.js”文件，在页面执行加载后，在自己的业务中调用hiTraceMeter的接口，进行性能打点追踪，示例代码如下：

   ```js
   import hiTraceMeter from '@ohos.hiTraceMeter'

   export default {
       data: {
           title: ""
       },
       onInit() {
           this.title = this.$t('strings.world');

           // 从startTrace到finishTrace流程的耗时期望为5ms
           hiTraceMeter.startTrace("business", 1);
           hiTraceMeter.startTrace("business", 1, 5); 
           
           // 追踪并行执行的同名任务
           hiTraceMeter.startTrace("business", 1);
           // 业务流程
           console.log(`business running`);
           hiTraceMeter.startTrace("business", 2);  // 第二个追踪的任务开始，同时第一个追踪的同名任务还没结束，出现了并行执行，对应接口的taskId需要不同
           // 业务流程
           console.log(`business running`);
           hiTraceMeter.finishTrace("business", 1);
           // 业务流程
           console.log(`business running`);
           hiTraceMeter.finishTrace("business", 2);

           // 追踪串行执行的同名任务
           hiTraceMeter.startTrace("business", 1);
           // 业务流程
           console.log(`business running`);
           hiTraceMeter.finishTrace("business", 1);  // 第一个追踪的任务结束
           // 业务流程
           console.log(`business running`);
           hiTraceMeter.startTrace("business", 1);   // 第二个追踪的同名任务开始，同名的待追踪任务串行执行
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

2. 点击应用界面上的运行按钮运行项目，即可通过日志信息分析实际业务。


