# oh_pasteboard.h


## Overview

Provides data structure, enum types, and APIs for accessing the system pasteboard.

**Library**: libpasteboard.so

**File to include**: <database/pasteboard/oh_pasteboard.h>

**System capability**: SystemCapability.MiscServices.Pasteboard

**Since**: 13

**Related module**: [Pasteboard](_pasteboard.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [Pasteboard_NotifyType](_pasteboard.md#pasteboard_notifytype) [Pasteboard_NotifyType](_pasteboard.md#pasteboard_notifytype) | Defines an enum for the data change types of the pasteboard. | 
| typedef void(\* [Pasteboard_Notify](_pasteboard.md#pasteboard_notify)) (void \*context, [Pasteboard_NotifyType](_pasteboard.md#pasteboard_notifytype) type) | Defines a callback to be invoked when the pasteboard content changes. | 
| typedef void(\* [Pasteboard_Finalize](_pasteboard.md#pasteboard_finalize)) (void \*context) | Defines a callback to be invoked to release the context when the pasteboard observer object is destroyed. | 
| typedef struct [OH_PasteboardObserver](_pasteboard.md#oh_pasteboardobserver) [OH_PasteboardObserver](_pasteboard.md#oh_pasteboardobserver) | Defines the pasteboard observer. | 
| typedef struct [OH_Pasteboard](_pasteboard.md#oh_pasteboard) [OH_Pasteboard](_pasteboard.md#oh_pasteboard) | Define the pasteboard object to operate the system pasteboard. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [Pasteboard_NotifyType](_pasteboard.md#pasteboard_notifytype) { [NOTIFY_LOCAL_DATA_CHANGE](_pasteboard.md) = 1, [NOTIFY_REMOTE_DATA_CHANGE](_pasteboard.md) = 2 } | Enumerates the data change types of the pasteboard. | 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_PasteboardObserver](_pasteboard.md#oh_pasteboardobserver) \* [OH_PasteboardObserver_Create](_pasteboard.md#oh_pasteboardobserver_create) () | Creates an [OH_PasteboardObserver](_pasteboard.md#oh_pasteboardobserver) instance and a pointer to it. | 
| int [OH_PasteboardObserver_Destroy](_pasteboard.md#oh_pasteboardobserver_destroy) ([OH_PasteboardObserver](_pasteboard.md#oh_pasteboardobserver) \*observer) | Destroys an [OH_PasteboardObserver](_pasteboard.md#oh_pasteboardobserver) instance. | 
| int [OH_PasteboardObserver_SetData](_pasteboard.md#oh_pasteboardobserver_setdata) ([OH_PasteboardObserver](_pasteboard.md#oh_pasteboardobserver) \*observer, void \*context, const [Pasteboard_Notify](_pasteboard.md#pasteboard_notify) callback, const [Pasteboard_Finalize](_pasteboard.md#pasteboard_finalize) finalize) | Sets a callback for the pasteboard observer. | 
| [OH_Pasteboard](_pasteboard.md#oh_pasteboard) \* [OH_Pasteboard_Create](_pasteboard.md#oh_pasteboard_create) () | Creates an [OH_Pasteboard](_pasteboard.md#oh_pasteboard) instance and a pointer to it. | 
| void [OH_Pasteboard_Destroy](_pasteboard.md#oh_pasteboard_destroy) ([OH_Pasteboard](_pasteboard.md#oh_pasteboard) \*pasteboard) | Destroys an [OH_Pasteboard](_pasteboard.md#oh_pasteboard) instance. | 
| int [OH_Pasteboard_Subscribe](_pasteboard.md#oh_pasteboard_subscribe) ([OH_Pasteboard](_pasteboard.md#oh_pasteboard) \*pasteboard, int type, const [OH_PasteboardObserver](_pasteboard.md#oh_pasteboardobserver) \*observer) | Subscribes to the pasteboard observer. | 
| int [OH_Pasteboard_Unsubscribe](_pasteboard.md#oh_pasteboard_unsubscribe) ([OH_Pasteboard](_pasteboard.md#oh_pasteboard) \*pasteboard, int type, const [OH_PasteboardObserver](_pasteboard.md#oh_pasteboardobserver) \*observer) | Unsubscribes from the pasteboard observer. | 
| bool [OH_Pasteboard_IsRemoteData](_pasteboard.md#oh_pasteboard_isremotedata) ([OH_Pasteboard](_pasteboard.md#oh_pasteboard) \*pasteboard) | Checks whether the pasteboard data comes from remote devices. | 
| int [OH_Pasteboard_GetDataSource](_pasteboard.md#oh_pasteboard_getdatasource) ([OH_Pasteboard](_pasteboard.md#oh_pasteboard) \*pasteboard, char \*source, unsigned int len) | Obtains the pasteboard data source. | 
| bool [OH_Pasteboard_HasType](_pasteboard.md#oh_pasteboard_hastype) ([OH_Pasteboard](_pasteboard.md#oh_pasteboard) \*pasteboard, const char \*type) | Checks whether the pasteboard contains data of the specified type. | 
| bool [OH_Pasteboard_HasData](_pasteboard.md#oh_pasteboard_hasdata) ([OH_Pasteboard](_pasteboard.md#oh_pasteboard) \*pasteboard) | Checks whether the pasteboard contains data. | 
| OH_UdmfData \* [OH_Pasteboard_GetData](_pasteboard.md#oh_pasteboard_getdata) ([OH_Pasteboard](_pasteboard.md#oh_pasteboard) \*pasteboard, int \*status) | Obtains data from the pasteboard. | 
| int [OH_Pasteboard_SetData](_pasteboard.md#oh_pasteboard_setdata) ([OH_Pasteboard](_pasteboard.md#oh_pasteboard) \*pasteboard, OH_UdmfData \*data) | Writes the unified data object to the pasteboard. | 
| int [OH_Pasteboard_ClearData](_pasteboard.md#oh_pasteboard_cleardata) ([OH_Pasteboard](_pasteboard.md#oh_pasteboard) \*pasteboard) | Clears data from the pasteboard. | 
| char ** [OH_Pasteboard_GetMimeTypes](_pasteboard.md#oh_pasteboard_getmimetypes) ([OH_Pasteboard](_pasteboard.md#oh_pasteboard) \*pasteboard, unsigned int *count) | Obtains the MIME type from the pasteboard. | 
