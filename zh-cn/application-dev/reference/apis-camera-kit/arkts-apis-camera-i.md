# Interfaces (其他)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## CameraDevice

相机设备信息。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                              | 类型                                  | 只读 | 可选 | 说明        |
|---------------------------------|-------------------------------------| ---- |----|---------- |
| cameraId                        | string                              | 是   | 否  | 相机ID。|
| cameraPosition                  | [CameraPosition](arkts-apis-camera-e.md#cameraposition)   | 是   | 否  | 相机位置。    |
| cameraType                      | [CameraType](arkts-apis-camera-e.md#cameratype)           | 是   | 否  | 相机类型。    |
| connectionType                  | [ConnectionType](arkts-apis-camera-e.md#connectiontype)   | 是   | 否  | 相机连接类型。 |
| cameraOrientation<sup>12+</sup> | number                              | 是   | 否  | 相机安装角度，不会随着屏幕旋转而改变，取值范围为0°-360°，单位：度。 |
| hostDeviceName<sup>15+</sup>    | string                              | 是   | 否  | 远端设备名称。若当前无远端设备，返回为空。 |
| hostDeviceType<sup>15+</sup>    | [HostDeviceType](arkts-apis-camera-e.md#hostdevicetype15) | 是   | 否  | 远端设备类型。 |

## CameraStatusInfo

相机管理器回调返回的接口实例，该实例表示相机状态信息。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称   | 类型                           |    只读   |     可选     | 说明       |
| ------ | ----------------------------- | --------- |------------ | ---------- |
| camera | [CameraDevice](arkts-apis-camera-i.md#cameradevice) |     否    |       否     | 相机信息。 |
| status | [CameraStatus](arkts-apis-camera-e.md#camerastatus) |     否    |       否     | 相机状态。 |

## FoldStatusInfo<sup>12+</sup>

相机管理器回调返回的接口实例，表示折叠机折叠状态信息。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称   | 类型                           |    只读   |     可选     | 说明       |
| ------ | ----------------------------- | --------- |------------ | ---------- |
| supportedCameras | [Array<CameraDevice\>](arkts-apis-camera-i.md#cameradevice) |     是    |       否     | 当前折叠状态所支持的相机信息列表。 |
| foldStatus | [FoldStatus](arkts-apis-camera-e.md#foldstatus12) |     是    |       否     | 折叠屏折叠状态。 |

## Profile

相机配置信息项。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称      | 类型                          | 只读 | 可选 | 说明         |
| -------- | ----------------------------- |---- | ---- | ------------- |
| format   | [CameraFormat](arkts-apis-camera-e.md#cameraformat) | 是  |  否  | 输出格式。      |
| size     | [Size](#size)                 | 是  |  否  | 分辨率。<br>设置的是相机的分辨率宽度和高度，而非实际输出图像的宽度和高度。  |

## FrameRateRange

帧率范围。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称      | 类型                          | 只读 | 可选 | 说明            |
| -------- | ----------------------------- |----- |---| -------------- |
| min      | number                        |  是  | 否 | 最小帧率，单位：fps。      |
| max      | number                        |  是  | 否 | 最大帧率，单位：fps。      |

## VideoProfile

视频配置信息项，继承[Profile](#profile)。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                       | 类型                                      | 只读 | 可选 | 说明        |
| ------------------------- | ----------------------------------------- | --- | ---- |----------- |
| frameRateRange            | [FrameRateRange](arkts-apis-camera-i.md#frameraterange)         | 是  |  否  | 帧率范围，单位：fps(frames per second)。 |

## CameraOutputCapability

相机输出能力项。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                           | 类型                                                | 只读 | 可选 | 说明                |
| ----------------------------- | --------------------------------------------------- | ---- | ---- |-------------------|
| previewProfiles               | Array\<[Profile](#profile)\>                        |  是  | 否 | 支持的预览配置信息集合。      |
| photoProfiles                 | Array\<[Profile](#profile)\>                        |  是  | 否 | 支持的拍照配置信息集合。        |
| videoProfiles                 | Array\<[VideoProfile](#videoprofile)\>              |  是  | 否 | 支持的录像配置信息集合。        |
| supportedMetadataObjectTypes  | Array\<[MetadataObjectType](arkts-apis-camera-e.md#metadataobjecttype)\>  |  是  | 否 | 支持的metadata流类型信息集合。 |

## TorchStatusInfo<sup>11+</sup>

手电筒回调返回的接口实例，表示手电筒状态信息。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称              | 类型       | 只读 | 可选 | 说明        |
| ---------------- | ---------- | ---- | ---- | ----------- |
| isTorchAvailable | boolean    | 是   | 否   | 手电筒是否可用。true表示手电筒可用，false表示手电筒不可用。|
| isTorchActive    | boolean    | 是   | 否   | 手电筒是否被激活。true表示手电筒被激活，false表示手电筒未被激活。 |
| torchLevel       | number     | 是   | 否   | 手电筒亮度等级，取值范围为[0,1]，越靠近1，亮度越大。  |

## Size

尺寸参数。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称   | 类型    | 只读 | 可选  | 说明         |
| ------ | ------ | ---- |-----| ------------ |
| height | number | 否   | 否   | 图像尺寸高(像素)。 |
| width  | number | 否   | 否   | 图像尺寸宽(像素)。 |

## Point

点坐标用于对焦和曝光配置。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称    | 类型   | 只读   | 可选   | 说明         |
| ------ | ------ | ------ | ------ | ------------ |
| x      | number | 否     | 否     | 点的x坐标。   |
| y      | number | 否     | 否     | 点的y坐标。   |

## CameraConcurrentInfo<sup>18+</sup>

相机的输出并发能力信息。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称   | 类型    | 只读 | 可选  | 说明         |
| ------ | ------ |----|-----| ------------ |
| device              | [CameraDevice](arkts-apis-camera-i.md#cameradevice)   | 是  | 否   | 相机并发设备。 |
| type                | [CameraConcurrentType](arkts-apis-camera-e.md#cameraconcurrenttype18)  | 是  | 否   | 镜头并发类型。 |
| modes               | Array\<[SceneMode](arkts-apis-camera-e.md#scenemode11) \>              | 是  | 否   | 相机支持的模式。 |
| outputCapabilities  | Array\<[CameraOutputCapability](#cameraoutputcapability) \> | 是  | 否   | 相机对应模式的输出能力集。 |

## Location

图片地理位置信息。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称          | 类型   | 只读 | 可选  |说明         |
| ------------ | ------ | ---- |-----|------------ |
| latitude     | number |  否  | 否   |纬度（度）。取值范围：[-90, 90]。    |
| longitude    | number |  否  | 否   |经度（度）。取值范围：[-180, 180]。    |
| altitude     | number |  否  | 否   |海拔（米）。    |

## PhotoCaptureSetting

拍摄照片的设置。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称      | 类型                            | 只读 | 可选 | 说明                                                                   |
| -------- | ------------------------------- | ---- | ---- |----------------------------------------------------------------------|
| quality  | [QualityLevel](arkts-apis-camera-e.md#qualitylevel)   | 否   | 是   | 图片质量（默认低）。                                                           |
| rotation | [ImageRotation](arkts-apis-camera-e.md#imagerotation) | 否   | 是   | 图片旋转角度（默认0度，顺时针旋转）。                                                  |
| location | [Location](#location)           | 否   | 是   | 图片地理位置信息（默认以设备硬件信息为准）。                                               |
| mirror   | boolean                         | 否   | 是   | 镜像使能开关（默认关）。使用之前需要使用[isMirrorSupported](arkts-apis-camera-PhotoOutput.md#ismirrorsupported)进行判断是否支持。true表示使能，false表示不使能。 |

## FrameShutterInfo

拍照帧输出信息。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称       | 类型   | 只读 | 可选 | 说明        |
| --------- | ------ | ---- | ---- | ---------- |
| captureId | number | 否   | 否   | 拍照的ID。|
| timestamp | number | 否   | 否   | 快门时间戳，单位毫秒。|

## FrameShutterEndInfo<sup>12+</sup>

拍照曝光结束信息。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称      | 类型   | 只读 | 可选 | 说明       |
| --------- | ------ | ---- | ---- | ---------- |
| captureId | number | 否   | 否   | 拍照的ID。|

## CaptureStartInfo<sup>11+</sup>

拍照开始信息。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称       | 类型    | 只读 | 可选 | 说明       |
| ---------- | ------ | ---- | ---- | --------- |
| captureId  | number | 否   | 否   | 拍照的ID。|
| time       | number | 否   | 否   | 预估的单次拍照底层出sensor采集帧时间，如果上报-1，代表没有预估时间。    |

## CaptureEndInfo

拍照停止信息。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称       | 类型    | 只读 | 可选 | 说明       |
| ---------- | ------ | ---- | ---- | ---------|
| captureId  | number | 否   | 否   | 拍照的ID。|
| frameCount | number | 否   | 否   | 帧数。|

## AutoDeviceSwitchStatus<sup>13+</sup>

自动切换镜头状态信息。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称       | 类型      | 只读 | 可选 | 说明                      |
| ---------- |---------| ---- | ---- |-------------------------|
| isDeviceSwitched  | boolean | 是   | 否   | 自动切换镜头是否成功。true表示成功，false表示失败。       |
| isDeviceCapabilityChanged | boolean  | 是   | 否   | 自动切换镜头成功后，其镜头能力值是否发生改变。true表示发生变化，false表示未发生变化。 |

## Rect

矩形定义，返回的检测点坐标系以设备充电口在右侧时的横向设备方向为基准。该坐标系左上角为（0，0），右下角为（1，1），其中（topLeftX，topLeftY）表示矩形区域的左上角坐标，width和height分别表示矩形区域的宽和高。因此在实际使用中根据业务诉求需要裁剪或者选择人脸区域时，必须将矩形区域的x坐标和y坐标分别乘以实际相机输出流的宽和高，即可得到裁剪后的人脸矩形区域。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称      | 类型   |  只读  | 可选  |           说明         |
| -------- | ------ | ------ |-----| --------------------- |
| topLeftX | number |   否   | 否   | 矩形区域左上角x坐标。   |
| topLeftY | number |   否   | 否   | 矩形区域左上角y坐标。   |
| width    | number |   否   | 否   | 矩形宽，相对值，范围[0, 1]。  |
| height   | number |   否   | 否   | 矩形高，相对值，范围[0, 1]。  |

## MetadataObject

相机元能力信息，[CameraInput](arkts-apis-camera-CameraInput.md)相机信息中的数据来源，通过metadataOutput.on('metadataObjectsAvailable')接口获取。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称         | 类型                                        | 只读 | 可选 |说明                |
| ----------- | ------------------------------------------- | ---- | ---- | ----------------- |
| type        | [MetadataObjectType](arkts-apis-camera-e.md#metadataobjecttype)   |  是  |  否  | metadata 类型。    |
| timestamp   | number                                      |  是  |  否  | 当前时间戳，单位毫秒。|
| boundingBox | [Rect](#rect)                               |  是  |  否  | metadata 区域框。  |

## SmoothZoomInfo<sup>11+</sup>

平滑变焦参数信息。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称     | 类型        |   只读   |   可选   | 说明       |
| -------- | ---------- | -------- | -------- | ---------- |
| duration |   number   |   否     |    否    | 平滑变焦总时长，单位ms。 |

## ControlCenterStatusInfo<sup>20+</sup>

相机控制器效果激活状态信息。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称     | 类型        |   只读   |   可选   | 说明       |
| -------- | ---------- | -------- | -------- | ---------- |
| effectType | [ControlCenterEffectType](arkts-apis-camera-e.md#controlcentereffecttype20) |   是    |    否    | 相机控制器效果类型。 |
| isActive | boolean | 是| 否| 相机控制器效果激活状态。true表示已激活，false表示未激活。 |