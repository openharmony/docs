# udmf.h
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @jcwen-->
<!--SE: @junathuawei1; @zph000-->
<!--TSE: @lj_liujing; @yippo; @logic42-->

## 概述

提供访问统一数据管理框架数据的接口、数据结构、枚举类型。

**引用文件：** <database/udmf/udmf.h>

**库：** libudmf.so

**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core

**起始版本：** 12

**相关模块：** [UDMF](capi-udmf.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_UdmfData](capi-udmf-oh-udmfdata.md) | OH_UdmfData | 定义统一数据对象数据结构。 |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) | OH_UdmfRecord | 定义统一数据对象中记录数据的数据结构，称为数据记录。 |
| [OH_UdmfRecordProvider](capi-udmf-oh-udmfrecordprovider.md) | OH_UdmfRecordProvider | 定义统一数据对象中的数据提供者。 |
| [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md) | OH_UdmfProperty | 定义统一数据对象中数据记录的属性结构。 |
| [OH_Udmf_ProgressInfo](capi-udmf-oh-udmf-progressinfo.md) | OH_Udmf_ProgressInfo | 定义进度信息的数据结构。 |
| [OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md) | OH_UdmfGetDataParams | 定义异步获取UDMF数据的请求参数。 |
| [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md) | OH_UdmfOptions | 数据操作选项，定义数据操作的可选参数。 |
| [OH_UdmfDataLoadParams](capi-udmf-oh-udmfdataloadparams.md) | OH_UdmfDataLoadParams | 表示数据加载参数结构体。 |
| [OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md) | OH_UdmfDataLoadInfo | 表示数据加载信息结构体。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [Udmf_Intention](#udmf_intention) | Udmf_Intention | 描述UDMF数据通路枚举类型。 |
| [Udmf_ShareOption](#udmf_shareoption) | Udmf_ShareOption | UDMF支持的设备内使用范围类型枚举。 |
| [Udmf_FileConflictOptions](#udmf_fileconflictoptions) | Udmf_FileConflictOptions | 定义文件拷贝冲突时的选项。 |
| [Udmf_ProgressIndicator](#udmf_progressindicator) | Udmf_ProgressIndicator | 定义进度条指示选项，可选择是否采用系统默认进度显示。 |
| [Udmf_Visibility](#udmf_visibility) | Udmf_Visibility | 定义数据的可见性等级。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [UDMF_KEY_BUFFER_LEN (512)](#udmf_key_buffer_len) | - | 统一数据对象唯一标识符最小空间长度。 |
| [typedef void (\*OH_Udmf_DataProgressListener)(OH_Udmf_ProgressInfo* progressInfo, OH_UdmfData* data)](#oh_udmf_dataprogresslistener) | OH_Udmf_DataProgressListener | 定义获取进度信息和数据的监听回调函数。<br>使用时需要判断数据是否返回空指针。只有当进度达到100%时，才会返回数据。 |
| [OH_UdmfData* OH_UdmfData_Create()](#oh_udmfdata_create) | - | 创建统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)指针及实例对象。当不再需要使用指针时，请使用[OH_UdmfData_Destroy](capi-udmf-h.md#oh_udmfdata_destroy)销毁实例对象，否则会导致内存泄漏。 |
| [void OH_UdmfData_Destroy(OH_UdmfData* pThis)](#oh_udmfdata_destroy) | - | 销毁统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)指针指向的实例对象。 |
| [int OH_UdmfData_AddRecord(OH_UdmfData* pThis, OH_UdmfRecord* record)](#oh_udmfdata_addrecord) | - | 添加一个数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)到统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)中。 |
| [bool OH_UdmfData_HasType(OH_UdmfData* pThis, const char* type)](#oh_udmfdata_hastype) | - | 检查统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)中是否存在指定类型。 |
| [char** OH_UdmfData_GetTypes(OH_UdmfData* pThis, unsigned int* count)](#oh_udmfdata_gettypes) | - | 获取统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)中包含的所有类型结果集。 |
| [OH_UdmfRecord** OH_UdmfData_GetRecords(OH_UdmfData* pThis, unsigned int* count)](#oh_udmfdata_getrecords) | - | 获取统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)中包含的所有记录结果集。 |
| [typedef void (\*UdmfData_Finalize)(void* context)](#udmfdata_finalize) | UdmfData_Finalize | 定义用于释放上下文的回调函数，统一数据提供者对象销毁时触发。 |
| [OH_UdmfRecordProvider* OH_UdmfRecordProvider_Create()](#oh_udmfrecordprovider_create) | - | 创建一个统一数据提供者[OH_UdmfRecordProvider](capi-udmf-oh-udmfrecordprovider.md)指针及实例对象。当不再需要使用指针时，请使用[OH_UdmfRecordProvider_Destroy](capi-udmf-h.md#oh_udmfrecordprovider_destroy)销毁实例对象，否则会导致内存泄漏。 |
| [int OH_UdmfRecordProvider_Destroy(OH_UdmfRecordProvider* provider)](#oh_udmfrecordprovider_destroy) | - | 销毁统一数据提供者[OH_UdmfRecordProvider](capi-udmf-oh-udmfrecordprovider.md)指针指向的实例对象。 |
| [typedef void* (\*OH_UdmfRecordProvider_GetData)(void* context, const char* type)](#oh_udmfrecordprovider_getdata) | OH_UdmfRecordProvider_GetData | 定义用于按类型获取数据的回调函数。当从OH_UdmfRecord中获取数据时，会触发此回调函数，得到的数据就是这个回调函数返回的数据。 |
| [int OH_UdmfRecordProvider_SetData(OH_UdmfRecordProvider* provider, void* context, const OH_UdmfRecordProvider_GetData callback, const UdmfData_Finalize finalize)](#oh_udmfrecordprovider_setdata) | - | 设置统一数据提供者的数据提供回调函数。 |
| [OH_UdmfRecord* OH_UdmfRecord_Create()](#oh_udmfrecord_create) | - | 创建统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)指针及实例对象。当不再需要使用指针时，请使用[OH_UdmfRecord_Destroy](capi-udmf-h.md#oh_udmfrecord_destroy)销毁实例对象，否则会导致内存泄漏。 |
| [void OH_UdmfRecord_Destroy(OH_UdmfRecord* pThis)](#oh_udmfrecord_destroy) | - | 销毁统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)指针指向的实例对象。 |
| [int OH_UdmfRecord_AddGeneralEntry(OH_UdmfRecord* pThis, const char* typeId, unsigned char* entry, unsigned int count)](#oh_udmfrecord_addgeneralentry) | - | 添加用户自定义的通用数据至统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)中。对于已定义UDS的类型（比如PlainText、Link、Pixelmap等）不可使用该接口。 |
| [int OH_UdmfRecord_AddPlainText(OH_UdmfRecord* pThis, OH_UdsPlainText* plainText)](#oh_udmfrecord_addplaintext) | - | 增加纯文本类型[OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)数据至统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)中。 |
| [int OH_UdmfRecord_AddHyperlink(OH_UdmfRecord* pThis, OH_UdsHyperlink* hyperlink)](#oh_udmfrecord_addhyperlink) | - | 增加超链接类型[OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)数据至统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)中。 |
| [int OH_UdmfRecord_AddHtml(OH_UdmfRecord* pThis, OH_UdsHtml* html)](#oh_udmfrecord_addhtml) | - | 增加超文本标记语言类型[OH_UdsHtml](capi-udmf-oh-udshtml.md)数据至统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)中。 |
| [int OH_UdmfRecord_AddAppItem(OH_UdmfRecord* pThis, OH_UdsAppItem* appItem)](#oh_udmfrecord_addappitem) | - | 增加桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)数据至统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)中。 |
| [int OH_UdmfRecord_AddFileUri(OH_UdmfRecord* pThis, OH_UdsFileUri* fileUri)](#oh_udmfrecord_addfileuri) | - | 增加文件Uri类型[OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)数据至统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)中。 |
| [int OH_UdmfRecord_AddPixelMap(OH_UdmfRecord* pThis, OH_UdsPixelMap* pixelMap)](#oh_udmfrecord_addpixelmap) | - | 增加像素图片类型[OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md)数据至统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)中。 |
| [int OH_UdmfRecord_AddArrayBuffer(OH_UdmfRecord* record, const char* type, OH_UdsArrayBuffer* buffer)](#oh_udmfrecord_addarraybuffer) | - | 增加一个ArrayBuffer类型[OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md)的数据至统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)中。 |
| [int OH_UdmfRecord_AddContentForm(OH_UdmfRecord* pThis, OH_UdsContentForm* contentForm)](#oh_udmfrecord_addcontentform) | - | 增加一个内容卡片类型[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)的数据至统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)中。 |
| [char** OH_UdmfRecord_GetTypes(OH_UdmfRecord* pThis, unsigned int* count)](#oh_udmfrecord_gettypes) | - | 获取统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)中所有类型的结果集。 |
| [int OH_UdmfRecord_GetGeneralEntry(OH_UdmfRecord* pThis, const char* typeId, unsigned char** entry, unsigned int* count)](#oh_udmfrecord_getgeneralentry) | - | 获取统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)中的特定类型的数据结果集。 |
| [int OH_UdmfRecord_GetPlainText(OH_UdmfRecord* pThis, OH_UdsPlainText* plainText)](#oh_udmfrecord_getplaintext) | - | 从统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)中获取纯文本类型[OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)数据。 |
| [int OH_UdmfRecord_GetHyperlink(OH_UdmfRecord* pThis, OH_UdsHyperlink* hyperlink)](#oh_udmfrecord_gethyperlink) | - | 从统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)中获取超链接类型[OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)数据。 |
| [int OH_UdmfRecord_GetHtml(OH_UdmfRecord* pThis, OH_UdsHtml* html)](#oh_udmfrecord_gethtml) | - | 从统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)中获取超文本标记语言类型[OH_UdsHtml](capi-udmf-oh-udshtml.md)数据。 |
| [int OH_UdmfRecord_GetAppItem(OH_UdmfRecord* pThis, OH_UdsAppItem* appItem)](#oh_udmfrecord_getappitem) | - | 从统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)中获取桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)数据。 |
| [int OH_UdmfRecord_SetProvider(OH_UdmfRecord* pThis, const char* const* types, unsigned int count, OH_UdmfRecordProvider* provider)](#oh_udmfrecord_setprovider) | - | 将指定类型的统一数据提供者[OH_UdmfRecordProvider](capi-udmf-oh-udmfrecordprovider.md)设置至统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)中。 |
| [int OH_UdmfRecord_GetFileUri(OH_UdmfRecord* pThis, OH_UdsFileUri* fileUri)](#oh_udmfrecord_getfileuri) | - | 从统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)中获取文件Uri类型[OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)数据。 |
| [int OH_UdmfRecord_GetPixelMap(OH_UdmfRecord* pThis, OH_UdsPixelMap* pixelMap)](#oh_udmfrecord_getpixelmap) | - | 从统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)中获取像素图片类型[OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md)数据。 |
| [int OH_UdmfRecord_GetArrayBuffer(OH_UdmfRecord* record, const char* type, OH_UdsArrayBuffer* buffer)](#oh_udmfrecord_getarraybuffer) | - | 从统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)中获取ArrayBuffer类型[OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md)数据。 |
| [int OH_UdmfRecord_GetContentForm(OH_UdmfRecord* pThis, OH_UdsContentForm* contentForm)](#oh_udmfrecord_getcontentform) | - | 从统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)中获取内容卡片类型[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)数据。 |
| [int OH_UdmfData_GetPrimaryPlainText(OH_UdmfData* data, OH_UdsPlainText* plainText)](#oh_udmfdata_getprimaryplaintext) | - | 从统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)中获取第一个纯文本类型[OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)数据。 |
| [int OH_UdmfData_GetPrimaryHtml(OH_UdmfData* data, OH_UdsHtml* html)](#oh_udmfdata_getprimaryhtml) | - | 从统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)中获取第一个超文本标记语言类型[OH_UdsHtml](capi-udmf-oh-udshtml.md)数据。 |
| [int OH_UdmfData_GetRecordCount(OH_UdmfData* data)](#oh_udmfdata_getrecordcount) | - | 获取统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)中包含的所有记录数量。 |
| [OH_UdmfRecord* OH_UdmfData_GetRecord(OH_UdmfData* data, unsigned int index)](#oh_udmfdata_getrecord) | - | 获取统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)中指定位置的数据记录。 |
| [bool OH_UdmfData_IsLocal(OH_UdmfData* data)](#oh_udmfdata_islocal) | - | 检查统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)是否是来自本端设备的数据。 |
| [OH_UdmfProperty* OH_UdmfProperty_Create(OH_UdmfData* unifiedData)](#oh_udmfproperty_create) | - | 创建统一数据对象中数据记录属性[OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)指针及实例对象。当不再需要使用指针时，请使用[OH_UdmfProperty_Destroy](capi-udmf-h.md#oh_udmfproperty_destroy)销毁实例对象，否则会导致内存泄漏。 |
| [void OH_UdmfProperty_Destroy(OH_UdmfProperty* pThis)](#oh_udmfproperty_destroy) | - | 销毁数据属性[OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)指针指向的实例对象。 |
| [const char* OH_UdmfProperty_GetTag(OH_UdmfProperty* pThis)](#oh_udmfproperty_gettag) | - | 从数据属性[OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)中获取用户自定义标签值。 |
| [int64_t OH_UdmfProperty_GetTimestamp(OH_UdmfProperty* pThis)](#oh_udmfproperty_gettimestamp) | - | 从数据属性[OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)中获取时间戳。 |
| [Udmf_ShareOption OH_UdmfProperty_GetShareOption(OH_UdmfProperty* pThis)](#oh_udmfproperty_getshareoption) | - | 从数据属性[OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)中获取设备内适用范围属性。 |
| [int OH_UdmfProperty_GetExtrasIntParam(OH_UdmfProperty* pThis, const char* key, int defaultValue)](#oh_udmfproperty_getextrasintparam) | - | 从数据属性[OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)中获取自定义的附加整型参数。 |
| [const char* OH_UdmfProperty_GetExtrasStringParam(OH_UdmfProperty* pThis, const char* key)](#oh_udmfproperty_getextrasstringparam) | - | 从数据属性[OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)中获取自定义的附加字符串参数。 |
| [int OH_UdmfProperty_SetTag(OH_UdmfProperty* pThis, const char* tag)](#oh_udmfproperty_settag) | - | 设置数据属性[OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)的自定义标签值。 |
| [int OH_UdmfProperty_SetShareOption(OH_UdmfProperty* pThis, Udmf_ShareOption option)](#oh_udmfproperty_setshareoption) | - | 设置数据属性[OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)的设备内适用范围[Udmf_ShareOption](capi-udmf-h.md#udmf_shareoption)参数。 |
| [int OH_UdmfProperty_SetExtrasIntParam(OH_UdmfProperty* pThis, const char* key, int param)](#oh_udmfproperty_setextrasintparam) | - | 设置数据属性[OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)的附加整型参数。 |
| [int OH_UdmfProperty_SetExtrasStringParam(OH_UdmfProperty* pThis, const char* key, const char* param)](#oh_udmfproperty_setextrasstringparam) | - | 设置数据属性[OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)的附加字符串参数。 |
| [OH_UdmfOptions* OH_UdmfOptions_Create()](#oh_udmfoptions_create) | - | 创建指向[OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)实例的指针。 |
| [void OH_UdmfOptions_Destroy(OH_UdmfOptions* pThis)](#oh_udmfoptions_destroy) | - | 销毁指向[OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)实例的指针。 |
| [const char* OH_UdmfOptions_GetKey(OH_UdmfOptions* pThis)](#oh_udmfoptions_getkey) | - | 从数据操作选项[OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)实例中获取数据的唯一标识符信息。 |
| [int OH_UdmfOptions_SetKey(OH_UdmfOptions* pThis, const char* key)](#oh_udmfoptions_setkey) | - | 设置数据操作选项[OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)实例中的数据的唯一标识符内容参数。 |
| [Udmf_Intention OH_UdmfOptions_GetIntention(OH_UdmfOptions* pThis)](#oh_udmfoptions_getintention) | - | 从数据操作选项[OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)实例中获取数据通路信息。 |
| [int OH_UdmfOptions_SetIntention(OH_UdmfOptions* pThis, Udmf_Intention intention)](#oh_udmfoptions_setintention) | - | 设置数据操作选项[OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)实例中的数据通路内容参数。 |
| [int OH_UdmfOptions_Reset(OH_UdmfOptions* pThis)](#oh_udmfoptions_reset) | - | 重置数据操作选项[OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)实例为空。 |
| [int OH_Udmf_GetUnifiedData(const char* key, Udmf_Intention intention, OH_UdmfData* unifiedData)](#oh_udmf_getunifieddata) | - | 从统一数据管理框架数据库中获取统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)数据。 |
| [int OH_Udmf_GetUnifiedDataByOptions(OH_UdmfOptions* options, OH_UdmfData** dataArray, unsigned int* dataSize)](#oh_udmf_getunifieddatabyoptions) | - | 通过数据通路类型从统一数据管理框架数据库中获取统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)数据。 |
| [int OH_Udmf_SetUnifiedData(Udmf_Intention intention, OH_UdmfData* unifiedData, char* key, unsigned int keyLen)](#oh_udmf_setunifieddata) | - | 从统一数据管理框架数据库中写入统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)数据。 |
| [int OH_Udmf_SetUnifiedDataByOptions(OH_UdmfOptions* options, OH_UdmfData *unifiedData, char *key, unsigned int keyLen)](#oh_udmf_setunifieddatabyoptions) | - | 从统一数据管理框架数据库中写入统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)数据。 |
| [int OH_Udmf_UpdateUnifiedData(OH_UdmfOptions* options, OH_UdmfData* unifiedData)](#oh_udmf_updateunifieddata) | - | 对统一数据管理框架数据库中的统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)数据进行数据更改。 |
| [int OH_Udmf_DeleteUnifiedData(OH_UdmfOptions* options, OH_UdmfData** dataArray, unsigned int* dataSize)](#oh_udmf_deleteunifieddata) | - | 删除统一数据管理框架数据库中的统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)数据。 |
| [void OH_Udmf_DestroyDataArray(OH_UdmfData** dataArray, unsigned int dataSize)](#oh_udmf_destroydataarray) | - | 销毁数据数组内存。 |
| [int OH_UdmfProgressInfo_GetProgress(OH_Udmf_ProgressInfo* progressInfo)](#oh_udmfprogressinfo_getprogress) | - | 从进度信息[OH_Udmf_ProgressInfo](capi-udmf-oh-udmf-progressinfo.md)中获取进度百分比数据。 |
| [int OH_UdmfProgressInfo_GetStatus(OH_Udmf_ProgressInfo* progressInfo)](#oh_udmfprogressinfo_getstatus) | - | 从进度信息[OH_Udmf_ProgressInfo](capi-udmf-oh-udmf-progressinfo.md)中获取状态信息。 |
| [OH_UdmfGetDataParams* OH_UdmfGetDataParams_Create()](#oh_udmfgetdataparams_create) | - | 创建异步获取UDMF数据的请求参数[OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md)指针及实例对象。<br>当不再需要使用指针时，请使用[OH_UdmfGetDataParams_Destroy](capi-udmf-h.md#oh_udmfgetdataparams_destroy)销毁实例对象，否则会导致内存泄漏。 |
| [void OH_UdmfGetDataParams_Destroy(OH_UdmfGetDataParams* pThis)](#oh_udmfgetdataparams_destroy) | - | 销毁异步请求参数[OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md)指针指向的实例对象。 |
| [void OH_UdmfGetDataParams_SetDestUri(OH_UdmfGetDataParams* params, const char* destUri)](#oh_udmfgetdataparams_setdesturi) | - | 设置异步请求参数[OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md)中的目标路径。<br>若设置了目标路径，会将文件类型的数据进行拷贝到指定路径。回调中获取到的文件类型数据会被替换为目标路径的URI。<br>若不设置目标路径，则不会执行拷贝文件操作。回调中获取到的文件类型数据为源端路径URI。<br>若应用涉及复杂文件处理策略，或需要将文件拷贝在多个路径下时，建议不设置此参数，由应用自行完成文件拷贝相关处理。 |
| [void OH_UdmfGetDataParams_SetFileConflictOptions(OH_UdmfGetDataParams* params, const Udmf_FileConflictOptions options)](#oh_udmfgetdataparams_setfileconflictoptions) | - | 设置异步请求参数[OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md)中的文件冲突选项。 |
| [void OH_UdmfGetDataParams_SetProgressIndicator(OH_UdmfGetDataParams* params, const Udmf_ProgressIndicator progressIndicator)](#oh_udmfgetdataparams_setprogressindicator) | - | 设置异步请求参数[OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md)中的进度条指示选项。 |
| [void OH_UdmfGetDataParams_SetDataProgressListener(OH_UdmfGetDataParams* params, const OH_Udmf_DataProgressListener dataProgressListener)](#oh_udmfgetdataparams_setdataprogresslistener) | - | 设置异步请求参数[OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md)中的监听回调函数。 |
| [Udmf_Visibility OH_UdmfOptions_GetVisibility(OH_UdmfOptions* pThis)](#oh_udmfoptions_getvisibility) | - | 从数据操作选项[OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)实例中获取数据可见性等级。 |
| [int OH_UdmfOptions_SetVisibility(OH_UdmfOptions* pThis, Udmf_Visibility visibility)](#oh_udmfoptions_setvisibility) | - | 设置数据操作选项[OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)实例中的数据可见性等级。 |
| [typedef OH_UdmfData* (\*OH_Udmf_DataLoadHandler)(OH_UdmfDataLoadInfo* acceptableInfo)](#oh_udmf_dataloadhandler) | OH_Udmf_DataLoadHandler | 表示用于加载数据的回调函数。 |
| [OH_UdmfDataLoadParams* OH_UdmfDataLoadParams_Create()](#oh_udmfdataloadparams_create) | - | 创建指向数据加载参数[OH_UdmfDataLoadParams](capi-udmf-oh-udmfdataloadparams.md)实例的指针。 |
| [void OH_UdmfDataLoadParams_Destroy(OH_UdmfDataLoadParams* pThis)](#oh_udmfdataloadparams_destroy) | - | 销毁数据加载参数[OH_UdmfDataLoadParams](capi-udmf-oh-udmfdataloadparams.md)指针指向的实例对象。 |
| [void OH_UdmfDataLoadParams_SetLoadHandler(OH_UdmfDataLoadParams* params, const OH_Udmf_DataLoadHandler dataLoadHandler)](#oh_udmfdataloadparams_setloadhandler) | - | 设置数据加载参数[OH_UdmfDataLoadParams](capi-udmf-oh-udmfdataloadparams.md)中的数据加载处理函数。 |
| [void OH_UdmfDataLoadParams_SetDataLoadInfo(OH_UdmfDataLoadParams* params, OH_UdmfDataLoadInfo* dataLoadInfo)](#oh_udmfdataloadparams_setdataloadinfo) | - | 设置数据加载参数[OH_UdmfDataLoadParams](capi-udmf-oh-udmfdataloadparams.md)中的数据加载信息。 |
| [OH_UdmfDataLoadInfo* OH_UdmfDataLoadInfo_Create()](#oh_udmfdataloadinfo_create) | - | 创建指向数据加载信息[OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md)实例的指针。 |
| [void OH_UdmfDataLoadInfo_Destroy(OH_UdmfDataLoadInfo* dataLoadInfo)](#oh_udmfdataloadinfo_destroy) | - | 销毁数据加载信息[OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md)指针指向的实例对象。 |
| [char** OH_UdmfDataLoadInfo_GetTypes(OH_UdmfDataLoadInfo* dataLoadInfo, unsigned int* count)](#oh_udmfdataloadinfo_gettypes) | - | 从数据加载信息[OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md)中获取数据类型列表。 |
| [void OH_UdmfDataLoadInfo_SetType(OH_UdmfDataLoadInfo* dataLoadInfo, const char* type)](#oh_udmfdataloadinfo_settype) | - | 设置数据加载信息[OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md)中的数据类型。 |
| [int OH_UdmfDataLoadInfo_GetRecordCount(OH_UdmfDataLoadInfo* dataLoadInfo)](#oh_udmfdataloadinfo_getrecordcount) | - | 获取数据加载信息[OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md)中的记录数量。 |
| [void OH_UdmfDataLoadInfo_SetRecordCount(OH_UdmfDataLoadInfo* dataLoadInfo, unsigned int recordCount)](#oh_udmfdataloadinfo_setrecordcount) | - | 设置数据加载信息[OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md)中的记录数量。 |

## 枚举类型说明

### Udmf_Intention

```
enum Udmf_Intention
```

**描述**

描述UDMF数据通路枚举类型。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| UDMF_INTENTION_DRAG | 拖拽数据通路。 |
| UDMF_INTENTION_PASTEBOARD | 剪贴板数据通路。 |
| UDMF_INTENTION_DATA_HUB | 公共数据通路。<br>**起始版本：** 20 |
| UDMF_INTENTION_SYSTEM_SHARE | 系统分享数据通路。<br>**起始版本：** 20 |
| UDMF_INTENTION_PICKER | Picker数据通路。<br>**起始版本：** 20 |
| UDMF_INTENTION_MENU | 菜单数据通路。<br>**起始版本：** 20 |

### Udmf_ShareOption

```
enum Udmf_ShareOption
```

**描述**

UDMF支持的设备内使用范围类型枚举。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| SHARE_OPTIONS_INVALID | 表示不合法的使用范围类型。 |
| SHARE_OPTIONS_IN_APP | 表示允许在本设备同应用内使用。 |
| SHARE_OPTIONS_CROSS_APP | 表示允许在本设备内跨应用使用。 |

### Udmf_FileConflictOptions

```
enum Udmf_FileConflictOptions
```

**描述**

定义文件拷贝冲突时的选项。

**起始版本：** 15

| 枚举项 | 描述 |
| -- | -- |
| UDMF_OVERWRITE = 0 | 目标路径存在同文件名时覆盖。若不配置策略，默认使用改策略。 |
| UDMF_SKIP = 1 | 目标路径存在同文件名时跳过。 |

### Udmf_ProgressIndicator

```
enum Udmf_ProgressIndicator
```

**描述**

定义进度条指示选项，可选择是否采用系统默认进度显示。

**起始版本：** 15

| 枚举项 | 描述 |
| -- | -- |
| UDMF_NONE = 0 | 不采用系统默认进度显示。 |
| UDMF_DEFAULT = 1 | 采用系统默认进度显示，500ms内获取数据完成将不会拉起默认进度条。 |

### Udmf_Visibility

```
enum Udmf_Visibility
```

**描述**

定义数据的可见性等级。

**起始版本：** 20

| 枚举项 | 描述 |
| -- | -- |
| UDMF_ALL | 可见性等级，所有应用可见。 |
| UDMF_OWN_PROCESS | 可见性等级，仅数据提供者可见。 |

## 函数说明

### OH_UdmfGetDataParams_SetAcceptableInfo()

```
void OH_UdmfGetDataParams_SetAcceptableInfo(OH_UdmfGetDataParams* params, OH_UdmfDataLoadInfo* acceptableInfo)
```

**描述**

设置异步请求参数[OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md)中可接收的数据描述信息。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md)* params | 表示指向[OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md)实例的指针。 |
| [OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md)* acceptableInfo | 表示指向[OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md)实例的指针。 |

### OH_UdmfDataLoadParams_Create()

```
OH_UdmfDataLoadParams* OH_UdmfDataLoadParams_Create()
```

**描述**

创建指向数据加载参数[OH_UdmfDataLoadParams](capi-udmf-oh-udmfdataloadparams.md)实例的指针。

**起始版本：** 20

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_UdmfDataLoadParams](capi-udmf-oh-udmfdataloadparams.md)* | 如果创建成功，返回一个指向数据加载参数[OH_UdmfDataLoadParams](capi-udmf-oh-udmfdataloadparams.md)实例的指针；否则返回nullptr。 |

### OH_UdmfDataLoadParams_Destroy()

```
void OH_UdmfDataLoadParams_Destroy(OH_UdmfDataLoadParams* pThis)
```

**描述**

销毁数据加载参数[OH_UdmfDataLoadParams](capi-udmf-oh-udmfdataloadparams.md)指针指向的实例对象。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfDataLoadParams](capi-udmf-oh-udmfdataloadparams.md)* pThis | 表示指向数据加载参数[OH_UdmfDataLoadParams](capi-udmf-oh-udmfdataloadparams.md)实例的指针。 |

### OH_UdmfDataLoadParams_SetLoadHandler()

```
void OH_UdmfDataLoadParams_SetLoadHandler(OH_UdmfDataLoadParams* params, const OH_Udmf_DataLoadHandler dataLoadHandler)
```

**描述**

设置数据加载参数[OH_UdmfDataLoadParams](capi-udmf-oh-udmfdataloadparams.md)中的数据加载处理函数。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfDataLoadParams](capi-udmf-oh-udmfdataloadparams.md)* params | 表示指向数据加载参数[OH_UdmfDataLoadParams](capi-udmf-oh-udmfdataloadparams.md)实例的指针。 |
| [const OH_Udmf_DataLoadHandler](capi-udmf-h.md#oh_udmf_dataloadhandler) dataLoadHandler | 表示用户定义的数据加载处理函数。 |

### OH_UdmfDataLoadParams_SetDataLoadInfo()

```
void OH_UdmfDataLoadParams_SetDataLoadInfo(OH_UdmfDataLoadParams* params, OH_UdmfDataLoadInfo* dataLoadInfo)
```

**描述**

设置数据加载参数[OH_UdmfDataLoadParams](capi-udmf-oh-udmfdataloadparams.md)中的数据加载信息。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfDataLoadParams](capi-udmf-oh-udmfdataloadparams.md)* params | 表示指向数据加载参数[OH_UdmfDataLoadParams](capi-udmf-oh-udmfdataloadparams.md)实例的指针。 |
| [OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md)* dataLoadInfo | 表示指向数据加载信息[OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md)实例的指针。 |

### OH_UdmfDataLoadInfo_Create()

```
OH_UdmfDataLoadInfo* OH_UdmfDataLoadInfo_Create()
```

**描述**

创建指向数据加载信息[OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md)实例的指针。

**起始版本：** 20

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md)* | 如果创建成功，返回一个指向数据加载信息[OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md)实例的指针；否则返回nullptr。 |

### OH_UdmfDataLoadInfo_Destroy()

```
void OH_UdmfDataLoadInfo_Destroy(OH_UdmfDataLoadInfo* dataLoadInfo)
```

**描述**

销毁数据加载信息[OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md)指针指向的实例对象。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md)* dataLoadInfo | 表示指向数据加载信息[OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md)实例的指针。 |

### OH_UdmfDataLoadInfo_GetTypes()

```
char** OH_UdmfDataLoadInfo_GetTypes(OH_UdmfDataLoadInfo* dataLoadInfo, unsigned int* count)
```

**描述**

从数据加载信息[OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md)中获取数据类型列表。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md)* dataLoadInfo | 表示指向数据加载信息[OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md)实例的指针。 |
| unsigned int* count | 返回的数据类型数量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| char** | 返回数据类型的字符串数组。 |

### OH_UdmfDataLoadInfo_SetType()

```
void OH_UdmfDataLoadInfo_SetType(OH_UdmfDataLoadInfo* dataLoadInfo, const char* type)
```

**描述**

设置数据加载信息[OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md)中的数据类型。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md)* dataLoadInfo | 表示指向数据加载信息[OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md)实例的指针。 |
| const char* type | 表示数据类型的字符串。 |

### OH_UdmfDataLoadInfo_GetRecordCount()

```
int OH_UdmfDataLoadInfo_GetRecordCount(OH_UdmfDataLoadInfo* dataLoadInfo)
```

**描述**

获取数据加载信息[OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md)中的记录数量。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md)* dataLoadInfo | 表示指向数据加载信息[OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回记录的数量。 |

### OH_UdmfDataLoadInfo_SetRecordCount()

```
void OH_UdmfDataLoadInfo_SetRecordCount(OH_UdmfDataLoadInfo* dataLoadInfo, unsigned int recordCount)
```

**描述**

设置数据加载信息[OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md)中的记录数量。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md)* dataLoadInfo | 表示指向数据加载信息[OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md)实例的指针。 |
| unsigned int recordCount | 表示记录的数量。 |

### OH_Udmf_DataLoadHandler()

```
typedef OH_UdmfData* (*OH_Udmf_DataLoadHandler)(OH_UdmfDataLoadInfo* acceptableInfo)
```

**描述**

表示用于加载数据的回调函数。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md)* acceptableInfo | 表示接收端可接收的数据类型和数量信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_UdmfData](capi-udmf-oh-udmfdata.md)* (*OH_Udmf_DataLoadHandler) | 返回待加载的数据。 |

### OH_UdmfOptions_GetVisibility()

```
Udmf_Visibility OH_UdmfOptions_GetVisibility(OH_UdmfOptions* pThis)
```

**描述**

从数据操作选项[OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)实例中获取数据可见性等级。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)* pThis | 指向数据操作选项[OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Udmf_Visibility](capi-udmf-h.md#udmf_visibility) | 返回数据可见性等级[Udmf_Visibility](capi-udmf-h.md#udmf_visibility)的值。 |

### OH_UdmfOptions_SetVisibility()

```
int OH_UdmfOptions_SetVisibility(OH_UdmfOptions* pThis, Udmf_Visibility visibility)
```

**描述**

设置数据操作选项[OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)实例中的数据可见性等级。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)* pThis | 指向数据操作选项[OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)实例的指针。 |
| [Udmf_Visibility](capi-udmf-h.md#udmf_visibility) visibility | 数据可见性等级[Udmf_Visibility](capi-udmf-h.md#udmf_visibility)参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行结果。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br> 若返回UDMF_E_OK，表示执行成功。<br> 若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### UDMF_KEY_BUFFER_LEN()

```
UDMF_KEY_BUFFER_LEN (512)
```

**描述**

统一数据对象唯一标识符最小空间长度。

**起始版本：** 12

### OH_Udmf_DataProgressListener()

```
typedef void (*OH_Udmf_DataProgressListener)(OH_Udmf_ProgressInfo* progressInfo, OH_UdmfData* data)
```

**描述**

定义获取进度信息和数据的监听回调函数。<br>使用时需要判断数据是否返回空指针。只有当进度达到100%时，才会返回数据。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Udmf_ProgressInfo](capi-udmf-oh-udmf-progressinfo.md)* progressInfo | 进度信息，作为出参使用。 |
| [OH_UdmfData](capi-udmf-oh-udmfdata.md)* data | 返回的统一数据对象，作为出参使用。 |

### OH_UdmfData_Create()

```
OH_UdmfData* OH_UdmfData_Create()
```

**描述**

创建统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)指针及实例对象。当不再需要使用指针时，请使用[OH_UdmfData_Destroy](capi-udmf-h.md#oh_udmfdata_destroy)销毁实例对象，否则会导致内存泄漏。

**起始版本：** 12

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_UdmfData](capi-udmf-oh-udmfdata.md)* | 执行成功则返回一个指向统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)实例对象的指针，否则返回nullptr。 |

**参考：**

OH_UdmfData

### OH_UdmfData_Destroy()

```
void OH_UdmfData_Destroy(OH_UdmfData* pThis)
```

**描述**

销毁统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)指针指向的实例对象。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfData](capi-udmf-oh-udmfdata.md)* pThis | 表示指向统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)实例的指针。 |

**参考：**

OH_UdmfData

### OH_UdmfData_AddRecord()

```
int OH_UdmfData_AddRecord(OH_UdmfData* pThis, OH_UdmfRecord* record)
```

**描述**

添加一个数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)到统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)中。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfData](capi-udmf-oh-udmfdata.md)* pThis | 表示指向统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)实例的指针。 |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* record | 表示指向统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_UdmfData_HasType()

```
bool OH_UdmfData_HasType(OH_UdmfData* pThis, const char* type)
```

**描述**

检查统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)中是否存在指定类型。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfData](capi-udmf-oh-udmfdata.md)* pThis | 表示指向统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)实例的指针。 |
| const char* type | 表示指定类型的字符串指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回查找类型的状态。返回false表示不存在指定类型，返回true表示存在指定类型。 |

### OH_UdmfData_GetTypes()

```
char** OH_UdmfData_GetTypes(OH_UdmfData* pThis, unsigned int* count)
```

**描述**

获取统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)中包含的所有类型结果集。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfData](capi-udmf-oh-udmfdata.md)* pThis | 表示指向统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)实例的指针。 |
| unsigned int* count | 该参数是输出参数，结果集中的类型数量会写入该变量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| char** | 执行成功时返回统一数据对象的类型结果集，否则返回nullptr。 |

### OH_UdmfData_GetRecords()

```
OH_UdmfRecord** OH_UdmfData_GetRecords(OH_UdmfData* pThis, unsigned int* count)
```

**描述**

获取统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)中包含的所有记录结果集。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfData](capi-udmf-oh-udmfdata.md)* pThis | 表示指向统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)实例的指针。 |
| unsigned int* count | 该参数是输出参数，结果集中的记录数量会写入该变量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)** | 执行成功时返回统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)结果集，否则返回nullptr。 |

### UdmfData_Finalize()

```
typedef void (*UdmfData_Finalize)(void* context)
```

**描述**

定义用于释放上下文的回调函数，统一数据提供者对象销毁时触发。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| void* context | 要释放的上下文指针。 |

### OH_UdmfRecordProvider_Create()

```
OH_UdmfRecordProvider* OH_UdmfRecordProvider_Create()
```

**描述**

创建一个统一数据提供者[OH_UdmfRecordProvider](capi-udmf-oh-udmfrecordprovider.md)指针及实例对象。当不再需要使用指针时，请使用[OH_UdmfRecordProvider_Destroy](capi-udmf-h.md#oh_udmfrecordprovider_destroy)销毁实例对象，否则会导致内存泄漏。

**起始版本：** 13

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_UdmfRecordProvider](capi-udmf-oh-udmfrecordprovider.md)* | 执行成功时返回一个指向统一数据提供者[OH_UdmfRecordProvider](capi-udmf-oh-udmfrecordprovider.md)实例对象的指针，否则返回nullptr。 |

### OH_UdmfRecordProvider_Destroy()

```
int OH_UdmfRecordProvider_Destroy(OH_UdmfRecordProvider* provider)
```

**描述**

销毁统一数据提供者[OH_UdmfRecordProvider](capi-udmf-oh-udmfrecordprovider.md)指针指向的实例对象。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfRecordProvider](capi-udmf-oh-udmfrecordprovider.md)* provider | 表示指向统一数据提供者对象[OH_UdmfRecordProvider](capi-udmf-oh-udmfrecordprovider.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_UdmfRecordProvider_GetData()

```
typedef void* (*OH_UdmfRecordProvider_GetData)(void* context, const char* type)
```

**描述**

定义用于按类型获取数据的回调函数。当从OH_UdmfRecord中获取数据时，会触发此回调函数，得到的数据就是这个回调函数返回的数据。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| void* context | 用[OH_UdmfRecordProvider_SetData](capi-udmf-h.md#oh_udmfrecordprovider_setdata)设置的上下文指针。 |
|  const char* type | 要获取的数据类型。详细类型信息见[udmf_meta.h](capi-udmf-meta-h.md)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| void* | 需要返回一个标准化数据。 |

### OH_UdmfRecordProvider_SetData()

```
int OH_UdmfRecordProvider_SetData(OH_UdmfRecordProvider* provider, void* context, const OH_UdmfRecordProvider_GetData callback, const UdmfData_Finalize finalize)
```

**描述**

设置统一数据提供者的数据提供回调函数。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfRecordProvider](capi-udmf-oh-udmfrecordprovider.md)* provider | 指向统一数据提供者[OH_UdmfRecordProvider](capi-udmf-oh-udmfrecordprovider.md)实例对象的指针。 |
| void* context | 上下文指针，将作为第一个参数传入[OH_UdmfRecordProvider_GetData](capi-udmf-h.md#oh_udmfrecordprovider_getdata)。 |
| const [OH_UdmfRecordProvider_GetData](#oh_udmfrecordprovider_getdata) callback | 获取数据的回调函数。详见：[OH_UdmfRecordProvider_GetData](capi-udmf-h.md#oh_udmfrecordprovider_getdata)。 |
| const [UdmfData_Finalize](#udmfdata_finalize) finalize | 可选的回调函数，可以用于统一数据提供者销毁时释放上下文数据。详见：[UdmfData_Finalize](capi-udmf-h.md#udmfdata_finalize)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_UdmfRecord_Create()

```
OH_UdmfRecord* OH_UdmfRecord_Create()
```

**描述**

创建统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)指针及实例对象。当不再需要使用指针时，请使用[OH_UdmfRecord_Destroy](capi-udmf-h.md#oh_udmfrecord_destroy)销毁实例对象，否则会导致内存泄漏。

**起始版本：** 12

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* | 执行成功则返回一个指向统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)实例对象的指针，否则返回nullptr。 |

### OH_UdmfRecord_Destroy()

```
void OH_UdmfRecord_Destroy(OH_UdmfRecord* pThis)
```

**描述**

销毁统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)指针指向的实例对象。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* pThis | 表示指向统一数据对象[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)实例的指针。 |

### OH_UdmfRecord_AddGeneralEntry()

```
int OH_UdmfRecord_AddGeneralEntry(OH_UdmfRecord* pThis, const char* typeId, unsigned char* entry, unsigned int count)
```

**描述**

添加用户自定义的通用数据至统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)中。对于已定义UDS的类型（比如PlainText、Link、Pixelmap等）不可使用该接口。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* pThis | 表示指向统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)实例的指针。 |
| const char* typeId | 表示数据类型标识，为和系统定义的类型进行区分，建议以'ApplicationDefined'开头。 |
| unsigned char* entry | 表示用户自定义数据。 |
| unsigned int count | 表示用户自定义数据的大小。数据大小不超过4KB。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_UdmfRecord_AddPlainText()

```
int OH_UdmfRecord_AddPlainText(OH_UdmfRecord* pThis, OH_UdsPlainText* plainText)
```

**描述**

增加纯文本类型[OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)数据至统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)中。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* pThis | 表示指向统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)实例的指针。 |
| [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)* plainText | 表示指向纯文本类型[OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_UdmfRecord_AddHyperlink()

```
int OH_UdmfRecord_AddHyperlink(OH_UdmfRecord* pThis, OH_UdsHyperlink* hyperlink)
```

**描述**

增加超链接类型[OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)数据至统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)中。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* pThis | 表示指向统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)实例的指针。 |
| [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)* hyperlink | 表示指向超链接类型[OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_UdmfRecord_AddHtml()

```
int OH_UdmfRecord_AddHtml(OH_UdmfRecord* pThis, OH_UdsHtml* html)
```

**描述**

增加超文本标记语言类型[OH_UdsHtml](capi-udmf-oh-udshtml.md)数据至统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)中。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* pThis | 表示指向统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)实例的指针。 |
| [OH_UdsHtml](capi-udmf-oh-udshtml.md)* html | 表示指向超文本标记语言类型[OH_UdsHtml](capi-udmf-oh-udshtml.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_UdmfRecord_AddAppItem()

```
int OH_UdmfRecord_AddAppItem(OH_UdmfRecord* pThis, OH_UdsAppItem* appItem)
```

**描述**

增加桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)数据至统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)中。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* pThis | 表示指向统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)实例的指针。 |
| [OH_UdsAppItem](capi-udmf-oh-udsappitem.md)* appItem | 表示指向桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_UdmfRecord_AddFileUri()

```
int OH_UdmfRecord_AddFileUri(OH_UdmfRecord* pThis, OH_UdsFileUri* fileUri)
```

**描述**

增加文件Uri类型[OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)数据至统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)中。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* pThis | 表示指向统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)实例的指针。 |
| [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)* fileUri | 表示指向文件Uri类型[OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_UdmfRecord_AddPixelMap()

```
int OH_UdmfRecord_AddPixelMap(OH_UdmfRecord* pThis, OH_UdsPixelMap* pixelMap)
```

**描述**

增加像素图片类型[OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md)数据至统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)中。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* pThis | 表示指向统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)实例的指针。 |
| [OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md)* pixelMap | 表示指向像素图片类型[OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_UdmfRecord_AddArrayBuffer()

```
int OH_UdmfRecord_AddArrayBuffer(OH_UdmfRecord* record, const char* type, OH_UdsArrayBuffer* buffer)
```

**描述**

增加一个ArrayBuffer类型[OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md)的数据至统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)中。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* record | 表示指向统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)实例的指针。 |
| const char* type | 表示自定义的ArrayBuffer数据的数据类型标识，不可与已有的数据类型标识重复。 |
| [OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md)* buffer | 表示指向ArrayBuffer类型[OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_UdmfRecord_AddContentForm()

```
int OH_UdmfRecord_AddContentForm(OH_UdmfRecord* pThis, OH_UdsContentForm* contentForm)
```

**描述**

增加一个内容卡片类型[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)的数据至统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)中。

**起始版本：** 14


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* pThis | 表示指向统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)实例的指针。 |
| [OH_UdsContentForm](capi-udmf-oh-udscontentform.md)* contentForm | 表示指向内容卡片类型[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_UdmfRecord_GetTypes()

```
char** OH_UdmfRecord_GetTypes(OH_UdmfRecord* pThis, unsigned int* count)
```

**描述**

获取统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)中所有类型的结果集。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* pThis | 表示指向统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)实例的指针。 |
| unsigned int* count | 该参数是输出参数，结果集中的类型数量会写入该变量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| char** | 执行成功时返回类型列表，否则返回nullptr。 |

### OH_UdmfRecord_GetGeneralEntry()

```
int OH_UdmfRecord_GetGeneralEntry(OH_UdmfRecord* pThis, const char* typeId, unsigned char** entry, unsigned int* count)
```

**描述**

获取统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)中的特定类型的数据结果集。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* pThis | 表示指向统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)实例的指针。 |
| const char* typeId | 表示数据类型标识。 |
| unsigned char** entry | 该参数是输出参数，结果集中数据的具体信息会写入该变量。 |
| unsigned int* count | 该参数是输出参数，结果集中的数据长度会写入该变量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。<br>若返回UDMF_ERR，表示内部数据错误。 |

### OH_UdmfRecord_GetPlainText()

```
int OH_UdmfRecord_GetPlainText(OH_UdmfRecord* pThis, OH_UdsPlainText* plainText)
```

**描述**

从统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)中获取纯文本类型[OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)数据。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* pThis | 表示指向统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)实例的指针。 |
| [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)* plainText | 该参数是输出参数，表示指向纯文本类型[OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。<br>若返回UDMF_ERR，表示内部数据错误。 |

### OH_UdmfRecord_GetHyperlink()

```
int OH_UdmfRecord_GetHyperlink(OH_UdmfRecord* pThis, OH_UdsHyperlink* hyperlink)
```

**描述**

从统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)中获取超链接类型[OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)数据。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* pThis | 表示指向统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)实例的指针。 |
| [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)* hyperlink | 该参数是输出参数，表示指向超链接类型[OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。<br>若返回UDMF_ERR，表示内部数据错误。 |

### OH_UdmfRecord_GetHtml()

```
int OH_UdmfRecord_GetHtml(OH_UdmfRecord* pThis, OH_UdsHtml* html)
```

**描述**

从统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)中获取超文本标记语言类型[OH_UdsHtml](capi-udmf-oh-udshtml.md)数据。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* pThis | 表示指向统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)实例的指针。 |
| [OH_UdsHtml](capi-udmf-oh-udshtml.md)* html | 该参数是输出参数，表示指向超文本标记语言类型[OH_UdsHtml](capi-udmf-oh-udshtml.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。<br>若返回UDMF_ERR，表示内部数据错误。 |

### OH_UdmfRecord_GetAppItem()

```
int OH_UdmfRecord_GetAppItem(OH_UdmfRecord* pThis, OH_UdsAppItem* appItem)
```

**描述**

从统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)中获取桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)数据。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* pThis | 表示指向统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)实例的指针。 |
| [OH_UdsAppItem](capi-udmf-oh-udsappitem.md)* appItem | 该参数是输出参数，表示指向桌面图标类型[OH_UdsAppItem](capi-udmf-oh-udsappitem.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。<br>若返回UDMF_ERR，表示内部数据错误。 |

### OH_UdmfRecord_SetProvider()

```
int OH_UdmfRecord_SetProvider(OH_UdmfRecord* pThis, const char* const* types, unsigned int count, OH_UdmfRecordProvider* provider)
```

**描述**

将指定类型的统一数据提供者[OH_UdmfRecordProvider](capi-udmf-oh-udmfrecordprovider.md)设置至统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)中。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* pThis | 表示指向统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)实例的指针。 |
| const char* const* types | 表示一组指定的要提供的数据类型。 |
| unsigned int count | 表示指定的数据类型的数量。 |
| [OH_UdmfRecordProvider](capi-udmf-oh-udmfrecordprovider.md)* provider | 表示指向统一数据提供者对象[OH_UdmfRecordProvider](capi-udmf-oh-udmfrecordprovider.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_UdmfRecord_GetFileUri()

```
int OH_UdmfRecord_GetFileUri(OH_UdmfRecord* pThis, OH_UdsFileUri* fileUri)
```

**描述**

从统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)中获取文件Uri类型[OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)数据。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* pThis | 表示指向统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)实例的指针。 |
| [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)* fileUri | 该参数是输出参数，表示指向文件Uri类型[OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_UdmfRecord_GetPixelMap()

```
int OH_UdmfRecord_GetPixelMap(OH_UdmfRecord* pThis, OH_UdsPixelMap* pixelMap)
```

**描述**

从统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)中获取像素图片类型[OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md)数据。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* pThis | 表示指向统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)实例的指针。 |
| [OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md)* pixelMap | 该参数是输出参数，表示指向像素图片类型[OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_UdmfRecord_GetArrayBuffer()

```
int OH_UdmfRecord_GetArrayBuffer(OH_UdmfRecord* record, const char* type, OH_UdsArrayBuffer* buffer)
```

**描述**

从统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)中获取ArrayBuffer类型[OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md)数据。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* record | 表示指向统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)实例的指针。 |
| const char* type | 表示要获取的ArrayBuffer类型数据的数据类型标识。 |
| [OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md)* buffer | 该参数是输出参数，表示指向ArrayBuffer类型[OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_UdmfRecord_GetContentForm()

```
int OH_UdmfRecord_GetContentForm(OH_UdmfRecord* pThis, OH_UdsContentForm* contentForm)
```

**描述**

从统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)中获取内容卡片类型[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)数据。

**起始版本：** 14


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* pThis | 表示指向统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)实例的指针。 |
| [OH_UdsContentForm](capi-udmf-oh-udscontentform.md)* contentForm | 该参数是输出参数，表示指向内容卡片类型[OH_UdsContentForm](capi-udmf-oh-udscontentform.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_UdmfData_GetPrimaryPlainText()

```
int OH_UdmfData_GetPrimaryPlainText(OH_UdmfData* data, OH_UdsPlainText* plainText)
```

**描述**

从统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)中获取第一个纯文本类型[OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)数据。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfData](capi-udmf-oh-udmfdata.md)* data | 表示指向统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)实例的指针。 |
| [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)* plainText | 该参数是输出参数，表示指向纯文本类型[OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_UdmfData_GetPrimaryHtml()

```
int OH_UdmfData_GetPrimaryHtml(OH_UdmfData* data, OH_UdsHtml* html)
```

**描述**

从统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)中获取第一个超文本标记语言类型[OH_UdsHtml](capi-udmf-oh-udshtml.md)数据。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfData](capi-udmf-oh-udmfdata.md)* data | 表示指向统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)实例的指针。 |
| [OH_UdsHtml](capi-udmf-oh-udshtml.md)* html | 该参数是输出参数，表示指向超文本标记语言类型[OH_UdsHtml](capi-udmf-oh-udshtml.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_UdmfData_GetRecordCount()

```
int OH_UdmfData_GetRecordCount(OH_UdmfData* data)
```

**描述**

获取统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)中包含的所有记录数量。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfData](capi-udmf-oh-udmfdata.md)* data | 表示指向统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)实例的指针。|

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回统一数据对象[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)的数量。 |

### OH_UdmfData_GetRecord()

```
OH_UdmfRecord* OH_UdmfData_GetRecord(OH_UdmfData* data, unsigned int index)
```

**描述**

获取统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)中指定位置的数据记录。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfData](capi-udmf-oh-udmfdata.md)* data | 表示指向统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)实例的指针。 |
| unsigned int index | 表示要获取的统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)在统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)中的下标。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* | 执行成功时返回统一数据记录[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)实例对象的指针，否则返回nullptr。 |

### OH_UdmfData_IsLocal()

```
bool OH_UdmfData_IsLocal(OH_UdmfData* data)
```

**描述**

检查统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)是否是来自本端设备的数据。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfData](capi-udmf-oh-udmfdata.md)* data | 表示指向统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回数据是否是来自本端设备。返回true表示来自本端设备，返回false表示来自远端设备。 |

### OH_UdmfProperty_Create()

```
OH_UdmfProperty* OH_UdmfProperty_Create(OH_UdmfData* unifiedData)
```

**描述**

创建统一数据对象中数据记录属性[OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)指针及实例对象。当不再需要使用指针时，请使用[OH_UdmfProperty_Destroy](capi-udmf-h.md#oh_udmfproperty_destroy)销毁实例对象，否则会导致内存泄漏。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfData](capi-udmf-oh-udmfdata.md)* unifiedData | 表示指向统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)* | 执行成功则返回一个指向属性[OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)实例对象的指针，否则返回nullptr。 |

### OH_UdmfProperty_Destroy()

```
void OH_UdmfProperty_Destroy(OH_UdmfProperty* pThis)
```

**描述**

销毁数据属性[OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)指针指向的实例对象。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)* pThis | 表示指向数据属性[OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)实例的指针。 |

### OH_UdmfProperty_GetTag()

```
const char* OH_UdmfProperty_GetTag(OH_UdmfProperty* pThis)
```

**描述**

从数据属性[OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)中获取用户自定义标签值。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)* pThis | 表示指向数据属性[OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 执行成功时返回自定义标签值的字符串指针，否则返回nullptr。 |

### OH_UdmfProperty_GetTimestamp()

```
int64_t OH_UdmfProperty_GetTimestamp(OH_UdmfProperty* pThis)
```

**描述**

从数据属性[OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)中获取时间戳。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)* pThis | 表示指向数据属性[OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int64_t | 返回时间戳值。 |

### OH_UdmfProperty_GetShareOption()

```
Udmf_ShareOption OH_UdmfProperty_GetShareOption(OH_UdmfProperty* pThis)
```

**描述**

从数据属性[OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)中获取设备内适用范围属性。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)* pThis | 表示指向数据属性[OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Udmf_ShareOption](#udmf_shareoption) | 返回设备内适用范围属性[Udmf_ShareOption](capi-udmf-h.md#udmf_shareoption)值。 |

### OH_UdmfProperty_GetExtrasIntParam()

```
int OH_UdmfProperty_GetExtrasIntParam(OH_UdmfProperty* pThis, const char* key, int defaultValue)
```

**描述**

从数据属性[OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)中获取自定义的附加整型参数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)* pThis | 表示指向数据属性[OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)实例的指针。 |
| const char* key | 表示键值对的键。 |
| int defaultValue | 用于用户自行设置获取值失败时的默认值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 执行成功返回指定的键关联的整型值，否则返回用户设置的默认值defaultValue。 |

### OH_UdmfProperty_GetExtrasStringParam()

```
const char* OH_UdmfProperty_GetExtrasStringParam(OH_UdmfProperty* pThis, const char* key)
```

**描述**

从数据属性[OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)中获取自定义的附加字符串参数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)* pThis | 表示指向数据属性[OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)实例的指针。 |
| const char* key | 表示键值对的键。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 执行成功时返回指定的键关联的字符串值的指针，否则返回nullptr。 |

### OH_UdmfProperty_SetTag()

```
int OH_UdmfProperty_SetTag(OH_UdmfProperty* pThis, const char* tag)
```

**描述**

设置数据属性[OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)的自定义标签值。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)* pThis | 表示指向数据属性[OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)实例的指针。 |
| const char* tag | 表示自定义标签值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_UdmfProperty_SetShareOption()

```
int OH_UdmfProperty_SetShareOption(OH_UdmfProperty* pThis, Udmf_ShareOption option)
```

**描述**

设置数据属性[OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)的设备内适用范围[Udmf_ShareOption](capi-udmf-h.md#udmf_shareoption)参数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)* pThis | 表示指向数据属性[OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)实例的指针。 |
| [Udmf_ShareOption](#udmf_shareoption) option | 表示设备内适用范围[Udmf_ShareOption](capi-udmf-h.md#udmf_shareoption)参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_UdmfProperty_SetExtrasIntParam()

```
int OH_UdmfProperty_SetExtrasIntParam(OH_UdmfProperty* pThis, const char* key, int param)
```

**描述**

设置数据属性[OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)的附加整型参数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)* pThis | 表示指向[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)实例的指针。 |
| const char* key | 表示键值对的键。 |
| int param | 表示键值对的值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_UdmfProperty_SetExtrasStringParam()

```
int OH_UdmfProperty_SetExtrasStringParam(OH_UdmfProperty* pThis, const char* key, const char* param)
```

**描述**

设置数据属性[OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)的附加字符串参数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)* pThis | 表示指向数据属性[OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)实例的指针。 |
| const char* key | 表示键值对的键。 |
| const char* param | 表示键值对的值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_UdmfOptions_Create()

```
OH_UdmfOptions* OH_UdmfOptions_Create()
```

**描述**

创建指向[OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)实例的指针。

**起始版本：** 20

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)* | 执行成功则返回一个指向数据操作选项[OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)实例的指针，否则返回nullptr。 |

### OH_UdmfOptions_Destroy()

```
void OH_UdmfOptions_Destroy(OH_UdmfOptions* pThis)
```

**描述**

销毁指向[OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)实例的指针。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)* pThis | 指向数据操作选项[OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)实例的指针。 |

### OH_UdmfOptions_GetKey()

```
const char* OH_UdmfOptions_GetKey(OH_UdmfOptions* pThis)
```

**描述**

从数据操作选项[OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)实例中获取数据的唯一标识符信息。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)* pThis | 指向数据操作选项[OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 输入有效入参时返回符串指针，否则返回nullptr。 |

### OH_UdmfOptions_SetKey()

```
int OH_UdmfOptions_SetKey(OH_UdmfOptions* pThis, const char* key)
```

**描述**

设置数据操作选项[OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)实例中的数据的唯一标识符内容参数。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)* pThis | 指向数据操作选项[OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)实例的指针。 |
| const char* key | 数据的唯一标识符的新字符串值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_UdmfOptions_GetIntention()

```
Udmf_Intention OH_UdmfOptions_GetIntention(OH_UdmfOptions* pThis)
```

**描述**

从数据操作选项[OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)实例中获取数据通路信息。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)* pThis | 指向数据操作选项[OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Udmf_Intention](#udmf_intention) | 返回[Udmf_Intention](capi-udmf-h.md#udmf_intention)的值。 |

### OH_UdmfOptions_SetIntention()

```
int OH_UdmfOptions_SetIntention(OH_UdmfOptions* pThis, Udmf_Intention intention)
```

**描述**

设置数据操作选项[OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)实例中的数据通路内容参数。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)* pThis | 指向数据操作选项[OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)实例的指针。 |
| [Udmf_Intention](#udmf_intention) intention | 数据通路类型参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_UdmfOptions_Reset()

```
int OH_UdmfOptions_Reset(OH_UdmfOptions* pThis)
```

**描述**

重置数据操作选项[OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)实例为空。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)* pThis | 指向数据操作选项[OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_Udmf_GetUnifiedData()

```
int OH_Udmf_GetUnifiedData(const char* key, Udmf_Intention intention, OH_UdmfData* unifiedData)
```

**描述**

从统一数据管理框架数据库中获取统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)数据。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* key | 表示数据库存储的唯一标识符。 |
| [Udmf_Intention](#udmf_intention) intention | 表示数据通路类型[Udmf_Intention](capi-udmf-h.md#udmf_intention)。 |
| [OH_UdmfData](capi-udmf-oh-udmfdata.md)* unifiedData | 该参数是输出参数，获取到的统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)会写入该变量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。<br>若返回UDMF_ERR，表示内部数据错误。 |

### OH_Udmf_GetUnifiedDataByOptions()

```
int OH_Udmf_GetUnifiedDataByOptions(OH_UdmfOptions* options, OH_UdmfData** dataArray, unsigned int* dataSize)
```

**描述**

通过数据通路类型从统一数据管理框架数据库中获取统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)数据。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)* options | 指向数据操作选项[OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)实例的指针。 |
| [OH_UdmfData](capi-udmf-oh-udmfdata.md)** dataArray | 该参数是输出参数，表示统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)列表，<br>此指针需要使用[OH_Udmf_DestroyDataArray](capi-udmf-h.md#oh_udmf_destroydataarray)函数释放。 |
| unsigned int* dataSize | 该参数是输出参数，表示获取到的统一数据对象个数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。<br>若返回UDMF_ERR，表示内部数据错误。 |

### OH_Udmf_SetUnifiedData()

```
int OH_Udmf_SetUnifiedData(Udmf_Intention intention, OH_UdmfData* unifiedData, char* key, unsigned int keyLen)
```

**描述**

从统一数据管理框架数据库中写入统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)数据。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Udmf_Intention](#udmf_intention) intention | 表示数据通路类型[Udmf_Intention](capi-udmf-h.md#udmf_intention)。 |
| [OH_UdmfData](capi-udmf-oh-udmfdata.md)* unifiedData | 表示统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)数据。 |
| key | 表示成功将数据设置到数据库后对应数据的唯一标识符。 |
| unsigned int keyLen | 表示唯一标识符参数的空间大小，内存大小不小于512字节。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。<br>若返回UDMF_ERR，表示内部数据错误。 |

### OH_Udmf_SetUnifiedDataByOptions()

```
int OH_Udmf_SetUnifiedDataByOptions(OH_UdmfOptions* options, OH_UdmfData *unifiedData, char *key, unsigned int keyLen)
```

**描述**

从统一数据管理框架数据库中写入统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)数据。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)* options | 指向数据操作选项[OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)实例的指针。 |
| [OH_UdmfData](capi-udmf-oh-udmfdata.md) *unifiedData | 指向统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)实例的指针。 |
| char *key | 成功将数据设置到数据库后对应数据的唯一标识符，内存大小不小于[UDMF_KEY_BUFFER_LEN](#udmf_key_buffer_len)。 |
| unsigned int keyLen | 唯一标识符参数的空间大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。<br>若返回UDMF_ERR，表示内部数据错误。 |

### OH_Udmf_UpdateUnifiedData()

```
int OH_Udmf_UpdateUnifiedData(OH_UdmfOptions* options, OH_UdmfData* unifiedData)
```

**描述**

对统一数据管理框架数据库中的统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)数据进行数据更改。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)* options | 指向数据操作选项[OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)实例的指针。 |
| [OH_UdmfData](capi-udmf-oh-udmfdata.md)* unifiedData | 指向统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。<br>若返回UDMF_ERR，表示内部数据错误。 |

### OH_Udmf_DeleteUnifiedData()

```
int OH_Udmf_DeleteUnifiedData(OH_UdmfOptions* options, OH_UdmfData** dataArray, unsigned int* dataSize)
```

**描述**

删除统一数据管理框架数据库中的统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)数据。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)* options | 指向数据操作选项[OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)实例的指针。 |
| [OH_UdmfData](capi-udmf-oh-udmfdata.md)** dataArray | 该参数是输出参数，统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)列表，<br>此指针需要使用[OH_Udmf_DestroyDataArray](capi-udmf-h.md#oh_udmf_destroydataarray)函数释放。 |
| unsigned int* dataSize | 该参数是输出参数，表示获取到的统一数据对象个数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。<br>若返回UDMF_ERR，表示内部数据错误。 |

### OH_Udmf_DestroyDataArray()

```
void OH_Udmf_DestroyDataArray(OH_UdmfData** dataArray, unsigned int dataSize)
```

**描述**

销毁数据数组内存。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfData](capi-udmf-oh-udmfdata.md)** dataArray | 指向统一数据对象[OH_UdmfData](capi-udmf-oh-udmfdata.md)的指针列表。 |
| unsigned int dataSize | 列表中的数据大小。 |

**参考：**

OH_UdmfData

### OH_UdmfProgressInfo_GetProgress()

```
int OH_UdmfProgressInfo_GetProgress(OH_Udmf_ProgressInfo* progressInfo)
```

**描述**

从进度信息[OH_Udmf_ProgressInfo](capi-udmf-oh-udmf-progressinfo.md)中获取进度百分比数据。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Udmf_ProgressInfo](capi-udmf-oh-udmf-progressinfo.md)* progressInfo | 表示进度信息[OH_Udmf_ProgressInfo](capi-udmf-oh-udmf-progressinfo.md)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回进度百分比数据。 |

