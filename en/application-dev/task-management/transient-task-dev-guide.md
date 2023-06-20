# Transient Task Development

## When to Use

By default, an application can run for a period of 6 to 12 seconds after it switches to the background. When this period expires, the application is suspended. If an application requires more time to execute an important task, it can call the **requestSuspendDelay** API to request a transient task to delay the suspension.

You are advised not to call the [requestSuspendDelay()](../reference/apis/js-apis-resourceschedule-backgroundTaskManager.md#backgroundtaskmanagerrequestsuspenddelay) method to apply for delayed suspension after the application is running in the background. Instead, you need to call this interface to declare the execution time of the extended application to the system before performing any time-consuming operation. It is recommended that an application calls [requestSuspendDelay()](../reference/apis/js-apis-resourceschedule-backgroundTaskManager.md#backgroundtaskmanagerrequestsuspenddelay) when it is running in the foreground, so as not to affect the transient task quota of the application.

An application can obtain the remaining duration before being suspended by calling [getRemainingDelayTime()](../reference/apis/js-apis-resourceschedule-backgroundTaskManager.md#backgroundtaskmanagergetremainingdelaytime). Each application has a daily time quota for transient tasks. Therefore, after the time-consuming task finishes execution, the application should call [cancelSuspendDelay()](../reference/apis/js-apis-resourceschedule-backgroundTaskManager.md#backgroundtaskmanagercancelsuspenddelay) to cancel the transient task in a timely manner.

Typical time-consuming tasks include saving status data to the local database, opening and processing a large file, and synchronizing data to the cloud server.


## Available APIs


**Table 1** Main APIs for transient tasks

| API                                     | Description                                      |
| ---------------------------------------- | ---------------------------------------- |
| requestSuspendDelay(reason: string, callback: Callback&lt;void&gt;): [DelaySuspendInfo](../reference/apis/js-apis-backgroundTaskManager.md#delaysuspendinfo)| Requests delayed suspension after the application switches to the background.<br>The default duration of delayed suspension is 3 minutes when the battery level is normal and 1 minute when the battery level is low.|
| getRemainingDelayTime(requestId: number): Promise&lt;number&gt; | Obtains the remaining duration before the application is suspended.<br>This API uses a promise to return the result.  |
| cancelSuspendDelay(requestId: number): void | Cancels the suspension delay.                                 |


## How to Develop

When an application needs to execute a time-consuming task in the background, call the API to request a transient task. After the time-consuming task finishes execution, call the API to cancel the transient task.

```js
import backgroundTaskManager from '@ohos.resourceschedule.backgroundTaskManager';

let id; // ID of the suspension delay request.
let delayTime; // Remaining duration for the suspension delay request.

// Request a suspension delay.
function requestSuspendDelay() {
  let myReason = 'test requestSuspendDelay'; // Reason for the suspension delay request.

  try {
    let delayInfo = backgroundTaskManager.requestSuspendDelay(myReason, () => {
      // The callback is invoked to notify the application that the suspension delay request is about to time out. The application needs to perform some cleanup and annotation operations and cancels the transient task.
      console.info("[backgroundTaskManager] Request suspension delay will time out.");
      backgroundTaskManager.cancelSuspendDelay(id);
    })
    id = delayInfo.requestId;
    delayTime = delayInfo.actualDelayTime;
    console.info("[backgroundTaskManager] The requestId is: " + id);
    console.info("[backgroundTaskManager]The actualDelayTime is: " + delayTime);
  } catch (error) {
    console.error(`[backgroundTaskManager] requestSuspendDelay failed. code is ${error.code} message is ${error.message}`);
  }
}

// Obtain the remaining duration before the application is suspended.
async function getRemainingDelayTime() {
  try {
    await backgroundTaskManager.getRemainingDelayTime(id).then(res => {
      console.log('[backgroundTaskManager] promise => Operation getRemainingDelayTime succeeded. Data: ' + JSON.stringify(res));
    }).catch(error => {
      console.error(`[backgroundTaskManager] promise => Operation getRemainingDelayTime failed. code is ${error.code} message is ${error.message}`);
    })
  } catch (error) {
    console.error(`[backgroundTaskManager] promise => Operation getRemainingDelayTime failed. code is ${error.code} message is ${error.message}`);
  }
}

// Cancel the suspension delay.
function cancelSuspendDelay() {
  backgroundTaskManager.cancelSuspendDelay(id);
}

async function performingLongRunningTask() {
  // Before executing a time-consuming task, call the API to request a transient task to delay the suspension.
  requestSuspendDelay();

  // If required, obtain the available time quota through the getRemainingDelayTime() API.
  await getRemainingDelayTime();

  if (delayTime < 0) {// If the time is less than a certain value, cancel the time-consuming task.
    // Handle the scenario where the time quota is insufficient.
    cancelSuspendDelay();
    return;
  }

  // Execute the time-consuming task.

  // After the time-consuming task is executed, call the API to cancel the transient task.
  cancelSuspendDelay();
}
```
