# oh_pasteboard.h


## 概述

提供访问系统剪贴板的接口、数据结构、枚举类型。 

**库：** libpasteboard.so

**引用文件：** <database/pasteboard/oh_pasteboard.h>

**系统能力：** SystemCapability.MiscServices.Pasteboard

**起始版本：** 13

**相关模块：**[Pasteboard](_pasteboard.md)


## 汇总


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| typedef enum [Pasteboard_NotifyType](_pasteboard.md#pasteboard_notifytype) [Pasteboard_NotifyType](_pasteboard.md#pasteboard_notifytype) | 剪贴板的数据变更类型。  |
| typedef void(\* [Pasteboard_Notify](_pasteboard.md#pasteboard_notify)) (void \*context, [Pasteboard_NotifyType](_pasteboard.md#pasteboard_notifytype) type) | 定义剪贴板内容变更时触发的回调函数。  |
| typedef void(\* [Pasteboard_Finalize](_pasteboard.md#pasteboard_finalize)) (void \*context) | 定义用于释放上下文的回调函数，剪贴板数据变更观察者对象销毁时触发。  |
| typedef struct [OH_PasteboardObserver](_pasteboard.md#oh_pasteboardobserver) [OH_PasteboardObserver](_pasteboard.md#oh_pasteboardobserver) | 定义剪贴板数据变更观察者。  |
| typedef struct [OH_Pasteboard](_pasteboard.md#oh_pasteboard) [OH_Pasteboard](_pasteboard.md#oh_pasteboard) | 定义剪贴板对象，用以操作系统剪贴板。  |
| typedef enum [Pasteboard_FileConflictOption](_pasteboard.md#pasteboard_fileconflictoption) [Pasteboard_FileConflictOption](_pasteboard.md#pasteboard_fileconflictoption) | 定义文件拷贝冲突时的选项。 |
| typedef enum [Pasteboard_ProgressIndicator](_pasteboard.md#pasteboard_progressindicator) [Pasteboard_ProgressIndicator](_pasteboard.md#pasteboard_progressindicator) | 定义进度条指示选项，可选择是否采用系统默认进度显示。 |
| typedef struct [Pasteboard_ProgressInfo](_pasteboard.md#pasteboard_progressinfo) [Pasteboard_ProgressInfo](_pasteboard.md#pasteboard_progressinfo) | 定义进度上报的数据结构，且仅当进度指示选项[ProgressIndicator](_pasteboard.md#pasteboard_progressindicator)设置为NONE时才会上报此信息。 |
| typedef struct [Pasteboard_ProgressListener](_pasteboard.md#pasteboard_progresslistener) [Pasteboard_ProgressListener](_pasteboard.md#pasteboard_progresslistener) | 定义进度数据变化的订阅函数，当选择不使用系统默认进度显示时，可设置该项获取粘贴过程的进度。 |
| typedef struct [pasteboard_progresssignal](_pasteboard.md#pasteboard_progresssignal) [Pasteboard_ProgressSignal](_pasteboard.md#pasteboard_progresssignal) | 定义进度取消的函数，在粘贴过程中可选择取消任务，且仅当进度指示选项[ProgressIndicator](_pasteboard.md#pasteboard_progressindicator)设置为NONE时此参数才有意义。 |
| typedef struct [OH_Pasteboard_GetDataParams](_pasteboard.md#oh_pasteboard_getdataparams) [OH_Pasteboard_GetDataParams](_pasteboard.md#oh_pasteboard_getdataparams) | 剪贴板中获取数据时需要的参数，包含目标路径、文件冲突选项、进度条指示选项等。 |
| typedef void(* [Pasteboard_ProgressNotify](_pasteboard.md#pasteboard_progressnotify))([Pasteboard_ProgressInfo](_pasteboard.md#pasteboard_progressinfo) progressInfo); | 定义获取进度数据的回调函数，当选择不使用系统默认进度显示时，可设置该项获取粘贴过程的进度。 |
| typedef int (* [Pasteboard_ProgressCancel](_pasteboard.md#pasteboard_progresscancel))(); | 取消正在进行的粘贴动作。 |


### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [Pasteboard_NotifyType](_pasteboard.md#pasteboard_notifytype) { [NOTIFY_LOCAL_DATA_CHANGE](_pasteboard.md) = 1, [NOTIFY_REMOTE_DATA_CHANGE](_pasteboard.md) = 2 } | 剪贴板的数据变更类型。  |
| [Pasteboard_FileConflictOption](_pasteboard.md#pasteboard_fileconflictoption) { [OVERWRITE](_pasteboard.md) = 0, [SKIP](_pasteboard.md) = 1 } | 拷贝文件文件冲突时的选项。 |
| [Pasteboard_ProgressIndicator](_pasteboard.md#pasteboard_progressindicator) { [NONE](_pasteboard.md) = 0, [DEFAULT](_pasteboard.md) = 1 } | 从剪贴板获取数据时的进度条类型。 |


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_PasteboardObserver](_pasteboard.md#oh_pasteboardobserver) \* [OH_PasteboardObserver_Create](_pasteboard.md#oh_pasteboardobserver_create) () | 创建一个剪贴板数据变更观察者[OH_PasteboardObserver](_pasteboard.md#oh_pasteboardobserver)指针及实例对象。  |
| int [OH_PasteboardObserver_Destroy](_pasteboard.md#oh_pasteboardobserver_destroy) ([OH_PasteboardObserver](_pasteboard.md#oh_pasteboardobserver) \*observer) | 销毁剪贴板数据变更观察者[OH_PasteboardObserver](_pasteboard.md#oh_pasteboardobserver)指针指向的实例对象。  |
| int [OH_PasteboardObserver_SetData](_pasteboard.md#oh_pasteboardobserver_setdata) ([OH_PasteboardObserver](_pasteboard.md#oh_pasteboardobserver) \*observer, void \*context, const [Pasteboard_Notify](_pasteboard.md#pasteboard_notify) callback, const [Pasteboard_Finalize](_pasteboard.md#pasteboard_finalize) finalize) | 向剪贴板数据变更观察者设置回调函数。  |
| [OH_Pasteboard](_pasteboard.md#oh_pasteboard) \* [OH_Pasteboard_Create](_pasteboard.md#oh_pasteboard_create) () | 创建剪贴板[OH_Pasteboard](_pasteboard.md#oh_pasteboard)指针及实例对象。  |
| void [OH_Pasteboard_Destroy](_pasteboard.md#oh_pasteboard_destroy) ([OH_Pasteboard](_pasteboard.md#oh_pasteboard) \*pasteboard) | 销毁剪贴板[OH_Pasteboard](_pasteboard.md#oh_pasteboard)实例对象。  |
| int [OH_Pasteboard_Subscribe](_pasteboard.md#oh_pasteboard_subscribe) ([OH_Pasteboard](_pasteboard.md#oh_pasteboard) \*pasteboard, int type, const [OH_PasteboardObserver](_pasteboard.md#oh_pasteboardobserver) \*observer) | 订阅剪贴板的数据变更事件。  |
| int [OH_Pasteboard_Unsubscribe](_pasteboard.md#oh_pasteboard_unsubscribe) ([OH_Pasteboard](_pasteboard.md#oh_pasteboard) \*pasteboard, int type, const [OH_PasteboardObserver](_pasteboard.md#oh_pasteboardobserver) \*observer) | 取消对剪贴板数据变更事件的订阅。  |
| bool [OH_Pasteboard_IsRemoteData](_pasteboard.md#oh_pasteboard_isremotedata) ([OH_Pasteboard](_pasteboard.md#oh_pasteboard) \*pasteboard) | 判断剪贴板中的数据是否来自远端设备。  |
| int [OH_Pasteboard_GetDataSource](_pasteboard.md#oh_pasteboard_getdatasource) ([OH_Pasteboard](_pasteboard.md#oh_pasteboard) \*pasteboard, char \*source, unsigned int len) | 获取剪贴板中数据的数据源。  |
| bool [OH_Pasteboard_HasType](_pasteboard.md#oh_pasteboard_hastype) ([OH_Pasteboard](_pasteboard.md#oh_pasteboard) \*pasteboard, const char \*type) | 判断剪贴板中是否有指定类型的数据。  |
| bool [OH_Pasteboard_HasData](_pasteboard.md#oh_pasteboard_hasdata) ([OH_Pasteboard](_pasteboard.md#oh_pasteboard) \*pasteboard) | 判断剪贴板中是否有数据。  |
| OH_UdmfData \* [OH_Pasteboard_GetData](_pasteboard.md#oh_pasteboard_getdata) ([OH_Pasteboard](_pasteboard.md#oh_pasteboard) \*pasteboard, int \*status) | 获取剪贴板中的数据。  |
| int [OH_Pasteboard_SetData](_pasteboard.md#oh_pasteboard_setdata) ([OH_Pasteboard](_pasteboard.md#oh_pasteboard) \*pasteboard, OH_UdmfData \*data) | 将统一数据对象数据写入剪贴板。  |
| int [OH_Pasteboard_ClearData](_pasteboard.md#oh_pasteboard_cleardata) ([OH_Pasteboard](_pasteboard.md#oh_pasteboard) \*pasteboard) | 清空剪贴板中的数据。  |
| char ** [OH_Pasteboard_GetMimeTypes](_pasteboard.md#oh_pasteboard_getmimetypes) ([OH_Pasteboard](_pasteboard.md#oh_pasteboard) \*pasteboard, unsigned int *count) | 获取剪切板中的MIME类型。  |
| OH_UdmfData *[OH_Pasteboard_GetDataWithProgress](_pasteboard.md#oh_pasteboard_getdatawithprogress)([OH_Pasteboard](_pasteboard.md#oh_pasteboard) *pasteboard, [OH_Pasteboard_GetDataParams](_pasteboard.md#oh_pasteboard_getdataparams) *params, int *status) | 获取剪贴板的数据以及粘贴进度。 |

