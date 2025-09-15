# @ohos.util.HashSet (Nonlinear Container HashSet)
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @yuanyao14-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->

HashSet is implemented based on [HashMap](js-apis-hashmap.md). In HashSet, only the **value** object is processed.

Unlike [TreeSet](js-apis-treeset.md), which stores and accesses data in sorted order, HashSet sorts data by hash value. This means that HashSet may use a different order when storing and accessing elements. Both of them allow only unique elements. However, null values are allowed in HashSet, but not in TreeSet, because null values may affect the order of elements in the container.

**Recommended use case**: Use HashSet when you need a set that has only unique elements or need to deduplicate a set.

This topic uses the following to identify the use of generics:
- T: Type

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> Container classes, implemented in static languages, have restrictions on storage locations and properties, and do not support custom properties or methods.


## Modules to Import

```ts
import { HashSet } from '@kit.ArkTS';
```

## HashSet

### Properties

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| length | number | Yes| No| Number of elements in a HashSet.|

**Example**

```ts
let hashSet = new HashSet<number>();
hashSet.add(1);
hashSet.add(2);
hashSet.add(3);
hashSet.add(4);
hashSet.add(5);
let res = hashSet.length;
console.info("length:", res);  // length: 5
```

### constructor

constructor()

A constructor used to create a **HashSet** instance.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200012 | The HashSet's constructor cannot be directly invoked. |

**Example**

```ts
let hashSet = new HashSet<number>();
```


### isEmpty

isEmpty(): boolean

Checks whether this HashSet is empty (contains no element).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Check result. The value **true** is returned if the HashSet is empty; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The isEmpty method cannot be bound. |

**Example**

```ts
const hashSet = new HashSet<number>();
let result = hashSet.isEmpty();
console.info("result:", result);  // result: true
```


### has

has(value: T): boolean

Checks whether this HashSet has the specified element.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | T | Yes| Target element.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Operation result. The value **true** is returned if the specified element is contained; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200011 | The has method cannot be bound. |

**Example**

```ts
let hashSet = new HashSet<string>();
hashSet.add("squirrel");
let result = hashSet.has("squirrel");
console.info("result:", result);  // result: true
```


### add

add(value: T): boolean

Adds elements to this HashSet.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | T | Yes| Target element.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Operation result. The value **true** is returned if the element is added; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200011 | The add method cannot be bound. |

**Example**

```ts
let hashSet = new HashSet<string>();
let result = hashSet.add("squirrel");
console.info("result:", result);  // result: true
```


### remove

remove(value: T): boolean

Removes an element from this HashSet.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | T | Yes| Target element.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Operation result. The value **true** is returned if the element is removed; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200011 | The remove method cannot be bound. |

**Example**

```ts
let hashSet = new HashSet<string>();
hashSet.add("squirrel");
hashSet.add("sparrow");
let result = hashSet.remove("sparrow");
console.info("result:", result);  // result: true
```


### clear

clear(): void

Clears this HashSet and sets its length to **0**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The clear method cannot be bound. |

**Example**

```ts
let hashSet = new HashSet<string>();
hashSet.add("squirrel");
hashSet.add("sparrow");
hashSet.clear();
let result = hashSet.isEmpty();
console.info("result:", result);  // result: true
```


### values

values(): IterableIterator&lt;T&gt;

Returns an iterator that contains all the values in this HashSet.

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
let hashSet = new HashSet<string>();
hashSet.add("squirrel");
hashSet.add("sparrow");
let values = hashSet.values();
for (let value of values) {
  console.info("value:", value);
}
// value: squirrel
// value: sparrow
```


### forEach

forEach(callbackFn: (value?: T, key?: T, set?: HashSet&lt;T&gt;) => void, thisArg?: Object): void

Uses a callback to traverse each element.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callbackFn | function | Yes| Callback invoked to traverse the elements in the HashSet.|
| thisArg | Object | No| Value of **this** to use when **callbackFn** is invoked. The default value is this instance.|

callbackFn parameters
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | T | No| Value of the element that is currently traversed.|
| key | T | No| Key of the element that is currently traversed (same as **value**).|
| set | HashSet&lt;T&gt; | No| Instance that calls the **forEach** API. The default value is this instance.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The forEach method cannot be bound. |

**Example**

```ts
let hashSet = new HashSet<string>();
hashSet.add("sparrow");
hashSet.add("squirrel");
hashSet.forEach((value: string, key: string): void => {
  console.info("value:" + value, "key:" + key);
});
// value:squirrel key:squirrel
// value:sparrow key:sparrow
```
```ts
// You are not advised to use the set or remove APIs in forEach because they may cause unpredictable risks such as infinite loops. You can use the for loop when inserting or deleting data.
let hashSet = new HashSet<string>();
for(let i = 0; i < 10; i++) {
  hashSet.add("sparrow" + i);
}
for(let i = 0; i < 10; i++) {
  hashSet.remove("sparrow" + i);
}
```

### entries
entries(): IterableIterator<[T, T]>

Returns an iterator that contains all the elements in this HashSet.

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
let hashSet = new HashSet<string>();
hashSet.add("squirrel");
hashSet.add("sparrow");
let iter = hashSet.entries();
let temp: IteratorResult<[string, string]> = iter.next();
while(!temp.done) {
  console.info("key:" + temp.value[0]);
  console.info("value:" + temp.value[1]);
  temp = iter.next();
}
// key:squirrel
// value:squirrel
// key:sparrow
// value:sparrow
```
```ts
// You are not advised to use the set or remove APIs in entries because they may cause unpredictable risks such as infinite loops. You can use the for loop when inserting or deleting data.
let hashSet = new HashSet<string>();
for(let i = 0; i < 10; i++) {
  hashSet.add("sparrow" + i);
}
for(let i = 0; i < 10; i++) {
  hashSet.remove("sparrow" + i);
}
```

### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;T&gt;

Returns an iterator, each item of which is a JavaScript object.

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
let hashSet = new HashSet<string>();
hashSet.add("squirrel");
hashSet.add("sparrow");

// Method 1:
for (let item of hashSet) {
  console.info("value: " + item);
}
// value: squirrel
// value: sparrow

// Method 2:
let iter = hashSet[Symbol.iterator]();
let temp: IteratorResult<string> = iter.next();
while(!temp.done) {
  console.info("value: " + temp.value);
  temp = iter.next();
}
// value: squirrel
// value: sparrow
```

```ts
// You are not advised to use the set or remove APIs in Symbol.iterator because they may cause unpredictable risks such as infinite loops. You can use the for loop when inserting or deleting data.
let hashSet = new HashSet<string>();
for(let i = 0;i < 10;i++) {
  hashSet.add("sparrow" + i);
}
for(let i = 0;i < 10;i++) {
  hashSet.remove("sparrow" + i);
}
```
