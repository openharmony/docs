# text_area.h
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @Zhang-Dong-hui-->
<!--Designer: @xiangyuan6-->
<!--Tester: @jiaoaozihao-->
<!--Adviser: @Brilliantry_Rui-->

## 概述

定义TextArea相关的枚举类型。TextArea组件用于接收多行文本输入，枚举值用于指定不同的输入类型，会影响输入内容的验证规则，例如支持基本输入、纯数字、电话号码、邮箱地址、验证码等模式。开发者可根据表单类型选择合适的枚举值，系统将自动提供对应的内容验证，从而优化用户输入体验并确保数据格式的正确性。

**引用文件：** <arkui/node_attributes/text_area.h>

**库：** libace_ndk.z.so

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**起始版本：** 12

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**相关示例：** <!--RP1-->[native_type_sample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/NativeType/native_type_sample)<!--RP1End-->

## 汇总

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [ArkUI_TextAreaType](#arkui_textareatype) | ArkUI_TextAreaType | 定义多行文本输入类型枚举值。不同的枚举值用于指定TextArea组件的输入类型，用于影响输入内容的验证规则。 |

## 枚举类型说明

### ArkUI_TextAreaType

```c
enum ArkUI_TextAreaType
```

**描述**

定义多行文本输入类型枚举值。不同的枚举值用于指定TextArea组件的输入类型，会影响输入内容的验证规则。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_TEXTAREA_TYPE_NORMAL = 0 | 基本输入模式，无特殊限制。 |
| ARKUI_TEXTAREA_TYPE_NUMBER = 2 | 纯数字输入模式。 |
| ARKUI_TEXTAREA_TYPE_PHONE_NUMBER = 3 | 电话号码输入模式。<br>支持输入数字、空格、+ 、-、*、#、(、)，长度不限。 |
| ARKUI_TEXTAREA_TYPE_EMAIL = 5 | 邮箱地址输入模式。<br>支持数字、字母、下划线、小数点、!、#、$、%、&、'、*、+、-、/、=、?、^、`、\{、\|、\}、~以及@字符（只能存在一个@字符）。邮箱地址格式需符合基本规范：@字符前为用户名部分，@字符后为域名部分。 |
| ARKUI_TEXTAREA_TYPE_ONE_TIME_CODE = 14 | 验证码输入模式，无特殊限制。该模式下组件获焦后会默认拉起系统输入法。<br>**起始版本：** 20 |


