# @ohos.deviceAttest    
为了证明设备是OpenHarmony生态中的合法设备，设备证明模块会把设备信息通过云端进行一致性合法校验。  
通过本模块接口，可查询设备在云端校验的结果。  
。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import deviceAttest from '@ohos.deviceAttest'    
```  
    
## getAttestStatus    
获取端云校验结果的详细信息。  
 **调用形式：**     
    
- getAttestStatus(callback: AsyncCallback\<AttestResultInfo>): void    
起始版本： 9    
- getAttestStatus(): Promise\<AttestResultInfo>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当获取端云校验结果的详细信息成功，error为undefined，result为获取到的[AttestResultInfo](#attestresultinfo)；否则为错误对象。 |  
| Promise<AttestResultInfo> | Promise对象，返回端云校验结果的详细信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
| 20000001 | system service exception. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import base from '@ohos.base';  
  
try {  
    deviceAttest.getAttestStatus((error: base.BusinessError, value: deviceAttest.AttestResultInfo) => {  
    if (typeof error != 'undefined') {  
        console.info("error code:" + error.code + " message:" + error.message);  
    } else {  
        console.info("auth:" + value.authResult + " software:" + value.softwareResult + " ticket:" + value.ticket);  
        console.info("versionIdResult:" + value.softwareResultDetail[0],  
        " patchlevelResult:" + value.softwareResultDetail[1],  
        " roothashResult:" + value.softwareResultDetail[2],  
        " PCIDResult:" + value.softwareResultDetail[3],  
        " reserver:" + value.softwareResultDetail[4]);  
    }  
    })  
} catch (error) {  
    let code: number = (error as base.BusinessError).code;  
    let message: string = (error as base.BusinessError).message;  
    console.info("error code:" + code + " message:" + message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import base from '@ohos.base';  
  
try {  
    deviceAttest.getAttestStatus().then((value: deviceAttest.AttestResultInfo) => {  
    console.info("auth:" + value.authResult + " software:" + value.softwareResult + " ticket:" + value.ticket);  
    console.info("versionIdResult:" + value.softwareResultDetail[0],  
        " patchlevelResult:" + value.softwareResultDetail[1],  
        " roothashResult:" + value.softwareResultDetail[2],  
        " PCIDResult:" + value.softwareResultDetail[3],  
        " reserver:" + value.softwareResultDetail[4]);  
    }).catch((error: base.BusinessError) => {  
        console.info("error code:" + error.code + " message:" + error.message);  
    });  
} catch (error) {  
    let code: number = (error as base.BusinessError).code;  
    let message: string = (error as base.BusinessError).message;  
    console.info("error code:" + code + " message:" + message);  
}  
    
```    
  
    
## getAttestStatusSync    
以同步方式获取端云校验结果的详细信息。  
 **调用形式：**     
- getAttestStatusSync(): AttestResultInfo  
  
 **系统API:**  此接口为系统接口。    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| AttestResultInfo | 返回端云校验结果的详细信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
| 20000001 | system service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import base from '@ohos.base';  
  
try {  
    let value: deviceAttest.AttestResultInfo = deviceAttest.getAttestStatusSync();  
    console.info("auth:" + value.authResult + " software:" + value.softwareResult + " ticket:" + value.ticket);  
    console.info("versionIdResult:" + value.softwareResultDetail[0],  
    " patchlevelResult:" + value.softwareResultDetail[1],  
    " roothashResult:" + value.softwareResultDetail[2],  
    " PCIDResult:" + value.softwareResultDetail[3],  
    " reserver:" + value.softwareResultDetail[4]);  
} catch (error) {  
    let code: number = (error as base.BusinessError).code;  
    let message: string = (error as base.BusinessError).message;  
    console.info("error code:" + code + " message:" + message);  
}  
    
```    
  
    
## AttestResultInfo    
端云校验结果的详细信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.XTS.DeviceAttest  
