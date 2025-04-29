# @ohos.print (Print) (System API)

The **print** module provides APIs for basic print operations.

> **NOTE** 
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.print (Print)](./js-apis-print-sys.md).

## Modules to Import

```ts
import { print } from '@kit.BasicServicesKit';
```


## print.PrintMargin

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

## print.PrinterRange

Defines the print range.

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Attributes**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| startPage | number | No| Start page.|
| endPage | number | No| End page.|
| pages | Array&lt;number&gt; | No| Discrete pages.|

## print.PreviewAttribute

Defines the print preview attributes.

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Attributes**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| previewRange | [PrinterRange](#printprinterrange) | Yes| Preview page range.|
| result | number | No| Print preview result.|

## print.PrintResolution

Defines the resolution for printing.

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Attributes**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| id | string | Yes| Resolution ID.|
| horizontalDpi | number | Yes| Horizontal DPI.|
| verticalDpi | number | Yes| Vertical DPI.|

## print.PrinterCapability

Defines the printer capabilities.

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Attributes**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| colorMode | number | Yes| Color mode.|
| duplexMode | number | Yes| Single-sided or double-sided printing mode.|
| pageSize | Array&lt;[PrintPageSize](./js-apis-print.md#printprintpagesize11)&gt; | Yes| List of page sizes supported by the printer.|
| resolution | Array&lt;[PrintResolution](#printprintresolution)&gt; | No| List of resolutions supported by the printer.|
| minMargin | [PrintMargin](#printprintmargin) | No| Minimum margin of the printer.|
| options<sup>11+</sup> | Object | No| Printer options. The value is a JSON object string.|

## print.PrinterInfo

Provides the printer information.

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Attributes**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| printerId | string | Yes| Printer ID.|
| printerName | string | Yes| Printer name.|
| printerState | [PrinterState](./js-apis-print.md#printprinterstate14) | Yes| Printer state.|
| printerIcon | number | No| Resource ID of the printer icon.|
| description | string | No| Printer description.|
| capability | [PrinterCapability](#printprintercapability) | No| Printer capability.|
| options | Object | No| Printer options. The value is a JSON object string.|

## print.PrintJob

Defines a print job.

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Attributes**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| fdList | Array&lt;number&gt; | Yes| FD list of files to print.|
| jobId | string | Yes| ID of the print job.|
| printerId | string | Yes| ID of the printer used for printing.|
| jobState | [PrintJobState](./js-apis-print.md#printprintjobstate14) | Yes| State of the print job.|
| jobSubstate<sup>11+</sup> | [PrintJobSubState](./js-apis-print.md#printprintjobsubstate14) | Yes| Substate of the print job.|
| copyNumber | number | Yes| Copy of the file list.|
| pageRange | [PrinterRange](#printprinterrange) | Yes| Print range.|
| isSequential | boolean | Yes| Whether the printing is sequential. The value **true** means that the printing is sequential; the value **false** means the opposite. The default value is **false**.|
| pageSize | [PrintPageSize](./js-apis-print.md#printprintpagesize11) | Yes| Selected page size.|
| isLandscape | boolean | Yes| Whether the printing is in landscape mode. The value **true** means that the printing is in landscape mode; the value **false** means the printing is in portrait mode The default value is **false**.|
| colorMode | number | Yes| Color mode.|
| duplexMode | number | Yes| Single-sided or double-sided printing mode.|
| margin | [PrintMargin](#printprintmargin) | No| Current page margin.|
| preview | [PreviewAttribute](#printpreviewattribute) | No| Preview settings.|
| options | Object | No| Printer options. The value is a JSON object string.|

## print.PrinterExtensionInfo

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

## print.queryAllPrinterExtensionInfos

queryAllPrinterExtensionInfos(callback: AsyncCallback&lt;Array&lt;PrinterExtensionInfo&gt;&gt;): void

Obtains the information of all installed printer extensions. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;Array&lt;[PrinterExtensionInfo](#printprinterextensioninfo)&gt;&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |

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

## print.queryAllPrinterExtensionInfos

queryAllPrinterExtensionInfos(): Promise&lt;Array&lt;PrinterExtensionInfo&gt;&gt;

Obtains the information of all installed printer extensions. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;Array&lt;[PrinterExtensionInfo](#printprinterextensioninfo)&gt;&gt; | Promise used to return the result.used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |

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

## print.startDiscoverPrinter

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
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
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

## print.startDiscoverPrinter

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
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
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

## print.stopDiscoverPrinter

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
| 201 | the application does not have permission to call this function. |
| 202 | not system application |

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

## print.stopDiscoverPrinter

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
| 201 | the application does not have permission to call this function. |
| 202 | not system application |

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

## print.connectPrinter

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
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
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

## print.connectPrinter

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
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
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

## print.disconnectPrinter

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
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
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

## print.disconnectPrinter

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
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
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

## print.queryPrinterCapability

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
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
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

## print.queryPrinterCapability

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
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
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

## print.startPrintJob

startPrintJob(jobInfo: PrintJob, callback: AsyncCallback&lt;void&gt;): void

Starts the specified print job. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| jobInfo | [PrintJob](#printprintjob) | Yes| Information about the print job.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
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

## print.startPrintJob

startPrintJob(jobInfo: PrintJob): Promise&lt;void&gt;

Starts the specified print job. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| jobInfo | [PrintJob](#printprintjob) | Yes| Information about the print job.|

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
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

## print.cancelPrintJob

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
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
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

## print.cancelPrintJob

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
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
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

## print.requestPrintPreview

requestPrintPreview(jobInfo: PrintJob, callback: Callback&lt;number&gt;): void

Requests print preview data. This API uses a callback to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| jobInfo | [PrintJob](#printprintjob) | Yes| Information about the print job.|
| callback | Callback&lt;number&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
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

## print.requestPrintPreview

requestPrintPreview(jobInfo: PrintJob): Promise&lt;number&gt;

Requests print preview data. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| jobInfo | [PrintJob](#printprintjob) | Yes| Information about the print job.|

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;number&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
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

## print.on

on(type: 'printerStateChange', callback: (state: PrinterState, info: PrinterInfo) => void): void

Registers a listener for printer state change events. This API uses a callback to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | 'printerStateChange' | Yes| Listening type. The value is fixed at **'printerStateChange'**.|
| callback | (state: [PrinterState](./js-apis-print.md#printprinterstate14), info: [PrinterInfo](#printprinterinfo)) => void | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
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

## print.off

off(type: 'printerStateChange', callback?: Callback&lt;boolean&gt;): void

Unregisters the listener for printer state change events. This API uses a callback to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | 'printerStateChange' | Yes| Listening type. The value is fixed at **'printerStateChange'**.|
| callback | Callback&lt;boolean&gt; | No| Callback used to return the result. The value **true** means that the listener for printer state change events is successfully unregistered, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';

print.off('printerStateChange', (data: boolean) => {
    console.log('off printerStateChange data : ' + JSON.stringify(data));
})
```

## print.on

on(type: 'jobStateChange', callback: (state: PrintJobState, job: PrintJob) => void): void

Registers a listener for print job state change events. This API uses a callback to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | 'jobStateChange' | Yes| Listening type. The value is fixed at **'jobStateChange'**.|
| callback | (state: [PrintJobState](./js-apis-print.md#printprintjobstate14), job: [PrintJob](#printprintjob)) => void | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';

print.on('jobStateChange', (state: print.PrintJobState, job: print.PrintJob) => {
    console.log('onJobStateChange, state : ' + JSON.stringify(state) + ', job : ' + JSON.stringify(job));
})
```

## print.off

off(type: 'jobStateChange', callback?: Callback&lt;boolean&gt;): void

Unregisters the listener for print job state change events. This API uses a callback to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | 'jobStateChange' | Yes| Listening type. The value is fixed at **'jobStateChange'**.|
| callback | Callback&lt;boolean&gt; | No| Callback used to return the result. The value **true** means that the listener for print job state change events is successfully unregistered, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';

print.off('jobStateChange', (data: boolean) => {
    console.log('offJobStateChanged data : ' + JSON.stringify(data));
})
```

## print.on

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
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';

print.on('extInfoChange', (extensionId: string, info: string) => {
    console.log('onExtInfoChange, entensionId : ' + JSON.stringify(extensionId) + ', info : ' + JSON.stringify(info));
})
```

## print.off

off(type: 'extInfoChange', callback?: Callback&lt;boolean&gt;): void

Unregisters the listener for printer extension information change events. This API uses a callback to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | 'extInfoChange' | Yes| Listening type. The value is fixed at **'extInfoChange'**.|
| callback | Callback&lt;boolean&gt; | No| Callback used to return the result. The value **true** means that the listener for printer extension information change events is successfully unregistered, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';

print.off('extInfoChange', (data: boolean) => {
    console.log('offExtInfoChange data : ' + JSON.stringify(data));
})
```

## print.addPrinters

addPrinters(printers: Array&lt;PrinterInfo&gt;, callback: AsyncCallback&lt;void&gt;): void

Adds printers. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| printers | Array&lt;[PrinterInfo](#printprinterinfo)&gt; | Yes| List of printers to add.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
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

## print.addPrinters

addPrinters(printers: Array&lt;PrinterInfo&gt;): Promise&lt;void&gt;

Adds printers. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| printers | Array&lt;[PrinterInfo](#printprinterinfo)&gt; | Yes| List of printers to add.|

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
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

## print.removePrinters

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
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
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

## print.removePrinters

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
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
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

## print.updatePrinters

updatePrinters(printers: Array&lt;PrinterInfo&gt;, callback: AsyncCallback&lt;void&gt;): void

Updates information about the specified printers. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| printers | Array&lt;[PrinterInfo](#printprinterinfo)&gt; | Yes| List of printers whose information is to be updated.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
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

## print.updatePrinters

updatePrinters(printers: Array&lt;PrinterInfo&gt;): Promise&lt;void&gt;

Updates information about the specified printers. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| printers | Array&lt;[PrinterInfo](#printprinterinfo)&gt; | Yes| List of printers whose information is to be updated.|

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
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

## print.updatePrinterState

updatePrinterState(printerId: string, state: PrinterState, callback: AsyncCallback&lt;void&gt;): void

Updates the printer state. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| printerId | string | Yes| Printer ID.|
| state | [PrinterState](./js-apis-print.md#printprinterstate14) | Yes| Printer state.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
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

## print.updatePrinterState

updatePrinterState(printerId: string, state: PrinterState): Promise&lt;void&gt;

Updates the printer state. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| printerId | string | Yes| Printer ID.|
| state | [PrinterState](./js-apis-print.md#printprinterstate14) | Yes| Printer state.|

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
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

## print.updatePrintJobState

updatePrintJobState(jobId: string, state: PrintJobState, subState: PrintJobSubState, callback: AsyncCallback&lt;void&gt;): void

Updates the print job state. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| jobId | string | Yes| ID of the print job.|
| state | [PrintJobState](./js-apis-print.md#printprintjobstate14) | Yes| State of the print job.|
| subState | [PrintJobSubState](./js-apis-print.md#printprintjobsubstate14) | Yes| Substate of the print job.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
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

## print.updatePrintJobState

updatePrintJobState(jobId: string, state: PrintJobState, subState: PrintJobSubState): Promise&lt;void&gt;

Updates the print job state. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| jobId | string | Yes| ID of the print job.|
| state | [PrintJobState](./js-apis-print.md#printprintjobstate14) | Yes| State of the print job.|
| subState | [PrintJobSubState](./js-apis-print.md#printprintjobsubstate14) | Yes| Substate of the print job.|

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
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

## print.updateExtensionInfo

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
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
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

## print.updateExtensionInfo

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
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
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

## print.queryAllPrintJobs<sup>(deprecated)</sup>

> This API is supported since API version 10 and deprecated since API version 11.
> You are advised to use [queryPrintJobList](#printqueryprintjoblist11) instead.

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
| 201 | the application does not have permission to call this function. |
| 202 | not system application |

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

## print.queryAllPrintJobs<sup>(deprecated)</sup>

> This API is supported since API version 10 and deprecated since API version 11.
> You are advised to use [queryPrintJobList](#printqueryprintjoblist11-1) instead.

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
| 201 | the application does not have permission to call this function. |
| 202 | not system application |

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

## print.queryPrintJobList<sup>11+</sup>

queryPrintJobList(callback: AsyncCallback&lt;Array&lt;PrintJob&gt;&gt;): void

Queries all print jobs. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;Array&lt;[PrintJob](#printprintjob)&gt;&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |

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

## print.queryPrintJobList<sup>11+</sup>

queryPrintJobList(): Promise&lt;Array&lt;PrintJob&gt;&gt;

Queries all print jobs. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;Array&lt;[PrintJob](#printprintjob)&gt;&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |

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

## print.queryPrintJobById<sup>11+</sup>

queryPrintJobById(jobId: string, callback: AsyncCallback&lt;PrintJob&gt;): void

Queries a print job by ID. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| jobId | string | Yes| ID of the print job.|
| callback | AsyncCallback&lt;[PrintJob](#printprintjob)&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
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

## print.queryPrintJobById<sup>11+</sup>

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
| Promise&lt;[PrintJob](#printprintjob)&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
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

## print.startGettingPrintFile<sup>11+</sup>

startGettingPrintFile(jobId: string, printAttributes: PrintAttributes, fd: number, onFileStateChanged: Callback&lt;PrintFileCreationState&gt;): void

Starts to obtain the print file. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| jobId | string | Yes| ID of the print job.|
| printAttributes | [PrintAttributes](./js-apis-print.md#printprintattributes11) | Yes| Print attributes.|
| fd | number | Yes| File descriptor.|
| onFileStateChanged | Callback&lt;[PrintFileCreationState](./js-apis-print.md#printprintfilecreationstate11)&gt; | Yes| Callback for updating the file state.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
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

## print.notifyPrintService<sup>11+</sup>

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
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
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

## print.notifyPrintService<sup>11+</sup>

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
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
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

## print.getAddedPrinters<sup>12+</sup>

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
| 201 | the application does not have permission to call this function. |
| 202 | not system application |

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

## print.getPrinterInfoById<sup>12+</sup>

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
| Promise&lt;[PrinterInfo](#printprinterinfo)&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
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

## print.notifyPrintServiceEvent<sup>12+</sup>

notifyPrintServiceEvent(event: ApplicationEvent): Promise&lt;void&gt;

Notifies the print service of the print application events. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB

**System API**: This is a system API.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| event | [ApplicationEvent](./js-apis-print.md#printapplicationevent14) | Yes| Print application events.|

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application |
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
