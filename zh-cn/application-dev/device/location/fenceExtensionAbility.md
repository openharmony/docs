# FenceExtensionAbility

## 概述
[FenceExtensionAbility](../../reference/apis-location-kit/js-apis-app-ability-FenceExtensionAbility.md)是一个地理围栏类型的ExtensionAbility，开发者可以使用该Ability来快速便捷的实现地理围栏拓展能力，协助用户完成快捷交互，提升用户体验。

## 使用场景

1. 通过位置服务的[geoLocationManager.on('gnssFenceStatusChange')](../../reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanagerongnssfencestatuschange)接口进行地理围栏的注册和事件订阅，并在want参数中传入实现的FenceExtensionAbility相关参数信息；
2. 系统会在注册的地理围栏触发后，通过onFenceStatusChange接口上报围栏事件和数据，APP可以在接收到事件后进行相应的业务处理，例如发送一个通知。

## 接口介绍
接口详情参见[FenceExtensionAbility](../../reference/apis-location-kit/js-apis-app-ability-FenceExtensionAbility.md)。
| 接口 | 描述 |
| ---- | ---- |
| onFenceStatusChange(transition: geoLocationManager.GeofenceTransition, additions: Record&lt;string, string&gt;): void  | 接收系统通知的地理围栏事件，根据围栏事件类型和数据进行相应处理。 |
| onDestroy(): void | 接收FenceExtensionAbility的销毁事件并处理，会在FenceExtensionAbility销毁前回调。 |

## 开发步骤

### 实现一个地理围栏扩展服务

首先需要实现[FenceExtensionAbility](../../reference/apis-location-kit/js-apis-app-ability-FenceExtensionAbility.md)提供方的能力。

需要在DevEco Studio工程中手动新建一个FenceExtensionAbility，具体步骤如下。

1. 在工程Module对应的ets目录下，右键选择“New &gt; Directory”，新建一个目录并命名为fenceextensionability。
2. 在fenceextensionability目录，右键选择“New &gt; File”，新建一个.ets文件并命名为MyFenceExtensionAbility.ets。
3. 打开MyFenceExtensionAbility.ets，导入FenceExtensionAbility的依赖包，自定义类继承FenceExtensionAbility并实现onFenceStatusChange和onDestroy接口。

示例代码如下：

```ts
import { FenceExtensionAbility, geoLocationManager } from '@kit.LocationKit';
import { notificationManager } from '@kit.NotificationKit';
import { Want, wantAgent } from '@kit.AbilityKit';

export class MyFenceExtensionAbility extends FenceExtensionAbility {
  onFenceStatusChange(transition: geoLocationManager.GeofenceTransition, additions: Record<string, string>): void {
    // 接受围栏状态变化事件，处理业务逻辑
    console.info(`on geofence transition,id:${transition.geofenceId},event:${transition.transitionEvent},additions:${JSON.stringify(additions)}`);

    // 可以发送围栏业务通知
    let wantAgentInfo: wantAgent.WantAgentInfo = {
      wants: [
        {
          bundleName: 'com.example.myapplication',
          abilityName: 'EntryAbility',
          parameters:
          {
            "geofenceId": transition?.geofenceId,
            "transitionEvent": transition?.transitionEvent,
          }
        } as Want
      ],
      actionType: wantAgent.OperationType.START_ABILITY,
      requestCode: 100
    };
    wantAgent.getWantAgent(wantAgentInfo).then((wantAgentMy) => {
      let notificationRequest: notificationManager.NotificationRequest = {
        id: 1,
        content: {
          notificationContentType: notificationManager.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
          normal: {
            title: `围栏通知`,
            text: `on geofence transition,id:${transition.geofenceId},event:${transition.transitionEvent},additions:${JSON.stringify(additions)}`,
          }
        },
        notificationSlotType: notificationManager.SlotType.SOCIAL_COMMUNICATION,
        wantAgent: wantAgentMy
      };
      notificationManager.publish(notificationRequest);
    });
  }
}
```

4. 在工程Module对应的[module.json5配置文件](../../quick-start/module-configuration-file.md)中注册FenceExtensionAbility，type标签需要设置为fence，srcEntry标签表示当前FenceExtensionAbility组件所对应的代码路径。

```json
{
  "module": {
    "extensionAbilities": [
      {
        "name": "MyFenceExtensionAbility",
        "srcEntry": "./ets/fenceExtensionability/MyFenceExtensionAbility.ets",
        "description": "MyFenceExtensionAbility",
        "type": "fence",
        "exported": true
      },
    ]
  }
}
```