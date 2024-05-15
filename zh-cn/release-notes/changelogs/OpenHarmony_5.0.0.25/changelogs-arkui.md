# ArkUI子系统Changelog

## cl.arkui.1 Navigation、NavDestination默认样式变化

**访问级别**

公开接口

**变更原因**

UX样式增强

**变更影响**

变更前：
1. Navigation Mini模式，未隐藏返回键时，非自定义主标题默认字号为24fp；
2. Navigation Mini模式及NavDestination组件的标题栏高度为：含副标题82vp，不含副标题56vp；
3. Navigation Mini模式非自定义主标题字重默认值为MEDIUM；
4. Navigation Full、Free模式，非自定义标题展开态，标题与menu的间距为8vp。

变更后：
1. Navigation Mini模式，未隐藏返回键时，非自定义主标题默认字号为26fp；
2. Navigation Mini模式及NavDestination组件的标题栏高度为：56vp；
3. Navigation Mini模式非自定义主标题字重默认值为BOLD；
4. Navigation Full、Free模式，非自定义标题展开态：
   含副标题：
   ①主标题高度+副标题高度+主副标题之间间距2vp+标题下间距8vp<82vp，主副标题之间间距2vp，标题居中布局；
   ②主标题高度+副标题高度+主副标题之间间距2vp+标题下间距8vp>=82vp,固定标题下间距8vp，主副标题之间间距2vp，主标题向上自适应布局。
   不含副标题：
   ①标题高度+标题下间距8vp>=56vp，固定标题下间距8vp，标题向上自适应布局；
   ②标题高度+标题下间距8vp<56vp，标题居中布局。

变更前后对比效果，如下图所示：
| 变更前 | 变更后 |
|---------|---------|
| ![](figures/NavigationMini_Before.jpeg) | ![](figures/NavigationMini_After.jpeg) |
| ![](figures/NavigationMiniSubtitle_Before.jpeg) | ![](figures/NavigationMiniSubtitle_After.jpeg) |
| ![](figures/NavigationMiniHideBackButton_Before.jpeg) | ![](figures/NavigationMiniHideBackButton_After.jpeg) |
| ![](figures/NavigationMiniHideBackButtonSubtitle_Before.jpeg) | ![](figures/NavigationMiniHideBackButtonSubtitle_After.jpeg) |
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

## cl.arkui.2 一级菜单弹出/退出动效增强，二级菜单新增STACK_EXPAND和EMBEDDED_EXPAND模式动效

**访问级别**

公开接口

**变更原因**

一级/二级菜单弹窗默认风格刷新

**变更影响**

一级菜单弹出/退出动效：
变更前：
菜单弹出/退出是透明度在变换

变更后：
菜单相对target组件弹出/退出，在透明度的基础上增加了位移缩放模糊动效

二级菜单弹出/退出动效：
变更前:
二级菜单在一级菜单侧边展开，退出时直接消失
变更后：
1. 开发者设置为STACK_EXPAND模式，二级菜单展开形成前后两个层级，一级菜单向后位移缩放，透明度同时切换，二级菜单中的标题和箭头以点击的menuItem为中心，向下位移至正确位置，同时箭头方向顺时针旋转90度。
2. STACK_EXPAND模式退出时，二级菜单向上位移至正确位置，且箭头逆时针旋转90度，透明度变为0，一级菜单向前位移至原位且大小恢复原样，透明度变为100%；
3. 开发者设置为EMBEDDED_EXPAND模式，二级菜单展开到合适高度，且向下的箭头顺时针旋转180度，退出时，二级菜单慢慢消失高度变为0，且箭头逆时针旋转180度。

**起始 API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.25 版本开始。

**变更的接口/组件**

菜单

**适配指导**

一级菜单弹出/退出动效行为变更，无需适配，二级菜单弹出/退出动效，可以调用subMenuExpandingMode接口设置动效模式