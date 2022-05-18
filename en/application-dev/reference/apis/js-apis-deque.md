# Linear Container Deque

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import Deque from '@ohos.util.Deque'; 
```

## System Capabilities

SystemCapability.Utils.Lang

## Deque

### Attributes

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| length | number | Yes| No| Number of entries in a double-ended queue (deque, called container later).|

### constructor

constructor()

A constructor used to create a **Deque** instance.

**Example**

```ts
let deque = new Deque();
```

### insertFront

insertFront(element: T): void

Inserts an entry at the front of this container.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| element | T | Yes| Entry to insert.|

**Example**

```ts
let deque = new Deque();
deque.insertFront("a");
deque.insertFront(1);
let b = [1, 2, 3];
deque.insertFront(b);
let c = {name : "lala", age : "13"};
deque.insertFront(false);
```

### insertEnd

insertEnd(element: T): void

Inserts an entry at the end of this container.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| element | T | Yes| Entry to insert.|

**Example**

```ts
let deque = new Deque();
deque.insertEnd("a");
deque.insertEnd(1);
let b = [1, 2, 3];
deque.insertEnd(b);
let c = {name : "lala", age : "13"};
deque.insertEnd(false);
```

### has

has(element: T): boolean

Checks whether this container has the specified entry.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| element | T | Yes| Entry to check.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the specified entry is contained; returns **false** otherwise.|

**Example**

```ts
let deque = new Deque();
let result = deque.has("Ahfbrgrbgnutfodgorrogorg");
deque.insertFront("Ahfbrgrbgnutfodgorrogorg");
let result1 = deque.has("Ahfbrgrbgnutfodgorrogorg");
```

### popFirst

popFirst(): T

Removes the first entry of this container.

**Return value**

| Type| Description|
| -------- | -------- |
| T | Entry removed.|

**Example**

```ts
let deque = new Deque();
deque.insertFront(2);
deque.insertFront(4);
deque.insertEnd(5);
deque.insertFront(2);
deque.insertFront(4);
let result = deque.popFirst();
```

### popLast

popLast(): T

Removes the last entry of this container.

**Return value**

| Type| Description|
| -------- | -------- |
| T | Entry removed.|

**Example**

```ts
let deque = new Deque();
deque.insertFront(2);
deque.insertEnd(4);
deque.insertFront(5);
deque.insertFront(2);
deque.insertFront(4);
let result = deque.popLast();
```

### forEach

forEach(callbackfn: (value: T, index?: number, deque?: Deque&lt;T&gt;) => void,
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
| value | T | Yes| Value of the element that is currently traversed.|
| index | number | No| Position index of the entry that is currently traversed.|
| deque | Deque&lt;T&gt; | No| Instance that invokes the **forEach** method.|

**Example**

```ts
let deque = new Deque();
deque.insertFront(2);
deque.insertEnd(4);
deque.insertFront(5);
deque.insertEnd(4);
deque.forEach((value, index) => {
  console.log("value:" + value, index);
});
```

### getFirst

getFirst(): T

Obtains the first entry of this container.

**Return value**

| Type| Description|
| -------- | -------- |
| T | Entry obtained.|

**Example**

```ts
let deque = new Deque();
deque.insertEnd(2);
deque.insertEnd(4);
deque.insertFront(5);
deque.insertFront(4);
let result = deque.getFirst();
```

### getLast

getLast(): T

Obtains the last entry of this container.

**Return value**

| Type| Description|
| -------- | -------- |
| T | Entry obtained.|

**Example**

```ts
let deque = new Deque();
deque.insertFront(2);
deque.insertFront(4);
deque.insertFront(5);
deque.insertFront(4);
let result = deque.getLast();
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
let deque = new Deque();
deque.insertFront(2);
deque.insertFront(4);
deque.insertFront(5);
deque.insertFront(4);

// Method 1:
for (let item of deque) { 
  console.log("value:" + item); 
}

// Method 2:
let iter = deque[Symbol.iterator]();
let temp = iter.next().value;
while(temp != undefined) {
  console.log("value:" + temp);
  temp = iter.next().value;
}
```
