# Background Task Management Development

## When to Use

If a service needs to be continued when the application or service module is running in the background (not visible to users), the application or service module can request a transient task or continuous task for delayed suspension based on the service type.


## Available APIs

```
import backgroundTaskManager from '@ohos.backgroundTaskManager';
```

**Table 1** Main APIs of backgroundTaskManager

| API| Description|
| -------- | -------- |
| function&nbsp;requestSuspendDelay(reason:&nbsp;string,&nbsp;callback:&nbsp;Callback&lt;void&gt;):&nbsp;**DelaySuspendInfo**; | Requests delayed suspension after the application switches to the background. <br/>The default duration of delayed suspension is 180000 when the battery level is higher than or equal to the broadcast low battery level and 60000 when the battery level is lower than the broadcast low battery level.|
| function&nbsp;getRemainingDelayTime(requestId:&nbsp;number,&nbsp;callback:&nbsp;AsyncCallback&lt;number&gt;):&nbsp;void;<br/>function&nbsp;getRemainingDelayTime(requestId:&nbsp;number):&nbsp;Promise&lt;number&gt;; | Obtains the remaining duration before the application is suspended. (The value of **requestId** is obtained from the return value of **requestSuspendDelay**.)<br/>Two asynchronous methods are provided: callback and promise.|
| function&nbsp;cancelSuspendDelay(requestId:&nbsp;number):&nbsp;void; | Cancels the suspension delay. (The value of **requestId** is obtained from the return value of **requestSuspendDelay**.)|

**Table 2** Parameters in DelaySuspendInfo

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| requestId | number | Yes| ID of the suspension delay request.|
| actualDelayTime | number | Yes| Actual suspension delay duration of the application, in milliseconds.|


## How to Develop

1. Request suspension delay.
   ```
   import backgroundTaskManager from '@ohos.backgroundTaskManager';
   let myReason = 'test requestSuspendDelay';
   let delayInfo = backgroundTaskManager.requestSuspendDelay(myReason, () => {
       console.info("Request suspension delay will time out.");
   });
   var id = delayInfo.requestId;console.info("requestId is: " + id);
   ```

2. Obtain the remaining duration before the application is suspended.
   ```
   backgroundTaskManager.getRemainingDelayTime(id).then( res => {
       console.log('promise => Operation succeeded. Data: ' + JSON.stringify(res));
   }).catch( err => {
       console.log('promise => Operation failed. Cause: ' + err.data);
   });
   ```

3. Cancel the suspension delay.
   ```
   backgroundTaskManager.cancelSuspendDelay(id);
   ```


## Development Examples

```
import backgroundTaskManager from '@ohos.backgroundTaskManager';
let myReason = 'test requestSuspendDelay';
// Request suspension delay.
let delayInfo = backgroundTaskManager.requestSuspendDelay(myReason, () => {
    console.info("Request suspension delay will time out.");
});
// Print the suspension delay information.
var id = delayInfo.requestId;
var time = delayInfo.actualDelayTime;
console.info("The requestId is: " + id);
console.info("The actualDelayTime is: " + time);
// Obtain the remaining duration before the application is suspended.
backgroundTaskManager.getRemainingDelayTime(id).then( res => {
    console.log('promise => Operation succeeded. Data: ' + JSON.stringify(res));
}).catch( err => {
    console.log('promise => Operation failed. Cause: ' + err.data);
});
// Cancel the suspension delay.
backgroundTaskManager.cancelSuspendDelay(id);
```
