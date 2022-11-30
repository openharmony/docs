# Nonlinear Container PlainArray 

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

**PlainArray** stores key-value (KV) pairs. Each key must be unique, be of the number type, and have only one value.

**PlainArray** is based on generics and uses a lightweight structure. Keys in the array are searched using binary search and are mapped to values in other arrays.

Both **PlainArray** and **[LightWeightMap](js-apis-lightweightmap.md)** are used to store KV pairs in the lightweight structure. However, the key type of **PlainArray** can only be **number**.

**Recommended use case**: Use **PlainArray** when you need to store KV pairs whose keys are of the **number** type.

This topic uses the following to identify the use of generics:
- T: Type

## Modules to Import

```ts
import PlainArray from '@ohos.util.PlainArray';  
```



## PlainArray

### Attributes

**System capability**: SystemCapability.Utils.Lang

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| length | number | Yes| No| Number of elements in a plain array (called container later).|


### constructor

constructor()

A constructor used to create a **PlainArray** instance.

**System capability**: SystemCapability.Utils.Lang

**Error codes**

For details about the error codes, see [containers Error Codes](../errorcodes/errorcode-containers.md).

| ID| Error Message|
| -------- | -------- |
| 10200012 | The PlainArray's constructor cannot be directly invoked. |

**Example**

```ts
let plainArray = new PlainArray();
try {
  let plainArray2 = PlainArray();
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```


### isEmpty

isEmpty(): boolean

