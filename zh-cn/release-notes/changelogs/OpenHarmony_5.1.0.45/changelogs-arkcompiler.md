# ArkCompiler子系统变更说明

## cl.arkcompiler.1 在Array上查找属性以及设置属性的行为变更说明

**访问级别**

公开接口

**变更原因**

ECMAScript 规范中规定，当对某些Array实例进行某些查询，而查询的属性在Array实例自身上不存在时，需遍历原型链来执行查询。由于部分非StableArray的情况被识别为StableArray，导致跳过了原型链查询，查询结果与 ECMAScript 规范所定义的预期结果不一致。

**变更影响**

此变更不涉及应用适配。

**变更前**

- 情况一：当一个对象(o)是Array类型的实例时，通过特定方式(`fill, push, splice, unshift`)修改(Array.prototype)，部分接口(`concat, slice, at, reduce, reverse`)无法正确从(o)上读取到(Array.prototype)上的元素，返回错误结果。
- 情况二：当一个类MyArray继承自Array，对象(o)是MyArray的实例时，(o)上的constructor属性未被正确调用，导致对(o)调用`instance of`时返回结果错误。
- 情况三：当一个类MyArray继承自Array，对象(o)是MyArray的实例时，修改MyArray.prototype.proto，部分接口(`concat, slice, at, reduce, reverse`)无法正确从(o)上读取到MyArray.prototype.proto上的元素，返回结果错误。
- 情况四：当一个类MyArray继承自Array，对象(o)是MyArray的实例时，向(MyArray.prototype)中插入元素，部分接口(`concat, slice, at, reduce, reverse`)无法正确从(o)上读取到(MyArray.prototype)上的元素，返回结果错误。

```js
// 情况一：
function BehaviorChange1() {
// 以下有四种方法修改Array.prototype, 效果都是让Array.prototype = [233, 233, 233], 不同代码之间是并列关系
//  ----------------- 方法1 -----------------
    let arr1 = new Array(10);
    arr1.__proto__.length = 3;
    arr1.__proto__.fill(233, 0, 3);
//  ----------------- 方法1 -----------------

//  ----------------- 方法2 -----------------
    let arr1 = new Array(10);
    arr1.__proto__.push(233, 233, 233);
//  ----------------- 方法2 -----------------

//  ----------------- 方法3 -----------------
    let arr1 = new Array(10);
    arr1.__proto__.length = 3;
    arr1.__proto__.splice(1, 0, 233, 233, 233);
//  ----------------- 方法3 -----------------

//  ----------------- 方法4 -----------------
    let arr1 = new Array(10);
    arr1.__proto__.unshift(233, 233, 233);
//  ----------------- 方法4 -----------------

    let arr2 = new Array(10);
    let arr3 = arr1.concat(arr2);
    print(arr3[11]); // 输出：undefined，不符合规范

    let arr4 = arr1.slice(1);
    print(arr4[0]); // 输出：undefined，不符合规范

    let res = arr1.at(1);
    print(res); // 输出：undefined，不符合规范

    const sum = arr1.reduce((accumulator, currentValue) => {
        return accumulator + currentValue;
    })
    print(sum); // 输出：undefined，不符合规范

    arr1.reverse();
    print(arr1[1]); //输出: undefined，不符合规范
}
BehaviorChange1();

// 情况二：
function BehaviorChange2() {
    class MyArray extends Array {}
    let custom = new MyArray(1, 2, 3);
    let result1 = custom.concat([4, 5]);
    print(result1 instanceof MyArray); // 输出：false，不符合规范

    let result2 = custom.slice(1);
    print(result2 instanceof MyArray); // 输出：false，不符合规范
}
BehaviorChange2()

// 情况三：
function BehaviorChange3() {
    class MyArray extends Array {}
    let arr1 = new MyArray(10);
    MyArray.prototype.__proto__ = [233, 233, 233];
    let arr2 = new Array(10);
    let arr3 = arr1.concat(arr2);
    print(arr3[1]); // 输出：undefined，不符合规范

    let arr4 = arr1.slice(1);
    print(arr4[0]); // 输出：undefined，不符合规范

    let res = arr1.at(1);
    print(res); // 输出：undefined，不符合规范

    const sum = arr1.reduce((accumulator, currentValue) => {
        return accumulator + currentValue;
    })
    print(sum); // 输出：undefined，不符合规范

    arr1.reverse();
    print(arr1[1]); //输出: undefined，不符合规范
}
BehaviorChange3();

// 情况四：
function BehaviorChange4() {
    class MyArray extends Array {}
    let arr1 = new MyArray(10);
    MyArray.prototype[0] = 233;
    MyArray.prototype[1] = 233;
    MyArray.prototype[2] = 233;

    let arr2 = new Array(10);
    let arr3 = arr1.concat(arr2);
    print(arr3[1]); // 输出：undefined，不符合规范

    let arr4 = arr1.slice(1);
    print(arr4[0]); // 输出：undefined，不符合规范

    let res = arr1.at(1);
    print(res); // 输出：undefined，不符合规范

    const sum = arr1.reduce((accumulator, currentValue) => {
        return accumulator + currentValue;
    })
    print(sum); // 输出：undefined，不符合规范

    arr1.reverse();
    print(arr1[1]); //输出: undefined，不符合规范
}
BehaviorChange4();
```
**变更后**

