# @ohos.app.ability.PrintExtensionAbility    
该模块为打印扩展能力的操作API，提供调用打印扩展能力的接口。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## PrintExtensionAbility  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Print.PrintFramework    
### onCreate    
初始化扩展能力,会在系统首次连接打印扩展时调用。  
 **调用形式：**     
- onCreate(want: Want): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Print.PrintFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | 表示调用打印页面需要参数 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
    
 **示例代码：**   
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
  
    
### onStartDiscoverPrinter    
开始发现与设备连接的打印机时调用。  
 **调用形式：**     
- onStartDiscoverPrinter(): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Print.PrintFramework    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
    
 **示例代码：**   
```ts    
import PrintExtensionAbility from '@ohos.app.ability.PrintExtensionAbility';  
  
export default class HWPrintExtension extends PrintExtensionAbility {  
    onStartDiscoverPrinter(): void {  
        console.log('onStartDiscoverPrinter enter');  
        // ...  
    }  
}  
    
```    
  
    
### onStopDiscoverPrinter    
停止发现打印机时调用。  
 **调用形式：**     
- onStopDiscoverPrinter(): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Print.PrintFramework    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
    
 **示例代码：**   
```ts    
import PrintExtensionAbility from '@ohos.app.ability.PrintExtensionAbility';  
  
export default class HWPrintExtension extends PrintExtensionAbility {  
    onStopDiscoverPrinter(): void {  
        console.log('onStopDiscoverPrinter enter');  
        // ...  
    }  
}  
    
```    
  
    
### onConnectPrinter    
连接到特定打印机时调用。  
 **调用形式：**     
- onConnectPrinter(printerId: number): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Print.PrintFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| printerId | number | true | 表示打印机ID |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
    
 **示例代码：**   
```ts    
import PrintExtensionAbility from '@ohos.app.ability.PrintExtensionAbility';  
  
export default class HWPrintExtension extends PrintExtensionAbility {  
    onConnectPrinter(printerId: number): void {  
        console.log('onConnectPrinter enter');  
        // ...  
    }  
}  
    
```    
  
    
### onDisconnectPrinter    
断开与特定打印机的连接时调用。  
 **调用形式：**     
- onDisconnectPrinter(printerId: number): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Print.PrintFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| printerId | number | true | 表示打印机ID |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
    
 **示例代码：**   
```ts    
import PrintExtensionAbility from '@ohos.app.ability.PrintExtensionAbility';  
  
export default class HWPrintExtension extends PrintExtensionAbility {  
    onDisconnectPrinter(printerId: number): void {  
        console.log('onDisconnectPrinter enter');  
        // ...  
    }  
}  
    
```    
  
    
### onStartPrintJob    
开始打印任务时调用。  
 **调用形式：**     
- onStartPrintJob(jobInfo: print.PrintJob): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Print.PrintFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| jobInfo | print.PrintJob | true | 表示打印任务的信息  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
    
 **示例代码：**   
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
  
    
### onCancelPrintJob    
移除已开始的打印任务时调用。  
 **调用形式：**     
- onCancelPrintJob(jobInfo: print.PrintJob): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Print.PrintFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| jobInfo | print.PrintJob | true | 表示打印任务的信息  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
    
 **示例代码：**   
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
  
    
### onRequestPrinterCapability    
请求打印机能力时调用。  
 **调用形式：**     
- onRequestPrinterCapability(printerId: number): print.PrinterCapability  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Print.PrintFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| printerId | number | true | 表示打印机ID |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| print.PrinterCapability | 表示打印能力 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
    
 **示例代码：**   
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
  
    
### onRequestPreview    
请求预览时调用，并将结果返回到Print SA。  
 **调用形式：**     
- onRequestPreview(jobInfo: print.PrintJob): string  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Print.PrintFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| jobInfo | print.PrintJob | true | 表示打印任务的信息 。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
    
 **示例代码：**   
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
  
    
### onDestroy  
 **调用形式：**     
- onDestroy(): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Print.PrintFramework    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
    
 **示例代码：**   
```ts    
import PrintExtensionAbility from '@ohos.app.ability.PrintExtensionAbility';  
  
export default class HWPrintExtension extends PrintExtensionAbility {  
    onDestroy(): void {  
        console.log('onDestroy');  
    }  
}  
    
```    
  
