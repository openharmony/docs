# util


> **NOTE**<br>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


This module provides common utility functions, such as **TextEncoder** and **TextDecoder** for string encoding and decoding, **RationalNumber** for rational number operations, **LruBuffer** for buffer management, **Scope** for range determination, **Base64** for Base64 encoding and decoding, and **types** for checks of built-in object types.


## Modules to Import

```
import util from '@ohos.util';
```

## util.printf

printf(format: string,  ...args: Object[]): string

Prints the input content in a formatted string.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | format  | string  | Yes | Format of the string to print. |
 | ...args  | Object[]  | No | Data to format. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | string  | String in the specified format. |

**Example**
  ```js
  var res = util.printf("%s", "hello world!");
  console.log(res);
  ```


## util.getErrorString

getErrorString(errno: number): string

Obtains detailed information about a system error code.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | errno  | number  | Yes | Error code generated. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | string  | Detailed information about the error code. |

**Example**
  ```js
  var errnum = 10; // 10 is the system error code.
  var result = util.getErrorString(errnum);
  console.log("result = " + result);
  ```


## util.callbackWrapper

callbackWrapper(original: Function): (err: Object, value: Object )=&gt;void

Calls back an asynchronous function. In the callback, the first parameter indicates the cause of the rejection (the value is **null** if the promise has been resolved), and the second parameter indicates the resolved value.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | original  | Function  | Yes | Asynchronous function. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | Function  | Callback, in which the first parameter indicates the cause of the rejection (the value is **null** if the promise has been resolved) and the second parameter indicates the resolved value. |

**Example**
  ```js
  async function promiseFn() {
      return Promise.reject('value');
  }
  var cb = util.callbackWrapper(promiseFn);
  cb((err, ret) => {
      console.log(err);
      console.log(ret);
  })
  ```


## util.promiseWrapper

promiseWrapper(original: (err: Object, value: Object) =&gt; void): Object

Processes an asynchronous function and returns a promise version.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | original  | Function  | Yes | Asynchronous function. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | Function  | Function in the error-first style (that is, **(err, value) =>...** is called as the last parameter) and the promise version. |

**Example**
  ```js
  function aysnFun(str1, str2, callback) {
      if (typeof str1 === 'string' && typeof str2 === 'string') {
          callback(null, str1 + str2);
      } else {
          callback('type err');
      }
  }
  let newPromiseObj = util.promiseWrapper(aysnFun)("Hello", 'World');
  newPromiseObj.then(res => {
      console.log(res);
  })
  ```


## TextDecoder

### Attributes

**System capability**: SystemCapability.Utils.Lang

 | Name | Type | Readable | Writable | Description |
 | --------  | --------  | --------  | --------  | --------  |
 | encoding  | string  | Yes | No | Encoding format.<br>-&nbsp;Supported formats: utf-8, ibm866, iso-8859-2, iso-8859-3, iso-8859-4, iso-8859-5, iso-8859-6, iso-8859-7, iso-8859-8, iso-8859-8-i, iso-8859-10, iso-8859-13, iso-8859-14, iso-8859-15, koi8-r, koi8-u, macintosh, windows-874, windows-1250, windows-1251, windows-1252, windows-1253, windows-1254, windows-1255, windows-1256, windows-1257, windows-1258, x-mac-cyrilli, gbk, gb18030, big5, euc-jp, iso-2022-jp, shift_jis, euc-kr, utf-16be, utf-16le |
 | fatal  | boolean  | Yes | No | Whether to display fatal errors. |
 | ignoreBOM  | boolean  | Yes | No | Whether to ignore the byte order marker (BOM). The default value is **false**, which indicates that the result contains the BOM. |


### constructor

constructor(encoding?: string, options?: { fatal?: boolean; ignoreBOM?: boolean },)

A constructor used to create a **TextDecoder** object.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | encoding  | string  | No | Encoding format. |
 | options  | Object  | No | Encoding-related options, which include **fatal** and **ignoreBOM**. |

  **Table 1** options

 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | fatal  | boolean  | No | Whether to display fatal errors. |
 | ignoreBOM  | boolean  | No | Whether to ignore the BOM. |

**Example**
  ```js
  var textDecoder = new util.TextDecoder("utf-8",{ignoreBOM: true});
  ```


### decode

decode(input: Uint8Array, options?: { stream?: false }): string

Decodes the input content.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | input  | Unit8Array  | Yes | Uint8Array to decode. |
 | options  | Object  | No | Options related to decoding. |

  **Table 2** options

 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | stream  | boolean  | No | Whether to allow data blocks in subsequent **decode()**. If data is processed in blocks, set this parameter to **true**. If this is the last data block to process or data is not divided into blocks, set this parameter to **false**. The default value is **false**. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | string  | Data decoded. |

**Example**
  ```js
  var textDecoder = new util.TextDecoder("utf-8",{ignoreBOM: true});
  var result = new Uint8Array(6);
  result[0] = 0xEF;
  result[1] = 0xBB;
  result[2] = 0xBF;
  result[3] = 0x61;
  result[4] = 0x62;
  result[5] = 0x63;
  console.log("input num:");
  var retStr = textDecoder.decode( result , {stream: false});
  console.log("retStr = " + retStr);
  ```


## TextEncoder

### Attributes

**System capability**: SystemCapability.Utils.Lang

 | Name | Type | Readable | Writable | Description |
 | --------  | --------  | --------  | --------  | --------  |
 | encoding  | string  | Yes | No | Encoding format. The default format is **utf-8**. |


### constructor

constructor()

A constructor used to create a **TextEncoder** object.

**System capability**: SystemCapability.Utils.Lang

**Example**
  ```js
  var textEncoder = new util.TextEncoder();
  ```


### encode

encode(input?: string): Uint8Array

Encodes the input content.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | input  | string  | Yes | String to encode. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | Uint8Array  | Encoded text. |

**Example**
  ```js
  var textEncoder = new util.TextEncoder();
  var buffer = new ArrayBuffer(20);
  var result = new Uint8Array(buffer);
  result = textEncoder.encode("\uD800¥¥");
  ```


### encodeInto

