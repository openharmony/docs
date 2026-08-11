# @ohos.net.vpnExtension (VPN增强管理)

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->

三方VPN管理模块，支持三方VPN的启动和停止功能。三方VPN是指由第三方提供的VPN服务，它们通常提供更多的功能和更广泛的网络连接选项，包括更多的安全和隐私功能，以及更全面的定制选项。当前提供三方VPN能力主要用于创建虚拟网卡及配置VPN路由信息，连接隧道过程及内部连接的协议需要应用内部自行实现。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 约束限制

为保障系统安全性和稳定性，防止VpnExtensionAbility滥用系统资源，系统对其能力进行管控，不支持部分模块的引用，详情请参考[附录](#附录)。

## 导入模块

```js
import { vpnExtension } from '@kit.NetworkKit';
```

## LinkAddress
type LinkAddress = connection.LinkAddress

获取网络链接信息。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| [connection.LinkAddress](./js-apis-net-connection.md#linkaddress) | 网络链路信息。 |

## RouteInfo
type RouteInfo = connection.RouteInfo

获取网络路由信息。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| [connection.RouteInfo](./js-apis-net-connection.md#routeinfo) | 网络路由信息。 |

## VpnExtensionContext
type VpnExtensionContext = _VpnExtensionContext

VPN扩展的上下文。它允许访问serviceExtension特定资源。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| [_VpnExtensionContext](./js-apis-inner-application-VpnExtensionContext.md) | VPN扩展的上下文。 |

## vpnExtension.startVpnExtensionAbility

startVpnExtensionAbility(want: Want): Promise\<void>

启动新的三方VPN功能。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型                                | 必填 | 说明               |
| ------ | ----------------------------------- | ---- | ------------------ |
| want   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 指示要启动的信息。<br> **说明：** 从API version 22开始，支持在VPN首次启动时传递want中的parameters字段。 |

**返回值：**

| 类型           | 说明                    |
| -------------- | ----------------------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                               |
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
import { Want } from '@kit.AbilityKit';
import { vpnExtension } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
          .fontSize(40)
          .fontWeight(FontWeight.Bold).onClick(() => {
          console.info("btn click")
        })
        Button('Start Extension').onClick(() => {
          vpnExtension.startVpnExtensionAbility(want).then(() => {
            console.info('startVpnExtensionAbility success');
          }).catch((err: BusinessError) => {
            console.error('startVpnExtensionAbility error: ' + JSON.stringify(err));
          })
        }).width('70%').fontSize(30).margin(16)
      }.width('100%')
    }.height('100%')
  }
}
```

## vpnExtension.stopVpnExtensionAbility

stopVpnExtensionAbility(want: Want): Promise\<void>

停止同一应用程序中的服务。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型                                | 必填 | 说明             |
| ------ | ----------------------------------- | ---- | ---------------- |
| want   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 指示要启动的信息。 |

**返回值：**

| 类型           | 说明                    |
| -------------- | ----------------------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)和[通用错误码](../errorcode-universal.md)。

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
import { Want } from '@kit.AbilityKit';
import { vpnExtension } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
          console.info("btn click")
        })
        Button('Start Extension').onClick(() => {
          vpnExtension.startVpnExtensionAbility(want).then(() => {
            console.info('startVpnExtensionAbility success');
          }).catch((err: BusinessError) => {
            console.error('startVpnExtensionAbility error: ' + JSON.stringify(err));
          })
        }).width('70%').fontSize(30).margin(16)
        Button('Stop Extension').onClick(() => {
          console.info("btn end")
          vpnExtension.stopVpnExtensionAbility(want).then(() => {
            console.info('stopVpnExtensionAbility success');
          }).catch((err: BusinessError) => {
            console.error('stopVpnExtensionAbility error: ' + JSON.stringify(err));
          })
        }).width('70%').fontSize(30).margin(16)

      }.width('100%')
    }.height('100%')
  }
}
```

## vpnExtension.createVpnObserver

createVpnObserver(): VpnObserver

创建一个VPN观察者对象。用于监听VPN相关事件。

**起始版本：** 26.0.0

**系统能力**：SystemCapability.Communication.NetManager.Vpn

**模型约束**：此接口仅可在Stage模型下使用。

**返回值：**

