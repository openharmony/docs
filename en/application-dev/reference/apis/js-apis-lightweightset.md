# @ohos.util.LightWeightSet (Nonlinear Container LightWeightSet)

**LightWeightSet** stores a set of values, each of which must be unique.

**LightWeightSet** is based on generics and uses a lightweight structure. Its default initial capacity is 8, and it has the capacity doubled in each expansion.

The values in such a set are searched using hash values, which are stored in an array.

Compared with **[HashSet](js-apis-hashset.md)**, which can also store values, **LightWeightSet** occupies less memory.

**Recommended use case**: Use **LightWeightSet** when you need a set that has only unique elements or need to deduplicate a set.

This topic uses the following to identify the use of generics:
- T: Type

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import LightWeightSet from '@ohos.util.LightWeightSet';  
```

## LightWeightSet

### Attributes

**System capability**: SystemCapability.Utils.Lang

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| length | number | Yes| No| Number of elements in a lightweight set (called container later).|


### constructor

constructor()

A constructor used to create a **LightWeightSet** instance.

**System capability**: SystemCapability.Utils.Lang

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200012 | The LightWeightSet's constructor cannot be directly invoked. |

**Example**

```ts
let lightWeightSet = new LightWeightSet();
```


### isEmpty

isEmpty(): boolean

Checks whether this container is empty (contains no element).

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the container is empty; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The isEmpty method cannot be bound. |

**Example**

```ts
const lightWeightSet = new LightWeightSet();
let result = lightWeightSet.isEmpty();
```

### add

add(obj: T): boolean

Adds an element to this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| obj | T | Yes| Target element.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the element is added successfully; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The add method cannot be bound. |

**Example**

```ts
let lightWeightSet = new LightWeightSet();
let result = lightWeightSet.add("squirrel");
```


### addAll

addAll(set: LightWeightSet&lt;T&gt;): boolean

Adds all elements in a **LightWeightSet** instance to this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| set | LightWeightSet&lt;T&gt; | Yes| **LightWeightSet** instance whose elements are to be added to the current container.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The addAll method cannot be bound. |

**Example**

```ts
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let set = new LightWeightSet();
set.add("gull");
let result = lightWeightSet.addAll(set);
```


### hasAll

hasAll(set: LightWeightSet&lt;T&gt;): boolean

Checks whether this container contains all elements of the specified **LightWeightSet** instance.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| set | LightWeightSet&lt;T&gt; | Yes| **LightWeightSet** instance to be used for comparison.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if all the elements in the specified **LightWeightSet** instance are contained; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The hasAll method cannot be bound. |

**Example**

```ts
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let set = new LightWeightSet();
set.add("sparrow");
let result = lightWeightSet.hasAll(set);
```


### has

has(key: T): boolean

Checks whether this container has the specified key.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key| T | Yes| Target key.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the specified key is contained; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The has method cannot be bound. |

**Example**

```ts
let lightWeightSet = new LightWeightSet();
lightWeightSet.add(123);
let result = lightWeightSet.has(123);
```


### equal

equal(obj: Object): boolean

Checks whether this container contains objects of the same type as the specified **obj**.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| obj | Object | Yes| **LightWeightSet** instance to be used for comparison.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the container contains objects of the same type as the specified **obj**; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The equal method cannot be bound. |

**Example**

```ts
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let obj = ["sparrow", "squirrel"];
let result = lightWeightSet.equal(obj);
```


### increaseCapacityTo

increaseCapacityTo(minimumCapacity: number): void

Increases the capacity of this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| minimumCapacity | number | Yes| Minimum number of elements to accommodate in the container.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The increaseCapacityTo method cannot be bound. |
| 10200001 | The value of minimumCapacity is out of range. |

**Example**

```ts
let lightWeightSet = new LightWeightSet();
lightWeightSet.increaseCapacityTo(10);
```


### getIndexOf

getIndexOf(key: T): number

Obtains the position index of the element with the specified key in this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key| T | Yes| Key of the target element.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Position index of the element.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The getIndexOf method cannot be bound. |

**Example**

```ts
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let result = lightWeightSet.getIndexOf("sparrow");
```


### remove

remove(key: T): T

Removes an element of the specified key from this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key| T | Yes| Key of the target element.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Value of the element removed.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The remove method cannot be bound. |

**Example**

```ts
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let result = lightWeightSet.remove("sparrow");
```


### removeAt

removeAt(index: number): boolean

Removes the element at the specified position from this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Position index of the element.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the element is removed successfully; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The removeAt method cannot be bound. |

**Example**

```ts
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let result = lightWeightSet.removeAt(1);
```


### getValueAt

getValueAt(index: number): T

Obtains the value of the element at the specified position in this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Position index of the element.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Value obtained.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The getValueAt method cannot be bound. |

**Parameters**

```ts
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let result = lightWeightSet.getValueAt(1);
```


### clear

clear(): void

Clears this container and sets its length to **0**.

**System capability**: SystemCapability.Utils.Lang

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The clear method cannot be bound. |

**Example**

```ts
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
lightWeightSet.clear();
```


### toString

toString(): String

Obtains a string that contains all elements in this container.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| String | String obtained.|

**Example**

```ts
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let result = lightWeightSet.toString();
```


### toArray

toArray(): Array&lt;T&gt;

Obtains an array that contains all objects in this container.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| Array&lt;T&gt; | Array obtained.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The toArray method cannot be bound. |

**Example**

```ts
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let result = lightWeightSet.toArray();
```


### values

values(): IterableIterator&lt;T&gt;

Obtains an iterator that contains all the values in this container.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;T&gt; | Iterator obtained.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The values method cannot be bound. |

**Example**

```ts
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let iter = lightWeightSet.values();
let index = 0;
while(index < lightWeightSet.length) {
  console.log(JSON.stringify(iter.next().value));
  index++;
}
```


### forEach

forEach(callbackFn: (value?: T, key?: T, set?: LightWeightSet&lt;T&gt;) => void, thisArg?: Object): void

Uses a callback to traverse the elements in this container and obtain their position indexes.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callbackFn | function | Yes| Callback invoked to traverse the elements in the container.|
| thisArg | Object | No| Value of **this** to use when **callbackFn** is invoked. The default value is this instance.|

callbackFn
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | T | No| Value of the element that is currently traversed. The default value is the value of the first key-value pair.|
| key| T | No| Key of the element that is currently traversed (same as **value**). The default value is the key of the first key-value pair.|
| set | LightWeightSet&lt;T&gt; | No| Instance that calls the **forEach** API. The default value is this instance.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The forEach method cannot be bound. |

**Example**

```ts
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("sparrow");
lightWeightSet.add("gull");
lightWeightSet.forEach((value, key) => {
    console.log("value:" + value, "key:" + key);
});
```


### entries

entries(): IterableIterator<[T, T]>

Obtains an iterator that contains all the elements in this container.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator<[T, T]> | Iterator obtained.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The entries method cannot be bound. |

**Example**

```ts
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let iter = lightWeightSet.entries();
let index = 0;
while(index < lightWeightSet.length) {
  console.log(JSON.stringify(iter.next().value));
  index++;
}
```


### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;T&gt;

Obtains an iterator, each item of which is a JavaScript object.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;T&gt; | Iterator obtained.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The Symbol.iterator method cannot be bound. |

**Example**

```ts
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");

// Method 1:
for (let item of lightWeightSet) { 
  console.log("value:" + item);
}

// Method 2:
let iter = lightWeightSet[Symbol.iterator]();
let temp = iter.next().value;
while(temp != undefined) {
  console.log("value:" + temp);
  temp = iter.next().value;
}
```
