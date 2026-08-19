# oh_pasteboard.h
<!--Kit: Basic Services Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @yangxiaodong41-->
<!--Designer: @zhusiyuan2-->
<!--Tester: @maxiaorong-->
<!--Adviser: @fang-jinxu-->

## 概述

提供访问系统剪贴板的接口、数据结构、枚举类型。支持剪贴板数据的读写、监听剪贴板内容变化、获取粘贴进度等功能。

**引用文件：** <database/pasteboard/oh_pasteboard.h>

**库：** libpasteboard.so

**系统能力：** SystemCapability.MiscServices.Pasteboard

**起始版本：** 13

**相关模块：** [Pasteboard](capi-pasteboard.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [Pasteboard_ProgressInfo](capi-pasteboard-progressinfo.md) | Pasteboard_ProgressInfo | 定义进度上报的数据结构。 |
| [Pasteboard_GetDataParams](capi-pasteboard-getdataparams.md) | Pasteboard_GetDataParams | 表示从剪贴板获取粘贴数据和进度时需要提供的参数。 |
| [OH_PasteboardObserver](capi-pasteboard-oh-pasteboardobserver.md) | OH_PasteboardObserver | 定义剪贴板数据变更观察者。用于监听系统剪贴板数据的变化事件，当剪贴板内容发生更新时，通过回调通知应用。典型使用场景：需要响应剪贴板内容变化的应用。 |
| [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md) | OH_Pasteboard | 定义剪贴板对象，用以操作系统剪贴板。 |

### 宏定义

| 名称  | 描述   |
|--------------|-----------|
| [PASTEBOARD_MIMETYPE_TEXT_PLAIN](#pasteboard_mimetype_text_plain)  "text/plain" | 纯文本类型。 |
| [PASTEBOARD_MIMETYPE_TEXT_URI](#pasteboard_mimetype_text_uri)  "text/uri" | URI类型。 |
| [PASTEBOARD_MIMETYPE_TEXT_HTML](#pasteboard_mimetype_text_html)  "text/html" | HTML类型。 |
| [PASTEBOARD_MIMETYPE_PIXELMAP](#pasteboard_mimetype_pixelmap)  "pixelMap" | pixelMap类型。 |
| [PASTEBOARD_MIMETYPE_TEXT_WANT](#pasteboard_mimetype_text_want)  "text/want" | want类型。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [Pasteboard_NotifyType](#pasteboard_notifytype) | Pasteboard_NotifyType | 剪贴板的数据变更类型。 |
| [Pasteboard_FileConflictOptions](#pasteboard_fileconflictoptions) | Pasteboard_FileConflictOptions | 定义文件拷贝冲突时的选项。 |
| [Pasteboard_ProgressIndicator](#pasteboard_progressindicator) | Pasteboard_ProgressIndicator | 定义进度条指示选项，可选择是否采用系统默认进度显示。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef void (\*OH_Pasteboard_ProgressListener)(Pasteboard_ProgressInfo* progressInfo)](#oh_pasteboard_progresslistener) | OH_Pasteboard_ProgressListener | 用于在不使用系统默认进度显示时，通知应用拷贝粘贴任务进度。 |
| [typedef void (\*Pasteboard_Notify)(void* context, Pasteboard_NotifyType type)](#pasteboard_notify) | Pasteboard_Notify | 定义剪贴板内容变更时触发的回调函数。 |
| [typedef void (\*Pasteboard_Finalize)(void* context)](#pasteboard_finalize) | Pasteboard_Finalize | 定义用于释放上下文的回调函数，剪贴板数据变更观察者对象销毁时触发。 |
| [OH_PasteboardObserver* OH_PasteboardObserver_Create()](#oh_pasteboardobserver_create) | - | 创建一个剪贴板数据变更观察者[OH_PasteboardObserver](capi-pasteboard-oh-pasteboardobserver.md)指针及实例对象。 |
| [int OH_PasteboardObserver_Destroy(OH_PasteboardObserver* observer)](#oh_pasteboardobserver_destroy) | - | 销毁剪贴板数据变更观察者[OH_PasteboardObserver](capi-pasteboard-oh-pasteboardobserver.md)指针指向的实例对象。 |
| [int OH_PasteboardObserver_SetData(OH_PasteboardObserver* observer, void* context,const Pasteboard_Notify callback, const Pasteboard_Finalize finalize)](#oh_pasteboardobserver_setdata) | - | 向剪贴板数据变更观察者设置回调函数。 |
| [OH_Pasteboard* OH_Pasteboard_Create()](#oh_pasteboard_create) | - | 创建剪贴板[OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)指针及实例对象。 |
| [void OH_Pasteboard_Destroy(OH_Pasteboard* pasteboard)](#oh_pasteboard_destroy) | - | 销毁剪贴板[OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)实例对象。 |
| [int OH_Pasteboard_Subscribe(OH_Pasteboard* pasteboard, int type, const OH_PasteboardObserver* observer)](#oh_pasteboard_subscribe) | - | 订阅剪贴板的数据变更事件。 |
| [int OH_Pasteboard_Unsubscribe(OH_Pasteboard* pasteboard, int type, const OH_PasteboardObserver* observer)](#oh_pasteboard_unsubscribe) | - | 取消对剪贴板数据变更事件的订阅。 |
| [bool OH_Pasteboard_IsRemoteData(OH_Pasteboard* pasteboard)](#oh_pasteboard_isremotedata) | - | 判断剪贴板中的数据是否来自远端设备。 |
| [int OH_Pasteboard_GetDataSource(OH_Pasteboard* pasteboard, char* source, unsigned int len)](#oh_pasteboard_getdatasource) | - | 获取剪贴板中数据的数据源。 |
| [bool OH_Pasteboard_HasType(OH_Pasteboard* pasteboard, const char* type)](#oh_pasteboard_hastype) | - | 判断剪贴板中是否有指定类型的数据。 |
| [bool OH_Pasteboard_HasData(OH_Pasteboard* pasteboard)](#oh_pasteboard_hasdata) | - | 判断剪贴板中是否有数据。 |
| [OH_UdmfData* OH_Pasteboard_GetData(OH_Pasteboard* pasteboard, int* status)](#oh_pasteboard_getdata) | - | 获取剪贴板中的数据。 |
| [int OH_Pasteboard_SetData(OH_Pasteboard* pasteboard, OH_UdmfData* data)](#oh_pasteboard_setdata) | - | 将统一数据对象数据写入剪贴板。 |
| [int OH_Pasteboard_ClearData(OH_Pasteboard* pasteboard)](#oh_pasteboard_cleardata) | - | 清空剪贴板中的数据。 |
| [char **OH_Pasteboard_GetMimeTypes(OH_Pasteboard *pasteboard, unsigned int *count)](#oh_pasteboard_getmimetypes) | - | 获取剪贴板中的MIME类型。 |
| [Pasteboard_GetDataParams *OH_Pasteboard_GetDataParams_Create(void)](#oh_pasteboard_getdataparams_create) | - | 创建剪贴板[Pasteboard_GetDataParams](capi-pasteboard-getdataparams.md)指针及实例对象。 |
| [void OH_Pasteboard_GetDataParams_Destroy(Pasteboard_GetDataParams* params)](#oh_pasteboard_getdataparams_destroy) | - | 销毁剪贴板[Pasteboard_GetDataParams](capi-pasteboard-getdataparams.md)指针指向的实例对象。 |
| [void OH_Pasteboard_GetDataParams_SetProgressIndicator(Pasteboard_GetDataParams* params,Pasteboard_ProgressIndicator progressIndicator)](#oh_pasteboard_getdataparams_setprogressindicator) | - | 向剪贴板[Pasteboard_GetDataParams](capi-pasteboard-getdataparams.md)设置进度条指示选项，可选择是否采用系统默认进度显示。 |
| [void OH_Pasteboard_GetDataParams_SetDestUri(Pasteboard_GetDataParams* params, const char* destUri, uint32_t destUriLen)](#oh_pasteboard_getdataparams_setdesturi) | - | 向剪贴板[Pasteboard_GetDataParams](capi-pasteboard-getdataparams.md)设置拷贝文件时目标路径。若不支持文件处理，则不需要设置此参数；若应用涉及复杂文件处理策略或需要区分文件多路径存储，建议不设置此参数，由应用自行完成文件复制处理。 |
| [void OH_Pasteboard_GetDataParams_SetFileConflictOptions(Pasteboard_GetDataParams* params,Pasteboard_FileConflictOptions option)](#oh_pasteboard_getdataparams_setfileconflictoptions) | - | 向剪贴板[Pasteboard_GetDataParams](capi-pasteboard-getdataparams.md)设置文件冲突选项。 |
| [void OH_Pasteboard_GetDataParams_SetProgressListener(Pasteboard_GetDataParams* params,const OH_Pasteboard_ProgressListener listener)](#oh_pasteboard_getdataparams_setprogresslistener) | - | 向剪贴板[Pasteboard_GetDataParams](capi-pasteboard-getdataparams.md)设置进度上报回调函数。 |
| [int OH_Pasteboard_ProgressInfo_GetProgress(Pasteboard_ProgressInfo* progressInfo)](#oh_pasteboard_progressinfo_getprogress) | - | 从[Pasteboard_ProgressInfo](capi-pasteboard-progressinfo.md)获取粘贴进度。 |
| [void OH_Pasteboard_ProgressCancel(Pasteboard_GetDataParams* params)](#oh_pasteboard_progresscancel) | - | 定义取消函数，用于在获取粘贴数据时取消正在进行的粘贴动作。 |
| [OH_UdmfData* OH_Pasteboard_GetDataWithProgress(OH_Pasteboard* pasteboard, Pasteboard_GetDataParams* params,int* status)](#oh_pasteboard_getdatawithprogress) | - | 获取剪贴板的数据以及粘贴进度，不支持对文件夹的拷贝。 |
| [uint32_t OH_Pasteboard_GetChangeCount(OH_Pasteboard *pasteboard)](#oh_pasteboard_getchangecount) | - | 获取剪贴板内容的变化次数。 |
| [void OH_Pasteboard_SyncDelayedDataAsync(OH_Pasteboard* pasteboard, void (*callback)(int errorCode))](#oh_pasteboard_syncdelayeddataasync) | - | 通知剪贴板从应用同步所有延迟数据，与延迟复制接口[OH_UdmfRecordProvider_SetData](../apis-arkdata/capi-udmf-h.md#oh_udmfrecordprovider_setdata)搭配使用。当应用使用延迟复制功能复制时，仅将应用支持的数据类型写入剪贴板。应用应在退出时，重新调用[OH_Pasteboard_SetData](#oh_pasteboard_setdata)接口主动提交所有复制数据或调用此接口通知剪贴板获取全量数据，等待数据同步完成再继续退出，否则可能导致其他应用粘贴获取不到数据。 |
| [bool OH_Pasteboard_HasRemoteData(OH_Pasteboard* pasteboard)](#oh_pasteboard_hasremotedata) | - | 判断当前待粘贴的剪贴板数据是否在远端设备上。 |

## 宏定义说明

### PASTEBOARD_MIMETYPE_TEXT_PLAIN

```c
#define PASTEBOARD_MIMETYPE_TEXT_PLAIN "text/plain"
```

**描述**

纯文本类型。

**起始版本：** 22

### PASTEBOARD_MIMETYPE_TEXT_URI

```c
#define PASTEBOARD_MIMETYPE_TEXT_URI "text/uri"
```

**描述**

URI类型。

**起始版本：** 22

### PASTEBOARD_MIMETYPE_TEXT_HTML

```c
#define PASTEBOARD_MIMETYPE_TEXT_HTML "text/html"
```

**描述**

HTML类型。

**起始版本：** 22

### PASTEBOARD_MIMETYPE_PIXELMAP

```c
#define PASTEBOARD_MIMETYPE_PIXELMAP "pixelMap"
```

**描述**

pixelMap类型。

**起始版本：** 22

### PASTEBOARD_MIMETYPE_TEXT_WANT

```c
#define PASTEBOARD_MIMETYPE_TEXT_WANT "text/want"
```

**描述**

want类型。

**起始版本：** 22

## 枚举类型说明

### Pasteboard_NotifyType

```c
enum Pasteboard_NotifyType
```

**描述：**

剪贴板的数据变更类型。

**使用场景**：用于区分剪贴板数据变更的来源，判断是本地设备还是远端设备的数据变更。

**起始版本：** 13

| 枚举项 | 描述 |
| -- | -- |
| NOTIFY_LOCAL_DATA_CHANGE = 1 | 本地设备剪贴板数据变更。 |
| NOTIFY_REMOTE_DATA_CHANGE = 2 | 组网内的非本地设备剪贴板数据变更。 |

### Pasteboard_FileConflictOptions

```c
enum Pasteboard_FileConflictOptions
```

**描述：**

定义文件拷贝冲突时的选项。

**使用场景**：在获取剪贴板数据并拷贝文件时，目标路径已存在同名文件，需指定冲突处理策略。

**起始版本：** 15

| 枚举项 | 描述 |
| -- | -- |
| PASTEBOARD_OVERWRITE = 0 | 目标路径存在同文件名时覆盖。 |
| PASTEBOARD_SKIP = 1 | 目标路径存在同文件名时跳过。 |

### Pasteboard_ProgressIndicator

```c
enum Pasteboard_ProgressIndicator
```

**描述：**

定义进度条指示选项，可选择是否采用系统默认进度显示。

**使用场景**：在获取剪贴板数据并拷贝文件时，控制是否显示进度提示。

**起始版本：** 15

| 枚举项 | 描述 |
| -- | -- |
| PASTEBOARD_NONE = 0 | 不采用系统默认进度显示。 |
| PASTEBOARD_DEFAULT = 1 | 采用系统默认进度显示。 |

## 函数说明

### OH_Pasteboard_ProgressListener()

```c
typedef void (*OH_Pasteboard_ProgressListener)(Pasteboard_ProgressInfo* progressInfo)
```

**描述：**

用于在不使用系统默认进度显示时，通知应用拷贝粘贴任务进度。

**使用场景**：当需要自定义进度显示UI时，设置此回调函数来获取进度信息。

**起始版本：** 15

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Pasteboard_ProgressInfo](capi-pasteboard-progressinfo.md)* progressInfo | 定义进度上报的数据结构，且仅当进度指示选项[Pasteboard_ProgressIndicator](#pasteboard_progressindicator)设置为PASTEBOARD_NONE时才会上报此信息。 |

### Pasteboard_Notify()

```c
typedef void (*Pasteboard_Notify)(void* context, Pasteboard_NotifyType type)
```

**描述：**

定义剪贴板内容变更时触发的回调函数。

**使用场景**：需要在剪贴板数据变更时执行特定逻辑时实现此回调函数。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| void* context | 上下文信息，由函数[OH_PasteboardObserver_SetData](capi-oh-pasteboard-h.md#oh_pasteboardobserver_setdata)传入。 |
| [Pasteboard_NotifyType](capi-oh-pasteboard-h.md#pasteboard_notifytype) type | 数据变更的类型。详见：[Pasteboard_NotifyType](capi-oh-pasteboard-h.md#pasteboard_notifytype)。 |

### Pasteboard_Finalize()

```c
typedef void (*Pasteboard_Finalize)(void* context)
```

**描述：**

定义用于释放上下文的回调函数，剪贴板数据变更观察者对象销毁时触发。

**使用场景**：当在Pasteboard_Notify回调中使用了动态分配的上下文数据时，需要实现此回调来释放资源。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| void* context | 要释放的上下文指针。当context指向需要手动释放的动态内存或资源时，应在回调函数中释放；当context指向静态内存或无需管理的资源时，回调函数可以不做处理。 |

### OH_PasteboardObserver_Create()

```c
OH_PasteboardObserver* OH_PasteboardObserver_Create()
```

**描述：**

创建一个剪贴板数据变更观察者[OH_PasteboardObserver](capi-pasteboard-oh-pasteboardobserver.md)指针及实例对象。典型使用场景包括：监听剪贴板内容变化以实现数据同步、在剪贴板内容更新时触发业务逻辑等。调用此函数后，系统会初始化一个剪贴板数据变更观察者对象，返回指向该对象的指针。创建成功后，开发者需要通过[OH_PasteboardObserver_SetData](#oh_pasteboardobserver_setdata)设置回调函数，然后通过[OH_Pasteboard_Subscribe](#oh_pasteboard_subscribe)订阅剪贴板变更事件。

**约束和限制：**

- 调用者应在不需要监听剪贴板数据变更时调用[OH_PasteboardObserver_Destroy](#oh_pasteboardobserver_destroy)释放资源，否则会导致内存泄漏。
- 观察者对象不支持多线程并发访问，需要在同一线程中创建和销毁。

**起始版本：** 13

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_PasteboardObserver](capi-pasteboard-oh-pasteboardobserver.md)* | 执行成功时返回一个指向剪贴板数据变更观察者[OH_PasteboardObserver](capi-pasteboard-oh-pasteboardobserver.md)实例对象的指针，否则返回空指针。<br> 当不再需要使用指针时，请使用[OH_PasteboardObserver_Destroy](capi-oh-pasteboard-h.md#oh_pasteboardobserver_destroy)销毁实例对象，否则会导致内存泄漏。 |

### OH_PasteboardObserver_Destroy()

```c
int OH_PasteboardObserver_Destroy(OH_PasteboardObserver* observer)
```

**描述：**

销毁剪贴板数据变更观察者[OH_PasteboardObserver](capi-pasteboard-oh-pasteboardobserver.md)指针指向的实例对象。

**使用场景**：不再需要监听剪贴板数据变更时，应先取消订阅，再销毁观察者对象。

**开发建议**：销毁前请确保已调用[OH_Pasteboard_Unsubscribe](#oh_pasteboard_unsubscribe)取消订阅。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PasteboardObserver](capi-pasteboard-oh-pasteboardobserver.md)* observer | 表示指向剪贴板数据变更观察者[OH_PasteboardObserver](capi-pasteboard-oh-pasteboardobserver.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。详见[PASTEBOARD_ErrCode](capi-oh-pasteboard-err-code-h.md#pasteboard_errcode)。 |

**错误码说明:**

- **ERR_OK**: 执行成功
- **ERR_INVALID_PARAMETER**: 参数无效

### OH_PasteboardObserver_SetData()

```c
int OH_PasteboardObserver_SetData(OH_PasteboardObserver* observer, void* context, const Pasteboard_Notify callback, const Pasteboard_Finalize finalize)
```

**描述：**

向剪贴板数据变更观察者设置回调函数。当应用需要在剪贴板数据发生变化时执行特定操作（如更新UI显示、同步数据到其他模块）时，通过此接口设置回调函数。设置完成后，当剪贴板发生对应类型的数据变更时将触发回调。回调通常在系统线程中执行，需注意线程安全。回调函数的生命周期应不短于观察者的生命周期。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PasteboardObserver](capi-pasteboard-oh-pasteboardobserver.md)* observer | 表示指向剪贴板数据变更观察者[OH_PasteboardObserver](capi-pasteboard-oh-pasteboardobserver.md)实例的指针。 |
| void* context | 表示指向上下文数据的指针，将作为第一个参数传入[Pasteboard_Notify](capi-oh-pasteboard-h.md#pasteboard_notify)。 |
| const [Pasteboard_Notify](capi-oh-pasteboard-h.md#pasteboard_notify) callback | 表示数据变更回调函数，在剪贴板数据变更时触发。详见[Pasteboard_Notify](capi-oh-pasteboard-h.md#pasteboard_notify)。 |
| const [Pasteboard_Finalize](capi-oh-pasteboard-h.md#pasteboard_finalize) finalize | 表示可选的回调函数，可以用于剪贴板数据变更观察者销毁时释放上下文数据。默认为nullptr，不执行释放操作。详见[Pasteboard_Finalize](capi-oh-pasteboard-h.md#pasteboard_finalize)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。错误码定义详见[PASTEBOARD_ErrCode](capi-oh-pasteboard-err-code-h.md#pasteboard_errcode)。<br> 若返回ERR_OK，表示执行成功。<br> 若返回ERR_INVALID_PARAMETER，表示传入了无效参数。 |

### OH_Pasteboard_Create()

```c
OH_Pasteboard* OH_Pasteboard_Create()
```

**描述：**

创建剪贴板[OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)指针及实例对象。

**使用场景**：需要访问或操作系统剪贴板时，首先创建剪贴板对象实例。

**开发建议**：创建成功后请及时使用，并在不需要时调用OH_Pasteboard_Destroy销毁。

**起始版本：** 13

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)* | 执行成功则返回一个指向剪贴板[OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)实例对象的指针，否则返回nullptr。<br> 当不再需要使用指针时，请使用[OH_Pasteboard_Destroy](#oh_pasteboard_destroy)销毁实例对象，否则会导致内存泄漏。 |

### OH_Pasteboard_Destroy()

```c
void OH_Pasteboard_Destroy(OH_Pasteboard* pasteboard)
```

**描述：**

销毁剪贴板[OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)实例对象。

**使用场景**：不再需要访问剪贴板时，应销毁剪贴板对象释放资源。

**开发建议**：销毁前请确保已取消所有订阅。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)* pasteboard | 表示指向剪贴板[OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)实例的指针。 |

### OH_Pasteboard_Subscribe()

```c
int OH_Pasteboard_Subscribe(OH_Pasteboard* pasteboard, int type, const OH_PasteboardObserver* observer)
```

**描述：**

订阅剪贴板的数据变更事件。典型使用场景包括：监听剪贴板内容变化、实现跨设备剪贴板同步、剪贴板内容变化时更新UI等。调用此函数后，当剪贴板数据发生变化时，系统会通过观察者的回调函数[Pasteboard_Notify](#pasteboard_notify)通知应用。可以订阅本地设备或远端设备的数据变更事件，通过type参数指定需要订阅的事件类型。

**配对调用：**

- 调用此方法订阅剪贴板变更事件后，当不再需要监听时，必须调用[OH_Pasteboard_Unsubscribe](#oh_pasteboard_unsubscribe)取消订阅。
- 取消订阅时需传入与订阅时相同的观察者对象和事件类型。
- 未取消订阅可能导致持续监听和资源占用。

**约束和限制：**

- 同一观察者不能重复订阅同一类型的事件，否则会返回错误。
- 订阅后的观察者对象在取消订阅前不能被销毁。
- 回调函数在异步IPC线程中执行，需要注意线程安全。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)* pasteboard | 表示指向剪贴板[OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)实例的指针。 |
| int type | 表示订阅的剪贴板数据变更类型，详见：[Pasteboard_NotifyType](capi-oh-pasteboard-h.md#pasteboard_notifytype)。 |
| const [OH_PasteboardObserver](capi-pasteboard-oh-pasteboardobserver.md)* observer | 表示指向剪贴板数据变更观察者[OH_PasteboardObserver](capi-pasteboard-oh-pasteboardobserver.md)实例的指针。它指定了剪贴板数据变更时触发的回调函数，详见：[OH_PasteboardObserver](capi-pasteboard-oh-pasteboardobserver.md)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。错误码定义详见[PASTEBOARD_ErrCode](capi-oh-pasteboard-err-code-h.md#pasteboard_errcode)。<br> 若返回ERR_OK，表示执行成功。<br> 若返回ERR_INVALID_PARAMETER，表示传入了无效参数。 |

### OH_Pasteboard_Unsubscribe()

```c
int OH_Pasteboard_Unsubscribe(OH_Pasteboard* pasteboard, int type, const OH_PasteboardObserver* observer)
```

**描述：**

取消对剪贴板数据变更事件的订阅。调用此方法前，必须先调用OH_Pasteboard_Subscribe订阅剪贴板数据变更事件。

**使用场景**：不再需要监听剪贴板数据变更时，应取消订阅释放资源。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)* pasteboard | 表示指向剪贴板[OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)实例的指针。 |
| int type | 表示订阅的剪贴板数据变更类型，需与订阅时传入的类型值一致，详见：[Pasteboard_NotifyType](capi-oh-pasteboard-h.md#pasteboard_notifytype)。 |
| const [OH_PasteboardObserver](capi-pasteboard-oh-pasteboardobserver.md)* observer | 表示指向剪贴板数据变更观察者[OH_PasteboardObserver](capi-pasteboard-oh-pasteboardobserver.md)实例的指针。它指定了剪贴板数据变更时触发的回调函数，详见：[OH_PasteboardObserver](capi-pasteboard-oh-pasteboardobserver.md)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。错误码定义详见[PASTEBOARD_ErrCode](capi-oh-pasteboard-err-code-h.md#pasteboard_errcode)。<br> 若返回ERR_OK，表示执行成功。<br> 若返回ERR_INVALID_PARAMETER，表示传入了无效参数。 |

### OH_Pasteboard_IsRemoteData()

```c
bool OH_Pasteboard_IsRemoteData(OH_Pasteboard* pasteboard)
```

**描述：**

判断剪贴板中的数据是否来自远端设备。典型使用场景包括：跨设备剪贴板同步、分布式场景下根据数据来源选择处理策略、实现数据来源相关的安全校验等。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)* pasteboard | 表示指向剪贴板[OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回剪贴板中的数据是否来自远端设备。返回true表示剪贴板中的数据来自远端设备，返回false表示剪贴板中数据来自本端设备。 |

### OH_Pasteboard_GetDataSource()

```c
int OH_Pasteboard_GetDataSource(OH_Pasteboard* pasteboard, char* source, unsigned int len)
```

**描述：**

获取剪贴板中数据的数据源。

**使用场景**：适用于需要识别数据来源或进行权限控制的场景。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)* pasteboard | 表示指向剪贴板[OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)实例的指针。 |
| char* source | 表示用于存放剪贴板数据源实例的指针，开发者需在调用接口前申请指针指向的内存，建议申请128字节。 |
| unsigned int len | 表示source指针对应的内存长度，取值需不小于数据源字符串的长度（含字符串结束符），建议长度：128字节。当内存长度不足时，返回ERR_INVALID_PARAMETER错误码。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。错误码定义详见[PASTEBOARD_ErrCode](capi-oh-pasteboard-err-code-h.md#pasteboard_errcode)。<br> 若返回ERR_OK，表示执行成功。<br> 若返回ERR_INVALID_PARAMETER，表示传入了无效参数。 |

### OH_Pasteboard_HasType()

```c
bool OH_Pasteboard_HasType(OH_Pasteboard* pasteboard, const char* type)
```

**描述：**

判断剪贴板中是否有指定类型的数据。典型使用场景包括：粘贴前检查剪贴板数据类型是否支持、根据数据类型选择不同的处理方式、验证剪贴板数据格式等。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)* pasteboard | 表示指向剪贴板[OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)实例的指针。 |
| const char* type | 表示要检查的数据类型。包含剪贴板基础数据类型与自定义数据类型，其中剪贴板基础数据类型有："text/plain"、"text/html"、"text/uri"、"text/want"和"pixelMap"，详见[宏定义](#宏定义)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回剪贴板中是否有指定类型的数据。返回true表示剪贴板中包含指定类型的数据，返回false表示剪贴板中没有指定类型的数据。 |

### OH_Pasteboard_HasData()

```c
bool OH_Pasteboard_HasData(OH_Pasteboard* pasteboard)
```

**描述：**

判断剪贴板中是否有数据。

**使用场景**：在读取剪贴板数据前，先判断是否有数据，避免空数据操作。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)* pasteboard | 表示指向剪贴板[OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回剪贴板中是否有数据。返回true表示剪贴板中有数据，返回false表示剪贴板中没有数据。 |

### OH_Pasteboard_HasRemoteData()

```c
bool OH_Pasteboard_HasRemoteData(OH_Pasteboard* pasteboard)
```

**描述：**

判断剪贴板数据是否在远端设备上。由于数据跨设备传输耗时较大，如果剪贴板数据在远端设备上，不建议在UI线程执行检查剪贴板数据中是否包含自定义数据类型，或读取剪贴板数据。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)* pasteboard | 表示指向剪贴板[OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回指示剪贴板数据是否在远端设备上的结果。true表示剪贴板数据在远端设备上；false表示剪贴板数据不在远端设备上。默认为false。 |

### OH_Pasteboard_GetData()

```c
OH_UdmfData* OH_Pasteboard_GetData(OH_Pasteboard* pasteboard, int* status)
```

**描述：**

获取剪贴板中的数据。调用此函数后，系统会读取剪贴板中的内容，返回统一数据对象[OH_UdmfData](../apis-arkdata/capi-udmf-oh-udmfdata.md)实例的指针。开发者可以通过OH_UdmfData相关接口解析数据内容。获取到的数据对象需要开发者手动释放。由于获取剪贴板中数据的时延受数据量大小与网络环境的影响，调用此接口可能耗时较长，建议开发者在非UI线程调用。

**约束和限制：**

- 如果剪贴板为空或数据格式不支持，会返回nullptr。
- 返回的OH_UdmfData对象需要开发者调用[OH_UdmfData_Destroy](../apis-arkdata/capi-udmf-h.md#oh_udmfdata_destroy)释放。
- 粘贴的数据量大时，建议使用[OH_Pasteboard_GetDataWithProgress](#oh_pasteboard_getdatawithprogress)接口以获取进度信息。

**起始版本：** 13

**需要权限**：ohos.permission.READ_PASTEBOARD，应用访问剪贴板内容需[申请访问剪贴板权限](../../basic-services/pasteboard/get-pastedata-permission-guidelines.md)。[使用粘贴控件](../../security/AccessToken/pastebutton.md)访问剪贴板内容的应用，可以无需申请权限。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)* pasteboard | 表示指向剪贴板[OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)实例的指针。 |
| int* status | 该参数是输出参数，表示执行的错误码。错误码定义详见[PASTEBOARD_ErrCode](capi-oh-pasteboard-err-code-h.md#pasteboard_errcode)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_UdmfData](../apis-arkdata/capi-udmf-oh-udmfdata.md)* | 执行成功时返回统一数据对象[OH_UdmfData](../apis-arkdata/capi-udmf-oh-udmfdata.md)实例的指针。否则返回空指针。 |

### OH_Pasteboard_SetData()

```c
int OH_Pasteboard_SetData(OH_Pasteboard* pasteboard, OH_UdmfData* data)
```

**描述：**

将统一数据对象数据写入剪贴板。写入成功后，其他应用可以使用系统剪贴板提供的数据读取接口访问该数据。统一数据对象的数据大小受系统剪贴板容量限制，在写入系统剪贴板后，数据的生命周期由系统剪贴板进行管理。调用此函数后，合法的数据内容会被写入系统剪贴板，覆盖之前的剪贴板数据内容。写入成功后，会触发所有订阅了剪贴板数据变更事件的观察者的回调函数。其他应用可以通过剪贴板API读取这些数据。

**约束和限制：**

- 序列化后的数据大小不能超过系统容量限制（在不同设备上的容量存在差异，通常为128MB）。
- 写入操作会清除之前剪贴板中的所有内容。
- 对于复制数据的数据量比较大的场景，建议使用延迟复制功能以提升性能。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)* pasteboard | 表示指向剪贴板[OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)实例的指针。 |
| [OH_UdmfData](../apis-arkdata/capi-udmf-oh-udmfdata.md)* data | 表示指向统一数据对象[OH_UdmfData](../apis-arkdata/capi-udmf-oh-udmfdata.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。错误码定义详见[PASTEBOARD_ErrCode](capi-oh-pasteboard-err-code-h.md#pasteboard_errcode)。<br> 若返回ERR_OK，表示执行成功。<br> 若返回ERR_INVALID_PARAMETER，表示传入了无效参数。 |

### OH_Pasteboard_ClearData()

```c
int OH_Pasteboard_ClearData(OH_Pasteboard* pasteboard)
```

**描述：**

清空剪贴板中的数据。

**使用场景**：需要清除剪贴板中的数据时使用，如退出应用时清除敏感数据。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)* pasteboard | 表示指向剪贴板[OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行的错误码。错误码定义详见[PASTEBOARD_ErrCode](capi-oh-pasteboard-err-code-h.md#pasteboard_errcode)。<br> 若返回ERR_OK，表示执行成功。<br> 若返回ERR_INVALID_PARAMETER，表示传入了无效参数。 |

### OH_Pasteboard_GetMimeTypes()

```c
char **OH_Pasteboard_GetMimeTypes(OH_Pasteboard *pasteboard, unsigned int *count)
```

**描述：**

获取剪贴板中的MIME类型。典型使用场景包括：判断剪贴板数据类型以选择合适的处理方式、在粘贴前检查数据类型是否支持等。

**起始版本：** 14

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md) *pasteboard | 表示指向剪贴板[OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)实例的指针。 |
| unsigned int *count | 该参数是输出参数，结果集中的类型数量会写入该变量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| char ** | 执行成功时返回剪贴板所有内容的MIME类型，否则返回nullptr。 |

### OH_Pasteboard_GetDataParams_Create()

```c
Pasteboard_GetDataParams *OH_Pasteboard_GetDataParams_Create(void)
```

**描述：**

创建剪贴板[Pasteboard_GetDataParams](capi-pasteboard-getdataparams.md)指针及实例对象。当应用需要获取剪贴板数据并监控进度（如大文件拷贝场景）时，应用按需调用[OH_Pasteboard_GetDataParams_SetProgressIndicator](#oh_pasteboard_getdataparams_setprogressindicator)、[OH_Pasteboard_GetDataParams_SetDestUri](#oh_pasteboard_getdataparams_setdesturi)、[OH_Pasteboard_GetDataParams_SetFileConflictOptions](#oh_pasteboard_getdataparams_setfileconflictoptions)接口配置进度条指示选项、拷贝文件时目标路径、文件冲突选项。

**使用场景**：需要获取剪贴板数据并监控进度（如大文件拷贝、远端数据粘贴等场景），或需要自定义粘贴行为（如指定目标路径、处理文件冲突）时使用。

**起始版本：** 15

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Pasteboard_GetDataParams](capi-pasteboard-getdataparams.md) * | 执行成功时返回一个指向剪贴板[Pasteboard_GetDataParams](capi-pasteboard-getdataparams.md)实例对象的指针，否则返回空指针。<br> 当不再需要使用指针时，请使用[OH_Pasteboard_GetDataParams_Destroy](capi-oh-pasteboard-h.md#oh_pasteboard_getdataparams_destroy)销毁实例对象，否则会导致内存泄漏。 |

### OH_Pasteboard_GetDataParams_Destroy()

```c
void OH_Pasteboard_GetDataParams_Destroy(Pasteboard_GetDataParams* params)
```

**描述：**

销毁剪贴板[Pasteboard_GetDataParams](capi-pasteboard-getdataparams.md)指针指向的实例对象。调用此函数后，Pasteboard_GetDataParams对象被释放，参数配置随之失效。如果在获取粘贴数据过程中销毁参数对象，可能导致进度回调无法正常触发。

**配对调用：**

- 此方法与[OH_Pasteboard_GetDataParams_Create](#oh_pasteboard_getdataparams_create)配对使用。
- 必须在[OH_Pasteboard_GetDataWithProgress](#oh_pasteboard_getdatawithprogress)调用完成后销毁参数对象。
- 不能在进度回调函数中调用此方法销毁。

**使用场景**：不再需要Pasteboard_GetDataParams对象时，应销毁释放资源。

**起始版本：** 15

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Pasteboard_GetDataParams](capi-pasteboard-getdataparams.md)* params | 表示指向剪贴板Pasteboard_GetDataParams的指针。 |

### OH_Pasteboard_GetDataParams_SetProgressIndicator()

```c
void OH_Pasteboard_GetDataParams_SetProgressIndicator(Pasteboard_GetDataParams* params,Pasteboard_ProgressIndicator progressIndicator)
```

**描述：**

向剪贴板[Pasteboard_GetDataParams](capi-pasteboard-getdataparams.md)设置进度条指示选项，可选择是否采用系统默认进度显示。典型使用场景：大文件粘贴时建议使用PASTEBOARD_DEFAULT显示系统默认进度条；需要自定义进度UI或后台静默粘贴时使用PASTEBOARD_NONE。

**起始版本：** 15

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Pasteboard_GetDataParams](capi-pasteboard-getdataparams.md)* params | 表示指向剪贴板Pasteboard_GetDataParams的指针。 |
| [Pasteboard_ProgressIndicator](#pasteboard_progressindicator) progressIndicator | 定义进度条指示选项。 |

### OH_Pasteboard_GetDataParams_SetDestUri()

```c
void OH_Pasteboard_GetDataParams_SetDestUri(Pasteboard_GetDataParams* params, const char* destUri, uint32_t destUriLen)
```

**描述：**

设置拷贝文件时目标路径。若不支持文件处理，则不需要设置此参数；若应用涉及复杂文件处理策略或需要区分文件多路径存储，建议不设置此参数，由应用自行完成文件复制处理。

**使用场景**：需要将剪贴板中的文件拷贝到指定目标路径时设置。

**起始版本：** 15

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Pasteboard_GetDataParams](capi-pasteboard-getdataparams.md)* params | 表示指向剪贴板Pasteboard_GetDataParams的指针。 |
| const char* destUri | 定义拷贝文件目标路径。路径需为绝对路径格式，且应用需具有该路径的读写权限。 |
| uint32_t destUriLen | 定义拷贝文件目标路径长度，单位：字节。 |

### OH_Pasteboard_GetDataParams_SetFileConflictOptions()

```c
void OH_Pasteboard_GetDataParams_SetFileConflictOptions(Pasteboard_GetDataParams* params,Pasteboard_FileConflictOptions option)
```

**描述：**

向剪贴板[Pasteboard_GetDataParams](capi-pasteboard-getdataparams.md)设置文件冲突选项。调用[OH_Pasteboard_GetDataWithProgress](#oh_pasteboard_getdatawithprogress)时，需将已设置文件冲突选项的[Pasteboard_GetDataParams](capi-pasteboard-getdataparams.md)作为参数传入。

**使用场景**：拷贝文件时，目标路径存在同名文件，需要设置冲突处理策略。

**参数选取原则**：

- PASTEBOARD_OVERWRITE：需要确保使用最新文件内容时选择覆盖。
- PASTEBOARD_SKIP：需要保留原有文件时选择跳过。

**起始版本：** 15

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Pasteboard_GetDataParams](capi-pasteboard-getdataparams.md)* params | 表示指向剪贴板Pasteboard_GetDataParams的指针。 |
| [Pasteboard_FileConflictOptions](#pasteboard_fileconflictoptions) option | 定义文件拷贝冲突时的选项，默认为PASTEBOARD_OVERWRITE。 |

### OH_Pasteboard_GetDataParams_SetProgressListener()

```c
void OH_Pasteboard_GetDataParams_SetProgressListener(Pasteboard_GetDataParams* params,const OH_Pasteboard_ProgressListener listener)
```

**描述：**

向剪贴板[Pasteboard_GetDataParams](capi-pasteboard-getdataparams.md)设置进度上报回调函数。

**使用场景**：需要自定义进度显示UI或后台静默处理粘贴任务时，通过设置此回调函数来接收进度更新。

**起始版本：** 15

**参数：**

| 参数项                                                                              | 描述 |
|----------------------------------------------------------------------------------| -- |
| [Pasteboard_GetDataParams](capi-pasteboard-getdataparams.md)* params             | 表示指向剪贴板Pasteboard_GetDataParams的指针。 |
| const [OH_Pasteboard_ProgressListener](#oh_pasteboard_progresslistener) listener | 表示进度上报回调函数，仅在[progressIndicator](#oh_pasteboard_getdataparams_setprogressindicator)设置为PASTEBOARD_NONE时生效。该参数支持传入NULL，以表示无需进度回调。 |

### OH_Pasteboard_ProgressInfo_GetProgress()

```c
int OH_Pasteboard_ProgressInfo_GetProgress(Pasteboard_ProgressInfo* progressInfo)
```

**描述：**

从[Pasteboard_ProgressInfo](capi-pasteboard-progressinfo.md)获取粘贴进度。典型使用场景包括：在自定义进度回调中更新UI进度条、监控大文件粘贴进度、根据进度调整业务逻辑等。

**起始版本：** 15

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Pasteboard_ProgressInfo](capi-pasteboard-progressinfo.md)* progressInfo | 表示指向剪贴板[Pasteboard_ProgressInfo](capi-pasteboard-progressinfo.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回粘贴进度百分比，取值范围[0, 100]。 |

### OH_Pasteboard_ProgressCancel()

```c
void OH_Pasteboard_ProgressCancel(Pasteboard_GetDataParams* params)
```

**描述：**

取消正在进行的粘贴操作。该函数用于中断[OH_Pasteboard_GetDataWithProgress](#oh_pasteboard_getdatawithprogress)执行过程中的数据传输。调用后，当前粘贴操作将被终止，已传输的部分数据可能保留或清理，取决于具体操作状态。取消后如需再次获取剪贴板数据，需重新调用[OH_Pasteboard_GetDataWithProgress](#oh_pasteboard_getdatawithprogress)。

**使用场景**：适用于用户主动取消、错误中断传输，或限制粘贴超时等情形。

**约束和限制：**

- 仅在调用[OH_Pasteboard_GetDataWithProgress](#oh_pasteboard_getdatawithprogress)且操作未完成时有效。
- 取消操作是异步的，可能不会立即生效。
- 取消操作不可逆，一旦取消，如需要获取剪贴板数据，需要重新开始粘贴流程。

**起始版本：** 15

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Pasteboard_GetDataParams](capi-pasteboard-getdataparams.md)* params | 表示指向剪贴板Pasteboard_GetDataParams的指针。 |

### OH_Pasteboard_GetDataWithProgress()

```c
OH_UdmfData* OH_Pasteboard_GetDataWithProgress(OH_Pasteboard* pasteboard, Pasteboard_GetDataParams* params,int* status)
```

**描述：**

获取剪贴板的数据以及粘贴进度，不支持对文件夹的拷贝。调用此函数后，系统开始从系统剪贴板获取数据。如果剪贴板数据来自远端设备或包含大量文件，会通过[OH_Pasteboard_ProgressListener](#oh_pasteboard_progresslistener)回调函数上报进度。数据传输完成后，返回统一数据对象指针。整个过程可能耗时较长，建议在非UI线程调用。

**起始版本：** 15

**需要权限**：ohos.permission.READ_PASTEBOARD，应用访问剪贴板内容需[申请访问剪贴板权限](../../basic-services/pasteboard/get-pastedata-permission-guidelines.md)。[使用粘贴控件](../../security/AccessToken/pastebutton.md)访问剪贴板内容的应用，可以无需申请权限。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)* pasteboard | 表示指向剪贴板[OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)实例的指针。 |
| [Pasteboard_GetDataParams](capi-pasteboard-getdataparams.md)* params | 表示指向剪贴板Pasteboard_GetDataParams的指针。 |
| int* status | 该参数是输出参数，表示执行的错误码。错误码定义详见[PASTEBOARD_ErrCode](capi-oh-pasteboard-err-code-h.md#pasteboard_errcode)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_UdmfData](../apis-arkdata/capi-udmf-oh-udmfdata.md)* | 执行成功时返回统一数据对象OH_UdmfData实例的指针。否则返回空指针。 |

### OH_Pasteboard_GetChangeCount()

```c
uint32_t OH_Pasteboard_GetChangeCount(OH_Pasteboard *pasteboard)
```

**描述：**

获取剪贴板内容的变化次数。典型使用场景包括：判断剪贴板内容是否已变化、实现剪贴板内容增量同步、检测剪贴板内容是否过期、基于变化计数实现缓存优化等。

**起始版本：** 18

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md) *pasteboard | 表示指向剪贴板[OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| uint32_t | 执行成功时返回剪贴板内容的变化次数，否则返回0。 |

**返回值说明:**

- 当剪贴板内容过期（如设备重启、剪贴板服务重启或数据生命周期结束）或调用OH_Pasteboard_ClearData等接口导致剪贴板内容为空时，内容变化次数不会因此改变。
- 系统重启或剪贴板服务异常重启时，剪贴板内容变化次数重新从0开始计数。
- 对同一内容连续多次复制会被视作多次更改，每次复制均会导致内容变化次数增加。

### OH_Pasteboard_SyncDelayedDataAsync()

```c
void OH_Pasteboard_SyncDelayedDataAsync(OH_Pasteboard* pasteboard, void (*callback)(int errorCode))
```

**描述：**

通知剪贴板从应用同步所有延迟数据（延迟数据指在延迟复制模式下，先写入数据类型到剪贴板，实际数据内容按需延迟加载的数据传输机制），与延迟复制接口[OH_UdmfRecordProvider_SetData](../apis-arkdata/capi-udmf-h.md#oh_udmfrecordprovider_setdata)搭配使用。当所有延迟数据同步完成时，使用callback异步通知应用。当应用使用延迟复制功能复制时，仅将应用支持的数据类型写入剪贴板。应用应在退出时，重新调用[OH_Pasteboard_SetData](#oh_pasteboard_setdata)接口主动提交所有复制数据或调用此接口通知剪贴板获取全量数据，等待数据同步完成再继续退出，否则可能导致其他应用粘贴获取不到数据。

> **注意：**
> - 调用此接口会延长退出过程，建议应用直接设置数据到剪贴板，而不是调用延迟复制接口[OH_UdmfRecordProvider_SetData](../apis-arkdata/capi-udmf-h.md#oh_udmfrecordprovider_setdata)和此接口。

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md) *pasteboard | 表示指向剪贴板[OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)实例的指针。 |
| void (*callback)(int errorCode) | 数据同步完成后调用的回调函数指针，errorCode表示同步任务的结果，错误码定义详见[PASTEBOARD_ErrCode](capi-oh-pasteboard-err-code-h.md#pasteboard_errcode)。 |