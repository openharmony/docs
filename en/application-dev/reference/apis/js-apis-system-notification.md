# @system.notification

> **NOTE**
> - The APIs of this module are no longer maintained since API version 7. You are advised to use [`@ohos.notification`](js-apis-notification.md).
> 
> - The initial APIs of this module are supported since API version 3. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```
import notification from '@system.notification';
```

## ActionResult

**System capability**: SystemCapability.Notification.Notification

| Name       | Type                                          | Readable                                        | Writable                                        | Mandatory| Description                     |
| ----------- | ---------------------------------------------- | ---- | ------------------------- | ------------------------- | ------------------------- |
| bundleName  | string                                          | Yes                                        | Yes                                        | Yes  | Name of the application bundle to which the notification will be redirected after being clicked.                 |
| abilityName | string                                          | Yes                                        | Yes                                        | Yes  | Name of the application ability to which the notification will be redirected after being clicked.|
| uri         | string                                          | Yes                                        | Yes                                        | No  | URI of the page to be redirected to.             |


## ShowNotificationOptions

**System capability**: SystemCapability.Notification.Notification

| Name         | Type                                          | Readable                                        | Writable                                        | Mandatory| Description                       |
| ------------- | ---------------------------------------------- | ---- | ------------------------- | ------------------------- | ------------------------- |
| contentTitle  | string                                          | Yes                                        | Yes                                        | No  | Notification title.                 |
| contentText   | string                                          | Yes                                        | Yes                                        | No  | Notification content.                 |
| clickAction   | ActionResult                                    | Yes                                  | Yes                                  | No  | Action triggered when the notification is clicked.    |


## notification.show

show(options?: ShowNotificationOptions): void

Displays a notification.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| options | ShowNotificationOptions | No| Notification title.|

**Example**
```javascript
export default {
    show() {
        notification.show({
            contentTitle: 'title info',
            contentText: 'text',
            clickAction: {
                bundleName: 'com.example.testapp',
                abilityName: 'notificationDemo',
                uri: '/path/to/notification',
            },
        });
    },
}
```
