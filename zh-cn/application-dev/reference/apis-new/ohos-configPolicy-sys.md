# @ohos.configPolicy    
配置策略提供按预先定义的定制配置层级获取对应定制配置目录和文件路径的能力。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import configPolicy from '@ohos.configPolicy'    
```  
    
## getOneCfgFile    
根据提供的跟随模式获取指定文件名的最高优先级配置文件路径，并使用Promise形式返回。  
 **调用形式：**     
    
- getOneCfgFile(relPath: string, callback: AsyncCallback\<string>)    
起始版本： 8    
- getOneCfgFile(relPath: string): Promise\<string>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.ConfigPolicy    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| relPath | string | true | 配置文件名<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步回调，用于返回文件列表 |  
| Promise<string> | 最高优先级配置文件的路径 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
  try {  
    let relpath: string = 'etc/config.xml';  
    configPolicy.getOneCfgFile(relpath, (error: BusinessError, value: string) => {  
      if (error == null) {  
        console.log('value is ' + value);  
      } else {  
        console.log('error occurs ' + error);  
      }  
    });  
  } catch (error) {  
    let code = (error as BusinessError).code;  
    let message = (error as BusinessError).message;  
    console.log('error:' + code + ',' + message);  
  }  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
  try {  
    let relpath: string = 'etc/config.xml';  
    configPolicy.getOneCfgFile(relpath).then((value: string) => {  
      console.log('value is ' + value);  
    }).catch((error: BusinessError) => {  
      console.log('getOneCfgFile promise ' + error);  
    });  
  } catch (error) {  
    let code = (error as BusinessError).code;  
    let message = (error as BusinessError).message;  
    console.log('error:' + code + ',' + message);  
  }  
    
```    
  
    
## getCfgFiles    
按优先级从低到高，使用Promise形式返回指定文件名所有的文件列表。  
 **调用形式：**     
    
- getCfgFiles(relPath: string, callback: AsyncCallback\<Array\<string>>)    
起始版本： 8    
- getCfgFiles(relPath: string): Promise\<Array\<string>>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.ConfigPolicy    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| relPath | string | true | 配置文件名<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步回调，用于返回文件列表 |  
| Promise<Array<string>> | 文件列表 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
  try {  
    let relpath: string = 'etc/config.xml';  
    configPolicy.getCfgFiles(relpath, configPolicy.FollowXMode.SIM_DEFAULT,  
      (error: BusinessError, value: Array<string>) => {  
      if (error == null) {  
        console.log('value is ' + value);  
      } else {  
        console.log('error occurs ' + error);  
      }  
    });  
  } catch (error) {  
    let code = (error as BusinessError).code;  
    let message = (error as BusinessError).message;  
    console.log('error:' + code + ',' + message);  
  }  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```null    
import { BusinessError } from '@ohos.base';  
  
  try {  
    let relpath: string = 'etc/config.xml';  
    let extra: string = 'etc/carrier/${telephony.sim.opkey0}';  
    configPolicy.getCfgFiles(relpath, configPolicy.FollowXMode.SIM_DEFAULT, extra).then((value: Array<string>) => {  
      console.log('value is ' + value);  
    }).catch((error: BusinessError) => {  
      console.log('getCfgFiles promise ' + error);  
    });  
  } catch (error) {  
    let code = (error as BusinessError).code;  
    let message = (error as BusinessError).message;  
    console.log('error:' + code + ',' + message);  
  }  
    
```    
  
    
## getCfgDirList    
返回配置层级目录列表。  
 **调用形式：**     
    
- getCfgDirList(callback: AsyncCallback\<Array\<string>>)    
起始版本： 8    
- getCfgDirList(): Promise\<Array\<string>>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.ConfigPolicy    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步回调，用于返回配置层级目录列表 |  
| Promise<Array<string>> | 配置层级目录列表 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
  try {  
    configPolicy.getCfgDirList((error: BusinessError, value: Array<string>) => {  
      if (error == null) {  
        console.log('value is ' + value);  
      } else {  
        console.log('error occurs ' + error);  
      }  
    });  
  } catch (error) {  
    let code = (error as BusinessError).code;  
    let message = (error as BusinessError).message;  
    console.log('error:' + code + ',' + message);  
  }  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```null    
import { BusinessError } from '@ohos.base';  
  
  try {  
    let relpath: string = 'etc/config.xml';  
    configPolicy.getCfgFiles(relpath).then((value: Array<string>) => {  
      console.log('value is ' + value);  
    }).catch((error: BusinessError) => {  
      console.log('getCfgFiles promise ' + error);  
    });  
  } catch (error) {  
    let code = (error as BusinessError).code;  
    let message = (error as BusinessError).message;  
    console.log('error:' + code + ',' + message);  
  }  
    
```    
  
