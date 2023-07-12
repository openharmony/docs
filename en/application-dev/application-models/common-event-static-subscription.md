# Subscribing to Common Events in Static Mode (for System Applications Only)

## When to Use

A static subscriber is started once it receives a target event published by the system or application. At the same time, the [onReceiveEvent()](../reference/apis/js-apis-application-staticSubscriberExtensionAbility.md#staticsubscriberextensionabilityonreceiveevent) callback is triggered, in which you can implement the service logic. For example, if an application needs to execute some initialization tasks during device power-on, the application can subscribe to the power-on event in static mode. After receiving the power-on event, the application is started to execute the initialization tasks.

Subscribing to a common event in static mode is achieved by configuring a declaration file and implementing a class that inherits from [StaticSubscriberExtensionAbility](../reference/apis/js-apis-application-staticSubscriberExtensionAbility.md).

> **NOTE**
>
> The static subscription mode has negative impact on system power consumption. Therefore, exercise caution when using this mode.

## How to Develop

1. Declaring a static subscriber.

   To declare a static subscriber, create an ExtensionAbility, which is derived from the **StaticSubscriberExtensionAbility** class, in the project.

   You can implement service logic in the [**onReceiveEvent()**](../reference/apis/js-apis-application-staticSubscriberExtensionAbility.md#staticsubscriberextensionabilityonreceiveevent) callback.

   ```ts
   import StaticSubscriberExtensionAbility from '@ohos.application.StaticSubscriberExtensionAbility'
   
   export default class StaticSubscriber extends StaticSubscriberExtensionAbility {
     onReceiveEvent(event) {
       console.info('onReceiveEvent, event: ' + event.event);
     }
   }
   ```

2. Configure static subscriber settings.

   After writing the static subscriber code, configure the subscriber in the [module.json5](../quick-start/module-configuration-file.md) file.

   ```ts
   {
     "module": {
       ...
       "extensionAbilities": [
         {
           "name": "StaticSubscriber",
           "srcEntry": "./ets/staticsubscriber/StaticSubscriber.ts",
           "description": "$string:StaticSubscriber_desc",
           "icon": "$media:icon",
           "label": "$string:StaticSubscriber_label",
           "type": "staticSubscriber",
           "exported": true,
           "metadata": [
             {
               "name": "ohos.extension.staticSubscriber",
               "resource": "$profile:subscribe"
             }
           ]
         }
       ]
       ...
     }
   }
   ```

   Some fields in the file are described as follows:

   - **srcEntry **: entry file path of the ExtensionAbility, that is, the file path of the static subscriber declared in Step 2.

   - **type**: ExtensionAbility type. For a static subscriber, set this field to **staticSubscriber**.

   - **metadata**: level-2 configuration file information of the ExtensionAbility. The configuration information varies according to the ExtensionAbility type. Therefore, you must use different config files to indicate the specific configuration.
        - **name**: name of the ExtensionAbility. For a static subscriber, declare the name as **ohos.extension.staticSubscriber** for successful identification.
        - **resource**: path that stores the ExtensionAbility configuration, which is customizable. In this example, the path is **resources/base/profile/subscribe.json**.


3. Configure the level-2 configuration file to which the metadata points.

   ```json
   {
     "commonEvents": [
       {
         "name": "xxx",
         "permission": "xxx",
         "events":[
           "xxx"
         ]
       }
     ]
   }
   ```

   If the level-2 configuration file is not declared in this format, the file cannot be identified. Some fields in the file are described as follows:

   - **name**: name of the ExtensionAbility, which must be the same as the name of **extensionAbility** declared in **module.json5**.
   - **permission**: permission required for the publisher. If a publisher without the required permission attempts to publish an event, the event is regarded as invalid and will not be published.
   - **events**: list of target events to subscribe to.

4. Modify the [preset configuration file](https://gitee.com/openharmony/vendor_hihope/blob/master/rk3568/preinstall-config/install_list_capability.json) of the device, that is, the **/system/etc/app/install_list_capability.json** file on the device. When the device is started, this file is read. During application installation, the common event type specified by **allowCommonEvent** in the file is authorized. The **install_list_capability.json** file contains the following fields:

   - **bundleName**: bundle name of the application.
   - **app_signature**: fingerprint information of the application. For details, see [Configuration in install_list_capability.json](../../device-dev/subsystems/subsys-app-privilege-config-guide.md#configuration-in-install_list_capabilityjson).
   - **allowCommonEvent**: type of common event that can be started by static broadcast.

   ```json
   [
     ...
     {
       "bundleName": "com.example.myapplication", // Bundle name.
       "app_signature": ["****"], // Fingerprint information.
       "allowCommonEvent": ["usual.event.A", "usual.event.B"] // Type of common event that can be started by static broadcast.
     }
   ]
   ```
   
   > **NOTE**
   >
   > The **install_list_capability.json** file is available only for preinstalled applications.

