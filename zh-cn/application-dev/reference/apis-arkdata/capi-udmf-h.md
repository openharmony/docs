# udmf.h

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
| [OH_UdmfData](capi-oh-udmfdata.md) | OH_UdmfData | 定义统一数据对象数据结构。 |
| [OH_UdmfRecord](capi-oh-udmfrecord.md) | OH_UdmfRecord | 定义统一数据对象中记录数据的数据结构，称为数据记录。 |
| [OH_UdmfRecordProvider](capi-oh-udmfrecordprovider.md) | OH_UdmfRecordProvider | 定义统一数据对象中的数据提供者。 |
| [OH_UdmfProperty](capi-oh-udmfproperty.md) | OH_UdmfProperty | 定义统一数据对象中数据记录的属性结构。 |
| [OH_Udmf_ProgressInfo](capi-oh-udmf-progressinfo.md) | OH_Udmf_ProgressInfo | 定义进度信息的数据结构。 |
| [OH_UdmfGetDataParams](capi-oh-udmfgetdataparams.md) | OH_UdmfGetDataParams | 定义异步获取UDMF数据的请求参数。 |
| [OH_UdmfOptions](capi-oh-udmfoptions.md) | OH_UdmfOptions | 数据操作选项，定义数据操作的可选参数。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [Udmf_Intention](#udmf_intention) | Udmf_Intention | 描述UDMF数据通路枚举类型。 |
| [Udmf_ShareOption](#udmf_shareoption) | Udmf_ShareOption | UDMF支持的设备内使用范围类型枚举。 |
| [Udmf_FileConflictOptions](#udmf_fileconflictoptions) | Udmf_FileConflictOptions | 定义文件拷贝冲突时的选项。 |
| [Udmf_ProgressIndicator](#udmf_progressindicator) | Udmf_ProgressIndicator | 定义进度条指示选项，可选择是否采用系统默认进度显示。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [UDMF_KEY_BUFFER_LEN (512)](#) | - | 统一数据对象唯一标识符最小空间长度。 |
| [typedef void (\*OH_Udmf_DataProgressListener)(OH_Udmf_ProgressInfo* progressInfo, OH_UdmfData* data)](#oh_udmf_dataprogresslistener) | OH_Udmf_DataProgressListener | 定义获取进度信息和数据的监听回调函数。<br>使用时需要判断数据是否返回空指针。只有当进度达到100%时，才会返回数据。 |
| [OH_UdmfData* OH_UdmfData_Create()](#oh_udmfdata_create) | - | 创建统一数据对象[OH_UdmfData](capi-oh-udmfdata.md)指针及实例对象。当不再需要使用指针时，请使用[OH_UdmfData_Destroy](capi-udmf-h.md#oh_udmfdata_destroy)销毁实例对象，否则会导致内存泄漏。 |
| [void OH_UdmfData_Destroy(OH_UdmfData* pThis)](#oh_udmfdata_destroy) | - | 销毁统一数据对象[OH_UdmfData](capi-oh-udmfdata.md)指针指向的实例对象。 |
| [int OH_UdmfData_AddRecord(OH_UdmfData* pThis, OH_UdmfRecord* record)](#oh_udmfdata_addrecord) | - | 添加一个数据记录[OH_UdmfRecord](capi-oh-udmfrecord.md)到统一数据对象[OH_UdmfData](capi-oh-udmfdata.md)中。 |
| [bool OH_UdmfData_HasType(OH_UdmfData* pThis, const char* type)](#oh_udmfdata_hastype) | - | 检查统一数据对象[OH_UdmfData](capi-oh-udmfdata.md)中是否存在指定类型。 |
| [char** OH_UdmfData_GetTypes(OH_UdmfData* pThis, unsigned int* count)](#oh_udmfdata_gettypes) | - | 获取统一数据对象[OH_UdmfData](capi-oh-udmfdata.md)中包含的所有类型结果集。 |
| [OH_UdmfRecord** OH_UdmfData_GetRecords(OH_UdmfData* pThis, unsigned int* count)](#oh_udmfdata_getrecords) | - | 获取统一数据对象[OH_UdmfData](capi-oh-udmfdata.md)中包含的所有记录结果集。 |
| [typedef void (\*UdmfData_Finalize)(void* context)](#udmfdata_finalize) | UdmfData_Finalize | 定义用于释放上下文的回调函数，统一数据提供者对象销毁时触发。 |
| [OH_UdmfRecordProvider* OH_UdmfRecordProvider_Create()](#oh_udmfrecordprovider_create) | - | 创建一个统一数据提供者[OH_UdmfRecordProvider](capi-oh-udmfrecordprovider.md)指针及实例对象。当不再需要使用指针时，请使用[OH_UdmfRecordProvider_Destroy](capi-udmf-h.md#oh_udmfrecordprovider_destroy)销毁实例对象，否则会导致内存泄漏。 |
| [int OH_UdmfRecordProvider_Destroy(OH_UdmfRecordProvider* provider)](#oh_udmfrecordprovider_destroy) | - | 销毁统一数据提供者[OH_UdmfRecordProvider](capi-oh-udmfrecordprovider.md)指针指向的实例对象。 |
| [typedef void* (\*OH_UdmfRecordProvider_GetData)(void* context, const char* type)](#oh_udmfrecordprovider_getdata) | OH_UdmfRecordProvider_GetData | 定义用于按类型获取数据的回调函数。当从OH_UdmfRecord中获取数据时，会触发此回调函数，得到的数据就是这个回调函数返回的数据。 |
| [int OH_UdmfRecordProvider_SetData(OH_UdmfRecordProvider* provider, void* context,const OH_UdmfRecordProvider_GetData callback, const UdmfData_Finalize finalize)](#oh_udmfrecordprovider_setdata) | - | 设置统一数据提供者的数据提供回调函数。 |
| [OH_UdmfRecord* OH_UdmfRecord_Create()](#oh_udmfrecord_create) | - | 创建统一数据记录[OH_UdmfRecord](capi-oh-udmfrecord.md)指针及实例对象。当不再需要使用指针时，请使用[OH_UdmfRecord_Destroy](capi-udmf-h.md#oh_udmfrecord_destroy)销毁实例对象，否则会导致内存泄漏。 |
| [void OH_UdmfRecord_Destroy(OH_UdmfRecord* pThis)](#oh_udmfrecord_destroy) | - | 销毁统一数据记录[OH_UdmfRecord](capi-oh-udmfrecord.md)指针指向的实例对象。 |
| [int OH_UdmfRecord_AddGeneralEntry(OH_UdmfRecord* pThis, const char* typeId, unsigned char* entry, unsigned int count)](#oh_udmfrecord_addgeneralentry) | - | 添加用户自定义的通用数据至统一数据记录[OH_UdmfRecord](capi-oh-udmfrecord.md)中。对于已定义UDS的类型（比如PlainText、Link、Pixelmap等）不可使用该接口。 |
| [int OH_UdmfRecord_AddPlainText(OH_UdmfRecord* pThis, OH_UdsPlainText* plainText)](#oh_udmfrecord_addplaintext) | - | 增加纯文本类型[OH_UdsPlainText](capi-oh-udsplaintext.md)数据至统一数据记录[OH_UdmfRecord](capi-oh-udmfrecord.md)中。 |
| [int OH_UdmfRecord_AddHyperlink(OH_UdmfRecord* pThis, OH_UdsHyperlink* hyperlink)](#oh_udmfrecord_addhyperlink) | - | 增加超链接类型[OH_UdsHyperlink](capi-oh-udshyperlink.md)数据至统一数据记录[OH_UdmfRecord](capi-oh-udmfrecord.md)中。 |
| [int OH_UdmfRecord_AddHtml(OH_UdmfRecord* pThis, OH_UdsHtml* html)](#oh_udmfrecord_addhtml) | - | 增加超文本标记语言类型[OH_UdsHtml](capi-oh-udshtml.md)数据至统一数据记录[OH_UdmfRecord](capi-oh-udmfrecord.md)中。 |
| [int OH_UdmfRecord_AddAppItem(OH_UdmfRecord* pThis, OH_UdsAppItem* appItem)](#oh_udmfrecord_addappitem) | - | 增加桌面图标类型[OH_UdsAppItem](capi-oh-udsappitem.md)数据至统一数据记录[OH_UdmfRecord](capi-oh-udmfrecord.md)中。 |
| [int OH_UdmfRecord_AddFileUri(OH_UdmfRecord* pThis, OH_UdsFileUri* fileUri)](#oh_udmfrecord_addfileuri) | - | 增加文件Uri类型[OH_UdsFileUri](capi-oh-udsfileuri.md)数据至统一数据记录[OH_UdmfRecord](capi-oh-udmfrecord.md)中。 |
| [int OH_UdmfRecord_AddPixelMap(OH_UdmfRecord* pThis, OH_UdsPixelMap* pixelMap)](#oh_udmfrecord_addpixelmap) | - | 增加像素图片类型[OH_UdsPixelMap](capi-oh-udspixelmap.md)数据至统一数据记录[OH_UdmfRecord](capi-oh-udmfrecord.md)中。 |
| [int OH_UdmfRecord_AddArrayBuffer(OH_UdmfRecord* record, const char* type, OH_UdsArrayBuffer* buffer)](#oh_udmfrecord_addarraybuffer) | - | 增加一个ArrayBuffer类型[OH_UdsArrayBuffer](capi-oh-udsarraybuffer.md)的数据至统一数据记录[OH_UdmfRecord](capi-oh-udmfrecord.md)中。 |
| [int OH_UdmfRecord_AddContentForm(OH_UdmfRecord* pThis, OH_UdsContentForm* contentForm)](#oh_udmfrecord_addcontentform) | - | 增加一个内容卡片类型[OH_UdsContentForm](capi-oh-udscontentform.md)的数据至统一数据记录[OH_UdmfRecord](capi-oh-udmfrecord.md)中。 |
| [char** OH_UdmfRecord_GetTypes(OH_UdmfRecord* pThis, unsigned int* count)](#oh_udmfrecord_gettypes) | - | 获取统一数据记录[OH_UdmfRecord](capi-oh-udmfrecord.md)中所有类型的结果集。 |
| [int OH_UdmfRecord_GetGeneralEntry(OH_UdmfRecord* pThis, const char* typeId,unsigned char** entry, unsigned int* count)](#oh_udmfrecord_getgeneralentry) | - | 获取统一数据记录[OH_UdmfRecord](capi-oh-udmfrecord.md)中的特定类型的数据结果集。 |
| [int OH_UdmfRecord_GetPlainText(OH_UdmfRecord* pThis, OH_UdsPlainText* plainText)](#oh_udmfrecord_getplaintext) | - | 从统一数据记录[OH_UdmfRecord](capi-oh-udmfrecord.md)中获取纯文本类型[OH_UdsPlainText](capi-oh-udsplaintext.md)数据。 |
| [int OH_UdmfRecord_GetHyperlink(OH_UdmfRecord* pThis, OH_UdsHyperlink* hyperlink)](#oh_udmfrecord_gethyperlink) | - | 从统一数据记录[OH_UdmfRecord](capi-oh-udmfrecord.md)中获取超链接类型[OH_UdsHyperlink](capi-oh-udshyperlink.md)数据。 |
| [int OH_UdmfRecord_GetHtml(OH_UdmfRecord* pThis, OH_UdsHtml* html)](#oh_udmfrecord_gethtml) | - | 从统一数据记录[OH_UdmfRecord](capi-oh-udmfrecord.md)中获取超文本标记语言类型[OH_UdsHtml](capi-oh-udshtml.md)数据。 |
| [int OH_UdmfRecord_GetAppItem(OH_UdmfRecord* pThis, OH_UdsAppItem* appItem)](#oh_udmfrecord_getappitem) | - | 从统一数据记录[OH_UdmfRecord](capi-oh-udmfrecord.md)中获取桌面图标类型[OH_UdsAppItem](capi-oh-udsappitem.md)数据。 |
| [int OH_UdmfRecord_SetProvider(OH_UdmfRecord* pThis, const char* const* types, unsigned int count,OH_UdmfRecordProvider* provider)](#oh_udmfrecord_setprovider) | - | 将指定类型的统一数据提供者[OH_UdmfRecordProvider](capi-oh-udmfrecordprovider.md)设置至统一数据记录[OH_UdmfRecord](capi-oh-udmfrecord.md)中。 |
| [int OH_UdmfRecord_GetFileUri(OH_UdmfRecord* pThis, OH_UdsFileUri* fileUri)](#oh_udmfrecord_getfileuri) | - | 从统一数据记录[OH_UdmfRecord](capi-oh-udmfrecord.md)中获取文件Uri类型[OH_UdsFileUri](capi-oh-udsfileuri.md)数据。 |
| [int OH_UdmfRecord_GetPixelMap(OH_UdmfRecord* pThis, OH_UdsPixelMap* pixelMap)](#oh_udmfrecord_getpixelmap) | - | 从统一数据记录[OH_UdmfRecord](capi-oh-udmfrecord.md)中获取像素图片类型[OH_UdsPixelMap](capi-oh-udspixelmap.md)数据。 |
| [int OH_UdmfRecord_GetArrayBuffer(OH_UdmfRecord* record, const char* type, OH_UdsArrayBuffer* buffer)](#oh_udmfrecord_getarraybuffer) | - | 从统一数据记录[OH_UdmfRecord](capi-oh-udmfrecord.md)中获取ArrayBuffer类型[OH_UdsArrayBuffer](capi-oh-udsarraybuffer.md)数据。 |
| [int OH_UdmfRecord_GetContentForm(OH_UdmfRecord* pThis, OH_UdsContentForm* contentForm)](#oh_udmfrecord_getcontentform) | - | 从统一数据记录[OH_UdmfRecord](capi-oh-udmfrecord.md)中获取内容卡片类型[OH_UdsContentForm](capi-oh-udscontentform.md)数据。 |
| [int OH_UdmfData_GetPrimaryPlainText(OH_UdmfData* data, OH_UdsPlainText* plainText)](#oh_udmfdata_getprimaryplaintext) | - | 从统一数据对象[OH_UdmfData](capi-oh-udmfdata.md)中获取第一个纯文本类型[OH_UdsPlainText](capi-oh-udsplaintext.md)数据。 |
| [int OH_UdmfData_GetPrimaryHtml(OH_UdmfData* data, OH_UdsHtml* html)](#oh_udmfdata_getprimaryhtml) | - | 从统一数据对象[OH_UdmfData](capi-oh-udmfdata.md)中获取第一个超文本标记语言类型[OH_UdsHtml](capi-oh-udshtml.md)数据。 |
| [int OH_UdmfData_GetRecordCount(OH_UdmfData* data)](#oh_udmfdata_getrecordcount) | - | 获取统一数据对象[OH_UdmfData](capi-oh-udmfdata.md)中包含的所有记录数量。 |
| [OH_UdmfRecord* OH_UdmfData_GetRecord(OH_UdmfData* data, unsigned int index)](#oh_udmfdata_getrecord) | - | 获取统一数据对象[OH_UdmfData](capi-oh-udmfdata.md)中指定位置的数据记录。 |
| [bool OH_UdmfData_IsLocal(OH_UdmfData* data)](#oh_udmfdata_islocal) | - | 检查统一数据对象[OH_UdmfData](capi-oh-udmfdata.md)是否是来自本端设备的数据。 |
| [OH_UdmfProperty* OH_UdmfProperty_Create(OH_UdmfData* unifiedData)](#oh_udmfproperty_create) | - | 创建统一数据对象中数据记录属性[OH_UdmfProperty](capi-oh-udmfproperty.md)指针及实例对象。当不再需要使用指针时，请使用[OH_UdmfProperty_Destroy](capi-udmf-h.md#oh_udmfproperty_destroy)销毁实例对象，否则会导致内存泄漏。 |
| [void OH_UdmfProperty_Destroy(OH_UdmfProperty* pThis)](#oh_udmfproperty_destroy) | - | 销毁数据属性[OH_UdmfProperty](capi-oh-udmfproperty.md)指针指向的实例对象。 |
| [const char* OH_UdmfProperty_GetTag(OH_UdmfProperty* pThis)](#oh_udmfproperty_gettag) | - | 从数据属性[OH_UdmfProperty](capi-oh-udmfproperty.md)中获取用户自定义标签值。 |
| [int64_t OH_UdmfProperty_GetTimestamp(OH_UdmfProperty* pThis)](#oh_udmfproperty_gettimestamp) | - | 从数据属性[OH_UdmfProperty](capi-oh-udmfproperty.md)中获取时间戳。 |
| [Udmf_ShareOption OH_UdmfProperty_GetShareOption(OH_UdmfProperty* pThis)](#oh_udmfproperty_getshareoption) | - | 从数据属性[OH_UdmfProperty](capi-oh-udmfproperty.md)中获取设备内适用范围属性。 |
| [int OH_UdmfProperty_GetExtrasIntParam(OH_UdmfProperty* pThis, const char* key, int defaultValue)](#oh_udmfproperty_getextrasintparam) | - | 从数据属性[OH_UdmfProperty](capi-oh-udmfproperty.md)中获取自定义的附加整型参数。 |
| [const char* OH_UdmfProperty_GetExtrasStringParam(OH_UdmfProperty* pThis, const char* key)](#oh_udmfproperty_getextrasstringparam) | - | 从数据属性[OH_UdmfProperty](capi-oh-udmfproperty.md)中获取自定义的附加字符串参数。 |
| [int OH_UdmfProperty_SetTag(OH_UdmfProperty* pThis, const char* tag)](#oh_udmfproperty_settag) | - | 设置数据属性[OH_UdmfProperty](capi-oh-udmfproperty.md)的自定义标签值。 |
| [int OH_UdmfProperty_SetShareOption(OH_UdmfProperty* pThis, Udmf_ShareOption option)](#oh_udmfproperty_setshareoption) | - | 设置数据属性[OH_UdmfProperty](capi-oh-udmfproperty.md)的设备内适用范围{@link OH_Udmf_ShareOption}参数。 |
| [int OH_UdmfProperty_SetExtrasIntParam(OH_UdmfProperty* pThis, const char* key, int param)](#oh_udmfproperty_setextrasintparam) | - | 设置数据属性[OH_UdmfProperty](capi-oh-udmfproperty.md)的附加整型参数。 |
| [int OH_UdmfProperty_SetExtrasStringParam(OH_UdmfProperty* pThis,const char* key, const char* param)](#oh_udmfproperty_setextrasstringparam) | - | 设置数据属性[OH_UdmfProperty](capi-oh-udmfproperty.md)的附加字符串参数。 |
| [OH_UdmfOptions* OH_UdmfOptions_Create()](#oh_udmfoptions_create) | - | 创建指向[OH_UdmfOptions](capi-oh-udmfoptions.md)实例的指针。 |
| [void OH_UdmfOptions_Destroy(OH_UdmfOptions* pThis)](#oh_udmfoptions_destroy) | - | 销毁指向[OH_UdmfOptions](capi-oh-udmfoptions.md)实例的指针。 |
| [const char* OH_UdmfOptions_GetKey(OH_UdmfOptions* pThis)](#oh_udmfoptions_getkey) | - | 从数据操作选项[OH_UdmfOptions](capi-oh-udmfoptions.md)实例中获取数据的唯一标识符信息。 |
| [int OH_UdmfOptions_SetKey(OH_UdmfOptions* pThis, const char* key)](#oh_udmfoptions_setkey) | - | 设置数据操作选项[OH_UdmfOptions](capi-oh-udmfoptions.md)实例中的数据的唯一标识符内容参数。 |
| [Udmf_Intention OH_UdmfOptions_GetIntention(OH_UdmfOptions* pThis)](#oh_udmfoptions_getintention) | - | 从数据操作选项[OH_UdmfOptions](capi-oh-udmfoptions.md)实例中获取数据通路信息。 |
| [int OH_UdmfOptions_SetIntention(OH_UdmfOptions* pThis, Udmf_Intention intention)](#oh_udmfoptions_setintention) | - | 设置数据操作选项[OH_UdmfOptions](capi-oh-udmfoptions.md)实例中的数据通路内容参数。 |
| [int OH_UdmfOptions_Reset(OH_UdmfOptions* pThis)](#oh_udmfoptions_reset) | - | 重置数据操作选项[OH_UdmfOptions](capi-oh-udmfoptions.md)实例为空。 |
| [int OH_Udmf_GetUnifiedData(const char* key, Udmf_Intention intention, OH_UdmfData* unifiedData)](#oh_udmf_getunifieddata) | - | 从统一数据管理框架数据库中获取统一数据对象[OH_UdmfData](capi-oh-udmfdata.md)数据。 |
| [int OH_Udmf_GetUnifiedDataByOptions(OH_UdmfOptions* options, OH_UdmfData** dataArray, unsigned int* dataSize)](#oh_udmf_getunifieddatabyoptions) | - | 通过数据通路类型从统一数据管理框架数据库中获取统一数据对象[OH_UdmfData](capi-oh-udmfdata.md)数据。 |
| [int OH_Udmf_SetUnifiedData(Udmf_Intention intention, OH_UdmfData* unifiedData,char* key, unsigned int keyLen)](#oh_udmf_setunifieddata) | - | 从统一数据管理框架数据库中写入统一数据对象[OH_UdmfData](capi-oh-udmfdata.md)数据。 |
| [int OH_Udmf_SetUnifiedDataByOptions(OH_UdmfOptions* options, OH_UdmfData *unifiedData, char *key, unsigned int keyLen)](#oh_udmf_setunifieddatabyoptions) | - | 从统一数据管理框架数据库中写入统一数据对象[OH_UdmfData](capi-oh-udmfdata.md)数据。 |
| [int OH_Udmf_UpdateUnifiedData(OH_UdmfOptions* options, OH_UdmfData* unifiedData)](#oh_udmf_updateunifieddata) | - | 对统一数据管理框架数据库中的统一数据对象[OH_UdmfData](capi-oh-udmfdata.md)数据进行数据更改。 |
| [int OH_Udmf_DeleteUnifiedData(OH_UdmfOptions* options, OH_UdmfData** dataArray, unsigned int* dataSize)](#oh_udmf_deleteunifieddata) | - | 删除统一数据管理框架数据库中的统一数据对象[OH_UdmfData](capi-oh-udmfdata.md)数据。 |
| [void OH_Udmf_DestroyDataArray(OH_UdmfData** dataArray, unsigned int dataSize)](#oh_udmf_destroydataarray) | - | 销毁数据数组内存。 |
| [int OH_UdmfProgressInfo_GetProgress(OH_Udmf_ProgressInfo* progressInfo)](#oh_udmfprogressinfo_getprogress) | - | 从进度信息[OH_Udmf_ProgressInfo](capi-oh-udmf-progressinfo.md)中获取进度百分比数据。 |
| [int OH_UdmfProgressInfo_GetStatus(OH_Udmf_ProgressInfo* progressInfo)](#oh_udmfprogressinfo_getstatus) | - | 从进度信息[OH_Udmf_ProgressInfo](capi-oh-udmf-progressinfo.md)中获取状态信息。 |
| [OH_UdmfGetDataParams* OH_UdmfGetDataParams_Create()](#oh_udmfgetdataparams_create) | - | 创建异步获取UDMF数据的请求参数[OH_UdmfGetDataParams](capi-oh-udmfgetdataparams.md)指针及实例对象。<br>当不再需要使用指针时，请使用[OH_UdmfGetDataParams_Destroy](capi-udmf-h.md#oh_udmfgetdataparams_destroy)销毁实例对象，否则会导致内存泄漏。 |
| [void OH_UdmfGetDataParams_Destroy(OH_UdmfGetDataParams* pThis)](#oh_udmfgetdataparams_destroy) | - | 销毁异步请求参数[OH_UdmfGetDataParams](capi-oh-udmfgetdataparams.md)指针指向的实例对象。 |
| [void OH_UdmfGetDataParams_SetDestUri(OH_UdmfGetDataParams* params, const char* destUri)](#oh_udmfgetdataparams_setdesturi) | - | 设置异步请求参数[OH_UdmfGetDataParams](capi-oh-udmfgetdataparams.md)中的目标路径。<br>若设置了目标路径，会将文件类型的数据进行拷贝到指定路径。回调中获取到的文件类型数据会被替换为目标路径的URI。<br>若不设置目标路径，则不会执行拷贝文件操作。回调中获取到的文件类型数据为源端路径URI。<br>若应用涉及复杂文件处理策略，或需要将文件拷贝在多个路径下时，建议不设置此参数，由应用自行完成文件拷贝相关处理。 |
| [void OH_UdmfGetDataParams_SetFileConflictOptions(OH_UdmfGetDataParams* params, const Udmf_FileConflictOptions options)](#oh_udmfgetdataparams_setfileconflictoptions) | - | 设置异步请求参数[OH_UdmfGetDataParams](capi-oh-udmfgetdataparams.md)中的文件冲突选项。 |
| [void OH_UdmfGetDataParams_SetProgressIndicator(OH_UdmfGetDataParams* params,const Udmf_ProgressIndicator progressIndicator)](#oh_udmfgetdataparams_setprogressindicator) | - | 设置异步请求参数[OH_UdmfGetDataParams](capi-oh-udmfgetdataparams.md)中的进度条指示选项。 |
| [void OH_UdmfGetDataParams_SetDataProgressListener(OH_UdmfGetDataParams* params,const OH_Udmf_DataProgressListener dataProgressListener)](#oh_udmfgetdataparams_setdataprogresslistener) | - | 设置异步请求参数[OH_UdmfGetDataParams](capi-oh-udmfgetdataparams.md)中的监听回调函数。 |

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


## 函数说明

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
| [OH_Udmf_ProgressInfo](capi-oh-udmf-progressinfo.md)* progressInfo | 进度信息，作为出参使用。 |
| [OH_UdmfData](capi-oh-udmfdata.md)* data | 返回的统一数据对象，作为出参使用。 |

### OH_UdmfData_Create()

```
OH_UdmfData* OH_UdmfData_Create()
```

**描述**

创建统一数据对象[OH_UdmfData](capi-oh-udmfdata.md)指针及实例对象。当不再需要使用指针时，请使用[OH_UdmfData_Destroy](capi-udmf-h.md#oh_udmfdata_destroy)销毁实例对象，否则会导致内存泄漏。

**起始版本：** 12

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_UdmfData](capi-oh-udmfdata.md)* | 执行成功则返回一个指向统一数据对象[OH_UdmfData](capi-oh-udmfdata.md)实例对象的指针，否则返回nullptr。 |

**参考：**

OH_UdmfData

### OH_UdmfData_Destroy()

```
void OH_UdmfData_Destroy(OH_UdmfData* pThis)
```

**描述**

销毁统一数据对象[OH_UdmfData](capi-oh-udmfdata.md)指针指向的实例对象。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfData](capi-oh-udmfdata.md)* pThis | 表示指向统一数据对象[OH_UdmfData](capi-oh-udmfdata.md)实例的指针。 |

**参考：**

OH_UdmfData

### OH_UdmfData_AddRecord()

```
int OH_UdmfData_AddRecord(OH_UdmfData* pThis, OH_UdmfRecord* record)
```

**描述**

添加一个数据记录[OH_UdmfRecord](capi-oh-udmfrecord.md)到统一数据对象[OH_UdmfData](capi-oh-udmfdata.md)中。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfData](capi-oh-udmfdata.md)* pThis | 表示指向统一数据对象[OH_UdmfData](capi-oh-udmfdata.md)实例的指针。 |
| [OH_UdmfRecord](capi-oh-udmfrecord.md)* record | 表示指向统一数据记录[OH_UdmfRecord](capi-oh-udmfrecord.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。请参阅错误码定义[Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode)。<br>若返回UDMF_E_OK，表示执行成功。<br>若返回UDMF_E_INVALID_PARAM，表示传入了无效参数。 |

### OH_UdmfData_HasType()

```
bool OH_UdmfData_HasType(OH_UdmfData* pThis, const char* type)
```

**描述**

检查统一数据对象[OH_UdmfData](capi-oh-udmfdata.md)中是否存在指定类型。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_UdmfData](capi-oh-udmfdata.md)* pThis | 表示指向统一数据对象[OH_UdmfData](capi-oh-udmfdata.md)实例的指针。 |
| const char* type | 表示指定类型的字符串指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回查找类型的状态。返回false表示不存在指定类型，返回true表示存在指定类型。 |