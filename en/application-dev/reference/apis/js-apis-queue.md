# Linear Container Queue

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import Queue from '@ohos.util.Queue';  
```

## System Capabilities

SystemCapability.Utils.Lang


## Queue


### Attributes

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| length | number | Yes| No| Number of entries in a queue (called container later).|


### constructor

constructor()

A constructor used to create a **Queue** instance.

**Example**

```ts
let queue = new Queue();
```


### add

add(element: T): boolean

Adds an entry at the end of this container.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| element | T | Yes| Entry to add.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the entry is added successfully; returns **false** otherwise.|

**Example**

```ts
let queue = new Queue();
let result = queue.add("a");
let result1 = queue.add(1);
queue.add(1);
let b = [1, 2, 3];
queue.add(b);
let c = {name : "lala", age : "13"};
let result3 = queue.add(c);
```

### pop

pop(): T

Removes the first entry from this container.

**Return value**

| Type| Description|
| -------- | -------- |
| T | Entry removed.|

**Example**

```ts
let queue = new Queue();
queue.add(2);
queue.add(4);
queue.add(5);
queue.add(2);
queue.add(4);
let result = queue.pop();
```

### getFirst

getFirst(): T

Obtains the first entry of this container.

**Parameters**

| Type| Description|
| -------- | -------- |
| T | The first entry obtained.|

**Example**

```ts
let queue = new Queue();
queue.add(2);
queue.add(4);
queue.add(5);
queue.add(2);
let result = queue.getFirst();
```

### forEach

forEach(callbackfn: (value: T, index?: number, Queue?: Queue&lt;T&gt;) => void,
thisArg?: Object): void

Uses a callback to traverse the entries in this container and obtain their position indexes.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callbackfn | function | Yes| Callback invoked to traverse the entries in the container.|
| thisArg | Object | No| Value to use when the callback is invoked.|

callbackfn

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | T | Yes| Value of the entry that is currently traversed.|
| index | number | No| Position index of the entry that is currently traversed.|
| Queue | Queue&lt;T&gt; | No| Instance that invokes the **forEach** method.|

**Example**

```ts
let queue = new Queue();
queue.add(2);
queue.add(4);
queue.add(5);
queue.add(4);
queue.forEach((value, index) => {
  console.log("value:" + value, index);
});

```

### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;T&gt;


Obtains an iterator, each item of which is a JavaScript object.

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;T&gt; | Iterator obtained.|

**Example**
```ts
let queue = new Queue();
queue.add(2);
queue.add(4);
queue.add(5);
queue.add(4);

// Method 1:
for (let item of queue) { 
  console.log("value:" + item); 
}

// Method 2:
let iter = queue[Symbol.iterator]();
let temp = iter.next().value;
while(temp != undefined) {
  console.log("value:" + temp);
  temp = iter.next().value;
}
```
