# uds.h
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @jcwen-->
<!--Designer: @junathuawei1; @zph000-->
<!--Tester: @lj_liujing; @yippo; @logic42-->
<!--Adviser: @ge-yafang-->

## 概述

提供标准化数据结构相关接口函数、结构体定义。

**引用文件：** <database/udmf/uds.h>

**库：** libudmf.so

**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core

**起始版本：** 12

**相关模块：** [UDMF](capi-udmf.md)

## 汇总

### 结构体

| 名称                                           | typedef关键字     | 描述                                   |
| ---------------------------------------------- | ----------------- | -------------------------------------- |
| [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)     | OH_UdsPlainText   | 描述纯文本类型数据的统一数据结构。     |
| [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)     | OH_UdsHyperlink   | 描述超链接类型的统一数据结构。         |
| [OH_UdsHtml](capi-udmf-oh-udshtml.md)               | OH_UdsHtml        | 描述超文本标记语言类型的统一数据结构。 |
| [OH_UdsAppItem](capi-udmf-oh-udsappitem.md)         | OH_UdsAppItem     | 描述桌面图标类型的统一数据结构。       |
| [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)         | OH_UdsFileUri     | 描述文件Uri类型的统一数据结构。        |
| [OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md)       | OH_UdsPixelMap    | 描述像素图片类型的统一数据结构。       |
| [OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md) | OH_UdsArrayBuffer | 描述ArrayBuffer类型的统一数据结构。    |
| [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) | OH_UdsContentForm | 描述内容卡片类型的统一数据结构。       |

### 函数

