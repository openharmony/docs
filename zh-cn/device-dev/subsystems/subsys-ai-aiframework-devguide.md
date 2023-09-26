# AI框架开发指导

## 概述

### 功能简介
AI业务子系统是OpenHarmony提供原生的分布式AI能力的子系统。AI业务子系统提供了统一的AI引擎框架，实现算法能力快速插件化集成。
AI引擎框架主要包含插件管理、模块管理和通信管理模块，完成对AI算法能力的生命周期管理和按需部署。插件管理主要实现插件的生命周期管理及插件的按需部署，快速集成AI能力插件；模块管理主要实现任务的调度及管理客户端的实例；通信管理主要实现客户端和服务端之间的跨进程通信管理及AI服务与插件之间的数据传输。后续，会逐步定义统一的AI能力接口，便于AI能力的分布式调用。同时，框架提供适配不同推理框架层级的统一推理接口。
AI引擎框架结构如下图所示。


  **图1** AI引擎框架
  ![zh-cn_image_0000001200128073](figures/zh-cn_image_0000001200128073.png)

### 搭建环境


1. 准备开发板：Hi3516DV300或Hi3518EV300

2. [下载源码](../get-code/sourcecode-acquire.md)

## 技术规范

### 代码管理规范

AI引擎框架包含client、server和common三个主要模块，其中client提供server端连接管理功能，OpenHarmony SDK在算法对外接口中需封装调用client提供的公共接口；server提供插件加载以及任务管理等功能，各Plugin实现由server提供的插件接口，完成插件接入；common提供与平台相关的操作方法、引擎协议以及相关工具类，供其他各模块调用。


AI引擎框架各模块之间的代码依赖关系如下图所示：


  **图1** AI引擎代码依赖关系

  ![zh-cn_image_0000001151931738](figures/zh-cn_image_0000001151931738.jpg)


#### 建议：插件与OpenHarmony SDK在AI引擎指定的路径下进行代码开发

在AI引擎框架的整体规划中，OpenHarmony SDK属于client端的一部分，插件由server端调用，属于server端的一部分，因此AI引擎框架为接入的插件与OpenHarmony SDK规划的路径：

- SDK代码路径：//foundation/ai/engine/services/client/algorithm_sdk
  
  示例1：//foundation/ai/engine/services/client/algorithm_sdk/cv

  示例2：//foundation/ai/engine/services/client/algorithm_sdk/nlu

- 插件代码路径：//foundation/ai/engine/services/server/plugin
  
  示例1：//foundation/ai/engine/services/server/plugin/cv

  示例2：//foundation/ai/engine/services/server/plugin/nlu


#### 规则：插件提供的全部对外接口，统一存放在AI业务子系统interfaces/kits目录

OpenHarmony SDK对外接口是AI业务子系统提供能力的对外暴露方式，按照OpenHarmony的接口管理要求，需统一存放在各子系统的interfaces/kits目录中。当前AI业务子系统插件对外接口路径为//foundation/ai/engine/interfaces/kits，不同插件可在该路径下添加目录，比如增加cv插件，则在路径//foundation/ai/engine/interfaces/kits/cv下面存放接口文件。


#### 规则：插件编译输出路径必须是在/usr/lib

server端加载插件是采用dlopen方式，只支持在/usr/lib路径进行，因此插件在编译so时，需要在编译配置文件中指定输出路径为/usr/lib。

### 命名规范

#### SDK命名规则：领域_关键词&lt;_其他信息1_其他信息2_…&gt;_sdk.so

关于领域，建议使用当前主流简称，比如图片视频相关的使用"cv"，语音识别相关的使用“asr”，翻译相关的使用“translation”等，存在其他领域的可增加定义；关键词则需要恰当准确的描述所对应插件的算法能力，比如唤醒词识别，则使用keyword_spotting；对于其他信息，比如插件支持的芯片类型、国内海外等信息，可在关键词与“sdk”之间依次添加，信息之间以下划线连接；SDK命名，必须以“_sdk”结尾。

例如：唤醒词识别插件对应的SDK，只支持麒麟9000芯片，适用于中国国内地区适用，则对应的SDK命名为：asr_keyword_spotting_kirin9000_china_sdk.so


#### 插件命名规则：领域_关键词&lt;_其他信息1_其他信息2_…&gt;.so

插件与SDK存在一一对应的关系，故插件命名的领域、关键词、其他信息等名词解释与要求，均与SDK命名要求保持一致。两者唯一的不同之处在于SDK命名多了个“_sdk”结尾；比如插件命名为“asr_keyword_spotting.so”，则对应SDK命名为“asr_keyword_spotting_sdk.so”。

例如：唤醒词识别插件对应的SDK，只支持麒麟9000芯片，适用于中国国内地区适用，则对应的插件命名为：asr_keyword_spotting_kirin9000_china.so