### OH_UdmfProgressInfo_GetStatus()

```
int OH_UdmfProgressInfo_GetStatus(OH_Udmf_ProgressInfo* progressInfo)
```

**描述**

从进度信息[OH_Udmf_ProgressInfo](capi-udmf-oh-udmf-progressinfo.md)中获取状态信息。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Udmf_ProgressInfo](capi-udmf-oh-udmf-progressinfo.md)* progressInfo | 表示进度信息[OH_Udmf_ProgressInfo](capi-udmf-oh-udmf-progressinfo.md)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回状态信息。 |

### OH_UdmfGetDataParams_Create()

```
OH_UdmfGetDataParams* OH_UdmfGetDataParams_Create()
```

**描述**

创建异步获取UDMF数据的请求参数[OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md)指针及实例对象。<br>当不再需要使用指针时，请使用[OH_UdmfGetDataParams_Destroy](capi-udmf-h.md#oh_udmfgetdataparams_destroy)销毁实例对象，否则会导致内存泄漏。

**起始版本：** 15

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md)* | 执行成功则返回一个指向属性[OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md)实例对象的指针，否则返回nullptr。 |

### OH_UdmfGetDataParams_Destroy()

```
void OH_UdmfGetDataParams_Destroy(OH_UdmfGetDataParams* pThis)
```

