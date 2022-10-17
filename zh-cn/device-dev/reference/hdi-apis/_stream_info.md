# StreamInfo


## **概述**

流信息，用于创建流时传入相关的配置参数。

**相关模块:**

[Camera](camera.md)


## **汇总**


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [streamId_](#streamid) | 流的ID，用于在设备内唯一标识一条流。 | 
| [width_](#width) | 图像宽度。 | 
| [height_](#height) | 图像高度。 | 
| [format_](#format) | 图像格式。 | 
| [dataspace_](#dataspace) | 图像颜色空间。 | 
| [intent_](#intent) | 流类型。 | 
| [tunneledMode_](#tunneledmode) | 隧道模式，值为true时开启，false关闭。 | 
| [bufferQueue_](#bufferqueue) | 图形提供的生产者句柄。 | 
| [minFrameDuration_](#minframeduration) | 最小帧间隔。 | 
| [encodeType_](#encodetype) | 编码类型。 | 


## **类成员变量说明**


### bufferQueue_

  
```
BufferProducerSequenceable StreamInfo::bufferQueue_
```

**描述：**

图形提供的生产者句柄。


### dataspace_

  
```
int StreamInfo::dataspace_
```

**描述：**

图像颜色空间。


### encodeType_

  
```
enum EncodeType StreamInfo::encodeType_
```

**描述：**

编码类型。


### format_

  
```
int StreamInfo::format_
```

**描述：**

图像格式。


### height_

  
```
int StreamInfo::height_
```

**描述：**

图像高度。


### intent_

  
```
enum StreamIntent StreamInfo::intent_
```

**描述：**

流类型。


### minFrameDuration_

  
```
int StreamInfo::minFrameDuration_
```

**描述：**

最小帧间隔。


### streamId_

  
```
int StreamInfo::streamId_
```

**描述：**

流的ID，用于在设备内唯一标识一条流。


### tunneledMode_

  
```
boolean StreamInfo::tunneledMode_
```

**描述：**

隧道模式，值为true时开启，false关闭。 开启隧道模式后，HAL不直接和上层交互，通过图形提供的生产者句柄来传递帧数据， 对于一些IOT设备，可能不需要或者不支持预览流的图像数据缓存流转，此时需要关闭隧道模式。


### width_

  
```
int StreamInfo::width_
```

**描述：**

图像宽度。
