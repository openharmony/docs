# 电话子系统ChangeLog



## cl.telephony.1 sms模块接口变更

sendMessage接口作废弃处理，变更为sendShortMessage接口。

**变更影响**

从API version 10开始，sendMessage接口废弃。应用需要自行适配为sendShortMessage。接口功能不变。

**关键的接口/组件变更**

修改前的接口原型：

```js
function sendMessage(options: SendMessageOptions): void;
```

修改后的接口原型：

```js
function sendShortMessage(options: SendMessageOptions, callback: AsyncCallback<void>): void;
function sendShortMessage(options: SendMessageOptions): Promise<void>;
```



**适配指导**

使用变更后的接口，示例代码如下：

```js
import sms from '@ohos.telephony.sms';

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
sms.sendShortMessage(options, (err) => {
    console.log(`callback: err->${JSON.stringify(err)}`);
});
```

```js
import sms from '@ohos.telephony.sms';

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
let promise = sms.sendShortMessage(options);
promise.then(() => {
    console.log(`sendShortMessage success`);
}).catch(err => {
    console.error(`sendShortMessage failed, promise: err->${JSON.stringify(err)}`);
});

```

## cl.telephony.2 sim模块接口变更

getSimTelephoneNumber接口权限变更，由ohos.permission.GET_TELEPHONY_STATE变更为ohos.permission.GET_PHONE_NUMBERS。

**变更影响**

从API version 10开始，getSimTelephoneNumber接口权限变更为ohos.permission.GET_PHONE_NUMBERS。

应用需要修改为申请权限ohos.permission.GET_PHONE_NUMBERS。接口功能不变。

**关键的接口/组件变更**

修改前的接口原型：

```js
  @permission ohos.permission.GET_TELEPHONY_STATE
  function getSimTelephoneNumber(slotId: number, callback: AsyncCallback<string>): void;

  @permission ohos.permission.GET_TELEPHONY_STATE
  function getSimTelephoneNumber(slotId: number): Promise<string>;
```

修改后的接口原型：

```js
  @permission ohos.permission.GET_PHONE_NUMBERS
  function getSimTelephoneNumber(slotId: number, callback: AsyncCallback<string>): void;
  
  @permission ohos.permission.GET_PHONE_NUMBERS
  function getSimTelephoneNumber(slotId: number): Promise<string>;
```



**适配指导**

使用变更后的接口，示例代码如下：

module.json中申请权限需要更换或者添加ohos.permission.GET_PHONE_NUMBERS。

```js
"requestPermissions" : [
    {
        "name": "ohos.permission.GET_PHONE_NUMBERS",
        "reason": "$string:GET_PHONE_NUMBERS"
       }
]
```