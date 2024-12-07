# Timer

The Timer module provides basic timer capabilities. You can use the APIs of this module to execute functions at the specified time.

> **NOTE**
>
> The initial APIs of this module are supported since API version 3. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> When a timer is used on the UI, the timer triggering mechanism is controlled by the underlying principles of the UI. As such, when the UI transitions to the background, the timer will be frozen.

## setTimeout

setTimeout(handler: Function | string, delay?: number, ...arguments: any[]): number

Sets a timer for the system to call a function after the timer goes off.

The timer is automatically deleted after the callback is executed, and can be manually deleted by calling the **clearTimeout** API.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| handler | Function \| string | Yes| Function to be called after the timer goes off. If the type is string, error information is printed and no other processing is performed.|
| delay | number | No| Number of milliseconds delayed before the execution. It is recommended that an integer be passed in. A decimal will be rounded down.<br>If this parameter is not specified, the default value 0 is used, indicating that the function is executed immediately (in the next event loop).<br>NOTE<br>1. In either case, the actual delay may be longer than expected.<br>2. If a value less than 1 is passed, the default value 0 is used.|
| ...arguments | any[] | No| Additional parameters to pass to the handler after the timer goes off.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | ID of the timer. The timer ID is shared by processes and is an integer starting from 0 in ascending order.|

**Example 1: carrying no parameters**

  ```ts
  setTimeout(() => {
    console.info('delay 1s');
  }, 1000);
  ```

**Example 2: carrying parameters**

  ```ts
  function myFunction(param1: string, param2: string) {
    console.info(param1, param2);
  }
  setTimeout(myFunction, 1000, 'Hello', 'World');
  ```

## clearTimeout

clearTimeout(timeoutID?: number): void

Cancels a timer set via **setTimeout()**.

The timer object is stored in the thread that creates the timer and must be deleted in that thread.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| timeoutID | number | No| ID of the timer to cancel, which is returned by **setTimeout()** If this parameter is omitted, no timer is canceled.|

**Example**

  ```js
  let timeoutID = setTimeout(() => {
    console.log('do after 1s delay.');
  }, 1000);
  clearTimeout(timeoutID);
  ```


## setInterval

setInterval(handler: Function | string, delay: number, ...arguments: any[]): number

Sets a repeating timer for the system to repeatedly call a function at a fixed interval.

The timer can only be manually deleted by calling the **clearInterval** API.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| handler | Function \| string | Yes| Function to be called repeatedly. If the type is string, error information is printed and no other processing is performed.|
| delay | number | Yes| Number of milliseconds delayed before the execution.|
| ...arguments | any[] | No| Additional parameters to pass to the handler after the timer goes off.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | ID of the timer. The timer ID is shared by processes and is an integer starting from 0 in ascending order.|

**Example**

  ```js
  setInterval(() => {
    console.log('do every 1s.');
  }, 1000);
  ```


## clearInterval

clearInterval(intervalID?: number): void

Cancels the repeating timer set via **setInterval()**.

The timer object is stored in the thread that creates the timer and must be deleted in that thread.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| intervalID | number | No| ID of the repeating timer to cancel, which is returned by **setInterval()**. If this parameter is omitted, no timer is canceled.|

**Example**

  ```js
  let intervalID = setInterval(() => {
    console.log('do every 1s.');
  }, 1000);
  clearInterval(intervalID);
  ```

## Other Description
### Timeout Delay
If the page is engaged in other operations, the timeout may be later than expected. The function or code snippet passed to **setTimeout** is executed in the next time period. Example:
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
Although a 0 ms delay is specified for **setTimeout**, the task is not executed immediately. Instead, it is placed in the queue and waits for the next event loop. The functions in the queue can be executed only after the ongoing code execution is complete. As such, the final execution sequence may be different from that expected.

### Maximum Delay
The timer internally stores the delay as a 32-bit signed integer. If the delay is greater than 2147483647 ms (about 24.8 days), overflow occurs, and the timer is executed immediately.

### Timer Suspension
The timer triggering mechanism is controlled by the bottom-layer task scheduling. If an application is switched to the background, timers that have reached their set time will not be triggered. Once the application is restored to the foreground, the expired timers will be triggered in sequence. You can run the **trace** command to check whether a process is still scheduled. If the process is not scheduled, the timer is suspended.

### Timer ID
The **setTimeout()** and **setInterval()** APIs shares an ID pool, which means that, in theory, **clearTimeout()** and **clearInterval()** can be interchanged. However, to maintain clarity in coding practices, it is advised to avoid such intermixing.
