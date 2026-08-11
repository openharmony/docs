# ArkUI_NodeAttributeType（富文本类组件相关属性）
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @xiangyuan6; @carnivore233-->
<!--Designer: @xiangyuan6; @xiangyuan6-->
<!--Tester: @jiaoaozihao-->
<!--Adviser: @Brilliantry_Rui-->

```c
enum ArkUI_NodeAttributeType
```

## 概述

定义ArkUI在Native侧可以设置的富文本类组件属性样式集合，用于定制TextEditor组件的外观样式、交互行为和排版效果，满足不同业务场景下对富文本编辑器的差异化配置需求。

**起始版本：** 24

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**所在头文件：** [native_node.h](capi-native-node-h.md)

## NODE_TEXT_EDITOR_ENTER_KEY_TYPE

```c
NODE_TEXT_EDITOR_ENTER_KEY_TYPE = MAX_NODE_SCOPE_NUM * ARKUI_NODE_TEXT_EDITOR = 22000
```

TextEditor组件回车键类型，支持属性设置、属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 回车键类型，参数类型[ArkUI_EnterKeyType](capi-text-common-h.md#arkui_enterkeytype)，默认值为ARKUI_ENTER_KEY_TYPE_NEW_LINE。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 回车键类型，参数类型[ArkUI_EnterKeyType](capi-text-common-h.md#arkui_enterkeytype)。 |

## NODE_TEXT_EDITOR_CARET_COLOR

```c
NODE_TEXT_EDITOR_CARET_COLOR = 22001
```

TextEditor组件光标颜色，支持属性设置、属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].u32 | 光标颜色，采用0xARGB格式，例如0xFFFF0000表示红色。默认跟随系统主题。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].u32 | 光标颜色，采用0xARGB格式，例如0xFFFF0000表示红色。默认跟随系统主题。 |

## NODE_TEXT_EDITOR_SCROLL_BAR_COLOR

```c
NODE_TEXT_EDITOR_SCROLL_BAR_COLOR = 22002
```

TextEditor组件滚动条颜色，支持属性设置、属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .data[0].u32 | 滚动条颜色，采用0xARGB格式，例如0xFFFF0000表示红色。默认跟随系统主题。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .data[0].u32 | 滚动条颜色，采用0xARGB格式，例如0xFFFF0000表示红色。默认跟随系统主题。 |

## NODE_TEXT_EDITOR_BAR_STATE

```c
NODE_TEXT_EDITOR_BAR_STATE = 22003
```

