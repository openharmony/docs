# CameraDeviceResourceCost


## 概述

相机设备资源开销，用于**ICameraDevice::[GetResourceCost()](interface_i_camera_host_v13.md#getresourcecost)**。

**相关模块：**[Camera](_camera_v13.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| unsigned int resourceCost_ | 当前Camera设备使用总的资源，范围为[0, 100]。 | 
| String[] conflictingDevices_ | 当前相机设备打开时无法打开的相机设备ID列表。 | 
