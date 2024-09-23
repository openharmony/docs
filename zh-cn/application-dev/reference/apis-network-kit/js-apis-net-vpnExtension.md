# @ohos.net.vpnExtension (VPN 增强管理)

三方VPN管理模块，支持三方VPN的启动和停止功能。
三方VPN是指由第三方提供的VPN服务，它们通常提供更多的功能和更广泛的网络连接选项，包括更多的安全和隐私功能，以及更全面的定制选项。

> **说明：**
> 本模块首批接口从 API version 11 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import { vpnExtension } from '@kit.NetworkKit';
```

## vpnExtension.startVpnExtensionAbility

startVpnExtensionAbility(want: Want): Promise\<void>

启动新的三方vpn功能。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型                                | 必填 | 说明               |
| ------ | ----------------------------------- | ---- | ------------------ |
| want   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 指示要启动的信息。 |

**返回值：**

| 类型           | 说明                    |
| -------------- | ----------------------- |
| Promise\<void> | 无返回值的Promise对象。 |

**错误码：**

| 错误码 ID | 错误信息                               |
| --------- | -------------------------------------- |
| 401       | If the input parameter is not valid parameter.|
| 16000001  | The specified ability does not exist.  |
| 16000002  | Incorrect ability type.                |
| 16000006  | Cross-user operations are not allowed. |
| 16000008  | The crowdtesting application expires.  |
| 16000011  | The context does not exist.            |
| 16000050  | Internal error.                        |
| 16200001  | The caller has been released.          |

**示例：**
Stage 模型示例：

```ts
import { common, Want } from '@kit.AbilityKit';
import { vpnExtension } from '@kit.NetworkKit';

let context = getContext(this) as common.VpnExtensionContext;
let want: Want = {
  deviceId: "",
  bundleName: "com.example.myvpndemo",
  abilityName: "MyVpnExtAbility",
};

