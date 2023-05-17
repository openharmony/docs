# Subscribing to Common Events in Static Mode (for System Applications Only)

## When to Use

A static subscriber is started once it receives a target event published by the system or application. At the same time, the **onReceiveEvent** callback is triggered, in which you can implement the service logic. For example, if an application needs to execute some initialization tasks during device power-on, the application can subscribe to the power-on event in static mode. After receiving the power-on event, the application is started to execute the initialization tasks. Subscribing to a common event in static mode is achieved by configuring a declaration file and implementing a class that inherits from **StaticSubscriberExtensionAbility**. Note that this subscribing mode has negative impact on system power consumption. Therefore, exercise caution when using this mode.

## How to Develop

1. Declaring a Static Subscriber

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

2. Project Configuration for a Static Subscriber

   After writing the static subscriber code, configure the subscriber in the **module.json5** file. The configuration format is as follows:

   ```ts
   {
     "module": {
       ......
       "extensionAbilities": [
         {
           "name": "StaticSubscriber",
           "srcEntry": "./ets/StaticSubscriber/StaticSubscriber.ts",
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
       ......
     }
   }
   ```

   Pay attention to the following fields in the JSON file:

   - **srcEntry**: entry file path of the ExtensionAbility, that is, the file path of the static subscriber declared in Step 2.

   - **type**: ExtensionAbility type. For a static subscriber, set this field to **staticSubscriber**.

   - **metadata**: level-2 configuration file information of the ExtensionAbility. The configuration information varies according to the ExtensionAbility type. Therefore, you must use different config files to indicate the specific configuration.
        - **name**: name of the ExtensionAbility. For a static subscriber, declare the name as **ohos.extension.staticSubscriber** for successful identification.
        - **resource**: path that stores the ExtensionAbility configuration, which is customizable. In this example, the path is **resources/base/profile/subscribe.json**.

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

     - **name**: name of the ExtensionAbility, which must be the same as the name of **extensionAbility** declared in **module.json5**.

     - **permission**: permission required for the publisher. If a publisher without the required permission attempts to publish an event, the event is regarded as invalid and will not be published.

     - **events**: list of target events to subscribe to.

3. Device System Configuration

    In the device system configuration file **/etc/static_subscriber_config.json**, add the bundle name of the static subscriber.

    ```json
    {
        "xxx",
        "ohos.extension.staticSubscriber",
        "xxx"
    }
   ```

