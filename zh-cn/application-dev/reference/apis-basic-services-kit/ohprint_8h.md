# ohprint.h


## 概述

声明用于发现和连接打印机、从打印机打印文件、查询已添加打印机的列表及其中的打印机信息等API.

**库：** libohprint.so \@kit BasicServicesKit

**系统能力：** SystemCapability.Print.PrintFramework

**起始版本：** 12

**相关模块：**[OH_Print](_o_h___print.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [Print_Margin](_print___margin.md) | 打印边距.  | 
| struct  [Print_PageSize](_print___page_size.md) | 纸张大小信息.  | 
| struct  [Print_Range](_print___range.md) | 打印范围.  | 
| struct  [Print_PrintAttributes](_print___print_attributes.md) | 打印属性结构体.  | 
| struct  [Print_PrintDocCallback](_print___print_doc_callback.md) | 打印文档任务回调结构体.  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef void(\* [Print_WriteResultCallback](_o_h___print.md#print_writeresultcallback)) (const char \*jobId, uint32_t code) | 文件回写回调.  | 
| typedef void(\* [Print_OnStartLayoutWrite](_o_h___print.md#print_onstartlayoutwrite)) (const char \*jobId, uint32_t fd, const [Print_PrintAttributes](_print___print_attributes.md) \*oldAttrs, const [Print_PrintAttributes](_print___print_attributes.md) \*newAttrs, [Print_WriteResultCallback](_o_h___print.md#print_writeresultcallback) writeCallback) | 文件开始回写回调函数.  | 
| typedef void(\* [Print_OnJobStateChanged](_o_h___print.md#print_onjobstatechanged)) (const char \*jobId, uint32_t state) | 打印任务状态回调.  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [Print_ErrorCode](_o_h___print.md#print_errorcode) {<br/>[PRINT_ERROR_NONE](_o_h___print.md) = 0, [PRINT_ERROR_NO_PERMISSION](_o_h___print.md) = 201, [PRINT_ERROR_INVALID_PARAMETER](_o_h___print.md) = 401, [PRINT_ERROR_GENERIC_FAILURE](_o_h___print.md) = 24300001,<br/>[PRINT_ERROR_RPC_FAILURE](_o_h___print.md) = 24300002, [PRINT_ERROR_SERVER_FAILURE](_o_h___print.md) = 24300003, [PRINT_ERROR_INVALID_EXTENSION](_o_h___print.md) = 24300004, [PRINT_ERROR_INVALID_PRINTER](_o_h___print.md) = 24300005,<br/>[PRINT_ERROR_INVALID_PRINT_JOB](_o_h___print.md) = 24300006, [PRINT_ERROR_FILE_IO](_o_h___print.md) = 24300007, [PRINT_ERROR_UNKNOWN](_o_h___print.md) = 24300255<br/>} | 枚举错误码.  | 
| [Print_JobDocAdapterState](_o_h___print.md#print_jobdocadapterstate) {<br/>[PRINT_DOC_ADAPTER_PREVIEW_ABILITY_DESTROY](_o_h___print.md) = 0, [PRINT_DOC_ADAPTER_PRINT_TASK_SUCCEED](_o_h___print.md) = 1, [PRINT_DOC_ADAPTER_PRINT_TASK_FAIL](_o_h___print.md) = 2, [PRINT_DOC_ADAPTER_PRINT_TASK_CANCEL](_o_h___print.md) = 3,<br/>[PRINT_DOC_ADAPTER_PRINT_TASK_BLOCK](_o_h___print.md) = 4, [PRINT_DOC_ADAPTER_PREVIEW_ABILITY_DESTROY_FOR_CANCELED](_o_h___print.md) = 5, [PRINT_DOC_ADAPTER_PREVIEW_ABILITY_DESTROY_FOR_STARTED](_o_h___print.md) = 6<br/>} | 打印文档任务的状态.  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [Print_ErrorCode](_o_h___print.md#print_errorcode)[OH_Print_StartPrintByNative](_o_h___print.md#oh_print_startprintbynative) (const char \*printJobName, [Print_PrintDocCallback](_print___print_doc_callback.md) printDocCallback, void \*context) | 拉起打印预览界面接口.  | 
