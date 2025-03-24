# OH_Scan


## Overview

Enables applications to use CAPI to access scanners.

**Since**: 12


## Summary


### Types

| Name| Description|
| -------- | -------- |
| Scan_ScannerDevice | Device information of a scanner.|
| Scan_PictureScanProgress | Image scanning progress.|
| Scan_ScannerOptions | Scanner options.|
| Scan_ScannerDiscoveryCallback | Callback function for scanner discovery.|


### Enums

| Name| Description|
| -------- | -------- |
| Scan_ErrorCode | Enumerates the error codes.|


### Functions

| Name| Description|
| -------- | -------- |
| OH_Scan_Init | Starts the scanning service, initializes the client, and establishes a connection with the scanning service.|
| OH_Scan_StartScannerDiscovery | Searches for scanners and registers a callback function to process the found scanners.|
| OH_Scan_OpenScanner | Connects to a scanner.|
| OH_Scan_CloseScanner | Disconnects from the scanner.|
| OH_Scan_GetScannerParameter | Obtains scanner settings.|
| OH_Scan_SetScannerParameter | Sets the option parameters of the scanner.|
| OH_Scan_StartScan | Starts the scanner.|
| OH_Scan_CancelScan | Cancels scanning.|
| OH_Scan_GetPictureScanProgress | Queries the image scanning progress.|
| OH_Scan_Exit | Exits the scanning service and releases the client memory.|


## Type Description


### Scan_ScannerDevice

**Description**

Device information of a scanner.

**Since**: 12

| Member        | Description    |
| ------------ | -------- |
| scannerId    | Scanner ID.|
| manufacturer | Manufacturer.  |
| model        | Device model.|
| discoverMode | Device discovery mode|
| serialNumber | Serial number.  |

### Scan_PictureScanProgress

**Description**

Image scanning progress.

**Since**: 12

| Member    | Description                   |
| -------- | ----------------------- |
| progress | Image scanning progress. The value ranges from 0 to 100.|
| fd       | Image handle.           |
| isFinal  | Whether the next image is available.       |

### Scan_ScannerOptions

**Description**

Scanner options.

**Since**: 12

| Member        | Description        |
| ------------ | ------------ |
| titles       | Option title.    |
| descriptions | Option description.|
| ranges       | Option range.    |
| optionCount  | Number of options.    |

### Scan_ScannerDiscoveryCallback

**Description**

Callback function for scanner discovery.

**Since**: 12

| Parameter       | Description      |
| ----------- | ---------- |
| devices     | Scanner.|
| deviceCount | Number of scanners.  |

## Enum Description


### Scan_ErrorCode

**Description**

Enumerates the error codes.

**Since**: 12

| Value| Description|
| -------- | -------- |
| SCAN_ERROR_NONE | Operation succeeded.|
| SCAN_ERROR_NO_PERMISSION | Permission denied.|
| SCAN_ERROR_INVALID_PARAMETER | Invalid parameter.|
| SCAN_ERROR_GENERIC_FAILURE | Internal error.|
| SCAN_ERROR_RPC_FAILURE | PRC communication error.|
| SCAN_ERROR_SERVER_FAILURE | Server error.|
| SCAN_ERROR_UNSUPPORTED | Operation is not supported.|
| SCAN_ERROR_CANCELED | Operation canceled.|
| SCAN_ERROR_DEVICE_BUSY | Device is busy.|
| SCAN_ERROR_INVALID | Invalid operation.|
| SCAN_ERROR_JAMMED | Paper jammed at the paper feeder.|
| SCAN_ERROR_NO_DOCS | Out of paper.|
| SCAN_ERROR_COVER_OPEN | The cover of the scanner is opened.|
| SCAN_ERROR_IO_ERROR | Scanner I/O operation error.|
| SCAN_ERROR_NO_MEMORY | Insufficient memory.|


## Function Description


### OH_Scan_Init()

```cpp
int32_t OH_Scan_Init();
```

**Description**

Starts the scanning service, initializes the client, and establishes a connection with the scanning service.

**System capability**: ohos.permission.PRINT

**Since**: 12

**Returns**

**Scan_ERROR_NONE**: Operation is succeeded.

**SCAN_ERROR_NO_PERMISSION**: Permission is denied.

