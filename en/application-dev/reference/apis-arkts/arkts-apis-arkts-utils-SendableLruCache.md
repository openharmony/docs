# SendableLruCache<K, V>
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @lijiamin2025-->
<!--Designer: @weng-changcheng-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->

Provides APIs to discard the least recently used data to make rooms for new elements when the cache is full. This class uses the Least Recently Used (LRU) algorithm, which believes that the recently used data may be accessed again in the near future and the least accessed data is the least valuable data and should be removed from the cache. **SendableLruCache** supports the Sendable feature, allowing it to store Sendable objects and ensuring safe cross-thread access.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The initial SendableLruCache APIs are supported since API version 18.
>
> This module can be imported only to ArkTS files (with the file name extension .ets).

## Modules to Import

```ts
import { ArkTSUtils } from '@kit.ArkTS'
```

## Properties

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

| Name  | Type  | Read-Only| Optional| Description                  |
| ------ | ------ | ---- | ---- | ---------------------- |
| length<sup>18+</sup> | number | Yes  | No  | Total number of values in this cache.|

**Example**

```ts
let pro = new ArkTSUtils.SendableLruCache<number, number>();
pro.put(2, 10);
pro.put(1, 8);
let result = pro.length;
console.info('result = ' + result);
// Expected output: result = 2
```

## constructor<sup>18+</sup>

constructor(capacity?: number)

A constructor used to create a **SendableLruCache** instance. The default capacity of the cache is 64.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type  | Mandatory| Description                        |
| -------- | ------ | ---- | ---------------------------- |
| capacity | number | No  | Capacity of the cache to create. The default value is **64**, and the maximum value is **2147483647**. If the value is less than or equal to 0, an exception is thrown.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                                   |
| -------- | ------------------------------------------|
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**Example**

```ts
let pro = new ArkTSUtils.SendableLruCache<number, number>();
```

## updateCapacity<sup>18+</sup>

updateCapacity(newCapacity: number): void

Changes the cache capacity. If the total number of values in the cache exceeds the specified capacity, the least recently used key-value pairs are removed.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name     | Type  | Mandatory| Description                        |
| ----------- | ------ | ---- | ---------------------------- |
| newCapacity | number | Yes  | New capacity of the cache. The maximum value is 2147483647. If the value is less than or equal to 0, an exception is thrown.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                                   |
| -------- | ------------------------------------------|
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**Example**

```ts
let pro = new ArkTSUtils.SendableLruCache<number, number>();
pro.updateCapacity(100);
```

## toString<sup>18+</sup>

toString(): string

Obtains the string representation of this cache.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type  | Description                      |
| ------ | -------------------------- |
| string | String representation of the cache, in the format of SendableLruCache[ maxSize = (maxSize), hits = (hitCount), misses = (missCount), hitRate = (hitRate) ], where **(maxSize)** indicates the maximum size of the cache, **(hitCount)** indicates the number of matched queries, **(missCount)** indicates the number of times that the number of mismatched queries, and **(hitRate)** indicates the matching rate.|

**Example**

```ts
let pro = new ArkTSUtils.SendableLruCache<number, number>();
pro.put(2, 10);
pro.get(2);
pro.get(3);
console.info(pro.toString());
// Expected output: SendableLruCache[ maxSize = 64, hits = 1, misses = 1, hitRate = 50% ]
// maxSize: maximum size of the cache. hits: number of matched queries. misses: number of mismatched queries. hitRate: matching rate.
```

## getCapacity<sup>18+</sup>

getCapacity(): number

Obtains the capacity of this cache.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type  | Description                  |
| ------ | ---------------------- |
| number | Capacity of the cache.|

**Example**

```ts
let pro = new ArkTSUtils.SendableLruCache<number, number>();
let result = pro.getCapacity();
console.info('result = ' + result);
// Expected output: result = 64
```

## clear<sup>18+</sup>

clear(): void

