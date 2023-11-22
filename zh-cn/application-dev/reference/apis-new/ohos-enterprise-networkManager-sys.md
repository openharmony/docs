# @ohos.enterprise.networkManager    
本模块提供设备网络管理能力，包括查询设备IP地址、MAC地址信息等。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import networkManager from '@ohos.enterprise.networkManager'    
```  
    
## AddMethod    
添加网络包方法。    
    
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager    
 **系统接口：** 此接口为系统接口。    
    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| APPEND | 0 | 追加。 |  
| INSERT | 1 | 插入。 |  
    
## Direction    
规则链。    
    
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager    
 **系统接口：** 此接口为系统接口。    
    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| INPUT | 0 | 输入链。 |  
| OUTPUT | 1 | 输出链。 |  
    
## Action    
数据包的行为。    
    
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager    
 **系统接口：** 此接口为系统接口。    
    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| ALLOW | 0 | 接收数据包。  |  
| DENY | 1 | 丢弃数据包。 |  
    
## Protocol    
网络协议。    
    
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager    
 **系统接口：** 此接口为系统接口。    
    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| ALL | 0 | 全部网络协议。 |  
| TCP | 1 | 网络协议TCP。  |  
| UDP | 2 | 网络协议UDP。 |  
| ICMP | 3 | 网络协议ICMP。 |  
    
## AddFilterRule    
添加网络包过滤规则。  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager    
### 属性    
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager    
 **系统接口：** 此接口为系统接口。    
    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| ruleNo | number | false | false | 规则序号。 |  
| srcAddr | string | false | false | ip源地址。 |  
| destAddr | string | false | false | ip目标地址。 |  
| srcPort | string | false | false | ip源端口。 |  
| destPort | string | false | false | ip目标端口。  |  
| uid | string | false | false | 应用uid。 |  
| method | AddMethod | false | true | 添加策略。 |  
| direction | Direction | false | true | 规则链。  |  
| action | Action | false | true | 接收或者丢弃数据包。 |  
| protocol | Protocol | false | false | 网络协议。 |  
    
## RemoveFilterRule    
移除网络包过滤规则。  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager    
### 属性    
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager    
 **系统接口：** 此接口为系统接口。    
    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| srcAddr | string | false | false | ip源地址。 |  
| destAddr | string | false | false | ip目标地址。 |  
| srcPort | string | false | false | ip源端口。  |  
| destPort | string | false | false | ip目标端口。 |  
| uid | string | false | false | 应用uid。 |  
| direction | Direction | false | true | 规则链。 |  
| action | Action | false | false | 接收或者丢弃数据包。 |  
| protocol | Protocol | false | false | 网络协议。 |  
    
## getAllNetworkInterfaces    
指定设备管理应用获取所有激活的网络接口。  
 **调用形式：**     
    
- getAllNetworkInterfaces(admin: Want, callback: AsyncCallback\<Array\<string>>): void    
起始版本： 10    
- getAllNetworkInterfaces(admin: Want): Promise\<Array\<string>>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager  
 **需要权限：** ohos.permission.ENTERPRISE_GET_NETWORK_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| admin | Want | true | 设备管理应用。                |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当接口调用成功，err为null，data为网络接口名称数组，否则err为错误对象。 |  
| Promise<Array<string>> | Promise结果，返回网络接口名称数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 9200001 | the application is not an administrator of the device. |  
| 9200002 | the administrator application does not have permission to manage the device. |  
| 201 |  |  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import Want from '@ohos.app.ability.Want';  
let wantTemp: Want = {  
  bundleName: 'com.example.myapplication',  
  abilityName: 'EntryAbility',  
};  
  
networkManager.getAllNetworkInterfaces(wantTemp, (err, result) => {  
  if (err) {  
    console.error(`Failed to get all network interfaces. Code: ${err.code}, message: ${err.message}`);  
    return;  
  }  
  console.info(`Succeeded in getting all network interfaces, result : ${JSON.stringify(result)}`);  
});    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```null    
import Want from '@ohos.app.ability.Want';  
import { BusinessError } from '@ohos.base';  
let wantTemp: Want = {  
  bundleName: 'com.example.myapplication',  
  abilityName: 'EntryAbility',  
};  
  