| 名称                                                         | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_UdsPlainText* OH_UdsPlainText_Create()](#oh_udsplaintext_create) | 创建纯文本类型[OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)指针及实例对象。当不再需要使用指针时，请使用[OH_UdsPlainText_Destroy](capi-uds-h.md#oh_udsplaintext_destroy)销毁实例对象，否则会导致内存泄漏。 |
| [void OH_UdsPlainText_Destroy(OH_UdsPlainText* pThis)](#oh_udsplaintext_destroy) | 销毁纯文本类型数据[OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)指针指向的实例对象。 |
| [const char* OH_UdsPlainText_GetType(OH_UdsPlainText* pThis)](#oh_udsplaintext_gettype) | 从纯文本类型[OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)中获取类型ID。 |
| [const char* OH_UdsPlainText_GetContent(OH_UdsPlainText* pThis)](#oh_udsplaintext_getcontent) | 从纯文本类型[OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)中获取纯文本内容信息。 |
| [const char* OH_UdsPlainText_GetAbstract(OH_UdsPlainText* pThis)](#oh_udsplaintext_getabstract) | 从纯文本类型[OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)中获取纯文本摘要信息。 |
| [int OH_UdsPlainText_SetContent(OH_UdsPlainText* pThis, const char* content)](#oh_udsplaintext_setcontent) | 设置纯文本类型[OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)中的纯文本内容参数。 |
| [int OH_UdsPlainText_SetAbstract(OH_UdsPlainText* pThis, const char* abstract)](#oh_udsplaintext_setabstract) | 设置纯文本类型[OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)中的纯文本摘要参数。 |
| [OH_UdsHyperlink* OH_UdsHyperlink_Create()](#oh_udshyperlink_create) | 创建超链接类型[OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)指针及实例对象。当不再需要使用指针时，请使用[OH_UdsHyperlink_Destroy](capi-uds-h.md#oh_udshyperlink_destroy)销毁实例对象，否则会导致内存泄漏。 |
| [void OH_UdsHyperlink_Destroy(OH_UdsHyperlink* pThis)](#oh_udshyperlink_destroy) | 销毁超链接类型[OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)指针指向的实例对象。 |
| [const char* OH_UdsHyperlink_GetType(OH_UdsHyperlink* pThis)](#oh_udshyperlink_gettype) | 从超链接类型[OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)中获取类型ID。 |
| [const char* OH_UdsHyperlink_GetUrl(OH_UdsHyperlink* pThis)](#oh_udshyperlink_geturl) | 从超链接类型[OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)中获取URL参数。 |
| [const char* OH_UdsHyperlink_GetDescription(OH_UdsHyperlink* pThis)](#oh_udshyperlink_getdescription) | 从超链接类型[OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)中获取描述参数。 |
| [int OH_UdsHyperlink_SetUrl(OH_UdsHyperlink* pThis, const char* url)](#oh_udshyperlink_seturl) | 设置超链接类型[OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)实例中URL参数。 |
| [int OH_UdsHyperlink_SetDescription(OH_UdsHyperlink* pThis, const char* description)](#oh_udshyperlink_setdescription) | 设置超链接类型[OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)实例中描述参数。 |
| [OH_UdsHtml* OH_UdsHtml_Create()](#oh_udshtml_create)        | 创建超文本标记语言类型[OH_UdsHtml](capi-udmf-oh-udshtml.md)指针及实例对象。当不再需要使用指针时，请使用[OH_UdsHtml_Destroy](capi-uds-h.md#oh_udshtml_destroy)销毁实例对象，否则会导致内存泄漏。 |
| [void OH_UdsHtml_Destroy(OH_UdsHtml* pThis)](#oh_udshtml_destroy) | 销毁超文本标记语言类型[OH_UdsHtml](capi-udmf-oh-udshtml.md)指针指向的实例对象。 |
| [const char* OH_UdsHtml_GetType(OH_UdsHtml* pThis)](#oh_udshtml_gettype) | 获取超文本标记语言类型[OH_UdsHtml](capi-udmf-oh-udshtml.md)对象中类型ID。 |
| [const char* OH_UdsHtml_GetContent(OH_UdsHtml* pThis)](#oh_udshtml_getcontent) | 获取超文本标记语言类型[OH_UdsHtml](capi-udmf-oh-udshtml.md)对象中HTML格式内容参数。 |
| [const char* OH_UdsHtml_GetPlainContent(OH_UdsHtml* pThis)](#oh_udshtml_getplaincontent) | 获取超文本标记语言类型[OH_UdsHtml](capi-udmf-oh-udshtml.md)对象中的纯文本内容参数。 |
| [int OH_UdsHtml_SetContent(OH_UdsHtml* pThis, const char* content)](#oh_udshtml_setcontent) | 设置超文本标记语言类型[OH_UdsHtml](capi-udmf-oh-udshtml.md)中的HTML格式内容参数。 |
| [int OH_UdsHtml_SetPlainContent(OH_UdsHtml* pThis, const char* plainContent)](#oh_udshtml_setplaincontent) | 设置超文本标记语言类型[OH_UdsHtml](capi-udmf-oh-udshtml.md)中的纯文本内容参数。 |
| [OH_UdsAppItem* OH_UdsAppItem_Create()](#oh_udsappitem_create) | 创建桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)指针及实例对象。当不再需要使用指针时，请使用[OH_UdsAppItem_Destroy](capi-uds-h.md#oh_udsappitem_destroy)销毁实例对象，否则会导致内存泄漏。 |
| [void OH_UdsAppItem_Destroy(OH_UdsAppItem* pThis)](#oh_udsappitem_destroy) | 销毁桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)指针指向的实例对象。 |
| [const char* OH_UdsAppItem_GetType(OH_UdsAppItem* pThis)](#oh_udsappitem_gettype) | 从桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)实例获取类型ID。 |
| [const char* OH_UdsAppItem_GetId(OH_UdsAppItem* pThis)](#oh_udsappitem_getid) | 从桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)实例中获取应用ID。 |
| [const char* OH_UdsAppItem_GetName(OH_UdsAppItem* pThis)](#oh_udsappitem_getname) | 从桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)实例中获取应用名称。 |
| [const char* OH_UdsAppItem_GetIconId(OH_UdsAppItem* pThis)](#oh_udsappitem_geticonid) | 从桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)实例中获取图片ID。 |
| [const char* OH_UdsAppItem_GetLabelId(OH_UdsAppItem* pThis)](#oh_udsappitem_getlabelid) | 从桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)实例中获取标签ID。 |
| [const char* OH_UdsAppItem_GetBundleName(OH_UdsAppItem* pThis)](#oh_udsappitem_getbundlename) | 从桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)实例中获取bundle名称。 |
| [const char* OH_UdsAppItem_GetAbilityName(OH_UdsAppItem* pThis)](#oh_udsappitem_getabilityname) | 从桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)实例中ability名称。 |
| [int OH_UdsAppItem_SetId(OH_UdsAppItem* pThis, const char* appId)](#oh_udsappitem_setid) | 设置桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)对象的应用ID。 |
| [int OH_UdsAppItem_SetName(OH_UdsAppItem* pThis, const char* appName)](#oh_udsappitem_setname) | 设置桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)对象的应用名称。 |
| [int OH_UdsAppItem_SetIconId(OH_UdsAppItem* pThis, const char* appIconId)](#oh_udsappitem_seticonid) | 设置桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)对象的图片ID。 |
| [int OH_UdsAppItem_SetLabelId(OH_UdsAppItem* pThis, const char* appLabelId)](#oh_udsappitem_setlabelid) | 设置桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)对象的标签ID。 |
| [int OH_UdsAppItem_SetBundleName(OH_UdsAppItem* pThis, const char* bundleName)](#oh_udsappitem_setbundlename) | 设置桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)对象的bundle名称。 |
| [int OH_UdsAppItem_SetAbilityName(OH_UdsAppItem* pThis, const char* abilityName)](#oh_udsappitem_setabilityname) | 设置桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)对象的ability名称。 |
| [OH_UdsFileUri* OH_UdsFileUri_Create()](#oh_udsfileuri_create) | 创建文件Uri类型[OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)的实例对象以及指向它的指针。当不再需要使用指针时，请使用[OH_UdsFileUri_Destroy](capi-uds-h.md#oh_udsfileuri_destroy)销毁实例对象，否则会导致内存泄漏。 |
| [void OH_UdsFileUri_Destroy(OH_UdsFileUri* pThis)](#oh_udsfileuri_destroy) | 销毁文件Uri类型[OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)的实例对象。 |
| [const char* OH_UdsFileUri_GetType(OH_UdsFileUri* pThis)](#oh_udsfileuri_gettype) | 从文件Uri类型[OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)实例中获取类型ID。 |
| [const char* OH_UdsFileUri_GetFileUri(OH_UdsFileUri* pThis)](#oh_udsfileuri_getfileuri) | 从文件Uri类型[OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)实例中获取文件Uri。 |
| [const char* OH_UdsFileUri_GetFileType(OH_UdsFileUri* pThis)](#oh_udsfileuri_getfiletype) | 从文件Uri类型[OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)实例中获取文件类型。 |
| [int OH_UdsFileUri_SetFileUri(OH_UdsFileUri* pThis, const char* fileUri)](#oh_udsfileuri_setfileuri) | 设置文件Uri类型[OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)对象的Uri信息。 |
| [int OH_UdsFileUri_SetFileType(OH_UdsFileUri* pThis, const char* fileType)](#oh_udsfileuri_setfiletype) | 设置文件Uri类型[OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)对象的文件类型。 |
| [OH_UdsPixelMap* OH_UdsPixelMap_Create()](#oh_udspixelmap_create) | 创建像素图片类型[OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md)的实例对象以及指向它的指针。当不再需要使用指针时，请使用[OH_UdsPixelMap_Destroy](capi-uds-h.md#oh_udspixelmap_destroy)销毁实例对象，否则会导致内存泄漏。 |
| [void OH_UdsPixelMap_Destroy(OH_UdsPixelMap* pThis)](#oh_udspixelmap_destroy) | 销毁像素图片类型[OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md)的实例对象。 |
| [const char* OH_UdsPixelMap_GetType(OH_UdsPixelMap* pThis)](#oh_udspixelmap_gettype) | 从像素图片类型[OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md)实例中获取类型ID。 |
| [void OH_UdsPixelMap_GetPixelMap(OH_UdsPixelMap* pThis, OH_PixelmapNative* pixelmapNative)](#oh_udspixelmap_getpixelmap) | 从像素图片类型[OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md)实例中获取像素图片[OH_PixelmapNative](../apis-image-kit/capi-pixelmap-native-h.md#oh_pixelmapnative_antialiasinglevel)实例的指针。 |
| [int OH_UdsPixelMap_SetPixelMap(OH_UdsPixelMap* pThis, OH_PixelmapNative* pixelmapNative)](#oh_udspixelmap_setpixelmap) | 设置像素图片类型[OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md)对象的像素图片内容。 |
| [OH_UdsArrayBuffer* OH_UdsArrayBuffer_Create()](#oh_udsarraybuffer_create) | 创建ArrayBuffer类型[OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md)的实例对象以及指向它的指针。当不再需要使用指针时，请使用[OH_UdsArrayBuffer_Destroy](capi-uds-h.md#oh_udsarraybuffer_destroy)销毁实例对象，否则会导致内存泄漏。 |
| [int OH_UdsArrayBuffer_Destroy(OH_UdsArrayBuffer* buffer)](#oh_udsarraybuffer_destroy) | 销毁ArrayBuffer类型[OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md)的实例对象。 |
| [int OH_UdsArrayBuffer_SetData(OH_UdsArrayBuffer* buffer, unsigned char* data, unsigned int len)](#oh_udsarraybuffer_setdata) | 设置ArrayBuffer类型[OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md)对象的数据内容。 |
| [int OH_UdsArrayBuffer_GetData(OH_UdsArrayBuffer* buffer, unsigned char** data, unsigned int* len)](#oh_udsarraybuffer_getdata) | 从ArrayBuffer类型[OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md)实例中获取用户自定义的ArrayBuffer数据内容。 |
| [OH_UdsContentForm* OH_UdsContentForm_Create()](#oh_udscontentform_create) | 创建内容卡片类型[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)指针及实例对象。 |
| [void OH_UdsContentForm_Destroy(OH_UdsContentForm* pThis)](#oh_udscontentform_destroy) | 销毁内容卡片类型数据[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)指针指向的实例对象。 |
| [const char* OH_UdsContentForm_GetType(OH_UdsContentForm* pThis)](#oh_udscontentform_gettype) | 从内容卡片类型[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)中获取类型ID。 |
| [int OH_UdsContentForm_GetThumbData(OH_UdsContentForm* pThis, unsigned char** thumbData, unsigned int* len)](#oh_udscontentform_getthumbdata) | 从内容卡片类型[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)中获取图片数据。 |
| [const char* OH_UdsContentForm_GetDescription(OH_UdsContentForm* pThis)](#oh_udscontentform_getdescription) | 从内容卡片类型[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)中获取描述信息。 |
| [const char* OH_UdsContentForm_GetTitle(OH_UdsContentForm* pThis)](#oh_udscontentform_gettitle) | 从内容卡片类型[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)中获取标题信息。 |
| [int OH_UdsContentForm_GetAppIcon(OH_UdsContentForm* pThis, unsigned char** appIcon, unsigned int* len)](#oh_udscontentform_getappicon) | 从内容卡片类型[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)中获取应用图标数据。 |
| [const char* OH_UdsContentForm_GetAppName(OH_UdsContentForm* pThis)](#oh_udscontentform_getappname) | 从内容卡片类型[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)中获取应用名称信息。 |
| [const char* OH_UdsContentForm_GetLinkUri(OH_UdsContentForm* pThis)](#oh_udscontentform_getlinkuri) | 从内容卡片类型[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)中获取超链接信息。 |
| [int OH_UdsContentForm_SetThumbData(OH_UdsContentForm* pThis, const unsigned char* thumbData, unsigned int len)](#oh_udscontentform_setthumbdata) | 设置内容卡片类型[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)中的图片数据。 |
| [int OH_UdsContentForm_SetDescription(OH_UdsContentForm* pThis, const char* description)](#oh_udscontentform_setdescription) | 设置内容卡片类型[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)中的描述信息。 |
| [int OH_UdsContentForm_SetTitle(OH_UdsContentForm* pThis, const char* title)](#oh_udscontentform_settitle) | 设置内容卡片类型[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)中的标题信息。 |
| [int OH_UdsContentForm_SetAppIcon(OH_UdsContentForm* pThis, const unsigned char* appIcon, unsigned int len)](#oh_udscontentform_setappicon) | 设置内容卡片类型[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)中的应用图标数据。 |
| [int OH_UdsContentForm_SetAppName(OH_UdsContentForm* pThis, const char* appName)](#oh_udscontentform_setappname) | 设置内容卡片类型[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)中的应用名称数据。 |
| [int OH_UdsContentForm_SetLinkUri(OH_UdsContentForm* pThis, const char* linkUri)](#oh_udscontentform_setlinkuri) | 设置内容卡片类型[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)中的超链接数据。 |

## 函数说明

### OH_UdsPlainText_Create()

```
OH_UdsPlainText* OH_UdsPlainText_Create()
```

**描述**

创建纯文本类型[OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)指针及实例对象。当不再需要使用指针时，请使用[OH_UdsPlainText_Destroy](capi-uds-h.md#oh_udsplaintext_destroy)销毁实例对象，否则会导致内存泄漏。

**起始版本：** 12

**返回：**

| 类型                                        | 说明                                                         |
| ------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)* | 执行成功则返回一个指向纯文本类型[OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)实例对象的指针，否则返回nullptr。 |

### OH_UdsPlainText_Destroy()

```
void OH_UdsPlainText_Destroy(OH_UdsPlainText* pThis)
```

**描述**

销毁纯文本类型数据[OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)指针指向的实例对象。

**起始版本：** 12


**参数：**

| 参数项                                            | 描述                                                         |
| ------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)* pThis | 表示指向[OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)实例的指针。 |

### OH_UdsPlainText_GetType()

```
const char* OH_UdsPlainText_GetType(OH_UdsPlainText* pThis)
```

**描述**

从纯文本类型[OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)中获取类型ID。

**起始版本：** 12


**参数：**

| 参数项                                            | 描述                                                         |
| ------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)* pThis | 表示指向纯文本类型[OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)实例的指针。 |

**返回：**

| 类型        | 说明                                                    |
| ----------- | ------------------------------------------------------- |
| const char* | 输入有效入参时返回类型ID的字符串指针，否则返回nullptr。 |

### OH_UdsPlainText_GetContent()

```
const char* OH_UdsPlainText_GetContent(OH_UdsPlainText* pThis)
```

**描述**

从纯文本类型[OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)中获取纯文本内容信息。

**起始版本：** 12


**参数：**

| 参数项                                            | 描述                                                         |
| ------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)* pThis | 表示指向纯文本类型[OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)实例的指针。 |

**返回：**

| 类型        | 说明                                                         |
| ----------- | ------------------------------------------------------------ |
| const char* | 输入有效入参时返回纯文本内容信息的字符串指针，否则返回nullptr。 |

### OH_UdsPlainText_GetAbstract()

```
const char* OH_UdsPlainText_GetAbstract(OH_UdsPlainText* pThis)
```

**描述**

从纯文本类型[OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)中获取纯文本摘要信息。

**起始版本：** 12


**参数：**

| 参数项                                            | 描述                                                         |
| ------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)* pThis | 表示指向纯文本类型[OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)实例的指针。 |

**返回：**

| 类型        | 说明                                                         |
| ----------- | ------------------------------------------------------------ |
| const char* | 输入有效入参时返回纯文本摘要信息的字符串指针，否则返回nullptr。 |

OH_UdsPlainText

### OH_UdsPlainText_SetContent()

```
int OH_UdsPlainText_SetContent(OH_UdsPlainText* pThis, const char* content)
```

**描述**

设置纯文本类型[OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)中的纯文本内容参数。

**起始版本：** 12


**参数：**

| 参数项                                            | 描述                                                         |
| ------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)* pThis | 表示指向纯文本类型[OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)实例的指针。 |
| const char* content                               | 表示纯文本内容参数。                                         |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_UdsPlainText_SetAbstract()

```
int OH_UdsPlainText_SetAbstract(OH_UdsPlainText* pThis, const char* abstract)
```

**描述**

设置纯文本类型[OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)中的纯文本摘要参数。

**起始版本：** 12


**参数：**

| 参数项                                            | 描述                                                         |
| ------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)* pThis | 表示指向纯文本类型[OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)实例的指针。 |
| const char* abstract                              | 表示纯文本摘要参数。                                         |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_UdsHyperlink_Create()

```
OH_UdsHyperlink* OH_UdsHyperlink_Create()
```

**描述**

创建超链接类型[OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)指针及实例对象。当不再需要使用指针时，请使用[OH_UdsHyperlink_Destroy](capi-uds-h.md#oh_udshyperlink_destroy)销毁实例对象，否则会导致内存泄漏。

**起始版本：** 12

**返回：**

| 类型             | 说明                                                         |
| ---------------- | ------------------------------------------------------------ |
| OH_UdsHyperlink* | 执行则成功返回一个指向超链接类型[OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)实例对象的指针，否则返回nullptr。 |

### OH_UdsHyperlink_Destroy()

```
void OH_UdsHyperlink_Destroy(OH_UdsHyperlink* pThis)
```

**描述**

销毁超链接类型[OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)指针指向的实例对象。

**起始版本：** 12


**参数：**

| 参数项                                            | 描述                                                         |
| ------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)* pThis | 表示指向超链接类型[OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)实例的指针。 |

### OH_UdsHyperlink_GetType()

```
const char* OH_UdsHyperlink_GetType(OH_UdsHyperlink* pThis)
```

**描述**

从超链接类型[OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)中获取类型ID。

**起始版本：** 12


**参数：**

| 参数项                                            | 描述                                                         |
| ------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)* pThis | 表示指向超链接类型[OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)实例的指针。 |

**返回：**

| 类型        | 说明                                                    |
| ----------- | ------------------------------------------------------- |
| const char* | 输入有效入参时返回类型ID的字符串指针，否则返回nullptr。 |

### OH_UdsHyperlink_GetUrl()

```
const char* OH_UdsHyperlink_GetUrl(OH_UdsHyperlink* pThis)
```

**描述**

从超链接类型[OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)中获取URL参数。

**起始版本：** 12


**参数：**

| 参数项                                            | 描述                                                         |
| ------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)* pThis | 表示指向超链接类型[OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)实例的指针。 |

**返回：**

| 类型        | 说明                                                     |
| ----------- | -------------------------------------------------------- |
| const char* | 输入有效入参时返回URL参数的字符串指针，否则返回nullptr。 |

### OH_UdsHyperlink_GetDescription()

```
const char* OH_UdsHyperlink_GetDescription(OH_UdsHyperlink* pThis)
```

**描述**

从超链接类型[OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)中获取描述参数。

**起始版本：** 12


**参数：**

| 参数项                                            | 描述                                                         |
| ------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)* pThis | 表示指向超链接类型[OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)实例的指针。 |

**返回：**

| 类型        | 说明                                                      |
| ----------- | --------------------------------------------------------- |
| const char* | 输入有效入参时返回描述参数的字符串指针，否则返回nullptr。 |

### OH_UdsHyperlink_SetUrl()

```
int OH_UdsHyperlink_SetUrl(OH_UdsHyperlink* pThis, const char* url)
```

**描述**

设置超链接类型[OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)实例中URL参数。

**起始版本：** 12


**参数：**

| 参数项                                            | 描述                                                         |
| ------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)* pThis | 表示指向超链接类型[OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)实例的指针。 |
| const char* url                                   | 表示URL参数。                                                |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_UdsHyperlink_SetDescription()

```
int OH_UdsHyperlink_SetDescription(OH_UdsHyperlink* pThis, const char* description)
```

**描述**

设置超链接类型[OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)实例中描述参数。

**起始版本：** 12


**参数：**

| 参数项                                            | 描述                                                         |
| ------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)* pThis | 表示指向超链接类型[OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)实例的指针。 |
| const char* description                           | 表示描述信息。                                               |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_UdsHtml_Create()

```
OH_UdsHtml* OH_UdsHtml_Create()
```

**描述**

创建超文本标记语言类型[OH_UdsHtml](capi-udmf-oh-udshtml.md)指针及实例对象。当不再需要使用指针时，请使用[OH_UdsHtml_Destroy](capi-uds-h.md#oh_udshtml_destroy)销毁实例对象，否则会导致内存泄漏。

**起始版本：** 12

**返回：**

| 类型                              | 说明                                                         |
| --------------------------------- | ------------------------------------------------------------ |
| [OH_UdsHtml](capi-udmf-oh-udshtml.md)* | 执行成功则返回一个指向超文本标记语言类型[OH_UdsHtml](capi-udmf-oh-udshtml.md)实例对象的指针，否则返回nullptr。 |

### OH_UdsHtml_Destroy()

```
void OH_UdsHtml_Destroy(OH_UdsHtml* pThis)
```

**描述**

销毁超文本标记语言类型[OH_UdsHtml](capi-udmf-oh-udshtml.md)指针指向的实例对象。

**起始版本：** 12


**参数：**

| 参数项                                  | 描述                                                         |
| --------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsHtml](capi-udmf-oh-udshtml.md)* pThis | 表示指向超文本标记语言类型[OH_UdsHtml](capi-udmf-oh-udshtml.md)实例的指针。 |

### OH_UdsHtml_GetType()

```
const char* OH_UdsHtml_GetType(OH_UdsHtml* pThis)
```

**描述**

获取超文本标记语言类型[OH_UdsHtml](capi-udmf-oh-udshtml.md)对象中类型ID。

**起始版本：** 12


**参数：**

| 参数项                                  | 描述                                                         |
| --------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsHtml](capi-udmf-oh-udshtml.md)* pThis | 表示指向超文本标记语言类型[OH_UdsHtml](capi-udmf-oh-udshtml.md)实例的指针。 |

**返回：**

| 类型        | 说明                                                    |
| ----------- | ------------------------------------------------------- |
| const char* | 输入有效入参时返回类型ID的字符串指针，否则返回nullptr。 |

### OH_UdsHtml_GetContent()

```
const char* OH_UdsHtml_GetContent(OH_UdsHtml* pThis)
```

**描述**

获取超文本标记语言类型[OH_UdsHtml](capi-udmf-oh-udshtml.md)对象中HTML格式内容参数。

**起始版本：** 12


**参数：**

| 参数项                                  | 描述                                                         |
| --------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsHtml](capi-udmf-oh-udshtml.md)* pThis | 表示指向超文本标记语言类型[OH_UdsHtml](capi-udmf-oh-udshtml.md)实例的指针。 |

**返回：**

| 类型        | 说明                                                         |
| ----------- | ------------------------------------------------------------ |
| const char* | 输入有效入参时返回HTML格式内容的字符串指针，否则返回nullptr。 |

### OH_UdsHtml_GetPlainContent()

```
const char* OH_UdsHtml_GetPlainContent(OH_UdsHtml* pThis)
```

**描述**

获取超文本标记语言类型[OH_UdsHtml](capi-udmf-oh-udshtml.md)对象中的纯文本内容参数。

**起始版本：** 12


**参数：**

| 参数项                                  | 描述                                                         |
| --------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsHtml](capi-udmf-oh-udshtml.md)* pThis | 表示指向超文本标记语言类型[OH_UdsHtml](capi-udmf-oh-udshtml.md)实例的指针。 |

**返回：**

| 类型        | 说明                                                        |
| ----------- | ----------------------------------------------------------- |
| const char* | 输入有效入参时返回纯文本内容的字符串指针，否则返回nullptr。 |

### OH_UdsHtml_SetContent()

```
int OH_UdsHtml_SetContent(OH_UdsHtml* pThis, const char* content)
```

**描述**

设置超文本标记语言类型[OH_UdsHtml](capi-udmf-oh-udshtml.md)中的HTML格式内容参数。

**起始版本：** 12


**参数：**

| 参数项                                  | 描述                                                         |
| --------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsHtml](capi-udmf-oh-udshtml.md)* pThis | 表示指向超文本标记语言类型[OH_UdsHtml](capi-udmf-oh-udshtml.md)实例的指针。 |
| const char* content                     | 表示HTML格式内容参数。                                       |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_UdsHtml_SetPlainContent()

```
int OH_UdsHtml_SetPlainContent(OH_UdsHtml* pThis, const char* plainContent)
```

**描述**

设置超文本标记语言类型[OH_UdsHtml](capi-udmf-oh-udshtml.md)中的纯文本内容参数。

**起始版本：** 12


**参数：**

| 参数项                                  | 描述                                                         |
| --------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsHtml](capi-udmf-oh-udshtml.md)* pThis | 表示指向超文本标记语言类型[OH_UdsHtml](capi-udmf-oh-udshtml.md)实例的指针。 |
| const char* plainContent                | 表示纯文本内容参数。                                         |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_UdsAppItem_Create()

```
OH_UdsAppItem* OH_UdsAppItem_Create()
```

**描述**

创建桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)指针及实例对象。当不再需要使用指针时，请使用[OH_UdsAppItem_Destroy](capi-uds-h.md#oh_udsappitem_destroy)销毁实例对象，否则会导致内存泄漏。

**起始版本：** 12

**返回：**

| 类型                                    | 说明                                                         |
| --------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsAppItem](capi-udmf-oh-udsappitem.md)* | 执行成功返则回一个指向桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)实例对象的指针，否则返回nullptr。 |

### OH_UdsAppItem_Destroy()

```
void OH_UdsAppItem_Destroy(OH_UdsAppItem* pThis)
```

**描述**

销毁桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)指针指向的实例对象。

**起始版本：** 12


**参数：**

| 参数项                                        | 描述                                                         |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsAppItem](capi-udmf-oh-udsappitem.md)* pThis | 表示一个指向桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)对象的指针。 |

### OH_UdsAppItem_GetType()

```
const char* OH_UdsAppItem_GetType(OH_UdsAppItem* pThis)
```

**描述**

从桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)实例获取类型ID。

**起始版本：** 12


**参数：**

| 参数项                                        | 描述                                                         |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsAppItem](capi-udmf-oh-udsappitem.md)* pThis | 表示一个指向桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)对象的指针。 |

**返回：**

| 类型        | 说明                                                    |
| ----------- | ------------------------------------------------------- |
| const char* | 输入有效入参时返回类型ID的字符串指针，否则返回nullptr。 |

### OH_UdsAppItem_GetId()

```
const char* OH_UdsAppItem_GetId(OH_UdsAppItem* pThis)
```

**描述**

从桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)实例中获取应用ID。

**起始版本：** 12


**参数：**

| 参数项                                        | 描述                                                         |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsAppItem](capi-udmf-oh-udsappitem.md)* pThis | 表示一个指向桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)对象的指针。 |

**返回：**

| 类型        | 说明                                                    |
| ----------- | ------------------------------------------------------- |
| const char* | 输入有效入参时返回应用ID的字符串指针，否则返回nullptr。 |

### OH_UdsAppItem_GetName()

```
const char* OH_UdsAppItem_GetName(OH_UdsAppItem* pThis)
```

**描述**

从桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)实例中获取应用名称。

**起始版本：** 12


**参数：**

| 参数项                                        | 描述                                                         |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsAppItem](capi-udmf-oh-udsappitem.md)* pThis | 表示一个指向桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)对象的指针。 |

**返回：**

| 类型        | 说明                                                      |
| ----------- | --------------------------------------------------------- |
| const char* | 输入有效入参时返回应用名称的字符串指针，否则返回nullptr。 |

### OH_UdsAppItem_GetIconId()

```
const char* OH_UdsAppItem_GetIconId(OH_UdsAppItem* pThis)
```

**描述**

从桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)实例中获取图片ID。

**起始版本：** 12


**参数：**

| 参数项                                        | 描述                                                         |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsAppItem](capi-udmf-oh-udsappitem.md)* pThis | 表示一个指向桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)对象的指针。 |

**返回：**

| 类型        | 说明                                                    |
| ----------- | ------------------------------------------------------- |
| const char* | 输入有效入参时返回图片ID的字符串指针，否则返回nullptr。 |

### OH_UdsAppItem_GetLabelId()

```
const char* OH_UdsAppItem_GetLabelId(OH_UdsAppItem* pThis)
```

**描述**

从桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)实例中获取标签ID。

**起始版本：** 12


**参数：**

| 参数项                                        | 描述                                                         |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsAppItem](capi-udmf-oh-udsappitem.md)* pThis | 表示一个指向桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)对象的指针。 |

**返回：**

| 类型        | 说明                                                    |
| ----------- | ------------------------------------------------------- |
| const char* | 输入有效入参时返回标签ID的字符串指针，否则返回nullptr。 |

### OH_UdsAppItem_GetBundleName()

```
const char* OH_UdsAppItem_GetBundleName(OH_UdsAppItem* pThis)
```

**描述**

从桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)实例中获取bundle名称。

**起始版本：** 12


**参数：**

| 参数项                                        | 描述                                                         |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsAppItem](capi-udmf-oh-udsappitem.md)* pThis | 表示一个指向桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)对象的指针。 |

**返回：**

| 类型        | 说明                                                        |
| ----------- | ----------------------------------------------------------- |
| const char* | 输入有效入参时返回bundle名称的字符串指针，否则返回nullptr。 |

### OH_UdsAppItem_GetAbilityName()

```
const char* OH_UdsAppItem_GetAbilityName(OH_UdsAppItem* pThis)
```

**描述**

从桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)实例中ability名称。

**起始版本：** 12


**参数：**

| 参数项                                        | 描述                                                         |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsAppItem](capi-udmf-oh-udsappitem.md)* pThis | 表示一个指向桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)对象的指针。 |

**返回：**

| 类型        | 说明                                                         |
| ----------- | ------------------------------------------------------------ |
| const char* | 输入有效入参时返回ability名称的字符串指针，否则返回nullptr。 |

### OH_UdsAppItem_SetId()

```
int OH_UdsAppItem_SetId(OH_UdsAppItem* pThis, const char* appId)
```

**描述**

设置桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)对象的应用ID。

**起始版本：** 12


**参数：**

| 参数项                                        | 描述                                                         |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsAppItem](capi-udmf-oh-udsappitem.md)* pThis | 表示一个指向桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)对象的指针。 |
| const char* appId                             | 表示应用ID。                                                 |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_UdsAppItem_SetName()

```
int OH_UdsAppItem_SetName(OH_UdsAppItem* pThis, const char* appName)
```

**描述**

设置桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)对象的应用名称。

**起始版本：** 12


**参数：**

| 参数项                                        | 描述                                                         |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsAppItem](capi-udmf-oh-udsappitem.md)* pThis | 表示一个指向桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)对象的指针。 |
| const char* appName                           | 表示应用名称。                                               |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_UdsAppItem_SetIconId()

```
int OH_UdsAppItem_SetIconId(OH_UdsAppItem* pThis, const char* appIconId)
```

**描述**

设置桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)对象的图片ID。

**起始版本：** 12


**参数：**

| 参数项                                        | 描述                                                         |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsAppItem](capi-udmf-oh-udsappitem.md)* pThis | 表示一个指向桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)对象的指针。 |
| const char* appIconId                         | 表示图片ID。                                                 |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_UdsAppItem_SetLabelId()

```
int OH_UdsAppItem_SetLabelId(OH_UdsAppItem* pThis, const char* appLabelId)
```

**描述**

设置桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)对象的标签ID。

**起始版本：** 12


**参数：**

| 参数项                                        | 描述                                                         |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsAppItem](capi-udmf-oh-udsappitem.md)* pThis | 表示一个指向桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)对象的指针。 |
| const char* appLabelId                        | 表示标签ID。                                                 |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_UdsAppItem_SetBundleName()

```
int OH_UdsAppItem_SetBundleName(OH_UdsAppItem* pThis, const char* bundleName)
```

**描述**

设置桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)对象的bundle名称。

**起始版本：** 12


**参数：**

| 参数项                                        | 描述                                                         |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsAppItem](capi-udmf-oh-udsappitem.md)* pThis | 表示一个指向桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)对象的指针。 |
| const char* bundleName                        | 表示bundle名称。                                             |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_UdsAppItem_SetAbilityName()

```
int OH_UdsAppItem_SetAbilityName(OH_UdsAppItem* pThis, const char* abilityName)
```

**描述**

设置桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)对象的ability名称。

**起始版本：** 12


**参数：**

| 参数项                                        | 描述                                                         |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsAppItem](capi-udmf-oh-udsappitem.md)* pThis | 表示一个指向桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)对象的指针。 |
| const char* abilityName                       | 表示ability名称。                                            |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_UdsFileUri_Create()

```
OH_UdsFileUri* OH_UdsFileUri_Create()
```

**描述**

创建文件Uri类型[OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)的实例对象以及指向它的指针。当不再需要使用指针时，请使用[OH_UdsFileUri_Destroy](capi-uds-h.md#oh_udsfileuri_destroy)销毁实例对象，否则会导致内存泄漏。

**起始版本：** 13

**返回：**

| 类型                                    | 说明                                                         |
| --------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)* | 执行成功则返回一个指向文件Uri类型[OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)实例对象的指针，否则返回nullptr。 |

### OH_UdsFileUri_Destroy()

```
void OH_UdsFileUri_Destroy(OH_UdsFileUri* pThis)
```

**描述**

销毁文件Uri类型[OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)的实例对象。

**起始版本：** 13


**参数：**

| 参数项                                        | 描述                                                         |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)* pThis | 表示指向文件Uri类型[OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)实例的指针。 |

### OH_UdsFileUri_GetType()

```
const char* OH_UdsFileUri_GetType(OH_UdsFileUri* pThis)
```

**描述**

从文件Uri类型[OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)实例中获取类型ID。

**起始版本：** 13


**参数：**

| 参数项                                        | 描述                                                         |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)* pThis | 表示指向文件Uri类型[OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)实例的指针。 |

**返回：**

| 类型        | 说明                                                    |
| ----------- | ------------------------------------------------------- |
| const char* | 输入有效入参时返回类型ID的字符串指针，否则返回nullptr。 |

### OH_UdsFileUri_GetFileUri()

```
const char* OH_UdsFileUri_GetFileUri(OH_UdsFileUri* pThis)
```

**描述**

从文件Uri类型[OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)实例中获取文件Uri。

**起始版本：** 13


**参数：**

| 参数项                                        | 描述                                                         |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)* pThis | 表示指向文件Uri类型[OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)实例的指针。 |

**返回：**

| 类型        | 说明                                                     |
| ----------- | -------------------------------------------------------- |
| const char* | 输入有效入参时返回文件Uri的字符串指针，否则返回nullptr。 |

### OH_UdsFileUri_GetFileType()

```
const char* OH_UdsFileUri_GetFileType(OH_UdsFileUri* pThis)
```

**描述**

从文件Uri类型[OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)实例中获取文件类型。

**起始版本：** 13


**参数：**

| 参数项                                        | 描述                                                         |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)* pThis | 表示指向文件Uri类型[OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)实例的指针。 |

**返回：**

| 类型        | 说明                                                      |
| ----------- | --------------------------------------------------------- |
| const char* | 输入有效入参时返回文件类型的字符串指针，否则返回nullptr。 |

### OH_UdsFileUri_SetFileUri()

```
int OH_UdsFileUri_SetFileUri(OH_UdsFileUri* pThis, const char* fileUri)
```

**描述**

设置文件Uri类型[OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)对象的Uri信息。

**起始版本：** 13


**参数：**

| 参数项                                        | 描述                                                         |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)* pThis | 表示指向文件Uri类型[OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)实例的指针。 |
| const char* fileUri                           | 表示文件Uri。                                                |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_UdsFileUri_SetFileType()

```
int OH_UdsFileUri_SetFileType(OH_UdsFileUri* pThis, const char* fileType)
```

**描述**

设置文件Uri类型[OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)对象的文件类型。

**起始版本：** 13


**参数：**

| 参数项                                        | 描述                                                         |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)* pThis | 表示指向文件Uri类型[OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)实例的指针。 |
| const char* fileType                          | 表示文件类型。                                               |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_UdsPixelMap_Create()

```
OH_UdsPixelMap* OH_UdsPixelMap_Create()
```

**描述**

创建像素图片类型[OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md)的实例对象以及指向它的指针。当不再需要使用指针时，请使用[OH_UdsPixelMap_Destroy](capi-uds-h.md#oh_udspixelmap_destroy)销毁实例对象，否则会导致内存泄漏。

**起始版本：** 13

**返回：**

| 类型                                      | 说明                                                         |
| ----------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md)* | 执行成功则返回一个指向像素图片类型[OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md)实例对象的指针，否则返回nullptr。 |

### OH_UdsPixelMap_Destroy()

```
void OH_UdsPixelMap_Destroy(OH_UdsPixelMap* pThis)
```

**描述**

销毁像素图片类型[OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md)的实例对象。

**起始版本：** 13


**参数：**

| 参数项                                          | 描述                                                         |
| ----------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md)* pThis | 表示指向像素图片类型[OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md)实例的指针。 |

