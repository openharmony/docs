# ArkCompiler Subsystem Changelog

## cl.arkcompiler.1 Behavior Change for Property Lookup and Setting on Array

**Access Level**

Public API

**Reason for Change**

According to the ECMAScript specification, when certain properties are queried on Array instances and these properties do not exist on the Array instance itself, the prototype chain should be traversed to perform the query. Some non-StableArrays are mistakenly identified as StableArrays. As a result, the prototype chain query is skipped, and the query result is inconsistent with the expected outcomes defined by the ECMAScript specification.

**Impact of the Change**

This change does not require application adaptation.

**Before**

- Case 1: When an object (o) is an instance of the Array type and (Array.prototype) is modified using specific methods (**fill**, **push**, **splice**, or **unshift**), certain APIs (**concat**, **slice**, **at**, **reduce**, or **reverse**) cannot correctly read elements from (o) on (Array.prototype), returning an incorrect result.
- Case 2: When a class MyArray inherits from Array and an object (o) is an instance of MyArray, the constructor property on (o) is not correctly invoked, leading to incorrect results when calling **instance of** on (o).
- Case 3: When a class MyArray inherits from Array, an object (o) is an instance of MyArray, and MyArray.prototype.proto is modified, certain APIs (**concat**, **slice**, **at**, **reduce**, or **reverse**) cannot correctly read elements from (o) on MyArray.prototype.proto, returning an incorrect result.
- Case 4: When a class MyArray inherits from Array, an object (o) is an instance of MyArray, and an element is inserted to (MyArray.prototype), certain APIs (**concat**, **slice**, **at**, **reduce**, or **reverse**) cannot correctly read elements from (o) on (MyArray.prototype), returning an incorrect result.

```js
// Case 1:
function BehaviorChange1() {
// The following provides four methods to modify Array.prototype, making Array.prototype = [233, 233, 233]. Each code block is parallel.
// ----------------- Method 1 -----------------
    let arr1 = new Array(10);
    arr1.__proto__.length = 3;
    arr1.__proto__.fill(233, 0, 3);
// ----------------- Method 1 -----------------

// ----------------- Method 2 -----------------
    let arr1 = new Array(10);
    arr1.__proto__.push(233, 233, 233);
// ----------------- Method 2 -----------------

// ----------------- Method 3 -----------------
    let arr1 = new Array(10);
    arr1.__proto__.length = 3;
    arr1.__proto__.splice(1, 0, 233, 233, 233);
// ----------------- Method 3 -----------------

// ----------------- Method 4 -----------------
    let arr1 = new Array(10);
    arr1.__proto__.unshift(233, 233, 233);
// ----------------- Method 4 -----------------

    let arr2 = new Array(10);
    let arr3 = arr1.concat(arr2);
    print(arr3[11]); // Output: undefined, non-compliant

    let arr4 = arr1.slice(1);
    print(arr4[0]); // Output: undefined, non-compliant

    let res = arr1.at(1);
    print(res); // Output: undefined, non-compliant

    const sum = arr1.reduce((accumulator, currentValue) => {
        return accumulator + currentValue;
    })
    print(sum); // Output: undefined, non-compliant

    arr1.reverse();
    print(arr1[1]); // Output: undefined, non-compliant
}
BehaviorChange1();

// Case 2:
function BehaviorChange2() {
    class MyArray extends Array {}
    let custom = new MyArray(1, 2, 3);
    let result1 = custom.concat([4, 5]);
    print(result1 instanceof MyArray); // Output: false, non-compliant

    let result2 = custom.slice(1);
    print(result2 instanceof MyArray); // Output: false, non-compliant
}
BehaviorChange2()

// Case 3:
function BehaviorChange3() {
    class MyArray extends Array {}
    let arr1 = new MyArray(10);
    MyArray.prototype.__proto__ = [233, 233, 233];
    let arr2 = new Array(10);
    let arr3 = arr1.concat(arr2);
    print(arr3[1]); // Output: undefined, non-compliant

    let arr4 = arr1.slice(1);
    print(arr4[0]); // Output: undefined, non-compliant

    let res = arr1.at(1);
    print(res); // Output: undefined, non-compliant

    const sum = arr1.reduce((accumulator, currentValue) => {
        return accumulator + currentValue;
    })
    print(sum); // Output: undefined, non-compliant

    arr1.reverse();
    print(arr1[1]); // Output: undefined, non-compliant
}
BehaviorChange3();

// Case 4:
function BehaviorChange4() {
    class MyArray extends Array {}
    let arr1 = new MyArray(10);
    MyArray.prototype[0] = 233;
    MyArray.prototype[1] = 233;
    MyArray.prototype[2] = 233;

    let arr2 = new Array(10);
    let arr3 = arr1.concat(arr2);
    print(arr3[1]); // Output: undefined, non-compliant

    let arr4 = arr1.slice(1);
    print(arr4[0]); // Output: undefined, non-compliant

    let res = arr1.at(1);
    print(res); // Output: undefined, non-compliant

    const sum = arr1.reduce((accumulator, currentValue) => {
        return accumulator + currentValue;
    })
    print(sum); // Output: undefined, non-compliant

    arr1.reverse();
    print(arr1[1]); // Output: undefined, non-compliant
}
BehaviorChange4();
```
**After change**

