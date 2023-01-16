# Common Event and Notification Development

## What is the emitter data size limit?

Applicable to: OpenHarmony SDK 3.2.5.3, stage model of API version 9

The emitter data size cannot exceed 10240.

## How do I implement the click-a-notification-to-open-an-application function?

Applicable to: OpenHarmony SDK 3.2.5.5, stage model of API version 9

You can implement this function by setting the **wantAgent** attribute in the **NotificationRequest** parameter of the **Notification.publish** API.

Reference: [Notification](../reference/apis/js-apis-notification.md#notificationpublish) and [WantAgent](../reference/apis/js-apis-app-ability-wantAgent.md)

Example:

```
import WantAgent from '@ohos.wantAgent';

async function publishNotification() {
  let wantAgentInfo = {
    wants: [
      {
        bundleName: "com.example.notification",
        abilityName: "MainAbility",
      }
    ],
    operationType: WantAgent.OperationType.START_ABILITIES,
    requestCode: 0,
  }
  const wantAgent = await WantAgent.getWantAgent(wantAgentInfo)
  let contentType = Notification.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT;
  await Notification.publish({
    content: {
      contentType: contentType,
      normal: {
        title: "Test Title",
        text: "Test content",
      }
    },
    id: 1,
    wantAgent: wantAgent
  })
  prompt.showToast ({ message: "Sent successfully." })
}
```
