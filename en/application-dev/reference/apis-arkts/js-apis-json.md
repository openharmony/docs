# @ohos.util.json (JSON Parsing and Generation)

The JSON module provides a series of APIs for converting JSON text into JSON objects or values and converting objects into JSON strings.

>**NOTE**
>
>The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import JSON from '@ohos.util.json';
```

## Transformer

type Transformer = (this: Object, key: string, value: Object) => Object | undefined | null

Defines the type of the conversion result function.

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

## JSON.parse

parse(text: string, reviver?: Transformer): Object | null

Parses a JSON string into an ArkTS object or null.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description           |
| ------ | ------ | ---- | --------------- |
| text   | string | Yes| Valid JSON string.|
| reviver  | [Transformer](#transformer) | No| Conversion function. This parameter can be used to modify the value generated after parsing. The default value is undefined.|

**Returns**

| Type| Description|
| -------- | -------- |
| Object \| null | ArkTS object or null (if null is passed in).|

**Example**

```ts
import JSON from '@ohos.util.json';

let jsonText = '{"name": "John", "age": 30, "city": "ChongQing"}';
let obj = JSON.parse(jsonText);
```


## JSON.stringify

stringify(value: Object, replacer?: (number | string)[] | null, space?: string | number): string

Converts an ArkTS object or array into a JSON string.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | Object | Yes| ArkTS object or array.|
| replacer | number[] \| string[] \| null | No| If an array is passed in, only the keys in the array are serialized to the final JSON string. If null is passed in, all keys of the object are serialized. The default value is undefined.|
| space | string \| number | No| Indentation, white space, or line break characters inserted into the output JSON string for readability purposes. If a number is passed in, it indicates the number of space characters to be used as indentation. If a string is passed in, the string is inserted before the output JSON string. If null is passed in, no white space is used. The default value is an empty string.|

**Returns**

| Type| Description|
| -------- | -------- |
| string | JSON string after conversion.|

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

Converts an ArkTS object or array into a JSON string.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | Object | Yes| ArkTS object or array.|
| replacer | [Transformer](#transformer) | No| During serialization, each key of the serialized value is converted and processed by this function. The default value is undefined.|
| space | string \| number | No| Indentation, white space, or line break characters inserted into the output JSON string for readability purposes. If a number is passed in, it indicates the number of space characters to be used as indentation. If a string is passed in, the string is inserted before the output JSON string. If null is passed in, no white space is used. The default value is an empty string.|

**Returns**

| Type| Description|
| -------- | -------- |
| string | JSON string after conversion.|

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

Checks whether an ArkTS object contains a key. This API can be used for related operations after [JSON.parse](#jsonparse) is called to parse a JSON string.

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

**Example**

```ts

const jsonText = '{"name": "John", "age": 30, "city": "ChongQing"}';
let obj = JSON.parse(jsonText);
let rst = JSON.has(obj, "name");
```


## JSON.remove

remove(obj: object, property: string): void

Removes a key from an ArkTS object. This API can be used for related operations after [JSON.parse](#jsonparse) is called to parse a JSON string.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| obj | object | Yes| ArkTS object.|
| property | string | Yes| Key to remove.|

**Example**

```ts

const jsonText = '{"name": "John", "age": 30, "city": "ChongQing"}';
let obj = JSON.parse(jsonText);
let rst = JSON.remove(obj, "name");
```
