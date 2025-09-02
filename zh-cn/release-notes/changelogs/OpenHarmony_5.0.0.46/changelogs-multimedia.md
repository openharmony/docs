# multimedia变更说明

## cl.multimedia.1 @ohos.multimedia.medialibrary变更

**访问级别**

公开接口。

**变更原因**

动态照片自动播放时会放大至1.1倍；动态照片左右滑动自动播放时，闪烁和晃动效果明显。为改善用户界面使用体验，动态照片设置autoPlay自动播放时不放大。

**变更影响**

此变更无需应用适配。

@ohos.multimedia.medialibrary模块中的autoPlay接口ux默认行为规范变更。

变更前行为：动态照片设置autoPlay自动播放时放大至1.1倍。

变更后行为：动态照片设置autoPlay自动播放时不放大。

**起始 API Level**

13

**变更发生的版本**

从OpenHarmony SDK 5.0.0.46开始。

**变更的接口/组件**

@ohos.multimedia.medialibrary模块中的autoPlay接口。

**适配指导**

默认行为变更，无需适配。