encodeInto(input: string, dest: Uint8Array, ): { read: number; written: number }

Stores the UTF-8 encoded text.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | input  | string  | Yes | String to encode. |
 | dest  | Uint8Array  | Yes | **Uint8Array** instance used to store the UTF-8 encoded text. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | Uint8Array  | Encoded text. |

**Example**
  ```js
  var that = new util.TextEncoder();
  var buffer = new ArrayBuffer(4);
  this.dest = new Uint8Array(buffer);
  var result = that.encodeInto("abcd", this.dest);
  ```

## RationalNumber<sup>8+</sup>


### constructor<sup>8+</sup>

constructor(numerator: number,denominator: number)

A constructor used to create a **RationalNumber** object.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | numerator  | number  | Yes | Numerator, which is an integer. |
 | denominator  | number  | Yes | Denominator, which is an integer. |

**Example**
  ```js
  var rationalNumber = new util.RationalNumber(1,2);
  ```


### createRationalFromString<sup>8+</sup>

static createRationalFromString​(rationalString: string): RationalNumber​

Creates a **RationalNumber** object based on the given string.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | rationalString  | string  | Yes | String used to create the **RationalNumber** object. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | object  | **RationalNumber** object created. |

**Example**
  ```js
  var rationalNumber = new util.RationalNumber(1,2);
  var rational = rationalNumer.creatRationalFromString("3/4");
  ```


### compareTo<sup>8+</sup>

compareTo​(another: RationalNumber): number​

Compares this **RationalNumber** object with a given object.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | another  | RationalNumber  | Yes | Object used to compare with this **RationalNumber** object. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | number  | Returns **0** if the two objects are equal; returns **1** if the given object is less than this object; return **-1** if the given object is greater than this object. |

**Example**

  ```js
  var rationalNumber = new util.RationalNumber(1,2);
  var rational = rationalNumer.creatRationalFromString("3/4");
  var result = rationalNumber.compareTo(rational);
  ```


### valueOf<sup>8+</sup>

valueOf(): number

Obtains the value of this **RationalNumber** object as an integer or a floating-point number.

**System capability**: SystemCapability.Utils.Lang

**Return value**
 | Type | Description |
 | --------  | --------  |
 | number  | An integer or a floating-point number. |

**Example**
  ```js
  var rationalNumber = new util.RationalNumber(1,2);
  var result = rationalNumber.valueOf();
  ```


### equals<sup>8+</sup>

equals​(obj: Object): boolean

Checks whether this **RationalNumber** object equals the given object.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | object  | Object  | Yes | Object used to compare with this **RationalNumber** object. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | boolean  | Returns **true** if the two objects are equal; returns **false** otherwise. |

**Example**
  ```js
  var rationalNumber = new util.RationalNumber(1,2);
  var rational = rationalNumer.creatRationalFromString("3/4");
  var result = rationalNumber.equals(rational);
  ```


### getCommonDivisor<sup>8+</sup>

static getCommonDivisor​(number1: number,number2: number): number

Obtains the greatest common divisor of two specified integers.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | number1  | number  | Yes | The first integer used to get the greatest common divisor. |
 | number2  | number  | Yes | The second integer used to get the greatest common divisor. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | number  | Greatest common divisor obtained. |

**Example**
  ```js
  var rationalNumber = new util.RationalNumber(1,2);
  var result = rationalNumber.getCommonDivisor(4,6);
  ```


### getNumerator<sup>8+</sup>

getNumerator​(): number

Obtains the numerator of this **RationalNumber** object.

**System capability**: SystemCapability.Utils.Lang

**Return value**

 | Type | Description |
 | --------  | --------  |
 | number  | Numerator of this **RationalNumber** object. |

**Example**
  ```js
  var rationalNumber = new util.RationalNumber(1,2);
  var result = rationalNumber.getNumerator();
  ```


### getDenominator<sup>8+</sup>

getDenominator​(): number

Obtains the denominator of this **RationalNumber** object.

**System capability**: SystemCapability.Utils.Lang

**Return value**
 | Type | Description |
 | --------  | --------  |
 | number  | Denominator of this **RationalNumber** object. |

**Example**
  ```js
  var rationalNumber = new util.RationalNumber(1,2);
  var result = rationalNumber.getDenominator();
  ```


### isZero<sup>8+</sup>

isZero​(): boolean

Checks whether this **RationalNumber** object is **0**.

**System capability**: SystemCapability.Utils.Lang

**Return value**
 | Type | Description |
 | --------  | --------  |
 | boolean  | Returns **true** if the value of this **RationalNumber** object is **0**; returns **false** otherwise. |

**Example**
  ```js
  var rationalNumber = new util.RationalNumber(1,2);
  var result = rationalNumber.isZero();
  ```


### isNaN<sup>8+</sup>

isNaN​(): boolean

Checks whether this **RationalNumber** object is a Not a Number (NaN).

**System capability**: SystemCapability.Utils.Lang

**Return value**
 | Type | Description |
 | --------  | --------  |
 | boolean  | Returns **true** if this **RationalNumber** object is a NaN (the denominator and numerator are both **0**); returns **false** otherwise. |

**Example**
  ```js
  var rationalNumber = new util.RationalNumber(1,2);
  var result = rationalNumber.isNaN();
  ```


### isFinite<sup>8+</sup>

isFinite​(): boolean

Checks whether this **RationalNumber** object represents a finite value.

**System capability**: SystemCapability.Utils.Lang

**Return value**
 | Type | Description |
 | --------  | --------  |
 | boolean  | Returns **true** if this **RationalNumber** object represents a finite value (the denominator is not **0**); returns **false** otherwise. |

**Example**
  ```js
  var rationalNumber = new util.RationalNumber(1,2);
  var result = rationalNumber.isFinite();
  ```


### toString<sup>8+</sup>

toString​(): string

Obtains the string representation of this **RationalNumber** object.

**System capability**: SystemCapability.Utils.Lang

**Return value**
 | Type | Description |
 | --------  | --------  |
 | string  | Returns **NaN** if the numerator and denominator of this object are both **0**; returns a string in Numerator/Denominator format otherwise, for example, **3/5**. |

