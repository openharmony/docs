# util

> **Note：**
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


This module provides common utility functions, such as **TextEncoder** and **TextDecoder** for string encoding and decoding, **RationalNumber** for rational number operations, **LruBuffer** for buffer management, **Scope** for range determination, **Base64** for Base64 encoding and decoding, and **Types** for checks of built-in object types.


## Modules to Import


```
import util from '@ohos.util';
```



## util.printf

printf(format: string,  ...args: Object[]): string

Prints the input content in a formatted string.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | format | string | Yes | Format&nbsp;of&nbsp;the&nbsp;string&nbsp;to&nbsp;print. | 
  | ...args | Object[] | No | Data&nbsp;to&nbsp;format. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | string | String&nbsp;in&nbsp;the&nbsp;specified&nbsp;format. | 

- Example
  
  ```
  var res = util.printf("%s", "hello world!");
  console.log(res);
  ```


## util.getErrorString

getErrorString(errno: number): string

Obtains detailed information about a system error code.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | errno | number | Yes | Error&nbsp;code&nbsp;generated. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | string | Detailed&nbsp;information&nbsp;about&nbsp;the&nbsp;error&nbsp;code. | 

- Example
  
  ```
  var errnum = 10; // 10 is the system error code.
  var result = util.getErrorString(errnum);
  console.log("result = " + result);
  ```


## util.callbackWrapper

callbackWrapper(original: Function): (err: Object, value: Object )=&gt;void

Calls back an asynchronous function. In the callback, the first parameter indicates the cause of the rejection (the value is **null** if the promise has been resolved), and the second parameter indicates the resolved value.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | original | Function | Yes | Asynchronous&nbsp;function&nbsp;to&nbsp;process. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | Function | Callback,&nbsp;in&nbsp;which&nbsp;the&nbsp;first&nbsp;parameter&nbsp;indicates&nbsp;the&nbsp;cause&nbsp;of&nbsp;the&nbsp;rejection&nbsp;(the&nbsp;value&nbsp;is&nbsp;**null**&nbsp;if&nbsp;the&nbsp;promise&nbsp;has&nbsp;been&nbsp;resolved)&nbsp;and&nbsp;the&nbsp;second&nbsp;parameter&nbsp;indicates&nbsp;the&nbsp;resolved&nbsp;value. | 

- Example
  
  ```
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

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | original | Function | Yes | Asynchronous&nbsp;function&nbsp;to&nbsp;process. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | Function | Function&nbsp;in&nbsp;the&nbsp;error-first&nbsp;style&nbsp;(that&nbsp;is,&nbsp;**(err,&nbsp;value)&nbsp;=&gt;...**&nbsp;is&nbsp;called&nbsp;as&nbsp;the&nbsp;last&nbsp;parameter)&nbsp;and&nbsp;the&nbsp;promise&nbsp;version. | 

- Example
  
  ```
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

  | Name | Type | Readable | Writable | Description | 
| -------- | -------- | -------- | -------- | -------- |
| encoding | string | Yes | No | Encoding&nbsp;format.<br/>-&nbsp;Supported&nbsp;formats:&nbsp;utf-8,&nbsp;ibm866,&nbsp;iso-8859-2,&nbsp;iso-8859-3,&nbsp;iso-8859-4,&nbsp;iso-8859-5,&nbsp;iso-8859-6,&nbsp;iso-8859-7,&nbsp;iso-8859-8,&nbsp;iso-8859-8-i,&nbsp;iso-8859-10,&nbsp;iso-8859-13,&nbsp;iso-8859-14,&nbsp;iso-8859-15,&nbsp;koi8-r,&nbsp;koi8-u,&nbsp;macintosh,&nbsp;windows-874,&nbsp;windows-1250,&nbsp;windows-1251,&nbsp;windows-1252,&nbsp;windows-1253,&nbsp;windows-1254,&nbsp;windows-1255,&nbsp;windows-1256,&nbsp;windows-1257,&nbsp;windows-1258,&nbsp;x-mac-cyrilli,&nbsp;gbk,&nbsp;gb18030,&nbsp;big5,&nbsp;euc-jp,&nbsp;iso-2022-jp,&nbsp;shift_jis,&nbsp;euc-kr,&nbsp;utf-16be,&nbsp;utf-16le | 
| fatal | boolean | Yes | No | Whether&nbsp;to&nbsp;display&nbsp;fatal&nbsp;errors. | 
| ignoreBOM | boolean | Yes | No | Whether&nbsp;to&nbsp;ignore&nbsp;the&nbsp;byte&nbsp;order&nbsp;marker&nbsp;(BOM).&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;**false**,&nbsp;which&nbsp;indicates&nbsp;that&nbsp;the&nbsp;result&nbsp;contains&nbsp;the&nbsp;BOM. | 


### constructor

constructor(encoding?:string, options?:{ fatal?:boolean;ignoreBOM?:boolean })

A constructor used to create a **TextDecoder** object.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | encoding | string | No | Encoding&nbsp;format. | 
  | options | Object | No | Encoding-related&nbsp;options,&nbsp;which&nbsp;include&nbsp;**fatal**&nbsp;and&nbsp;**ignoreBOM**. | 

    **Table 1** options
  
  | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | fatal | boolean | No | Whether&nbsp;to&nbsp;display&nbsp;fatal&nbsp;errors. | 
  | ignoreBOM | boolean | No | Whether&nbsp;to&nbsp;ignore&nbsp;the&nbsp;BOM. | 

- Example
  
  ```
  var textDecoder = new util.TextDecoder("utf-8",{ignoreBOM:true});
  ```


### decode

decode(input: Unit8Array, options?:{stream?:false}):string

Decodes the input content.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | input | Unit8Array | Yes | Uint8Array&nbsp;to&nbsp;decode. | 
  | options | Object | No | Options&nbsp;related&nbsp;to&nbsp;decoding. | 

    **Table 2** options
  
  | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | stream | boolean | No | Whether&nbsp;to&nbsp;allow&nbsp;data&nbsp;blocks&nbsp;in&nbsp;subsequent&nbsp;**decode()**.&nbsp;If&nbsp;data&nbsp;is&nbsp;processed&nbsp;in&nbsp;blocks,&nbsp;set&nbsp;this&nbsp;parameter&nbsp;to&nbsp;**true**.&nbsp;If&nbsp;this&nbsp;is&nbsp;the&nbsp;last&nbsp;data&nbsp;block&nbsp;to&nbsp;process&nbsp;or&nbsp;data&nbsp;is&nbsp;not&nbsp;divided&nbsp;into&nbsp;blocks,&nbsp;set&nbsp;this&nbsp;parameter&nbsp;to&nbsp;**false**.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;**false**. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | string | Data&nbsp;decoded. | 

- Example
  
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


### Attributes

  | Name | Type | Readable | Writable | Description | 
| -------- | -------- | -------- | -------- | -------- |
| encoding | string | Yes | No | Encoding&nbsp;format.&nbsp;The&nbsp;default&nbsp;format&nbsp;is&nbsp;**utf-8**. | 


