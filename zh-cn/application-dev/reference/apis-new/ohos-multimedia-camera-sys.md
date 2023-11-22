# @ohos.multimedia.camera    
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import camera from '@ohos.multimedia.camera'    
```  
    
## PrelaunchConfig    
相机预启动配置参数。当前sensor级别预热，待扩展流预热参数。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| cameraDevice | CameraDevice | false | true | 相机信息。 |  
    
## CameraManager    
相机管理器类，使用前需要通过getCameraManager获取相机管理实例。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
### isCameraMuteSupported    
查询当前设备是否支持禁用相机，通过返回值返回结果。  
 **调用形式：**     
- isCameraMuteSupported(): boolean  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示相机可以被禁用，返回false表示相机不能被禁用。 |  
    
 **示例代码：**   
```ts    
function isCameraMuteSupported(cameraManager: camera.CameraManager): boolean {  
  let isMuteSupported: boolean = cameraManager.isCameraMuteSupported();  
  return isMuteSupported;  
}  
    
```    
  
    
### muteCamera    
禁用相机。  
 **调用形式：**     
- muteCamera(mute: boolean): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mute | boolean | true | 禁用相机。 |  
    
 **示例代码：**   
```ts    
function muteCamera(cameraManager: camera.CameraManager): void {  
  let mute: boolean = true;  
  cameraManager.muteCamera(mute);  
}  
    
```    
  
    
### on('cameraMute')    
禁用回调，通过注册回调函数获取相机禁用状态变化。  
 **调用形式：**     
    
- on(type: 'cameraMute', callback: AsyncCallback\<boolean>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'cameraMute'，系统相机摄像头开关，cameraManager对象获取成功后可监听。系统设置打开或禁用相机会触发该事件并返回状态 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，用于获取禁用状态变化信息，返回true是开启状态，返回false是禁用状态。 |  
    
 **示例代码：**   
示例代码（callback）：  
```null    
import { BusinessError } from '@ohos.base';  
  
function registerCameraMute(cameraManager: camera.CameraManager): void {  
  cameraManager.on('cameraMute', (err: BusinessError, curMuted: boolean) => {  
    let isMuted: boolean = curMuted;  
    console.log(`cameraMute status: ${isMuted}`);  
  })  
}  
    
```    
  
    
### off('cameraMute')    
禁用回调，通过注册回调函数获取相机禁用状态变化。  
 **调用形式：**     
    
- off(type: 'cameraMute', callback?: AsyncCallback\<boolean>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'cameraMute'，系统相机摄像头开关，cameraManager对象获取成功后可监听。系统设置打开或禁用相机会触发该事件并返回状态 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，用于获取禁用状态变化信息，返回true是开启状态，返回false是禁用状态。 |  
    
 **示例代码：**   
示例代码（callback）：  
```null    
import { BusinessError } from '@ohos.base';  
  
function callback(err: BusinessError, curMuetd: boolean): void {  
  let isMuted: boolean = curMuetd;  
}  
  
function unregisterCameraMute(cameraManager: camera.CameraManager): void {  
  cameraManager.on('cameraMute', callback);  
  cameraManager.off('cameraMute', callback);  
}  
    
```    
  
    
### isPrelaunchSupported    
检查指定cameraDevice是否支持预热启动。  
 **调用形式：**     
- isPrelaunchSupported(camera: CameraDevice): boolean  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| camera | CameraDevice | true | 相机信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回指定cameraDevice是否支持预热启动。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400101 | Parameter missing or parameter type incorrect. |  
    
 **示例代码：**   
```ts    
import common from '@ohos.app.ability.common';  
  
function isPreLaunchSupported(context: common.BaseContext): boolean {  
  let cameraManager: camera.CameraManager = camera.getCameraManager(context);  
  let cameras: Array<camera.CameraDevice> = cameraManager.getSupportedCameras();  
  let isSupported: boolean = false;  
  if (cameras  cameras.length >= 1) {  
    isSupported = cameraManager.isPrelaunchSupported(cameras[0]);  
    console.log(`PreLaunch supported states: ${isSupported}`);  
    return isSupported;  
  }  
  return isSupported;  
}  
    
