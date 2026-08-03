# Class (SendableLruCache)
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @wang_zhaoyong-->
<!--Designer: @weng-changcheng-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

SendableLruCache在缓存空间不足时，会用新数据替换近期最少使用的数据。此设计基于资源访问的考虑：近期访问的数据可能在不久的将来再次访问，因此最少访问的数据价值最小，应优先移出缓存。SendableLruCache支持Sendable（可跨线程安全共享的）特性，可保存Sendable对象，确保跨线程安全访问。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> SendableLruCache首批接口从API version 18开始支持。
>
> 此模块仅支持在ArkTS文件（文件后缀为.ets）中导入使用。
> 

**装饰器类型：**\@Sendable

## 导入模块

```ts
import { ArkTSUtils } from '@kit.ArkTS';
```

## 属性

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

| 名称   | 类型   | 只读 | 可选 | 说明                   |
| ------ | ------ | ---- | ---- | ---------------------- |
| length<sup>18+</sup> | number | 是   | 否   | 当前缓存中值的总数。 |

**示例：**

```ts
let lruCache = new ArkTSUtils.SendableLruCache<number, number>();
lruCache.put(2, 10);
lruCache.put(1, 8);
let result = lruCache.length;
console.info('result = ' + result);
// 预期输出：result = 2
```

## constructor<sup>18+</sup>

constructor(capacity?: number)

默认构造函数用于创建一个新的SendableLruCache实例，默认容量为64。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名   | 类型   | 必填 | 说明                         |
| -------- | ------ | ---- | ---------------------------- |
| capacity | number | 否   | 指示缓存的自定义容量。不传时，默认值为64，最大值不能超过2^31-1；小于等于0时会抛出异常。建议根据实际业务数据量设置合适的容量值，以平衡缓存命中率与内存占用。 |

**示例：**

```ts
let lruCache = new ArkTSUtils.SendableLruCache<number, number>();
```

## updateCapacity<sup>18+</sup>

updateCapacity(newCapacity: number): void

将缓存容量设置为指定值。如果缓存中值的总数超过指定容量，将淘汰最少使用的键值对。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名      | 类型   | 必填 | 说明                         |
| ----------- | ------ | ---- | ---------------------------- |
| newCapacity | number | 是   | 指示要为缓存自定义的容量，最大值不能超过2^31-1；小于等于0时会抛出异常。建议根据实际业务数据量设置合适的容量值，以平衡缓存命中率与内存占用。|

**示例：**

```ts
let lruCache = new ArkTSUtils.SendableLruCache<number, number>();
lruCache.updateCapacity(100);
```

## toString<sup>18+</sup>

toString(): string

返回对象的字符串表示形式，包含缓存最大容量、查询匹配成功次数、查询匹配失败次数及匹配率等信息。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明                       |
| ------ | -------------------------- |
| string | 返回对象的字符串表示形式。 返回字符串格式是：SendableLruCache[ maxSize = (maxSize), hits = (hitCount), misses = (missCount), hitRate = (hitRate) ]。 (maxSize)表示缓存最大值，(hitCount)表示查询值匹配成功的次数，(missCount)表示查询值匹配失败的次数，(hitRate)表示查询值匹配率。|

**示例：**

```ts
let lruCache = new ArkTSUtils.SendableLruCache<number, number>();
lruCache.put(2, 10);
lruCache.get(2);
lruCache.get(3);
console.info(lruCache.toString());
// 预期输出：SendableLruCache[ maxSize = 64, hits = 1, misses = 1, hitRate = 50% ]
// maxSize: 缓存最大值 hits: 查询值匹配成功的次数 misses: 查询值匹配失败的次数 hitRate: 查询值匹配率
```

## getCapacity<sup>18+</sup>

getCapacity(): number

获取当前缓存的容量。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明                   |
| ------ | ---------------------- |
| number | 返回当前缓存的容量。 |

**示例：**

```ts
let lruCache = new ArkTSUtils.SendableLruCache<number, number>();
let result = lruCache.getCapacity();
console.info('result = ' + result);
// 预期输出：result = 64
```

## clear<sup>18+</sup>

clear(): void

从当前缓存清除所有键值对。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

