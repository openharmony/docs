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
