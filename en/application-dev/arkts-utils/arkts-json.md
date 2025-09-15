# JSON Extension Library
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @yuanyao14-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->

## When to Use

The JSON extension library extends the native JSON functionality, providing additional error handling, circular reference detection, BigInt processing, and strict type checking for different input types. It relies on the native **JSON.parse** and **JSON.stringify** methods but adds custom logic and additional methods such as **has** and **remove**. For details, see [@arkts.json](../reference/apis-arkts/js-apis-json.md).

The JSON extension library mainly applies to the following scenarios:

- JSON parsing or serialization that involves BigInt handling.

- Situations requiring stricter parameter verification and error handling.

- Scenarios where circular references need to be detected when objects are serialized.

- Safe object operations (for example, **has** or **remove**).

This library is suitable for scenarios where enhanced JSON functionality is needed, especially when dealing with BigInt and strict parameter verification.

## JSON Extension Description

### parse

parse(text: string, reviver?: Transformer, options?: ParseOptions): Object | null

Parses a JSON string and supports BigInt mode.

**Differences from native**

| Feature| Native parse | Current parse|
| -------- | -------- | -------- |
| BigInt support| Not supported (throws **TypeError**)|Supported (via **parseBigInt** extension)|
| Parameter verification| Weak verification|Strong verification (throws **BusinessError**)|
| Error message| Native error (such as **SyntaxError**)|	Custom **BusinessError**|
| **reviver** parameter| Supported| Supported, with strict type checking|

### stringify

stringify(value: Object, replacer?: (number | string)[] | null, space?: string | number): string

Converts an object to a JSON string and supports BigInt mode.

**Differences from native**

| Feature| Native stringify| Current stringify|
| -------- | -------- | -------- |
| BigInt support| Not supported (throws **TypeError**)| Supported (via **stringifyBigInt** extension)|
| Circular reference detection| Throws **TypeError**| Detects and throws **BusinessError**|
| Parameter verification| Weak verification| Strong verification (**replacer** must be a function or an array)|
| Error message| Native error| Custom **BusinessError**|

### has

has(obj: object, property: string): boolean

Checks whether an object contains a specified property, ensuring the input is an object and the property key is a valid string.

**Differences from native**

| Feature| Native (obj.hasOwnProperty)| Current has|
| -------- | -------- | -------- |
| Parameter verification| No verification (potential misuse)| Enforces **obj** as a regular object and **property** as a non-empty string|
| Error handling| May fail silently| Throws **BusinessError**|

### remove

remove(obj: object, property: string): void

Removes a specified property from an object.

| Feature| Native (delete obj.key)| Current remove|
| -------- | -------- | -------- | 
| Parameter verification| No verification (potential accidental deletion)| Enforces **obj** as a regular object and **property** as a non-empty string|
| Error handling| May fail silently| Throws **BusinessError**|

### Summary

| Feature| Native JSON| This Library|
| ----- | ----- | -----| 
| Strict parameter verification| Not supported|	Supported|
| Circular reference detection| Not supported|	Supported|
| BigInt processing| Not supported|	Supported|
| Enhanced error handling (**BusinessError**)| Not supported| Supported|
| Additional methods (**has** or **remove**)| Not supported| Supported|

## Development Scenario

### Parsing JSON Strings Containing Nested Quotation Marks

Nested quotation marks in a JSON string break its structure, which will cause parsing failure.

```ts
// For example, the following JSON string is damaged due to nested quotation marks. If JSON.parse is executed, an exception will be thrown.
// let jsonStr = `{"info": "{"name": "zhangsan", "age": 18}"}`;
```

The following provides two methods to solve this problem:

Method 1: Avoid nested quotation marks.

```ts
import { JSON } from '@kit.ArkTS';

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

/*
 * Convert `{"info": "{"name": "zhangsan", "age": 18}"}` in the original JSON string
 * to `{"info": {"name": "zhangsan", "age": 18}}`.
 * */
let jsonStr = `{"info": {"name": "zhangsan", "age": 18}}`;
let obj1  = JSON.parse(jsonStr) as TestObj;
console.info(JSON.stringify(obj1));    //{"info":{"name":"zhangsan","age":18}}
// Obtain the name property in the JSON string.
console.info(obj1.info.name); // zhangsan
```