```ts
let lruCache = new ArkTSUtils.SendableLruCache<number, number>();
lruCache.put(2, 10);
let result = lruCache.length;
lruCache.clear();
let res = lruCache.length;
console.info('result = ' + result);
console.info('res = ' + res);
// 预期输出：result = 1
// 预期输出：res = 0
```

## getCreateCount<sup>18+</sup>

getCreateCount(): number

获取调用createDefault方法创建对象的次数。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明                |
| ------ | -------------------|
| number | 返回使用createDefault方法创建对象的次数。 |

**示例：**

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
// 预期输出：res = 2
// 执行get操作时，如果键值不存在，调用createDefault接口判断返回值是否等于undefined
// 如果不等于，则需要把key和返回值作为键值对添加到cache中，并且创建次数加1
```

## getMissCount<sup>18+</sup>

getMissCount(): number

获取查询值不匹配的次数。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| number | 返回查询值不匹配的次数。 |

**示例：**

```ts
let lruCache = new ArkTSUtils.SendableLruCache<number, number>();
lruCache.put(2, 10);
lruCache.get(2);
let result = lruCache.getMissCount();
console.info('result = ' + result);
// 预期输出：result = 0
```

## getRemoveCount<sup>18+</sup>

getRemoveCount(): number

获取缓存键值对的淘汰次数。当缓存数量超过容量限制时，最少使用的键值对将被淘汰。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明                       |
| ------ | -------------------------- |
| number | 返回缓存键值对淘汰的次数。 |

**示例：**

```ts
let lruCache = new ArkTSUtils.SendableLruCache<number, number>();
lruCache.put(2, 10);
lruCache.updateCapacity(2);
lruCache.put(50, 22);
let result = lruCache.getRemoveCount();
console.info('result = ' + result);
// 预期输出：result = 0
```

## getMatchCount<sup>18+</sup>

getMatchCount(): number

获取查询值匹配成功的次数。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明                       |
| ------ | -------------------------- |
| number | 返回查询值匹配成功的次数。 |

**示例：**

```ts
let lruCache = new ArkTSUtils.SendableLruCache<number, number>();
lruCache.put(2, 10);
lruCache.get(2);
let result = lruCache.getMatchCount();
console.info('result = ' + result);
// 预期输出：result = 1
```

## getPutCount<sup>18+</sup>

getPutCount(): number

获取将值添加到缓存的次数。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明                         |
| ------ | ---------------------------- |
| number | 返回向缓存中添加值的次数。 |

**示例：**

```ts
let lruCache = new ArkTSUtils.SendableLruCache<number, number>();
lruCache.put(2, 10);
let result = lruCache.getPutCount();
console.info('result = ' + result);
// 预期输出：result = 1
```

## isEmpty<sup>18+</sup>

isEmpty(): boolean

检查当前缓存是否为空。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型    | 说明                                     |
| ------- | ---------------------------------------- |
| boolean | 返回true表示当前缓存为空，不包含任何键值对；返回false表示当前缓存不为空。 |

**示例：**

```ts
let lruCache = new ArkTSUtils.SendableLruCache<number, number>();
lruCache.put(2, 10);
let result = lruCache.isEmpty();
console.info('result = ' + result);
// 预期输出：result = false
```

## get<sup>18+</sup>

get(key: K): V | undefined

返回键对应的值。如果指定的键不存在于缓存中，将调用createDefault方法；若createDefault返回非undefined值，则将该键值对添加到缓存并返回该值；若createDefault返回undefined，则返回undefined。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明         |
| ------ | ---- | ---- | ------------ |
| key    | K    | 是   | 要查询的键。 |

**返回值：**

| 类型                     | 说明                                                         |
| ------------------------ | ------------------------------------------------------------ |
| V \| undefined | 如果指定的键存在于缓存中，则返回与键关联的值；否则调用createDefault方法创建值。若createDefault返回非undefined值，则将该键值对添加到缓存中，并返回该值；若createDefault返回undefined，则最终返回undefined。当因添加新条目导致缓存中值的数量超过容量时，将淘汰最少使用的键值对。 |

**示例：**

```ts
let lruCache = new ArkTSUtils.SendableLruCache<number, number>();
lruCache.put(2, 10);
let result  = lruCache.get(2);
console.info('result = ' + result);
// 预期输出：result = 10
```

## put<sup>18+</sup>

put(key: K, value: V): V

将键值对添加到缓存中，并返回与添加的键关联的值。当缓存中值的数量超过容量时，将淘汰最少使用的键值对。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明                       |
| ------ | ---- | ---- | -------------------------- |
| key    | K    | 是   | 要添加的键。             |
| value  | V    | 是   | 与要添加的键关联的值。 |

**返回值：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| V    | 返回与添加的键关联的值。|

**示例：**

```ts
let lruCache = new ArkTSUtils.SendableLruCache<number, number>();
let result = lruCache.put(2, 10);
console.info('result = ' + result);
// 预期输出：result = 10
```

## values<sup>18+</sup>

values(): V[]

获取当前缓存中所有值的列表，按从最近访问到最少访问的顺序排列。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型      | 说明                                                         |
| --------- | ------------------------------------------------------------ |
| V&nbsp;[] | 返回当前缓存中所有值的列表，按从最近访问到最少访问的顺序排列。 |

**示例：**

```ts
let lruCache = new ArkTSUtils.SendableLruCache<number|string,number|string>();
lruCache.put(2, 10);
lruCache.put(2, "anhu");
lruCache.put("afaf", "grfb");
let result = lruCache.values();
console.info('result = ' + result);
// 预期输出：result = anhu,grfb
```

## keys<sup>18+</sup>

keys(): K[]

获取当前缓存中所有键，按从最近访问到最少访问的顺序排列。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型      | 说明                                                         |
| --------- | ------------------------------------------------------------ |
| K&nbsp;[] | 返回当前缓存中所有键的列表，按从最近访问到最少访问的顺序排列。 |

**示例：**

```ts
let lruCache = new ArkTSUtils.SendableLruCache<number, number>();
lruCache.put(2, 10);
lruCache.put(3, 1);
let result = lruCache.keys();
console.info('result = ' + result);
// 预期输出：result = 2,3
```

## remove<sup>18+</sup>

remove(key: K): V | undefined

从当前缓存中删除指定键及其关联值，返回该键关联的值。若键不存在，则返回undefined。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明           |
| ------ | ---- | ---- | -------------- |
| key    | K    | 是   | 要删除的键。 |

**返回值：**

| 类型                     | 说明                                                         |
| ------------------------ | ------------------------------------------------------------ |
| V&nbsp;\|&nbsp;undefined | 返回与key关联的值；若key不存在，则返回undefined。 |

**示例：**

```ts
let lruCache = new ArkTSUtils.SendableLruCache<number, number>();
lruCache.put(2, 10);
let result = lruCache.remove(20);
console.info('result = ' + result);
// 预期输出：result = undefined
```

## contains<sup>18+</sup>

contains(key: K): boolean

检查当前缓存是否包含指定的键，如果存在，返回true；否则，返回false。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明             |
| ------ | ------ | ---- | ---------------- |
| key    | K      | 是   | 表示要检查的键。 |

**返回值：**

| 类型    | 说明                                       |
| ------- | ------------------------------------------ |
| boolean | true：缓存包含指定的键；false：缓存不包含指定的键。 |

**示例：**

```ts
let lruCache = new ArkTSUtils.SendableLruCache<number, number>();
lruCache.put(2, 10);
let result = lruCache.contains(2);
console.info('result = ' + result);
// 预期输出：result = true
```

## entries<sup>18+</sup>

entries(): IterableIterator&lt;[K,V]&gt;

允许迭代包含在这个对象中的所有键值对，按从最近访问到最少访问的顺序排列。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型        | 说明                 |
| ----------- | -------------------- |
| IterableIterator<[K,&nbsp;V]> | 返回键值对的迭代器。 |

**示例：**

```ts
let lruCache = new ArkTSUtils.SendableLruCache<number, number>();
lruCache.put(2, 10);
lruCache.put(3, 15);
let pair:Iterable<Object[]> = lruCache.entries();
let arrayValue = Array.from(pair);
for (let value of arrayValue) {
  console.info(value[0] + ', ' + value[1]);
  // 预期输出：
  // 2, 10
  // 3, 15
}
```