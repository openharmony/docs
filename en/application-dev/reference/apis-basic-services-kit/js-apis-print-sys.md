# @ohos.print (Print) (System API)

The **print** module provides APIs for basic print operations.

> **NOTE** 
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.print (Print)](./js-apis-print-sys.md).

## Modules to Import

```ts
import { print } from '@kit.BasicServicesKit';
```


## PrintMargin

Defines the page margins for printing.

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Attributes**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| top | number | No| Top margin of the page.|
| bottom | number | No| Bottom margin of the page.|
| left | number | No| Left margin of the page.|
| right | number | No| Right margin of the page.|

## PrinterRange

Defines the print range.

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Attributes**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| startPage | number | No| Start page.|
| endPage | number | No| End page.|
| pages | Array&lt;number&gt; | No| Discrete pages.|

## PreviewAttribute

Defines the print preview attributes.

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Attributes**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| previewRange | PrinterRange | Yes| Preview page range.|
| result | number | No| Print preview result.|

## PrintResolution

Defines the resolution for printing.

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Attributes**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| id | string | Yes| Resolution ID.|
| horizontalDpi | number | Yes| Horizontal DPI.|
| verticalDpi | number | Yes| Vertical DPI.|



## PrinterCapability

Defines the printer capabilities.

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Attributes**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| colorMode | number | Yes| Color mode.|
| duplexMode | number | Yes| Single-sided or double-sided printing mode.|
| pageSize | Array&lt;PrintPageSize&gt; | Yes| List of page sizes supported by the printer.|
| resolution | Array&lt;PrintResolution&gt; | No| List of resolutions supported by the printer.|
| minMargin | PrintMargin | No| Minimum margin of the printer.|
| options<sup>11+</sup> | Object | No| Printer options. The value is a JSON object string.|

## PrinterInfo

Provides the printer information.

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Attributes**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| printerId | string | Yes| Printer ID.|
| printerName | string | Yes| Printer name.|
| printerState | PrinterState | Yes| Printer state.|
| printerIcon | number | No| Resource ID of the printer icon.|
| description | string | No| Printer description.|
| capability | PrinterCapability | No| Printer capability.|
| options | Object | No| Printer options. The value is a JSON object string.|

## PrintJob

Defines a print job.

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Attributes**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| fdList | Array&lt;number&gt; | Yes| FD list of files to print.|
| jobId | string | Yes| ID of the print job.|
| printerId | string | Yes| ID of the printer used for printing.|
| jobState | PrintJobState | Yes| State of the print job.|
| jobSubstate<sup>11+</sup> | PrintJobSubState | Yes| Substate of the print job.|
| copyNumber | number | Yes| Copy of the file list.|
| pageRange | PrinterRange | Yes| Print range.|
| isSequential | boolean | Yes| Whether to enable sequential printing.|
| pageSize | PrintPageSize | Yes| Selected page size.|
| isLandscape | boolean | Yes| Whether to print in landscape mode.|
| colorMode | number | Yes| Color mode.|
| duplexMode | number | Yes| Single-sided or double-sided printing mode.|
| margin | PrintMargin | No| Current page margin.|
| preview | PreviewAttribute | No| Preview settings.|
| options | Object | No| Printer options. The value is a JSON object string.|


## PrinterState

Enumerates the printer states.

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

| **Name**| **Value**| **Description**|
| -------- | -------- | -------- |
| PRINTER_ADDED | 0 | A new printer is added.|
| PRINTER_REMOVED | 1 | The printer is removed.|
| PRINTER_CAPABILITY_UPDATED | 2 | The printer is updated.|
| PRINTER_CONNECTED | 3 | The printer is connected.|
| PRINTER_DISCONNECTED | 4 | The printer is disconnected.|
| PRINTER_RUNNING | 5 | The printer is running.|

## PrintJobState

Enumerates the print job states.

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

| **Name**| **Value**| **Description**|
| -------- | -------- | -------- |
| PRINT_JOB_PREPARE | 0 | The printer is prepared for the print job.|
| PRINT_JOB_QUEUED | 1 | The print job is on the print queue of the printer.|
| PRINT_JOB_RUNNING | 2 | The print job is being executed.|
| PRINT_JOB_BLOCKED | 3 | The print job is blocked.|
| PRINT_JOB_COMPLETED | 4 | The print job is complete.|

## PrintJobSubState

Enumerates the print job substates.

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

