# @ohos.util.json (JSON Parsing and Generation)

The JSON module provides a series of APIs for converting JSON text into JSON objects or values and converting objects into JSON text.

>**NOTE**
>
>The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import { JSON } from '@kit.ArkTS';
```

## Transformer

type Transformer = (this: Object, key: string, value: Object) => Object | undefined | null

Defines the type of the conversion result function.<br>
When used as a parameter of [JSON.parse](#jsonparse), the function is called by each member of the object, allowing for custom data processing or conversion during parsing.<br>
When used as a parameter of [JSON.stringify](#jsonstringify-1), the function is used to transfer and handle each property during serialization.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description           |
| ------ | ------ | ---- | --------------- |
| this   | Object | Yes| Object to which the key-value pair to parse belongs.|
| key  | string | Yes| Key to parse.|
| value  | Object | Yes| Value of the key.|

**Returns**

| Type| Description|
| -------- | -------- |
| Object \| undefined \| null | Object obtained after parsing, undefined, or null.|

## BigIntMode

Enumerates the modes for processing BigInt.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Name| Value| Description           |
| ------ | ------ | --------------- |
| DEFAULT   | 0 |BigInt is not supported.|
| PARSE_AS_BIGINT   | 1 |Parses an integer that is less than -(2^53-1) or greater than (2^53-1) as BigInt.|
| ALWAYS_PARSE_AS_BIGINT   | 2 |Parses all integers as BigInt.|

## ParseOptions

Describes the parsing options, which can define the mode for processing BigInt.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Name| Type| Mandatory|Description           |
| ------ | ------ | ---- | --------------- |
| bigIntMode   | [BigIntMode](#bigintmode) | Yes|Mode for processing BigInt.|

## JSON.parse

parse(text: string, reviver?: Transformer, options?: ParseOptions): Object | null

Parses a JSON string into an ArkTS object or null.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description           |
| ------ | ------ | ---- | --------------- |
| text   | string | Yes| Valid JSON string.|
| reviver  | [Transformer](#transformer) | No| Conversion function. This parameter can be used to modify the value generated after parsing. The default value is undefined.|
| options   | [ParseOptions](#parseoptions) | No| Parsing options. This parameter is used to control the type of the parsing result. The default value is undefined.|

**Returns**

| Type| Description|
| -------- | -------- |
| Object \| null | ArkTS object or null (if null is passed in).|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**
<!--code_no_check-->
```ts
// /entry/src/main/ets/pages/test.ts
export function reviverFunc(key, value) {
  if (key === "age") {
    return value + 1;
  }
  return value;
}
```

<!--code_no_check-->
```ts
import { JSON } from '@kit.ArkTS';
import { reviverFunc } from './test';

let jsonText = '{"name": "John", "age": 30, "city": "ChongQing"}';
let obj = JSON.parse(jsonText);
console.info((obj as object)?.["name"]);
// Output: John
const jsonTextStr = '{"name": "John", "age": 30}';
let objRst = JSON.parse(jsonTextStr, reviverFunc);
console.info((objRst as object)?.["age"]);
// Output: 31
let options: JSON.ParseOptions = {
  bigIntMode: JSON.BigIntMode.PARSE_AS_BIGINT,
}
let numberText = '{"largeNumber":112233445566778899}';
let numberObj = JSON.parse(numberText,(key: string, value: Object | undefined | null): Object | undefined | null => {
  if(key === "largeNumber") return value;
  return value;
},options) as Object;

console.info((numberObj as object)?.["largeNumber"]);
// Output: 112233445566778899
```

```ts
import { JSON } from '@kit.ArkTS';

/*
 * Deserialize JSON strings with nested quotation marks.
 * */

interface Info {
  name: string;
  age: number;
}

interface TestObj {
  info: Info;
}

interface TestStr {
  info: string;
}

// The JSON string contains nested quotation marks. This breaks the JSON structure, making it impossible to deserialize properly.
// let jsonStr = `{"info": "{"name": "zhangsan", "age": 18}"}`;

