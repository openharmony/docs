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
| HiTraceChain | HiTraceId Begin(const std::string&amp; name, int flags) | HiTraceIdStruct HiTraceChainBegin(const char* name, int flags) |
|  | void End(const HiTraceId&amp; id) | void HiTraceChainEnd(const HiTraceIdStruct* pId) |
|  | HiTraceId GetId() | HiTraceIdStruct HiTraceChainGetId() |
|  | void SetId(const HiTraceId&amp; id) | void HiTraceChainSetId(const HiTraceIdStruct* pId) |
|  | void ClearId() | void HiTraceChainClearId() |
|  | HiTraceId CreateSpan() | HiTraceIdStruct HiTraceChainCreateSpan() |
|  | void Tracepoint(HiTraceTracepointType type, const HiTraceId&amp; id, const char* fmt, ...) | void HiTraceChainTracepoint(HiTraceTracepointType type, const HiTraceIdStruct* pId, const char* fmt, ...) |
|  | void Tracepoint(HiTraceCommunicationMode mode, HiTraceTracepointType type, const HiTraceId&amp; id, const char* fmt, ...) | void HiTraceChainTracepointEx(HiTraceCommunicationMode mode, HiTraceTracepointType type, const HiTraceIdStruct* pId, const char* fmt, ...) |
| HiTraceId | HiTraceId() | void HiTraceChainInitId(HiTraceIdStruct* pId) |
|  | HiTraceId(const uint8_t* pIdArray, int len) | HiTraceIdStruct HiTraceChainBytesToId(const uint8_t* pIdArray, int len) |
|  | bool IsValid() | int HiTraceChainIsValid(const HiTraceIdStruct* pId) |
|  | bool IsFlagEnabled(HiTraceFlag flag) | int HiTraceChainIsFlagEnabled(const HiTraceIdStruct* pId, HiTraceFlag flag) |
|  | void EnableFlag(HiTraceFlag flag) | void HiTraceChainEnableFlag(HiTraceIdStruct* pId, HiTraceFlag flag) |
|  | int GetFlags() | int HiTraceChainGetFlags(const HiTraceIdStruct* pId) |
|  | void SetFlags(int flags) | void HiTraceChainSetFlags(HiTraceIdStruct* pId, int flags) |
|  | uint64_t GetChainId() | uint64_t HiTraceChainGetChainId(const HiTraceIdStruct* pId) |
|  | void SetChainId(uint64_t chainId) | void HiTraceChainSetChainId(HiTraceIdStruct* pId, uint64_t chainId) |
|  | uint64_t GetSpanId() | uint64_t HiTraceChainGetSpanId(const HiTraceIdStruct* pId) |
|  | void SetSpanId(uint64_t spanId) | void HiTraceChainSetSpanId(HiTraceIdStruct* pId, uint64_t spanId) |
|  | uint64_t GetParentSpanId() | uint64_t HiTraceChainGetParentSpanId(const HiTraceIdStruct* pId) |
|  | void SetParentSpanId(uint64_t parentSpanId) | void HiTraceChainSetParentSpanId(HiTraceIdStruct* pId, uint64_t parentSpanId) |
|  | int ToBytes(uint8_t* pIdArray, int len) | int HiTraceChainIdToBytes(const HiTraceIdStruct_ pId, uint8_t* pIdArray, int len) |


### 接口功能参数

  **表2** 跟踪标志组合类型枚举

| **名称** | **值** | **说明** |
| -------- | -------- | -------- |
| HITRACE_FLAG_DEFAULT           | 0      | 缺省标志。       |
| HITRACE_FLAG_INCLUDE_ASYNC | 1      | 异步调用标志。启动跟踪时，缺省只跟踪同步调用。设置该标志，同时跟踪同步、异步调用。   |
| HITRACE_FLAG_DONOT_CREATE_SPAN | 1 << 1 | 无分支标志。启动跟踪时，在同步、异步调用时缺省自动创建分支信息。设置该标志，指示不创建分支。     |
| HITRACE_FLAG_TP_INFO           | 1 << 2 | 埋点标志。启动跟踪式时，缺省不进行埋点。调试场景下设置该标志，在同步、异步调用的收发侧自动埋点，输出埋点信息和时间戳。收发埋点按照client、server分为client send（CS）、server receive（SR）、server send（SS）、client receive（CR）四类信息。一次同步调用输出CS/SR/SS/CR，一次异步调用输出CS/SR/SS三个埋点信息。       |
| HITRACE_FLAG_NO_BE_INFO        | 1 << 3 | 无起始结束标志。启动跟踪时，缺省打印启动及结束跟踪信息。设置该标志，指示不打印启动及结束跟踪信息。 |
| HITRACE_FLAG_DONOT_ENABLE_LOG       | 1 << 4 | 日志关联标志。设置该标志，指示隐藏日志中的跟踪信息。  |
| HITRACE_FLAG_FAULT_TRIGGER   | 1 << 5 | 故障触发标志。预置标志，暂时没有作用。  |
| HITRACE_FLAG_D2D_TP_INFO       | 1 << 6 | 设备间埋点标志。TP_INFO的一个子集，设置该标志，只进行设备间的调用埋点。 |

  **表3** 跟踪埋点类型枚举

