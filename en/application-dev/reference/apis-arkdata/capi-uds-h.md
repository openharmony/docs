# uds.h

## Overview

Defines the APIs and structs related to the uniform data structs.

**File to include**: <database/udmf/uds.h>

**Library**: libudmf.so

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Since**: 12

**Related module**: [UDMF](capi-udmf.md)

## Summary

### Structs

| Name                                          | typedef Keyword    | Description                                  |
| ---------------------------------------------- | ----------------- | -------------------------------------- |
| [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)     | OH_UdsPlainText   | Defines a struct for the unified data of the plaintext type.    |
| [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)     | OH_UdsHyperlink   | Defines a struct for the unified data of the hyperlink type.        |
| [OH_UdsHtml](capi-udmf-oh-udshtml.md)               | OH_UdsHtml        | Defines a struct for the unified data of the Hypertext Markup Language (HTML) type.|
| [OH_UdsAppItem](capi-udmf-oh-udsappitem.md)         | OH_UdsAppItem     | Defines a struct for the unified data of the home screen icon type.      |
| [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)         | OH_UdsFileUri     | Defines a struct for the unified data of the file URI type.       |
| [OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md)       | OH_UdsPixelMap    | Defines a struct for the unified data of the pixel map type.      |
| [OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md) | OH_UdsArrayBuffer | Defines a struct for the unified data of the ArrayBuffer type.   |
| [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) | OH_UdsContentForm | Defines a struct for the unified data of the content card type.      |

### Functions

