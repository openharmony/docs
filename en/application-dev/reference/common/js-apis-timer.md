# Timer

The **Timer** module provides basic timer capabilities. You can use the APIs of this module to execute functions at the specified time.

> **NOTE**
>
> The initial APIs of this module are supported since API version 3. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> When a timer is used on the UI, the timer triggering mechanism is controlled by the underlying principles of the UI. As such, when the UI transitions to the background, the timer will be frozen.

## setTimeout

setTimeout(handler: Function | string, delay?: number, ...arguments: any[]): number

Sets a timer for the system to call a function after the timer goes off. 
The timer is automatically deleted after the callback is executed, and can be manually deleted by calling the **clearTimeout** API.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| handler | Function \| string | Yes| Function to be called after the timer goes off. If the type is string, error information is printed and no other processing is performed.|
| delay | number | No| Number of milliseconds delayed before the execution. If this parameter is left empty, the default value **0** is used, which means that the execution starts immediately or as soon as possible.|
| ...arguments | any[] | No| Additional parameters to pass to the handler after the timer goes off.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | ID of the timer. The timer ID is shared by processes and is an integer starting from 0 in ascending order.|

**Example**

  ```ts
  setTimeout(() => {
    console.log('delay 1s');
  }, 1000);
  ```


## clearTimeout

clearTimeout(timeoutID?: number): void

Cancels the repeating timer set via **setTimeout()**.

The timer object is stored in the thread that creates the timer and must be deleted in that thread.

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
