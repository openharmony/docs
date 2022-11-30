# 系统定时器

本模块主要由系统定时器功能组成。开发者可以使用定时功能实现定时服务，如闹钟等。

> **说明：**
>
> - 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块接口为系统接口。

## 导入模块


```js
import systemTimer from '@ohos.systemTimer';
```

## 常量

支持创建的定时器类型。

| 名称                | 类型   | 值   | 说明                         |
| ------------------- | ------ | ---- | ---------------------------- |
| TIMER_TYPE_REALTIME | number | 1    | 系统启动时间定时器。（定时器启动时间不能晚于当前设置的系统时间）         |
| TIMER_TYPE_WAKEUP   | number | 2    | 唤醒定时器。                 |
| TIMER_TYPE_EXACT    | number | 4    | 精准定时器。                 |
| TIMER_TYPE_IDLE     | number | 8    | IDLE模式定时器（暂不支持）。 |

 ## TimerOptions

创建系统定时器的初始化选项。

**系统能力：** SystemCapability.MiscServices.Time

| 名称      | 类型                              | 必填 | 说明                                                         |
| --------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| type      | number                            | 是   | 定时器类型。<br>取值为1时，表示为系统启动时间定时器（定时器启动时间不能晚于当前设置的系统时间） ；<br>取值为2时，表示为唤醒定时器；<br>取值为4时，表示为精准定时器；<br>取值为5时，表示为IDLE模式定时器（暂不支持）。 |
| repeat    | boolean                           | 是   | true为循环定时器，false为单次定时器。                        |
| interval  | number                            | 否   | 如果是循环定时器，repeat值应大于5000毫秒，非重复定时器置为0。 |
| wantAgent | [WantAgent](js-apis-wantAgent.md) | 否   | 设置通知的WantAgent，定时器到期后通知。（支持拉起应用MainAbility，暂不支持拉起ServiceAbility。） |
| callback  | number                            | 是   | 以回调函数的形式返回定时器的ID。                             |


## systemTimer.createTimer

createTimer(options: TimerOptions, callback: AsyncCallback&lt;number&gt;): void