Checks whether this container is empty.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the container is empty; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [containers Error Codes](../errorcodes/errorcode-containers.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The isEmpty method cannot be bound. |

**Example**

```ts
const plainArray = new PlainArray();
let result = plainArray.isEmpty();
try {
  plainArray.isEmpty.bind({})(); // bind() creates a new bound function that, when called, has its this keyword set to the provided value. It is used to test exception capture.
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```


### has

has(key: number): boolean

Checks whether this container contains the specified key.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type | Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | number | Yes| Target key.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the specified key is contained; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [containers Error Codes](../errorcodes/errorcode-containers.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The has method cannot be bound. |

**Example**

```ts
let plainArray = new PlainArray();
plainArray.has(1);
plainArray.add(1, "squirrel");
let result1 = plainArray.has(1);
try {
  plainArray.has.bind({}, 1)(); // bind() creates a new bound function that, when called, has its this keyword set to the provided value. It is used to test exception capture.
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```


### get

get(key: number): T

Obtains the value of the specified key in this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type | Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | number | Yes| Target key.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Value of the key.|

**Error codes**

For details about the error codes, see [containers Error Codes](../errorcodes/errorcode-containers.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The get method cannot be bound. |

**Example**

```ts
let plainArray = new PlainArray();
plainArray.add(1, "squirrel");
plainArray.add(2, "sparrow");
let result = plainArray.get(1);
try {
  plainArray.get.bind({}, 1)(); // bind() creates a new bound function that, when called, has its this keyword set to the provided value. It is used to test exception capture.
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```


### getIndexOfKey

getIndexOfKey(key: number): number

Obtains the index of the first occurrence of an element with the specified key in this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type | Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | number | Yes| Target key.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Returns the position index if obtained; returns **-1** otherwise.|

**Error codes**

For details about the error codes, see [containers Error Codes](../errorcodes/errorcode-containers.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The getIndexOfKey method cannot be bound. |

**Example**

```ts
let plainArray = new PlainArray();
plainArray.add(1, "squirrel");
plainArray.add(2, "sparrow");
let result = plainArray.getIndexOfKey(2);
try {
  plainArray.getIndexOfKey.bind({}, 2)(); // bind() creates a new bound function that, when called, has its this keyword set to the provided value. It is used to test exception capture.
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```


### getIndexOfValue

getIndexOfValue(value: T): number

Obtains the index of the first occurrence of an element with the specified value in this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type | Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | T | Yes| Value of the target element.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Returns the position index if obtained; returns **-1** otherwise.|

**Error codes**

For details about the error codes, see [containers Error Codes](../errorcodes/errorcode-containers.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The getIndexOfValue method cannot be bound. |

**Example**

```ts
let plainArray = new PlainArray();
plainArray.add(1, "squirrel");
plainArray.add(2, "sparrow");
let result = plainArray.getIndexOfValue("squirrel");
try {
  plainArray.getIndexOfValue.bind({}, "squirrel")(); // bind() creates a new bound function that, when called, has its this keyword set to the provided value. It is used to test exception capture.
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```


### getKeyAt

getKeyAt(index: number): number

Obtains the key of the element at the specified position in this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type | Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Position index of the target element.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Returns the key of the element if obtained; returns **-1** otherwise.|

**Error codes**

For details about the error codes, see [containers Error Codes](../errorcodes/errorcode-containers.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The getKeyAt method cannot be bound. |

**Example**

```ts
let plainArray = new PlainArray();
plainArray.add(1, "squirrel");
plainArray.add(2, "sparrow");
let result = plainArray.getKeyAt(1);
try {
  plainArray.getKeyAt.bind({}, 1)(); // bind() creates a new bound function that, when called, has its this keyword set to the provided value. It is used to test exception capture.
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```

### getValueAt

getValueAt(index: number): T

Obtains the value of an element at the specified position in this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type | Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Position index of the target element.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Returns the value of the element if obtained; returns **undefined** otherwise.|

  **Error codes**

For details about the error codes, see [containers Error Codes](../errorcodes/errorcode-containers.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The getValueAt method cannot be bound. |
| 10200001 | The value of parameters are out of range. |

**Example**

```ts
let plainArray = new PlainArray();
plainArray.add(1, "squirrel");
plainArray.add(2, "sparrow");
let result = plainArray.getValueAt(1);
try {
  plainArray.getValueAt.bind({}, 1)(); // bind() creates a new bound function that, when called, has its this keyword set to the provided value. It is used to test exception capture.
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
try {
  plainArray.getValueAt(10);
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```

### clone

clone(): PlainArray&lt;T&gt;

Clones this container and returns a copy. The modification to the copy does not affect the original instance.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| PlainArray&lt;T&gt; | New **PlainArray** instance obtained.|

**Error codes**

For details about the error codes, see [containers Error Codes](../errorcodes/errorcode-containers.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The clone method cannot be bound. |

**Example**

```ts
let plainArray = new PlainArray();
plainArray.add(1, "squirrel");
plainArray.add(2, "sparrow");
let newPlainArray = plainArray.clone();
try {
  plainArray.clone.bind({})(); // bind() creates a new bound function that, when called, has its this keyword set to the provided value. It is used to test exception capture.
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```


### add

add(key: number, value: T): void

Adds an element to this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type | Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | number | Yes| Key of the target element.|
| value | T | Yes| Value of the target element.|

**Error codes**

For details about the error codes, see [containers Error Codes](../errorcodes/errorcode-containers.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The add method cannot be bound. |

**Example**

```ts
let plainArray = new PlainArray();
plainArray.add(1, "squirrel");
try {
  plainArray.add.bind({}, "squirrel")(); // bind() creates a new bound function that, when called, has its this keyword set to the provided value. It is used to test exception capture.
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```


### remove

remove(key: number): T

Removes an element with the specified key from this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type | Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | number | Yes| Target key.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Value of the element removed.|

**Error codes**

For details about the error codes, see [containers Error Codes](../errorcodes/errorcode-containers.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The remove method cannot be bound. |

**Example**

```ts
let plainArray = new PlainArray();
plainArray.add(1, "squirrel");
plainArray.add(2, "sparrow");
let result = plainArray.remove(2);
try {
  plainArray.remove.bind({}, 2)(); // bind() creates a new bound function that, when called, has its this keyword set to the provided value. It is used to test exception capture.
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```


### removeAt

removeAt(index: number): T

Removes an element at the specified position from this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type | Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Position index of the target element.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Element removed.|

**Error codes**

For details about the error codes, see [containers Error Codes](../errorcodes/errorcode-containers.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The removeAt method cannot be bound. |

**Example**

```ts
let plainArray = new PlainArray();
plainArray.add(1, "squirrel");
plainArray.add(2, "sparrow");
let result = plainArray.removeAt(1);
try {
  plainArray.removeAt.bind({}, 1)(); // bind() creates a new bound function that, when called, has its this keyword set to the provided value. It is used to test exception capture.
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```


### removeRangeFrom

removeRangeFrom(index: number, size: number): number

Removes elements in a specified range from this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type | Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Start position of the elements to remove.|
| size | number | Yes| Number of elements to remove.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Number of elements removed.|

**Error codes**

For details about the error codes, see [containers Error Codes](../errorcodes/errorcode-containers.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The removeRangeFrom method cannot be bound. |
| 10200001 | The value of parameters are out of range. |

**Example**

```ts
let plainArray = new PlainArray();
plainArray.add(1, "squirrel");
plainArray.add(2, "sparrow");
let result = plainArray.removeRangeFrom(1, 3);
try {
  plainArray.removeRangeFrom.bind({}, 1, 3)(); // bind() creates a new bound function that, when called, has its this keyword set to the provided value. It is used to test exception capture.
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
try {
  plainArray.removeRangeFrom(10, 3);
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```


### setValueAt

setValueAt(index: number, value: T): void

Sets a value for an element at the specified position in this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type | Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Position index of the target element.|
| value | T | Yes| Value of the target element.|

**Error codes**

For details about the error codes, see [containers Error Codes](../errorcodes/errorcode-containers.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The setValueAt method cannot be bound. |
| 10200001 | The value of parameters are out of range. |

**Example**

```ts
let plainArray = new PlainArray();
plainArray.add(1, "squirrel");
plainArray.add(2, "sparrow");
plainArray.setValueAt(1, 3546);
try {
  plainArray.setValueAt.bind({}, 1, 3546)(); // bind() creates a new bound function that, when called, has its this keyword set to the provided value. It is used to test exception capture.
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
try {
  plainArray.setValueAt(10, 3);
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```


### toString

toString(): String

Obtains a string that contains all elements in this container.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| String | String obtained.|

**Error codes**

For details about the error codes, see [containers Error Codes](../errorcodes/errorcode-containers.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The toString method cannot be bound. |

**Example**

```ts
let plainArray = new PlainArray();
plainArray.add(1, "squirrel");
plainArray.add(2, "sparrow");
let result = plainArray.toString();
try {
  plainArray.toString.bind({})(); // bind() creates a new bound function that, when called, has its this keyword set to the provided value. It is used to test exception capture.
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```


### clear

clear(): void

Clears this container and sets its length to **0**.

**System capability**: SystemCapability.Utils.Lang

**Error codes**

For details about the error codes, see [containers Error Codes](../errorcodes/errorcode-containers.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The clear method cannot be bound. |

**Example**

```ts
let plainArray = new PlainArray();
plainArray.add(1, "squirrel");
plainArray.add(2, "sparrow");
plainArray.clear();
try {
  plainArray.clear.bind({})(); // bind() creates a new bound function that, when called, has its this keyword set to the provided value. It is used to test exception capture.
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```


### forEach

forEach(callbackfn: (value: T, index?: number, PlainArray?: PlainArray&lt;T&gt;) => void, thisArg?: Object): void

Uses a callback to traverse the elements in this container and obtain their position indexes.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type | Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callbackfn | function | Yes| Callback invoked to traverse the elements in the container.|
| thisArg | Object | No| Value to use when the callback is invoked.|

callbackfn
| Name| Type | Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | T | Yes| Value of the element that is currently traversed.|
| index | number | No| Key of the element that is currently traversed.|
| PlainArray | PlainArray&lt;T&gt;| No| Instance that invokes the **forEach** API.|

**Error codes**

For details about the error codes, see [containers Error Codes](../errorcodes/errorcode-containers.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The forEach method cannot be bound. |

**Example**

```ts
let plainArray = new PlainArray();
plainArray.add(1, "squirrel");
plainArray.add(2, "sparrow");
plainArray.forEach((value, index) => {
  console.log("value:" + value, index);
});
try {
  plainArray.forEach.bind({}, (value, index) => {
    console.log("value:" + value, index);
  })(); // bind() creates a new bound function that, when called, has its this keyword set to the provided value. It is used to test exception capture.
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```


### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;[number, T]&gt;

Obtains an iterator object that contains key-value pairs, where the key is of the number type.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;[number, T]&gt; | Iterator obtained.|

**Error codes**

For details about the error codes, see [containers Error Codes](../errorcodes/errorcode-containers.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The Symbol.iterator method cannot be bound. |

**Example**

```ts
let plainArray = new PlainArray();
plainArray.add(1, "squirrel");
plainArray.add(2, "sparrow");

// Method 1:
for (let item of plainArray) { 
  console.log("key:" + item[0]);
  console.log("value:" + item[1]);
}

// Method 2:
let iter = plainArray[Symbol.iterator]();
let temp = iter.next().value;
while(temp != undefined) {
  console.log("key:" + temp[0]);
  console.log("value:" + temp[1]);
  temp = iter.next().value;
}
try {
  plainArray[Symbol.iterator].bind({})(); // bind() creates a new bound function that, when called, has its this keyword set to the provided value. It is used to test exception capture.
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```
