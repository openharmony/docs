# Linear Container Stack

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import Stack from '@ohos.util.Stack'  
```

## System Capabilities

SystemCapability.Utils.Lang


## Stack


### Attributes

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| length | number | Yes| No| Number of entries in a stack (called container later).|


### constructor

constructor()

A constructor used to create a **Stack** instance.

**Example**

```
let stack = new Stack();
```


### push

push(item: T): T

Adds an entry at the top of this container.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| item | T | Yes| Element to add.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Element added.|

**Example**

```
let stack = new Stack();
let result = stack.push("a");
let result1 = stack.push(1);
let b = [1, 2, 3];
stack.push(b);
let c = {name : "lala", age : "13"};
let result3 = stack.push(c);
```

### pop

pop(): T

Removes the top entry from this container.

**Return value**

| Type| Description|
| -------- | -------- |
| T | Entry removed.|

**Example**

```
let stack = new Stack();
stack.push(2);
stack.push(4);
stack.push(5);
stack.push(2);
stack.push(4);
let result = stack.pop();
```

### peek

peek(): T

Obtains the top entry of this container.

**Return value**

| Type| Description|
| -------- | -------- |
| T | Entry obtained.|

**Example**

```
let stack = new Stack();
stack.push(2);
stack.push(4);
stack.push(5);
stack.push(2);
let result = stack.peek();
```

### locate

locate(element: T): number

Obtains the index of the first occurrence of the specified entry in this container.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| element | T | Yes| Entry to query.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Returns the position index if obtained; returns **-1** if the specified entry is not found.|

**Example**

```
let stack = new Stack();
stack.push(2);
stack.push(4);
stack.push(5);
stack.push(2);
let result = stack.locate(2);
```

### forEach

forEach(callbackfn: (value: T, index?: number, stack?: Stack&lt;T&gt;) => void,
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
| stack | Stack&lt;T&gt; | No| Instance that invokes the **forEach** method.|

**Example**

```
let stack = new Stack();
stack.push(2);
stack.push(4);
stack.push(5);
stack.push(4);
stack.forEach((value, index) => {
 console.log(value, index);
});
```

### isEmpty

isEmpty(): boolean

Checks whether this container is empty (contains no entries).

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the container is empty; returns **false** otherwise.|

**Example**

```
let stack = new Stack();
stack.push(2);
stack.push(4);
stack.push(5);
stack.push(4);
let result = stack.isEmpty();
```

### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;T&gt;


Obtains an iterator, each item of which is a JavaScript object.

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;T&gt; | Iterator obtained.|

**Example**
```
let stack = new Stack();
stack.push(2);
stack.push(4);
stack.push(5);
stack.push(4);

// Method 1:
for (let item of stack) { 
  console.log(item); 
}

// Method 2:
let iter = stack[Symbol.iterator]();
let temp = iter.next().value;
while(temp != undefined) {
  console.log(temp);
  temp = iter.next().value;
}
```
