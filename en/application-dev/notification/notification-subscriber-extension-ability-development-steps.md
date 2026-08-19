# Developing the ExtensionAbility for Notification Subscription

<!--Kit: Notification Kit-->
<!--Subsystem: Notification-->
<!--Owner: @HuYueRong-->
<!--Designer: @dongqingran-->
<!--Tester: @wanghong1997-->
<!--Adviser: @fang-jinxu-->
<!-- md-trans-meta sourceCommit=661a14238183b0e458a09cda6a06543844926c5b translatedAt=2026-08-13T03:11:40.983Z pushedAt=2026-08-13T07:40:11.019Z -->

## Available APIs

| API                             | Description               |
| ---------------------------------- | --------------------|
| [onDestroy(): void](../reference/apis-notification-kit/js-apis-notificationSubscriberExtensionAbility.md#ondestroy)                  | Callback to be invoked when the notification subscription extension is destroyed.|
| [onReceiveMessage(notificationInfo: NotificationInfo): void](../reference/apis-notification-kit/js-apis-notificationSubscriberExtensionAbility.md#onreceivemessage) | Callback to be invoked when a notification is received.|
| [onCancelMessages(hashCodes: Array\<string>): void](../reference/apis-notification-kit/js-apis-notificationSubscriberExtensionAbility.md#oncancelmessages) | Callback to be invoked when notifications are canceled.|

## Prerequisites

You have requested the [ohos.permission.SUBSCRIBE_NOTIFICATION](../security/AccessToken/restricted-permissions.md#ohospermissionsubscribe_notification) permission.

## How to Develop

To implement a provider for [NotificationSubscriberExtensionAbility](../reference/apis-notification-kit/js-apis-notificationSubscriberExtensionAbility.md), you need to create a **NotificationSubscriberExtensionAbility** in [DevEco Studio](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-tools-overview) project. The procedure is as follows:

1. Create the **entry/src/main/ets/extensionability** directory.

2. Create the **NotificationSubscriberExtAbility.ets** file in the **entry/src/main/ets/extensionability** directory. The file content is as follows:

   <!--@[callback_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Notification-Kit/ThirdpartyWearableDemo/entry/src/main/ets/extensionability/NotificationSubscriberExtAbility.ets)-->   

   ``` TypeScript
   import { hilog } from '@kit.PerformanceAnalysisKit';
   import { notificationExtensionSubscription, NotificationSubscriberExtensionAbility } from '@kit.NotificationKit';
   // ...
   
   const DOMAIN = 0x0000;
   // ...
   export class NotificationSubscriberExtAbility extends NotificationSubscriberExtensionAbility {
     // ...
     onDestroy(): void {
       hilog.info(DOMAIN, 'testTag', 'onDestroy');
       // ...
     }
     // ...
     onReceiveMessage(notificationInfo: notificationExtensionSubscription.NotificationInfo): void {
       hilog.info(DOMAIN, 'testTag', `on receive message ${JSON.stringify(notificationInfo)}`)
       // ...
     }
     // ...
     onCancelMessages(hashCodes: Array<string>): void {
       hilog.info(DOMAIN, 'testTag', `on cancel message ${JSON.stringify(hashCodes)}`)
       // ...
     }
     // ...
   }
   ```

3. Use the [Bluetooth module](../connectivity/connectivity-kit-intro.md#bluetooth) API to pair with the wearable (with Bluetooth in pairing state) and obtain the device address. Then, subscribe to or unsubscribe from notifications through the [subscribe](../reference/apis-notification-kit/js-apis-notificationExtensionSubscription.md#notificationextensionsubscriptionsubscribe)/[unsubscribe](../reference/apis-notification-kit/js-apis-notificationExtensionSubscription.md#notificationextensionsubscriptionunsubscribe) APIs.

4. After implementing [NotificationSubscriberExtensionAbility](../reference/apis-notification-kit/js-apis-notificationSubscriberExtensionAbility.md), call the [openSubscriptionSettingsWithResult](../reference/apis-notification-kit/js-apis-notificationExtensionSubscription.md#notificationextensionsubscriptionopensubscriptionsettingswithresult) API at an appropriate time to open the notification subscription settings screen and guide the user to grant the permission for obtaining notifications from the device. This screen is displayed as a semi-modal dialog box, and the authorization result is returned when the dialog box is closed. It is recommended that you provide a notification authorization button on the device management screen. When the user taps the button, the [openSubscriptionSettingsWithResult](../reference/apis-notification-kit/js-apis-notificationExtensionSubscription.md#notificationextensionsubscriptionopensubscriptionsettingswithresult) API is called.

5. Configure **ExtensionAbilities** in the **module.json5** file of the application.

   <!--@[quick_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Notification-Kit/ThirdpartyWearableDemo/entry/src/main/module.json5)-->

   ``` JSON5
   {
     "name": "NotificationSubscriberExtAbility",
     "srcEntry": "./ets/extensionability/NotificationSubscriberExtAbility.ets",
     "type": "notificationSubscriber",
     "description": "$string:NotificationSubscriberExtAbility_desc",
     "icon": "$media:layered_image",
     "label": "$string:NotificationSubscriberExtAbility_label",
     "exported": true
   }
   ```

6. Add the following content to the **string.json** file of the application:

    ```json
    [
      {
        "name": "NotificationSubscriberExtAbility_desc",
        "value": "description"
      },
      {
        "name": "NotificationSubscriberExtAbility_label",
        "value": "ThirdPartyWearableApp"
      }
    ]
    ```

7. The following uses classic Bluetooth as an example. You can use BLE for connection as required.

8. After the user receives a message, the application establishes a Bluetooth connection if the current connection is invalid.

9. If an active Bluetooth connection already exists, the application directly uses this connection to send the message.

10. If message transmission fails over this Bluetooth connection, the application re-establishes the connection and sends the message once the connection is successfully established.

11. Apply for the [ohos.permission.ACCESS_BLUETOOTH](../security/AccessToken/permissions-for-all-user.md#ohospermissionaccess_bluetooth) permission. For details about how to configure and apply for permissions, see [Declaring Permissions](../security/AccessToken/declare-permissions.md) and [Requesting User Authorization](../security/AccessToken/request-user-authorization.md).

    <!--@[quick_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Notification-Kit/ThirdpartyWearableDemo/entry/src/main/ets/extensionability/NotificationSubscriberExtAbility.ets)-->    

    ``` TypeScript
    import { hilog } from '@kit.PerformanceAnalysisKit';
    import { notificationExtensionSubscription, NotificationSubscriberExtensionAbility } from '@kit.NotificationKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    import { socket } from '@kit.ConnectivityKit'
    import { util } from '@kit.ArkTS'; 
    
    const DOMAIN = 0x0000;
    class TransferInfo {
      public type: string = ''
      public info: notificationExtensionSubscription.NotificationInfo | undefined
      public cancelHashCodes: Array<string> | undefined
    }
    // Spp means Serial Port Profile
    class SppClientManager {
      private clientNumber: number = -1;
      private peerDevice: string = '';
      private connectPromise: Promise<boolean> | null = null;
    
      constructor(peerDevice: string) {
        this.peerDevice = peerDevice
      }
    
      public isConnect(): boolean {
        return this.clientNumber !== -1;
      }
    
      public startConnect(): Promise<boolean> {
        if (this.isConnect()) {
          return Promise.resolve(true);
        }
        if (this.connectPromise) {
          return this.connectPromise;
        }
        this.connectPromise = new Promise((resolve) => {
          let option: socket.SppOptions = {
            uuid: '00009999-0000-1000-8000-00805F9B34FB', // UUID of the server to connect to, ensure server support
            secure: false,
            type: socket.SppType.SPP_RFCOMM
          };
          socket.sppConnect(this.peerDevice, option, (err: BusinessError, num: number) => {
            this.connectPromise = null;
            if (err) {
              hilog.error(DOMAIN, 'testTag', `cpp connect failed, errCode: ${err.code}, errMessage: ${err.message}`);
              resolve(false);
            } else {
              hilog.info(DOMAIN, 'testTag', `spp connect success clientNumber: ${num}`);
              this.clientNumber = num;
              socket.on('sppRead', this.clientNumber, this.read);
              resolve(true);
            }
          });
        });
        return this.connectPromise;
      }
    
      private sendData(jsonStr: string) {
        if (!this.isConnect()) {
          hilog.error(DOMAIN, 'testTag', `server is not connected`);
          return;
        }
        if (!jsonStr) {
          hilog.error(DOMAIN, 'testTag', 'json is empty');
          return;
        }
        hilog.info(DOMAIN, 'testTag', `prepare sending data to client ${this.clientNumber}`);
        const textEncoder:util.TextEncoder = new util.TextEncoder();
        const uint8Array: Uint8Array = textEncoder.encodeInto(jsonStr);
        const arrayBuffer = uint8Array.buffer;
    
        socket.sppWrite(this.clientNumber, arrayBuffer);
        hilog.info(DOMAIN, 'testTag', `sending success size: ${arrayBuffer.byteLength} bytes, data: ${jsonStr}`);
      }
    
      public sendNotificationData(notificationInfo: notificationExtensionSubscription.NotificationInfo) {
        let info: TransferInfo = {
          type: 'publish',
          info: notificationInfo,
          cancelHashCodes: undefined
        };
    
        let jsonStr = JSON.stringify(info);
        this.sendData(jsonStr);
      }
    
      public sendCancelNotificationData(cancelHashCodes: Array<string>) {
        let info: TransferInfo = {
          type: 'cancel',
          cancelHashCodes: cancelHashCodes,
          info: undefined
        };
    
        let jsonStr = JSON.stringify(info);
        this.sendData(jsonStr);
      }
    
      public read = (dataBuffer: ArrayBuffer) => {
        let data = new Uint8Array(dataBuffer);
        hilog.info(DOMAIN, 'testTag', `client data: ${JSON.stringify(data)}`);
      };
    
      public stopConnect() {
        hilog.info(DOMAIN, 'testTag', `closeSppClient ${this.clientNumber}`);
        this.connectPromise = null;
        try {
          socket.off('sppRead', this.clientNumber, this.read);
        } catch (err) {
          hilog.error(DOMAIN, 'testTag', `off sppRead errCode: ${err.code}, errMessage: ${err.message}`);
        }
        try {
          socket.sppCloseClientSocket(this.clientNumber);
        } catch (err) {
          hilog.error(DOMAIN, 'testTag', `stopConnect errCode: ${err.code}, errMessage: ${err.message}`);
        }
        this.clientNumber = -1;
      }
    }
    
    // export SppClientManager;
    export class NotificationSubscriberExtAbility extends NotificationSubscriberExtensionAbility {
      private sppClientManager: SppClientManager | undefined;
      onDestroy(): void {
        hilog.info(DOMAIN, 'testTag', 'onDestroy');
        this.sppClientManager?.stopConnect();
      }
      // Called back when a notification is published.
      onReceiveMessage(notificationInfo: notificationExtensionSubscription.NotificationInfo): void {
        hilog.info(DOMAIN, 'testTag', `on receive message ${JSON.stringify(notificationInfo)}`)
        notificationExtensionSubscription.getSubscribeInfo()
          .then(async (info) => {
            if (this.sppClientManager == undefined) {
              this.sppClientManager = new SppClientManager(info[0].addr);
            }
            if (this.sppClientManager.isConnect()) {
              this.sendPublishWithRetry(notificationInfo);
            } else {
              let connected = await this.sppClientManager.startConnect();
              if (connected) {
                this.sendPublishWithRetry(notificationInfo);
              } else {
                hilog.error(DOMAIN, 'testTag', `startConnect failed, skip send`);
              }
            }
          }).catch((err: BusinessError) => {
          hilog.error(DOMAIN, 'testTag',
            `notificationExtensionSubscription failed, errCode ${err.code}, errorMessage ${err.message}`);
        });
      }
      // Sends a publish notification and retries once upon failure.
      private async sendPublishWithRetry(notificationInfo: notificationExtensionSubscription.NotificationInfo) {
        try {
          this.sppClientManager!.sendNotificationData(notificationInfo);
        } catch (err) {
          hilog.error(DOMAIN, 'testTag', `send failed, errCode ${err.code}, errorMessage ${err.message}, and retry one times`);
          this.sppClientManager!.stopConnect();
          let connected = await this.sppClientManager!.startConnect();
          if (connected) {
            this.sppClientManager!.sendNotificationData(notificationInfo);
          } else {
            hilog.error(DOMAIN, 'testTag', `retry startConnect failed, skip send`);
          }
        }
      }
    
      // Called back when notifications are cancelled.
      onCancelMessages(hashCodes: Array<string>): void {
        hilog.info(DOMAIN, 'testTag', `on cancel message ${JSON.stringify(hashCodes)}`)
        notificationExtensionSubscription.getSubscribeInfo()
          .then(async (info) => {
            if (this.sppClientManager == undefined) {
              this.sppClientManager = new SppClientManager(info[0].addr);
            }
            if (this.sppClientManager.isConnect()) {
              this.sendCancelWithRetry(hashCodes);
            } else {
              let connected = await this.sppClientManager.startConnect();
              if (connected) {
                this.sendCancelWithRetry(hashCodes);
              } else {
                hilog.error(DOMAIN, 'testTag', `startConnect failed, skip send`);
              }
            }
          }).catch((err: BusinessError) => {
          hilog.error(DOMAIN, 'testTag', `notificationExtensionSubscription failed, errCode ${err.code}, errorMessage ${err.message}`);
        });
      }
      // Retries a cancel operation if it fails.
      private async sendCancelWithRetry(hashCodes: string[]) {
        try {
          this.sppClientManager!.sendCancelNotificationData(hashCodes);
        } catch (err) {
          hilog.error(DOMAIN, 'testTag', `send failed, errCode ${err.code}, errorMessage ${err.message}, and retry one times`);
          this.sppClientManager!.stopConnect();
          let connected = await this.sppClientManager!.startConnect();
          if (connected) {
            this.sppClientManager!.sendCancelNotificationData(hashCodes);
          } else {
            hilog.error(DOMAIN, 'testTag', `retry startConnect failed, skip send`);
          }
        }
      }
    }
    ```