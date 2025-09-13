# Class (BitVector)
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @lijiamin2025-->
<!--Designer: @weng-changcheng-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->
> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This module can be imported only to ArkTS files (with the file name extension .ets).

A linear data structure that is implemented on arrays. A bit vector stores bit values and provides bit-level storage and processing.

**Decorator**: \@Sendable

## Modules to Import

```ts
import { collections } from '@kit.ArkTS';
```

## Properties

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Name  | Type  | Read Only| Optional| Description                 |
| ------ | ------ | ---- | ---- | --------------------- |
| length | number | Yes  | No  | Number of elements in a bit vector.|


## constructor

constructor(length: number)

Constructor used to create a bit vector.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description                   |
| ------ | ------ | ---- | ----------------------- |
| length | number | Yes  | Length of the bit vector.|

**Example**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
```


## push

push(element:number): boolean

Adds an element at the end of this bit vector.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type  | Mandatory| Description                               |
| ------- | ------ | ---- | ----------------------------------- |
| element | number | Yes  | Element to add. The value **0** indicates bit value 0, and other values indicate bit value 1.|

**Return value**

| Type   | Description                             |
| ------- | --------------------------------- |
| boolean | Operation result. The value **true** is returned if the element is added; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |
| 10200011 | The push method cannot be bound.                             |
| 10200201 | Concurrent modification error.                               |

**Example**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0); // bitVector: [0, 1, 0, 1, 0]
```

## pop

pop(): number

Removes the last element from this bit vector.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type  | Description                                      |
| ------ | ------------------------------------------ |
| number | Element (bit value) removed.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                       |
| -------- | ------------------------------- |
| 10200011 | The pop method cannot be bound. |
| 10200201 | Concurrent modification error.  |

**Example**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0); // bitVector: [0, 1, 0, 1, 0]
let res = bitVector.pop(); // bitVector: [0, 1, 0, 1]
console.info("bitVector pop:", res); // 0
```

## has

has(element: number, fromIndex: number, toIndex: number): boolean

Checks whether a bit value is included in a given range of this bit vector.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type  | Mandatory| Description                                |
| --------- | ------ | ---- | ------------------------------------ |
| element   | number | Yes  | Bit value. The value **0** indicates bit value 0, and other values indicate bit value 1.|
| fromIndex | number | Yes  | Start index of the range (inclusive). If **fromIndex** is less than **0** or greater than or equal to **toIndex**, an error is thrown. |
| toIndex   | number | Yes  | End index of the range (inclusive). If **toIndex** is less than **0** or greater than or equal to **length**, an error is thrown.      |

**Return value**

| Type   | Description                                  |
| ------- | -------------------------------------- |
| boolean | Check result. The value **true** is returned if the bit value exists; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 10200001 | The value of fromIndex or toIndex is out of range.           |
| 10200011 | The has method cannot be bound.                              |
| 10200201 | Concurrent modification error.                               |

**Example**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0); // bitVector: [0, 1, 0, 1, 0]
let res0: boolean = bitVector.has(0, 1, 4);
console.info("bitVector has 0:", res0); // true
```

## setBitsByRange

setBitsByRange(element: number, fromIndex: number, toIndex: number): void

Sets elements in a given range in this bit vector to a bit value.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type  | Mandatory| Description                              |
| --------- | ------ | ---- | ---------------------------------- |
| element   | number | Yes  | Bit value to set. The value **0** indicates bit value 0, and other values indicate bit value 1.|
| fromIndex | number | Yes  | Start index of the range (inclusive). If **fromIndex** is less than **0** or greater than or equal to **toIndex**, an error is thrown. |
| toIndex   | number | Yes  | End index of the range (exclusive). If **toIndex** is less than **0** or greater than or equal to **length**, an error is thrown.    |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |
| 10200001 | The value of fromIndex or toIndex is out of range.           |
| 10200011 | The setBitsByRange method cannot be bound.                   |
| 10200201 | Concurrent modification error.                               |

**Example**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0); // bitVector: [0, 1, 0, 1, 0]
bitVector.setBitsByRange(1, 1, 3); // bitVector: [0, 1, 1, 1, 0]
```

## setAllBits

setAllBits(element: number): void

Sets all elements in this bit vector to a bit value.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type  | Mandatory| Description                               |
| ------- | ------ | ---- | ----------------------------------- |
| element | number | Yes  | Bit value to set. The value **0** indicates bit value 0, and other values indicate bit value 1.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |
| 10200011 | The setAllBits method cannot be bound.                       |
| 10200201 | Concurrent modification error.                               |

**Example**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0); // bitVector: [0, 1, 0, 1, 0]
bitVector.setAllBits(1); // bitVector: [1, 1, 1, 1, 1]
```