| **Name**| **Value**| **Description**|
| -------- | -------- | -------- |
| PRINT_JOB_COMPLETED_SUCCESS | 0 | The print job is successful.|
| PRINT_JOB_COMPLETED_FAILED | 1 | The print job failed.|
| PRINT_JOB_COMPLETED_CANCELLED | 2 | The print job is canceled.|
| PRINT_JOB_COMPLETED_FILE_CORRUPTED | 3 | The print job is corrupted.|
| PRINT_JOB_BLOCK_OFFLINE | 4 | The printer is offline.|
| PRINT_JOB_BLOCK_BUSY | 5 | The printer is occupied by another process.|
| PRINT_JOB_BLOCK_CANCELLED | 6 | The print job is canceled.|
| PRINT_JOB_BLOCK_OUT_OF_PAPER | 7 | The printer is out of paper.|
| PRINT_JOB_BLOCK_OUT_OF_INK | 8 | The printer is out of ink.|
| PRINT_JOB_BLOCK_OUT_OF_TONER | 9 | The printer is out of toner.|
| PRINT_JOB_BLOCK_JAMMED | 10 | The printer is in a paper jam.|
| PRINT_JOB_BLOCK_DOOR_OPEN | 11 | The printer door is open.|
| PRINT_JOB_BLOCK_SERVICE_REQUEST | 12 | Print service request.|
| PRINT_JOB_BLOCK_LOW_ON_INK | 13 | The printer is low on ink.|
| PRINT_JOB_BLOCK_LOW_ON_TONER | 14 | The printer is low on toner.|
| PRINT_JOB_BLOCK_REALLY_LOW_ON_INK | 15 | The printer is extremely low on ink.|
| PRINT_JOB_BLOCK_BAD_CERTIFICATE | 16 | The print certificate is incorrect.|
| PRINT_JOB_BLOCK_ACCOUNT_ERROR<sup>11+</sup> | 18 | There is an error with the printer account.|
| PRINT_JOB_BLOCK_PRINT_PERMISSION_ERROR<sup>11+</sup> | 19 | There is an error with the printer permission.|
| PRINT_JOB_BLOCK_PRINT_COLOR_PERMISSION_ERROR<sup>11+</sup> | 20 | There is an error with the color print permission.|
| PRINT_JOB_BLOCK_NETWORK_ERROR<sup>11+</sup> | 21 | The printer is not connected to the network.|
| PRINT_JOB_BLOCK_SERVER_CONNECTION_ERROR<sup>11+</sup> | 22 | The printer could not be connected to the server.|
| PRINT_JOB_BLOCK_LARGE_FILE_ERROR<sup>11+</sup> | 23 | An error occurs when a large file is printed.|
| PRINT_JOB_BLOCK_FILE_PARSING_ERROR<sup>11+</sup> | 24 | There is an error with file parsing.|
| PRINT_JOB_BLOCK_SLOW_FILE_CONVERSION<sup>11+</sup> | 25 | The file conversion is slow.|
| PRINT_JOB_RUNNING_UPLOADING_FILES<sup>11+</sup> | 26 | The file is being uploaded.|
| PRINT_JOB_RUNNING_CONVERTING_FILES<sup>11+</sup> | 27 | The file is being converted.|
| PRINT_JOB_BLOCK_UNKNOWN | 99 | An unknown print error occurs.|

## PrintErrorCode

Enumerates the print error codes.

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

| **Name**| **Value**| **Description**|
| -------- | -------- | -------- |
| E_PRINT_NONE | 0 | No error.|
| E_PRINT_NO_PERMISSION | 201 | No permission.|
| E_PRINT_INVALID_PARAMETER | 401 | Invalid parameter.|
| E_PRINT_GENERIC_FAILURE | 13100001 | Printing failure.|
| E_PRINT_RPC_FAILURE | 13100002 | RPC failure.|
| E_PRINT_SERVER_FAILURE | 13100003 | Print service failure.|
| E_PRINT_INVALID_EXTENSION | 13100004 | Invalid printer extension.|
| E_PRINT_INVALID_PRINTER | 13100005 | Invalid printer.|
| E_PRINT_INVALID_PRINT_JOB | 13100006 | Invalid print job.|
| E_PRINT_FILE_IO | 13100007 | Incorrect file input/output.|

## ApplicationEvent<sup>12+</sup>

Enumerates print application events.

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

| **Name**| **Value**| **Description**|
| -------- | -------- | -------- |
| APPLICATION_CREATED | 0 | Starts the print application.|
| APPLICATION_CLOSED_FOR_STARTED | 1 | Closes the print application by clicking **Start**.|
| APPLICATION_CLOSED_FOR_CANCELED | 2 | Closes the print application by clicking **Cancel**.|

## PrinterExtensionInfo

Provides the printer extension information.

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Attributes**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| extensionId | string | Yes| ID of the printer extension.|
| vendorId | string | Yes| Vendor ID of the printer extension.|
| vendorName | string | Yes| Vendor name of the printer extension.|
| vendorIcon | number | Yes| Vendor icon of the printer extension.|
| version | string | Yes| Version of the printer extension.|

## queryAllPrinterExtensionInfos

queryAllPrinterExtensionInfos(callback: AsyncCallback&lt;Array&lt;PrinterExtensionInfo&gt;&gt;): void

Obtains the information of all installed printer extensions. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;Array&lt;PrinterExtensionInfo&gt;&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

