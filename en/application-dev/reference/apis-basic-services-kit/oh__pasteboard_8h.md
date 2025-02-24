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
| typedef enum [Pasteboard_FileConflictOption](_pasteboard.md#pasteboard_fileconflictoption) [Pasteboard_FileConflictOption](_pasteboard.md#pasteboard_fileconflictoption) | Defines an enum for options for file copy conflicts.|
| typedef enum [Pasteboard_ProgressIndicator](_pasteboard.md#pasteboard_progressindicator) [Pasteboard_ProgressIndicator](_pasteboard.md#pasteboard_progressindicator) | Defines an enum for progress indicator display options. You can choose whether to use the default progress indicator.|
| typedef struct [Pasteboard_ProgressInfo](_pasteboard.md#pasteboard_progressinfo) [Pasteboard_ProgressInfo](_pasteboard.md#pasteboard_progressinfo) | Defines a struct for the progress information. This information is reported only when [ProgressIndicator](_pasteboard.md#pasteboard_progressindicator) is set to **NONE**.|
| typedef struct [Pasteboard_ProgressListener](_pasteboard.md#pasteboard_progresslistener) [Pasteboard_ProgressListener](_pasteboard.md#pasteboard_progresslistener) | Defines a listener for progress data changes. If the default progress indicator is not used, you can set this type to obtain the paste progress.|
| typedef struct [pasteboard_progresssignal](_pasteboard.md#pasteboard_progresssignal) [Pasteboard_ProgressSignal](_pasteboard.md#pasteboard_progresssignal) | Defines a function for canceling the paste task. This parameter is valid only when [ProgressIndicator](_pasteboard.md#pasteboard_progressindicator) is set to **NONE**.|
| typedef struct [OH_Pasteboard_GetDataParams](_pasteboard.md#oh_pasteboard_getdataparams) [OH_Pasteboard_GetDataParams](_pasteboard.md#oh_pasteboard_getdataparams) | Defines a struct for the parameters required for obtaining data in the pasteboard, including the destination path, file conflict options, and progress indicator options.|
| typedef void(* [Pasteboard_ProgressNotify](_pasteboard.md#pasteboard_progressnotify))([Pasteboard_ProgressInfo](_pasteboard.md#pasteboard_progressinfo) progressInfo); | Defines a callback function for obtaining the progress information. If the default progress indicator is not used, you can set this type to obtain the paste progress.|
| typedef int (* [Pasteboard_ProgressCancel](_pasteboard.md#pasteboard_progresscancel))(); | Defines a function for canceling the ongoing paste operation.|


### Enums

| Name| Description|
| -------- | -------- |
| [Pasteboard_NotifyType](_pasteboard.md#pasteboard_notifytype) { [NOTIFY_LOCAL_DATA_CHANGE](_pasteboard.md) = 1, [NOTIFY_REMOTE_DATA_CHANGE](_pasteboard.md) = 2 } | Enumerates the data change types of the pasteboard. |
| [Pasteboard_FileConflictOption](_pasteboard.md#pasteboard_fileconflictoption) { [OVERWRITE](_pasteboard.md) = 0, [SKIP](_pasteboard.md) = 1 } | Enumerates options for a file copy conflict.|
| [Pasteboard_ProgressIndicator](_pasteboard.md#pasteboard_progressindicator) { [NONE](_pasteboard.md) = 0, [DEFAULT](_pasteboard.md) = 1 } | Enumerates progress indicator types.|


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
| OH_UdmfData *[OH_Pasteboard_GetDataWithProgress](_pasteboard.md#oh_pasteboard_getdatawithprogress)([OH_Pasteboard](_pasteboard.md#oh_pasteboard) *pasteboard, [OH_Pasteboard_GetDataParams](_pasteboard.md#oh_pasteboard_getdataparams) *params, int *status) | Obtains the pasteboard data and paste progress.|
