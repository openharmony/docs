# @ohos.fastbuffer (FastBuffer)
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @wang_zhaoyong-->
<!--Designer: @Malzahar-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

FastBuffer对象是比Buffer性能更优的Buffer容器，用于表示固定长度的字节序列，是专门存放二进制数据的缓冲区。

FastBuffer通过from构造时，仅支持FastBuffer、Uint8Array、string、Array、ArrayBuffer和SharedArrayBuffer类型的参数。

需要高效处理二进制数据（如图片、文件传输、网络通信等）时，推荐使用FastBuffer以获得更好的性能。

> **说明：**
>
> 本模块首批接口从API version 20开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 容器类使用静态语言实现，限制了存储位置和属性，不支持自定义属性和方法。


## 导入模块

```ts
import { fastbuffer } from '@kit.ArkTS';
```

## BufferEncoding

type BufferEncoding = 'ascii' | 'utf8' | 'utf-8' | 'utf16le' | 'ucs2' | 'ucs-2' | 'base64' | 'base64url' | 'latin1' | 'binary' | 'hex'

表示支持的编码格式类型。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

| 类型    | 说明                 |
| ------- | -------------------- |
| 'ascii' | 表示ascii格式。 |
| 'utf8' | 表示utf8格式。 |
| 'utf-8' | 表示utf8格式。 |
| 'utf16le' | 表示utf16小端序格式。 |
| 'ucs2' | utf16le格式的别名。 |
| 'ucs-2' | utf16le格式的别名。 |
| 'base64' | 表示base64格式。 |
| 'base64url' | 表示base64url格式。 |
| 'latin1' | iso-8859-1的别名，向下兼容ascii格式。 |
| 'binary' | 表示二进制格式。 |
| 'hex' | 表示十六进制格式。 |

## fastbuffer.alloc

alloc(size: number, fill?: string | FastBuffer | number, encoding?: BufferEncoding): FastBuffer

