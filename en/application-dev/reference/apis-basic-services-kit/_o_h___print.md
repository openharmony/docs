# OH_Print

## Overview

Provides applications with the ability to access the print system using CAPI.

**Since**: 12

## Summary

### Files

| Name| Description|
| -------- | -------- |
| [ohprint.h](ohprint_8h.md) |Declares APIs for discovering and connecting to printers, printing files, and querying the list of added printers and printer information.|

### Types

| Name| Description|
| -------- | -------- |
| [Print_StringList](#print_stringlist) | Defines a printer list.|
| [Print_Property](#print_property) | Defines a property for the printer.|
| [Print_PropertyList](#print_propertylist) | Defines a property list for the printer.|
| [Print_Resolution](#print_resolution) | Defines the resolution unit for printing.|
| [Print_Margin](#print_margin) | Defines the page margin.|
| [Print_PageSize](#print_pagesize) | Defines the page size for printing.|
| [Print_PrinterCapability](#print_printercapability) | Defines the printer capabilities.|
| [Print_DefaultValue](#print_defaultvalue) | Defines the default printing information.|
| [Print_PrinterInfo](#print_printerinfo) | Defines the printer information.|
| [Print_PrintJob](#print_printjob) | Defines a print job.|
| [Print_Range](#print_range) | Defines the page range.|
| [Print_PrintAttributes](#print_printattributes) | Defines the print attributes.|
| [Print_WriteResultCallback](#print_writeresultcallback) | Defines a callback used to return the write result.|
| [Print_OnStartLayoutWrite](#print_onstartlayoutwrite) | Defines a callback to be invoked when the layout processing starts.|
| [Print_OnJobStateChanged](#print_onjobstatechanged) | Defines a callback to be invoked when the print job state changes.|
| [Print_PrintDocCallback](#print_printdoccallback) | Defines a callback used to return the file state.|
| [Print_PrinterDiscoveryCallback](#print_printerdiscoverycallback) | Defines a callback used to return the discovered printers.|
| [Print_PrinterChangeCallback](#print_printerchangecallback) | Defines a callback to be invoked when the printer state changes.|

### Enums

| Name| Description|
| -------- | -------- |
| [Print_ErrorCode](#print_errorcode) | Enumerates the error codes.|
| [Print_PrinterState](#print_printerstate) | Enumerates the printer state codes.|
| [Print_DiscoveryEvent](#print_discoveryevent) | Enumerates the printer discovery events.|
| [Print_PrinterEvent](#print_printerevent) | Enumerates the printer state change events.|
| [Print_DuplexMode](#print_duplexmode) | Enumerates the duplex modes for printing.|
| [Print_ColorMode](#print_colormode) | Enumerates the color modes for printing.|
| [Print_OrientationMode](#print_orientationmode) | Enumerates the orientation modes for printing.|
| [Print_Quality](#print_quality) | Enumerates the print qualities.|
| [Print_DocumentFormat](#print_documentformat) | Enumerates the document formats.|
| [Print_JobDocAdapterState](#print_jobdocadapterstate) | Enumerates the print job adapter states.|

### Functions

| Name| Description|
| -------- | -------- |
| [OH_Print_Init](#oh_print_init) | Initiates the print service, initializes the print client, and establishes a connection to the print service.|
| [OH_Print_Release](#oh_print_release) | Closes the connection to the print service, unregisters the callback, and releases the print client resources.|
| [OH_Print_StartPrinterDiscovery](#oh_print_startprinterdiscovery) | Starts printer discovery.|
| [OH_Print_StopPrinterDiscovery](#oh_print_stopprinterdiscovery) | Stops printer discovery.|
| [OH_Print_ConnectPrinter](#oh_print_connectprinter) | Connects to a printer by printer ID.|
| [OH_Print_StartPrintJob](#oh_print_startprintjob) | Starts a print job.|
| [OH_Print_RegisterPrinterChangeListener](#oh_print_registerprinterchangelistener) | Registers a listener to listen for the printer state changes.|
| [OH_Print_UnregisterPrinterChangeListener](#oh_print_unregisterprinterchangelistener) | Unregisters the listener used to listen for the printer state changes.|
| [OH_Print_QueryPrinterList](#oh_print_queryprinterlist) | Queries the printer list.|
| [OH_Print_ReleasePrinterList](#oh_print_releaseprinterlist) | Releases the memory allocated for querying the printer list.|
| [OH_Print_QueryPrinterInfo](#oh_print_queryprinterinfo) | Queries the printer information.|
| [OH_Print_ReleasePrinterInfo](#oh_print_releaseprinterinfo) | Releases the memory allocated for querying the printer information.|
| [OH_Print_LaunchPrinterManager](#oh_print_launchprintermanager) | Launches the printer manager.|
| [OH_Print_QueryPrinterProperties](#oh_print_queryprinterproperties) | Queries the printer properties.|
| [OH_Print_ReleasePrinterProperties](#oh_print_releaseprinterproperties) | Releases the memory allocated for querying the printer properties.|
| [OH_Print_UpdatePrinterProperties](#oh_print_updateprinterproperties) | Updates the printer properties.|
| [OH_Print_RestorePrinterProperties](#oh_print_restoreprinterproperties) | Restores printer properties to the default settings based on the property key list.|
| [OH_Print_StartPrintByNative](#oh_print_startprintbynative) | Starts printing.|

## Type Description

### Print_StringList

**Description**

Defines a printer list.

**Since**: 12

| Member        | Description    |
| ------------ | -------- |
| count    | Number of strings.|
| list | String pointer array.  |

### Print_Property

**Description**

Defines a property for the printer.

**Since**: 12

| Member    | Description                   |
| -------- | ----------------------- |
| key | Property key.|
| value       | Property value.           |

### Print_PropertyList

**Description**

Defines a property list for the printer.

**Since**: 12

| Member        | Description        |
| ------------ | ------------ |
| count       | Number of properties.    |
| list | Property pointer array.|

### Print_Resolution

**Description**

Defines the resolution unit for printing.

**Since**: 12

| Parameter       | Description      |
| ----------- | ---------- |
| horizontalDpi     | Horizontal resolution (dpi).|
| verticalDpi | Vertical resolution (dpi).  |

### Print_Margin

**Description**

Defines the page margin.

**Since**: 12

| Parameter       | Description      |
| ----------- | ---------- |
| leftMargin     | Left margin (µm).|
| topMargin | Top margin (µm).  |
| rightMargin | Right margin (µm).  |
| bottomMargin | Bottom margin (µm).  |

### Print_PageSize

**Description**

Defines the page size for printing.

**Since**: 12

| Parameter       | Description      |
| ----------- | ---------- |
| id     | Page ID.|
| name | Page name.  |
| width | Paper width (µm).  |
| height | Paper height (µm).  |

### Print_PrinterCapability

**Description**

Defines the printer capabilities.

**Since**: 12

| Parameter       | Description      |
| ----------- | ---------- |
| supportedColorModes     | Supported color modes.|
| supportedColorModesCount | Number of supported color modes.  |
| supportedDuplexModes | Supported duplex modes.  |
| supportedDuplexModesCount | Number of supported duplex modes.  |
| supportedPageSizes | Supported page sizes.  |
| supportedPageSizesCount | Number of supported paper sizes.  |
| supportedMediaTypes | Supported media types (JSON string array format).  |
| supportedQualities | Supported print qualities.  |
| supportedQualitiesCount | Number of supported print qualities.  |
| supportedPaperSources | Supported paper sources (JSON string array format).  |
| supportedCopies | Maximum number of copies that can be printed.  |
| supportedResolutions | Supported resolutions.  |
| supportedResolutionsCount | Number of supported resolutions.  |
| supportedOrientations | Supported printing orientations.  |
| supportedOrientationsCount | Number of supported printing orientations.  |
| advancedCapability | Advanced capabilities (JSON format).  |

### Print_DefaultValue

**Description**

Defines the default printing information.

**Since**: 12

| Parameter       | Description      |
| ----------- | ---------- |
| defaultColorMode     | Default color mode.|
| defaultDuplexMode | Default duplex mode.  |
| defaultMediaType | Default media type.  |
| defaultPageSizeId | Default page size ID.  |
| defaultMargin | Default margin.  |
| defaultPaperSource | Default paper source.  |
| defaultPrintQuality | Default print quality.  |
| defaultCopies | Default number of copies.  |
| defaultResolution | Default resolution.  |
| defaultOrientation | Default printing orientation.  |
| otherDefaultValues | Other default values (JSON format).  |

### Print_PrinterInfo

**Description**

Defines the printer information.

**Since**: 12

| Parameter       | Description      |
| ----------- | ---------- |
| printerState     | Printer state.|
| capability | Printer capability.  |
| defaultValue | Default printer property.  |
| isDefaultPrinter | Whether the printer is the default one.  |
| printerId | Printer ID.  |
| printerName | Printer name.  |
| description | Printer description.  |
| location | Printer location.  |
| makeAndModel | Printer manufacturer and model information.  |
| printerUri | Printer URI.  |
| detailInfo | Detailed information (JSON format).  |

### Print_PrintJob

**Description**

Defines a print job.

**Since**: 12

| Parameter       | Description      |
| ----------- | ---------- |
| jobName     | Print job name.|
| fdList | List of file descriptors of the print job.  |
| fdListCount | Number of file descriptors of the print job.  |
| printerId | Printer ID.  |
| copyNumber | Number of copies to print.  |
| paperSource | Paper source.  |
| mediaType | Media type.  |
| pageSizeId | Page size ID.  |
| colorMode | Color mode.  |
| duplexMode | Duplex mode.  |
| resolution | Resolution.  |
| printMargin | Page margin.  |
| borderless | Whether to print without margins.  |
| orientationMode | Orientation mode.  |
| printQuality | Print quality.  |
| documentFormat | Document format.  |
| advancedOptions | Advanced options (JSON format).  |

### Print_Range

**Description**

Defines the page range.

**Since**: 13

| Parameter       | Description      |
| ----------- | ---------- |
| startPage     | Start page number.|
| endPage | End page number.  |
| pagesArrayLen | Length of the page array.  |
| pagesArray | Page array.  |

### Print_PrintAttributes

**Description**

Defines the print attributes.

**Since**: 13

| Parameter       | Description      |
| ----------- | ---------- |
| pageRange     | Defines the page range.|
| pageSize | Paper size.  |
| pageMargin | Page margin.  |
| copyNumber | Number of copies to print.  |
| duplexMode | Duplex mode.  |
| colorMode | Color mode.  |
| isSequential | Whether to print in sequence.  |
| isLandscape | Whether to print in landscape mode.  |
| hasOption | Whether print options are provided.  |
| options | Print options (in 256 bytes).  |

### Print_WriteResultCallback

**Description**

Defines a callback used to return the write result.

**Since**: 13

**Parameters**

| Name     | Description      |
| --------- | ---------- |
| jobId     | Print job ID.|
| code | State code of the write result.  |

### Print_OnStartLayoutWrite

**Description**

Defines a callback to be invoked when the layout processing starts.

**Since**: 13

**Parameters**

| Name     | Description      |
| --------- | ---------- |
| jobId     | Print job ID.|
| fd | File descriptor.  |
| oldAttrs | Previous print attributes.  |
| newAttrs | New print attributes.  |
| writeCallback | Callback used to return the write result.  |

### Print_OnJobStateChanged

**Description**

Defines a callback to be invoked when the print job state changes.

**Since**: 13

**Parameters**

| Name     | Description      |
| --------- | ---------- |
| jobId     | Print job ID.|
| state | Print job state.  |

### Print_PrintDocCallback

**Description**

Defines a callback used to return the file state.

**Since**: 13

| Parameter       | Description      |
| ----------- | ---------- |
| startLayoutWriteCb     | Callback to be invoked when the layout processing starts.|
| jobStateChangedCb | Callback to be invoked when the print job state changes.  |

### Print_PrinterDiscoveryCallback

**Description**

Defines a callback used to return the discovered printers.

**Since**: 12

**Parameters**

| Name     | Description      |
| --------- | ---------- |
| event     | Discovery event.|
| printerInfo | Printer information.  |

### Print_PrinterChangeCallback

**Description**

Defines a callback to be invoked when the printer state changes.

**Since**: 12

**Parameters**

| Name     | Description      |
| --------- | ---------- |
| event     | Change event.|
| printerInfo | Printer information.  |

## Enum Description

### Print_ErrorCode

**Description**

Enumerates the error codes.

**Since**: 12

| Name| Description| Value|
| -------- | -------- | -------- |
| PRINT_ERROR_NONE | Operation successful.| 0 |
| PRINT_ERROR_NO_PERMISSION | Permission verification failed.| 201 |
| PRINT_ERROR_INVALID_PARAMETER | Invalid parameter.| 401 |
| PRINT_ERROR_GENERIC_FAILURE | Internal error.| 24300001 |
| PRINT_ERROR_RPC_FAILURE | RPC communication error.| 24300002 |
| PRINT_ERROR_SERVER_FAILURE | Server error.| 24300003 |
| PRINT_ERROR_INVALID_EXTENSION | Invalid extension.| 24300004 |
| PRINT_ERROR_INVALID_PRINTER | Invalid printer.| 24300005 |
| PRINT_ERROR_INVALID_PRINT_JOB | Invalid print job.| 24300006 |
| PRINT_ERROR_FILE_IO | File I/O operation failed.| 24300007 |
| PRINT_ERROR_UNKNOWN | Unknown error.| 24300255 |

### Print_PrinterState

**Description**

Enumerates the printer state codes.

**Since**: 12

| Name| Description|
| -------- | -------- |
| PRINTER_IDLE | The printer is idle.|
| PRINTER_BUSY | The printer is busy.|
| PRINTER_UNAVAILABLE | The printer is unavailable.|

### Print_DiscoveryEvent

**Description**

Enumerates the printer discovery events.

**Since**: 12

| Name| Description|
| -------- | -------- |
| PRINTER_DISCOVERED | Printer discovered.|
| PRINTER_LOST | Printer lost.|
| PRINTER_CONNECTING | Printer connecting.|
| PRINTER_CONNECTED | Printer connected.|

### Print_PrinterEvent

**Description**

Enumerates the printer state change events.

**Since**: 12

| Name| Description|
| -------- | -------- |
| PRINTER_ADDED | A printer is added.|
| PRINTER_DELETED | A printer is deleted.|
| PRINTER_STATE_CHANGED | The printer state has changed.|
| PRINTER_INFO_CHANGED | The printer information has changed.|
| PRINTER_PREFERENCE_CHANGED | The printer preferences have changed.|

### Print_DuplexMode

**Description**

Enumerates the duplex modes for printing.

**Since**: 12

| Name| Description|
| -------- | -------- |
| DUPLEX_MODE_ONE_SIDED | Single-sided printing.|
| DUPLEX_MODE_TWO_SIDED_LONG_EDGE | Long-edge duplex printing.|
| DUPLEX_MODE_TWO_SIDED_SHORT_EDGE | Short-edge duplex printing.|

### Print_ColorMode

**Description**

Enumerates the color modes for printing.

**Since**: 12

| Name| Description|
| -------- | -------- |
| COLOR_MODE_MONOCHROME | Monochrome mode.|
| COLOR_MODE_COLOR | Color mode.|
| COLOR_MODE_AUTO | Auto mode.|

### Print_OrientationMode

**Description**

Enumerates the orientation modes for printing.

**Since**: 12

| Name| Description|
| -------- | -------- |
| ORIENTATION_MODE_PORTRAIT | Portrait.|
| ORIENTATION_MODE_LANDSCAPE | Landscape.|
| ORIENTATION_MODE_REVERSE_LANDSCAPE | Reverse landscape.|
| ORIENTATION_MODE_REVERSE_PORTRAIT | Reverse portrait.|
| ORIENTATION_MODE_NONE | Not specified.|

### Print_Quality

**Description**

Enumerates the print qualities.

**Since**: 12

| Name| Description|
| -------- | -------- |
| PRINT_QUALITY_DRAFT | Draft quality.|
| PRINT_QUALITY_NORMAL | Normal quality.|
| PRINT_QUALITY_HIGH | High quality.|

### Print_DocumentFormat

**Description**

Enumerates the document formats.

**Since**: 12

| Name| Description| MIME Type|
| -------- | -------- | -------- |
| DOCUMENT_FORMAT_AUTO | Auto-detected format.| application/octet-stream. |
| DOCUMENT_FORMAT_JPEG | JPEG image.| image/jpeg. |
| DOCUMENT_FORMAT_PDF | PDF document.| application/pdf. |
| DOCUMENT_FORMAT_POSTSCRIPT | PostScript document.| application/postscript. |
| DOCUMENT_FORMAT_TEXT | Plain text.| text/plain. |

### Print_JobDocAdapterState

**Description**

Enumerates the print job adapter states.

**Since**: 13

| Name| Description|
| -------- | -------- |
| PRINT_DOC_ADAPTER_PREVIEW_ABILITY_DESTROY | Preview destroyed.|
| PRINT_DOC_ADAPTER_PRINT_TASK_SUCCEED | Successful print job.|
| PRINT_DOC_ADAPTER_PRINT_TASK_FAIL | Print job failed.|
| PRINT_DOC_ADAPTER_PRINT_TASK_CANCEL | Print job canceled.|
| PRINT_DOC_ADAPTER_PRINT_TASK_BLOCK | Print job blocked.|
| PRINT_DOC_ADAPTER_PREVIEW_ABILITY_DESTROY_FOR_CANCELED | Preview destroyed due to print job cancellation.|
| PRINT_DOC_ADAPTER_PREVIEW_ABILITY_DESTROY_FOR_STARTED | Preview destroyed due to print job start.|

## Function Description

### OH_Print_Init()

```cpp
Print_ErrorCode OH_Print_Init();
```

**Description**

Initiates the print service, initializes the print client, and establishes a connection to the print service.

**Required permissions**: ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Since**: 12

**Returns**

| Error Code| Description|
| -------- | -------- |
| PRINT_ERROR_NONE | Operation successful.|
| PRINT_ERROR_NO_PERMISSION | Permission denied.|
| PRINT_ERROR_RPC_FAILURE | Failed to connect to the print service.|
| PRINT_ERROR_SERVER_FAILURE | Failed to start the CUPS service.|

### OH_Print_Release()

```cpp
Print_ErrorCode OH_Print_Release();
```

**Description**

Closes the connection to the print service, unregisters the callback, and releases the print client resources.

**System capability**: SystemCapability.Print.PrintFramework

**Since**: 12

**Returns**

| Error Code| Description|
| -------- | -------- |
| PRINT_ERROR_NONE | Operation successful.|

### OH_Print_StartPrinterDiscovery()

```cpp
Print_ErrorCode OH_Print_StartPrinterDiscovery(Print_PrinterDiscoveryCallback callback);
```

**Description**

Starts printer discovery.

**Required permissions**: ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| callback | callback used to return the discovered printers.|

**Returns**

| Error Code| Description|
| -------- | -------- |
| PRINT_ERROR_NONE | Operation successful.|
| PRINT_ERROR_NO_PERMISSION | Permission denied.|
| PRINT_ERROR_RPC_FAILURE | Failed to connect to the print service.|
| PRINT_ERROR_SERVER_FAILURE | Failed to query the extended printing list from the BMS.|
| PRINT_ERROR_INVALID_EXTENSION | Invalid print extension.|

### OH_Print_StopPrinterDiscovery()

```cpp
Print_ErrorCode OH_Print_StopPrinterDiscovery();
```

**Description**

Stops printer discovery.

**Required permissions**: ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Since**: 12

**Returns**

| Error Code| Description|
| -------- | -------- |
| PRINT_ERROR_NONE | Operation successful.|
| PRINT_ERROR_NO_PERMISSION | Permission denied.|
| PRINT_ERROR_RPC_FAILURE | Failed to connect to the print service.|

### OH_Print_ConnectPrinter()

```cpp
Print_ErrorCode OH_Print_ConnectPrinter(const char *printerId);
```

**Description**

Connects to a printer by printer ID.

**Required permissions**: ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| printerId | ID of the printer to be connected.|

**Returns**

| Error Code| Description|
| -------- | -------- |
| PRINT_ERROR_NONE | Operation successful.|
| PRINT_ERROR_NO_PERMISSION | Permission denied.|
| PRINT_ERROR_RPC_FAILURE | Failed to connect to the print service.|
| PRINT_ERROR_INVALID_PRINTER | Failed to find the printer in the discovery list.|
| PRINT_ERROR_SERVER_FAILURE | Failed to find the printer extension.|

### OH_Print_StartPrintJob()

```cpp
Print_ErrorCode OH_Print_StartPrintJob(const Print_PrintJob *printJob);
```

**Description**

Starts a print job.

**Required permissions**: ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| printJob | Pointer to the **Print_PrintJob** struct that contains the print job information.|

**Returns**

| Error Code| Description|
| -------- | -------- |
| PRINT_ERROR_NONE | Operation successful.|
| PRINT_ERROR_NO_PERMISSION | Permission denied.|
| PRINT_ERROR_RPC_FAILURE | Failed to connect to the print service.|
| PRINT_ERROR_INVALID_PRINTER | Failed to find the printer in the connection list.|
| PRINT_ERROR_SERVER_FAILURE | Failed to create a print job in the print service.|
| PRINT_ERROR_INVALID_PRINT_JOB | Invalid print job.|

### OH_Print_RegisterPrinterChangeListener()

```cpp
Print_ErrorCode OH_Print_RegisterPrinterChangeListener(Print_PrinterChangeCallback callback);
```

**Description**

Registers a listener to listen for the printer state changes.

**Required permissions**: ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| callback | Callback to be invoked when the printer state changes.|

**Returns**

| Error Code| Description|
| -------- | -------- |
| PRINT_ERROR_NONE | Operation successful.|
| PRINT_ERROR_NO_PERMISSION | Permission denied.|
| PRINT_ERROR_RPC_FAILURE | Failed to connect to the print service.|

### OH_Print_UnregisterPrinterChangeListener()

```cpp
void OH_Print_UnregisterPrinterChangeListener();
```

**Description**

Unregisters the listener used to listen for the printer state changes.

**Required permissions**: ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Since**: 12

### OH_Print_QueryPrinterList()

```cpp
Print_ErrorCode OH_Print_QueryPrinterList(Print_StringList *printerIdList);
```

**Description**

Queries the printer list.

**Required permissions**: ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| printerIdList | Pointer to **Print_StringList** that stores the query result.|

**Returns**

| Error Code| Description|
| -------- | -------- |
| PRINT_ERROR_NONE | Operation successful.|
| PRINT_ERROR_NO_PERMISSION | Permission denied.|
| PRINT_ERROR_INVALID_PARAMETER | **printerIdList** is null.|
| PRINT_ERROR_INVALID_PRINTER | Failed to query any connected printers.|
| PRINT_ERROR_GENERIC_FAILURE | Failed to copy the printer ID list.|

### OH_Print_ReleasePrinterList()

```cpp
void OH_Print_ReleasePrinterList(Print_StringList *printerIdList);
```

**Description**

Releases the memory allocated for querying the printer list.

**System capability**: SystemCapability.Print.PrintFramework

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| printerIdList | Printer ID list queried.|

### OH_Print_QueryPrinterInfo()

```cpp
Print_ErrorCode OH_Print_QueryPrinterInfo(const char *printerId, Print_PrinterInfo **printerInfo);
```

**Description**

Queries printer information based on the printer ID.

**Required permissions**: ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| printerId | Printer ID to be queried.|
| printerInfo | Pointer to **Print_PrinterInfo** that stores the query result.|

**Returns**

| Error Code| Description|
| -------- | -------- |
| PRINT_ERROR_NONE | Operation successful.|
| PRINT_ERROR_NO_PERMISSION | Permission denied.|
| PRINT_ERROR_RPC_FAILURE | Failed to connect to the print service.|
| PRINT_ERROR_INVALID_PARAMETER | **printerId** or **printerInfo** is null.|
| PRINT_ERROR_INVALID_PRINTER | Failed to find the printer in the connection list.|

### OH_Print_ReleasePrinterInfo()

```cpp
void OH_Print_ReleasePrinterInfo(Print_PrinterInfo *printerInfo);
```

**Description**

Releases the memory allocated for querying the printer information.

**System capability**: SystemCapability.Print.PrintFramework

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| printerInfo | Pointer to the printer information.|

### OH_Print_LaunchPrinterManager()

```cpp
Print_ErrorCode OH_Print_LaunchPrinterManager();
```

**Description**

Launches the system printer manager.

**System capability**: SystemCapability.Print.PrintFramework

**Since**: 12

**Returns**

| Error Code| Description|
| -------- | -------- |
| PRINT_ERROR_NONE | Operation successful.|
| PRINT_ERROR_GENERIC_FAILURE | Failed to launch the printer manager.|

### OH_Print_QueryPrinterProperties()

```cpp
Print_ErrorCode OH_Print_QueryPrinterProperties(const char *printerId, 
                                              const Print_StringList *propertyKeyList,
                                              Print_PropertyList *propertyList);
```

**Description**

Queries printer properties based on the property key list.

**Required permissions**: ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| printerId | Printer ID to be queried.|
| propertyKeyList | List of property keys.|
| propertyList | Property list used to store the query result.|

**Returns**

| Error Code| Description|
| -------- | -------- |
| PRINT_ERROR_NONE | Operation successful.|
| PRINT_ERROR_NO_PERMISSION | Permission denied.|
| PRINT_ERROR_INVALID_PARAMETER | The parameter is null or the key list is empty.|
| PRINT_ERROR_INVALID_PRINTER | Failed to find printer properties.|
| PRINT_ERROR_GENERIC_FAILURE | Failed to copy the printer properties.|

### OH_Print_ReleasePrinterProperties()

```cpp
void OH_Print_ReleasePrinterProperties(Print_PropertyList *propertyList);
```

**Description**

Releases the memory allocated for querying the printer properties.

**System capability**: SystemCapability.Print.PrintFramework

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| propertyList | Pointer to the property list.|

### OH_Print_UpdatePrinterProperties()

```cpp
Print_ErrorCode OH_Print_UpdatePrinterProperties(const char *printerId, 
                                               const Print_PropertyList *propertyList);
```

**Description**

Updates the printer properties based on the KV pairs.

**Required permissions**: ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| printerId | Printer ID to be set.|
| propertyList | Property list to be set.|

**Returns**

| Error Code| Description|
| -------- | -------- |
| PRINT_ERROR_NONE | Operation successful.|
| PRINT_ERROR_NO_PERMISSION | Permission denied.|
| PRINT_ERROR_RPC_FAILURE | Failed to connect to the print service.|

### OH_Print_RestorePrinterProperties()

```cpp
Print_ErrorCode OH_Print_RestorePrinterProperties(const char *printerId, 
                                                const Print_StringList *propertyKeyList);
```

**Description**

Restores printer properties to the default settings based on the property key list.

**Required permissions**: ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| printerId | Printer ID to be restored.|
| propertyKeyList | Property list to be restored.|

**Returns**

| Error Code| Description|
| -------- | -------- |
| PRINT_ERROR_NONE | Operation successful.|
| PRINT_ERROR_NO_PERMISSION | Permission denied.|
| PRINT_ERROR_RPC_FAILURE | Failed to connect to the print service.|

### OH_Print_StartPrintByNative()

```cpp
Print_ErrorCode OH_Print_StartPrintByNative(const char *printJobName,
                                          Print_PrintDocCallback printDocCallback,
                                          void *context);
```

**Description**

Starts printing.

**Required permissions**: ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| printJobName | Print job name.|
| printDocCallback | Callback used to return the file state.|
| context | Context of the caller.|

**Returns**

| Error Code| Description|
| -------- | -------- |
| PRINT_ERROR_NONE | Operation successful.|
| PRINT_ERROR_NO_PERMISSION | Permission denied.|
| PRINT_ERROR_RPC_FAILURE | Failed to connect to the print service.|
