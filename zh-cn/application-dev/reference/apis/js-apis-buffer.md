# @ohos.buffer (Buffer)

> **说明：**
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

Buffer对象用于表示固定长度的字节序列,是专门存放二进制数据的缓存区。

**推荐使用场景：** 可用于处理大量二进制数据，处理图片、文件接收上传等等

## 导入模块

```ts
import buffer from '@ohos.buffer';
```

## BufferEncoding

表示支持的编码格式字符串。

**系统能力：** SystemCapability.Utils.Lang

| 编码格式    | 说明                 |
| ------- | -------------------- |
| ascii  | 表示ascii格式。   |
| utf8  | 表示utf8格式。   |
| utf-8 | 表示utf8格式。 |
| utf16le | 表示utf16小端序格式。 |
| ucs2 | 表示utf16小端序格式。 |
| ucs-2 | 表示utf16小端序格式。 |
| base64 | 表示base64格式。 |
| base64url | 表示base64格式。 |
| latin1 | 表示ascii格式。 |
| binary | 表示二进制格式。 |
| hex | 表示十六进制格式。 |

## Buffer

### 属性

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| length | number | 是 | 否 | buffer的字节长度。 |
| buffer | ArrayBuffer | 是 | 否 | ArrayBuffer对象。 |
| byteOffset | number | 是 | 否 | 当前buffer所在内存池的偏移量。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200013 | Cannot set property ${propertyName} of Buffer which has only a getter. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.from("1236");
console.log(JSON.stringify(buf.length));
let arrayBuffer = buf.buffer;
console.log(JSON.stringify(new Uint8Array(arrayBuffer)));
console.log(JSON.stringify(buf.byteOffset));
```

### alloc

alloc(size: number, fill?: string | Buffer | number, encoding?: BufferEncoding): Buffer

创建`size`个字节长度的Buffer实例，并初始化。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| size | number | 是 | 指定的Buffer实例长度，单位：字节。 |
| fill | string&nbsp;\|&nbsp;Buffer&nbsp;\|&nbsp;number | 否 | 预填充的值，默认值: 0 |
| encoding | [BufferEncoding](#bufferencoding) | 否 | 编码方式（当`fill`为string时，才有意义）。 默认值: 'utf-8' |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Buffer | 带初始化的Buffer实例。 |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf1 = buffer.alloc(5);
let buf2 = buffer.alloc(5, 'a');
let buf3 = buffer.alloc(11, 'aGVsbG8gd29ybGQ=', 'base64');
```

### allocUninitializedFromPool

allocUninitializedFromPool(size: number): Buffer

创建指定大小的未被初始化Buffer实例。内存从缓冲池分配。
创建的Buffer的内容未知，需要使用fill()函数来初始化Buffer实例。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| size | number | 是 | 指定的Buffer实例长度，单位：字节。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Buffer | 未初始化的Buffer实例。 |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.allocUninitializedFromPool(10);
buf.fill(0);
```

### allocUninitialized

allocUninitialized(size: number): Buffer

创建指定大小的未被初始化Buffer实例。内存不从缓冲池分配。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| size | number | 是 |指定的Buffer实例长度，单位：字节。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Buffer | 未初始化的Buffer实例。 |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.allocUninitialized(10);
buf.fill(0);
```

### byteLength

byteLength(string: string | Buffer | TypedArray | DataView | ArrayBuffer | SharedArrayBuffer, encoding?: BufferEncoding): number

