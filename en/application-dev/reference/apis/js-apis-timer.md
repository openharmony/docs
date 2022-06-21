# Timer


## setTimeout

## Modules to Import


```
import Time from '@ohos.Time';
```

setTimeout(handler[,delay[,…args]]): number

Sets a timer for the system to call a function after the timer goes off.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| handler | Function | Yes| Function to be called after the timer goes off.|
| delay | number | No| Number of milliseconds delayed before the execution. If this parameter is left empty, the default value **0** is used, which means that the execution starts immediately or as soon as possible.|
| ...args | Array&lt;any&gt; | No| Additional parameters to pass to the handler after the timer goes off.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Timer ID.|

**Example**

```js
export default {    
  setTimeOut() {        
    var timeoutID = setTimeout(function() {            
      console.log('delay 1s');
    }, 1000);    
  }
}
```


## clearTimeout

clearTimeout(timeoutID: number): void

Cancels the timer created via **setTimeout()**.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| timeoutID | number | Yes| ID of the timer to cancel, which is returned by **setTimeout()**|

**Example**

```js
export default {    
  clearTimeOut() {        
    var timeoutID = setTimeout(function() {            
      console.log('do after 1s delay.');        
    }, 1000);        
    clearTimeout(timeoutID);    
  }
}
```


## setInterval

setInterval(handler[, delay[, ...args]]): number

Sets a repeating timer for the system to repeatedly call a function at a fixed interval.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| handler | Function | Yes| Function to be called repeatedly.|
| delay | number | No| Number of milliseconds delayed before the execution.|
| ...args | Array&lt;any&gt; | No| Additional parameters to pass to the handler after the timer goes off.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | ID of the repeating timer.|

**Example**

```js
export default {    
  setInterval() {        
    var intervalID = setInterval(function() {            
      console.log('do very 1s.');        
    }, 1000);    
  }
}
```


## clearInterval

clearInterval(intervalID: number): void

Cancels the repeating timer set via **setInterval()**.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| intervalID | number | Yes| ID of the repeating timer to cancel, which is returned by **setInterval()**.|

**Example**

```js
export default {    
  clearInterval() {        
    var intervalID = setInterval(function() {
      console.log('do very 1s.');
    }, 1000);
    clearInterval(intervalID);
  }
}
```