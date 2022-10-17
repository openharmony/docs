# 网络流量管理

网络流量管理提供对用户上网过程中产生的流量进行统计，支持用户按网络接口（蜂窝、Wi-Fi）和按应用查询网络流量使用情况的功能

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import statistics from '@ohos.net.statistics'
```

## statistics.getIfaceRxBytes

getIfaceRxBytes(nic: string, callback: AsyncCallback\<number>): void

获取指定网卡的接收数据量，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| nic | string | 是   | 网卡名 |
| callback | AsyncCallback\<number> | 是   | 回调函数，number代表数据量，单位：bytes。 |

**示例：**

```js
statistics.getIfaceRxBytes(this.nic, (err, data) => {
    this.callBack(err, data);
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(data))
})
```

## statistics.getIfaceRxBytes

getIfaceRxBytes(nic: string): Promise\<number>;

获取指定网卡的接收数据量，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| nic | string | 是   | 网卡名 |

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<number> | 以Promise形式返回指定网卡的接收数据量，单位：bytes。 |

**示例：**

```js
statistics.getIfaceRxBytes(this.nic).then((err, data) {
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})
```

## statistics.getIfaceTxBytes

getIfaceTxBytes(nic: string, callback: AsyncCallback\<number>): void

获取指定网卡的发送数据量，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| nic | string | 是   | 网卡名 |
| callback | AsyncCallback\<number> | 是   | 回调函数，number代表数据量，单位：bytes。 |

**示例：**

```js
statistics.getIfaceTxBytes(this.nic, (err, data) => {
    this.callBack(err, data);
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(data))
})
```

## statistics.getIfaceTxBytes

getIfaceTxBytes(nic: string): Promise\<number>;

获取指定网卡的发送数据量，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| nic | string | 是   | 网卡名 |

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<number> | 以Promise形式返回指定网卡的发送数据量，单位：bytes。 |

**示例：**

```js
statistics.getIfaceTxBytes(this.nic).then((err, data) {
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})
```

## statistics.getCellularRxBytes

getCellularRxBytes(callback: AsyncCallback\<number>): void;

获取蜂窝网的接收数据量，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<number> | 是   | 回调函数，number代表数据量，单位：bytes。 |

**示例：**

```js
statistics.getCellularRxBytes((err, data) => {
    this.callBack(err, data);
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(data))
})
```

## statistics.getCellularRxBytes

getCellularRxBytes(): Promise\<number>;

获取蜂窝网的接收数据量，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<number> | 以Promise形式返回蜂窝网的接收数据量，单位：bytes。 |

**示例：**

```js
statistics.getCellularRxBytes().then((err, data) {
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})
```

## statistics.getCellularTxBytes

getCellularTxBytes(callback: AsyncCallback\<number>): void;

获取蜂窝网的发送数据量，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<number> | 是   | 回调函数，number代表数据量，单位：bytes。 |

**示例：**

```js
statistics.getCellularTxBytes((err, data) => {
    this.callBack(err, data);
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(data))
})
```

## statistics.getCellularTxBytes

getCellularTxBytes(): Promise\<number>;

获取蜂窝网的发送数据量，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<number> | 以Promise形式返回蜂窝网的发送数据量，单位：bytes。 |

**示例：**

```js
statistics.getCellularTxBytes().then((err, data) {
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})
```

## statistics.getAllRxBytes

getAllRxBytes(callback: AsyncCallback\<number>): void;

获取所有网卡的接收数据量，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<number> | 是   | 回调函数，number代表数据量，单位：bytes。 |

**示例：**

```js
statistics.getAllRxBytes(err, data) => {
    this.callBack(err, data);
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(data))
})
```

## statistics.getAllRxBytes

getAllRxBytes(): Promise\<number>;

获取所有网卡的接收数据量，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<number> | 以Promise形式返回所有网卡的接收数据量，单位：bytes。 |

**示例：**

```js
statistics.getAllRxBytes().then((err, data) {
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})
```

## statistics.getAllTxBytes

getAllTxBytes(callback: AsyncCallback\<number>): void;

获取所有网卡的发送数据，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<number> | 是   | 回调函数，number代表数据量，单位：bytes。 |

**示例：**

```js
statistics.getAllTxBytes((err, data) => {
    this.callBack(err, data);
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(data))
})
```

## statistics.getAllTxBytes

getAllTxBytes(): Promise\<number>;

获取所有网卡的发送数据量，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<number> | 以Promise形式返回所有网卡的发送数据量，单位：bytes。 |

**示例：**

```js
statistics.getAllTxBytes().then((err, data) {
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})
```

## statistics.getUidRxBytes

getUidRxBytes(uid: number, callback: AsyncCallback\<number>): void;

获取指定应用的接收数据量，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| uid | number | 是   | 应用ID |
| callback | AsyncCallback\<number> | 是   | 回调函数，number代表数据量，单位：bytes。 |

**示例：**

```js
statistics.getUidRxBytes(this.uid, (err, data) => {
    this.callBack(err, data);
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(data))
})
```

## statistics.getUidRxBytes

getUidRxBytes(uid: number): Promise\<number>;

获取指定应用的接收数据量，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| uid | number | 是   | 应用ID |

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<number> | 以Promise形式返回指定网卡的接收数据量，单位：bytes。 |

**示例：**

```js
statistics.getUidRxBytes(this.uid).then((err, data) {
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})
```

## statistics.getUidTxBytes

getUidTxBytes(uid: number, callback: AsyncCallback\<number>): void;

获取指定应用的发送数据量，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| uid | number | 是   | 应用ID |
| callback | AsyncCallback\<number> | 是   | 回调函数，number代表数据量，单位：bytes。 |

**示例：**

```js
statistics.getUidTxBytes(this.uid, (err, data) => {
    this.callBack(err, data);
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(data))
})
```

## statistics.getUidTxBytes

getUidTxBytes(uid: number): Promise\<number>;

获取指定应用的发送数据量，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| uid | number | 是   | 应用ID |

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<number> | 以Promise形式返回指定网卡的发送数据量，单位：bytes。 |

**示例：**

```js
statistics.getUidTxBytes(this.uid).then((err, data) {
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})
```
