# @ohos.buffer    
Buffer对象用于表示固定长度的字节序列，是专门存放二进制数据的缓存区。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import buffer from '@ohos.buffer'    
```  
    
## BufferEncoding    
表示支持的编码格式类型。  
 **系统能力:**  SystemCapability.Utils.Lang    
    
| 取值范围 | 说明 |  
| --------| --------|  
| ascii | 表示ascii格式。 |  
| utf8 | 表示utf8格式。 |  
| utf-8 | 表示utf8格式。 |  
| utf16le | 表示utf16小端序格式。 |  
| ucs2 | utf16le的别名。 |  
| ucs-2 | utf16le的别名。 |  
| base64 | 表示base64格式。 |  
| base64url | 表示base64url格式。 |  
| latin1 | 表示ascii格式。 |  
| binary | 表示二进制格式。 |  
| hex | 表示十六进制格式。 |  
    
## TypedArray  
 **系统能力:**  SystemCapability.Utils.Lang    
## alloc    
创建一定字节长度的Buffer对象，并初始化。  
 **调用形式：**     
- alloc(size: number, fill?: string | Buffer | number, encoding?: BufferEncoding): Buffer  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| size | number | true | 指定的Buffer对象长度，单位：字节。 |  
| fill | string | false | 填充至新缓存区的值，默认值: 0。 |  
| encoding | BufferEncoding | false | 编码格式（当`fill`为string时，才有意义）。 默认值: 'utf-8'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Buffer | 返回一个Buffer对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf1 = buffer.alloc(5);  
let buf2 = buffer.alloc(5, 'a');  
let buf3 = buffer.alloc(11, 'aGVsbG8gd29ybGQ=', 'base64');    
```    
  
    
## allocUninitializedFromPool    
创建指定大小未被初始化的Buffer对象。内存从缓冲池分配。创建的Buffer的内容未知，需要使用[fill](#fill)函数来初始化Buffer对象。  
 **调用形式：**     
- allocUninitializedFromPool(size: number): Buffer  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| size | number | true | 指定的Buffer对象长度，单位：字节。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Buffer | 未初始化的Buffer实例。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.allocUninitializedFromPool(10);  
buf.fill(0);    
```    
  
    
## allocUninitialized    
创建指定大小未被初始化的Buffer实例。内存不从缓冲池分配。创建的Buffer的内容未知，需要使用[fill](#fill)函数来初始化Buffer对象。  
 **调用形式：**     
- allocUninitialized(size: number): Buffer  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| size | number | true | 指定的Buffer对象长度，单位：字节。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Buffer | 未初始化的Buffer实例。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.allocUninitialized(10);  
buf.fill(0);    
```    
  
    
## byteLength    
根据不同的编码方法，返回指定字符串的字节数。  
 **调用形式：**     
- byteLength(     string: string | Buffer | TypedArray | DataView | ArrayBuffer | SharedArrayBuffer,     encoding?: BufferEncoding   ): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| string | string | true | 指定字符串。 |  
| encoding | BufferEncoding | false | 编码格式。 默认值: 'utf-8'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回指定字符串的字节数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import buffer from '@ohos.buffer';  
let str = '\u00bd + \u00bc = \u00be';console.log(`${str}: ${str.length} characters, ${buffer.byteLength(str, 'utf-8')} bytes`);// 打印: ½ + ¼ = ¾: 9 characters, 12 bytes    
```    
  
    
## concat    
将数组中的内容复制指定字节长度到新的Buffer对象中并返回。  
 **调用形式：**     
- concat(list: Buffer[] | Uint8Array[], totalLength?: number): Buffer  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| list | string | true | 实例数组。 |  
| totalLength | number | false | 需要复制的总字节长度，默认值为0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Buffer | 返回新的Buffer对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "length" is out of range. It must be >= 0 and <= uint32 max. Received value is: [length] |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf1 = buffer.from("1234");  
let buf2 = buffer.from("abcd");  
let buf = buffer.concat([buf1, buf2]);  
console.log(buf.toString('hex')); // 3132333461626364    
```    
  
    
## from    
根据指定数组创建新的Buffer对象。  
 **调用形式：**     
- from(array: number[]): Buffer  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| array | number[] | true | 指定数组。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Buffer | 新的Buffer对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
<span style="font-family: monospace, monospace; font-size: 1em; letter-spacing: 0px;">import buffer from '@ohos.buffer';</span>  
let buf = buffer.from([0x62, 0x75, 0x66, 0x66, 0x65, 0x72]);  
console.log(buf.toString('hex')); // 627566666572    
```    
  
    
## from    
创建指定长度的与`arrayBuffer`共享内存的Buffer对象。  
 **调用形式：**     
- from(arrayBuffer: ArrayBuffer | SharedArrayBuffer, byteOffset?: number, length?: number): Buffer  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| arrayBuffer | string | true | 实例对象。 |  
| byteOffset | number | false | 字节偏移量，默认值: 0。 |  
| length | number | false | 字节长度， 默认值: (arrayBuffer.byteLength - byteOffset)。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Buffer | 返回一个共享内存的Buffer对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "[byteOffset/length]" is out of range. |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let ab = new ArrayBuffer(10);  
let buf = buffer.from(ab, 0, 2);    
```    
  
    
## from    
创建并复制`buffer`数据到新的Buffer对象并返回。  
 **调用形式：**     
- from(buffer: Buffer | Uint8Array): Buffer  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| buffer | string | true | 对象数据。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Buffer | 新的Buffer对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf1 = buffer.from('buffer');  
let buf2 = buffer.from(buf1);    
```    
  
    
## from    
根据指定的`object`类型数据，创建新的Buffer对象。  
 **调用形式：**     
- from(object: Object, offsetOrEncoding: number | string, length: number): Buffer  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| object | Object | true | 支持Symbol.toPrimitive或valueOf()的对象。 |  
| offsetOrEncoding | string | true | 字节偏移量或编码格式。 |  
| length | number | true | 字节长度。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Buffer | 返回新的Buffer对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.from(new String('this is a test'), 'utf8', 14);    
```    
  
    
## from    
根据指定编码格式的字符串，创建新的Buffer对象。  
 **调用形式：**     
- from(string: String, encoding?: BufferEncoding): Buffer  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| string | String | true | 字符串 |  
| encoding | BufferEncoding | false | 编码格式。 默认值: 'utf-8'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Buffer | 返回新的Buffer对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf1 = buffer.from('this is a test');  
let buf2 = buffer.from('7468697320697320612074c3a97374', 'hex');  
  
console.log(buf1.toString());	// 打印: this is a test  
console.log(buf2.toString()); // 打印: this is a test    
```    
  
    
## isBuffer    
判断`obj`是否为Buffer。  
 **调用形式：**     
- isBuffer(obj: Object): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| obj | Object | true | 判断对象 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 如果obj是Buffer，则返回true，否则返回false。 |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let result = buffer.isBuffer(buffer.alloc(10)); // true  
let result1 = buffer.isBuffer(buffer.from('foo')); // true  
let result2 = buffer.isBuffer('a string'); // false  
let result3 = buffer.isBuffer([]); // false  
let result4 = buffer.isBuffer(new Uint8Array(1024)); // false    
```    
  
    
## isEncoding    
判断`encoding`是否为支持的编码格式。  
 **调用形式：**     
- isEncoding(encoding: string): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| encoding | string | true | 编码格式。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 是支持的编码格式返回true，反之则返回false。 |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
console.log(buffer.isEncoding('utf-8').toString());	// 打印: true  
console.log(buffer.isEncoding('hex').toString());	// 打印: true  
console.log(buffer.isEncoding('utf/8').toString());	// 打印: false  
console.log(buffer.isEncoding('').toString());	// 打印: false    
```    
  
    
## compare    
返回两个数组的比较结果，通常用于对Buffer对象数组进行排序。  
 **调用形式：**     
- compare(buf1: Buffer | Uint8Array, buf2: Buffer | Uint8Array): -1 | 0 | 1  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| buf1 | string | true | 待比较数组。 |  
| buf2 | string | true | 待比较数组。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| -1 | 0 | 1 | 如果buf1与buf2相同，则返回0。<br/>如果排序时buf1位于buf2之后，则返回1。<br/>如果排序时buf1位于buf2之前，则返回-1。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf1 = buffer.from('1234');  
let buf2 = buffer.from('0123');  
let res = buf1.compare(buf2);  
  
console.log(Number(res).toString()); // 打印 1    
```    
  
    
## transcode    
将给定的Buffer或Uint8Array对象从一种字符编码重新编码为另一种。  
 **调用形式：**     
- transcode(source: Buffer | Uint8Array, fromEnc: string, toEnc: string): Buffer  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| source | string | true | 实例对象。 |  
| fromEnc | string | true | 当前编码。 |  
| toEnc | string | true | 目标编码。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Buffer | 根据当前编码转换成目标编码，并返回一个新的buffer实例。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.alloc(50);  
let newBuf = buffer.transcode(buffer.from('€'), 'utf-8', 'ascii');  
console.log(newBuf.toString('ascii'));    
```    
  
    
## Buffer  
 **系统能力:**  SystemCapability.Utils.Lang    
### 属性    
 **系统能力:**  SystemCapability.Utils.Lang    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| length | number | false | true | Buffer对象的字节长度。 |  
| buffer | ArrayBuffer | false | true | ArrayBuffer对象。 |  
| byteOffset | number | false | true | 当前Buffer所在内存池的偏移量。 |  
    
### fill    
用`value`填充当前对象指定位置的数据，默认为循环填充，并返回填充后的Buffer对象。  
 **调用形式：**     
- fill(       value: string | Buffer | Uint8Array | number,       offset?: number,       end?: number,       encoding?: BufferEncoding     ): Buffer  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | string | true | 用于填充的值。 |  
| offset | number | false | 起始偏移量。 默认值: 0。 |  
| end | number | false | 结束偏移量（不包含结束位置）。 默认值: 当前对象的字节长度。 |  
| encoding | BufferEncoding | false | 字符编码格式（`value`为string才有意义）。 默认值: 'utf-8'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Buffer | 返回一个填充后的Buffer对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200001 |  |  
| 401 |  |  
    
 **示例代码：**   
```js    
import buffer from '@ohos.buffer';  
let b = buffer.allocUninitializedFromPool(50).fill('h');console.log(b.toString());    
```    
  
    
### compare    
返回两个数组的比较结果，通常用于对Buffer对象数组进行排序。  
 **调用形式：**     
- compare(       target: Buffer | Uint8Array,       targetStart?: number,       targetEnd?: number,       sourceStart?: number,       sourceEnd?: number     ): -1 | 0 | 1  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| target | string | true | 要比较的实例对象。 |  
| targetStart | number | false | `target`实例中开始的偏移量。 默认值: 0。 |  
| targetEnd | number | false | `target`实例中结束的偏移量（不包含结束位置）。 默认值: 目标对象的字节长度。 |  
| sourceStart | number | false | `this`实例中开始的偏移量。 默认值: 0。 |  
| sourceEnd | number | false | `this`实例中结束的偏移量（不包含结束位置）。 默认值: 当前对象的字节长度。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| -1 | 0 | 1 |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 |  |  
    
 **示例代码：**   
```js    
import buffer from '@ohos.buffer';  
let buf1 = buffer.from([1, 2, 3, 4, 5, 6, 7, 8, 9]);let buf2 = buffer.from([5, 6, 7, 8, 9, 1, 2, 3, 4]);  
console.log(buf1.compare(buf2, 5, 9, 0, 4).toString());// 打印: 0console.log(buf1.compare(buf2, 0, 6, 4).toString());// 打印: -1console.log(buf1.compare(buf2, 5, 6, 5).toString());// 打印: 1    
```    
  
    
### copy    
将`this`实例中指定位置的数据复制到`target`的指定位置上，并返回复制的字节总长度。  
 **调用形式：**     
- copy(target: Buffer | Uint8Array, targetStart?: number, sourceStart?: number, sourceEnd?: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| target | string | true | 要复制到的Buffer或Uint8Array实例。 |  
| targetStart | number | false | `target`实例中开始写入的偏移量。 默认值: 0。 |  
| sourceStart | number | false | `this`实例中开始复制的偏移量。 默认值: 0。 |  
| sourceEnd | number | false | `this`实例中结束复制的偏移量（不包含结束位置）。 默认值: 当前对象的字节长度。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 复制的字节总长度。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "[targetStart/sourceStart/sourceEnd]" is out of range. |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf1 = buffer.allocUninitializedFromPool(26);  
let buf2 = buffer.allocUninitializedFromPool(26).fill('!');  
  
for (let i = 0; i < 26; i++) {  
  buf1.writeInt8(i + 97, i);  
}  
  
buf1.copy(buf2, 8, 16, 20);  
console.log(buf2.toString('ascii', 0, 25));  
// 打印: !!!!!!!!qrst!!!!!!!!!!!!!    
```    
  
    
### equals    
比较`this`实例和otherBuffer实例是否相等。  
 **调用形式：**     
- equals(otherBuffer: Uint8Array | Buffer): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| otherBuffer | string | true | 比较的目标对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 相等则返回true，否则返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf1 = buffer.from('ABC');  
let buf2 = buffer.from('414243', 'hex');  
let buf3 = buffer.from('ABCD');  
  
console.log(buf1.equals(buf2).toString());	// 打印: true  
console.log(buf1.equals(buf3).toString());	// 打印: false    
```    
  
    
### includes    
检查Buffer对象是否包含`value`值。  
 **调用形式：**     
- includes(value: string | number | Buffer | Uint8Array, byteOffset?: number, encoding?: BufferEncoding): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | string | true | 要搜索的内容。 |  
| byteOffset | number | false | 字节偏移量。 如果为负数，则从末尾开始计算偏移量。 默认值: 0。 |  
| encoding | BufferEncoding | false | 字符编码格式。 默认值: 'utf-8'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 存在为true，否则为false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.from('this is a buffer');  
console.log(buf.includes('this').toString());	// 打印: true  
console.log(buf.includes('be').toString());	// 打印: false    
```    
  
    
### indexOf    
查找当前对象中第一次出现`value`的索引，如果不包含`value`，则为-1。  
 **调用形式：**     
- indexOf(value: string | number | Buffer | Uint8Array, byteOffset?: number, encoding?: BufferEncoding): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | string | true | 要查找的内容。 |  
| byteOffset | number | false | 字节偏移量。 如果为负数，则从末尾开始计算偏移量。 默认值: 0。 |  
| encoding | BufferEncoding | false | 字符编码格式。 默认值: 'utf-8'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 第一次出现位置。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.from('this is a buffer');  
console.log(buf.indexOf('this').toString());	// 打印: 0  
console.log(buf.indexOf('is').toString());		// 打印: 2    
```    
  
    
### keys    
返回一个包含key值的迭代器。  
 **调用形式：**     
- keys(): IterableIterator\<number>  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| IterableIterator<number> | 返回一个包含key值的迭代器。 |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.from('buffer');  
let numbers = Array.from(buf.values())  
for (const key of numbers) {  
  console.log(key.toString());  
}    
```    
  
    
### values    
返回一个包含value的迭代器。  
 **调用形式：**     
- values(): IterableIterator\<number>  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| IterableIterator<number> | 迭代器。 |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf1 = buffer.from('buffer');  
let pair = buf1.values()  
let next:IteratorResult<number> = pair.next()  
while (!next.done) {  
  console.log(next.value.toString());  
  next = pair.next()  
}    
```    
  
    
### entries    
返回一个包含key和value的迭代器。  
 **调用形式：**     
- entries(): IterableIterator\<[number, number]>  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| IterableIterator<[number, number]> | 表示迭代器的key值。表示迭代器的value值。 |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.from('buffer');  
let pair = buf.entries()  
let next: IteratorResult<Object[]> = pair.next()  
while (!next.done) {  
  console.info("buffer: " + next.value)  
  next = pair.next()  
}    
```    
  
    
### lastIndexOf    
返回`this`实例中最后一次出现`value`的索引，如果对象不包含，则为-1。  
 **调用形式：**     
- lastIndexOf(value: string | number | Buffer | Uint8Array, byteOffset?: number, encoding?: BufferEncoding): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | string | true | 要搜索的内容。 |  
| byteOffset | number | false | 字节偏移量。 如果为负数，则从末尾开始计算偏移量。 默认值: 0。 |  
| encoding | BufferEncoding | false | 字符编码格式。 默认值: 'utf-8'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 最后一次出现`value`值的索引。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.from('this buffer is a buffer');  
console.log(buf.lastIndexOf('this').toString());	// 打印: 0  
console.log(buf.lastIndexOf('buffer').toString());	// 打印: 17    
```    
  
    
### readBigInt64BE    
从指定的`offset`处读取有符号的大端序64位整数。  
 **调用形式：**     
- readBigInt64BE(offset?: number): bigint  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| offset | number | false | 偏移量。默认值: 0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| bigint | 读取出的内容。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "offset" is out of range. |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.from([0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x70,   
        0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78]);  
console.log(buf.readBigInt64BE(0).toString());  
  
let buf1 = buffer.allocUninitializedFromPool(8);  
let result = buf1.writeBigInt64BE(BigInt(0x0102030405060708), 0);    
```    
  
    
### readBigInt64LE    
从指定的`offset`处读取有符号的小端序64位整数。  
 **调用形式：**     
- readBigInt64LE(offset?: number): bigint  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| offset | number | false | 偏移量。默认值: 0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| bigint | 读取出的内容。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "offset" is out of range. |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.from([0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x70,   
        0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78]);  
console.log(buf.readBigInt64LE(0).toString());  
  
let buf1 = buffer.allocUninitializedFromPool(8);  
let result = buf1.writeBigInt64BE(BigInt(0x0102030405060708), 0);    
```    
  
    
### readBigUInt64BE    
从指定的`offset`处读取无符号的大端序64位整数。  
 **调用形式：**     
- readBigUInt64BE(offset?: number): bigint  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| offset | number | false | 偏移量。默认值: 0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| bigint | 读取出的内容。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "offset" is out of range. |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.from([0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x70,   
        0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78]);  
console.log(buf.readBigUInt64BE(0).toString());  
  
let buf1 = buffer.allocUninitializedFromPool(8);  
let result = buf1.writeBigUInt64BE(BigInt(0xdecafafecacefade), 0);    
```    
  
    
### readBigUInt64LE    
从指定的`offset`处读取无符号的小端序64位整数。  
 **调用形式：**     
- readBigUInt64LE(offset?: number): bigint  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| offset | number | false | 偏移量。默认值: 0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| bigint | 读取出的内容。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "offset" is out of range. |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.from([0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x70,   
        0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78]);  
console.log(buf.readBigUInt64LE(0).toString());  
  
let buf1 = buffer.allocUninitializedFromPool(8);  
let result = buf1.writeBigUInt64BE(BigInt(0xdecafafecacefade), 0);    
```    
  
    
### readDoubleBE    
从指定`offset`处读取64位大端序双精度值。  
 **调用形式：**     
- readDoubleBE(offset?: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| offset | number | false | 偏移量。默认值: 0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 读取出的内容。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "offset" is out of range. |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.from([1, 2, 3, 4, 5, 6, 7, 8]);  
console.log(buf.readDoubleBE(0).toString());  
  
let buf1 = buffer.allocUninitializedFromPool(8);  
let result = buf1.writeDoubleBE(123.456, 0);    
```    
  
    
### readDoubleLE    
从指定`offset`处读取64位小端序双精度值。  
 **调用形式：**     
- readDoubleLE(offset?: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| offset | number | false | 偏移量。默认值: 0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 读取出的内容。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "offset" is out of range. |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.from([1, 2, 3, 4, 5, 6, 7, 8]);  
console.log(buf.readDoubleLE(0).toString());  
  
let buf1 = buffer.allocUninitializedFromPool(8);  
let result = buf1.writeDoubleLE(123.456, 0);    
```    
  
    
### readFloatBE    
从指定`offset`处读取32位大端序浮点数。  
 **调用形式：**     
- readFloatBE(offset?: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| offset | number | false | 偏移量。默认值: 0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 读取出的内容。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "offset" is out of range. |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.from([1, 2, 3, 4, 5, 6, 7, 8]);  
console.log(buf.readFloatBE(0).toString());  
  
let buf1 = buffer.allocUninitializedFromPool(4);  
let result = buf1.writeFloatBE(0xcabcbcbc, 0);    
```    
  
    
### readFloatLE    
从指定`offset`处读取32位小端序浮点数。  
 **调用形式：**     
- readFloatLE(offset?: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| offset | number | false | 偏移量。默认值: 0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 读取出的内容。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "offset" is out of range. |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.from([1, 2, 3, 4, 5, 6, 7, 8]);  
console.log(buf.readFloatLE(0).toString());  
  
let buf1 = buffer.allocUninitializedFromPool(4);  
let result = buf1.writeFloatLE(0xcabcbcbc, 0);    
```    
  
    
### readInt8    
从指定的`offset`处读取有符号的8位整数。  
 **调用形式：**     
- readInt8(offset?: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| offset | number | false | 偏移量。默认值: 0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 读取出的内容。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "offset" is out of range. |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.from([-1, 5]);  
console.log(buf.readInt8(0).toString());	// 打印: -1  
console.log(buf.readInt8(1).toString());	// 打印: 5  
  
let buf1 = buffer.allocUninitializedFromPool(2);  
let result = buf1.writeInt8(0x12);    
```    
  
    
### readInt16BE    
从指定的`offset`处读取有符号的大端序16位整数。  
 **调用形式：**     
- readInt16BE(offset?: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| offset | number | false | 偏移量。默认值: 0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 读取出的内容。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "offset" is out of range. |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.from([0, 5]);  
console.log(buf.readInt16BE(0).toString());	// 打印: 5  
  
let buf1 = buffer.alloc(2);  
let result = buf1.writeInt16BE(0x1234, 0);    
```    
  
    
### readInt16LE    
从指定的`offset`处读取有符号的小端序16位整数。  
 **调用形式：**     
- readInt16LE(offset?: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| offset | number | false | 偏移量。默认值: 0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 读取出的内容。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "offset" is out of range. |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.from([0, 5]);  
console.log(buf.readInt16LE(0).toString());	// 打印: 1280  
  
let buf1 = buffer.alloc(2);  
let result = buf1.writeInt16BE(0x1234, 0);    
```    
  
    
### readInt32BE    
从指定的`offset`处读取有符号的大端序32位整数。  
 **调用形式：**     
- readInt32BE(offset?: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| offset | number | false | 偏移量。默认值: 0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 读取出的内容。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "offset" is out of range. |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.from([0, 0, 0, 5]);  
console.log(buf.readInt32BE(0).toString());	// 打印: 5  
  
let buf1 = buffer.alloc(4);  
let result = buf1.writeInt32BE(0x12345678, 0);    
```    
  
    
### readInt32LE    
从指定的`offset`处读取有符号的小端序32位整数。  
 **调用形式：**     
- readInt32LE(offset?: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| offset | number | false | 偏移量。默认值: 0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 读取出的内容。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "offset" is out of range. |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.from([0, 0, 0, 5]);  
console.log(buf.readInt32LE(0).toString());	// 打印: 83886080  
  
let buf1 = buffer.alloc(4);  
let result = buf1.writeInt32BE(0x12345678, 0);    
```    
  
    
### readIntBE    
从指定的`offset`处的buf读取byteLength个字节，并将结果解释为支持最高48位精度的大端序、二进制补码有符号值。  
 **调用形式：**     
- readIntBE(offset: number, byteLength: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| offset | number | true | 偏移量。 默认值: 0。 |  
| byteLength | number | true | 读取的字节数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 读取的内容。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.from("ab");  
let num = buf.readIntBE(0, 1);  
console.log(num.toString()); // 97  
  
let buf1 = buffer.allocUninitializedFromPool(6);  
let result = buf1.writeIntBE(0x123456789011, 0, 6);    
```    
  
    
### readIntLE    
从指定的`offset`处的buf读取`byteLength`个字节，并将结果解释为支持最高48位精度的小端序、二进制补码有符号值。  
 **调用形式：**     
- readIntLE(offset: number, byteLength: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| offset | number | true | 偏移量。 默认值: 0。 |  
| byteLength | number | true | 读取的字节数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 读取出的内容。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.from([0x12, 0x34, 0x56, 0x78, 0x90, 0xab]);  
console.log(buf.readIntLE(0, 6).toString(16));  
  
let buf1 = buffer.allocUninitializedFromPool(6);  
let result = buf1.writeIntLE(0x123456789011, 0, 6);    
```    
  
    
### readUInt8    
从`offset`处读取8位无符号整型数。  
 **调用形式：**     
- readUInt8(offset?: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| offset | number | false | 偏移量。 默认值: 0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 读取出的内容。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "offset" is out of range. |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.from([1, -2]);  
console.log(buf.readUInt8(0).toString());  
console.log(buf.readUInt8(1).toString());  
  
let buf1 = buffer.allocUninitializedFromPool(4);  
let result = buf1.writeUInt8(0x42);    
```    
  
    
### readUInt16BE    
从指定的`offset`处的buf读取无符号的大端序16位整数。  
 **调用形式：**     
- readUInt16BE(offset?: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| offset | number | false | 偏移量。 默认值: 0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 读取出的内容。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "offset" is out of range. |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.from([0x12, 0x34, 0x56]);  
console.log(buf.readUInt16BE(0).toString(16));  
console.log(buf.readUInt16BE(1).toString(16));  
  
let buf1 = buffer.allocUninitializedFromPool(4);  
let result = buf1.writeUInt16BE(0x1234, 0);    
```    
  
    
### readUInt16LE    
从指定的`offset`处的buf读取无符号的小端序16位整数。  
 **调用形式：**     
- readUInt16LE(offset?: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| offset | number | false | 偏移量。 默认值: 0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 读取出的内容。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "offset" is out of range. |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.from([0x12, 0x34, 0x56]);  
console.log(buf.readUInt16LE(0).toString(16));  
console.log(buf.readUInt16LE(1).toString(16));  
  
let buf1 = buffer.allocUninitializedFromPool(4);  
let result = buf1.writeUInt16LE(0x1234, 0);    
```    
  
    
### readUInt32BE    
从指定的`offset`处的buf读取无符号的大端序32位整数。  
 **调用形式：**     
- readUInt32BE(offset?: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| offset | number | false | 偏移量。 默认值: 0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 读取出的内容。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "offset" is out of range. |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.from([0x12, 0x34, 0x56, 0x78]);  
console.log(buf.readUInt32BE(0).toString(16));  
  
let buf1 = buffer.allocUninitializedFromPool(4);  
let result = buf1.writeUInt32BE(0x12345678, 0);    
```    
  
    
### readUInt32LE    
从指定的`offset`处的buf读取无符号的小端序32位整数。  
 **调用形式：**     
- readUInt32LE(offset?: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| offset | number | false | 偏移量。 默认值: 0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 读取出的内容。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "offset" is out of range. |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.from([0x12, 0x34, 0x56, 0x78]);  
console.log(buf.readUInt32LE(0).toString(16));  
  
let buf1 = buffer.allocUninitializedFromPool(4);  
let result = buf1.writeUInt32LE(0x12345678, 0);    
```    
  
    
### readUIntBE    
从指定的`offset`处的buf读取`byteLength`个字节，并将结果解释为支持最高48位精度的无符号大端序整数。  
 **调用形式：**     
- readUIntBE(offset: number, byteLength: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| offset | number | true | 偏移量。 默认值: 0。 |  
| byteLength | number | true | 要读取的字节数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 读取出的内容。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.from([0x12, 0x34, 0x56, 0x78, 0x90, 0xab]);  
console.log(buf.readUIntBE(0, 6).toString(16));  
  
let buf1 = buffer.allocUninitializedFromPool(4);  
let result = buf1.writeUIntBE(0x13141516, 0, 4);    
```    
  
    
### readUIntLE    
从指定的`offset`处的buf读取`byteLength`个字节，并将结果解释为支持最高48位精度的无符号小端序整数。  
 **调用形式：**     
- readUIntLE(offset: number, byteLength: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| offset | number | true | 偏移量。 默认值: 0。 |  
| byteLength | number | true | 要读取的字节数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 读取出的内容。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.from([0x12, 0x34, 0x56, 0x78, 0x90, 0xab]);  
console.log(buf.readUIntLE(0, 6).toString(16));  
  
let buf1 = buffer.allocUninitializedFromPool(4);  
let result = buf1.writeUIntLE(0x13141516, 0, 4);    
```    
  
    
### subarray    
截取当前对象指定位置的数据并返回。  
 **调用形式：**     
- subarray(start?: number, end?: number): Buffer  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| start | number | false | 截取开始位置。 默认值: 0。 |  
| end | number | false | 截取结束位置（不包含结束位置）。 默认值: 当前对象的字节长度。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Buffer | 返回新的Buffer对象。 |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf1 = buffer.allocUninitializedFromPool(26);  
  
for (let i = 0; i < 26; i++) {  
  buf1.writeInt8(i + 97, i);  
}  
const buf2 = buf1.subarray(0, 3);  
console.log(buf2.toString('ascii', 0, buf2.length));  
// 打印: abc    
```    
  
    
### swap16    
将当前对象解释为无符号的16位整数数组，并交换字节顺序。  
 **调用形式：**     
- swap16(): Buffer  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Buffer | 交换之后的Buffer实例。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200009 | Buffer size must be a multiple of 16-bits |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf1 = buffer.from([0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8]);  
console.log(buf1.toString('hex'));	// 打印: 0102030405060708  
  
buf1.swap16();  
console.log(buf1.toString('hex'));	// 打印: 0201040306050807    
```    
  
    
### swap32    
将当前对象解释为无符号的32位整数数组，并交换字节顺序。  
 **调用形式：**     
- swap32(): Buffer  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Buffer | 交换之后的Buffer对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200009 | Buffer size must be a multiple of 32-bits |  
    
 **示例代码：**   
示例：  
```ts    
<span style="font-family: monospace, monospace; font-size: 1em; letter-spacing: 0px;">import buffer from '@ohos.buffer';</span>let buf1 = buffer.from([0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8]);  
console.log(buf1.toString('hex'));	// 打印: 0102030405060708  
  
buf1.swap32();<span style="font-family: monospace, monospace; font-size: 1em; letter-spacing: 0px;">console.log(buf1.toString('hex'));	// 打印: 0403020108070605</span><i></i><span style="font-size: 14px; letter-spacing: 0px;"></span>  
    
```    
  
    
### swap64    
将当前对象解释为无符号的64位整数数组，并交换字节顺序。  
 **调用形式：**     
- swap64(): Buffer  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Buffer | 交换之后的Buffer对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200009 | Buffer size must be a multiple of 64-bits |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf1 = buffer.from([0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8]);  
console.log(buf1.toString('hex'));	// 打印: 0102030405060708  
buf1.swap64();  
console.log(buf1.toString('hex'));	// 打印: 0807060504030201    
```    
  
    
### toJSON    
将Buffer转为JSON并返回。  
 **调用形式：**     
- toJSON(): Object  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Object | JSON对象。 |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf1 = buffer.from([0x1, 0x2, 0x3, 0x4, 0x5]);  
let obj = buf1.toJSON();  
console.log(JSON.stringify(obj))  
// 打印: {"type":"Buffer","data":[1,2,3,4,5]}    
```    
  
    
### toString    
将当前对象中指定位置数据转成指定编码格式字符串并返回。  
 **调用形式：**     
- toString(encoding?: string, start?: number, end?: number): string  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| encoding | string | false | 字符编码格式。 默认值: 'utf-8'。 |  
| start | number | false | 开始位置。 默认值: 0。 |  
| end | number | false | 结束位置。 默认值: Buffer.length。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 字符串。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf1 = buffer.allocUninitializedFromPool(26);  
for (let i = 0; i < 26; i++) {  
  buf1.writeInt8(i + 97, i);  
}  
console.log(buf1.toString('utf-8'));  
// 打印: abcdefghijklmnopqrstuvwxyz    
```    
  
    
### write    
从Buffer对象的offset偏移写入指定编码的字符串str，写入的字节长度为length。  
 **调用形式：**     
- write(str: string, offset?: number, length?: number, encoding?: string): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| str | string | true | 要写入Buffer的字符串。 |  
| offset | number | false | 偏移量。 默认值: 0。 |  
| length | number | false | 最大字节长度。 默认值: (Buffer.length - offset)。 |  
| encoding | string | false | 字符编码。 默认值: 'utf-8'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回写入的字节数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "[offset/length]" is out of range. |  
    
 **示例代码：**   
示例：  
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
从Buffer对象的offset偏移写入有符号的大端序64位BigInt型数据value。  
 **调用形式：**     
- writeBigInt64BE(value: bigint, offset?: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | bigint | true | 写入Buffer的数据。<br/> |  
| offset | number | false | 偏移量。 默认值: 0。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 写入的字节数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.allocUninitializedFromPool(8);  
let result = buf.writeBigInt64BE(BigInt(0x0102030405060708), 0);    
```    
  
    
### writeBigInt64LE    
从Buffer对象的offset偏移写入有符号的小端序64位BigInt型数据value。  
 **调用形式：**     
- writeBigInt64LE(value: bigint, offset?: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | bigint | true | 写入Buffer的数据。 |  
| offset | number | false | 偏移量。 默认值: 0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 写入的字节数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.allocUninitializedFromPool(8);  
let result = buf.writeBigInt64LE(BigInt(0x0102030405060708), 0);    
```    
  
    
### writeBigUInt64BE    
从Buffer对象的offset偏移写入无符号的大端序64位BigUInt型数据value。  
 **调用形式：**     
- writeBigUInt64BE(value: bigint, offset?: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | bigint | true | 写入Buffer的数据。 |  
| offset | number | false | 偏移量。 默认值: 0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 写入的字节数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.allocUninitializedFromPool(8);  
let result = buf.writeBigUInt64BE(BigInt(0xdecafafecacefade), 0);    
```    
  
    
### writeBigUInt64LE    
从Buffer对象的offset偏移写入无符号的小端序64位BigUInt型数据value。  
 **调用形式：**     
- writeBigUInt64LE(value: bigint, offset?: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | bigint | true | 写入Buffer的数据。 |  
| offset | number | false | 偏移量。 默认值: 0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 写入的字节数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.allocUninitializedFromPool(8);  
let result = buf.writeBigUInt64LE(BigInt(0xdecafafecacefade), 0);    
```    
  
    
### writeDoubleBE    
从Buffer对象的offset偏移写入大端序的64位双浮点型数据value。  
 **调用形式：**     
- writeDoubleBE(value: number, offset?: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | number | true | 写入Buffer的数据。 |  
| offset | number | false | 偏移量。 默认值: 0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 写入的字节数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | 偏移量。 默认值: 0。 |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.allocUninitializedFromPool(8);  
let result = buf.writeDoubleBE(123.456, 0);    
```    
  
    
### writeDoubleLE    
从Buffer对象的offset偏移写入小端序的64位双浮点型数据value。  
 **调用形式：**     
- writeDoubleLE(value: number, offset?: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | number | true | 写入Buffer的数据。 |  
| offset | number | false | 偏移量。 默认值: 0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 写入的字节数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 8. Received value is: [offset] |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.allocUninitializedFromPool(8);  
let result = buf.writeDoubleLE(123.456, 0);    
```    
  
    
### writeFloatBE    
从Buffer对象的offset偏移写入大端序的32位浮点型数据value。  
 **调用形式：**     
- writeFloatBE(value: number, offset?: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | number | true | 写入Buffer的数据。 |  
| offset | number | false | 偏移量。 默认值: 0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 写入的字节数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 4. Received value is: [offset] |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.allocUninitializedFromPool(8);  
let result = buf.writeFloatBE(0xcafebabe, 0);    
```    
  
    
### writeFloatLE    
从Buffer对象的offset偏移写入小端序的32位浮点型数据value。  
 **调用形式：**     
- writeFloatLE(value: number, offset?: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | number | true | 写入Buffer的数据。 |  
| offset | number | false | 偏移量。 默认值: 0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 写入的字节数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "offset" is out of range. It must be >= 0 and <= buf.length - 4. Received value is: [offset] |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.allocUninitializedFromPool(8);  
let result = buf.writeFloatLE(0xcafebabe, 0);    
```    
  
    
### writeInt8    
从Buffer对象的offset偏移写入8位有符号整型数据value。  
 **调用形式：**     
- writeInt8(value: number, offset?: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | number | true | 写入Buffer的数据。 |  
| offset | number | false | 偏移量。 默认值: 0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 写入的字节数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.allocUninitializedFromPool(2);  
let result = buf.writeInt8(2, 0);  
let result1 = buf.writeInt8(-2, 1);    
```    
  
    
### writeInt16BE    
从Buffer对象的offset偏移写入大端序的16位有符号整型数据value。  
 **调用形式：**     
- writeInt16BE(value: number, offset?: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | number | true | 写入Buffer的数据。 |  
| offset | number | false | 偏移量。 默认值: 0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 写入的字节数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.allocUninitializedFromPool(2);  
let result = buf.writeInt16BE(0x0102, 0);    
```    
  
    
### writeInt16LE    
从Buffer对象的offset偏移写入小端序的16位有符号整型数据value。  
 **调用形式：**     
- writeInt16LE(value: number, offset?: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | number | true | 写入Buffer的数据。 |  
| offset | number | false | 偏移量。 默认值: 0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 写入的字节数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.allocUninitializedFromPool(2);  
let result = buf.writeInt16LE(0x0304, 0);    
```    
  
    
### writeInt32BE    
从Buffer对象的offset偏移写入大端序的32位有符号整型数据value。  
 **调用形式：**     
- writeInt32BE(value: number, offset?: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | number | true | 写入Buffer的数据。 |  
| offset | number | false | 偏移量。 默认值: 0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 写入的字节数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.allocUninitializedFromPool(4);  
let result = buf.writeInt32BE(0x01020304, 0);    
```    
  
    
### writeInt32LE    
从Buffer对象的offset偏移写入小端序的32位有符号整型数据value。  
 **调用形式：**     
- writeInt32LE(value: number, offset?: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | number | true | 写入Buffer的数据。 |  
| offset | number | false | 偏移量。 默认值: 0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 写入的字节数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.allocUninitializedFromPool(4);  
let result = buf.writeInt32LE(0x05060708, 0);    
```    
  
    
### writeIntBE    
从Buffer对象的offset偏移写入大端序的有符号value数据，value字节长度为byteLength。  
 **调用形式：**     
- writeIntBE(value: number, offset: number, byteLength: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | number | true | 从Buffer对象的offset偏移写入大端序的有符号value数据，value字节长度为byteLength。 |  
| offset | number | true | 偏移量。 默认值: 0。 |  
| byteLength | number | true | 要写入的字节数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 写入的字节数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.allocUninitializedFromPool(6);  
let result = buf.writeIntBE(0x1234567890ab, 0, 6);    
```    
  
    
### writeIntLE    
从Buffer对象的offset偏移写入小端序的有符号value数据，value字节长度为byteLength。  
 **调用形式：**     
- writeIntLE(value: number, offset: number, byteLength: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | number | true | 写入Buffer的数据。 |  
| offset | number | true | 偏移量。 默认值: 0。 |  
| byteLength | number | true | 要写入的字节数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 写入的字节数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.allocUninitializedFromPool(6);  
let result = buf.writeIntLE(0x1234567890ab, 0, 6);    
```    
  
    
### writeUInt8    
从Buffer对象的offset偏移写入8位无符号整型数据value。  
 **调用形式：**     
- writeUInt8(value: number, offset?: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | number | true | 写入Buffer的数据。 |  
| offset | number | false | 偏移量。 默认值: 0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 写入的字节数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.allocUninitializedFromPool(4);  
let result = buf.writeUInt8(0x3, 0);  
let result1 = buf.writeUInt8(0x4, 1);  
let result2 = buf.writeUInt8(0x23, 2);  
let result3 = buf.writeUInt8(0x42, 3);    
```    
  
    
### writeUInt16BE    
从Buffer对象的offset偏移写入大端序的16位无符号整型数据value。  
 **调用形式：**     
- writeUInt16BE(value: number, offset?: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | number | true | 写入Buffer的数据。<br/> |  
| offset | number | false | 偏移量。 默认值为0。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 写入的字节数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.allocUninitializedFromPool(4);  
let result = buf.writeUInt16BE(0xdead, 0);  
let result1 = buf.writeUInt16BE(0xbeef, 2);    
```    
  
    
### writeUInt16LE    
从Buffer对象的offset偏移写入小端序的16位无符号整型数据value。  
 **调用形式：**     
- writeUInt16LE(value: number, offset?: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | number | true | 写入Buffer的数据。 |  
| offset | number | false | 偏移量。 默认值: 0。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 写入的字节数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.allocUninitializedFromPool(4);  
let result = buf.writeUInt16LE(0xdead, 0);  
let result1 = buf.writeUInt16LE(0xbeef, 2);    
```    
  
    
### writeUInt32BE    
从Buffer对象的offset偏移写入大端序的32位无符号整型数据value。  
 **调用形式：**     
- writeUInt32BE(value: number, offset?: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | number | true | 写入Buffer的数据。<br/> |  
| offset | number | false | 偏移量。 默认值: 0。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 写入的字节数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.allocUninitializedFromPool(4);  
let result = buf.writeUInt32LE(0xfeedface, 0);    
```    
  
    
### writeUInt32LE    
从Buffer对象的offset偏移写入小端序的32位无符号整型数据value。  
 **调用形式：**     
- writeUInt32LE(value: number, offset?: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | number | true | 写入Buffer的数据。 |  
| offset | number | false | 偏移量。 默认值: 0。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 写入的字节数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.allocUninitializedFromPool(4);  
let result = buf.writeUInt32LE(0xfeedface, 0);    
```    
  
    
### writeUIntBE    
从Buffer对象的offset偏移写入大端序的无符号value数据，value字节长度为byteLength。  
 **调用形式：**     
- writeUIntBE(value: number, offset: number, byteLength: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | number | true | 写入Buffer的数据。<br/> |  
| offset | number | true | 偏移量。 默认值: 0。<br/> |  
| byteLength | number | true | 要写入的字节数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 写入的字节数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.allocUninitializedFromPool(6);  
let result = buf.writeUIntBE(0x1234567890ab, 0, 6);    
```    
  
    
### writeUIntLE    
从Buffer对象的offset偏移写入小端序的无符号value数据，value字节长度为byteLength。  
 **调用形式：**     
- writeUIntLE(value: number, offset: number, byteLength: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | number | true | 写入Buffer的数据。 |  
| offset | number | true | 偏移量。 默认值: 0。<br/> |  
| byteLength | number | true | 要写入的字节数。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 写入的字节数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200001 | The value of "[param]" is out of range. It must be >= [left range] and <= [right range]. Received value is: [param] |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let buf = buffer.allocUninitializedFromPool(6);  
let result = buf.writeUIntLE(0x1234567890ab, 0, 6);    
```    
  
    
## Blob  
 **系统能力:**  SystemCapability.Utils.Lang    
### 属性    
 **系统能力:**  SystemCapability.Utils.Lang    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| size | number | false | true | Blob实例的总字节大小。 |  
| type | string | false | true | Blob实例的内容类型。 |  
    
### arrayBuffer    
将Blob中的数据放入到ArrayBuffer中，并返回一个Promise。  
 **调用形式：**     
    
- arrayBuffer(): Promise\<ArrayBuffer>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<ArrayBuffer> | Promise对象，返回包含Blob数据的ArrayBuffer。 |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let blob: buffer.Blob = new buffer.Blob(['a', 'b', 'c']);  
let pro = blob.arrayBuffer();  
pro.then((val: ArrayBuffer) => {  
  let uintarr: Uint8Array = new Uint8Array(val);  
  console.log(uintarr.toString());  
});    
```    
  
    
### slice    
创建并返回一个复制原Blob对象中指定数据长度的Blob新对象。  
 **调用形式：**     
- slice(start?: number, end?: number, type?: string): Blob  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| start | number | false | 起始位置。默认值为0。 |  
| end | number | false | 结束位置。默认值为原Blob对象中的数据长度。 |  
| type | string | false | 内容类型。默认值为''。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Blob | 新的Blob实例对象。 |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let blob: buffer.Blob = new buffer.Blob(['a', 'b', 'c']);  
let blob2 = blob.slice(0, 2);  
let blob3 = blob.slice(0, 2, "MIME");    
```    
  
    
### text    
使用UTF8进行解码并返回一个文本。使用Promise异步回调。  
 **调用形式：**     
    
- text(): Promise\<string>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<string> | Promise对象，返回包含以UTF8解码的文本。 |  
    
 **示例代码：**   
示例：  
```ts    
import buffer from '@ohos.buffer';  
  
let blob: buffer.Blob = new buffer.Blob(['a', 'b', 'c']);  
let pro = blob.text();  
pro.then((val: string) => {  
  console.log(val)  
});    
```    
  