根据不同的编码方法，返回字符串的字节数。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| string | string&nbsp;\|&nbsp;Buffer&nbsp;\|&nbsp;TypedArray&nbsp;\|&nbsp;DataView&nbsp;\|&nbsp;ArrayBuffer&nbsp;\|&nbsp;SharedArrayBuffer | 是 | 指定字符串。 |
| encoding | [BufferEncoding](#bufferencoding) | 否 | 编码方式。 默认值: 'utf-8' |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回字符串的字节数 |

**示例：**

```ts
import buffer from '@ohos.buffer';

let str = '\u00bd + \u00bc = \u00be';
console.log(`${str}: ${str.length} characters, ${buffer.byteLength(str, 'utf-8')} bytes`);
// 打印: ½ + ¼ = ¾: 9 characters, 12 bytes
```

### compare

compare(buf1: Buffer | Uint8Array, buf2: Buffer | Uint8Array): -1 | 0 | 1

返回比较buf1和buf2的结果, 通常用于对Buffer实例的数组进行排序。


**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| buf1 | Buffer&nbsp;\|&nbsp;Uint8Array | 是 | 待比较数组。 |
| buf2 | Buffer&nbsp;\|&nbsp;Uint8Array | 是 | 待比较数组。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| -1&nbsp;\|&nbsp;0&nbsp;\|&nbsp;1 | 如果buf1与buf2相同，则返回0<br/>如果排序时buf1位于buf2之后，则返回1<br/>如果排序时buf1位于buf2之前，则返回-1。 |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf1 = buffer.from('1234');
let buf2 = buffer.from('0123');
let res = buf1.compare(buf2);

console.log(Number(res).toString()); // 打印 1
```

### concat

concat(list: Buffer[] | Uint8Array[], totalLength?: number): Buffer

将`list`中的实例内容复制`totalLength`字节长度到新的Buffer实例中并返回。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| list | Buffer[]&nbsp;\|&nbsp;Uint8Array[] | 是 | 实例数组。 |
| totalLength | number | 否 | 需要融合的总字节长度。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Buffer | 返回新Buffer的实例。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "totalLength" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf1 = buffer.from("1234");
let buf2 = buffer.from("abcd");
let buf = buffer.concat([buf1, buf2]);
console.log(buf.toString('hex')); // 3132333461626364
```

### from

from(array: number[]): Buffer;

根据指定数组创建新的Buffer实例。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| array | number[] | 是 | 指定数组。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Buffer | 新的Buffer实例。 |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.from([0x62, 0x75, 0x66, 0x66, 0x65, 0x72]);
console.log(buf.toString('hex')); // 627566666572
```

### from

from(arrayBuffer: ArrayBuffer | SharedArrayBuffer, byteOffset?: number, length?: number): Buffer

创建指定长度的与`arrayBuffer`共享内存的Buffer实例

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| arrayBuffer | ArrayBuffer&nbsp;\|&nbsp;SharedArrayBuffer | 是 | 实例对象。 |
| byteOffset | number | 否 | 字节偏移量，默认值: 0。 |
| length | number | 否 | 字节长度， 默认值: arrayBuffer.byteLength - byteOffset。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Buffer | 返回一个共享内存的Buffer实例。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[byteOffset/length]" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let ab = new ArrayBuffer(10);
let buf = buffer.from(ab, 0, 2);
```

### from

from(buffer: Buffer | Uint8Array): Buffer

创建并复制`buffer`数据到新的Buffer实例并返回。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| buffer | Buffer&nbsp;\|&nbsp;Uint8Array | 是 | 实例数据。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Buffer | 新的Buffer实例。 |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf1 = buffer.from('buffer');
let buf2 = buffer.from(buf1);
```

### from

from(object: Object, offsetOrEncoding: number | string, length: number): Buffer

根据指定的`object`类型数据，创建新的Buffer实例。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| object | Object | 是 | 支持Symbol.toPrimitive或valueOf()的对象 |
| offsetOrEncoding | number&nbsp;\|&nbsp;string | 是 | 字节偏移量或编码。 |
| length | number | 是 | 字节长度。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Buffer | 新的Buffer实例。 |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.from(new String('this is a test'));
```

### from

from(string: String, encoding?: BufferEncoding): Buffer

根据指定编码格式的字符串，创建新的Buffer实例。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| string | String | 是 | 字符串 |
| encoding | [BufferEncoding](#bufferencoding) | 否 | 编码格式。 默认值: 'utf-8'。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Buffer | 新的Buffer实例。 |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf1 = buffer.from('this is a test');
let buf2 = buffer.from('7468697320697320612074c3a97374', 'hex');

console.log(buf1.toString());	// 打印: this is a test
console.log(buf2.toString());
```


### isBuffer

isBuffer(obj: Object): boolean

判断`obj`是否为Buffer。

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
import buffer from '@ohos.buffer';

buffer.isBuffer(buffer.alloc(10)); // true
buffer.isBuffer(buffer.from('foo')); // true
buffer.isBuffer('a string'); // false
buffer.isBuffer([]); // false
buffer.isBuffer(new Uint8Array(1024)); // false
```

### isEncoding

isEncoding(encoding: string): boolean

判断`encoding`是否为支持的编码格式。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| encoding | string | 是 | 编码格式。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | true或者false。 |

**示例：**

```ts
import buffer from '@ohos.buffer';

console.log(buffer.isEncoding('utf-8').toString());	// 打印: true
console.log(buffer.isEncoding('hex').toString());	// 打印: true
console.log(buffer.isEncoding('utf/8').toString());	// 打印: false
console.log(buffer.isEncoding('').toString());	// 打印: false
```

### compare

compare(target: Buffer | Uint8Array, targetStart?: number, targetEnd?: number, sourceStart?: number, sourceEnd?: number): -1 | 0 | 1

`this`实例对象与`target`实例对象进行比较，返回buf在排序中的顺序，-1:前排序，0:与buf相同，1:后排序。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| target | Buffer&nbsp;\|&nbsp;Uint8Array | 是 | 要比较的实例对象。 |
| targetStart | number | 否 | `target`实例中开始的偏移量。 默认值: 0。 |
| targetEnd | number | 否 | `target`实例中结束的偏移量（不包括本身）。 默认值: target.length。 |
| sourceStart | number | 否 | `this`实例中开始的偏移量。 默认值: 0。 |
| sourceEnd | number | 否 | `this`实例中结束的偏移量（不包括本身）。 默认值: buf.length。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 比较结果。-1:前排序，0:与buf相同，1:后排序。 |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf1 = buffer.from([1, 2, 3, 4, 5, 6, 7, 8, 9]);
let buf2 = buffer.from([5, 6, 7, 8, 9, 1, 2, 3, 4]);

console.log(buf1.compare(buf2, 5, 9, 0, 4).toString());	// 打印: 0
console.log(buf1.compare(buf2, 0, 6, 4).toString());	// 打印: -1
console.log(buf1.compare(buf2, 5, 6, 5).toString());	// 打印: 1
```

### copy

copy(target: Buffer| Uint8Array, targetStart?: number, sourceStart?: number, sourceEnd?: number): number

将`this`实例中指定位置的数据复制到`target`的指定位置上，并返回复制的字节总长度。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| target | Buffer&nbsp;\|&nbsp;Uint8Array | 是 | 要复制到的Buffer或Uint8Array实例。 |
| targetStart | number | 否 | `target`实例中开始写入的偏移量。 默认值: 0。 |
| sourceStart | number | 否 | `this`实例中开始复制的偏移量。 默认值: 0。 |
| sourceEnd | number | 否 | `this`实例中结束复制的偏移量（不包括）。 默认值: buf.length。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number |  复制的字节总长度。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[targetStart/sourceStart/sourceEnd]" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf1 = buffer.allocUninitializedFromPool(26);
let buf2 = buffer.allocUninitializedFromPool(26).fill('!');

for (let i = 0; i < 26; i++) {
  buf1[i] = i + 97;
}

buf1.copy(buf2, 8, 16, 20);
console.log(buf2.toString('ascii', 0, 25));
// 打印: !!!!!!!!qrst!!!!!!!!!!!!!
```

### entries

entries(): IterableIterator&lt;[number,&nbsp;number]&gt;

返回一个包含key和value的迭代器。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.from('buffer');
for (let pair of buf.entries()) {
  console.log(pair.toString());
}
```

### equals

equals(otherBuffer: Uint8Array | Buffer): boolean

比较`this`实例和otherBuffer实例是否相等。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| otherBuffer | Uint8Array&nbsp;\|&nbsp;Buffer | 是 | 比较的目标对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 相等则返回true，否则返回false。 |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf1 = buffer.from('ABC');
let buf2 = buffer.from('414243', 'hex');
let buf3 = buffer.from('ABCD');

console.log(buf1.equals(buf2).toString());	// 打印: true
console.log(buf1.equals(buf3).toString());	// 打印: false
```

### fill

fill(value: string | Buffer | Uint8Array | number, offset?: number, end?: number, encoding?: BufferEncoding): Buffer

用`value`填充`this`实例指定位置的数据，默认为循环填充，并返回填充后的Buffer实例。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | string&nbsp;\|&nbsp;Buffer&nbsp;\|&nbsp;Uint8Array&nbsp;\|&nbsp;number | 是 | 用于填充的值。 |
| offset | number | 否 | 起始偏移量。 默认值: 0。 |
| end | number | 否 | 结束偏移量（不包括在内）。 默认值: buf.length。 |
| encoding | [BufferEncoding](#bufferencoding) | 否 | 字符编码格式（`value`为string才有意义）。 默认值: 'utf-8'。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Buffer | 填充后的Buffer实例。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[offset/end]" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let b = buffer.allocUninitializedFromPool(50).fill('h');
console.log(b.toString());
```


### includes

includes(value: string | number | Buffer | Uint8Array, byteOffset?: number, encoding?: BufferEncoding): boolean

检查Buffer对象是否包含`value`值。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | string&nbsp;\|&nbsp;number&nbsp;\|&nbsp;Buffer&nbsp;\|&nbsp;Uint8Array | 是 | 要搜索的内容。 |
| byteOffset | number | 否 | 字节偏移量。 如果为负数，则从末尾开始计算偏移量。 默认值: 0。 |
| encoding | [BufferEncoding](#bufferencoding) | 否 | 字符编码格式。 默认值: 'utf-8'。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 存在为true，否则为false。 |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.from('this is a buffer');
console.log(buf.includes('this').toString());	// 打印: true
console.log(buf.includes('be').toString());	// 打印: false
```

### indexOf

indexOf(value: string | number | Buffer | Uint8Array, byteOffset?: number, encoding?: BufferEncoding): number

查找`this`实例中第一次出现`value`的索引，如果不包含`value`，则为-1

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | string&nbsp;\|&nbsp;number&nbsp;\|&nbsp;Buffer&nbsp;\|&nbsp;Uint8Array | 是 | 要搜索的内容。 |
| byteOffset | number | 否 | 字节偏移量。 如果为负数，则从末尾开始计算偏移量。 默认值: 0。 |
| encoding | [BufferEncoding](#bufferencoding) | 否 | 字符编码格式。 默认值: 'utf-8'。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 第一次出现位置。 |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.from('this is a buffer');
console.log(buf.indexOf('this').toString());	// 打印: 0
console.log(buf.indexOf('is').toString());		// 打印: 2
```

### keys

keys(): IterableIterator&lt;number&gt;

返回一个包含key值的迭代器

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
|  IterableIterator&lt;number&gt; | 迭代器。 |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.from('buffer');
for (const key of buf.keys()) {
  console.log(key.toString());
}
```

### lastIndexOf

lastIndexOf(value: string | number | Buffer | Uint8Array, byteOffset?: number, encoding?: BufferEncoding): number

返回`this`实例中最后一次出现`value`的索引，如果对象不包含，则为-1。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | string&nbsp;\|&nbsp;number&nbsp;\|&nbsp;Buffer&nbsp;\|&nbsp;Uint8Array | 是 | 要搜索的内容。 |
| byteOffset | number | 否 | 字节偏移量。 如果为负数，则从末尾开始计算偏移量。 默认值: 0。 |
| encoding | [BufferEncoding](#bufferencoding) | 否 | 字符编码格式。 默认值: 'utf-8'。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 最后一次出现`value`值的索引。 |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.from('this buffer is a buffer');
console.log(buf.lastIndexOf('this').toString());	// 打印: 0
console.log(buf.lastIndexOf('buffer').toString());	// 打印: 17
```


### readBigInt64BE

readBigInt64BE(offset?: number): bigint

从指定的`offset`处读取有符号的大端序64位整数。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。默认值: 0。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| bigint | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.from([0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x70, 
        0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78]);
console.log(buf.readBigInt64BE(0).toString());

let buf1 = buffer.allocUninitializedFromPool(8);
buf1.writeBigInt64BE(0x0102030405060708n, 0);
```

### readBigInt64LE

readBigInt64LE(offset?: number): bigint

从指定的`offset`处读取有符号的小端序64位整数。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。默认值: 0。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| bigint | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.from([0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x70, 
        0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78]);
console.log(buf.readBigInt64LE(0).toString());

let buf1 = buffer.allocUninitializedFromPool(8);
buf1.writeBigInt64BE(0x0102030405060708n, 0);
```

### readBigUInt64BE

readBigUInt64BE(offset?: number): bigint

从指定的`offset`处读取无符号的大端序64位整数。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。默认值: 0。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| bigint | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.from([0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x70, 
        0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78]);
console.log(buf.readBigUInt64BE(0).toString());

let buf1 = buffer.allocUninitializedFromPool(8);
buf1.writeBigUInt64BE(0xdecafafecacefaden, 0);
```

### readBigUInt64LE

readBigUInt64LE(offset?: number): bigint

从指定的`offset`处读取无符号的小端序64位整数。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。默认值: 0。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| bigint | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.from([0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x70, 
        0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78]);
console.log(buf.readBigUInt64LE(0).toString());

let buf1 = buffer.allocUninitializedFromPool(8);
buf1.writeBigUInt64BE(0xdecafafecacefaden, 0);
```

### readDoubleBE

readDoubleBE(offset?: number): number

从指定`offset`处读取64位大端序双精度值。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。默认值: 0。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.from([1, 2, 3, 4, 5, 6, 7, 8]);
console.log(buf.readDoubleBE(0).toString());

let buf1 = buffer.allocUninitializedFromPool(8);
buf1.writeDoubleBE(123.456, 0);
```

### readDoubleLE

readDoubleLE(offset?: number): number

从指定`offset`处读取64位小端序双精度值。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。默认值: 0。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.from([1, 2, 3, 4, 5, 6, 7, 8]);
console.log(buf.readDoubleLE(0).toString());

let buf1 = buffer.allocUninitializedFromPool(8);
buf1.writeDoubleLE(123.456, 0);
```

### readFloatBE

readFloatBE(offset?: number): number

从指定`offset`处读取32位大端序浮点数。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。默认值: 0。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.from([1, 2, 3, 4, 5, 6, 7, 8]);
console.log(buf.readFloatBE(0).toString());

let buf1 = buffer.allocUninitializedFromPool(4);
buf1.writeFloatBE(0xcabcbcbc, 0);
```

### readFloatLE

readFloatLE(offset?: number): number

从指定`offset`处读取32位小端序浮点数。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。默认值: 0。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.from([1, 2, 3, 4, 5, 6, 7, 8]);
console.log(buf.readFloatLE(0).toString());

let buf1 = buffer.allocUninitializedFromPool(4);
buf1.writeFloatLE(0xcabcbcbc, 0);
```

### readInt8

readInt8(offset?: number): number

从指定的`offset`处读取有符号的8位整数。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。默认值: 0。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.from([-1, 5]);
console.log(buf.readInt8(0).toString());	// 打印: -1
console.log(buf.readInt8(1).toString());	// 打印: 5

let buf1 = buffer.allocUninitializedFromPool(2);
buf1.writeInt8(0x12);
```

### readInt16BE

readInt16BE(offset?: number): number

从指定的`offset`处读取有符号的大端序16位整数。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。默认值: 0。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.from([0, 5]);
console.log(buf.readInt16BE(0).toString());	// 打印: 5

let buf1 = buffer.alloc(2);
buf1.writeInt16BE(0x1234, 0);
```

### readInt16LE

readInt16LE(offset?: number): number

从指定的`offset`处读取有符号的小端序16位整数

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。默认值: 0。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.from([0, 5]);
console.log(buf.readInt16LE(0).toString());	// 打印: 1280

let buf1 = buffer.alloc(2);
buf1.writeInt16BE(0x1234, 0);
```

### readInt32BE

readInt32BE(offset?: number): number

从指定的`offset`处读取有符号的大端序32位整数

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。默认值: 0。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.from([0, 0, 0, 5]);
console.log(buf.readInt32BE(0).toString());	// 打印: 5

let buf1 = buffer.alloc(4);
buf1.writeInt32BE(0x12345678, 0);
```

### readInt32LE

readInt32LE(offset?: number): number

从指定的`offset`处读取有符号的小端序32位整数

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。默认值: 0。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.from([0, 0, 0, 5]);
console.log(buf.readInt32LE(0).toString());	// 打印: 83886080

let buf1 = buffer.alloc(4);
buf1.writeInt32BE(0x12345678, 0);
```

### readIntBE

readIntBE(offset: number, byteLength: number): number

从指定的`offset`处的buf读取byteLength个字节，并将结果解释为支持最高48位精度的大端序、二进制补码有符号值。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 是 | 偏移量。 默认值: 0。 |
| byteLength | number | 是 | 读取的字节数。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取的内容。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[offset/byteLength]" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.from("ab");
let num = buf.readIntBE(0, 1);
console.log(num.toString()); // 97

let buf1 = buffer.allocUninitializedFromPool(6);
buf1.writeIntBE(0x123456789011, 0, 6);
```


### readIntLE

readIntLE(offset: number, byteLength: number): number

从指定的`offset`处的buf读取`byteLength`个字节，并将结果解释为支持最高48位精度的小端序、二进制补码有符号值。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 是 | 偏移量。 默认值: 0。 |
| byteLength | number | 是 | 读取的字节数。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[offset/byteLength]" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.from([0x12, 0x34, 0x56, 0x78, 0x90, 0xab]);
console.log(buf.readIntLE(0, 6).toString(16));

let buf1 = buffer.allocUninitializedFromPool(6);
buf1.writeIntLE(0x123456789011, 0, 6);
```

### readUInt8

readUInt8(offset?: number): number

从`offset`处读取8位无符号整型数。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。 默认值: 0。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.from([1, -2]);
console.log(buf.readUInt8(0).toString());
console.log(buf.readUInt8(1).toString());

let buf1 = buffer.allocUninitializedFromPool(4);
buf1.writeUInt8(0x42);
```

### readUInt16BE

readUInt16BE(offset?: number): number

从指定的`offset`处的buf读取无符号的大端序16位整数。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。 默认值: 0。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.from([0x12, 0x34, 0x56]);
console.log(buf.readUInt16BE(0).toString(16));
console.log(buf.readUInt16BE(1).toString(16));

let buf1 = buffer.allocUninitializedFromPool(4);
buf1.writeUInt16BE(0x1234, 0);
```

### readUInt16LE

readUInt16LE(offset?: number): number

从指定的`offset`处的buf读取无符号的小端序16位整数。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。 默认值: 0。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.from([0x12, 0x34, 0x56]);
console.log(buf.readUInt16LE(0).toString(16));
console.log(buf.readUInt16LE(1).toString(16));

let buf1 = buffer.allocUninitializedFromPool(4);
buf1.writeUInt16LE(0x1234, 0);
```

### readUInt32BE

readUInt32BE(offset?: number): number

从指定的`offset`处的buf读取无符号的大端序32位整数。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。 默认值: 0。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.from([0x12, 0x34, 0x56, 0x78]);
console.log(buf.readUInt32BE(0).toString(16));

let buf1 = buffer.allocUninitializedFromPool(4);
buf1.writeUInt32BE(0x12345678, 0);
```

### readUInt32LE

readUInt32LE(offset?: number): number

从指定的`offset`处的buf读取无符号的小端序32位整数。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。 默认值: 0。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.from([0x12, 0x34, 0x56, 0x78]);
console.log(buf.readUInt32LE(0).toString(16));

let buf1 = buffer.allocUninitializedFromPool(4);
buf1.writeUInt32LE(0x12345678, 0);
```

### readUIntBE

readUIntBE(offset: number, byteLength: number): number

从指定的`offset`处的buf读取`byteLength`个字节，并将结果解释为支持最高48位精度的无符号大端序整数。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 是 | 偏移量。 默认值: 0。 |
| byteLength | number | 是 | 要读取的字节数。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[offset/byteLength]" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.from([0x12, 0x34, 0x56, 0x78, 0x90, 0xab]);
console.log(buf.readUIntBE(0, 6).toString(16));

let buf1 = buffer.allocUninitializedFromPool(4);
buf1.writeUIntBE(0x13141516, 0, 4);
```

### readUIntLE

readUIntLE(offset: number, byteLength: number): number

从指定的`offset`处的buf读取`byteLength`个字节，并将结果解释为支持最高48位精度的无符号小端序整数。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 是 | 偏移量。 默认值: 0。 |
| byteLength | number | 是 | 要读取的字节数。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[offset/byteLength]" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.from([0x12, 0x34, 0x56, 0x78, 0x90, 0xab]);
console.log(buf.readUIntLE(0, 6).toString(16));

let buf1 = buffer.allocUninitializedFromPool(4);
buf1.writeUIntLE(0x13141516, 0, 4);
```

### subarray

subarray(start?: number, end?: number): Buffer

截取指定位置的`this`实例并返回。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| start | number | 否 | 截取开始位置。 默认值: 0。 |
| end | number | 否 |  截取结束位置（不包括在内）。 默认值: buf.length。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Buffer | 新的Buffer实例。 |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf1 = buffer.allocUninitializedFromPool(26);

for (let i = 0; i < 26; i++) {
  buf1[i] = i + 97;
}
const buf2 = buf1.subarray(0, 3);
console.log(buf2.toString('ascii', 0, buf2.length));
// 打印: abc
```

### swap16

swap16(): Buffer

将`this`实例解释为无符号的16位整数数组，并就地交换字节顺序。

**系统能力：** SystemCapability.Utils.Lang


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Buffer | 交换之后的Buffer实例。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200009 | Buffer size must be a multiple of 16-bits |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf1 = buffer.from([0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8]);
console.log(buf1.toString('hex'));	// 打印: 0102030405060708

buf1.swap16();
console.log(buf1.toString('hex'));	// 打印: 0201040306050807
```

### swap32

swap32(): Buffer

将`this`实例解释为无符号的32位整数数组，并就地交换字节顺序

**系统能力：** SystemCapability.Utils.Lang


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Buffer | 交换之后的Buffer实例。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200009 | Buffer size must be a multiple of 32-bits |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf1 = buffer.from([0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8]);
console.log(buf1.toString('hex'));	// 打印: 0102030405060708

buf1.swap32();
console.log(buf1.toString('hex'));	// 打印: 0403020108070605
```

### swap64

swap64(): Buffer

将`this`实例解释为无符号的64位整数数组，并就地交换字节顺序

**系统能力：** SystemCapability.Utils.Lang


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Buffer | 交换之后的Buffer实例。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200009 | Buffer size must be a multiple of 64-bits |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf1 = buffer.from([0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8]);
console.log(buf1.toString('hex'));	// 打印: 0102030405060708
buf1.swap64();
console.log(buf1.toString('hex'));	// 打印: 0807060504030201
```

### toJSON

toJSON(): Object

将buf转为JSON并返回。

**系统能力：** SystemCapability.Utils.Lang


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Object | JSON对象。 |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf1 = buffer.from([0x1, 0x2, 0x3, 0x4, 0x5]);
let obj = buf1.toJSON();
console.log(JSON.stringify(obj))
// 打印: {"type":"Buffer","data":[1,2,3,4,5]}
```

### toString

toString(encoding?: string, start?: number, end?: number): string

将`this`实例中指定位置数据转成指定编码格式字符串并返回。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| encoding | string | 否 | 字符编码格式。 默认值: 'utf-8'。 |
| start  | number | 否 |  开始位置。 默认值: 0。 |
| end  | number | 否 |  结束位置。 默认值: buf.length。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 字符串。 |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf1 = buffer.allocUninitializedFromPool(26);
for (let i = 0; i < 26; i++) {
  buf1[i] = i + 97;
}
console.log(buf1.toString('utf-8'));
// 打印: abcdefghijklmnopqrstuvwxyz
```

### values

values(): IterableIterator&lt;number&gt;

返回一个包含value的迭代器。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;number&gt; | 迭代器。 |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf1 = buffer.from('buffer');
for (let value of buf1.values()) {
  console.log(value.toString());
}
```

### write

write(str: string, offset?: number, length?: number, encoding?: string): number

从buf的offset偏移写入指定编码的字符串str,写入的字节长度为length

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| str | string | 是 | 要写入Buffer的字符串。 |
| offset | number | 否 | 偏移量。 默认值: 0。 |
| length | number | 否 | 最大字节长度。 默认值: (buf.length - offset)。|
| encoding | string | 否 | 字符编码。 默认值: 'utf-8'。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[offset/length]" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.alloc(256);
let len = buf.write('\u00bd + \u00bc = \u00be', 0);
console.log(`${len} bytes: ${buf.toString('utf-8', 0, len)}`);
// 打印: 12 bytes: ½ + ¼ = ¾

let buffer1 = buffer.alloc(10);
let length = buffer1.write('abcd', 8);
```

### writeBigInt64BE

writeBigInt64BE(value: bigint, offset?: number): number

从buf的offset偏移写入有符号的大端序64位BigInt型数据value

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | bigint | 是 | 写入 buf 的数字。 |
| offset | number | 否 | 偏移量。 默认值: 0。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[value/offset]" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.allocUninitializedFromPool(8);
buf.writeBigInt64BE(0x0102030405060708n, 0);
```

### writeBigInt64LE

writeBigInt64LE(value: bigint, offset?: number): number

从buf的offset偏移写入有符号的小端序64位BigInt型数据value

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | bigint | 是 | 写入 buf 的数字。 |
| offset | number | 否 | 偏移量。 默认值: 0。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[value/offset]" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.allocUninitializedFromPool(8);
buf.writeBigInt64LE(0x0102030405060708n, 0);
```

### writeBigUInt64BE

writeBigUInt64BE(value: bigint, offset?: number): number

从buf的offset偏移写入无符号的大端序64位BigUInt型数据value

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | bigint | 是 | 写入 buf 的数字。 |
| offset | number | 否 | 偏移量。 默认值: 0。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[value/offset]" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.allocUninitializedFromPool(8);
buf.writeBigUInt64BE(0xdecafafecacefaden, 0);
```

### writeBigUInt64LE

writeBigUInt64LE(value: bigint, offset?: number): number

从buf的offset偏移写入无符号的小端序64位BigUInt型数据value

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | bigint | 是 | 写入 buf 的数字。 |
| offset | number | 否 | 偏移量。 默认值: 0。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[value/offset]" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.allocUninitializedFromPool(8);
buf.writeBigUInt64LE(0xdecafafecacefaden, 0);
```

### writeDoubleBE

writeDoubleBE(value: number, offset?: number): number

从buf的offset偏移写入大端序的64位双浮点型数据value

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入 buf 的数字。 |
| offset | number | 否 | 偏移量。 默认值: 0。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[value/offset]" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.allocUninitializedFromPool(8);
buf.writeDoubleBE(123.456, 0);
```

### writeDoubleLE

writeDoubleLE(value: number, offset?: number): number

从buf的offset偏移写入小端序的64位双浮点型数据value

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入 buf 的数字。 |
| offset | number | 否 | 偏移量。 默认值: 0。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[value/offset]" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.allocUninitializedFromPool(8);
buf.writeDoubleLE(123.456, 0);
```

### writeFloatBE

writeFloatBE(value: number, offset?: number): number

从buf的offset偏移写入大端序的32位浮点型数据value

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入 buf 的数字。 |
| offset | number | 否 | 偏移量。 默认值: 0。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[value/offset]" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.allocUninitializedFromPool(8);
buf.writeFloatBE(0xcafebabe, 0);
```


### writeFloatLE

writeFloatLE(value: number, offset?: number): number

从buf的offset偏移写入小端序的32位浮点型数据value

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入 buf 的数字。 |
| offset | number | 否 | 偏移量。 默认值: 0。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[value/offset]" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.allocUninitializedFromPool(8);
buf.writeFloatLE(0xcafebabe, 0);
```

### writeInt8

writeInt8(value: number, offset?: number): number

从buf的offset偏移写入8位有符号整型数据value

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入 buf 的数字。 |
| offset | number | 否 | 偏移量。 默认值: 0。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[value/offset]" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.allocUninitializedFromPool(2);
buf.writeInt8(2, 0);
buf.writeInt8(-2, 1);
```


### writeInt16BE

writeInt16BE(value: number, offset?: number): number

从buf的offset偏移写入大端序的16位有符号整型数据value

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入 buf 的数字。 |
| offset | number | 否 | 偏移量。 默认值: 0。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[value/offset]" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.allocUninitializedFromPool(2);
buf.writeInt16BE(0x0102, 0);
```


### writeInt16LE

writeInt16LE(value: number, offset?: number): number

从buf的offset偏移写入小端序的16位有符号整型数据value

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入 buf 的数字。 |
| offset | number | 否 | 偏移量。 默认值: 0。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[value/offset]" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.allocUninitializedFromPool(2);
buf.writeInt16LE(0x0304, 0);
```

### writeInt32BE

writeInt32BE(value: number, offset?: number): number

从buf的offset偏移写入大端序的32位有符号整型数据value

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入 buf 的数字。 |
| offset | number | 否 | 偏移量。 默认值: 0。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[value/offset]" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.allocUninitializedFromPool(4);
buf.writeInt32BE(0x01020304, 0);
```


### writeInt32LE

writeInt32LE(value: number, offset?: number): number

从buf的offset偏移写入小端序的32位有符号整型数据value

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入 buf 的数字。 |
| offset | number | 否 | 偏移量。 默认值: 0。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[value/offset]" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.allocUninitializedFromPool(4);
buf.writeInt32LE(0x05060708, 0);
```

### writeIntBE

writeIntBE(value: number, offset: number, byteLength: number): number

从buf的offset偏移写入大端序的有符号value数据,value字节长度为byteLength

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入 buf 的数字。 |
| offset | number | 是 | 偏移量。 默认值: 0。 |
| byteLength | number | 是 | 要写入的字节数。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[value/offset/byteLength]" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.allocUninitializedFromPool(6);
buf.writeIntBE(0x1234567890ab, 0, 6);
```


### writeIntLE

writeIntLE(value: number, offset: number, byteLength: number): number

从buf的offset偏移写入小端序的有符号value数据,value字节长度为byteLength

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入 buf 的数字。 |
| offset | number | 是 | 偏移量。 默认值: 0。 |
| byteLength | number | 是 | 要写入的字节数。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[value/offset/byteLength]" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.allocUninitializedFromPool(6);
buf.writeIntLE(0x1234567890ab, 0, 6);
```

### writeUInt8

writeUInt8(value: number, offset?: number): number

从buf的offset偏移写入8位无符号整型数据value

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入 buf 的数字。 |
| offset | number | 否 | 偏移量。 默认值: 0。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[value/offset]" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.allocUninitializedFromPool(4);
buf.writeUInt8(0x3, 0);
buf.writeUInt8(0x4, 1);
buf.writeUInt8(0x23, 2);
buf.writeUInt8(0x42, 3);
```

### writeUInt16BE

writeUInt16BE(value: number, offset?: number): number

从buf的offset偏移写入大端序的16位无符号整型数据value

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入 buf 的数字。 |
| offset | number | 否 | 偏移量。 默认值: 0。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[value/offset]" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.allocUninitializedFromPool(4);
buf.writeUInt16BE(0xdead, 0);
buf.writeUInt16BE(0xbeef, 2);
```

### writeUInt16LE

writeUInt16LE(value: number, offset?: number): number

从buf的offset偏移写入小端序的16位无符号整型数据value

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入 buf 的数字。 |
| offset | number | 否 | 偏移量。 默认值: 0。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[value/offset]" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.allocUninitializedFromPool(4);
buf.writeUInt16LE(0xdead, 0);
buf.writeUInt16LE(0xbeef, 2);
```

### writeUInt32BE

writeUInt32BE(value: number, offset?: number): number

从buf的offset偏移写入大端序的32位无符号整型数据value

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入 buf 的数据。 |
| offset | number | 否 | 偏移量。 默认值: 0。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[value/offset]" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.allocUninitializedFromPool(4);
buf.writeUInt32BE(0xfeedface, 0);
```

### writeUInt32LE

writeUInt32LE(value: number, offset?: number): number

从buf的offset偏移写入小端序的32位无符号整型数据value

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入 buf 的数字。 |
| offset | number | 否 | 偏移量。 默认值: 0。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[value/offset]" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.allocUninitializedFromPool(4);
buf.writeUInt32LE(0xfeedface, 0);
```

### writeUIntBE

writeUIntBE(value: number, offset: number, byteLength: number): number

从buf的offset偏移写入大端序的无符号value数据,value字节长度为byteLength

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入 buf 的数据。 |
| offset | number | 是 | 偏移量。 默认值: 0。 |
| byteLength | number | 是 | 要写入的字节数。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[value/offset/byteLength]" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.allocUninitializedFromPool(6);
buf.writeUIntBE(0x1234567890ab, 0, 6);
```

### writeUIntLE

writeUIntLE(value: number, offset: number, byteLength: number): number

从buf的offset偏移写入小端序的无符号value数据,value字节长度为byteLength

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入 buf 的数据。 |
| offset | number | 是 | 偏移量。 默认值: 0。 |
| byteLength | number | 是 | 要写入的字节数。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[buffer错误码](../errorcodes/errorcode-buffer.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[value/offset/byteLength]" is out of range. |

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.allocUninitializedFromPool(6);
buf.writeUIntLE(0x1234567890ab, 0, 6);
```

### transcode

transcode(source: Buffer | Uint8Array, fromEnc: string, toEnc: string): Buffer

将给定的Buffer或Uint8Array实例从一种字符编码重新编码为另一种

**系统能力：** SystemCapability.Utils.Lang

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

**示例：**

```ts
import buffer from '@ohos.buffer';

let buf = buffer.alloc(50);
let newBuf = buffer.transcode(buffer.from('€'), 'utf-8', 'ascii');
console.log(newBuf.toString('ascii'));
```

## Blob

### 属性

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| size | number | 是 | 否 | Blob实例的总字节大小。 |
| type | string | 是 | 否 | Blob实例的内容类型。 |

### constructor

constructor(sources: string[] | ArrayBuffer[] | TypedArray[] | DataView[] | Blob[] , options?: Object)

Blob的构造函数。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| sources | string[]&nbsp;\|&nbsp;ArrayBuffer[]&nbsp;\|&nbsp;TypedArray[]&nbsp;\|&nbsp;DataView[]&nbsp;\|&nbsp;Blob[] | 是 | Blob实例的数据源。 |
| options | Object | 否 | options:<br/>-&nbsp;endings:'transparent'或'native'<br/>-&nbsp;type:Blob内容类型 |


**示例：**
```ts
import buffer from '@ohos.buffer';

let blob = new buffer.Blob(['a', 'b', 'c']);
let blob1 = new buffer.Blob(['a', 'b', 'c'], {endings:'native', type: 'MIME'});
```

### arrayBuffer

arrayBuffer(): Promise&lt;ArrayBuffer&gt;

将Blob中的数据放入到ArrayBuffer中，并返回一个Promise。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;ArrayBuffer&gt; | 返回包含Blob数据的ArrayBuffer的Promise。 |

**示例：**
```ts
let blob = new buffer.Blob(['a', 'b', 'c']);
let pro = blob.arrayBuffer();
pro.then(val => {
  let uintarr = new Uint8Array(val);
  console.log(uintarr.toString());
});
```
### slice

slice(start?: number, end?: number, type?: string): Blob

创建并返回一个复制原blob对象中start到end位置数据的新blob实例对象。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| start | number | 否 | 起始位置。 |
| end | number | 否 | 结束位置。 |
| type | string | 否 | 内容类型。 |

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| Blob | 新的Blob实例对象。 |

**示例：**
```ts
let blob = new buffer.Blob(['a', 'b', 'c']);
let blob2 = blob.slice(0, 2);
let blob3 = blob.slice(0, 2, "MIME");
```

### text

text(): Promise&lt;string&gt;

返回一个Promise，该Promise中的值为UTF8编码类型的文本。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;string&gt; | 包含以UTF8编码的文本的Promise。 |

**示例：**
```ts
let blob = new buffer.Blob(['a', 'b', 'c']);
let pro = blob.text();
pro.then(val => {
    console.log(val)
});
```