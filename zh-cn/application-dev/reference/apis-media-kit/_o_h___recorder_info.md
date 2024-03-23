# OH_RecorderInfo


## 概述

录制文件信息。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

**相关模块：**[AVScreenCapture](_a_v_screen_capture.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| char \* [url](#url) | 录制文件的URL。 | 
| uint32_t [urlLen](#urllen) | 录制文件的URL长度。 | 
| [OH_ContainerFormatType](_a_v_screen_capture.md#oh_containerformattype) [fileFormat](#fileformat) | 录制文件的格式。 | 


## 结构体成员变量说明


### fileFormat

```
OH_ContainerFormatType OH_RecorderInfo::fileFormat
```

**描述**

录制文件的格式。


### url

```
char* OH_RecorderInfo::url
```

**描述**

录制文件的URL。


### urlLen

```
uint32_t OH_RecorderInfo::urlLen
```

**描述**

录制文件的URL长度。
