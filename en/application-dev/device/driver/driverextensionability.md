# UI-free Driver Development

<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @zgene94-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @hu-zhiqiong-->
<!-- md-trans-meta sourceCommit=d8985113333b8c3c0dd4e2a9924806e724527539 translatedAt=2026-08-01T02:49:30.051Z pushedAt=2026-08-01T06:22:14.096Z -->

## When to Use

Basic drivers without a UI are suitable for simple devices that do not require UI-based driver configuration, such as mice and keyboards, where only plug-and-play functionality is needed. You can use **DriverExtensionAbility** to develop such apps.

## Basic Concepts

 - DriverExtensionAbility

    [DriverExtensionAbility](../../reference/apis-driverdevelopment-kit/js-apis-app-ability-driverExtensionAbility.md) is a Driver-type **ExtensionAbility** component that provides driver-related extension framework capabilities. For certain devices, external hardware modules can be plugged in to extend device capabilities, and the driver for the hardware module can be installed as an app. [DriverExtensionAbility](../../reference/apis-driverdevelopment-kit/js-apis-app-ability-driverExtensionAbility.md) can be bound by an app through the APIs provided by [@ohos.driver.deviceManager (Peripheral Management)](../../reference/apis-driverdevelopment-kit/js-apis-driver-deviceManager.md), and it processes related transactions in the background based on the app's requests.

    Each type of **ExtensionAbility** has its own context. The **DriverExtensionAbility** provides related capabilities through the [DriverExtensionContext](../../reference/apis-driverdevelopment-kit/js-apis-inner-application-driverExtensionContext.md).

## Environment Setup

Before you get started, make necessary preparations by following instructions in [Environment Preparation](environmental-preparation.md).

## How to Develop

To implement a driver, create a DriverExtensionAbility in the DevEco Studio project. The procedure is as follows:

1. Create an OpenHarmony project. For details, see [Creating a Project](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-create-new-project). (If a project has been created in [UI-based Driver Development](externaldevice-guidelines.md), skip this step.)

2. In the **ets** directory of the project, right-click **New** > **Directory** to create a directory named **driverextability**.

3. In the **driverextability** directory, right-click and choose **New** > **ArkTS File** to create a file named **DriverExtAbility.ets**.

4. Import the related kit, and define the request code.

   <!-- @[driver_service_step4](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/DriverDevelopmentKit/DriverDemo/entry/src/main/ets/driverextability/DriverExtAbility.ets) --> 

   ``` TypeScript
   import { DriverExtensionAbility } from '@kit.DriverDevelopmentKit';
   import { Want } from '@kit.AbilityKit';
   import { rpc } from '@kit.IPCKit';
   
   const REQUEST_CODE = 99; // Negotiate the request code with the peripheral client.
   ```

5. Open the **DriverExtAbility.ets** file, import [@ohos.rpc (RPC)](../../reference/apis-ipc-kit/js-apis-rpc.md), override the **onRemoteMessageRequest()** method, receive the message sent by the application, and return the processing result to the application. **REQUEST_CODE** is used to verify the service request code sent by the application.

   <!-- @[driver_service_step5](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/DriverDevelopmentKit/DriverDemo/entry/src/main/ets/driverextability/DriverExtAbility.ets) --> 

   ``` TypeScript
   class StubTest extends rpc.RemoteObject {
     // Receive a message from the application and return the processing result to the client.
     onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence,
       option: rpc.MessageOption) {
       if (code === REQUEST_CODE) {
         // Receive the data sent from the application.
         // When the application calls data.writeString() multiple times to write data, the driver can receive the corresponding data by calling data.readString() for multiple times.
         let optFir: string = data.readString();
         // The driver returns the data processing result to the application.
         // In the example, "Hello" is received and "Hello World" is returned to the application.
         reply.writeString(optFir + ` World`);
       }
       return true;
     }
   }
   ```

