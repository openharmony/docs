# PrelaunchConfig


## 概述

预启动配置信息，用于[Prelaunch](interface_i_camera_host_v11.md#prelaunch)。

**起始版本：** 4.0

**相关模块：**[Camera](_camera_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| String [cameraId](#cameraid) | Camera ID，相机设备唯一标识。 | 
| struct [StreamInfo_V1_1](_stream_info___v1__1_v11.md)[] [streamInfos_V1_1](#streaminfos_v1_1) | 流预启动模式中使用的流信息，目前可以忽略。 | 
| unsigned char[] [setting](#setting) | 表示预启动配置信息。 | 


## 类成员变量说明


### cameraId

```
String PrelaunchConfig::cameraId
```

**描述**

Camera ID，相机设备唯一标识。


### setting

```
unsigned char [] PrelaunchConfig::setting
```

**描述**

表示预启动配置信息。


### streamInfos_V1_1

```
struct StreamInfo_V1_1 [] PrelaunchConfig::streamInfos_V1_1
```

**描述**

流预启动模式中使用的流信息，目前可以忽略。
