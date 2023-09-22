# @ohos.app.ability.PrintExtensionAbility (打印扩展)

该模块为打印扩展的操作API，提供调用打印扩展功能的接口。

> **说明：**
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

- 本模块接口为系统接口。

- 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import PrintExtensionAbility from '@ohos.app.ability.PrintExtensionAbility';
```

## onCreate

onCreate(want: Want): void

初始化扩展能力,会在系统首次连接打印扩展时调用。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| want | Want | 是 | 表示调用打印页面需要参数 |

## onStartDiscoverPrinter

onStartDiscoverPrinter(): void

开始发现与设备连接的打印机时调用。

**系统能力：** SystemCapability.Print.PrintFramework

## onStopDiscoverPrinter

onStopDiscoverPrinter(): void

停止发现打印机时调用。

**系统能力：** SystemCapability.Print.PrintFramework

## onConnectPrinter

onConnectPrinter(printerId: number): void

连接到特定打印机时调用。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| printerId | number | 是 | 表示打印机ID |

## onDisconnectPrinter

onDisconnectPrinter(printerId: number): void

断开与特定打印机的连接时调用。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| printerId | number | 是 | 表示打印机ID |

## onStartPrintJob

onStartPrintJob(jobInfo: print.PrintJob): void

开始打印任务时调用。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| jobInfo | print.PrintJob | 是 | 表示打印任务的信息 |

## onCancelPrintJob

onCancelPrintJob(jobInfo: print.PrintJob): void

移除已开始的打印任务时调用。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| jobInfo | print.PrintJob | 是 | 表示打印任务的信息 |

## onRequestPrinterCapability

onRequestPrinterCapability(printerId: number): print.PrinterCapability

请求打印机能力时调用。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| printerId | number | 是 | 表示打印机ID |

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| print.PrinterCapability | 表示打印能力 |

## onRequestPreview

onRequestPreview(jobInfo: print.PrintJob): string

请求预览时调用，并将结果返回到Print SA。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| jobInfo | print.PrintJob | 是 | 表示打印任务信息 |

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| string | 返回的预览结果 |

## onDestroy

onDestroy(): void

结束打印扩展时调用。

**系统能力：** SystemCapability.Print.PrintFramework

## **示例：**

```ts
import PrintExtensionAbility from '@ohos.app.ability.PrintExtensionAbility';
import print from '@ohos.print';
import Want from '@ohos.app.ability.Want';

export default class HWPrintExtension extends PrintExtensionAbility {
    onCreate(want: Want): void {
        console.log('onCreate');
        // ...
    }

    /**
     * start discovery printer
     */
    onStartDiscoveryPrinter(): void {
        console.log('onStartDiscoveryPrinter enter');
        // ...
    }

    /**
     * stop discovery printer
     */
    onStopDiscoveryPrinter(): void {
        console.log('onStopDiscoveryPrinter enter');
        // ...
    }

    /**
     * connect to printer
     */
    onConnectPrinter(printerId: number): void {
        console.log('onConnectPrinter enter');
        // ...
    }

    /**
     * disconnect to printer
     */
    onDisconnectPrinter(printerId: number): void {
        console.log('onDisconnectPrinter enter');
        // ...
    }

    /**
     * start job
     */
    onStartPrintJob(printJob: print.PrintJob): void {
        console.log('onStartPrintJob, jobId is: ' + printJob.jobId);
        // ...
    }

    /**
     * cancel job
     */
    onCancelPrintJob(printJob: print.PrintJob): void {
        console.log('onCancelPrintJob, jobId is: ' + printJob.jobId);
        // ...
    }

    /**
     * request printer caps
     */
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

    /**
     * request preview
     */
    onRequestPreview(jobInfo: print.PrintJob): string {
        console.log('onRequestPreview enter');
        // ...
        let tmp : string = '';
        return tmp;
    }

    onDestroy(): void {
        console.log('onDestroy');
    }
}
```