**SCAN_ERROR_RPC_FAILURE**: An RPC communication error occurs.

**SCAN_ERROR_SERVER_FAILURE**: A server exception occurs.

### OH_Scan_StartScannerDiscovery()

```cpp
int32_t OH_Scan_StartScannerDiscovery(Scan_ScannerDiscoveryCallback callback);
```

**Description**

Searches for scanners and registers a callback function to process the found scanners.

**System capability**: ohos.permission.PRINT

**Since**: 12

**Parameters**

| Name    | Description                      |
| -------- | -------------------------- |
| callback | Callback function for scanner discovery.|

**Returns**

**Scan_ERROR_NONE**: Operation is succeeded.

**SCAN_ERROR_NO_PERMISSION**: Permission is denied.

**SCAN_ERROR_RPC_FAILURE**: An RPC communication error occurs.

**SCAN_ERROR_SERVER_FAILURE**: A server exception occurs.

### OH_Scan_OpenScanner()

```cpp
int32_t OH_Scan_OpenScanner(const char* scannerId);
```

**Description**

Connects to a scanner.

**System capability**: ohos.permission.PRINT

**Since**: 12

**Parameters**

| Name     | Description      |
| --------- | ---------- |
| scannerId | Scanner ID.|

**Returns**

**Scan_ERROR_NONE**: Operation is succeeded.

**SCAN_ERROR_NO_PERMISSION**: Permission is denied.

**SCAN_ERROR_RPC_FAILURE**: An RPC communication error occurs.

**SCAN_ERROR_SERVER_FAILURE**: A server exception occurs.

**SCAN_ERROR_DEVICE_BUSY**: The scanner is busy.

**SCAN_ERROR_INVALID_PARAMETER**: The parameter is invalid.

**SCAN_ERROR_IO_ERROR**: An I/O operation error occurs on the scanner.

**SCAN_ERROR_NO_MEMORY**: The scanner memory is insufficient.

### OH_Scan_CloseScanner()

```cpp
int32_t OH_Scan_CloseScanner(const char* scannerId);
```

**Description**

Disconnects from a scanner.

**System capability**: ohos.permission.PRINT

**Since**: 12

**Parameters**

| Name     | Description      |
| --------- | ---------- |
| scannerId | Scanner ID.|

**Returns**

**Scan_ERROR_NONE**: Operation is succeeded.

**SCAN_ERROR_NO_PERMISSION**: Permission is denied.

**SCAN_ERROR_RPC_FAILURE**: An RPC communication error occurs.

**SCAN_ERROR_SERVER_FAILURE**: A server exception occurs.

**SCAN_ERROR_INVALID_PARAMETER**: The parameter is invalid.

### OH_Scan_GetScannerParameter()

```cpp
Scan_ScannerOptions* OH_Scan_GetScannerParameter(const char* scannerId, int32_t* errorCode);
```

**Description**

Obtains the scanner setting options. The memory is automatically released when returned structure points to {@link OH_Scan_Exit}. Only one copy of each scanner model is stored in the memory.

**System capability**: ohos.permission.PRINT

**Since**: 12

**Parameters**

| Name     | Description      |
| --------- | ---------- |
| scannerId | Scanner ID.|
| errorCode | Error code.    |

**Returns**

**Scan_ERROR_NONE**: Operation is succeeded.

**SCAN_ERROR_NO_PERMISSION**: Permission is denied.

**SCAN_ERROR_RPC_FAILURE**: An RPC communication error occurs.

**SCAN_ERROR_SERVER_FAILURE**: A server exception occurs.

### OH_Scan_SetScannerParameter()

```cpp
int32_t OH_Scan_SetScannerParameter(const char* scannerId, const int32_t option, const char* value);
```

**Description**

Sets the option parameters of the scanner. The option values are obtained through the {@link OH_Scan_GetScannerParameter} API.

**System capability**: ohos.permission.PRINT

**Since**: 12

**Parameters**

| Name     | Description      |
| --------- | ---------- |
| scannerId | Scanner ID.|
| option    | Option Number.  |
| value     | Option value.    |

**Returns**

**Scan_ERROR_NONE**: Operation is succeeded.

**SCAN_ERROR_NO_PERMISSION**: Permission is denied.

