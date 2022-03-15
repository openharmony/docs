# HDMI<a name="1"></a>

## Overview<a name="section1"></a>

High-Definition Multimedia Interface (HDMI) is an audio/video transmission protocol released by Hitachi, Panasonic, Philips, Silicon Image, Sony, Thomson, and Toshiba.

HDMI works in master/slave mode and usually has a source and a sink.

The HDMI APIs provide a set of common functions for HDMI transmission, including:

- Opening and closing an HDMI controller
- Starting and stopping HDMI transmission
- Setting audio, video, and High Dynamic Range (HDR) attributes, color depth, and AV mute
- Reading the raw Extended Display Identification Data (EDID) from a sink
- Registering and unregistering a callback for HDMI hot plug detect (HPD) 

[Figure 1](#fig1) shows the HDMI physical connection.

 **Figure 1** HDMI physical connection<a name="fig1"></a>

 ![](figures/HDMI_physical_connection.png "HDMI_physical_connection")

## Available APIs<a name="section2"></a>

**Table 1** HDMI driver APIs

<a name="table1"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="18.63%"><p>Category</p>
</th>
<th class="cellrowborder" valign="top" width="28.03%"><p>API</p>
</th>
<th class="cellrowborder" valign="top" width="53.339999999999996%"><p>Description</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" bgcolor="#ffffff" rowspan="2" valign="top" width="18.63%"><p>Managing HDMI controllers</p>
</td>
<td class="cellrowborder" valign="top" width="28.03%"><p>HdmiOpen</p>
</td>
<td class="cellrowborder" valign="top" width="53.339999999999996%">Opens an HDMI controller.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top"><p>HdmiClose</p>
</td>
<td class="cellrowborder" valign="top"><p>Closes an HDMI controller.</p>
</td>
</tr>
<tr><td class="cellrowborder" bgcolor="#ffffff" rowspan="2" valign="top" width="18.63%"><p>Starting or stopping HDMI transmission</p>
</td>
<td class="cellrowborder" valign="top" width="28.03%"><p>HdmiStart</p>
</td>
<td class="cellrowborder" valign="top" width="53.339999999999996%">Starts HDMI transmission.</p>
</td>
</tr>
<tr id="row5632152611414"><td class="cellrowborder" valign="top"><p>HdmiStop</p>
</td>
<td class="cellrowborder" valign="top"><p>Stops HDMI transmission.</p>
</td>
</tr>
<tr><td class="cellrowborder" bgcolor="#ffffff" rowspan="6" valign="top" width="18.63%"><p>Setting an HDMI controller</p>
</td>
<td class="cellrowborder" valign="top" width="28.03%"><p>HdmiAvmuteSet</p>
</td>
<td class="cellrowborder" valign="top" width="53.339999999999996%">Sets the AV mute feature.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top"><p>HdmiDeepColorSet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p>Sets the color depth.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top"><p>HdmiDeepColorGet</p>
</td>
<td class="cellrowborder" valign="top"><p>Obtains the color depth.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top"><p>HdmiSetVideoAttribute</p>
</td>
<td class="cellrowborder" valign="top"><p>Sets video attributes.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top"><p>HdmiSetAudioAttribute</p>
</td>
<td class="cellrowborder" valign="top"><p>Sets audio attributes.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top"><p>HdmiSetHdrAttribute</p>
</td>
<td class="cellrowborder" valign="top"><p>Sets HDR attributes.</p>
</td>
</tr>
<tr><td class="cellrowborder" bgcolor="#ffffff" valign="top" width="18.63%"><p>Reading EDID</p>
</td>
<td class="cellrowborder" valign="top" width="28.03%"><p>HdmiReadSinkEdid</p>
</td>
<td class="cellrowborder" valign="top" width="53.339999999999996%">Reads the raw EDID from a sink.</p>
</td>
</tr>
<tr><td class="cellrowborder" bgcolor="#ffffff" rowspan="2" valign="top" width="18.63%"><p>Registering or unregistering a callback for HDMI HPD</p>
</td>
<td class="cellrowborder" valign="top" width="28.03%"><p>HdmiRegisterHpdCallbackFunc</p>
</td>
<td class="cellrowborder" valign="top" width="53.339999999999996%">Registers a callback for HDMI HPD.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top"><p>HdmiUnregisterHpdCallbackFunc</p>
</td>
<td class="cellrowborder" valign="top"><p>Unregisters the callback for HDMI HPD.</p>
</td>
</tr>
</tbody>
</table>

## Usage Guidelines<a name="section3"></a>

### How to Use<a name="section4"></a>

[Figure 2](#fig2) shows how HDMI works.

**Figure 2** How HDMI works<a name="fig2"></a>

![](figures/HDMI_usage_flowchart.png "HDMI_usage_flowchart")

### Opening an HDMI Controller<a name="section5"></a>

Before HDMI communication, call **HdmiOpen** to open an HDMI controller.

```c
DevHandle HdmiOpen(int16_t number);
```

**Table 2** Description of HdmiOpen

<a name="table2"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="20.66%"><p> Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="79.34%"><p><strong>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="20.66%"><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="79.34%"><p>HDMI controller ID.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.66%"><p><strong>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="79.34%"><p><strong>Description</strong></p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.66%"><p>NULL</p>
</td>
<td class="cellrowborder" valign="top" width="79.34%"><p>Failed to open the HDMI controller.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.66%"><p>Controller handle</p>
</td>
<td class="cellrowborder" valign="top" width="79.34%"><p>Handle of the HDMI controller opened.</p>
</td>
</tr>
</tbody>
</table>

For example, the system has two HDMI controllers, numbered 0 and 1. Open controller 0. 

```c
DevHandle hdmiHandle = NULL; /* HDMI controller handle /

/* Open HDMI controller 0. */
hdmiHandle = HdmiOpen(0);
if (hdmiHandle == NULL) {
    HDF_LOGE("HdmiOpen: failed\n");
    return;
}
```

### Registering a Callback for HPD<a name="section6"></a>

```c
int32_t HdmiRegisterHpdCallbackFunc(DevHandle handle, struct HdmiHpdCallbackInfo *callback);
```

**Table 3** Description of HdmiRegisterHpdCallbackFunc

<a name="table3"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="50%"><p><strong> Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="50%"><p><strong>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="50%"><p>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>HDMI controller handle.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>callback</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>Pointer to the callback to be invoked to return the HPD result.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p><strong>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p><strong>Description</strong></p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>The callback is registered successfully.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>Negative number</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>Failed to register the callback.</p>
</td>
</tr>
</tbody>
</table>

The following is an example of registering a callback for HPD:

```c
/* Definition of the callback for HPD */
static void HdmiHpdHandle(void *data, bool hpd)
{
    if (data == NULL) {
    HDF_LOGE("priv data is NULL");
    return;
}

    if (hpd == true) {
        HDF_LOGD("HdmiHpdHandle: hot plug");
        /* Add related processing if required. */
    } else {
        HDF_LOGD("HdmiHpdHandle: hot unplog");
        /* Add related processing if required. */
    }
}

    /* Example of registering a callback for HPD */
    struct HdmiHpdCallbackInfo info = {0};
    info.data = handle;
    info.callbackFunc = HdmiHpdHandle;
    ret = HdmiRegisterHpdCallbackFunc(hdmiHandle, info);
    if (ret != 0) {
        HDF_LOGE("HdmiRegisterHpdCallbackFunc: Register failed.");
    }
```

### Reading the RAW EDID<a name="section7"></a>

```c
int32_t HdmiReadSinkEdid(DevHandle handle, uint8_t *buffer, uint32_t len);
```

**Table 4** Description of HdmiReadSinkEdid

<a name="table4"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="50%"><p><strong> Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="50%"><p><strong>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="50%"><p>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>HDMI controller handle.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>buffer</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>Pointer to the data buffer.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>len</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>Data length.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p><strong>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p><strong>Description</strong></p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>Positive integer</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>Raw EDID read.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>Negative number or **0**</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>Failed to read the EDID.</p>
</td>
</tr>
</tbody>
</table>

The following is an example of reading the raw EDID from a sink:

```c
int32_t len;
uint8_t edid[HDMI_EDID_MAX_LEN] = {0};

len = HdmiReadSinkEdid(hdmiHandle, edid, HDMI_EDID_MAX_LEN);
if (len <= 0) {
    HDF_LOGE("%s: HdmiReadSinkEdid failed len = %d.", __func__, len);
}
```

### Setting Video, Audio, and HDR Attributes<a name="section8"></a>

#### Setting Audio Attributes

```c
int32_t HdmiSetAudioAttribute(DevHandle handle, struct HdmiAudioAttr *attr);
```

**Table 5** Description of HdmiSetAudioAttribute

<a name="table5"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="50%"><p><strong> Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="50%"><p><strong>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="50%"><p>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>HDMI controller handle.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>attr</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>Pointer to the audio attributes.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p><strong>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p><strong>Description</strong></p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>The operation is successful.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>Negative number</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>The operation failed.</p>
</td>
</tr>
</tbody>
</table>

The following is an example of setting audio attributes:

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

#### Setting Video Attributes

```c
int32_t HdmiSetVideoAttribute(DevHandle handle, struct HdmiVideoAttr *attr);
```

**Table 6** Description of HdmiSetVideoAttribute

<a name="table6"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="50%"><p><strong> Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="50%"><p><strong>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="50%"><p>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>HDMI controller handle.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>attr</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>Pointer to the video attributes.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p><strong>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p><strong>Description</strong></p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>The operation is successful.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>Negative number</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>The operation failed.</p>
</td>
</tr>
</tbody>
</table>

The following is an example of setting video attributes:

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

#### Setting HDR Attributes

```c
int32_t HdmiSetHdrAttribute(DevHandle handle, struct HdmiHdrAttr *attr);
```

**Table 7** Description of HdmiSetHdrAttribute

<a name="table7"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="50%"><p><strong> Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="50%"><p><strong>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="50%"><p>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>HDMI controller handle.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>attr</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>Pointer to the HDR attributes.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p><strong>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p><strong>Description</strong></p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>The operation is successful.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>Negative number</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>The operation failed.</p>
</td>
</tr>
</tbody>
</table>

The following is an example of setting HDR attributes:

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

### Setting Other Attributes<a name="section9"></a>

#### Setting HDMI AV Mute

```c
int32_t HdmiAvmuteSet(DevHandle handle, bool enable);
```

**Table 8** Description of HdmiAvmuteSet

<a name="table8"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="50%"><p><strong> Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="50%"><p><strong>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="50%"><p>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>HDMI controller handle.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>enable</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>Whether the AV mute feature is enabled.
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p><strong>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p><strong>Description</strong></p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>The operation is successful.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>Negative number</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>The operation failed.</p>
</td>
</tr>
</tbody>
</table>

The following is an example of setting AV mute:

```c
int32_t ret;

ret = HdmiAvmuteSet(hdmiHandle, true);
if (ret != 0) {
    HDF_LOGE("HdmiAvmuteSet failed.");
}
```

#### Setting the Color Depth

```c
int32_t HdmiDeepColorSet(DevHandle handle, enum HdmiDeepColor color);
```

**Table 9** Description of HdmiDeepColorSet

<a name="table9"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="50%"><p><strong> Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="50%"><p><strong>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="50%"><p>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>HDMI controller handle.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>color</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>Color depth to set.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p><strong>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p><strong>Description</strong></p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>The operation is successful.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>Negative number</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>The operation failed.</p>
</td>
</tr>
</tbody>
</table>

The following is an example of setting the color depth:

```c
int32_t ret;

ret = HdmiDeepColorSet(handle, HDMI_DEEP_COLOR_48BITS);
if (ret != 0) {
    HDF_LOGE("HdmiDeepColorSet failed.");
}
```

#### Obtaining the Color Depth

```c
int32_t HdmiDeepColorGet(DevHandle handle, enum HdmiDeepColor *color);
```

**Table 10** Description of HdmiDeepColorGet

<a name="table10"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="50%"><p><strong> Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="50%"><p><strong>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="50%"><p>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>HDMI controller handle.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>color</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>Pointer to the color depth.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p><strong>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p><strong>Description</strong></p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>The operation is successful.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>Negative number</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>The operation failed.</p>
</td>
</tr>
</tbody>
</table>

The following is an example of obtaining the color depth:

```c
enum HdmiDeepColor color;
int32_t ret;

ret = HdmiDeepColorGet(handle, &color);
if (ret != 0) {
    HDF_LOGE("HdmiDeepColorGet failed.");
}
```

### Starting HDMI Transmission<a name="section10"></a>

```c
int32_t HdmiStart(DevHandle handle);
```

**Table 11** Description of HdmiStart

<a name="table11"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="50%"><p><strong> Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="50%"><p><strong>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="50%"><p>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>HDMI controller handle.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p><strong>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p><strong>Description</strong></p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>The operation is successful.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>Negative number</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>The operation failed.</p>
</td>
</tr>
</tbody>
</table>

The following is an example of starting HDMI transmission:

```c
int32_t ret;

ret = HdmiStart(hdmiHandle);
if (ret != 0) {
    HDF_LOGE("Failed to start transmission.");
}
```

### Stopping HDMI Transmission<a name="section11"></a>

```c
int32_t HdmiStop(DevHandle handle);
```

**Table 12** Description of HdmiStop

<a name="table12"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="50%"><p><strong> Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="50%"><p><strong>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="50%"><p>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>HDMI controller handle.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p><strong>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p><strong>Description</strong></p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>The operation is successful.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>Negative number</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>The operation failed.</p>
</td>
</tr>
</tbody>
</table>

The following is an example of stopping HDMI transmission:

```c
int32_t ret;

ret = HdmiStop(hdmiHandle);
if (ret != 0) {
    HDF_LOGE("Failed to stop transmission.");
}
```

### Unregistering the Callback for HPD<a name="section12"></a>

```c
int32_t HdmiUnregisterHpdCallbackFunc(DevHandle handle);
```

**Table 13** Description of HdmiUnregisterHpdCallbackFunc

<a name="table13"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="50%"><p><strong> Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="50%"><p><strong>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="50%"><p>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>HDMI controller handle.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p><strong>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p><strong>Description</strong></p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>The operation is successful.</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%"><p>Negative number</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>The operation failed.</p>
</td>
</tr>
</tbody>
</table>

The following is an example of unregistering the callback for HPD:

```c
int32_t ret;

ret = HdmiUnregisterHpdCallbackFunc(hdmiHandle);
if (ret != 0) {
    HDF_LOGE("unregister failed.");
}
```

### Closing an HDMI Controller<a name="section13"></a>

```c
void HdmiClose(DevHandle handle);
```

**Table 14** Description of HdmiClose

<a name="table14"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="50%"><p><strong> Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="50%"><p><strong>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="50%"><p>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p>HDMI controller handle.</p>
</td>
</tr>
</tbody>
</table>

The following is an example of closing an HDMI controller:

```c
HdmiClose(hdmiHandle);
```

## Example<a name="section14"></a>

This following example shows how to use HDMI APIs to manage an HDMI device on a Hi3516D V300 development board.

A virtual driver is used in this example. The hardware information is as follows:

-   SoC: Hi3516D V300

-   HDMI controller: HDMI controller 0


The sample code is as follows:

```c
#include "hdmi_if.h"          /* Header file for HDMI standard APIs */
#include "hdf_log.h"         /* Header file for log APIs */
#include "osal_time.h"       /* Header file for delay and sleep APIs */

/* Callback for hog plug detect */
static void HdmiHpdHandle(void *data, bool hpd)
{
    if (data == NULL) {
    HDF_LOGE("priv data is NULL");
    return;
    }

    if (hpd == true) {
        HDF_LOGD("HdmiHpdHandle: hot plug");
        /* Add related processing if required. */
    } else {
        HDF_LOGD("HdmiHpdHandle: hot unplog");
        /* Add related processing if required. */
    }
}

/* Set HDMI attributes. */
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

/* Main entry of HDMI routines */
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
