# HiTraceChain开发指导

## 概述

HiTraceChain主要是对于跨设备/跨进程/跨线程的业务流程，通过相同的traceid在整个业务流程中传递，将流程处理过程中的调用关系、各种输出信息关联和展现出来，帮助使用者分析、定位问题和系统调优。


## 应用场景

HiTraceChain在产品中应用场景如下，包括：

- 端侧业务流程信息（日志、事件等）关联、上报

- 云侧对上报信息的关联展示和分析，辅助问题定位

- IDE对业务流程详细信息、耗时分布进行调试，辅助系统调优

    **图1** HiTraceChain应用场景
    ![zh-cn_image_0000001216312860](figures/zh-cn_image_0000001216312860.png)


### 业务使用示例

  **图2** 业务调用流程图（跨设备、跨进程同步调用）

  ![zh-cn_image_0000001216632830](figures/zh-cn_image_0000001216632830.png)

1. 调试时展示业务流程中的调用关系，进行关键路径分析、功能依赖分析，确定各调用点耗时、调用频率，提前发现性能瓶颈点。

     **图3** 业务调用流程序列图
     ![zh-cn_image_0000001216792790](figures/zh-cn_image_0000001216792790.png)


     **图4** 业务调用流程性能耗时分布
     ![zh-cn_image_0000001261272659](figures/zh-cn_image_0000001261272659.png)

2. 在日志和事件等信息中自动附加traceid信息，便于开发人员综合分析和快速实现问题定界定位。


## 接口说明

HiTraceChain提供C++、C接口。上层业务主要使用HiTraceChain跟踪启动、结束接口。

HiTraceChain实现在C层，主要原理是在一次业务调用流程中，利用通信传递traceid，在业务处理前将traceid设置到当前线程的TLS(Thread Local Storage)中，业务处理结束清除当前线程的TLS；这样的话，在业务处理中可以从当前线程的上下文TLS取到traceid，自动附加到日志、事件信息中。


### 接口形式对比

  **表1** C++、C的函数接口

