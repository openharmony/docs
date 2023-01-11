# 时间时区子系统ChangeLog

## cl.time.1 接口异常抛出变更

时间时区子系统定时器接口异常抛出：202非系统应用异常和401参数无效异常。

**变更影响**

该接口变更前向兼容，基于此前版本开发的应用可继续使用接口，增加相应的异常处理，原有功能不受影响。

**关键接口/组件变更**

变更前：
  - 接口异常抛出message，无错误码。

变更后：
  - 接口异常抛出message和code，包括202非系统应用异常和401参数无效异常。

    | 模块名            | 类名        | 方法/属性/枚举/常量                                          | 变更类型 |
    | ----------------- | ----------- | ------------------------------------------------------------ | -------- |
    | @ohos.systemTimer | systemTimer | function createTimer(options: TimerOptions, callback: AsyncCallback<number>): void | 变更     |
    | @ohos.systemTimer | systemTimer | function createTimer(options: TimerOptions): Promise<number> | 变更     |
    | @ohos.systemTimer | systemTimer | function startTimer(timer: number, triggerTime: number, callback: AsyncCallback<void>): void | 变更     |
    | @ohos.systemTimer | systemTimer | function startTimer(timer: number, triggerTime: number): Promise<void> | 变更     |
    | @ohos.systemTimer | systemTimer | function stopTimer(timer: number, callback: AsyncCallback<void>): void | 变更     |
    | @ohos.systemTimer | systemTimer | function stopTimer(timer: number): Promise<void>             | 变更     |
    | @ohos.systemTimer | systemTimer | function destroyTimer(timer: number, callback: AsyncCallback<void>): void | 变更     |
    | @ohos.systemTimer | systemTimer | function destroyTimer(timer: number): Promise<void>          | 变更     |


**适配指导**

应用中调用systemTimer所有接口可参考下列代码进行异常捕获

createTimer callback形式调用：

**示例：**

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
                    //捕获权限否定异常
                    console.info(`Failed to create timer. message:${error.message}, code:${error.code}`);
                }
        	});
        } catch(e) {
            //捕获参数校验失败异常
            console.info(`Failed to create timer. message:${e.message}, code:${e.code}`);
        }
    }
}
```

createTimer promise形式调用：

**示例：**

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
                //捕获权限否定异常
            	console.info(`Failed to create timer. message:${error.message}, code:${error.code}`);
        	});
        } catch(e) {
            //捕获参数校验失败异常
            console.info(`Failed to create timer. message:${e.message}, code:${e.code}`);
        }
    }
}
```

startTimer callback形式调用：

**示例：**

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
                    //捕获权限否定异常
                    console.error(`Failed to start timer. message:${error.message}, code:${error.code}`);
                }
      		});
        } catch (e) {
            //捕获参数校验失败异常
            console.info(`Failed to start timer. message:${e.message}, code:${e.code}`);
        }
    }
}
```

startTimer promise形式调用：

**示例：**

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
                //捕获权限否定异常
            	console.info(`Failed to start timer. message:${error.message}, code:${error.code}`);
        	});
        } catch (e) {
            //捕获参数校验失败异常
            console.info(`Failed to start timer. message:${e.message}, code:${e.code}`);
        }
    }
}
```

stopTimer callback形式调用：

**示例：**

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
                    //捕获权限否定异常
                    console.error(`Failed to stop timer. message:${error.message}, code:${error.code}`);
                }
      		});
        } catch (e) {
            //捕获参数校验失败异常
            console.info(`Failed to stop timer. message:${e.message}, code:${e.code}`);
        }
    }
}
```

stopTimer promise形式调用：

**示例：**

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
                //捕获权限否定异常
            	console.info(`Failed to stop timer. message:${error.message}, code:${error.code}`);
        	});
        } catch (e) {
            //捕获参数校验失败异常
            console.info(`Failed to stop timer. message:${e.message}, code:${e.code}`);
        }
    }
}
```

destroyTimer callback形式调用：

**示例：**

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
                    //捕获权限否定异常
                    console.error(`Failed to destroy timer. message:${error.message}, code:${error.code}`);
                }
      		});
        } catch (e) {
            //捕获参数校验失败异常
            console.info(`Failed to destroy timer. message:${e.message}, code:${e.code}`);
        }
    }
}
```

destroyTimer promise形式调用：

**示例：**

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
                //捕获权限否定异常
            	console.info(`Failed to destroy timer. message:${error.message}, code:${error.code}`);
        	});
        } catch (e) {
            //捕获参数校验失败异常
            console.info(`Failed to destroy timer. message:${e.message}, code:${e.code}`);
        }
    }
}
```

