# 驱动子系统扩展外设管理模块Changelog

## cl.usbddk.1 SendPipeRequest和SendPipeRequestWithAshmem接口行为变更

**访问级别**

公开接口

**变更原因**

调用SendPipeRequest和SendPipeRequestWithAshmem接口时，如果入参中的devMmap的bufferlen的长度大于设备的MaxPacketSize，会导致报错，但是以前接口未将错误上报，开发者无法感知。

**变更影响**

该变更为非兼容变更。

对于开发者的影响：

获得接口的真实反馈，提升开发体验。

**起始API Level**

SendPipeRequest ：API 10。

SendPipeRequestWithAshmem：API 12。

**变更发生版本**

从OpenHarmony 5.1.0.49开始。

**变更的接口/组件**

drivers/external_device_manager。

**适配指导**

只要开发者传入正确的参数，接口功能不变，因此无需开发者适配。