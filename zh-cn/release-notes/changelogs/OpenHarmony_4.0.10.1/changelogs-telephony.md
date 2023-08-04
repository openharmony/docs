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
