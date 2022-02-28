# 分布式跟踪开发指导

## 场景介绍

HiTraceChain为开发者提供业务流程调用链跟踪的维测接口，帮助开发者迅速获取指定业务流程调用链的运行日志，定位跨设备/跨进程/跨线程的故障问题。

## 接口说明

分布式跟踪接口由hiTraceChain模块提供，详细API请参考[分布式跟踪API参考](../reference/apis/js-apis-hitracechain.md)。

**分布式跟踪接口功能介绍：**

| 接口名                                                                                                              | 返回值         | 描述         |
| ------------------------------------------------------------------------------------------------------------------- | -------------- | ------------ |
| hiTraceChain.begin(name: string, flags: number = HiTraceFlag.DEFAULT)                                               | HiTraceId      | 开始跟踪。   |
| hiTraceChain.tracepoint(mode: HiTraceCommunicationMode, type: HiTraceTracepointType, id: HiTraceId, msg?: string)   | void           | 信息埋点。   |
| hiTraceChain.end(id: HiTraceId)                                                                                     | void           | 结束跟踪。   |

## 开发步骤

在应用启动执行页面加载后，开始分布式跟踪，完成业务之后，停止分布式跟踪。

1. 新建一个JS应用工程，在“Project”窗口点击“entry > src > main > js > default > pages > index”，打开工程中的“index.js”文件，在页面执行加载后，在实际业务逻辑中调用hiTraceChain的API，进行分布式跟踪，示例代码如下：

   ```
   import hiTraceChain from '@ohos.hiTraceChain'

   export default {
       data: {
           title: ""
       },
       onInit() {
           this.title = this.$t('strings.world');

           // 1、开启分布式跟踪
           let asyncTraceId = hiTraceChain.begin("business", hiTraceChain.HiTraceFlag.INCLUDE_ASYNC | hiTraceChain.HiTraceFlag.DONOT_CREATE_SPAN);
           
           // 2、业务流程开始
           console.log(`business start`);

           // 3、埋点操作
           hiTraceChain.tracepoint(hiTraceChain.HiTraceCommunicationMode.THREAD, hiTraceChain.HiTraceTracepointType.SS, asyncTraceId, "Just a example");

           // 4、业务流程执行中
           console.log(`business running`);

           // 5、业务流程结束
           console.log(`business end`);

           // 6、停止跟踪
           hiTraceChain.end(asyncTraceId);
       }
   }
   ```

2. 运行项目，点击应用界面上的运行按钮，即可通过日志信息分析实际业务。