| **名称** | **值** | **说明** |
| -------- | -------- | -------- |
| HITRACE_TP_CS       | 0 | 客户端发送类型，标识client侧的发送埋点。        |
| HITRACE_TP_CR       | 1 | 客户端接收类型，标识client侧的接收埋点。        |
| HITRACE_TP_SS       | 2 | 服务端发送类型，标识server侧的发送埋点。        |
| HITRACE_TP_SR       | 3 | 服务端接收类型，标识server侧的接收埋点。        |
| HITRACE_TP_GENERAL  | 4 | 一般类型，标识CS、CR、SS、SR四种场景之外的埋点。|

  **表4** 跟踪通信类型枚举

| **名称** | **值** | **说明** |
| -------- | -------- | -------- |
| HITRACE_CM_DEFAULT  | 0 | 缺省通信类型    |
| HITRACE_CM_THREAD   | 1 | 线程间通信类型  |
| HITRACE_CM_PROCESS  | 2 | 进程间通信类型  |
| HITRACE_CM_DEVICE   | 3 | 设备间通信类型  |

  **表5** C++接口说明函数参数和功能

| **类** | **方法** | **描述** |
| -------- | -------- | -------- |
| HiTraceChain | HiTraceId Begin(const std::string&amp; name, int flags) | 功能：启动HiTraceChain跟踪、生成HiTraceId对象并设置到当前线程TLS中。<br/>输入参数：<br/>- name：业务流程名称。<br/>- flags：跟踪指示位，可以组合使用，具体说明请参考**表2** 跟踪标志组合类型枚举。<br/>- 输出参数：无。<br/>- 返回值：启动跟踪超过返回有效HiTraceId对象，否则返回无效对象。<br/>注意：嵌套启动跟踪时，内层启动调用返回无效对象。 |
|  | void End(const HiTraceId&amp; id) | 功能：根据Begin返回的HiTraceId停止HiTraceChain跟踪；清除当前线程TLS中HiTraceId内容。<br/>输入参数：<br/>- id：HiTraceId对象。<br/>输出参数：无。<br/>返回值：无。 |
|  | HiTraceId GetId() | 功能：从当前线程TLS中获取HiTraceId对象。<br/>输入参数：无。<br/>输出参数：无。<br/>返回值：当前线程上下文的HiTraceId对象。 |
|  | void SetId(const HiTraceId&amp; id) | 功能：设置HiTraceId对象内容到当前线程TLS中。<br/>输入参数：<br/>- id：HiTraceId对象。<br/>输出参数：无。<br/>返回值：无。 |
|  | void ClearId() | 功能：清除当前线程TLS中的HiTraceId对象。<br/>输入参数：无。<br/>输出参数：无。<br/>返回值：无。 |
|  | HiTraceId CreateSpan() | 接口功能：获取当前HiTraceId对象中的分支ID。<br/>输入参数：无。<br/>输出参数：无。<br/>返回值：当前分支ID。 |
|  | void Tracepoint(HiTraceTracepointType type, const HiTraceId&amp; id, const char* fmt, ...) | 功能：根据埋点信息类型输出HiTraceChain埋点信息，包括时间戳、子分支HiTraceId对象信息。<br/>输入参数：<br/>- type：埋点信息类型，具体说明请参考**表3** 跟踪埋点类型枚举。<br/>- id：当前子分支id。<br/>- fmt：格式化变参描述字符串。<br/>- args：变参。<br/>输出参数：无。<br/>返回值：无。 |
|  | void Tracepoint(HiTraceCommunicationMode mode, HiTraceTracepointType type, const HiTraceId&amp; id, const char* fmt, ...) | 功能：根据通信模式、埋点信息类型输出HiTraceChain埋点信息，包括时间戳、子分支HiTraceId对象信息。<br/>输入参数：<br/>- mode：通信模式，具体说明请参考**表4** 跟踪通信类型枚举。<br/>- type：埋点信息类型，具体说明请参考**表3** 跟踪埋点类型枚举。<br/>- id：当前子分支id。<br/>- fmt：格式化变参描述字符串。<br/>- args：变参。<br/>输出参数：无。<br/>返回值：无。 |
| HiTraceId | HiTraceId(); | 功能：缺省构造函数，生成无效HiTraceId对象。<br/>输入参数：无。<br/>输出参数：无。<br/>返回值：无。 |
|  | HiTraceId(const uint8_t* pIdArray, int len) | 功能：构造函数，根据字节数组创建跟踪HiTraceId对象。<br/>输入参数：<br/>- pIdArray：字节数组指针。<br/>- len：字节数组长度。<br/>输出参数：无。<br/>返回值：无。 |
|  | bool IsValid() | 功能：HiTraceId对象是否有效。<br/>输入参数：无。<br/>输出参数：无。<br/>返回值：true 有效；false 无效。 |
|  | bool IsFlagEnabled(HiTraceFlag flag) | 功能：HiTraceId对象的某标志是否置位。<br/>输入参数：<br/>- flag：跟踪指示位，具体含义见Begin函数中的定义。<br/>输出参数：无。<br/>返回值：true 该标志置位；false 该标志未置位。 |
|  | void EnableFlag(HiTraceFlag flag) | 功能：设置某跟踪标志位到HiTraceId对象中。<br/>输入参数：<br/>- flag：跟踪指示位，具体含义见Begin函数中的定义。<br/>输出参数：无。<br/>返回值：无。 |
|  | int GetFlags() | 功能：获取HiTraceId对象中设置的标志位。<br/>输入参数：无。<br/>输出参数：无。<br/>返回值：跟踪指示位组合，具体含义见Begin函数中的定义。 |
|  | void SetFlags(int flags) | 功能：设置跟踪标志位到HiTraceId对象中。<br/>输入参数：<br/>- flags：跟踪指示位组合，具体含义见Begin函数中的定义。<br/>输出参数：无。<br/>返回值：无。 |
|  | uint64_t GetChainId() | 功能：获取跟踪链ID。<br/>输入参数：无。<br/>输出参数：无。<br/>返回值：跟踪链ID。 |
|  | void SetChainId(uint64_t chainId) | 功能：设置跟踪链ID到HiTraceId对象中。<br/>输入参数：<br/>- chainId：跟踪链ID。<br/>输出参数：无。<br/>返回值：无。 |
|  | uint64_t GetSpanId() | 接口功能：获取当前HiTraceId对象中的分支ID。<br/>输入参数：无。<br/>输出参数：无。<br/>返回值：当前分支ID。 |
|  | void SetSpanId(uint64_t spanId) | 功能：设置分支ID到HiTraceId对象中。<br/>输入参数：<br/>- spanId：分支ID。<br/>输出参数：无。<br/>返回值：无。 |
|  | uint64_t GetParentSpanId() | 功能：获取当前HiTraceId对象中的父分支ID。<br/>输入参数：无。<br/>输出参数：无。<br/>返回值：父分支ID。 |
|  | void SetParentSpanId(uint64_t parentSpanId) | 功能：设置父分支ID到HiTraceId对象中。<br/>输入参数：<br/>- parentSpanId：父分支ID。<br/>输出参数：无。<br/>返回值：无。 |
|  | int ToBytes(uint8_t* pIdArray, int len) | 功能：将HiTraceId对象转换为字节数组，便于缓存或者通信传递。<br/>输入参数：<br/>- pIdArray：字节数组指针，数组长度至少为HITRACE_ID_LEN。<br/>- len: 字节数组长度<br/>输出参数：<br/>- pIdArray：字节数组指针，对象有效时存储转换后的对象数据。<br/>返回值：0 转换失败； &amp;gt;0 有效对象转换数组长度。 |


### 通信调用处理

业务使用时跨设备/跨进程/跨线程的调用是通过通信机制实现的，HiTraceChain需要通信机制传递traceid。

OpenHarmony系统内置部分通信机制（如ZIDL）已经支持传递traceid。

下面描述了同步通信调用传递traceid的处理过程，异步通信调用处理类似。

  对于不支持的扩展通信机制可以参照该方式实现。<br>
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
   external_deps = [ "hitrace:libhitracechain" ]
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
   external_deps = [ "hitrace:libhitracechain" ]
   ```
