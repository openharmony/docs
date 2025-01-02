# ArkCompiler Subsystem Changelog

## cl.arkcompiler.1 Callback Function Declaration of map Provided by Sendable TypedArray Is Changed

**Access Level**

Public API

**Reason for Change**

The sendable TypedArray container provides the **map** API. This API performs an operation or conversion (through the return value of **callbackFn**) on each element in a typed array and returns a new typed array that contains the elements after the processing.

The following uses Uint8Array as an example. Before the change, the **callbackFn** function declaration of the **map** API has no return value. As a result, the data after conversion is lost.
- Declare the callback function of the **map** API as follows: **map(callbackFn: TypedArrayForEachCallback\<number, Uint8Array>): Uint8Array**.
- **TypedArrayForEachCallback** is defined without a return value, as follows: **type TypedArrayForEachCallback\<ElementType, ArrayType> = (value: ElementType, index: number, array: ArrayType) => void**.

**Change Impact**

This change is a non-compatible change.

**Before Change**

- Case 1: The **callbackFn** function in the **map** API has no return value. The code can be compiled, but the implementation is different from that expected.
- Case 2: The **callbackFn** function in the **map** API has a return value, the type of which is not number. The code can be compiled, and the implementation is the same as that expected.
- Case 3: The **callbackFn** function in the **map** API has a return value, the type of which is number. The code can be compiled, and the implementation is the same as that expected.

  ```
  let arr = [1, 2, 3, 4, 5];
  
  // Create a Uint8Array.
  let uint8: collections.Uint8Array = new collections.Uint8Array(arr);
  
  // Case 1: The feature of map is not implemented. callbackFn has no return value, and the map API returns a new collections.Uint8Array.
  let zeroMappedArray: collections.Uint8Array = uint8.map((value: number) => {}); // The compilation is successful.
  console.info('' + zeroMappedArray); // Output: collections.Uint8Array [0, 0, 0, 0, 0]
  
  // Case 2: The feature of map is implemented. callbackFn returns an element value (in the form of a string) after map is called, and the map API returns a new collections.Uint8Array.
  let wrongTypeMapped: collections.Uint8Array = uint8.map((value: number) => value + "1"); // The compilation is successful.
  console.info('' + wrongTypeMapped); //Output: collections.Uint8Array [11, 21, 31, 41, 51]
  
  // Case 3: The feature of map is implemented. callbackFn returns an element value after map is called, and the map API returns a new collections.Uint8Array.
  let normalMapped: collections.Uint8Array = uint8.map((value: number) => value * 2); // The compilation is successful.
  console.info('' + normalMapped); // Output: collections.Uint8Array [2, 4, 6, 8, 10]
  ```

**After Change**

- Case 1: The **callbackFn** function in the **map** API has no return value. The code cannot be compiled. (This change is incompatible.)
- Case 2: The **callbackFn** function in the **map** API has a return value, the type of which is not number. The code cannot be compiled. (This change is incompatible.)
- Case 3: The **callbackFn** function in the **map** API has a return value, the type of which is number. The code can be compiled, and the implementation is the same as that expected. (This change is compatible.)


    ```
    let arr = [1, 2, 3, 4, 5];
    
    // Create a Uint8Array.
    let uint8: collections.Uint8Array = new collections.Uint8Array(arr);
    
    // Case 1: The feature of map is not implemented. callbackFn has no return value, and the map API returns a new collections.Uint8Array.
    let zeroMappedArray: collections.Uint8Array = uint8.map((value: number) => {}); // An incompatible change. The compilation fails. 
    
    // Case 2: The feature of map is implemented. callbackFn returns a string after map is called, and the map API returns a new collections.Uint8Array.
    let wrongTypeMapped: collections.Uint8Array = uint8.map((value: number) => value + "1"); // An incompatible change. The compilation fails. 
    
    // Case 3: The feature of map is implemented. callbackFn returns an element value after map is called, and the map API returns a new collections.Uint8Array.
    let normalMapped: collections.Uint8Array = uint8.map((value: number) => value * 2); // The compilation is successful.
    console.info('' + normalMapped); // Output: collections.Uint8Array [2, 4, 6, 8, 10]
    ```

**Start API Level**

API version 12

**Change Since**

OpenHarmony SDK 5.0.0.31

**Key API/Component Changes**

**map** API of TypedArray (including Int8Array/Uint8Array/Int16Array/Uint16Array/Int32Array/Uint32Array) in the **/interface/sdk-js/arkts/@arkts.collections.d.ets** file.

