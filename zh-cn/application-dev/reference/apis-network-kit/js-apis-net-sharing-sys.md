# @ohos.net.sharing (网络共享管理)（系统接口）

网络共享管理分享设备已有网络给其他连接设备，支持 Wi-Fi 热点共享、蓝牙共享和 USB 共享，同时提供网络共享状态、共享流量查询功能。

> **说明：**
>
> 本模块首批接口从 API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块为系统接口。

## 导入模块

```js
import { sharing } from '@kit.NetworkKit';
```

## sharing.isSharingSupported

isSharingSupported(callback: AsyncCallback\<boolean>): void

判断是否支持网络共享，使用 callback 方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback\<boolean> | 是   | 回调函数，返回 true 代表支持网络共享。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 2200002   | Failed to connect to the service.            |
| 2200003   | System internal error.                       |
| 2202011   | Cannot get network sharing configuration.    |

**示例：**

```js
import { sharing } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

sharing.isSharingSupported((error: BusinessError, data: boolean) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(data));
});
```

## sharing.isSharingSupported

isSharingSupported(): Promise\<boolean>

判断是否支持网络共享，使用 Promise 方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**返回值：**

| 类型              | 说明                                  |
| ----------------- | ------------------------------------- |
| Promise\<boolean> | 以 Promise 形式返回是否支持共享结果。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 2200002   | Failed to connect to the service.            |
| 2200003   | System internal error.                       |
| 2202011   | Cannot get network sharing configuration.    |

**示例：**

```js
import { sharing } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

sharing
  .isSharingSupported()
  .then((data: boolean) => {
    console.log(JSON.stringify(data));
  })
  .catch((error: BusinessError) => {
    console.log(JSON.stringify(error));
  });
```

## sharing.isSharing

isSharing(callback: AsyncCallback\<boolean>): void

获取当前网络共享状态，使用 callback 方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                 |
| -------- | ----------------------- | ---- | ------------------------------------ |
| callback | AsyncCallback\<boolean> | 是   | 回调函数，返回 true 代表网络共享中。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 2200002   | Failed to connect to the service.            |
| 2200003   | System internal error.                       |
| 2202011   | Cannot get network sharing configuration.    |

**示例：**

```js
import { sharing } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

sharing.isSharing((error: BusinessError, data: boolean) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(data));
});
```

## sharing.isSharing

isSharing(): Promise\<boolean>

获取当前网络共享状态，使用 Promise 方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**返回值：**

| 类型              | 说明                                                            |
| ----------------- | --------------------------------------------------------------- |
| Promise\<boolean> | 以 Promise 形式返回网络共享状态结果，返回 true 代表网络共享中。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 2200002   | Failed to connect to the service.            |
| 2200003   | System internal error.                       |
| 2202011   | Cannot get network sharing configuration.    |

**示例：**

```js
import { sharing } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

sharing
  .isSharing()
  .then((data: boolean) => {
    console.log(JSON.stringify(data));
  })
  .catch((error: BusinessError) => {
    console.log(JSON.stringify(error));
  });
```

## sharing.startSharing

startSharing(type: SharingIfaceType, callback: AsyncCallback\<void>): void

