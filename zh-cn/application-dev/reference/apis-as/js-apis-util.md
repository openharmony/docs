# @ohos.util (util工具函数)

该模块主要提供常用的工具函数，实现字符串编解码（[TextEncoder](#textencoder)，[TextDecoder](#textdecoder)）、Base64编解码（[Base64Helper<sup>9+</sup>](#base64helper9)）等功能。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import util from '@ohos.util';
```

## TextDecoderOptions<sup>11+</sup>

**系统能力：** SystemCapability.Utils.Lang

解码相关选项参数，存在两个属性fatal和ignoreBOM。

| 名称      | 类型 | 必填 | 说明               |
| --------- | -------- | ---- | ------------------ |
| fatal     | boolean  | 否   | 是否显示致命错误，默认值是false。 |
| ignoreBOM | boolean  | 否   | 是否忽略BOM标记，默认值是false。  |

## DecodeWithStreamOptions<sup>11+</sup>

**系统能力：** SystemCapability.Utils.Lang

解码是否跟随附加数据块相关选项参数。

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| stream | boolean | 否 | 在随后的decodeWithStream()调用中是否跟随附加数据块。如果以块的形式处理数据，则设置为true；如果处理最后的数据块或数据未分块，则设置为false。默认为false。 |

## TextDecoder

TextDecoder用于将字节数组解码为字符串，可以处理多种编码格式，包括utf-8、utf-16le/be、iso-8859和windows-1251等不同的编码格式。

### create<sup>9+</sup>

create(encoding?: string, options?: TextDecoderOptions): TextDecoder

替代有参构造功能。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名   | 类型   | 必填 | 说明                                             |
| -------- | ------ | ---- | ------------------------------------------------ |
| encoding | string | 否   | 编码格式，默认值是'utf-8'。                      |
| options  | [TextDecoderOptions](#textdecoderoptions11) | 否   | 解码相关选项参数，存在两个属性fatal和ignoreBOM。|

**示例：**

```ts
let textDecoderOptions: util.TextDecoderOptions = {
  fatal: false,
  ignoreBOM : true
}
let result = util.TextDecoder.create('utf-8', textDecoderOptions)
let retStr = result.encoding
```

### decodeWithStream<sup>9+</sup>

decodeWithStream(input: Uint8Array, options?: DecodeWithStreamOptions): string

通过输入参数解码后输出对应文本。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| input | Uint8Array | 是 | 符合格式需要解码的数组。 |
| options | [DecodeWithStreamOptions](#decodewithstreamoptions11) | 否 | 解码相关选项参数。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 解码后的数据。 |

**示例：**

```ts
let textDecoderOptions: util.TextDecoderOptions = {
  fatal: false,
  ignoreBOM : true
}
let decodeWithStreamOptions: util.DecodeWithStreamOptions = {
  stream: false
}
let textDecoder = util.TextDecoder.create('utf-8', textDecoderOptions);
let result = new Uint8Array(6);
result[0] = 0xEF;
result[1] = 0xBB;
result[2] = 0xBF;
result[3] = 0x61;
result[4] = 0x62;
result[5] = 0x63;
console.info("input num:");
let retStr = textDecoder.decodeWithStream(result , decodeWithStreamOptions);
console.info("retStr = " + retStr);
```

## EncodeIntoUint8ArrayInfo<sup>11+</sup>

**系统能力：** SystemCapability.Utils.Lang

编码后的文本。

| 名称      | 类型 | 可读  |可写  | 说明               |
| --------- | -------- | -------- |-------- |------------------ |
| read     | number  | 是 | 否 |表示已读取的字符数。 |
| written | number   | 是 |否 |表示已写入的字节数。  |

## TextEncoder

TextEncoder用于将字符串编码为字节数组，支持多种编码格式，包括utf-8、utf-16le/be等。需要注意的是，在使用TextEncoder进行编码时，不同编码格式下字符所占的字节数是不同的。例如，utf-8编码下中文字符通常占3个字节，而utf-16le/be编码下中文字符通常占2个字节。因此，在使用TextEncoder时需要明确指定要使用的编码格式，以确保编码结果正确。

### constructor

constructor()

TextEncoder的构造函数。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

```ts
let textEncoder = new util.TextEncoder();
```

### constructor<sup>9+</sup>

constructor(encoding?: string)

TextEncoder的构造函数。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ---- | ---- | ---- |
| encoding | string | 否 | 编码格式，默认值为'utf-8'。 |

**示例：**

```ts
let textEncoder = new util.TextEncoder("utf-8");
```

### encodeInto<sup>9+</sup>

encodeInto(input?: string): Uint8Array

通过输入参数编码后输出Uint8Array对象。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| input  | string | 否   | 需要编码的字符串，默认值是空字符串。 |

**返回值：**

| 类型       | 说明               |
| ---------- | ------------------ |
| Uint8Array | 返回编码后的Uint8Array对象。 |

**示例：**

```ts
let textEncoder = new util.TextEncoder();
let buffer = new ArrayBuffer(20);
let result = new Uint8Array(buffer);
result = textEncoder.encodeInto("\uD800¥¥");
```

### encodeIntoUint8Array<sup>9+</sup>

encodeIntoUint8Array(input: string, dest: Uint8Array): EncodeIntoUint8ArrayInfo

对字符串进行编码，将结果写入dest数组。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型       | 必填 | 说明                                                    |
| ------ | ---------- | ---- | ------------------------------------------------------- |
| input  | string     | 是   | 需要编码的字符串。                                      |
| dest   | Uint8Array | 是   | Uint8Array对象实例，用于将生成的UTF-8编码文本放入其中。 |

**返回值：**

| 类型       | 说明               |
| ---------- | ------------------ |
| [EncodeIntoUint8ArrayInfo](#encodeintouint8arrayinfo11) | 返回一个对象，read表示已编码的字符数，write表示编码字符所占用的字节数。 |

**示例：**

```ts
let that = new util.TextEncoder();
let buffer = new ArrayBuffer(4);
let dest = new Uint8Array(buffer);
let result = new Object();
result = that.encodeIntoUint8Array('abcd', dest);
```

## Type<sup>10+</sup>

Base64编码格式枚举。

**系统能力：** SystemCapability.Utils.Lang

| 名称   |值| 说明               |
| ----- |---| ----------------- |
| BASIC | 0 | 表示BASIC编码格式。|
| MIME  | 1 | 表示MIME编码格式。 |

## Base64Helper<sup>9+</sup>

Base64编码表包含A-Z、a-z、0-9这62个字符，以及"+"和"/"这两个特殊字符。在编码时，将原始数据按3个字节一组进行划分，得到若干个6位的数字，然后使用Base64编码表中对应的字符来表示这些数字。如果最后剩余1或2个字节，则需要使用"="字符进行补齐。

### constructor<sup>9+</sup>

constructor()

Base64Helper的构造函数。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

```ts 
let base64 = new  util.Base64Helper();
```

### encodeSync<sup>9+</sup>

encodeSync(src: Uint8Array): Uint8Array

通过输入参数编码后输出Uint8Array对象。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型       | 必填 | 说明                |
| ------ | ---------- | ---- | ------------------- |
| src    | Uint8Array | 是   | 待编码Uint8Array对象。 |

**返回值：**

| 类型       | 说明                          |
| ---------- | ----------------------------- |
| Uint8Array | 返回编码后的Uint8Array对象。 |

**示例：**

```ts
let that = new util.Base64Helper();
let array = new Uint8Array([115,49,51]);
let result = that.encodeSync(array);
```

### encodeToStringSync<sup>9+</sup>

encodeToStringSync(src: Uint8Array, options?: Type): string

通过输入参数编码后输出对应文本。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型       | 必填 | 说明                |
| ------ | ---------- | ---- | ------------------- |
| src    | Uint8Array | 是   | 待编码Uint8Array对象。 |
| options<sup>10+</sup>    | [Type](#type10) | 否   | 从API version 10开始支持该参数，表示对应的编码格式。<br/>此参数可选，可选值为：util.Type.BASIC和util.Type.MIME，默认值为：util.Type.BASIC。<br/>- 当参数取值为util.Type.BASIC时，输出结果包含：64个可打印字符，包括大写字母A-Z、小写字母a-z、数字0-9共62个字符，再加上另外2个'+'和'/'，没有回车符、换行符。<br/>- 当参数取值为util.Type.MIME时，输出结果包含：64个可打印字符，包括大写字母A-Z、小写字母a-z、数字0-9共62个字符，再加上另外2个'+'和'/'，编码输出每一行不超过76个字符，而且每行以'\r\n'符结束。|

**返回值：**

| 类型   | 说明                 |
| ------ | -------------------- |
| string | 返回编码后的字符串。 |

**示例：**

```ts
let that = new util.Base64Helper();
let array = new Uint8Array([77,97,110,105,115,100,105,115,116,105,110,103,117,105,115,104,101,100,110,111,116,111,110,108,121,98,121,104,105,115,114,101,97,115,111,110,98,117,116,98,121,116,104,105,115,115,105,110,103,117,108,97,114,112,97,115,115,105,111,110,102,114,111,109,111,116,104,101,114,97,110,105,109,97,108,115,119,104,105,99,104,105,115,97,108,117,115,116,111,102,116,104,101,109,105,110,100,101,120,99,101,101,100,115,116,104,101,115,104,111,114,116,118,101,104,101,109,101,110,99,101,111,102,97,110,121,99,97,114,110,97,108,112,108,101,97,115,117,114,101]);
let result = that.encodeToStringSync(array, util.Type.MIME);
```

### decodeSync<sup>9+</sup>

decodeSync(src: Uint8Array | string, options?: Type): Uint8Array

通过输入参数解码后输出对应Uint8Array对象。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型                           | 必填 | 说明                          |
| ------ | ------------------------------ | ---- | ----------------------------- |
| src    | Uint8Array&nbsp;\|&nbsp;string | 是   | 待解码Uint8Array对象或者字符串。 |
| options<sup>10+</sup>    | [Type](#type10) | 否   | 从API version 10开始支持该参数，表示对应的编码格式。<br/>此参数可选，可选值为：util.Type.BASIC和util.Type.MIME，默认值为：util.Type.BASIC。<br/>- 当参数取值为util.Type.BASIC时，表示入参包含：64个可打印字符，包括大写字母A-Z、小写字母a-z、数字0-9共62个字符，再加上另外2个'+'和'/'，没有回车符、换行符。<br/>- 当参数取值为util.Type.MIME时，表示入参包含：64个可打印字符，包括大写字母A-Z、小写字母a-z、数字0-9共62个字符，再加上另外2个'+'和'/'，每一行不超过76个字符，而且每行以'\r\n'符结束。 |

**返回值：**

| 类型       | 说明                          |
| ---------- | ----------------------------- |
| Uint8Array | 返回解码后新分配的Uint8Array对象。 |

**示例：**

```ts
let that = new util.Base64Helper();
let buff = 'TWFuaXNkaXN0aW5ndWlzaGVkbm90b25seWJ5aGlzcmVhc29uYnV0Ynl0aGlzc2luZ3VsYXJwYXNz\r\naW9uZnJvbW90aGVyYW5pbWFsc3doaWNoaXNhbHVzdG9mdGhlbWluZGV4Y2VlZHN0aGVzaG9ydHZl\r\naGVtZW5jZW9mYW55Y2FybmFscGxlYXN1cmU=\r\n';
let result = that.decodeSync(buff, util.Type.MIME);
```

### encode<sup>9+</sup>

encode(src: Uint8Array): Promise&lt;Uint8Array&gt;

通过输入参数异步编码后输出对应Uint8Array对象。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型       | 必填 | 说明                    |
| ------ | ---------- | ---- | ----------------------- |
| src    | Uint8Array | 是   | 异步编码输入Uint8Array对象。 |

**返回值：**

| 类型                      | 说明                              |
| ------------------------- | --------------------------------- |
| Promise&lt;Uint8Array&gt; | 返回异步编码后新分配的Uint8Array对象。 |

**示例：**

  ```ts
  let that = new util.Base64Helper();
  let array = new Uint8Array([115,49,51]);
  let rarray = new Uint8Array([99,122,69,122]);
  that.encode(array).then(val=>{
    for (let i = 0; i < rarray.length; i++) {
      console.info(val[i].toString());
    }
  })
  ```