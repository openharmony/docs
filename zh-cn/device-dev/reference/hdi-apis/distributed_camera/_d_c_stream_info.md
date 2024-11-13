# DCStreamInfo


## 概述

分布式相机内部流信息，用于创建流时传入相关的配置参数。

**起始版本：** 3.2

**相关模块：**[Camera](_distributed.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [streamId_](#streamid_) | 流的ID，用于在设备内唯一标识一条流。 | 
| int [width_](#width_) | 图像宽度。 | 
| int [height_](#height_) | 图像高度。 | 
| int [stride_](#stride_) | 图像步幅。 | 
| int [format_](#format_) | 图像格式。 | 
| int [dataspace_](#dataspace_) | 图像颜色空间。 | 
| enum [DCEncodeType](_distributed.md#dcencodetype)[encodeType_](#encodetype_) | 编码类型，具体类型查看[DCEncodeType](_distributed.md#dcencodetype)。 | 
| enum [DCStreamType](_distributed.md#dcstreamtype)[type_](#type_) | 流类型，具体类型查看[DCStreamType](_distributed.md#dcstreamtype)。 | 


## 类成员变量说明


### dataspace_

```
int DCStreamInfo::dataspace_
```

**描述**


图像颜色空间。


### encodeType_

```
enum DCEncodeType DCStreamInfo::encodeType_
```

**描述**


编码类型，具体类型查看[DCEncodeType](_distributed.md#dcencodetype)。


### format_

```
int DCStreamInfo::format_
```

**描述**


图像格式。


### height_

```
int DCStreamInfo::height_
```

**描述**


图像高度。


### streamId_

```
int DCStreamInfo::streamId_
```

**描述**


流的ID，用于在设备内唯一标识一条流。


### stride_

```
int DCStreamInfo::stride_
```

**描述**


图像步幅。


### type_

```
enum DCStreamType DCStreamInfo::type_
```

**描述**


流类型，具体类型查看[DCStreamType](_distributed.md#dcstreamtype)。


### width_

```
int DCStreamInfo::width_
```

**描述**


图像宽度。