- Case 1: When an object (o) is an instance of the Array type and (Array.prototype) is modified using specific methods (**fill**, **push**, **splice**, or **unshift**), the APIs (**concat**, **slice**, **at**, **reduce**, or **reverse**) can correctly read elements from (o) on (Array.prototype), returning the correct result. (incompatible change)
- Case 2: When a class MyArray inherits from Array and an object (o) is an instance of MyArray, the constructor property on (o) is not correctly invoked, leading to correct results when calling **instance of** on (o). (incompatible change)
- Case 3: When a class MyArray inherits from Array, an object (o) is an instance of MyArray, and MyArray.prototype.proto is modified, the APIs (**concat**, **slice**, **at**, **reduce**, or **reverse**) can correctly read elements from (o) on MyArray.prototype.proto, returning the correct result. (incompatible change)
- Case 4: When a class MyArray inherits from Array, an object (o) is an instance of MyArray, and an element is inserted to (MyArray.prototype), the APIs (**concat**, **slice**, **at**, **reduce**, or **reverse**) can correctly read elements from (o) on (MyArray.prototype), returning the correct result. (incompatible change)

```js
// Case 1:
function BehaviorChange1() {
// The following provides four methods to modify Array.prototype, making Array.prototype = [233, 233, 233]. Each code block is parallel.
// ----------------- Method 1 -----------------
    let arr1 = new Array(10);
    arr1.__proto__.length = 3;
    arr1.__proto__.fill(233, 0, 3);
// ----------------- Method 1 -----------------

// ----------------- Method 2 -----------------
    let arr1 = new Array(10);
    arr1.__proto__.push(233, 233, 233);
// ----------------- Method 2 -----------------

// ----------------- Method 3 -----------------
    let arr1 = new Array(10);
    arr1.__proto__.length = 3;
    arr1.__proto__.splice(1, 0, 233, 233, 233);
// ----------------- Method 3 -----------------

// ----------------- Method 4 -----------------
    let arr1 = new Array(10);
    arr1.__proto__.unshift(233, 233, 233);
// ----------------- Method 4 -----------------

    let arr2 = new Array(10);
    let arr3 = arr1.concat(arr2);
    print(arr3[11]); // Output: 233, compliant. concat traverses the prototype chain when the property is not found on the instance.

    let arr4 = arr1.slice(1);
    print(arr4[0]); // Output: 233, compliant. slice traverses the prototype chain when the property is not found on the instance.

    let res = arr1.at(1);
    print(res); // Output: 233, compliant. at traverses the prototype chain when the property is not found on the instance.

    const sum = arr1.reduce((accumulator, currentValue) => {
        return accumulator + currentValue;
    })
    print(sum); // Output: 699, compliant. reduce traverses the prototype chain when the property is not found on the instance.

    arr1.reverse();
    print(arr1[1]); // Output: 233, compliant. reverse traverses the prototype chain when the property is not found on the instance.
}
BehaviorChange1();

// Case 2:
function BehaviorChange2() {
    class MyArray extends Array {}
    let custom = new MyArray(1, 2, 3);
    let result1 = custom.concat([4, 5]);
    print(result1 instanceof MyArray); // Output: true, compliant. constructor on custom is correctly called.

    let result2 = custom.slice(1);
    print(result2 instanceof MyArray); // Output: true, compliant. constructor on custom is correctly called.
}
BehaviorChange2()

// Case 3:
function BehaviorChange3() {
    class MyArray extends Array {}
    let arr1 = new MyArray(10);
    MyArray.prototype.__proto__ = [233, 233, 233];
    let arr2 = new Array(10);
    let arr3 = arr1.concat(arr2);
    print(arr3[1]); // Output: 233, compliant. concat traverses the prototype chain when the property is not found on the instance.

    let arr4 = arr1.slice(1);
    print(arr4[0]); // Output: 233, compliant. slice traverses the prototype chain when the property is not found on the instance.

    let res = arr1.at(1);
    print(res); // Output: 233, compliant. at traverses the prototype chain when the property is not found on the instance.

    const sum = arr1.reduce((accumulator, currentValue) => {
        return accumulator + currentValue;
    })
    print(sum); // Output: 233, compliant. reduce traverses the prototype chain when the property is not found on the instance.

    arr1.reverse();
    print(arr1[1]); // Output: 233, compliant. reverse traverses the prototype chain when the property is not found on the instance.
}
BehaviorChange3();

// Case 4:
function BehaviorChange4() {
    class MyArray extends Array {}
    let arr1 = new MyArray(10);
    MyArray.prototype[0] = 233;
    MyArray.prototype[1] = 233;
    MyArray.prototype[2] = 233;

    let arr2 = new Array(10);
    let arr3 = arr1.concat(arr2);
    print(arr3[1]); // Output: 233, compliant. concat traverses the prototype chain when the property is not found on the instance.

    let arr4 = arr1.slice(1);
    print(arr4[0]); // Output: 233, compliant. slice traverses the prototype chain when the property is not found on the instance.

    let res = arr1.at(1);
    print(res); // Output: 233, compliant. at traverses the prototype chain when the property is not found on the instance.

    const sum = arr1.reduce((accumulator, currentValue) => {
        return accumulator + currentValue;
    })
    print(sum); // Output: 699, compliant. reduce traverses the prototype chain when the property is not found on the instance.

    arr1.reverse();
    print(arr1[1]); // Output: 233, compliant. reverse traverses the prototype chain when the property is not found on the instance.
}
BehaviorChange4();


```

**Start API Level**

API 9

**Change Since**

OpenHarmony 5.1.0.45

**Key API/Component Changes**

**instance of**, **concat**, **slice**, **at**, **reduce**, and **reverse** APIs in Array

**Adaptation Guide**

When looking up properties on Array, pay attention to the changes in return values.