|  | **C++** | **C** |
| -------- | -------- | -------- |
| **类** | **函数** | **函数** |
| HiTraceChain | HiTraceId&nbsp;Begin(const&nbsp;std::string&amp;&nbsp;name,&nbsp;int&nbsp;flags) | HiTraceIdStruct&nbsp;HiTraceChainBegin(const&nbsp;char\*&nbsp;name,&nbsp;int&nbsp;flags) |
|  | void&nbsp;End(const&nbsp;HiTraceId&amp;&nbsp;id) | void&nbsp;HiTraceChainEnd(const&nbsp;HiTraceIdStruct\*&nbsp;pId) |
|  | HiTraceId&nbsp;GetId(); | HiTraceIdStruct&nbsp;HiTraceChainGetId() |
|  | void&nbsp;SetId(const&nbsp;HiTraceId&amp;&nbsp;id) | void&nbsp;HiTraceChainSetId(const&nbsp;HiTraceIdStruct\*&nbsp;pId) |
|  | void&nbsp;ClearId() | void&nbsp;HiTraceChainClearId() |
|  | HiTraceId&nbsp;CreateSpan() | HiTraceIdStruct&nbsp;HiTraceChainCreateSpan() |
|  | void&nbsp;Tracepoint(HiTraceTracepointType&nbsp;type,&nbsp;const&nbsp;HiTraceId&amp;&nbsp;id,&nbsp;const&nbsp;char\*&nbsp;fmt,&nbsp;...) | void&nbsp;HiTraceChainTracepoint(HiTraceTracepointType&nbsp;type,&nbsp;const&nbsp;HiTraceIdStruct_&nbsp;pId,&nbsp;const&nbsp;char_&nbsp;fmt,&nbsp;...) |
|  | void&nbsp;Tracepoint(HiTraceCommunicationMode&nbsp;mode,&nbsp;HiTraceTracepointType&nbsp;type,&nbsp;const&nbsp;HiTraceId&amp;&nbsp;id,&nbsp;const&nbsp;char\*&nbsp;fmt,&nbsp;...) | void&nbsp;HiTraceChainTracepointEx(HiTraceCommunicationMode&nbsp;mode,&nbsp;HiTraceTracepointType&nbsp;type,&nbsp;const&nbsp;HiTraceIdStruct_&nbsp;pId,&nbsp;const&nbsp;char_&nbsp;fmt,&nbsp;...) |
| HiTraceId | HiTraceId(); | void&nbsp;HiTraceChainInitId(HiTraceIdStruct\*&nbsp;pId) |
|  | HiTraceId(const&nbsp;uint8_t\*&nbsp;pIdArray,&nbsp;int&nbsp;len) | HiTraceIdStruct&nbsp;HiTraceChainBytesToId(const&nbsp;uint8_t\*&nbsp;pIdArray,&nbsp;int&nbsp;len) |
|  | bool&nbsp;IsValid() | int&nbsp;HiTraceChainIsValid(const&nbsp;HiTraceIdStruct\*&nbsp;pId) |
|  | bool&nbsp;IsFlagEnabled(HiTraceFlag&nbsp;flag) | int&nbsp;HiTraceChainIsFlagEnabled(const&nbsp;HiTraceIdStruct\*&nbsp;pId,&nbsp;HiTraceFlag&nbsp;flag) |
|  | void&nbsp;EnableFlag(HiTraceFlag&nbsp;flag) | void&nbsp;HiTraceChainEnableFlag(HiTraceIdStruct\*&nbsp;pId,&nbsp;HiTraceFlag&nbsp;flag) |
|  | int&nbsp;GetFlags() | int&nbsp;HiTraceChainGetFlags(const&nbsp;HiTraceIdStruct\*&nbsp;pId) |
|  | void&nbsp;SetFlags(int&nbsp;flags) | void&nbsp;HiTraceChainSetFlags(HiTraceIdStruct\*&nbsp;pId,&nbsp;int&nbsp;flags) |
|  | uint64_t&nbsp;GetChainId() | uint64_t&nbsp;HiTraceChainGetChainId(const&nbsp;HiTraceIdStruct\*&nbsp;pId) |
|  | void&nbsp;SetChainId(uint64_t&nbsp;chainId) | void&nbsp;HiTraceChainSetChainId(HiTraceIdStruct\*&nbsp;pId,&nbsp;uint64_t&nbsp;chainId) |
|  | uint64_t&nbsp;GetSpanId() | uint64_t&nbsp;HiTraceChainGetSpanId(const&nbsp;HiTraceIdStruct\*&nbsp;pId) |
|  | void&nbsp;SetSpanId(uint64_t&nbsp;spanId) | void&nbsp;HiTraceChainSetSpanId(HiTraceIdStruct\*&nbsp;pId,&nbsp;uint64_t&nbsp;spanId) |
|  | uint64_t&nbsp;GetParentSpanId() | uint64_t&nbsp;HiTraceChainGetParentSpanId(const&nbsp;HiTraceIdStruct\*&nbsp;pId) |
|  | void&nbsp;SetParentSpanId(uint64_t&nbsp;parentSpanId) | void&nbsp;HiTraceChainSetParentSpanId(HiTraceIdStruct\*&nbsp;pId,&nbsp;uint64_t&nbsp;parentSpanId) |
|  | int&nbsp;ToBytes(uint8_t\*&nbsp;pIdArray,&nbsp;int&nbsp;len) | int&nbsp;HiTraceChainIdToBytes(const&nbsp;HiTraceIdStruct_&nbsp;pId,&nbsp;uint8_t_&nbsp;pIdArray,&nbsp;int&nbsp;len) |


### 接口功能参数

  **表2** C++接口说明函数参数和功能

