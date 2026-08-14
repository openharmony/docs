# text_common.h

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @Zhang-Dong-hui-->
<!--Designer: @xiangyuan6-->
<!--Tester: @jiaoaozihao-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=9d935c682ca66fcb6cb6ddce38110a22b9819131 translatedAt=2026-08-11T09:12:26.689Z pushedAt=2026-08-12T07:29:27.102Z -->

## Overview

Defines common text enumerations and APIs, covering text alignment, decoration line styles, copy and paste, overflow handling, line break policies, and menu customization. It is applicable to scenarios such as text boxes and text display, helping you flexibly control text styles and interaction behavior while reducing development complexity.

**File to include:** <arkui/node_attributes/text_common.h>

**Library:** libace_ndk.z.so

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Since:** 12

**Related module:** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**Sample:** <!--RP1-->[native_type_sample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/NativeType/native_type_sample)<!--RP1End-->

## Summary

### Structs

| Name | typedef Keyword | Description |
| -- | -- | -- |
| [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md) | ArkUI_StyledString_Descriptor | Defines the styled string descriptor object supported by the text component, enabling style configuration and management of text content. This struct is applicable when rich text display and style customization are required. |
| [ArkUI_ShowCounterConfig](capi-arkui-nativemodule-arkui-textshowcounterconfig.md) | ArkUI_ShowCounterConfig | Defines the text input character counter configuration for managing character counting. This struct is applicable when character count limits and real-time prompts are needed for user input, helping users track input progress and prevent exceeding character limits. |
| [ArkUI_TextContentBaseController](capi-arkui-nativemodule-arkui-textcontentbasecontroller.md) | ArkUI_TextContentBaseController | Defines a basic controller for text content, providing content control capabilities for text components. This struct supports operations such as obtaining, setting, and updating text content. It is applicable when dynamic content management and real-time control of text components are needed, helping you manage displayed text content more flexibly. |
| [ArkUI_TextMenuItem](capi-arkui-nativemodule-arkui-textmenuitem.md) | ArkUI_TextMenuItem | Defines a text menu item for setting attributes such as a title, icon, and enabled state, supporting text selection menus customization. |
| [ArkUI_TextMenuItemArray](capi-arkui-nativemodule-arkui-textmenuitemarray.md) | ArkUI_TextMenuItemArray | Defines a text menu item array for carrying multiple text menu item data in text selection menu or context menu scenarios. |
| [ArkUI_TextEditMenuOptions](capi-arkui-nativemodule-arkui-texteditmenuoptions.md) | ArkUI_TextEditMenuOptions | Defines text menu extension options for extending the functionality of the text editing menu. This struct is applicable when you need to customize text editing menu operations. |
| [ArkUI_TextSelectionMenuOptions](capi-arkui-nativemodule-arkui-textselectionmenuoptions.md) | ArkUI_TextSelectionMenuOptions | Defines custom text selection menu options, supporting custom configuration of menu content, style, and behavior. This struct is applicable when customization of text selection menu interactions is needed. |
| [OH_ArkUI_DecorationStyleOptions](capi-arkui-nativemodule-oh-arkui-decorationstyleoptions.md) | OH_ArkUI_DecorationStyleOptions | Defines decoration style options. |

### Enums

