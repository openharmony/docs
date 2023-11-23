# @ohos.connectedTag    
本模块提供有源标签的使用，包括初始化有源标签芯片、读取有源标签内容、写入内容到有源标签等。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import connectedTag from '@ohos.connectedTag'    
```  
    
## init<sup>(deprecated)</sup>    
初始化有源标签芯片。  
 **调用形式：**     
- init(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.connectedTag/connectedTag#initialize。  
 **系统能力:**  SystemCapability.Communication.ConnectedTag  
 **需要权限：** ohos.permission.NFC_TAG    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true:初始化成功， false:初始化失败。 |  
    
## initialize<sup>(9+)</sup>    
初始化有源标签芯片。  
 **调用形式：**     
- initialize(): void  
  
 **系统能力:**  SystemCapability.Communication.ConnectedTag  
 **需要权限：** ohos.permission.NFC_TAG    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 3200101 | Connected NFC tag running state is abnormal in service. |  
    
## uninit<sup>(deprecated)</sup>    
卸载有源标签芯片资源。  
 **调用形式：**     
- uninit(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.connectedTag/connectedTag#uninitialize。  
 **系统能力:**  SystemCapability.Communication.ConnectedTag  
 **需要权限：** ohos.permission.NFC_TAG    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true:卸载操作成功， false:卸载操作失败。 |  
    
## uninitialize<sup>(9+)</sup>    
卸载有源标签芯片资源。  
  
 **调用形式：**     
- uninitialize(): void  
  
 **系统能力:**  SystemCapability.Communication.ConnectedTag  
 **需要权限：** ohos.permission.NFC_TAG    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 3200101 | Connected NFC tag running state is abnormal in service. |  
    
## readNdefTag<sup>(deprecated)</sup>    
读取有源标签内容，使用promise方式作为异步方法。  
 **调用形式：**     
- readNdefTag(): Promise\<string>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.connectedTag/connectedTag#read。  
 **系统能力:**  SystemCapability.Communication.ConnectedTag  
 **需要权限：** ohos.permission.NFC_TAG    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<string> | 返回读取有源标签内容。 |  
    
 **示例代码：**   
示例（promise）：  
  
```ts    
import connectedTag from '@ohos.connectedTag';  
import { BusinessError } from '@ohos.base';  
  
connectedTag.readNdefTag().then((data) => {  
    console.log("connectedTag readNdefTag Promise data = " + data);  
}).catch((err: BusinessError)=> {  
    console.log("connectedTag readNdefTag Promise err: " + err);  
});  
    
```    
  
    
## readNdefTag<sup>(deprecated)</sup>    
读取有源标签内容，使用AsyncCallback方式作为异步方法。  
 **调用形式：**     
- readNdefTag(callback: AsyncCallback\<string>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.connectedTag/connectedTag#read。  
 **系统能力:**  SystemCapability.Communication.ConnectedTag  
 **需要权限：** ohos.permission.NFC_TAG    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<string> | true | 读取有源标签内容回调函数。<br/> |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import connectedTag from '@ohos.connectedTag';  
  
connectedTag.readNdefTag((err, data)=> {  
    if (err) {  
        console.log("connectedTag readNdefTag AsyncCallback err: " + err);  
    } else {  
        console.log("connectedTag readNdefTag AsyncCallback data: " + data);  
    }  
});  
    
```    
  
    
## read<sup>(9+)</sup>    
读取有源标签内容，使用promise方式作为异步方法。  
 **调用形式：**     
    
