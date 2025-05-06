# OH_Print

## Overview

Provides applications with the ability to access the printing system using CAPI.

**Since:** 12

## Summary

### Type Definitions

| Name | Description |
| -------- | -------- |
| [Print_StringList](#print_stringlist) | Printer device list. |
| [Print_Property](#print_property) | Printer property. |
| [Print_PropertyList](#print_propertylist) | Printer property list. |
| [Print_Resolution](#print_resolution) | Print resolution unit. |
| [Print_Margin](#print_margin) | Print margin. |
| [Print_PageSize](#print_pagesize) | Print paper size. |
| [Print_PrinterCapability](#print_printercapability) | Printer capability. |
| [Print_DefaultValue](#print_defaultvalue) | Print default information. |
| [Print_PrinterInfo](#print_printerinfo) | Printer information. |
| [Print_PrintJob](#print_printjob) | Print job. |
| [Print_Range](#print_range) | Print range. |
| [Print_PrintAttributes](#print_printattributes) | Print attributes. |
| [Print_WriteResultCallback](#print_writeresultcallback) | Write result callback. |
| [Print_OnStartLayoutWrite](#print_onstartlayoutwrite) | Start layout callback. |
| [Print_OnJobStateChanged](#print_onjobstatechanged) | Print job state callback. |
| [Print_PrintDocCallback](#print_printdoccallback) | Print document state callback. |
| [Print_PrinterDiscoveryCallback](#print_printerdiscoverycallback) | Printer discovery callback. |
| [Print_PrinterChangeCallback](#print_printerchangecallback) | Printer state change callback. |

### Enumerations

| Name | Description |
| -------- | -------- |
| [Print_ErrorCode](#print_errorcode) | Error codes. |
| [Print_PrinterState](#print_printerstate) | Printer state codes. |
| [Print_DiscoveryEvent](#print_discoveryevent) | Printer discovery events. |
| [Print_PrinterEvent](#print_printerevent) | Printer state change events. |
| [Print_DuplexMode](#print_duplexmode) | Print duplex mode. |
| [Print_ColorMode](#print_colormode) | Print color mode. |
| [Print_OrientationMode](#print_orientationmode) | Print orientation. |
| [Print_Quality](#print_quality) | Print quality. |
| [Print_DocumentFormat](#print_documentformat) | Printer document format. |
| [Print_JobDocAdapterState](#print_jobdocadapterstate) | Print job state. |

### Functions

| Name | Description |
| -------- | -------- |
| [OH_Print_Init](#oh_print_init) | Starts the print service, initializes the print client, and establishes a connection to the print service. |
| [OH_Print_Release](#oh_print_release) | Closes the connection to the print service, unregisters callbacks, and releases print client resources. |
| [OH_Print_StartPrinterDiscovery](#oh_print_startprinterdiscovery) | Starts printer discovery. |
| [OH_Print_StopPrinterDiscovery](#oh_print_stopprinterdiscovery) | Stops printer discovery. |
| [OH_Print_ConnectPrinter](#oh_print_connectprinter) | Connects to a printer using the printer ID. |
| [OH_Print_StartPrintJob](#oh_print_startprintjob) | Starts a print job. |
| [OH_Print_RegisterPrinterChangeListener](#oh_print_registerprinterchangelistener) | Registers a printer state change event listener. |
| [OH_Print_UnregisterPrinterChangeListener](#oh_print_unregisterprinterchangelistener) | Unregisters the printer state change event listener. |
| [OH_Print_QueryPrinterList](#oh_print_queryprinterlist) | Queries the printer list. |
| [OH_Print_ReleasePrinterList](#oh_print_releaseprinterlist) | Releases the printer list. |
| [OH_Print_QueryPrinterInfo](#oh_print_queryprinterinfo) | Queries printer information. |
| [OH_Print_ReleasePrinterInfo](#oh_print_releaseprinterinfo) | Releases printer information memory. |
| [OH_Print_LaunchPrinterManager](#oh_print_launchprintermanager) | Launches the printer manager window. |
| [OH_Print_QueryPrinterProperties](#oh_print_queryprinterproperties) | Queries printer properties. |
| [OH_Print_ReleasePrinterProperties](#oh_print_releaseprinterproperties) | Releases printer properties. |
| [OH_Print_UpdatePrinterProperties](#oh_print_updateprinterproperties) | Updates printer properties. |
| [OH_Print_RestorePrinterProperties](#oh_print_restoreprinterproperties) | Restores printer properties to default settings based on the property key list. |
| [OH_Print_StartPrintByNative](#oh_print_startprintbynative) | Starts printing. |

## Type Definitions

### Print_StringList

**Description**

Printer device list.

**Since:** 12

| Member | Description |
| ------------ | -------- |
| count    | Number of strings. |
| list | String pointer array.   |

### Print_Property

**Description**

Printer property.

**Since:** 12

| Member | Description |
| -------- | ----------------------- |
| key | Property key. |
| value | Property value. |

### Print_PropertyList

**Description**

Printer property list.

**Since:** 12

| Member | Description |
| ------------ | ------------ |
| count | Number of properties. |
| list | Property pointer array. |

### Print_Resolution

**Description**

Print resolution unit.

**Since:** 12

| Parameter | Description |
| ----------- | ---------- |
| horizontalDpi | Horizontal resolution (dpi). |
| verticalDpi | Vertical resolution (dpi). |

### Print_Margin

**Description**

Print margin.

**Since:** 12

| Parameter | Description |
| ----------- | ---------- |
| leftMargin | Left margin (microns). |
| topMargin | Top margin (microns). |
| rightMargin | Right margin (microns). |
| bottomMargin | Bottom margin (microns). |

### Print_PageSize

**Description**

Print paper size.

**Since:** 12

| Parameter | Description |
| ----------- | ---------- |
| id | Paper ID. |
| name | Paper name. |
| width | Paper width (microns). |
| height | Paper height (microns). |

### Print_PrinterCapability

**Description**

Printer capability.

**Since:** 12

| Parameter | Description |
| ----------- | ---------- |
| supportedColorModes | Supported color modes list. |
| supportedColorModesCount | Number of supported color modes. |
| supportedDuplexModes | Supported duplex modes list. |
| supportedDuplexModesCount | Number of supported duplex modes. |
| supportedPageSizes | Supported paper sizes list. |
| supportedPageSizesCount | Number of supported paper sizes. |
| supportedMediaTypes | Supported media types (JSON string array format). |
| supportedQualities | Supported print qualities list. |
| supportedQualitiesCount | Number of supported print qualities. |
| supportedPaperSources | Supported paper sources (JSON string array format). |
| supportedCopies | Maximum supported copies. |
| supportedResolutions | Supported resolutions list. |
| supportedResolutionsCount | Number of supported resolutions. |
| supportedOrientations | Supported orientations list. |
| supportedOrientationsCount | Number of supported orientations. |
| advancedCapability | Advanced capability (JSON format). |

### Print_DefaultValue

**Description**

Printer default information.

**Since:** 12

| Parameter | Description |
| ----------- | ---------- |
| defaultColorMode | Default color mode. |
| defaultDuplexMode | Default duplex mode. |
| defaultMediaType | Default media type. |
| defaultPageSizeId | Default paper size ID. |
| defaultMargin | Default margin. |
| defaultPaperSource | Default paper source. |
| defaultPrintQuality | Default print quality. |
| defaultCopies | Default number of copies. |
| defaultResolution | Default resolution. |
| defaultOrientation | Default orientation. |
| otherDefaultValues | Other default values (JSON format). |

### Print_PrinterInfo

**Description**

Printer information.

**Since:** 12

| Parameter | Description |
| ----------- | ---------- |
| printerState | Printer state. |
| capability | Printer capability. |
| defaultValue | Printer default properties. |
| isDefaultPrinter | Whether it is the default printer. |
| printerId | Printer ID. |
| printerName | Printer name. |
| description | Printer description. |
| location | Printer location. |
| makeAndModel | Printer manufacturer and model information. |
| printerUri | Printer URI. |
| detailInfo | Detailed information (JSON format). |

### Print_PrintJob

**Description**

Print job.

**Since:** 12

| Parameter | Description |
| ----------- | ---------- |
| jobName | Print job name. |
| fdList | Print file descriptor array. |
| fdListCount | Number of print file descriptors. |
| printerId | Printer ID. |
| copyNumber | Number of copies. |
| paperSource | Paper source. |
| mediaType | Media type. |
| pageSizeId | Paper size ID. |
| colorMode | Color mode. |
| duplexMode | Duplex mode. |
| resolution | Resolution. |
| printMargin | Print margin. |
| borderless | Whether to print borderless. |
| orientationMode | Print orientation. |
| printQuality | Print quality. |
| documentFormat | Document format. |
| advancedOptions | Advanced options (JSON format). |

### Print_Range

**Description**

Print range.

**Since:** 13

| Parameter | Description |
| ----------- | ---------- |
| startPage | Start page number. |
| endPage | End page number. |
| pagesArrayLen | Page array length. |
| pagesArray | Page array. |

### Print_PrintAttributes

**Description**

Print attributes.

**Since:** 13

| Parameter | Description |
| ----------- | ---------- |
| pageRange | Print range. |
| pageSize | Paper size. |
| pageMargin | Page margin. |
| copyNumber | Number of copies. |
| duplexMode | Duplex mode. |
| colorMode | Color mode. |
| isSequential | Whether to print sequentially. |
| isLandscape | Whether to print in landscape. |
| hasOption | Whether there are print options. |
| options | Print options (256 bytes). |

### Print_WriteResultCallback

**Description**

Write result callback.

**Since:** 13

**Parameters:**

| Name | Description |
| --------- | ---------- |
| jobId | Print job ID. |
| code | Write result status code. |

### Print_OnStartLayoutWrite

**Description**

Start layout callback.

**Since:** 13

**Parameters:**

| Name | Description |
| --------- | ---------- |
| jobId | Print job ID. |
| fd | File descriptor. |
| oldAttrs | Previous print attributes. |
| newAttrs | Current print attributes. |
| writeCallback | Write result callback function. |

### Print_OnJobStateChanged

**Description**

Print job state change callback.

**Since:** 13

**Parameters:**

| Name | Description |
| --------- | ---------- |
| jobId | Print job ID. |
| state | Print job state. |

### Print_PrintDocCallback

**Description**

Print document state callback.

**Since:** 13

| Parameter | Description |
| ----------- | ---------- |
| startLayoutWriteCb | Start layout write callback. |
| jobStateChangedCb | Job state change callback. |

### Print_PrinterDiscoveryCallback

**Description**

Printer discovery callback.

**Since:** 12

**Parameters:**

| Name | Description |
| --------- | ---------- |
| event | Discovery event. |
| printerInfo | Printer information. |

### Print_PrinterChangeCallback

**Description**

Printer state change callback.

**Since:** 12

**Parameters:**

| Name | Description |
| --------- | ---------- |
| event | Change event. |
| printerInfo | Printer information. |

## Enumerations

### Print_ErrorCode

**Description**

Error codes.

**Since:** 12

| Enum Value | Description | Value |
| -------- | -------- | -------- |
| PRINT_ERROR_NONE | Operation successful. | 0 |
| PRINT_ERROR_NO_PERMISSION | Permission verification failed. | 201 |
| PRINT_ERROR_INVALID_PARAMETER | Invalid parameter. | 401 |
| PRINT_ERROR_GENERIC_FAILURE | Generic internal error. | 24300001 |
| PRINT_ERROR_RPC_FAILURE | RPC communication error. | 24300002 |
| PRINT_ERROR_SERVER_FAILURE | Server error. | 24300003 |
| PRINT_ERROR_INVALID_EXTENSION | Invalid extension. | 24300004 |
| PRINT_ERROR_INVALID_PRINTER | Invalid printer. | 24300005 |
| PRINT_ERROR_INVALID_PRINT_JOB | Invalid print job. | 24300006 |
| PRINT_ERROR_FILE_IO | File I/O error. | 24300007 |
| PRINT_ERROR_UNKNOWN | Unknown error. | 24300255 |

### Print_PrinterState

**Description**

Printer state codes.

**Since:** 12

| Enum Value | Description |
| -------- | -------- |
| PRINTER_IDLE | Printer idle. |
| PRINTER_BUSY | Printer busy. |
| PRINTER_UNAVAILABLE | Printer unavailable. |

### Print_DiscoveryEvent

**Description**

Printer discovery events.

**Since:** 12

| Enum Value | Description |
| -------- | -------- |
| PRINTER_DISCOVERED | Printer discovered. |
| PRINTER_LOST | Printer lost. |
| PRINTER_CONNECTING | Printer connecting. |
| PRINTER_CONNECTED | Printer connected. |

### Print_PrinterEvent

**Description**

Printer events.

**Since:** 12

| Enum Value | Description |
| -------- | -------- |
| PRINTER_ADDED | Printer added. |
| PRINTER_DELETED | Printer deleted. |
| PRINTER_STATE_CHANGED | Printer state changed. |
| PRINTER_INFO_CHANGED | Printer information changed. |
| PRINTER_PREFERENCE_CHANGED | Printer preference changed. |

### Print_DuplexMode

**Description**

Print duplex mode.

**Since:** 12

| Enum Value | Description |
| -------- | -------- |
| DUPLEX_MODE_ONE_SIDED | One-sided printing. |
| DUPLEX_MODE_TWO_SIDED_LONG_EDGE | Two-sided long edge printing. |
| DUPLEX_MODE_TWO_SIDED_SHORT_EDGE | Two-sided short edge printing. |

### Print_ColorMode

**Description**

Print color mode.

**Since:** 12

| Enum Value | Description |
| -------- | -------- |
| COLOR_MODE_MONOCHROME | Monochrome mode. |
| COLOR_MODE_COLOR | Color mode. |
| COLOR_MODE_AUTO | Auto mode. |

### Print_OrientationMode

**Description**

Print orientation.

**Since:** 12

| Enum Value | Description |
| -------- | -------- |
| ORIENTATION_MODE_PORTRAIT | Portrait. |
| ORIENTATION_MODE_LANDSCAPE | Landscape. |
| ORIENTATION_MODE_REVERSE_LANDSCAPE | Reverse landscape. |
| ORIENTATION_MODE_REVERSE_PORTRAIT | Reverse portrait. |
| ORIENTATION_MODE_NONE | Not specified. |

### Print_Quality

**Description**

Print quality.

**Since:** 12

| Enum Value | Description |
| -------- | -------- |
| PRINT_QUALITY_DRAFT | Draft quality. |
| PRINT_QUALITY_NORMAL | Normal quality. |
| PRINT_QUALITY_HIGH | High quality. |

### Print_DocumentFormat

**Description**

Document format.

**Since:** 12

| Enum Value | Description | MIME Type |
| -------- | -------- | -------- |
| DOCUMENT_FORMAT_AUTO | Auto detect. | application/octet-stream. |
| DOCUMENT_FORMAT_JPEG | JPEG image. | image/jpeg. |
| DOCUMENT_FORMAT_PDF | PDF document. | application/pdf. |
| DOCUMENT_FORMAT_POSTSCRIPT | PostScript document. | application/postscript. |
| DOCUMENT_FORMAT_TEXT | Plain text. | text/plain. |

### Print_JobDocAdapterState

**Description**

Print job document adapter state.

**Since:** 13

| Enum Value | Description |
| -------- | -------- |
| PRINT_DOC_ADAPTER_PREVIEW_ABILITY_DESTROY | Print preview ability destroyed. |
| PRINT_DOC_ADAPTER_PRINT_TASK_SUCCEED | Print task succeeded. |
| PRINT_DOC_ADAPTER_PRINT_TASK_FAIL | Print task failed. |
| PRINT_DOC_ADAPTER_PRINT_TASK_CANCEL | Print task canceled. |
| PRINT_DOC_ADAPTER_PRINT_TASK_BLOCK | Print task blocked. |
| PRINT_DOC_ADAPTER_PREVIEW_ABILITY_DESTROY_FOR_CANCELED | Preview ability destroyed due to cancellation. |
| PRINT_DOC_ADAPTER_PREVIEW_ABILITY_DESTROY_FOR_STARTED | Preview ability destroyed due to task start. |

## Function Documentation

### OH_Print_Init()

```cpp
Print_ErrorCode OH_Print_Init();
```

**Description**

Starts the print service, initializes the print client, and establishes a connection to the print service.

**Permission:** ohos.permission.PRINT

**System Capability:** SystemCapability.Print.PrintFramework

**Since:** 12

**Returns:**

| Error Code | Description |
| -------- | -------- |
| PRINT_ERROR_NONE | Operation successful. |
| PRINT_ERROR_NO_PERMISSION | Missing print permission. |
| PRINT_ERROR_RPC_FAILURE | Unable to connect to print service. |
| PRINT_ERROR_SERVER_FAILURE | CUPS service failed to start. |

### OH_Print_Release()

```cpp
Print_ErrorCode OH_Print_Release();
```

**Description**

Closes the connection to the print service, unregisters callbacks, and releases print client resources.

**System Capability:** SystemCapability.Print.PrintFramework

**Since:** 12

**Returns:**

| Error Code | Description |
| -------- | -------- |
| PRINT_ERROR_NONE | Operation successful. |

### OH_Print_StartPrinterDiscovery()

```cpp
Print_ErrorCode OH_Print_StartPrinterDiscovery(Print_PrinterDiscoveryCallback callback);
```

**Description**

Starts the printer discovery process.

**Permission:** ohos.permission.PRINT

**System Capability:** SystemCapability.Print.PrintFramework

**Since:** 12

**Parameters:**

| Name | Description |
| -------- | -------- |
| callback | Printer discovery event callback function. |

**Returns:**

| Error Code | Description |
| -------- | -------- |
| PRINT_ERROR_NONE | Operation successful. |
| PRINT_ERROR_NO_PERMISSION | Missing print permission. |
| PRINT_ERROR_RPC_FAILURE | Unable to connect to print service. |
| PRINT_ERROR_SERVER_FAILURE | Failed to query print extension list from BMS. |
| PRINT_ERROR_INVALID_EXTENSION | No available print extensions found. |

### OH_Print_StopPrinterDiscovery()

```cpp
Print_ErrorCode OH_Print_StopPrinterDiscovery();
```

**Description**

Stops the printer discovery process.

**Permission:** ohos.permission.PRINT

**System Capability:** SystemCapability.Print.PrintFramework

**Since:** 12

**Returns:**

| Error Code | Description |
| -------- | -------- |
| PRINT_ERROR_NONE | Operation successful. |
| PRINT_ERROR_NO_PERMISSION | Missing print permission. |
| PRINT_ERROR_RPC_FAILURE | Unable to connect to print service. |

### OH_Print_ConnectPrinter()

```cpp
Print_ErrorCode OH_Print_ConnectPrinter(const char *printerId);
```

**Description**

Connects to a printer using the printer ID.

**Permission:** ohos.permission.PRINT

**System Capability:** SystemCapability.Print.PrintFramework

**Since:** 12

**Parameters:**

| Name | Description |
| -------- | -------- |
| printerId | Printer ID to connect to. |

**Returns:**

| Error Code | Description |
| -------- | -------- |
| PRINT_ERROR_NONE | Operation successful. |
| PRINT_ERROR_NO_PERMISSION | Missing print permission. |
| PRINT_ERROR_RPC_FAILURE | Unable to connect to print service. |
| PRINT_ERROR_INVALID_PRINTER | Printer not in discovered list. |
| PRINT_ERROR_SERVER_FAILURE | Unable to find extension responsible for the printer. |

### OH_Print_StartPrintJob()

```cpp
Print_ErrorCode OH_Print_StartPrintJob(const Print_PrintJob *printJob);
```

**Description**

Starts a print job.

**Permission:** ohos.permission.PRINT

**System Capability:** SystemCapability.Print.PrintFramework

**Since:** 12

**Parameters:**

| Name | Description |
| -------- | -------- |
| printJob | Pointer to Print_PrintJob structure containing print job information. |

**Returns:**

| Error Code | Description |
| -------- | -------- |
| PRINT_ERROR_NONE | Operation successful. |
| PRINT_ERROR_NO_PERMISSION | Missing print permission. |
| PRINT_ERROR_RPC_FAILURE | Unable to connect to print service. |
| PRINT_ERROR_INVALID_PRINTER | Printer not in connected list. |
| PRINT_ERROR_SERVER_FAILURE | Failed to create print job in print service. |
| PRINT_ERROR_INVALID_PRINT_JOB | Unable to find job in job queue. |

### OH_Print_RegisterPrinterChangeListener()

```cpp
Print_ErrorCode OH_Print_RegisterPrinterChangeListener(Print_PrinterChangeCallback callback);
```

**Description**

Registers a printer state change listener.

**Permission:** ohos.permission.PRINT

**System Capability:** SystemCapability.Print.PrintFramework

**Since:** 12

**Parameters:**

| Name | Description |
| -------- | -------- |
| callback | Printer state change callback function. |

**Returns:**

| Error Code | Description |
| -------- | -------- |
| PRINT_ERROR_NONE | Operation successful. |
| PRINT_ERROR_NO_PERMISSION | Missing print permission. |
| PRINT_ERROR_RPC_FAILURE | Unable to connect to print service. |

### OH_Print_UnregisterPrinterChangeListener()

```cpp
void OH_Print_UnregisterPrinterChangeListener();
```

**Description**

Unregisters the printer state change listener.

**Permission:** ohos.permission.PRINT

**System Capability:** SystemCapability.Print.PrintFramework

**Since:** 12

### OH_Print_QueryPrinterList()

```cpp
Print_ErrorCode OH_Print_QueryPrinterList(Print_StringList *printerIdList);
```

**Description**

Queries the list of added printers.

**Permission:** ohos.permission.PRINT

**System Capability:** SystemCapability.Print.PrintFramework

**Since:** 12

**Parameters:**

| Name | Description |
| -------- | -------- |
| printerIdList | Pointer to Print_StringList to store the queried printer ID list. |

**Returns:**

| Error Code | Description |
| -------- | -------- |
| PRINT_ERROR_NONE | Operation successful. |
| PRINT_ERROR_NO_PERMISSION | Missing print permission. |
| PRINT_ERROR_INVALID_PARAMETER | printerIdList is NULL. |
| PRINT_ERROR_INVALID_PRINTER | Unable to query any connected printers. |
| PRINT_ERROR_GENERIC_FAILURE | Unable to copy printer ID list. |

### OH_Print_ReleasePrinterList()

```cpp
void OH_Print_ReleasePrinterList(Print_StringList *printerIdList);
```

**Description**

Releases memory allocated for printer list query.

**System Capability:** SystemCapability.Print.PrintFramework

**Since:** 12

**Parameters:**

| Name | Description |
| -------- | -------- |
| printerIdList | Printer ID list to be released. |

### OH_Print_QueryPrinterInfo()

```cpp
Print_ErrorCode OH_Print_QueryPrinterInfo(const char *printerId, Print_PrinterInfo **printerInfo);
```

**Description**

Queries printer information based on printer ID.

**Permission:** ohos.permission.PRINT

**System Capability:** SystemCapability.Print.PrintFramework

**Since:** 12

**Parameters:**

| Name | Description |
| -------- | -------- |
| printerId | Printer ID to query. |
| printerInfo | Pointer to Print_PrinterInfo pointer to store printer information. |

**Returns:**

| Error Code | Description |
| -------- | -------- |
| PRINT_ERROR_NONE | Operation successful. |
| PRINT_ERROR_NO_PERMISSION | Missing print permission. |
| PRINT_ERROR_RPC_FAILURE | Unable to connect to print service. |
| PRINT_ERROR_INVALID_PARAMETER | printerId or printerInfo is NULL. |
| PRINT_ERROR_INVALID_PRINTER | Unable to find printer in connected printer list. |

### OH_Print_ReleasePrinterInfo()

```cpp
void OH_Print_ReleasePrinterInfo(Print_PrinterInfo *printerInfo);
```

**Description**

Releases memory allocated for printer information query.

**System Capability:** SystemCapability.Print.PrintFramework

**Since:** 12

**Parameters:**

| Name | Description |
| -------- | -------- |
| printerInfo | Pointer to queried printer information to be released. |

### OH_Print_LaunchPrinterManager()

```cpp
Print_ErrorCode OH_Print_LaunchPrinterManager();
```

**Description**

Launches the system's printer management window.

**System Capability:** SystemCapability.Print.PrintFramework

**Since:** 12

**Returns:**

| Error Code | Description |
| -------- | -------- |
| PRINT_ERROR_NONE | Operation successful. |
| PRINT_ERROR_GENERIC_FAILURE | Unable to launch printer manager window. |

### OH_Print_QueryPrinterProperties()

```cpp
Print_ErrorCode OH_Print_QueryPrinterProperties(const char *printerId, 
                                              const Print_StringList *propertyKeyList,
                                              Print_PropertyList *propertyList);
```

**Description**

Queries printer property values based on property key list.

**Permission:** ohos.permission.PRINT

**System Capability:** SystemCapability.Print.PrintFramework

**Since:** 12

**Parameters:**

| Name | Description |
| -------- | -------- |
| printerId | Printer ID to query. |
| propertyKeyList | List of property keys to query. |
| propertyList | List of queried printer property values. |

**Returns:**

| Error Code | Description |
| -------- | -------- |
| PRINT_ERROR_NONE | Operation successful. |
| PRINT_ERROR_NO_PERMISSION | Missing print permission. |
| PRINT_ERROR_INVALID_PARAMETER | One of the parameters is NULL or key list is empty. |
| PRINT_ERROR_INVALID_PRINTER | Printer properties for specified printer not found. |
| PRINT_ERROR_GENERIC_FAILURE | Unable to copy printer properties. |

### OH_Print_ReleasePrinterProperties()

```cpp
void OH_Print_ReleasePrinterProperties(Print_PropertyList *propertyList);
```

**Description**

Releases memory allocated for printer properties query.

**System Capability:** SystemCapability.Print.PrintFramework

**Since:** 12

**Parameters:**

| Name | Description |
| -------- | -------- |
| propertyList | Pointer to queried printer properties to be released. |

### OH_Print_UpdatePrinterProperties()

```cpp
Print_ErrorCode OH_Print_UpdatePrinterProperties(const char *printerId, 
                                               const Print_PropertyList *propertyList);
```

**Description**

Sets printer properties based on property key-value pair list.

**Permission:** ohos.permission.PRINT

**System Capability:** SystemCapability.Print.PrintFramework

**Since:** 12

**Parameters:**

| Name | Description |
| -------- | -------- |
| printerId | Printer ID to set. |
| propertyList | List of printer property values to set. |

**Returns:**

| Error Code | Description |
| -------- | -------- |
| PRINT_ERROR_NONE | Operation successful. |
| PRINT_ERROR_NO_PERMISSION | Missing print permission. |
| PRINT_ERROR_RPC_FAILURE | Unable to connect to print service. |

### OH_Print_RestorePrinterProperties()

```cpp
Print_ErrorCode OH_Print_RestorePrinterProperties(const char *printerId, 
                                                const Print_StringList *propertyKeyList);
```

**Description**

Restores printer properties to default settings based on property key list.

**Permission:** ohos.permission.PRINT

**System Capability:** SystemCapability.Print.PrintFramework

**Since:** 12

**Parameters:**

| Name | Description |
| -------- | -------- |
| printerId | Printer ID to restore. |
| propertyKeyList | List of property keys to restore. |

**Returns:**

| Error Code | Description |
| -------- | -------- |
| PRINT_ERROR_NONE | Operation successful. |
| PRINT_ERROR_NO_PERMISSION | Missing print permission. |
| PRINT_ERROR_RPC_FAILURE | Unable to connect to print service. |

### OH_Print_StartPrintByNative()

```cpp
Print_ErrorCode OH_Print_StartPrintByNative(const char *printJobName,
                                          Print_PrintDocCallback printDocCallback,
                                          void *context);
```

**Description**

Starts print service.

**Permission:** ohos.permission.PRINT

**System Capability:** SystemCapability.Print.PrintFramework

**Since:** 13

**Parameters:**

| Name | Description |
| -------- | -------- |
| printJobName | Print job name. |
| printDocCallback | Print document state callback. |
| context | Caller application context. |

**Returns:**

| Error Code | Description |
| -------- | -------- |
| PRINT_ERROR_NONE | Operation successful. |
| PRINT_ERROR_NO_PERMISSION | Missing print permission. |
| PRINT_ERROR_RPC_FAILURE | Unable to connect to print service. |