```    
  
    
### setPrelaunchConfig    
在调用setPrelaunchConfig接口前，需要先检查设备是否支持预热启动，使用[isPrelaunchSupported](#isprelaunchsupported)判断指定cameraDevice是否支持预热启动。  
 **调用形式：**     
- setPrelaunchConfig(prelaunchConfig: PrelaunchConfig): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core  
 **需要权限：** ohos.permission.CAMERA    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| prelaunchConfig | PrelaunchConfig | true | 预启动配置参数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400101 | Parameter missing or parameter type incorrect. |  
| 7400102 | Operation not allow. |  
    
 **示例代码：**   
```null    
import common from '@ohos.app.ability.common';  
import { BusinessError } from '@ohos.base';  
  
function setPrelaunchConfig(context: common.BaseContext): void {  
  let cameraManager: camera.CameraManager = camera.getCameraManager(context);  
  let cameras: Array<camera.CameraDevice> = cameraManager.getSupportedCameras();  
  if (cameras  cameras.length >= 1) {  
    let cameraDevice: camera.CameraDevice = cameras[0];  
    if(cameraManager.isPrelaunchSupported(cameraDevice)) {  
      try {  
        cameraManager.setPrelaunchConfig({cameraDevice: cameraDevice});  
      } catch (error) {  
        let err = error as BusinessError;  
        console.error(`setPrelaunchConfig error. Code: ${err.code}, message: ${err.message}`);  
      }  
    }  
  }  
}  
    
```    
  
    
### prelaunch    
用户点击系统相机图标，拉起相机应用同时调用，下发预热请求，使能相机预热启动。  
 **调用形式：**     
- prelaunch(): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **示例代码：**   
```ts    
import common from '@ohos.app.ability.common';  
import { BusinessError } from '@ohos.base';  
  
function preLaunch(context: common.BaseContext): void {  
  let cameraManager: camera.CameraManager = camera.getCameraManager(context);  
  try {  
    cameraManager.prelaunch();  
  } catch (error) {  
    let err = error as BusinessError;  
    console.error(`prelaunch error. Code: ${err.code}, message: ${err.message}`);  
  }  
}  
    
```    
  
    
### createDeferredPreviewOutput    
创建延迟预览输出对象，在配流时替代普通的预览输出对象加入数据流。  
 **调用形式：**     
- createDeferredPreviewOutput(profile: Profile): PreviewOutput  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| profile | Profile | true | 相机预览流的配置文件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| PreviewOutput | 返回预览输出对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400101 | Parameter missing or parameter type incorrect. |  
    
 **示例代码：**   
```ts    
import common from '@ohos.app.ability.common';  
  
function getDeferredPreviewOutput(context: common.BaseContext, previewProfile: camera.Profile): camera.PreviewOutput {  
  const cameraManager: camera.CameraManager = camera.getCameraManager(context);  
  const output: camera.PreviewOutput = cameraManager.createDeferredPreviewOutput(previewProfile);  
  return output;  
}  
    
