# ArkUI子系统Changelog

## cl.arkui.1 Navigation、NavDestination默认样式变化

**访问级别**

公开接口

**变更原因**

UX样式增强

**变更影响**

1. Navigation Mini模式，主标题字重默认值由MEDIUM变更为BOLD；隐藏返回键时，非自定义主标题默认字号由24fp变更为26fp;

变更前后对比效果，如下图所示：

| 变更前 | 变更后 |
|---------|---------|
| ![](figures/NavigationMini_Before.jpeg) | ![](figures/NavigationMini_After.jpeg) |
| ![](figures/NavigationMiniHideBackButton_Before.jpeg) | ![](figures/NavigationMiniHideBackButton_After.jpeg) |

2. Navigation Mini模式及NavDestination组件的标题栏含副标题时默认高度由82vp变更为56vp，标题居中布局；back图标变更；

变更前后对比效果，如下图所示：

| 变更前 | 变更后 |
|---------|---------|
| ![](figures/NavigationMiniSubtitle_Before.jpeg) | ![](figures/NavigationMiniSubtitle_After.jpeg) |
| ![](figures/NavigationMiniHideBackButtonSubtitle_Before.jpeg) | ![](figures/NavigationMiniHideBackButtonSubtitle_After.jpeg) |

3. Navigation Full、Free模式，大标题模式，布局变更：<br/>
变更前：标题居中布局；<br/>
变更后：<br/>
含副标题：<br/>
   (1)当主标题高度+副标题高度+主副标题之间间距2vp+标题下间距8vp =< 82vp时，固定主副标题之间间距2vp，标题居中布局；<br/>
   (2)当主标题高度+副标题高度+主副标题之间间距2vp+标题下间距8vp > 82vp时，固定标题下间距8vp，主副标题之间间距2vp，主标题向上自适应布局。<br/>
   不含副标题：<br/>
   (1)当标题高度 > 56vp时，固定标题下间距8vp，标题向上自适应布局；<br/>
   (2)当标题高度 =< 56vp时，标题居中布局。<br/>

变更前后对比效果，如下图所示：
| 变更前 | 变更后 |
|---------|---------|
| ![](figures/NavigationFull_Before.jpeg) | ![](figures/NavigationFull_After.jpeg) |
| ![](figures/NavigationFullSubtitle_Before.jpeg) | ![](figures/NavigationFullSubtitle_After.jpeg) |
| ![](figures/NavigationFullSubtitle2_Before.jpeg) | ![](figures/NavigationFullSubtitle2_After.jpeg) |


**起始API Level**

9

**变更发生版本**

从OpenHarmony SDK 5.0.0.25 版本开始。

**变更的接口/组件**

Navigation、NavDestination

**适配指导**

默认效果变更，无需适配。但应注意变更后的默认效果是否符合预期。