# udmf.h

## Overview

Defines the APIs, data structs, and enums for accessing the UDMF.

**File to include**: <database/udmf/udmf.h>

**Library**: libudmf.so

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Since**: 12

**Related module**: [UDMF](capi-udmf.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_UdmfData](capi-udmf-oh-udmfdata.md) | OH_UdmfData | Defines a struct for a unified data object.|
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) | OH_UdmfRecord | Defines a struct for a data record in a unified data object.|
| [OH_UdmfRecordProvider](capi-udmf-oh-udmfrecordprovider.md) | OH_UdmfRecordProvider | Defines a struct for the data record provider in a unified data object.|
| [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md) | OH_UdmfProperty | Defines a struct for a data record property in a uniform data object.|
| [OH_Udmf_ProgressInfo](capi-udmf-oh-udmf-progressinfo.md) | OH_Udmf_ProgressInfo | Defines a struct for progress information.|
| [OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md) | OH_UdmfGetDataParams | Defines a struct for parameters used to obtain UDMF data asynchronously.|
| [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md) | OH_UdmfOptions | Defines the optional parameters for data operations.|
| [OH_UdmfDataLoadParams](capi-udmf-oh-udmfdataloadparams.md) | OH_UdmfDataLoadParams | Defines a struct for data loading parameters.|
| [OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md) | OH_UdmfDataLoadInfo | Defines a struct for the data loading information.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [Udmf_Intention](#udmf_intention) | Udmf_Intention | Enumerates the UDMF data channel types.|
| [Udmf_ShareOption](#udmf_shareoption) | Udmf_ShareOption | Enumerates the options for using the unified data in a device.|
| [Udmf_FileConflictOptions](#udmf_fileconflictoptions) | Udmf_FileConflictOptions | Enumerates the options used to resolve file copy conflicts.|
| [Udmf_ProgressIndicator](#udmf_progressindicator) | Udmf_ProgressIndicator | Enumerates the progress indicator options. You can use the default progress indicator as required.|
| [Udmf_Visibility](#udmf_visibility) | Udmf_Visibility | Enumerates data visibility level.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [UDMF_KEY_BUFFER_LEN (512)](#udmf_key_buffer_len) | - | Defines minimum length of the buffer that holds the key (unique identifier) of a unified data object.|
| [typedef void (\*OH_Udmf_DataProgressListener)(OH_Udmf_ProgressInfo* progressInfo, OH_UdmfData* data)](#oh_udmf_dataprogresslistener) | OH_Udmf_DataProgressListener | Defines the callback used to return the data retrieval progress information and data obtained.<br>A null pointer is returned if the progress is less than 100%. The data obtained is returned only when the progress reaches 100%.|
| [OH_UdmfData* OH_UdmfData_Create()](#oh_udmfdata_create) | - | Creates an [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance and a pointer to it. If this pointer is no longer required, use [OH_UdmfData_Destroy](capi-udmf-h.md#oh_udmfdata_destroy) to destroy it. Otherwise, memory leaks may occur.|
| [void OH_UdmfData_Destroy(OH_UdmfData* pThis)](#oh_udmfdata_destroy) | - | Destroys an [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance.|
| [int OH_UdmfData_AddRecord(OH_UdmfData* pThis, OH_UdmfRecord* record)](#oh_udmfdata_addrecord) | - | Adds an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) to an [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance.|
| [bool OH_UdmfData_HasType(OH_UdmfData* pThis, const char* type)](#oh_udmfdata_hastype) | - | Checks whether the specified type exists in an [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance.|
| [char** OH_UdmfData_GetTypes(OH_UdmfData* pThis, unsigned int* count)](#oh_udmfdata_gettypes) | - | Obtains all data types in an [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance.|
| [OH_UdmfRecord** OH_UdmfData_GetRecords(OH_UdmfData* pThis, unsigned int* count)](#oh_udmfdata_getrecords) | - | Obtains all records contained in an [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance.|
| [typedef void (\*UdmfData_Finalize)(void* context)](#udmfdata_finalize) | UdmfData_Finalize | Defines a callback function used to release the context. This callback is invoked when the **OH_UdmfRecordProvider** instance is destroyed.|
| [OH_UdmfRecordProvider* OH_UdmfRecordProvider_Create()](#oh_udmfrecordprovider_create) | - | Creates an [OH_UdmfRecordProvider](capi-udmf-oh-udmfrecordprovider.md) instance and a pointer to it. If this pointer is no longer required, use [OH_UdmfRecordProvider_Destroy](capi-udmf-h.md#oh_udmfrecordprovider_destroy) to destroy it. Otherwise, memory leaks may occur.|
| [int OH_UdmfRecordProvider_Destroy(OH_UdmfRecordProvider* provider)](#oh_udmfrecordprovider_destroy) | - | Destroys an [OH_UdmfRecordProvider](capi-udmf-oh-udmfrecordprovider.md) instance.|
| [typedef void* (\*OH_UdmfRecordProvider_GetData)(void* context, const char* type)](#oh_udmfrecordprovider_getdata) | OH_UdmfRecordProvider_GetData | Defines a callback function used to obtain data by type. This callback will be invoked to return the data obtained from **OH_UdmfRecord**.|
| [int OH_UdmfRecordProvider_SetData(OH_UdmfRecordProvider* provider, void* context, const OH_UdmfRecordProvider_GetData callback, const UdmfData_Finalize finalize)](#oh_udmfrecordprovider_setdata) | - | Sets a callback for an **OH_UdmfRecordProvider** instance to provide data.|
| [OH_UdmfRecord* OH_UdmfRecord_Create()](#oh_udmfrecord_create) | - | Creates an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance and a pointer to it. If this pointer is no longer required, use [OH_UdmfRecord_Destroy](capi-udmf-h.md#oh_udmfrecord_destroy) to destroy it. Otherwise, memory leaks may occur.|
| [void OH_UdmfRecord_Destroy(OH_UdmfRecord* pThis)](#oh_udmfrecord_destroy) | - | Destroys an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.|
| [int OH_UdmfRecord_AddGeneralEntry(OH_UdmfRecord* pThis, const char* typeId, unsigned char* entry, unsigned int count)](#oh_udmfrecord_addgeneralentry) | - | Adds customized general data to an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance. This API cannot be used to add data of UDS types (such as PlainText, Link, and Pixelmap).|
| [int OH_UdmfRecord_AddPlainText(OH_UdmfRecord* pThis, OH_UdsPlainText* plainText)](#oh_udmfrecord_addplaintext) | - | Adds data of the [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md) type to an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.|
| [int OH_UdmfRecord_AddHyperlink(OH_UdmfRecord* pThis, OH_UdsHyperlink* hyperlink)](#oh_udmfrecord_addhyperlink) | - | Adds data of the [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md) type to an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.|
| [int OH_UdmfRecord_AddHtml(OH_UdmfRecord* pThis, OH_UdsHtml* html)](#oh_udmfrecord_addhtml) | - | Adds data of the [OH_UdsHtml](capi-udmf-oh-udshtml.md) type to an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.|
| [int OH_UdmfRecord_AddAppItem(OH_UdmfRecord* pThis, OH_UdsAppItem* appItem)](#oh_udmfrecord_addappitem) | - | Adds data of the [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) type to an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.|
| [int OH_UdmfRecord_AddFileUri(OH_UdmfRecord* pThis, OH_UdsFileUri* fileUri)](#oh_udmfrecord_addfileuri) | - | Adds data of the [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md) type to an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.|
| [int OH_UdmfRecord_AddPixelMap(OH_UdmfRecord* pThis, OH_UdsPixelMap* pixelMap)](#oh_udmfrecord_addpixelmap) | - | Adds data of the [OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md) type to an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.|
| [int OH_UdmfRecord_AddArrayBuffer(OH_UdmfRecord* record, const char* type, OH_UdsArrayBuffer* buffer)](#oh_udmfrecord_addarraybuffer) | - | Adds data of the [OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md) type to an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.|
| [int OH_UdmfRecord_AddContentForm(OH_UdmfRecord* pThis, OH_UdsContentForm* contentForm)](#oh_udmfrecord_addcontentform) | - | Adds data of the [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) type to an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.|
| [char** OH_UdmfRecord_GetTypes(OH_UdmfRecord* pThis, unsigned int* count)](#oh_udmfrecord_gettypes) | - | Obtains all data types in an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.|
| [int OH_UdmfRecord_GetGeneralEntry(OH_UdmfRecord* pThis, const char* typeId, unsigned char** entry, unsigned int* count)](#oh_udmfrecord_getgeneralentry) | - | Obtains the data of the specified type in an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.|
| [int OH_UdmfRecord_GetPlainText(OH_UdmfRecord* pThis, OH_UdsPlainText* plainText)](#oh_udmfrecord_getplaintext) | - | Obtains [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md) data from an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.|
| [int OH_UdmfRecord_GetHyperlink(OH_UdmfRecord* pThis, OH_UdsHyperlink* hyperlink)](#oh_udmfrecord_gethyperlink) | - | Obtains [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md) data from an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.|
| [int OH_UdmfRecord_GetHtml(OH_UdmfRecord* pThis, OH_UdsHtml* html)](#oh_udmfrecord_gethtml) | - | Obtains [OH_UdsHtml](capi-udmf-oh-udshtml.md) data from an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.|
| [int OH_UdmfRecord_GetAppItem(OH_UdmfRecord* pThis, OH_UdsAppItem* appItem)](#oh_udmfrecord_getappitem) | - | Obtains [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) data from an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.|
| [int OH_UdmfRecord_SetProvider(OH_UdmfRecord* pThis, const char* const* types, unsigned int count, OH_UdmfRecordProvider* provider)](#oh_udmfrecord_setprovider) | - | Sets the [OH_UdmfRecordProvider](capi-udmf-oh-udmfrecordprovider.md) in an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.|
| [int OH_UdmfRecord_GetFileUri(OH_UdmfRecord* pThis, OH_UdsFileUri* fileUri)](#oh_udmfrecord_getfileuri) | - | Obtains [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md) data from an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.|
| [int OH_UdmfRecord_GetPixelMap(OH_UdmfRecord* pThis, OH_UdsPixelMap* pixelMap)](#oh_udmfrecord_getpixelmap) | - | Obtains [OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md) data from an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.|
| [int OH_UdmfRecord_GetArrayBuffer(OH_UdmfRecord* record, const char* type, OH_UdsArrayBuffer* buffer)](#oh_udmfrecord_getarraybuffer) | - | Obtains [OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md) data from an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.|
| [int OH_UdmfRecord_GetContentForm(OH_UdmfRecord* pThis, OH_UdsContentForm* contentForm)](#oh_udmfrecord_getcontentform) | - | Obtains [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) data from an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.|
| [int OH_UdmfData_GetPrimaryPlainText(OH_UdmfData* data, OH_UdsPlainText* plainText)](#oh_udmfdata_getprimaryplaintext) | - | Obtains the first [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md) data from an [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance.|
| [int OH_UdmfData_GetPrimaryHtml(OH_UdmfData* data, OH_UdsHtml* html)](#oh_udmfdata_getprimaryhtml) | - | Obtains the first [OH_UdsHtml](capi-udmf-oh-udshtml.md) data from an [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance.|
| [int OH_UdmfData_GetRecordCount(OH_UdmfData* data)](#oh_udmfdata_getrecordcount) | - | Obtains the number of data records contained in an [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance.|
| [OH_UdmfRecord* OH_UdmfData_GetRecord(OH_UdmfData* data, unsigned int index)](#oh_udmfdata_getrecord) | - | Obtains the specified data record from an [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance.|
| [bool OH_UdmfData_IsLocal(OH_UdmfData* data)](#oh_udmfdata_islocal) | - | Checks whether an [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance is from the local device.|
| [OH_UdmfProperty* OH_UdmfProperty_Create(OH_UdmfData* unifiedData)](#oh_udmfproperty_create) | - | Creates an [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md) instance and a pointer to it. If this pointer is no longer required, use [OH_UdmfProperty_Destroy](capi-udmf-h.md#oh_udmfproperty_destroy) to destroy it. Otherwise, memory leaks may occur.|
| [void OH_UdmfProperty_Destroy(OH_UdmfProperty* pThis)](#oh_udmfproperty_destroy) | - | Destroys an [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md) instance.|
| [const char* OH_UdmfProperty_GetTag(OH_UdmfProperty* pThis)](#oh_udmfproperty_gettag) | - | Obtains the custom tag value from an [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md) instance.|
| [int64_t OH_UdmfProperty_GetTimestamp(OH_UdmfProperty* pThis)](#oh_udmfproperty_gettimestamp) | - | Obtains the timestamp from an [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md) instance.|
| [Udmf_ShareOption OH_UdmfProperty_GetShareOption(OH_UdmfProperty* pThis)](#oh_udmfproperty_getshareoption) | - | Obtains the share option from an [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md) instance.|
| [int OH_UdmfProperty_GetExtrasIntParam(OH_UdmfProperty* pThis, const char* key, int defaultValue)](#oh_udmfproperty_getextrasintparam) | - | Obtains the customized extra integer parameter from an [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md) instance.|
| [const char* OH_UdmfProperty_GetExtrasStringParam(OH_UdmfProperty* pThis, const char* key)](#oh_udmfproperty_getextrasstringparam) | - | Obtains the customized extra string parameter from an [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md) instance.|
| [int OH_UdmfProperty_SetTag(OH_UdmfProperty* pThis, const char* tag)](#oh_udmfproperty_settag) | - | Sets the tag value for an [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md) instance.|
| [int OH_UdmfProperty_SetShareOption(OH_UdmfProperty* pThis, Udmf_ShareOption option)](#oh_udmfproperty_setshareoption) | - | Sets the [Udmf_ShareOption](capi-udmf-h.md#udmf_shareoption) for an [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md) instance.|
| [int OH_UdmfProperty_SetExtrasIntParam(OH_UdmfProperty* pThis, const char* key, int param)](#oh_udmfproperty_setextrasintparam) | - | Sets the extra integer parameter for an [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md) instance.|
| [int OH_UdmfProperty_SetExtrasStringParam(OH_UdmfProperty* pThis, const char* key, const char* param)](#oh_udmfproperty_setextrasstringparam) | - | Sets the extra string parameter for an [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md) instance.|
| [OH_UdmfOptions* OH_UdmfOptions_Create()](#oh_udmfoptions_create) | - | Creates an [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md) instance.|
| [void OH_UdmfOptions_Destroy(OH_UdmfOptions* pThis)](#oh_udmfoptions_destroy) | - | Destroys an [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md) instance.|
| [const char* OH_UdmfOptions_GetKey(OH_UdmfOptions* pThis)](#oh_udmfoptions_getkey) | - | Obtains the key (unique identifier) from an [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md) instance.|
| [int OH_UdmfOptions_SetKey(OH_UdmfOptions* pThis, const char* key)](#oh_udmfoptions_setkey) | - | Sets the key (unique identifier) in an [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md) instance.|
| [Udmf_Intention OH_UdmfOptions_GetIntention(OH_UdmfOptions* pThis)](#oh_udmfoptions_getintention) | - | Obtains the data channel information from an [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md) instance.|
| [int OH_UdmfOptions_SetIntention(OH_UdmfOptions* pThis, Udmf_Intention intention)](#oh_udmfoptions_setintention) | - | Sets the data channel content parameter in an [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md) instance.|
| [int OH_UdmfOptions_Reset(OH_UdmfOptions* pThis)](#oh_udmfoptions_reset) | - | Resets an [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md) instance to empty.|
| [int OH_Udmf_GetUnifiedData(const char* key, Udmf_Intention intention, OH_UdmfData* unifiedData)](#oh_udmf_getunifieddata) | - | Obtains an [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance from the UDMF database.|
| [int OH_Udmf_GetUnifiedDataByOptions(OH_UdmfOptions* options, OH_UdmfData** dataArray, unsigned int* dataSize)](#oh_udmf_getunifieddatabyoptions) | - | Obtains an [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance from the UDMF database by data channel type.|
| [int OH_Udmf_SetUnifiedData(Udmf_Intention intention, OH_UdmfData* unifiedData, char* key, unsigned int keyLen)](#oh_udmf_setunifieddata) | - | Sets an [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance in the UDMF database.|
| [int OH_Udmf_SetUnifiedDataByOptions(OH_UdmfOptions* options, OH_UdmfData *unifiedData, char *key, unsigned int keyLen)](#oh_udmf_setunifieddatabyoptions) | - | Sets an [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance in the UDMF database.|
| [int OH_Udmf_UpdateUnifiedData(OH_UdmfOptions* options, OH_UdmfData* unifiedData)](#oh_udmf_updateunifieddata) | - | Updates an [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance in the UDMF database.|
| [int OH_Udmf_DeleteUnifiedData(OH_UdmfOptions* options, OH_UdmfData** dataArray, unsigned int* dataSize)](#oh_udmf_deleteunifieddata) | - | Deletes an [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance from the UDMF database.|
| [void OH_Udmf_DestroyDataArray(OH_UdmfData** dataArray, unsigned int dataSize)](#oh_udmf_destroydataarray) | - | Destroys the memory of the data array.|
| [int OH_UdmfProgressInfo_GetProgress(OH_Udmf_ProgressInfo* progressInfo)](#oh_udmfprogressinfo_getprogress) | - | Obtains the progress (in percentage) from an [OH_Udmf_ProgressInfo](capi-udmf-oh-udmf-progressinfo.md) instance.|
| [int OH_UdmfProgressInfo_GetStatus(OH_Udmf_ProgressInfo* progressInfo)](#oh_udmfprogressinfo_getstatus) | - | Obtains the status information from an [OH_Udmf_ProgressInfo](capi-udmf-oh-udmf-progressinfo.md) instance.|
| [OH_UdmfGetDataParams* OH_UdmfGetDataParams_Create()](#oh_udmfgetdataparams_create) | - | Creates an [OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md) instance and a pointer to it.<br>If this pointer is no longer required, use [OH_UdmfGetDataParams_Destroy](capi-udmf-h.md#oh_udmfgetdataparams_destroy) to destroy it. Otherwise, memory leaks may occur.|
| [void OH_UdmfGetDataParams_Destroy(OH_UdmfGetDataParams* pThis)](#oh_udmfgetdataparams_destroy) | - | Destroys an [OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md) instance.|
| [void OH_UdmfGetDataParams_SetDestUri(OH_UdmfGetDataParams* params, const char* destUri)](#oh_udmfgetdataparams_setdesturi) | - | Sets the destination directory in an [OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md) instance.<br>If the destination directory is set, data of the file type will be copied to the specified directory. The file type data obtained in the callback will be replaced with the URI of the destination directory.<br>If the destination directory is not specified, the file will not be copied. The file type data obtained in the callback is the URI of the source directory.<br>If the application involves complex file processing or files need to be copied to multiple directories, you are advised to leave this parameter unspecified and let the application handle the file copy.|
| [void OH_UdmfGetDataParams_SetFileConflictOptions(OH_UdmfGetDataParams* params, const Udmf_FileConflictOptions options)](#oh_udmfgetdataparams_setfileconflictoptions) | - | Sets the policy for resolving file conflicts in an [OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md) instance.|
| [void OH_UdmfGetDataParams_SetProgressIndicator(OH_UdmfGetDataParams* params, const Udmf_ProgressIndicator progressIndicator)](#oh_udmfgetdataparams_setprogressindicator) | - | Sets the progress indicator in an [OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md) instance.|
| [void OH_UdmfGetDataParams_SetDataProgressListener(OH_UdmfGetDataParams* params, const OH_Udmf_DataProgressListener dataProgressListener)](#oh_udmfgetdataparams_setdataprogresslistener) | - | Sets the callback used to return the progress obtained in an [OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md) instance.|
| [Udmf_Visibility OH_UdmfOptions_GetVisibility(OH_UdmfOptions* pThis)](#oh_udmfoptions_getvisibility) | - | Obtains the data visibility level from an [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md) instance.|
| [int OH_UdmfOptions_SetVisibility(OH_UdmfOptions* pThis, Udmf_Visibility visibility)](#oh_udmfoptions_setvisibility) | - | Sets the data visibility level in an [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md) instance.|
| [typedef OH_UdmfData* (\*OH_Udmf_DataLoadHandler)(OH_UdmfDataLoadInfo* acceptableInfo)](#oh_udmf_dataloadhandler) | OH_Udmf_DataLoadHandler | Defines the callback used to load data.|
| [OH_UdmfDataLoadParams* OH_UdmfDataLoadParams_Create()](#oh_udmfdataloadparams_create) | - | Creates an [OH_UdmfDataLoadParams](capi-udmf-oh-udmfdataloadparams.md) instance and a pointer to it.|
| [void OH_UdmfDataLoadParams_Destroy(OH_UdmfDataLoadParams* pThis)](#oh_udmfdataloadparams_destroy) | - | Destroys an [OH_UdmfDataLoadParams](capi-udmf-oh-udmfdataloadparams.md) instance.|
| [void OH_UdmfDataLoadParams_SetLoadHandler(OH_UdmfDataLoadParams* params, const OH_Udmf_DataLoadHandler dataLoadHandler)](#oh_udmfdataloadparams_setloadhandler) | - | Sets the processing function for data loading in an [OH_UdmfDataLoadParams](capi-udmf-oh-udmfdataloadparams.md) instance.|
| [void OH_UdmfDataLoadParams_SetDataLoadInfo(OH_UdmfDataLoadParams* params, OH_UdmfDataLoadInfo* dataLoadInfo)](#oh_udmfdataloadparams_setdataloadinfo) | - | Sets data loading information in an [OH_UdmfDataLoadParams](capi-udmf-oh-udmfdataloadparams.md) instance.|
| [OH_UdmfDataLoadInfo* OH_UdmfDataLoadInfo_Create()](#oh_udmfdataloadinfo_create) | - | Creates an [OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md) instance.|
| [void OH_UdmfDataLoadInfo_Destroy(OH_UdmfDataLoadInfo* dataLoadInfo)](#oh_udmfdataloadinfo_destroy) | - | Destroys an [OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md) instance.|
| [char** OH_UdmfDataLoadInfo_GetTypes(OH_UdmfDataLoadInfo* dataLoadInfo, unsigned int* count)](#oh_udmfdataloadinfo_gettypes) | - | Obtains the data types from an [OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md) instance.|
| [void OH_UdmfDataLoadInfo_SetType(OH_UdmfDataLoadInfo* dataLoadInfo, const char* type)](#oh_udmfdataloadinfo_settype) | - | Sets the data type in an [OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md) instance.|
| [int OH_UdmfDataLoadInfo_GetRecordCount(OH_UdmfDataLoadInfo* dataLoadInfo)](#oh_udmfdataloadinfo_getrecordcount) | - | Obtains the number of records in an [OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md) instance.|
| [void OH_UdmfDataLoadInfo_SetRecordCount(OH_UdmfDataLoadInfo* dataLoadInfo, unsigned int recordCount)](#oh_udmfdataloadinfo_setrecordcount) | - | Sets the number of records in an [OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md) instance.|

## Enum Description

### Udmf_Intention

```
enum Udmf_Intention
```

**Description**

Enumerates the UDMF data channel types.

**Since**: 12

| Name| Description|
| -- | -- |
| UDMF_INTENTION_DRAG | Channel for dragging data.|
| UDMF_INTENTION_PASTEBOARD | Channel for pasteboard data.|
| UDMF_INTENTION_DATA_HUB | Public data channel.<br>**Since**: 20|
| UDMF_INTENTION_SYSTEM_SHARE | Channel for sharing data by the system.<br>**Since**: 20|
| UDMF_INTENTION_PICKER | Channel for picker data.<br>**Since**: 20|
| UDMF_INTENTION_MENU | Channel for menu data.<br>**Since**: 20|

### Udmf_ShareOption

```
enum Udmf_ShareOption
```

**Description**

Enumerates the options for using the unified data in a device.

**Since**: 12

| Name| Description|
| -- | -- |
| SHARE_OPTIONS_INVALID | Invalid use.|
| SHARE_OPTIONS_IN_APP | **UnifiedData** can be used only in the same application of a device.|
| SHARE_OPTIONS_CROSS_APP | **UnifiedData** can be used across applications of a device.|

### Udmf_FileConflictOptions

```
enum Udmf_FileConflictOptions
```

**Description**

Enumerates the options used to resolve file copy conflicts.

**Since**: 15

| Name| Description|
| -- | -- |
| UDMF_OVERWRITE = 0 | Overwrites the file with the same name in the destination directory. This is the default value.|
| UDMF_SKIP = 1 | Skips the file if there is a file with the same name in the destination directory.|

### Udmf_ProgressIndicator

```
enum Udmf_ProgressIndicator
```

**Description**

Enumerates the progress indicator options. You can use the default progress indicator as required.

**Since**: 15

| Name| Description|
| -- | -- |
| UDMF_NONE = 0 | The default progress indicator is not used.|
| UDMF_DEFAULT = 1 | The default progress indicator is used. If data is obtained within 500 ms, the default progress bar is not started.|

### Udmf_Visibility

```
enum Udmf_Visibility
```

**Description**

Enumerates data visibility level.

**Since**: 20

| Name| Description|
| -- | -- |
| UDMF_ALL | Visible to all applications.|
| UDMF_OWN_PROCESS | Visible only to the data provider.|

## Function Description

### OH_UdmfGetDataParams_SetAcceptableInfo()

```
void OH_UdmfGetDataParams_SetAcceptableInfo(OH_UdmfGetDataParams* params, OH_UdmfDataLoadInfo* acceptableInfo)
```

**Description**

Sets the acceptable data description in an [OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md) instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md)* params | Pointer to the [OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md) instance.|
| [OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md)* acceptableInfo | Pointer to the [OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md) instance.|

### OH_UdmfDataLoadParams_Create()

```
OH_UdmfDataLoadParams* OH_UdmfDataLoadParams_Create()
```

**Description**

Creates an [OH_UdmfDataLoadParams](capi-udmf-oh-udmfdataloadparams.md) instance and a pointer to it.

**Since**: 20

**Returns**

| Type| Description|
| -- | -- |
| [OH_UdmfDataLoadParams](capi-udmf-oh-udmfdataloadparams.md)* | Returns a pointer to the [OH_UdmfDataLoadParams](capi-udmf-oh-udmfdataloadparams.md) instance created if the operation is successful; returns **nullptr** otherwise.|

### OH_UdmfDataLoadParams_Destroy()

```
void OH_UdmfDataLoadParams_Destroy(OH_UdmfDataLoadParams* pThis)
```

**Description**

Destroys an [OH_UdmfDataLoadParams](capi-udmf-oh-udmfdataloadparams.md) instance.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfDataLoadParams](capi-udmf-oh-udmfdataloadparams.md)* pThis | Creates an [OH_UdmfDataLoadParams](capi-udmf-oh-udmfdataloadparams.md) instance and a pointer to it.|

### OH_UdmfDataLoadParams_SetLoadHandler()

```
void OH_UdmfDataLoadParams_SetLoadHandler(OH_UdmfDataLoadParams* params, const OH_Udmf_DataLoadHandler dataLoadHandler)
```

**Description**

Sets the processing function for data loading in an [OH_UdmfDataLoadParams](capi-udmf-oh-udmfdataloadparams.md) instance.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfDataLoadParams](capi-udmf-oh-udmfdataloadparams.md)* params | Creates an [OH_UdmfDataLoadParams](capi-udmf-oh-udmfdataloadparams.md) instance and a pointer to it.|
| [const OH_Udmf_DataLoadHandler](capi-udmf-h.md#oh_udmf_dataloadhandler) dataLoadHandler | User-defined processing function for data loading.|

### OH_UdmfDataLoadParams_SetDataLoadInfo()

```
void OH_UdmfDataLoadParams_SetDataLoadInfo(OH_UdmfDataLoadParams* params, OH_UdmfDataLoadInfo* dataLoadInfo)
```

**Description**

Sets data loading information in an [OH_UdmfDataLoadParams](capi-udmf-oh-udmfdataloadparams.md) instance.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfDataLoadParams](capi-udmf-oh-udmfdataloadparams.md)* params | Pointer to the [OH_UdmfDataLoadParams](capi-udmf-oh-udmfdataloadparams.md) instance.|
| [OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md)* dataLoadInfo | Pointer to the [OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md) instance.|

### OH_UdmfDataLoadInfo_Create()

```
OH_UdmfDataLoadInfo* OH_UdmfDataLoadInfo_Create()
```

**Description**

Creates an [OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md) instance.

**Since**: 20

**Returns**

| Type| Description|
| -- | -- |
| [OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md)* | Returns a pointer to the [OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md) instance created if the operation is successful; returns **nullptr** otherwise.|

### OH_UdmfDataLoadInfo_Destroy()

```
void OH_UdmfDataLoadInfo_Destroy(OH_UdmfDataLoadInfo* dataLoadInfo)
```

**Description**

Destroys an [OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md) instance.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md)* dataLoadInfo | Pointer to the [OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md) instance.|

### OH_UdmfDataLoadInfo_GetTypes()

```
char** OH_UdmfDataLoadInfo_GetTypes(OH_UdmfDataLoadInfo* dataLoadInfo, unsigned int* count)
```

**Description**

Obtains the data types from an [OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md) instance.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md)* dataLoadInfo | Pointer to the [OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md) instance.|
| unsigned int* count | Number of data types returned.|

**Returns**

| Type| Description|
| -- | -- |
| char** | String array of the returned data types.|

### OH_UdmfDataLoadInfo_SetType()

```
void OH_UdmfDataLoadInfo_SetType(OH_UdmfDataLoadInfo* dataLoadInfo, const char* type)
```

**Description**

Sets the data type in an [OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md) instance.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md)* dataLoadInfo | Creates an [OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md) instance.|
| const char* type | A sting indicating the data type.|

### OH_UdmfDataLoadInfo_GetRecordCount()

```
int OH_UdmfDataLoadInfo_GetRecordCount(OH_UdmfDataLoadInfo* dataLoadInfo)
```

**Description**

Obtains the number of records in an [OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md) instance.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md)* dataLoadInfo | Creates an [OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| int | Number of records.|

### OH_UdmfDataLoadInfo_SetRecordCount()

```
void OH_UdmfDataLoadInfo_SetRecordCount(OH_UdmfDataLoadInfo* dataLoadInfo, unsigned int recordCount)
```

**Description**

Sets the number of records in an [OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md) instance.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md)* dataLoadInfo | Creates an [OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md) instance.|
| unsigned int recordCount | Number of records.|

### OH_Udmf_DataLoadHandler()

```
typedef OH_UdmfData* (*OH_Udmf_DataLoadHandler)(OH_UdmfDataLoadInfo* acceptableInfo)
```

**Description**

Defines the callback used to load data.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfDataLoadInfo](capi-udmf-oh-udmfdataloadinfo.md)* acceptableInfo | Data type and data size that can be received.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_UdmfData](capi-udmf-oh-udmfdata.md)* (*OH_Udmf_DataLoadHandler) | Data to be loaded.|

### OH_UdmfOptions_GetVisibility()

```
Udmf_Visibility OH_UdmfOptions_GetVisibility(OH_UdmfOptions* pThis)
```

**Description**

Obtains the data visibility level from an [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md) instance.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)* pThis | Pointer to the [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| [Udmf_Visibility](capi-udmf-h.md#udmf_visibility) | Value of the [Udmf_Visibility](capi-udmf-h.md#udmf_visibility) instance obtained.|

### OH_UdmfOptions_SetVisibility()

```
int OH_UdmfOptions_SetVisibility(OH_UdmfOptions* pThis, Udmf_Visibility visibility)
```

**Description**

Sets the data visibility level in an [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md) instance.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)* pThis | Pointer to the [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md) instance.|
| [Udmf_Visibility](capi-udmf-h.md#udmf_visibility) visibility | Data visibility level [Udmf_Visibility](capi-udmf-h.md#udmf_visibility).|

**Returns**

| Type| Description|
| -- | -- |
| int | Execution result. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br> Returns **UDMF_E_OK** if the operation is successful.<br> Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### UDMF_KEY_BUFFER_LEN()

```
UDMF_KEY_BUFFER_LEN (512)
```

**Description**

Defines minimum length of the buffer that holds the key (unique identifier) of a unified data object.

**Since**: 12

### OH_Udmf_DataProgressListener()

```
typedef void (*OH_Udmf_DataProgressListener)(OH_Udmf_ProgressInfo* progressInfo, OH_UdmfData* data)
```

**Description**

Defines the callback used to return the data retrieval progress information and data obtained.<br>A null pointer is returned if the progress is less than 100%. The data obtained is returned only when the progress reaches 100%.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Udmf_ProgressInfo](capi-udmf-oh-udmf-progressinfo.md)* progressInfo | Progress information obtained.|
| [OH_UdmfData](capi-udmf-oh-udmfdata.md)* data | Data obtained.|

### OH_UdmfData_Create()

```
OH_UdmfData* OH_UdmfData_Create()
```

**Description**

Creates an [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance and a pointer to it. If this pointer is no longer required, use [OH_UdmfData_Destroy](capi-udmf-h.md#oh_udmfdata_destroy) to destroy it. Otherwise, memory leaks may occur.

**Since**: 12

**Returns**

| Type| Description|
| -- | -- |
| [OH_UdmfData](capi-udmf-oh-udmfdata.md)* | Returns a pointer to the [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance created if the operation is successful; returns **nullptr** otherwise.|

**See**

OH_UdmfData

### OH_UdmfData_Destroy()

```
void OH_UdmfData_Destroy(OH_UdmfData* pThis)
```

**Description**

Destroys an [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfData](capi-udmf-oh-udmfdata.md)* pThis | Pointer to the [OH_UdmfData](../apis-arkdata/capi-udmf-oh-udmfdata.md) instance.|

**See**

OH_UdmfData

### OH_UdmfData_AddRecord()

```
int OH_UdmfData_AddRecord(OH_UdmfData* pThis, OH_UdmfRecord* record)
```

**Description**

Adds an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) to an [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfData](capi-udmf-oh-udmfdata.md)* pThis | Pointer to the [OH_UdmfData](../apis-arkdata/capi-udmf-oh-udmfdata.md) instance.|
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* record | Pointer to the [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| int | Error code. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdmfData_HasType()

```
bool OH_UdmfData_HasType(OH_UdmfData* pThis, const char* type)
```

**Description**

Checks whether the specified type exists in an [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfData](capi-udmf-oh-udmfdata.md)* pThis | Pointer to the [OH_UdmfData](../apis-arkdata/capi-udmf-oh-udmfdata.md) instance.|
| const char* type | Pointer to the type to check.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Check result. The value **true** means the **OH_UdmfData** instance contains the specified type; the value **false** means the opposite.|

### OH_UdmfData_GetTypes()

```
char** OH_UdmfData_GetTypes(OH_UdmfData* pThis, unsigned int* count)
```

**Description**

Obtains all data types in an [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfData](capi-udmf-oh-udmfdata.md)* pThis | Pointer to the [OH_UdmfData](../apis-arkdata/capi-udmf-oh-udmfdata.md) instance.|
| unsigned int* count | Pointer to the number of data types obtained.|

**Returns**

| Type| Description|
| -- | -- |
| char** | Returns the data types obtained if the operation is successful; returns **nullptr** otherwise.|

### OH_UdmfData_GetRecords()

```
OH_UdmfRecord** OH_UdmfData_GetRecords(OH_UdmfData* pThis, unsigned int* count)
```

**Description**

Obtains all records contained in an [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfData](capi-udmf-oh-udmfdata.md)* pThis | Pointer to the [OH_UdmfData](../apis-arkdata/capi-udmf-oh-udmfdata.md) instance.|
| unsigned int* count | Pointer to the number of records obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)** | Returns a pointer to the [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance created if the operation is successful; returns **nullptr** otherwise.|

### UdmfData_Finalize()

```
typedef void (*UdmfData_Finalize)(void* context)
```

**Description**

Defines a callback function used to release the context. This callback is invoked when the **OH_UdmfRecordProvider** instance is destroyed.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| void* context | Pointer to the context to release.|

### OH_UdmfRecordProvider_Create()

```
OH_UdmfRecordProvider* OH_UdmfRecordProvider_Create()
```

**Description**

Creates an [OH_UdmfRecordProvider](capi-udmf-oh-udmfrecordprovider.md) instance and a pointer to it. If this pointer is no longer required, use [OH_UdmfRecordProvider_Destroy](capi-udmf-h.md#oh_udmfrecordprovider_destroy) to destroy it. Otherwise, memory leaks may occur.

**Since**: 13

**Returns**

| Type| Description|
| -- | -- |
| [OH_UdmfRecordProvider](capi-udmf-oh-udmfrecordprovider.md)* | Returns a pointer to the [OH_UdmfRecordProvider](capi-udmf-oh-udmfrecordprovider.md) instance created if the operation is successful; returns **nullptr** otherwise.|

### OH_UdmfRecordProvider_Destroy()

```
int OH_UdmfRecordProvider_Destroy(OH_UdmfRecordProvider* provider)
```

**Description**

Destroys an [OH_UdmfRecordProvider](capi-udmf-oh-udmfrecordprovider.md) instance.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfRecordProvider](capi-udmf-oh-udmfrecordprovider.md)* provider | Pointer to the [OH_UdmfRecordProvider](capi-udmf-oh-udmfrecordprovider.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| int | Error code. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdmfRecordProvider_GetData()

```
typedef void* (*OH_UdmfRecordProvider_GetData)(void* context, const char* type)
```

**Description**

Defines a callback function used to obtain data by type. This callback will be invoked to return the data obtained from **OH_UdmfRecord**.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| void* context | Pointer to the context set by [OH_UdmfRecordProvider_SetData](capi-udmf-h.md#oh_udmfrecordprovider_setdata).|
|  const char* type | Pointer to the type of the data to obtain. For details, see [udmf_meta.h](capi-udmf-meta-h.md).|

**Returns**

| Type| Description|
| -- | -- |
| void* | Uniform data obtained.|

### OH_UdmfRecordProvider_SetData()

```
int OH_UdmfRecordProvider_SetData(OH_UdmfRecordProvider* provider, void* context, const OH_UdmfRecordProvider_GetData callback, const UdmfData_Finalize finalize)
```

**Description**

Sets a callback for an **OH_UdmfRecordProvider** instance to provide data.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfRecordProvider](capi-udmf-oh-udmfrecordprovider.md)* provider | Pointer to the [OH_UdmfRecordProvider](capi-udmf-oh-udmfrecordprovider.md) instance.|
| void* context | Pointer to the context, which is passed as the first parameter to [OH_UdmfRecordProvider_GetData](capi-udmf-h.md#oh_udmfrecordprovider_getdata).|
| const [OH_UdmfRecordProvider_GetData](#oh_udmfrecordprovider_getdata) callback | Callback used to obtain data. For details, see [OH_UdmfRecordProvider_GetData](capi-udmf-h.md#oh_udmfrecordprovider_getdata).|
| const [UdmfData_Finalize](#udmfdata_finalize) finalize | Optional callback used to release the context data when the **OH_UdmfRecordProvider** instance is destroyed. For details, see [UdmfData_Finalize](capi-udmf-h.md#udmfdata_finalize).|

**Returns**

| Type| Description|
| -- | -- |
| int | Error code. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdmfRecord_Create()

```
OH_UdmfRecord* OH_UdmfRecord_Create()
```

**Description**

Creates an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance and a pointer to it. If this pointer is no longer required, use [OH_UdmfRecord_Destroy](capi-udmf-h.md#oh_udmfrecord_destroy) to destroy it. Otherwise, memory leaks may occur.

**Since**: 12

**Returns**

| Type| Description|
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* | Returns a pointer to the [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance created if the operation is successful; returns **nullptr** otherwise.|

### OH_UdmfRecord_Destroy()

```
void OH_UdmfRecord_Destroy(OH_UdmfRecord* pThis)
```

**Description**

Destroys an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* pThis | Pointer to the [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.|

### OH_UdmfRecord_AddGeneralEntry()

```
int OH_UdmfRecord_AddGeneralEntry(OH_UdmfRecord* pThis, const char* typeId, unsigned char* entry, unsigned int count)
```

**Description**

Adds customized general data to an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance. This API cannot be used to add data of UDS types (such as PlainText, Link, and Pixelmap).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* pThis | Pointer to the [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.|
| const char* typeId | Pointer to the data type identifier, which is used to distinguish custom data types from system-defined types. It is recommended that the value start with 'ApplicationDefined'.|
| unsigned char* entry | Pointer to the customized data to add.|
| unsigned int count | Size of customized data to add. The data size cannot exceed 4 KB.|

**Returns**

| Type| Description|
| -- | -- |
| int | Error code. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdmfRecord_AddPlainText()

```
int OH_UdmfRecord_AddPlainText(OH_UdmfRecord* pThis, OH_UdsPlainText* plainText)
```

**Description**

Adds data of the [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md) type to an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* pThis | Pointer to the [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.|
| [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)* plainText | Pointer to the [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| int | Error code. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdmfRecord_AddHyperlink()

```
int OH_UdmfRecord_AddHyperlink(OH_UdmfRecord* pThis, OH_UdsHyperlink* hyperlink)
```

**Description**

Adds data of the [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md) type to an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* pThis | Pointer to the [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.|
| [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)* hyperlink | Pointer to the [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| int | Error code. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdmfRecord_AddHtml()

```
int OH_UdmfRecord_AddHtml(OH_UdmfRecord* pThis, OH_UdsHtml* html)
```

**Description**

Adds data of the [OH_UdsHtml](capi-udmf-oh-udshtml.md) type to an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* pThis | Pointer to the [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.|
| [OH_UdsHtml](capi-udmf-oh-udshtml.md)* html | Pointer to the [OH_UdsHtml](capi-udmf-oh-udshtml.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| int | Error code. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdmfRecord_AddAppItem()

```
int OH_UdmfRecord_AddAppItem(OH_UdmfRecord* pThis, OH_UdsAppItem* appItem)
```

**Description**

Adds data of the [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) type to an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* pThis | Pointer to the [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.|
| [OH_UdsAppItem](capi-udmf-oh-udsappitem.md)* appItem | Pointer to the [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| int | Error code. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdmfRecord_AddFileUri()

```
int OH_UdmfRecord_AddFileUri(OH_UdmfRecord* pThis, OH_UdsFileUri* fileUri)
```

**Description**

Adds data of the [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md) type to an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* pThis | Pointer to the [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.|
| [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)* fileUri | Pointer to the [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| int | Error code. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdmfRecord_AddPixelMap()

```
int OH_UdmfRecord_AddPixelMap(OH_UdmfRecord* pThis, OH_UdsPixelMap* pixelMap)
```

**Description**

Adds data of the [OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md) type to an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* pThis | Pointer to the [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.|
| [OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md)* pixelMap | Pointer to the [OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| int | Error code. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdmfRecord_AddArrayBuffer()

```
int OH_UdmfRecord_AddArrayBuffer(OH_UdmfRecord* record, const char* type, OH_UdsArrayBuffer* buffer)
```

**Description**

Adds data of the [OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md) type to an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* record | Pointer to the [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.|
| const char* type | Pointer to the ArrayBuffer type ID, which must be unique.|
| [OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md)* buffer | Pointer to the [OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| int | Error code. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdmfRecord_AddContentForm()

```
int OH_UdmfRecord_AddContentForm(OH_UdmfRecord* pThis, OH_UdsContentForm* contentForm)
```

**Description**

Adds data of the [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) type to an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.

**Since**: 14


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* pThis | Pointer to the [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.|
| [OH_UdsContentForm](capi-udmf-oh-udscontentform.md)* contentForm | Pointer to the [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| int | Error code. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdmfRecord_GetTypes()

```
char** OH_UdmfRecord_GetTypes(OH_UdmfRecord* pThis, unsigned int* count)
```

**Description**

Obtains all data types in an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* pThis | Pointer to the [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.|
| unsigned int* count | Pointer to the number of data types obtained.|

**Returns**

| Type| Description|
| -- | -- |
| char** | Returns a list of data types obtained if the operation is successful; returns **nullptr** otherwise.|

### OH_UdmfRecord_GetGeneralEntry()

```
int OH_UdmfRecord_GetGeneralEntry(OH_UdmfRecord* pThis, const char* typeId, unsigned char** entry, unsigned int* count)
```

**Description**

Obtains the data of the specified type in an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* pThis | Pointer to the [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.|
| const char* typeId | Pointer to the data type ID.|
| unsigned char** entry | Double pointer to the data obtained.|
| unsigned int* count | Pointer to the length of the data obtained.|

**Returns**

| Type| Description|
| -- | -- |
| int | Error code. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.<br>Returns **UDMF_ERR** if an internal data error occurs.|

### OH_UdmfRecord_GetPlainText()

```
int OH_UdmfRecord_GetPlainText(OH_UdmfRecord* pThis, OH_UdsPlainText* plainText)
```

**Description**

Obtains [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md) data from an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* pThis | Pointer to the [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.|
| [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)* plainText | Pointer to the [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| int | Error code. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.<br>Returns **UDMF_ERR** if an internal data error occurs.|

### OH_UdmfRecord_GetHyperlink()

```
int OH_UdmfRecord_GetHyperlink(OH_UdmfRecord* pThis, OH_UdsHyperlink* hyperlink)
```

**Description**

Obtains [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md) data from an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* pThis | Pointer to the [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.|
| [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md)* hyperlink | Pointer to the [OH_UdsHyperlink](capi-udmf-oh-udshyperlink.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| int | Error code. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.<br>Returns **UDMF_ERR** if an internal data error occurs.|

### OH_UdmfRecord_GetHtml()

```
int OH_UdmfRecord_GetHtml(OH_UdmfRecord* pThis, OH_UdsHtml* html)
```

**Description**

Obtains [OH_UdsHtml](capi-udmf-oh-udshtml.md) data from an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* pThis | Pointer to the [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.|
| [OH_UdsHtml](capi-udmf-oh-udshtml.md)* html | Pointer to the [OH_UdsHtml](capi-udmf-oh-udshtml.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| int | Error code. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.<br>Returns **UDMF_ERR** if an internal data error occurs.|

### OH_UdmfRecord_GetAppItem()

```
int OH_UdmfRecord_GetAppItem(OH_UdmfRecord* pThis, OH_UdsAppItem* appItem)
```

**Description**

Obtains [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) data from an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* pThis | Pointer to the [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.|
| [OH_UdsAppItem](capi-udmf-oh-udsappitem.md)* appItem | Pointer to the [OH_UdsAppItem](capi-udmf-oh-udsappitem.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| int | Error code. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.<br>Returns **UDMF_ERR** if an internal data error occurs.|

### OH_UdmfRecord_SetProvider()

```
int OH_UdmfRecord_SetProvider(OH_UdmfRecord* pThis, const char* const* types, unsigned int count, OH_UdmfRecordProvider* provider)
```

**Description**

Sets the [OH_UdmfRecordProvider](capi-udmf-oh-udmfrecordprovider.md) in an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* pThis | Pointer to the [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.|
| const char* const* types | Pointer to the data types to be provided.|
| unsigned int count | Number of the data types.|
| [OH_UdmfRecordProvider](capi-udmf-oh-udmfrecordprovider.md)* provider | Pointer to the [OH_UdmfRecordProvider](capi-udmf-oh-udmfrecordprovider.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| int | Error code. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdmfRecord_GetFileUri()

```
int OH_UdmfRecord_GetFileUri(OH_UdmfRecord* pThis, OH_UdsFileUri* fileUri)
```

**Description**

Obtains [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md) data from an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* pThis | Pointer to the [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.|
| [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md)* fileUri | Pointer to the [OH_UdsFileUri](capi-udmf-oh-udsfileuri.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| int | Error code. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdmfRecord_GetPixelMap()

```
int OH_UdmfRecord_GetPixelMap(OH_UdmfRecord* pThis, OH_UdsPixelMap* pixelMap)
```

**Description**

Obtains [OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md) data from an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* pThis | Pointer to the [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.|
| [OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md)* pixelMap | Pointer to the [OH_UdsPixelMap](capi-udmf-oh-udspixelmap.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| int | Error code. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdmfRecord_GetArrayBuffer()

```
int OH_UdmfRecord_GetArrayBuffer(OH_UdmfRecord* record, const char* type, OH_UdsArrayBuffer* buffer)
```

**Description**

Obtains [OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md) data from an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* record | Pointer to the [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.|
| const char* type | Pointer to the data type ID of the ArrayBuffer data to obtain.|
| [OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md)* buffer | Pointer to the [OH_UdsArrayBuffer](capi-udmf-oh-udsarraybuffer.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| int | Error code. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdmfRecord_GetContentForm()

```
int OH_UdmfRecord_GetContentForm(OH_UdmfRecord* pThis, OH_UdsContentForm* contentForm)
```

**Description**

Obtains [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) data from an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.

**Since**: 14


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* pThis | Pointer to the [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.|
| [OH_UdsContentForm](capi-udmf-oh-udscontentform.md)* contentForm | Pointer to the [OH_UdsContentForm](capi-udmf-oh-udscontentform.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| int | Error code. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdmfData_GetPrimaryPlainText()

```
int OH_UdmfData_GetPrimaryPlainText(OH_UdmfData* data, OH_UdsPlainText* plainText)
```

**Description**

Obtains the first [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md) data from an [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfData](capi-udmf-oh-udmfdata.md)* data | Pointer to the [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance.|
| [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md)* plainText | Pointer to the [OH_UdsPlainText](capi-udmf-oh-udsplaintext.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| int | Error code. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdmfData_GetPrimaryHtml()

```
int OH_UdmfData_GetPrimaryHtml(OH_UdmfData* data, OH_UdsHtml* html)
```

**Description**

Obtains the first [OH_UdsHtml](capi-udmf-oh-udshtml.md) data from an [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfData](capi-udmf-oh-udmfdata.md)* data | Pointer to the [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance.|
| [OH_UdsHtml](capi-udmf-oh-udshtml.md)* html | Pointer to the [OH_UdsHtml](capi-udmf-oh-udshtml.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| int | Error code. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdmfData_GetRecordCount()

```
int OH_UdmfData_GetRecordCount(OH_UdmfData* data)
```

**Description**

Obtains the number of data records contained in an [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfData](capi-udmf-oh-udmfdata.md)* data | Pointer to the [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| int | Number of the data records in an [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance obtained.|

### OH_UdmfData_GetRecord()

```
OH_UdmfRecord* OH_UdmfData_GetRecord(OH_UdmfData* data, unsigned int index)
```

**Description**

Obtains the specified data record from an [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfData](capi-udmf-oh-udmfdata.md)* data | Pointer to the [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance.|
| unsigned int index | Subscript of the [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance to be obtained in [OH_UdmfData](capi-udmf-oh-udmfdata.md).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md)* | Returns a pointer to the [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance created if the operation is successful; returns **nullptr** otherwise.|

### OH_UdmfData_IsLocal()

```
bool OH_UdmfData_IsLocal(OH_UdmfData* data)
```

**Description**

Checks whether an [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance is from the local device.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfData](capi-udmf-oh-udmfdata.md)* data | Pointer to the [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Check result. The value **true** means the data is from the local device; the value **false** means the opposite.|

### OH_UdmfProperty_Create()

```
OH_UdmfProperty* OH_UdmfProperty_Create(OH_UdmfData* unifiedData)
```

**Description**

Creates an [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md) instance and a pointer to it. If this pointer is no longer required, use [OH_UdmfProperty_Destroy](capi-udmf-h.md#oh_udmfproperty_destroy) to destroy it. Otherwise, memory leaks may occur.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfData](capi-udmf-oh-udmfdata.md)* unifiedData | Pointer to the [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)* | Returns a pointer to the [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md) instance created if the operation is successful; returns **nullptr** otherwise.|

### OH_UdmfProperty_Destroy()

```
void OH_UdmfProperty_Destroy(OH_UdmfProperty* pThis)
```

**Description**

Destroys an [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md) instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)* pThis | Pointer to the [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md) instance.|

### OH_UdmfProperty_GetTag()

```
const char* OH_UdmfProperty_GetTag(OH_UdmfProperty* pThis)
```

**Description**

Obtains the custom tag value from an [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md) instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)* pThis | Pointer to the [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| const char* | Returns a pointer to the custom tag value obtained if the operation is successful; returns **nullptr** otherwise.|

### OH_UdmfProperty_GetTimestamp()

```
int64_t OH_UdmfProperty_GetTimestamp(OH_UdmfProperty* pThis)
```

**Description**

Obtains the timestamp from an [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md) instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)* pThis | Pointer to the [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| int64_t | Timestamp obtained.|

### OH_UdmfProperty_GetShareOption()

```
Udmf_ShareOption OH_UdmfProperty_GetShareOption(OH_UdmfProperty* pThis)
```

**Description**

Obtains the share option from an [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md) instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)* pThis | Pointer to the [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| [Udmf_ShareOption](#udmf_shareoption) | Share option in the [Udmf_ShareOption](capi-udmf-h.md#udmf_shareoption) instance obtained.|

### OH_UdmfProperty_GetExtrasIntParam()

```
int OH_UdmfProperty_GetExtrasIntParam(OH_UdmfProperty* pThis, const char* key, int defaultValue)
```

**Description**

Obtains the customized extra integer parameter from an [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md) instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)* pThis | Pointer to the [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md) instance.|
| const char* key | Pointer to the key of the parameter to set.|
| int defaultValue | Default value to be returned if the parameter fails to be obtained.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns the integer value obtained if the operation is successful; returns **defaultValue** if the operation fails.|

### OH_UdmfProperty_GetExtrasStringParam()

```
const char* OH_UdmfProperty_GetExtrasStringParam(OH_UdmfProperty* pThis, const char* key)
```

**Description**

Obtains the customized extra string parameter from an [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md) instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)* pThis | Pointer to the [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md) instance.|
| const char* key | Pointer to the key of the parameter to set.|

**Returns**

| Type| Description|
| -- | -- |
| const char* | Returns a pointer to the string value obtained if the operation is successful; returns **nullptr** otherwise.|

### OH_UdmfProperty_SetTag()

```
int OH_UdmfProperty_SetTag(OH_UdmfProperty* pThis, const char* tag)
```

**Description**

Sets the tag value for an [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md) instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)* pThis | Pointer to the [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md) instance.|
| const char* tag | Pointer to the tag value to set.|

**Returns**

| Type| Description|
| -- | -- |
| int | Error code. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdmfProperty_SetShareOption()

```
int OH_UdmfProperty_SetShareOption(OH_UdmfProperty* pThis, Udmf_ShareOption option)
```

**Description**

Sets the [Udmf_ShareOption](capi-udmf-h.md#udmf_shareoption) for an [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md) instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)* pThis | Pointer to the [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md) instance.|
| [Udmf_ShareOption](#udmf_shareoption) option | Pointer to the [Udmf_ShareOption](capi-udmf-h.md#udmf_shareoption) instance.|

**Returns**

| Type| Description|
| -- | -- |
| int | Error code. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdmfProperty_SetExtrasIntParam()

```
int OH_UdmfProperty_SetExtrasIntParam(OH_UdmfProperty* pThis, const char* key, int param)
```

**Description**

Sets the extra integer parameter for an [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md) instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)* pThis | Pointer to the [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.|
| const char* key | Pointer to the key of the parameter to set.|
| int param | Parameter value to set.|

**Returns**

| Type| Description|
| -- | -- |
| int | Error code. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdmfProperty_SetExtrasStringParam()

```
int OH_UdmfProperty_SetExtrasStringParam(OH_UdmfProperty* pThis, const char* key, const char* param)
```

**Description**

Sets the extra string parameter for an [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md) instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfProperty](capi-udmf-oh-udmfproperty.md)* pThis | Pointer to the [OH_UdmfRecord](capi-udmf-oh-udmfrecord.md) instance.|
| const char* key | Pointer to the key of the parameter to set.|
| const char* param | Parameter value to set.|

**Returns**

| Type| Description|
| -- | -- |
| int | Error code. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdmfOptions_Create()

```
OH_UdmfOptions* OH_UdmfOptions_Create()
```

**Description**

Creates an [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md) instance.

**Since**: 20

**Returns**

| Type| Description|
| -- | -- |
| [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)* | Returns a pointer to the [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md) instance created if the operation is successful; returns **nullptr** otherwise.|

### OH_UdmfOptions_Destroy()

```
void OH_UdmfOptions_Destroy(OH_UdmfOptions* pThis)
```

**Description**

Destroys an [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md) instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)* pThis | Pointer to the [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md) instance.|

### OH_UdmfOptions_GetKey()

```
const char* OH_UdmfOptions_GetKey(OH_UdmfOptions* pThis)
```

**Description**

Obtains the key (unique identifier) from an [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md) instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)* pThis | Pointer to the [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| const char* | Returns a pointer to the unique identifier obtained if the operation is successful; returns **nullptr** otherwise.|

### OH_UdmfOptions_SetKey()

```
int OH_UdmfOptions_SetKey(OH_UdmfOptions* pThis, const char* key)
```

**Description**

Sets the key (unique identifier) in an [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md) instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)* pThis | Pointer to the [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md) instance.|
| const char* key | Pointer to the value of the unique identifier of the data.|

**Returns**

| Type| Description|
| -- | -- |
| int | Error code. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdmfOptions_GetIntention()

```
Udmf_Intention OH_UdmfOptions_GetIntention(OH_UdmfOptions* pThis)
```

**Description**

Obtains the data channel information from an [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md) instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)* pThis | Pointer to the [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| [Udmf_Intention](#udmf_intention) | Returns the value of [Udmf_Intent](capi-udmf-h.md#udmf_intention).|

### OH_UdmfOptions_SetIntention()

```
int OH_UdmfOptions_SetIntention(OH_UdmfOptions* pThis, Udmf_Intention intention)
```

**Description**

Sets the data channel content parameter in an [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md) instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)* pThis | Pointer to the [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md) instance.|
| [Udmf_Intention](#udmf_intention) intention | Data channel type.|

**Returns**

| Type| Description|
| -- | -- |
| int | Error code. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_UdmfOptions_Reset()

```
int OH_UdmfOptions_Reset(OH_UdmfOptions* pThis)
```

**Description**

Resets an [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md) instance to empty.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)* pThis | Pointer to the [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| int | Error code. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.|

### OH_Udmf_GetUnifiedData()

```
int OH_Udmf_GetUnifiedData(const char* key, Udmf_Intention intention, OH_UdmfData* unifiedData)
```

**Description**

Obtains an [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance from the UDMF database.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const char* key | Pointer to the unique identifier of the data in the database.|
| [Udmf_Intention](#udmf_intention) intention | Data channel type [Udmf_Intent](capi-udmf-h.md#udmf_intention).|
| [OH_UdmfData](capi-udmf-oh-udmfdata.md)* unifiedData | Pointer to the [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance obtained.|

**Returns**

| Type| Description|
| -- | -- |
| int | Error code. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.<br>Returns **UDMF_ERR** if an internal data error occurs.|

### OH_Udmf_GetUnifiedDataByOptions()

```
int OH_Udmf_GetUnifiedDataByOptions(OH_UdmfOptions* options, OH_UdmfData** dataArray, unsigned int* dataSize)
```

**Description**

Obtains an [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance from the UDMF database by data channel type.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)* options | Pointer to the [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md) instance.|
| [OH_UdmfData](capi-udmf-oh-udmfdata.md)** dataArray | Double pointer to the [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance,<br>which should be released by using the [OH_Udmf_DestroyDataArray](capi-udmf-h.md#oh_udmf_destroydataarray) function.|
| unsigned int* dataSize | Pointer to the data size obtained.|

**Returns**

| Type| Description|
| -- | -- |
| int | Error code. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.<br>Returns **UDMF_ERR** if an internal data error occurs.|

### OH_Udmf_SetUnifiedData()

```
int OH_Udmf_SetUnifiedData(Udmf_Intention intention, OH_UdmfData* unifiedData, char* key, unsigned int keyLen)
```

**Description**

Sets an [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance in the UDMF database.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [Udmf_Intention](#udmf_intention) intention | Data channel type [Udmf_Intent](capi-udmf-h.md#udmf_intention).|
| [OH_UdmfData](capi-udmf-oh-udmfdata.md)* unifiedData | Pointer to the [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance.|
| key | Pointer to the key that uniquely identifies the data in the database.|
| unsigned int keyLen | Length of the key. The memory size must be greater than or equal to 512 bytes.|

**Returns**

| Type| Description|
| -- | -- |
| int | Error code. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.<br>Returns **UDMF_ERR** if an internal data error occurs.|

### OH_Udmf_SetUnifiedDataByOptions()

```
int OH_Udmf_SetUnifiedDataByOptions(OH_UdmfOptions* options, OH_UdmfData *unifiedData, char *key, unsigned int keyLen)
```

**Description**

Sets an [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance in the UDMF database.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)* options | Pointer to the [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md) instance.|
| [OH_UdmfData](capi-udmf-oh-udmfdata.md) *unifiedData | Pointer to the [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance.|
| char *key | Pointer to the key that uniquely identifies the data in the database. The memory size must be greater than [UDMF_KEY_BUFFER_LEN](#udmf_key_buffer_len).|
| unsigned int keyLen | Length of the key.|

**Returns**

| Type| Description|
| -- | -- |
| int | Error code. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.<br>Returns **UDMF_ERR** if an internal data error occurs.|

### OH_Udmf_UpdateUnifiedData()

```
int OH_Udmf_UpdateUnifiedData(OH_UdmfOptions* options, OH_UdmfData* unifiedData)
```

**Description**

Updates an [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance in the UDMF database.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)* options | Pointer to the [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md) instance.|
| [OH_UdmfData](capi-udmf-oh-udmfdata.md)* unifiedData | Pointer to the [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| int | Error code. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.<br>Returns **UDMF_ERR** if an internal data error occurs.|

### OH_Udmf_DeleteUnifiedData()

```
int OH_Udmf_DeleteUnifiedData(OH_UdmfOptions* options, OH_UdmfData** dataArray, unsigned int* dataSize)
```

**Description**

Deletes an [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance from the UDMF database.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md)* options | Pointer to the [OH_UdmfOptions](capi-udmf-oh-udmfoptions.md) instance.|
| [OH_UdmfData](capi-udmf-oh-udmfdata.md)** dataArray | Double pointer to the [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance,<br>which should be released by using the [OH_Udmf_DestroyDataArray](capi-udmf-h.md#oh_udmf_destroydataarray) function.|
| unsigned int* dataSize | Pointer to the data size obtained.|

**Returns**

| Type| Description|
| -- | -- |
| int | Error code. For details, see [Udmf_ErrCode](capi-udmf-err-code-h.md#udmf_errcode).<br>Returns **UDMF_E_OK** if the operation is successful.<br>Returns **UDMF_E_INVALID_PARAM** if an invalid parameter is passed in.<br>Returns **UDMF_ERR** if an internal data error occurs.|

### OH_Udmf_DestroyDataArray()

```
void OH_Udmf_DestroyDataArray(OH_UdmfData** dataArray, unsigned int dataSize)
```

**Description**

Destroys the memory of the data array.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfData](capi-udmf-oh-udmfdata.md)** dataArray | Double pointer to the [OH_UdmfData](capi-udmf-oh-udmfdata.md) instance.|
| unsigned int dataSize | Data size.|

**See**

OH_UdmfData

### OH_UdmfProgressInfo_GetProgress()

```
int OH_UdmfProgressInfo_GetProgress(OH_Udmf_ProgressInfo* progressInfo)
```

**Description**

Obtains the progress (in percentage) from an [OH_Udmf_ProgressInfo](capi-udmf-oh-udmf-progressinfo.md) instance.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Udmf_ProgressInfo](capi-udmf-oh-udmf-progressinfo.md)* progressInfo | Pointer to the [OH_Udmf_ProgressInfo](capi-udmf-oh-udmf-progressinfo.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| int | Progress obtained, in percentage.|

### OH_UdmfProgressInfo_GetStatus()

```
int OH_UdmfProgressInfo_GetStatus(OH_Udmf_ProgressInfo* progressInfo)
```

**Description**

Obtains the status information from an [OH_Udmf_ProgressInfo](capi-udmf-oh-udmf-progressinfo.md) instance.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Udmf_ProgressInfo](capi-udmf-oh-udmf-progressinfo.md)* progressInfo | Pointer to the [OH_Udmf_ProgressInfo](capi-udmf-oh-udmf-progressinfo.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| int | Status information obtained.|

### OH_UdmfGetDataParams_Create()

```
OH_UdmfGetDataParams* OH_UdmfGetDataParams_Create()
```

**Description**

Creates an [OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md) instance and a pointer to it.<br>If this pointer is no longer required, use [OH_UdmfGetDataParams_Destroy](capi-udmf-h.md#oh_udmfgetdataparams_destroy) to destroy it. Otherwise, memory leaks may occur.

**Since**: 15

**Returns**

| Type| Description|
| -- | -- |
| [OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md)* | Returns a pointer to the [OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md) instance created if the operation is successful; returns **nullptr** otherwise.|

### OH_UdmfGetDataParams_Destroy()

```
void OH_UdmfGetDataParams_Destroy(OH_UdmfGetDataParams* pThis)
```

**Description**

Destroys an [OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md) instance.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md)* pThis | Pointer to the [OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md) instance.|

### OH_UdmfGetDataParams_SetDestUri()

```
void OH_UdmfGetDataParams_SetDestUri(OH_UdmfGetDataParams* params, const char* destUri)
```

**Description**

Sets the destination directory in an [OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md) instance.<br>If the destination directory is set, data of the file type will be copied to the specified directory. The file type data obtained in the callback will be replaced with the URI of the destination directory.<br>If the destination directory is not specified, the file will not be copied. The file type data obtained in the callback is the URI of the source directory.<br>If the application involves complex file processing or files need to be copied to multiple directories, you are advised to leave this parameter unspecified and let the application handle the file copy.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md)* params | Pointer to the [OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md) instance.|
| const char* destUri | Destination directory to set.|

### OH_UdmfGetDataParams_SetFileConflictOptions()

```
void OH_UdmfGetDataParams_SetFileConflictOptions(OH_UdmfGetDataParams* params, const Udmf_FileConflictOptions options)
```

**Description**

Sets the policy for resolving file conflicts in an [OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md) instance.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md)* params | Pointer to the [OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md) instance.|
| const [Udmf_FileConflictOptions](#udmf_fileconflictoptions) options | Policy to set.|

### OH_UdmfGetDataParams_SetProgressIndicator()

```
void OH_UdmfGetDataParams_SetProgressIndicator(OH_UdmfGetDataParams* params, const Udmf_ProgressIndicator progressIndicator)
```

**Description**

Sets the progress indicator in an [OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md) instance.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md)* params | Pointer to the [OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md) instance.|
| const [Udmf_ProgressIndicator](#udmf_progressindicator) progressIndicator | Whether to use the default progress indicator.|

### OH_UdmfGetDataParams_SetDataProgressListener()

```
void OH_UdmfGetDataParams_SetDataProgressListener(OH_UdmfGetDataParams* params, const OH_Udmf_DataProgressListener dataProgressListener)
```

**Description**

Sets the callback used to return the progress obtained in an [OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md) instance.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md)* params | Pointer to the [OH_UdmfGetDataParams](capi-udmf-oh-udmfgetdataparams.md) instance.|
| const [OH_Udmf_DataProgressListener](#oh_udmf_dataprogresslistener) dataProgressListener | Callback to set.|
