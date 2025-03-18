# 网络连接管理

## 简介

网络连接管理提供管理网络一些基础能力，包括WiFi/蜂窝/Ethernet等多网络连接优先级管理、网络质量评估、订阅默认/指定网络连接状态变化、查询网络连接信息、DNS解析等功能。

> **说明：**
>
> 为了保证应用的运行效率，大部分API调用都是异步的，对于异步调用的API均提供了callback和Promise两种方式，以下示例均采用promise函数，更多方式可以查阅[API参考](../reference/apis-network-kit/js-apis-net-connection.md)。

## 基本概念

- 网络生产者：数据网络的提供方。比如WiFi、蜂窝、Ethernet等。
- 网络消费者：数据网络的使用方。比如应用或系统服务。
- 网络探测：检测网络有效性，避免将网络从可用网络切换到不可用网络。内容包括绑定网络探测、DNS探测、HTTP探测及HTTPS探测。
- 网络优选：处理多网络共存时选择最优网络。在网络状态、网络信息及评分发生变化时被触发。

## 约束

- 开发语言：JS
- 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 场景介绍

网络连接管理的典型场景如下所示。

- 接收指定网络的状态变化通知。
- 获取所有注册的网络。
- 根据数据网络查询网络的连接信息。
- 使用对应网络解析域名，获取所有IP。

具体开发方式介绍如下。

## 接口说明

完整的JS API说明以及实例代码请参考：[网络连接管理](../reference/apis-network-kit/js-apis-net-connection.md)。

| 接口名 | 描述 |
| ---- | ---- |
| getDefaultNet(callback: AsyncCallback\<NetHandle>): void; |获取一个含有默认网络的netId的NetHandle对象，使用callback回调。 |
| <!--DelRow--> getGlobalHttpProxy(callback: AsyncCallback\<HttpProxy>): void;| 获取网络的全局代理设置，使用callback回调。 |
| <!--DelRow--> setGlobalHttpProxy(httpProxy: HttpProxy, callback: AsyncCallback\<void>): void;| 设置网络全局Http代理配置信息，使用callback回调。 |
| setAppHttpProxy(httpProxy: HttpProxy): void;| 设置网络应用级Http代理配置信息。 |
| getAppNet(callback: AsyncCallback\<NetHandle>): void;| 获取一个App绑定的包含了网络netId的NetHandle对象，使用callback回调。 |
| setAppNet(netHandle: NetHandle, callback: AsyncCallback\<void>): void;| 绑定App到指定网络，绑定后的App只能通过指定网络访问外网。使用callback回调。 |
| getDefaultNetSync(): NetHandle; |使用同步方法获取默认激活的数据网络。可以使用getNetCapabilities去获取网络的类型、拥有的能力等信息。|
| hasDefaultNet(callback: AsyncCallback\<boolean>): void; |检查默认数据网络是否被激活，使用callback回调。 |
| getAllNets(callback: AsyncCallback\<Array\<NetHandle>>): void;| 获取所处于连接状态的网络的NetHandle对象列表，使用callback回调。 |
| getConnectionProperties(netHandle: NetHandle, callback: AsyncCallback\<ConnectionProperties>): void; |查询netHandle对应的网络的连接信息，使用callback回调。 |
| getNetCapabilities(netHandle: NetHandle, callback: AsyncCallback\<NetCapabilities>): void; |获取netHandle对应的网络的能力信息，使用callback回调。 |
| isDefaultNetMetered(callback: AsyncCallback\<boolean>): void; |检查当前网络上的数据流量使用是否被计量，使用callback方式作为异步方法。 |
| reportNetConnected(netHandle: NetHandle, callback: AsyncCallback\<void>): void;| 向网络管理报告网络处于可用状态，调用此接口说明应用程序认为网络的可用性(ohos.net.connection.NetCap.NET_CAPABILITY_VAILDATED)与网络管理不一致。使用callback回调。 |
| reportNetDisconnected(netHandle: NetHandle, callback: AsyncCallback\<void>): void;| 向网络管理报告网络处于不可用状态，调用此接口说明应用程序认为网络的可用性(ohos.net.connection.NetCap.NET_CAPABILITY_VAILDATED)与网络管理不一致。使用callback回调。 |
| getAddressesByName(host: string, callback: AsyncCallback\<Array\<NetAddress>>): void; |使用对应网络解析域名，获取所有IP，使用callback回调。 |
| <!--DelRow--> enableAirplaneMode(callback: AsyncCallback\<void>): void; | 设置网络为飞行模式，使用callback回调。 |
| <!--DelRow--> disableAirplaneMode(callback: AsyncCallback\<void>): void;| 关闭网络飞行模式，使用callback回调。 |
| createNetConnection(netSpecifier?: NetSpecifier, timeout?: number): NetConnection; | 返回一个NetConnection对象，netSpecifier指定关注的网络的各项特征。timeout是超时时间(单位：毫秒)，netSpecifier是timeout的必要条件，两者都没有则表示关注默认网络。 |
| bindSocket(socketParam: TCPSocket \| UDPSocket, callback: AsyncCallback\<void>): void; | 将TCPSocket或UDPSockett绑定到当前网络，使用callback回调。 |
| getAddressByName(host: string, callback: AsyncCallback\<NetAddress>): void; |使用对应网络解析域名，获取一个IP，调用callback。 |
| on(type: 'netAvailable', callback: Callback\<NetHandle>): void;                   |订阅网络可用事件。 |
| on(type: 'netCapabilitiesChange', callback: Callback\<NetCapabilityInfo\>): void; |订阅网络能力变化事件。 |
| on(type: 'netConnectionPropertiesChange', callback: Callback\<{ netHandle: NetHandle, connectionProperties: ConnectionProperties }>): void; |订阅网络连接信息变化事件。 |
| on(type: 'netBlockStatusChange', callback: Callback<{ netHandle: NetHandle, blocked: boolean }>): void; |订阅网络阻塞状态事件，使用callback方式作为异步方法。 |
| on(type: 'netLost', callback: Callback\<NetHandle>): void; |订阅网络丢失事件。 |
| on(type: 'netUnavailable', callback: Callback\<void>): void; |订阅网络不可用事件。 |
| register(callback: AsyncCallback\<void>): void; |订阅指定网络状态变化的通知。 |
| unregister(callback: AsyncCallback\<void>): void; |取消订阅默认网络状态变化的通知。 |

