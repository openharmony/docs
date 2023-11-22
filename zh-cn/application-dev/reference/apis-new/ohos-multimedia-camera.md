# @ohos.multimedia.camera    
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import camera from '@ohos.multimedia.camera'    
```  
    
## getCameraManager    
获取相机管理器实例，同步返回结果。  
 **调用形式：**     
- getCameraManager(context: Context): CameraManager  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| context | Context | true | 应用上下文。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| CameraManager |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400101 | Parameter missing or parameter type incorrect |  
| 7400201 | Camera service fatal error. |  
    
 **示例代码：**   
```js    
import common from '@ohos.app.ability.common';  
import { BusinessError } from '@ohos.base';  
  
function getCameraManager(context: common.BaseContext): camera.CameraManager | undefined {  
  let cameraManager: camera.CameraManager | undefined = undefined;  
  try {  
    cameraManager = camera.getCameraManager(context);  
  } catch (error) {  
    let err = error as BusinessError;  
    console.error(`The getCameraManager call failed. error code: ${err.code}`);  
  }  
  return cameraManager;  
}  
    
```    
  
    
## CameraStatus    
枚举，相机状态。    
    
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| CAMERA_STATUS_APPEAR | 0 | 新的相机出现。 |  
| CAMERA_STATUS_DISAPPEAR | 1 | 相机被移除。 |  
| CAMERA_STATUS_AVAILABLE | 2 | 相机可用。 |  
| CAMERA_STATUS_UNAVAILABLE | 3 | 相机不可用。 |  
    
## Profile    
相机配置信息项。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| format | CameraFormat | true | true | 输出格式。 |  
| size | Size | true | true | 分辨率。 |  
    
## FrameRateRange    
帧率范围。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| min | number | true | true | 最小帧率。 |  
| max | number | true | true | 最大帧率。 |  
    
## VideoProfile    
视频配置信息项。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| frameRateRange | FrameRateRange | true | true | 帧率范围，fps(frames per second)。 |  
    
## CameraOutputCapability    
相机输出能力项。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| previewProfiles | Array<Profile> | true | true | 支持的预览配置信息。 |  
| photoProfiles | Array<Profile> | true | true | 支持的拍照配置信息。 |  
| videoProfiles | Array<VideoProfile> | true | true | 支持的录像配置信息。 |  
| supportedMetadataObjectTypes | Array<MetadataObjectType> | true | true | 支持的metadata流类型信息。 |  
    
## CameraErrorCode    
相机错误码。接口使用不正确以及on接口监听error状态返回。    
    
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| INVALID_ARGUMENT | 7400101 | 参数缺失或者参数类型不对。 |  
| OPERATION_NOT_ALLOWED | 7400102 | 操作流程不对，不允许。 |  
| SESSION_NOT_CONFIG | 7400103 | session 未配置返回。 |  
| SESSION_NOT_RUNNING | 7400104 | session 未运行返回。 |  
| SESSION_CONFIG_LOCKED | 7400105 | session 配置已锁定返回。 |  
| DEVICE_SETTING_LOCKED | 7400106 | 设备设置已锁定返回。 |  
| CONFLICT_CAMERA | 7400107 | 设备重复打开返回。 |  
| DEVICE_DISABLED | 7400108 | 安全原因摄像头被禁用。 |  
| DEVICE_PREEMPTED | 7400109 | 相机被抢占导致无法使用 |  
| SERVICE_FATAL_ERROR | 7400201 | 相机服务错误返回。 |  
    
## CameraManager    
相机管理器类，使用前需要通过getCameraManager获取相机管理实例。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
### getSupportedCameras    
获取支持指定的相机设备对象，同步返回结果。  
 **调用形式：**     
- getSupportedCameras(): Array\<CameraDevice>  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<CameraDevice> | 相机设备列表。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
function getSupportedCameras(cameraManager: camera.CameraManager): Array<camera.CameraDevice> {  
  let cameras: Array<camera.CameraDevice> = [];  
  try {  
    cameras = cameraManager.getSupportedCameras();  
  } catch (error) {  
    let err = error as BusinessError;  
    console.error(`The getSupportedCameras call failed. error code: ${err.code}`);  
  }  
  return cameras;  
}  
    
```    
  
    
### getSupportedOutputCapability    
获取指定模式下相机设备支持的输出能力，同步返回结果。  
 **调用形式：**     
- getSupportedOutputCapability(camera: CameraDevice): CameraOutputCapability  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| camera | CameraDevice | true | 相机设备，通过 getSupportedCameras 接口获取。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| CameraOutputCapability | 相机输出能力。 |  
    
 **示例代码：**   
