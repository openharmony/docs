# util工具函数

该模块主要提供常用的工具函数，实现字符串编解码（TextEncoder，TextDecoder）、有理数运算（RationalNumber）、缓冲区管理（LruBuffer）、范围判断（Scope）、Base64编解码（Base64）、内置对象类型检查（Types）等功能。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```js
import util from '@ohos.util';
```

## util.format<sup>9+</sup>

format(format: string,  ...args: Object[]): string

通过式样化字符串对输入的内容按特定格式输出。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名  | 类型     | 必填 | 说明           |
| ------- | -------- | ---- | -------------- |
| format  | string   | 是   | 式样化字符串。 |
| ...args | Object[] | 否   | 替换式样化字符串通配符的数据。  |

**返回值：**

| 类型   | 说明                         |
| ------ | ---------------------------- |
| string | 按特定格式式样化后的字符串。 |

**示例：**

  ```js
let res = util.format("%s", "hello world!");
console.log(res);
  ```

## util.printf<sup>(deprecated)</sup>

printf(format: string,  ...args: Object[]): string

通过式样化字符串对输入的内容按特定格式输出。

> **说明：**
>
> 从API Version 7开始支持，从API Version 9开始废弃，建议使用[util.format<sup>9+</sup>](#utilformat9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| format | string | 是 | 式样化字符串。 |
| ...args | Object[] | 否 | 替换式样化字符串通配符的数据。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 按特定格式式样化后的字符串。 |

**示例：**

  ```js
  let res = util.printf("%s", "hello world!");
  console.log(res);
  ```

## util.errnoToString<sup>9+</sup>

errnoToString(errno: number): string

获取系统错误码对应的详细信息。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| errno  | number | 是   | 系统发生错误产生的错误码。 |

**返回值：**

| 类型   | 说明                   |
| ------ | ---------------------- |
| string | 错误码对应的详细信息。 |

**示例：**

```js
let errnum = 10; // 10 : a system error number
let result = util.errnoToString(errnum);
console.log("result = " + result);
```

## util.getErrorString<sup>(deprecated)</sup>

getErrorString(errno: number): string

获取系统错误码对应的详细信息。

> **说明：**
>
> 从API Version 7开始支持，从API Version 9开始废弃，建议使用[util.errnoToString<sup>9+</sup>](#utilerrnotostring9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| errno | number | 是 | 系统发生错误产生的错误码。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 错误码对应的详细信息。 |

**示例：**

  ```js
  let errnum = 10; // 10 : a system error number
  let result = util.getErrorString(errnum);
  console.log("result = " + result);
  ```

## util.callbackWrapper

callbackWrapper(original: Function): (err: Object, value: Object )=&gt;void

对异步函数进行回调化处理，回调中第一个参数将是拒绝原因（如果 Promise 已解决，则为 null），第二个参数将是已解决的值。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| original | Function | 是 | 异步函数。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Function | 返回一个第一个参数是拒绝原因（如果&nbsp;Promise&nbsp;已解决，则为&nbsp;null），第二个参数是已解决的回调函数。 |

**示例：**

  ```js
  async function promiseFn() {
      return Promise.reject('value');
  }
  let err = "type err";
  let cb = util.callbackWrapper(promiseFn);
  cb((err, ret) => {
      console.log(err);
      console.log(ret);
  }, err)
  ```

## util.promisify<sup>9+</sup>

promisify(original: (err: Object, value: Object) =&gt; void): Function

对异步函数处理并返回一个promise的函数。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| original | Function | 是 | 异步函数。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Function | 采用遵循常见的错误优先的回调风格的函数（也就是将&nbsp;(err,&nbsp;value)&nbsp;=&gt;&nbsp;...&nbsp;回调作为最后一个参数），并返回一个返回&nbsp;promise&nbsp;的函数。 |

**示例：**

  ```js
  function aysnFun(str1, str2) {
    if (typeof str1 === 'object' && typeof str2 === 'object') {
      return str2
    } else {
      return str1
    }
  }
  let newPromiseObj = util.promisify(aysnFun);
  newPromiseObj({ err: "type error" }, {value:'HelloWorld'}).then(res => {
    console.log(res);
  })
  ```

## util.promiseWrapper<sup>(deprecated)</sup>

promiseWrapper(original: (err: Object, value: Object) =&gt; void): Object

对异步函数处理并返回一个promise的版本。

> **说明：**
>
> 此接口不可用，建议使用[util.promisify<sup>9+</sup>](#utilpromisify9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| original | Function | 是 | 异步函数。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Function | 采用遵循常见的错误优先的回调风格的函数（也就是将&nbsp;(err,&nbsp;value)&nbsp;=&gt;&nbsp;...&nbsp;回调作为最后一个参数），并返回一个返回&nbsp;promise&nbsp;的版本。 |

## util.randomUUID<sup>9+</sup>

randomUUID(entropyCache?: boolean): string

使用加密安全随机数生成器生成随机的RFC 4122版本4的 UUID。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| entropyCache | boolean | 否 | 是否使用已缓存的UUID， 默认true。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 表示此UUID的字符串。 |

**示例：**

  ```js
  let uuid = util.randomUUID(true);
  console.log("RFC 4122 Version 4 UUID:" + uuid);
  // 输出：
  // RFC 4122 Version 4 UUID:88368f2a-d5db-47d8-a05f-534fab0a0045
  ```

## util.randomBinaryUUID<sup>9+</sup>

randomBinaryUUID(entropyCache?: boolean): Uint8Array

使用加密安全随机数生成器生成随机的RFC 4122版本4的 UUID。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| entropyCache | boolean | 否 | 是否使用已缓存的UUID， 默认true。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Uint8Array | 表示此UUID的Uint8Array值。 |

**示例：**

  ```js
  let uuid = util.randomBinaryUUID(true);
  console.log(JSON.stringify(uuid));
  // 输出：
  // 138,188,43,243,62,254,70,119,130,20,235,222,199,164,140,150
  ```

## util.parseUUID<sup>9+</sup>

parseUUID(uuid: string): Uint8Array

从字符串中解析UUID，如RFC 4122版本4中所述。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| uuid | string | 是 | UUID字符串。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Uint8Array | 返回表示此UUID的Uint8Array，如果解析失败，则抛出SyntaxError。 |

**示例：**

  ```js
  let uuid = util.parseUUID("84bdf796-66cc-4655-9b89-d6218d100f9c");
  console.log(JSON.stringify(uuid));
  // 输出：
  // 132,189,247,150,102,204,70,85,155,137,214,33,141,16,15,156
  ```

## TextDecoder

### 属性

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Utils.Lang。

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| encoding | string | 是 | 否 | 编码格式。<br/>-&nbsp;支持格式：utf-8、ibm866、iso-8859-2、iso-8859-3、iso-8859-4、iso-8859-5、iso-8859-6、iso-8859-7、iso-8859-8、iso-8859-8-i、iso-8859-10、iso-8859-13、iso-8859-14、iso-8859-15、koi8-r、koi8-u、macintosh、windows-874、windows-1250、windows-1251、windows-1252、windows-1253、windows-1254、windows-1255、windows-1256、windows-1257、windows-1258、x-mac-cyrilli、gbk、gb18030、big5、euc-jp、iso-2022-jp、shift_jis、euc-kr、utf-16be、utf-16le。 |
| fatal | boolean | 是 | 否 | 是否显示致命错误。 |
| ignoreBOM | boolean | 是 | 否 | 是否忽略BOM（byte&nbsp;order&nbsp;marker）标记，默认值为false&nbsp;，表示解码结果包含BOM标记。 |

### constructor<sup>9+</sup>

constructor()

TextDecoder的构造函数。

**系统能力：** SystemCapability.Utils.Lang

### create<sup>9+</sup>

create(encoding?: string,options?: { fatal?: boolean; ignoreBOM?: boolean },): TextDecoder;

替代有参构造功能。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名   | 类型   | 必填 | 说明                                             |
| -------- | ------ | ---- | ------------------------------------------------ |
| encoding | string | 否   | 编码格式。                                       |
| options  | Object | 否   | 编码相关选项参数，存在两个属性fatal和ignoreBOM。 |

**表1.1**options

| 名称      | 参数类型 | 必填 | 说明               |
| --------- | -------- | ---- | ------------------ |
| fatal     | boolean  | 否   | 是否显示致命错误。 |
| ignoreBOM | boolean  | 否   | 是否忽略BOM标记。  |

**示例：**

```js
let textDecoder = new util.TextDecoder()
textDecoder.create('utf-8', { ignoreBOM : true });
```

### constructor<sup>(deprecated)</sup>

constructor(encoding?: string, options?: { fatal?: boolean; ignoreBOM?: boolean },)

TextDecoder的构造函数。

> **说明：**
>
> 从API Version 7开始支持，从API Version 9开始废弃，建议使用[constructor<sup>9+</sup>](#constructor9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| encoding | string | 否 | 编码格式。 |
| options | Object | 否 | 编码相关选项参数，存在两个属性fatal和ignoreBOM。 |

  **表1** options

| 名称 | 参数类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| fatal | boolean | 否 | 是否显示致命错误。 |
| ignoreBOM | boolean | 否 | 是否忽略BOM标记。 |

**示例：**

  ```js
  let textDecoder = new util.TextDecoder("utf-8",{ignoreBOM: true});
  ```

### decode

decode(input: Uint8Array, options?: { stream?: false }): string

通过输入参数解码后输出对应文本。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| input | Uint8Array | 是 | 符合格式需要解码的数组。 |
| options | Object | 否 | 解码相关选项参数。 |

**表2** options

| 名称 | 参数类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| stream | boolean | 否 | 在随后的decode()调用中是否跟随附加数据块。如果以块的形式处理数据，则设置为true；如果处理最后的数据块或数据未分块，则设置为false。默认为false。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 解码后的数据。 |

**示例：**

  ```js
  let textDecoder = new util.TextDecoder("utf-8",{ignoreBOM: true});
  let result = new Uint8Array(6);
  result[0] = 0xEF;
  result[1] = 0xBB;
  result[2] = 0xBF;
  result[3] = 0x61;
  result[4] = 0x62;
  result[5] = 0x63;
  console.log("input num:");
  let retStr = textDecoder.decode( result , {stream: false});
  console.log("retStr = " + retStr);
  ```


### decodeWithStream<sup>9+</sup>

decodeWithStream(input: Uint8Array, options?: { stream?: boolean }): string

通过输入参数解码后输出对应文本。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| input | Uint8Array | 是 | 符合格式需要解码的数组。 |
| options | Object | 否 | 解码相关选项参数。 |

**表2** options

| 名称 | 参数类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| stream | boolean | 否 | 在随后的decodeWithStream()调用中是否跟随附加数据块。如果以块的形式处理数据，则设置为true；如果处理最后的数据块或数据未分块，则设置为false。默认为false。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 解码后的数据。 |

**示例：**

  ```js
  let textDecoder = new util.TextDecoder("utf-8",{ignoreBOM: true});
  let result = new Uint8Array(6);
  result[0] = 0xEF;
  result[1] = 0xBB;
  result[2] = 0xBF;
  result[3] = 0x61;
  result[4] = 0x62;
  result[5] = 0x63;
  console.log("input num:");
  let retStr = textDecoder.decodeWithStream( result , {stream: false});
  console.log("retStr = " + retStr);
  ```


## TextEncoder

### 属性

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Utils.Lang。

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| encoding | string | 是 | 否 | 编码格式，默认值是utf-8。 |


### constructor

constructor()

TextEncoder的构造函数。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

  ```js
  let textEncoder = new util.TextEncoder();
  ```

### encodeInto<sup>9+</sup>

encodeInto(input?: string): Uint8Array

通过输入参数编码后输出对应文本。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| input  | string | 否   | 需要编码的字符串。 |

**返回值：**

| 类型       | 说明               |
| ---------- | ------------------ |
| Uint8Array | 返回编码后的文本。 |

**示例：**

  ```js
let textEncoder = new util.TextEncoder();
let buffer = new ArrayBuffer(20);
let result = new Uint8Array(buffer);
result = textEncoder.encodeInto("\uD800¥¥");
  ```

### encode<sup>(deprecated)</sup>

encode(input?: string): Uint8Array

通过输入参数编码后输出对应文本。

> **说明：**
>
> 从API Version 7开始支持，从API Version 9开始废弃，建议使用[encodeInto<sup>9+</sup>](#encodeinto9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| input | string | 否 | 需要编码的字符串。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Uint8Array | 返回编码后的文本。 |

**示例：**
  ```js
  let textEncoder = new util.TextEncoder();
  let buffer = new ArrayBuffer(20);
  let result = new Uint8Array(buffer);
  result = textEncoder.encode("\uD800¥¥");
  ```

### encodeIntoUint8Array<sup>9+</sup>

encodeIntoUint8Array(input: string, dest: Uint8Array, ): { read: number; written: number }

放置生成的UTF-8编码文本。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型       | 必填 | 说明                                                    |
| ------ | ---------- | ---- | ------------------------------------------------------- |
| input  | string     | 是   | 需要编码的字符串。                                      |
| dest   | Uint8Array | 是   | Uint8Array对象实例，用于将生成的UTF-8编码文本放入其中。 |

**返回值：**

| 类型       | 说明               |
| ---------- | ------------------ |
| Uint8Array | 返回编码后的文本。 |

**示例：**

  ```js
let that = new util.TextEncoder()
let buffer = new ArrayBuffer(4)
let dest = new Uint8Array(buffer)
let result = new Object()
result = that.encodeInto('abcd', dest)
  ```

### encodeInto<sup>(deprecated)</sup>

encodeInto(input: string, dest: Uint8Array, ): { read: number; written: number }

放置生成的UTF-8编码文本。

> **说明：**
>
> 从API Version 7开始支持，从API Version 9开始废弃，建议使用[encodeIntoUint8Array<sup>9+</sup>](#encodeintouint8array9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| input | string | 是 | 需要编码的字符串。 |
| dest | Uint8Array | 是 | Uint8Array对象实例，用于将生成的UTF-8编码文本放入其中。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Uint8Array | 返回编码后的文本。 |

**示例：**
  ```js
  let that = new util.TextEncoder()
  let buffer = new ArrayBuffer(4)
  let dest = new Uint8Array(buffer)
  let result = new Object()
  result = that.encodeInto('abcd', dest)
  ```

## RationalNumber<sup>8+</sup>

### constructor<sup>9+</sup>

constructor()

RationalNumber的构造函数。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

```js
let rationalNumber = new util.RationalNumber();
```

### parseRationalNumber<sup>9+</sup>

parseRationalNumber(numerator: number,denominator: number): RationalNumber

替代原有参构造的参数处理。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名      | 类型   | 必填 | 说明             |
| ----------- | ------ | ---- | ---------------- |
| numerator   | number | 是   | 分子，整数类型。 |
| denominator | number | 是   | 分母，整数类型。 |

**示例：**

```js
let rationalNumber = new util.RationalNumber();
rationalNumber.parseRationalNumber(1,2)
```

### constructor<sup>(deprecated)</sup>

constructor(numerator: number,denominator: number)

RationalNumber的构造函数。

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[constructor<sup>9+</sup>](#constructor9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| numerator | number | 是 | 分子，整数类型。 |
| denominator | number | 是 | 分母，整数类型。 |

**示例：**

```js
let rationalNumber = new util.RationalNumber(1,2);
```

### createRationalFromString<sup>8+</sup>

static createRationalFromString​(rationalString: string): RationalNumber​

基于给定的字符串创建一个RationalNumber对象。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| rationalString | string | 是 | 字符串格式。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| object | 返回有理数类的对象。 |

**示例：**

```js
let rationalNumber = new util.RationalNumber(1,2);
let rational = util.RationalNumber.createRationalFromString("3/4");
```

### compare<sup>9+</sup>

compare​(another: RationalNumber): number​

将当前的RationalNumber对象与给定的对象进行比较。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名  | 类型           | 必填 | 说明               |
| ------- | -------------- | ---- | ------------------ |
| another | RationalNumber | 是   | 其他的有理数对象。 |

**返回值：**

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| number | 如果两个对象相等，则返回0；如果给定对象小于当前对象，则返回1；如果给定对象大于当前对象，则返回-1。 |

**示例：**

  ```js
let rationalNumber = new util.RationalNumber(1,2);
let rational = util.RationalNumber.createRationalFromString("3/4");
let result = rationalNumber.compare(rational);
  ```

### compareTo<sup>(deprecated)</sup>

compareTo​(another: RationalNumber): number​

将当前的RationalNumber对象与给定的对象进行比较。

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[compare<sup>9+</sup>](#compare9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| another | RationalNumber | 是 | 其他的有理数对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 如果两个对象相等，则返回0；如果给定对象小于当前对象，则返回1；如果给定对象大于当前对象，则返回-1。 |

**示例：**

```js
let rationalNumber = new util.RationalNumber(1,2);
let rational = util.RationalNumber.createRationalFromString("3/4");
let result = rationalNumber.compareTo(rational);
```

### valueOf<sup>8+</sup>

valueOf(): number

以整数形式或者浮点数的形式获取当前RationalNumber对象的值。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回整数或者浮点数的值。 |

**示例：**

```js
let rationalNumber = new util.RationalNumber(1,2);
let result = rationalNumber.valueOf();
```

### equals<sup>8+</sup>

equals​(obj: Object): boolean

将当前的RationalNumber对象与给定的对象进行比较是否相等。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| object | Object | 是 | 其他类型对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果给定对象与当前对象相同，则返回true；否则返回false。 |

**示例：**

```js
let rationalNumber = new util.RationalNumber(1,2);
let rational = util.RationalNumber.createRationalFromString("3/4");
let result = rationalNumber.equals(rational);
```

### getCommonFactor<sup>9+</sup>

getCommonFactor(number1: number,number2: number): number

获取两个指定整数的最大公约数。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名  | 类型   | 必填 | 说明       |
| ------- | ------ | ---- | ---------- |
| number1 | number | 是   | 整数类型。 |
| number2 | number | 是   | 整数类型。 |

**返回值：**

| 类型   | 说明                           |
| ------ | ------------------------------ |
| number | 返回两个给定数字的最大公约数。 |

**示例：**

```js
let rationalNumber = new util.RationalNumber(1,2);
let result = util.RationalNumber.getCommonFactor(4,6);
```

### getCommonDivisor<sup>(deprecated)</sup>

static getCommonDivisor​(number1: number,number2: number): number

获取两个指定整数的最大公约数。

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[getCommonFactor<sup>9+</sup>](#getcommonfactor9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| number1 | number | 是 | 整数类型。 |
| number2 | number | 是 | 整数类型。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回两个给定数字的最大公约数。 |

**示例：**

```js
let rationalNumber = new util.RationalNumber(1,2);
let result = util.RationalNumber.getCommonDivisor(4,6);
```

### getNumerator<sup>8+</sup>

getNumerator​(): number

获取当前RationalNumber对象的分子。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回RationalNumber对象的分子的值。 |

**示例：**

```js
let rationalNumber = new util.RationalNumber(1,2);
let result = rationalNumber.getNumerator();
```

### getDenominator<sup>8+</sup>

getDenominator​(): number

获取当前RationalNumber对象的分母。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回RationalNumber对象的分母的值。 |

**示例：**

```js
let rationalNumber = new util.RationalNumber(1,2);
lett result = rationalNumber.getDenominator();
```

### isZero<sup>8+</sup>

isZero​():boolean

检查当前RationalNumber对象是否为0。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果当前对象表示的值为0，则返回true；否则返回false。 |

**示例：**

```js
let rationalNumber = new util.RationalNumber(1,2);
let result = rationalNumber.isZero();
```

### isNaN<sup>8+</sup>

isNaN​(): boolean

检查当前RationalNumber对象是否表示非数字(NaN)值。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果分母和分子都为0，则返回true；否则返回false。 |

**示例：**

```js
let rationalNumber = new util.RationalNumber(1,2);
let result = rationalNumber.isNaN();
```

### isFinite<sup>8+</sup>

isFinite​():boolean

检查当前RationalNumber对象是否表示一个有限值。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果分母不为0，则返回true；否则返回false。 |

**示例：**

```js
let rationalNumber = new util.RationalNumber(1,2);
let result = rationalNumber.isFinite();
```

### toString<sup>8+</sup>

toString​(): string

获取当前RationalNumber对象的字符串表示形式。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 返回Numerator/Denominator格式的字符串，例如3/5，如果当前对象的分子和分母都为0，则返回NaN。 |

**示例：**

```js
let rationalNumber = new util.RationalNumber(1,2);
let result = rationalNumber.toString();
```


## LRUCache<sup>9+</sup>

### 属性

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Utils.Lang。

| 名称   | 类型   | 可读 | 可写 | 说明                   |
| ------ | ------ | ---- | ---- | ---------------------- |
| length | number | 是   | 否   | 当前缓冲区中值的总数。 |

**示例：**

```js
let pro = new util.LRUCache();
pro.put(2,10);
pro.put(1,8);
let result = pro.length;
```

### constructor<sup>9+</sup>

constructor(capacity?: number)

默认构造函数用于创建一个新的LruBuffer实例，默认容量为64。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名   | 类型   | 必填 | 说明                         |
| -------- | ------ | ---- | ---------------------------- |
| capacity | number | 否   | 指示要为缓冲区自定义的容量。 |

**示例：**

```js
let lrubuffer= new util.LRUCache();
```


### updateCapacity<sup>9+</sup>

updateCapacity(newCapacity: number): void

将缓冲区容量更新为指定容量，如果newCapacity小于或等于0，则抛出异常。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名      | 类型   | 必填 | 说明                         |
| ----------- | ------ | ---- | ---------------------------- |
| newCapacity | number | 是   | 指示要为缓冲区自定义的容量。 |

**示例：**

```js
let pro = new util.LRUCache();
let result = pro.updateCapacity(100);
```


### toString<sup>9+</sup>

toString(): string

返回对象的字符串表示形式。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明                       |
| ------ | -------------------------- |
| string | 返回对象的字符串表示形式。 |

**示例：**

```js
let pro = new util.LRUCache();
pro.put(2,10);
pro.get(2);
pro.remove(20);
let result = pro.toString();
```


### getCapacity<sup>9+</sup>

getCapacity(): number

获取当前缓冲区的容量。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明                   |
| ------ | ---------------------- |
| number | 返回当前缓冲区的容量。 |

**示例：**

  ```js
let pro = new util.LRUCache();
let result = pro.getCapacity();
  ```


### clear<sup>9+</sup>

clear(): void

从当前缓冲区清除键值对。后续会调用afterRemoval()方法执行后续操作。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

  ```js
let pro = new util.LRUCache();
pro.put(2,10);
let result = pro.length;
pro.clear();
  ```


### getCreateCount<sup>9+</sup>

getCreateCount(): number

获取createDefault()返回值的次数。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明                              |
| ------ | --------------------------------- |
| number | 返回createDefault()返回值的次数。 |

**示例：**

  ```js
let pro = new util.LRUCache();
pro.put(1,8);
let result = pro.getCreateCount();
  ```


### getMissCount<sup>9+</sup>

getMissCount(): number

获取查询值不匹配的次数。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| number | 返回查询值不匹配的次数。 |

**示例：**

  ```js
let pro = new util.LRUCache();
pro.put(2,10);
pro.get(2);
let result = pro.getMissCount();
  ```


### getRemovalCount<sup>9+</sup>

getRemovalCount(): number

获取从缓冲区中逐出值的次数。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明                       |
| ------ | -------------------------- |
| number | 返回从缓冲区中驱逐的次数。 |

**示例：**

  ```js
let pro = new util.LRUCache();
pro.put(2,10);
pro.updateCapacity(2);
pro.put(50,22);
let result = pro.getRemovalCount();
  ```


### getMatchCount<sup>9+</sup>

getMatchCount(): number

获取查询值匹配成功的次数。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明                       |
| ------ | -------------------------- |
| number | 返回查询值匹配成功的次数。 |

**示例：**

  ```js
let pro = new util.LRUCache();
pro.put(2,10);
pro.get(2);
let result = pro.getMatchCount();
  ```


### getPutCount<sup>9+</sup>

getPutCount(): number

获取将值添加到缓冲区的次数。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明                         |
| ------ | ---------------------------- |
| number | 返回将值添加到缓冲区的次数。 |

**示例：**

  ```js
let pro = new util.LRUCache();
pro.put(2,10);
let result = pro.getPutCount();
  ```


### isEmpty<sup>9+</sup>

isEmpty(): boolean

检查当前缓冲区是否为空。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型    | 说明                                     |
| ------- | ---------------------------------------- |
| boolean | 如果当前缓冲区不包含任何值，则返回true。 |

**示例：**

  ```js
let pro = new util.LRUCache();
pro.put(2,10);
let result = pro.isEmpty();
  ```


### get<sup>9+</sup>

get(key: K): V | undefined

表示要查询的键。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明         |
| ------ | ---- | ---- | ------------ |
| key    | K    | 是   | 要查询的键。 |

**返回值：**

| 类型                     | 说明                                                         |
| ------------------------ | ------------------------------------------------------------ |
| V \| undefined | 如果指定的键存在于缓冲区中，则返回与键关联的值；否则返回undefined。 |

**示例：**

  ```js
let pro = new util.LRUCache();
pro.put(2,10);
let result  = pro.get(2);
  ```


### put<sup>9+</sup>

put(key: K,value: V): V

将键值对添加到缓冲区。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明                       |
| ------ | ---- | ---- | -------------------------- |
| key    | K    | 是   | 要添加的密钥。             |
| value  | V    | 是   | 指示与要添加的键关联的值。 |

**返回值：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| V    | 返回与添加的键关联的值；如果要添加的键已经存在，则返回原始值，如果键或值为空，则抛出此异常。 |

**示例：**

  ```js
let pro = new util.LRUCache();
let result = pro.put(2,10);
  ```

### values<sup>9+</sup>

values(): V[]

获取当前缓冲区中所有值从最近访问到最近最少访问的顺序列表 。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型      | 说明                                                         |
| --------- | ------------------------------------------------------------ |
| V&nbsp;[] | 按从最近访问到最近最少访问的顺序返回当前缓冲区中所有值的列表。 |

**示例：**

  ```js
let pro = new util.LRUCache();
pro.put(2,10);
pro.put(2,"anhu");
pro.put("afaf","grfb");
let result = pro.values();
  ```


### keys<sup>9+</sup>

keys(): K[]

获取当前缓冲区中所有键从最近访问到最近最少访问的升序列表。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型      | 说明                                                         |
| --------- | ------------------------------------------------------------ |
| K&nbsp;[] | 按升序返回当前缓冲区中所有键的列表，从最近访问到最近最少访问。 |

**示例：**

  ```js
let pro = new util.LRUCache();
pro.put(2,10);
let result = pro.keys();
  ```


### remove<sup>9+</sup>

remove(key: K): V | undefined

从当前缓冲区中删除指定的键及其关联的值。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明           |
| ------ | ---- | ---- | -------------- |
| key    | K    | 是   | 要删除的密钥。 |

**返回值：**

| 类型                     | 说明                                                         |
| ------------------------ | ------------------------------------------------------------ |
| V&nbsp;\|&nbsp;undefined | 返回一个包含已删除键值对的Optional对象；如果key不存在，则返回一个空的Optional对象，如果key为null，则抛出异常。 |

**示例：**

  ```js
let pro = new util.LRUCache();
pro.put(2,10);
let result = pro.remove(20);
  ```


### afterRemoval<sup>9+</sup>

afterRemoval(isEvict: boolean,key: K,value: V,newValue: V): void

删除值后执行后续操作。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名   | 类型    | 必填 | 说明                                                         |
| -------- | ------- | ---- | ------------------------------------------------------------ |
| isEvict  | boolean | 是   | 因容量不足而调用该方法时，参数值为true，其他情况为false。    |
| key      | K       | 是   | 表示删除的键。                                               |
| value    | V       | 是   | 表示删除的值。                                               |
| newValue | V       | 是   | 如果已调用put方法并且要添加的键已经存在，则参数值是关联的新值。其他情况下参数值为空。 |

**示例：**

  ```js
let arr = [];
class ChildLruBuffer<K, V> extends util.LRUCache<K, V>
{
	constructor()
	{
		super();
	}
	afterRemoval(isEvict, key, value, newValue)
	{
		if (isEvict === false)
		{
			arr = [key, value, newValue];
		}
	}
}
let lru = new ChildLruBuffer();
lru.afterRemoval(false,10,30,null);
  ```


### contains<sup>9+</sup>

contains(key: object): boolean

检查当前缓冲区是否包含指定的键。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明             |
| ------ | ------ | ---- | ---------------- |
| key    | object | 是   | 表示要检查的键。 |

**返回值：**

| 类型    | 说明                                       |
| ------- | ------------------------------------------ |
| boolean | 如果缓冲区包含指定的键，则返回&nbsp;true。 |

**示例：**

  ```js
let pro = new util.LRUCache();
pro.put(2,10);
let result = pro.contains(20);
  ```


### createDefault<sup>9+</sup>

createDefault(key: K): V

如果未计算特定键的值，则执行后续操作，参数表示丢失的键，返回与键关联的值。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明           |
| ------ | ---- | ---- | -------------- |
| key    | K    | 是   | 表示丢失的键。 |

**返回值：**

| 类型 | 说明               |
| ---- | ------------------ |
| V    | 返回与键关联的值。 |

**示例：**

  ```js
let pro = new util.LRUCache();
let result = pro.createDefault(50);
  ```


### entries<sup>9+</sup>

entries(): IterableIterator&lt;[K,V]&gt;

允许迭代包含在这个对象中的所有键值对。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型        | 说明                 |
| ----------- | -------------------- |
| [K,&nbsp;V] | 返回一个可迭代数组。 |

**示例：**

  ```js
let pro = new util.LRUCache();
pro.put(2,10);
let result = pro.entries();
  ```

### [Symbol.iterator]<sup>9+</sup>

[Symbol.iterator]\(): IterableIterator&lt;[K, V]&gt;

返回一个键值对形式的二维数组。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型        | 说明                           |
| ----------- | ------------------------------ |
| [K,&nbsp;V] | 返回一个键值对形式的二维数组。 |

**示例：**

  ```js
let pro = new util.LRUCache();
pro.put(2,10);
let result = pro[Symbol.iterator]();
  ```

## LruBuffer<sup>(deprecated)</sup>

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[LRUCache<sup>9+</sup>](#lrucache9)替代。

### 属性

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Utils.Lang。

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| length | number | 是 | 否 | 当前缓冲区中值的总数。 |

**示例：**

  ```js
  let pro = new util.LruBuffer();
  pro.put(2,10);
  pro.put(1,8);
  let result = pro.length;
  ```

### constructor<sup>(deprecated)</sup>

constructor(capacity?: number)

默认构造函数用于创建一个新的LruBuffer实例，默认容量为64。

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[constructor<sup>9+</sup>](#constructor9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| capacity | number | 否 | 指示要为缓冲区自定义的容量。 |

**示例：**

  ```js
  let lrubuffer= new util.LruBuffer();
  ```

### updateCapacity<sup>(deprecated)</sup>

updateCapacity(newCapacity: number): void

将缓冲区容量更新为指定容量，如果newCapacity小于或等于0，则抛出异常。

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[updateCapacity<sup>9+</sup>](#updatecapacity9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| newCapacity | number | 是 | 指示要为缓冲区自定义的容量。 |

**示例：**

  ```js
  let pro = new util.LruBuffer();
  let result = pro.updateCapacity(100);
  ```

### toString<sup>(deprecated)</sup>

toString(): string

返回对象的字符串表示形式。

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[toString<sup>9+</sup>](#tostring9)替代。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 返回对象的字符串表示形式。 |

**示例：**

  ```js
  let pro = new util.LruBuffer();
  pro.put(2,10);
  pro.get(2);
  pro.remove(20);
  let result = pro.toString();
  ```

### getCapacity<sup>(deprecated)</sup>

getCapacity(): number

获取当前缓冲区的容量。

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[getCapacity<sup>9+</sup>](#getcapacity9)替代。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回当前缓冲区的容量。 |

**示例：**
  ```js
  let pro = new util.LruBuffer();
  let result = pro.getCapacity();
  ```

### clear<sup>(deprecated)</sup>

clear(): void

从当前缓冲区清除键值对。后续会调用afterRemoval()方法执行后续操作。

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[clear<sup>9+</sup>](#clear9)替代。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

  ```js
  let pro = new util.LruBuffer();
  pro.put(2,10);
  let result = pro.length;
  pro.clear();
  ```

### getCreateCount<sup>(deprecated)</sup>

getCreateCount(): number

获取createDefault()返回值的次数。

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[getCreateCount<sup>9+</sup>](#getcreatecount9)替代。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回createDefault()返回值的次数。 |

**示例：**

  ```js
  let pro = new util.LruBuffer();
  pro.put(1,8);
  let result = pro.getCreateCount();
  ```

### getMissCount<sup>(deprecated)</sup>

getMissCount(): number

获取查询值不匹配的次数。

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[getMissCount<sup>9+</sup>](#getmisscount9)替代。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回查询值不匹配的次数。 |

**示例：**

  ```js
  let pro = new util.LruBuffer();
  pro.put(2,10);
  pro.get(2);
  let result = pro.getMissCount();
  ```

### getRemovalCount<sup>(deprecated)</sup>

getRemovalCount(): number

获取从缓冲区中逐出值的次数。

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[getRemovalCount<sup>9+</sup>](#getremovalcount9)替代。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回从缓冲区中驱逐的次数。 |

**示例：**

  ```js
  let pro = new util.LruBuffer();
  pro.put(2,10);
  pro.updateCapacity(2);
  pro.put(50,22);
  let result = pro.getRemovalCount();
  ```

### getMatchCount<sup>(deprecated)</sup>

getMatchCount(): number

获取查询值匹配成功的次数。

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[getMatchCount<sup>9+</sup>](#getmatchcount9)替代。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回查询值匹配成功的次数。 |

**示例：**

  ```js
  let pro = new util.LruBuffer();
  pro.put(2,10);
  pro.get(2);
  let result = pro.getMatchCount();
  ```

### getPutCount<sup>(deprecated)</sup>

getPutCount(): number

获取将值添加到缓冲区的次数。

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[getPutCount<sup>9+</sup>](#getputcount9)替代。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回将值添加到缓冲区的次数。 |

**示例：**

  ```js
  let pro = new util.LruBuffer();
  pro.put(2,10);
  let result = pro.getPutCount();
  ```

### isEmpty<sup>(deprecated)</sup>

isEmpty(): boolean

检查当前缓冲区是否为空。

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[isEmpty<sup>9+</sup>](#isempty9)替代。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果当前缓冲区不包含任何值，则返回true。 |

**示例：**

  ```js
  let pro = new util.LruBuffer();
  pro.put(2,10);
  let result = pro.isEmpty();
  ```

### get<sup>(deprecated)</sup>

get(key: K): V | undefined

表示要查询的键。

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[get<sup>9+</sup>](#get9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | K | 是 | 要查询的键。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| V&nbsp;\|&nbsp;undefined | 如果指定的键存在于缓冲区中，则返回与键关联的值；否则返回undefined。 |

**示例：**

  ```js
  let pro = new util.LruBuffer();
  pro.put(2,10);
  let result  = pro.get(2);
  ```

### put<sup>(deprecated)</sup>

put(key: K,value: V): V

将键值对添加到缓冲区。

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[put<sup>9+</sup>](#put9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | K | 是 | 要添加的密钥。 |
| value | V | 是 | 指示与要添加的键关联的值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| V | 返回与添加的键关联的值；如果要添加的键已经存在，则返回原始值，如果键或值为空，则抛出此异常。 |

**示例：**

  ```js
  let pro = new util.LruBuffer();
  let result = pro.put(2,10);
  ```

### values<sup>(deprecated)</sup>

values(): V[]

获取当前缓冲区中所有值从最近访问到最近最少访问的顺序列表。

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[values<sup>9+</sup>](#values9)替代。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| V&nbsp;[] | 按从最近访问到最近最少访问的顺序返回当前缓冲区中所有值的列表。 |

**示例：**

  ```js
  let pro = new util.LruBuffer();
  pro.put(2,10);
  pro.put(2,"anhu");
  pro.put("afaf","grfb");
  let result = pro.values();
  ```

### keys<sup>(deprecated)</sup>

keys(): K[]

获取当前缓冲区中所有键从最近访问到最近最少访问的升序列表。

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[keys<sup>9+</sup>](#keys9)替代。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| K&nbsp;[] | 按升序返回当前缓冲区中所有键的列表，从最近访问到最近最少访问。 |

**示例：**
  ```js
  let pro = new util.LruBuffer();
  pro.put(2,10);
  let result = pro.keys();
  ```

### remove<sup>(deprecated)</sup>

remove(key: K): V | undefined

从当前缓冲区中删除指定的键及其关联的值。

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[remove<sup>9+</sup>](#remove9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | K | 是 | 要删除的密钥。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| V&nbsp;\|&nbsp;undefined | 返回一个包含已删除键值对的Optional对象；如果key不存在，则返回一个空的Optional对象，如果key为null，则抛出异常。 |

**示例：**
  ```js
  let pro = new util.LruBuffer();
  pro.put(2,10);
  let result = pro.remove(20);
  ```

### afterRemoval<sup>(deprecated)</sup>

afterRemoval(isEvict: boolean,key: K,value: V,newValue: V): void

删除值后执行后续操作。

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[afterRemoval<sup>9+</sup>](#afterremoval9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| isEvict | boolean | 是 | 因容量不足而调用该方法时，参数值为true，其他情况为false。 |
| key | K | 是 | 表示删除的键。 |
| value | V | 是 | 表示删除的值。 |
| newValue | V | 是 | 如果已调用put方法并且要添加的键已经存在，则参数值是关联的新值。其他情况下参数值为空。 |

**示例：**

  ```js
  let arr = [];
  class ChildLruBuffer<K, V> extends util.LruBuffer<K, V>
  {
  	constructor()
  	{
  		super();
  	}
  	afterRemoval(isEvict, key, value, newValue)
  	{
  		if (isEvict === false)
  		{
  			arr = [key, value, newValue];
  		}
  	}
  }
  let lru = new ChildLruBuffer();
  lru.afterRemoval(false,10,30,null);
  ```

### contains<sup>(deprecated)</sup>

contains(key: K): boolean

检查当前缓冲区是否包含指定的键。


> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[contains<sup>9+</sup>](#contains9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | K | 是 | 表示要检查的键。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果缓冲区包含指定的键，则返回&nbsp;true。 |

**示例：**

  ```js
  let pro = new util.LruBuffer();
  pro.put(2,10);
  let result = pro.contains(20);
  ```

### createDefault<sup>(deprecated)</sup>

createDefault(key: K): V

如果未计算特定键的值，则执行后续操作，参数表示丢失的键，返回与键关联的值。

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[createDefault<sup>9+</sup>](#createdefault9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | K | 是 | 表示丢失的键。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| V | 返回与键关联的值。 |

**示例：**

  ```js
  let pro = new util.LruBuffer();
  let result = pro.createDefault(50);
  ```

### entries<sup>(deprecated)</sup>

entries(): IterableIterator&lt;[K,V]&gt;

允许迭代包含在这个对象中的所有键值对。

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[entries<sup>9+</sup>](#entries9)替代。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [K,&nbsp;V] | 返回一个可迭代数组。 |

**示例：**

  ```js
  let pro = new util.LruBuffer();
  pro.put(2,10);
  let result = pro.entries();
  ```

### [Symbol.iterator]<sup>(deprecated)</sup>

[Symbol.iterator]\(): IterableIterator&lt;[K, V]&gt;

返回一个键值对形式的二维数组。

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[Symbol.iterator<sup>9+</sup>](#symboliterator9)替代。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [K,&nbsp;V] | 返回一个键值对形式的二维数组。 |

**示例：**

  ```js
  let pro = new util.LruBuffer();
  pro.put(2,10);
  let result = pro[Symbol.iterator]();
  ```

### ScopeType<sup>8+</sup>

用于表示范围中的值的类型。该类型的值，类型可以为ScopeComparable或number。

ScopeComparable类型的值需要实现compareTo方法，确保传入的数据具有可比性。

```js
interface ScopeComparable{
    compareTo(other: ScopeComparable): boolean;
}
type ScopeType = ScopeComparable | number;
```


构造新类，实现compareTo方法。后续示例代码中，均通过Temperature，获取[ScopeType](#scopetype8)的实例化对象。


示例：
```js
class Temperature{
    constructor(value){
       // 当使用ts语言开发时，需要补充以下代码：
       // private readonly _temp: Temperature;
       this._temp = value;
    }
    compareTo(value){
       return this._temp >= value.getTemp();
    }
    getTemp(){
       return this._temp;
    }
    toString(){
       return this._temp.toString();
    }
}
```

## ScopeHelper<sup>9+</sup>

### constructor<sup>9+</sup>

constructor(lowerObj: ScopeType, upperObj: ScopeType)

用于创建指定下限和上限的作用域实例的构造函数，返回一个ScopeHelper对象。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名   | 类型                     | 必填 | 说明                   |
| -------- | ------------------------ | ---- | ---------------------- |
| lowerObj | [ScopeType](#scopetype8) | 是   | 指定作用域实例的下限。 |
| upperObj | [ScopeType](#scopetype8) | 是   | 指定作用域实例的上限。 |

**示例：**

  ```js
let tempLower = new Temperature(30);
let tempUpper = new Temperature(40);
let range = new util.ScopeHelper(tempLower, tempUpper);
  ```


### toString<sup>9+</sup>

toString(): string

该字符串化方法返回一个包含当前范围的字符串表示形式。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明                                   |
| ------ | -------------------------------------- |
| string | 返回包含当前范围对象的字符串表示形式。 |

**示例：**

  ```js
let tempLower = new Temperature(30);
let tempUpper = new Temperature(40);
let range = new util.ScopeHelper(tempLower, tempUpper);
let result = range.toString();
  ```


### intersect<sup>9+</sup>

intersect(range: ScopeHelper): ScopeHelper

获取给定范围和当前范围的交集。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型                         | 必填 | 说明               |
| ------ | ---------------------------- | ---- | ------------------ |
| range  | [ScopeHelper](#scopehelper9) | 是   | 传入一个给定范围。 |

**返回值：**

| 类型                           | 说明                           |
| ------------------------------ | ------------------------------ |
| [ScopeHelper9+](#scopehelper9) | 返回给定范围和当前范围的交集。 |

**示例：**

  ```js
let tempLower = new Temperature(30);
let tempUpper = new Temperature(40);
let range = new util.ScopeHelper(tempLower, tempUpper);
let tempMiDF = new Temperature(35);
let tempMidS = new Temperature(39);
let rangeFir = new util.ScopeHelper(tempMiDF, tempMidS);
range.intersect(rangeFir );
  ```


### intersect<sup>9+</sup>

intersect(lowerObj:ScopeType,upperObj:ScopeType):ScopeHelper

获取当前范围与给定下限和上限范围的交集。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名   | 类型                     | 必填 | 说明             |
| -------- | ------------------------ | ---- | ---------------- |
| lowerObj | [ScopeType](#scopetype8) | 是   | 给定范围的下限。 |
| upperObj | [ScopeType](#scopetype8) | 是   | 给定范围的上限。 |

**返回值：**

| 类型                         | 说明                                     |
| ---------------------------- | ---------------------------------------- |
| [ScopeHelper](#scopehelper9) | 返回当前范围与给定下限和上限范围的交集。 |

**示例：**

  ```js
let tempLower = new Temperature(30);
let tempUpper = new Temperature(40);
let tempMiDF = new Temperature(35);
let tempMidS = new Temperature(39);
let range = new util.ScopeHelper(tempLower, tempUpper);
let result = range.intersect(tempMiDF, tempMidS);
  ```


### getUpper<sup>9+</sup>

getUpper(): ScopeType

获取当前范围的上限。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型                     | 说明                   |
| ------------------------ | ---------------------- |
| [ScopeType](#scopetype8) | 返回当前范围的上限值。 |

**示例：**

  ```js
let tempLower = new Temperature(30);
let tempUpper = new Temperature(40);
let range = new util.ScopeHelper(tempLower, tempUpper);
let result = range.getUpper();
  ```


### getLower<sup>9+</sup>

getLower(): ScopeType

获取当前范围的下限。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型                     | 说明                   |
| ------------------------ | ---------------------- |
| [ScopeType](#scopetype8) | 返回当前范围的下限值。 |

**示例：**

  ```js
let tempLower = new Temperature(30);
let tempUpper = new Temperature(40);
let range = new util.ScopeHelper(tempLower, tempUpper);
let result = range.getLower();
  ```


### expand<sup>9+</sup>

expand(lowerObj: ScopeType,upperObj: ScopeType): ScopeHelper

创建并返回包括当前范围和给定下限和上限的并集。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名   | 类型                     | 必填 | 说明             |
| -------- | ------------------------ | ---- | ---------------- |
| lowerObj | [ScopeType](#scopetype8) | 是   | 给定范围的下限。 |
| upperObj | [ScopeType](#scopetype8) | 是   | 给定范围的上限。 |

**返回值：**

| 类型                         | 说明                                 |
| ---------------------------- | ------------------------------------ |
| [ScopeHelper](#scopehelper9) | 返回当前范围和给定下限和上限的并集。 |

**示例：**

  ```js
let tempLower = new Temperature(30);
let tempUpper = new Temperature(40);
let tempMiDF = new Temperature(35);
let tempMidS = new Temperature(39);
let range = new util.ScopeHelper(tempLower, tempUpper);
let result = range.expand(tempMiDF, tempMidS);
  ```


### expand<sup>9+</sup>

expand(range: ScopeHelper): ScopeHelper

创建并返回包括当前范围和给定范围的并集。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型                         | 必填 | 说明               |
| ------ | ---------------------------- | ---- | ------------------ |
| range  | [ScopeHelper](#scopehelper9) | 是   | 传入一个给定范围。 |

**返回值：**

| 类型                         | 说明                               |
| ---------------------------- | ---------------------------------- |
| [ScopeHelper](#scopehelper9) | 返回包括当前范围和给定范围的并集。 |

**示例：**

  ```js
let tempLower = new Temperature(30);
let tempUpper = new Temperature(40);
let tempMiDF = new Temperature(35);
let tempMidS = new Temperature(39);
let range = new util.ScopeHelper(tempLower, tempUpper);
let rangeFir = new util.ScopeHelper(tempMiDF, tempMidS);
let result = range.expand(rangeFir);
  ```


### expand<sup>9+</sup>

expand(value: ScopeType): ScopeHelper

创建并返回包括当前范围和给定值的并集。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型                     | 必填 | 说明             |
| ------ | ------------------------ | ---- | ---------------- |
| value  | [ScopeType](#scopetype8) | 是   | 传入一个给定值。 |

**返回值：**

| 类型                         | 说明                             |
| ---------------------------- | -------------------------------- |
| [ScopeHelper](#scopehelper9) | 返回包括当前范围和给定值的并集。 |

**示例：**

  ```js
let tempLower = new Temperature(30);
let tempUpper = new Temperature(40);
let tempMiDF = new Temperature(35);
let range = new util.ScopeHelper(tempLower, tempUpper);
let result = range.expand(tempMiDF);
  ```


### contains<sup>9+</sup>

contains(value: ScopeType): boolean

检查给定value是否包含在当前范围内。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型                     | 必填 | 说明             |
| ------ | ------------------------ | ---- | ---------------- |
| value  | [ScopeType](#scopetype8) | 是   | 传入一个给定值。 |

**返回值：**

| 类型    | 说明                                                |
| ------- | --------------------------------------------------- |
| boolean | 如果给定值包含在当前范围内返回true，否则返回false。 |

**示例：**

  ```js
let tempLower = new Temperature(30);
let tempUpper = new Temperature(40);
let tempMiDF = new Temperature(35);
let range = new util.ScopeHelper(tempLower, tempUpper);
range.contains(tempMiDF);
  ```


### contains<sup>9+</sup>

contains(range: ScopeHelper): boolean

检查给定range是否在当前范围内。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型                         | 必填 | 说明               |
| ------ | ---------------------------- | ---- | ------------------ |
| range  | [ScopeHelper](#scopehelper9) | 是   | 传入一个给定范围。 |

**返回值：**

| 类型    | 说明                                                  |
| ------- | ----------------------------------------------------- |
| boolean | 如果给定范围包含在当前范围内返回true，否则返回false。 |

**示例：**

  ```js
let tempLower = new Temperature(30);
let tempUpper = new Temperature(40);
let range = new util.ScopeHelper(tempLower, tempUpper);
let tempLess = new Temperature(20);
let tempMore = new Temperature(45);
let rangeSec = new util.ScopeHelper(tempLess, tempMore);
let result = range.contains(rangeSec);
  ```


### clamp<sup>9+</sup>

clamp(value: ScopeType): ScopeType

将给定值限定到当前范围内。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型                     | 必填 | 说明           |
| ------ | ------------------------ | ---- | -------------- |
| value  | [ScopeType](#scopetype8) | 是   | 传入的给定值。 |

**返回值：**

| 类型                     | 说明                                                         |
| ------------------------ | ------------------------------------------------------------ |
| [ScopeType](#scopetype8) | 如果传入的value小于下限，则返回lowerObj；如果大于上限值则返回upperObj；如果在当前范围内，则返回value。 |

**示例：**

  ```js
let tempLower = new Temperature(30);
let tempUpper = new Temperature(40);
let tempMiDF = new Temperature(35);
let range = new util.ScopeHelper(tempLower, tempUpper);
let result = range.clamp(tempMiDF);
  ```

## Scope<sup>(deprecated)</sup>

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[ScopeHelper<sup>9+</sup>](#scopehelper9)替代。

### constructor<sup>(deprecated)</sup>

constructor(lowerObj: ScopeType, upperObj: ScopeType)

用于创建指定下限和上限的作用域实例的构造函数，返回一个Scope对象。

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[constructor<sup>9+</sup>](#constructor9)替代。


**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| lowerObj | [ScopeType](#scopetype8) | 是 | 指定作用域实例的下限。 |
| upperObj | [ScopeType](#scopetype8) | 是 | 指定作用域实例的上限。 |

**示例：**
  ```js
  let tempLower = new Temperature(30);
  let tempUpper = new Temperature(40);
  let range = new util.Scope(tempLower, tempUpper);
  ```

### toString<sup>(deprecated)</sup>

toString(): string

该字符串化方法返回一个包含当前范围的字符串表示形式。

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[toString<sup>9+</sup>](#tostring9)替代。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 返回包含当前范围对象的字符串表示形式。 |

**示例：**

  ```js
  let tempLower = new Temperature(30);
  let tempUpper = new Temperature(40);
  let range = new util.Scope(tempLower, tempUpper);
  let result = range.toString();
  ```

### intersect<sup>(deprecated)</sup>

intersect(range: Scope): Scope

获取给定范围和当前范围的交集。

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[intersect<sup>9+</sup>](#intersect9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| range | [Scope](#scope8) | 是 | 传入一个给定范围。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [Scope](#scope8) | 返回给定范围和当前范围的交集。 |

**示例：**

  ```js
  let tempLower = new Temperature(30);
  let tempUpper = new Temperature(40);
  let range = new util.Scope(tempLower, tempUpper);
  let tempMiDF = new Temperature(35);
  let tempMidS = new Temperature(39);
  let rangeFir = new util.Scope(tempMiDF, tempMidS);
  range.intersect(rangeFir );
  ```

### intersect<sup>(deprecated)</sup>

intersect(lowerObj:ScopeType,upperObj:ScopeType):Scope

获取当前范围与给定下限和上限范围的交集。

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[intersect<sup>9+</sup>](#intersect9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| lowerObj | [ScopeType](#scopetype8) | 是 | 给定范围的下限。 |
| upperObj | [ScopeType](#scopetype8) | 是 | 给定范围的上限。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [Scope](#scope8) | 返回当前范围与给定下限和上限范围的交集。 |

**示例：**

  ```js
  let tempLower = new Temperature(30);
  let tempUpper = new Temperature(40);
  let tempMiDF = new Temperature(35);
  let tempMidS = new Temperature(39);
  let range = new util.Scope(tempLower, tempUpper);
  let result = range.intersect(tempMiDF, tempMidS);
  ```

### getUpper<sup>(deprecated)</sup>

getUpper(): ScopeType

获取当前范围的上限。

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[getUpper<sup>9+</sup>](#getupper9)替代。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [ScopeType](#scopetype8) | 返回当前范围的上限值。 |

**示例：**

  ```js
  let tempLower = new Temperature(30);
  let tempUpper = new Temperature(40);
  let range = new util.Scope(tempLower, tempUpper);
  let result = range.getUpper();
  ```

### getLower<sup>(deprecated)</sup>

getLower(): ScopeType

获取当前范围的下限。

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[getLower<sup>9+</sup>](#getlower9)替代。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [ScopeType](#scopetype8) | 返回当前范围的下限值。 |

**示例：**

  ```js
  let tempLower = new Temperature(30);
  let tempUpper = new Temperature(40);
  let range = new util.Scope(tempLower, tempUpper);
  let result = range.getLower();
  ```

### expand<sup>(deprecated)</sup>

expand(lowerObj: ScopeType,upperObj: ScopeType): Scope

创建并返回包括当前范围和给定下限和上限的并集。

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[expand<sup>9+</sup>](#expand9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| lowerObj | [ScopeType](#scopetype8) | 是 | 给定范围的下限。 |
| upperObj | [ScopeType](#scopetype8) | 是 | 给定范围的上限。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [Scope](#scope8) | 返回当前范围和给定下限和上限的并集。 |

**示例：**

  ```js
  let tempLower = new Temperature(30);
  let tempUpper = new Temperature(40);
  let tempMiDF = new Temperature(35);
  let tempMidS = new Temperature(39);
  let range = new util.Scope(tempLower, tempUpper);
  let result = range.expand(tempMiDF, tempMidS);
  ```

### expand<sup>(deprecated)</sup>

expand(range: Scope): Scope

创建并返回包括当前范围和给定范围的并集。

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[expand<sup>9+</sup>](#expand9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| range | [Scope](#scope8) | 是 | 传入一个给定范围。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [Scope](#scope8) | 返回包括当前范围和给定范围的并集。 |

**示例：**

  ```js
  let tempLower = new Temperature(30);
  let tempUpper = new Temperature(40);
  let tempMiDF = new Temperature(35);
  let tempMidS = new Temperature(39);
  let range = new util.Scope(tempLower, tempUpper);
  let rangeFir = new util.Scope(tempMiDF, tempMidS);
  let result = range.expand(rangeFir);
  ```

### expand<sup>(deprecated)</sup>

expand(value: ScopeType): Scope

创建并返回包括当前范围和给定值的并集。

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[expand<sup>9+</sup>](#expand9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | [ScopeType](#scopetype8) | 是 | 传入一个给定值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [Scope](#scope8) | 返回包括当前范围和给定值的并集。 |

**示例：**

  ```js
  let tempLower = new Temperature(30);
  let tempUpper = new Temperature(40);
  let tempMiDF = new Temperature(35);
  let range = new util.Scope(tempLower, tempUpper);
  let result = range.expand(tempMiDF);
  ```

### contains<sup>(deprecated)</sup>

contains(value: ScopeType): boolean

检查给定value是否包含在当前范围内。

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[contains<sup>9+</sup>](#contains9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | [ScopeType](#scopetype8) | 是 | 传入一个给定值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果给定值包含在当前范围内返回true，否则返回false。 |

**示例：**

  ```js
  let tempLower = new Temperature(30);
  let tempUpper = new Temperature(40);
  let tempMiDF = new Temperature(35);
  let range = new util.Scope(tempLower, tempUpper);
  range.contains(tempMiDF);
  ```

### contains<sup>(deprecated)</sup>

contains(range: Scope): boolean

检查给定range是否在当前范围内。

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[contains<sup>9+</sup>](#contains9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| range | [Scope](#scope8) | 是 | 传入一个给定范围。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果给定范围包含在当前范围内返回true，否则返回false。 |

**示例：**

  ```js
  let tempLower = new Temperature(30);
  let tempUpper = new Temperature(40);
  let range = new util.Scope(tempLower, tempUpper);
  let tempLess = new Temperature(20);
  let tempMore = new Temperature(45);
  let rangeSec = new util.Scope(tempLess, tempMore);
  let result = range.contains(rangeSec);
  ```

### clamp<sup>(deprecated)</sup>


clamp(value: ScopeType): ScopeType

将给定值限定到当前范围内。

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[clamp<sup>9+</sup>](#clamp9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | [ScopeType](#scopetype8) | 是 | 传入的给定值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [ScopeType](#scopetype8) | 如果传入的value小于下限，则返回lowerObj；如果大于上限值则返回upperObj；如果在当前范围内，则返回value。 |

**示例：**

  ```js
  let tempLower = new Temperature(30);
  let tempUpper = new Temperature(40);
  let tempMiDF = new Temperature(35);
  let range = new util.Scope(tempLower, tempUpper);
  let result = range.clamp(tempMiDF);
  ```

## Base64Helper<sup>9+</sup>

### constructor<sup>9+</sup>

constructor()

Base64Helper的构造函数。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

  ```js
let base64 = new  util.Base64Helper();
  ```

### encodeSync<sup>9+</sup>

encodeSync(src: Uint8Array): Uint8Array

通过输入参数编码后输出对应文本。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型       | 必填 | 说明                |
| ------ | ---------- | ---- | ------------------- |
| src    | Uint8Array | 是   | 编码输入Uint8数组。 |

**返回值：**

| 类型       | 说明                          |
| ---------- | ----------------------------- |
| Uint8Array | 返回编码后新分配的Uint8数组。 |

**示例：**

  ```js
let that = new util.Base64Helper();
let array = new Uint8Array([115,49,51]);
let result = that.encodeSync(array);
  ```


### encodeToStringSync<sup>9+</sup>

encodeToStringSync(src: Uint8Array): string

通过输入参数编码后输出对应文本。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型       | 必填 | 说明                |
| ------ | ---------- | ---- | ------------------- |
| src    | Uint8Array | 是   | 编码输入Uint8数组。 |

**返回值：**

| 类型   | 说明                 |
| ------ | -------------------- |
| string | 返回编码后的字符串。 |

**示例：**

  ```js
let that = new util.Base64Helper();
let array = new Uint8Array([115,49,51]);
let result = that.encodeToStringSync(array);
  ```


### decodeSync<sup>9+</sup>

decodeSync(src: Uint8Array | string): Uint8Array

通过输入参数解码后输出对应文本。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型                           | 必填 | 说明                          |
| ------ | ------------------------------ | ---- | ----------------------------- |
| src    | Uint8Array&nbsp;\|&nbsp;string | 是   | 解码输入Uint8数组或者字符串。 |

**返回值：**

| 类型       | 说明                          |
| ---------- | ----------------------------- |
| Uint8Array | 返回解码后新分配的Uint8数组。 |

**示例：**

  ```js
let that = new util.Base64Helper();
let buff = 'czEz';
let result = that.decodeSync(buff);
  ```


### encode<sup>9+</sup>

encode(src: Uint8Array): Promise&lt;Uint8Array&gt;

通过输入参数异步编码后输出对应文本。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型       | 必填 | 说明                    |
| ------ | ---------- | ---- | ----------------------- |
| src    | Uint8Array | 是   | 异步编码输入Uint8数组。 |

**返回值：**

| 类型                      | 说明                              |
| ------------------------- | --------------------------------- |
| Promise&lt;Uint8Array&gt; | 返回异步编码后新分配的Uint8数组。 |

**示例：**

  ```js
let that = new util.Base64Helper();
let array = new Uint8Array([115,49,51]);
let rarray = new Uint8Array([99,122,69,122]);
that.encode(array).then(val=>{    
    for (var i = 0; i < rarray.length; i++) {        
        console.log(val[i].toString())
    }
})
  ```


### encodeToString<sup>9+</sup>

encodeToString(src: Uint8Array): Promise&lt;string&gt;

通过输入参数异步编码后输出对应文本。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型       | 必填 | 说明                    |
| ------ | ---------- | ---- | ----------------------- |
| src    | Uint8Array | 是   | 异步编码输入Uint8数组。 |

**返回值：**

| 类型                  | 说明                     |
| --------------------- | ------------------------ |
| Promise&lt;string&gt; | 返回异步编码后的字符串。 |

**示例：**

  ```js
let that = new util.Base64Helper();
let array = new Uint8Array([115,49,51]);
that.encodeToString(array).then(val=>{    
    console.log(val)
})
  ```


### decode<sup>9+</sup>

decode(src: Uint8Array | string): Promise&lt;Uint8Array&gt;

通过输入参数异步解码后输出对应文本。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型                           | 必填 | 说明                              |
| ------ | ------------------------------ | ---- | --------------------------------- |
| src    | Uint8Array&nbsp;\|&nbsp;string | 是   | 异步解码输入Uint8数组或者字符串。 |

**返回值：**

| 类型                      | 说明                              |
| ------------------------- | --------------------------------- |
| Promise&lt;Uint8Array&gt; | 返回异步解码后新分配的Uint8数组。 |

**示例：**

  ```js
let that = new util.Base64Helper();
let array = new Uint8Array([99,122,69,122]);
let rarray = new Uint8Array([115,49,51]);
that.decode(array).then(val=>{    
    for (var i = 0; i < rarray.length; i++) {        
        console.log(val[i].toString())
    }
})
  ```


## Base64<sup>(deprecated)</sup>

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[Base64Helper<sup>9+</sup>](#base64helper9)替代。

### constructor<sup>(deprecated)</sup>

constructor()

Base64的构造函数。

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[constructor<sup>9+</sup>](#constructor9)替代。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

  ```js
  let base64 = new  util.Base64();
  ```

### encodeSync<sup>(deprecated)</sup>

encodeSync(src: Uint8Array): Uint8Array

通过输入参数编码后输出对应文本。

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[encodeSync<sup>9+</sup>](#encodesync9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| src | Uint8Array | 是 | 编码输入Uint8数组。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Uint8Array | 返回编码后新分配的Uint8数组。 |

**示例：**

  ```js
  let that = new util.Base64();
  let array = new Uint8Array([115,49,51]);
  let result = that.encodeSync(array);
  ```

### encodeToStringSync<sup>(deprecated)</sup>

encodeToStringSync(src: Uint8Array): string

通过输入参数编码后输出对应文本。

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[encodeToStringSync<sup>9+</sup>](#encodetostringsync9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| src | Uint8Array | 是 | 编码输入Uint8数组。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 返回编码后的字符串。 |

**示例：**

  ```js
  let that = new util.Base64();
  let array = new Uint8Array([115,49,51]);
  let result = that.encodeToStringSync(array);
  ```

### decodeSync<sup>(deprecated)</sup>

decodeSync(src: Uint8Array | string): Uint8Array

通过输入参数解码后输出对应文本。

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[decodeSync<sup>9+</sup>](#decodesync9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| src | Uint8Array&nbsp;\|&nbsp;string | 是 | 解码输入Uint8数组或者字符串。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Uint8Array | 返回解码后新分配的Uint8数组。 |

**示例：**

  ```js
  let that = new util.Base64();
  let buff = 'czEz';
  let result = that.decodeSync(buff);
  ```

### encode<sup>(deprecated)</sup>

encode(src: Uint8Array): Promise&lt;Uint8Array&gt;

通过输入参数异步编码后输出对应文本。

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[encode<sup>9+</sup>](#encode9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| src | Uint8Array | 是 | 异步编码输入Uint8数组。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;Uint8Array&gt; | 返回异步编码后新分配的Uint8数组。 |

**示例：**

  ```js
  let that = new util.Base64();
  let array = new Uint8Array([115,49,51]);
  let rarray = new Uint8Array([99,122,69,122]);
  that.encode(array).then(val=>{    
      for (var i = 0; i < rarray.length; i++) {        
          console.log(val[i].toString())
      }
  })
  ```

### encodeToString<sup>(deprecated)</sup>

encodeToString(src: Uint8Array): Promise&lt;string&gt;

通过输入参数异步编码后输出对应文本。

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[encodeToString<sup>9+</sup>](#encodetostring9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| src | Uint8Array | 是 | 异步编码输入Uint8数组。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;string&gt; | 返回异步编码后的字符串。 |

**示例：**

  ```js
  let that = new util.Base64();
  let array = new Uint8Array([115,49,51]);
  that.encodeToString(array).then(val=>{    
      console.log(val)
  })
  ```

### decode<sup>(deprecated)</sup>


decode(src: Uint8Array | string): Promise&lt;Uint8Array&gt;

通过输入参数异步解码后输出对应文本。

> **说明：**
>
> 从API Version 8开始支持，从API Version 9开始废弃，建议使用[decode<sup>9+</sup>](#decode9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| src | Uint8Array&nbsp;\|&nbsp;string | 是 | 异步解码输入Uint8数组或者字符串。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;Uint8Array&gt; | 返回异步解码后新分配的Uint8数组。 |

**示例：**

  ```js
  let that = new util.Base64();
  let array = new Uint8Array([99,122,69,122]);
  let rarray = new Uint8Array([115,49,51]);
  that.decode(array).then(val=>{    
      for (var i = 0; i < rarray.length; i++) {        
          console.log(val[i].toString())
      }
  })
  ```

## types<sup>8+</sup>


### constructor<sup>8+</sup>

constructor()

Types的构造函数。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

  ```js
  let type = new util.types();
  ```


### isAnyArrayBuffer<sup>8+</sup>

isAnyArrayBuffer(value: Object): boolean

检查输入的value是否是ArrayBuffer类型。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 判断的结果，如果是ArrayBuffer类型为true，反之为false。 |

**示例：**

  ```js
  let that = new util.types();
  let result = that.isAnyArrayBuffer(new ArrayBuffer(0));
  ```


### isArrayBufferView<sup>8+</sup>

isArrayBufferView(value: Object): boolean

检查输入的value是否是内置ArrayBufferView辅助类型。

ArrayBufferView辅助类型包括：Int8Array、Int16Array、Int32Array、Uint8Array、Uint8ClampedArray、Uint32Array、Float32Array、Float64Array、DataView。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 判断的结果，如果是内置包含的ArrayBufferView辅助类型为true，反之为false。 |

**示例：**

  ```js
  let that = new util.types();
  let result = that.isArrayBufferView(new Int8Array([]));
  ```


### isArgumentsObject<sup>8+</sup>

isArgumentsObject(value: Object): boolean

检查输入的value是否是一个arguments对象类型。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 判断的结果，如果是内置包含的arguments类型为true，反之为false。 |

**示例：**

  ```js
  let that = new util.types();
  function foo() {
      var result = that.isArgumentsObject(arguments);
  }
  let f = foo();
  ```


### isArrayBuffer<sup>8+</sup>

isArrayBuffer(value: Object): boolean

检查输入的value是否是ArrayBuffer类型。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 判断的结果，如果是内置包含的ArrayBuffer类型为true，反之为false。 |

**示例：**

  ```js
  let that = new util.types();
  let result = that.isArrayBuffer(new ArrayBuffer(0));
  ```


### isAsyncFunction<sup>8+</sup>

isAsyncFunction(value: Object): boolean

检查输入的value是否是一个异步函数类型。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 判断的结果，如果是内置包含的异步函数类型为true，反之为false。 |

**示例：**

  ```js
  let that = new util.types();
  let result = that.isAsyncFunction(async function foo() {});
  ```


### isBooleanObject<sup>8+</sup>

isBooleanObject(value: Object): boolean

检查输入的value是否是一个Boolean对象类型。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 判断的结果，如果是内置包含的Boolean对象类型为true，反之为false。 |

**示例：**

  ```js
  let that = new util.types();
  let result = that.isBooleanObject(new Boolean(true));
  ```


### isBoxedPrimitive<sup>8+</sup>

isBoxedPrimitive(value: Object): boolean

检查输入的value是否是Boolean或Number或String或Symbol对象类型。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 判断的结果，如果是内置包含的Boolean或Number或String或Symbol对象类型为true，反之为false。 |

**示例：**

  ```js
  let that = new util.types();
  let result = that.isBoxedPrimitive(new Boolean(false));
  ```


### isDataView<sup>8+</sup>

isDataView(value: Object): boolean

检查输入的value是否是DataView类型。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 判断的结果，如果是内置包含的DataView对象类型为true，反之为false。 |

**示例：**

  ```js
  let that = new util.types();
  const ab = new ArrayBuffer(20);
  let result = that.isDataView(new DataView(ab));
  ```


### isDate<sup>8+</sup>

isDate(value: Object): boolean

检查输入的value是否是Date类型。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 判断的结果，如果是内置包含的Date对象类型为true，反之为false。 |

**示例：**

  ```js
  let that = new util.types();
  let result = that.isDate(new Date());
  ```


### isExternal<sup>8+</sup>

isExternal(value: Object): boolean

检查输入的value是否是native External类型。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 判断的结果，如果是内置包含native&nbsp;External类型为true，反之为false。 |

**示例：**

  ```js
  let that = new util.types();
  let result = that.isExternal(true);
  ```


### isFloat32Array<sup>8+</sup>

isFloat32Array(value: Object): boolean

检查输入的value是否是Float32Array数组类型。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 判断的结果，如果是内置包含的Float32Array数组类型为true，反之为false。 |

**示例：**

  ```js
  let that = new util.types();
  let result = that.isFloat32Array(new Float32Array());
  ```


### isFloat64Array<sup>8+</sup>

isFloat64Array(value: Object): boolean

检查输入的value是否是Float64Array数组类型。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 判断的结果，如果是内置包含的Float64Array数组类型为true，反之为false。 |

**示例：**

  ```js
  let that = new util.types();
  let result = that.isFloat64Array(new Float64Array());
  ```


### isGeneratorFunction<sup>8+</sup>

isGeneratorFunction(value: Object): boolean

检查输入的value是否是generator函数类型。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 判断的结果，如果是内置包含的generator函数类型为true，反之为false。 |

**示例：**

  ```js
  let that = new util.types();
  let result = that.isGeneratorFunction(function* foo() {});
  ```


### isGeneratorObject<sup>8+</sup>

isGeneratorObject(value: Object): boolean

检查输入的value是否是generator对象类型。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 判断的结果，如果是内置包含的generator对象类型为true，反之为false。 |

**示例：**

  ```js
  let that = new util.types();
  function* foo() {}
  const generator = foo();
  let result = that.isGeneratorObject(generator);
  ```


### isInt8Array<sup>8+</sup>

isInt8Array(value: Object): boolean

检查输入的value是否是Int8Array数组类型。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 判断的结果，如果是内置包含的Int8Array数组类型为true，反之为false。 |

**示例：**

  ```js
  let that = new util.types();
  let result = that.isInt8Array(new Int8Array([]));
  ```


### isInt16Array<sup>8+</sup>

isInt16Array(value: Object): boolean

检查输入的value是否是Int16Array数组类型。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 判断的结果，如果是内置包含的Int16Array数组类型为true，反之为false。 |

**示例：**

  ```js
  let that = new util.types();
  let result = that.isInt16Array(new Int16Array([]));
  ```


### isInt32Array<sup>8+</sup>

isInt32Array(value: Object): boolean

检查输入的value是否是Int32Array数组类型。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 判断的结果，如果是内置包含的Int32Array数组类型为true，反之为false。 |

**示例：**

  ```js
  let that = new util.types();
  let result = that.isInt32Array(new Int32Array([]));
  ```


### isMap<sup>8+</sup>

isMap(value: Object): boolean

检查输入的value是否是Map类型。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 判断的结果，如果是内置包含的Map类型为true，反之为false。 |

**示例：**

  ```js
  let that = new util.types();
  let result = that.isMap(new Map());
  ```


### isMapIterator<sup>8+</sup>

isMapIterator(value: Object): boolean

检查输入的value是否是Map的Iterator类型。

**系统能力：** SystemCapability.Utils.Lang

**参数：**


| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 判断的结果，如果是内置包含的Map的Iterator类型为true，反之为false。 |

**示例：**

  ```js
  let that = new util.types();
  const map = new Map();
  let result = that.isMapIterator(map.keys());
  ```


### isNativeError<sup>8+</sup>

isNativeError(value: Object): boolean

检查输入的value是否是Error类型。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 判断的结果，如果是内置包含的Error类型为true，反之为false。 |

**示例：**

  ```js
  let that = new util.types();
  let result = that.isNativeError(new TypeError());
  ```


### isNumberObject<sup>8+</sup>

isNumberObject(value: Object): boolean

检查输入的value是否是Number对象类型。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 判断的结果，如果是内置包含的Number对象类型为true，反之为false。 |

**示例：**

  ```js
  let that = new util.types();
  let result = that.isNumberObject(new Number(0));
  ```


### isPromise<sup>8+</sup>

isPromise(value: Object): boolean

检查输入的value是否是Promise类型。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 判断的结果，如果是内置包含的Promise类型为true，反之为false。 |

**示例：**

  ```js
  let that = new util.types();
  let result = that.isPromise(Promise.resolve(1));
  ```


### isProxy<sup>8+</sup>

isProxy(value: Object): boolean

检查输入的value是否是Proxy类型。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 判断的结果，如果是内置包含的Proxy类型为true，反之为false。 |

**示例：**

  ```js
  let that = new util.types();
  const target = {};
  const proxy = new Proxy(target, {});
  let result = that.isProxy(proxy);
  ```


### isRegExp<sup>8+</sup>

isRegExp(value: Object): boolean

检查输入的value是否是RegExp类型。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 判断的结果，如果是内置包含的RegExp类型为true，反之为false。 |

**示例：**

  ```js
  let that = new util.types();
  let result = that.isRegExp(new RegExp('abc'));
  ```


### isSet<sup>8+</sup>

isSet(value: Object): boolean

检查输入的value是否是Set类型。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 判断的结果，如果是内置包含的Set类型为true，反之为false。 |

**示例：**

  ```js
  let that = new util.types();
  let result = that.isSet(new Set());
  ```


### isSetIterator<sup>8+</sup>

isSetIterator(value: Object): boolean

检查输入的value是否是Set的Iterator类型。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 判断的结果，如果是内置包含的Set的Iterator类型为true，反之为false。 |

**示例：**

  ```js
  let that = new util.types();
  const set = new Set();
  let result = that.isSetIterator(set.keys());
  ```


### isStringObject<sup>8+</sup>

isStringObject(value: Object): boolean

检查输入的value是否是String对象类型。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 判断的结果，如果是内置包含的String对象类型为true，反之为false。 |

**示例：**

  ```js
  let that = new util.types();
  let result = that.isStringObject(new String('foo'));
  ```


### isSymbolObjec<sup>8+</sup>

isSymbolObject(value: Object): boolean

检查输入的value是否是Symbol对象类型。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 判断的结果，如果是内置包含的Symbol对象类型为true，反之为false。 |

**示例：**

  ```js
  let that = new util.types();
  const symbols = Symbol('foo');
  let result = that.isSymbolObject(Object(symbols));
  ```


### isTypedArray<sup>8+</sup>

isTypedArray(value: Object): boolean

检查输入的value是否是TypedArray类型的辅助类型。

TypedArray类型的辅助类型，包括Int8Array、Int16Array、Int32Array、Uint8Array、Uint8ClampedArray、Uint16Array、Uint32Array、Float32Array、Float64Array、DataView。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 判断的结果，如果是内置包含的TypedArray包含的类型为true，反之为false。 |

**示例：**

  ```js
  let that = new util.types();
  let result = that.isTypedArray(new Float64Array([]));
  ```


### isUint8Array<sup>8+</sup>

isUint8Array(value: Object): boolean

检查输入的value是否是Uint8Array数组类型。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 判断的结果，如果是内置包含的Uint8Array数组类型为true，反之为false。 |

**示例：**

  ```js
  let that = new util.types();
  let result = that.isUint8Array(new Uint8Array([]));
  ```


### isUint8ClampedArray<sup>8+</sup>

isUint8ClampedArray(value: Object): boolean

检查输入的value是否是Uint8ClampedArray数组类型。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 判断的结果，如果是内置包含的Uint8ClampedArray数组类型为true，反之为false。 |

**示例：**

  ```js
  let that = new util.types();
  let result = that.isUint8ClampedArray(new Uint8ClampedArray([]));
  ```


### isUint16Array<sup>8+</sup>

isUint16Array(value: Object): boolean

检查输入的value是否是Uint16Array数组类型。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 判断的结果，如果是内置包含的Uint16Array数组类型为true，反之为false。 |

**示例：**

  ```js
  let that = new util.types();
  let result = that.isUint16Array(new Uint16Array([]));
  ```


### isUint32Array<sup>8+</sup>

isUint32Array(value: Object): boolean

检查输入的value是否是Uint32Array数组类型。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 判断的结果，如果是内置包含的Uint32Array数组类型为true，反之为false。 |

**示例：**

  ```js
  let that = new util.types();
  let result = that.isUint32Array(new Uint32Array([]));
  ```


### isWeakMap<sup>8+</sup>

isWeakMap(value: Object): boolean

检查输入的value是否是WeakMap类型。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 判断的结果，如果是内置包含的WeakMap类型为true，反之为false。 |

**示例：**

  ```js
  let that = new util.types();
  let result = that.isWeakMap(new WeakMap());
  ```


### isWeakSet<sup>8+</sup>

isWeakSet(value: Object): boolean

检查输入的value是否是WeakSet类型。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 判断的结果，如果是内置包含的WeakSet类型为true，反之为false。 |

**示例：**

  ```js
  let that = new util.types();
  let result = that.isWeakSet(new WeakSet());
  ```


### isBigInt64Array<sup>8+</sup>

isBigInt64Array(value: Object): boolean

检查输入的value是否是BigInt64Array类型。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 判断的结果，如果是内置包含的BigInt64Array类型为true，反之为false。 |

**示例：**

  ```js
  let that = new util.types();
  let result = that.isBigInt64Array(new BigInt64Array([]));
  ```


### isBigUint64Array<sup>8+</sup>

isBigUint64Array(value: Object): boolean

检查输入的value是否是BigUint64Array类型。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 判断的结果，如果是内置包含的BigUint64Array类型为true，反之为false。 |

**示例：**

  ```js
  let that = new util.types();
  let result = that.isBigUint64Array(new BigUint64Array([]));
  ```


### isModuleNamespaceObject<sup>8+</sup>

isModuleNamespaceObject(value: Object): boolean

检查输入的value是否是Module Namespace Object类型。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 判断的结果，如果是内置包含的Module Namespace Object类型为true，反之为false。 |

**示例：**

  ```js
  import url from '@ohos.url'
  let that = new util.types();
  let result = that.isModuleNamespaceObject(url);
  ```


### isSharedArrayBuffer<sup>8+</sup>

isSharedArrayBuffer(value: Object): boolean

检查输入的value是否是SharedArrayBuffer类型。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | 待检测对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 判断的结果，如果是内置包含的SharedArrayBuffer类型为true，反之为false。 |

**示例：**

  ```js
  let that = new util.types();
  let result = that.isSharedArrayBuffer(new SharedArrayBuffer(0));
  ```
  <!--no_check-->