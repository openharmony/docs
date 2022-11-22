# System Timer

The **systemTimer** module provides system timer features. You can use the APIs of this module to implement the alarm clock and other timer services.

> **NOTE**
>- The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>- The APIs of this module are system APIs and cannot be called by third-party applications.

## Modules to Import


```
import systemTimer from '@ohos.systemTimer';
```


## systemTime.createTimer

createTimer(options: TimerOptions, callback: AsyncCallback&lt;number&gt;): void

Creates a timer. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name   | Type                            | Mandatory| Description                                                                       |
| ------- | ---------------------------------| ---- | --------------------------------------------------------------------------- |
| options |  [TimerOptions](#timeroptions)   | Yes  | Timer options. |

**Return value**

| Type                     | Description                                                        |
| ------------------------- | ------------------------------------------------------------ |
| syncCallback&lt;number&gt;| Callback used to return the timer ID.                            |

**Example**

  ```js
export default {
    systemTimer () {
        var options = {
            type: systemTimer.TIMER_TYPE_REALTIME,
            repeat: false
        }
        systemTimer.createTimer(options, (error, data) => {
            if (error) {
                console.error(`failed to systemTime.createTimer ` + JSON.stringify(error));
                return;
            }
            console.log(`systemTime.createTimer success data : ` + JSON.stringify(data));
        });
    }
}
  ```


## systemTime.createTimer

createTimer(options: TimerOptions): Promise&lt;number&gt;

Creates a timer. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name   | Type                            | Mandatory| Description                                                                       |
| ------- | ---------------------------------| ---- | --------------------------------------------------------------------------- |
| options |  [TimerOptions](#timeroptions)   | Yes  | Timer options. |

**Return value**

| Type                 | Description                                                        |
| --------------------- | ------------------------------------------------------------ |
| Promise&lt;number&gt; | Promise used to return the timer ID.                               |

**Example**

  ```js
export default {
    systemTimer () {
        var options = {
            type: systemTimer.TIMER_TYPE_REALTIME,
            repeat:false
        }
        systemTimer.createTimer(options).then((data) => {
            console.log(`systemTime.createTimer success data : ` + JSON.stringify(data));
        }).catch((error) => {
            console.error(`failed to systemTime.createTimer because ` + JSON.stringify(error));
        });
    }
}
  ```


## systemTime.startTimer

startTimer(timer: number, triggerTime: number, callback: AsyncCallback&lt;void&gt;): void

Starts a timer. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name     | Type                       | Mandatory| Description                                                        |
| ----------- | --------------------------- | ---- | ------------------------------------------------------------ |
| timer       | number                      | Yes  | ID of the timer.                                                |
| triggerTime | number                      | Yes  | Time when the timer is triggered, in milliseconds.                              |


**Example**

  ```js
export default {
    systemTimer () {
        var options = {
            type: systemTimer.TIMER_TYPE_REALTIME,
            repeat:false
        }
        let timerId = systemTimer.createTimer(options)
		let triggerTime = new Date().getTime()
        triggerTime += 3000
        systemTimer.startTimer(timerId, triggerTime, (error, data) => {
            if (error) {
                console.error(`failed to systemTime.startTimer ` + JSON.stringify(error));
                return;
            }
            console.log(`systemTime.startTimer success data : ` + JSON.stringify(data));
        });
    }
}
  ```

## systemTime.startTimer

startTimer(timer: number, triggerTime: number): Promise&lt;void&gt;

Starts a timer. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name     | Type                       | Mandatory| Description                                                        |
| ----------- | --------------------------- | ---- | ------------------------------------------------------------ |
| timer       | number                      | Yes  | ID of the timer.    |                                                                                                                                                     | triggerTime | number                      | Yes  | Time when the timer is triggered, in milliseconds.                              |

**Example**

  ```js
export default {
    systemTimer (){
        var options = {
            type: systemTimer.TIMER_TYPE_REALTIME,
            repeat:false
        }
        let timerId = systemTimer.createTimer(options)
		let triggerTime = new Date().getTime()
        triggerTime += 3000
        systemTimer.startTimer(timerId, triggerTime).then((data) => {
            console.log(`systemTime.startTimer success data : ` + JSON.stringify(data));
        }).catch((error) => {
            console.error(`failed to systemTime.startTimer because ` + JSON.stringify(error));
        });
    }
}
  ```


## systemTime.stopTimer

stopTimer(timer: number, callback: AsyncCallback&lt;void&gt;): void

Stops a timer. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name  | Type                       | Mandatory| Description                                                        |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| timer    | number                      | Yes  | ID of the timer.                                                |

**Example**

  ```js
export default {
    systemTimer () {
        var options = {
            type: systemTimer.TIMER_TYPE_REALTIME,
            repeat:false
        }
        let timerId = systemTimer.createTimer(options)
		let triggerTime = new Date().getTime()
        triggerTime += 3000
        systemTimer.startTimer(timerId, triggerTime)
        systemTimer.stoptTimer(timerId, (error, data) => {
            if (error) {
                console.error(`failed to systemTime.startTimer ` + JSON.stringify(error));
                return;
            }
            console.log(`systemTime.startTimer success data : ` + JSON.stringify(data));
        });
    }
}
  ```


## systemTime.stopTimer

stopTimer(timer: number): Promise&lt;void&gt;

Stops a timer. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| timer  | number  | Yes  | ID of the timer.                                                |

**Example**

  ```js
export default {
    systemTimer (){
        var options = {
            type: systemTimer.TIMER_TYPE_REALTIME,
            repeat:false
        }
        let timerId = systemTimer.createTimer(options)
		let triggerTime = new Date().getTime()
        triggerTime += 3000
        systemTimer.startTimer(timerId, triggerTime)
        systemTimer.stoptTimer(timerId).then((data) => {
            console.log(`systemTime.startTimer success data : ` + JSON.stringify(data));
        }).catch((error) => {
            console.error(`failed to systemTime.startTimer because ` + JSON.stringify(error));
        });
    }
}
  ```


## systemTime.destroyTimer

destroyTimer(timer: number, callback: AsyncCallback&lt;void&gt;): void

Destroys a timer. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name  | Type                       | Mandatory| Description                                                        |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| timer    | number                      | Yes  | ID of the timer.                                                |

**Example**

  ```js
export default {
    systemTimer () {
        var options = {
            type: systemTimer.TIMER_TYPE_REALTIME,
            repeat:false
        }
        let timerId = systemTimer.createTimer(options)
		let triggerTime = new Date().getTime()
        triggerTime += 3000
        systemTimer.startTimer(timerId, triggerTime)
        systemTimer.stopTimer(timerId)
        systemTimer.destroyTimer(timerId, (error, data) => {
            if (error) {
                console.error(`failed to systemTime.startTimer ` + JSON.stringify(error));
                return;
            }
            console.log(`systemTime.startTimer success data : ` + JSON.stringify(data));
        });
    }
}
  ```


## systemTime.destroyTimer

destroyTimer(timer: number): Promise&lt;void&gt;

Destroys a timer. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| timer  | number  | Yes  | ID of the timer.                                                |

**Example**

  ```js
export default {
    systemTimer (){
        var options = {
            type: systemTimer.TIMER_TYPE_REALTIME,
            repeat:false
        }
        let timerId = systemTimer.createTimer(options)
		let triggerTime = new Date().getTime()
        triggerTime += 3000
        systemTimer.startTimer(timerId, triggerTime)
        systemTimer.stopTimer(timerId)
        systemTimer.destroyTimer(timerId, 10000).then((data) => {
            console.log(`systemTime.startTimer success data : ` + JSON.stringify(data));
        }).catch((error) => {
            console.error(`failed to systemTime.startTimer because ` + JSON.stringify(error));
        });
    }
}
  ```

 ## TimerOptions

Defines the initialization options for **createTimer**.

**System capability**: SystemCapability.MiscServices.Time

| Name  | Type             | Mandatory| Description                                                                                                                     |
| -------- | ------------------| ---- | ------------------------------------------------------------------------------------------------------------------------- |
| type     | number            | Yes  | **const TIMER_TYPE_REALTIME**: sets the timer to the CPU time type. (When the set time is later than the timer startup time, the timer expires.) If it is not specified, the timer is of the wall-time type.<br>**const TIMER_TYPE_WAKEUP**: sets the timer to the wakeup type. If it is not specified, the timer is of the non-wakeup type.<br>**const TIMER_TYPE_EXACT**: sets the timer to the exact type. If it is not specified, the timer is of the non-exact type.<br>**const TIMER_TYPE_IDLE: number**: sets the timer to the idle type. If it is not specified, the timer is of the non-idle type (not yet supported). |
| repeat   | boolean           | Yes  | Whether the timer is a repeating timer. The value **true** means that the timer is a repeating timer, and **false** means that the timer is a one-shot timer.                                                                                   |
| interval | number            | No  | Repeat interval. For a repeating timer, the value must be greater than 5000 ms. For a one-shot timer, the value is **0**.                                                            |
| wantAgent| wantAgent         | No  | **wantAgent** object of the notification to be sent when the timer expires. (An application MainAbility can be started, but not a Service ability.)                              |
| callback | number            | Yes  | Callback used to return the timer ID.    |
