# @ohos.telephony.observer (observer)

本模块提供订阅管理功能，可以订阅/取消订阅的事件包括：网络状态变化、信号状态变化、通话状态变化、蜂窝数据链路连接状态、蜂窝数据业务的上下行数据流状态、SIM状态变化。

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import { observer } from '@kit.TelephonyKit';
```

## NetworkState

type NetworkState = radio.NetworkState

网络注册状态。

**系统能力**：SystemCapability.Telephony.StateRegistry

|       类型       |            说明             |
| ---------------- | --------------------------- |
| [radio.NetworkState](js-apis-radio.md#networkstate) | 网络注册状态。 |

## SignalInformation

type SignalInformation = radio.SignalInformation

网络信号强度信息对象。

**系统能力**：SystemCapability.Telephony.StateRegistry

|       类型       |            说明             |
| ---------------- | --------------------------- |
| [radio.SignalInformation](js-apis-radio.md#signalinformation) | 网络信号强度信息对象。 |


## DataConnectState

type DataConnectState = data.DataConnectState

描述蜂窝数据链路连接状态。

**系统能力**：SystemCapability.Telephony.StateRegistry

|       类型       |            说明             |
| ---------------- | --------------------------- |
| [data.DataConnectState](js-apis-telephony-data.md#dataconnectstate) | 描述蜂窝数据链路连接状态。 |


## RatType

type RatType = radio.RadioTechnology

无线接入技术。

**系统能力**：SystemCapability.Telephony.StateRegistry

|       类型       |            说明             |
| ---------------- | --------------------------- |
| [radio.RadioTechnology](js-apis-radio.md#radiotechnology) | 无线接入技术。 |


## DataFlowType

type DataFlowType = data.DataFlowType

描述蜂窝数据流类型。

**系统能力**：SystemCapability.Telephony.StateRegistry

|       类型       |            说明             |
| ---------------- | --------------------------- |
| [data.DataFlowType](js-apis-telephony-data.md#dataflowtype) | 描述蜂窝数据流类型。 |


## CallState

type CallState = call.CallState

通话状态码。

**系统能力**：SystemCapability.Telephony.StateRegistry

|       类型       |            说明             |
| ---------------- | --------------------------- |
| [call.CallState](js-apis-call.md#callstate) | 通话状态码。 |


## CardType

type CardType = sim.CardType

卡类型。

**系统能力**：SystemCapability.Telephony.StateRegistry

|       类型       |            说明             |
| ---------------- | --------------------------- |
| [sim.CardType](js-apis-sim.md#cardtype7) | 卡类型。 |


## SimState

type SimState = sim.SimState

SIM卡状态。

**系统能力**：SystemCapability.Telephony.StateRegistry

|       类型       |            说明             |
| ---------------- | --------------------------- |
| [sim.SimState](js-apis-sim.md#simstate) | SIM卡状态。 |


## observer.on('networkStateChange')

on\(type: \'networkStateChange\', callback: Callback\<NetworkState\>\): void

订阅网络状态变化事件，使用callback方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                      | 必填 | 说明                                                              |
| -------- | --------------------------------------------------------- | ---- | ---------------------------------------------------------------- |
| type     | string                                                    | 是   | 网络状态变化事件，参数固定为'networkStateChange'。                 |
| callback | Callback\<[NetworkState](js-apis-radio.md#networkstate)\> | 是   | 以callback形式异步返回结果。参考radio的[NetworkState](js-apis-radio.md#networkstate)。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
observer.on('networkStateChange', (data: observer.NetworkState) => {
    console.log("on networkStateChange, data:" + JSON.stringify(data));
});
```


## observer.on('networkStateChange')

