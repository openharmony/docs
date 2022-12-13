# @ohos.telephony.sms (短信服务)

短信服务提供了管理短信的一些基础能力，包括创建、发送短信，获取、设置发送短信的默认SIM卡槽ID，获取、设置短信服务中心（SMSC）地址，以及检查当前设备是否具备短信发送和接收能力等。

>**说明：** 
>
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import sms from '@ohos.telephony.sms';
```

## sms.createMessage

createMessage\(pdu: Array&lt;number&gt;, specification: string, callback: AsyncCallback<ShortMessage\>\): void

根据协议数据单元（PDU）和指定的短信协议创建短信实例。使用callback异步回调。

**系统能力**：SystemCapability.Telephony.SmsMms

**参数：**

| 参数名        | 类型                                               | 必填 | 说明                                                         |
| ------------- | -------------------------------------------------- | ---- | ------------------------------------------------------------ |
| pdu           | Array&lt;number&gt;                                | 是   | 协议数据单元，从收到的信息中获取。                           |
| specification | string                                             | 是   | 短信协议类型。<br/>- 3gpp：表示GSM/UMTS/LTE SMS<br/>- 3gpp2：表示CDMA SMS |
| callback      | AsyncCallback&lt;[ShortMessage](#shortmessage)&gt; | 是   | 回调函数。                                                   |

**示例：**

```js
const specification = '3gpp';
// 以数组的形式显示协议数据单元（PDU），类型为number，例如[0x08, 0x91, ...]
const pdu = [0x08, 0x91];
sms.createMessage(pdu, specification, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.createMessage

createMessage\(pdu: Array&lt;number&gt;, specification: string\): Promise<ShortMessage\>

根据协议数据单元（PDU）和指定的短信协议创建短信实例。使用Promise异步回调。

**系统能力**：SystemCapability.Telephony.SmsMms

**参数：**

| 参数名        | 类型                | 必填 | 说明                                                         |
| ------------- | ------------------- | ---- | ------------------------------------------------------------ |
| pdu           | Array&lt;number&gt; | 是   | 协议数据单元，从收到的信息中获取。                           |
| specification | string              | 是   | 短信协议类型。<br/>- 3gpp：表示GSM/UMTS/LTE SMS<br/>- 3gpp2：表示CDMA SMS |

**返回值：**

| 类型                                         | 说明                              |
| -------------------------------------------- | --------------------------------- |
| Promise&lt;[ShortMessage](#shortmessage)&gt; | 以Promise形式返回创建的短信实例。 |

**示例：**

```js
const specification = '3gpp';
// 以数组的形式显示协议数据单元（PDU），类型为number，例如[0x08, 0x91, ...]
const pdu = [0x08, 0x91];
let promise = sms.createMessage(pdu, specification);
promise.then(data => {
    console.log(`createMessage success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`createMessage failed, promise: err->${JSON.stringify(err)}`);
});
```

## sms.sendMessage

sendMessage(options: SendMessageOptions): void

发送短信。

**需要权限**：ohos.permission.SEND_MESSAGES

**系统能力**：SystemCapability.Telephony.SmsMms

**参数：**

| 参数名  | 类型                                      | 必填 | 说明                                                         |
| ------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| options | [SendMessageOptions](#sendmessageoptions) | 是   | 发送短信的参数和回调，参考[SendMessageOptions](#sendmessageoptions)。 |

**示例：**

```js
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


## sms.getDefaultSmsSlotId<sup>7+</sup>

getDefaultSmsSlotId\(callback: AsyncCallback&lt;number&gt;\): void

获取发送短信的默认SIM卡槽ID。使用callback异步回调。

**系统能力**：SystemCapability.Telephony.SmsMms

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                     |
| -------- | --------------------------- | ---- | ---------------------------------------- |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**示例：**

