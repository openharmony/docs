# Codec

## 概述
### 功能简介

OpenHarmony Codec HDI（Hardware Device Interface）驱动框架基于OpenMax实现了视频硬件编解码驱动，提供Codec基础能力接口给上层媒体服务调用，包括获取组件编解码能力、创建组件、参数设置、数据的轮转和控制、以及销毁组件等功能，实现对视频数据的编解码处理（可以将YUV/RGB等格式的视频数据编码成H264/H265等编码格式，也可以将H264/H265等裸流数据解码成YUV/RGB等格式数据）。本文主要介绍基于HDF（Hardware Driver Foundation）驱动框架开发的Codec编解码功能。

Codec HDI驱动框架基于HDF驱动框架实现。Codec HDI驱动架构组成：

**图 1**  Codec HDI驱动框架

![image](figures/Codec框架图.png "Codec HDI驱动框架图")

- Codec HDI Callback Remote Service：匿名Callback服务，通过该服务，可以处理回调。
- Codec HDI Interface：提供了基于OpenMax的标准接口，上层可通过这些接口来实现硬件的编解码。
- Codec HDI Adapter：HDI 实现层，实现了HDI Interface接口，并与OpenMax IL 对接。
- OpenMax IL Interface：OpenMax IL接口，Codec HDI驱动直接对接OpenMax IL层。
- Vendor Impl：厂商适配层，各大厂商适配的OpenMax 实现层。
- Codec Hardware：硬件解码设备。

### 基本概念
在进行开发前，开发者应了解一下基本概念：

- 采样率

    采样率就是每秒从连续信号中提取并组成离散信号的采样个数，用赫兹（Hz）来表示。

- OpenMax IL

    OpenMax IL定义了硬件或软件编解码的标准，使得应用程序和媒体框架能够以统一的方式与多媒体编解码器和支持的组件进行交互。

- 帧率

    帧率就是每秒内传输的图片的帧数，也可以理解为图形处理器每秒能够刷新几次。帧率越大，画面越流畅；帧率越小，画面越有跳动感。

- 码率

    视频的码率是指在单位时间内传输的视频数据数量，一般用kbps作为单位。码率越高，视频就越清晰，反之则画面粗糙而且多马赛克。

- 组件

    组件就是指的OpenMax IL 组件，是对视频流中模块的抽象，本文中的组件指的是编解码组件，专门处理视频的编解码。

### 约束与限制

Codec HDI只针对标准系统，其它系统暂不支持。

