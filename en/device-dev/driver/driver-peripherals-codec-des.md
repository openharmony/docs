# Codec

## Overview
### Function

The codec Hardware Device Interface (HDI) driver framework is implemented based on OpenHarmony Hardware Driver Foundation (HDF). The HDI driver framework implements the video hardware codec driver based on OpenMAX. It provides APIs for the upper-layer media services to obtain component encoding and decoding capabilities, create a component, set parameters, transfer data, and destroy a component. The codec driver can encode video data in YUV or RGB format to H.264 or H.265 format, and decode raw stream data from H.264 or H.265 format to YUV or RGB format.

The figure below shows the codec HDI driver framework.

**Figure 1** Codec HDI driver framework

![image](figures/Codec_architecture.png "Codec HDI driver framework")

- Codec HDI Callback Remote Service: an anonymous callback service used to process callbacks.
- Codec HDI: provides standard APIs based on OpenMAX. The upper layer services call the APIs to implement hardware encoding and decoding.
- Codec HDI Adapter: HDI implementation layer, which implements HDI APIs and interacts with OpenMAX Integration layer (IL).
- OpenMAX IL interface: provides OpenMAX IL APIs to directly interact with the codec HDI driver.
- Vendor Impl: vendor adaptation layer, which is the OpenMAX implementation layer adapted by each vendor.
- Codec Hardware: hardware coding and decoding device.

### Basic Concepts
Before you get started, understand the following concepts:

- Sampling rate

    The number of samples taken from continuous signals every second to form discrete signals, in Hz.

- OpenMAX IL

    A standardized media component interface to enable applications and media frameworks to interact with multimedia codecs and supported components in a unified manner.

- Frame rate

    Number of frames of images transmitted per second, or the number of times that a GPU can refresh images per second. A higher frame rate indicates smoother motion, while a lower frame rate means choppier motion and blurry footage.

- Bit rate

    Number of bits transmitted or processed per unit of time, generally in kbit/s. A higher bit rate indicates clearer image, while a lower bit rate means blurry image with artifacts.

- Component

    An OpenMAX IL component, which is an abstraction of modules in video streams. The components in this document refer to codec components used for video encoding and decoding.

### Constraints

The codec HDI applies only to the standard system.