创建指定字节长度的FastBuffer对象并初始化。调用后，FastBuffer对象的每个字节将被填充为指定的fill值，未指定fill时默认填充为0。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| size | number | 是 | 指定的FastBuffer对象长度，单位：字节。取值范围：0 <= size <= UINT32_MAX。|
| fill | string&nbsp;\|&nbsp;[FastBuffer](#fastbuffer)&nbsp;\|&nbsp;number | 否 | 填充至新缓冲区的值，默认值：0。 |
| encoding | [BufferEncoding](#bufferencoding) | 否 | 编码格式（当`fill`为string时，才有意义）。默认值：'utf8'。传入无法识别的encoding会抛出TypeError。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [FastBuffer](#fastbuffer) | 返回一个FastBuffer对象。 |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

// 创建长度为5的FastBuffer对象，默认填充0
let buf1 = fastbuffer.alloc(5);
console.info(buf1.toString());
// 输出结果：00000
// 创建长度为5的FastBuffer对象，填充字符'a'
let buf2 = fastbuffer.alloc(5, 'a');
// 创建长度为11的FastBuffer对象，使用base64编码填充
let buf3 = fastbuffer.alloc(11, 'aGVsbG8gd29ybGQ=', 'base64');
console.info(buf2.toString());
// 输出结果：aaaaa
console.info(buf3.toString());
// 输出结果：hello world
```

## fastbuffer.allocUninitializedFromPool

allocUninitializedFromPool(size: number): FastBuffer

从缓冲池中创建指定大小未初始化的FastBuffer对象。调用[fill](#fill)函数初始化该对象。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| size | number | 是 | 指定的FastBuffer对象长度，单位：字节。取值范围：0 <= size <= UINT32_MAX。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [FastBuffer](#fastbuffer) | 未初始化的FastBuffer实例。 |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(10);
buf.fill(0);
// "buf":[0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
```

## fastbuffer.allocUninitialized

allocUninitialized(size: number): FastBuffer

创建指定大小未初始化的FastBuffer对象。调用[fill](#fill)函数初始化该对象。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| size | number | 是 | 指定的FastBuffer对象长度，单位：字节。取值范围：0 <= size <= UINT32_MAX。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [FastBuffer](#fastbuffer) | 未初始化的FastBuffer实例。 |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitialized(10);
buf.fill(0);
// "buf":[0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
```

## fastbuffer.byteLength

byteLength(value: string | FastBuffer | TypedArray | DataView | ArrayBuffer | SharedArrayBuffer, encoding?: BufferEncoding): number

根据不同的编码格式，返回指定内容的字节数。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | string&nbsp;\|&nbsp;[FastBuffer](#fastbuffer)&nbsp;\|&nbsp;TypedArray&nbsp;\|&nbsp;DataView&nbsp;\|&nbsp;ArrayBuffer&nbsp;\|&nbsp;SharedArrayBuffer | 是 | 指定用于计算字节长度的内容。 |
| encoding | [BufferEncoding](#bufferencoding) | 否 | 编码格式（当`value`为string时，才有意义）。默认值：'utf8'。传入无法识别的encoding会抛出TypeError。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回指定内容的字节数。 |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let str = 'hello world';
console.info(`${str}: ${str.length} characters, ${fastbuffer.byteLength(str, 'utf-8')} bytes`);
// 输出结果：hello world: 11 characters, 11 bytes

str = '\u00bd + \u00bc = \u00be';
console.info(`${str}: ${str.length} characters, ${fastbuffer.byteLength(str, 'utf-8')} bytes`);
// 输出结果：½ + ¼ = ¾: 9 characters, 12 bytes
```

## fastbuffer.compare

compare(buf1: FastBuffer | Uint8Array, buf2: FastBuffer | Uint8Array): -1 | 0 | 1

返回两个FastBuffer对象的比较结果，通常用于对FastBuffer对象数组进行排序。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| buf1 | [FastBuffer](#fastbuffer)&nbsp;\|&nbsp;Uint8Array | 是 | 待比较的第一个对象。 |
| buf2 | [FastBuffer](#fastbuffer)&nbsp;\|&nbsp;Uint8Array | 是 | 待比较的第二个对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| -1&nbsp;\|&nbsp;0&nbsp;\|&nbsp;1 | 如果buf1与buf2相同，则返回0。<br/>如果排序时buf1位于buf2之后，则返回1。<br/>如果排序时buf1位于buf2之前，则返回-1。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200068 | The underlying ArrayBuffer is null or detach. |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf1 = fastbuffer.from('1234');
let buf2 = fastbuffer.from('0123');
let compareResult = fastbuffer.compare(buf1, buf2);

console.info(Number(compareResult).toString());
// 输出结果：1
```

## fastbuffer.concat

concat(list: FastBuffer[] | Uint8Array[], totalLength?: number): FastBuffer

将数组中指定字节长度的内容复制并拼接后，返回新的FastBuffer对象。

当数组中所有对象的长度总和大于totalLength时，返回结果的长度将被截断为totalLength。

当数组中所有对象的长度总和小于totalLength时，返回结果的多余部分将会被填充为0。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| list | [FastBuffer](#fastbuffer)[]&nbsp;\|&nbsp;Uint8Array[] | 是 | 待拼接的FastBuffer或Uint8Array实例数组，数组中所有对象的内容将被依次复制到新的FastBuffer对象中。 |
| totalLength | number | 否 | 需要复制的总字节长度，默认值为数组中所有对象的长度总和。取值范围：0 <= totalLength <= UINT32_MAX。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [FastBuffer](#fastbuffer) | 返回新的FastBuffer对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | Range error. Possible causes: The value of the parameter is not within the specified range. |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf1 = fastbuffer.from('1234');
let buf2 = fastbuffer.from('abcd');
let buf = fastbuffer.concat([buf1, buf2]);
console.info(buf.toString('hex'));
// 输出结果：3132333461626364
```

## fastbuffer.from

from(array: number[]): FastBuffer

根据指定数组创建新的FastBuffer对象。

**系统能力：** SystemCapability.Utils.Lang

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| array | number[] | 是 | 指定数组，数组内各元素的取值范围为[0, 255]。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [FastBuffer](#fastbuffer) | 新的FastBuffer对象。 |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from([0x62, 0x75, 0x66, 0x66, 0x65, 0x72]);
console.info(buf.toString('hex'));
// 输出结果：627566666572
```

## fastbuffer.from

from(arrayBuffer: ArrayBuffer | SharedArrayBuffer, byteOffset?: number, length?: number): FastBuffer

创建与`arrayBuffer`共享内存的指定长度的FastBuffer对象。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| arrayBuffer | ArrayBuffer&nbsp;\|&nbsp;SharedArrayBuffer | 是 | 用于创建FastBuffer对象的底层ArrayBuffer或SharedArrayBuffer，创建的FastBuffer将与该对象共享相同的内存区域。 |
| byteOffset | number | 否 | 字节偏移量，默认值：0。 |
| length | number | 否 | 字节长度，默认值：（arrayBuffer.byteLength - byteOffset）。取值范围：0 <= length <= arrayBuffer.byteLength - byteOffset。传入null时返回长度为0的FastBuffer对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [FastBuffer](#fastbuffer) | 返回一个FastBuffer对象，该对象与入参对象`arrayBuffer`共享相同的内存区域。修改FastBuffer对象的数据将同步修改原ArrayBuffer中对应位置的数据，修改原ArrayBuffer的数据也会同步修改FastBuffer中对应位置的数据。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | Range error. Possible causes: The value of the parameter is not within the specified range. |
| 10200068 | The underlying ArrayBuffer is null or detach. |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let arrayBuffer = new ArrayBuffer(10);
let buf = fastbuffer.from(arrayBuffer, 0, 2);
console.info(buf.length.toString());
// 输出结果：2
```

## fastbuffer.from

from(buffer: FastBuffer | Uint8Array): FastBuffer

当入参为FastBuffer对象时，创建新的FastBuffer对象并复制入参数据。新旧对象数据独立，互不影响。

当入参为Uint8Array对象时，基于其内存创建新的FastBuffer对象。两个对象保持内存关联，修改任一对象的数据会同步影响另一对象。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| buffer | [FastBuffer](#fastbuffer)&nbsp;\|&nbsp;Uint8Array | 是 | 用于创建新FastBuffer对象的源数据。当入参为FastBuffer时，将复制其数据创建新对象；当入参为Uint8Array时，基于其内存创建新对象并保持内存关联。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [FastBuffer](#fastbuffer) | 返回新的FastBuffer对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200068 | The underlying ArrayBuffer is null or detach. |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

// 从字符串创建FastBuffer对象
let buf1 = fastbuffer.from('buffer');
// 以FastBuffer对象类型创建新的FastBuffer对象
let buf2 = fastbuffer.from(buf1);
console.info(buf2.toString());
// 输出结果：buffer

// 以Uint8Array对象类型进行创建FastBuffer对象，保持对象间内存共享
let uint8Array = new Uint8Array(10);
let buf3 = fastbuffer.from(uint8Array);
// 修改buf3以验证内存共享：buf3修改后uint8Array同步变化
buf3.fill(1);
console.info('uint8Array:', uint8Array);
// 输出结果：1,1,1,1,1,1,1,1,1,1
```

## fastbuffer.from

from(value: string, encoding?: BufferEncoding): FastBuffer

根据指定编码格式的字符串，创建新的FastBuffer对象。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | string | 是 | 用于创建FastBuffer对象的字符串。 |
| encoding | [BufferEncoding](#bufferencoding) | 否 | 编码格式。默认值：'utf8'。传入无法识别的encoding会抛出TypeError。|

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [FastBuffer](#fastbuffer) | 返回新的FastBuffer对象。 |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

// 从普通字符串创建FastBuffer对象
let buf1 = fastbuffer.from('this is a test');
// 从hex编码字符串创建FastBuffer对象
let buf2 = fastbuffer.from('7468697320697320612074c3a97374', 'hex');

console.info(buf1.toString());
// 输出结果：this is a test
console.info(buf2.toString());
// 输出结果：this is a tést
```


## fastbuffer.isBuffer

isBuffer(obj: Object): boolean

判断`obj`是否为FastBuffer。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| obj | Object | 是 | 待判断是否为FastBuffer的对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果obj是FastBuffer，则返回true，否则返回false。 |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let allocResult = fastbuffer.isBuffer(fastbuffer.alloc(10)); // 10: fastbuffer size
console.info('allocResult = ' + allocResult);
// 输出结果：allocResult = true
let fromResult = fastbuffer.isBuffer(fastbuffer.from('foo'));
console.info('fromResult = ' + fromResult);
// 输出结果：fromResult = true
let stringResult = fastbuffer.isBuffer('a string');
console.info('stringResult = ' + stringResult);
// 输出结果：stringResult = false
let arrayResult = fastbuffer.isBuffer([]);
console.info('arrayResult = ' + arrayResult);
// 输出结果：arrayResult = false
let uint8ArrayResult = fastbuffer.isBuffer(new Uint8Array(1024));
console.info('uint8ArrayResult = ' + uint8ArrayResult);
// 输出结果：uint8ArrayResult = false
```

## fastbuffer.isEncoding

isEncoding(encoding: string): boolean

判断`encoding`是否为支持的编码格式。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| encoding | string | 是 | 待判断是否为支持的编码格式。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 是支持的编码格式返回true，反之则返回false。 |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

console.info(fastbuffer.isEncoding('utf-8').toString());
// 输出结果：true
console.info(fastbuffer.isEncoding('hex').toString());
// 输出结果：true
console.info(fastbuffer.isEncoding('utf/8').toString());
// 输出结果：false
console.info(fastbuffer.isEncoding('').toString());
// 输出结果：false
```

## fastbuffer.transcode

transcode(source: FastBuffer | Uint8Array, fromEnc: string, toEnc: string): FastBuffer

将FastBuffer或Uint8Array对象从fromEnc编码转换为toEnc编码。适用于需要在不同编码格式之间转换数据的场景。例如，将UTF-8编码的数据转换为Latin1编码，以便在仅支持ASCII的系统中处理。

fastbuffer.transcode支持的编码：'ascii' | 'utf8' | 'utf16le'| 'ucs2' | 'latin1'| 'binary'。

**系统能力：** SystemCapability.Utils.Lang

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| source | [FastBuffer](#fastbuffer)&nbsp;\|&nbsp;Uint8Array | 是 | 需要进行编码转换的源数据对象，将从fromEnc编码转换为toEnc编码。 |
| fromEnc | string | 是 | 当前编码格式。支持的格式范围为'ascii' \| 'utf8' \| 'utf16le' \| 'ucs2' \| 'latin1' \| 'binary'。传入空字符串时，表示使用编码格式'utf8'。 |
| toEnc | string | 是 | 目标编码。支持的格式范围为'ascii' \| 'utf8' \| 'utf16le' \| 'ucs2' \| 'latin1' \| 'binary'。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [FastBuffer](#fastbuffer) | 将当前编码转换成目标编码，并返回一个新的FastBuffer对象。 |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let newBuf = fastbuffer.transcode(fastbuffer.from('buffer'), 'utf-8', 'ascii');
console.info('newBuf = ' + newBuf.toString('ascii'));
// 输出结果：newBuf = buffer
```

## FastBuffer

### 属性

**系统能力：** SystemCapability.Utils.Lang

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| length | number | 是 | 否 | FastBuffer对象的字节长度。 |
| buffer | ArrayBuffer | 是 | 否 | FastBuffer底层对应的ArrayBuffer对象。 |
| byteOffset | number | 是 | 否 | 当前FastBuffer底层ArrayBuffer的偏移量。 |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from('1236');
console.info(JSON.stringify(buf.length));
// 输出结果：4
let arrayBuffer = buf.buffer;
console.info(JSON.stringify(new Uint8Array(arrayBuffer)));
// 输出结果：{"0":49,"1":50,"2":51,"3":54}
console.info(JSON.stringify(buf.byteOffset));
// 输出结果：0
```

### compare

compare(target: FastBuffer | Uint8Array, targetStart?: number, targetEnd?: number, sourceStart?: number, sourceEnd?: number): -1 | 0 | 1

比较当前对象this与目标对象target，并返回比较结果。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| target | [FastBuffer](#fastbuffer)&nbsp;\|&nbsp;Uint8Array | 是 | 要比较的实例对象。 |
| targetStart | number | 否 | `target`实例中开始的偏移量。默认值：0。取值范围：0 <= targetStart <= target.length。 |
| targetEnd | number | 否 | `target`实例中结束的偏移量（不包含结束位置）。默认值：目标对象的字节长度。取值范围：0 <= targetEnd <= target.length。 |
| sourceStart | number | 否 | `this`实例中开始的偏移量。默认值：0。取值范围：0 <= sourceStart <= this.length。|
| sourceEnd | number | 否 | `this`实例中结束的偏移量（不包含结束位置）。默认值：当前对象的字节长度。取值范围：0 <= sourceEnd <= this.length。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| -1 \| 0 \| 1 | 返回比较结果。<br>-1：当前排列在目标前；<br>0：当前与目标相同；<br>1：当前排列在目标后。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | Range error. Possible causes: The value of the parameter is not within the specified range. |
| 10200068 | The underlying ArrayBuffer is null or detach. |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf1 = fastbuffer.from([1, 2, 3, 4, 5, 6, 7, 8, 9]);
let buf2 = fastbuffer.from([5, 6, 7, 8, 9, 1, 2, 3, 4]);

// 比较buf1[0,4)与buf2[5,9)，结果为0表示相同
console.info(buf1.compare(buf2, 5, 9, 0, 4).toString());
// 输出结果：0
// 比较buf1[4,end)与buf2[0,6)，结果为-1表示buf1排在前面
console.info(buf1.compare(buf2, 0, 6, 4).toString());
// 输出结果：-1
// 比较buf1[5,end)与buf2[5,6)，结果为1表示buf1排在后面
console.info(buf1.compare(buf2, 5, 6, 5).toString());
// 输出结果：1
```

### copy

copy(target: FastBuffer| Uint8Array, targetStart?: number, sourceStart?: number, sourceEnd?: number): number

将`this`实例中指定位置的数据复制到`target`的指定位置上，并返回复制的字节总长度。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| target | [FastBuffer](#fastbuffer)&nbsp;\|&nbsp;Uint8Array | 是 | 要复制到的Buffer或Uint8Array实例。 |
| targetStart | number | 否 | `target`实例中开始写入的偏移量。默认值：0。取值范围：0 <= targetStart <= UINT32_MAX。 |
| sourceStart | number | 否 | `this`实例中开始复制的偏移量。默认值：0。取值范围：0 <= sourceStart <= UINT32_MAX。 |
| sourceEnd | number | 否 | `this`实例中结束复制的偏移量（不包含结束位置）。默认值：当前对象的字节长度。取值范围：0 <= sourceEnd <= this.length。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number |  复制的字节总长度。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | Range error. Possible causes: The value of the parameter is not within the specified range. |
| 10200068 | The underlying ArrayBuffer is null or detach. |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

// 创建未初始化的FastBuffer对象作为复制源
let buf1 = fastbuffer.allocUninitializedFromPool(26);
// 创建填充'!'的FastBuffer对象作为复制目标
let buf2 = fastbuffer.allocUninitializedFromPool(26).fill('!');
// 向buf1写入a-z的ASCII字符
for (let i = 0; i < 26; i++) {
  buf1.writeInt8(i + 97, i);
}
// 将buf1的第16到20字节复制到buf2的第8字节起的位置
buf1.copy(buf2, 8, 16, 20);
console.info(buf2.toString('ascii', 0, 25));
// 输出结果：!!!!!!!!qrst!!!!!!!!!!!!!
```

### entries

entries(): IterableIterator&lt;[number,&nbsp;number]&gt;

返回一个包含key值和value值的迭代器，其中key为字节索引位置，value为该位置的字节值。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;[number,&nbsp;number]&gt; |  包含key和value的迭代器，同时两者皆为number类型。 |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

// 创建FastBuffer对象
let buf = fastbuffer.from('buffer');
// 获取entries迭代器
let entryIterator = buf.entries();
// 获取迭代器的第一个元素
let nextEntry: IteratorResult<[number, number]> = entryIterator.next();
// 遍历迭代器输出每个[key, value]对
while (!nextEntry.done) {
  console.info('fastbuffer: ' + nextEntry.value);
  /*
  输出结果：fastbuffer: 0,98
           fastbuffer: 1,117
           fastbuffer: 2,102
           fastbuffer: 3,102
           fastbuffer: 4,101
           fastbuffer: 5,114
   */
  nextEntry = entryIterator.next();
}
```

### equals

equals(otherBuffer: Uint8Array | FastBuffer): boolean

逐字节比较`this`和otherBuffer是否相等。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| otherBuffer | Uint8Array&nbsp;\|&nbsp;[FastBuffer](#fastbuffer) | 是 | 比较的目标对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 若`this`和otherBuffer逐字节相等则返回true，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200068 | The underlying ArrayBuffer is null or detach. |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf1 = fastbuffer.from('ABC');
let buf2 = fastbuffer.from('414243', 'hex');
let buf3 = fastbuffer.from('ABCD');

console.info(buf1.equals(buf2).toString());
// 输出结果：true
console.info(buf1.equals(buf3).toString());
// 输出结果：false
```

### fill

fill(value: string | FastBuffer | Uint8Array | number, offset?: number, end?: number, encoding?: BufferEncoding): FastBuffer

使用`value`填充当前对象指定位置的数据，当`value`长度小于待填充范围时将循环重复`value`进行填充，并返回填充后的FastBuffer对象。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | string&nbsp;\|&nbsp;[FastBuffer](#fastbuffer)&nbsp;\|&nbsp;Uint8Array&nbsp;\|&nbsp;number | 是 | 用于填充的值。 |
| offset | number | 否 | 起始偏移量。默认值：0。取值范围：0 <= offset <= this.length。 |
| end | number | 否 | 结束偏移量（不包含结束位置）。 默认值：当前对象的字节长度。取值范围：0 <= end <= this.length。 |
| encoding | [BufferEncoding](#bufferencoding) | 否 | 字符编码格式（`value`为string才有意义）。默认值：'utf8'。传入无法识别的encoding会抛出TypeError。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [FastBuffer](#fastbuffer) | 返回填充后的FastBuffer对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | Range error. Possible causes: The value of the parameter is not within the specified range. |
| 10200068 | The underlying ArrayBuffer is null or detach. |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let filledBuffer = fastbuffer.allocUninitializedFromPool(50).fill('h');
console.info(filledBuffer.toString());
// 输出结果：hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
```


### includes

includes(value: string | number | FastBuffer | Uint8Array, byteOffset?: number, encoding?: BufferEncoding): boolean

检查FastBuffer对象是否包含`value`值。

若byteOffset为正数，则从0开始计算偏移量；如果为负数，则从末尾开始计算偏移量。

当byteOffset大于等于this.length时，返回false。当byteOffset小于等于-this.length，查找整个FastBuffer中是否存在`value`。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | string&nbsp;\|&nbsp;number&nbsp;\|&nbsp;[FastBuffer](#fastbuffer)&nbsp;\|&nbsp;Uint8Array | 是 | 要搜索的内容。 |
| byteOffset | number | 否 | 字节偏移量。若byteOffset为正数，则从0开始计算偏移量；如果为负数，则从末尾开始计算偏移量。默认值：0。|
| encoding | [BufferEncoding](#bufferencoding) | 否 | 字符编码格式（当`value`为string时，才有意义）。默认值：'utf8'。传入无法识别的encoding会抛出TypeError。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 若FastBuffer对象包含`value`值时返回true，否则为false。 |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from('this is a buffer');
console.info(buf.includes('this').toString());
// 输出结果：true
console.info(buf.includes('be').toString());
// 输出结果：false
```

### indexOf

indexOf(value: string | number | FastBuffer | Uint8Array, byteOffset?: number, encoding?: BufferEncoding): number

返回当前对象中首次出现`value`的索引，如果不包含`value`，则返回-1。

若byteOffset为正数，则从0开始计算偏移量；如果为负数，则从末尾开始计算偏移量。

当byteOffset大于等于this.length时，返回-1。当byteOffset小于等于-this.length，返回整个FastBuffer中首次出现`value`的索引。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | string&nbsp;\|&nbsp;number&nbsp;\|&nbsp;[FastBuffer](#fastbuffer)&nbsp;\|&nbsp;Uint8Array | 是 | 要查找的内容。 |
| byteOffset | number | 否 | 字节偏移量。若byteOffset为正数，则从0开始计算偏移量；如果为负数，则从末尾开始计算偏移量。默认值：0。|
| encoding | [BufferEncoding](#bufferencoding) | 否 | 字符编码格式（当`value`为string时，才有意义）。默认值：'utf8'。传入无法识别的encoding会抛出TypeError。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回第一次出现的位置。如果不包含`value`，则返回-1。 |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from('this is a buffer');
console.info(buf.indexOf('this').toString());
// 输出结果：0
console.info(buf.indexOf('is').toString());
// 输出结果：2
```

### keys

keys(): IterableIterator&lt;number&gt;

返回一个包含key值的迭代器，其中key为字节索引位置，范围为0到length-1。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
|  IterableIterator&lt;number&gt; | 返回一个包含key值的迭代器。 |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from('buffer');
let keys = buf.keys();
for (const key of keys) {
  console.info(key.toString());
}
/*
输出结果：0
        1
        2
        3
        4
        5
 */
```

### values

values(): IterableIterator&lt;number&gt;

返回一个包含FastBuffer字节值的迭代器。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;number&gt; | 包含FastBuffer中每个字节值的迭代器。 |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf1 = fastbuffer.from('buffer');
let valueIterator = buf1.values();
let nextValue:IteratorResult<number> = valueIterator.next();
while (!nextValue.done) {
  console.info(nextValue.value.toString());
  /*
  输出结果：98
           117
           102
           102
           101
           114
   */
  nextValue = valueIterator.next();
}
```

### lastIndexOf

lastIndexOf(value: string | number | FastBuffer | Uint8Array, byteOffset?: number, encoding?: BufferEncoding): number

返回当前对象中最后一次出现`value`的索引，如果对象不包含`value`，则返回-1。

若byteOffset为正数，则从0开始计算偏移量；如果为负数，则从末尾开始计算偏移量。

当byteOffset大于等于this.length时，返回整个FastBuffer中最后一次出现`value`的索引。当byteOffset小于等于-this.length时，返回-1。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | string&nbsp;\|&nbsp;number&nbsp;\|&nbsp;[FastBuffer](#fastbuffer)&nbsp;\|&nbsp;Uint8Array | 是 | 要搜索的内容。 |
| byteOffset | number | 否 | 字节偏移量。若byteOffset为正数，则从0开始计算偏移量；如果为负数，则从末尾开始计算偏移量。默认值：this.length - 1。|
| encoding | [BufferEncoding](#bufferencoding) | 否 | 字符编码格式（当`value`为string时，才有意义）。默认值：'utf8'。传入无法识别的encoding会抛出TypeError。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 最后一次出现`value`值的索引。如果对象不包含`value`，则返回-1。 |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from('this buffer is a buffer');
console.info(buf.lastIndexOf('this').toString());
// 输出结果：0
console.info(buf.lastIndexOf('buffer').toString());
// 输出结果：17
```


### readBigInt64BE

readBigInt64BE(offset?: number): bigint

从指定的`offset`处读取有符号的大端序64位整数。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。默认值：0。取值范围：0 <= offset <= this.length - 8。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| bigint | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 8. Received value is: [offset]. |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from([0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x70,
  0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78]);
console.info(buf.readBigInt64BE(0).toString());
// 输出结果：7161960797921896816
```

### readBigInt64LE

readBigInt64LE(offset?: number): bigint

从指定的`offset`处读取有符号的小端序64位整数。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。取值范围：0 <= offset <= this.length - 8，默认值：0。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| bigint | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 8. Received value is: [offset]. |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from([0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x70,
  0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78]);
console.info(buf.readBigInt64LE(0).toString());
// 输出结果：8100120198111388771
```

### readBigUInt64BE

readBigUInt64BE(offset?: number): bigint

从指定的`offset`处读取无符号的大端序64位整数。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。取值范围：0 <= offset <= this.length - 8，默认值：0。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| bigint | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 8. Received value is: [offset]. |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from([0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x70,
  0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78]);
console.info(buf.readBigUInt64BE(0).toString());
// 输出结果：7161960797921896816
```

### readBigUInt64LE

readBigUInt64LE(offset?: number): bigint

从指定的`offset`处读取无符号的小端序64位整数。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。取值范围：0 <= offset <= this.length - 8，默认值：0。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| bigint | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 8. Received value is: [offset]. |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from([0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x70,
  0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78]);
console.info(buf.readBigUInt64LE(0).toString());
// 输出结果：8100120198111388771
```

### readDoubleBE

readDoubleBE(offset?: number): number

从指定的`offset`处读取64位大端序双精度值。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。取值范围：0 <= offset <= this.length - 8，默认值：0。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 8. Received value is: [offset]. |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from([1, 2, 3, 4, 5, 6, 7, 8]);
console.info(buf.readDoubleBE(0).toString());
// 输出结果：8.20788039913184e-304
```

### readDoubleLE

readDoubleLE(offset?: number): number

从指定的`offset`处读取64位小端序双精度值。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。取值范围：0 <= offset <= this.length - 8，默认值：0。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 8. Received value is: [offset]. |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from([1, 2, 3, 4, 5, 6, 7, 8]);
console.info(buf.readDoubleLE(0).toString());
// 输出结果：5.447603722011605e-270
```

### readFloatBE

readFloatBE(offset?: number): number

从指定的`offset`处读取32位大端序浮点数。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。取值范围：0 <= offset <= this.length - 4，默认值：0。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 4. Received value is: [offset]. |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from([1, 2, 3, 4, 5, 6, 7, 8]);
console.info(buf.readFloatBE(0).toString());
// 输出结果：2.387939260590663e-38
```

### readFloatLE

readFloatLE(offset?: number): number

从指定的`offset`处读取32位小端序浮点数。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。取值范围：0 <= offset <= this.length - 4，默认值：0。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 4. Received value is: [offset]. |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from([1, 2, 3, 4, 5, 6, 7, 8]);
console.info(buf.readFloatLE(0).toString());
// 输出结果：1.539989614439558e-36
```

### readInt8

readInt8(offset?: number): number

从指定的`offset`处读取有符号的8位整数。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。取值范围：0 <= offset <= this.length - 1，默认值：0。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 1. Received value is: [offset]. |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from([-1, 5]);
console.info(buf.readInt8(0).toString());
// 输出结果：-1
console.info(buf.readInt8(1).toString());
// 输出结果：5
```

### readInt16BE

readInt16BE(offset?: number): number

从指定的`offset`处读取有符号的大端序16位整数。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。取值范围：0 <= offset <= this.length - 2，默认值：0。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 2. Received value is: [offset]. |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from([0, 5]);
console.info(buf.readInt16BE(0).toString());
// 输出结果：5
```

### readInt16LE

readInt16LE(offset?: number): number

从指定的`offset`处读取有符号的小端序16位整数。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。取值范围：0 <= offset <= this.length - 2，默认值：0。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 2. Received value is: [offset]. |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from([0, 5]);
console.info(buf.readInt16LE(0).toString());
// 输出结果：1280
```

### readInt32BE

readInt32BE(offset?: number): number

从指定的`offset`处读取有符号的大端序32位整数。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。取值范围：0 <= offset <= this.length - 4，默认值：0。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 4. Received value is: [offset]. |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from([0, 0, 0, 5]);
console.info(buf.readInt32BE(0).toString());
// 输出结果：5
```

### readInt32LE

readInt32LE(offset?: number): number

从指定的`offset`处读取有符号的小端序32位整数。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。取值范围：0 <= offset <= this.length - 4，默认值：0。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 |  The value of "offset" is out of range. It must be >= 0 and <= buf.length - 4. Received value is: [offset]. |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from([0, 0, 0, 5]);
console.info(buf.readInt32LE(0).toString());
// 输出结果：83886080
```

### readIntBE

readIntBE(offset: number, byteLength: number): number

从指定的`offset`处读取byteLength个字节，并将结果解释为支持最高48位精度的大端序、二进制补码有符号值。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 是 | 偏移量。取值范围：0 <= offset <= this.length - byteLength，默认值：0。 |
| byteLength | number | 是 | 读取的字节数。取值范围：1 <= byteLength <= 6。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from('ab');
let num = buf.readIntBE(0, 1);
console.info(num.toString());
// 输出结果：97
```


### readIntLE

readIntLE(offset: number, byteLength: number): number

从指定的`offset`处读取`byteLength`个字节，并将结果解释为支持最高48位精度的小端序、二进制补码有符号值。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 是 | 偏移量。取值范围：0 <= offset <= this.length - byteLength，默认值：0。 |
| byteLength | number | 是 | 读取的字节数。取值范围：1 <= byteLength <= 6。|


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from([0x12, 0x34, 0x56, 0x78, 0x90, 0xab]);
console.info(buf.readIntLE(0, 6).toString(16));
// 输出结果：-546f87a9cbee
```

### readUInt8

readUInt8(offset?: number): number

从指定的`offset`处读取8位无符号整型数。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。取值范围：0 <= offset <= this.length - 1，默认值：0。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 1. Received value is: [offset]. |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from([1, -2]);
console.info(buf.readUInt8(0).toString());
// 输出结果：1
console.info(buf.readUInt8(1).toString());
// 输出结果：254
```

### readUInt16BE

readUInt16BE(offset?: number): number

从指定的`offset`处读取无符号的大端序16位整数。

**系统能力：** SystemCapability.Utils.Lang

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。取值范围：0 <= offset <= this.length - 2，默认值：0。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 2. Received value is: [offset]. |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from([0x12, 0x34, 0x56]);
console.info(buf.readUInt16BE(0).toString(16));
// 输出结果：1234
console.info(buf.readUInt16BE(1).toString(16));
// 输出结果：3456
```

### readUInt16LE

readUInt16LE(offset?: number): number

从指定的`offset`处读取无符号的小端序16位整数。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。取值范围：0 <= offset <= this.length - 2，默认值：0。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 2. Received value is: [offset]. |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from([0x12, 0x34, 0x56]);
console.info(buf.readUInt16LE(0).toString(16));
// 输出结果：3412
console.info(buf.readUInt16LE(1).toString(16));
// 输出结果：5634
```

### readUInt32BE

readUInt32BE(offset?: number): number

从指定的`offset`处读取无符号的大端序32位整数。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。取值范围：0 <= offset <= this.length - 4，默认值：0。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 4. Received value is: [offset]. |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from([0x12, 0x34, 0x56, 0x78]);
console.info(buf.readUInt32BE(0).toString(16));
// 输出结果：12345678
```

### readUInt32LE

readUInt32LE(offset?: number): number

从指定的`offset`处读取无符号的小端序32位整数。

**系统能力：** SystemCapability.Utils.Lang

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 否 | 偏移量。取值范围：0 <= offset <= this.length - 4，默认值：0。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 4. Received value is: [offset]. |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from([0x12, 0x34, 0x56, 0x78]);
console.info(buf.readUInt32LE(0).toString(16));
// 输出结果：78563412
```

### readUIntBE

readUIntBE(offset: number, byteLength: number): number

从指定的`offset`处读取`byteLength`个字节，并将结果解释为支持最高48位精度的无符号大端序整数。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 是 | 偏移量。取值范围：0 <= offset <= this.length - byteLength。 |
| byteLength | number | 是 | 要读取的字节数。取值范围：1 <= byteLength <= 6。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。当offset为小数时，返回undefined。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from([0x12, 0x34, 0x56, 0x78, 0x90, 0xab]);
console.info(buf.readUIntBE(0, 6).toString(16));
// 输出结果：1234567890ab
```

### readUIntLE

readUIntLE(offset: number, byteLength: number): number

从指定的`offset`处读取`byteLength`个字节，并将结果解释为支持最高48位精度的无符号小端序整数。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number | 是 | 偏移量。取值范围：0 <= offset <= this.length - byteLength。 |
| byteLength | number | 是 | 读取的字节数。取值范围：1 <= byteLength <= 6。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 读取出的内容。当offset为小数时，返回undefined。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.from([0x12, 0x34, 0x56, 0x78, 0x90, 0xab]);
console.info(buf.readUIntLE(0, 6).toString(16));
// 输出结果：ab9078563412
```

### subarray

subarray(start?: number, end?: number): FastBuffer

截取当前对象指定位置的数据并返回。返回的FastBuffer对象与原对象共享同一内存区域，修改任一对象的数据都会影响另一个。

**系统能力：** SystemCapability.Utils.Lang

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| start | number | 否 | 截取开始位置。默认值：0。 |
| end | number | 否 |  截取结束位置（不包含结束位置）。默认值：当前对象的字节长度。取值范围：start <= end <= this.length。传入null时返回长度为0的FastBuffer对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| FastBuffer | 返回新的FastBuffer对象。|

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf1 = fastbuffer.allocUninitializedFromPool(26);

for (let i = 0; i < 26; i++) {
  buf1.writeInt8(i + 97, i);
}
const buf2 = buf1.subarray(0, 3);
console.info(buf2.toString('ascii', 0, buf2.length));
// 输出结果: abc
```

### swap16

swap16(): FastBuffer

以16位无符号整数为单位交换当前对象的字节顺序。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| FastBuffer | 交换之后的FastBuffer对象。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200009 | The fastbuffer size must be a multiple of 16-bits. |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf1 = fastbuffer.from([0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8]);
console.info(buf1.toString('hex'));
// 输出结果：0102030405060708
buf1.swap16();
console.info(buf1.toString('hex'));
// 输出结果：0201040306050807
```

### swap32

swap32(): FastBuffer

将当前对象转换为无符号的32位整数数组，并交换字节顺序。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| FastBuffer | 交换之后的FastBuffer对象。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200009 | The fastbuffer size must be a multiple of 32-bits. |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf1 = fastbuffer.from([0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8]);
console.info(buf1.toString('hex'));
// 输出结果：0102030405060708
buf1.swap32();
console.info(buf1.toString('hex'));
// 输出结果：0403020108070605
```

### swap64

swap64(): FastBuffer

将当前对象转换为无符号的64位整数数组，并交换字节顺序。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| FastBuffer | 交换之后的FastBuffer对象。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200009 | The fastbuffer size must be a multiple of 64-bits. |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf1 = fastbuffer.from([0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8]);
console.info(buf1.toString('hex'));
// 输出结果：0102030405060708
buf1.swap64();
console.info(buf1.toString('hex'));
// 输出结果：0807060504030201
```

### toJSON

toJSON(): Object

将FastBuffer转为JSON并返回。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Object | JSON对象。 |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf1 = fastbuffer.from([0x1, 0x2, 0x3, 0x4, 0x5]);
let jsonResult = buf1.toJSON();
console.info(JSON.stringify(jsonResult));
// 输出结果: {"type":"FastBuffer","data":[1,2,3,4,5]}
```

### toString

toString(encoding?: string, start?: number, end?: number): string

将当前对象中指定位置的数据转成指定编码格式的字符串并返回。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| encoding | string | 否 | 字符编码格式，支持的格式范围参考[BufferEncoding](#bufferencoding)。默认值：'utf8'。 |
| start  | number | 否 |  开始位置。默认值：0。 |
| end  | number | 否 |  结束位置。默认值：this.length。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 字符串。当start >= this.length或start > end时返回空字符串。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200068 | The underlying ArrayBuffer is null or detach. |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf1 = fastbuffer.allocUninitializedFromPool(26);
for (let i = 0; i < 26; i++) {
  buf1.writeInt8(i + 97, i);
}
console.info(buf1.toString('utf-8'));
// 输出结果: abcdefghijklmnopqrstuvwxyz
```

### write

write(str: string, offset?: number, length?: number, encoding?: string): number

在FastBuffer对象的offset偏移处写入指定编码的字符串，最大写入字节长度为length，实际写入字节数取决于字符串编码后的字节数。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| str | string | 是 | 要写入FastBuffer的字符串。 |
| offset | number | 否 | 偏移量。默认值：0。 |
| length | number | 否 | 最大字节长度。默认值：(this.length - offset)。|
| encoding | string | 否 | 字符编码格式，支持的格式范围参考[BufferEncoding](#bufferencoding)。默认值：'utf8'。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | Range error. Possible causes: The value of the parameter is not within the specified range. |
| 10200068 | The underlying ArrayBuffer is null or detach. |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.alloc(256);
let bytesWritten = buf.write('\u00bd + \u00bc = \u00be', 0);
console.info(`${bytesWritten} bytes: ${buf.toString('utf-8', 0, bytesWritten)}`);
// 输出结果: 12 bytes: ½ + ¼ = ¾

let buf1 = fastbuffer.alloc(10);
let length = buf1.write('abcd', 8);
console.info('length = ' + length);
// 输出结果：length = 2
```

### writeBigInt64BE

writeBigInt64BE(value: bigint, offset?: number): number

在FastBuffer对象的offset偏移处写入有符号的大端序64位BigInt型数据。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | bigint | 是 | 写入FastBuffer的数据。取值范围：-INT64_MAX <= value <= INT64_MAX。|
| offset | number | 否 | 偏移量。默认值：0。取值范围：0 <= offset <= this.length - 8。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 偏移量offset加上写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(8);
let result = buf.writeBigInt64BE(BigInt(0x0102030405060708), 0);
console.info('result = ' + result);
// 输出结果：result = 8
```

### writeBigInt64LE

writeBigInt64LE(value: bigint, offset?: number): number

在FastBuffer对象的offset偏移处写入有符号的小端序64位BigInt型数据。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | bigint | 是 | 写入FastBuffer的数据。取值范围：-INT64_MAX <= value <= INT64_MAX。|
| offset | number | 否 | 偏移量。默认值：0。取值范围：0 <= offset <= this.length - 8。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 偏移量offset加上写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(8);
let result = buf.writeBigInt64LE(BigInt(0x0102030405060708), 0);
console.info('result = ' + result);
// 输出结果：result = 8
```

### writeBigUInt64BE

writeBigUInt64BE(value: bigint, offset?: number): number

在FastBuffer对象的offset偏移处写入无符号的大端序64位BigUInt型数据。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | bigint | 是 | 写入FastBuffer的数据。取值范围：0 <= value <= UINT64_MAX。|
| offset | number | 否 | 偏移量。默认值：0。取值范围：0 <= offset <= this.length - 8。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 偏移量offset加上写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(8);
let result = buf.writeBigUInt64BE(BigInt(0xdecafafecacefade), 0);
console.info('result = ' + result);
// 输出结果：result = 8
```

### writeBigUInt64LE

writeBigUInt64LE(value: bigint, offset?: number): number

在FastBuffer对象的offset偏移处写入无符号的小端序64位BigUInt型数据。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | bigint | 是 | 写入FastBuffer的数据。取值范围：0 <= value <= UINT64_MAX。 |
| offset | number | 否 | 偏移量。默认值：0。取值范围：0 <= offset <= this.length - 8。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 偏移量offset加上写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(8);
let result = buf.writeBigUInt64LE(BigInt(0xdecafafecacefade), 0);
console.info('result = ' + result);
// 输出结果：result = 8
```

### writeDoubleBE

writeDoubleBE(value: number, offset?: number): number

在FastBuffer对象的offset偏移处写入大端序的64位双浮点型数据。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入FastBuffer的数据。取值范围：-DOUBLE_MAX <= value <= DOUBLE_MAX。|
| offset | number | 否 | 偏移量。默认值：0。取值范围：0 <= offset <= this.length - 8。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 偏移量offset加上写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 8. Received value is: [offset] |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(8);
let result = buf.writeDoubleBE(123.456, 0);
console.info('result = ' + result);
// 输出结果：result = 8
```

### writeDoubleLE

writeDoubleLE(value: number, offset?: number): number

在FastBuffer对象的offset偏移处写入小端序的64位双浮点型数据。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入FastBuffer的数据。取值范围：-DOUBLE_MAX <= value <= DOUBLE_MAX。|
| offset | number | 否 | 偏移量。默认值：0。取值范围：0 <= offset <= this.length - 8。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 偏移量offset加上写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 8. Received value is: [offset] |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(8);
let result = buf.writeDoubleLE(123.456, 0);
console.info('result = ' + result);
// 输出结果：result = 8
```

### writeFloatBE

writeFloatBE(value: number, offset?: number): number

在FastBuffer对象的offset偏移处写入大端序的32位浮点型数据。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入FastBuffer的数据。取值范围：-FLOAT_MAX <= value <= FLOAT_MAX。|
| offset | number | 否 | 偏移量。默认值：0。取值范围：0 <= offset <= this.length - 4。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 偏移量offset加上写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 4. Received value is: [offset] |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(8);
let result = buf.writeFloatBE(3.1415, 0);
console.info('result = ' + result);
// 输出结果：result = 4
```


### writeFloatLE

writeFloatLE(value: number, offset?: number): number

在FastBuffer对象的offset偏移处写入小端序的32位浮点型数据。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入FastBuffer的数据。取值范围：-FLOAT_MAX <= value <= FLOAT_MAX。 |
| offset | number | 否 | 偏移量。默认值：0。取值范围：0 <= offset <= this.length - 4。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 偏移量offset加上写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 4. Received value is: [offset] |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(8);
let result = buf.writeFloatLE(3.1415, 0);
console.info('result = ' + result);
// 输出结果：result = 4
```

### writeInt8

writeInt8(value: number, offset?: number): number

在FastBuffer对象的offset偏移处写入8位有符号整型数据。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入FastBuffer的数据。取值范围：-INT8_MAX <= value <= INT8_MAX。 |
| offset | number | 否 | 偏移量。默认值：0。取值范围：0 <= offset <= this.length - 1。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 偏移量offset加上写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(2);
let result = buf.writeInt8(2, 0);
console.info('result = ' + result);
// 输出结果：result = 1
let result1 = buf.writeInt8(-2, 1);
console.info('result1 = ' + result1);
// 输出结果：result1 = 2
```


### writeInt16BE

writeInt16BE(value: number, offset?: number): number

在FastBuffer对象的offset偏移处写入大端序的16位有符号整型数据。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入FastBuffer的数据。取值范围：-INT16_MAX <= value <= INT16_MAX。 |
| offset | number | 否 | 偏移量。默认值：0。取值范围：0 <= offset <= this.length - 2。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 偏移量offset加上写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(2);
let result = buf.writeInt16BE(0x0102, 0);
console.info('result = ' + result);
// 输出结果：result = 2
```


### writeInt16LE

writeInt16LE(value: number, offset?: number): number

在FastBuffer对象的offset偏移处写入小端序的16位有符号整型数据。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入FastBuffer的数据。取值范围：-INT16_MAX <= value <= INT16_MAX。 |
| offset | number | 否 | 偏移量。默认值：0。取值范围：0 <= offset <= this.length - 2。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 偏移量offset加上写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(2);
let result = buf.writeInt16LE(0x0304, 0);
console.info('result = ' + result);
// 输出结果：result = 2
```

### writeInt32BE

writeInt32BE(value: number, offset?: number): number

在FastBuffer对象的offset偏移处写入大端序的32位有符号整型数据。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入FastBuffer的数据。取值范围：-INT32_MAX <= value <= INT32_MAX。 |
| offset | number | 否 | 偏移量。默认值：0。取值范围：0 <= offset <= this.length - 4。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 偏移量offset加上写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(4);
let result = buf.writeInt32BE(0x01020304, 0);
console.info('result = ' + result);
// 输出结果：result = 4
```


### writeInt32LE

writeInt32LE(value: number, offset?: number): number

在FastBuffer对象的offset偏移处写入小端序的32位有符号整型数据。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入FastBuffer的数据。取值范围：-INT32_MAX <= value <= INT32_MAX。 |
| offset | number | 否 | 偏移量。默认值：0。取值范围：0 <= offset <= this.length - 4。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 偏移量offset加上写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(4);
let result = buf.writeInt32LE(0x05060708, 0);
console.info('result = ' + result);
// 输出结果：result = 4
```

### writeIntBE

writeIntBE(value: number, offset: number, byteLength: number): number

在FastBuffer对象的offset偏移处写入大端序的有符号数据，字节长度为byteLength。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入FastBuffer的数据。取值范围：-2^(8×byteLength-1) ≤ value ≤ 2^(8×byteLength-1)-1。 |
| offset | number | 是 | 偏移量。默认值：0。取值范围：0 <= offset <= this.length - byteLength。传入null或undefined时偏移量为0。 |
| byteLength | number | 是 | 要写入的字节数。取值范围：1 <= byteLength <= 6。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 偏移量offset加上写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(6);
let result = buf.writeIntBE(0x1234567890ab, 0, 6);
console.info('result = ' + result);
// 输出结果：result = 6
```


### writeIntLE

writeIntLE(value: number, offset: number, byteLength: number): number

在FastBuffer对象的offset偏移处写入小端序的有符号数据，字节长度为byteLength。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入FastBuffer的数据。取值范围：-2^(8×byteLength-1) ≤ value ≤ 2^(8×byteLength-1)-1。 |
| offset | number | 是 | 偏移量。默认值：0。取值范围：0 <= offset <= this.length - byteLength。传入null或undefined时偏移量为0。 |
| byteLength | number | 是 | 要写入的字节数。取值范围：1 <= byteLength <= 6。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 偏移量offset加上写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(6);
let result = buf.writeIntLE(0x1234567890ab, 0, 6);
console.info('result = ' + result);
// 输出结果：result = 6
```

### writeUInt8

writeUInt8(value: number, offset?: number): number

在FastBuffer对象的offset偏移处写入8位无符号整型数据。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入FastBuffer的数据。取值范围：0 <= value <= UINT8_MAX。 |
| offset | number | 否 | 偏移量。默认值：0。取值范围：0 <= offset <= this.length - 1。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 偏移量offset加上写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(4);
let result = buf.writeUInt8(0x3, 0);
console.info('result = ' + result);
// 输出结果：result = 1
let result1 = buf.writeUInt8(0x4, 1);
console.info('result1 = ' + result1);
// 输出结果：result1 = 2
let result2 = buf.writeUInt8(0x23, 2);
console.info('result2 = ' + result2);
// 输出结果：result2 = 3
let result3 = buf.writeUInt8(0x42, 3);
console.info('result3 = ' + result3);
// 输出结果：result3 = 4
```

### writeUInt16BE

writeUInt16BE(value: number, offset?: number): number

在FastBuffer对象的offset偏移处写入大端序的16位无符号整型数据。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入FastBuffer的数据。取值范围：0 <= value <= UINT16_MAX。 |
| offset | number | 否 | 偏移量。默认值：0。取值范围：0 <= offset <= this.length - 2。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 偏移量offset加上写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(4);
let result = buf.writeUInt16BE(0xdead, 0);
console.info('result = ' + result);
// 输出结果：result = 2
let result1 = buf.writeUInt16BE(0xbeef, 2);
console.info('result1 = ' + result1);
// 输出结果：result1 = 4
```

### writeUInt16LE

writeUInt16LE(value: number, offset?: number): number

在FastBuffer对象的offset偏移处写入小端序的16位无符号整型数据。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入FastBuffer的数据。取值范围：0 <= value <= UINT16_MAX。 |
| offset | number | 否 | 偏移量。默认值：0。取值范围：0 <= offset <= this.length - 2。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 偏移量offset加上写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(4);
let result = buf.writeUInt16LE(0xdead, 0);
console.info('result = ' + result);
// 输出结果：result = 2
let result1 = buf.writeUInt16LE(0xbeef, 2);
console.info('result1 = ' + result1);
// 输出结果：result1 = 4
```

### writeUInt32BE

writeUInt32BE(value: number, offset?: number): number

在FastBuffer对象的offset偏移处写入大端序的32位无符号整型数据。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入FastBuffer的数据。取值范围：0 <= value <= UINT32_MAX。 |
| offset | number | 否 | 偏移量。默认值：0。取值范围：0 <= offset <= this.length - 4。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 偏移量offset加上写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(4);
let result = buf.writeUInt32BE(0xfeedface, 0);
console.info('result = ' + result);
// 输出结果：result = 4
```

### writeUInt32LE

writeUInt32LE(value: number, offset?: number): number

在FastBuffer对象的offset偏移处写入小端序的32位无符号整型数据。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入FastBuffer的数据。取值范围：0 <= value <= UINT32_MAX。 |
| offset | number | 否 | 偏移量。默认值：0。取值范围：0 <= offset <= this.length - 4。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 偏移量offset加上写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(4);
let result = buf.writeUInt32LE(0xfeedface, 0);
console.info('result = ' + result);
// 输出结果：result = 4
```

### writeUIntBE

writeUIntBE(value: number, offset: number, byteLength: number): number

在FastBuffer对象的offset偏移处写入大端序的无符号数据，字节长度为byteLength。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入FastBuffer的数据。取值范围：0 ≤ value ≤ 2^(8×byteLength)-1。 |
| offset | number | 是 | 偏移量。默认值：0。取值范围：0 <= offset <= this.length - byteLength。传入null或undefined时偏移量为0。 |
| byteLength | number | 是 | 要写入的字节数。取值范围：1 <= byteLength <= 6。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 偏移量offset加上写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(6);
let result = buf.writeUIntBE(0x1234567890ab, 0, 6);
console.info('result = ' + result);
// 输出结果：result = 6
```

### writeUIntLE

writeUIntLE(value: number, offset: number, byteLength: number): number

在FastBuffer对象的offset偏移处写入小端序的无符号数据，字节长度为byteLength。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 写入FastBuffer的数据。取值范围：0 ≤ value ≤ 2^(8×byteLength)-1。 |
| offset | number | 是 | 偏移量。默认值：0。取值范围：0 <= offset <= this.length - byteLength。传入null或undefined时偏移量为0。 |
| byteLength | number | 是 | 要写入的字节数。取值范围：1 <= byteLength <= 6。 |


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 偏移量offset加上写入的字节数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |

**示例：**

```ts
import { fastbuffer } from '@kit.ArkTS';

let buf = fastbuffer.allocUninitializedFromPool(6);
let result = buf.writeUIntLE(0x1234567890ab, 0, 6);
console.info('result = ' + result);
// 输出结果：result = 6
```
