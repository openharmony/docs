# Timer (定时器)

本模块提供基础的定时器能力，支持按照指定的时间执行对应函数。

> **说明：**
>
> 本模块首批接口从API version 3开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## setTimeout

setTimeout(handler: Function | string, delay?: number, ...arguments: any[]): number

设置一个定时器，该定时器在定时器到期后执行一个函数。  
该定时器在回调被执行后自动删除，或使用clearTimeout接口手动删除。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| handler | Function \| string | 是 | 定时器到期后执行函数。类型为string则打印Error信息，不进行其他处理。 |
| delay | number | 否 | 延迟的毫秒数，函数的调用会在该延迟之后发生。如果省略该参数，delay取默认值0，意味着“马上”执行，或尽快执行。 |
| ...arguments | any[] | 否 | 附加参数，一旦定时器到期，它们会作为参数传递给handler。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 该定时器的ID，为整数。 |

**示例：**

  ```js
  setTimeout(function() {            
    console.log('delay 1s');
  }, 1000);
  ```


## clearTimeout

clearTimeout(timeoutID?: number): void

可取消通过调用setTimeout()建立的定时器。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| timeoutID | number | 否 | 要取消定时器的ID，&nbsp;是由setTimeout()返回的。如果省略该参数，则不取消任何定时任务，无任何处理。|

**示例：**

  ```js    
  let timeoutID = setTimeout(function() {            
    console.log('do after 1s delay.');        
  }, 1000);        
  clearTimeout(timeoutID);
  ```


## setInterval

setInterval(handler: Function | string, delay: number, ...arguments: any[]): number

重复调用一个函数，在每次调用之间具有固定的时间延迟。  
删除该定时器需手动调用clearInterval接口。

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
| number | 该定时器的ID，为整数。 |

**示例：**

  ```js
  setInterval(function() {            
    console.log('do every 1s.');        
  }, 1000);
  ```


## clearInterval

clearInterval(intervalID?: number): void

可取消通过setInterval()设置的重复定时任务。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| intervalID | number | 否 | 要取消的重复定时器的ID，是由&nbsp;setInterval()&nbsp;返回的。如果省略该参数，则不取消任何定时任务，无任何处理。|

**示例：**

  ```js      
  let intervalID = setInterval(function() {
    console.log('do every 1s.');
  }, 1000);
  clearInterval(intervalID);
  ```
