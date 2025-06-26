# oh_pasteboard.h

## Overview

Provides data structure, enum types, and APIs for accessing the system pasteboard.<br>

**File to include**: <database/pasteboard/oh_pasteboard.h>

**Library**: libpasteboard.so

**System capability**: SystemCapability.MiscServices.Pasteboard

**Since**: 13

**Related module**: [Pasteboard](capi-pasteboard.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [Pasteboard_ProgressInfo](capi-pasteboard-progressinfo.md) | Pasteboard_ProgressInfo | Defines a struct for the progress information.|
| [Pasteboard_GetDataParams](capi-pasteboard-getdataparams.md) | Pasteboard_GetDataParams | Defines a struct for the parameters required for obtaining the pasteboard data and paste progress.|
| [OH_PasteboardObserver](capi-pasteboard-oh-pasteboardobserver.md) | OH_PasteboardObserver | Defines a struct for the pasteboard observer.|
| [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md) | OH_Pasteboard | Defines a struct for the pasteboard object to operate the system pasteboard.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [Pasteboard_NotifyType](#pasteboard_notifytype) | Pasteboard_NotifyType | Enumerates the data change types of the pasteboard.|
| [Pasteboard_FileConflictOptions](#pasteboard_fileconflictoptions) | Pasteboard_FileConflictOptions | Enumerates the options used to resolve file copy conflicts.|
| [Pasteboard_ProgressIndicator](#pasteboard_progressindicator) | Pasteboard_ProgressIndicator | Enumerates the progress indicator options. You can use the default progress indicator as required.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef void (\*OH_Pasteboard_ProgressListener)(Pasteboard_ProgressInfo* progressInfo)](#oh_pasteboard_progresslistener) | OH_Pasteboard_ProgressListener | Defines a callback to be invoked to obtain the progress information when the default progress indicator is not used.|
| [typedef void (\*Pasteboard_Notify)(void* context, Pasteboard_NotifyType type)](#pasteboard_notify) | Pasteboard_Notify | Defines a callback to be invoked when the pasteboard content changes.|
| [typedef void (\*Pasteboard_Finalize)(void* context)](#pasteboard_finalize) | Pasteboard_Finalize | Defines a callback to be invoked to release the context when the pasteboard observer object is destroyed.|
| [OH_PasteboardObserver* OH_PasteboardObserver_Create()](#oh_pasteboardobserver_create) | - | Creates an [OH_PasteboardObserver](capi-pasteboard-oh-pasteboardobserver.md) instance and a pointer to it.|
| [int OH_PasteboardObserver_Destroy(OH_PasteboardObserver* observer)](#oh_pasteboardobserver_destroy) | - | Destroys the [OH_PasteboardObserver](capi-pasteboard-oh-pasteboardobserver.md) instance.|
| [int OH_PasteboardObserver_SetData(OH_PasteboardObserver* observer, void* context,const Pasteboard_Notify callback, const Pasteboard_Finalize finalize)](#oh_pasteboardobserver_setdata) | - | Sets a callback for the pasteboard observer.|
| [OH_Pasteboard* OH_Pasteboard_Create()](#oh_pasteboard_create) | - | Creates an [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md) instance and a pointer to it.|
| [void OH_Pasteboard_Destroy(OH_Pasteboard* pasteboard)](#oh_pasteboard_destroy) | - | Destroys the [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md) instance.|
| [int OH_Pasteboard_Subscribe(OH_Pasteboard* pasteboard, int type, const OH_PasteboardObserver* observer)](#oh_pasteboard_subscribe) | - | Subscribes to the pasteboard observer.|
| [int OH_Pasteboard_Unsubscribe(OH_Pasteboard* pasteboard, int type, const OH_PasteboardObserver* observer)](#oh_pasteboard_unsubscribe) | - | Unsubscribes from the pasteboard observer.|
| [bool OH_Pasteboard_IsRemoteData(OH_Pasteboard* pasteboard)](#oh_pasteboard_isremotedata) | - | Checks whether the pasteboard data comes from remote devices.|
| [int OH_Pasteboard_GetDataSource(OH_Pasteboard* pasteboard, char* source, unsigned int len)](#oh_pasteboard_getdatasource) | - | Obtains the pasteboard data source.|
| [bool OH_Pasteboard_HasType(OH_Pasteboard* pasteboard, const char* type)](#oh_pasteboard_hastype) | - | Checks whether the pasteboard contains data of the specified type.|
| [bool OH_Pasteboard_HasData(OH_Pasteboard* pasteboard)](#oh_pasteboard_hasdata) | - | Checks whether the pasteboard contains data.|
| [OH_UdmfData* OH_Pasteboard_GetData(OH_Pasteboard* pasteboard, int* status)](#oh_pasteboard_getdata) | - | Obtains data from the pasteboard.|
| [int OH_Pasteboard_SetData(OH_Pasteboard* pasteboard, OH_UdmfData* data)](#oh_pasteboard_setdata) | - | Sets the unified data object in the OH_Pasteboard instance.|
| [int OH_Pasteboard_ClearData(OH_Pasteboard* pasteboard)](#oh_pasteboard_cleardata) | - | Clears data from the pasteboard.|
| [char **OH_Pasteboard_GetMimeTypes(OH_Pasteboard *pasteboard, unsigned int *count)](#oh_pasteboard_getmimetypes) | - | Obtains the MIME types from the pasteboard.|
| [Pasteboard_GetDataParams *OH_Pasteboard_GetDataParams_Create(void)](#oh_pasteboard_getdataparams_create) | - | Creates a [Pasteboard_GetDataParams](capi-pasteboard-getdataparams.md) instance and a pointer to it.|
| [void OH_Pasteboard_GetDataParams_Destroy(Pasteboard_GetDataParams* params)](#oh_pasteboard_getdataparams_destroy) | - | Destroys the [Pasteboard_GetDataParams](capi-pasteboard-getdataparams.md) instance.|
| [void OH_Pasteboard_GetDataParams_SetProgressIndicator(Pasteboard_GetDataParams* params,Pasteboard_ProgressIndicator progressIndicator)](#oh_pasteboard_getdataparams_setprogressindicator) | - | Sets a progress indicator in [Pasteboard_GetDataParams](capi-pasteboard-getdataparams.md). You can use the default progress indicator as required.|
| [void OH_Pasteboard_GetDataParams_SetDestUri(Pasteboard_GetDataParams* params, const char* destUri, uint32_t destUriLen)](#oh_pasteboard_getdataparams_setdesturi) | - | Sets the destination URI in a [Pasteboard_GetDataParams](capi-pasteboard-getdataparams.md) instance for copying files. If file processing is not supported, this parameter is not required. If the application involves complex file processing policies or needs to distinguish file multipathing storage, you are advised not to set this parameter but let the application copies files by itself.|
| [void OH_Pasteboard_GetDataParams_SetFileConflictOptions(Pasteboard_GetDataParams* params,Pasteboard_FileConflictOptions option)](#oh_pasteboard_getdataparams_setfileconflictoptions) | - | Sets the options used to resolve file copy conflicts in a [Pasteboard_GetDataParams](capi-pasteboard-getdataparams.md) instance.|
| [void OH_Pasteboard_GetDataParams_SetProgressListener(Pasteboard_GetDataParams* params,const OH_Pasteboard_ProgressListener listener)](#oh_pasteboard_getdataparams_setprogresslistener) | - | Sets a progress listener in a [Pasteboard_GetDataParams](capi-pasteboard-getdataparams.md) instance.|
| [int OH_Pasteboard_ProgressInfo_GetProgress(Pasteboard_ProgressInfo* progressInfo)](#oh_pasteboard_progressinfo_getprogress) | - | Obtains the paste progress in a [Pasteboard_ProgressInfo](capi-pasteboard-progressinfo.md) instance.|
| [void OH_Pasteboard_ProgressCancel(Pasteboard_GetDataParams* params)](#oh_pasteboard_progresscancel) | - | Cancels the ongoing paste operation when the pasteboard data is obtained.|
| [OH_UdmfData* OH_Pasteboard_GetDataWithProgress(OH_Pasteboard* pasteboard, Pasteboard_GetDataParams* params,int* status)](#oh_pasteboard_getdatawithprogress) | - | Obtains the pasteboard data and paste progress. Folders cannot be copied.|
| [uint32_t OH_Pasteboard_GetChangeCount(OH_Pasteboard *pasteboard)](#oh_pasteboard_getchangecount) | - | Obtains the number of pasteboard content changes.|

## Enum Description

### Pasteboard_NotifyType

```
enum Pasteboard_NotifyType
```

**Description**

Enumerates the data change types of the pasteboard.

**Since**: 13

| Enum Item| Description|
| -- | -- |
| NOTIFY_LOCAL_DATA_CHANGE = 1 | The pasteboard data of the local device is changed.|
| NOTIFY_REMOTE_DATA_CHANGE = 2 | The pasteboard data of a non-local device on the network is changed.|

### Pasteboard_FileConflictOptions

```
enum Pasteboard_FileConflictOptions
```

**Description**

Enumerates the options used to resolve file copy conflicts.

**Since**: 15

| Enum Item| Description|
| -- | -- |
| PASTEBOARD_OVERWRITE = 0 | Overwrites the file with the same name in the destination directory.|
| PASTEBOARD_SKIP = 1 | Skips the file if there is a file with the same name in the destination directory.|

### Pasteboard_ProgressIndicator

```
enum Pasteboard_ProgressIndicator
```

**Description**

Enumerates the progress indicator options. You can use the default progress indicator as required.

**Since**: 15

| Enum Item| Description|
| -- | -- |
| PASTEBOARD_NONE = 0 | The default progress indicator is not used.|
| PASTEBOARD_DEFAULT = 1 | The default progress indicator is used.|


## Function Description

### OH_Pasteboard_ProgressListener()

```
typedef void (*OH_Pasteboard_ProgressListener)(Pasteboard_ProgressInfo* progressInfo)
```

**Description**

Defines a callback to be invoked to obtain the progress information when the default progress indicator is not used.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [Pasteboard_ProgressInfo](capi-pasteboard-progressinfo.md)* progressInfo | A struct for the progress information. This information is reported only when [Pasteboard_ProgressInfo](capi-pasteboard-progressinfo.md) is set to **NONE**.|

### Pasteboard_Notify()

```
typedef void (*Pasteboard_Notify)(void* context, Pasteboard_NotifyType type)
```

**Description**

Defines a callback to be invoked when the pasteboard content changes.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| void* context | Context information, which is passed by the [OH_PasteboardObserver_SetData](capi-oh-pasteboard-h.md#oh_pasteboardobserver_setdata) function.|
| [Pasteboard_NotifyType](capi-oh-pasteboard-h.md#pasteboard_notifytype) type | Data change type. For details, see [Pasteboard_NotifyType](capi-oh-pasteboard-h.md#pasteboard_notifytype).|

### Pasteboard_Finalize()

```
typedef void (*Pasteboard_Finalize)(void* context)
```

**Description**

Defines a callback to be invoked to release the context when the pasteboard observer object is destroyed.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| void* context | Pointer to the context to release.|

### OH_PasteboardObserver_Create()

```
OH_PasteboardObserver* OH_PasteboardObserver_Create()
```

**Description**

Creates an [OH_PasteboardObserver](capi-pasteboard-oh-pasteboardobserver.md) instance and a pointer to it.

**Since**: 13

**Returns**

| Type| Description|
| -- | -- |
| [OH_PasteboardObserver](capi-pasteboard-oh-pasteboardobserver.md)* | Returns a pointer to the [OH_PasteboardObserver](capi-pasteboard-oh-pasteboardobserver.md) instance created if the operation is successful; returns **nullptr** otherwise.<br>If this pointer is no longer required, use [OH_PasteboardObserver_Destroy](capi-oh-pasteboard-h.md#oh_pasteboardobserver_destroy) to destroy it. Otherwise, memory leaks may occur. |

### OH_PasteboardObserver_Destroy()

```
int OH_PasteboardObserver_Destroy(OH_PasteboardObserver* observer)
```

**Description**

Destroys the [OH_PasteboardObserver](capi-pasteboard-oh-pasteboardobserver.md) instance.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PasteboardObserver](capi-pasteboard-oh-pasteboardobserver.md)* observer | Pointer to an [OH_PasteboardObserver](capi-pasteboard-oh-pasteboardobserver.md) instance.|

**Returns**

| Type| Description                                                                                                                                                                                                                                 |
| -- |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| int | Error code. For details about the error codes, see [PASTEBOARD_ErrCode](capi-oh-pasteboard-err-code-h.md#pasteboard_errcode).<br>Returns [ERR_OK](capi-oh-pasteboard-err-code-h.md#pasteboard_errcode) if the operation is successful.<br>Returns [ERR_INVALID_PARAMETER](capi-oh-pasteboard-err-code-h.md#pasteboard_errcode) if an invalid parameter is passed in.|

### OH_PasteboardObserver_SetData()

```
int OH_PasteboardObserver_SetData(OH_PasteboardObserver* observer, void* context,const Pasteboard_Notify callback, const Pasteboard_Finalize finalize)
```

**Description**

Sets a callback for the pasteboard observer.

**Since**: 13


**Parameters**

| Name                                                             | Description|
|------------------------------------------------------------------| -- |
| [OH_PasteboardObserver](capi-pasteboard-oh-pasteboardobserver.md)* observer | Pointer to an [OH_PasteboardObserver](capi-pasteboard-oh-pasteboardobserver.md) instance.|
| void* context                                                    | Pointer to the context, which is passed to [Pasteboard_Notify](capi-oh-pasteboard-h.md#pasteboard_notify) as the first parameter.|
| const [Pasteboard_Notify](capi-oh-pasteboard-h.md#pasteboard_notify) callback           | Callback to be invoked when the data changes. For details, see [Pasteboard_Notify](capi-oh-pasteboard-h.md#pasteboard_notify).|
| const [Pasteboard_Finalize](capi-oh-pasteboard-h.md#pasteboard_finalize) finalize                               | Optional callback, which can be used to release context data when the pasteboard observer is destroyed. For details, see [Pasteboard_Finalize](capi-oh-pasteboard-h.md#pasteboard_finalize).|

**Returns**

| Type| Description|
| -- | -- |
| int | Error code. For details about the error codes, see [PASTEBOARD_ErrCode](capi-oh-pasteboard-err-code-h.md#pasteboard_errcode).<br>Returns [ERR_OK](capi-oh-pasteboard-err-code-h.md#pasteboard_errcode) if the operation is successful.<br>Returns [ERR_INVALID_PARAMETER](capi-oh-pasteboard-err-code-h.md#pasteboard_errcode) if an invalid parameter is passed in.|

### OH_Pasteboard_Create()

```
OH_Pasteboard* OH_Pasteboard_Create()
```

**Description**

Creates an [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md) instance and a pointer to it.

**Since**: 13

**Returns**

| Type| Description|
| -- | -- |
| [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)* | Returns a pointer to the [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md) instance created if the operation is successful; returns **nullptr** otherwise.|

### OH_Pasteboard_Destroy()

```
void OH_Pasteboard_Destroy(OH_Pasteboard* pasteboard)
```

**Description**

Destroys the [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md) instance.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)* pasteboard | Pointer to an [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md) instance.|

### OH_Pasteboard_Subscribe()

```
int OH_Pasteboard_Subscribe(OH_Pasteboard* pasteboard, int type, const OH_PasteboardObserver* observer)
```

**Description**

Subscribes to the pasteboard observer.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)* pasteboard | Pointer to an [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md) instance.|
| int type | Subscribed data change type of the pasteboard. For details, see [Pasteboard_NotifyType](capi-oh-pasteboard-h.md#pasteboard_notifytype).|
| const [OH_PasteboardObserver](capi-pasteboard-oh-pasteboardobserver.md)* observer | Pointer to an [OH_PasteboardObserver](capi-pasteboard-oh-pasteboardobserver.md) instance. It specifies the callback to be invoked when the pasteboard data changes. For details, see [OH_PasteboardObserver](capi-pasteboard-oh-pasteboardobserver.md).|

**Returns**

| Type| Description|
| -- | -- |
| int | Error code. For details about the error codes, see [PASTEBOARD_ErrCode](capi-oh-pasteboard-err-code-h.md#pasteboard_errcode).<br>Returns [ERR_OK](capi-oh-pasteboard-err-code-h.md#pasteboard_errcode) if the operation is successful.<br>Returns [ERR_INVALID_PARAMETER](capi-oh-pasteboard-err-code-h.md#pasteboard_errcode) if an invalid parameter is passed in.|

### OH_Pasteboard_Unsubscribe()

```
int OH_Pasteboard_Unsubscribe(OH_Pasteboard* pasteboard, int type, const OH_PasteboardObserver* observer)
```

**Description**

Unsubscribes from the pasteboard observer.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)* pasteboard | Pointer to an [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md) instance.|
| int type | Subscribed data change type of the pasteboard. For details, see [Pasteboard_NotifyType](capi-oh-pasteboard-h.md#pasteboard_notifytype).|
| const [OH_PasteboardObserver](capi-pasteboard-oh-pasteboardobserver.md)* observer | Pointer to an [OH_PasteboardObserver](capi-pasteboard-oh-pasteboardobserver.md) instance. It specifies the callback to be invoked when the pasteboard data changes. For details, see [OH_PasteboardObserver](capi-pasteboard-oh-pasteboardobserver.md).|

**Returns**

| Type| Description|
| -- | -- |
| int | Error code. For details about the error codes, see [PASTEBOARD_ErrCode](capi-oh-pasteboard-err-code-h.md#pasteboard_errcode).<br>Returns [ERR_OK](capi-oh-pasteboard-err-code-h.md#pasteboard_errcode) if the operation is successful.<br>Returns [ERR_INVALID_PARAMETER](capi-oh-pasteboard-err-code-h.md#pasteboard_errcode) if an invalid parameter is passed in.|

### OH_Pasteboard_IsRemoteData()

```
bool OH_Pasteboard_IsRemoteData(OH_Pasteboard* pasteboard)
```

**Description**

Checks whether the pasteboard data comes from remote devices.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)* pasteboard | Pointer to an [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Returns a Boolean value indicating whether the data is from a remote device. The value **true** means the data is from a remote device; **false** means the data is from the local device.|

### OH_Pasteboard_GetDataSource()

```
int OH_Pasteboard_GetDataSource(OH_Pasteboard* pasteboard, char* source, unsigned int len)
```

**Description**

Obtains the pasteboard data source.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)* pasteboard | Pointer to an [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md) instance.|
| char* source | Pointer to the pasteboard data source instance. You need to allocate the memory for the pointer before calling this API.|
| unsigned int len | Memory length corresponding to the source. If the memory length is insufficient, the API call will fail. The recommended length is 128.|

**Returns**

| Type| Description|
| -- | -- |
| int | Error code. For details about the error codes, see [PASTEBOARD_ErrCode](capi-oh-pasteboard-err-code-h.md#pasteboard_errcode).<br>Returns [ERR_OK](capi-oh-pasteboard-err-code-h.md#pasteboard_errcode) if the operation is successful.<br>Returns [ERR_INVALID_PARAMETER](capi-oh-pasteboard-err-code-h.md#pasteboard_errcode) if an invalid parameter is passed in.|

### OH_Pasteboard_HasType()

```
bool OH_Pasteboard_HasType(OH_Pasteboard* pasteboard, const char* type)
```

**Description**

Checks whether the pasteboard contains data of the specified type.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)* pasteboard | Pointer to an [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md) instance.|
| const char* type | Data type to be checked, which is classified into basic types and custom types. The basic data types include text/plain, text/html, text/uri, text/want, and pixelMap.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Returns a Boolean value indicating whether the pasteboard contains data of the specified type. The value **true** means the pasteboard contains data of the specified type; the value **false** means the opposite.|

### OH_Pasteboard_HasData()

```
bool OH_Pasteboard_HasData(OH_Pasteboard* pasteboard)
```

**Description**

Checks whether the pasteboard contains data.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)* pasteboard | Pointer to an [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Returns a Boolean value indicating whether the pasteboard contains data. The value **true** means the pasteboard contains data; the value **false** means the opposite.|

### OH_Pasteboard_GetData()

```
OH_UdmfData* OH_Pasteboard_GetData(OH_Pasteboard* pasteboard, int* status)
```

**Description**

Obtains data from the pasteboard.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)* pasteboard | Pointer to an [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md) instance.|
| int* status | Output parameter, indicating the error code of the operation. For details about the error codes, see [PASTEBOARD_ErrCode](capi-oh-pasteboard-err-code-h.md#pasteboard_errcode).|

**Returns**

| Type| Description|
| -- | -- |
| OH_UdmfData* | Returns the pointer to an **OH_UdmfData** instance obtained if the operation is successful; returns a null pointer otherwise. |

### OH_Pasteboard_SetData()

```
int OH_Pasteboard_SetData(OH_Pasteboard* pasteboard, OH_UdmfData* data)
```

**Description**

Sets the unified data object in the OH_Pasteboard instance.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)* pasteboard | Pointer to an [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md) instance.|
| OH_UdmfData* data | Pointer to an **OH_UdmfData** instance. |

**Returns**

| Type| Description|
| -- | -- |
| int | Error code. For details about the error codes, see [PASTEBOARD_ErrCode](capi-oh-pasteboard-err-code-h.md#pasteboard_errcode).<br>Returns [ERR_OK](capi-oh-pasteboard-err-code-h.md#pasteboard_errcode) if the operation is successful.<br>Returns [ERR_INVALID_PARAMETER](capi-oh-pasteboard-err-code-h.md#pasteboard_errcode) if an invalid parameter is passed in.|

### OH_Pasteboard_ClearData()

```
int OH_Pasteboard_ClearData(OH_Pasteboard* pasteboard)
```

**Description**

Clears data from the pasteboard.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)* pasteboard | Pointer to an [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| int | Error code. For details about the error codes, see [PASTEBOARD_ErrCode](capi-oh-pasteboard-err-code-h.md#pasteboard_errcode).<br>Returns [ERR_OK](capi-oh-pasteboard-err-code-h.md#pasteboard_errcode) if the operation is successful.<br>Returns [ERR_INVALID_PARAMETER](capi-oh-pasteboard-err-code-h.md#pasteboard_errcode) if an invalid parameter is passed in.|

### OH_Pasteboard_GetMimeTypes()

```
char **OH_Pasteboard_GetMimeTypes(OH_Pasteboard *pasteboard, unsigned int *count)
```

**Description**

Obtains the MIME types from the pasteboard.

**Since**: 14


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md) *pasteboard | Pointer to an [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md) instance.|
| unsigned int *count | Pointer to the number of MIME types obtained.|

**Returns**

| Type| Description|
| -- | -- |
| char | Returns the MIME types obtained if the operation is successful; returns **nullptr** otherwise.|

### OH_Pasteboard_GetDataParams_Create()

```
Pasteboard_GetDataParams *OH_Pasteboard_GetDataParams_Create(void)
```

**Description**

Creates a [Pasteboard_GetDataParams](capi-pasteboard-getdataparams.md) instance and a pointer to it.

**Since**: 15

**Returns**

| Type| Description|
| -- | -- |
| [Pasteboard_GetDataParams](capi-pasteboard-getdataparams.md) | Returns a pointer to the [Pasteboard_GetDataParams](capi-pasteboard-getdataparams.md) instance created if the operation is successful; returns **nullptr** otherwise. If this pointer is no longer required, use [OH_Pasteboard_GetDataParams_Destroy](capi-oh-pasteboard-h.md#oh_pasteboard_getdataparams_destroy) to destroy it. Otherwise, memory leaks may occur. |

### OH_Pasteboard_GetDataParams_Destroy()

```
void OH_Pasteboard_GetDataParams_Destroy(Pasteboard_GetDataParams* params)
```

**Description**

Destroys the [Pasteboard_GetDataParams](capi-pasteboard-getdataparams.md) instance.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [Pasteboard_GetDataParams](capi-pasteboard-getdataparams.md)* params | Pointer to an **OH_Pasteboard_GetDataParams** instance.|

### OH_Pasteboard_GetDataParams_SetProgressIndicator()

```
void OH_Pasteboard_GetDataParams_SetProgressIndicator(Pasteboard_GetDataParams* params,Pasteboard_ProgressIndicator progressIndicator)
```

**Description**

Sets a progress indicator in [Pasteboard_GetDataParams](capi-pasteboard-getdataparams.md). You can use the default progress indicator as required.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [Pasteboard_GetDataParams](capi-pasteboard-getdataparams.md)* params | Pointer to an **OH_Pasteboard_GetDataParams** instance.|
| [Pasteboard_ProgressIndicator](#pasteboard_progressindicator) progressIndicator | Progress indicator to set.|

### OH_Pasteboard_GetDataParams_SetDestUri()

```
void OH_Pasteboard_GetDataParams_SetDestUri(Pasteboard_GetDataParams* params, const char* destUri, uint32_t destUriLen)
```

**Description**

Sets the destination URI for copying files. If file processing is not supported, this parameter is not required. If the application involves complex file processing policies or needs to distinguish file multipathing storage, you are advised not to set this parameter but let the application copies files by itself.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [Pasteboard_GetDataParams](capi-pasteboard-getdataparams.md)* params | Pointer to an **OH_Pasteboard_GetDataParams** instance.|
| const char* destUri | Destination URI of the copied file.|
| uint32_t destUriLen | Length of the destination URI of the copied file.|

### OH_Pasteboard_GetDataParams_SetFileConflictOptions()

```
void OH_Pasteboard_GetDataParams_SetFileConflictOptions(Pasteboard_GetDataParams* params,Pasteboard_FileConflictOptions option)
```

**Description**

Sets the options used to resolve file copy conflicts in a [Pasteboard_GetDataParams](capi-pasteboard-getdataparams.md) instance.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [Pasteboard_GetDataParams](capi-pasteboard-getdataparams.md)* params | Pointer to an **OH_Pasteboard_GetDataParams** instance.|
| [Pasteboard_FileConflictOptions](#pasteboard_fileconflictoptions) option | Options used to resolve file copy conflicts. The default value is **PASTEBOARD_OVERWRITE**.|

### OH_Pasteboard_GetDataParams_SetProgressListener()

```
void OH_Pasteboard_GetDataParams_SetProgressListener(Pasteboard_GetDataParams* params,const OH_Pasteboard_ProgressListener listener)
```

**Description**

Sets a progress listener in a [Pasteboard_GetDataParams](capi-pasteboard-getdataparams.md) instance.

**Since**: 15


**Parameters**

| Name                                                                             | Description|
|----------------------------------------------------------------------------------| -- |
| [Pasteboard_GetDataParams](capi-pasteboard-getdataparams.md)* params             | Pointer to an **OH_Pasteboard_GetDataParams** instance.|
| const [OH_Pasteboard_ProgressListener](#oh_pasteboard_progresslistener) listener | Progress listener.|

### OH_Pasteboard_ProgressInfo_GetProgress()

```
int OH_Pasteboard_ProgressInfo_GetProgress(Pasteboard_ProgressInfo* progressInfo)
```

**Description**

Obtains the paste progress in a [Pasteboard_ProgressInfo](capi-pasteboard-progressinfo.md) instance.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [Pasteboard_ProgressInfo](capi-pasteboard-progressinfo.md)* progressInfo | Pointer to a [Pasteboard_ProgressInfo](capi-pasteboard-progressinfo.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| int | Percentage of the paste progress.|

### OH_Pasteboard_ProgressCancel()

```
void OH_Pasteboard_ProgressCancel(Pasteboard_GetDataParams* params)
```

**Description**

Cancels the ongoing paste operation when the pasteboard data is obtained.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [Pasteboard_GetDataParams](capi-pasteboard-getdataparams.md)* params | Pointer to an **OH_Pasteboard_GetDataParams** instance.|

### OH_Pasteboard_GetDataWithProgress()

```
OH_UdmfData* OH_Pasteboard_GetDataWithProgress(OH_Pasteboard* pasteboard, Pasteboard_GetDataParams* params,int* status)
```

**Description**

Obtains the pasteboard data and paste progress. Folders cannot be copied.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)* pasteboard | Pointer to an [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md) instance.|
| [Pasteboard_GetDataParams](capi-pasteboard-getdataparams.md)* params | Pointer to an **OH_Pasteboard_GetDataParams** instance.|
| int* status | Output parameter, indicating the error code of the operation. For details about the error codes, see [PASTEBOARD_ErrCode](capi-oh-pasteboard-err-code-h.md#pasteboard_errcode).|

**Returns**

| Type| Description|
| -- | -- |
| OH_UdmfData* | Returns the pointer to an **OH_PasteData** instance obtained if the operation is successful; returns a null pointer otherwise.|

### OH_Pasteboard_GetChangeCount()

```
uint32_t OH_Pasteboard_GetChangeCount(OH_Pasteboard *pasteboard)
```

**Description**

Obtains the number of pasteboard content changes.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md) *pasteboard | Pointer to an [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| uint32_t | Returns the number of pasteboard content changes if this API is called successfully; otherwise, returns **0**.<br>Even though the pasteboard data expires, or the data becomes empty because of the called **OH_Pasteboard_ClearData** API, the number of data changes remains.<br>When the system is restarted, or the pasteboard service is restarted due to an exception, the number of pasteboard data changes counts from 0. In addition, copying the same data repeatedly is considered to change the data for multiple times. Therefore, each time the data is copied, the number of data changes increases. |