### OH_UdsPixelMap_GetType()

```
const char* OH_UdsPixelMap_GetType(OH_UdsPixelMap* pThis)
```

**描述**

从像素图片类型[OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md)实例中获取类型ID。

**起始版本：** 13


**参数：**

| 参数项                                          | 描述                                                         |
| ----------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md)* pThis | 表示指向像素图片类型[OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md)实例的指针。 |

**返回：**

| 类型        | 说明                                                    |
| ----------- | ------------------------------------------------------- |
| const char* | 输入有效入参时返回类型ID的字符串指针，否则返回nullptr。 |

### OH_UdsPixelMap_GetPixelMap()

```
void OH_UdsPixelMap_GetPixelMap(OH_UdsPixelMap* pThis, OH_PixelmapNative* pixelmapNative)
```

**描述**

从像素图片类型[OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md)实例中获取像素图片[OH_PixelmapNative](../apis-image-kit/capi-pixelmap-native-h.md#oh_pixelmapnative_antialiasinglevel)实例的指针。

**起始版本：** 13


**参数：**

| 参数项                                          | 描述                                                         |
| ----------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md)* pThis | 表示指向像素图片类型[OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md)实例的指针。 |
| OH_PixelmapNative* pixelmapNative               | 该参数是输出参数，表示指向像素图片[OH_PixelmapNative](../apis-image-kit/capi-pixelmap-native-h.md#oh_pixelmapnative_antialiasinglevel)实例的指针。 |

### OH_UdsPixelMap_SetPixelMap()

```
int OH_UdsPixelMap_SetPixelMap(OH_UdsPixelMap* pThis, OH_PixelmapNative* pixelmapNative)
```

**描述**

设置像素图片类型[OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md)对象的像素图片内容。

**起始版本：** 13


**参数：**

| 参数项                                          | 描述                                                         |
| ----------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md)* pThis | 表示指向像素图片类型[OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md)实例的指针。 |
| OH_PixelmapNative* pixelmapNative               | 表示指向像素图片[OH_PixelmapNative](../apis-image-kit/capi-pixelmap-native-h.md#oh_pixelmapnative_antialiasinglevel)实例的指针 |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_UdsArrayBuffer_Create()

```
OH_UdsArrayBuffer* OH_UdsArrayBuffer_Create()
```

**描述**

创建ArrayBuffer类型[OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md)的实例对象以及指向它的指针。当不再需要使用指针时，请使用[OH_UdsArrayBuffer_Destroy](capi-uds-h.md#oh_udsarraybuffer_destroy)销毁实例对象，否则会导致内存泄漏。

**起始版本：** 13

**返回：**

| 类型                                            | 说明                                                         |
| ----------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md)* | 执行成功则返回一个指向ArrayBuffer类型[OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md)实例对象的指针，否则返回nullptr。 |

### OH_UdsArrayBuffer_Destroy()

```
int OH_UdsArrayBuffer_Destroy(OH_UdsArrayBuffer* buffer)
```

**描述**

销毁ArrayBuffer类型[OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md)的实例对象。

**起始版本：** 13


**参数：**

| 参数项                                                 | 描述                                                         |
| ------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md)* buffer | 表示指向ArrayBuffer类型[OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md)实例的指针。 |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行的错误码。请参阅错误码定义[OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_UdsArrayBuffer_SetData()

```
int OH_UdsArrayBuffer_SetData(OH_UdsArrayBuffer* buffer, unsigned char* data, unsigned int len)
```

**描述**

设置ArrayBuffer类型[OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md)对象的数据内容。

**起始版本：** 13


**参数：**

| 参数项                                                 | 描述                                                         |
| ------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md)* buffer | 表示指向ArrayBuffer类型[OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md)实例的指针。 |
| unsigned char* data                                    | 表示用户自定义的ArrayBuffer数据。                            |
| unsigned int len                                       | 表示用户自定义的ArrayBuffer数据的大小。                      |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行的错误码。请参阅错误码定义[OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_UdsArrayBuffer_GetData()

```
int OH_UdsArrayBuffer_GetData(OH_UdsArrayBuffer* buffer, unsigned char** data, unsigned int* len)
```

**描述**

从ArrayBuffer类型[OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md)实例中获取用户自定义的ArrayBuffer数据内容。

**起始版本：** 13


**参数：**

| 参数项                                                 | 描述                                                         |
| ------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md)* buffer | 表示指向ArrayBuffer类型[OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md)实例的指针。 |
| unsigned char** data                                   | 该参数是输出参数，表示用户自定义的ArrayBuffer数据。          |
| unsigned int* len                                      | 该参数是输出参数，表示用户自定义的ArrayBuffer数据的大小。    |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行的错误码。请参阅错误码定义[OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_UdsContentForm_Create()

```
OH_UdsContentForm* OH_UdsContentForm_Create()
```

**描述**

创建内容卡片类型[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)指针及实例对象。

**起始版本：** 14

**返回：**

| 类型                                            | 说明                                                         |
| ----------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsContentForm](capi-udmf-oh-udscontentform.md)* | 执行成功则返回一个指向内容卡片类型[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)实例对象的指针，否则返回nullptr。 |

