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
import { LightWeightSet } from '@kit.ArkTS';
```

## LightWeightSet

### Attributes

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| length | number | Yes| No| Number of elements in a lightweight set (called container later).|


### constructor

constructor()

A constructor used to create a **LightWeightSet** instance.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200012 | The LightWeightSet's constructor cannot be directly invoked. |

**Example**

```ts
let lightWeightSet: LightWeightSet<number | string> = new LightWeightSet();
```


### isEmpty

isEmpty(): boolean

Checks whether this container is empty (contains no element).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the container is empty; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The isEmpty method cannot be bound. |

**Example**

```ts
const lightWeightSet: LightWeightSet<number> = new LightWeightSet();
let result = lightWeightSet.isEmpty();
```

### add

add(obj: T): boolean

Adds an element to this container.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| obj | T | Yes| Target element.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the element is added; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The add method cannot be bound. |

**Example**

```ts
let lightWeightSet: LightWeightSet<string> = new LightWeightSet();
let result = lightWeightSet.add("squirrel");
```


### addAll

addAll(set: LightWeightSet&lt;T&gt;): boolean

Adds all elements in a **LightWeightSet** instance to this container.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| set | LightWeightSet&lt;T&gt; | Yes| **LightWeightSet** instance whose elements are to be added to the current container.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the element is added; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The addAll method cannot be bound. |

**Example**

```ts
let lightWeightSet: LightWeightSet<string> = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let set: LightWeightSet<string> = new LightWeightSet();
set.add("gull");
let result = lightWeightSet.addAll(set);
```


### hasAll

hasAll(set: LightWeightSet&lt;T&gt;): boolean

Checks whether this container contains all elements of the specified **LightWeightSet** instance.

**Atomic service API**: This API can be used in atomic services since API version 12.

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The hasAll method cannot be bound. |

**Example**

```ts
let lightWeightSet: LightWeightSet<string> = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let set: LightWeightSet<string> = new LightWeightSet();
set.add("sparrow");
let result = lightWeightSet.hasAll(set);
```


### has

has(key: T): boolean

Checks whether this container has the specified key.

**Atomic service API**: This API can be used in atomic services since API version 12.

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

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The has method cannot be bound. |

**Example**

```ts
let lightWeightSet: LightWeightSet<number> = new LightWeightSet();
lightWeightSet.add(123);
let result = lightWeightSet.has(123);
```


### increaseCapacityTo

increaseCapacityTo(minimumCapacity: number): void

Increases the capacity of this container.

If the passed-in capacity is greater than or equal to the number of elements in this container, the container capacity is changed to the new capacity. If the passed-in capacity is less than the number of elements in this container, the capacity is not changed.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| minimumCapacity | number | Yes| Minimum number of elements to accommodate in this container.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200001 | The value of minimumCapacity is out of range. |
| 10200011 | The increaseCapacityTo method cannot be bound. |

**Example**

```ts
let lightWeightSet: LightWeightSet<string> = new LightWeightSet();
lightWeightSet.increaseCapacityTo(10);
```


### getIndexOf

getIndexOf(key: T): number

Obtains the position index of the element with the specified key in this container.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key| T | Yes| Key of the target element.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Position index of the element. If the element does not exist, a negative value is returned. The negative value consists of a minus sign and the position where the element (if available) should be. The position starts from 1.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The getIndexOf method cannot be bound. |

**Example**

```ts
let lightWeightSet: LightWeightSet<string> = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let result = lightWeightSet.getIndexOf("sparrow");
```


### remove

remove(key: T): T

Removes an element of the specified key from this container.

**Atomic service API**: This API can be used in atomic services since API version 12.

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

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The remove method cannot be bound. |

**Example**

```ts
let lightWeightSet: LightWeightSet<string> = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let result = lightWeightSet.remove("sparrow");
```


### removeAt

removeAt(index: number): boolean

Removes the element at the specified position from this container.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Position index of the element. The value must be less than or equal to int32_max, that is, 2147483647.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the element is removed; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The removeAt method cannot be bound. |

**Example**

```ts
let lightWeightSet: LightWeightSet<string> = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let result = lightWeightSet.removeAt(1);
```


### getValueAt

getValueAt(index: number): T

Obtains the value of the element at the specified position in this container.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Position index of the element. The value must be less than or equal to int32_max, that is, 2147483647.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Value obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The getValueAt method cannot be bound. |

**Parameters**

```ts
let lightWeightSet: LightWeightSet<string> = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let result = lightWeightSet.getValueAt(1);
```


### clear

clear(): void

Clears this container and sets its length to **0**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The clear method cannot be bound. |

**Example**

```ts
let lightWeightSet: LightWeightSet<string> = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
lightWeightSet.clear();
```


### toString

toString(): String

Obtains a string that contains all elements in this container.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| String | String obtained.|

**Example**

```ts
let lightWeightSet: LightWeightSet<string> = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let result = lightWeightSet.toString();
```


### toArray

toArray(): Array&lt;T&gt;

Obtains an array that contains all objects in this container.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| Array&lt;T&gt; | Array obtained.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The toArray method cannot be bound. |

**Example**

```ts
let lightWeightSet: LightWeightSet<string> = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let result = lightWeightSet.toArray();
```


### values

values(): IterableIterator&lt;T&gt;

Obtains an iterator that contains all the values in this container.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;T&gt; | Iterator obtained.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The values method cannot be bound. |

**Example**

```ts
let lightWeightSet: LightWeightSet<string> = new LightWeightSet();
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

