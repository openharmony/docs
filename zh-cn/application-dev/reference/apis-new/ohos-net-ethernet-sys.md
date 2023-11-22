# @ohos.net.ethernet    
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import ethernet from '@ohos.net.ethernet'    
```  
    
## getIfaceConfig    
获取指定网络接口信息，使用callback方式作为异步方法。  
 **调用形式：**     
    
- getIfaceConfig(iface: string, callback: AsyncCallback\<InterfaceConfiguration>): void    
起始版本： 9    
- getIfaceConfig(iface: string): Promise\<InterfaceConfiguration>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Ethernet  
 **需要权限：** ohos.permission.GET_NETWORK_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| iface | string | true | 指定网络接口 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回指定网络接口信息 |  
| Promise<InterfaceConfiguration> | 以Promise形式返回接口信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 2200001 | Invalid parameter value. |  
| 2200002 | Operation failed. Cannot connect to service. |  
| 2200003 | System internal error. |  
| 2201005 | Device information does not exist. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
import ethernet from '@ohos.net.ethernet'  
import { BusinessError } from '@ohos.base'  
  
ethernet.getIfaceConfig("eth0", (error: BusinessError, value: ethernet.InterfaceConfiguration) => {  
  if (error) {  
    console.log("getIfaceConfig  callback error = " + JSON.stringify(error));  
  } else {  
    console.log("getIfaceConfig callback mode = " + JSON.stringify(value.mode));  
    console.log("getIfaceConfig callback ipAddr = " + JSON.stringify(value.ipAddr));  
    console.log("getIfaceConfig callback route = " + JSON.stringify(value.route));  
    console.log("getIfaceConfig callback gateway = " + JSON.stringify(value.gateway));  
    console.log("getIfaceConfig callback netMask = " + JSON.stringify(value.netMask));  
    console.log("getIfaceConfig callback dnsServers = " + JSON.stringify(value.dnsServers));  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
import ethernet from '@ohos.net.ethernet'  
import { BusinessError } from '@ohos.base'  
  
ethernet.getIfaceConfig("eth0").then((data: ethernet.InterfaceConfiguration) => {  
  console.log("getIfaceConfig promise mode = " + JSON.stringify(data.mode));  
  console.log("getIfaceConfig promise ipAddr = " + JSON.stringify(data.ipAddr));  
  console.log("getIfaceConfig promise route = " + JSON.stringify(data.route));  
  console.log("getIfaceConfig promise gateway = " + JSON.stringify(data.gateway));  
  console.log("getIfaceConfig promise netMask = " + JSON.stringify(data.netMask));  
  console.log("getIfaceConfig promise dnsServers = " + JSON.stringify(data.dnsServers));  
}).catch((error: BusinessError) => {  
  console.log("getIfaceConfig promise error = " + JSON.stringify(error));  
});  
    
```    
  
    
## setIfaceConfig    
设置网络接口配置信息，使用callback方式作为异步方法。  
 **调用形式：**     
    
