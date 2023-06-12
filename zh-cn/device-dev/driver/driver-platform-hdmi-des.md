# HDMI

## 概述

### 功能简介

HDMI（High Definition Multimedia Interface），即高清多媒体接口，主要用于DVD、机顶盒等音视频Source到TV、显示器等Sink设备的传输。

HDMI以主从方式工作，通常有一个Source端和一个Sink端。

HDMI接口定义了完成HDMI传输的通用方法集合，包括：

- HDMI控制器管理：打开或关闭HDMI控制器

- HDMI启动/停止传输：启动或停止HDMI传输

- HDMI控制器设置：设置音频、视频及HDR属性，设置色彩深度、声音图像消隐等

- HDMI读取EDID：读取Sink端原始的EDID数据

- HDMI热插拔：注册/注销热插拔回调函数

### 基本概念

HDMI是Hitachi、Panasonic、Philips、Silicon Image、Sony、Thomson、Toshiba共同发布的一款音视频传输协议。传输过程遵循TMDS（Transition Minimized Differential Signaling）协议。

- TMDS（Transition Minimized Differential signal）：过渡调制差分信号，也被称为最小化传输差分信号，用于发送音频、视频及各种辅助数据。

- DDC（Display Data Channel）：显示数据通道，发送端与接收端可利用DDC通道得知彼此的发送与接收能力，但HDMI仅需单向获知接收端（显示器）的能力。

- CEC（Consumer Electronics Control）：消费电子控制，该功能应该能够在连接HDMI的发送设备与接收设备之间实现交互操作。

- FRL（Fixed Rate Link）：TMDS 的架构进行讯号传输时，最高带宽可达 18Gbps，而FRL模式的带宽则提升到48 Gbps。

- HDCP（High-bandwidth Digital Content Protection）：即高带宽数字内容保护技术，当用户对高清晰信号进行非法复制时，该技术会进行干扰，降低复制出来的影像的质量，从而对内容进行保护。

- EDID（Extended Display Identification Data）：扩展显示标识数据，通常存储在显示器的固件中，标识供应商信息、EDID版本信息、最大图像大小、颜色设置、厂商预设置、频率范围的限制以及显示器名和序列号的字符串。

### 运作机制

在HDF框架中，HDMI模块接口适配模式拟采用独立服务模式，如图1所示。在这种模式下，每一个设备对象会独立发布一个设备服务来处理外部访问，设备管理器收到API的访问请求之后，通过提取该请求的参数，达到调用实际设备对象的相应内部方法的目的。独立服务模式可以直接借助HDF设备管理器的服务管理能力，但需要为每个设备单独配置设备节点，增加内存占用。

独立服务模式下，核心层不会统一发布一个服务供上层使用，因此这种模式下驱动要为每个控制器发布一个服务，具体表现为：

- 驱动适配者需要实现HdfDriverEntry的Bind钩子函数以绑定服务。

- device_info.hcs文件中deviceNode的policy字段为1或2，不能为0。

**图 1** HDMI独立服务模式结构图

![HDMI独立服务模式结构图](figures/独立服务模式结构图.png)

HDMI模块各分层作用：

- 接口层提供打开HDMI设备、启动HDMI传输、停止HDMI传输、声音图像消隐设置、设置色彩深度、获取色彩深度、设置视频属性、获取视频属性、设置HDR属性、读取Sink端原始EDID数据、注册HDMI热插拔检测回调函数、注销HDMI热插拔检测回调函数、关闭HDMI设备的接口。

- 核心层主要提供HDMI控制器的打开、关闭及管理的能力，通过钩子函数与适配层交互。

- 适配层主要是将钩子函数的功能实例化，实现具体的功能。

HDMI的Source端提供+5V和GND，用于DDC和CEC通信。通过DDC通道，Source端可以读取Sink端的各项参数，如接受能力等；CEC为可选通道，用于同步Source端与Sink端的控制信号，改善用户体验。TMDS通道有四组差分信号，TMDS Clock Channel为TMDS提供时钟信号，其余三组传输音视频数据及各种辅助数据；HDP为热插拔检测端口，当有Sink端接入时，Source端会通过中断服务程序进行响应。

