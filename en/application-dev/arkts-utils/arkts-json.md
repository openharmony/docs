# JSON Extension Library

The JSON extension library extends the native JSON functionality, providing additional error handling, circular reference detection, BigInt processing, and strict type checking for different input types. It relies on the native **JSON.parse** and **JSON.stringify** methods but adds custom logic and additional methods such as **has** and **remove**. For details, see [@arkts.json](../reference/apis-arkts/js-apis-json.md).

## parse

parse(text: string, reviver?: Transformer, options?: ParseOptions): Object | null

Parses a JSON string and supports BigInt mode.

**Differences from native**

| Feature| Native parse | Current parse|
| -------- | -------- | -------- |
| BigInt support| Not supported (throws **TypeError**)|Supported (via **parseBigInt** extension)|
| Parameter verification| Weak verification|Strong verification (throws **BusinessError**)|
| Error message| Native error (such as **SyntaxError**)|	Custom **BusinessError**|
| **reviver** parameter| Supported| Supported, with strict type checking|

## stringify

stringify(value: Object, replacer?: (number | string)[] | null, space?: string | number): string

Converts an object to a JSON string and supports BigInt mode.

**Differences from native**

| Feature| Native stringify| Current stringify|
| -------- | -------- | -------- |
| BigInt support| Not supported (throws **TypeError**)| Supported (via **stringifyBigInt** extension)|
| Circular reference detection| Throws **TypeError**| Detects and throws **BusinessError**|
| Parameter verification| Weak verification| Strong verification (**replacer** must be a function or an array)|
| Error message| Native error| Custom **BusinessError**|

## has

has(obj: object, property: string): boolean

Checks whether an object contains a specified property, ensuring the input is an object and the property key is a valid string.

**Differences from native**

| Feature| Native (obj.hasOwnProperty)| Current has|
| -------- | -------- | -------- |
| Parameter verification| No verification (potential misuse)| Enforces **obj** as a regular object and **property** as a non-empty string|
| Error handling| May fail silently| Throws **BusinessError**|

## remove

remove(obj: object, property: string): void

Removes a specified property from an object.

| Feature| Native (delete obj.key)| Current remove|
| -------- | -------- | -------- | 
| Parameter verification| No verification (potential accidental deletion)| Enforces **obj** as a regular object and **property** as a non-empty string|
| Error handling| May fail silently| Throws **BusinessError**|

**Summary**

| Feature| Native JSON| This Library|
| ----- | ----- | -----| 
| Strict parameter verification| Not supported|	Supported|
| Circular reference detection| Not supported|	Supported|
| BigInt processing| Not supported|	Supported|
| Enhanced error handling (**BusinessError**)| Not supported| Supported|
| Additional methods (**has** or **remove**)| Not supported| Supported|

**Use Cases**

- JSON parsing or serialization that involves BigInt handling.

- Situations requiring stricter parameter verification and error handling.

- Scenarios where circular references need to be detected.

- Safe object operations (for example, **has** or **remove**).

This library is suitable for scenarios where enhanced JSON functionality is needed, especially when dealing with BigInt and strict parameter verification.
