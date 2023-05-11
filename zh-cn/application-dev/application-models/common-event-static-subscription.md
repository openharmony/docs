# 静态订阅公共事件（仅对系统应用开放）

## 场景介绍

静态订阅者在未接收订阅的目标事件时，处于未拉起状态，当系统或应用发布了指定的公共事件后，静态订阅者将被拉起，并执行onReceiveEvent回调，开发者可通过在onReceiveEvent回调中执行业务逻辑，实现当应用接收到特定公共事件时执行业务逻辑的目的。例如，某应用希望在设备开机的时候执行一些初始化任务，那么该应用可以静态订阅开机事件，在收到开机事件后会拉起该应用，然后执行初始化任务。静态订阅是通过配置文件声明和实现继承自StaticSubscriberExtensionAbility的类实现对公共事件的订阅。**需要注意的是，静态订阅公共事件对系统功耗有一定影响，建议谨慎使用**。

## 开发步骤

1. 静态订阅者声明

   声明一个静态订阅者，首先需要在工程中新建一个ExtensionAbility，该ExtensionAbility从StaticSubscriberExtensionAbility派生，其代码实现如下：

   ```ts
   import StaticSubscriberExtensionAbility from '@ohos.application.StaticSubscriberExtensionAbility'
   
   export default class StaticSubscriber extends StaticSubscriberExtensionAbility {
     onReceiveEvent(event) {
       console.info('onReceiveEvent, event:' + event.event);
     }
   }
   ```

   开发者可以在onReceiveEvent中实现业务逻辑。

2. 静态订阅者工程配置

   在完成静态订阅者的代码实现后，需要将该订阅者配置到系统的module.json5中，配置形式如下：

   ```ts
   {
     "module": {
       ...
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
       ...
     }
   }
   ```

   上述json文件主要关注以下字段：

   - srcEntry : 表示ExtensionAbility的入口文件路径，即步骤2中声明的静态订阅者所在的文件路径

   - type: 表示ExtensionAbility的类型，对于静态订阅者需要声明为“staticSubscriber”

   - metadata: 表示ExtensionAbility的二级配置文件信息。由于不同的ExtensionAbility类型其配置信息不尽相同，因此需要使用不同的config文件表示其具体配置信息。
        - name：表示ExtensionAbility的类型名称，对于静态订阅类型，name必须声明为“ohos.extension.staticSubscriber”，否则无法识别为静态订阅者；
        - resource: 字段表示ExtensionAbility的配置信息路径，由开发者自行定义，在本例中表示路径为“resources/base/profile/subscribe.json"。

   metadata指向的二级配置文件的通常形式如下：

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

   需要注意二级配置文件必须按照此形式进行声明，否则会无法正确识别。下面对字段进行介绍：

   - name: 静态订阅ExtensionAbility的名称，需要和module.json5中声明的ExtensionAbility的name一致

   - permission：订阅者要求的发布者需要具备的权限，对于发布了目标事件但不具备permission中声明的权限的发布者将被视为非法事件不予发布

   - events: 订阅的目标事件列表

3. 修改设备系统配置文件

    修改设备系统配置文件 **/system/etc/app/install_list_capability.json**，将静态订阅应用者的包名添加至该json文件中即可。

    ```json
   {
    "install_list": [
            {
                "bundleName": "ohos.extension.staticSubscriber",
                "allowCommonEvent": ["usual.event.A", "usual.event.B"],
            }
        ]
    }
   ```
## 相关示例

针对StaticSubscriberExtensionAbility开发，可参考如下实例：

- [StaticSubscriber：静态订阅（ArkTS）（API9）（Full SDK）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/ApplicationModels/StaticSubscriber)

