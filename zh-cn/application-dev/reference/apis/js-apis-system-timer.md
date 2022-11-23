# 系统定时器

本模块主要由系统定时器功能组成。开发者可以使用定时功能实现定时服务，如闹钟等。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
>- 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>- 本模块接口为系统接口，三方应用不支持调用。

## 导入模块


```
import systemTimer from '@ohos.systemTimer';
```


## systemTimer.createTimer

createTimer(options: TimerOptions, callback: AsyncCallback&lt;number&gt;): void

创建定时器。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 名称    | 类型                             | 必填 | 说明                                                                        |
| ------- | ---------------------------------| ---- | --------------------------------------------------------------------------- |
| options |  [TimerOptions](#timeroptions)   | 是   | 创建系统定时器，包括定时器类型，是否循环触发，间隔时间，WantAgent通知机制。 |

**返回值：**

| 类型                      | 说明                                                         |
| ------------------------- | ------------------------------------------------------------ |
| syncCallback&lt;number&gt;| 以回调函数的形式返回定时器的ID。                             |

**示例：**

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


## systemTimer.createTimer

createTimer(options: TimerOptions): Promise&lt;number&gt;

创建定时器。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 名称    | 类型                             | 必填 | 说明                                                                        |
| ------- | ---------------------------------| ---- | --------------------------------------------------------------------------- |
| options |  [TimerOptions](#timeroptions)   | 是   | 创建系统定时器，包括定时器类型，是否循环触发，间隔时间，WantAgent通知机制。 |

**返回值：**

| 类型                  | 说明                                                         |
| --------------------- | ------------------------------------------------------------ |
| Promise&lt;number&gt; | 以Promise形式返回定时器的ID。                                |

**示例：**

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


## systemTimer.startTimer

startTimer(timer: number, triggerTime: number, callback: AsyncCallback&lt;void&gt;): void

开始定时器。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名      | 类型                        | 必填 | 说明                                                         |
| ----------- | --------------------------- | ---- | ------------------------------------------------------------ |
| timer       | number                      | 是   | 定时器的ID。                                                 |
| triggerTime | number                      | 是   | 定时器的触发时间，单位：毫秒。                               |


**示例：**

  ```js
export default {
    async systemTimer () {
        var options = {
            type: systemTimer.TIMER_TYPE_REALTIME,
            repeat:false
        }
        let timerId = await systemTimer.createTimer(options)
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

## systemTimer.startTimer

startTimer(timer: number, triggerTime: number): Promise&lt;void&gt;

开始定时器。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名      | 类型                        | 必填 | 说明                                                         |
| ----------- | --------------------------- | ---- | ------------------------------------------------------------ |
| timer       | number                      | 是   | 定时器的ID。                                                                                                                                                             
| triggerTime | number                      | 是   | 定时器的触发时间，单位：毫秒。                               |                                                                                                                    


**示例：**

  ```js
export default {
    async systemTimer (){
        var options = {
            type: systemTimer.TIMER_TYPE_REALTIME,
            repeat:false
        }
        let timerId = await systemTimer.createTimer(options)
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


## systemTimer.stopTimer

stopTimer(timer: number, callback: AsyncCallback&lt;void&gt;): void

停止定时器。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                         |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| timer    | number                      | 是   | 定时器的ID。                                                 |

**示例：**

  ```js
export default {
    async systemTimer () {
        var options = {
            type: systemTimer.TIMER_TYPE_REALTIME,
            repeat:false
        }
        let timerId = await systemTimer.createTimer(options)
		let triggerTime = new Date().getTime()
        triggerTime += 3000
        systemTimer.startTimer(timerId, triggerTime)
        systemTimer.stopTimer(timerId, (error) => {
            if (error) {
                console.error(`failed to systemTime.startTimer ` + JSON.stringify(error));
                return;
            }
        });
    }
}
  ```


## systemTimer.stopTimer

stopTimer(timer: number): Promise&lt;void&gt;

停止定时器。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名 | 类型    | 必填 | 说明                                                         |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| timer  | number  | 是   | 定时器的ID。                                                 |

**示例：**

  ```js
export default {
    async systemTimer (){
        var options = {
            type: systemTimer.TIMER_TYPE_REALTIME,
            repeat:false
        }
        let timerId = await systemTimer.createTimer(options)
		let triggerTime = new Date().getTime()
        triggerTime += 3000
        systemTimer.startTimer(timerId, triggerTime)
        systemTimer.stopTimer(timerId).then((data) => {
            console.log(`systemTime.startTimer success data : ` + JSON.stringify(data));
        }).catch((error) => {
            console.error(`failed to systemTime.startTimer because ` + JSON.stringify(error));
        });
    }
}
  ```


## systemTimer.destroyTimer

destroyTimer(timer: number, callback: AsyncCallback&lt;void&gt;): void

销毁定时器。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                         |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| timer    | number                      | 是   | 定时器的ID。                                                 |

**示例：**

  ```js
export default {
    async systemTimer () {
        var options = {
            type: systemTimer.TIMER_TYPE_REALTIME,
            repeat:false
        }
        let timerId = await systemTimer.createTimer(options)
		let triggerTime = new Date().getTime()
        triggerTime += 3000
        systemTimer.startTimer(timerId, triggerTime)
        systemTimer.stopTimer(timerId)
        systemTimer.destroyTimer(timerId, (error) => {
            if (error) {
                console.error(`failed to systemTime.startTimer ` + JSON.stringify(error));
                return;
            }
        });
    }
}
  ```


## systemTimer.destroyTimer

destroyTimer(timer: number): Promise&lt;void&gt;

销毁定时器。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名 | 类型    | 必填 | 说明                                                         |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| timer  | number  | 是   | 定时器的ID。                                                 |

**示例：**

  ```js
export default {
    async systemTimer (){
        var options = {
            type: systemTimer.TIMER_TYPE_REALTIME,
            repeat:false
        }
        let timerId = await systemTimer.createTimer(options)
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

createTimer的初始化选项。

**系统能力：** SystemCapability.MiscServices.Time

| 参数名   | 类型              | 必填 | 说明                                                                                                                      |
| -------- | ------------------| ---- | ------------------------------------------------------------------------------------------------------------------------- |
| type     | number            | 是   | const TIMER_TYPE_REALTIME: 设置为系统启动时间定时器(当设置系统时间超过定时器启动时间，定时器则失效)，否则为walltime定时器; <br/>const TIMER_TYPE_WAKEUP: 设置为唤醒定时器，否则为非唤醒; <br/>const TIMER_TYPE_EXACT: 设置为精准定时器，否则为非精准定时器; <br/>const TIMER_TYPE_IDLE: number: 设置为IDLE模式定时器，否则为非IDLE模式定时器（暂不支持） |
| repeat   | boolean           | 是   | true 为循环定时器，false为单次定时器。                                                                                    |
| interval | number            | 否   | 如果是循环定时器，repeat值应大于5000毫秒，非重复定时器置为0。                                                             |
| wantAgent| wantAgent         | 否   | 设置通知的wantagent，定时器到期后通知。(支持拉起应用MainAbility,暂不支持拉起ServiceAbility)                               |
| callback | number            | 是   | 以回调函数的形式返回定时器的ID     |