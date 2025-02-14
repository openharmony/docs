# multimedia变更说明

## cl.multimedia.1 @ohos.multimedia.medialibrary变更

**访问级别**

公开接口。

**变更原因**

不带水印的动态照片滑动自动播放时图片和视频放大至1.1倍，复杂场景拍摄的动态照片左右滑动自动播放时效果闪和晃动明显。

**变更影响**

该变更为不兼容性变更。

@ohos.multimedia.medialibrary模块中的autoPlay接口ux默认行为规范变更。

变更前行为：不带水印的照片播放时照片视频放大至1.1倍。

变更后行为：不带水印的照片播放时照片视频不放大。

**起始 API Level**

13

**变更发生的版本**

从OpenHarmony SDK 5.0.0.46开始。

**变更的接口/组件**

@ohos.multimedia.medialibrary模块中的autoPlay接口。

**适配指导**

不需要开发者适配