# ArkCompiler Subsystem Changelog

## cl.ArkCompiler.1 ArkTS Syntax Validator Change

Compared with OpenHarmony SDK 4.0.10.8, the syntax validator in OpenHarmony SDK 4.0.10.10/11 is able to detect violations of the following rules and reports corresponding errors.

> **NOTE**
> This change is only an enhancement of the syntax validator capability. The syntax rules below are not new rules themselves.

### Rule arkts-no-classes-as-obj

This rule checks usage of an imported class as a variable. Below is an example:

 ```ts
// module1.ets
export class C {}

// module2.ets
import { C } from './module1'

let c = C  // error: arkts-no-class-as-obj
 ```

**Change Impact**

Code adaptation is required. Otherwise, the compilation fails.

**Key API/Component Changes**

The ArkTS syntax validator is enhanced.

**Adaptation Guide**

Modify code files that do not comply with the ArkTS syntax rules. For details about the rules and modification suggestions, see [Adaptation Cases](../../../application-dev/quick-start/arkts-more-cases.md#arkts-no-classes-as-obj).

### Rule arkts-strict-typing

This rule checks assignment of values of the **X | undefined** type to an entity of the **X** type in the .ets file. Below is an example:

 ```ts
// module.ets
function foo(a: number) {
  return a + 1
}

function bar(x: number): number | undefined {
  return x > 0 ? x : undefined
}

foo(bar(-123))  // error: arkts-strict-typing
 ```

This rule checks assignment of values of the **X | null** type to an entity of the **X** type in the .ets file. Below is an example:

 ```ts
// module.ets
function foo(a: number) {
  return a + 1
}

function bar(x: number): number | null {
  return x > 0 ? x : null
}

foo(bar(-123))  // error: arkts-strict-typing
 ```

**Change Impact**

Code adaptation is required. Otherwise, the compilation fails.

**Key API/Component Changes**

The ArkTS syntax validator is enhanced.

**Adaptation Guide**

Modify code files that do not comply with the ArkTS syntax rules. For details about the rules and modification suggestions, see [Adaptation Cases](../../../application-dev/quick-start/arkts-more-cases.md#arkts-strict-typingstrictmodeerror).

### Rule arkts-no-ts-deps

This rule checks imports of entities from an .ets file to a .ts file. Below is an example:


 ```ts
// lib.ts
export class C {}


// module.ets
import { C } from './lib'
 ```

**Change Impact**

Code adaptation is required. Otherwise, the compilation fails.

**Key API/Component Changes**

The ArkTS syntax validator is enhanced.

**Adaptation Guide**

Modify code files that do not comply with the ArkTS syntax rules. For details about the rules and modification suggestions, see [Adaptation Cases](../../../application-dev/quick-start/arkts-more-cases.md#arkts-no-tsdeps).

## cl.ArkCompiler.2 ArkTS Syntax Rule Change

Added ArkTS syntax rule levels: error and warning.

- **Error**: constraint with which compliance is mandatory. An error will result in a compilation failure.
- **Warning**: constraint with which compliance is recommended. A warning does not affect the compilation process, but may cause compilation failures in the future.

Since 4.0.10.11, the levels of rules **arkts-no-definite-assignment** and **arkts-no-decorators-except-arkui** are degraded to warning. If **ESObject** is used in code, a warning is reported.

In addition, the ArkTS syntax supports the following features:

**tuple**, **keyof**, **for-of**, use of expansion characters in array scenarios, re-export, module name suffixed with .js, **readonly**, **Encode**, **Decode**, **ParesHexOctet**, **Array.isArray**, **Object.entries**, **Object.keys**, **Object.values**, **Object.hasOwn**, **Object.hasOwnPropertyNames**, **Reflect.get**, **Reflect.set**, **Reflect.has**, **Reflect.ownKeys**, **Reflect.set**, **Symbol.iterator**, and **Required** and **Readonly** in Utility types.

**Change Impact**

There is no compatibility impact. No code adaptation is required.