| **类** | **方法** | **描述** |
| -------- | -------- | -------- |
| HiTraceChain | HiTraceId&nbsp;Begin(const&nbsp;std::string&amp;&nbsp;name,&nbsp;int&nbsp;flags) | 功能：启动HiTraceChain跟踪、生成HiTraceId对象并设置到当前线程TLS中。<br/>输入参数：<br/>-&nbsp;name：业务流程名称。<br/>-&nbsp;flags：跟踪指示位，可以组合使用，具体含义为：<br/>&nbsp;&nbsp;-&nbsp;HITRACE_FLAG_INCLUDE_ASYNC：同时跟踪同步调用和异步调用，缺省只跟踪同步调用。<br/>&nbsp;&nbsp;-&nbsp;HITRACE_FLAG_DONOT_CREATE_SPAN：不创建子分支，缺省创建子分支。<br/>&nbsp;&nbsp;-&nbsp;HITRACE_FLAG_TP_INFO：输出tracepoint信息，缺省不输出。<br/>&nbsp;&nbsp;-&nbsp;HITRACE_FLAG_NO_BE_INFO：不输出起始、结束信息，缺省输出。<br/>&nbsp;&nbsp;-&nbsp;HITRACE_FLAG_DONOT_ENABLE_LOG：不与日志关联输出，缺省关联。<br/>&nbsp;&nbsp;-&nbsp;HITRACE_FLAG_FAULT_TRIGGER：故障触发的跟踪，缺省为正常启动的。<br/>&nbsp;&nbsp;-&nbsp;HITRACE_FLAG_D2D_TP_INFO：输出设备间tracepoint信息，缺省不输出。<br/>&nbsp;&nbsp;-&nbsp;HITRACE_FLAG_DEFAULT:&nbsp;缺省标志。<br/>-&nbsp;输出参数：无<br/>-&nbsp;返回值：启动跟踪超过返回有效HiTraceId对象，否则返回无效对象。<br/>注意：嵌套启动跟踪时，内层启动调用返回无效对象。 |
|  | void&nbsp;End(const&nbsp;HiTraceId&amp;&nbsp;id) | 功能：根据Begin返回的HiTraceId停止HiTraceChain跟踪；清除当前线程TLS中HiTraceId内容。<br/>输入参数：<br/>-&nbsp;id：HiTraceId对象。<br/>输出参数：无。<br/>返回值：无。 |
|  | HiTraceId&nbsp;GetId(); | 功能：从当前线程TLS中获取HiTraceId对象。<br/>输入参数：无。<br/>输出参数：无。<br/>返回值：当前线程上下文的HiTraceId对象。 |
|  | void&nbsp;SetId(const&nbsp;HiTraceId&amp;&nbsp;id) | 功能：设置HiTraceId对象内容到当前线程TLS中。<br/>输入参数：<br/>-&nbsp;id：HiTraceId对象。<br/>输出参数：无。<br/>返回值：无。 |
|  | void&nbsp;ClearId() | 功能：清除当前线程TLS中的HiTraceId对象。<br/>输入参数：无。<br/>输出参数：无。<br/>返回值：无。 |
|  | HiTraceId&nbsp;CreateSpan() | 接口功能：获取当前HiTraceId对象中的分支ID。<br/>输入参数：无。<br/>输出参数：无。<br/>返回值：当前分支ID。 |
|  | void&nbsp;Tracepoint(HiTraceTracepointType&nbsp;type,&nbsp;const&nbsp;HiTraceId&amp;&nbsp;id,&nbsp;const&nbsp;char\*&nbsp;fmt,&nbsp;...) | 功能：根据埋点信息类型输出HiTraceChain埋点信息，包括时间戳、子分支HiTraceId对象信息。<br/>输入参数：<br/>-&nbsp;type：埋点信息类型，具体为<br/>&nbsp;&nbsp;-&nbsp;HITRACE_TP_CS：Client&nbsp;Send，同步/异步通信客户端发送信息。<br/>&nbsp;&nbsp;-&nbsp;HITRACE_TP_SR：Server&nbsp;Receive，&nbsp;同步/异步通信服务端接收信息。<br/>&nbsp;&nbsp;-&nbsp;HITRACE_TP_SS：Server&nbsp;Send，同步通信服务端发送响应信息。<br/>&nbsp;&nbsp;-&nbsp;HITRACE_TP_CR：Client&nbsp;Receive，同步通信客户端接收响应信息。<br/>&nbsp;&nbsp;-&nbsp;HITRACE_TP_GENERAL：普通输出信息。<br/>-&nbsp;id：当前子分支id。<br/>-&nbsp;fmt：格式化变参描述字符串。<br/>-&nbsp;args：变参。<br/>输出参数：无。<br/>返回值：无。 |
|  | void&nbsp;Tracepoint(HiTraceCommunicationMode&nbsp;mode,&nbsp;HiTraceTracepointType&nbsp;type,&nbsp;const&nbsp;HiTraceId&amp;&nbsp;id,&nbsp;const&nbsp;char\*&nbsp;fmt,&nbsp;...) | 功能：根据通信模式、埋点信息类型输出HiTraceChain埋点信息，包括时间戳、子分支HiTraceId对象信息。<br/>输入参数：<br/>-&nbsp;mode：通信模式，具体为<br/>&nbsp;&nbsp;-&nbsp;HITRACE_CM_DEFAULT：未指定通信模式。<br/>&nbsp;&nbsp;-&nbsp;HITRACE_CM_THREAD：线程间通信。<br/>&nbsp;&nbsp;-&nbsp;HITRACE_CM_PROCESS：进程间通信。<br/>&nbsp;&nbsp;-&nbsp;HITRACE_CM_DEVICE：设备间通信。<br/>-&nbsp;type：埋点信息类型，具体为<br/>&nbsp;&nbsp;-&nbsp;HITRACE_TP_CS：Client&nbsp;Send，同步/异步通信客户端发送信息。<br/>&nbsp;&nbsp;-&nbsp;HITRACE_TP_SR：Server&nbsp;Receive，&nbsp;同步/异步通信服务端接收信息。<br/>&nbsp;&nbsp;-&nbsp;HITRACE_TP_SS：Server&nbsp;Send，同步通信服务端发送响应信息。<br/>&nbsp;&nbsp;-&nbsp;HITRACE_TP_CR：Client&nbsp;Receive，同步通信客户端接收响应信息。<br/>&nbsp;&nbsp;-&nbsp;HITRACE_TP_GENERAL：普通输出信息。<br/>-&nbsp;id：当前子分支id。<br/>-&nbsp;fmt：格式化变参描述字符串。<br/>-&nbsp;args：变参。<br/>输出参数：无。<br/>返回值：无。 |
| HiTraceId | HiTraceId(); | 功能：缺省构造函数，生成无效HiTraceId对象。<br/>输入参数：无。<br/>输出参数：无。<br/>返回值：无。 |
|  | HiTraceId(const&nbsp;uint8_t\*&nbsp;pIdArray,&nbsp;int&nbsp;len) | 功能：构造函数，根据字节数组创建跟踪HiTraceId对象。<br/>输入参数：<br/>-&nbsp;pIdArray：字节数组指针。<br/>-&nbsp;len：字节数组长度。<br/>输出参数：无。<br/>返回值：无。 |
|  | bool&nbsp;IsValid() | 功能：HiTraceId对象是否有效。<br/>输入参数：无。<br/>输出参数：无。<br/>返回值：true&nbsp;有效；false&nbsp;无效。 |
|  | bool&nbsp;IsFlagEnabled(HiTraceFlag&nbsp;flag) | 功能：HiTraceId对象的某标志是否置位。<br/>输入参数：<br/>-&nbsp;flag：跟踪指示位，具体含义见Begin函数中的定义。<br/>输出参数：无。<br/>返回值：true&nbsp;该标志置位；false&nbsp;该标志未置位。 |
|  | void&nbsp;EnableFlag(HiTraceFlag&nbsp;flag) | 功能：设置某跟踪标志位到HiTraceId对象中。<br/>输入参数：<br/>-&nbsp;flag：跟踪指示位，具体含义见Begin函数中的定义。<br/>输出参数：无。<br/>返回值：无。 |
|  | int&nbsp;GetFlags() | 功能：获取HiTraceId对象中设置的标志位。<br/>输入参数：无。<br/>输出参数：无。<br/>返回值：跟踪指示位组合，具体含义见Begin函数中的定义。 |
|  | void&nbsp;SetFlags(int&nbsp;flags) | 功能：设置跟踪标志位到HiTraceId对象中。<br/>输入参数：<br/>-&nbsp;flags：跟踪指示位组合，具体含义见Begin函数中的定义。<br/>输出参数：无。<br/>返回值：无。 |
|  | uint64_t&nbsp;GetChainId() | 功能：获取跟踪链ID。<br/>输入参数：无。<br/>输出参数：无。<br/>返回值：跟踪链ID。 |
|  | void&nbsp;SetChainId(uint64_t&nbsp;chainId) | 功能：设置跟踪链ID到HiTraceId对象中。<br/>输入参数：<br/>-&nbsp;chainId：跟踪链ID。<br/>输出参数：无。<br/>返回值：无。 |
|  | uint64_t&nbsp;GetSpanId() | 接口功能：获取当前HiTraceId对象中的分支ID。<br/>输入参数：无。<br/>输出参数：无。<br/>返回值：当前分支ID。 |
|  | void&nbsp;SetSpanId(uint64_t&nbsp;spanId) | 功能：设置分支ID到HiTraceId对象中。<br/>输入参数：<br/>-&nbsp;spanId：分支ID。<br/>输出参数：无。<br/>返回值：无。 |
|  | uint64_t&nbsp;GetParentSpanId() | 功能：获取当前HiTraceId对象中的父分支ID。<br/>输入参数：无。<br/>输出参数：无。<br/>返回值：父分支ID。 |
|  | void&nbsp;SetParentSpanId(uint64_t&nbsp;parentSpanId) | 功能：设置父分支ID到HiTraceId对象中。<br/>输入参数：<br/>-&nbsp;parentSpanId：父分支ID。<br/>输出参数：无。<br/>返回值：无。 |
|  | int&nbsp;ToBytes(uint8_t\*&nbsp;pIdArray,&nbsp;int&nbsp;len) | 功能：将HiTraceId对象转换为字节数组，便于缓存或者通信传递。<br/>输入参数：<br/>-&nbsp;pIdArray：字节数组指针，数组长度至少为HITRACE_ID_LEN。<br/>-&nbsp;len:&nbsp;字节数组长度<br/>输出参数：<br/>-&nbsp;pIdArray：字节数组指针，对象有效时存储转换后的对象数据。<br/>返回值：0&nbsp;转换失败；&nbsp;&amp;gt;0&nbsp;有效对象转换数组长度。 |


