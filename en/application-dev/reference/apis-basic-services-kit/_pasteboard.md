# Pasteboard


## Overview

The **Pasteboard** module supports copying and pasting multiple types of data, including plain text, HTML, URI, and pixel map.

**Since**: 13


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [oh_pasteboard.h](oh__pasteboard_8h.md) | Provides data structure, enum types, and APIs for accessing the system pasteboard.|
| [oh_pasteboard_err_code.h](oh__pasteboard__err__code_8h.md) | Defines the error code information of the pasteboard.|


### Types

| Name| Description|
| -------- | -------- |
| typedef enum [Pasteboard_NotifyType](#pasteboard_notifytype) [Pasteboard_NotifyType](#pasteboard_notifytype) | Enumerates the data change types of the pasteboard. |
| typedef void(\* [Pasteboard_Notify](#pasteboard_notify)) (void \*context, [Pasteboard_NotifyType](#pasteboard_notifytype) type) | Defines a callback to be invoked when the pasteboard content changes. |
| typedef void(\* [Pasteboard_Finalize](#pasteboard_finalize)) (void \*context) | Defines a callback to be invoked to release the context when the pasteboard observer object is destroyed. |
| typedef struct [OH_PasteboardObserver](#oh_pasteboardobserver) [OH_PasteboardObserver](#oh_pasteboardobserver) | Defines the pasteboard observer. |
| typedef struct [OH_Pasteboard](#oh_pasteboard) [OH_Pasteboard](#oh_pasteboard) | Define the pasteboard object to operate the system pasteboard. |
| typedef enum [PASTEBOARD_ErrCode](#pasteboard_errcode) [PASTEBOARD_ErrCode](#pasteboard_errcode) | Enumerates the error codes. |
| typedef enum [Pasteboard_FileConflictOptions](#pasteboard_fileconflictoptions) [Pasteboard_FileConflictOptions](#pasteboard_fileconflictoptions) | Defines an enum for options for file copy conflicts.|
| typedef enum [Pasteboard_ProgressIndicator](#pasteboard_progressindicator) [Pasteboard_ProgressIndicator](#pasteboard_progressindicator) | Defines an enum for progress indicator options. You can use the default progress indicator as required.|
| typedef struct [Pasteboard_ProgressInfo](#pasteboard_progressinfo) [Pasteboard_ProgressInfo](#pasteboard_progressinfo) | Defines the progress information. This information is reported only when [Pasteboard_ProgressIndicator](#pasteboard_progressindicator) is set to **PASTEBOARD_NONE**.|
| typedef void (* [OH_Pasteboard_ProgressListener](#oh_pasteboard_progresslistener))([Pasteboard_ProgressInfo](#pasteboard_progressinfo)* progressInfo) | Defines a callback function for obtaining the progress information. If the default progress indicator is not used, you can set this parameter to obtain the pasting progress.|
| typedef struct [Pasteboard_GetDataParams](#pasteboard_getdataparams) [Pasteboard_GetDataParams](#pasteboard_getdataparams) | Defines a struct for the pasteboard parameters required for displaying progress, including progress indicator options, destination path, and file conflict options.|


### Enumerated value

| Name| Description|
| -------- | -------- |
| [Pasteboard_NotifyType](#pasteboard_notifytype) { NOTIFY_LOCAL_DATA_CHANGE = 1, NOTIFY_REMOTE_DATA_CHANGE = 2 } | Enumerates the data change types of the pasteboard. |
| [PASTEBOARD_ErrCode](#pasteboard_errcode) {<br>ERR_OK = 0, ERR_PERMISSION_ERROR = 201, ERR_INVALID_PARAMETER = 401, ERR_DEVICE_NOT_SUPPORTED = 801,<br>ERR_INNER_ERROR = 12900000, ERR_BUSY = 12900003, ERR_PASTEBOARD_COPY_FILE_ERROR = 12900007, ERR_PASTEBOARD_PROGRESS_START_ERROR = 12900008, ERR_PASTEBOARD_PROGRESS_ABNORMAL = 12900009, ERR_PASTEBOARD_GET_DATA_FAILED = 12900010, ERR_BUSY_PROCESSING = 27787277, ERR_COPY_FORBIDDEN = 27787278<br>} | Enumerates the error codes. |
| [Pasteboard_FileConflictOptions](#pasteboard_fileconflictoptions) { PASTEBOARD_OVERWRITE = 0, PASTEBOARD_SKIP = 1} | Enumerates options for a file copy conflict.|
| [Pasteboard_ProgressIndicator](#pasteboard_progressindicator) { PASTEBOARD_NONE = 0, PASTEBOARD_DEFAULT = 1 } | Enumerates progress indicator types.|


### Functions

| Name| Description|
| -------- | -------- |
| [OH_PasteboardObserver](#oh_pasteboardobserver) \* [OH_PasteboardObserver_Create](#oh_pasteboardobserver_create) () | Creates an [OH_PasteboardObserver](#oh_pasteboardobserver) instance and a pointer to it. |
| int [OH_PasteboardObserver_Destroy](#oh_pasteboardobserver_destroy) ([OH_PasteboardObserver](#oh_pasteboardobserver) \*observer) | Destroys an [OH_PasteboardObserver](#oh_pasteboardobserver) instance. |
| int [OH_PasteboardObserver_SetData](#oh_pasteboardobserver_setdata) ([OH_PasteboardObserver](#oh_pasteboardobserver) \*observer, void \*context, const [Pasteboard_Notify](#pasteboard_notify) callback, const [Pasteboard_Finalize](#pasteboard_finalize) finalize) | Sets a callback for the pasteboard observer. |
| [OH_Pasteboard](#oh_pasteboard) \* [OH_Pasteboard_Create](#oh_pasteboard_create) () | Creates an [OH_Pasteboard](#oh_pasteboard) instance and a pointer to it. |
| void [OH_Pasteboard_Destroy](#oh_pasteboard_destroy) ([OH_Pasteboard](#oh_pasteboard) \*pasteboard) | Destroys an [OH_Pasteboard](#oh_pasteboard) instance. |
| int [OH_Pasteboard_Subscribe](#oh_pasteboard_subscribe) ([OH_Pasteboard](#oh_pasteboard) \*pasteboard, int type, const [OH_PasteboardObserver](#oh_pasteboardobserver) \*observer) | Subscribes to the pasteboard observer. |
| int [OH_Pasteboard_Unsubscribe](#oh_pasteboard_unsubscribe) ([OH_Pasteboard](#oh_pasteboard) \*pasteboard, int type, const [OH_PasteboardObserver](#oh_pasteboardobserver) \*observer) | Unsubscribes from the pasteboard observer. |
| bool [OH_Pasteboard_IsRemoteData](#oh_pasteboard_isremotedata) ([OH_Pasteboard](#oh_pasteboard) \*pasteboard) | Checks whether the pasteboard data comes from remote devices. |
| int [OH_Pasteboard_GetDataSource](#oh_pasteboard_getdatasource) ([OH_Pasteboard](#oh_pasteboard) \*pasteboard, char \*source, unsigned int len) | Obtains the pasteboard data source. |
| bool [OH_Pasteboard_HasType](#oh_pasteboard_hastype) ([OH_Pasteboard](#oh_pasteboard) \*pasteboard, const char \*type) | Checks whether the pasteboard contains data of the specified type. |
| bool [OH_Pasteboard_HasData](#oh_pasteboard_hasdata) ([OH_Pasteboard](#oh_pasteboard) \*pasteboard) | Checks whether the pasteboard contains data. |
| OH_UdmfData \* [OH_Pasteboard_GetData](#oh_pasteboard_getdata) ([OH_Pasteboard](#oh_pasteboard) \*pasteboard, int \*status) | Obtains data from the pasteboard. |
| int [OH_Pasteboard_SetData](#oh_pasteboard_setdata) ([OH_Pasteboard](#oh_pasteboard) \*pasteboard, OH_UdmfData \*data) | Writes the unified data object to the pasteboard. |
| int [OH_Pasteboard_ClearData](#oh_pasteboard_cleardata) ([OH_Pasteboard](#oh_pasteboard) \*pasteboard) | Clears data from the pasteboard. |
| char ** [OH_Pasteboard_GetMimeTypes](#oh_pasteboard_getmimetypes) ([OH_Pasteboard](#oh_pasteboard) \*pasteboard, unsigned int *count) | Obtains the MIME type from the pasteboard. |
| [Pasteboard_GetDataParams](#pasteboard_getdataparams) *[OH_Pasteboard_GetDataParams_Create](#oh_pasteboard_getdataparams_create)(void) | Creates a [Pasteboard_GetDataParams](#pasteboard_getdataparams) instance and a pointer to it.|
| void [OH_Pasteboard_GetDataParams_Destroy](#oh_pasteboard_getdataparams_destroy)([Pasteboard_GetDataParams](#pasteboard_getdataparams)* params) | Destroys a [Pasteboard_GetDataParams](#pasteboard_getdataparams) instance.|
| void [OH_Pasteboard_GetDataParams_SetProgressIndicator](#oh_pasteboard_getdataparams_setprogressindicator)([Pasteboard_GetDataParams](#pasteboard_getdataparams)* params, [Pasteboard_ProgressIndicator](#pasteboard_progressindicator) progressIndicator) | Sets the progress indication options in [Pasteboard_GetDataParams](#pasteboard_getdataparams). You can use the default progress indicator as required.|
| void [OH_Pasteboard_GetDataParams_SetDestUri](#oh_pasteboard_getdataparams_setdesturi)([Pasteboard_GetDataParams](#pasteboard_getdataparams)* params, const char* destUri, uint32_t destUriLen) | Sets the destination path in [Pasteboard_GetDataParams](#pasteboard_getdataparams).|
| void [OH_Pasteboard_GetDataParams_SetFileConflictOptions](#oh_pasteboard_getdataparams_setfileconflictoptions)([Pasteboard_GetDataParams](#pasteboard_getdataparams)* params, [Pasteboard_FileConflictOptions](#pasteboard_fileconflictoptions) option) | Sets the file copy conflict options in [Pasteboard_GetDataParams](#pasteboard_getdataparams).|
| void [OH_Pasteboard_GetDataParams_SetProgressListener](#oh_pasteboard_getdataparams_setprogresslistener)([Pasteboard_GetDataParams](#pasteboard_getdataparams)* params, const [OH_Pasteboard_ProgressListener](#oh_pasteboard_progresslistener) listener) | Sets a progress listener in [Pasteboard_GetDataParams](#pasteboard_getdataparams).|
| int [OH_Pasteboard_ProgressInfo_GetProgress](#oh_pasteboard_progressinfo_getprogress)([Pasteboard_ProgressInfo](#pasteboard_progressinfo)* progressInfo) | Obtains the pasting progress using [Pasteboard_ProgressInfo](#pasteboard_progressinfo).|
| void [OH_Pasteboard_ProgressCancel](#oh_pasteboard_progresscancel)([Pasteboard_GetDataParams](#pasteboard_getdataparams)* params) | Cancels an ongoing copy and paste task using [Pasteboard_GetDataParams](#pasteboard_getdataparams).|
| OH_UdmfData* [OH_Pasteboard_GetDataWithProgress](#oh_pasteboard_getdatawithprogress)([OH_Pasteboard](#oh_pasteboard)* pasteboard, [Pasteboard_GetDataParams](#pasteboard_getdataparams)* params, int* status) | Obtains the pasteboard data and pasting progress. Folders cannot be copied.|
| uint32_t [OH_Pasteboard_GetChangeCount](#oh_pasteboard_getchangecount) ([OH_Pasteboard](#oh_pasteboard) \*pasteboard) | Obtains the number of times that the pasteboard data changes. |


## Type Description


### OH_Pasteboard

```
typedef struct OH_Pasteboard OH_Pasteboard
```
**Description**

Define the pasteboard object to operate the system pasteboard.

**Since**: 13


### OH_PasteboardObserver

```
typedef struct OH_PasteboardObserver OH_PasteboardObserver
```
**Description**

Defines the pasteboard observer.

**Since**: 13


### PASTEBOARD_ErrCode

```
typedef enum PASTEBOARD_ErrCode PASTEBOARD_ErrCode
```
**Description**

Enumerates the error codes.

**Since**: 13


### Pasteboard_Finalize

```
typedef void(* Pasteboard_Finalize) (void *context)
```
**Description**

Defines a callback to be invoked to release the context when the pasteboard observer object is destroyed.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| context | Pointer to the context to release. |


### Pasteboard_Notify

```
typedef void(* Pasteboard_Notify) (void *context, Pasteboard_NotifyType type)
```
**Description**

Defines a callback to be invoked when the pasteboard content changes.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| context | Context, which is passed in by the [OH_PasteboardObserver_SetData](#oh_pasteboardobserver_setdata) function. |
| type | Data change type. For details, see [Pasteboard_NotifyType](#pasteboard_notifytype). |


### Pasteboard_NotifyType

```
typedef enum Pasteboard_NotifyType Pasteboard_NotifyType
```
**Description**

Enumerates the data change types of the pasteboard.

**Since**: 13

### Pasteboard_FileConflictOptions

```
typedef enum Pasteboard_FileConflictOptions Pasteboard_FileConflictOptions
```

**Description**

File conflict options for a copy-and-paste task. The default value is **PASTEBOARD_OVERWRITE**.

**Since**: 15

### Pasteboard_ProgressIndicator 

```
typedef enum Pasteboard_ProgressIndicator Pasteboard_ProgressIndicator
```

**Description**

Defines options for the progress indicator. You can use the default progress indicator as required.

**Since**: 15

### Pasteboard_ProgressInfo

```
typedef struct Pasteboard_ProgressInfo Pasteboard_ProgressInfo
```

**Description**

Defines the progress information. This information is reported only when [Pasteboard_ProgressIndicator](#pasteboard_progressindicator) is set to **NONE**.

**Since**: 15

### OH_Pasteboard_ProgressListener

```
typedef void (*OH_Pasteboard_ProgressListener)(Pasteboard_ProgressInfo* progressInfo);
```

**Description**

Notifies the application of the copy and paste task progress when the default progress indicator is not used.

**Since**: 15

**Parameters**

| Name        | Type                                               | Description                                                        |
| ------------ | --------------------------------------------------- | ------------------------------------------------------------ |
| progressInfo | [Pasteboard_ProgressInfo](#pasteboard_progressinfo) | Defines the progress information. This information is reported only when [Pasteboard_ProgressIndicator](#pasteboard_progressindicator) is set to **NONE**.|

### Pasteboard_GetDataParams

```
typedef struct Pasteboard_GetDataParams Pasteboard_GetDataParams;
```

**Description**

Defines a struct for the pasteboard parameters required for displaying progress, including progress indicator options, destination path, and file conflict options.

**Since**: 15


## Enum Description


### PASTEBOARD_ErrCode

```
enum PASTEBOARD_ErrCode
```
**Description**

Enumerates the error codes.

**Since**: 13

| Value| Description|
| -------- | -------- |
| ERR_OK  | The operation is successful. |
| ERR_PERMISSION_ERROR  | Permission verification failed. |
| ERR_INVALID_PARAMETER  | Invalid parameter. |
| ERR_DEVICE_NOT_SUPPORTED  | The device capability is not supported. |
| ERR_INNER_ERROR  | Internal error. |
| ERR_BUSY  | System busy. |
| ERR_PASTEBOARD_COPY_FILE_ERROR | File copying failed.|
| ERR_PASTEBOARD_PROGRESS_START_ERROR | Progress indicator creation fails when the application uses the system progress indicator.|
| ERR_PASTEBOARD_PROGRESS_ABNORMAL | Progress reporting is abnormal when the application stops using the system progress indicator.|
| ERR_PASTEBOARD_GET_DATA_FAILED | Obtaining pasteboard data failed.|


### Pasteboard_NotifyType

```
enum Pasteboard_NotifyType
```
**Description**

Enumerates the data change types of the pasteboard.

**Since**: 13

| Value| Description|
| -------- | -------- |
| NOTIFY_LOCAL_DATA_CHANGE  | The pasteboard data of the local device is changed. |
| NOTIFY_REMOTE_DATA_CHANGE  | The pasteboard data of a non-local device on the network is changed. |

### Pasteboard_FileConflictOptions 

```
enum Pasteboard_FileConflictOptions
```

**Description**

Defines options for file copy conflicts.

**Since**: 15

| Value              | Description                                                        |
| -------------------- | ------------------------------------------------------------ |
| PASTEBOARD_OVERWRITE | Overwrites the file with the same name in the destination path.                                |
| PASTEBOARD_SKIP      | Skips the file with the same name in the destination path. If **SKIP** is set, the pasteboard data of the skipped file is not pasted to the application.|

### Pasteboard_ProgressIndicator 

```
enum Pasteboard_ProgressIndicator
```

**Description**

Defines options for the progress indicator. You can use the default progress indicator as required.

**Since**: 15

| Value            | Description                    |
| ------------------ | ------------------------ |
| PASTEBOARD_NONE    | The default progress indicator is not used.|
| PASTEBOARD_DEFAULT | The default progress indicator is used.  |

## Function Description


### OH_Pasteboard_ClearData()

```
int OH_Pasteboard_ClearData (OH_Pasteboard * pasteboard)
```
**Description**

Clears data from the pasteboard.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| pasteboard | Pointer to an [OH_Pasteboard](#oh_pasteboard) instance. |

**Returns**

Returns an error code. For details, see [PASTEBOARD_ErrCode](#pasteboard_errcode).<br>Returns **ERR_OK** if the operation is successful.<br>Returns **ERR_INVALID_PARAMETER** if an invalid parameter is passed in.

**See**

[OH_Pasteboard](#oh_pasteboard)

[PASTEBOARD_ErrCode](#pasteboard_errcode)


### OH_Pasteboard_Create()

```
OH_Pasteboard* OH_Pasteboard_Create ()
```
**Description**

Creates an [OH_Pasteboard](#oh_pasteboard) instance and a pointer to it.

**Since**: 13

**Returns**

Returns a pointer to the [OH_Pasteboard](#oh_pasteboard) instance created if the operation is successful; returns **nullptr** otherwise.

**See**

[OH_Pasteboard](#oh_pasteboard)


### OH_Pasteboard_Destroy()

```
void OH_Pasteboard_Destroy (OH_Pasteboard * pasteboard)
```
**Description**

Destroys an [OH_Pasteboard](#oh_pasteboard) instance.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| pasteboard | Pointer to an [OH_Pasteboard](#oh_pasteboard) instance. |

**See**

[OH_Pasteboard](#oh_pasteboard)


### OH_Pasteboard_GetData()

```
OH_UdmfData* OH_Pasteboard_GetData (OH_Pasteboard * pasteboard, int * status )
```
**Description**

Obtains data from the pasteboard.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| pasteboard | Pointer to an [OH_Pasteboard](#oh_pasteboard) instance. |
| status | Output parameter, indicating the error code of the operation. For details, see [PASTEBOARD_ErrCode](#pasteboard_errcode). |

**Returns**

Returns a pointer to the **OH_UdmfData** instance obtained if the operation is successful; returns <b>nullptr</b> otherwise.

**See**

[OH_Pasteboard](#oh_pasteboard)

OH_UdmfData

[PASTEBOARD_ErrCode](#pasteboard_errcode)


### OH_Pasteboard_GetDataSource()

```
int OH_Pasteboard_GetDataSource (OH_Pasteboard * pasteboard, char * source, unsigned int len )
```
**Description**

Obtains the pasteboard data source.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| pasteboard | Pointer to an [OH_Pasteboard](#oh_pasteboard) instance. |
| source | Output parameter, indicating the source string of the pasteboard data. |
| len | Output parameter, indicating the length of the data source string. |

**Returns**

Returns an error code. For details, see [PASTEBOARD_ErrCode](#pasteboard_errcode).<br>Returns **ERR_OK** if the operation is successful.<br>Returns **ERR_INVALID_PARAMETER** if an invalid parameter is passed in.

**See**

[OH_Pasteboard](#oh_pasteboard)

[PASTEBOARD_ErrCode](#pasteboard_errcode)


### OH_Pasteboard_HasData()

```
bool OH_Pasteboard_HasData (OH_Pasteboard * pasteboard)
```
**Description**

Checks whether the pasteboard contains data.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| pasteboard | Pointer to an [OH_Pasteboard](#oh_pasteboard) instance. |

**Returns**

Returns a Boolean value indicating whether the pasteboard contains data. The value **true** means the pasteboard contains data; the value **false** means the opposite.

**See**

[OH_Pasteboard](#oh_pasteboard)


### OH_Pasteboard_HasType()

```
bool OH_Pasteboard_HasType (OH_Pasteboard * pasteboard, const char * type )
```
**Description**

Checks whether the pasteboard contains data of the specified type.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| pasteboard | Pointer to an [OH_Pasteboard](#oh_pasteboard) instance. |
| type | Data type to be checked. |

**Returns**

Returns a Boolean value indicating whether the pasteboard contains data of the specified type. The value **true** means the pasteboard contains data of the specified type; the value **false** means the opposite.

**See**

[OH_Pasteboard](#oh_pasteboard)


### OH_Pasteboard_IsRemoteData()

```
bool OH_Pasteboard_IsRemoteData (OH_Pasteboard * pasteboard)
```
**Description**

Checks whether the pasteboard data comes from remote devices.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| pasteboard | Pointer to an [OH_Pasteboard](#oh_pasteboard) instance. |

**Returns**

Returns a Boolean value indicating whether the data is from a remote device. The value **true** means the data is from a remote device. The value **false** means the data is from the local device.

**See**

[OH_Pasteboard](#oh_pasteboard)


### OH_Pasteboard_SetData()

```
int OH_Pasteboard_SetData (OH_Pasteboard * pasteboard, OH_UdmfData * data )
```
**Description**

Writes the unified data object to the pasteboard.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| pasteboard | Pointer to an [OH_Pasteboard](#oh_pasteboard) instance. |
| data | Pointer to an **OH_UdmfData** instance. |

**Returns**

Returns an error code. For details, see [PASTEBOARD_ErrCode](#pasteboard_errcode).<br> Returns **ERR_OK** if the operation is successful.<br> Returns **ERR_INVALID_PARAMETER** if an invalid parameter is passed in.

**See**

[OH_Pasteboard](#oh_pasteboard)

OH_UdmfData

[PASTEBOARD_ErrCode](#pasteboard_errcode)


### OH_Pasteboard_Subscribe()

```
int OH_Pasteboard_Subscribe (OH_Pasteboard * pasteboard, int type, const OH_PasteboardObserver * observer )
```
**Description**

Subscribes to the pasteboard observer.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| pasteboard | Pointer to an [OH_Pasteboard](#oh_pasteboard) instance. |
| type | Subscribed data change type of the pasteboard. For details, see [Pasteboard_NotifyType](#pasteboard_notifytype). |
| observer | Pointer to an [OH_PasteboardObserver](#oh_pasteboardobserver) instance. It specifies the callback to be invoked when the pasteboard data changes. For details, see [OH_PasteboardObserver](#oh_pasteboardobserver). |

**Returns**

Returns an error code. For details, see [PASTEBOARD_ErrCode](#pasteboard_errcode).<br> Returns **ERR_OK** if the operation is successful.<br> Returns **ERR_INVALID_PARAMETER** if an invalid parameter is passed in.

**See**

[OH_Pasteboard](#oh_pasteboard)

[OH_PasteboardObserver](#oh_pasteboardobserver)

[Pasteboard_NotifyType](#pasteboard_notifytype)

[PASTEBOARD_ErrCode](#pasteboard_errcode)


### OH_Pasteboard_Unsubscribe()

```
int OH_Pasteboard_Unsubscribe (OH_Pasteboard * pasteboard, int type, const OH_PasteboardObserver * observer )
```
**Description**

Unsubscribes from the pasteboard observer.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| pasteboard | Pointer to an [OH_Pasteboard](#oh_pasteboard) instance. |
| type | Subscribed data change type of the pasteboard. For details, see [Pasteboard_NotifyType](#pasteboard_notifytype). |
| observer | Pointer to an [OH_PasteboardObserver](#oh_pasteboardobserver) instance. It specifies the callback to be invoked when the pasteboard data changes. For details, see [OH_PasteboardObserver](#oh_pasteboardobserver). |

**Returns**

Returns an error code. For details, see [PASTEBOARD_ErrCode](#pasteboard_errcode).<br> Returns **ERR_OK** if the operation is successful.<br> Returns **ERR_INVALID_PARAMETER** if an invalid parameter is passed in.

**See**

[OH_Pasteboard](#oh_pasteboard)

[OH_PasteboardObserver](#oh_pasteboardobserver)

[Pasteboard_NotifyType](#pasteboard_notifytype)

[PASTEBOARD_ErrCode](#pasteboard_errcode)


### OH_PasteboardObserver_Create()

```
OH_PasteboardObserver* OH_PasteboardObserver_Create ()
```
**Description**

Creates an [OH_PasteboardObserver](#oh_pasteboardobserver) instance and a pointer to it.

**Since**: 13

**Returns**

Returns a pointer to the [OH_PasteboardObserver](#oh_pasteboardobserver) instance created if the operation is successful; returns **nullptr** otherwise. If this pointer is no longer required, use [OH_PasteboardObserver_Destroy](#oh_pasteboardobserver_destroy) to destroy it. Otherwise, memory leaks may occur.

**See**

[OH_PasteboardObserver](#oh_pasteboardobserver)


### OH_PasteboardObserver_Destroy()

```
int OH_PasteboardObserver_Destroy (OH_PasteboardObserver * observer)
```
**Description**

Destroys an [OH_PasteboardObserver](_pasteboard.md#oh_pasteboardobserver) instance.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| observer | Pointer to an [OH_PasteboardObserver](#oh_pasteboardobserver) instance. |

**Returns**

Returns an error code. For details, see [PASTEBOARD_ErrCode](#pasteboard_errcode).<br>Returns **ERR_OK** if the operation is successful.<br>Returns **ERR_INVALID_PARAMETER** if an invalid parameter is passed in.

**See**

[OH_PasteboardObserver](#oh_pasteboardobserver)

[PASTEBOARD_ErrCode](#pasteboard_errcode)


### OH_PasteboardObserver_SetData()

```
int OH_PasteboardObserver_SetData (OH_PasteboardObserver * observer, void * context, const Pasteboard_Notify callback, const Pasteboard_Finalize finalize )
```
**Description**

Sets a callback for the pasteboard observer.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| observer | Pointer to an [OH_PasteboardObserver](#oh_pasteboardobserver) instance. |
| context | Pointer to the context data, which is passed to [Pasteboard_Notify](#pasteboard_notify) as the first parameter. |
| callback | Callback to be invoked when the data changes. For details, see [Pasteboard_Notify](#pasteboard_notify). |
| finalize | Optional callback, which can be used to release context data when the pasteboard observer is destroyed. For details, see [Pasteboard_Finalize](#pasteboard_finalize). |

**Returns**

Returns an error code. For details, see [PASTEBOARD_ErrCode](#pasteboard_errcode).<br> Returns **ERR_OK** if the operation is successful.<br> Returns **ERR_INVALID_PARAMETER** if an invalid parameter is passed in.

**See**

[OH_PasteboardObserver](#oh_pasteboardobserver)

[Pasteboard_Notify](#pasteboard_notify)

[PASTEBOARD_ErrCode](#pasteboard_errcode)

### OH_Pasteboard_GetMimeTypes()

```
char ** OH_Pasteboard_GetMimeTypes (OH_Pasteboard * pasteboard, unsigned int * count)
```
**Description**

Obtains the MIME type from the pasteboard.

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| pasteboard | Pointer to an [OH_Pasteboard](#oh_pasteboard) instance. |
| count | Pointer to the number of uniform data types obtained. |

**Returns**

Returns the MIME type obtained if the operation is successful; returns **nullptr** otherwise.

The lifecycle of the object returned by this API is managed by the input parameter object **pasteboard**. When the application calls [OH_Pasteboard_Destroy](#oh_pasteboard_destroy) to destroy **pasteboard**, the result returned by this API is released synchronously.

The **pasteboard** object saves only the latest result and the historical results obtained by the API become invalid.

**See**

[OH_Pasteboard](#oh_pasteboard)

### OH_Pasteboard_GetDataParams_Create()

```c
Pasteboard_GetDataParams *OH_Pasteboard_GetDataParams_Create(void);
```

**Description**

Creates a [Pasteboard_GetDataParams](#pasteboard_getdataparams) instance and a pointer to it.

**Since**: 15

**Returns**

Returns a pointer to the [Pasteboard_GetDataParams](#pasteboard_getdataparams) instance created if the operation is successful; returns **nullptr** otherwise. If this pointer is no longer required, use [OH_Pasteboard_GetDataParams_Destroy](#oh_pasteboard_getdataparams_destroy) to destroy it. Otherwise, memory leaks may occur.

**See**

[Pasteboard_GetDataParams](#pasteboard_getdataparams)

### OH_Pasteboard_GetDataParams_Destroy()

```c
void OH_Pasteboard_GetDataParams_Destroy(Pasteboard_GetDataParams* params)
```

**Description**

Destroys a [Pasteboard_GetDataParams](#pasteboard_getdataparams) instance.

**Since**: 15

**Parameters**

| Name  | Description                                                        |
| ------ | ------------------------------------------------------------ |
| params | Pointer to a [Pasteboard_GetDataParams](#pasteboard_getdataparams) instance.|

**See**

[Pasteboard_GetDataParams](#pasteboard_getdataparams)

### OH_Pasteboard_GetDataParams_SetProgressIndicator()

```c
void OH_Pasteboard_GetDataParams_SetProgressIndicator(Pasteboard_GetDataParams* params,
    Pasteboard_ProgressIndicator progressIndicator)
```

**Description**

Sets the progress indication options in [Pasteboard_GetDataParams](#pasteboard_getdataparams). You can use the default progress indicator as required.

**Since**: 15

**Parameters**

| Name             | Description                                                |
| ----------------- | ---------------------------------------------------- |
| params            | Pointer to the context data.                          |
| progressIndicator | Progress indicator options. You can use the default progress indicator as required.|

**See**

[Pasteboard_GetDataParams](#pasteboard_getdataparams)

[Pasteboard_ProgressIndicator](#pasteboard_progressindicator)

### OH_Pasteboard_GetDataParams_SetDestUri()

```c
void OH_Pasteboard_GetDataParams_SetDestUri(Pasteboard_GetDataParams* params, const char* destUri, uint32_t destUriLen)
```

**Description**

Sets the destination path in [Pasteboard_GetDataParams](#pasteboard_getdataparams) for copying files. If file processing is not supported, this parameter is not required. If the application involves complex file processing policies or needs to distinguish file multipathing storage, you are advised not to set this parameter but let the application copies files by itself.

**Since**: 15

**Parameters**

| Name      | Description                      |
| ---------- | -------------------------- |
| params     | Pointer to the context data.|
| destUri    | Destination path for copying files.|
| destUriLen | Length of the destination path.        |

**See**

[Pasteboard_GetDataParams](#pasteboard_getdataparams)

[Pasteboard_ProgressIndicator](#pasteboard_progressindicator)

### OH_Pasteboard_GetDataParams_SetFileConflictOptions()

```c
void OH_Pasteboard_GetDataParams_SetFileConflictOptions(Pasteboard_GetDataParams* params,
    Pasteboard_FileConflictOptions option)
```

**Description**

Sets the file copy conflict options in [Pasteboard_GetDataParams](#pasteboard_getdataparams). The default value is **PASTEBOARD_OVERWRITE**.

**Since**: 15

**Parameters**

| Name  | Description                                                  |
| ------ | ------------------------------------------------------ |
| params | Pointer to the context data.                            |
| option | File copy conflict options The default value is **PASTEBOARD_OVERWRITE**.|

**See**

[Pasteboard_GetDataParams](#pasteboard_getdataparams)

[Pasteboard_FileConflictOptions](#pasteboard_fileconflictoptions)

### OH_Pasteboard_GetDataParams_SetProgressListener()

```c
void OH_Pasteboard_GetDataParams_SetProgressListener(Pasteboard_GetDataParams* params,
    const OH_Pasteboard_ProgressListener listener)
```

**Description**

Sets a progress listener in [Pasteboard_GetDataParams](#pasteboard_getdataparams).

**Since**: 15

**Parameters**

| Name    | Description                                                        |
| -------- | ------------------------------------------------------------ |
| params   | Pointer to the context data.                                  |
| listener | A listener for progress data changes. If the default progress indicator is not used, you can set this parameter to obtain the pasting progress.|

**See**

[Pasteboard_GetDataParams](#pasteboard_getdataparams)

[OH_Pasteboard_ProgressListener](#oh_pasteboard_progresslistener)

### OH_Pasteboard_ProgressInfo_GetProgress()

```c
int OH_Pasteboard_ProgressInfo_GetProgress(Pasteboard_ProgressInfo* progressInfo)
```

**Description**

Obtains the pasting progress using [Pasteboard_ProgressInfo](#pasteboard_progressinfo). Result can be obtained only when [Pasteboard_ProgressIndicator](#pasteboard_progressindicator) is set to **PASTEBOARD_NONE**.

**Since**: 15

**Parameters**

| Name        | Description                                                        |
| ------------ | ------------------------------------------------------------ |
| progressInfo | Defines the progress information. This information is reported only when [Pasteboard_ProgressIndicator](#pasteboard_progressindicator) is set to **PASTEBOARD_NONE**.|

**Returns**

Returns progress percentage of a copy and paste task.

**See**

[Pasteboard_ProgressInfo](#pasteboard_progressinfo)

### OH_Pasteboard_ProgressCancel()

```c
void OH_Pasteboard_ProgressCancel(Pasteboard_GetDataParams* params);
```

**Description**

Cancels an ongoing copy and paste task using [Pasteboard_GetDataParams](#pasteboard_getdataparams). This parameter is valid only when [Pasteboard_ProgressIndicator](#pasteboard_progressindicator) is set to **PASTEBOARD_NONE**.

**Since**: 15

**Parameters**

| Name  | Description                      |
| ------ | -------------------------- |
| params | Pointer to the context data.|

**See**

[Pasteboard_GetDataParams](#pasteboard_getdataparams)

### OH_Pasteboard_GetDataWithProgress()

```c
OH_UdmfData* OH_Pasteboard_GetDataWithProgress(OH_Pasteboard* pasteboard, Pasteboard_GetDataParams* params, int* status);
```

**Description**

Obtains the pasteboard content and progress. Folders cannot be copied.

**Since**: 15

**Parameters**

| Name      | Description                                                        |
| ---------- | ------------------------------------------------------------ |
| pasteboard | Pointer to an [OH_Pasteboard](#oh_pasteboard) instance.   |
| params     | Parameters required when an application uses the file copy capability provided by the pasteboard. For details, see [Pasteboard_GetDataParams](#pasteboard_getdataparams).|
| status     | Output parameter, indicating the error code of the operation. For details, see [PASTEBOARD_ErrCode](#pasteboard_errcode).|

**Returns**

Returns a pointer to the **OH_UdmfData** instance obtained if the operation is successful; returns <b>nullptr</b> otherwise.

**See**

[Pasteboard_GetDataParams](#pasteboard_getdataparams)

### OH_Pasteboard_GetChangeCount()

```
uint32_t OH_Pasteboard_GetChangeCount(OH_Pasteboard *pasteboard);
```
**Description**

Obtains the number of times that the pasteboard data changes.

Even though the pasteboard data expires, or the data becomes empty because of the called [OH_Pasteboard_ClearData](#oh_pasteboard_cleardata) API, the number of data changes remains.

When the system is restarted, or the pasteboard service is restarted due to an exception, the number of pasteboard data changes counts from 0. In addition, copying the same data repeatedly is considered to change the data for multiple times. Therefore, each time the data is copied, the number of data changes increases.

**Since**: 16

**Parameters**

| Name| Description|
| -------- | -------- |
| pasteboard | Pointer to an [OH_Pasteboard](#oh_pasteboard) instance. |

**Returns**

Returns the result if this API is called successfully; otherwise, returns **0**.

**See**

[OH_Pasteboard](#oh_pasteboard)

