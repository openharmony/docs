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
