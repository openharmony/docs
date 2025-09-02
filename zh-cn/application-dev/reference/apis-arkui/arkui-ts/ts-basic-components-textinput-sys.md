# TextInput (系统接口)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @kangshihui-->
<!--Designer: @pssea-->
<!--Tester: @jiaoaozihao-->
<!--Adviser: @HelloCrease-->

单行文本输入框组件。

>  **说明：**
>
>  该组件从API version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
>  当前页面仅包含本模块的系统接口，其他公开接口参见[TextInput](ts-basic-components-textinput.md)。

## InputType枚举说明

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称                                 | 值 | 说明                                       |
| ---------------------------------- | --- | ---------------------------------------- |
| SCREEN_LOCK_PASSWORD<sup>11+</sup> | 9 | 锁屏应用密码输入模式。支持输入数字、字母、下划线、空格、特殊字符。密码显示小眼睛图标并且默认会将文字变成圆点，从API version 12开始，特定设备上输入文字直接显示为圆点。密码输入模式不支持下划线样式。 <br>**系统接口：** 此接口为系统接口。 |