```    
  
    
## HostDeviceType    
枚举，远端相机设备类型。    
    
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| UNKNOWN_TYPE | 0 | 未知设备类型。 |  
| PHONE | 0x0E | 智能手机相机设备类型 |  
| TABLET | 0x11 | 平板电脑相机设备类型。 |  
    
## CameraDevice    
相机设备信息。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| hostDeviceName | string | true | true | 远端设备名称，**系统接口：** 此接口为系统接口。 |  
| hostDeviceType | HostDeviceType | true | true | 远端相机设备类型，**系统接口：** 此接口为系统接口。 |  
    
## FilterType    
滤镜类型。    
    
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NONE | 0 | 原图。 |  
| CLASSIC | 1 | 经典。 |  
| DAWN | 2 | 晨光。 |  
| PURE | 3 | 清纯。 |  
| GREY | 4 | 灰调。 |  
| NATURAL | 5 | 自然。 |  
| MORI | 6 | 森系。 |  
| FAIR | 7 | 白皙。 |  
| PINK | 8 | 粉调。 |  
    
## BeautyType    
美颜类型。    
    
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| AUTO | 0 | 自动。 |  
| SKIN_SMOOTH | 1 | 光滑。 |  
| FACE_SLENDER | 2 | 瘦脸。 |  
| SKIN_TONE | 3 | 肤色。 |  
    
## CaptureSession    
拍照会话类，保存一次相机运行所需要的所有资源[CameraInput](#camerainput)、[CameraOutput](#cameraoutput)，并向相机设备申请完成相机功能(录像，拍照)。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
### getSupportedFilters    
获取当前支持的滤镜效果列表。  
 **调用形式：**     
- getSupportedFilters(): Array\<number>  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<number> | 返回支持的滤镜效果列表。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400103 | Session not config. |  
    
 **示例代码：**   
```ts    
function setFilter(portraitSession: camera.PortraitSession, filterTypes: Array<camera.FilterType>): void {  
  if (filterTypes === undefined || filterTypes.length <= 0) {  
    return;  
  }  
  portraitSession.setFilter(filterTypes[0]);  
}  
    
```    
  
    
### getFilter    
获取当前已设置的滤镜效果。  
 **调用形式：**     
- getFilter(): number  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 已设置的滤镜效果。可查阅[FilterType](#filtertype)。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400103 | Session not config. |  
    
 **示例代码：**   
```ts    
function getFilter(portraitSession: camera.PortraitSession): number {  
  let filterType: number = portraitSession.getFilter();  
  return filterType;  
}  
    
```    
  
    
### setFilter    
设置滤镜效果。需要先检查设备是否支持对应的滤镜效果，可以通过[getSupportedFilters](#getsupportedfilters)方法获取所支持的类型。  
 **调用形式：**     
- setFilter(filter: number): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| filter | number | true | 当前用户设置的滤镜类型。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400101 | Parameter missing or parameter type incorrect. |  
| 7400103 | Session not config. |  
    
 **示例代码：**   
```ts    
function setFilter(portraitSession: camera.PortraitSession, filterTypes: Array<camera.FilterType>): void {  
  if (filterTypes === undefined || filterTypes.length <= 0) {  
    return;  
  }  
  portraitSession.setFilter(filterTypes[0]);  
}  
    
```    
  
    
### getSupportedBeautyTypes    
获取当前支持的美颜效果列表。  
 **调用形式：**     
- getSupportedBeautyTypes(): Array\<BeautyType>  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<BeautyType> | 返回当前支持的美颜效果列表。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400103 | Session not config. |  
    
 **示例代码：**   
```ts    
function getSupportedBeautyTypes(portraitSession: camera.PortraitSession): Array<camera.BeautyType> {  let beautyTypes: Array<camera.BeautyType> = portraitSession.getSupportedBeautyTypes();  return beautyTypes;}    
```    
  
    
### getSupportedBeautyRange    
获取指定美颜效果的范围值。在不同设备返回的美颜强度有所不同，下表仅做示例。  
 **调用形式：**     
- getSupportedBeautyRange(type: BeautyType): Array\<number>  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | BeautyType | true | 美颜类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<number> | 当前美颜类型所支持的美颜强度。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400103 | Session not config. |  
    
### getBeauty    
查询当前已设置的美颜效果对应的美颜强度。  
 **调用形式：**     
- getBeauty(type: BeautyType): number  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | BeautyType | true | 美颜类型 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 美颜强度 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400103 | Session not config. |  
    
 **示例代码：**   
```ts    
function getBeauty(portraitSession: camera.PortraitSession): number {  
  const invalid_value: number = -1;  
  let beautyTypes = portraitSession.getSupportedBeautyTypes();  
  if (beautyTypes === undefined || beautyTypes.length <= 0) {  
    return invalid_value;  
  }  
  let beautyLevels: Array<number> = portraitSession.getSupportedBeautyRange(beautyTypes[0]);  
  if (beautyLevels === undefined || beautyLevels.length <= 0) {  
    return invalid_value;  
  }  
  portraitSession.setBeauty(beautyTypes[0], beautyLevels[0]);  
  let beautyLevel: number = portraitSession.getBeauty(beautyTypes[0]);  
  return beautyLevel;  
}  
    