on\(type: \'networkStateChange\', options: ObserverOptions, callback: Callback\<NetworkState\>\): void

订阅指定卡槽位的网络状态变化事件，使用callback方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

|  参数名  |                              类型                         | 必填 |                            说明                                   |
| -------- | --------------------------------------------------------- | ---- | ---------------------------------------------------------------- |
| type     | string                                                    | 是   | 网络状态变化事件，参数固定为'networkStateChange'。                 |
| options  | [ObserverOptions](#observeroptions11)                     | 是   | 电话相关事件订阅参数可选项。                                        |
| callback | Callback\<[NetworkState](js-apis-radio.md#networkstate)\> | 是   | 以callback形式异步返回结果，参考radio的[NetworkState](js-apis-radio.md#networkstate)。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
let options: observer.ObserverOptions = {
    slotId: 0
}
observer.on('networkStateChange', options, (data: observer.NetworkState) => {
    console.log("on networkStateChange, data:" + JSON.stringify(data));
});
```


## observer.off('networkStateChange')

off\(type: \'networkStateChange\', callback?: Callback\<NetworkState\>\): void

取消订阅网络状态变化事件，使用callback方式作为异步方法。

> **说明：**
>
> 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                      | 必填 | 说明                                                         |
| -------- | --------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                    | 是   | 网络状态变化事件，参数固定为'networkStateChange'。                 |
| callback | Callback\<[NetworkState](js-apis-radio.md#networkstate)\> | 否   | 以callback形式异步返回结果，参考radio的[NetworkState](js-apis-radio.md#networkstate)。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
let callback: (data: observer.NetworkState) => void = (data: observer.NetworkState) => {
    console.log("on networkStateChange, data:" + JSON.stringify(data));
}
observer.on('networkStateChange', callback);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
observer.off('networkStateChange', callback);
observer.off('networkStateChange');
```

## observer.on('signalInfoChange')

on\(type: \'signalInfoChange\', callback: Callback\<Array\<SignalInformation\>\>): void

订阅信号状态变化事件，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------------- |
| type     | string                                                       | 是   | 信号状态变化事件，参数固定为'signalInfoChange'。              |
| callback | Callback\<Array\<[SignalInformation](js-apis-radio.md#signalinformation)\>\> | 是   | 以callback形式异步返回结果，参考radio的[SignalInformation](js-apis-radio.md#signalinformation)。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                  错误信息                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
import { radio } from '@kit.TelephonyKit';

observer.on('signalInfoChange', (data: Array<radio.SignalInformation>) => {
    console.log("on signalInfoChange, data:" + JSON.stringify(data));
});
```


## observer.on('signalInfoChange')

on\(type: \'signalInfoChange\', options: ObserverOptions, callback: Callback\<Array\<SignalInformation\>\>): void

订阅指定卡槽位的信号状态变化事件，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------------- |
| type     | string                                                       | 是   | 信号状态变化事件，参数固定为'signalInfoChange'。              |
| options  | [ObserverOptions](#observeroptions11)                        | 是   | 电话相关事件订阅参数可选项。                                   |
| callback | Callback\<Array\<[SignalInformation](js-apis-radio.md#signalinformation)\>\> | 是   | 以callback形式异步返回结果，参考radio的[SignalInformation](js-apis-radio.md#signalinformation)。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
import { radio } from '@kit.TelephonyKit';

let options: observer.ObserverOptions = {
    slotId: 0
}
observer.on('signalInfoChange', options, (data: Array<radio.SignalInformation>) => {
    console.log("on signalInfoChange, data:" + JSON.stringify(data));
});
```


## observer.off('signalInfoChange')

off\(type: \'signalInfoChange\', callback?: Callback\<Array\<SignalInformation\>\>): void

取消订阅信号状态变化事件，使用callback方式作为异步方法。

> **说明：**
>
> 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 信号状态变化事件，参数固定为'signalInfoChange'。              |
| callback | Callback\<Array\<[SignalInformation](js-apis-radio.md#signalinformation)\>\> | 否   | 以callback形式异步返回结果，参考radio的[SignalInformation](js-apis-radio.md#signalinformation)。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
import { radio } from '@kit.TelephonyKit';

let callback: (data: Array<radio.SignalInformation>) => void = (data: Array<radio.SignalInformation>) => {
    console.log("on signalInfoChange, data:" + JSON.stringify(data));
}
observer.on('signalInfoChange', callback);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
observer.off('signalInfoChange', callback);
observer.off('signalInfoChange');
```


## observer.on('callStateChange')

on(type: 'callStateChange', callback: Callback\<CallStateInfo\>): void

订阅通话状态变化事件，使用callback方式作为异步方法。

> **说明：**
>
> 获取电话号码时需要ohos.permission.READ_CALL_LOG权限，该权限为系统权限。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                           | 必填 | 说明                                                        |
| -------- | --------------------------------------------- | ---- | ----------------------------------------------------------- |
| type     | string                                        | 是   | 通话状态变化事件，参数固定为'callStateChange'。                |
| callback | Callback\<[CallStateInfo](#callstateinfo11)\> | 是   | 以callback形式异步返回结果，参考call的[CallState](js-apis-call.md#callstate)<br />number：电话号码。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
observer.on('callStateChange', (data: observer.CallStateInfo) => {
    console.log("on callStateChange, data:" + JSON.stringify(data));
});
```


## observer.on('callStateChange')

on(type: 'callStateChange', options: ObserverOptions, callback: Callback\<CallStateInfo\>): void

订阅通话状态变化事件，使用callback方式作为异步方法。

> **说明：**
>
> 获取电话号码时需要ohos.permission.READ_CALL_LOG权限，该权限为系统权限。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------------- |
| type     | string                                                       | 是   | 通话状态变化事件，参数固定为'callStateChange'。               |
| options  | [ObserverOptions](#observeroptions11)                        | 是   | 电话相关事件订阅参数可选项。                                  |
| callback | Callback\<[CallStateInfo](#callstateinfo11)\>                | 是   | 以callback形式异步返回结果，参考call的[CallState](js-apis-call.md#callstate)<br />number：电话号码。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
let options: observer.ObserverOptions = {
    slotId: 0
}
observer.on('callStateChange', options, (data: observer.CallStateInfo) => {
    console.log("on callStateChange, data:" + JSON.stringify(data));
});
```


## observer.off('callStateChange')

off(type: 'callStateChange', callback?: Callback\<CallStateInfo\>): void

取消订阅通话状态变化事件，使用callback方式作为异步方法。

> **说明：**
>
> 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------------- |
| type     | string                                                       | 是   | 通话状态变化事件，参数固定为'callStateChange'。               |
| callback | Callback\<[CallStateInfo](#callstateinfo11)\>                | 否   | 以callback形式异步返回结果，参考call的[CallState](js-apis-call.md#callstate)<br />number：电话号码。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
let callback: (data: observer.CallStateInfo) => void = (data: observer.CallStateInfo) => {
    console.log("on callStateChange, data:" + JSON.stringify(data));
}
observer.on('callStateChange', callback);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
observer.off('callStateChange', callback);
observer.off('callStateChange');
```


## observer.on('cellularDataConnectionStateChange')<sup>7+</sup>

on\(type: 'cellularDataConnectionStateChange', callback: Callback\<DataConnectionStateInfo\>\): void

订阅蜂窝数据链路连接状态，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                               | 必填 | 说明                                                                 |
| -------- | --------------------------------- | ---- | -------------------------------------------------------------------- |
| type     | string                            | 是   | 蜂窝数据链路连接状态事件，参数固定为'cellularDataConnectionStateChange'。|
| callback | Callback\<[DataConnectionStateInfo](#dataconnectionstateinfo11)\>  | 是   | 以callback形式异步返回结果，参考data的[DataConnectState](js-apis-telephony-data.md#dataconnectstate)，radio的[RadioTechnology](js-apis-radio.md#radiotechnology)。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
observer.on('cellularDataConnectionStateChange', (data: observer.DataConnectionStateInfo) => {
    console.log("on cellularDataConnectionStateChange, data:" + JSON.stringify(data));
});
```


## observer.on('cellularDataConnectionStateChange')<sup>7+</sup>

on\(type: 'cellularDataConnectionStateChange', options: ObserverOptions, callback: Callback\<DataConnectionStateInfo\>\): void

订阅指定卡槽位的蜂窝数据链路连接状态，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 蜂窝数据链路连接状态事件，参数固定为'cellularDataConnectionStateChange'。|
| options  | [ObserverOptions](#observeroptions11)                        | 是   | 电话相关事件订阅参数可选项。             |
| callback | Callback\<[DataConnectionStateInfo](#dataconnectionstateinfo11)\> | 是   | 以callback形式异步返回结果，参考data的[DataConnectState](js-apis-telephony-data.md#dataconnectstate)，radio的[RadioTechnology](js-apis-radio.md#radiotechnology)。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
let options: observer.ObserverOptions = {
    slotId: 0
}
observer.on('cellularDataConnectionStateChange', options, (data: observer.DataConnectionStateInfo) => {
    console.log("on cellularDataConnectionStateChange, data:" + JSON.stringify(data));
});
```


## observer.off('cellularDataConnectionStateChange')<sup>7+</sup>

off\(type: 'cellularDataConnectionStateChange',  callback?: Callback\<DataConnectionStateInfo\>\): void

移除订阅蜂窝数据链路连接状态，使用callback方式作为异步方法。

> **说明：**
>
> 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 蜂窝数据链路连接状态事件，参数固定为'cellularDataConnectionStateChange'。|
| callback | Callback\<[DataConnectionStateInfo](#dataconnectionstateinfo11)\> | 否   | 以callback形式异步返回结果，参考data的[DataConnectState](js-apis-telephony-data.md#dataconnectstate)，radio的[RadioTechnology](js-apis-radio.md#radiotechnology)。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
let callback: (data: observer.DataConnectionStateInfo) => void = (data: observer.DataConnectionStateInfo) => {
    console.log("on cellularDataConnectionStateChange, data:" + JSON.stringify(data));
}
observer.on('cellularDataConnectionStateChange', callback);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
observer.off('cellularDataConnectionStateChange', callback);
observer.off('cellularDataConnectionStateChange');
```


## observer.on('cellularDataFlowChange')<sup>7+</sup>

on\(type: 'cellularDataFlowChange', callback: Callback\<DataFlowType\>\): void

订阅蜂窝数据业务的上下行数据流状态，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是  | 蜂窝数据业务的上下行数据流状态事件，参数固定为'cellularDataFlowChange'。         |
| callback | Callback\<[DataFlowType](js-apis-telephony-data.md#dataflowtype)\> | 是   | 以callback形式异步返回结果，参考data的[DataFlowType](js-apis-telephony-data.md#dataflowtype)。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
import { data } from '@kit.TelephonyKit';

observer.on('cellularDataFlowChange', (data: data.DataFlowType) => {
    console.log("on cellularDataFlowChange, data:" + JSON.stringify(data));
});
```


## observer.on('cellularDataFlowChange')<sup>7+</sup>

on\(type: 'cellularDataFlowChange', options: ObserverOptions,  callback: Callback\<DataFlowType\>\): void

订阅指定卡槽位的蜂窝数据业务的上下行数据流状态，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                       | 必填 | 说明                                                         |
| -------- | ---------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                     | 是   | 蜂窝数据业务的上下行数据流状态事件，参数固定为'cellularDataFlowChange'。         |
| options   | [ObserverOptions](#observeroptions11)                     | 是   | 电话相关事件订阅参数可选项。                                                   |
| callback | Callback\<[DataFlowType](js-apis-telephony-data.md#dataflowtype)\> | 是   | 以callback形式异步返回结果，参考data的[DataFlowType](js-apis-telephony-data.md#dataflowtype)。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
import { data } from '@kit.TelephonyKit';

let options: observer.ObserverOptions = {
    slotId: 0
}
observer.on('cellularDataFlowChange', options, (data: data.DataFlowType) => {
    console.log("on cellularDataFlowChange, data:" + JSON.stringify(data));
});
```


## observer.off('cellularDataFlowChange')<sup>7+</sup>

off\(type: 'cellularDataFlowChange', callback?: Callback\<DataFlowType\>\): void

移除订阅蜂窝数据业务的上下行数据流状态，使用callback方式作为异步方法。

> **说明：**
>
> 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                                | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                             | 是   | 蜂窝数据业务的上下行数据流状态事件，参数固定为'cellularDataFlowChange'。   |
| callback | Callback\<[DataFlowType](js-apis-telephony-data.md#dataflowtype)\> | 否   | 以callback形式异步返回结果，参考data的[DataFlowType](js-apis-telephony-data.md#dataflowtype)。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
import { data } from '@kit.TelephonyKit';

let callback: (data: data.DataFlowType) => void = (data: data.DataFlowType) => {
    console.log("on cellularDataFlowChange, data:" + JSON.stringify(data));
}
observer.on('cellularDataFlowChange', callback);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
observer.off('cellularDataFlowChange', callback);
observer.off('cellularDataFlowChange');
```


## observer.on('simStateChange')<sup>7+</sup>

on\(type: 'simStateChange', callback: Callback\<SimStateData\>\): void

订阅sim状态更改事件，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------------- |
| type     | string                                                       | 是   | sim状态更改事件，参数固定为'simStateChange'。                 |
| callback | Callback\<[SimStateData](#simstatedata7)\> | 是   | 以callback形式异步返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
observer.on('simStateChange', (data: observer.SimStateData) => {
    console.log("on simStateChange, data:" + JSON.stringify(data));
});
```


## observer.on('simStateChange')<sup>7+</sup>

on\(type: 'simStateChange', options: ObserverOptions, callback: Callback\<SimStateData\>\): void

订阅指定卡槽位的sim状态更改事件，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | sim状态更改事件，参数固定为'simStateChange'。                 |
| options   | [ObserverOptions](#observeroptions11)                       | 是   | 电话相关事件订阅参数可选项。                                  |
| callback | Callback\<[SimStateData](#simstatedata7)\> | 是   | 以callback形式异步返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
let options: observer.ObserverOptions = {
    slotId: 0
}
observer.on('simStateChange', options, (data: observer.SimStateData) => {
    console.log("on simStateChange, data:" + JSON.stringify(data));
});
```


## observer.off('simStateChange')<sup>7+</sup>

off\(type: 'simStateChange', callback?: Callback\<SimStateData\>\): void

移除订阅sim状态更改事件，使用callback方式作为异步方法。

> **说明：**
>
> 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | sim状态更改事件，参数固定为'simStateChange'。                 |
| callback | Callback\<[SimStateData](#simstatedata7)\> | 否   | 以callback形式异步返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
let callback: (data: observer.SimStateData) => void = (data: observer.SimStateData) => {
    console.log("on simStateChange, data:" + JSON.stringify(data));
}
observer.on('simStateChange', callback);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
observer.off('simStateChange', callback);
observer.off('simStateChange');
```

## observer.on('iccAccountInfoChange')<sup>10+</sup>

on\(type: 'iccAccountInfoChange', callback: Callback\<void\>\): void

订阅卡帐户变化事件，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 卡帐户变化事件，参数固定为'iccAccountInfoChange'。                 |
| callback | Callback\<void\> | 是   | 以callback形式异步返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
observer.on('iccAccountInfoChange', () => {
    console.log("on iccAccountInfoChange success");
});
```


## observer.off('iccAccountInfoChange')<sup>10+</sup>

off\(type: 'iccAccountInfoChange', callback?: Callback\<void\>\): void

移除订阅卡帐户变化事件，使用callback方式作为异步方法。

> **说明：**
>
> 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 卡帐户变化事件，参数固定为'iccAccountInfoChange'。                 |
| callback | Callback\<void\> | 否   | 以callback形式异步返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
let callback: () => void = () => {
    console.log("on iccAccountInfoChange success");
}
observer.on('iccAccountInfoChange', callback);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
observer.off('iccAccountInfoChange', callback);
observer.off('iccAccountInfoChange');
```


## LockReason<sup>8+</sup>

SIM卡锁类型。

**系统能力**：SystemCapability.Telephony.StateRegistry

| 名称        | 值   | 说明              |
| ----------- | ---- | ----------------- |
| SIM_NONE    | 0    | 无锁。            |
| SIM_PIN     | 1    | PIN锁。           |
| SIM_PUK     | 2    | PUK锁。           |
| SIM_PN_PIN  | 3    | 网络PIN锁。       |
| SIM_PN_PUK  | 4    | 网络PUK锁。       |
| SIM_PU_PIN  | 5    | 子网PIN锁。       |
| SIM_PU_PUK  | 6    | 子网PUK锁。       |
| SIM_PP_PIN  | 7    | 服务提供商PIN锁。 |
| SIM_PP_PUK  | 8    | 服务提供商PUK锁。 |
| SIM_PC_PIN  | 9    | 组织PIN锁。       |
| SIM_PC_PUK  | 10   | 组织PUK锁。       |
| SIM_SIM_PIN | 11   | SIM PIN锁。       |
| SIM_SIM_PUK | 12   | SIM PUK锁。       |


## SimStateData<sup>7+</sup>

SIM卡类型和状态。

**系统能力**：SystemCapability.Telephony.StateRegistry

|     名称            |                 类型                | 必填 | 说明                                                      |
| ------------------- | ----------------------------------- | ---- | --------------------------------------------------------  |
| type                | [CardType](js-apis-sim.md#cardtype7) | 是   | SIM卡类型。 |
| state               | [SimState](js-apis-sim.md#simstate) | 是   | SIM卡状态。 |
| reason<sup>8+</sup> | [LockReason](#lockreason8)          | 是   | SIM卡锁类型。                                             |


## CallStateInfo<sup>11+</sup>

通话状态相关信息。

**系统能力**：SystemCapability.Telephony.StateRegistry

|     名称            |                 类型                    | 必填 | 说明     |
| ------------------- | -------------------------------------- | ---- | -------- |
| state               | [CallState](js-apis-call.md#callstate) | 是   | 通话类型。 |
| number              | string                                 | 是   | 电话号码。 |


## DataConnectionStateInfo<sup>11+</sup>

数据连接状态相关信息。

**系统能力**：SystemCapability.Telephony.StateRegistry

|     名称            |                 类型                                            | 必填 | 说明         |
| ------------------- | ---------------------------------------------------------------| ---- | ------------ |
| state               | [DataConnectState](js-apis-telephony-data.md#dataconnectstate) | 是   | 数据连接状态。 |
| network             | [RatType](js-apis-radio.md#radiotechnology)                    | 是   | 网络类型。     |


## ObserverOptions<sup>11+</sup>

电话相关事件订阅参数可选项。

**系统能力**：SystemCapability.Telephony.StateRegistry

|     名称            |         类型      | 必填  | 说明                                    |
| ------------------- | ------------------| ---- | --------------------------------------- |
| slotId              | number            | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。    |

