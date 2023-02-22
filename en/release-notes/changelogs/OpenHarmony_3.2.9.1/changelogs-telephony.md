# Telephony Subsystem Changelog



## cl.telephony.1 Input Parameter Change of System APIs of the SMS Module

Input parameters are changed for some released system APIs of the SMS module of the telephony subsystem, which do not comply with the API specifications of OpenHarmony. The following changes are made in API version 9 and later:

The **slotId** parameter is added to the **isImsSmsSupported** API, indicating the slot ID.

**Change Impacts**

Input parameters of JavaScript APIs need to be adapted for applications developed based on earlier versions. Otherwise, relevant functions will be affected.

**Key API/Component Changes**

- Involved APIs

  isImsSmsSupported(callback: AsyncCallback<boolean>): void;
  isImsSmsSupported(): Promise<boolean>;

- Before change:

```js
function isImsSmsSupported(callback: AsyncCallback<boolean>): void;
function isImsSmsSupported(): Promise<boolean>;
```

- After change:

```js
function isImsSmsSupported(slotId: number, callback: AsyncCallback<boolean>): void;
function isImsSmsSupported(slotId: number): Promise<boolean>;
```

**Adaptation Guide**

Add an input parameter. The sample code is as follows:

Callback mode

```js
let slotId = 0;
sms.isImsSmsSupported(slotId, (err, data) => {
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

Promise mode

```js
let slotId = 0;
let promise = sms.isImsSmsSupported(slotId);
promise.then(data => {
    console.log(`isImsSmsSupported success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`isImsSmsSupported failed, promise: err->${JSON.stringify(err)}`);
});
```