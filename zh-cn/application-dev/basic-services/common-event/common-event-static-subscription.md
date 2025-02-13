# 静态订阅公共事件（仅对系统应用开放）

## 场景介绍

静态订阅者在未接收订阅的目标事件时，处于未拉起状态。当系统或应用发布了指定的公共事件后，静态订阅者将被拉起，并执行[`onReceiveEvent()`](../../reference/apis-basic-services-kit/js-apis-application-staticSubscriberExtensionAbility-sys.md#staticsubscriberextensionabilityonreceiveevent)回调。

开发者可以通过在[`onReceiveEvent()`](../../reference/apis-basic-services-kit/js-apis-application-staticSubscriberExtensionAbility-sys.md#staticsubscriberextensionabilityonreceiveevent)回调中执行业务逻辑，实现当应用接收到特定公共事件时执行业务逻辑的目的。例如，应用希望在设备开机时执行一些初始化任务，那么该应用可以静态订阅开机事件，在收到开机事件后会拉起该应用，然后执行初始化任务。

静态订阅是通过配置文件声明和实现继承自[`StaticSubscriberExtensionAbility`](../../reference/apis-basic-services-kit/js-apis-application-staticSubscriberExtensionAbility-sys.md)的类实现对公共事件的订阅。

> **说明：**
>
> 需要注意的是，静态订阅公共事件对系统功耗有一定影响，建议谨慎使用。

## 开发步骤

1. 静态订阅者声明。

   声明一个静态订阅者，首先需要在工程中新建一个ExtensionAbility，该ExtensionAbility从StaticSubscriberExtensionAbility派生。

   开发者可以在[`onReceiveEvent()`](../../reference/apis-basic-services-kit/js-apis-application-staticSubscriberExtensionAbility-sys.md#staticsubscriberextensionabilityonreceiveevent)回调中实现业务逻辑。

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

2. 静态订阅者工程配置。

   在完成静态订阅者的代码实现后，需要在[module.json5配置文件](../../quick-start/module-configuration-file.md)中进行配置订阅者信息。

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

   其中部分字段解释如下：

   - srcEntry：表示ExtensionAbility的入口文件路径，即步骤2中声明的静态订阅者所在的文件路径。

   - type：表示ExtensionAbility的类型，对于静态订阅者需要声明为`staticSubscriber`。

   - metadata：表示ExtensionAbility的二级配置文件信息。由于不同的ExtensionAbility类型其配置信息不尽相同，因此需要使用不同的config文件表示其具体配置信息。
        - name：表示ExtensionAbility的类型名称，对于静态订阅类型，name必须声明为`ohos.extension.staticSubscriber`，否则无法识别为静态订阅者。
        - resource：字段表示ExtensionAbility的配置信息路径，由开发者自行定义，在本例中表示路径为`resources/base/profile/subscribe.json`。


3. 配置metadata指向的二级配置文件subscribe.json。

   > **说明：**
   >
   > 二级配置文件必须按照此形式进行声明，否则会无法正确识别。

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

   commonEvents标签标识订阅者配置静态订阅事件，轻量级设备上不支持此标签和子标签。标签值为对象数组类型，包含name、permission、events、filter四个子标签。

   **表1** commonEvents标签说明

   | **属性名称** | **含义**                                                     | **数据类型** | **是否可缺省**             |
   | ------------ | ------------------------------------------------------------ | ------------ | -------------------------- |
   | name         | 标识静态订阅ExtensionAbility的名称，需要和module.json5中声明的ExtensionAbility的name一致。 | 字符串       | 该标签不可缺省。           |
   | permission   | 标识订阅者要求的发布者需要具备的权限。                       | 字符串       | 该标签可缺省，缺省值为空。 |
   | events       | 标识订阅的目标事件列表。                                     | 字符串数组   | 该标签不可缺省。           |
   | filter       | 标识静态事件过滤的条件。从API version 16开始，支持该属性。<br />取值说明详见下表。 | 对象数组     | 该标签可缺省，缺省值为空。 |

   filter标签标识订阅者可以根据需要配置过滤的静态订阅事件，标签值为对象数组类型，包含event、conditions两个子标签。

   **表2** filter标签说明

   | **属性名称** | **含义**                                                     | **数据类型** | **是否可缺省**   |
   | ------------ | ------------------------------------------------------------ | ------------ | ---------------- |
   | event        | 标识静态订阅事件需要过滤的事件名，与事件列表进行匹配，否则配置无效。 | 字符串       | 该标签不可缺省。 |
   | conditions   | 标识当前事件的过滤条件，从[发布者CommonEventPublishData](../../reference/apis-basic-services-kit/js-apis-inner-commonEvent-commonEventPublishData.md#commoneventpublishdata)中进行过滤。 | 对象         | 该标签不可缺省。 |

   conditions标签标识静态订阅过滤事件需要的条件配置，标签值为对象类型，包含code、data、parameters三个子标签。

   **表3** conditions标签说明

   | **属性名称** | **含义**                                   | **数据类型**       | **是否可缺省**             |
   | ------------ | ------------------------------------------ | ------------------ | -------------------------- |
   | code         | 标识静态订阅事件需要过滤的结果代码。       | 整型数值           | 该标签可缺省，缺省值为空。 |
   | data         | 标识静态订阅事件需要过滤的自定义结果数据。 | 字符串             | 该标签可缺省，缺省值为空。 |
   | parameters   | 标识静态订阅事件需要过滤的附加信息。       | 布尔值/数值/字符串 | 该标签可缺省，缺省值为空。 |


4. 修改设备的[预置配置文件](https://gitee.com/openharmony/vendor_hihope/blob/master/rk3568/preinstall-config/install_list_capability.json)。预置配置文件在设备上的路径为`/system/variant/phone/base/etc/app/install_list_capability.json`，设备开机启动时会读取该配置文件，在应用安装时会对在文件中配置的`allowCommonEvent`公共事件类型进行授权。预授权配置文件字段内容包括`bundleName`、`app_signature`和`allowCommonEvent`。

   - `bundleName`字段配置为应用的Bundle名称。
   - `app_signature`字段配置为应用的指纹信息。指纹信息的配置请参见[应用特权配置指南](../../../device-dev/subsystems/subsys-app-privilege-config-guide.md#install_list_capabilityjson中配置)，或者通过[bm工具](../../tools/bm-tool.md)获取并填写该应用的`appId`。
   - `allowCommonEvent`字段配置为允许静态广播拉起的公共事件项。

   ```json
   [
     // ...
     {
       "bundleName": "com.samples.stageprocessthread", // Bundle名称
       "app_signature": ["****"], // 指纹信息
       "allowCommonEvent": ["usual.event.AIRPLANE_MODE"] // 允许静态广播拉起的公共事件项
     }
   ]
   ```
   
   > **说明**：
   >
   > 当前仅支持预置应用配置该文件。

## 相关实例

针对StaticSubscriberExtensionAbility开发，可参考如下实例：

- [静态订阅（ArkTS）（Full SDK）（API10）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/ApplicationModels/StaticSubscriber)

