# HDMI<a name="1"></a>

-   [概述](#section1)
-   [接口说明](#section2)
-   [使用指导](#section3)
    -   [使用流程](#section4)
    -   [打开HDMI控制器](#section5)
    -   [注册热插拔回调函数](#section6)
    -   [读取EDID](#section7)
    -   [设置属性](#section8)
    -   [启动HDMI传输](#section10)
    -   [停止HDMI传输](#section11)
    -   [注销热插拔回调函数](#section12)
    -   [关闭HDMI控制器](#section13)
    
-   [使用实例](#section14)

## 概述<a name="section1"></a>

-   HDMI（High-Definition Multiface Interface）是Hitachi, Panasonic, Philips, SiliconImage, Sony, Thomson, Toshiba共同发布的一款音视频传输协议。
-   HDMI以主从方式工作，通常有一个Source端和一个Sink端。
-   HDMI接口定义了完成HDMI传输的通用方法集合，包括：

    - HDMI控制器管理：打开或关闭HDMI控制器
    - HDMI启动/停止传输：启动或停止HDMI传输
    - HDMI控制器设置：设置音频、视频及HDR属性，设置色彩深度、声音图像消隐等
    - HDMI读取EDID：读取Sink端原始的EDID数据
    - HDMI热插拔：注册/注销热插拔回调函数
-   HDMI物理连接如[图1](#fig1)所示：  
     **图 1**  HDMI物理连线示意图<a name="fig1"></a>  
     ![](figures/HDMI物理连线示意图.png "HDMI物理连线示意图")

## 接口说明<a name="section2"></a>

**表 1**  HDMI驱动API接口功能介绍

<a name="table1"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="18.63%"><p>功能分类</p>
</th>
<th class="cellrowborder" valign="top" width="28.03%"><p>接口名</p>
</th>
<th class="cellrowborder" valign="top" width="53.339999999999996%"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" bgcolor="#ffffff" rowspan="2" valign="top" width="18.63%"><p>HDMI控制器管理接口</p>
</td>
<td class="cellrowborder" valign="top" width="28.03%"><p>HdmiOpen</p>
</td>
<td class="cellrowborder" valign="top" width="53.339999999999996%">打开HDMI控制器</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top"><p>HdmiClose</p>
</td>
<td class="cellrowborder" valign="top"><p>关闭HDMI控制器</p>
</td>
</tr>
<tr><td class="cellrowborder" bgcolor="#ffffff" rowspan="2" valign="top" width="18.63%"><p>启动/停止HDMI传输接口</p>
</td>
<td class="cellrowborder" valign="top" width="28.03%"><p>HdmiStart</p>
</td>
<td class="cellrowborder" valign="top" width="53.339999999999996%">启动HDMI传输</p>
</td>
</tr>
<tr id="row5632152611414"><td class="cellrowborder" valign="top"><p>HdmiStop</p>
</td>
<td class="cellrowborder" valign="top"><p>停止HDMI传输</p>
</td>
</tr>
<tr><td class="cellrowborder" bgcolor="#ffffff" rowspan="6" valign="top" width="18.63%"><p>HDMI控制器设置接口</p>
</td>
<td class="cellrowborder" valign="top" width="28.03%"><p>HdmiAvmuteSet</p>
</td>
<td class="cellrowborder" valign="top" width="53.339999999999996%">HDMI声音图像消隐设置</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top"><p>HdmiDeepColorSet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p>设置色彩深度</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top"><p>HdmiDeepColorGet</p>
</td>
<td class="cellrowborder" valign="top"><p>获取色彩深度</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top"><p>HdmiSetVideoAttribute</p>
</td>
<td class="cellrowborder" valign="top"><p>设置视频属性</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top"><p>HdmiSetAudioAttribute</p>
</td>
<td class="cellrowborder" valign="top"><p>设置音频属性</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top"><p>HdmiSetHdrAttribute</p>
</td>
<td class="cellrowborder" valign="top"><p>设置HDR属性</p>
</td>
</tr>
<tr><td class="cellrowborder" bgcolor="#ffffff" valign="top" width="18.63%"><p>EDID获取接口</p>
</td>
<td class="cellrowborder" valign="top" width="28.03%"><p>HdmiReadSinkEdid</p>
</td>
<td class="cellrowborder" valign="top" width="53.339999999999996%">HDMI读取Sink端原始EDID数据</p>
</td>
</tr>
<tr><td class="cellrowborder" bgcolor="#ffffff" rowspan="2" valign="top" width="18.63%"><p>HDMI热插拔相关接口</p>
</td>
<td class="cellrowborder" valign="top" width="28.03%"><p>HdmiRegisterHpdCallbackFunc</p>
</td>
<td class="cellrowborder" valign="top" width="53.339999999999996%">注册HDMI热插拔检测回调函数</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top"><p>HdmiUnregisterHpdCallbackFunc</p>
</td>
<td class="cellrowborder" valign="top"><p>注销HDMI热插拔检测回调函数</p>
</td>
</tr>
</tbody>
</table>

## 使用指导<a name="section3"></a>

### 使用流程<a name="section4"></a>

使用HDMI设备的一般流程如[图2](#fig2)所示。

**图 2**  HDMI设备使用流程图<a name="fig2"></a>  
![](figures/HDMI使用流程图.png "HDMI使用流程图")

### 打开HDMI控制器<a name="section5"></a>

在进行HDMI通信前，首先要调用HdmiOpen打开HDMI控制器。

```c
DevHandle HdmiOpen(int16_t number);
```

**表 2**  HdmiOpen参数和返回值描述

<a name="table2"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="20.66%"><p>参数</strong></p>
</th>
<th class="cellrowborder" valign="top" width="79.34%"><p><strong>参数描述</strong></p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="20.66%"><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="79.34%"><p>HDMI控制器号</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.66%"><p><strong>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="79.34%"><p><strong>返回值描述</strong></p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.66%"><p>NULL</p>
</td>
<td class="cellrowborder" valign="top" width="79.34%"><p>打开HDMI控制器失败</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.66%"><p>控制器句柄</p>
</td>
<td class="cellrowborder" valign="top" width="79.34%"><p>打开的HDMI控制器句柄</p>
</td>
</tr>
</tbody>
</table>

假设系统中存在2个HDMI控制器，编号从0到1，那么我们现在获取0号控制器：

```c
DevHandle hdmiHandle = NULL;  /* HDMI控制器句柄 /

/* 打开HDMI控制器 */
hdmiHandle = HdmiOpen(0);
if (hdmiHandle == NULL) {
    HDF_LOGE("HdmiOpen: failed\n");
    return;
}
```

### 注册热插拔检测回调函数<a name="section6"></a>

```c
int32_t HdmiRegisterHpdCallbackFunc(DevHandle handle, struct HdmiHpdCallbackInfo *callback);
```

**表 3**  HdmiRegisterHpdCallbackFunc参数和返回值描述

<a name="table3"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="50%"><p><strong>参数</strong></p>
</th>
<th class="cellrowborder" valign="top" width="50%"><p><strong>参数描述</strong></p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="50%"><p>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>HDMI控制器句柄</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>callback</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>热插拔回调函数信息</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p><strong>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p><strong>返回值描述</strong></p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>注册成功</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>负数</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>注册失败</p>
</td>
</tr>
</tbody>
</table>

注册热插拔检测回调函数示例：

```c
/* 热插拔检测回调函数定义 */
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
        HDF_LOGD("HdmiHpdHandle: hot unplog");
        /* 调用者添加相关处理 */
    }
}

    /* 热插拔检测回调函数注册示例 */
    struct HdmiHpdCallbackInfo info = {0};
    info.data = handle;
    info.callbackFunc = HdmiHpdHandle;
    ret = HdmiRegisterHpdCallbackFunc(hdmiHandle, info);
    if (ret != 0) {
        HDF_LOGE("HdmiRegisterHpdCallbackFunc: Register failed.");
    }
```

### 读取EDID<a name="section7"></a>

```c
int32_t HdmiReadSinkEdid(DevHandle handle, uint8_t *buffer, uint32_t len);
```

**表 4**  HdmiReadSinkEdid参数和返回值描述

<a name="table4"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="50%"><p><strong>参数</strong></p>
</th>
<th class="cellrowborder" valign="top" width="50%"><p><strong>参数描述</strong></p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="50%"><p>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>HDMI控制器句柄</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>buffer</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>数据缓冲区</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>len</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>数据长度</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p><strong>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p><strong>返回值描述</strong></p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>正整数</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>成功读取的原始EDID数据</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>负数或0</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>读取失败</p>
</td>
</tr>
</tbody>
</table>

读取Sink端的原始EDID数据示例：

```c
int32_t len;
uint8_t edid[HDMI_EDID_MAX_LEN] = {0};

len = HdmiReadSinkEdid(hdmiHandle, edid, HDMI_EDID_MAX_LEN);
if (len <= 0) {
    HDF_LOGE("%s: HdmiReadSinkEdid failed len = %d.", __func__, len);
}
```

### 设置音频、视频及HDR属性<a name="section8"></a>

#### 设置音频属性

```c
int32_t HdmiSetAudioAttribute(DevHandle handle, struct HdmiAudioAttr *attr);
```

**表 5**  HdmiSetAudioAttribute参数和返回值描述

<a name="table5"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="50%"><p><strong>参数</strong></p>
</th>
<th class="cellrowborder" valign="top" width="50%"><p><strong>参数描述</strong></p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="50%"><p>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>HDMI控制器句柄</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>attr</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>音频属性</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p><strong>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p><strong>返回值描述</strong></p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>设置成功</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>负数</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>设置失败</p>
</td>
</tr>
</tbody>
</table>

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
if (ret != 0) {
    HDF_LOGE("HdmiSetAudioAttribute failed.");
}
```

#### 设置视频属性

```c
int32_t HdmiSetVideoAttribute(DevHandle handle, struct HdmiVideoAttr *attr);
```

**表 6**  HdmiSetVideoAttribute参数和返回值描述

<a name="table6"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="50%"><p><strong>参数</strong></p>
</th>
<th class="cellrowborder" valign="top" width="50%"><p><strong>参数描述</strong></p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="50%"><p>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>HDMI控制器句柄</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>attr</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>视频属性</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p><strong>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p><strong>返回值描述</strong></p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>设置成功</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>负数</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>设置失败</p>
</td>
</tr>
</tbody>
</table>

设置视频属性示例：

```c
struct HdmiVideoAttr videoAttr = {0};
int32_t ret;

videoAttr.colorSpace = HDMI_COLOR_SPACE_YCBCR444;
videoAttr.colorimetry = HDMI_COLORIMETRY_EXTENDED;
videoAttr.extColorimetry = HDMI_EXTENDED_COLORIMETRY_BT2020_CONST_LUM;
videoAttr.quantization = HDMI_QUANTIZATION_RANGE_FULL;
ret = HdmiSetVideoAttribute(handle, &videoAttr);
if (ret != 0) {
    HDF_LOGE("HdmiSetVideoAttribute failed.");
}
```

#### 设置HDR属性

```c
int32_t HdmiSetHdrAttribute(DevHandle handle, struct HdmiHdrAttr *attr);
```

**表 7**  HdmiSetHdrAttribute参数和返回值描述

<a name="table7"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="50%"><p><strong>参数</strong></p>
</th>
<th class="cellrowborder" valign="top" width="50%"><p><strong>参数描述</strong></p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="50%"><p>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>HDMI控制器句柄</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>attr</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>HDR属性</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p><strong>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p><strong>返回值描述</strong></p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>设置成功</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>负数</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>设置失败</p>
</td>
</tr>
</tbody>
</table>

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
if (ret != 0) {
    HDF_LOGE("HdmiSetHdrAttribute failed.");
}
```

### 其他可选设置<a name="section9"></a>

#### 设置HDMI声音图像消隐

```c
int32_t HdmiAvmuteSet(DevHandle handle, bool enable);
```

**表 8**  HdmiAvmuteSet参数和返回值描述

<a name="table8"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="50%"><p><strong>参数</strong></p>
</th>
<th class="cellrowborder" valign="top" width="50%"><p><strong>参数描述</strong></p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="50%"><p>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>HDMI控制器句柄</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>enable</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>使能/去使能avmute</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p><strong>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p><strong>返回值描述</strong></p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>设置成功</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>负数</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>设置失败</p>
</td>
</tr>
</tbody>
</table>

设置声音图像消隐示例：

```c
int32_t ret;

ret = HdmiAvmuteSet(hdmiHandle, true);
if (ret != 0) {
    HDF_LOGE("HdmiAvmuteSet failed.");
}
```

#### 设置色彩深度

```c
int32_t HdmiDeepColorSet(DevHandle handle, enum HdmiDeepColor color);
```

**表 9**  HdmiDeepColorSet参数和返回值描述

<a name="table9"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="50%"><p><strong>参数</strong></p>
</th>
<th class="cellrowborder" valign="top" width="50%"><p><strong>参数描述</strong></p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="50%"><p>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>HDMI控制器句柄</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>color</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>色彩深度</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p><strong>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p><strong>返回值描述</strong></p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>设置成功</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>负数</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>设置失败</p>
</td>
</tr>
</tbody>
</table>

设置色彩深度示例：

```c
int32_t ret;

ret = HdmiDeepColorSet(handle, HDMI_DEEP_COLOR_48BITS);
if (ret != 0) {
    HDF_LOGE("HdmiDeepColorSet failed.");
}
```

#### 获取色彩深度

```c
int32_t HdmiDeepColorGet(DevHandle handle, enum HdmiDeepColor *color);
```

**表 10**  HdmiDeepColorGet参数和返回值描述

<a name="table10"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="50%"><p><strong>参数</strong></p>
</th>
<th class="cellrowborder" valign="top" width="50%"><p><strong>参数描述</strong></p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="50%"><p>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>HDMI控制器句柄</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>color</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>色彩深度</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p><strong>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p><strong>返回值描述</strong></p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>获取成功</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>负数</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>获取失败</p>
</td>
</tr>
</tbody>
</table>

获取色彩深度示例：

```c
enum HdmiDeepColor color;
int32_t ret;

ret = HdmiDeepColorGet(handle, &color);
if (ret != 0) {
    HDF_LOGE("HdmiDeepColorGet failed.");
}
```

### 启动HDMI传输<a name="section10"></a>

```c
int32_t HdmiStart(DevHandle handle);
```

**表 11**  HdmiStart参数和返回值描述

<a name="table11"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="50%"><p><strong>参数</strong></p>
</th>
<th class="cellrowborder" valign="top" width="50%"><p><strong>参数描述</strong></p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="50%"><p>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>HDMI控制器句柄</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p><strong>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p><strong>返回值描述</strong></p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>启动成功</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>负数</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>启动失败</p>
</td>
</tr>
</tbody>
</table>

启动HDMI传输示例：

```c
int32_t ret;

ret = HdmiStart(hdmiHandle);
if (ret != 0) {
    HDF_LOGE("start transmission failed.");
}
```

### 停止HDMI传输<a name="section11"></a>

```c
int32_t HdmiStop(DevHandle handle);
```

**表 12**  HdmiStop参数和返回值描述

<a name="table12"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="50%"><p><strong>参数</strong></p>
</th>
<th class="cellrowborder" valign="top" width="50%"><p><strong>参数描述</strong></p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="50%"><p>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>HDMI控制器句柄</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p><strong>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p><strong>返回值描述</strong></p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>停止成功</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>负数</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>停止失败</p>
</td>
</tr>
</tbody>
</table>

停止HDMI传输示例：

```c
int32_t ret;

ret = HdmiStop(hdmiHandle);
if (ret != 0) {
    HDF_LOGE("stop transmission failed.");
}
```

### 注销热插拔检测回调函数<a name="section12"></a>

```c
int32_t HdmiUnregisterHpdCallbackFunc(DevHandle handle);
```

**表 13**  HdmiUnregisterHpdCallbackFunc参数和返回值描述

<a name="table13"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="50%"><p><strong>参数</strong></p>
</th>
<th class="cellrowborder" valign="top" width="50%"><p><strong>参数描述</strong></p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="50%"><p>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>HDMI控制器句柄</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p><strong>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p><strong>返回值描述</strong></p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>注销成功</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>负数</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>注销失败</p>
</td>
</tr>
</tbody>
</table>

注销热插拔检测回调函数示例：

```c
int32_t ret;

ret = HdmiUnregisterHpdCallbackFunc(hdmiHandle);
if (ret != 0) {
    HDF_LOGE("unregister failed.");
}
```

### 关闭HDMI控制器<a name="section13"></a>

```c
void HdmiClose(DevHandle handle);
```

**表 14**  HdmiClose参数和返回值描述

<a name="table14"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="50%"><p><strong>参数</strong></p>
</th>
<th class="cellrowborder" valign="top" width="50%"><p><strong>参数描述</strong></p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="50%"><p>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>HDMI控制器句柄</p>
</td>
</tr>
</tbody>
</table>

关闭HDMI控制器示例：

```c
HdmiClose(hdmiHandle);
```

## 使用实例<a name="section14"></a>

本例程以操作开发板上的HDMI设备为例，详细展示HDMI接口的完整使用流程。

本例拟在Hi3516DV300开发板上对虚拟驱动进行简单的传输操作：

-   SOC：hi3516dv300。

-   HDMI控制器：使用0号HDMI控制器。


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
        HDF_LOGD("HdmiHpdHandle: hot unplog");
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