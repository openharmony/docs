# @ohos.net.vpn    
VPN 管理模块，支持 VPN 的启动和停止功能。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import vpn from '@ohos.net.vpn'    
```  
    
## createVpnConnection    
createVpnConnection(context: AbilityContext): VpnConnection  
  
创建一个 VPN 连接对象。  
 **调用形式：**     
- createVpnConnection(context: AbilityContext): VpnConnection  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Vpn    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| context | AbilityContext | true | 指定 context |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| VpnConnection | 返回一个 VPN 连接对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码：**   
Stage 模型示例：  
```ts    
import vpn from '@ohos.net.vpn';  
import common from '@ohos.app.ability.common';  
  
@Entry  
@Component  
struct Index {  
  private context = getContext(this) as common.UIAbilityContext;  
  private VpnConnection: vpn.VpnConnection = vpn.createVpnConnection(this.context);  
  functiontest()  
  {  
    console.info("vpn createVpnConnection: " + JSON.stringify(this.VpnConnection));  
  }  
  build() {  }  
}  
    
```    
  
    
## VpnConnection    
VPN 连接对象。在调用 VpnConnection 的方法前，需要先通过[vpn.createVpnConnection](#vpncreatevpnconnection)创建 VPN 连接对象。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Vpn    
### setUp    
使用 config 创建一个 vpn 网络  
 **调用形式：**     
    
- setUp(config: VpnConfig, callback: AsyncCallback\<number>): void    
起始版本： 10    
- setUp(config: VpnConfig): Promise\<number>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Vpn  
 **需要权限：** ohos.permission.MANAGE_VPN    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| config | VpnConfig | true | 指定 VPN 网络的配置信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当成功启动 VPN 网络时，返回虚拟网卡的文件描述符 fd, error 为 undefined，否则为错误对象。 |  
| Promise<number> | 以 Promise 形式返回获取结果，返回指定虚拟网卡的文件描述符 fd。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 2200001 | Invalid parameter value. |  
| 2200002 | Operation failed. Cannot connect to service. |  
| 2200003 | System internal error. |  
| 2203001 | VPN creation denied, please check the user type. |  
| 2203002 | VPN exist already, please execute destroy first. |  
    
 **示例代码1：**   
示例callback：  
  
  
```js    
import vpn from '@ohos.net.vpn';  
import common from '@ohos.app.ability.common';  
import { BusinessError } from "@ohos.base";  
  
@Entry  
@Component  
struct Index {  
  private context = getContext(this) as common.UIAbilityContext;  
  private VpnConnection: vpn.VpnConnection = vpn.createVpnConnection(this.context);  
  SetUp(): void {  
    let config: vpn.VpnConfig = {  
      addresses: [{  
        address: {  
          address: "10.0.0.5",  
          family: 1  
        },  
        prefixLength: 24  
      }],  
      mtu: 1400,  
      dnsAddresses: ["114.114.114.114"]  
    }  
    this.VpnConnection.setUp(config, (error: BusinessError, data: number) => {  
      console.info(JSON.stringify(error));  
      console.info("tunfd: " + JSON.stringify(data));  
    });  
  }  
  build() { }  
}  
    
```    
  
    
 **示例代码2：**   
示例Promise：  
  
```js    
import vpn from '@ohos.net.vpn';  
import common from '@ohos.app.ability.common';  
import { BusinessError } from "@ohos.base";  
  
@Entry  
@Component  
struct Index {  
  private context = getContext(this) as common.UIAbilityContext;  
  private VpnConnection: vpn.VpnConnection = vpn.createVpnConnection(this.context);  
  SetUp(): void {  
    let config: vpn.VpnConfig = {  
      addresses: [{  
        address: {  
          address: "10.0.0.5",  
          family: 1  
        },  
        prefixLength: 24  
      }],  
      mtu: 1400,  
      dnsAddresses: ["114.114.114.114"]  
    }  
    this.VpnConnection.setUp(config).then((data: number) => {  
      console.info("setUp success, tunfd: " + JSON.stringify(data));  
    }).catch((err: BusinessError) => {  
      console.info("setUp fail" + JSON.stringify(err));  
    });  
  }  
  build() { }  
}  
    
```    
  
    
### protect    
保护套接字不受 VPN 连接影响，通过该套接字发送的数据将直接基于物理网络收发，因此其流量不会通过 VPN 转发  
 **调用形式：**     
    
- protect(socketFd: number, callback: AsyncCallback\<void>): void    
起始版本： 10    
- protect(socketFd: number): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Vpn  
 **需要权限：** ohos.permission.MANAGE_VPN    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| socketFd | number | true | 指定保护的 socketfd, 该文件描述符通过[getSocketFd](js-apis-socket.md#getsocketfd10-1)获取。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，成功时，error 为 undefined，失败返回错误码错误信息。 |  
| Promise<void> | 以 Promise 形式返回设定结果，失败返回错误码错误信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 2200001 | Invalid parameter value. |  
| 2200002 | Operation failed. Cannot connect to service. |  
| 2200003 | System internal error. |  
| 2203004 | Invalid socket file descriptor. |  
    
 **示例代码1：**   
示例callback：  
  
  
```js    
import socket from "@ohos.net.socket";  
import vpn from '@ohos.net.vpn';  
import common from '@ohos.app.ability.common';  
import { BusinessError } from "@ohos.base";  
  
