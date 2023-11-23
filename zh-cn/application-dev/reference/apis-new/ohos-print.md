# @ohos.print    
该模块为基本打印的操作API，提供调用基础打印功能的接口。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import print from '@ohos.print'    
```  
    
## PrintTask    
打印任务完成后的事件监听回调接口类  
 **系统能力:**  SystemCapability.Print.PrintFramework    
### on('block')    
注册打印完成后的监听，使用callback回调。  
 **调用形式：**     
    
- on(type: 'block', callback: Callback\<void>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Print.PrintFramework  
 **需要权限：** ohos.permission.PRINT    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 注册监听，<br/>监听字段：block，<br/>表示打印阻塞 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 打印完成后处于响应状态的回调 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import print from '@ohos.print';  
import { BusinessError } from '@ohos.base';  
  
let file = ['file://data/print/a.png', 'file://data/print/b.png'];  
print.print(file).then((printTask: print.PrintTask) => {  
    printTask.on('block', () => {  
        console.log('print state is block');  
    })  
    // ...  
}).catch((error: BusinessError) => {  
    console.log('print err ' + JSON.stringify(error));  
})  
    
```    
  
    
### on('succeed')    
注册打印完成后的监听，使用callback回调。  
 **调用形式：**     
    
- on(type: 'succeed', callback: Callback\<void>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Print.PrintFramework  
 **需要权限：** ohos.permission.PRINT    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 注册监听，<br/>监听字段：succeed，<br/>表示打印成功 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 打印完成后处于响应状态的回调 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import print from '@ohos.print';  
import { BusinessError } from '@ohos.base';  
  
let file = ['file://data/print/a.png', 'file://data/print/b.png'];  
print.print(file).then((printTask: print.PrintTask) => {  
    printTask.on('succeed', () => {  
        console.log('print state is succeed');  
    })  
    // ...  
}).catch((error: BusinessError) => {  
    console.log('print err ' + JSON.stringify(error));  
})  
    
```    
  
    
### on('fail')    
注册打印完成后的监听，使用callback回调。  
 **调用形式：**     
    
- on(type: 'fail', callback: Callback\<void>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Print.PrintFramework  
 **需要权限：** ohos.permission.PRINT    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  注册监听，<br/>监听字段：fail，<br/>表示打印失败 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 打印完成后处于响应状态的回调 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import print from '@ohos.print';  
import { BusinessError } from '@ohos.base';  
  
let file = ['file://data/print/a.png', 'file://data/print/b.png'];  
print.print(file).then((printTask: print.PrintTask) => {  
    printTask.on('fail', () => {  
        console.log('print state is fail');  
    })  
    // ...  
}).catch((error: BusinessError) => {  
    console.log('print err ' + JSON.stringify(error));  
})  
    
```    
  
    
### on('cancel')    
注册打印完成后的监听，使用callback回调。  
 **调用形式：**     
    
- on(type: 'cancel', callback: Callback\<void>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Print.PrintFramework  
 **需要权限：** ohos.permission.PRINT    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 注册监听，<br/>监听字段：cancel，<br/>表示打印取消 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 打印完成后处于响应状态的回调 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import print from '@ohos.print';  
import { BusinessError } from '@ohos.base';  
  
let file = ['file://data/print/a.png', 'file://data/print/b.png'];  
print.print(file).then((printTask: print.PrintTask) => {  
    printTask.on('cancel', () => {  
        console.log('print state is cancel');  
    })  
    // ...  
}).catch((error: BusinessError) => {  
    console.log('print err ' + JSON.stringify(error));  
})  
    
```    
  
    
### off('block')    
取消打印完成后的监听，使用callback回调。  
 **调用形式：**     
    
- off(type: 'block', callback?: Callback\<void>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Print.PrintFramework  
 **需要权限：** ohos.permission.PRINT    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 取消监听，<br/>监听字段：block，<br/>表示打印阻塞 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 取消相应状态监听成功后的回调 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import print from '@ohos.print';  
import { BusinessError } from '@ohos.base';  
  
let file = ['file://data/print/a.png', 'file://data/print/b.png'];  
print.print(file).then((printTask: print.PrintTask) => {  
    printTask.off('block', () => {  
        console.log('unregister state block');  
    })  
    // ...  
}).catch((error: BusinessError) => {  
    console.log('print err ' + JSON.stringify(error));  
})  
    
```    
  
    
### off('succeed')    
取消打印完成后的监听，使用callback回调。  
 **调用形式：**     
    
- off(type: 'succeed', callback?: Callback\<void>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Print.PrintFramework  
 **需要权限：** ohos.permission.PRINT    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 取消监听，<br/>监听字段：succeed，<br/>表示打印成功 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 取消相应状态监听成功后的回调 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import print from '@ohos.print';  
import { BusinessError } from '@ohos.base';  
  
let file = ['file://data/print/a.png', 'file://data/print/b.png'];  
print.print(file).then((printTask: print.PrintTask) => {  
    printTask.off('succeed', () => {  
        console.log('unregister state succeed');  
    })  
    // ...  
}).catch((error: BusinessError) => {  
    console.log('print err ' + JSON.stringify(error));  
})  
    
```    
  
    
### off('fail')    
取消打印完成后的监听，使用callback回调  
 **调用形式：**     
    
- off(type: 'fail', callback?: Callback\<void>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Print.PrintFramework  
 **需要权限：** ohos.permission.PRINT    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 取消监听，<br/>监听字段：fail，<br/>表示打印失败 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 取消相应状态监听成功后的回调 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import print from '@ohos.print';  
import { BusinessError } from '@ohos.base';  
  
let file = ['file://data/print/a.png', 'file://data/print/b.png'];  
print.print(file).then((printTask: print.PrintTask) => {  
    printTask.off('fail', () => {  
        console.log('unregister state fail');  
    })  
    // ...  
}).catch((error: BusinessError) => {  
    console.log('print err ' + JSON.stringify(error));  
})  
    
```    
  
    
### off('cancel')    
取消打印完成后的监听，使用callback回调。  
 **调用形式：**     
    
- off(type: 'cancel', callback?: Callback\<void>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Print.PrintFramework  
 **需要权限：** ohos.permission.PRINT    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 取消监听，<br/>监听字段：cancel，<br/>表示打印取消 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 取消相应状态监听成功后的回调 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import print from '@ohos.print';  
import { BusinessError } from '@ohos.base';  
  
let file = ['file://data/print/a.png', 'file://data/print/b.png'];  
print.print(file).then((printTask: print.PrintTask) => {  
    printTask.off('cancel', () => {  
        console.log('unregister state cancel');  
    })  
    // ...  
}).catch((error: BusinessError) => {  
    console.log('print err ' + JSON.stringify(error));  
})  
    
```    
  
    
## print    
打印接口，传入文件进行打印  
 **调用形式：**     
    
- print(files: Array\<string>, callback: AsyncCallback\<PrintTask>): void    
起始版本： 10    
- print(files: Array\<string>): Promise\<PrintTask>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Print.PrintFramework  
 **需要权限：** ohos.permission.PRINT    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| files | Array<string> | true | 待打印文件列表，支持图片（.jpg .png .gif .bmp .webp） |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步获取打印完成之后的回调 |  
| Promise<PrintTask> | 打印完成结果 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
  
```ts    
import print from '@ohos.print';  
import { BusinessError } from '@ohos.base';  
  
//传入文件的uri  
let file = ['file://data/print/a.png', 'file://data/print/b.png'];  
//或者传入id  
//let file = ['fd://1', 'fd://2'];  
print.print(file, (err: BusinessError, printTask: print.PrintTask) => {  
    if (err) {  
        console.log('print err ' + JSON.stringify(err));  
    } else {  
        printTask.on('succeed', () => {  
            console.log('print state is succeed');  
        })  
        // ...  
    }  
})  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import print from '@ohos.print';  
import { BusinessError } from '@ohos.base';  
  
//传入文件的uri  
let file = ['file://data/print/a.png', 'file://data/print/b.png'];  
//或者传入id  
//let file = ['fd://1', 'fd://2'];  
print.print(file).then((printTask: print.PrintTask) => {  
    printTask.on('succeed', () => {  
        console.log('print state is succeed');  
    })  
    // ...  
}).catch((error: BusinessError) => {  
    console.log('print err ' + JSON.stringify(error));  
})  
    
```    
  
