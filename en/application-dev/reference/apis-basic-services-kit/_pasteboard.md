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
| typedef enum [Pasteboard_NotifyType](#pasteboard_notifytype) [Pasteboard_NotifyType](#pasteboard_notifytype) | Defines an enum for the data change types of the pasteboard. |
| typedef void(\* [Pasteboard_Notify](#pasteboard_notify)) (void \*context, [Pasteboard_NotifyType](#pasteboard_notifytype) type) | Defines a callback to be invoked when the pasteboard content changes. |
| typedef void(\* [Pasteboard_Finalize](#pasteboard_finalize)) (void \*context) | Defines a callback to be invoked to release the context when the pasteboard observer object is destroyed. |
| typedef struct [OH_PasteboardObserver](#oh_pasteboardobserver) [OH_PasteboardObserver](#oh_pasteboardobserver) | Defines the pasteboard observer. |
| typedef struct [OH_Pasteboard](#oh_pasteboard) [OH_Pasteboard](#oh_pasteboard) | Define the pasteboard object to operate the system pasteboard. |
| typedef enum [PASTEBOARD_ErrCode](#pasteboard_errcode) [PASTEBOARD_ErrCode](#pasteboard_errcode) | Defines an enum for error codes. |


### Enums

| Name| Description|
| -------- | -------- |
| [Pasteboard_NotifyType](#pasteboard_notifytype) { NOTIFY_LOCAL_DATA_CHANGE = 1, NOTIFY_REMOTE_DATA_CHANGE = 2 } | Enumerates the data change types of the pasteboard. |
| [PASTEBOARD_ErrCode](#pasteboard_errcode) {<br>ERR_OK = 0, ERR_PERMISSION_ERROR = 201, ERR_INVALID_PARAMETER = 401, ERR_DEVICE_NOT_SUPPORTED = 801,<br>ERR_INNER_ERROR = 12900000, ERR_BUSY = 12900003<br>} | Enumerates the error codes. |


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
| ERR_OK  | The operation is successful. ||
| ERR_PERMISSION_ERROR  | Permission verification has failed. ||
| ERR_INVALID_PARAMETER  | Invalid parameter. ||
| ERR_DEVICE_NOT_SUPPORTED  | The device capability is not supported. ||
| ERR_INNER_ERROR  | Internal error. ||
| ERR_BUSY  | System busy. ||


### Pasteboard_NotifyType

```
enum Pasteboard_NotifyType
```
**Description**

Enumerates the data change types of the pasteboard.

**Since**: 13

| Value| Description|
| -------- | -------- |
| NOTIFY_LOCAL_DATA_CHANGE  | The pasteboard data of the local device is changed. ||
| NOTIFY_REMOTE_DATA_CHANGE  | The pasteboard data of a non-local device on the network is changed. ||


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

Returns an error code. For details, see [PASTEBOARD_ErrCode](#pasteboard_errcode). Returns **ERR_OK** if the operation is successful. Returns **ERR_INVALID_PARAMETER** if an invalid parameter is passed in.

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

Returns an error code. For details, see [PASTEBOARD_ErrCode](#pasteboard_errcode). Returns **ERR_OK** if the operation is successful. Returns **ERR_INVALID_PARAMETER** if an invalid parameter is passed in.

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

Returns **true** if there is data in the pasteboard; returns **false** otherwise.

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

Returns **true** if the pasteboard contains data of the specified type; returns **false** otherwise.

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

Returns **true** if the pasteboard data comes from the remote devices; returns **false** otherwise.

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