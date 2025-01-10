# Pasteboard


## 概述

系统剪贴板支持复制和粘贴多种类型的数据。 可以使用此模块接口操作纯文本、HTML、URI、像素图片等其他类型的数据。

**起始版本：** 13


## 汇总


### 文件

| 名称 | 描述 |
| -------- | -------- |
| [oh_pasteboard.h](oh__pasteboard_8h.md) | 提供访问系统剪贴板的接口、数据结构、枚举类型。 |
| [oh_pasteboard_err_code.h](oh__pasteboard__err__code_8h.md) | 声明剪贴板框架错误码信息。 |


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| typedef enum [Pasteboard_NotifyType](#pasteboard_notifytype) [Pasteboard_NotifyType](#pasteboard_notifytype) | 剪贴板的数据变更类型。  |
| typedef void(\* [Pasteboard_Notify](#pasteboard_notify)) (void \*context, [Pasteboard_NotifyType](#pasteboard_notifytype) type) | 定义剪贴板内容变更时触发的回调函数。  |
| typedef void(\* [Pasteboard_Finalize](#pasteboard_finalize)) (void \*context) | 定义用于释放上下文的回调函数，剪贴板数据变更观察者对象销毁时触发。  |
| typedef struct [OH_PasteboardObserver](#oh_pasteboardobserver) [OH_PasteboardObserver](#oh_pasteboardobserver) | 定义剪贴板数据变更观察者。  |
| typedef struct [OH_Pasteboard](#oh_pasteboard) [OH_Pasteboard](#oh_pasteboard) | 定义剪贴板对象，用以操作系统剪贴板。  |
| typedef enum [PASTEBOARD_ErrCode](#pasteboard_errcode) [PASTEBOARD_ErrCode](#pasteboard_errcode) | 错误码信息。  |
| typedef enum [Pasteboard_FileConflictOption](#pasteboard_fileconflictoption) [Pasteboard_FileConflictOption](#pasteboard_fileconflictoption) | 定义文件拷贝冲突时的选项。 |
| typedef enum [Pasteboard_ProgressIndicator](#pasteboard_progressindicator) [Pasteboard_ProgressIndicator](#pasteboard_progressindicator) | 定义进度条指示选项，可选择是否采用系统默认进度显示。 |
| typedef struct [Pasteboard_ProgressInfo](#pasteboard_progressinfo) [Pasteboard_ProgressInfo](#pasteboard_progressinfo) | 定义进度上报的数据结构。 |
| typedef struct [Pasteboard_ProgressListener](#pasteboard_progresslistener) [Pasteboard_ProgressListener](#pasteboard_progresslistener) | 定义进度数据变化的订阅函数，当选择不使用系统默认进度显示时，可设置该项获取粘贴过程的进度。 |
| typedef struct [Pasteboard_ProgressSignal](#pasteboard_progresssignal) [Pasteboard_ProgressSignal](#pasteboard_progresssignal) | 定义进度取消的函数，在粘贴过程中可选择取消任务。 |
| typedef struct [OH_Pasteboard_GetDataParams](#oh_pasteboard_getdataparams) [OH_Pasteboard_GetDataParams](#oh_pasteboard_getdataparams) | 剪贴板中获取数据时需要的参数，包含目标路径、文件冲突选项、进度条指示选项等。 |
| typedef void(* [Pasteboard_ProgressNotify](#pasteboard_progressnotify))([Pasteboard_ProgressInfo](#pasteboard_progressinfo) progressInfo); | 定义获取进度数据的回调函数，当选择不使用系统默认进度显示时，可设置该项获取粘贴过程的进度。 |
| typedef int (* [Pasteboard_ProgressCancel](#pasteboard_progresscancel))(); | 取消正在进行的拷贝粘贴任务。 |


### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [Pasteboard_NotifyType](#pasteboard_notifytype) { NOTIFY_LOCAL_DATA_CHANGE = 1, NOTIFY_REMOTE_DATA_CHANGE = 2 } | 剪贴板的数据变更类型。  |
| [PASTEBOARD_ErrCode](#pasteboard_errcode) {<br/>ERR_OK = 0, ERR_PERMISSION_ERROR = 201, ERR_INVALID_PARAMETER = 401, ERR_DEVICE_NOT_SUPPORTED = 801,<br/>ERR_INNER_ERROR = 12900000, ERR_BUSY = 12900003, ERR_COPY_FILE_ERROR = 12900007, ERR_PROGRESS_START_ERROR = 12900008, ERR_PROGRESS_ABNORMAL = 12900009, ERR_GET_DATA_FAILED = 12900010,<br/>} | 错误码信息。  |
| [Pasteboard_FileConflictOption](#pasteboard_fileconflictoption) { OVERWRITE = 0, SKIP = 1} | 拷贝文件文件冲突时的选项。 |
| [Pasteboard_ProgressIndicator](#pasteboard_progressindicator) { NONE = 0, DEFAULT = 1 } | 从剪贴板获取数据时的进度条类型。 |


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_PasteboardObserver](#oh_pasteboardobserver) \* [OH_PasteboardObserver_Create](#oh_pasteboardobserver_create) () | 创建一个剪贴板数据变更观察者[OH_PasteboardObserver](#oh_pasteboardobserver)指针及实例对象。  |
| int [OH_PasteboardObserver_Destroy](#oh_pasteboardobserver_destroy) ([OH_PasteboardObserver](#oh_pasteboardobserver) \*observer) | 销毁剪贴板数据变更观察者[OH_PasteboardObserver](#oh_pasteboardobserver)指针指向的实例对象。  |
| int [OH_PasteboardObserver_SetData](#oh_pasteboardobserver_setdata) ([OH_PasteboardObserver](#oh_pasteboardobserver) \*observer, void \*context, const [Pasteboard_Notify](#pasteboard_notify) callback, const [Pasteboard_Finalize](#pasteboard_finalize) finalize) | 向剪贴板数据变更观察者设置回调函数。  |
| [OH_Pasteboard](#oh_pasteboard) \* [OH_Pasteboard_Create](#oh_pasteboard_create) () | 创建剪贴板[OH_Pasteboard](#oh_pasteboard)指针及实例对象。  |
| void [OH_Pasteboard_Destroy](#oh_pasteboard_destroy) ([OH_Pasteboard](#oh_pasteboard) \*pasteboard) | 销毁剪贴板[OH_Pasteboard](#oh_pasteboard)实例对象。  |
| int [OH_Pasteboard_Subscribe](#oh_pasteboard_subscribe) ([OH_Pasteboard](#oh_pasteboard) \*pasteboard, int type, const [OH_PasteboardObserver](#oh_pasteboardobserver) \*observer) | 订阅剪贴板的数据变更事件。  |
| int [OH_Pasteboard_Unsubscribe](#oh_pasteboard_unsubscribe) ([OH_Pasteboard](#oh_pasteboard) \*pasteboard, int type, const [OH_PasteboardObserver](#oh_pasteboardobserver) \*observer) | 取消对剪贴板数据变更事件的订阅。  |
| bool [OH_Pasteboard_IsRemoteData](#oh_pasteboard_isremotedata) ([OH_Pasteboard](#oh_pasteboard) \*pasteboard) | 判断剪贴板中的数据是否来自远端设备。  |
| int [OH_Pasteboard_GetDataSource](#oh_pasteboard_getdatasource) ([OH_Pasteboard](#oh_pasteboard) \*pasteboard, char \*source, unsigned int len) | 获取剪贴板中数据的数据源。  |
| bool [OH_Pasteboard_HasType](#oh_pasteboard_hastype) ([OH_Pasteboard](#oh_pasteboard) \*pasteboard, const char \*type) | 判断剪贴板中是否有指定类型的数据。  |
| bool [OH_Pasteboard_HasData](#oh_pasteboard_hasdata) ([OH_Pasteboard](#oh_pasteboard) \*pasteboard) | 判断剪贴板中是否有数据。  |
| OH_UdmfData \* [OH_Pasteboard_GetData](#oh_pasteboard_getdata) ([OH_Pasteboard](#oh_pasteboard) \*pasteboard, int \*status) | 获取剪贴板中的数据。  |
| int [OH_Pasteboard_SetData](#oh_pasteboard_setdata) ([OH_Pasteboard](#oh_pasteboard) \*pasteboard, OH_UdmfData \*data) | 将统一数据对象数据写入剪贴板。  |
| int [OH_Pasteboard_ClearData](#oh_pasteboard_cleardata) ([OH_Pasteboard](#oh_pasteboard) \*pasteboard) | 清空剪贴板中的数据。  |
| char ** [OH_Pasteboard_GetMimeTypes](#oh_pasteboard_getmimetypes) ([OH_Pasteboard](#oh_pasteboard) \*pasteboard, unsigned int *count) | 获取剪切板中的MIME类型。  |
| OH_UdmfDat *[OH_Pasteboard_GetDataWithProgress](#oh_pasteboard_getdatawithprogress)(OH_Pasteboard *pasteboard, [OH_Pasteboard_GetDataParams](#oh_pasteboard_getdataparams) *params, int *status) | 获取剪贴板的数据以及粘贴进度 |


## 类型定义说明


### OH_Pasteboard

```
typedef struct OH_Pasteboard OH_Pasteboard
```
**描述：**

定义剪贴板对象，用以操作系统剪贴板。

**起始版本：** 13


### OH_PasteboardObserver

```
typedef struct OH_PasteboardObserver OH_PasteboardObserver
```
**描述：**

定义剪贴板数据变更观察者。

**起始版本：** 13


### PASTEBOARD_ErrCode

```
typedef enum PASTEBOARD_ErrCode PASTEBOARD_ErrCode
```
**描述：**

错误码信息。

**起始版本：** 13


### Pasteboard_Finalize

```
typedef void(* Pasteboard_Finalize) (void *context)
```
**描述：**

定义用于释放上下文的回调函数，剪贴板数据变更观察者对象销毁时触发。

**起始版本：** 13

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| context | 要释放的上下文指针。  |


### Pasteboard_Notify

```
typedef void(* Pasteboard_Notify) (void *context, Pasteboard_NotifyType type)
```
**描述：**

定义剪贴板内容变更时触发的回调函数。

**起始版本：** 13

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| context | 上下文信息，由函数[OH_PasteboardObserver_SetData](#oh_pasteboardobserver_setdata)传入。  |
| type | 数据变更的类型。详见：[Pasteboard_NotifyType](#pasteboard_notifytype)。  |


### Pasteboard_NotifyType

```
typedef enum Pasteboard_NotifyType Pasteboard_NotifyType
```
**描述：**

剪贴板的数据变更类型。

**起始版本：** 13

### Pasteboard_FileConflictOption 

```
typedef enum Pasteboard_FileConflictOption
```

**描述：**

定义文件拷贝冲突时的选项，

**起始版本：** 15

### Pasteboard_ProgressIndicator 

```
typedef enum Pasteboard_ProgressIndicator
```

**描述：**

定义进度条指示选项，可选择是否采用系统默认进度显示。

**起始版本：** 15

### Pasteboard_ProgressInfo 

```
typedef struct Pasteboard_ProgressInfo {
	int progress;
} Pasteboard_ProgressInfo;
```

**描述：**

定义进度上报的数据结构，且仅当进度指示选项[Pasteboard_ProgressIndicator](#pasteboard_progressindicator)设置为NONE时才会上报此信息。

**起始版本：** 15

| 名称     | 类型 | 描述                                                       |
| -------- | ---- | ---------------------------------------------------------- |
| progress | int  | 不使用系统提供的进度条时，系统上报拷贝粘贴任务进度百分比。 |

### Pasteboard_ProgressNotify

```
typedef void (*Pasteboard_ProgressNotify)(Pasteboard_ProgressInfo progressInfo);
```

**描述：**

用于在不使用剪贴板提供的进度条时，通知应用拷贝粘贴任务进度。

**起始版本：** 15

**参数:**

| 名称         | 类型                                                | 描述                                                         |
| ------------ | --------------------------------------------------- | ------------------------------------------------------------ |
| progressInfo | [Pasteboard_ProgressInfo](#pasteboard_progressinfo) | 定义进度上报的数据结构，且仅当进度指示选项[Pasteboard_ProgressIndicator](#pasteboard_progressindicator)设置为NONE时才会上报此信息。 |

### Pasteboard_ProgressListener 

```
typedef struct Pasteboard_ProgressListener {
	Pasteboard_ProgressNotify callback;
} Pasteboard_ProgressListener;
```

**描述：**

定义进度数据变化的订阅函数，当选择不使用系统默认进度显示时，可设置该项获取粘贴过程的进度。

**起始版本：** 15

| 名称     | 类型                                                    | 描述                                                         |
| -------- | ------------------------------------------------------- | ------------------------------------------------------------ |
| callback | [Pasteboard_ProgressNotify](#pasteboard_progressnotify) | 用于在不使用剪贴板提供的进度条时，通知应用拷贝粘贴任务进度。 |

### Pasteboard_ProgressCancel

```
typedef int (*Pasteboard_ProgressCancel)();
```

**描述：**

取消正在进行的拷贝粘贴任务。

**起始版本：** 15

### Pasteboard_ProgressSignal

```
typedef struct Pasteboard_ProgressSignal {
    Pasteboard_ProgressCancel cancel;
} Pasteboard_ProgressSignal;
```

**描述：**

定义进度取消的函数，在粘贴过程中可选择取消任务，且仅当进度指示选项[Pasteboard_ProgressIndicator](#pasteboard_progressindicator)设置为NONE时此参数才有意义。

**起始版本：** 15

| 名称   | 类型                                                    | 描述                     |
| ------ | ------------------------------------------------------- | ------------------------ |
| cancel | [Pasteboard_ProgressCancel](#pasteboard_progresscancel) | 取消正在进行的粘贴任务。 |

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

**描述：**

应用在使用剪贴板提供的文件拷贝能力的情况下需要的参数，包含目标路径、文件冲突选项、进度条类型等。

**起始版本：** 15

| 名称               | 类型                                                         | 说明                                                         |
| ------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| destUri            | char *                                                       | 拷贝文件时目标路径。若不支持文件处理，则不需要设置此参数；若应用涉及复杂文件处理策略或需要区分文件多路径存储，建议不设置此参数，由应用自行完成文件copy处理。 |
| destUriLen         | unsigned int                                                 | 拷贝文件时目标路径长度。                                     |
| fileConflictOption | [Pasteboard_FileConflictOption](#pasteboard_fileconflictoption) | 定义文件拷贝冲突时的选项，默认为OVERWRITE。                  |
| progressIndicator  | [Pasteboard_ProgressIndicator](#pasteboard_progressindicator) | 定义进度条指示选项，可选择是否采用系统默认进度显示。         |
| progressListener   | [Pasteboard_ProgressListener](#pasteboard_progresslistener)  | 定义进度数据变化的订阅函数，当选择不使用系统默认进度显示时，可设置该项获取粘贴过程的进度。 |
| progressSignal     | [Pasteboard_ProgressSignal](#pasteboard_progresssignal)      | 定义进度取消的函数，在粘贴过程中可选择取消任务，且仅当进度指示选项[Pasteboard_ProgressIndicator](#pasteboard_progressindicator)设置为NONE时此参数才有意义。 |


## 枚举类型说明


### PASTEBOARD_ErrCode

```
enum PASTEBOARD_ErrCode
```
**描述：**

错误码信息。

**起始版本：** 13

| 枚举值 | 描述 |
| -------- | -------- |
| ERR_OK  | 执行成功。  |
| ERR_PERMISSION_ERROR  | 权限校验失败。  |
| ERR_INVALID_PARAMETER  | 非法参数。  |
| ERR_DEVICE_NOT_SUPPORTED  | 设备能力不支持。  |
| ERR_INNER_ERROR  | 内部错误。  |
| ERR_BUSY  | 系统忙。  |
| ERR_COPY_FILE_ERROR | 文件拷贝失败。 |
| ERR_PROGRESS_START_ERROR | 当应用使用系统提供的进度条时，创建进度条失败。 |
| ERR_PROGRESS_ABNORMAL | 当应用不使用剪贴板提供的进度条时，进度上报异常。 |
| ERR_GET_DATA_FAILED | 获取粘贴数据失败。 |


### Pasteboard_NotifyType

```
enum Pasteboard_NotifyType
```
**描述：**

剪贴板的数据变更类型。

**起始版本：** 13

| 枚举值 | 描述 |
| -------- | -------- |
| NOTIFY_LOCAL_DATA_CHANGE  | 本地设备剪贴板数据变更。  ||
| NOTIFY_REMOTE_DATA_CHANGE  | 组网内的非本地设备剪贴板数据变更。  ||

### Pasteboard_FileConflictOption 

```
enum Pasteboard_FileConflictOption
```

**描述：**

定义拷贝文件文件冲突时的选项。

**起始版本：** 15

| 枚举值    | 描述                                                         |
| --------- | ------------------------------------------------------------ |
| OVERWRITE | 目标路径存在同文件名时覆盖。                                 |
| SKIP      | 目标路径存在同文件名时跳过，若设置SKIP，应用获取到的粘贴数据不包含跳过文件。 |

### Pasteboard_ProgressIndicator 

```
enum Pasteboard_ProgressIndicator
```

**描述：**

定义进度条指示选项，可选择是否采用系统默认进度显示。

**起始版本：** 15

| 枚举值  | 描述                     |
| ------- | ------------------------ |
| NONE    | 不采用系统默认进度显示。 |
| DEFAULT | 采用系统默认进度显示。   |

## 函数说明


### OH_Pasteboard_ClearData()

```
int OH_Pasteboard_ClearData (OH_Pasteboard * pasteboard)
```
**描述：**

清空剪贴板中的数据。

**起始版本：** 13

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| pasteboard | 表示指向剪贴板[OH_Pasteboard](#oh_pasteboard)实例的指针。  |

**返回：**

返回执行的错误码。错误码定义详见[PASTEBOARD_ErrCode](#pasteboard_errcode)。 若返回ERR_OK，表示指向成功。 若返回ERR_INVALID_PARAMETER，表示传入了无效参数。

**参见：**

[OH_Pasteboard](#oh_pasteboard)

[PASTEBOARD_ErrCode](#pasteboard_errcode)


### OH_Pasteboard_Create()

```
OH_Pasteboard* OH_Pasteboard_Create ()
```
**描述：**

创建剪贴板[OH_Pasteboard](#oh_pasteboard)指针及实例对象。

**起始版本：** 13

**返回：**

执行成功则返回一个指向剪贴板[OH_Pasteboard](#oh_pasteboard)实例对象的指针，否则返回nulllptr。

**参见：**

[OH_Pasteboard](#oh_pasteboard)


### OH_Pasteboard_Destroy()

```
void OH_Pasteboard_Destroy (OH_Pasteboard * pasteboard)
```
**描述：**

销毁剪贴板[OH_Pasteboard](#oh_pasteboard)实例对象。

**起始版本：** 13

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| pasteboard | 表示指向剪贴板[OH_Pasteboard](#oh_pasteboard)实例的指针。  |

**参见：**

[OH_Pasteboard](#oh_pasteboard)


### OH_Pasteboard_GetData()

```
OH_UdmfData* OH_Pasteboard_GetData (OH_Pasteboard * pasteboard, int * status )
```
**描述：**

获取剪贴板中的数据。

**起始版本：** 13

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| pasteboard | 表示指向剪贴板[OH_Pasteboard](#oh_pasteboard)实例的指针。  |
| status | 该参数是输出参数，表示执行的错误码。错误码定义详见[PASTEBOARD_ErrCode](#pasteboard_errcode)。  |

**返回：**

执行成功时返回统一数据对象**OH_UdmfData**实例的指针。否则返回空指针。

**参见：**

[OH_Pasteboard](#oh_pasteboard)

OH_UdmfData

[PASTEBOARD_ErrCode](#pasteboard_errcode)


### OH_Pasteboard_GetDataSource()

```
int OH_Pasteboard_GetDataSource (OH_Pasteboard * pasteboard, char * source, unsigned int len )
```
**描述：**

获取剪贴板中数据的数据源。

**起始版本：** 13

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| pasteboard | 表示指向剪贴板[OH_Pasteboard](#oh_pasteboard)实例的指针。  |
| source | 该参数是输出参数，表示剪贴板中数据的数据源字符串。  |
| len | 该参数是输出参数，表示数据源字符串的长度。  |

**返回：**

返回执行的错误码。错误码定义详见[PASTEBOARD_ErrCode](#pasteboard_errcode)。 若返回ERR_OK，表示指向成功。 若返回ERR_INVALID_PARAMETER，表示传入了无效参数。

**参见：**

[OH_Pasteboard](#oh_pasteboard)

[PASTEBOARD_ErrCode](#pasteboard_errcode)


### OH_Pasteboard_HasData()

```
bool OH_Pasteboard_HasData (OH_Pasteboard * pasteboard)
```
**描述：**

判断剪贴板中是否有数据。

**起始版本：** 13

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| pasteboard | 表示指向剪贴板[OH_Pasteboard](#oh_pasteboard)实例的指针。  |

**返回：**

返回剪贴板中是否有数据。返回true表示剪贴板中有数据，返回false表示剪贴板中没有数据。

**参见：**

[OH_Pasteboard](#oh_pasteboard)


### OH_Pasteboard_HasType()

```
bool OH_Pasteboard_HasType (OH_Pasteboard * pasteboard, const char * type )
```
**描述：**

判断剪贴板中是否有指定类型的数据。

**起始版本：** 13

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| pasteboard | 表示指向剪贴板[OH_Pasteboard](#oh_pasteboard)实例的指针。  |
| type | 表示要检查的数据类型。  |

**返回：**

返回剪贴板中是否有指定类型的数据。返回true表示剪贴板中包含指定类型的数据，返回false表示剪贴板中没有指定类型的数据。

**参见：**

[OH_Pasteboard](#oh_pasteboard)


### OH_Pasteboard_IsRemoteData()

```
bool OH_Pasteboard_IsRemoteData (OH_Pasteboard * pasteboard)
```
**描述：**

判断剪贴板中的数据是否来自远端设备。

**起始版本：** 13

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| pasteboard | 表示指向剪贴板[OH_Pasteboard](#oh_pasteboard)实例的指针。  |

**返回：**

返回剪贴板中的数据是否来自远端设备。返回true表示剪贴板中的数据来自远端设备，返回false表示剪贴板中数据来自本端设备。

**参见：**

[OH_Pasteboard](#oh_pasteboard)


### OH_Pasteboard_SetData()

```
int OH_Pasteboard_SetData (OH_Pasteboard * pasteboard, OH_UdmfData * data )
```
**描述：**

将统一数据对象数据写入剪贴板。

**起始版本：** 13

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| pasteboard | 表示指向剪贴板[OH_Pasteboard](#oh_pasteboard)实例的指针。  |
| data | 表示指向统一数据对象**OH_UdmfData**实例的指针。  |

**返回：**

返回执行的错误码。错误码定义详见[PASTEBOARD_ErrCode](#pasteboard_errcode)。 若返回ERR_OK，表示指向成功。 若返回ERR_INVALID_PARAMETER，表示传入了无效参数。

**参见：**

[OH_Pasteboard](#oh_pasteboard)

OH_UdmfData

[PASTEBOARD_ErrCode](#pasteboard_errcode)


### OH_Pasteboard_Subscribe()

```
int OH_Pasteboard_Subscribe (OH_Pasteboard * pasteboard, int type, const OH_PasteboardObserver * observer )
```
**描述：**

订阅剪贴板的数据变更事件。

**起始版本：** 13

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| pasteboard | 表示指向剪贴板[OH_Pasteboard](#oh_pasteboard)实例的指针。  |
| type | 表示订阅的剪贴板数据变更类型，详见：[Pasteboard_NotifyType](#pasteboard_notifytype)。  |
| observer | 表示指向剪贴板数据变更观察者[OH_PasteboardObserver](#oh_pasteboardobserver)实例的指针。 它指定了剪贴板数据变更时触发的回调函数，详见：[OH_PasteboardObserver](#oh_pasteboardobserver)。  |

**返回：**

返回执行的错误码。错误码定义详见[PASTEBOARD_ErrCode](#pasteboard_errcode)。 若返回ERR_OK，表示指向成功。 若返回ERR_INVALID_PARAMETER，表示传入了无效参数。

**参见：**

[OH_Pasteboard](#oh_pasteboard)

[OH_PasteboardObserver](#oh_pasteboardobserver)

[Pasteboard_NotifyType](#pasteboard_notifytype)

[PASTEBOARD_ErrCode](#pasteboard_errcode)


### OH_Pasteboard_Unsubscribe()

```
int OH_Pasteboard_Unsubscribe (OH_Pasteboard * pasteboard, int type, const OH_PasteboardObserver * observer )
```
**描述：**

取消对剪贴板数据变更事件的订阅。

**起始版本：** 13

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| pasteboard | 表示指向剪贴板[OH_Pasteboard](#oh_pasteboard)实例的指针。  |
| type | 表示订阅的剪贴板数据变更类型，详见：[Pasteboard_NotifyType](#pasteboard_notifytype)。  |
| observer | 表示指向剪贴板数据变更观察者[OH_PasteboardObserver](#oh_pasteboardobserver)实例的指针。 它指定了剪贴板数据变更时触发的回调函数，详见：[OH_PasteboardObserver](#oh_pasteboardobserver)。  |

**返回：**

返回执行的错误码。错误码定义详见[PASTEBOARD_ErrCode](#pasteboard_errcode)。 若返回ERR_OK，表示指向成功。 若返回ERR_INVALID_PARAMETER，表示传入了无效参数。

**参见：**

[OH_Pasteboard](#oh_pasteboard)

[OH_PasteboardObserver](#oh_pasteboardobserver)

[Pasteboard_NotifyType](#pasteboard_notifytype)

[PASTEBOARD_ErrCode](#pasteboard_errcode)


### OH_PasteboardObserver_Create()

```
OH_PasteboardObserver* OH_PasteboardObserver_Create ()
```
**描述：**

创建一个剪贴板数据变更观察者[OH_PasteboardObserver](#oh_pasteboardobserver)指针及实例对象。

**起始版本：** 13

**返回：**

执行成功时返回一个指向剪贴板数据变更观察者[OH_PasteboardObserver](#oh_pasteboardobserver)实例对象的指针，否则返回空指针。 当不再需要使用指针时，请使用[OH_PasteboardObserver_Destroy](#oh_pasteboardobserver_destroy)销毁实例对象，否则会导致内存泄漏。

**参见：**

[OH_PasteboardObserver](#oh_pasteboardobserver)


### OH_PasteboardObserver_Destroy()

```
int OH_PasteboardObserver_Destroy (OH_PasteboardObserver * observer)
```
**描述：**

销毁剪贴板数据变更观察者[OH_PasteboardObserver](#oh_pasteboardobserver)指针指向的实例对象。

**起始版本：** 13

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| observer | 表示指向剪贴板数据变更观察者[OH_PasteboardObserver](#oh_pasteboardobserver)实例的指针。  |

**返回：**

返回执行的错误码。错误码定义详见[PASTEBOARD_ErrCode](#pasteboard_errcode)。 若返回ERR_OK，表示指向成功。 若返回ERR_INVALID_PARAMETER，表示传入了无效参数。

**参见：**

[OH_PasteboardObserver](#oh_pasteboardobserver)

[PASTEBOARD_ErrCode](#pasteboard_errcode)


### OH_PasteboardObserver_SetData()

```
int OH_PasteboardObserver_SetData (OH_PasteboardObserver * observer, void * context, const Pasteboard_Notify callback, const Pasteboard_Finalize finalize )
```
**描述：**

向剪贴板数据变更观察者设置回调函数。

**起始版本：** 13

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| observer | 表示指向剪贴板数据变更观察者[OH_PasteboardObserver](#oh_pasteboardobserver)实例的指针。  |
| context | 表示指向上下文数据的指针，将作为第一个参数传入[Pasteboard_Notify](#pasteboard_notify)。  |
| callback | 表示数据变更回调函数。详见：[Pasteboard_Notify](#pasteboard_notify)。  |
| finalize | 表示可选的回调函数，可以用于剪贴板数据变更观察者销毁时释放上下文数据。详见：[Pasteboard_Finalize](#pasteboard_finalize)。  |

**返回：**

返回执行的错误码。错误码定义详见[PASTEBOARD_ErrCode](#pasteboard_errcode)。 若返回ERR_OK，表示指向成功。 若返回ERR_INVALID_PARAMETER，表示传入了无效参数。

**参见：**

[OH_PasteboardObserver](#oh_pasteboardobserver)

[Pasteboard_Notify](#pasteboard_notify)

[PASTEBOARD_ErrCode](#pasteboard_errcode)

### OH_Pasteboard_GetMimeTypes()

```
char ** OH_Pasteboard_GetMimeTypes (OH_Pasteboard * pasteboard, unsigned int * count)
```
**描述：**

获取剪切板中的MIME类型。

**起始版本：** 14

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| pasteboard | 表示指向剪贴板[OH_Pasteboard](#oh_pasteboard)实例的指针。  |
| count | 该参数是输出参数，结果集中的类型数量会写入该变量。  |

**返回：**

执行成功时返回剪切板所有内容的MIME类型，否则返回nullptr。

本接口返回对象的生命周期由入参对象pasteboard管理，应用调用[OH_Pasteboard_Destroy](#oh_pasteboard_destroy)销毁入参对象pasteboard时同步释放本接口返回的结果，不允许应用主动释放。

入参对象pasteboard只保存本接口最新返回的结果，接口历史调用获得的结果将失效。

**参见：**

[OH_Pasteboard](#oh_pasteboard)

### OH_Pasteboard_GetDataWithProgress()

```
OH_UdmfData* OH_Pasteboard_GetDataWithProgress(OH_Pasteboard* pasteboard, OH_Pasteboard_GetDataParams *params, int *status);
```

**描述：**

获取剪贴板的内容和进度，使用Promise异步回调。

**起始版本：** 15

**参数:**

| 名称       | 描述                                                         |
| ---------- | ------------------------------------------------------------ |
| pasteboard | 表示指向剪贴板[OH_Pasteboard](#oh_pasteboard)实例的指针。    |
| params     | 应用在使用剪贴板提供的文件拷贝能力的情况下需要的参数。定义详见[OH_Pasteboard_GetDataParams](#oh_pasteboard_getdataparams)。 |
| status     | 该参数是输出参数，表示执行的错误码。错误码定义详见[PASTEBOARD_ErrCode](#pasteboard_errcode)。 |

**返回：**

执行成功时返回统一数据对象**OH_UdmfData**实例的指针。否则返回空指针。