## 接收指定网络的状态变化通知

1. 声明接口调用所需要的权限：ohos.permission.GET_NETWORK_INFO。
此权限级别为normal，在申请权限前，请保证符合[权限使用的基本原则](../security/AccessToken/app-permission-mgmt-overview.md#权限使用的基本原则)。然后参考[访问控制-声明权限](../security/AccessToken/declare-permissions.md)声明对应权限。

2. 从@kit.NetworkKit中导入connection命名空间。

3. 调用[createNetConnection](../reference/apis-network-kit/js-apis-net-connection.md#connectioncreatenetconnection)方法，指定网络能力、网络类型和超时时间(可选，如不传入代表默认网络；创建不同于默认网络时可通过指定这些参数完成)，创建一个NetConnection对象。

4. 调用该对象的[on()](../reference/apis-network-kit/js-apis-net-connection.md#onnetavailable)方法，传入type和callback，订阅关心的事件。

5. 调用该对象的[register()](../reference/apis-network-kit/js-apis-net-connection.md#register)方法，订阅指定网络状态变化的通知。

6. 当网络可用时，会收到netAvailable事件的回调；当网络不可用时，会收到netUnavailable事件的回调。

7. 当不使用该网络时，可以调用该对象的[unregister()](../reference/apis-network-kit/js-apis-net-connection.md#unregister)方法，取消订阅。

```ts
// 引入包名。
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let netSpecifier: connection.NetSpecifier = {
  netCapabilities: {
    // 假设当前默认网络是WiFi，需要创建蜂窝网络连接，可指定网络类型为蜂窝网。
    bearerTypes: [connection.NetBearType.BEARER_CELLULAR],
    // 指定网络能力为Internet。
    networkCap: [connection.NetCap.NET_CAPABILITY_INTERNET]
  },
};

// 指定超时时间为10s(默认值为0)。
let timeout = 10 * 1000;

// 创建NetConnection对象。
let conn = connection.createNetConnection(netSpecifier, timeout);

// 订阅指定网络状态变化的通知。
conn.register((err: BusinessError, data: void) => {
  console.log(JSON.stringify(err));
});

// 订阅事件，如果当前指定网络可用，通过on_netAvailable通知用户。
conn.on('netAvailable', ((data: connection.NetHandle) => {
  console.log("net is available, netId is " + data.netId);
}));

// 订阅事件，如果当前指定网络不可用，通过on_netUnavailable通知用户。
conn.on('netUnavailable', ((data: void) => {
  console.log("net is unavailable, data is " + JSON.stringify(data));
}));

// 当不使用该网络时，可以调用该对象的unregister()方法，取消订阅。
conn.unregister((err: BusinessError, data: void) => {
});
```

## 监控默认网络变化并主动重建网络连接

根据当前网络状态及网络质量情况，默认网络可能会发生变化，如下所示。
1. 在WiFi弱信号的情况下，默认网络可能会切换到蜂窝网络。
2. 在蜂窝网络状态差的情况下，默认网络可能会切换到WiFi。
3. 关闭WiFi后，默认网络可能会切换到蜂窝网络。
4. 关闭蜂窝网络后，默认网络可能会切换到WiFi。
5. 在WiFi弱信号的情况下，默认网络可能会切换到其他WiFi(存在跨网情况)。
6. 在蜂窝网络状态差的情况下，默认网络可能会切换到其他蜂窝(存在跨网情况)。

本节旨在介绍监控默认网络的变化后，应用报文能够快速迁移到新默认网络上，具体做法如下。

### 监控默认网络变化

```ts
import { connection } from '@kit.NetworkKit';

async function test() {
  const netConnection = connection.createNetConnection();

  /* 监听默认网络改变。 */
  netConnection.on('netAvailable', (data: connection.NetHandle) => {
    console.log(JSON.stringify(data));
  });
}
```

### 默认网络变化后重新建立网络连接

#### 原网络连接使用http模块建立网络连接

如果您使用了http模块建立网络连接，由于该模块没有提供Close接口用于关闭Socket，在切换默认网络并建立新的网络连接后原有Socket不会立即关闭。因此请切换使用Remote Communication Kit建立网络连接。

#### 原网络连接使用Remote Communication Kit建立网络连接

```ts
import { rcp } from '@kit.RemoteCommunicationKit';
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let session = rcp.createSession();

async function useRcp() {
  /* 建立rcp请求。 */
  try {
    const request = await session.get('https://www.example.com');
    console.info(request.statusCode.toString());
  } catch (e) {
    console.error(e.code.toString());
  }
}

async function rcpTest() {
  const netConnection = connection.createNetConnection();
  netConnection.on('netAvailable', async (netHandle: connection.NetHandle) => {
    /* 发生默认网络切换，重新建立session。 */
    session.close();
    session = rcp.createSession();
    useRcp();
  });
  try {
    netConnection.register(() => {
    });
    useRcp();
  } catch (e) {
    console.error(e.code.toString());
  }
}
```

#### 原网络连接使用Socket模块建立连接

```ts
import { connection, socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let sock: socket.TCPSocket = socket.constructTCPSocketInstance();

async function useSocket() {
  let tcpConnectOptions: socket.TCPConnectOptions = {
    address: {
      address: '192.168.xx.xxx',
      port: 8080
    },
    timeout: 6000
  }

  /* 建立socket连接。 */
  sock.connect(tcpConnectOptions, (err: BusinessError) => {
    if (err) {
      console.error('connect fail');
      return;
    }
    console.log('connect success');

    /* 通过socket发送数据。 */
    let tcpSendOptions: socket.TCPSendOptions = {
      data: 'Hello, server!'
    }
    sock.send(tcpSendOptions).then(() => {
      console.log('send success');
    }).catch((err: BusinessError) => {
      console.error('send fail');
    });
  })
}

async function socketTest() {
  const netConnection = connection.createNetConnection();
  netConnection.on('netAvailable', async (netHandle: connection.NetHandle) => {
    console.log('default network changed');
    await sock.close();
    sock = socket.constructTCPSocketInstance();
    useSocket();
  });
  try {
    netConnection.register(() => {
    });
    useSocket();
  } catch (e) {
    console.error(e.code.toString());
  }
}
```

#### 原网络连接使用Socket Library建立网络连接

请在监控到默认网络变化后关闭原有Socket并重新建立Socket连接。

## 获取所有注册的网络

1. 声明接口调用所需要的权限：ohos.permission.GET_NETWORK_INFO。
此权限级别为normal，在申请权限前，请保证符合[权限使用的基本原则](../security/AccessToken/app-permission-mgmt-overview.md#权限使用的基本原则)。然后参考[访问控制-声明权限](../security/AccessToken/declare-permissions.md)声明对应权限。

2. 从@kit.NetworkKit中导入connection命名空间。

3. 调用[getAllNets](../reference/apis-network-kit/js-apis-net-connection.md#connectiongetallnets)方法，获取所有处于连接状态的网络列表。

```ts
// 引入包名。
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 构造单例对象。
export class GlobalContext {
  public netList: connection.NetHandle[] = [];
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}

// 获取所有处于连接状态的网络列表。
connection.getAllNets().then((data: connection.NetHandle[]) => {
  console.info("Succeeded to get data: " + JSON.stringify(data));
  if (data) {
    GlobalContext.getContext().netList = data;
  }
});
```

## 根据数据网络查询网络的能力信息及连接信息

1. 声明接口调用所需要的权限：ohos.permission.GET_NETWORK_INFO。
此权限级别为normal，在申请权限前，请保证符合[权限使用的基本原则](../security/AccessToken/app-permission-mgmt-overview.md#权限使用的基本原则)。然后参考[访问控制-声明权限](../security/AccessToken/declare-permissions.md)声明对应权限。

2. 从@kit.NetworkKit中导入connection命名空间。

3. 通过调用[getDefaultNet](../reference/apis-network-kit/js-apis-net-connection.md#connectiongetdefaultnet)方法，获取默认的数据网络(NetHandle)；或者通过调用[getAllNets](../reference/apis-network-kit/js-apis-net-connection.md#connectiongetallnets)方法，获取所有处于连接状态的网络列表(Array\<NetHandle>)。

4. 调用[getNetCapabilities](../reference/apis-network-kit/js-apis-net-connection.md#connectiongetnetcapabilities)方法，获取NetHandle对应网络的能力信息。能力信息包含了网络类型(蜂窝网络、Wi-Fi网络、以太网网络等)、网络具体能力等网络信息。

5. 调用[getConnectionProperties](../reference/apis-network-kit/js-apis-net-connection.md#connectiongetconnectionproperties)方法，获取NetHandle对应网络的连接信息。

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 构造单例对象。
export class GlobalContext {
  public netList: connection.NetHandle[] = [];
  public netHandle: connection.NetHandle|null = null;
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}

// 调用getDefaultNet方法，获取默认的数据网络(NetHandle)。
connection.getDefaultNet().then((data:connection.NetHandle) => {
  if (data.netId == 0) {
    // 当前无默认网络时，获取的netHandler的netid为0,属于异常情况，需要额外处理。
    return;
  }
  if (data) {
    console.info("getDefaultNet get data: " + JSON.stringify(data));
    GlobalContext.getContext().netHandle = data;
    // 获取netHandle对应网络的能力信息。能力信息包含了网络类型、网络具体能力等网络信息。
    connection.getNetCapabilities(GlobalContext.getContext().netHandle).then(
      (data: connection.NetCapabilities) => {
      console.info("getNetCapabilities get data: " + JSON.stringify(data));
      // 获取网络类型(bearerTypes)。
      let bearerTypes: Set<number> = new Set(data.bearerTypes);
      let bearerTypesNum = Array.from(bearerTypes.values());
      for (let item of bearerTypesNum) {
        if (item == 0) {
          // 蜂窝网络。
          console.log(JSON.stringify("BEARER_CELLULAR"));
        } else if (item == 1) {
          // Wi-Fi网络。
          console.log(JSON.stringify("BEARER_WIFI"));
        } else if (item == 3) {
          // 以太网网络。
          console.log(JSON.stringify("BEARER_ETHERNET"));
        }
      }

      // 获取网络具体能力(networkCap)。
      let itemNumber : Set<number> = new Set(data.networkCap);
      let dataNumber = Array.from(itemNumber.values());
      for (let item of dataNumber) {
        if (item == 0) {
          // 表示网络可以访问运营商的MMSC(Multimedia Message Service，多媒体短信服务)发送和接收彩信。
          console.log(JSON.stringify("NET_CAPABILITY_MMS"));
        } else if (item == 11) {
          // 表示网络流量未被计费。
          console.log(JSON.stringify("NET_CAPABILITY_NOT_METERED"));
        } else if (item == 12) {
          // 表示该网络应具有访问Internet的能力，该能力由网络提供者设置。
          console.log(JSON.stringify("NET_CAPABILITY_INTERNET"));
        } else if (item == 15) {
          // 表示网络不使用VPN(Virtual Private Network，虚拟专用网络)。
          console.log(JSON.stringify("NET_CAPABILITY_NOT_VPN"));
        } else if (item == 16) {
          // 表示该网络访问Internet的能力被网络管理成功验证，该能力由网络管理模块设置。
          console.log(JSON.stringify("NET_CAPABILITY_VALIDATED"));
        }
      }
    })
  }
});

// 获取netHandle对应网络的连接信息。连接信息包含了链路信息、路由信息等。
connection.getConnectionProperties(GlobalContext.getContext().netHandle).then((data: connection.ConnectionProperties) => {
  console.info("getConnectionProperties get data: " + JSON.stringify(data));
})

// 调用getAllNets,获取所有处于连接状态的网络列表(Array<NetHandle>)。
connection.getAllNets().then((data: connection.NetHandle[]) => {
  console.info("getAllNets get data: " + JSON.stringify(data));
  if (data) {
    GlobalContext.getContext().netList = data;

    let itemNumber : Set<connection.NetHandle> = new Set(GlobalContext.getContext().netList);
    let dataNumber = Array.from(itemNumber.values());
    for (let item of dataNumber) {
      // 循环获取网络列表每个netHandle对应网络的能力信息。
      connection.getNetCapabilities(item).then((data: connection.NetCapabilities) => {
        console.info("getNetCapabilities get data: " + JSON.stringify(data));
      })

      // 循环获取网络列表每个netHandle对应的网络的连接信息。
      connection.getConnectionProperties(item).then((data: connection.ConnectionProperties) => {
        console.info("getConnectionProperties get data: " + JSON.stringify(data));
      })
    }
  }
})
```

## 使用对应网络解析域名，获取所有IP

1. 声明接口调用所需要的权限：ohos.permission.INTERNET
此权限级别为normal，在申请权限前，请保证符合[权限使用的基本原则](../security/AccessToken/app-permission-mgmt-overview.md#权限使用的基本原则)。然后参考[访问控制-声明权限](../security/AccessToken/declare-permissions.md)声明对应权限。

2. 从@kit.NetworkKit中导入connection命名空间。

3. 调用[getAddressesByName](../reference/apis-network-kit/js-apis-net-connection.md#connectiongetaddressesbyname)方法，使用默认网络解析主机名以获取所有IP地址。

```ts
// 引入包名。
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 使用默认网络解析主机名以获取所有IP地址。
connection.getAddressesByName("xxxx").then((data: connection.NetAddress[]) => {
  console.info("Succeeded to get data: " + JSON.stringify(data));
});
```