For more details, see [OpenMAX IL](https://www.khronos.org/api/openmax/il).

## Development Guidelines

### When to Use
The codec module implements hardware encoding and decoding of video data. It converts raw stream data such as H.264 data into YUV or RGB data, and converts YUV or RGB data into data formats such as H.264.

### Available APIs

- codec_component_manager.h

  | API                                                                                                                                     | Description                     |
  | -------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------|
  | int32_t (*CreateComponent)(struct CodecComponentType **component, uint32_t *componentId, char *compName, int64_t appData, struct CodecCallbackType *callbacks) | Creates a codec component instance.            |
  | int32_t (*DestroyComponent)(uint32_t componentId)                                                                                                              | Destroys a codec component instance.                 |

- codec_component _if.h

  | API                                                                                                                                                               | Description                     |
  | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------- |
  | int32_t (*SendCommand)(struct CodecComponentType *self, enum OMX_COMMANDTYPE cmd, uint32_t param, int8_t *cmdData, uint32_t cmdDataLen)                                 | Sends commands to a component.               |
  | int32_t (*GetParameter)(struct CodecComponentType *self, uint32_t paramIndex, int8_t *paramStruct, uint32_t paramStructLen)                                        | Obtains component parameter settings.             |
  | int32_t (*SetParameter)(struct CodecComponentType *self, uint32_t index, int8_t *paramStruct, uint32_t paramStructLen)                                                  | Sets component parameters.           |
  | int32_t (*GetState)(struct CodecComponentType *self, enum OMX_STATETYPE *state)                                                                                         | Obtains the component status.               |
  | int32_t (*UseBuffer)(struct CodecComponentType *self, uint32_t portIndex, struct OmxCodecBuffer *buffer)                                                                | Requests a port buffer for the component.         |
  | int32_t (*FreeBuffer)(struct CodecComponentType *self, uint32_t portIndex, const struct OmxCodecBuffer *buffer)                                                         | Releases the buffer.                   |
  | int32_t (*EmptyThisBuffer)(struct CodecComponentType *self, const struct OmxCodecBuffer *buffer)                                                                        | Empties this buffer.       |
  | int32_t (*FillThisBuffer)(struct CodecComponentType *self, const struct OmxCodecBuffer *buffer)                                                                         | Fills this buffer.         |

- codec_callback_if.h

  | API                                                                                                        | Description                          |
  | ---------------------------------------------------------------------------------------------------------------- |----------------------------------- |
  | int32_t (*EventHandler)(struct CodecCallbackType *self, enum OMX_EVENTTYPE event, struct EventInfo *info)        | Reports an event.                          |
  | int32_t (*EmptyBufferDone)(struct CodecCallbackType *self, int64_t appData, const struct OmxCodecBuffer *buffer) | Reports an event indicating that the encoding or decoding in the input buffer is complete.|
  | int32_t (*FillBufferDone)(struct CodecCallbackType *self, int64_t appData, const struct OmxCodecBuffer *buffer)  | Reports an event indicating that the output buffer is filled.            |

For more information, see [codec](https://gitee.com/openharmony/drivers_peripheral/tree/master/codec).

### Development Procedure
The codec HDI driver development procedure is as follows:

#### Registering and Initializing the Driver
Define the **HdfDriverEntry** structure (which defines the driver initialization method) and fill in the **g_codecComponentDriverEntry** structure to implement the pointers in **Bind()**, **Init()**, and **Release()**.

```c
struct HdfDriverEntry g_codecComponentDriverEntry = {
    .moduleVersion = 1,
    .moduleName = "codec_hdi_omx_server",
    .Bind = HdfCodecComponentTypeDriverBind,
    .Init = HdfCodecComponentTypeDriverInit,
    .Release = HdfCodecComponentTypeDriverRelease,
};
HDF_INIT(g_codecComponentDriverEntry); // Register HdfDriverEntry of the codec HDI with the HDF.
```

- **HdfCodecComponentTypeDriverBind**: binds the device in the HDF to **CodecComponentTypeHost** and registers the codec service with the HDF.

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

- **HdfCodecComponentTypeDriverInit**: loads the attribute configuration in the HDF Configuration Source (HCS).

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

- **HdfCodecComponentTypeDriverRelease**: releases the driver instance.

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

#### Driver HCS
The HCS consists of the following:

- Device configuration
- Configuration of the supported components

You need to configure the driver node, loading sequence, and service name. For details about the HCS syntax, see [Configuration Management](driver-hdf-manage.md).

The following uses the RK3568 development board as an example. The configuration files of the standard system are in the **vendor/hihope/rk3568/hdf_config/uhdf/** directory.

1. Configure the device.

    Add the **codec_omx_service** configuration to **codec_host** in **device_info.hcs**. The following is an example:
    ```c
    codec :: host {
        hostName = "codec_host";
        priority = 50;
        gid = ["codec_host", "uhdf_driver", "vendor_mpp_driver"];
        codec_omx_device :: device {
            device0 :: deviceNode {
                policy = 2;                                       // Automatic loading, not lazy loading.
                priority = 100;                                   // Priority.
                moduleName = "libcodec_hdi_omx_server.z.so";      // Dynamic library of the driver.
                serviceName = "codec_hdi_omx_service";            // Service name of the driver.
                deviceMatchAttr = "codec_component_capabilities"; // Attribute configuration.
            }
        }
    }
    ```

2. Configure supported components.

    Add the component configuration to the **media_codec\codec_component_capabilities.hcs** file. The following is an example:
    ```c
    /* Explanation to the node name HDF_video_hw_enc_avc_rk:
    **
    **    HDF____________video__________________hw____________________enc____________avc_______rk
    **     |               |                    |                      |              |        |
    ** HDF or OMX    video or audio    hardware or software    encoder or decoder    MIME    vendor
    */
    HDF_video_hw_enc_avc_rk {
        role = 1;                                           // Role of the audio and video codec.
        type = 1;                                           // Codec type.
        name = "OMX.rk.video_encoder.avc";                  // Component name.
        supportProfiles = [1, 32768, 2, 32768, 8, 32768];   // Supported profiles.
        maxInst = 4;                                        // Maximum number of instances.
        isSoftwareCodec = false;                            // Whether it is software codec.
        processModeMask = [];                               // Codec processing mode.
        capsMask = [0x01];                                  // CodecCapsMask configuration.
        minBitRate = 1;                                     // Minimum bit rate.
        maxBitRate = 40000000;                              // Maximum bit rate.
        minWidth = 176;                                     // Minimum video width.
        minHeight = 144;;                                   // Minimum video height.
        maxWidth = 1920;                                    // Maximum video width.
        maxHeight = 1088;                                   // Maximum video height.
        widthAlignment = 16;                                // Horizontal alignment.
        heightAlignment = 8;                                // Vertical alignment.
        minBlockCount = 0xFFFFFFFF;
        maxBlockCount = 0xFFFFFFFF;
        minBlocksPerSecond = 0xFFFFFFFF;
        maxBlocksPerSecond = 0xFFFFFFFF;
        blockSizeWidth = 0xFFFFFFFF;
        blockSizeHeight = 0xFFFFFFFF;
        supportPixelFmts = [28, 24, 30, 22, 7, 3, 14, 13, 20, 26, 27, 12]; // List of supported colors.
        measuredFrameRate = [320, 240, 165, 165, 720, 480, 149, 149, 1280, 720, 73, 73, 1920, 1080, 18, 18];
        bitRateMode = [1, 2];                                // Bit rate mode.
        minFrameRate = 0;                                    // Frame rate.
        maxFrameRate = 0;
    }
    ```

### Development Example
After completing codec module driver adaptation, use the HDI APIs provided by the codec module for further development. The codec HDI provides the following features:

1. Provides codec HDI APIs for video services to implement encoding and decoding for video services.
2. Provides standard interfaces for device developers to ensure that the OEM vendors comply with the HDI adapter standard. This promises a healthy evolution of the ecosystem.

The development procedure is as follows:

1. Initialize the driver, including initializing the instances, callbacks, and component.
2. Set codec parameters and information such as the video width, height, and bit rate.
3. Apply for input and output buffers.
4. Flip codec buffers, enable the component to enter the **OMX_Executing** state, and process the callbacks.
5. Deinitialize the interface instance, destroy the buffers, close the component, and releases all interface instances.

#### Initializing the Driver
Initialize the interface instance and callbacks, and create a component.
```cpp
// Initialize the codec HDI ComponentManager instance.
omxMgr_ = GetCodecComponentManager();

// Initialize the callback.
callback_ = CodecCallbackTypeStubGetInstance();
if (!omxMgr_ || !callback_) {
    FUNC_EXIT_ERR();
    return false;
}
// Set the callback pointers.
callback_->EventHandler    = &OMXCore::OnEvent;
callback_->EmptyBufferDone = &OMXCore::OnEmptyBufferDone;
callback_->FillBufferDone  = &OMXCore::OnFillBufferDone;

// Create a component instance.
uint32_t err = HDF_SUCCESS;
if (codec == codecMime::AVC) {
    err = omxMgr_->CreateComponent(&client_, &componentId_, const_cast<char *>(DECODER_AVC), (int64_t)this,
                                   callback_);
} else {
    err = omxMgr_->CreateComponent(&client_, &componentId_, const_cast<char *>(DECODER_HEVC), (int64_t)this,
                                   callback_);
}
```

#### Setting Codec Parameters and Configuration
Set the width and height of the input and output data, input data format, and output data format.
```cpp
// Set the width and height of the input image.
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
// Set the output width, height, and format.
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
param.format.video.eColorFormat = AV_COLOR_FORMAT; // Set the output data format to YUV420SP.
err = client_->SetParameter(client_, OMX_IndexParamPortDefinition, (int8_t *)&param, sizeof(param));
if (err != HDF_SUCCESS) {
    HDF_LOGE("%{public}s failed  with PortIndex::PORT_INDEX_OUTPUT, index is OMX_IndexParamPortDefinition",
             __func__);
    return false;
}
// Set the input data format to H.264/H.265.
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
param.xFramerate = FRAME; // Set the frame rate to 30.
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

#### Applying for Input and Output Buffers
Perform the following steps:

1. Use **UseBuffer()** to apply for input and output buffers and save the buffer IDs. The buffer IDs can be used for subsequent buffer flipping.
2. Check whether the corresponding port is enabled. If not, enable the port first.
3. Use **SendCommand()** to change the component status to **OMX_StateIdle**, and wait until the operation result is obtained.
```cpp
// Apply for the input buffer.
auto ret = UseBufferOnPort(PortIndex::PORT_INDEX_INPUT);
if (!ret) {
    HDF_LOGE("%{public}s UseBufferOnPort PortIndex::PORT_INDEX_INPUT error", __func__);
    return false;
}
// Apply for the output buffer.
ret = UseBufferOnPort(PortIndex::PORT_INDEX_OUTPUT);
if (!ret) {
    HDF_LOGE("%{public}s UseBufferOnPort PortIndex::PORT_INDEX_OUTPUT error", __func__);
    return false;
}
// Enable the component to enter the OMX_StateIdle state.
auto err = client_->SendCommand(client_, OMX_CommandStateSet, OMX_StateIdle, NULL, 0);
if (err != HDF_SUCCESS) {
    HDF_LOGE("%{public}s failed to SendCommand with OMX_CommandStateSet:OMX_StateIdle", __func__);
    return false;
}
HDF_LOGI("Wait for OMX_StateIdle status");
this->WaitForStatusChanged();
```

Implement **UseBufferOnPort()** as follows:

```cpp
bool CodecHdiDecode::UseBufferOnPort(enum PortIndex portIndex)
{
    HDF_LOGI("%{public}s enter, portIndex = %{public}d", __func__, portIndex);
    int bufferSize = 0;
    int bufferCount = 0;
    bool bPortEnable = false;
    // Obtain parameters of the port buffer.
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
    // Set the port buffer.
    UseBufferOnPort(portIndex, bufferCount, bufferSize);
    // Check whether the port is available.
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

#### Codec Buffer Flipping
Set the component to the **OMX_StateExecuting** state, fill the input buffer, read data from the output buffer, and flip the buffers.

```cpp
// Set the component to the OMX_StateExecuting state and start buffer flipping.
HDF_LOGI("...command to OMX_StateExecuting....");
auto err = client_->SendCommand(client_, OMX_CommandStateSet, OMX_StateExecuting, NULL, 0);
if (err != HDF_SUCCESS) {
    HDF_LOGE("%{public}s failed to SendCommand with OMX_CommandStateSet:OMX_StateIdle", __func__);
    return;
}
// Set the output buffer to fill.
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
// Fill the input buffer.
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
// Wait.
while (!this->exit_) {
    usleep(10000);
    continue;
}
// Enable the component to enter the OMX_StateIdle state after decoding.
client_->SendCommand(client_, OMX_CommandStateSet, OMX_StateIdle, NULL, 0);
```

The RK3568 development board does not support data framing. Therefore, you need to manually divide the data into frames. Data is divided from code 0x000001 or 0x00000001 and sent to the server for processing. The sample code is as follows:

```cpp
// Read a file by frame.
bool OMXCore::ReadOnePacket(FILE* fp, char* buf, uint32_t& nFilled)
{
    // Read four bytes first.
    size_t t = fread(buf, 1, 4, fp);
    if (t < 4) {
        // The file reading ends.
        return true;
    }
    size_t filled = 0;
    filled = 4;

    bool bRet = true;
    while (!feof(fp)) {
        fread(buf + filled, 1, 1, fp);
        if (buf[filled] == 1) {
            // Check the start code.
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

The codec HDI provides the following callbacks:

- **EventHandler**: Called when a command is executed. For example, when the command for changing the component state from **OMX_StateIdle** to **OMX_StateExecuting** is executed, this callback is invoked to return the result.
- **EmptyBufferDone**: Called when the input data is consumed. If the client needs to fill data to encode or decode, it must call **EmptyThisBuffer()** again.
- **FillBufferDone**: Called when the output data is filled. If the client needs to read the encoded or decoded data, it must call **FillThisBuffer()** again.

```cpp
// EmptyBufferDone example
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
// FillBufferDone example
int32_t OMXCore::OnFillBufferDone(struct CodecCallbackType *self, int8_t *pAppData, uint32_t pAppDataLen,
                                    struct OmxCodecBuffer *pBuffer)
{
    HDF_LOGI("onFillBufferDone: pBuffer.bufferID [%{public}d]", pBuffer->bufferId);
    g_core->OnFillBufferDone(pBuffer);
    return HDF_SUCCESS;
}
int32_t OMXCore::onFillBufferDone(struct OmxCodecBuffer* pBuffer)
{
    // Locate the buffer based on the buffer ID.
    if (bExit_) {
        return HDF_SUCCESS;
    }

    auto iter = omxBuffers_.find(pBuffer->bufferId);
    if (iter == omxBuffers_.end() || !iter->second) {
        return HDF_SUCCESS;
    }
    // Obtain the output data.
    BufferInfo *pBufferInfo = iter->second;
    const void *addr = pBufferInfo->avSharedPtr->ReadFromAshmem(pBuffer->filledLen, pBuffer->offset);
    // Decode the data and save it to a file.
    fwrite(addr, 1, pBuffer->filledLen, fpOut_.get());
    fflush(fpOut_.get());
    // Reset the buffer data.
    pBuffer->offset    = 0;
    pBuffer->filledLen = 0;
    if (pBuffer->flag == OMX_BUFFERFLAG_EOS) {
        // End
        bExit_ = true;
        HDF_LOGI("OnFillBufferDone the END coming");
        return HDF_SUCCESS;
    }
    // Call FillThisBuffer() again.
    auto err = client_->FillThisBuffer(client_, pBufferInfo->pOmxBuffer);
    if (err != HDF_SUCCESS) {
        HDF_LOGE("FillThisBuffer error");
        return HDF_SUCCESS;
    }
    return HDF_SUCCESS;
}

// EventHandler example
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

#### Destroying a Component
Change the component state to **OMX_StateIdle**, release the input and output buffers, change the component state to **OMX_StateLoaded**, and call **DestoryComponent** to destroy the component.

##### Example of Releasing Buffers

```cpp
// Change the component state to OMX_StateLoaded.
client_->SendCommand(client_, OMX_CommandStateSet, OMX_StateLoaded, nullptr, 0);

// Release all buffers in use.
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
// After the buffers are released, the component enters the OMX_StateLoaded state.
if (status != OMX_StateLoaded) {
    HDF_LOGI("Wait for OMX_StateLoaded status");
    this->WaitForStatusChanged();
} else {
    HDF_LOGI(" status is %{public}d", status);
}
```

##### Example of Destroying a Component Instance

```cpp
// Destroy a component instance.
void OMXCore::Release() {
    omxMgr_->DestoryComponent(client_);
    client_ = nullptr;
    CodecComponentManagerRelease();
}
```

# FAQs

## Green Screens Displayed During the Decoding Process

**Symptom**

Green screens are displayed during the decoding process.

**Possible Causes**

OpenMAX does not support framing.

**Solution**

Pass in one frame at a time when **EmptyThisBuffer** is call.

## Only Green Screen Displayed During the Decoding Process

**Symptom**

Decoding fails, and all the frames decoded cannot be played.

**Possible Causes**

For the data in AVCC format, the first frame to be processed must be extra_data.

**Solution**

Write sps and pps to the buffer in extra_data format, and set the buffer flag to **OMX_BUFFERFLAG_EXTRADATA**.

## Failed to Play the Encoded Video

**Symptom**

After the generated video stream (H.264 stream) is written to a file, the video stream cannot be played by FFplay.

**Possible Causes**

- The **xFramerate** parameter of the output port is incorrectly set.
- The **OMX_VIDEO_PARAM_AVCTYPE** parameter is correctly set.


**Solution**

View the **codec_host** log generated during encoding, search for "encode params init settings", and check for incorrect parameters. If **framerate** is **0**, **xFramerate** is incorrectly set. In this case, move the frame rate leftwards by 16 bits. 

Check and correct the setting of **OMX_VIDEO_PARAM_AVCTYPE**. 


# Reference

For more information, see [codec](https://gitee.com/openharmony/drivers_peripheral/tree/master/codec).
