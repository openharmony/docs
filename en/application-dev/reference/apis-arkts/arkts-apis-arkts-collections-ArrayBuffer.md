# Class (ArrayBuffer)
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

Underlying data structure of the ArkTS TypedArray ([Int8Array](arkts-apis-arkts-collections-Int8Array.md), [Uint8Array](arkts-apis-arkts-collections-Uint8Array.md), [Int16Array](arkts-apis-arkts-collections-Int16Array.md), [Uint16Array](arkts-apis-arkts-collections-Uint16Array.md), [Int32Array](arkts-apis-arkts-collections-Int32Array.md), [Uint32Array](arkts-apis-arkts-collections-Uint32Array.md), [Uint8ClampedArray](arkts-apis-arkts-collections-Uint8ClampedArray.md), and [Float32Array](arkts-apis-arkts-collections-Float32Array.md)).

**Decorator**: \@Sendable

## Modules to Import

```ts
import { collections } from '@kit.ArkTS';
```

## Properties

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name  | Type  | Read Only| Optional| Description             |
| ------ | ------ | ---- | ---- | ----------------|
| byteLength | number | Yes  | No  | Number of bytes occupied by the buffer.|

## constructor
constructor(byteLength: number)

A constructor used to create an ArkTS ArrayBuffer of a given length.

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------|
| byteLength  | number | Yes  | Number of bytes occupied by the buffer. The maximum value is **2147483647**.    |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 401      | Parameter error.                                          |
| 10200012 | The ArrayBuffer's constructor cannot be directly invoked. |

**Example**

```ts
let arrayBuffer: collections.ArrayBuffer = new collections.ArrayBuffer(10);
console.info("byteLength: " + arrayBuffer.byteLength); // byteLength: 10
```

## slice
slice(begin: number, end?: number): ArrayBuffer

Selects a range of elements in this ArkTS ArrayBuffer to create an ArkTS ArrayBuffer.

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name| Type  | Mandatory| Description                                             |
| ------ | ------ | ---- | ------------------------------------------------ |
| begin  | number | Yes  | Start index of the range. If a negative number is passed in, it refers to the index of `begin + arrayBuffer.byteLength`.|
| end    | number | No  | End index of the range (exclusive). If a negative number is passed in, it refers to the index of `end + arrayBuffer.byteLength`. The default value is the length of the original ArkTS ArrayBuffer.|

**Return value**

| Type        | Description     |
| ------------ | --------- |
| ArrayBuffer | New ArrayBuffer generated.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID|                    Error Message                  |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 10200011 | The slice method cannot be bound.            |
| 10200201 | Concurrent modification error.               |

**Example**

```ts
let arrayBuffer: collections.ArrayBuffer = new collections.ArrayBuffer(10);
let slicedBuffer: collections.ArrayBuffer = arrayBuffer.slice(0, 4);
console.info("byteLength: " + slicedBuffer.byteLength); // byteLength: 4
```