### constructor

constructor()

A constructor used to create a **TextEncoder** object.

- Example
  
  ```
  var textEncoder = new util.TextEncoder();
  ```


### encode

encode(input?:string):Uint8Array

Encodes the input content.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | input | string | Yes | String&nbsp;to&nbsp;encode. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | Uint8Array | Encoded&nbsp;text. | 

- Example
  
  ```
  var textEncoder = new util.TextEncoder();
  var result = new Uint8Array(buffer);
  result = textEncoder.encode("\uD800¥¥");
  ```


### encodeInto

encodeInto(input:string, dest:Uint8Array, ):{ read:number; written:number }

Stores the UTF-8 encoded text.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | input | string | Yes | String&nbsp;to&nbsp;encode. | 
  | dest | Uint8Array | Yes | Uint8Array&nbsp;object&nbsp;used&nbsp;to&nbsp;hold&nbsp;the&nbsp;UTF-8&nbsp;encoded&nbsp;text. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | Uint8Array | Encoded&nbsp;text. | 

- Example
  
  ```
  var that = new util.TextEncoder();
  var buffer = new ArrayBuffer(4);
  this.dest = new Uint8Array(buffer);
  var result = that.encodeInto("abcd", this.dest);
  ```


## RationalNumber<sup>8+</sup>


### constructor<sup>8+</sup>

constructor(numerator:number,denominator:number)

A constructor used to create a **RationalNumber** object.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | numerator | number | Yes | Numerator,&nbsp;which&nbsp;is&nbsp;an&nbsp;integer. | 
  | denominator | number | Yes | Denominator,&nbsp;which&nbsp;is&nbsp;an&nbsp;integer. | 

- Example
  
  ```
  var rationalNumber = new util.RationalNumber(1,2);
  ```


### createRationalFromString<sup>8+</sup>

static createRationalFromString​(rationalString:string):RationalNumber​

Creates a **RationalNumber** object using the given string.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | rationalString | string | Yes | String&nbsp;used&nbsp;to&nbsp;create&nbsp;the&nbsp;**RationalNumber**&nbsp;object. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | object | **RationalNumber**&nbsp;object&nbsp;created. | 

- Example
  
  ```
  var rationalNumber = new util.RationalNumber(1,2);
  var rational = rationalNumer.creatRationalFromString("3/4");
  ```


### compareTo<sup>8+</sup>

compareTo​(another:RationalNumber):number​

Compares this **RationalNumber** object with a given object.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | another | RationalNumber | Yes | Object&nbsp;used&nbsp;to&nbsp;compare&nbsp;with&nbsp;this&nbsp;**RationalNumber**&nbsp;object. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | number | Returns&nbsp;**0**&nbsp;if&nbsp;the&nbsp;two&nbsp;objects&nbsp;are&nbsp;equal;&nbsp;returns&nbsp;**1**&nbsp;if&nbsp;the&nbsp;given&nbsp;object&nbsp;is&nbsp;less&nbsp;than&nbsp;this&nbsp;object;&nbsp;return&nbsp;**-1**&nbsp;if&nbsp;the&nbsp;given&nbsp;object&nbsp;is&nbsp;greater&nbsp;than&nbsp;this&nbsp;object. | 

- Example
  
  ```
  var rationalNumber = new util.RationalNumber(1,2);
  var rational = rationalNumer.creatRationalFromString("3/4");
  var result = rationalNumber.compareTo(rational);
  ```


### valueOf<sup>8+</sup>

valueOf():number

Obtains the value of this **RationalNumber** object as an integer or a floating-point number.

- Return values
    | Type | Description | 
  | -------- | -------- |
  | number | An&nbsp;integer&nbsp;or&nbsp;a&nbsp;floating-point&nbsp;number. | 

- Example
  
  ```
  var rationalNumber = new util.RationalNumber(1,2);
  var result = rationalNumber.valueOf();
  ```


### equals<sup>8+</sup>

equals​(obj:Object):boolean

Checks whether this **RationalNumber** object equals the given object.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | object | Object | Yes | Object&nbsp;used&nbsp;to&nbsp;compare&nbsp;with&nbsp;this&nbsp;**RationalNumber**&nbsp;object. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;two&nbsp;objects&nbsp;are&nbsp;equal;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  var rationalNumber = new util.RationalNumber(1,2);
  var rational = rationalNumer.creatRationalFromString("3/4");
  var result = rationalNumber.equals(rational);
  ```


### getCommonDivisor<sup>8+</sup>

static getCommonDivisor​(number1:number,number2:number):number

Obtains the greatest common divisor of the two specified integers.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | number1 | number | Yes | The&nbsp;first&nbsp;integer&nbsp;used&nbsp;to&nbsp;get&nbsp;the&nbsp;greatest&nbsp;common&nbsp;divisor. | 
  | number2 | number | Yes | The&nbsp;second&nbsp;integer&nbsp;used&nbsp;to&nbsp;get&nbsp;the&nbsp;greatest&nbsp;common&nbsp;divisor. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | number | Greatest&nbsp;common&nbsp;divisor&nbsp;obtained. | 

- Example
  
  ```
  var rationalNumber = new util.RationalNumber(1,2);
  var result = rationalNumber.getCommonDivisor(4,6);
  ```


### getNumerator<sup>8+</sup>

getNumerator​():number

Obtains the numerator of this **RationalNumber** object.

- Return values
    | Type | Description | 
  | -------- | -------- |
  | number | Numerator&nbsp;of&nbsp;this&nbsp;**RationalNumber**&nbsp;object. | 

- Example
  
  ```
  var rationalNumber = new util.RationalNumber(1,2);
  var result = rationalNumber.getNumerator();
  ```


### getDenominator<sup>8+</sup>

getDenominator​():number

Obtains the denominator of this **RationalNumber** object.

- Return values
    | Type | Description | 
  | -------- | -------- |
  | number | Denominator&nbsp;of&nbsp;this&nbsp;**RationalNumber**&nbsp;object. | 

- Example
  
  ```
  var rationalNumber = new util.RationalNumber(1,2);
  var result = rationalNumber.getDenominator();
  ```


### isZero<sup>8+</sup>

isZero​():boolean

Checks whether this **RationalNumber** object is **0**.

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;value&nbsp;of&nbsp;this&nbsp;**RationalNumber**&nbsp;object&nbsp;is&nbsp;**0**;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  var rationalNumber = new util.RationalNumber(1,2);
  var result = rationalNumber.isZero();
  ```


### isNaN<sup>8+</sup>

isNaN​():boolean

