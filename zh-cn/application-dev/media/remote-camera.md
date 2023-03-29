# 分布式相机开发指导

## 场景介绍

分布式相机模块支持相机相关基础功能介绍说明。

## 开发步骤
在计算器中连接分布式设备，在获取相机列表getSupportedCameras()，遍历返回的列表，判断对应Camera对象中的ConnectionType是否等于CAMERA_CONNECTION_REMOTE,若等于则使用此对象创建cameraInput，之后调用与本地相机使用一样。参考：[相机开发指导](./camera.md)

详细API含义请参考：[相机管理API文档](../reference/apis/js-apis-camera.md)

### 连接分布式相机

打开设置->WLAN,将需要连接分布式相机的两台设备连入同一局域网。

打开计算器，点击右上角小图标，出现新的窗口，按提示输入验证码，连接成功。

### 创建实例

```js
import camera from '@ohos.multimedia.camera'
import image from '@ohos.multimedia.image'
import media from '@ohos.multimedia.media'
import featureAbility from '@ohos.ability.featureAbility'

// 创建CameraManager对象
let cameraManager = camera.getCameraManager(globalThis.Context)
if (!cameraManager) {
    console.error("camera.getCameraManager error")
    return;
} 

// 注册回调函数监听相机状态变化，获取状态变化的相机信息
cameraManager.on('cameraStatus', (cameraStatusInfo) => {
    console.log('camera : ' + cameraStatusInfo.camera.cameraId);
    console.log('status: ' + cameraStatusInfo.status);
})

// 获取相机列表
let remoteCamera
let cameraArray = cameraManager.getSupportedCameras();
if (cameraArray.length <= 0) {
    console.error("cameraManager.getSupportedCameras error")
    return;
} 

for(let cameraIndex = 0; cameraIndex < cameraArray.length; cameraIndex++) {
    console.log('cameraId : ' + cameraArray[cameraIndex].cameraId)                          // 获取相机ID
    console.log('cameraPosition : ' + cameraArray[cameraIndex].cameraPosition)              // 获取相机位置
    console.log('cameraType : ' + cameraArray[cameraIndex].cameraType)                      // 获取相机类型
    console.log('connectionType : ' + cameraArray[cameraIndex].connectionType)              // 获取相机连接类型
    if (cameraArray[cameraIndex].connectionType == CAMERA_CONNECTION_REMOTE) {
        remoteCamera = cameraArray[cameraIndex]
    }
}

// 创建相机输入流
let cameraInput
try {
    cameraInput = cameraManager.createCameraInput(remoteCamera);
} catch () {
   console.error('Failed to createCameraInput errorCode = ' + error.code);
}
```
剩余步骤参照[相机开发指导](./camera.md)