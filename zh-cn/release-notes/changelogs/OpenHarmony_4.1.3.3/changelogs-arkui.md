# ArkUI子系统变更说明

## cl.arkui.1 手势事件出参中的控件坐标系数据规格明确

**访问级别**

公开接口

**变更原因**

以往组件经过平移、旋转、缩放变换后，事件响应的控件坐标是错误的，不能对应到控件坐标系。

**变更影响**

此次变更，会返回开发者准确的控件坐标系下的数据。

**变更发生版本**

从OpenHarmony SDK 4.1.3.3开始。

**变更的接口/组件**

* GestureEvent中的offsetX、offsetY、pinchCenterX、pinchCenterY、speed。

* FingerInfo中的localX、localY。

* ClickEvent中的x、y。

* TouchObject中的x、y。

**适配指导**

此次变更，会返回开发者准确的控件坐标下的数据，无需新增适配。

## cl.ArkUI.2 TextInput组件selectBackgroundColor接口变更

**访问级别**
公开接口

**变更原因**
使用selectedBackgroundColor设置ResourceColor，未设置不透明度时，选中文本会遮罩所选文字。

**变更影响**
该变更为兼容性变更，在开发者设置selectedBackgroundColor的ResourceColor时，如果未指明不透明度，默认设置20%的不透明度。

**变更发生版本**
从OpenHarmony SDK 4.1.3.3开始。

**变更的接口/组件**
TextInput组件的selectedBackgroundColor接口。

**适配指导**
默认行为变更，不涉及适配。

## cl.ArkUI.3 Tabs组件animationDuration属性默认行为变更

**访问级别**

公开接口

**变更原因**

Tabs组件animationDuration属性的默认行为未保持一致。
不设置animationDuration属性值时，点击TabBar页签切换TabContent无动画；设置为小于0的异常值时，点击TabBar页签切换TabContent有动画，按默认值300ms显示。

**变更影响**

该变更为非兼容性变更。
API version 10及以前，Tabs组件不设置animationDuration属性值时，点击TabBar页签切换TabContent无动画。
API version 11及以后，Tabs组件不设置animationDuration属性值时，点击TabBar页签切换TabContent有动画，动画时长为默认值300ms。

**变更发生版本**

从OpenHarmony SDK 4.1.3.3 开始。

**变更的接口/组件**

Tabs组件的animationDuration属性。

**适配指导**

变更前，若希望点击TabBar页签切换TabContent无动画，可以不设置animationDuration属性值或设置animationDuration属性值为0。
变更后，若希望点击TabBar页签切换TabContent无动画，API version 11及以后，需设置animationDuration属性值为0，API version 10及以前维持变更前规则，不会产生影响。

## cl.ArkUI.4 TextInput组件padding接口变更

**访问级别**

公开接口

**变更原因**

使用padding设置{left:10vp}，未设置上下右内边距，上下右内边距实际效果为0，不是TextInput组件padding默认值。

**变更影响**

该变更为非兼容性变更，在开发者设置padding{left:10vp}时，如果未指明上下右内边距，则上下内边距走默认值16vp,右内边距8vp。

**变更发生版本**

缺陷修复, 所有版本生效。

**变更的接口/组件**

TextInput组件的padding接口。

**适配指导**

此次变更,若开发者希望TextInput组件左内边距为10vp,上下右内边距为0vp,需要显示指定{left:10vp, right:0vp, top:0vp, bottom:0vp}, 未指明的各方向内边距均走TextInput组件padding默认值。

## cl.ArkUI.5 Text组件换行高度规格明确

**访问级别**

其他

**变更原因**

Text组件换行高度应该和字号大小保持一致，非固定值14px。

**变更影响**

该变更为非兼容性变更。

API Version 10及以前在开发者设置fontSize('20px')时，Text组件内容换行高度为14px, Text组件子组件Span换行高度也是固定值14px。

API Version 11及以后在开发者设置fontSize('20px')时，Text组件内容换行高度则为20px, Text组件子组件Span换行高度还是固定值14px。

**变更发生版本**

从OpenHarmony SDK 4.1.3.3开始。

**变更的接口/组件**

Text组件。

**适配指导**

默认行为变更，不涉及适配。

## cl.ArkUI.6 Scroller调用scrollTo方法控制Grid组件跳转Bug修复

**访问级别**

公开接口

**变更原因**

 Scroller调用scrollTo方法控制Grid组件跳转超过Grid当前页面主轴方向高度距离时，存在跳转位置会有rowsGap*行数的误差的Bug。现问题已修复。

**变更影响**

该变更为兼容性变更。此次变更，开发者使用Scroller调用scrollTo方法控制Grid组件跳转时，会跳转到更精确的位置。

**API Level**

7

**变更发生版本**

从OpenHarmony 4.1.3.3开始。

**变更的接口/组件**

变更前：Grid组件，调用Scroller的scrollTo接口，跳转超过一屏时，跳转位置会有rowsGap*行数的误差。

变更后：Grid组件，调用Scroller的scrollTo接口，跳转超过一屏时，跳转位置会更精确。

**适配指导**

此次变更，Scroller调用scrollTo方法控制Grid组件跳转位置会更精确，不涉及适配。