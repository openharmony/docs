# OH_ArkUI_UserDataSpan
 <!--Kit: ArkUI-->
 <!--Subsystem: ArkUI-->
 <!--Owner: @carnivore233-->
 <!--Designer: @carnivore233-->
 <!--Tester: @mateng_Holtens-->
 <!--Adviser: @Brilliantry_Rui-->

```c
typedef struct OH_ArkUI_UserDataSpan OH_ArkUI_UserDataSpan
```

## 概述

定义用户数据Span样式，用于在富文本中为属性字符串附加自定义用户数据，以便在文本交互或自定义渲染时进行数据标识与关联。例如，在即时通讯应用中可为消息文本Span附加消息ID，在富文本编辑器中可为文本片段附加自定义样式标签等场景中使用。<br>调用[OH_ArkUI_UserDataSpan_Create](capi-styled-string-h.md#oh_arkui_userdataspan_create)接口创建用户数据Span样式对象。<br>使用完毕后应调用[OH_ArkUI_UserDataSpan_Destroy](capi-styled-string-h.md#oh_arkui_userdataspan_destroy)接口销毁用户数据Span样式对象。<br>创建成功后，可调用[OH_ArkUI_UserDataSpan_SetUserData](capi-styled-string-h.md#oh_arkui_userdataspan_setuserdata)接口设置用户数据。<br>调用[OH_ArkUI_UserDataSpan_GetUserData](capi-styled-string-h.md#oh_arkui_userdataspan_getuserdata)接口获取用户数据。

**起始版本：** 24

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**所在头文件：** [styled_string.h](capi-styled-string-h.md)