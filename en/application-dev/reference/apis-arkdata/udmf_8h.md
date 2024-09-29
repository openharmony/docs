# udmf.h


## Overview

Defines the APIs, data structs, and enums for accessing the UDMF.

**File to include**: &lt;database/udmf/udmf.h&gt;

**Library**: libudmf.so

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Since**: 12

**Related module**: [UDMF](_u_d_m_f.md)


## Summary


### Macros

| Name | Description | 
| -------- | -------- |
| [UDMF_KEY_BUFFER_LEN](_u_d_m_f.md#udmf_key_buffer_len)&nbsp;&nbsp;&nbsp;(512) | Minimum length of the buffer that holds the key (unique identifier) of a uniform data object. | 


### Types

| Name | Description | 
| -------- | -------- |
| typedef enum [Udmf_Intention](_u_d_m_f.md#udmf_intention) [Udmf_Intention](_u_d_m_f.md#udmf_intention) | Defines an enum for unified data channels defined in the UDMF. | 
| typedef enum [Udmf_ShareOption](_u_d_m_f.md#udmf_shareoption) [Udmf_ShareOption](_u_d_m_f.md#udmf_shareoption) | Defines an enum for the options for using the uniform data in a device. | 
| typedef struct [OH_UdmfData](_u_d_m_f.md#oh_udmfdata) [OH_UdmfData](_u_d_m_f.md#oh_udmfdata) | Defines a struct for a uniform data object. | 
| typedef struct [OH_UdmfRecord](_u_d_m_f.md#oh_udmfrecord) [OH_UdmfRecord](_u_d_m_f.md#oh_udmfrecord) | Defines a struct for a data record in a uniform data object. | 
| typedef struct [OH_UdmfProperty](_u_d_m_f.md#oh_udmfproperty) [OH_UdmfProperty](_u_d_m_f.md#oh_udmfproperty) | Defines a struct for a data record property in a uniform data object. | 


### Enums

| Name | Description | 
| -------- | -------- |
| [Udmf_Intention](_u_d_m_f.md#udmf_intention) { UDMF_INTENTION_DRAG, UDMF_INTENTION_PASTEBOARD } | Enumerates the UDMF data channel types. | 
| [Udmf_ShareOption](_u_d_m_f.md#udmf_shareoption) { SHARE_OPTIONS_INVALID, SHARE_OPTIONS_IN_APP, SHARE_OPTIONS_CROSS_APP } | Enumerates the options for using the uniform data in a device. | 


### Functions

| Name | Description | 
| -------- | -------- |
| [OH_UdmfData](_u_d_m_f.md#oh_udmfdata) \* [OH_UdmfData_Create](_u_d_m_f.md#oh_udmfdata_create) () | Creates an [OH_UdmfData](_u_d_m_f.md#oh_udmfdata) instance and a pointer to it. | 
| void [OH_UdmfData_Destroy](_u_d_m_f.md#oh_udmfdata_destroy) ([OH_UdmfData](_u_d_m_f.md#oh_udmfdata) \*pThis) | Destroys an [OH_UdmfData](_u_d_m_f.md#oh_udmfdata) instance. | 
| int [OH_UdmfData_AddRecord](_u_d_m_f.md#oh_udmfdata_addrecord) ([OH_UdmfData](_u_d_m_f.md#oh_udmfdata) \*pThis, [OH_UdmfRecord](_u_d_m_f.md#oh_udmfrecord) \*record) | Adds an [OH_UdmfRecord](_u_d_m_f.md#oh_udmfrecord) to an [OH_UdmfData](_u_d_m_f.md#oh_udmfdata) instance. | 
| bool [OH_UdmfData_HasType](_u_d_m_f.md#oh_udmfdata_hastype) ([OH_UdmfData](_u_d_m_f.md#oh_udmfdata) \*pThis, const char \*type) | Checks whether the specified type exists in an [OH_UdmfData](_u_d_m_f.md#oh_udmfdata) instance. | 
| char \*\* [OH_UdmfData_GetTypes](_u_d_m_f.md#oh_udmfdata_gettypes) ([OH_UdmfData](_u_d_m_f.md#oh_udmfdata) \*pThis, unsigned int \*count) | Obtains all data types in an [OH_UdmfData](_u_d_m_f.md#oh_udmfdata) instance. | 
| [OH_UdmfRecord](_u_d_m_f.md#oh_udmfrecord) \*\* [OH_UdmfData_GetRecords](_u_d_m_f.md#oh_udmfdata_getrecords) ([OH_UdmfData](_u_d_m_f.md#oh_udmfdata) \*pThis, unsigned int \*count) | Obtains all records contained in an [OH_UdmfData](_u_d_m_f.md#oh_udmfdata) instance. | 
| [OH_UdmfRecord](_u_d_m_f.md#oh_udmfrecord) \* [OH_UdmfRecord_Create](_u_d_m_f.md#oh_udmfrecord_create) () | Creates an [OH_UdmfRecord](_u_d_m_f.md#oh_udmfrecord) instance and a pointer to it. | 
| void [OH_UdmfRecord_Destroy](_u_d_m_f.md#oh_udmfrecord_destroy) ([OH_UdmfRecord](_u_d_m_f.md#oh_udmfrecord) \*pThis) | Destroys an [OH_UdmfRecord](_u_d_m_f.md#oh_udmfrecord) instance. | 
| int [OH_UdmfRecord_AddGeneralEntry](_u_d_m_f.md#oh_udmfrecord_addgeneralentry) ([OH_UdmfRecord](_u_d_m_f.md#oh_udmfrecord) \*pThis, const char \*typeId, unsigned char \*entry, unsigned int count) | Adds customized uniform data to an [OH_UdmfRecord](_u_d_m_f.md#oh_udmfrecord) instance. | 
| int [OH_UdmfRecord_AddPlainText](_u_d_m_f.md#oh_udmfrecord_addplaintext) ([OH_UdmfRecord](_u_d_m_f.md#oh_udmfrecord) \*pThis, [OH_UdsPlainText](_u_d_m_f.md#oh_udsplaintext) \*plainText) | Adds data of the [OH_UdsPlainText](_u_d_m_f.md#oh_udsplaintext) type to an [OH_UdmfRecord](_u_d_m_f.md#oh_udmfrecord) instance. | 
| int [OH_UdmfRecord_AddHyperlink](_u_d_m_f.md#oh_udmfrecord_addhyperlink) ([OH_UdmfRecord](_u_d_m_f.md#oh_udmfrecord) \*pThis, [OH_UdsHyperlink](_u_d_m_f.md#oh_udshyperlink) \*hyperlink) | Adds data of the hyperlink type [OH_UdsHyperlink](_u_d_m_f.md#oh_udshyperlink) type to an [OH_UdmfRecord](_u_d_m_f.md#oh_udmfrecord) instance. | 
| int [OH_UdmfRecord_AddHtml](_u_d_m_f.md#oh_udmfrecord_addhtml) ([OH_UdmfRecord](_u_d_m_f.md#oh_udmfrecord) \*pThis, [OH_UdsHtml](_u_d_m_f.md#oh_udshtml) \*html) | Adds data of the [OH_UdsHtml](_u_d_m_f.md#oh_udshtml) type to an [OH_UdmfRecord](_u_d_m_f.md#oh_udmfrecord) instance. | 
| int [OH_UdmfRecord_AddAppItem](_u_d_m_f.md#oh_udmfrecord_addappitem) ([OH_UdmfRecord](_u_d_m_f.md#oh_udmfrecord) \*pThis, [OH_UdsAppItem](_u_d_m_f.md#oh_udsappitem) \*appItem) | Adds data of the [OH_UdsAppItem](_u_d_m_f.md#oh_udsappitem) type to an [OH_UdmfRecord](_u_d_m_f.md#oh_udmfrecord) instance. | 
| char \*\* [OH_UdmfRecord_GetTypes](_u_d_m_f.md#oh_udmfrecord_gettypes) ([OH_UdmfRecord](_u_d_m_f.md#oh_udmfrecord) \*pThis, unsigned int \*count) | Obtains all data types in an [OH_UdmfRecord](_u_d_m_f.md#oh_udmfrecord) instance. | 
| int [OH_UdmfRecord_GetGeneralEntry](_u_d_m_f.md#oh_udmfrecord_getgeneralentry) ([OH_UdmfRecord](_u_d_m_f.md#oh_udmfrecord) \*pThis, const char \*typeId, unsigned char \*\*entry, unsigned int \*count) | Obtains the data of the specified type in an [OH_UdmfRecord](_u_d_m_f.md#oh_udmfrecord) instance. | 
| int [OH_UdmfRecord_GetPlainText](_u_d_m_f.md#oh_udmfrecord_getplaintext) ([OH_UdmfRecord](_u_d_m_f.md#oh_udmfrecord) \*pThis, [OH_UdsPlainText](_u_d_m_f.md#oh_udsplaintext) \*plainText) | Obtains [OH_UdsPlainText](_u_d_m_f.md#oh_udsplaintext) data from an [OH_UdmfRecord](_u_d_m_f.md#oh_udmfrecord) instance. | 
| int [OH_UdmfRecord_GetHyperlink](_u_d_m_f.md#oh_udmfrecord_gethyperlink) ([OH_UdmfRecord](_u_d_m_f.md#oh_udmfrecord) \*pThis, [OH_UdsHyperlink](_u_d_m_f.md#oh_udshyperlink) \*hyperlink) | Obtains [OH_UdsHyperlink](_u_d_m_f.md#oh_udshyperlink) data from an [OH_UdmfRecord](_u_d_m_f.md#oh_udmfrecord) instance. | 
| int [OH_UdmfRecord_GetHtml](_u_d_m_f.md#oh_udmfrecord_gethtml) ([OH_UdmfRecord](_u_d_m_f.md#oh_udmfrecord) \*pThis, [OH_UdsHtml](_u_d_m_f.md#oh_udshtml) \*html) | Obtains [OH_UdsHtml](_u_d_m_f.md#oh_udshtml) data from an [OH_UdmfRecord](_u_d_m_f.md#oh_udmfrecord) instance. | 
| int [OH_UdmfRecord_GetAppItem](_u_d_m_f.md#oh_udmfrecord_getappitem) ([OH_UdmfRecord](_u_d_m_f.md#oh_udmfrecord) \*pThis, [OH_UdsAppItem](_u_d_m_f.md#oh_udsappitem) \*appItem) | Obtains **OH_UdsAppItem** data from an [OH_UdmfRecord](_u_d_m_f.md#oh_udmfrecord) instance. | 
| [OH_UdmfProperty](_u_d_m_f.md#oh_udmfproperty) \* [OH_UdmfProperty_Create](_u_d_m_f.md#oh_udmfproperty_create) ([OH_UdmfData](_u_d_m_f.md#oh_udmfdata) \*unifiedData) | Creates an [OH_UdmfProperty](_u_d_m_f.md#oh_udmfproperty) instance and a pointer to it. | 
| void [OH_UdmfProperty_Destroy](_u_d_m_f.md#oh_udmfproperty_destroy) ([OH_UdmfProperty](_u_d_m_f.md#oh_udmfproperty) \*pThis) | Destroys an [OH_UdmfProperty](_u_d_m_f.md#oh_udmfproperty) instance. | 
| const char \* [OH_UdmfProperty_GetTag](_u_d_m_f.md#oh_udmfproperty_gettag) ([OH_UdmfProperty](_u_d_m_f.md#oh_udmfproperty) \*pThis) | Obtains the custom tag value from an [OH_UdmfProperty](_u_d_m_f.md#oh_udmfproperty) instance. | 
| int64_t [OH_UdmfProperty_GetTimestamp](_u_d_m_f.md#oh_udmfproperty_gettimestamp) ([OH_UdmfProperty](_u_d_m_f.md#oh_udmfproperty) \*pThis) | Obtains the timestamp from an [OH_UdmfProperty](_u_d_m_f.md#oh_udmfproperty) instance. | 
| [Udmf_ShareOption](_u_d_m_f.md#udmf_shareoption)[OH_UdmfProperty_GetShareOption](_u_d_m_f.md#oh_udmfproperty_getshareoption) ([OH_UdmfProperty](_u_d_m_f.md#oh_udmfproperty) \*pThis) | Obtains the share option from an [OH_UdmfProperty](_u_d_m_f.md#oh_udmfproperty) instance. | 
| int [OH_UdmfProperty_GetExtrasIntParam](_u_d_m_f.md#oh_udmfproperty_getextrasintparam) ([OH_UdmfProperty](_u_d_m_f.md#oh_udmfproperty) \*pThis, const char \*key, int defaultValue) | Obtains the customized extra integer parameter from an [OH_UdmfProperty](_u_d_m_f.md#oh_udmfproperty) instance. | 
| const char \* [OH_UdmfProperty_GetExtrasStringParam](_u_d_m_f.md#oh_udmfproperty_getextrasstringparam) ([OH_UdmfProperty](_u_d_m_f.md#oh_udmfproperty) \*pThis, const char \*key) | Obtains the customized extra string parameter from an [OH_UdmfProperty](_u_d_m_f.md#oh_udmfproperty) instance. | 
| int [OH_UdmfProperty_SetTag](_u_d_m_f.md#oh_udmfproperty_settag) ([OH_UdmfProperty](_u_d_m_f.md#oh_udmfproperty) \*pThis, const char \*tag) | Sets the tag value for an [OH_UdmfProperty](_u_d_m_f.md#oh_udmfproperty) instance. | 
| int [OH_UdmfProperty_SetShareOption](_u_d_m_f.md#oh_udmfproperty_setshareoption) ([OH_UdmfProperty](_u_d_m_f.md#oh_udmfproperty) \*pThis, [Udmf_ShareOption](_u_d_m_f.md#udmf_shareoption) option) | Sets the share option for an [OH_UdmfProperty](_u_d_m_f.md#oh_udmfproperty) instance. | 
| int [OH_UdmfProperty_SetExtrasIntParam](_u_d_m_f.md#oh_udmfproperty_setextrasintparam) ([OH_UdmfProperty](_u_d_m_f.md#oh_udmfproperty) \*pThis, const char \*key, int param) | Sets the extra integer parameter for an [OH_UdmfProperty](_u_d_m_f.md#oh_udmfproperty) instance. | 
| int [OH_UdmfProperty_SetExtrasStringParam](_u_d_m_f.md#oh_udmfproperty_setextrasstringparam) ([OH_UdmfProperty](_u_d_m_f.md#oh_udmfproperty) \*pThis, const char \*key, const char \*param) | Sets the extra string parameter for an [OH_UdmfProperty](_u_d_m_f.md#oh_udmfproperty) instance. | 
| int [OH_Udmf_GetUnifiedData](_u_d_m_f.md#oh_udmf_getunifieddata) (const char \*key, [Udmf_Intention](_u_d_m_f.md#udmf_intention) intention, [OH_UdmfData](_u_d_m_f.md#oh_udmfdata) \*unifiedData) | Obtains an [OH_UdmfData](_u_d_m_f.md#oh_udmfdata) instance from the UDMF database. | 
| int [OH_Udmf_SetUnifiedData](_u_d_m_f.md#oh_udmf_setunifieddata) ([Udmf_Intention](_u_d_m_f.md#udmf_intention) intention, [OH_UdmfData](_u_d_m_f.md#oh_udmfdata) \*unifiedData, char \*key, unsigned int keyLen) | Sets an [OH_UdmfData](_u_d_m_f.md#oh_udmfdata) instance in the UDMF database. | 
