# @ohos.util.PlainArray (Nonlinear Container PlainArray) 
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @yuanyao14-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->

PlainArray stores key-value (KV) pairs. Each key must be unique, be of the number type, and have only one value.

PlainArray is based on generics and uses a lightweight structure. Keys in the array are searched using binary search and are mapped to values in other arrays.

Both PlainArray and [LightWeightMap](js-apis-lightweightmap.md) are used to store KV pairs in the lightweight structure. However, the keys of PlainArray can only be of the number type.

**Recommended use case**: Use PlainArray when you need to store KV pairs whose keys are of the **number** type.

This topic uses the following to identify the use of generics:
- T: Type

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> Container classes, implemented in static languages, have restrictions on storage locations and properties, and do not support custom properties or methods.


## Modules to Import

```ts
import { PlainArray } from '@kit.ArkTS';  
```


## PlainArray

### Properties

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| length | number | Yes| No| Number of elements in a PlainArray.|


### constructor

constructor()

A constructor used to create a **PlainArray** instance.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200012 | The PlainArray's constructor cannot be directly invoked. |

**Example**

```ts
let plainArray = new PlainArray<string>();
```


### isEmpty

isEmpty(): boolean

Checks whether this PlainArray is empty.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Check result. The value **true** is returned if the PlainArray is empty; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The isEmpty method cannot be bound. |

**Example**

```ts
const plainArray = new PlainArray<string>();
let result = plainArray.isEmpty();
console.info("result = ", result); // result =  true
```


### has

has(key: number): boolean

Checks whether PlainArray has the specified key.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | number | Yes| Target key. The value must be less than or equal to int32_max, that is, 2147483647.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Check result. The value **true** is returned if the specified key is contained; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The has method cannot be bound. |

**Example**

```ts
let plainArray = new PlainArray<string>();
plainArray.add(1, "squirrel");
let result = plainArray.has(1);
console.info("result = ", result); // result = true
```


### get

get(key: number): T

Obtains the value of the specified key in this PlainArray.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | number | Yes| Target key. The value must be less than or equal to int32_max, that is, 2147483647.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Value of the key.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The get method cannot be bound. |

**Example**

```ts
let plainArray = new PlainArray<string>();
plainArray.add(1, "squirrel");
plainArray.add(2, "sparrow");
let result = plainArray.get(1);
console.info("result:", result);  // result: squirrel
```


### getIndexOfKey

getIndexOfKey(key: number): number

Obtains the index of the element with the specified key in this PlainArray.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | number | Yes| Target key. The value must be less than or equal to int32_max, that is, 2147483647.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Index of the element. If no match is found, **-1** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The getIndexOfKey method cannot be bound. |

**Example**

```ts
let plainArray = new PlainArray<string>();
plainArray.add(1, "squirrel");
plainArray.add(2, "sparrow");
let result = plainArray.getIndexOfKey(2);
console.info("result = ", result); // result = 1
```


### getIndexOfValue

getIndexOfValue(value: T): number

Obtains the index of the first occurrence of an element with the specified value in this PlainArray.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | T | Yes| Value of the target element.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Index of the element. If no match is found, **-1** is returned.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The getIndexOfValue method cannot be bound. |

**Example**

```ts
let plainArray = new PlainArray<string>();
plainArray.add(1, "squirrel");
plainArray.add(2, "sparrow");
let result = plainArray.getIndexOfValue("squirrel");
console.info("result:", result);  // result: 0
```


### getKeyAt

getKeyAt(index: number): number

Obtains the key of the element at the specified position in this PlainArray.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Position index of the target element. The value must be less than or equal to int32_max, that is, 2147483647.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Key of the element. If no match is found, **-1** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The getKeyAt method cannot be bound. |

**Example**

```ts
let plainArray = new PlainArray<string>();
plainArray.add(1, "squirrel");
plainArray.add(2, "sparrow");
let result = plainArray.getKeyAt(1);
console.info("result = ", result); // result = 2
```

### getValueAt

getValueAt(index: number): T

Obtains the value of an element at the specified position in this PlainArray.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Position index of the target element. The value must be less than or equal to int32_max, that is, 2147483647.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Value of the element. If no match is found, **undefined** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200001 | The value of index is out of range. |
| 10200011 | The getValueAt method cannot be bound. |

**Example**

```ts
let plainArray = new PlainArray<string>();
plainArray.add(1, "squirrel");
plainArray.add(2, "sparrow");
let result = plainArray.getValueAt(1);
console.info("result:", result);  // result: sparrow
```

### clone

clone(): PlainArray&lt;T&gt;

Clones this PlainArray and returns a copy. The modification to the copy does not affect the original instance.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| PlainArray&lt;T&gt; | New **PlainArray** instance obtained.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The clone method cannot be bound. |

**Example**

```ts
let plainArray = new PlainArray<string>();
plainArray.add(1, "squirrel");
plainArray.add(2, "sparrow");
let newPlainArray = plainArray.clone();
console.info("result:", newPlainArray.get(1));  // result: squirrel
```


### add

add(key: number, value: T): void

Adds an element to this PlainArray.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | number | Yes| Key of the target element. The value must be less than or equal to int32_max, that is, 2147483647.|
| value | T | Yes| Value of the target element.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The add method cannot be bound. |

**Example**

