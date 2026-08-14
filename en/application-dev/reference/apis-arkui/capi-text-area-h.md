# text_area.h

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @Zhang-Dong-hui-->
<!--Designer: @xiangyuan6-->
<!--Tester: @jiaoaozihao-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=1fff2d486e3243c0754f8adfd7ecd9495d7fddb9 translatedAt=2026-08-11T09:10:48.851Z pushedAt=2026-08-12T06:33:10.177Z -->

## Overview

Defines enumerations related to **TextArea**. The **TextArea** component is used for receiving multi-line text input. The enumerated values specify different input types, which affect the validation rules for input content, such as basic input, pure numbers, phone numbers, email addresses, and verification codes. You can select the appropriate enumerated value based on the form type, and the system will automatically provide corresponding content validation, thereby optimizing the user input experience and ensuring the correctness of the data format.

**File to include:** <arkui/node_attributes/text_area.h>

**Library:** libace_ndk.z.so

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Since:** 12

**Related module:** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**Sample:** <!--RP1-->[native_type_sample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/NativeType/native_type_sample)<!--RP1End-->

## Summary

### Enums

| Name | typedef Keyword | Description |
| -- | -- | -- |
| [ArkUI_TextAreaType](#arkui_textareatype) | ArkUI_TextAreaType | Enumerates the input types of multi-line text. Different enumerated values specify the input types of the **TextArea** component and affect the validation rules for the input content. |

## Enum Description

### ArkUI_TextAreaType

```c
enum ArkUI_TextAreaType
```

**Description**

Enumerates the input types of multi-line text. Different enumerated values specify the input types of the **TextArea** component and affect the validation rules for the input content.

**Since:** 12

| Value | Description |
| -- | -- |
| ARKUI_TEXTAREA_TYPE_NORMAL = 0 | Normal input type with no special restrictions. |
| ARKUI_TEXTAREA_TYPE_NUMBER = 2 | Numeric input type. |
| ARKUI_TEXTAREA_TYPE_PHONE_NUMBER = 3 | Phone number input type.<br>It supports digits, spaces, +, -, *, #, (, ), with no length limit. |
| ARKUI_TEXTAREA_TYPE_EMAIL = 5 | Email address input type.<br>It supports digits, letters, underscores, dots, !, #, $, %, &amp;, ', *, +, -, /, =, ?, ^, `, {, , }, ~, and @ (only one @ allowed). The email address must follow the basic format: the part before @ is the username, and the part after @ is the domain. |
| ARKUI_TEXTAREA_TYPE_ONE_TIME_CODE = 14 | Verification code input type with no special restrictions. In this type, the system input method is shown by default when the component gains focus.<br>**Since:** 20 |