```    
  
    
### setBeauty    
设置美颜类型以及对应的美颜强度。将通过[getSupportedBeautyTypes](#getsupportedbeautytypes)获取得到的[BeautyType](#beautytype)都关闭，表明当前美颜关闭；若有一种美颜类型未关闭，表明当前美颜打开。  
 **调用形式：**     
- setBeauty(type: BeautyType, value: number): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | BeautyType | true | 美颜类型 |  
| value | number | true | 美颜强度，通过[getSupportedBeautyRange](#getsupportedbeautyrange)接口获取。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400103 | Session not config. |  
    
 **示例代码：**   
```null    
function setBeauty(portraitSession: camera.PortraitSession): void {  
  let beautyTypes: Array<camera.BeautyType> = portraitSession.getSupportedBeautyTypes();  
  if (beautyTypes === undefined || beautyTypes.length <= 0) {  
    return;  
  }  
  let beautyLevels: Array<number> = portraitSession.getSupportedBeautyRange(beautyTypes[0]);  
  if (beautyLevels === undefined || beautyLevels.length <= 0) {  
    return;  
  }  
  portraitSession.setBeauty(beautyTypes[0], beautyLevels[0]);  
}  
    
```    
  
    
## CameraMode    
    
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| PORTRAIT | 1 | 人像模式 |  
    
## getModeManager    
获取模式化管理器实例，同步返回结果。模式化管理是对于cameraManager功能的增强与扩充，主要用于一些高级功能的管理（如人像模式）。  
 **调用形式：**     
- getModeManager(context: Context): ModeManager  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| context | Context | true | 应用上下文。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ModeManager | 模式化管理器。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400101 | Parameter missing or parameter type incorrect |  
| 7400201 | Camera service fatal error. |  
    
 **示例代码：**   
```js    
import common from '@ohos.app.ability.common';  
import { BusinessError } from '@ohos.base';  
  
function getModeManager(context: common.BaseContext): camera.ModeManager | undefined {  
  let modeManager: camera.ModeManager | undefined = undefined;  
  try {  
    modeManager = camera.getModeManager(context);  
  } catch (error) {  
    let err = error as BusinessError;  
    console.error(`The getModeManager call failed. error code: ${err.code}`);  
  }  
  return modeManager;  
}  
    
