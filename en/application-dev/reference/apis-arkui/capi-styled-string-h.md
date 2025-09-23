# styled_string.h
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hddgzw-->
<!--Designer: @pssea-->
<!--Tester: @jiaoaozihao-->
<!--Adviser: @HelloCrease-->

## Overview

Defines text styles for the ArkUI text component on the native side.

**File to include**: <arkui/styled_string.h>

**Library**: libace_ndk.z.so

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Since**: 12

**Related module**: [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**Example**: <!--RP1-->[StyledStringNDK](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/StyledStringNDK)<!--RP1End-->

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [ArkUI_StyledString](capi-arkui-nativemodule-arkui-styledstring.md) | ArkUI_StyledString | Defines a styled string object supported by the text component.|

### Functions

| Name| Description|
| -- | -- |
| [ArkUI_StyledString* OH_ArkUI_StyledString_Create(OH_Drawing_TypographyStyle* style, OH_Drawing_FontCollection* collection)](#oh_arkui_styledstring_create) | Creates an **ArkUI_StyledString** object and returns its pointer.|
| [void OH_ArkUI_StyledString_Destroy(ArkUI_StyledString* handle)](#oh_arkui_styledstring_destroy) | Destroys an **ArkUI_StyledString** object and reclaims the memory occupied by the object.|
| [void OH_ArkUI_StyledString_PushTextStyle(ArkUI_StyledString* handle, OH_Drawing_TextStyle* style)](#oh_arkui_styledstring_pushtextstyle) | Pushes a text style to the top of the style stack of a styled string.|
| [void OH_ArkUI_StyledString_AddText(ArkUI_StyledString* handle, const char* content)](#oh_arkui_styledstring_addtext) | Adds text for a styled string.|
| [void OH_ArkUI_StyledString_PopTextStyle(ArkUI_StyledString* handle)](#oh_arkui_styledstring_poptextstyle) | Pops the style at the top of the style stack of a styled string.|
| [OH_Drawing_Typography* OH_ArkUI_StyledString_CreateTypography(ArkUI_StyledString* handle)](#oh_arkui_styledstring_createtypography) | Creates an **OH_Drawing_Typography** object based on an **ArkUI_StyledString** object.|
| [void OH_ArkUI_StyledString_AddPlaceholder(ArkUI_StyledString* handle, OH_Drawing_PlaceholderSpan* placeholder)](#oh_arkui_styledstring_addplaceholder) | Adds a placeholder.|
| [ArkUI_StyledString_Descriptor* OH_ArkUI_StyledString_Descriptor_Create(void)](#oh_arkui_styledstring_descriptor_create) | Creates an **ArkUI_StyledString_Descriptor** object.|
| [void OH_ArkUI_StyledString_Descriptor_Destroy(ArkUI_StyledString_Descriptor* descriptor)](#oh_arkui_styledstring_descriptor_destroy) | Destroys an **ArkUI_StyledString_Descriptor** object and reclaims the memory occupied by the object.|
| [int32_t OH_ArkUI_UnmarshallStyledStringDescriptor(uint8_t* buffer, size_t bufferSize, ArkUI_StyledString_Descriptor* descriptor)](#oh_arkui_unmarshallstyledstringdescriptor) | Unmarshals a byte array containing styled string information into a styled string.|
| [int32_t OH_ArkUI_MarshallStyledStringDescriptor(uint8_t* buffer, size_t bufferSize, ArkUI_StyledString_Descriptor* descriptor, size_t* resultSize)](#oh_arkui_marshallstyledstringdescriptor) | Marshals the styled string information into a byte array.|
| [const char* OH_ArkUI_ConvertToHtml(ArkUI_StyledString_Descriptor* descriptor)](#oh_arkui_converttohtml) | Converts styled string information into HTML.|

## Function Description

### OH_ArkUI_StyledString_Create()

```
ArkUI_StyledString* OH_ArkUI_StyledString_Create(OH_Drawing_TypographyStyle* style, OH_Drawing_FontCollection* collection)
```

**Description**

Creates an **ArkUI_StyledString** object and returns its pointer.

**Since**: 12

**Parameters**

| Name| Description                                                                                                                                                              |
| -- |------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| [OH_Drawing_TypographyStyle](../apis-arkgraphics2d/capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to an **OH_Drawing_TypographyStyle** object, obtained using [OH_Drawing_CreateTypographyStyle](../apis-arkgraphics2d/capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|
| [OH_Drawing_FontCollection](../apis-arkgraphics2d/capi-drawing-oh-drawing-fontcollection.md)* collection | Pointer to an **OH_Drawing_FontCollection** object, obtained using [OH_Drawing_CreateFontCollection](../apis-arkgraphics2d/capi-drawing-font-collection-h.md).                                                                                   |

**Return value**

| Type                     | Description|
|-------------------------| -- |
| [ArkUI_StyledString](capi-arkui-nativemodule-arkui-styledstring.md)* | Pointer to the newly created **ArkUI_StyledString** object. If a null pointer is returned, the creation fails. Possible causes include a full application address space or parameter errors, such as a null pointer being passed for the **style** or **collection** parameter.|

### OH_ArkUI_StyledString_Destroy()

```
void OH_ArkUI_StyledString_Destroy(ArkUI_StyledString* handle)
```

**Description**

Destroys an **ArkUI_StyledString** object and reclaims the memory occupied by the object.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_StyledString](capi-arkui-nativemodule-arkui-styledstring.md)* handle | Pointer to an **ArkUI_StyledString** object.|

### OH_ArkUI_StyledString_PushTextStyle()

```
void OH_ArkUI_StyledString_PushTextStyle(ArkUI_StyledString* handle, OH_Drawing_TextStyle* style)
```

**Description**

Pushes a text style to the top of the style stack of a styled string.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_StyledString](capi-arkui-nativemodule-arkui-styledstring.md)* handle | Pointer to an **ArkUI_StyledString** object.|
| [OH_Drawing_TextStyle](../apis-arkgraphics2d/capi-drawing-oh-drawing-textstyle.md)* style | Pointer to an **OH_Drawing_TextStyle** object.|

### OH_ArkUI_StyledString_AddText()

```
void OH_ArkUI_StyledString_AddText(ArkUI_StyledString* handle, const char* content)
```

**Description**

Adds text for a styled string.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_StyledString](capi-arkui-nativemodule-arkui-styledstring.md)* handle | Pointer to an **ArkUI_StyledString** object.|
| const char* content | Pointer to the text content.|

### OH_ArkUI_StyledString_PopTextStyle()

```
void OH_ArkUI_StyledString_PopTextStyle(ArkUI_StyledString* handle)
```

**Description**

Pops the style at the top of the style stack of a styled string.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_StyledString](capi-arkui-nativemodule-arkui-styledstring.md)* handle | Pointer to an **ArkUI_StyledString** object.|

### OH_ArkUI_StyledString_CreateTypography()

```
OH_Drawing_Typography* OH_ArkUI_StyledString_CreateTypography(ArkUI_StyledString* handle)
```

**Description**

Creates an **OH_Drawing_Typography** object based on an **ArkUI_StyledString** object.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_StyledString](capi-arkui-nativemodule-arkui-styledstring.md)* handle | Pointer to an **ArkUI_StyledString** object.|

**Return value**

| Type                        | Description|
|----------------------------| -- |
| [OH_Drawing_Typography](../apis-arkgraphics2d/capi-drawing-oh-drawing-typography.md)* | Pointer to the **OH_Drawing_Typography** object. If a null pointer is returned, the creation fails. A possible cause is that a parameter error, for example, a null pointer for the **handle** parameter, occurs.|

### OH_ArkUI_StyledString_AddPlaceholder()

```
void OH_ArkUI_StyledString_AddPlaceholder(ArkUI_StyledString* handle, OH_Drawing_PlaceholderSpan* placeholder)
```

**Description**

Adds a placeholder.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_StyledString](capi-arkui-nativemodule-arkui-styledstring.md)* handle | Pointer to an **ArkUI_StyledString** object.|
| [OH_Drawing_PlaceholderSpan](../apis-arkgraphics2d/capi-drawing-oh-drawing-placeholderspan.md)* placeholder | Pointer to an **OH_Drawing_PlaceholderSpan** object.|

### OH_ArkUI_StyledString_Descriptor_Create()

```
ArkUI_StyledString_Descriptor* OH_ArkUI_StyledString_Descriptor_Create(void)
```

**Description**

Creates an **ArkUI_StyledString_Descriptor** object.

**Since**: 14

**Return value**

| Type                                | Description|
|------------------------------------| -- |
| [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)* | Pointer to an **ArkUI_StyledString_Descriptor** object.|

### OH_ArkUI_StyledString_Descriptor_Destroy()

```
void OH_ArkUI_StyledString_Descriptor_Destroy(ArkUI_StyledString_Descriptor* descriptor)
```

**Description**

Destroys an **ArkUI_StyledString_Descriptor** object and reclaims the memory occupied by the object.

**Since**: 14

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)* descriptor | Pointer to an **ArkUI_StyledString_Descriptor** object.|

### OH_ArkUI_UnmarshallStyledStringDescriptor()

```
int32_t OH_ArkUI_UnmarshallStyledStringDescriptor(uint8_t* buffer, size_t bufferSize, ArkUI_StyledString_Descriptor* descriptor)
```

**Description**

Unmarshals a byte array containing styled string information into a styled string.

**Since**: 14

**Parameters**

| Name| Description|
| -- | -- |
| uint8_t* buffer | Byte array to be deserialized.|
| size_t bufferSize | Length of the byte array.|
| [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)* descriptor | Pointer to an **ArkUI_StyledString_Descriptor** object.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_MarshallStyledStringDescriptor()

```
int32_t OH_ArkUI_MarshallStyledStringDescriptor(uint8_t* buffer, size_t bufferSize, ArkUI_StyledString_Descriptor* descriptor, size_t* resultSize)
```

**Description**

Marshals the styled string information into a byte array.

**Since**: 14

**Parameters**

| Name| Description|
| -- | -- |
| uint8_t* buffer | Byte array where the serialized data will be stored.|
| size_t bufferSize | Length of the byte array.|
| [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)* descriptor | Pointer to an **ArkUI_StyledString_Descriptor** object.|
| size_t* resultSize | Actual length of the resulting byte array after deserialization.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>        Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>        Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>        Returns [ARKUI_ERROR_CODE_INVALID_STYLED_STRING](capi-native-type-h.md#arkui_errorcode) if the styled string is invalid.|

### OH_ArkUI_ConvertToHtml()

```
const char* OH_ArkUI_ConvertToHtml(ArkUI_StyledString_Descriptor* descriptor)
```

**Description**

Converts styled string information into HTML.

**Since**: 14

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)* descriptor | Pointer to an **ArkUI_StyledString_Descriptor** object.|

**Return value**

| Type| Description|
| -- | -- |
| const char* | HTML object. The pointer is managed internally and should be destroyed by calling **OH_ArkUI_StyledString_Descriptor_Destroy()** when no longer needed to free the memory.|
<!--no_check-->