HDMI物理连接如图2所示： 
 
**图 2** HDMI物理连线示意图
  
![HDMI物理连线示意图](figures/HDMI物理连线示意图.png)

### 约束与限制

HDMI模块当前仅支持轻量和小型系统内核（LiteOS），暂无实际适配驱动 。

## 使用指导

### 场景介绍

HDMI具有体积小，传输速率高，传输带宽宽，兼容性好，能同时传输无压缩音视频信号等优点。与传统的全模拟接口相比，HDMI不但增加了设备间接线的便捷性，还提供了一些HDMI特有的智能化功能，可用于小体积设备进行高质量音视频传输的场景。

### 接口说明

HDMI模块提供的主要接口如下所示，具体API详见//drivers/hdf_core/framework/include/platform/hdmi_if.h。

**表 1** HDMI驱动API接口功能介绍

| 接口名 | 描述 |
| ----------------------------- | -------------------------- |
| HdmiOpen | 打开HDMI控制器 |
| HdmiClose | 关闭HDMI控制器 |
| HdmiStart | 启动HDMI传输 |
| HdmiStop | 停止HDMI传输 |
| HdmiAvmuteSet | 声音图像消隐设置 |
| HdmiDeepColorSet | 设置色彩深度 |
| HdmiDeepColorGet | 获取色彩深度 |
| HdmiSetVideoAttribute | 设置视频属性 |
| HdmiSetAudioAttribute | 设置音频属性 |
| HdmiSetHdrAttribute | 设置HDR属性 |
| HdmiReadSinkEdid | 读取Sink端原始EDID数据 |
| HdmiRegisterHpdCallbackFunc | 注册HDMI热插拔检测回调函数 |
| HdmiUnregisterHpdCallbackFunc | 注销HDMI热插拔检测回调函数 |

### 开发步骤

使用HDMI设备的一般流程如图3所示。

**图 3** HDMI设备使用流程图
  
![HDMI设备使用流程图](figures/HDMI使用流程图.png)

#### 打开HDMI控制器

在进行HDMI通信前，首先要调用HdmiOpen打开HDMI控制器。

```c
DevHandle HdmiOpen(int16_t number);
```

**表 2** HdmiOpen参数和返回值描述

| 参数 | 参数描述 |
| ---------- | -------------------- |
| number | int16_t类型，HDMI控制器号 |
| **返回值** | **返回值描述** |
| NULL | 打开HDMI控制器失败 |
| 控制器句柄 | 打开的HDMI控制器句柄 |

假设系统中存在2个HDMI控制器，编号从0到1，以下代码示例为获取0号控制器：

```c
DevHandle hdmiHandle = NULL;  // HDMI控制器句柄

// 打开HDMI控制器
hdmiHandle = HdmiOpen(0);
if (hdmiHandle == NULL) {
    HDF_LOGE("HdmiOpen: hdmi open fail!\n");
    return NULL;
}
```

#### 注册热插拔检测回调函数

```c
int32_t HdmiRegisterHpdCallbackFunc(DevHandle handle, struct HdmiHpdCallbackInfo *callback);
```

**表 3** HdmiRegisterHpdCallbackFunc参数和返回值描述

| 参数 | 参数描述 |
| ---------- | ------------------ |
| handle | DevHandle类型，HDMI控制器句柄 |
| callback | 结构体指针，热插拔回调函数信息 |
| **返回值** | **返回值描述** |
| HDF_SUCCESS | 注册成功 |
| 负数 | 注册失败 |

注册热插拔检测回调函数示例：

