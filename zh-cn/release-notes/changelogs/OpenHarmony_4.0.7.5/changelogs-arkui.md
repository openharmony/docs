# arkui子系统ChangeLog

## cl.arkui.1 Button组件hover状态效果变更

Button组件的hover状态由100-105%放大效果变更为0-5%不透明度的叠加效果，hover状态切换到press状态的效果变更为5-10%不透明度的叠加效果。

**变更影响**

影响Button的hover状态的视觉效果以及hover状态切换到press状态的视觉效果。

## cl.arkui.2 toast组件多行文本对齐方式

toast多行文本对齐方式由居中对齐变为左对齐

**变更影响**

影响toast文本提示框的多行文本的视觉效果。

## cl.arkui.3 SideBarContainer组件新增属性、修改属性默认值及新增显示模式

1、新增minContentWidth，默认值360vp，开发者未设置时为0vp。设置为小于0的值时按默认值显示。Embed场景下，增大组件尺寸时仅增大内容区的尺寸，缩小组件尺寸时，先缩小内容区的尺寸至minContentWidth，然后再缩小侧边栏的尺寸，当缩小侧边栏的尺寸至minSideBarWidth后，继续缩小组件尺寸时，会保持侧边栏最小尺寸，继续缩小内容区尺寸，并采用截断方式显示内容区，内容区尺寸可以缩小至0vp。minContentWidth优先于侧边栏的maxSideBarWidth与sideBarWidth属性，minContentWidth未设置时默认值优先级低于设置的minSideBarWidth与maxSideBarWidth属性。<br/>2、minSideBarWidth、SideBarWidth的默认宽度在API version 9及以下版本默认值为200vp，API version 10的默认值为240vp。
<br/>3、新增Auto显示模式，组件尺寸大于等于minSideBarWidth+minContentWidth时，采用Embed模式显示；组件尺寸小于minSideBarWidth+minContentWidth时，采用Overlay模式显示；未设置minSideBarWidth或minContentWidth时，会使用未设置接口的默认值进行计算，若计算后的值小于600vp，则使用600vp做为模式切换的断点值。。

**变更影响**

在API version 10下，影响SideBarContainer组件默认情况下的视觉效果。