// The following provides two methods to solve this problem:
// Method 1: Avoid nested operations. Convert "{"name": "zhangsan", "age": 18}" in the original JSON string to {"name": "zhangsan", "age": 18}.
let jsonStr = `{"info": {"name": "zhangsan", "age": 18}}`;
let obj1  = JSON.parse(jsonStr) as TestObj;
console.info(JSON.stringify(obj1)); //{"info":{"name":"zhangsan","age":18}}
// Obtain the name property in the JSON string.
console.info(obj1.info.name); // zhangsan

// Method 2: Escape the nested quotation marks in the JSON string to restore the proper JSON structure.
jsonStr = `{"info": "{\\"name\\": \\"zhangsan\\", \\"age\\": 18}"}`;
let obj2 = JSON.parse(jsonStr) as TestStr;;
console.info(JSON.stringify(obj2)); // {"info":"{\"name\": \"zhangsan\", \"age\": 18}"}
// Obtain the name property in the JSON string.
let obj3 = JSON.parse(obj2.info) as Info;
console.info(obj3.name); // zhangsan
```

## JSON.stringify

stringify(value: Object, replacer?: (number | string)[] | null, space?: string | number): string

Converts an ArkTS object or array into a JSON string. In the case of a container, linear containers are supported, but non-linear containers are not.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | Object | Yes| ArkTS object or array. In the case of a container, linear containers are supported, but non-linear containers are not.|
| replacer | number[] \| string[] \| null | No| If an array is passed in, only the keys in the array are serialized to the final JSON string. If null is passed in, all keys of the object are serialized. The default value is undefined.|
| space | string \| number | No| White spaces or strings inserted into the output JSON string for readability purposes. If the parameter is a number, it represents the number of indentation spaces; if it is a string, it represents the indentation characters. If no parameter is provided, there will be no indentation. The default value is an empty string.|

**Returns**

| Type| Description|
| -------- | -------- |
| string | JSON string after conversion.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**
<!--code_no_check-->
```ts
// /entry/src/main/ets/pages/test.ts
export let exportObj = {1: "John", 2: 30, 3: "New York"};
```

<!--code_no_check-->
```ts
import { JSON } from '@kit.ArkTS';
import { exportObj } from './test';

let arr = [1, 2];
let rstArrStr = JSON.stringify(exportObj, arr);
console.info(rstArrStr);
// Output: "{"1":"John,""2":30}"
interface Person {
  name: string;
  age: number;
  city: string;
}
let inputObj = {"name": "John", "age": 30, "city": "ChongQing"} as Person;
let rstStr = JSON.stringify(inputObj, ["name"]);
console.info(rstStr);
// Output: "{"name":"John"}"
let rstStrSpace = JSON.stringify(inputObj, ["name"], '  ');
console.info(rstStrSpace);
// Output:
/*
"{
  "name": "John"
}"
*/
let rstStrStar = JSON.stringify(inputObj, ["name"], '&&');
console.info(rstStrStar);
// Output:
/*
"{
&&"name": "John"
}"
*/
```


## JSON.stringify

stringify(value: Object, replacer?: Transformer, space?: string | number): string

Converts an ArkTS object or array into a JSON string. In the case of a container, linear containers are supported, but non-linear containers are not.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | Object | Yes| ArkTS object or array. In the case of a container, linear containers are supported, but non-linear containers are not.|
| replacer | [Transformer](#transformer) | No| During serialization, each key of the serialized value is converted and processed by this function. The default value is undefined.|
| space | string \| number | No| Indentation, white space, or line break characters inserted into the output JSON string for readability purposes. If a number is passed in, it indicates the number of space characters to be used as indentation. If a string is passed in, the string is inserted before the output JSON string. If null is passed in, no white space is used. The default value is an empty string.|

**Returns**

| Type| Description|
| -------- | -------- |
| string | JSON string after conversion.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**
```ts
// /entry/src/main/ets/pages/test.ts
export function replacer(key: string, value: Object): Object {
  if (typeof value === "string") {
    return value.toUpperCase();
  }
  return value;
}
```

<!--code_no_check-->
```ts
import { JSON } from '@kit.ArkTS';
import { replacer } from './test';

