# Notification Module


## Required Permissions

None


## Modules to Import

```js
import Notification from '@ohos.notification';
```

## System Capabilities

```js
SystemCapability.Notification.Notification
```

## Notification.publish(request: NotificationRequest, callback: AsyncCallback\<void\>)

- Functionality

  Publishes a notification. This method uses a callback to return the result.

- Parameters


| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | --------------------- | ---- | ------------------------------------------- |
| request  | Read-only| NotificationRequest   | Yes| Notification to publish.|
| callback | Read-only| AsyncCallback\<void\> | Yes| Callback used to return the result.|

- NotificationRequest

| Name| Readable/Writable| Type| Mandatory| Description|
| --------------------- | -------- | --------------------------------------------- | ---- | -------------------------- |
| content               | Readable and writable| NotificationContent                           | Yes| Notification content.|
| id                    | Readable and writable| number                                        | No| Notification ID.|
| slotType              | Readable and writable| SlotType                                      | No| Notification slot type.|
| isOngoing             | Readable and writable| boolean                                       | No| Whether the notification is an ongoing notification.|
| isUnremovable         | Readable and writable| boolean                                       | No| Whether the notification can be removed.|
| deliveryTime          | Readable and writable| number                                        | No| Time when the notification is sent.|
| tapDismissed          | Readable and writable| boolean                                       | No| Whether the notification can be automatically cleared.|
| autoDeletedTime       | Readable and writable| number                                        | No| Time when the notification is automatically cleared.|
| wantAgent             | Readable and writable| WantAgent                                     | No| **WantAgent** object to which the notification will be redirected after being clicked.|
| extraInfo             | Readable and writable| {[key: string]: any}                          | No| Extended parameter.|
| color                 | Readable and writable| number                                        | No| Background color of the notification.|
| colorEnabled          | Readable and writable| boolean                                       | No| Whether the notification background color is enabled.|
| isAlertOnce           | Readable and writable| boolean                                       | No| Whether the notification triggers an alert only once.|
| isStopwatch           | Readable and writable| boolean                                       | No| Whether to display the stopwatch.|
| isCountDown           | Readable and writable| boolean                                       | No| Whether to display the countdown time.|
| isFloatingIcon        | Readable and writable| boolean                                       | No| Whether the notification is displayed as a floating icon.|
| label                 | Readable and writable| string                                        | No| Notification label.|
| badgeIconStyle        | Readable and writable| number                                        | No| Notification badge type.|
| showDeliveryTime      | Readable and writable| boolean                                       | No| Whether to display the time when the notification is delivered.|
| actionButtons         | Readable and writable| Array\<NotificationActionButton\>             | No| Buttons in the notification. Up to two buttons are allowed.|
| smallIcon             | Readable and writable| PixelMap                                      | No| Small notification icon.|
| largeIcon             | Readable and writable| PixelMap                                      | No| Large notification icon.|
| creatorBundleName     | Read-only| string                                        | No| Name of the bundle that creates the notification.|
| creatorUid            | Read-only| number                                        | No| UID of the notification creator.|
| creatorPid            | Read-only| number                                        | No| PID of the notification creator.|
| hashCode              | Read-only| string                                        | No| Unique ID of the notification.|
| classification        | Readable and writable| string                                        | No| Notification category.|
| groupName             | Readable and writable| string                                        | No| Notification group name.|
| template<sup>8+</sup> | Readable and writable| [NotificationTemplate](#notificationtemplate) | No| Notification template.|

NotificationContent

| Name| Readable/Writable| Type| Mandatory| Description|
| ----------- | -------- | ---------------------------- | ---- | ------------------ |
| contentType | Readable and writable| ContentType                  | Yes| Notification content type.|
| normal      | Readable and writable| NotificationBasicContent     | No| Normal text.|
| longText    | Readable and writable| NotificationLongTextContent  | No| Long text.|
| multiLine   | Readable and writable| NotificationMultiLineContent | No| Multi-line text.|
| picture     | Readable and writable| NotificationPictureContent   | No| Picture-attached.|

- ContentType

| Name| Readable/Writable| Type| Description|
| --------------------------------- | -------- | ----------- | ---------------- |
| NOTIFICATION_CONTENT_BASIC_TEXT   | Read-only| ContentType | Normal text notification.|
| NOTIFICATION_CONTENT_LONG_TEXT    | Read-only| ContentType | Long text notification.|
| NOTIFICATION_CONTENT_PICTURE      | Read-only| ContentType | Picture-attached notification.|
| NOTIFICATION_CONTENT_CONVERSATION | Read-only| ContentType | Conversation notification.|
| NOTIFICATION_CONTENT_MULTILINE    | Read-only| ContentType | Multi-line text notification.|

- NotificationBasicContent

| Name| Readable/Writable| Type| Mandatory| Description|
| -------------- | -------- | ------ | ---- | -------------------------------- |
| title          | Readable and writable| string | Yes| Notification title.|
| text           | Readable and writable| string | Yes| Notification content.|
| additionalText | Readable and writable| string | Yes| Additional information of the notification.|

- NotificationLongTextContent

| Name| Readable/Writable| Type| Mandatory| Description|
| -------------- | -------- | ------ | ---- | -------------------------------- |
| title          | Readable and writable| string | Yes| Notification title.|
| text           | Readable and writable| string | Yes| Notification content.|
| additionalText | Readable and writable| string | Yes| Additional information of the notification.|
| longText       | Readable and writable| string | Yes| Long text content of the notification.|
| briefText      | Readable and writable| string | Yes| Brief text of the notification.|
| expandedTitle  | Readable and writable| string | Yes| Title of the notification in the expanded state.|

- NotificationMultiLineContent

| Name| Readable/Writable| Type| Mandatory| Description|
| -------------- | -------- | --------------- | ---- | -------------------------------- |
| title          | Readable and writable| string          | Yes| Notification title.|
| text           | Readable and writable| string          | Yes| Notification content.|
| additionalText | Readable and writable| string          | Yes| Additional information of the notification.|
| briefText      | Readable and writable| string          | Yes| Brief text of the notification.|
| longTitle      | Readable and writable| string          | Yes| Title of the notification in the expanded state.|
| lines          | Readable and writable| Array\<String\> | Yes| Multi-line content.|

- NotificationPictureContent

| Name| Readable/Writable| Type| Mandatory| Description|
| -------------- | -------- | -------------- | ---- | -------------------------------- |
| title          | Readable and writable| string         | Yes| Notification title.|
| text           | Readable and writable| string         | Yes| Notification content.|
| additionalText | Readable and writable| string         | Yes| Additional information of the notification.|
| briefText      | Readable and writable| string         | Yes| Brief text of the notification.|
| expandedTitle  | Readable and writable| string         | Yes| Title of the notification in the expanded state.|
| picture        | Readable and writable| image.PixelMap | Yes| Picture included in the notification.|

- SlotType

| Name| Readable/Writable| Type| Mandatory| Description|
| -------------------- | -------- | -------- | ---- | -------- |
| SOCIAL_COMMUNICATION | Read-only| SlotType | No| Notification slot for social communication.|
| SERVICE_INFORMATION  | Read-only| SlotType | No| Notification slot for service information.|
| CONTENT_INFORMATION  | Read-only| SlotType | No| Notification slot for content consultation.|
| OTHER_TYPES          | Read-only| SlotType | No| Notification slot for other purposes.|

- NotificationActionButton

| Name| Readable/Writable| Type| Mandatory| Description|
| --------- | -------- | --------------------- | ---- | ------------------------- |
| title     | Readable and writable| string                | Yes| Button title.|
| wantAgent | Readable and writable| wantAgent             | Yes| **WantAgent** of the button.|
| extras    | Readable and writable| Array\<String\>       | No| Extra information of the button.|
| icon      | Readable and writable| image.PixelMap        | No| Button icon.|
| userInput | Readable and writable| NotificationUserInput | No| User input object.|

- NotificationUserInput

| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | ------ | ---- | ----------------------------- |
| inputKey | Readable and writable| string | Yes| Key to identify the user input.|


- Return value

  void

- Example

```js
// publish callback
function publishCallback(err) {
	console.info("==========================>publishCallback=======================>");
}
// NotificationRequest object
var notificationRequest = {
    id: 1,
    content: {
        contentType: notify.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
        normal: {
            title: "test_title",
            text: "test_text",
            additionalText: "test_additionalText"
        }
    }
}
Notification.publish(notificationRequest, publishCallback)
```



## Notification.publish(request: NotificationRequest)

- Functionality

  Publishes a notification. This method uses a promise to return the result.

- Return value

  Promise\<void\>

- Example

```js
// NotificationRequest object
var notificationRequest = {
    notificationId: 1,
    content: {
        contentType: notify.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
        normal: {
            title: "test_title",
            text: "test_text",
            additionalText: "test_additionalText"
        }
    }
}
Notification.publish(notificationRequest).then((void) => {
	console.info("==========================>publishCallback=======================>");
});

```



## Notification.cancel(id: number, label: string, callback: AsyncCallback\<void\>)

- Functionality

  Cancels a notification with the specified ID and label. This method uses a callback to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | --------------------- | ---- | -------------------- |
| id       | Read-only| number                | Yes| Notification ID.|
| label    | Read-only| string                | Yes| Notification label.|
| callback | Read-only| AsyncCallback\<void\> | Yes| Callback used to return the result.|

- Return value

  void

- Example

```js
// cancel callback
function cancelCallback(err) {
	console.info("==========================>cancelCallback=======================>");
}
Notification.cancel(0, "label", cancelCallback)
```



## Notification.cancel(id: number, label? : string)

- Functionality

  Cancels a notification with the specified ID and label. This method uses a promise to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| ----- | -------- | ------ | ---- | -------- |
| id    | Read-only| number | Yes| Notification ID.|
| label | Read-only| string | No| Notification label.|

- Return value

  Promise\<void\>

- Example

```js
Notification.cancel(0).then((void) => {
	console.info("==========================>cancelCallback=======================>");
});
```



## Notification.cancel(id: number, callback: AsyncCallback\<void\>)

- Functionality

  Cancels a notification with the specified ID. This method uses a callback to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | --------------------- | ---- | -------------------- |
| id       | Read-only| number                | Yes| Notification ID.|
| callback | Read-only| AsyncCallback\<void\> | Yes| Callback used to return the result.|

- Return value

  void

- Example

```js
// cancel callback
function cancelCallback(err) {
	console.info("==========================>cancelCallback=======================>");
}
Notification.cancel(0, cancelCallback)
```



## Notification.cancelAll(callback: AsyncCallback\<void\>)

- Functionality

  Cancels all notifications. This method uses a callback to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | --------------------- | ---- | -------------------- |
| callback | Read-only| AsyncCallback\<void\> | Yes| Callback used to return the result.|

- Return value

  void

- Example

```js
// cancel callback
function cancelAllback(err) {
	console.info("==========================>cancelAllback=======================>");
}
Notification.cancelAll(cancelCallback)
```



## Notification.cancelAll()

- Functionality

  Cancels all notifications. This method uses a promise to return the result.

- Parameters

  None

- Return value

  Promise\<void\>

- Example

```js
Notification.cancelAll().then((void) => {
	console.info("==========================>cancelAllback=======================>");
});
```



## Notification.addSlot(slot: NotificationSlot, callback: AsyncCallback\<void\>)

- Functionality

  Adds a notification slot. This method uses a callback to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | --------------------- | ---- | -------------------- |
| slot     | Read-only| NotificationSlot      | Yes| Notification slot to add.|
| callback | Read-only| AsyncCallback\<void\> | Yes| Callback used to return the result.|

- NotificationSlot

| Name| Readable/Writable| Type| Mandatory| Description|
| -------------------- | -------- | --------------- | ---- | ------------------------------------------ |
| type                 | Readable and writable| SlotType        | Yes| Notification slot type.|
| level                | Readable and writable| number          | No| Notification level. If this parameter is not set, the default value is used based on the notification slot type.|
| desc                 | Readable and writable| string          | No| Description of the notification slot.|
| badgeFlag            | Readable and writable| boolean         | No| Whether to display the badge.|
| bypassDnd            | Readable and writable| boolean         | No| Whether to bypass the system do-not-disturb (DND) setting.|
| lockscreenVisibility | Readable and writable| boolean         | No| How the notification is displayed on the locked screen.|
| vibrationEnabled     | Readable and writable| boolean         | No| Whether vibration is enabled for the notification.|
| sound                | Readable and writable| string          | No| Notification sound.|
| lightEnabled         | Readable and writable| boolean         | No| Whether light is enabled for the notification.|
| lightColor           | Readable and writable| number          | No| Notification light color.|
| vibrationValues      | Readable and writable| Array\<number\> | No| Notification vibration mode.|

* Return values

  void

* Example

```js
// addSlot callback
function addSlotCallBack(err) {
	console.info("==========================>addSlotCallBack=======================>");
}
// NotificationSlot object
var notificationSlot = {
    type: Notification.SlotType.SOCIAL_COMMUNICATION
}
Notification.addSlot(notificationSlot, addSlotCallBack)
```



## Notification.addSlot(slot: NotificationSlot)

- Functionality

  Adds a notification slot. This method uses a promise to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| ---- | -------- | ---------------- | ---- | -------------------- |
| slot | Read-only| NotificationSlot | Yes| Notification slot to add.|

- Return value

  Promise\<void\>

- Example

```js
// NotificationSlot object
var notificationSlot = {
    type: Notification.SlotType.SOCIAL_COMMUNICATION
}
Notification.addSlot(notificationSlot).then((void) => {
	console.info("==========================>addSlotCallback=======================>");
});
```



## Notification.addSlot(type: SlotType, callback: AsyncCallback\<void\>)

- Functionality

  Adds a notification slot. This method uses a callback to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | --------------------- | ---- | ---------------------- |
| type     | Read-only| SlotType              | Yes| Type of the notification slot to add.|
| callback | Read-only| AsyncCallback\<void\> | Yes| Callback used to return the result.|

- Return value

  void

- Example

```js
// addSlot callback
function addSlotCallBack(err) {
	console.info("==========================>addSlotCallBack=======================>");
}
Notification.addSlot(Notification.SlotType.SOCIAL_COMMUNICATION, addSlotCallBack)
```



## Notification.addSlot(type: SlotType)

- Functionality

  Adds a notification slot. This method uses a promise to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| ---- | -------- | -------- | ---- | ---------------------- |
| type | Read-only| SlotType | Yes| Type of the notification slot to add.|

- Return value

  Promise\<void\>

- Example

```js
Notification.addSlot(Notification.SlotType.SOCIAL_COMMUNICATION).then((void) => {
	console.info("==========================>addSlotCallback=======================>");
});
```



## Notification.addSlots(slots: Array\<NotificationSlot\>, callback: AsyncCallback\<void\>)

- Functionality

  Adds multiple notification slots. This method uses a callback to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | ------------------------- | ---- | ------------------------ |
| slots    | Read-only| Array\<NotificationSlot\> | Yes| Notification slots to add.|
| callback | Read-only| AsyncCallback\<void\>     | Yes| Callback used to return the result.|

- Return value

  void

- Example

```js
// addSlots callback
function addSlotsCallBack(err) {
	console.info("==========================>addSlotsCallBack=======================>");
}
// NotificationSlot object
var notificationSlot = {
    type: Notification.SlotType.SOCIAL_COMMUNICATION
}
// NotificationSlotArray object
var notificationSlotArray = new Array(); 
notificationSlotArray[0] = notificationSlot; 

Notification.addSlots(notificationSlotArray, addSlotsCallBack)
```



## Notification.addSlots(slots: Array\<NotificationSlot\>)

- Functionality

  Adds multiple notification slots. This method uses a promise to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| ----- | -------- | ------------------------- | ---- | ------------------------ |
| slots | Read-only| Array\<NotificationSlot\> | Yes| Notification slots to add.|

- Return value

  Promise\<void\>

- Example

```js
// NotificationSlot object
var notificationSlot = {
    type: Notification.SlotType.SOCIAL_COMMUNICATION
}
// NotificationSlotArray object
var notificationSlotArray = new Array(); 
notificationSlotArray[0] = notificationSlot; 

Notification.addSlots(notificationSlotArray).then((void) => {
	console.info("==========================>addSlotCallback=======================>");
});
```



## Notification.getSlot(slotType: SlotType, callback: AsyncCallback\<NotificationSlot\>)

- Functionality

  Obtains a notification slot of the specified type. This method uses a callback to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | --------------------------------- | ---- | ----------------------------------------------------------- |
| slotType | Read-only| slotType                          | Yes| Type of the notification slot, which can be used for social communication, service information, content consultation, and other purposes.|
| callback | Read-only| AsyncCallback\<NotificationSlot\> | Yes| Callback used to return the result.|

- Return value

  void

- Example

```js
// getSlot callback
function getSlotCallback(err,data) {
	console.info("==========================>getSlotCallback=======================>");
}
var slotType = Notification.SlotType.SOCIAL_COMMUNICATION;
Notification.getSlot(slotType, getSlotCallback)
```



## Notification.getSlot(slotType)

- Functionality

  Obtains a notification slot of the specified type. This method uses a promise to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | -------- | ---- | ----------------------------------------------------------- |
| slotType | Read-only| slotType | Yes| Type of the notification slot, which can be used for social communication, service information, content consultation, and other purposes.|

- Return value

  Promise\<NotificationSlot\>

- Example

```js
var slotType = Notification.SlotType.SOCIAL_COMMUNICATION;
Notification.getSlot(slotType).then((data) => {
	console.info("==========================>getSlotCallback=======================>");
});
```



## Notification.getSlots(callback: AsyncCallback<Array\<NotificationSlot\>>)

- Functionality

  Obtains all notification slots. This method uses a callback to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | --------------------------------- | ---- | -------------------- |
| callback | Read-only| AsyncCallback\<NotificationSlot\> | Yes| Callback used to return the result.|

- Return value

  void

- Example

```js
// getSlots callback
function getSlotsCallback(err,data) {
	console.info("==========================>getSlotsCallback=======================>");
}
Notification.getSlots(getSlotsCallback)
```



## Notification.getSlots()

- Functionality

  Obtains all notification slots of the current application. This method uses a promise to return the result.

- Parameters

  None

- Return value

  Promise\<Array\<NotificationSlot\>\>

- Example

```js
Notification.getSlots().then((data) => {
	console.info("==========================>getSlotsCallback=======================>");
});
```



## Notification.removeSlot(slotType: SlotType, callback: AsyncCallback\<void\>)

- Functionality

  Removes a notification slot of the specified type. This method uses a callback to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | --------------------- | ---- | ----------------------------------------------------------- |
| SlotType | Read-only| SlotType              | Yes| Type of the notification slot, which can be used for social communication, service information, content consultation, and other purposes.|
| callback | Read-only| AsyncCallback\<void\> | Yes| Callback used to return the result.|

- Return value

  void

- Example

```js
// removeSlot callback
function removeSlotCallback(err) {
	console.info("==========================>removeSlotCallback=======================>");
}
var slotType = Notification.SlotType.SOCIAL_COMMUNICATION;
Notification.removeSlot(slotType,removeSlotCallback)
```



## Notification.removeSlot(slotType: SlotType)

- Functionality

  Removes a notification slot of the specified type. This method uses a promise to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | -------- | ---- | ----------------------------------------------------------- |
| SlotType | Read-only| SlotType | Yes| Type of the notification slot, which can be used for social communication, service information, content consultation, and other purposes.|

- Return value

  Promise\<void\>

- Example

```js
var slotType = Notification.SlotType.SOCIAL_COMMUNICATION;
Notification.removeSlot(slotType).then((void) => {
	console.info("==========================>removeSlotCallback=======================>");
});
```



## Notification.removeAllSlots(callback: AsyncCallback\<void\>)

- Functionality

  Removes all notification slots. This method uses a callback to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | --------------------- | ---- | -------------------- |
| callback | Read-only| AsyncCallback\<void\> | Yes| Callback used to return the result.|

- Return value

  void

- Example

```js
function removeAllCallBack(err) {
	console.info("================>removeAllCallBack=======================>");
}
Notification.removeAllSlots(removeAllCallBack)
```



## Notification.removeAllSlots()

- Functionality

  Removes all notification slots. This method uses a promise to return the result.

- Parameters

  None

- Return value

  Promise\<void\>

- Example

```js
Notification.removeAllSlots().then((void) => {
	console.info("==========================>removeAllCallBack=======================>");
});
```



## Notification.subscribe(subscriber: NotificationSubscriber, info: NotificationSubscribeInfo, callback: AsyncCallback\<void\>)

- Functionality

  Subscribes to a notification with the subscription information specified. This method uses a callback to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| ---------- | -------- | ------------------------- | ---- | ---------------- |
| subscriber | Read-only| NotificationSubscriber    | Yes| Notification subscriber.|
| info       | Read-only| NotificationSubscribeInfo | Yes| Subscription information.|
| callback   | Read-only| AsyncCallback\<void\>     | Yes| Callback used to return the result.|

- NotificationSubscriber

| Name| Readable/Writable| Type| Mandatory| Description|
| ------------------------------------------------------------ | -------- | -------- | ---- | -------------------------- |
| onConsume?:(data: SubscribeCallbackData)                     | Readable and writable| function | No| Callback for receiving notifications.|
| onCancel?:(data: SubscribeCallbackData)                      | Readable and writable| function | No| Callback for canceling notifications.|
| onUpdate?:(data: NotificationSortingMap)                     | Readable and writable| function | No| Callback for notification sorting updates.|
| onConnect?:()                                                | Readable and writable| function | No| Callback for subscription.|
| onDisconnect?:()                                             | Readable and writable| function | No| Callback for unsubscription.|
| onDestroy?:()                                                | Readable and writable| function | No| Callback for service destruction.|
| onDoNotDisturbDateChange?:(mode: notification.DoNotDisturbDate) | Readable and writable| function | No| Callback for DND time setting updates.|

- SubscribeCallbackData

| Name| Readable/Writable| Type| Mandatory| Description|
| --------------- | -------- | ---------------------- | ---- | -------- |
| request         | Read-only| NotificationRequest    | Yes| Notification content.|
| sortingMap      | Read-only| NotificationSortingMap | No| Notification sorting information.|
| reason          | Read-only| number                 | No| Reason for deletion.|
| sound           | Read-only| string                 | No| Sound used for notification.|
| vibrationValues | Read-only| Array\<number\>        | No| Vibration used for notification.|

- NotificationSortingMap

| Name| Readable/Writable| Type| Mandatory| Description|
| -------------- | -------- | ------------------------------------ | ---- | ---------------- |
| sortings       | Read-only| {[key: string]: NotificationSorting} | Yes| Array of notification sorting information.|
| sortedHashCode | Read-only| Array\<string\>                      | Yes| Array of unique notification IDs.|

- NotificationSorting

| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | ---------------- | ---- | ------------ |
| slot     | Read-only| NotificationSlot | Yes| Notification slot.|
| hashCode | Read-only| string           | Yes| Unique ID of the notification.|
| ranking  | Read-only| number           | Yes| Notification sequence number.|

- DoNotDisturbType


| Name| Readable/Writable| Type| Description|
| ------------ | -------- | --------------------- | ---------------------------------------- |
| TYPE_NONE    | Read-only| enum DoNotDisturbType | Non-DND.|
| TYPE_ONCE    | Read-only| enum DoNotDisturbType | One-shot DND at the specified time segment (only considering the hour and minute)|
| TYPE_DAILY   | Read-only| enum DoNotDisturbType | Daily DND at the specified time segment (only considering the hour and minute)|
| TYPE_CLEARLY | Read-only| enum DoNotDisturbType | DND at the specified time segment (considering the year, month, day, hour, and minute)|

- DoNotDisturbDate

| Name| Readable/Writable| Type| Description|
| ----- | -------- | ---------------- | ------------------------ |
| type  | Readable and writable| DoNotDisturbType | DND time type.|
| begin | Readable and writable| Date             | DND start time.|
| end   | Readable and writable| Date             | DND end time.|

- NotificationSubscribeInfo

| Name| Readable/Writable| Type| Mandatory| Description|
| ----------- | -------- | --------------- | ---- | ------------------------------- |
| bundleNames | Readable and writable| Array\<string\> | No| Bundle names of the applications whose notifications are to be subscribed to.|
| userId      | Readable and writable| number          | No| User whose notifications are to be subscribed to.|

- Return value

  void

- Example

```js
// subscribe callback
function subscribeCallback(err) {
	console.info("==========================>subscribeCallback=======================>");
}
function onConsumeCallback(err, data) {
	console.info("==========================>onConsumeCallback=======================>");
}
var subscriber = {
    onConsume: onConsumeCallback
}
var info = {
    bundleNames: ["bundleName1","bundleName2"]
}
Notification.subscribe(subscriber, info, subscribeCallback);
```



## Notification.subscribe(subscriber: NotificationSubscriber, callback: AsyncCallback\<void\>)

- Functionality

  Subscribes to a notification. This method uses a callback to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| ---------- | -------- | ---------------------- | ---- | ---------------- |
| subscriber | Read-only| NotificationSubscriber | Yes| Notification subscriber.|
| callback   | Read-only| AsyncCallback\<void\>  | Yes| Callback used to return the result.|

- Return value

  void

- Example

```js
function subscribeCallback(err) {
	console.info("==========================>subscribeCallback=======================>");
}
function onConsumeCallback(err, data) {
	console.info("==========================>onConsumeCallback=======================>");
}
var subscriber = {
    onConsume: onConsumeCallback
}
Notification.subscribe(subscriber, subscribeCallback);
```



## Notification.subscribe(subscriber: NotificationSubscriber, info?: NotificationSubscribeInfo)

- Functionality

  Subscribes to a notification with the subscription information specified. This method uses a promise to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| ---------- | -------- | ------------------------- | ---- | ------------ |
| subscriber | Read-only| NotificationSubscriber    | Yes| Notification subscriber.|
| info       | Read-only| NotificationSubscribeInfo | No| Subscription information.|

- Return value

  Promise\<void\>

- Example

```js
function onConsumeCallback(err, data) {
	console.info("==========================>onConsumeCallback=======================>");
}
var subscriber = {
    onConsume: onConsumeCallback
};
Notification.subscribe(subscriber).then((void) => {
	console.info("==========================>subscribeCallback=======================>");
});
```



## Notification.unsubscribe(subscriber: NotificationSubscriber, callback: AsyncCallback\<void\>)

- Functionality

  Unsubscribes from a notification. This method uses a callback to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| ---------- | -------- | ---------------------- | ---- | -------------------- |
| subscriber | Read-only| NotificationSubscriber | Yes| Notification subscriber.|
| callback   | Read-only| AsyncCallback\<void\>  | Yes| Callback used to return the result.|

- Return value

  void

- Example

```js
function unsubscribeCallback(err) {
	console.info("==========================>unsubscribeCallback=======================>");
}
function onConsumeCallback(err, data) {
	console.info("==========================>onConsumeCallback=======================>");
}
var subscriber = {
    onConsume: onConsumeCallback
}
Notification.unsubscribe(subscriber, unsubscribeCallback);
```



## Notification.unsubscribe(subscriber: NotificationSubscriber)

- Functionality

  Unsubscribes from a notification. This method uses a promise to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| ---------- | -------- | ---------------------- | ---- | ------------ |
| subscriber | Read-only| NotificationSubscriber | Yes| Notification subscriber.|

- Return value

  Promise\<void\>

- Example

```js
function onConsumeCallback(err, data) {
	console.info("==========================>onConsumeCallback=======================>");
}
var subscriber = {
    onConsume: onConsumeCallback
};
Notification.unsubscribe(subscriber).then((void) => {
	console.info("==========================>unsubscribeCallback=======================>");
});
```



## Notification.enableNotification(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void\>)

- Functionality

  Sets whether to enable notification for a specified bundle. This method uses a callback to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | --------------------- | ---- | -------------------- |
| bundle   | Read-only| BundleOption          | Yes| Bundle information.|
| enable   | Read-only| boolean               | Yes| Whether to enable notification.|
| callback | Read-only| AsyncCallback\<void\> | Yes| Callback used to return the result.|

- BundleOption

| Name| Readable/Writable| Type| Mandatory| Description|
| ------ | -------- | ------ | ---- | ------ |
| bundle | Readable and writable| string | Yes| Bundle name.|
| uid    | Readable and writable| number | No| User ID.|
- Return value

  void

- Example

```js
function enableNotificationCallback(err) {
	console.info("==========================>enableNotificationCallback=======================>");
}
var bundle = {
    bundle: "bundleName1";
}
Notification.enableNotification(bundle, false, enableNotificationCallback);
```



## Notification.enableNotification(bundle: BundleOption, enable: boolean)

- Functionality

  Sets whether to enable notification for a specified bundle. This method uses a promise to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| ------ | -------- | ------------ | ---- | ---------- |
| bundle | Read-only| BundleOption | Yes| Bundle information.|
| enable | Read-only| boolean      | Yes| Whether to enable notification.|

- Return value

  Promise\<void\>

- Example

```js
var bundle = {
    bundle: "bundleName1";
}
Notification.enableNotification(bundle, false).then((void) => {
	console.info("==========================>enableNotificationCallback=======================>");
});
```



## Notification.isNotificationEnabled(bundle: BundleOption, callback: AsyncCallback\<boolean\>)

- Functionality

  Checks whether notification is enabled for a specified bundle. This method uses a callback to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | --------------------- | ---- | ------------------------ |
| bundle   | Read-only| BundleOption          | Yes| Bundle information.|
| callback | Read-only| AsyncCallback\<void\> | Yes| Callback used to return the result.|

- Return value

  void

- Example

```js
function isNotificationEnabledCallback(err, data) {
	console.info("==========================>isNotificationEnabledCallback=======================>");
}
var bundle = {
    bundle: "bundleName1";
}
Notification.isNotificationEnabled(bundle, isNotificationEnabledCallback);
```



## Notification.isNotificationEnabled(bundle: BundleOption)

- Functionality

  Checks whether notification is enabled for a specified bundle. This method uses a promise to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| ------ | -------- | ------------ | ---- | ---------- |
| bundle | Read-only| BundleOption | Yes| Bundle information.|

- Return value

  Promise\<boolean\>

- Example

```js
var bundle = {
    bundle: "bundleName1";
}
Notification.isNotificationEnabled(bundle).then((data) => {
	console.info("==========================>isNotificationEnabledCallback=======================>");
});
```



## Notification.isNotificationEnabled(callback: AsyncCallback\<boolean\>)

- Functionality

  Checks whether notification is enabled for the current application. This method uses a callback to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | --------------------- | ---- | ------------------------ |
| callback | Read-only| AsyncCallback\<void\> | Yes| Callback used to return the result.|

- Return value

  void

- Example

```js
function isNotificationEnabledCallback(err, data) {
	console.info("==========================>isNotificationEnabledCallback=======================>");
}

Notification.isNotificationEnabled(isNotificationEnabledCallback);
```



## Notification.isNotificationEnabled()

- Functionality

  Checks whether notification is enabled for the current application. This method uses a promise to return the result.

- Parameters

  None

- Return value

  Promise\<boolean\>

- Example

```js
Notification.isNotificationEnabled().then((data) => {
	console.info("==========================>isNotificationEnabledCallback=======================>");
});
```



## Notification.displayBadge(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void\>)

- Functionality

  Sets whether to display the badge in notifications for a specified bundle. This method uses a callback to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | --------------------- | ---- | -------------------- |
| bundle   | Read-only| BundleOption          | Yes| Bundle information.|
| enable   | Read-only| boolean               | Yes| Whether to display the badge.|
| callback | Read-only| AsyncCallback\<void\> | Yes| Callback used to return the result.|

- Return value

  void

- Example

```js
function displayBadgeCallback(err) {
	console.info("==========================>displayBadgeCallback=======================>");
}
var bundle = {
    bundle: "bundleName1";
}
Notification.displayBadge(bundle, false, displayBadgeCallback);
```



## Notification.displayBadge(bundle: BundleOption, enable: boolean)

- Functionality

  Sets whether to display the badge in notifications for a specified bundle. This method uses a promise to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| ------ | -------- | ------------ | ---- | ---------- |
| bundle | Read-only| BundleOption | Yes| Bundle information.|
| enable | Read-only| boolean      | Yes| Whether to display the badge.|

- Return value

  Promise\<void\>

- Example

```js
var bundle = {
    bundle: "bundleName1";
}
Notification.displayBadge(bundle, false).then((void) => {
	console.info("==========================>displayBadgeCallback=======================>");
});
```



## Notification.isBadgeDisplayed(bundle: BundleOption, callback: AsyncCallback\<boolean\>)

- Functionality

  Checks whether the badge will be displayed in notifications of a specified bundle. This method uses a callback to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | --------------------- | ---- | ------------------------ |
| bundle   | Read-only| BundleOption          | Yes| Bundle information.|
| callback | Read-only| AsyncCallback\<void\> | Yes| Callback used to return the result.|

- Return value

  void

- Example

```js
function isBadgeDisplayedCallback(err, data) {
	console.info("==========================>isBadgeDisplayedCallback=======================>");
}
var bundle = {
    bundle: "bundleName1";
}
Notification.isBadgeDisplayed(bundle, isBadgeDisplayedCallback);
```



## Notification.isBadgeDisplayed(bundle: BundleOption)

- Functionality

  Checks whether the badge will be displayed in notifications of a specified bundle. This method uses a promise to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| ------ | -------- | ------------ | ---- | ---------- |
| bundle | Read-only| BundleOption | Yes| Bundle information.|

- Return value

  Promise\<boolean\>

- Example

```js
var bundle = {
    bundle: "bundleName1";
}
Notification.isBadgeDisplayed(bundle).then((data) => {
	console.info("==========================>isBadgeDisplayedCallback=======================>");
});
```



## Notification.setSlotByBundle(bundle: BundleOption, slot: NotificationSlot, callback: AsyncCallback\<void\>)

- Functionality

  Sets a notification slot for a specified bundle. This method uses a callback to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | --------------------- | ---- | -------------------- |
| bundle   | Read-only| BundleOption          | Yes| Bundle information.|
| slot     | Read-only| NotificationSlot      | Yes| Notification slot.|
| callback | Read-only| AsyncCallback\<void\> | Yes| Callback used to return the result.|

- Return value

  void

- Example

```js
function setSlotByBundleCallback(err) {
	console.info("==========================>setSlotByBundleCallback=======================>");
}
var bundle = {
    bundle: "bundleName1";
}
var notificationSlot = {
    type: Notification.SlotType.SOCIAL_COMMUNICATION
}
Notification.setSlotByBundle(bundle, notificationSlot, setSlotByBundleCallback);
```



## Notification.setSlotByBundle(bundle: BundleOption, slot: NotificationSlot)

- Functionality

  Sets a notification slot for a specified bundle. This method uses a promise to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| ------ | -------- | ------------ | ---- | ---------- |
| bundle | Read-only| BundleOption | Yes| Bundle information.|
| slot| Read-only| NotificationSlot| Yes| Notification slot.|

- Return value

  Promise\<void\>

- Example

```js
var bundle = {
    bundle: "bundleName1";
}
var notificationSlot = {
    type: Notification.SlotType.SOCIAL_COMMUNICATION
}
Notification.displayBadge(bundle, notificationSlot).then((void) => {
	console.info("==========================>setSlotByBundleCallback=======================>");
});
```



## Notification.getSlotsByBundle(bundle: BundleOption, callback: AsyncCallback<Array\<NotificationSlot\>>)

- Functionality

  Obtains the notification slots of a specified bundle. This method uses a callback to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | ---------------------------------------- | ---- | -------------------- |
| bundle   | Read-only| BundleOption                             | Yes| Bundle information.|
| callback | Read-only| AsyncCallback<Array\<NotificationSlot\>> | Yes| Callback used to return the result.|

- Return value

  void

- Example

```js
function getSlotsByBundleCallback(err, data) {
	console.info("==========================>getSlotsByBundleCallback=======================>");
}
var bundle = {
    bundle: "bundleName1";
}
Notification.getSlotsByBundle(bundle, getSlotsByBundleCallback);
```



## Notification.getSlotsByBundle(bundle: BundleOption)

- Functionality

  Obtains the notification slots of a specified bundle. This method uses a promise to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| ------ | -------- | ------------ | ---- | ---------- |
| bundle | Read-only| BundleOption | Yes| Bundle information.|

- Return value

  Promise<Array\<NotificationSlot\>>

- Example

```js
var bundle = {
    bundle: "bundleName1";
}
Notification.getSlotsByBundle(bundle).then((data) => {
	console.info("==========================>getSlotsByBundleCallback=======================>");
});
```



## Notification.getSlotNumByBundle(bundle: BundleOption, callback: AsyncCallback\<number\>)

- Functionality

  Obtains the number of notification slots of a specified bundle. This method uses a callback to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | ------------------------- | ---- | ---------------------- |
| bundle   | Read-only| BundleOption              | Yes| Bundle information.|
| callback | Read-only| AsyncCallback\<number\> | Yes| Callback used to return the result.|

- Return value

  void

- Example

```js
function getSlotNumByBundle(err, data) {
	console.info("==========================>getSlotNumByBundleCallback=======================>");
}
var bundle = {
    bundle: "bundleName1";
}
Notification.getSlotNumByBundle(bundle, getSlotNumByBundleCallback);
```



## Notification.getSlotNumByBundle(bundle: BundleOption)

- Functionality

  Obtains the number of notification slots of a specified bundle. This method uses a promise to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| ------ | -------- | ------------ | ---- | ---------- |
| bundle | Read-only| BundleOption | Yes| Bundle information.|

- Return value

  Promise\<number\>

- Example

```js
var bundle = {
    bundle: "bundleName1";
}
Notification.getSlotNumByBundle(bundle).then((data) => {
	console.info("==========================>getSlotNumByBundleCallback=======================>");
});
```



## Notification.remove(bundle: BundleOption, notificationKey: NotificationKey, callback: AsyncCallback\<void\>)

- Functionality

  Removes a notification for a specified bundle. This method uses a callback to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| --------------- | -------- | --------------------- | ---- | -------------------- |
| bundle          | Read-only| BundleOption          | Yes| Bundle information.|
| notificationKey | Read-only| NotificationKey       | Yes| Notification key.|
| callback        | Read-only| AsyncCallback\<void\> | Yes| Callback used to return the result.|

- NotificationKey

| Name| Readable/Writable| Type| Mandatory| Description|
| ----- | -------- | ------ | ---- | -------- |
| id    | Readable and writable| number | Yes| Notification ID.|
| label | Readable and writable| string | No| Notification label.|

- Return value

  void

- Example

```js
function removeCallback(err) {
	console.info("==========================>removeCallback=======================>");
}
var bundle = {
    bundle: "bundleName1";
}
var notificationKey = {
    id: 0;
    label: "label";
}
Notification.remove(bundle, notificationKey, removeCallback);
```



## Notification.remove(bundle: BundleOption, notificationKey: NotificationKey)

- Functionality

  Removes a notification for a specified bundle. This method uses a promise to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| --------------- | -------- | --------------- | ---- | ---------- |
| bundle          | Read-only| BundleOption    | Yes| Bundle information.|
| notificationKey | Read-only| NotificationKey | Yes| Notification key.|

- Return value

  Promise\<void\>

- Example

```js
var bundle = {
    bundle: "bundleName1";
}
var notificationKey = {
    id: 0;
    label: "label";
}
Notification.remove(bundle, notificationKey).then((void) => {
	console.info("==========================>removeCallback=======================>");
});
```



## Notification.remove(hashCode: string, callback: AsyncCallback\<void\>)

- Functionality

  Removes a notification. This method uses a callback to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | --------------------- | ---- | -------------------- |
| hashCode | Read-only| string                | Yes| Unique notification ID.|
| callback | Read-only| AsyncCallback\<void\> | Yes| Callback used to return the result.|

- Return value

  void

- Example

```js
function removeCallback(err) {
	console.info("==========================>removeCallback=======================>");
}

Notification.remove(hashCode, removeCallback);
```



## Notification.remove(hashCode: string)

- Functionality

  Removes a notification. This method uses a promise to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | ---------- | ---- | ---------- |
| hashCode | Read-only| string | Yes| Unique notification ID.|

- Return value

  Promise\<void\>

- Example

```js
Notification.remove(hashCode).then((void) => {
	console.info("==========================>removeCallback=======================>");
});
```



## Notification.removeAll(bundle: BundleOption, callback: AsyncCallback\<void\>)

- Functionality

  Removes all notifications for a specified bundle. This method uses a callback to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | --------------------- | ---- | ---------------------------- |
| bundle   | Read-only| BundleOption          | Yes| Bundle information.|
| callback | Read-only| AsyncCallback\<void\> | Yes| Callback used to return the result.|

- Return value

  void

- Example

```js
function removeAllCallback(err) {
	console.info("==========================>removeAllCallback=======================>");
}
var bundle = {
    bundle: "bundleName1";
}
Notification.removeAll(bundle, removeAllCallback);
```



## Notification.removeAll(callback: AsyncCallback\<void\>)

- Functionality

  Removes all notifications. This method uses a callback to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | --------------------- | ---- | -------------------- |
| callback | Read-only| AsyncCallback\<void\> | Yes| Callback used to return the result.|

- Return value

  void

- Example

```js
function removeAllCallback(err) {
	console.info("==========================>removeAllCallback=======================>");
}

Notification.removeAll(removeAllCallback);
```



## Notification.removeAll(bundle?: BundleOption)

- Functionality

  Removes all notifications for a specified bundle. This method uses a promise to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| ------ | -------- | ------------ | ---- | ---------- |
| bundle | Read-only| BundleOption | No| Bundle information.|

- Return value

  Promise\<void\>

- Example

```js
Notification.removeAll().then((void) => {
	console.info("==========================>removeAllCallback=======================>");
});
```



## Notification.getAllActiveNotifications(callback: AsyncCallback<Array\<NotificationRequest\>>)

- Functionality

  Obtains all active notifications. This method uses a callback to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | ------------------------------------------- | ---- | -------------------- |
| callback | Read-only| AsyncCallback<Array\<NotificationRequest\>> | Yes| Callback used to return the result.|

- Return value

  void

- Example

```js
function getAllActiveNotificationsCallback(err, data) {
	console.info("==========================>getAllActiveNotificationsCallback=======================>");
}

Notification.getAllActiveNotifications(getAllActiveNotificationsCallback);
```



## Notification.getAllActiveNotifications()

- Functionality

  Obtains all active notifications. This method uses a promise to return the result.

- Parameters

  None

- Return value

  Promise\<Array\<NotificationRequest\>\>

- Example

```js
Notification.getAllActiveNotifications().then((data) => {
	console.info("==========================>getAllActiveNotificationsCallback=======================>");
});
```



## Notification.getActiveNotificationCount(callback: AsyncCallback\<number\>)

- Functionality

  Obtains the number of active notifications. This method uses a callback to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | ---------------------- | ---- | ---------------------- |
| callback | Read-only| AsyncCallback\<number\> | Yes| Callback used to return the result.|

- Return value

  void

- Example

```js
function getActiveNotificationCountCallback(err, data) {
	console.info("==========================>getActiveNotificationCountCallback=======================>");
}

Notification.getActiveNotificationCount(getActiveNotificationCountCallback);
```



## Notification.getActiveNotificationCount()

- Functionality

  Obtains the number of active notifications. This method uses a promise to return the result.

- Parameters

  None

- Return value

  Promise\<number>

- Example

```js
Notification.getActiveNotificationCount().then((data) => {
	console.info("==========================>getActiveNotificationCountCallback=======================>");
});
```



## Notification.getActiveNotifications(callback: AsyncCallback<Array\<NotificationRequest\>>)

- Functionality

  Obtains active notifications of the current application. This method uses a callback to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | ------------------------------------------- | ---- | ------------------------------ |
| callback | Read-only| AsyncCallback<Array\<NotificationRequest\>> | Yes| Callback used to return the result.|

- Return value

  void

- Example

```js
function getActiveNotificationsCallback(err, data) {
	console.info("==========================>getActiveNotificationsCallback=======================>");
}

Notification.getActiveNotifications(getActiveNotificationsCallback);
```



## Notification.getActiveNotifications()

- Functionality

  Obtains active notifications. This method uses a promise to return the result.

- Parameters

  None

- Return value

  Promise\<Array\<NotificationRequest\>\>

- Example

```js
Notification.getActiveNotifications().then((data) => {
	console.info("==========================>getActiveNotificationsCallback=======================>");
});
```



## Notification.cancelGroup(groupName: string, callback: AsyncCallback\<void\>)

- Functionality

  Cancels a notification group of the current application. This method uses a callback to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| --------- | -------- | --------------------- | ---- | ---------------------------- |
| groupName | Read-only| string                | Yes| Name of the notification group to cancel.|
| callback  | Read-only| AsyncCallback\<void\> | Yes| Callback used to return the result.|

- Return value

  void

- Example

```js
function cancelGroupCallback(err) {
   console.info("==========================>cancelGroupCallback=======================>");
}

var groupName = "GroupName";

Notification.cancelGroup(groupName, cancelGroupCallback);
```



## Notification.cancelGroup(groupName: string)

- Functionality

  Cancels a notification group of the current application. This method uses a promise to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| --------- | -------- | ------ | ---- | -------------- |
| groupName | Read-only| string | Yes| Name of the notification group to cancel.|

- Return value

  Promise\<void\>

- Example

```js
var groupName = "GroupName";
Notification.cancelGroup(groupName).then(() => {
	console.info("==========================>cancelGroupPromise=======================>");
});
```



## Notification.removeGroupByBundle(bundle: BundleOption, groupName: string, callback: AsyncCallback\<void\>)

- Functionality

  Removes a notification group for a specified bundle. This method uses a callback to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| --------- | -------- | --------------------- | ---- | ---------------------------- |
| bundle    | Read-only| BundleOption          | Yes| Bundle information.|
| groupName | Read-only| string                | Yes| Name of the notification group to remove.|
| callback  | Read-only| AsyncCallback\<void\> | Yes| Callback used to return the result.|

- Return value

  void

- Example

```js
function removeGroupByBundleCallback(err) {
   console.info("==========================>removeGroupByBundleCallback=======================>");
}

var bundleOption = {bundle: "Bundle"};
var groupName = "GroupName";

Notification.removeGroupByBundle(bundleOption, groupName, removeGroupByBundleCallback);
```



## Notification.removeGroupByBundle(bundle: BundleOption, groupName: string)

- Functionality

  Removes a notification group for a specified bundle. This method uses a promise to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| --------- | -------- | ------------ | ---- | -------------- |
| bundle    | Read-only| BundleOption | Yes| Bundle information.|
| groupName | Read-only| string       | Yes| Name of the notification group to remove.|

- Return value

  Promise\<void\>

- Example

```js
var bundleOption = {bundle: "Bundle"};
var groupName = "GroupName";
Notification.removeGroupByBundle(bundleOption, groupName).then(() => {
	console.info("==========================>removeGroupByBundlePromise=======================>");
});
```



## Notification.setDoNotDisturbDate(date: DoNotDisturbDate, callback: AsyncCallback\<void\>)

- Functionality

  Sets the DND time. This method uses a callback to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | --------------------- | ---- | ---------------------- |
| date     | Read-only| DoNotDisturbDate      | Yes| DND time to set.|
| callback | Read-only| AsyncCallback\<void\> | Yes| Callback used to return the result.|

- Return value

  void

- Example

```js
function setDoNotDisturbDateCallback(err) {
   console.info("==========================>setDoNotDisturbDateCallback=======================>");
}

var doNotDisturbDate = {
    type: notification.DoNotDisturbType.TYPE_ONCE,
    begin: new Date(),
    end: new Date(2021, 11, 15, 18, 0)
}

Notification.setDoNotDisturbDate(doNotDisturbDate, setDoNotDisturbDateCallback);
```



## Notification.setDoNotDisturbDate(date: DoNotDisturbDate)

- Functionality

  Sets the DND time. This method uses a promise to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| ---- | -------- | ---------------- | ---- | -------------- |
| date | Read-only| DoNotDisturbDate | Yes| DND time to set.|

- Return value

  Promise\<void\>

- Example

```js
var doNotDisturbDate = {
    type: notification.DoNotDisturbType.TYPE_ONCE,
    begin: new Date(),
    end: new Date(2021, 11, 15, 18, 0)
}
Notification.setDoNotDisturbDate(doNotDisturbDate).then(() => {
	console.info("==========================>setDoNotDisturbDatePromise=======================>");
});
```



## Notification.getDoNotDisturbDate(callback: AsyncCallback\<DoNotDisturbDate\>)

- Functionality

  Obtains the DND time. This method uses a callback to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | --------------------------------- | ---- | ---------------------- |
| callback | Read-only| AsyncCallback\<DoNotDisturbDate\> | Yes| Callback used to return the result.|

- Return value

  void

- Example

```js
function getDoNotDisturbDateCallback(err,data) {
   console.info("==========================>getDoNotDisturbDateCallback=======================>");
}

Notification.getDoNotDisturbDate(getDoNotDisturbDateCallback);
```



## Notification.getDoNotDisturbDate()

- Functionality

  Obtains the DND time. This method uses a promise to return the result.

- Parameters

  None

- Return value

  Promise\<DoNotDisturbDate\>

- Example

```js
Notification.getDoNotDisturbDate().then((data) => {
	console.info("==========================>getDoNotDisturbDatePromise=======================>");
});
```



## Notification.supportDoNotDisturbMode(callback: AsyncCallback\<boolean\>)

- Functionality

  Checks whether the DND mode is supported. This method uses a callback to return the result.

- Parameters

| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | ------------------------ | ---- | -------------------------------- |
| callback | Read-only| AsyncCallback\<boolean\> | Yes| Callback used to return the result.|

- Return value

  void

- Example

```js
function supportDoNotDisturbModeCallback(err,data) {
   console.info("==========================>supportDoNotDisturbModeCallback=======================>");
}

Notification.supportDoNotDisturbMode(supportDoNotDisturbModeCallback);
```



## Notification.supportDoNotDisturbMode()

- Functionality

  Checks whether the DND mode is supported. This method uses a promise to return the result.

- Parameters

  None

- Return value

  Promise\<boolean\>

- Example

```js
Notification.supportDoNotDisturbMode().then((data) => {
	console.info("==========================>supportDoNotDisturbModePromise=======================>");
});
```



## Notification.isSupportTemplate

isSupportTemplate(templateName: string, callback: AsyncCallback\<boolean\>): void

Checks whether a specified template exists. This method uses a callback to return the result.

- Parameters

| Name| Type| Mandatory| Description|
| ------------ | ------------------------ | ---- | -------------------------- |
| templateName | string                   | Yes| Template name.|
| callback     | AsyncCallback\<boolean\> | Yes| Callback used to return the result.|

- Example

```javascript
var templateName = 'process';
function isSupportTemplateCallback(err, data) {
    console.info("isSupportTemplateCallback");
}

Notification.isSupportTemplate(templateName, isSupportTemplateCallback);
```



## Notification.isSupportTemplate

isSupportTemplate(templateName: string): Promise\<boolean\>

Checks whether a specified template exists. This method uses a promise to return the result.

- Parameters

| Name| Type| Mandatory| Description|
| ------------ | ------ | ---- | -------- |
| templateName | string | Yes| Name|

- Return value

| Type| Description|
| ------------------ | --------------- |
| Promise\<boolean\> | Promise used to return the result.|

- Example

```javascript
var templateName = 'process';

Notification.isSupportTemplate(templateName).then((data) => {
    console.info("isSupportTemplateCallback");
});
```



## NotificationTemplate

Describes the template information.

| Name| Type| Readable| Writable| Description|
| ---- | ---------------------- | ---- | ---- | -------- |
| name | string                 | Yes| Yes| Template name.|
| data | {[key:string]: Object} | Yes| Yes| Template data.|



## WantAgent APIs

## Modules to Import

```js
import WantAgent from '@ohos.wantAgent';
```

## WantAgent.getWantAgent(info: WantAgentInfo, callback: AsyncCallback\<WantAgent\>)

- Functionality

  Obtains a **WantAgent** object. This method uses a callback to return the result.

- Parameters


| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | -------------------------- | ---- | ----------------------- |
| info     | Read-only| WantAgentInfo              | Yes| Information about the **WantAgent** object to obtain.|
| callback | Read-only| AsyncCallback\<WantAgent\> | Yes| Callback used to return the result.|

- WantAgentInfo

| Name| Readable/Writable| Type| Mandatory| Description|
| -------------- | -------- | ------------------------------- | ---- | ---------------------- |
| wants          | Readable and writable| Array\<Want\>                   | Yes| Array of all **Want** objects.|
| operationType  | Readable and writable| wantAgent.OperationType         | Yes| Type of the operation specified in a **Want** object.|
| requestCode    | Readable and writable| number                          | Yes| Request code defined by the user.|
| wantAgentFlags | Readable and writable| Array<wantAgent.WantAgentFlags> | No| Array of flags for using the **WantAgent** object.|
| extraInfo      | Readable and writable| {[key: string]: any}            | No| Extra information.|

- 
  WantAgentFlags


| Name| Readable/Writable| Type| Mandatory| Description|
| ------------------- | -------- | ---- | ---- | ------------------------------------------------------------ |
| ONE_TIME_FLAG       | Read-only| enum | No| The **WantAgent** object can be used only once.|
| NO_BUILD_FLAG       | Read-only| enum | No| The **WantAgent** object does not exist and hence it is not created. In this case, **null** is returned.|
| CANCEL_PRESENT_FLAG | Read-only| enum | No| The existing **WantAgent** object should be canceled before a new object is generated.|
| UPDATE_PRESENT_FLAG | Read-only| enum | No| Extra data of the existing **WantAgent** object is replaced with that of the new object.|
| CONSTANT_FLAG       | Read-only| enum | No| The **WantAgent** object is immutable.|

- OperationType

| Name| Readable/Writable| Type| Mandatory| Description|
| ----------------- | -------- | ---- | ---- | ----------------------- |
| UNKNOWN_TYPE      | Read-only| enum | No| Unknown operation.|
| START_ABILITY     | Read-only| enum | No| Starts an ability with a UI.|
| START_ABILITIES   | Read-only| enum | No| Starts multiple abilities with a UI.|
| START_SERVICE     | Read-only| enum | No| Starts an ability without a UI.|
| SEND_COMMON_EVENT | Read-only| enum | No| Sends a common event.|

- Return value

  void

- Example

```js
import WantAgent from '@ohos.wantAgent';
import { OperationType, WantAgentFlags } from '@ohos.wantagent';

// getWantAgent callback
function getWantAgentCallback(err, data) {
	console.info("==========================>getWantAgentCallback=======================>");
}
// WantAgentInfo object
var wantAgentInfo = {
    wants: [
        {
            deviceId: "deviceId",
            bundleName: "com.neu.setResultOnAbilityResultTest1",
            abilityName: "com.example.test.MainAbility",
            action: "action1",
            entities: ["entity1"],
            type: "MIMETYPE",
            uri: "key={true,true,false}",
            parameters:
            {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: "[1, 2, 3]",
                mykey3: "ssssssssssssssssssssssssss",
                mykey4: [false, true, false],
                mykey5: ["qqqqq", "wwwwww", "aaaaaaaaaaaaaaaaa"],
                mykey6: true,
            }
        }
    ],
    operationType: OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgentFlags.UPDATE_PRESENT_FLAG]
}

WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback)
```



## WantAgent.getWantAgent(info: WantAgentInfo): Promise\<WantAgent\>

- Functionality

  Obtains a **WantAgent** object. This method uses a promise to return the result.

- Parameters


| Name| Readable/Writable| Type| Mandatory| Description|
| ---- | -------- | ------------- | ---- | ------------- |
| info | Read-only| WantAgentInfo | Yes| Information about the **WantAgent** object to obtain.|

- Return value

  Promise\<WantAgent\>

- Example

```js
import WantAgent from '@ohos.wantAgent';
import { OperationType, WantAgentFlags } from '@ohos.wantagent';

// WantAgentInfo object
var wantAgentInfo = {
    wants: [
        {
            deviceId: "deviceId",
            bundleName: "com.neu.setResultOnAbilityResultTest1",
            abilityName: "com.example.test.MainAbility",
            action: "action1",
            entities: ["entity1"],
            type: "MIMETYPE",
            uri: "key={true,true,false}",
            parameters:
            {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: "[1, 2, 3]",
                mykey3: "ssssssssssssssssssssssssss",
                mykey4: [false, true, false],
                mykey5: ["qqqqq", "wwwwww", "aaaaaaaaaaaaaaaaa"],
                mykey6: true,
            }
        }
    ],
    operationType: OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgentFlags.UPDATE_PRESENT_FLAG]
}

WantAgent.getWantAgent(wantAgentInfo).then((data) => {
	console.info("==========================>getWantAgentCallback=======================>");
});
```



## WantAgent.getBundleName(agent: WantAgent, callback: AsyncCallback\<string\>)

- Functionality

  Obtains the bundle name of a **WantAgent** object. This method uses a callback to return the result.

- Parameters


| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | ----------------------- | ---- | --------------------------------- |
| agent    | Read-only| WantAgent               | Yes| **WantAgent** object whose bundle name is to be obtained.|
| callback | Read-only| AsyncCallback\<string\> | Yes| Callback used to return the result.|

- Return value

  void

- Example

```js
import WantAgent from '@ohos.wantAgent';
import { OperationType, WantAgentFlags } from '@ohos.wantagent';

// WantAgent object
var wantAgent;

// getWantAgent callback
function getWantAgentCallback(err, data) {
	console.info("==========================>getWantAgentCallback=======================>");
    if (err.code == 0) {
    	wantAgent = data;
    } else {
        console.info('----getWantAgent failed!----');
    }
}
// WantAgentInfo object
var wantAgentInfo = {
    wants: [
        {
            deviceId: "deviceId",
            bundleName: "com.neu.setResultOnAbilityResultTest1",
            abilityName: "com.example.test.MainAbility",
            action: "action1",
            entities: ["entity1"],
            type: "MIMETYPE",
            uri: "key={true,true,false}",
            parameters:
            {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: "[1, 2, 3]",
                mykey3: "ssssssssssssssssssssssssss",
                mykey4: [false, true, false],
                mykey5: ["qqqqq", "wwwwww", "aaaaaaaaaaaaaaaaa"],
                mykey6: true,
            }
        }
    ],
    operationType: OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgentFlags.UPDATE_PRESENT_FLAG]
}

WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback)

// getBundleName callback
function getBundleNameCallback(err, data) {
	console.info("==========================>getBundleNameCallback=======================>");
}
WantAgent.getBundleName(wantAgent, getBundleNameCallback)
```



## WantAgent.getBundleName(agent: WantAgent): Promise\<string\>

- Functionality

  Obtains the bundle name of a **WantAgent** object. This method uses a promise to return the result.

- Parameters


| Name| Readable/Writable| Type| Mandatory| Description|
| ----- | -------- | --------- | ---- | ------------- |
| agent | Read-only| WantAgent | Yes| **WantAgent** object whose bundle name is to be obtained.|

- Return value

  Promise\<string\>

- Example

```js
import WantAgent from '@ohos.wantAgent';
import { OperationType, WantAgentFlags } from '@ohos.wantagent';

// WantAgent object
var wantAgent;

// WantAgentInfo object
var wantAgentInfo = {
    wants: [
        {
            deviceId: "deviceId",
            bundleName: "com.neu.setResultOnAbilityResultTest1",
            abilityName: "com.example.test.MainAbility",
            action: "action1",
            entities: ["entity1"],
            type: "MIMETYPE",
            uri: "key={true,true,false}",
            parameters:
            {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: "[1, 2, 3]",
                mykey3: "ssssssssssssssssssssssssss",
                mykey4: [false, true, false],
                mykey5: ["qqqqq", "wwwwww", "aaaaaaaaaaaaaaaaa"],
                mykey6: true,
            }
        }
    ],
    operationType: OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgentFlags.UPDATE_PRESENT_FLAG]
}

WantAgent.getWantAgent(wantAgentInfo).then((data) => {
	console.info("==========================>getWantAgentCallback=======================>");
    wantAgent = data;
});

WantAgent.getBundleName(wantAgent).then((data) => {
	console.info("==========================>getBundleNameCallback=======================>");
});
```



## WantAgent.getUid(agent: WantAgent, callback: AsyncCallback\<number\>)

- Functionality

  Obtains the user ID of a **WantAgent** object. This method uses a callback to return the result.

- Parameters


| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | ----------------------- | ---- | ----------------------------------- |
| agent    | Read-only| WantAgent               | Yes| **WantAgent** object whose user ID is to be obtained.|
| callback | Read-only| AsyncCallback\<number\> | Yes| Callback used to return the result.|

- Return value

  void

- Example

```js
import WantAgent from '@ohos.wantAgent';
import { OperationType, WantAgentFlags } from '@ohos.wantagent';

// WantAgent object
var wantAgent;

// getWantAgent callback
function getWantAgentCallback(err, data) {
	console.info("==========================>getWantAgentCallback=======================>");
    if (err.code == 0) {
    	wantAgent = data;
    } else {
        console.info('----getWantAgent failed!----');
    }
}
// WantAgentInfo object
var wantAgentInfo = {
    wants: [
        {
            deviceId: "deviceId",
            bundleName: "com.neu.setResultOnAbilityResultTest1",
            abilityName: "com.example.test.MainAbility",
            action: "action1",
            entities: ["entity1"],
            type: "MIMETYPE",
            uri: "key={true,true,false}",
            parameters:
            {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: "[1, 2, 3]",
                mykey3: "ssssssssssssssssssssssssss",
                mykey4: [false, true, false],
                mykey5: ["qqqqq", "wwwwww", "aaaaaaaaaaaaaaaaa"],
                mykey6: true,
            }
        }
    ],
    operationType: OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgentFlags.UPDATE_PRESENT_FLAG]
}

WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback)

// getUid callback
function getUidCallback(err, data) {
	console.info("==========================>getUidCallback=======================>");
}
WantAgent.getUid(wantAgent, getUidCallback)
```



## WantAgent.getUid(agent: WantAgent): Promise\<number\>

- Functionality

  Obtains the user ID of a **WantAgent** object. This method uses a promise to return the result.

- Parameters


| Name| Readable/Writable| Type| Mandatory| Description|
| ----- | -------- | --------- | ---- | ------------- |
| agent | Read-only| WantAgent | Yes| **WantAgent** object whose user ID is to be obtained.|

- Return value

  Promise\<number\>

- Example

```js
import WantAgent from '@ohos.wantAgent';
import { OperationType, WantAgentFlags } from '@ohos.wantagent';

// WantAgent object
var wantAgent;

// WantAgentInfo object
var wantAgentInfo = {
    wants: [
        {
            deviceId: "deviceId",
            bundleName: "com.neu.setResultOnAbilityResultTest1",
            abilityName: "com.example.test.MainAbility",
            action: "action1",
            entities: ["entity1"],
            type: "MIMETYPE",
            uri: "key={true,true,false}",
            parameters:
            {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: "[1, 2, 3]",
                mykey3: "ssssssssssssssssssssssssss",
                mykey4: [false, true, false],
                mykey5: ["qqqqq", "wwwwww", "aaaaaaaaaaaaaaaaa"],
                mykey6: true,
            }
        }
    ],
    operationType: OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgentFlags.UPDATE_PRESENT_FLAG]
}

WantAgent.getWantAgent(wantAgentInfo).then((data) => {
	console.info("==========================>getWantAgentCallback=======================>");
    wantAgent = data;
});

WantAgent.getUid(wantAgent).then((data) => {
	console.info("==========================>getUidCallback=======================>");
});
```



## WantAgent.getWant(agent: WantAgent, callback: AsyncCallback\<Want\>)

- Functionality

  Obtains the want in a **WantAgent** object. This method uses a callback to return the result.

- Parameters


| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | --------------------- | ---- | ------------------------------- |
| agent    | Read-only| WantAgent             | Yes| **WantAgent** object.|
| callback | Read-only| AsyncCallback\<Want\> | Yes| Callback used to return the result.|

- Return value

  void

- Example

```js
import WantAgent from '@ohos.wantAgent';
import { OperationType, WantAgentFlags } from '@ohos.wantagent';

// WantAgent object
var wantAgent;

// getWantAgent callback
function getWantAgentCallback(err, data) {
	console.info("==========================>getWantAgentCallback=======================>");
    if (err.code == 0) {
    	wantAgent = data;
    } else {
        console.info('----getWantAgent failed!----');
    }
}
// WantAgentInfo object
var wantAgentInfo = {
    wants: [
        {
            deviceId: "deviceId",
            bundleName: "com.neu.setResultOnAbilityResultTest1",
            abilityName: "com.example.test.MainAbility",
            action: "action1",
            entities: ["entity1"],
            type: "MIMETYPE",
            uri: "key={true,true,false}",
            parameters:
            {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: "[1, 2, 3]",
                mykey3: "ssssssssssssssssssssssssss",
                mykey4: [false, true, false],
                mykey5: ["qqqqq", "wwwwww", "aaaaaaaaaaaaaaaaa"],
                mykey6: true,
            }
        }
    ],
    operationType: OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgentWantAgentFlags.UPDATE_PRESENT_FLAG]
}

WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback)

// getWant callback
function getWantCallback(err, data) {
	console.info("==========================>getWantCallback=======================>");
}
WantAgent.getWant(wantAgent, getWantCallback)
```



## WantAgent.getWant(agent: WantAgent): Promise\<Want\>

- Functionality

  Obtains the want in a **WantAgent** object. This method uses a promise to return the result.

- Parameters


| Name| Readable/Writable| Type| Mandatory| Description|
| ----- | -------- | --------- | ---- | ------------- |
| agent | Read-only| WantAgent | Yes| **WantAgent** object.|

- Return value

  Promise\<Want\>

- Example

```js
import WantAgent from '@ohos.wantAgent';
import { OperationType, WantAgentFlags } from '@ohos.wantagent';

// WantAgent object
var wantAgent;

// WantAgentInfo object
var wantAgentInfo = {
    wants: [
        {
            deviceId: "deviceId",
            bundleName: "com.neu.setResultOnAbilityResultTest1",
            abilityName: "com.example.test.MainAbility",
            action: "action1",
            entities: ["entity1"],
            type: "MIMETYPE",
            uri: "key={true,true,false}",
            parameters:
            {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: "[1, 2, 3]",
                mykey3: "ssssssssssssssssssssssssss",
                mykey4: [false, true, false],
                mykey5: ["qqqqq", "wwwwww", "aaaaaaaaaaaaaaaaa"],
                mykey6: true,
            }
        }
    ],
    operationType: OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgentFlags.UPDATE_PRESENT_FLAG]
}

WantAgent.getWantAgent(wantAgentInfo).then((data) => {
	console.info("==========================>getWantAgentCallback=======================>");
    wantAgent = data;
});

WantAgent.getWant(wantAgent).then((data) => {
	console.info("==========================>getWantCallback=======================>");
});
```



## WantAgent.cancel(agent: WantAgent, callback: AsyncCallback\<void\>)

- Functionality

  Cancels a **WantAgent** object. This method uses a callback to return the result.

- Parameters


| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | --------------------- | ---- | --------------------------- |
| agent    | Read-only| WantAgent             | Yes| **WantAgent** object to cancel.|
| callback | Read-only| AsyncCallback\<void\> | Yes| Callback used to return the result.|

- Return value

  void

- Example

```js
import WantAgent from '@ohos.wantAgent';
import { OperationType, WantAgentFlags } from '@ohos.wantagent';

// WantAgent object
var wantAgent;

// getWantAgent callback
function getWantAgentCallback(err, data) {
	console.info("==========================>getWantAgentCallback=======================>");
    if (err.code == 0) {
    	wantAgent = data;
    } else {
        console.info('----getWantAgent failed!----');
    }
}
// WantAgentInfo object
var wantAgentInfo = {
    wants: [
        {
            deviceId: "deviceId",
            bundleName: "com.neu.setResultOnAbilityResultTest1",
            abilityName: "com.example.test.MainAbility",
            action: "action1",
            entities: ["entity1"],
            type: "MIMETYPE",
            uri: "key={true,true,false}",
            parameters:
            {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: "[1, 2, 3]",
                mykey3: "ssssssssssssssssssssssssss",
                mykey4: [false, true, false],
                mykey5: ["qqqqq", "wwwwww", "aaaaaaaaaaaaaaaaa"],
                mykey6: true,
            }
        }
    ],
    operationType: OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgentFlags.UPDATE_PRESENT_FLAG]
}

WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback)

// cancel callback
function cancelCallback(err, data) {
	console.info("==========================>cancelCallback=======================>");
}
WantAgent.cancel(wantAgent, cancelCallback)
```



## WantAgent.cancel(agent: WantAgent): Promise\<void\>

- Functionality

  Cancels a **WantAgent** object. This method uses a promise to return the result.

- Parameters


| Name| Readable/Writable| Type| Mandatory| Description|
| ----- | -------- | --------- | ---- | ------------- |
| agent | Read-only| WantAgent | Yes| **WantAgent** object to cancel.|

- Return value

  Promise\<void\>

- Example

```js
import WantAgent from '@ohos.wantAgent';
import { OperationType, WantAgentFlags } from '@ohos.wantagent';

// WantAgent object
var wantAgent;

// WantAgentInfo object
var wantAgentInfo = {
    wants: [
        {
            deviceId: "deviceId",
            bundleName: "com.neu.setResultOnAbilityResultTest1",
            abilityName: "com.example.test.MainAbility",
            action: "action1",
            entities: ["entity1"],
            type: "MIMETYPE",
            uri: "key={true,true,false}",
            parameters:
            {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: "[1, 2, 3]",
                mykey3: "ssssssssssssssssssssssssss",
                mykey4: [false, true, false],
                mykey5: ["qqqqq", "wwwwww", "aaaaaaaaaaaaaaaaa"],
                mykey6: true,
            }
        }
    ],
    operationType: OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgentFlags.UPDATE_PRESENT_FLAG]
}

WantAgent.getWantAgent(wantAgentInfo).then((data) => {
	console.info("==========================>getWantAgentCallback=======================>");
    wantAgent = data;
});

WantAgent.cancel(wantAgent).then((data) => {
	console.info("==========================>cancelCallback=======================>");
});
```



## WantAgent.trigger(agent: WantAgent, triggerInfo: TriggerInfo, callback?: Callback\<CompleteData\>)

- Functionality

  Triggers a **WantAgent** object. This method uses a callback to return the result.

- Parameters


| Name| Readable/Writable| Type| Mandatory| Description|
| ----------- | -------- | ----------------------------- | ---- | ------------------------------- |
| agent       | Read-only| WantAgent                     | Yes| **WantAgent** object to trigger.|
| triggerInfo | Read-only| TriggerInfo                   | Yes| **TriggerInfo** object.|
| callback    | Read-only| AsyncCallback\<CompleteData\> | Yes| Callback used to return the result.|

- TriggerInfo

| Name| Readable/Writable| Type| Mandatory| Description|
| ---------- | -------- | -------------------- | ---- | ----------- |
| code       | Readable and writable| number               | Yes| Result code.|
| want       | Readable and writable| Want                 | No| Want.|
| permission | Readable and writable| string               | No| Permission.|
| extraInfo  | Readable and writable| {[key: string]: any} | No| Extra information.|

- Return value

  void

- Example

```js
import WantAgent from '@ohos.wantAgent';
import { OperationType, WantAgentFlags } from '@ohos.wantagent';

// WantAgent object
var wantAgent;

// getWantAgent callback
function getWantAgentCallback(err, data) {
	console.info("==========================>getWantAgentCallback=======================>");
    if (err.code == 0) {
    	wantAgent = data;
    } else {
        console.info('----getWantAgent failed!----');
    }
}
// WantAgentInfo object
var wantAgentInfo = {
    wants: [
        {
            deviceId: "deviceId",
            bundleName: "com.neu.setResultOnAbilityResultTest1",
            abilityName: "com.example.test.MainAbility",
            action: "action1",
            entities: ["entity1"],
            type: "MIMETYPE",
            uri: "key={true,true,false}",
            parameters:
            {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: "[1, 2, 3]",
                mykey3: "ssssssssssssssssssssssssss",
                mykey4: [false, true, false],
                mykey5: ["qqqqq", "wwwwww", "aaaaaaaaaaaaaaaaa"],
                mykey6: true,
            }
        }
    ],
    operationType: OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgentFlags.UPDATE_PRESENT_FLAG]
}

WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback)

//Trigger callback
function triggerCallback(err, data) {
	console.info("==========================>triggerCallback=======================>");
}

var triggerInfo = {
    code:0
}
WantAgent.trigger(wantAgent, triggerInfo, triggerCallback)
```



## WantAgent.equal(agent: WantAgent, otherAgent: WantAgent, callback: AsyncCallback\<boolean\>)

- Functionality

  Checks whether two **WantAgent** objects are equal. This method uses a callback to return the result.

- Parameters


| Name| Readable/Writable| Type| Mandatory| Description|
| ---------- | -------- | ------------------------ | ---- | --------------------------------------- |
| agent      | Read-only| WantAgent                | Yes| The first **WantAgent** object.|
| otherAgent | Read-only| WantAgent                | Yes| The second **WantAgent** object.|
| callback   | Read-only| AsyncCallback\<boolean\> | Yes| Callback used to return the result.|

- Return value

  void

- Example

```js
import WantAgent from '@ohos.wantAgent';
import { OperationType, WantAgentFlags } from '@ohos.wantagent';

// WantAgent object
var wantAgent1;
var wantAgent2;

// getWantAgent callback
function getWantAgentCallback(err, data) {
	console.info("==========================>getWantAgentCallback=======================>");
    if (err.code == 0) {
    	wantAgent1 = data;
        wantAgent2 = data;
    } else {
        console.info('----getWantAgent failed!----');
    }
}
// WantAgentInfo object
var wantAgentInfo = {
    wants: [
        {
            deviceId: "deviceId",
            bundleName: "com.neu.setResultOnAbilityResultTest1",
            abilityName: "com.example.test.MainAbility",
            action: "action1",
            entities: ["entity1"],
            type: "MIMETYPE",
            uri: "key={true,true,false}",
            parameters:
            {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: "[1, 2, 3]",
                mykey3: "ssssssssssssssssssssssssss",
                mykey4: [false, true, false],
                mykey5: ["qqqqq", "wwwwww", "aaaaaaaaaaaaaaaaa"],
                mykey6: true,
            }
        }
    ],
    operationType: OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgentFlags.UPDATE_PRESENT_FLAG]
}

WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback)

// equal callback
function equalCallback(err, data) {
	console.info("==========================>equalCallback=======================>");
}
WantAgent.equal(wantAgent1, wantAgent2, equalCallback)
```



## WantAgent.equal(agent: WantAgent, otherAgent: WantAgent): Promise\<boolean\>

- Functionality

  Checks whether two **WantAgent** objects are equal. This method uses a promise to return the result.

- Parameters


| Name| Readable/Writable| Type| Mandatory| Description|
| ---------- | -------- | --------- | ---- | ------------- |
| agent      | Read-only| WantAgent | Yes| The first **WantAgent** object.|
| otherAgent | Read-only| WantAgent | Yes| The second **WantAgent** object.|

- Return value

  Promise\<boolean\>

- Example

```js
import WantAgent from '@ohos.wantAgent';
import { OperationType, WantAgentFlags } from '@ohos.wantagent';

// WantAgent object
var wantAgent1;
var wantAgent2;

// WantAgentInfo object
var wantAgentInfo = {
    wants: [
        {
            deviceId: "deviceId",
            bundleName: "com.neu.setResultOnAbilityResultTest1",
            abilityName: "com.example.test.MainAbility",
            action: "action1",
            entities: ["entity1"],
            type: "MIMETYPE",
            uri: "key={true,true,false}",
            parameters:
            {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: "[1, 2, 3]",
                mykey3: "ssssssssssssssssssssssssss",
                mykey4: [false, true, false],
                mykey5: ["qqqqq", "wwwwww", "aaaaaaaaaaaaaaaaa"],
                mykey6: true,
            }
        }
    ],
    operationType: OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgentFlags.UPDATE_PRESENT_FLAG]
}

WantAgent.getWantAgent(wantAgentInfo).then((data) => {
	console.info("==========================>getWantAgentCallback=======================>");
    wantAgent1 = data;
    wantAgent2 = data;
});

WantAgent.equal(wantAgent1, wantAgent2).then((data) => {
	console.info("==========================>equalCallback=======================>");
});
```



#### 
