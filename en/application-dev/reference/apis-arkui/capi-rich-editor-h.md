# rich_editor.h

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @carnivore233-->
<!--Designer: @xiangyuan6-->
<!--Tester: @jiaoaozihao-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=ed1823b8bfef96231dc44d6fdc52b5591476e06b translatedAt=2026-08-11T09:10:07.134Z pushedAt=2026-08-12T06:03:00.888Z -->

## Overview

Defines structs, enumerations, and APIs related to **RichEditor**. **RichEditor** provides rich text editing capabilities, supporting custom text selection menus, styled string controllers, paragraph and text style settings, and haptic feedback control. It is suitable for scenarios where rich text editing and custom interaction menus need to be implemented in apps.

**File to include:** <arkui/node_attributes/rich_editor.h>

**Library:** libace_ndk.z.so

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Since:** 24

**Related module:** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**Sample:** <!--RP1-->[native_type_sample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/NativeType/native_type_sample)<!--RP1End-->

## Summary

### Structs

| Name | typedef Keyword | Description |
| -- | -- | -- |
| [OH_ArkUI_TextEditorSelectionMenuOptions](capi-arkui-nativemodule-oh-arkui-texteditorselectionmenuoptions.md) | OH_ArkUI_TextEditorSelectionMenuOptions | Defines the text selection menu options of the text editor. |
| [OH_ArkUI_TextEditorPlaceholderOptions](capi-arkui-nativemodule-oh-arkui-texteditorplaceholderoptions.md) | OH_ArkUI_TextEditorPlaceholderOptions | Defines the placeholder text options when no content is entered in the text editor. |
| [OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md) | OH_ArkUI_TextEditorStyledStringController | Defines the styled string controller of the text editor. |
| [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md) | OH_ArkUI_TextEditorParagraphStyle | Defines the paragraph style of the text editor. |
| [OH_ArkUI_TextEditorTextStyle](capi-arkui-nativemodule-oh-arkui-texteditortextstyle.md) | OH_ArkUI_TextEditorTextStyle | Defines the text style of the text editor. |

### Enums