| Name | typedef Keyword | Description |
| -- | -- | -- |
| [ArkUI_TextAlignment](#arkui_textalignment) | ArkUI_TextAlignment | Enumerates text horizontal alignment styles. |
| [ArkUI_TextVerticalAlignment](#arkui_textverticalalignment) | ArkUI_TextVerticalAlignment | Enumerates text vertical alignment styles. |
| [ArkUI_TextContentAlign](#arkui_textcontentalign) | ArkUI_TextContentAlign | Enumerates vertical alignment styles in the text content area. |
| [ArkUI_TextDirection](#arkui_textdirection) | ArkUI_TextDirection | Enumerates text layout directions. |
| [ArkUI_EnterKeyType](#arkui_enterkeytype) | ArkUI_EnterKeyType | Enumerates the types of the **Enter** key for single-line text input. |
| [ArkUI_TextDecorationType](#arkui_textdecorationtype) | ArkUI_TextDecorationType | Enumerates text decoration types. |
| [ArkUI_TextDecorationStyle](#arkui_textdecorationstyle) | ArkUI_TextDecorationStyle | Enumerates text decoration styles. |
| [ArkUI_TextCase](#arkui_textcase) | ArkUI_TextCase | Enumerates text cases. |
| [ArkUI_TextCopyOptions](#arkui_textcopyoptions) | ArkUI_TextCopyOptions | Enumerates copy options, which define whether copy and paste is allowed for text content. |
| [ArkUI_TextOverflow](#arkui_textoverflow) | ArkUI_TextOverflow | Enumerates the display modes when the text is too long. |
| [ArkUI_WordBreak](#arkui_wordbreak) | ArkUI_WordBreak | Enumerates word break rules. |
| [ArkUI_EllipsisMode](#arkui_ellipsismode) | ArkUI_EllipsisMode | Enumerates ellipsis positions. |
| [ArkUI_KeyboardAppearance](#arkui_keyboardappearance) | ArkUI_KeyboardAppearance | Enumerates the appearance of the keyboard when the text box is focused. |
| [ArkUI_TextMenuItemId](#arkui_textmenuitemid) | ArkUI_TextMenuItemId | Enumerates the IDs of text menu items. |
| [OH_ArkUI_LineBreakStrategy](#oh_arkui_linebreakstrategy) | OH_ArkUI_LineBreakStrategy | Enumerates line break policies. |
| [ArkUI_TextSpanType](#arkui_textspantype) | ArkUI_TextSpanType | Enumerates the text recognition types of a custom text selection menu. |
| [ArkUI_TextResponseType](#arkui_textresponsetype) | ArkUI_TextResponseType | Enumerates the response types of a custom text selection menu. |

### Functions

| Name | Description |
| -- | -- |
| [typedef void (\*ArkUI_TextCreateMenuCallback)(ArkUI_TextMenuItemArray* items, void* userData)](#arkui_textcreatemenucallback) | Callback for the text menu creation event. This callback is triggered when a text menu is created, allowing you to set menu data in it. |
| [typedef void (\*ArkUI_TextPrepareMenuCallback)(ArkUI_TextMenuItemArray* items, void* userData)](#arkui_textpreparemenucallback) | Callback for the text menu preparation event. This callback is called when the text selection area changes and before the menu is displayed, allowing you to set menu data in it. |
| [typedef bool (\*ArkUI_TextMenuItemClickCallback)(const ArkUI_TextMenuItem* item, int32_t start, int32_t end, void* userData)](#arkui_textmenuitemclickcallback) | Callback for the text menu item click event. This callback is called when a menu item is clicked. You can intercept the default processing behavior in this callback. It is applicable when custom logic needs to be executed upon a menu item click, such as validating clipboard content before pasting, attaching custom information when copying, or logging operations before sharing. |
| [ArkUI_ShowCounterConfig* OH_ArkUI_ShowCounterConfig_Create()](#oh_arkui_showcounterconfig_create) | Creates a text input counter configuration object. When this object is no longer used, call [OH_ArkUI_ShowCounterConfig_Dispose](#oh_arkui_showcounterconfig_dispose) to dispose of it. |
| [void OH_ArkUI_ShowCounterConfig_Dispose(ArkUI_ShowCounterConfig* config)](#oh_arkui_showcounterconfig_dispose) | Disposes of the text input counter configuration object created by [OH_ArkUI_ShowCounterConfig_Create](#oh_arkui_showcounterconfig_create). |
| [void OH_ArkUI_ShowCounterConfig_SetCounterTextColor(ArkUI_ShowCounterConfig* config, uint32_t color)](#oh_arkui_showcounterconfig_setcountertextcolor) | Sets the text color of the counter when the text input has not reached the maximum character limit. |
| [void OH_ArkUI_ShowCounterConfig_SetCounterTextOverflowColor(ArkUI_ShowCounterConfig* config, uint32_t color)](#oh_arkui_showcounterconfig_setcountertextoverflowcolor) | Sets the text color of the counter when the text input exceeds the maximum character limit. |
| [uint32_t OH_ArkUI_ShowCounterConfig_GetCounterTextColor(ArkUI_ShowCounterConfig* config)](#oh_arkui_showcounterconfig_getcountertextcolor) | Obtains the text color of the counter when the text input has not reached the maximum character limit. |
| [uint32_t OH_ArkUI_ShowCounterConfig_GetCounterTextOverflowColor(ArkUI_ShowCounterConfig* config)](#oh_arkui_showcounterconfig_getcountertextoverflowcolor) | Obtains the text color of the counter when the text input exceeds the maximum character limit. |
| [ArkUI_TextMenuItem* OH_ArkUI_TextMenuItem_Create()](#oh_arkui_textmenuitem_create) | Creates a text menu item object for customizing the text selection menu or extending the system menu. It is applicable when custom menu items need to be added, such as sharing to a specific platform or performing custom editing operations. When this object is no longer used, call [OH_ArkUI_TextMenuItem_Dispose](#oh_arkui_textmenuitem_dispose) to dispose of it. |
| [void OH_ArkUI_TextMenuItem_Dispose(ArkUI_TextMenuItem* textMenuItem)](#oh_arkui_textmenuitem_dispose) | Disposes of the text menu item object created by [OH_ArkUI_TextMenuItem_Create](#oh_arkui_textmenuitem_create). |
| [ArkUI_TextEditMenuOptions* OH_ArkUI_TextEditMenuOptions_Create()](#oh_arkui_texteditmenuoptions_create) | Creates a text menu extension object for extending the text editing menu functionality. It is applicable when custom menu items need to be added to the text editing component, such as inserting special characters or performing quick formatting. When this object is no longer used, call [OH_ArkUI_TextEditMenuOptions_Dispose](#oh_arkui_texteditmenuoptions_dispose) to dispose of it. |
| [void OH_ArkUI_TextEditMenuOptions_Dispose(ArkUI_TextEditMenuOptions* editMenuOptions)](#oh_arkui_texteditmenuoptions_dispose) | Disposes of the text menu extension object created by [OH_ArkUI_TextEditMenuOptions_Create](#oh_arkui_texteditmenuoptions_create). |
| [ArkUI_TextSelectionMenuOptions* OH_ArkUI_TextSelectionMenuOptions_Create()](#oh_arkui_textselectionmenuoptions_create) | Creates a custom text selection menu object for configuring the content and behavior of the text selection menu. It is applicable when the text selection menu needs to be fully customized, such as replacing the default menu and adding application-specific operations. When this object is no longer used, call [OH_ArkUI_TextSelectionMenuOptions_Dispose](#oh_arkui_textselectionmenuoptions_dispose) to dispose of it. |
| [void OH_ArkUI_TextSelectionMenuOptions_Dispose(ArkUI_TextSelectionMenuOptions* selectionMenuOptions)](#oh_arkui_textselectionmenuoptions_dispose) | Disposes of the custom text selection menu object created by [OH_ArkUI_TextSelectionMenuOptions_Create](#oh_arkui_textselectionmenuoptions_create). |
| [ArkUI_TextContentBaseController* OH_ArkUI_TextContentBaseController_Create()](#oh_arkui_textcontentbasecontroller_create) | Creates a text content base controller object. When this object is no longer used, call [OH_ArkUI_TextContentBaseController_Dispose](#oh_arkui_textcontentbasecontroller_dispose) to dispose of it. |
| [void OH_ArkUI_TextContentBaseController_Dispose(ArkUI_TextContentBaseController* controller)](#oh_arkui_textcontentbasecontroller_dispose) | Disposes of the text content base controller object created by [OH_ArkUI_TextContentBaseController_Create](#oh_arkui_textcontentbasecontroller_create). |
| [void OH_ArkUI_TextContentBaseController_DeleteBackward(ArkUI_TextContentBaseController* controller)](#oh_arkui_textcontentbasecontroller_deletebackward) | Deletes the character before the cursor in editing state; deletes the last character of the text box component in other states. |
| [void OH_ArkUI_TextContentBaseController_ScrollToVisible(ArkUI_TextContentBaseController* controller, int32_t start, int32_t end)](#oh_arkui_textcontentbasecontroller_scrolltovisible) | Passes the start and end indexes to the bound text box component, and scrolls the text within the range to the visible area. |
| [OH_ArkUI_DecorationStyleOptions* OH_ArkUI_DecorationStyleOptions_Create()](#oh_arkui_decorationstyleoptions_create) | Creates a decoration style object for setting the type, style, and color of text decorative lines. It is applicable when decoration effects such as underlines or strikethroughs need to be added to text, for example, in rich text editors, hyperlink text, or price tags. When this object is no longer used, call [OH_ArkUI_DecorationStyleOptions_Destroy](#oh_arkui_decorationstyleoptions_destroy) to destroy it. |
| [void OH_ArkUI_DecorationStyleOptions_Destroy(OH_ArkUI_DecorationStyleOptions* options)](#oh_arkui_decorationstyleoptions_destroy) | Destroys the decoration style object created by [OH_ArkUI_DecorationStyleOptions_Create](#oh_arkui_decorationstyleoptions_create). |

## Enum Description

### ArkUI_TextAlignment

```c
enum ArkUI_TextAlignment
```

**Description**

Enumerates text horizontal alignment styles.

**Since:** 12

| Value | Description |
| -- | -- |
| ARKUI_TEXT_ALIGNMENT_START = 0 | Aligned with the start. |
| ARKUI_TEXT_ALIGNMENT_CENTER = 1 | Horizontally centered. |
| ARKUI_TEXT_ALIGNMENT_END = 2 | Aligned with the end. |
| ARKUI_TEXT_ALIGNMENT_JUSTIFY = 3 | Aligned with both margins. |
| ARKUI_TEXT_ALIGNMENT_LEFT_TO_RIGHT = 4 | Aligned from left to right.<br>**Since:** 23 |
| ARKUI_TEXT_ALIGNMENT_RIGHT_TO_LEFT = 5 | Aligned from right to left.<br>**Since:** 23 |

### ArkUI_TextVerticalAlignment

```c
enum ArkUI_TextVerticalAlignment
```

**Description**

Enumerates text vertical alignment styles.

**Since:** 20

| Value | Description |
| -- | -- |
| ARKUI_TEXT_VERTICAL_ALIGNMENT_BASELINE = 0 | Aligned to the baseline. |
| ARKUI_TEXT_VERTICAL_ALIGNMENT_BOTTOM = 1 | Bottom aligned. |
| ARKUI_TEXT_VERTICAL_ALIGNMENT_CENTER = 2 | Centered. |
| ARKUI_TEXT_VERTICAL_ALIGNMENT_TOP = 3 | Top aligned. |

### ArkUI_TextContentAlign

```c
enum ArkUI_TextContentAlign
```

**Description**

Enumerates vertical alignment styles in the text content area.

**Since:** 21

| Value | Description |
| -- | -- |
| ARKUI_TEXT_CONTENT_ALIGN_TOP = 0 | Top aligned. |
| ARKUI_TEXT_CONTENT_ALIGN_CENTER = 1 | Centered. |
| ARKUI_TEXT_CONTENT_ALIGN_BOTTOM = 2 | Bottom aligned. |

### ArkUI_TextDirection

```c
enum ArkUI_TextDirection
```

**Description**

Enumerates text layout directions.

**Since:** 23

| Value | Description |
| -- | -- |
| ARKUI_TEXT_DIRECTION_LTR = 0 | From left to right. |
| ARKUI_TEXT_DIRECTION_RTL = 1 | From right to left. |
| ARKUI_TEXT_DIRECTION_DEFAULT = 2 | Follows the component layout. |
| ARKUI_TEXT_DIRECTION_AUTO = 3 | Follows the writing direction of the content. For example, for right-to-left (RTL) languages (such as Tibetan and Uyghur), the text is laid out from right to left. For left-to-right (LTR) languages (such as Chinese and English), the text is laid out from left to right. |

### ArkUI_EnterKeyType

```c
enum ArkUI_EnterKeyType
```

**Description**

Enumerates the types of the **Enter** key for single-line text input.

**Since:** 12

| Value | Description |
| -- | -- |
| ARKUI_ENTER_KEY_TYPE_GO = 2 | The **Enter** key is labeled "Go." |
| ARKUI_ENTER_KEY_TYPE_SEARCH = 3 | The **Enter** key is labeled "Search." |
| ARKUI_ENTER_KEY_TYPE_SEND = 4 | The **Enter** key is labeled "Send." |
| ARKUI_ENTER_KEY_TYPE_NEXT = 5 | The **Enter** key is labeled "Next." |
| ARKUI_ENTER_KEY_TYPE_DONE = 6 | The **Enter** key is labeled "Done." |
| ARKUI_ENTER_KEY_TYPE_PREVIOUS = 7 | The **Enter** key is labeled "Previous." |
| ARKUI_ENTER_KEY_TYPE_NEW_LINE = 8 | The **Enter** key is labeled "New Line." |

### ArkUI_TextDecorationType

```c
enum ArkUI_TextDecorationType
```

**Description**

Enumerates text decoration types.

**Since:** 12

| Value | Description |
| -- | -- |
| ARKUI_TEXT_DECORATION_TYPE_NONE = 0 | No text decoration. |
| ARKUI_TEXT_DECORATION_TYPE_UNDERLINE = 1 | Line under the text. |
| ARKUI_TEXT_DECORATION_TYPE_OVERLINE = 2 | Line over the text. |
| ARKUI_TEXT_DECORATION_TYPE_LINE_THROUGH = 3 | Line through the text. |

### ArkUI_TextDecorationStyle

```c
enum ArkUI_TextDecorationStyle
```

**Description**

Enumerates text decoration styles.

**Since:** 12

| Value | Description |
| -- | -- |
| ARKUI_TEXT_DECORATION_STYLE_SOLID = 0 | Single solid line. |
| ARKUI_TEXT_DECORATION_STYLE_DOUBLE = 1 | Double solid line. |
| ARKUI_TEXT_DECORATION_STYLE_DOTTED = 2 | Dotted line. |
| ARKUI_TEXT_DECORATION_STYLE_DASHED = 3 | Dashed line. |
| ARKUI_TEXT_DECORATION_STYLE_WAVY = 4 | Wavy line. |

### ArkUI_TextCase

```c
enum ArkUI_TextCase
```

**Description**

Enumerates text cases.

**Since:** 12

| Value | Description |
| -- | -- |
| ARKUI_TEXT_CASE_NORMAL = 0 | The original case of the text is retained. |
| ARKUI_TEXT_CASE_LOWER = 1 | All letters in the text are in lowercase. |
| ARKUI_TEXT_CASE_UPPER = 2 | All letters in the text are in uppercase. |

### ArkUI_TextCopyOptions

```c
enum ArkUI_TextCopyOptions
```

**Description**

Enumerates copy options, which define whether copy and paste is allowed for text content.

**Since:** 12

| Value | Description |
| -- | -- |
| ARKUI_TEXT_COPY_OPTIONS_NONE = 0 | Copy is not allowed. |
| ARKUI_TEXT_COPY_OPTIONS_IN_APP = 1 | Intra-application copy is allowed. |
| ARKUI_TEXT_COPY_OPTIONS_LOCAL_DEVICE = 2 | Intra-device copy is allowed. |
| ARKUI_TEXT_COPY_OPTIONS_CROSS_DEVICE = 3 | Cross-device copy is allowed. |

### ArkUI_TextOverflow

```c
enum ArkUI_TextOverflow
```

**Description**

Enumerates the display modes when the text is too long.

**Since:** 12

| Value | Description |
| -- | -- |
| ARKUI_TEXT_OVERFLOW_NONE = 0 | Extra-long text is not clipped. |
| ARKUI_TEXT_OVERFLOW_CLIP = 1 | Extra-long text is clipped. |
| ARKUI_TEXT_OVERFLOW_ELLIPSIS = 2 | An ellipsis (...) is used to represent text overflow. |
| ARKUI_TEXT_OVERFLOW_MARQUEE = 3 | Text continuously scrolls in marquee mode when text overflow occurs. |

### ArkUI_WordBreak

```c
enum ArkUI_WordBreak
```

**Description**

Enumerates word break rules.

**Since:** 12

| Value | Description |
| -- | -- |
| ARKUI_WORD_BREAK_NORMAL = 0 | Word breaks can occur between any two characters for Chinese, Japanese, and Korean (CJK) text, but can occur only at a space character for non-CJK text (such as English). It is applicable to general scenarios where line break control requirements are not high. |
| ARKUI_WORD_BREAK_BREAK_ALL = 1 | Word breaks can occur between any two characters for non-CJK text. Word breaks can occur between any two characters for Chinese, Japanese, and Korean (CJK) text. |
| ARKUI_WORD_BREAK_BREAK_WORD = 2 | Word breaks can occur between any two characters for non-CJK text, except that if it preferentially wraps lines at appropriate characters (for example, spaces) whenever possible. CJK text behavior is the same as for **NORMAL**. |
| ARKUI_WORD_BREAK_HYPHENATION = 3 | Line breaks can occur between any two syllabic units for non-CJK text. CJK text behavior is the same as for **NORMAL**.<br>**Since:** 18 |

### ArkUI_EllipsisMode

```c
enum ArkUI_EllipsisMode
```

**Description**

Enumerates ellipsis positions.

**Since:** 12

| Value | Description |
| -- | -- |
| ARKUI_ELLIPSIS_MODE_START = 0 | An ellipsis is used at the start of the line of text. This applies to single-line text scenarios. |
| ARKUI_ELLIPSIS_MODE_CENTER = 1 | An ellipsis is used at the center of the line of text. This applies to single-line text scenarios. |
| ARKUI_ELLIPSIS_MODE_END = 2 | An ellipsis is used at the end of the line of text. This applies to single-line and multi-line text scenarios. |
| ARKUI_ELLIPSIS_MODE_MULTILINE_START = 3 | An ellipsis is used at the start of the line of text. This applies to single-line and multi-line text scenarios.<br>**Since:** 24 |
| ARKUI_ELLIPSIS_MODE_MULTILINE_CENTER = 4 | An ellipsis is used at the center of the line of text. This applies to single-line and multi-line text scenarios.<br>**Since:** 24 |

### ArkUI_KeyboardAppearance

```c
enum ArkUI_KeyboardAppearance
```

**Description**

Enumerates the appearance of the keyboard when the text box is focused.

**Since:** 15

| Value | Description |
| -- | -- |
| ARKUI_KEYBOARD_APPEARANCE_NONE_IMMERSIVE = 0 | Default appearance mode, not using the immersive style. |
| ARKUI_KEYBOARD_APPEARANCE_IMMERSIVE = 1 | Immersive style, following the system color mode. |
| ARKUI_KEYBOARD_APPEARANCE_LIGHT_IMMERSIVE = 2 | Immersive style in light mode. |
| ARKUI_KEYBOARD_APPEARANCE_DARK_IMMERSIVE = 3 | Immersive style in dark mode. |

### ArkUI_TextMenuItemId

```c
enum ArkUI_TextMenuItemId
```

**Description**

Enumerates the IDs of text menu items.

**Since:** 22

| Value | Description |
| -- | -- |
| ARKUI_TEXT_MENU_ITEM_ID_CUT = 0 | Cut. |
| ARKUI_TEXT_MENU_ITEM_ID_COPY = 1 | Copy. |
| ARKUI_TEXT_MENU_ITEM_ID_PASTE = 2 | Paste. |
| ARKUI_TEXT_MENU_ITEM_ID_SELECT_ALL = 3 | Select all. |
| ARKUI_TEXT_MENU_ITEM_ID_COLLABORATION_SERVICE = 4 | Collaboration service that provides cross-device interaction capabilities, such as cross-device camera access. |
| ARKUI_TEXT_MENU_ITEM_ID_CAMERA_INPUT = 5 | Camera input. |
| ARKUI_TEXT_MENU_ITEM_ID_AI_WRITER = 6 | AI-assisted writing. This menu item depends on a large language model to take effect. |
| ARKUI_TEXT_MENU_ITEM_ID_TRANSLATE = 7 | Translation menu item. The translation service is provided for the selected text. |
| ARKUI_TEXT_MENU_ITEM_ID_SEARCH = 8 | Search. This menu item launches a browser to search for the selected text. |
| ARKUI_TEXT_MENU_ITEM_ID_SHARE = 9 | Share menu item. This menu item launches a window for sharing the selected text. |
| ARKUI_TEXT_MENU_ITEM_ID_URL = 10 | URL menu item. This menu item provides the redirection service for the selected URL, launching a browser search or application page. |
| ARKUI_TEXT_MENU_ITEM_ID_EMAIL = 11 | Email menu item. This menu item provides the redirection service for the selected email address, launching the email application. |
| ARKUI_TEXT_MENU_ITEM_ID_PHONE_NUMBER = 12 | Phone call menu item. This menu item provides the redirection service for the selected phone number, launching the phone dialer page. |
| ARKUI_TEXT_MENU_ITEM_ID_ADDRESS = 13 | Navigation menu item. This menu item provides the redirection service for the selected address, launching the map application. |
| ARKUI_TEXT_MENU_ITEM_ID_DATA_TIME = 14 | Event creation menu item. This menu item provides the redirection service for the selected date and time, launching the page for creating a calendar event. |
| ARKUI_TEXT_MENU_ITEM_ID_ASK_AI = 15 | Ask AI. This menu item provides the AI query capability for the selected text. This menu item depends on a large language model to take effect. |
| ARKUI_TEXT_MENU_ITEM_ID_AUTO_FILL = 16 | Autofill. For example, the account and password can be automatically filled.<br>**Since:** 24 |
| ARKUI_TEXT_MENU_ITEM_ID_PASSWORD_VAULT = 17 | Password vault.<br>**Since:** 24 |
| ARKUI_TEXT_MENU_ITEM_ID_APP_RESERVED_BEGIN = 10000 | Start ID of a custom menu item. In addition to the built-in menu item IDs, you can also customize menu item IDs. |
| ARKUI_TEXT_MENU_ITEM_ID_APP_RESERVED_END = 20000 | End ID of a custom menu item. In addition to the built-in menu item IDs, you can also customize menu item IDs. |

### OH_ArkUI_LineBreakStrategy

```c
enum OH_ArkUI_LineBreakStrategy
```

**Description**

Enumerates line break policies.

**Since:** 24

| Value | Description |
| -- | -- |
| OH_ARKUI_LINE_BREAK_STRATEGY_GREEDY = 0 | Greedy mode.<br>Places as many words on a line as possible and moves to the next line only if no more words can fit into the same line. |
| OH_ARKUI_LINE_BREAK_STRATEGY_HIGH_QUALITY = 1 | High-quality mode.<br>Fills in lines as much as possible on the basis of **BALANCED**, which may result in a large blank area on the last line. |
| OH_ARKUI_LINE_BREAK_STRATEGY_BALANCE = 2 | Balance mode.<br>Without splitting words, the width of each line in a paragraph is the same as much as possible. |

### ArkUI_TextSpanType

```c
enum ArkUI_TextSpanType
```

**Description**

Enumerates the recognition types of a custom text selection menu.

**Since:** 22

| Value | Description |
| -- | -- |
| ARKUI_TEXT_SPAN_TYPE_TEXT = 0 | Text. |
| ARKUI_TEXT_SPAN_TYPE_IMAGE = 1 | Image. |
| ARKUI_TEXT_SPAN_TYPE_MIXED = 2 | Mixed text and image. |
| ARKUI_TEXT_SPAN_TYPE_DEFAULT = 3 | If this type and other types are set, the menu corresponding to the type of the selected text is displayed after the text is selected. If this type is set but other types are not set, the menu corresponding to this type is displayed after the text is selected. For example, if there are two menus whose recognition types are **ARKUI_TEXT_SPAN_TYPE_TEXT** and **ARKUI_TEXT_SPAN_TYPE_DEFAULT** respectively, the menu corresponding to **ARKUI_TEXT_SPAN_TYPE_TEXT** is displayed when the text is selected, and the menu corresponding to **ARKUI_TEXT_SPAN_TYPE_DEFAULT** is displayed when the image is selected. |

### ArkUI_TextResponseType

```c
enum ArkUI_TextResponseType
```

**Description**

Enumerates the response types of a custom text selection menu.

**Since:** 22

| Value | Description |
| -- | -- |
| ARKUI_TEXT_RESPONSE_TYPE_RIGHT_CLICK = 0 | The menu is displayed when the component is right-clicked. |
| ARKUI_TEXT_RESPONSE_TYPE_LONG_PRESS = 1 | The menu is displayed when the component is long-pressed. |
| ARKUI_TEXT_RESPONSE_TYPE_SELECT = 2 | The menu is displayed when the component is selected. |
| ARKUI_TEXT_RESPONSE_TYPE_DEFAULT = 3 | If this type and other types are set, the menu corresponding to the type is displayed when the operation of another type is triggered. If this type is set but other types are not set, the menu corresponding to this type is displayed when the operation of another type is triggered. For example, if there are two menus whose response types are **ARKUI_TEXT_RESPONSE_TYPE_RIGHT_CLICK** and **ARKUI_TEXT_RESPONSE_TYPE_DEFAULT** respectively, the menu corresponding to **ARKUI_TEXT_RESPONSE_TYPE_RIGHT_CLICK** is displayed when you right-click the menu, and the menu corresponding to **ARKUI_TEXT_RESPONSE_TYPE_DEFAULT** is displayed when you hold down the right mouse button. |

## Function Description

### ArkUI_TextCreateMenuCallback()

```c
typedef void (*ArkUI_TextCreateMenuCallback)(ArkUI_TextMenuItemArray* items, void* userData)
```

**Description**

Callback for the text menu creation event. This callback is triggered when a text menu is created, allowing you to set menu data in it.

> **NOTE**
>
> This callback and **ArkUI_TextPrepareMenuCallback** are both used for menu data setting, but their trigger timings differ: this callback is triggered when a menu is created, while **ArkUI_TextPrepareMenuCallback** is triggered after the text selection area changes and before the menu is displayed. Both can be registered simultaneously to handle menu initialization and selection change scenarios respectively.

**Since:** 22

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_TextMenuItemArray](capi-arkui-nativemodule-arkui-textmenuitemarray.md)* items | Pointer to the **ArkUI_TextMenuItemArray** object, which is created and released by the system. You can call [OH_ArkUI_TextMenuItemArray_Insert](capi-native-type-h.md#oh_arkui_textmenuitemarray_insert) and [OH_ArkUI_TextMenuItemArray_Erase](capi-native-type-h.md#oh_arkui_textmenuitemarray_erase) to modify the array in the callback. |
| void\* userData | Pointer to the user-defined data, which is passed by you when registering the callback and returned as-is when the callback is triggered. It is used to obtain context data in the callback. The value **null** indicates that no custom data is passed. |

### ArkUI_TextPrepareMenuCallback()

```c
typedef void (*ArkUI_TextPrepareMenuCallback)(ArkUI_TextMenuItemArray* items, void* userData)
```

**Description**

Callback for the text menu preparation event. This callback is called when the text selection area changes and before the menu is displayed, allowing you to set menu data in it.

**Since:** 22

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_TextMenuItemArray](capi-arkui-nativemodule-arkui-textmenuitemarray.md)* items | Pointer to the **ArkUI_TextMenuItemArray** object, which is created and released by the system. You can call [OH_ArkUI_TextMenuItemArray_Insert](capi-native-type-h.md#oh_arkui_textmenuitemarray_insert) and [OH_ArkUI_TextMenuItemArray_Erase](capi-native-type-h.md#oh_arkui_textmenuitemarray_erase) to modify the array in the callback. |
| void\* userData | Pointer to the user-defined data, which is passed by you when registering the callback and returned as-is when the callback is triggered. It is used to obtain context data in the callback. The value **null** indicates that no custom data is passed. |

### ArkUI_TextMenuItemClickCallback()

```c
typedef bool (*ArkUI_TextMenuItemClickCallback)(const ArkUI_TextMenuItem* item, int32_t start, int32_t end, void* userData)
```

**Description**

Callback for the text menu item click event. This callback is called when a menu item is clicked. You can intercept the default processing behavior in this callback. It is applicable when custom logic needs to be executed upon a menu item click, such as validating clipboard content before pasting, attaching custom information when copying, or logging operations before sharing.

**Since:** 22

**Parameters**

| Name | Description |
| -- | -- |
| const [ArkUI_TextMenuItem](capi-arkui-nativemodule-arkui-textmenuitem.md)* item | Pointer to the **ArkUI_TextMenuItem** object, indicating the clicked text menu item. |
| int32_t start | Start index of the selected text. It is passed by the system when the callback is triggered and indicates the start position of the selected text. The index starts from 0. |
| int32_t end | End index of the selected text. It is passed by the system when the callback is triggered and indicates the end position of the selected text. The index starts from 0, and the end index is greater than or equal to the start index. |
| void\* userData | Pointer to the user-defined data, which is passed by you when registering the callback and returned as-is when the callback is triggered. It is used to obtain context data in the callback. The value **null** indicates that no custom data is passed. |

**Returns**

| Type | Description |
| -- | -- |
| bool | Whether to intercept the default processing behavior of the system.<br> **true**: Intercept the system's default processing behavior. For example, clicking text menu items such as **Paste** or **Copy** will only execute the custom processing behavior.<br> **false**: Do not intercept the system's default processing behavior. For example, clicking text menu items such as **Paste** or **Copy** will first execute the custom processing behavior and then the default processing behavior. |

### OH_ArkUI_ShowCounterConfig_Create()

```c
ArkUI_ShowCounterConfig* OH_ArkUI_ShowCounterConfig_Create()
```

**Description**

Creates a text input counter configuration object. When this object is no longer used, call [OH_ArkUI_ShowCounterConfig_Dispose](#oh_arkui_showcounterconfig_dispose) to dispose of it.

**Since:** 22

**Returns**

| Type | Description |
| -- | -- |
| [ArkUI_ShowCounterConfig*](capi-arkui-nativemodule-arkui-textshowcounterconfig.md) | Pointer to the text input counter configuration object. |

### OH_ArkUI_ShowCounterConfig_Dispose()

```c
void OH_ArkUI_ShowCounterConfig_Dispose(ArkUI_ShowCounterConfig* config)
```

**Description**

Disposes of the text input counter configuration object created by [OH_ArkUI_ShowCounterConfig_Create](#oh_arkui_showcounterconfig_create).

**Since:** 22

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_ShowCounterConfig](capi-arkui-nativemodule-arkui-textshowcounterconfig.md)* config | Pointer to the text input counter configuration object to be disposed of. |

### OH_ArkUI_ShowCounterConfig_SetCounterTextColor()

```c
void OH_ArkUI_ShowCounterConfig_SetCounterTextColor(ArkUI_ShowCounterConfig* config, uint32_t color)
```

**Description**

Sets the text color of the counter when the text input has not reached the maximum character limit. If this API is not called, the default color is **0x66182431**, displayed as gray.

**Since:** 22

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_ShowCounterConfig](capi-arkui-nativemodule-arkui-textshowcounterconfig.md)* config | Pointer to the text input counter configuration object. It must be created using **OH_ArkUI_ShowCounterConfig_Create()** before use. |
| uint32_t color | Text color of the counter when the text input has not reached the maximum character limit, in 0xARGB format. |

### OH_ArkUI_ShowCounterConfig_SetCounterTextOverflowColor()

```c
void OH_ArkUI_ShowCounterConfig_SetCounterTextOverflowColor(ArkUI_ShowCounterConfig* config, uint32_t color)
```

**Description**

Sets the text color of the counter when the text input exceeds the maximum character limit. If this API is not called, the default color is **0x99FA2A2D**, displayed as red.

**Since:** 22

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_ShowCounterConfig](capi-arkui-nativemodule-arkui-textshowcounterconfig.md)* config | Pointer to the text input counter configuration object. |
| uint32_t color | Text color of the counter when the text input exceeds the maximum character limit, in 0xARGB format. |

### OH_ArkUI_ShowCounterConfig_GetCounterTextColor()

```c
uint32_t OH_ArkUI_ShowCounterConfig_GetCounterTextColor(ArkUI_ShowCounterConfig* config)
```

**Description**

Obtains the text color of the counter when the text input has not reached the maximum character limit.

**Since:** 22

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_ShowCounterConfig](capi-arkui-nativemodule-arkui-textshowcounterconfig.md)* config | Pointer to the text input counter configuration object. |

**Returns**

| Type | Description |
| -- | -- |
| uint32_t | Text color of the counter when the text input has not reached the maximum character limit, in 0xARGB format. **0** is returned if the color is not set using [OH_ArkUI_ShowCounterConfig_SetCounterTextColor](#oh_arkui_showcounterconfig_setcountertextcolor); otherwise, the set color value is returned. |

### OH_ArkUI_ShowCounterConfig_GetCounterTextOverflowColor()

```c
uint32_t OH_ArkUI_ShowCounterConfig_GetCounterTextOverflowColor(ArkUI_ShowCounterConfig* config)
```

**Description**

Obtains the text color of the counter when the text input exceeds the maximum character limit.

**Since:** 22

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_ShowCounterConfig](capi-arkui-nativemodule-arkui-textshowcounterconfig.md)* config | Pointer to the text input counter configuration object. |

**Returns**

| Type | Description |
| -- | -- |
| uint32_t | Text color of the counter when the text input exceeds the maximum character limit, in 0xARGB format. **0** is returned if the color is not set using [OH_ArkUI_ShowCounterConfig_SetCounterTextOverflowColor](#oh_arkui_showcounterconfig_setcountertextoverflowcolor); otherwise, the set color value is returned. |

### OH_ArkUI_TextMenuItem_Create()

```c
ArkUI_TextMenuItem* OH_ArkUI_TextMenuItem_Create()
```

**Description**

Creates a text menu item object for customizing the text selection menu or extending the system menu. It is applicable when custom menu items need to be added, such as sharing to a specific platform or performing custom editing operations. When this object is no longer used, call [OH_ArkUI_TextMenuItem_Dispose](#oh_arkui_textmenuitem_dispose) to dispose of it.

**Since:** 22

**Returns**

| Type | Description |
| -- | -- |
| [ArkUI_TextMenuItem*](capi-arkui-nativemodule-arkui-textmenuitem.md) | Pointer to the text menu item object, used to represent a single menu item in the text selection menu. |

### OH_ArkUI_TextMenuItem_Dispose()

```c
void OH_ArkUI_TextMenuItem_Dispose(ArkUI_TextMenuItem* textMenuItem)
```

**Description**

Disposes of the text menu item object created by [OH_ArkUI_TextMenuItem_Create](#oh_arkui_textmenuitem_create).

**Since:** 22

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_TextMenuItem](capi-arkui-nativemodule-arkui-textmenuitem.md)* textMenuItem | Pointer to the **ArkUI_TextMenuItem** object. |

### OH_ArkUI_TextEditMenuOptions_Create()

```c
ArkUI_TextEditMenuOptions* OH_ArkUI_TextEditMenuOptions_Create()
```

**Description**

Creates a text menu extension object for extending the text editing menu functionality. It is applicable when custom menu items need to be added to the text editing component, such as inserting special characters or performing quick formatting. When this object is no longer used, call [OH_ArkUI_TextEditMenuOptions_Dispose](#oh_arkui_texteditmenuoptions_dispose) to dispose of it.

**Since:** 22

**Returns**

| Type | Description |
| -- | -- |
| [ArkUI_TextEditMenuOptions*](capi-arkui-nativemodule-arkui-texteditmenuoptions.md) | Pointer to the text menu extension object, used to extend the functionality of the text editing menu. |

### OH_ArkUI_TextEditMenuOptions_Dispose()

```c
void OH_ArkUI_TextEditMenuOptions_Dispose(ArkUI_TextEditMenuOptions* editMenuOptions)
```

**Description**

Disposes of the text menu extension object created by [OH_ArkUI_TextEditMenuOptions_Create](#oh_arkui_texteditmenuoptions_create).

**Since:** 22

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_TextEditMenuOptions](capi-arkui-nativemodule-arkui-texteditmenuoptions.md)* editMenuOptions | Pointer to the **ArkUI_TextEditMenuOptions** object. |

### OH_ArkUI_TextSelectionMenuOptions_Create()

```c
ArkUI_TextSelectionMenuOptions* OH_ArkUI_TextSelectionMenuOptions_Create()
```

**Description**

Creates a custom text selection menu object for configuring the content and behavior of the text selection menu. It is applicable when the text selection menu needs to be fully customized, such as replacing the default menu and adding application-specific operations. When this object is no longer used, call [OH_ArkUI_TextSelectionMenuOptions_Dispose](#oh_arkui_textselectionmenuoptions_dispose) to dispose of it.

**Since:** 22

**Returns**

| Type | Description |
| -- | -- |
| [ArkUI_TextSelectionMenuOptions*](capi-arkui-nativemodule-arkui-textselectionmenuoptions.md) | Pointer to the custom text selection menu object, used for custom configuration of menu content, styles, and behavior. |

### OH_ArkUI_TextSelectionMenuOptions_Dispose()

```c
void OH_ArkUI_TextSelectionMenuOptions_Dispose(ArkUI_TextSelectionMenuOptions* selectionMenuOptions)
```

**Description**

Disposes of the custom text selection menu object created by [OH_ArkUI_TextSelectionMenuOptions_Create](#oh_arkui_textselectionmenuoptions_create).

**Since:** 22

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_TextSelectionMenuOptions](capi-arkui-nativemodule-arkui-textselectionmenuoptions.md)* selectionMenuOptions | Pointer to the **ArkUI_TextSelectionMenuOptions** object. |

### OH_ArkUI_TextContentBaseController_Create()

```c
ArkUI_TextContentBaseController* OH_ArkUI_TextContentBaseController_Create()
```

**Description**

Creates a text content base controller object. When this object is no longer used, call [OH_ArkUI_TextContentBaseController_Dispose](#oh_arkui_textcontentbasecontroller_dispose) to dispose of it.

**Since:** 23

**Returns**

| Type | Description |
| -- | -- |
| [ArkUI_TextContentBaseController*](capi-arkui-nativemodule-arkui-textcontentbasecontroller.md) | Pointer to the text content base controller object, used for content control of text components, supporting operations such as obtaining, setting, and updating text content. |

### OH_ArkUI_TextContentBaseController_Dispose()

```c
void OH_ArkUI_TextContentBaseController_Dispose(ArkUI_TextContentBaseController* controller)
```

**Description**

Disposes of the text content base controller object created by [OH_ArkUI_TextContentBaseController_Create](#oh_arkui_textcontentbasecontroller_create).

**Since:** 23

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_TextContentBaseController](capi-arkui-nativemodule-arkui-textcontentbasecontroller.md)* controller | Pointer to the text content base controller object to be disposed of. |

### OH_ArkUI_TextContentBaseController_DeleteBackward()

```c
void OH_ArkUI_TextContentBaseController_DeleteBackward(ArkUI_TextContentBaseController* controller)
```

**Description**

Deletes the character before the cursor in editing state; deletes the last character of the text box component in other states.

> **NOTE**
>
> Before use, ensure that the controller has been bound to the input box component.

**Since:** 23

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_TextContentBaseController](capi-arkui-nativemodule-arkui-textcontentbasecontroller.md)* controller | Pointer to the text content base controller object. It must be created through **OH_ArkUI_TextContentBaseController_Create()** before use. |

### OH_ArkUI_TextContentBaseController_ScrollToVisible()

```c
void OH_ArkUI_TextContentBaseController_ScrollToVisible(ArkUI_TextContentBaseController* controller, int32_t start, int32_t end)
```

**Description**

Passes the start and end indexes to the bound text box component, and scrolls the text within the range to the visible area.

**Since:** 23

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_TextContentBaseController](capi-arkui-nativemodule-arkui-textcontentbasecontroller.md)* controller | Pointer to the text content base controller object. It must be created using **OH_ArkUI_TextContentBaseController_Create()** before use.<br>This controller passes the start index and end index to the bound input box component for scrolling. |
| int32_t start | Start text index.<br>The start index must be less than or equal to the end index. Otherwise, the API call is invalid. The value range is [0, Total length of the text in the text box]. If the start index is less than 0, the start index is regarded as 0. If the start index is greater than the total length, the start index is regarded as the total length. |
| int32_t end | End text index.<br>The end index must be greater than or equal to the start index. Otherwise, the API call is invalid. The value range is [0, Total length of the text in the text box]. If the end index is less than 0, the end index is regarded as 0. If the end index is greater than the total length, the end index is regarded as the total length. |

### OH_ArkUI_DecorationStyleOptions_Create()

```c
OH_ArkUI_DecorationStyleOptions* OH_ArkUI_DecorationStyleOptions_Create()
```

**Description**

Creates a decoration style object for setting the type, style, and color of text decorative lines. It is applicable when decoration effects such as underlines or strikethroughs need to be added to text, for example, in rich text editors, hyperlink text, or price tags. When this object is no longer used, call [OH_ArkUI_DecorationStyleOptions_Destroy](#oh_arkui_decorationstyleoptions_destroy) to destroy it.

**Since:** 24

**Returns**

| Type | Description |
| -- | -- |
| [OH_ArkUI_DecorationStyleOptions*](capi-arkui-nativemodule-oh-arkui-decorationstyleoptions.md) | Pointer to the decoration style object, used to define the decorative line style. |

### OH_ArkUI_DecorationStyleOptions_Destroy()

```c
void OH_ArkUI_DecorationStyleOptions_Destroy(OH_ArkUI_DecorationStyleOptions* options)
```

**Description**

Destroys the decoration style object created by [OH_ArkUI_DecorationStyleOptions_Create](#oh_arkui_decorationstyleoptions_create).

**Since:** 24

**Parameters**

| Name | Description |
| -- | -- |
| [OH_ArkUI_DecorationStyleOptions](capi-arkui-nativemodule-oh-arkui-decorationstyleoptions.md)* options | Pointer to the option object to be destroyed. |