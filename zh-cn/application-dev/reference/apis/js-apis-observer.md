# observer

>**说明：**
>
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```
import observer from '@ohos.telephony.observer'
```

## observer.on('networkStateChange')<a name=observer.on.networkStateChange-callback></a>

on\(type: \'networkStateChange\', callback: Callback<NetworkState\>\): void;

订阅网络状态变化事件，使用callback方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                              |
| -------- | ----------------------------------------- | ---- | --------------------------------- |
| type     | string                                    | 是   | 网络状态变化事件                  |
| callback | Callback\<[NetworkState](js-apis-radio.md#NetworkState)\> | 是   | 回调函数。参考radio的[NetworkState](js-apis-radio.md#NetworkState) |

**示例：**

```
observer.on('networkStateChange', data =>{ 
    console.log("on networkStateChange, data:" + JSON.stringify(data));
});
```


## observer.on('networkStateChange')<a name=observer.on.networkStateChange.options-callback></a>

on\(type: \'networkStateChange\', options: { slotId: number }, callback: Callback<NetworkState\>\): void;

订阅指定卡槽位的网络状态变化事件，使用callback方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| type     | string                                    | 是   | 网络状态变化事件                  |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | Callback\<[NetworkState](js-apis-radio.md#NetworkState)\> | 是   | 回调函数。参考radio的[NetworkState](js-apis-radio.md#NetworkState) |

**示例：**

```
observer.on('networkStateChange', {slotId: 0}, data =>{ 
    console.log("on networkStateChange, data:" + JSON.stringify(data));
});
```


## observer.off('networkStateChange')<a name=observer.off.networkStateChange-callback></a>

off\(type: \'networkStateChange\', callback?: Callback<NetworkState\>\): void;

取消订阅网络状态变化事件，使用callback方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO。

>**说明：**
>
>可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                     | 必填 | 说明                              |
| -------- | ------------------------ | ---- | --------------------------------- |
| type     | string                   | 是   | 网络状态变化事件                  |
| callback | Callback\<[NetworkState](js-apis-radio.md#NetworkState)\> | 否   | 回调函数。参考radio的[NetworkState](js-apis-radio.md#NetworkState) |

**示例：**

```
let callback = data => {
    console.log("on networkStateChange, data:" + JSON.stringify(data));
}
observer.on('networkStateChange', callback);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
observer.off('networkStateChange', callback);
observer.off('networkStateChange');
```

## observer.on('signalInfoChange')<a name=observer.on.signalInfoChange-callback></a>

on\(type: \'signalInfoChange\', callback: Callback<Array<SignalInformation\>\>): void;

订阅信号状态变化事件，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 信号状态变化事件                                             |
| callback | Callback<Array<[SignalInformation](js-apis-radio.md#SignalInformation)\>\> | 是   | 回调函数。参考radio的[SignalInformation](js-apis-radio.md#SignalInformation) |

**示例：**

```
observer.on('signalInfoChange', data =>{ 
    console.log("on signalInfoChange, data:" + JSON.stringify(data));
});
```


## observer.on('signalInfoChange')<a name=observer.on.signalInfoChange.options-callback></a>

on\(type: \'signalInfoChange\', options: { slotId: number }, callback: Callback<Array<SignalInformation\>\>): void;

订阅指定卡槽位的信号状态变化事件，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| type     | string                                    | 是   | 信号状态变化事件                |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | Callback<Array<[SignalInformation](js-apis-radio.md#SignalInformation)\>\> | 是   | 回调函数。参考radio的[SignalInformation](js-apis-radio.md#SignalInformation) |

**示例：**

```
observer.on('signalInfoChange', {slotId: 0}, data =>{ 
    console.log("on signalInfoChange, data:" + JSON.stringify(data));
});
```


## observer.off('signalInfoChange')<a name=observer.off.signalInfoChange-callback></a>

off\(type: \'signalInfoChange\', callback?: Callback<Array<SignalInformation\>\>): void;

取消订阅信号状态变化事件，使用callback方式作为异步方法。

>**说明：**
>
>可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 信号状态变化事件                                             |
| callback | Callback<Array<[SignalInformation](js-apis-radio.md#SignalInformation)\>\> | 否   | 回调函数。参考radio的[SignalInformation](js-apis-radio.md#SignalInformation) |

**示例：**

```
let callback = data => {
    console.log("on signalInfoChange, data:" + JSON.stringify(data));
}
observer.on('signalInfoChange', callback);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
observer.off('signalInfoChange', callback);
observer.off('signalInfoChange');
```


## observer.on('callStateChange')<a name=observer.on.callStateChange-callback></a>

on(type: 'callStateChange', callback: Callback\<{ state: [CallState](js-apis-call.md#CallState), number: string }\>): void;

订阅通话状态变化事件，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CALL_LOG

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 通话状态变化事件                                             |
| callback | Callback\<{ state: [CallState](js-apis-call.md#CallState), number: string }\> | 是   | 回调函数，参考call的[CallState](js-apis-call.md#CallState)<br />number：电话号码 |

**示例：**

```
observer.on('callStateChange', value =>{ 
    console.log("on callStateChange, state:" + value.state + ", number:" + value.number);
});
```


## observer.on('callStateChange')<a name=observer.on.callStateChange.options-callback></a>

on(type: 'callStateChange', options: { slotId: number }, callback: Callback<{ state: [CallState](js-apis-call.md#CallState), number: string }>): void;

订阅通话状态变化事件，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CALL_LOG

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 通话状态变化事件                                             |
| slotId   | number                                                       | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2                       |
| callback | Callback\<{ state: [CallState](js-apis-call.md#CallState), number: string }\> | 是   | 回调函数，参考call的[CallState](js-apis-call.md#CallState)<br />number：电话号码 |

**示例：**

```
observer.on('callStateChange', {slotId: 0}, value =>{ 
    console.log("on callStateChange, state:" + value.state + ", number:" + value.number);
});
```


## observer.off('callStateChange')<a name=observer.off.callStateChange-callback></a>

off(type: 'callStateChange', callback?: Callback<{ state: [CallState](js-apis-call.md#CallState), number: string }>): void;

取消订阅通话状态变化事件，使用callback方式作为异步方法。

**需要权限**：ohos.permission.READ_CALL_LOG

>**说明：**
>
>可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 通话状态变化事件                                             |
| callback | Callback\<{ state: [CallState](js-apis-call.md#CallState), number: string }\> | 否   | 回调函数，参考call的[CallState](js-apis-call.md#CallState)<br />number：电话号码 |

**示例：**

```
let callback = value => {
    console.log("on callStateChange, state:" + value.state + ", number:" + value.number);
}
observer.on('callStateChange', callback);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
observer.off('callStateChange', callback);
observer.off('callStateChange');
```


## observer.on('cellularDataConnectionStateChange')<sup>7+</sup><a name=observer.on.cellularDataConnectionStateChange-callback></a>

on\(type: 'cellularDataConnectionStateChange', callback: Callback\<{ state: DataConnectState, network: RadioTechnology }\>\): void;

订阅蜂窝数据链路连接状态，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 蜂窝数据链路连接状态事件                                     |
| callback | Callback\<{ state: [DataConnectState](js-apis-telephony-data.md#DataConnectState), network: [RadioTechnology](js-apis-radio.md#RadioTechnology) }\> | 是   | 回调函数，参考data的[DataConnectState](js-apis-telephony-data.md#DataConnectState)，radio的[RadioTechnology](js-apis-radio.md#RadioTechnology)。 |

**示例：**

```
observer.on('cellularDataConnectionStateChange', value =>{
    console.log("on cellularDataConnectionStateChange, state:" + value.state + ", network:" + value.network);
});
```


## observer.on('cellularDataConnectionStateChange')<sup>7+</sup><a name=observer.on.cellularDataConnectionStateChange.options-callback></a>

on\(type: 'cellularDataConnectionStateChange', options: { slotId: number }, callback: Callback\<{ state: DataConnectState, network: RadioTechnology }\>\): void;

订阅指定卡槽位的蜂窝数据链路连接状态，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 蜂窝数据链路连接状态事件                                     |
| slotId   | number                                                       | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2                       |
| callback | Callback\<{ state: [DataConnectState](js-apis-telephony-data.md#DataConnectState), network: [RadioTechnology](js-apis-radio.md#RadioTechnology) }\> | 是   | 回调函数，参考data的[DataConnectState](js-apis-telephony-data.md#DataConnectState)，radio的[RadioTechnology](js-apis-radio.md#RadioTechnology)。 |

**示例：**

```
observer.on('cellularDataConnectionStateChange', {slotId: 0}, value =>{
    console.log("on cellularDataConnectionStateChange, state:" + value.state + ", network:" + value.network);
});
```


## observer.off('cellularDataConnectionStateChange')<sup>7+</sup><a name=observer.off.cellularDataConnectionStateChange-callback></a>

off\(type: 'cellularDataConnectionStateChange',  callback?: Callback\<{ state: DataConnectState, network: RadioTechnology }\>\): void;

移除订阅蜂窝数据链路连接状态，使用callback方式作为异步方法。

>**说明：**
>
>可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 蜂窝数据链路连接状态事件                                     |
| callback | Callback\<{ state: [DataConnectState](js-apis-telephony-data.md#DataConnectState), network: [RadioTechnology](js-apis-radio.md#RadioTechnology) }\> | 否   | 回调函数，参考data的[DataConnectState](js-apis-telephony-data.md#DataConnectState)，radio的[RadioTechnology](js-apis-radio.md#RadioTechnology)。 |

**示例：**

```
let callback = value => {
    console.log("on cellularDataConnectionStateChange, state:" + value.state + ", network:" + value.network);
}
observer.on('cellularDataConnectionStateChange', callback);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
observer.off('cellularDataConnectionStateChange', callback);
observer.off('cellularDataConnectionStateChange');
```


## observer.on('cellularDataFlowChange')<sup>7+</sup><a name=observer.on.cellularDataFlowChange-callback></a>

on\(type: 'cellularDataFlowChange', callback: Callback\<DataFlowType\>\): void;

订阅蜂窝数据业务的上下行数据流状态，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 蜂窝数据业务的上下行数据流状态状态事件                                     |
| callback | Callback\<[DataFlowType](js-apis-telephony-data.md#DataFlowType)\> | 是   | 回调函数，参考data的[DataFlowType](js-apis-telephony-data.md#DataFlowType)。 |

**示例：**

```
observer.on('cellularDataFlowChange', data =>{
    console.log("on networkStateChange, data:" + JSON.stringify(data));
});
```


## observer.on('cellularDataFlowChange')<sup>7+</sup><a name=observer.on.cellularDataFlowChange.options-callback></a>

on\(type: 'cellularDataFlowChange', options: { slotId: number },  callback: Callback\<DataFlowType\>\): void;

订阅指定卡槽位的蜂窝数据业务的上下行数据流状态，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 蜂窝数据业务的上下行数据流状态事件                                     |
| slotId   | number                                                       | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2                       |
| callback | Callback\<[DataFlowType](js-apis-telephony-data.md#DataFlowType)\> | 是   | 回调函数，参考data的[DataFlowType](js-apis-telephony-data.md#DataFlowType)。 |

**示例：**

```
observer.on('cellularDataFlowChange', {slotId: 0}, data =>{
    console.log("on cellularDataFlowChange, data:" + JSON.stringify(data));
});
```


## observer.off('cellularDataFlowChange')<sup>7+</sup><a name=observer.off.cellularDataFlowChange-callback></a>

off\(type: 'cellularDataFlowChange', callback?: Callback\<DataFlowType\>\): void;

移除订阅蜂窝数据业务的上下行数据流状态，使用callback方式作为异步方法。

>**说明：**
>
>可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 蜂窝数据业务的上下行数据流状态事件                                             |
| callback | Callback\<[DataFlowType](js-apis-telephony-data.md#DataFlowType)\> | 否   | 回调函数，参考data的[DataFlowType](js-apis-telephony-data.md#DataFlowType)。 |

**示例：**

```
let callback = data => {
    console.log("on cellularDataFlowChange, data:" + JSON.stringify(data));
}
observer.on('cellularDataFlowChange', callback);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
observer.off('cellularDataFlowChange', callback);
observer.off('cellularDataFlowChange');
```


## observer.on('simStateChange')<sup>7+</sup><a name=observer.on.simStateChange-callback></a>

on\(type: 'simStateChange', callback: Callback\<SimStateData\>\): void;

订阅sim状态更改事件，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | sim状态更改事件                                     |
| callback | Callback\<[SimStateData](#simstatedata7)\> | 是   | 回调函数。 |

**示例：**

```
observer.on('simStateChange', data =>{
    console.log("on simStateChange, data:" + JSON.stringify(data));
});
```


## observer.on('simStateChange')<sup>7+</sup><a name=observer.on.simStateChange.options-callback></a>

on\(type: 'simStateChange', options: { slotId: number }, callback: Callback\<SimStateData\>\): void;

订阅指定卡槽位的sim状态更改事件，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | sim状态更改事件                                     |
| slotId   | number                                                       | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2                       |
| callback | Callback\<[SimStateData](#simstatedata7)\> | 是   | 回调函数。 |

**示例：**

```
observer.on('simStateChange', {slotId: 0}, data =>{
    console.log("on simStateChange, data:" + JSON.stringify(data));
});
```


## observer.off('simStateChange')<sup>7+</sup><a name=observer.off.simStateChange-callback></a>

off\(type: 'simStateChange', callback?: Callback\<SimStateData\>\): void;

移除订阅sim状态更改事件，使用callback方式作为异步方法。

>**说明：**
>
>可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | sim状态更改事件                                             |
| callback | Callback\<[SimStateData](#simstatedata7)\> | 否   | 回调函数。 |

**示例：**

```
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

| 变量        | 值   | 说明                                                         |
| ----------- | ---- | ------------------------------------------------------------ |
| SIM_NONE    | 0    | 无锁。<br/>**系统能力**：SystemCapability.Telephony.StateRegistry |
| SIM_PIN     | 1    | PIN锁。<br/>**系统能力**：SystemCapability.Telephony.StateRegistry |
| SIM_PUK     | 2    | PUK锁。<br/>**系统能力**：SystemCapability.Telephony.StateRegistry |
| SIM_PN_PIN  | 3    | 网络PIN锁。<br/>**系统能力**：SystemCapability.Telephony.StateRegistry |
| SIM_PN_PUK  | 4    | 网络PUK锁。<br/>**系统能力**：SystemCapability.Telephony.StateRegistry |
| SIM_PU_PIN  | 5    | 子网PIN锁。<br/>**系统能力**：SystemCapability.Telephony.StateRegistry |
| SIM_PU_PUK  | 6    | 子网PUK锁。<br/>**系统能力**：SystemCapability.Telephony.StateRegistry |
| SIM_PP_PIN  | 7    | 服务提供商PIN锁。<br/>**系统能力**：SystemCapability.Telephony.StateRegistry |
| SIM_PP_PUK  | 8    | 服务提供商PUK锁。<br/>**系统能力**：SystemCapability.Telephony.StateRegistry |
| SIM_PC_PIN  | 9    | 组织PIN锁。<br/>**系统能力**：SystemCapability.Telephony.StateRegistry |
| SIM_PC_PUK  | 10   | 组织PUK锁。<br/>**系统能力**：SystemCapability.Telephony.StateRegistry |
| SIM_SIM_PIN | 11   | SIM PIN锁。<br/>**系统能力**：SystemCapability.Telephony.StateRegistry |
| SIM_SIM_PUK | 12   | SIM PUK锁。<br/>**系统能力**：SystemCapability.Telephony.StateRegistry |


## SimStateData<sup>7+</sup>

SIM卡类型和状态。

| 变量              | 类型                  | 说明                                                         |
| ----------------- | --------------------- | ------------------------------------------------------------ |
| type  | [CardType](js-apis-sim.md#cardtype) | SIM卡类型，参考sim的[CardType](js-apis-sim.md#cardtype)。<br/>**系统能力**：SystemCapability.Telephony.StateRegistry |
| state | [SimState](js-apis-sim.md#SimState) | SIM卡状态，参考sim的[SimState](js-apis-sim.md#SimState)。<br/>**系统能力**：SystemCapability.Telephony.StateRegistry |
| reason<sup>8+</sup>       | [LockReason](#lockreason8) | SIM卡锁类型。<br/>**系统能力**：SystemCapability.Telephony.StateRegistry |