### OH_UdsContentForm_Destroy()

```
void OH_UdsContentForm_Destroy(OH_UdsContentForm* pThis)
```

**描述**

销毁内容卡片类型数据[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)指针指向的实例对象。

**起始版本：** 14


**参数：**

| 参数项                                                | 描述                                                         |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsContentForm](capi-udmf-oh-udscontentform.md)* pThis | 表示指向[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)实例的指针。 |

### OH_UdsContentForm_GetType()

```
const char* OH_UdsContentForm_GetType(OH_UdsContentForm* pThis)
```

**描述**

从内容卡片类型[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)中获取类型ID。

**起始版本：** 14


**参数：**

| 参数项                                                | 描述                                                         |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsContentForm](capi-udmf-oh-udscontentform.md)* pThis | 表示指向[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)实例的指针。 |

**返回：**

| 类型        | 说明                                                    |
| ----------- | ------------------------------------------------------- |
| const char* | 输入有效入参时返回类型ID的字符串指针，否则返回nullptr。 |

### OH_UdsContentForm_GetThumbData()

```
int OH_UdsContentForm_GetThumbData(OH_UdsContentForm* pThis, unsigned char** thumbData, unsigned int* len)
```

**描述**

从内容卡片类型[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)中获取图片数据。

**起始版本：** 14


