# 设置系统定时器

本模块主要由时间、时区和定时三大功能组成。其中，定时服务用来管理和使用时间、时区。开发者可以通过对系统进行设置、获取等操作管理系统时间、时区，也可以通过定时功能实现定时服务如闹钟服务等。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
>- 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>- 本模块接口为系统接口，三方应用不支持调用。

## 导入模块


```
import systemTimer from '@ohos.systemTimer';
```


## systemTime.createTimer

createTimer(options: TimerOptions, callback: AsyncCallback&lt;number&gt;): void

创建定时器。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名   | 类型              | 必填 | 说明                                                                                    |
| -------- | ------------------| ---- | --------------------------------------------------------------------------------------- |
| options  | TimerOptions      | 是   | const TIMER_TYPE_REALTIME: 设置为系统启动时间定时器，否则为walltime定时器; <br/>const TIMER_TYPE_WAKEUP: 设置为唤醒定时器，否则为非唤醒; <br/>const TIMER_TYPE_EXACT: 设置为精准定时器，否则为非精准定时器; <br/>const TIMER_TYPE_IDLE: number: 设置为IDLE模式定时器，否则为非IDLE模式定时器（暂不支持） |
| repeat   | boolean           | 是   | true 为循环定时器，false为单次定时器。                                                  |
| interval | number            | 否   | 如果是循环定时器，repeat值应大于5000毫秒，非重复定时器置为0。                           |
| wantAgent| wantAgent         | 否   | 设置通知的wantagent，定时器到期后通知。(支持拉起鸿蒙应用MainAbility,暂不支持拉起SA)     |

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


## systemTime.createTimer

createTimer(options: TimerOptions): Promise&lt;number&gt;

创建定时器。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名   | 类型              | 必填 | 说明                                                                                    |
| -------- | ------------------| ---- | --------------------------------------------------------------------------------------- |
| options  | TimerOptions      | 是   | const TIMER_TYPE_REALTIME: 设置为系统启动时间定时器，否则为walltime定时器; <br/>const TIMER_TYPE_WAKEUP: 设置为唤醒定时器，否则为非唤醒; <br/>const TIMER_TYPE_EXACT: 设置为精准定时器，否则为非精准定时器; <br/>const TIMER_TYPE_IDLE: number: 设置为IDLE模式定时器，否则为非IDLE模式定时器（暂不支持） |
| repeat   | boolean           | 是   | true 为循环定时器，false为单次定时器。                                                  |
| interval | number            | 否   | 如果是循环定时器，repeat值应大于5000毫秒，非重复定时器置为0。                           |
| wantAgent| wantAgent         | 否   | 设置通知的wantagent，定时器到期后通知。(支持拉起鸿蒙应用MainAbility,暂不支持拉起SA)     |

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


## systemTime.startTimer

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
    systemTimer () {
        var options = {
            type: systemTimer.TIMER_TYPE_REALTIME,
            repeat:false
        }
        let timerId = systemTimer.Timer(options)
        systemTimer.startTimer(timerId, 10000, (error, data) => {
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
    systemTimer (){
        var options = {
            type: systemTimer.TIMER_TYPE_REALTIME,
            repeat:false
        }
        let timerId = systemTimer.Timer(options)
        systemTimer.startTimer(timerId, 10000).then((data) => {
            console.log(`systemTime.startTimer success data : ` + JSON.stringify(data));
        }).catch((error) => {
            console.error(`failed to systemTime.startTimer because ` + JSON.stringify(error));
        });
    }
}
  ```


## systemTime.stopTimer

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
    systemTimer () {
        var options = {
            type: systemTimer.TIMER_TYPE_REALTIME,
            repeat:false
        }
        let timerId = systemTimer.Timer(options)
        systemTimer.startTimer(timerId, 100000)
        systemTimer.stoptTimer(timerId, 10000, (error, data) => {
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

停止定时器。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名 | 类型    | 必填 | 说明                                                         |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| timer  | number  | 是   | 定时器的ID。                                                 |                                                                                                                      

**示例：**

  ```js
export default {
    systemTimer (){
        var options = {
            type: systemTimer.TIMER_TYPE_REALTIME,
            repeat:false
        }
        let timerId = systemTimer.Timer(options)
        systemTimer.startTimer(timerId, 100000)
        systemTimer.stoptTimer(timerId, 10000).then((data) => {
            console.log(`systemTime.startTimer success data : ` + JSON.stringify(data));
        }).catch((error) => {
            console.error(`failed to systemTime.startTimer because ` + JSON.stringify(error));
        });
    }
}
  ```


## systemTime.destroyTimer

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
    systemTimer () {
        var options = {
            type: systemTimer.TIMER_TYPE_REALTIME,
            repeat:false
        }
        let timerId = systemTimer.Timer(options)
        systemTimer.startTimer(timerId, 100000)
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

销毁定时器。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名 | 类型    | 必填 | 说明                                                         |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| timer  | number  | 是   | 定时器的ID。                                                 |

**示例：**

  ```js
export default {
    systemTimer (){
        var options = {
            type: systemTimer.TIMER_TYPE_REALTIME,
            repeat:false
        }
        let timerId = systemTimer.Timer(options)
        systemTimer.startTimer(timerId, 100000)
        systemTimer.stopTimer(timerId)
        systemTimer.destroytTimer(timerId, 10000).then((data) => {
            console.log(`systemTime.startTimer success data : ` + JSON.stringify(data));
        }).catch((error) => {
            console.error(`failed to systemTime.startTimer because ` + JSON.stringify(error));
        });
    }
}
  ```