Method 2: Escape the nested quotation marks in the JSON string to restore the proper JSON structure.

```ts
import { JSON } from '@kit.ArkTS';

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

/*
 * Double-escape `{"info": "{"name": "zhangsan", "age": 18}"}` in the original JSON string
 * and convert it to `{"info": "{\\"name\\": \\"zhangsan\\", \\"age\\": 18}"}`.
 * */
let jsonStr = `{"info": "{\\"name\\": \\"zhangsan\\", \\"age\\": 18}"}`;
let obj2 = JSON.parse(jsonStr) as TestStr;
console.info(JSON.stringify(obj2));    // {"info":"{\"name\": \"zhangsan\", \"age\": 18}"}
// Obtain the name property in the JSON string.
let obj3 = JSON.parse(obj2.info) as Info;
console.info(obj3.name); // zhangsan
```

### Parsing JSON Strings Containing BigInts

If the JSON string contains an integer less than -(2^53-1) or greater than (2^53-1), the data precision is lost or incorrect after parsing. In this scenario, **BigIntMode** must be specified to parse big integers as BigInt.

```ts
import { JSON } from '@kit.ArkTS';

let numberText = '{"number": 10, "largeNumber": 112233445566778899}';

let numberObj1 = JSON.parse(numberText) as Object;
console.info((numberObj1 as object)?.["largeNumber"]);    // 112233445566778900

// Use the BigInt mode of PARSE_AS_BIGINT for parsing to avoid parsing errors.
let options: JSON.ParseOptions = {
  bigIntMode: JSON.BigIntMode.PARSE_AS_BIGINT,
}

let numberObj2 = JSON.parse(numberText, null, options) as Object;

console.info(typeof (numberObj2 as object)?.["number"]);   // number
console.info((numberObj2 as object)?.["number"]);    // 10

console.info(typeof (numberObj2 as object)?.["largeNumber"]);    // bigint
console.info((numberObj2 as object)?.["largeNumber"]);    // 112233445566778899
```

### Serializing BigInt Objects

To address the issue that native JSON cannot serialize BigInt objects, this library provides the following two JSON serialization methods:

Method 1: Serialize a BigInt object without a custom conversion function.

```ts
import { JSON } from '@kit.ArkTS';

let bigIntObject = BigInt(112233445566778899n)

console.info(JSON.stringify(bigIntObject)); // 112233445566778899
```

Method 2: Use a custom conversion function to serialize a BigInt object.

```ts
import { JSON } from '@kit.ArkTS';

let bigIntObject = BigInt(112233445566778899n)

// Incorrect serialization approach: Directly return a BigInt object in the custom function.
// JSON.stringify(bigIntObject, (key: string, value: Object): Object =>{ return value; });

// Correct serialization approach: Preprocess the BigInt object as a string in the custom function.
let result: string = JSON.stringify(bigIntObject, (key: string, value: Object): Object => {
  if (typeof value === 'bigint') {
    return value.toString();
  }
  return value;
});
console.info("result:", result); // result: "112233445566778899"
```

### Serializing Floating-Point Numbers

In JSON serialization, floating-point numbers undergo special handling: When the fractional part is 0, it will be automatically omitted for concision. This may result in loss of precision information and affect scenarios where accurate representation of floating-point numbers is required (such as financial calculation and scientific measurement). The following example provides a solution to this scenario:

```ts
import { JSON } from '@kit.ArkTS';

// Serializing a floating-point number with a non-zero fractional part works as expected.
let floatNumber1 = 10.12345;
console.info(JSON.stringify(floatNumber1)); // 10.12345

// Serializing a floating-point number with a zero fractional part results in the loss of fractional precision for a more concise representation.
let floatNumber2 = 10.00;
console.info(JSON.stringify(floatNumber2)); // 10

// The following is a method to prevent the loss of floating-point precision:
let result = JSON.stringify(floatNumber2, (key: string, value: Object): Object => {
  if (typeof value === 'number') {
    // Customize the fixed precision as needed for your specific use case.
    return value.toFixed(2);
  }
  return value;
});
console.info(result); // "10.00"
```