**参数：**

| 参数项                                                | 描述                                                         |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsContentForm](capi-udmf-oh-udscontentform.md)* pThis | 表示指向[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)实例的指针。 |
| unsigned char** thumbData                             | 该参数是输出参数，表示内容卡片中的图片二进制数据。           |
| unsigned int* len                                     | 该参数是输出参数，表示内容卡片中的图片二进制数据的大小。     |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行的错误码。请参阅错误码定义[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。<br>若返回UDMF_ERR，表示出现了内部系统错误。 |

### OH_UdsContentForm_GetDescription()

```
const char* OH_UdsContentForm_GetDescription(OH_UdsContentForm* pThis)
```

**描述**

从内容卡片类型[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)中获取描述信息。

**起始版本：** 14


**参数：**

| 参数项                                                | 描述                                                         |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsContentForm](capi-udmf-oh-udscontentform.md)* pThis | 表示指向[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)实例的指针。 |

**返回：**

| 类型        | 说明                                                      |
| ----------- | --------------------------------------------------------- |
| const char* | 输入有效入参时返回描述信息的字符串指针，否则返回nullptr。 |

### OH_UdsContentForm_GetTitle()

```
const char* OH_UdsContentForm_GetTitle(OH_UdsContentForm* pThis)
```

**描述**

