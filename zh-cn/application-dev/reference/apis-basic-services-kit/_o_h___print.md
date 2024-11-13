# OH_Print


## 概述

提供打印模块的C接口定义。

**系统能力：** SystemCapability.Print.PrintFramework

**起始版本：** 12


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [ohprint.h](ohprint_8h.md) | 声明用于发现和连接打印机、从打印机打印文件、查询已添加打印机的列表及其中的打印机信息等API。  | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [Print_Margin](_print___margin.md) | 打印边距  | 
| struct  [Print_PageSize](_print___page_size.md) | 纸张大小信息。  | 
| struct  [Print_Range](_print___range.md) | 打印范围。  | 
| struct  [Print_PrintAttributes](_print___print_attributes.md) | 打印属性结构体。  | 
| struct  [Print_PrintDocCallback](_print___print_doc_callback.md) | 打印文档任务回调结构体。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef void(\* [Print_WriteResultCallback](#print_writeresultcallback)) (const char \*jobId, uint32_t code) | 文件回写回调。  | 
| typedef void(\* [Print_OnStartLayoutWrite](#print_onstartlayoutwrite)) (const char \*jobId, uint32_t fd, const [Print_PrintAttributes](_print___print_attributes.md) \*oldAttrs, const [Print_PrintAttributes](_print___print_attributes.md) \*newAttrs, [Print_WriteResultCallback](#print_writeresultcallback) writeCallback) | 文件开始回写回调函数。  | 
| typedef void(\* [Print_OnJobStateChanged](#print_onjobstatechanged)) (const char \*jobId, uint32_t state) | 打印任务状态回调。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [Print_ErrorCode](#print_errorcode) {<br/>PRINT_ERROR_NONE = 0, PRINT_ERROR_NO_PERMISSION = 201, PRINT_ERROR_INVALID_PARAMETER = 401, PRINT_ERROR_GENERIC_FAILURE = 24300001,<br/>PRINT_ERROR_RPC_FAILURE = 24300002, PRINT_ERROR_SERVER_FAILURE = 24300003, PRINT_ERROR_INVALID_EXTENSION = 24300004, PRINT_ERROR_INVALID_PRINTER = 24300005,<br/>PRINT_ERROR_INVALID_PRINT_JOB = 24300006, PRINT_ERROR_FILE_IO = 24300007, PRINT_ERROR_UNKNOWN = 24300255<br/>} | 枚举错误码。  | 
| [Print_JobDocAdapterState](#print_jobdocadapterstate) {<br/>PRINT_DOC_ADAPTER_PREVIEW_ABILITY_DESTROY = 0, PRINT_DOC_ADAPTER_PRINT_TASK_SUCCEED = 1, PRINT_DOC_ADAPTER_PRINT_TASK_FAIL = 2, PRINT_DOC_ADAPTER_PRINT_TASK_CANCEL = 3,<br/>PRINT_DOC_ADAPTER_PRINT_TASK_BLOCK = 4, PRINT_DOC_ADAPTER_PREVIEW_ABILITY_DESTROY_FOR_CANCELED = 5, PRINT_DOC_ADAPTER_PREVIEW_ABILITY_DESTROY_FOR_STARTED = 6<br/>} | 打印文档任务的状态。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [Print_ErrorCode](#print_errorcode)[OH_Print_StartPrintByNative](#oh_print_startprintbynative) (const char \*printJobName, [Print_PrintDocCallback](_print___print_doc_callback.md) printDocCallback, void \*context) | 拉起打印预览界面接口。  | 


## 类型定义说明


### Print_OnJobStateChanged

```
typedef void(* Print_OnJobStateChanged) (const char *jobId, uint32_t state)
```
**描述**
打印任务状态回调。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| jobId | 打印任务id。  | 
| state | 当前任务状态。  | 


### Print_OnStartLayoutWrite

```
typedef void(* Print_OnStartLayoutWrite) (const char *jobId, uint32_t fd, const Print_PrintAttributes *oldAttrs, const Print_PrintAttributes *newAttrs, Print_WriteResultCallback writeCallback)
```
**描述**
文件开始回写回调函数。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| jobId | 打印任务id。  | 
| fd | 回写的文件句柄。  | 
| oldAttrs | 用户设置打印参数变化前的参数。  | 
| newAttrs | 用户设置打印参数变化后的参数。  | 
| writeCallback | 使用方回写完文件后调用回调函数通知打印服务。  | 


### Print_WriteResultCallback

```
typedef void(* Print_WriteResultCallback) (const char *jobId, uint32_t code)
```
**描述**
文件回写回调。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| jobId | 打印任务id。  | 
| code | 文件回写结果。  | 


## 枚举类型说明


### Print_ErrorCode

```
enum Print_ErrorCode
```
**描述**
枚举错误码.

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| PRINT_ERROR_NONE  | 成功。   | 
| PRINT_ERROR_NO_PERMISSION  | 没有权限。   | 
| PRINT_ERROR_INVALID_PARAMETER  | 无效参数。   | 
| PRINT_ERROR_GENERIC_FAILURE  | 内部错误。   | 
| PRINT_ERROR_RPC_FAILURE  | rpc传输错误。   | 
| PRINT_ERROR_SERVER_FAILURE  | 打印服务错误。   | 
| PRINT_ERROR_INVALID_EXTENSION  | 无效打印扩展。   | 
| PRINT_ERROR_INVALID_PRINTER  | 无效打印机。   | 
| PRINT_ERROR_INVALID_PRINT_JOB  | 无效打印任务。   | 
| PRINT_ERROR_FILE_IO  | 文件读写错误。   | 
| PRINT_ERROR_UNKNOWN  | 未知错误。   | 


### Print_JobDocAdapterState

```
enum Print_JobDocAdapterState
```
**描述**
打印文档任务的状态。

**起始版本：** 13

| 枚举值 | 描述 | 
| -------- | -------- |
| PRINT_DOC_ADAPTER_PREVIEW_ABILITY_DESTROY  | 打印预览界面销毁。   | 
| PRINT_DOC_ADAPTER_PRINT_TASK_SUCCEED  | 打印任务执行成功。   | 
| PRINT_DOC_ADAPTER_PRINT_TASK_FAIL  | 打印任务执行失败。   | 
| PRINT_DOC_ADAPTER_PRINT_TASK_CANCEL  | 打印任务被取消。   | 
| PRINT_DOC_ADAPTER_PRINT_TASK_BLOCK  | 打印任务阻塞。   | 
| PRINT_DOC_ADAPTER_PREVIEW_ABILITY_DESTROY_FOR_CANCELED  | 预览界面点击取消按钮界面退出。   | 
| PRINT_DOC_ADAPTER_PREVIEW_ABILITY_DESTROY_FOR_STARTED  | 预览界面点击打印按钮界面退出。   | 


## 函数说明


### OH_Print_StartPrintByNative()

```
Print_ErrorCode OH_Print_StartPrintByNative (const char * printJobName, Print_PrintDocCallback printDocCallback, void * context )
```
**描述**
拉起打印预览界面接口。

**系统能力：** SystemCapability.Print.PrintFramework

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| printJobName | 打印任务名称。  | 
| printDocCallback | 打印文档任务回调结构体。  | 
| context | 调用接口的ability的上下文。  | 

**Permission：**

ohos.permission.PRINT

**返回：**

Print_ErrorCode#PRINT_ERROR_NONE：执行成功。

PRINT_ERROR_NO_PERMISSION：需要配置ohos.permission.PRINT权限。

PRINT_ERROR_RPC_FAILURE：无法连接打印服务。