Checks whether this **RationalNumber** object is a Not a Number (NaN).

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;this&nbsp;**RationalNumber**&nbsp;object&nbsp;is&nbsp;a&nbsp;NaN&nbsp;(the&nbsp;denominator&nbsp;and&nbsp;numerator&nbsp;are&nbsp;both&nbsp;**0**);&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  var rationalNumber = new util.RationalNumber(1,2);
  var result = rationalNumber.isNaN();
  ```


### isFinite<sup>8+</sup>

isFinite​():boolean

Checks whether this **RationalNumber** object represents a finite value.

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;this&nbsp;**RationalNumber**&nbsp;object&nbsp;represents&nbsp;a&nbsp;finite&nbsp;value&nbsp;(the&nbsp;denominator&nbsp;is&nbsp;not&nbsp;**0**);&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  var rationalNumber = new util.RationalNumber(1,2);
  var result = rationalNumber.isFinite();
  ```


### toString<sup>8+</sup>

toString​():string

Obtains the string representation of this **RationalNumber** object.

- Return values
    | Type | Description | 
  | -------- | -------- |
  | string | Returns&nbsp;**NaN**&nbsp;if&nbsp;the&nbsp;numerator&nbsp;and&nbsp;denominator&nbsp;of&nbsp;this&nbsp;object&nbsp;are&nbsp;both&nbsp;**0**;&nbsp;returns&nbsp;a&nbsp;string&nbsp;in&nbsp;Numerator/Denominator&nbsp;format&nbsp;otherwise,&nbsp;for&nbsp;example,&nbsp;**3/5**. | 

- Example
  
  ```
  var rationalNumber = new util.RationalNumber(1,2);
  var result = rationalNumber.toString();
  ```


## LruBuffer<sup>8+</sup>


### Attributes

  | Name | Type | Readable | Writable | Description | 
| -------- | -------- | -------- | -------- | -------- |
| length | number | Yes | No | Total&nbsp;number&nbsp;of&nbsp;values&nbsp;in&nbsp;this&nbsp;buffer. | 

- Example
  
  ```
  var pro = new util.LruBuffer();
  pro.put(2,10);
  pro.put(1,8);
  var result = pro.length;
  ```


### constructor<sup>8+</sup>

constructor(capacity?:number)

A constructor used to create an **LruBuffer** instance. The default capacity of the buffer is 64.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | capacity | number | No | Capacity&nbsp;of&nbsp;the&nbsp;**LruBuffer**&nbsp;to&nbsp;create. | 

- Example
  
  ```
  var lrubuffer= new util.LruBuffer();
  ```


### updateCapacity<sup>8+</sup>

updateCapacity(newCapacity:number):void

Changes the **LruBuffer** capacity. If the new capacity is less than or equal to **0**, an exception will be thrown.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | newCapacity | number | Yes | New&nbsp;capacity&nbsp;of&nbsp;the&nbsp;buffer. | 

- Example
  
  ```
  var pro = new util.LruBuffer();
  var result = pro.updateCapacity(100);
  ```


### toString<sup>8+</sup>

toString():string

Obtains the string representation of this **LruBuffer** object.

- Return values
    | Type | Description | 
  | -------- | -------- |
  | string | String&nbsp;representation&nbsp;of&nbsp;this&nbsp;object. | 

- Example
  
  ```
  var pro = new util.LruBuffer();
  pro.put(2,10);
  pro.get(2);
  pro.remove(20);
  var result = pro.toString();
  ```


### getCapacity<sup>8+</sup>

getCapacity():number

Obtains the capacity of this buffer.

- Return values
    | Type | Description | 
  | -------- | -------- |
  | number | Capacity&nbsp;of&nbsp;this&nbsp;buffer. | 

- Example
  
  ```
  var pro = new util.LruBuffer();
  var result = pro.getCapacity();
  ```


### clear<sup>8+</sup>

clear():void

Clears key-value pairs from this buffer. The **afterRemoval()** method will be called to perform subsequent operations.

- Example
  
  ```
  var pro = new util.LruBuffer();
  pro.put(2,10);
  var result = pro.size();
  pro.clear();
  ```


### getCreateCount<sup>8+</sup>

getCreateCount():number

Obtains the number of return values for **createDefault()**.

- Return values
    | Type | Description | 
  | -------- | -------- |
  | number | Number&nbsp;of&nbsp;return&nbsp;values&nbsp;for&nbsp;**createDefault()**. | 

- Example
  
  ```
  var pro = new util.LruBuffer();
  pro.put(1,8);
  var result = pro.getCreateCount();
  ```


### getMissCount<sup>8+</sup>

getMissCount():number

Obtains the number of times that the queried values are mismatched.

- Return values
    | Type | Description | 
  | -------- | -------- |
  | number | Number&nbsp;of&nbsp;times&nbsp;that&nbsp;the&nbsp;queried&nbsp;values&nbsp;are&nbsp;mismatched. | 

- Example
  
  ```
  var pro = new util.LruBuffer();
  pro.put(2,10);
  pro.get(2);
  var result = pro.getMissCount();
  ```


### getRemovalCount<sup>8+</sup>

getRemovalCount():number

Obtains the number of removals from this buffer.

- Return values
    | Type | Description | 
  | -------- | -------- |
  | number | Number&nbsp;of&nbsp;removals&nbsp;from&nbsp;the&nbsp;buffer. | 

- Example
  
  ```
  var pro = new util.LruBuffer();
  pro.put(2,10);
  pro.updateCapacity(2);
  pro.put(50,22);
  var result = pro.getRemovalCount();
  ```


### getMatchCount<sup>8+</sup>

getMatchCount():number

Obtains the number of times that the queried values are matched.

- Return values
    | Type | Description | 
  | -------- | -------- |
  | number | Number&nbsp;of&nbsp;times&nbsp;that&nbsp;the&nbsp;queried&nbsp;values&nbsp;are&nbsp;matched. | 

- Example
  
  ```
  var pro = new util.LruBuffer();
  pro.put(2,10);
  pro.get(2);
  var result = pro.getMatchCount();
  ```


### getPutCount<sup>8+</sup>

getPutCount():number

Obtains the number of additions to this buffer.

- Return values
    | Type | Description | 
  | -------- | -------- |
  | number | Number&nbsp;of&nbsp;additions&nbsp;to&nbsp;the&nbsp;buffer. | 

- Example
  
  ```
  var pro = new util.LruBuffer();
  pro.put(2,10);
  var result = pro.getPutCount();
  ```


### isEmpty<sup>8+</sup>

isEmpty():boolean

Checks whether this buffer is empty.

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;buffer&nbsp;does&nbsp;not&nbsp;contain&nbsp;any&nbsp;value. | 

- Example
  
  ```
  var pro = new util.LruBuffer();
  pro.put(2,10);
  var result = pro.isEmpty();
  ```


### get<sup>8+</sup>

get(key:K):V | undefined

Obtains the value of the specified key.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | key | K | Yes | Key&nbsp;based&nbsp;on&nbsp;which&nbsp;the&nbsp;value&nbsp;is&nbsp;queried. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | V&nbsp;\|&nbsp;undefind | Returns&nbsp;the&nbsp;value&nbsp;of&nbsp;the&nbsp;key&nbsp;if&nbsp;a&nbsp;match&nbsp;is&nbsp;found&nbsp;in&nbsp;the&nbsp;buffer;&nbsp;returns&nbsp;**undefined**&nbsp;otherwise. | 