**Example**
  ```js
  var rationalNumber = new util.RationalNumber(1,2);
  var result = rationalNumber.toString();
  ```

## LruBuffer<sup>8+</sup>

### Attributes

**System capability**: SystemCapability.Utils.Lang

 | Name | Type | Readable | Writable | Description |
 | --------  | --------  | --------  | --------  | --------  |
 | length  | number  | Yes | No | Total number of values in this buffer. |

**Example**
  ```js
  var pro = new util.LruBuffer();
  pro.put(2,10);
  pro.put(1,8);
  var result = pro.length;
  ```


### constructor<sup>8+</sup>

constructor(capacity?: number)

A constructor used to create an **LruBuffer** instance. The default capacity of the buffer is 64.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | capacity  | number  | No | Capacity of the **LruBuffer** to create. |

**Example**
  ```js
  var lrubuffer= new util.LruBuffer();
  ```


### updateCapacity<sup>8+</sup>

updateCapacity(newCapacity: number): void

Changes the **LruBuffer** capacity. If the new capacity is less than or equal to **0**, an exception will be thrown.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | newCapacity  | number  | Yes | New capacity of the **LruBuffer**. |

**Example**
  ```js
  var pro = new util.LruBuffer();
  var result = pro.updateCapacity(100);
  ```


### toString<sup>8+</sup>

toString(): string

Obtains the string representation of this **LruBuffer** object.

**System capability**: SystemCapability.Utils.Lang

**Return value**
 | Type | Description |
 | --------  | --------  |
 | string  | String representation of this **LruBuffer** object. |

**Example**
  ```js
  var pro = new util.LruBuffer();
  pro.put(2,10);
  pro.get(2);
  pro.remove(20);
  var result = pro.toString();
  ```


### getCapacity<sup>8+</sup>

getCapacity(): number

Obtains the capacity of this buffer.

**System capability**: SystemCapability.Utils.Lang

**Return value**
 | Type | Description |
 | --------  | --------  |
 | number  | Capacity of this buffer. |

**Example**
  ```js
  var pro = new util.LruBuffer();
  var result = pro.getCapacity();
  ```


### clear<sup>8+</sup>

clear(): void

Clears key-value pairs from this buffer. The **afterRemoval()** method will be called to perform subsequent operations.

**System capability**: SystemCapability.Utils.Lang

**Example**
  ```js
  var pro = new util.LruBuffer();
  pro.put(2,10);
  var result = pro.size();
  pro.clear();
  ```


### getCreateCount<sup>8+</sup>

getCreateCount(): number

Obtains the number of return values for **createDefault()**.

**System capability**: SystemCapability.Utils.Lang

**Return value**
 | Type | Description |
 | --------  | --------  |
 | number  | Number of return values for **createDefault()**. |

**Example**
  ```js
  var pro = new util.LruBuffer();
  pro.put(1,8);
  var result = pro.getCreateCount();
  ```


### getMissCount<sup>8+</sup>

getMissCount(): number

Obtains the number of times that the queried values are mismatched.

**System capability**: SystemCapability.Utils.Lang

**Return value**
 | Type | Description |
 | --------  | --------  |
 | number  | Number of times that the queried values are mismatched. |

**Example**
  ```js
  var pro = new util.LruBuffer();
  pro.put(2,10);
  pro.get(2);
  var result = pro.getMissCount();
  ```


### getRemovalCount<sup>8+</sup>

getRemovalCount(): number

Obtains the number of removals from this buffer.

**System capability**: SystemCapability.Utils.Lang

**Return value**
 | Type | Description |
 | --------  | --------  |
 | number  | Number of removals from the buffer. |

**Example**
  ```js
  var pro = new util.LruBuffer();
  pro.put(2,10);
  pro.updateCapacity(2);
  pro.put(50,22);
  var result = pro.getRemovalCount();
  ```


### getMatchCount<sup>8+</sup>

getMatchCount(): number

Obtains the number of times that the queried values are matched.

**System capability**: SystemCapability.Utils.Lang

**Return value**
 | Type | Description |
 | --------  | --------  |
 | number  | Number of times that the queried values are matched. |

**Example**
  ```js
  var pro = new util.LruBuffer();
  pro.put(2,10);
  pro.get(2);
  var result = pro.getMatchCount();
  ```


### getPutCount<sup>8+</sup>

getPutCount(): number

Obtains the number of additions to this buffer.

**System capability**: SystemCapability.Utils.Lang

**Return value**
 | Type | Description |
 | --------  | --------  |
 | number  | Number of additions to the buffer. |

**Example**
  ```js
  var pro = new util.LruBuffer();
  pro.put(2,10);
  var result = pro.getPutCount();
  ```


### isEmpty<sup>8+</sup>

isEmpty(): boolean

Checks whether this buffer is empty.

**System capability**: SystemCapability.Utils.Lang

**Return value**
 | Type | Description |
 | --------  | --------  |
 | boolean  | Returns **true** if the buffer does not contain any value. |

**Example**
  ```js
  var pro = new util.LruBuffer();
  pro.put(2,10);
  var result = pro.isEmpty();
  ```


### get<sup>8+</sup>

get(key: K): V  | undefined

Obtains the value of the specified key.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | key  | K  | Yes | Key based on which the value is queried. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | V&nbsp;\ |&nbsp;undefind  | Returns the value of the key if a match is found in the buffer; returns **undefined** otherwise. |

**Example**
  ```js
  var pro = new util.LruBuffer();
  pro.put(2,10);
  var result  = pro.get(2);
  ```


### put<sup>8+</sup>

put(key: K,value: V): V

Adds a key-value pair to this buffer.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | key  | K  | Yes | Key of the key-value pair to add. |
 | value  | V  | Yes | Value of the key-value pair to add. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | V  | Returns the existing value if the key already exists; returns the value added otherwise. If the key or value is null, an exception will be thrown.  |

**Example**
  ```js
  var pro = new util.LruBuffer();
  var result = pro.put(2,10);
  ```


### values<sup>8+</sup>

values(): V[]