### 接口开发规范

#### 规则：SDK需按算法调用顺序，封装client对外提供接口；对于异步插件对应的SDK，需要实现client提供的回调接口IClientCb

AI引擎的client端对外提供的接口包括AieClientInit、AieClientPrepare、AieClientSyncProcess、AieClientAsyncProcess、AieClientRelease、AieClientDestroy、AieClientSetOption、AieClientGetOption，SDK需要根据插件的接口按照顺序至少封装AieClientInit、AieClientPrepare、AieClientSyncProcess/AieClientAsyncProcess、AieClientRelease、AieClientDestroy五个接口，否则会出现调用问题或者内存泄漏。比如封装过程遗漏了AieClientPrepare接口，则server端无法完成插件加载，故后面的接口都无法调用成功。

对于异步插件，SDK需要实现IClientCb接口，用于接收来自client端的算法推理结果，并将该结果返回给三方调用者。


#### 规则：SDK接口实现中，需要保存与client交互的相关通用数据

AI引擎将的client端采用单例实现，对接多个SDK，因此各SDK需要保存与client交互的通用数据，用于连接server端进行任务推理、结果返回等；需保存数据包含clientInfo、algorithmInfo、configInfo三种数据类型，定义在SDK的成员变量里即可。


#### 建议：SDK实现client定义的IServiceDeadCb接口

Server端是系统常驻进程，以系统能力的形式为多个client提供服务；client定义的IServiceDeadCb接口，是在server端异常死亡后，会被触发调用。这种异常场景，SDK可在死亡通知接口中，实现相关操作，比如停止调用或者再次拉起server端等。

IServiceDeadCb接口实现示例：


```
class ServiceDeadCb : public IServiceDeadCb {
public:
ServiceDeadCb() = default;
~ServiceDeadCb() override = default;
void OnServiceDead() override
{
printf("[ServiceDeadCb]OnServiceDead Callback happens");
}
};
```

如上示例，SDK可在OnServiceDead()方法中实现自己的操作，比如停止所有的接口调用等等。


#### 规则：SDK与plugin需要使用编解码模块，将特定算法数据转换成AI引擎的通用数据类型

插件的推理数据，会由三方调用者通过client、server传递到插件中；不同的算法所需要的数据类型是不一致的，比如cv的需要图片数据、asr的需要语音数据；为了适配数据类型的差异，AI引擎对外提供了对基本数据类型的编解码能力，将不同数据类型转换为AI引擎可以使用的通用数据类型。

编码后的数据类型定义：


```
struct DataInfo {
unsigned char *data;
int length;
} DataInfo;

```

如上示例，DataInfo数据结构包括指向数据内存的指针和数据长度两个变量组成。

框架接口使用方法：

1.添加依赖的头文件："utils/encdec/include/encdec.h"。

2.添加build.gn中的依赖项：

include_dirs添加"//foundation/ai/engine/services/common"。

deps添加"//foundation/ai/engine/services/common/utils/encdec:encdec" 。

3.编解码示例：


```
// 编码调用函数示例：arg1，arg2，arg3等为需编码的变量，dataInfo为编码后的结果
retCode = ProcessEncode(dataInfo, arg1, arg2, arg3) //可以接收任意多个参数
// 解码调用函数示例:dataInfo为需要解码的信息，arg1，arg2，arg3等为解码后的结果
retCode = ProcessDecode(dataInfo, arg1, arg2, arg3) //可以接收任意多个参数
```

注意：

- 编码和解码调用时的参数顺序需要保证一致。

- 编码后dataInfo的内存需要调用者手动进行释放。

- server端和client端的内存是分开管理和释放的。

- 如果包含共享内存的指针，不需要额外处理。

- 如果其他类型的指针，则需要解引用后使用ProcessEncode/ ProcessDecode。

- 该编解码模块未适配class数据类型，不建议使用。


#### 规则：在SDK中，对以编解码返回的出参数据类型，需要进行内存释放，否则会出现内存泄漏

编码得到的通用数据，本质上是将不同类型数据封装在同一块内存中，然后将这块内存的首地址与长度封装到结构体中。通过编码返回到SDK中的出参数据，在插件中申请了内存，但插件无法释放；因此SDK在拿到数据之后，需要对内存进行释放，否则SDK将无法拿到数据。

内存释放示例：


```
DataInfo outputInfo = {
.data = nullptr,
.length = 0,
};
AieClientPrepare(clientInfo_, algorithmInfo_, inputInfo, outputInfo, nullptr);
if (outputInfo.data != nullptr) {
free(outputInfo.data);
outputInfo.data = nullptr;
outputInfo.length = 0;
}
```