- Example
  
  ```
  var pro = new util.LruBuffer();
  pro.put(2,10);
  var result  = pro.get(2);
  ```


### put<sup>8+</sup>

put(key:K,value:V):V

Adds a key-value pair to this buffer.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | key | K | Yes | Key&nbsp;of&nbsp;the&nbsp;key-value&nbsp;pair&nbsp;to&nbsp;add. | 
  | value | V | Yes | Value&nbsp;of&nbsp;the&nbsp;key-value&nbsp;pair&nbsp;to&nbsp;add. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | V | Returns&nbsp;the&nbsp;existing&nbsp;value&nbsp;if&nbsp;the&nbsp;key&nbsp;already&nbsp;exists;&nbsp;returns&nbsp;the&nbsp;value&nbsp;added&nbsp;otherwise.&nbsp;If&nbsp;the&nbsp;key&nbsp;or&nbsp;value&nbsp;is&nbsp;null,&nbsp;an&nbsp;exception&nbsp;will&nbsp;be&nbsp;thrown. | 

- Example
  
  ```
  var pro = new util.LruBuffer();
  var result = pro.put(2,10);
  ```


### values<sup>8+</sup>

values():V[]

Obtains all values in this buffer, listed from the most to the least recently accessed.

- Return values
    | Type | Description | 
  | -------- | -------- |
  | V&nbsp;[] | All&nbsp;values&nbsp;in&nbsp;the&nbsp;buffer,&nbsp;listed&nbsp;from&nbsp;the&nbsp;most&nbsp;to&nbsp;the&nbsp;least&nbsp;recently&nbsp;accessed. | 

- Example
  
  ```
  var pro = new util.LruBuffer();
  pro.put(2,10);
  pro.put(2,"anhu");
  pro.put("afaf","grfb");
  var result = pro.values();
  ```


### keys<sup>8+</sup>

keys():K[]

Obtains all keys in this buffer, listed from the most to the least recently accessed.

- Return values
    | Type | Description | 
  | -------- | -------- |
  | K&nbsp;[] | All&nbsp;keys&nbsp;in&nbsp;the&nbsp;buffer,&nbsp;listed&nbsp;from&nbsp;the&nbsp;most&nbsp;to&nbsp;the&nbsp;least&nbsp;recently&nbsp;accessed. | 

- Example
  
  ```
  var pro = new util.LruBuffer();
  pro.put(2,10);
  var result = pro.keys();
  ```


### remove<sup>8+</sup>

remove(key:K):V | undefined

Deletes the specified key and its value from this buffer.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | key | K | Yes | Key&nbsp;to&nbsp;delete. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | V&nbsp;\|&nbsp;undefind | Returns&nbsp;an&nbsp;**Optional**&nbsp;object&nbsp;containing&nbsp;the&nbsp;deleted&nbsp;key-value&nbsp;pair&nbsp;if&nbsp;the&nbsp;key&nbsp;exists&nbsp;in&nbsp;the&nbsp;buffer;&nbsp;returns&nbsp;an&nbsp;empty&nbsp;**Optional**&nbsp;object&nbsp;otherwise.&nbsp;If&nbsp;the&nbsp;key&nbsp;is&nbsp;null,&nbsp;an&nbsp;exception&nbsp;will&nbsp;be&nbsp;thrown. | 

- Example
  
  ```
  var pro = new util.LruBuffer();
  pro.put(2,10);
  var result = pro.remove(20);
  ```


### afterRemoval<sup>8+</sup>

afterRemoval(isEvict:boolean,key:K,value:V,newValue:V):void

Performs subsequent operations after a value is deleted.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | isEvict | boolean | No | Whether&nbsp;the&nbsp;buffer&nbsp;capacity&nbsp;is&nbsp;insufficient.&nbsp;If&nbsp;the&nbsp;value&nbsp;is&nbsp;**true**,&nbsp;this&nbsp;method&nbsp;is&nbsp;called&nbsp;due&nbsp;to&nbsp;insufficient&nbsp;capacity. | 
  | key | K | Yes | Key&nbsp;deleted. | 
  | value | V | Yes | Value&nbsp;deleted. | 
  | newValue | V | No | New&nbsp;value&nbsp;for&nbsp;the&nbsp;key&nbsp;if&nbsp;the&nbsp;**put()**&nbsp;method&nbsp;is&nbsp;called&nbsp;and&nbsp;the&nbsp;key&nbsp;to&nbsp;be&nbsp;added&nbsp;already&nbsp;exists.&nbsp;In&nbsp;other&nbsp;cases,&nbsp;this&nbsp;parameter&nbsp;is&nbsp;left&nbsp;blank. | 

- Example
  
  ```
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

contains(key:K):boolean

Checks whether this buffer contains the specified key.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | key | K | Yes | Key&nbsp;to&nbsp;check. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;buffer&nbsp;contains&nbsp;the&nbsp;specified&nbsp;key;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  var pro = new util.LruBuffer();
  pro.put(2,10);
  var result = pro.contains(20);
  ```


### createDefault<sup>8+</sup>

createDefault(key:K):V

Creates a value if the value of the specified key is not available.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | key | K | Yes | Key&nbsp;of&nbsp;which&nbsp;the&nbsp;value&nbsp;is&nbsp;missing. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | V | Value&nbsp;of&nbsp;the&nbsp;key. | 

- Example
  
  ```
  var pro = new util.LruBuffer();
  var result = pro.createDefault(50);
  ```


### entries<sup>8+</sup>

entries():IterableIterator&lt;[K,V]&gt;

Obtains a new iterator object that contains all key-value pairs in this object.

- Return values
    | Type | Description | 
  | -------- | -------- |
  | [K,&nbsp;V] | Returns&nbsp;an&nbsp;iterable&nbsp;array. | 

- Example
  
  ```
  var pro = new util.LruBuffer();
  pro.put(2,10);
  var result = pro.entries();
  ```


### [Symbol.iterator]<sup>8+</sup>

[Symbol.iterator](): IterableIterator&lt;[K, V]&gt;

Obtains a two-dimensional array in key-value pairs.

- Return values
    | Type | Description | 
  | -------- | -------- |
  | [K,&nbsp;V] | A&nbsp;two-dimensional&nbsp;array&nbsp;in&nbsp;key-value&nbsp;pairs. | 

- Example
  
  ```
  var pro = new util.LruBuffer();
  pro.put(2,10);
  var result = pro[symbol.iterator]();
  ```


## Scope<sup>8+</sup>


### ScopeType<sup>8+</sup>

Defines the type of values in a **Scope** object. The value type can be **ScopeComparable** or **number**.

  The values of the **ScopeComparable** type are used to implement the **compareTo** method. Therefore, ensure that the input parameters are comparable.