networkManager.getAllNetworkInterfaces(wantTemp).then((result) => {  
  console.info(`Succeeded in getting all network interfaces, result : ${JSON.stringify(result)}`);  
}).catch((err: BusinessError) => {  
  console.error(`Failed to get all network interfaces. Code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
## getIpAddress    
指定设备管理应用根据网络接口获取设备IP地址。  
 **调用形式：**     
    
- getIpAddress(admin: Want, networkInterface: string, callback: AsyncCallback\<string>): void    
起始版本： 10    
- getIpAddress(admin: Want, networkInterface: string): Promise\<string>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager  
 **需要权限：** ohos.permission.ENTERPRISE_GET_NETWORK_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| admin | Want | true | 设备管理应用。       |  
| networkInterface | string | true | 指定网络接口。                  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当接口调用成功，err为null，data为IP地址，否则err为错误对象。 |  
| Promise<string> | Promise结果，返回设备IP地址。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 9200001 | the application is not an administrator of the device. |  
| 9200002 | the administrator application does not have permission to manage the device. |  
| 201 |  |  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import Want from '@ohos.app.ability.Want';  
let wantTemp: Want = {  
  bundleName: 'com.example.myapplication',  
  abilityName: 'EntryAbility',  
};  
  
networkManager.getIpAddress(wantTemp, 'eth0', (err, result) => {  
  if (err) {  
    console.error(`Failed to get ip address. Code: ${err.code}, message: ${err.message}`);  
    return;  
  }  
  console.info(`Succeeded in getting ip address, result : ${result}`);  
});    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import Want from '@ohos.app.ability.Want';  
import { BusinessError } from '@ohos.base';  
let wantTemp: Want = {  
  bundleName: 'com.example.myapplication',  
  abilityName: 'EntryAbility',  
};  
  
networkManager.getIpAddress(wantTemp, 'eth0').then((result) => {  
  console.info(`Succeeded in getting ip address, result : ${result}`);  
}).catch((err: BusinessError) => {  
  console.error(`Failed to get ip address. Code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
## getMac    
指定设备管理应用根据网络接口获取设备MAC地址。  
 **调用形式：**     
    
- getMac(admin: Want, networkInterface: string, callback: AsyncCallback\<string>): void    
起始版本： 10    
- getMac(admin: Want, networkInterface: string): Promise\<string>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager  
 **需要权限：** ohos.permission.ENTERPRISE_GET_NETWORK_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| admin | Want | true | 设备管理应用。         |  
| networkInterface | string | true | 指定网络接口。                   |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当接口调用成功，err为null，data为设备MAC地址，否则err为错误对象。 |  
| Promise<string> | Promise结果，返回设备MAC地址。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 9200001 | the application is not an administrator of the device. |  
| 9200002 | the administrator application does not have permission to manage the device. |  
| 201 |  |  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import Want from '@ohos.app.ability.Want';  
let wantTemp: Want = {  
  bundleName: 'com.example.myapplication',  
  abilityName: 'EntryAbility',  
};  
  
networkManager.getMac(wantTemp, 'eth0', (err, result) => {  
  if (err) {  
    console.error(`Failed to get mac. Code: ${err.code}, message: ${err.message}`);  
    return;  
  }  
  console.info(`Succeeded in getting mac, result : ${result}`);  
});    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
  
```ts    
import Want from '@ohos.app.ability.Want';  
import { BusinessError } from '@ohos.base';  
let wantTemp: Want = {  
  bundleName: 'com.example.myapplication',  
  abilityName: 'EntryAbility',  
};  
  
networkManager.getMac(wantTemp, 'eth0').then((result) => {  
  console.info(`Succeeded in getting mac, result : ${result}`);  
}).catch((err: BusinessError) => {  
  console.error(`Failed to get mac. Code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
## isNetworkInterfaceDisabled    
指定设备管理应用查询指定网络接口是否被禁用。  
 **调用形式：**     
    
- isNetworkInterfaceDisabled(admin: Want, networkInterface: string, callback: AsyncCallback\<boolean>): void    
起始版本： 10    
- isNetworkInterfaceDisabled(admin: Want, networkInterface: string): Promise\<boolean>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager  
 **需要权限：** ohos.permission.ENTERPRISE_GET_NETWORK_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| admin | Want | true | 设备管理应用。                   |  
| networkInterface | string | true | 指定网络接口。                   |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当接口调用成功，err为null，data为指定网络接口是否被禁用，true表示该网络接口被禁用，false表示该网络接口未被禁用，否则err为错误对象。 |  
| Promise<boolean> | Promise结果，返回指定网络接口是否被禁用，true表示该网络接口被禁用，false表示该网络接口未被禁用。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 9200001 | the application is not an administrator of the device. |  
| 9200002 | the administrator application does not have permission to manage the device. |  
| 201 |  |  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import Want from '@ohos.app.ability.Want';  
let wantTemp: Want = {  
  bundleName: 'com.example.myapplication',  
  abilityName: 'EntryAbility',  
};  
  
networkManager.isNetworkInterfaceDisabled(wantTemp, 'eth0', (err, result) => {  
  if (err) {  
    console.error(`Failed to query network interface is disabled or not. Code: ${err.code}, message: ${err.message}`);  
    return;  
  }  
  console.info(`Succeeded in querying network interface is disabled or not, result : ${result}`);  
});    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import Want from '@ohos.app.ability.Want';  
import { BusinessError } from '@ohos.base';  
let wantTemp: Want = {  
  bundleName: 'com.example.myapplication',  
  abilityName: 'EntryAbility',  
};  
  
networkManager.isNetworkInterfaceDisabled(wantTemp, 'eth0').then((result) => {  
  console.info(`Succeeded in querying network interface is disabled or not, result : ${result}`);  
}).catch((err: BusinessError) => {  
  console.error(`Failed to query network interface is disabled or not. Code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
## setNetworkInterfaceDisabled    
指定设备管理应用禁止设备使用指定网络。  
 **调用形式：**     
    
- setNetworkInterfaceDisabled(admin: Want, networkInterface: string, isDisabled: boolean, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setNetworkInterfaceDisabled(admin: Want, networkInterface: string, isDisabled: boolean): Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager  
 **需要权限：** ohos.permission.ENTERPRISE_SET_NETWORK    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| admin | Want | true | 设备管理应用。    |  
| networkInterface | string | true | 指定网络接口。      |  
| isDisabled | boolean | true | true表示禁用该网络接口，false表示开启该网络接口。          |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当接口调用成功，err为null，否则err为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。当禁用网络接口失败时抛出错误对象 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 9200001 | the application is not an administrator of the device. |  
| 9200002 | the administrator application does not have permission to manage the device. |  
| 201 |  |  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import Want from '@ohos.app.ability.Want';  
let wantTemp: Want = {  
  bundleName: 'com.example.myapplication',  
  abilityName: 'EntryAbility',  
};  
  
networkManager.setNetworkInterfaceDisabled(wantTemp, 'eth0', true, (err) => {  
  if (err) {  
    console.error(`Failed to set network interface disabled. Code: ${err.code}, message: ${err.message}`);  
    return;  
  }  
  console.info(`Succeeded in setting network interface disabled`);  
});    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import Want from '@ohos.app.ability.Want';  
import { BusinessError } from '@ohos.base';  
let wantTemp: Want = {  
  bundleName: 'com.example.myapplication',  
  abilityName: 'EntryAbility',  
};  
  
networkManager.setNetworkInterfaceDisabled(wantTemp, 'eth0', true).then(() => {  
  console.info(`Succeeded in setting network interface disabled`);  
}).catch((err: BusinessError) => {  
  console.error(`Failed to set network interface disabled. Code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
## setGlobalProxy    
指定设备管理应用设置网络全局代理  
 **调用形式：**     
    
- setGlobalProxy(admin: Want, httpProxy: connection.HttpProxy, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setGlobalProxy(admin: Want, httpProxy: connection.HttpProxy): Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager  
 **需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| admin | Want | true | 设备管理应用。                  |  
| httpProxy | connection.HttpProxy | true | 网络全局Http代理配置信息。     |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当接口调用成功，err为null，否则err为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。当设置网络全局代理失败时抛出错误对象 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 9200001 | the application is not an administrator of the device. |  
| 9200002 | the administrator application does not have permission to manage the device. |  
| 201 |  |  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import Want from '@ohos.app.ability.Want';  
import connection from '@ohos.net.connection';  
let wantTemp: Want = {  
  bundleName: 'com.example.myapplication',  
  abilityName: 'EntryAbility',  
};  
let exclusionStr: string = "192.168,baidu.com"  
let exclusionArray: Array<string> = exclusionStr.split(',');  
let httpProxy: connection.HttpProxy = {  
  host: "192.168.xx.xxx",  
  port: 8080,  
  exclusionList: exclusionArray  
};  
  
networkManager.setGlobalProxy(wantTemp, httpProxy, (err) => {  
  if (err) {  
    console.error(`Failed to set network global proxy. Code: ${err.code}, message: ${err.message}`);  
    return;  
  }  
  console.info(`Succeeded in setting network global proxy`);  
});    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import Want from '@ohos.app.ability.Want';  
import { BusinessError } from '@ohos.base';  
import connection from '@ohos.net.connection';  
let wantTemp: Want = {  
  bundleName: 'com.example.myapplication',  
  abilityName: 'EntryAbility',  
};  
let exclusionStr: string = "192.168,baidu.com"  
let exclusionArray: Array<string> = exclusionStr.split(',');  
let httpProxy: connection.HttpProxy = {  
  host: "192.168.xx.xxx",  
  port: 8080,  
  exclusionList: exclusionArray  
};  
  
networkManager.setGlobalProxy(wantTemp, httpProxy).then(() => {  
  console.info(`Succeeded in setting network global proxy`);  
}).catch((err: BusinessError) => {  
  console.error(`Failed to set network global proxy. Code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
## getGlobalProxy    
指定设备管理应用获取网络全局代理  
 **调用形式：**     
    
- getGlobalProxy(admin: Want, callback: AsyncCallback\<connection.HttpProxy>): void    
起始版本： 10    
- getGlobalProxy(admin: Want): Promise\<connection.HttpProxy>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager  
 **需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| admin | Want | true | 设备管理应用。               |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当接口调用成功，err为null，否则err为错误对象。 |  
| Promise<connection.HttpProxy> | Promise对象，返回网络全局Http代理配置信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 9200001 | the application is not an administrator of the device. |  
| 9200002 | the administrator application does not have permission to manage the device. |  
| 201 |  |  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import Want from '@ohos.app.ability.Want';  
let wantTemp: Want = {  
  bundleName: 'com.example.myapplication',  
  abilityName: 'EntryAbility',  
};  
  
networkManager.getGlobalProxy(wantTemp, (err, result) => {  
  if (err) {  
    console.error(`Failed to get network global proxy. Code: ${err.code}, message: ${err.message}`);  
    return;  
  }  
  console.info(`Succeeded in getting network global proxy, result : ${JSON.stringify(result)}`);  
});    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import Want from '@ohos.app.ability.Want';  
import { BusinessError } from '@ohos.base';  
let wantTemp: Want = {  
  bundleName: 'com.example.myapplication',  
  abilityName: 'EntryAbility',  
};  
  
networkManager.getGlobalProxy(wantTemp).then(() => {  
  console.info(`Succeeded in getting network global proxy`);  
}).catch((err: BusinessError) => {  
  console.error(`Failed to get network global proxy. Code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
## addIptablesFilterRule    
指定设备管理应用为设备添加网络包过滤规则。  
 **调用形式：**     
    
- addIptablesFilterRule(admin: Want, filterRule: AddFilterRule, callback: AsyncCallback\<void>): void    
起始版本： 10    
- addIptablesFilterRule(admin: Want, filterRule: AddFilterRule): Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager  
 **需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| admin | Want | true | 设备管理应用。                  |  
| filterRule | AddFilterRule | true | 添加网络包过滤规则。             |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当接口调用成功，err为null，否则err为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。当添加网络包过滤规则失败时抛出错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 9200001 | the application is not an administrator of the device. |  
| 9200002 | the administrator application does not have permission to manage the device. |  
| 201 |  |  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import Want from '@ohos.app.ability.Want';  
let wantTemp: Want = {  
  bundleName: 'com.example.myapplication',  
  abilityName: 'EntryAbility',  
};  
let filterRule: networkManager.AddFilterRule = {  
  "ruleNo": 1,  
  "srcAddr": "192.168.1.1-192.168.255.255",  
  "destAddr": "10.1.1.1",  
  "srcPort": "8080",  
  "destPort": "8080",  
  "uid": "9696",  
  "method": networkManager.AddMethod.APPEND,  
  "direction": networkManager.Direction.OUTPUT,  
  "action": networkManager.Action.DENY,  
  "protocol": networkManager.Protocol.UDP,  
}  
  
networkManager.addIptablesFilterRule(wantTemp, filterRule, (err) => {  
  if (err) {  
    console.error(`Failed to set iptables filter rule. Code: ${err.code}, message: ${err.message}`);  
    return;  
  }  
  console.info(`Succeeded in setting iptables filter rule`);  
});    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import Want from '@ohos.app.ability.Want';  
import { BusinessError } from '@ohos.base';  
let wantTemp: Want = {  
  bundleName: 'com.example.myapplication',  
  abilityName: 'EntryAbility',  
};  
let filterRule: networkManager.AddFilterRule = {  
  "ruleNo": 1,  
  "srcAddr": "192.168.1.1-192.168.255.255",  
  "destAddr": "10.1.1.1",  
  "srcPort": "8080",  
  "destPort": "8080",  
  "uid": "9696",  
  "method": networkManager.AddMethod.APPEND,  
  "direction": networkManager.Direction.OUTPUT,  
  "action": networkManager.Action.DENY,  
  "protocol": networkManager.Protocol.UDP,  
}  
  
networkManager.addIptablesFilterRule(wantTemp, filterRule).then(() => {  
  console.info(`Succeeded in setting iptables filter rule`);  
}).catch((err: BusinessError) => {  
  console.error(`Failed to set iptables filter rule. Code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
## removeIptablesFilterRule    
指定设备管理应用移除网络包过滤规则。  
 **调用形式：**     
    
- removeIptablesFilterRule(admin: Want, filterRule: RemoveFilterRule, callback: AsyncCallback\<void>): void    
起始版本： 10    
- removeIptablesFilterRule(admin: Want, filterRule: RemoveFilterRule): Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager  
 **需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| admin | Want | true | 设备管理应用。          |  
| filterRule | RemoveFilterRule | true | 移除网络包过滤规则。        |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当接口调用成功，err为null，否则err为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。当移除网络包过滤规则失败时抛出错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 9200001 | the application is not an administrator of the device. |  
| 9200002 | the administrator application does not have permission to manage the device. |  
| 201 |  |  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback<span style="letter-spacing: 0px;">）：</span>  
```ts    
import Want from '@ohos.app.ability.Want';  
let wantTemp: Want = {  
  bundleName: 'com.example.myapplication',  
  abilityName: 'EntryAbility',  
};  
let filterRule: networkManager.RemoveFilterRule = {  
  "srcAddr": "192.168.1.1-192.168.255.255",  
  "destAddr": "10.1.1.1",  
  "srcPort": "8080",  
  "destPort": "8080",  
  "uid": "9696",  
  "direction": networkManager.Direction.OUTPUT,  
  "action": networkManager.Action.DENY,  
  "protocol": networkManager.Protocol.UDP,  
}  
  
networkManager.removeIptablesFilterRule(wantTemp, filterRule, (err) => {  
  if (err) {  
    console.error(`Failed to remove iptables filter rule. Code: ${err.code}, message: ${err.message}`);  
    return;  
  }  
  console.info(`Succeeded in removing iptables filter rule`);  
});    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import Want from '@ohos.app.ability.Want';  
import { BusinessError } from '@ohos.base';  
let wantTemp: Want = {  
  bundleName: 'com.example.myapplication',  
  abilityName: 'EntryAbility',  
};  
let filterRule: networkManager.RemoveFilterRule = {  
  "srcAddr": "192.168.1.1-192.168.255.255",  
  "destAddr": "10.1.1.1",  
  "srcPort": "8080",  
  "destPort": "8080",  
  "uid": "9696",  
  "direction": networkManager.Direction.OUTPUT,  
  "action": networkManager.Action.DENY,  
  "protocol": networkManager.Protocol.UDP,  
}  
  
networkManager.removeIptablesFilterRule(wantTemp, filterRule).then(() => {  
  console.info(`Succeeded in removing iptables filter rule`);  
}).catch((err: BusinessError) => {  
  console.error(`Failed to remove iptables filter rule. Code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
    
## listIptablesFilterRules    
指定设备管理应用获取网络包过滤规则。  
 **调用形式：**     
    
- listIptablesFilterRules(admin: Want, callback: AsyncCallback\<string>): void    
起始版本： 10    
- listIptablesFilterRules(admin: Want): Promise\<string>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager  
 **需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| admin | Want | true | 设备管理应用。                |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当接口调用成功，err为null，否则err为错误对象。 |  
| Promise<string> | Promise对象,返回网络包过滤规则。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 9200001 | the application is not an administrator of the device. |  
| 9200002 | the administrator application does not have permission to manage the device. |  
| 201 |  |  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import Want from '@ohos.app.ability.Want';  
let wantTemp: Want = {  
  bundleName: 'com.example.myapplication',  
  abilityName: 'EntryAbility',  
};  
  
networkManager.listIptablesFilterRules(wantTemp, (err, result) => {  
  if (err) {  
    console.error(`Failed to get iptables filter rule. Code: ${err.code}, message: ${err.message}`);  
    return;  
  }  
  console.info(`Succeeded in getting iptables filter rule, result : ${result}`);  
});    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import Want from '@ohos.app.ability.Want';  
import { BusinessError } from '@ohos.base';  
let wantTemp: Want = {  
  bundleName: 'com.example.myapplication',  
  abilityName: 'EntryAbility',  
};  
  
networkManager.listIptablesFilterRules(wantTemp).then((result) => {  
  console.info(`Succeeded in getting iptables filter rule, result: ${result}`);  
}).catch((err: BusinessError) => {  
  console.error(`Failed to remove iptables filter rule. Code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