- 情况一：当一个对象(o)是Array类型的实例时，通过特定方式(`fill, push, splice, unshift`)修改(Array.prototype)，接口(`concat, slice, at, reduce, reverse`)正确从(o)上读取到(Array.prototype)上的元素，返回正确结果（不兼容变更）。
- 情况二：当一个类MyArray继承自Array，对象(o)是MyArray的实例时，(o)上的constructor属性未被正确调用，对(o)调用`instance of`时返回正确结果（不兼容变更）。
- 情况三：当一个类MyArray继承自Array，对象(o)是MyArray的实例时，修改MyArray.prototype.proto，接口(`concat, slice, at, reduce, reverse`)正确从(o)上读取到MyArray.prototype.proto上的元素，返回正确结果（不兼容变更）。
- 情况四：当一个类MyArray继承自Array，对象(o)是MyArray的实例时，向(MyArray.prototype)中插入元素，接口(`concat, slice, at, reduce, reverse`)正确从(o)上读取到(MyArray.prototype)上的元素，返回正确结果（不兼容变更）。

```js
// 情况一：
function BehaviorChange1() {
// 以下有四种方法修改Array.prototype, 效果都是让Array.prototype = [233, 233, 233], 不同代码之间是并列关系
//  ----------------- 方法1 -----------------
    let arr1 = new Array(10);
    arr1.__proto__.length = 3;
    arr1.__proto__.fill(233, 0, 3);
//  ----------------- 方法1 -----------------

//  ----------------- 方法2 -----------------
    let arr1 = new Array(10);
    arr1.__proto__.push(233, 233, 233);
//  ----------------- 方法2 -----------------

//  ----------------- 方法3 -----------------
    let arr1 = new Array(10);
    arr1.__proto__.length = 3;
    arr1.__proto__.splice(1, 0, 233, 233, 233);
//  ----------------- 方法3 -----------------

//  ----------------- 方法4 -----------------
    let arr1 = new Array(10);
    arr1.__proto__.unshift(233, 233, 233);
//  ----------------- 方法4 -----------------

    let arr2 = new Array(10);
    let arr3 = arr1.concat(arr2);
    print(arr3[11]); // 输出：233 符合规范，concat的时候当自身没有时会遍历原型链

    let arr4 = arr1.slice(1);
    print(arr4[0]); // 输出：233 符合规范，slice的时候当自身没有时会遍历原型链

    let res = arr1.at(1);
    print(res); // 输出：233 符合规范，at的时候当自身没有时会遍历原型链

    const sum = arr1.reduce((accumulator, currentValue) => {
        return accumulator + currentValue;
    })
    print(sum); // 输出：699 符合规范，reduce的时候当自身没有时会遍历原型链

    arr1.reverse();
    print(arr1[1]); //输出: 233 符合规范，reverse的时候当自身没有时会遍历原型链
}
BehaviorChange1();

// 情况二：
function BehaviorChange2() {
    class MyArray extends Array {}
    let custom = new MyArray(1, 2, 3);
    let result1 = custom.concat([4, 5]);
    print(result1 instanceof MyArray); // 输出：true 符合规范，custom上的constructor方法被正确调用

    let result2 = custom.slice(1);
    print(result2 instanceof MyArray); // 输出：true 符合规范，custom上的constructor方法被正确调用
}
BehaviorChange2()

// 情况三：
function BehaviorChange3() {
    class MyArray extends Array {}
    let arr1 = new MyArray(10);
    MyArray.prototype.__proto__ = [233, 233, 233];
    let arr2 = new Array(10);
    let arr3 = arr1.concat(arr2);
    print(arr3[1]); // 输出：233 符合规范，concat的时候当自身没有时会遍历原型链

    let arr4 = arr1.slice(1);
    print(arr4[0]); // 输出：233 符合规范，slice的时候当自身没有时会遍历原型链

    let res = arr1.at(1);
    print(res); // 输出：233 符合规范，at的时候当自身没有时会遍历原型链

    const sum = arr1.reduce((accumulator, currentValue) => {
        return accumulator + currentValue;
    })
    print(sum); // 输出：233 符合规范，reduce的时候当自身没有时会遍历原型链

    arr1.reverse();
    print(arr1[1]); //输出: 233 符合规范，reverse的时候当自身没有时会遍历原型链
}
BehaviorChange3();

// 情况四：
function BehaviorChange4() {
    class MyArray extends Array {}
    let arr1 = new MyArray(10);
    MyArray.prototype[0] = 233;
    MyArray.prototype[1] = 233;
    MyArray.prototype[2] = 233;

    let arr2 = new Array(10);
    let arr3 = arr1.concat(arr2);
    print(arr3[1]); // 输出：233 符合规范，concat的时候当自身没有时会遍历原型链

    let arr4 = arr1.slice(1);
    print(arr4[0]); // 输出：233 符合规范，slice的时候当自身没有时会遍历原型链

    let res = arr1.at(1);
    print(res); // 输出：233 符合规范，at的时候当自身没有时会遍历原型链

    const sum = arr1.reduce((accumulator, currentValue) => {
        return accumulator + currentValue;
    })
    print(sum); // 输出：699 符合规范，reduce的时候当自身没有时会遍历原型链

    arr1.reverse();
    print(arr1[1]); // 输出: 233 符合规范，reverse的时候当自身没有时会遍历原型链
}
BehaviorChange4();


```

**起始API Level**

API 9

**变更发生版本**

从OpenHarmony 5.1.0.45 版本开始。

**变更的接口/组件**

涉及Array中`instance of, concat, slice, at, reduce, reverse`接口，详细触发操作见上文。

**适配指导**

在Array上查找属性时注意返回值的变更。