| Name | typedef Keyword | Description |
| -- | -- | -- |
| [OH_ArkUI_HapticFeedbackMode](#oh_arkui_hapticfeedbackmode) | OH_ArkUI_HapticFeedbackMode | Enumerates haptic feedback modes. |
| [OH_ArkUI_TextEditorSpanType](#oh_arkui_texteditorspantype) | OH_ArkUI_TextEditorSpanType | Enumerates the span types of a custom text selection menu. |
| [OH_ArkUI_TextEditorResponseType](#oh_arkui_texteditorresponsetype) | OH_ArkUI_TextEditorResponseType | Enumerates the response types of a custom text selection menu. |
| [OH_ArkUI_TextMenuType](#oh_arkui_textmenutype) | OH_ArkUI_TextMenuType | Enumerates text menu types. |

### Functions

| Name | Description |
| -- | -- |
| [OH_ArkUI_TextEditorPlaceholderOptions* OH_ArkUI_TextEditorPlaceholderOptions_Create()](#oh_arkui_texteditorplaceholderoptions_create) | Creates an option object for the placeholder text used when there is no input. When the object is no longer used, call [OH_ArkUI_TextEditorPlaceholderOptions_Destroy](#oh_arkui_texteditorplaceholderoptions_destroy) to destroy it. |
| [void OH_ArkUI_TextEditorPlaceholderOptions_Destroy(OH_ArkUI_TextEditorPlaceholderOptions* options)](#oh_arkui_texteditorplaceholderoptions_destroy) | Destroys the option object for the placeholder text used when there is no input. |
| [OH_ArkUI_TextEditorStyledStringController* OH_ArkUI_TextEditorStyledStringController_Create()](#oh_arkui_texteditorstyledstringcontroller_create) | Creates a styled string controller object. When the object is no longer used, call [OH_ArkUI_TextEditorStyledStringController_Destroy](#oh_arkui_texteditorstyledstringcontroller_destroy) to destroy it. |
| [void OH_ArkUI_TextEditorStyledStringController_Destroy(OH_ArkUI_TextEditorStyledStringController* controller)](#oh_arkui_texteditorstyledstringcontroller_destroy) | Destroys the styled string controller object. |
| [OH_ArkUI_TextEditorParagraphStyle* OH_ArkUI_TextEditorParagraphStyle_Create()](#oh_arkui_texteditorparagraphstyle_create) | Creates a paragraph style object. When the object is no longer used, call [OH_ArkUI_TextEditorParagraphStyle_Destroy](#oh_arkui_texteditorparagraphstyle_destroy) to destroy it. |
| [void OH_ArkUI_TextEditorParagraphStyle_Destroy(OH_ArkUI_TextEditorParagraphStyle* style)](#oh_arkui_texteditorparagraphstyle_destroy) | Destroys the paragraph style object. |
| [OH_ArkUI_TextEditorTextStyle* OH_ArkUI_TextEditorTextStyle_Create()](#oh_arkui_texteditortextstyle_create) | Creates a text style object. When the object is no longer used, call [OH_ArkUI_TextEditorTextStyle_Destroy](#oh_arkui_texteditortextstyle_destroy) to destroy it. |
| [void OH_ArkUI_TextEditorTextStyle_Destroy(OH_ArkUI_TextEditorTextStyle* style)](#oh_arkui_texteditortextstyle_destroy) | Destroys the text style object. |
| [OH_ArkUI_TextEditorSelectionMenuOptions* OH_ArkUI_TextEditorSelectionMenuOptions_Create()](#oh_arkui_texteditorselectionmenuoptions_create) | Creates a text selection menu option object of the text editor. When the object is no longer used, call [OH_ArkUI_TextEditorSelectionMenuOptions_Destroy](#oh_arkui_texteditorselectionmenuoptions_destroy) to destroy it. |
| [void OH_ArkUI_TextEditorSelectionMenuOptions_Destroy(OH_ArkUI_TextEditorSelectionMenuOptions* options)](#oh_arkui_texteditorselectionmenuoptions_destroy) | Destroys the text selection menu option object of the text editor. |

## Enum Description

### OH_ArkUI_HapticFeedbackMode

```c
enum OH_ArkUI_HapticFeedbackMode
```

**Description**

Enumerates haptic feedback modes, which are used to control the haptic feedback behavior of the text editor during user interactions (such as long press, drag, and other operations).

**Since:** 24

| Value | Description |
| -- | -- |
| OH_ARKUI_HAPTIC_FEEDBACK_MODE_DISABLED = 0 | Disables haptic feedback. |
| OH_ARKUI_HAPTIC_FEEDBACK_MODE_ENABLED = 1 | Enables haptic feedback. |
| OH_ARKUI_HAPTIC_FEEDBACK_MODE_AUTO = 2 | Follows the haptic feedback of the system. |

### OH_ArkUI_TextEditorSpanType

```c
enum OH_ArkUI_TextEditorSpanType
```

**Description**

Enumerates the span types of a custom text selection menu, which are used to identify the span type of the text selection menu in the text editor. Different span types correspond to different content structures, affecting the display and interaction behavior of the custom menu. For example, the **TEXT** type is used when the user selects only text content, the **MIXED** type is used when the selection contains mixed content such as text and images, and the **BUILDER** type is used when a custom menu item layout is required.

**Since:** 24

| Value | Description |
| -- | -- |
| OH_ARKUI_TEXT_EDITOR_SPAN_TYPE_TEXT = 0 | Text span. |
| OH_ARKUI_TEXT_EDITOR_SPAN_TYPE_IMAGE = 1 | Image span. |
| OH_ARKUI_TEXT_EDITOR_SPAN_TYPE_MIXED = 2 | Mixed span. |
| OH_ARKUI_TEXT_EDITOR_SPAN_TYPE_BUILDER = 3 | Custom layout span. |
| OH_ARKUI_TEXT_EDITOR_SPAN_TYPE_DEFAULT = 4 | Default span. |

### OH_ArkUI_TextEditorResponseType

```c
enum OH_ArkUI_TextEditorResponseType
```

**Description**

Enumerates the response types of a custom text selection menu, which are used to identify the interaction method that triggers the menu pop-up. Different response types correspond to different user operations (such as right-click, long press, and mouse-based selection), allowing different menu content to be customized based on the response type.

**Since:** 24

| Value | Description |
| -- | -- |
| OH_ARKUI_TEXT_EDITOR_RESPONSE_TYPE_RIGHT_CLICK = 0 | The menu is displayed when the component is right-clicked. |
| OH_ARKUI_TEXT_EDITOR_RESPONSE_TYPE_LONG_PRESS = 1 | The menu is displayed when the component is long-pressed. |
| OH_ARKUI_TEXT_EDITOR_RESPONSE_TYPE_SELECT = 2 | The menu is displayed when the component is selected. |
| OH_ARKUI_TEXT_EDITOR_RESPONSE_TYPE_DEFAULT = 3 | Default response type. |

### OH_ArkUI_TextMenuType

```c
enum OH_ArkUI_TextMenuType
```

**Description**

Enumerates text menu types, which are used to distinguish different types of pop-up menus in the text editor, including the text selection menu and the preview menu. Different menu types correspond to different interaction scenarios and menu display modes. For example, the text selection menu pops up when the user selects text and is used for text operations such as copy and delete; the preview menu pops up when the user long-presses an image and is used to trigger image content drag preview as well as copy and deletion operations.

**Since:** 24

| Value | Description |
| -- | -- |
| OH_ARKUI_TEXT_EDITOR_SELECTION_MENU = 0 | Text selection menu. |
| OH_ARKUI_TEXT_EDITOR_PREVIEW_MENU = 1 | Preview menu. |

## Function Description

### OH_ArkUI_TextEditorPlaceholderOptions_Create()

```c
OH_ArkUI_TextEditorPlaceholderOptions* OH_ArkUI_TextEditorPlaceholderOptions_Create()
```

**Description**

Creates an option object for the placeholder text used when there is no input. When the object is no longer used, call [OH_ArkUI_TextEditorPlaceholderOptions_Destroy](#oh_arkui_texteditorplaceholderoptions_destroy) to destroy it.

**Since:** 24

**Returns**

| Type | Description |
| -- | -- |
| [OH_ArkUI_TextEditorPlaceholderOptions*](capi-arkui-nativemodule-oh-arkui-texteditorplaceholderoptions.md) | Pointer to the [OH_ArkUI_TextEditorPlaceholderOptions](capi-arkui-nativemodule-oh-arkui-texteditorplaceholderoptions.md) object. |

### OH_ArkUI_TextEditorPlaceholderOptions_Destroy()

```c
void OH_ArkUI_TextEditorPlaceholderOptions_Destroy(OH_ArkUI_TextEditorPlaceholderOptions* options)
```

**Description**

Destroys the option object for the placeholder text used when there is no input.

**Since:** 24

**Parameters**

| Name | Description |
| -- | -- |
| [OH_ArkUI_TextEditorPlaceholderOptions](capi-arkui-nativemodule-oh-arkui-texteditorplaceholderoptions.md)* options | Pointer to the [OH_ArkUI_TextEditorPlaceholderOptions](capi-arkui-nativemodule-oh-arkui-texteditorplaceholderoptions.md) object. |

### OH_ArkUI_TextEditorStyledStringController_Create()

```c
OH_ArkUI_TextEditorStyledStringController* OH_ArkUI_TextEditorStyledStringController_Create()
```

**Description**

Creates a styled string controller object, which is used to control the styled string of the text editor when rich text content needs to be managed through styled strings (such as mixed layout of text and images, dynamic setting of paragraph or character styles, and other scenarios). When the object is no longer used, call [OH_ArkUI_TextEditorStyledStringController_Destroy](#oh_arkui_texteditorstyledstringcontroller_destroy) to destroy it.

**Since:** 24

**Returns**

| Type | Description |
| -- | -- |
| [OH_ArkUI_TextEditorStyledStringController*](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md) | Pointer to the [OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md) object. |

### OH_ArkUI_TextEditorStyledStringController_Destroy()

```c
void OH_ArkUI_TextEditorStyledStringController_Destroy(OH_ArkUI_TextEditorStyledStringController* controller)
```

**Description**

Destroys the styled string controller object.

**Since:** 24

**Parameters**

| Name | Description |
| -- | -- |
| [OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md)* controller | Pointer to the [OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md) object. |

### OH_ArkUI_TextEditorParagraphStyle_Create()

```c
OH_ArkUI_TextEditorParagraphStyle* OH_ArkUI_TextEditorParagraphStyle_Create()
```

**Description**

Creates a paragraph style object. When the object is no longer used, call [OH_ArkUI_TextEditorParagraphStyle_Destroy](#oh_arkui_texteditorparagraphstyle_destroy) to destroy it.

**Since:** 24

**Returns**

| Type | Description |
| -- | -- |
| [OH_ArkUI_TextEditorParagraphStyle*](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md) | Pointer to the [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md) object. |

### OH_ArkUI_TextEditorParagraphStyle_Destroy()

```c
void OH_ArkUI_TextEditorParagraphStyle_Destroy(OH_ArkUI_TextEditorParagraphStyle* style)
```

**Description**

Destroys the paragraph style object.

**Since:** 24

**Parameters**

| Name | Description |
| -- | -- |
| [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md)* style | Pointer to the [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md) object. |

### OH_ArkUI_TextEditorTextStyle_Create()

```c
OH_ArkUI_TextEditorTextStyle* OH_ArkUI_TextEditorTextStyle_Create()
```

**Description**

Creates a text style object. When the object is no longer used, call [OH_ArkUI_TextEditorTextStyle_Destroy](#oh_arkui_texteditortextstyle_destroy) to destroy it.

**Since:** 24

**Returns**

| Type | Description |
| -- | -- |
| [OH_ArkUI_TextEditorTextStyle*](capi-arkui-nativemodule-oh-arkui-texteditortextstyle.md) | Pointer to the [OH_ArkUI_TextEditorTextStyle](capi-arkui-nativemodule-oh-arkui-texteditortextstyle.md) object. |

### OH_ArkUI_TextEditorTextStyle_Destroy()

```c
void OH_ArkUI_TextEditorTextStyle_Destroy(OH_ArkUI_TextEditorTextStyle* style)
```

**Description**

Destroys the text style object.

**Since:** 24

**Parameters**

| Name | Description |
| -- | -- |
| [OH_ArkUI_TextEditorTextStyle](capi-arkui-nativemodule-oh-arkui-texteditortextstyle.md)* style | Pointer to the [OH_ArkUI_TextEditorTextStyle](capi-arkui-nativemodule-oh-arkui-texteditortextstyle.md) object. |

### OH_ArkUI_TextEditorSelectionMenuOptions_Create()

```c
OH_ArkUI_TextEditorSelectionMenuOptions* OH_ArkUI_TextEditorSelectionMenuOptions_Create()
```

**Description**

Creates a text selection menu option object of the text editor. When the object is no longer used, call [OH_ArkUI_TextEditorSelectionMenuOptions_Destroy](#oh_arkui_texteditorselectionmenuoptions_destroy) to destroy it.

**Since:** 24

**Returns**

| Type | Description |
| -- | -- |
| [OH_ArkUI_TextEditorSelectionMenuOptions*](capi-arkui-nativemodule-oh-arkui-texteditorselectionmenuoptions.md) | Pointer to the [OH_ArkUI_TextEditorSelectionMenuOptions](capi-arkui-nativemodule-oh-arkui-texteditorselectionmenuoptions.md) object. |

### OH_ArkUI_TextEditorSelectionMenuOptions_Destroy()

```c
void OH_ArkUI_TextEditorSelectionMenuOptions_Destroy(OH_ArkUI_TextEditorSelectionMenuOptions* options)
```

**Description**

Destroys the text selection menu option object of the text editor.

**Since:** 24

**Parameters**

| Name | Description |
| -- | -- |
| [OH_ArkUI_TextEditorSelectionMenuOptions](capi-arkui-nativemodule-oh-arkui-texteditorselectionmenuoptions.md)* options | Pointer to the [OH_ArkUI_TextEditorSelectionMenuOptions](capi-arkui-nativemodule-oh-arkui-texteditorselectionmenuoptions.md) object. |