```    
  
    
## ModeManager    
相机模式化管理器类，使用前需要通过[getModeManager](#cameragetmodemanager)获取相机模式化管理实例。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
### getSupportedModes    
获取指定相机设备支持的模式列表，同步返回结果。  
 **调用形式：**     
- getSupportedModes(device: CameraDevice): Array\<CameraMode>  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| device | CameraDevice | true | 相机设备实例，通过[getSupportedCameras](#getsupportedcameras)接口获取。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<CameraMode> | 支持的模式列表。 |  
    
 **示例代码：**   
```ts    
function getSupportedModes(modeManager: camera.ModeManager, cameraDevice: camera.CameraDevice): Array<camera.CameraMode> {  let cameraModes: Array<camera.CameraMode> = modeManager.getSupportedModes(cameraDevice);  return cameraModes;}    
```    
  
    
### getSupportedOutputCapability    
获取指定模式下相机设备支持的输出能力，同步返回结果。  
 **调用形式：**     
- getSupportedOutputCapability(device: CameraDevice, mode: CameraMode): CameraOutputCapability  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| device | CameraDevice | true | 相机设备，通过[getSupportedCameras](#getsupportedcameras)接口获取。 |  
| mode | CameraMode | true | 指定模式，通过[getSupportedModes](#getsupportedmodes)接口获取。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| CameraOutputCapability | 相机输出能力。 |  
    
 **示例代码：**   
```ts    
function getSupportedOutputCapability(cameraManager: camera.CameraManager, modeManager: camera.ModeManager): camera.CameraOutputCapability | undefined {  
  let cameras: Array<camera.CameraDevice> = cameraManager.getSupportedCameras();  
  if (cameras == undefined || cameras.length <= 0) {  
    return undefined;  
  }  
  let cameraDevice: camera.CameraDevice = cameras[0];  
  let cameraModes: Array<camera.CameraMode> = modeManager.getSupportedModes(cameraDevice);  
  if (cameraModes === undefined || cameraModes.length <= 0) {  
    return undefined;  
  }  
  let mode: camera.CameraMode = cameraModes[0];  
  let cameraOutputCapability: camera.CameraOutputCapability = modeManager.getSupportedOutputCapability(cameraDevice, mode);  
  return cameraOutputCapability;  
}  
    
