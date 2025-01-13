# ArkCompiler子系统变更说明

## cl.arkcompiler.1 在TypedArray上查找属性以及设置属性的行为变更说明

**访问级别**

公开接口

**变更原因**

ECMAScript规范中规定了对于在JS对象上调用`Reflect.set`以及`[[HasProperty]]`的行为，这两个函数涉及到遍历原型链的过程。
当遍历原型链过程涉及到TypedArray对象时，当前的运行时实现导致运行返回结果与规范定义的预期结果不一致。

**变更影响**

该变更为不兼容变更。

**变更前**

- 情况一：当一个对象(o)的原型是TypedArray类型的对象(ta)时，通过`in`判断(o)上的是否存在某个属性，如果查找的key是一个大于(ta)的长度的下标，属性判断会返回错误结果。
- 情况二：当一个对象(o)的原型是TypedArray类型的对象(ta)时，通过`in`判断(o)上的是否存在某个属性，如果查找的key是一个Number类型，且这个key在(ta)的原型对象上时，属性判断会返回错误结果。
- 情况三：通过`Reflect.set`向一个对象(o)中的某个属性key设置值value，本地调用的参数中的`receiver`是一个TypedArray类型的对象(ta)，如果属性key是一个NumbericIndex类型且其值大于(ta)的长度时，`Reflect.set`返回错误的结果。

```js
// 情况一：当一个对象(o)的原型是TypedArray类型的对象(ta)时，通过`in`判断(o)上的是否存在某个属性，查找的key是一个大于(ta)的长度的下标 
function BehaviorChange1() {
    // 以Int8Array为例创建一个TypedArray对象
    const typedArray = new Int8Array(5);
    typedArray[1] = 42;

    // 创建一个Object对象，并将它的原型设置为TypedArray对象
    const obj = Object.create(typedArray);
    // 查找Object对象上是否有"6"这个属性的时候，遍历原型链查找
    print(6 in obj); // 输出：true
}
BehaviorChange1();

// 情况二：当一个对象(o)的原型是TypedArray类型的对象(ta)时，通过`in`判断(o)上的是否存在某个属性，查找的key是一个NumbericIndex类型，且这个key在(ta)的原型对象上
function BehaviorChange2() {
    // 创建一个普通的Object对象，持有属性"6"
    const obj1 = {};
    obj1[6] = "b";

    // 以Int8Array为例创建一个TypedArray对象
    const typedArray = new Int8Array(5);
    typedArray[1] = 42;
    // 将typedArray的原型设置为第一步创建的obj1对象
    typedArray.__proto__ = obj1;

    // 创建一个Object对象，并将它的原型设置为TypedArray对象
    const obj = Object.create(typedArray);
    // 查找Object对象上是否有"6"这个属性的时候，遍历原型链查找
    print("6" in obj); // 输出：true
}
BehaviorChange2()

// 情况三：通过`Reflect.set`向一个对象(o)中的某个属性key设置值value，本地调用的参数中的`receiver`是一个TypedArray类型的对象(ta)，属性key是一个NumbericIndex类型且其值大于(ta)的长度
function BehaviorChange3() {
    // 第二个参数是propKey，第三个参数是value，第四个参数是receiver
    print(Reflect.set({}, 100, 123, new Int32Array())); // 输出：true
}
BehaviorChange3();
```

**变更后**

- 情况一：当一个对象(o)的原型是TypedArray类型的对象(ta)时，通过`in`判断(o)上的是否存在某个属性，如果查找的key是一个大于(ta)的长度的下标，属性返回正确结果（不兼容变更）。
- 情况二：当一个对象(o)的原型是TypedArray类型的对象(ta)时，通过`in`判断(o)上的是否存在某个属性，如果查找的key是一个NumbericIndex类型，且这个key在(ta)的原型对象上时，属性判断返回正确结果（不兼容变更）。
- 情况三：通过`Reflect.set`向一个对象(o)中的某个属性key设置值value，本地调用的参数中的`receiver`是一个TypedArray类型的对象(ta)，如果属性key是一个NumbericIndex类型且其值大于(ta)的长度时，`Reflect.set`返回正确的结果（不兼容变更）。

```js
// 情况一：当一个对象(o)的原型是TypedArray类型的对象(ta)时，通过`in`判断(o)上的是否存在某个属性，查找的key是一个大于(ta)的长度的下标 
function BehaviorChange1() {
    // 以Int8Array为例创建一个TypedArray对象
    const typedArray = new Int8Array(5);
    typedArray[1] = 42;

    // 创建一个Object对象，并将它的原型设置为TypedArray对象
    const obj = Object.create(typedArray);
    // 查找Object对象上是否有"6"这个属性的时候，遍历原型链查找
    print(6 in obj); // 输出：false 符合规范，遍历原型链也找不到该属性
}
BehaviorChange1();

// 情况二：当一个对象(o)的原型是TypedArray类型的对象(ta)时，通过`in`判断(o)上的是否存在某个属性，查找的key是一个NumbericIndex类型，且这个key在(ta)的原型对象上
function BehaviorChange2() {
    // 创建一个普通的Object对象，持有属性"6"
    const obj1 = {};
    obj1[6] = "b";

    // 以Int8Array为例创建一个TypedArray对象
    const typedArray = new Int8Array(5);
    typedArray[1] = 42;
    // 将typedArray的原型设置为第一步创建的obj1对象
    typedArray.__proto__ = obj1;

    // 创建一个Object对象，并将它的原型设置为TypedArray对象
    const obj = Object.create(typedArray);
    // 查找Object对象上是否有"6"这个属性的时候，遍历原型链查找
    print("6" in obj); // 输出：false 符合规范，key是一个NumbericIndex类型，遍历原型链查找到typedArray后，不会再往之后的链上查找了
}
BehaviorChange2()

// 情况三：通过`Reflect.set`向一个对象(o)中的某个属性key设置值value，本地调用的参数中的`receiver`是一个TypedArray类型的对象(ta)，属性key是一个NumbericIndex类型且其值大于(ta)的长度
function BehaviorChange3() {
    // 第二个参数是propKey，第三个参数是value，第四个参数是receiver
    print(Reflect.set({}, 100, 123, new Int32Array())); // 输出：false 100大于TypedArray对象的长度，添加属性会失败
}
BehaviorChange3();
```

**起始API Level**

API 9

**变更发生版本**

从OpenHarmony 5.1.0.46 版本开始。

**变更的接口/组件**

使用ECMAScript内置函数`in`以及`Reflect.set`对Object类型对象且原型对象为TypedArray对象（包括Int8Array/Uint8Array/Int16Array/Uint16Array/Int32Array/Uint32Array/Uint8ClampedArray/Float32Array/Float64Array）进行属性访问相关的操作。

**适配指导**

使用上述三种情况访问或者设置TypedArray中的属性时注意返回值的变更。