6. In the **DriverExtAbility.ets** file, add the import dependency for [DriverExtensionAbility](../../reference/apis-driverdevelopment-kit/js-apis-app-ability-driverExtensionAbility.md). This package provides the **onInit()**, **onRelease()**, **onConnect()**, and **onDisconnect()** lifecycle callbacks. Define a custom class that inherits from [DriverExtensionAbility](../../reference/apis-driverdevelopment-kit/js-apis-app-ability-driverExtensionAbility.md) and override the lifecycle callbacks as needed.

   <!-- @[driver_service_step6](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/DriverDevelopmentKit/DriverDemo/entry/src/main/ets/driverextability/DriverExtAbility.ets) --> 

   ``` TypeScript
   export default class DriverExtAbility extends DriverExtensionAbility {
     onInit(want: Want) {
       console.info('testTag', `onInit, want: ${want.abilityName}`);
     }
   
     onRelease() {
       console.info('testTag', `onRelease`);
     }
   
     onConnect(want: Want) {
       console.info('testTag', `onConnect, want: ${want.abilityName}`);
       return new StubTest('test');
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

7. Register **DriverExtensionAbility** in the [**module.json5** file](../../quick-start/module-configuration-file.md) of the module in the project. Set **type** to **driver** and **srcEntry** to the code path of **DriverExtensionAbility**.

   <!-- @[driver_service_step7](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/DriverDevelopmentKit/DriverDemo/entry/src/main/module.json5) --> 

   ``` JSON5
   {
     "module": {
       "name": "entry",
       "type": "entry",
       "description": "$string:module_desc",
       "mainElement": "EntryAbility",
       "deviceTypes": [
         "default"
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
           "icon": "$media:layered_image",
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
                 "ohos.want.action.home"
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
               "name": "bus", // Bus, which is mandatory.
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
             },
             {
               "name": "launchOnBind," // Whether to enable delayed driver startup. This parameter is optional. The value **true** indicates delayed startup, and the value **false** indicates immediate startup. The value is **false** by default if the specified value is incorrect or the value is left unspecified.
               "value": "true"
             },
             {
               "name": "ohos.permission.ACCESS_DDK_ALLOWED," // Whether to allow DDK access. This parameter is optional. The value **true** indicates that DDK access is allowed, and the value **false** indicates the opposite. The default value is **false** if the specified value is incorrect or the value is left unspecified.
               "value": "true"
             }
           ]
         }
       ]
     }
   }
   ```

8. After completing development of the client and driver sample code, import the HAP to the device by following instructions in [Running Your App/Atomic Service on a Local Real Device](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-run-device), and run **Hello** in the HAP to check whether **Hello world** is displayed. If yes, the IPC communication is ready for use.

## Driver Development

Currently, **DriverExtensionAbility** provides four capabilities: HidDdk, UsbDdk, USBSerialDDK, and ScsiPeripheralDDK, which are used to develop dedicated drivers for extended peripherals. For details, see:

* [HID DDK Development](hid-ddk-guidelines.md)

* [USB DDK Development](usb-ddk-guidelines.md)

* [USB Serial DDK Development](usb-serial-ddk-guidelines.md)

* [SCSI Peripheral DDK Development](scsi-peripheral-ddk-guidelines.md)

<!--RP1-->

## Application Signing

> **NOTE**
>
> Configure the permission before enabling automatic signing.

You need to configure a signature file for your application to run on a device. Besides, to develop a peripheral driver client, you need to declare the **ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER** and **ohos.permission.ACCESS_DDK_DRIVERS** permissions for the peripheral.

- ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER (This permission is required for API version 10 or later.)

  To obtain authorization on this access permission, [declare it](../../security/AccessToken/declare-permissions.md) in the **requestPermissions** field in the **module.json5** file.

- ohos.permission.ACCESS_DDK_DRIVERS (This permission is required for API version 18 or later.)

  1. [Declare the required permissions](../../security/AccessToken/declare-permissions.md) in the **requestPermissions** field in the **module.json5** file.

  2. Modify the **acls** field in the **HarmonyAppProvision** configuration file to request permissions via ACL. For details, see [Requesting Restricted Permissions](../../security/AccessToken/declare-permissions-in-acl.md).

  3. In the **HarmonyAppProvision** configuration file (that is, **Sdk/openharmony/_{Version} _/toolchains /lib/UnsgnedReleasedProfileTemplate.json** file), configure the bundle name of the driver server to connect. If there are multiple servers, separate their bundle names with a comma.

      The configuration procedure is as follows:

      Add the **app-services-capabilities** node to the root node of the file and configure the node as follows:

      ```json
      "app-services-capabilities": {
        "ohos.permission.ACCESS_DDK_DRIVERS": {"bundleNames": "bundleName0,bundleName1,bundleName2"}
      }
      ```

Automatic signing: For details, see [Signing Your App/Service Automatically](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-signing#section18815157237).

<!--RP1End-->