Obtains all values in this buffer, listed from the most to the least recently accessed.

**System capability**: SystemCapability.Utils.Lang

**Return value**
 | Type | Description |
 | --------  | --------  |
 | V&nbsp;[]  | All values in the buffer, listed from the most to the least recently accessed. |

**Example**
  ```js
  var pro = new util.LruBuffer();
  pro.put(2,10);
  pro.put(2,"anhu");
  pro.put("afaf","grfb");
  var result = pro.values();
  ```


### keys<sup>8+</sup>

keys(): K[]

Obtains all keys in this buffer, listed from the most to the least recently accessed.

**System capability**: SystemCapability.Utils.Lang

**Return value**
 | Type | Description |
 | --------  | --------  |
 | K&nbsp;[]  | All keys in the buffer, listed from the most to the least recently accessed. |

**Example**
  ```js
  var pro = new util.LruBuffer();
  pro.put(2,10);
  var result = pro.keys();
  ```


### remove<sup>8+</sup>

remove(key: K): V  | undefined

Removes the specified key and its value from this buffer.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | key  | K  | Yes | Key to remove. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | V&nbsp;\ |&nbsp;undefind  | Returns an **Optional** object containing the removed key-value pair if the key exists in the buffer; returns an empty **Optional** object otherwise. If the key is null, an exception will be thrown. |

**Example**
  ```js
  var pro = new util.LruBuffer();
  pro.put(2,10);
  var result = pro.remove(20);
  ```


### afterRemoval<sup>8+</sup>

afterRemoval(isEvict: boolean,key: K,value: V,newValue: V): void

Performs subsequent operations after a value is removed.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | isEvict  | boolean  | No | Whether the buffer capacity is insufficient. If the value is **true**, this method is called due to insufficient capacity. |
 | key  | K  | Yes | Key removed. |
 | value  | V  | Yes | Value removed. |
 | newValue  | V  | No | New value for the key if the **put()** method is called and the key to be added already exists. In other cases, this parameter is left blank. |

**Example**
  ```js
  var arr = [];
  class ChildLruBuffer extends util.LruBuffer
  {
  	constructor()
  	{
  		super();
  	}
  	static getInstance()
  	{
  		if(this.instance ==  null)
  		{
  			this.instance = new ChildLruBuffer();
  		}
  		return this.instance;  
  	}
  	afterRemoval(isEvict, key, value, newValue)
  	{
  		if (isEvict === false)
  		{
  			arr = [key, value, newValue];
  		}
  	}
  }
  ChildLruBuffer.getInstance().afterRemoval(false,10,30,null);
  ```


### contains<sup>8+</sup>

contains(key: K): boolean

Checks whether this buffer contains the specified key.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | key  | K  | Yes | Key to check. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | boolean  | Returns **true** if the buffer contains the specified key; returns **false** otherwise. |

**Example**
  ```js
  var pro = new util.LruBuffer();
  pro.put(2,10);
  var result = pro.contains(20);
  ```


### createDefault<sup>8+</sup>

createDefault(key: K): V

Creates a value if the value of the specified key is not available.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | key  | K  | Yes | Key of which the value is missing. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | V  | Value of the key. |

**Example**
  ```js
  var pro = new util.LruBuffer();
  var result = pro.createDefault(50);
  ```


### entries<sup>8+</sup>

entries(): IterableIterator&lt;[K,V]&gt;

Obtains a new iterator object that contains all key-value pairs in this object.

**System capability**: SystemCapability.Utils.Lang

**Return value**
 | Type | Description |
 | --------  | --------  |
 | [K,&nbsp;V]  | Iterable array. |

**Example**
  ```js
  var pro = new util.LruBuffer();
  pro.put(2,10);
  var result = pro.entries();
  ```


### [Symbol.iterator]<sup>8+</sup>

[Symbol.iterator]\(): IterableIterator&lt;[K, V]&gt;

Obtains a two-dimensional array in key-value pairs.

**System capability**: SystemCapability.Utils.Lang

**Return value**
 | Type | Description |
 | --------  | --------  |
 | [K,&nbsp;V]  | Two-dimensional array in key-value pairs. |

**Example**
  ```js
  var pro = new util.LruBuffer();
  pro.put(2,10);
  var result = pro[symbol.iterator]();
  ```


## Scope<sup>8+</sup>


### ScopeType<sup>8+</sup>

Defines the type of values in a **Scope** object. The value type can be **ScopeComparable** or **number**.

The values of the **ScopeComparable** type are used to implement the **compareTo** method. Therefore, ensure that the input parameters are comparable.
```js
interface ScopeComparable{
    compareTo(other: ScopeComparable): boolean;
}
type ScopeType = ScopeComparable  | number;
```