@Entry
@Component
struct Index {
  @State message: string = 'Hello World'

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

## vpnExtension.stopVpnExtensionAbility

stopVpnExtensionAbility(want: Want): Promise\<void>

停止同一应用程序中的服务。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型                                | 必填 | 说明             |
| ------ | ----------------------------------- | ---- | ---------------- |
| want   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 指示要启动的信息 |

**返回值：**

| 类型           | 说明                    |
| -------------- | ----------------------- |
| Promise\<void> | 无返回值的Promise对象。 |

**错误码：**

| 错误码 ID | 错误信息                               |
| --------- | -------------------------------------- |
| 401       | If the input parameter is not valid parameter.|
| 16000001  | The specified ability does not exist.  |
| 16000002  | Incorrect ability type.                |
| 16000006  | Cross-user operations are not allowed. |
| 16000011  | The context does not exist.            |
| 16000050  | Internal error.                        |
| 16200001  | The caller has been released.          |

**示例：**
Stage 模型示例：

```ts
import { common, Want } from '@kit.AbilityKit';
import { vpnExtension } from '@kit.NetworkKit';

let context = getContext(this) as common.VpnExtensionContext;
let want: Want = {
  deviceId: "",
  bundleName: "com.example.myvpndemo",
  abilityName: "MyVpnExtAbility",
};

@Entry
@Component
struct Index {
  @State message: string = 'Hello World'

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


## vpnExtension.createVpnConnection

createVpnConnection(context: VpnExtensionContext): VpnConnection

创建一个 三方VPN 连接对象。

> **说明：**
>
> 调用createVpnConnection接口前，需要先调用startVpnExtensionAbility接口启用vpn功能。

**系统能力**：SystemCapability.Communication.NetManager.Vpn

**模型约束**：此接口仅可在Stage模型下使用。

**参数：**

| 参数名  | 类型                                                         | 必填 | 说明           |
| ------- | ------------------------------------------------------------ | ---- | -------------- |
| context | [VpnExtensionContext](js-apis-inner-application-VpnExtensionContext.md) | 是   | 指定 context。 |

**返回值：**

| 类型                            | 说明                    |
| :------------------------------ | :---------------------- |
| [VpnConnection](#vpnconnection) | 返回一个 VPN 连接对象。 |

**错误码：**

| 错误码 ID | 错误信息         |
| --------- | ---------------- |
| 401       | Parameter error. |

**示例：**
Stage 模型示例：

```ts
import { vpnExtension, VpnExtensionAbility } from '@kit.NetworkKit';
import { common, Want } from '@kit.AbilityKit';

let context: vpnExtension.VpnExtensionContext;
export default class MyVpnExtAbility extends VpnExtensionAbility {
  onCreate(want: Want) {
    let VpnConnection : vpnExtension.VpnConnection = vpnExtension.createVpnConnection(context);
    console.info("vpn createVpnConnection: " + JSON.stringify(VpnConnection));
  }
}
```

## VpnConnection

VPN 连接对象。在调用 VpnConnection 的方法前，需要先通过vpnExt.createVpnConnection创建 VPN 连接对象。

### create

create(config: VpnConfig): Promise\<number\>

使用 config 创建一个 vpn 网络，使用 Promise 方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Vpn

**参数：**

| 参数名 | 类型                    | 必填 | 说明                      |
| ------ | ----------------------- | ---- | ------------------------- |
| config | [VpnConfig](#vpnconfig) | 是   | 指定 VPN 网络的配置信息。 |

**返回值：**

| 类型              | 说明                                                           |
| ----------------- | -------------------------------------------------------------- |
| Promise\<number\> | 以 Promise 形式返回获取结果，返回指定虚拟网卡的文件描述符 fd。 |

**错误码：**

| 错误码 ID | 错误信息                                         |
| --------- | ------------------------------------------------ |
| 401       | Parameter error.                                 |
| 2200001   | Invalid parameter value.                         |
| 2200002   | Operation failed. Cannot connect to service.     |
| 2200003   | System internal error.                           |
| 2203001   | VPN creation denied, please check the user type. |
| 2203002   | VPN exist already, please execute destroy first. |

**示例：**

```js
import { vpnExtension, VpnExtensionAbility } from '@kit.NetworkKit';
import { common, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let context: vpnExtension.VpnExtensionContext;
export default class MyVpnExtAbility extends VpnExtensionAbility {
  private tunIp: string = '10.0.0.5';
  private blockedAppName: string = 'com.example.myvpndemo';
  onCreate(want: Want) {
    let VpnConnection : vpnExtension.VpnConnection = vpnExtension.createVpnConnection(context);
    console.info("vpn createVpnConnection: " + JSON.stringify(VpnConnection));
    this.SetupVpn();
  }
  SetupVpn() {
        class Address {
            address: string;
            family: number;

            constructor(address: string, family: number) {
                this.address = address;
                this.family = family;
            }
        }

        class AddressWithPrefix {
            address: Address;
            prefixLength: number;

            constructor(address: Address, prefixLength: number) {
                this.address = address;
                this.prefixLength = prefixLength;
            }
        }

        class Config {
            addresses: AddressWithPrefix[];
            mtu: number;
            dnsAddresses: string[];
            trustedApplications: string[];
            blockedApplications: string[];

            constructor(
                tunIp: string,
                blockedAppName: string
            ) {
                this.addresses = [
                    new AddressWithPrefix(new Address(tunIp, 1), 24)
                ];
                this.mtu = 1400;
                this.dnsAddresses = ["114.114.114.114"];
                this.trustedApplications = [];
                this.blockedApplications = [blockedAppName];
            }
        }

        let config = new Config(this.tunIp, this.blockedAppName);

        try {
            let VpnConnection : vpnExtension.VpnConnection = vpnExtension.createVpnConnection(context);
            VpnConnection.create(config).then((data) => {
                hilog.error(0x0000, 'developTag', 'tunfd: %{public}s', JSON.stringify(data) ?? '');
            })
        } catch (error) {
            hilog.error(0x0000, 'developTag', 'vpn setUp fail: %{public}s', JSON.stringify(error) ?? '');
        }
    }
}
```

### protect

protect(socketFd: number): Promise\<void\>

保护套接字不受 VPN 连接影响，通过该套接字发送的数据将直接基于物理网络收发，因此其流量不会通过 VPN 转发, 使用 Promise 方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Vpn

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------------------------------------- |
| socketFd | number | 是   | 指定保护的 socketfd, 该文件描述符通过[getSocketFd](js-apis-socket.md#getsocketfd10-1)获取。 |

**返回值：**

| 类型            | 说明                                                  |
| --------------- | ----------------------------------------------------- |
| Promise\<void\> | 以 Promise 形式返回设定结果，失败返回错误码错误信息。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2200001   | Invalid parameter value.                     |
| 2200002   | Operation failed. Cannot connect to service. |
| 2200003   | System internal error.                       |
| 2203004   | Invalid socket file descriptor.              |

**示例：**

```js
import { vpnExtension, VpnExtensionAbility } from '@kit.NetworkKit';
import { common, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let g_tunnelFd = -1;
let context: vpnExtension.VpnExtensionContext;
export default class MyVpnExtAbility extends VpnExtensionAbility {
  private vpnServerIp: string = '192.168.31.13';
  onCreate(want: Want) {
    let VpnConnection : vpnExtension.VpnConnection = vpnExtension.createVpnConnection(context);
    console.info("vpn createVpnConnection: " + JSON.stringify(VpnConnection));
    this.CreateTunnel();
    this.Protect();
  }
  CreateTunnel() {
      g_tunnelFd = 8888;
  }
  Protect() {
        hilog.info(0x0000, 'developTag', '%{public}s', 'vpn Protect');
        let VpnConnection : vpnExtension.VpnConnection = vpnExtension.createVpnConnection(context);
        VpnConnection.protect(g_tunnelFd).then(() => {
            hilog.info(0x0000, 'developTag', '%{public}s', 'vpn Protect Success');
        }).catch((err : Error) => {
            hilog.error(0x0000, 'developTag', 'vpn Protect Failed %{public}s', JSON.stringify(err) ?? '');
        })
  }
}
```

### destroy

destroy(): Promise\<void\>

销毁启动的 VPN 网络，使用 Promise 方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Vpn

**返回值：**

| 类型            | 说明                                                  |
| --------------- | ----------------------------------------------------- |
| Promise\<void\> | 以 Promise 形式返回设定结果，失败返回错误码错误信息。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2200002   | Operation failed. Cannot connect to service. |
| 2200003   | System internal error.                       |

**示例：**

```js
import { vpnExtension, VpnExtensionAbility } from '@kit.NetworkKit';
import { common, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let context: vpnExtension.VpnExtensionContext;
export default class MyVpnExtAbility extends VpnExtensionAbility {
  onCreate(want: Want) {
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

## VpnConfig

三方VPN配置参数。

**系统能力**：SystemCapability.Communication.NetManager.Vpn

| 名称                | 类型                                                           | 必填 | 说明                                |
| ------------------- | -------------------------------------------------------------- | ---- | ----------------------------------- |
| addresses           | Array\<[LinkAddress](js-apis-net-connection.md#linkaddress)\> | 是   | VPN 虚拟网卡的 IP 地址。            |
| routes              | Array\<[RouteInfo](js-apis-net-connection.md#routeinfo)\>     | 否   | VPN 虚拟网卡的路由信息。            |
| dnsAddresses        | Array\<string\>                                                | 否   | DNS 服务器地址信息。                |
| searchDomains       | Array\<string\>                                                | 否   | DNS 的搜索域列表。                  |
| mtu                 | number                                                         | 否   | 最大传输单元 MTU 值(单位:字节)。     |
| isIPv4Accepted      | boolean                                                        | 否   | 是否支持 IPV4, 默认值为 true。      |
| isIPv6Accepted      | boolean                                                        | 否   | 是否支持 IPV6, 默认值为 false。     |
| isInternal          | boolean                                                        | 否   | 是否支持内置 VPN, 默认值为 false。   |
| isBlocking          | boolean                                                        | 否   | 是否阻塞模式, 默认值为 false。       |
| trustedApplications | Array\<string\>                                                | 否   | 白名单信息, string 类型表示的包名。  |
| blockedApplications | Array\<string\>                                                | 否   | 黑名单信息, string 类型表示的包名。  |

**示例：**

```js
import { vpnExtension} from '@kit.NetworkKit';

let vpnConfig: vpnExtension.VpnConfig = {
  addresses: [],
  routes: [{
    interface: "eth0",
    destination: {
      address: {
        address:'',
        family:1,
        port:8080
      },
      prefixLength:1
    },
    gateway: {
      address:'',
      family:1,
      port:8080
    },
    hasGateway: true,
    isDefaultRoute: true,
  }],
  mtu: 1400,
  dnsAddresses: ["223.5.5.5", "223.6.6.6"],
  trustedApplications: [],
  blockedApplications: [],
}
let context: vpnExtension.VpnExtensionContext;

function vpnCreate(){
  let VpnConnection: vpnExtension.VpnConnection = vpnExtension.createVpnConnection(context);
  VpnConnection.create(vpnConfig).then((data) => {
    console.info("vpn create " + JSON.stringify(data));
  })
}
```