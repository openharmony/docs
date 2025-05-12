# ohprint.h


## Overview

Declares APIs for discovering and connecting to printers, printing files, and querying the list of added printers and printer information.

**Library**: libohprint.so \@kit BasicServicesKit

**System capability**: SystemCapability.Print.PrintFramework

**Since**: 12

**Related module**: [OH_Print](_o_h___print.md)


## Summary


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
| typedef void(\* [Print_WriteResultCallback](_o_h___print.md#print_writeresultcallback)) (const char \*jobId, uint32_t code) | Defines a callback used to return the file write-back result. | 
| typedef void(\* [Print_OnStartLayoutWrite](_o_h___print.md#print_onstartlayoutwrite)) (const char \*jobId, uint32_t fd, const [Print_PrintAttributes](_print___print_attributes.md) \*oldAttrs, const [Print_PrintAttributes](_print___print_attributes.md) \*newAttrs, [Print_WriteResultCallback](_o_h___print.md#print_writeresultcallback) writeCallback) | Defines a callback to be invoked when the file write-back starts. | 
| typedef void(\* [Print_OnJobStateChanged](_o_h___print.md#print_onjobstatechanged)) (const char \*jobId, uint32_t state) | Defines a callback used to return the print job state. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [Print_ErrorCode](_o_h___print.md#print_errorcode) {<br>PRINT_ERROR_NONE = 0, PRINT_ERROR_NO_PERMISSION = 201, PRINT_ERROR_INVALID_PARAMETER = 401, PRINT_ERROR_GENERIC_FAILURE = 24300001,<br>PRINT_ERROR_RPC_FAILURE = 24300002, PRINT_ERROR_SERVER_FAILURE = 24300003, PRINT_ERROR_INVALID_EXTENSION = 24300004, PRINT_ERROR_INVALID_PRINTER = 24300005,<br>PRINT_ERROR_INVALID_PRINT_JOB = 24300006, PRINT_ERROR_FILE_IO = 24300007, PRINT_ERROR_UNKNOWN = 24300255<br>} | Enumerates the error codes. | 
| [Print_JobDocAdapterState](_o_h___print.md#print_jobdocadapterstate) {<br>PRINT_DOC_ADAPTER_PREVIEW_ABILITY_DESTROY = 0, PRINT_DOC_ADAPTER_PRINT_TASK_SUCCEED = 1, PRINT_DOC_ADAPTER_PRINT_TASK_FAIL = 2, PRINT_DOC_ADAPTER_PRINT_TASK_CANCEL = 3,<br>PRINT_DOC_ADAPTER_PRINT_TASK_BLOCK = 4, PRINT_DOC_ADAPTER_PREVIEW_ABILITY_DESTROY_FOR_CANCELED = 5, PRINT_DOC_ADAPTER_PREVIEW_ABILITY_DESTROY_FOR_STARTED = 6<br>} | Enumerates the print job states. | 


### Functions

| Name| Description| 
| -------- | -------- |
| [Print_ErrorCode](_o_h___print.md#print_errorcode) [OH_Print_StartPrintByNative](_o_h___print.md#oh_print_startprintbynative) (const char \*printJobName, [Print_PrintDocCallback](_print___print_doc_callback.md) printDocCallback, void \*context) | Calls the API for opening the print preview page.| 
