# libohcamera.so

> **注释**
>
> 自API版本11起，支持此模块的初始API。新添加的API将用上标标记，以指示其最早的API版本。

## 相关模块

```c++
#include "/multimedia/camera_framework/camera.h"
#include "/multimedia/camera_framework/camera_manager.h"
#include "/multimedia/camera_framework/camera_input.h"
#include "/multimedia/camera_framework/capture_session.h"
#include "/multimedia/camera_framework/metadata_output.h"
#include "/multimedia/camera_framework/preview_output.h"
#include "/multimedia/camera_framework/photo_output.h"
#include "/multimedia/camera_framework/video_output.h"
```

## 功能描述

### OH_Camera_GetCameraManager

```
Camera_ErrorCode OH_Camera_GetCameraManager(Camera_Manager** cameraManager);
```

创建CameraManager实例。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称         | 类型                                   | 强制性| 描述           |
| -------------- | --------------------------------------- | ----     | ----------------------|
| cameraManager  | [Camera_Manager**](#camera_manager)     | 是      | 相机管理器。       |

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400201         |  相机服务出现致命错误。                    |

### OH_Camera_DeleteCameraManager

```
Camera_ErrorCode OH_Camera_DeleteCameraManager(Camera_Manager* cameraManager);
```

删除CameraManager实例。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称         | 类型                                   | 强制性| 描述           |
| -------------- | --------------------------------------- | ----     | ----------------------|
| cameraManager  | [Camera_Manager**](#camera_manager)     | 是      | 相机管理器。      |

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400201         |  相机服务出现致命错误。                    |

### Camera_Status

```
typedef enum Camera_Status Camera_Status;
```

枚举相机状态。

**系统能力**: SystemCapability.Multimedia.Camera.Core

| 名称                    | Value  | 描述          |
| ------------------------- | ----   | -------------------  |
| CAMERA_STATUS_APPEAR      | 0      | 显示状态。       |
| CAMERA_STATUS_DISAPPEAR   | 1      | 消失状态。    |
| CAMERA_STATUS_AVAILABLE   | 2      | 可用状态。    |
| CAMERA_STATUS_UNAVAILABLE | 3      | 不可用状态。  |

### Camera_Profile

```
typedef struct Camera_Profile Camera_Profile;
```

相机流的配置文件。

**系统能力**: SystemCapability.Multimedia.Camera.Core

| 名称   | 类型                           | 强制性| 描述    |
| -------- | -----------------------------   |--------  | -------------  |
| format   | [Camera_Format](#camera_format) | 是      | 相机格式。 |
| size     | [Camera_Size](#camera_size)     | 是      | 图片大小。 |

### Camera_FrameRateRange

```
typedef struct Camera_FrameRateRange Camera_FrameRateRange;
```

帧速率范围。

**系统能力**: SystemCapability.Multimedia.Camera.Core

| 名称   | 类型                | 强制性| 描述      |
| -------- | -------------------- |----------| ---------------- |
| min      | uint32_t             | 是      | 最小帧速率。  |
| max      | uint32_t             | 是      | 最大帧速率。  |

### Camera_VideoProfile

```
typedef struct Camera_VideoProfile Camera_VideoProfile;
```

视频配置文件。

**系统能力**: SystemCapability.Multimedia.Camera.Core

| 名称         | 类型                                           | 强制性| 描述                                |
| -------------- | ------------------------------------------------| -------- |------------------------------------------- |
| format         | [Camera_Format](#camera_format)                 | 是      | 相机格式。                             |
| size           | [Camera_Size](#camera_size)                     | 是      | 图片大小。                             |
| range          | [Camera_FrameRateRange](#camera_frameraterange) | 是      | 帧速率，单位为fps（每秒帧数）。|

### Camera_OutputCapability

```
typedef struct Camera_OutputCapability Camera_OutputCapability;
```

相机输出能力。

**系统能力**: SystemCapability.Multimedia.Camera.Core

| 名称                        | 类型                                                    | 强制性| 描述                        |
| ----------------------------- | -------------------------------------------------------- | -------- |----------------------------------- |
| previewProfiles               | [Camera_Profile**](#camera_profile)                      | 是      | 预览配置文件列表。             |
| previewProfilesSize           | uint32_t                                                 | 是      | 预览配置文件列表的大小。     |
| photoProfiles                 | [Camera_Profile**](#camera_profile)                      | 是      | 照片配置文件列表。               |
| photoProfilesSize             | uint32_t                                                 | 是      | 照片配置文件列表的大小。       |
| videoProfiles                 | [Camera_VideoProfile**](#camera_videoprofile)            | 是      | 视频配置文件列表。               |
| videoProfilesSize             | uint32_t                                                 | 是      | 视频配置文件列表的大小。       |
| supportedMetadataObjectTypes  | [Camera_MetadataObjectType**](#camera_metadataobjecttype)| 是      | 元数据对象类型列表。        |
| metadataProfilesSize          | uint32_t                                                 | 是      | 元数据对象类型列表的大小。|

### Camera_ErrorCode

```
typedef enum Camera_ErrorCode Camera_ErrorCode;
```

相机错误代码的枚举。

**系统能力**: SystemCapability.Multimedia.Camera.Core

| 名称                         | Value      | 描述                                     |
| -------------------------      | --------   | --------------------------------------------    |
| CAMERA_OK                      | 0          | 相机结果正常。                            |
| CAMERA_INVALID_ARGUMENT        | 7400101    | 参数丢失或参数类型不准确。  |
| CAMERA_OPERATION_NOT_ALLOWED   | 7400102    | 操作不允许。                          |
| CAMERA_SESSION_NOT_CONFIG      | 7400103    | 会话未配置。                             |
| CAMERA_SESSION_NOT_RUNNING     | 7400104    | 会话未运行。                            |
| CAMERA_SESSION_CONFIG_LOCKED   | 7400105    | 会话配置已锁定。                          |
| CAMERA_DEVICE_SETTING_LOCKED   | 7400106    | 设备设置已锁定。                         |
| CAMERA_CONFLICT_CAMERA         | 7400107    | 因冲突无法使用相机。           |
| CAMERA_DEVICE_DISABLED         | 7400108    | 由于安全原因，相机已禁用。       |
| CAMERA_DEVICE_PREEMPTED        | 7400109    | 因被抢占无法使用相机。          |
| CAMERA_SERVICE_FATAL_ERROR     | 7400201    | 相机服务致命错误。                     |

### Camera_Manager

```
typedef struct Camera_Manager Camera_Manager;
```

实现相机管理。在**Camera_Manager**中调用任何API之前，必须使用**OH_Camera_GetCameraManager**获取**Camera_Mnager**实例。

### OH_CameraManager_GetSupportedCameras

```
Camera_ErrorCode OH_CameraManager_GetSupportedCameras(Camera_Manager* cameraManager, Camera_Device** cameras, uint32_t* size);
```

获取支持的相机描述。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称         | 类型                               | 强制性| 描述                                                                              |
| -------------- | ----------------------------------- | ----     | ---------------------------------------------------------------------------------------- |
| cameraManager  | [Camera_Manager*](#camera_manager)  | 是      | 相机管理器。                                                                         |
| cameras        | [Camera_Device**](#camera_device)   | 是      | 相机设备对象。                                                                    |
| size           | uint32_t*                           | 是      | 如果方法调用成功，将填充支持的链接Camera_Device列表的大小。|

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |

### OH_CameraManager_DeleteSupportedCameras

```
Camera_ErrorCode OH_CameraManager_DeleteSupportedCameras(Camera_Manager* cameraManager,Camera_Device* cameras, uint32_t size);
```

删除支持的相机。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称         | 类型                               | 强制性| 描述                                                                              |
| -------------- | ----------------------------------- | ----     | ---------------------------------------------------------------------------------------- |
| cameraManager  | [Camera_Manager*](#camera_manager)  | 是      | 相机管理器。                                                                         |
| cameras        | [Camera_Device*](#camera_device)    | 是      | 相机设备对象。                                                                    |
| size           | uint32_t                            | 是      | 如果方法调用成功，将填充支持的链接Camera_Device列表的大小。|

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |

### OH_CameraManager_GetSupportedCameraOutputCapability

```
Camera_ErrorCode OH_CameraManager_GetSupportedCameraOutputCapability(Camera_Manager* cameraManager,const Camera_Device* camera, Camera_OutputCapability** cameraOutputCapability);
```

获取特定相机和特定模式支持的输出功能。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称                | 类型                                                | 强制性| 描述              |
| --------------------- | -----------------------------------------------------| -------- | -------------------------|
| cameraManager         | [Camera_Manager*](#camera_manager)                   | 是      | 相机管理器。         |
| camera                | [Camera_Device*](#camera_device)                     | 是      | 相机设备对象。    |
| cameraOutputCapability| [Camera_OutputCapability**](#camera_outputcapability)| 是      | 相机输出能力。|

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |

### OH_CameraManager_DeleteSupportedCameraOutputCapability

```
Camera_ErrorCode OH_CameraManager_DeleteSupportedCameraOutputCapability(Camera_Manager* cameraManager,Camera_OutputCapability* cameraOutputCapability);
```

删除支持的输出功能。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称                | 类型                                               | 强制性| 描述              |
| --------------------- | ----------------------------------------------------| ----     | -------------------------|
| cameraManager         | [Camera_Manager*](#camera_manager)                  | 是      | 相机管理器。         |
| cameraOutputCapability| [Camera_OutputCapability*](#camera_outputcapability)| 是      | 相机输出能力。|

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |

### OH_CameraManager_IsCameraMuted

```
Camera_ErrorCode OH_CameraManager_IsCameraMuted(Camera_Manager* cameraManager, bool* isCameraMuted);
```

判断相机是否静音。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称                | 类型                               | 强制性| 描述                                                        |
| --------------------- | ------------------------------------| ----     | ------------------------------------------------------------------ |
| cameraManager         | [Camera_Manager*](#camera_manager)  | 是      | 相机管理器。                                                   |
| isCameraMuted         | bool*                               | 是      | 如果方法调用成功，将判断相机是否静音。|

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |

### OH_CameraManager_CreateCaptureSession

```
Camera_ErrorCode OH_CameraManager_CreateCaptureSession(Camera_Manager* cameraManager,Camera_CaptureSession** captureSession);
```

创建捕获会话实例。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称         | 类型                                              | 强制性| 描述             |
| ---------------| ---------------------------------------------------| -------- | ----------------------- |
| cameraManager  | [Camera_Manager*](#camera_manager)                 | 是      | 相机管理器。        |
| captureSession | [Camera_CaptureSession**](#camera_capturesession)  | 是      | 捕获会话对象。 |

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400201         |  相机服务出现致命错误。                    |

### OH_CameraManager_CreateCameraInput

```
Camera_ErrorCode OH_CameraManager_CreateCameraInput(Camera_Manager* cameraManager,const Camera_Device* camera, Camera_Input** cameraInput);
```

创建相机输入实例。

**所需权限**: ohos.permission.CAMERA

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称         | 类型                               | 强制性| 描述           |
| -------------- | ----------------------------------- | ----     | ----------------------|
| cameraManager  | [Camera_Manager*](#camera_manager)  | 是      | 相机管理器。      |
| camera         | [Camera_Device*](#camera_device)    | 是      | 相机设备对象。 |
| cameraInput    | [Camera_Input**](#camera_input)     | 是      | 相机输入对象。  |

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400201         |  相机服务出现致命错误。                    |

### OH_CameraManager_CreateCameraInput_WithPositionAndType

```
Camera_ErrorCode OH_CameraManager_CreateCameraInput_WithPositionAndType(Camera_Manager* cameraManager,Camera_Position position, Camera_类型type, Camera_Input** cameraInput);
```

创建相机输入实例。

**所需权限**: ohos.permission.CAMERA

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称        | 类型                               | 强制性| 描述               |
| --------------| ----------------------------------- | ----     | --------------------------|
| cameraManager | [Camera_Manager*](#camera_manager)  | 是      | 相机管理器。          |
| position      | [Camera_Position](#camera_position) | 是      | 相机位置的枚举。 |
| type         | [Camera_Type](#camera_type)         | 是      | 相机类型的枚举。     |
| cameraInput   | [Camera_Input**](#camera_input)     | 是      | 相机输入对象。      |

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400201         |  相机服务出现致命错误。                    |

### OH_CameraManager_CreatePreviewOutput

```
Camera_ErrorCode OH_CameraManager_CreatePreviewOutput(Camera_Manager* cameraManager, const Camera_Profile* profile, const char* surfaceId, Camera_PreviewOutput** previewOutput);
```

创建预览输出实例。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称        | 类型                                          | 强制性| 描述                                  |
| --------------| ---------------------------------------------- | ----     | ---------------------------------------------|
| cameraManager | [Camera_Manager*](#camera_manager)             | 是      | 相机管理器。                             |
| profile       | [Camera_Profile*](#camera_profile)             | 是      | 相机流的配置文件。                  |
| surfaceId     | char*                                          | 是      | 用于创建Camera_PreviewOutput。|
| previewOutput | [Camera_PreviewOutput**](#camera_previewoutput)| 是      | 预览输出对象。                       |

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400201         |  相机服务出现致命错误。                    |

### OH_CameraManager_CreatePhotoOutput

```
Camera_ErrorCode OH_CameraManager_CreatePhotoOutput(Camera_Manager* cameraManager, const Camera_Profile* profile, const char* surfaceId, Camera_PhotoOutput** photoOutput);
```

创建一个照片输出实例。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称        | 类型                                      | 强制性| 描述                                  |
| --------------| ------------------------------------------ | ----     | ---------------------------------------------|
| cameraManager | [Camera_Manager*](#camera_manager)         | 是      | 相机管理器。                             |
| profile       | [Camera_Profile*](#camera_profile)         | 是      | 相机流的配置文件。                  |
| surfaceId     | char*                                      | 是      | 用于创建Camera_PreviewOutput。|
| photoOutput   | [Camera_PhotoOutput**](#camera_photooutput)| 是      | 照片输出对象。                         |

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400201         |  相机服务出现致命错误。                    |

### OH_CameraManager_CreateVideoOutput

```
Camera_ErrorCode OH_CameraManager_CreateVideoOutput(Camera_Manager* cameraManager, const Camera_VideoProfile* profile, const char* surfaceId, Camera_VideoOutput** videoOutput);
```

创建一个视频输出实例。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称        | 类型                                         | 强制性| 描述                                  |
| --------------| --------------------------------------------- | ----     | ---------------------------------------------|
| cameraManager | [Camera_Manager*](#camera_manager)            | 是      | 相机管理器。                             |
| profile       | [Camera_VideoProfile*](#camera_videoprofile)  | 是      | 视频配置文件。                               |
| surfaceId     | char*                                         | 是      | 用于创建Camera_PreviewOutput。|
| videoOutput   | [Camera_VideoOutput**](#camera_videooutput)   | 是      | 视频输出。                                |

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400201         |  相机服务出现致命错误。                    |

### OH_CameraManager_CreateMetadataOutput

```
Camera_ErrorCode OH_CameraManager_CreateMetadataOutput(Camera_Manager* cameraManager, const Camera_MetadataObjectType* profile, Camera_MetadataOutput** metadataOutput);
```

创建元数据输出实例。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称        | 类型                                                    | 强制性| 描述                    |
| --------------| -------------------------------------------------------- | ----     | -------------------------------|
| cameraManager | [Camera_Manager*](#camera_manager)                       | 是      | 相机管理器。               |
| profile       | [Camera_MetadataObjectType*](#camera_metadataobjecttype) | 是      | 元数据对象类型的枚举。 |
| metadataOutput| [Camera_MetadataOutput**](#camera_metadataoutput)        | 是      | 元数据输出对象。        |

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400201         |  相机服务出现致命错误。                    |

### OH_CameraManager_StatusCallback

```
typedef void (*OH_CameraManager_StatusCallback)(Camera_Manager* cameraManager, Camera_StatusInfo* status);
```

在CameraManager_Callbacks中调用的相机管理器状态回调。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称         | 类型                                              | 强制性| 描述         |
| ---------------| ---------------------------------------------------| ----     | --------------------|
| cameraManager  | [Camera_Manager*](#camera_manager)                 | 是      | 相机管理器。    |
| status         | [Camera_StatusInfo*](#camera_statusinfo)           | 是      | 相机状态信息。 |

### CameraManager_Callbacks

```
typedef struct CameraManager_Callbacks CameraManager_Callbacks;
```

相机设备状态的回调。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称         | 类型                                                                  | 强制性 | 描述                  |
| ------------   | -----------------------------------------------------------------------|-----------| --------------------------   |
| onCameraStatus | [OH_CameraManager_StatusCallback](#oh_cameramanager_statuscallback)    |  是      | 相机状态更改事件。  |

### OH_CameraManager_RegisterCallback

```
Camera_ErrorCode OH_CameraManager_RegisterCallback(Camera_Manager* cameraManager, CameraManager_Callbacks* callback);
```

注册相机状态更改事件回调。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称        | 类型                                                | 强制性| 描述                          |
| --------------| ---------------------------------------------------- | ----     | -------------------------------------|
| cameraManager | [Camera_Manager*](#camera_manager)                   | 是      | 相机管理器。                     |
| callback      | [CameraManager_Callbacks*](#cameramanager_callbacks) | 是      | 相机设备状态的回调。|

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |

### OH_CameraManager_UnregisterCallback

```
Camera_ErrorCode OH_CameraManager_UnregisterCallback(Camera_Manager* cameraManager, CameraManager_Callbacks* callback);
```

注销相机状态更改事件回调。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称        | 类型                                                | 强制性| 描述                          |
| --------------| ---------------------------------------------------- | ----     | -------------------------------------|
| cameraManager | [Camera_Manager*](#camera_manager)                   | 是      | 相机管理器。                     |
| callback      | [CameraManager_Callbacks*](#cameramanager_callbacks) | 是      | 相机设备状态的回调。|

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |

### Camera_StatusInfo

```
typedef struct Camera_StatusInfo Camera_StatusInfo;
```

相机状态信息。

**系统能力**: SystemCapability.Multimedia.Camera.Core

| 名称| 类型                             |     强制性   | 描述           |
| ------ | -----------------------------    | --------------  | ---------------       |
| camera | [Camera_Device*](#camera_device) |        是      | 相机实例。      |
| status | [Camera_Status](#camera_status)  |        是      | 当前相机状态。|

### Camera_Position

```
typedef enum Camera_Position Camera_Position;
```

相机位置的枚举。

**系统能力**: SystemCapability.Multimedia.Camera.Core

| 名称                      | Value  | 描述         |
| --------------------------- | ---- | --------------------- |
| CAMERA_POSITION_UNSPECIFIED | 0    | 未指定位置。 |
| CAMERA_POSITION_BACK        | 1    | 后置。        |
| CAMERA_POSITION_FRONT       | 2    | 前置。       |

### Camera_Type

```
typedef enum Camera_Type Camera_Type;
```

相机类型的枚举。

**系统能力**: SystemCapability.Multimedia.Camera.Core

| 名称                  | Value  | 描述        |
| ----------------------- | ---- | -------------------- |
| CAMERA_TYPE_DEFAULT     | 0    | 默认相机类型。 |
| CAMERA_TYPE_WIDE_ANGLE  | 1    | 宽相机。         |
| CAMERA_TYPE_ULTRA_WIDE  | 2    | 超宽相机。   |
| CAMERA_TYPE_TELEPHOTO   | 3    | 电话相机。    |
| CAMERA_TYPE_TRUE_DEPTH  | 4    | 深度相机。   |

### Camera_Connection

```
typedef enum Camera_Connection Camera_Connection;
```

相机连接类型的枚举。

**系统能力**: SystemCapability.Multimedia.Camera.Core

| 名称                       | Value  | 描述              |
| ---------------------------- | ---- | -------------------------- |
| CAMERA_CONNECTION_BUILT_IN   | 0    | 内置相机。           |
| CAMERA_CONNECTION_USB_PLUGIN | 1    | 使用USB连接的相机。|
| CAMERA_CONNECTION_REMOTE     | 2    | 远程相机。             |

### Camera_Device

```
typedef struct Camera_Device Camera_Device;
```

相机设备对象。

**系统能力**: SystemCapability.Multimedia.Camera.Core

| 名称         | 类型                                   | 强制性| 描述                      |
| -------------- | ---------------------------------       | ----     | -------------------------------- |
| cameraId       | char*                                   | 是      | 相机id属性。             |
| cameraPosition | [Camera_Position](#camera_position)     | 是      | 相机位置属性。       |
| camera类型    | [Camera_Type](#camera_type)             | 是      | 相机类型。                     |
| connection类型| [Camera_Connection](#camera_connection) | 是      | 相机连接类型属性。|

### Camera_Size

```
typedef struct Camera_Size Camera_Size;
```

大小参数。

**系统能力**: SystemCapability.Multimedia.Camera.Core

| 名称 | 类型    | 强制性| 描述  |
| ------ | ------   | -------- | ------       |
| width  | uint32_t | 是      | 宽度。       |
| height | uint32_t | 是      | 高度。      |

### Camera_Point

```
typedef struct Camera_Point Camera_Point;
```

点参数。

**系统能力**: SystemCapability.Multimedia.Camera.Core

| 名称 | 类型   | 强制性  | 描述     |
| ------ | ------  | --------   | ------------    |
| x      | int32_t | 是        | X坐标。  |
| y      | int32_t | 是        | Y坐标。  |

### Camera_Format

```
typedef enum Camera_Format Camera_Format;
```

相机格式类型的枚举。

**系统能力**: SystemCapability.Multimedia.Camera.Core

| 名称                  | Value     | 描述       |
| ----------------------- | --------- | ----------------- |
| CAMERA_FORMAT_RGBA_8888 | 3         | RGBA 8888格式。 |
| CAMERA_FORMAT_YUV_420_SP| 1003      | YUV 420格式。   |
| CAMERA_FORMAT_JPEG      | 2000      | JPEG格式。     |

### Camera_Input

提供**[Camera_CaptureSession](#camera_capturesession)**中使用的相机信息。

### OH_CameraInput_Open

```
Camera_ErrorCode OH_CameraInput_Open(Camera_Input* cameraInput);
```

打开相机。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称       | 类型                          | 强制性| 描述            |
| ------------ | ----------------------------   | ----     | --------------------   |
| cameraInput  | [Camera_Input*](#camera_input) | 是      | 相机输入对象。   |

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -------------------------------------------------- |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400107         |  因冲突无法使用相机。          |
| 7400108         |  由于安全原因，相机已禁用。      |
| 7400201         |  相机服务出现致命错误。                    |

### OH_CameraInput_Close

```
Camera_ErrorCode OH_CameraInput_Close(Camera_Input* cameraInput);
```

关闭相机。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称       | 类型                          | 强制性| 描述            |
| ------------ | ----------------------------   | ----     | --------------------   |
| cameraInput  | [Camera_Input*](#camera_input) | 是      | 相机输入对象。   |

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -------------------------------------------------- |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400201         |  相机服务出现致命错误。                    |

### OH_CameraInput_Release

```
Camera_ErrorCode OH_CameraInput_Release(Camera_Input* cameraInput);
```

释放相机输入实例。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称       | 类型                          | 强制性| 描述            |
| ------------ | ----------------------------   | ----     | --------------------   |
| cameraInput  | [Camera_Input*](#camera_input) | 是      | 相机输入对象。   |

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -------------------------------------------------- |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400201         |  相机服务出现致命错误。                    |

### OH_CameraInput_OnError

```
typedef void (*OH_CameraInput_OnError)(const Camera_Input* cameraInput, Camera_ErrorCode errorCode);
```

在CameraInput_Callbacks中调用的相机输入错误回调。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称       | 类型                                  | 强制性| 描述                   |
| ------------ | ------------------------------------   | ----     | ---------------------------   |
| cameraInput  | [Camera_Input*](#camera_input)         | 是      | 相机输入对象。          |
| errorCode    | [Camera_ErrorCode](#camera_errorcode)  | 是      | 相机错误代码的枚举。   |

### CameraInput_Callbacks

```
typedef struct CameraInput_Callbacks CameraInput_Callbacks;
```

相机设备状态的回调。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称  | 类型                                               | 强制性 | 描述                 |
| --------| ----------------------------------------------------|-----------| -------------------------   |
| onError | [OH_CameraInput_OnError](#oh_camerainput_onerror)   |  是      | 摄像机错误代码的枚举。   |

### OH_CameraInput_RegisterCallback

```
Camera_ErrorCode OH_CameraInput_RegisterCallback(Camera_Input* cameraInput, CameraInput_Callbacks* callback);
```

注册相机状态更改事件回调。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称        | 类型                                            | 强制性| 描述                               |
| ------------- | ----------------------------------------------   | ----     | ---------------------------------------   |
| cameraInput   | [Camera_Input*](#camera_input)                   | 是      | 相机输入对象。                      |
| callback      | [CameraInput_Callbacks*](#camerainput_callbacks) | 是      | 相机输入错误事件的回调。 |

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |

### OH_CameraInput_UnregisterCallback

```
Camera_ErrorCode OH_CameraInput_UnregisterCallback(Camera_Input* cameraInput, CameraInput_Callbacks* callback);
```

注销相机输入更改事件回调。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称        | 类型                                            | 强制性| 描述                               |
| ------------- | ----------------------------------------------   | ----     | ---------------------------------------   |
| cameraInput   | [Camera_Input*](#camera_input)                   | 是      | 相机输入对象。                      |
| callback      | [CameraInput_Callbacks*](#camerainput_callbacks) | 是      | 相机输入错误事件的回调。 |

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |

### Camera_FlashMode

```
typedef enum Camera_FlashMode Camera_FlashMode;
```

闪光模式的枚举。

**系统能力**: SystemCapability.Multimedia.Camera.Core

| 名称                 | Value| 描述      |
| ---------------------- | ---- | ---------------- |
| FLASH_MODE_CLOSE       | 0    | 关闭模式。      |
| FLASH_MODE_OPEN        | 1    | 打开模式。       |
| FLASH_MODE_AUTO        | 2    | 自动模式。       |
| FLASH_MODE_ALWAYS_OPEN | 3    | 始终打开模式。|

### Camera_ExposureMode

```
typedef enum Camera_ExposureMode Camera_ExposureMode;
```

曝光模式的枚举。

**系统能力**: SystemCapability.Multimedia.Camera.Core

| 名称                        | Value| 描述                   |
| ----------------------------- | ---- | ----------------------------- |
| EXPOSURE_MODE_LOCKED          | 0    | 锁定曝光模式。           |
| EXPOSURE_MODE_AUTO            | 1    | 自动曝光模式。           |
| EXPOSURE_MODE_CONTINUOUS_AUTO | 2    | 连续自动曝光。|

### Camera_FocusMode

```
typedef enum Camera_FocusMode Camera_FocusMode;
```

聚焦模式的枚举。

**系统能力**: SystemCapability.Multimedia.Camera.Core

| 名称                     | Value| 描述           |
| -------------------------- | ---- | -----------------     |
| FOCUS_MODE_MANUAL          | 0    | 手动模式。          |
| FOCUS_MODE_CONTINUOUS_AUTO | 1    | 连续自动模式。 |
| FOCUS_MODE_AUTO            | 2    | 自动模式。            |
| FOCUS_MODE_LOCKED          | 3    | 锁定模式。          |

### Camera_FocusState

```
typedef enum Camera_FocusState Camera_FocusState;
```

聚焦状态的枚举。

**系统能力**: SystemCapability.Multimedia.Camera.Core

| 名称                | Value| 描述     |
| --------------------- | ---- | --------------- |
| FOCUS_STATE_SCAN      | 0    | 扫描状态。     |
| FOCUS_STATE_FOCUSED   | 1    | 聚焦状态。  |
| FOCUS_STATE_UNFOCUSED | 2    | 非聚焦状态。|

### Camera_VideoStabilizationMode

```
typedef enum Camera_VideoStabilizationMode Camera_VideoStabilizationMode;
```

视频防抖模式的枚举。

**系统能力**: SystemCapability.Multimedia.Camera.Core

| 名称                       | Value| 描述                                                            |
| ---------------------------- | ---- | ---------------------------------------------------------------------- |
| STABILIZATION_MODE_OFF       | 0    | 关闭视频防抖模式。                                           |
| STABILIZATION_MODE_LOW       | 1    | LOW模式提供基本的防抖效果。                          |
| STABILIZATION_MODE_MIDDLE    | 2    | MIDDLE模式意味着算法可以获得比LOW模式更好的效果。 |
| STABILIZATION_MODE_HIGH      | 3    | HIGH模式意味着算法可以获得比MIDDLE模式更好的效果。|
| STABILIZATION_MODE_AUTO      | 4    | HDF相机可以自动选择模式。                              |

### Camera_CaptureSession

实现拍摄会话。

### OH_CaptureSession_BeginConfig

```
Camera_ErrorCode OH_CaptureSession_BeginConfig(Camera_CaptureSession* session);
```

开始捕获会话配置。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称   | 类型                                            | 强制性| 描述            |
| -------- | --------------------                             | ----     | ---------------------- |
| session  | [Camera_CaptureSession*](#camera_capturesession) | 是      | 捕获会话对象。|

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                     |
| --------------- | ------------------------------------------------- |
| 0               |  方法调用成功。                     |
| 7400101         |  参数丢失或参数类型不准确的。|
| 7400105         |  会话配置已锁定。                        |

### OH_CaptureSession_CommitConfig

```
Camera_ErrorCode OH_CaptureSession_CommitConfig(Camera_CaptureSession* session);
```

提交捕获会话配置。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称   | 类型                                            | 强制性| 描述            |
| -------- | --------------------                             | ----     | --------------------   |
| session  | [Camera_CaptureSession*](#camera_capturesession) | 是      | 捕获会话对象。|

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                     |
| --------------- | ------------------------------------------------- |
| 0               |  方法调用成功。                     |
| 7400101         |  参数丢失或参数类型不准确的。|
| 7400102         |  操作不允许。                        |
| 7400201         |  相机服务出现致命错误。                   |

### OH_CaptureSession_AddInput

```
Camera_ErrorCode OH_CaptureSession_AddInput(Camera_CaptureSession* session, Camera_Input* cameraInput);
```

添加相机输入。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称      | 类型                                            | 强制性| 描述            |
| ----------- | ---------------------------------------          | ----     | ---------------------- |
| session     | [Camera_CaptureSession*](#camera_capturesession) | 是      | 捕获会话对象。|
| cameraInput | [Camera_Input*](#camera_input)                   | 是      | 相机输入对象。   |

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                     |
| --------------- | ------------------------------------------------- |
| 0               |  方法调用成功。                     |
| 7400101         |  参数丢失或参数类型不准确的。|
| 7400102         |  操作不允许。                        |

### OH_CaptureSession_RemoveInput

```
Camera_ErrorCode OH_CaptureSession_RemoveInput(Camera_CaptureSession* session, Camera_Input* cameraInput);
```

删除相机输入。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称      | 类型                                            | 强制性| 描述            |
| ----------- | ---------------------------------------          | ----     | ---------------------- |
| session     | [Camera_CaptureSession*](#camera_capturesession) | 是      | 捕获会话对象。|
| cameraInput | [Camera_Input*](#camera_input)                   | 是      | 相机输入对象。   |

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                     |
| --------------- | ------------------------------------------------- |
| 0               |  方法调用成功。                     |
| 7400101         |  参数丢失或参数类型不准确的。|
| 7400102         |  操作不允许。                        |

### OH_CaptureSession_AddPreviewOutput

```
Camera_ErrorCode OH_CaptureSession_AddPreviewOutput(Camera_CaptureSession* session,Camera_PreviewOutput* previewOutput);
```

添加预览输出。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称        | 类型                                            | 强制性| 描述            |
| -----------   | ---------------------------------------          | ----     | ---------------------- |
| session       | [Camera_CaptureSession*](#camera_capturesession) | 是      | 捕获会话对象。|
| previewOutput | [Camera_PreviewOutput*](#camera_previewoutput)   | 是      | 预览输出对象。 |

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                     |
| --------------- | ------------------------------------------------- |
| 0               |  方法调用成功。                     |
| 7400101         |  参数丢失或参数类型不准确的。|
| 7400102         |  操作不允许。                        |

### OH_CaptureSession_RemovePreviewOutput

```
Camera_ErrorCode OH_CaptureSession_RemovePreviewOutput(Camera_CaptureSession* session,Camera_PreviewOutput* previewOutput);
```

删除预览输出。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称        | 类型                                            | 强制性| 描述            |
| -----------   | ---------------------------------------          | ----     | ---------------------- |
| session       | [Camera_CaptureSession*](#camera_capturesession) | 是      | 捕获会话对象。|
| previewOutput | [Camera_PreviewOutput*](#camera_previewoutput)   | 是      | 预览输出对象。 |

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                     |
| --------------- | ------------------------------------------------- |
| 0               |  方法调用成功。                     |
| 7400101         |  参数丢失或参数类型不准确的。|
| 7400102         |  操作不允许。                        |

### OH_CaptureSession_AddPhotoOutput

```
Camera_ErrorCode OH_CaptureSession_AddPhotoOutput(Camera_CaptureSession* session, Camera_PhotoOutput* photoOutput);
```

添加照片输出。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称        | 类型                                            | 强制性| 描述            |
| -----------   | ---------------------------------------          | ----     | ---------------------- |
| session       | [Camera_CaptureSession*](#camera_capturesession) | 是      | 捕获会话对象。|
| photoOutput   | [Camera_PhotoOutput*](#camera_photooutput)       | 是      | 照片输出对象。   |

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                     |
| --------------- | ------------------------------------------------- |
| 0               |  方法调用成功。                     |
| 7400101         |  参数丢失或参数类型不准确的。|
| 7400102         |  操作不允许。                        |

### OH_CaptureSession_RemovePhotoOutput

```
Camera_ErrorCode OH_CaptureSession_RemovePhotoOutput(Camera_CaptureSession* session, Camera_PhotoOutput* photoOutput);
```

删除照片输出。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称        | 类型                                            | 强制性| 描述            |
| -----------   | ---------------------------------------          | ----     | ---------------------- |
| session       | [Camera_CaptureSession*](#camera_capturesession) | 是      | 捕获会话对象。|
| photoOutput   | [Camera_PhotoOutput*](#camera_photooutput)       | 是      | 照片输出对象。   |

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                     |
| --------------- | ------------------------------------------------- |
| 0               |  方法调用成功。                     |
| 7400101         |  参数丢失或参数类型不准确的。|
| 7400102         |  操作不允许。                        |

### OH_CaptureSession_AddVideoOutput

```
Camera_ErrorCode OH_CaptureSession_AddVideoOutput(Camera_CaptureSession* session, Camera_VideoOutput* videoOutput);
```

添加视频输出。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称        | 类型                                            | 强制性| 描述            |
| -----------   | ---------------------------------------          | ----     | ---------------------- |
| session       | [Camera_CaptureSession*](#camera_capturesession) | 是      | 捕获会话对象。|
| videoOutput   | [Camera_VideoOutput*](#camera_videooutput)       | 是      | 视频输出对象。   |

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                     |
| --------------- | ------------------------------------------------- |
| 0               |  方法调用成功。                     |
| 7400101         |  参数丢失或参数类型不准确的。|
| 7400102         |  操作不允许。                        |

### OH_CaptureSession_RemoveVideoOutput

```
Camera_ErrorCode OH_CaptureSession_RemoveVideoOutput(Camera_CaptureSession* session, Camera_VideoOutput* videoOutput);
```

删除视频输出。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称        | 类型                                            | 强制性| 描述            |
| -----------   | ---------------------------------------          | ----     | ---------------------- |
| session       | [Camera_CaptureSession*](#camera_capturesession) | 是      | 捕获会话对象。|
| videoOutput   | [Camera_VideoOutput*](#camera_videooutput)       | 是      | 视频输出对象。   |

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                     |
| --------------- | ------------------------------------------------- |
| 0               |  方法调用成功。                     |
| 7400101         |  参数丢失或参数类型不准确的。|
| 7400102         |  操作不允许。                        |

### OH_CaptureSession_AddMetadataOutput

```
Camera_ErrorCode OH_CaptureSession_AddMetadataOutput(Camera_CaptureSession* session,Camera_MetadataOutput* metadataOutput);
```

添加元数据输出。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称           | 类型                                            | 强制性| 描述            |
| -----------      | ---------------------------------------          | ----     | ---------------------- |
| session          | [Camera_CaptureSession*](#camera_capturesession) | 是      | 捕获会话对象。|
| metadataOutput   | [Camera_MetadataOutput*](#camera_metadataoutput) | 是      | 元数据输出对象。|

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                     |
| --------------- | ------------------------------------------------- |
| 0               |  方法调用成功。                     |
| 7400101         |  参数丢失或参数类型不准确的。|
| 7400102         |  操作不允许。                        |

### OH_CaptureSession_RemoveMetadataOutput

```
Camera_ErrorCode OH_CaptureSession_RemoveMetadataOutput(Camera_CaptureSession* session,Camera_MetadataOutput* metadataOutput);
```

删除元数据输出。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称           | 类型                                            | 强制性| 描述            |
| -----------      | ---------------------------------------          | ----     | ---------------------- |
| session          | [Camera_CaptureSession*](#camera_capturesession) | 是      | 捕获会话对象。|
| metadataOutput   | [Camera_MetadataOutput*](#camera_metadataoutput) | 是      | 元数据输出对象。|

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                     |
| --------------- | ------------------------------------------------- |
| 0               |  方法调用成功。                     |
| 7400101         |  参数丢失或参数类型不准确的。|
| 7400102         |  操作不允许。                        |

### OH_CaptureSession_Start

```
Camera_ErrorCode OH_CaptureSession_Start(Camera_CaptureSession* session);
```

启动捕获会话。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称           | 类型                                            | 强制性| 描述            |
| -----------      | ---------------------------------------          | ----     | ---------------------- |
| session          | [Camera_CaptureSession*](#camera_capturesession) | 是      | 捕获会话对象。|

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                     |
| --------------- | ------------------------------------------------- |
| 0               |  方法调用成功。                     |
| 7400101         |  参数丢失或参数类型不准确的。|
| 7400103         |  捕获会话未配置。               |
| 7400201         |  相机服务出现致命错误。                   |

### OH_CaptureSession_Stop

```
Camera_ErrorCode OH_CaptureSession_Stop(Camera_CaptureSession* session);
```

停止捕获会话。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称           | 类型                                            | 强制性| 描述            |
| -----------      | ---------------------------------------          | ----     | ---------------------- |
| session          | [Camera_CaptureSession*](#camera_capturesession) | 是      | 捕获会话对象。|

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                     |
| --------------- | ------------------------------------------------- |
| 0               |  方法调用成功。                     |
| 7400101         |  参数丢失或参数类型不准确的。|
| 7400201         |  相机服务出现致命错误。                   |

### OH_CaptureSession_Release

```
Camera_ErrorCode OH_CaptureSession_Release(Camera_CaptureSession* session);
```

释放捕获会话。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称           | 类型                                            | 强制性| 描述            |
| -----------      | ---------------------------------------          | ----     | ---------------------- |
| session          | [Camera_CaptureSession*](#camera_capturesession) | 是      | 捕获会话对象。|

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                     |
| --------------- | ------------------------------------------------- |
| 0               |  方法调用成功。                     |
| 7400101         |  参数丢失或参数类型不准确的。|
| 7400201         |  相机服务出现致命错误。                   |

### OH_CaptureSession_HasFlash

```
Camera_ErrorCode OH_CaptureSession_HasFlash(Camera_CaptureSession* session, bool* hasFlash);
```

检查设备是否有闪光灯。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称           | 类型                                            | 强制性| 描述                           |
| -----------      | ---------------------------------------          | ----     | ------------------------------------- |
| session          | [Camera_CaptureSession*](#camera_capturesession) | 是      | 捕获会话对象。               |
| hasFlash         | bool*                                            | 是      | 是否支持闪光灯。|

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400103         |  捕获会话未配置。                |

### OH_CaptureSession_IsFlashModeSupported

```
Camera_ErrorCode OH_CaptureSession_IsFlashModeSupported(Camera_CaptureSession* session,Camera_FlashMode flashMode, bool* isSupported);
```

检查是否支持闪光灯模式。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称           | 类型                                            | 强制性| 描述                                |
| -----------      | ---------------------------------------          | ----     | ------------------------------------------ |
| session          | [Camera_CaptureSession*](#camera_capturesession) | 是      | 捕获会话对象。                    |
| flashMode        | [Camera_FlashMode](#camera_flashmode)            | 是      | 闪光灯模式的枚举。                       |
| isSupported      | bool*                                            | 是      | 是否支持闪光灯模式。|

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400103         |  捕获会话未配置。                |

### OH_CaptureSession_GetFlashMode

```
Camera_ErrorCode OH_CaptureSession_GetFlashMode(Camera_CaptureSession* session, Camera_FlashMode* flashMode);
```

获取当前闪光灯模式。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称           | 类型                                            | 强制性| 描述            |
| -----------      | ---------------------------------------          | ----     | ---------------------- |
| session          | [Camera_CaptureSession*](#camera_capturesession) | 是      | 捕获会话对象。|
| flashMode        | [Camera_FlashMode*](#camera_flashmode)           | 是      | 闪光灯模式的枚举。   |

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400103         |  捕获会话未配置。                |

### OH_CaptureSession_SetFlashMode

```
Camera_ErrorCode OH_CaptureSession_SetFlashMode(Camera_CaptureSession* session, Camera_FlashMode flashMode);
```

设置闪光灯模式。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称           | 类型                                            | 强制性| 描述            |
| -----------      | ---------------------------------------          | ----     | ---------------------- |
| session          | [Camera_CaptureSession*](#camera_capturesession) | 是      | 捕获会话对象。|
| flashMode        | [Camera_FlashMode](#camera_flashmode)            | 是      | 闪光灯模式的枚举。   |

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400103         |  捕获会话未配置。                |

### OH_CaptureSession_IsExposureModeSupported

```
Camera_ErrorCode OH_CaptureSession_IsExposureModeSupported(Camera_CaptureSession* session, Camera_ExposureMode exposureMode, bool* isSupported);
```

检查是否支持曝光模式。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称           | 类型                                            | 强制性| 描述                                   |
| -----------      | ---------------------------------------          | ----     | --------------------------------------------- |
| session          | [Camera_CaptureSession*](#camera_capturesession) | 是      | 捕获会话对象。                       |
| exposureMode     | [Camera_ExposureMode](#camera_exposuremode)      | 是      | 曝光模式的枚举。                       |
| isSupported      | bool*                                            | 是      | 是否支持曝光模式。|

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400103         |  捕获会话未配置。                |

### OH_CaptureSession_GetExposureMode

```
Camera_ErrorCode OH_CaptureSession_GetExposureMode(Camera_CaptureSession* session, Camera_ExposureMode* exposureMode);
```

获取当前曝光模式。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称           | 类型                                            | 强制性| 描述            |
| -----------      | ---------------------------------------          | ----     | ---------------------- |
| session          | [Camera_CaptureSession*](#camera_capturesession) | 是      | 捕获会话对象。|
| exposureMode     | [Camera_ExposureMode*](#camera_exposuremode)     | 是      | 曝光模式的枚举。|

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400103         |  捕获会话未配置。                |

### OH_CaptureSession_SetExposureMode

```
Camera_ErrorCode OH_CaptureSession_SetExposureMode(Camera_CaptureSession* session, Camera_ExposureMode exposureMode);
```

设置曝光模式。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称           | 类型                                            | 强制性| 描述            |
| -----------      | ---------------------------------------          | ----     | ---------------------- |
| session          | [Camera_CaptureSession*](#camera_capturesession) | 是      | 捕获会话对象。|
| exposureMode     | [Camera_ExposureMode](#camera_exposuremode)      | 是      | 曝光模式的枚举。|

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400103         |  捕获会话未配置。                |

### OH_CaptureSession_GetMeteringPoint

```
Camera_ErrorCode OH_CaptureSession_GetMeteringPoint(Camera_CaptureSession* session, Camera_Point* point);
```

获取当前测量点。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称           | 类型                                            | 强制性| 描述            |
| -----------      | ---------------------------------------          | ----     | ---------------------- |
| session          | [Camera_CaptureSession*](#camera_capturesession) | 是      | 捕获会话对象。|
| point            | [Camera_Point*](#camera_point)                   | 是      | 点参数。       |

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400103         |  捕获会话未配置。                |

### OH_CaptureSession_SetMeteringPoint

```
Camera_ErrorCode OH_CaptureSession_SetMeteringPoint(Camera_CaptureSession* session, Camera_Point point);
```

设置计量区域的中心点。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称           | 类型                                            | 强制性| 描述            |
| -----------      | ---------------------------------------          | ----     | ---------------------- |
| session          | [Camera_CaptureSession*](#camera_capturesession) | 是      | 捕获会话对象。|
| point            | [Camera_Point](#camera_point)                    | 是      | 点参数。       |

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400103         |  捕获会话未配置。                |

### OH_CaptureSession_GetExposureBiasRange

```
Camera_ErrorCode OH_CaptureSession_GetExposureBiasRange(Camera_CaptureSession* session, float* minExposureBias, float* maxExposureBias, float* step);
```

查询曝光补偿范围。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称           | 类型                                            | 强制性| 描述                                          |
| -----------      | ----------------------------------------------   | ----     | ---------------------------------------------------- |
| session          | [Camera_CaptureSession*](#camera_capturesession) | 是      | 捕获会话对象。                              |
| minExposureBias  | float*                                           | 是      | 曝光补偿的最小值。                |
| maxExposureBias  | float*                                           | 是      | 曝光补偿的最大值。                |
| step             | float*                                           | 是      | 每个级别之间的曝光补偿系数。|

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400103         |  捕获会话未配置。                |

### OH_CaptureSession_SetExposureBias

```
Camera_ErrorCode OH_CaptureSession_SetExposureBias(Camera_CaptureSession* session, float exposureBias);
```

设置曝光补偿。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称           | 类型                                            | 强制性| 描述                             |
| -----------      | ---------------------------------------          | ----     | --------------------------------------- |
| session          | [Camera_CaptureSession*](#camera_capturesession) | 是      | 捕获会话对象。                 |
| exposureBias     | float                                            | 是      | 要设置的目标曝光补偿。|

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400103         |  捕获会话未配置。                |

### OH_CaptureSession_GetExposureBias

```
Camera_ErrorCode OH_CaptureSession_GetExposureBias(Camera_CaptureSession* session, float* exposureBias);
```

获取当前曝光补偿。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称           | 类型                                            | 强制性| 描述                       |
| -----------      | ---------------------------------------          | ----     | --------------------------------- |
| session          | [Camera_CaptureSession*](#camera_capturesession) | 是      | 捕获会话对象。           |
| exposureBias     | float*                                           | 是      | 当前的曝光补偿。|

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400103         |  捕获会话未配置。                |

### OH_CaptureSession_IsFocusModeSupported

```
Camera_ErrorCode OH_CaptureSession_IsFocusModeSupported(Camera_CaptureSession* session, Camera_FocusMode focusMode, bool* isSupported);
```

检查是否支持聚焦模式。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称           | 类型                                            | 强制性| 描述                                |
| -----------      | ---------------------------------------          | ----     | ------------------------------------------ |
| session          | [Camera_CaptureSession*](#camera_capturesession) | 是      | 捕获会话对象。                    |
| focusMode        | [Camera_FocusMode](#camera_focusmode)            | 是      | 聚焦模式的枚举。                       |
| isSupported      | bool*                                            | 是      | 是否支持聚焦模式。|

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400103         |  捕获会话未配置。                |

### OH_CaptureSession_GetFocusMode

```
Camera_ErrorCode OH_CaptureSession_GetFocusMode(Camera_CaptureSession* session, Camera_FocusMode* focusMode);
```

获取当前聚焦模式。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称           | 类型                                            | 强制性| 描述            |
| -----------      | ---------------------------------------          | ----     | ---------------------- |
| session          | [Camera_CaptureSession*](#camera_capturesession) | 是      | 捕获会话对象。|
| focusMode        | [Camera_FocusMode](#camera_focusmode)            | 是      | 聚焦模式的枚举。   |

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400103         |  捕获会话未配置。                |

### OH_CaptureSession_SetFocusMode

```
Camera_ErrorCode OH_CaptureSession_SetFocusMode(Camera_CaptureSession* session, Camera_FocusMode focusMode);
```

设置聚焦模式。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称           | 类型                                            | 强制性| 描述            |
| -----------      | ---------------------------------------          | ----     | ---------------------- |
| session          | [Camera_CaptureSession*](#camera_capturesession) | 是      | 捕获会话对象。|
| focusMode        | [Camera_FocusMode](#camera_focusmode)            | 是      | 聚焦模式的枚举。   |

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400103         |  捕获会话未配置。                |

### OH_CaptureSession_GetFocusPoint

```
Camera_ErrorCode OH_CaptureSession_GetFocusPoint(Camera_CaptureSession* session, Camera_Point* focusPoint);
```

获取当前焦点。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称           | 类型                                            | 强制性| 描述            |
| -----------      | ---------------------------------------          | ----     | ---------------------- |
| session          | [Camera_CaptureSession*](#camera_capturesession) | 是      | 捕获会话对象。|
| focusPoint       | [Camera_Point*](#camera_point)                   | 是      | 点参数。       |

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400103         |  捕获会话未配置。                |

### OH_CaptureSession_SetFocusPoint

```
Camera_ErrorCode OH_CaptureSession_SetFocusPoint(Camera_CaptureSession* session, Camera_Point focusPoint);
```

设置焦点。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称           | 类型                                            | 强制性| 描述            |
| -----------      | ---------------------------------------          | ----     | ---------------------- |
| session          | [Camera_CaptureSession*](#camera_capturesession) | 是      | 捕获会话对象。|
| focusPoint       | [Camera_Point](#camera_point)                    | 是      | 点参数。       |

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400103         |  捕获会话未配置。                |

### OH_CaptureSession_GetZoomRatioRange

```
Camera_ErrorCode OH_CaptureSession_GetZoomRatioRange(Camera_CaptureSession* session, float* minZoom, float* maxZoom);
```

获取所有支持的缩放比例范围。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称           | 类型                                            | 强制性| 描述                     |
| -----------      | ---------------------------------------          | ----     | ------------------------------- |
| session          | [Camera_CaptureSession*](#camera_capturesession) | 是      | 捕获会话对象。         |
| minZoom          | float*                                           | 是      | 缩放比例范围的最小值。|
| maxZoom          | float*                                           | 是      | 缩放比例范围的最大值。|

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400103         |  捕获会话未配置。                |

### OH_CaptureSession_GetZoomRatio

```
Camera_ErrorCode OH_CaptureSession_GetZoomRatio(Camera_CaptureSession* session, float* zoom);
```

获取当前缩放比例。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称           | 类型                                            | 强制性| 描述            |
| -----------      | ---------------------------------------          | ----     | ---------------------- |
| session          | [Camera_CaptureSession*](#camera_capturesession) | 是      | 捕获会话对象。|
| zoom             | float*                                           | 是      | 当前缩放比例。|

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400103         |  捕获会话未配置。                |

### OH_CaptureSession_SetZoomRatio

```
Camera_ErrorCode OH_CaptureSession_SetZoomRatio(Camera_CaptureSession* session, float zoom);
```

设置缩放比例。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称           | 类型                                            | 强制性| 描述                  |
| -----------      | ---------------------------------------          | ----     | ---------------------------- |
| session          | [Camera_CaptureSession*](#camera_capturesession) | 是      | 捕获会话对象。      |
| zoom             | float                                            | 是      | 要设置的目标缩放比例。|

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400103         |  捕获会话未配置。                |

### OH_CaptureSession_IsVideoStabilizationModeSupported

```
Camera_ErrorCode OH_CaptureSession_IsVideoStabilizationModeSupported(Camera_CaptureSession* session,Camera_VideoStabilizationMode mode, bool* isSupported);
```

检查是否支持视频防抖模式。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称           | 类型                                                            | 强制性| 描述                                              |
| -----------      | ------------------------------------------------------           | ----     | -------------------------------------------------------- |
| session          | [Camera_CaptureSession*](#camera_capturesession)                 | 是      | 捕获会话对象。                                  |
| mode             | [Camera_VideoStabilizationMode](#camera_videostabilizationmode)  | 是      | 视频防抖模式的枚举。                       |
| isSupported      | bool*                                                            | 是      | 是否支持视频防抖模式。|

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400103         |  捕获会话未配置。                |

### OH_CaptureSession_GetVideoStabilizationMode

```
Camera_ErrorCode OH_CaptureSession_GetVideoStabilizationMode(Camera_CaptureSession* session, Camera_VideoStabilizationMode* mode);
```

获取当前视频防抖模式。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称           | 类型                                                            | 强制性| 描述                       |
| -----------      | ------------------------------------------------------           | ----     | --------------------------------- |
| session          | [Camera_CaptureSession*](#camera_capturesession)                 | 是      | 捕获会话对象。           |
| mode             | [Camera_VideoStabilizationMode*](#camera_videostabilizationmode) | 是      | 视频防抖模式的枚举。|

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400103         |  捕获会话未配置。                |

### OH_CaptureSession_SetVideoStabilizationMode

```
Camera_ErrorCode OH_CaptureSession_SetVideoStabilizationMode(Camera_CaptureSession* session,Camera_VideoStabilizationMode mode);
```

设置视频防抖模式。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称           | 类型                                                            | 强制性| 描述                       |
| -----------      | ------------------------------------------------------           | ----     | --------------------------------- |
| session          | [Camera_CaptureSession*](#camera_capturesession)                 | 是      | 捕获会话对象。           |
| mode             | [Camera_VideoStabilizationMode](#camera_videostabilizationmode)  | 是      | 视频防抖模式的枚举。|

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400103         |  捕获会话未配置。                |

### OH_CaptureSession_OnFocusStateChange

```
typedef void (*OH_CaptureSession_OnFocusStateChange)(Camera_CaptureSession* session, Camera_FocusState focusState);
```

在CaptureSession_Callbacks中调用的捕获会话焦点状态回调。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称           | 类型                                             | 强制性| 描述            |
| -----------      | --------------------------------------------------| ----     | ---------------------- |
| session          | [Camera_CaptureSession*](#camera_capturesession)  | 是      | 捕获会话对象。|
| focusState       | [Camera_FocusState](#camera_focusstate)           | 是      | 焦点状态的枚举。  |

### OH_CaptureSession_OnError

```
typedef void (*OH_CaptureSession_OnError)(Camera_CaptureSession* session, Camera_ErrorCode errorCode);
```

在CaptureSession_Callbacks中调用的捕获会话错误回调。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称           | 类型                                             | 强制性| 描述                |
| -----------      | --------------------------------------------------| ----     | -------------------------- |
| session          | [Camera_CaptureSession*](#camera_capturesession)  | 是      | 捕获会话对象。    |
| errorCode        | [Camera_ErrorCode](#camera_errorcode)             | 是      | 相机错误代码的枚举。|

### CaptureSession_Callbacks

```
typedef struct CaptureSession_Callbacks CaptureSession_Callbacks;
```

捕获会话的回调。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称             | 类型                                                                        | 强制性| 描述                               |
| -----------        | -----------------------------------------------------------------------------|----------| ----------------------------------------- |
| onFocusStateChange | [OH_CaptureSession_OnFocusStateChange](#oh_capturesession_onfocusstatechange)| 是      | 捕获会话焦点状态更改事件。 |
| onError            | [OH_CaptureSession_OnError](#oh_capturesession_onerror)                      | 是      | 捕获会话错误事件。              |

### OH_CaptureSession_RegisterCallback

```
Camera_ErrorCode OH_CaptureSession_RegisterCallback(Camera_CaptureSession* session, CaptureSession_Callbacks* callback);
```

注册捕获会话事件回调。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称    | 类型                                                  | 强制性| 描述                    |
| --------- | ------------------------------------------------------ | ----     | ------------------------------ |
| session   | [Camera_CaptureSession*](#camera_capturesession)       | 是      | 捕获会话对象。        |
| callback  | [CaptureSession_Callbacks*](#capturesession_callbacks) | 是      | 捕获会话的回调。|

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |

### OH_CaptureSession_UnregisterCallback

```
Camera_ErrorCode OH_CaptureSession_UnregisterCallback(Camera_CaptureSession* session, CaptureSession_Callbacks* callback);
```

注销捕获会话事件回调。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称    | 类型                                                  | 强制性| 描述                    |
| --------- | ------------------------------------------------------ | ----     | ------------------------------ |
| session   | [Camera_CaptureSession*](#camera_capturesession)       | 是      | 捕获会话对象。        |
| callback  | [CaptureSession_Callbacks*](#capturesession_callbacks) | 是      | 捕获会话的回调。|

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |

### Camera_PreviewOutput

实现预览输出。

### OH_PreviewOutput_Start

```
Camera_ErrorCode OH_PreviewOutput_Start(Camera_PreviewOutput* previewOutput);
```

开始预览输出。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称           | 类型                                          | 强制性| 描述            |
| -----------      | ---------------------------------------        | ----     | ---------------------- |
| previewOutput    | [Camera_PreviewOutput*](#camera_previewoutput) | 是      | 预览输出对象。 |

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400103         |  捕获会话未配置。                |
| 7400201         |  相机服务出现致命错误。                    |

### OH_PreviewOutput_Stop

```
Camera_ErrorCode OH_PreviewOutput_Stop(Camera_PreviewOutput* previewOutput);
```

停止预览输出。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称           | 类型                                          | 强制性| 描述            |
| -----------      | ---------------------------------------        | ----     | ---------------------- |
| previewOutput    | [Camera_PreviewOutput*](#camera_previewoutput) | 是      | 预览输出对象。 |

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400201         |  相机服务出现致命错误。                    |

### OH_PreviewOutput_Release

```
Camera_ErrorCode OH_PreviewOutput_Release(Camera_PreviewOutput* previewOutput);
```

释放预览输出。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称           | 类型                                          | 强制性| 描述            |
| -----------      | ---------------------------------------        | ----     | ---------------------- |
| previewOutput    | [Camera_PreviewOutput*](#camera_previewoutput) | 是      | 预览输出对象。 |

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400201         |  相机服务出现致命错误。                    |

### OH_PreviewOutput_OnFrameStart

```
typedef void (*OH_PreviewOutput_OnFrameStart)(Camera_PreviewOutput* previewOutput);
```

预览输出帧开始回调，以便在PreviewOutput_Callbacks中调用。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称           | 类型                                           | 强制性| 描述            |
| -----------      | ------------------------------------------------| ----     | ------------------     |
| previewOutput    | [Camera_PreviewOutput*](#camera_previewoutput)  | 是      | 预览输出对象。 |

### OH_PreviewOutput_OnFrameEnd

```
typedef void (*OH_PreviewOutput_OnFrameEnd)(Camera_PreviewOutput* previewOutput, int32_t frameCount);
```

在PreviewOutput_Callbacks中调用的预览输出帧结束回调。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称           | 类型                                           | 强制性| 描述                                     |
| -----------      | ------------------------------------------------| ----     | ----------------------------------------------- |
| previewOutput    | [Camera_PreviewOutput*](#camera_previewoutput)  | 是      | 预览输出对象。                          |
| frameCount       | int32_t                                         | 是      | 由回调传递的帧计数。|

### OH_PreviewOutput_OnError

```
typedef void (*OH_PreviewOutput_OnError)(Camera_PreviewOutput* previewOutput, Camera_ErrorCode errorCode);
```

在PreviewOutput_Callbacks中调用的预览输出错误回调。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称           | 类型                                           | 强制性| 描述                |
| -----------      | ------------------------------------------------| ----     | -------------------------- |
| previewOutput    | [Camera_PreviewOutput*](#camera_previewoutput)  | 是      | 预览输出对象。     |
| errorCode        | [Camera_ErrorCode](#camera_errorcode)           | 是      | 相机错误代码的枚举。|

### PreviewOutput_Callbacks

```
typedef struct PreviewOutput_Callbacks PreviewOutput_Callbacks;
```

用于预览输出的回调。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称       | 类型                                                          | 强制性 | 描述                       |
| ----------   | ---------------------------------------------------------------|-----------| --------------------------------- |
| onFrameStart | [OH_PreviewOutput_OnFrameStart](#oh_previewoutput_onframestart)|  是      | 预览输出帧开始事件。 |
| onFrameEnd   | [OH_PreviewOutput_OnFrameEnd](#oh_previewoutput_onframeend)    |  是      | 预览输出帧结束事件。   |
| onError      | [OH_PreviewOutput_OnError](#oh_previewoutput_onerror)          |  是      | 预览输出错误事件。       |

### OH_PreviewOutput_RegisterCallback

```
Camera_ErrorCode OH_PreviewOutput_RegisterCallback(Camera_PreviewOutput* previewOutput, PreviewOutput_Callbacks* callback);
```

注册预览输出更改事件回调。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称        | 类型                                                | 强制性| 描述                   |
| ------------- | -----------------------------------------------------| ----     | ------------------------------|
| previewOutput | [Camera_PreviewOutput*](#camera_previewoutput)       | 是      | 预览输出对象。        |
| callback      | [PreviewOutput_Callbacks*](#previewoutput_callbacks) | 是      | 用于预览输出的回调。|

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |

### OH_PreviewOutput_UnregisterCallback

```
Camera_ErrorCode OH_PreviewOutput_UnregisterCallback(Camera_PreviewOutput* previewOutput, PreviewOutput_Callbacks* callback);
```

注销预览输出更改事件回调。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称        | 类型                                                | 强制性| 描述                   |
| ------------- | -----------------------------------------------------| ----     | ------------------------------|
| previewOutput | [Camera_PreviewOutput*](#camera_previewoutput)       | 是      | 预览输出对象。        |
| callback      | [PreviewOutput_Callbacks*](#previewoutput_callbacks) | 是      | 用于预览输出的回调。|

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |

### Camera_ImageRotation

```
typedef enum Camera_ImageRotation Camera_ImageRotation;
```

图像旋转角度的枚举。

**系统能力**: SystemCapability.Multimedia.Camera.Core

| 名称             | 数值| 描述                           |
| ---------------  --| ---- | ------------------------------------- |
| IAMGE_ROTATION_0   | 0    | 捕获图像旋转0度。  |
| IAMGE_ROTATION_90  | 90   | 捕获图像旋转90度。 |
| IAMGE_ROTATION_180 | 180  | 捕获图像旋转180度。|
| IAMGE_ROTATION_270 | 270  | 捕获图像旋转270度。|

### Camera_Location

```
typedef struct Camera_Location Camera_Location;
```

相机拍摄位置。

**系统能力**: SystemCapability.Multimedia.Camera.Core

| 名称       | 类型  | 强制性|描述  |
| ------------ | ------ | ---      |------------ |
| latitude     | double | 是      |纬度。    |
| longitude    | double | 是      |经度。   |
| altitude     | double | 是      |海拔高度。    |

### Camera_QualityLevel

```
typedef enum Camera_QualityLevel Camera_QualityLevel;
```

图像质量级别的枚举。

**系统能力**: SystemCapability.Multimedia.Camera.Core

| 名称               | 数值  | 描述        |
| -------------------- | ---- | -------------------- |
| QUALITY_LEVEL_HIGH   | 0    | 高图像质量。  |
| QUALITY_LEVEL_MEDIUM | 1    | 中等图像质量。|
| QUALITY_LEVEL_LOW    | 2    | 低图像质量。   |


### Camera_PhotoCaptureSetting

```
typedef struct Camera_PhotoCaptureSetting Camera_PhotoCaptureSetting;
```

要设置的照片捕获选项。

**系统能力**: SystemCapability.Multimedia.Camera.Core

| 名称   | 类型                                         | 强制性 | 描述                                            |
| -------- | -------------------------------               | --------  | ------------------------------------------------------ |
| quality  | [Camera_QualityLevel](#camera_qualitylevel)   | 是       | 照片图像质量。                                   |
| rotation | [Camera_ImageRotation](#camera_imagerotation) | 是       | 照片旋转。                                        |
| location | [Camera_Location*](#camera_location)          | 是       | 照片位置。                                        |
| mirror   | bool                                          | 是       | 设置镜像照片功能开关，默认为false。|

### Camera_PhotoOutput

实现拍摄会话中使用的输出信息。

### OH_PhotoOutput_Capture

```
Camera_ErrorCode OH_PhotoOutput_Capture(Camera_PhotoOutput* photoOutput);
```

拍摄照片。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称           | 类型                                          | 强制性| 描述            |
| -----------      | ---------------------------------------        | ----     | ---------------------- |
| photoOutput      | [Camera_PhotoOutput*](#camera_photooutput)     | 是      | 照片输出对象。   |

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400104         |  捕获会话未运行。               |
| 7400201         |  相机服务出现致命错误。                    |

### OH_PhotoOutput_Capture_WithCaptureSetting

```
Camera_ErrorCode OH_PhotoOutput_Capture_WithCaptureSetting(Camera_PhotoOutput* photoOutput, Camera_PhotoCaptureSetting setting);
```

使用捕获设置捕获照片。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称      | 类型                                                    | 强制性| 描述                  |
| ----------- | -------------------------------------------------------- | ----     | ---------------------------- |
| photoOutput | [Camera_PhotoOutput*](#camera_photooutput)               | 是      | 照片输出对象。         |
| setting     | [Camera_PhotoCaptureSetting](#camera_photocapturesetting)| 是      | 要设置的照片捕获选项。|

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400104         |  捕获会话未运行。               |
| 7400201         |  相机服务出现致命错误。                    |

### OH_PhotoOutput_Release

```
Camera_ErrorCode OH_PhotoOutput_Release(Camera_PhotoOutput* photoOutput);
```

释放照片输出。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称      | 类型                                         | 强制性| 描述          |
| ----------- | ---------------------------------------       | ----     | ---------------      |
| photoOutput | [Camera_PhotoOutput*](#camera_photooutput)    | 是      | 照片输出对象。 |

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400201         |  相机服务出现致命错误。                    |

### OH_PhotoOutput_IsMirrorSupported

```
Camera_ErrorCode OH_PhotoOutput_IsMirrorSupported(Camera_PhotoOutput* photoOutput, bool* isSupported);
```

检查是否支持镜像模式。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称      | 类型                                         | 强制性| 描述                            |
| ----------- | ---------------------------------------       | ----     | -------------------------------------- |
| photoOutput | [Camera_PhotoOutput*](#camera_photooutput)    | 是      | 照片输出对象。                   |
| isSupported | bool*                                         | 是      | 是否支持镜像。|

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400201         |  相机服务出现致命错误。                    |



### OH_PhotoOutput_OnFrameStart

```
typedef void (*OH_PhotoOutput_OnFrameStart)(Camera_PhotoOutput* photoOutput);
```

在PhotoOutput_Callbacks中调用的照片输出帧启动回调。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称           | 类型                                          | 强制性| 描述            |
| -----------      | ---------------------------------------        | ----     | ---------------------- |
| photoOutput      | [Camera_PhotoOutput*](#camera_photooutput)     | 是      | 照片输出对象。   |

### OH_PhotoOutput_OnFrameShutter

```
typedef void (*OH_PhotoOutput_OnFrameShutter)(Camera_PhotoOutput* photoOutput, Camera_FrameShutterInfo* info);
```

在PhotoOutput_Callbacks中调用的照片输出帧快门回调。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称      | 类型                                                | 强制性| 描述             |
| ----------- | --------------------------------------------------   | ---- | ----------------------------|
| photoOutput | [Camera_PhotoOutput*](#camera_photooutput)           | 是  | 照片输出对象。        |
| info        | [Camera_FrameShutterInfo*](#camera_frameshutterinfo) | 是  | 帧快门回调信息。|

### OH_PhotoOutput_OnFrameEnd

```
typedef void (*OH_PhotoOutput_OnFrameEnd)(Camera_PhotoOutput* photoOutput, int32_t frameCount);
```

在PhotoOutput_Callbacks中调用的照片输出帧结束回调。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称      | 类型                                       | 强制性| 描述                                 |
| ----------- | --------------------------------------------| ---- | ------------------------------------------------|
| photoOutput | [Camera_PhotoOutput*](#camera_photooutput)  | 是  | 照片输出对象。                            |
| frameCount  | int32_t                                     | 是  | 由回调传递的帧计数。|

### OH_PhotoOutput_OnError

```
typedef void (*OH_PhotoOutput_OnError)(Camera_PhotoOutput* photoOutput, Camera_ErrorCode errorCode);
```

在PhotoOutput_Callbacks中调用的照片输出错误回调。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称      | 类型                                       | 强制性| 描述                |
| ----------- | --------------------------------------------| -------- | ---------------------------|
| photoOutput | [Camera_PhotoOutput*](#camera_photooutput)  | 是      | 照片输出对象。       |
| errorCode   | [Camera_ErrorCode](#camera_errorcode)       | 是      | 相机错误代码的枚举。|

### PhotoOutput_Callbacks

```
typedef struct PhotoOutput_Callbacks PhotoOutput_Callbacks;
```

照片输出的回调。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称         | 类型                                                          | 强制性 | 描述                       |
| ------------   | ---------------------------------------------------------------|-----------| --------------------------------- |
| onFrameStart   | [OH_PhotoOutput_OnFrameStart](#oh_photooutput_onframestart)    |  是      | 照片输出帧启动事件。   |
| onFrameShutter | [OH_PhotoOutput_OnFrameShutter](#oh_photooutput_onframeshutter)|  是      | 照片输出框快门事件。 |
| onFrameEnd     | [OH_PhotoOutput_OnFrameEnd](#oh_photooutput_onframeend)        |  是      | 照片输出帧结束事件。     |
| onError        | [OH_PhotoOutput_OnError](#oh_photooutput_onerror)              |  是      | 照片输出错误事件。         |

### OH_PhotoOutput_RegisterCallback

```
Camera_ErrorCode OH_PhotoOutput_RegisterCallback(Camera_PhotoOutput* photoOutput, PhotoOutput_Callbacks* callback);
```

注册照片输出更改事件回调。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称     | 类型                                               | 强制性| 描述                  |
| -----------| ----------------------------------------------------| -------- | -----------------------------|
| photoOutput| [Camera_PhotoOutput*](#camera_photooutput)          | 是      | 照片输出对象。         |
| callback   | [PhotoOutput_Callbacks*](#photooutput_callbacks)    | 是      | 照片输出的回调。 |

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |

### OH_PhotoOutput_UnregisterCallback

```
Camera_ErrorCode OH_PhotoOutput_UnregisterCallback(Camera_PhotoOutput* photoOutput, PhotoOutput_Callbacks* callback);
```

注销照片输出更改事件回调。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称     | 类型                                               | 强制性| 描述                  |
| -----------| ----------------------------------------------------| -------- | ---------------------------- |
| photoOutput| [Camera_PhotoOutput*](#camera_photooutput)          | 是      | 照片输出对象。         |
| callback   | [PhotoOutput_Callbacks*](#photooutput_callbacks)    | 是      | 照片输出的回调。 |

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |

### Camera_CaptureEndInfo

```
typedef struct Camera_CaptureEndInfo Camera_CaptureEndInfo;
```

捕获结束信息。

**系统能力**: SystemCapability.Multimedia.Camera.Core

| 名称     | 类型   | 强制性| 描述  |
| ---------- | ------  | ----     | ---------    |
| captureId  | int32_t | 是      | 捕获id。  |
| frameCount | int64_t | 是      | 帧数。 |

### Camera_VideoOutput

实现视频录制会话中使用的输出信息。

### OH_VideoOutput_Start

```
Camera_ErrorCode OH_VideoOutput_Start(Camera_VideoOutput* videoOutput);
```

开始视频输出。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称           | 类型                                          | 强制性| 描述            |
| -----------      | ---------------------------------------        | ----     | ---------------------- |
| videoOutput      | [Camera_VideoOutput*](#camera_videooutput)     | 是      | 视频输出对象。   |

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400103         |  捕获会话未配置。                |
| 7400201         |  相机服务出现致命错误。                    |

### OH_VideoOutput_Stop

```
Camera_ErrorCode OH_VideoOutput_Stop(Camera_VideoOutput* videoOutput);
```

停止视频输出。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称           | 类型                                          | 强制性| 描述            |
| -----------      | ---------------------------------------        | ----     | ---------------------- |
| videoOutput      | [Camera_VideoOutput*](#camera_videooutput)     | 是      | 视频输出对象。   |

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400201         |  相机服务出现致命错误。                    |

### OH_VideoOutput_Release

```
Camera_ErrorCode OH_VideoOutput_Release(Camera_VideoOutput* videoOutput);
```

释放视频输出。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称           | 类型                                          | 强制性| 描述            |
| -----------      | ---------------------------------------        | ----     | ---------------------- |
| videoOutput      | [Camera_VideoOutput*](#camera_videooutput)     | 是      | 视频输出对象。   |

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400201         |  相机服务出现致命错误。                    |

### OH_VideoOutput_OnFrameStart

```
typedef void (*OH_VideoOutput_OnFrameStart)(Camera_VideoOutput* videoOutput);
```

在VideoOutput_Callbacks中调用的视频输出帧开始回调。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称           | 类型                                          | 强制性| 描述            |
| -----------      | ---------------------------------------        | ----     | ---------------------- |
| videoOutput      | [Camera_VideoOutput*](#camera_videooutput)     | 是      | 视频输出对象。   |

### OH_VideoOutput_OnFrameEnd

```
typedef void (*OH_VideoOutput_OnFrameEnd)(Camera_VideoOutput* videoOutput, int32_t frameCount);
```

在VideoOutput_Callbacks中调用的视频输出帧结束回调。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称           | 类型                                     | 强制性| 描述                                     |
| -----------      | ---------------------------------------   | ----     | ----------------------------------------------- |
| videoOutput      | [Camera_VideoOutput*](#camera_videooutput)| 是      | 视频输出对象。                            |
| frameCount       | int32_t                                   | 是      | 由回调传递的帧计数。|

### OH_VideoOutput_OnError

```
typedef void (*OH_VideoOutput_OnError)(Camera_VideoOutput* videoOutput, Camera_ErrorCode errorCode);
```

在VideoOutput_Callbacks中调用的视频输出错误回调。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称           | 类型                                     | 强制性| 描述                 |
| -----------      | ---------------------------------------   | ----     | --------------------------- |
| videoOutput      | [Camera_VideoOutput*](#camera_videooutput)| 是      | 视频输出对象。        |
| errorCode        | [Camera_ErrorCode](#camera_errorcode)     | 是      | 相机错误代码的枚举。 |

### VideoOutput_Callbacks

```
typedef struct VideoOutput_Callbacks VideoOutput_Callbacks;
```

用于视频输出的回调。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称         | 类型                                                          | 强制性 | 描述                    |
| ------------   | ---------------------------------------------------------------|-----------| ------------------------------ |
| onFrameStart   | [OH_VideoOutput_OnFrameStart](#oh_videooutput_onframestart)    |  是      | 视频输出帧启动事件。|
| onFrameEnd     | [OH_VideoOutput_OnFrameEnd](#oh_videooutput_onframeend)        |  是      | 视频输出帧结束事件。  |
| onError        | [OH_VideoOutput_OnError](#oh_videooutput_onerror)              |  是      | 视频输出错误事件。      |

### OH_VideoOutput_RegisterCallback

```
Camera_ErrorCode OH_VideoOutput_RegisterCallback(Camera_VideoOutput* videoOutput, VideoOutput_Callbacks* callback);
```

注册视频输出更改事件回调。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称       | 类型                                           | 强制性| 描述                 |
| -----------  | ---------------------------------------         | ----     | ----------------------      |
| videoOutput  | [Camera_VideoOutput*](#camera_videooutput)      | 是      | 视频输出对象。        |
| callback     | [VideoOutput_Callbacks*](#videooutput_callbacks)| 是      | 用于视频输出的回调。|

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |

### OH_VideoOutput_UnregisterCallback

```
Camera_ErrorCode OH_VideoOutput_UnregisterCallback(Camera_VideoOutput* videoOutput, VideoOutput_Callbacks* callback);
```

注销视频输出更改事件回调。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称       | 类型                                           | 强制性| 描述                 |
| -----------  | ---------------------------------------         | ----     | ----------------------      |
| videoOutput  | [Camera_VideoOutput*](#camera_videooutput)      | 是      | 视频输出对象。        |
| callback     | [VideoOutput_Callbacks*](#videooutput_callbacks)| 是      | 用于视频输出的回调。|

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |


### Camera_MetadataOutput

实现元数据流。

### OH_MetadataOutput_Start

```
Camera_ErrorCode OH_MetadataOutput_Start(Camera_MetadataOutput* metadataOutput);
```

启动元数据输出。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称         | 类型                                            | 强制性| 描述              |
| -----------    | ---------------------------------------          | ----     | ----------------------   |
| metadataOutput | [Camera_MetadataOutput*](#camera_metadataoutput) | 是      | 元数据输出对象。  |

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400103         |  捕获会话未配置。                |
| 7400201         |  相机服务出现致命错误。                    |

### OH_MetadataOutput_Stop

```
Camera_ErrorCode OH_MetadataOutput_Stop(Camera_MetadataOutput* metadataOutput);
```

停止元数据输出。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称         | 类型                                            | 强制性| 描述              |
| -----------    | ---------------------------------------          | ----     | ----------------------   |
| metadataOutput | [Camera_MetadataOutput*](#camera_metadataoutput) | 是      | 元数据输出对象。  |

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400201         |  相机服务出现致命错误。                    |

### OH_MetadataOutput_Release

```
Camera_ErrorCode OH_MetadataOutput_Release(Camera_MetadataOutput* metadataOutput);
```

释放元数据输出。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称         | 类型                                            | 强制性| 描述              |
| -----------    | ---------------------------------------          | ----     | ----------------------   |
| metadataOutput | [Camera_MetadataOutput*](#camera_metadataoutput) | 是      | 元数据输出对象。  |

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |
| 7400201         |  相机服务出现致命错误。                    |

### OH_MetadataOutput_OnMetadataObjectAvailable

```
typedef void (*OH_MetadataOutput_OnMetadataObjectAvailable)(Camera_MetadataOutput* metadataOutput, Camera_MetadataObject* metadataObject, uint32_t size);
```

在MetadataOutput_Callbacks中调用的元数据输出元数据对象可用回调。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称         | 类型                                           | 强制性| 描述                    |
| -----------    | ---------------------------------------         | -------- | ------------------------------ |
| metadataOutput | [Camera_MetadataOutput*](#camera_metadataoutput)| 是      | 元数据输出对象。        |
| metadataObject | [Camera_MetadataObject*](#camera_metadataobject)| 是      | 元数据对象基础。         |
| size           | uint32_t                                        | 是      | 元数据对象的大小。|

### OH_MetadataOutput_OnError

```
typedef void (*OH_MetadataOutput_OnError)(Camera_MetadataOutput* metadataOutput, Camera_ErrorCode errorCode);
```

在MetadataOutput_Callbacks中调用的元数据输出错误回调。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称        | 类型                                           | 强制性| 描述                 |
| -----------   | ---------------------------------------         | -------- | --------------------------- |
| metadataOutput| [Camera_MetadataOutput*](#camera_metadataoutput)| 是      | 元数据输出对象。     |
| errorCode     | [Camera_ErrorCode](#camera_errorcode)           | 是      | 相机错误代码的枚举。 |

### MetadataOutput_Callbacks

```
typedef struct MetadataOutput_Callbacks MetadataOutput_Callbacks;
```

元数据输出的回调。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称                   | 类型                                                                                       | 强制性 | 描述                                                  |
| ------------------------ | ------------------------------------------------------------------------------------------- |-----------| ------------------------------------------------------------ |
| onMetadataObjectAvailable| [OH_MetadataOutput_OnMetadataObjectAvailable](#oh_metadataoutput_onmetadataobjectavailable) |  是      | 此回调将调用元数据输出结果数据。 |
| onError                  | [OH_MetadataOutput_OnError](#oh_metadataoutput_onerror)                                     |  是      | 元数据输出错误事件。            |

### OH_MetadataOutput_RegisterCallback

```
Camera_ErrorCode OH_MetadataOutput_RegisterCallback(Camera_MetadataOutput* metadataOutput, MetadataOutput_Callbacks* callback);
```

注册元数据输出更改事件回调。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称          | 类型                                                 | 强制性| 描述                    |
| --------------  | ----------------------------------------------------  | ----     | ------------------------------ |
| metadataOutput  | [Camera_MetadataOutput*](#camera_metadataoutput)      | 是      | 元数据输出对象。        |
| callback        | [MetadataOutput_Callbacks*](#metadataoutput_callbacks)| 是      | 元数据输出的回调。|

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |

### OH_MetadataOutput_UnregisterCallback

```
Camera_ErrorCode OH_MetadataOutput_UnregisterCallback(Camera_MetadataOutput* metadataOutput, MetadataOutput_Callbacks* callback);
```

注销元数据输出更改事件回调。

**系统能力**: SystemCapability.Multimedia.Camera.Core

**参数**

| 名称          | 类型                                                 | 强制性| 描述                    |
| --------------  | ----------------------------------------------------  | ----     | ------------------------------ |
| metadataOutput  | [Camera_MetadataOutput*](#camera_metadataoutput)      | 是      | 元数据输出对象。        |
| callback        | [MetadataOutput_Callbacks*](#metadataoutput_callbacks)| 是      | 元数据输出的回调。|

**返回值**

| 类型                                    | 描述                   |
| ---------------------------------------  | ----------------------------- |
| [Camera_ErrorCode](#camera_errorcode)    | 如果操作成功或失败，则返回[Camera_ErrorCode](#camera_errorcode)中定义的错误代码。|

**错误代码**

有关错误代码的详细信息，请参阅[Camera Error Codes](#camera_errorcode) 

| ID              | 错误消息                                      |
| --------------- | -----------------------------------------------    |
| 0               |  方法调用成功。                      |
| 7400101         |  参数丢失或参数类型不准确的。 |

### Camera_MetadataObjectType

```
typedef enum Camera_MetadataObjectType Camera_MetadataObjectType;
```

元数据对象类型的枚举。

**系统能力**: SystemCapability.Multimedia.Camera.Core

| 名称                    | 数值  | 描述    |
| ------------------------- | ------ | -------------- |
| FACE_DETECTION            | 0      | Face detection.|

### Camera_Rect

```
typedef struct Camera_Rect Camera_Rect;
```

矩形定义。

**系统能力**: SystemCapability.Multimedia.Camera.Core

| 名称   | 类型   |    强制性    |           描述             |
| -------- | ------  | --------------- | --------------------              |
| topLeftX | int32_t |       是       | 左上角的X坐标。  |
| topLeftY | int32_t |       是       | 左上角的Y坐标。  |
| width    | int32_t |       是       | 此矩形的宽度。          |
| height   | int32_t |       是       | 此矩形的高度。         |

### Camera_MetadataObject

```
typedef struct Camera_MetadataObject Camera_MetadataObject;
```

元数据对象基础。

**系统能力**: SystemCapability.Multimedia.Camera.Core

| 名称      | 类型                                                     | 强制性 | 描述                                               |
| --------    | --------------------------------------------------        | ----      | --------------------------------------------------------- |
| 类型       | [Camera_MetadataObjectType](#camera_metadataobjecttype)   | 是       | 元数据对象类型。                                     |
| timestamp   | int64_t                                                   | 是       | 元数据对象时间戳（以毫秒为单位）。                |
| boundingBox | [Camera_Rect*](#camera_rect)                              | 是       | 检测到的元数据对象的轴对齐边界框。|
