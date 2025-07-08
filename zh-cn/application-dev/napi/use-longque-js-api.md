# 接口介绍
Longque JS API 由 Longque JS Engine 提供，适用于在 OpenHarmony 平台构建稳定、高性能的应用。所有 API 均位于 `__Longque__` 对象下。接口的版本可通过 `__Longque__.version` 获得，开发者可使用该版本进行特性判断。

**【注意】：Longque JS API处于实验阶段，使用前请阅读文档，评估其稳定性和兼容性。**

## createDelegate接口
> 接口引入版本 : 1

### 接口描述
| 接口                      | 名称         | 说明                                                                                                                                                     |
| ------------------------- | ------------ | -------------------------------------------------------------------------------------------------------------------------------------------------------- |
| createDelegate             | 创建委托       | 创建 `underlyingObject` 的委托对象，对委托对象的属性读写操作将映射至 `underlyingObject`。通过 `initObject` 指定初始委托对象，通过 `propertyFilterFlags` 指定属性过滤器。默认情况下，将映射 `underlyingObject` 及其原型链上所有可枚举的字符串键属性。

### 参数
(1) `underlyingObject`： 必选参数。表示被委托的底层对象。参数要求：
- `underlyingObject` 必须是对象，否则会抛出 `TypeError` 异常。
- 若 `underlyingObject` 是代理对象，将抛出 `TypeError` 异常。
- 若未指定 `SKIP_PROTOTYPE_CHAIN` 过滤器，且 `underlyingObject` 原型链上存在代理对象，则抛出 `TypeError` 异常。

(2) `initObject`：可选参数。表示初始委托对象。若传入 undefined，表示不指定初始对象，将由接口自动创建。参数要求：
- `initObject` 必须是对象，否则会抛出 `TypeError` 异常。
- 若 `initObject` 是代理对象，将抛出 `TypeError` 异常。
- 不能将委托对象作为 `initObject`，否则抛出 `TypeError` 异常。
- 若 `initObject` 是不可扩展的，则抛出 `TypeError` 异常。
- 若 `initObject` 中某些属性无法定义，将抛出 `TypeError` 异常，此时 `initObject` 中仅部分属性定义成功。

(3) `propertyFilterFlags`：可选参数。表示属性过滤器。如果传入的是 undefined，表示不指定过滤器。参数要求：
- 以下列出了当前支持的属性过滤器（未来可能扩展）。
```sh
__Longque__.SKIP_PROTOTYPE_CHAIN: 只委托 underlyingObject 自身属性，不考虑原型链 
__Longque__.SKIP_PREFIX_UNDERSCORE: 过滤掉名字以 '_' 开头的属性
__Longque__.SKIP_PREFIX_DOLLAR: 过滤掉名字以 '$' 开头的属性
__Longque__.SKIP_CONSTRUCTOR: 过滤掉 'constructor' 属性
```
- 必须使用列出的过滤器，否则接口行为未定义，可能导致代码兼容性问题。
- 所有过滤器均为 `number` 类型，可用 | 运算符同时指定多个。
- 若 `propertyFilterFlags` 非 `number` 类型，抛出 `TypeError` 异常。

### 返回值
只有接口在不抛出异常的情况下，才会正确返回：
- 若未指定初始委托对象，返回新创建的委托对象。
- 若已指定初始委托对象，返回该初始委托对象。

### 注意事项
(1) 委托对象的属性顺序可能与 for-in、Object.keys 方法的结果不一致，请勿依赖属性顺序。

(2) 委托对象的实现是引擎内部机制。请勿依赖在委托对象上调用 `Object.getOwnPropertyDescriptor`、`getOwnPropertyDescriptors`、`Reflect.getOwnPropertyDescriptor` 等接口的返回结果。

### 使用示例

```js
function createDelegateTest() {
  var myobj = {
    42: 0,
    x: 1,
    _y: 2,
    $z:3
  };

  var proto = {
    foo: 'foo'
  };
  Object.setPrototypeOf(myobj, proto);

  var d1 = __Longque__.createDelegate(myobj, undefined);
  console.log(JSON.stringify(d1)); // {"42":0,"x":1,"_y":2,"$z":3,"foo":"foo"}

  const propertyFilterFlags = __Longque__.SKIP_PREFIX_UNDERSCORE | __Longque__.SKIP_PREFIX_DOLLAR;
  var d2 = __Longque__.createDelegate(myobj, undefined, propertyFilterFlags);
  console.log(JSON.stringify(d2)); // {"42":0,"x":1,"foo":"foo"}

  d2[42] = 100;

  const newFilter = propertyFilterFlags | __Longque__.SKIP_PROTOTYPE_CHAIN;
  var d3 = __Longque__.createDelegate(myobj, undefined, newFilter);
  console.log(JSON.stringify(d3)); // {"42":100,"x":1}
}

createDelegateTest();
```