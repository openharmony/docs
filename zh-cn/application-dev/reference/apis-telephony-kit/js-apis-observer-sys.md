# @ohos.telephony.observer (observer)（系统接口）

本模块提供订阅管理功能，可以订阅/取消订阅的事件包括：小区信息变化事件、指定卡槽位的小区信息变化事件。

>**说明：**
>
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
>当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.telephony.observer (observer)](js-apis-observer.md)

## 导入模块

```ts
import { observer } from '@kit.TelephonyKit';
```


## observer.on('cellInfoChange')<sup>8+</sup>

on\(type: \'cellInfoChange\', callback: Callback\<Array\<CellInformation\>\>\): void

订阅小区信息变化事件，使用callback方式作为异步方法。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.LOCATION 和 ohos.permission.APPROXIMATELY_LOCATION

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名   | 类型                                                      | 必填 | 说明                                      |
| -------- | --------------------------------------------------------- | ---- |------------------------------------------|
| type     | string                                                    | 是   | 小区信息变化事件，固定为'cellInfoChange'。 |
| callback | Callback\<Array\<[CellInformation](js-apis-radio.md#cellinformation8)\>\> | 是   | 以callback形式异步返回结果。                |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
import { radio } from '@kit.TelephonyKit';

observer.on('cellInfoChange', (data: Array<radio.CellInformation>) => {
    console.log("on cellInfoChange, data:" + JSON.stringify(data));
});
```


## observer.on('cellInfoChange')<sup>8+</sup>

on\(type: \'cellInfoChange\', options: ObserverOptions, callback: Callback\<Array\<CellInformation\>\>\): void

订阅指定卡槽位的小区信息变化事件，使用callback方式作为异步方法。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.LOCATION 和 ohos.permission.APPROXIMATELY_LOCATION

**系统能力**：SystemCapability.Telephony.StateRegistry

**参数：**

| 参数名 | 类型                                               | 必填 | 说明                                      |
| ------ |--------------------------------------------------| ---- |--------------------------------------------|
| type     | string                                           | 是   | 小区信息变化事件，固定为'cellInfoChange'。 |
| options  | [ObserverOptions](js-apis-observer.md#observeroptions11)            | 是   | 电话相关事件订阅参数可选项。                |
| callback | Callback\<Array\<[CellInformation](js-apis-radio.md#cellinformation8)\>\> | 是   | 以callback形式异步返回结果。       |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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
observer.on('cellInfoChange', options, (data: Array<radio.CellInformation>) => {
    console.log("on cellInfoChange, data:" + JSON.stringify(data));
});
```


## observer.off('cellInfoChange')<sup>8+</sup>

off\(type: \'cellInfoChange\', callback?: Callback\<Array\<CellInformation\>\>\): void

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
| callback | Callback\<Array\<[CellInformation](js-apis-radio.md#cellinformation8)\>\> | 否   | 以callback形式异步返回结果。|

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
import { radio } from '@kit.TelephonyKit';

let callback: (data: Array<radio.CellInformation>) => void = (data: Array<radio.CellInformation>) => {
    console.log("on cellInfoChange, data:" + JSON.stringify(data));
}
observer.on('cellInfoChange', callback);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
observer.off('cellInfoChange', callback);
observer.off('cellInfoChange');
```

