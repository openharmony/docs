# Background Task Management

> ![icon-note.gif](public_sys-resources/icon-note.gif) **Note:**
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import backgroundTaskManager from '@ohos.backgroundTaskManager';  
```


## Required Permissions

None


## backgroundTaskManager.requestSuspendDelay

requestSuspendDelay(reason: string, callback: Callback&lt;void&gt;): DelaySuspendInfo

Requests delayed suspension after the application switches to the background.

The default duration of delayed suspension is 180000 when the battery level is higher than or equal to the broadcast low battery level and 60000 when the battery level is lower than the broadcast low battery level.

- **Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | reason | string | Yes| Reason for delayed transition to the suspended state.|
  | callback | Callback&lt;void&gt; | Yes| Invoked when a delay is about to time out. Generally, this callback is used to notify the application 6 seconds before the delay times out.|

- **Return value**
  | Type| Description|
  | -------- | -------- |
  | [DelaySuspendInfo](#delaysuspendinfo) | Information about the suspension delay.|

- **Example**
  ```
  let myReason = 'test requestSuspendDelay';
  let delayInfo = backgroundTaskManager.requestSuspendDelay(myReason, () => {
      console.info("Request suspension delay will time out.");
  })
  ```


## backgroundTaskManager.getRemainingDelayTime

getRemainingDelayTime(requestId: number, callback: AsyncCallback&lt;number&gt;): void

Obtains the remaining duration before the application is suspended. This method uses an asynchronous callback to return the result.

- **Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | requestId | number | Yes| ID of the suspension delay request.|
  | callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the remaining duration before the application is suspended, in milliseconds.|

- **Example**
  ```
  let id = 1;
  backgroundTaskManager.getRemainingDelayTime(id, (err, res) => {
      if(err.data === 0) {
          console.log('promise => Operation succeeded. Data: ' + JSON.stringify(res));
      } else {
          console.log('promise => Operation failed. Cause: ' + err.data);
      }
  })
  ```


## backgroundTaskManager.getRemainingDelayTime

getRemainingDelayTime(requestId: number): Promise&lt;number&gt;

Obtains the remaining duration before the application is suspended. This method uses a promise to return the result.

- **Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | requestId | number | Yes| ID of the suspension delay request.|

- **Return value**
  | Type| Description|
  | -------- | -------- |
  | Promise&lt;number&gt; | Promise used to return the remaining duration before the application is suspended, in milliseconds.|

- **Example**
  ```
  let id = 1;
  backgroundTaskManager.getRemainingDelayTime(id).then( res => {
      console.log('promise => Operation succeeded. Data: ' + JSON.stringify(res));
  }).catch( err => {
      console.log('promise => Operation failed. Cause: ' + err.data);
  })
  ```


## backgroundTaskManager.cancelSuspendDelay

cancelSuspendDelay(requestId: number): void

Cancels the suspension delay.

- **Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | requestId | number | Yes| ID of the suspension delay request.|

- **Example**
  ```
  backgroundTaskManager.cancelSuspendDelay(id);
  ```


#### DelaySuspendInfo

Provides the information about the suspension delay.

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| requestId | number | Yes| ID of the suspension delay request.|
| actualDelayTime | number | Yes| Actual suspension delay duration of the application, in milliseconds. <br/>The default duration is 180000 when the battery level is higher than or equal to the broadcast low battery level and 60000 when the battery level is lower than the broadcast low battery level.|