```ts    
<span style="font-size: 14px; letter-spacing: 0px;">function getSupportedOutputCapability(cameraDevice: camera.CameraDevice, cameraManager: camera.CameraManager): camera.CameraOutputCapability {</span>  
  let cameraOutputCapability: camera.CameraOutputCapability = cameraManager.getSupportedOutputCapability(cameraDevice);  
  return cameraOutputCapability;  
}    
```    
  
    
### isCameraMuted    
查询相机当前的禁用状态（禁用/未禁用）。在此之前，需要通过[isCameraMuteSupported](#iscameramutesupported)确认当前设备支持禁用相机。  
 **调用形式：**     
- isCameraMuted(): boolean  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示相机被禁用，返回false表示相机未被禁用。 |  
    
 **示例代码：**   
```ts    
function isCameraMuted(cameraManager: camera.CameraManager): boolean {  
  let isMuted: boolean = cameraManager.isCameraMuted();  
  return isMuted;  
}  
    
```    
  
    
### createCameraInput    
使用CameraDevice对象创建CameraInput实例，同步返回结果。  
 **调用形式：**     
- createCameraInput(camera: CameraDevice): CameraInput  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core  
 **需要权限：** ohos.permission.CAMERA    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| camera | CameraDevice | true | CameraDevice对象，通过 getSupportedCameras 接口获取 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| CameraInput | CameraInput实例。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400101 | Parameter missing or parameter type incorrect |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
function createCameraInput(cameraDevice: camera.CameraDevice, cameraManager: camera.CameraManager): camera.CameraInput | undefined {  
  let cameraInput: camera.CameraInput | undefined = undefined;  
  try {  
    cameraInput = cameraManager.createCameraInput(cameraDevice);  
  } catch (error) {  
    // 失败返回错误码error.code并处理  
    let err = error as BusinessError;  
    console.error(`The createCameraInput call failed. error code: ${err.code}`);  
  }  
  return cameraInput;  
}  
    
```    
  
    
### createCameraInput  
 **调用形式：**     
- createCameraInput(position: CameraPosition, type: CameraType): CameraInput  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core  
 **需要权限：** ohos.permission.CAMERA    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| position | CameraPosition | true | 相机位置，通过 getSupportedCameras 接口获取设备，然后获取设备位置信息 |  
| type | CameraType | true | 相机类型，通过 getSupportedCameras 接口获取设备，然后获取设备类型信息 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| CameraInput | CameraInput实例。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400101 | Parameter missing or parameter type incorrect |  
    
### createPreviewOutput    
创建预览输出对象，同步返回结果。  
 **调用形式：**     
- createPreviewOutput(profile: Profile, surfaceId: string): PreviewOutput  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| profile | Profile | true | 支持的预览配置信息,通过getSupportedOutputCapability接口获取。 |  
| surfaceId | string | true | 从[XComponent](../arkui-ts/ts-basic-components-xcomponent.md)或者[ImageReceiver](js-apis-image.md#imagereceiver9)组件获取的surfaceId。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| PreviewOutput | PreviewOutput实例。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400101 | Parameter missing or parameter type incorrect |  
    
 **示例代码：**   
```ts    
function createPreviewOutput(cameraOutputCapability: camera.CameraOutputCapability, cameraManager: camera.CameraManager, surfaceId: string): camera.PreviewOutput | undefined {  
  let profile: camera.Profile = cameraOutputCapability.previewProfiles[0];  
  let previewOutput: camera.PreviewOutput | undefined = undefined;  
  try {  
    previewOutput = cameraManager.createPreviewOutput(profile, surfaceId);  
  } catch (error) {  
    // 失败返回错误码error.code并处理  
    let err = error as BusinessError;  
    console.log(`The createPreviewOutput call failed. error code: ${err.code}`);  
  }  
  return previewOutput;  
}  
    
```    
  
    
### createPhotoOutput    
创建拍照输出对象，同步返回结果。  
 **调用形式：**     
- createPhotoOutput(profile: Profile, surfaceId: string): PhotoOutput  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| profile | Profile | true | 支持的拍照配置信息，通过getSupportedOutputCapability接口获取。 |  
| surfaceId | string | true | 从[ImageReceiver](js-apis-image.md#imagereceiver9)获取的surfaceId。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| PhotoOutput | PhotoOutput实例。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400101 | Parameter missing or parameter type incorrect |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
function createPhotoOutput(cameraOutputCapability: camera.CameraOutputCapability, cameraManager: camera.CameraManager, surfaceId: string): camera.PhotoOutput | undefined {  
  let profile: camera.Profile = cameraOutputCapability.photoProfiles[0];  
  let photoOutput: camera.PhotoOutput | undefined = undefined;  
  try {  
    photoOutput = cameraManager.createPhotoOutput(profile, surfaceId);  
  } catch (error) {  
    // 失败返回错误码error.code并处理  
    let err = error as BusinessError;  
    console.log(`The createPhotoOutput call failed. error code: ${err.code}`);  
  }  
  return photoOutput;  
}  
    
```    
  
    
### createVideoOutput    
创建录像输出对象，同步返回结果。  
 **调用形式：**     
- createVideoOutput(profile: VideoProfile, surfaceId: string): VideoOutput  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| profile | VideoProfile | true | 支持的录像配置信息，通过getSupportedOutputCapability接口获取。 |  
| surfaceId | string | true | 从[VideoRecorder](js-apis-media.md#videorecorder9)获取的surfaceId。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| VideoOutput | VideoOutput实例。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400101 | Parameter missing or parameter type incorrect |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
function createVideoOutput(cameraOutputCapability: camera.CameraOutputCapability, cameraManager: camera.CameraManager, surfaceId: string): camera.VideoOutput | undefined {  
  let profile: camera.VideoProfile = cameraOutputCapability.videoProfiles[0];  
  let videoOutput: camera.VideoOutput | undefined = undefined;  
  try {  
    videoOutput = cameraManager.createVideoOutput(profile, surfaceId);  
  } catch (error) {  
    // 失败返回错误码error.code并处理  
    let err = error as BusinessError;  
    console.log(`The createPhotoOutput call failed. error code: ${err.code}`);  
  }  
  return videoOutput;  
}  
    
```    
  
    
### createMetadataOutput    
创建metadata流输出对象，同步返回结果。  
 **调用形式：**     
- createMetadataOutput(metadataObjectTypes: Array\<MetadataObjectType>): MetadataOutput  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| metadataObjectTypes | Array<MetadataObjectType> | true | metadata流类型信息，通过getSupportedOutputCapability接口获取。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| MetadataOutput | MetadataOutput实例。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400101 | Parameter missing or parameter type incorrect |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
function createMetadataOutput(cameraManager: camera.CameraManager, cameraOutputCapability: camera.CameraOutputCapability): void {  
  let metadataObjectTypes: Array<camera.MetadataObjectType> = cameraOutputCapability.supportedMetadataObjectTypes;  
  let metadataOutput: camera.MetadataOutput | undefined = undefined;  
  try {  
    metadataOutput = cameraManager.createMetadataOutput(metadataObjectTypes);  
  } catch (error) {  
    // 失败返回错误码error.code并处理  
    let err = error as BusinessError;  
    console.log(`createMetadataOutput error. error code: ${err.code}`);  
  }  
}  
    
```    
  
    
### createCaptureSession    
创建CaptureSession实例，通过注册回调函数获取结果。  
 **调用形式：**     
- createCaptureSession(): CaptureSession  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| CaptureSession | CaptureSession实例。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400201 | Camera service fatal error. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
function createCaptureSession(cameraManager: camera.CameraManager): camera.CaptureSession | undefined {  
  let captureSession: camera.CaptureSession | undefined = undefined;  
  try {  
    captureSession = cameraManager.createCaptureSession();  
  } catch (error) {  
    // 失败返回错误码error.code并处理  
    let err = error as BusinessError;  
    console.log(`createCaptureSession error. error code: ${err.code}`);  
  }  
  return captureSession;  
}  
    
```    
  
    
### on('cameraStatus')    
相机设备状态回调，通过注册回调函数获取相机的状态变化。  
 **调用形式：**     
    
- on(type: 'cameraStatus', callback: AsyncCallback\<CameraStatusInfo>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'cameraStatus'。cameraManager对象获取成功后可监听。目前只支持对设备打开或者关闭会触发该事件并返回对应信息 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，用于获取镜头状态变化信息。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
function registerCameraStatus(cameraManager: camera.CameraManager): void {  
  cameraManager.on('cameraStatus', (err: BusinessError, cameraStatusInfo: camera.CameraStatusInfo) => {  
    console.log(`camera : ${cameraStatusInfo.camera.cameraId}`);  
    console.log(`status: ${cameraStatusInfo.status}`);  
  });  
}  
    
```    
  
    
### off('cameraStatus')    
相机设备状态回调，通过注册回调函数获取相机的状态变化。  
 **调用形式：**     
    
- off(type: 'cameraStatus', callback?: AsyncCallback\<CameraStatusInfo>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'cameraStatus'。cameraManager对象获取成功后可监听。目前只支持对设备打开或者关闭会触发该事件并返回对应信息 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，用于获取镜头状态变化信息。 |  
    
 **示例代码：**   
示例代码（callback）：  
```null    
function unregisterCameraStatus(cameraManager: camera.CameraManager): void {  
  cameraManager.off('cameraStatus');  
}  
    
```    
  
    
## CameraStatusInfo    
相机管理器回调返回的接口实例，表示相机状态信息。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| camera | CameraDevice | false | true | 相机信息。 |  
| status | CameraStatus | false | true | 相机状态。 |  
    
## CameraPosition    
枚举，相机位置。    
    
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| CAMERA_POSITION_UNSPECIFIED | 0 | 相机位置未指定。 |  
| CAMERA_POSITION_BACK | 1 | 后置相机。 |  
| CAMERA_POSITION_FRONT | 2 | 前置相机。 |  
    
## CameraType    
枚举，相机类型。    
    
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| CAMERA_TYPE_DEFAULT | 0 | 相机类型未指定。 |  
| CAMERA_TYPE_WIDE_ANGLE | 1 | 广角相机。 |  
| CAMERA_TYPE_ULTRA_WIDE | 2 | 超广角相机。 |  
| CAMERA_TYPE_TELEPHOTO | 3 | 长焦相机。 |  
| CAMERA_TYPE_TRUE_DEPTH | 4 | 带景深信息的相机。 |  
    
## ConnectionType    
枚举，相机连接类型。    
    
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| CAMERA_CONNECTION_BUILT_IN | 0 | 内置相机。 |  
| CAMERA_CONNECTION_USB_PLUGIN | 1 | USB连接的相机。 |  
| CAMERA_CONNECTION_REMOTE | 2 | 远程连接的相机。 |  
    
## CameraDevice    
相机设备信息。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| cameraId | string | true | true | CameraDevice对象 |  
| cameraPosition | CameraPosition | true | true | 相机位置。 |  
| cameraType | CameraType | true | true | 相机类型。 |  
| connectionType | ConnectionType | true | true | <span style="letter-spacing: 0px;">相机连接类型。</span> |  
    
## Size    
枚举，输出能力查询。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| height | number | false | true | 图像尺寸高(像素)。 |  
| width | number | false | true | 图像尺寸宽(像素)。 |  
    
## Point    
枚举，点坐标用于对焦、曝光配置。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| x | number | false | true | 点的x坐标。 |  
| y | number | false | true | 点的y坐标。 |  
    
## CameraInput    
会话中[CaptureSession](#capturesession)使用的相机信息。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
### open    
打开相机，通过注册回调函数获取状态。  
 **调用形式：**     
    
- open(callback: AsyncCallback\<void>): void    
起始版本： 10    
- open(): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，用于获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400107 | Can not use camera cause of conflict. |  
| 7400108 | Camera disabled cause of security reason. |  
| 7400201 | Camera service fatal error. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
function openCameraInput(cameraInput: camera.CameraInput): void {  
  cameraInput.open((err: BusinessError) => {  
    if (err) {  
      console.error(`Failed to open the camera. ${err.code}`);  
      return;  
    }  
    console.log('Callback returned with camera opened.');  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
function openCameraInput(cameraInput: camera.CameraInput): void {  
  cameraInput.open().then(() => {  
    console.log('Promise returned with camera opened.');  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to open the camera. ${err.code}`);  
  });  
}  
    
```    
  
    
### close    
关闭相机，通过Promise获取状态。  
 **调用形式：**     
    
- close(callback: AsyncCallback\<void>): void    
起始版本： 10    
- close(): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，用于获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
| Promise<void> | 使用Promise的方式获取结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400201 | Camera service fatal error. |  
    
 **示例代码1：**   
示例代码（callback）：  
```null    
import { BusinessError } from '@ohos.base';  
  
function closeCameraInput(cameraInput: camera.CameraInput): void {  
  cameraInput.close((err: BusinessError) => {  
    if (err) {  
      console.error(`Failed to close the cameras. ${err.code}`);  
      return;  
    }  
    console.log('Callback returned with camera closed.');  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
function closeCameraInput(cameraInput: camera.CameraInput): void {  
  cameraInput.close().then(() => {  
    console.log('Promise returned with camera closed.');  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to close the cameras. ${err.code}`);  
  });  
}  
    
```    
  
    
### on('error')    
监听CameraInput的错误事件，通过注册回调函数获取结果。  
 **调用形式：**     
    
- on(type: 'error', camera: CameraDevice, callback: ErrorCallback): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'error'，CameraInput对象创建成功可监听。相机设备出错情况下可触发该事件并返回结果，比如（设备不可用或者冲突等返回对应错误信息） |  
| camera | CameraDevice | true | CameraDevice对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
function registerCameraInputError(cameraInput: camera.CameraInput, cameraDevice: camera.CameraDevice): void {  
  cameraInput.on('error', cameraDevice, (error: BusinessError) => {  
    console.log(`Camera input error code: ${error.code}`);  
  });  
}  
    
```    
  
    
### off('error')    
注销监听CameraInput的错误事件。  
 **调用形式：**     
    
- off(type: 'error', camera: CameraDevice, callback?: ErrorCallback): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'error'，CameraInput对象创建成功可监听。相机设备出错情况下可触发该事件并返回结果，比如（设备不可用或者冲突等返回对应错误信息）。 |  
| camera | CameraDevice | true | CameraDevice对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，可选，有就是匹配on('error') callback |  
    
 **示例代码：**   
```ts    
function unregisterCameraInputError(cameraInput: camera.CameraInput, cameraDevice: camera.CameraDevice): void {  
  cameraInput.off('error', cameraDevice);  
}  
    
```    
  
    
## CameraFormat    
枚举，输出格式。    
    
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| CAMERA_FORMAT_RGBA_8888 | 3 | RGB格式的图片。 |  
| CAMERA_FORMAT_YUV_420_SP | 1003 | YUV 420 SP格式的图片。 |  
| CAMERA_FORMAT_JPEG | 2000 | JPEG格式的图片。 |  
    
## FlashMode    
枚举，闪光灯模式。    
    
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| FLASH_MODE_CLOSE | 0 | 闪光灯关闭。 |  
| FLASH_MODE_OPEN | 1 | 闪光灯打开。 |  
| FLASH_MODE_AUTO | 2 | 自动闪光灯。 |  
| FLASH_MODE_ALWAYS_OPEN | 3 | 闪光灯常亮。 |  
    
## ExposureMode    
枚举，曝光模式。    
    
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| EXPOSURE_MODE_LOCKED | 0 | 锁定曝光模式。不支持曝光区域中心点设置。 |  
| EXPOSURE_MODE_AUTO | 1 | 自动曝光模式。支持曝光区域中心点设置，可以使用[setMeteringPoint](#setmeteringpoint)设置曝光区域中心点。 |  
| EXPOSURE_MODE_CONTINUOUS_AUTO | 2 | 连续自动曝光。不支持曝光区域中心点设置。 |  
    
## FocusMode    
枚举，焦距模式。    
    
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| FOCUS_MODE_MANUAL | 0 | 手动对焦。通过手动修改相机焦距来改变对焦位置，不支持对焦点设置。 |  
| FOCUS_MODE_CONTINUOUS_AUTO | 1 | 连续自动对焦。不支持对焦点设置。 |  
| FOCUS_MODE_AUTO | 2 | 自动对焦。支持对焦点设置，可以使用[setFocusPoint](#setfocuspoint)设置对焦点，根据对焦点执行一次自动对焦。对焦动作完成后（无论对焦成功或是对焦失败），都进入对焦锁定。应用层需要再次调用CONTINUOUS_AUTO后才能再次进入连续自动对焦。 |  
| FOCUS_MODE_LOCKED | 3 | 对焦锁定。不支持对焦点设置。 |  
    
## FocusState    
枚举，焦距状态。    
    
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| FOCUS_STATE_SCAN | 0 | 触发对焦。 |  
| FOCUS_STATE_FOCUSED | 1 | 对焦成功。 |  
| FOCUS_STATE_UNFOCUSED | 2 | 未完成对焦。 |  
    
## VideoStabilizationMode    
枚举，视频防抖模式。    
    
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| OFF | 0 | 关闭视频防抖功能。 |  
| LOW | 1 | 使用基础防抖算法。 |  
| MIDDLE | 2 | 使用防抖效果一般的防抖算法，防抖效果优于LOW类型。 |  
| HIGH | 3 | 使用防抖效果最好的防抖算法，防抖效果优于MIDDLE类型。 |  
| AUTO | 4 | 自动进行选择。 |  
    
## CaptureSession    
拍照会话类，保存一次相机运行所需要的所有资源[CameraInput](#camerainput)、[CameraOutput](#cameraoutput)，并向相机设备申请完成相机功能(录像，拍照)。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
### beginConfig    
开始配置会话。  
 **调用形式：**     
- beginConfig(): void  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400105 | Session config locked. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
function beginConfig(captureSession: camera.CaptureSession): void {  
  try {  
    captureSession.beginConfig();  
  } catch (error) {  
    // 失败返回错误码error.code并处理  
    let err = error as BusinessError;  
    console.error(`The beginConfig call failed. error code: ${err.code}`);  
  }  
}  
    
```    
  
    
### commitConfig    
提交配置信息，通过注册回调函数获取结果。  
 **调用形式：**     
    
- commitConfig(callback: AsyncCallback\<void>): void    
起始版本： 10    
- commitConfig(): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，用于获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
| Promise<void> | 使用Promise的方式获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400102 | Operation not allow. |  
| 7400201 | Camera service fatal error. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
function commitConfig(captureSession: camera.CaptureSession): void {  
  captureSession.commitConfig((err: BusinessError) => {  
    if (err) {  
      console.error(`The commitConfig call failed. error code: ${err.code}`);  
      return;  
    }  
    console.log('Callback invoked to indicate the commit config success.');  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（paromise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
function commitConfig(captureSession: camera.CaptureSession): void {  
  captureSession.commitConfig().then(() => {  
    console.log('Promise returned to indicate the commit config success.');  
  }).catch((err: BusinessError) => {  
    // 失败返回错误码error.code并处理  
    console.error(`The commitConfig call failed. error code: ${err.code}`);  
  });  
}  
    
```    
  
    
### addInput    
把[CameraInput](#camerainput)加入到会话。  
 **调用形式：**     
- addInput(cameraInput: CameraInput): void  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| cameraInput | CameraInput | true | 需要添加的CameraInput实例。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400101 | Parameter missing or parameter type incorrect |  
| 7400102 | Operation not allow. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
function addInput(captureSession: camera.CaptureSession, cameraInput: camera.CameraInput): void {  
  try {  
    captureSession.addInput(cameraInput);  
  } catch (error) {  
    // 失败返回错误码error.code并处理  
    let err = error as BusinessError;  
    console.log(`The addInput call failed. error code: ${err.code}`);  
  }  
}  
    
```    
  
    
### removeInput    
移除[CameraInput](#camerainput)。  
 **调用形式：**     
- removeInput(cameraInput: CameraInput): void  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| cameraInput | CameraInput | true | 需要移除的CameraInput实例。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400101 | Parameter missing or parameter type incorrect |  
| 7400102 | Operation not allow. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
function removeInput(captureSession: camera.CaptureSession, cameraInput: camera.CameraInput): void {  
  try {  
    captureSession.removeInput(cameraInput);  
  } catch (error) {  
    // 失败返回错误码error.code并处理  
    let err = error as BusinessError;  
    console.log(`The removeInput call failed. error code: ${err.code}`);  
  }  
}  
    
```    
  
    
### addOutput    
把[CameraOutput](#cameraoutput)加入到会话。  
 **调用形式：**     
- addOutput(cameraOutput: CameraOutput): void  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| cameraOutput | CameraOutput | true | 需要添加的CameraOutput实例。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400101 | Parameter missing or parameter type incorrect |  
| 7400102 | Operation not allow. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
function addOutput(captureSession: camera.CaptureSession, cameraOutput: camera.CameraOutput): void {  
  try {  
    captureSession.addOutput(cameraOutput);  
  } catch (error) {  
    // 失败返回错误码error.code并处理  
    let err = error as BusinessError;  
    console.log(`The addOutput call failed. error code: ${err.code}`);  
  }  
}  
    
```    
  
    
### removeOutput    
从会话中移除[CameraOutput](#cameraoutput)。  
 **调用形式：**     
- removeOutput(cameraOutput: CameraOutput): void  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| cameraOutput | CameraOutput | true | 需要移除的CameraOutput实例。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400101 | Parameter missing or parameter type incorrect |  
| 7400102 | Operation not allow. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
function removeOutput(captureSession: camera.CaptureSession, previewOutput: camera.PreviewOutput): void {  
  try {  
    captureSession.removeOutput(previewOutput);  
  } catch (error) {  
    // 失败返回错误码error.code并处理  
    let err = error as BusinessError;  
    console.log(`The removeOutput call failed. error code: ${err.code}`);  
  }  
}  
    
```    
  
    
### start    
开始会话工作，通过注册回调函数获取结果。  
 **调用形式：**     
    
- start(callback: AsyncCallback\<void>): void    
起始版本： 10    
- start(): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，用于获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
| Promise<void> | 使用Promise的方式获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400103 | Session not config. |  
| 7400201 | Camera service fatal error. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
function startCaptureSession(captureSession: camera.CaptureSession): void {  
  captureSession.start((err: BusinessError) => {  
    if (err) {  
      console.error(`Failed to start the session ${err.code}`);  
      return;  
    }  
    console.log('Callback invoked to indicate the session start success.');  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
function startCaptureSession(captureSession: camera.CaptureSession): void {  
  captureSession.start().then(() => {  
    console.log('Promise returned to indicate the session start success.');  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to start the session ${err.code}`);  
  });  
}  
    
```    
  
    
### stop    
停止输出预览流，通过注册回调函数获取结果。  
 **调用形式：**     
    
- stop(callback: AsyncCallback\<void>): void    
起始版本： 10    
- stop(): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400201 |  |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
function stopCaptureSession(captureSession: camera.CaptureSession): void {  
  captureSession.stop((err: BusinessError) => {  
    if (err) {  
      console.error(`Failed to stop the session ${err.code}`);  
      return;  
    }  
    console.log('Callback invoked to indicate the session stop success.');  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
function stopCaptureSession(captureSession: camera.CaptureSession): void {  
  captureSession.stop().then(() => {  
    console.log('Promise returned to indicate the session stop success.');  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to stop the session ${err.code}`);  
  });  
}  
    
```    
  
    
### release    
释放输出资源，通过注册回调函数获取结果。  
 **调用形式：**     
    
- release(callback: AsyncCallback\<void>): void    
起始版本： 10    
- release(): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，用于获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
| Promise<void> | 使用Promise的方式获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400201 | Camera service fatal error. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
function releaseCaptureSession(captureSession: camera.CaptureSession): void {  
  captureSession.release((err: BusinessError) => {  
    if (err) {  
      console.error(`Failed to release the CaptureSession instance ${err.code}`);  
      return;  
    }  
    console.log('Callback invoked to indicate that the CaptureSession instance is released successfully.');  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
function releaseCaptureSession(captureSession: camera.CaptureSession): void {  
  captureSession.release().then(() => {  
    console.log('Promise returned to indicate that the CaptureSession instance is released successfully.');  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to release the CaptureSession instance ${err.code}`);  
  });  
}  
    
```    
  
    
### hasFlash    
检测是否有闪光灯，通过注册回调函数获取结果。  
 **调用形式：**     
- hasFlash(): boolean  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示设备支持闪光灯。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400103 | Session not config. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
function hasFlash(captureSession: camera.CaptureSession): boolean {  
  let status: boolean = false;  
  try {  
    status = captureSession.hasFlash();  
  } catch (error) {  
    // 失败返回错误码error.code并处理  
    let err = error as BusinessError;  
    console.error(`The hasFlash call failed. error code: ${err.code}`);  
  }  
  return status;  
}  
    
```    
  
    
### isFlashModeSupported    
检测闪光灯模式是否支持。  
 **调用形式：**     
- isFlashModeSupported(flashMode: FlashMode): boolean  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| flashMode | FlashMode | true | 指定闪光灯模式。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示支持该闪光灯模式。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400103 | Session not config. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
function isFlashModeSupported(captureSession: camera.CaptureSession): boolean {  
  let status: boolean = false;  
  try {  
    status = captureSession.isFlashModeSupported(camera.FlashMode.FLASH_MODE_AUTO);  
  } catch (error) {  
    // 失败返回错误码error.code并处理  
    let err = error as BusinessError;  
    console.error(`The isFlashModeSupported call failed. error code: ${err.code}`);  
  }  
  return status;  
}  
    
```    
  
    
### getFlashMode    
<span style="letter-spacing: 0px;">获取当前设备的闪光灯模式。</span>  
 **调用形式：**     
- getFlashMode(): FlashMode  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| FlashMode | 获取当前设备的闪光灯模式。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400103 | Session not config. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
function getFlashMode(captureSession: camera.CaptureSession): camera.FlashMode | undefined {  
  let flashMode: camera.FlashMode | undefined = undefined;  
  try {  
    flashMode = captureSession.getFlashMode();  
  } catch (error) {  
    // 失败返回错误码error.code并处理  
    let err = error as BusinessError;  
    console.error(`The getFlashMode call failed.error code: ${err.code}`);  
  }  
  return flashMode;  
}  
    
```    
  
    
### setFlashMode    
设置闪光灯模式。  
 **调用形式：**     
- setFlashMode(flashMode: FlashMode): void  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| flashMode | FlashMode | true | 指定闪光灯模式。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400103 | Session not config. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
function setFlashMode(captureSession: camera.CaptureSession): void {  
  try {  
    captureSession.setFlashMode(camera.FlashMode.FLASH_MODE_AUTO);  
  } catch (error) {  
    // 失败返回错误码error.code并处理  
    let err = error as BusinessError;  
    console.error(`The setFlashMode call failed. error code: ${err.code}`);  
  }  
}  
    
```    
  
    
### isExposureModeSupported    
检测曝光模式是否支持。  
 **调用形式：**     
- isExposureModeSupported(aeMode: ExposureMode): boolean  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| aeMode | ExposureMode | true | 曝光模式。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 获取是否支持曝光模式。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400103 | Session not config. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
function isExposureModeSupported(captureSession: camera.CaptureSession): boolean {  
  let isSupported: boolean = false;  
  try {  
    isSupported = captureSession.isExposureModeSupported(camera.ExposureMode.EXPOSURE_MODE_LOCKED);  
  } catch (error) {  
    // 失败返回错误码error.code并处理  
    let err = error as BusinessError;  
    console.error(`The isExposureModeSupported call failed. error code: ${err.code}`);  
  }  
  return isSupported;  
}  
    
```    
  
    
### getExposureMode    
获取当前曝光模式。  
 **调用形式：**     
- getExposureMode(): ExposureMode  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ExposureMode | 获取当前曝光模式。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400103 | Session not config. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
function getExposureMode(captureSession: camera.CaptureSession): camera.ExposureMode | undefined {  
  let exposureMode: camera.ExposureMode | undefined = undefined;  
  try {  
    exposureMode = captureSession.getExposureMode();  
  } catch (error) {  
    // 失败返回错误码error.code并处理  
    let err = error as BusinessError;  
    console.error(`The getExposureMode call failed. error code: ${err.code}`);  
  }  
  return exposureMode;  
}  
    
```    
  
    
### setExposureMode  
 **调用形式：**     
- setExposureMode(aeMode: ExposureMode): void  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| aeMode | ExposureMode | true | 曝光模式。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400103 | Session not config. |  
    
 **示例代码：**   
设置曝光模式。进行设置之前，需要先检查设备是否支持指定的曝光模式，可使用方法[isExposureModeSupported](#isexposuremodesupported)。  
```ts    
import { BusinessError } from '@ohos.base';  
  
function setExposureMode(captureSession: camera.CaptureSession): void {  
  try {  
    captureSession.setExposureMode(camera.ExposureMode.EXPOSURE_MODE_LOCKED);  
  } catch (error) {  
    // 失败返回错误码error.code并处理  
    let err = error as BusinessError;  
    console.error(`The setExposureMode call failed. error code: ${err.code}`);  
  }  
}  
    
```    
  
    
### getMeteringPoint  
 **调用形式：**     
- getMeteringPoint(): Point  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Point | 获取当前曝光点。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400103 | Session not config. |  
    
 **示例代码：**   
查询曝光区域中心点。（该接口目前为预留，将在3.2版本开放）  
```ts    
import { BusinessError } from '@ohos.base';  
  
function getMeteringPoint(captureSession: camera.CaptureSession): camera.Point | undefined {  
  let exposurePoint: camera.Point | undefined = undefined;  
  try {  
    exposurePoint = captureSession.getMeteringPoint();  
  } catch (error) {  
    // 失败返回错误码error.code并处理  
    let err = error as BusinessError;  
    console.error(`The getMeteringPoint call failed. error code: ${err.code}`);  
  }  
  return exposurePoint;  
}  
    
```    
  
    
### setMeteringPoint    
设置曝光区域中心点，曝光点应在0-1坐标系内，该坐标系左上角为{0，0}，右下角为{1，1}。此坐标系是以设备充电口在右侧时的横向设备方向为基准的，例如应用的预览界面布局以设备充电口在下侧时的竖向方向为基准，布局宽高为{w，h}，且触碰点为{x，y}，则转换后的坐标点为{y/h，1-x/w}。  
 **调用形式：**     
- setMeteringPoint(point: Point): void  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| point | Point | true | <span style="letter-spacing: 0px;">曝光点，x,y设置范围应在[0,1]之内，超过范围，如果小于0设置0，大于1设置1。</span> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400103 | Session not config. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
function setMeteringPoint(captureSession: camera.CaptureSession): void {  
  const exposurePoint: camera.Point = {x: 1, y: 1};  
  try {  
    captureSession.setMeteringPoint(exposurePoint);  
  } catch (error) {  
    // 失败返回错误码error.code并处理  
    let err = error as BusinessError;  
    console.error(`The setMeteringPoint call failed. error code: ${err.code}`);  
  }  
}  
    
```    
  
    
### getExposureBiasRange    
查询曝光补偿范围。  
  
 **调用形式：**     
- getExposureBiasRange(): Array\<number>  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<number> | 获取补偿范围的数组。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400103 | Session not config. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
function getExposureBiasRange(captureSession: camera.CaptureSession): Array<number> {  
  let biasRangeArray: Array<number> = [];  
  try {  
    biasRangeArray = captureSession.getExposureBiasRange();  
  } catch (error) {  
    // 失败返回错误码error.code并处理  
    let err = error as BusinessError;  
    console.error(`The getExposureBiasRange call failed. error code: ${err.code}`);  
  }  
  return biasRangeArray;  
}  
    
```    
  
    
### setExposureBias    
设置曝光补偿，曝光补偿值（EV）。进行设置之前，建议先通过方法[getExposureBiasRange](#getexposurebiasrange)查询支持的范围。  
 **调用形式：**     
- setExposureBias(exposureBias: number): void  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| exposureBias | number | true | 曝光补偿，getExposureBiasRange查询支持的范围，如果设置超过支持范围的值，自动匹配到就近临界点。曝光补偿存在步长，如步长为0.5。则设置1.2时，获取到实际生效曝光补偿为1.0。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)， |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400103 | Session not config. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
function setExposureBias(captureSession: camera.CaptureSession, biasRangeArray: Array<number>): void {  
  if (biasRangeArray  biasRangeArray.length > 0) {  
    let exposureBias = biasRangeArray[0];  
    try {  
      captureSession.setExposureBias(exposureBias);  
    } catch (error) {  
      // 失败返回错误码error.code并处理  
      let err = error as BusinessError;  
      console.error(`The setExposureBias call failed. error code: ${err.code}`);  
    }  
  }  
}  
    
```    
  
    
### getExposureValue    
查询当前曝光值。  
 **调用形式：**     
- getExposureValue(): number  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 获取曝光值。曝光补偿存在步长，如步长为0.5。则设置1.2时，获取到实际生效曝光补偿为1.0。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400103 | Session not config. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
function getExposureValue(captureSession: camera.CaptureSession): number {  
  const invalid_value: number = -1;  
  let exposureValue: number = invalid_value;  
  try {  
    exposureValue = captureSession.getExposureValue();  
  } catch (error) {  
    // 失败返回错误码error.code并处理  
    let err = error as BusinessError;  
    console.error(`The getExposureValue call failed. error code: ${err.code}`);  
  }  
  return exposureValue;  
}  
    
```    
  
    
### isFocusModeSupported    
检测对焦模式是否支持。  
 **调用形式：**     
- isFocusModeSupported(afMode: FocusMode): boolean  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| afMode | FocusMode | true | 指定的焦距模式。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示支持该焦距模式。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400103 | Session not config. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
function isFocusModeSupported(captureSession: camera.CaptureSession): boolean {  
  let status: boolean = false;  
  try {  
    status = captureSession.isFocusModeSupported(camera.FocusMode.FOCUS_MODE_AUTO);  
  } catch (error) {  
    // 失败返回错误码error.code并处理  
    let err = error as BusinessError;  
    console.error(`The isFocusModeSupported call failed. error code: ${err.code}`);  
  }  
  return status;  
}  
    
```    
  
    
### getFocusMode    
获取当前的对焦模式。  
  
 **调用形式：**     
- getFocusMode(): FocusMode  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| FocusMode | 获取当前设备的焦距模式。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400103 | Session not config. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
function getFocusMode(captureSession: camera.CaptureSession): camera.FocusMode | undefined {  
  let afMode: camera.FocusMode | undefined = undefined;  
  try {  
    afMode = captureSession.getFocusMode();  
  } catch (error) {  
    // 失败返回错误码error.code并处理  
    let err = error as BusinessError;  
    console.error(`The getFocusMode call failed. error code: ${err.code}`);  
  }  
  return afMode;  
}  
    
```    
  
    
### setFocusMode    
设置对焦模式。进行设置之前，需要先检查设备是否支持指定的焦距模式，可使用方法[isFocusModeSupported](#isfocusmodesupported)。  
 **调用形式：**     
- setFocusMode(afMode: FocusMode): void  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| afMode | FocusMode | true | 指定的焦距模式。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400103 | Session not config. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
function setFocusMode(captureSession: camera.CaptureSession): void {  
  try {  
    captureSession.setFocusMode(camera.FocusMode.FOCUS_MODE_AUTO);  
  } catch (error) {  
    // 失败返回错误码error.code并处理  
    let err = error as BusinessError;  
    console.error(`The setFocusMode call failed. error code: ${err.code}`);  
  }  
}  
    
```    
  
    
### setFocusPoint    
设置焦点，焦点应在0-1坐标系内，该坐标系左上角为{0，0}，右下角为{1，1}。此坐标系是以设备充电口在右侧时的横向设备方向为基准的，例如应用的预览界面布局以设备充电口在下侧时的竖向方向为基准，布局宽高为{w，h}，且触碰点为{x，y}，则转换后的坐标点为{y/h，1-x/w}。  
 **调用形式：**     
- setFocusPoint(point: Point): void  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| point | Point | true | 焦点。x,y设置范围应在[0,1]之内，超过范围，如果小于0设置0，大于1设置1。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400103 | Session not config. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
function setFocusPoint(captureSession: camera.CaptureSession): void {  
  const focusPoint: camera.Point = {x: 1, y: 1};  
  try {  
    captureSession.setFocusPoint(focusPoint);  
  } catch (error) {  
    // 失败返回错误码error.code并处理  
    let err = error as BusinessError;  
    console.error(`The setFocusPoint call failed. error code: ${err.code}`);  
  }  
}  
    
```    
  
    
### getFocusPoint    
查询焦点。  
  
 **调用形式：**     
- getFocusPoint(): Point  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Point | 用于获取当前焦点。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400103 | Session not config. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
function getFocusPoint(captureSession: camera.CaptureSession): camera.Point | undefined {  
  let point: camera.Point | undefined = undefined;  
  try {  
    point = captureSession.getFocusPoint();  
  } catch (error) {  
    // 失败返回错误码error.code并处理  
    let err = error as BusinessError;  
    console.error(`The getFocusPoint call failed. error code: ${err.code}`);  
  }  
  return point;  
}  
    
```    
  
    
### getFocalLength    
查询焦距值。  
 **调用形式：**     
- getFocalLength(): number  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 用于获取当前焦距。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400103 | Session not config. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
function getFocalLength(captureSession: camera.CaptureSession): number {  
  const invalid_value: number = -1;  
  let focalLength: number = invalid_value;  
  try {  
    focalLength = captureSession.getFocalLength();  
  } catch (error) {  
    // 失败返回错误码error.code并处理  
    let err = error as BusinessError;  
    console.error(`The getFocalLength call failed. error code: ${err.code}`);  
  }  
  return focalLength;  
}  
    
```    
  
    
### getZoomRatioRange    
获取支持的变焦范围。  
 **调用形式：**     
- getZoomRatioRange(): Array\<number>  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<number> | 用于获取可变焦距比范围，返回的数组包括其最小值和最大值。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400103 | Session not config. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
function getZoomRatioRange(captureSession: camera.CaptureSession): Array<number> {  
  let zoomRatioRange: Array<number> = [];  
  try {  
    zoomRatioRange = captureSession.getZoomRatioRange();  
  } catch (error) {  
    // 失败返回错误码error.code并处理  
    let err = error as BusinessError;  
    console.error(`The getZoomRatioRange call failed. error code: ${err.code}`);  
  }  
  return zoomRatioRange;  
}  
    
```    
  
    
### getZoomRatio    
获取当前的变焦比。  
  
 **调用形式：**     
- getZoomRatio(): number  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 获取当前的变焦比结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400103 | Session not config. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
function getZoomRatio(captureSession: camera.CaptureSession): number {  
  const invalid_value: number = -1;  
  let zoomRatio: number = invalid_value;  
  try {  
    zoomRatio = captureSession.getZoomRatio();  
  } catch (error) {  
    // 失败返回错误码error.code并处理  
    let err = error as BusinessError;  
    console.error(`The getZoomRatio call failed. error code: ${err.code}`);  
  }  
  return zoomRatio;  
}  
    
```    
  
    
### setZoomRatio    
设置变焦比，变焦精度最高为小数点后两位，超过变焦精度的变焦值系统无法响应。  
 **调用形式：**     
- setZoomRatio(zoomRatio: number): void  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| zoomRatio | number | true | 可变焦距比，通过getZoomRatioRange获取支持的变焦范围，如果设置超过支持范围的值，自动匹配到就近临界点。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400103 | 接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
function setZoomRatio(captureSession: camera.CaptureSession, zoomRatioRange: Array<number>): void {  
  if (zoomRatioRange === undefined || zoomRatioRange.length <= 0) {  
    return;  
  }  
  let zoomRatio = zoomRatioRange[0];  
  try {  
    captureSession.setZoomRatio(zoomRatio);  
  } catch (error) {  
    // 失败返回错误码error.code并处理  
    let err = error as BusinessError;  
    console.error(`The setZoomRatio call failed. error code: ${err.code}`);  
  }  
}  
    
```    
  
    
### isVideoStabilizationModeSupported    
查询是否支持指定的视频防抖模式。  
 **调用形式：**     
- isVideoStabilizationModeSupported(vsMode: VideoStabilizationMode): boolean  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| vsMode | VideoStabilizationMode | true | 视频防抖模式。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回视频防抖模式是否支持。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400103 | Session not config. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
function isVideoStabilizationModeSupported(captureSession: camera.CaptureSession): boolean {  
  let isSupported: boolean = false;  
  try {  
    isSupported = captureSession.isVideoStabilizationModeSupported(camera.VideoStabilizationMode.OFF);  
  } catch (error) {  
    // 失败返回错误码error.code并处理  
    let err = error as BusinessError;  
    console.error(`The isVideoStabilizationModeSupported call failed. error code: ${err.code}`);  
  }  
  return isSupported;  
}  
    
```    
  
    
### getActiveVideoStabilizationMode    
查询当前正在使用的视频防抖模式。  
 **调用形式：**     
- getActiveVideoStabilizationMode(): VideoStabilizationMode  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| VideoStabilizationMode | 视频防抖是否正在使用。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400103 | Session not config. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
function getActiveVideoStabilizationMode(captureSession: camera.CaptureSession): camera.VideoStabilizationMode | undefined {  
  let vsMode: camera.VideoStabilizationMode | undefined = undefined;  
  try {  
    vsMode = captureSession.getActiveVideoStabilizationMode();  
  } catch (error) {  
    // 失败返回错误码error.code并处理  
    let err = error as BusinessError;  
    console.error(`The getActiveVideoStabilizationMode call failed. error code: ${err.code}`);  
  }  
  return vsMode;  
}  
    
```    
  
    
### setVideoStabilizationMode    
设置视频防抖模式。需要先检查设备是否支持对应的防抖模式，可以通过[isVideoStabilizationModeSupported](#isvideostabilizationmodesupported)方法判断所设置的模式是否支持。  
 **调用形式：**     
- setVideoStabilizationMode(mode: VideoStabilizationMode): void  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mode | VideoStabilizationMode | true | 需要设置的视频防抖模式。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400103 | Session not config. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
function setVideoStabilizationMode(captureSession: camera.CaptureSession): void {  
  try {  
    captureSession.setVideoStabilizationMode(camera.VideoStabilizationMode.OFF);  
  } catch (error) {  
    // 失败返回错误码error.code并处理  
    let err = error as BusinessError;  
    console.error(`The setVideoStabilizationMode call failed. error code: ${err.code}`);  
  }  
}  
    
```    
  
    
### on('focusStateChange')    
监听相机聚焦的状态变化，通过注册回调函数获取结果。  
 **调用形式：**     
    
- on(type: 'focusStateChange', callback: AsyncCallback\<FocusState>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'focusStateChange'，session 创建成功可监听。仅当自动对焦模式时,且相机对焦状态发生改变时可触发该事件 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，用于获取当前对焦状态。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
function registerFocusStateChange(captureSession: camera.CaptureSession): void {  
  captureSession.on('focusStateChange', (err: BusinessError, focusState: camera.FocusState) => {  
    console.log(`Focus state: ${focusState}`);  
  });  
}  
    
```    
  
    
### off('focusStateChange')    
监听相机聚焦的状态变化，通过注册回调函数获取结果。  
 **调用形式：**     
    
- off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'focusStateChange'，session 创建成功可监听。仅当自动对焦模式时,且相机对焦状态发生改变时可触发该事件 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，用于获取当前对焦状态。 |  
    
 **示例代码：**   
示例代码（promise）：  
```ts    
function unregisterFocusStateChange(captureSession: camera.CaptureSession): void {  
  captureSession.off('focusStateChange');  
}  
    
```    
  
    
### on('error')    
监听拍照会话的错误事件，通过注册回调函数获取结果。  
 **调用形式：**     
    
- on(type: 'error', callback: ErrorCallback): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'error'，session创建成功之后可监听该接口。session调用相关接口出现错误时会触发该事件，比如调用（beginConfig()，commitConfig()，addInput）等接口发生错误时返回错误信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，用于获取错误信息。返回错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
function registerCaptureSessionError(captureSession: camera.CaptureSession): void {  
  captureSession.on('error', (error: BusinessError) => {  
    console.log(`Capture session error code: ${error.code}`);  
  });  
}  
    
```    
  
    
### off('error')    
监听拍照会话的错误事件，通过注册回调函数获取结果。  
 **调用形式：**     
    
- off(type: 'error', callback?: ErrorCallback): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'error'，session创建成功之后可监听该接口。session调用相关接口出现错误时会触发该事件，比如调用（beginConfig()，commitConfig()，addInput）等接口发生错误时返回错误信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，用于获取错误信息。返回错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
<span style="font-size: 14px; letter-spacing: 0px;">function unregisterCaptureSessionError(captureSession: camera.CaptureSession): void {</span>  
  captureSession.off('error');  
}    
```    
  
    
## CameraOutput    
会话中[CaptureSession](#capturesession)使用的输出信息，output的基类。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
### release  
 **调用形式：**     
    
- release(callback: AsyncCallback\<void>): void    
起始版本： 10    
- release(): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400201 |  |  
    
## PreviewOutput    
预览输出类。继承[CameraOutput](#cameraoutput)。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
### start    
启动录制，通过注册回调函数获取结果。  
 **调用形式：**     
    
- start(callback: AsyncCallback\<void>): void    
起始版本： 10    
- start(): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，用于获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400103 | Session not config. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
function startPreviewOutput(previewOutput: camera.PreviewOutput): void {  
  previewOutput.start((err: BusinessError) => {  
    if (err) {  
      console.error(`Failed to start the previewOutput. ${err.code}`);  
      return;  
    }  
    console.log('Callback returned with previewOutput started.');  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
function startPreviewOutput(previewOutput: camera.PreviewOutput): void {  
  previewOutput.start().then(() => {  
    console.log('Promise returned with previewOutput started.');  
  }).catch((err: BusinessError) => {  
    console.log('Failed to previewOutput start '+ err.code);  
  });  
}  
    
```    
  
    
### stop    
结束录制，通过注册回调函数获取结果。  
 **调用形式：**     
    
- stop(callback: AsyncCallback\<void>): void    
起始版本： 10    
- stop(): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，用于获取结果。 |  
| Promise<void> | 使用Promise的方式获取结果。 |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
function stopPreviewOutput(previewOutput: camera.PreviewOutput): void {  
  previewOutput.stop((err: BusinessError) => {  
    if (err) {  
      console.error(`Failed to stop the previewOutput. ${err.code}`);  
      return;  
    }  
    console.log('Callback returned with previewOutput stopped.');  
  })  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
function stopPreviewOutput(previewOutput: camera.PreviewOutput): void {  
  previewOutput.stop().then(() => {  
    console.log('Callback returned with previewOutput stopped.');  
  }).catch((err: BusinessError) => {  
    console.log('Failed to previewOutput stop '+ err.code);  
  });  
}  
    
```    
  
    
### on('frameStart')    
监听录像开始，通过注册回调函数获取结果。  
 **调用形式：**     
    
- on(type: 'frameStart', callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'frameStart'，videoOutput创建成功后可监听。底层第一次曝光时触发该事件并返回。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，用于获取结果。  只要有该事件返回就证明录像开始 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
function registerPreviewOutputFrameStart(previewOutput: camera.PreviewOutput): void {  
  previewOutput.on('frameStart', () => {  
    console.log('Preview frame started');  
  });  
}  
    
```    
  
    
### off('frameStart')    
注销监听录像开始。  
 **调用形式：**     
    
- off(type: 'frameStart', callback?: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'frameStart'，videoOutput创建成功后可监听。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，可选 |  
    
 **示例代码：**   
示例代码（promise）：  
```ts    
function unregisterPreviewOutputFrameStart(previewOutput: camera.PreviewOutput): void {  
  previewOutput.off('frameStart');  
}  
    
```    
  
    
### on('frameEnd')    
监听录像结束，通过注册回调函数获取结果。  
 **调用形式：**     
    
- on(type: 'frameEnd', callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'frameEnd'，videoOutput创建成功后可监听。录像完全结束最后一帧时触发该事件并返回 。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，用于获取结果。 只要有该事件返回就证明录像结束 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
function registerPreviewOutputFrameEnd(previewOutput: camera.PreviewOutput): void {  
  previewOutput.on('frameEnd', () => {  
    console.log('Preview frame ended');  
  });  
}  
    
```    
  
    
### off('frameEnd')    
监听录像结束，通过注册回调函数获取结果。  
 **调用形式：**     
    
- off(type: 'frameEnd', callback?: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'frameEnd'，videoOutput创建成功后可监听。录像完全结束最后一帧时触发该事件并返回 。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，用于获取结果。 只要有该事件返回就证明录像结束 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
function unregisterPreviewOutputFrameEnd(previewOutput: camera.PreviewOutput): void {  
  previewOutput.off('frameEnd');  
}  
    
```    
  
    
### on('error')    
监听录像输出发生错误，通过注册回调函数获取结果。  
 **调用形式：**     
    
- on(type: 'error', callback: ErrorCallback): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'error'，videoOutput创建成功后可监听。录像接口调用出现错误时触发该事件并返回对应错误码,比如调用（start(),release()）接口时出现错误返回对应错误信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，用于获取错误信息。返回错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
function registerPreviewOutputError(previewOutput: camera.PreviewOutput): void {  
  previewOutput.on('error', (previewOutputError: BusinessError) => {  
    console.log(`Preview output error code: ${previewOutputError.code}`);  
  })  
}  
    
```    
  
    
### off('error')    
监听metadata流的错误，通过注册回调函数获取结果。  
 **调用形式：**     
    
- off(type: 'error', callback?: ErrorCallback): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'error'，metadataOutput创建成功后可监听。metadata接口使用错误时触发该事件并返回对应错误码，比如调用（start（），release（））接口时发生错误返回对应错误信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，用于获取错误信息。返回错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
    
 **示例代码：**   
示例代码（callback）：  
```null    
function unregisterPreviewOutputError(previewOutput: camera.PreviewOutput): void {  
  previewOutput.off('error');  
}  
    
```    
  
    
## ImageRotation    
枚举，图片旋转角度。    
    
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| ROTATION_0 | 0 | 图片旋转0度。 |  
| ROTATION_90 | 90 | 图片旋转90度。 |  
| ROTATION_180 | 180 | 图片旋转180度。 |  
| ROTATION_270 | 270 | 图片旋转270度。 |  
    
## Location    
图片地理位置信息。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| latitude | number | false | true | 纬度(度)。 |  
| longitude | number | false | true | 经度(度)。 |  
| altitude | number | false | true | 海拔(米)。 |  
    
## QualityLevel    
枚举，图片质量。    
    
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| QUALITY_LEVEL_HIGH | 0 | 图片质量高。 |  
| QUALITY_LEVEL_MEDIUM | 1 | 图片质量中等。 |  
| QUALITY_LEVEL_LOW | 2 | 图片质量差。 |  
    
## PhotoCaptureSetting    
拍摄照片的设置。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| quality | QualityLevel | false | false | 图片质量。 |  
| rotation | ImageRotation | false | false | 图片旋转角度。 |  
| location | Location | false | false | 图片地理位置信息。 |  
| mirror | boolean | false | false | 镜像使能开关(默认关)。 |  
    
## PhotoOutput    
拍照会话中使用的输出信息，继承[CameraOutput](#cameraoutput)  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
### capture    
以默认设置触发一次拍照，通过Promise获取结果。  
 **调用形式：**     
    
- capture(callback: AsyncCallback\<void>): void    
起始版本： 10    
- capture(): Promise\<void>    
起始版本： 10    
- capture(setting: PhotoCaptureSetting, callback: AsyncCallback\<void>): void    
起始版本： 10    
- capture(setting?: PhotoCaptureSetting): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| setting | PhotoCaptureSetting | true | 拍照设置。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，用于获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400104 | Session not running. |  
| 7400201 | Camera service fatal error. |  
| 7400101 | Parameter missing or parameter type incorrect |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
function capture(photoOutput: camera.PhotoOutput): void {  
  photoOutput.capture((err: BusinessError) => {  
    if (err) {  
      console.error(`Failed to capture the photo ${err.code}`);  
      return;  
    }  
    console.log('Callback invoked to indicate the photo capture request success.');  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
function capture(photoOutput: camera.PhotoOutput): void {  
  photoOutput.capture().then(() => {  
    console.log('Promise returned to indicate that photo capture request success.');  
  }).catch((err: BusinessError) => {  
    console.log('Failed to photoOutput capture '+ err.code);  
  });  
}  
    
```    
  
    
### isMirrorSupported    
查询是否支持镜像拍照。  
 **调用形式：**     
- isMirrorSupported(): boolean  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回是否支持镜像拍照。 |  
    
 **示例代码：**   
```ts    
function isMirrorSupported(photoOutput: camera.PhotoOutput): boolean {  
  let isSupported: boolean = photoOutput.isMirrorSupported();  
  return isSupported;  
}  
    
```    
  
    
### on('captureStart')    
监听拍照开始，通过注册回调函数获取Capture ID。  
 **调用形式：**     
    
- on(type: 'captureStart', callback: AsyncCallback\<number>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'captureStart'，photoOutput创建成功后可监听。每次拍照，底层开始曝光时触发该事件并返回。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 使用callback的方式获取Capture ID。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
function registerPhotoOutputCaptureStart(photoOutput: camera.PhotoOutput): void {  
  photoOutput.on('captureStart', (err: BusinessError, captureId: number) => {  
    console.log(`photo capture stated, captureId : ${captureId}`);  
  });  
}  
    
```    
  
    
### off('captureStart')    
监听拍照开始，通过注册回调函数获取Capture ID。  
 **调用形式：**     
    
- off(type: 'captureStart', callback?: AsyncCallback\<number>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'captureStart'，photoOutput创建成功后可监听。每次拍照，底层开始曝光时触发该事件并返回。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 使用callback的方式获取Capture ID。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
function unregisterPhotoOutputCaptureStart(photoOutput: camera.PhotoOutput): void {  
  photoOutput.off('captureStart');  
}  
    
```    
  
    
### on('frameShutter')    
监听拍照帧输出捕获，通过注册回调函数获取结果。  
 **调用形式：**     
    
- on(type: 'frameShutter', callback: AsyncCallback\<FrameShutterInfo>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'frameShutter'，photoOutput创建成功后可监听。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，用于获取相关信息。该回调返回意味着可以再次下发拍照请求。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
function registerPhotoOutputFrameShutter(photoOutput: camera.PhotoOutput): void {  
  photoOutput.on('frameShutter', (err: BusinessError, frameShutterInfo: camera.FrameShutterInfo) => {  
    console.log(`photo capture end, captureId : ${frameShutterInfo.captureId}`);  
    console.log(`Timestamp for frame : ${frameShutterInfo.timestamp}`);  
  });  
}  
    
```    
  
    
### off('frameShutter')    
监听拍照帧输出捕获，通过注册回调函数获取结果。  
 **调用形式：**     
    
- off(type: 'frameShutter', callback?: AsyncCallback\<FrameShutterInfo>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'frameShutter'，photoOutput创建成功后可监听。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，用于获取相关信息。该回调返回意味着可以再次下发拍照请求。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
function unregisterPhotoOutputFrameShutter(photoOutput: camera.PhotoOutput): void {  
  photoOutput.off('frameShutter');  
}  
    
```    
  
    
### on('captureEnd')    
监听拍照结束，通过注册回调函数获取结果。  
 **调用形式：**     
    
- on(type: 'captureEnd', callback: AsyncCallback\<CaptureEndInfo>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'captureEnd'，photoOutput创建成功后可监听。拍照完全结束可触发该事件发生并返回相应信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，用于获取相关信息。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
function registerPhotoOutputCaptureEnd(photoOutput: camera.PhotoOutput): void {  
  photoOutput.on('captureEnd', (err: BusinessError, captureEndInfo: camera.CaptureEndInfo) => {  
    console.log(`photo capture end, captureId : ${captureEndInfo.captureId}`);  
    console.log(`frameCount : ${captureEndInfo.frameCount}`);  
  });  
}  
    
```    
  
    
### off('captureEnd')    
注销监听拍照结束。  
 **调用形式：**     
    
- off(type: 'captureEnd', callback?: AsyncCallback\<CaptureEndInfo>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'captureEnd'，photoOutput创建成功后可监听。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，可选。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
function unregisterPhotoOutputCaptureEnd(photoOutput: camera.PhotoOutput): void {  
  photoOutput.off('captureEnd');  
}  
    
```    
  
    
### on('error')    
监听拍照输出发生错误，通过注册回调函数获取结果。  
 **调用形式：**     
    
- on(type: 'error', callback: ErrorCallback): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'error'，photoOutput创建成功后可监听。拍照接口调用时出现错误触发该事件并返回错误信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，用于获取错误信息。返回错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
function registerPhotoOutputError(photoOutput: camera.PhotoOutput): void {  
  photoOutput.on('error', (error: BusinessError) => {  
    console.log(`Photo output error code: ${error.code}`);  
  });  
}  
    
```    
  
    
### off('error')    
监听拍照输出发生错误，通过注册回调函数获取结果。  
 **调用形式：**     
    
- off(type: 'error', callback?: ErrorCallback): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'error'，photoOutput创建成功后可监听。拍照接口调用时出现错误触发该事件并返回错误信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，用于获取错误信息。返回错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
function unregisterPhotoOutputError(photoOutput: camera.PhotoOutput): void {  
  photoOutput.off('error');  
}  
    
```    
  
    
## FrameShutterInfo    
拍照帧输出信息。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| captureId | number | false | true | 拍照的ID。 |  
| timestamp | number | false | true | 快门时间戳。 |  
    
## CaptureEndInfo    
拍照停止信息。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| captureId | number | false | true | 拍照的ID。 |  
| frameCount | number | false | true | 帧数。 |  
    
## VideoOutput    
录像会话中使用的输出信息，继承[CameraOutput](#cameraoutput)  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
### start    
启动录制，通过注册回调函数获取结果。  
 **调用形式：**     
    
- start(callback: AsyncCallback\<void>): void    
起始版本： 10    
- start(): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，用于获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400103 | Session not config. |  
| 7400201 | Camera service fatal error. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
function startVideoOutput(videoOutput: camera.VideoOutput): void {  
  videoOutput.start((err: BusinessError) => {  
    if (err) {  
      console.error(`Failed to start the video output ${err.code}`);  
      return;  
    }  
    console.log('Callback invoked to indicate the video output start success.');  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
function startVideoOutput(videoOutput: camera.VideoOutput): void {  
  videoOutput.start().then(() => {  
    console.log('Promise returned to indicate that start method execution success.');  
  }).catch((err: BusinessError) => {  
    console.log('Failed to videoOutput start '+ err.code);  
  });  
}  
    
```    
  
    
### stop    
结束录制，通过注册回调函数获取结果。  
 **调用形式：**     
    
- stop(callback: AsyncCallback\<void>): void    
起始版本： 10    
- stop(): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，用于获取结果。 |  
| Promise<void> | 使用Promise的方式获取结果。 |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
function stopVideoOutput(videoOutput: camera.VideoOutput): void {  
  videoOutput.stop((err: BusinessError) => {  
    if (err) {  
      console.error(`Failed to stop the video output ${err.code}`);  
      return;  
    }  
    console.log('Callback invoked to indicate the video output stop success.');  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
function stopVideoOutput(videoOutput: camera.VideoOutput): void {  
  videoOutput.stop().then(() => {  
    console.log('Promise returned to indicate that stop method execution success.');  
  }).catch((err: BusinessError) => {  
    console.log('Failed to videoOutput stop '+ err.code);  
  });  
}  
    
```    
  
    
### on('frameStart')    
监听录像开始，通过注册回调函数获取结果。  
 **调用形式：**     
    
- on(type: 'frameStart', callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'frameStart'，videoOutput创建成功后可监听。底层第一次曝光时触发该事件并返回。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，用于获取结果。  只要有该事件返回就证明录像开始 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
function registerVideoOutputFrameStart(videoOutput: camera.VideoOutput): void {  
  videoOutput.on('frameStart', () => {  
    console.log('Video frame started');  
  });  
}  
    
```    
  
    
### off('frameStart')    
监听录像开始，通过注册回调函数获取结果。  
 **调用形式：**     
    
- off(type: 'frameStart', callback?: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'frameStart'，videoOutput创建成功后可监听。底层第一次曝光时触发该事件并返回。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，用于获取结果。  只要有该事件返回就证明录像开始 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
function unregisterVideoOutputFrameStart(videoOutput: camera.VideoOutput): void {  
  videoOutput.off('frameStart');  
}  
    
```    
  
    
### on('frameEnd')    
监听录像结束，通过注册回调函数获取结果。  
 **调用形式：**     
    
- on(type: 'frameEnd', callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
function registerVideoOutputFrameEnd(videoOutput: camera.VideoOutput): void {  
  videoOutput.on('frameEnd', () => {  
    console.log('Video frame ended');  
  });  
}  
    
```    
  
    
### off('frameEnd')    
监听录像结束，通过注册回调函数获取结果。  
 **调用形式：**     
    
- off(type: 'frameEnd', callback?: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'frameEnd'，videoOutput创建成功后可监听。录像完全结束最后一帧时触发该事件并返回 。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，用于获取结果。 只要有该事件返回就证明录像结束 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
function unregisterVideoOutputFrameEnd(videoOutput: camera.VideoOutput): void {  
  videoOutput.off('frameEnd');  
}  
    
```    
  
    
### on('error')    
监听录像输出发生错误，通过注册回调函数获取结果。  
 **调用形式：**     
    
- on(type: 'error', callback: ErrorCallback): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'error'，videoOutput创建成功后可监听。录像接口调用出现错误时触发该事件并返回对应错误码,比如调用（start(),release()）接口时出现错误返回对应错误信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，用于获取错误信息。返回错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
function registerVideoOutputError(videoOutput: camera.VideoOutput): void {  
  videoOutput.on('error', (error: BusinessError) => {  
    console.log(`Video output error code: ${error.code}`);  
  });  
}  
    
```    
  
    
### off('error')    
监听metadata流的错误，通过注册回调函数获取结果。  
 **调用形式：**     
    
- off(type: 'error', callback?: ErrorCallback): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'error'，metadataOutput创建成功后可监听。metadata接口使用错误时触发该事件并返回对应错误码，比如调用（start（），release（））接口时发生错误返回对应错误信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，用于获取错误信息。返回错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
function unregisterVideoOutputError(videoOutput: camera.VideoOutput): void {  
  videoOutput.off('error');  
}  
    
```    
  
    
## MetadataObjectType    
枚举，metadata流。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| FACE_DETECTION | 0 | metadata对象类型,人脸检测。检测点应在0-1坐标系内，该坐标系左上角为{0，0}，右下角为{1，1}。<br> 此坐标系是以设备充电口在右侧时的横向设备方向为基准的，<br> 例如应用的预览界面布局以设备充电口在下侧时的竖向方向为基准，<br> 布局宽高为{w，h}， 返回点为{x，y}，则转换后的坐标点为{1-y，x}。 |  
    
## Rect    
矩形定义。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| topLeftX | number | false | true | 矩形区域左上角x坐标。 |  
| topLeftY | number | false | true | 矩形区域左上角y坐标。 |  
| width | number | false | true | 矩形宽。 |  
| height | number | false | true | 矩形高。 |  
    
## MetadataObject    
相机元能力信息，[CameraInput](#camerainput)相机信息中的数据来源，通过metadataOutput.on('metadataObjectsAvailable')接口获取  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| type | MetadataObjectType | true | true | metadata 类型，目前只有人脸识别。 |  
| timestamp | number | true | true | 当前时间戳（毫秒）。 |  
| boundingBox | Rect | true | true | metadata 区域框 |  
    
## MetadataOutput    
metadata流。继承[CameraOutput](#cameraoutput)  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
### start    
开始输出metadata。  
 **调用形式：**     
    
- start(callback: AsyncCallback\<void>): void    
起始版本： 10    
- start(): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，用于获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
| Promise<void> | 使用Promise的方式获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400103 | Session not config. |  
| 7400201 | Camera service fatal error. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
function startMetadataOutput(metadataOutput: camera.MetadataOutput): void {  
  metadataOutput.start((err: BusinessError) => {  
    if (err) {  
      console.error(`Failed to start metadataOutput. ${err.code}`);  
      return;  
    }  
    console.log('Callback returned with metadataOutput started.');  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
function startMetadataOutput(metadataOutput: camera.MetadataOutput): void {  
  metadataOutput.start().then(() => {  
    console.log('Callback returned with metadataOutput started.');  
  }).catch((err: BusinessError) => {  
    console.log('Failed to metadataOutput start '+ err.code);  
  });  
}  
    
```    
  
    
### stop    
停止输出metadata。  
 **调用形式：**     
    
- stop(callback: AsyncCallback\<void>): void    
起始版本： 10    
- stop(): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，用于获取结果。 |  
| Promise<void> | 使用Promise的方式获取结果。 |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
function stopMetadataOutput(metadataOutput: camera.MetadataOutput): void {  
  metadataOutput.stop((err: BusinessError) => {  
    if (err) {  
      console.error(`Failed to stop the metadataOutput. ${err.code}`);  
      return;  
    }  
    console.log('Callback returned with metadataOutput stopped.');  
  })  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
function stopMetadataOutput(metadataOutput: camera.MetadataOutput): void {  
  metadataOutput.stop().then(() => {  
    console.log('Callback returned with metadataOutput stopped.');  
  }).catch((err: BusinessError) => {  
    console.log('Failed to metadataOutput stop '+ err.code);  
  });  
}  
    
```    
  
    
### on('metadataObjectsAvailable')    
监听检测到的metadata对象，通过注册回调函数获取结果。  
 **调用形式：**     
    
- on(type: 'metadataObjectsAvailable', callback: AsyncCallback\<Array\<MetadataObject>>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'metadataObjectsAvailable'，metadataOutput创建成功后可监听。检测到有效的metadata数据时触发该事件发生并返回相应的metadata数据 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，用于获取metadata数据。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
function registerMetadataObjectsAvailable(metadataOutput: camera.MetadataOutput): void {  
  metadataOutput.on('metadataObjectsAvailable', (err: BusinessError, metadataObjectArr: Array<camera.MetadataObject>) => {  
    console.log(`metadata output metadataObjectsAvailable`);  
  });  
}  
    
```    
  
    
### off('metadataObjectsAvailable')    
注销监听检测到的metadata对象。  
 **调用形式：**     
    
- off(type: 'metadataObjectsAvailable', callback?: AsyncCallback\<Array\<MetadataObject>>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'metadataObjectsAvailable'，metadataOutput创建成功后可监听。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，可选。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
function unregisterMetadataObjectsAvailable(metadataOutput: camera.MetadataOutput): void {  
  metadataOutput.off('metadataObjectsAvailable');  
}  
    
```    
  
    
### on('error')    
监听metadata流的错误，通过注册回调函数获取结果。  
 **调用形式：**     
    
- on(type: 'error', callback: ErrorCallback): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'error'，metadataOutput创建成功后可监听。metadata接口使用错误时触发该事件并返回对应错误码，比如调用（start（），release（））接口时发生错误返回对应错误信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，用于获取错误信息。返回错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
function registerMetadataOutputError(metadataOutput: camera.MetadataOutput): void {  
  metadataOutput.on('error', (metadataOutputError: BusinessError) => {  
    console.log(`Metadata output error code: ${metadataOutputError.code}`);  
  });  
}  
    
```    
  
    
### off('error')    
注销监听metadata流的错误。  
 **调用形式：**     
    
- off(type: 'error', callback?: ErrorCallback): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'error'，metadataOutput创建成功后可监听。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，可选。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
function unregisterMetadataOutputError(metadataOutput: camera.MetadataOutput): void {  
  metadataOutput.off('error');  
}  
    
```    
  
