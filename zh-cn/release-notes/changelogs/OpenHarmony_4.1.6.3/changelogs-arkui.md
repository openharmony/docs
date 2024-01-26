# ArkUI子系统变更说明

## cl.arkui.1 TextInput/TextArea组件光标超出圆角部分截断显示效果变更

**访问级别**

公开接口

**变更原因**

该变更为非兼容性变更，当设置TextInput组件padding为0时，光标会显示在输入框默认圆角外，不符合应用诉求。

**变更影响**

API version 11变更前：输入框使用默认圆角， 设置padding为0，光标超出文本组件圆角部分未被截断。

API version 11变更后：输入框使用默认圆角， 设置padding为0，光标超出文本组件圆角部分会被截断。

**API Level**

11

**变更发生版本**

从OpenHarmony SDK 4.1.6.3开始。 

**变更的接口/组件**

TextInput/TextArea

**适配指导**

默认行为变更，不涉及适配。

## cl.arkui.2  Tabs组件的animationDuration属性异常值行为变更

**访问级别**

其他

**变更原因**

animationDuration属性设置为null时未按默认值处理。

**变更影响**

该变更为非兼容性变更。

API version 10及以前，animationDuration属性设置为null时，点击TabBar页签切换TabContent无动画。

API version 11及以后，animationDuration属性设置为null时，按默认值处理。即TabBar为BottomTabBarStyle样式时点击TabBar页签切换TabContent无动画，TabBar为其他样式时有动画，动画时长为默认值300ms。

**API Level**

11

**变更发生版本**

从OpenHarmony SDK 4.1.6.3 开始。

**变更的接口/组件**

受影响的组件：Tabs。

**适配指导**

变更前，若希望点击TabBar页签切换TabContent无动画，设置了animationDuration属性值为null。那么在变更后，API version 11及以后版本，需设置animationDuration属性值为0，API version 10及以前维持变更前规则，不会产生影响。
