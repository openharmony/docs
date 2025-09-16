# @ohos.fastbuffer (FastBuffer)
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @yuanyao14-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->

A **FastBuffer** object is a more efficient buffer container for representing a byte sequence of a fixed length. It is used to store binary data.

When the **FastBuffer** object is constructed using **from**, only the parameters of the FastBuffer, Uint8Array, string, Array, and ArrayBuffer types are supported.

FastBuffer is recommended if high-performance processing of large binary data (such as images, file transfer, and network communication) is required.

> **NOTE**
>
> The initial APIs of this module are supported since API version 20. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> Container classes, implemented in static languages, have restrictions on storage locations and properties, and do not support custom properties or methods.


## Modules to Import

```ts
import { fastbuffer } from '@kit.ArkTS';
```

## BufferEncoding

type BufferEncoding = 'ascii' | 'utf8' | 'utf-8' | 'utf16le' | 'ucs2' | 'ucs-2' | 'base64' | 'base64url' | 'latin1' | 'binary' | 'hex'

Enumerates the supported encoding formats.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

| Type   | Description                |
| ------- | -------------------- |
| 'ascii' | ASCII format.|
| 'utf8' | UTF-8 format.|
| 'utf-8' | UTF-8 format.|
| 'utf16le' | UTF-16LE format.|
| 'ucs2' | Alias of UTF-16LE.|
| 'ucs-2' | Alias of UTF-16LE.|
| 'base64' | Base64 format.|
| 'base64url' | Base64URL format.|
| 'latin1' | Alias of iso-8859-1, which is backward compatible with the ASCII format.|
| 'binary' | Binary format.|
| 'hex' | Hexadecimal format.|

## fastbuffer.alloc

alloc(size: number, fill?: string | FastBuffer | number, encoding?: BufferEncoding): FastBuffer

