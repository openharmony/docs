# Multimedia Subsystem Changelog

## cl.multimedia.1 Deprecated the muteCamera API

**Access Level**

System API

**Reason for Change**

To meet the requirements for future evolution, the **muteCamera** API in the **@ohos.multimedia.camera.d.ts** file is deprecated.

**Change Impact**

This change is a non-compatible change.

When the **muteCamera** API is used, a message is displayed, indicating that the API has been deprecated. You are advised to use the substitute API.

**Start API Level**

10

**Change Since**

OpenHarmony SDK 5.0.0.37

**Deprecated APIs/Components**

|            Deprecated API           |               Description              |           Substitute API           |
| :----------------------------: | :----------------------------------: | :---------------------------: |
| muteCamera | Replaced by **muteCameraPersistent**. | muteCameraPersistent |

**Adaptation Guide**

Change **muteCamera** to **muteCameraPersistent** during application development.

For details about how to use the new API, see [muteCameraPersistent](../../../application-dev/reference/apis-camera-kit/js-apis-camera-sys.md#mutecamerapersistent12).

## cl.multimedia.2 Deprecated the CameraPosition.CAMERA_POSITION_FOLD_INNER API

**Access Level**

Public API

**Reason for Change**

Originally, the camera position information collected applies only for some products. To meet the requirements of other products, the **CameraPosition.CAMERA_POSITION_FOLD_INNER** API in the @ohos.multimedia.camera.d.ts file is deprecated.

**Change Impact**

This change is a non-compatible change.

When the **CameraPosition.CAMERA_POSITION_FOLD_INNER** API is used, a message is displayed, indicating that the API has been deprecated. You need to make adaptations accordingly.

**Start API Level**

11

**Change Since**

OpenHarmony SDK 5.0.0.37

**Deprecated APIs/Components**

|            Deprecated API           | Description |           Substitute API           |
| :----------------------------: |:----:| :---------------------------: |
| CAMERA_POSITION_FOLD_INNER |  Deprecated. | There is no substitute API. |

**Adaptation Guide**

Solution 1: Use [display.on('foldStatusChange')](../../../application-dev/reference/apis-arkui/js-apis-display.md#displayonfoldstatuschange10) of the @ohos.display.d.ts module to listen for folding status changes of a foldable device.

When detecting such a change, use [getSupportedCameras](../../../application-dev/reference/apis-camera-kit/js-apis-camera.md#getsupportedcameras) of the @ohos.multimedia.camera.d.ts module to obtain the camera information. Then select the camera to open based on the information.

The camera information obtained by [getSupportedCameras](../../../application-dev/reference/apis-camera-kit/js-apis-camera.md#getsupportedcameras) is the same regardless of whether [FoldStatus](../../../application-dev/reference/apis-arkui/js-apis-display.md#foldstatus10) in the data returned through the callback [display.on('foldStatusChange')](../../../application-dev/reference/apis-arkui/js-apis-display.md#displayonfoldstatuschange10) is **FOLD_STATUS_HALF_FOLDED** or **FOLD_STATUS_EXPANDED**.

Solution 2: Use [CameraManager.on('foldStatusChange')](../../../application-dev/reference/apis-camera-kit/js-apis-camera.md#onfoldstatuschange12) of the @ohos.multimedia.camera.d.ts module to listen for folding status changes of a foldable device.

When detecting such a change, [FoldStatusInfo](../../../application-dev/reference/apis-camera-kit/js-apis-camera.md#foldstatusinfo12) is returned, including the folding status of the device and the list of cameras supported in this status. You can select the camera to open based on the information.