## 通信调用处理

业务使用时跨设备/跨进程/跨线程的调用是通过通信机制实现的，HiTraceChain需要通信机制传递traceid。

OpenHarmony系统内置部分通信机制（如ZIDL）已经支持传递traceid。

下面描述了同步通信调用传递traceid的处理过程，异步通信调用处理类似。

  对于不支持的扩展通信机制可以参照该方式实现。
  **图5** 同步通信处理
  ![zh-cn_image_0000001261032707](figures/zh-cn_image_0000001261032707.png)

处理流程：

1. client侧业务模块调用begin()接口启动调用链跟踪。

2. client侧业务模块发起同步调用transact，到client侧通信组件。

3. client侧通信组件：
   1. 从当前线程TLS中获取traceid。
   2. 生成子调用分支（child traceid）。
   3. 将child traceid写入同步调用通信数据（transaction data）中。
   4. 进行CS埋点（Client Send）。
   5. 将通信数据发送到server侧通信组件。

4. server侧通信组件收到通信数据：
   1. 从数据消息包中取出traceid。
   2. 将traceid设置到当前线程TLS中。
   3. 进行SR埋点（Server Receive）。
   4. 然后进行同步调用回调（onTransact）到server侧业务模块。

5. server侧业务模块进行服务处理，处理完毕发送处理结果（transact reply）到通信组件。

