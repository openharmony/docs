# Common Event Development
## Introduction
OpenHarmony provides a Common Event Service (CES) for applications to subscribe to, publish, and unsubscribe from common events.

Common events are classified into system common events and custom common events.

+ System common events: The system sends an event based on system policies to the apps that have subscribed to this event when it occurs. This type of event is typically system events published by key system services, such as HAP installation, update, and uninstallation.

+ Custom common event: customized by applications to implement cross-application event communication.

Each application can subscribe to common events as required. After your application subscribes to a common event, the system sends it to your application every time the event is published. Such an event may be published by the system, other applications, or your own application.

## Common Event Subscription Development

### When to Use
You can create a subscriber object to subscribe to a common event to obtain the parameters passed in the event. Certain system common events require specific permissions to subscribe to. For details, see [Required Permissions](../reference/apis/js-apis-commonEvent.md#support).

### Available APIs
| API                                                                                         | Description|
| ---------------------------------------------------------------------------------------------- | ----------- |
| createSubscriber(subscribeInfo: CommonEventSubscribeInfo, callback: AsyncCallback) | Creates a subscriber. This API uses a callback to return the result.|
| createSubscriber(subscribeInfo: CommonEventSubscribeInfo)                          | Creates a subscriber. This API uses a promise to return the result. |
| subscribe(subscriber: CommonEventSubscriber, callback: AsyncCallback)              | Subscribes to common events.|

### How to Develop
1. Import the **commonEvent** module.

```js
import commonEvent from '@ohos.commonEvent';
```

2. Create a **subscribeInfo** object. For details about the data types and parameters of the object, see [CommonEventSubscribeInfo](../reference/apis/js-apis-commonEvent.md#commoneventsubscribeinfo).

```js
// Used to save the created subscriber object for subsequent subscription and unsubscription.
private subscriber = null

// Subscriber information
var subscribeInfo = {
    events: ["event"],
}
```

3. Create a subscriber object and save the returned object for subsequent operations such as subscription and unsubscription.

```js
// Callback for subscriber creation.
commonEvent.createSubscriber(subscribeInfo, (err, subscriber) => {
    if (err.code) {
        console.error("[CommonEvent]CreateSubscriberCallBack err=" + JSON.stringify(err))
    } else {
        console.log("[CommonEvent]CreateSubscriber")
        this.subscriber = subscriber
        this.result = "Create subscriber succeed"
    }
})
```

4. Create a subscription callback, which is triggered when an event is received. The data returned by the subscription callback contains information such as the common event name and data carried by the publisher. For details about the data types and parameters of the common event data, see [CommonEventData](../reference/apis/js-apis-commonEvent.md#commoneventdata).

```js
// Callback for common event subscription.
if (this.subscriber != null) {
    commonEvent.subscribe(this.subscriber, (err, data) => {
        if (err.code) {
            console.error("[CommonEvent]SubscribeCallBack err=" + JSON.stringify(err))
        } else {
            console.log("[CommonEvent]SubscribeCallBack data=" + JSON.stringify(data))
            this.result = "receive, event = " + data.event + ", data = " + data.data + ", code = " + data.code
        }
    })
    this.result = "Subscribe succeed"
} else {
    prompt.showToast({ message: "Need create subscriber" })
}
```

## Common Event Publishing Development

### When to Use
You can use the **publish** APIs to publish a custom common event, which can carry data for subscribers to parse and process.

### Available APIs
| API                             | Description|
| ---------------------------------- | ------ |
| publish(event: string, callback: AsyncCallback) | Publishes a common event.|
| publish(event: string, options: CommonEventPublishData, callback: AsyncCallback) | Publishes a common event with given attributes.|

### How to Develop
#### Development for Publishing a Common Event
1. Import the **commonEvent** module.

```js
import commonEvent from '@ohos.commonEvent';
```

2. Pass in the common event name and callback, and publish the event.

```js
// Publish a common event.
commonEvent.publish("event", (err) => {
    if (err.code) {
        console.error("[CommonEvent]PublishCallBack err=" + JSON.stringify(err))
    } else {
        console.info("[CommonEvent]Publish1")
    }
})
```

#### Development for Publishing a Common Event with Given Attributes
1. Import the **commonEvent** module.

```js
import commonEvent from '@ohos.commonEvent'
```

2. Define attributes of the common event to publish. For details about the data types and parameters in the data to publish, see [CommonEventPublishData](../reference/apis/js-apis-commonEvent.md#commoneventpublishdata).

```js
// Attributes of a common event.
var options = {
    code: 1,			 // Result code of the common event
    data: "initial data";// Result data of the common event
}
```

3. Pass in the common event name, attributes of the common event, and callback, and publish the event.

```js
// Publish a common event.
commonEvent.publish("event", options, (err) => {
    if (err.code) {
        console.error("[CommonEvent]PublishCallBack err=" + JSON.stringify(err))
    } else {
        console.info("[CommonEvent]Publish2")
    }
})
```

## Common Event Unsubscription Development

### When to Use
You can use the **unsubscribe** API to unsubscribe from a common event.

### Available APIs
| API                             | Description|
| ---------------------------------- | ------ |
| unsubscribe(subscriber: CommonEventSubscriber, callback?: AsyncCallback) | Unsubscribes from a common event.|

### How to Develop
1. Import the **commonEvent** module.

```js
import commonEvent from '@ohos.commonEvent';
```

2. Subscribe to a common event by following instructions in [Common Event Subscription Development](#common-event-subscription-development).
3. Invoke the **unsubscribe** API in **CommonEvent** to unsubscribe from the common event.

```js
if (this.subscriber != null) {
    commonEvent.unsubscribe(this.subscriber, (err) => {
        if (err.code) {
            console.error("[CommonEvent]UnsubscribeCallBack err=" + JSON.stringify(err))
        } else {
            console.log("[CommonEvent]Unsubscribe")
            this.subscriber = null
            this.result = "Unsubscribe succeed"
        }
    })
}
```