Creates and initializes a **FastBuffer** object of the specified length.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| size | number | Yes| Size of the **FastBuffer** object to create, in bytes. Value range: 0 <= size <= UINT32_MAX|
| fill | string&nbsp;\|&nbsp;FastBuffer&nbsp;\|&nbsp;number | No| Value to be filled in the buffer. The default value is **0**.|
| encoding | [BufferEncoding](#bufferencoding) | No| Encoding format (valid only when **fill** is a string). The default value is **'utf8'**. If an unrecognized encoding format is passed, TypeError is thrown.|

**Return value**

| Type| Description|
| -------- | -------- |
| [FastBuffer](#fastbuffer) | **FastBuffer** object created.|

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf1 = fastbuffer.alloc(5);
let buf2 = fastbuffer.alloc(5, 'a');
let buf3 = fastbuffer.alloc(11, 'aGVsbG8gd29ybGQ=', 'base64');
console.info(buf2.toString());
// Output: aaaaa
console.info(buf3.toString());
// Output: hello world
```

## fastbuffer.allocUninitializedFromPool

allocUninitializedFromPool(size: number): FastBuffer

Creates an uninitialized **FastBuffer** object of a specified size from the buffer pool. You need to use [fill](#fill) to initialize the **FastBuffer** object created.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| size | number | Yes| Size of the **FastBuffer** object to create, in bytes. Value range: 0 <= size <= UINT32_MAX|

**Return value**

| Type| Description|
| -------- | -------- |
| [FastBuffer](#fastbuffer) | Uninitialized **FastBuffer** object.|

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(10);
buf.fill(0);
// "buf":[0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
```

## fastbuffer.allocUninitialized

allocUninitialized(size: number): FastBuffer

Creates an uninitialized **FastBuffer** object of a specified size. You need to use [fill](#fill) to initialize the **FastBuffer** object created.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| size | number | Yes|Size of the **FastBuffer** object to create, in bytes. Value range: 0 <= size <= UINT32_MAX|

**Return value**

| Type| Description|
| -------- | -------- |
| [FastBuffer](#fastbuffer) | Uninitialized **FastBuffer** object.|

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitialized(10);
buf.fill(0);
// "buf":[0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
```

## fastbuffer.byteLength

byteLength(value: string | FastBuffer | TypedArray | DataView | ArrayBuffer | SharedArrayBuffer, encoding?: BufferEncoding): number

Obtains the number of bytes of a string based on the encoding format.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | string&nbsp;\|&nbsp;FastBuffer&nbsp;\|&nbsp;TypedArray&nbsp;\|&nbsp;DataView&nbsp;\|&nbsp;ArrayBuffer&nbsp;\|&nbsp;SharedArrayBuffer | Yes| Target string.|
| encoding | [BufferEncoding](#bufferencoding) | No| Encoding format. The default value is **'utf8'**. If an unrecognized encoding format is passed, TypeError is thrown.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Number of bytes of the string.|

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let str = 'hello world';
console.info(`${str}: ${str.length} characters, ${fastbuffer.byteLength(str, 'utf-8')} bytes`);
// Output: hello world: 11 characters, 11 bytes

str = '\u00bd + \u00bc = \u00be';
console.info(`${str}: ${str.length} characters, ${fastbuffer.byteLength(str, 'utf-8')} bytes`);
// Output: ½ + ¼ = ¾: 9 characters, 12 bytes
```

## fastbuffer.compare

compare(buf1: FastBuffer | Uint8Array, buf2: FastBuffer | Uint8Array): -1 | 0 | 1

Compares two **FastBuffer** objects. This API is used for sorting **FastBuffer** objects.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| buf1 | [FastBuffer](#fastbuffer)&nbsp;\|&nbsp;Uint8Array | Yes| First object to compare.|
| buf2 | [FastBuffer](#fastbuffer)&nbsp;\|&nbsp;Uint8Array | Yes| Second object to compare.|

**Return value**

| Type| Description|
| -------- | -------- |
| -1&nbsp;\|&nbsp;0&nbsp;\|&nbsp;1 | Returns **0** if **buf1** is the same as **buf2**.<br>Returns **1** if **buf1** comes after **buf2** when sorted.<br>Returns **-1** if **buf1** comes before **buf2** when sorted.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 10200068 | The underlying ArrayBuffer is null or detach. |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf1 = fastbuffer.from('1234');
let buf2 = fastbuffer.from('0123');
let res = fastbuffer.compare(buf1, buf2);

console.info(Number(res).toString());
// Output: 1
```

## fastbuffer.concat

concat(list: FastBuffer[] | Uint8Array[], totalLength?: number): FastBuffer

Copies the content of a specified byte length from an array to a new **FastBuffer** object and returns the concatenated **FastBuffer** object.

If the total length of all objects in the array exceeds **totalLength**, the length of the returned result will be truncated to **totalLength**.

If the total length of all objects in the array is less than **totalLength**, the excess part of the returned result will be padded with zeros.

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 20.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| list | [FastBuffer](#fastbuffer)[]&nbsp;\|&nbsp;Uint8Array[] | Yes| Array of objects to concatenate.|
| totalLength | number | No| Total length of bytes to be copied. The default value is **0**.|

**Return value**

| Type| Description|
| -------- | -------- |
| [FastBuffer](#fastbuffer) | **FastBuffer** object created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | Range error. Possible causes: The value of the parameter is not within the specified range. |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf1 = fastbuffer.from("1234");
let buf2 = fastbuffer.from("abcd");
let buf = fastbuffer.concat([buf1, buf2]);
console.info(buf.toString('hex'));
// Output: 3132333461626364
```

## fastbuffer.from

from(array: number[]): FastBuffer

Creates a **FastBuffer** object with the specified array.

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 20.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| array | number[] | Yes| Array to create a **FastBuffer** object.|

**Return value**

| Type| Description|
| -------- | -------- |
| [FastBuffer](#fastbuffer) | **FastBuffer** object created.|

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from([0x62, 0x75, 0x66, 0x66, 0x65, 0x72]);
console.info(buf.toString('hex'));
// Output: 627566666572
```

## fastbuffer.from

from(arrayBuffer: ArrayBuffer | SharedArrayBuffer, byteOffset?: number, length?: number): FastBuffer

Creates a **FastBuffer** object of the specified length that shares memory with `ArrayBuffer`.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| arrayBuffer | ArrayBuffer&nbsp;\|&nbsp;SharedArrayBuffer | Yes| Target object.|
| byteOffset | number | No| Byte offset. The default value is **0**.|
| length | number | No| Length of the **FastBuffer** object to create, in bytes. The default value is **arrayBuffer.byteLength** minus **byteOffset**. Value range: 0 <= length <= arrayBuffer.byteLength - byteOffset|

**Return value**

| Type| Description|
| -------- | -------- |
| [FastBuffer](#fastbuffer) | **FastBuffer** object created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | Range error. Possible causes: The value of the parameter is not within the specified range. |
| 10200068 | The underlying ArrayBuffer is null or detach. |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let ab = new ArrayBuffer(10);
let buf = fastbuffer.from(ab, 0, 2);
console.info(buf.length.toString());
// Output: 2
```

## fastbuffer.from

from(buffer: FastBuffer | Uint8Array): FastBuffer

Copies the data of a passed **FastBuffer** object to create a **FastBuffer** object and returns the new one.

Creates a **FastBuffer** object based on the memory of a passed **Uint8Array** object and returns the new object, maintaining the memory association of the data.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| buffer | [FastBuffer](#fastbuffer)&nbsp;\|&nbsp;Uint8Array | Yes| Target object.|

**Return value**

| Type| Description|
| -------- | -------- |
| [FastBuffer](#fastbuffer) | **FastBuffer** object created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 10200068 | The underlying ArrayBuffer is null or detach. |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

// Create a FastBuffer object of the FastBuffer type.
let buf1 = fastbuffer.from('buffer');
let buf2 = fastbuffer.from(buf1);
console.info(buf2.toString());
// Output: buffer

// Create a FastBuffer object of the Uint8Array type to ensure memory sharing between objects.
let uint8Array = new Uint8Array(10);
let buf3 = fastbuffer.from(uint8Array);
buf3.fill(1)
console.info("uint8Array:", uint8Array)
// Output: 1,1,1,1,1,1,1,1,1,1
```

## fastbuffer.from

from(value: string, encoding?: BufferEncoding): FastBuffer

Creates a **FastBuffer** object based on a string in the given encoding format.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | string | Yes| String.|
| encoding | [BufferEncoding](#bufferencoding) | No| Encoding format. The default value is **'utf8'**. If an unrecognized encoding format is passed, TypeError is thrown.|

**Return value**

| Type| Description|
| -------- | -------- |
| [FastBuffer](#fastbuffer) | **FastBuffer** object created.|

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf1 = fastbuffer.from('this is a test');
let buf2 = fastbuffer.from('7468697320697320612074c3a97374', 'hex');

console.info(buf1.toString());
// Output: this is a test
console.info(buf2.toString());
// Output: this is a tést
```


## fastbuffer.isBuffer

isBuffer(obj: Object): boolean

Checks whether the specified object is a **FastBuffer** object.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| obj | Object | Yes| Object to check.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Check result. The value **true** is returned if the object is a **FastBuffer** object; otherwise, **false** is returned.|

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let result = fastbuffer.isBuffer(fastbuffer.alloc(10)); // 10: fastbuffer size
console.info("result = " + result);
// Output: result = true
let result1 = fastbuffer.isBuffer(fastbuffer.from('foo'));
console.info("result1 = " + result1);
// Output: result1 = true
let result2 = fastbuffer.isBuffer('a string');
console.info("result2 = " + result2);
// Output: result2 = false
let result3 = fastbuffer.isBuffer([]);
console.info("result3 = " + result3);
// Output: result3 = false
let result4 = fastbuffer.isBuffer(new Uint8Array(1024));
console.info("result4 = " + result4);
// Output: result4 = false
```

## fastbuffer.isEncoding

isEncoding(encoding: string): boolean

Checks whether the encoding format is supported.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| encoding | string | Yes| Encoding format.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Check result. The value **true** is returned if the encoding format is supported; otherwise, **false** is returned.|

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

console.info(fastbuffer.isEncoding('utf-8').toString());
// Output: true
console.info(fastbuffer.isEncoding('hex').toString());
// Output: true
console.info(fastbuffer.isEncoding('utf/8').toString());
// Output: false
console.info(fastbuffer.isEncoding('').toString());
// Output: false
```

## fastbuffer.transcode

transcode(source: FastBuffer | Uint8Array, fromEnc: string, toEnc: string): FastBuffer

Transcodes a **FastBuffer** or **Uint8Array** object from one encoding format to another.

This API supports the following encoding formats: 'ascii', 'utf8', 'utf16le', 'ucs2', 'latin1', and 'binary'.

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 20.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| source | [FastBuffer](#fastbuffer)&nbsp;\|&nbsp;Uint8Array | Yes| Target object.|
| fromEnc | string | Yes| Current encoding format. For details about the supported formats, see [BufferEncoding](#bufferencoding).|
| toEnc | string | Yes| Target encoding format. For details about the supported formats, see [BufferEncoding](#bufferencoding).|

**Return value**

| Type| Description|
| -------- | -------- |
| [FastBuffer](#fastbuffer) | New **FastBuffer** object in the target encoding format.|

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let newBuf = fastbuffer.transcode(fastbuffer.from('buffer'), 'utf-8', 'ascii');
console.info("newBuf = " + newBuf.toString('ascii'));
// Output: newBuf = buffer
```

## FastBuffer

### Properties

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 20.

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| length | number | Yes| No| Length of the **FastBuffer** object, in bytes.|
| buffer | ArrayBuffer | Yes| No| **ArrayBuffer** object.|
| byteOffset | number | Yes| No| Offset of the **FastBuffer** object in the memory pool.|

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from("1236");
console.info(JSON.stringify(buf.length));
// Output: 4
let arrayBuffer = buf.buffer;
console.info(JSON.stringify(new Uint8Array(arrayBuffer)));
// Output: {"0":49,"1":50,"2":51,"3":54}
console.info(JSON.stringify(buf.byteOffset));
// Output: 0
```

### compare

compare(target: FastBuffer | Uint8Array, targetStart?: number, targetEnd?: number, sourceStart?: number, sourceEnd?: number): -1 | 0 | 1

Compares the current **this** object with the **target** object and returns the comparison result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| target | [FastBuffer](#fastbuffer)&nbsp;\|&nbsp;Uint8Array | Yes| Target **FastBuffer** object to compare.|
| targetStart | number | No| Offset to the start of the data to compare in the target **FastBuffer** object. The default value is **0**. Value range: 0 <= targetStart <= target.length|
| targetEnd | number | No| Offset to the end of the data to compare in the target **FastBuffer** object (not inclusive). The default value is the length of the target **FastBuffer** object. Value range: 0 <= targetEnd <= target.length|
| sourceStart | number | No| Offset to the start of the data to compare in this **FastBuffer** object. The default value is **0**. Value range: 0 <= sourceStart <= this.length|
| sourceEnd | number | No| Offset to the end of the data to compare in this **FastBuffer** object (not inclusive). The default value is the length of this **FastBuffer** object. Value range: 0 <= sourceEnd <= this.length|

**Return value**

| Type| Description|
| -------- | -------- |
| -1 \| 0 \| 1 | Comparison result.<br>-1: This object comes before the target object when sorted.<br>0: The two objects are the same.<br>1: This object comes after the target object when sorted.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | Range error. Possible causes: The value of the parameter is not within the specified range. |
| 10200068 | The underlying ArrayBuffer is null or detach. |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf1 = fastbuffer.from([1, 2, 3, 4, 5, 6, 7, 8, 9]);
let buf2 = fastbuffer.from([5, 6, 7, 8, 9, 1, 2, 3, 4]);

console.info(buf1.compare(buf2, 5, 9, 0, 4).toString());
// Output: 0
console.info(buf1.compare(buf2, 0, 6, 4).toString());
// Output: -1
console.info(buf1.compare(buf2, 5, 6, 5).toString());
// Output: 1
```

### copy

copy(target: FastBuffer| Uint8Array, targetStart?: number, sourceStart?: number, sourceEnd?: number): number

Copies data at the specified position in this **FastBuffer** object to the specified position in another **FastBuffer** object.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| target | [FastBuffer](#fastbuffer)&nbsp;\|&nbsp;Uint8Array | Yes| **FastBuffer** or **Uint8Array** object to which data is copied.|
| targetStart | number | No| Offset to the start position in the target object where data is copied. The default value is **0**. Value range: 0 <= targetStart <= UINT32_MAX|
| sourceStart | number | No| Offset to the start position in this **FastBuffer** object where data is copied. The default value is **0**. Value range: 0 <= sourceStart <= UINT32_MAX|
| sourceEnd | number | No| Offset to the end position in this **FastBuffer** object (not inclusive). The default value is the length of this **FastBuffer** object. Value range: 0 <= sourceEnd <= this.length|

**Return value**

| Type| Description|
| -------- | -------- |
| number |  Total length of the data copied, in bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | Range error. Possible causes: The value of the parameter is not within the specified range. |
| 10200068 | The underlying ArrayBuffer is null or detach. |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf1 = fastbuffer.allocUninitializedFromPool(26);
let buf2 = fastbuffer.allocUninitializedFromPool(26).fill('!');

for (let i = 0; i < 26; i++) {
  buf1.writeInt8(i + 97, i);
}

buf1.copy(buf2, 8, 16, 20);
console.info(buf2.toString('ascii', 0, 25));
// Output: !!!!!!!!qrst!!!!!!!!!!!!!
```

### entries

entries(): IterableIterator&lt;[number,&nbsp;number]&gt;

Creates and returns an iterator that contains key-value pairs of this **FastBuffer** object.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;[number,&nbsp;number]&gt; |  Iterator that contains the key and value, both of which are of the number type.|

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from('buffer');
let pair = buf.entries();
let next: IteratorResult<Object[]> = pair.next();
while (!next.done) {
  console.info("fastbuffer: " + next.value);
  /*
  Output: buffer: 0,98
           fastbuffer: 1,117
           fastbuffer: 2,102
           fastbuffer: 3,102
           fastbuffer: 4,101
           fastbuffer: 5,114
  */
  next = pair.next();
}
```

### equals

equals(otherBuffer: Uint8Array | FastBuffer): boolean

Checks whether this **FastBuffer** object is the same as another **FastBuffer** object.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| otherBuffer | Uint8Array&nbsp;\|&nbsp;FastBuffer | Yes| **FastBuffer** object to compare.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Check result. The value **true** is returned if the two objects are equal byte by byte; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 10200068 | The underlying ArrayBuffer is null or detach. |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf1 = fastbuffer.from('ABC');
let buf2 = fastbuffer.from('414243', 'hex');
let buf3 = fastbuffer.from('ABCD');

console.info(buf1.equals(buf2).toString());
// Output: true
console.info(buf1.equals(buf3).toString());
// Output: false
```

### fill

fill(value: string | FastBuffer | Uint8Array | number, offset?: number, end?: number, encoding?: BufferEncoding): FastBuffer

Fills this **FastBuffer** object at the specified position. By default, data is filled cyclically.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | string&nbsp;\|&nbsp;FastBuffer&nbsp;\|&nbsp;Uint8Array&nbsp;\|&nbsp;number | Yes| Value to fill.|
| offset | number | No| Offset to the start position in this **FastBuffer** object where data is filled. The default value is **0**. Value range: 0 <= offset <= this.length|
| end | number | No| Offset to the end position in this **FastBuffer** object (not inclusive). The default value is the length of this **FastBuffer** object. Value range: 0 <= end <= this.length|
| encoding | [BufferEncoding](#bufferencoding) | No| Encoding format (valid only when **value** is a string). The default value is **'utf8'**. If an unrecognized encoding format is passed, TypeError is thrown.|

**Return value**

| Type| Description|
| -------- | -------- |
| [FastBuffer](#fastbuffer) | **FastBuffer** object filled with the specified value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | Range error. Possible causes: The value of the parameter is not within the specified range. |
| 10200068 | The underlying ArrayBuffer is null or detach. |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let b = fastbuffer.allocUninitializedFromPool(50).fill('h');
console.info(b.toString());
// Output: hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
```


### includes

includes(value: string | number | FastBuffer | Uint8Array, byteOffset?: number, encoding?: BufferEncoding): boolean

Checks whether this **FastBuffer** object contains the specified value.

If **byteOffset** is a positive number, the offset is calculated from 0. If **byteOffset** is a negative number, the offset is calculated from the end.

If **byteOffset** is greater than or equal to **this.length**, **false** is returned. If **byteOffset** is less than or equal to **-this.length**, the system checks whether the value exists in the entire FastBuffer.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | string&nbsp;\|&nbsp;number&nbsp;\|&nbsp;FastBuffer&nbsp;\|&nbsp;Uint8Array | Yes| Value to match.|
| byteOffset | number | No| Number of bytes to skip before starting to check data. If **byteOffset** is a positive number, the offset is calculated from 0. If **byteOffset** is a negative number, the offset is calculated from the end. The default value is **0**.|
| encoding | [BufferEncoding](#bufferencoding) | No| Encoding format (valid only when **value** is a string). The default value is **'utf8'**. If an unrecognized encoding format is passed, TypeError is thrown.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Check result. The value **true** is returned if the object contains the specified value; otherwise, **false** is returned.|

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from('this is a buffer');
console.info(buf.includes('this').toString());
// Output: true
console.info(buf.includes('be').toString());
// Output: false
```

### indexOf

indexOf(value: string | number | FastBuffer | Uint8Array, byteOffset?: number, encoding?: BufferEncoding): number

Obtains the index of the first occurrence of the specified value in this **FastBuffer** object. If no match is found, **-1** is returned.

If **byteOffset** is a positive number, the offset is calculated from 0. If **byteOffset** is a negative number, the offset is calculated from the end.

If **byteOffset** is greater than or equal to **this.length**, **-1** is returned. If **byteOffset** is less than or equal to **-this.length**, the index of the first occurrence of the specified value in the FastBuffer is returned.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | string&nbsp;\|&nbsp;number&nbsp;\|&nbsp;FastBuffer&nbsp;\|&nbsp;Uint8Array | Yes| Value to match.|
| byteOffset | number | No| Number of bytes to skip before starting to check data. If **byteOffset** is a positive number, the offset is calculated from 0. If **byteOffset** is a negative number, the offset is calculated from the end. The default value is **0**.|
| encoding | [BufferEncoding](#bufferencoding) | No| Encoding format (valid only when **value** is a string). The default value is **'utf8'**. If an unrecognized encoding format is passed, TypeError is thrown.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Index obtained.|

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from('this is a buffer');
console.info(buf.indexOf('this').toString());
// Output: 0
console.info(buf.indexOf('is').toString());
// Output: 2
```

### keys

keys(): IterableIterator&lt;number&gt;

Iterator created.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
|  IterableIterator&lt;number&gt; | Iterator created.|

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from('buffer');
let keys = buf.keys();
for (const key of keys) {
  console.info(key.toString());
}
/*
Output: 0
        1
        2
        3
        4
        5
*/
```

### values

values(): IterableIterator&lt;number&gt;

Creates and returns an iterator that contains the values of this **FastBuffer** object.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;number&gt; | Iterator.|

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf1 = fastbuffer.from('buffer');
let pair = buf1.values()
let next:IteratorResult<number> = pair.next()
while (!next.done) {
  console.info(next.value.toString());
  /*
  Output: 98
           117
           102
           102
           101
           114
  */
  next = pair.next();
}
```

### lastIndexOf

lastIndexOf(value: string | number | FastBuffer | Uint8Array, byteOffset?: number, encoding?: BufferEncoding): number

Obtains the index of the last occurrence of the specified value in this **FastBuffer** object. If no match is found, **-1** is returned.

If **byteOffset** is a positive number, the offset is calculated from 0. If **byteOffset** is a negative number, the offset is calculated from the end.

If **byteOffset** is greater than or equal to **this.length**, the index of the last occurrence of the specified value in the FastBuffer is returned. If **byteOffset** is less than or equal to **this.length**, **-1** is returned.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | string&nbsp;\|&nbsp;number&nbsp;\|&nbsp;FastBuffer&nbsp;\|&nbsp;Uint8Array | Yes| Value to match.|
| byteOffset | number | No| Number of bytes to skip before starting to check data. If **byteOffset** is a positive number, the offset is calculated from 0. If **byteOffset** is a negative number, the offset is calculated from the end. The default value is **this.length - 1**.|
| encoding | [BufferEncoding](#bufferencoding) | No| Encoding format (valid only when **value** is a string). The default value is **'utf8'**.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Index obtained.|

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from('this buffer is a buffer');
console.info(buf.lastIndexOf('this').toString());
// Output: 0
console.info(buf.lastIndexOf('buffer').toString());
// Output: 17
```


### readBigInt64BE

readBigInt64BE(offset?: number): bigint

Reads a 64-bit, big-endian, signed big integer from this **FastBuffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= this.length - 8|

**Return value**

| Type| Description|
| -------- | -------- |
| bigint | Data read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 8. Received value is: [offset]. |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from([0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x70,
  0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78]);
console.info(buf.readBigInt64BE(0).toString());
// Output: 7161960797921896816
```

### readBigInt64LE

readBigInt64LE(offset?: number): bigint

Reads a 64-bit, little-endian, signed big integer from this **FastBuffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= this.length - 8|

**Return value**

| Type| Description|
| -------- | -------- |
| bigint | Data read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 8. Received value is: [offset]. |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from([0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x70,
  0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78]);
console.info(buf.readBigInt64LE(0).toString());
// Output: 8100120198111388771
```

### readBigUInt64BE

readBigUInt64BE(offset?: number): bigint

Reads a 64-bit, big-endian, unsigned big integer from this **FastBuffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= this.length - 8|

**Return value**

| Type| Description|
| -------- | -------- |
| bigint | Data read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 8. Received value is: [offset]. |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from([0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x70,
  0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78]);
console.info(buf.readBigUInt64BE(0).toString());
// Output: 7161960797921896816
```

### readBigUInt64LE

readBigUInt64LE(offset?: number): bigint

Reads a 64-bit, little-endian, unsigned big integer from this **FastBuffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= this.length - 8|

**Return value**

| Type| Description|
| -------- | -------- |
| bigint | Data read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 8. Received value is: [offset]. |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from([0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x70,
  0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78]);
console.info(buf.readBigUInt64LE(0).toString());
// Output: 8100120198111388771
```

### readDoubleBE

readDoubleBE(offset?: number): number

Reads a 64-bit, big-endian, double-precision floating-point number from this **FastBuffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= this.length - 8|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Data read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 8. Received value is: [offset]. |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from([1, 2, 3, 4, 5, 6, 7, 8]);
console.info(buf.readDoubleBE(0).toString());
// Output: 8.20788039913184e-304
```

### readDoubleLE

readDoubleLE(offset?: number): number

Reads a 64-bit, little-endian, double-precision floating-point number from this **FastBuffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= this.length - 8|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Data read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 8. Received value is: [offset]. |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from([1, 2, 3, 4, 5, 6, 7, 8]);
console.info(buf.readDoubleLE(0).toString());
// Output: 5.447603722011605e-270
```

### readFloatBE

readFloatBE(offset?: number): number

Reads a 32-bit, big-endian, single-precision floating-point number from this **FastBuffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= this.length - 4|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Data read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 4. Received value is: [offset]. |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from([1, 2, 3, 4, 5, 6, 7, 8]);
console.info(buf.readFloatBE(0).toString());
// Output: 2.387939260590663e-38
```

### readFloatLE

readFloatLE(offset?: number): number

Reads a 32-bit, little-endian, single-precision floating-point number from this **FastBuffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= this.length - 4|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Data read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 4. Received value is: [offset]. |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from([1, 2, 3, 4, 5, 6, 7, 8]);
console.info(buf.readFloatLE(0).toString());
// Output: 1.539989614439558e-36
```

### readInt8

readInt8(offset?: number): number

Reads an 8-bit signed integer from this **FastBuffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= this.length - 1|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Data read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 1. Received value is: [offset]. |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from([-1, 5]);
console.info(buf.readInt8(0).toString());
// Output: -1
console.info(buf.readInt8(1).toString());
// Output: 5
```

### readInt16BE

readInt16BE(offset?: number): number

Reads a 16-bit, big-endian, signed integer from this **FastBuffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= this.length - 2|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Data read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 2. Received value is: [offset]. |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from([0, 5]);
console.info(buf.readInt16BE(0).toString());
// Output: 5
```

### readInt16LE

readInt16LE(offset?: number): number

Reads a 16-bit, little-endian, signed integer from this **FastBuffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= this.length - 2|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Data read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 2. Received value is: [offset]. |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from([0, 5]);
console.info(buf.readInt16LE(0).toString());
// Output: 1280
```

### readInt32BE

readInt32BE(offset?: number): number

Reads a 32-bit, big-endian, signed integer from this **FastBuffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= this.length - 4|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Data read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 4. Received value is: [offset]. |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from([0, 0, 0, 5]);
console.info(buf.readInt32BE(0).toString());
// Output: 5
```

### readInt32LE

readInt32LE(offset?: number): number

Reads a 32-bit, little-endian, signed integer from this **FastBuffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= this.length - 4|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Data read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 |  The value of "offset" is out of range. It must be >= 0 and <= buf.length - 4. Received value is: [offset]. |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from([0, 0, 0, 5]);
console.info(buf.readInt32LE(0).toString());
// Output: 83886080
```

### readIntBE

readIntBE(offset: number, byteLength: number): number

Reads the specified number of bytes from this **FastBuffer** object at the specified offset, and interprets the result as a big-endian, two's complement signed value that supports up to 48 bits of precision.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| offset | number | Yes| Offset. The default value is **0**. Value range: 0 <= offset <= this.length - byteLength|
| byteLength | number | Yes| Number of bytes to read. Value range: 1 <= byteLength <= 6|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Data read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from("ab");
let num = buf.readIntBE(0, 1);
console.info(num.toString());
// Output: 97
```


### readIntLE

readIntLE(offset: number, byteLength: number): number

Reads the specified number of bytes from this **FastBuffer** object at the specified offset and interprets the result as a little-endian, two's complement signed value that supports up to 48 bits of precision.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| offset | number | Yes| Offset. The default value is **0**. Value range: 0 <= offset <= this.length - byteLength|
| byteLength | number | Yes| Number of bytes to read. Value range: 1 <= byteLength <= 6|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Data read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from([0x12, 0x34, 0x56, 0x78, 0x90, 0xab]);
console.info(buf.readIntLE(0, 6).toString(16));
// Output: -546f87a9cbee
```

### readUInt8

readUInt8(offset?: number): number

Reads an 8-bit unsigned integer from this **FastBuffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= this.length - 1|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Data read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 1. Received value is: [offset]. |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from([1, -2]);
console.info(buf.readUInt8(0).toString());
// Output: 1
console.info(buf.readUInt8(1).toString());
// Output: 254
```

### readUInt16BE

readUInt16BE(offset?: number): number

Reads a 16-bit, big-endian, unsigned integer from this **FastBuffer** object at the specified offset.

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 20.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= this.length - 2|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Data read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 2. Received value is: [offset]. |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from([0x12, 0x34, 0x56]);
console.info(buf.readUInt16BE(0).toString(16));
// Output: 1234
console.info(buf.readUInt16BE(1).toString(16));
// Output: 3456
```

### readUInt16LE

readUInt16LE(offset?: number): number

Reads a 16-bit, little-endian, unsigned integer from this **FastBuffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= this.length - 2|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Data read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 2. Received value is: [offset]. |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from([0x12, 0x34, 0x56]);
console.info(buf.readUInt16LE(0).toString(16));
// Output: 3412
console.info(buf.readUInt16LE(1).toString(16));
// Output: 5634
```

### readUInt32BE

readUInt32BE(offset?: number): number

Reads a 32-bit, big-endian, unsigned integer from this **FastBuffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= this.length - 4|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Data read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 4. Received value is: [offset]. |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from([0x12, 0x34, 0x56, 0x78]);
console.info(buf.readUInt32BE(0).toString(16));
// Output: 12345678
```

### readUInt32LE

readUInt32LE(offset?: number): number

Reads a 32-bit, little-endian, unsigned integer from this **FastBuffer** object at the specified offset.

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 20.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= this.length - 4|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Data read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 4. Received value is: [offset]. |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from([0x12, 0x34, 0x56, 0x78]);
console.info(buf.readUInt32LE(0).toString(16));
// Output: 78563412
```

### readUIntBE

readUIntBE(offset: number, byteLength: number): number

Reads the specified number of bytes from this **FastBuffer** object at the specified offset, and interprets the result as an unsigned, big-endian integer that supports up to 48 bits of precision.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| offset | number | Yes| Offset. The default value is **0**. Value range: 0 <= offset <= this.length - byteLength|
| byteLength | number | Yes| Number of bytes to read.  Value range: 1 <= byteLength <= 6|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Data read. If the offset is a decimal, undefined is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from([0x12, 0x34, 0x56, 0x78, 0x90, 0xab]);
console.info(buf.readUIntBE(0, 6).toString(16));
// Output: 1234567890ab
```

### readUIntLE

readUIntLE(offset: number, byteLength: number): number

Reads the specified number of bytes from this **FastBuffer** object at the specified offset, and interprets the result as an unsigned, little-endian integer that supports up to 48 bits of precision.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| offset | number | Yes| Offset. The default value is **0**. Value range: 0 <= offset <= this.length - byteLength|
| byteLength | number | Yes| Number of bytes to read. Value range: 1 <= byteLength <= 6|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Data read. If the offset is a decimal, undefined is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from([0x12, 0x34, 0x56, 0x78, 0x90, 0xab]);
console.info(buf.readUIntLE(0, 6).toString(16));
// Output: ab9078563412
```

### subarray

subarray(start?: number, end?: number): FastBuffer

Truncates this **FastBuffer** object from the specified position to create a **FastBuffer** object.

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 20.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| start | number | No| Offset to the start position in this **FastBuffer** object where data is truncated. The default value is **0**.|
| end | number | No|  Offset to the end position in this **FastBuffer** object (not inclusive). The default value is the length of this **FastBuffer** object. Value range: start <= end <= this.length|

**Return value**

| Type| Description|
| -------- | -------- |
| FastBuffer | **FastBuffer** object created.|

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf1 = fastbuffer.allocUninitializedFromPool(26);

for (let i = 0; i < 26; i++) {
  buf1.writeInt8(i + 97, i);
}
const buf2 = buf1.subarray(0, 3);
console.info(buf2.toString('ascii', 0, buf2.length));
// Output: abc
```

### swap16

swap16(): FastBuffer

Converts this **FastBuffer** object into an array of unsigned 16-bit integers and swaps the byte order in place.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang


**Return value**

| Type| Description|
| -------- | -------- |
| FastBuffer | **FastBuffer** object swapped.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200009 | The fastbuffer size must be a multiple of 16-bits. |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf1 = fastbuffer.from([0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8]);
console.info(buf1.toString('hex'));
// Output: 0102030405060708
buf1.swap16();
console.info(buf1.toString('hex'));
// Output: 0201040306050807
```

### swap32

swap32(): FastBuffer

Converts this **FastBuffer** object into an array of unsigned 32-bit integers and swaps the byte order in place.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang


**Return value**

| Type| Description|
| -------- | -------- |
| FastBuffer | **FastBuffer** object swapped.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200009 | The fastbuffer size must be a multiple of 32-bits. |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf1 = fastbuffer.from([0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8]);
console.info(buf1.toString('hex'));
// Output: 0102030405060708
buf1.swap32();
console.info(buf1.toString('hex'));
// Output: 0403020108070605
```

### swap64

swap64(): FastBuffer

Converts this **FastBuffer** object into an array of unsigned 64-bit integers and swaps the byte order in place.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang


**Return value**

| Type| Description|
| -------- | -------- |
| FastBuffer | **FastBuffer** object swapped.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200009 | The fastbuffer size must be a multiple of 64-bits. |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf1 = fastbuffer.from([0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8]);
console.info(buf1.toString('hex'));
// Output: 0102030405060708
buf1.swap64();
console.info(buf1.toString('hex'));
// Output: 0807060504030201
```

### toJSON

toJSON(): Object

Converts this **FastBuffer** object into a JSON object.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang


**Return value**

| Type| Description|
| -------- | -------- |
| Object | JSON object.|

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf1 = fastbuffer.from([0x1, 0x2, 0x3, 0x4, 0x5]);
let obj = buf1.toJSON();
console.info(JSON.stringify(obj));
// Output: {"type":"FastBuffer","data":[1,2,3,4,5]}
```

### toString

toString(encoding?: string, start?: number, end?: number): string

Converts the data at the specified position in this **FastBuffer** object into a string in the specified encoding format.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| encoding | string | No| Encoding format (valid only when **value** is a string). The default value is **'utf8'**.|
| start  | number | No|  Offset to the start position of the data to convert. The default value is **0**.|
| end  | number | No|  Offset to the end position of the data to convert. The default value is **Buffer.length**.|

**Return value**

| Type| Description|
| -------- | -------- |
| string | String. When the value of **start** is greater than or equal to **this.length** or **start** is greater than **end**, an empty string is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 10200068 | The underlying ArrayBuffer is null or detach. |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf1 = fastbuffer.allocUninitializedFromPool(26);
for (let i = 0; i < 26; i++) {
  buf1.writeInt8(i + 97, i);
}
console.info(buf1.toString('utf-8'));
// Output: abcdefghijklmnopqrstuvwxyz
```

### write

write(str: string, offset?: number, length?: number, encoding?: string): number

Writes a string of the specified length to this **FastBuffer** object at the specified position in the given encoding format.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| str | string | Yes| String to write.|
| offset | number | No| Offset. The default value is **0**.|
| length | number | No| Maximum number of bytes to write. The default value is **this.length - offset**.|
| encoding | string | No| Encoding format of the string. The default value is **'utf8'**.|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Number of bytes written.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | Range error. Possible causes: The value of the parameter is not within the specified range. |
| 10200068 | The underlying ArrayBuffer is null or detach. |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.alloc(256);
let len = buf.write('\u00bd + \u00bc = \u00be', 0);
console.info(`${len} bytes: ${buf.toString('utf-8', 0, len)}`);
// Output: 12 bytes: ½ + ¼ = ¾

let buffer1 = fastbuffer.alloc(10);
let length = buffer1.write('abcd', 8);
console.info("length = " + length);
// Output: length = 2
```

### writeBigInt64BE

writeBigInt64BE(value: bigint, offset?: number): number

Writes a 64-bit, big-endian, signed big integer to this **FastBuffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | bigint | Yes| Data to write. Value range: -INT64_MAX <= value <= INT64_MAX|
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= this.length - 8|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Offset plus the number of written bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(8);
let result = buf.writeBigInt64BE(BigInt(0x0102030405060708), 0);
console.info("result = " + result);
// Output: result = 8
```

### writeBigInt64LE

writeBigInt64LE(value: bigint, offset?: number): number

Writes a 64-bit, little-endian, signed big integer to this **FastBuffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | bigint | Yes| Data to write. Value range: -INT64_MAX <= value <= INT64_MAX|
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= this.length - 8|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Offset plus the number of written bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(8);
let result = buf.writeBigInt64LE(BigInt(0x0102030405060708), 0);
console.info("result = " + result);
// Output: result = 8
```

### writeBigUInt64BE

writeBigUInt64BE(value: bigint, offset?: number): number

**Atomic service API**: This API can be used in atomic services since API version 20.

Writes a 64-bit, big-endian, unsigned big integer to this **FastBuffer** object at the specified offset.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | bigint | Yes| Data to write. Value range: 0 <= value <= UINT64_MAX|
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= this.length - 8|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Offset plus the number of written bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(8);
let result = buf.writeBigUInt64BE(BigInt(0xdecafafecacefade), 0);
console.info("result = " + result);
// Output: result = 8
```

### writeBigUInt64LE

writeBigUInt64LE(value: bigint, offset?: number): number

Writes a 64-bit, little-endian, unsigned big integer to this **FastBuffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | bigint | Yes| Data to write. Value range: 0 <= value <= UINT64_MAX|
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= this.length - 8|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Offset plus the number of written bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(8);
let result = buf.writeBigUInt64LE(BigInt(0xdecafafecacefade), 0);
console.info("result = " + result);
// Output: result = 8
```

### writeDoubleBE

writeDoubleBE(value: number, offset?: number): number

Writes a 64-bit, big-endian, double-precision floating-point number to this **FastBuffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Data to write. Value range: -DOUBLE_MAX <= value <= DOUBLE_MAX|
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= this.length - 8|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Offset plus the number of written bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 8. Received value is: [offset] |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(8);
let result = buf.writeDoubleBE(123.456, 0);
console.info("result = " + result);
// Output: result = 8
```

### writeDoubleLE

writeDoubleLE(value: number, offset?: number): number

Writes a 64-bit, little-endian, double-precision floating-point number to this **FastBuffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Data to write. Value range: -DOUBLE_MAX <= value <= DOUBLE_MAX|
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= this.length - 8|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Offset plus the number of written bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 8. Received value is: [offset] |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(8);
let result = buf.writeDoubleLE(123.456, 0);
console.info("result = " + result);
// Output: result = 8
```

### writeFloatBE

writeFloatBE(value: number, offset?: number): number

Writes a 32-bit, big-endian, single-precision floating-point number to this **FastBuffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Data to write. Value range: -FLOAT_MAX <= value <= FLOAT_MAX|
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= this.length - 4|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Offset plus the number of written bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 4. Received value is: [offset] |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(8);
let result = buf.writeFloatBE(3.1415, 0);
console.info("result = " + result);
// Output: result = 4
```


### writeFloatLE

writeFloatLE(value: number, offset?: number): number

Writes a 32-bit, little-endian, single-precision floating-point number to this **FastBuffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Data to write. Value range: -FLOAT_MAX <= value <= FLOAT_MAX|
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= this.length - 4|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Offset plus the number of written bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 4. Received value is: [offset] |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(8);
let result = buf.writeFloatLE(3.1415, 0);
console.info("result = " + result);
// Output: result = 4
```

### writeInt8

writeInt8(value: number, offset?: number): number

Writes an 8-bit signed integer to this **FastBuffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Data to write. Value range: -INT8_MAX <= value <= INT8_MAX|
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= this.length - 1|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Offset plus the number of written bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(2);
let result = buf.writeInt8(2, 0);
console.info("result = " + result);
// Output: result = 1
let result1 = buf.writeInt8(-2, 1);
console.info("result1 = " + result1);
// Output: result1 = 2
```


### writeInt16BE

writeInt16BE(value: number, offset?: number): number

Writes a 16-bit, big-endian, signed integer to this **FastBuffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Data to write. Value range: -INT16_MAX <= value <= INT16_MAX|
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= this.length - 2|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Offset plus the number of written bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(2);
let result = buf.writeInt16BE(0x0102, 0);
console.info("result = " + result);
// Output: result = 2
```


### writeInt16LE

writeInt16LE(value: number, offset?: number): number

Writes a 16-bit, little-endian, signed integer to this **FastBuffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Data to write. Value range: -INT16_MAX <= value <= INT16_MAX|
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= this.length - 2|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Offset plus the number of written bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(2);
let result = buf.writeInt16LE(0x0304, 0);
console.info("result = " + result);
// Output: result = 2
```

### writeInt32BE

writeInt32BE(value: number, offset?: number): number

Writes a 32-bit, big-endian, signed integer to this **FastBuffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Data to write. Value range: -INT32_MAX <= value <= INT32_MAX|
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= this.length - 4|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Offset plus the number of written bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(4);
let result = buf.writeInt32BE(0x01020304, 0);
console.info("result = " + result);
// Output: result = 4
```


### writeInt32LE

writeInt32LE(value: number, offset?: number): number

Writes a 32-bit, little-endian, signed integer to this **FastBuffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Data to write. Value range: -INT32_MAX <= value <= INT32_MAX|
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= this.length - 4|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Offset plus the number of written bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(4);
let result = buf.writeInt32LE(0x05060708, 0);
console.info("result = " + result);
// Output: result = 4
```

### writeIntBE

writeIntBE(value: number, offset: number, byteLength: number): number

Writes a big-endian signed value of the specified length to this **FastBuffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Data to write. The value range depends on **byteLength**. |
| offset | number | Yes| Offset. The default value is **0**. Value range: 0 <= offset <= this.length - byteLength|
| byteLength | number | Yes| Number of bytes to write.|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Offset plus the number of written bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(6);
let result = buf.writeIntBE(0x1234567890ab, 0, 6);
console.info("result = " + result);
// Output: result = 6
```


### writeIntLE

writeIntLE(value: number, offset: number, byteLength: number): number

Writes a little-endian signed value of the specified length to this **FastBuffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Data to write. The value range depends on **byteLength**.|
| offset | number | Yes| Offset. The default value is **0**. Value range: 0 <= offset <= this.length - byteLength|
| byteLength | number | Yes| Number of bytes to write.|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Offset plus the number of written bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(6);
let result = buf.writeIntLE(0x1234567890ab, 0, 6);
console.info("result = " + result);
// Output: result = 6
```

### writeUInt8

writeUInt8(value: number, offset?: number): number

Writes an 8-bit unsigned integer to this **FastBuffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Data to write. Value range: 0 <= value <= UINT8_MAX|
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= this.length - 1|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Offset plus the number of written bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(4);
let result = buf.writeUInt8(0x3, 0);
console.info("result = " + result);
// Output: result = 1
let result1 = buf.writeUInt8(0x4, 1);
console.info("result1 = " + result1);
// Output: result1 = 2
let result2 = buf.writeUInt8(0x23, 2);
console.info("result2 = " + result2);
// Output: result2 = 3
let result3 = buf.writeUInt8(0x42, 3);
console.info("result3 = " + result3);
// Output: result3 = 4
```

### writeUInt16BE

writeUInt16BE(value: number, offset?: number): number

Writes a 16-bit, big-endian, unsigned integer to this **FastBuffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Data to write. Value range: 0 <= value <= UINT16_MAX|
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= this.length - 2|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Offset plus the number of written bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(4);
let result = buf.writeUInt16BE(0xdead, 0);
console.info("result = " + result);
// Output: result = 2
let result1 = buf.writeUInt16BE(0xbeef, 2);
console.info("result1 = " + result1);
// Output: result1 = 4
```

### writeUInt16LE

writeUInt16LE(value: number, offset?: number): number

Writes a 16-bit, little-endian, unsigned integer to this **FastBuffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Data to write. Value range: 0 <= value <= UINT16_MAX|
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= this.length - 2|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Offset plus the number of written bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(4);
let result = buf.writeUInt16LE(0xdead, 0);
console.info("result = " + result);
// Output: result = 2
let result1 = buf.writeUInt16LE(0xbeef, 2);
console.info("result1 = " + result1);
// Output: result1 = 4
```

### writeUInt32BE

writeUInt32BE(value: number, offset?: number): number

Writes a 32-bit, big-endian, unsigned integer to this **FastBuffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Data to write. Value range: 0 <= value <= UINT32_MAX|
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= this.length - 4|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Offset plus the number of written bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(4);
let result = buf.writeUInt32BE(0xfeedface, 0);
console.info("result = " + result);
// Output: result = 4
```

### writeUInt32LE

writeUInt32LE(value: number, offset?: number): number

Writes a 32-bit, little-endian, unsigned integer to this **FastBuffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Data to write. Value range: 0 <= value <= UINT32_MAX|
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= this.length - 4|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Offset plus the number of written bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(4);
let result = buf.writeUInt32LE(0xfeedface, 0);
console.info("result = " + result);
// Output: result = 4
```

### writeUIntBE

writeUIntBE(value: number, offset: number, byteLength: number): number

Writes an unsigned big-endian value of the specified length to this **FastBuffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Data to write. The value range depends on **byteLength**.|
| offset | number | Yes| Offset. The default value is **0**. Value range: 0 <= offset <= this.length - byteLength|
| byteLength | number | Yes| Number of bytes to write.|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Offset plus the number of written bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(6);
let result = buf.writeUIntBE(0x1234567890ab, 0, 6);
console.info("result = " + result);
// Output: result = 6
```

### writeUIntLE

writeUIntLE(value: number, offset: number, byteLength: number): number

Writes an unsigned little-endian value of the specified length to this **FastBuffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Data to write. The value range depends on **byteLength**.|
| offset | number | Yes| Offset. The default value is **0**. Value range: 0 <= offset <= this.length - byteLength|
| byteLength | number | Yes| Number of bytes to write.|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Offset plus the number of written bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**Example**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(6);
let result = buf.writeUIntLE(0x1234567890ab, 0, 6);
console.info("result = " + result);
// Output: result = 6
```