- setIfaceConfig(iface: string, ic: InterfaceConfiguration, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setIfaceConfig(iface: string, ic: InterfaceConfiguration): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Ethernet  
 **需要权限：** ohos.permission.CONNECTIVITY_INTERNAL    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| iface | string | true | 网络接口名 |  
| ic | InterfaceConfiguration | true | 要设置的网络接口配置信息 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，成功无返回，失败返回对应错误码。 |  
| Promise<void> | 以Promise形式返回执行结果。成功无返回，失败返回对应错误码。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 2200001 | Invalid parameter value. |  
| 2200002 | Operation failed. Cannot connect to service. |  
| 2200003 | System internal error. |  
| 2201004 | Invalid Ethernet profile. |  
| 2201005 | Device information does not exist. |  
| 2201006 | Ethernet device not connected. |  
| 2201007 | Ethernet failed to write user configuration information. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
import ethernet from '@ohos.net.ethernet'  
import { BusinessError } from '@ohos.base'  
  
let config: ethernet.InterfaceConfiguration = {  
  mode: 0,  
  ipAddr: "192.168.xx.xxx",  
  route: "192.168.xx.xxx",  
  gateway: "192.168.xx.xxx",  
  netMask: "255.255.255.0",  
  dnsServers: "1.1.1.1"  
};  
  
ethernet.setIfaceConfig("eth0", config, (error: BusinessError) => {  
  if (error) {  
    console.log("setIfaceConfig callback error = " + JSON.stringify(error));  
  } else {  
    console.log("setIfaceConfig callback ok");  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
import ethernet from '@ohos.net.ethernet'  
import { BusinessError } from '@ohos.base'  
  
let config: ethernet.InterfaceConfiguration = {  
  mode: 0,  
  ipAddr: "192.168.xx.xxx",  
  route: "192.168.xx.xxx",  
  gateway: "192.168.xx.xxx",  
  netMask: "255.255.255.0",  
  dnsServers: "1.1.1.1"  
};  
  
const setConfigPromise = ethernet.setIfaceConfig("eth0", config);  
  
setConfigPromise.then(() => {  
  console.log("setIfaceConfig promise ok");  
}).catch((error: BusinessError)  => {  
  console.log("setIfaceConfig promise error = " + JSON.stringify(error));  
});  
    
```    
  
    
## isIfaceActive    
判断接口是否已激活，使用callback方式作为异步方法。  
 **调用形式：**     
    
- isIfaceActive(iface: string, callback: AsyncCallback\<number>): void    
起始版本： 9    
- isIfaceActive(iface: string): Promise\<number>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Ethernet  
 **需要权限：** ohos.permission.GET_NETWORK_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| iface | string | true | 接口名。为空时代表查询是否存在激活接口 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，已激活:1,未激活:0,其他为获取失败错误码。 |  
| Promise<number> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 2200001 | Invalid parameter value. |  
| 2200002 | Operation failed. Cannot connect to service. |  
| 2200003 | System internal error. |  
| 2201005 | Device information does not exist.  | |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
import ethernet from '@ohos.net.ethernet'  
import { BusinessError } from '@ohos.base'  
  
ethernet.isIfaceActive("eth0", (error: BusinessError, value: number) => {  
  if (error) {  
    console.log("whether2Activate callback error = " + JSON.stringify(error));  
  } else {  
    console.log("whether2Activate callback = " + JSON.stringify(value));  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
import ethernet from '@ohos.net.ethernet'  
import { BusinessError } from '@ohos.base'  
  
ethernet.isIfaceActive("eth0").then((data: number) => {  
  console.log("isIfaceActive promise = " + JSON.stringify(data));  
}).catch((error: BusinessError) => {  
  console.log("isIfaceActive promise error = " + JSON.stringify(error));  
});  
    
```    
  
    
## getAllActiveIfaces    
获取活动的网络接口，使用callback方式作为异步方法。  
 **调用形式：**     
    
- getAllActiveIfaces(callback: AsyncCallback\<Array\<string>>): void    
起始版本： 9    
- getAllActiveIfaces(): Promise\<Array\<string>>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Ethernet  
 **需要权限：** ohos.permission.GET_NETWORK_INFO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回值为对应接口名。 |  
| Promise<Array<string>> | 以Promise形式返回获取结果。返回值为对应接口名。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 2200002 | Operation failed. Cannot connect to service. |  
| 2200003 | System internal error. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
import ethernet from '@ohos.net.ethernet'  
import { BusinessError } from '@ohos.base'  
  
ethernet.getAllActiveIfaces((error: BusinessError, value: string[]) => {  
  if (error) {  
    console.log("getAllActiveIfaces callback error = " + JSON.stringify(error));  
  } else {  
    console.log("getAllActiveIfaces callback value.length = " + JSON.stringify(value.length));  
    for (let i = 0; i < value.length; i++) {  
      console.log("getAllActiveIfaces callback = " + JSON.stringify(value[i]));  
    }  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
import ethernet from '@ohos.net.ethernet'  
import { BusinessError } from '@ohos.base'  
  
ethernet.getAllActiveIfaces().then((data: string[]) => {  
  console.log("getAllActiveIfaces promise data.length = " + JSON.stringify(data.length));  
  for (let i = 0; i < data.length; i++) {  
    console.log("getAllActiveIfaces promise  = " + JSON.stringify(data[i]));  
  }  
}).catch((error:BusinessError) => {  
  console.log("getAllActiveIfaces promise error = " + JSON.stringify(error));  
});  
    
```    
  
    
## on('interfaceStateChange')<sup>(10+)</sup>    
注册网卡热插拔事件，使用callback方式作为异步方法。  
 **调用形式：**     
    
- on(type: 'interfaceStateChange', callback: Callback\<{ iface: string, active: boolean }>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Ethernet  
 **需要权限：** ohos.permission.GET_NETWORK_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 订阅的事件类型，'interfaceStateChange'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。<br>iface：网卡名称。<br>active：是否处于激活状态（true：激活；false：未激活） |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
import ethernet from '@ohos.net.ethernet'  
  
ethernet.on('interfaceStateChange', (data: object) => {  
  console.log('on interfaceSharingStateChange：' + JSON.stringify(data));  
});    
```    
  
    
## off('interfaceStateChange')<sup>(10+)</sup>    
注销网卡热插拔事件，使用callback方式作为异步方法。  
 **调用形式：**     
    
- off(type: 'interfaceStateChange', callback?: Callback\<{ iface: string, active: boolean }>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Ethernet  
 **需要权限：** ohos.permission.GET_NETWORK_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 订阅的事件类型，'interfaceStateChange'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。<br>iface：网卡名称。<br>active：是否处于激活状态（true：激活；false：未激活） |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
    
 **示例代码：**   
示例代码（promise）：  
```ts    
import ethernet from '@ohos.net.ethernet'  
  
ethernet.off('interfaceStateChange');    
```    
  
    
## InterfaceConfiguration    
以太网连接配置网络信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Ethernet    
### 属性    
 **系统能力:**  SystemCapability.Communication.NetManager.Ethernet    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| mode | IPSetMode | false | true | 以太网连接配置模式。 |  
| ipAddr | string | false | true | 以太网连接静态配置ip信息，地址值范围0-255.0-255.0-255.0-255（DHCP模式无需配置）。 |  
| route | string | false | true | 以太网连接静态配置路由信息，地址值范围0-255.0-255.0-255.0-255（DHCP模式无需配置）。 |  
| gateway | string | false | true | 以太网连接配置网关信息，地址值范围0-255.0-255.0-255.0-255（DHCP模式无需配置）。 |  
| netMask | string | false | true | 以太网连接配置子网掩码，地址值范围0-255.0-255.0-255.0-255（DHCP模式无需配置）。 |  
| dnsServers | string | false | true | 以太网连接配置dns服务地址，地址值范围0-255.0-255.0-255.0-255（DHCP模式无需配置）多地址间用“,”隔开。 |  
| httpProxy<sup>(10+)</sup> | HttpProxy | false | false | 以太网连接代理配置信息，默认情况下不配置任何代理信息。 |  
    
## IPSetMode    
以太网连接模式。    
    
 **系统能力:**  SystemCapability.Communication.NetManager.Ethernet    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| STATIC | 0 | 以太网连接静态配置网络信息。 |  
| DHCP | 1 | 以太网连接动态配置网络信息。 |  
