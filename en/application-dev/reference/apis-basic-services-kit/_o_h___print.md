# OH_Print


## Overview

Provides the C APIs definition of the print module.

**System capability**: SystemCapability.Print.PrintFramework

**Since**: 12


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [ohprint.h](ohprint_8h.md) | Declares APIs for discovering and connecting to printers, printing files, and querying the list of added printers and printer information. |


### Structs

| Name| Description|
| -------- | -------- |
| struct  [Print_Margin](_print___margin.md) | Defines the page margin. |
| struct  [Print_PageSize](_print___page_size.md) | Defines the page size. |
| struct  [Print_Range](_print___range.md) | Defines the page range. |
| struct  [Print_PrintAttributes](_print___print_attributes.md) | Defines the print attributes. |
| struct  [Print_PrintDocCallback](_print___print_doc_callback.md) | Defines the print job callback. |


### Types

| Name| Description|
| -------- | -------- |
| typedef void(\* [Print_WriteResultCallback](#print_writeresultcallback)) (const char \*jobId, uint32_t code) | Defines a callback used to return the file write-back result. |
| typedef void(\* [Print_OnStartLayoutWrite](#print_onstartlayoutwrite)) (const char \*jobId, uint32_t fd, const [Print_PrintAttributes](_print___print_attributes.md) \*oldAttrs, const [Print_PrintAttributes](_print___print_attributes.md) \*newAttrs, [Print_WriteResultCallback](#print_writeresultcallback) writeCallback) | Defines a callback to be invoked when the file write-back starts. |
| typedef void(\* [Print_OnJobStateChanged](#print_onjobstatechanged)) (const char \*jobId, uint32_t state) | Defines a callback used to return the print job state. |


### Enums

| Name| Description|
| -------- | -------- |
| [Print_ErrorCode](#print_errorcode) {<br>PRINT_ERROR_NONE = 0, PRINT_ERROR_NO_PERMISSION = 201, PRINT_ERROR_INVALID_PARAMETER = 401, PRINT_ERROR_GENERIC_FAILURE = 24300001,<br>PRINT_ERROR_RPC_FAILURE = 24300002, PRINT_ERROR_SERVER_FAILURE = 24300003, PRINT_ERROR_INVALID_EXTENSION = 24300004, PRINT_ERROR_INVALID_PRINTER = 24300005,<br>PRINT_ERROR_INVALID_PRINT_JOB = 24300006, PRINT_ERROR_FILE_IO = 24300007, PRINT_ERROR_UNKNOWN = 24300255<br>} | Enumerates the error codes. |
| [Print_JobDocAdapterState](#print_jobdocadapterstate) {<br>PRINT_DOC_ADAPTER_PREVIEW_ABILITY_DESTROY = 0, PRINT_DOC_ADAPTER_PRINT_TASK_SUCCEED = 1, PRINT_DOC_ADAPTER_PRINT_TASK_FAIL = 2, PRINT_DOC_ADAPTER_PRINT_TASK_CANCEL = 3,<br>PRINT_DOC_ADAPTER_PRINT_TASK_BLOCK = 4, PRINT_DOC_ADAPTER_PREVIEW_ABILITY_DESTROY_FOR_CANCELED = 5, PRINT_DOC_ADAPTER_PREVIEW_ABILITY_DESTROY_FOR_STARTED = 6<br>} | Enumerates the print job states. |


### Functions

| Name| Description|
| -------- | -------- |
| [Print_ErrorCode](#print_errorcode) [OH_Print_StartPrintByNative](#oh_print_startprintbynative) (const char \*printJobName, [Print_PrintDocCallback](_print___print_doc_callback.md) printDocCallback, void \*context) | Calls the API for opening the print preview page. |


## Type Description


### Print_OnJobStateChanged

```
typedef void(* Print_OnJobStateChanged) (const char *jobId, uint32_t state)
```
**Description**
Defines a callback used to return the print job state.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| jobId | Print job ID. |
| state | Current job state. |


### Print_OnStartLayoutWrite

```
typedef void(* Print_OnStartLayoutWrite) (const char *jobId, uint32_t fd, const Print_PrintAttributes *oldAttrs, const Print_PrintAttributes *newAttrs, Print_WriteResultCallback writeCallback)
```
**Description**
Defines a callback to be invoked when the file write-back starts.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| jobId | Print job ID. |
| fd | File handle for write-back. |
| oldAttrs | Print parameter before change. |
| newAttrs | Print parameter after change. |
| writeCallback | Callback to be invoked when the file write-back finishes. |


### Print_WriteResultCallback

```
typedef void(* Print_WriteResultCallback) (const char *jobId, uint32_t code)
```
**Description**
Defines a callback used to return the file write-back result.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| jobId | Print job ID. |
| code | File writeback result. |


## Enum Description


### Print_ErrorCode

```
enum Print_ErrorCode
```
**Description**
Enumerates the error codes.

**Since**: 12

| Value| Description|
| -------- | -------- |
| PRINT_ERROR_NONE  | Success.  |
| PRINT_ERROR_NO_PERMISSION  | Permission denied.  |
| PRINT_ERROR_INVALID_PARAMETER  | Invalid parameter.  |
| PRINT_ERROR_GENERIC_FAILURE  | Internal error.  |
| PRINT_ERROR_RPC_FAILURE  | RPC transmission failed.  |
| PRINT_ERROR_SERVER_FAILURE  | Print service failed.  |
| PRINT_ERROR_INVALID_EXTENSION  | Invalid print extension.  |
| PRINT_ERROR_INVALID_PRINTER  | Invalid printer.  |
| PRINT_ERROR_INVALID_PRINT_JOB  | Invalid print job.  |
| PRINT_ERROR_FILE_IO  | File I/O error.  |
| PRINT_ERROR_UNKNOWN  | Unknown error.  |


### Print_JobDocAdapterState

```
enum Print_JobDocAdapterState
```
**Description**
Enumerates the print job states.

**Since**: 13

| Value| Description|
| -------- | -------- |
| PRINT_DOC_ADAPTER_PREVIEW_ABILITY_DESTROY  | Print preview page destroyed.  |
| PRINT_DOC_ADAPTER_PRINT_TASK_SUCCEED  | Print job succeeded.  |
| PRINT_DOC_ADAPTER_PRINT_TASK_FAIL  | Print job failed.  |
| PRINT_DOC_ADAPTER_PRINT_TASK_CANCEL  | Print job canceled.  |
| PRINT_DOC_ADAPTER_PRINT_TASK_BLOCK  | Print job blocked.  |
| PRINT_DOC_ADAPTER_PREVIEW_ABILITY_DESTROY_FOR_CANCELED  | Print preview page destroyed by clicking the cancel button.  |
| PRINT_DOC_ADAPTER_PREVIEW_ABILITY_DESTROY_FOR_STARTED  | Print preview page destroyed by clicking the print button.  |


## Function Description


### OH_Print_StartPrintByNative()

```
Print_ErrorCode OH_Print_StartPrintByNative (const char * printJobName, Print_PrintDocCallback printDocCallback, void * context )
```
**Description**
Calls the API for opening the print preview page.

**System capability**: SystemCapability.Print.PrintFramework

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| printJobName | Print job name. |
| printDocCallback | Print job callback struct. |
| context | Context of the ability that calls the API. |

**Required Permissions**

ohos.permission.PRINT

**Returns**

**Print_ErrorCode#PRINT_ERROR_NONE**: The operation is successful.

**PRINT_ERROR_NO_PERMISSION**: The ohos.permission.PRINT permission must be declared.

**PRINT_ERROR_RPC_FAILURE**: Failed to connect to the print service.
