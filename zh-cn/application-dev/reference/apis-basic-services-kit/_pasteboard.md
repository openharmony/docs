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


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [Pasteboard_NotifyType](#pasteboard_notifytype) { NOTIFY_LOCAL_DATA_CHANGE = 1, NOTIFY_REMOTE_DATA_CHANGE = 2 } | 剪贴板的数据变更类型。  | 
| [PASTEBOARD_ErrCode](#pasteboard_errcode) {<br/>ERR_OK = 0, ERR_PERMISSION_ERROR = 201, ERR_INVALID_PARAMETER = 401, ERR_DEVICE_NOT_SUPPORTED = 801,<br/>ERR_INNER_ERROR = 12900000, ERR_BUSY = 12900003<br/>} | 错误码信息。  | 


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
| ERR_OK  | 执行成功。  || 
| ERR_PERMISSION_ERROR  | 权限校验失败。  || 
| ERR_INVALID_PARAMETER  | 非法参数。  || 
| ERR_DEVICE_NOT_SUPPORTED  | 设备能力不支持。  || 
| ERR_INNER_ERROR  | 内部错误。  || 
| ERR_BUSY  | 系统忙。  || 


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
