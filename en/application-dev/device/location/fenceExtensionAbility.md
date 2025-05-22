# FenceExtensionAbility

## Overview
[FenceExtensionAbility](../../reference/apis-location-kit/js-apis-app-ability-FenceExtensionAbility.md) is an ExtensionAbility of the geofence type. It enables you to efficiently implement geofencing functionalities.

## When to Use

1. Subscribe to geofence status change events through the [geoLocationManager.on('gnssFenceStatusChange')](../../reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanagerongnssfencestatuschange) API of the location service, and pass the FenceExtensionAbility parameters in the **want** parameter.
2. After the event is triggered, the system reports the geofence event and data through the **onFenceStatusChange** API. Based on the event received, the application can perform corresponding service processing, for example, sending notifications.

## Available APIs
For details about the APIs, see [FenceExtensionAbility](../../reference/apis-location-kit/js-apis-app-ability-FenceExtensionAbility.md).
| Available APIs| Description|
| ---- | ---- |
| onFenceStatusChange(transition: geoLocationManager.GeofenceTransition, additions: Record&lt;string, string&gt;): void  | Callback invoked when a geofence status change event is received. Service processing is then performed based on the event type and data.|
| onDestroy(): void | Callback invoked when a FenceExtensionAbility destruction event is received.|

## How to Develop

### Implementing a FenceExtensionAbility

Implement the capability of the [FenceExtensionAbility](../../reference/apis-location-kit/js-apis-app-ability-FenceExtensionAbility.md) provider.

To manually create a FenceExtensionAbility in a project in DevEco Studio, perform the following steps:

1. In the **ets** directory of a module in the project, right-click and choose **New > Directory** to create a directory named **fenceextensionability**.
2. Right-click the **fenceextensionability** directory, and choose **New** > **File** to create a file named **MyFenceExtensionAbility.ets**.
3. Open the **MyFenceExtensionAbility.ets** file and import its dependencies. Customize a class that inherits from **FenceExtensionAbility** and implement the **onFenceStatusChange** and **onDestroy** APIs.

The sample code is as follows:

```ts
import { FenceExtensionAbility, geoLocationManager } from '@kit.LocationKit';
import { notificationManager } from '@kit.NotificationKit';
import { Want, wantAgent } from '@kit.AbilityKit';

export class MyFenceExtensionAbility extends FenceExtensionAbility {
  onFenceStatusChange(transition: geoLocationManager.GeofenceTransition, additions: Record<string, string>): void {
    // Receive the geofence status change event and process the service logic.
    console.info(`on geofence transition,id:${transition.geofenceId},event:${transition.transitionEvent},additions:${JSON.stringify(additions)}`);

    // Send a geofence notification.
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
            title: `Geofence Notification`,
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

4. Register the FenceExtensionAbility in the [module.json5 file](../../quick-start/module-configuration-file.md) of the module in the project. Set **type** to **"fence"** and **srcEntry** to the code path of the FenceExtensionAbility component.

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
