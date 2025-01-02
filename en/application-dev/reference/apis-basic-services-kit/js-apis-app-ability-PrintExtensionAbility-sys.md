# @ohos.app.ability.PrintExtensionAbility (Print Extension Ability) (System API)

The **PrintExtensionAbility** module provides operation APIs of the print extension ability.

> **NOTE** 
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
>
> The APIs provided by this module are system APIs. 
>
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import PrintExtensionAbility from '@ohos.app.ability.PrintExtensionAbility';
```

## onCreate

onCreate(want: Want): void

Called to initialize the print extension when the system connects to the extension for the first time.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| want | Want | Yes| Parameters required for invoking the print page.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
import PrintExtensionAbility from '@ohos.app.ability.PrintExtensionAbility';
import Want from '@ohos.app.ability.Want';

export default class HWPrintExtension extends PrintExtensionAbility {
    onCreate(want: Want): void {
        console.log('onCreate');
        // ...
    }
}
```

## onStartDiscoverPrinter

onStartDiscoverPrinter(): void

Called when an attempt to discover printers starts.

**System capability**: SystemCapability.Print.PrintFramework

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
import PrintExtensionAbility from '@ohos.app.ability.PrintExtensionAbility';

export default class HWPrintExtension extends PrintExtensionAbility {
    onStartDiscoverPrinter(): void {
        console.log('onStartDiscoverPrinter enter');
        // ...
    }
}
```

## onStopDiscoverPrinter

onStopDiscoverPrinter(): void

Called when the attempt to discover printers stops.

**System capability**: SystemCapability.Print.PrintFramework

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
import PrintExtensionAbility from '@ohos.app.ability.PrintExtensionAbility';

export default class HWPrintExtension extends PrintExtensionAbility {
    onStopDiscoverPrinter(): void {
        console.log('onStopDiscoverPrinter enter');
        // ...
    }
}
```

## onConnectPrinter

onConnectPrinter(printerId: number): void

Called when the device connects to the specified printer.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| printerId | number | Yes| Printer ID.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
import PrintExtensionAbility from '@ohos.app.ability.PrintExtensionAbility';

export default class HWPrintExtension extends PrintExtensionAbility {
    onConnectPrinter(printerId: number): void {
        console.log('onConnectPrinter enter');
        // ...
    }
}
```

## onDisconnectPrinter

onDisconnectPrinter(printerId: number): void

Called when the device disconnects from the specified printer.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| printerId | number | Yes| Printer ID.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
import PrintExtensionAbility from '@ohos.app.ability.PrintExtensionAbility';

export default class HWPrintExtension extends PrintExtensionAbility {
    onDisconnectPrinter(printerId: number): void {
        console.log('onDisconnectPrinter enter');
        // ...
    }
}
```

## onStartPrintJob

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
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
import PrintExtensionAbility from '@ohos.app.ability.PrintExtensionAbility';
import print from '@ohos.print';

export default class HWPrintExtension extends PrintExtensionAbility {
    onStartPrintJob(jobInfo: print.PrintJob): void {
        console.log('onStartPrintJob, jobId is: ' + jobInfo.jobId);
        // ...
    }
}
```

## onCancelPrintJob

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
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
import PrintExtensionAbility from '@ohos.app.ability.PrintExtensionAbility';
import print from '@ohos.print';

export default class HWPrintExtension extends PrintExtensionAbility {
    onCancelPrintJob(jobInfo: print.PrintJob): void {
        console.log('onCancelPrintJob, jobId is: ' + jobInfo.jobId);
        // ...
    }
}
```

## onRequestPrinterCapability

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
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
import PrintExtensionAbility from '@ohos.app.ability.PrintExtensionAbility';
import print from '@ohos.print';

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

## onRequestPreview

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
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
import PrintExtensionAbility from '@ohos.app.ability.PrintExtensionAbility';
import print from '@ohos.print';

export default class HWPrintExtension extends PrintExtensionAbility {
    onRequestPreview(jobInfo: print.PrintJob): string {
        console.log('onRequestPreview enter');
        // ...
        let tmp : string = '';
        return tmp;
    }
}
```

## onDestroy

onDestroy(): void

Called when the print extension ability is stopped.

**System capability**: SystemCapability.Print.PrintFramework

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
import PrintExtensionAbility from '@ohos.app.ability.PrintExtensionAbility';

export default class HWPrintExtension extends PrintExtensionAbility {
    onDestroy(): void {
        console.log('onDestroy');
    }
}
```
