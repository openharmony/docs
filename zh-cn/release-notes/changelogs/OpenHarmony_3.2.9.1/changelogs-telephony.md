# 电话子系统ChangeLog



## cl.telephony.1 sms模块SystemAPI接口入参变更

已发布的部分电话子系统sms短信模块SystemAPI传入参数发生变化，不符合OpenHarmony接口规范。从API9开始做出以下变更：

isImsSmsSupported接口新增一个传入参数slotId，表示卡槽号。



**变更影响**

基于此前版本开发的应用，需适配变更js接口的入参，否则会影响原有功能。



**关键的接口/组件变更**

- 涉及接口

  isImsSmsSupported(callback: AsyncCallback<boolean>): void;
  isImsSmsSupported(): Promise<boolean>;

- 变更前：

```js
function isImsSmsSupported(callback: AsyncCallback<boolean>): void;
function isImsSmsSupported(): Promise<boolean>;
```

- 变更后：

```js
function isImsSmsSupported(slotId: number, callback: AsyncCallback<boolean>): void;
function isImsSmsSupported(slotId: number): Promise<boolean>;
```



**适配指导**

新增一个入参，示例代码如下：

callback方式

```js
let slotId = 0;
sms.isImsSmsSupported(slotId, (err, data) => {
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

promise方式

```js
let slotId = 0;
let promise = sms.isImsSmsSupported(slotId);
promise.then(data => {
    console.log(`isImsSmsSupported success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`isImsSmsSupported failed, promise: err->${JSON.stringify(err)}`);
});
```