| 类型                            | 说明                    |
| :------------------------------ | :---------------------- |
| [VpnObserver](#vpnobserver) | 返回一个VPN观察者对象。 |

**示例：**

```ts
import { vpnExtension } from '@kit.NetworkKit';

let vpnObserver: vpnExtension.VpnObserver = vpnExtension.createVpnObserver();
```

## VpnObserver

VPN观察者对象。用于监听VPN相关事件。在调用VpnObserver的方法前，需要先通过[vpnExtension.createVpnObserver](#vpnextensioncreatevpnobserver)创建VPN连接对象。

### onAuthorizationResult

onAuthorizationResult(callback: Callback\<boolean\>): void

注册用户授权结果监听器。授权结果在调用[startVpnExtensionAbility](#vpnextensionstartvpnextensionability)弹出授权弹窗，用户点击弹窗后通知，仅接收当前VPN的结果。在不需要监听授权结果时可以调用[offAuthorizationResult](#offauthorizationresult)接口取消注册。

>**注意**
>
>多次调用该接口时，仅最后一次传入的callback生效。

**起始版本：** 26.0.0

**系统能力**：SystemCapability.Communication.NetManager.Vpn

**模型约束**：此接口仅可在Stage模型下使用。

**参数：**

| 参数名    | 类型                | 必填 | 说明                                                         |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| callback  | Callback\<boolean\> |是   | 回调函数，用于返回用户授权结果。true表示用户同意授权，false表示用户拒绝授权。 |

**示例：**

```ts
import { vpnExtension } from '@kit.NetworkKit';

let vpnObserver: vpnExtension.VpnObserver = vpnExtension.createVpnObserver();
vpnObserver.onAuthorizationResult((result: boolean) => {
  if (result) {
    console.info('VPN authorization succeeded');
  } else {
    console.error('VPN authorization failed');
  }
});
```

### offAuthorizationResult

offAuthorizationResult(callback?: Callback\<boolean\>): void

取消注册用户授权结果监听器。

>**注意**
>
>多次调用[onAuthorizationResult](#onauthorizationresult)注册监听时，若需取消授权结果监听，需要传最后一次调用时传入的callback，或者不传入参数。

**起始版本：** 26.0.0

**系统能力**：SystemCapability.Communication.NetManager.Vpn

**模型约束**：此接口仅可在Stage模型下使用。

**参数：**

| 参数名    | 类型                | 必填 | 说明                                                         |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| callback  | Callback\<boolean\> | 否   | 监听器回调函数，用于返回用户授权结果。<br>传入该参数：取消注册指定的监听器。不传参数：取消注册所有已注册的监听器。 |

**示例：**

```ts
import { vpnExtension } from '@kit.NetworkKit';

let vpnObserver: vpnExtension.VpnObserver = vpnExtension.createVpnObserver();

let callback = (result: boolean) => {
  console.info('Authorization result: ' + result);
};
// 注册监听器
vpnObserver.onAuthorizationResult(callback);

// 取消注册指定监听器
vpnObserver.offAuthorizationResult(callback);

// 取消注册已注册的监听器
vpnObserver.offAuthorizationResult();
```

## vpnExtension.createVpnConnection

createVpnConnection(context: VpnExtensionContext): VpnConnection

创建一个三方VPN连接对象。

> **说明：**
>
> 调用createVpnConnection接口前，需要先调用startVpnExtensionAbility接口启用VPN功能。

**系统能力**：SystemCapability.Communication.NetManager.Vpn

**模型约束**：此接口仅可在Stage模型下使用。

**参数：**

| 参数名  | 类型                                                         | 必填 | 说明           |
| ------- | ------------------------------------------------------------ | ---- | -------------- |
| context | [VpnExtensionContext](js-apis-inner-application-VpnExtensionContext.md) | 是   | 指定 context。 |

**返回值：**

| 类型                            | 说明                    |
| :------------------------------ | :---------------------- |
| [VpnConnection](#vpnconnection) | 返回一个VPN连接对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息         |
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
    let vpnConnection : vpnExtension.VpnConnection = vpnExtension.createVpnConnection(context);
    console.info("VPN createVpnConnection: " + JSON.stringify(vpnConnection));
  }
}
```

## VpnConnection

VPN连接对象。在调用VpnConnection的方法前，需要先通过vpnExt.createVpnConnection创建VPN连接对象。

### create

create(config: VpnConfig): Promise\<number\>

使用config创建一个VPN网络。使用Promise异步回调。

> **说明：**
>
> 建议在不需要VPN网络的时候配对调用[destroy()](#destroy)或[destroy(vpnId: string)](#destroy20)接口销毁启动的VPN网络，并执行资源清理等操作。

**系统能力**：SystemCapability.Communication.NetManager.Vpn

**参数：**

| 参数名 | 类型                    | 必填 | 说明                      |
| ------ | ----------------------- | ---- | ------------------------- |
| config | [VpnConfig](#vpnconfig) | 是   | 指定VPN网络的配置信息。 |

**返回值：**

| 类型              | 说明                                                           |
| ----------------- | -------------------------------------------------------------- |
| Promise\<number\> | 以 Promise 形式返回获取结果，返回指定虚拟网卡的文件描述符 fd。 |

**错误码：**

以下错误码的详细介绍请参见[VPN错误码](errorcode-net-vpn.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                         |
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
    let vpnConnection : vpnExtension.VpnConnection = vpnExtension.createVpnConnection(context);
    console.info("vpn createVpnConnection: " + JSON.stringify(vpnConnection));
    this.SetupVpn();
    
    // 不需要VPN网络时，调用destroy()接口销毁启动的VPN网络，并执行资源清理等操作。
    vpnConnection.destroy().then(() => {
      console.info("destroy success.");
    }).catch((error : BusinessError) => {
      console.error(`destroy fail. Code:${error.code}, message:${error.message}`);
    });
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
            let vpnConnection : vpnExtension.VpnConnection = vpnExtension.createVpnConnection(context);
            vpnConnection.create(config).then((data) => {
                hilog.error(0x0000, 'developTag', 'tunfd: %{public}s', JSON.stringify(data) ?? '');
            })
        } catch (error) {
            hilog.error(0x0000, 'developTag', 'VPN setUp fail: %{public}s', JSON.stringify(error) ?? '');
        }
    }
}
```

### protect

protect(socketFd: number): Promise\<void\>

保护套接字不受VPN连接影响，通过该套接字发送的数据将直接基于物理网络收发，因此其流量不会通过VPN转发。使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Vpn

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------------------------------------- |
| socketFd | number | 是   | 指定保护的 socketfd，该文件描述符通过[getSocketFd](js-apis-socket.md#getsocketfd10-1)获取。 |

**返回值：**

| 类型            | 说明                                                  |
| --------------- | ----------------------------------------------------- |
| Promise\<void\> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[VPN错误码](errorcode-net-vpn.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
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
    let vpnConnection : vpnExtension.VpnConnection = vpnExtension.createVpnConnection(context);
    console.info("VPN createVpnConnection: " + JSON.stringify(vpnConnection));
    this.CreateTunnel();
    this.Protect();
  }
  CreateTunnel() {
      g_tunnelFd = 8888;
  }
  Protect() {
        hilog.info(0x0000, 'developTag', '%{public}s', 'VPN Protect');
        let vpnConnection : vpnExtension.VpnConnection = vpnExtension.createVpnConnection(context);
        vpnConnection.protect(g_tunnelFd).then(() => {
            hilog.info(0x0000, 'developTag', '%{public}s', 'VPN Protect Success');
        }).catch((err : Error) => {
            hilog.error(0x0000, 'developTag', 'VPN Protect Failed %{public}s', JSON.stringify(err) ?? '');
        })
  }
}
```

### destroy

destroy(): Promise\<void\>

销毁启动的VPN网络。使用Promise异步回调。

**系统能力**：SystemCapability.Communication.NetManager.Vpn

**返回值：**

| 类型            | 说明                                                  |
| --------------- | ----------------------------------------------------- |
| Promise\<void\> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[VPN错误码](errorcode-net-vpn.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
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
    let vpnConnection : vpnExtension.VpnConnection = vpnExtension.createVpnConnection(context);
    console.info("VPN createVpnConnection: " + JSON.stringify(vpnConnection));
    vpnConnection.destroy().then(() => {
      console.info("destroy success.");
    }).catch((error : BusinessError) => {
      console.error("destroy fail" + JSON.stringify(error));
    });
  }
}
```

### destroy<sup>20+</sup>

destroy(vpnId: string): Promise\<void\>
  
根据vpnId销毁指定的VPN网络。使用Promise异步回调。
  
**系统能力**：SystemCapability.Communication.NetManager.Vpn

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------------------------------------- |
| vpnId | string |  是  | vpn唯一标识。 |

**返回值：**

| 类型            | 说明                                                  |
| --------------- | ----------------------------------------------------- |
| Promise\<void\> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[VPN错误码](errorcode-net-vpn.md)。

| 错误码ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 19900001       |  Invalid parameter value.  |
| 19900002  |  System internal error.  |

**示例：**

```ts
import { vpnExtension, VpnExtensionAbility } from '@kit.NetworkKit';
import { BusinessError } from "@kit.BasicServicesKit";

export default class MyVpnExtAbility extends VpnExtensionAbility {
  onCreate() {
    let vpnConnection = vpnExtension.createVpnConnection(this.context);

    // 可通过generateVpnId()获取vpnId
    let vpnId = 'testVpnId';
    vpnConnection.destroy(vpnId).then(() => {
      console.info("destroy success");
    }).catch((error: BusinessError) => {
      console.error(`destroy fail, Code is ${error.code}, message is ${error.message}`);
    });
  }
}
```

### generateVpnId<sup>20+</sup>

generateVpnId(): Promise\<string\>

生成VPN唯一标识。使用Promise异步回调。

如需使用系统多VPN能力，需调用该接口生成vpnId，配置到VpnConfig中。

>**注意**
>
>当前系统多VPN能力仅支持IPv4。

**系统能力**：SystemCapability.Communication.NetManager.Vpn

**返回值：**

| 类型            | 说明                                                  |
| --------------- | ----------------------------------------------------- |
| Promise\<string\> | 以Promise形式返回获取结果，返回vpnId。 |

**错误码：**

以下错误码的详细介绍请参见[VPN错误码](errorcode-net-vpn.md)。

| 错误码ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 19900001       |  Invalid parameter value.  |
| 19900002  |  System internal error.  |

**示例：**

```ts
import { vpnExtension, VpnExtensionAbility } from '@kit.NetworkKit';
import { BusinessError } from "@kit.BasicServicesKit";

export default class MyVpnExtAbility extends VpnExtensionAbility {
  onCreate() {
    let vpnConnection = vpnExtension.createVpnConnection(this.context);
    vpnConnection.generateVpnId().then((data) => {
      if (data) {
        console.info("generateVpnId success, vpnId = " + JSON.stringify(data));
      }
    }).catch((error: BusinessError) => {
      console.error(`generateVpnId fail, Code is ${error.code}, message is ${error.message}`);
    });
  }
}
```
### protectProcessNet<sup>22+</sup>

protectProcessNet(): Promise\<void\>

保护应用进程不受VPN连接影响，被保护的进程直接基于物理网络收发数据，流量不通过VPN转发。使用Promise异步回调。

**系统能力**：SystemCapability.Communication.NetManager.Vpn

**返回值：**

| 类型            | 说明                                                  |
| --------------- | ----------------------------------------------------- |
| Promise\<void\> | Promise对象，无返回结果。 |

**示例：**

```js
import { vpnExtension, VpnExtensionAbility } from '@kit.NetworkKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let g_tunnelFd = -1;
export default class MyVpnExtAbility  extends VpnExtensionAbility {
  onCreate() {
    let vpnConnection = vpnExtension.createVpnConnection(this.context);
    console.info("VPN createVpnConnection: " + JSON.stringify(vpnConnection));
    this.ProtectNetByProcess();
  }
  CreateTunnel() {
    g_tunnelFd = 8888;
  }
  ProtectNetByProcess() {
    hilog.info(0x0000, 'developTag', '%{public}s', 'vpn ProtectNetByProcess');
    let vpnConnection = vpnExtension.createVpnConnection(this.context);
    vpnConnection.protectProcessNet().then(() => {
      hilog.info(0x0000, 'developTag', '%{public}s', 'vpn ProtectNetByProcess Success');
      this.CreateTunnel();
    }).catch((err: Error) => {
      hilog.error(0x0000, 'developTag', 'vpn ProtectNetByProcess Failed %{public}s', JSON.stringify(err) ?? '');
    })
  }
}
```

## VpnConfig

三方VPN配置参数。

**系统能力**：SystemCapability.Communication.NetManager.Vpn

<!--Table: 19%; 20%; 8%; 8%; 45%-->
| 名称             | 类型                                      | 只读 | 可选 | 说明                                       |
| ---------------- | ----------------------------------------- | ---- | ---- | ------------------------------------------ |
| addresses           | Array\<[LinkAddress](js-apis-net-connection.md#linkaddress)\>  | 否  | 否 | VPN虚拟网卡的IP地址。API version 23之前，最多支持64个IP地址；从API version 23开始，最多支持2000个IP地址。                                  |
| vpnId<sup>20+</sup>           | string | 否 | 是 | VPN唯一标识。 | 
| routes              | Array\<[RouteInfo](js-apis-net-connection.md#routeinfo)\>      | 否  | 是 | VPN虚拟网卡的路由信息（API version 23前最多可配置1024条路由；从API version 23开始最多可配置10000条路由）。                  |
| dnsAddresses        | Array\<string\>                                                 | 否  | 是 | DNS服务器地址信息。当配置DNS服务器地址后，VPN启动状态下被代理的应用上网时，使用配置的DNS服务器做DNS查询。最多可配置64个DNS服务器地址。                                    |
| searchDomains       | Array\<string\>                                                | 否  | 是 | DNS的搜索域列表。                                     |
| mtu                 | number                                                         | 否  | 是 | 最大传输单元MTU值（单位：字节）。取值范围：[576, 1500]。               |
| isIPv4Accepted      | boolean                                                         | 否  | 是 | 是否支持IPv4。true表示支持，false表示不支持，默认值为true。<br>**注意**：若支持IPv4功能，需要在addresses中配置IPv4类型的IP地址。  |
| isIPv6Accepted      | boolean                                                         | 否  | 是 | 是否支持IPv6。true表示支持，false表示不支持，默认值为false。<br>**注意**：若支持IPv6功能，需要在addresses中配置IPv6类型的IP地址。  |
| isInternal          | boolean                                                         | 否  | 是 | 是否支持内置VPN。true表示支持，false表示不支持，默认值为false。 |
| isBlocking          | boolean                                                        | 否  | 是 | 是否阻塞模式。true表示阻塞模式，false表示非阻塞模式，默认值为false。       |
| trustedApplications | Array\<string\>                                                | 否  | 是 | 受信任的应用信息列表，string类型表示的包名。当配置该列表后，仅该列表中的应用数据才能根据routes被VPN代理。API version 23前最多可配置64个受信任的应用包名；从API version 23开始最多可配置256个受信任的应用包名。<br>**注意**：trustedApplications和blockedApplications列表不能同时配置。                         |
| blockedApplications | Array\<string\>                                                 | 否  | 是 | 被阻止的应用信息列表，string类型表示的包名。当配置该列表后，该列表中的应用数据不会被VPN代理，其他应用可以根据routes配置被VPN代理。API version 23前最多可配置64个被阻止的应用包名；从API version 23开始最多可配置256个被阻止的应用包名。<br>**注意**：trustedApplications和blockedApplications列表不能同时配置。                         |

**示例：**

```js
import { vpnExtension} from '@kit.NetworkKit';

let vpnConfig: vpnExtension.VpnConfig = {
  addresses: [],
  vpnId: '123',
  routes: [{
    // 网卡名称配置为空时，系统默认将路由配置到VPN虚拟网卡。
    // 如填写非虚拟网卡实际名称，可能导致路由配置异常。
    interface: "vpn-tun",
    destination: {
      address: {
        address:'',
        family:1,
        port:8080
      },
      prefixLength:1
    },
    gateway: {
      // 网关地址配置为空时，系统默认将VPN虚拟网卡地址作为网关地址。
      // 如需使用非VPN虚拟网卡地址，请确保地址可达，否则可能导致路由配置失败。
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
  let vpnConnection: vpnExtension.VpnConnection = vpnExtension.createVpnConnection(context);
  vpnConnection.create(vpnConfig).then((data) => {
    console.info("VPN create " + JSON.stringify(data));
  })
}
```

## 附录

VpnExtensionAbility不支持以下模块的引用。

| Kit | 模块 |
|--|--|
| Contacts Kit | [@ohos.contact (联系人)](../apis-contacts-kit/js-apis-contact.md) |
| Location Kit | [@ohos.geolocation (位置服务)](../apis-location-kit/js-apis-geolocation.md) |
| Location Kit | [@ohos.geoLocationManager (位置服务)](../apis-location-kit/js-apis-geoLocationManager.md) |
| Audio Kit | [@ohos.multimedia.audio (音频管理)](../apis-audio-kit/arkts-apis-audio.md) |
| Camera Kit | [@ohos.multimedia.camera (相机管理)](../apis-camera-kit/arkts-apis-camera.md) |
| Telephony Kit | [@ohos.telephony.call (拨打电话)](../apis-telephony-kit/js-apis-call.md) |
| Telephony Kit | [@ohos.telephony.sim (SIM卡管理)](../apis-telephony-kit/js-apis-sim.md) |
| Telephony Kit | [@ohos.telephony.sms (短信服务)](../apis-telephony-kit/js-apis-sms.md) |