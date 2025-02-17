# @ohos.net.ethernet (以太网连接管理)

以太网连接管理主要提供有线网络能力，提供获取有线网络的IP地址等信息。

> **说明：**
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { ethernet } from '@kit.NetworkKit';
```

## HttpProxy

type HttpProxy = connection.HttpProxy;

网络代理配置信息。

**系统能力**：SystemCapability.Communication.NetManager.Ethernet

| 类型 | 说明                                       |
| ------- | ----------------------------------------|
| connection.HttpProxy     | 网络代理配置信息。      |


## ethernet.getMacAddress<sup>14+</sup>

getMacAddress(): Promise\<Array\<MacAddressInfo>>

获取所有以太网网卡名称及MAC地址信息，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.GET_ETHERNET_LOCAL_MAC

**系统能力**：SystemCapability.Communication.NetManager.Ethernet

**返回值：**

| 类型                                                    | 说明                               |
|-------------------------------------------------------| ---------------------------------- |
| Promise\<Array[\<MacAddressInfo>](#macaddressinfo14)> | 以Promise形式返回接口信息。        |

**错误码：**

| 错误码ID | 错误信息                                 |
| ------- | ----------------------------------------|
| 201     | Permission denied.                      |
| 2200002 | Operation failed. Cannot connect to service.       |
| 2201005 | Device information does not exist.  |

**示例：**

```ts
import { ethernet } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

ethernet.getMacAddress().then((data: Array<ethernet.MacAddressInfo>) => {
  console.info("getMacAddress promise data = " + JSON.stringify(data));
}).catch((error: BusinessError) => {
  console.error("getMacAddress promise error = " + JSON.stringify(error));
});
```

## MacAddressInfo<sup>14+</sup>
以太网网卡名称及MAC地址信息。

**系统能力**：SystemCapability.Communication.NetManager.Ethernet

| 名称         | 类型                    | 必填 | 说明                                                 |
| ------------ | ----------------------- | --- | ---------------------------------------------------- |
| iface        | string                  |  是 | 以太网卡名称。                                        |
| macAddress       | string                |  是 | 以太网卡MAC地址信息。 |
