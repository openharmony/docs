# @ohos.app.ability.PrintExtensionAbility (打印扩展能力)(系统接口)

该模块为打印扩展能力的操作API，提供调用打印扩展能力的接口。

> **说明：**  
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 当前界面仅包含本模块的系统接口，其他公开接口参见[@ohos.app.ability.PrintExtensionAbility (打印扩展能力)](./js-apis-app-ability-PrintExtensionAbility.md)。
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { PrintExtensionAbility } from '@kit.BasicServicesKit';
```

## PrintExtensionAbility.onStartPrintJob

onStartPrintJob(jobInfo: print.PrintJob): void

开始打印任务时调用。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| jobInfo | print.PrintJob | 是 | 表示打印任务的信息 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 202 | not system application |

**示例：**

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

移除已开始的打印任务时调用。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| jobInfo | print.PrintJob | 是 | 表示打印任务的信息 |

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 202 | not system application |

**示例：**

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

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 202 | not system application |

**示例：**

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

**错误码：**

以下错误码的详细介绍请参见[打印服务错误码](./errorcode-print.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 202 | not system application |

**示例：**

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
