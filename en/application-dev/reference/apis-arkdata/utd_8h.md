# utd.h


## Overview

Defines APIs and structs related to the Uniform Type Descriptors (UTDs).

**File to include**: &lt;database/udmf/utd.h&gt;

**Library**: libudmf.so

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Since**: 12

**Related module**: [UDMF](_u_d_m_f.md)


## Summary


### Types

| Name | Description | 
| -------- | -------- |
| typedef struct [OH_Utd](_u_d_m_f.md#oh_utd) [OH_Utd](_u_d_m_f.md#oh_utd) | Defines a struct for a UTD. | 


### Functions

| Name | Description | 
| -------- | -------- |
| [OH_Utd](_u_d_m_f.md#oh_utd) \* [OH_Utd_Create](_u_d_m_f.md#oh_utd_create) (const char \*typeId) | Creates an [OH_Utd](_u_d_m_f.md#oh_utd) instance and a pointer to it. | 
| void [OH_Utd_Destroy](_u_d_m_f.md#oh_utd_destroy) ([OH_Utd](_u_d_m_f.md#oh_utd) \*pThis) | Destroys an [OH_Utd](_u_d_m_f.md#oh_utd) instance. | 
| const char \* [OH_Utd_GetTypeId](_u_d_m_f.md#oh_utd_gettypeid) ([OH_Utd](_u_d_m_f.md#oh_utd) \*pThis) | Obtains the type ID from an [OH_Utd](_u_d_m_f.md#oh_utd) instance. | 
| const char \* [OH_Utd_GetDescription](_u_d_m_f.md#oh_utd_getdescription) ([OH_Utd](_u_d_m_f.md#oh_utd) \*pThis) | Obtains the description from an [OH_Utd](_u_d_m_f.md#oh_utd) instance. | 
| const char \* [OH_Utd_GetReferenceUrl](_u_d_m_f.md#oh_utd_getreferenceurl) ([OH_Utd](_u_d_m_f.md#oh_utd) \*pThis) | Obtains the URL from an [OH_Utd](_u_d_m_f.md#oh_utd) instance. | 
| const char \* [OH_Utd_GetIconFile](_u_d_m_f.md#oh_utd_geticonfile) ([OH_Utd](_u_d_m_f.md#oh_utd) \*pThis) | Obtains the path of the default icon file from an [OH_Utd](_u_d_m_f.md#oh_utd) instance. | 
| const char \*\* [OH_Utd_GetBelongingToTypes](_u_d_m_f.md#oh_utd_getbelongingtotypes) ([OH_Utd](_u_d_m_f.md#oh_utd) \*pThis, unsigned int \*count) | Obtains the relationships between the data in an [OH_Utd](_u_d_m_f.md#oh_utd) instance. | 
| const char \*\* [OH_Utd_GetFilenameExtensions](_u_d_m_f.md#oh_utd_getfilenameextensions) ([OH_Utd](_u_d_m_f.md#oh_utd) \*pThis, unsigned int \*count) | Obtains the file name extensions associated with an [OH_Utd](_u_d_m_f.md#oh_utd) instance. | 
| const char \*\* [OH_Utd_GetMimeTypes](_u_d_m_f.md#oh_utd_getmimetypes) ([OH_Utd](_u_d_m_f.md#oh_utd) \*pThis, unsigned int \*count) | Obtains the MIME types associated with an [OH_Utd](_u_d_m_f.md#oh_utd) instance. | 
| const char \*\* [OH_Utd_GetTypesByFilenameExtension](_u_d_m_f.md#oh_utd_gettypesbyfilenameextension) (const char \*extension, unsigned int \*count) | Obtains the uniform data types based on the file name extensions. | 
| const char \*\* [OH_Utd_GetTypesByMimeType](_u_d_m_f.md#oh_utd_gettypesbymimetype) (const char \*mimeType, unsigned int \*count) | Obtains the uniform data types based on the MIME types. | 
| bool [OH_Utd_BelongsTo](_u_d_m_f.md#oh_utd_belongsto) (const char \*srcTypeId, const char \*destTypeId) | Checks whether a UTD belongs to the target UTD. | 
| bool [OH_Utd_IsLower](_u_d_m_f.md#oh_utd_islower) (const char \*srcTypeId, const char \*destTypeId) | Checks whether a UTD is a lower-level type of the target UTD. For example, **TYPE_SCRIPT** is a lower-level type of **SOURCE_CODE**, and **TYPE_SCRIPT** and **SOURCE_CODE** are lower-level types of **PLAIN_TEXT**. | 
| bool [OH_Utd_IsHigher](_u_d_m_f.md#oh_utd_ishigher) (const char \*srcTypeId, const char \*destTypeId) | Checks whether a UTD is a higher-level type of the target UTD. For example, **SOURCE_CODE** is a higher-level type of **TYPE_SCRIPT**, and **PLAIN_TEXT** is a higher-level type of **SOURCE_CODE** and **TYPE_SCRIPT**. | 
| bool [OH_Utd_Equals](_u_d_m_f.md#oh_utd_equals) ([OH_Utd](_u_d_m_f.md#oh_utd) \*utd1, [OH_Utd](_u_d_m_f.md#oh_utd) \*utd2) | Checks whether two UTDs are the same. | 
| void [OH_Utd_DestroyStringList](_u_d_m_f.md#oh_utd_destroystringlist) (const char \*\*list, unsigned int count) | Destroys a UTD list. | 