## getBitsByRange

getBitsByRange(fromIndex: number, toIndex: number): BitVector

Obtains bit values within a given range of this bit vector.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type  | Mandatory| Description                          |
| --------- | ------ | ---- | ------------------------------ |
| fromIndex | number | Yes  | Start index of the range (inclusive). If **fromIndex** is less than **0** or greater than or equal to **toIndex**, an error is thrown.  |
| toIndex   | number | Yes  | End index of the range (exclusive). If **toIndex** is less than **0** or greater than or equal to **length**, an error is thrown.     |

**Return value**

| Type     | Description                              |
| --------- | ---------------------------------- |
| BitVector | Bit vector containing the bit values obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |
| 10200001 | The value of fromIndex or toIndex is out of range.           |
| 10200011 | The getBitsByRange method cannot be bound.                   |
| 10200201 | Concurrent modification error.                               |

**Example**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0); // bitVector: [0, 1, 0, 1, 0]
let bitVector2 = bitVector.getBitsByRange(1, 3); // bitVector2: [1, 0]
console.info("bitVector2 length:", bitVector2.length); // 2
```

## resize

resize(size: number): void

Resizes this bit vector.

If **size** is greater than the length of the existing bit vector, the bit vector is extended, and elements of the extra part are set to 0.

If **size** is less than or equal to the length of the existing bit vector, the bit vector is shrunk according to the size.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description            |
| ------ | ------ | ---- | ---------------- |
| size   | number | Yes  | New length.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |
| 10200011 | The resize method cannot be bound.                           |
| 10200201 | Concurrent modification error.                               |

**Example**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0); // bitVector: [0, 1, 0, 1, 0]
bitVector.resize(10); // bitVector: [0, 1, 0, 1, 0, 0, 0, 0, 0, 0]
console.info("bitVector get bit vector's length:", bitVector.length); // 10
bitVector.resize(3); // bitVector: [0, 1, 0]
console.info("bitVector get bit vector's length:", bitVector.length); // 3
```

## getBitCountByRange

getBitCountByRange(element: number, fromIndex: number, toIndex: number): number

Counts the number of bit values in a given range of this bit vector.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type  | Mandatory| Description                                |
| --------- | ------ | ---- | ------------------------------------ |
| element   | number | Yes  | Bit value. The value **0** indicates bit value 0, and other values indicate bit value 1.|
| fromIndex | number | Yes  | Start index of the range (inclusive). If **fromIndex** is less than **0** or greater than or equal to **toIndex**, an error is thrown.   |
| toIndex   | number | Yes  | End index of the range (exclusive). If **toIndex** is less than **0** or greater than or equal to **length**, an error is thrown.      |

**Return value**

| Type  | Description                               |
| ------ | ----------------------------------- |
| number | Number of bit values.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |
| 10200001 | The value of fromIndex or toIndex is out of range.           |
| 10200011 | The getBitCountByRange method cannot be bound.               |
| 10200201 | Concurrent modification error.                               |

**Example**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0); // bitVector: [0, 1, 0, 1, 0]
let res: number = bitVector.getBitCountByRange(1, 1, 4);
console.info("bitVector getBitCountByRange:", res); // 2
```

## getIndexOf

getIndexOf(element: number, fromIndex: number, toIndex: number): number

Returns the index of the first occurrence of a bit value in this bit vector. If the bit value is not found, **-1** is returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type  | Mandatory| Description                                |
| --------- | ------ | ---- | ------------------------------------ |
| element   | number | Yes  | Bit value. The value **0** indicates bit value 0, and other values indicate bit value 1.|
| fromIndex | number | Yes  | Start index of the range (inclusive). If **fromIndex** is less than **0** or greater than or equal to **toIndex**, an error is thrown.   |
| toIndex   | number | Yes  | End index of the range (exclusive). If **toIndex** is less than **0** or greater than or equal to **length**, an error is thrown.      |

**Return value**

| Type  | Description                                             |
| ------ | ------------------------------------------------- |
| number | Index of the first occurrence of the bit value. If the bit value is not found, **-1** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |
| 10200001 | The value of fromIndex or toIndex is out of range.           |
| 10200011 | The getIndexOf method cannot be bound.                       |
| 10200201 | Concurrent modification error.                               |

**Example**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0); // bitVector: [0, 1, 0, 1, 0]
let res: number = bitVector.getIndexOf(0, 1, 4);
console.info("bitVector getIndexOf:", res); // 2
```