```c
// 热插拔检测回调函数定义
static void HdmiHpdHandle(void *data, bool hpd)
{
    if (data == NULL) {
        HDF_LOGE("priv data is NULL");
        return;
    }
    if (hpd == true) {
        HDF_LOGD("HdmiHpdHandle: hot plug");
        // 调用者添加相关处理
    } else {
        HDF_LOGD("HdmiHpdHandle: hot unplug");
        // 调用者添加相关处理
    }
}

// 热插拔检测回调函数注册示例
struct HdmiHpdCallbackInfo info = {0};
info.data = handle;
info.callbackFunc = HdmiHpdHandle;
ret = HdmiRegisterHpdCallbackFunc(hdmiHandle, info);
if (ret != HDF_SUCCESS) {
    HDF_LOGE("HdmiRegisterHpdCallbackFunc: Register hpd callback func fail, ret:%d", ret);
    return ret;
}
```

#### 读取EDID

```c
int32_t HdmiReadSinkEdid(DevHandle handle, uint8_t *buffer, uint32_t len);
```

**表 4** HdmiReadSinkEdid参数和返回值描述

| 参数 | 参数描述 |
| ---------- | ---------------------- |
| handle | DevHandle类型，HDMI控制器句柄 |
| buffer | uint8_t类型指针，数据缓冲区 |
| len | uint32_t类型，数据长度 |
| **返回值** | **返回值描述** |
| 正整数 | 成功读取的原始EDID数据 |
| 负数或0 | 读取失败 |

读取Sink端的原始EDID数据示例：

```c
int32_t len;
uint8_t edid[HDMI_EDID_MAX_LEN] = {0};

len = HdmiReadSinkEdid(hdmiHandle, edid, HDMI_EDID_MAX_LEN);
if (len <= 0) {
    HDF_LOGE("HdmiReadSinkEdid: hdmi read sink edid fail, len = %d.", len);
	return HDF_FAILURE;
}
```

#### 设置音频属性

```c
int32_t HdmiSetAudioAttribute(DevHandle handle, struct HdmiAudioAttr *attr);
```

**表 5** HdmiSetAudioAttribute参数和返回值描述

| 参数 | 参数描述 |
| ------ | -------------- |
| handle | DevHandle类型，HDMI控制器句柄 |
| attr | 结构体指针，音频属性 |
| 返回值 | 返回值描述 |
| HDF_SUCCESS | 设置成功 |
| 负数 | 设置失败 |

设置音频属性示例：

```c
struct HdmiAudioAttr audioAttr = {0};
int32_t ret;

audioAttr.codingType = HDMI_AUDIO_CODING_TYPE_MP3;
audioAttr.ifType = HDMI_AUDIO_IF_TYPE_I2S;
audioAttr.bitDepth = HDMI_ADIO_BIT_DEPTH_16;
audioAttr.sampleRate = HDMI_SAMPLE_RATE_8K;
audioAttr.channels = HDMI_AUDIO_FORMAT_CHANNEL_3;
ret = HdmiSetAudioAttribute(handle, &audioAttr);
if (ret != HDF_SUCCESS) {
    HDF_LOGE("HdmiSetAudioAttribute: hdmi set audio attribute fail!, ret:%d", ret);
    return ret;
}
```

#### 设置视频属性

```c
int32_t HdmiSetVideoAttribute(DevHandle handle, struct HdmiVideoAttr *attr);
```

**表 6** HdmiSetVideoAttribute参数和返回值描述

| 参数| 参数描述|
| ---------- | -------------- |
| handle | DevHandle类型，HDMI控制器句柄 |
| attr | 结构体指针，视频属性 |
| **返回值** | **返回值描述** |
| HDF_SUCCESS | 设置成功 |
| 负数 | 设置失败 |

设置视频属性示例：

```c
struct HdmiVideoAttr videoAttr = {0};
int32_t ret;

videoAttr.colorSpace = HDMI_COLOR_SPACE_YCBCR444;
videoAttr.colorimetry = HDMI_COLORIMETRY_EXTENDED;
videoAttr.extColorimetry = HDMI_EXTENDED_COLORIMETRY_BT2020_CONST_LUM;
videoAttr.quantization = HDMI_QUANTIZATION_RANGE_FULL;
ret = HdmiSetVideoAttribute(handle, &videoAttr);
if (ret != HDF_SUCCESS) {
    HDF_LOGE("HdmiSetVideoAttribute: hdmi set video attribute fail, ret:%d.", ret);
    return ret;
}
```

