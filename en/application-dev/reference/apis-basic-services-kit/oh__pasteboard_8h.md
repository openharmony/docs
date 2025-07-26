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
| typedef struct [OH_PasteboardObserver](_pasteboard.md#oh_pasteboardobserver) [OH_PasteboardObserver](_pasteboard.md#oh_pasteboardobserver) | Defines a struct for the pasteboard observer. |
| typedef struct [OH_Pasteboard](_pasteboard.md#oh_pasteboard) [OH_Pasteboard](_pasteboard.md#oh_pasteboard) | Defines a struct for the pasteboard object to operate the system pasteboard. |
| typedef enum [Pasteboard_FileConflictOptions](_pasteboard.md#pasteboard_fileconflictoptions) [Pasteboard_FileConflictOptions](_pasteboard.md#pasteboard_fileconflictoptions) | Defines an enum for options for file copy conflicts.|
| typedef enum [Pasteboard_ProgressIndicator](_pasteboard.md#pasteboard_progressindicator) [Pasteboard_ProgressIndicator](_pasteboard.md#pasteboard_progressindicator) | Defines an enum for progress indicator display options. You can choose whether to use the default progress indicator.|
| typedef struct [Pasteboard_ProgressInfo](_pasteboard.md#pasteboard_progressinfo) [Pasteboard_ProgressInfo](_pasteboard.md#pasteboard_progressinfo) | Defines a struct for the progress information. This information is reported only when [Pasteboard_ProgressIndicator](#pasteboard_progressindicator) is set to [PASTEBOARD_NONE](_pasteboard.md).|
| typedef void (* [OH_Pasteboard_ProgressListener](_pasteboard.md#oh_pasteboard_progresslistener))([Pasteboard_ProgressInfo](_pasteboard.md#pasteboard_progressinfo)* progressInfo) | Defines a callback function for obtaining the progress information. If the default progress indicator is not used, you can set this type to obtain the paste progress.|
| typedef struct [Pasteboard_GetDataParams](_pasteboard.md#pasteboard_getdataparams) [Pasteboard_GetDataParams](_pasteboard.md#pasteboard_getdataparams) | Defines a struct for the pasteboard parameters required for displaying progress, including progress indicator options, destination path, and file conflict options.|


### Enums

| Name| Description|
| -------- | -------- |
| [Pasteboard_NotifyType](_pasteboard.md#pasteboard_notifytype) { [NOTIFY_LOCAL_DATA_CHANGE] = 1, [NOTIFY_REMOTE_DATA_CHANGE] = 2 } | Enumerates the data change types of the pasteboard. |
| [Pasteboard_FileConflictOptions](_pasteboard.md#pasteboard_fileconflictoptions) { [PASTEBOARD_OVERWRITE] = 0, [PASTEBOARD_SKIP] = 1 } | Enumerates options for a file copy conflict.|
| [Pasteboard_ProgressIndicator](_pasteboard.md#pasteboard_progressindicator) { [PASTEBOARD_NONE] = 0, [PASTEBOARD_DEFAULT] = 1 } | Enumerates progress indicator types.|


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
| [Pasteboard_GetDataParams](_pasteboard.md#pasteboard_getdataparams) *[OH_Pasteboard_GetDataParams_Create](_pasteboard.md#oh_pasteboard_getdataparams_create)(void) | Creates a [Pasteboard_GetDataParams](_pasteboard.md#pasteboard_getdataparams) instance and a pointer to it.|
| void [OH_Pasteboard_GetDataParams_Destroy](_pasteboard.md#oh_pasteboard_getdataparams_destroy)([Pasteboard_GetDataParams](_pasteboard.md#pasteboard_getdataparams)* params) | Destroys a [Pasteboard_GetDataParams](_pasteboard.md#pasteboard_getdataparams) instance.|
| void [OH_Pasteboard_GetDataParams_SetProgressIndicator](_pasteboard.md#oh_pasteboard_getdataparams_setprogressindicator)([Pasteboard_GetDataParams](_pasteboard.md#pasteboard_getdataparams)* params, [Pasteboard_ProgressIndicator](_pasteboard.md#pasteboard_progressindicator) progressIndicator) | Sets the progress indication options in [Pasteboard_GetDataParams](_pasteboard.md#pasteboard_getdataparams). You can use the default progress indicator as required.|
| void [OH_Pasteboard_GetDataParams_SetDestUri](_pasteboard.md#oh_pasteboard_getdataparams_setdesturi)([Pasteboard_GetDataParams](_pasteboard.md#pasteboard_getdataparams)* params, const char* destUri, uint32_t destUriLen) | Sets the destination path in [Pasteboard_GetDataParams](_pasteboard.md#pasteboard_getdataparams).|
| void [OH_Pasteboard_GetDataParams_SetFileConflictOptions](_pasteboard.md#oh_pasteboard_getdataparams_setfileconflictoptions)([Pasteboard_GetDataParams](_pasteboard.md#pasteboard_getdataparams)* params, [Pasteboard_FileConflictOptions](_pasteboard.md#pasteboard_fileconflictoptions) option) | Sets the file copy conflict options in [Pasteboard_GetDataParams](_pasteboard.md#pasteboard_getdataparams).|
| void [OH_Pasteboard_GetDataParams_SetProgressListener](_pasteboard.md#oh_pasteboard_getdataparams_setprogresslistener)([Pasteboard_GetDataParams](_pasteboard.md#pasteboard_getdataparams)* params, const [OH_Pasteboard_ProgressListener](_pasteboard.md#oh_pasteboard_progresslistener) listener) | Sets a progress listener in [Pasteboard_GetDataParams](_pasteboard.md#pasteboard_getdataparams).|
| int [OH_Pasteboard_ProgressInfo_GetProgress](_pasteboard.md#oh_pasteboard_progressinfo_getprogress)([Pasteboard_ProgressInfo](_pasteboard.md#pasteboard_progressinfo)* progressInfo) | Obtains the pasting progress using [Pasteboard_ProgressInfo](_pasteboard.md#pasteboard_progressinfo).|
| void [OH_Pasteboard_ProgressCancel](_pasteboard.md#oh_pasteboard_progresscancel)([Pasteboard_GetDataParams](_pasteboard.md#pasteboard_getdataparams)* params) | Cancels an ongoing copy and paste task using [Pasteboard_GetDataParams](_pasteboard.md#pasteboard_getdataparams).|
| OH_UdmfData* [OH_Pasteboard_GetDataWithProgress](_pasteboard.md#oh_pasteboard_getdatawithprogress)([OH_Pasteboard](_pasteboard.md#oh_pasteboard)* pasteboard, [Pasteboard_GetDataParams](_pasteboard.md#pasteboard_getdataparams)* params, int* status) | Obtains the pasteboard data and pasting progress. Folders cannot be copied.|
| int32_t [OH_Pasteboard_GetChangeCount](_pasteboard.md#oh_pasteboard_getchangecount) ([OH_Pasteboard](_pasteboard.md#oh_pasteboard) \*pasteboard) | Obtains the number of times that the pasteboard data changes. |
