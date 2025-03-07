# Subscribing to Common Events in Static Mode (for System Applications Only)

## When to Use

A static subscriber is started once it receives a target event published by the system or application. At the same time, [onReceiveEvent()](../../reference/apis-basic-services-kit/js-apis-application-staticSubscriberExtensionAbility-sys.md#staticsubscriberextensionabilityonreceiveevent) is triggered, in which you can implement the service logic.<br>

For example, if an application needs to execute some initialization tasks during device power-on, the application can subscribe to the power-on event in static mode. After receiving the power-on event, the application is started to execute the initialization tasks.

Subscribing to a common event in static mode is achieved by configuring a declaration file and implementing a class that inherits from [StaticSubscriberExtensionAbility](../../reference/apis-basic-services-kit/js-apis-application-staticSubscriberExtensionAbility-sys.md).

> **NOTE**
>
> Static subscription to common events affects system power consumption. Therefore, exercise caution when using this function.

## Lifecycle

The [StaticSubscriberExtensionAbility](../../reference/apis-basic-services-kit/js-apis-application-staticSubscriberExtensionAbility-sys.md) module is destroyed 15 seconds after [`onReceiveEvent()`](../../reference/apis-basic-services-kit/js-apis-application-staticSubscriberExtensionAbility-sys.md#staticsubscriberextensionabilityonreceiveevent) is executed.

## How to Develop

1. Declare a static subscriber.

   Create an ExtensionAbility inherited from [StaticSubscriberExtensionAbility](../../reference/apis-basic-services-kit/js-apis-application-staticSubscriberExtensionAbility-sys.md) in the project.

   You can implement service logic using [onReceiveEvent()](../../reference/apis-basic-services-kit/js-apis-application-staticSubscriberExtensionAbility-sys.md#staticsubscriberextensionabilityonreceiveevent).

   ```ts
   import { commonEventManager, StaticSubscriberExtensionAbility } from '@kit.BasicServicesKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';

   const TAG: string = 'StaticSubscriber';
   const DOMAIN_NUMBER: number = 0xFF00;
   
   export default class StaticSubscriber extends StaticSubscriberExtensionAbility {
     onReceiveEvent(event: commonEventManager.CommonEventData): void {
       hilog.info(DOMAIN_NUMBER, TAG, 'onReceiveEvent, event: ' + event.event);
       //...
     }
   }
   ```

2. Configure static subscriber settings.

   After writing the static subscriber code, configure the subscriber in the [module.json5](../../quick-start/module-configuration-file.md) file.

   ```json
   {
     "module": {
   	// ...
       "extensionAbilities": [
         {
           "name": "StaticSubscriber",
           "srcEntry": "./ets/staticsubscriber/StaticSubscriber.ets",
           "description": "$string:StaticSubscriber_desc",
           "icon": "$media:app_icon",
           "label": "$string:StaticSubscriber_label",
           "type": "staticSubscriber",
           "exported": false,
           "metadata": [
             {
               "name": "ohos.extension.staticSubscriber",
               "resource": "$profile:subscribe"
             }
           ]
         }
       ],
   	// ...
     }
   }
   ```

   Some fields in the file are described as follows:

   - **srcEntry**: entry file path of the ExtensionAbility, that is, the file path of the static subscriber declared in Step 2.

   - **type**: ExtensionAbility type. For a static subscriber, set this field to **staticSubscriber**.

   - **metadata**: level-2 configuration file information of the ExtensionAbility. The configuration information varies according to the ExtensionAbility type. Therefore, you must use different config files to indicate the specific configuration.
        - **name**: name of the ExtensionAbility. For a static subscriber, declare the name as **ohos.extension.staticSubscriber** for successful identification.
        - **resource**: path that stores the ExtensionAbility configuration, which is customizable. In this example, the path is **resources/base/profile/subscribe.json**.


3. Configure the level-2 configuration file **subscribe.json** to which the metadata points.

   > **NOTE**
   >
   > If the level-2 configuration file is not declared in this format, the file cannot be identified.

   ```json
   {
     "commonEvents": [
       {
         "name": "StaticSubscriber",
         "permission": "",
         "events": [
           "usual.event.AIRPLANE_MODE"
         ],
         "filter": [
           {
             "event": "usual.event.AIRPLANE_MODE",
             "conditions": {
               "code": 0,
               "data": "send common event data",
               "parameters": {
                 "bundleType": 1,
                 "userId": 100
               }
             }
           }
         ]
       }
     ]
   }
   ```

   The **commonEvents** tag identifies a static subscription event configured by a subscriber. Lightweight devices do not support this tag and its subtags. The tag value is of an object array and contains four subtags: **name**, **permission**, **events**, and **filter**.

   **Table 1** commonEvents

   | **Name**| **Description**                                                    | **Data Type**| **Initial Value Allowed**            |
   | ------------ | ------------------------------------------------------------ | ------------ | -------------------------- |
   | name         | Name of the ExtensionAbility, which must be the same as the name of **extensionAbility** declared in **module.json5**.| String      | No          |
   | permission   | Permissions required by the publisher.                      | String      | Yes (initial value: left empty)|
   | events       | List of subscribed target events.                                    | String array  | No          |
   | filter       | Filter criteria for static events. This attribute is supported since API version 16.<br>For details about the values, see the following table.| Object array    | Yes (initial value: left empty)|

   The **filter** tag identifies the static subscription events that can be filtered by the subscriber as required. The tag value is of the object array type and contains two subtags: **event** and **conditions**.

   **Table 2** filter

   | **Name**| **Description**                                                    | **Data Type**| **Initial Value Allowed**  |
   | ------------ | ------------------------------------------------------------ | ------------ | ---------------- |
   | event        | Name of the event to be filtered out for static subscription events. The event name should match with the event list; otherwise, the configuration is invalid.| String      | No|
   | conditions   | Filter criteria of an event, which is obtained from [CommonEventPublishData](../../reference/apis-basic-services-kit/js-apis-inner-commonEvent-commonEventPublishData.md#commoneventpublishdata).| Object        | No|

   The **conditions** tag identifies the condition configuration for filtering static subscription events. The tag value is of the object type and contains three subtags: **code**, **data**, and **parameters**.

   **Table 3** conditions

   | **Name**| **Description**                                  | **Data Type**      | **Initial Value Allowed**            |
   | ------------ | ------------------------------------------ | ------------------ | -------------------------- |
   | code         | Result code to filter.      | Integer          | Yes (initial value: left empty)|
   | data         | Custom result data to filter.| String            | Yes (initial value: left empty)|
   | parameters   | Additional information to filter.      | Boolean/Number/String| Yes (initial value: left empty)|


4. Modify the [preset configuration file](https://gitee.com/openharmony/vendor_hihope/blob/master/rk3568/preinstall-config/install_list_capability.json) of the device, that is, the **/system/variant/phone/base/etc/app/install_list_capability.json** file. When the device is started, this file is read. During application installation, the common event type specified by **allowCommonEvent** in the file is authorized. The **install_list_capability.json** file contains the following fields:

   - **bundleName**: bundle name of the application.
   - **app_signature**: fingerprint information of the application. For details about how to configure fingerprint information, see [Application Privilege Configuration](https://gitee.com/openharmony/docs/blob/master/en/device-dev/subsystems/subsys-app-privilege-config-guide.md#configuration-in-install_list_capabilityjson), or obtain and enter the application ID using [Bundle Manager](https://gitee.com/openharmony/docs/blob/master/en/application-dev/tools/bm-tool.md).
   - **allowCommonEvent**: type of common event that can be started by static broadcast.

   ```json
   [
     // ...
     {
       "bundleName": "com.samples.stageprocessthread", // Bundle name.
       "app_signature": ["****"], // Fingerprint information.
       "allowCommonEvent": ["usual.event.AIRPLANE_MODE"] // Type of common event that can be started by static broadcast.
     }
   ]
   ```
   
   > **NOTE**
   >
   > The **install_list_capability.json** file is available only for preinstalled applications.
