# Event and Notification Development


## How do I encapsulate a commonEvent utility class? (API version 9)

**Problem**

A commonEvent utility class needs to be encapsulated for the following purpose: Register a custom callback function when creating a subscriber, and then call the custom callback function when receiving an event notification.

**Solution**

```
import commonEvent from '@ohos.commonEventManager';

export class SubscribeEvent {
  private static subscriber = null
  // Custom callback function
  private static callback = null
  /**
   * Create a subscriber.
   * @param subscribeInfo Indicates the event to subscribe to.
   * @callback Indicates the custom callback.
   */
  static createSubscriber(subscribeInfo, callback:(a,b)=>void) {
    this.callback = callback
    commonEvent.createSubscriber(subscribeInfo, (err, subscriber) => {
      if (err) {
        console.error('CreateSubscriberCallBack err = ' + JSON.stringify(err))
      } else {
        this.subscriber = subscriber;
        this.subscribe(this.subscriber)
        console.info('Create subscriber succeed')
      }
    })
  }

  /**
   * Subscribe to a common event.
   * @param subscriber Indicates the subscriber.
   */
  private static subscribe(subscriber) {
    if (subscriber != null) {
      commonEvent.subscribe(subscriber, (err, data) => {
        if (err) {
          console.error('subscribe err = ' + JSON.stringify(err))
        } else {
          console.info('SubscribeCallBack data= ' + JSON.stringify(data))
          this.callback('hello callback', data)
        }
      })
    } else {
      console.info("Need create subscriber")
    }
  }
}

@Entry
@Component
struct Faq10_1 {
  @State message: string = ''

  build() {
    Row() {
      Column() {
        Text('Subscribe:' + this.message)
          .fontSize(30)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            let subscribeInfo = {
              events: ["myEvent"]
            };
            let callback = (a,b) => {
              this.message = a
            }
            SubscribeEvent.createSubscriber(subscribeInfo,callback)
          })
        Text('Publish')
          .fontSize(30)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            // Attributes of a common event.
            let options = {
              code: 0,    // Result code of the common event.
              data: "initial data",// Result data of the common event.
              isOrdered: true  // The common event is an ordered one.
            }
            // Callback for common event publication.
            function publishCB(err) {
              if (err) {
                console.error(`publish failed, code is ${err.code}, message is ${err.message}`);
              } else {
                console.info("publish");
              }
            }
            // Publish a common event.
            try {
              commonEvent.publish("myEvent", options, publishCB);
            } catch (err) {
              console.error(`publish failed, code is ${err.code}, message is ${err.message}`);
            }
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

**Reference**

[@ohos.commonEventManager (Common Event)](../reference/apis-basic-services-kit/js-apis-commonEventManager.md)

## How do I make events be transferred in only one UIAbility instance? (API version 9)

**Problem**

Events need to be subscribed to and triggered only in one UIAbility instance.

**Solution**

Use the API in the **EventHub** module of the UIAbility to subscribe to events. The **EventHub** module offers the event center, which provides the API for subscribing to, unsubscribing from, and triggering events.

**Example**

```
import UIAbility from '@ohos.app.ability.UIAbility';
 export default class EntryAbility extends UIAbility {
    onCreate() {
        this.context.eventHub.on('myEvent', this.eventFunc);
    }

    onDestroy() {
        // Result
        // eventFunc is called,undefined,undefined
        this.context.eventHub.emit('myEvent');
        // Result
        // eventFunc is called,1,undefined
        this.context.eventHub.emit('myEvent', 1);
        // Result
        // eventFunc is called,1,2
        this.context.eventHub.emit('myEvent', 1, 2);
    }

     eventFunc(argOne, argTwo) {
        console.log('eventFunc is called, ${argOne}, ${argTwo}');
    }}
```

**Reference**

[Using EventHub for Data Synchronization](../application-models/uiability-data-sync-with-ui.md#using-eventhub-for-data-synchronization).


## How do I implement a click-to-open-application feature in the notification? (API version 9)

**Solution**

You can implement this feature by setting the **wantAgent** attribute in the **NotificationRequest** parameter of the **Notification.publish** API.

**Example**

```
import notificationManager from '@ohos.notificationManager';
import WantAgent from '@ohos.app.ability.wantAgent';

async function publishNotification() {
  let wantAgentInfo = {
    wants: [
      {
        bundleName: "com.example.webuseragent", // Bundle name of the target application.
        abilityName: "EntryAbility",
      }
    ],
    operationType: WantAgent.OperationType.START_ABILITIES,
    requestCode: 1,
  }
  const wantAgent = await WantAgent.getWantAgent(wantAgentInfo)
  let contentType = notificationManager.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT;
  await notificationManager.publish({
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
}
```

**Reference**

[Notification](../reference/apis-notification-kit/js-apis-notificationManager.md) and [WantAgent](../reference/apis-ability-kit/js-apis-app-ability-wantAgent.md)


## What should I do if calling notificationManager.publish fails?

**Problem**

After a notification is published, no error log is displayed, and no notification is displayed in the notification panel.

**Solution**

Before publishing a notification, you must enable the notification feature for your application in the system settings of the real device so that the notification can be viewed in the notification panel.

To manually enable the notification feature, choose **Settings** > **Notification & status bar** > *Application name* > **Allow notifications**.

You can also call the **notificationManager.requestEnableNotification()** API to display a dialog box (only once) to prompt the user to enable the feature.