@Entry  
@Component  
struct Index {  
  private context = getContext(this) as common.UIAbilityContext;  
  private VpnConnection: vpn.VpnConnection = vpn.createVpnConnection(this.context);  
  
  Protect(): void {  
    let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();  
    let ipAddress: socket.NetAddress = {  
      address: "0.0.0.0"  
    }  
    tcp.bind(ipAddress);  
    let addressConnect: socket.TCPConnectOptions = {  
      address: {  
        address: "192.168.1.11",  
        port: 8888  
      },  
      timeout: 6000  
    }  
    tcp.connect(addressConnect);  
    tcp.getSocketFd().then((tunnelfd: number) => {  
      console.info("tunenlfd: " + tunnelfd);  
      this.VpnConnection.protect(tunnelfd, (error: BusinessError) => {  
        console.info(JSON.stringify(error));  
      });  
    });  
  }  
  build() { }  
}  
    
```    
  
    
 **示例代码2：**   
示例Promise：  
  
```js    
import socket from "@ohos.net.socket";  
import vpn from '@ohos.net.vpn';  
import common from '@ohos.app.ability.common';  
import { BusinessError } from "@ohos.base";  
  
@Entry  
@Component  
struct Index {  
  private context = getContext(this) as common.UIAbilityContext;  
  private VpnConnection: vpn.VpnConnection = vpn.createVpnConnection(this.context);  
  
  Protect(): void {  
    let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();  
    let ipAddress: socket.NetAddress = {  
      address: "0.0.0.0"  
    }  
    tcp.bind(ipAddress);  
    let addressConnect: socket.TCPConnectOptions = {  
      address: {  
        address: "192.168.1.11",  
        port: 8888  
      },  
      timeout: 6000  
    }  
    tcp.connect(addressConnect);  
    tcp.getSocketFd().then((tunnelfd: number) => {  
      console.info("tunenlfd: " + tunnelfd);  
      this.VpnConnection.protect(tunnelfd).then(() => {  
        console.info("protect success.");  
      }).catch((err: BusinessError) => {  
        console.info("protect fail" + JSON.stringify(err));  
      });  
    });  
  }  
  build() { }  
}  
    
```    
  
    
### destroy    
销毁启动的 VPN 网络  
 **调用形式：**     
    
- destroy(callback: AsyncCallback\<void>): void    
起始版本： 10    
- destroy(): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Vpn  
 **需要权限：** ohos.permission.MANAGE_VPN    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，成功时，error 为 undefined，失败返回错误码错误信息。 |  
| Promise<void> | 以 Promise 形式返回设定结果，失败返回错误码错误信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 2200002 | Operation failed. Cannot connect to service. |  
| 2200003 | System internal error. |  
    
 **示例代码1：**   
示例callback：  
  
  
```js    
import vpn from '@ohos.net.vpn';  
import common from '@ohos.app.ability.common';  
import { BusinessError } from "@ohos.base";  
  
@Entry  
@Component  
struct Index {  
  private context = getContext(this) as common.UIAbilityContext;  
  private VpnConnection: vpn.VpnConnection = vpn.createVpnConnection(this.context);  
  Destroy(): void {  
    this.VpnConnection.destroy((error: BusinessError) => {  
      console.info(JSON.stringify(error));  
    });  
  }  
  build() { }  
}  
    
```    
  
    
 **示例代码2：**   
示例Promise：  
  
```js    
import vpn from '@ohos.net.vpn';  
import common from '@ohos.app.ability.common';  
import { BusinessError } from "@ohos.base";  
  
@Entry  
@Component  
struct Index {  
  private context = getContext(this) as common.UIAbilityContext;  
  private VpnConnection: vpn.VpnConnection = vpn.createVpnConnection(this.context);  
  Destroy(): void {  
    this.VpnConnection.destroy().then(() => {  
      console.info("destroy success.");  
    }).catch((err: BusinessError) => {  
      console.info("destroy fail" + JSON.stringify(err));  
    });  
  }  
  build() { }  
}  
    
```    
  
    
## VpnConfig    
VPN 配置参数。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Vpn    
### 属性    
 **系统能力:**  SystemCapability.Communication.NetManager.Vpn    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| addresses | Array<LinkAddress> | false | true | VPN 虚拟网卡的 IP 地址。 |  
| routes | Array<RouteInfo> | false | false | VPN 虚拟网卡的路由信息。 |  
| dnsAddresses | Array<string> | false | false | DNS 服务器地址信息。 |  
| searchDomains | Array<string> | false | false | DNS 的搜索域列表。 |  
| mtu | number | false | false | 最大传输单元 MTU 值(单位:字节)。 |  
| isIPv4Accepted | boolean | false | false | 是否支持 IPV4, 默认值为 true。 |  
| isIPv6Accepted | boolean | false | false | 是否支持 IPV6, 默认值为 flase。 |  
| isLegacy | boolean | false | false | 是否支持内置 VPN, 默认值为 flase。 |  
| isBlocking | boolean | false | false | 是否阻塞模式, 默认值为 flase。 |  
| trustedApplications | Array<string> | false | false | 白名单信息, string 类型表示的包名。 |  
| blockedApplications | Array<string> | false | false | 黑名单信息, string 类型表示的包名。 |  
