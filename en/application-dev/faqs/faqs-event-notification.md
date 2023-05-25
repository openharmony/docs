# Event and Notification Development

## How do I encapsulate a commonEvent utility class?

Applicable to: OpenHarmony 3.1 Beta 5 (API version 9)

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
        Text ('Subscribe:' + this.message)
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
        Text ('Publish')
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

[@ohos.commonEventManager (Common Event)](../reference/apis/js-apis-commonEventManager.md)

## How do I make events be transferred in only one UIAbility instance?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Problem**

Events need to be subscribed to and triggered only in one UIAbility instance.

**Solution**

Use the API in the **EventHub** module of the UIAbility to subscribe to events. The **EventHub** module offers the event center, which provides the API for subscribing to, unsubscribing from, and triggering events.

**Example**

```
import UIAbility from '@ohos.app.ability.UIAbility';
 export default class EntryAbility extends UIAbility {
    onForeground() {
        this.context.eventHub.on('myEvent', this.eventFunc);
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
