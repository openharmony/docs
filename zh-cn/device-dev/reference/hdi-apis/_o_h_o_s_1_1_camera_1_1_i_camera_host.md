# OHOS::Camera::ICameraHost


## **概述**

**所属模块:**

[Camera](_camera.md)


## **汇总**


### Public 成员函数

  | Public&nbsp;成员函数 | 描述 | 
| -------- | -------- |
| **DECLARE_INTERFACE_DESCRIPTOR**&nbsp;(u"HDI.Camera.V1_0.Host") | IPC通信token校验。 | 
| [SetCallback](_camera.md#setcallback)&nbsp;(const&nbsp;OHOS::sptr&lt;&nbsp;[ICameraHostCallback](_o_h_o_s_1_1_camera_1_1_i_camera_host_callback.md)&nbsp;&gt;&nbsp;&amp;callback)=0 | 设置ICameraHost回调接口，回调函数参考&nbsp;[ICameraHostCallback](_o_h_o_s_1_1_camera_1_1_i_camera_host_callback.md)。&nbsp;[更多...](_camera.md#setcallback) | 
| [GetCameraIds](_camera.md#getcameraids)&nbsp;(std::vector&lt;&nbsp;std::string&nbsp;&gt;&nbsp;&amp;cameraIds)=0 | 获取当前可用的Camera设备ID列表。&nbsp;[更多...](_camera.md#getcameraids) | 
| [GetCameraAbility](_camera.md#getcameraability)&nbsp;(const&nbsp;std::string&nbsp;&amp;cameraId,&nbsp;std::shared_ptr&lt;&nbsp;CameraAbility&nbsp;&gt;&nbsp;&amp;ability)=0 | 获取Camera设备能力集合。&nbsp;[更多...](_camera.md#getcameraability) | 
| [OpenCamera](_camera.md#opencamera)&nbsp;(const&nbsp;std::string&nbsp;&amp;cameraId,&nbsp;const&nbsp;OHOS::sptr&lt;&nbsp;[ICameraDeviceCallback](_o_h_o_s_1_1_camera_1_1_i_camera_device_callback.md)&nbsp;&gt;&nbsp;&amp;callback,&nbsp;OHOS::sptr&lt;&nbsp;[ICameraDevice](_o_h_o_s_1_1_camera_1_1_i_camera_device.md)&nbsp;&gt;&nbsp;&amp;device)=0 | 打开Camera设备。&nbsp;[更多...](_camera.md#opencamera) | 
| [SetFlashlight](_camera.md#setflashlight)&nbsp;(const&nbsp;std::string&nbsp;&amp;cameraId,&nbsp;bool&nbsp;&amp;isEnable)=0 | 打开或关闭闪光灯。&nbsp;[更多...](_camera.md#setflashlight) | 


### 静态 Public 成员函数

  | 静态&nbsp;Public&nbsp;成员函数 | 描述 | 
| -------- | -------- |
| [Get](_camera.md#get)&nbsp;(const&nbsp;char&nbsp;\*serviceName) | 获取ICameraHost实例。&nbsp;[更多...](_camera.md#get) | 


## **详细描述**

Camera服务的管理类。