```
interface ScopeComparable{
    compareTo(other:ScopeComparable):boolean;
}
type ScopeType = ScopeComparable | number;
```


Create a class to implement the **compareTo** method. In the subsequent sample code, **Temperature** is used as an example of the [ScopeType](#scopetype8) object.


  Example

```
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

constructor(lowerObj:ScopeType,upperObje:ScopeType)

A constructor used to create a **Scope** object with the specified upper and lower limits.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | lowerObj | [ScopeType](#scopetype8) | Yes | Lower&nbsp;limit&nbsp;of&nbsp;the&nbsp;**Scope**&nbsp;object. | 
  | upperObj | [ScopeType](#scopetype8) | Yes | Upper&nbsp;limit&nbsp;of&nbsp;the&nbsp;**Scope**&nbsp;object. | 

- Example
  
  ```
  var tempLower = new Temperature(30);
  var tempUpper = new Temperature(40);
  var range = new util.Scope(tempLower, tempUpper);
  ```


### toString<sup>8+</sup>

toString():string

Obtains a string representation that contains this **Scope**.

- Return values
    | Type | Description | 
  | -------- | -------- |
  | string | String&nbsp;representation&nbsp;containing&nbsp;the&nbsp;**Scope**. | 

- Example
  
  ```
  var tempLower = new Temperature(30);
  var tempUpper = new Temperature(40);
  var range = new util.Scope(tempLower, tempUpper);
  var result = range.toString();
  ```


### intersect<sup>8+</sup>

intersect(range:Scope):Scope

Obtains the intersection of this **Scope** and the given **Scope**.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | range | [Scope](#scope8) | Yes | **Scope**&nbsp;specified. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | [Scope](#scope8) | Intersection&nbsp;of&nbsp;this&nbsp;**Scope**&nbsp;and&nbsp;the&nbsp;given&nbsp;**Scope**. | 

- Example
  
  ```
  var tempLower = new Temperature(30);
  var tempUpper = new Temperature(40);
  var range = new util.Scope(tempLower, tempUpper);
  var tempMiDF = new Temperature(35);
  var tempMidS = new Temperature(39);
  var rangeFir = new util.Scope(tempMiDF, tempMidS);
  range.intersect(rangeFir );
  ```


### intersect<sup>8+</sup>

intersect(lowerObj:ScopeType,upperObj:ScopeType):Scope

Obtains the intersection of this **Scope** and the given lower and upper limits.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | lowerObj | [ScopeType](#scopetype8) | Yes | Lower&nbsp;limit. | 
  | upperObj | [ScopeType](#scopetype8) | Yes | Upper&nbsp;limit. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | [Scope](#scope8) | Intersection&nbsp;of&nbsp;this&nbsp;**Scope**&nbsp;and&nbsp;the&nbsp;given&nbsp;lower&nbsp;and&nbsp;upper&nbsp;limits. | 

- Example
  
  ```
  var tempLower = new Temperature(30);
  var tempUpper = new Temperature(40);
  var tempMiDF = new Temperature(35);
  var tempMidS = new Temperature(39);
  var range = new util.Scope(tempLower, tempUpper);
  var result = range.intersect(tempMiDF, tempMidS);
  ```


### getUpper<sup>8+</sup>

getUpper():ScopeType

Obtains the upper limit of this **Scope**.

- Return values
    | Type | Description | 
  | -------- | -------- |
  | [ScopeType](#scopetype8) | Upper&nbsp;limit&nbsp;of&nbsp;this&nbsp;**Scope**. | 

- Example
  
  ```
  var tempLower = new Temperature(30);
  var tempUpper = new Temperature(40);
  var range = new util.Scope(tempLower, tempUpper);
  var result = range.getUpper();
  ```


### getLower<sup>8+</sup>

getLower():ScopeType

Obtains the lower limit of this **Scope**.

- Return values
    | Type | Description | 
  | -------- | -------- |
  | [ScopeType](#scopetype8) | Lower&nbsp;limit&nbsp;of&nbsp;this&nbsp;**Scope**. | 

- Example
  
  ```
  var tempLower = new Temperature(30);
  var tempUpper = new Temperature(40);
  var range = new util.Scope(tempLower, tempUpper);
  var result = range.getLower();
  ```


### expand<sup>8+</sup>

expand(lowerObj:ScopeType,upperObj:ScopeType):Scope

Obtains the union set of this **Scope** and the given lower and upper limits.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | lowerObj | [ScopeType](#scopetype8) | Yes | Lower&nbsp;limit. | 
  | upperObj | [ScopeType](#scopetype8) | Yes | Upper&nbsp;limit. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | [Scope](#scope8) | Union&nbsp;set&nbsp;of&nbsp;this&nbsp;**Scope**&nbsp;and&nbsp;the&nbsp;given&nbsp;lower&nbsp;and&nbsp;upper&nbsp;limits. | 

- Example
  
  ```
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

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | range | [Scope](#scope8) | Yes | **Scope**&nbsp;specified. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | [Scope](#scope8) | Union&nbsp;set&nbsp;of&nbsp;this&nbsp;**Scope**&nbsp;and&nbsp;the&nbsp;given&nbsp;**Scope**. | 

- Example
  
  ```
  var tempLower = new Temperature(30);
  var tempUpper = new Temperature(40);
  var tempMiDF = new Temperature(35);
  var tempMidS = new Temperature(39);
  var range = new util.Scope(tempLower, tempUpper);
  var rangeFir = new util.Scope(tempMiDF, tempMidS);
  var result = range.expand(rangeFir);
  ```


### expand<sup>8+</sup>

expand(value:ScopeType):Scope

Obtains the union set of this **Scope** and the given value.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | value | [ScopeType](#scopetype8) | Yes | Value&nbsp;specified. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | [Scope](#scope8) | Union&nbsp;set&nbsp;of&nbsp;this&nbsp;**Scope**&nbsp;and&nbsp;the&nbsp;given&nbsp;value. | 

- Example
  
  ```
  var tempLower = new Temperature(30);
  var tempUpper = new Temperature(40);
  var tempMiDF = new Temperature(35);
  var range = new util.Scope(tempLower, tempUpper);
  var result = range.expand(tempMiDF); 
  ```


### contains<sup>8+</sup>

contains(value:ScopeType):boolean

Checks whether a value is within this **Scope**.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | value | [ScopeType](#scopetype8) | Yes | Value&nbsp;specified. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;value&nbsp;is&nbsp;within&nbsp;this&nbsp;**Scope**;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  var tempLower = new Temperature(30);
  var tempUpper = new Temperature(40);
  var tempMiDF = new Temperature(35);
  var range = new util.Scope(tempLower, tempUpper);
  range.contains(tempMiDF);
  ```


### contains<sup>8+</sup>

contains(range:Scope):boolean

Checks whether a range is within this **Scope**.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | range | [Scope](#scope8) | Yes | Range&nbsp;specified. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;range&nbsp;is&nbsp;within&nbsp;this&nbsp;**Scope**;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  var tempLower = new Temperature(30);
  var tempUpper = new Temperature(40);
  var range = new util.Scope(tempLower, tempUpper);
  var tempLess = new Temperature(20);
  var tempMore = new Temperature(45);
  var rangeSec = new util.Scope(tempLess, tempMore);
  var result = range.contains(rangeSec);
  ```


### clamp<sup>8+</sup>

clamp(value:ScopeType):ScopeType

Limits a value to this **Scope**.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | value | [ScopeType](#scopetype8) | Yes | Value&nbsp;specified. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | [ScopeType](#scopetype8) | Returns&nbsp;**lowerObj**&nbsp;if&nbsp;the&nbsp;specified&nbsp;value&nbsp;is&nbsp;less&nbsp;than&nbsp;the&nbsp;lower&nbsp;limit;&nbsp;returns&nbsp;**upperObj**&nbsp;if&nbsp;the&nbsp;specified&nbsp;value&nbsp;is&nbsp;greater&nbsp;than&nbsp;the&nbsp;upper&nbsp;limit;&nbsp;returns&nbsp;the&nbsp;specified&nbsp;value&nbsp;if&nbsp;it&nbsp;is&nbsp;within&nbsp;this&nbsp;**Scope**. | 

- Example
  
  ```
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

- Example
  
  ```
  var base64 = new  util.Base64();
  ```


### encodeSync<sup>8+</sup>

encodeSync(src:Uint8Array):Uint8Array

Encodes the input content.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | src | Uint8Array | Yes | Uint8Array&nbsp;to&nbsp;encode. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | Uint8Array | Uint8Array&nbsp;encoded. | 

- Example
  
  ```
  var that = new util.Base64();
  var array = new Uint8Array([115,49,51]);
  var result = that.encodeSync(array);
  ```


### encodeToStringSync<sup>8+</sup>

encodeToStringSync(src:Uint8Array):string

Encodes the input content into a string.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | src | Uint8Array | Yes | Uint8Array&nbsp;to&nbsp;encode. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | string | String&nbsp;encoded&nbsp;from&nbsp;the&nbsp;Uint8Array. | 

- Example
  
  ```
  var that = new util.Base64();
  var array = new Uint8Array([115,49,51]);
  var result = that.encodeToStringSync(array);
  ```


### decodeSync<sup>8+</sup>

decodeSync(src:Uint8Array | string):Uint8Array

Decodes the input content.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | src | Uint8Array&nbsp;\|&nbsp;string | Yes | Uint8Array&nbsp;or&nbsp;string&nbsp;to&nbsp;decode. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | Uint8Array | Uint8Array&nbsp;decoded. | 

- Example
  
  ```
  var that = new util.Base64();
  var buff = 'czEz';
  var result = that.decodeSync(buff);
  ```


### encode<sup>8+</sup>

encode(src:Uint8Array):Promise&lt;Uint8Array&gt;

Encodes the input content asynchronously.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | src | Uint8Array | Yes | Uint8Array&nbsp;to&nbsp;encode&nbsp;asynchronously. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | Promise&lt;Uint8Array&gt; | Uint8Array&nbsp;obtained&nbsp;after&nbsp;asynchronous&nbsp;encoding. | 

- Example
  
  ```
  var that = new util.Base64();
  var array = new Uint8Array([115,49,51]);
  var rarray = new Uint8Array([99,122,69,122]);
  that.encode(array).then(val=>{    
      for (var i = 0; i < rarray.length; i++) {        
          console.log(val[i]);
      }
  })
  ```


### encodeToString<sup>8+</sup>

encodeToString(src:Uint8Array):Promise&lt;string&gt;

Encodes the input content asynchronously into a string.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | src | Uint8Array | Yes | Uint8Array&nbsp;to&nbsp;encode&nbsp;asynchronously. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | Promise&lt;string&gt; | String&nbsp;obtained&nbsp;after&nbsp;asynchronous&nbsp;encoding. | 

- Example
  
  ```
  var that = new util.Base64();
  var array = new Uint8Array([115,49,51]);
  that.encodeToString(array).then(val=>{    
      console.log(val);
  })
  ```


### decode<sup>8+</sup>

decode(src:Uint8Array | string):Promise&lt;Uint8Array&gt;

Decodes the input content asynchronously.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | src | Uint8Array&nbsp;\|&nbsp;string | Yes | Uint8Array&nbsp;or&nbsp;string&nbsp;to&nbsp;decode&nbsp;asynchronously. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | Promise&lt;Uint8Array&gt; | Uint8Array&nbsp;obtained&nbsp;after&nbsp;asynchronous&nbsp;decoding. | 

- Example
  
  ```
  var that = new util.Base64();
  var array = new Uint8Array([99,122,69,122]);
  var rarray = new Uint8Array([115,49,51]);
  that.decode(array).then(val=>{    
      for (var i = 0; i < rarray.length; i++) {        
          console.log(val[i]);
      }
  })
  ```


## Types<sup>8+</sup>


### constructor<sup>8+</sup>

constructor()

A constructor used to create a **Types** object.

- Example
  
  ```
  var type = new  util.Types();
  ```


### isAnyArrayBuffer<sup>8+</sup>

isAnyArrayBuffer(value: Object):boolean

Checks whether the input value is of the **ArrayBuffer** type.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | value | Object | Yes | Object&nbsp;to&nbsp;check. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;input&nbsp;value&nbsp;is&nbsp;of&nbsp;the&nbsp;**ArrayBuffer**&nbsp;type;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  var that = new util.Types();
  var result = that.isAnyArrayBuffer(new ArrayBuffer([]));
  ```


### isArrayBufferView<sup>8+</sup>

isArrayBufferView(value: Object):boolean

Checks whether the input value is of the **ArrayBufferView** type.

**ArrayBufferView** is a helper type representing any of the following: **Int8Array**, **Int16Array**, **Int32Array**, **Uint8Array**, **Uint8ClampedArray**, **Uint32Array**, **Float32Array**, **Float64Array**, and **DataView**.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | value | Object | Yes | Object&nbsp;to&nbsp;check. | 

    Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;input&nbsp;value&nbsp;is&nbsp;of&nbsp;the&nbsp;**ArrayBufferView**&nbsp;type;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  var that = new util.Types();
  var result = that.isArrayBufferView(new Int8Array([]));
  ```


### isArgumentsObject<sup>8+</sup>

isArgumentsObject(value: Object):boolean

Checks whether the input value is of the **arguments** type.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | value | Object | Yes | Object&nbsp;to&nbsp;check. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;input&nbsp;value&nbsp;is&nbsp;of&nbsp;the&nbsp;**arguments**&nbsp;type;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  var that = new util.Types();
  function foo() {
      var result = that.isArgumentsObject(arguments);
  }
  var f = foo();
  ```


### isArrayBuffer<sup>8+</sup>

isArrayBuffer(value: Object):boolean

Checks whether the input value is of the **ArrayBuffer** type.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | value | Object | Yes | Object&nbsp;to&nbsp;check. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;input&nbsp;value&nbsp;is&nbsp;of&nbsp;the&nbsp;**ArrayBuffer**&nbsp;type;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  var that = new util.Types();
  var result = that.isArrayBuffer(new ArrayBuffer([]));
  ```


### isAsyncFunction<sup>8+</sup>

isAsyncFunction(value: Object):boolean

Checks whether the input value is an asynchronous function.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | value | Object | Yes | Object&nbsp;to&nbsp;check. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;input&nbsp;value&nbsp;is&nbsp;an&nbsp;asynchronous&nbsp;function;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  var that = new util.Types();
  var result = that.isAsyncFunction(async function foo() {});
  ```


### isBooleanObject<sup>8+</sup>

isBooleanObject(value: Object):boolean

Checks whether the input value is of the **Boolean** type.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | value | Object | Yes | Object&nbsp;to&nbsp;check. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;input&nbsp;value&nbsp;is&nbsp;of&nbsp;the&nbsp;**Boolean**&nbsp;type;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  var that = new util.Types();
  var result = that.isBooleanObject(new Boolean(true));
  ```


### isBoxedPrimitive<sup>8+</sup>

isBoxedPrimitive(value: Object):boolean

Checks whether the input value is of the **Boolean**, **Number**, **String**, or **Symbol** type.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | value | Object | Yes | Object&nbsp;to&nbsp;check. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;input&nbsp;value&nbsp;is&nbsp;of&nbsp;the&nbsp;**Boolean**,&nbsp;**Number**,&nbsp;**String**,&nbsp;or&nbsp;**Symbol**&nbsp;type;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  var that = new util.Types();
  var result = that.isBoxedPrimitive(new Boolean(false));
  ```


### isDataView<sup>8+</sup>

isDataView(value: Object):boolean

Checks whether the input value is of the **DataView** type.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | value | Object | Yes | Object&nbsp;to&nbsp;check. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;input&nbsp;value&nbsp;is&nbsp;of&nbsp;the&nbsp;**DataView**&nbsp;type;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  var that = new util.Types();
  const ab = new ArrayBuffer(20);
  var result = that.isDataView(new DataView(ab));
  ```


### isDate<sup>8+</sup>

isDate(value: Object):boolean

Checks whether the input value is of the **Date** type.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | value | Object | Yes | Object&nbsp;to&nbsp;check. | 

- Return values
    | Type | Description |
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;input&nbsp;value&nbsp;is&nbsp;of&nbsp;the&nbsp;**Date**&nbsp;type;&nbsp;returns&nbsp;**false**&nbsp;otherwise. |

- Example
  
  ```
  var that = new util.Types();
  var result = that.isDate(new Date());
  ```


### isExternal<sup>8+</sup>

isExternal(value: Object):boolean

Checks whether the input value is of the **native external** type.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | value | Object | Yes | Object&nbsp;to&nbsp;check. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;input&nbsp;value&nbsp;is&nbsp;of&nbsp;the&nbsp;**native&nbsp;external**&nbsp;type;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  var that = new util.Types();
  const data = util.createExternalType();
  var result = that.isExternal(data);
  ```


### isFloat32Array<sup>8+</sup>

isFloat32Array(value: Object):boolean

Checks whether the input value is of the **Float32Array** type.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | value | Object | Yes | Object&nbsp;to&nbsp;check. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;input&nbsp;value&nbsp;is&nbsp;of&nbsp;the&nbsp;**Float32Array**&nbsp;type;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  var that = new util.Types();
  var result = that.isFloat32Array(new Float32Array());
  ```


### isFloat64Array<sup>8+</sup>

isFloat64Array(value: Object):boolean

Checks whether the input value is of the **Float64Array** type.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | value | Object | Yes | Object&nbsp;to&nbsp;check. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;input&nbsp;value&nbsp;is&nbsp;of&nbsp;the&nbsp;**Float64Array**&nbsp;type;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  var that = new util.Types();
  var result = that.isFloat64Array(new Float64Array());
  ```


### isGeneratorFunction<sup>8+</sup>

isGeneratorFunction(value: Object):boolean

Checks whether the input value is a generator function.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | value | Object | Yes | Object&nbsp;to&nbsp;check. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;input&nbsp;value&nbsp;is&nbsp;a&nbsp;generator&nbsp;function;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  var that = new util.Types();
  var result = that.isGeneratorFunction(function* foo() {});
  ```


### isGeneratorObject<sup>8+</sup>

isGeneratorObject(value: Object):boolean

Checks whether the input value is a generator object.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | value | Object | Yes | Object&nbsp;to&nbsp;check. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;input&nbsp;value&nbsp;is&nbsp;a&nbsp;generator&nbsp;object;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  var that = new util.Types();
  function* foo() {}
  const generator = foo();
  var result = that.isGeneratorObject(generator);
  ```


### isInt8Array<sup>8+</sup>

isInt8Array(value: Object):boolean

Checks whether the input value is of the **Int8Array** type.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | value | Object | Yes | Object&nbsp;to&nbsp;check. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;input&nbsp;value&nbsp;is&nbsp;of&nbsp;the&nbsp;**Int8Array**&nbsp;type;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  var that = new util.Types();
  var result = that.isInt8Array(new Int8Array([]));
  ```


### isInt16Array<sup>8+</sup>

isInt16Array(value: Object):boolean

Checks whether the input value is of the **Int16Array** type.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | value | Object | Yes | Object&nbsp;to&nbsp;check. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;input&nbsp;value&nbsp;is&nbsp;of&nbsp;the&nbsp;**Int16Array**&nbsp;type;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  var that = new util.Types();
  var result = that.isInt16Array(new Int16Array([]));
  ```


### isInt32Array<sup>8+</sup>

isInt32Array(value: Object):boolean

Checks whether the input value is of the **Int32Array** type.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | value | Object | Yes | Object&nbsp;to&nbsp;check. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;input&nbsp;value&nbsp;is&nbsp;of&nbsp;the&nbsp;**Int32Array**&nbsp;type;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  var that = new util.Types();
  var result = that.isInt32Array(new Int32Array([]));
  ```


### isMap<sup>8+</sup>

isMap(value: Object):boolean

Checks whether the input value is of the **Map** type.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | value | Object | Yes | Object&nbsp;to&nbsp;check. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;input&nbsp;value&nbsp;is&nbsp;of&nbsp;the&nbsp;**Map**&nbsp;type;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  var that = new util.Types();
  var result = that.isMap(new Map());
  ```


### isMapIterator<sup>8+</sup>

isMapIterator(value: Object):boolean

Checks whether the input value is of the **MapIterator** type.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | value | Object | Yes | Object&nbsp;to&nbsp;check. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;input&nbsp;value&nbsp;is&nbsp;of&nbsp;the&nbsp;**MapIterator**&nbsp;type;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  var that = new util.Types();
  const map = new Map();
  var result = that.isMapIterator(map.keys());
  ```


### isNativeError<sup>8+</sup>

isNativeError(value: Object):boolean

Checks whether the input value is of the **Error** type.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | value | Object | Yes | Object&nbsp;to&nbsp;check. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;input&nbsp;value&nbsp;is&nbsp;of&nbsp;the&nbsp;**Error**&nbsp;type;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  var that = new util.Types();
  var result = that.isNativeError(new TypeError());
  ```


### isNumberObject<sup>8+</sup>

isNumberObject(value: Object):boolean

Checks whether the input value is a number object.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | value | Object | Yes | Object&nbsp;to&nbsp;check. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;input&nbsp;value&nbsp;is&nbsp;a&nbsp;number&nbsp;object;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  var that = new util.Types();
  var result = that.isNumberObject(new Number(0));
  ```


### isPromise<sup>8+</sup>

isPromise(value: Object):boolean

Checks whether the input value is a promise.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | value | Object | Yes | Object&nbsp;to&nbsp;check. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;input&nbsp;value&nbsp;is&nbsp;a&nbsp;promise;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  var that = new util.Types();
  var result = that.isPromise(Promise.resolve(1));
  ```


### isProxy<sup>8+</sup>

isProxy(value: Object):boolean

Checks whether the input value is a proxy.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | value | Object | Yes | Object&nbsp;to&nbsp;check. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;input&nbsp;value&nbsp;is&nbsp;a&nbsp;proxy;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  var that = new util.Types();
  const target = {};
  const proxy = new Proxy(target, {});
  var result = that.isProxy(proxy);
  ```


### isRegExp<sup>8+</sup>

isRegExp(value: Object):boolean

Checks whether the input value is of the **RegExp** type.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | value | Object | Yes | Object&nbsp;to&nbsp;check. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;input&nbsp;value&nbsp;is&nbsp;of&nbsp;the&nbsp;**RegExp**&nbsp;type;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  var that = new util.Types();
  var result = that.isRegExp(new RegExp('abc'));
  ```


### isSet<sup>8+</sup>

isSet(value: Object):boolean

Checks whether the input value is of the **Set** type.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | value | Object | Yes | Object&nbsp;to&nbsp;check. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;input&nbsp;value&nbsp;is&nbsp;of&nbsp;the&nbsp;**Set**&nbsp;type;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  var that = new util.Types();
  var result = that.isSet(new Set());
  ```


### isSetIterator<sup>8+</sup>

isSetIterator(value: Object):boolean

Checks whether the input value is of the **SetIterator** type.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | value | Object | Yes | Object&nbsp;to&nbsp;check. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;input&nbsp;value&nbsp;is&nbsp;of&nbsp;the&nbsp;**SetIterator**&nbsp;type;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  var that = new util.Types();
  const set = new Set();
  var result = that.isSetIterator(set.keys());
  ```


### isStringObject<sup>8+</sup>

isStringObject(value: Object):boolean

Checks whether the input value is a string object.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | value | Object | Yes | Object&nbsp;to&nbsp;check. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;input&nbsp;value&nbsp;is&nbsp;a&nbsp;string&nbsp;object;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  var that = new util.Types();
  var result = that.isStringObject(new String('foo'));
  ```


### isSymbolObjec<sup>8+</sup>

isSymbolObjec(value: Object):boolean

Checks whether the input value is a symbol object.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | value | Object | Yes | Object&nbsp;to&nbsp;check. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;input&nbsp;value&nbsp;is&nbsp;a&nbsp;symbol&nbsp;object;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  var that = new util.Types();
  const symbols = Symbol('foo');
  var result = that.isSymbolObject(Object(symbols));
  ```


### isTypedArray<sup>8+</sup>

isTypedArray(value: Object):boolean

Checks whether the input value is of the **TypedArray** type.

**TypedArray** is a helper type representing any of the following: **Int8Array**, **Int16Array**, **Int32Array**, **Uint8Array**, **Uint8ClampedArray**, **Uint16Array**, **Uint32Array**, **Float32Array**, **Float64Array**, and **DataView**.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | value | Object | Yes | Object&nbsp;to&nbsp;check. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;input&nbsp;value&nbsp;is&nbsp;of&nbsp;the&nbsp;**TypedArray**&nbsp;type;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  var that = new util.Types();
  var result = that.isTypedArray(new Float64Array([]));
  ```


### isUint8Array<sup>8+</sup>

isUint8Array(value: Object):boolean

Checks whether the input value is of the **Uint8Array** type.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | value | Object | Yes | Object&nbsp;to&nbsp;check. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;input&nbsp;value&nbsp;is&nbsp;of&nbsp;the&nbsp;**Uint8Array**&nbsp;type;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  var that = new util.Types();
  var result = that.isUint8Array(new Uint8Array([]));
  ```


### isUint8ClampedArray<sup>8+</sup>

isUint8ClampedArray(value: Object):boolean

Checks whether the input value is of the **Uint8ClampedArray** type.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | value | Object | Yes | Object&nbsp;to&nbsp;check. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;input&nbsp;value&nbsp;is&nbsp;of&nbsp;the&nbsp;**Uint8ClampedArray**&nbsp;type;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  var that = new util.Types();
  var result = that.isUint8ClampedArray(new Uint8ClampedArray([]));
  ```


### isUint16Array<sup>8+</sup>

isUint16Array(value: Object):boolean

Checks whether the input value is of the **Uint16Array** type.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | value | Object | Yes | Object&nbsp;to&nbsp;check. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;input&nbsp;value&nbsp;is&nbsp;of&nbsp;the&nbsp;**Uint16Array**&nbsp;type;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  var that = new util.Types();
  var result = that.isUint16Array(new Uint16Array([]));
  ```


### isUint32Array<sup>8+</sup>

isUint32Array(value: Object):boolean

Checks whether the input value is of the **Uint32Array** type.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | value | Object | Yes | Object&nbsp;to&nbsp;check. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;input&nbsp;value&nbsp;is&nbsp;of&nbsp;the&nbsp;**Uint32Array**&nbsp;type;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  var that = new util.Types();
  var result = that.isUint32Array(new Uint32Array([]));
  ```


### isWeakMap<sup>8+</sup>

isWeakMap(value: Object):boolean

Checks whether the input value is of the **WeakMap** type.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | value | Object | Yes | Object&nbsp;to&nbsp;check. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;input&nbsp;value&nbsp;is&nbsp;of&nbsp;the&nbsp;**WeakMap**&nbsp;type;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  var that = new util.Types();
  var result = that.isWeakMap(new WeakMap());
  ```


### isWeakSet<sup>8+</sup>

isWeakSet(value: Object):boolean

Checks whether the input value is of the **WeakSet** type.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | value | Object | Yes | Object&nbsp;to&nbsp;check. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;input&nbsp;value&nbsp;is&nbsp;of&nbsp;the&nbsp;**WeakSet**&nbsp;type;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  var that = new util.Types();
  var result = that.isWeakSet(new WeakSet());
  ```
