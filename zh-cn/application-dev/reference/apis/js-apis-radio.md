# 网络搜索

>**说明：**
>
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```
import radio from '@ohos.telephony.radio'
```

## radio.getRadioTech<a name=radio.getRadioTech-callback></a>

getRadioTech\(slotId: number, callback: AsyncCallback<\{psRadioTech: RadioTechnology, csRadioTech: RadioTechnology\}\>\): void

获取当前接入的CS域和PS域无线接入技术，使用callback方式作为异步方法。

需要ohos.permission.GET\_NETWORK\_INFO权限。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                   |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                                       | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback\<{psRadioTech: [RadioTechnology](#RadioTechnology), csRadioTech:[RadioTechnology](#RadioTechnology)}\> | 是   | 回调函数。                             |

**示例：**

```
let slotId = 0;
radio.getRadioTech(slotId, (err, data) =>{ 
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## radio.getRadioTech<a name=radio.getRadioTech-promise></a>

getRadioTech\(slotId: number\): Promise<\{psRadioTech: RadioTechnology, csRadioTech: RadioTechnology\}\>

获取当前接入的CS域和PS域无线接入技术，使用Promise方式作为异步方法。

需要ohos.permission.GET\_NETWORK\_INFO权限。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型                                                         | 说明                                            |
| ------------------------------------------------------------ | ----------------------------------------------- |
| Promise<{psRadioTech: [RadioTechnology](#RadioTechnology), csRadioTech: [RadioTechnology](#RadioTechnology)}> | 以Promise形式返回获取当前接入的CS域和PS域技术。 |

**示例：**

```
let slotId = 0;
let promise = radio.getRadioTech(slotId);
promise.then(data => {
    console.log(`getRadioTech success, data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getRadioTech fail, err->${JSON.stringify(err)}`);
});
```


## radio.getNetworkState<a name=radio.getNetworkState-callback1></a>

getNetworkState\(callback: AsyncCallback<NetworkState\>\): void

获取网络状态，使用callback方式作为异步方法。

需要ohos.permission.GET\_NETWORK\_INFO权限。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                           | 必填 | 说明       |
| -------- | ---------------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<[NetworkState](#NetworkState)\> | 是   | 回调函数。 |

**示例：**

```
radio.getNetworkState((err, data) =>{
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## radio.getNetworkState<a name=radio.getNetworkState-callback2></a>

getNetworkState\(slotId: number, callback: AsyncCallback<NetworkState\>\): void

获取网络状态，使用callback方式作为异步方法。

需要ohos.permission.GET\_NETWORK\_INFO权限。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                           | 必填 | 说明                                   |
| -------- | ---------------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                         | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback\<[NetworkState](#NetworkState)\> | 是   | 回调函数。                             |

**示例：**

```
let slotId = 0;
radio.getNetworkState(slotId, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## radio.getNetworkState<a name=radio.getNetworkState-promise></a>

getNetworkState\(slotId?: number\): Promise<NetworkState\>

获取网络状态，使用Promise方式作为异步方法。

需要ohos.permission.GET\_NETWORK\_INFO权限。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 否   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型                                     | 说明                        |
| ---------------------------------------- | --------------------------- |
| Promise\<[NetworkState](#NetworkState)\> | 以Promise形式返回网络状态。 |

**示例：**

```
let slotId = 0;
let promise = radio.getNetworkState(slotId);
promise.then(data => {
    console.log(`getNetworkState success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getNetworkState fail, promise: err->${JSON.stringify(err)}`);
});
```


## radio.getNetworkSelectionMode<a name=radio.getNetworkSelectionMode-callback></a>

getNetworkSelectionMode\(slotId: number, callback: AsyncCallback<NetworkSelectionMode\>\): void

获取当前选网模式，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                   |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                                       | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback\<[NetworkSelectionMode](#NetworkSelectionMode)\> | 是   | 回调函数。                             |

**示例：**

```
let slotId = 0;
radio.getNetworkSelectionMode(slotId, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## radio.getNetworkSelectionMode<a name=radio.getNetworkSelectionMode-promise></a>

getNetworkSelectionMode\(slotId: number\): Promise<NetworkSelectionMode\>

获取当前选网模式，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型                                                     | 说明                            |
| -------------------------------------------------------- | ------------------------------- |
| Promise\<[NetworkSelectionMode](#NetworkSelectionMode)\> | 以Promise形式返回当前选网模式。 |

**示例：**

```
let slotId = 0;
let promise = radio.getNetworkSelectionMode(slotId);
promise.then(data => {
    console.log(`getNetworkSelectionMode success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getNetworkSelectionMode fail, promise: err->${JSON.stringify(err)}`);
});
```


## radio.getISOCountryCodeForNetwork<sup>7+</sup><a name=radio.getISOCountryCodeForNetwork-callback></a>

getISOCountryCodeForNetwork\(slotId: number, callback: AsyncCallback<string\>\): void

获取注册网络所在国家的ISO国家码，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                     |
| -------- | ----------------------- | ---- | ---------------------------------------- |
| slotId   | number                  | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2   |
| callback | AsyncCallback\<string\> | 是   | 回调函数。返回国家码，例如：CN（中国）。 |

**示例：**

```
let slotId = 0;
radio.getISOCountryCodeForNetwork(slotId, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## radio.getISOCountryCodeForNetwork<sup>7+</sup><a name=radio.getISOCountryCodeForNetwork-promise></a>

getISOCountryCodeForNetwork\(slotId: number\): Promise<string\>

获取注册网络所在国家的ISO国家码，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| Promise\<string\> | 以Promise形式返回注册网络所在国家的ISO国家码，例如CN（中国）。 |

**示例：**

```
let slotId = 0;
let promise = radio.getISOCountryCodeForNetwork(slotId);
promise.then(data => {
    console.log(`getISOCountryCodeForNetwork success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getISOCountryCodeForNetwork fail, promise: err->${JSON.stringify(err)}`);
});
```


## radio.getSignalInformation<a name=radio.getSignalInformation-callback></a>

getSignalInformation\(slotId: number, callback: AsyncCallback<Array<SignalInformation\>\>\): void

获取指定SIM卡槽对应的注册网络信号强度信息列表，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| slotId   | number                                                       | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2                       |
| callback | AsyncCallback\<Array\<[SignalInformation](#SignalInformation)\>\> | 是   | 回调函数，返回[SignalInformation](#SignalInformation)对象的数组。 |

**示例：**

```
let slotId = 0;
radio.getSignalInformation(slotId, (err, data) => {
   console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## radio.getSignalInformation<a name=radio.getSignalInformation-promise></a>

getSignalInformation\(slotId: number\): Promise<Array<SignalInformation\>\>

获取指定SIM卡槽对应的注册网络信号强度信息列表，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<[SignalInformation](#SignalInformation)\>\> | 以Promise形式返回网络信号强度[SignalInformation](#SignalInformation)对象的数组。 |

**示例：**

```
let slotId = 0;
let promise = radio.getSignalInformation(slotId);
promise.then(data => {
    console.log(`getSignalInformation success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`getSignalInformation fail, promise: err->${JSON.stringify(err)}`);
});
```


## radio.isRadioOn<sup>7+</sup><a name=radio.isRadioOn-callback></a>

isRadioOn\(callback: AsyncCallback<boolean\>\): void

判断Radio是否打开，使用callback方式作为异步方法。

需要ohos.permission.GET\_NETWORK\_INFO权限。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                     | 必填 | 说明                                                    |
| -------- | ------------------------ | ---- | ------------------------------------------------------- |
| callback | AsyncCallback\<boolean\> | 是   | 回调函数。<br/>- true：Radio打开<br/>- false：Radio关闭 |

**示例：**

```
radio.isRadioOn((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## radio.isRadioOn<sup>7+</sup><a name=radio.isRadioOn-promise></a>

isRadioOn\(\): Promise<boolean\>

判断Radio是否打开，使用Promise方式作为异步方法。

需要ohos.permission.GET\_NETWORK\_INFO权限。

**系统能力**：SystemCapability.Telephony.CoreService

**返回值：**

| 类型               | 说明                                                         |
| ------------------ | ------------------------------------------------------------ |
| Promise\<boolean\> | 以Promise形式返回判断Radio是否打开的结果。<br/>- true：Radio打开<br/>- false：Radio关闭 |

**示例：**

```
let promise = radio.isRadioOn();
promise.then(data => {
    console.log(`isRadioOn success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`isRadioOn fail, promise: err->${JSON.stringify(err)}`);
});
```


## radio.getOperatorName<sup>7+</sup><a name=radio.getOperatorName-callback></a>

getOperatorName\(slotId: number, callback: AsyncCallback<string\>\): void

获取运营商名称，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                       |
| -------- | ----------------------- | ---- | ------------------------------------------ |
| slotId   | number                  | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2     |
| callback | AsyncCallback\<string\> | 是   | 回调函数。返回运营商名称，例如：中国移动。 |

**示例：**

```
let slotId = 0;
radio.getOperatorName(slotId, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## radio.getOperatorName<sup>7+</sup><a name=radio.getOperatorName-promise></a>

getOperatorName\(slotId: number\): Promise<string\>

获取运营商名称，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| Promise\<string\> | 以Promise形式返回运营商名称，例如：中国移动。                |

**示例：**

```
let slotId = 0;
let promise = radio.getOperatorName(slotId);
promise.then(data => {
    console.log(`getOperatorName success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getOperatorName fail, promise: err->${JSON.stringify(err)}`);
});
```


## RadioTechnology<a name=RadioTechnology></a>

无线接入技术。

| 变量                      | 值   | 说明                                                         |
| ------------------------- | ---- | ------------------------------------------------------------ |
| RADIO_TECHNOLOGY_UNKNOWN  | 0    | 未知无线接入技术（RAT）。<br>**系统能力**：SystemCapability.Telephony.CoreService |
| RADIO_TECHNOLOGY_GSM      | 1    | 无线接入技术GSM（Global System For Mobile Communication）。<br/>**系统能力**：SystemCapability.Telephony.CoreService |
| RADIO_TECHNOLOGY_1XRTT    | 2    | 无线接入技术1XRTT（Single-Carrier Radio Transmission Technology）。<br/>**系统能力**：SystemCapability.Telephony.CoreService |
| RADIO_TECHNOLOGY_WCDMA    | 3    | 无线接入技术WCDMA（Wideband Code Division Multiple Access）。<br/>**系统能力**：SystemCapability.Telephony.CoreService |
| RADIO_TECHNOLOGY_HSPA     | 4    | 无线接入技术HSPA（High Speed Packet Access）。<br/>**系统能力**：SystemCapability.Telephony.CoreService |
| RADIO_TECHNOLOGY_HSPAP    | 5    | 无线接入技术HSPAP（High Speed packet access (HSPA+) ）。<br/>**系统能力**：SystemCapability.Telephony.CoreService |
| RADIO_TECHNOLOGY_TD_SCDMA | 6    | 无线接入技术TDSCDMA（TimeDivision-Synchronous Code Division Multiple Access）。<br/>**系统能力**：SystemCapability.Telephony.CoreService |
| RADIO_TECHNOLOGY_EVDO     | 7    | 无线接入技术EVDO（Evolution、Data Only）。<br/>**系统能力**：SystemCapability.Telephony.CoreService |
| RADIO_TECHNOLOGY_EHRPD    | 8    | 无线接入技术EHRPD（Evolved High Rate Package Data）。<br/>**系统能力**：SystemCapability.Telephony.CoreService |
| RADIO_TECHNOLOGY_LTE      | 9    | 无线接入技术LTE（Long Term Evolution）。<br/>**系统能力**：SystemCapability.Telephony.CoreService |
| RADIO_TECHNOLOGY_LTE_CA   | 10   | 无线接入技术LTE_CA（Long Term Evolution_Carrier Aggregation）。<br/>**系统能力**：SystemCapability.Telephony.CoreService |
| RADIO_TECHNOLOGY_IWLAN    | 11   | 无线接入技术IWLAN（Industrial Wireless LAN）。<br/>**系统能力**：SystemCapability.Telephony.CoreService |
| RADIO_TECHNOLOGY_NR       | 12   | 无线接入技术NR（New Radio）。<br/>**系统能力**：SystemCapability.Telephony.CoreService |


## SignalInformation<a name=SignalInformation></a>

网络信号强度信息对象。

| 属性名      | 类型                        | 说明                                                         |
| ----------- | --------------------------- | ------------------------------------------------------------ |
| signalType  | [NetworkType](#NetworkType) | 网络信号强度类型。<br/>**系统能力**：SystemCapability.Telephony.CoreService |
| signalLevel | number                      | 网络信号强度等级。<br/>**系统能力**：SystemCapability.Telephony.CoreService |


## NetworkType<a name=NetworkType></a>

网络类型。

| 变量                 | 值   | 说明                                                         |
| -------------------- | ---- | ------------------------------------------------------------ |
| NETWORK_TYPE_UNKNOWN | 0    | 未知网络类型。<br/>**系统能力**：SystemCapability.Telephony.CoreService |
| NETWORK_TYPE_GSM     | 1    | 网络类型为GSM（Global System For Mobile Communication）。<br/>**系统能力**：SystemCapability.Telephony.CoreService |
| NETWORK_TYPE_CDMA    | 2    | 网络类型为CDMA（Code Division Multiple Access）。<br/>**系统能力**：SystemCapability.Telephony.CoreService |
| NETWORK_TYPE_WCDMA   | 3    | 网络类型为WCDMA（Wideband Code Division Multiple Access）。<br/>**系统能力**：SystemCapability.Telephony.CoreService |
| NETWORK_TYPE_TDSCDMA | 4    | 网络类型为TDSCDMA（TimeDivision-Synchronous Code Division Multiple Access）。<br/>**系统能力**：SystemCapability.Telephony.CoreService |
| NETWORK_TYPE_LTE     | 5    | 网络类型为LTE（Long Term Evolution）。<br/>**系统能力**：SystemCapability.Telephony.CoreService |
| NETWORK_TYPE_NR      | 6    | 网络类型为5G NR（New Radio）。<br/>**系统能力**：SystemCapability.Telephony.CoreService |

## NetworkState<a name=NetworkState></a>

网络注册状态。

| 变量              | 类型                  | 说明                                                         |
| ----------------- | --------------------- | ------------------------------------------------------------ |
| longOperatorName  | string                | 注册网络的长运营商名称。<br/>**系统能力**：SystemCapability.Telephony.CoreService |
| shortOperatorName | string                | 注册网络的短运营商名称。<br/>**系统能力**：SystemCapability.Telephony.CoreService |
| plmnNumeric       | string                | 注册网络的PLMN码。<br/>**系统能力**：SystemCapability.Telephony.CoreService |
| isRoaming         | boolean               | 是否处于漫游状态。<br/>**系统能力**：SystemCapability.Telephony.CoreService |
| regState          | [RegState](#RegState) | 设备的网络注册状态。<br/>**系统能力**：SystemCapability.Telephony.CoreService |
| nsaState          | [NsaState](#NsaState) | 设备的NSA网络注册状态。<br/>**系统能力**：SystemCapability.Telephony.CoreService |
| isCaActive        | boolean               | CA的状态。<br/>**系统能力**：SystemCapability.Telephony.CoreService |
| isEmergency       | boolean               | 此设备是否只允许拨打紧急呼叫。<br/>**系统能力**：SystemCapability.Telephony.CoreService |


## RegState<a name=RegState></a>

网络注册状态。

| 变量                          | 值   | 说明                                                         |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| REG_STATE_NO_SERVICE          | 0    | 设备不能使用任何服务。<br/>**系统能力**：SystemCapability.Telephony.CoreService |
| REG_STATE_IN_SERVICE          | 1    | 设备可以正常使用业务。<br/>**系统能力**：SystemCapability.Telephony.CoreService |
| REG_STATE_EMERGENCY_CALL_ONLY | 2    | 设备只能使用紧急呼叫业务。<br/>**系统能力**：SystemCapability.Telephony.CoreService |
| REG_STATE_POWER_OFF           | 3    | 蜂窝无线电已关闭。<br/>**系统能力**：SystemCapability.Telephony.CoreService |


## NsaState<a name=NsaState></a>

非独立组网状态。

| 变量                       | 值   | 说明                                                         |
| -------------------------- | ---- | ------------------------------------------------------------ |
| NSA_STATE_NOT_SUPPORT      | 1    | 设备在不支持NSA的LTE小区下处于空闲状态或连接状态。<br/>**系统能力**：SystemCapability.Telephony.CoreService |
| NSA_STATE_NO_DETECT        | 2    | 在支持NSA但不支持NR覆盖检测的LTE小区下，设备处于空闲状态。<br/>**系统能力**：SystemCapability.Telephony.CoreService |
| NSA_STATE_CONNECTED_DETECT | 3    | 设备在LTE小区下连接到LTE网络支持NSA和NR覆盖检测。<br/>**系统能力**：SystemCapability.Telephony.CoreService |
| NSA_STATE_IDLE_DETECT      | 4    | 支持NSA和NR覆盖检测的LTE小区下设备处于空闲状态。<br/>**系统能力**：SystemCapability.Telephony.CoreService |
| NSA_STATE_DUAL_CONNECTED   | 5    | 设备在支持NSA的LTE小区下连接到LTE + NR网络。<br/>**系统能力**：SystemCapability.Telephony.CoreService |
| NSA_STATE_SA_ATTACHED      | 6    | 设备在5GC附着时在NG-RAN小区下空闲或连接到NG-RAN小区。<br/>**系统能力**：SystemCapability.Telephony.CoreService |


## NetworkSelectionMode<a name=NetworkSelectionMode></a>

选网模式。

| 变量                        | 值   | 说明                                                         |
| --------------------------- | ---- | ------------------------------------------------------------ |
| NETWORK_SELECTION_UNKNOWN   | 0    | 未知选网模式。<br/>**系统能力**：SystemCapability.Telephony.CoreService |
| NETWORK_SELECTION_AUTOMATIC | 1    | 自动选网模式。<br/>**系统能力**：SystemCapability.Telephony.CoreService |
| NETWORK_SELECTION_MANUAL    | 2    | 手动选网模式。<br/>**系统能力**：SystemCapability.Telephony.CoreService |

