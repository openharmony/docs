# 电话子系统ChangeLog



## cl.telephony.radio.1 isNrSupported接口变更


NR是专有名词，需要全部大写。

开发者需要根据以下说明对应用进行适配。



**变更影响**

基于此前版本开发的应用，需适配变更的js接口，变更前的接口已经不能正常使用了，否则会影响原有功能。



**关键的接口/组件变更**

- 涉及接口

  isNrSupported(): boolean;
  isNrSupported(slotId: number): boolean;

- 变更前：

```js
function isNrSupported(): boolean;
function isNrSupported(slotId: number): boolean;
```

- 变更后：

```js
function isNRSupported(): boolean;
function isNRSupported(slotId: number): boolean;
```



**适配指导**

使用变更后的接口，示例代码如下：

```js
let result = radio.isNrSupported();
console.log("Result: "+ result);
```


```js
let slotId = 0;
let result = radio.isNRSupported(slotId);
console.log("Result: "+ result);
```


## cl.telephony.call.2 dial接口变更

从API9开始，废弃此接口，改为使用dialCall接口。

开发者需要根据以下说明对应用进行适配。


**变更影响**

该接口删除无法再使用，请使用新增的接口dialCall替换，否则会影响原有功能。


**关键的接口/组件变更**

- 涉及接口

  dial(phoneNumber: string, callback: AsyncCallback<boolean>): void;
  dial(phoneNumber: string, options: DialOptions, callback: AsyncCallback<boolean>): void;
  dial(phoneNumber: string, options?: DialOptions): Promise<boolean>;

- 变更前：

```js
function dial(phoneNumber: string, callback: AsyncCallback<boolean>): void;
function dial(phoneNumber: string, options: DialOptions, callback: AsyncCallback<boolean>): void;
function dial(phoneNumber: string, options?: DialOptions): Promise<boolean>;
```

- 变更后：

```js
function dialCall(phoneNumber: string, callback: AsyncCallback<void>): void;
function dialCall(phoneNumber: string, options: DialCallOptions, callback: AsyncCallback<void>): void;
function dialCall(phoneNumber: string, options?: DialCallOptions): Promise<void>;
```



**适配指导**

该接口删除无法再使用，请使用新增的接口dialCall替换。
使用变更后的接口，示例代码如下：

```js
call.dialCall("138xxxxxxxx", (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


```js
call.dialCall("138xxxxxxxx", {
    accountId: 0,
    videoState: 0,
    dialScene: 0,
    dialType: 0,
}, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


```js
try {
    call.dialCall('138xxxxxxxx');
    console.log(`dialCall success, promise: data->${JSON.stringify(data)}`);
} catch (error) {
    console.log(`dialCall fail, promise: err->${JSON.stringify(error)}`);
}
```

