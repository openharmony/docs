# VPN应用开发指南

## 简介

VPN，即虚拟专用网络（Virtual Private Network），是在公用网络上建立专用网络的一种技术。在VPN网络中，任意两个节点间的连接并非依赖传统专用网络所需要的端到端的物理链路，而是构建在公用网络服务商提供的平台（如Internet）之上的逻辑网络。用户数据在这一逻辑链路中进行传输。

OpenHarmony为开发者提供了用于创建VPN的API解决方案。当前提供三方VPN能力主要用于创建虚拟网卡及配置VPN路由信息，连接隧道过程及内部连接的协议需要应用内部自行实现。本文将指导您如何开发自己的VPN客户端。

> **说明：**
>
> 为了保证应用的运行效率，所有API调用都是异步的，对于异步调用的API均提供了Promise的方式，以下示例均采用Promise方式，更多方式可以查阅[API参考](../reference/apis-network-kit/js-apis-net-vpnExtension.md)。

## VPN应用的显示体验

借助系统提供的VPN Extension接口开发者可以构建支持不同协议的VPN服务。OpenHarmony系统提供了界面 (UI) 使用户可以了解当前VPN应用服务的启动和连接：

- 在VPN应用首次启动连接之前，系统会显示VPN连接授权对话框。该对话框会提示用户是否信任该VPN应用并接受VPN连接请求。
- 当VPN启动连接成功时，状态栏显示一个VPN (钥匙) 图标以提醒用户VPN处于连接状态。

为了使用户可以方便的查看和配置，您的VPN应用还需要提供以下界面：

- 用于手动启动和停止连接的控件。
- 当VPN启动连接时，在通知栏显示VPN应用的连接状态或提供网络统计信息 (如连接时长、流量等) 。点击该通知能够将您的VPN应用调入前台。

## 接口说明

完整的JS API说明以及示例代码请参考：[VPN扩展应用API](../reference/apis-network-kit/js-apis-net-vpnExtension.md)。

## 创建VPN Extension Ability

如果想使您的应用支持VPN能力，首先您需要创建一个继承于VpnExtensionAbility的extensionAbilities。

```ts
// 举例：在应用的module.json5中定义MyVpnExtAbility
"extensionAbilities": [
  {
    "name": "MyVpnExtAbility",
    "description": "vpnservice",
    "type": "vpn",
    "srcEntry": "./ets/serviceextability/MyVpnExtAbility.ts"
  }
]
```

> **注意：**
>
> 如果DevEco Studio工具提示不能识别"type": "vpn"，需要您手动在SDK的toolchains\modulecheck\module.json文件中，给extensionAbilities对应的type枚举添加"vpn"定义，并清除build缓存。

接下来您需要在创建的VpnExtensionAbility中实现VPN的配置、启动和停止操作：

