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
| typedef enum [Pasteboard_NotifyType](#pasteboard_notifytype) [Pasteboard_NotifyType](#pasteboard_notifytype) | Defines an enum for data change types of the pasteboard. |
| typedef void(\* [Pasteboard_Notify](#pasteboard_notify)) (void \*context, [Pasteboard_NotifyType](#pasteboard_notifytype) type) | Defines a callback to be invoked when the pasteboard content changes. |
| typedef void(\* [Pasteboard_Finalize](#pasteboard_finalize)) (void \*context) | Defines a callback to be invoked to release the context when the pasteboard observer object is destroyed. |
| typedef struct [OH_PasteboardObserver](#oh_pasteboardobserver) [OH_PasteboardObserver](#oh_pasteboardobserver) | Defines the pasteboard observer. |
| typedef struct [OH_Pasteboard](#oh_pasteboard) [OH_Pasteboard](#oh_pasteboard) | Define the pasteboard object to operate the system pasteboard. |
| typedef enum [PASTEBOARD_ErrCode](#pasteboard_errcode) [PASTEBOARD_ErrCode](#pasteboard_errcode) | Defines an enum for the error codes used in the **Pasteboard** module. |
| typedef enum [Pasteboard_FileConflictOption](#pasteboard_fileconflictoption) [Pasteboard_FileConflictOption](#pasteboard_fileconflictoption) | Defines an enum for options for file copy conflicts.|
| typedef enum [Pasteboard_ProgressIndicator](#pasteboard_progressindicator) [Pasteboard_ProgressIndicator](#pasteboard_progressindicator) | Defines an enum for progress indicator options. You can choose whether to use the default progress indicator.|
| typedef struct [Pasteboard_ProgressInfo](#pasteboard_progressinfo) [Pasteboard_ProgressInfo](#pasteboard_progressinfo) | Defines the progress information.|
| typedef struct [Pasteboard_ProgressListener](#pasteboard_progresslistener) [Pasteboard_ProgressListener](#pasteboard_progresslistener) | Defines a listener for progress data changes. If the default progress indicator is not used, you can set this type to obtain the paste progress.|
| typedef struct [Pasteboard_ProgressSignal](#pasteboard_progresssignal) [Pasteboard_ProgressSignal](#pasteboard_progresssignal) | Defines a function for canceling the paste task.|
| typedef struct [OH_Pasteboard_GetDataParams](#oh_pasteboard_getdataparams) [OH_Pasteboard_GetDataParams](#oh_pasteboard_getdataparams) | Defines the parameters required for obtaining data in the pasteboard, including the destination path, file conflict options, and progress indicator options.|
| typedef void(* [Pasteboard_ProgressNotify](#pasteboard_progressnotify))([Pasteboard_ProgressInfo](#pasteboard_progressinfo) progressInfo); | Defines a callback function for obtaining the progress information. If the default progress indicator is not used, you can set this type to obtain the paste progress.|
| typedef int (* [Pasteboard_ProgressCancel](#pasteboard_progresscancel))(); | Defines a function for canceling an ongoing copy-and-paste task.|


### Enums

| Name| Description|
| -------- | -------- |
| [Pasteboard_NotifyType](#pasteboard_notifytype) { NOTIFY_LOCAL_DATA_CHANGE = 1, NOTIFY_REMOTE_DATA_CHANGE = 2 } | Enumerates the data change types of the pasteboard. |
| [PASTEBOARD_ErrCode](#pasteboard_errcode) {<br>ERR_OK = 0, ERR_PERMISSION_ERROR = 201, ERR_INVALID_PARAMETER = 401, ERR_DEVICE_NOT_SUPPORTED = 801,<br>ERR_INNER_ERROR = 12900000, ERR_BUSY = 12900003, ERR_COPY_FILE_ERROR = 12900007, ERR_PROGRESS_START_ERROR = 12900008, ERR_PROGRESS_ABNORMAL = 12900009, ERR_GET_DATA_FAILED = 12900010,<br>} | Enumerates the error codes. |
| [Pasteboard_FileConflictOption](#pasteboard_fileconflictoption) { OVERWRITE = 0, SKIP = 1} | Enumerates options for a file copy conflict.|
| [Pasteboard_ProgressIndicator](#pasteboard_progressindicator) { NONE = 0, DEFAULT = 1 } | Enumerates progress indicator types.|


### Functions

| Name| Description|
| -------- | -------- |
| [OH_PasteboardObserver](#oh_pasteboardobserver) \* [OH_PasteboardObserver_Create](#oh_pasteboardobserver_create) () | Creates an [OH_PasteboardObserver](#oh_pasteboardobserver) instance and a pointer to it. |
| int [OH_PasteboardObserver_Destroy](#oh_pasteboardobserver_destroy) ([OH_PasteboardObserver](#oh_pasteboardobserver) \*observer) | Destroys an [OH_PasteboardObserver](#oh_pasteboardobserver) instance and a pointer to it. |
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
| OH_UdmfDat *[OH_Pasteboard_GetDataWithProgress](#oh_pasteboard_getdatawithprogress)(OH_Pasteboard *pasteboard, [OH_Pasteboard_GetDataParams](#oh_pasteboard_getdataparams) *params, int *status) | Obtains the pasteboard data and paste progress.|
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

### Pasteboard_FileConflictOption 

```
typedef enum Pasteboard_FileConflictOption
```

**Description**

Enumerates options for a file copy conflict.

**Since**: 15

### Pasteboard_ProgressIndicator 

```
typedef enum Pasteboard_ProgressIndicator
```

**Description**

Defines options for the progress indicator. You can choose whether to use the default progress indicator.

**Since**: 15

### Pasteboard_ProgressInfo 

```
typedef struct Pasteboard_ProgressInfo {
	int progress;
} Pasteboard_ProgressInfo;
```

**Description**

Defines the progress information. This information is reported only when [Pasteboard_ProgressIndicator](#pasteboard_progressindicator) is set to **NONE**.

**Since**: 15

| Name    | Type| Description                                                      |
| -------- | ---- | ---------------------------------------------------------- |
| progress | int  | If the progress indicator provided by the system is not used, the system reports the progress percentage of the copy-and-paste task.|

### Pasteboard_ProgressNotify

```
typedef void (*Pasteboard_ProgressNotify)(Pasteboard_ProgressInfo progressInfo);
```

**Description**

Notifies the application of the copy-and-paste task progress when the progress indicator provided by the pasteboard is not used.

**Since**: 15

**Parameters**

| Name        | Type                                               | Description                                                        |
| ------------ | --------------------------------------------------- | ------------------------------------------------------------ |
| progressInfo | [Pasteboard_ProgressInfo](#pasteboard_progressinfo) | Defines the progress information. This information is reported only when [Pasteboard_ProgressIndicator](#pasteboard_progressindicator) is set to **NONE**.|

### Pasteboard_ProgressListener 

```
typedef struct Pasteboard_ProgressListener {
	Pasteboard_ProgressNotify callback;
} Pasteboard_ProgressListener;
```

**Description**

Defines a listener for progress data changes. If the default progress indicator is not used, you can set this type to obtain the paste progress.

**Since**: 15

| Name    | Type                                                   | Description                                                        |
| -------- | ------------------------------------------------------- | ------------------------------------------------------------ |
| callback | [Pasteboard_ProgressNotify](#pasteboard_progressnotify) | Notifies the application of the copy-and-paste task progress when the progress indicator provided by the pasteboard is not used.|

### Pasteboard_ProgressCancel

```
typedef int (*Pasteboard_ProgressCancel)();
```

**Description**

Cancels an ongoing copy-and-paste task.

**Since**: 15

### Pasteboard_ProgressSignal

```
typedef struct Pasteboard_ProgressSignal {
    Pasteboard_ProgressCancel cancel;
} Pasteboard_ProgressSignal;
```

**Description**

Defines a function for canceling the paste task. This parameter is valid only when [Pasteboard_ProgressIndicator](#pasteboard_progressindicator) is set to **NONE**.

**Since**: 15

| Name  | Type                                                   | Description                    |
| ------ | ------------------------------------------------------- | ------------------------ |
| cancel | [Pasteboard_ProgressCancel](#pasteboard_progresscancel) | Cancels an ongoing paste task.|

### OH_Pasteboard_GetDataParams

```
typedef struct OH_Pasteboard_GetDataParams {
    char *destUri;
    unsigned int destUriLen;
    Pasteboard_FileConflictOption fileConflictOption;
    Pasteboard_ProgressIndicator progressIndicator;
    Pasteboard_ProgressListener progressListener;
    Pasteboard_ProgressSignal progressSignal;
} OH_Pasteboard_GetDataParams;
```

**Description**

Obtains parameters when an application uses the file copy capability provided by the pasteboard, including the destination path, file conflict options, and progress indicator types.

**Since**: 15

| Name              | Type                                                        | Description                                                        |
| ------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| destUri            | char *                                                       | Destination path for copying files. If file processing is not supported, this parameter is not required. If the application involves complex file processing policies or needs to distinguish file multipathing storage, you are advised not to set this parameter but let the application copies files by itself.|
| destUriLen         | unsigned int                                                 | Length of the destination path.                                    |
| fileConflictOption | [Pasteboard_FileConflictOption](#pasteboard_fileconflictoption) | File conflict options for a copy-and-paste task. The default value is **OVERWRITE**.                 |
| progressIndicator  | [Pasteboard_ProgressIndicator](#pasteboard_progressindicator) | Progress indicator display options. You can choose whether to use the default progress indicator.        |
| progressListener   | [Pasteboard_ProgressListener](#pasteboard_progresslistener)  | A listener for progress data changes. If the default progress indicator is not used, you can set this variable to obtain the paste progress.|
| progressSignal     | [Pasteboard_ProgressSignal](#pasteboard_progresssignal)      | A function for canceling the paste task. This parameter is valid only when [Pasteboard_ProgressIndicator](#pasteboard_progressindicator) is set to **NONE**.|


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
| ERR_PERMISSION_ERROR  | Permission verification has failed. |
| ERR_INVALID_PARAMETER  | Invalid parameter. |
| ERR_DEVICE_NOT_SUPPORTED  | The device capability is not supported. |
| ERR_INNER_ERROR  | Internal error. |
| ERR_BUSY  | System busy. |
| ERR_COPY_FILE_ERROR | File copying failed.|
| ERR_PROGRESS_START_ERROR | Progress indicator creation fails when the application uses the system progress indicator.|
| ERR_PROGRESS_ABNORMAL | Progress reporting is abnormal when the application stops using the system progress indicator.|
| ERR_GET_DATA_FAILED | Fails to obtain the copied data.|


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

### Pasteboard_FileConflictOption 

```
enum Pasteboard_FileConflictOption
```

**Description**

Defines options for file copy conflicts.

**Since**: 15

| Value   | Description                                                        |
| --------- | ------------------------------------------------------------ |
| OVERWRITE | Overwrites the file with the same name in the destination path.                                |
| SKIP      | Skips the file with the same name in the destination path. If **SKIP** is set, the copied data of the skipped file is not pasted to the application.|

### Pasteboard_ProgressIndicator 

```
enum Pasteboard_ProgressIndicator
```

**Description**

Defines options for the progress indicator. You can choose whether to use the default progress indicator.

**Since**: 15

| Value | Description                    |
| ------- | ------------------------ |
| NONE    | The default progress indicator is not used.|
| DEFAULT | The default progress indicator is used.  |

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

Destroys an [OH_Pasteboard](_pasteboard.md#oh_pasteboard) instance.

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

Returns a pointer to the **OH_UdmfData** instance obtained if the operation is successful; returns **nullptr** otherwise.

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

Returns an error code. For details, see [PASTEBOARD_ErrCode](#pasteboard_errcode).<br>Returns **ERR_OK** if the operation is successful.<br>Returns **ERR_INVALID_PARAMETER** if an invalid parameter is passed in.

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

Returns an error code. For details, see [PASTEBOARD_ErrCode](#pasteboard_errcode).<br>Returns **ERR_OK** if the operation is successful.<br>Returns **ERR_INVALID_PARAMETER** if an invalid parameter is passed in.

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

Returns an error code. For details, see [PASTEBOARD_ErrCode](#pasteboard_errcode).<br>Returns **ERR_OK** if the operation is successful.<br>Returns **ERR_INVALID_PARAMETER** if an invalid parameter is passed in.

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

Returns an error code. For details, see [PASTEBOARD_ErrCode](#pasteboard_errcode).<br>Returns **ERR_OK** if the operation is successful.<br>Returns **ERR_INVALID_PARAMETER** if an invalid parameter is passed in.

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

### OH_Pasteboard_GetDataWithProgress()

```
OH_UdmfData* OH_Pasteboard_GetDataWithProgress(OH_Pasteboard* pasteboard, OH_Pasteboard_GetDataParams *params, int *status);
```

**Description**

Obtains the pasteboard data and progress. This API uses a promise to return the result.

**Since**: 15

**Parameters**

| Name      | Description                                                        |
| ---------- | ------------------------------------------------------------ |
| pasteboard | Pointer to an [OH_Pasteboard](#oh_pasteboard) instance.   |
| params     | Parameters required when an application uses the file copy capability provided by the pasteboard. For details, see [OH_Pasteboard_GetDataParams](#oh_pasteboard_getdataparams).|
| status     | Output parameter, indicating the error code of the operation. For details, see [PASTEBOARD_ErrCode](#pasteboard_errcode).|

**Returns**

Returns a pointer to the **OH_UdmfData** instance obtained if the operation is successful; returns **nullptr** otherwise.

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