| Name                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_UdsPlainText* OH_UdsPlainText_Create()](#oh_udsplaintext_create) | Creates an [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md) instance and a pointer to it. If this pointer is no longer required, use [OH_UdsPlainText_Destroy](capi-uds-h.md#oh_udsplaintext_destroy) to destroy it. Otherwise, memory leaks may occur.|
| [void OH_UdsPlainText_Destroy(OH_UdsPlainText* pThis)](#oh_udsplaintext_destroy) | Destroys an [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md) instance.|
| [const char* OH_UdsPlainText_GetType(OH_UdsPlainText* pThis)](#oh_udsplaintext_gettype) | Obtains the type ID from an [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md) instance.|
| [const char* OH_UdsPlainText_GetContent(OH_UdsPlainText* pThis)](#oh_udsplaintext_getcontent) | Obtains the plaintext from an [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md) instance.|
| [const char* OH_UdsPlainText_GetAbstract(OH_UdsPlainText* pThis)](#oh_udsplaintext_getabstract) | Obtains the abstract from an [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md) instance.|
| [int OH_UdsPlainText_SetContent(OH_UdsPlainText* pThis, const char* content)](#oh_udsplaintext_setcontent) | Sets the plaintext content for an [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md) instance.|
| [int OH_UdsPlainText_SetAbstract(OH_UdsPlainText* pThis, const char* abstract)](#oh_udsplaintext_setabstract) | Sets the abstract for an [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md) instance.|
| [OH_UdsHyperlink* OH_UdsHyperlink_Create()](#oh_udshyperlink_create) | Creates an [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md) instance and a pointer to it. If this pointer is no longer required, use [OH_UdsHyperlink_Destroy](capi-uds-h.md#oh_udshyperlink_destroy) to destroy it. Otherwise, memory leaks may occur.|
| [void OH_UdsHyperlink_Destroy(OH_UdsHyperlink* pThis)](#oh_udshyperlink_destroy) | Destroys an [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md) instance.|
| [const char* OH_UdsHyperlink_GetType(OH_UdsHyperlink* pThis)](#oh_udshyperlink_gettype) | Obtains the type ID from an [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md) instance.|
| [const char* OH_UdsHyperlink_GetUrl(OH_UdsHyperlink* pThis)](#oh_udshyperlink_geturl) | Obtains the URL from an [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md) instance.|
| [const char* OH_UdsHyperlink_GetDescription(OH_UdsHyperlink* pThis)](#oh_udshyperlink_getdescription) | Obtains the description from an [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md) instance.|
| [int OH_UdsHyperlink_SetUrl(OH_UdsHyperlink* pThis, const char* url)](#oh_udshyperlink_seturl) | Sets the URL for an [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md) instance.|
| [int OH_UdsHyperlink_SetDescription(OH_UdsHyperlink* pThis, const char* description)](#oh_udshyperlink_setdescription) | Sets the description for an [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md) instance.|
| [OH_UdsHtml* OH_UdsHtml_Create()](#oh_udshtml_create)        | Creates an [OH_UdsHtml](capi-udmf-oh-udshtml.md) instance and a pointer to it. If this pointer is no longer required, use [OH_UdsHtml_Destroy](capi-uds-h.md#oh_udshtml_destroy) to destroy it. Otherwise, memory leaks may occur.|
| [void OH_UdsHtml_Destroy(OH_UdsHtml* pThis)](#oh_udshtml_destroy) | Destroys an [OH_UdsHtml](capi-udmf-oh-udshtml.md) instance.|
| [const char* OH_UdsHtml_GetType(OH_UdsHtml* pThis)](#oh_udshtml_gettype) | Obtains the type ID from an [OH_UdsHtml](capi-udmf-oh-udshtml.md) instance.|
| [const char* OH_UdsHtml_GetContent(OH_UdsHtml* pThis)](#oh_udshtml_getcontent) | Obtains the HTML content from an [OH_UdsHtml](capi-udmf-oh-udshtml.md) instance.|
| [const char* OH_UdsHtml_GetPlainContent(OH_UdsHtml* pThis)](#oh_udshtml_getplaincontent) | Obtains the plaintext content from an [OH_UdsHtml](capi-udmf-oh-udshtml.md) instance.|
| [int OH_UdsHtml_SetContent(OH_UdsHtml* pThis, const char* content)](#oh_udshtml_setcontent) | Sets the HTML content for an [OH_UdsHtml](capi-udmf-oh-udshtml.md) instance.|
| [int OH_UdsHtml_SetPlainContent(OH_UdsHtml* pThis, const char* plainContent)](#oh_udshtml_setplaincontent) | Sets the plaintext content for an [OH_UdsHtml](capi-udmf-oh-udshtml.md) instance.|
| [OH_UdsAppItem* OH_UdsAppItem_Create()](#oh_udsappitem_create) | Creates an [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance and a pointer to it. If this pointer is no longer required, use [OH_UdsAppItem_Destroy](capi-uds-h.md#oh_udsappitem_destroy) to destroy it. Otherwise, memory leaks may occur.|
| [void OH_UdsAppItem_Destroy(OH_UdsAppItem* pThis)](#oh_udsappitem_destroy) | Destroys an [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance.|
| [const char* OH_UdsAppItem_GetType(OH_UdsAppItem* pThis)](#oh_udsappitem_gettype) | Obtains the type ID from an [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance.|
| [const char* OH_UdsAppItem_GetId(OH_UdsAppItem* pThis)](#oh_udsappitem_getid) | Obtains the application ID from an [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance.|
| [const char* OH_UdsAppItem_GetName(OH_UdsAppItem* pThis)](#oh_udsappitem_getname) | Obtains the application name from an [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance.|
| [const char* OH_UdsAppItem_GetIconId(OH_UdsAppItem* pThis)](#oh_udsappitem_geticonid) | Obtains the image ID from an [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance.|
| [const char* OH_UdsAppItem_GetLabelId(OH_UdsAppItem* pThis)](#oh_udsappitem_getlabelid) | Obtains the label ID from an [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance.|
| [const char* OH_UdsAppItem_GetBundleName(OH_UdsAppItem* pThis)](#oh_udsappitem_getbundlename) | Obtains the bundle name from an [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance.|
| [const char* OH_UdsAppItem_GetAbilityName(OH_UdsAppItem* pThis)](#oh_udsappitem_getabilityname) | Obtains the ability name from an [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance.|
| [int OH_UdsAppItem_SetId(OH_UdsAppItem* pThis, const char* appId)](#oh_udsappitem_setid) | Sets the application ID for an [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance.|
| [int OH_UdsAppItem_SetName(OH_UdsAppItem* pThis, const char* appName)](#oh_udsappitem_setname) | Sets the application name for an [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance.|
| [int OH_UdsAppItem_SetIconId(OH_UdsAppItem* pThis, const char* appIconId)](#oh_udsappitem_seticonid) | Sets the image ID for an [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance.|
| [int OH_UdsAppItem_SetLabelId(OH_UdsAppItem* pThis, const char* appLabelId)](#oh_udsappitem_setlabelid) | Sets the label ID for an [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance.|
| [int OH_UdsAppItem_SetBundleName(OH_UdsAppItem* pThis, const char* bundleName)](#oh_udsappitem_setbundlename) | Sets the bundle name for an [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance.|
| [int OH_UdsAppItem_SetAbilityName(OH_UdsAppItem* pThis, const char* abilityName)](#oh_udsappitem_setabilityname) | Sets the ability name for an [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance.|
| [OH_UdsFileUri* OH_UdsFileUri_Create()](#oh_udsfileuri_create) | Creates an [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md) instance and a pointer to it. If this pointer is no longer required, use [OH_UdsFileUri_Destroy](capi-uds-h.md#oh_udsfileuri_destroy) to destroy it. Otherwise, memory leaks may occur.|
| [void OH_UdsFileUri_Destroy(OH_UdsFileUri* pThis)](#oh_udsfileuri_destroy) | Destroys an [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md) instance.|
| [const char* OH_UdsFileUri_GetType(OH_UdsFileUri* pThis)](#oh_udsfileuri_gettype) | Obtains the type ID from an [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md) instance.|
| [const char* OH_UdsFileUri_GetFileUri(OH_UdsFileUri* pThis)](#oh_udsfileuri_getfileuri) | Obtains the file URI from an [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md) instance.|
| [const char* OH_UdsFileUri_GetFileType(OH_UdsFileUri* pThis)](#oh_udsfileuri_getfiletype) | Obtains the file type from an [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md) instance.|
| [int OH_UdsFileUri_SetFileUri(OH_UdsFileUri* pThis, const char* fileUri)](#oh_udsfileuri_setfileuri) | Sets the URI information for an [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md) instance.|
| [int OH_UdsFileUri_SetFileType(OH_UdsFileUri* pThis, const char* fileType)](#oh_udsfileuri_setfiletype) | Sets the file type for an [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md) instance.|
| [OH_UdsPixelMap* OH_UdsPixelMap_Create()](#oh_udspixelmap_create) | Creates an [OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md) instance and a pointer to it. If this pointer is no longer required, use [OH_UdsPixelMap_Destroy](capi-uds-h.md#oh_udspixelmap_destroy) to destroy it. Otherwise, memory leaks may occur.|
| [void OH_UdsPixelMap_Destroy(OH_UdsPixelMap* pThis)](#oh_udspixelmap_destroy) | Destroys an [OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md) instance.|
| [const char* OH_UdsPixelMap_GetType(OH_UdsPixelMap* pThis)](#oh_udspixelmap_gettype) | Obtains the type ID from an [OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md) instance.|
| [void OH_UdsPixelMap_GetPixelMap(OH_UdsPixelMap* pThis, OH_PixelmapNative* pixelmapNative)](#oh_udspixelmap_getpixelmap) | Obtains the pointer to the [OH_PixelmapNative](../apis-image-kit/capi-pixelmap-native-h.md#oh_pixelmapnative_antialiasinglevel) instance from an [OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md) instance.|
| [int OH_UdsPixelMap_SetPixelMap(OH_UdsPixelMap* pThis, OH_PixelmapNative* pixelmapNative)](#oh_udspixelmap_setpixelmap) | Sets the pixel image content for an [OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md) instance.|
| [OH_UdsArrayBuffer* OH_UdsArrayBuffer_Create()](#oh_udsarraybuffer_create) | Creates an [OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md) instance and a pointer to it. If this pointer is no longer required, use [OH_UdsArrayBuffer_Destroy](capi-uds-h.md#oh_udsarraybuffer_destroy) to destroy it. Otherwise, memory leaks may occur.|
| [int OH_UdsArrayBuffer_Destroy(OH_UdsArrayBuffer* buffer)](#oh_udsarraybuffer_destroy) | Destroys an [OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md) instance.|
| [int OH_UdsArrayBuffer_SetData(OH_UdsArrayBuffer* buffer, unsigned char* data, unsigned int len)](#oh_udsarraybuffer_setdata) | Sets the data content for an [OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md) instance.|
| [int OH_UdsArrayBuffer_GetData(OH_UdsArrayBuffer* buffer, unsigned char** data, unsigned int* len)](#oh_udsarraybuffer_getdata) | Obtains the custom ArrayBuffer data from an [OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md) instance.|
| [OH_UdsContentForm* OH_UdsContentForm_Create()](#oh_udscontentform_create) | Creates an [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance and a pointer to it.|
| [void OH_UdsContentForm_Destroy(OH_UdsContentForm* pThis)](#oh_udscontentform_destroy) | Destroys an [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance.|
| [const char* OH_UdsContentForm_GetType(OH_UdsContentForm* pThis)](#oh_udscontentform_gettype) | Obtains the type ID from an [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance.|
| [int OH_UdsContentForm_GetThumbData(OH_UdsContentForm* pThis, unsigned char** thumbData, unsigned int* len)](#oh_udscontentform_getthumbdata) | Obtains the image data from an [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance.|
| [const char* OH_UdsContentForm_GetDescription(OH_UdsContentForm* pThis)](#oh_udscontentform_getdescription) | Obtains the description from an [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance.|
| [const char* OH_UdsContentForm_GetTitle(OH_UdsContentForm* pThis)](#oh_udscontentform_gettitle) | Obtains the title from an [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance.|
| [int OH_UdsContentForm_GetAppIcon(OH_UdsContentForm* pThis, unsigned char** appIcon, unsigned int* len)](#oh_udscontentform_getappicon) | Obtains the application icon data from an [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance.|
| [const char* OH_UdsContentForm_GetAppName(OH_UdsContentForm* pThis)](#oh_udscontentform_getappname) | Obtains the application name from an [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance.|
| [const char* OH_UdsContentForm_GetLinkUri(OH_UdsContentForm* pThis)](#oh_udscontentform_getlinkuri) | Obtains the hyperlink from an [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance.|
| [int OH_UdsContentForm_SetThumbData(OH_UdsContentForm* pThis, const unsigned char* thumbData, unsigned int len)](#oh_udscontentform_setthumbdata) | Sets the image data for an [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance.|
| [int OH_UdsContentForm_SetDescription(OH_UdsContentForm* pThis, const char* description)](#oh_udscontentform_setdescription) | Sets the description for an [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance.|
| [int OH_UdsContentForm_SetTitle(OH_UdsContentForm* pThis, const char* title)](#oh_udscontentform_settitle) | Sets the title for an [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance.|
| [int OH_UdsContentForm_SetAppIcon(OH_UdsContentForm* pThis, const unsigned char* appIcon, unsigned int len)](#oh_udscontentform_setappicon) | Sets the application icon data for an [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance.|
| [int OH_UdsContentForm_SetAppName(OH_UdsContentForm* pThis, const char* appName)](#oh_udscontentform_setappname) | Sets the application name for an [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance.|
| [int OH_UdsContentForm_SetLinkUri(OH_UdsContentForm* pThis, const char* linkUri)](#oh_udscontentform_setlinkuri) | Sets the hyperlink for an [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance.|

## Function Description

### OH_UdsPlainText_Create()

```
OH_UdsPlainText* OH_UdsPlainText_Create()
```

**Description**

Creates an [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md) instance and a pointer to it. If this pointer is no longer required, use [OH_UdsPlainText_Destroy](capi-uds-h.md#oh_udsplaintext_destroy) to destroy it. Otherwise, memory leaks may occur.

**Since**: 12

**Returns**

| Type                                       | Description                                                        |
| ------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)* | Returns a pointer to the [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md) instance created if the operation is successful; returns **nullptr** otherwise.|

### OH_UdsPlainText_Destroy()

```
void OH_UdsPlainText_Destroy(OH_UdsPlainText* pThis)
```

**Description**

Destroys an [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md) instance.

**Since**: 12


**Parameters**

| Name                                           | Description                                                        |
| ------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)* pThis | Pointer to the [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md) instance.|

### OH_UdsPlainText_GetType()

```
const char* OH_UdsPlainText_GetType(OH_UdsPlainText* pThis)
```

**Description**

Obtains the type ID from an [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md) instance.

**Since**: 12


**Parameters**

| Name                                           | Description                                                        |
| ------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)* pThis | Pointer to the [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md) instance.|

**Returns**

| Type       | Description                                                   |
| ----------- | ------------------------------------------------------- |
| const char* | Returns a pointer to the type ID obtained if the operation is successful; returns **nullptr** otherwise.|

### OH_UdsPlainText_GetContent()

```
const char* OH_UdsPlainText_GetContent(OH_UdsPlainText* pThis)
```

**Description**

Obtains the plaintext from an [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md) instance.

**Since**: 12


**Parameters**

| Name                                           | Description                                                        |
| ------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)* pThis | Pointer to the [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md) instance.|

**Returns**

| Type       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| const char* | Returns a pointer to the plaintext obtained if the operation is successful; returns **nullptr** otherwise.|

### OH_UdsPlainText_GetAbstract()

```
const char* OH_UdsPlainText_GetAbstract(OH_UdsPlainText* pThis)
```

**Description**

Obtains the abstract from an [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md) instance.

**Since**: 12


**Parameters**

| Name                                           | Description                                                        |
| ------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)* pThis | Pointer to the [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md) instance.|

**Returns**

| Type       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| const char* | Returns a pointer to the abstract obtained if the operation is successful; returns **nullptr** otherwise.|

OH_UdsPlainText

### OH_UdsPlainText_SetContent()

```
int OH_UdsPlainText_SetContent(OH_UdsPlainText* pThis, const char* content)
```

**Description**

Sets the plaintext content for an [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md) instance.

**Since**: 12


**Parameters**

| Name                                           | Description                                                        |
| ------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)* pThis | Pointer to the [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md) instance.|
| const char* content                               | Pointer to the plain text content to set.                                        |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Error codes. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdsPlainText_SetAbstract()

```
int OH_UdsPlainText_SetAbstract(OH_UdsPlainText* pThis, const char* abstract)
```

**Description**

Sets the abstract for an [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md) instance.

**Since**: 12


**Parameters**

| Name                                           | Description                                                        |
| ------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)* pThis | Pointer to the [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md) instance.|
| const char* abstract                              | Pointer to the abstract to set.                                        |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Error codes. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdsHyperlink_Create()

```
OH_UdsHyperlink* OH_UdsHyperlink_Create()
```

**Description**

Creates an [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md) instance and a pointer to it. If this pointer is no longer required, use [OH_UdsHyperlink_Destroy](capi-uds-h.md#oh_udshyperlink_destroy) to destroy it. Otherwise, memory leaks may occur.

**Since**: 12

**Returns**

| Type            | Description                                                        |
| ---------------- | ------------------------------------------------------------ |
| OH_UdsHyperlink* | Returns a pointer to the [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md) instance created if the operation is successful; returns **nullptr** otherwise.|

### OH_UdsHyperlink_Destroy()

```
void OH_UdsHyperlink_Destroy(OH_UdsHyperlink* pThis)
```

**Description**

Destroys an [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md) instance.

**Since**: 12


**Parameters**

| Name                                           | Description                                                        |
| ------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)* pThis | Pointer to the [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md) instance.|

### OH_UdsHyperlink_GetType()

```
const char* OH_UdsHyperlink_GetType(OH_UdsHyperlink* pThis)
```

**Description**

Obtains the type ID from an [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md) instance.

**Since**: 12


**Parameters**

| Name                                           | Description                                                        |
| ------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)* pThis | Pointer to the [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md) instance.|

**Returns**

| Type       | Description                                                   |
| ----------- | ------------------------------------------------------- |
| const char* | Returns a pointer to the type ID obtained if the operation is successful; returns **nullptr** otherwise.|

### OH_UdsHyperlink_GetUrl()

```
const char* OH_UdsHyperlink_GetUrl(OH_UdsHyperlink* pThis)
```

**Description**

Obtains the URL from an [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md) instance.

**Since**: 12


**Parameters**

| Name                                           | Description                                                        |
| ------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)* pThis | Pointer to the [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md) instance.|

**Returns**

| Type       | Description                                                    |
| ----------- | -------------------------------------------------------- |
| const char* | Returns a pointer to the URL obtained if the operation is successful; returns **nullptr** otherwise.|

### OH_UdsHyperlink_GetDescription()

```
const char* OH_UdsHyperlink_GetDescription(OH_UdsHyperlink* pThis)
```

**Description**

Obtains the description from an [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md) instance.

**Since**: 12


**Parameters**

| Name                                           | Description                                                        |
| ------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)* pThis | Pointer to the [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md) instance.|

**Returns**

| Type       | Description                                                     |
| ----------- | --------------------------------------------------------- |
| const char* | Returns a pointer to the description obtained if the operation is successful; returns **nullptr** otherwise.|

### OH_UdsHyperlink_SetUrl()

```
int OH_UdsHyperlink_SetUrl(OH_UdsHyperlink* pThis, const char* url)
```

**Description**

Sets the URL for an [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md) instance.

**Since**: 12


**Parameters**

| Name                                           | Description                                                        |
| ------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)* pThis | Pointer to the [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md) instance.|
| const char* url                                   | Pointer to the URL to set.                                               |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Error codes. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdsHyperlink_SetDescription()

```
int OH_UdsHyperlink_SetDescription(OH_UdsHyperlink* pThis, const char* description)
```

**Description**

Sets the description for an [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md) instance.

**Since**: 12


**Parameters**

| Name                                           | Description                                                        |
| ------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)* pThis | Pointer to the [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md) instance.|
| const char* description                           | Pointer to the description to set.                                              |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Error codes. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdsHtml_Create()

```
OH_UdsHtml* OH_UdsHtml_Create()
```

**Description**

Creates an [OH_UdsHtml](capi-udmf-oh-udshtml.md) instance and a pointer to it. If this pointer is no longer required, use [OH_UdsHtml_Destroy](capi-uds-h.md#oh_udshtml_destroy) to destroy it. Otherwise, memory leaks may occur.

**Since**: 12

**Returns**

| Type                             | Description                                                        |
| --------------------------------- | ------------------------------------------------------------ |
| [OH_UdsHtml](capi-udmf-oh-udshtml.md)* | Returns a pointer to the [OH_UdsHtml](capi-udmf-oh-udshtml.md) instance created if the operation is successful; returns **nullptr** otherwise.|

### OH_UdsHtml_Destroy()

```
void OH_UdsHtml_Destroy(OH_UdsHtml* pThis)
```

**Description**

Destroys an [OH_UdsHtml](capi-udmf-oh-udshtml.md) instance.

**Since**: 12


**Parameters**

| Name                                 | Description                                                        |
| --------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsHtml](capi-udmf-oh-udshtml.md)* pThis | Pointer to the [OH_UdsHtml](capi-udmf-oh-udshtml.md) instance.|

### OH_UdsHtml_GetType()

```
const char* OH_UdsHtml_GetType(OH_UdsHtml* pThis)
```

**Description**

Obtains the type ID from an [OH_UdsHtml](capi-udmf-oh-udshtml.md) instance.

**Since**: 12


**Parameters**

| Name                                 | Description                                                        |
| --------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsHtml](capi-udmf-oh-udshtml.md)* pThis | Pointer to the [OH_UdsHtml](capi-udmf-oh-udshtml.md) instance.|

**Returns**

| Type       | Description                                                   |
| ----------- | ------------------------------------------------------- |
| const char* | Returns a pointer to the type ID obtained if the operation is successful; returns **nullptr** otherwise.|

### OH_UdsHtml_GetContent()

```
const char* OH_UdsHtml_GetContent(OH_UdsHtml* pThis)
```

**Description**

Obtains the HTML content from an [OH_UdsHtml](capi-udmf-oh-udshtml.md) instance.

**Since**: 12


**Parameters**

| Name                                 | Description                                                        |
| --------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsHtml](capi-udmf-oh-udshtml.md)* pThis | Pointer to the [OH_UdsHtml](capi-udmf-oh-udshtml.md) instance.|

**Returns**

| Type       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| const char* | Returns a pointer to the HTML content obtained if the operation is successful; returns **nullptr** otherwise.|

### OH_UdsHtml_GetPlainContent()

```
const char* OH_UdsHtml_GetPlainContent(OH_UdsHtml* pThis)
```

**Description**

Obtains the plaintext content from an [OH_UdsHtml](capi-udmf-oh-udshtml.md) instance.

**Since**: 12


**Parameters**

| Name                                 | Description                                                        |
| --------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsHtml](capi-udmf-oh-udshtml.md)* pThis | Pointer to the [OH_UdsHtml](capi-udmf-oh-udshtml.md) instance.|

**Returns**

| Type       | Description                                                       |
| ----------- | ----------------------------------------------------------- |
| const char* | Returns a pointer to the plaintext obtained if the operation is successful; returns **nullptr** otherwise.|

### OH_UdsHtml_SetContent()

```
int OH_UdsHtml_SetContent(OH_UdsHtml* pThis, const char* content)
```

**Description**

Sets the HTML content for an [OH_UdsHtml](capi-udmf-oh-udshtml.md) instance.

**Since**: 12


**Parameters**

| Name                                 | Description                                                        |
| --------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsHtml](capi-udmf-oh-udshtml.md)* pThis | Pointer to the [OH_UdsHtml](capi-udmf-oh-udshtml.md) instance.|
| const char* content                     | Pointer to the content in HTML format to set.                                      |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Error codes. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdsHtml_SetPlainContent()

```
int OH_UdsHtml_SetPlainContent(OH_UdsHtml* pThis, const char* plainContent)
```

**Description**

Sets the plaintext content for an [OH_UdsHtml](capi-udmf-oh-udshtml.md) instance.

**Since**: 12


**Parameters**

| Name                                 | Description                                                        |
| --------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsHtml](capi-udmf-oh-udshtml.md)* pThis | Pointer to the [OH_UdsHtml](capi-udmf-oh-udshtml.md) instance.|
| const char* plainContent                | Pointer to the plain text content to set.                                        |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Error codes. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdsAppItem_Create()

```
OH_UdsAppItem* OH_UdsAppItem_Create()
```

**Description**

Creates an [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance and a pointer to it. If this pointer is no longer required, use [OH_UdsAppItem_Destroy](capi-uds-h.md#oh_udsappitem_destroy) to destroy it. Otherwise, memory leaks may occur.

**Since**: 12

**Returns**

| Type                                   | Description                                                        |
| --------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsAppItem](capi-udmf-oh-udsappitem.md)* | Returns a pointer to the [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance created if the operation is successful; returns **nullptr** otherwise.|

### OH_UdsAppItem_Destroy()

```
void OH_UdsAppItem_Destroy(OH_UdsAppItem* pThis)
```

**Description**

Destroys an [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance.

**Since**: 12


**Parameters**

| Name                                       | Description                                                        |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsAppItem](capi-udmf-oh-udsappitem.md)* pThis | Pointer to the [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance.|

### OH_UdsAppItem_GetType()

```
const char* OH_UdsAppItem_GetType(OH_UdsAppItem* pThis)
```

**Description**

Obtains the type ID from an [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance.

**Since**: 12


**Parameters**

| Name                                       | Description                                                        |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsAppItem](capi-udmf-oh-udsappitem.md)* pThis | Pointer to the [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance.|

**Returns**

| Type       | Description                                                   |
| ----------- | ------------------------------------------------------- |
| const char* | Returns a pointer to the type ID obtained if the operation is successful; returns **nullptr** otherwise.|

### OH_UdsAppItem_GetId()

```
const char* OH_UdsAppItem_GetId(OH_UdsAppItem* pThis)
```

**Description**

Obtains the application ID from an [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance.

**Since**: 12


**Parameters**

| Name                                       | Description                                                        |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsAppItem](capi-udmf-oh-udsappitem.md)* pThis | Pointer to the [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance.|

**Returns**

| Type       | Description                                                   |
| ----------- | ------------------------------------------------------- |
| const char* | Returns a pointer to the application ID obtained if the operation is successful; returns **nullptr** otherwise.|

### OH_UdsAppItem_GetName()

```
const char* OH_UdsAppItem_GetName(OH_UdsAppItem* pThis)
```

**Description**

Obtains the application name from an [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance.

**Since**: 12


**Parameters**

| Name                                       | Description                                                        |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsAppItem](capi-udmf-oh-udsappitem.md)* pThis | Pointer to the [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance.|

**Returns**

| Type       | Description                                                     |
| ----------- | --------------------------------------------------------- |
| const char* | Returns a pointer to the application name obtained if the operation is successful; returns **nullptr** otherwise.|

### OH_UdsAppItem_GetIconId()

```
const char* OH_UdsAppItem_GetIconId(OH_UdsAppItem* pThis)
```

**Description**

Obtains the image ID from an [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance.

**Since**: 12


**Parameters**

| Name                                       | Description                                                        |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsAppItem](capi-udmf-oh-udsappitem.md)* pThis | Pointer to the [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance.|

**Returns**

| Type       | Description                                                   |
| ----------- | ------------------------------------------------------- |
| const char* | Returns a pointer to the application icon ID obtained if the operation is successful; returns **nullptr** otherwise.|

### OH_UdsAppItem_GetLabelId()

```
const char* OH_UdsAppItem_GetLabelId(OH_UdsAppItem* pThis)
```

**Description**

Obtains the label ID from an [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance.

**Since**: 12


**Parameters**

| Name                                       | Description                                                        |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsAppItem](capi-udmf-oh-udsappitem.md)* pThis | Pointer to the [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance.|

**Returns**

| Type       | Description                                                   |
| ----------- | ------------------------------------------------------- |
| const char* | Returns a pointer to the application label ID obtained if the operation is successful; returns **nullptr** otherwise.|

### OH_UdsAppItem_GetBundleName()

```
const char* OH_UdsAppItem_GetBundleName(OH_UdsAppItem* pThis)
```

**Description**

Obtains the bundle name from an [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance.

**Since**: 12


**Parameters**

| Name                                       | Description                                                        |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsAppItem](capi-udmf-oh-udsappitem.md)* pThis | Pointer to the [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance.|

**Returns**

| Type       | Description                                                       |
| ----------- | ----------------------------------------------------------- |
| const char* | Returns a pointer to the bundle name obtained if the operation is successful; returns **nullptr** otherwise.|

### OH_UdsAppItem_GetAbilityName()

```
const char* OH_UdsAppItem_GetAbilityName(OH_UdsAppItem* pThis)
```

**Description**

Obtains the ability name from an [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance.

**Since**: 12


**Parameters**

| Name                                       | Description                                                        |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsAppItem](capi-udmf-oh-udsappitem.md)* pThis | Pointer to the [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance.|

**Returns**

| Type       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| const char* | Returns a pointer to the ability name obtained if the operation is successful; returns **nullptr** otherwise.|

### OH_UdsAppItem_SetId()

```
int OH_UdsAppItem_SetId(OH_UdsAppItem* pThis, const char* appId)
```

**Description**

Sets the application ID for an [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance.

**Since**: 12


**Parameters**

| Name                                       | Description                                                        |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsAppItem](capi-udmf-oh-udsappitem.md)* pThis | Pointer to the [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance.|
| const char* appId                             | Pointer to the application ID to set.                                                |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Error codes. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdsAppItem_SetName()

```
int OH_UdsAppItem_SetName(OH_UdsAppItem* pThis, const char* appName)
```

**Description**

Sets the application name for an [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance.

**Since**: 12


**Parameters**

| Name                                       | Description                                                        |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsAppItem](capi-udmf-oh-udsappitem.md)* pThis | Pointer to the [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance.|
| const char* appName                           | Pointer to the application name to set.                                              |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Error codes. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdsAppItem_SetIconId()

```
int OH_UdsAppItem_SetIconId(OH_UdsAppItem* pThis, const char* appIconId)
```

**Description**

Sets the icon ID for an [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance.

**Since**: 12


**Parameters**

| Name                                       | Description                                                        |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsAppItem](capi-udmf-oh-udsappitem.md)* pThis | Pointer to the [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance.|
| const char* appIconId                         | Pointer to the application icon ID to set.                                                |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Error codes. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdsAppItem_SetLabelId()

```
int OH_UdsAppItem_SetLabelId(OH_UdsAppItem* pThis, const char* appLabelId)
```

**Description**

Sets the label ID for an [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance.

**Since**: 12


**Parameters**

| Name                                       | Description                                                        |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsAppItem](capi-udmf-oh-udsappitem.md)* pThis | Pointer to the [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance.|
| const char* appLabelId                        | Pointer to the application label ID to set.                                                |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Error codes. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdsAppItem_SetBundleName()

```
int OH_UdsAppItem_SetBundleName(OH_UdsAppItem* pThis, const char* bundleName)
```

**Description**

Sets the bundle name for an [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance.

**Since**: 12


**Parameters**

| Name                                       | Description                                                        |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsAppItem](capi-udmf-oh-udsappitem.md)* pThis | Pointer to the [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance.|
| const char* bundleName                        | Pointer to the bundle name to set.                                            |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Error codes. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdsAppItem_SetAbilityName()

```
int OH_UdsAppItem_SetAbilityName(OH_UdsAppItem* pThis, const char* abilityName)
```

**Description**

Sets the ability name for an [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance.

**Since**: 12


**Parameters**

| Name                                       | Description                                                        |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsAppItem](capi-udmf-oh-udsappitem.md)* pThis | Pointer to the [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance.|
| const char* abilityName                       | Pointer to the ability name to set.                                           |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Error codes. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdsFileUri_Create()

```
OH_UdsFileUri* OH_UdsFileUri_Create()
```

**Description**

Creates an [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md) instance and a pointer to it. If this pointer is no longer required, use [OH_UdsFileUri_Destroy](capi-uds-h.md#oh_udsfileuri_destroy) to destroy it. Otherwise, memory leaks may occur.

**Since**: 13

**Returns**

| Type                                   | Description                                                        |
| --------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)* | Returns a pointer to the [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md) instance if the operation is successful; returns **nullptr** otherwise.|

### OH_UdsFileUri_Destroy()

```
void OH_UdsFileUri_Destroy(OH_UdsFileUri* pThis)
```

**Description**

Destroys an [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md) instance.

**Since**: 13


**Parameters**

| Name                                       | Description                                                        |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)* pThis | Pointer to the [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md) instance.|

### OH_UdsFileUri_GetType()

```
const char* OH_UdsFileUri_GetType(OH_UdsFileUri* pThis)
```

**Description**

Obtains the type ID from an [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md) instance.

**Since**: 13


**Parameters**

| Name                                       | Description                                                        |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)* pThis | Pointer to the [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md) instance.|

**Returns**

| Type       | Description                                                   |
| ----------- | ------------------------------------------------------- |
| const char* | Returns a pointer to the type ID obtained if the operation is successful; returns **nullptr** otherwise.|

### OH_UdsFileUri_GetFileUri()

```
const char* OH_UdsFileUri_GetFileUri(OH_UdsFileUri* pThis)
```

**Description**

Obtains the file URI from an [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md) instance.

**Since**: 13


**Parameters**

| Name                                       | Description                                                        |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)* pThis | Pointer to the [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md) instance.|

**Returns**

| Type       | Description                                                    |
| ----------- | -------------------------------------------------------- |
| const char* | Returns a pointer to the file URI obtained if the operation is successful; returns **nullptr** otherwise.|

### OH_UdsFileUri_GetFileType()

```
const char* OH_UdsFileUri_GetFileType(OH_UdsFileUri* pThis)
```

**Description**

Obtains the file type from an [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md) instance.

**Since**: 13


**Parameters**

| Name                                       | Description                                                        |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)* pThis | Pointer to the [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md) instance.|

**Returns**

| Type       | Description                                                     |
| ----------- | --------------------------------------------------------- |
| const char* | Returns a pointer to the file type obtained if the operation is successful; returns **nullptr** otherwise.|

### OH_UdsFileUri_SetFileUri()

```
int OH_UdsFileUri_SetFileUri(OH_UdsFileUri* pThis, const char* fileUri)
```

**Description**

Sets the URI information for an [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md) instance.

**Since**: 13


**Parameters**

| Name                                       | Description                                                        |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)* pThis | Pointer to the [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md) instance.|
| const char* fileUri                           | Pointer to the file URI to set.                                               |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Error codes. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdsFileUri_SetFileType()

```
int OH_UdsFileUri_SetFileType(OH_UdsFileUri* pThis, const char* fileType)
```

**Description**

Sets the file type for an [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md) instance.

**Since**: 13


**Parameters**

| Name                                       | Description                                                        |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)* pThis | Pointer to the [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md) instance.|
| const char* fileType                          | Pointer to the file type to set.                                              |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Error codes. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdsPixelMap_Create()

```
OH_UdsPixelMap* OH_UdsPixelMap_Create()
```

**Description**

Creates an [OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md) instance and a pointer to it. If this pointer is no longer required, use [OH_UdsPixelMap_Destroy](capi-uds-h.md#oh_udspixelmap_destroy) to destroy it. Otherwise, memory leaks may occur.

**Since**: 13

**Returns**

| Type                                     | Description                                                        |
| ----------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md)* | Returns a pointer to the [OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md) instance if the operation is successful; returns **nullptr** otherwise.|

### OH_UdsPixelMap_Destroy()

```
void OH_UdsPixelMap_Destroy(OH_UdsPixelMap* pThis)
```

**Description**

Destroys an [OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md) instance.

**Since**: 13


**Parameters**

| Name                                         | Description                                                        |
| ----------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md)* pThis | Pointer to the [OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md) instance.|

### OH_UdsPixelMap_GetType()

```
const char* OH_UdsPixelMap_GetType(OH_UdsPixelMap* pThis)
```

**Description**

Obtains the type ID from an [OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md) instance.

**Since**: 13


**Parameters**

| Name                                         | Description                                                        |
| ----------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md)* pThis | Pointer to the [OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md) instance.|

**Returns**

| Type       | Description                                                   |
| ----------- | ------------------------------------------------------- |
| const char* | Returns a pointer to the type ID obtained if the operation is successful; returns **nullptr** otherwise.|

### OH_UdsPixelMap_GetPixelMap()

```
void OH_UdsPixelMap_GetPixelMap(OH_UdsPixelMap* pThis, OH_PixelmapNative* pixelmapNative)
```

**Description**

Obtains the pointer to the [OH_PixelmapNative](../apis-image-kit/capi-pixelmap-native-h.md#oh_pixelmapnative_antialiasinglevel) instance from an [OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md) instance.

**Since**: 13


**Parameters**

| Name                                         | Description                                                        |
| ----------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md)* pThis | Pointer to the [OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md) instance.|
| OH_PixelmapNative* pixelmapNative               | Pointer to the [OH_PixelmapNative](../apis-image-kit/capi-pixelmap-native-h.md#oh_pixelmapnative_antialiasinglevel) instance.|

### OH_UdsPixelMap_SetPixelMap()

```
int OH_UdsPixelMap_SetPixelMap(OH_UdsPixelMap* pThis, OH_PixelmapNative* pixelmapNative)
```

**Description**

Sets the pixel image content for an [OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md) instance.

**Since**: 13


**Parameters**

| Name                                         | Description                                                        |
| ----------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md)* pThis | Pointer to the [OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md) instance.|
| OH_PixelmapNative* pixelmapNative               | Pointer to the [OH_PixelmapNative](../apis-image-kit/capi-pixelmap-native-h.md#oh_pixelmapnative_antialiasinglevel) instance.|

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Error codes. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdsArrayBuffer_Create()

```
OH_UdsArrayBuffer* OH_UdsArrayBuffer_Create()
```

**Description**

Creates an [OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md) instance and a pointer to it. If this pointer is no longer required, use [OH_UdsArrayBuffer_Destroy](capi-uds-h.md#oh_udsarraybuffer_destroy) to destroy it. Otherwise, memory leaks may occur.

**Since**: 13

**Returns**

| Type                                           | Description                                                        |
| ----------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md)* | Returns a pointer to the [OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md) instance if the operation is successful; returns **nullptr** otherwise.|

### OH_UdsArrayBuffer_Destroy()

```
int OH_UdsArrayBuffer_Destroy(OH_UdsArrayBuffer* buffer)
```

**Description**

Destroys an [OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md) instance.

**Since**: 13


**Parameters**

| Name                                                | Description                                                        |
| ------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md)* buffer | Pointer to the [OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md) instance.|

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Error codes. For details, see [OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdsArrayBuffer_SetData()

```
int OH_UdsArrayBuffer_SetData(OH_UdsArrayBuffer* buffer, unsigned char* data, unsigned int len)
```

**Description**

Sets the data content for an [OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md) instance.

**Since**: 13


**Parameters**

| Name                                                | Description                                                        |
| ------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md)* buffer | Pointer to the [OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md) instance.|
| unsigned char* data                                    | Pointer to the ArrayBuffer data to set.                           |
| unsigned int len                                       | Length of the ArrayBuffer data to set.                     |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Error codes. For details, see [OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdsArrayBuffer_GetData()

```
int OH_UdsArrayBuffer_GetData(OH_UdsArrayBuffer* buffer, unsigned char** data, unsigned int* len)
```

**Description**

Obtains the custom ArrayBuffer data from an [OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md) instance.

**Since**: 13


**Parameters**

| Name                                                | Description                                                        |
| ------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md)* buffer | Pointer to the [OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md) instance.|
| unsigned char** data                                   | Double pointer to the ArrayBuffer data obtained.         |
| unsigned int* len                                      | Pointer to the length of the ArrayBuffer data obtained.   |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Error codes. For details, see [OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdsContentForm_Create()

```
OH_UdsContentForm* OH_UdsContentForm_Create()
```

**Description**

Creates an [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance and a pointer to it.

**Since**: 14

**Returns**

| Type                                           | Description                                                        |
| ----------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsContentForm](capi-udmf-oh-udscontentform.md)* | Returns a pointer to the [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance if the operation is successful; returns **nullptr** otherwise.|

### OH_UdsContentForm_Destroy()

```
void OH_UdsContentForm_Destroy(OH_UdsContentForm* pThis)
```

**Description**

Destroys an [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance.

**Since**: 14


**Parameters**

| Name                                               | Description                                                        |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsContentForm](capi-udmf-oh-udscontentform.md)* pThis | Pointer to the [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance.|

### OH_UdsContentForm_GetType()

```
const char* OH_UdsContentForm_GetType(OH_UdsContentForm* pThis)
```

**Description**

Obtains the type ID from an [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance.

**Since**: 14


**Parameters**

| Name                                               | Description                                                        |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsContentForm](capi-udmf-oh-udscontentform.md)* pThis | Pointer to the [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance.|

**Returns**

| Type       | Description                                                   |
| ----------- | ------------------------------------------------------- |
| const char* | Returns a pointer to the type ID obtained if the operation is successful; returns **nullptr** otherwise.|

### OH_UdsContentForm_GetThumbData()

```
int OH_UdsContentForm_GetThumbData(OH_UdsContentForm* pThis, unsigned char** thumbData, unsigned int* len)
```

**Description**

Obtains the image data from an [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance.

**Since**: 14


**Parameters**

| Name                                               | Description                                                        |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsContentForm](capi-udmf-oh-udscontentform.md)* pThis | Pointer to the [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance.|
| unsigned char** thumbData                             | Double pointer to the binary image data obtained.          |
| unsigned int* len                                     | Pointer to the length of the binary image data obtained.    |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Error codes. For details, see [OH_UdsContentForm](capi-udmf-oh-udscontentform.md).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.<br>Returns **UDMF_ERR** if an internal system error occurs.|

### OH_UdsContentForm_GetDescription()

```
const char* OH_UdsContentForm_GetDescription(OH_UdsContentForm* pThis)
```

**Description**

Obtains the description from an [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance.

**Since**: 14


**Parameters**

| Name                                               | Description                                                        |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsContentForm](capi-udmf-oh-udscontentform.md)* pThis | Pointer to the [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance.|

**Returns**

| Type       | Description                                                     |
| ----------- | --------------------------------------------------------- |
| const char* | Returns a pointer to the description string obtained if the operation is successful; returns **nullptr** otherwise.|

### OH_UdsContentForm_GetTitle()

```
const char* OH_UdsContentForm_GetTitle(OH_UdsContentForm* pThis)
```

**Description**

Obtains the title from an [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance.

**Since**: 14


**Parameters**

| Name                                               | Description                                                        |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsContentForm](capi-udmf-oh-udscontentform.md)* pThis | Pointer to the [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance.|

**Returns**

| Type       | Description                                                     |
| ----------- | --------------------------------------------------------- |
| const char* | Returns a pointer to the title string obtained if the operation is successful; returns **nullptr** otherwise.|

### OH_UdsContentForm_GetAppIcon()

```
int OH_UdsContentForm_GetAppIcon(OH_UdsContentForm* pThis, unsigned char** appIcon, unsigned int* len)
```

**Description**

Obtains the application icon data from an [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance.

**Since**: 14


**Parameters**

| Name                                               | Description                                                        |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsContentForm](capi-udmf-oh-udscontentform.md)* pThis | Pointer to the [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance.|
| unsigned char** appIcon                               | Double pointer to the binary application icon data obtained.      |
| unsigned int* len                                     | Pointer to the length of the binary application icon data obtained.|

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Error codes. For details, see [OH_UdsContentForm](capi-udmf-oh-udscontentform.md).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.<br>Returns **UDMF_ERR** if an internal system error occurs.|

### OH_UdsContentForm_GetAppName()

```
const char* OH_UdsContentForm_GetAppName(OH_UdsContentForm* pThis)
```

**Description**

Obtains the application name from an [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance.

**Since**: 14


**Parameters**

| Name                                               | Description                                                        |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsContentForm](capi-udmf-oh-udscontentform.md)* pThis | Pointer to the [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance.|

**Returns**

| Type       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| const char* | Returns a pointer to the application name obtained if the operation is successful; returns **nullptr** otherwise.|

### OH_UdsContentForm_GetLinkUri()

```
const char* OH_UdsContentForm_GetLinkUri(OH_UdsContentForm* pThis)
```

**Description**

Obtains the hyperlink from an [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance.

**Since**: 14


**Parameters**

| Name                                               | Description                                                        |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsContentForm](capi-udmf-oh-udscontentform.md)* pThis | Pointer to the [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance.|

**Returns**

| Type       | Description                                                   |
| ----------- | ------------------------------------------------------- |
| const char* | Returns a pointer to the hyperlink obtained if the operation is successful; returns **nullptr** otherwise.|

### OH_UdsContentForm_SetThumbData()

```
int OH_UdsContentForm_SetThumbData(OH_UdsContentForm* pThis, const unsigned char* thumbData, unsigned int len)
```

**Description**

Sets the image data for an [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance.

**Since**: 14


**Parameters**

| Name                                               | Description                                                        |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsContentForm](capi-udmf-oh-udscontentform.md)* pThis | Pointer to the [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance.|
| const unsigned char* thumbData                        | Pointer to the binary image data to set.                            |
| unsigned int len                                      | Length of the binary image data to set.                      |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Error codes. For details, see [OH_UdsContentForm](capi-udmf-oh-udscontentform.md).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdsContentForm_SetDescription()

```
int OH_UdsContentForm_SetDescription(OH_UdsContentForm* pThis, const char* description)
```

**Description**

Sets the description for an [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance.

**Since**: 14


**Parameters**

| Name                                               | Description                                                        |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsContentForm](capi-udmf-oh-udscontentform.md)* pThis | Pointer to the [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance.|
| const char* description                               | Pointer to the description to set.                                              |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Error codes. For details, see [OH_UdsContentForm](capi-udmf-oh-udscontentform.md).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdsContentForm_SetTitle()

```
int OH_UdsContentForm_SetTitle(OH_UdsContentForm* pThis, const char* title)
```

**Description**

Sets the title for an [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance.

**Since**: 14


**Parameters**

| Name                                               | Description                                                        |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsContentForm](capi-udmf-oh-udscontentform.md)* pThis | Pointer to the [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance.|
| const char* title                                     | Pointer to the title to set.                                              |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Error codes. For details, see [OH_UdsContentForm](capi-udmf-oh-udscontentform.md).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdsContentForm_SetAppIcon()

```
int OH_UdsContentForm_SetAppIcon(OH_UdsContentForm* pThis, const unsigned char* appIcon, unsigned int len)
```

**Description**

Sets the application icon data for an [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance.

**Since**: 14


**Parameters**

| Name                                               | Description                                                        |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsContentForm](capi-udmf-oh-udscontentform.md)* pThis | Pointer to the [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance.|
| const unsigned char* appIcon                          | Pointer to the binary application icon data to set.                        |
| unsigned int len                                      | Length of the binary application icon data to set.                  |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Error codes. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdsContentForm_SetAppName()

```
int OH_UdsContentForm_SetAppName(OH_UdsContentForm* pThis, const char* appName)
```

**Description**

Sets the application name for an [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance.

**Since**: 14


**Parameters**

| Name                                               | Description                                                        |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsContentForm](capi-udmf-oh-udscontentform.md)* pThis | Pointer to the [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance.|
| const char* appName                                   | Pointer to the application name to set.                                  |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Error codes. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdsContentForm_SetLinkUri()

```
int OH_UdsContentForm_SetLinkUri(OH_UdsContentForm* pThis, const char* linkUri)
```

**Description**

Sets the hyperlink for an [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance.

**Since**: 14


**Parameters**

| Name                                               | Description                                                        |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsContentForm](capi-udmf-oh-udscontentform.md)* pThis | Pointer to the [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance.|
| const char* linkUri                                   | Pointer to the hyperlink to set.                                    |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Error codes. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|