#### 设置HDR属性

```c
int32_t HdmiSetHdrAttribute(DevHandle handle, struct HdmiHdrAttr *attr);
```

**表 7** HdmiSetHdrAttribute参数和返回值描述

| 参数 | 参数描述 |
| ---------- | -------------- |
| handle | DevHandle类型，HDMI控制器句柄 |
| attr | 结构体指针，HDR属性 |
| **返回值** | **返回值描述** |
| HDF_SUCCESS | 设置成功 |
| 负数 | 设置失败 |

设置HDR属性示例：

```c
struct HdmiHdrAttr hdrAttr = {0};
int32_t ret;

hdrAttr.mode = HDMI_HDR_MODE_CEA_861_3;
hdrAttr.userMode = HDMI_HDR_USERMODE_DOLBY;
hdrAttr.eotfType = HDMI_EOTF_SMPTE_ST_2048;
hdrAttr.metadataType = HDMI_DRM_STATIC_METADATA_TYPE_1;
hdrAttr.colorimetry = HDMI_HDR_EXTENDED_COLORIMETRY_XV_YCC_709;
ret = HdmiSetHdrAttribute(handle, &hdrAttr);
if (ret != HDF_SUCCESS) {
    HDF_LOGE("HdmiSetHdrAttribute: hdmi set hdr attribute fail, ret:%d", ret);
    return ret;
}
```

#### 设置HDMI声音图像消隐

```c
int32_t HdmiAvmuteSet(DevHandle handle, bool enable);
```

**表 8** HdmiAvmuteSet参数和返回值描述

| 参数 | 参数描述 |
| ---------- | ----------------- |
| handle | DevHandle类型，HDMI控制器句柄 |
| enable | 布尔值，使能/去使能avmute |
| **返回值** | **返回值描述** |
| HDF_SUCCESS | 设置成功 |
| 负数 | 设置失败 |

设置声音图像消隐示例：

```c
int32_t ret;

ret = HdmiAvmuteSet(hdmiHandle, true);
if (ret != HDF_SUCCESS) {
    HDF_LOGE("HdmiAvmuteSet: hdmi avmute set fail, ret:%d", ret);
    return ret;
}
```

#### 设置色彩深度

```c
int32_t HdmiDeepColorSet(DevHandle handle, enum HdmiDeepColor color);
```

**表 9** HdmiDeepColorSet参数和返回值描述

| 参数 | 参数描述 |
| ---------- | -------------- |
| handle | DevHandle类型，HDMI控制器句柄 |
| color | 枚举类型，色彩深度 |
| **返回值** | **返回值描述** |
| HDF_SUCCESS | 设置成功 |
| 负数 | 设置失败 |

设置色彩深度示例：

```c
int32_t ret;

ret = HdmiDeepColorSet(handle, HDMI_DEEP_COLOR_48BITS);
if (ret != HDF_SUCCESS) {
    HDF_LOGE("HdmiDeepColorSet: hdmi deep color set fail, ret:%d.", ret);
    return ret;
}
```

#### 获取色彩深度

```c
int32_t HdmiDeepColorGet(DevHandle handle, enum HdmiDeepColor *color);
```

**表 10** HdmiDeepColorGet参数和返回值描述

| 参数 | 参数描述 |
| ---------- | -------------- |
| handle | DevHandle类型，HDMI控制器句柄 |
| color | 枚举类型指针，色彩深度 |
| **返回值** | **返回值描述** |
| HDF_SUCCESS | 获取成功 |
| 负数 | 获取失败 |

获取色彩深度示例：

```c
enum HdmiDeepColor color;
int32_t ret;

ret = HdmiDeepColorGet(handle, &color);
if (ret != HDF_SUCCESS) {
    HDF_LOGE("HdmiDeepColorGet: hdmi deep color get fail, ret:%d", ret);
    return ret;
}
```

#### 启动HDMI传输

