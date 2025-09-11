# @ohos.buffer (Buffer)
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @yuanyao14-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->

A **Buffer** object represents a byte sequence of a fixed length. It is used to store binary data.

**Recommended use case**: Use Buffer when you need to process images and a large amount of binary data, and receive or upload files.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { buffer } from '@kit.ArkTS';
```

## BufferEncoding

Enumerates the supported encoding formats.

**Atomic service API**: This API can be used in atomic services since API version 11.

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

## buffer.alloc

alloc(size: number, fill?: string | Buffer | number, encoding?: BufferEncoding): Buffer

Creates and initializes a **Buffer** object of the specified length.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| size | number | Yes| Size of the **Buffer** object to create, in bytes.|
| fill | string \| [Buffer](#buffer) \| number | No| Value to be filled in the buffer. The default value is **0**.|
| encoding | [BufferEncoding](#bufferencoding) | No| Encoding format (valid only when **fill** is a string). The default value is **'utf8'**.|

**Return value**

| Type| Description|
| -------- | -------- |
| [Buffer](#buffer) | **Buffer** object created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { buffer, JSON } from '@kit.ArkTS';

let buf1 = buffer.alloc(5);
console.info(JSON.stringify(buf1)); // {"type":"Buffer","data":[0,0,0,0,0]}

let buf2 = buffer.alloc(5, 'a');
console.info(JSON.stringify(buf2)); // {"type":"Buffer","data":[97,97,97,97,97]}

let buf3 = buffer.alloc(11, 'aGVsbG8gd29ybGQ=', 'base64');
console.info(JSON.stringify(buf3)); // {"type":"Buffer","data":[104,101,108,108,111,32,119,111,114,108,100]}
```

## buffer.allocUninitializedFromPool

allocUninitializedFromPool(size: number): Buffer

