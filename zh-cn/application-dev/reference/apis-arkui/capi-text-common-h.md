# text_common.h
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @Zhang-Dong-hui-->
<!--Designer: @xiangyuan6-->
<!--Tester: @jiaoaozihao-->
<!--Adviser: @Brilliantry_Rui-->

## 概述

定义文本类组件通用的枚举和接口。

**引用文件：** <arkui/node_attributes/text_common.h>

**库：** libace_ndk.z.so

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**起始版本：** 12

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**相关示例：** <!--RP1-->[native_type_sample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/NativeType/native_type_sample)<!--RP1End-->

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md) | ArkUI_StyledString_Descriptor | 定义文本组件支持的属性字符串的数据对象，支持对文本内容进行样式设置与管理，适用于需要富文本展示、样式定制等场景。 |
| [ArkUI_ShowCounterConfig](capi-arkui-nativemodule-arkui-textshowcounterconfig.md) | ArkUI_ShowCounterConfig | 定义文本输入框的计数器配置，用于管理字符计数。适用于需要对用户输入进行字符数限制与实时提示的场景，帮助用户了解输入进度，防止超出字符限制。 |
| [ArkUI_TextContentBaseController](capi-arkui-nativemodule-arkui-textcontentbasecontroller.md) | ArkUI_TextContentBaseController | 定义文本内容基础控制器，为文本类组件提供内容控制能力，支持文本内容的获取、设置和更新等操作，适用于需要对文本组件进行动态内容管理和实时控制的场景，可帮助开发者更灵活地管理文本显示内容。 |
| [ArkUI_TextMenuItem](capi-arkui-nativemodule-arkui-textmenuitem.md) | ArkUI_TextMenuItem | 定义文本菜单项结构体，用于在文本选择菜单中表示单个菜单项，支持设置菜单项的标题、图标、启用状态等属性，适用于开发者需要自定义文本选择菜单内容、扩展菜单项功能的场景，帮助开发者灵活定制文本选择菜单，提升用户交互体验。 |
| [ArkUI_TextMenuItemArray](capi-arkui-nativemodule-arkui-textmenuitemarray.md) | ArkUI_TextMenuItemArray | 定义文本菜单项数组结构体，用于在文本选择菜单或上下文菜单场景中承载多个文本菜单项数据。 |
| [ArkUI_TextEditMenuOptions](capi-arkui-nativemodule-arkui-texteditmenuoptions.md) | ArkUI_TextEditMenuOptions | 定义可编辑文本菜单扩展项结构体类型，用于扩展文本编辑菜单的功能，适用于开发者需要自定义文本编辑菜单操作的场景。 |
| [ArkUI_TextSelectionMenuOptions](capi-arkui-nativemodule-arkui-textselectionmenuoptions.md) | ArkUI_TextSelectionMenuOptions | 定义自定义文本选择菜单的选项配置，支持菜单内容、样式和行为等自定义配置，适用于需要定制文本选择菜单交互的场景。 |
| [OH_ArkUI_DecorationStyleOptions](capi-arkui-nativemodule-oh-arkui-decorationstyleoptions.md) | OH_ArkUI_DecorationStyleOptions | 定义装饰线样式。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [ArkUI_TextAlignment](#arkui_textalignment) | ArkUI_TextAlignment | 定义字体水平对齐样式枚举值。 |
| [ArkUI_TextVerticalAlignment](#arkui_textverticalalignment) | ArkUI_TextVerticalAlignment | 定义文本垂直对齐样式枚举值。 |
| [ArkUI_TextContentAlign](#arkui_textcontentalign) | ArkUI_TextContentAlign | 定义文本内容区垂直对齐样式枚举值。 |
| [ArkUI_TextDirection](#arkui_textdirection) | ArkUI_TextDirection | 定义文本排版方向枚举值。 |
| [ArkUI_EnterKeyType](#arkui_enterkeytype) | ArkUI_EnterKeyType | 定义单行文本输入法回车键类型枚举值。 |
| [ArkUI_TextDecorationType](#arkui_textdecorationtype) | ArkUI_TextDecorationType | 定义装饰线类型枚举值。 |
| [ArkUI_TextDecorationStyle](#arkui_textdecorationstyle) | ArkUI_TextDecorationStyle | 定义装饰线样式枚举值。 |
| [ArkUI_TextCase](#arkui_textcase) | ArkUI_TextCase | 定义文本大小写枚举值。 |
| [ArkUI_TextCopyOptions](#arkui_textcopyoptions) | ArkUI_TextCopyOptions | 定义组件支持设置文本是否可复制粘贴。 |
| [ArkUI_TextOverflow](#arkui_textoverflow) | ArkUI_TextOverflow | 定义文本超长时的显示方式。 |
| [ArkUI_WordBreak](#arkui_wordbreak) | ArkUI_WordBreak | 定义文本断行规则。 |
| [ArkUI_EllipsisMode](#arkui_ellipsismode) | ArkUI_EllipsisMode | 定义文本省略位置。 |
| [ArkUI_KeyboardAppearance](#arkui_keyboardappearance) | ArkUI_KeyboardAppearance | 定义输入框拉起的键盘样式。 |
| [ArkUI_TextMenuItemId](#arkui_textmenuitemid) | ArkUI_TextMenuItemId | 文本菜单项id枚举。 |
| [OH_ArkUI_LineBreakStrategy](#oh_arkui_linebreakstrategy) | OH_ArkUI_LineBreakStrategy | 换行策略类型枚举。 |
| [ArkUI_TextSpanType](#arkui_textspantype) | ArkUI_TextSpanType | 自定义文本选择菜单的文本识别类型枚举。 |
| [ArkUI_TextResponseType](#arkui_textresponsetype) | ArkUI_TextResponseType | 自定义文本选择菜单的响应类型枚举。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [typedef void (\*ArkUI_TextCreateMenuCallback)(ArkUI_TextMenuItemArray* items, void* userData)](#arkui_textcreatemenucallback) | 文本菜单创建事件回调函数，在文本菜单创建时会触发此回调函数，开发者可在此函数中设置菜单数据。 |
| [typedef void (\*ArkUI_TextPrepareMenuCallback)(ArkUI_TextMenuItemArray* items, void* userData)](#arkui_textpreparemenucallback) | 文本菜单准备事件回调函数，当文本选择区域变化后显示菜单之前会触发此回调函数，开发者可在此函数中配置菜单数据。 |
| [typedef bool (\*ArkUI_TextMenuItemClickCallback)(const ArkUI_TextMenuItem* item, int32_t start, int32_t end, void* userData)](#arkui_textmenuitemclickcallback) | 文本菜单项点击事件回调函数，在菜单项被点击时触发此回调函数，开发者可在此函数中对系统默认处理行为进行拦截。 |
| [ArkUI_ShowCounterConfig* OH_ArkUI_ShowCounterConfig_Create()](#oh_arkui_showcounterconfig_create) | 创建文本输入框计数器的配置对象。 |
| [void OH_ArkUI_ShowCounterConfig_Dispose(ArkUI_ShowCounterConfig* config)](#oh_arkui_showcounterconfig_dispose) | 销毁文本输入框计数器的配置对象。 |
| [void OH_ArkUI_ShowCounterConfig_SetCounterTextColor(ArkUI_ShowCounterConfig* config, uint32_t color)](#oh_arkui_showcounterconfig_setcountertextcolor) | 设置文本输入框未达到最大字符数时计数器的颜色。 |
| [void OH_ArkUI_ShowCounterConfig_SetCounterTextOverflowColor(ArkUI_ShowCounterConfig* config, uint32_t color)](#oh_arkui_showcounterconfig_setcountertextoverflowcolor) | 设置文本输入框超出最大字符数时计数器的颜色。 |
| [uint32_t OH_ArkUI_ShowCounterConfig_GetCounterTextColor(ArkUI_ShowCounterConfig* config)](#oh_arkui_showcounterconfig_getcountertextcolor) | 获取文本输入框未达到最大字符数时计数器的颜色。 |
| [uint32_t OH_ArkUI_ShowCounterConfig_GetCounterTextOverflowColor(ArkUI_ShowCounterConfig* config)](#oh_arkui_showcounterconfig_getcountertextoverflowcolor) | 获取文本输入框超出最大字符数时计数器的颜色。 |
| [ArkUI_TextMenuItem* OH_ArkUI_TextMenuItem_Create()](#oh_arkui_textmenuitem_create) | 创建文本菜单项对象。 |
| [void OH_ArkUI_TextMenuItem_Dispose(ArkUI_TextMenuItem* textMenuItem)](#oh_arkui_textmenuitem_dispose) | 释放文本菜单项对象。 |
| [ArkUI_TextEditMenuOptions* OH_ArkUI_TextEditMenuOptions_Create()](#oh_arkui_texteditmenuoptions_create) | 创建文本菜单扩展项对象。 |
| [void OH_ArkUI_TextEditMenuOptions_Dispose(ArkUI_TextEditMenuOptions* editMenuOptions)](#oh_arkui_texteditmenuoptions_dispose) | 释放文本菜单扩展项对象。 |
| [ArkUI_TextSelectionMenuOptions* OH_ArkUI_TextSelectionMenuOptions_Create()](#oh_arkui_textselectionmenuoptions_create) | 创建自定义文本选择菜单对象。 |
| [void OH_ArkUI_TextSelectionMenuOptions_Dispose(ArkUI_TextSelectionMenuOptions* selectionMenuOptions)](#oh_arkui_textselectionmenuoptions_dispose) | 释放自定义文本选择菜单对象。 |
| [ArkUI_TextContentBaseController* OH_ArkUI_TextContentBaseController_Create()](#oh_arkui_textcontentbasecontroller_create) | 创建文本内容基础控制器对象。 |
| [void OH_ArkUI_TextContentBaseController_Dispose(ArkUI_TextContentBaseController* controller)](#oh_arkui_textcontentbasecontroller_dispose) | 销毁文本内容基础控制器对象。 |
| [void OH_ArkUI_TextContentBaseController_DeleteBackward(ArkUI_TextContentBaseController* controller)](#oh_arkui_textcontentbasecontroller_deletebackward) | 在编辑态时删除光标前字符。其他状态删除输入框组件的最后一个字符。 |
| [void OH_ArkUI_TextContentBaseController_ScrollToVisible(ArkUI_TextContentBaseController* controller, int32_t start, int32_t end)](#oh_arkui_textcontentbasecontroller_scrolltovisible) | 将起始索引与结束索引传递给与其绑定的输入框组件，并将此范围内的文字滚动到可视区域。 |
| [OH_ArkUI_DecorationStyleOptions* OH_ArkUI_DecorationStyleOptions_Create()](#oh_arkui_decorationstyleoptions_create) | 创建一个装饰线样式对象。当该对象不再使用时，请调用[OH_ArkUI_DecorationStyleOptions_Destroy](capi-text-common-h.md#oh_arkui_decorationstyleoptions_destroy)销毁。 |
| [void OH_ArkUI_DecorationStyleOptions_Destroy(OH_ArkUI_DecorationStyleOptions* options)](#oh_arkui_decorationstyleoptions_destroy) | 销毁装饰线样式对象。 |

## 枚举类型说明

### ArkUI_TextAlignment

```c
enum ArkUI_TextAlignment
```

**描述**

定义字体水平对齐样式枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_TEXT_ALIGNMENT_START = 0 | 水平对齐首部。 |
| ARKUI_TEXT_ALIGNMENT_CENTER = 1 | 水平居中对齐。 |
| ARKUI_TEXT_ALIGNMENT_END = 2 | 水平对齐尾部。 |
| ARKUI_TEXT_ALIGNMENT_JUSTIFY = 3 | 双端对齐。 |
| ARKUI_TEXT_ALIGNMENT_LEFT_TO_RIGHT = 4 | 从左到右对齐。<br>**起始版本：** 23 |
| ARKUI_TEXT_ALIGNMENT_RIGHT_TO_LEFT = 5 | 从右到左对齐。<br>**起始版本：** 23 |

### ArkUI_TextVerticalAlignment

```c
enum ArkUI_TextVerticalAlignment
```

**描述**

定义文本垂直对齐样式枚举值。

**起始版本：** 20

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_TEXT_VERTICAL_ALIGNMENT_BASELINE = 0 | 基线对齐。 |
| ARKUI_TEXT_VERTICAL_ALIGNMENT_BOTTOM = 1 | 底部对齐。 |
| ARKUI_TEXT_VERTICAL_ALIGNMENT_CENTER = 2 | 居中对齐。 |
| ARKUI_TEXT_VERTICAL_ALIGNMENT_TOP = 3 | 顶部对齐。 |

### ArkUI_TextContentAlign

```c
enum ArkUI_TextContentAlign
```

**描述**

定义文本内容区垂直对齐样式枚举值。

**起始版本：** 21

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_TEXT_CONTENT_ALIGN_TOP = 0 | 顶部对齐。 |
| ARKUI_TEXT_CONTENT_ALIGN_CENTER = 1 | 居中对齐。 |
| ARKUI_TEXT_CONTENT_ALIGN_BOTTOM = 2 | 底部对齐。 |

### ArkUI_TextDirection

```c
enum ArkUI_TextDirection
```

**描述**

定义文本排版方向枚举值。

**起始版本：** 23

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_TEXT_DIRECTION_LTR = 0 | 文本排版方向从左到右。 |
| ARKUI_TEXT_DIRECTION_RTL = 1 | 文本排版方向从右到左。 |
| ARKUI_TEXT_DIRECTION_DEFAULT = 2 | 文本排版方向遵循组件布局。 |
| ARKUI_TEXT_DIRECTION_AUTO = 3 | 遵循自身实际文本内容的排版方向，如果文本为 RTL（Right-to-Left）类语言（如藏文、维吾尔文），文本排版方向为从右到左。如果为 LTR（Left-to-Right）类语言（如中文、英文），文本排版方向为从左到右。 |

### ArkUI_EnterKeyType

```c
enum ArkUI_EnterKeyType
```

**描述**

定义单行文本输入法回车键类型枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_ENTER_KEY_TYPE_GO = 2 | 显示为开始样式。 |
| ARKUI_ENTER_KEY_TYPE_SEARCH = 3 | 显示为搜索样式。 |
| ARKUI_ENTER_KEY_TYPE_SEND = 4 | 显示为发送样式。 |
| ARKUI_ENTER_KEY_TYPE_NEXT = 5 | 显示为下一个样式。 |
| ARKUI_ENTER_KEY_TYPE_DONE = 6 | 显示为完成样式。 |
| ARKUI_ENTER_KEY_TYPE_PREVIOUS = 7 | 显示为上一个样式。 |
| ARKUI_ENTER_KEY_TYPE_NEW_LINE = 8 | 显示为换行样式。 |

### ArkUI_TextDecorationType

```c
enum ArkUI_TextDecorationType
```

**描述**

定义装饰线类型枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_TEXT_DECORATION_TYPE_NONE = 0 | 不使用装饰线。 |
| ARKUI_TEXT_DECORATION_TYPE_UNDERLINE = 1 | 文字下划线修饰。 |
| ARKUI_TEXT_DECORATION_TYPE_OVERLINE = 2 | 文字上划线修饰。 |
| ARKUI_TEXT_DECORATION_TYPE_LINE_THROUGH = 3 | 穿过文本的修饰线。 |

### ArkUI_TextDecorationStyle

```c
enum ArkUI_TextDecorationStyle
```

**描述**

定义装饰线样式枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_TEXT_DECORATION_STYLE_SOLID = 0 | 单实线。 |
| ARKUI_TEXT_DECORATION_STYLE_DOUBLE = 1 | 双实线。 |
| ARKUI_TEXT_DECORATION_STYLE_DOTTED = 2 | 点线。 |
| ARKUI_TEXT_DECORATION_STYLE_DASHED = 3 | 虚线。 |
| ARKUI_TEXT_DECORATION_STYLE_WAVY = 4 | 波浪线。 |

### ArkUI_TextCase

```c
enum ArkUI_TextCase
```

**描述**

定义文本大小写枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_TEXT_CASE_NORMAL = 0 | 保持原有大小写。 |
| ARKUI_TEXT_CASE_LOWER = 1 | 文本全小写。 |
| ARKUI_TEXT_CASE_UPPER = 2 | 文本全大写。 |

### ArkUI_TextCopyOptions

```c
enum ArkUI_TextCopyOptions
```

**描述**

定义组件支持设置文本是否可复制粘贴。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_TEXT_COPY_OPTIONS_NONE = 0 | 不支持复制。 |
| ARKUI_TEXT_COPY_OPTIONS_IN_APP = 1 | 支持应用内复制。 |
| ARKUI_TEXT_COPY_OPTIONS_LOCAL_DEVICE = 2 | 支持设备内复制。 |
| ARKUI_TEXT_COPY_OPTIONS_CROSS_DEVICE = 3 | 支持跨设备复制。 |

### ArkUI_TextOverflow

```c
enum ArkUI_TextOverflow
```

**描述**

定义文本超长时的显示方式。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_TEXT_OVERFLOW_NONE = 0 | 文本超长时不裁剪显示。 |
| ARKUI_TEXT_OVERFLOW_CLIP = 1 | 文本超长时进行裁剪显示。 |
| ARKUI_TEXT_OVERFLOW_ELLIPSIS = 2 | 文本超长时显示不下的文本用省略号代替。 |
| ARKUI_TEXT_OVERFLOW_MARQUEE = 3 | 文本超长时以跑马灯的方式展示。 |

### ArkUI_WordBreak

```c
enum ArkUI_WordBreak
```

**描述**

定义文本断行规则。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_WORD_BREAK_NORMAL = 0 | CJK(中文、日文、韩文)文本可以在任意2个字符间断行，而Non-CJK文本（如英文等）只能在空白符处断行。 |
| ARKUI_WORD_BREAK_BREAK_ALL = 1 | 对于Non-CJK的文本，可在任意2个字符间断行。CJK(中文、日文、韩文)文本可以在任意2个字符间断行。 |
| ARKUI_WORD_BREAK_BREAK_WORD = 2 | 对于Non-CJK的文本可在任意2个字符间断行，一行文本中有断行破发点（如空白符）时，优先按破发点换行。对于CJK的文本，换行效果与NORMAL效果保持一致。 |
| ARKUI_WORD_BREAK_HYPHENATION = 3 | 对于Non-CJK的文本，可以按照音节断行。对于CJK的文本，换行效果与NORMAL效果保持一致。<br>**起始版本：** 18 |

### ArkUI_EllipsisMode

```c
enum ArkUI_EllipsisMode
```

**描述**

定义文本省略位置。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_ELLIPSIS_MODE_START = 0 | 省略行首内容。适用单行文本场景。 |
| ARKUI_ELLIPSIS_MODE_CENTER = 1 | 省略行中内容。适用单行文本场景。 |
| ARKUI_ELLIPSIS_MODE_END = 2 | 省略行末内容。适用单行文本和多行文本场景。 |
| ARKUI_ELLIPSIS_MODE_MULTILINE_START = 3 | 省略行首内容。适用单行文本和多行文本场景。<br>**起始版本：** 24 |
| ARKUI_ELLIPSIS_MODE_MULTILINE_CENTER = 4 | 省略行中内容。适用单行文本和多行文本场景。<br>**起始版本：** 24 |

### ArkUI_KeyboardAppearance

```c
enum ArkUI_KeyboardAppearance
```

**描述**

定义输入框拉起的键盘样式。

**起始版本：** 15

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_KEYBOARD_APPEARANCE_NONE_IMMERSIVE = 0 | 默认模式，不使用沉浸式样式。 |
| ARKUI_KEYBOARD_APPEARANCE_IMMERSIVE = 1 | 沉浸式模式，由系统决定采用的样式。 |
| ARKUI_KEYBOARD_APPEARANCE_LIGHT_IMMERSIVE = 2 | 浅色沉浸式样式。 |
| ARKUI_KEYBOARD_APPEARANCE_DARK_IMMERSIVE = 3 | 深色沉浸式样式。 |

### ArkUI_TextMenuItemId

```c
enum ArkUI_TextMenuItemId
```

**描述**

文本菜单项id枚举。

**起始版本：** 22

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_TEXT_MENU_ITEM_ID_CUT = 0 | 裁剪。 |
| ARKUI_TEXT_MENU_ITEM_ID_COPY = 1 | 复制。 |
| ARKUI_TEXT_MENU_ITEM_ID_PASTE = 2 | 粘贴。 |
| ARKUI_TEXT_MENU_ITEM_ID_SELECT_ALL = 3 | 全选。 |
| ARKUI_TEXT_MENU_ITEM_ID_COLLABORATION_SERVICE = 4 | 互通服务。例如跨设备交互，包括跨设备的相机访问等能力。 |
| ARKUI_TEXT_MENU_ITEM_ID_CAMERA_INPUT = 5 | 拍摄输入。 |
| ARKUI_TEXT_MENU_ITEM_ID_AI_WRITER = 6 | AI帮写。该菜单项依赖大模型能力，否则不生效。 |
| ARKUI_TEXT_MENU_ITEM_ID_TRANSLATE = 7 | 翻译。对选中的文本提供翻译服务。 |
| ARKUI_TEXT_MENU_ITEM_ID_SEARCH = 8 | 搜索。对选中的文本提供搜索服务，拉起浏览器搜索选中文本内容。 |
| ARKUI_TEXT_MENU_ITEM_ID_SHARE = 9 | 分享。对选中的文本提供分享服务，拉起分享窗口分享选中文本内容。 |
| ARKUI_TEXT_MENU_ITEM_ID_URL = 10 | 打开链接。对选中的URL提供跳转服务，拉起浏览器搜索或者应用页面。 |
| ARKUI_TEXT_MENU_ITEM_ID_EMAIL = 11 | 新建邮件。对选中的邮箱地址提供跳转服务，拉起邮箱应用。 |
| ARKUI_TEXT_MENU_ITEM_ID_PHONE_NUMBER = 12 | 呼叫。对选中的电话号码跳转服务，拉起电话拨号页面。 |
| ARKUI_TEXT_MENU_ITEM_ID_ADDRESS = 13 | 导航前往。对选中的地址提供跳转服务，拉起地图应用。 |
| ARKUI_TEXT_MENU_ITEM_ID_DATA_TIME = 14 | 新建日程。对选中的日期和时间提供跳转服务，拉起新建日程页面。 |
| ARKUI_TEXT_MENU_ITEM_ID_ASK_AI = 15 | 问问AI。对选中的文本提供AI问询能力。 |
| ARKUI_TEXT_MENU_ITEM_ID_AUTO_FILL = 16 | 自动填充。例如自动填充账号密码。<br>**起始版本：** 24 |
| ARKUI_TEXT_MENU_ITEM_ID_PASSWORD_VAULT = 17 | 密码保险箱。<br>**起始版本：** 24 |
| ARKUI_TEXT_MENU_ITEM_ID_APP_RESERVED_BEGIN = 10000 | 应用自定义菜单项起始id，除了系统内置的菜单项id，应用还可以自定义菜单项id。 |
| ARKUI_TEXT_MENU_ITEM_ID_APP_RESERVED_END = 20000 | 应用自定义菜单项结束id，除了系统内置的菜单项id，应用还可以自定义菜单项id。 |

### OH_ArkUI_LineBreakStrategy

```c
enum OH_ArkUI_LineBreakStrategy
```

**描述**

换行策略类型枚举。

**起始版本：** 24

| 枚举项 | 描述 |
| -- | -- |
| OH_ARKUI_LINE_BREAK_STRATEGY_GREEDY = 0 | 贪婪模式。<br>使每一行尽可能显示多的字符，直到这一行不能显示更多字符时进行折行。 |
| OH_ARKUI_LINE_BREAK_STRATEGY_HIGH_QUALITY = 1 | 高质量模式。<br>在平衡模式的基础上，尽可能填满行，同时最后一行的权重较低，可能出现最后一行留白较多的情形。 |
| OH_ARKUI_LINE_BREAK_STRATEGY_BALANCE = 2 | 平衡模式。<br>在不拆词的情况下，尽量使一个段落中每一行的宽度相同。 |

### ArkUI_TextSpanType

```c
enum ArkUI_TextSpanType
```

**描述**

自定义文本选择菜单的文本识别类型枚举。

**起始版本：** 22

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_TEXT_SPAN_TYPE_TEXT = 0 | 选中文本内容为文字类型。 |
| ARKUI_TEXT_SPAN_TYPE_IMAGE = 1 | 选中文本内容为图像类型。 |
| ARKUI_TEXT_SPAN_TYPE_MIXED = 2 | 选中文本内容为图文混合类型。 |
| ARKUI_TEXT_SPAN_TYPE_DEFAULT = 3 | 如果设置为此类型且设置了其他类型时，选中文本后会显示与选中文本内容类型对应的菜单。如果设置为此类型但其他类型未设置时，选中文本后会显示此类型对应的菜单。例如，同时设置了文本识别类型为ARKUI_TEXT_SPAN_TYPE_TEXT、ARKUI_TEXT_SPAN_TYPE_DEFAULT的两个菜单，此时选中文本内容为文字类型会触发ARKUI_TEXT_SPAN_TYPE_TEXT对应的菜单弹出，选中文本内容为图像类型则会触发ARKUI_TEXT_SPAN_TYPE_DEFAULT对应的菜单弹出。 |

### ArkUI_TextResponseType

```c
enum ArkUI_TextResponseType
```

**描述**

自定义文本选择菜单的响应类型枚举。

**起始版本：** 22

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_TEXT_RESPONSE_TYPE_RIGHT_CLICK = 0 | 通过鼠标右键触发菜单弹出。 |
| ARKUI_TEXT_RESPONSE_TYPE_LONG_PRESS = 1 | 通过长按触发菜单弹出。 |
| ARKUI_TEXT_RESPONSE_TYPE_SELECT = 2 | 通过鼠标选中触发菜单弹出。 |
| ARKUI_TEXT_RESPONSE_TYPE_DEFAULT = 3 | 如果设置为此类型且设置了其他类型时，触发其他类型的操作会显示对应类型的菜单。如果设置为此类型但其他类型未设置时，触发其他类型的操作会显示此类型对应的菜单。例如，同时设置了响应类型为ARKUI_TEXT_RESPONSE_TYPE_RIGHT_CLICK、ARKUI_TEXT_RESPONSE_TYPE_DEFAULT的两个菜单，此时通过鼠标右键会触发ARKUI_TEXT_RESPONSE_TYPE_RIGHT_CLICK对应的菜单弹出，长按则会触发ARKUI_TEXT_RESPONSE_TYPE_DEFAULT对应的菜单弹出。 |


## 函数说明

### ArkUI_TextCreateMenuCallback()

```c
typedef void (*ArkUI_TextCreateMenuCallback)(ArkUI_TextMenuItemArray* items, void* userData)
```

**描述**

文本菜单创建事件回调函数，在文本菜单创建时会触发此回调函数，开发者可在此函数中设置菜单数据。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_TextMenuItemArray](capi-arkui-nativemodule-arkui-textmenuitemarray.md)* items | 指向ArkUI_TextMenuItemArray对象的指针，该数组对象由系统内部创建并释放，在回调函数中开发者可以调用[OH_ArkUI_TextMenuItemArray_Insert](capi-native-type-h.md#oh_arkui_textmenuitemarray_insert)，[OH_ArkUI_TextMenuItemArray_Erase](capi-native-type-h.md#oh_arkui_textmenuitemarray_erase)进行数组修改。 |
| void\* userData | 用户自定义数据。 |

### ArkUI_TextPrepareMenuCallback()

```c
typedef void (*ArkUI_TextPrepareMenuCallback)(ArkUI_TextMenuItemArray* items, void* userData)
```

**描述**

文本菜单准备事件回调函数，当文本选择区域变化后显示菜单之前会触发此回调函数，开发者可在此函数中配置菜单数据。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_TextMenuItemArray](capi-arkui-nativemodule-arkui-textmenuitemarray.md)* items | 指向ArkUI_TextMenuItemArray对象的指针，该数组对象由系统内部创建并释放，在回调函数中开发者可以调用[OH_ArkUI_TextMenuItemArray_Insert](capi-native-type-h.md#oh_arkui_textmenuitemarray_insert)，[OH_ArkUI_TextMenuItemArray_Erase](capi-native-type-h.md#oh_arkui_textmenuitemarray_erase)进行数组修改。 |
| void\* userData | 用户自定义数据。 |

### ArkUI_TextMenuItemClickCallback()

```c
typedef bool (*ArkUI_TextMenuItemClickCallback)(const ArkUI_TextMenuItem* item, int32_t start, int32_t end, void* userData)
```

**描述**

文本菜单项点击事件回调函数，在菜单项被点击时触发此回调函数，开发者可在此函数中对系统默认处理行为进行拦截。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkUI_TextMenuItem](capi-arkui-nativemodule-arkui-textmenuitem.md)* item | 指向ArkUI_TextMenuItem对象的指针，表示被点击的文本菜单项。 |
| int32_t start | 选中文本起始索引。 |
| int32_t end | 选中文本结束索引。 |
| void\* userData | 用户自定义数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 是否拦截系统默认处理行为。<br>         true：拦截系统默认处理行为，如点击"粘贴"、"复制"等文本菜单项时不再执行系统默认处理行为，仅执行开发者自定义处理行为。<br>         false：不拦截系统默认处理行为，如点击"粘贴"、"复制"等文本菜单项时先执行开发者自定义处理行为，再执行系统默认处理行为。 |

### OH_ArkUI_ShowCounterConfig_Create()

```c
ArkUI_ShowCounterConfig* OH_ArkUI_ShowCounterConfig_Create()
```

**描述**

创建文本输入框计数器的配置对象。

**起始版本：** 22

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ShowCounterConfig*](capi-arkui-nativemodule-arkui-textshowcounterconfig.md) | 指向文本输入框计数器的配置对象的指针。 |

### OH_ArkUI_ShowCounterConfig_Dispose()

```c
void OH_ArkUI_ShowCounterConfig_Dispose(ArkUI_ShowCounterConfig* config)
```

**描述**

销毁文本输入框计数器的配置对象。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ShowCounterConfig](capi-arkui-nativemodule-arkui-textshowcounterconfig.md)* config | 销毁文本输入框计数器的配置对象指针。 |

### OH_ArkUI_ShowCounterConfig_SetCounterTextColor()

```c
void OH_ArkUI_ShowCounterConfig_SetCounterTextColor(ArkUI_ShowCounterConfig* config, uint32_t color)
```

**描述**

设置文本输入框未达到最大字符数时计数器的颜色。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ShowCounterConfig](capi-arkui-nativemodule-arkui-textshowcounterconfig.md)* config | 指向文本输入框计数器的配置对象指针。 |
| uint32_t color | 文本输入框未达到最大字符数时计数器的颜色，格式为0xARGB，默认值为0x66182431。 |

### OH_ArkUI_ShowCounterConfig_SetCounterTextOverflowColor()

```c
void OH_ArkUI_ShowCounterConfig_SetCounterTextOverflowColor(ArkUI_ShowCounterConfig* config, uint32_t color)
```

**描述**

设置文本输入框超出最大字符数时计数器的颜色。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ShowCounterConfig](capi-arkui-nativemodule-arkui-textshowcounterconfig.md)* config | 指向文本输入框计数器的配置对象指针。 |
| uint32_t color | 文本输入框超出最大字符数时计数器的颜色，格式为0xARGB，默认值为0x99FA2A2D。 |

### OH_ArkUI_ShowCounterConfig_GetCounterTextColor()

```c
uint32_t OH_ArkUI_ShowCounterConfig_GetCounterTextColor(ArkUI_ShowCounterConfig* config)
```

**描述**

获取文本输入框未达到最大字符数时计数器的颜色。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ShowCounterConfig](capi-arkui-nativemodule-arkui-textshowcounterconfig.md)* config | 指向文本输入框计数器的配置对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| uint32_t | 返回文本输入框未达到最大字符数时计数器的颜色，格式为0xARGB，如果未通过[OH_ArkUI_ShowCounterConfig_SetCounterTextColor](capi-text-common-h.md#oh_arkui_showcounterconfig_setcountertextcolor)接口设置计数器颜色，则返回0。 |

### OH_ArkUI_ShowCounterConfig_GetCounterTextOverflowColor()

```c
uint32_t OH_ArkUI_ShowCounterConfig_GetCounterTextOverflowColor(ArkUI_ShowCounterConfig* config)
```

**描述**

获取文本输入框超出最大字符数时计数器的颜色。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ShowCounterConfig](capi-arkui-nativemodule-arkui-textshowcounterconfig.md)* config | 指向文本输入框计数器的配置对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| uint32_t | 返回文本输入框超出最大字符数时计数器的颜色，格式为0xARGB，如果未通过[OH_ArkUI_ShowCounterConfig_SetCounterTextOverflowColor](capi-text-common-h.md#oh_arkui_showcounterconfig_setcountertextoverflowcolor)接口设置计数器颜色，则返回0。 |

### OH_ArkUI_TextMenuItem_Create()

```c
ArkUI_TextMenuItem* OH_ArkUI_TextMenuItem_Create()
```

**描述**

创建文本菜单项对象。

**起始版本：** 22

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_TextMenuItem*](capi-arkui-nativemodule-arkui-textmenuitem.md) | 指向ArkUI_TextMenuItem对象的指针。 |

### OH_ArkUI_TextMenuItem_Dispose()

```c
void OH_ArkUI_TextMenuItem_Dispose(ArkUI_TextMenuItem* textMenuItem)
```

**描述**

释放文本菜单项对象。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_TextMenuItem](capi-arkui-nativemodule-arkui-textmenuitem.md)* textMenuItem | 指向ArkUI_TextMenuItem对象的指针。 |

### OH_ArkUI_TextEditMenuOptions_Create()

```c
ArkUI_TextEditMenuOptions* OH_ArkUI_TextEditMenuOptions_Create()
```

**描述**

创建文本菜单扩展项对象。

**起始版本：** 22

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_TextEditMenuOptions*](capi-arkui-nativemodule-arkui-texteditmenuoptions.md) | 指向ArkUI_TextEditMenuOptions对象的指针。 |

### OH_ArkUI_TextEditMenuOptions_Dispose()

```c
void OH_ArkUI_TextEditMenuOptions_Dispose(ArkUI_TextEditMenuOptions* editMenuOptions)
```

**描述**

释放文本菜单扩展项对象。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_TextEditMenuOptions](capi-arkui-nativemodule-arkui-texteditmenuoptions.md)* editMenuOptions | 指向ArkUI_TextEditMenuOptions对象的指针。 |

### OH_ArkUI_TextSelectionMenuOptions_Create()

```c
ArkUI_TextSelectionMenuOptions* OH_ArkUI_TextSelectionMenuOptions_Create()
```

**描述**

创建自定义文本选择菜单对象。

**起始版本：** 22

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_TextSelectionMenuOptions*](capi-arkui-nativemodule-arkui-textselectionmenuoptions.md) | 指向ArkUI_TextSelectionMenuOptions对象的指针。 |

### OH_ArkUI_TextSelectionMenuOptions_Dispose()

```c
void OH_ArkUI_TextSelectionMenuOptions_Dispose(ArkUI_TextSelectionMenuOptions* selectionMenuOptions)
```

**描述**

释放自定义文本选择菜单对象。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_TextSelectionMenuOptions](capi-arkui-nativemodule-arkui-textselectionmenuoptions.md)* selectionMenuOptions | 指向ArkUI_TextSelectionMenuOptions对象的指针。 |

### OH_ArkUI_TextContentBaseController_Create()

```c
ArkUI_TextContentBaseController* OH_ArkUI_TextContentBaseController_Create()
```

**描述**

创建文本内容基础控制器对象。

**起始版本：** 23

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_TextContentBaseController*](capi-arkui-nativemodule-arkui-textcontentbasecontroller.md) | 指向控制器对象的指针。 |

### OH_ArkUI_TextContentBaseController_Dispose()

```c
void OH_ArkUI_TextContentBaseController_Dispose(ArkUI_TextContentBaseController* controller)
```

**描述**

销毁文本内容基础控制器对象。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_TextContentBaseController](capi-arkui-nativemodule-arkui-textcontentbasecontroller.md)* controller | 待销毁的控制器对象指针。 |

### OH_ArkUI_TextContentBaseController_DeleteBackward()

```c
void OH_ArkUI_TextContentBaseController_DeleteBackward(ArkUI_TextContentBaseController* controller)
```

**描述**

在编辑态时删除光标前字符。其他状态删除输入框组件的最后一个字符。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_TextContentBaseController](capi-arkui-nativemodule-arkui-textcontentbasecontroller.md)* controller | 控制器对象指针。 |


### OH_ArkUI_TextContentBaseController_ScrollToVisible()

```c
void OH_ArkUI_TextContentBaseController_ScrollToVisible(ArkUI_TextContentBaseController* controller, int32_t start, int32_t end)
```

**描述**

将起始索引与结束索引传递给与其绑定的输入框组件，并将此范围内的文字滚动到可视区域。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_TextContentBaseController](capi-arkui-nativemodule-arkui-textcontentbasecontroller.md)* controller | 控制器对象指针。<br>通过此controller将起始索引与结束索引传递给与其绑定的输入框组件并进行滚动操作。 |
| int32_t start | 起始文字索引值。<br>起始索引应小于等于结束索引，否则接口调用无效。取值范围[0, 输入框文本总长度]，起始索引小于0视为0，大于总长度视为总长度。 |
| int32_t end | 结束文字索引值。<br>结束索引应大于等于起始索引，否则接口调用无效。取值范围[0, 输入框文本总长度]，结束索引小于0视为0，大于总长度视为总长度。 |

### OH_ArkUI_DecorationStyleOptions_Create()

```c
OH_ArkUI_DecorationStyleOptions* OH_ArkUI_DecorationStyleOptions_Create()
```

**描述**

创建一个装饰线样式对象。当该对象不再使用时，请调用[OH_ArkUI_DecorationStyleOptions_Destroy](capi-text-common-h.md#oh_arkui_decorationstyleoptions_destroy)销毁。

**起始版本：** 24

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_ArkUI_DecorationStyleOptions*](capi-arkui-nativemodule-oh-arkui-decorationstyleoptions.md) | 指向[OH_ArkUI_DecorationStyleOptions](capi-arkui-nativemodule-oh-arkui-decorationstyleoptions.md)对象的指针。 |

### OH_ArkUI_DecorationStyleOptions_Destroy()

```c
void OH_ArkUI_DecorationStyleOptions_Destroy(OH_ArkUI_DecorationStyleOptions* options)
```

**描述**

销毁装饰线样式对象。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_DecorationStyleOptions](capi-arkui-nativemodule-oh-arkui-decorationstyleoptions.md)* options | 指向待销毁的选项对象的指针。 |