**描述**

销毁异步请求参数[OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md)指针指向的实例对象。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md)* pThis | 表示指向异步请求参数[OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md)实例的指针。 |

### OH_UdmfGetDataParams_SetDestUri()

```
void OH_UdmfGetDataParams_SetDestUri(OH_UdmfGetDataParams* params, const char* destUri)
```

**描述**

设置异步请求参数[OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md)中的目标路径。<br>若设置了目标路径，会将文件类型的数据进行拷贝到指定路径。回调中获取到的文件类型数据会被替换为目标路径的URI。<br>若不设置目标路径，则不会执行拷贝文件操作。回调中获取到的文件类型数据为源端路径URI。<br>若应用涉及复杂文件处理策略，或需要将文件拷贝在多个路径下时，建议不设置此参数，由应用自行完成文件拷贝相关处理。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md)* params | 表示指向异步请求参数[OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md)实例的指针。 |
| const char* destUri | 表示目标路径地址。 |

### OH_UdmfGetDataParams_SetFileConflictOptions()

```
void OH_UdmfGetDataParams_SetFileConflictOptions(OH_UdmfGetDataParams* params, const Udmf_FileConflictOptions options)
```

**描述**

设置异步请求参数[OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md)中的文件冲突选项。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md)* params | 表示指向异步请求参数[OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md)实例的指针。 |
| const [Udmf_FileConflictOptions](#udmf_fileconflictoptions) options | 表示文件拷贝冲突时的选项。 |

### OH_UdmfGetDataParams_SetProgressIndicator()

```
void OH_UdmfGetDataParams_SetProgressIndicator(OH_UdmfGetDataParams* params, const Udmf_ProgressIndicator progressIndicator)
```

**描述**

设置异步请求参数[OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md)中的进度条指示选项。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md)* params | 表示指向异步请求参数[OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md)实例的指针。 |
| const [Udmf_ProgressIndicator](#udmf_progressindicator) progressIndicator | 表示是否使用默认进度条选项。 |

### OH_UdmfGetDataParams_SetDataProgressListener()

```
void OH_UdmfGetDataParams_SetDataProgressListener(OH_UdmfGetDataParams* params, const OH_Udmf_DataProgressListener dataProgressListener)
```

**描述**

设置异步请求参数[OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md)中的监听回调函数。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md)* params | 表示指向异步请求参数[OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md)实例的指针。 |
| const [OH_Udmf_DataProgressListener](#oh_udmf_dataprogresslistener) dataProgressListener | 用户自定义的监听回调函数，可用于获取进度信息和数据。 |