```ts
let plainArray = new PlainArray<string>();
plainArray.add(1, "squirrel");
console.info("result:", plainArray.get(1));  // result: squirrel
```


### remove

remove(key: number): T

Removes a key-value pair with the specified key.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | number | Yes| Target key. The value must be less than or equal to int32_max, that is, 2147483647.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Value in the key-value pair removed.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The remove method cannot be bound. |

**Example**

```ts
let plainArray = new PlainArray<string>();
plainArray.add(1, "squirrel");
plainArray.add(2, "sparrow");
let result = plainArray.remove(2);
console.info("result:", result);  // result: sparrow
```


### removeAt

removeAt(index: number): T

Removes an element at the specified position from this PlainArray.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Position index of the target element. The value must be less than or equal to int32_max, that is, 2147483647.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Element removed.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The removeAt method cannot be bound. |

**Example**

```ts
let plainArray = new PlainArray<string>();
plainArray.add(1, "squirrel");
plainArray.add(2, "sparrow");
let result = plainArray.removeAt(1);
console.info("result:", result);  // result: sparrow
```


### removeRangeFrom

removeRangeFrom(index: number, size: number): number

Removes elements within the specified range.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Start position of the elements to remove. The value must be less than or equal to int32_max, that is, 2147483647.|
| size | number | Yes| Number of elements to remove. The value must be less than or equal to int32_max, that is, 2147483647.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Number of elements removed.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200001 | The value of index is out of range. |
| 10200011 | The removeRangeFrom method cannot be bound. |

**Example**

```ts
let plainArray = new PlainArray<string>();
plainArray.add(1, "squirrel");
plainArray.add(2, "sparrow");
let result = plainArray.removeRangeFrom(1, 3);
console.info("result:", result);  // result: 1
```


### setValueAt

setValueAt(index: number, value: T): void

Sets a value for an element at the specified position in this PlainArray.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Position index of the target element. The value must be less than or equal to int32_max, that is, 2147483647.|
| value | T | Yes| Value of the target element.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200001 | The value of index is out of range. |
| 10200011 | The setValueAt method cannot be bound. |

**Example**

```ts
let plainArray = new PlainArray<string | number>();
plainArray.add(1, "squirrel");
plainArray.add(2, "sparrow");
plainArray.setValueAt(1, 3546);
let result = plainArray.getValueAt(1);
console.info("result:", result);  // result: 3546
```


### toString

toString(): String

Obtains a string that contains all elements in this PlainArray.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| String | String obtained.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The toString method cannot be bound. |

**Example**

```ts
let plainArray = new PlainArray<string>();
plainArray.add(1, "squirrel");
plainArray.add(2, "sparrow");
let result = plainArray.toString();
console.info("result:", result);  // result: 1:squirrel,2:sparrow
```


### clear

clear(): void

Clears this PlainArray and sets its length to **0**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The clear method cannot be bound. |

**Example**

```ts
let plainArray = new PlainArray<string>();
plainArray.add(1, "squirrel");
plainArray.add(2, "sparrow");
plainArray.clear();
let result = plainArray.isEmpty();
console.info("result:", result);  // result: true
```


### forEach

forEach(callbackFn: (value: T, index?: number, PlainArray?: PlainArray&lt;T&gt;) => void, thisArg?: Object): void

Uses a callback to traverse each element in the **PlainArray** instance.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callbackFn | function | Yes| Callback invoked to traverse the elements in the PlainArray.|
| thisArg | Object | No| Value of **this** to use when **callbackFn** is invoked. The default value is this instance.|

callbackFn parameters
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | T | Yes| Value of the element that is currently traversed.|
| index | number | No| Position index of the element that is currently traversed.|
| PlainArray | PlainArray&lt;T&gt;| No| Instance that calls the **forEach** API. The default value is this instance.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The forEach method cannot be bound. |

**Example**

```ts
let plainArray = new PlainArray<string>();
plainArray.add(1, "squirrel");
plainArray.add(2, "sparrow");
plainArray.forEach((value: string, index: number) => {
  console.info("value:" + value, "index:" + index);
});
// value:squirrel index:1
// value:sparrow index:2
```

```ts
// You are not advised to use the add, remove, or removeAt APIs in forEach because they may cause unpredictable risks such as infinite loops. You can use the for loop when inserting or deleting data.
let plainArray = new PlainArray<string>();
for(let i = 0; i < 10; i++) {
  plainArray.add(i,"123");
}

for(let i = 0; i < 10; i++) {
  plainArray.remove(i);
}
```

### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;[number, T]&gt;

Returns an iterator object that contains key-value pairs, where the key is of the number type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;[number, T]&gt; | Iterator obtained.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The Symbol.iterator method cannot be bound. |

**Example**

```ts
let plainArray = new PlainArray<string>();
plainArray.add(1, "squirrel");
plainArray.add(2, "sparrow");

for (let item of plainArray) {
  console.info("value:" + item[1], "index:" + item[0]);
}
// value:squirrel index:1
// value:sparrow index:2
```
```ts
// You are not advised to use the add, remove, or removeAt APIs in Symbol.iterator because they may cause unpredictable risks such as infinite loops. You can use the for loop when inserting or deleting data.
let plainArray = new PlainArray<string>();
for(let i = 0; i < 10; i++) {
  plainArray.add(i,"123");
}

for(let i = 0; i < 10; i++) {
  plainArray.remove(i);
}
```
