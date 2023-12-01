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