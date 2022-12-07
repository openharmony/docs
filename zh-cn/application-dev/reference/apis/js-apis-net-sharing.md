# 网络共享管理

网络共享管理分享设备已有网络给其他连接设备，支持Wi-Fi热点共享和蓝牙共享，同时提供网络共享状态、共享流量查询功能。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import sharing from '@ohos.net.sharing'
```

## sharing.isSharingSupported

isSharingSupported(callback: AsyncCallback\<boolean>): void

判断是否支持网络共享，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<boolean> | 是   | 回调函数，返回true代表支持网络共享。 |

**示例：**

```js
sharing.isSharingSupported((error, data) => {
    console.log(JSON.stringify(error));
    console.log(JSON.stringify(data));
});
```

## sharing.isSharingSupported

isSharingSupported(): Promise\<boolean>

判断是否支持网络共享，使用Promise方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<boolean> | 以Promise形式返回是否支持共享结果。 |

**示例：**

```js
sharing.isSharingSupported().then(data => {
    console.log(JSON.stringify(data));
}).catch(error => {
    console.log(JSON.stringify(error));
});
```

## sharing.isSharing

isSharing(callback: AsyncCallback\<boolean>): void

获取当前网络共享状态，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<boolean> | 是   | 回调函数，返回true代表网络共享中。 |

**示例：**

```js
sharing.isSharing((error, data) => {
    console.log(JSON.stringify(error));
    console.log(JSON.stringify(data));
});
```

## sharing.isSharing

isSharing(): Promise\<boolean>

获取当前网络共享状态，使用Promise方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<boolean> | 以Promise形式返回网络共享状态结果，返回true代表网络共享中。 |

**示例：**

```js
sharing.isSharing().then(data => {
    console.log(JSON.stringify(data));
}).catch(error => {
    console.log(JSON.stringify(error));
});
```

## sharing.startSharing

startSharing(type: SharingIfaceType, callback: AsyncCallback\<void>): void

开启指定类型共享，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| type | [SharingIfaceType](#sharingifacetype) | 是   | 共享类型，0：Wi-Fi 1：USB 2：BLUETOOTH。 |
| callback | AsyncCallback\<void> | 是   | 回调函数，返回开启网络共享结果。 |

**示例：**

```js
import SharingIfaceType from '@ohos.net.sharing'
sharing.startSharing(SharingIfaceType.SHARING_WIFI, (error) => {
    console.log(JSON.stringify(error));
});
```

## sharing.startSharing

startSharing(type: SharingIfaceType): Promise\<void>

开启指定类型共享，使用Promise方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| type | [SharingIfaceType](#sharingifacetype) | 是   | 共享类型，0：Wi-Fi 1：USB 2：BLUETOOTH。 |

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<void> | 以Promise形式返回开启共享执行结果。 |

**示例：**

```js
import SharingIfaceType from '@ohos.net.sharing'
sharing.startSharing(SharingIfaceType.SHARING_WIFI).then(() => {
    console.log("start wifi sharing successful");
}).catch(error => {
    console.log("start wifi sharing failed");
});
```

## sharing.stopSharing

stopSharing(type: SharingIfaceType, callback: AsyncCallback\<void>): void

关闭指定类型共享，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| type | [SharingIfaceType](#sharingifacetype) | 是   | 共享类型，0：Wi-Fi 1：USB 2：BLUETOOTH。 |
| callback | AsyncCallback\<void> | 是   | 回调函数,返回停止网络共享结果。 |

**示例：**

```js
import SharingIfaceType from '@ohos.net.sharing'
sharing.stopSharing(SharingIfaceType.SHARING_WIFI, (error) => {
    console.log(JSON.stringify(error));
});
```

## sharing.stopSharing

stopSharing(type: SharingIfaceType): Promise\<void>

关闭指定类型共享，使用Promise方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| type | [SharingIfaceType](#sharingifacetype) | 是   | 共享类型，0：Wi-Fi 1：USB 2：BLUETOOTH。 |

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<void> | 以Promise形式返回关闭共享执行结果。 |

**示例：**

```js
import SharingIfaceType from '@ohos.net.sharing'
sharing.stopSharing(SharingIfaceType.SHARING_WIFI).then(() => {
    console.log("stop wifi sharing successful");
}).catch(error => {
    console.log("stop wifi sharing failed");
});
```

## sharing.getStatsRxBytes

getStatsRxBytes(callback: AsyncCallback\<number>): void

获取共享网络接收数据量，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<number> | 是   | 回调函数，number代表数据量，单位：KB。 |

**示例：**

```js
sharing.getStatsRxBytes((error, data) => {
    console.log(JSON.stringify(error));
    console.log(JSON.stringify(data));
});
```

## sharing.getStatsRxBytes

getStatsRxBytes(): Promise\<number>

获取共享网络接收数据量，使用Promise方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<number> | 以Promise形式返回共享网络接收数据量，单位：KB。 |

**示例：**

```js
sharing.getStatsRxBytes().then(data => {
    console.log(JSON.stringify(data));
}).catch(error => {
    console.log(JSON.stringify(error));
});
```

## sharing.getStatsTxBytes

getStatsTxBytes(callback: AsyncCallback\<number>): void

获取共享网络发送数据量，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<number> | 是   | 回调函数，number代表数据量，单位：KB。 |

**示例：**

```js
sharing.getStatsTxBytes((error, data) => {
    console.log(JSON.stringify(error));
    console.log(JSON.stringify(data));
});
```

## sharing.getStatsTxBytes

getStatsTxBytes(): Promise\<number>

获取共享网络发送数据量，使用Promise方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<number> | 以Promise形式返回共享网络发送数据量，单位：KB。 |

**示例：**

```js
sharing.getStatsTxBytes().then(data => {
    console.log(JSON.stringify(data));
}).catch(error => {
    console.log(JSON.stringify(error));
});
```

## sharing.getStatsTotalBytes

getStatsTotalBytes(callback: AsyncCallback\<number>): void

获取共享网络总数据量，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<number> | 是   | 回调函数，number代表数据量，单位：KB。 |

**示例：**

```js
sharing.getStatsTotalBytes((error, data) => {
    console.log(JSON.stringify(error));
    console.log(JSON.stringify(data));
});
```

## sharing.getStatsTotalBytes

getStatsTotalBytes(): Promise\<number>

获取共享网络总数据量，使用Promise方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<number> | 以Promise形式返回共享网络总数据量，单位：KB。 |

**示例：**

```js
sharing.getStatsTotalBytes().then(data => {
    console.log(JSON.stringify(data));
}).catch(error => {
    console.log(JSON.stringify(error));
});
```

## sharing.getSharingIfaces

getSharingIfaces(state: SharingIfaceState, callback: AsyncCallback\<Array\<string>>): void

获取指定状态的网卡名称列表，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| state    | [SharingIfaceState](#sharingifacestate) | 是   | 网络共享状态。 |
| callback | AsyncCallback\<Array\<string>> | 是   | 回调函数，返回指定状态的网卡名称列表。 |

**示例：**

```js
import SharingIfaceState from '@ohos.net.sharing'
sharing.getSharingIfaces(SharingIfaceState.SHARING_NIC_CAN_SERVER, (error, data) => {
    console.log(JSON.stringify(error));
    console.log(JSON.stringify(data));
});
```

## sharing.getSharingIfaces

getSharingIfaces(state: SharingIfaceState): Promise\<Array\<string>>

获取指定状态的网卡名称列表，使用Promise方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| state    | [SharingIfaceState](#sharingifacestate) | 是   | 网络共享状态。 |

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<Array\<string>> | 以Promise形式返回指定状态网卡名称列表。 |

**示例：**

```js
import SharingIfaceState from '@ohos.net.sharing'
sharing.getSharingIfaces(SharingIfaceState.SHARING_NIC_CAN_SERVER).then(data => {
    console.log(JSON.stringify(data));
}).catch(error => {
    console.log(JSON.stringify(error));
});
```

## sharing.getSharingState

getSharingState(type: SharingIfaceType, callback: AsyncCallback\<SharingIfaceState>): void

获取指定类型网络共享状态，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| type | [SharingIfaceType](#sharingifacetype) | 是   | 共享类型，0：Wi-Fi 1：USB 2：BLUETOOTH。 |
| callback | AsyncCallback\<[SharingIfaceState](#sharingifacestate)> | 是   | 回调函数，返回指定类型网络共享状态。 |

**示例：**

```js
import SharingIfaceState from '@ohos.net.sharing'
sharing.getSharingState(SharingIfaceType.SHARING_WIFI, (error, data) => {
    console.log(JSON.stringify(error));
    console.log(JSON.stringify(data));
});
```

## sharing.getSharingState

getSharingState(type: SharingIfaceType): Promise\<SharingIfaceState>

获取指定类型网络共享状态，使用Promise方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| type | [SharingIfaceType](#sharingifacetype) | 是   | 共享类型，0：Wi-Fi 1：USB 2：BLUETOOTH。 |

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<[SharingIfaceState](#sharingifacestate)> | 以Promise形式返回定类型网络共共享状态。 |

**示例：**

```js
import SharingIfaceType from '@ohos.net.sharing'
sharing.getSharingIfaces(SharingIfaceType.SHARING_WIFI).then(data => {
    console.log(JSON.stringify(data));
}).catch(error => {
    console.log(JSON.stringify(error));
});
```

## sharing.getSharableRegexes

getSharableRegexes(type: SharingIfaceType, callback: AsyncCallback\<Array\<string>>): void

获取指定类型网卡名称正则表达式列表，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| type | [SharingIfaceType](#sharingifacetype) | 是   | 共享类型，0：Wi-Fi 1：USB 2：BLUETOOTH。 |
| callback | AsyncCallback\<Array\<string>> | 是   | 回调函数，返回指定类型网卡名称正则表达式列表。 |

**示例：**

```js
import SharingIfaceState from '@ohos.net.sharing'
sharing.getSharingState(SharingIfaceType.SHARING_WIFI, (error, data) => {
    console.log(JSON.stringify(error));
    console.log(JSON.stringify(data));
});
```

## sharing.getSharableRegexes

getSharableRegexes(type: SharingIfaceType): Promise\<Array\<string>>

获取指定类型网卡名称正则表达式列表，使用Promise方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| type | [SharingIfaceType](#sharingifacetype) | 是   | 共享类型，0：Wi-Fi 1：USB 2：BLUETOOTH。 |

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<Array\<string>> | 以Promise形式返回正则表达式列表。 |

**示例：**

```js
import SharingIfaceType from '@ohos.net.sharing'
sharing.getSharableRegexes(SharingIfaceType.SHARING_WIFI).then(data => {
    console.log(JSON.stringify(data));
}).catch(error => {
    console.log(JSON.stringify(error));
});
```

## on('sharingStateChange')

on(type: 'sharingStateChange', callback: Callback\<boolean>): void

注册网络共享状态变化事件，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| type | string | 是   | 事件名称。 |
| callback | AsyncCallback\<boolean> | 是   | 回调函数，返回网络共享状态。 |

**示例：**

```js
sharing.on('sharingStateChange', (error, data) => {
    console.log(JSON.stringify(error));
    console.log(JSON.stringify(data));
});
```

## off('sharingStateChange')

off(type: 'sharingStateChange', callback?: Callback\<boolean>): void

注销网络共享状态变化事件，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| type | string | 是   | 事件名称。 |
| callback | AsyncCallback\<boolean> | 否   | 回调函数，返回网络共享状态。 |

**示例：**

```js
sharing.off('sharingStateChange', (error, data) => {
    console.log(JSON.stringify(error));
    console.log(JSON.stringify(data));
});
```

## on('interfaceSharingStateChange')

on(type: 'interfaceSharingStateChange', callback: Callback\<{ type: SharingIfaceType, iface: string, state: SharingIfaceState }>): void

注册网卡网络共享状态变化事件，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| type | string | 是   | 事件名称。 |
| callback | AsyncCallback\<{ type: [SharingIfaceType](#sharingifacetype), iface: string, state: SharingIfaceState(#sharingifacestate) }> | 是   | 回调函数,指定网卡共享状态变化时调用。 |

**示例：**

```js
sharing.on('interfaceSharingStateChange', (error, data) => {
    console.log(JSON.stringify(error));
    console.log(JSON.stringify(data));
});
```

## off('interfaceSharingStateChange')

off(type: 'interfaceSharingStateChange', callback?: Callback\<{ type: SharingIfaceType, iface: string, state: SharingIfaceState }>): void

注销网卡网络共享状态变化事件，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| type | string | 是   | 事件名称。 |
| callback | AsyncCallback\<{ type: [SharingIfaceType](#sharingifacetype), iface: string, state: SharingIfaceState(#sharingifacestate) }> | 否   | 回调函数，注销指定网卡共享状态变化通知。 |

**示例：**

```js
sharing.off('interfaceSharingStateChange', (error, data) => {
    console.log(JSON.stringify(error));
    console.log(JSON.stringify(data));
});
```

## on('sharingUpstreamChange')

on(type: 'sharingUpstreamChange', callback: Callback\<NetHandle>): void

注册上行网络变化事件，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| type | string | 是   | 事件名称。 |
| callback | AsyncCallback\<NetHandle> | 是   | 回调函数，上行网络变化时调用。 |

**示例：**

```js
sharing.on('sharingUpstreamChange', (error, data) => {
    console.log(JSON.stringify(error));
    console.log(JSON.stringify(data));
});
```

## off('sharingUpstreamChange')

off(type: 'sharingUpstreamChange', callback?: Callback\<NetHandle>): void

注销上行网络变化事件，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| type | string | 是   | 事件名称。 |
| callback | AsyncCallback\<NetHandle> | 否   | 回调函数，注销上行网络变化事件。 |

**示例：**

```js
sharing.off('sharingUpstreamChange', (error, data) => {
    console.log(JSON.stringify(error));
    console.log(JSON.stringify(data));
});
```

## SharingIfaceState

网络共享状态。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

| 名称                  | 值   | 说明                   |
| ------------------------ | ---- | ---------------------- |
| SHARING_NIC_SERVING    | 1 | 正在网络共享。 |
| SHARING_NIC_CAN_SERVER | 2 | 可提供网络共享。 |
| SHARING_NIC_ERROR      | 3 | 网络共享错误。 |

## SharingIfaceType

网络共享类型（暂不支持USB共享）。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

| 名称                  | 值   | 说明                   |
| ------------------------ | ---- | ---------------------- |
| SHARING_WIFI       | 0 | 网络共享类型Wi-Fi。 |
| SHARING_USB     | 1 | 网络共享类型USB。 |
| SHARING_BLUETOOTH    | 2 | 网络共享类型蓝牙。 |
