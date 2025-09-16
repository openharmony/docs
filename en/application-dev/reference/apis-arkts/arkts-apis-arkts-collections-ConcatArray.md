# Interface (ConcatArray)
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

An array-like object that can be concatenated. This API extends **ISendable**.

This section uses the following to identify the use of generics:

- T: type, which can be any of the [sendable data types](../../arkts-utils/arkts-sendable.md#sendable-data-types).

## Modules to Import

```ts
import { collections } from '@kit.ArkTS';
```

## Properties

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Name  | Type  | Read Only| Optional| Description             |
| ------ | ------ | ---- | ---- | ----------------- |
| length | number | Yes  | No  | Number of elements in a ConcatArray.|

## [index: number]

readonly &#91;index: number&#93;: T

Returns the element at a given index in this ConcatArray.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type  | Mandatory| Description                      |
| ----- | ------ | ---- | ---------------------------- |
| index | number | Yes  | Index of the element. The index starts from zero. The element at the specified index cannot be modified. |

**Return value**

| Type  | Description                    |
| ----- | ------------------------ |
| T | Element in the ConcatArray.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                            |
| ------- | ------------------------------------ |
| 401 |  Parameter error. Illegal index.         |
| 10200001 | The value of index is out of range. |

**Example**

```ts
let concatArray : collections.ConcatArray<number> = new collections.Array<number>(1, 2, 4);
console.info("Element at index 1: ", concatArray[1]);
```

## join

join(separator?: string): string

Concatenates all elements in this array into a string, with a given separator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type  | Mandatory| Description                                                |
| --------- | ------ | ---- | ---------------------------------------------------- |
| separator | string | No  | Separator to be used. If no value is passed in, a comma (,) is used as the separator.|

**Return value**

| Type  | Description                                                        |
| ------ | ------------------------------------------------------------ |
| string | String obtained. If the array is empty, an empty string is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------- |
| 401 |  Parameter error. Invalid separator. |

**Example**

```ts
let concatArray : collections.ConcatArray<string> = new collections.Array<string>('a', 'b', 'c');
let joinedString = concatArray.join('-'); // "a-b-c" is returned.
```

## slice

slice(start?: number, end?: number): ConcatArray\<T>

Selects a range of elements in this array to create an array.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| start  | number | No  | Start index of the range. If a negative number is passed in, it refers to the index of `start + array.length`. The default value is **0**.  |
| end    | number | No  | End index of the range (exclusive). If a negative number is passed in, it refers to the index of `end + array.length`. The default value is the length of the ArkTS array.|

**Return value**

| Type     | Description                      |
| --------- | -------------------------- |
| ConcatArray\<T> | New array containing the selected elements.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------- |
| 401 |  Parameter error. Invalid \`start\` or \`end\` parameters. |

**Example**

```ts
let concatArray : collections.ConcatArray<number> = new collections.Array<number>(1, 2, 3, 4, 5);
let slicedArray = concatArray.slice (1, 3); // [2, 3] is returned. The original array remains unchanged.
```