```    
  
    
### createCaptureSession    
根据当前的模式名，创建指定模式的会话。  
 **调用形式：**     
- createCaptureSession(mode: CameraMode): CaptureSession  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mode | CameraMode | true | 指定模式，通过[getSupportedModes](#getsupportedmodes)获取。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| CaptureSession | 指定模式的会话实例。 |  
    
## PortraitEffect    
    
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| OFF | 0 | 关闭。 |  
| CIRCLES | 1 | 圆形。 |  
    
## PortraitSession    
继承自[CaptureSession](#capturesession)，用于设置人像模式的参数。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
### getSupportedPortraitEffects    
获取支持的人像虚化效果列表。  
 **调用形式：**     
- getSupportedPortraitEffects(): Array\<PortraitEffect>  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<PortraitEffect> | 支持的人像虚化效果列表。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400103 | Session not config. |  
    
 **示例代码：**   
```ts    
function getSupportedPortraitEffects(portraitSession: camera.PortraitSession): Array<camera.PortraitEffect> {  let portraitEffects: Array<camera.PortraitEffect> = portraitSession.getSupportedPortraitEffects();  return portraitEffects;}    
```    
  
    
### getPortraitEffect  
 **调用形式：**     
- getPortraitEffect(): PortraitEffect  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| PortraitEffect | 当前设置的人像虚化效果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400103 | Session not config. |  
    
 **示例代码：**   
获取当前设置的人像虚化效果。  
```ts    
function getSupportedPortraitEffects(portraitSession: camera.PortraitSession): Array<camera.PortraitEffect> {  let portraitEffects: Array<camera.PortraitEffect> = portraitSession.getSupportedPortraitEffects();  return portraitEffects;}    
```    
  
    
### setPortraitEffect    
设置人像虚化效果。需要先检查设备是否支持人像虚化模式，可以通过[getSupportedPortraitEffects](#getsupportedportraiteffects)获取当前设备所支持的PortraitEffect。  
 **调用形式：**     
- setPortraitEffect(effect: PortraitEffect): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| effect | PortraitEffect | true | 人像虚化效果，通过[getSupportedPortraitEffects](#getsupportedportraiteffects)接口获取。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400103 | Session not config. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
function setPortraitEffect(portraitSession: camera.PortraitSession, portraitEffects: Array<camera.PortraitEffect>): void {  
  if (portraitEffects === undefined || portraitEffects.length <= 0) {  
    return;  
  }  
  try {  
    portraitSession.setPortraitEffect(portraitEffects[0]);  
  } catch (error) {  
    let err = error as BusinessError;  
    console.error(`The setPortraitEffect call failed. error code: ${err.code}`);  
  }  
}  
    
```    
  
    
## PreviewOutput    
预览输出类。继承[CameraOutput](#cameraoutput)。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
### addDeferredSurface    
配置延迟预览的Surface，可以在session.commitConfig()配流和session.start()启流之后运行。  
 **调用形式：**     
- addDeferredSurface(surfaceId: string): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| surfaceId | string | true | 从[XComponent](../arkui-ts/ts-basic-components-xcomponent.md)组件获取的surfaceId。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400101 | Parameter missing or parameter type incorrect |  
    
 **示例代码：**   
```ts    
import common from '@ohos.app.ability.common';  
async function preview(context: common.BaseContext, cameraInfo: camera.CameraDevice, previewProfile: camera.Profile, photoProfile: camera.Profile, photoSurfaceId: string, previewSurfaceId: string): Promise<void> {  const cameraManager: camera.CameraManager = camera.getCameraManager(context);  const cameraInput: camera.CameraInput = cameraManager.createCameraInput(cameraInfo)  const previewOutput: camera.PreviewOutput = cameraManager.createDeferredPreviewOutput(previewProfile);  const photoOutput: camera.PhotoOutput = cameraManager.createPhotoOutput(photoProfile, photoSurfaceId);  const session: camera.CaptureSession  = cameraManager.createCaptureSession();  session.beginConfig();  session.addInput(cameraInput);  session.addOutput(previewOutput);  session.addOutput(photoOutput);  await session.commitConfig();  await session.start();  previewOutput.addDeferredSurface(previewSurfaceId);}    
```    
  
    
## PhotoOutput    
拍照会话中使用的输出信息，继承[CameraOutput](#cameraoutput)  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
### isQuickThumbnailSupported    
是否支持输出快速缩略图。在CaptureSession.addOutput、CaptureSession.addInput之后，CaptureSession.commitConfig之前生效。  
 **调用形式：**     
- isQuickThumbnailSupported(): boolean  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回支持情况，如果返回true表示支持，否则不支持。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400104 | session is not running |  
    
 **示例代码：**   
```ts    
import common from '@ohos.app.ability.common';  
async function isQuickThumbnailSupported(context: common.BaseContext, photoProfile: camera.Profile, surfaceId: string): Promise<boolean> {  let cameraManager: camera.CameraManager = camera.getCameraManager(context);  let cameras: Array<camera.CameraDevice> = cameraManager.getSupportedCameras();  // 创建CaptureSession实例  let captureSession: camera.CaptureSession = cameraManager.createCaptureSession();  // 开始配置会话  captureSession.beginConfig();  // 把CameraInput加入到会话  let cameraInput: camera.CameraInput = cameraManager.createCameraInput(cameras[0]);  await cameraInput.open();  captureSession.addInput(cameraInput);  // 把photoOutput加入到会话  let photoOutput: camera.PhotoOutput = cameraManager.createPhotoOutput(photoProfile, surfaceId);  captureSession.addOutput(photoOutput);  let isSupported: boolean = photoOutput.isQuickThumbnailSupported();  return isSupported;}    
```    
  
    
### enableQuickThumbnail    
使能/去使能快速缩略图。在CaptureSession.addOutput、CaptureSession.addInput之后，CaptureSession.commitConfig之前生效。  
 **调用形式：**     
- enableQuickThumbnail(enabled: boolean): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| enabled | boolean | true | true：使能快速缩略图；false：去使能快速缩略图。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 7400104 | session is not running |  
    
 **示例代码：**   
```ts    
import common from '@ohos.app.ability.common';  
import { BusinessError } from '@ohos.base';  
  
async function enableQuickThumbnail(context: common.BaseContext, photoProfile: camera.Profile, surfaceId: string): Promise<void> {  
  let cameraManager: camera.CameraManager = camera.getCameraManager(context);  
  let cameras: Array<camera.CameraDevice> = cameraManager.getSupportedCameras();  
  // 创建CaptureSession实例  
  let captureSession: camera.CaptureSession = cameraManager.createCaptureSession();  
  // 开始配置会话  
  captureSession.beginConfig();  
  // 把CameraInput加入到会话  
  let cameraInput: camera.CameraInput = cameraManager.createCameraInput(cameras[0]);  
  await cameraInput.open();  
  captureSession.addInput(cameraInput);  
  // 把PhotoOutPut加入到会话  
  let photoOutput: camera.PhotoOutput = cameraManager.createPhotoOutput(photoProfile, surfaceId);  
  captureSession.addOutput(photoOutput);  
  let isSupported: boolean = photoOutput.isQuickThumbnailSupported();  
  if (!isSupported) {  
    console.log('Quick Thumbnail is not supported to be turned on.');  
    return;  
  }  
  try {  
    photoOutput.enableQuickThumbnail(true);  
  } catch (error) {  
    let err = error as BusinessError;  
    console.error(`The enableQuickThumbnail call failed. error code: ${err.code}`);  
  }  
}  
    
```    
  
    
### on('quickThumbnail')    
监听快速缩略图输出事件。  在enableQuickThumbnail(true)使能快速缩略图之后监听生效。  
 **调用形式：**     
    
- on(type: 'quickThumbnail', callback: AsyncCallback\<image.PixelMap>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'quickThumbnail'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调返回PixelMap。 |  
    
 **示例代码：**   
```ts    
import common from '@ohos.app.ability.common';  
import { BusinessError } from '@ohos.base';  
import image from '@ohos.multimedia.image';  
  
async function registerQuickThumbnail(context: common.BaseContext, photoProfile: camera.Profile, surfaceId: string): Promise<void> {  
  let cameraManager: camera.CameraManager = camera.getCameraManager(context);  
  let cameras: Array<camera.CameraDevice> = cameraManager.getSupportedCameras();  
  // 创建CaptureSession实例  
  let captureSession: camera.CaptureSession = cameraManager.createCaptureSession();  
  // 开始配置会话  
  captureSession.beginConfig();  
  // 把CameraInput加入到会话  
  let cameraInput: camera.CameraInput = cameraManager.createCameraInput(cameras[0]);  
  await cameraInput.open();  
  captureSession.addInput(cameraInput);  
  // 把PhotoOutPut加入到会话  
  let photoOutput: camera.PhotoOutput = cameraManager.createPhotoOutput(photoProfile, surfaceId);  
  captureSession.addOutput(photoOutput);  
  let isSupported: boolean = photoOutput.isQuickThumbnailSupported();  
  if (!isSupported) {  
    console.log('Quick Thumbnail is not supported to be turned on.');  
    return;  
  }  
  try {  
    photoOutput.enableQuickThumbnail(true);  
  } catch (error) {  
    let err = error as BusinessError;  
    console.error(`The enableQuickThumbnail call failed. error code: ${err.code}`);  
  }  
  
  photoOutput.on('quickThumbnail', (err: BusinessError, pixelMap: image.PixelMap) => {  
    if (err || pixelMap === undefined) {  
      console.error('photoOutput on thumbnail failed');  
      return;  
    }  
    // 显示或保存pixelMap  
    // do something  
  })  
}  
    
```    
  
    
### off('quickThumbnail')    
注销监听快速缩略图输出事件。  
 **调用形式：**     
    
- off(type: 'quickThumbnail', callback?: AsyncCallback\<image.PixelMap>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.Camera.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'quickThumbnail'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 可选。 |  
    
 **示例代码：**   
```ts    
function unregisterQuickThumbnail(photoOutput: camera.PhotoOutput): void {  
  photoOutput.off('quickThumbnail');  
}  
    
```    
  
