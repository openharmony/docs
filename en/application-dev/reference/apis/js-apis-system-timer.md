# @ohos.systemTimer (System Timer)

The **systemTimer** module provides system timer features. You can use the APIs of this module to implement the alarm clock and other timer services.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs provided by this module are system APIs.

## Modules to Import


```js
import systemTimer from '@ohos.systemTimer';
```

## Constants

Provides the constants that define the supported timer types.

**System capability**: SystemCapability.MiscServices.Time

| Name               | Type  | Value  | Description                        |
| ------------------- | ------ | ---- | ---------------------------- |
| TIMER_TYPE_REALTIME | number | 1    | CPU time type. (The start time of the timer cannot be later than the current system time.)        |
| TIMER_TYPE_WAKEUP   | number | 2    | Wakeup type.                |
| TIMER_TYPE_EXACT    | number | 4    | Exact type.                |
| TIMER_TYPE_IDLE     | number | 8    | Idle type (not supported currently).|

 ## TimerOptions

Defines the initialization options for **createTimer**.

**System capability**: SystemCapability.MiscServices.Time

| Name     | Type                                         | Mandatory| Description                                                        |
| --------- | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| type      | number                                        | Yes  | Timer type.<br>**1**: CPU time type. (The start time of the timer cannot be later than the current system time.)<br>**2**: wakeup type.<br>**4**: exact type.<br>**8**: idle type (not supported currently).|
| repeat    | boolean                                       | Yes  | Whether the timer is a repeating timer.<br>The value **true** means that the timer is a repeating timer, and **false** means that the timer is a one-shot timer.                       |
| interval  | number                                        | No  | Repeat interval.<br>For a repeating timer, the value must be greater than 5000 ms. For a one-shot timer, the value is **0**.|
| wantAgent | [WantAgent](js-apis-app-ability-wantAgent.md) | No  | **WantAgent** object of the notification to be sent when the timer expires. (An application MainAbility can be started, but not a Service ability.)|
| callback  | number                                        | Yes  | Callback used to return the timer ID.                            |


## systemTimer.createTimer

createTimer(options: TimerOptions, callback: AsyncCallback&lt;number&gt;): void