Clears all key-value pairs from this cache.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
let pro = new ArkTSUtils.SendableLruCache<number, number>();
pro.put(2, 10);
let result = pro.length;
pro.clear();
let res = pro.length;
console.info('result = ' + result);
console.info('res = ' + res);
// Expected output: result = 1
// Expected output: res = 0
```

## getCreateCount<sup>18+</sup>

getCreateCount(): number

Obtains the number of times that the default internal API is called to create objects.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type  | Description               |
| ------ | -------------------|
| number | Number of times that the default internal API is called.|

**Example**

```ts
@Sendable
class ChildLRUCache extends ArkTSUtils.SendableLruCache<number, number> {
  constructor() {
    super();
  }
  createDefault(key: number): number {
    return key;
  }
}

let lru = new ChildLRUCache();
lru.put(2, 10);
lru.get(3);
lru.get(5);
let res = lru.getCreateCount();
console.info('res = ' + res);
// Expected output: res = 2
// When the get operation is performed, if the key does not exist, call the createDefault API to check whether the return value is undefined.
// If the return value is not undefined, add the key and return value to the cache as a new entry and increase the creation count by one.
```

## getMissCount<sup>18+</sup>

getMissCount(): number

Obtains the number of times that the queried values are mismatched.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type  | Description                    |
| ------ | ------------------------ |
| number | Number of times that the queried values are mismatched.|

**Example**

```ts
let pro = new ArkTSUtils.SendableLruCache<number, number>();
pro.put(2, 10);
pro.get(2);
let result = pro.getMissCount();
console.info('result = ' + result);
// Expected output: result = 0
```

## getRemoveCount<sup>18+</sup>

getRemoveCount(): number

Obtains the number of times that key-value pairs in the cache are recycled. When the size of the cache exceeds the capacity limit, the least used key-value pairs will be recycled.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type  | Description                      |
| ------ | -------------------------- |
| number | Number of times that key-value pairs in the cache are recycled.|

**Example**

```ts
let pro = new ArkTSUtils.SendableLruCache<number, number>();
pro.put(2, 10);
pro.updateCapacity(2);
pro.put(50, 22);
let result = pro.getRemoveCount();
console.info('result = ' + result);
// Expected output: result = 0
```

## getMatchCount<sup>18+</sup>

getMatchCount(): number

Obtains the number of times that the queried values are matched.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type  | Description                      |
| ------ | -------------------------- |
| number | Number of times that the queried values are matched.|

**Example**

```ts
let pro = new ArkTSUtils.SendableLruCache<number, number>();
pro.put(2, 10);
pro.get(2);
let result = pro.getMatchCount();
console.info('result = ' + result);
// Expected output: result = 1
```

## getPutCount<sup>18+</sup>

getPutCount(): number

Obtains the number of additions to this cache.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type  | Description                        |
| ------ | ---------------------------- |
| number | Number of additions to the cache.|

**Example**

```ts
let pro = new ArkTSUtils.SendableLruCache<number, number>();
pro.put(2, 10);
let result = pro.getPutCount();
console.info('result = ' + result);
// Expected output: result = 1
```

## isEmpty<sup>18+</sup>

isEmpty(): boolean

Checks whether this cache is empty.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type   | Description                                    |
| ------- | ---------------------------------------- |
| boolean | Check result. The value **true** is returned if the cache is empty and does not contain any key-value pairs; otherwise, **false** is returned.|

**Example**

```ts
let pro = new ArkTSUtils.SendableLruCache<number, number>();
pro.put(2, 10);
let result = pro.isEmpty();
console.info('result = ' + result);
// Expected output: result = false
```

## get<sup>18+</sup>

get(key: K): V | undefined

Obtains the value of a key.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description        |
| ------ | ---- | ---- | ------------ |
| key    | K    | Yes  | Key based on which the value is queried.|

**Return value**

| Type                    | Description                                                        |
| ------------------------ | ------------------------------------------------------------ |
| V \| undefined | If the specified key exists in the cache, the return value is the value associated with that key. If not, the default internal API is called to generate an object with the same key and value and return the value. If the default internal API returns **undefined**, the return value is **undefined**; otherwise, the return value is whatever that API comes up with.|

**Example**

```ts
let pro = new ArkTSUtils.SendableLruCache<number, number>();
pro.put(2, 10);
let result  = pro.get(2);
console.info('result = ' + result);
// Expected output: result = 10
```

## put<sup>18+</sup>

put(key: K,value: V): V

Adds a key-value pair to this cache and returns the value associated with the key. If the total number of values in the cache is greater than the specified capacity, the deletion operation is performed.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description                      |
| ------ | ---- | ---- | -------------------------- |
| key    | K    | Yes  | Key of the key-value pair to add.            |
| value  | V    | Yes  | Value of the key-value pair to add.|

**Return value**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| V    | Value of the key-value pair added.|

**Example**

```ts
let pro = new ArkTSUtils.SendableLruCache<number, number>();
let result = pro.put(2, 10);
console.info('result = ' + result);
// Expected output: result = 10
```

## values<sup>18+</sup>

values(): V[]

Obtains all values in this cache, listed from the most to the least recently accessed, where the most recently accessed indicates the key-value pair with the latest operation.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type     | Description                                                        |
| --------- | ------------------------------------------------------------ |
| V&nbsp;[] | All values in the cache, listed from the most to the least recently used.|

**Example**

```ts
let pro = new ArkTSUtils.SendableLruCache<number|string,number|string>();
pro.put(2, 10);
pro.put(2, "anhu");
pro.put("afaf", "grfb");
let result = pro.values();
console.info('result = ' + result);
// Expected output: result = anhu,grfb
```

## keys<sup>18+</sup>

keys(): K[]

Obtains all keys in this cache, listed from the most to the least recently accessed.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type     | Description                                                        |
| --------- | ------------------------------------------------------------ |
| K&nbsp;[] | All keys in the cache, listed from the most to the least recently used.|

**Example**

```ts
let pro = new ArkTSUtils.SendableLruCache<number, number>();
pro.put(2, 10);
pro.put(3, 1);
let result = pro.keys();
console.info('result = ' + result);
// Expected output: result = 2,3
```

## remove<sup>18+</sup>

remove(key: K): V | undefined

Removes a key and its associated value from this cache and returns the value associated with the key. If the key does not exist, undefined is returned.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description          |
| ------ | ---- | ---- | -------------- |
| key    | K    | Yes  | Key to remove.|

**Return value**

| Type                    | Description                                                        |
| ------------------------ | ------------------------------------------------------------ |
| V&nbsp;\|&nbsp;undefined | Returns an **Optional** object containing the removed key-value pair if the key exists in the cache; returns undefined if the key does not exist; throws an error if **null** is passed in for **key**.|

**Example**

```ts
let pro = new ArkTSUtils.SendableLruCache<number, number>();
pro.put(2, 10);
let result = pro.remove(20);
console.info('result = ' + result);
// Expected output: result = undefined
```

## contains<sup>18+</sup>

contains(key: K): boolean

Checks whether the cache contains the specified key.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description            |
| ------ | ------ | ---- | ---------------- |
| key    | K      | Yes  | Key to check.|

**Return value**

| Type   | Description                                      |
| ------- | ------------------------------------------ |
| boolean | Check result. The value **true** is returned if the cache contains the specified key; otherwise, **false** is returned.|

**Example**

```ts
let pro = new ArkTSUtils.SendableLruCache<number, number>();
pro.put(2, 10);
let result = pro.contains(2);
console.info('result = ' + result);
// Expected output: result = true
```

## entries<sup>18+</sup>

entries(): IterableIterator&lt;[K,V]&gt;

Obtains a new iterator object that contains all key-value pairs in this object.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type       | Description                |
| ----------- | -------------------- |
| IterableIterator<[K,&nbsp;V]> | Iterable array.|

**Example**

```ts
let pro = new ArkTSUtils.SendableLruCache<number, number>();
pro.put(2, 10);
pro.put(3, 15);
let pair:Iterable<Object[]> = pro.entries();
let arrayValue = Array.from(pair);
for (let value of arrayValue) {
  console.info(value[0]+ ', '+ value[1]);
  // Expected output:
  // 2, 10
  // 3, 15
}
```
