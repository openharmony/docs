# Telephone Service Changelog



## cl.telephony.1 SMS Module API Change

Deprecated **sendMessage** and replaced it with **sendShortMessage**.

**Change Impact**

**sendMessage** is deprecated since API version 10. **sendShortMessage** should be used to replace **sendMessage** in application development. The API function remains unchanged.

**Key API/Component Changes**

Before change:

```js
function sendMessage(options: SendMessageOptions): void;
```

After change:

```js
function sendShortMessage(options: SendMessageOptions, callback: AsyncCallback<void>): void;
function sendShortMessage(options: SendMessageOptions): Promise<void>;
```



**Adaptation Guide**

Call the **sendShortMessage** API instead of the **sendMessage** API. The sample code is as follows:

```js
import sms from '@ohos.telephony.sms';

let sendCallback = function (err, data) {
    console.log(`sendCallback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
}
let deliveryCallback = function (err, data) {
    console.log(`deliveryCallback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
}
let slotId = 0;
let content ='SMS message content';
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
let content ='SMS message content';
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

## cl.telephony.2 SIM Module API Change

Changed the required permission of **getSimTelephoneNumber** from **ohos.permission.GET_TELEPHONY_STATE** to **ohos.permission.GET_PHONE_NUMBERS**.

**Change Impact**

The required permission of **getSimTelephoneNumber** is from **ohos.permission.GET_TELEPHONY_STATE** to **ohos.permission.GET_PHONE_NUMBERS** since API version 10.

An application needs to apply for the **ohos.permission.GET_PHONE_NUMBERS** permission. The API function remains unchanged.

**Key API/Component Changes**

Before change:

```js
  @permission ohos.permission.GET_TELEPHONY_STATE
  function getSimTelephoneNumber(slotId: number, callback: AsyncCallback<string>): void;

  @permission ohos.permission.GET_TELEPHONY_STATE
  function getSimTelephoneNumber(slotId: number): Promise<string>;
```

After change:

```js
  @permission ohos.permission.GET_PHONE_NUMBERS
  function getSimTelephoneNumber(slotId: number, callback: AsyncCallback<string>): void;
  
  @permission ohos.permission.GET_PHONE_NUMBERS
  function getSimTelephoneNumber(slotId: number): Promise<string>;
```



**Adaptation Guide**

Set the callback value to **void** when calling **setVoNState**. The sample code is as follows:

In the **module.json** file, add the **ohos.permission.GET_PHONE_NUMBERS** permission or replace the existing permission with it. The sample code is as follows:

```js
"requestPermissions" : [
    {
        "name": "ohos.permission.GET_PHONE_NUMBERS",
        "reason": "$string:GET_PHONE_NUMBERS"
       }
]
```
