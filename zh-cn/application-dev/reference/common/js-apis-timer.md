# Timer (定时器)

本模块提供基础的定时器能力，支持按照指定的时间执行对应函数。

> **说明：**
>
> 本模块首批接口从API version 3开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 开发者在UI界面中使用定时器时，定时器的触发机制会受UI底层原理管控，如果UI界面退到后台，定时器会被冻结。

## setTimeout

setTimeout(handler: Function | string, delay?: number, ...arguments: any[]): number

设置一个定时器，该定时器在定时器到期后执行一个函数。  
该定时器在回调被执行后自动删除，或使用clearTimeout接口手动删除。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| handler | Function \| string | 是 | 定时器到期后执行函数。类型为string则打印Error信息，不进行其他处理。 |
| delay | number | 否 | 延迟的毫秒数，函数的调用会在该延迟之后发生。建议整数，若传入小数，会被向下取整。<br>如果省略该参数，delay取默认值0，意味着“马上”执行，更准确的说，在下一个事件循环执行。<br>注意：<br>1. 无论是哪种情况，实际延迟可能会比预期长一些。<br>2. 如果值小于1，会被默认取0。 |
| ...arguments | any[] | 否 | 附加参数，一旦定时器到期，它们会作为参数传递给handler。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 该定时器的ID，定时器ID为进程共享，是从0开始顺序增加的整数，无重复值。 |

**示例1：不带参数**

  ```ts
  setTimeout(() => {
    console.info('delay 1s');
  }, 1000);
  ```

**示例2：带参数传递给函数**

  ```ts
  function myFunction(param1: string, param2: string) {
    console.info(param1, param2);
  }
  setTimeout(myFunction, 1000, 'Hello', 'World');
  ```

## clearTimeout

clearTimeout(timeoutID?: number): void

可取消通过调用setTimeout()建立的定时器。

定时器对象保存在创建它的线程内，删除定时器需要在创建该定时器的线程删除。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| timeoutID | number | 否 | 要取消定时器的ID，&nbsp;是由setTimeout()返回的。如果省略该参数，则不取消任何定时任务，无任何处理。|

**示例：**

  ```js
  let timeoutID = setTimeout(() => {
    console.log('do after 1s delay.');
  }, 1000);
  clearTimeout(timeoutID);
  ```


## setInterval

setInterval(handler: Function | string, delay: number, ...arguments: any[]): number

重复调用一个函数，在每次调用之间具有固定的时间延迟。
删除该定时器需手动调用clearInterval接口。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| handler | Function \| string | 是 | 要重复调用的函数。类型为string则打印Error信息，不进行其他处理。|
| delay | number | 是 | 延迟的毫秒数，函数的调用会在该延迟之后发生。 |
| ...arguments | any[] | 否 | 附加参数，一旦定时器到期，他们会作为参数传递给handler。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 该定时器的ID，定时器ID为进程共享，是从0开始顺序增加的整数，无重复值。 |

**示例：**

  ```js
  setInterval(() => {
    console.log('do every 1s.');
  }, 1000);
  ```


## clearInterval

clearInterval(intervalID?: number): void

可取消通过setInterval()设置的重复定时任务。

定时器对象保存在创建它的线程内，删除定时器需要在创建该定时器的线程删除。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| intervalID | number | 否 | 要取消的重复定时器的ID，是由&nbsp;setInterval()&nbsp;返回的。如果省略该参数，则不取消任何定时任务，无任何处理。|

**示例：**

  ```js
  let intervalID = setInterval(() => {
    console.log('do every 1s.');
  }, 1000);
  clearInterval(intervalID);
  ```

## 其他说明
### 超时延迟
如果页面正忙于其他任务，超时也可能比预期的晚。setTimeout的函数或代码片段是在下一个时间周期执行的。例如：
  ```ts
  function foo() {
    console.info('OH test foo is called')
  }
  setTimeout(foo, 0);
  console.info('After OH test setTimeout')

  // output
  After OH test setTimeout
  OH test foo is called
  ```
这是因为，虽然setTimeout设置了0ms的延迟，但任务不是立即执行，而是会被放入队列中，等待下一次事件循环执行。当前正在执行的代码必须先完成，队列中的函数才会被执行，因此最终的执行顺序可能和预期不一致。

### 最大延迟值
timer内部以32位带符号整数存储延时，这就会导致如果一个延时大于2147483647毫秒（大约24.8天）时就会溢出，导致定时器将会被立即执行。

### 定时器冻结
定时器的触发受底层任务调度。当前应用被切换到后台后，定时器到期也不会触发。应用被重新拉起到前台后，到期定时器会按序触发。可使用trace查看进程是否还存在调度，如果没有调度，则定时器被冻结。

### 定时器ID
setTimeout()和setInterval()使用共享的ID池，意味着在技术上可以混用clearTimeout()和clearInterval()。但出于代码清晰性考虑，我们应该避免混用它们。