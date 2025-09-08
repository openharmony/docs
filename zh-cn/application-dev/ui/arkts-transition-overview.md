# 转场动画概述
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @CCFFWW-->
<!--Designer: @CCFFWW-->
<!--Tester: @lxl007-->
<!--Adviser: @HelloCrease-->


转场动画是指对将要出现或消失的组件做动画，对始终出现的组件做动画应使用[属性动画](arkts-attribute-animation-overview.md)。转场动画主要为了让开发者从繁重的消失节点管理中解放出来，如果用属性动画做组件转场，开发者需要在动画结束回调中删除组件节点。同时，由于动画结束前已经删除的组件节点可能会重新出现，还需要在结束回调中增加对节点状态的判断。


转场动画分为基础转场和高级模板化转场，有如下几类：


- [出现/消失转场](arkts-enter-exit-transition.md)：对新增、消失的控件实现动画效果，是通用的基础转场效果。

- [导航转场](arkts-navigation-navigation.md#导航示例)：页面的路由转场方式，对应一个界面消失，另外一个界面出现的动画效果，如设置应用一级菜单切换到二级界面。

- [模态转场](arkts-modal-transition.md)：新的界面覆盖在旧的界面之上的动画，旧的界面不消失，新的界面出现，如弹框就是典型的模态转场动画。

- [共享元素转场 (一镜到底)](arkts-shared-element-transition.md)：共享元素转场是一种界面切换时对相同或者相似的元素做的一种位置和大小匹配的过渡动画效果。

- [页面转场动画（不推荐）](arkts-page-transition-animation.md)：页面的路由转场方式，可以通过在pageTransition函数中自定义页面入场和页面退场的转场动效。为了实现更好的转场效果，推荐使用[导航转场](arkts-navigation-navigation.md)和[模态转场](arkts-modal-transition.md)。

- [旋转屏动画](arkts-rotation-transition-animation.md)：旋转屏动画主要分为两类：[布局切换的旋转屏动画](arkts-rotation-transition-animation.md#布局切换的旋转屏动画)和[透明度变化的旋转屏动画](arkts-rotation-transition-animation.md#透明度变化的旋转屏动画)，旨在实现屏幕显示方向变化时的自然过渡。