**Adaptation Guide**

- In the preceding case 2, you can make adaptation as follows:

  ```
  let wrongTypeMapped: collections.Uint8Array = uint8.map((value: number) => parseInt(value + "1")); // Use parseInt to convert a string to a number.
  ```

- For details, see the following sample code:

  [ArkTS Collections - Typed Array](../../../application-dev/reference/apis-arkts/js-apis-arkts-collections.md#collectionstypedarray)

## cl.arkcompiler.2 Compilation Check Enhanced for ArkTS Sendable Syntax Rules

**Access Level**

Others

**Reason for Change**

A sendable object must comply with the [usage rules](../../..//application-dev/arkts-utils/arkts-sendable.md#sendable-usage-rules). In sendable generic class scenarios where some constraints should be made, the compiler does not check for these constraints. As a result, a sendable object using these syntaxes runs abnormally in concurrent scenarios, but no compilation error is reported. In this version update, a compile-time check is added for these constraints. You can find the code that fails to meet the sendable usage constraints earlier through compile-time errors, reducing fault locating costs at the runtime.

**Change Impact**

This change is a non-compatible change.


Before the change: When a sendable generic class is declared as a type, the formal parameter of the type can be of a non-sendable type. In this case, no error message is displayed on the DevEco Studio editing page, and no compilation error is reported.

After the change: When a sendable generic class is declared as a type, the formal parameter of the type cannot be of a non-sendable type. Otherwise, an error message is displayed on the DevEco Studio editing page, and a compilation error is reported.

For variables, parameters, and return values that are declared using a sendable generic class but assigned to a non-sendable object, if they are used in concurrent instance sharing scenarios, runtime exceptions occur before the change, whereas compilation errors are reported after the change. If they are used as common objects, no runtime error is reported before the change, whereas compilation errors are reported after the change.


Example scenarios:

Sendable Generic Class Constraints

Scenario 1: When a sendable object is shared by multiple threads, a runtime exception is reported before the change, whereas a compilation error is reported after the change.

Before change:

```ts
// declaration.ets
export class NonSendableClass {};

// main.ets
import { NonSendableClass } from './declaration';
import collections from '@arkts.collections';

@Sendable
class SendableClass {
    private arr: collections.Array<NonSendableClass> = new collections.Array();
    constructor() {
        this.arr.push(new NonSendableClass()); // Runtime ERROR
    }
}
let sendableclassObject: SendableClass = new SendableClass();
```

After change:

```ts
// declaration.ets
export class NonSendableClass {};

// main.ets
import { NonSendableClass } from './declaration';
import collections from '@arkts.collections';

@Sendable
class SendableClass {
    private arr: collections.Array<NonSendableClass> = new collections.Array(); // ArkTS compile-time error
    constructor() {
        this.arr.push(new NonSendableClass());
    }
}
let sendableclassObject: SendableClass = new SendableClass();
```

Scenario 2: When a sendable object is used as a common object, no error is reported before the change, whereas a compilation error is reported after the change. This change is incompatible.

Before change:

```ts
@Sendable
class SendableClassA<T> {
    one: string = '1';
}
class NoneSendableClassA<T> {
    one: string = '1';
}
let sendableObjectA: SendableClassA<NoneSendableClassA<number>> = new SendableClassA();
```

After change:

```ts
@Sendable
class SendableClassA<T> {
    one: string = '1';
}
class NoneSendableClassA<T> {
    one: string = '1';
}
let sendableObjectA: SendableClassA<NoneSendableClassA<number>> = new SendableClassA(); // ArkTS compile-time error
```

**Start API Level**

API version 12

**Change Since**

OpenHarmony SDK 5.0.0.31

**Key API/Component Changes**

N/A

**Adaptation Guide**

The type of a sendable generic class must be sendable.

## cl.arkcompiler.3 Compilation Check Enhanced for ArkTS Sendable Syntax Rules for Assigning Values

**Access Level**

Others

**Reason for Change**

Sendable value assignment must comply with the [usage rules](../../..//application-dev/arkts-utils/arkts-sendable.md#sendable-usage-rules). However, a non-sendable object can be assigned to the sendable type, and the compiler does not provide a check for this scenario. As a result, a runtime exception occurs when a non-sendable object is used as a sendable object, but no compilation error is reported. In this version update, a compile-time check is added for the constraint. You can find the code that fails to meet the sendable usage constraints earlier through compile-time errors, reducing fault locating costs at the runtime.

Error object: a variable, parameter, or return value that is declared using the sendable type or interface but assigned to a non-sendable object.

**Change Impact**

This change is a non-compatible change.

Before the change: In some scenarios where a non-sendable object is assigned to the sendable type, no error message is displayed on the DevEco Studio editing page, and no compilation error is reported.

After the change: In some scenarios where a non-sendable object is assigned to the sendable type, an error message is displayed on the DevEco Studio editing page, and a compilation error is reported.

When the error object is used as a sendable object, a runtime exception is reported before the change, whereas a compilation error is reported after the change. When the error object is used as a common object, no error is reported before the change, whereas a compilation error is reported after the change. Before the change, a non-sendable object can be assigned to the sendable type in some scenarios. After the change, a non-sendable object cannot be assigned to the sendable type.

An error is reported in the following scenarios: 

Case 1: The error object is used as a sendable object.

Before change:

```ts
// declaration.ets
export class NonSendableClass {};
@Sendable
export class SendableClass {};

export class NonSendableClassT<T> {};
@Sendable
export class SendableClassT<T> {};

// main.ets
import { NonSendableClass, SendableClass, NonSendableClassT, SendableClassT } from './declaration';
import collections from '@arkts.collections';

@Sendable
class SendableData {
    propA: SendableClass = new NonSendableClass(); // Runtime ERROR
    propB: SendableClassT<number>;
    propC: SendableClass;
    propD: SendableClass;
    propE: SendableClass;

    constructor(sendableT: SendableClassT<number>) {
      const sendableList: SendableClass[] = [new NonSendableClass()];
      this.propB = new NonSendableClassT<number>(); // Runtime ERROR
      this.propC = this.getSendable(); // Runtime ERROR
      this.propD = sendableList[0]; // Runtime ERROR
      this.propE = sendableT; // Runtime ERROR
    }

    getSendable(): SendableClass {
        return new NonSendableClass();
    }
}

new SendableData(new NonSendableClassT<number>());

const sendable: SendableClassT<number> = new NonSendableClassT<number>();
const sendableArray: collections.Array<SendableClass> = new collections.Array<SendableClass>();
sendableArray.push(sendable); // Runtime ERROR

```

After change:

```ts
// declaration.ets
export class NonSendableClass {};
@Sendable
export class SendableClass {};

export class NonSendableClassT<T> {};
@Sendable
export class SendableClassT<T> {};

// main.ets
import { NonSendableClass, SendableClass, NonSendableClassT, SendableClassT } from './declaration';
import collections from '@arkts.collections';

@Sendable
class SendableData {
    propA: SendableClass = new NonSendableClass(); // ArkTS compile-time error
    propB: SendableClassT<number>;
    propC: SendableClass;
    propD: SendableClass;
    propE: SendableClass;
    
    constructor(sendableT: SendableClassT<number>) {
      const sendableList: SendableClass[] = [new NonSendableClass()]; // ArkTS compile-time error
      this.propB = new NonSendableClassT<number>(); // ArkTS compile-time error
      this.propC = this.getSendable(); 
      this.propD = sendableList[0]; 
      this.propE = sendableT;
    }

    getSendable(): SendableClass {
        return new NonSendableClass(); // ArkTS compile-time error
    }
}

new SendableData(new NonSendableClassT<number>()); // ArkTS compile-time error

const sendable: SendableClassT<number> = new NonSendableClassT<number>(); // ArkTS compile-time error
const sendableArray: collections.Array<SendableClass> = new collections.Array<SendableClass>();
sendableArray.push(sendable);

```

Case 2: The error object is used as a common object.

Before change:

```ts
class NonSendableClass {};
@Sendable
class SendableClass {};

class NonSendableClassT<T> {};
@Sendable
class SendableClassT<T> {};

function getSendable(): SendableClass {
    return new NonSendableClass();
}

const objectA: SendableClass = getSendable();
const objectB: SendableClassT<number> = new NonSendableClassT<number>();

```

After change:

```ts
class NonSendableClass {};
@Sendable
class SendableClass {};

class NonSendableClassT<T> {};
@Sendable
class SendableClassT<T> {};

function getSendable(): SendableClass {
    return new NonSendableClass(); // ArkTS compile-time error
}

const objectA: SendableClass = getSendable();
const objectB: SendableClassT<number> = new NonSendableClassT<number>(); // ArkTS compile-time error

```

**Start API Level**

API version 12

**Change Since**

OpenHarmony SDK 5.0.0.31

**Key API/Component Changes**

N/A

**Adaptation Guide**

Do not assign a non-sendable object to a sendable variable, parameter, or return value.
