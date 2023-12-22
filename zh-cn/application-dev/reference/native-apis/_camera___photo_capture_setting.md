# Camera_PhotoCaptureSetting


## 概述

要设置的拍照捕获选项。

**起始版本：** 11

**相关模块：**[OH_Camera](_o_h___camera.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [quality](#quality) | 拍照图像质量。 | 
| [rotation](#rotation) | 拍照旋转角度。 | 
| [location](#location) | 拍照位置。 | 
| [mirror](#mirror) | 设置镜像拍照功能开关，默认为false。 | 


## 结构体成员变量说明


### location

```
Camera_Location* Camera_PhotoCaptureSetting::location
```

**描述**

拍照位置。


### mirror

```
bool Camera_PhotoCaptureSetting::mirror
```

**描述**

设置镜像拍照功能开关，默认为false。


### quality

```
Camera_QualityLevel Camera_PhotoCaptureSetting::quality
```

**描述**

拍照图像质量。


### rotation

```
Camera_ImageRotation Camera_PhotoCaptureSetting::rotation
```

**描述**

拍照旋转角度。
