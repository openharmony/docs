# Telephony Subsystem Changelog



## cl.telephony.radio.1 isNrSupported API Change


NR is a proper noun and must be capitalized.

You need to adapt your application.



**Change Impact**

The JS API needs to be adapted for applications developed based on earlier versions. Otherwise, relevant functions will be affected.



**Key API/Component Changes**

- Involved APIs:

  isNrSupported(): boolean;
  isNrSupported(slotId: number): boolean;

- Before change:

```js
function isNrSupported(): boolean;
function isNrSupported(slotId: number): boolean;
```

- After change:

```js
function isNRSupported(): boolean;
function isNRSupported(slotId: number): boolean;
```



**Adaptation Guide**

Use the new API. The sample code is as follows:

```js
let result = radio.isNrSupported();
console.log("Result: "+ result);
```


```js
let slotId = 0;
let result = radio.isNRSupported(slotId);
console.log("Result: "+ result);
```


## cl.telephony.call.2 dial API Change

Changed the `dial` API to the `dialCall` API in the call module of the telephony subsystem since API version 9.

You need to adapt your application.


**Change Impact**

The `dial` API is deprecated and cannot be used anymore. Use the `dialCall` API instead. Otherwise, relevant functions will be affected.


**Key API/Component Changes**

- Involved APIs:

  dial(phoneNumber: string, callback: AsyncCallback<boolean>): void;
  dial(phoneNumber: string, options: DialOptions, callback: AsyncCallback<boolean>): void;
  dial(phoneNumber: string, options?: DialOptions): Promise<boolean>;

- Before change:

```js
function dial(phoneNumber: string, callback: AsyncCallback<boolean>): void;
function dial(phoneNumber: string, options: DialOptions, callback: AsyncCallback<boolean>): void;
function dial(phoneNumber: string, options?: DialOptions): Promise<boolean>;
```

- After change:

```js
function dialCall(phoneNumber: string, callback: AsyncCallback<void>): void;
function dialCall(phoneNumber: string, options: DialCallOptions, callback: AsyncCallback<void>): void;
function dialCall(phoneNumber: string, options?: DialCallOptions): Promise<void>;
```



**Adaptation Guide**

The `dial` API is deprecated and cannot be used anymore. Use the `dialCall` API instead.
Use the new API. The sample code is as follows:

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
