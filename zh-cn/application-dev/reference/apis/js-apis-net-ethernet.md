# @ohos.net.ethernet (以太网连接管理)

以太网连接管理主要提供有线网络能力，提供设置有线网络的IP地址，子网掩码，网关，DNS等信息

> **说明：**
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import ethernet from '@ohos.net.ethernet'
```

## ethernet.setIfaceConfig

setIfaceConfig(iface: string, ic: InterfaceConfiguration, callback: AsyncCallback\<void>): void

设置网络接口配置信息，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Ethernet

**参数：**

| 参数名   | 类型                                              | 必填 | 说明                                       |
| -------- | ------------------------------------------------- | ---- | ------------------------------------------ |
| iface    | string                                            | 是   | 网络接口名                                     |
| ic       | [InterfaceConfiguration](#interfaceconfiguration) | 是   | 要设置的网络接口配置信息                   |
| callback | AsyncCallback\<void>                     | 是   | 回调函数，成功无返回，失败返回对应错误码。 |

**错误码：**

| 错误码ID | 错误信息                                 |
| ------- | ----------------------------------------|
| 201     | Permission denied.                      |
| 401     | Parameter error.                        |
| 2200001 | Invalid parameter value.                |
| 2200002 | Operation failed. Cannot connect to service.|
| 2200003 | System internal error.                  |
| 2201005 | The device information does not exist.  |
| 2201006 | Device disconnected.                    |
| 2201007 | Failed to write the user configuration.    |

**示例：**

```js
ethernet.setIfaceConfig("eth0", {
  mode: 0,
  ipAddr: "192.168.xx.xxx",
  route: "192.168.xx.xxx",
  gateway: "192.168.xx.xxx",
  netMask: "255.255.255.0",
  dnsServers: "1.1.1.1"
}, (error) => {
  if (error) {
    console.log("setIfaceConfig callback error = " + JSON.stringify(error));
  } else {
    console.log("setIfaceConfig callback ok ");
  }
});
```

## ethernet.setIfaceConfig

setIfaceConfig(iface: string, ic: InterfaceConfiguration): Promise\<void>

设置网络接口配置信息，使用Promise方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Ethernet

**参数：**

| 参数名 | 类型                                              | 必填 | 说明                     |
| ------ | ------------------------------------------------- | ---- | ------------------------ |
| iface  | string                                            | 是   | 接口名                   |
| ic     | [InterfaceConfiguration](#interfaceconfiguration) | 是   | 要设置的网络接口配置信息 |

**返回值：**

| 类型                | 说明                                                        |
| ------------------- | ----------------------------------------------------------- |
| Promise\<void>       | 以Promise形式返回执行结果。成功无返回，失败返回对应错误码。 |

**错误码：**

| 错误码ID | 错误信息                                 |
| ------- | ----------------------------------------|
| 201     | Permission denied.                      |
| 401     | Parameter error.                        |
| 2200001 | Invalid parameter value.                |
| 2200002 | Operation failed. Cannot connect to service.|
| 2200003 | System internal error.                  |
| 2201005 | The device information does not exist.  |
| 2201006 | Device disconnected.                   |
| 2201007 | Failed to write the user configuration.    |

**示例：**

```js
ethernet.setIfaceConfig("eth0", {
  mode: 0,
  ipAddr: "192.168.xx.xxx",
  route: "192.168.xx.xxx",
  gateway: "192.168.xx.xxx",
  netMask: "255.255.255.0",
  dnsServers: "1.1.1.1"
}).then(() => {
  console.log("setIfaceConfig promise ok ");
}).catch(error => {
  console.log("setIfaceConfig promise error = " + JSON.stringify(error));
});
```

## ethernet.getIfaceConfig

getIfaceConfig(iface: string, callback: AsyncCallback\<InterfaceConfiguration>): void

获取指定网络接口信息，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Ethernet

**参数：**

| 参数名   | 类型                                            | 必填  | 说明         |
| -------- | ----------------------------------------------- | ----- | ------------ |
| iface    | string                                          | 是    | 指定网络接口 |
| callback | AsyncCallback\<[InterfaceConfiguration](#interfaceconfiguration)> | 是    | 回调函数，返回指定网络接口信息   |

**错误码：**

| 错误码ID | 错误信息                                 |
| ------- | ----------------------------------------|
| 201     | Permission denied.                      |
| 401     | Parameter error.                        |
| 2200001 | Invalid parameter value.                |
| 2200002 | Operation failed. Cannot connect to service.|
| 2200003 | System internal error.                  |
| 2201005 | The device information does not exist.  |

**示例：**

```js
ethernet.getIfaceConfig("eth0", (error, value) => {
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

## ethernet.getIfaceConfig

getIfaceConfig(iface: string): Promise\<InterfaceConfiguration>

获取指定网络接口信息，使用Promise方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Ethernet

**参数：**

| 参数名   | 类型                                    | 必填 | 说明         |
| -------- | --------------------------------------- | ---- | ------------ |
| iface    | string                                  | 是   | 指定网络接口 |

**返回值：**

| 类型                              | 说明                               |
| --------------------------------- | ---------------------------------- |
| Promise\<[InterfaceConfiguration](#interfaceconfiguration)>   | 以Promise形式返回接口信息。        |

**错误码：**

| 错误码ID | 错误信息                                 |
| ------- | ----------------------------------------|
| 201     | Permission denied.                      |
| 401     | Parameter error.                        |
| 2200001 | Invalid parameter value.                |
| 2200002 | Operation failed. Cannot connect to service.|
| 2200003 | System internal error.                  |
| 2201005 | The device information does not exist.  |

**示例：**

```js
ethernet.getIfaceConfig("eth0").then((data) => {
  console.log("getIfaceConfig promise mode = " + JSON.stringify(data.mode));
  console.log("getIfaceConfig promise ipAddr = " + JSON.stringify(data.ipAddr));
  console.log("getIfaceConfig promise route = " + JSON.stringify(data.route));
  console.log("getIfaceConfig promise gateway = " + JSON.stringify(data.gateway));
  console.log("getIfaceConfig promise netMask = " + JSON.stringify(data.netMask));
  console.log("getIfaceConfig promise dnsServers = " + JSON.stringify(data.dnsServers));
}).catch(error => {
  console.log("getIfaceConfig promise error = " + JSON.stringify(error));
});
```

## ethernet.isIfaceActive

isIfaceActive(iface: string, callback: AsyncCallback\<number>): void

判断接口是否已激活，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Ethernet

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                               |
| -------- | --------------------------- | ---- | -------------------------------------------------- |
| iface    | string                      | 是   | 接口名。为空时代表查询是否存在激活接口             |
| callback | AsyncCallback\<number>       | 是   | 回调函数，已激活:1,未激活:0,其他为获取失败错误码。 |

**错误码：**

| 错误码ID | 错误信息                                 |
| ------- | ----------------------------------------|
| 201     | Permission denied.                      |
| 401     | Parameter error.                        |
| 2200001 | Invalid parameter value.                |
| 2200002 | Operation failed. Cannot connect to service.|
| 2200003 | System internal error.                  |
| 2201005 | The device information does not exist.  |

**示例：**

```js
ethernet.isIfaceActive("eth0", (error, value) => {
  if (error) {
    console.log("whether2Activate callback error = " + JSON.stringify(error));
  } else {
    console.log("whether2Activate callback = " + JSON.stringify(value));
  }
});
```

## ethernet.isIfaceActive

isIfaceActive(iface: string): Promise\<number>

判断接口是否已激活，使用Promise方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Ethernet

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| iface  | string | 是   | 接口名。为空时代表查询是否存在激活接口 |

**返回值：**

| 类型            | 说明                                                               |
| ----------------| ------------------------------------------------------------------ |
| Promise\<number> | 以Promise形式返回获取结果。已激活:1,未激活:0,其他为获取失败错误码。|

**错误码：**

| 错误码ID | 错误信息                                 |
| ------- | ----------------------------------------|
| 201     | Permission denied.                      |
| 401     | Parameter error.                        |
| 2200001 | Invalid parameter value.                |
| 2200002 | Operation failed. Cannot connect to service.|
| 2200003 | System internal error.                  |
| 2201005 | The device information does not exist.  |

**示例：**

```js
ethernet.isIfaceActive("eth0").then((data) => {
  console.log("isIfaceActive promise = " + JSON.stringify(data));
}).catch(error => {
  console.log("isIfaceActive promise error = " + JSON.stringify(error));
});
```

## ethernet.getAllActiveIfaces

getAllActiveIfaces(callback: AsyncCallback\<Array\<string>>): void

获取活动的网络接口，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Ethernet

**参数：**

| 参数名   | 类型                                 | 必填 | 说明                           |
| -------- | ------------------------------------ | ---- | ------------------------------ |
| callback | AsyncCallback\<Array\<string>>         | 是   | 回调函数，返回值为对应接口名。 |

**错误码：**

| 错误码ID | 错误信息                                 |
| ------- | ----------------------------------------|
| 201     | Permission denied.                      |
| 2200002 | Operation failed. Cannot connect to service.|
| 2200003 | System internal error.                  |

**示例：**

```js
ethernet.getAllActiveIfaces((error, value) => {
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

## ethernet.getAllActiveIfaces

getAllActiveIfaces(): Promise\<Array\<string>>

获取活动的网络接口，使用Promise方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Ethernet

**返回值：**

| 类型                           | 说明                                            |
| ------------------------------ | ----------------------------------------------- |
| Promise\<Array\<string>>         | 以Promise形式返回获取结果。返回值为对应接口名。 |

**错误码：**

| 错误码ID | 错误信息                                 |
| ------- | ----------------------------------------|
| 201     | Permission denied.                      |
| 2200002 | Operation failed. Cannot connect to service.|
| 2200003 | System internal error.                  |

**示例：**

```js
ethernet.getAllActiveIfaces().then((data) => {
  console.log("getAllActiveIfaces promise data.length = " + JSON.stringify(data.length));
  for (let i = 0; i < data.length; i++) {
    console.log("getAllActiveIfaces promise  = " + JSON.stringify(data[i]));
  }
}).catch(error => {
  console.log("getAllActiveIfaces promise error = " + JSON.stringify(error));
});
```

## InterfaceConfiguration

以太网连接配置网络信息。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Ethernet

| 名称          | 类型                    | 必填 | 说明                                                         |
| ------------ | ----------------------- | ---|------------------------------------------------------------ |
| mode         | [IPSetMode](#ipsetmode) | 是 | 以太网连接配置模式。 |
| ipAddr       | string                  | 是 | 以太网连接静态配置ip信息，地址值范围0-255.0-255.0-255.0-255（DHCP模式无需配置）。 |
| route        | string                  | 是 | 以太网连接静态配置路由信息，地址值范围0-255.0-255.0-255.0-255（DHCP模式无需配置）。 |
| gateway      | string                  | 是 | 以太网连接配置网关信息，地址值范围0-255.0-255.0-255.0-255（DHCP模式无需配置）。 |
| netMask      | string                  | 是 | 以太网连接配置子网掩码，地址值范围0-255.0-255.0-255.0-255（DHCP模式无需配置）。 |
| dnsServers   | string                  | 是 | 以太网连接配置dns服务地址，地址值范围0-255.0-255.0-255.0-255（DHCP模式无需配置）多地址间用“,”隔开。 |

## IPSetMode

以太网连接模式。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Ethernet

| 名称                  | 值   | 说明                   |
| ------------------------ | ---- | ---------------------- |
| STATIC | 0 | 以太网连接静态配置网络信息。 |
| DHCP   | 1 | 以太网连接动态配置网络信息。 |
