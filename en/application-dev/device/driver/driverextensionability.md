# Peripheral Driver Development

## When to Use

[DriverExtensionAbility](../../reference/apis-driverdevelopment-kit/js-apis-app-ability-driverExtensionAbility.md) is an **ExtensionAbility** of the driver type that provides the driver-related extension framework. If the capabilities of a device can be expanded by inserting an external hardware module, you can install the driver of the hardware module through an application. **DriverExtensionAbility** can be used to develop such applications.


You can bind a [DriverExtensionAbility](../../reference/apis-driverdevelopment-kit/js-apis-app-ability-driverExtensionAbility.md) object to an application through **DriverExtensionManager** so that related transactions can be processed in the background based on the application request information.
Each type of **ExtensionAbility** has its own context. The **DriverExtensionAbility** provides related capabilities through the [DriverExtensionContext](../../reference/apis-driverdevelopment-kit/js-apis-inner-application-driverExtensionContext.md).

## Environment Setup

Set up the environment following the instructions in [Peripheral Driver Client Development](externaldevice-guidelines.md).

The following table lists the SDK version requirements.

| NDK API| SDK Version|
|---------|--------|
| USB DDK | API version 10 or later|
| HID DDK | API version 11 or later|

## How to Develop

To implement a driver, create a DriverExtensionAbility in the DevEco Studio project. The procedure is as follows:

1. In the **ets** directory of a module in the project, right-click and choose **New > Directory** to create a directory named **driverextability**.

2. In the **driverextability** directory, right-click and choose **New > ArkTS File** to create a file named **DriverExtAbility.ets**.

3. Import the related kit, and define the request code.

    ```ts
    import { DriverExtensionAbility } from '@kit.DriverDevelopmentKit';
    import { Want } from '@kit.AbilityKit';
    import { rpc } from '@kit.IPCKit';

    const REQUEST_CODE = 99; // Negotaite the request code with the peripheral client.
    ```

4. Open the **DriverExtAbility.ets** file, import the [RPC module](../../reference/apis-ipc-kit/js-apis-rpc.md), and overload the **onRemoteMessageRequest()** method to receive messages from the application and return the processing result to the application. **REQUEST_VALUE** is used to verify the service request code sent by the application.

    ```ts
    class StubTest extends rpc.RemoteObject {
      // Receive a message from the application and return the processing result to the client.
      onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence,
        option: rpc.MessageOption) {
        if (code === REQUEST_CODE) {
          // Receive the data sent from the application.
          // When the application calls data.writeString() multiple times to write data, the driver can receive the corresponding data by calling data.readString() for multiple times.
          let optFir: string = data.readString();
          // The driver returns the data processing result to the application.
          // In the example, Hello is received and Hello World is returned to the  application.
          reply.writeString(optFir + ` World`);
        }
        return true;
      }
    }
    ```

5. In the **DriverExtAbility.ets** file, import the dependency package [DriverExtensionAbility](../../reference/apis-driverdevelopment-kit/js-apis-app-ability-driverExtensionAbility.md), which provides the **onInit()**, **onRelease()**, **onConnect()**, and **onDisconnect()** lifecycle callbacks. Then, customize a class to inherit from [DriverExtensionAbility](../../reference/apis-driverdevelopment-kit/js-apis-app-ability-driverExtensionAbility.md) and override the lifecycle callbacks as required.

    ```ts
    export default class DriverExtAbility extends DriverExtensionAbility {
      onInit(want: Want) {
        console.info('testTag', `onInit, want: ${want.abilityName}`);
      }

      onRelease() {
        console.info('testTag', `onRelease`);
      }

      onConnect(want: Want) {
        console.info('testTag', `onConnect, want: ${want.abilityName}`);
        return new StubTest("test");
      }

      onDisconnect(want: Want) {
        console.info('testTag', `onDisconnect, want: ${want.abilityName}`);
      }

      onDump(params: Array<string>) {
        console.info('testTag', `onDump, params:` + JSON.stringify(params));
        return ['params'];
      }
    }
    ```

6. Register **DriverExtensionAbility** in the [**module.json5** file](../../quick-start/module-configuration-file.md) of the module in the project. Set **type** to **service** and **srcEntry** to the code path of **DriverExtensionAbility**.

    ```json
    {
      "module": {
        "name": "entry",
        "type": "entry",
        "description": "$string:module_desc",
        "mainElement": "EntryAbility",
        "deviceTypes": [
          "default",
          "tablet"
        ],
        "requestPermissions": [
          {
            "name": "ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER" // Peripheral-specific permission, which is mandatory.
          }
        ],
        "deliveryWithInstall": true,
        "installationFree": false,
        "pages": "$profile:main_pages",
        "abilities": [
          {
            "name": "EntryAbility",
            "srcEntry": "./ets/entryability/EntryAbility.ets",
            "description": "$string:EntryAbility_desc",
            "icon": "$media:startIcon",
            "label": "$string:EntryAbility_label",
            "startWindowIcon": "$media:startIcon",
            "startWindowBackground": "$color:start_window_background",
            "exported": true,
            "skills": [
              {
                "entities": [
                  "entity.system.home"
                ],
                "actions": [
                  "action.system.home"
                ]
              }
            ]
          }
        ],
        "extensionAbilities": [
          {
            "name": "DriverExtAbility",
            "icon": "$media:startIcon",
            "description": "driver",
            "type": "driver",
            "exported": true,
            "srcEntry": "./ets/driverextability/DriverExtAbility.ets",
            "metadata": [
              {
                "name": "bus", // The bus is mandatory.
                "value": "USB"
              },
              {
                "name": "desc", // Driver description, which is optional.
                "value": "the sample of driverExtensionAbility"
              },
              {
                "name": "vendor", // Driver vendor name, which is optional.
                "value": "string"
              },
              {
                "name": "vid," // List of USB vendor IDs. Enter a hex value. Here, the value is the hex value of 4817.
                "value": "0x12D1"
              },
              {
                "name": "pid," // List of USB product IDs. Enter a hex value. Here, the value is the hex value of 4258.
                "value": "0x10A2"
              }
            ]
          }
        ]
      }
    }
    ```

7. After completing development of the client and driver sample code, import the HAP to the device by following instructions in [Running Your App/Service on a Local Real Device](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V13/ide-run-device-V13), and run **Hello** in the HAP to check whether **Hello world** is displayed. If yes, the IPC communication is ready for use.

## Driver Development

**DriverExtensionAbility** provides two development modes, namely, HID DDK and USB DDK, for driver development.

Choose either mode depending on your need:

* [HID DDK Development](https://gitee.com/openharmony/docs/blob/master/en/application-dev/napi/hid-ddk-guidelines.md)
* [USB DDK Development](https://gitee.com/openharmony/docs/blob/master/en/application-dev/napi/usb-ddk-guidelines.md)

## Application Signing

You need to configure a signature file for your application to run on a device. Besides, to develop a peripheral driver client, you need to declare the **ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER** permission for the peripheral.

If the HID DDK or USB DDK is used, configure the required permission as described above.

Automatic signing: [Signing Your App/Service Automatically](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/ide-signing-V5#section18815157237)

Permission configuration: [Requesting ACL Permissions and Signing Your App/Service](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/ide-signing-V5#section157591551175916).
