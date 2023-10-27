# SMS Service Development

## Overview

The Short Messaging Service (SMS) module provides basic SMS management functions. You can create and send SMS messages, and obtain the ID of the default SIM card used to send and receive SMS messages. Besides, you can obtain and set the SMSC address, and check whether the current device can send and receive SMS messages.

## Basic Concepts

- SMS

  A service capable of SMS message storage and forwarding. It enables mobile phones to send and receive SMS messages. The content of the SMS message can be text, digits, or binary non-text data. The information about the sender is stored in the Short Message Service Center (SMSC) and forwarded to the recipient.

- SMSC

  An entity that relays, stores, or forwards SMS messages between base stations and mobile devices. It uses the GMS 03.40 protocol for sending SMS messages to or receiving SMS messages from mobile phones.

- PDU

  Protocol data unit, which uses the following encoding schemes to send and receive SMS messages: 7-bit, 8-bit, and UCS-2. 7-bit encoding is used to send common ASCII characters, 8-bit encoding to send data messages, and UCS-2 encoding to send Unicode characters.

## Constraints

1. The SMS service is available only on standard-system devices.
2. An available SIM card must be present on the device, and the permission to send SMS messages must be granted.


## Available APIs

> **NOTE**
> To maximize the application running efficiency, most API calls are called asynchronously in callback or promise mode. The following code examples use the callback mode. For details about the APIs, see [sms API Reference](../reference/apis/js-apis-sms.md).

| Name                                                      | Description                                                   |
| ------------------------------------------------------------ | ------------------------------------------------------- |
| sendMessage(options: SendMessageOptions): void               | Sends text or data SMS messages.                                                     |
| createMessage(pdu: Array\<number>, specification: string, callback: AsyncCallback\<ShortMessage>): void | Creates an SMS message instance based on the PDU and the specified SMS protocol.|
| getDefaultSmsSlotId(callback: AsyncCallback\<number>): void   | Obtains the ID of the default SIM card used to send SMS messages.                                               |
| setSmscAddr(slotId: number, smscAddr: string, callback: AsyncCallback\<void>): void | Sets the SMSC address based on the specified slot ID.               |
| getSmscAddr(slotId: number, callback: AsyncCallback\<string>): void | Obtains the SMSC address based on the specified slot ID.                                 |


## How to Develop

1. Declare the required permission:
   - To send SMS messages, call the **sendMessage** API and declare the **ohos.permission.SEND\_MESSAGES** permission. The permission is of the **system\_basic** level.
   - To set the SMSC address, call the** setSmscAddr** API and declare the **ohos.permission.SET\_TELEPHONY\_STATE** permission. The permission is of the **system\_basic** level.
   - To obtain the SMSC address, call the** getSmscAddr** API and declare the **ohos.permission.GET\_TELEPHONY\_STATE** permission. The permission is of the **system\_basic** level.
   Before applying for the permission, ensure that the [basic principles for permission management](../security/accesstoken-overview.md#basic-principles-for-permission-management) are met. Then, declare the corresponding permission by following instructions in [Declaring Permissions in the Configuration File](../security/accesstoken-guidelines.md#declaring-permissions-in-the-configuration-file).

2. Import the required modules.

3. Send an SMS message.

```ts
import sms from '@ohos.telephony.sms';
import { AsyncCallback } from '@ohos.base';
import { BusinessError } from '@ohos.base';

let sendCallback: AsyncCallback<sms.ISendShortMessageCallback> = (err: BusinessError, data: sms.ISendShortMessageCallback) => {
    console.log(`sendCallback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`); 
}
let deliveryCallback: AsyncCallback<sms.IDeliveryShortMessageCallback> = (err: BusinessError, data: sms.IDeliveryShortMessageCallback) => {
    console.log(`deliveryCallback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`); 
}
let slotId: number = 0;
let content: string = 'Message content';
let destinationHost: string = '+861xxxxxxxxxx';
let serviceCenter: string = '+861xxxxxxxxxx';
let destinationPort: number = 1000;
let options: sms.SendMessageOptions = {slotId, content, destinationHost, serviceCenter, destinationPort, sendCallback, deliveryCallback};
sms.sendMessage(options);
```

