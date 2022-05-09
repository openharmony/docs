# 接口开发规范


## 规则：SDK需按算法调用顺序，封装client对外提供接口；对于异步插件对应的SDK，需要实现client提供的回调接口IClientCb

AI引擎的client端对外提供的接口包括AieClientInit、AieClientPrepare、AieClientSyncProcess、AieClientAsyncProcess、AieClientRelease、AieClientDestroy、AieClientSetOption、AieClientGetOption，SDK需要根据插件的北向接口按照顺序至少封装AieClientInit、AieClientPrepare、AieClientSyncProcess/AieClientAsyncProcess、AieClientRelease、AieClientDestroy五个接口，否则会出现调用问题或者内存泄漏。比如封装过程遗漏了AieClientPrepare接口，则server端无法完成插件加载，故后面的接口都无法调用成功。

对于异步插件，SDK需要实现IClientCb接口，用于接收来自client端的算法推理结果，并将该结果返回给三方调用者。


## 规则：SDK接口实现中，需要保存与client交互的相关通用数据

AI引擎将的client端采用单例实现，对接多个SDK，因此各SDK需要保存与client交互的通用数据，用于连接server端进行任务推理、结果返回等；需保存数据包含clientInfo、algorithmInfo、configInfo三种数据类型，定义在SDK的成员变量里即可。


## 建议：SDK实现client定义的IServiceDeadCb接口

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


## 规则：SDK与plugin需要使用编解码模块，将特定算法数据转换成AI引擎的通用数据类型

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


## 规则：在SDK中，对以编解码返回的出参数据类型，需要进行内存释放，否则会出现内存泄漏

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


## 规则：plugin需要实现server定义的IPlugin接口，并使用宏PLUGIN_INTERFACE_IMPL对外提供插件函数指针

Server端管理的插件内部接口实现逻辑各不相同，为了统一插件的加载流程，AI引擎定义了插件接口IPlugin；在运行态，插件是以动态链接库的形式被AI引擎框架通过dlopen方式加载，各插件需要使用PLUGIN_INTERFACE_IMPL语句对外暴露函数指针，否则插件将无法被正常加载使用。


## 规则：plugin需要使用AI引擎提供的统一数据通道

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