Create a class to implement the **compareTo** method. In the subsequent sample code, **Temperature** is used as an example of the [ScopeType](#scopetype8) object.


Example
```js
class Temperature{
    constructor(value){
       this._temp = value;
    }
    comapreTo(value){
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


### constructor<sup>8+</sup>

constructor(lowerObj: ScopeType, upperObj: ScopeType)

A constructor used to create a **Scope** object with the specified upper and lower limits.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | lowerObj  | [ScopeType](#scopetype8)  | Yes | Lower limit of the **Scope** object. |
 | upperObj  | [ScopeType](#scopetype8)  | Yes | Upper limit of the **Scope** object. |

**Example**
  ```js
  var tempLower = new Temperature(30);
  var tempUpper = new Temperature(40);
  var range = new util.Scope(tempLower, tempUpper);
  ```


### toString<sup>8+</sup>

toString(): string

Obtains a string representation that contains this **Scope**.

**System capability**: SystemCapability.Utils.Lang

**Return value**
 | Type | Description |
 | --------  | --------  |
 | string  | String representation containing the **Scope**. |

**Example**
  ```js
  var tempLower = new Temperature(30);
  var tempUpper = new Temperature(40);
  var range = new util.Scope(tempLower, tempUpper);
  var result = range.toString();
  ```


### intersect<sup>8+</sup>

intersect(range: Scope): Scope

Obtains the intersection of this **Scope** and the given **Scope**.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | range  | [Scope](#scope8)  | Yes | **Scope** specified. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | [Scope](#scope8)  | Intersection of this **Scope** and the given **Scope**. |

**Example**
  ```js
  var tempLower = new Temperature(30);
  var tempUpper = new Temperature(40);
  var range = new util.Scope(tempLower, tempUpper);
  var tempMiDF = new Temperature(35);
  var tempMidS = new Temperature(39);
  var rangeFir = new util.Scope(tempMiDF, tempMidS);
  range.intersect(rangeFir );
  ```


### intersect<sup>8+</sup>

intersect(lowerObj: ScopeType,upperObj: ScopeType): Scope

Obtains the intersection of this **Scope** and the given lower and upper limits.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | lowerObj  | [ScopeType](#scopetype8)  | Yes | Lower limit. |
 | upperObj  | [ScopeType](#scopetype8)  | Yes | Upper limit. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | [Scope](#scope8)  | Intersection of this **Scope** and the given lower and upper limits. |

**Example**
  ```js
  var tempLower = new Temperature(30);
  var tempUpper = new Temperature(40);
  var tempMiDF = new Temperature(35);
  var tempMidS = new Temperature(39);
  var range = new util.Scope(tempLower, tempUpper);
  var result = range.intersect(tempMiDF, tempMidS);
  ```


### getUpper<sup>8+</sup>

getUpper(): ScopeType

Obtains the upper limit of this **Scope**.

**System capability**: SystemCapability.Utils.Lang

**Return value**

 | Type | Description |
 | --------  | --------  |
 | [ScopeType](#scopetype8)  | Upper limit of this **Scope**. |

**Example**
  ```js
  var tempLower = new Temperature(30);
  var tempUpper = new Temperature(40);
  var range = new util.Scope(tempLower, tempUpper);
  var result = range.getUpper();
  ```


### getLower<sup>8+</sup>

getLower(): ScopeType

Obtains the lower limit of this **Scope**.

**System capability**: SystemCapability.Utils.Lang

**Return value**
 | Type | Description |
 | --------  | --------  |
 | [ScopeType](#scopetype8)  | Lower limit of this **Scope**. |

**Example**
  ```js
  var tempLower = new Temperature(30);
  var tempUpper = new Temperature(40);
  var range = new util.Scope(tempLower, tempUpper);
  var result = range.getLower();
  ```


### expand<sup>8+</sup>

expand(lowerObj: ScopeType,upperObj: ScopeType): Scope

Obtains the union set of this **Scope** and the given lower and upper limits.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | lowerObj  | [ScopeType](#scopetype8)  | Yes | Lower limit. |
 | upperObj  | [ScopeType](#scopetype8)  | Yes | Upper limit. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | [Scope](#scope8)  | Union set of this **Scope** and the given lower and upper limits. |

**Example**
  ```js
  var tempLower = new Temperature(30);
  var tempUpper = new Temperature(40);
  var tempMiDF = new Temperature(35);
  var tempMidS = new Temperature(39);
  var range = new util.Scope(tempLower, tempUpper);
  var result = range.expand(tempMiDF, tempMidS);
  ```


### expand<sup>8+</sup>

expand(range:Scope):Scope

Obtains the union set of this **Scope** and the given **Scope**.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | range  | [Scope](#scope8)  | Yes | **Scope** specified. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | [Scope](#scope8)  | Union set of this **Scope** and the given **Scope**. |

**Example**
  ```js
  var tempLower = new Temperature(30);
  var tempUpper = new Temperature(40);
  var tempMiDF = new Temperature(35);
  var tempMidS = new Temperature(39);
  var range = new util.Scope(tempLower, tempUpper);
  var rangeFir = new util.Scope(tempMiDF, tempMidS);
  var result = range.expand(rangeFir);
  ```


### expand<sup>8+</sup>

expand(value: ScopeType): Scope

Obtains the union set of this **Scope** and the given value.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | value  | [ScopeType](#scopetype8)  | Yes | Value specified. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | [Scope](#scope8)  | Union set of this **Scope** and the given value. |

**Example**
  ```js
  var tempLower = new Temperature(30);
  var tempUpper = new Temperature(40);
  var tempMiDF = new Temperature(35);
  var range = new util.Scope(tempLower, tempUpper);
  var result = range.expand(tempMiDF);
  ```


### contains<sup>8+</sup>

contains(value: ScopeType): boolean

Checks whether a value is within this **Scope**.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | value  | [ScopeType](#scopetype8)  | Yes | Value specified. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | boolean  | Returns **true** if the value is within this **Scope**; returns **false** otherwise. |

**Example**
  ```js
  var tempLower = new Temperature(30);
  var tempUpper = new Temperature(40);
  var tempMiDF = new Temperature(35);
  var range = new util.Scope(tempLower, tempUpper);
  range.contains(tempMiDF);
  ```


### contains<sup>8+</sup>

contains(range: Scope): boolean

Checks whether a range is within this **Scope**.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | range  | [Scope](#scope8)  | Yes | **Scope** specified. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | boolean  | Returns **true** if the range is within this **Scope**; returns **false** otherwise. |

**Example**
  ```js
  var tempLower = new Temperature(30);
  var tempUpper = new Temperature(40);
  var range = new util.Scope(tempLower, tempUpper);
  var tempLess = new Temperature(20);
  var tempMore = new Temperature(45);
  var rangeSec = new util.Scope(tempLess, tempMore);
  var result = range.contains(rangeSec);
  ```


### clamp<sup>8+</sup>

clamp(value: ScopeType): ScopeType

Limits a value to this **Scope**.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | value  | [ScopeType](#scopetype8)  | Yes | Value specified. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | [ScopeType](#scopetype8)  | Returns **lowerObj** if the specified value is less than the lower limit; returns **upperObj** if the specified value is greater than the upper limit; returns the specified value if it is within this **Scope**. |

**Example**
  ```js
  var tempLower = new Temperature(30);
  var tempUpper = new Temperature(40);
  var tempMiDF = new Temperature(35);
  var range = new util.Scope(tempLower, tempUpper);
  var result = range.clamp(tempMiDF);
  ```


## Base64<sup>8+</sup>


### constructor<sup>8+</sup>

constructor()

A constructor used to create a **Base64** object.

**System capability**: SystemCapability.Utils.Lang

**Example**
  ```js
  var base64 = new  util.Base64();
  ```


### encodeSync<sup>8+</sup>

encodeSync(src: Uint8Array): Uint8Array

Encodes the input content.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | src  | Uint8Array  | Yes | Uint8Array to encode. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | Uint8Array  | Uint8Array encoded. |

**Example**
  ```js
  var that = new util.Base64();
  var array = new Uint8Array([115,49,51]);
  var result = that.encodeSync(array);
  ```


### encodeToStringSync<sup>8+</sup>

encodeToStringSync(src: Uint8Array): string

Encodes the input content.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | src  | Uint8Array  | Yes | Uint8Array to encode. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | string  | String encoded from the Uint8Array. |

**Example**
  ```js
  var that = new util.Base64();
  var array = new Uint8Array([115,49,51]);
  var result = that.encodeToStringSync(array);
  ```


### decodeSync<sup>8+</sup>

decodeSync(src: Uint8Array  | string): Uint8Array

Decodes the input content.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | src  | Uint8Array&nbsp;\ |&nbsp;string  | Yes | Uint8Array or string to decode. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | Uint8Array  | Uint8Array decoded. |

**Example**
  ```js
  var that = new util.Base64();
  var buff = 'czEz';
  var result = that.decodeSync(buff);
  ```


### encode<sup>8+</sup>

encode(src: Uint8Array): Promise&lt;Uint8Array&gt;

Encodes the input content asynchronously.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | src  | Uint8Array  | Yes | Uint8Array to encode asynchronously. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | Promise&lt;Uint8Array&gt;  | Uint8Array obtained after asynchronous encoding. |

**Example**
  ```js
  var that = new util.Base64();
  var array = new Uint8Array([115,49,51]);
  var rarray = new Uint8Array([99,122,69,122]);
  that.encode(array).then(val=>{    
      for (var i = 0; i < rarray.length; i++) {        
          console.log(val[i])
      }
  })
  ```


### encodeToString<sup>8+</sup>

encodeToString(src: Uint8Array): Promise&lt;string&gt;

Encodes the input content asynchronously.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | src  | Uint8Array  | Yes | Uint8Array to encode asynchronously. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | Promise&lt;string&gt;  | String obtained after asynchronous encoding. |

**Example**
  ```js
  var that = new util.Base64();
  var array = new Uint8Array([115,49,51]);
  that.encodeToString(array).then(val=>{    
      console.log(val)
  })
  ```


### decode<sup>8+</sup>

decode(src: Uint8Array  | string): Promise&lt;Uint8Array&gt;

Decodes the input content asynchronously.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | src  | Uint8Array&nbsp;\ |&nbsp;string  | Yes | Uint8Array or string to decode asynchronously. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | Promise&lt;Uint8Array&gt;  | Uint8Array obtained after asynchronous decoding. |

**Example**
  ```js
  var that = new util.Base64();
  var array = new Uint8Array([99,122,69,122]);
  var rarray = new Uint8Array([115,49,51]);
  that.decode(array).then(val=>{    
      for (var i = 0; i < rarray.length; i++) {        
          console.log(val[i])
      }
  })
  ```


## types<sup>8+</sup>


### constructor<sup>8+</sup>

constructor()

A constructor used to create a **types** object.

**System capability**: SystemCapability.Utils.Lang

**Example**
  ```js
  var type = new util.types();
  ```


### isAnyArrayBuffer<sup>8+</sup>

isAnyArrayBuffer(value: Object): boolean

Checks whether the input value is of the **ArrayBuffer** type.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | value  | Object  | Yes | Object to check. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | boolean  | Returns **true** if the input value is of the **ArrayBuffer** type; returns **false** otherwise. |

**Example**
  ```js
  var that = new util.types();
  var result = that.isAnyArrayBuffer(new ArrayBuffer([]));
  ```


### isArrayBufferView<sup>8+</sup>

isArrayBufferView(value: Object): boolean

Checks whether the input value is of the **ArrayBufferView** type.

**ArrayBufferView** is a helper type representing any of the following: **Int8Array**, **Int16Array**, **Int32Array**, **Uint8Array**, **Uint8ClampedArray**, **Uint32Array**, **Float32Array**, **Float64Array**, and **DataView**.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | value  | Object  | Yes | Object to check. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | boolean  | Returns **true** if the input value is of the **ArrayBufferView** type; returns **false** otherwise. |

**Example**
  ```js
  var that = new util.types();
  var result = that.isArrayBufferView(new Int8Array([]));
  ```


### isArgumentsObject<sup>8+</sup>

isArgumentsObject(value: Object): boolean

Checks whether the input value is of the **arguments** type.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | value  | Object  | Yes | Object to check. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | boolean  | Returns **true** if the input value is of the **arguments** type; returns **false** otherwise. |

**Example**
  ```js
  var that = new util.types();
  function foo() {
      var result = that.isArgumentsObject(arguments);
  }
  var f = foo();
  ```


### isArrayBuffer<sup>8+</sup>

isArrayBuffer(value: Object): boolean

Checks whether the input value is of the **ArrayBuffer** type.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | value  | Object  | Yes | Object to check. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | boolean  | Returns **true** if the input value is of the **ArrayBuffer** type; returns **false** otherwise. |

**Example**
  ```js
  var that = new util.types();
  var result = that.isArrayBuffer(new ArrayBuffer([]));
  ```


### isAsyncFunction<sup>8+</sup>

isAsyncFunction(value: Object): boolean

Checks whether the input value is an asynchronous function.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | value  | Object  | Yes | Object to check. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | boolean  | Returns **true** if the input value is an asynchronous function; returns **false** otherwise. |

**Example**
  ```js
  var that = new util.types();
  var result = that.isAsyncFunction(async function foo() {});
  ```


### isBooleanObject<sup>8+</sup>

isBooleanObject(value: Object): boolean

Checks whether the input value is of the **Boolean** type.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | value  | Object  | Yes | Object to check. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | boolean  | Returns **true** if the input value is of the **Boolean** type; returns **false** otherwise. |

**Example**
  ```js
  var that = new util.types();
  var result = that.isBooleanObject(new Boolean(true));
  ```


### isBoxedPrimitive<sup>8+</sup>

isBoxedPrimitive(value: Object): boolean

Checks whether the input value is of the **Boolean**, **Number**, **String**, or **Symbol** type.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | value  | Object  | Yes | Object to check. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | boolean  | Returns **true** if the input value is of the **Boolean**, **Number**, **String**, or **Symbol** type; returns **false** otherwise. |

**Example**
  ```js
  var that = new util.types();
  var result = that.isBoxedPrimitive(new Boolean(false));
  ```


### isDataView<sup>8+</sup>

isDataView(value: Object): boolean

Checks whether the input value is of the **DataView** type.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | value  | Object  | Yes | Object to check. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | boolean  | Returns **true** if the input value is of the **DataView** type; returns **false** otherwise. |

**Example**
  ```js
  var that = new util.types();
  const ab = new ArrayBuffer(20);
  var result = that.isDataView(new DataView(ab));
  ```


### isDate<sup>8+</sup>

isDate(value: Object): boolean

Checks whether the input value is of the **Date** type.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | value  | Object  | Yes | Object to check. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | boolean  | Returns **true** if the input value is of the **Date** type; returns **false** otherwise. |

**Example**
  ```js
  var that = new util.types();
  var result = that.isDate(new Date());
  ```


### isExternal<sup>8+</sup>

isExternal(value: Object): boolean

Checks whether the input value is of the **native external** type.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | value  | Object  | Yes | Object to check. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | boolean  | Returns **true** if the input value is of the **native external** type; returns **false** otherwise. |

**Example**
  ```js
  var that = new util.types();
  const data = util.createExternalType();
  var result = that.isExternal(data);
  ```


### isFloat32Array<sup>8+</sup>

isFloat32Array(value: Object): boolean

Checks whether the input value is of the **Float32Array** type.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | value  | Object  | Yes | Object to check. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | boolean  | Returns **true** if the input value is of the **Float32Array** type; returns **false** otherwise. |

**Example**
  ```js
  var that = new util.types();
  var result = that.isFloat32Array(new Float32Array());
  ```


### isFloat64Array<sup>8+</sup>

isFloat64Array(value: Object): boolean

Checks whether the input value is of the **Float64Array** type.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | value  | Object  | Yes | Object to check. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | boolean  | Returns **true** if the input value is of the **Float64Array** type; returns **false** otherwise. |

**Example**
  ```js
  var that = new util.types();
  var result = that.isFloat64Array(new Float64Array());
  ```


### isGeneratorFunction<sup>8+</sup>

isGeneratorFunction(value: Object): boolean

Checks whether the input value is a generator function.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | value  | Object  | Yes | Object to check. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | boolean  | Returns **true** if the input value is a generator function; returns **false** otherwise. |

**Example**
  ```js
  var that = new util.types();
  var result = that.isGeneratorFunction(function* foo() {});
  ```


### isGeneratorObject<sup>8+</sup>

isGeneratorObject(value: Object): boolean

Checks whether the input value is a generator object.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | value  | Object  | Yes | Object to check. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | boolean  | Returns **true** if the input value is a generator object; returns **false** otherwise. |

**Example**
  ```js
  var that = new util.types();
  function* foo() {}
  const generator = foo();
  var result = that.isGeneratorObject(generator);
  ```


### isInt8Array<sup>8+</sup>

isInt8Array(value: Object): boolean

Checks whether the input value is of the **Int8Array** type.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | value  | Object  | Yes | Object to check. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | boolean  | Returns **true** if the input value is of the **Int8Array** type; returns **false** otherwise. |

**Example**
  ```js
  var that = new util.types();
  var result = that.isInt8Array(new Int8Array([]));
  ```


### isInt16Array<sup>8+</sup>

isInt16Array(value: Object): boolean

Checks whether the input value is of the **Int16Array** type.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | value  | Object  | Yes | Object to check. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | boolean  | Returns **true** if the input value is of the **Int16Array** type; returns **false** otherwise. |

**Example**
  ```js
  var that = new util.types();
  var result = that.isInt16Array(new Int16Array([]));
  ```


### isInt32Array<sup>8+</sup>

isInt32Array(value: Object): boolean

Checks whether the input value is of the **Int32Array** type.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | value  | Object  | Yes | Object to check. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | boolean  | Returns **true** if the input value is of the **Int32Array** type; returns **false** otherwise. |

**Example**
  ```js
  var that = new util.types();
  var result = that.isInt32Array(new Int32Array([]));
  ```


### isMap<sup>8+</sup>

isMap(value: Object): boolean

Checks whether the input value is of the **Map** type.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | value  | Object  | Yes | Object to check. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | boolean  | Returns **true** if the input value is of the **Map** type; returns **false** otherwise. |

**Example**
  ```js
  var that = new util.types();
  var result = that.isMap(new Map());
  ```


### isMapIterator<sup>8+</sup>

isMapIterator(value: Object): boolean

Checks whether the input value is of the **MapIterator** type.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | value  | Object  | Yes | Object to check. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | boolean  | Returns **true** if the input value is of the **MapIterator** type; returns **false** otherwise. |

**Example**
  ```js
  var that = new util.types();
  const map = new Map();
  var result = that.isMapIterator(map.keys());
  ```


### isNativeError<sup>8+</sup>

isNativeError(value: Object): boolean

Checks whether the input value is of the **Error** type.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | value  | Object  | Yes | Object to check. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | boolean  | Returns **true** if the input value is of the **Error** type; returns **false** otherwise. |

**Example**
  ```js
  var that = new util.types();
  var result = that.isNativeError(new TypeError());
  ```


### isNumberObject<sup>8+</sup>

isNumberObject(value: Object): boolean

Checks whether the input value is a number object.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | value  | Object  | Yes | Object to check. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | boolean  | Returns **true** if the input value is a number object; returns **false** otherwise. |

**Example**
  ```js
  var that = new util.types();
  var result = that.isNumberObject(new Number(0));
  ```


### isPromise<sup>8+</sup>

isPromise(value: Object): boolean

Checks whether the input value is a promise.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | value  | Object  | Yes | Object to check. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | boolean  | Returns **true** if the input value is a promise; returns **false** otherwise. |

**Example**
  ```js
  var that = new util.types();
  var result = that.isPromise(Promise.resolve(1));
  ```


### isProxy<sup>8+</sup>

isProxy(value: Object): boolean

Checks whether the input value is a proxy.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | value  | Object  | Yes | Object to check. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | boolean  | Returns **true** if the input value is a proxy; returns **false** otherwise. |

**Example**
  ```js
  var that = new util.types();
  const target = {};
  const proxy = new Proxy(target, {});
  var result = that.isProxy(proxy);
  ```


### isRegExp<sup>8+</sup>

isRegExp(value: Object): boolean

Checks whether the input value is of the **RegExp** type.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | value  | Object  | Yes | Object to check. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | boolean  | Returns **true** if the input value is of the **RegExp** type; returns **false** otherwise. |

**Example**
  ```js
  var that = new util.types();
  var result = that.isRegExp(new RegExp('abc'));
  ```


### isSet<sup>8+</sup>

isSet(value: Object): boolean

Checks whether the input value is of the **Set** type.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | value  | Object  | Yes | Object to check. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | boolean  | Returns **true** if the input value is of the **Set** type; returns **false** otherwise. |

**Example**
  ```js
  var that = new util.types();
  var result = that.isSet(new Set());
  ```


### isSetIterator<sup>8+</sup>

isSetIterator(value: Object): boolean

Checks whether the input value is of the **SetIterator** type.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | value  | Object  | Yes | Object to check. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | boolean  | Returns **true** if the input value is of the **SetIterator** type; returns **false** otherwise. |

**Example**
  ```js
  var that = new util.types();
  const set = new Set();
  var result = that.isSetIterator(set.keys());
  ```


### isStringObject<sup>8+</sup>

isStringObject(value: Object): boolean

Checks whether the input value is a string object.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | value  | Object  | Yes | Object to check. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | boolean  | Returns **true** if the input value is a string object; returns **false** otherwise. |

**Example**
  ```js
  var that = new util.types();
  var result = that.isStringObject(new String('foo'));
  ```


### isSymbolObjec<sup>8+</sup>

isSymbolObject(value: Object): boolean

Checks whether the input value is a symbol object.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | value  | Object  | Yes | Object to check. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | boolean  | Returns **true** if the input value is a symbol object; returns **false** otherwise. |

**Example**
  ```js
  var that = new util.types();
  const symbols = Symbol('foo');
  var result = that.isSymbolObject(Object(symbols));
  ```


### isTypedArray<sup>8+</sup>

isTypedArray(value: Object): boolean

Checks whether the input value is of the **TypedArray** type.

**TypedArray** is a helper type representing any of the following: **Int8Array**, **Int16Array**, **Int32Array**, **Uint8Array**, **Uint8ClampedArray**, **Uint16Array**, **Uint32Array**, **Float32Array**, **Float64Array**, and **DataView**.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | value  | Object  | Yes | Object to check. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | boolean  | Returns **true** if the input value is of the **TypedArray** type; returns **false** otherwise. |

**Example**
  ```js
  var that = new util.types();
  var result = that.isTypedArray(new Float64Array([]));
  ```


### isUint8Array<sup>8+</sup>

isUint8Array(value: Object): boolean

Checks whether the input value is of the **Uint8Array** type.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | value  | Object  | Yes | Object to check. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | boolean  | Returns **true** if the input value is of the **Uint8Array** type; returns **false** otherwise. |

**Example**
  ```js
  var that = new util.types();
  var result = that.isUint8Array(new Uint8Array([]));
  ```


### isUint8ClampedArray<sup>8+</sup>

isUint8ClampedArray(value: Object): boolean

Checks whether the input value is of the **Uint8ClampedArray** type.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | value  | Object  | Yes | Object to check. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | boolean  | Returns **true** if the input value is of the **Uint8ClampedArray** type; returns **false** otherwise. |

**Example**
  ```js
  var that = new util.types();
  var result = that.isUint8ClampedArray(new Uint8ClampedArray([]));
  ```


### isUint16Array<sup>8+</sup>

isUint16Array(value: Object): boolean

Checks whether the input value is of the **Uint16Array** type.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | value  | Object  | Yes | Object to check. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | boolean  | Returns **true** if the input value is of the **Uint16Array** type; returns **false** otherwise. |

**Example**
  ```js
  var that = new util.types();
  var result = that.isUint16Array(new Uint16Array([]));
  ```


### isUint32Array<sup>8+</sup>

isUint32Array(value: Object): boolean

Checks whether the input value is of the **Uint32Array** type.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | value  | Object  | Yes | Object to check. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | boolean  | Returns **true** if the input value is of the **Uint32Array** type; returns **false** otherwise. |

**Example**
  ```js
  var that = new util.types();
  var result = that.isUint32Array(new Uint32Array([]));
  ```


### isWeakMap<sup>8+</sup>

isWeakMap(value: Object): boolean

Checks whether the input value is of the **WeakMap** type.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | value  | Object  | Yes | Object to check. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | boolean  | Returns **true** if the input value is of the **WeakMap** type; returns **false** otherwise. |

**Example**
  ```js
  var that = new util.types();
  var result = that.isWeakMap(new WeakMap());
  ```


### isWeakSet<sup>8+</sup>

isWeakSet(value: Object): boolean

Checks whether the input value is of the **WeakSet** type.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
 | Name | Type | Mandatory | Description |
 | --------  | --------  | --------  | --------  |
 | value  | Object  | Yes | Object to check. |

**Return value**
 | Type | Description |
 | --------  | --------  |
 | boolean  | Returns **true** if the input value is of the **WeakSet** type; returns **false** otherwise. |

**Example**
  ```js
  var that = new util.types();
  var result = that.isWeakSet(new WeakSet());
  ```