- read(): Promise\<number[]>    
起始版本： 9    
- read(callback: AsyncCallback\<number[]>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Communication.ConnectedTag  
 **需要权限：** ohos.permission.NFC_TAG    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 读取有源标签内容回调函数。 |  
| Promise<number[]> | 返回读取有源标签内容。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 3200101 | Connected NFC tag running state is abnormal in service. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import connectedTag from '@ohos.connectedTag';  
  
connectedTag.read((err, data)=> {  
    if (err) {  
        console.log("connectedTag read AsyncCallback err: " + err);  
    } else {  
        console.log("connectedTag read AsyncCallback data: " + data);  
    }  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import connectedTag from '@ohos.connectedTag';  
import { BusinessError } from '@ohos.base';  
  
connectedTag.read().then((data) => {  
    console.log("connectedTag read Promise data = " + data);  
}).catch((err: BusinessError)=> {  
    console.log("connectedTag read Promise err: " + err);  
});  
    
```    
  
    
## writeNdefTag<sup>(deprecated)</sup>    
写入内容到有源标签，使用promise方式作为异步方法。  
 **调用形式：**     
- writeNdefTag(data: string): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.connectedTag/connectedTag#write。  
 **系统能力:**  SystemCapability.Communication.ConnectedTag  
 **需要权限：** ohos.permission.NFC_TAG    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| data<sup>(deprecated)</sup> | string | true | 有源标签内容, 长度最大是1024个字节。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回值。 |  
    
 **示例代码：**   
示例（promise）：  
  
```ts    
import connectedTag from '@ohos.connectedTag';  
import { BusinessError } from '@ohos.base';  
  
let rawData = "010203"; // change it tobe correct.  
connectedTag.writeNdefTag(rawData).then(() => {  
    console.log("connectedTag writeNdefTag Promise success.");  
}).catch((err: BusinessError)=> {  
    console.log("connectedTag writeNdefTag Promise err: " + err);  
});  
    
```    
  
    
## writeNdefTag<sup>(deprecated)</sup>    
写入内容到有源标签，使用AsyncCallback方式作为异步方法。  
 **调用形式：**     
- writeNdefTag(data: string, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.connectedTag/connectedTag#write。  
 **系统能力:**  SystemCapability.Communication.ConnectedTag  
 **需要权限：** ohos.permission.NFC_TAG    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| data<sup>(deprecated)</sup> | string | true | 有源标签内容, 长度最大是1024个字节。<br/> |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 读取有源标签内容回调函数。<br/> |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import connectedTag from '@ohos.connectedTag';  
  
let rawData = "010203"; // change it tobe correct.  
connectedTag.writeNdefTag(rawData, (err)=> {  
    if (err) {  
        console.log("connectedTag writeNdefTag AsyncCallback err: " + err);  
    } else {  
        console.log("connectedTag writeNdefTag AsyncCallback success.");  
    }  
});  
    
```    
  
    
## write<sup>(9+)</sup>    
写入内容到有源标签，使用promise方式作为异步方法。  
 **调用形式：**     
    
- write(data: number[]): Promise\<void>    
起始版本： 9    
- write(data: number[], callback: AsyncCallback\<void>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Communication.ConnectedTag  
 **需要权限：** ohos.permission.NFC_TAG    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| data | number[] | true | 有源标签内容, 由十六进制数字组成，范围从0x00至0xFF。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 读取有源标签内容回调函数。 |  
| Promise<void> | 无返回值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 3200101 | Connected NFC tag running state is abnormal in service. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import connectedTag from '@ohos.connectedTag';  
  
let rawData = [0x01, 0x02, 0x03]; // change it tobe correct.  
connectedTag.write(rawData, (err)=> {  
    if (err) {  
        console.log("connectedTag write NdefTag AsyncCallback err: " + err);  
    } else {  
        console.log("connectedTag write NdefTag AsyncCallback success.");  
    }  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import connectedTag from '@ohos.connectedTag';  
import { BusinessError } from '@ohos.base';  
  
let rawData = [0x01, 0x02, 0x03]; // change it tobe correct.  
connectedTag.write(rawData).then(() => {  
    console.log("connectedTag write NdefTag Promise success.");  
}).catch((err: BusinessError)=> {  
    console.log("connectedTag write NdefTag Promise err: " + err);  
});  
    
```    
  
    
## on('notify')    
注册NFC场强状态事件。  
 **调用形式：**     
    
- on(type: 'notify', callback: Callback\<number>): void    
起始版本： 8  
  
 **系统能力:**  SystemCapability.Communication.ConnectedTag  
 **需要权限：** ohos.permission.NFC_TAG    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 固定填"notify"字符串<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 状态改变回调函数，返回值参见[NfcRfType](#nfcrftype)。 |  
    
## off('notify')    
取消NFC场强状态事件的注册。  
 **调用形式：**     
    
- off(type: 'notify', callback?: Callback\<number>): void    
起始版本： 8  
  
 **系统能力:**  SystemCapability.Communication.ConnectedTag  
 **需要权限：** ohos.permission.NFC_TAG    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 固定填"notify"字符串。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 状态改变回调函数。如果callback不填，将“去注册”该事件关联的所有回调函数。 |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import connectedTag from '@ohos.connectedTag';  
// Register eventconnectedTag.on("notify", (rfState : number)=> {  console.log("connectedTag on Callback rfState: " + rfState);});  
let initStatus = connectedTag.init();console.log("connectedTag init status: " + initStatus);  
// Add nfc connecected tag business oprations here...// connectedTag.writeNdefTag(rawData)// connectedTag.readNdefTag()  
let uninitStatus = connectedTag.uninit();console.log("connectedTag uninit status: " + uninitStatus);  
// Unregister eventconnectedTag.off("notify", (rfState : number)=> {  console.log("connectedTag off Callback rfState: " + rfState);});    
```    
  
    
## NfcRfType    
表示NFC场强状态的枚举。  
    
    
 **系统能力:**  SystemCapability.Communication.ConnectedTag    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NFC_RF_LEAVE | 0 | NFC离场事件。 |  
| NFC_RF_ENTER | 1 | NFC进场事件<br/> |  