## getLastIndexOf

getLastIndexOf(element: number, fromIndex: number, toIndex: number): number

Returns the index of the last occurrence of a bit value in this bit vector. If the bit value is not found, **-1** is returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type  | Mandatory| Description                                |
| --------- | ------ | ---- | ------------------------------------ |
| element   | number | Yes  | Bit value. The value **0** indicates bit value 0, and other values indicate bit value 1.|
| fromIndex | number | Yes  | Start index of the range (inclusive). If **fromIndex** is less than **0** or greater than or equal to **toIndex**, an error is thrown.   |
| toIndex   | number | Yes  | End index of the range (exclusive). If **toIndex** is less than **0** or greater than or equal to **length**, an error is thrown.      |

**Return value**

| Type  | Description                                                 |
| ------ | ----------------------------------------------------- |
| number | Index of the last occurrence of the bit value. If the bit value is not found, **-1** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |
| 10200001 | The value of fromIndex or toIndex is out of range.           |
| 10200011 | The getLastIndexOf method cannot be bound.                   |
| 10200201 | Concurrent modification error.                               |

**Example**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0); // bitVector: [0, 1, 0, 1, 0]
let res: number = bitVector.getLastIndexOf(0, 1, 4);
console.info("bitVector getLastIndexOf:", res); // 2
```

## flipBitByIndex

flipBitByIndex(index: number): void

Flips the bit value (from 0 to 1 or from 1 to 0) at a given index in this bit vector.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description      |
| ------ | ------ | ---- | ---------- |
| index  | number | Yes  | Index. If **index** is less than **0** or greater than or equal to **length**, an error is reported.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |
| 10200001 | The value of index is out of range.                          |
| 10200011 | The flipBitByIndex method cannot be bound.                   |
| 10200201 | Concurrent modification error.                               |

**Example**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0); // bitVector: [0, 1, 0, 1, 0]
bitVector.flipBitByIndex(3); // bitVector: [0, 1, 0, 0, 0]
```

## flipBitsByRange

flipBitsByRange(fromIndex: number, toIndex: number): void

Flips the bit values (from 0 to 1 or from 1 to 0) in a given range in this bit vector.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type  | Mandatory| Description                          |
| --------- | ------ | ---- | ------------------------------ |
| fromIndex | number | Yes  | Start index of the range (inclusive). If **fromIndex** is less than **0** or greater than or equal to **toIndex**, an error is thrown. |
| toIndex   | number | Yes  | End index of the range (exclusive). If **toIndex** is less than **0** or greater than or equal to **length**, an error is thrown.    |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |
| 10200001 | The value of fromIndex or toIndex is out of range.           |
| 10200011 | The flipBitsByRange method cannot be bound.                  |
| 10200201 | Concurrent modification error.                               |

**Example**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0); // bitVector: [0, 1, 0, 1, 0]
bitVector.flipBitsByRange(1, 4); // bitVector: [0, 0, 1, 0, 0]
```

## values

values(): IterableIterator\<number>

Returns an iterator object that contains the value of each element in this bit vector.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type                          | Description                         |
| ------------------------------ | ----------------------------- |
| IterableIterator&lt;number&gt; | Bit vector iterator object.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                          |
| -------- | ---------------------------------- |
| 10200011 | The values method cannot be bound. |
| 10200201 | Concurrent modification error.     |

**Example**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0); // bitVector: [0, 1, 0, 1, 0]
let iter: IterableIterator<number> = bitVector.values();
let temp: IteratorResult<number> = iter.next();
while (!temp.done) {
  console.info(JSON.stringify(temp.value));
  temp = iter.next();
} // 0, 1, 0, 1, and 0 are returned in sequence.
```

## [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;number&gt;

Returns an iterator, each item of which is a JavaScript object.

> **NOTE**
>
> This API cannot be used in .ets files.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type                     | Description            |
| ------------------------- | ---------------- |
| IterableIterator&lt;number&gt; | Iterator obtained.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 10200011 | The Symbol.iterator method cannot be bound. |

**Example**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);

for (let item of bitVector) {
  console.info("value: " + item);
}
```

## [index: number]

&#91;index: number&#93;: number

Returns the element at a given index in this BitVector.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type  | Mandatory| Description                    |
| ----- | ------ | ---- | -------------------------- |
| index | number | Yes  | Index of the element. The index starts from zero.|

**Return value**

| Type  | Description                |
| ----- | ---------------------|
| number | Number data type.|

**Example**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0); // bitVector: [0, 1, 0, 1, 0]
console.info("BitVector Element Index at 1: " + bitVector[1]);
```
