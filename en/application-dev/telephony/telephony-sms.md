# SMS Service Development

## Scenario Description

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
| createMessage(pdu: Array\<number>, specification: string, callback: AsyncCallback\<ShortMessage>): void | Creates an SMS message instance based on the PDU and the specified SMS protocol.|
| sendMessage(options: SendMessageOptions): void               | Sends text or data SMS messages.                                                     |
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

3. Create an SMS message instance based on the PDU and the specified SMS protocol.

4. Send an SMS message.

   ```js
    // Import the required modules.
    import sms from '@ohos.telephony.sms'
   
    export default class SmsModel {
        async createMessage() {
            const specification = '3gpp'
            const pdu = [0x08, 0x91] // Display PDUs in array format. The type is number.
            const shortMessage = await sms.createMessage(pdu, specification)
            Logger.info(`${TAG}, createMessageCallback: shortMessage = ${JSON.stringify(shortMessage)}`)
            return shortMessage
        }
   
        sendMessage(slotId, content, destinationHost, serviceCenter, destinationPort, handleSend, handleDelivery) {
            Logger.info(`${TAG}, sendMessage start ${slotId} ${content} ${destinationHost} ${serviceCenter} ${destinationPort}`)
            const options =
            {
                slotId: slotId,
                content: content,
                destinationHost: destinationHost,
                serviceCenter: serviceCenter,
                destinationPort: destinationPort,
                sendCallback(err, data) {
                    Logger.info(`${TAG}, sendCallback: data = ${JSON.stringify(data)} err = ${JSON.stringify(err)}`)
                    handleSend(err, data)
                },
                deliveryCallback(err, data) {
                    Logger.info(`${TAG}, deliveryCallback: data = ${JSON.stringify(data)} err = ${JSON.stringify(err)}`)
                    handleDelivery(err, data)
                }
            }
            // Send an SMS message.
            sms.sendMessage(options)
            Logger.info(`${TAG}, sendMessage end`)
        }
   
        // Obtain the ID of the default SIM card used to send SMS messages.
        async getDefaultSmsSlotId() {
            const defaultSmsSlotId = await sms.getDefaultSmsSlotId()
            Logger.info(`${TAG}, getDefaultSmsSlotId: defaultSmsSlotId = ${defaultSmsSlotId}`)
            return defaultSmsSlotId
        }
   
        // Set the SMSC address based on the specified slot ID.
        async setSmscAddr(slotId, smscAddr) {
            const serviceCenter = await sms.setSmscAddr(slotId, smscAddr)
            Logger.info(`${TAG}, setSmscAddr: serviceCenter = ${JSON.stringify(serviceCenter)}`)
            return serviceCenter
        }
   
        // Obtain the SMSC address based on the specified slot ID.
        async getSmscAddr(slotId) {
            const serviceCenter = await sms.getSmscAddr(slotId)
            Logger.info(`${TAG}, getSmscAddr: serviceCenter = ${JSON.stringify(serviceCenter)}`)
            return serviceCenter
        }
    }
   ```