#### 规则：plugin需要实现server定义的IPlugin接口，并使用宏PLUGIN_INTERFACE_IMPL对外提供插件函数指针

Server端管理的插件内部接口实现逻辑各不相同，为了统一插件的加载流程，AI引擎定义了插件接口IPlugin；在运行态，插件是以动态链接库的形式被AI引擎框架通过dlopen方式加载，各插件需要使用PLUGIN_INTERFACE_IMPL语句对外暴露函数指针，否则插件将无法被正常加载使用。


#### 规则：plugin需要使用AI引擎提供的统一数据通道

AI引擎在server与插件之间，提供了一个统一的数据通道，用来处理来自SDK的推理请求和来自插件的结果返回；plugin在推理接口中，需按数据通道完成请求数据的获取以及推理结果的封装。

数据通道使用示例：


```
int SyncProcess(IRequest *request, IResponse *&response)
{
HILOGI("[IvpPlugin]Begin SyncProcess");
if (request == nullptr) {
HILOGE("[IvpPlugin]SyncProcess request is nullptr");
return RETCODE_NULL_PARAM;
}
DataInfo inputInfo = request->GetMsg();
if (inputInfo.data == nullptr) {
HILOGE("[IvpPlugin]InputInfo data is nullptr");
return RETCODE_NULL_PARAM;
}

...

response = IResponse::Create(request);
response->SetResult(outputInfo);
return RETCODE_SUCCESS;
}
```

示例中request和response是数据通道的内容主体。server端会将数据封装在request中，传递到插件，插件进行算法处理之后，则需要将结果封装成response进行返回。

## 开发指导

### 开发SDK

SDK头文件的功能实现是基于对SDK的调用映射到对客户端的调用。Client端提供的接口如下表所示。


  **表1** Client端提供的接口

| 接口名 | 接口说明 | 参数要求 |
| -------- | -------- | -------- |
| int&nbsp;**AieClientInit**(const&nbsp;ConfigInfo&nbsp;&amp;configInfo,<br/>&nbsp;ClientInfo&nbsp;&amp;clientInfo,&nbsp;const&nbsp;AlgorithmInfo<br/>&nbsp;&amp;algorithmInfo,&nbsp;IServiceDeadCb&nbsp;\*cb) | **作用**：链接并初始化引擎服务，激活跨进程调用。<br/>**返回值**：0为成功，其他返回值失败。 | **configInfo**（不能为NULL）：引擎相关初始化配置数据 <br/>**clientInfo**（不能为NULL）：引擎客户端信息 <br/>**algorithmInfo**（不能为NULL）：调用算法信息 <br/>**cb**（可为NULL）：死亡回调对象  |
| int&nbsp;**AieClientPrepare**(const&nbsp;ClientInfo&nbsp;&amp;clientInfo<br/>,&nbsp;const&nbsp;AlgorithmInfo&nbsp;&amp;algorithmInfo,&nbsp;const&nbsp;DataInfo<br/>&nbsp;&amp;inputInfo,&nbsp;DataInfo&nbsp;&amp;outputInfo,&nbsp;IClientCb&nbsp;\*cb) | **作用**：加载算法插件。<br/>**返回值**：&nbsp;0为成功，其他返回值失败。 | **clientInfo**（不能为NULL）：引擎客户端信息 <br/>**algorithmInfo**（不能为NULL）：调用算法信息 <br/>**inputInfo**（可为NULL）：加载算法插件时输入所需信息 <br/>**outputInfo**（可为NULL）：加载算法插件之后如需返回信息则通过此出参返回 <br/>**cb**：异步算法通过此回调返回运算结果，因此**异步算法此结构体不能为空** 若为同步算法，传入空值即可  |
| int&nbsp;**AieClientAsyncProcess**(const&nbsp;ClientInfo&nbsp;&amp;clientInfo,<br/>&nbsp;const&nbsp;AlgorithmInfo&nbsp;&amp;algorithmInfo,&nbsp;const&nbsp;DataInfo<br/>&nbsp;&amp;inputInfo) | **作用**：执行异步算法。<br/>**返回值**：0为成功，其他返回值失败。 | **clientInfo**（不能为NULL）：引擎客户端信息 <br/>**algorithmInfo**（不能为NULL）：调用算法信息 <br/>**inputInfo**（可为NULL）：算法运算入参  |
| int&nbsp;**AieClientSyncProcess**(const&nbsp;ClientInfo&nbsp;&amp;clientInfo,<br/>&nbsp;const&nbsp;AlgorithmInfo&nbsp;&amp;algorithmInfo,&nbsp;const<br/>&nbsp;DataInfo&nbsp;&amp;inputInfo,&nbsp;DataInfo&nbsp;&amp;outputInfo) | **作用**：执行同步算法。<br/>**返回值**：0为成功，其他返回值失败。 | **clientInfo**（不能为NULL）：引擎客户端信息 <br/>**algorithmInfo**（不能为NULL）：调用算法信息 <br/>**inputInfo**（可为NULL）：算法运算入参 <br/>**outputInfo**（可为NULL）：同步算法运算结果出参  |
| int&nbsp;**AieClientRelease**(const&nbsp;ClientInfo&nbsp;&amp;clientInfo,<br/>&nbsp;const&nbsp;AlgorithmInfo&nbsp;&amp;algorithmInfo,&nbsp;const<br/>&nbsp;DataInfo&nbsp;&amp;inputInfo) | **作用**：卸载算法插件。<br/>**返回值**：0为成功，其他返回值失败。 | **clientInfo**（不能为NULL）：引擎客户端信息 <br/>**algorithmInfo**（不能为NULL）：卸载算法插件的相关信息 <br/>**inputInfo**（可为NULL）：调用卸载接口时的输入信息  |
| int&nbsp;**AieClientDestroy**(ClientInfo&nbsp;&amp;clientInfo) | **作用**：断开与服务端的链接，释放相关缓存。<br/>**返回值**：0为成功，其他返回值失败。 | **clientInfo**（不能为NULL）：所要销毁的引擎客户端信息  |
| int&nbsp;**AieClientSetOption**(const&nbsp;ClientInfo&nbsp;&amp;clientInfo,<br/>&nbsp;int&nbsp;optionType,&nbsp;const&nbsp;DataInfo&nbsp;&amp;inputInfo) | **作用**：设置配置项，可将一些算法的拓展信息通过此接口传入插件。<br/>**返回值**：0为成功，其他返回值失败。 | **clientInfo**（不能为NULL）：引擎客户端信息 <br/>**optionType**&nbsp;（不能为NULL）：算法配置项，算法插件可根据需要利用此状态位 <br/>**inputInfo**（可为NULL）：插件可根据需要通过此入参设置算法参数信息  |
| int&nbsp;**AieClientGetOption**(const&nbsp;ClientInfo&nbsp;&amp;clientInfo,<br/>&nbsp;int&nbsp;optionType,&nbsp;const&nbsp;DataInfo&nbsp;&amp;inputInfo,<br/>&nbsp;DataInfo&nbsp;&amp;outputInfo) | **作用**：给定特定的optionType和inputInfo，获取其对应的配置项信息。<br/>**返回值**：0为成功，其他返回值失败。 | **clientInfo**（不能为NULL）：引擎客户端信息 <br/>**optionType**（不能为NULL）：所获取配置项信息的对应算法状态位 <br/>**inputInfo**（可为NULL）：所获取配置项信息的对应算法参数信息 <br/>**outputInfo**（可为NULL）：所要获取的配置项信息返回结果  |


