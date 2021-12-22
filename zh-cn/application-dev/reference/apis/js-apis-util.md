# 字符串编解码

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```
import util from '@ohos.util';
```


## 权限

无


## util.printf

printf(format: string, ...args: Object[]): string

通过式样化字符串对输入的内容按特定格式输出。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | format | string | 是 | 式样化字符串。 |
  | ...args | Object[] | 否 | 待式样化数据。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | string | 按特定格式式样化后的字符串。 |

- 示例：
  ```
  var res = util.printf("%s", "hello world!");
  console.log(res);
  ```


## util.getErrorString

getErrorString(errno: number): string

获取系统错误码对应的详细信息。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | errno | number | 是 | 系统发生错误产生的错误码。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | string | 错误码对应的详细信息。 |

- 示例：
  ```
  var errnum = 10; // 10：a system error number
  var result = util.getErrorString(errnum);
  console.log("result = " + result);
  ```


## util.callbackWrapper

callbackWrapper(original: Function): (err: Object, value: Object)=&gt;void

对异步函数进行回调化处理，回调中第一个参数将是拒绝原因（如果 Promise 已解决，则为 null），第二个参数将是已解决的值。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | original | Function | 是 | 异步函数。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | Function | 返回一个第一个参数是拒绝原因（如果&nbsp;Promise&nbsp;已解决，则为&nbsp;null），第二个参数是已解决的回调函数。 |

- 示例：
  ```
  async function promiseFn() {
      return Promise.reject('value');
  }
  var cb = util.callbackWrapper(promiseFn);
  cb((err, ret) => {
      expect(err).strictEqual('value');
      expect(ret).strictEqual(undefined);
  })
  ```


## util.promiseWrapper

promiseWrapper(original: (err: Object, value: Object) =&gt; void): Object

对异步函数处理并返回一个promise的版本。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | original | Function | 是 | 异步函数。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | Function | 采用遵循常见的错误优先的回调风格的函数（也就是将&nbsp;(err,&nbsp;value)&nbsp;=&gt;&nbsp;...&nbsp;回调作为最后一个参数），并返回一个返回&nbsp;promise&nbsp;的版本。 |

- 示例：
  ```
  function aysnFun(str1, str2, callback) {
      if (typeof str1 === 'string' && typeof str1 === 'string') {
          callback(null, str1 + str2);
      } else {
          callback('type err');
      }
  }
  let newPromiseObj = util.promiseWrapper(aysnFun)("Hello", 'World');
  newPromiseObj.then(res => {
      expect(res).strictEqual('HelloWorld');
  })
  ```


## TextDecoder


### 属性

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| encoding | string | 是 | 否 | 编码格式。<br/>-&nbsp;支持格式：utf-8、ibm866、iso-8859-2、iso-8859-3、iso-8859-4、iso-8859-5、iso-8859-6、iso-8859-7、iso-8859-8、iso-8859-8-i、iso-8859-10、iso-8859-13、iso-8859-14、iso-8859-15、koi8-r、koi8-u、macintosh、windows-874、windows-1250、windows-1251、windows-1252、windows-1253、windows-1254、windows-1255、windows-1256、windows-1257、windows-1258、x-mac-cyrilli、gbk、gb18030、big5、euc-jp、iso-2022-jp、shift_jis、euc-kr、utf-16be、utf-16le。 |
| fatal | boolean | 是 | 否 | 是否显示致命错误。 |
| ignoreBOM | boolean | 是 | 否 | 是否忽略BOM（byte&nbsp;order&nbsp;marker）标记，默认值是false。 |


### constructor

constructor(encoding?: string, options?: { fatal?: boolean; ignoreBOM?: boolean },)

TextDecoder的构造函数。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | encoding | string | 否 | 编码格式。 |
  | options | Object | 否 | 编码相关选项参数，存在两个属性fatal和ignoreBOM。 |

  **表1** options
  
  | 名称 | 参数类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | fatal | boolean | 否 | 是否显示致命错误。 |
  | ignoreBOM | boolean | 否 | 是否忽略BOM标记。 |

- 示例：
  ```
  var textDecoder = new util.TextDecoder("utf-8",{ignoreBOM:true});
  ```


### decode

decode(input: Uint8Array, options?:{stream?:false}): string

通过输入参数解码后输出对应文本。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | input | Uint8Array | 是 | 符合格式需要解码的数组。 |
  | options | Object | 否 | 解码相关选项参数。 |

  **表2** options
  
  | 名称 | 参数类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | stream | boolean | 否 | 在随后的decode()调用中是否跟随附加数据块，如果以块的形式处理数据，则设置为true；如果处理最后的数据块或数据未分块，则设置为false。默认为false。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | string | 解码后的数据。 |

- 示例：
  ```
  var textDecoder = new util.TextDecoder("utf-8",{ignoreBOM:true});
  var result = new Uint8Array(6);
  result[0] = 0xEF;
  result[1] = 0xBB;
  result[2] = 0xBF;
  result[3] = 0x61;
  result[4] = 0x62;
  result[5] = 0x63;
  console.log("input num:");
  for(var j= 0; j < 6; j++) {
      console.log(result[j]);
  }
  var retStr = textDecoder.decode( result , {stream:false});
  console.log("retStr = " + retStr);
  ```


## TextEncoder


### 属性

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| encoding | string | 是 | 否 | 编码格式，默认值是utf-8。 |


### constructor

constructor()

TextEncoder的构造函数。

- 示例：
  ```
  var textEncoder = new util.TextEncoder();
  ```


### encode

encode(input?: string): Uint8Array

通过输入参数编码后输出对应文本。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | input | string | 是 | 需要编码的字符串。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | Uint8Array | 返回编码后的文本。 |

- 示例：
  ```
  var textEncoder = new util.TextEncoder();
  var result = new Uint8Array(buffer);
  result = textEncoder.encode("\uD800¥¥");
  ```


### encodeInto

encodeInto(input: string, dest: Uint8Array,):{ read: number; written: number }

放置生成的UTF-8编码文本。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | input | string | 是 | 需要编码的字符串。 |
  | dest | Uint8Array | 是 | Uint8Array对象实例，用于将生成的UTF-8编码文本放入其中。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | Uint8Array | 返回编码后的文本。 |

- 示例：
  ```
  var that = new util.TextEncoder();
  var buffer = new ArrayBuffer(4);
  this.dest = new Uint8Array(buffer);
  var result = that.encodeInto("abcd", this.dest);
  ```
