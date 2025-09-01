# 浏览器插件与本地应用通信
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @bingli-->
<!--Designer: @bingli-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

浏览器插件与本地应用通信需要通过WebNativeMessagingExtensionAbility实现。

WebNativeMessagingExtensionAbility,是[Stage模型](../application-models/stage-model-development-overview.md)中扩展组件[ExtensionAbility](../application-models/extensionability-overview.md)的派生类。开发者可以通过WebNativeMessagingExtensionAbility实现浏览器插件与本地应用的数据传递，功能对接。

## 接口说明

浏览器插件与本地应用通信能力关键接口如下表所示。API的接口使用指导请参见[webNativeMessagingExtensionAbility API参考](../reference/apis-arkweb/arkts-apis-web-webNativeMessagingExtensionAbility.md),[webNativeMessagingExtensionContext API参考](../reference/apis-arkweb/arkts-apis-web-webNativeMessagingExtensionContext.md)和[webNativeMessagingExtensionManager API参考](../reference/apis-arkweb/arkts-apis-web-webNativeMessagingExtensionManager.md)。

| 接口名                                  | 描述        |
| ----------------------------------------- | ---------- |
| onConnectNative(info: ConnectionInfo): void | 当Web原生消息连接建立时回调此方法。 |
| onDisconnectNative(info: ConnectionInfo): void | 当Web原生消息连接断开时回调此方法。 |
| onDestroy(): void | 在WebNativeMessagingExtensionAbility销毁之前回调。 |

## 约束与限制

## 开发步骤

1. 在应用配置文件`module.json5`中注册`extensionAbilities`相关配置

新增`"extensionAbilities"`字段, 其中注册类型`"type"`设置为`"webNativeMessaging"`, 设置应用间配置共享[crossAppSharedConfig](../database/share-config.md)信息。

在WebNativeMessagingExtensionAbility配置文件示例:

```json
{
    "extensionAbilities": [
        {
            "description": "$string:ServiceExtAbility",
            "icon": "$media:icon",
            "name": "WebNativeMessagingExtensionAbility",
            "type": "webNativeMessaging",
            "exported": false,
            "crossAppSharedConfig": [
                {
                    "uri": "datashareproxy://$bundlename/browserNativeMessagingHosts",
                    "value": "{\"extensionAbility\": \" aiassistant.messagingAbility\", \"allowed_origins\": [\" arkweb-extension://knldjmfmopnpolahpmmgbagdohdnhkik/\"]}",
                    "allowList": [
                        "4565798431254567621", // browser appIdentifier
                    ]
                    // 数据使用[crossAppSharedConfig](../database/share-config.md)
                }
            ]
            // 在WebNativeMessagingExtension.ets文件里自定义继承WebNativeMessagingExtensionAbility,重写其中的onConnectNative/onDisconnectNative和onDestroy。
            "srcEntry": "./ets/WebNativeMessagingExtension/WebNativeMessagingExtension.ets"
        }
    ]
}
```

## "uri": "datashareproxy://$bundlename/browserNativeMessagingHosts"
其中uri为固定key值, "datashareproxy://"为固定值，"$bundlename"为当前应用包名,"browserNativeMessagingHosts"为固定值。

## "value": "{\"extensionAbility\": \" aiassistant.messagingAbility\", \"allowed_origins\": [\" arkweb-extension://knldjmfmopnpolahpmmgbagdohdnhkik/\"]}"
其中aiassistant.messagingAbility 为当前extension名， "arkweb-extension://knldjmfmopnpolahpmmgbagdohdnhkik/"为插件身份标识，其余为固定值。

## allowList
包含的是授权访问该应用间配置共享[crossAppSharedConfig](../database/share-config.md)的应用appid,比如安装插件的浏览器appid。

2.开发者可以在`WebNativeMessagingExtension.ets`文件中自定义类继承的`WebNativeMessagingExtensionAbility`,通过重写其`onConnectNative`,`onDisconnectNative`,`onDestroy`方法,使其能够相应连接请求，断开请求，以及销毁状态。

下面的示例展示了一个空实现的`WebNativeMessagingExtension.ets`文件;

```ts
// xxx.ets
import { AbilityConstant, UIAbility, Want } from '@kit.Ability';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';
import WebNativeMessagingExtensionContext from '@ohos.web.webNativeMessagingExtensionContext';
import WebNativeMessagingExtensionAbility from '@ohos.web.webNativeMessagingExtensionAbility';
import { ConnectionInfo } from '@ohos.web.webNativeMessagingExtensionAbility';
import StartOptions from '@ohos.app.ability.StartOptions';

let TAG: string = "test";
export default class MyExtensionAbility extends WebNativeMessagingExtensionAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
        hilog.info(0x0000, 'testTag', "MyExtensionAbility Created!");
    }

    onConnectNative(connnect: ConnectionInfo): void {
        hilog.info(0x0000, 'testTag', 'onConnectNative connectionId %{public}d bundleName %{public}s ' + 
            'extensionOrigin %{public}s fdRead %{public}d fdWrite %{public}d', connect.connectionId,
            JSON.stringify(connect.bundleName), connect.extensionOrigin, connect.fdRead, connect.fdWrite);
    }

    onDisconnectNative(connnect: ConnectionInfo): void {
        hilog.info(0x0000, 'testTag', 'onDisconnectNative connectionId %{public}d bundleName %{public}s ' + 
            'extensionOrigin %{public}s fdRead %{public}d fdWrite %{public}d', connect.connectionId,
            JSON.stringify(connect.bundleName), connect.extensionOrigin, connect.fdRead, connect.fdWrite);
        
        let wantInfo: Want = {
            deviceId: '', // deviceId为空表示本设备
            bundleName: 'com.example.helloworld',
            moduleName: 'entry', // moduleName非必选
            abilityName: 'SecondAbility',
            parameters: {},
        };
        this.context.startAbility(wantInfo).then(() => {
            console.info('startAbility success.');
            let id:number = 789;
            this.context.stopNativeConnection(id);
            console.info('stopNativeConnection success.');
            this.context.terminateSelf();
        }).catch((error: BusinessError) => {
            console.error('startAbility failed.', JSON.stringify(error));
        })
    }

    onDestroy(): void {
        hilog.info(0x0000, 'testTag ', 'Extension onDestroy');
    }
}
```

## 相关实例