TextEditor组件滚动条显示模式，支持属性设置、属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 滚动条显示模式，参数类型[ArkUI_BarState](capi-scroll-h.md#arkui_barstate)，默认值为ARKUI_BAR_STATE_AUTO。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 滚动条显示模式，参数类型[ArkUI_BarState](capi-scroll-h.md#arkui_barstate)。 |

## NODE_TEXT_EDITOR_ENABLE_DATA_DETECTOR

```c
NODE_TEXT_EDITOR_ENABLE_DATA_DETECTOR = 22004
```

TextEditor组件文本实体识别功能开关，启用后，文本中的电话号码、邮箱、链接等实体将被自动识别并标记为可交互内容。配合NODE_TEXT_EDITOR_DATA_DETECTOR_CONFIG属性可自定义识别类型和交互行为。支持属性设置、属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 是否启用文本实体识别功能，0表示禁用，1表示启用，默认值为0。推荐在需要自动识别并高亮文本中实体信息的场景下设置此属性。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 是否启用了文本实体识别功能，0表示禁用，1表示启用。 |

## NODE_TEXT_EDITOR_DATA_DETECTOR_CONFIG

```c
NODE_TEXT_EDITOR_DATA_DETECTOR_CONFIG = 22005
```

TextEditor组件文本实体识别配置，设置后，可配置识别类型、实体显示样式，并可选择是否开启长按预览功能。配合NODE_TEXT_EDITOR_ENABLE_DATA_DETECTOR属性使用，支持属性设置和属性重置。<br>
作为属性设置方法参数[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .object | 文本实体识别配置，设置后可指定需要识别的文本实体类型（如电话号码、邮箱、链接等）及识别后的交互行为。仅在启用文本实体识别功能(NODE_TEXT_EDITOR_ENABLE_DATA_DETECTOR设置为1)后传入此参数以自定义识别类型，不传入时使用系统默认识别配置。参数类型[ArkUI_TextDataDetectorConfig](capi-arkui-nativemodule-oh-arkui-textdatadetectorconfig.md)。 |

## NODE_TEXT_EDITOR_EDIT_MENU_OPTIONS

```c
NODE_TEXT_EDITOR_EDIT_MENU_OPTIONS = 22006
```

TextEditor组件扩展菜单选项，支持属性设置和属性重置。<br>
作为属性设置方法参数[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .object | 扩展菜单选项，设置后可自定义默认菜单项的行为，或添加自定义选项内容。参数类型[ArkUI_TextEditMenuOptions](capi-arkui-nativemodule-arkui-texteditmenuoptions.md)。 |

## NODE_TEXT_EDITOR_PLACEHOLDER

```c
NODE_TEXT_EDITOR_PLACEHOLDER = 22007
```

TextEditor组件无输入时的提示文本选项，支持属性设置和属性重置。<br>
作为属性设置方法参数[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .object | 无输入时的提示文本选项，参数类型[ArkUI_TextEditorPlaceholderOptions](capi-arkui-nativemodule-oh-arkui-texteditorplaceholderoptions.md)。不传入时，编辑器无输入状态下不显示提示文本。 |

## NODE_TEXT_EDITOR_STYLED_STRING_CONTROLLER

```c
NODE_TEXT_EDITOR_STYLED_STRING_CONTROLLER = 22008
```

TextEditor组件属性字符串控制器，支持属性设置。设置后，可通过该控制器管理TextEditor中的内容、光标、选区、输入样式及编辑状态。<br>
作为属性设置方法参数[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .object | 属性字符串控制器，参数类型[ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md)。 |

## NODE_TEXT_EDITOR_ENABLE_PREVIEW_TEXT

```c
NODE_TEXT_EDITOR_ENABLE_PREVIEW_TEXT = 22009
```

TextEditor组件预上屏功能开关，启用后，组件内显示输入法输入过程中的拼音、笔画字符。支持属性设置、属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 是否启用预上屏功能，0表示禁用，1表示启用，默认值为1。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 是否启用预上屏功能，0表示禁用，1表示启用。 |

## NODE_TEXT_EDITOR_LAYOUT_MANAGER

```c
NODE_TEXT_EDITOR_LAYOUT_MANAGER = 22010
```

TextEditor组件TextLayoutManager获取，获取后，可通过布局管理器查询文本的布局信息，如行数、行高和内容偏移等。支持属性获取。<br>
作为属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 24


**返回：**

| 类型 | 说明 |
| -- | -- |
| .object | 布局管理器，可通过该管理器查询文本的布局信息。参数类型[ArkUI_TextLayoutManager](capi-arkui-nativemodule-arkui-textlayoutmanager.md)。 |

## NODE_TEXT_EDITOR_ENABLE_SELECTED_DATA_DETECTOR

```c
NODE_TEXT_EDITOR_ENABLE_SELECTED_DATA_DETECTOR = 22011
```

TextEditor组件文本选择识别AI菜单开关，支持属性设置、属性重置和属性获取。启用后，用户选中特殊文本实体时将弹出AI识别菜单，提供基于选中文本内容的智能识别和操作选项。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 是否启用文本选择识别的AI菜单，0表示禁用，1表示启用，默认值为1。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 是否启用了文本选择识别的AI菜单，0表示禁用，1表示启用。 |

## NODE_TEXT_EDITOR_SELECTED_BACKGROUND_COLOR

```c
NODE_TEXT_EDITOR_SELECTED_BACKGROUND_COLOR = 22012
```

TextEditor组件选中内容背景颜色，支持属性设置、属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .data[0].u32 | 选中内容的背景颜色，采用0xARGB格式，例如0xFFFF0000表示红色。默认跟随系统主题。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .data[0].u32 | 选中内容的背景颜色，采用0xARGB格式，例如0xFFFF0000表示红色。默认跟随系统主题。 |

## NODE_TEXT_EDITOR_ENABLE_KEYBOARD_ON_FOCUS

```c
NODE_TEXT_EDITOR_ENABLE_KEYBOARD_ON_FOCUS = 22013
```

TextEditor组件非点击获焦时拉起输入法开关，支持属性设置、属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 非点击获焦时是否拉起输入法，0表示不拉起，1表示拉起，默认值为1。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 非点击获焦时是否拉起输入法，0表示不拉起，1表示拉起。 |

## NODE_TEXT_EDITOR_MAX_LENGTH

```c
NODE_TEXT_EDITOR_MAX_LENGTH = 22014
```

TextEditor组件最大字符数，支持属性设置、属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 文本编辑器允许输入的最大长度，取值范围为[0, +∞)，超出此限制后将阻止继续输入文本。设置为0、负数或未设置该属性时不限制输入长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 文本编辑器允许输入的最大长度。 |

## NODE_TEXT_EDITOR_MAX_LINES

```c
NODE_TEXT_EDITOR_MAX_LINES = 22015
```

TextEditor组件内容最大行数，支持属性设置、属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 文本编辑器最大行数限制，取值范围：(0, +∞)。设置为0、负数或未设置该属性时，取默认值UINT32_MAX，不限制行数。建议在需要固定显示高度的场景下设置该参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 文本编辑器最大行数限制。 |

## NODE_TEXT_EDITOR_ENABLE_HAPTIC_FEEDBACK

```c
NODE_TEXT_EDITOR_ENABLE_HAPTIC_FEEDBACK = 22016
```

TextEditor组件触感反馈开关，启用后，在文本拖选等交互操作时将产生触感反馈震动响应，支持属性设置、属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 是否在文本编辑器中启用触感反馈，0表示不启用，1表示启用，默认值为1。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 是否启用了触感反馈，0表示不启用，1表示启用。 |

## NODE_TEXT_EDITOR_COPY_OPTIONS

```c
NODE_TEXT_EDITOR_COPY_OPTIONS = 22017
```

TextEditor组件复制选项，支持属性设置、属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 复制选项，参数类型[ArkUI_CopyOptions](capi-native-type-h.md#arkui_copyoptions)，默认值为ARKUI_COPY_OPTIONS_LOCAL_DEVICE。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 复制选项，参数类型[ArkUI_CopyOptions](capi-native-type-h.md#arkui_copyoptions)。 |

## NODE_TEXT_EDITOR_KEYBOARD_APPEARANCE

```c
NODE_TEXT_EDITOR_KEYBOARD_APPEARANCE = 22018
```

TextEditor组件键盘外观，支持属性设置、属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 键盘外观，参数类型[ArkUI_KeyboardAppearance](capi-text-common-h.md#arkui_keyboardappearance)，默认值为ARKUI_KEYBOARD_APPEARANCE_NONE_IMMERSIVE。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 文本编辑器当前设置的键盘外观类型，参数类型[ArkUI_KeyboardAppearance](capi-text-common-h.md#arkui_keyboardappearance)。 |

## NODE_TEXT_EDITOR_STOP_BACK_PRESS

```c
NODE_TEXT_EDITOR_STOP_BACK_PRESS = 22019
```

TextEditor组件是否阻止返回键事件向上层传播，支持属性设置、属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 是否阻止返回事件传播，0表示不阻止，1表示阻止，默认值为0。推荐在编辑器有未保存内容或需要拦截返回键防止意外退出的场景设置为1。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 是否阻止返回事件传播，0表示不阻止，1表示阻止。 |

## NODE_TEXT_EDITOR_ENABLE_AUTO_SPACING

```c
NODE_TEXT_EDITOR_ENABLE_AUTO_SPACING = 22020
```

TextEditor组件中西文自动间距开关，支持属性设置、属性重置和属性获取。适用于包含中英文混排内容的编辑场景，启用后可在中文与西文之间自动添加间距，改善混排文本的阅读体验。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 是否启用中西文自动间距，0表示不启用，1表示启用，默认值为0。推荐在包含中英文混排内容的编辑场景设置为1，以改善混排文本的阅读体验。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 是否启用中西文自动间距，0表示不启用，1表示启用。 |

## NODE_TEXT_EDITOR_CUSTOM_KEYBOARD

```c
NODE_TEXT_EDITOR_CUSTOM_KEYBOARD = 22021
```

TextEditor组件自定义键盘。当需要替换系统默认键盘时传入此参数（如数字键盘、表情键盘等特殊输入布局），不传入时使用系统默认键盘。支持属性设置、属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .object | 自定义键盘，参数类型[ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md)。 |
| .value[0]?.i32 | 设置自定义键盘是否支持内容避让功能，即键盘弹出时页面内容自动调整位置以避免被键盘遮挡，0表示不支持，1表示支持，默认值为0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .object | 自定义键盘，参数类型[ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md)。 |
| .value[0].i32 | 自定义键盘是否支持内容避让功能，即键盘弹出时页面内容自动调整位置以避免被键盘遮挡，0表示不支持，1表示支持。 |

## NODE_TEXT_EDITOR_BIND_SELECTION_MENU

```c
NODE_TEXT_EDITOR_BIND_SELECTION_MENU = 22022
```

TextEditor组件自定义文本选择菜单绑定，支持属性设置和属性重置。<br>
作为属性设置方法参数[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .object | 自定义选择菜单，不传入时使用系统默认文本选择菜单。参数类型[ArkUI_TextEditorSelectionMenuOptions](capi-arkui-nativemodule-oh-arkui-texteditorselectionmenuoptions.md)。 |

## NODE_TEXT_EDITOR_INCLUDE_FONT_PADDING

```c
NODE_TEXT_EDITOR_INCLUDE_FONT_PADDING = 22023
```

TextEditor组件首行尾行防截断间距开关，启用后，在首行和尾行增加间距以避免文字截断，支持属性设置、属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 是否添加首行尾行防截断间距，0表示不添加，1表示添加，默认值为0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 是否添加首行尾行防截断间距，0表示不添加，1表示添加。 |

## NODE_TEXT_EDITOR_FALLBACK_LINE_SPACING

```c
NODE_TEXT_EDITOR_FALLBACK_LINE_SPACING = 22024
```

TextEditor组件行高自适应开关，在多行文字叠加时，行高可以基于文字实际高度自适应，支持属性设置、属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 行高是否自适应，0表示不自适应，1表示自适应，默认值为0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 行高是否自适应，0表示不自适应，1表示自适应。 |

## NODE_TEXT_EDITOR_COMPRESS_LEADING_PUNCTUATION

```c
NODE_TEXT_EDITOR_COMPRESS_LEADING_PUNCTUATION = 22025
```

TextEditor组件行首标点符号压缩开关，启用后，行首的标点符号将缩减占位宽度，调整文本排版对齐效果，支持属性设置、属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 是否启用行首标点符号压缩，0表示不启用，1表示启用，默认值为0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 是否启用行首标点符号压缩，0表示不启用，1表示启用。 |

## NODE_TEXT_EDITOR_SELECTED_DRAG_PREVIEW_STYLE

```c
NODE_TEXT_EDITOR_SELECTED_DRAG_PREVIEW_STYLE = 22026
```

TextEditor组件选中拖拽预览样式，支持属性设置、属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .object | 选中拖拽预览样式配置，参数类型[ArkUI_SelectedDragPreviewStyle](capi-arkui-nativemodule-arkui-textselecteddragpreviewstyle.md)。当需要自定义选中文本拖拽时的预览效果时传入此参数，不传入时使用系统默认拖拽预览样式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .object | 选中拖拽预览样式配置，参数类型[ArkUI_SelectedDragPreviewStyle](capi-arkui-nativemodule-arkui-textselecteddragpreviewstyle.md)。 |

## NODE_TEXT_EDITOR_SINGLE_LINE

```c
NODE_TEXT_EDITOR_SINGLE_LINE = 22027
```

TextEditor组件单行模式开关，支持属性设置、属性重置和属性获取。启用单行模式后，NODE_TEXT_EDITOR_MAX_LINES属性设置的最大行数将不再生效。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 是否启用单行模式，0表示不启用，1表示启用，默认值为0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 是否启用单行模式，0表示不启用，1表示启用。 |

## NODE_TEXT_EDITOR_ORPHAN_CHAR_OPTIMIZATION

```c
NODE_TEXT_EDITOR_ORPHAN_CHAR_OPTIMIZATION = 22028
```

TextEditor组件孤字优化开关，支持属性设置、属性重置和属性获取。启用后会调整换行点以尽可能避免孤字。仅在[ArkUI_WordBreak](capi-text-common-h.md#arkui_wordbreak)属性为非ARKUI_WORD_BREAK_BREAK_ALL时生效。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 26.0.0


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 是否启用孤字优化，0表示不启用，1表示启用。默认值为0。仅在[ArkUI_WordBreak](capi-text-common-h.md#arkui_wordbreak)属性为非ARKUI_WORD_BREAK_BREAK_ALL时生效。|

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 是否启用孤字优化，0表示不启用，1表示启用。 |

## NODE_TEXT_EDITOR_HORIZONTAL_SCROLLING

```c
NODE_TEXT_EDITOR_HORIZONTAL_SCROLLING = 22029
```

设置TextEditor组件在文本宽度超过内容区宽度时是否启用水平滚动，支持属性设置、属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 26.0.0


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 是否启用水平滚动，0表示不启用水平滚动，1表示启用水平滚动。默认值为0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 是否启用水平滚动，0表示不启用水平滚动，1表示启用水平滚动。 |

## NODE_TEXT_EDITOR_PUNCTUATION_OVERFLOW

```c
NODE_TEXT_EDITOR_PUNCTUATION_OVERFLOW = 22030
```

设置TextEditor组件是否启用行尾标点符号悬挂，支持属性设置、属性重置和属性获取。<br>
启用后，行尾单个标点符号超出排版宽度而不换行，避免行尾标点符号换行至下一行行首，从而改善文本排版效果。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 26.0.0


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 是否启用行尾标点符号悬挂，0表示不启用标点符号悬挂，1表示启用标点符号悬挂。默认值为0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 是否启用行尾标点符号悬挂，0表示不启用行尾标点符号悬挂，1表示启用行尾标点符号悬挂。 |