创建定时器，使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名   | 类型                          | 必填 | 说明                                                         |
| -------- | ----------------------------- | ---- | ------------------------------------------------------------ |
| options  | [TimerOptions](#timeroptions) | 是   | 创建系统定时器的初始化选项，包括定时器类型、是否循环触发、间隔时间、WantAgent通知机制等。 |
| callback | AsyncCallback&lt;number>      | 是   | 回调函数，返回定时器的ID。                                   |

**示例：**

```js
export default {
    systemTimer () {
        let options = {
            type: systemTimer.TIMER_TYPE_REALTIME,
            repeat: false
        };
        systemTimer.createTimer(options, (error, data) => {
            if (error) {
                console.error(`Failed to create timer. Cause:` + JSON.stringify(error));
                return;
            }
            console.log(`Succeeded in creating timer. Data:` + JSON.stringify(data));
        });
    }
}
```

## systemTimer.createTimer

createTimer(options: TimerOptions): Promise&lt;number&gt;

创建定时器，使用Promise异步回调。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名  | 类型                          | 必填 | 说明                                                         |
| ------- | ----------------------------- | ---- | ------------------------------------------------------------ |
| options | [TimerOptions](#timeroptions) | 是   | 创建系统定时器的初始化选项，包括定时器类型、是否循环触发、间隔时间、WantAgent通知机制等。 |

**返回值：**

| 类型                  | 说明                          |
| --------------------- | ----------------------------- |
| Promise&lt;number&gt; | Promise对象，返回定时器的ID。 |

**示例：**

```js
export default {
    systemTimer () {
        let options = {
            type: systemTimer.TIMER_TYPE_REALTIME,
            repeat:false
        };
        systemTimer.createTimer(options).then((data) => {
            console.log(`Succeeded in creating timer. Data:` + JSON.stringify(data));
        }).catch((error) => {
            console.error(`Failed to create timer. Cause:` + JSON.stringify(error));
        });
    }
}
```

## systemTimer.startTimer

startTimer(timer: number, triggerTime: number, callback: AsyncCallback&lt;void&gt;): void

开始定时器，使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名      | 类型                   | 必填 | 说明                           |
| ----------- | ---------------------- | ---- | ------------------------------ |
| timer       | number                 | 是   | 定时器的ID。                   |
| triggerTime | number                 | 是   | 定时器的触发时间，单位：毫秒。 |
| callback    | AsyncCallback&lt;void> | 是   | 回调函数。                     |

**示例：**

```js
export default {
    async systemTimer () {
        let options = {
            type: systemTimer.TIMER_TYPE_REALTIME,
            repeat:false
        }
      let timerId = await systemTimer.createTimer(options)
  	  let triggerTime = new Date().getTime()
      triggerTime += 3000
      systemTimer.startTimer(timerId, triggerTime, (error, data) => {
          if (error) {
              console.error(`Failed to start timer. Cause:` + JSON.stringify(error));
              return;
          }
          console.log(`Succeeded in startting timer. Data:` + JSON.stringify(data));
      });
    }
}
```

## systemTimer.startTimer

startTimer(timer: number, triggerTime: number): Promise&lt;void&gt;

开始定时器，使用Promise异步回调。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名      | 类型   | 必填 | 说明                           |
| ----------- | ------ | ---- | ------------------------------ |
| timer       | number | 是   | 定时器的ID。                   |
| triggerTime | number | 是   | 定时器的触发时间，单位：毫秒。 |

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**示例：**

```js
export default {
    async systemTimer (){
        let options = {
            type: systemTimer.TIMER_TYPE_REALTIME,
            repeat:false
        }
        let timerId = await systemTimer.createTimer(options)
        let triggerTime = new Date().getTime()
        triggerTime += 3000
        systemTimer.startTimer(timerId, triggerTime).then((data) => {
            console.log(`Succeeded in startting timer. Data:` + JSON.stringify(data));
        }).catch((error) => {
            console.error(`Failed to start timer. Cause:` + JSON.stringify(error));
        });
    }
}
```

## systemTimer.stopTimer

stopTimer(timer: number, callback: AsyncCallback&lt;void&gt;): void

停止定时器，使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名   | 类型                   | 必填 | 说明         |
| -------- | ---------------------- | ---- | ------------ |
| timer    | number                 | 是   | 定时器的ID。 |
| callback | AsyncCallback&lt;void> | 是   | 回调函数。   |

**示例：**

```js
export default {
  async systemTimer () {
      let options = {
          type: systemTimer.TIMER_TYPE_REALTIME,
          repeat:false
      }
      let timerId = await systemTimer.createTimer(options)
  	let triggerTime = new Date().getTime()
      triggerTime += 3000
      systemTimer.startTimer(timerId, triggerTime)
      systemTimer.stopTimer(timerId, (error) => {
          if (error) {
              console.error(`Failed to stop timer. Cause:` + JSON.stringify(error));
              return;
          }
      });
  }
}
```

## systemTimer.stopTimer

stopTimer(timer: number): Promise&lt;void&gt;

停止定时器，使用Promise异步回调。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名 | 类型   | 必填 | 说明         |
| ------ | ------ | ---- | ------------ |
| timer  | number | 是   | 定时器的ID。 |

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**示例：**

```js
export default {
  async systemTimer (){
      let options = {
          type: systemTimer.TIMER_TYPE_REALTIME,
          repeat:false
      }
      let timerId = await systemTimer.createTimer(options)
  	let triggerTime = new Date().getTime()
      triggerTime += 3000
      systemTimer.startTimer(timerId, triggerTime)
      systemTimer.stopTimer(timerId).then((data) => {
          console.log(`Succeeded in stopping timer. Data:` + JSON.stringify(data));
      }).catch((error) => {
          console.error(`Failed to stop timer. Cause:` + JSON.stringify(error));
      });
  }
}
```

## systemTimer.destroyTimer

destroyTimer(timer: number, callback: AsyncCallback&lt;void&gt;): void

销毁定时器，使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名   | 类型                   | 必填 | 说明         |
| -------- | ---------------------- | ---- | ------------ |
| timer    | number                 | 是   | 定时器的ID。 |
| callback | AsyncCallback&lt;void> | 是   | 回调函数。   |

**示例：**

```js
export default {
    async systemTimer () {
        let options = {
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
                console.error(`Failed to destroy timer. Cause:` + JSON.stringify(error));
                return;
            }
        });
    }
}
```

## systemTimer.destroyTimer

destroyTimer(timer: number): Promise&lt;void&gt;

销毁定时器，使用Promise异步回调。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名 | 类型   | 必填 | 说明         |
| ------ | ------ | ---- | ------------ |
| timer  | number | 是   | 定时器的ID。 |

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**示例：**

```js
export default {
    async systemTimer (){
        let options = {
            type: systemTimer.TIMER_TYPE_REALTIME,
            repeat:false
        }
        let timerId = await systemTimer.createTimer(options)
        let triggerTime = new Date().getTime()
        triggerTime += 3000
        systemTimer.startTimer(timerId, triggerTime)
        systemTimer.stopTimer(timerId)
        systemTimer.destroyTimer(timerId, 10000).then((data) => {
            console.log(`Succeeded in destroying timer. Data:` + JSON.stringify(data));
        }).catch((error) => {
            console.error(`Failed to destroy timer. Cause:` + JSON.stringify(error));
        });
    }
}
```