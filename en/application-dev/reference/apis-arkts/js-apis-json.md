# @ohos.util.json (JSON Parsing and Generation)

The JSON module provides a series of APIs for converting JSON text into JSON objects or values and converting objects into JSON strings.

>**NOTE**
>
>The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import { JSON } from '@kit.ArkTS';
```

## Transformer

type Transformer = (this: Object, key: string, value: Object) => Object | undefined | null

Defines the type of the conversion result function.

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

```ts
let jsonText = '{"name": "John", "age": 30, "city": "ChongQing"}';
let obj = JSON.parse(jsonText);

let options: JSON.ParseOptions = {
  bigIntMode: JSON.BigIntMode.PARSE_AS_BIGINT,
}
let numberText = '{"largeNumber":112233445566778899}';
let numberObj = JSON.parse(numberText,(key: string, value: Object | undefined | null): Object | undefined | null => {
  if(key === "largeNumber") return value;
  return value;
},options) as Object;

console.info((numberObj as object)?.["largeNumber"]);
// Expected output: 112233445566778899
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
interface Person {
  name: string;
  age: number;
  city: string;
}
let obj = {"name": "John", "age": 30, "city": "ChongQing"} as Person;
let str1 = JSON.stringify(obj, ["name"]);
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
function replacer(key: string, value: Object): Object {
  if (typeof value === "string") {
    return value.toUpperCase();
  }
  return value;
}
interface Person {
  name: string;
  age: number;
  city: string;
}

let obj = {"name": "John", "age": 30, "city": "ChongQing"} as Person;
let str2 = JSON.stringify(obj, replacer);
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
| boolean | **true**: The ArkTS object contains the key.<br>**false**: The ArkTS object does not contain the key.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
const jsonText = '{"name": "John", "age": 30, "city": "ChongQing"}';
let obj = JSON.parse(jsonText);
let rst = JSON.has(obj, "name");
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
const jsonText = '{"name": "John", "age": 30, "city": "ChongQing"}';
let obj = JSON.parse(jsonText);
let rst = JSON.remove(obj, "name");
```
