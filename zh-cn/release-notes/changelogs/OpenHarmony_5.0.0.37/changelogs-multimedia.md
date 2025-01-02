# multimedia子系统变更说明

## cl.multimedia.1 muteCamera接口废弃

**访问级别**

系统接口。

**废弃原因**

为了满足muteCamera后续演进，@ohos.multimedia.camera.d.ts文件内muteCamera接口废弃。

**废弃影响**

该变更为不兼容变更。
使用muteCamera接口会有废弃提示。建议迁移使用替代接口。

**起始 API Level**

10

**废弃发生的版本**

从OpenHarmony SDK 5.0.0.37开始。

**废弃的接口/组件**

|            接口声明            |               废弃说明               |           代替接口            |
| :----------------------------: | :----------------------------------: | :---------------------------: |
| muteCamera | 使用muteCameraPersistent替换 | muteCameraPersistent |

**适配指导**

开发者需将使用@ohos.multimedia.camera.d.ts模块muteCamera废弃接口的地方适配修改为muteCameraPersistent接口。

新接口使用指南请参考 [muteCameraPersistent](../../../application-dev/reference/apis-camera-kit/js-apis-camera-sys.md#mutecamerapersistent12)。

## cl.multimedia.2 CameraPosition.CAMERA_POSITION_FOLD_INNER接口废弃

**访问级别**

公开接口

**废弃原因**

原方案采集镜头的位置信息只能满足部分产品，为了满足其他不同形态产品，需要将@ohos.multimedia.camera.d.ts文件内CameraPosition.CAMERA_POSITION_FOLD_INNER接口废弃。

**废弃影响**

该变更为不兼容变更。
使用CameraPosition.CAMERA_POSITION_FOLD_INNER接口会有废弃提示。需要开发者进行适配。

**起始 API Level**

11

**废弃发生的版本**

从OpenHarmony SDK 5.0.0.37开始。

**废弃的接口/组件**

|            接口声明            | 废弃说明 |           代替接口            |
| :----------------------------: |:----:| :---------------------------: |
| CAMERA_POSITION_FOLD_INNER |  废弃  | 无替代接口 |

**适配指导**

方案1：开发者可以使用@ohos.display.d.ts模块的[display.on('foldStatusChange')](../../../application-dev/reference/apis-arkui/js-apis-display.md#displayonfoldstatuschange10)监听折叠屏折叠状态变化，
在监听到折叠屏折叠状态变化后需要重新通过@ohos.multimedia.camera.d.ts模块的[getSupportedCameras](../../../application-dev/reference/apis-camera-kit/js-apis-camera.md#getsupportedcameras)接口获取镜头信息，再按需选择要打开的镜头。
其中[display.on('foldStatusChange')](../../../application-dev/reference/apis-arkui/js-apis-display.md#displayonfoldstatuschange10)回调返回的数据[FoldStatus](../../../application-dev/reference/apis-arkui/js-apis-display.md#foldstatus10)为FOLD_STATUS_HALF_FOLDED或者FOLD_STATUS_EXPANDED状态时在[getSupportedCameras](../../../application-dev/reference/apis-camera-kit/js-apis-camera.md#getsupportedcameras)接口获取镜头信息是一致的

方案2：开发者可以使用@ohos.multimedia.camera.d.ts模块的[CameraManager.on('foldStatusChange')](../../../application-dev/reference/apis-camera-kit/js-apis-camera.md#onfoldstatuschange12)监听折叠屏折叠状态变化，
在监听到折叠屏折叠状态变化后会回调[FoldStatusInfo](../../../application-dev/reference/apis-camera-kit/js-apis-camera.md#foldstatusinfo12)，包含了当前设备的折叠状态和当前折叠状态所支持的相机列表信息，再按需选择要打开的镜头。