其中，ConfigInfo，ClientInfo，AlgorithmInfo，DataInfo的数据结构如下表所示。


  **表2** ConfigInfo，ClientInfo，AlgorithmInfo，DataInfo的数据结构

| 结构体名称 | 说明 | 属性 |
| -------- | -------- | -------- |
| ConfigInfo | 算法配置项信息。 | **const&nbsp;char&nbsp;\*description**：配置项信息主体  |
| ClientInfo | 客户端信息。 | **long&nbsp;long&nbsp;clientVersion**：客户端设备版本号（当前还未启用） <br/>**int&nbsp;clientId**：客户端ID <br/>**int&nbsp;sessionId**：会话ID <br/>**uid_t&nbsp;serverUid**：server端UID <br/>**uid_t&nbsp;clientUid**：client端UID <br/>**int&nbsp;extendLen**：拓展信息（extendMsg）长度 <br/>**unsigned&nbsp;char&nbsp;\*extendMsg**：拓展信息主体  |
| AlgorithmInfo | 算法信息。 | **long&nbsp;long&nbsp;clientVersion**：客户端设备版本号（当前还未启用） <br/>**bool&nbsp;isAsync**：是否为异步执行 <br/>**int&nbsp;algorithmType**：引擎框架根据插件加载顺序分配的算法类型ID <br/>**long&nbsp;long&nbsp;algorithmVersion**：算法版本号 <br/>**bool&nbsp;isCloud**：是否上云（当前还未启用） <br/>**int&nbsp;operateId**：执行ID（当前还未启用） <br/>**int&nbsp;requestId**：请求ID，标识每次request，以对应执行结果 <br/>**int&nbsp;extendLen**：拓展信息（extendMsg）长度 <br/>**unsigned&nbsp;char&nbsp;\*extendMsg**：拓展信息主体  |
| DataInfo | 算法数据入参(inputInfo)、<br/>接口调用结果出参(outputInfo)。 | **unsigned&nbsp;char&nbsp;\*data**：数据主体 <br/>**int&nbsp;length**：数据(data)长度  |