接口约束和限制参考[OpenMax IL标准](https://www.khronos.org/api/openmax/il)。

## 开发指导

### 场景介绍
Codec模块主要完成对视频数据的硬件编解码，将H264等裸流数据转化成图形支持的YUV或者RGB数据，也支持将图形的YUV或RGB数据编码成H264等数据格式。

### 接口说明

- codec_component_manager.h

  | 接口名称                                                                                                                                                       | 功能描述                      |
  | -------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------|
  | int32_t (*CreateComponent)(struct CodecComponentType **component, uint32_t *componentId, char *compName, int64_t appData, struct CodecCallbackType *callbacks) | 创建Codec组件实例             |
  | int32_t (*DestroyComponent)(uint32_t componentId)                                                                                                              | 销毁Codec组件实例                  |

- codec_component _if.h

  | 接口名称                                                                                                                                                                | 功能描述                      |
  | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------- |
  | int32_t (*SendCommand)(struct CodecComponentType *self, enum OMX_COMMANDTYPE cmd, uint32_t param, int8_t *cmdData, uint32_t cmdDataLen)                                 | 发送命令给组件                |
  | int32_t (*GetParameter)(struct CodecComponentType *self, uint32_t paramIndex, int8_t *paramStruct, uint32_t paramStructLen)                                             | 获取组件参数设置              |
  | int32_t (*SetParameter)(struct CodecComponentType *self, uint32_t index, int8_t *paramStruct, uint32_t paramStructLen)                                                  | 设置组件需要的参数            |
  | int32_t (*GetState)(struct CodecComponentType *self, enum OMX_STATETYPE *state)                                                                                         | 获取组件的状态                |
  | int32_t (*UseBuffer)(struct CodecComponentType *self, uint32_t portIndex, struct OmxCodecBuffer *buffer)                                                                | 指定组件端口的buffer          |
  | int32_t (*FreeBuffer)(struct CodecComponentType *self, uint32_t portIndex, const struct OmxCodecBuffer *buffer)                                                         | 释放buffer                    |
  | int32_t (*EmptyThisBuffer)(struct CodecComponentType *self, const struct OmxCodecBuffer *buffer)                                                                        | 编解码输入待处理buffer        |
  | int32_t (*FillThisBuffer)(struct CodecComponentType *self, const struct OmxCodecBuffer *buffer)                                                                         | 编解码输出填充buffer          |

- codec_callback_if.h

  | 接口名称                                                                                                         | 功能描述                           | 
  | ---------------------------------------------------------------------------------------------------------------- |----------------------------------- | 
  | int32_t (*EventHandler)(struct CodecCallbackType *self, enum OMX_EVENTTYPE event, struct EventInfo *info)        | 事件上报                           | 
  | int32_t (*EmptyBufferDone)(struct CodecCallbackType *self, int64_t appData, const struct OmxCodecBuffer *buffer) | 上报输入buffer编码或者解码处理完毕 | 
  | int32_t (*FillBufferDone)(struct CodecCallbackType *self, int64_t appData, const struct OmxCodecBuffer *buffer)  | 上报输出buffer填充完毕             | 

更多接口请参考[Codec驱动仓](https://gitee.com/openharmony/drivers_peripheral/tree/master/codec)。

### 开发步骤
Codec HDI驱动的开发过程主要包含以下步骤：

#### Driver的注册及初始化
定义Codec HDI的HdfDriverEntry结构体，该结构体中定义了Driver初始化的方法，填充g_codecComponentDriverEntry结构体，实现Bind、Init、Release函数指针。 

```c
struct HdfDriverEntry g_codecComponentDriverEntry = {
    .moduleVersion = 1,
    .moduleName = "codec_hdi_omx_server",
    .Bind = HdfCodecComponentTypeDriverBind,
    .Init = HdfCodecComponentTypeDriverInit,
    .Release = HdfCodecComponentTypeDriverRelease,
};
HDF_INIT(g_codecComponentDriverEntry); // 将Codec HDI的HdfDriverEntry结构体注册到HDF上
```

- HdfCodecComponentTypeDriverBind：将HDF中device绑定到CodecComponentTypeHost，将codec service注册到HDF框架。

    ```c
    int32_t HdfCodecComponentTypeDriverBind(struct HdfDeviceObject *deviceObject)
    {
        HDF_LOGI("HdfCodecComponentTypeDriverBind enter.");
        struct HdfCodecComponentTypeHost *omxcomponenttypeHost =
            (struct HdfCodecComponentTypeHost *)OsalMemAlloc(sizeof(struct HdfCodecComponentTypeHost));
        if (omxcomponenttypeHost == NULL) {
            HDF_LOGE("HdfCodecComponentTypeDriverBind OsalMemAlloc HdfCodecComponentTypeHost failed!");
            return HDF_FAILURE;
        }
        int ret = HdfDeviceObjectSetInterfaceDesc(deviceObject, COMPONENT_MANAGER_SERVICE_DESC);
        if (ret != HDF_SUCCESS) {
            HDF_LOGE("Failed to set interface desc");
            return ret;
        }

        omxcomponenttypeHost->ioservice.Dispatch = CodecComponentTypeDriverDispatch;
        omxcomponenttypeHost->ioservice.Open = NULL;
        omxcomponenttypeHost->ioservice.Release = NULL;
        omxcomponenttypeHost->service = CodecComponentManagerSerivceGet();
        if (omxcomponenttypeHost->service == NULL) {
            OsalMemFree(omxcomponenttypeHost);
            return HDF_FAILURE;
        }

        deviceObject->service = &omxcomponenttypeHost->ioservice;
        return HDF_SUCCESS;
    }
    ```

- HdfCodecComponentTypeDriverInit：加载HCS（HDF Configuration Source）中的属性配置。

    ```c
    int32_t HdfCodecComponentTypeDriverInit(struct HdfDeviceObject *deviceObject)
    {
        HDF_LOGI("HdfCodecComponentTypeDriverInit enter.");
        if (deviceObject == NULL) {
            return HDF_FAILURE;
        }
        InitDataNode(deviceObject->property);
        if (LoadCapabilityData() != HDF_SUCCESS) {
            ClearCapabilityData();
        }
        return HDF_SUCCESS;
    }
    ```

- HdfCodecComponentTypeDriverRelease：释放驱动实例。

    ```c
    void HdfCodecComponentTypeDriverRelease(struct HdfDeviceObject *deviceObject)
    {
        HDF_LOGI("HdfCodecComponentTypeDriverRelease enter.");
        struct HdfCodecComponentTypeHost *omxcomponenttypeHost =
            CONTAINER_OF(deviceObject->service, struct HdfCodecComponentTypeHost, ioservice);
        OmxComponentManagerSeriveRelease(omxcomponenttypeHost->service);
        OsalMemFree(omxcomponenttypeHost);
        ClearCapabilityData();
    }
    ```

#### Driver的HCS配置
HCS配置包括两部分：

- device相关配置。
- 支持的组件相关配置。

HCS配置内容包括：驱动节点、加载顺序、服务名称等。HCS语法可参考[配置管理](driver-hdf-manage.md)。

以RK3568开发板为例，标准系统配置文件路径（其它系统暂不涉及）：
vendor/hihope/rk3568/hdf_config/uhdf/

1. device相关配置

    在device_info.hcs的codec_host中增加codec_omx_service配置，具体配置如下：
    ```c
    codec :: host {
        hostName = "codec_host";
        priority = 50;
        gid = ["codec_host", "uhdf_driver", "vendor_mpp_driver"];
        codec_omx_device :: device {
            device0 :: deviceNode {
                policy = 2;                                       // 自动加载，非延迟加载
                priority = 100;                                   // 优先级
                moduleName = "libcodec_hdi_omx_server.z.so";      // 驱动的动态库
                serviceName = "codec_hdi_omx_service";            // 配置驱动的服务名
                deviceMatchAttr = "codec_component_capabilities"; // 属性配置
            }
        }
    }
    ```

2. 支持的组件相关配置

    在media_codec\codec_component_capabilities.hcs中增加组件配置，具体配置如下：
    ```c
    /* node name explanation -- HDF_video_hw_enc_avc_rk：
    **
    **    HDF____________video__________________hw____________________enc____________avc_______rk
    **     |               |                    |                      |              |        |
    ** HDF or OMX    video or audio    hardware or software    encoder or decoder    mime    vendor
    */
    HDF_video_hw_enc_avc_rk {
        role = 1;                                           // AvCodecRole配置
        type = 1;                                           // CodecType配置
        name = "OMX.rk.video_encoder.avc";                  // 组件名配置
        supportProfiles = [1, 32768, 2, 32768, 8, 32768];   // 支持的profile配置
        maxInst = 4;                                        // 最大实例数量配置
        isSoftwareCodec = false;                            // 硬件/软件
        processModeMask = [];                               // CodecProcessMode配置
        capsMask = [0x01];                                  // CodecCapsMask配置
        minBitRate = 1;                                     // 最小比特率
        maxBitRate = 40000000;                              // 最大比特率
        minWidth = 176;                                     // 视频最小宽
        minHeight = 144;                                    // 视频最小高
        maxWidth = 1920;                                    // 视频最大宽
        maxHeight = 1088;                                   // 视频最大高
        widthAlignment = 16;                                // 水平对齐
        heightAlignment = 8;                                // 垂直对齐
        minBlockCount = 0xFFFFFFFF;
        maxBlockCount = 0xFFFFFFFF;
        minBlocksPerSecond = 0xFFFFFFFF;
        maxBlocksPerSecond = 0xFFFFFFFF;
        blockSizeWidth = 0xFFFFFFFF;
        blockSizeHeight = 0xFFFFFFFF;
        supportPixelFmts = [28, 24, 30, 22, 7, 3, 14, 13, 20, 26, 27, 12];  // 支持的颜色列表，Display支持的颜色列表
        measuredFrameRate = [320, 240, 165, 165, 720, 480, 149, 149, 1280, 720, 73, 73, 1920, 1080, 18, 18];
        bitRateMode = [1, 2];                               // 比特率模式，BitRateMode
        minFrameRate = 0;                                   // 帧率配置
        maxFrameRate = 0;
    }
    ```

### 使用实例
在按照开发步骤进行相关操作后，Codec模块完成了基本的驱动适配，用户可使用Codec模块提供的HDI接口进行下一步的开发。Codec HDI核心功能如下：

1. 提供Codec HDI接口供北向视频服务调用，实现视频服务的基本编解码。
2. 作为标准南向接口，保证南向OEM产商实现HDI-adapter的规范性，保证生态良性演进。

用户开发步骤如下所示：

1. 初始化，包括接口实例、回调的初始化和对应的组件的初始化；
2. 设置编解码参数和配置信息，如视频宽、高和码率等；
3. 输入输出Buffer申请；
4. 编解码Buffer流转，使组件进入OMX_Executing状态，并处理相应的回调；
5. 接口去初始化，销毁buffer，关闭组件并释放所有的接口对象；

#### 初始化
初始化过程包括接口的初始化，回调的初始化以及组件的创建。
```cpp
// 初始化Codec HDI ComponentManager实例
omxMgr_ = GetCodecComponentManager();

// 初始化回调
callback_ = CodecCallbackTypeStubGetInstance();
if (!omxMgr_ || !callback_) {
    FUNC_EXIT_ERR();
    return false;
}
// 设置回调函数指针
callback_->EventHandler    = &OMXCore::OnEvent;
callback_->EmptyBufferDone = &OMXCore::OnEmptyBufferDone;
callback_->FillBufferDone  = &OMXCore::OnFillBufferDone;

// 新建组件实例
uint32_t err = HDF_SUCCESS;
if (codec == codecMime::AVC) {
    err = omxMgr_->CreateComponent(&client_, &componentId_, const_cast<char *>(DECODER_AVC), (int64_t)this,
                                   callback_);
} else {
    err = omxMgr_->CreateComponent(&client_, &componentId_, const_cast<char *>(DECODER_HEVC), (int64_t)this,
                                   callback_);
}
```

#### 设置编解码参数和配置信息
Codec HDI编解码参数配置，包括输入输出数据的宽和高，输入数据格式和输出数据格式。
```cpp
// 设置输入端口图片的宽高
OMX_PARAM_PORTDEFINITIONTYPE param;
InitParam(param);
param.nPortIndex = (uint32_t)PortIndex::PORT_INDEX_INPUT;
auto err = client_->GetParameter(client_, OMX_IndexParamPortDefinition, (int8_t *)&param, sizeof(param));
if (err != HDF_SUCCESS) {
    HDF_LOGE("%{public}s failed PortIndex::PORT_INDEX_INPUT, index is OMX_IndexParamPortDefinition", __func__);
    return false;
}
HDF_LOGI("PortIndex::PORT_INDEX_INPUT: eCompressionFormat = %{public}d, eColorFormat = %{public}d ",
         param.format.video.eCompressionFormat, param.format.video.eColorFormat);
param.format.video.nFrameWidth  = width_;
param.format.video.nFrameHeight = height_;
param.format.video.nStride      = width_;
param.format.video.nSliceHeight = height_;
err = client_->SetParameter(client_, OMX_IndexParamPortDefinition, (int8_t *)&param, sizeof(param));
if (err != HDF_SUCCESS) {
    HDF_LOGE("%{public}s failed with PortIndex::PORT_INDEX_INPUT, index is OMX_IndexParamPortDefinition", __func__);
    return false;
}
// 输出宽、高和格式设置
InitParam(param);
param.nPortIndex = (uint32_t)PortIndex::PORT_INDEX_OUTPUT;
err = client_->GetParameter(client_, OMX_IndexParamPortDefinition, (int8_t *)&param, sizeof(param));
if (err != HDF_SUCCESS) {
    HDF_LOGE("%{public}s failed with PortIndex::PORT_INDEX_OUTPUT, index is OMX_IndexParamPortDefinition", __func__);
    return false;
}
HDF_LOGI("PortIndex::PORT_INDEX_OUTPUT eCompressionFormat = %{public}d, eColorFormat=%{public}d",
         param.format.video.eCompressionFormat, param.format.video.eColorFormat);
param.format.video.nFrameWidth  = width_;
param.format.video.nFrameHeight = height_;
param.format.video.nStride      = width_;
param.format.video.nSliceHeight = height_;
param.format.video.eColorFormat = AV_COLOR_FORMAT;  // 输出数据格式设置为YUV420SP
err = client_->SetParameter(client_, OMX_IndexParamPortDefinition, (int8_t *)&param, sizeof(param));
if (err != HDF_SUCCESS) {
    HDF_LOGE("%{public}s failed  with PortIndex::PORT_INDEX_OUTPUT, index is OMX_IndexParamPortDefinition",
             __func__);
    return false;
}
// 设置输入数据为H264/H265格式数据
OMX_VIDEO_PARAM_PORTFORMATTYPE param;
InitParam(param);
param.nPortIndex = (uint32_t)PortIndex::PORT_INDEX_INPUT;
auto err = client_->GetParameter(client_, OMX_IndexParamVideoPortFormat, (int8_t *)&param, sizeof(param));
if (err != HDF_SUCCESS) {
    HDF_LOGE("%{public}s failed with PortIndex::PORT_INDEX_INPUT", __func__);
    return false;
}
HDF_LOGI("set Format PortIndex::PORT_INDEX_INPUT eCompressionFormat = %{public}d, eColorFormat=%{public}d",
         param.eCompressionFormat, param.eColorFormat);
param.xFramerate = FRAME;  // 30帧
if (codecMime_ == codecMime::AVC) {
    param.eCompressionFormat = OMX_VIDEO_CodingAVC;  // H264
} else {
    param.eCompressionFormat = (OMX_VIDEO_CODINGTYPE)CODEC_OMX_VIDEO_CodingHEVC;  // H265
}

err = client_->SetParameter(client_, OMX_IndexParamVideoPortFormat, (int8_t *)&param, sizeof(param));
if (err != HDF_SUCCESS) {
    HDF_LOGE("%{public}s failed  with PortIndex::PORT_INDEX_INPUT", __func__);
    return false;
}
```

#### 申请输入输出Buffer
此处讲解输入输出buffer的申请的整个过程，我们需要按照下面的步骤依次执行：

1. 用户通过UseBuffer申请输入输出Buffer，并保存bufferId，后续buffer轮转可以直接通过bufferId来操作。
2. 用户需要判断对应的端口是否是使能状态，如果不是，需要先将对应的端口设置为使能状态。
3. 用户通过SendCommand将组件的状态为修改为OMX_StateIdle，需要等待其结果通知。
```cpp
// 输入端口buffer申请
auto ret = UseBufferOnPort(PortIndex::PORT_INDEX_INPUT);
if (!ret) {
    HDF_LOGE("%{public}s UseBufferOnPort PortIndex::PORT_INDEX_INPUT error", __func__);
    return false;
}
// 输出端口buffer申请
ret = UseBufferOnPort(PortIndex::PORT_INDEX_OUTPUT);
if (!ret) {
    HDF_LOGE("%{public}s UseBufferOnPort PortIndex::PORT_INDEX_OUTPUT error", __func__);
    return false;
}
// 发送命令使组件进入OMX_StateIdle状态
auto err = client_->SendCommand(client_, OMX_CommandStateSet, OMX_StateIdle, NULL, 0);
if (err != HDF_SUCCESS) {
    HDF_LOGE("%{public}s failed to SendCommand with OMX_CommandStateSet:OMX_StateIdle", __func__);
    return false;
}
HDF_LOGI("Wait for OMX_StateIdle status");
this->WaitForStatusChanged();
```

UseBufferOnPort实现如下：

```cpp
bool CodecHdiDecode::UseBufferOnPort(enum PortIndex portIndex)
{
    HDF_LOGI("%{public}s enter, portIndex = %{public}d", __func__, portIndex);
    int bufferSize = 0;
    int bufferCount = 0;
    bool bPortEnable = false;
    // 获取端口buffer参数
    OMX_PARAM_PORTDEFINITIONTYPE param;
    InitParam(param);
    param.nPortIndex = (OMX_U32)portIndex;
    auto err = client_->GetParameter(client_, OMX_IndexParamPortDefinition, (int8_t *)&param, sizeof(param));
    if (err != HDF_SUCCESS) {
        HDF_LOGE("%{public}s failed to GetParameter with OMX_IndexParamPortDefinition : portIndex[%{public}d]",
            __func__, portIndex);
        return false;
    }
    bufferSize = param.nBufferSize;
    bufferCount = param.nBufferCountActual;
    bPortEnable = param.bEnabled;
    HDF_LOGI("buffer index [%{public}d], buffer size [%{public}d], "
        "buffer count [%{public}d], portEnable[%{public}d], err [%{public}d]",
        portIndex, bufferSize, bufferCount, bPortEnable, err);
    {
        OMX_PARAM_BUFFERSUPPLIERTYPE param;
        InitParam(param);
        param.nPortIndex = (uint32_t)portIndex;
        auto err = client_->GetParameter(client_, OMX_IndexParamCompBufferSupplier, (int8_t *)&param, sizeof(param));
        HDF_LOGI("param.eBufferSupplier[%{public}d] isSupply [%{public}d], err [%{public}d]", param.eBufferSupplier,
            this->isSupply_, err);
    }
    // 设置端口buffer
    UseBufferOnPort(portIndex, bufferCount, bufferSize);
    // 检查端口是否可用状态
    if (!bPortEnable) {
        auto err = client_->SendCommand(client_, OMX_CommandPortEnable, (uint32_t)portIndex, NULL, 0);
        if (err != HDF_SUCCESS) {
            HDF_LOGE("%{public}s SendCommand OMX_CommandPortEnable::PortIndex::PORT_INDEX_INPUT error", __func__);
            return false;
        }
    }
    return true;
}

bool CodecHdiDecode::UseBufferOnPort(enum PortIndex portIndex, int bufferCount, int bufferSize)
{
    for (int i = 0; i < bufferCount; i++) {
        OmxCodecBuffer *omxBuffer = new OmxCodecBuffer();
        memset_s(omxBuffer, sizeof(OmxCodecBuffer), 0, sizeof(OmxCodecBuffer));
        omxBuffer->size = sizeof(OmxCodecBuffer);
        omxBuffer->version.s.nVersionMajor = 1;
        omxBuffer->bufferType = BUFFER_TYPE_AVSHARE_MEM_FD;
        int fd = AshmemCreate(0, bufferSize);
        shared_ptr<Ashmem> sharedMem = make_shared<Ashmem>(fd, bufferSize);
        omxBuffer->bufferLen = FD_SIZE;
        omxBuffer->buffer = (uint8_t *)(unsigned long)fd;
        omxBuffer->allocLen = bufferSize;
        omxBuffer->fenceFd = -1;

        if (portIndex == PortIndex::PORT_INDEX_INPUT) {
            omxBuffer->type = READ_ONLY_TYPE;  // ReadOnly
            sharedMem->MapReadAndWriteAshmem();
        } else {
            omxBuffer->type = READ_WRITE_TYPE;
            sharedMem->MapReadOnlyAshmem();
        }
        auto err = client_->UseBuffer(client_, (uint32_t)portIndex, omxBuffer);
        if (err != HDF_SUCCESS) {
            HDF_LOGE("%{public}s failed to UseBuffer with  portIndex[%{public}d]", __func__, portIndex);
            sharedMem->UnmapAshmem();
            sharedMem->CloseAshmem();
            sharedMem = nullptr;
            return false;
        }
        omxBuffer->bufferLen = 0;
        HDF_LOGI("UseBuffer returned bufferID [%{public}d]", omxBuffer->bufferId);

        BufferInfo *bufferInfo = new BufferInfo;
        bufferInfo->omxBuffer = omxBuffer;
        bufferInfo->avSharedPtr = sharedMem;
        bufferInfo->portIndex = portIndex;
        omxBuffers_.insert(std::make_pair<int, BufferInfo *>(omxBuffer->bufferId, std::move(bufferInfo)));
        if (portIndex == PortIndex::PORT_INDEX_INPUT) {
            unUsedInBuffers_.push_back(omxBuffer->bufferId);
        } else {
            unUsedOutBuffers_.push_back(omxBuffer->bufferId);
        }
        int fdret = (int)omxBuffer->buffer;
        HDF_LOGI("{bufferID = %{public}d, srcfd = %{public}d, retfd = %{public}d}", omxBuffer->bufferId, fd, fdret);
    }
    return true;
}
```

#### 编解码Buffer流转
用户需要先将组件设置为OMX_StateExecuting状态，然后填充输入buffer，读取输出buffer，进行buffer的轮转。

```cpp
// 设置组件进入OMX_StateExecuting状态并开始buffer的轮转
HDF_LOGI("...command to OMX_StateExecuting....");
auto err = client_->SendCommand(client_, OMX_CommandStateSet, OMX_StateExecuting, NULL, 0);
if (err != HDF_SUCCESS) {
    HDF_LOGE("%{public}s failed to SendCommand with OMX_CommandStateSet:OMX_StateIdle", __func__);
    return;
}
// 设置输出buffer填充
for (auto bufferId : unUsedOutBuffers_) {
    HDF_LOGI("fill bufferid [%{public}d]", bufferId);
    auto iter = omxBuffers_.find(bufferId);
    if (iter != omxBuffers_.end()) {
        BufferInfo *bufferInfo = iter->second;
        auto err = client_->FillThisBuffer(client_, bufferInfo->pOmxBuffer);
        if (err != HDF_SUCCESS) {
            HDF_LOGE("FillThisBuffer error");
            FUNC_EXIT_ERR();
            return;
        }
    }
}
// 填充输入buffer
bool bEndOfFile = false;
while (!bEndOfFile) {
    int bufferID = GetFreeBufferId();
    if (this->exit_) {
        break;
    }
    if (bufferID < 0) {
        usleep(10000);
        continue;
    }
    auto iter = omxBuffers_.find(bufferID);
    if (iter == omxBuffers_.end()) {
        continue;
    }
    BufferInfo *bufferInfo = iter->second;
    void *sharedAddr = (void *)bufferInfo->avSharedPtr->ReadFromAshmem(0, 0);
    bool bEOS = (size_t)this->ReadOnePacket(fpIn_, (char *)sharedAddr, bufferInfo->omxBuffer->filledLen);
    HDF_LOGI("read data size is %{public}d", bufferInfo->omxBuffer->filledLen);
    bufferInfo->omxBuffer->offset = 0;
    if (bEOS) {
        bufferInfo->omxBuffer->flag = OMX_BUFFERFLAG_EOS;
        bEndOfFile = true;
    }
    auto err = client_->EmptyThisBuffer(client_, bufferInfo->omxBuffer);
    if (err != HDF_SUCCESS) {
        HDF_LOGE("%{public}s EmptyThisBuffer error", __func__);
        return;
    }
}
// wait
while (!this->exit_) {
    usleep(10000);
    continue;
}
// 解码完成后使组件进入OMX_StateIdle状态
client_->SendCommand(client_, OMX_CommandStateSet, OMX_StateIdle, NULL, 0);
```

当在rk开发板上进行解码时，由于其OMX的实现不支持数据的分帧，所以需要手动分帧，目前简单实现按照起始码0x000001或0x00000001分帧发送到服务端处理。分帧代码如下：

```cpp
// 文件分帧读取实现
bool OMXCore::ReadOnePacket(FILE* fp, char* buf, uint32_t& nFilled)
{
    // 先读取4个字节
    size_t t = fread(buf, 1, 4, fp);
    if (t < 4) {
        // 文件读取结束
        return true;
    }
    size_t filled = 0;
    filled = 4;

    bool bRet = true;
    while (!feof(fp)) {
        fread(buf + filled, 1, 1, fp);
        if (buf[filled] == 1) {
            // 检查起始码
            if ((buf[filled - 1] == 0) &&
                (buf[filled - 2] == 0) &&
                (buf[filled - 3] == 0)) {
                fseek(fp, -4, SEEK_CUR);
                filled -= 3;
                bRet = false;
                break;
            } else if ((buf[filled - 1] == 0) &&
                       (buf[filled - 2] == 0)) {
                fseek(fp, -3, SEEK_CUR);
                filled -= 2;
                bRet = false;
                break;
            }
        }
        filled++;
    }
    nFilled = filled;
    return bRet;
}
```

Codec HDI提供3个回调函数：EventHandler，EmptyBufferDone和FillBufferDone。

- EventHandler：主要命令完成后的通知，例如：OMX_StateIdle转为OMX_StateExecuting的命令执行成功通知等。
- EmptyBufferDone：输入数据消费完毕，客户端需要重新填入待编解码数据，再次调用EmptyThisBuffer。
- FillBufferDone：输出数据填充完毕，客户端需要读取已编码/解码数据，再次调用FillThisBuffer。

```cpp
// EmptyBufferDone回调处理示例
int32_t OMXCore::OnEmptyBufferDone(struct CodecCallbackType *self, int8_t *pAppData, uint32_t pAppDataLen,
                                    const struct OmxCodecBuffer *pBuffer)
{
    HDF_LOGI("onEmptyBufferDone: pBuffer.bufferID [%{public}d]", pBuffer->bufferId);
    g_core->OnEmptyBufferDone(pBuffer);
    return HDF_SUCCESS;
}
int32_t OMXCore::OnEmptyBufferDone(const struct OmxCodecBuffer *pBuffer)
{
    unique_lock<mutex> ulk(mLockInputBuffers_);
    unUsedInBuffers_.push_back(pBuffer->bufferId);
    return HDF_SUCCESS;
}
// FillBufferDone回调处理示例
int32_t OMXCore::OnFillBufferDone(struct CodecCallbackType *self, int8_t *pAppData, uint32_t pAppDataLen,
                                    struct OmxCodecBuffer *pBuffer)
{
    HDF_LOGI("onFillBufferDone: pBuffer.bufferID [%{public}d]", pBuffer->bufferId);
    g_core->OnFillBufferDone(pBuffer);
    return HDF_SUCCESS;
}
int32_t OMXCore::onFillBufferDone(struct OmxCodecBuffer* pBuffer)
{
    // 根据bufferID找到buffer
    if (bExit_) {
        return HDF_SUCCESS;
    }

    auto iter = omxBuffers_.find(pBuffer->bufferId);
    if (iter == omxBuffers_.end() || !iter->second) {
        return HDF_SUCCESS;
    }
    // 取出输出的数据
    BufferInfo *pBufferInfo = iter->second;
    const void *addr = pBufferInfo->avSharedPtr->ReadFromAshmem(pBuffer->filledLen, pBuffer->offset);
    // 解码数据保存到文件
    fwrite(addr, 1, pBuffer->filledLen, fpOut_.get());
    fflush(fpOut_.get());
    // 重置buffer数据
    pBuffer->offset    = 0;
    pBuffer->filledLen = 0;
    if (pBuffer->flag == OMX_BUFFERFLAG_EOS) {
        // 结束
        bExit_ = true;
        HDF_LOGI("OnFillBufferDone the END coming");
        return HDF_SUCCESS;
    }
    // 再次调用FillThisBuffer
    auto err = client_->FillThisBuffer(client_, pBufferInfo->pOmxBuffer);
    if (err != HDF_SUCCESS) {
        HDF_LOGE("FillThisBuffer error");
        return HDF_SUCCESS;
    }
    return HDF_SUCCESS;
}

// EventHandler示例
int32_t CodecHdiDecode::OnEvent(struct CodecCallbackType *self, enum OMX_EVENTTYPE event, struct EventInfo *info)
{
    HDF_LOGI("onEvent: appData[0x%{public}p], eEvent [%{public}d], "
        "nData1[%{public}d]", info->appData, event, info->data1);
    switch (event) {
        case OMX_EventCmdComplete: {
            OMX_COMMANDTYPE cmd = (OMX_COMMANDTYPE)info->data1;
            if (OMX_CommandStateSet == cmd) {
                HDF_LOGI("OMX_CommandStateSet reached, status is %{public}d", info->data2);
                g_core->onStatusChanged();
            }
            break;
        }
        default:
            break;
    }
    return HDF_SUCCESS;
}
```

#### 接口去初始化
组件关闭前，需要将组件状态修改为OMX_StateIdle，然后开始释放输入输出Buffer，再将组件状态修改为OMX_StateLoaded，最后再调用DestoryComponent去关闭组件。

##### Buffer释放示例

```cpp
// 发送命令使组件进入OMX_StateLoaded状态
client_->SendCommand(client_, OMX_CommandStateSet, OMX_StateLoaded, nullptr, 0);

// 释放所有申请的buffer
auto iter = omxBuffers_.begin();
while (iter != omxBuffers_.end()) {
    BufferInfo *bufferInfo = iter->second;
    client_->FreeBuffer(client_, (uint32_t)bufferInfo->portIndex, bufferInfo->omxBuffer);
    delete bufferInfo;
    iter++;
}
omxBuffers_.clear();
unUsedInBuffers_.clear();
unUsedOutBuffers_.clear();

enum OMX_STATETYPE status;
client_->GetState(client_, &status);
// buffer释放后组件即进入OMX_StateLoaded状态
if (status != OMX_StateLoaded) {
    HDF_LOGI("Wait for OMX_StateLoaded status");
    this->WaitForStatusChanged();
} else {
    HDF_LOGI(" status is %{public}d", status);
}
```

##### 组件实例释放示例

```cpp
// 组件实例释放
void OMXCore::Release() {
    omxMgr_->DestoryComponent(client_);
    client_ = nullptr;
    CodecComponentManagerRelease();
}
```

# 常见问题

## 解码过程中部分绿屏

**现象描述**

解码过程中，开始能正常解码，后续绿屏比较多。

**可能原因**

OpenMax不支持分帧。

**解决办法**

上层在调用EmptyThisBuffer时，需要按照每次一帧的方式传入。

## 解码过程中全是绿屏

**现象描述**

解码过程中，解码失败全部播放不了。

**可能原因**

OpenMax对AVCC格式的数据处理，第一帧一定要是extra_data，可能没有正常输入extra_data导致AVCC格式解码失败。

**解决办法**

将sps和pps按照extrea_data格式写入buffer，并设置好buffer的flag为OMX_BUFFERFLAG_EXTRADATA。

## 编码输出播放不了

**现象描述**

编码输出视频不正确，将生成的视频流（如H264流）写入文件后，通过ffplay工具播放不了。

**可能原因**

1. 输出端口的xFramerate参数未正常设置。
2. 如果设置了参数OMX_VIDEO_PARAM_AVCTYPE，请检查此参数是否正确。


**解决办法**

请看编码时codec_host的日志，搜索“encode params init settings”，确认是否出现异常的参数。如果是framerate为0，则是原因1，需要将正常的framerate左移16位；如果是其它参数异常，可能是原因2，需要检查其相应的参数。


# 参考

如果您想了解更多关于Codec特性的源码及使用信息，请参考[Codec驱动代码仓](https://gitee.com/openharmony/drivers_peripheral/tree/master/codec)。