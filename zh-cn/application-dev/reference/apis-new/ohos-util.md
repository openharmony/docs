# @ohos.util    
该模块主要提供常用的工具函数，实现字符串编解码（[TextEncoder](#textencoder)，[TextDecoder](#textdecoder)）、有理数运算（[RationalNumber<sup>8+</sup>](#rationalnumber8)）、缓冲区管理（[LRUCache<sup>9+</sup>](#lrucache9)）、范围判断（[ScopeHelper<sup>9+</sup>](#scopehelper9)）、Base64编解码（[Base64Helper<sup>9+</sup>](#base64helper9)）、内置对象类型检查（[types<sup>8+</sup>](#types8)）等功能。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import util from '@ohos.util'    
```  
    
## printf<sup>(deprecated)</sup>    
通过式样化字符串对输入的内容按特定格式输出。  
 **调用形式：**     
- printf(format: string, ...args: Object[]): string  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.format。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| format<sup>(deprecated)</sup> | string | true | 式样化字符串。 |  
| args<sup>(deprecated)</sup> | Object[] | true | v |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 按特定格式式样化后的字符串。 |  
    
 **示例代码：**   
```ts    
let res = util.printf("%s", "hello world!");console.log(res);    
```    
  
    
## format<sup>(9+)</sup>    
通过式样化字符串对输入的内容按特定格式输出。  
 **调用形式：**     
- format(format: string, ...args: Object[]): string  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| format | string | true | 式样化字符串。 |  
| args | Object[] | true | 替换式样化字符串通配符的数据，此参数缺失时，默认返回第一个参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 按特定格式式样化后的字符串。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let name = 'John';  
let age = 20;  
let formattedString = util.format('My name is %s and I am %s years old', name, age);  
console.log(formattedString);  
// 输出结果：My name is John and I am 20 years old  
let num = 10.5;  
formattedString = util.format('The number is %d', num);  
console.log(formattedString);  
// 输出结果：The number is 10.5  
num = 100.5;  
formattedString = util.format('The number is %i', num);  
console.log(formattedString);  
// 输出结果：The number is 100  
const pi = 3.141592653;  
formattedString = util.format('The value of pi is %f', pi);  
console.log(formattedString);  
// 输出结果：The value of pi is 3.141592653  
const obj = { name: 'John', age: 20 };  
formattedString = util.format('The object is %j', obj);  
console.log(formattedString);  
// 输出结果：The object is {"name":"John","age":20}  
const person = {  
  name: 'John',  
  age: 20,  
  address: {  
    city: 'New York',  
    country: 'USA'  
  }  
};  
console.log(util.format('Formatted object using %%O: %O', person));  
console.log(util.format('Formatted object using %%o: %o', person));  
/*  
输出结果：  
Formatted object using %O: { name: 'John',  
  age: 20,  
  address:  
  { city: 'New York',  
    country: 'USA' } }  
Formatted object using %o: { name: 'John',  
  age: 20,  
  address:  
  { city: 'New York',  
    country: 'USA' } }  
*/  
const percentage = 80;  
let arg = 'homework';  
formattedString = util.format('John finished %d%% of the %s', percentage, arg);  
console.log(formattedString);  
// 输出结果：John finished 80% of the homework  
    
```    
  
    
## getErrorString<sup>(deprecated)</sup>    
获取系统错误码对应的详细信息。  
 **调用形式：**     
- getErrorString(errno: number): string  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.errnoToString。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| errno<sup>(deprecated)</sup> | number | true | 系统发生错误产生的错误码。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 错误码对应的详细信息。 |  
    
 **示例代码：**   
```ts    
let errnum = -1; // -1 : a system error numberlet result = util.getErrorString(errnum);console.log("result = " + result);    
```    
  
    
## errnoToString<sup>(9+)</sup>    
获取系统错误码对应的详细信息。  
 **调用形式：**     
- errnoToString(errno: number): string  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| errno | number | true | 系统发生错误产生的错误码。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 错误码对应的详细信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let errnum = -1; // -1 : a system error numberlet result = util.errnoToString(errnum);console.log("result = " + result);    
```    
  
    
## callbackWrapper    
对异步函数进行回调化处理，回调中第一个参数将是拒绝原因（如果 Promise 已解决，则为 null），第二个参数将是已解决的值。  
 **调用形式：**     
- callbackWrapper(original: Function): (err: Object, value: Object) => void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| original | Function | true | 异步函数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| (err: Object, value: Object) => void | 返回一个第一个参数是拒绝原因（如果Promise已解决，则为null），第二个参数是已解决的回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
async function fn() {  return 'hello world';}let cb = util.callbackWrapper(fn);cb(1, (err : Object, ret : string) => {  if (err) throw new Error;  console.log(ret);});    
```    
  
    
## promisify<sup>(9+)</sup>    
对异步函数处理并返回一个promise的函数。  
 **调用形式：**     
- promisify(original: (err: Object, value: Object) => void): Function  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| original | (err: Object, value: Object) => void | true | 异步函数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Function | 采用遵循常见的错误优先的回调风格的函数（也就是将(err,value)=>...回调作为最后一个参数），并返回一个返回promise的函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
function fun(num, callback) {  
  if (typeof num === 'number') {  
      callback(null, num + 3);  
  } else {  
      callback("type err");  
  }  
}  
  
const addCall = util.promisify(fun);  
(async () => {  
  try {  
      let res = await addCall(2);  
      console.log(res);  
  } catch (err) {  
      console.log(err);  
  }  
})();  
    
```    
  
    
## promiseWrapper<sup>(deprecated)</sup>    
对异步函数处理并返回一个promise的版本。  
 **调用形式：**     
- promiseWrapper(original: (err: Object, value: Object) => void): Object  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.promisify。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| original<sup>(deprecated)</sup> | (err: Object, value: Object) => void | true | 异步函数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Object | 采用遵循常见的错误优先的回调风格的函数（也就是将(err,value)=>...回调作为最后一个参数），并返回一个返回promise的版本。 |  
    
## generateRandomUUID<sup>(9+)</sup>    
使用加密安全随机数生成器生成随机的RFC 4122版本4的string类型UUID。  
 **调用形式：**     
- generateRandomUUID(entropyCache?: boolean): string  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| entropyCache | boolean | false | 是否使用已缓存的UUID， 默认true。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 表示此UUID的字符串。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let uuid = util.generateRandomUUID(true);console.log("RFC 4122 Version 4 UUID:" + uuid);// 输出：// RFC 4122 Version 4 UUID:88368f2a-d5db-47d8-a05f-534fab0a0045    
```    
  
    
## generateRandomBinaryUUID<sup>(9+)</sup>    
使用加密安全随机数生成器生成随机的RFC 4122版本4的Uint8Array类型UUID。  
 **调用形式：**     
- generateRandomBinaryUUID(entropyCache?: boolean): Uint8Array  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| entropyCache | boolean | false | 是否使用已缓存的UUID， 默认true。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Uint8Array | 表示此UUID的Uint8Array值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let uuid = util.generateRandomBinaryUUID(true);console.log(JSON.stringify(uuid));// 输出：// 138,188,43,243,62,254,70,119,130,20,235,222,199,164,140,150    
```    
  
    
## parseUUID<sup>(9+)</sup>    
将generateRandomUUID生成的string类型UUID转换为generateRandomBinaryUUID生成的Uint8Array类型UUID，如RFC 4122版本4中所述。  
 **调用形式：**     
- parseUUID(uuid: string): Uint8Array  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uuid | string | true | UUID字符串。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Uint8Array | 返回表示此UUID的Uint8Array，如果解析失败，则抛出SyntaxError。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let uuid = util.parseUUID("84bdf796-66cc-4655-9b89-d6218d100f9c");console.log(JSON.stringify(uuid));// 输出：// 132,189,247,150,102,204,70,85,155,137,214,33,141,16,15,156    
```    
  
    
## TextDecoder  
 **系统能力:**  SystemCapability.Utils.Lang    
### 属性    
 **系统能力:**  SystemCapability.Utils.Lang    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| encoding | string | true | true | 编码格式。<br/>-支持格式：utf-8、ibm866、iso-8859-2、iso-8859-3、iso-8859-4、iso-8859-5、iso-8859-6、iso-8859-7、iso-8859-8、iso-8859-8-i、iso-8859-10、iso-8859-13、iso-8859-14、iso-8859-15、koi8-r、koi8-u、macintosh、windows-874、windows-1250、windows-1251、windows-1252、windows-1253、windows-1254、windows-1255、windows-1256、windows-1257、windows-1258、x-mac-cyrilli、gbk、gb18030、big5、euc-jp、iso-2022-jp、shift_jis、euc-kr、utf-16be、utf-16le。 |  
| fatal | boolean | true | true | 是否显示致命错误。 |  
| ignoreBOM |  | true | true | 是否忽略BOM（byteordermarker）标记，默认值为false，表示解码结果包含BOM标记。 |  
    
### create<sup>(9+)</sup>    
替代有参构造功能。  
 **调用形式：**     
- static create(encoding?: string, options?: { fatal?: boolean; ignoreBOM?: boolean }): TextDecoder  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| encoding | string | false | 编码格式，默认值是'utf-8'。 |  
| options | { fatal?: boolean; ignoreBOM?: boolean } | false | 编码相关选项参数，存在两个属性fatal和ignoreBOM。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| TextDecoder |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let result = util.TextDecoder.create('utf-8', { ignoreBOM : true })let retStr = result.encoding    
```    
  
    
### decode<sup>(deprecated)</sup>    
通过输入参数解码后输出对应文本。  
 **调用形式：**     
- decode(input: Uint8Array, options?: { stream?: false }): string  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.decodeWithStream。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| input<sup>(deprecated)</sup> | Uint8Array | true | 符合格式需要解码的数组。 |  
| options<sup>(deprecated)</sup> | { stream?: false } | false | 解码相关选项参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 解码后的数据。 |  
    
 **示例代码：**   
```ts    
let textDecoder = new util.TextDecoder("utf-8",{ignoreBOM: true});let result = new Uint8Array(6);result[0] = 0xEF;result[1] = 0xBB;result[2] = 0xBF;result[3] = 0x61;result[4] = 0x62;result[5] = 0x63;console.log("input num:");let retStr = textDecoder.decode( result , {stream: false});console.log("retStr = " + retStr);    
```    
  
    
### decodeWithStream<sup>(9+)</sup>    
通过输入参数解码后输出对应文本。  
 **调用形式：**     
- decodeWithStream(input: Uint8Array, options?: { stream?: boolean }): string  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| input | Uint8Array | true | 符合格式需要解码的数组。 |  
| options | { stream?: boolean } | false | 解码相关选项参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 解码后的数据。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let textDecoder = util.TextDecoder.create('utf-8', { ignoreBOM : true });let result = new Uint8Array(6);result[0] = 0xEF;result[1] = 0xBB;result[2] = 0xBF;result[3] = 0x61;result[4] = 0x62;result[5] = 0x63;console.log("input num:");let retStr = textDecoder.decodeWithStream( result , {stream: false});console.log("retStr = " + retStr);    
```    
  
    
## TextEncoder    
TextEncoder用于将字符串编码为字节数组，支持多种编码格式，包括utf-8、utf-16le/be等。需要注意的是，在使用TextEncoder进行编码时，不同编码格式下字符所占的字节数是不同的。例如，utf-8编码下中文字符通常占3个字节，而utf-16le/be编码下中文字符通常占2个字节。因此，在使用TextEncoder时需要明确指定要使用的编码格式，以确保编码结果正确。  
 **系统能力:**  SystemCapability.Utils.Lang    
### 属性    
 **系统能力:**  SystemCapability.Utils.Lang    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| encoding |  | true | true | 编码格式，默认值是'utf-8'。 |  
    
### encode<sup>(deprecated)</sup>    
通过输入参数异步编码后输出对应文本。  
 **调用形式：**     
- encode(input?: string): Uint8Array  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.encodeInto。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| input<sup>(deprecated)</sup> | string | false |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Uint8Array | 异步编码输入Uint8数组。 |  
    
 **示例代码：**   
```ts    
<span style="letter-spacing: 0px;">let textEncoder = new util.TextEncoder();</span>  
let buffer = new ArrayBuffer(20);let result = new Uint8Array(buffer);result = textEncoder.encode("\uD800¥¥");    
```    
  
    
### encodeInto<sup>(9+)</sup>    
通过输入参数编码后输出对应文本。  
 **调用形式：**     
- encodeInto(input?: string): Uint8Array  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| input | string | false | 需要编码的字符串，默认值是空字符串。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Uint8Array | 返回编码后的文本。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let textEncoder = new util.TextEncoder();let buffer = new ArrayBuffer(20);let result = new Uint8Array(buffer);result = textEncoder.encode("\uD800¥¥");    
```    
  
    
### encodeInto<sup>(deprecated)</sup>    
放置生成的UTF-8编码文本。  
 **调用形式：**     
- encodeInto(input: string, dest: Uint8Array): { read: number; written: number }  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.encodeIntoUint8Array。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| input<sup>(deprecated)</sup> | string | true | <span style="letter-spacing: 0px;">需要编码的字符串。</span>。 |  
| dest<sup>(deprecated)</sup> | Uint8Array | true | Uint8Array对象实例，用于将生成的UTF-8编码文本放入其中。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| { read: number; written: number } |  |  
    
 **示例代码：**   
```ts    
let that = new util.TextEncoder()let buffer = new ArrayBuffer(4)let dest = new Uint8Array(buffer)let result = new Object()result = that.encodeInto('abcd', dest)    
```    
  
    
### encodeIntoUint8Array<sup>(9+)</sup>    
放置生成的UTF-8编码文本。  
 **调用形式：**     
- encodeIntoUint8Array(input: string, dest: Uint8Array): { read: number; written: number }  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| input | string | true | 需要编码的字符串。 |  
| dest | Uint8Array | true | Uint8Array对象实例，用于将生成的UTF-8编码文本放入其中。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| { read: number; written: number } | 返回编码后的文本。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let that = new util.TextEncoder()let buffer = new ArrayBuffer(4)let dest = new Uint8Array(buffer)let result = new Object()result = that.encodeIntoUint8Array('abcd', dest)    
```    
  
    
## RationalNumber<sup>(8+)</sup>    
RationalNumber主要是对有理数进行比较，获取分子分母等方法。例如使用toString()方法可以将有理数转换为字符串形式，使用该类可以方便地进行有理数的各种操作。  
 **系统能力:**  SystemCapability.Utils.Lang    
### parseRationalNumber<sup>(9+)</sup>    
用于创建具有给定分子和分母的RationalNumber实例。  
 **调用形式：**     
- static parseRationalNumber(numerator: number, denominator: number): RationalNumber  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| numerator | number | true | 分子，整数类型。 |  
| denominator | number | true | 分母，整数类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RationalNumber |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let rationalNumber = util.RationalNumber.parseRationalNumber(1,2);    
```    
  
    
### createRationalFromString<sup>(8+)</sup>    
基于给定的字符串创建一个RationalNumber对象。  
 **调用形式：**     
- static createRationalFromString(rationalString: string): RationalNumber  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| rationalString | string | true | 字符串格式。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RationalNumber | 返回有理数类的对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let rational = util.RationalNumber.createRationalFromString("3/4");    
```    
  
    
### compareTo<sup>(deprecated)</sup>    
将当前的RationalNumber对象与给定的对象进行比较。  
 **调用形式：**     
- compareTo(another: RationalNumber): number  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.compare。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| another<sup>(deprecated)</sup> | RationalNumber | true | 其他的有理数对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 如果两个对象相等，则返回0；如果给定对象小于当前对象，则返回1；如果给定对象大于当前对象，则返回-1。 |  
    
 **示例代码：**   
```ts    
let rationalNumber = new util.RationalNumber(1,2);let rational = util.RationalNumber.createRationalFromString("3/4");let result = rationalNumber.compareTo(rational);    
```    
  
    
### compare<sup>(9+)</sup>    
将当前的RationalNumber对象与给定的对象进行比较。  
 **调用形式：**     
- compare(another: RationalNumber): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| another | RationalNumber | true | 其他的有理数对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 如果两个对象相等，则返回0；如果给定对象小于当前对象，则返回1；如果给定对象大于当前对象，则返回-1。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let rationalNumber = util.RationalNumber.parseRationalNumber(1,2);let rational = util.RationalNumber.createRationalFromString("3/4");let result = rationalNumber.compare(rational);console.log("result = " + result);// 输出结果：result = -1    
```    
  
    
### equals<sup>(8+)</sup>    
将当前的RationalNumber对象与给定的对象进行比较是否相等。  
 **调用形式：**     
- equals(obj: Object): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| obj | Object | true | 其他类型对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 如果给定对象与当前对象相同，则返回true；否则返回false。 |  
    
 **示例代码：**   
```ts    
<span style="letter-spacing: 0px;">let rationalNumber = new util.RationalNumber(1,2);</span>let rational = util.RationalNumber.createRationalFromString("3/4");let result = rationalNumber.equals(rational);console.log("result = " + result);// 输出结果：result = false```API 9及以上建议使用以下写法：```tslet rationalNumber = util.RationalNumber.parseRationalNumber(1,2);let rational = util.RationalNumber.createRationalFromString("3/4");let result = rationalNumber.equals(rational);console.log("result = " + result);<span style="letter-spacing: 0px;">// 输出结果：result = false</span><b></b><span style="font-size: 14px; letter-spacing: 0px;"></span>  
    
```    
  
    
### valueOf<sup>(8+)</sup>    
以整数形式或者浮点数的形式获取当前RationalNumber对象的值。  
 **调用形式：**     
- valueOf(): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回整数或者浮点数的值。 |  
    
 **示例代码：**   
```ts    
let rationalNumber = new util.RationalNumber(1,2);let result = rationalNumber.valueOf();console.log("result = " + result);// 输出结果：result = 0.5```API 9及以上建议使用以下写法：```tslet rationalNumber = util.RationalNumber.parseRationalNumber(1,2);let result = rationalNumber.valueOf();console.log("result = " + result);// 输出结果：result = 0.5    
```    
  
    
### getCommonDivisor<sup>(deprecated)</sup>    
获取两个指定整数的最大公约数。  
 **调用形式：**     
- static getCommonDivisor(number1: number, number2: number): number  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.getCommonFactor。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| number1<sup>(deprecated)</sup> | number | true | 整数类型。 |  
| number2<sup>(deprecated)</sup> | number | true | 整数类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回两个给定数字的最大公约数。 |  
    
 **示例代码：**   
```ts    
let result = util.RationalNumber.getCommonFactor(4,6);console.log("result = " + result);// 输出结果：result = 2    
```    
  
    
### getCommonFactor<sup>(9+)</sup>    
获取两个指定整数的最大公约数。  
 **调用形式：**     
- static getCommonFactor(number1: number, number2: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| number1 | number | true | 整数类型。 |  
| number2 | number | true | 整数类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回两个给定数字的最大公约数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let result = util.RationalNumber.getCommonFactor(4,6);console.log("result = " + result);// 输出结果：result = 2    
```    
  
    
### getDenominator<sup>(8+)</sup>    
获取当前RationalNumber对象的分母。  
 **调用形式：**     
- getDenominator(): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回RationalNumber对象的分母的值。 |  
    
 **示例代码：**   
```ts    
let rationalNumber = new util.RationalNumber(1,2);let result = rationalNumber.getDenominator();console.log("result = " + result);// 输出结果：result = 2```API 9及以上建议使用以下写法：```tslet rationalNumber = util.RationalNumber.parseRationalNumber(1,2)let result = rationalNumber.getDenominator();console.log("result = " + result);// 输出结果：result = 2    
```    
  
    
### getNumerator<sup>(8+)</sup>    
获取当前RationalNumber对象的分子。  
 **调用形式：**     
- getNumerator(): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回RationalNumber对象的分子的值。 |  
    
 **示例代码：**   
```ts    
let rationalNumber = new util.RationalNumber(1,2);let result = rationalNumber.getNumerator();console.log("result = " + result);// 输出结果：result = 1```API 9及以上建议使用以下写法：```tslet rationalNumber = util.RationalNumber.parseRationalNumber(1,2);let result = rationalNumber.getNumerator();console.log("result = " + result);// 输出结果：result = 1    
```    
  
    
### isFinite<sup>(8+)</sup>    
检查当前RationalNumber对象是否表示一个有限值。  
 **调用形式：**     
- isFinite(): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 如果分母不为0，则返回true；否则返回false。 |  
    
 **示例代码：**   
```ts    
let rationalNumber = new util.RationalNumber(1,2);let result = rationalNumber.isFinite();console.log("result = " + result);// 输出结果：result = true```API 9及以上建议使用以下写法：```tslet rationalNumber = util.RationalNumber.parseRationalNumber(1,2);let result = rationalNumber.isFinite();console.log("result = " + result);// 输出结果：result = true    
```    
  
    
### isNaN<sup>(8+)</sup>    
检查当前RationalNumber对象是否表示非数字。  
 **调用形式：**     
- isNaN(): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 如果分母和分子都为0，则返回true；否则返回false。 |  
    
 **示例代码：**   
```ts    
et rationalNumber = new util.RationalNumber(1,2);let result = rationalNumber.isNaN();console.log("result = " + result);// 输出结果：result = false```API 9及以上建议使用以下写法：```tslet rationalNumber = util.RationalNumber.parseRationalNumber(1,2);let result = rationalNumber.isNaN();console.log("result = " + result);// 输出结果：result = false    
```    
  
    
### isZero<sup>(8+)</sup>    
检查当前RationalNumber对象是否为0。  
 **调用形式：**     
- isZero(): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 如果当前对象表示的值为0，则返回true；否则返回false。 |  
    
 **示例代码：**   
```ts    
let rationalNumber = new util.RationalNumber(1,2);let result = rationalNumber.isZero();console.log("result = " + result);// 输出结果：result = false```API 9及以上建议使用以下写法：```tslet rationalNumber = util.RationalNumber.parseRationalNumber(1,2);let result = rationalNumber.isZero();console.log("result = " + result);// 输出结果：result = false    
```    
  
    
### toString<sup>(8+)</sup>    
获取当前RationalNumber对象的字符串表示形式。  
 **调用形式：**     
- toString(): string  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回Numerator/Denominator格式的字符串，例如3/5，如果当前对象的分子和分母都为0，则返回NaN。 |  
    
 **示例代码：**   
```ts    
let rationalNumber = new util.RationalNumber(1,2);let result = rationalNumber.toString();console.log("result = " + result);// 输出结果：result = 1/2```API 9及以上建议使用以下写法：```tslet rationalNumber = util.RationalNumber.parseRationalNumber(1,2);let result = rationalNumber.toString();console.log("result = " + result);// 输出结果：result = 1/2    
```    
  
    
## LruBuffer<sup>(deprecated)</sup>    
默认构造函数用于创建一个新的LruBuffer实例，默认容量为64。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.util.LRUCache替代。  
 **系统能力:**  SystemCapability.Utils.Lang    
### 属性    
 **系统能力:**  SystemCapability.Utils.Lang    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| length<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.util.LRUCache.length替代。<br>当前缓冲区中值的总数。 |  
    
### updateCapacity<sup>(deprecated)</sup>    
将缓冲区容量更新为指定容量，如果newCapacity小于或等于0，则抛出异常。  
 **调用形式：**     
- updateCapacity(newCapacity: number): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.LRUCache.updateCapacity。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| newCapacity<sup>(deprecated)</sup> | number | true | 指示要为缓冲区自定义的容量。 |  
    
 **示例代码：**   
```ts    
let pro : util.LRUCache<number,number>= new util.LRUCache();pro.updateCapacity(100);    
```    
  
    
### toString<sup>(deprecated)</sup>    
返回对象的字符串表示形式。  
 **调用形式：**     
- toString(): string  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.LRUCache.toString。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回对象的字符串表示形式。 |  
    
 **示例代码：**   
```ts    
let pro : util.LRUCache<number,number> = new util.LRUCache();pro.put(2,10);pro.get(2);pro.remove(20);let result = pro.toString();    
```    
  
    
### getCapacity<sup>(deprecated)</sup>    
获取当前缓冲区的容量。  
 **调用形式：**     
- getCapacity(): number  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.LRUCache.getCapacity。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回当前缓冲区的容量。 |  
    
 **示例代码：**   
```ts    
let pro : util.LRUCache<number,number> = new util.LRUCache();let result = pro.getCapacity();    
```    
  
    
### clear<sup>(deprecated)</sup>    
从当前缓冲区清除键值对。后续会调用afterRemoval()方法执行后续操作。  
 **调用形式：**     
- clear(): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.LRUCache.clear。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **示例代码：**   
```ts    
let pro : util.LRUCache<number,number> = new util.LRUCache();pro.put(2,10);let result = pro.length;pro.clear();    
```    
  
    
### getCreateCount<sup>(deprecated)</sup>    
获取createDefault()返回值的次数。  
 **调用形式：**     
- getCreateCount(): number  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.LRUCache.getCreateCount。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回createDefault()返回值的次数。 |  
    
 **示例代码：**   
```ts    
let pro : util.LRUCache<number,number> = new util.LRUCache();pro.put(1,8);let result = pro.getCreateCount();    
```    
  
    
### getMissCount<sup>(deprecated)</sup>    
获取查询值不匹配的次数。  
 **调用形式：**     
- getMissCount(): number  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.LRUCache.getMissCount。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回查询值不匹配的次数 |  
    
 **示例代码：**   
```ts    
let pro : util.LRUCache<number,number> = new util.LRUCache();pro.put(2,10);pro.get(2);let result = pro.getMissCount();    
```    
  
    
### getRemovalCount<sup>(deprecated)</sup>    
获取从缓冲区中逐出值的次数。  
 **调用形式：**     
- getRemovalCount(): number  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.LRUCache.getRemovalCount。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回从缓冲区中驱逐的次数。 |  
    
 **示例代码：**   
```ts    
let pro : util.LRUCache<number,number> = new util.LRUCache();pro.put(2,10);pro.updateCapacity(2);pro.put(50,22);let result = pro.getRemovalCount();    
```    
  
    
### getMatchCount<sup>(deprecated)</sup>    
获取查询值匹配成功的次数。  
 **调用形式：**     
- getMatchCount(): number  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.LRUCache.getMatchCount。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回查询值匹配成功的次数。 |  
    
 **示例代码：**   
```ts    
let pro : util.LRUCache<number,number> = new util.LRUCache();  pro.put(2,10);  pro.get(2);  let result = pro.getMatchCount();    
```    
  
    
### getPutCount<sup>(deprecated)</sup>    
获取将值添加到缓冲区的次数。  
 **调用形式：**     
- getPutCount(): number  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.LRUCache.getPutCount。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回将值添加到缓冲区的次数。 |  
    
 **示例代码：**   
```ts    
let pro : util.LRUCache<number,number> = new util.LRUCache();pro.put(2,10);let result = pro.getPutCount();    
```    
  
    
### isEmpty<sup>(deprecated)</sup>    
检查当前缓冲区是否为空。  
 **调用形式：**     
- isEmpty(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.LRUCache.isEmpty。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 如果当前缓冲区不包含任何值，则返回true。 |  
    
 **示例代码：**   
```ts    
let pro : util.LRUCache<number,number> = new util.LRUCache();pro.put(2,10);let result = pro.isEmpty();    
```    
  
    
### get<sup>(deprecated)</sup>    
表示要查询的键。  
 **调用形式：**     
- get(key: K): V | undefined  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.LRUCache.get。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key<sup>(deprecated)</sup> | K | true | 要查询的键。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| V | undefined | 如果指定的键存在于缓冲区中，则返回与键关联的值；否则返回undefined。 |  
    
 **示例代码：**   
```ts    
let pro : util.LRUCache<number,number> = new util.LRUCache();pro.put(2,10);let result  = pro.get(2);    
```    
  
    
### put<sup>(deprecated)</sup>    
将键值对添加到缓冲区。  
 **调用形式：**     
- put(key: K, value: V): V  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.LRUCache.put。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key<sup>(deprecated)</sup> | K | true | 要添加的密钥。 |  
| value<sup>(deprecated)</sup> | V | true | 指示与要添加的键关联的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| V | 返回与添加的键关联的值；如果要添加的键已经存在，则返回原始值，如果键或值为空，则抛出此异常。 |  
    
 **示例代码：**   
```ts    
let pro : util.LRUCache<number,number> = new util.LRUCache();let result = pro.put(2,10);    
```    
  
    
### values<sup>(deprecated)</sup>    
获取当前缓冲区中所有值从最近访问到最近最少访问的顺序列表。  
 **调用形式：**     
- values(): V[]  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.LRUCache.values。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| V[] | 按从最近访问到最近最少访问的顺序返回当前缓冲区中所有值的列表。 |  
    
 **示例代码：**   
```ts    
let pro : util.LRUCache<number|string,number|string> = new util.LRUCache();pro.put(2,10);pro.put(2,"anhu");pro.put("afaf","grfb");let result = pro.values();    
```    
  
    
### keys<sup>(deprecated)</sup>    
获取当前缓冲区中所有键从最近访问到最近最少访问的升序列表。  
 **调用形式：**     
- keys(): K[]  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.LRUCache.keys。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| K[] | 按升序返回当前缓冲区中所有键的列表，从最近访问到最近最少访问。 |  
    
 **示例代码：**   
```ts    
let pro : util.LRUCache<number,number>= new util.LRUCache();pro.put(2,10);let result = pro.keys();    
```    
  
    
### remove<sup>(deprecated)</sup>    
从当前缓冲区中删除指定的键及其关联的值。  
 **调用形式：**     
- remove(key: K): V | undefined  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.LRUCache.remove。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key<sup>(deprecated)</sup> | K | true | 要删除的密钥。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| V | undefined | 返回一个包含已删除键值对的Optional对象；如果key不存在，则返回一个空的Optional对象，如果key为null，则抛出异常。 |  
    
 **示例代码：**   
```ts    
let pro : util.LRUCache<number,number>= new util.LRUCache();pro.put(2,10);let result = pro.remove(20);    
```    
  
    
### afterRemoval<sup>(deprecated)</sup>    
删除值后执行后续操作。  
 **调用形式：**     
- afterRemoval(isEvict: boolean, key: K, value: V, newValue: V): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.LRUCache.afterRemoval。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isEvict<sup>(deprecated)</sup> | boolean | true | 因容量不足而调用该方法时，参数值为true，其他情况为false。 |  
| key<sup>(deprecated)</sup> | K | true | 表示删除的键。 |  
| value<sup>(deprecated)</sup> | V | true | 表示删除的值。 |  
| newValue<sup>(deprecated)</sup> | V | true | 如果已调用put方法并且要添加的键已经存在，则参数值是关联的新值。其他情况下参数值为空。 |  
    
 **示例代码：**   
```ts    
let arr : Object[] = [];class ChildLruBuffer<K, V> extends util.LRUCache<K, V> {  constructor() {    super();  }  
  afterRemoval(isEvict: boolean, key: K, value: V, newValue: V) : void  {    if (isEvict === false) {      arr = [key, value, newValue];    }  }}let lru : ChildLruBuffer<number,number|null>= new ChildLruBuffer();lru.afterRemoval(false,10,30,null);    
```    
  
    
### contains<sup>(deprecated)</sup>    
检查当前缓冲区是否包含指定的键。  
 **调用形式：**     
- contains(key: K): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.LRUCache.contains。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key<sup>(deprecated)</sup> | K | true | 表示要检查的键。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 如果缓冲区包含指定的键，则返回true。 |  
    
 **示例代码：**   
```ts    
let pro : util.LRUCache<number|object,number> = new util.LRUCache();pro.put(2,10);class Lru{s : string = ""}let obj : Lru = {s : "key" }let result = pro.contains(obj);    
```    
  
    
### createDefault<sup>(deprecated)</sup>    
如果未计算特定键的值，则执行后续操作，参数表示丢失的键，返回与键关联的值。  
 **调用形式：**     
- createDefault(key: K): V  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.LRUCache.createDefault。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key<sup>(deprecated)</sup> | K | true | 表示丢失的键。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| V | 返回与键关联的值。 |  
    
 **示例代码：**   
```ts    
let pro : util.LRUCache<number,number> = new util.LRUCache();let result = pro.createDefault(50);    
```    
  
    
### entries<sup>(deprecated)</sup>    
允许迭代包含在这个对象中的所有键值对。  
 **调用形式：**     
- entries(): IterableIterator\<[K, V]>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.LRUCache.entries。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| IterableIterator<[K, V]> | 返回一个可迭代数组。 |  
    
 **示例代码：**   
```ts    
let pro : util.LRUCache<number,number> = new util.LRUCache();pro.put(2,10);let result = pro.entries();    
```    
  
    
### [Symbol.iterator]<sup>(deprecated)</sup>    
返回一个键值对形式的二维数组。  
 **调用形式：**     
- [Symbol.iterator](): IterableIterator\<[K, V]>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.LRUCache.[Symbol.iterator]。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| IterableIterator<[K, V]> | 返回一个键值对形式的二维数组。 |  
    
 **示例代码：**   
```ts    
<span style="letter-spacing: 0px;">let pro : util.LRUCache<number,number> = new util.LRUCache();</span>pro.put(2,10);let result = pro[Symbol.iterator]();    
```    
  
    
## LRUCache<sup>(9+)</sup>    
LRUCache用于在缓存空间不够的时候，将近期最少使用的数据替换为新数据。此设计基于资源访问的考虑：近期访问的数据，可能在不久的将来会再次访问。于是最少访问的数据就是价值最小的数据，是最应该踢出缓存空间的数据。  
 **系统能力:**  SystemCapability.Utils.Lang    
### 属性    
 **系统能力:**  SystemCapability.Utils.Lang    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| length<sup>(9+)</sup> | number | false | true | 当前缓冲区中值的总数。 |  
    
### updateCapacity<sup>(9+)</sup>    
将缓冲区容量更新为指定容量，如果newCapacity小于或等于0，则抛出异常。  
 **调用形式：**     
- updateCapacity(newCapacity: number): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| newCapacity | number | true | 指示要为缓冲区自定义的容量。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let pro : util.LruBuffer<number,number> = new util.LruBuffer();  pro.updateCapacity(100);    
```    
  
    
### toString<sup>(9+)</sup>    
返回对象的字符串表示形式。  
 **调用形式：**     
- toString(): string  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回对象的字符串表示形式。 |  
    
 **示例代码：**   
```ts    
 let pro : util.LruBuffer<number,number> = new util.LruBuffer();  pro.put(2,10);  pro.get(2);  pro.remove(20);  let result = pro.toString();    
```    
  
    
### getCapacity<sup>(9+)</sup>    
获取当前缓冲区的容量。  
 **调用形式：**     
- getCapacity(): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回当前缓冲区的容量。 |  
    
 **示例代码：**   
```ts    
let pro : util.LruBuffer<number,number> = new util.LruBuffer();  let result = pro.getCapacity();    
```    
  
    
### clear<sup>(9+)</sup>    
从当前缓冲区清除键值对。后续会调用afterRemoval()方法执行后续操作。  
 **调用形式：**     
- clear(): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **示例代码：**   
```ts    
let pro : util.LruBuffer<number,number> = new util.LruBuffer();  pro.put(2,10);  let result = pro.length;  pro.clear();    
```    
  
    
### getCreateCount<sup>(9+)</sup>    
获取createDefault()返回值的次数。  
 **调用形式：**     
- getCreateCount(): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回createDefault()返回值的次数。 |  
    
 **示例代码：**   
```ts    
let pro : util.LruBuffer<number,number> = new util.LruBuffer();  pro.put(1,8);  let result = pro.getCreateCount();    
```    
  
    
### getMissCount<sup>(9+)</sup>    
获取查询值不匹配的次数。  
 **调用形式：**     
- getMissCount(): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回查询值不匹配的次数。 |  
    
 **示例代码：**   
```ts    
let pro : util.LruBuffer<number,number> = new util.LruBuffer();  pro.put(2,10);  pro.get(2);  let result = pro.getMissCount();    
```    
  
    
### getRemovalCount<sup>(9+)</sup>    
获取从缓冲区中逐出值的次数。  
 **调用形式：**     
- getRemovalCount(): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回从缓冲区中驱逐的次数。 |  
    
 **示例代码：**   
```ts    
let pro : util.LruBuffer<number,number> = new util.LruBuffer();  pro.put(2,10);  pro.updateCapacity(2);  pro.put(50,22);  let result = pro.getRemovalCount();    
```    
  
    
### getMatchCount<sup>(9+)</sup>    
获取查询值匹配成功的次数。  
 **调用形式：**     
- getMatchCount(): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回查询值匹配成功的次数。 |  
    
 **示例代码：**   
```ts    
<span style="letter-spacing: 0px;">let pro : util.LruBuffer<number,number> = new util.LruBuffer();</span>  pro.put(2,10);  pro.get(2);<span style="letter-spacing: 0px;">let result = pro.getMatchCount();</span><i></i><span style="font-size: 14px; letter-spacing: 0px;"></span>  
    
```    
  
    
### getPutCount<sup>(9+)</sup>    
获取将值添加到缓冲区的次数。  
 **调用形式：**     
- getPutCount(): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回将值添加到缓冲区的次数。 |  
    
 **示例代码：**   
```ts    
let pro : util.LruBuffer<number,number> = new util.LruBuffer();  pro.put(2,10);  let result = pro.getPutCount();    
```    
  
    
### isEmpty<sup>(9+)</sup>    
检查当前缓冲区是否为空。  
 **调用形式：**     
- isEmpty(): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 如果当前缓冲区不包含任何值，则返回true。 |  
    
 **示例代码：**   
```ts    
let pro : util.LruBuffer<number,number> = new util.LruBuffer();  pro.put(2,10);  let result = pro.isEmpty();    
```    
  
    
### get<sup>(9+)</sup>    
表示要查询的键。  
 **调用形式：**     
- get(key: K): V | undefined  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key | K | true | 要查询的键。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| V | undefined | 如果指定的键存在于缓冲区中，则返回与键关联的值；否则返回undefined。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let pro : util.LruBuffer<number,number> = new util.LruBuffer();  pro.put(2,10);  let result  = pro.get(2);    
```    
  
    
### put<sup>(9+)</sup>    
将键值对添加到缓冲区。  
 **调用形式：**     
- put(key: K, value: V): V  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key | K | true | 要添加的密钥。 |  
| value | V | true | 指示与要添加的键关联的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| V | 返回与添加的键关联的值；如果要添加的键已经存在，则返回原始值，如果键或值为空，则抛出此异常。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let pro : util.LruBuffer<number,number> = new util.LruBuffer();  let result = pro.put(2,10);    
```    
  
    
### values<sup>(9+)</sup>    
获取当前缓冲区中所有值从最近访问到最近最少访问的顺序列表。  
 **调用形式：**     
- values(): V[]  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| V[] | 按从最近访问到最近最少访问的顺序返回当前缓冲区中所有值的列表。 |  
    
 **示例代码：**   
```ts    
let pro : util.LruBuffer<number|string,number|string> = new util.LruBuffer();  pro.put(2,10);  pro.put(2,"anhu");  pro.put("afaf","grfb");  let result = pro.values();    
```    
  
    
### keys<sup>(9+)</sup>    
获取当前缓冲区中所有键从最近访问到最近最少访问的升序列表。  
 **调用形式：**     
- keys(): K[]  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| K[] | 按升序返回当前缓冲区中所有键的列表，从最近访问到最近最少访问。 |  
    
 **示例代码：**   
```ts    
let pro : util.LruBuffer<number,number> = new util.LruBuffer();  pro.put(2,10);  let result = pro.keys();    
```    
  
    
### remove<sup>(9+)</sup>    
从当前缓冲区中删除指定的键及其关联的值。  
 **调用形式：**     
- remove(key: K): V | undefined  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key | K | true | 要删除的密钥。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| V | undefined | 返回一个包含已删除键值对的Optional对象；如果key不存在，则返回一个空的Optional对象，如果key为null，则抛出异常。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let pro : util.LruBuffer<number,number> = new util.LruBuffer();  pro.put(2,10);  let result = pro.remove(20);    
```    
  
    
### afterRemoval<sup>(9+)</sup>    
删除值后执行后续操作。  
 **调用形式：**     
- afterRemoval(isEvict: boolean, key: K, value: V, newValue: V): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isEvict | boolean | true | 因容量不足而调用该方法时，参数值为true，其他情况为false。 |  
| key | K | true | 表示删除的键。 |  
| value | V | true | 表示删除的值。 |  
| newValue | V | true | 如果已调用put方法并且要添加的键已经存在，则参数值是关联的新值。其他情况下参数值为空。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let arr : object = [];  class ChildLruBuffer<K, V> extends util.LruBuffer<K, V>  {  constructor()  {  super();  }  afterRemoval(isEvict : boolean, key : K, value : V, newValue : V)  {  if (isEvict === false)  {  arr = [key, value, newValue];  }  }  }  let lru : ChildLruBuffer<number,number|null> = new ChildLruBuffer();  lru.afterRemoval(false,10,30,null);    
```    
  
    
### contains<sup>(9+)</sup>    
检查当前缓冲区是否包含指定的键。  
 **调用形式：**     
- contains(key: K): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key | K | true | 表示要检查的键。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 如果缓冲区包含指定的键，则返回true。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let pro : util.LruBuffer<number,number> = new util.LruBuffer();  pro.put(2,10);  let result = pro.contains(20);    
```    
  
    
### createDefault<sup>(9+)</sup>    
如果未计算特定键的值，则执行后续操作，参数表示丢失的键，返回与键关联的值。  
 **调用形式：**     
- createDefault(key: K): V  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key | K | true | 表示丢失的键。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| V | 返回与键关联的值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let pro : util.LruBuffer<number,number> = new util.LruBuffer();  let result = pro.createDefault(50);    
```    
  
    
### entries<sup>(9+)</sup>    
允许迭代包含在这个对象中的所有键值对。  
 **调用形式：**     
- entries(): IterableIterator\<[K, V]>  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| IterableIterator<[K, V]> | 返回一个可迭代数组。 |  
    
 **示例代码：**   
```ts    
let pro : util.LruBuffer<number,number> = new util.LruBuffer();  pro.put(2,10);  let result = pro.entries();    
```    
  
    
### [Symbol.iterator]<sup>(9+)</sup>    
返回一个键值对形式的二维数组。  
 **调用形式：**     
- [Symbol.iterator](): IterableIterator\<[K, V]>  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| IterableIterator<[K, V]> | 返回一个键值对形式的二维数组。 |  
    
 **示例代码：**   
```ts    
let pro : util.LruBuffer<number,number> = new util.LruBuffer();  pro.put(2,10);  let result = pro.entries();    
```    
  
    
## ScopeComparable    
ScopeComparable类型的值需要实现compareTo方法，确保传入的数据具有可比性。    
### compareTo<sup>(8+)</sup>    
比较两个值的大小，返回一个布尔值。  
 **调用形式：**     
- compareTo(other: ScopeComparable): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| other | ScopeComparable | true | 表示要比较的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 调用compareTo的值大于等于传入的值返回true，否则返回false。 |  
    
 **示例代码：**   
```ts    
class Temperature{  
  private readonly _temp: number;  
  constructor(value : number) {  
    this._temp = value;  
  }  
  compareTo(value : Temperature ) {  
    return this._temp >= value.getTemp();  
  }  
  getTemp() {  
    return this._temp;  
  }  
  toString() : string {  
    return this._temp.toString();  
  }  
}  
    
```    
  
    
### compareTo<sup>(10+)</sup>  
 **调用形式：**     
- compareTo(other: ScopeComparable): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| other | ScopeComparable | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean |  |  
    
## ScopeType<sup>(8+)</sup>    
用于表示范围中的值的类型。  
 **系统能力:**  SystemCapability.Utils.Lang    
    
| 取值范围 | 说明 |  
| --------| --------|  
| ScopeComparable | 表示值的类型为ScopeComparable。 |  
| number | | number | 表示值的类型为数字。 | |  
    
## Scope<sup>(deprecated)</sup>    
用于创建指定下限和上限的作用域实例的构造函数，返回一个Scope对象。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.util.ScopeHelper替代。  
 **系统能力:**  SystemCapability.Utils.Lang    
### toString<sup>(deprecated)</sup>    
该字符串化方法返回一个包含当前范围的字符串表示形式。  
 **调用形式：**     
- toString(): string  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.ScopeHelper.toString。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回包含当前范围对象的字符串表示形式。 |  
    
 **示例代码：**   
```ts    
class Temperature{  
    private readonly _temp: number;  
    constructor(value : number) {  
      this._temp = value;  
    }  
    compareTo(value : Temperature ) {  
      return this._temp >= value.getTemp();  
    }  
    getTemp() {  
      return this._temp;  
    }  
    toString() : string {  
      return this._temp.toString();  
    }  
  }  
  
  let tempLower = new Temperature(30);  
  let tempUpper = new Temperature(40);  
  let range = new util.Scope(tempLower, tempUpper);  
  let result = range.toString();  
    
```    
  
    
### intersect<sup>(deprecated)</sup>    
获取给定范围和当前范围的交集。  
 **调用形式：**     
- intersect(range: Scope): Scope  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.ScopeHelper.intersect。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| range<sup>(deprecated)</sup> | Scope | true | 传入一个给定范围。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Scope | 返回给定范围和当前范围的交集。 |  
    
### intersect<sup>(deprecated)</sup>    
获取当前范围与给定下限和上限范围的交集。  
 **调用形式：**     
- intersect(lowerObj: ScopeType, upperObj: ScopeType): Scope  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.ScopeHelper.intersect。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| lowerObj<sup>(deprecated)</sup> | ScopeType | true | 给定范围的下限。 |  
| upperObj<sup>(deprecated)</sup> | ScopeType | true | 给定范围的上限。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Scope | 返回当前范围与给定下限和上限范围的交集。 |  
    
 **示例代码：**   
```ts    
class Temperature{  
    private readonly _temp: number;  
    constructor(value : number) {  
      this._temp = value;  
    }  
    compareTo(value : Temperature ) {  
      return this._temp >= value.getTemp();  
    }  
    getTemp() {  
      return this._temp;  
    }  
    toString() : string {  
      return this._temp.toString();  
    }  
  }  
  
  let tempLower = new Temperature(30);  
  let tempUpper = new Temperature(40);  
  let tempMiDF = new Temperature(35);  
  let tempMidS = new Temperature(39);  
  let range = new util.Scope(tempLower, tempUpper);  
  let result = range.intersect(tempMiDF, tempMidS);  
    
```    
  
    
### getUpper<sup>(deprecated)</sup>    
获取当前范围的上限。  
 **调用形式：**     
- getUpper(): ScopeType  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.ScopeHelper.getUpper。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ScopeType | 返回当前范围的上限值。 |  
    
 **示例代码：**   
```ts    
class Temperature{  
    private readonly _temp: number;  
    constructor(value : number) {  
      this._temp = value;  
    }  
    compareTo(value : Temperature ) {  
      return this._temp >= value.getTemp();  
    }  
    getTemp() {  
      return this._temp;  
    }  
    toString() : string {  
      return this._temp.toString();  
    }  
  }  
  
  let tempLower = new Temperature(30);  
  let tempUpper = new Temperature(40);  
  let range = new util.Scope(tempLower, tempUpper);  
  let result = range.getUpper();  
    
```    
  
    
### getLower<sup>(deprecated)</sup>    
获取当前范围的下限。  
 **调用形式：**     
- getLower(): ScopeType  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.ScopeHelper.getLower。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ScopeType | 返回当前范围的下限值。 |  
    
 **示例代码：**   
```ts    
class Temperature{  
    private readonly _temp: number;  
    constructor(value : number) {  
      this._temp = value;  
    }  
    compareTo(value : Temperature ) {  
      return this._temp >= value.getTemp();  
    }  
    getTemp() {  
      return this._temp;  
    }  
    toString() : string {  
      return this._temp.toString();  
    }  
  }  
  
  let tempLower = new Temperature(30);  
  let tempUpper = new Temperature(40);  
  let range = new util.Scope(tempLower, tempUpper);  
  let result = range.getLower();  
    
```    
  
    
### expand<sup>(deprecated)</sup>  
 **调用形式：**     
- expand(lowerObj: ScopeType, upperObj: ScopeType): Scope  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.ScopeHelper.expand。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| lowerObj<sup>(deprecated)</sup> | ScopeType | true | 给定范围的下限。 |  
| upperObj<sup>(deprecated)</sup> | ScopeType | true | 给定范围的上限。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Scope | 返回当前范围和给定下限和上限的并集。 |  
    
 **示例代码：**   
```ts    
class Temperature{  
    private readonly _temp: number;  
    constructor(value : number) {  
      this._temp = value;  
    }  
    compareTo(value : Temperature ) {  
      return this._temp >= value.getTemp();  
    }  
    getTemp() {  
      return this._temp;  
    }  
    toString() : string {  
      return this._temp.toString();  
    }  
  }  
  
  let tempLower = new Temperature(30);  
  let tempUpper = new Temperature(40);  
  let tempMiDF = new Temperature(35);  
  let tempMidS = new Temperature(39);  
  let range = new util.Scope(tempLower, tempUpper);  
  let result = range.expand(tempMiDF, tempMidS);  
    
```    
  
    
### expand<sup>(deprecated)</sup>    
创建并返回包括当前范围和给定范围的并集。  
 **调用形式：**     
- expand(range: Scope): Scope  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.ScopeHelper.expand。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| range<sup>(deprecated)</sup> | Scope | true | 传入一个给定范围。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Scope | 返回包括当前范围和给定范围的并集。 |  
    
 **示例代码：**   
```ts    
class Temperature{  
    private readonly _temp: number;  
    constructor(value : number) {  
      this._temp = value;  
    }  
    compareTo(value : Temperature ) {  
      return this._temp >= value.getTemp();  
    }  
    getTemp() {  
      return this._temp;  
    }  
    toString() : string {  
      return this._temp.toString();  
    }  
  }  
  
  let tempLower = new Temperature(30);  
  let tempUpper = new Temperature(40);  
  let tempMiDF = new Temperature(35);  
  let tempMidS = new Temperature(39);  
  let range = new util.Scope(tempLower, tempUpper);  
  let rangeFir = new util.Scope(tempMiDF, tempMidS);  
  let result = range.expand(rangeFir);  
    
```    
  
    
### expand<sup>(deprecated)</sup>    
创建并返回包括当前范围和给定值的并集。  
 **调用形式：**     
- expand(value: ScopeType): Scope  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.ScopeHelper.expand。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value<sup>(deprecated)</sup> | ScopeType | true | 传入一个给定值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Scope | 返回包括当前范围和给定值的并集。 |  
    
 **示例代码：**   
```ts    
class Temperature{  
    private readonly _temp: number;  
    constructor(value : number) {  
      this._temp = value;  
    }  
    compareTo(value : Temperature ) {  
      return this._temp >= value.getTemp();  
    }  
    getTemp() {  
      return this._temp;  
    }  
    toString() : string {  
      return this._temp.toString();  
    }  
  }  
  
  let tempLower = new Temperature(30);  
  let tempUpper = new Temperature(40);  
  let tempMiDF = new Temperature(35);  
  let range = new util.Scope(tempLower, tempUpper);  
  let result = range.expand(tempMiDF);  
    
```    
  
    
### contains<sup>(deprecated)</sup>    
检查给定value是否包含在当前范围内。  
 **调用形式：**     
- contains(value: ScopeType): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.ScopeHelper.contains。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value<sup>(deprecated)</sup> | ScopeType | true | 传入一个给定值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 如果给定值包含在当前范围内返回true，否则返回false。 |  
    
 **示例代码：**   
```ts    
class Temperature{  
    private readonly _temp: number;  
    constructor(value : number) {  
      this._temp = value;  
    }  
    compareTo(value : Temperature ) {  
      return this._temp >= value.getTemp();  
    }  
    getTemp() {  
      return this._temp;  
    }  
    toString() : string {  
      return this._temp.toString();  
    }  
  }  
  
  let tempLower = new Temperature(30);  
  let tempUpper = new Temperature(40);  
  let tempMiDF = new Temperature(35);  
  let range = new util.Scope(tempLower, tempUpper);  
  let result = range.contains(tempMiDF);  
    
```    
  
    
### contains<sup>(deprecated)</sup>    
检查给定range是否在当前范围内。  
 **调用形式：**     
- contains(range: Scope): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.ScopeHelper.contains。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| range<sup>(deprecated)</sup> | Scope | true | 传入一个给定范围。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 如果给定范围包含在当前范围内返回true，否则返回false。 |  
    
 **示例代码：**   
```ts    
class Temperature{  
    private readonly _temp: number;  
    constructor(value : number) {  
      this._temp = value;  
    }  
    compareTo(value : Temperature ) {  
      return this._temp >= value.getTemp();  
    }  
    getTemp() {  
      return this._temp;  
    }  
    toString() : string {  
      return this._temp.toString();  
    }  
  }  
  
  let tempLower = new Temperature(30);  
  let tempUpper = new Temperature(40);  
  let range = new util.Scope(tempLower, tempUpper);  
  let tempLess = new Temperature(20);  
  let tempMore = new Temperature(45);  
  let rangeSec = new util.Scope(tempLess, tempMore);  
  let result = range.contains(rangeSec);  
    
```    
  
    
### clamp<sup>(deprecated)</sup>    
将给定值限定到当前范围内。  
 **调用形式：**     
- clamp(value: ScopeType): ScopeType  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.ScopeHelper.clamp。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value<sup>(deprecated)</sup> | ScopeType | true | 传入的给定值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ScopeType | 如果传入的value小于下限，则返回lowerObj；如果大于上限值则返回upperObj；如果在当前范围内，则返回value。 |  
    
 **示例代码：**   
```ts    
class Temperature{  
    private readonly _temp: number;  
    constructor(value : number) {  
      this._temp = value;  
    }  
    compareTo(value : Temperature ) {  
      return this._temp >= value.getTemp();  
    }  
    getTemp() {  
      return this._temp;  
    }  
    toString() : string {  
      return this._temp.toString();  
    }  
  }  
  
  let tempLower = new Temperature(30);  
  let tempUpper = new Temperature(40);  
  let tempMiDF = new Temperature(35);  
  let range = new util.Scope(tempLower, tempUpper);  
  let result = range.clamp(tempMiDF);  
    
```    
  
    
## ScopeHelper<sup>(9+)</sup>    
ScopeHelper接口用于描述一个字段的有效范围。ScopeHelper实例的构造函数用于创建具有指定下限和上限的对象，并要求这些对象必须具有可比性。  
 **系统能力:**  SystemCapability.Utils.Lang    
### toString<sup>(9+)</sup>    
该字符串化方法返回一个包含当前范围的字符串表示形式。  
 **调用形式：**     
- toString(): string  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回包含当前范围对象的字符串表示形式。 |  
    
 **示例代码：**   
```ts    
class Temperature{  
  private readonly _temp: number;  
  constructor(value : number) {  
    this._temp = value;  
  }  
  compareTo(value : Temperature ) {  
    return this._temp >= value.getTemp();  
  }  
  getTemp() {  
    return this._temp;  
  }  
  toString() : string {  
    return this._temp.toString();  
  }  
}  
  
let tempLower = new Temperature(30);  
let tempUpper = new Temperature(40);  
let range = new util.ScopeHelper(tempLower, tempUpper);  
let result = range.toString();  
    
```    
  
    
### intersect<sup>(9+)</sup>    
获取给定范围和当前范围的交集。  
 **调用形式：**     
- intersect(range: ScopeHelper): ScopeHelper  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| range | ScopeHelper | true | 传入一个给定范围。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ScopeHelper | 返回给定范围和当前范围的交集。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
class Temperature{  
  private readonly _temp: number;  
  constructor(value : number) {  
    this._temp = value;  
  }  
  compareTo(value : Temperature ) {  
    return this._temp >= value.getTemp();  
  }  
  getTemp() {  
    return this._temp;  
  }  
  toString() : string {  
    return this._temp.toString();  
  }  
}  
  
let tempLower = new Temperature(30);  
let tempUpper = new Temperature(40);  
let range = new util.ScopeHelper(tempLower, tempUpper);  
let tempMiDF = new Temperature(35);  
let tempMidS = new Temperature(39);  
let rangeFir = new util.ScopeHelper(tempMiDF, tempMidS);  
range.intersect(rangeFir);  
    
```    
  
    
### intersect<sup>(9+)</sup>    
获取当前范围与给定下限和上限范围的交集。  
 **调用形式：**     
- intersect(lowerObj: ScopeType, upperObj: ScopeType): ScopeHelper  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| lowerObj | ScopeType | true | 给定范围的下限。 |  
| upperObj | ScopeType | true | 给定范围的上限。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ScopeHelper | 返回当前范围与给定下限和上限范围的交集。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
class Temperature{  
  private readonly _temp: number;  
  constructor(value : number) {  
    this._temp = value;  
  }  
  compareTo(value : Temperature ) {  
    return this._temp >= value.getTemp();  
  }  
  getTemp() {  
    return this._temp;  
  }  
  toString() : string {  
    return this._temp.toString();  
  }  
}  
  
let tempLower = new Temperature(30);  
let tempUpper = new Temperature(40);  
let tempMiDF = new Temperature(35);  
let tempMidS = new Temperature(39);  
let range = new util.ScopeHelper(tempLower, tempUpper);  
let result = range.intersect(tempMiDF, tempMidS);  
    
```    
  
    
### getUpper<sup>(9+)</sup>    
获取当前范围的上限。  
 **调用形式：**     
- getUpper(): ScopeType  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ScopeType | 返回当前范围的上限值。 |  
    
 **示例代码：**   
```ts    
class Temperature{  
  private readonly _temp: number;  
  constructor(value : number) {  
    this._temp = value;  
  }  
  compareTo(value : Temperature ) {  
    return this._temp >= value.getTemp();  
  }  
  getTemp() {  
    return this._temp;  
  }  
  toString() : string {  
    return this._temp.toString();  
  }  
}  
  
let tempLower = new Temperature(30);  
let tempUpper = new Temperature(40);  
let range = new util.ScopeHelper(tempLower, tempUpper);  
let result = range.getUpper();  
    
```    
  
    
### getLower<sup>(9+)</sup>    
获取当前范围的下限。  
 **调用形式：**     
- getLower(): ScopeType  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ScopeType | 返回当前范围的下限值。 |  
    
 **示例代码：**   
```ts    
class Temperature{  
  private readonly _temp: number;  
  constructor(value : number) {  
    this._temp = value;  
  }  
  compareTo(value : Temperature ) {  
    return this._temp >= value.getTemp();  
  }  
  getTemp() {  
    return this._temp;  
  }  
  toString() : string {  
    return this._temp.toString();  
  }  
}  
  
let tempLower = new Temperature(30);  
let tempUpper = new Temperature(40);  
let range = new util.ScopeHelper(tempLower, tempUpper);  
let result = range.getLower();  
    
```    
  
    
### expand<sup>(9+)</sup>    
创建并返回包括当前范围和给定下限和上限的并集。  
 **调用形式：**     
- expand(lowerObj: ScopeType, upperObj: ScopeType): ScopeHelper  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| lowerObj | ScopeType | true | 给定范围的下限。 |  
| upperObj | ScopeType | true | 给定范围的上限。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ScopeHelper | 返回当前范围和给定下限和上限的并集。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
class Temperature{  
  private readonly _temp: number;  
  constructor(value : number) {  
    this._temp = value;  
  }  
  compareTo(value : Temperature ) {  
    return this._temp >= value.getTemp();  
  }  
  getTemp() {  
    return this._temp;  
  }  
  toString() : string {  
    return this._temp.toString();  
  }  
}  
  
let tempLower = new Temperature(30);  
let tempUpper = new Temperature(40);  
let tempMiDF = new Temperature(35);  
let tempMidS = new Temperature(39);  
let range = new util.ScopeHelper(tempLower, tempUpper);  
let result = range.expand(tempMiDF, tempMidS);  
    
```    
  
    
### expand<sup>(9+)</sup>    
创建并返回包括当前范围和给定范围的并集。  
 **调用形式：**     
- expand(range: ScopeHelper): ScopeHelper  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| range | ScopeHelper | true | 传入一个给定范围。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ScopeHelper | 返回包括当前范围和给定范围的并集。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
class Temperature{  
  private readonly _temp: number;  
  constructor(value : number) {  
    this._temp = value;  
  }  
  compareTo(value : Temperature ) {  
    return this._temp >= value.getTemp();  
  }  
  getTemp() {  
    return this._temp;  
  }  
  toString() : string {  
    return this._temp.toString();  
  }  
}  
  
let tempLower = new Temperature(30);  
let tempUpper = new Temperature(40);  
let tempMiDF = new Temperature(35);  
let tempMidS = new Temperature(39);  
let range = new util.ScopeHelper(tempLower, tempUpper);  
let rangeFir = new util.ScopeHelper(tempMiDF, tempMidS);  
let result = range.expand(rangeFir);  
    
```    
  
    
### expand<sup>(9+)</sup>    
创建并返回包括当前范围和给定值的并集。  
 **调用形式：**     
- expand(value: ScopeType): ScopeHelper  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | ScopeType | true | 传入一个给定值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ScopeHelper | 返回包括当前范围和给定值的并集。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
```ts  
class Temperature{  
  private readonly _temp: number;  
  constructor(value : number) {  
    this._temp = value;  
  }  
  compareTo(value : Temperature ) {  
    return this._temp >= value.getTemp();  
  }  
  getTemp() {  
    return this._temp;  
  }  
  toString() : string {  
    return this._temp.toString();  
  }  
}  
  
let tempLower = new Temperature(30);  
let tempUpper = new Temperature(40);  
let tempMiDF = new Temperature(35);  
let range = new util.ScopeHelper(tempLower, tempUpper);  
let result = range.expand(tempMiDF);  
    
```    
  
    
### contains<sup>(9+)</sup>    
检查给定value是否包含在当前范围内。  
 **调用形式：**     
- contains(value: ScopeType): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | ScopeType | true | 传入一个给定值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 如果给定值包含在当前范围内返回true，否则返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
class Temperature{  
  private readonly _temp: number;  
  constructor(value : number) {  
    this._temp = value;  
  }  
  compareTo(value : Temperature ) {  
    return this._temp >= value.getTemp();  
  }  
  getTemp() {  
    return this._temp;  
  }  
  toString() : string {  
    return this._temp.toString();  
  }  
}  
  
let tempLower = new Temperature(30);  
let tempUpper = new Temperature(40);  
let tempMiDF = new Temperature(35);  
let range = new util.ScopeHelper(tempLower, tempUpper);  
let result = range.contains(tempMiDF);  
    
```    
  
    
### contains<sup>(9+)</sup>    
检查给定range是否在当前范围内。  
 **调用形式：**     
- contains(range: ScopeHelper): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| range | ScopeHelper | true | 传入一个给定范围。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 如果给定范围包含在当前范围内返回true，否则返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
class Temperature{  
  private readonly _temp: number;  
  constructor(value : number) {  
    this._temp = value;  
  }  
  compareTo(value : Temperature ) {  
    return this._temp >= value.getTemp();  
  }  
  getTemp() {  
    return this._temp;  
  }  
  toString() : string {  
    return this._temp.toString();  
  }  
}  
  
let tempLower = new Temperature(30);  
let tempUpper = new Temperature(40);  
let range = new util.ScopeHelper(tempLower, tempUpper);  
let tempLess = new Temperature(20);  
let tempMore = new Temperature(45);  
let rangeSec = new util.ScopeHelper(tempLess, tempMore);  
let result = range.contains(rangeSec);  
    
```    
  
    
### clamp<sup>(9+)</sup>    
将给定值限定到当前范围内。  
 **调用形式：**     
- clamp(value: ScopeType): ScopeType  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | ScopeType | true | 传入的给定值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ScopeType | 如果传入的value小于下限，则返回lowerObj；如果大于上限值则返回upperObj；如果在当前范围内，则返回value。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
class Temperature{  
  private readonly _temp: number;  
  constructor(value : number) {  
    this._temp = value;  
  }  
  compareTo(value : Temperature ) {  
    return this._temp >= value.getTemp();  
  }  
  getTemp() {  
    return this._temp;  
  }  
  toString() : string {  
    return this._temp.toString();  
  }  
}  
  
let tempLower = new Temperature(30);  
let tempUpper = new Temperature(40);  
let tempMiDF = new Temperature(35);  
let range = new util.ScopeHelper(tempLower, tempUpper);  
let result = range.clamp(tempMiDF);  
    
```    
  
    
## Base64<sup>(deprecated)</sup>    
Base64的构造函数。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.util.Base64Helper替代。  
 **系统能力:**  SystemCapability.Utils.Lang    
### encodeSync<sup>(deprecated)</sup>    
通过输入参数编码后输出对应文本。  
 **调用形式：**     
- encodeSync(src: Uint8Array): Uint8Array  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.Base64Helper.encodeSync。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| src<sup>(deprecated)</sup> | Uint8Array | true | 编码输入Uint8数组。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Uint8Array | 返回编码后新分配的Uint8数组。 |  
    
 **示例代码：**   
```ts    
let that = new util.Base64Helper();  let array = new Uint8Array([115,49,51]);  let result = that.encodeSync(array);    
```    
  
    
### encodeToStringSync<sup>(deprecated)</sup>    
通过输入参数编码后输出对应文本。  
 **调用形式：**     
- encodeToStringSync(src: Uint8Array): string  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.Base64Helper.encodeToStringSync。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| src<sup>(deprecated)</sup> | Uint8Array | true | 编码输入Uint8数组。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回编码后的字符串。 |  
    
 **示例代码：**   
```ts    
let that = new util.Base64Helper();  let array = new Uint8Array([77,97,110,105,115,100,105,115,116,105,110,103,117,105,115,104,101,100,110,111,116,111,110,108,121,98,121,104,105,115,114,101,97,115,111,110,98,117,116,98,121,116,104,105,115,115,105,110,103,117,108,97,114,112,97,115,115,105,111,110,102,114,111,109,111,116,104,101,114,97,110,105,109,97,108,115,119,104,105,99,104,105,115,97,108,117,115,116,111,102,116,104,101,109,105,110,100,101,120,99,101,101,100,115,116,104,101,115,104,111,114,116,118,101,104,101,109,101,110,99,101,111,102,97,110,121,99,97,114,110,97,108,112,108,101,97,115,117,114,101]);  let result = that.encodeToStringSync(array, util.Type.MIME);    
```    
  
    
### decodeSync<sup>(deprecated)</sup>    
通过输入参数解码后输出对应文本。  
 **调用形式：**     
- decodeSync(src: Uint8Array | string): Uint8Array  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.Base64Helper.decodeSync。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| src<sup>(deprecated)</sup> | string | true | 解码输入Uint8数组或者字符串。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Uint8Array | 返回解码后新分配的Uint8数组。 |  
    
 **示例代码：**   
```ts    
let that = new util.Base64Helper();  let buff = 'TWFuaXNkaXN0aW5ndWlzaGVkbm90b25seWJ5aGlzcmVhc29uYnV0Ynl0aGlzc2luZ3VsYXJwYXNz\r\naW9uZnJvbW90aGVyYW5pbWFsc3doaWNoaXNhbHVzdG9mdGhlbWluZGV4Y2VlZHN0aGVzaG9ydHZl\r\naGVtZW5jZW9mYW55Y2FybmFscGxlYXN1cmU=\r\n';  let result = that.decodeSync(buff, util.Type.MIME);    
```    
  
    
### encode<sup>(deprecated)</sup>    
通过输入参数异步编码后输出对应文本。  
 **调用形式：**     
- encode(src: Uint8Array): Promise\<Uint8Array>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.Base64Helper.encode。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| src<sup>(deprecated)</sup> | Uint8Array | true | 异步编码输入Uint8数组。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Uint8Array> | 返回异步编码后新分配的Uint8数组。 |  
    
 **示例代码：**   
```ts    
let that = new util.Base64Helper();  let array = new Uint8Array([115,49,51]);  let rarray = new Uint8Array([99,122,69,122]);  that.encode(array).then(val=>{    for (let i = 0; i < rarray.length; i++) {      console.log(val[i].toString())    }  })    
```    
  
    
### encodeToString<sup>(deprecated)</sup>    
通过输入参数异步编码后输出对应文本。  
 **调用形式：**     
- encodeToString(src: Uint8Array): Promise\<string>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.Base64Helper.encodeToString。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| src<sup>(deprecated)</sup> | Uint8Array | true | 异步编码输入Uint8数组。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<string> | 返回异步编码后的字符串。 |  
    
 **示例代码：**   
```ts    
let that = new util.Base64Helper();  let array = new Uint8Array([77,97,110,105,115,100,105,115,116,105,110,103,117,105,115,104,101,100,110,111,116,111,110,108,121,98,121,104,105,115,114,101,97,115,111,110,98,117,116,98,121,116,104,105,115,115,105,110,103,117,108,97,114,112,97,115,115,105,111,110,102,114,111,109,111,116,104,101,114,97,110,105,109,97,108,115,119,104,105,99,104,105,115,97,108,117,115,116,111,102,116,104,101,109,105,110,100,101,120,99,101,101,100,115,116,104,101,115,104,111,114,116,118,101,104,101,109,101,110,99,101,111,102,97,110,121,99,97,114,110,97,108,112,108,101,97,115,117,114,101]);  that.encodeToString(array, util.Type.MIME).then(val=>{    // 根据开发者需求进行添加。  })    
```    
  
    
### decode<sup>(deprecated)</sup>    
通过输入参数异步解码后输出对应文本。  
 **调用形式：**     
- decode(src: Uint8Array | string): Promise\<Uint8Array>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.util.Base64Helper.decode。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| src<sup>(deprecated)</sup> | string | true | 异步解码输入Uint8数组或者字符串。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Uint8Array> | 返回异步解码后新分配的Uint8数组。 |  
    
 **示例代码：**   
```ts    
let that = new util.Base64Helper();  let array = 'TWFuaXNkaXN0aW5ndWlzaGVkbm90b25seWJ5aGlzcmVhc29uYnV0Ynl0aGlzc2luZ3VsYXJwYXNz\r\naW9uZnJvbW90aGVyYW5pbWFsc3doaWNoaXNhbHVzdG9mdGhlbWluZGV4Y2VlZHN0aGVzaG9ydHZl\r\naGVtZW5jZW9mYW55Y2FybmFscGxlYXN1cmU=\r\n';  that.decode(array, util.Type.MIME).then(val=>{    // 根据开发者需求进行添加。  })    
```    
  
    
## Type<sup>(10+)</sup>    
Base64编码格式枚举。    
    
 **系统能力:**  SystemCapability.Utils.Lang    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| BASIC | 0 | 表示BASIC编码格式 |  
| MIME | 1 | 表示MIME编码格式。 |  
    
## Base64Helper<sup>(9+)</sup>    
Base64编码表包含A-Z、a-z、0-9这62个字符，以及"+"和"/"这两个特殊字符。在编码时，将原始数据按3个字节一组进行划分，得到若干个6位的数字，然后使用Base64编码表中对应的字符来表示这些数字。如果最后剩余1或2个字节，则需要使用"="字符进行补齐。  
 **系统能力:**  SystemCapability.Utils.Lang    
### encodeSync<sup>(9+)</sup>    
通过输入参数编码后输出对应文本。  
 **调用形式：**     
- encodeSync(src: Uint8Array): Uint8Array  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| src | Uint8Array | true | 编码输入Uint8数组。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Uint8Array | 返回编码后新分配的Uint8数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let that = new util.Base64();  let array = new Uint8Array([115,49,51]);  let result = that.encodeSync(array);    
```    
  
    
### encodeToStringSync<sup>(9+)</sup>    
通过输入参数编码后输出对应文本。  
 **调用形式：**     
- encodeToStringSync(src: Uint8Array, options?: Type): string  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| src | Uint8Array | true | 编码输入Uint8数组。 |  
| options | Type | false | 从API version 10开始支持该参数，表示对应的编码格式。<br/>此参数可选，可选值为：util.Type.BASIC和util.Type.MIME，默认值为：util.Type.BASIC。<br/>- 当参数取值为util.Type.BASIC时，输出结果包含：64个可打印字符，包括大写字母A-Z、小写字母a-z、数字0-9共62个字符，再加上另外2个'+'和'/'，没有回车符、换行符。<br/>- 当参数取值为util.Type.MIME时，输出结果包含：64个可打印字符，包括大写字母A-Z、小写字母a-z、数字0-9共62个字符，再加上另外2个'+'和'/'，编码输出每一行不超过76个字符，而且每行以'\r<br>'符结束。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回编码后的字符串。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let that = new util.Base64();  let array = new Uint8Array([115,49,51]);  let result = that.encodeToStringSync(array);    
```    
  
    
### decodeSync<sup>(9+)</sup>    
通过输入参数解码后输出对应文本。  
 **调用形式：**     
- decodeSync(src: Uint8Array | string, options?: Type): Uint8Array  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| src | string | true | 解码输入Uint8数组或者字符串。 |  
| options | Type | false | 从API version 10开始支持该参数，表示对应的编码格式。<br/>此参数可选，可选值为：util.Type.BASIC和util.Type.MIME，默认值为：util.Type.BASIC。<br/>- 当参数取值为util.Type.BASIC时，表示入参包含：64个可打印字符，包括大写字母A-Z、小写字母a-z、数字0-9共62个字符，再加上另外2个'+'和'/'，没有回车符、换行符。<br/>- 当参数取值为util.Type.MIME时，表示入参包含：64个可打印字符，包括大写字母A-Z、小写字母a-z、数字0-9共62个字符，再加上另外2个'+'和'/'，每一行不超过76个字符，而且每行以'\r<br>'符结束。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Uint8Array | | Uint8Array | 返回解码后新分配的Uint8数组。 | |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let that = new util.Base64();  let buff = 'czEz';  let result = that.decodeSync(buff);    
```    
  
    
### encode<sup>(9+)</sup>    
通过输入参数异步编码后输出对应文本。  
 **调用形式：**     
    
- encode(src: Uint8Array): Promise\<Uint8Array>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| src | Uint8Array | true | 异步编码输入Uint8数组。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<Uint8Array> | 返回异步编码后新分配的Uint8数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let that = new util.Base64();  let array = new Uint8Array([115,49,51]);  let rarray = new Uint8Array([99,122,69,122]);  that.encode(array).then(val=>{          for (let i = 0; i < rarray.length; i++) {                  console.log(val[i].toString())      }  })    
```    
  
    
### encodeToString<sup>(9+)</sup>    
通过输入参数异步编码后输出对应文本。  
 **调用形式：**     
    
- encodeToString(src: Uint8Array, options?: Type): Promise\<string>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| src | Uint8Array | true | 异步编码输入Uint8数组。 |  
| options | Type | false | 从API version 10开始支持该参数，表示对应的编码格式。<br/>此参数可选，可选值为：util.Type.BASIC和util.Type.MIME，默认值为：util.Type.BASIC。<br/>- 当参数取值为util.Type.BASIC时，输出结果包含：64个可打印字符，包括大写字母A-Z、小写字母a-z、数字0-9共62个字符，再加上另外2个'+'和'/'，没有回车符、换行符。<br/>- 当参数取值为util.Type.MIME时，输出结果包含：64个可打印字符，包括大写字母A-Z、小写字母a-z、数字0-9共62个字符，再加上另外2个'+'和'/'，编码输出每一行不超过76个字符，而且每行以'\r<br>'符结束。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<string> | 返回异步编码后的字符串。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let that = new util.Base64();  let array = new Uint8Array([115,49,51]);  that.encodeToString(array).then(val=>{          console.log(val)  })    
```    
  
    
### decode<sup>(9+)</sup>    
通过输入参数异步解码后输出对应文本。  
 **调用形式：**     
    
- decode(src: Uint8Array | string, options?: Type): Promise\<Uint8Array>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| src | string | true | 异步解码输入Uint8数组或者字符串。 |  
| options | Type | false | 从API version 10开始支持该参数，表示对应的编码格式。<br/>此参数可选，可选值为：util.Type.BASIC和util.Type.MIME，默认值为：util.Type.BASIC。<br/>- 当参数取值为util.Type.BASIC时，表示入参包含：64个可打印字符，包括大写字母A-Z、小写字母a-z、数字0-9共62个字符，再加上另外2个'+'和'/'，没有回车符、换行符。<br/>- 当参数取值为util.Type.MIME时，表示入参包含：64个可打印字符，包括大写字母A-Z、小写字母a-z、数字0-9共62个字符，再加上另外2个'+'和'/'，每一行不超过76个字符，而且每行以'\r<br>'符结束。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<Uint8Array> | 返回异步解码后新分配的Uint8数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let that = new util.Base64();  let array = new Uint8Array([99,122,69,122]);  let rarray = new Uint8Array([115,49,51]);  that.decode(array).then(val=>{          for (let i = 0; i < rarray.length; i++) {                  console.log(val[i].toString())      }  })    
```    
  
    
## types<sup>(8+)</sup>    
types为不同类型的内置对象提供类型检查，可以避免由于类型错误导致的异常或崩溃。该模块包含了多个工具函数，用于判断JS对象是否属于各种类型例如：ArrayBuffer、Map、Set等。  
 **系统能力:**  SystemCapability.Utils.Lang    
### isAnyArrayBuffer<sup>(8+)</sup>    
检查输入的value是否是ArrayBuffer类型。  
 **调用形式：**     
- isAnyArrayBuffer(value: Object): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Object | true | 待检测对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 判断的结果，如果是ArrayBuffer类型为true，反之为false。 |  
    
 **示例代码：**   
```ts    
let that = new util.types();  let result = that.isAnyArrayBuffer(new ArrayBuffer(0));    
```    
  
    
### isArrayBufferView<sup>(8+)</sup>    
检查输入的value是否是内置ArrayBufferView辅助类型。  
 **调用形式：**     
- isArrayBufferView(value: Object): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Object | true | 待检测对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 判断的结果，如果是内置包含的ArrayBufferView辅助类型为true，反之为false。 |  
    
 **示例代码：**   
```ts    
let that = new util.types();  let result = that.isArrayBufferView(new Int8Array([]));    
```    
  
    
### isArgumentsObject<sup>(8+)</sup>    
检查输入的value是否是一个arguments对象类型。  
 **调用形式：**     
- isArgumentsObject(value: Object): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Object | true | 待检测对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 判断的结果，如果是内置包含的arguments类型为true，反之为false。 |  
    
 **示例代码：**   
```ts    
let that = new util.types();  function foo() {      let result = that.isArgumentsObject(arguments);  }  let f = foo();    
```    
  
    
### isArrayBuffer<sup>(8+)</sup>    
检查输入的value是否是ArrayBuffer类型。  
 **调用形式：**     
- isArrayBuffer(value: Object): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Object | true | 待检测对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 判断的结果，如果是内置包含的ArrayBuffer类型为true，反之为false。 |  
    
 **示例代码：**   
```ts    
let that = new util.types();  let result = that.isArrayBuffer(new ArrayBuffer(0));    
```    
  
    
### isAsyncFunction<sup>(8+)</sup>    
检查输入的value是否是一个异步函数类型。  
 **调用形式：**     
- isAsyncFunction(value: Object): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Object | true | 待检测对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 判断的结果，如果是内置包含的异步函数类型为true，反之为false。 |  
    
 **示例代码：**   
```ts    
let that = new util.types();  let result = that.isAsyncFunction(async () => {});    
```    
  
    
### isBigInt64Array<sup>(8+)</sup>    
检查输入的value是否是BigInt64Array类型。  
 **调用形式：**     
- isBigInt64Array(value: Object): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Object | true | 待检测对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 判断的结果，如果是内置包含的BigInt64Array类型为true，反之为false。 |  
    
 **示例代码：**   
```ts    
let that = new util.types();  let result = that.isBigInt64Array(new BigInt64Array([]));    
```    
  
    
### isBigUint64Array<sup>(8+)</sup>    
检查输入的value是否是BigUint64Array类型。  
 **调用形式：**     
- isBigUint64Array(value: Object): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Object | true | 待检测对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 判断的结果，如果是内置包含的BigUint64Array类型为true，反之为false。 |  
    
 **示例代码：**   
```ts    
let that = new util.types();  let result = that.isBigUint64Array(new BigUint64Array([]));    
```    
  
    
### isBooleanObject<sup>(8+)</sup>    
检查输入的value是否是一个Boolean对象类型。  
 **调用形式：**     
- isBooleanObject(value: Object): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Object | true | 待检测对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 判断的结果，如果是内置包含的Boolean对象类型为true，反之为false。 |  
    
 **示例代码：**   
```ts    
let that = new util.types();  let result = that.isBooleanObject(new Boolean(true));    
```    
  
    
### isBoxedPrimitive<sup>(8+)</sup>    
检查输入的value是否是Boolean或Number或String或Symbol对象类型。  
 **调用形式：**     
- isBoxedPrimitive(value: Object): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Object | true | 待检测对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 判断的结果，如果是内置包含的Boolean或Number或String或Symbol对象类型为true，反之为false。 |  
    
 **示例代码：**   
```ts    
let that = new util.types();  let result = that.isBoxedPrimitive(new Boolean(false));    
```    
  
    
### isDataView<sup>(8+)</sup>    
检查输入的value是否是DataView类型。  
 **调用形式：**     
- isDataView(value: Object): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Object | true | 待检测对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 判断的结果，如果是内置包含的DataView对象类型为true，反之为false。 |  
    
 **示例代码：**   
```ts    
let that = new util.types();  const ab = new ArrayBuffer(20);  let result = that.isDataView(new DataView(ab));    
```    
  
    
### isDate<sup>(8+)</sup>    
检查输入的value是否是Date类型。  
 **调用形式：**     
- isDate(value: Object): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Object | true | 待检测对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 判断的结果，如果是内置包含的Date对象类型为true，反之为false。 |  
    
 **示例代码：**   
```ts    
let that = new util.types();  let result = that.isDate(new Date());    
```    
  
    
### isExternal<sup>(8+)</sup>    
检查输入的value是否是native External类型。  
 **调用形式：**     
- isExternal(value: Object): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Object | true | 待检测对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 判断的结果，如果是内置包含nativeExternal类型为true，反之为false。 |  
    
 **示例代码：**   
```ts    
let that = new util.types();  let result = that.isExternal(true);    
```    
  
    
### isFloat32Array<sup>(8+)</sup>    
检查输入的value是否是Float32Array数组类型。  
 **调用形式：**     
- isFloat32Array(value: Object): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Object | true | 待检测对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 判断的结果，如果是内置包含的Float32Array数组类型为true，反之为false。 |  
    
 **示例代码：**   
```ts    
let that = new util.types();  let result = that.isFloat32Array(new Float32Array());    
```    
  
    
### isFloat64Array<sup>(8+)</sup>    
检查输入的value是否是Float64Array数组类型。  
 **调用形式：**     
- isFloat64Array(value: Object): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Object | true | 待检测对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 判断的结果，如果是内置包含的Float64Array数组类型为true，反之为false。 |  
    
 **示例代码：**   
```ts    
let that = new util.types();  let result = that.isFloat64Array(new Float64Array());    
```    
  
    
### isGeneratorFunction<sup>(8+)</sup>    
检查输入的value是否是generator函数类型。  
 **调用形式：**     
- isGeneratorFunction(value: Object): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Object | true | 待检测对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 判断的结果，如果是内置包含的generator函数类型为true，反之为false。 |  
    
 **示例代码：**   
```ts    
let that = new util.types();  let result = that.isGeneratorFunction(function* foo() {});    
```    
  
    
### isGeneratorObject<sup>(8+)</sup>    
检查输入的value是否是generator对象类型。  
 **调用形式：**     
- isGeneratorObject(value: Object): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Object | true | 待检测对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 判断的结果，如果是内置包含的generator对象类型为true，反之为false。 |  
    
 **示例代码：**   
```ts    
let that = new util.types();  function* foo() {}  const generator = foo();  let result = that.isGeneratorObject(generator);    
```    
  
    
### isInt8Array<sup>(8+)</sup>    
检查输入的value是否是Int8Array数组类型。  
 **调用形式：**     
- isInt8Array(value: Object): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Object | true | 待检测对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 判断的结果，如果是内置包含的Int8Array数组类型为true，反之为false。 |  
    
 **示例代码：**   
```ts    
let that = new util.types();  let result = that.isInt8Array(new Int8Array([]));    
```    
  
    
### isInt16Array<sup>(8+)</sup>    
检查输入的value是否是Int16Array数组类型。  
 **调用形式：**     
- isInt16Array(value: Object): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Object | true | 待检测对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 判断的结果，如果是内置包含的Int16Array数组类型为true，反之为false。 |  
    
 **示例代码：**   
```ts    
let that = new util.types();  let result = that.isInt16Array(new Int16Array([]));    
```    
  
    
### isInt32Array<sup>(8+)</sup>    
检查输入的value是否是Int32Array数组类型。  
 **调用形式：**     
- isInt32Array(value: Object): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Object | true | 待检测对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 判断的结果，如果是内置包含的Int32Array数组类型为true，反之为false。 |  
    
 **示例代码：**   
```ts    
let that = new util.types();  let result = that.isInt32Array(new Int32Array([]));    
```    
  
    
### isMap<sup>(8+)</sup>    
检查输入的value是否是Map类型。  
 **调用形式：**     
- isMap(value: Object): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Object | true | 待检测对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 判断的结果，如果是内置包含的Map类型为true，反之为false。 |  
    
 **示例代码：**   
```ts    
et that = new util.types();  let result = that.isMap(new Map());    
```    
  
    
### isMapIterator<sup>(8+)</sup>    
检查输入的value是否是Map的Iterator类型。  
 **调用形式：**     
- isMapIterator(value: Object): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Object | true | 待检测对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 判断的结果，如果是内置包含的Map的Iterator类型为true，反之为false。 |  
    
 **示例代码：**   
```ts    
let that = new util.types();  const map : Map<number,number> = new Map();  let result = that.isMapIterator(map.keys());    
```    
  
    
### isModuleNamespaceObject<sup>(8+)</sup>    
检查输入的value是否是Module Namespace Object类型。  
 **调用形式：**     
- isModuleNamespaceObject(value: Object): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Object | true | 待检测对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 判断的结果，如果是内置包含的Module |  
    
 **示例代码：**   
```ts    
import url from '@ohos.url'  let that = new util.types();  let result = that.isModuleNamespaceObject(url);    
```    
  
    
### isNativeError<sup>(8+)</sup>    
检查输入的value是否是Error类型。  
 **调用形式：**     
- isNativeError(value: Object): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Object | true | 待检测对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 判断的结果，如果是内置包含的Error类型为true，反之为false。 |  
    
 **示例代码：**   
```ts    
let that = new util.types();  let result = that.isNativeError(new TypeError());    
```    
  
    
### isNumberObject<sup>(8+)</sup>    
检查输入的value是否是Number对象类型。  
 **调用形式：**     
- isNumberObject(value: Object): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Object | true | 待检测对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 判断的结果，如果是内置包含的Number对象类型为true，反之为false。 |  
    
 **示例代码：**   
```ts    
let that = new util.types();  let result = that.isNumberObject(new Number(0));    
```    
  
    
### isPromise<sup>(8+)</sup>    
检查输入的value是否是Promise类型。  
 **调用形式：**     
- isPromise(value: Object): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Object | true | 待检测对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 判断的结果，如果是内置包含的Promise类型为true，反之为false。 |  
    
 **示例代码：**   
```ts    
let that = new util.types();  let result = that.isPromise(Promise.resolve(1));    
```    
  
    
### isProxy<sup>(8+)</sup>    
检查输入的value是否是Proxy类型。  
 **调用形式：**     
- isProxy(value: Object): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Object | true | 待检测对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 判断的结果，如果是内置包含的Proxy类型为true，反之为false。 |  
    
 **示例代码：**   
```ts    
class Target{  }  let that = new util.types();  const target : Target = {};  const proxy = new Proxy(target, target);  let result = that.isProxy(proxy);    
```    
  
    
### isRegExp<sup>(8+)</sup>    
检查输入的value是否是RegExp类型。  
 **调用形式：**     
- isRegExp(value: Object): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Object | true | 待检测对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 判断的结果，如果是内置包含的RegExp类型为true，反之为false。 |  
    
 **示例代码：**   
```ts    
let that = new util.types();  let result = that.isRegExp(new RegExp('abc'));    
```    
  
    
### isSet<sup>(8+)</sup>    
检查输入的value是否是Set类型。  
 **调用形式：**     
- isSet(value: Object): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Object | true | 待检测对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 判断的结果，如果是内置包含的Set类型为true，反之为false。 |  
    
 **示例代码：**   
```ts    
let that = new util.types();  let set : Set<number> = new Set();  let result = that.isSet(set);    
```    
  
    
### isSetIterator<sup>(8+)</sup>    
检查输入的value是否是Set的Iterator类型。  
 **调用形式：**     
- isSetIterator(value: Object): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Object | true | 待检测对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 判断的结果，如果是内置包含的Set的Iterator类型为true，反之为false。 |  
    
 **示例代码：**   
```ts    
let that = new util.types();  const set : Set<number> = new Set();  let result = that.isSetIterator(set.keys());    
```    
  
    
### isSharedArrayBuffer<sup>(8+)</sup>    
检查输入的value是否是SharedArrayBuffer类型。  
 **调用形式：**     
- isSharedArrayBuffer(value: Object): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Object | true | 待检测对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 判断的结果，如果是内置包含的SharedArrayBuffer类型为true，反之为false。 |  
    
 **示例代码：**   
```ts    
let that = new util.types();  let result = that.isSharedArrayBuffer(new SharedArrayBuffer(0));    
```    
  
    
### isStringObject<sup>(8+)</sup>    
检查输入的value是否是String对象类型。  
 **调用形式：**     
- isStringObject(value: Object): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Object | true | 待检测对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 判断的结果，如果是内置包含的String对象类型为true，反之为false。 |  
    
 **示例代码：**   
```ts    
let that = new util.types();  let result = that.isStringObject(new String('foo'));    
```    
  
    
### isSymbolObject<sup>(8+)</sup>    
检查输入的value是否是Symbol对象类型。  
 **调用形式：**     
- isSymbolObject(value: Object): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Object | true | 待检测对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 判断的结果，如果是内置包含的Symbol对象类型为true，反之为false。 |  
    
 **示例代码：**   
```ts    
let that = new util.types();  const symbols = Symbol('foo');  let result = that.isSymbolObject(Object(symbols));    
```    
  
    
### isTypedArray<sup>(8+)</sup>    
检查输入的value是否是TypedArray类型的辅助类型。TypedArray类型的辅助类型，包括Int8Array、Int16Array、Int32Array、Uint8Array、Uint8ClampedArray、Uint16Array、Uint32Array、Float32Array、Float64Array、DataView。  
 **调用形式：**     
- isTypedArray(value: Object): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Object | true | 待检测对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 判断的结果，如果是内置包含的TypedArray包含的类型为true，反之为false。 |  
    
 **示例代码：**   
```ts    
let that = new util.types();  let result = that.isTypedArray(new Float64Array([]));    
```    
  
    
### isUint8Array<sup>(8+)</sup>    
检查输入的value是否是Uint8Array数组类型。  
 **调用形式：**     
- isUint8Array(value: Object): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Object | true | 待检测对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 判断的结果，如果是内置包含的Uint8Array数组类型为true，反之为false。 |  
    
 **示例代码：**   
```ts    
let that = new util.types();  let result = that.isUint8Array(new Uint8Array([]));    
```    
  
    
### isUint8ClampedArray<sup>(8+)</sup>    
检查输入的value是否是Uint8ClampedArray数组类型。  
 **调用形式：**     
- isUint8ClampedArray(value: Object): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Object | true | 待检测对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 判断的结果，如果是内置包含的Uint8ClampedArray数组类型为true，反之为false。 |  
    
 **示例代码：**   
```ts    
let that = new util.types();  let result = that.isUint8ClampedArray(new Uint8ClampedArray([]));    
```    
  
    
### isUint16Array<sup>(8+)</sup>    
检查输入的value是否是Uint16Array数组类型。  
 **调用形式：**     
- isUint16Array(value: Object): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Object | true | 待检测对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 判断的结果，如果是内置包含的Uint16Array数组类型为true，反之为false。 |  
    
 **示例代码：**   
```ts    
let that = new util.types();  let result = that.isUint16Array(new Uint16Array([]));    
```    
  
    
### isUint32Array<sup>(8+)</sup>    
检查输入的value是否是Uint32Array数组类型。  
 **调用形式：**     
- isUint32Array(value: Object): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Object | true | 待检测对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 判断的结果，如果是内置包含的Uint32Array数组类型为true，反之为false。 |  
    
 **示例代码：**   
```ts    
let that = new util.types();  let result = that.isUint32Array(new Uint32Array([]));    
```    
  
    
### isWeakMap<sup>(8+)</sup>    
检查输入的value是否是WeakMap类型。  
 **调用形式：**     
- isWeakMap(value: Object): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Object | true | 待检测对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 判断的结果，如果是内置包含的WeakMap类型为true，反之为false。 |  
    
 **示例代码：**   
```ts    
let that = new util.types();  let value : WeakMap<object,number> = new WeakMap();  let result = that.isWeakMap(value);    
```    
  
    
### isWeakSet<sup>(8+)</sup>    
检查输入的value是否是WeakSet类型。  
 **调用形式：**     
- isWeakSet(value: Object): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Object | true | 待检测对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 判断的结果，如果是内置包含的WeakSet类型为true，反之为false。 |  
    
 **示例代码：**   
```ts    
let that = new util.types();  let result = that.isWeakSet(new WeakSet());    
```    
  
