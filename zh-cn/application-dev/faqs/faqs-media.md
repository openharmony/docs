# 媒体开发常见问题

## 如何设置前置拍照

适用于：OpenHarmony SDK 3.2.3.5版本，API9 Stage模型

1. 设置相机位置camera.CameraPosition.CAMERA_POSITION_FRONT

2. 根据相机位置和类型创建CameraInput实例

参考文档：[相机管理](../reference/apis/js-apis-camera.md)

示例：

```
//默认设置后置相机,通过设置isFrontCamera来切换相机
let cameraId
let cameraInput
for(let cameraIndex = 0; cameraIndex < this.cameraArray.length; cameraIndex++) {
   let faceType = this.cameraArray[cameraIndex].cameraPosition
   switch(faceType) {
  case camera.CameraPosition.CAMERA_POSITION_FRONT://前置相机
    if(this.isFrontCamera){
   cameraId = this.cameraArray[cameraIndex].cameraId
    }
	   break
	 case camera.CameraPosition.CAMERA_POSITION_BACK://后置相机
	   if(!this.isFrontCamera){
		 cameraId = this.cameraArray[cameraIndex].cameraId
	   }
	   break
	 case camera.CameraPosition.CAMERA_POSITION_UNSPECIFIED:
	 default:
	   break
   }
}
cameraInput = await this.cameraManager.createCameraInput(cameraId)
```

## 如何进行图片剪切

适用于：OpenHarmony 3.2.5.6版本，API9 Stage模型

1. **通过传入的uri创建图片源实例ImageSource对象。**
     
   ```
   let path = this.context.getApplicationContext().fileDirs + "test.jpg";
   const imageSourceApi = image.createImageSource(path);
   ```

2. **设置解码参数，通过图片解码获取PixelMap图像对象，解码过程中同时支持图像处理操作。**
   - 设置desiredSize支持按尺寸缩放，如果设置为全0，则不进行缩放。
   - 设置desiredRegion支持按矩形区域裁剪，如果设置为全0，则不进行裁剪。
   - 设置rotateDegrees支持旋转角度，以图像中心点顺时针旋转。
        
      ```
      const decodingOptions = {
        desiredSize: {
        height:0,
        width:0
        },
        //按矩形区域裁剪
        desiredRegion: {
        size: {
         height:100,
         width:100
        },
        x:0,
        y:0
        },
        //旋转90度
        rotate:90
      }
      imageSourceApi.createPixelMap(decodingOptions).then(pixelMap => {
        this.handlePixelMap(pixelMap)
      })
      ```

3. 解码完成获取到PixelMap对象后，可以进行后续处理，比如渲染显示等。

## 如何申请设备上的媒体读写权限

适用于：OpenHarmonySDK 3.2.5.5版本，API9 Stage模型

1. 在module.json5配置文件中配置媒体读写权限ohos.permission.READ_MEDIA和ohos.permission.WRITE_MEDIA。
   示例：

     
   ```
   {
     "module" : {
       "requestPermissions":[
         {
           "name" : "ohos.permission.READ_MEDIA",
           "reason": "$string:reason"
         },
         {
           "name" : "ohos.permission.WRITE_MEDIA",
           "reason": "$string:reason"
         }
       ]
     }
   }
   ```

2. 这两个权限的授权方式均为user_grant，因此需要调用requestPermissionsFromUser接口，以动态弹窗的方式向用户申请授权。
     
   ```
   import abilityAccessCtrl from '@ohos.abilityAccessCtrl.d.ts';
   
   let permissions: Array<string> = ['ohos.permission.READ_MEDIA','ohos.permission.WRITE_MEDIA']
   let atManager = abilityAccessCtrl.createAtManager();
   // context为调用方UIAbility的AbilityContext
   atManager.requestPermissionsFromUser(context, permissions).then((data) => {
       console.log("Succeed to request permission from user with data: " + JSON.stringify(data))
   }).catch((error) => {
       console.log("Failed to request permission from user with error: " + JSON.stringify(error))
   })
   ```

## MP4格式的视频为什么播放不了

适用于：OpenHarmonySDK 3.2.7.5版本，API9 Stage模型

暂不支持h.265编码格式的MP4视频播放。


## 为什么视频创建至十几个时新创建的视频无法播放甚至崩溃

适用于：OpenHarmonySDK 3.2.7.5版本，API9 Stage模型

当前限制最多创建13个媒体播放实例。
