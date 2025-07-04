# ArkCompiler Subsystem Changelog

## cl.arkcompiler.1 Behavior Change for Property Lookup and Setting on TypedArray

**Access Level**

Public API

**Reason for Change**

The ECMAScript specification defines the behavior of calling **Reflect.set** and** [[HasProperty]]** on JS objects, both of which involve traversing the prototype chain.
If a TypedArray object is involved in the process of traversing the prototype chain, the current runtime implementation causes the return value to be inconsistent with the expected result defined in the specifications.

**Impact of the Change**

This change is a non-compatible change.

**Before**

- Case 1: When an object (o) has a prototype that is a TypedArray object (ta), using **in** to check whether a property exists on (o) returns an incorrect result if the key being checked is an index greater than the length of (ta).
- Case 2: When an object (o) has a prototype that is a TypedArray object (ta), using **in** to check whether a property exists on (o) returns an incorrect result if the key being checked is a Number type and exists on the prototype of (ta).
- Case 3: Using **Reflect.set** to set a value for a property key on an object (o), where the receiver in the local call is a TypedArray object (ta), returns an incorrect result if the property key is a NumericIndex type with a value greater than the length of (ta).

```js
// Case 1: When an object (o) has a prototype that is a TypedArray object (ta), using in to check whether a property exists on (o), and the key being checked is an index greater than the length of (ta).
function BehaviorChange1() {
    // Create a TypedArray object using Int8Array as an example.
    const typedArray = new Int8Array(5);
    typedArray[1] = 42;

    // Create an Object object and set its prototype to the TypedArray object.
    const obj = Object.create(typedArray);
    // Traverse the prototype chain to check whether the object has the property "6".
    print(6 in obj); // Output: true
}
BehaviorChange1();

// Case 2: When an object (o) has a prototype that is a TypedArray object (ta), using in to check whether a property exists on (o), and the key being checked is a Number type that exists on the prototype of (ta).
function BehaviorChange2() {
    // Create a regular Object object holding the property "6".
    const obj1 = {};
    obj1[6] = "b";

    // Create a TypedArray object using Int8Array as an example.
    const typedArray = new Int8Array(5);
    typedArray[1] = 42;
    // Set the prototype of typedArray to the obj1 object created in the first step.
    typedArray.__proto__ = obj1;

    // Create an Object object and set its prototype to the TypedArray object.
    const obj = Object.create(typedArray);
    // Traverse the prototype chain to check whether the object has the property "6".
    print("6" in obj); // Output: true
}
BehaviorChange2()

// Case 3: Using Reflect.set to set a value for a property key on an object (o), where the receiver in the local call is a TypedArray object (ta), and the property key is a NumericIndex type with a value greater than the length of (ta).
function BehaviorChange3() {
    // The second parameter is propKey, the third parameter is value, and the fourth parameter is receiver.
    print(Reflect.set({}, 100, 123, new Int32Array())); // Output: true
}
BehaviorChange3();
```

**After**

- Case 1: When an object (o) has a prototype that is a TypedArray object (ta), using **in** to check whether a property exists on (o) returns the correct result if the key being checked is an index greater than the length of (ta). (incompatible change)
- Case 2: When an object (o) has a prototype that is a TypedArray object (ta), using **in** to check whether a property exists on (o) returns the correct result if the key being checked is a Number type that exists on the prototype of (ta). (incompatible change)
- Case 3: Using **Reflect.set** to set a value for a property key on an object (o), where the receiver in the local call is a TypedArray object (ta), returns the correct result if the property key is a NumericIndex type with a value greater than the length of (ta). (incompatible change)

```js
// Case 1: When an object (o) has a prototype that is a TypedArray object (ta), using in to check whether a property exists on (o), and the key being checked is an index greater than the length of (ta).
function BehaviorChange1() {
    // Create a TypedArray object using Int8Array as an example.
    const typedArray = new Int8Array(5);
    typedArray[1] = 42;

    // Create an Object object and set its prototype to the TypedArray object.
    const obj = Object.create(typedArray);
    // Traverse the prototype chain to check whether the object has the property "6".
    print(6 in obj); // Output: false (consistent with the specification. The property cannot be found even after traversing the prototype chain.)
}
BehaviorChange1();

// Case 2: When an object (o) has a prototype that is a TypedArray object (ta), using in to check whether a property exists on (o), and the key being checked is a Number type that exists on the prototype of (ta).
function BehaviorChange2() {
    // Create a regular Object object holding the property "6".
    const obj1 = {};
    obj1[6] = "b";

    // Create a TypedArray object using Int8Array as an example.
    const typedArray = new Int8Array(5);
    typedArray[1] = 42;
    // Set the prototype of typedArray to the obj1 object created in the first step.
    typedArray.__proto__ = obj1;

    // Create an Object object and set its prototype to the TypedArray object.
    const obj = Object.create(typedArray);
    // Traverse the prototype chain to check whether the object has the property "6".
    print("6" in obj); // Output: false (consistent with the specification. The key is a NumericIndex type, and the search stops at typedArray.)
}
BehaviorChange2()

// Case 3: Using Reflect.set to set a value for a property key on an object (o), where the receiver in the local call is a TypedArray object (ta), and the property key is a NumericIndex type with a value greater than the length of (ta).
function BehaviorChange3() {
    // The second parameter is propKey, the third parameter is value, and the fourth parameter is receiver.
    print(Reflect.set({}, 100, 123, new Int32Array())); // Output: false (100 is greater than the length of the TypedArray object. Therefore, adding the property fails.)
}
BehaviorChange3();
```

**Start API Level**

API 9

**Change Since**

OpenHarmony 5.1.0.46

**Key API/Component Changes**

Using the ECMAScript built-in functions **in** and **Reflect.set** for property access-related operations on Object type objects with TypedArray objects (including Int8Array, Uint8Array, Int16Array, Uint16Array, Int32Array, Uint32Array, Uint8ClampedArray, Float32Array, Float64Array) as their prototypes.

**Adaptation Guide**

When accessing or setting properties on TypedArray objects in the scenarios described above, pay attention to the changes in return values.