**SCAN_ERROR_RPC_FAILURE**: An RPC communication error occurs.

**SCAN_ERROR_SERVER_FAILURE**: A server exception occurs.

**SCAN_ERROR_INVALID_PARAMETER**: The parameter is invalid.

### OH_Scan_StartScan()

```cpp
int32_t OH_Scan_StartScan(const char* scannerId, bool batchMode);
```

**Description**

Starts a scanner.

**System capability**: ohos.permission.PRINT

**Since**: 12

**Parameters**

| Name     | Description      |
| --------- | ---------- |
| scannerId | Scanner ID.|
| batchMode | Batch processing mode.|

**Returns**

**Scan_ERROR_NONE**: Operation is succeeded.
**SCAN_ERROR_NO_PERMISSION**: Permission is denied.

**SCAN_ERROR_RPC_FAILURE**: An RPC communication error occurs.

**SCAN_ERROR_SERVER_FAILURE**: A server exception occurs.

**SCAN_ERROR_INVALID_PARAMETER**: The parameter is invalid.

**SCAN_ERROR_JAMMED**: Paper jammed at the paper feeder.

**SCAN_ERROR_NO_DOCS**: The scanner is out of paper.

**SCAN_ERROR_COVER_OPEN**: The cover of the scanner is opened.

**SCAN_ERROR_IO_ERROR**: An I/O operation exception occurs on the scanner.

**SCAN_ERROR_NO_MEMORY**: The scanner memory is insufficient.

**SCAN_ERROR_DEVICE_BUSY**: The scanner is busy.

### OH_Scan_CancelScan()

```cpp
int32_t OH_Scan_CancelScan(const char* scannerId);
```

**Description**

Cancels scanning.

**System capability**: ohos.permission.PRINT

**Since**: 12

**Parameters**

| Name     | Description      |
| --------- | ---------- |
| scannerId | Scanner ID.|

**Returns**

**Scan_ERROR_NONE**: Operation is succeeded.

**SCAN_ERROR_NO_PERMISSION**: Permission is denied.

**SCAN_ERROR_RPC_FAILURE**: An RPC communication error occurs.

**SCAN_ERROR_SERVER_FAILURE**: A server exception occurs.

**SCAN_ERROR_INVALID_PARAMETER**: The parameter is invalid.

### OH_Scan_GetPictureScanProgress()

```cpp
int32_t OH_Scan_GetPictureScanProgress(const char* scannerId, Scan_PictureScanProgress* prog);
```

**Description**

Queries the image scanning progress.

**System capability**: ohos.permission.PRINT

**Since**: 12

**Parameters**

| Name     | Description        |
| --------- | ------------ |
| scannerId | Scanner ID.  |
| prog      | Image scanning progress.|

**Returns**

**Scan_ERROR_NONE**: Operation is succeeded.

**SCAN_ERROR_NO_PERMISSION**: Permission is denied.

**SCAN_ERROR_RPC_FAILURE**: An RPC communication error occurs.

**SCAN_ERROR_SERVER_FAILURE**: A server exception occurs.

**SCAN_ERROR_INVALID_PARAMETER**: The parameter is invalid.

**SCAN_ERROR_JAMMED**: Paper jammed at the paper feeder.

**SCAN_ERROR_NO_DOCS**: The scanner is out of paper.

**SCAN_ERROR_COVER_OPEN**: The cover of the scanner is opened.

**SCAN_ERROR_IO_ERROR**: An I/O operation exception occurs on the scanner.

**SCAN_ERROR_NO_MEMORY**: The scanner memory is insufficient.

**SCAN_ERROR_DEVICE_BUSY**: The scanner is busy.

### OH_Scan_Exit()

```cpp
int32_t OH_Scan_Exit();
```

**Description**

Exits the scanning service, clear the client memory, and cancel the registered scanning callback function.

**System capability**: ohos.permission.PRINT

**Since**: 12

**Returns**

**Scan_ERROR_NONE**: Operation is succeeded.

**SCAN_ERROR_NO_PERMISSION**: Permission is denied.

**SCAN_ERROR_RPC_FAILURE**: An RPC communication error occurs.

**SCAN_ERROR_SERVER_FAILURE**: A server exception occurs.

**SCAN_ERROR_INVALID_PARAMETER**: The parameter is invalid.