interface Person {
  name: string;
  age: number;
  city: string;
}
let inputObj = {"name": "John", "age": 30, "city": "ChongQing"} as Person;
let rstStr= JSON.stringify(inputObj, replacer);
console.info(rstStr);
// Output: "{"name":"JOHN,""age":30,"city":"CHONGQING"}"
let rstStrSpace= JSON.stringify(inputObj, replacer, '  ');
console.info(rstStrSpace);
// Output:
/*
"{
  "name": "JOHN",
  "age": 30,
  "city": "CHONGQING"
}"
*/
let rstStrSymbol= JSON.stringify(inputObj, replacer, '@@@');
console.info(rstStrSymbol);
// Output:
/*
"{
@@@"name": "JOHN",
@@@"age": 30,
@@@"city": "CHONGQING"
}"
*/
```

```ts
import { JSON } from '@kit.ArkTS';

/*
 * Serialize BigInt objects.
 * */
let bigIntObject = BigInt(112233445566778899)

/*
 * Scenario 1: Serialize a BigInt object without a custom conversion function.
 * */
console.info(JSON.stringify(bigIntObject)); // 112233445566778896

/*
 * Scenario 2: Use a custom conversion function to serialize a BigInt object.
 * 2.1 Directly returning a BigInt object in the custom function will cause a JSCrash.
 * 2.2 Use a custom conversion function to preprocess the BigInt object as a string for serialization.
 * */

// 2.1 Incorrect serialization approach: Directly return a BigInt object in the custom function.
// JSON.stringify(bigIntObject, (key: string, value: Object): Object =>{ return value; });

// 2.2 Correct serialization approach: Preprocess the BigInt object as a string in the custom function.
let result: string = JSON.stringify(bigIntObject, (key: string, value: Object): Object => {
  if (typeof value === 'bigint') {
    return value.toString();
  }
  return value;
});
console.info("result:", result); // result: "112233445566778896"
```

```ts
import { JSON } from '@kit.ArkTS';

/*
 * Serialize floating-point numbers.
 * */
let floatNumber1 = 10.12345;
let floatNumber2 = 10.00;

// Serializing a floating-point number with a non-zero fractional part works as expected.
let result1 = JSON.stringify(floatNumber1);
console.info(result1); // 10.12345

// Serializing a floating-point number with a zero fractional part results in the loss of fractional precision for a more concise representation.
let result11 = JSON.stringify(floatNumber2);
console.info(result11); // 10

// The following is a method to prevent the loss of floating-point precision:
let result2 = JSON.stringify(floatNumber2, (key: string, value: Object): Object => {
  if (typeof value === 'number') {
    // Customize the fixed precision as needed for your specific use case.
    return value.toFixed(2);
  }
  return value;
});
console.info(result2); // "10.00"
```

## JSON.has

has(obj: object, property: string): boolean

Checks whether an ArkTS object contains a key. This API can be used for related operations after [JSON.parse](#jsonparse) is called to parse a JSON string. This API supports only valid JSON strings whose outermost layer is in dictionary format (in braces instead of square brackets).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| obj | object | Yes| ArkTS object.|
| property | string | Yes| Key to check.|

**Returns**

| Type| Description|
| -------- | -------- |
| boolean | Check result. The value **true** is returned if the ArkTS object contains the key; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
import { JSON } from '@kit.ArkTS';

const jsonText = '{"name": "John", "age": 30, "city": "ChongQing"}';
let inputObj = JSON.parse(jsonText);
let result = JSON.has(inputObj, "name");
console.info("result = " + result);
// Output: result = true
```


## JSON.remove

remove(obj: object, property: string): void

Removes a key from an ArkTS object. This API can be used for related operations after [JSON.parse](#jsonparse) is called to parse a JSON string. This API supports only valid JSON strings whose outermost layer is in dictionary format (in braces instead of square brackets).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| obj | object | Yes| ArkTS object.|
| property | string | Yes| Key to remove.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
import { JSON } from '@kit.ArkTS';

const jsonText = '{"name": "John", "age": 30, "city": "ChongQing"}';
let inputObj = JSON.parse(jsonText);
JSON.remove(inputObj, "name");
let result = JSON.has(inputObj, "name");
console.info("result = " + result);
// Output: result = false
```