具体开发过程可参考[唤醒词识别SDK开发示例](#唤醒词识别sdk的开发示例)。

### 开发插件
AI引擎框架规定了一套算法插件接入规范，各插件需实现规定接口以实现获取插件版本信息、算法推理类型、同步执行算法、异步执行算法、加载算法插件、卸载算法插件、设置算法配置信息、获取指定算法配置信息等功能。（同步算法实现SyncProcess接口，异步算法实现AsyncProcess接口）。


算法插件类IPlugin接口设计如下表所示。


  **表1** 算法插件类IPlugin接口设计

| 接口名 | 接口说明 | 参数要求 |
| -------- | -------- | -------- |
| const&nbsp;long&nbsp;long&nbsp;GetVersion()&nbsp;const; | **作用**：获取插件版本信息。<br/>**返回值**：版本号（long&nbsp;long） | - |
| const&nbsp;char&nbsp;\*GetInferMode()&nbsp;const; | **作用**：获取算法推理类型。<br/>**返回值**："SYNC"&nbsp;or&nbsp;"ASYNC"; | - |
| int&nbsp;SyncProcess(IRequest&nbsp;\*request,<br/>IResponse&nbsp;\*&amp;response); | **作用**：执行插件同步算法。<br/>**返回值**：0为成功，其他返回值为失败。 | **request**(NOT&nbsp;NULL)：用于向算法插件传递请求内容；引擎服务端与插件的数据通道。<br/>**response**(NOT&nbsp;NULL)：作为出参用于接收算法插件发回的同步算法执行结果，引擎服务端与插件的数据通道。 |
| int&nbsp;AsyncProcess(IRequest&nbsp;\*request,<br/>IPluginAlgorithmCallback&nbsp;\*callback); | **作用**：执行异步算法。<br/>**返回值**：0为成功，其他返回值为失败。 | **request**(NOT&nbsp;NULL)：用于向算法插件传递请求内容；引擎服务端与插件的数据通道。<br/>**callback**(NOT&nbsp;NULL)：算法插件异步执行结果通过此回调返回引擎服务端。 |
| int&nbsp;Prepare(long&nbsp;long&nbsp;transactionId,<br/>const&nbsp;DataInfo&nbsp;&amp;inputInfo,&nbsp;DataInfo<br/>&amp;outputInfo); | **作用**：加载算法插件。<br/>**返回值**：0为成功，其他返回值为失败。 | **transactionId**(NOT&nbsp;NULL)：事务ID，用于标记客户端+会话信息。<br/>**inputInfo**(可为NULL)：加载算法插件传入的一些信息。<br/>**outputInfo**(可为NULL)：调用加载接口时的出参，返回相关执行结果。 |
| int&nbsp;Release(bool&nbsp;isFullUnload,&nbsp;long&nbsp;long<br/>transactionId,&nbsp;const&nbsp;DataInfo&nbsp;&amp;inputInfo); | **作用**：卸载相关算法插件。<br/>**返回值**：0为成功，其他返回值为失败。 | **isFullUnload**(NOT&nbsp;NULL)：表示此插件是否只剩一个client调用，否则不能直接卸载插件，需等最后一个client来进行卸载。<br/>**transactionId**(NOT&nbsp;NULL)：事务ID，用于标记客户端+会话信息。<br/>**inputInfo**(可为NULL)：卸载算法插件传入的一些信息。 |
| int&nbsp;SetOption(int&nbsp;optionType,&nbsp;const<br/>DataInfo&nbsp;&amp;inputInfo); | **作用**：设置配置项，可将一些算法的拓展信息通过此接口传入插件。<br/>**返回值**：0为成功，其他返回值为失败。 | **optionType**&nbsp;(NOT&nbsp;NULL)：算法配置项，算法插件可根据需要利用此状态位。<br/>**inputInfo**(可为NULL)：插件可根据需要通过此入参设置算法参数信息。 |
| int&nbsp;GetOption(int&nbsp;optionType,&nbsp;const<br/>DataInfo&nbsp;&amp;inputInfo,&nbsp;DataInfo<br/>&amp;outputInfo); | **作用**：给定特定的optionType和inputInfo，获取其对应的配置项信息。<br/>**返回值**：0为成功，其他返回值为失败。 | **optionType**(NOT&nbsp;NULL)：所获取配置项信息的对应算法状态位。<br/>**inputInfo**(可为NULL)：所获取配置项信息的对应算法参数信息。<br/>**outputInfo**(可为NULL)：所要获取的配置项信息返回结果。 |


算法插件类接口：Prepare、SyncProcess、AsyncProcess、Release、SetOption、GetOption分别于客户端接口AieClientPrepare、AieClientSyncProcess、AieClientAsyncProcess、AieClientRelease、AieClientSetOption、AieClientGetOption一一对应；GetInferMode接口用于返回算法执行类型——同步或异步。


算法插件回调类IPluginCallback 接口设计如下表所示。


  **表2** 算法插件回调类IPluginCallback 接口设计

| 接口名 | 接口说明 | 参数要求 |
| -------- | -------- | -------- |
| void&nbsp;OnEvent(PluginEvent&nbsp;event,<br/>IResponse&nbsp;\*response); | 作用：插件通过此回调返回异步算法执行结果。 | **event**：算法执行结果枚举,‘ON_PLUGIN_SUCCEED’或&nbsp;‘ON_PLUGIN_FAIL’（成功或者失败）。<br/>**response**：算法执行结果封装。 |


Request、Response是AI引擎服务端与算法插件进行通信的对象。Request封装了调用方的请求、输入数据等，而插件主要通过Response将运算之后的结果返回给AI引擎服务端。


Request类的属性如下表所示。


  **表3** Request类的属性

| 属性名称 | 属性说明 | 默认值 |
| -------- | -------- | -------- |
| innerSequenceId_ | 类型：long&nbsp;long<br/>作用：暂未启用。 | 0 |
| requestId_ | 类型：int<br/>作用：标识请求序列，用于绑定返回运算结果。 | 0 |
| operationId_ | 类型：int<br/>作用：暂未启用。 | 0 |
| transactionId_ | 类型：long&nbsp;long<br/>作用：事务ID，唯一标识clientId+sessionId。 | 0 |
| algoPluginType_ | 类型：int<br/>作用：引擎框架根据插件加载顺序分配的算法类型的ID。 | 0 |
| msg_ | 类型：DataInfo<br/>作用：存放调用算法接口的输入数据。 | .data&nbsp;=&nbsp;nullptr<br/>.length&nbsp;=&nbsp;0 |


Response类的属性如下表所示。


  **表4** Response类的属性

| 属性名称 | 属性说明 | 默认值 |
| -------- | -------- | -------- |
| innerSequenceId_ | 类型：long&nbsp;long<br/>作用：暂未启用。 | 0 |
| requestId_ | 类型：int<br/>作用：标识请求序列，用于绑定返回运算结果。 | 0 |
| retCode__ | 类型：int<br/>作用：异步执行算法推理结果码。 | 0 |
| retDesc_ | 类型：string<br/>作用：暂未启用。 | - |
| transactionId_ | 类型：long&nbsp;long<br/>作用：事务ID，唯一标识clientId+sessionId。 | 0 |
| algoPluginType_ | 类型：int<br/>作用：引擎框架根据插件加载顺序分配的算法类型的ID。 | INVALID_ALGO_PLUGIN_TYPE(-1) |
| result_ | 类型：DataInfo<br/>作用：存放异步算法推理结果。 | .data&nbsp;=&nbsp;nullptr<br/>.length&nbsp;=&nbsp;0 |


具体开发过程可参考[唤醒词识别插件开发示例](#唤醒词识别插件的开发示例)。

### 开发配置文件

开发者开发的SDK通过AlgorithmInfo结构体中algorithmVersion以及algorithmType识别出具体的插件类型，实现插件能力的调用。因此开发者需完成以下步骤：


1. 代码路径//foundation/ai/engine/services/common/protocol/plugin_config/plugin_config_ini/中添加插件的配置文件。

2. 代码路径//foundation/ai/engine/services/common/protocol/plugin_config/中的aie_algorithm_type.h文件添加算法类型。

3. 代码路径//foundation/ai/engine/services/server/plugin_manager/include/中的aie_plugin_info.h文件添加唤醒词识别的算法名称及其在ALGORITHM_TYPE_ID_LIST中的序号。

具体开发过程可参考[唤醒词识别配置文件开发示例](#唤醒词识别配置文件的开发示例)。

## 开发实例

### 唤醒词识别SDK的开发示例


1. 在//foundation/ai/engine /interfaces/kits目录中添加唤醒词识别SDK的API接口定义，该接口可用三方应用进行调用。如下代码片段即为唤醒词识别定义的API接口示例，其相关代码参考路径为：//foundation/ai/engine/interfaces/kits/asr/keyword_spotting。
  
   ```
   class KWSSdk {
   public:
       KWSSdk();
       virtual ~KWSSdk();
   
       // 定义创建唤醒词检测工具包的方法
       int32_t Create();
   
       // 定义同步执行唤醒词检测任务的方法
       int32_t SyncExecute(const Array<int16_t> &audioInput);
   
       // 定义设置唤醒词检测回调器的方法。
       int32_t SetCallback(const std::shared_ptr<KWSCallback> &callback);
   
       // 定义销毁唤醒词工具包的方法，释放与插件的会话信息
       int32_t Destroy();
   };
   ```

2. 在//foundation/ai/engine/services/client/algorithm_sdk目录中增加SDK中API接口的具体实现，调用client端提供的接口，实现算法插件能力的使用。如下代码片段即为唤醒词识别的API接口中create方法的具体实现示例，更多详细代码请参考：//foundation/ai/engine/services/client/algorithm_sdk/asr/keyword_spotting。
  
   ```
   int32_t KWSSdk::KWSSdkImpl::Create()
   {
       if (kwsHandle_ != INVALID_KWS_HANDLE) {
           HILOGE("[KWSSdkImpl]The SDK has been created");
           return KWS_RETCODE_FAILURE;
       }
       if (InitComponents() != RETCODE_SUCCESS) {
           HILOGE("[KWSSdkImpl]Fail to init sdk components");
           return KWS_RETCODE_FAILURE;
       }
       // 调用client端提供的AieClientInit接口，实现初始化引擎服务，激活跨进程调用
       int32_t retCode = AieClientInit(configInfo_, clientInfo_, algorithmInfo_, nullptr);
       if (retCode != RETCODE_SUCCESS) {
           HILOGE("[KWSSdkImpl]AieClientInit failed. Error code[%d]", retCode);
           return KWS_RETCODE_FAILURE;
       }
       if (clientInfo_.clientId == INVALID_CLIENT_ID) {
           HILOGE("[KWSSdkImpl]Fail to allocate client id");
           return KWS_RETCODE_FAILURE;
       }
       DataInfo inputInfo = {
           .data = nullptr,
           .length = 0,
       };
       DataInfo outputInfo = {
           .data = nullptr,
           .length = 0,
       };
       // 调用client端提供的AieClientPrepare接口，实现加载算法插件
       retCode = AieClientPrepare(clientInfo_, algorithmInfo_, inputInfo, outputInfo, nullptr);
       if (retCode != RETCODE_SUCCESS) {
           HILOGE("[KWSSdkImpl]AieclientPrepare failed. Error code[%d]", retCode);
           return KWS_RETCODE_FAILURE;
       }
       if (outputInfo.data == nullptr || outputInfo.length <= 0) {
           HILOGE("[KWSSdkImpl]The data or length of output info is invalid");
           return KWS_RETCODE_FAILURE;
       }
       MallocPointerGuard<unsigned char> pointerGuard(outputInfo.data);
       retCode = PluginHelper::UnSerializeHandle(outputInfo, kwsHandle_);
       if (retCode != RETCODE_SUCCESS) {
           HILOGE("[KWSSdkImpl]Get handle from inputInfo failed");
           return KWS_RETCODE_FAILURE;
       }
       return KWS_RETCODE_SUCCESS;
   }
   ```

   上述代码为API接口的具体实现。在示例代码中，SDK中create接口的具体实现即为上述示例代码中create方法，该方法调用了AI引擎框架client端提供的AieClientInit及AieClientPrepare接口，从而实现与server端建立连接及加载算法模型的能力。

   > **说明：**
   > 
   > SDK调用AI引擎client端接口应遵循AieClientInit-&gt;AieClientPrepare-&gt;AieClientSyncProcess/AieClientAsyncProcess-&gt;AieClientRelease-&gt;AieClientDestroy顺序，否则调用接口会返回错误码。

### 唤醒词识别插件的开发示例
在代码路径//foundation/ai/engine/services/server/plugin中添加唤醒词识别插件的接口定义（IPlugin），并实现AI能力的调用。如下代码片段即实现唤醒词识别的算法插件的接口定义。更多插件开发的相关代码参考路径如下：//foundation/ai/engine/services/server/plugin/asr/keyword_spotting
     
   ```
   #include "plugin/i_plugin.h
   class KWSPlugin : public IPlugin {
   public:
       KWSPlugin();
       ~KWSPlugin();
       const long long GetVersion() const override;
       const char* GetName() const override;
       const char* GetInferMode() const override;
       int32_t Prepare(long long transactionId, const DataInfo &amp;amp;inputInfo, DataInfo &amp;amp;outputInfo) override;
       int32_t SetOption(int optionType, const DataInfo &amp;amp;inputInfo) override;
       int32_t GetOption(int optionType, const DataInfo &amp;amp;inputInfo, DataInfo &amp;amp;outputInfo) override;
       int32_t SyncProcess(IRequest *request, IResponse *&amp;amp;response) override;
       int32_t AsyncProcess(IRequest *request, IPluginCallback*callback) override;
       int32_t Release(bool isFullUnload, long long transactionId, const DataInfo &amp;amp;inputInfo) override;
   };
   ```
上述代码实现server提供的IPlugin接口。唤醒词识别的sample中调用的client端接口与插件中的接口对应关系及其实现功能如下表所示。
     
**表1** 唤醒词识别中client端接口与插件中的接口对应关系

| client端定义的接口 | 插件中定义的接口 | 功能 |
| -------- | -------- | -------- |
| AieClientPrepare | Prepare | 提供推理算法插件初始化功能，例如：加载唤醒词识别模型，将固定位置（/sdcard/wenwen_inst.wk）模型加载至内存。 |
| AieClientSyncProcess | SyncProcess | 提供同步执行推理算法的能力，例如：实现同步执行音频推理算法，判断音频中是否存在唤醒词。 |
| AieClientAsyncProcess | AsyncProcess | 提供异步执行推理算法的能力，当前唤醒词识别场景不涉及，但开发者可根据具体场景自行实现。 |
| AieClientSetOption | SetOption | 提供手动设置算法相关配置项，如置信度阈值、时延等超参数的能力。当前唤醒词识别场景未涉及，开发者可视具体场景自行实现。 |
| AieClientGetOption | GetOption | 提供获取算法相关配置项，以唤醒词识别为例：获取唤醒词模型中输入输出的规模，输入规模即为唤醒词识别模型要求输入的MFCC特征的维度（固定值：4000），输出规模即为结果的置信度得分维度（固定值：2）。 |
| AieClientRelease | Release | 提供卸载算法模型功能，以唤醒词识别为例：实现卸载相关模型，并清理特征处理器中的动态内存。 |

   注意：

   1.接口AieClientInit、AieClientDestroy分别用于与server端建立和断开连接，未调用到插件算法中，因此插件中无需定义与之对应的接口。

   2.唤醒词识别插件需要使用PLUGIN_INTERFACE_IMPL语句对外暴露函数指针，否则插件将无法被正常加载使用。


   ```
   PLUGIN_INTERFACE_IMPL(KWSPlugin);
   ```

### 唤醒词识别配置文件的开发示例

1. 在代码路径//foundation/ai/engine/services/common/protocol/plugin_config/plugin_config_ini/中添加唤醒词识别的配置文件。
  
   ```
   [base]
   supported_boards = hi3516dv300
   related_sessions = asr_keyword_spotting+20001002
   
   //[asr_keyword_spotting+20001002]的命名规则为[算法名称+算法version]
   [asr_keyword_spotting+20001002]
   AID         = asr_keyword_spotting
   VersionCode = 20001002
   VersionName = 2.00.01.002
   XPU         = NNIE
   District    = China
   // 编译出的插件so文件所在的位置
   FullPath    = /usr/lib/libasr_keyword_spotting.so
   Chipset     = ALL
   ChkSum      = ''
   Key         = ''
   ```

2. 在代码路径//foundation/ai/engine/services/common/protocol/plugin_config/中的aie_algorithm_type.h文件添加唤醒词识别算法类型id。
  
   ```
   // 唤醒词识别的算法类型id与唤醒词识别在ALGORITHM_TYPE_ID_LIST中的序号一一对应
   const int ALGORITHM_TYPE_KWS = 3;
   ```

3. 在代码路径//foundation/ai/engine/services/server/plugin_manager/include/中的aie_plugin_info.h文件添加唤醒词识别算法名称及在ALGORITHM_TYPE_ID_LIST中的序号。
  
   ```
   const std::string ALGORITHM_ID_SAMPLE_1 = "sample_plugin_1";
   const std::string ALGORITHM_ID_SAMPLE_2 = "sample_plugin_2";
   const std::string ALGORITHM_ID_IVP = "cv_human_detect";
   // 添加唤醒词识别的算法名称asr_keyword_spotting
   // 算法的变量名称与ALGORITHM_TYPE_ID_LIST中算法typeId命名相同，例如：ALGORITHM_ID_KWS 
   const std::string ALGORITHM_ID_KWS = "asr_keyword_spotting";
   const std::string ALGORITHM_ID_IC = "cv_image_classification";
   const std::string ALGORITHM_ID_INVALID = "invalid algorithm id";
   
   const std::vector<std::string> ALGORITHM_TYPE_ID_LIST = {
       ALGORITHM_ID_SAMPLE_1,
       ALGORITHM_ID_SAMPLE_2,
       ALGORITHM_ID_IVP,
       // 添加唤醒词识别在ALGORITHM_TYPE_ID_LIST中的序号，通过该序号可获得唤醒词识别的算法名称
       // 唤醒词识别的算法名称和唤醒词识别在ALGORITHM_TYPE_ID_LIST中的序号顺序需保持一致
       ALGORITHM_ID_KWS,
       ALGORITHM_ID_IC,
   };
   ```