从内容卡片类型[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)中获取标题信息。

**起始版本：** 14


**参数：**

| 参数项                                                | 描述                                                         |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsContentForm](capi-udmf-oh-udscontentform.md)* pThis | 表示指向[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)实例的指针。 |

**返回：**

| 类型        | 说明                                                      |
| ----------- | --------------------------------------------------------- |
| const char* | 输入有效入参时返回标题信息的字符串指针，否则返回nullptr。 |

### OH_UdsContentForm_GetAppIcon()

```
int OH_UdsContentForm_GetAppIcon(OH_UdsContentForm* pThis, unsigned char** appIcon, unsigned int* len)
```

**描述**

从内容卡片类型[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)中获取应用图标数据。

**起始版本：** 14


**参数：**

| 参数项                                                | 描述                                                         |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsContentForm](capi-udmf-oh-udscontentform.md)* pThis | 表示指向[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)实例的指针。 |
| unsigned char** appIcon                               | 该参数是输出参数，表示内容卡片中的应用图标二进制数据。       |
| unsigned int* len                                     | 该参数是输出参数，表示内容卡片中的应用图标二进制数据的大小。 |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行的错误码。请参阅错误码定义[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。<br>若返回UDMF_ERR，表示出现了内部系统错误。 |

### OH_UdsContentForm_GetAppName()

```
const char* OH_UdsContentForm_GetAppName(OH_UdsContentForm* pThis)
```

**描述**

从内容卡片类型[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)中获取应用名称信息。

**起始版本：** 14


**参数：**

| 参数项                                                | 描述                                                         |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsContentForm](capi-udmf-oh-udscontentform.md)* pThis | 表示指向[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)实例的指针。 |

