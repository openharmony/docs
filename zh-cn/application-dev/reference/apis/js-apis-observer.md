# @ohos.telephony.observer (observer)

本模块提供订阅管理功能，可以订阅/取消订阅的事件包括：网络状态变化、信号状态变化、通话状态变化、蜂窝数据链路连接状态、蜂窝数据业务的上下行数据流状态、SIM状态变化。

>**说明：**
>
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```
import observer from '@ohos.telephony.observer';
```

## observer.on('networkStateChange')

on\(type: \'networkStateChange\', callback: Callback<NetworkState\>\): void;

订阅网络状态变化事件，使用callback方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                      | 必填 | 说明                                                              |
| -------- | --------------------------------------------------------- | ---- | ---------------------------------------------------------------- |
| type     | string                                                    | 是   | 网络状态变化事件，参数固定为'networkStateChange'。                 |
| callback | Callback\<[NetworkState](js-apis-radio.md#networkstate)\> | 是   | 回调函数。参考radio的[NetworkState](js-apis-radio.md#networkstate)|

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)错误码。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```js
observer.on('networkStateChange', data => {
    console.log("on networkStateChange, data:" + JSON.stringify(data));
});
```


## observer.on('networkStateChange')

on\(type: \'networkStateChange\', options: { slotId: number }, callback: Callback<NetworkState\>\): void;

订阅指定卡槽位的网络状态变化事件，使用callback方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

|  参数名  |                              类型                         | 必填 |                            说明                                   |
| -------- | --------------------------------------------------------- | ---- | ---------------------------------------------------------------- |
| type     | string                                                    | 是   | 网络状态变化事件，参数固定为'networkStateChange'。                 |
| slotId   | number                                                    | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2                             |
| callback | Callback\<[NetworkState](js-apis-radio.md#networkstate)\> | 是   | 回调函数。参考radio的[NetworkState](js-apis-radio.md#networkstate) |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)错误码。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```js
observer.on('networkStateChange', {slotId: 0}, data => {
    console.log("on networkStateChange, data:" + JSON.stringify(data));
});
```


## observer.off('networkStateChange')

off\(type: \'networkStateChange\', callback?: Callback<NetworkState\>\): void;

取消订阅网络状态变化事件，使用callback方式作为异步方法。

>**说明：**
>
>可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                      | 必填 | 说明                                                         |
| -------- | --------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                    | 是   | 网络状态变化事件，参数固定为'networkStateChange'。                 |
| callback | Callback\<[NetworkState](js-apis-radio.md#networkstate)\> | 否   | 回调函数。参考radio的[NetworkState](js-apis-radio.md#networkstate) |

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```js
let callback = data => {
    console.log("on networkStateChange, data:" + JSON.stringify(data));
}
observer.on('networkStateChange', callback);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
observer.off('networkStateChange', callback);
observer.off('networkStateChange');
```

## observer.on('signalInfoChange')

on\(type: \'signalInfoChange\', callback: Callback<Array<SignalInformation\>\>): void;

订阅信号状态变化事件，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------------- |
| type     | string                                                       | 是   | 信号状态变化事件，参数固定为'signalInfoChange'。              |
| callback | Callback<Array<[SignalInformation](js-apis-radio.md#signalinformation)\>\> | 是   | 回调函数。参考radio的[SignalInformation](js-apis-radio.md#signalinformation) |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)错误码。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```js
observer.on('signalInfoChange', data => {
    console.log("on signalInfoChange, data:" + JSON.stringify(data));
});
```


## observer.on('signalInfoChange')

on\(type: \'signalInfoChange\', options: { slotId: number }, callback: Callback<Array<SignalInformation\>\>): void;

订阅指定卡槽位的信号状态变化事件，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------------- |
| type     | string                                                       | 是   | 信号状态变化事件，参数固定为'signalInfoChange'。              |
| slotId   | number                                                       | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2                       |
| callback | Callback<Array<[SignalInformation](js-apis-radio.md#signalinformation)\>\> | 是   | 回调函数。参考radio的[SignalInformation](js-apis-radio.md#signalinformation) |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)错误码。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```js
observer.on('signalInfoChange', {slotId: 0}, data => {
    console.log("on signalInfoChange, data:" + JSON.stringify(data));
});
```


## observer.off('signalInfoChange')

off\(type: \'signalInfoChange\', callback?: Callback<Array<SignalInformation\>\>): void;

取消订阅信号状态变化事件，使用callback方式作为异步方法。

>**说明：**
>
>可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 信号状态变化事件，参数固定为'signalInfoChange'。              |
| callback | Callback<Array<[SignalInformation](js-apis-radio.md#signalinformation)\>\> | 否   | 回调函数。参考radio的[SignalInformation](js-apis-radio.md#signalinformation) |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)错误码。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```js
let callback = data => {
    console.log("on signalInfoChange, data:" + JSON.stringify(data));
}
observer.on('signalInfoChange', callback);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
observer.off('signalInfoChange', callback);
observer.off('signalInfoChange');
```

## observer.on('cellInfoChange')<sup>8+</sup>

on\(type: \'cellInfoChange\', callback: Callback<CellInformation\>\): void;

订阅小区信息变化事件，使用callback方式作为异步方法。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.LOCATION 和 ohos.permission.APPROXIMATELY_LOCATION

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                      | 必填 | 说明                                                         |
| -------- | --------------------------------------------------------- | ---- |------------------------------------------------------------|
| type     | string                                                    | 是   | 小区信息变化事件，固定为'cellInfoChange'。              |
| callback | Callback\<[CellInformation](js-apis-radio.md#cellinformation8)\> | 是   | 回调函数。|

**错误码：**

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```js
observer.on('cellInfoChange', data => {
    console.log("on cellInfoChange, data:" + JSON.stringify(data));
});
```


## observer.on('cellInfoChange')<sup>8+</sup>

on\(type: \'cellInfoChange\', options: { slotId: number }, callback: Callback<CellInformation\>\): void;

订阅指定卡槽位的小区信息变化事件，使用callback方式作为异步方法。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.LOCATION 和 ohos.permission.APPROXIMATELY_LOCATION

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名 | 类型                                               | 必填 | 说明                                                         |
| ------ |--------------------------------------------------| ---- |------------------------------------------------------------|
| type     | string                                           | 是   | 小区信息变化事件，固定为'cellInfoChange'。                                                   |
| slotId | number                                           | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2                              |
| callback | Callback\<[CellInformation](js-apis-radio.md#cellinformation8)\> | 是   | 回调函数。|

**错误码：**

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```js
observer.on('cellInfoChange', {slotId: 0}, data => {
    console.log("on cellInfoChange, data:" + JSON.stringify(data));
});
```


## observer.off('cellInfoChange')<sup>8+</sup>

off\(type: \'cellInfoChange\', callback?: Callback<CellInformation\>\): void;

取消订阅小区信息变化事件，使用callback方式作为异步方法。

>**说明：**
>
>可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                      | 必填 | 说明                                                         |
| -------- | --------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                    | 是   | 小区信息变化事件，固定为'cellInfoChange'。                                            |
| callback | Callback\<[CellInformation](js-apis-radio.md#cellinformation8)\> | 否   | 回调函数。|

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```js
let callback = data => {
    console.log("on cellInfoChange, data:" + JSON.stringify(data));
}
observer.on('cellInfoChange', callback);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
observer.off('cellInfoChange', callback);
observer.off('cellInfoChange');
```

## observer.on('callStateChange')

on(type: 'callStateChange', callback: Callback\<{ state: CallState, number: string }\>): void;

订阅通话状态变化事件，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------------- |
| type     | string                                                       | 是   | 通话状态变化事件，参数固定为'callStateChange'。               |
| callback | Callback\<{ state: [CallState](js-apis-call.md#callstate), number: string }\> | 是   | 回调函数，参考call的[CallState](js-apis-call.md#callstate)<br />number：电话号码 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)错误码。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```js
observer.on('callStateChange', value => {
    console.log("on callStateChange, state:" + value.state + ", number:" + value.number);
});
```


## observer.on('callStateChange')

on(type: 'callStateChange', options: { slotId: number }, callback: Callback<{ state:CallState, number: string }>): void;

订阅通话状态变化事件，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------------- |
| type     | string                                                       | 是   | 通话状态变化事件，参数固定为'callStateChange'。               |
| slotId   | number                                                       | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2                       |
| callback | Callback\<{ state: [CallState](js-apis-call.md#callstate), number: string }\> | 是   | 回调函数，参考call的[CallState](js-apis-call.md#callstate)<br />number：电话号码 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)错误码。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```js
observer.on('callStateChange', {slotId: 0}, value => {
    console.log("on callStateChange, state:" + value.state + ", number:" + value.number);
});
```


## observer.off('callStateChange')

off(type: 'callStateChange', callback?: Callback<{ state: CallState, number: string }>): void;

取消订阅通话状态变化事件，使用callback方式作为异步方法。

>**说明：**
>
>可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------------- |
| type     | string                                                       | 是   | 通话状态变化事件，参数固定为'callStateChange'。               |
| callback | Callback\<{ state: [CallState](js-apis-call.md#callstate), number: string }\> | 否   | 回调函数，参考call的[CallState](js-apis-call.md#callstate)<br />number：电话号码 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)错误码。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```js
let callback = value => {
    console.log("on callStateChange, state:" + value.state + ", number:" + value.number);
}
observer.on('callStateChange', callback);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
observer.off('callStateChange', callback);
observer.off('callStateChange');
```


## observer.on('cellularDataConnectionStateChange')<sup>7+</sup>

on\(type: 'cellularDataConnectionStateChange', callback: Callback\<{ state: DataConnectState, network: RatType}\>\): void;

订阅蜂窝数据链路连接状态，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 蜂窝数据链路连接状态事件，参数固定为'cellularDataConnectionStateChange'。|
| callback | Callback\<{ state: [DataConnectState](js-apis-telephony-data.md#dataconnectstate), network: [RatType](js-apis-radio.md#radiotechnology) }\> | 是   | 回调函数，参考data的[DataConnectState](js-apis-telephony-data.md#dataconnectstate)，radio的[RadioTechnology](js-apis-radio.md#radiotechnology)。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)错误码。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```js
observer.on('cellularDataConnectionStateChange', value => {
    console.log("on cellularDataConnectionStateChange, state:" + value.state + ", network:" + value.network);
});
```


## observer.on('cellularDataConnectionStateChange')<sup>7+</sup>

on\(type: 'cellularDataConnectionStateChange', options: { slotId: number }, callback: Callback\<{ state: DataConnectState, network: RatType }\>\): void;

订阅指定卡槽位的蜂窝数据链路连接状态，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 蜂窝数据链路连接状态事件，参数固定为'cellularDataConnectionStateChange'。|
| slotId   | number                                                       | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2                       |
| callback | Callback\<{ state: [DataConnectState](js-apis-telephony-data.md#dataconnectstate), network: [RatType](js-apis-radio.md#radiotechnology) }\> | 是   | 回调函数，参考data的[DataConnectState](js-apis-telephony-data.md#dataconnectstate)，radio的[RadioTechnology](js-apis-radio.md#radiotechnology)。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)错误码。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```js
observer.on('cellularDataConnectionStateChange', {slotId: 0}, value => {
    console.log("on cellularDataConnectionStateChange, state:" + value.state + ", network:" + value.network);
});
```


## observer.off('cellularDataConnectionStateChange')<sup>7+</sup>

off\(type: 'cellularDataConnectionStateChange',  callback?: Callback\<{ state: DataConnectState, network: RatType}\>\): void;

移除订阅蜂窝数据链路连接状态，使用callback方式作为异步方法。

>**说明：**
>
>可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 蜂窝数据链路连接状态事件，参数固定为'cellularDataConnectionStateChange'。|
| callback | Callback\<{ state: [DataConnectState](js-apis-telephony-data.md#dataconnectstate), network: [RatType](js-apis-radio.md#radiotechnology) }\> | 否   | 回调函数，参考data的[DataConnectState](js-apis-telephony-data.md#dataconnectstate)，radio的[RadioTechnology](js-apis-radio.md#radiotechnology)。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)错误码。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```js
let callback = value => {
    console.log("on cellularDataConnectionStateChange, state:" + value.state + ", network:" + value.network);
}
observer.on('cellularDataConnectionStateChange', callback);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
observer.off('cellularDataConnectionStateChange', callback);
observer.off('cellularDataConnectionStateChange');
```


## observer.on('cellularDataFlowChange')<sup>7+</sup>

on\(type: 'cellularDataFlowChange', callback: Callback\<DataFlowType\>\): void;

订阅蜂窝数据业务的上下行数据流状态，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是  | 蜂窝数据业务的上下行数据流状态状态事件，参数固定为'cellularDataFlowChange'。         |
| callback | Callback\<[DataFlowType](js-apis-telephony-data.md#dataflowtype)\> | 是   | 回调函数，参考data的[DataFlowType](js-apis-telephony-data.md#dataflowtype)。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)错误码。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```js
observer.on('cellularDataFlowChange', data => {
    console.log("on networkStateChange, data:" + JSON.stringify(data));
});
```


## observer.on('cellularDataFlowChange')<sup>7+</sup>

on\(type: 'cellularDataFlowChange', options: { slotId: number },  callback: Callback\<DataFlowType\>\): void;

订阅指定卡槽位的蜂窝数据业务的上下行数据流状态，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 蜂窝数据业务的上下行数据流状态状态事件，参数固定为'cellularDataFlowChange'。         |
| slotId   | number                                                       | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2                                             |
| callback | Callback\<[DataFlowType](js-apis-telephony-data.md#dataflowtype)\> | 是   | 回调函数，参考data的[DataFlowType](js-apis-telephony-data.md#dataflowtype)。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)错误码。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```js
observer.on('cellularDataFlowChange', {slotId: 0}, data => {
    console.log("on cellularDataFlowChange, data:" + JSON.stringify(data));
});
```


## observer.off('cellularDataFlowChange')<sup>7+</sup>

off\(type: 'cellularDataFlowChange', callback?: Callback\<DataFlowType\>\): void;

移除订阅蜂窝数据业务的上下行数据流状态，使用callback方式作为异步方法。

>**说明：**
>
>可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                                | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                             | 是   | 蜂窝数据业务的上下行数据流状态状态事件，参数固定为'cellularDataFlowChange'。   |
| callback | Callback\<[DataFlowType](js-apis-telephony-data.md#dataflowtype)\> | 否   | 回调函数，参考data的[DataFlowType](js-apis-telephony-data.md#dataflowtype)。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)错误码。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```js
let callback = data => {
    console.log("on cellularDataFlowChange, data:" + JSON.stringify(data));
}
observer.on('cellularDataFlowChange', callback);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
observer.off('cellularDataFlowChange', callback);
observer.off('cellularDataFlowChange');
```


## observer.on('simStateChange')<sup>7+</sup>

on\(type: 'simStateChange', callback: Callback\<SimStateData\>\): void;

订阅sim状态更改事件，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------------- |
| type     | string                                                       | 是   | sim状态更改事件，参数固定为'simStateChange'。                 |
| callback | Callback\<[SimStateData](#simstatedata7)\> | 是   | 回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)错误码。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```js
observer.on('simStateChange', data => {
    console.log("on simStateChange, data:" + JSON.stringify(data));
});
```


## observer.on('simStateChange')<sup>7+</sup>

on\(type: 'simStateChange', options: { slotId: number }, callback: Callback\<SimStateData\>\): void;

订阅指定卡槽位的sim状态更改事件，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | sim状态更改事件，参数固定为'simStateChange'。                 |
| slotId   | number                                                       | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2                       |
| callback | Callback\<[SimStateData](#simstatedata7)\> | 是   | 回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)错误码。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```js
observer.on('simStateChange', {slotId: 0}, data => {
    console.log("on simStateChange, data:" + JSON.stringify(data));
});
```


## observer.off('simStateChange')<sup>7+</sup>

off\(type: 'simStateChange', callback?: Callback\<SimStateData\>\): void;

移除订阅sim状态更改事件，使用callback方式作为异步方法。

>**说明：**
>
>可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | sim状态更改事件，参数固定为'simStateChange'。                 |
| callback | Callback\<[SimStateData](#simstatedata7)\> | 否   | 回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)错误码。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```js
let callback = data => {
    console.log("on simStateChange, data:" + JSON.stringify(data));
}
observer.on('simStateChange', callback);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
observer.off('simStateChange', callback);
observer.off('simStateChange');
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
