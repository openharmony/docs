# @ohos.buffer (Buffer)

Buffer对象用于表示固定长度的字节序列，是专门存放二进制数据的缓存区。

**推荐使用场景：** 可用于处理大量二进制数据，图片处理、文件接收上传等。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { buffer } from '@kit.ArkTS';
```

## BufferEncoding

表示支持的编码格式类型。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

| 类型    | 说明                 |
| ------- | -------------------- |
| 'ascii' | 表示ascii格式。 |
| 'utf8' | 表示utf8格式。 |
| 'utf-8' | 表示utf8格式。 |
| 'utf16le' | 表示utf16小端序格式。 |
| 'ucs2' | utf16le的别名。 |
| 'ucs-2' | utf16le的别名。 |
| 'base64' | 表示base64格式。 |
| 'base64url' | 表示base64url格式。 |
| 'latin1' | iso-8859-1的别名, 向下兼容ascii格式。 |
| 'binary' | 表示二进制格式。 |
| 'hex' | 表示十六进制格式。 |

## buffer.alloc

alloc(size: number, fill?: string | Buffer | number, encoding?: BufferEncoding): Buffer

创建一定字节长度的Buffer对象，并初始化。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| size | number | 是 | 指定的Buffer对象长度，单位：字节。 |
| fill | string&nbsp;\|&nbsp;Buffer&nbsp;\|&nbsp;number | 否 | 填充至新缓存区的值，默认值: 0。 |
| encoding | [BufferEncoding](#bufferencoding) | 否 | 编码格式（当`fill`为string时，才有意义）。 默认值: 'utf8'。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Buffer | 返回一个Buffer对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf1 = buffer.alloc(5);
let buf2 = buffer.alloc(5, 'a');
let buf3 = buffer.alloc(11, 'aGVsbG8gd29ybGQ=', 'base64');
```

## buffer.allocUninitializedFromPool

allocUninitializedFromPool(size: number): Buffer

