# Transient Task Development

## When to Use

By default, an application can run for 6 to 12 seconds after it switches to the background but before being suspended. If an application requires more time to execute an important task, it can call the **requestSuspendDelay** API to delay the suspension.

It is recommended that an application calls the **requestSuspendDelay** API before executing any time-consuming task, rather than when it is already running in the background.
The calling of the **requestSuspendDelay** API when the application is running in the foreground does not affect the transient task quota of the application.

Each application has a daily time quota for transient tasks. Therefore, after the time-consuming task finishes execution, the application should cancel the transient task in a timely manner.

Typical time-consuming tasks include saving status data to the local database, opening and processing a large file, and synchronizing data to the cloud server.


## Available APIs


**Table 1** Main APIs for transient tasks

| API                                     | Description                                      |
| ---------------------------------------- | ---------------------------------------- |
| requestSuspendDelay(reason: string, callback: Callback&lt;void&gt;): [DelaySuspendInfo](../reference/apis/js-apis-backgroundTaskManager.md#delaysuspendinfo) | Requests delayed suspension after the application switches to the background.<br>The default duration value of delayed suspension is 3 minutes when the battery level is normal and 1 minute when the battery level is low.|
| getRemainingDelayTime(requestId: number): Promise&lt;number&gt; | Obtains the remaining duration before the application is suspended.<br>This API uses a promise to return the result.  |
| cancelSuspendDelay(requestId: number): void | Cancels the suspension delay.                                 |


## How to Develop

1. When an application needs to execute a time-consuming task, call the API to request a transient task. After the time-consuming task finishes execution, call the API to cancel the transient task.

```js
import backgroundTaskManager from '@ohos.backgroundTaskManager';

let delayInfo;
let id;

// Request a suspension delay.
function requestSuspendDelay() {
    let myReason = 'test requestSuspendDelay';
    delayInfo = backgroundTaskManager.requestSuspendDelay(myReason, () => {
        console.info("Request suspension delay will time out.");
        // The callback in invoked to notify the application that the suspension delay request is about to time out. The application needs to perform some cleanup and annotation operations.
    });

    id = delayInfo.requestId;
    console.info("requestId is: " + id);
}

// Obtain the remaining duration before the application is suspended.
function getRemainingDelayTime() {
    let delayTime = 0;
    backgroundTaskManager.getRemainingDelayTime(id).then((res) => {
        console.log('promise => Operation getRemainingDelayTime succeeded. Data: ' + JSON.stringify(res));
        delayTime = res;
    }).catch((err) => {
        console.log('promise => Operation getRemainingDelayTime failed. Cause: ' + err.code);
    });
    return delayTime;
}

// Cancel the suspension delay.
function cancelSuspendDelay() {
    backgroundTaskManager.cancelSuspendDelay(id);
}

function performingLongRunningTask() {
    // Before executing the time-consuming task, call the API to request a transient task to delay the suspension.
    requestSuspendDelay();

    // Obtain the available time quota through the getRemainingDelayTime() API.
    let delayTime = getRemainingDelayTime();

    if (delayTime < 0) {// If the time is less than a certain value, cancel the time-consuming operation.
        // Handle the scenario where the time quota is insufficient.

        cancelSuspendDelay();
        return;
    }

    // Execute the time-consuming task.

    // After the time-consuming task is executed, call the API to cancel the transient task.
    cancelSuspendDelay();
}
```