6. server侧通信组件：
   1. 进行SS埋点（Server Send）。
   2. 将响应数据发送到client侧通信组件。
   3. 清除当前线程TLS中的traceid信息。

7. client侧通信组件收到响应数据：
   1. 进行CR埋点（Client Receive）。
   2. 发送同步调用响应（transact reply）到client侧业务模块。

8. client侧业务模块进行同步调用响应处理。

9. client侧业务模块在流程结束时调用end()接口停止调用链跟踪。


## 开发实例


### C++接口实例

1. 源代码开发
     在类定义头文件或者类实现源文件中，包含hitracechain头文件：
     
   ```
   #include "hitrace/tracechain.h"
   ```

     在业务类实现源文件中使用（启动/结束跟踪）：
   
   ```
   using namespace OHOS::HiviewDFX;
   auto traceId = HiTraceChain::Begin("MyServiceFlow", HITRACE_FLAG_DEFAULT);
   ......
   HiTraceChain::End(traceId);
   ```

2. 编译设置，在BUILD.gn里增加子系统SDK依赖：
   
   ```
   external_deps = [ "hiviewdfx:libhitracechain" ]
   ```


### C接口实例

1. 源代码开发
     在源文件中，包含hitracechain头文件：
     
   ```
   #include "hitrace/tracechain.h"
   ```

     在业务类实现源文件中使用（启动/结束跟踪）：
   
   ```
   HiTraceIdStruct traceId = HiTraceChainBegin("MyServiceFlow", HITRACE_FLAG_DEFAULT);
   ......
   HiTraceChainEnd(traceId);
   ```

2. 编译设置，在BUILD.gn里增加子系统SDK依赖：
   
   ```
   external_deps = [ "hiviewdfx:libhitracechain" ]
   ```
