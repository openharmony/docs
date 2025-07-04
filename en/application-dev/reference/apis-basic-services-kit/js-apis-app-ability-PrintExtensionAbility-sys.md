# @ohos.app.ability.PrintExtensionAbility (Print Extension Ability) (System API)

The **PrintExtensionAbility** module provides operation APIs of the print extension ability.

> **NOTE** 
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.app.ability.PrintExtensionAbility (Print Extension Ability)](./js-apis-app-ability-PrintExtensionAbility.md).
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { PrintExtensionAbility } from '@kit.BasicServicesKit';
```

## PrintExtensionAbility.onStartPrintJob

onStartPrintJob(jobInfo: print.PrintJob): void

Called when the specified print job starts.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| jobInfo | print.PrintJob | Yes| Information about the print job.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 202 | not system application |

**Example**

```ts
import { PrintExtensionAbility } from '@kit.BasicServicesKit';
import { print } from '@kit.BasicServicesKit';

export default class HWPrintExtension extends PrintExtensionAbility {
    onStartPrintJob(jobInfo: print.PrintJob): void {
        console.log('onStartPrintJob, jobId is: ' + jobInfo.jobId);
        // ...
    }
}
```

## PrintExtensionAbility.onCancelPrintJob

onCancelPrintJob(jobInfo: print.PrintJob): void

Called when the specified print job is canceled.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| jobInfo | print.PrintJob | Yes| Information about the print job.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 202 | not system application |

**Example**

```ts
import { PrintExtensionAbility } from '@kit.BasicServicesKit';
import { print } from '@kit.BasicServicesKit';

export default class HWPrintExtension extends PrintExtensionAbility {
    onCancelPrintJob(jobInfo: print.PrintJob): void {
        console.log('onCancelPrintJob, jobId is: ' + jobInfo.jobId);
        // ...
    }
}
```

## PrintExtensionAbility.onRequestPrinterCapability

onRequestPrinterCapability(printerId: number): print.PrinterCapability

Called when a request is sent to check the capability of the specified printer.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| printerId | number | Yes| Printer ID.|

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| print.PrinterCapability | Capability of the printer.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 202 | not system application |

**Example**

```ts
import { PrintExtensionAbility } from '@kit.BasicServicesKit';
import { print } from '@kit.BasicServicesKit';

export default class HWPrintExtension extends PrintExtensionAbility {
    onRequestPrinterCapability(printerId: number): print.PrinterCapability {
        console.log('onRequestPrinterCapability enter');
        // ...
        let tmp : print.PrinterCapability = {
            colorMode : 1,
            duplexMode : 1,
            pageSize : []
        };
        return tmp;
    }
}
```

## PrintExtensionAbility.onRequestPreview

onRequestPreview(jobInfo: print.PrintJob): string

Called when a print preview request is sent. The result is returned to the print SA.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| jobInfo | print.PrintJob | Yes| Information about the print job.|

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| string | Preview result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 202 | not system application |

**Example**

```ts
import { PrintExtensionAbility } from '@kit.BasicServicesKit';
import { print } from '@kit.BasicServicesKit';

export default class HWPrintExtension extends PrintExtensionAbility {
    onRequestPreview(jobInfo: print.PrintJob): string {
        console.log('onRequestPreview enter');
        // ...
        let tmp : string = '';
        return tmp;
    }
}
```