Creates a **Buffer** object of the specified size from the buffer pool, without initializing it.
You need to use [fill()](#fill) to initialize the **Buffer** object created.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| size | number | Yes| Size of the **Buffer** object to create, in bytes.|

**Return value**

| Type| Description|
| -------- | -------- |
| [Buffer](#buffer) | Uninitialized **Buffer** object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { buffer, JSON } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(10);
buf.fill(0);
console.info(JSON.stringify(buf)); // {"type":"Buffer","data":[0,0,0,0,0,0,0,0,0,0]}
```

## buffer.allocUninitialized

allocUninitialized(size: number): Buffer

Creates a **Buffer** object of the specified size, without initializing it. This API does not allocate memory from the buffer pool.
You need to use [fill()](#fill) to initialize the **Buffer** object created.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| size | number | Yes|Size of the **Buffer** object to create, in bytes.|

**Return value**

| Type| Description|
| -------- | -------- |
| [Buffer](#buffer) | Uninitialized **Buffer** object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { buffer, JSON } from '@kit.ArkTS';

let buf = buffer.allocUninitialized(10);
buf.fill(0);
console.info(JSON.stringify(buf)); // {"type":"Buffer","data":[0,0,0,0,0,0,0,0,0,0]}
```

## buffer.byteLength

byteLength(string: string | Buffer | TypedArray | DataView | ArrayBuffer | SharedArrayBuffer, encoding?: BufferEncoding): number

Obtains the number of bytes of a string based on the encoding format.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| string | string \| [Buffer](#buffer) \| TypedArray \| DataView \| ArrayBuffer \| SharedArrayBuffer | Yes| Target string.|
| encoding | [BufferEncoding](#bufferencoding) | No| Encoding format. The default value is **'utf8'**.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Number of bytes of the string.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let str = '\u00bd + \u00bc = \u00be';
console.info(`${str}: ${str.length} characters, ${buffer.byteLength(str, 'utf-8')} bytes`);
// Output: ½ + ¼ = ¾: 9 characters, 12 bytes
```

## buffer.compare

compare(buf1: Buffer | Uint8Array, buf2: Buffer | Uint8Array): -1 | 0 | 1

Compares two **Buffer** objects. This API is used for sorting **Buffer** objects.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| buf1 | [Buffer](#buffer) \| Uint8Array | Yes| **Buffer** object to compare.|
| buf2 | [Buffer](#buffer) \| Uint8Array | Yes| **Buffer** object to compare.|

**Return value**

| Type| Description|
| -------- | -------- |
| -1&nbsp;\|&nbsp;0&nbsp;\|&nbsp;1 | Returns **0** if **buf1** is the same as **buf2**.<br>Returns **1** if **buf1** comes after **buf2** when sorted.<br>Returns **-1** if **buf1** comes before **buf2** when sorted.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf1 = buffer.from('1234');
let buf2 = buffer.from('0123');
let res = buffer.compare(buf1, buf2);

console.info(Number(res).toString());
// Output: 1
```

## buffer.concat

concat(list: Buffer[] | Uint8Array[], totalLength?: number): Buffer

Concatenates an array of **Buffer** objects of the specified length into a new object.

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| list | Buffer[]&nbsp;\|&nbsp;Uint8Array[] | Yes| Array of objects to concatenate.|
| totalLength | number | No| Total length of bytes to be copied. The default value is **0**.|

**Return value**

| Type| Description|
| -------- | -------- |
| [Buffer](#buffer) | **Buffer** object created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200001 | The value of "length" is out of range. It must be >= 0 and <= uint32 max. Received value is: [length] |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf1 = buffer.from("1234");
let buf2 = buffer.from("abcd");
let buf = buffer.concat([buf1, buf2]);
console.info(buf.toString('hex'));
// Output: 3132333461626364
```

## buffer.from

from(array: number[]): Buffer

Creates a **Buffer** object with the specified array.

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| array | number[] | Yes| Array to create a **Buffer** object.|

**Return value**

| Type| Description|
| -------- | -------- |
| [Buffer](#buffer) | **Buffer** object created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from([0x62, 0x75, 0x66, 0x66, 0x65, 0x72]);
console.info(buf.toString('hex'));
// Output: 627566666572
```

## buffer.from

from(arrayBuffer: ArrayBuffer | SharedArrayBuffer, byteOffset?: number, length?: number): Buffer

Creates a **Buffer** object of the specified length that shares memory with ArrayBuffer.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| arrayBuffer | ArrayBuffer&nbsp;\|&nbsp;SharedArrayBuffer | Yes| **ArrayBuffer** or **SharedArrayBuffer** object whose memory is to be shared.|
| byteOffset | number | No| Byte offset. The default value is **0**.|
| length | number | No| Length of the **Buffer** object to create, in bytes. The default value is **arrayBuffer.byteLength** minus **byteOffset**.|

**Return value**

| Type| Description|
| -------- | -------- |
| [Buffer](#buffer) | **Buffer** object created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200001 | The value of "[byteOffset/length]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [byteOffset/length] |

**Example**

```ts
import { buffer, JSON } from '@kit.ArkTS';

let ab = new ArrayBuffer(10);
let buf = buffer.from(ab, 0, 2);
console.info(JSON.stringify(buf)); // {"type":"Buffer","data":[0,0]}
```

## buffer.from

from(buffer: Buffer | Uint8Array): Buffer

Copies the data of a passed **Buffer** object to create a new **Buffer** object and returns the new one.
Creates a **Buffer** object based on the memory of a passed **Uint8Array** object and returns the new object, maintaining the memory association of the data.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| buffer | [Buffer](#buffer) \| Uint8Array | Yes| Target object.|

**Return value**

| Type| Description|
| -------- | -------- |
| [Buffer](#buffer) | **Buffer** object created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

// Create a Buffer object of the Buffer type.
let buf1 = buffer.from('buffer');
let buf2 = buffer.from(buf1);

// Create a Buffer object of the Uint8Array type to ensure memory sharing between objects.
let uint8Array = new Uint8Array(10);
let buf3 = buffer.from(uint8Array);
buf3.fill(1);
console.info("uint8Array:", uint8Array);
// Output: 1,1,1,1,1,1,1,1,1,1
```

## buffer.from

from(object: Object, offsetOrEncoding: number | string, length: number): Buffer

Creates a **Buffer** object based on the specified object.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| object | Object | Yes| Object that supports **Symbol.toPrimitive** or **valueOf()**.|
| offsetOrEncoding | number&nbsp;\|&nbsp;string | Yes| Byte offset or encoding format.|
| length | number | Yes| Length of the **Buffer** object to create, in bytes. This parameter is valid only when the return value of **valueOf()** of **object** is **ArrayBuffer**. Value range: 0 <= length <= ArrayBuffer.byteLength. Error 10200001 is reported if a value outside this range is reported. In other cases, you can set this parameter to any value of the number type. This parameter does not affect the result.|

**Return value**

| Type| Description|
| -------- | -------- |
| [Buffer](#buffer) | **Buffer** object created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
import { buffer, JSON } from '@kit.ArkTS';

let buf = buffer.from(new String('this is a test'), 'utf8', 14);
console.info(JSON.stringify(buf)); // {"type":"Buffer","data":[116,104,105,115,32,105,115,32,97,32,116,101,115,116]}
```

## buffer.from

from(string: String, encoding?: BufferEncoding): Buffer

Creates a **Buffer** object based on a string in the given encoding format.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| string | String | Yes| String.|
| encoding | [BufferEncoding](#bufferencoding) | No| Encoding format. The default value is **'utf8'**.|

**Return value**

| Type| Description|
| -------- | -------- |
| [Buffer](#buffer) | **Buffer** object created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf1 = buffer.from('this is a test');
let buf2 = buffer.from('7468697320697320612074c3a97374', 'hex');

console.info(buf1.toString());
// Output: this is a test
console.info(buf2.toString());
// Output: this is a tést
```


## buffer.isBuffer

isBuffer(obj: Object): boolean

Checks whether the specified object is a **Buffer** object.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| obj | Object | Yes| Object to check.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Check result. The value **true** is returned if the object is a **Buffer** object; otherwise, **false** is returned.|

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let result = buffer.isBuffer(buffer.alloc(10)); // 10: buffer size
console.info("result = " + result);
// Output: result = true
let result1 = buffer.isBuffer(buffer.from('foo'));
console.info("result1 = " + result1);
// Output: result1 = true
let result2 = buffer.isBuffer('a string');
console.info("result2 = " + result2);
// Output: result2 = false
let result3 = buffer.isBuffer([]);
console.info("result3 = " + result3);
// Output: result3 = false
let result4 = buffer.isBuffer(new Uint8Array(1024));
console.info("result4 = " + result4);
// Output: result4 = false
```

## buffer.isEncoding

isEncoding(encoding: string): boolean

Checks whether the encoding format is supported.

**Atomic service API**: This API can be used in atomic services since API version 11.

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
import { buffer } from '@kit.ArkTS';

console.info(buffer.isEncoding('utf-8').toString());
// Output: true
console.info(buffer.isEncoding('hex').toString());
// Output: true
console.info(buffer.isEncoding('utf/8').toString());
// Output: false
console.info(buffer.isEncoding('').toString());
// Output: false
```

## buffer.transcode

transcode(source: Buffer | Uint8Array, fromEnc: string, toEnc: string): Buffer

Transcodes a **Buffer** or **Uint8Array** object from one encoding format to another.

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| source | [Buffer](#buffer) \| Uint8Array | Yes| Object to encode.|
| fromEnc | string | Yes| Current encoding format. For details about the supported formats, see [BufferEncoding](#bufferencoding).|
| toEnc | string | Yes| Target encoding format. For details about the supported formats, see [BufferEncoding](#bufferencoding).|

**Return value**

| Type| Description|
| -------- | -------- |
| [Buffer](#buffer) | New **Buffer** object in the target encoding format.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let newBuf = buffer.transcode(buffer.from('€'), 'utf-8', 'ascii');
console.info("newBuf = " + newBuf.toString('ascii'));
// Output: newBuf = ,
```

## Buffer

### Properties

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| length | number | Yes| No| Length of the **Buffer** object, in bytes.|
| buffer | ArrayBuffer | Yes| No| **ArrayBuffer** object.|
| byteOffset | number | Yes| No| Offset of the **Buffer** object in the memory pool.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200013 | ${propertyName} cannot be set for the buffer that has only a getter. |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from("1236");
console.info(JSON.stringify(buf.length));
// Output: 4
let arrayBuffer = buf.buffer;
console.info(JSON.stringify(new Uint8Array(arrayBuffer)));
// Output: {"0":49,"1":50,"2":51,"3":54}
console.info(JSON.stringify(buf.byteOffset));
// Output: 0
```

### compare

compare(target: Buffer | Uint8Array, targetStart?: number, targetEnd?: number, sourceStart?: number, sourceEnd?: number): -1 | 0 | 1

Compares this **Buffer** object with another object.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| target | [Buffer](#buffer) \| Uint8Array | Yes| Target **Buffer** object to compare.|
| targetStart | number | No| Offset to the start of the data to compare in the target **Buffer** object. The default value is **0**.|
| targetEnd | number | No| Offset to the end of the data to compare in the target **Buffer** object (not inclusive). The default value is the length of the target **Buffer** object.|
| sourceStart | number | No| Offset to the start of the data to compare in this **Buffer** object. The default value is **0**.|
| sourceEnd | number | No| Offset to the end of the data to compare in this **Buffer** object (not inclusive). The default value is the length of this **Buffer** object.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Comparison result. The value **0** is returned if the two **Buffer** objects are the same; **1** is returned if this object comes after the target object when sorted; **-1** is returned if this object comes before the target object when sorted.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200001 | The value of "[targetStart/targetEnd/sourceStart/sourceEnd]" is out of range. |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf1 = buffer.from([1, 2, 3, 4, 5, 6, 7, 8, 9]);
let buf2 = buffer.from([5, 6, 7, 8, 9, 1, 2, 3, 4]);

console.info(buf1.compare(buf2, 5, 9, 0, 4).toString());
// Output: 0
console.info(buf1.compare(buf2, 0, 6, 4).toString());
// Output: -1
console.info(buf1.compare(buf2, 5, 6, 5).toString());
// Output: 1
```

### copy

copy(target: Buffer| Uint8Array, targetStart?: number, sourceStart?: number, sourceEnd?: number): number

Copies data at the specified position in this **Buffer** object to the specified position in another **Buffer** object.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| target | [Buffer](#buffer) \| Uint8Array | Yes| **Buffer** or **Uint8Array** object to which data is copied.|
| targetStart | number | No| Offset to the start position in the target object where data is copied. The default value is **0**.|
| sourceStart | number | No| Offset to the start position in this **Buffer** object where data is copied. The default value is **0**.|
| sourceEnd | number | No| Offset to the end position in this **Buffer** object (not inclusive). The default value is the length of this **Buffer** object.|

**Return value**

| Type| Description|
| -------- | -------- |
| number |  Total length of the data copied, in bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200001 | The value of "[targetStart/sourceStart/sourceEnd]" is out of range. |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf1 = buffer.allocUninitializedFromPool(26);
let buf2 = buffer.allocUninitializedFromPool(26).fill('!');

for (let i = 0; i < 26; i++) {
  buf1.writeInt8(i + 97, i);
}

buf1.copy(buf2, 8, 16, 20);
console.info(buf2.toString('ascii', 0, 25));
// Output: !!!!!!!!qrst!!!!!!!!!!!!!
```

### entries

entries(): IterableIterator&lt;[number,&nbsp;number]&gt;

Creates and returns an iterator that contains key-value pairs of this **Buffer** object.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;[number,&nbsp;number]&gt; |  Iterator that contains the key and value, both of which are of the number type.|

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from('buffer');
let pair = buf.entries();
let next: IteratorResult<Object[]> = pair.next();
while (!next.done) {
  console.info("buffer: " + next.value);
  /*
  Output: buffer: 0,98
           buffer: 1,117
           buffer: 2,102
           buffer: 3,102
           buffer: 4,101
           buffer: 5,114
  */
  next = pair.next();
}
```

### equals

equals(otherBuffer: Uint8Array | Buffer): boolean

Checks whether this **Buffer** object is the same as another **Buffer** object.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| otherBuffer | Uint8Array \| [Buffer](#buffer) | Yes| **Buffer** object to compare.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Check result. The value **true** is returned if the two objects are the same; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf1 = buffer.from('ABC');
let buf2 = buffer.from('414243', 'hex');
let buf3 = buffer.from('ABCD');

console.info(buf1.equals(buf2).toString());
// Output: true
console.info(buf1.equals(buf3).toString());
// Output: false
```

### fill

fill(value: string | Buffer | Uint8Array | number, offset?: number, end?: number, encoding?: BufferEncoding): Buffer

Fills this **Buffer** object at the specified position. By default, data is filled cyclically.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | string \| [Buffer](#buffer) \| Uint8Array \| number | Yes| Value to fill.|
| offset | number | No| Offset to the start position in this **Buffer** object where data is filled. The default value is **0**.|
| end | number | No| Offset to the end position in this **Buffer** object (not inclusive). The default value is the length of this **Buffer** object.|
| encoding | [BufferEncoding](#bufferencoding) | No| Encoding format (valid only when **value** is a string). The default value is **'utf8'**.|

**Return value**

| Type| Description|
| -------- | -------- |
| [Buffer](#buffer) | **Buffer** object filled with the specified value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200001 | The value of "[offset/end]" is out of range. |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let b = buffer.allocUninitializedFromPool(50).fill('h');
console.info(b.toString());
// Output: hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
```


### includes

includes(value: string | number | Buffer | Uint8Array, byteOffset?: number, encoding?: BufferEncoding): boolean

Checks whether this **Buffer** object contains the specified value.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | string \| number \| [Buffer](#buffer) \| Uint8Array | Yes| Value to match.|
| byteOffset | number | No| Number of bytes to skip before starting to check data. If the offset is a negative number, data is checked from the end of the **Buffer** object. The default value is **0**.|
| encoding | [BufferEncoding](#bufferencoding) | No| Encoding format (valid only when **value** is a string). The default value is **'utf8'**.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Check result. The value **true** is returned if the object contains the specified value; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from('this is a buffer');
console.info(buf.includes('this').toString());
// Output: true
console.info(buf.includes('be').toString());
// Output: false
```

### indexOf

indexOf(value: string | number | Buffer | Uint8Array, byteOffset?: number, encoding?: BufferEncoding): number

Obtains the index of the first occurrence of the specified value in this **Buffer** object. If no match is found, **-1** is returned.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | string \| number \| [Buffer](#buffer) \| Uint8Array | Yes| Value to match.|
| byteOffset | number | No| Number of bytes to skip before starting to check data. If the offset is a negative number, data is checked from the end of the **Buffer** object. The default value is **0**.|
| encoding | [BufferEncoding](#bufferencoding) | No| Encoding format (valid only when **value** is a string). The default value is **'utf8'**.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Index obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from('this is a buffer');
console.info(buf.indexOf('this').toString());
// Output: 0
console.info(buf.indexOf('is').toString());
// Output: 2
```

### keys

keys(): IterableIterator&lt;number&gt;

Creates and returns an iterator that contains the keys of this **Buffer** object.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
|  IterableIterator&lt;number&gt; | Iterator created.|

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from('buffer');
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

### lastIndexOf

lastIndexOf(value: string | number | Buffer | Uint8Array, byteOffset?: number, encoding?: BufferEncoding): number

Obtains the index of the last occurrence of the specified value in this **Buffer** object. If no match is found, **-1** is returned.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | string \| number \| [Buffer](#buffer) \| Uint8Array | Yes| Value to match.|
| byteOffset | number | No| Number of bytes to skip before starting to check data. If the offset is a negative number, data is checked from the end of the **Buffer** object. The default value is the length of this **Buffer** object.|
| encoding | [BufferEncoding](#bufferencoding) | No| Encoding format (valid only when **value** is a string). The default value is **'utf8'**.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Index obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from('this buffer is a buffer');
console.info(buf.lastIndexOf('this').toString());
// Output: 0
console.info(buf.lastIndexOf('buffer').toString());
// Output: 17
```


### readBigInt64BE

readBigInt64BE(offset?: number): bigint

Reads a 64-bit, big-endian, signed big integer from this **Buffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= Buffer.length - 8|

**Return value**

| Type| Description|
| -------- | -------- |
| bigint | Data read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1.Incorrect parameter types. |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 8. Received value is: [offset]. |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from([0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x70,
  0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78]);
console.info(buf.readBigInt64BE(0).toString());
// Output: 7161960797921896816

let buf1 = buffer.allocUninitializedFromPool(8);
let result = buf1.writeBigInt64BE(BigInt(0x0102030405060708), 0);
console.info("result = " + result);
// Output: result = 8
```

### readBigInt64LE

readBigInt64LE(offset?: number): bigint

Reads a 64-bit, little-endian, signed big integer from this **Buffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= Buffer.length - 8|

**Return value**

| Type| Description|
| -------- | -------- |
| bigint | Data read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1.Incorrect parameter types. |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 8. Received value is: [offset]. |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from([0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x70,
  0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78]);
console.info(buf.readBigUInt64LE(0).toString());
// Output: 8100120198111388771

let buf1 = buffer.allocUninitializedFromPool(8);
let result = buf1.writeBigUInt64BE(BigInt(0xdecafafecacefade), 0);
console.info("result = " + result);
// Output: result = 8
```

### readBigUInt64BE

readBigUInt64BE(offset?: number): bigint

Reads a 64-bit, big-endian, unsigned big integer from this **Buffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= Buffer.length - 8|

**Return value**

| Type| Description|
| -------- | -------- |
| bigint | Data read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1.Incorrect parameter types. |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 8. Received value is: [offset]. |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from([0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x70,
  0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78]);
console.info(buf.readBigUInt64BE(0).toString());
// Output: 7161960797921896816
let buf1 = buffer.allocUninitializedFromPool(8);
let result = buf1.writeBigUInt64BE(BigInt(0xdecafafecacefade), 0);
console.info("result = " + result);
// Output: result = 8
```

### readBigUInt64LE

readBigUInt64LE(offset?: number): bigint

Reads a 64-bit, little-endian, unsigned big integer from this **Buffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= Buffer.length - 8|

**Return value**

| Type| Description|
| -------- | -------- |
| bigint | Data read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1.Incorrect parameter types. |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 8. Received value is: [offset]. |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from([0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x70,
  0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78]);
console.info(buf.readBigUInt64LE(0).toString());
// Output: 8100120198111388771

let buf1 = buffer.allocUninitializedFromPool(8);
let result = buf1.writeBigUInt64BE(BigInt(0xdecafafecacefade), 0);
console.info("result = " + result);
// Output: result = 8
```

### readDoubleBE

readDoubleBE(offset?: number): number

Reads a 64-bit, big-endian, double-precision floating-point number from this **Buffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= Buffer.length - 8|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Data read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1.Incorrect parameter types. |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 8. Received value is: [offset]. |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from([1, 2, 3, 4, 5, 6, 7, 8]);
console.info(buf.readDoubleBE(0).toString());
// Output: 8.20788039913184e-304
let buf1 = buffer.allocUninitializedFromPool(8);
let result = buf1.writeDoubleBE(123.456, 0);
console.info("result = " + result);
// Output: result = 8
```

### readDoubleLE

readDoubleLE(offset?: number): number

Reads a 64-bit, little-endian, double-precision floating-point number from this **Buffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= Buffer.length - 8|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Data read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1.Incorrect parameter types. |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 8. Received value is: [offset]. |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from([1, 2, 3, 4, 5, 6, 7, 8]);
console.info(buf.readDoubleLE(0).toString());
// Output: 5.447603722011605e-270
let buf1 = buffer.allocUninitializedFromPool(8);
let result = buf1.writeDoubleLE(123.456, 0);
console.info("result = " + result);
// Output: result = 8
```

### readFloatBE

readFloatBE(offset?: number): number

Reads a 32-bit, big-endian, single-precision floating-point number from this **Buffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= Buffer.length - 4|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Data read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1.Incorrect parameter types. |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 4. Received value is: [offset]. |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from([1, 2, 3, 4, 5, 6, 7, 8]);
console.info(buf.readFloatBE(0).toString());
// Output: 2.387939260590663e-38
let buf1 = buffer.allocUninitializedFromPool(4);
let result = buf1.writeFloatBE(0xcabcbcbc, 0);
console.info("result = " + result);
// Output: result = 4
```

### readFloatLE

readFloatLE(offset?: number): number

Reads a 32-bit, little-endian, single-precision floating-point number from this **Buffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= Buffer.length - 4|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Data read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1.Incorrect parameter types. |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 4. Received value is: [offset]. |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from([1, 2, 3, 4, 5, 6, 7, 8]);
console.info(buf.readFloatLE(0).toString());
// Output: 1.539989614439558e-36
let buf1 = buffer.allocUninitializedFromPool(4);
let result = buf1.writeFloatLE(0xcabcbcbc, 0);
console.info("result = " + result);
// Output: result = 4
```

### readInt8

readInt8(offset?: number): number

Reads an 8-bit signed integer from this **Buffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= Buffer.length - 1|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Data read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1.Incorrect parameter types. |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 1. Received value is: [offset]. |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from([-1, 5]);
console.info(buf.readInt8(0).toString());
// Output: 0
console.info(buf.readInt8(1).toString());
// Output: 5
let buf1 = buffer.allocUninitializedFromPool(2);
let result = buf1.writeInt8(0x12);
console.info("result = " + result);
// Output: result = 1
```

### readInt16BE

readInt16BE(offset?: number): number

Reads a 16-bit, big-endian, signed integer from this **Buffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= Buffer.length - 2|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Data read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1.Incorrect parameter types. |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 2. Received value is: [offset]. |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from([0, 5]);
console.info(buf.readInt16BE(0).toString());
// Output: 5
let buf1 = buffer.alloc(2);
let result = buf1.writeInt16BE(0x1234, 0);
console.info("result = " + result);
// Output: result = 2
```

### readInt16LE

readInt16LE(offset?: number): number

Reads a 16-bit, little-endian, signed integer from this **Buffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= Buffer.length - 2|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Data read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1.Incorrect parameter types. |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 2. Received value is: [offset]. |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from([0, 5]);
console.info(buf.readInt16LE(0).toString());
// Output: 1280
let buf1 = buffer.alloc(2);
let result = buf1.writeInt16BE(0x1234, 0);
console.info("result = " + result);
// Output: result = 2
```

### readInt32BE

readInt32BE(offset?: number): number

Reads a 32-bit, big-endian, signed integer from this **Buffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= Buffer.length - 4|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Data read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1.Incorrect parameter types. |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 4. Received value is: [offset]. |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from([0, 0, 0, 5]);
console.info(buf.readInt32BE(0).toString());
// Output: 5
let buf1 = buffer.alloc(4);
let result = buf1.writeInt32BE(0x12345678, 0);
console.info("result = " + result);
// Output: result = 4
```

### readInt32LE

readInt32LE(offset?: number): number

Reads a 32-bit, little-endian, signed integer from this **Buffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= Buffer.length - 4|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Data read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1.Incorrect parameter types. |
| 10200001 |  The value of "offset" is out of range. It must be >= 0 and <= buf.length - 4. Received value is: [offset]. |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from([0, 0, 0, 5]);
console.info(buf.readInt32LE(0).toString());
// Output: 83886080
let buf1 = buffer.alloc(4);
let result = buf1.writeInt32BE(0x12345678, 0);
console.info("result = " + result);
// Output: result = 4
```

### readIntBE

readIntBE(offset: number, byteLength: number): number

Reads the specified number of bytes from this **Buffer** object at the specified offset, and interprets the result as a big-endian, two's complement signed value that supports up to 48 bits of precision.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| offset | number | Yes| Offset. The default value is **0**. Value range: 0 <= offset <= Buffer.length - byteLength|
| byteLength | number | Yes| Number of bytes to read. Value range: 1 <= byteLength <= 6|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Data read. If the offset is a decimal, undefined is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from("ab");
let num = buf.readIntBE(0, 1);
console.info(num.toString());
// Output: 97
let buf1 = buffer.allocUninitializedFromPool(6);
let result = buf1.writeIntBE(0x123456789011, 0, 6);
console.info("result = " + result);
// Output: result = 6
```


### readIntLE

readIntLE(offset: number, byteLength: number): number

Reads the specified number of bytes from this **Buffer** object at the specified offset and interprets the result as a little-endian, two's complement signed value that supports up to 48 bits of precision.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| offset | number | Yes| Offset. The default value is **0**. Value range: 0 <= offset <= Buffer.length - byteLength|
| byteLength | number | Yes| Number of bytes to read. Value range: 1 <= byteLength <= 6|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Data read. If the offset is a decimal, undefined is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from([0x12, 0x34, 0x56, 0x78, 0x90, 0xab]);
console.info(buf.readIntLE(0, 6).toString(16));
// Output: -546f87a9cbee
let buf1 = buffer.allocUninitializedFromPool(6);
let result = buf1.writeIntLE(0x123456789011, 0, 6);
console.info("result = " + result);
// Output: result = 6
```

### readUInt8

readUInt8(offset?: number): number

Reads an 8-bit unsigned integer from this **Buffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= Buffer.length - 1|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Data read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Incorrect parameter types. |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 1. Received value is: [offset]. |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from([1, -2]);
console.info(buf.readUInt8(0).toString());
// Output: 1
console.info(buf.readUInt8(1).toString());
// Output: 0
let buf1 = buffer.allocUninitializedFromPool(4);
let result = buf1.writeUInt8(0x42);
console.info("result = " + result);
// Output: result = 1
```

### readUInt16BE

readUInt16BE(offset?: number): number

Reads a 16-bit, big-endian, unsigned integer from this **Buffer** object at the specified offset.

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= Buffer.length - 2|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Data read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Incorrect parameter types. |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 2. Received value is: [offset]. |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from([0x12, 0x34, 0x56]);
console.info(buf.readUInt16BE(0).toString(16));
// Output: 1234
console.info(buf.readUInt16BE(1).toString(16));
// Output: 3456
let buf1 = buffer.allocUninitializedFromPool(4);
let result = buf1.writeUInt16BE(0x1234, 0);
console.info("result = " + result);
// Output: result = 2
```

### readUInt16LE

readUInt16LE(offset?: number): number

Reads a 16-bit, little-endian, unsigned integer from this **Buffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= Buffer.length - 2|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Data read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Incorrect parameter types. |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 2. Received value is: [offset]. |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from([0x12, 0x34, 0x56]);
console.info(buf.readUInt16LE(0).toString(16));
// Output: 3412
console.info(buf.readUInt16LE(1).toString(16));
// Output: 5634
let buf1 = buffer.allocUninitializedFromPool(4);
let result = buf1.writeUInt16LE(0x1234, 0);
console.info("result = " + result);
// Output: result = 2
```

### readUInt32BE

readUInt32BE(offset?: number): number

Reads a 32-bit, big-endian, unsigned integer from this **Buffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= Buffer.length - 4|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Data read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Incorrect parameter types. |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 4. Received value is: [offset]. |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from([0x12, 0x34, 0x56, 0x78]);
console.info(buf.readUInt32BE(0).toString(16));
// Output: 12345678
let buf1 = buffer.allocUninitializedFromPool(4);
let result = buf1.writeUInt32BE(0x12345678, 0);
console.info("result = " + result);
// Output: result = 4
```

### readUInt32LE

readUInt32LE(offset?: number): number

Reads a 32-bit, little-endian, unsigned integer from this **Buffer** object at the specified offset.

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= Buffer.length - 4|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Data read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Incorrect parameter types. |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 4. Received value is: [offset]. |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from([0x12, 0x34, 0x56, 0x78]);
console.info(buf.readUInt32LE(0).toString(16));
// Output: 78563412
let buf1 = buffer.allocUninitializedFromPool(4);
let result = buf1.writeUInt32LE(0x12345678, 0);
console.info("result = " + result);
// Output: result = 4
```

### readUIntBE

readUIntBE(offset: number, byteLength: number): number

Reads the specified number of bytes from this **Buffer** object at the specified offset, and interprets the result as an unsigned, big-endian integer that supports up to 48 bits of precision.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| offset | number | Yes| Offset. The default value is **0**. Value range: 0 <= offset <= Buffer.length - byteLength|
| byteLength | number | Yes| Number of bytes to read.  Value range: 1 <= byteLength <= 6|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Data read. If the offset is a decimal, undefined is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from([0x12, 0x34, 0x56, 0x78, 0x90, 0xab]);
console.info(buf.readUIntBE(0, 6).toString(16));
// Output: 1234567890ab
let buf1 = buffer.allocUninitializedFromPool(4);
let result = buf1.writeUIntBE(0x13141516, 0, 4);
console.info("result = " + result);
// Output: result = 4
```

### readUIntLE

readUIntLE(offset: number, byteLength: number): number

Reads the specified number of bytes from this **Buffer** object at the specified offset, and interprets the result as an unsigned, little-endian integer that supports up to 48 bits of precision.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| offset | number | Yes| Offset. The default value is **0**. Value range: 0 <= offset <= Buffer.length - byteLength|
| byteLength | number | Yes| Number of bytes to read. Value range: 1 <= byteLength <= 6|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Data read. If the offset is a decimal, undefined is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from([0x12, 0x34, 0x56, 0x78, 0x90, 0xab]);
console.info(buf.readUIntLE(0, 6).toString(16));
// Output: ab9078563412
let buf1 = buffer.allocUninitializedFromPool(4);
let result = buf1.writeUIntLE(0x13141516, 0, 4);
console.info("result = " + result);
// Output: result = 4
```

### subarray

subarray(start?: number, end?: number): Buffer

Truncates this **Buffer** object from the specified position to create a new **Buffer** object.

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| start | number | No| Offset to the start position in this **Buffer** object where data is truncated. The default value is **0**.|
| end | number | No|  Offset to the end position in this **Buffer** object (not inclusive). The default value is the length of this **Buffer** object.|

**Return value**

| Type| Description|
| -------- | -------- |
| [Buffer](#buffer) | **Buffer** object created. When the value of **start** or **end** is less than **0**, an empty buffer is returned.|

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf1 = buffer.allocUninitializedFromPool(26);

for (let i = 0; i < 26; i++) {
  buf1.writeInt8(i + 97, i);
}
const buf2 = buf1.subarray(0, 3);
console.info(buf2.toString('ascii', 0, buf2.length));
// Output: abc
```

### swap16

swap16(): Buffer

Converts this **Buffer** object into an array of unsigned 16-bit integers and swaps the byte order in place.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang


**Return value**

| Type| Description|
| -------- | -------- |
| [Buffer](#buffer) | **Buffer** object swapped.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200009 | The buffer size must be a multiple of 16-bits. |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf1 = buffer.from([0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8]);
console.info(buf1.toString('hex'));
// Output: 0102030405060708
buf1.swap16();
console.info(buf1.toString('hex'));
// Output: 0201040306050807
```

### swap32

swap32(): Buffer

Converts this **Buffer** object into an array of unsigned 32-bit integers and swaps the byte order in place.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang


**Return value**

| Type| Description|
| -------- | -------- |
| [Buffer](#buffer) | **Buffer** object swapped.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200009 | The buffer size must be a multiple of 32-bits. |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf1 = buffer.from([0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8]);
console.info(buf1.toString('hex'));
// Output: 0102030405060708
buf1.swap32();
console.info(buf1.toString('hex'));
// Output: 0403020108070605
```

### swap64

swap64(): Buffer

Converts this **Buffer** object into an array of unsigned 64-bit integers and swaps the byte order in place.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang


**Return value**

| Type| Description|
| -------- | -------- |
| [Buffer](#buffer) | **Buffer** object swapped.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200009 | The buffer size must be a multiple of 64-bits. |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf1 = buffer.from([0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8]);
console.info(buf1.toString('hex'));
// Output: 0102030405060708
buf1.swap64();
console.info(buf1.toString('hex'));
// Output: 0807060504030201
```

### toJSON

toJSON(): Object

Converts this **Buffer** object into a JSON object.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang


**Return value**

| Type| Description|
| -------- | -------- |
| Object | JSON object.|

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf1 = buffer.from([0x1, 0x2, 0x3, 0x4, 0x5]);
let obj = buf1.toJSON();
console.info(JSON.stringify(obj));
// Output: {"type":"Buffer","data":[1,2,3,4,5]}
```

### toString

toString(encoding?: string, start?: number, end?: number): string

Converts the data at the specified position in this **Buffer** object into a string in the specified encoding format.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| encoding | string | No| Encoding format (valid only when **value** is a string). The default value is **'utf8'**.|
| start  | number | No|  Offset to the start position of the data to convert. The default value is **0**.|
| end  | number | No|  Offset to the end position of the data to convert. The default value is the length of this **Buffer** object.|

**Return value**

| Type| Description|
| -------- | -------- |
| string | String. When the value of **start** is greater than or equal to **Buffer.length** or **start** is greater than **end**, an empty string is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Incorrect parameter types. |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf1 = buffer.allocUninitializedFromPool(26);
for (let i = 0; i < 26; i++) {
  buf1.writeInt8(i + 97, i);
}
console.info(buf1.toString('utf-8'));
// Output: abcdefghijklmnopqrstuvwxyz
```

### values

values(): IterableIterator&lt;number&gt;

Creates and returns an iterator that contains the values of this **Buffer** object.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;number&gt; | Iterator.|

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf1 = buffer.from('buffer');
let pair = buf1.values();
let next:IteratorResult<number> = pair.next();
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

### write

write(str: string, offset?: number, length?: number, encoding?: string): number

Writes a string of the specified length to this **Buffer** object at the specified position in the given encoding format.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| str | string | Yes| String to write.|
| offset | number | No| Offset. The default value is **0**.|
| length | number | No| Maximum number of bytes to write. The default value is **Buffer.length** minus **offset**.|
| encoding | string | No| Encoding format of the string. The default value is **'utf8'**.|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Number of bytes written.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200001 | The value of "[offset/length]" is out of range. It must be >= 0 and <= buf.length. Received value is: [offset/length]. |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.alloc(256);
let len = buf.write('\u00bd + \u00bc = \u00be', 0);
console.info(`${len} bytes: ${buf.toString('utf-8', 0, len)}`);
// Output: 12 bytes: ½ + ¼ = ¾

let buffer1 = buffer.alloc(10);
let length = buffer1.write('abcd', 8);
console.info("length = " + length);
// Output: length = 2
```

### writeBigInt64BE

writeBigInt64BE(value: bigint, offset?: number): number

Writes a 64-bit, big-endian, signed big integer to this **Buffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | bigint | Yes| Data to write.|
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= Buffer.length - 8|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Offset plus the number of written bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(8);
let result = buf.writeBigInt64BE(BigInt(0x0102030405060708), 0);
console.info("result = " + result);
// Output: result = 8
```

### writeBigInt64LE

writeBigInt64LE(value: bigint, offset?: number): number

Writes a 64-bit, little-endian, signed big integer to this **Buffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | bigint | Yes| Data to write.|
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= Buffer.length - 8|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Offset plus the number of written bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(8);
let result = buf.writeBigInt64LE(BigInt(0x0102030405060708), 0);
console.info("result = " + result);
// Output: result = 8
```

### writeBigUInt64BE

writeBigUInt64BE(value: bigint, offset?: number): number

**Atomic service API**: This API can be used in atomic services since API version 11.

Writes a 64-bit, big-endian, unsigned big integer to this **Buffer** object at the specified offset.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | bigint | Yes| Data to write.|
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= Buffer.length - 8|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Offset plus the number of written bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(8);
let result = buf.writeBigUInt64BE(BigInt(0xdecafafecacefade), 0);
console.info("result = " + result);
// Output: result = 8
```

### writeBigUInt64LE

writeBigUInt64LE(value: bigint, offset?: number): number

Writes a 64-bit, little-endian, unsigned big integer to this **Buffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | bigint | Yes| Data to write.|
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= Buffer.length - 8|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Offset plus the number of written bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(8);
let result = buf.writeBigUInt64LE(BigInt(0xdecafafecacefade), 0);
console.info("result = " + result);
// Output: result = 8
```

### writeDoubleBE

writeDoubleBE(value: number, offset?: number): number

Writes a 64-bit, big-endian, double-precision floating-point number to this **Buffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Data to write.|
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= Buffer.length - 8|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Offset plus the number of written bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 8. Received value is: [offset] |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(8);
let result = buf.writeDoubleBE(123.456, 0);
console.info("result = " + result);
// Output: result = 8
```

### writeDoubleLE

writeDoubleLE(value: number, offset?: number): number

Writes a 64-bit, little-endian, double-precision floating-point number to this **Buffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Data to write.|
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= Buffer.length - 8|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Offset plus the number of written bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 8. Received value is: [offset] |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(8);
let result = buf.writeDoubleLE(123.456, 0);
console.info("result = " + result);
// Output: result = 8
```

### writeFloatBE

writeFloatBE(value: number, offset?: number): number

Writes a 32-bit, big-endian, single-precision floating-point number to this **Buffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Data to write.|
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= Buffer.length - 4|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Offset plus the number of written bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 4. Received value is: [offset] |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(8);
let result = buf.writeFloatBE(0xcafebabe, 0);
console.info("result = " + result);
// Output: result = 4
```


### writeFloatLE

writeFloatLE(value: number, offset?: number): number

Writes a 32-bit, little-endian, single-precision floating-point number to this **Buffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Data to write.|
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= Buffer.length - 4|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Offset plus the number of written bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 4. Received value is: [offset] |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(8);
let result = buf.writeFloatLE(0xcafebabe, 0);
console.info("result = " + result);
// Output: result = 4
```

### writeInt8

writeInt8(value: number, offset?: number): number

Writes an 8-bit signed integer to this **Buffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Data to write.|
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= Buffer.length - 1|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Offset plus the number of written bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(2);
let result = buf.writeInt8(2, 0);
console.info("result = " + result);
// Output: result = 1
let result1 = buf.writeInt8(-2, 1);
console.info("result1 = " + result1);
// Output: result1 = 2
```


### writeInt16BE

writeInt16BE(value: number, offset?: number): number

Writes a 16-bit, big-endian, signed integer to this **Buffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Data to write.|
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= Buffer.length - 2|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Offset plus the number of written bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(2);
let result = buf.writeInt16BE(0x0102, 0);
console.info("result = " + result);
// Output: result = 2
```


### writeInt16LE

writeInt16LE(value: number, offset?: number): number

Writes a 16-bit, little-endian, signed integer to this **Buffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Data to write.|
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= Buffer.length - 2|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Offset plus the number of written bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(2);
let result = buf.writeInt16LE(0x0304, 0);
console.info("result = " + result);
// Output: result = 2
```

### writeInt32BE

writeInt32BE(value: number, offset?: number): number

Writes a 32-bit, big-endian, signed integer to this **Buffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Data to write.|
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= Buffer.length - 4|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Offset plus the number of written bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(4);
let result = buf.writeInt32BE(0x01020304, 0);
console.info("result = " + result);
// Output: result = 4
```


### writeInt32LE

writeInt32LE(value: number, offset?: number): number

Writes a 32-bit, little-endian, signed integer to this **Buffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Data to write.|
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= Buffer.length - 4|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Offset plus the number of written bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(4);
let result = buf.writeInt32LE(0x05060708, 0);
console.info("result = " + result);
// Output: result = 4
```

### writeIntBE

writeIntBE(value: number, offset: number, byteLength: number): number

Writes a big-endian signed value of the specified length to this **Buffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Data to write.|
| offset | number | Yes| Offset. The default value is **0**. Value range: 0 <= offset <= Buffer.length - byteLength|
| byteLength | number | Yes| Number of bytes to write.|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Offset plus the number of written bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(6);
let result = buf.writeIntBE(0x1234567890ab, 0, 6);
console.info("result = " + result);
// Output: result = 6
```


### writeIntLE

writeIntLE(value: number, offset: number, byteLength: number): number

Writes a little-endian signed value of the specified length to this **Buffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Data to write.|
| offset | number | Yes| Offset. The default value is **0**. Value range: 0 <= offset <= Buffer.length - byteLength|
| byteLength | number | Yes| Number of bytes to write.|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Offset plus the number of written bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(6);
let result = buf.writeIntLE(0x1234567890ab, 0, 6);
console.info("result = " + result);
// Output: result = 6
```

### writeUInt8

writeUInt8(value: number, offset?: number): number

Writes an 8-bit unsigned integer to this **Buffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Data to write.|
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= Buffer.length - 1|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Offset plus the number of written bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(4);
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

Writes a 16-bit, big-endian, unsigned integer to this **Buffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Data to write.|
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= Buffer.length - 2|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Offset plus the number of written bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(4);
let result = buf.writeUInt16BE(0xdead, 0);
console.info("result = " + result);
// Output: result = 2
let result1 = buf.writeUInt16BE(0xbeef, 2);
console.info("result1 = " + result1);
// Output: result1 = 4
```

### writeUInt16LE

writeUInt16LE(value: number, offset?: number): number

Writes a 16-bit, little-endian, unsigned integer to this **Buffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Data to write.|
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= Buffer.length - 2|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Offset plus the number of written bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(4);
let result = buf.writeUInt16LE(0xdead, 0);
console.info("result = " + result);
// Output: result = 2
let result1 = buf.writeUInt16LE(0xbeef, 2);
console.info("result1 = " + result1);
// Output: result1 = 4
```

### writeUInt32BE

writeUInt32BE(value: number, offset?: number): number

Writes a 32-bit, big-endian, unsigned integer to this **Buffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Data to write.|
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= Buffer.length - 4|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Offset plus the number of written bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(4);
let result = buf.writeUInt32BE(0xfeedface, 0);
console.info("result = " + result);
// Output: result = 4
```

### writeUInt32LE

writeUInt32LE(value: number, offset?: number): number

Writes a 32-bit, little-endian, unsigned integer to this **Buffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Data to write.|
| offset | number | No| Offset. The default value is **0**. Value range: 0 <= offset <= Buffer.length - 4|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Offset plus the number of written bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(4);
let result = buf.writeUInt32LE(0xfeedface, 0);
console.info("result = " + result);
// Output: result = 4
```

### writeUIntBE

writeUIntBE(value: number, offset: number, byteLength: number): number

Writes an unsigned big-endian value of the specified length to this **Buffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Data to write.|
| offset | number | Yes| Offset. The default value is **0**. Value range: 0 <= offset <= Buffer.length - byteLength|
| byteLength | number | Yes| Number of bytes to write.|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Offset plus the number of written bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(6);
let result = buf.writeUIntBE(0x1234567890ab, 0, 6);
console.info("result = " + result);
// Output: result = 6
```

### writeUIntLE

writeUIntLE(value: number, offset: number, byteLength: number): number

Writes an unsigned little-endian value of the specified length to this **Buffer** object at the specified offset.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Data to write.|
| offset | number | Yes| Offset. The default value is **0**. Value range: 0 <= offset <= Buffer.length - byteLength|
| byteLength | number | Yes| Number of bytes to write.|


**Return value**

| Type| Description|
| -------- | -------- |
| number | Offset plus the number of written bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**Example**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(6);
let result = buf.writeUIntLE(0x1234567890ab, 0, 6);
console.info("result = " + result);
// Output: result = 6
```

## Blob

### Properties

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| size | number | Yes| No| Total size of the **Blob** object, in bytes.|
| type | string | Yes| No| Type of the data in the **Blob** object.|

### constructor

constructor(sources: string[] | ArrayBuffer[] | TypedArray[] | DataView[] | Blob[] , options?: Object)

A constructor used to create a **Blob** object.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| sources | string[]&nbsp;\|&nbsp;ArrayBuffer[]&nbsp;\|&nbsp;TypedArray[]&nbsp;\|&nbsp;DataView[]&nbsp;\|&nbsp;Blob[] | Yes| Data sources of the **Blob** object.|
| options | Object | No| options:<br>- **endings**: specifies how the terminator **'\n'** is output. The value can be **'native'** or **'transparent'**. **'native'** means that the terminator follows the system. **'transparent'** means that the terminator stored in the **Blob** object remains unchanged. The default value is **'transparent'**.<br>- **type**: type of the data in the **Blob** object. This type represents the MIME type of the data. However, it is not used for type format validation. The default value is **''**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**
```ts
import { buffer } from '@kit.ArkTS';

let blob: buffer.Blob  = new buffer.Blob(['a', 'b', 'c']);

class option {
  endings: string = "";
  type: string = "";
}
let o1: option = {endings:'native', type: 'MIME'}
let blob1: buffer.Blob = new buffer.Blob(['a', 'b', 'c'], o1);
```

### arrayBuffer

arrayBuffer(): Promise&lt;ArrayBuffer&gt;

Puts the **Blob** data into an **ArrayBuffer** object. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Return value**
| Type| Description|
| -------- | -------- |
| Promise&lt;ArrayBuffer&gt; | Promise used to return the **ArrayBuffer** containing the **Blob** data.|

**Example**
```ts
import { buffer } from '@kit.ArkTS';

let blob: buffer.Blob = new buffer.Blob(['a', 'b', 'c']);
let pro = blob.arrayBuffer();
pro.then((val: ArrayBuffer) => {
  let uint8Array: Uint8Array = new Uint8Array(val);
  console.info(uint8Array.toString());
  // Output: 97,98,99
});
```
### slice

slice(start?: number, end?: number, type?: string): Blob

Creates and returns a **Blob** object that contains specified data from this **Blob** object.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| start | number | No| Offset to the start position of the data to copy. The default value is **0**.|
| end | number | No| Offset to the end position of the data to copy. The default value is the data length in the original **Blob** object.|
| type | string | No| Type of the data in the new **Blob** object. The default value is **''**.|

**Return value**
| Type| Description|
| -------- | -------- |
| Blob | New **Blob** object created.|

**Example**
```ts
import { buffer } from '@kit.ArkTS';

let blob: buffer.Blob = new buffer.Blob(['a', 'b', 'c']);
let blob2 = blob.slice(0, 2);
let blob3 = blob.slice(0, 2, "MIME");
console.info("type:", blob3.type); // type: MIME
```

### text

text(): Promise&lt;string&gt;

Decodes data using UTF-8 and returns a string. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Return value**
| Type| Description|
| -------- | -------- |
| Promise&lt;string&gt; | Promise used to return the string decoded using UTF-8.|

**Example**
```ts
import { buffer } from '@kit.ArkTS';

let blob: buffer.Blob = new buffer.Blob(['a', 'b', 'c']);
let pro = blob.text();
pro.then((val: string) => {
  console.info(val);
  // Output: abc
});
```
