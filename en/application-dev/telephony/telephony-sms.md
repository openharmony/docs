# SMS Service Development

## When to Use

The Short Messaging Service (SMS) module provides basic SMS management functions. You can create and send SMS messages, and obtain the ID of the default SIM card used to send and receive SMS messages. Besides, you can obtain and set the SMSC address, and check whether the current device can send and receive SMS messages.

## Basic Concepts

- SMS

  A service capable of SMS message storage and forwarding. It enables mobile phones to send and receive SMS messages. The content of the SMS message can be text, digits, or binary non-text data. The information about the sender is stored in the Short Message Service Center (SMSC) and forwarded to the recipient.

- SMSC

  An entity that relays, stores, or forwards SMS messages between base stations and mobile devices. It uses the GSM 03.40 protocol for sending SMS messages to or receiving SMS messages from mobile phones.

- PDU

  Protocol data unit, which uses the following encoding schemes to send and receive SMS messages: 7-bit, 8-bit, and UCS-2. 7-bit encoding is used to send common ASCII characters, 8-bit encoding to send data messages, and UCS-2 encoding to send Unicode characters.

## Constraints

1. The SMS service is available only on standard-system devices.
2. An available SIM card must be present on the device, and the permission to send SMS messages must be granted.


## Available APIs

> **NOTE**
> To maximize the application running efficiency, most API calls are called asynchronously in callback or promise mode. The following code examples use the callback mode. For details about the APIs, see [API Reference](../reference/apis-telephony-kit/js-apis-sms.md).

| Name                                                      | Description                                                   |
| ------------------------------------------------------------ | ------------------------------------------------------- |
| sendShortMessage(options: SendMessageOptions, callback: AsyncCallback\<void\>): void              | Sends text or data SMS messages. You need to request for the **ohos.permission.SEND_MESSAGES** permission, which is available only for system applications.     |
| createMessage(pdu: Array\<number\>, specification: string, callback: AsyncCallback\<ShortMessage\>): void | Creates an SMS message instance based on the PDU and the specified SMS protocol.|
| getDefaultSmsSlotId(callback: AsyncCallback\<number\>): void   | Obtains the ID of the default SIM card used to send SMS messages.                                               |
| <!--DelRow-->setSmscAddr(slotId: number, smscAddr: string, callback: AsyncCallback\<void\>): void | Sets the SMSC address based on the specified slot ID.               |
| <!--DelRow-->getSmscAddr(slotId: number, callback: AsyncCallback\<string>): void | Obtains the SMSC address based on the specified slot ID.                                 |

<!--Del-->
## How to Develop (for System Applications Only)

1. Declare the required permission:
   - To send SMS messages, call the **sendShortMessage** API and declare the **ohos.permission.SEND\_MESSAGES** permission. The permission is of the **system\_basic** level.
   - To set the SMSC address, call the** setSmscAddr** API and declare the **ohos.permission.SET\_TELEPHONY\_STATE** permission. The permission is of the **system\_basic** level.
   - To obtain the SMSC address, call the** getSmscAddr** API and declare the **ohos.permission.GET\_TELEPHONY\_STATE** permission. The permission is of the **system\_basic** level.
   Before requesting the permission, ensure that the [basic principles for using permissions](../security/AccessToken/app-permission-mgmt-overview.md#basic-principles-for-using-permissions) are met. Then, declare the required permission by referring to [Requesting Application Permissions](../security/AccessToken/determine-application-mode.md#requesting-permissions-for-system_basic-applications).

2. Import the required modules.

3. Send an SMS message.

```ts
// Sample code
import { sms } from '@kit.TelephonyKit';
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';

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
sms.sendShortMessage(options, (err: BusinessError) => {
    console.log(`callback: err->${JSON.stringify(err)}`);
});

```
<!--DelEnd-->

## How to Develop

The API for sending SMS messages can be called only after the required system permission is granted. For a third-party application, it also needs to implement the function of redirecting to the SMS editing page and obtaining the edited content and recipient number by calling the **startAbility** API.

```ts
// Sample code
import { common, Want } from '@kit.AbilityKit';

const MMS_BUNDLE_NAME = "com.ohos.mms";
const MMS_ABILITY_NAME = "com.ohos.mms.MainAbility";
const MMS_ENTITIES = "entity.system.home";

export class Contact {
    contactsName: string;
    telephone: number;

    constructor(contactsName: string, telephone: number) {
        this.contactsName = contactsName;
        this.telephone = telephone;
    }
}

@Entry
@Component
struct JumpMessage {
    private context = getContext(this) as common.UIAbilityContext;

    startMMSAbilityExplicit() {
        // Complete the contact and number. You can query the contact name based on the phone number. Therefore, the phone number is mainly used in this mode.
        let params: Array<Object> = [new Contact ("Tom", 13344556677)];

        let want: Want = {
            bundleName: "com.ohos.mms",
            abilityName: "com.ohos.mms.MainAbility",
            parameters: {
                contactObjects: JSON.stringify(params),
                pageFlag: "conversation",
                // Enter the SMS message content.
                content: "SMS message content"
            }
        };

        this.context.startAbilityForResult(want).then((data) => {
            console.log("Success" + JSON.stringify(data));
        }).catch(() => {
            console.log("error");
        });
    }

    build() {
        Row() {
            Column() {
                Button ('Send SMS')
                  .onClick(() => {
                      this.startMMSAbilityExplicit();
                  })
            }
            .width('100%')
        }
        .height('100%')
    }
}

```