```c
int32_t HdmiStart(DevHandle handle);
```

**表 11** HdmiStart参数和返回值描述

| 参数 | 参数描述 |
| ---------- | -------------- |
| handle | DevHandle类型，HDMI控制器句柄 |
| **返回值** | **返回值描述** |
| HDF_SUCCESS | 启动成功 |
| 负数 | 启动失败 |

启动HDMI传输示例：

```c
int32_t ret;

ret = HdmiStart(hdmiHandle);
if (ret != HDF_SUCCESS) {
    HDF_LOGE("HdmiStart: start transmission fail, ret:%d", ret);
    return ret;
}
```

#### 停止HDMI传输<a name="section11"></a>

```c
int32_t HdmiStop(DevHandle handle);
```

**表 12** HdmiStop参数和返回值描述

| 参数 | 参数描述 |
| ---------- | -------------- |
| handle | DevHandle类型，HDMI控制器句柄 |
| **返回值** | **返回值描述** |
| HDF_SUCCESS | 停止成功 |
| 负数 | 停止失败 |

停止HDMI传输示例：

```c
int32_t ret;

ret = HdmiStop(hdmiHandle);
if (ret != HDF_SUCCESS) {
    HDF_LOGE("HdmiStop: stop transmission fail, ret:%d.", ret);
    return ret;
}
```

#### 注销热插拔检测回调函数

```c
int32_t HdmiUnregisterHpdCallbackFunc(DevHandle handle);
```

**表 13** HdmiUnregisterHpdCallbackFunc参数和返回值描述

| 参数 | 参数描述 |
| ---------- | -------------- |
| handle | DevHandle类型，HDMI控制器句柄 |
| **返回值** | **返回值描述** |
| HDF_SUCCESS | 注销成功 |
| 负数 | 注销失败 |

注销热插拔检测回调函数示例：

```c
int32_t ret;

ret = HdmiUnregisterHpdCallbackFunc(hdmiHandle);
if (ret != HDF_SUCCESS) {
    HDF_LOGE("HdmiUnregisterHpdCallbackFunc：unregister fail, ret:%d.", ret);
    return ret;
}
```

#### 关闭HDMI控制器

```c
void HdmiClose(DevHandle handle);
```

**表 14**  HdmiClose参数和返回值描述

| 参数 | 参数描述 |
| ---------- | -------------- |
| handle | DevHandle类型，HDMI控制器句柄 |

关闭HDMI控制器示例：

```c
HdmiClose(hdmiHandle);
```

### 使用实例

本例程以操作开发板上的HDMI设备为例，详细展示HDMI接口的完整使用流程。

本例拟在Hi3516DV300开发板上对虚拟驱动进行简单的传输操作：

- SOC：hi3516dv300。

- HDMI控制器：使用0号HDMI控制器。


示例如下：

