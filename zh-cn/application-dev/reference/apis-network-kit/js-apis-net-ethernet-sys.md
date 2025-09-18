# @ohos.net.ethernet (以太网连接管理)（系统接口）

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->

以太网连接管理主要提供有线网络能力，提供设置有线网络的IP地址，子网掩码，网关，DNS，代理等信息。

> **说明：**
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块为系统接口。

## 导入模块

```ts
import { ethernet } from '@kit.NetworkKit';
```

## ethernet.setIfaceConfig<sup>9+</sup>

setIfaceConfig(iface: string, ic: InterfaceConfiguration, callback: AsyncCallback\<void>): void

设置网络接口配置信息，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Ethernet

**参数：**

| 参数名   | 类型                                              | 必填 | 说明                                       |
| -------- | ------------------------------------------------- | ---- | ------------------------------------------ |
| iface    | string                                            | 是   | 网络接口名。                                     |
| ic       | [InterfaceConfiguration](#interfaceconfiguration9) | 是   | 要设置的网络接口配置信息。                   |
| callback | AsyncCallback\<void>                     | 是   | 回调函数。成功无返回，失败返回对应错误码。 |

**错误码：**

| 错误码ID | 错误信息                                 |
| ------- | ----------------------------------------|
| 201     | Permission denied.                      |
| 202     | Non-system applications use system APIs.                      |
| 401     | Parameter error.                        |
| 2200001 | Invalid parameter value.                |
| 2200002 | Failed to connect to the service.       |
| 2200003 | System internal error.                  |
| 2201004 | Invalid Ethernet profile.  |
| 2201005 | Device information does not exist.  |
| 2201006 | Ethernet device not connected.                    |
| 2201007 | Ethernet failed to write user configuration information.    |

**示例：**

```ts
import { ethernet } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
    console.error("setIfaceConfig callback error = " + JSON.stringify(error));
  } else {
    console.info("setIfaceConfig callback ok");
  }
});
```

## ethernet.setIfaceConfig<sup>9+</sup>

setIfaceConfig(iface: string, ic: InterfaceConfiguration): Promise\<void>

设置网络接口配置信息，使用Promise方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Ethernet

**参数：**

| 参数名 | 类型                                              | 必填 | 说明                     |
| ------ | ------------------------------------------------- | ---- | ------------------------ |
| iface  | string                                            | 是   | 接口名。                   |
| ic     | [InterfaceConfiguration](#interfaceconfiguration9) | 是   | 要设置的网络接口配置信息。 |

**返回值：**

| 类型                | 说明                                                        |
| ------------------- | ----------------------------------------------------------- |
| Promise\<void>       | 以Promise形式返回执行结果。成功无返回，失败返回对应错误码。 |

**错误码：**

| 错误码ID | 错误信息                                 |
| ------- | ----------------------------------------|
| 201     | Permission denied.                      |
| 202     | Non-system applications use system APIs.                      |
| 401     | Parameter error.                        |
| 2200001 | Invalid parameter value.                |
| 2200002 |Failed to connect to the service. |
| 2200003 | System internal error.                  |
| 2201004 | Invalid Ethernet profile.  |
| 2201005 | Device information does not exist.  |
| 2201006 | Ethernet device not connected.                    |
| 2201007 | Ethernet failed to write user configuration information.    |

**示例：**

```ts
import { ethernet } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
  console.info("setIfaceConfig promise ok");
}).catch((error: BusinessError)  => {
  console.error("setIfaceConfig promise error = " + JSON.stringify(error));
});
```

## ethernet.getIfaceConfig<sup>9+</sup>

getIfaceConfig(iface: string, callback: AsyncCallback\<InterfaceConfiguration>): void

获取指定网络接口信息，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Ethernet

**参数：**

| 参数名   | 类型                                            | 必填  | 说明         |
| -------- | ----------------------------------------------- | ----- | ------------ |
| iface    | string                                          | 是    | 指定网络接口。 |
| callback | AsyncCallback\<[InterfaceConfiguration](#interfaceconfiguration9)> | 是    | 回调函数。返回指定网络接口信息。   |

**错误码：**

| 错误码ID | 错误信息                                 |
| ------- | ----------------------------------------|
| 201     | Permission denied.                      |
| 202     | Non-system applications use system APIs.                      |
| 401     | Parameter error.                        |
| 2200001 | Invalid parameter value.                |
| 2200002 | Failed to connect to the service.       |
| 2200003 | System internal error.                  |
| 2201005 | Device information does not exist.  |

**示例：**

```ts
import { ethernet } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

ethernet.getIfaceConfig("eth0", (error: BusinessError, value: ethernet.InterfaceConfiguration) => {
  if (error) {
    console.error("getIfaceConfig  callback error = " + JSON.stringify(error));
  } else {
    console.info("getIfaceConfig callback mode = " + JSON.stringify(value.mode));
    console.info("getIfaceConfig callback ipAddr = " + JSON.stringify(value.ipAddr));
    console.info("getIfaceConfig callback route = " + JSON.stringify(value.route));
    console.info("getIfaceConfig callback gateway = " + JSON.stringify(value.gateway));
    console.info("getIfaceConfig callback netMask = " + JSON.stringify(value.netMask));
    console.info("getIfaceConfig callback dnsServers = " + JSON.stringify(value.dnsServers));
  }
});
```

## ethernet.getIfaceConfig<sup>9+</sup>

getIfaceConfig(iface: string): Promise\<InterfaceConfiguration>

获取指定网络接口信息，使用Promise方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Ethernet

**参数：**

| 参数名   | 类型                                    | 必填 | 说明         |
| -------- | --------------------------------------- | ---- | ------------ |
| iface    | string                                  | 是   | 指定网络接口。 |

**返回值：**

| 类型                              | 说明                               |
| --------------------------------- | ---------------------------------- |
| Promise\<[InterfaceConfiguration](#interfaceconfiguration9)>   | 以Promise形式返回接口信息。        |

**错误码：**

| 错误码ID | 错误信息                                 |
| ------- | ----------------------------------------|
| 201     | Permission denied.                      |
| 202     | Non-system applications use system APIs.                      |
| 401     | Parameter error.                        |
| 2200001 | Invalid parameter value.                |
| 2200002 | Failed to connect to the service.       |
| 2200003 | System internal error.                  |
| 2201005 | Device information does not exist.  |

**示例：**

```ts
import { ethernet } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

ethernet.getIfaceConfig("eth0").then((data: ethernet.InterfaceConfiguration) => {
  console.info("getIfaceConfig promise mode = " + JSON.stringify(data.mode));
  console.info("getIfaceConfig promise ipAddr = " + JSON.stringify(data.ipAddr));
  console.info("getIfaceConfig promise route = " + JSON.stringify(data.route));
  console.info("getIfaceConfig promise gateway = " + JSON.stringify(data.gateway));
  console.info("getIfaceConfig promise netMask = " + JSON.stringify(data.netMask));
  console.info("getIfaceConfig promise dnsServers = " + JSON.stringify(data.dnsServers));
}).catch((error: BusinessError) => {
  console.error("getIfaceConfig promise error = " + JSON.stringify(error));
});
```

## ethernet.isIfaceActive<sup>9+</sup>

isIfaceActive(iface: string, callback: AsyncCallback\<number>): void

判断接口是否已激活，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Ethernet

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                               |
| -------- | --------------------------- | ---- | -------------------------------------------------- |
| iface    | string                      | 是   | 接口名。为空时代表查询是否存在激活接口。             |
| callback | AsyncCallback\<number>       | 是   | 回调函数。已激活：1，未激活：0，其他为获取失败错误码。 |

**错误码：**

| 错误码ID | 错误信息                                 |
| ------- | ----------------------------------------|
| 201     | Permission denied.                      |
| 202     | Non-system applications use system APIs.                      |
| 401     | Parameter error.                        |
| 2200001 | Invalid parameter value.                |
| 2200002 | Failed to connect to the service.       |
| 2200003 | System internal error.                  |
| 2201005 | Device information does not exist.  |

**示例：**

```ts
import { ethernet } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

ethernet.isIfaceActive("eth0", (error: BusinessError, value: number) => {
  if (error) {
    console.error("whether2Activate callback error = " + JSON.stringify(error));
  } else {
    console.info("whether2Activate callback = " + JSON.stringify(value));
  }
});
```

## ethernet.isIfaceActive<sup>9+</sup>

isIfaceActive(iface: string): Promise\<number>

判断接口是否已激活，使用Promise方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Ethernet

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| iface  | string | 是   | 接口名。为空时代表查询是否存在激活接口。 |

**返回值：**

| 类型            | 说明                                                               |
| ----------------| ------------------------------------------------------------------ |
| Promise\<number> | 以Promise形式返回获取结果。已激活：1，未激活：0，其他为获取失败错误码。|

**错误码：**

| 错误码ID | 错误信息                                 |
| ------- | ----------------------------------------|
| 201     | Permission denied.                      |
| 202     | Non-system applications use system APIs.                      |
| 401     | Parameter error.                        |
| 2200001 | Invalid parameter value.                |
| 2200002 | Failed to connect to the service.       |
| 2200003 | System internal error.                  |
| 2201005 | Device information does not exist.  |

**示例：**

```ts
import { ethernet } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

ethernet.isIfaceActive("eth0").then((data: number) => {
  console.info("isIfaceActive promise = " + JSON.stringify(data));
}).catch((error: BusinessError) => {
  console.error("isIfaceActive promise error = " + JSON.stringify(error));
});
```

## ethernet.getAllActiveIfaces<sup>9+</sup>

getAllActiveIfaces(callback: AsyncCallback\<Array\<string>>): void

获取活动的网络接口，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Ethernet

**参数：**

| 参数名   | 类型                                 | 必填 | 说明                           |
| -------- | ------------------------------------ | ---- | ------------------------------ |
| callback | AsyncCallback\<Array\<string>>         | 是   | 回调函数。返回值为对应接口名。 |

**错误码：**

| 错误码ID | 错误信息                                 |
| ------- | ----------------------------------------|
| 201     | Permission denied.                      |
| 202     | Non-system applications use system APIs.                      |
| 2200002 | Failed to connect to the service.       |
| 2200003 | System internal error.                  |

**示例：**

```ts
import { ethernet } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

ethernet.getAllActiveIfaces((error: BusinessError, value: string[]) => {
  if (error) {
    console.error("getAllActiveIfaces callback error = " + JSON.stringify(error));
  } else {
    console.info("getAllActiveIfaces callback value.length = " + JSON.stringify(value.length));
    for (let i = 0; i < value.length; i++) {
      console.info("getAllActiveIfaces callback = " + JSON.stringify(value[i]));
    }
  }
});
```

## ethernet.getAllActiveIfaces<sup>9+</sup>

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
| 202     | Non-system applications use system APIs.                      |
| 2200002 | Failed to connect to the service.       |
| 2200003 | System internal error.                  |

**示例：**

```ts
import { ethernet } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

ethernet.getAllActiveIfaces().then((data: string[]) => {
  console.info("getAllActiveIfaces promise data.length = " + JSON.stringify(data.length));
  for (let i = 0; i < data.length; i++) {
    console.info("getAllActiveIfaces promise  = " + JSON.stringify(data[i]));
  }
}).catch((error:BusinessError) => {
  console.error("getAllActiveIfaces promise error = " + JSON.stringify(error));
});
```

## ethernet.on('interfaceStateChange')<sup>10+</sup>

on(type: 'interfaceStateChange', callback: Callback\<InterfaceStateInfo>): void

注册网卡热插拔事件，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Ethernet

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| type     | string                  | 是   | 订阅的事件类型，'interfaceStateChange'。 |
| callback | AsyncCallback\<[InterfaceStateInfo](#interfacestateinfo11)> | 是   | 回调函数。返回以太网卡状态信息。 |

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 201     | Permission denied.                      |
| 202     | Non-system applications use system APIs.                      |
| 401     | Parameter error.                     |

**示例：**

```ts
import { ethernet } from '@kit.NetworkKit';

ethernet.on('interfaceStateChange', (data: object) => {
  console.info('on interfaceSharingStateChange：' + JSON.stringify(data));
});
```

## ethernet.off('interfaceStateChange')<sup>10+</sup>

off(type: 'interfaceStateChange', callback?: Callback\<InterfaceStateInfo\>): void

注销网卡热插拔事件，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Ethernet

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| type     | string                  | 是   | 订阅的事件类型，'interfaceStateChange'。 |
| callback | AsyncCallback\<[InterfaceStateInfo](#interfacestateinfo11)> | 否   | 回调函数。返回以太网卡状态信息。 |

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 201     | Permission denied.                      |
| 202     | Non-system applications use system APIs.                      |
| 401     | Parameter error.                     |

**示例：**

```ts
import { ethernet } from '@kit.NetworkKit';

ethernet.off('interfaceStateChange');
```


## ethernet.getEthernetDeviceInfos<sup>20+</sup>

getEthernetDeviceInfos(): Promise\<Array\<EthernetDeviceInfos>>

获取以太网设备信息。使用Promise异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Ethernet

**返回值：**

| 类型                | 说明                                                        |
| ------------------- | ----------------------------------------------------------- |
| Promise\<Array\<[EthernetDeviceInfos](#ethernetdeviceinfos20)>>  | 以Promise形式返回执行结果。成功返回以太网设备信息列表，失败返回对应错误码。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[以太网连接错误码](errorcode-net-ethernet.md)。

| 错误码ID | 错误信息                                |
| ------- | ----------------------------------------|
| 201     | Permission denied.                      |
| 202     | Non-system applications use system APIs.|
| 2201005 | Device information does not exist.      |

**示例：**

```ts
import { ethernet } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

ethernet.getEthernetDeviceInfos().then((data: Array<ethernet.EthernetDeviceInfos>) => {
  console.info("getEthernetDeviceInfos data.length = " + JSON.stringify(data.length));
  for (let i = 0; i < data.length; i++) {
    console.info("getEthernetDeviceInfos = " + JSON.stringify(data[i]));
  }
}).catch((err: BusinessError) => {
  console.error("getEthernetDeviceInfos err = " + err.code);
});
```

## InterfaceConfiguration<sup>9+</sup>

以太网连接配置网络信息。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Ethernet

| 名称          | 类型                    | 必填 | 说明                                                         |
| ------------ | ----------------------- | ---|------------------------------------------------------------ |
| mode         | [IPSetMode](#ipsetmode9) | 是 | 以太网连接配置模式。 |
| ipAddr       | string                  | 是 | 以太网连接静态配置ip信息，地址值范围0-255.0-255.0-255.0-255（DHCP模式无需配置）。 |
| route        | string                  | 是 | 以太网连接静态配置路由信息，地址值范围0-255.0-255.0-255.0-255（DHCP模式无需配置）。 |
| gateway      | string                  | 是 | 以太网连接配置网关信息，地址值范围0-255.0-255.0-255.0-255（DHCP模式无需配置）。 |
| netMask      | string                  | 是 | 以太网连接配置子网掩码，地址值范围0-255.0-255.0-255.0-255（DHCP模式无需配置）。 |
| dnsServers   | string                  | 是 | 以太网连接配置dns服务地址，地址值范围0-255.0-255.0-255.0-255（DHCP模式无需配置）多地址间用“,”隔开。 |
| httpProxy<sup>10+</sup> | [HttpProxy](js-apis-net-connection.md#httpproxy10) | 否 | 以太网连接代理配置信息，默认情况下不配置任何代理信息。 |

## InterfaceStateInfo<sup>11+</sup>

监听以太网卡状态变化

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Ethernet

| 名称         | 类型                    | 必填 | 说明                                                 |
| ------------ | ----------------------- | --- | ---------------------------------------------------- |
| iface        | string                  |  是 | 以太网卡名称。                                        |
| active       | boolean                 |  是 | 以太网卡是否处于激活状态（true：激活；false：未激活）。 |

## IPSetMode<sup>9+</sup>

以太网连接模式。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Ethernet

| 名称                  | 值   | 说明                        |
| --------------------- | ---- | -------------------------- |
| STATIC                | 0    | 以太网连接静态配置网络信息。 |
| DHCP                  | 1    | 以太网连接动态配置网络信息。 |
| LAN_STATIC<sup>11+</sup>| 2    | LAN连接静态配置网络信息。    |
| LAN_DHCP<sup>11+</sup>  | 3    | LAN连接动态配置网络信息。    |

## EthernetDeviceInfos<sup>20+</sup>

以太网设备信息。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Ethernet

| 名称           | 类型                    | 只读 | 可选 | 说明                                                         |
| ------------   | ----------------------- | ---| ---|------------------------------------------------------------ |
| ifaceName      | string                  | 否 | 否 | 网络接口名。      |
| deviceName     | string                  | 否 | 否 | 设备名称。    |
| connectionMode | [DeviceConnectionType](#deviceconnectiontype20)  | 否 | 否 | 设备连接模式。 |
| supplierName   | string                  | 否 | 否 | 供应商名称。 |
| supplierId     | string                  | 否 | 否 | 供应商标识号。 |
| productName    | string                  | 否 | 否 | 产品名称。 |
| maximumRate    | string                  | 否 | 否 | 最大连接速率。 |

## DeviceConnectionType<sup>20+</sup>

以太网设备连接模式。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Ethernet

| 名称                  | 值   | 说明                        |
| --------------------- | ---- | -------------------------- |
| BUILT_IN              | 0    | 以太网设备为内置连接模式。 |
| EXTERNAL              | 1    | 以太网设备为外接连接模式。例如，以太网设备通过USB连接。 |