创建指定大小未被初始化的Buffer对象。内存从缓冲池分配。
创建的Buffer的内容未知，需要使用[fill](#fill)函数来初始化Buffer对象。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| size | number | 是 | 指定的Buffer对象长度，单位：字节。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Buffer | 未初始化的Buffer实例。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(10);
buf.fill(0);
```

## buffer.allocUninitialized

allocUninitialized(size: number): Buffer

创建指定大小未被初始化的Buffer实例。内存不从缓冲池分配。
创建的Buffer的内容未知，需要使用[fill](#fill)函数来初始化Buffer对象。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| size | number | 是 |指定的Buffer对象长度，单位：字节。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Buffer | 未初始化的Buffer实例。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitialized(10);
buf.fill(0);
```

## buffer.byteLength

byteLength(string: string | Buffer | TypedArray | DataView | ArrayBuffer | SharedArrayBuffer, encoding?: BufferEncoding): number

根据不同的编码方法，返回指定字符串的字节数。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| string | string&nbsp;\|&nbsp;Buffer&nbsp;\|&nbsp;TypedArray&nbsp;\|&nbsp;DataView&nbsp;\|&nbsp;ArrayBuffer&nbsp;\|&nbsp;SharedArrayBuffer | 是 | 指定字符串。 |
| encoding | [BufferEncoding](#bufferencoding) | 否 | 编码格式。 默认值: 'utf8'。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回指定字符串的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let str = '\u00bd + \u00bc = \u00be';
console.log(`${str}: ${str.length} characters, ${buffer.byteLength(str, 'utf-8')} bytes`);
// 打印: ½ + ¼ = ¾: 9 characters, 12 bytes
```

## buffer.compare

compare(buf1: Buffer | Uint8Array, buf2: Buffer | Uint8Array): -1 | 0 | 1

返回两个数组的比较结果，通常用于对Buffer对象数组进行排序。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| buf1 | Buffer&nbsp;\|&nbsp;Uint8Array | 是 | 待比较数组。 |
| buf2 | Buffer&nbsp;\|&nbsp;Uint8Array | 是 | 待比较数组。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| -1&nbsp;\|&nbsp;0&nbsp;\|&nbsp;1 | 如果buf1与buf2相同，则返回0。<br/>如果排序时buf1位于buf2之后，则返回1。<br/>如果排序时buf1位于buf2之前，则返回-1。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf1 = buffer.from('1234');
let buf2 = buffer.from('0123');
let res = buf1.compare(buf2);

console.log(Number(res).toString()); // 打印 1
```

## buffer.concat

concat(list: Buffer[] | Uint8Array[], totalLength?: number): Buffer

将数组中的内容复制指定字节长度到新的Buffer对象中并返回。

**系统能力：** SystemCapability.Utils.Lang

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| list | Buffer[]&nbsp;\|&nbsp;Uint8Array[] | 是 | 实例数组。 |
| totalLength | number | 否 | 需要复制的总字节长度，默认值为0。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Buffer | 返回新的Buffer对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200001 | The value of "length" is out of range. It must be >= 0 and <= uint32 max. Received value is: [length] |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf1 = buffer.from("1234");
let buf2 = buffer.from("abcd");
let buf = buffer.concat([buf1, buf2]);
console.log(buf.toString('hex')); // 3132333461626364
```

## buffer.from

from(array: number[]): Buffer;

根据指定数组创建新的Buffer对象。

**系统能力：** SystemCapability.Utils.Lang

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| array | number[] | 是 | 指定数组。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Buffer | 新的Buffer对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from([0x62, 0x75, 0x66, 0x66, 0x65, 0x72]);
console.log(buf.toString('hex')); // 627566666572
```

## buffer.from

from(arrayBuffer: ArrayBuffer | SharedArrayBuffer, byteOffset?: number, length?: number): Buffer

创建指定长度的与`arrayBuffer`共享内存的Buffer对象。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| arrayBuffer | ArrayBuffer&nbsp;\|&nbsp;SharedArrayBuffer | 是 | 实例对象。 |
| byteOffset | number | 否 | 字节偏移量，默认值: 0。 |
| length | number | 否 | 字节长度， 默认值: (arrayBuffer.byteLength - byteOffset)。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Buffer | 返回一个共享内存的Buffer对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200001 | The value of "[byteOffset/length]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [byteOffset/length] |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let ab = new ArrayBuffer(10);
let buf = buffer.from(ab, 0, 2);
```

## buffer.from

from(buffer: Buffer | Uint8Array): Buffer

创建并复制`buffer`数据到新的Buffer对象并返回。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| buffer | Buffer&nbsp;\|&nbsp;Uint8Array | 是 | 对象数据。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Buffer | 新的Buffer对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf1 = buffer.from('buffer');
let buf2 = buffer.from(buf1);
```

## buffer.from

from(object: Object, offsetOrEncoding: number | string, length: number): Buffer

根据指定的`object`类型数据，创建新的Buffer对象。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| object | Object | 是 | 支持Symbol.toPrimitive或valueOf()的对象。 |
| offsetOrEncoding | number&nbsp;\|&nbsp;string | 是 | 字节偏移量或编码格式。 |
| length | number | 是 | 字节长度(此入参仅在object的valueOf()返回值为ArrayBuffer时生效，取值范围：0 <= length <= ArrayBuffer.byteLength, 超出范围时报错: 10200001)。其他情况下可填任意number类型值，该参数不会对结果产生影响。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Buffer | 返回新的Buffer对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from(new String('this is a test'), 'utf8', 14);
```

## buffer.from

from(string: String, encoding?: BufferEncoding): Buffer

根据指定编码格式的字符串，创建新的Buffer对象。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| string | String | 是 | 字符串 |
| encoding | [BufferEncoding](#bufferencoding) | 否 | 编码格式。 默认值: 'utf8'。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Buffer | 返回新的Buffer对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf1 = buffer.from('this is a test');
let buf2 = buffer.from('7468697320697320612074c3a97374', 'hex');

console.log(buf1.toString());	// 打印: this is a test
console.log(buf2.toString()); // 打印: this is a tést
```


## buffer.isBuffer

isBuffer(obj: Object): boolean

判断`obj`是否为Buffer。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| obj | Object | 是 | 判断对象 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果obj是Buffer，则返回true，否则返回false。 |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let result = buffer.isBuffer(buffer.alloc(10)); // true
let result1 = buffer.isBuffer(buffer.from('foo')); // true
let result2 = buffer.isBuffer('a string'); // false
let result3 = buffer.isBuffer([]); // false
let result4 = buffer.isBuffer(new Uint8Array(1024)); // false
```

## buffer.isEncoding

isEncoding(encoding: string): boolean

判断`encoding`是否为支持的编码格式。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| encoding | string | 是 | 编码格式。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 是支持的编码格式返回true，反之则返回false。 |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

console.log(buffer.isEncoding('utf-8').toString());	// 打印: true
console.log(buffer.isEncoding('hex').toString());	// 打印: true
console.log(buffer.isEncoding('utf/8').toString());	// 打印: false
console.log(buffer.isEncoding('').toString());	// 打印: false
```

## buffer.transcode

transcode(source: Buffer | Uint8Array, fromEnc: string, toEnc: string): Buffer

将给定的Buffer或Uint8Array对象从一种字符编码重新编码为另一种。

**系统能力：** SystemCapability.Utils.Lang

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| source | Buffer&nbsp;\|&nbsp;Uint8Array | 是 | 实例对象。 |
| fromEnc | string | 是 | 当前编码。 |
| toEnc | string | 是 | 目标编码。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Buffer | 根据当前编码转换成目标编码，并返回一个新的buffer实例。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let newBuf = buffer.transcode(buffer.from('€'), 'utf-8', 'ascii');
console.log(newBuf.toString('ascii'));
```

## Buffer

### 属性

**系统能力：** SystemCapability.Utils.Lang

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| length | number | 是 | 否 | Buffer对象的字节长度。 |
| buffer | ArrayBuffer | 是 | 否 | ArrayBuffer对象。 |
| byteOffset | number | 是 | 否 | 当前Buffer所在内存池的偏移量。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200013 | ${propertyName} cannot be set for the buffer that has only a getter. |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from("1236");
console.log(JSON.stringify(buf.length));
let arrayBuffer = buf.buffer;
console.log(JSON.stringify(new Uint8Array(arrayBuffer)));
console.log(JSON.stringify(buf.byteOffset));
```

### compare

compare(target: Buffer | Uint8Array, targetStart?: number, targetEnd?: number, sourceStart?: number, sourceEnd?: number): -1 | 0 | 1

当前Buffer对象与目标Buffer对象进行比较，并返回Buffer在排序中的顺序结果。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| target | Buffer&nbsp;\|&nbsp;Uint8Array | 是 | 要比较的实例对象。 |
| targetStart | number | 否 | `target`实例中开始的偏移量。 默认值: 0。 |
| targetEnd | number | 否 | `target`实例中结束的偏移量（不包含结束位置）。 默认值: 目标对象的字节长度。 |
| sourceStart | number | 否 | `this`实例中开始的偏移量。 默认值: 0。 |
| sourceEnd | number | 否 | `this`实例中结束的偏移量（不包含结束位置）。 默认值: 当前对象的字节长度。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回比较结果。-1：当前排列在目标前，0：当前与目标相同，1：当前排列在目标后。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200001 | The value of "[targetStart/targetEnd/sourceStart/sourceEnd]" is out of range. |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf1 = buffer.from([1, 2, 3, 4, 5, 6, 7, 8, 9]);
let buf2 = buffer.from([5, 6, 7, 8, 9, 1, 2, 3, 4]);

console.log(buf1.compare(buf2, 5, 9, 0, 4).toString());	// 打印: 0
console.log(buf1.compare(buf2, 0, 6, 4).toString());	// 打印: -1
console.log(buf1.compare(buf2, 5, 6, 5).toString());	// 打印: 1
```

### copy

copy(target: Buffer| Uint8Array, targetStart?: number, sourceStart?: number, sourceEnd?: number): number

将`this`实例中指定位置的数据复制到`target`的指定位置上，并返回复制的字节总长度。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| target | Buffer&nbsp;\|&nbsp;Uint8Array | 是 | 要复制到的Buffer或Uint8Array实例。 |
| targetStart | number | 否 | `target`实例中开始写入的偏移量。 默认值: 0。 |
| sourceStart | number | 否 | `this`实例中开始复制的偏移量。 默认值: 0。 |
| sourceEnd | number | 否 | `this`实例中结束复制的偏移量（不包含结束位置）。 默认值: 当前对象的字节长度。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number |  复制的字节总长度。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200001 | The value of "[targetStart/sourceStart/sourceEnd]" is out of range. |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf1 = buffer.allocUninitializedFromPool(26);
let buf2 = buffer.allocUninitializedFromPool(26).fill('!');

for (let i = 0; i < 26; i++) {
  buf1.writeInt8(i + 97, i);
}

buf1.copy(buf2, 8, 16, 20);
console.log(buf2.toString('ascii', 0, 25));
// 打印: !!!!!!!!qrst!!!!!!!!!!!!!
```

### entries

entries(): IterableIterator&lt;[number,&nbsp;number]&gt;

返回一个包含key和value的迭代器。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;[number,&nbsp;number]&gt; |  包含key和value的迭代器，同时两者皆为number类型。 |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from('buffer');
let pair = buf.entries();
let next: IteratorResult<Object[]> = pair.next();
while (!next.done) {
  console.info("buffer: " + next.value);
  next = pair.next();
}
```

### equals

equals(otherBuffer: Uint8Array | Buffer): boolean

比较`this`实例和otherBuffer实例是否相等。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| otherBuffer | Uint8Array&nbsp;\|&nbsp;Buffer | 是 | 比较的目标对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 相等则返回true，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf1 = buffer.from('ABC');
let buf2 = buffer.from('414243', 'hex');
let buf3 = buffer.from('ABCD');

console.log(buf1.equals(buf2).toString());	// 打印: true
console.log(buf1.equals(buf3).toString());	// 打印: false
```

### fill

fill(value: string | Buffer | Uint8Array | number, offset?: number, end?: number, encoding?: BufferEncoding): Buffer

用`value`填充当前对象指定位置的数据，默认为循环填充，并返回填充后的Buffer对象。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | string&nbsp;\|&nbsp;Buffer&nbsp;\|&nbsp;Uint8Array&nbsp;\|&nbsp;number | 是 | 用于填充的值。 |
| offset | number | 否 | 起始偏移量。 默认值: 0。 |
| end | number | 否 | 结束偏移量（不包含结束位置）。 默认值: 当前对象的字节长度。 |
| encoding | [BufferEncoding](#bufferencoding) | 否 | 字符编码格式（`value`为string才有意义）。 默认值: 'utf8'。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Buffer | 返回一个填充后的Buffer对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200001 | The value of "[offset/end]" is out of range. |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let b = buffer.allocUninitializedFromPool(50).fill('h');
console.log(b.toString());
```


### includes

includes(value: string | number | Buffer | Uint8Array, byteOffset?: number, encoding?: BufferEncoding): boolean

检查Buffer对象是否包含`value`值。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | string&nbsp;\|&nbsp;number&nbsp;\|&nbsp;Buffer&nbsp;\|&nbsp;Uint8Array | 是 | 要搜索的内容。 |
| byteOffset | number | 否 | 字节偏移量。 如果为负数，则从末尾开始计算偏移量。 默认值: 0。 |
| encoding | [BufferEncoding](#bufferencoding) | 否 | 字符编码格式。 默认值: 'utf8'。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 存在为true，否则为false。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from('this is a buffer');
console.log(buf.includes('this').toString());	// 打印: true
console.log(buf.includes('be').toString());	// 打印: false
```

### indexOf

indexOf(value: string | number | Buffer | Uint8Array, byteOffset?: number, encoding?: BufferEncoding): number

查找当前对象中第一次出现`value`的索引，如果不包含`value`，则为-1。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | string&nbsp;\|&nbsp;number&nbsp;\|&nbsp;Buffer&nbsp;\|&nbsp;Uint8Array | 是 | 要查找的内容。 |
| byteOffset | number | 否 | 字节偏移量。 如果为负数，则从末尾开始计算偏移量。 默认值: 0。 |
| encoding | [BufferEncoding](#bufferencoding) | 否 | 字符编码格式。 默认值: 'utf8'。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 第一次出现位置。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from('this is a buffer');
console.log(buf.indexOf('this').toString());	// 打印: 0
console.log(buf.indexOf('is').toString());		// 打印: 2
```

### keys

keys(): IterableIterator&lt;number&gt;

返回一个包含key值的迭代器。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
|  IterableIterator&lt;number&gt; | 返回一个包含key值的迭代器。 |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from('buffer');
let numbers = Array.from(buf.keys());
for (const key of numbers) {
  console.log(key.toString());
}
```

### lastIndexOf

lastIndexOf(value: string | number | Buffer | Uint8Array, byteOffset?: number, encoding?: BufferEncoding): number

返回`this`实例中最后一次出现`value`的索引，如果对象不包含，则为-1。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | string&nbsp;\|&nbsp;number&nbsp;\|&nbsp;Buffer&nbsp;\|&nbsp;Uint8Array | 是 | 要搜索的内容。 |
| byteOffset | number | 否 | 字节偏移量。 如果为负数，则从末尾开始计算偏移量。 默认值: Buffer.length。 |
| encoding | [BufferEncoding](#bufferencoding) | 否 | 字符编码格式。 默认值: 'utf8'。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 最后一次出现`value`值的索引。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from('this buffer is a buffer');
console.log(buf.lastIndexOf('this').toString());    // 打印: 0
console.log(buf.lastIndexOf('buffer').toString());  // 打印: 17
```


### readBigInt64BE

readBigInt64BE(offset?: number): bigint

从指定的`offset`处读取有符号的大端序64位整数。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。默认值: 0。取值范围：0 <= offset <= Buffer.length - 8 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| bigint | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1.Incorrect parameter types. |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 8. Received value is: [offset]. |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from([0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x70,
        0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78]);
console.log(buf.readBigInt64BE(0).toString());

let buf1 = buffer.allocUninitializedFromPool(8);
let result = buf1.writeBigInt64BE(BigInt(0x0102030405060708), 0);
```

### readBigInt64LE

readBigInt64LE(offset?: number): bigint

从指定的`offset`处读取有符号的小端序64位整数。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。取值范围：0 <= offset <= Buffer.length - 8，默认值: 0。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| bigint | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1.Incorrect parameter types. |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 8. Received value is: [offset]. |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from([0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x70,
        0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78]);
console.log(buf.readBigInt64LE(0).toString());

let buf1 = buffer.allocUninitializedFromPool(8);
let result = buf1.writeBigInt64BE(BigInt(0x0102030405060708), 0);
```

### readBigUInt64BE

readBigUInt64BE(offset?: number): bigint

从指定的`offset`处读取无符号的大端序64位整数。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。取值范围：0 <= offset <= Buffer.length - 8，默认值: 0。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| bigint | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1.Incorrect parameter types. |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 8. Received value is: [offset]. |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from([0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x70,
        0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78]);
console.log(buf.readBigUInt64BE(0).toString());

let buf1 = buffer.allocUninitializedFromPool(8);
let result = buf1.writeBigUInt64BE(BigInt(0xdecafafecacefade), 0);
```

### readBigUInt64LE

readBigUInt64LE(offset?: number): bigint

从指定的`offset`处读取无符号的小端序64位整数。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。取值范围：0 <= offset <= Buffer.length - 8，默认值: 0。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| bigint | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1.Incorrect parameter types. |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 8. Received value is: [offset]. |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from([0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x70,
        0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78]);
console.log(buf.readBigUInt64LE(0).toString());

let buf1 = buffer.allocUninitializedFromPool(8);
let result = buf1.writeBigUInt64BE(BigInt(0xdecafafecacefade), 0);
```

### readDoubleBE

readDoubleBE(offset?: number): number

从指定`offset`处读取64位大端序双精度值。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。取值范围：0 <= offset <= Buffer.length - 8，默认值: 0。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1.Incorrect parameter types. |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 8. Received value is: [offset]. |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from([1, 2, 3, 4, 5, 6, 7, 8]);
console.log(buf.readDoubleBE(0).toString());

let buf1 = buffer.allocUninitializedFromPool(8);
let result = buf1.writeDoubleBE(123.456, 0);
```

### readDoubleLE

readDoubleLE(offset?: number): number

从指定`offset`处读取64位小端序双精度值。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。取值范围：0 <= offset <= Buffer.length - 8，默认值: 0。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1.Incorrect parameter types. |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 8. Received value is: [offset]. |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from([1, 2, 3, 4, 5, 6, 7, 8]);
console.log(buf.readDoubleLE(0).toString());

let buf1 = buffer.allocUninitializedFromPool(8);
let result = buf1.writeDoubleLE(123.456, 0);
```

### readFloatBE

readFloatBE(offset?: number): number

从指定`offset`处读取32位大端序浮点数。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。取值范围：0 <= offset <= Buffer.length - 4，默认值: 0。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1.Incorrect parameter types. |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 4. Received value is: [offset]. |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from([1, 2, 3, 4, 5, 6, 7, 8]);
console.log(buf.readFloatBE(0).toString());

let buf1 = buffer.allocUninitializedFromPool(4);
let result = buf1.writeFloatBE(0xcabcbcbc, 0);
```

### readFloatLE

readFloatLE(offset?: number): number

从指定`offset`处读取32位小端序浮点数。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。取值范围：0 <= offset <= Buffer.length - 4，默认值: 0。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1.Incorrect parameter types. |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 4. Received value is: [offset]. |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from([1, 2, 3, 4, 5, 6, 7, 8]);
console.log(buf.readFloatLE(0).toString());

let buf1 = buffer.allocUninitializedFromPool(4);
let result = buf1.writeFloatLE(0xcabcbcbc, 0);
```

### readInt8

readInt8(offset?: number): number

从指定的`offset`处读取有符号的8位整数。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。取值范围：0 <= offset <= Buffer.length - 1，默认值: 0。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1.Incorrect parameter types. |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 1. Received value is: [offset]. |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from([-1, 5]);
console.log(buf.readInt8(0).toString());	// 打印: 0
console.log(buf.readInt8(1).toString());	// 打印: 5

let buf1 = buffer.allocUninitializedFromPool(2);
let result = buf1.writeInt8(0x12);
```

### readInt16BE

readInt16BE(offset?: number): number

从指定的`offset`处读取有符号的大端序16位整数。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。取值范围：0 <= offset <= Buffer.length - 2，默认值: 0。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1.Incorrect parameter types. |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 2. Received value is: [offset]. |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from([0, 5]);
console.log(buf.readInt16BE(0).toString());	// 打印: 5

let buf1 = buffer.alloc(2);
let result = buf1.writeInt16BE(0x1234, 0);
```

### readInt16LE

readInt16LE(offset?: number): number

从指定的`offset`处读取有符号的小端序16位整数。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。取值范围：0 <= offset <= Buffer.length - 2，默认值: 0。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1.Incorrect parameter types. |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 2. Received value is: [offset]. |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from([0, 5]);
console.log(buf.readInt16LE(0).toString());	// 打印: 1280

let buf1 = buffer.alloc(2);
let result = buf1.writeInt16BE(0x1234, 0);
```

### readInt32BE

readInt32BE(offset?: number): number

从指定的`offset`处读取有符号的大端序32位整数。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。取值范围：0 <= offset <= Buffer.length - 4，默认值: 0。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1.Incorrect parameter types. |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 4. Received value is: [offset]. |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from([0, 0, 0, 5]);
console.log(buf.readInt32BE(0).toString());	// 打印: 5

let buf1 = buffer.alloc(4);
let result = buf1.writeInt32BE(0x12345678, 0);
```

### readInt32LE

readInt32LE(offset?: number): number

从指定的`offset`处读取有符号的小端序32位整数。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。取值范围：0 <= offset <= Buffer.length - 4，默认值: 0。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1.Incorrect parameter types. |
| 10200001 |  The value of "offset" is out of range. It must be >= 0 and <= buf.length - 4. Received value is: [offset]. |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from([0, 0, 0, 5]);
console.log(buf.readInt32LE(0).toString());	// 打印: 83886080

let buf1 = buffer.alloc(4);
let result = buf1.writeInt32BE(0x12345678, 0);
```

### readIntBE

readIntBE(offset: number, byteLength: number): number

从指定的`offset`处的buf读取byteLength个字节，并将结果解释为支持最高48位精度的大端序、二进制补码有符号值。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 是 | 偏移量。取值范围：0 <= offset <= Buffer.length - byteLength，默认值: 0。 |
| byteLength | number | 是 | 读取的字节数。取值范围：1 <= byteLength <= 6。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取的内容。当offset为小数时，返回undefined。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from("ab");
let num = buf.readIntBE(0, 1);
console.log(num.toString()); // 97

let buf1 = buffer.allocUninitializedFromPool(6);
let result = buf1.writeIntBE(0x123456789011, 0, 6);
```


### readIntLE

readIntLE(offset: number, byteLength: number): number

从指定的`offset`处的buf读取`byteLength`个字节，并将结果解释为支持最高48位精度的小端序、二进制补码有符号值。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 是 | 偏移量。取值范围：0 <= offset <= Buffer.length - byteLength，默认值: 0。 |
| byteLength | number | 是 | 读取的字节数。取值范围：1 <= byteLength <= 6。|


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。当offset为小数时，返回undefined。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from([0x12, 0x34, 0x56, 0x78, 0x90, 0xab]);
console.log(buf.readIntLE(0, 6).toString(16));

let buf1 = buffer.allocUninitializedFromPool(6);
let result = buf1.writeIntLE(0x123456789011, 0, 6);
```

### readUInt8

readUInt8(offset?: number): number

从`offset`处读取8位无符号整型数。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。取值范围：0 <= offset <= Buffer.length - 1，默认值: 0。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Incorrect parameter types. |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 1. Received value is: [offset]. |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from([1, -2]);
console.log(buf.readUInt8(0).toString());
console.log(buf.readUInt8(1).toString());

let buf1 = buffer.allocUninitializedFromPool(4);
let result = buf1.writeUInt8(0x42);
```

### readUInt16BE

readUInt16BE(offset?: number): number

从指定的`offset`处的buf读取无符号的大端序16位整数。

**系统能力：** SystemCapability.Utils.Lang

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。取值范围：0 <= offset <= Buffer.length - 2，默认值: 0。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Incorrect parameter types. |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 2. Received value is: [offset]. |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from([0x12, 0x34, 0x56]);
console.log(buf.readUInt16BE(0).toString(16));
console.log(buf.readUInt16BE(1).toString(16));

let buf1 = buffer.allocUninitializedFromPool(4);
let result = buf1.writeUInt16BE(0x1234, 0);
```

### readUInt16LE

readUInt16LE(offset?: number): number

从指定的`offset`处的buf读取无符号的小端序16位整数。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。取值范围：0 <= offset <= Buffer.length - 2，默认值: 0。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Incorrect parameter types. |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 2. Received value is: [offset]. |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from([0x12, 0x34, 0x56]);
console.log(buf.readUInt16LE(0).toString(16));
console.log(buf.readUInt16LE(1).toString(16));

let buf1 = buffer.allocUninitializedFromPool(4);
let result = buf1.writeUInt16LE(0x1234, 0);
```

### readUInt32BE

readUInt32BE(offset?: number): number

从指定的`offset`处的buf读取无符号的大端序32位整数。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。取值范围：0 <= offset <= Buffer.length - 4，默认值: 0。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Incorrect parameter types. |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 4. Received value is: [offset]. |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from([0x12, 0x34, 0x56, 0x78]);
console.log(buf.readUInt32BE(0).toString(16));

let buf1 = buffer.allocUninitializedFromPool(4);
let result = buf1.writeUInt32BE(0x12345678, 0);
```

### readUInt32LE

readUInt32LE(offset?: number): number

从指定的`offset`处的buf读取无符号的小端序32位整数。

**系统能力：** SystemCapability.Utils.Lang

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。取值范围：0 <= offset <= Buffer.length - 4，默认值: 0。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Incorrect parameter types. |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 4. Received value is: [offset]. |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from([0x12, 0x34, 0x56, 0x78]);
console.log(buf.readUInt32LE(0).toString(16));

let buf1 = buffer.allocUninitializedFromPool(4);
let result = buf1.writeUInt32LE(0x12345678, 0);
```

### readUIntBE

readUIntBE(offset: number, byteLength: number): number

从指定的`offset`处的buf读取`byteLength`个字节，并将结果解释为支持最高48位精度的无符号大端序整数。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 是 | 偏移量。取值范围：0 <= offset <= Buffer.length - byteLength，默认值: 0。 |
| byteLength | number | 是 | 要读取的字节数。读取的字节数。取值范围：1 <= byteLength <= 6。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。当offset为小数时，返回undefined。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from([0x12, 0x34, 0x56, 0x78, 0x90, 0xab]);
console.log(buf.readUIntBE(0, 6).toString(16));

let buf1 = buffer.allocUninitializedFromPool(4);
let result = buf1.writeUIntBE(0x13141516, 0, 4);
```

### readUIntLE

readUIntLE(offset: number, byteLength: number): number

从指定的`offset`处的buf读取`byteLength`个字节，并将结果解释为支持最高48位精度的无符号小端序整数。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 是 | 偏移量。取值范围：0 <= offset <= Buffer.length - byteLength，默认值: 0。 |
| byteLength | number | 是 | 读取的字节数。取值范围：1 <= byteLength <= 6。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。当offset为小数时，返回undefined。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.from([0x12, 0x34, 0x56, 0x78, 0x90, 0xab]);
console.log(buf.readUIntLE(0, 6).toString(16));

let buf1 = buffer.allocUninitializedFromPool(4);
let result = buf1.writeUIntLE(0x13141516, 0, 4);
```

### subarray

subarray(start?: number, end?: number): Buffer

截取当前对象指定位置的数据并返回。

**系统能力：** SystemCapability.Utils.Lang

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| start | number | 否 | 截取开始位置。 默认值: 0。 |
| end | number | 否 |  截取结束位置（不包含结束位置）。 默认值: 当前对象的字节长度。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Buffer | 返回新的Buffer对象。当 start < 0 或 end < 0 时返回一个空Buffer。 |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf1 = buffer.allocUninitializedFromPool(26);

for (let i = 0; i < 26; i++) {
  buf1.writeInt8(i + 97, i);
}
const buf2 = buf1.subarray(0, 3);
console.log(buf2.toString('ascii', 0, buf2.length));
// 打印: abc
```

### swap16

swap16(): Buffer

将当前对象解释为无符号的16位整数数组，并交换字节顺序。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Buffer | 交换之后的Buffer实例。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200009 | The buffer size must be a multiple of 16-bits. |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf1 = buffer.from([0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8]);
console.log(buf1.toString('hex'));	// 打印: 0102030405060708

buf1.swap16();
console.log(buf1.toString('hex'));	// 打印: 0201040306050807
```

### swap32

swap32(): Buffer

将当前对象解释为无符号的32位整数数组，并交换字节顺序。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Buffer | 交换之后的Buffer对象。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200009 | The buffer size must be a multiple of 32-bits. |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf1 = buffer.from([0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8]);
console.log(buf1.toString('hex'));	// 打印: 0102030405060708

buf1.swap32();
console.log(buf1.toString('hex'));	// 打印: 0403020108070605
```

### swap64

swap64(): Buffer

将当前对象解释为无符号的64位整数数组，并交换字节顺序。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Buffer | 交换之后的Buffer对象。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200009 | The buffer size must be a multiple of 64-bits. |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf1 = buffer.from([0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8]);
console.log(buf1.toString('hex'));	// 打印: 0102030405060708
buf1.swap64();
console.log(buf1.toString('hex'));	// 打印: 0807060504030201
```

### toJSON

toJSON(): Object

将Buffer转为JSON并返回。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Object | JSON对象。 |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf1 = buffer.from([0x1, 0x2, 0x3, 0x4, 0x5]);
let obj = buf1.toJSON();
console.log(JSON.stringify(obj));
// 打印: {"type":"Buffer","data":[1,2,3,4,5]}
```

### toString

toString(encoding?: string, start?: number, end?: number): string

将当前对象中指定位置数据转成指定编码格式字符串并返回。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| encoding | string | 否 | 字符编码格式。 默认值: 'utf8'。 |
| start  | number | 否 |  开始位置。 默认值: 0。 |
| end  | number | 否 |  结束位置。 默认值: Buffer.length。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 字符串。 当start >= Buffer.length 或 start > end 时返回空字符串。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Incorrect parameter types. |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf1 = buffer.allocUninitializedFromPool(26);
for (let i = 0; i < 26; i++) {
  buf1.writeInt8(i + 97, i);
}
console.log(buf1.toString('utf-8'));
// 打印: abcdefghijklmnopqrstuvwxyz
```

### values

values(): IterableIterator&lt;number&gt;

返回一个包含value的迭代器。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;number&gt; | 迭代器。 |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf1 = buffer.from('buffer');
let pair = buf1.values()
let next:IteratorResult<number> = pair.next()
while (!next.done) {
  console.log(next.value.toString());
  next = pair.next();
}
```

### write

write(str: string, offset?: number, length?: number, encoding?: string): number

从Buffer对象的offset偏移写入指定编码的字符串str，写入的字节长度为length。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| str | string | 是 | 要写入Buffer的字符串。 |
| offset | number | 否 | 偏移量。 默认值: 0。 |
| length | number | 否 | 最大字节长度。 默认值: (Buffer.length - offset)。|
| encoding | string | 否 | 字符编码。 默认值: 'utf8'。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200001 | The value of "[offset/length]" is out of range. It must be >= 0 and <= buf.length. Received value is: [offset/length]. |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.alloc(256);
let len = buf.write('\u00bd + \u00bc = \u00be', 0);
console.log(`${len} bytes: ${buf.toString('utf-8', 0, len)}`);
// 打印: 12 bytes: ½ + ¼ = ¾

let buffer1 = buffer.alloc(10);
let length = buffer1.write('abcd', 8);
```

### writeBigInt64BE

writeBigInt64BE(value: bigint, offset?: number): number

从Buffer对象的offset偏移写入有符号的大端序64位BigInt型数据value。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | bigint | 是 | 写入Buffer的数据。 |
| offset | number | 否 | 偏移量。 默认值: 0。取值范围：0 <= offset <= Buffer.length - 8。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 偏移量offset加上写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(8);
let result = buf.writeBigInt64BE(BigInt(0x0102030405060708), 0);
```

### writeBigInt64LE

writeBigInt64LE(value: bigint, offset?: number): number

从Buffer对象的offset偏移写入有符号的小端序64位BigInt型数据value。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | bigint | 是 | 写入Buffer的数据。 |
| offset | number | 否 | 偏移量。 默认值: 0。取值范围：0 <= offset <= Buffer.length - 8。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 偏移量offset加上写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(8);
let result = buf.writeBigInt64LE(BigInt(0x0102030405060708), 0);
```

### writeBigUInt64BE

writeBigUInt64BE(value: bigint, offset?: number): number

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

从Buffer对象的offset偏移写入无符号的大端序64位BigUInt型数据value。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | bigint | 是 | 写入Buffer的数据。 |
| offset | number | 否 | 偏移量。 默认值: 0。取值范围：0 <= offset <= Buffer.length - 8。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 偏移量offset加上写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(8);
let result = buf.writeBigUInt64BE(BigInt(0xdecafafecacefade), 0);
```

### writeBigUInt64LE

writeBigUInt64LE(value: bigint, offset?: number): number

从Buffer对象的offset偏移写入无符号的小端序64位BigUInt型数据value。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | bigint | 是 | 写入Buffer的数据。 |
| offset | number | 否 | 偏移量。 默认值: 0。取值范围：0 <= offset <= Buffer.length - 8。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 偏移量offset加上写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(8);
let result = buf.writeBigUInt64LE(BigInt(0xdecafafecacefade), 0);
```

### writeDoubleBE

writeDoubleBE(value: number, offset?: number): number

从Buffer对象的offset偏移写入大端序的64位双浮点型数据value。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入Buffer的数据。 |
| offset | number | 否 | 偏移量。 默认值: 0。取值范围：0 <= offset <= Buffer.length - 8。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 偏移量offset加上写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 8. Received value is: [offset] |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(8);
let result = buf.writeDoubleBE(123.456, 0);
```

### writeDoubleLE

writeDoubleLE(value: number, offset?: number): number

从Buffer对象的offset偏移写入小端序的64位双浮点型数据value。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入Buffer的数据。 |
| offset | number | 否 | 偏移量。 默认值: 0。取值范围：0 <= offset <= Buffer.length - 8。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 偏移量offset加上写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 8. Received value is: [offset] |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(8);
let result = buf.writeDoubleLE(123.456, 0);
```

### writeFloatBE

writeFloatBE(value: number, offset?: number): number

从Buffer对象的offset偏移写入大端序的32位浮点型数据value。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入Buffer的数据。 |
| offset | number | 否 | 偏移量。 默认值: 0。取值范围：0 <= offset <= Buffer.length - 4。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 偏移量offset加上写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 4. Received value is: [offset] |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(8);
let result = buf.writeFloatBE(0xcafebabe, 0);
```


### writeFloatLE

writeFloatLE(value: number, offset?: number): number

从Buffer对象的offset偏移写入小端序的32位浮点型数据value。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入Buffer的数据。 |
| offset | number | 否 | 偏移量。 默认值: 0。取值范围：0 <= offset <= Buffer.length - 4。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 偏移量offset加上写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 4. Received value is: [offset] |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(8);
let result = buf.writeFloatLE(0xcafebabe, 0);
```

### writeInt8

writeInt8(value: number, offset?: number): number

从Buffer对象的offset偏移写入8位有符号整型数据value。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入Buffer的数据。 |
| offset | number | 否 | 偏移量。 默认值: 0。取值范围：0 <= offset <= Buffer.length - 1。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 偏移量offset加上写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(2);
let result = buf.writeInt8(2, 0);
let result1 = buf.writeInt8(-2, 1);
```


### writeInt16BE

writeInt16BE(value: number, offset?: number): number

从Buffer对象的offset偏移写入大端序的16位有符号整型数据value。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入Buffer的数据。 |
| offset | number | 否 | 偏移量。 默认值: 0。取值范围：0 <= offset <= Buffer.length - 2。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 偏移量offset加上写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(2);
let result = buf.writeInt16BE(0x0102, 0);
```


### writeInt16LE

writeInt16LE(value: number, offset?: number): number

从Buffer对象的offset偏移写入小端序的16位有符号整型数据value。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入Buffer的数据。 |
| offset | number | 否 | 偏移量。 默认值: 0。取值范围：0 <= offset <= Buffer.length - 2。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 偏移量offset加上写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(2);
let result = buf.writeInt16LE(0x0304, 0);
```

### writeInt32BE

writeInt32BE(value: number, offset?: number): number

从Buffer对象的offset偏移写入大端序的32位有符号整型数据value。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入Buffer的数据。 |
| offset | number | 否 | 偏移量。 默认值: 0。取值范围：0 <= offset <= Buffer.length - 4。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 偏移量offset加上写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(4);
let result = buf.writeInt32BE(0x01020304, 0);
```


### writeInt32LE

writeInt32LE(value: number, offset?: number): number

从Buffer对象的offset偏移写入小端序的32位有符号整型数据value。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入Buffer的数据。 |
| offset | number | 否 | 偏移量。 默认值: 0。取值范围：0 <= offset <= Buffer.length - 4。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 偏移量offset加上写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(4);
let result = buf.writeInt32LE(0x05060708, 0);
```

### writeIntBE

writeIntBE(value: number, offset: number, byteLength: number): number

从Buffer对象的offset偏移写入大端序的有符号value数据，value字节长度为byteLength。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入Buffer的数据。 |
| offset | number | 是 | 偏移量。 默认值: 0。取值范围：0 <= offset <= Buffer.length - byteLength。 |
| byteLength | number | 是 | 要写入的字节数。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 偏移量offset加上写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(6);
let result = buf.writeIntBE(0x1234567890ab, 0, 6);
```


### writeIntLE

writeIntLE(value: number, offset: number, byteLength: number): number

从Buffer对象的offset偏移写入小端序的有符号value数据，value字节长度为byteLength。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入Buffer的数据。 |
| offset | number | 是 | 偏移量。 默认值: 0。取值范围：0 <= offset <= Buffer.length - byteLength。 |
| byteLength | number | 是 | 要写入的字节数。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 偏移量offset加上写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(6);
let result = buf.writeIntLE(0x1234567890ab, 0, 6);
```

### writeUInt8

writeUInt8(value: number, offset?: number): number

从Buffer对象的offset偏移写入8位无符号整型数据value。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入Buffer的数据。 |
| offset | number | 否 | 偏移量。 默认值: 0。取值范围：0 <= offset <= Buffer.length - 1。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 偏移量offset加上写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(4);
let result = buf.writeUInt8(0x3, 0);
let result1 = buf.writeUInt8(0x4, 1);
let result2 = buf.writeUInt8(0x23, 2);
let result3 = buf.writeUInt8(0x42, 3);
```

### writeUInt16BE

writeUInt16BE(value: number, offset?: number): number

从Buffer对象的offset偏移写入大端序的16位无符号整型数据value。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入Buffer的数据。 |
| offset | number | 否 | 偏移量。 默认值为0。取值范围：0 <= offset <= Buffer.length - 2。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 偏移量offset加上写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(4);
let result = buf.writeUInt16BE(0xdead, 0);
let result1 = buf.writeUInt16BE(0xbeef, 2);
```

### writeUInt16LE

writeUInt16LE(value: number, offset?: number): number

从Buffer对象的offset偏移写入小端序的16位无符号整型数据value。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入Buffer的数据。 |
| offset | number | 否 | 偏移量。 默认值: 0。取值范围：0 <= offset <= Buffer.length - 2。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 偏移量offset加上写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(4);
let result = buf.writeUInt16LE(0xdead, 0);
let result1 = buf.writeUInt16LE(0xbeef, 2);
```

### writeUInt32BE

writeUInt32BE(value: number, offset?: number): number

从Buffer对象的offset偏移写入大端序的32位无符号整型数据value。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入Buffer的数据。 |
| offset | number | 否 | 偏移量。 默认值: 0。取值范围：0 <= offset <= Buffer.length - 4。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 偏移量offset加上写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(4);
let result = buf.writeUInt32BE(0xfeedface, 0);
```

### writeUInt32LE

writeUInt32LE(value: number, offset?: number): number

从Buffer对象的offset偏移写入小端序的32位无符号整型数据value。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入Buffer对象的数字。 |
| offset | number | 否 | 偏移量。 默认值: 0。取值范围：0 <= offset <= Buffer.length - 4。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 偏移量offset加上写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(4);
let result = buf.writeUInt32LE(0xfeedface, 0);
```

### writeUIntBE

writeUIntBE(value: number, offset: number, byteLength: number): number

从Buffer对象的offset偏移写入大端序的无符号value数据，value字节长度为byteLength。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入Buffer的数据。 |
| offset | number | 是 | 偏移量。 默认值: 0。取值范围：0 <= offset <= Buffer.length - byteLength。 |
| byteLength | number | 是 | 要写入的字节数。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 偏移量offset加上写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(6);
let result = buf.writeUIntBE(0x1234567890ab, 0, 6);
```

### writeUIntLE

writeUIntLE(value: number, offset: number, byteLength: number): number

从Buffer对象的offset偏移写入小端序的无符号value数据，value字节长度为byteLength。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入Buffer的数据。 |
| offset | number | 是 | 偏移量。 默认值: 0。取值范围：0 <= offset <= Buffer.length - byteLength。 |
| byteLength | number | 是 | 要写入的字节数。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 偏移量offset加上写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**示例：**

```ts
import { buffer } from '@kit.ArkTS';

let buf = buffer.allocUninitializedFromPool(6);
let result = buf.writeUIntLE(0x1234567890ab, 0, 6);
```

## Blob

### 属性

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| size | number | 是 | 否 | Blob实例的总字节大小。 |
| type | string | 是 | 否 | Blob实例的内容类型。 |

### constructor

constructor(sources: string[] | ArrayBuffer[] | TypedArray[] | DataView[] | Blob[] , options?: Object)

Blob的构造函数。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| sources | string[]&nbsp;\|&nbsp;ArrayBuffer[]&nbsp;\|&nbsp;TypedArray[]&nbsp;\|&nbsp;DataView[]&nbsp;\|&nbsp;Blob[] | 是 | Blob实例的数据源。 |
| options | Object | 否 | options:<br/>- endings:含义为结束符'\n'的字符串如何被输出，为'transparent'或'native'。native代表行结束符会跟随系统。'transparent'代表会保持Blob中保存的结束符不变。此参数非必填，默认值为'transparent'。<br/>- type:Blob内容类型。其目的是让类型传达数据的MIME媒体类型，但是不执行类型格式的验证。此参数非必填，默认参数为''。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**
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

将Blob中的数据放入到ArrayBuffer中，并返回一个Promise。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;ArrayBuffer&gt; | Promise对象，返回包含Blob数据的ArrayBuffer。 |

**示例：**
```ts
import { buffer } from '@kit.ArkTS';

let blob: buffer.Blob = new buffer.Blob(['a', 'b', 'c']);
let pro = blob.arrayBuffer();
pro.then((val: ArrayBuffer) => {
  let uintarr: Uint8Array = new Uint8Array(val);
  console.log(uintarr.toString());
});
```
### slice

slice(start?: number, end?: number, type?: string): Blob

创建并返回一个复制原Blob对象中指定数据长度的Blob新对象。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| start | number | 否 | 起始位置。默认值为0。 |
| end | number | 否 | 结束位置。默认值为原Blob对象中的数据长度。 |
| type | string | 否 | 内容类型。默认值为''。 |

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| Blob | 新的Blob实例对象。 |

**示例：**
```ts
import { buffer } from '@kit.ArkTS';

let blob: buffer.Blob = new buffer.Blob(['a', 'b', 'c']);
let blob2 = blob.slice(0, 2);
let blob3 = blob.slice(0, 2, "MIME");
```

### text

text(): Promise&lt;string&gt;

使用UTF8进行解码并返回一个文本。使用Promise异步回调。

**原子化服务API**：从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;string&gt; | Promise对象，返回包含以UTF8解码的文本。 |

**示例：**
```ts
import { buffer } from '@kit.ArkTS';

let blob: buffer.Blob = new buffer.Blob(['a', 'b', 'c']);
let pro = blob.text();
pro.then((val: string) => {
  console.log(val);
});
```