**Atomic service API**: This API can be used in atomic services since API version 12.

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The forEach method cannot be bound. |

**Example**

```ts
let lightWeightSet: LightWeightSet<string> = new LightWeightSet();
lightWeightSet.add("sparrow");
lightWeightSet.add("gull");
lightWeightSet.forEach((value ?: string, key ?: string) => {
  console.log("value:" + value, "key:" + key);
});
```
```ts
// You are not advised to use the add, remove, or removeAt APIs in forEach because they may cause unpredictable risks such as infinite loops. You can use the for loop when inserting or deleting data.
let lightWeightSet: LightWeightSet<string> = new LightWeightSet();
for(let i = 0; i < 10; i++) {
  lightWeightSet.add(i + "123");
}
for(let i = 0; i < 10; i++) {
  lightWeightSet.remove(i + "123");
}
```

### entries

entries(): IterableIterator<[T, T]>

Obtains an iterator that contains all the elements in this container.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator<[T, T]> | Iterator obtained.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The entries method cannot be bound. |

**Example**

```ts
let lightWeightSet: LightWeightSet<string> = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let iter = lightWeightSet.entries();
let index = 0;
while(index < lightWeightSet.length) {
  console.log(JSON.stringify(iter.next().value));
  index++;
}
```
```ts
// You are not advised to use the add, remove, or removeAt APIs in entries because they may cause unpredictable risks such as infinite loops. You can use the for loop when inserting or deleting data.
let lightWeightSet: LightWeightSet<string> = new LightWeightSet();
for(let i = 0; i < 10; i++) {
  lightWeightSet.add(i + "123");
}
for(let i = 0; i < 10; i++) {
  lightWeightSet.remove(i + "123");
}
```

### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;T&gt;

Obtains an iterator, each item of which is a JavaScript object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;T&gt; | Iterator obtained.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The Symbol.iterator method cannot be bound. |

**Example**

```ts
let lightWeightSet: LightWeightSet<string> = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");

// Method 1:
let nums: Array<string> = lightWeightSet.toArray()
for (let item of nums) {
  console.log("value:" + item);
}

// Method 2:
let iter = lightWeightSet[Symbol.iterator]();
let temp: IteratorResult<string> = iter.next();
while(!temp.done) {
  console.log("value:" + temp.value);
  temp = iter.next();
}
```
```ts
// You are not advised to use the add, remove, or removeAt APIs in Symbol.iterator because they may cause unpredictable risks such as infinite loops. You can use the for loop when inserting or deleting data.
let lightWeightSet: LightWeightSet<string> = new LightWeightSet();
for(let i = 0; i < 10; i++) {
  lightWeightSet.add(i + "123");
}
for(let i = 0; i < 10; i++) {
  lightWeightSet.remove(i + "123");
}
```


### equal<sup>(deprecated)</sup>

equal(obj: Object): boolean

Checks whether the elements of this container are the same as those of **obj**.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 12. There is no substitute API.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| obj | Object | Yes| **LightWeightSet** instance to be used for comparison.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if **obj** is a **LightWeightSet** container or array containing only strings or numbers and the elements in them are the same; returns **false** in other cases.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The equal method cannot be bound. |

**Example**

```ts
let lightWeightSet: LightWeightSet<string> = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let obj = ["sparrow", "squirrel"];
let result = lightWeightSet.equal(obj);
```