开启指定类型共享，使用 callback 方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                     |
| -------- | ------------------------------------- | ---- | ---------------------------------------- |
| type     | [SharingIfaceType](#sharingifacetype) | 是   | 共享类型，0：Wi-Fi 1：USB 2：BLUETOOTH。 |
| callback | AsyncCallback\<void>                  | 是   | 回调函数，返回开启网络共享结果。         |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2200001   | Invalid parameter value.                     |
| 2200002   | Failed to connect to the service.            |
| 2200003   | System internal error.                       |
| 2202004   | Try to share an unavailable iface.           |
| 2202005   | WiFi sharing failed.                         |
| 2202006   | Bluetooth sharing failed.                    |
| 2202009   | Failed to enable forwarding for network sharing.       |
| 2202011   | Cannot get network sharing configuration.    |

**示例：**

```js
import { sharing } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let SHARING_WIFI = 0;
sharing.startSharing(SHARING_WIFI, (error: BusinessError) => {
  console.log(JSON.stringify(error));
});
```

## sharing.startSharing

startSharing(type: SharingIfaceType): Promise\<void>

开启指定类型共享，使用 Promise 方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**参数：**

| 参数名 | 类型                                  | 必填 | 说明                                     |
| ------ | ------------------------------------- | ---- | ---------------------------------------- |
| type   | [SharingIfaceType](#sharingifacetype) | 是   | 共享类型，0：Wi-Fi 1：USB 2：BLUETOOTH。 |

**返回值：**

| 类型           | 说明                                  |
| -------------- | ------------------------------------- |
| Promise\<void> | 以 Promise 形式返回开启共享执行结果。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 202       | Non-system applications use system APIs.     |
| 201       | Permission denied.                           |
| 401       | Parameter error.                             |
| 2200001   | Invalid parameter value.                     |
| 2200002   | Failed to connect to the service.            |
| 2200003   | System internal error.                       |
| 2202004   | Try to share an unavailable iface.           |
| 2202005   | WiFi sharing failed.                         |
| 2202006   | Bluetooth sharing failed.                    |
| 2202009   | Failed to enable forwarding for network sharing.       |
| 2202011   | Cannot get network sharing configuration.    |

**示例：**

```js
import { sharing } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let SHARING_WIFI = 0;
sharing
  .startSharing(SHARING_WIFI)
  .then(() => {
    console.log('start wifi sharing successful');
  })
  .catch((error: BusinessError) => {
    console.log('start wifi sharing failed');
  });
```

## sharing.stopSharing

stopSharing(type: SharingIfaceType, callback: AsyncCallback\<void>): void

关闭指定类型共享，使用 callback 方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                     |
| -------- | ------------------------------------- | ---- | ---------------------------------------- |
| type     | [SharingIfaceType](#sharingifacetype) | 是   | 共享类型，0：Wi-Fi 1：USB 2：BLUETOOTH。 |
| callback | AsyncCallback\<void>                  | 是   | 回调函数,返回停止网络共享结果。          |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2200001   | Invalid parameter value.                     |
| 2200002   | Failed to connect to the service.            |
| 2200003   | System internal error.                       |
| 2202004   | Try to share an unavailable iface.           |
| 2202005   | WiFi sharing failed.                         |
| 2202006   | Bluetooth sharing failed.                    |
| 2202011   | Cannot get network sharing configuration.    |

**示例：**

```js
import { sharing } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let SHARING_WIFI = 0;
sharing.stopSharing(SHARING_WIFI, (error: BusinessError) => {
  console.log(JSON.stringify(error));
});
```

## sharing.stopSharing

stopSharing(type: SharingIfaceType): Promise\<void>

关闭指定类型共享，使用 Promise 方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**参数：**

| 参数名 | 类型                                  | 必填 | 说明                                     |
| ------ | ------------------------------------- | ---- | ---------------------------------------- |
| type   | [SharingIfaceType](#sharingifacetype) | 是   | 共享类型，0：Wi-Fi 1：USB 2：BLUETOOTH。 |

**返回值：**

| 类型           | 说明                                  |
| -------------- | ------------------------------------- |
| Promise\<void> | 以 Promise 形式返回关闭共享执行结果。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2200001   | Invalid parameter value.                     |
| 2200002   | Failed to connect to the service.            |
| 2200003   | System internal error.                       |
| 2202004   | Try to share an unavailable iface.           |
| 2202005   | WiFi sharing failed.                         |
| 2202006   | Bluetooth sharing failed.                    |
| 2202011   | Cannot get network sharing configuration.    |

**示例：**

```js
import { sharing } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let SHARING_WIFI = 0;
sharing
  .stopSharing(SHARING_WIFI)
  .then(() => {
    console.log('stop wifi sharing successful');
  })
  .catch((error: BusinessError) => {
    console.log('stop wifi sharing failed');
  });
```

## sharing.getStatsRxBytes

getStatsRxBytes(callback: AsyncCallback\<number>): void

获取共享网络接收数据量，使用 callback 方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                    |
| -------- | ---------------------- | ---- | --------------------------------------- |
| callback | AsyncCallback\<number> | 是   | 回调函数，number 代表数据量，单位：KB。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2200002   | Failed to connect to the service.            |
| 2200003   | System internal error.                       |

**示例：**

```js
import { sharing } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

sharing.getStatsRxBytes((error: BusinessError, data: number) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(data));
});
```

## sharing.getStatsRxBytes

getStatsRxBytes(): Promise\<number>

获取共享网络接收数据量，使用 Promise 方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**返回值：**

| 类型             | 说明                                              |
| ---------------- | ------------------------------------------------- |
| Promise\<number> | 以 Promise 形式返回共享网络接收数据量，单位：KB。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2200002   | Failed to connect to the service.            |
| 2200003   | System internal error.                       |

**示例：**

```js
import { sharing } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

sharing
  .getStatsRxBytes()
  .then((data: number) => {
    console.log(JSON.stringify(data));
  })
  .catch((error: BusinessError) => {
    console.log(JSON.stringify(error));
  });
```

## sharing.getStatsTxBytes

getStatsTxBytes(callback: AsyncCallback\<number>): void

获取共享网络发送数据量，使用 callback 方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                    |
| -------- | ---------------------- | ---- | --------------------------------------- |
| callback | AsyncCallback\<number> | 是   | 回调函数，number 代表数据量，单位：KB。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2200002   | Failed to connect to the service.            |
| 2200003   | System internal error.                       |

**示例：**

```js
import { sharing } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

sharing.getStatsTxBytes((error: BusinessError, data: number) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(data));
});
```

## sharing.getStatsTxBytes

getStatsTxBytes(): Promise\<number>

获取共享网络发送数据量，使用 Promise 方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**返回值：**

| 类型             | 说明                                              |
| ---------------- | ------------------------------------------------- |
| Promise\<number> | 以 Promise 形式返回共享网络发送数据量，单位：KB。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2200002   | Failed to connect to the service.            |
| 2200003   | System internal error.                       |

**示例：**

```js
import { sharing } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

sharing
  .getStatsTxBytes()
  .then((data: number) => {
    console.log(JSON.stringify(data));
  })
  .catch((error: BusinessError) => {
    console.log(JSON.stringify(error));
  });
```

## sharing.getStatsTotalBytes

getStatsTotalBytes(callback: AsyncCallback\<number>): void

获取共享网络总数据量，使用 callback 方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                    |
| -------- | ---------------------- | ---- | --------------------------------------- |
| callback | AsyncCallback\<number> | 是   | 回调函数，number 代表数据量，单位：KB。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2200002   | Failed to connect to the service.            |
| 2200003   | System internal error.                       |

**示例：**

```js
import { sharing } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

sharing.getStatsTotalBytes((error: BusinessError, data: number) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(data));
});
```

## sharing.getStatsTotalBytes

getStatsTotalBytes(): Promise\<number>

获取共享网络总数据量，使用 Promise 方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**返回值：**

| 类型             | 说明                                            |
| ---------------- | ----------------------------------------------- |
| Promise\<number> | 以 Promise 形式返回共享网络总数据量，单位：KB。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2200002   | Failed to connect to the service.            |
| 2200003   | System internal error.                       |

**示例：**

```js
import { sharing } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

sharing
  .getStatsTotalBytes()
  .then((data: number) => {
    console.log(JSON.stringify(data));
  })
  .catch((error: BusinessError) => {
    console.log(JSON.stringify(error));
  });
```

## sharing.getSharingIfaces

getSharingIfaces(state: SharingIfaceState, callback: AsyncCallback\<Array\<string>>): void

获取指定状态的网卡名称列表，使用 callback 方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**参数：**

| 参数名   | 类型                                    | 必填 | 说明                                   |
| -------- | --------------------------------------- | ---- | -------------------------------------- |
| state    | [SharingIfaceState](#sharingifacestate) | 是   | 网络共享状态。                         |
| callback | AsyncCallback\<Array\<string>>          | 是   | 回调函数，返回指定状态的网卡名称列表。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2200001   | Invalid parameter value.                     |
| 2200002   | Failed to connect to the service.            |
| 2200003   | System internal error.                       |

**示例：**

```js
import { sharing } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let SHARING_BLUETOOTH = 2;
sharing.getSharingIfaces(SHARING_BLUETOOTH, (error: BusinessError, data: string[]) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(data));
});
```

## sharing.getSharingIfaces

getSharingIfaces(state: SharingIfaceState): Promise\<Array\<string>>

获取指定状态的网卡名称列表，使用 Promise 方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**参数：**

| 参数名 | 类型                                    | 必填 | 说明           |
| ------ | --------------------------------------- | ---- | -------------- |
| state  | [SharingIfaceState](#sharingifacestate) | 是   | 网络共享状态。 |

**返回值：**

| 类型                     | 说明                                      |
| ------------------------ | ----------------------------------------- |
| Promise\<Array\<string>> | 以 Promise 形式返回指定状态网卡名称列表。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2200001   | Invalid parameter value.                     |
| 2200002   | Failed to connect to the service.            |
| 2200003   | System internal error.                       |

**示例：**

```js
import { sharing } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let SHARING_BLUETOOTH = 2;
sharing
  .getSharingIfaces(SHARING_BLUETOOTH)
  .then((data: string[]) => {
    console.log(JSON.stringify(data));
  })
  .catch((error: BusinessError) => {
    console.log(JSON.stringify(error));
  });
```

## sharing.getSharingState

getSharingState(type: SharingIfaceType, callback: AsyncCallback\<SharingIfaceState\>): void

获取指定类型网络共享状态，使用 callback 方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**参数：**

| 参数名   | 类型                                                    | 必填 | 说明                                     |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------------- |
| type     | [SharingIfaceType](#sharingifacetype)                   | 是   | 共享类型，0：Wi-Fi 1：USB 2：BLUETOOTH。 |
| callback | AsyncCallback\<[SharingIfaceState](#sharingifacestate)> | 是   | 回调函数，返回指定类型网络共享状态。     |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2200001   | Invalid parameter value.                     |
| 2200002   | Failed to connect to the service.            |
| 2200003   | System internal error.                       |

**示例：**

```js
import { sharing } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let SHARING_WIFI = 0;
sharing.getSharingState(SHARING_WIFI, (error: BusinessError, data: sharing.SharingIfaceState) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(data));
});
```

## sharing.getSharingState

getSharingState(type: SharingIfaceType): Promise\<SharingIfaceState\>

获取指定类型网络共享状态，使用 Promise 方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**参数：**

| 参数名 | 类型                                  | 必填 | 说明                                     |
| ------ | ------------------------------------- | ---- | ---------------------------------------- |
| type   | [SharingIfaceType](#sharingifacetype) | 是   | 共享类型，0：Wi-Fi 1：USB 2：BLUETOOTH。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2200001   | Invalid parameter value.                     |
| 2200002   | Failed to connect to the service.            |
| 2200003   | System internal error.                       |

**返回值：**

| 类型                                              | 说明                                      |
| ------------------------------------------------- | ----------------------------------------- |
| Promise\<[SharingIfaceState](#sharingifacestate)> | 以 Promise 形式返回定类型网络共共享状态。 |

**示例：**

```js
import { sharing } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let SHARING_WIFI = 0;
sharing
  .getSharingState(SHARING_WIFI)
  .then((data: sharing.SharingIfaceState) => {
    console.log(JSON.stringify(data));
  })
  .catch((error: BusinessError) => {
    console.log(JSON.stringify(error));
  });
```

## sharing.getSharableRegexes

getSharableRegexes(type: SharingIfaceType, callback: AsyncCallback\<Array\<string\>\>): void

获取指定类型网卡名称正则表达式列表，使用 callback 方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                           |
| -------- | ------------------------------------- | ---- | ---------------------------------------------- |
| type     | [SharingIfaceType](#sharingifacetype) | 是   | 共享类型，0：Wi-Fi 1：USB 2：BLUETOOTH。       |
| callback | AsyncCallback\<Array\<string>>        | 是   | 回调函数，返回指定类型网卡名称正则表达式列表。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2200001   | Invalid parameter value.                     |
| 2200002   | Failed to connect to the service.            |
| 2200003   | System internal error.                       |

**示例：**

```js
import { sharing } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let SHARING_WIFI = 0;
sharing.getSharableRegexes(SHARING_WIFI, (error: BusinessError, data: string[]) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(data));
});
```

## sharing.getSharableRegexes

getSharableRegexes(type: SharingIfaceType): Promise\<Array\<string>>

获取指定类型网卡名称正则表达式列表，使用 Promise 方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**参数：**

| 参数名 | 类型                                  | 必填 | 说明                                     |
| ------ | ------------------------------------- | ---- | ---------------------------------------- |
| type   | [SharingIfaceType](#sharingifacetype) | 是   | 共享类型，0：Wi-Fi 1：USB 2：BLUETOOTH。 |

**返回值：**

| 类型                     | 说明                                |
| ------------------------ | ----------------------------------- |
| Promise\<Array\<string>> | 以 Promise 形式返回正则表达式列表。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2200001   | Invalid parameter value.                     |
| 2200002   | Failed to connect to the service.            |
| 2200003   | System internal error.                       |

**示例：**

```js
import { sharing } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let SHARING_WIFI = 0;
sharing
  .getSharableRegexes(SHARING_WIFI)
  .then((data: string[]) => {
    console.log(JSON.stringify(data));
  })
  .catch((error: BusinessError) => {
    console.log(JSON.stringify(error));
  });
```

## sharing.on('sharingStateChange')

on(type: 'sharingStateChange', callback: Callback\<boolean>): void

注册网络共享状态变化事件，使用 callback 方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**参数：**

| 参数名   | 类型                    | 必填 | 说明                         |
| -------- | ----------------------- | ---- | ---------------------------- |
| type     | string                  | 是   | 事件名称。                   |
| callback | AsyncCallback\<boolean> | 是   | 回调函数，返回网络共享状态。 |

**错误码：**

| 错误码 ID | 错误信息                                 |
| --------- | ---------------------------------------- |
| 201       | Permission denied.                       |
| 202       | Non-system applications use system APIs. |
| 401       | Parameter error.                         |

**示例：**

```js
import { sharing } from '@kit.NetworkKit';

sharing.on('sharingStateChange', (data: boolean) => {
  console.log('on sharingStateChange: ' + JSON.stringify(data));
});
```

## sharing.off('sharingStateChange')

off(type: 'sharingStateChange', callback?: Callback\<boolean>): void

注销网络共享状态变化事件，使用 callback 方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**参数：**

| 参数名   | 类型                    | 必填 | 说明                         |
| -------- | ----------------------- | ---- | ---------------------------- |
| type     | string                  | 是   | 事件名称。                   |
| callback | AsyncCallback\<boolean> | 否   | 回调函数，返回网络共享状态。 |

**错误码：**

| 错误码 ID | 错误信息                                 |
| --------- | ---------------------------------------- |
| 201       | Permission denied.                       |
| 202       | Non-system applications use system APIs. |
| 401       | Parameter error.                         |

**示例：**

```js
import { sharing } from '@kit.NetworkKit';

sharing.off('sharingStateChange', (data: boolean) => {
  console.log(JSON.stringify(data));
});
```

## sharing.on('interfaceSharingStateChange')

on(type: 'interfaceSharingStateChange', callback: Callback\<InterfaceSharingStateInfo\>): void

注册网卡网络共享状态变化事件，使用 callback 方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**参数：**

| 参数名   | 类型                                                                   | 必填 | 说明                                  |
| -------- | -------------------------------------------------------------------- | ---- | ------------------------------------- |
| type     | string                                                                | 是   | 事件名称。                            |
| callback | AsyncCallback\<[InterfaceSharingStateInfo](#interfacesharingstateinfo11)> | 是   | 回调函数。指定网卡共享状态变化时调用。 |

**错误码：**

| 错误码 ID | 错误信息                                 |
| --------- | ---------------------------------------- |
| 201       | Permission denied.                       |
| 202       | Non-system applications use system APIs. |
| 401       | Parameter error.                         |

**示例：**

```js
import { sharing } from '@kit.NetworkKit';

sharing.on('interfaceSharingStateChange', (data: object) => {
  console.log('on interfaceSharingStateChange:' + JSON.stringify(data));
});
```

## sharing.off('interfaceSharingStateChange')

off(type: 'interfaceSharingStateChange', callback?: Callback\<InterfaceSharingStateInfo\>): void

注销网卡网络共享状态变化事件，使用 callback 方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**参数：**

| 参数名   | 类型                                                                        | 必填 | 说明                                     |
| -------- | --------------------------------------------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                                                     | 是   | 事件名称。                               |
| callback | AsyncCallback\<[InterfaceSharingStateInfo](#interfacesharingstateinfo11)> | 否   | 回调函数，注销指定网卡共享状态变化通知。 |

**错误码：**

| 错误码 ID | 错误信息                                 |
| --------- | ---------------------------------------- |
| 201       | Permission denied.                       |
| 202       | Non-system applications use system APIs. |
| 401       | Parameter error.                         |

**示例：**

```js
import { sharing } from '@kit.NetworkKit';

sharing.off('interfaceSharingStateChange', (data: object) => {
  console.log(JSON.stringify(data));
});
```

## sharing.on('sharingUpstreamChange')

on(type: 'sharingUpstreamChange', callback: Callback\<NetHandle>): void

注册上行网络变化事件，使用 callback 方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**参数：**

| 参数名   | 类型                      | 必填 | 说明                           |
| -------- | ------------------------- | ---- | ------------------------------ |
| type     | string                    | 是   | 事件名称。                     |
| callback | AsyncCallback\<NetHandle> | 是   | 回调函数，上行网络变化时调用。 |

**错误码：**

| 错误码 ID | 错误信息                                 |
| --------- | ---------------------------------------- |
| 201       | Permission denied.                       |
| 202       | Non-system applications use system APIs. |
| 401       | Parameter error.                         |

**示例：**

```js
import { sharing } from '@kit.NetworkKit';

sharing.on('sharingUpstreamChange', (data: object) => {
  console.log('on sharingUpstreamChange:' + JSON.stringify(data));
});
```

## sharing.off('sharingUpstreamChange')

off(type: 'sharingUpstreamChange', callback?: Callback\<NetHandle>): void

注销上行网络变化事件，使用 callback 方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

**参数：**

| 参数名   | 类型                      | 必填 | 说明                             |
| -------- | ------------------------- | ---- | -------------------------------- |
| type     | string                    | 是   | 事件名称。                       |
| callback | AsyncCallback\<NetHandle> | 否   | 回调函数，注销上行网络变化事件。 |

**错误码：**

| 错误码 ID | 错误信息                                 |
| --------- | ---------------------------------------- |
| 201       | Permission denied.                       |
| 202       | Non-system applications use system APIs. |
| 401       | Parameter error.                         |

**示例：**

```js
import { sharing } from '@kit.NetworkKit';

sharing.off('sharingUpstreamChange', (data: object) => {
  console.log(JSON.stringify(data));
});
```

## InterfaceSharingStateInfo<sup>11+</sup>

唤醒在网络共享模式下的变化时的监听器

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

| 名称     | 类型                                              | 必填 | 说明                 |
| -------- | ------------------------------------------------- | ---- | ------------------- |
| type     | [SharingIfaceType](#sharingifacetype)             | 是   | 网络共享类型。       |
| iface    | string                                            | 是   | 指定的共享网络名称。 |
| state    | [SharingIfaceState](#sharingifacestate)           | 是   | 网卡共享状态。       |

## SharingIfaceState

网络共享状态。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

| 名称                   | 值  | 说明             |
| ---------------------- | --- | ---------------- |
| SHARING_NIC_SERVING    | 1   | 正在网络共享。   |
| SHARING_NIC_CAN_SERVER | 2   | 可提供网络共享。 |
| SHARING_NIC_ERROR      | 3   | 网络共享错误。   |

## SharingIfaceType

网络共享类型。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.NetSharing

| 名称              | 值  | 说明                 |
| ----------------- | --- | -------------------- |
| SHARING_WIFI      | 0   | 网络共享类型 Wi-Fi。 |
| SHARING_USB       | 1   | 网络共享类型 USB。   |
| SHARING_BLUETOOTH | 2   | 网络共享类型蓝牙。   |
