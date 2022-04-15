# Nonlinear Container PlainArray 

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import PlainArray from '@ohos.util.PlainArray'  
```

## System Capability

SystemCapability.Utils.Lang

## PlainArray


### Attributes

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| length | number | Yes| No| Number of entries in a plain array (called container later).|


### constructor

constructor()

A constructor used to create a **PlainArray** instance.

**Example**

```
let plainArray = new PlainArray();
```


### isEmpty

isEmpty(): boolean

Checks whether this container is empty.

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the container is empty; returns **false** otherwise.|

**Example**

```
const plainArray = new PlainArray();
let result = plainArray.isEmpty();
```


### has

has(key: number): boolean

Checks whether this container contains the specified key.

**Parameters**

| Name| Type | Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | number | Yes| Key to check.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the specified key is contained; returns **false** otherwise.|

**Example**

```
let plainArray = new PlainArray();
plainArray.has(1);
plainArray.add(1, "sddfhf");
let result1 = plainArray.has(1);
```


### get

get(key: number): T

Obtains the value of the specified key in this container.

**Parameters**

| Name| Type | Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | number | Yes| Key to query.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Value of the key.|

**Example**

```
let plainArray = new PlainArray();
plainArray.add(1, "sddfhf");
plainArray.add(2, "sffdfhf");
let result = plainArray.get(1);
```


### getIndexOfKey

getIndexOfKey(key: number): number

Obtains the index of the first occurrence of an entry with the specified key in this container.

**Parameters**

| Name| Type | Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | number | Yes| Key of the entry to obtain.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Returns the position index if obtained; returns **-1** if the specified entry is not found.|

**Example**

```
let plainArray = new PlainArray();
plainArray.add(1, "sddfhf");
plainArray.add(2, "sffdfhf");
let result = plainArray.getIndexOfKey("sdfs");
```


### getIndexOfValue

getIndexOfValue(value: T): number

Obtains the index of the first occurrence of an entry with the specified value in this container.

**Parameters**

| Name| Type | Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | T | Yes| Value of the entry to obtain.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Returns the position index if obtained; returns **-1** if the specified entry is not found.|

**Example**

```
let plainArray = new PlainArray();
plainArray.add(1, "sddfhf");
plainArray.add(2, "sffdfhf");
let result = plainArray.getIndexOfValue("sddfhf");
```


### getKeyAt

getKeyAt(index: number): number

Obtains the key of the entry at the specified position in this container.

**Parameters**

| Name| Type | Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Position index of the entry to obtain.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Returns the key of the entry if obtained; returns **-1** otherwise.|

**Example**

```
let plainArray = new PlainArray();
plainArray.add(1, "sddfhf");
plainArray.add(2, "sffdfhf");
let result = plainArray.getKeyAt(1);
```

### getValueAt

getValueAt(index: number): T

Obtains the value of an entry at the specified position in this container.

**Parameters**

  | Name| Type | Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | index | number | Yes| Position index of the entry to obtain.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | T | Returns the value of the entry if obtained; returns **undefined** otherwise.|

**Example**

  ```
  let plainArray = new PlainArray();
  plainArray.add(1, "sddfhf");
  plainArray.add(2, "sffdfhf");
  let result = plainArray.getKeyAt(1);
  ```

### clone

clone(): PlainArray&lt;T&gt;

Clones this container and returns a copy. The modification to the copy does not affect the original instance.

**Return value**

| Type| Description|
| -------- | -------- |
| PlainArray&lt;T&gt; | New **PlainArray** instance obtained.|

**Example**

```
let plainArray = new PlainArray();
plainArray.add(1, "sddfhf");
plainArray.add(2, "sffdfhf");
let newPlainArray = plainArray.clone();
```


### add

add(key: number, value: T): void

Adds an entry to this container.

**Parameters**

| Name| Type | Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | number | Yes| Key of the entry to add.|
| value | T | Yes| Value of the entry to add.|

**Example**

```
let plainArray = new PlainArray();
plainArray.add(1, "sddfhf");
```


### remove

remove(key: number): T

Removes an entry with the specified key from this container.

**Parameters**

| Name| Type | Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | number | Yes| Key of the entry to remove.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Value of the entry removed.|

**Example**

```
let plainArray = new PlainArray();
plainArray.add(1, "sddfhf");
plainArray.add(2, "sffdfhf");
plainArray.remove(2);
let result = plainArray.remove(2);
```


### removeAt

removeAt(index: number): T

Removes an entry at the specified position from this container.

**Parameters**

| Name| Type | Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Position index of the entry to remove.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Entry removed.|

**Example**

```
let plainArray = new PlainArray();
plainArray.add(1, "sddfhf");
plainArray.add(2, "sffdfhf");
plainArray.removeAt(1);
let result = plainArray.removeAt(1);
```


### removeRangeFrom

removeRangeFrom(index: number, size: number): number

Removes entries in a specified range from this container.

**Parameters**

| Name| Type | Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Start position of the entries to remove.|
| size | number | Yes| Number of entries to remove.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Number of entries removed.|

**Example**

```
let plainArray = new PlainArray();
plainArray.add(1, "sddfhf");
plainArray.add(2, "sffdfhf");
let result = plainArray.removeRangeFrom(1, 3);
```


### setValueAt

setValueAt(index: number, value: T): void

Sets a value for an entry at the specified position in this container.

**Parameters**

| Name| Type | Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Position index of the entry.|
| value | T | Yes| Value of the entry to set.|

**Example**

```
let plainArray = new PlainArray();
plainArray.add(1, "sddfhf");
plainArray.add(2, "sffdfhf");
plainArray.setValueAt(1, 3546);
```


### toString

toString(): String

Obtains a string that contains all entries in this container.

**Return value**

| Type| Description|
| -------- | -------- |
| String | String obtained.|

**Example**

```
let plainArray = new PlainArray();
plainArray.add(1, "sddfhf");
plainArray.add(2, "sffdfhf");
let result = plainArray.toString();
```


### clear

clear(): void

Clears this container and sets its length to **0**.

**Example**

```
let plainArray = new PlainArray();
plainArray.add(1, "sddfhf");
plainArray.add(2, "sffdfhf");
plainArray.clear();
```


### forEach

forEach(callbackfn: (value: T, index?: number, PlainArray?: PlainArray&lt;T&gt;) => void, thisArg?: Object): void

Uses a callback to traverse the entries in this container and obtain their position indexes.

**Parameters**

| Name| Type | Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callbackfn | function | Yes| Callback invoked to traverse the entries in the container.|
| thisArg | Object | No| Value to use when the callback is invoked.|

callbackfn
| Name| Type | Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | T | Yes| Value of the entry that is currently traversed.|
| index | number | No| Key of the entry that is currently traversed.|
| PlainArray | PlainArray&lt;T&gt;| No| Instance that invokes the **forEach** API.|

**Example**

```
let plainArray = new PlainArray();
plainArray.add(1, "sddfhf");
plainArray.add(2, "sffdfhf");
plainArray.forEach((value, key) => {
  console.log(value, key);
});
```


### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;[number, T]&gt;

Obtains an iterator, each item of which is a JavaScript object.

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;[number, T]&gt; | Iterator obtained.|

**Example**

```
let plainArray = new PlainArray();
plainArray.add(1, "sddfhf");
plainArray.add(2, "sffdfhf");

// Method 1:
for (let item of plainArray) { 
  console.log("index: " + item[0]);
  console.log("value: " + item[1]);
}

// Method 2:
let iter = plainArray[Symbol.iterator]();
let temp = iter.next().value;
while(temp != undefined) {
  console.log(temp[0]);
  console.log(temp[1]);
  temp = iter.next().value;
}
```
