# 短信服务

>**说明：** 
>
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```
import sms from '@ohos.telephony.sms';
```

## sms.createMessage<a name=sms.createMessage-callback></a>

createMessage\(pdu: Array<number\>, specification: string, callback: AsyncCallback<ShortMessage\>\): void

根据协议数据单元（PDU）和指定的短信协议创建短信实例，使用callback方式作为异步方法。

- 参数

  | 参数名        | 类型                                               | 必填 | 说明                                                         |
  | ------------- | -------------------------------------------------- | ---- | ------------------------------------------------------------ |
  | pdu           | Array&lt;number&gt;                                | 是   | 协议数据单元，从收到的信息中获取。                           |
  | specification | string                                             | 是   | 短信协议类型。<br/>- 3gpp表示GSM/UMTS/LTE SMS<br/>- 3gpp2表示CDMA SMS |
  | callback      | AsyncCallback&lt;[ShortMessage](#ShortMessage)&gt; | 是   | 回调函数。                                                   |

-   示例

    ```
    let specification = '3gpp';
    let pdu = [0x08, 0x91, ...];
    sms.createMessage(pdu, specification, (err, data) => {
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## sms.createMessage<a name=sms.createMessage-promise></a>

createMessage\(pdu: Array<number\>, specification: string\): Promise<ShortMessage\>

根据协议数据单元（PDU）和指定的短信协议创建短信实例，使用Promise方式作为异步方法。

- 参数

  | 参数名        | 类型                | 必填 | 说明                                                         |
  | ------------- | ------------------- | ---- | ------------------------------------------------------------ |
  | pdu           | Array&lt;number&gt; | 是   | 协议数据单元，从收到的信息中获取。                           |
  | specification | string              | 是   | 短信协议类型。<br/>- 3gpp表示GSM/UMTS/LTE SMS<br/>- 3gpp2表示CDMA SMS |

- 返回值

  | 类型                                         | 说明                              |
  | -------------------------------------------- | --------------------------------- |
  | Promise&lt;[ShortMessage](#ShortMessage)&gt; | 以Promise形式返回创建的短信实例。 |

-   示例

    ```
    let specification = '3gpp';
    let pdu = [0x08, 0x91, ...];
    let promise = sms.createMessage(pdu, specification);
    promise.then(data => {
        console.log(`createMessage success, promise: data->${JSON.stringify(data)}`);
    }).catch(err => {
        console.error(`createMessage fail, promise: err->${JSON.stringify(err)}`);
    });
    ```

## sms.sendMessage

sendMessage(options: SendMessageOptions): void

发送短信。

需要ohos.permission.SEND_MESSAGES权限。

- 参数

  | 参数名  | 类型                                      | 必填 | 说明                                                         |
  | ------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
  | options | [SendMessageOptions](#SendMessageOptions) | 是   | 发送短信的参数和回调，参考[SendMessageOptions](#SendMessageOptions)。 |

- 示例

  ```
  let sendCallback = function (err, data) {    
      console.log(`sendCallback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`); 
  }
  let deliveryCallback = function (err, data) {    
      console.log(`deliveryCallback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`); 
  }
  let slotId = 0;
  let content = '短信内容';
  let destinationHost = '+861xxxxxxxxxx';
  let serviceCenter = '+861xxxxxxxxxx';
  let destinationPort = 1000;
  let options = {slotId, content, destinationHost, serviceCenter, destinationPort, sendCallback, deliveryCallback};
  sms.sendMessage(options);
  ```


## sms.getDefaultSmsSlotId<sup>7+</sup><a name=sms.getDefaultSmsSlotId-callback></a>

getDefaultSmsSlotId\(callback: AsyncCallback<number\>\): void

获取发送短信的默认SIM卡槽ID，使用callback方式作为异步方法。

- 参数

  | 参数名   | 类型                        | 必填 | 说明                                     |
  | -------- | --------------------------- | ---- | ---------------------------------------- |
  | callback | AsyncCallback&lt;number&gt; | 是   | 回调函数。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

-   示例

    ```
    sms.getDefaultSmsSlotId((err, data) => {
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## sms.getDefaultSmsSlotId<sup>7+</sup><a name=sms.getDefaultSmsSlotId-promise></a>

getDefaultSmsSlotId\(\): Promise<number\>

获取发送短信的默认SIM卡槽ID，使用Promise方式作为异步方法。

- 返回值

  | 类型            | 说明                                                         |
  | --------------- | ------------------------------------------------------------ |
  | Promise<number> | 以Promise形式返回发送短信的默认SIM卡：<br/>- 0：卡槽1<br/>- 1：卡槽2 |

-   示例

    ```
    let promise = call.getDefaultSmsSlotId();
    promise.then(data => {
        console.log(`getDefaultSmsSlotId success, promise: data->${JSON.stringify(data)}`);
    }).catch(err => {
        console.error(`getDefaultSmsSlotId fail, promise: err->${JSON.stringify(err)}`);
    });
    ```


## sms.setSmscAddr<sup>7+</sup><a name=sms.setSmscAddr-callback></a>

setSmscAddr\(slotId: number, smscAddr: string, callback: AsyncCallback<void\>\): void

设置短信服务中心（SMSC）地址，使用callback方式作为异步方法。

需要ohos.permission.SET\_TELEPHONY\_STATE权限，该权限为系统权限。

- 参数

  | 参数名   | 类型                      | 必填 | 说明                                      |
  | -------- | ------------------------- | ---- | ----------------------------------------- |
  | slotId   | number                    | 是   | SIM卡槽ID：<br/>- 0：卡槽1<br/>- 1：卡槽2 |
  | smscAddr | string                    | 是   | 短信服务中心地址。                        |
  | callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。                                |

-   示例

    ```
    let slotId = 0;
    let smscAddr = '+861xxxxxxxxxx';
    sms.setSmscAddr(slotId, smscAddr, (err,data) => {
          console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## sms.setSmscAddr<sup>7+</sup><a name=sms.setSmscAddr-promise></a>

setSmscAddr\(slotId: number, smscAddr: string\): Promise<void\>

设置短信服务中心（SMSC）地址，使用Promise方式作为异步方法。

需要ohos.permission.SET\_TELEPHONY\_STATE权限，该权限为系统权限。

- 参数

  | 参数名   | 类型   | 必填 | 说明                                      |
  | -------- | ------ | ---- | ----------------------------------------- |
  | slotId   | number | 是   | SIM卡槽ID：<br/>- 0：卡槽1<br/>- 1：卡槽2 |
  | smscAddr | string | 是   | 短信服务中心地址。                        |

- 返回值

  | 类型                | 说明                            |
  | ------------------- | ------------------------------- |
  | Promise&lt;void&gt; | 以Promise形式异步返回设置结果。 |

-   示例

    ```
    let slotId = 0;
    let smscAddr = '+861xxxxxxxxxx';
    let promise = sms.setSmscAddr(slotId, smscAddr);
    promise.then(data => {
        console.log(`setSmscAddr success, promise: data->${JSON.stringify(data)}`);
    }).catch(err => {
        console.error(`setSmscAddr fail, promise: err->${JSON.stringify(err)}`);
    });
    ```


## sms.getSmscAddr<sup>7+</sup><a name=sms.getSmscAddr-callback></a>

getSmscAddr\(slotId: number, callback: AsyncCallback<string\>\): void

获取短信服务中心（SMSC）地址，使用callback方式作为异步方法。

需要ohos.permission.GET\_TELEPHONY\_STATE权限，该权限为系统权限。

- 参数

  | 参数名   | 类型                        | 必填 | 说明                                      |
  | -------- | --------------------------- | ---- | ----------------------------------------- |
  | slotId   | number                      | 是   | SIM卡槽ID：<br/>- 0：卡槽1<br/>- 1：卡槽2 |
  | callback | AsyncCallback&lt;string&gt; | 是   | 回调函数。                                |

-   示例

    ```
    let slotId = 0;
    sms.getSmscAddr(slotId, (err, data) => {
          console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## sms.getSmscAddr<sup>7+</sup><a name=sms.getSmscAddr-promise></a>

getSmscAddr\(slotId: number\): Promise<string\>

获取短信服务中心（SMSC）地址，使用Promise方式作为异步方法。

需要ohos.permission.GET\_TELEPHONY\_STATE权限，该权限为系统权限。

- 参数

  | 参数名 | 类型   | 必填 | 说明                                      |
  | ------ | ------ | ---- | ----------------------------------------- |
  | slotId | number | 是   | SIM卡槽ID：<br/>- 0：卡槽1<br/>- 1：卡槽2 |

- 返回值

  | 类型                  | 说明                                          |
  | --------------------- | --------------------------------------------- |
  | Promise&lt;string&gt; | 以Promise形式返回获取短信服务中心地址的结果。 |

-   示例

    ```
    let slotId = 0;
    let promise = sms.getSmscAddr(slotId);
    promise.then(data => {
        console.log(`getSmscAddr success, promise: data->${JSON.stringify(data)}`);
    }).catch(err => {
        console.error(`getSmscAddr fail, promise: err->${JSON.stringify(err)}`);
    });
    ```


## ShortMessage<a name=ShortMessage></a>

短信实例。

| 变量                     | 类型                                    | 说明                                                         |
| ------------------------ | --------------------------------------- | ------------------------------------------------------------ |
| emailAddress             | string                                  | 电子邮件地址。                                               |
| emailMessageBody         | string                                  | 电子邮件正文。                                               |
| hasReplyPath             | boolean                                 | 收到的短信是否包含“TP-Reply-Path”，默认为false。<br/>“TP-Reply-Path”：移动电话根据发送SMS消息的短消息中心进行回复。 |
| isEmailMessage           | boolean                                 | 收到的短信是否为电子邮件。                                   |
| isReplaceMessage         | boolean                                 | 收到的短信是否为“替换短信”，默认为false。<br/>“替换短信”有关详细信息，参见 “3GPP TS 23.040 9.2.3.9”。 |
| isSmsStatusReportMessage | boolean                                 | 当前消息是否为“短信状态报告”，默认为false。<br/>“短信状态报告”是一种特定格式的短信，被用来从Service Center到Mobile Station传送状态报告。 |
| messageClass             | [ShortMessageClass](#ShortMessageClass) | 短信类型。                                                   |
| pdu                      | Array&lt;number&gt;                     | SMS消息中的协议数据单元 （PDU）。                            |
| protocolId               | number                                  | 发送短信时使用的协议标识。                                   |
| scAddress                | string                                  | 短消息服务中心（SMSC）地址。                                 |
| scTimestamp              | number                                  | SMSC时间戳。                                                 |
| status                   | number                                  | SMS-STATUS-REPORT消息中的短信状态指示短信服务中心（SMSC）发送的短信状态。 |
| userRawData              | Array&lt;number&gt;                     | 除数据头外的用户数据。                                       |
| visibleMessageBody       | string                                  | 短信正文。                                                   |
| visibleRawAddress        | string                                  | 发送者地址。                                                 |


## ShortMessageClass<a name=ShortMessageClass></a>

短信类型。

| 变量             | 值   | 说明                                     |
| ---------------- | ---- | ---------------------------------------- |
| UNKNOWN          | 0    | 未知类型。                               |
| INSTANT_MESSAGE  | 1    | 即时消息，收到后立即显示。               |
| OPTIONAL_MESSAGE | 2    | 存储在设备或SIM卡上的短信。              |
| SIM_MESSAGE      | 3    | 包含SIM卡信息的短信，需要存储在SIM卡中。 |
| FORWARD_MESSAGE  | 4    | 要转发到另一台设备的短信。               |


## SendMessageOptions<a name=SendMessageOptions></a>

发送短信的参数和回调。

根据SendMessageOptions中的可选参数content的值判断短信类型。

| 参数名           | 类型                                                         | 必填 | 说明                                                         |
| ---------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| slotId           | number                                                       | 是   | 用于发送短信的SIM卡槽ID：<br/>- 0：卡槽1<br/>- 1：卡槽2      |
| destinationHost  | string                                                       | 是   | 短信的发送地址。                                             |
| content          | string \| Array&lt;number&gt;                                | 是   | 如果内容是字符串，则这是一条文本短信。如果内容是字节数组，则这是一条数据短信。 |
| serviceCenter    | string                                                       | 否   | 短信中心地址。默认使用SIM卡中的短信中心地址。                |
| destinationPort  | number                                                       | 否   | 如果发送数据消息，destinationPort 是必需的。否则是可选的。   |
| sendCallback     | AsyncCallback&lt;[ISendShortMessageCallback](#ISendShortMessageCallback)&gt; | 否   | 短信发送结果回调，返回短信发送的结果，参考[ISendShortMessageCallback](#ISendShortMessageCallback)。 |
| deliveryCallback | AsyncCallback&lt;[IDeliveryShortMessageCallback](#IDeliveryShortMessageCallback)&gt; | 否   | 短信送达结果回调，返回短信递送报告，参考[IDeliveryShortMessageCallback](#IDeliveryShortMessageCallback)。 |


## ISendShortMessageCallback<a name=ISendShortMessageCallback></a>

回调实例。返回短信发送结果、存储已发送短信的URI和是否为长短信的最后一部分。

| 参数名     | 类型                            | 必填 | 说明                                                         |
| ---------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| isLastPart | boolean                         | 否   | 指定这是否是长短信的最后一部分。true表示这是长短信的最后一部分，false表示不是。默认为false。 |
| result     | [SendSmsResult](#SendSmsResult) | 是   | 短信发送结果。                                               |
| url        | string                          | 是   | 存储发送短信的URI。                                          |


## IDeliveryShortMessageCallback<a name=IDeliveryShortMessageCallback></a>

回调实例。返回短信送达报告。

| 参数名 | 类型                | 必填 | 说明           |
| ------ | ------------------- | ---- | -------------- |
| pdu    | Array&lt;number&gt; | 是   | 短信送达报告。 |


## SendSmsResult<a name=SendSmsResult></a>

短信发送结果。

| 参数名                               | 值   | 说明                                                   |
| ------------------------------------ | ---- | ------------------------------------------------------ |
| SEND_SMS_SUCCESS                     | 0    | 发送短信成功。                                         |
| SEND_SMS_FAILURE_UNKNOWN             | 1    | 发送短信失败，原因未知。                               |
| SEND_SMS_FAILURE_RADIO_OFF           | 2    | 发送短信失败，原因为调制解调器关机。                   |
| SEND_SMS_FAILURE_SERVICE_UNAVAILABLE | 3    | 发送短信失败，原因为网络不可用、不支持发送或接收短信。 |