Creates a timer. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name  | Type                         | Mandatory| Description                                                        |
| -------- | ----------------------------- | ---- | ------------------------------------------------------------ |
| options  | [TimerOptions](#timeroptions) | Yes  | Timer initialization options, including the timer type, whether the timer is a repeating timer, interval, and **WantAgent** options.|
| callback | AsyncCallback&lt;number>      | Yes  | Callback used to return the timer ID.                                  |

**Example**

```js
export default {
  systemTimer () {
    let options = {
      type: systemTimer.TIMER_TYPE_REALTIME,
      repeat: false
    };
    try {
      systemTimer.createTimer(options, (error, timerId) => {
        if (error) {
          console.info(`Failed to create timer. message: ${error.message}, code: ${error.code}`);
          return;
        }
        console.info(`Succeeded in creating timer. timerId: ${timerId}`);
      });
    } catch(e) {
      console.info(`Failed to create timer. message: ${e.message}, code: ${e.code}`);
    }
  }
}
```

## systemTimer.createTimer

createTimer(options: TimerOptions): Promise&lt;number&gt;

Creates a timer. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name | Type                         | Mandatory| Description                                                        |
| ------- | ----------------------------- | ---- | ------------------------------------------------------------ |
| options | [TimerOptions](#timeroptions) | Yes  | Timer initialization options, including the timer type, whether the timer is a repeating timer, interval, and **WantAgent** options.|

**Return value**

| Type                 | Description                         |
| --------------------- | ----------------------------- |
| Promise&lt;number&gt; | Promise used to return the timer ID.|

**Example**

```js
export default {
  systemTimer () {
    let options = {
      type: systemTimer.TIMER_TYPE_REALTIME,
      repeat:false
    };   
    try {
      systemTimer.createTimer(options).then((timerId) => {
        console.info(`Succeeded in creating timer. timerId: ${timerId}`);
      }).catch((error) => {
        console.info(`Failed to create timer. message: ${error.message}, code: ${error.code}`);
      });
    } catch(e) {
      console.info(`Failed to create timer. message: ${e.message}, code: ${e.code}`);
    }
  }
}
```

## systemTimer.startTimer

startTimer(timer: number, triggerTime: number, callback: AsyncCallback&lt;void&gt;): void

Starts a timer. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name     | Type                  | Mandatory| Description                          |
| ----------- | ---------------------- | ---- | ------------------------------ |
| timer       | number                 | Yes  | ID of the timer.                  |
| triggerTime | number                 | Yes  | Time when the timer is triggered, in milliseconds.|
| callback    | AsyncCallback&lt;void> | Yes  | Callback used to return the result.                    |

**Example**

```js
export default {
  async systemTimer () {
    let options = {
      type: systemTimer.TIMER_TYPE_REALTIME,
      repeat:false
    }
  let timerId = await systemTimer.createTimer(options);
  let triggerTime = new Date().getTime();
  triggerTime += 3000;
  try {
      systemTimer.startTimer(timerId, triggerTime, (error) => {
        if (error) {
          console.info(`Failed to start timer. message: ${error.message}, code: ${error.code}`);
          return;
        }
        console.info(`Succeeded in starting timer.`);
      });
    } catch(e) {
      console.info(`Failed to start timer. message: ${e.message}, code: ${e.code}`);
    }
  }
}
```

## systemTimer.startTimer

startTimer(timer: number, triggerTime: number): Promise&lt;void&gt;

Starts a timer. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name     | Type  | Mandatory| Description                          |
| ----------- | ------ | ---- | ------------------------------ |
| timer       | number | Yes  | ID of the timer.                  |
| triggerTime | number | Yes  | Time when the timer is triggered, in milliseconds.|

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value.|

**Example**

```js
export default {
  async systemTimer (){
    let options = {
      type: systemTimer.TIMER_TYPE_REALTIME,
      repeat:false
    }
    let timerId = await systemTimer.createTimer(options);
    let triggerTime = new Date().getTime();
    triggerTime += 3000;
    try {
      systemTimer.startTimer(timerId, triggerTime).then(() => {
        console.info(`Succeeded in starting timer.`);
         }).catch((error) => {
        console.info(`Failed to start timer. message: ${error.message}, code: ${error.code}`);
      });
    } catch(e) {
      console.info(`Failed to start timer. message: ${e.message}, code: ${e.code}`);
    } 
  }
}
```

## systemTimer.stopTimer

stopTimer(timer: number, callback: AsyncCallback&lt;void&gt;): void

Stops a timer. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name  | Type                  | Mandatory| Description        |
| -------- | ---------------------- | ---- | ------------ |
| timer    | number                 | Yes  | ID of the timer.|
| callback | AsyncCallback&lt;void> | Yes  | Callback used to return the result.  |

**Example**

```js
export default {
  async systemTimer () {
    let options = {
      type: systemTimer.TIMER_TYPE_REALTIME,
      repeat:false
    }
    let timerId = await systemTimer.createTimer(options);
    let triggerTime = new Date().getTime();
    triggerTime += 3000;
    systemTimer.startTimer(timerId, triggerTime);
    try {
      systemTimer.stopTimer(timerId, (error) => {
        if (error) {
          console.info(`Failed to stop timer. message: ${error.message}, code: ${error.code}`);
          return;
        }
        console.info(`Succeeded in stopping timer.`);
      });
    } catch(e) {
      console.info(`Failed to stop timer. message: ${e.message}, code: ${e.code}`);
    }
  }
}
```

## systemTimer.stopTimer

stopTimer(timer: number): Promise&lt;void&gt;

Stops a timer. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name| Type  | Mandatory| Description        |
| ------ | ------ | ---- | ------------ |
| timer  | number | Yes  | ID of the timer.|

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value.|

**Example**

```js
export default {
  async systemTimer (){
    let options = {
      type: systemTimer.TIMER_TYPE_REALTIME,
      repeat:false
    }
    let timerId = await systemTimer.createTimer(options);
    let triggerTime = new Date().getTime();
    triggerTime += 3000;
    systemTimer.startTimer(timerId, triggerTime);
    try {
      systemTimer.stopTimer(timerId).then(() => {
        console.info(`Succeeded in stopping timer.`);
      }).catch((error) => {
        console.info(`Failed to stop timer. message: ${error.message}, code: ${error.code}`);
      });
    } catch(e) {
      console.info(`Failed to stop timer. message: ${e.message}, code: ${e.code}`);
    }
  }
}
```

## systemTimer.destroyTimer

destroyTimer(timer: number, callback: AsyncCallback&lt;void&gt;): void

Destroys a timer. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name  | Type                  | Mandatory| Description        |
| -------- | ---------------------- | ---- | ------------ |
| timer    | number                 | Yes  | ID of the timer.|
| callback | AsyncCallback&lt;void> | Yes  | Callback used to return the result.  |

**Example**

```js
export default {
  async systemTimer () {
    let options = {
      type: systemTimer.TIMER_TYPE_REALTIME,
      repeat:false
    }
    let timerId = await systemTimer.createTimer(options);
    let triggerTime = new Date().getTime();
    triggerTime += 3000;
    systemTimer.startTimer(timerId, triggerTime);
    systemTimer.stopTimer(timerId);
    try {
      systemTimer.destroyTimer(timerId, (error) => {
        if (error) {
          console.info(`Failed to destroy timer. message: ${error.message}, code: ${error.code}`);
          return;
        }
        console.info(`Succeeded in destroying timer.`);
      });
    } catch(e) {
      console.info(`Failed to destroying timer. message: ${e.message}, code: ${e.code}`);
    }
  }
}
```

## systemTimer.destroyTimer

destroyTimer(timer: number): Promise&lt;void&gt;

Destroys a timer. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name| Type  | Mandatory| Description        |
| ------ | ------ | ---- | ------------ |
| timer  | number | Yes  | ID of the timer.|

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value.|

**Example**

```js
export default {
  async systemTimer (){
    let options = {
      type: systemTimer.TIMER_TYPE_REALTIME,
      repeat:false
    }
    let timerId = await systemTimer.createTimer(options);
    let triggerTime = new Date().getTime();
    triggerTime += 3000;
    systemTimer.startTimer(timerId, triggerTime);
    systemTimer.stopTimer(timerId);
    try {
      systemTimer.destroyTimer(timerId).then(() => {
         console.info(`Succeeded in destroying timer.`);
      }).catch((error) => {
        console.info(`Failed to destroy timer. message: ${error.message}, code: ${error.code}`);
      });
    } catch(e) {
      console.info(`Failed to destroying timer. message: ${e.message}, code: ${e.code}`);
    }
  }
}
```