- 建立一个VPN的网络隧道，以UDP隧道为例（参考本文下方VPN Demo示例工程文件[napi_init](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_NetManager/VPNControl_Case/entry/src/main/cpp/napi_init.cpp)的UdpConnect()方法）；
- 通过VpnConnection.[protect](../reference/apis-network-kit/js-apis-net-vpnExtension.md#protect)保护前一步建立的UDP隧道；
- 构建VPN Config参数，参考[VPN Config参数说明](#vpn-config参数说明)；
- 通过VpnConnection.[create](../reference/apis-network-kit/js-apis-net-vpnExtension.md#create)建立VPN网络连接；
- 处理虚拟网卡的数据，如：读写操作。


## 启动VPN Extension Ability

当VPN应用启动VPN连接时，需要调用startVpnExtensionAbility接口，携带需要启动的VpnExtensionAbility信息，其中bundleName需要与您的VPN应用bundleName一致，abilityName为您在前面创建的VpnExtensionAbility名。您可参考如下示例：

```ts
import { common, Want } from '@kit.AbilityKit';
import { vpnExtension } from '@kit.NetworkKit';

let want: Want = {
  deviceId: "",
  bundleName: "com.example.myvpndemo",
  abilityName: "MyVpnExtAbility",
};

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold).onClick(() => {
          console.info("btn click") })
        Button('Start Extension').onClick(() => {
          vpnExtension.startVpnExtensionAbility(want);
        }).width('70%').fontSize(45).margin(16)
        }.width('100%')
    }.height('100%')
  }
}
```

如果您的VPN应用未获取用户信任，系统将弹出VPN连接的授权对话框，当获取用户授权后，系统将自动调用并启动您实现的VPN Extension Ability的[onCreate](../reference/apis-network-kit/js-apis-VpnExtensionAbility.md#vpnextensionabilityoncreate)方法将被调用。

目前系统仅支持启动一个VPN连接服务，当VPN已经启动时应用新调用启动接口会收到系统拒绝错误，此时建议您的应用可以提醒用户先断开当前已经激活的VPN应用连接。



## 停止VPN Extension Ability

当VPN应用需要停止VPN连接时，需要调用stopVpnExtensionAbility接口，携带需要停止的VpnExtensionAbility信息。系统会对调用方做权限校验，stopVpnExtensionAbility的调用方应用必须获取了用户的VPN信任授权，且只允许停止应用自己启动的VpnExtensionAbility，所以接口传入的参数中bundleName需要与您的VPN应用bundleName一致，abilityName为指定停止VPN的VpnExtensionAbility名。

您可参考如下示例：

```ts
import { common, Want } from '@kit.AbilityKit';
import { vpnExtension } from '@kit.NetworkKit';

let want: Want = {
  deviceId: "",
  bundleName: "com.example.myvpndemo",
  abilityName: "MyVpnExtAbility",
};

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold).onClick(() => {
          console.info("btn click") })
        Button('Start Extension').onClick(() => {
          vpnExtension.startVpnExtensionAbility(want);
        }).width('70%').fontSize(45).margin(16)
        Button('Stop Extension').onClick(() => {
          console.info("btn end")
          vpnExtension.stopVpnExtensionAbility(want);
        }).width('70%').fontSize(45).margin(16)

        }.width('100%')
    }.height('100%')
  }
}
```

stopVpnExtensionAbility后，您的VPN Extension Ability的[onDestroy](../reference/apis-network-kit/js-apis-VpnExtensionAbility.md#vpnextensionabilityondestroy)方法将被调用，您可在此时destroy vpn连接。

```ts
import { vpnExtension, VpnExtensionAbility } from '@kit.NetworkKit';
import { common, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let context: vpnExtension.VpnExtensionContext;
export default class MyVpnExtAbility extends VpnExtensionAbility {
  onDestroy() {
    let VpnConnection : vpnExtension.VpnConnection = vpnExtension.createVpnConnection(context);
    console.info("vpn createVpnConnection: " + JSON.stringify(VpnConnection));
    VpnConnection.destroy().then(() => {
      console.info("destroy success.");
    }).catch((error : BusinessError) => {
      console.error("destroy fail" + JSON.stringify(error));
    });
  }
}
```

## 服务生命周期

为了保障设备的网络连接，当系统观察到VPN相关应用出现异常时会主动停止VPN连接：

- 当调用startVpnExtensionAbility接口的应用进程退出时。
- 当VPN服务进程销毁时。

## VPN Config参数说明

| 名称                | 类型                                                         | 必填 | 说明                                                         |
| ------------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| addresses           | Array\<[LinkAddress](../reference/apis-network-kit/js-apis-net-connection.md#linkaddress)\> | 是   | VPN虚拟网卡的IP地址。                                        |
| routes              | Array\<[RouteInfo](../reference/apis-network-kit/js-apis-net-connection.md#routeinfo)\> | 否   | VPN虚拟网卡的路由信息(目前最多可配置1024条路由)。            |
| dnsAddresses        | Array\<string\>                                              | 否   | DNS服务器地址信息。配置后VPN白名单的应用访问网络时使用这些DNS服务器，不配置则使用系统分配的DNS服务器地址。 |
| searchDomains       | Array\<string\>                                              | 否   | DNS的搜索域列表。                                            |
| mtu                 | number                                                       | 否   | 最大传输单元MTU值(单位：字节)。                               |
| isIPv4Accepted      | boolean                                                      | 否   | 是否支持IPV4，默认值为true。true：支持IPV4；false：不支持IPV4。                                 |
| isIPv6Accepted      | boolean                                                      | 否   | 是否支持IPV6，默认值为false。true：支持IPV6；false：不支持IPV6。                                |
| isInternal          | boolean                                                      | 否   | 是否支持内置VPN，默认值为false。true：支持内置VPN；false：不支持内置VPN。                             |
| isBlocking          | boolean                                                      | 否   | 是否阻塞模式，默认值为false。true：是阻塞模式；false：不是阻塞模式。                                |
| trustedApplications | Array\<string\>                                              | 否   | VPN生效的应用白名单信息，string类型表示的包名。              |
| blockedApplications | Array\<string\>                                              | 否   | 不生效VPN的应用黑名单信息，string类型表示的包名。            |

**示例：**

```ts
import { vpnExtension} from '@kit.NetworkKit';

let vpnConfig: vpnExtension.VpnConfig = {
  // 配置VPN虚拟网卡的IP地址
  addresses: [{
    address: {
      address:'192.x.x.5',
      family:1
    },
    prefixLength:24
  }],
  // 配置路由参数
  routes: [{
    // VPN虚拟网卡接口名固定为“vpn-tun”
    interface: 'vpn-tun',
    destination: {
      address: {
        address:'10.x.x.8',
        family:1,
        port:8080
      },
      prefixLength:24
    },
    gateway: {
      address:'10.x.x.5',
      family:1,
      port:8080
    },
    hasGateway: false,
    isDefaultRoute: false,
  }],
  // 配置最大传输单元值
  mtu: 1400,
  // 配置VPN使用的DNS服务器，
  dnsAddresses: ['223.x.x.5', '223.x.x.6'],
  // VPN生效白名单的应用
  trustedApplications: ['com.test.browser'],
  // 不生效VPN黑名单的应用
  blockedApplications: ['com.test.games'],
}
let context: vpnExtension.VpnExtensionContext;

function vpnCreate(){
  let VpnConnection: vpnExtension.VpnConnection = vpnExtension.createVpnConnection(context);
  VpnConnection.create(vpnConfig).then((data) => {
    console.info("vpn create " + JSON.stringify(data));
  })
}
```



## VPN Demo示例

OpenHarmony开源项目包含一个名为[VPN](https://gitee.com/openharmony/applications_app_samples/tree/master/code/DocsSample/NetWork_Kit/NetWorkKit_NetManager/VPNControl_Case)的示例应用。此应用展示了如何设置和连接 VPN 服务。



