# @ohos.bundle.distributedBundleManager    
本模块提供分布式应用的管理能力。本模块接口为系统接口。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import distributedBundleManager from '@ohos.bundle.distributedBundleManager'    
```  
    
## getRemoteAbilityInfo    
以异步方法获取由elementName指定的远程设备上的应用的AbilityInfo信息。  
 **调用形式：**     
    
- getRemoteAbilityInfo(elementName: ElementName, callback: AsyncCallback\<RemoteAbilityInfo>): void    
起始版本： 9    
- getRemoteAbilityInfo(elementName: ElementName): Promise\<RemoteAbilityInfo>    
起始版本： 9    
- getRemoteAbilityInfo(elementNames: Array\<ElementName>,     callback: AsyncCallback\<Array\<RemoteAbilityInfo>>): void    
起始版本： 9    
- getRemoteAbilityInfo(elementNames: Array\<ElementName>): Promise\<Array\<RemoteAbilityInfo>>    
起始版本： 9    
- getRemoteAbilityInfo(elementName: ElementName,     locale: string, callback: AsyncCallback\<RemoteAbilityInfo>): void    
起始版本： 9    
- getRemoteAbilityInfo(elementName: ElementName, locale: string): Promise\<RemoteAbilityInfo>    
起始版本： 9    
- getRemoteAbilityInfo(elementNames: Array\<ElementName>,     locale: string, callback: AsyncCallback\<Array\<RemoteAbilityInfo>>): void    
起始版本： 9    
- getRemoteAbilityInfo(elementNames: Array\<ElementName>, locale: string): Promise\<Array\<RemoteAbilityInfo>>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.DistributedBundleFramework  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| elementName | ElementName | true | ElementName信息。<br/> |  
| elementNames | Array<ElementName> | true | ElementName信息,最大数组长度为10。<br/> |  
| locale | string | true | 语言地区。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，调用成功返回err为null，data为RemoteAbilityInfo对象；调用失败err为错误对象, data为undefined。 |  
| Promise<RemoteAbilityInfo> | Promise对象，调用成功返回RemoteAbilityInfo对象；调用失败返回错误对象。 |  
| Promise<Array<RemoteAbilityInfo>> | Promise对象，调用成功返回RemoteAbilityInfo对象；调用失败返回错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 17700001 | The specified bundle name is not found. |  
| 17700003 | The specified ability name is not found. |  
| 17700007 | The specified device ID is not found. |  
| 17700027 | The distributed service is not running. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import distributedBundle from '@ohos.bundle.distributedBundleManager';  
import { BusinessError } from '@ohos.base';  
  
try {  
    distributedBundle.getRemoteAbilityInfo(  
        {  
            deviceId: '1',  
            bundleName: 'com.example.application',  
            abilityName: 'EntryAbility'  
        }, (err: BusinessError, data: distributedBundle.RemoteAbilityInfo) => {  
            if (err) {  
                console.log(`Operation failed: error code is ${err.code}  and error message is ${err.message}`);  
            } else {  
                console.info('Operation succeed:' + JSON.stringify(data));  
            }  
        });  
} catch (err) {  
    let code = (err as BusinessError).code;  
    let message = (err as BusinessError).message;  
    console.log(`Operation failed: error code is ${code}  and error message is ${message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import distributedBundle from '@ohos.bundle.distributedBundleManager';  
import { BusinessError } from '@ohos.base';  
  
try {  
    distributedBundle.getRemoteAbilityInfo(  
        {  
            deviceId: '1',  
            bundleName: 'com.example.application',  
            abilityName: 'EntryAbility'  
        }).then((data: distributedBundle.RemoteAbilityInfo) => {  
            console.info('Operation succeed:' + JSON.stringify(data));  
        }).catch((err: BusinessError) => {  
            console.log(`Operation failed: error code is ${err.code}  and error message is ${err.message}`);  
        });  
} catch (err) {  
    let code = (err as BusinessError).code;  
    let message = (err as BusinessError).message;  
    console.log(`Operation failed: error code is ${code}  and error message is ${message}`);  
}  
    
```    
  
    
 **示例代码3：**   
示例（promise）：  
  
```ts    
import distributedBundle from '@ohos.bundle.distributedBundleManager';  
import { BusinessError } from '@ohos.base';  
  
try {  
    distributedBundle.getRemoteAbilityInfo(  
        [  
            {  
                deviceId: '1',  
                bundleName: 'com.example.application',  
                abilityName: 'EntryAbility'  
            },  
            {  
                deviceId: '1',  
                bundleName: 'com.example.application2',  
                abilityName: 'EntryAbility'  
            }  
        ]).then((data: distributedBundle.RemoteAbilityInfo[]) => {  
            console.info('Operation succeed:' + JSON.stringify(data));  
        }).catch((err: BusinessError) => {  
            console.log(`Operation failed: error code is ${err.code}  and error message is ${err.message}`);  
        });  
} catch (err) {  
    let code = (err as BusinessError).code;  
    let message = (err as BusinessError).message;  
    console.log(`Operation failed: error code is ${code}  and error message is ${message}`);  
}  
    
```    
  
