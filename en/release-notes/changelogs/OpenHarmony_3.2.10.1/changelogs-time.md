# Time Subsystem ChangeLog

## cl.time.1 API Error Change

Errors thrown by timer APIs of the time subsystem: **202** (non-system application) and **401** (invalid parameters).

**Change Impacts**

The API change is forward compatible. Applications developed based on earlier versions can still use the APIs, and corresponding error handling is added. The original functions are not affected.

**Key API/Component Changes**

Before change:
  - The API throws an error message without an error code.

After change:
  - The API throws an error message with an error code. Error code **202** indicates that the application is not a system application, and error code **401** indicates that the parameters are invalid.

    | Module           | Class       | Method/Attribute/Enumeration/Constant                                         | Change Type|
    | ----------------- | ----------- | ------------------------------------------------------------ | -------- |
    | @ohos.systemTimer | systemTimer | function createTimer(options: TimerOptions, callback: AsyncCallback<number>): void | Changed    |
    | @ohos.systemTimer | systemTimer | function createTimer(options: TimerOptions): Promise<number> | Changed    |
    | @ohos.systemTimer | systemTimer | function startTimer(timer: number, triggerTime: number, callback: AsyncCallback<void>): void | Changed    |
    | @ohos.systemTimer | systemTimer | function startTimer(timer: number, triggerTime: number): Promise<void> | Changed    |
    | @ohos.systemTimer | systemTimer | function stopTimer(timer: number, callback: AsyncCallback<void>): void | Changed    |
    | @ohos.systemTimer | systemTimer | function stopTimer(timer: number): Promise<void>             | Changed    |
    | @ohos.systemTimer | systemTimer | function destroyTimer(timer: number, callback: AsyncCallback<void>): void | Changed    |
    | @ohos.systemTimer | systemTimer | function destroyTimer(timer: number): Promise<void>          | Changed    |


**Adaptation Guide**

Refer to the code below to capture errors when **systemTimer** APIs are called in applications.

createTimer callback mode:

**Example**:

```js
export default {
    systemTimer () {
        let options = {
            type: systemTimer.TIMER_TYPE_REALTIME,
            repeat: false
        };
        try {
            systemTimer.createTimer(options, (error, data) => {
                if (error) {
                    // Capture the permission denial error.
                    console.info(`Failed to create timer. message:${error.message}, code:${error.code}`);
                }
        	});
        } catch(e) {
            // Capture the parameter verification error.
            console.info(`Failed to create timer. message:${e.message}, code:${e.code}`);
        }
    }
}
```

createTimer promise mode:

**Example**:

```js
export default {
    systemTimer () {
        let options = {
            type: systemTimer.TIMER_TYPE_REALTIME,
            repeat: false
        };
        try {
            systemTimer.createTimer(options).then((data) => {
            	console.info(`Succeeded in creating timer. Data:` + data);
        	}).catch((error) => {
                // Capture the permission denial error.
            	console.info(`Failed to create timer. message:${error.message}, code:${error.code}`);
        	});
        } catch(e) {
            // Capture the parameter verification error.
            console.info(`Failed to create timer. message:${e.message}, code:${e.code}`);
        }
    }
}
```

startTimer callback mode:

**Example**:

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
                    // Capture the permission denial error.
                    console.error(`Failed to start timer. message:${error.message}, code:${error.code}`);
                }
      		});
        } catch (e) {
            // Capture the parameter verification error.
            console.info(`Failed to start timer. message:${e.message}, code:${e.code}`);
        }
    }
}
```

startTimer promise mode:

**Example**:

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
            systemTimer.startTimer(timerId, triggerTime).then((data) => {
            	console.log(`Succeeded in startting timer. Data:` + data);
        	}).catch((error) => {
                // Capture the permission denial error.
            	console.info(`Failed to start timer. message:${error.message}, code:${error.code}`);
        	});
        } catch (e) {
            // Capture the parameter verification error.
            console.info(`Failed to start timer. message:${e.message}, code:${e.code}`);
        }
    }
}
```

stopTimer callback mode:

**Example**:

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
            systemTimer.stopTimer(timerId, triggerTime, (error) => {
                if (error) {
                    // Capture the permission denial error.
                    console.error(`Failed to stop timer. message:${error.message}, code:${error.code}`);
                }
      		});
        } catch (e) {
            // Capture the parameter verification error.
            console.info(`Failed to stop timer. message:${e.message}, code:${e.code}`);
        }
    }
}
```

stopTimer promise mode:

**Example**:

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
            systemTimer.stopTimer(timerId, triggerTime).then((data) => {
            	console.log(`Succeeded in stop timer. Data:` + data);
        	}).catch((error) => {
                // Capture the permission denial error.
            	console.info(`Failed to stop timer. message:${error.message}, code:${error.code}`);
        	});
        } catch (e) {
            // Capture the parameter verification error.
            console.info(`Failed to stop timer. message:${e.message}, code:${e.code}`);
        }
    }
}
```

destroyTimer callback mode:

**Example**:

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
            systemTimer.destroyTimer(timerId, triggerTime, (error) => {
                if (error) {
                    // Capture the permission denial error.
                    console.error(`Failed to destroy timer. message:${error.message}, code:${error.code}`);
                }
      		});
        } catch (e) {
            // Capture the parameter verification error.
            console.info(`Failed to destroy timer. message:${e.message}, code:${e.code}`);
        }
    }
}
```

destroyTimer promise mode:

**Example**:

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
            systemTimer.destroyTimer(timerId, triggerTime).then((data) => {
            	console.log(`Succeeded in destroy timer. Data:` + data);
        	}).catch((error) => {
                // Capture the permission denial error.
            	console.info(`Failed to destroy timer. message:${error.message}, code:${error.code}`);
        	});
        } catch (e) {
            // Capture the parameter verification error.
            console.info(`Failed to destroy timer. message:${e.message}, code:${e.code}`);
        }
    }
}
```
