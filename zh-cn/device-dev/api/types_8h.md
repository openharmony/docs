# types.h


## **概述**

**所属模块:**

[Camera](_camera.md)


## **汇总**


### 类

  | 类 | 描述 | 
| -------- | -------- |
| [OHOS::Camera::StreamInfo](_o_h_o_s_1_1_camera_1_1_stream_info.md) | 流信息，用于创建流时传入相关的配置参数。&nbsp;[更多...](_o_h_o_s_1_1_camera_1_1_stream_info.md) | 
| [OHOS::Camera::StreamAttribute](_o_h_o_s_1_1_camera_1_1_stream_attribute.md) | 流的属性。&nbsp;[更多...](_o_h_o_s_1_1_camera_1_1_stream_attribute.md) | 
| [OHOS::Camera::CaptureInfo](_o_h_o_s_1_1_camera_1_1_capture_info.md) | 捕获请求的相关信息。&nbsp;[更多...](_o_h_o_s_1_1_camera_1_1_capture_info.md) | 
| [OHOS::Camera::CaptureEndedInfo](_o_h_o_s_1_1_camera_1_1_capture_ended_info.md) | 捕获结束相关信息，用于捕获结束回调&nbsp;**OnCaptureEnded**。&nbsp;[更多...](_o_h_o_s_1_1_camera_1_1_capture_ended_info.md) | 
| [OHOS::Camera::CaptureErrorInfo](_o_h_o_s_1_1_camera_1_1_capture_error_info.md) | 流错误信息，用于回调&nbsp;**OnCaptureError**。&nbsp;[更多...](_o_h_o_s_1_1_camera_1_1_capture_error_info.md) | 


### 类型定义

  | 类型定义 | 描述 | 
| -------- | -------- |
| **OHOS::Camera::CameraAbility**&nbsp;=&nbsp;CameraMetadata | Camera设备能力集合。 | 
| **OHOS::Camera::CameraSetting**&nbsp;=&nbsp;CameraMetadata | Camera设置参数，包括sensor帧率，3A相关参数等。 | 
| **OHOS::Camera::MetaType**&nbsp;=&nbsp;int32_t | 整型。 | 


### 枚举

  | 枚举 | 描述 | 
