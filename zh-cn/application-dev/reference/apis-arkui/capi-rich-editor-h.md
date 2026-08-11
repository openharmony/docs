# rich_editor.h
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @carnivore233-->
<!--Designer: @xiangyuan6-->
<!--Tester: @jiaoaozihao-->
<!--Adviser: @Brilliantry_Rui-->

## 概述

定义文本编辑器相关的结构体、枚举和函数。文本编辑器提供富文本编辑能力，支持自定义文本选择菜单、属性字符串控制器、段落样式和文本样式设置，以及触感反馈控制等功能，适用于需要在应用中实现富文本编辑和自定义交互菜单的场景。

**引用文件：** <arkui/node_attributes/rich_editor.h>

**库：** libace_ndk.z.so

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**起始版本：** 24

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**相关示例：** <!--RP1-->[native_type_sample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/NativeType/native_type_sample)<!--RP1End-->

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_ArkUI_TextEditorSelectionMenuOptions](capi-arkui-nativemodule-oh-arkui-texteditorselectionmenuoptions.md) | OH_ArkUI_TextEditorSelectionMenuOptions | 定义文本编辑器的文本选择菜单选项。 |
| [OH_ArkUI_TextEditorPlaceholderOptions](capi-arkui-nativemodule-oh-arkui-texteditorplaceholderoptions.md) | OH_ArkUI_TextEditorPlaceholderOptions | 定义文本编辑器无输入时的提示文本选项。 |
| [OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md) | OH_ArkUI_TextEditorStyledStringController | 定义文本编辑器的属性字符串控制器。 |
| [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md) | OH_ArkUI_TextEditorParagraphStyle | 定义文本编辑器的段落样式。 |
| [OH_ArkUI_TextEditorTextStyle](capi-arkui-nativemodule-oh-arkui-texteditortextstyle.md) | OH_ArkUI_TextEditorTextStyle | 定义文本编辑器的文本样式。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_ArkUI_HapticFeedbackMode](#oh_arkui_hapticfeedbackmode) | OH_ArkUI_HapticFeedbackMode | 触感反馈模式枚举。 |
| [OH_ArkUI_TextEditorSpanType](#oh_arkui_texteditorspantype) | OH_ArkUI_TextEditorSpanType | 自定义文本选择菜单span类型枚举。 |
| [OH_ArkUI_TextEditorResponseType](#oh_arkui_texteditorresponsetype) | OH_ArkUI_TextEditorResponseType | 自定义文本选择菜单响应类型枚举。 |
| [OH_ArkUI_TextMenuType](#oh_arkui_textmenutype) | OH_ArkUI_TextMenuType | 文本菜单类型枚举。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_ArkUI_TextEditorPlaceholderOptions* OH_ArkUI_TextEditorPlaceholderOptions_Create()](#oh_arkui_texteditorplaceholderoptions_create) | 创建一个无输入时的提示文本的选项对象。当该对象不再使用时，请调用[OH_ArkUI_TextEditorPlaceholderOptions_Destroy](#oh_arkui_texteditorplaceholderoptions_destroy)销毁。 |
| [void OH_ArkUI_TextEditorPlaceholderOptions_Destroy(OH_ArkUI_TextEditorPlaceholderOptions* options)](#oh_arkui_texteditorplaceholderoptions_destroy) | 销毁无输入时的提示文本的选项对象。 |
| [OH_ArkUI_TextEditorStyledStringController* OH_ArkUI_TextEditorStyledStringController_Create()](#oh_arkui_texteditorstyledstringcontroller_create) | 创建一个属性字符串控制器对象。当该对象不再使用时，请调用[OH_ArkUI_TextEditorStyledStringController_Destroy](#oh_arkui_texteditorstyledstringcontroller_destroy)销毁。 |
| [void OH_ArkUI_TextEditorStyledStringController_Destroy(OH_ArkUI_TextEditorStyledStringController* controller)](#oh_arkui_texteditorstyledstringcontroller_destroy) | 销毁属性字符串控制器。 |
| [OH_ArkUI_TextEditorParagraphStyle* OH_ArkUI_TextEditorParagraphStyle_Create()](#oh_arkui_texteditorparagraphstyle_create) | 创建一个段落样式对象。当该对象不再使用时，请调用[OH_ArkUI_TextEditorParagraphStyle_Destroy](#oh_arkui_texteditorparagraphstyle_destroy)销毁。 |
| [void OH_ArkUI_TextEditorParagraphStyle_Destroy(OH_ArkUI_TextEditorParagraphStyle* style)](#oh_arkui_texteditorparagraphstyle_destroy) | 销毁段落样式对象。 |
| [OH_ArkUI_TextEditorTextStyle* OH_ArkUI_TextEditorTextStyle_Create()](#oh_arkui_texteditortextstyle_create) | 创建一个文本样式对象。当该对象不再使用时，请调用[OH_ArkUI_TextEditorTextStyle_Destroy](#oh_arkui_texteditortextstyle_destroy)销毁。 |
| [void OH_ArkUI_TextEditorTextStyle_Destroy(OH_ArkUI_TextEditorTextStyle* style)](#oh_arkui_texteditortextstyle_destroy) | 销毁文本样式对象。 |
| [OH_ArkUI_TextEditorSelectionMenuOptions* OH_ArkUI_TextEditorSelectionMenuOptions_Create()](#oh_arkui_texteditorselectionmenuoptions_create) | 创建一个文本编辑器文本选择菜单选项对象。当该对象不再使用时，请调用[OH_ArkUI_TextEditorSelectionMenuOptions_Destroy](#oh_arkui_texteditorselectionmenuoptions_destroy)销毁。 |
| [void OH_ArkUI_TextEditorSelectionMenuOptions_Destroy(OH_ArkUI_TextEditorSelectionMenuOptions* options)](#oh_arkui_texteditorselectionmenuoptions_destroy) | 销毁文本编辑器文本选择菜单选项对象。 |

## 枚举类型说明

### OH_ArkUI_HapticFeedbackMode

```c
enum OH_ArkUI_HapticFeedbackMode
```

**描述**

触感反馈模式枚举，用于控制文本编辑器在用户交互（如长按、拖拽等操作）时的触感反馈行为。

**起始版本：** 24

| 枚举项 | 描述 |
| -- | -- |
| OH_ARKUI_HAPTIC_FEEDBACK_MODE_DISABLED = 0 | 无振动效果。 |
| OH_ARKUI_HAPTIC_FEEDBACK_MODE_ENABLED = 1 | 有振动效果。 |
| OH_ARKUI_HAPTIC_FEEDBACK_MODE_AUTO = 2 | 跟随系统的振动效果。 |

### OH_ArkUI_TextEditorSpanType

```c
enum OH_ArkUI_TextEditorSpanType
```

**描述**

自定义文本选择菜单span类型枚举，用于标识文本编辑器中文本选择菜单的span类型。不同span类型对应不同的内容结构，影响自定义菜单的显示和交互行为。例如，当用户选中纯文本内容时使用TEXT类型，选中包含图文等混合内容时使用MIXED类型，需要自定义菜单项布局时使用BUILDER类型。

**起始版本：** 24

| 枚举项 | 描述 |
| -- | -- |
| OH_ARKUI_TEXT_EDITOR_SPAN_TYPE_TEXT = 0 | 文本span。 |
| OH_ARKUI_TEXT_EDITOR_SPAN_TYPE_IMAGE = 1 | 图片span。 |
| OH_ARKUI_TEXT_EDITOR_SPAN_TYPE_MIXED = 2 | 混合span。 |
| OH_ARKUI_TEXT_EDITOR_SPAN_TYPE_BUILDER = 3 | 自定义布局span。 |
| OH_ARKUI_TEXT_EDITOR_SPAN_TYPE_DEFAULT = 4 | 默认span。 |

### OH_ArkUI_TextEditorResponseType

```c
enum OH_ArkUI_TextEditorResponseType
```

**描述**

自定义文本选择菜单响应类型枚举，用于标识触发菜单弹出的交互方式。不同响应类型对应不同的用户操作（如右键点击、长按、鼠标选中），可根据响应类型定制不同的菜单内容。

**起始版本：** 24

| 枚举项 | 描述 |
| -- | -- |
| OH_ARKUI_TEXT_EDITOR_RESPONSE_TYPE_RIGHT_CLICK = 0 | 通过鼠标右键触发菜单弹出。 |
| OH_ARKUI_TEXT_EDITOR_RESPONSE_TYPE_LONG_PRESS = 1 | 通过长按触发菜单弹出。 |
| OH_ARKUI_TEXT_EDITOR_RESPONSE_TYPE_SELECT = 2 | 通过鼠标选中触发菜单弹出。 |
| OH_ARKUI_TEXT_EDITOR_RESPONSE_TYPE_DEFAULT = 3 | 默认响应类型。 |

### OH_ArkUI_TextMenuType

```c
enum OH_ArkUI_TextMenuType
```

**描述**

文本菜单类型枚举，用于区分文本编辑器中不同类型的弹出菜单，包括文本选择菜单和预览菜单。不同菜单类型分别对应不同的交互场景和菜单展示方式。例如，文本选择菜单在用户选中文字时弹出，用于复制、删除等文本操作；预览菜单在用户长按图片时弹出，用于触发图片内容拖拽预览以及复制、删除等操作。

**起始版本：** 24

| 枚举项 | 描述 |
| -- | -- |
| OH_ARKUI_TEXT_EDITOR_SELECTION_MENU = 0 | 文本选择菜单。 |
| OH_ARKUI_TEXT_EDITOR_PREVIEW_MENU = 1 | 预览菜单。 |


## 函数说明

### OH_ArkUI_TextEditorPlaceholderOptions_Create()

```c
OH_ArkUI_TextEditorPlaceholderOptions* OH_ArkUI_TextEditorPlaceholderOptions_Create()
```

**描述**

创建一个无输入时的提示文本的选项对象。当该对象不再使用时，请调用[OH_ArkUI_TextEditorPlaceholderOptions_Destroy](#oh_arkui_texteditorplaceholderoptions_destroy)销毁。

**起始版本：** 24

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_ArkUI_TextEditorPlaceholderOptions*](capi-arkui-nativemodule-oh-arkui-texteditorplaceholderoptions.md) | 指向[OH_ArkUI_TextEditorPlaceholderOptions](capi-arkui-nativemodule-oh-arkui-texteditorplaceholderoptions.md)对象的指针。 |

### OH_ArkUI_TextEditorPlaceholderOptions_Destroy()

```c
void OH_ArkUI_TextEditorPlaceholderOptions_Destroy(OH_ArkUI_TextEditorPlaceholderOptions* options)
```

**描述**

销毁无输入时的提示文本的选项对象。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_TextEditorPlaceholderOptions](capi-arkui-nativemodule-oh-arkui-texteditorplaceholderoptions.md)* options | 指向[OH_ArkUI_TextEditorPlaceholderOptions](capi-arkui-nativemodule-oh-arkui-texteditorplaceholderoptions.md)对象的指针。 |

### OH_ArkUI_TextEditorStyledStringController_Create()

```c
OH_ArkUI_TextEditorStyledStringController* OH_ArkUI_TextEditorStyledStringController_Create()
```

**描述**

创建一个属性字符串控制器对象，用于在需要通过属性字符串管理富文本内容（如混合排版文本与图片、动态设置段落或字符样式等场景）时控制文本编辑器的属性字符串。当该对象不再使用时，请调用[OH_ArkUI_TextEditorStyledStringController_Destroy](#oh_arkui_texteditorstyledstringcontroller_destroy)销毁。

**起始版本：** 24

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_ArkUI_TextEditorStyledStringController*](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md) | 指向[OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md)对象的指针。 |

### OH_ArkUI_TextEditorStyledStringController_Destroy()

```c
void OH_ArkUI_TextEditorStyledStringController_Destroy(OH_ArkUI_TextEditorStyledStringController* controller)
```

**描述**

销毁属性字符串控制器。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md)* controller | 指向[OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md)对象的指针。 |

### OH_ArkUI_TextEditorParagraphStyle_Create()

```c
OH_ArkUI_TextEditorParagraphStyle* OH_ArkUI_TextEditorParagraphStyle_Create()
```

**描述**

创建一个段落样式对象。当该对象不再使用时，请调用[OH_ArkUI_TextEditorParagraphStyle_Destroy](#oh_arkui_texteditorparagraphstyle_destroy)销毁。

**起始版本：** 24

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_ArkUI_TextEditorParagraphStyle*](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md) | 指向[OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md)对象的指针。 |

### OH_ArkUI_TextEditorParagraphStyle_Destroy()

```c
void OH_ArkUI_TextEditorParagraphStyle_Destroy(OH_ArkUI_TextEditorParagraphStyle* style)
```

**描述**

销毁段落样式对象。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md)* style | 指向[OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md)对象的指针。 |

### OH_ArkUI_TextEditorTextStyle_Create()

```c
OH_ArkUI_TextEditorTextStyle* OH_ArkUI_TextEditorTextStyle_Create()
```

**描述**

创建一个文本样式对象。当该对象不再使用时，请调用[OH_ArkUI_TextEditorTextStyle_Destroy](#oh_arkui_texteditortextstyle_destroy)销毁。

**起始版本：** 24

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_ArkUI_TextEditorTextStyle*](capi-arkui-nativemodule-oh-arkui-texteditortextstyle.md) | 指向[OH_ArkUI_TextEditorTextStyle](capi-arkui-nativemodule-oh-arkui-texteditortextstyle.md)对象的指针。 |

### OH_ArkUI_TextEditorTextStyle_Destroy()

```c
void OH_ArkUI_TextEditorTextStyle_Destroy(OH_ArkUI_TextEditorTextStyle* style)
```

**描述**

销毁文本样式对象。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_TextEditorTextStyle](capi-arkui-nativemodule-oh-arkui-texteditortextstyle.md)* style | 指向[OH_ArkUI_TextEditorTextStyle](capi-arkui-nativemodule-oh-arkui-texteditortextstyle.md)对象的指针。 |

### OH_ArkUI_TextEditorSelectionMenuOptions_Create()

```c
OH_ArkUI_TextEditorSelectionMenuOptions* OH_ArkUI_TextEditorSelectionMenuOptions_Create()
```

**描述**

创建一个文本编辑器文本选择菜单选项对象。当该对象不再使用时，请调用[OH_ArkUI_TextEditorSelectionMenuOptions_Destroy](#oh_arkui_texteditorselectionmenuoptions_destroy)销毁。

**起始版本：** 24

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_ArkUI_TextEditorSelectionMenuOptions*](capi-arkui-nativemodule-oh-arkui-texteditorselectionmenuoptions.md) | 指向[OH_ArkUI_TextEditorSelectionMenuOptions](capi-arkui-nativemodule-oh-arkui-texteditorselectionmenuoptions.md)对象的指针。 |

### OH_ArkUI_TextEditorSelectionMenuOptions_Destroy()

```c
void OH_ArkUI_TextEditorSelectionMenuOptions_Destroy(OH_ArkUI_TextEditorSelectionMenuOptions* options)
```

**描述**

销毁文本编辑器文本选择菜单选项对象。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_TextEditorSelectionMenuOptions](capi-arkui-nativemodule-oh-arkui-texteditorselectionmenuoptions.md)* options | 指向[OH_ArkUI_TextEditorSelectionMenuOptions](capi-arkui-nativemodule-oh-arkui-texteditorselectionmenuoptions.md)对象的指针。 |


