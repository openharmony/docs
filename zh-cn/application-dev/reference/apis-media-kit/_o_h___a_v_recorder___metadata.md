# OH_AVRecorder_Metadata


## 概述

设置元数据信息。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

**相关模块：**[AVRecorder](_a_v_recorder.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| char \*[genre](#genre) | 媒体资源的类型或体裁。 | 
| char \*[videoOrientation](#videoorientation) | 视频的旋转方向，单位为度。 | 
| [OH_AVRecorder_Location](_o_h___a_v_recorder___location.md) [location](#location) | 视频的地理位置信息。 | 
| [OH_AVRecorder_MetadataTemplate](_o_h___a_v_recorder___metadata_template.md) [customInfo](#custominfo) | 从 moov.meta.list 读取的自定义参数键值映射。 | 


## 成员变量说明


### genre

```
char *genre
```

**描述**

媒体资源的类型或体裁。


### videoOrientation

```
char *videoOrientation
```

**描述**

视频的旋转方向，单位为度。


### location

```
OH_AVRecorder_Location location
```

**描述**

视频的地理位置信息。


### customInfo

```
OH_AVRecorder_MetadataTemplate customInfo
```

**描述**

从 moov.meta.list 读取的自定义参数键值映射。
