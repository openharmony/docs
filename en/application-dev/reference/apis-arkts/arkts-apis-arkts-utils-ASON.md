# ArkTSUtils.ASON
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @lijiamin2025-->
<!--Designer: @weng-changcheng-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->

A utility class used to parse JSON strings into [sendable data](../../arkts-utils/arkts-sendable.md#sendable-data-types). ASON allows you to parse JSON strings and generate Sendable data for pass-by-reference across concurrent instances. It also supports conversion from Sendable data into JSON strings.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This module can be imported only to ArkTS files (with the file name extension .ets).

## Modules to Import

```ts
import { ArkTSUtils } from '@kit.ArkTS'
```

## ISendable

type ISendable = lang.ISendable

**ISendable** is the parent type of all sendable types except `null` and `undefined`. It does not have any necessary methods or properties.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Type| Description  |
| ------ | ------ |
| [lang.ISendable](js-apis-arkts-lang.md#langisendable)   | Parent type of all sendable types.|

## Transformer

type Transformer = (this: ISendable, key: string, value: ISendable | undefined | null) => ISendable | undefined | null

Defines the type of the conversion result function.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description           |
| ------ | ------ | ---- | --------------- |
| this   | [ISendable](#isendable) | Yes| Object to which the key-value pair to parse belongs.|
| key  | string | Yes| Key to parse.|
| value  | [ISendable](#isendable) \| undefined \| null| Yes| Value of the key.|

**Return value**

| Type| Description|
| -------- | -------- |
| [ISendable](#isendable) \| undefined \| null | **ISendable** object, undefined, or null.|

## BigIntMode

Enumerates the modes for processing BigInt.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Name| Value| Description           |
| ------ | ------ | --------------- |
| DEFAULT   | 0 |BigInt is not supported.|
| PARSE_AS_BIGINT   | 1 |Parses an integer that is less than -(2^53-1) or greater than (2^53-1) as BigInt.|
| ALWAYS_PARSE_AS_BIGINT   | 2 |Parses all integers as BigInt.|

## ParseReturnType

Enumerates the return types of the parsing result.

**System capability**: SystemCapability.Utils.Lang

| Name| Value| Description           |
| ------ | ------ | --------------- |
| OBJECT   | 0 |Returns a **SendableObject** object.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| MAP<sup>13+</sup>   | 1 |Returns a **SendableMap** object.<br>**Atomic service API**: This API can be used in atomic services since API version 13.|

## ParseOptions

Describes the parsing options, which define the BigInt processing mode and the return type of the parsing result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Name| Type| Mandatory| Description           |
| ------ | ------ | ---- | --------------- |
| bigIntMode   | [BigIntMode](#bigintmode) | Yes|Mode for processing BigInt.|
| parseReturnType   | [ParseReturnType](#parsereturntype) | Yes|Return type of the parsing result.|

## parse

parse(text: string, reviver?: Transformer, options?: ParseOptions): ISendable | null

Parses a JSON string to generate ISendable data or null.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description           |
| ------ | ------ | ---- | --------------- |
| text   | string | Yes| Valid JSON string.|
| reviver   | [Transformer](#transformer) | No| Conversion function. This parameter can be used to modify the value generated after parsing. The default value is undefined. Currently, only undefined can be passed in.|
| options   | [ParseOptions](#parseoptions) | No| Parsing options. This parameter is used to control the type of the parsing result. The default value is undefined.|

**Return value**

| Type| Description|
| -------- | -------- |
| [ISendable](#isendable) \| null | ISendable data or **null** (if **null** is passed in).|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message     |
| -------- | ------------- |
| 401      | Parameter error. Invalid JSON string. |

**Example**

```ts
import { lang } from '@kit.ArkTS';
import { collections } from '@kit.ArkTS';

type ISendable = lang.ISendable;
let jsonText = '{"name": "John", "age": 30, "city": "ChongQing"}';
let obj = ArkTSUtils.ASON.parse(jsonText) as ISendable;
console.info((obj as object)?.["name"]);
// Expected output: 'John'
console.info((obj as object)?.["age"]);
// Expected output: 30
console.info((obj as object)?.["city"]);
// Expected output: 'ChongQing'

let options: ArkTSUtils.ASON.ParseOptions = {
  bigIntMode: ArkTSUtils.ASON.BigIntMode.PARSE_AS_BIGINT,
  parseReturnType: ArkTSUtils.ASON.ParseReturnType.OBJECT,
}
let numberText = '{"largeNumber":112233445566778899}';
let numberObj = ArkTSUtils.ASON.parse(numberText,undefined,options) as ISendable;

console.info((numberObj as object)?.["largeNumber"]);
// Expected output: 112233445566778899

let options2: ArkTSUtils.ASON.ParseOptions = {
    bigIntMode: ArkTSUtils.ASON.BigIntMode.PARSE_AS_BIGINT,
    parseReturnType: ArkTSUtils.ASON.ParseReturnType.MAP,
  }
let mapText = '{"largeNumber":112233445566778899}';
let map  = ArkTSUtils.ASON.parse(mapText,undefined,options2);
console.info("map is " + map);
// Expected output: map is [object SendableMap]
console.info("largeNumber is " + (map as collections.Map<string,bigint>).get("largeNumber"));
// Expected output: largeNumber is 112233445566778899
```

## stringify

stringify(value: Object | null | undefined): string

Converts ArkTS object data into a JSON string, with additional support for Map and Set types.

> **NOTE**
>
> Since API 18, the parameter type is changed to Object. In versions earlier than API 18, only the ISendable type is supported (except [Int8Array](arkts-apis-arkts-collections-Int8Array.md), [Uint8Array](arkts-apis-arkts-collections-Uint8Array.md), [Int16Array](arkts-apis-arkts-collections-Int16Array.md), [Uint16Array](arkts-apis-arkts-collections-Uint16Array.md), [Int32Array](arkts-apis-arkts-collections-Int32Array.md), [Uint32Array](arkts-apis-arkts-collections-Uint32Array.md), [Uint8ClampedArray](arkts-apis-arkts-collections-Uint8ClampedArray.md) and [Float32Array](arkts-apis-arkts-collections-Float32Array.md)).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | Object \| null \| undefined  | Yes| ArkTS object data.|

**Return value**

| Type| Description|
| -------- | -------- |
| string | JSON string.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message     |
| -------- | ------------- |
| 401      | Parameter error. Invalid ArkTS value. |

**Example**

```ts
import { ArkTSUtils, collections, HashMap, HashSet } from '@kit.ArkTS';

let hashMap = new HashMap<string,string>();
hashMap.set("ha","a");
hashMap.set("sh","b");
hashMap.set("map","c");
let str1 = ArkTSUtils.ASON.stringify(hashMap);
console.info(str1);
// Expected output: '{"sh":"b","ha":"a","map":"c"}'
let hashSet = new HashSet<string>();
hashSet.add("ha");
hashSet.add("sh");
hashSet.add("set");
let str2 = ArkTSUtils.ASON.stringify(hashSet);
console.info(str2);
// Expected output: '["set","sh","ha"]'
let map = new Map<string,string>();
map.set("m","a");
map.set("a","b");
map.set("p","c");
let str3 = ArkTSUtils.ASON.stringify(map);
console.info(str3);
// Expected output: '{"m":"a","a":"b","p":"c"}'
let set = new Set<string>();
set.add("s");
set.add("e");
set.add("t");
let str4 = ArkTSUtils.ASON.stringify(set);
console.info(str4);
// Expected output: '["s","e","t"]'
let sendableMap = new collections.Map<string,string>();
sendableMap.set("send","a");
sendableMap.set("able","b");
sendableMap.set("map","c");
let str5 = ArkTSUtils.ASON.stringify(sendableMap);
console.info(str5);
// Expected output: '{"send":"a","able":"b","map":"c"}'
let sendableSet = new collections.Set<string>();
sendableSet.add("send");
sendableSet.add("able");
sendableSet.add("set");
let str6 = ArkTSUtils.ASON.stringify(sendableSet);
console.info(str6);
// Expected output: '["send","able","set"]'
```
