# @ohos.net.statistics (Traffic Management) (System API)

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->

The **statistics** module provides APIs to query real-time or historical traffic statistics by the specified network interface card (NIC) or user ID (UID).

> **NOTE**
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.net.statistics (Traffic Management)](js-apis-net-statistics.md).

## Modules to Import

```js
import { statistics } from '@kit.NetworkKit';
```


## statistics.on('netStatsChange')<sup>10+</sup>

on(type: 'netStatsChange', callback: Callback\<NetStatsChangeInfo\>): void

Subscribes to traffic change events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_NETWORK_STATS

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                       | Mandatory| Description                                                              |
| -------- | ------------------------------------------- | ---- | ----------------------------------------------------------------- |
| type     | string                                      | Yes  | Event type. This field has a fixed value of **netStatsChange**.                                |
| callback | Callback\<[NetStatsChangeInfo](#netstatschangeinfo11)\> | Yes  | Callback invoked when the traffic changes.|

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

```js
import { statistics } from '@kit.NetworkKit';

class IFace {
  iface: string = ""
  uid?: number = 0
}
statistics.on('netStatsChange', (data: IFace) => {
  console.info('on netStatsChange' + JSON.stringify(data));
});
```

## statistics.off('netStatsChange')<sup>10+</sup>

off(type: 'netStatsChange', callback?: Callback\<NetStatsChangeInfo>): void

Unsubscribes from traffic change events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_NETWORK_STATS

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                       | Mandatory| Description                                                              |
| -------- | ------------------------------------------- | ---- | ----------------------------------------------------------------- |
| type     | string                                      | Yes  | Event type. This field has a fixed value of **netStatsChange**.                            |
| callback | Callback\<[NetStatsChangeInfo](#netstatschangeinfo11)\> | No  | Callback invoked when the traffic changes.|

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

```js
import { statistics } from '@kit.NetworkKit';

class IFace {
  iface: string = ""
  uid?: number = 0
}
let callback: (data: IFace) => void = (data: IFace) => {
    console.info("on netStatsChange, iFace:" + data.iface + " uid: " + data.uid);
}
statistics.on('netStatsChange', callback);
// You can pass the callback of the on method to cancel listening for a certain type of callback. If you do not pass the callback, you will cancel listening for all callbacks.
statistics.off('netStatsChange', callback);
statistics.off('netStatsChange');
```

## statistics.getTrafficStatsByIface<sup>10+</sup>

getTrafficStatsByIface(ifaceInfo: IfaceInfo, callback: AsyncCallback\<NetStatsInfo>): void

Obtains the historical traffic statistics of the specified NIC. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_NETWORK_STATS

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name   | Type                                           | Mandatory| Description                                                                                   |
| --------- | ----------------------------------------------- | ---- | -------------------------------------------------------------------------------------- |
| ifaceInfo | [IfaceInfo](#ifaceinfo10)                       | Yes  | NIC information. For details, see [IfaceInfo](#ifaceinfo10).                                    |
| callback  | AsyncCallback\<[NetStatsInfo](#netstatsinfo10)> | Yes  | Callback used to return the result. If the operation is successful, **error** is **undefined** and **statsInfo** is the historical traffic statistics of the NIC. Otherwise, **error** is an error object.|

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103017   | Failed to read the database.                 |

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { statistics } from '@kit.NetworkKit';

let iFaceInfo: statistics.IfaceInfo | null = null;
if (iFaceInfo) {
  statistics.getTrafficStatsByIface(iFaceInfo as statistics.IfaceInfo, (error: BusinessError, statsInfo: statistics.NetStatsInfo) => {
    console.error(JSON.stringify(error));
    console.info(
      "getTrafficStatsByIface bytes of received = " +
      JSON.stringify(statsInfo.rxBytes)
    );
    console.info(
      "getTrafficStatsByIface bytes of sent = " +
      JSON.stringify(statsInfo.txBytes)
    );
    console.info(
      "getTrafficStatsByIface packets of received = " +
      JSON.stringify(statsInfo.rxPackets)
    );
    console.info(
      "getTrafficStatsByIface packets of sent = " +
      JSON.stringify(statsInfo.txPackets)
    );
  });
}
```

## statistics.getTrafficStatsByIface<sup>10+</sup>

getTrafficStatsByIface(ifaceInfo: IfaceInfo): Promise\<NetStatsInfo>

Obtains the historical traffic statistics of the specified NIC. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_NETWORK_STATS

**System capability**: SystemCapability.Communication.NetManager.Core

| Name   | Type                     | Mandatory| Description                                               |
| --------- | ------------------------- | ---- | --------------------------------------------------- |
| ifaceInfo | [IfaceInfo](#ifaceinfo10) | Yes  | NIC information. For details, see [IfaceInfo](#ifaceinfo10).|

**Return value**
| Type| Description|
| -------- | -------- |
| Promise\<[NetStatsInfo](#netstatsinfo10)> | Promise used to return the result, which is the historical traffic statistics of the specified NIC.|

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103017   | Failed to read the database.                 |

**Example**

```js
import { statistics } from '@kit.NetworkKit';

let iFaceInfo: statistics.IfaceInfo | null = null;
if (iFaceInfo) {
  statistics.getTrafficStatsByIface(iFaceInfo as statistics.IfaceInfo).then((statsInfo: statistics.NetStatsInfo) => {
    console.info(
      "getTrafficStatsByIface bytes of received = " +
      JSON.stringify(statsInfo.rxBytes)
    );
    console.info(
      "getTrafficStatsByIface bytes of sent = " +
      JSON.stringify(statsInfo.txBytes)
    );
    console.info(
      "getTrafficStatsByIface packets of received = " +
      JSON.stringify(statsInfo.rxPackets)
    );
    console.info(
      "getTrafficStatsByIface packets of sent = " +
      JSON.stringify(statsInfo.txPackets)
    );
  });
}
```

## statistics.getTrafficStatsByUid<sup>10+</sup>

getTrafficStatsByUid(uidInfo: UidInfo, callback: AsyncCallback\<NetStatsInfo>): void

Obtains the historical traffic statistics of the specified application. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_NETWORK_STATS

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                           | Mandatory| Description                                                                                   |
| -------- | ----------------------------------------------- | ---- | -------------------------------------------------------------------------------------- |
| uidInfo  | [UidInfo](#uidinfo10)                           | Yes  | Application information. For details, see [UidInfo](#uidinfo10).                                        |
| callback | AsyncCallback\<[NetStatsInfo](#netstatsinfo10)> | Yes  | Callback used to return the result. If the operation is successful, **error** is **undefined** and **statsInfo** is the historical traffic statistics of the application. Otherwise, **error** is an error object.|

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103017   | Failed to read the database.                 |

**Example**

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
    console.info(
      "getTrafficStatsByUid bytes of received = " +
      JSON.stringify(statsInfo.rxBytes)
    );
    console.info(
      "getTrafficStatsByUid bytes of sent = " +
      JSON.stringify(statsInfo.txBytes)
    );
    console.info(
      "getTrafficStatsByUid packets of received = " +
      JSON.stringify(statsInfo.rxPackets)
    );
    console.info(
      "getTrafficStatsByUid packets of sent = " +
      JSON.stringify(statsInfo.txPackets)
    );
  }
);
```

## statistics.getTrafficStatsByUid<sup>10+</sup>

getTrafficStatsByUid(uidInfo: UidInfo): Promise\<NetStatsInfo>

Obtains the historical traffic statistics of the specified application. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_NETWORK_STATS

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name | Type                 | Mandatory| Description                                           |
| ------- | --------------------- | ---- | ----------------------------------------------- |
| uidInfo | [UidInfo](#uidinfo10) | Yes  | Application information. For details, see [UidInfo](#uidinfo10).|

**Return value**

| Type                                     | Description                                              |
| ----------------------------------------- | -------------------------------------------------- |
| Promise\<[NetStatsInfo](#netstatsinfo10)> | Promise used to return the result, which is the historical traffic statistics of the specified NIC.|

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103017   | Failed to read the database.                 |

**Example**

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
  console.info("getTrafficStatsByUid bytes of received = " + JSON.stringify(statsInfo.rxBytes));
  console.info("getTrafficStatsByUid bytes of sent = " + JSON.stringify(statsInfo.txBytes));
  console.info("getTrafficStatsByUid packets of received = " + JSON.stringify(statsInfo.rxPackets));
  console.info("getTrafficStatsByUid packets of sent = " + JSON.stringify(statsInfo.txPackets));
})
```

## statistics.getTrafficStatsByNetwork<sup>12+</sup>

getTrafficStatsByNetwork(networkInfo: NetworkInfo): Promise\<UidNetStatsInfo>

Obtains the traffic statistics of all applications on the specified network within the specified period. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_NETWORK_STATS

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name        | Type                           | Mandatory| Description                                        |
|-------------|-------------------------------|----|--------------------------------------------|
| networkInfo | [NetworkInfo](#networkinfo12) | Yes | Network information. For details, see [NetworkInfo](#networkinfo12).|

**Return value**

| Type                                             | Description                              |
|-------------------------------------------------|----------------------------------|
| Promise\<[UidNetStatsInfo](#uidnetstatsinfo12)> | Promise used to return the result, which is the historical traffic statistics of all applications.|

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103017   | Failed to read the database.                 |

**Example**

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

Obtains the traffic statistics of the specified application on the specified network within the specified period. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_NETWORK_STATS

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name        | Type                           | Mandatory| Description                                        |
|-------------|-------------------------------|----|--------------------------------------------|
| uid         | number                        | Yes | Application UID.                              |
| networkInfo | [NetworkInfo](#networkinfo12) | Yes | Network information. For details, see [NetworkInfo](#networkinfo12).|

**Return value**

| Type                                                       | Description                              |
|-----------------------------------------------------------|----------------------------------|
| Promise\<[NetStatsInfoSequence](#netstatsinfosequence12)> | Promise used to return the result, which is the historical traffic statistics of the application.|

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103017   | Failed to read the database.                 |

**Example**

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

Defines the parameters for querying historical traffic of an NIC.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name     | Type  | Read-Only|Optional|Description                             |
| --------- | ------ | ---- |---| --------------------------------- |
| iface     | string | No  |No|NIC name.                   |
| startTime | number | No  |No|Start time of the query, which is a timestamp in seconds.|
| endTime   | number | No | No|End time of the query, which is a timestamp in seconds.|

## UidInfo<sup>10+</sup>

Defines the parameters for querying historical traffic of an application.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name     | Type                                 | Read-Only|Optional| Description                       |
| --------- | ------------------------------------- | ---- |---| -------------------------- |
| ifaceInfo | IfaceInfo\<[IfaceInfo](#ifaceinfo10)> | No  |No|NIC information, including the NIC name and query time range.|
| uid       | number                                | No  |No|Application UID.         |

## NetStatsInfo<sup>10+</sup>

Defines the historical traffic information.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name     | Type  | Read-Only|Optional| Description                     |
| --------- | ------ | ---- |---| ------------------------ |
| rxBytes   | number | No  |No|Downlink traffic, in bytes.|
| txBytes   | number | No  |No|Uplink traffic, in bytes.|
| rxPackets | number | No  |No|Number of downlink packets.         |
| txPackets | number | No  |No|Number of uplink packets.         |

## NetStatsChangeInfo<sup>11+</sup>

Defines the NIC status and usage of an application.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name     | Type  | Read-Only|Optional| Description      |
| --------- | ------ | ---- |---|--------- |
| iface     | string | No  |No| NIC name.|
| uid       | number | No  |Yes|Application UID. |

## NetworkInfo<sup>12+</sup>

Defines the network information.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name       | Type                                                  | Read-Only|Optional| Description          |
|-----------|------------------------------------------------------|----|---|--------------|
| type      | [NetBearType](js-apis-net-connection.md#netbeartype) | No | No|Network type.       |
| startTime | number                                               | No |No| Start timestamp, in seconds.|
| endTime   | number                                               | No |No|End timestamp, in seconds.|
| simId     | number                                               | No | Yes|SIM card ID.   |

## UidNetStatsInfo<sup>12+</sup>

Defines the historical traffic statistics of all applications.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name       | Type                                           | Read-Only|Optional| Description          |
|-----------|-----------------------------------------------|----|---|--------------|
| undefined | [uid:number]: [NetStatsInfo](#netstatsinfo10) | No |No|Historical traffic statistics of all applications.|

## NetStatsInfoSequence<sup>12+</sup>

Defines the historical traffic statistics of the specified application.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name       | Type                             | Read-Only| Optional|Description          |
|-----------|---------------------------------|----|---|--------------|
| startTime | number                          | No |No|Start timestamp, in seconds.|
| endTime   | number                          | No |No|End timestamp, in seconds.|
| info      | [NetStatsInfo](#netstatsinfo10) | No |No|Defines the historical traffic statistics of the specified application.|
