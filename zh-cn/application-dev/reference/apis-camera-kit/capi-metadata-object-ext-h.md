# metadata_object_ext.h
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->

## 概述

声明元数据对象扩展概念。

**引用文件：** <ohcamera/metadata_object_ext.h>

**库：** libohcamera.so

**系统能力：** SystemCapability.Multimedia.Camera.Core

**起始版本：** 26.0.0

**相关模块：** [OH_Camera](capi-oh-camera.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_Camera_MetadataObjectExt](capi-oh-camera-oh-camera-metadataobjectext.md) | OH_Camera_MetadataObjectExt | 元数据对象扩展结构体。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [Camera_ErrorCode OH_MetadataObjectExt_GetMetadataObjectType(const OH_Camera_MetadataObjectExt* metadataObjectExt, Camera_MetadataObjectType* type)](#oh_metadataobjectext_getmetadataobjecttype) | 获取元数据对象类型。 |
| [Camera_ErrorCode OH_MetadataObjectExt_GetTimestamp(const OH_Camera_MetadataObjectExt* metadataObjectExt, int64_t* timestamp)](#oh_metadataobjectext_gettimestamp) | 获取元数据对象的时间戳。 |
| [Camera_ErrorCode OH_MetadataObjectExt_GetBoundingBox(const OH_Camera_MetadataObjectExt* metadataObjectExt, OH_Camera_Rect_Ext* boundingBox)](#oh_metadataobjectext_getboundingbox) | 获取元数据对象的边界框。 |
| [Camera_ErrorCode OH_MetadataObjectExt_GetPitchAngle(const OH_Camera_MetadataObjectExt* metadataObjectExt, float* pitchAngle)](#oh_metadataobjectext_getpitchangle) | 获取元数据对象（如人脸）的俯仰角度。取值范围为[-90, 90]，以向下为正方向。 |
| [Camera_ErrorCode OH_MetadataObjectExt_GetYawAngle(const OH_Camera_MetadataObjectExt* metadataObjectExt, float* yawAngle)](#oh_metadataobjectext_getyawangle) | 获取元数据对象（如人脸）的左右旋转角度。取值范围为[-90, 90]，以向右为正方向。 |
| [Camera_ErrorCode OH_MetadataObjectExt_GetRollAngle(const OH_Camera_MetadataObjectExt* metadataObjectExt, float* rollAngle)](#oh_metadataobjectext_getrollangle) | 获取元数据对象（如人脸）的平面内旋转角度。取值范围为[-180, 180]，以顺时针方向为正方向。 |
| [Camera_ErrorCode OH_MetadataObjectExt_GetLeftEyeBoundingBox(const OH_Camera_MetadataObjectExt* metadataObjectExt, OH_Camera_Rect_Ext* boundingBox)](#oh_metadataobjectext_getlefteyeboundingbox) | 获取元数据对象（如人脸）的左眼边界框。 |
| [Camera_ErrorCode OH_MetadataObjectExt_GetRightEyeBoundingBox(const OH_Camera_MetadataObjectExt* metadataObjectExt, OH_Camera_Rect_Ext* boundingBox)](#oh_metadataobjectext_getrighteyeboundingbox) | 获取元数据对象（如人脸）的右眼边界框。 |
| [Camera_ErrorCode OH_MetadataObjectExt_GetEmotion(const OH_Camera_MetadataObjectExt* metadataObjectExt, OH_Camera_MetadataObjectEmotion* emotion)](#oh_metadataobjectext_getemotion) | 获取元数据对象（如人脸）的情绪类型。 |
| [void OH_MetadataObjectExt_Destroy(OH_Camera_MetadataObjectExt** metadataObjectExt, uint32_t objectCount)](#oh_metadataobjectext_destroy) | 销毁OH_Camera_MetadataObjectExt实例数组。 |
| [bool OH_MetadataObjectExt_IsLockFocusTracked(const OH_Camera_MetadataObjectExt* metadataObjectExt)](#oh_metadataobjectext_islockfocustracked) |  查询焦点是否已锁定跟踪。 |

## 函数说明

### OH_MetadataObjectExt_GetMetadataObjectType()

```c
Camera_ErrorCode OH_MetadataObjectExt_GetMetadataObjectType(const OH_Camera_MetadataObjectExt* metadataObjectExt, Camera_MetadataObjectType* type)
```

**描述**

获取元数据对象类型。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const[OH_Camera_MetadataObjectExt](capi-oh-camera-oh-camera-metadataobjectext.md)* metadataObjectExt | OH_Camera_MetadataObjectExt实例的指针。 |
| [Camera_MetadataObjectType](capi-camera-h.md#camera_metadataobjecttype)* type | 元数据对象类型的指针，是一个Camera_MetadataObjectType实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：操作成功。<br>         CAMERA_INVALID_ARGUMENT：参数缺失或参数类型错误。 |

### OH_MetadataObjectExt_GetTimestamp()

```c
Camera_ErrorCode OH_MetadataObjectExt_GetTimestamp(const OH_Camera_MetadataObjectExt* metadataObjectExt, int64_t* timestamp)
```

**描述**

获取元数据对象的时间戳。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const[OH_Camera_MetadataObjectExt](capi-oh-camera-oh-camera-metadataobjectext.md)* metadataObjectExt | OH_Camera_MetadataObjectExt实例的指针。 |
| int64_t* timestamp | 存储时间戳的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：操作成功。<br>         CAMERA_INVALID_ARGUMENT：参数缺失或参数类型错误。 |

### OH_MetadataObjectExt_GetBoundingBox()

```c
Camera_ErrorCode OH_MetadataObjectExt_GetBoundingBox(const OH_Camera_MetadataObjectExt* metadataObjectExt, OH_Camera_Rect_Ext* boundingBox)
```

**描述**

获取元数据对象的边界框。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const[OH_Camera_MetadataObjectExt](capi-oh-camera-oh-camera-metadataobjectext.md)* metadataObjectExt | OH_Camera_MetadataObjectExt实例的指针。 |
| [OH_Camera_Rect_Ext](capi-oh-camera-oh-camera-rect-ext.md)* boundingBox | 元数据对象边界框的指针，是一个OH_Camera_Rect_Ext实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：操作成功。<br>         CAMERA_INVALID_ARGUMENT：参数缺失或参数类型错误。 |

### OH_MetadataObjectExt_GetPitchAngle()

```c
Camera_ErrorCode OH_MetadataObjectExt_GetPitchAngle(const OH_Camera_MetadataObjectExt* metadataObjectExt, float* pitchAngle)
```

**描述**

获取元数据对象（如人脸）的俯仰角度。取值范围为[-90, 90]，以向下为正方向。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const[OH_Camera_MetadataObjectExt](capi-oh-camera-oh-camera-metadataobjectext.md)* metadataObjectExt | OH_Camera_MetadataObjectExt实例的指针。 |
| float* pitchAngle | 存储俯仰角的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：操作成功。<br>         CAMERA_INVALID_ARGUMENT：参数缺失或参数类型错误。<br>         CAMERA_ERROR_OPTIONAL_PROPERTY_NOT_EXIST：可选属性不存在。 |

### OH_MetadataObjectExt_GetYawAngle()

```c
Camera_ErrorCode OH_MetadataObjectExt_GetYawAngle(const OH_Camera_MetadataObjectExt* metadataObjectExt, float* yawAngle)
```

**描述**

获取元数据对象（如人脸）的左右旋转角度。取值范围为[-90, 90]，以向右为正方向。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const[OH_Camera_MetadataObjectExt](capi-oh-camera-oh-camera-metadataobjectext.md)* metadataObjectExt | OH_Camera_MetadataObjectExt实例的指针。 |
| float* yawAngle | 存储左右旋转角度的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：操作成功。<br>         CAMERA_INVALID_ARGUMENT：参数缺失或参数类型错误。<br>         CAMERA_ERROR_OPTIONAL_PROPERTY_NOT_EXIST：可选属性不存在。 |

### OH_MetadataObjectExt_GetRollAngle()

```c
Camera_ErrorCode OH_MetadataObjectExt_GetRollAngle(const OH_Camera_MetadataObjectExt* metadataObjectExt, float* rollAngle)
```

**描述**

获取元数据对象（如人脸）的平面内旋转角度。取值范围为[-180, 180]，以顺时针方向为正方向。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const[OH_Camera_MetadataObjectExt](capi-oh-camera-oh-camera-metadataobjectext.md)* metadataObjectExt | OH_Camera_MetadataObjectExt实例的指针。 |
| float* rollAngle | 存储翻滚角的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：操作成功。<br>         CAMERA_INVALID_ARGUMENT：参数缺失或参数类型错误。<br>         CAMERA_ERROR_OPTIONAL_PROPERTY_NOT_EXIST：可选属性不存在。 |

### OH_MetadataObjectExt_GetLeftEyeBoundingBox()

```c
Camera_ErrorCode OH_MetadataObjectExt_GetLeftEyeBoundingBox(const OH_Camera_MetadataObjectExt* metadataObjectExt, OH_Camera_Rect_Ext* boundingBox)
```

**描述**

获取元数据对象（如人脸）的左眼边界框。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const[OH_Camera_MetadataObjectExt](capi-oh-camera-oh-camera-metadataobjectext.md)* metadataObjectExt | OH_Camera_MetadataObjectExt实例的指针。 |
| [OH_Camera_Rect_Ext](capi-oh-camera-oh-camera-rect-ext.md)* boundingBox | 元数据对象边界框的指针，是一个OH_Camera_Rect_Ext实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：操作成功。<br>         CAMERA_INVALID_ARGUMENT：参数缺失或参数类型错误。<br>         CAMERA_ERROR_OPTIONAL_PROPERTY_NOT_EXIST：可选属性不存在。 |

### OH_MetadataObjectExt_GetRightEyeBoundingBox()

```c
Camera_ErrorCode OH_MetadataObjectExt_GetRightEyeBoundingBox(const OH_Camera_MetadataObjectExt* metadataObjectExt, OH_Camera_Rect_Ext* boundingBox)
```

**描述**

获取元数据对象（如人脸）的右眼边界框。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const[OH_Camera_MetadataObjectExt](capi-oh-camera-oh-camera-metadataobjectext.md)* metadataObjectExt | OH_Camera_MetadataObjectExt实例的指针。 |
| [OH_Camera_Rect_Ext](capi-oh-camera-oh-camera-rect-ext.md)* boundingBox | 元数据对象边界框的指针，是一个OH_Camera_Rect_Ext实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：操作成功。<br>         CAMERA_INVALID_ARGUMENT：参数缺失或参数类型错误。<br>         CAMERA_ERROR_OPTIONAL_PROPERTY_NOT_EXIST：可选属性不存在。 |

### OH_MetadataObjectExt_GetEmotion()

```c
Camera_ErrorCode OH_MetadataObjectExt_GetEmotion(const OH_Camera_MetadataObjectExt* metadataObjectExt, OH_Camera_MetadataObjectEmotion* emotion)
```

**描述**

获取元数据对象（如人脸）的情绪类型。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const[OH_Camera_MetadataObjectExt](capi-oh-camera-oh-camera-metadataobjectext.md)* metadataObjectExt | OH_Camera_MetadataObjectExt实例的指针。 |
| [OH_Camera_MetadataObjectEmotion](capi-camera-h.md#oh_camera_metadataobjectemotion)* emotion | 存储情绪类型的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：操作成功。<br>         CAMERA_INVALID_ARGUMENT：参数缺失或参数类型错误。<br>         CAMERA_ERROR_OPTIONAL_PROPERTY_NOT_EXIST：可选属性不存在。 |

### OH_MetadataObjectExt_Destroy()

```c
void OH_MetadataObjectExt_Destroy(OH_Camera_MetadataObjectExt** metadataObjectExt, uint32_t objectCount)
```

**描述**

销毁OH_Camera_MetadataObjectExt实例数组。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Camera_MetadataObjectExt](capi-oh-camera-oh-camera-metadataobjectext.md)** metadataObjectExt | OH_Camera_MetadataObjectExt实例数组的指针。 |
| uint32_t objectCount | 要销毁的元数据对象数量。 |

### OH_MetadataObjectExt_IsLockFocusTracked()

```c
bool OH_MetadataObjectExt_IsLockFocusTracked(const OH_Camera_MetadataObjectExt* metadataObjectExt)
```

**描述**

查询焦点是否已锁定跟踪。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_Camera_MetadataObjectExt](capi-oh-camera-oh-camera-metadataobjectext.md)* metadataObjectExt | OH_Camera_MetadataObjectExt实例指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 焦点是否已锁定跟踪，返回true表示已锁定，返回false表示未锁定。 |