| -------- | -------- |
| [OHOS::Camera::CamRetCode](_camera.md#camretcode)&nbsp;:&nbsp;int32_t&nbsp;{&nbsp;&nbsp;&nbsp;[OHOS::Camera::NO_ERROR](_camera.md#gga9ecee2f0e6599644dc440c9e1c553b80aac4124a539038c0eb9752f19bd41db9a)&nbsp;=&nbsp;0,&nbsp;[OHOS::Camera::CAMERA_BUSY](_camera.md#gga9ecee2f0e6599644dc440c9e1c553b80a6d812337e14eb19f8afb2e70f3aad1a0)&nbsp;=&nbsp;-1,&nbsp;[OHOS::Camera::INSUFFICIENT_RESOURCES](_camera.md#gga9ecee2f0e6599644dc440c9e1c553b80a7250a9e68d64f0804d92f99e8cbc1e7e)&nbsp;=&nbsp;-2,&nbsp;[OHOS::Camera::INVALID_ARGUMENT](_camera.md#gga9ecee2f0e6599644dc440c9e1c553b80a9cfb72153a13ecf08abb34d59bec2223)&nbsp;=&nbsp;-3,&nbsp;&nbsp;&nbsp;[OHOS::Camera::METHOD_NOT_SUPPORTED](_camera.md#gga9ecee2f0e6599644dc440c9e1c553b80ae66837f5eefe837cf5777083e1aaadcc)&nbsp;=&nbsp;-4,&nbsp;[OHOS::Camera::CAMERA_CLOSED](_camera.md#gga9ecee2f0e6599644dc440c9e1c553b80a0322e66dfb3b398ead3bd50c823415cd)&nbsp;=&nbsp;-5,&nbsp;[OHOS::Camera::DEVICE_ERROR](_camera.md#gga9ecee2f0e6599644dc440c9e1c553b80a2b74d8a616b4360eec8826d9810c03c0)&nbsp;=&nbsp;-6&nbsp;} | HDI接口的返回值。&nbsp;[更多...](_camera.md#camretcode) | 
| [OHOS::Camera::ResultCallbackMode](_camera.md#resultcallbackmode)&nbsp;:&nbsp;int32_t&nbsp;{&nbsp;[OHOS::Camera::PER_FRAME](_camera.md#gga0290782009631708fe5351c54f019353a25a4a7cc14577e328d08dd1a758f784c),&nbsp;[OHOS::Camera::ON_CHANGED](_camera.md#gga0290782009631708fe5351c54f019353ab84abaca84197e5e75dc1210519ea37c)&nbsp;} | metadata的上报模式。&nbsp;[更多...](_camera.md#resultcallbackmode) | 
| [OHOS::Camera::OperationMode](_camera.md#operationmode)&nbsp;:&nbsp;int32_t&nbsp;{&nbsp;[OHOS::Camera::NORMAL](_camera.md#ggac397708a7aefbcf48c8a32b8af367ffda66a457d6883b55722bda11ac9a47e4dd)&nbsp;=&nbsp;0&nbsp;} | 流的使用模式。&nbsp;[更多...](_camera.md#operationmode) | 
| [OHOS::Camera::StreamIntent](_camera.md#streamintent)&nbsp;:&nbsp;int32_t&nbsp;{&nbsp;&nbsp;&nbsp;[OHOS::Camera::PREVIEW](_camera.md#gga2b195a400dc0113b8185900ddc231c19a2ec888585737101c7bc133d302e4ce0a)&nbsp;=&nbsp;0,&nbsp;[OHOS::Camera::VIDEO](_camera.md#gga2b195a400dc0113b8185900ddc231c19ad480442d11e56ef84ac7018df5637b6a)&nbsp;=&nbsp;1,&nbsp;[OHOS::Camera::STILL_CAPTURE](_camera.md#gga2b195a400dc0113b8185900ddc231c19a5898656f053185f8a374bc35cbd4d784)&nbsp;=&nbsp;2,&nbsp;[OHOS::Camera::POST_VIEW](_camera.md#gga2b195a400dc0113b8185900ddc231c19a67891a15f68cdc23c2b1bb6fdfe2d72f)&nbsp;=&nbsp;3,&nbsp;&nbsp;&nbsp;[OHOS::Camera::ANALYZE](_camera.md#gga2b195a400dc0113b8185900ddc231c19a817268e94893ff41b8a03147dfbbc94b)&nbsp;=&nbsp;4,&nbsp;[OHOS::Camera::CUSTOM](_camera.md#gga2b195a400dc0113b8185900ddc231c19a4ca8b162608a384d4335d04a56ac3e72)&nbsp;=&nbsp;5&nbsp;} | 流的类型。&nbsp;[更多...](_camera.md#streamintent) | 
| [OHOS::Camera::EncodeType](_camera.md#encodetype)&nbsp;:&nbsp;int32_t&nbsp;{&nbsp;[OHOS::Camera::ENCODE_TYPE_NULL](_camera.md#gga57d3c5974b8119b90f6f43592bd4b1d1af72ea69717272db8b03c0d2281c2f221)&nbsp;=&nbsp;0,&nbsp;[OHOS::Camera::ENCODE_TYPE_H264](_camera.md#gga57d3c5974b8119b90f6f43592bd4b1d1a6d21ce4760d97641e66c9a6a58df6105)&nbsp;=&nbsp;1,&nbsp;[OHOS::Camera::ENCODE_TYPE_H265](_camera.md#gga57d3c5974b8119b90f6f43592bd4b1d1a60e25172afdb6ca5f18db408485c1cdf)&nbsp;=&nbsp;2,&nbsp;[OHOS::Camera::ENCODE_TYPE_JPEG](_camera.md#gga57d3c5974b8119b90f6f43592bd4b1d1a1cf15a45d92fa0eae74c778f09d4bae7)&nbsp;=&nbsp;3&nbsp;} | 流数据的编码类型。&nbsp;[更多...](_camera.md#encodetype) | 
| [OHOS::Camera::StreamSupportType](_camera.md#streamsupporttype)&nbsp;:&nbsp;int32_t&nbsp;{&nbsp;[OHOS::Camera::DYNAMIC_SUPPORTED](_camera.md#gga2de5b91b51f744902c071f89d9302d56a96466427b9427c04c0a9f9a74e21b222),&nbsp;[OHOS::Camera::RE_CONFIGURED_REQUIRED](_camera.md#gga2de5b91b51f744902c071f89d9302d56afb9ebd5b0f7137f06e0b636247e7419e),&nbsp;[OHOS::Camera::NOT_SUPPORTED](_camera.md#gga2de5b91b51f744902c071f89d9302d56a5e0d17d563241a98d968bbdb5facf05e)&nbsp;} | 动态配置流的切换方式，使用场景参考&nbsp;[IsStreamsSupported](_camera.md#isstreamssupported)&nbsp;。&nbsp;[更多...](_camera.md#streamsupporttype) | 
| [OHOS::Camera::CameraStatus](_camera.md#camerastatus)&nbsp;{&nbsp;[OHOS::Camera::UN_AVAILABLE](_camera.md#ggac2c065c30743f0053f460a6683845dadaefabd193aca6ec50ad022c4003b079bd)&nbsp;=&nbsp;0,&nbsp;[OHOS::Camera::AVAILABLE](_camera.md#ggac2c065c30743f0053f460a6683845dada41bd9156c9456c38aa47cf0b8b2486a2)&nbsp;=&nbsp;1&nbsp;} | Camera设备状态。&nbsp;[更多...](_camera.md#camerastatus) | 
| [OHOS::Camera::FlashlightStatus](_camera.md#flashlightstatus)&nbsp;:&nbsp;uint32_t&nbsp;{&nbsp;[OHOS::Camera::FLASHLIGHT_OFF](_camera.md#gga1a82bc94cb6ff38f7fd0dfcffab71df3a624df2112053caa6316c6ee443758d1a)&nbsp;=&nbsp;0,&nbsp;[OHOS::Camera::FLASHLIGHT_ON](_camera.md#gga1a82bc94cb6ff38f7fd0dfcffab71df3a9f360d5fdf77e2f7c1c123f3ba45bc0c)&nbsp;=&nbsp;1,&nbsp;[OHOS::Camera::FLASHLIGHT_UNAVAILABLE](_camera.md#gga1a82bc94cb6ff38f7fd0dfcffab71df3a7fae7a9c7a791d240f3b6f6399988e8c)&nbsp;=&nbsp;2&nbsp;} | 闪光灯状态。&nbsp;[更多...](_camera.md#flashlightstatus) | 
| [OHOS::Camera::CameraEvent](_camera.md#cameraevent)&nbsp;:&nbsp;uint32_t&nbsp;{&nbsp;[OHOS::Camera::CAMERA_EVENT_DEVICE_ADD](_camera.md#gga14253812c3a39d52d827589bf5e5b970a85028d1dd16bef4b3f60e9543f2c89d8)&nbsp;=&nbsp;0,&nbsp;[OHOS::Camera::CAMERA_EVENT_DEVICE_RMV](_camera.md#gga14253812c3a39d52d827589bf5e5b970a715b664103cdf584fb48ed5e7c591c06)&nbsp;=&nbsp;1&nbsp;} | Camera事件。&nbsp;[更多...](_camera.md#cameraevent) | 
| [OHOS::Camera::ErrorType](_camera.md#errortype)&nbsp;:&nbsp;uint32_t&nbsp;{&nbsp;[OHOS::Camera::FATAL_ERROR](_camera.md#gga4d1b650185695d9df8652593a7bc522dad0dde9e602d14d5b583be24c5014f998)&nbsp;=&nbsp;0,&nbsp;[OHOS::Camera::REQUEST_TIMEOUT](_camera.md#gga4d1b650185695d9df8652593a7bc522da2b8e229bcb457de66e7b2882502a4df6)&nbsp;=&nbsp;1&nbsp;} | 设备错误类型，用于设备错误回调&nbsp;**OnError**。&nbsp;[更多...](_camera.md#errortype) | 
| [OHOS::Camera::StreamError](_camera.md#streamerror)&nbsp;{&nbsp;[OHOS::Camera::UNKNOWN_ERROR](_camera.md#gga376e6d566c73ec98e29b7dd93763aee6ae724e09ec34e66e49c86734ceffa2a26)&nbsp;=&nbsp;0,&nbsp;[OHOS::Camera::BUFFER_LOST](_camera.md#gga376e6d566c73ec98e29b7dd93763aee6a9300ec08f81b121b74ec589fca815952)&nbsp;=&nbsp;1&nbsp;} | 流错误类型，用于流错误类型&nbsp;**CaptureErrorInfo**。&nbsp;[更多...](_camera.md#streamerror) | 


## **详细描述**

Camera模块HDI接口使用的数据类型。

**Since：**

1.0

**Version：**

1.0
