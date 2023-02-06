# StaticSubscriberExtensionAbility开发指导

## 场景介绍

​公共事件服务提供了动态订阅和静态订阅两种订阅方式。动态订阅即订阅方在运行期调用公共事件订阅的API实现对公共事件的订阅，详见[公共事件订阅](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/application-models/common-event-subscription.md)。与动态订阅相对应的是静态订阅方式，这种方式不需要主动调用公共事件的API，而是通过配置文件声明和实现继承自StaticSubscriberExtensionAbility的类实现对公共事件的订阅。静态订阅者在未接收订阅的目标事件时，处于未拉起状态，当系统或应用发布了指定的公共事件后，静态订阅者将被拉起，并执行onReceiveEvent回调，开发者可通过在onReceiveEvent回调中执行业务逻辑，实现当应用接收到特定公共事件（例如开机事件）时执行业务逻辑的目的。**需要注意的是，静态订阅能力严格受限，相关接口为系统API，仅限于经过系统层面功耗评审的特定系统应用使用**。



## 开发步骤

1. 前置条件

   请确保您的应用具备以下特征：

   1）系统应用

   2）使用full-sdk开发

   3）经过性能功耗团队评审符合功耗要求，如果您希望在调试阶段尝试使用该功能，可修改系统配置文件/etc/static_subscriber_config.json,将待调试应用的包名添加至json文件中即可。

   

2. 静态订阅者声明

   声明一个静态订阅者，首先需要在工程中新建一个ExtensionAbility, 该ExtensionAbility从StaticSubscriberExtensionAbility派生，其代码实现如下：

   ```ts
   import StaticSubscriberExtensionAbility from '@ohos.application.StaticSubscriberExtensionAbility'
   
   export default class StaticSubscriber extends StaticSubscriberExtensionAbility {
       onReceiveEvent(event) {
           console.log('onReceiveEvent, event:' + event.event);
       }
   }
   ```

   开发者可以在onReceiveEvent中实现业务逻辑。

   

3. 静态订阅者工程配置

   在完成静态订阅者的代码实现后，需要将该订阅者配置到系统的module.json5中，配置形式如下：

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

   上述json文件主要关注以下字段：

   **srcEntrance**: 表示extension的入口文件路径，即步骤2中声明的静态订阅者所在的文件路径

   **type**: 表示extension的类型，对于静态订阅者需要声明为“staticSubscriber”

   **metadata**: 表示extension的二级配置文件信息。由于不同的extension类型其配置信息不尽相同，因此需要使用不同的config文件表示其具体配置信息。metadata字段共包含两个关键字name和resource。其中name字段表示extension的类型名称，对于静态订阅类型，name必须声明为“ohos.extension.staticSubscriber”，否则无法识别为静态订阅者；resource字段表示extension的配置信息路径，由开发者自行定义，在本例中表示路径为“resources/base/profile/subscribe.json"。

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

   **name**: 静态订阅extension的名称，需要和module.json5中声明的extensionAbility的name一致

   **permission**：订阅者要求的发布者需要具备的权限，对于发布了目标事件但不具备permission中声明的权限的发布者将被视为非法事件不予发布

   **events**: 订阅的目标事件列表



## 相关示例

针对StaticSubscriberExtensionAbility开发，可参考如下实例：[StaticSubscriber：静态订阅（ArkTS）（API9）（Full SDK）](https://gitee.com/openharmony/applications_app_samples/tree/master/ability/StaticSubscriber)

