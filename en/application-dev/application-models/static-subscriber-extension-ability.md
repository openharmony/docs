# StaticSubscriberExtensionAbility Development

## Scenario Description

​The common event service provides two subscription modes: dynamic and static. In dynamic subscription mode, a subscriber calls an API during the running period to subscribe to common events. For details, see [Subscribing to Common Events](common-event-subscription.md). In static subscription mode, no common event subscription API is called. A common event is subscribed by configuring a declaration file and implementing a class that inherits from **StaticSubscriberExtensionAbility**. A static subscriber is started once it receives a target event (for example, a power-on event) published by the system or application. At the same time, the **onReceiveEvent** callback is triggered, in which you can implement the service logic. **The static subscriber APIs are system APIs and can be used only by system applications that have passed the system-level power consumption review.**



## How to Develop

1. Prerequisites

   The application must meet the following requirements:

   The application is a system application.

   The application is developed using the full SDK.

   The application's power consumption has passed the system-level power consumption review. If you want to use static subscription in the debugging phase, add the bundle name of your application to the system configuration file **/etc/static_subscriber_config.json**.

   

2. Declaring a Static Subscriber

   To declare a static subscriber, create an ExtensionAbility, which is derived from the **StaticSubscriberExtensionAbility** class, in the project. The sample code is as follows:

   ```ts
   import StaticSubscriberExtensionAbility from '@ohos.application.StaticSubscriberExtensionAbility'
   
   export default class StaticSubscriber extends StaticSubscriberExtensionAbility {
       onReceiveEvent(event) {
           console.log('onReceiveEvent, event:' + event.event);
       }
   }
   ```

   You can implement service logic in the **onReceiveEvent** callback.

   

3. Project Configuration for a Static Subscriber

   After writing the static subscriber code, configure the subscriber in the **module.json5** file. The configuration format is as follows:

   ```ts
   {
     "module": {
       ......
       "extensionAbilities": [
         {
           "name": "StaticSubscriber",
           "srcEntrance": "./ets/StaticSubscriber/StaticSubscriber.ts",
           "description": "$string:StaticSubscriber_desc",
           "icon": "$media:icon",
           "label": "$string:StaticSubscriber_label",
           "type": "staticSubscriber",
           "visible": true,
           "metadata": [
             {
               "name": "ohos.extension.staticSubscriber",
               "resource": "$profile:subscribe"
             }
           ]
         }
       ]
       ......
     }
   }
   ```

   Pay attention to the following fields in the JSON file:

   **srcEntrance**: entry file path of the ExtensionAbility, that is, the file path of the static subscriber declared in Step 2.

   **type**: ExtensionAbility type. For a static subscriber, set this field to **staticSubscriber**.

   **metadata**: level-2 configuration file information of the ExtensionAbility. The configuration information varies according to the ExtensionAbility type. Therefore, you must use different config files to indicate the specific configuration. The **metadata** field contains two keywords: **name** and **resource**. The **name** field indicates the ExtensionAbility type name. For a static subscriber, declare the name as **ohos.extension.staticSubscriber** for successful identification. The **resource** field indicates the path that stores the ExtensionAbility configuration, which is customizable. In this example, the path is **resources/base/profile/subscribe.json**.

   A level-2 configuration file pointed to by **metadata** must be in the following format:

   ```ts
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

   If the level-2 configuration file is not declared in this format, the file cannot be identified. The fields are described as follows:

   **name**: name of the ExtensionAbility, which must be the same as the name of **extensionAbility** declared in **module.json5**.

   **permission**: permission required by the publisher. If a publisher without the required permission attempts to publish an event, the event is regarded as invalid and will not be published.

   **events**: list of subscribed target events



## Samples

For details about how to develop StaticSubscriberExtensionAbility, see [StaticSubscriber (ArkTS, API version 9, Full SDK)](https://gitee.com/openharmony/applications_app_samples/tree/master/ability/StaticSubscriber).