```c
#include "hdmi_if.h"          /* HDMI标准接口头文件 */
#include "hdf_log.h"         /* 标准日志打印头文件 */
#include "osal_time.h"       /* 标准延迟&睡眠接口头文件 */

/* 热插拔回调函数 */
static void HdmiHpdHandle(void *data, bool hpd)
{
    if (data == NULL) {
    HDF_LOGE("priv data is NULL");
    return;
    }

    if (hpd == true) {
        HDF_LOGD("HdmiHpdHandle: hot plug");
        /* 调用者添加相关处理 */
    } else {
        HDF_LOGD("HdmiHpdHandle: hot unplug");
        /* 调用者添加相关处理 */
    }
}

/* 设置HDMI相关属性 */
static int32_t TestHdmiSetAttr(DevHandle handle)
{
    enum HdmiDeepColor color;
    struct HdmiVideoAttr videoAttr = {0};
    struct HdmiAudioAttr audioAttr = {0};
    struct HdmiHdrAttr hdrAttr = {0};
    int32_t ret;

    ret = HdmiDeepColorSet(handle, HDMI_DEEP_COLOR_48BITS);
    
    if (ret != 0) {
        HDF_LOGE("HdmiDeepColorSet failed.");
        return ret;
    }
    ret = HdmiDeepColorGet(handle, &color);
    if (ret != 0) {
        HDF_LOGE("HdmiDeepColorGet failed.");
        return ret;
    }
    HDF_LOGE("HdmiDeepColorGet successful, color = %d.", color);
    videoAttr.colorSpace = HDMI_COLOR_SPACE_YCBCR444;
    videoAttr.colorimetry = HDMI_COLORIMETRY_EXTENDED;
    videoAttr.extColorimetry = HDMI_EXTENDED_COLORIMETRY_BT2020_CONST_LUM;
    videoAttr.quantization = HDMI_QUANTIZATION_RANGE_FULL;
    ret = HdmiSetVideoAttribute(handle, &videoAttr);
    if (ret != 0) {
        HDF_LOGE("HdmiSetVideoAttribute failed.");
        return ret;
    }
    audioAttr.codingType = HDMI_AUDIO_CODING_TYPE_MP3;
    audioAttr.ifType = HDMI_AUDIO_IF_TYPE_I2S;
    audioAttr.bitDepth = HDMI_ADIO_BIT_DEPTH_16;
    audioAttr.sampleRate = HDMI_SAMPLE_RATE_8K;
    audioAttr.channels = HDMI_AUDIO_FORMAT_CHANNEL_3;
    ret = HdmiSetAudioAttribute(handle, &audioAttr);
    if (ret != 0) {
        HDF_LOGE("HdmiSetAudioAttribute failed.");
        return ret;
    }
    hdrAttr.mode = HDMI_HDR_MODE_CEA_861_3;
    hdrAttr.userMode = HDMI_HDR_USERMODE_DOLBY;
    hdrAttr.eotfType = HDMI_EOTF_SMPTE_ST_2048;
    hdrAttr.metadataType = HDMI_DRM_STATIC_METADATA_TYPE_1;
    hdrAttr.colorimetry = HDMI_HDR_EXTENDED_COLORIMETRY_XV_YCC_709;
    ret = HdmiSetHdrAttribute(handle, &hdrAttr);
    if (ret != 0) {
        HDF_LOGE("HdmiSetHdrAttribute failed.");
        return ret;
    }

    return 0;
}

/* HDMI例程总入口 */
static int32_t TestCaseHdmi(void)
{
    DevHandle handle = NULL;
    int32_t ret;

    struct HdmiHpdCallbackInfo info = {0};
    uint8_t data[128] = {0};

    HDF_LOGD("HdmiAdapterInit: successful.");
    handle = HdmiOpen(0);
    if (handle == NULL) {
        HDF_LOGE("HdmiOpen failed.");
        return ret;
    }
    info.data = handle;
    info.callbackFunc = HdmiHpdHandle;
    ret = HdmiRegisterHpdCallbackFunc(handle, &info);
    if (ret != 0) {
        HDF_LOGE("HdmiRegisterHpdCallbackFunc failed.");
        return ret;
    }

    ret = HdmiReadSinkEdid(handle, data, 128);
    if (ret <= 0) {
        HDF_LOGE("HdmiReadSinkEdid failed.");
        return ret;
    }
    HDF_LOGE("HdmiReadSinkEdid successful, data[6] = %d, data[8] = %d.", data[6], data[8]);

    ret = TestHdmiSetAttr(handle);
    if (ret != 0) {
        HDF_LOGE("TestHdmiSetAttr failed.");
        return ret;
    }

    ret = HdmiStart(handle);
    if (ret != 0) {
        HDF_LOGE("HdmiStart failed.");
        return ret;
    }

    OsalMSleep(1000);

    ret = HdmiStop(handle);
    if (ret != 0) {
        HDF_LOGE("HdmiStop failed.");
        return ret;
    }

    ret = HdmiUnregisterHpdCallbackFunc(handle);
    if (ret != 0) {
        HDF_LOGE("HdmiUnregisterHpdCallbackFunc failed.");
        return ret;
    }
    HdmiClose(handle);
    return 0;
}

```
