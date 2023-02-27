# Telephony Subsystem Changelog



## cl.telephony.1 Call Module dial API Change

Changed the `dial` API to the `dialCall` API in the call module of the telephony subsystem since API version 9.

You need to adapt your application.


**Change Impact**

The `dial` API is deprecated and cannot be used anymore. Use the `dialCall` API instead. Otherwise, relevant functions will be affected.


**Key API/Component Changes**

- Involved APIs:

```js
  dial(phoneNumber: string, callback: AsyncCallback<boolean>): void;
  dial(phoneNumber: string, options: DialOptions, callback: AsyncCallback<boolean>): void;
  dial(phoneNumber: string, options?: DialOptions): Promise<boolean>;
```

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

The `dial` API is deprecated and cannot be used anymore. Use the `dialCall` API instead. Otherwise, relevant functions will be affected.
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