```js
sms.getDefaultSmsSlotId((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.getDefaultSmsSlotId<sup>7+</sup>

getDefaultSmsSlotId\(\): Promise&lt;number&gt;

获取发送短信的默认SIM卡槽ID。使用Promise异步回调。

**系统能力**：SystemCapability.Telephony.SmsMms

**返回值：**

| 类型            | 说明                                                         |
| --------------- | ------------------------------------------------------------ |
| Promise&lt;number&gt; | 以Promise形式返回发送短信的默认SIM卡：<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**示例：**

```js
let promise = sms.getDefaultSmsSlotId();
promise.then(data => {
    console.log(`getDefaultSmsSlotId success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`getDefaultSmsSlotId failed, promise: err->${JSON.stringify(err)}`);
});
```

## sms.setDefaultSmsSlotId<sup>7+</sup>

setDefaultSmsSlotId\(slotId: number, callback: AsyncCallback&lt;void&gt;\): void

设置发送短信的默认SIM卡槽ID。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.SmsMms

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| slotId   | number                    | 是   | SIM卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2<br/>- -1：清除默认配置 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。                                                   |

**示例：**

```js
sms.setDefaultSmsSlotId(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.setDefaultSmsSlotId<sup>7+</sup>

setDefaultSmsSlotId\(slotId: number\): Promise&lt;void&gt;

设置发送短信的默认SIM卡槽ID。使用Promise异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.SmsMms

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| slotId | number | 是   | SIM卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2<br/>- -1：清除默认配置 |

**返回值：**

| 类型            | 说明                            |
| --------------- | ------------------------------- |
| Promise\<void\> | 以Promise形式异步返回设置结果。 |

**示例：**

```js
let promise = sms.setDefaultSmsSlotId(0);
promise.then(data => {
    console.log(`setDefaultSmsSlotId success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`setDefaultSmsSlotId failed, promise: err->${JSON.stringify(err)}`);
});
```

## sms.setSmscAddr<sup>7+</sup>

setSmscAddr\(slotId: number, smscAddr: string, callback: AsyncCallback<void\>\): void

设置短信服务中心（SMSC）地址。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE，该权限为系统权限

**系统能力**：SystemCapability.Telephony.SmsMms

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                      |
| -------- | ------------------------- | ---- | ----------------------------------------- |
| slotId   | number                    | 是   | SIM卡槽ID：<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| smscAddr | string                    | 是   | 短信服务中心地址。                        |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。                                |

**示例：**

```js
let slotId = 0;
let smscAddr = '+861xxxxxxxxxx';
sms.setSmscAddr(slotId, smscAddr, (err,data) => {
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.setSmscAddr<sup>7+</sup>

setSmscAddr\(slotId: number, smscAddr: string\): Promise\<void\>

设置短信服务中心（SMSC）地址。使用Promise异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE，该权限为系统权限

**系统能力**：SystemCapability.Telephony.SmsMms

**参数：**

| 参数名   | 类型   | 必填 | 说明                                      |
| -------- | ------ | ---- | ----------------------------------------- |
| slotId   | number | 是   | SIM卡槽ID：<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| smscAddr | string | 是   | 短信服务中心地址。                        |

**返回值：**

| 类型                | 说明                            |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回设置结果。 |

**示例：**

```js
let slotId = 0;
let smscAddr = '+861xxxxxxxxxx';
let promise = sms.setSmscAddr(slotId, smscAddr);
promise.then(data => {
    console.log(`setSmscAddr success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`setSmscAddr failed, promise: err->${JSON.stringify(err)}`);
});
```


## sms.getSmscAddr<sup>7+</sup>

getSmscAddr\(slotId: number, callback: AsyncCallback<string\>\): void

获取短信服务中心（SMSC）地址。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE，该权限为系统权限

**系统能力**：SystemCapability.Telephony.SmsMms

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                      |
| -------- | --------------------------- | ---- | ----------------------------------------- |
| slotId   | number                      | 是   | SIM卡槽ID：<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback&lt;string&gt; | 是   | 回调函数。                                |

**示例：**

```js
let slotId = 0;
sms.getSmscAddr(slotId, (err, data) => {
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.getSmscAddr<sup>7+</sup>

getSmscAddr\(slotId: number\): Promise<string\>

获取短信服务中心（SMSC）地址。使用Promise异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE，该权限为系统权限

**系统能力**：SystemCapability.Telephony.SmsMms

**参数：**

| 参数名 | 类型   | 必填 | 说明                                      |
| ------ | ------ | ---- | ----------------------------------------- |
| slotId | number | 是   | SIM卡槽ID：<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型                  | 说明                                          |
| --------------------- | --------------------------------------------- |
| Promise&lt;string&gt; | 以Promise形式返回获取短信服务中心地址的结果。 |

**示例：**

```js
let slotId = 0;
let promise = sms.getSmscAddr(slotId);
promise.then(data => {
    console.log(`getSmscAddr success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`getSmscAddr failed, promise: err->${JSON.stringify(err)}`);
});
```

## sms.hasSmsCapability<sup>7+</sup>

hasSmsCapability(): boolean

检查当前设备是否具备短信发送和接收能力，该方法是同步方法。

**系统能力**：SystemCapability.Telephony.SmsMms

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | - true：设备具备短信发送和接收能力。<br/>- false：设备不具备短信发送和接收能力。 |

```js
let result = sms.hasSmsCapability(); 
console.log(`hasSmsCapability: ${JSON.stringify(result)}`);
```

## sms.splitMessage<sup>8+</sup>

splitMessage(content: string, callback: AsyncCallback<Array<string\>>): void

将长短信拆分为多个片段。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SEND_MESSAGES

**系统能力**：SystemCapability.Telephony.SmsMms

**参数：**

| 参数名   | 类型                          | 必填 | 说明                          |
| -------- | ----------------------------- | ---- | ----------------------------- |
| content  | string                        | 是   | 指示短消息内容，不能为null。 |
| callback | AsyncCallback<Array<string\>> | 是   | 回调函数。                    |

**示例：**

```js
let content = "long message";
sms.splitMessage(content, (err, data) => {
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.splitMessage<sup>8+</sup>

splitMessage(content: string): Promise<Array<string\>>

将长短信拆分为多个片段。使用Promise异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SEND_MESSAGES

**系统能力**：SystemCapability.Telephony.SmsMms

**参数：**

| 参数名  | 类型   | 必填 | 说明                         |
| ------- | ------ | ---- | ---------------------------- |
| content | string | 是   | 指示短消息内容，不能为null。 |

**返回值：**

| 类型                    | 说明                                |
| ----------------------- | ----------------------------------- |
| Promise<Array<string\>> | 以Promise形式返回多个片段的的结果。 |

**示例：**

```js
let content = "long message";
let promise = sms.splitMessage(content);
promise.then(data => {
    console.log(`splitMessage success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`splitMessage failed, promise: err->${JSON.stringify(err)}`);
});
```

## sms.addSimMessage<sup>7+</sup>

addSimMessage(options: SimMessageOptions, callback: AsyncCallback<void\>): void

添加SIM卡消息。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.RECEIVE_SMS,ohos.permission.SEND_MESSAGES

**系统能力**：SystemCapability.Telephony.SmsMms

**参数：**

| 参数名   | 类型                                     | 必填 | 说明            |
| -------- | ---------------------------------------- | ---- | --------------- |
| options  | [SimMessageOptions](#simmessageoptions7) | 是   | SIM卡消息选项。 |
| callback | AsyncCallback&lt;void&gt;                | 是   | 回调函数。      |

**示例：**

```js
let simMessageOptions = {
    slotId: 0,
    smsc: "test",
    pdu: "xxxxxx",
    status: sms.SimMessageStatus.SIM_MESSAGE_STATUS_READ
};
sms.addSimMessage(simMessageOptions, (err, data) => {
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.addSimMessage<sup>7+</sup>

addSimMessage(options: SimMessageOptions): Promise<void\>

添加SIM卡消息。使用Promise异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.RECEIVE_SMS,ohos.permission.SEND_MESSAGES

**系统能力**：SystemCapability.Telephony.SmsMms

**参数：**

| 参数名  | 类型                                     | 必填 | 说明            |
| ------- | ---------------------------------------- | ---- | --------------- |
| options | [SimMessageOptions](#simmessageoptions7) | 是   | SIM卡消息选项。 |

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | 以Promise形式返回添加的结果。 |

**示例：**

```js
let simMessageOptions = {
    slotId: 0,
    smsc: "test",
    pdu: "xxxxxx",
    status: sms.SimMessageStatus.SIM_MESSAGE_STATUS_READ
};
let promise = sms.addSimMessage(simMessageOptions);
promise.then(data => {
    console.log(`addSimMessage success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`addSimMessage failed, promise: err->${JSON.stringify(err)}`);
});
```

## sms.delSimMessage<sup>7+</sup>

delSimMessage(slotId: number, msgIndex: number, callback: AsyncCallback<void\>): void

删除SIM卡消息。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.RECEIVE_SMS,ohos.permission.SEND_MESSAGES

**系统能力**：SystemCapability.Telephony.SmsMms

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                      |
| -------- | ------------------------- | ---- | ----------------------------------------- |
| slotId   | number                    | 是   | SIM卡槽ID：<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| msgIndex | number                    | 是   | 消息索引。                                  |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。                                |

**示例：**

```js
let slotId = 0;
let msgIndex = 1;
sms.delSimMessage(slotId, msgIndex, (err, data) => {
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.delSimMessage<sup>7+</sup>

delSimMessage(slotId: number, msgIndex: number): Promise<void\>

删除SIM卡信息。使用Promise异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.RECEIVE_SMS,ohos.permission.SEND_MESSAGES

**系统能力**：SystemCapability.Telephony.SmsMms

**参数：**

| 参数名   | 类型   | 必填 | 说明                                      |
| -------- | ------ | ---- | ----------------------------------------- |
| slotId   | number | 是   | SIM卡槽ID：<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| msgIndex | number | 是   | 消息索引。                                  |

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | 以Promise形式返回删除的结果。 |

**示例：**

```js
let slotId = 0;
let msgIndex = 1;
let promise = sms.delSimMessage(slotId, msgIndex);
promise.then(data => {
    console.log(`delSimMessage success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`delSimMessage failed, promise: err->${JSON.stringify(err)}`);
});
```

## sms.updateSimMessage<sup>7+</sup>

updateSimMessage(options: UpdateSimMessageOptions, callback: AsyncCallback<void\>): void

更新SIM卡消息。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.RECEIVE_SMS,ohos.permission.SEND_MESSAGES

**系统能力**：SystemCapability.Telephony.SmsMms

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                |
| -------- | ---------------------------------------------------- | ---- | ------------------- |
| options  | [UpdateSimMessageOptions](#updatesimmessageoptions7) | 是   | 更新SIM卡消息选项。 |
| callback | AsyncCallback&lt;void&gt;                            | 是   | 回调函数。          |

**示例：**

```js
let updateSimMessageOptions = {
    slotId: 0,
    msgIndex: 1,
    newStatus: sms.SimMessageStatus.SIM_MESSAGE_STATUS_FREE,
    pdu: "xxxxxxx",
    smsc: "test"
};
sms.updateSimMessage(updateSimMessageOptions, (err, data) => {
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.updateSimMessage<sup>7+</sup>

updateSimMessage(options: UpdateSimMessageOptions): Promise<void\>

更新SIM卡消息。使用Promise异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.RECEIVE_SMS,ohos.permission.SEND_MESSAGES

**系统能力**：SystemCapability.Telephony.SmsMms

**参数：**

| 参数名  | 类型                                                 | 必填 | 说明                |
| ------- | ---------------------------------------------------- | ---- | ------------------- |
| options | [UpdateSimMessageOptions](#updatesimmessageoptions7) | 是   | 更新SIM卡消息选项。 |

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | 以Promise形式返回更新的结果。 |

**示例：**

```js
let updateSimMessageOptions = {
    slotId: 0,
    msgIndex: 1,
    newStatus: sms.SimMessageStatus.SIM_MESSAGE_STATUS_FREE,
    pdu: "xxxxxxx",
    smsc: "test"
};
let promise = sms.updateSimMessage(updateSimMessageOptions);
promise.then(data => {
    console.log(`updateSimMessage success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`updateSimMessage failed, promise: err->${JSON.stringify(err)}`);
});
```

## sms.getAllSimMessages<sup>7+</sup>

getAllSimMessages(slotId: number, callback: AsyncCallback<Array<SimShortMessage\>>): void

获取所有SIM卡消息。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.RECEIVE_SMS

**系统能力**：SystemCapability.Telephony.SmsMms

**参数：**

| 参数名   | 类型                                                        | 必填 | 说明                                      |
| -------- | ----------------------------------------------------------- | ---- | ----------------------------------------- |
| slotId   | number                                                      | 是   | SIM卡槽ID：<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback<Array<[SimShortMessage](#simshortmessage7)\>> | 是   | 回调函数。                                |

**示例：**

```js
let slotId = 0;
sms.getAllSimMessages(slotId, (err, data) => {
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.getAllSimMessages<sup>7+</sup>

getAllSimMessages(slotId: number): Promise<Array<SimShortMessage\>>

获取所有SIM卡消息。使用Promise异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.RECEIVE_SMS

**系统能力**：SystemCapability.Telephony.SmsMms

**参数：**

| 参数名 | 类型   | 必填 | 说明                                      |
| ------ | ------ | ---- | ----------------------------------------- |
| slotId | number | 是   | SIM卡槽ID：<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型                                                    | 说明                               |
| ------------------------------------------------------- | ---------------------------------- |
| PromiseArray<[SimShortMessage](#simshortmessage7)\>&gt; | 以Promise形式返回获取的SIM短消息。 |

**示例：**

```js
let slotId = 0;
let promise = sms.getAllSimMessages(slotId);
promise.then(data => {
    console.log(`getAllSimMessages success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`getAllSimMessages failed, promise: err->${JSON.stringify(err)}`);
});
```

## sms.setCBConfig<sup>7+</sup>

setCBConfig(options: CBConfigOptions, callback: AsyncCallback<void\>): void

设置小区广播配置。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.RECEIVE_SMS

**系统能力**：SystemCapability.Telephony.SmsMms

**参数：**

| 参数名   | 类型                                 | 必填 | 说明         |
| -------- | ------------------------------------ | ---- | ------------ |
| options  | [CBConfigOptions](#cbconfigoptions7) | 是   | 小区广播配置选项。 |
| callback | AsyncCallback&lt;void&gt;            | 是   | 回调函数。   |

**示例：**

```js
let cbConfigOptions = {
    slotId: 0,
    enable: true,
    startMessageId: 100,
    endMessageId: 200,
    ranType: sms.RanType.TYPE_GSM
};
sms.setCBConfig(cbConfigOptions, (err, data) => {
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.setCBConfig<sup>7+</sup>

setCBConfig(options: CBConfigOptions): Promise<void\>

设置小区广播配置。使用Promise异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.RECEIVE_SMS

**系统能力**：SystemCapability.Telephony.SmsMms

**参数：**

| 参数名  | 类型                                 | 必填 | 说明         |
| ------- | ------------------------------------ | ---- | ------------ |
| options | [CBConfigOptions](#cbconfigoptions7) | 是   | 小区广播配置选项。 |

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | 以Promise形式返回设置的结果。 |

**示例：**

```js
let cbConfigOptions = {
    slotId: 0,
    enable: true,
    startMessageId: 100,
    endMessageId: 200,
    ranType: sms.RanType.TYPE_GSM
};
let promise = sms.setCBConfig(cbConfigOptions);
promise.then(data => {
    console.log(`setCBConfig success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`setCBConfig failed, promise: err->${JSON.stringify(err)}`);
});
```

## sms.getSmsSegmentsInfo<sup>8+</sup>

getSmsSegmentsInfo(slotId: number, message: string, force7bit: boolean, callback: AsyncCallback<SmsSegmentsInfo\>): void

获取短信段信息。使用callback异步回调。

此接口为系统接口。

**系统能力**：SystemCapability.Telephony.SmsMms

**参数：**

| 参数名    | 类型                                                         | 必填 | 说明                                      |
| --------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
| slotId    | number                                                       | 是   | SIM卡槽ID：<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| message   | string                                                       | 是   | 消息。                                      |
| force7bit | boolean                                                      | 是   | 是否使用7 bit编码。                          |
| callback  | AsyncCallback&lt;[SmsSegmentsInfo](#smssegmentsinfo8)&gt; | 是   | 回调函数。                                  |

**示例：**

```js
let slotId = 0;
sms.getSmsSegmentsInfo(slotId, "message", false, (err, data) => {
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.getSmsSegmentsInfo<sup>8+</sup>

getSmsSegmentsInfo(slotId: number, message: string, force7bit: boolean): Promise<SmsSegmentsInfo\>

获取短信段信息。使用Promise异步回调。

此接口为系统接口。

**系统能力**：SystemCapability.Telephony.SmsMms

**参数：**

| 参数名    | 类型    | 必填 | 说明                                      |
| --------- | ------- | ---- | ----------------------------------------- |
| slotId    | number  | 是   | SIM卡槽ID：<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| message   | string  | 是   | 消息。                                      |
| force7bit | boolean | 是   | 是否使用7 bit编码。                          |

**返回值：**

| 类型                                                    | 说明                          |
| ------------------------------------------------------- | ----------------------------- |
| Promise&lt;[SmsSegmentsInfo](#smssegmentsinfo8)&gt; | 以Promise形式返回短信段信息。 |

**示例：**

```js
let slotId = 0;
let promise = sms.getSmsSegmentsInfo(slotId, "message", false);
promise.then(data => {
    console.log(`getSmsSegmentsInfo success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`getSmsSegmentsInfo failed, promise: err->${JSON.stringify(err)}`);
});
```

## sms.isImsSmsSupported<sup>8+</sup>

isImsSmsSupported(slotId: number, callback: AsyncCallback<boolean\>): void

如果IMS已注册并且在IMS上支持SMS，则支持通过IMS发送SMS。使用callback异步回调。

此接口为系统接口。

**系统能力**：SystemCapability.Telephony.SmsMms

**参数：**

| 参数名   | 类型                         | 必填 | 说明       |
| -------- | ---------------------------- | ---- | ---------- |
| slotId   | number                       | 是   | SIM卡槽ID：<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。 |

**示例：**

```js
let slotId = 0;
sms.isImsSmsSupported(slotId, (err, data) => {
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.isImsSmsSupported<sup>8+</sup>

isImsSmsSupported(slotId: number): Promise<boolean\>

如果IMS已注册并且在IMS上支持SMS，则支持通过IMS发送SMS。使用Promise异步回调。

此接口为系统接口。

**系统能力**：SystemCapability.Telephony.SmsMms

**参数：**

| 参数名 | 类型   | 必填  | 说明                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型                   | 说明                    |
| ---------------------- | ----------------------- |
| Promise&lt;boolean&gt; | 以Promise形式返回结果。 |

**示例：**

```js
let slotId = 0;
let promise = sms.isImsSmsSupported(slotId);
promise.then(data => {
    console.log(`isImsSmsSupported success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`isImsSmsSupported failed, promise: err->${JSON.stringify(err)}`);
});
```

## sms.getImsShortMessageFormat<sup>8+</sup>

getImsShortMessageFormat(callback: AsyncCallback<string\>): void

获取IMS上支持的SMS格式。使用callback异步回调。

此接口为系统接口。

**系统能力**：SystemCapability.Telephony.SmsMms

**参数：**

| 参数名   | 类型                        | 必填 | 说明       |
| -------- | --------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;string&gt; | 是   | 回调函数。 |

**示例：**

```js
sms.getImsShortMessageFormat((err, data) => {
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.getImsShortMessageFormat<sup>8+</sup>

getImsShortMessageFormat(): Promise<string\>

获取IMS上支持的SMS格式。使用Promise异步回调。

此接口为系统接口。

**系统能力**：SystemCapability.Telephony.SmsMms

**返回值：**

| 类型                  | 说明                       |
| --------------------- | -------------------------- |
| Promise&lt;string&gt; | 以Promise形式返回SMS格式。 |

**示例：**

```js
let promise = sms.getImsShortMessageFormat();
promise.then(data => {
    console.log(`getImsShortMessageFormat success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`getImsShortMessageFormat failed, promise: err->${JSON.stringify(err)}`);
});
```

## sms.decodeMms<sup>8+</sup>

decodeMms(mmsFilePathName: string | Array<number\>, callback: AsyncCallback<MmsInformation\>): void

彩信解码。使用callback异步回调。

此接口为系统接口。

**系统能力**：SystemCapability.Telephony.SmsMms

**参数：**

| 参数名          | 类型                                                    | 必填 | 说明           |
| --------------- | ------------------------------------------------------- | ---- | -------------- |
| mmsFilePathName | string \|Array<number\>                                 | 是   | 彩信文件路径名。 |
| callback        | AsyncCallback&lt;[MmsInformation](#mmsinformation8)&gt; | 是   | 回调函数。     |

**示例：**

```js
let mmsFilePathName = "filename";
sms.decodeMms(mmsFilePathName, (err, data) => {
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.decodeMms<sup>8+</sup>

decodeMms(mmsFilePathName: string | Array<number\>): Promise<MmsInformation\>

彩信解码。使用Promise异步回调。

此接口为系统接口。

**系统能力**：SystemCapability.Telephony.SmsMms

**参数：**

| 参数名          | 类型                    | 必填 | 说明           |
| --------------- | ----------------------- | ---- | -------------- |
| mmsFilePathName | string \|Array<number\> | 是   | 彩信文件路径名 |

**返回值：**

| 类型                                                      | 说明                        |
| --------------------------------------------------------- | --------------------------- |
| Promise&lt;&lt;[MmsInformation](#mmsinformation8)&gt;&gt; | 以Promise形式返回彩信信息。 |

**示例：**

```js
let mmsFilePathName = "filename";
let promise = sms.decodeMms(mmsFilePathName);
promise.then(data => {
    console.log(`decodeMms success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`decodeMms failed, promise: err->${JSON.stringify(err)}`);
});
```

## sms.encodeMms<sup>8+</sup>

encodeMms(mms: MmsInformation, callback: AsyncCallback<Array<number\>>): void

彩信编码。使用callback异步回调。

此接口为系统接口。

**系统能力**：SystemCapability.Telephony.SmsMms

**参数：**

| 参数名   | 类型                                | 必填 | 说明       |
| -------- | ----------------------------------- | ---- | ---------- |
| mms      | [MmsInformation](#mmsinformation8)  | 是   | 彩信信息。 |
| callback | AsyncCallback&lt;Array<number\>&gt; | 是   | 回调函数。 |

**示例：**

```js
let mmsAcknowledgeInd = {
    transactionId: "100",
    version: sms.MmsVersionType.MMS_VERSION_1_0,
    reportAllowed: sms.ReportType.MMS_YES
};
let mmsInformation = {
    messageType: sms.MessageType.TYPE_MMS_ACKNOWLEDGE_IND,
    mmsType: mmsAcknowledgeInd
};
sms.encodeMms(mmsInformation, (err, data) => {
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.encodeMms<sup>8+</sup>

encodeMms(mms: MmsInformation): Promise<Array<number\>>

彩信编码。使用Promise异步回调。

此接口为系统接口。

**系统能力**：SystemCapability.Telephony.SmsMms

**参数：**

| 参数名 | 类型                               | 必填 | 说明       |
| ------ | ---------------------------------- | ---- | ---------- |
| mms    | [MmsInformation](#mmsinformation8) | 是   | 彩信信息。 |

**返回值：**

| 类型                          | 说明                                |
| ----------------------------- | ----------------------------------- |
| Promise&lt;Array<number\>&gt; | 以Promise形式返回彩信编码后的结果。 |

**示例：**

```js
let mmsAcknowledgeInd = {
    transactionId: "100",
    version: sms.MmsVersionType.MMS_VERSION_1_0,
    reportAllowed: sms.ReportType.MMS_YES
};
let mmsInformation = {
    messageType: sms.MessageType.TYPE_MMS_ACKNOWLEDGE_IND,
    mmsType: mmsAcknowledgeInd
};
let promise = sms.encodeMms(mmsInformation);
promise.then(data => {
    console.log(`encodeMms success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`encodeMms failed, promise: err->${JSON.stringify(err)}`);
});
```

## ShortMessage

短信实例。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.SmsMms。

|         名称             |                  类型                   | 必填 | 说明                                                         |
| ------------------------ | --------------------------------------- | ---- | ------------------------------------------------------------ |
| hasReplyPath             | boolean                                 |  是  | 收到的短信是否包含“TP-Reply-Path”，默认为false。<br/>“TP-Reply-Path”：设备根据发送SMS消息的短消息中心进行回复。  |
| isReplaceMessage         | boolean                                 |  是  | 收到的短信是否为“替换短信”，默认为false。<br/>“替换短信”有关详细信息，参见 “3GPP TS 23.040 9.2.3.9”。 |
| isSmsStatusReportMessage | boolean                                 |  是  | 当前消息是否为“短信状态报告”，默认为false。<br/>“短信状态报告”是一种特定格式的短信，被用来从Service Center到Mobile Station传送状态报告。|
| messageClass             | [ShortMessageClass](#shortmessageclass) |  是  | 短信类型。                                                   |
| pdu                      | Array&lt;number&gt;                     |  是  | SMS消息中的协议数据单元 （PDU）。                            |
| protocolId               | number                                  |  是  | 发送短信时使用的协议标识。                                   |
| scAddress                | string                                  |  是  | 短消息服务中心（SMSC）地址。                                 |
| scTimestamp              | number                                  |  是  | SMSC时间戳。                                                 |
| status                   | number                                  |  是  | SMS-STATUS-REPORT消息中的短信状态指示短信服务中心（SMSC）发送的短信状态。 |
| visibleMessageBody       | string                                  |  是  | 短信正文。                                                   |
| visibleRawAddress        | string                                  |  是  | 发送者地址。                                                 |


## ShortMessageClass

短信类型。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.SmsMms。

| 名称             | 值   | 说明                                     |
| ---------------- | ---- | ---------------------------------------- |
| UNKNOWN          | 0    | 未知类型。                               |
| INSTANT_MESSAGE  | 1    | 即时消息，收到后立即显示。               |
| OPTIONAL_MESSAGE | 2    | 存储在设备或SIM卡上的短信。              |
| SIM_MESSAGE      | 3    | 包含SIM卡信息的短信，需要存储在SIM卡中。 |
| FORWARD_MESSAGE  | 4    | 要转发到另一台设备的短信。               |


## SendMessageOptions

发送短信的参数和回调。根据SendMessageOptions中的可选参数content的值判断短信类型。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.SmsMms。

|       名称       | 类型                                                         | 必填 | 说明                                                         |
| ---------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| slotId           | number                                                       | 是   | 用于发送短信的SIM卡槽ID：<br/>- 0：卡槽1<br/>- 1：卡槽2      |
| destinationHost  | string                                                       | 是   | 短信的发送地址。                                             |
| content          | string \| Array&lt;number&gt;                                | 是   | 如果内容是字符串，则这是一条文本短信。如果内容是字节数组，则这是一条数据短信。 |
| serviceCenter    | string                                                       | 否   | 短信中心地址。默认使用SIM卡中的短信中心地址。                |
| destinationPort  | number                                                       | 否   | 如果发送数据消息，destinationPort 是必需的。否则是可选的。   |
| sendCallback     | AsyncCallback&lt;[ISendShortMessageCallback](#isendshortmessagecallback)&gt; | 否   | 短信发送结果回调，返回短信发送的结果，参考[ISendShortMessageCallback](#isendshortmessagecallback)。 |
| deliveryCallback | AsyncCallback&lt;[IDeliveryShortMessageCallback](#ideliveryshortmessagecallback)&gt; | 否   | 短信送达结果回调，返回短信递送报告，参考[IDeliveryShortMessageCallback](#ideliveryshortmessagecallback)。 |


## ISendShortMessageCallback

回调实例。返回短信发送结果、存储已发送短信的URI和是否为长短信的最后一部分。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.SmsMms。

|   名称     | 类型                            | 必填 |                                               说明                                         |
| ---------- | ------------------------------- | ---- | ----------------------------------------------------------------------------------------- |
| isLastPart | boolean                         | 否   | 指定这是否是长短信的最后一部分。true表示这是长短信的最后一部分，false表示不是。默认为false。 |
| result     | [SendSmsResult](#sendsmsresult) | 是   | 短信发送结果。                                                                             |
| url        | string                          | 是   | 存储发送短信的URI。                                                                        |


## IDeliveryShortMessageCallback

回调实例，返回短信送达报告。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.SmsMms。

| 名称 | 类型                | 必填 | 说明           |
| ---- | ------------------- | ---- | -------------- |
| pdu  | Array&lt;number&gt; | 是   | 短信送达报告。 |


## SendSmsResult

短信发送结果。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.SmsMms。

| 名称                                 | 值   | 说明                                                   |
| ------------------------------------ | ---- | ------------------------------------------------------ |
| SEND_SMS_SUCCESS                     | 0    | 发送短信成功。                                         |
| SEND_SMS_FAILURE_UNKNOWN             | 1    | 发送短信失败，原因未知。                               |
| SEND_SMS_FAILURE_RADIO_OFF           | 2    | 发送短信失败，原因为调制解调器关机。                   |
| SEND_SMS_FAILURE_SERVICE_UNAVAILABLE | 3    | 发送短信失败，原因为网络不可用、不支持发送或接收短信。 |

## MmsInformation<sup>8+</sup>

彩信信息。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.SmsMms。

|     名称    | 类型                                                         | 必填 |    说明    |
| ----------- | ------------------------------------------------------------ | ---- | ---------- |
| messageType | [MessageType](#messagetype8)                                 | 是   | 消息类型。 |
| mmsType     | [MmsSendReq](#mmssendreq8) \|[MmsSendConf](#mmssendconf8) \|[MmsNotificationInd](#mmsnotificationind8) \|[MmsRespInd](#mmsrespind8) \|[MmsRetrieveConf](#mmsretrieveconf8)\|[MmsAcknowledgeInd](#mmsacknowledgeind8)\|[MmsDeliveryInd](#mmsdeliveryind8)\|[MmsReadOrigInd](#mmsreadorigind8)\|[MmsReadRecInd](#mmsreadrecind8) | 是   | PDU头类型 |
| attachment  | Array<[MmsAttachment](#mmsattachment8)\>                     | 否   | 附件      |

## MmsSendReq<sup>8+</sup>

彩信发送请求。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.SmsMms。

|       名称       | 类型                                 | 必填 | 说明         |
| ---------------- | ------------------------------------ | ---- | ------------ |
| from             | [MmsAddress](#mmsaddress8)           | 是   | 彩信来源     |
| transactionId    | string                               | 是   | 事务ID       |
| contentType      | string                               | 是   | 内容类型     |
| version          | [MmsVersionType](#mmsversiontype8)   | 是   | 版本         |
| to               | Array<[MmsAddress](#mmsaddress8)\>   | 否   | 发送至       |
| date             | number                               | 否   | 日期         |
| cc               | Array<[MmsAddress](#mmsaddress8)\>   | 否   | 抄送         |
| bcc              | Array<[MmsAddress](#mmsaddress8)\>   | 否   | 暗抄送       |
| subject          | string                               | 否   | 主题         |
| messageClass     | number                               | 否   | 消息类       |
| expiry           | number                               | 否   | 到期         |
| priority         | [MmsPriorityType](#mmsprioritytype8) | 否   | 优先         |
| senderVisibility | number                               | 否   | 发件人可见性 |
| deliveryReport   | number                               | 否   | 交付报告     |
| readReport       | number                               | 否   | 阅读报告     |

## MmsSendConf<sup>8+</sup>

彩信发送配置。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.SmsMms。

|     名称      | 类型                               | 必填 | 说明     |
| ------------- | ---------------------------------- | ---- | -------- |
| responseState | number                             | 是   | 响应状态 |
| transactionId | string                             | 是   | 事务ID   |
| version       | [MmsVersionType](#mmsversiontype8) | 是   | 版本     |
| messageId     | string                             | 否   | 消息ID   |

## MmsNotificationInd<sup>8+</sup>

彩信通知索引。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.SmsMms。

|      名称       | 类型                               | 必填 | 说明     |
| --------------- | ---------------------------------- | ---- | -------- |
| transactionId   | string                             | 是   | 事务ID   |
| messageClass    | number                             | 是   | 消息类   |
| messageSize     | number                             | 是   | 消息大小 |
| expiry          | number                             | 是   | 到期     |
| contentLocation | string                             | 是   | 内容位置 |
| version         | [MmsVersionType](#mmsversiontype8) | 是   | 版本     |
| from            | [MmsAddress](#mmsaddress8)         | 否   | 来源     |
| subject         | string                             | 否   | 主题     |
| deliveryReport  | number                             | 否   | 状态报告 |
| contentClass    | number                             | 否   | 内容类   |

## MmsAcknowledgeInd<sup>8+</sup>

彩信确认索引。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.SmsMms。

|      名称     | 类型                               | 必填 | 说明     |
| ------------- | ---------------------------------- | ---- | -------- |
| transactionId | string                             | 是   | 事务ID   |
| version       | [MmsVersionType](#mmsversiontype8) | 是   | 版本     |
| reportAllowed | [ReportType](#reporttype8)         | 否   | 允许报告 |

## MmsRetrieveConf<sup>8+</sup>

彩信检索配置。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.SmsMms。

|      名称      | 类型                                 | 必填 | 说明     |
| -------------- | ------------------------------------ | ---- | -------- |
| transactionId  | string                               | 是   | 事务ID   |
| messageId      | string                               | 是   | 消息ID   |
| date           | number                               | 是   | 日期     |
| contentType    | string                               | 是   | 内容类型 |
| to             | Array<[MmsAddress](#mmsaddress8)\>   | 是   | 发送至   |
| version        | [MmsVersionType](#mmsversiontype8)   | 是   | 版本     |
| from           | [MmsAddress](#mmsaddress8)           | 否   | 来源     |
| cc             | Array<[MmsAddress](#mmsaddress8)\>   | 否   | 抄送     |
| subject        | string                               | 否   | 主题     |
| priority       | [MmsPriorityType](#mmsprioritytype8) | 否   | 优先级   |
| deliveryReport | number                               | 否   | 状态报告 |
| readReport     | number                               | 否   | 阅读报告 |
| retrieveStatus | number                               | 否   | 检索状态 |
| retrieveText   | string                               | 否   | 检索文本 |

## MmsReadOrigInd<sup>8+</sup>

彩信读取原始索引。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.SmsMms。

|    名称    | 类型                               | 必填 | 说明     |
| ---------- | ---------------------------------- | ---- | -------- |
| version    | [MmsVersionType](#mmsversiontype8) | 是   | 版本     |
| messageId  | string                             | 是   | 消息ID   |
| to         | Array<[MmsAddress](#mmsaddress8)\> | 是   | 发送至   |
| from       | [MmsAddress](#mmsaddress8)         | 是   | 来源     |
| date       | number                             | 是   | 日期     |
| readStatus | number                             | 是   | 阅读状态 |

## MmsReadRecInd<sup>8+</sup>

彩信读取记录索引。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.SmsMms。

|    名称    | 类型                               | 必填 | 说明     |
| ---------- | ---------------------------------- | ---- | -------- |
| version    | [MmsVersionType](#mmsversiontype8) | 是   | 版本     |
| messageId  | string                             | 是   | 消息ID   |
| to         | Array<[MmsAddress](#mmsaddress8)\> | 是   | 发送至   |
| from       | [MmsAddress](#mmsaddress8)         | 是   | 来源     |
| readStatus | number                             | 是   | 阅读状态 |
| date       | number                             | 否   | 日期     |

## MmsAttachment<sup>8+</sup>

彩信附件。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.SmsMms。

|          名称           | 类型                                 | 必填 | 说明               |
| ----------------------- | ------------------------------------ | ---- | ------------------ |
| contentId               | string                               | 是   | 内容ID             |
| contentLocation         | string                               | 是   | 内容位置           |
| contentDisposition      | [DispositionType](#dispositiontype8) | 是   | 内容处理           |
| contentTransferEncoding | string                               | 是   | 内容传输编码       |
| contentType             | string                               | 是   | 内容类型           |
| isSmil                  | boolean                              | 是   | 同步多媒体集成语言 |
| path                    | string                               | 否   | 路径               |
| inBuff                  | Array<number\>                       | 否   | 缓冲区中           |
| fileName                | string                               | 否   | 文件名             |
| charset                 | [MmsCharSets](#mmscharsets8)         | 否   | 字符集             |

## MmsAddress<sup>8+</sup>

彩信地址。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.SmsMms。

|   名称  | 类型                         | 必填 | 说明   |
| ------- | ---------------------------- | ---- | ------ |
| address | string                       | 是   | 地址   |
| charset | [MmsCharSets](#mmscharsets8) | 是   | 字符集 |

## MessageType<sup>8+</sup>

消息类型。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.SmsMms。

|          名称             | 值   | 说明                 |
| ------------------------- | ---- | -------------------- |
| TYPE_MMS_SEND_REQ         | 128  | 彩信发送请求类型     |
| TYPE_MMS_SEND_CONF        | 129  | 彩信发送配置类型     |
| TYPE_MMS_NOTIFICATION_IND | 130  | 彩信通知索引类型     |
| TYPE_MMS_RESP_IND         | 131  | 彩信回复索引类型     |
| TYPE_MMS_RETRIEVE_CONF    | 132  | 彩信检索配置类型     |
| TYPE_MMS_ACKNOWLEDGE_IND  | 133  | 彩信确认索引类型     |
| TYPE_MMS_DELIVERY_IND     | 134  | 彩信传送索引类型     |
| TYPE_MMS_READ_REC_IND     | 135  | 彩信读取接收索引类型 |
| TYPE_MMS_READ_ORIG_IND    | 136  | 彩信读取原始索引类型 |

## MmsPriorityType<sup>8+</sup>

彩信优先级类型。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.SmsMms。

|    名称    | 值   | 说明           |
| ---------- | ---- | -------------- |
| MMS_LOW    | 128  | 彩信优先级低   |
| MMS_NORMAL | 129  | 彩信优先级正常 |
| MMS_HIGH   | 130  | 彩信优先级高   |

## MmsVersionType<sup>8+</sup>

彩信版本类型。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.SmsMms。

|      名称       | 值   | 说明        |
| --------------- | ---- | ----------- |
| MMS_VERSION_1_0 | 0x10 | 彩信版本1_0 |
| MMS_VERSION_1_1 | 0x11 | 彩信版本1_1 |
| MMS_VERSION_1_2 | 0x12 | 彩信版本1_2 |
| MMS_VERSION_1_3 | 0x13 | 彩信版本1_3 |

## MmsCharSets<sup>8+</sup>

彩信字符集。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.SmsMms。

|      名称       | 值     | 说明                |
| --------------- | ------ | ------------------- |
| BIG5            | 0X07EA | BIG5格式            |
| ISO_10646_UCS_2 | 0X03E8 | ISO_10646_UCS_2格式 |
| ISO_8859_1      | 0X04   | ISO_8859_1格式      |
| ISO_8859_2      | 0X05   | ISO_8859_2格式      |
| ISO_8859_3      | 0X06   | ISO_8859_3格式      |
| ISO_8859_4      | 0X07   | ISO_8859_4格式      |
| ISO_8859_5      | 0X08   | ISO_8859_5格式      |
| ISO_8859_6      | 0X09   | ISO_8859_6格式      |
| ISO_8859_7      | 0X0A   | ISO_8859_7格式      |
| ISO_8859_8      | 0X0B   | ISO_8859_8格式      |
| ISO_8859_9      | 0X0C   | ISO_8859_9格式      |
| SHIFT_JIS       | 0X11   | SHIFT_JIS格式       |
| US_ASCII        | 0X03   | US_ASCII格式        |
| UTF_8           | 0X6A   | UTF_8格式           |

## DispositionType<sup>8+</sup>

处理类型。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.SmsMms。

|    名称    | 值   | 说明     |
| ---------- | ---- | -------- |
| FROM_DATA  | 0    | 数据来源 |
| ATTACHMENT | 1    | 附件     |
| INLINE     | 2    | 内联     |

## ReportType<sup>8+</sup>

报告类型。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.SmsMms。

|  名称   | 值   | 说明 |
| ------- | ---- | ---- |
| MMS_YES | 128  | YES  |
| MMS_NO  | 129  | NO   |

## CBConfigOptions<sup>7+</sup>

小区广播配置选项。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.SmsMms。

|      名称      | 类型                 | 必填 | 说明         |
| -------------- | -------------------- | ---- | ------------ |
| slotId         | number               | 是   | 卡槽ID       |
| enable         | boolean              | 是   | 可行         |
| startMessageId | number               | 是   | 消息起始ID   |
| endMessageId   | number               | 是   | 消息结束ID   |
| ranType        | [RanType](#rantype7) | 是   | 设备网络制式 |

## SimMessageStatus<sup>7+</sup>

SIM卡消息状态。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.SmsMms。

|           名称            | 值   | 说明                        |
| ------------------------- | ---- | --------------------------- |
| SIM_MESSAGE_STATUS_FREE   | 0    | SIM卡上的状态可用空间       |
| SIM_MESSAGE_STATUS_READ   | 1    | 消息已读状态                |
| SIM_MESSAGE_STATUS_UNREAD | 3    | 消息未读状态                |
| SIM_MESSAGE_STATUS_SENT   | 5    | 存储发送消息（仅适用于SMS） |
| SIM_MESSAGE_STATUS_UNSENT | 7    | 储未发送消息（仅适用于SMS） |

## RanType<sup>7+</sup>

设备网络制式。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.SmsMms。

|   名称    | 值   | 说明 |
| --------- | ---- | ---- |
| TYPE_GSM  | 1    | GSM  |
| TYPE_CDMA | 2    | CMDA |

## SmsEncodingScheme<sup>8+</sup>

短信编码方案。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.SmsMms。

|         名称         | 值   | 说明         |
| -------------------- | ---- | ------------ |
| SMS_ENCODING_UNKNOWN | 0    | 未知短信编码 |
| SMS_ENCODING_7BIT    | 1    | 7位短信编码  |
| SMS_ENCODING_8BIT    | 2    | 8位短信编码  |
| SMS_ENCODING_16BIT   | 3    | 16位短信编码 |

## SimMessageOptions<sup>7+</sup>

SIM卡消息选项。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.SmsMms。

|  名称  | 类型                                   | 必填 | 说明           |
| ------ | -------------------------------------- | ---- | -------------- |
| slotId | number                                 | 是   | 卡槽ID         |
| smsc   | string                                 | 是   | 短消息业务中心 |
| pdu    | string                                 | 是   | 协议数据单元   |
| status | [SimMessageStatus](#simmessagestatus7) | 是   | 状态           |

## UpdateSimMessageOptions<sup>7+</sup>

更新SIM卡消息选项。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.SmsMms。

|   名称    | 类型                                   | 必填 | 说明           |
| --------- | -------------------------------------- | ---- | -------------- |
| slotId    | number                                 | 是   | 卡槽ID         |
| msgIndex  | number                                 | 是   | 消息索引       |
| newStatus | [SimMessageStatus](#simmessagestatus7) | 是   | 新状态         |
| pdu       | string                                 | 是   | 协议数据单元   |
| smsc      | string                                 | 是   | 短消息业务中心 |

## SimShortMessage<sup>7+</sup>

SIM卡短消息。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.SmsMms。

|       名称       | 类型                                   | 必填 | 说明          |
| ---------------- | -------------------------------------- | ---- | ------------- |
| shortMessage     | [ShortMessage](#shortmessage)          | 是   | 短消息        |
| simMessageStatus | [SimMessageStatus](#simmessagestatus7) | 是   | SIM卡消息状态 |
| indexOnSim       | number                                 | 是   | SIM卡索引     |

## MmsDeliveryInd<sup>8+</sup>

彩信发送标识。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.SmsMms。

|    名称   | 类型                               | 必填 | 说明   |
| --------- | ---------------------------------- | ---- | ------ |
| messageId | string                             | 是   | 消息ID |
| date      | number                             | 是   | 日期   |
| to        | Array<[MmsAddress](#mmsaddress8)\> | 是   | 发送至 |
| status    | number                             | 是   | 状态   |
| version   | [MmsVersionType](#mmsversiontype8) | 是   | 版本   |

## MmsRespInd<sup>8+</sup>

彩信回复标志。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.SmsMms。

|     名称      | 类型                               | 必填 | 说明     |
| ------------- | ---------------------------------- | ---- | -------- |
| transactionId | string                             | 是   | 事件ID   |
| status        | number                             | 是   | 状态     |
| version       | [MmsVersionType](#mmsversiontype8) | 是   | 版本     |
| reportAllowed | [ReportType](#reporttype8)         | 否   | 允许报告 |

## SmsSegmentsInfo<sup>8+</sup>

短信段信息。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.SmsMms。

|        名称          | 类型                                     | 必填 | 说明         |
| -------------------- | ---------------------------------------- | ---- | ------------ |
| splitCount           | number                                   | 是   | 拆分计数     |
| encodeCount          | number                                   | 是   | 编码计数     |
| encodeCountRemaining | number                                   | 是   | 剩余编码计数 |
| scheme               | [SmsEncodingScheme](#smsencodingscheme8) | 是   | 短信编码方案 |
