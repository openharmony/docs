# ICameraHost


## **概述**

定义Camera设备功能操作。

设置回调接口、返回设备ID列表、打开并执行Camera设备的相关操作。

**相关模块:**

[Camera](camera.md)


## **汇总**


### Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [SetCallback](#setcallback)&nbsp;([in]&nbsp;[ICameraHostCallback](interface_i_camera_host_callback.md)&nbsp;callbackObj) | 设置ICameraHost回调接口，回调函数参考[ICameraHostCallback](interface_i_camera_host_callback.md)。 | 
| [GetCameraIds](#getcameraids)&nbsp;([out]&nbsp;String[]&nbsp;cameraIds) | 获取当前可用的Camera设备ID列表。 | 
| [GetCameraAbility](#getcameraability)&nbsp;([in]&nbsp;String&nbsp;cameraId,&nbsp;[out]&nbsp;unsigned&nbsp;char[]&nbsp;cameraAbility) | 获取Camera设备能力集合。 | 
| [OpenCamera](#opencamera)&nbsp;([in]&nbsp;String&nbsp;cameraId,&nbsp;[in]&nbsp;[ICameraDeviceCallback](interface_i_camera_device_callback.md)&nbsp;callbackObj,&nbsp;[out]&nbsp;[ICameraDevice](interface_i_camera_device.md)&nbsp;device) | 打开Camera设备。 | 
| [SetFlashlight](#setflashlight)&nbsp;([in]&nbsp;String&nbsp;cameraId,&nbsp;[in]&nbsp;boolean&nbsp;isEnable) | 打开或关闭闪光灯。 | 


## **成员函数说明**


### GetCameraAbility()

  
```
ICameraHost::GetCameraAbility ([in] String cameraId, [out] unsigned char[] cameraAbility )
```

**描述：**

获取Camera设备能力集合。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| cameraId | 用于指定要操作的Camera设备，通过[GetCameraIds](#getcameraids)获取。 | 
| cameraAbility | 返回cameraId对应Camera设备的能力集合。 | 

**返回:**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[CamRetCode](camera.md#camretcode)。

**参见:**

[GetCameraIds](#getcameraids)


### GetCameraIds()

  
```
ICameraHost::GetCameraIds ([out] String[] cameraIds)
```

**描述：**

获取当前可用的Camera设备ID列表。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| cameraIds | 返回当前可用的设备列表。 | 

**返回:**

NO_ERROR 表示执行成功；

其他值表示执行失败，具体错误码查看[CamRetCode](camera.md#camretcode)。

**参见:**

[GetCameraAbility](#getcameraability)


### OpenCamera()

  
```
ICameraHost::OpenCamera ([in] String cameraId, [in] ICameraDeviceCallback callbackObj, [out] ICameraDevice device )
```

**描述：**

打开Camera设备。

打开指定的Camera设备，通过此接口可以获取到ICameraDevice对象，通过ICameraDevice对象可以操作具体的Camera设备。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| cameraId | 需要打开的Camera设备ID，可通过[GetCameraIds](#getcameraids)接口获取当前已有Camera设备列表。 | 
| callbackObj | Camera设备相关的回调函数，具体参见[ICameraDeviceCallback](interface_i_camera_device_callback.md)。 | 
| device | 返回当前要打开的Camera设备ID对应的ICameraDevice对象。 | 

**返回:**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[CamRetCode](camera.md#camretcode)。

**参见:**

[GetCameraIds](#getcameraids)


### SetCallback()

  
```
ICameraHost::SetCallback ([in] ICameraHostCallback callbackObj)
```

**描述：**

设置ICameraHost回调接口，回调函数参考[ICameraHostCallback](interface_i_camera_host_callback.md)。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| callbackObj | 要设置的回调函数。 | 

**返回:**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[CamRetCode](camera.md#camretcode)。


### SetFlashlight()

  
```
ICameraHost::SetFlashlight ([in] String cameraId, [in] boolean isEnable )
```

**描述：**

打开或关闭闪光灯。

该接口只能由打开cameraId指定Camera设备的调用者调用。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| cameraId | 闪光灯对应的Camera设备ID。 | 
| isEnable | 表示是否打开闪光灯，true表示打开，false表示关闭。 | 

**返回:**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看[CamRetCode](camera.md#camretcode)。

**参见:**

[GetCameraIds](#getcameraids)
