# @ohos.net.statistics (流量管理)（系统接口）

流量管理模块，支持基于网卡/UID 的实时流量统计和历史流量统计查询能力。

> **说明：**
> 本模块首批接口从 API version 10 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.net.statistics (流量管理)](js-apis-net-statistics.md)。

## 导入模块

```js
import { statistics } from '@kit.NetworkKit';
```


## statistics.on('netStatsChange')<sup>10+</sup>

on(type: 'netStatsChange', callback: Callback\<NetStatsChangeInfo\>): void

订阅流量改变事件通知。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.GET_NETWORK_STATS

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                        | 必填 | 说明                                                               |
| -------- | ------------------------------------------- | ---- | ----------------------------------------------------------------- |
| type     | string                                      | 是   | 订阅事件，固定为'netStatsChange'。                                 |
| callback | Callback\<[NetStatsChangeInfo](#netstatschangeinfo11)\> | 是   | 当流量有改变时触发回调函数。 |

**错误码：**

以下错误码的详细介绍参见[statistics 错误码](errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```js
import { statistics } from '@kit.NetworkKit';

class IFace {
  iface: string = ""
  uid?: number = 0
}
statistics.on('netStatsChange', (data: IFace) => {
  console.log('on netStatsChange' + JSON.stringify(data));
});
```

## statistics.off('netStatsChange')<sup>10+</sup>

off(type: 'netStatsChange', callback?: Callback\<NetStatsChangeInfo>): void

取消订阅流量改变事件通知。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.GET_NETWORK_STATS

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                        | 必填 | 说明                                                               |
| -------- | ------------------------------------------- | ---- | ----------------------------------------------------------------- |
| type     | string                                      | 是   | 注销订阅事件，固定为'netStatsChange'。                             |
| callback | Callback\<[NetStatsChangeInfo](#netstatschangeinfo11)\> | 否   | 当流量有改变时触发回调函数。 |

**错误码：**

以下错误码的详细介绍参见[statistics 错误码](errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```js
import { statistics } from '@kit.NetworkKit';

class IFace {
  iface: string = ""
  uid?: number = 0
}
let callback: (data: IFace) => void = (data: IFace) => {
    console.log("on netStatsChange, iFace:" + data.iface + " uid: " + data.uid);
}
statistics.on('netStatsChange', callback);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
statistics.off('netStatsChange', callback);
statistics.off('netStatsChange');
```

## statistics.getTrafficStatsByIface<sup>10+</sup>

getTrafficStatsByIface(ifaceInfo: IfaceInfo, callback: AsyncCallback\<NetStatsInfo>): void

获取指定网卡历史流量信息，使用 callback 方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.GET_NETWORK_STATS

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名    | 类型                                            | 必填 | 说明                                                                                    |
| --------- | ----------------------------------------------- | ---- | -------------------------------------------------------------------------------------- |
| ifaceInfo | [IfaceInfo](#ifaceinfo10)                       | 是   | 指定查询的网卡信息，参见[IfaceInfo](#ifaceinfo10)。                                     |
| callback  | AsyncCallback\<[NetStatsInfo](#netstatsinfo10)> | 是   | 回调函数。成功时 statsInfo 返回包含网卡历史流量信息，error 为 undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍参见[statistics 错误码](errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103017   | Failed to read the database.                 |

**示例：**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { statistics } from '@kit.NetworkKit';

let iFaceInfo: statistics.IfaceInfo | null = null;
if (iFaceInfo) {
  statistics.getTrafficStatsByIface(iFaceInfo as statistics.IfaceInfo, (error: BusinessError, statsInfo: statistics.NetStatsInfo) => {
    console.error(JSON.stringify(error));
    console.log(
      "getTrafficStatsByIface bytes of received = " +
      JSON.stringify(statsInfo.rxBytes)
    );
    console.log(
      "getTrafficStatsByIface bytes of sent = " +
      JSON.stringify(statsInfo.txBytes)
    );
    console.log(
      "getTrafficStatsByIface packets of received = " +
      JSON.stringify(statsInfo.rxPackets)
    );
    console.log(
      "getTrafficStatsByIface packets of sent = " +
      JSON.stringify(statsInfo.txPackets)
    );
  });
}
```

## statistics.getTrafficStatsByIface<sup>10+</sup>

getTrafficStatsByIface(ifaceInfo: IfaceInfo): Promise\<NetStatsInfo>

获取指定网卡历史流量信息，使用 Promise 方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.GET_NETWORK_STATS

**系统能力**：SystemCapability.Communication.NetManager.Core

| 参数名    | 类型                      | 必填 | 说明                                                |
| --------- | ------------------------- | ---- | --------------------------------------------------- |
| ifaceInfo | [IfaceInfo](#ifaceinfo10) | 是   | 指定查询的网卡信息，参见[IfaceInfo](#ifaceinfo10)。 |

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| Promise\<[NetStatsInfo](#netstatsinfo10)> | 以 Promise 形式返回获取结果,返回网卡历史流量信息。 |

**错误码：**

以下错误码的详细介绍参见[statistics 错误码](errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103017   | Failed to read the database.                 |

**示例：**

```js
import { statistics } from '@kit.NetworkKit';

let iFaceInfo: statistics.IfaceInfo | null = null;
if (iFaceInfo) {
  statistics.getTrafficStatsByIface(iFaceInfo as statistics.IfaceInfo).then((statsInfo: statistics.NetStatsInfo) => {
    console.log(
      "getTrafficStatsByIface bytes of received = " +
      JSON.stringify(statsInfo.rxBytes)
    );
    console.log(
      "getTrafficStatsByIface bytes of sent = " +
      JSON.stringify(statsInfo.txBytes)
    );
    console.log(
      "getTrafficStatsByIface packets of received = " +
      JSON.stringify(statsInfo.rxPackets)
    );
    console.log(
      "getTrafficStatsByIface packets of sent = " +
      JSON.stringify(statsInfo.txPackets)
    );
  });
}
```

## statistics.getTrafficStatsByUid<sup>10+</sup>

getTrafficStatsByUid(uidInfo: UidInfo, callback: AsyncCallback\<NetStatsInfo>): void

获取指定应用历史流量信息，使用 callback 方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.GET_NETWORK_STATS

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                            | 必填 | 说明                                                                                    |
| -------- | ----------------------------------------------- | ---- | -------------------------------------------------------------------------------------- |
| uidInfo  | [UidInfo](#uidinfo10)                           | 是   | 指定查询的应用信息，参见[UidInfo](#uidinfo10)。                                         |
| callback | AsyncCallback\<[NetStatsInfo](#netstatsinfo10)> | 是   | 回调函数。成功时 statsInfo 返回包含应用历史流量信息，error 为 undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍参见[statistics 错误码](errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103017   | Failed to read the database.                 |

**示例：**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { statistics } from '@kit.NetworkKit';

let uidInfo: statistics.UidInfo = {
  uid: 20010037,
  ifaceInfo: {
    iface: '',
    startTime: 1,
    endTime: 3,
  }
}

statistics.getTrafficStatsByUid(
  uidInfo,
  (error: BusinessError, statsInfo: statistics.NetStatsInfo) => {
    console.error(JSON.stringify(error));
    console.log(
      "getTrafficStatsByUid bytes of received = " +
      JSON.stringify(statsInfo.rxBytes)
    );
    console.log(
      "getTrafficStatsByUid bytes of sent = " +
      JSON.stringify(statsInfo.txBytes)
    );
    console.log(
      "getTrafficStatsByUid packets of received = " +
      JSON.stringify(statsInfo.rxPackets)
    );
    console.log(
      "getTrafficStatsByUid packets of sent = " +
      JSON.stringify(statsInfo.txPackets)
    );
  }
);
```

## statistics.getTrafficStatsByUid<sup>10+</sup>

getTrafficStatsByUid(uidInfo: UidInfo): Promise\<NetStatsInfo>

获取指定应用历史流量信息，使用 Promise 方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.GET_NETWORK_STATS

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名  | 类型                  | 必填 | 说明                                            |
| ------- | --------------------- | ---- | ----------------------------------------------- |
| uidInfo | [UidInfo](#uidinfo10) | 是   | 指定查询的应用信息，参见[UidInfo](#uidinfo10)。 |

**返回值：**

| 类型                                      | 说明                                               |
| ----------------------------------------- | -------------------------------------------------- |
| Promise\<[NetStatsInfo](#netstatsinfo10)> | 以 Promise 形式返回获取结果,返回应用历史流量信息。 |

**错误码：**

以下错误码的详细介绍参见[statistics 错误码](errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103017   | Failed to read the database.                 |

**示例：**

```js
import statistics from '@ohos.net.statistics'

let uidInfo: statistics.UidInfo = {
  uid: 20010037,
  ifaceInfo: {
    iface: '',
    startTime: 1,
    endTime: 3,
  }
}

statistics.getTrafficStatsByUid(uidInfo).then((statsInfo: statistics.NetStatsInfo) => {
  console.log("getTrafficStatsByUid bytes of received = " + JSON.stringify(statsInfo.rxBytes));
  console.log("getTrafficStatsByUid bytes of sent = " + JSON.stringify(statsInfo.txBytes));
  console.log("getTrafficStatsByUid packets of received = " + JSON.stringify(statsInfo.rxPackets));
  console.log("getTrafficStatsByUid packets of sent = " + JSON.stringify(statsInfo.txPackets));
})
```

## statistics.getTrafficStatsByNetwork<sup>12+</sup>

getTrafficStatsByNetwork(networkInfo: NetworkInfo): Promise\<UidNetStatsInfo>

获取指定时间段内所有应用在指定网络中的流量使用详情，使用 Promise 方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.GET_NETWORK_STATS

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名         | 类型                            | 必填 | 说明                                         |
|-------------|-------------------------------|----|--------------------------------------------|
| networkInfo | [NetworkInfo](#networkinfo12) | 是  | 指定查询的网络信息，参见[NetworkInfo](#networkinfo12)。 |

**返回值：**

| 类型                                              | 说明                               |
|-------------------------------------------------|----------------------------------|
| Promise\<[UidNetStatsInfo](#uidnetstatsinfo12)> | 以 Promise 形式返回获取结果。返回所有应用历史流量信息。 |

**错误码：**

以下错误码的详细介绍参见[statistics 错误码](errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103017   | Failed to read the database.                 |

**示例**

```js
import { connection, statistics } from '@kit.NetworkKit';

let networkInfo: statistics.NetworkInfo = {
  type: connection.NetBearType.BEARER_CELLULAR,
  startTime: Math.floor(Date.now() / 1000) - 86400 * 7, 
  endTime: Math.floor(Date.now() / 1000) + 5,
  simId: 1,
}

statistics.getTrafficStatsByNetwork(networkInfo).then((statsInfo: statistics.UidNetStatsInfo) => {
  let rank: Map<string, object> = new Map<string, object>(Object.entries(statsInfo));
  rank.forEach((value: object, key: string) => {
    console.info("getTrafficStatsByNetwork key=" + key + ", value=" + JSON.stringify(value));
  })
})
```

## statistics.getTrafficStatsByUidNetwork<sup>12+</sup>

getTrafficStatsByUidNetwork(uid: number, networkInfo: NetworkInfo): Promise\<NetStatsInfoSequence>

获取指定时间段内，应用在指定网络中的流量使用详情，使用 Promise 方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.GET_NETWORK_STATS

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名         | 类型                            | 必填 | 说明                                         |
|-------------|-------------------------------|----|--------------------------------------------|
| uid         | number                        | 是  | 指定查询的应用 UID。                               |
| networkInfo | [NetworkInfo](#networkinfo12) | 是  | 指定查询的网络信息，参见[NetworkInfo](#networkinfo12)。 |

**返回值：**

| 类型                                                        | 说明                               |
|-----------------------------------------------------------|----------------------------------|
| Promise\<[NetStatsInfoSequence](#netstatsinfosequence12)> | 以 Promise 形式返回获取结果。返回应用历史流量统计信息。 |

**错误码：**

以下错误码的详细介绍参见[statistics 错误码](errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103017   | Failed to read the database.                 |

**示例**

```js
import { connection, statistics } from '@kit.NetworkKit';

let uid: number = 20020147;
let networkInfo: statistics.NetworkInfo = {
  type: connection.NetBearType.BEARER_CELLULAR,
  startTime: Math.floor(Date.now() / 1000) - 86400 * 7, 
  endTime: Math.floor(Date.now() / 1000) + 5,
  simId: 1,
}

statistics.getTrafficStatsByUidNetwork(uid, networkInfo).then((statsInfoSequence: statistics.NetStatsInfoSequence) => {
  for (let i = 0; i < statsInfoSequence.length; i--) {
    console.info("getTrafficStatsByUidNetwork item:" + JSON.stringify(statsInfoSequence[i]));
  }
})
```

## IfaceInfo<sup>10+</sup>

查询网卡历史流量参数信息。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称      | 类型   | 必填 | 说明                              |
| --------- | ------ | ---- | --------------------------------- |
| iface     | string | 是   | 查询的网卡名。                    |
| startTime | number | 是   | 查询的开始时间(时间戳;单位：秒)。 |
| endTime   | number | 是   | 查询的结束时间(时间戳;单位：秒)。 |

## UidInfo<sup>10+</sup>

查询应用历史流量参数信息。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称      | 类型                                  | 必填 | 说明                        |
| --------- | ------------------------------------- | ---- | -------------------------- |
| ifaceInfo | IfaceInfo\<[IfaceInfo](#ifaceinfo10)> | 是   | 需查询的网卡和时间参数信息。 |
| uid       | number                                | 是   | 需查询的应用 uid。          |

## NetStatsInfo<sup>10+</sup>

获取的历史流量信息。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称      | 类型   | 必填 | 说明                      |
| --------- | ------ | ---- | ------------------------ |
| rxBytes   | number | 是   | 流量下行数据(单位:字节)。 |
| txBytes   | number | 是   | 流量上行数据(单位:字节)。 |
| rxPackets | number | 是   | 流量下行包个数。          |
| txPackets | number | 是   | 流量上行包个数。          |

## NetStatsChangeInfo<sup>11+</sup>

监听和管理网络接口的状态和使用情况。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称      | 类型   | 必填 | 说明       |
| --------- | ------ | ---- | --------- |
| iface     | string | 是   | 网卡名称。 |
| uid       | number | 否   | 应用UID。  |

## NetworkInfo<sup>12+</sup>

网络信息。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称        | 类型                                                   | 必填 | 说明           |
|-----------|------------------------------------------------------|----|--------------|
| type      | [NetBearType](js-apis-net-connection.md#netbeartype) | 是  | 网络类型。        |
| startTime | number                                               | 是  | 开始时间戳(单位:秒)。 |
| endTime   | number                                               | 是  | 结束时间戳(单位:秒)。 |
| simId     | number                                               | 否  | SIM 卡 ID。    |

## UidNetStatsInfo<sup>12+</sup>

获取的所有应用历史流量信息。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称        | 类型                                            | 必填 | 说明           |
|-----------|-----------------------------------------------|----|--------------|
| undefined | [uid:number]: [NetStatsInfo](#netstatsinfo10) | 是  | 所有应用的历史流量信息。 |

## NetStatsInfoSequence<sup>12+</sup>

获取的应用历史流量信息。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称        | 类型                              | 必填 | 说明           |
|-----------|---------------------------------|----|--------------|
| startTime | number                          | 是  | 开始时间戳(单位:秒)。 |
| endTime   | number                          | 是  | 结束时间戳(单位:秒)。 |
| info      | [NetStatsInfo](#netstatsinfo10) | 是  | 获取的应用历史流量信息。 |