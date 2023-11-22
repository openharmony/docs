# tagSession    
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## TagSession    
本模块是对NFC TagSession的使用说明。  
 **系统能力:**  SystemCapability.Communication.NFC.Tag    
### getTagInfo<sup>(deprecated)</sup>    
获取该Tag被分发时，NFC服务所提供的Tag数据对象。  
 **调用形式：**     
- getTagInfo(): tag.TagInfo  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.nfc.tag/tag#getTagInfo。  
 **系统能力:**  SystemCapability.Communication.NFC.Tag  
 **需要权限：** ohos.permission.NFC_TAG    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| tag.TagInfo | NFC服务所提供的Tag数据对象。 |  
    
 **示例代码：**   
```js    
import tag from '@ohos.nfc.tag';  
// see 'tag.TagInfo' at 'js-apis-nfcTag.md', tagInfo is an Object given by nfc service when tag is dispatched.// the folowing getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...  
let tagInfo : TagInfo = tag.getIsoDep(tagInfo).getTagInfo();console.log("tag tagInfo: " + tagInfo);    
```    
  
    
### connectTag<sup>(deprecated)</sup>    
和标签建立连接。在从标签读取数据或将数据写入标签之前，必须调用此方法。  
 **调用形式：**     
- connectTag(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: tagSession.TagSession#connect。  
 **系统能力:**  SystemCapability.Communication.NFC.Tag  
 **需要权限：** ohos.permission.NFC_TAG    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 连接建立成功返回true，失败返回false。 |  
    
 **示例代码：**   
```js    
import tag from '@ohos.nfc.tag';  
// see 'tag.TagInfo' at 'js-apis-nfcTag.md', tagInfo is an Object given by nfc service when tag is dispatched.// the folowing getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...  
let connectStatus : boolean = tag.getIsoDep(tagInfo).connectTag();console.log("connectStatus: " + connectStatus);    
```    
  
    
### connect<sup>(9+)</sup>    
和标签建立连接。在从标签读取数据或将数据写入标签之前，必须调用此方法。  
 **调用形式：**     
- connect(): void  
  
 **系统能力:**  SystemCapability.Communication.NFC.Tag  
 **需要权限：** ohos.permission.NFC_TAG    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 3100201 | Tag running state is abnormal in service. |  
    
 **示例代码：**   
```js    
import tag from '@ohos.nfc.tag';  
  
// see 'tag.TagInfo' at 'js-apis-nfcTag.md', tagInfo is an Object given by nfc service when tag is dispatched.  
// the folowing getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...  
  
try {  
    tag.getIsoDep(tagInfo).connect();   
    console.log("tag connect success");  
} catch (busiError) {  
    console.log("tag connect busiError: " + busiError);  
}  
    
```    
  
    
### reset<sup>(deprecated)</sup>    
重置与标签的连接。  
 **调用形式：**     
- reset(): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: tagSession.TagSession#resetConnection。  
 **系统能力:**  SystemCapability.Communication.NFC.Tag  
 **需要权限：** ohos.permission.NFC_TAG    
 **示例代码：**   
```ts    
import tag from '@ohos.nfc.tag';  
// see 'tag.TagInfo' at 'js-apis-nfcTag.md', tagInfo is an Object given by nfc service when tag is dispatched.// the folowing getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...tag.getIsoDep(tagInfo).reset();    
```    
  
    
### resetConnection<sup>(9+)</sup>    
重置与标签的连接。  
 **调用形式：**     
- resetConnection(): void  
  
 **系统能力:**  SystemCapability.Communication.NFC.Tag  
 **需要权限：** ohos.permission.NFC_TAG    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 3100201 | Tag running state is abnormal in service. |  
    
 **示例代码：**   
```js    
import tag from '@ohos.nfc.tag';  
  
// see 'tag.TagInfo' at 'js-apis-nfcTag.md', tagInfo is an Object given by nfc service when tag is dispatched.  
// the folowing getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...  
  
try {  
    tag.getIsoDep(tagInfo).resetConnection();   
    console.log("tag resetConnection success");  
} catch (busiError) {  
    console.log("tag resetConnection busiError: " + busiError);  
}  
    
```    
  
    
### isTagConnected<sup>(deprecated)</sup>    
检查是否已与标签建立连接。  
 **调用形式：**     
- isTagConnected(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: tagSession.TagSession#isConnected。  
 **系统能力:**  SystemCapability.Communication.NFC.Tag    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true，未建立连接返回false。 |  
    
 **示例代码：**   
```js    
import tag from '@ohos.nfc.tag';  
// see 'tag.TagInfo' at 'js-apis-nfcTag.md', tagInfo is an Object given by nfc service when tag is dispatched.// the folowing getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...  
let isTagConnected = tag.getIsoDep(tagInfo).isTagConnected(); console.log("isTagConnected: " + isTagConnected);    
```    
  
    
### isConnected<sup>(9+)</sup>    
检查是否已与标签建立连接。  
 **调用形式：**     
- isConnected(): boolean  
  
 **系统能力:**  SystemCapability.Communication.NFC.Tag    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 已建立连接返回 true，未建立连接返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 801 |  |  
    
 **示例代码：**   
```js    
import tag from '@ohos.nfc.tag';  
  
// see 'tag.TagInfo' at 'js-apis-nfcTag.md', tagInfo is an Object given by nfc service when tag is dispatched.  
// the folowing getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...  
  
try {  
    let isConnected = tag.getIsoDep(tagInfo).isConnected();   
    console.log("tag isConnected = " + isConnected);  
} catch (busiError) {  
    console.log("tag isConnected busiError: " + busiError);  
}  
    
```    
  
    
### setSendDataTimeout<sup>(deprecated)</sup>    
查询发送数据到Tag的等待超时时间，单位是毫秒。  
 **调用形式：**     
- setSendDataTimeout(timeout: number): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: tagSession.TagSession#setTimeout。  
 **系统能力:**  SystemCapability.Communication.NFC.Tag  
 **需要权限：** ohos.permission.NFC_TAG    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| timeout<sup>(deprecated)</sup> | number | true | 超时时间，单位毫秒，非负值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 设置超时时间成功返回true，设置失败返回false。 |  
    
 **示例代码：**   
```js    
import tag from '@ohos.nfc.tag';  
// see 'tag.TagInfo' at 'js-apis-nfcTag.md', tagInfo is an Object given by nfc service when tag is dispatched.// the folowing getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...  
let timeoutMs = 700;  // change it to be correct.let setStatus = tag.getIsoDep(tagInfo).setSendDataTimeout(timeoutMs); console.log("tag setSendDataTimeout setStatus: " + setStatus);    
```    
  
    
### setTimeout<sup>(9+)</sup>    
查询发送数据到Tag的等待超时时间，单位是毫秒。  
 **调用形式：**     
- setTimeout(timeout: number): void  
  
 **系统能力:**  SystemCapability.Communication.NFC.Tag  
 **需要权限：** ohos.permission.NFC_TAG    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| timeout | number | true | 超时时间，单位毫秒，非负值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 3100201 | Tag running state is abnormal in service. |  
    
 **示例代码：**   
```js    
import tag from '@ohos.nfc.tag';  
  
// see 'tag.TagInfo' at 'js-apis-nfcTag.md', tagInfo is an Object given by nfc service when tag is dispatched.  
// the folowing getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...  
  
let timeoutMs = 700;  // change it to be correct.  
try {  
    tag.getIsoDep(tagInfo).setTimeout(timeoutMs);   
    console.log("tag setTimeout success");  
} catch (busiError) {  
    console.log("tag setTimeout busiError: " + busiError);  
}  
    
```    
  
    
### getSendDataTimeout<sup>(deprecated)</sup>    
查询发送数据到Tag的等待超时时间，单位是毫秒。  
 **调用形式：**     
- getSendDataTimeout(): number  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: tagSession.TagSession#getTimeout。  
 **系统能力:**  SystemCapability.Communication.NFC.Tag  
 **需要权限：** ohos.permission.NFC_TAG    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 发送数据到Tag的等待超时时间，单位是毫秒，非负数。 |  
    
 **示例代码：**   
```js    
import tag from '@ohos.nfc.tag';  
// see 'tag.TagInfo' at 'js-apis-nfcTag.md', tagInfo is an Object given by nfc service when tag is dispatched.// the folowing getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...  
let sendDataTimeout = tag.getIsoDep(tagInfo).getSendDataTimeout(); console.log("tag sendDataTimeout: " + sendDataTimeout);    
```    
  
    
### getTimeout<sup>(9+)</sup>    
查询发送数据到Tag的等待超时时间，单位是毫秒。  
 **调用形式：**     
- getTimeout(): number  
  
 **系统能力:**  SystemCapability.Communication.NFC.Tag  
 **需要权限：** ohos.permission.NFC_TAG    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 发送数据到Tag的等待超时时间，单位是毫秒，非负数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 3100201 | Tag running state is abnormal in service. |  
    
 **示例代码：**   
```js    
import tag from '@ohos.nfc.tag';  
  
// see 'tag.TagInfo' at 'js-apis-nfcTag.md', tagInfo is an Object given by nfc service when tag is dispatched.  
// the folowing getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...  
  
try {  
    let timeout = tag.getIsoDep(tagInfo).getTimeout();   
    console.log("tag timeout = " + timeout);  
} catch (busiError) {  
    console.log("tag getTimeout busiError: " + busiError);  
}  
    
```    
  
    
### sendData<sup>(deprecated)</sup>    
发送指令到Tag上。  
 **调用形式：**     
- sendData(data: number[]): Promise\<number[]>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: tagSession.TagSession#transmit。  
 **系统能力:**  SystemCapability.Communication.NFC.Tag  
 **需要权限：** ohos.permission.NFC_TAG    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| data<sup>(deprecated)</sup> | number[] | true | 要发送的指令。每个number十六进制表示，范围是0x00 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number[]> | 对端Tag对指令的响应数据。每个number十六进制表示，范围是0x00~0xFF。 |  
    
 **示例代码：**   
```js    
import tag from '@ohos.nfc.tag';  
import { BusinessError } from '@ohos.base';  
  
// see 'tag.TagInfo' at 'js-apis-nfcTag.md', tagInfo is an Object given by nfc service when tag is dispatched.  
// the folowing getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...  
  
// connect the tag at first if not connected.  
if (!tag.getIsoDep(tagInfo).isTagConnected()) {  
  if (!tag.getIsoDep(tagInfo).connectTag()) {  
    console.log("tagSession connectTag failed.");  
    return;  
  }  
}  
  
let cmdData = [0x01, 0x02, 0x03, 0x04]; // change the raw data to be correct.  
tag.getIsoDep(tagInfo).sendData(cmdData).then((response) => {  
  console.log("tagSession sendData Promise response: " + response);  
}).catch((err : BusinessError)=> {  
  console.log("tagSession sendData Promise err: " + err);  
});  
    
```    
  
    
### sendData<sup>(deprecated)</sup>  
 **调用形式：**     
- sendData(data: number[], callback: AsyncCallback\<number[]>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: tagSession.TagSession#transmit。  
 **系统能力:**  SystemCapability.Communication.NFC.Tag  
 **需要权限：** ohos.permission.NFC_TAG    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| data<sup>(deprecated)</sup> | number[] | true |  |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number[]> | true |  |  
    
 **示例代码：**   
```js    
import tag from '@ohos.nfc.tag';  
  
// see 'tag.TagInfo' at 'js-apis-nfcTag.md', tagInfo is an Object given by nfc service when tag is dispatched.  
// the folowing getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...  
  
// connect the tag at first if not connected.  
if (!tag.getIsoDep(tagInfo).isTagConnected()) {  
    if (!tag.getIsoDep(tagInfo).connectTag()) {  
        console.log("tagSession connectTag failed.");  
        return;  
    }  
}  
  
let cmdData = [0x01, 0x02, 0x03, 0x04]; // change the raw data to be correct.  
tag.getIsoDep(tagInfo).sendData(cmdData, (err, response)=> {  
    if (err) {  
        console.log("tagSession sendData AsyncCallback err: " + err);  
    } else {  
        console.log("tagSession sendData AsyncCallback response: " + response);  
    }  
});  
    
```    
  
    
### transmit<sup>(9+)</sup>    
发送指令到Tag上  
 **调用形式：**     
    
- transmit(data: number[]): Promise\<number[]>    
起始版本： 9    
- transmit(data: number[], callback: AsyncCallback\<number[]>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Communication.NFC.Tag  
 **需要权限：** ohos.permission.NFC_TAG    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| data | number[] | true | 要发送的指令。每个number十六进制表示，范围是0x00~0xFF。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<number[]> | 端Tag对指令的响应数据。每个number十六进制表示，范围是0x00~0xFF。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 3100201 | Tag running state is abnormal in service. |  
    
 **示例代码1：**   
示例(Promise):  
```js    
import tag from '@ohos.nfc.tag';  
import { BusinessError } from '@ohos.base';  
  
// see 'tag.TagInfo' at 'js-apis-nfcTag.md', tagInfo is an Object given by nfc service when tag is dispatched.  
// the folowing getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...  
  
// connect the tag at first if not connected.  
try {  
  if (!tag.getIsoDep(tagInfo).isConnected()) {  
    tag.getIsoDep(tagInfo).connect();  
  }  
} catch (busiError) {  
  console.log("tag connect busiError: " + busiError);  
  return;  
}  
  
let cmdData = [0x01, 0x02, 0x03, 0x04]; // change the raw data to be correct.  
try {  
  tag.getIsoDep(tagInfo).transmit(cmdData).then((response) => {  
    console.log("tagSession transmit Promise response: " + response);  
  }).catch((err : BusinessError)=> {  
    console.log("tagSession transmit Promise err: " + err);  
  });  
} catch (busiError) {  
  console.log("tag transmit busiError: " + busiError);  
  return;  
}  
    
```    
  
    
 **示例代码2：**   
示例(callback):  
```js    
import tag from '@ohos.nfc.tag';  
  
// see 'tag.TagInfo' at 'js-apis-nfcTag.md', tagInfo is an Object given by nfc service when tag is dispatched.  
// the folowing getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...  
  
// connect the tag at first if not connected.  
try {  
    if (!tag.getIsoDep(tagInfo).isConnected()) {  
        tag.getIsoDep(tagInfo).connect();  
    }  
} catch (busiError) {  
    console.log("tag connect busiError: " + busiError);  
    return;  
}  
  
let cmdData = [0x01, 0x02, 0x03, 0x04]; // change the raw data to be correct.  
try {  
    tag.getIsoDep(tagInfo).transmit(cmdData, (err, response)=> {  
        if (err) {  
            console.log("tagSession transmit AsyncCallback err: " + err);  
        } else {  
            console.log("tagSession transmit AsyncCallback response: " + response);  
        }  
    });  
} catch (busiError) {  
    console.log("tag transmit busiError: " + busiError);  
    return;  
}  
    
```    
  
    
### getMaxSendLength<sup>(deprecated)</sup>    
查询可以发送到标签的最大数据长度。  
 **调用形式：**     
- getMaxSendLength(): number  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: tagSession.TagSession#getMaxTransmitSize。  
 **系统能力:**  SystemCapability.Communication.NFC.Tag  
 **需要权限：** ohos.permission.NFC_TAG    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 可以发送到标签的最大数据长度，非负数。 |  
    
 **示例代码：**   
```js    
import tag from '@ohos.nfc.tag';  
// see 'tag.TagInfo' at 'js-apis-nfcTag.md', tagInfo is an Object given by nfc service when tag is dispatched.// the folowing getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...  
let maxSendLen = tag.getIsoDep(tagInfo).getMaxSendLength(); console.log("tag maxSendLen: " + maxSendLen);    
```    
  
    
### getMaxTransmitSize<sup>(9+)</sup>    
查询可以发送到标签的最大数据长度。  
 **调用形式：**     
- getMaxTransmitSize(): number  
  
 **系统能力:**  SystemCapability.Communication.NFC.Tag  
 **需要权限：** ohos.permission.NFC_TAG    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 可以发送到标签的最大数据长度，非负数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 3100201 | Tag running state is abnormal in service. |  
    
 **示例代码：**   
```js    
import tag from '@ohos.nfc.tag';  
  
// see 'tag.TagInfo' at 'js-apis-nfcTag.md', tagInfo is an Object given by nfc service when tag is dispatched.  
// the folowing getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...  
  
try {  
    let maxTransmitSize = tag.getIsoDep(tagInfo).getMaxTransmitSize();   
    console.log("tag maxTransmitSize = " + maxTransmitSize);  
} catch (busiError) {  
    console.log("tag getMaxTransmitSize busiError: " + busiError);  
}  
    
```    
  