print.queryAllPrinterExtensionInfos((err: BusinessError, extensionInfos: print.PrinterExtensionInfo[]) => {
    if (err) {
        console.log('queryAllPrinterExtensionInfos err ' + JSON.stringify(err));
    } else {
        console.log('queryAllPrinterExtensionInfos success ' + JSON.stringify(extensionInfos));
    }
})
```

## queryAllPrinterExtensionInfos

queryAllPrinterExtensionInfos(): Promise&lt;Array&lt;PrinterExtensionInfo&gt;&gt;

Obtains the information of all installed printer extensions. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;Array&lt;PrinterExtensionInfo&gt;&gt; | Promise used to return the result.used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

print.queryAllPrinterExtensionInfos().then((extensionInfos: print.PrinterExtensionInfo[]) => {
    console.log('queryAllPrinterExtensionInfos success ' + JSON.stringify(extensionInfos));
    // ...
}).catch((error: BusinessError) => {
    console.log('failed to get AllPrinterExtension bacause ' + JSON.stringify(error));
})
```

## startDiscoverPrinter

startDiscoverPrinter(extensionList: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

Starts discovering printers with the specified printer extensions. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| extensionList | Array&lt;string&gt; | Yes| List of printer extensions to load.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let extensionList: string[] = [];
// If there is no information in extensionList, all extensions are used for printer discovery.
print.startDiscoverPrinter(extensionList, (err: BusinessError, data : void) => {
    if (err) {
        console.log('failed to start Discover Printer because : ' + JSON.stringify(err));
    } else {
        console.log('start Discover Printer success data : ' + JSON.stringify(data));
    }
})
```

## startDiscoverPrinter

startDiscoverPrinter(extensionList: Array&lt;string&gt;): Promise&lt;void&gt;

Starts discovering printers with the specified printer extensions. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| extensionList | Array&lt;string&gt; | Yes| List of printer extensions to load.|

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let extensionList: string[] = [];
// If there is no information in extensionList, all extensions are used for printer discovery.
print.startDiscoverPrinter(extensionList).then((data : void) => {
    console.log('start Discovery success data : ' + JSON.stringify(data));
}).catch((error: BusinessError) => {
    console.log('failed to start Discovery because : ' + JSON.stringify(error));
})
```

## stopDiscoverPrinter

stopDiscoverPrinter(callback: AsyncCallback&lt;void&gt;): void

Stops discovering printers with the specified printer extensions. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

print.stopDiscoverPrinter((err: BusinessError, data : void) => {
    if (err) {
        console.log('failed to stop Discover Printer because : ' + JSON.stringify(err));
    } else {
        console.log('stop Discover Printer success data : ' + JSON.stringify(data));
    }
})
```

## stopDiscoverPrinter

stopDiscoverPrinter(): Promise&lt;void&gt;

Stops discovering printers with the specified printer extensions. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

print.stopDiscoverPrinter().then((data : void) => {
    console.log('stop Discovery success data : ' + JSON.stringify(data));
}).catch((error: BusinessError) => {
    console.log('failed to stop Discovery because : ' + JSON.stringify(error));
})
```

## connectPrinter

connectPrinter(printerId: string, callback: AsyncCallback&lt;void&gt;): void

Connects to the specified printer. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| printerId | string | Yes| Printer ID.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let printerId: string = 'printerId_32';
print.connectPrinter(printerId, (err: BusinessError, data : void) => {
    if (err) {
        console.log('failed to connect Printer because : ' + JSON.stringify(err));
    } else {
        console.log('start connect Printer success data : ' + JSON.stringify(data));
    }
})
```

## connectPrinter

connectPrinter(printerId: string): Promise&lt;void&gt;

Connects to the specified printer. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| printerId | string | Yes| Printer ID.|

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let printerId: string = 'printerId_32';
print.connectPrinter(printerId).then((data : void) => {
    console.log('start connect Printer success data : ' + JSON.stringify(data));
}).catch((error: BusinessError) => {
    console.log('failed to connect Printer because : ' + JSON.stringify(error));
})
```

## disconnectPrinter

disconnectPrinter(printerId: string, callback: AsyncCallback&lt;void&gt;): void

Disconnects from the specified printer. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| printerId | string | Yes| Printer ID.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let printerId: string = 'printerId_32';
print.disconnectPrinter(printerId, (err: BusinessError, data : void) => {
    if (err) {
        console.log('failed to disconnect Printer because : ' + JSON.stringify(err));
    } else {
        console.log('start disconnect Printer success data : ' + JSON.stringify(data));
    }
})
```

## disconnectPrinter

disconnectPrinter(printerId: string): Promise&lt;void&gt;

Disconnects from the specified printer. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| printerId | string | Yes| Printer ID.|

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let printerId: string = 'printerId_32';
print.disconnectPrinter(printerId).then((data : void) => {
    console.log('start disconnect Printer success data : ' + JSON.stringify(data));
}).catch((error: BusinessError) => {
    console.log('failed to disconnect Printer because : ' + JSON.stringify(error));
})
```

## queryPrinterCapability

queryPrinterCapability(printerId: string, callback: AsyncCallback&lt;void&gt;): void

Queries the printer capability. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| printerId | string | Yes| Printer ID.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let printerId: string = 'printerId_32';
print.queryPrinterCapability(printerId, (err: BusinessError, data : void) => {
    if (err) {
        console.log('failed to query Printer Capability because : ' + JSON.stringify(err));
    } else {
        console.log('start query Printer Capability success data : ' + JSON.stringify(data));
    }
})
```

## queryPrinterCapability

queryPrinterCapability(printerId: string): Promise&lt;void&gt;

Queries the printer capability. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| printerId | string | Yes| Printer ID.|

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let printerId: string = 'printerId_32';
print.queryPrinterCapability(printerId).then((data : void) => {
    console.log('start query Printer success data : ' + JSON.stringify(data));
}).catch((error: BusinessError) => {
    console.log('failed to query Printer Capability because : ' + JSON.stringify(error));
})
```

## startPrintJob

startPrintJob(jobInfo: PrintJob, callback: AsyncCallback&lt;void&gt;): void

Starts the specified print job. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| jobInfo | PrintJob | Yes| Information about the print job.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let jobInfo : print.PrintJob = {
    fdList : [0,1],
    jobId : 'jobId_12',
    printerId : 'printerId_32',
    jobState : 3,
    jobSubstate : print.PrintJobSubState.PRINT_JOB_COMPLETED_SUCCESS,
    copyNumber : 1,
    pageRange : {},
    isSequential : false,
    pageSize : {id : '', name : '', width : 10, height : 20},
    isLandscape : false,
    colorMode : 6,
    duplexMode : 6,
    margin : undefined,
    preview : undefined,
    options : undefined
};
print.startPrintJob(jobInfo, (err: BusinessError, data : void) => {
    if (err) {
        console.log('failed to start Print Job because : ' + JSON.stringify(err));
    } else {
        console.log('start Print Job success data : ' + JSON.stringify(data));
    }
})
```

## startPrintJob

startPrintJob(jobInfo: PrintJob): Promise&lt;void&gt;

Starts the specified print job. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| jobInfo | PrintJob | Yes| Information about the print job.|

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let jobInfo : print.PrintJob = {
    fdList : [0,1],
    jobId : 'jobId_12',
    printerId : 'printerId_32',
    jobState : 3,
    jobSubstate : print.PrintJobSubState.PRINT_JOB_COMPLETED_SUCCESS,
    copyNumber : 1,
    pageRange : {},
    isSequential : false,
    pageSize : {id : '', name : '', width : 10, height : 20},
    isLandscape : false,
    colorMode : 6,
    duplexMode : 6,
    margin : undefined,
    preview : undefined,
    options : undefined
};
print.startPrintJob(jobInfo).then((data : void) => {
    console.log('start Print success data : ' + JSON.stringify(data));
}).catch((error: BusinessError) => {
    console.log('failed to start Print because : ' + JSON.stringify(error));
})
```

## cancelPrintJob

cancelPrintJob(jobId: string, callback: AsyncCallback&lt;void&gt;): void

Cancels the specified print job, which is on the print queue of the printer. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| jobId | string | Yes| Print job ID.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let jobId : string = '121212';
print.cancelPrintJob(jobId, (err: BusinessError, data : void) => {
    if (err) {
        console.log('cancelPrintJob failed, because : ' + JSON.stringify(err));
    } else {
        console.log('cancelPrintJob success, data: ' + JSON.stringify(data));
    }
})
```

## cancelPrintJob

cancelPrintJob(jobId: string): Promise&lt;void&gt;

Cancels the specified print job, which is on the print queue of the printer. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| jobId | string | Yes| Print job ID.|

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let jobId : string = '121212';
print.cancelPrintJob(jobId).then((data : void) => {
    console.log('cancelPrintJob success, data : ' + JSON.stringify(data));
}).catch((error: BusinessError) => {
    console.log('cancelPrintJob failed, because : ' + JSON.stringify(error));
})
```

## requestPrintPreview

requestPrintPreview(jobInfo: PrintJob, callback: Callback&lt;number&gt;): void

Requests print preview data. This API uses a callback to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| jobInfo | PrintJob | Yes| Information about the print job.|
| callback | Callback&lt;number&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';

let jobInfo : print.PrintJob = {
    fdList : [0,1],
    jobId : 'jobId_12',
    printerId : 'printerId_32',
    jobState : 3,
    jobSubstate : print.PrintJobSubState.PRINT_JOB_COMPLETED_SUCCESS,
    copyNumber : 1,
    pageRange : {},
    isSequential : false,
    pageSize : {id : '', name : '', width : 10, height : 20},
    isLandscape : false,
    colorMode : 6,
    duplexMode : 6,
    margin : undefined,
    preview : undefined,
    options : undefined
};
print.requestPrintPreview(jobInfo, (num : number) => {
    console.log('requestPrintPreview success, num : ' + JSON.stringify(num));

})
```

## requestPrintPreview

requestPrintPreview(jobInfo: PrintJob): Promise&lt;number&gt;

Requests print preview data. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| jobInfo | PrintJob | Yes| Information about the print job.|

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;number&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let jobInfo : print.PrintJob = {
    fdList : [0,1],
    jobId : 'jobId_12',
    printerId : 'printerId_32',
    jobState : 3,
    jobSubstate : print.PrintJobSubState.PRINT_JOB_COMPLETED_SUCCESS,
    copyNumber : 1,
    pageRange : {},
    isSequential : false,
    pageSize : {id : '', name : '', width : 10, height : 20},
    isLandscape : false,
    colorMode : 6,
    duplexMode : 6,
    margin : undefined,
    preview : undefined,
    options : undefined
};
print.requestPrintPreview(jobInfo).then((num: number) => {
    console.log('requestPrintPreview success, num : ' + JSON.stringify(num));
}).catch((error: BusinessError) => {
    console.log('requestPrintPreview failed, because : ' + JSON.stringify(error));
})
```

## on

on(type: 'printerStateChange', callback: (state: PrinterState, info: PrinterInfo) => void): void

Registers a listener for printer state change events. This API uses a callback to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | 'printerStateChange' | Yes| Listening type. The value is fixed at **'printerStateChange'**.|
| callback | (state: PrinterState, info: PrinterInfo) => void | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';

print.on('printerStateChange', (state: print.PrinterState, info: print.PrinterInfo) => {
    if (state === null || info === null) {
        console.log('printer state changed state is null or info is null');
        return;
    } else {
        console.log('on printer state changed, state : ' + JSON.stringify(state));
        console.log('on printer state changed, info : ' + JSON.stringify(info));
    }
})
```

## off

off(type: 'printerStateChange', callback?: Callback&lt;boolean&gt;): void

Unregisters the listener for printer state change events. This API uses a callback to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | 'printerStateChange' | Yes| Listening type. The value is fixed at **'printerStateChange'**.|
| callback | Callback&lt;boolean&gt; | No| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';

print.off('printerStateChange', (data: boolean) => {
    console.log('off printerStateChange data : ' + JSON.stringify(data));
})
```

## on

on(type: 'jobStateChange', callback: (state: PrintJobState, job: PrintJob) => void): void

Registers a listener for print job state change events. This API uses a callback to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | 'jobStateChange' | Yes| Listening type. The value is fixed at **'jobStateChange'**.|
| callback | (state: PrintJobState, job: PrintJob) => void | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';

print.on('jobStateChange', (state: print.PrintJobState, job: print.PrintJob) => {
    console.log('onJobStateChange, state : ' + JSON.stringify(state) + ', job : ' + JSON.stringify(job));
})
```

## off

off(type: 'jobStateChange', callback?: Callback&lt;boolean&gt;): void

Unregisters the listener for print job state change events. This API uses a callback to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | 'jobStateChange' | Yes| Listening type. The value is fixed at **'jobStateChange'**.|
| callback | Callback&lt;boolean&gt; | No| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';

print.off('jobStateChange', (data: boolean) => {
    console.log('offJobStateChanged data : ' + JSON.stringify(data));
})
```

## on

on(type: 'extInfoChange', callback: (extensionId: string, info: string) => void): void

Registers a listener for printer extension information change events. This API uses a callback to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | 'extInfoChange' | Yes| Listening type. The value is fixed at **'extInfoChange'**.|
| callback | (extensionId: string, info: string) => void | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';

print.on('extInfoChange', (extensionId: string, info: string) => {
    console.log('onExtInfoChange, entensionId : ' + JSON.stringify(extensionId) + ', info : ' + JSON.stringify(info));
})
```

## off

off(type: 'extInfoChange', callback?: Callback&lt;boolean&gt;): void

Unregisters the listener for printer extension information change events. This API uses a callback to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | 'extInfoChange' | Yes| Listening type. The value is fixed at **'extInfoChange'**.|
| callback | Callback&lt;boolean&gt; | No| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';

print.off('extInfoChange', (data: boolean) => {
    console.log('offExtInfoChange data : ' + JSON.stringify(data));
})
```

## addPrinters

addPrinters(printers: Array&lt;PrinterInfo&gt;, callback: AsyncCallback&lt;void&gt;): void

Adds printers. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| printers | Array&lt;PrinterInfo&gt; | Yes| List of printers to add.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let printerInfo : print.PrinterInfo = {
    printerId : '3232',
    printerName : 'hhhhh',
    printerState : 0,
    printerIcon : 12,
    description : 'str',
    capability : undefined,
    options : 'opt'
};
print.addPrinters([printerInfo], (err: BusinessError, data : void) => {
    if (err) {
        console.log('addPrinters failed, because : ' + JSON.stringify(err));
    } else {
        console.log('addPrinters success, data : ' + JSON.stringify(data));
    }
})
```

## addPrinters

addPrinters(printers: Array&lt;PrinterInfo&gt;): Promise&lt;void&gt;

Adds printers. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| printers | Array&lt;PrinterInfo&gt; | Yes| List of printers to add.|

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let printerInfo : print.PrinterInfo = {
    printerId : '3232',
    printerName : 'hhhhh',
    printerState : 0,
    printerIcon : 12,
    description : 'str',
    capability : undefined,
    options : 'opt'
};
print.addPrinters([printerInfo]).then((data : void) => {
    console.log('add printers data : ' + JSON.stringify(data));
}).catch((error: BusinessError) => {
    console.log('add printers error : ' + JSON.stringify(error));
})
```

## removePrinters

removePrinters(printerIds: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

Removes printers. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| printerIds | Array&lt;string&gt; | Yes| List of printers to remove.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let printerId : string = '1212';
print.removePrinters([printerId], (err: BusinessError, data : void) => {
    if (err) {
        console.log('removePrinters failed, because : ' + JSON.stringify(err));
    } else {
        console.log('removePrinters success, data : ' + JSON.stringify(data));
    }
})
```

## removePrinters

removePrinters(printerIds: Array&lt;string&gt;): Promise&lt;void&gt;

Removes printers. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| printerIds | Array&lt;string&gt; | Yes| List of printers to remove.|

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let printerId : string = '1212';
print.removePrinters([printerId]).then((data : void) => {
    console.log('remove printers data : ' + JSON.stringify(data));
}).catch((error: BusinessError) => {
    console.log('remove printers error : ' + JSON.stringify(error));
})
```

## updatePrinters

updatePrinters(printers: Array&lt;PrinterInfo&gt;, callback: AsyncCallback&lt;void&gt;): void

Updates information about the specified printers. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| printers | Array&lt;PrinterInfo&gt; | Yes| List of printers whose information is to be updated.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let printerInfo : print.PrinterInfo = {
    printerId : '3232',
    printerName : 'hhhhh',
    printerState : 0,
    printerIcon : 12,
    description : 'str',
    capability : undefined,
    options : 'opt'
};
print.updatePrinters([printerInfo], (err: BusinessError, data : void) => {
    if (err) {
        console.log('updataPrinters failed, because : ' + JSON.stringify(err));
    } else {
        console.log('updataPrinters success, data : ' + JSON.stringify(data));
    }
})
```

## updatePrinters

updatePrinters(printers: Array&lt;PrinterInfo&gt;): Promise&lt;void&gt;

Updates information about the specified printers. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| printers | Array&lt;PrinterInfo&gt; | Yes| List of printers whose information is to be updated.|

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let printerInfo : print.PrinterInfo = {
    printerId : '3232',
    printerName : 'hhhhh',
    printerState : 0,
    printerIcon : 12,
    description : 'str',
    capability : undefined,
    options : 'opt'
};
print.updatePrinters([printerInfo]).then((data : void) => {
    console.log('update printers data : ' + JSON.stringify(data));
}).catch((error: BusinessError) => {
    console.log('update printers error : ' + JSON.stringify(error));
})
```

## updatePrinterState

updatePrinterState(printerId: string, state: PrinterState, callback: AsyncCallback&lt;void&gt;): void

Updates the printer state. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| printerId | string | Yes| Printer ID.|
| state | PrinterState | Yes| Printer state.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let printerId : string = '1212';
let state : print.PrinterState = print.PrinterState.PRINTER_CONNECTED;
print.updatePrinterState(printerId, state, (err: BusinessError, data : void) => {
    if (err) {
        console.log('updataPrinterState failed, because : ' + JSON.stringify(err));
    } else {
        console.log('updataPrinterState success, data : ' + JSON.stringify(data));
    }
})
```

## updatePrinterState

updatePrinterState(printerId: string, state: PrinterState): Promise&lt;void&gt;

Updates the printer state. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| printerId | string | Yes| Printer ID.|
| state | PrinterState | Yes| Printer state.|

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let printerId : string = '1212';
let state : print.PrinterState = print.PrinterState.PRINTER_CONNECTED;
print.updatePrinterState(printerId, state).then((data : void) => {
    console.log('update printer state data : ' + JSON.stringify(data));
}).catch((error: BusinessError) => {
    console.log('update printer state error : ' + JSON.stringify(error));
})
```

## updatePrintJobState

updatePrintJobState(jobId: string, state: PrintJobState, subState: PrintJobSubState, callback: AsyncCallback&lt;void&gt;): void

Updates the print job state. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| jobId | string | Yes| ID of the print job.|
| state | PrintJobState | Yes| State of the print job.|
| subState | PrintJobSubState | Yes| Substate of the print job.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let jobId : string = '3434';
let state : print.PrintJobState = print.PrintJobState.PRINT_JOB_PREPARE;
let subState : print.PrintJobSubState = print.PrintJobSubState.PRINT_JOB_COMPLETED_SUCCESS;
print.updatePrintJobState(jobId, state, subState, (err: BusinessError, data : void) => {
    if (err) {
        console.log('updataPrintJobState failed, because : ' + JSON.stringify(err));
    } else {
        console.log('updatePrintJobState success, data : ' + JSON.stringify(data));
    }
})
```

## updatePrintJobState

updatePrintJobState(jobId: string, state: PrintJobState, subState: PrintJobSubState): Promise&lt;void&gt;

Updates the print job state. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| jobId | string | Yes| ID of the print job.|
| state | PrintJobState | Yes| State of the print job.|
| subState | PrintJobSubState | Yes| Substate of the print job.|

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let jobId : string = '3434';
let state : print.PrintJobState = print.PrintJobState.PRINT_JOB_PREPARE;
let subState : print.PrintJobSubState = print.PrintJobSubState.PRINT_JOB_COMPLETED_SUCCESS;
print.updatePrintJobState(jobId, state, subState).then((data : void) => {
    console.log('update print job state data : ' + JSON.stringify(data));
}).catch((error: BusinessError) => {
    console.log('update print job state error : ' + JSON.stringify(error));
})
```

## updateExtensionInfo

updateExtensionInfo(info: string, callback: AsyncCallback&lt;void&gt;): void

Updates the printer extension information. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| info | string | Yes| New printer extension information.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let info : string = 'WIFI_INACTIVE';
print.updateExtensionInfo(info, (err: BusinessError, data : void) => {
    if (err) {
        console.log('updateExtensionInfo failed, because : ' + JSON.stringify(err));
    } else {
        console.log('updateExtensionInfo success, data : ' + JSON.stringify(data));
    }
})
```

## updateExtensionInfo

updateExtensionInfo(info: string): Promise&lt;void&gt;

Updates the printer extension information. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| info | string | Yes| New printer extension information.|

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let info : string = 'WIFI_INACTIVE';
print.updateExtensionInfo(info).then((data : void) => {
    console.log('update print job state data : ' + JSON.stringify(data));
}).catch((error: BusinessError) => {
    console.log('update print job state error : ' + JSON.stringify(error));
})
```

## queryAllPrintJobs<sup>(deprecated)</sup>

> This API is supported since API version 10 and deprecated since API version 11.
> You are advised to use [queryPrintJobList](#queryprintjoblist11) instead.

queryAllPrintJobs(callback: AsyncCallback&lt;void&gt;): void

Queries all print jobs. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

print.queryAllPrintJobs((err: BusinessError, data : void) => {
    if (err) {
        console.log('queryAllPrintJobs failed, because : ' + JSON.stringify(err));
    } else {
        console.log('queryAllPrintJobs success, data : ' + JSON.stringify(data));
    }
})
```

## queryAllPrintJobs<sup>(deprecated)</sup>

> This API is supported since API version 10 and deprecated since API version 11.
> You are advised to use [queryPrintJobList](#queryprintjoblist11-1) instead.

queryAllPrintJobs(): Promise&lt;void&gt;

Queries all print jobs. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

print.queryAllPrintJobs().then((data : void) => {
    console.log('queryAllPrintJobs success, data : ' + JSON.stringify(data));
}).catch((error: BusinessError) => {
    console.log('queryAllPrintJobs failed, error : ' + JSON.stringify(error));
})
```

## queryPrintJobList<sup>11+</sup>

queryPrintJobList(callback: AsyncCallback&lt;Array&lt;PrintJob&gt;&gt;): void

Queries all print jobs. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;Array&lt;PrintJob&gt;&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

print.queryPrintJobList((err: BusinessError, printJobs : print.PrintJob[]) => {
    if (err) {
        console.log('queryPrintJobList failed, because : ' + JSON.stringify(err));
    } else {
        console.log('queryPrintJobList success, data : ' + JSON.stringify(printJobs));
    }
})
```

## queryPrintJobList<sup>11+</sup>

queryPrintJobList(): Promise&lt;Array&lt;PrintJob&gt;&gt;

Queries all print jobs. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;Array&lt;PrintJob&gt;&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

print.queryPrintJobList().then((printJobs : print.PrintJob[]) => {
    console.log('queryPrintJobList success, data : ' + JSON.stringify(printJobs));
}).catch((error: BusinessError) => {
    console.log('queryPrintJobList failed, error : ' + JSON.stringify(error));
})
```

## queryPrintJobById<sup>11+</sup>

queryPrintJobById(jobId: string, callback: AsyncCallback&lt;PrintJob&gt;): void

Queries a print job by ID. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| jobId | string | Yes| ID of the print job.|
| callback | AsyncCallback&lt;PrintJob&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let jobId : string = '1';
print.queryPrintJobById(jobId, (err: BusinessError, printJob : print.PrintJob) => {
    if (err) {
        console.log('queryPrintJobById failed, because : ' + JSON.stringify(err));
    } else {
        console.log('queryPrintJobById success, data : ' + JSON.stringify(printJob));
    }
})
```

## queryPrintJobById<sup>11+</sup>

queryPrintJobById(jobId: string): Promise&lt;PrintJob&gt;

Queries a print job by ID. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| jobId | string | Yes| ID of the print job.|

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;PrintJob&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let jobId : string = '1';
print.queryPrintJobById(jobId).then((printJob : print.PrintJob) => {
    console.log('queryPrintJobById data : ' + JSON.stringify(printJob));
}).catch((error: BusinessError) => {
    console.log('queryPrintJobById error : ' + JSON.stringify(error));
})
```

## startGettingPrintFile<sup>11+</sup>

startGettingPrintFile(jobId: string, printAttributes: PrintAttributes, fd: number, onFileStateChanged: Callback&lt;PrintFileCreationState&gt;): void

Starts to obtain the print file. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| jobId | string | Yes| ID of the print job.|
| printAttributes | PrintAttributes | Yes| Print attributes.|
| fd | number | Yes| File descriptor.|
| onFileStateChanged | Callback&lt;PrintFileCreationState&gt; | Yes| Callback for updating the file state.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let jobId : string= '1';
class MyPrintAttributes implements print.PrintAttributes {
    copyNumber?: number;
    pageRange?: print.PrintPageRange;
    pageSize?: print.PrintPageSize | print.PrintPageType;
    directionMode?: print.PrintDirectionMode;
    colorMode?: print.PrintColorMode;
    duplexMode?: print.PrintDuplexMode;
}

class MyPrintPageRange implements print.PrintPageRange {
    startPage?: number;
    endPage?: number;
    pages?: Array<number>;
}

class MyPrintPageSize implements print.PrintPageSize {
    id: string = '0';
    name: string = '0';
    width: number = 210;
    height: number = 297;
}

let printAttributes = new MyPrintAttributes();
printAttributes.copyNumber = 2;
printAttributes.pageRange = new MyPrintPageRange();
printAttributes.pageRange.startPage = 0;
printAttributes.pageRange.endPage = 5;
printAttributes.pageRange.pages = [1, 3];
printAttributes.pageSize = print.PrintPageType.PAGE_ISO_A3;
printAttributes.directionMode = print.PrintDirectionMode.DIRECTION_MODE_AUTO;
printAttributes.colorMode = print.PrintColorMode.COLOR_MODE_MONOCHROME;
printAttributes.duplexMode = print.PrintDuplexMode.DUPLEX_MODE_NONE;

let fd : number = 1;
print.startGettingPrintFile(jobId, printAttributes, fd, (state: print.PrintFileCreationState) => {
    console.log('onFileStateChanged success, data : ' + JSON.stringify(state));
})
```

## notifyPrintService<sup>11+</sup>

notifyPrintService(jobId: string, type: 'spooler_closed_for_cancelled' | 'spooler_closed_for_started', callback: AsyncCallback&lt;void&gt;): void

Notifies the print service of the spooler shutdown information. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| jobId | string | Yes| ID of the print job.|
| type | 'spooler_closed_for_cancelled' \| 'spooler_closed_for_started' | Yes| Spooler shutdown information.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let jobId : string = '1';
print.notifyPrintService(jobId, 'spooler_closed_for_started', (err: BusinessError, data : void) => {
    if (err) {
        console.log('notifyPrintService failed, because : ' + JSON.stringify(err));
    } else {
        console.log('notifyPrintService success, data : ' + JSON.stringify(data));
    }
})
```

## notifyPrintService<sup>11+</sup>

notifyPrintService(jobId: string, type: 'spooler_closed_for_cancelled' | 'spooler_closed_for_started'): Promise&lt;void&gt;

Notifies the print service of the spooler shutdown information. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| jobId | string | Yes| ID of the print job.|
| type | 'spooler_closed_for_cancelled' \| 'spooler_closed_for_started' | Yes| Spooler shutdown information.|

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let jobId : string = '1';
print.notifyPrintService(jobId, 'spooler_closed_for_started').then((data : void) => {
    console.log('notifyPrintService data : ' + JSON.stringify(data));
}).catch((error: BusinessError) => {
    console.log('notifyPrintService error : ' + JSON.stringify(error));
})
```

## getAddedPrinters<sup>12+</sup>

getAddedPrinters(): Promise&lt;Array&lt;string&gt;&gt;

Obtains the list of printers that have been added to the CUPS. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

print.getAddedPrinters().then((printers: string[]) => {
    console.log('getAddedPrinters success ' + JSON.stringify(printers));
    // ...
}).catch((error: BusinessError) => {
    console.log('failed to getAddedPrinters bacause ' + JSON.stringify(error));
})
```

## getPrinterInfoById<sup>12+</sup>

getPrinterInfoById(printerId: string): Promise&lt;PrinterInfo&gt;

Obtains printer information based on the printer ID. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| printerId | string | Yes| Printer ID.|

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;PrinterInfo&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let printerId : string = '1';
print.getPrinterInfoById(printerId).then((printerInfo : print.PrinterInfo) => {
    console.log('getPrinterInfoById data : ' + JSON.stringify(printerInfo));
}).catch((error: BusinessError) => {
    console.log('getPrinterInfoById error : ' + JSON.stringify(error));
})
```

## notifyPrintServiceEvent<sup>12+</sup>

notifyPrintServiceEvent(event: ApplicationEvent): Promise&lt;void&gt;

Notifies the print service of the print application events. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| event | ApplicationEvent | Yes| Print application events.|

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let event : print.ApplicationEvent = print.ApplicationEvent.APPLICATION_CREATED;
print.notifyPrintServiceEvent(event).then((data : void) => {
    console.log('notifyPrintServiceEvent data : ' + JSON.stringify(data));
}).catch((error: BusinessError) => {
    console.log('notifyPrintServiceEvent error : ' + JSON.stringify(error));
})
```