**返回：**

| 类型        | 说明                                                         |
| ----------- | ------------------------------------------------------------ |
| const char* | 输入有效入参时返回应用名称信息的字符串指针，否则返回nullptr。 |

### OH_UdsContentForm_GetLinkUri()

```
const char* OH_UdsContentForm_GetLinkUri(OH_UdsContentForm* pThis)
```

**描述**

从内容卡片类型[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)中获取超链接信息。

**起始版本：** 14


**参数：**

| 参数项                                                | 描述                                                         |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsContentForm](capi-udmf-oh-udscontentform.md)* pThis | 表示指向[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)实例的指针。 |

**返回：**

| 类型        | 说明                                                    |
| ----------- | ------------------------------------------------------- |
| const char* | 输入有效入参时返回超链接的字符串指针，否则返回nullptr。 |

### OH_UdsContentForm_SetThumbData()

```
int OH_UdsContentForm_SetThumbData(OH_UdsContentForm* pThis, const unsigned char* thumbData, unsigned int len)
```

**描述**

设置内容卡片类型[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)中的图片数据。

**起始版本：** 14


**参数：**

| 参数项                                                | 描述                                                         |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsContentForm](capi-udmf-oh-udscontentform.md)* pThis | 表示指向[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)实例的指针。 |
| const unsigned char* thumbData                        | 表示内容卡片中的图片二进制数据。                             |
| unsigned int len                                      | 表示内容卡片中的图片二进制数据的大小。                       |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行的错误码。请参阅错误码定义[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效的参数。 |

### OH_UdsContentForm_SetDescription()

```
int OH_UdsContentForm_SetDescription(OH_UdsContentForm* pThis, const char* description)
```

**描述**

设置内容卡片类型[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)中的描述信息。

**起始版本：** 14


**参数：**

| 参数项                                                | 描述                                                         |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsContentForm](capi-udmf-oh-udscontentform.md)* pThis | 表示指向[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)实例的指针。 |
| const char* description                               | 表示描述信息。                                               |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行的错误码。请参阅错误码定义[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效的参数。 |

### OH_UdsContentForm_SetTitle()

```
int OH_UdsContentForm_SetTitle(OH_UdsContentForm* pThis, const char* title)
```

**描述**

设置内容卡片类型[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)中的标题信息。

**起始版本：** 14


**参数：**

| 参数项                                                | 描述                                                         |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsContentForm](capi-udmf-oh-udscontentform.md)* pThis | 表示指向[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)实例的指针。 |
| const char* title                                     | 表示标题信息。                                               |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行的错误码。请参阅错误码定义[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效的参数。 |

### OH_UdsContentForm_SetAppIcon()

```
int OH_UdsContentForm_SetAppIcon(OH_UdsContentForm* pThis, const unsigned char* appIcon, unsigned int len)
```

**描述**

设置内容卡片类型[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)中的应用图标数据。

**起始版本：** 14


**参数：**

| 参数项                                                | 描述                                                         |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsContentForm](capi-udmf-oh-udscontentform.md)* pThis | 表示指向[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)实例的指针。 |
| const unsigned char* appIcon                          | 表示内容卡片中的应用图标二进制数据。                         |
| unsigned int len                                      | 表示内容卡片中的应用图标二进制数据的大小。                   |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效的参数。 |

### OH_UdsContentForm_SetAppName()

```
int OH_UdsContentForm_SetAppName(OH_UdsContentForm* pThis, const char* appName)
```

**描述**

设置内容卡片类型[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)中的应用名称数据。

**起始版本：** 14


**参数：**

| 参数项                                                | 描述                                                         |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsContentForm](capi-udmf-oh-udscontentform.md)* pThis | 表示指向[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)实例的指针。 |
| const char* appName                                   | 表示内容卡片中的应用名称。                                   |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效的参数。 |

### OH_UdsContentForm_SetLinkUri()

```
int OH_UdsContentForm_SetLinkUri(OH_UdsContentForm* pThis, const char* linkUri)
```

**描述**

设置内容卡片类型[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)中的超链接数据。

**起始版本：** 14


**参数：**

| 参数项                                                | 描述                                                         |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| [OH_UdsContentForm](capi-udmf-oh-udscontentform.md)* pThis | 表示指向[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)实例的指针。 |
| const char* linkUri                                   | 表示内容卡片中的超链接。                                     |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效的参数。 |



