# Ark Native Interface Practical Handbook
## Reference Index

| Name                        | Resource Link                                                                                                                                                                   | Main Purpose                                                                 | Positioning                         |
| ------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------- | ---------------------------------- |
| ANI Getting Started Guide (This Doc) | **[ani-usage-scenarios.md](https://gitee.com/openharmony/docs/blob/OpenHarmony_feature_20250328/en/application-dev/arkts-utils/ani_scenario.md)** | Comprehensive ANI documentation; resolves most issues                        | Beginner guide, must-read reference |
| NAPI to ANI Migration Examples     | **[napi2ani.md](https://gitee.com/liwentao_uiw/arkcompiler_runtime_core/blob/ani_spec/static_core/plugins/ets/runtime/ani/docs/napi2ani.md)**             | Demonstrates correct NAPI-to-ANI function migration for compatibility        | Reference guide for unknown mappings |
| ANI Usage Examples (ani_cookbook)  | **[ani_cookbook](https://gitee.com/ironrain/ani_cookbook)**                                                                                                   | Provides ready-to-use function examples for simple to advanced use cases     | Practical cookbook and starter kit  |
| ANI Interface Test Suite           | **[ani/tests test folder](https://gitee.com/openharmony/arkcompiler_runtime_core/tree/OpenHarmony_feature_20250328/static_core/plugins/ets/tests/ani/tests)** | Validates ANI functions and correctness; always functional                   | Reference for verifying API usage   |
| ani.h Header File                  | **[ani.h](https://gitee.com/openharmony/arkcompiler_runtime_core/blob/OpenHarmony_feature_20250328/static_core/plugins/ets/runtime/ani/ani.h)**           | Core definition file including function declarations, types, and inheritance | Source of truth for all definitions |

## Usage Suggestions

When working on NAPI-to-ANI migration tasks, follow this step-by-step approach:

1. **Understand the ANI Specification:**  
   Read the `ani.h` header file to understand argument types, return value conventions, and all `ani_*` types usages. This forms the foundation for correct migration.

2. **Study Migration Examples:**  
   Refer to `napi2ani.md` for real-world mappings. Observe structure, parameter handling and error processing strategies.

3. **Practice and Validate:**  
   Clone and run examples from `ani_cookbook` in your own development environment. Confirm your understanding through hands-on validation and strengthen familiarity with ANI APIs.
   
# ANI Scenario Documentation

## 1. Using `loadLibrary`

### 1.1 Native Function Binding

The process of binding native functions involves several key steps:

1. Declare native functions and methods in the `.ets` file.
2. In managed code add a call to `loadLibrary(libraryName)` function:
   - This might be done in a static initialization block or in code entrypoint (e.g. `main` function). This is required to guarantee that native library is loaded and all native functions are bound with their implementations before first access to any native function, 
   - `libraryName` is a string with name of native library - e.g. `example.z` for library `libexample.z.so`.
3. In the native library implement entry function `ani_status ANI_Constructor(ani_vm* vm, uint32_t* result)`:
   - Function must be declared with default visibility (i.e. `__attribute__((visibility("default")))`).
   - This function is invoked by implementation of `loadLibrary` right after dynamic library is loaded.
4. Within `ANI_Constructor`, use one of the following binding functions, depending on the scope: `Class_BindNativeMethods`, `Namespace_BindNativeFunctions`, or `Module_BindNativeFunctions`.
5. In native functions definitions provide correct additional arguments, which can be determined basing on the function scope:

| Scope              | Binding Function               | Required Arguments               | Description                                        |
|--------------------|--------------------------------|----------------------------------|----------------------------------------------------|
| Class (non-static) | `Class_BindNativeMethods`      | `ani_env`, `ani_object`          | Operates on instance of class.                     |
| Class (static)     | `Class_BindNativeMethods`      | `ani_env`, `ani_class`           | Operates on the class itself.                      |
| Namespace          | `Namespace_BindNativeFunctions`| `ani_env`                        | No object reference needed.                        |
| Module             | `Module_BindNativeFunctions`   | `ani_env`                        | No object reference needed.                        |

**Note:** The native function signatures in C++ must include these arguments as the leading parameters:

```cpp
// Instance method binding
void nativeInstanceMethod(ani_env* env, ani_object obj, ...);

// Static method binding
void nativeStaticMethod(ani_env* env, ani_class cls, ...);

// Namespace or module binding
void nativeNamespaceFunction(ani_env* env, ...);
```

#### Important Considerations

- Lifetime of local references received by native function is bound to duration of native call. Do **not** store native function parameters beyond their scope — the underlying memory will be released. For more details refer to [Lifecycle Management](#9-lifecycle-management).
- `ani_env` accepted by native functions is guaranteed to be valid during native call. Do **not** store it beyound scope of native call and do not pass it to other threads.
- Interface methods cannot be annotated as `native`.

---

### 1.1.1 Class Name, Identifier, and Symbol Lookup

Use the `ark_disasm` tool to inspect `.abc` files and determine class and symbol names.
Refer [Disassembling ABC Files](#116-disassembling-abc-files) to get `ark_disasm` tool.
Example disassembly:

```ts
.record example.Foo <ets.extends=std.core.Object, access.record=public>
```

Will have corresponding class name `C{example.Foo}` used in signatures and `example.Foo` used for `FindClass`.

---

### 1.1.2 Binding Methods in a Class

The following examples shows how native ArkTS function can be bound with its C++ implementation.
To ensure correct signature used in `Class_BindNativeMethods`, ABC file can be disassembled before writing the code.

**ArkTS Code:**
```ts
class PasteData {
    static { loadLibrary("libraryName") }
    native getRecordCount(a: int): int;
}
```

**Disassembled ABC:**
```ts
.function i32 example.PasteData.getRecordCount(example.PasteData a0, i32 a1) <native, access.function=public>
```

**C++ Implementation:**
```cpp
static ani_int getRecordCount(ani_env* env, ani_object object, ani_int a);
```

**Binding Code:**
```cpp
std::array methods = {
    ani_native_function {
        "getRecordCount",
        "i:i",
        reinterpret_cast<void*>(getRecordCount)
    },
};
env->Class_BindNativeMethods(cls, methods.data(), methods.size());
```

> Use `reinterpret_cast<void*>` to erase type of native function.

---

### 1.1.3 Binding Functions in a Namespace

**ArkTS Code:**
```ts
namespace PasteData {
    loadLibrary("libraryName")
    native function getRecordCount(a: int): int;
}
```

**Disassembled ABC:**
```ts
.function i32 example.PasteData.getRecordCount(i32 a0) <native, static, access.function=public>
```

**C++ Implementation:**
```cpp
static ani_int getRecordCount(ani_env* env, ani_int a);
```

**Binding Code:**
```cpp
std::array methods = {
    ani_native_function {
        "getRecordCount",
        "i:i",
        reinterpret_cast<void*>(getRecordCount)
    },
};
env->Namespace_BindNativeFunctions(ns, methods.data(), methods.size());
```

> **Important:** Native functions for namespaces and modules include only `ani_env*` additional argument. Do not add extra arguments like `ani_object` or `ani_class`.

---

### 1.1.4 Binding Functions in a Module

**ArkTS Code:**
```ts
loadLibrary("libraryName")

enum COLORINT { REDINT = 5 }
native function processEnumInt(color: COLORINT): void;
```

**Disassembled ABC:**
```ts
.function void example.ETSGLOBAL.processEnumInt(example.COLORINT a0) <native, static, access.function=public>
```

**C++ Implementation:**
```cpp
static void processEnumInt(ani_env* env, ani_enum_item enumItem);
```

**Binding Code:**
```cpp
ani_module module;
env->FindModule("example", &module);

std::array functions = {
    ani_native_function {
        "processEnumInt",
        "E{example.COLORINT}:",
        reinterpret_cast<void*>(processEnumInt)
    },
};
env->Module_BindNativeFunctions(module, methods.data(), methods.size());
```

> **Important:** Module records can be found only by `FindModule`. Module functions must be bound using `Module_BindNativeFunctions`.

---

### 1.1.5 Special Scenarios in Function Binding

- **Overloaded functions:** In case of overloaded native functions, you must bind each variant explicitly:

```ts
native function foo(): void
native function foo(arg: string): void
```

will require to bind both functions:

```cpp
std::array functions = {
    ani_native_function {
        "foo",
        ":",
        reinterpret_cast<void*>(foo)
    },
    ani_native_function {
        "foo",
        "C{std.core.String}:",
        reinterpret_cast<void*>(fooString)
    },
};
```

- Optional parameters **do not** create overloads:

```ts
function foo(a: int, b: int = 3): void
```

will be compiled as a single function in bytecode:

```ts
.function void example.foo(i32 a0, std.core.Int a1)
```

---

### 1.1.6 Disassembling ABC Files

To disassemble `.abc` files, use `ark_disasm` binary, which is built during regular project builds of the following repositories:
- [`arkcompiler_runtime_core`](https://gitee.com/openharmony/arkcompiler_runtime_core/tree/OpenHarmony_feature_20250328/)
- [`arkcompiler_ets_frontend`](https://gitee.com/openharmony/arkcompiler_ets_frontend/tree/OpenHarmony_feature_20250328/)

**Build Instructions:** [Follow this guide](https://gitee.com/JianfeiLee/arkcompiler_runtime_core/wikis/下载和编译运行ArkTS演进版本代码)

**Usage:**

```bash
./out/bin/ark_disasm yourabcfile.abc dumpfile.txt
```

> If disassembly fails, check for version mismatches between tools and runtime.

### 1.2 Class Loading Failure Diagnostics

`FindClass` method might fail with `ANI_PENDING_ERROR` being returned, indicating an error thrown during loading of class. This situation usually occurs due to broken or incompatible ABC files being used:
* Older ABC files are used with newer `etsstdlib.abc`
* New version of runtime includes incompatible changes requiring recompilation of managed code.

Commonly `LinkerUnresolvedClassError` is thrown, which can be visible in managed stack trace as:
```ts
at std.core.LinkerUnresolvedClassError.<ctor> (<unknown>:36)
```

Whole hierarchy of errors which can be thrown during class loading can be found in [RuntimeLinkerErrors.ets](https://gitee.com/openharmony/arkcompiler_runtime_core/blob/OpenHarmony_feature_20250328/static_core/plugins/ets/stdlib/std/core/RuntimeLinkerErrors.ets).

#### 1.2.1 LinkerUnresolvedClassError Troubleshooting
---
##### 1.2.1.1 Incorrect `loadLibrary` Usage

ArkTS uses lazy initialization of modules and classes. In practice it means that static blocks and top-level statements are executed only before first access to entities defined as part of the class or module. Consider the following example:

```ts
loadLibrary("libraryName")

// The only exported entity from module
export function foo(): void {
    fooImpl(12)
}

native function fooImpl(arg: int): void
```

Here `loadLibrary` is added as top-level statement, hence it will be executed before first call to `foo` or `fooImpl`.

##### 1.2.1.2 Device Missing ABC Loading

1. Check the program’s process to determine whether the ABC module was loaded during execution. If not, proceed to step 2:
```
cat /proc/pid/maps | grep abc
```

2. Check if the required ABC module exists under the `/system/framework` path. If it does, go to step 3.

3. Check whether the required ABC module loading path is present in `/system/framework/bootpath.json`. If not, add the path:
```
hdc file recv /system/framework/bootpath.json ./
hdc file send bootpath.json /system/framework/bootpath.json
```

> **Important:** Modifying this file requires rebooting the device!

4. If `bootpath.json` lacks the ABC module loading path, it may be due to missing configuration during module packaging. Add `is_boot_abc="True"` in `build.gn` under `generate_abc`.

----

## 2. Mangling Rules

_Mangling_ denotes to method of encoding function signatures, which is used to distinguish functions overloads. The format is:

```
<parameter_types>:<return_type>
```

### Examples

- `toInt(num: number): int` → `d:i`
- `toInt(str: string): int` → `C{std.core.String}:i`

Use:

```cpp
Object_CallMethodByName_Int(obj, "toInt", "d:i", &result);
Object_CallMethodByName_Int(obj, "toInt", "C{std.core.String}:i", &result);
```

---

### Type Mangling Reference

| ArkTS Type | Mangling Code  |   ANI Type    |
|------------|----------------|---------------|
| `boolean`  | `z`            | `ani_boolean` |
| `byte`     | `b`            | `ani_byte`    |
| `char`     | `c`            | `ani_char`    |
| `short`    | `s`            | `ani_short`   |
| `int`      | `i`            | `ani_int`     |
| `long`     | `l`            | `ani_long`    |
| `float`    | `f`            | `ani_float`   |
| `double`   | `d`            | `ani_double`  |
| `number`   | `d`            | `ani_double`  |

Note that `number` is alias to `double` in ArkTS.

#### Object Types

| ArkTS Class Type            | Mangling                    | Notes                                                             |
|-----------------------------|-----------------------------|-------------------------------------------------------------------|
| `class CustomCls`           | `C{example.CustomCls}`      | Leading `C`, dots for path                                        |
| `interface CustomIface`     | `C{example.CustomIface}`    | Leading `C`, dots for path                                        |
| `string`                    | `C{std.core.String}`        | Standard library type                                             |
| `bigint`                    | `C{escompat.BigInt}`        | Standard library type from `escompat` package                     |
| `Array`                     | `C{escompat.Array}`         | Standard library type from `escompat` package                     |
| `()=>void`                  | `C{std.core.Function0}`     | Function objects by required arguments count                      |
| `(...args: double[])=>void` | `C{std.core.FunctionR0}`    | Function objects with rest parameters by required arguments count |

#### Array Types

According to `3.16.1 Resizable Array Types` chapter of ArkTS specification, both `T[]` and `Array<T>` specify identical types.
Hence they are lowered identically into `C{escompat.Array}`:

```ts
function foo(a: string[], b: Array<Int>): void  // "C{escompat.Array}C{escompat.Array}:"
```

#### Fixed Array Types

| ArkTS Array                   |       Mangling          |
|-------------------------------|-------------------------|
| `FixedArray<int>`             | `A{i}`                  |
| `FixedArray<FixedArray<int>>` | `A{A{i}}`               |
| `FixedArray<String>`          | `A{C{std.core.String}}` |

#### Special Types

| Special Value  | Mangling              |        Notes         |
|----------------|-----------------------|----------------------|
| `null`         | `C{std.core.Object}`  | Use `GetNull()`      |
| `undefined`    | `C{std.core.Object}`  | Use `GetUndefined()` |

---

### Key Mangling Rules

1. **Separate Parameters and Return Types**
   - Use `:` to separate arguments from return type, e.g., `dd:i` (two doubles, returns int).

2. **Void Return with No Parameters**
   - No parameters: `:`
   - Parameters can be omitted if none, but return type is required.

3. **Object Format**
   - Format: `C{<module>.<Class>}`
   - Default module name is the file name if not explicitly declared.

4. **Array Format**
   - One-dimensional: `A{ElementType}`.
   - Multi-dimensional: add `A` nesting for each dimension, e.g., `A{A{I}}`.

5. **Generics Types**
   - Mapped to type constraint. Default type constraint is `Object | null | undefined`, which have `C{std.core.Object}` corresponding in signature.
   - Do not affect mangling directly.

6. **Union Types**
   - Mapped to _Least Upper Bound_ type:

```ts
function foo(a: string | number): void // "C{std.core.Object}:"
interface I {}
class C implements I {}
function foo(a: C | I): void    // "C{hello_ani.I}:"
```

7. **Optional Parameters (Boxing)**
  - Optional primitives become boxed objects:
    - `arg?: int` → `C{std.core.Int}`
    - `arg?: double` → `C{std.core.Double}`
  - Non-primitive optional types remain unchanged

8. **Functions as Parameters**
   - Use `C{std.core.FunctionN}`, where `N` is the argument count
   - Use `C{std.core.FunctionRN}`, where `R` denotes that function has rest parameters

---

### Example Mangled Signatures

```ts
class A {/*...*/}
class B {/*...*/}
namespace NS {
    class C {/*...*/}
}

function f(): void // Mangling ":"
function f(a: int): void // Mangling "i:"
function f(a: int, b: int): void // Mangling "ii:"
function f(a: number, b: double): int // Mangling "dd:i"

function f(a: Array<string>): void // Mangling "C{escompat.Array}:"
function f(a: string[]): void // Mangling "C{escompat.Array}:"

// Mangling "zbC{std.core.String}C{hello_ani.A}C{std.core.Object}C{hello_ani.B}:"
function f<T extends B>(a: boolean, b: byte, c: string, d: A, f: A | B, e: T): void

// Mangling "iC{std.core.Int}C{std.core.String}C{hello_ani.A}:"
function f(a: int, b?: int, c?: string, d?: A): void
// Mangling "A{i}A{C{std/core/String}}A{i}:C{std.core.Object}"
function f(a: int[], b: string[], ...c: int[]): string | boolean
// Mangling "C{std.core.Function0}C{std.core.Function0}C{std.core.FunctionR1}:"
function f(a: () => void, b: () => string, c: (x: int, ...y: int[]) => string): void
```

---

## 3 Type Definitions

### 3.1 Native Types / Primitive Types

```cpp
// Runtime types for ArkTS primitive types
typedef uint8_t  ani_boolean;  // Boolean (1 byte)     ArkTS declaration: boolean
typedef uint16_t ani_char;     // Character (2 bytes)  ArkTS declaration: char
typedef int8_t   ani_byte;     // Byte (1 byte)        ArkTS declaration: byte
typedef int16_t  ani_short;    // Short (2 bytes)      ArkTS declaration: short
typedef int32_t  ani_int;      // Integer (4 bytes)    ArkTS declaration: int
typedef int64_t  ani_long;     // Long (8 bytes)       ArkTS declaration: long
typedef float    ani_float;    // Float                ArkTS declaration: float
typedef double   ani_double;   // Double               ArkTS declaration: double/number
```

`number` is an alias for the `double` type.

> Since `ani_boolean` is `uint8_t` instead of `bool`, it cannot be directly printed using `cout` or other C++ stream APIs. You need to cast it to `int` before outputting.

### 3.2 Extended Types

| Type Definition     | Description               | Notes                                           |
| ------------------- | ------------------------- | ----------------------------------------------- |
| `ani_ref`           | Base type of `ani_object` |                                                 |
| `ani_object`        | Any non-primitive type    | Does not include primitive types like `ani_int` |
| `ani_error`         | `Error`                   |                                                 |
| `ani_fn_object`     | `Function/()=>void`       |                                                 |
| `ani_arraybuffer`   | `ArrayBuffer`             |                                                 |
| `ani_string`        | `string`                  |                                                 |
| `ani_fixedarray`    | `FixedArray<T>`           | Base type for all fixed arrays                  |
| `ani_array`         | `T[]`                     | The same as `Array<T>`                          |

If a function parameter expects `ani_ref` or `ani_object`, and you need to pass a value of `ani_int` type, you need to box it to `ani_ref`. See section [4.1](#41-boxing--unboxing).

### 3.3 Type Casting

Types on the following inheritance chain can be cast using `static_cast` if they have a parent-child relationship. Types outside this chain cannot be cast to `ani_ref` or `ani_object`. A typical example: `ani_method`.

However, such casting must ensure the availability of the type on the ArkTS runtime layer. For example, converting to `ani_ref` and attempting to use `ani_string` as an `ani_array` will cause a runtime crash.
```
ani_ref
├── ani_module
├── ani_namespace
├── ani_object
│   ├── ani_fn_object
│   ├── ani_enum_item
│   ├── ani_error
│   ├── ani_tuple_value
│   ├── ani_type
│   │   ├── ani_class
│   │   ├── ani_enum
│   │   └── ani_union
│   ├── ani_arraybuffer
│   ├── ani_string
│   ├── ani_array
│   └── ani_fixedarray
│       ├── ani_fixedarray_boolean
│       ├── ani_fixedarray_char
│       ├── ani_fixedarray_byte
│       ├── ani_fixedarray_short
│       ├── ani_fixedarray_int
│       ├── ani_fixedarray_long
│       ├── ani_fixedarray_float
│       ├── ani_fixedarray_double
│       └── ani_fixedarray_ref
```
e.g. `auto str = static_cast<ani_string>(string_ref);`

- How to convert `ani_int` / `ani_double` and other primitive types to `ani_ref`?

Refer to [Section 4.1](#41-boxing--unboxing). "Boxing" for the procedure.

### 3.4 Type Identification: Object_InstanceOf

`ani_object` in parameters represents all types. If a union type parameter like `A | B` exists, `Object_InstanceOf` must be used to identify the actual type.

```ts
type DataType = string | ArrayBuffer | FixedArray<int> | FixedArray<string>
native function handleData(data: DataType): void  

function main(){
    loadLibrary("libraryName")
    handleData("hello")                 // Will output "Object is String; content: hello"
    handleData(new ArrayBuffer(1024))   // Will output "Object is ArrayBuffer; length: 1024"
    handleData(new FixedArray<int>())   // Will output "Object is FixedArray"
}
```

```cpp
static void HandleDataImpl(ani_env *env, ani_object union_obj) {
    // Note: in production code it might be worth to cache the classes via `GlobalReference_Create`
    ani_class stringClass {};
    env->FindClass("std.core.String", &stringClass);
    
    ani_class arrayBufferClass {};
    env->FindClass("escompat.ArrayBuffer", &arrayBufferClass);

    ani_class fixedArrayIntClass {};
    env->FindClass("A{i}", &fixedArrayIntClass);

    ani_class fixedArrayStringClass {};
    env->FindClass("A{C{std.core.String}}", &fixedArrayStringClass);

    ani_boolean isString = ANI_FALSE;
    env->Object_InstanceOf(union_obj, stringClass, &isString);
    if (isString) {
        auto stringContent = ANIUtils_ANIStringToStdString(env, static_cast<ani_string>(union_obj));
        std::cout << "Object is String; content: " << stringContent.c_str() << std::endl;
        return;
    }

    ani_boolean isArrayBuffer = ANI_FALSE;
    env->Object_InstanceOf(union_obj, arrayBufferClass, &isArrayBuffer);
    if (isArrayBuffer) {
        ani_int length;
        env->Object_CallMethodByName_Int(union_obj, "getByteLength", nullptr, &length);
        std::cout << "Object is ArrayBuffer; length: " << length << std::endl;
        return; 
    }

    ani_boolean isIntArray = ANI_FALSE;
    env->Object_InstanceOf(union_obj, fixedArrayIntClass, &isIntArray);
    ani_boolean isStringArray = ANI_FALSE;
    env->Object_InstanceOf(union_obj, fixedArrayStringClass, &isStringArray);
    assert(isIntArray || isStringArray);
    std::cout << "Object is FixedArray" << std::endl;
    return;
}
```

## 4 Parameter Handling

### 4.1 Primitive Types

- From language point of view, ArkTS contains only boxed versions of primitive types.
- From runtime point of view, primitive types are used as optimization when primitive is specified as non-generic and non-union argument, return or field type.

#### 4.1.1 Boxed Types

| ANI Primitive Type | Boxed Class | Mangling              | binding/ANI Type | Notes               |
| ------------------ | ----------- | --------------------- | ---------------- | ------------------- |
|   `ani_boolean`    | `Boolean`   | `C{std.core.Boolean}` | `ani_object`     | Boxed boolean       |
|   `ani_byte`       | `Byte`      | `C{std.core.Byte}`    | `ani_object`     | Boxed byte          |
|   `ani_char`       | `Char`      | `C{std.core.Char}`    | `ani_object`     | Boxed char          |
|   `ani_short`      | `Short`     | `C{std.core.Short}`   | `ani_object`     | Boxed short         |
|   `ani_int`        | `Int`       | `C{std.core.Int}`     | `ani_object`     | Boxed int           |
|   `ani_long`       | `Long`      | `C{std.core.Long}`    | `ani_object`     | Boxed long          |
|   `ani_float`      | `Float`     | `C{std.core.Float}`   | `ani_object`     | Boxed float         |
|   `ani_double`     | `Double`    | `C{std.core.Double}`  | `ani_object`     | Boxed double        |
|   `ani_number`     | `Double`    | `C{std.core.Double}`  | `ani_object`     | Alias of double     |
|         -          | `Void`      | `C{std.core.Void}`    | `ani_object`     | Usually meaningless |

You can refer to [Section 5.1](#51-querying-methods-of-standard-classes) to query methods of these boxed types and their corresponding modules.

If the function parameter's mangling is `C{std.core.Object}`, it only accepts class instances. For example, `Array<T>` method `$_set(i: int, val: T): void` has mangling `iC{std.core.Object}:`, where the second argument must be a class instance.

In such cases, primitive values (like `int` or `double`) need to be boxed (into `Int` or `Double`). According to Section 3.3, the resulting `ani_object` can also be converted to `ani_ref` to fulfill function requirements.

Similarly, `A{C{std.core.Object}}` denotes a fixed array of class instances.

#### 4.1.2 Boxing

Purpose:
1. Satisfy function parameter type requirements.
2. Convert primitive values to class instances (e.g., `ani_int` to `ani_ref`).

In managed code, boxing happens automatically for optional parameters. Omitting an optional primitive value defaults to `undefined`. In native code, parameter must be passed explicitly.

- Create a boxed object:
```cpp
ani_ref createDouble(ani_env *env)
{
    // Note: in production code it might be worth to cache the class via `GlobalReference_Create`
    static constexpr const char *className = "std.core.Double";
    ani_class doubleCls {};
    env->FindClass(className, &doubleCls);
    ani_method ctor {};
    env->Class_FindMethod(doubleCls, "<ctor>", "d:", &ctor);
    ani_object obj {};
    if (env->Object_New(doubleCls, ctor, &obj, static_cast<ani_double>(2.0)) != ANI_OK) {
        std::cerr << "Failed to allocate Double!" << std::endl;
        ani_ref undefinedRef;
        env->GetUndefined(&undefinedRef);
        return undefinedRef;
    }
    return obj;
}
```

You can choose the desired constructor overload and specify it with `signature` parameter of `Class_FindMethod`.

#### 4.1.3 Unboxing

Use `unboxed` to extract the primitive value:
```cpp
Object_CallMethodByName_Double(boxed_double_obj, "unboxed", ":d", &unboxed_value)
```

`Double` is determined by the return type of the boxed object. Mangling `:d` means it returns a `double`.

**Example:**

```ts
function handleData(param: Double): void
```

```cpp
void HandleDataImpl(ani_env *env, ani_object param)
{
    ani_double value = 0;
    env->Object_CallMethodByName_Double(param, "unboxed", ":d", &value);
    std::cout << "Value: " << value << std::endl;
}
```

### 4.2 Generic Parameters

- With exception of `FixedArray`, all generic types are erased in runtime.
- In bytecode type parameters are compiled as their type constraint.
- Default type constraint is `Object | null | undefined`.
- Primitive types are always boxed when used as type parameters.

| ArkTS Type           | Example           | Mangling                                | binding/ANI Type     | Notes                               |
| -------------------- | ----------------- | --------------------------------------- | -------------------- | ----------------------------------- |
| `(a: T, b: R): void` | `f(1, "str")`     | `C{std.core.Object}C{std.core.Object}:` | `ani_object`         |                                     |
| `Array<T>`           | `Array<int>`      | `C{escompat.Array}`                     | `ani_object`         |                                     |
| `FixedArray<T>`      | `FixedArray<int>` | `A{i}`                                  | `ani_fixedarray_int` | Reified (non-erased) type parameter |

### 4.3 Union Types

Union types are compiled as _least upper bound_ of components, to which `ani_object` corresponds in ANI. Most commonly the type will be `C{std.core.Object}`, though it's not true in general:

```ts
interface I {}
class C implements I {}
function foo(arg: C | I): void  // Signature: "C{some_module.I}:"
```

> Optional parameter `arg?: T` always equals to `arg: T | undefined`, see ArkTS specification chapter `4.8.4 Optional Parameters`.

As union are represented with references, primitive values must be boxed to be used as part of union.

| ArkTS Type           | Mangling             | binding/ANI Type | Notes                  |
| -------------------- | -------------------- | ---------------- | ---------------------- |
| `a: double | string` | `C{std.core.Object}` | `ani_object`     | Primitives need boxing |

**Handling Arguments**:

Use `Object_InstanceOf` to determine the actual type of the argument and handle accordingly. See [3.4 Type Identification: Object_InstanceOf](#3.4-Type-Identification:-Object_InstanceOf)

### 4.4 Optional Parameters

**Mangling**:
1. Primitive types like `int`, `double` are boxed to `Int`, `Double`, etc.
2. Non-primitives retain their original mangling.
3. All optional parameters are considered union types with `undefined` (see ArkTS specification chapter `4.8.4 Optional Parameters`).
4. Overloaded constructors exist in the `.abc` file for functions with optional parameters.

| ArkTS Type          | Mangling               | Binding / ANI Type |    Notes   |
| ------------------- | ---------------------- | ------------------ | ---------- |
| `a: int`            | `i`                    | `ani_int`          |            |
| `a?: int`           | `C{std.core.Int}`      | `ani_object`       | Boxed      |
| `a: Int`            | `C{std.core.Int}`      | `ani_object`       |            |
| `a?: Int`           | `C{std.core.Int}`      | `ani_object`       |            |
| `a?: customCls`     | `C{example.CustomCls}` | `ani_object`       |            |
| `a?: string \| int` | `C{std.core.Object}`   | `ani_object`       | Union type |

**Argument Handling**:

If argument is a union with `undefined` type included, you must check whether it is `undefined` before accessing it in native code:

```cpp
static void CallMeWithOptionalDouble(ani_env *env, ani_object doubleObject)
{
    ani_boolean isUndefined;
    env->Reference_IsUndefined(doubleObject, &isUndefined);
    if (isUndefined) {
        std::cout << "CallMeWithOptionalDouble NOT passed value " << std::endl;
    } else {
        ani_double result;
        env->Object_CallMethodByName_Double(doubleObject, "unboxed", ":d", &result);
        std::cout << "CallMeWithOptionalDouble passed value: " <<  result << std::endl;
    }
}
```

### 4.5 Default Parameters

Similar to optional parameter cases:
1. Primitive types are automatically boxed.
2. Non-primitives retain original mangling.

```ts
// Signature: "zC{std.core.Boolean}:"
function foo(a: boolean, b: boolean = false): void {}
```

### 4.6 Variadic / Rest Parameters

Variadic arguments are syntactic sugar in ArkTS that collect arguments into an array.

```ts
// Signature: "iA{i}:"
function foo(a: int, ...b: int[]): void
```

## 5 Object Creation

### 5.1 Querying Methods of Standard Classes

Check the required standard library functions from [stdlib](https://gitee.com/openharmony/arkcompiler_runtime_core/blob/OpenHarmony_feature_20250328/static_core/plugins/ets/stdlib/). If you're unsure which class to query, disassemble the `etsstdlib.abc` to confirm name of class and compiled signatures.

**Example: ArrayBuffer**

Locate [ArrayBuffer.ets](https://gitee.com/openharmony/arkcompiler_runtime_core/tree/OpenHarmony_feature_20250328/static_core/plugins/ets/stdlib/escompat/ArrayBuffer.ets) and `constructor` defined in the class.
Code snippet:
```ts
export class ArrayBuffer extends Buffer
{
    public constructor(length: int, maxByteLength?: int)
    public constructor(length: number, maxByteLength?: number)
    public static isView(obj: Object): boolean
    get byteLength(): number 
}
```

From the above snippet, we can find:
1. Two constructors. The function name for ANI recognition is `<ctor>`. The mangling for the first constructor could be written as `iC{std.core.Int}:`. **Do not use `nullptr` in place of constructor signature** - overloaded methods should be resolved by signature.
2. Method named `isView` with parameter `Object` and return type `boolean` has mangled signature `C{std.core.Object}:z`
3. A `byteLength` property

### 5.2 Querying Methods of Non-standard Classes

Typical example here is enums, which are supported by frontend generating special classes during compilation.
Methods and fields generated in these classes are implementation-defined, hence it is not recommended to access them directly.
Instead, special ANI functions exist to support enums, e.g. `Enum_GetEnumItemByName` or `EnumItem_GetValue_String`.

### 5.3 Creating Class Instances

1. Use `FindClass` to locate the class.
2. Use `Class_FindMethod` to find the desired constructor using the proper mangling.
3. Use one of `Object_New` functions to instantiate the object.

**Example:**

```ts
// filename: example.ets
// moduleName: example
// By default, module name equals file name

class Point {
    x: int
    y: int
    constructor(x: int, y: int) {
        this.x = x; this.y = y;
    }
    constructor(x: number, y: number) {
        this.x = x as int; this.y = y as int;
    }
}
```

1. FindClass:
```cpp
ani_class cls {};
env->FindClass("example.Point", &cls);
```

2. Class_FindMethod:
```cpp
ani_method ctor1 {};
env->Class_FindMethod(cls, "<ctor>", "ii:", &ctor1);
ani_method ctor2 {};
env->Class_FindMethod(cls, "<ctor>", "dd:", &ctor2);
```

- Mangling `ii:` matches `constructor(x: int, y: int)`  
- Mangling `dd:` matches `constructor(x: double, y: double)`

**Never use nullptr in place of constructor signature.** Doing so will make native code error-prone, because it might unexpectedly break when new overloads are added into managed code. 

3. Object_New:
```cpp
ani_object obj1 {};
env->Object_New(cls, ctor1, &obj1, static_cast<ani_int>(1), static_cast<ani_int>(2));
ani_object obj2 {};
env->Object_New(cls, ctor2, &obj2, static_cast<ani_double>(1), static_cast<ani_double>(2));
```

Here,
- `obj1` is created using `constructor(x: int, y: int)`
- `obj2` is created using `constructor(x: double, y: double)`

**Creating Instances of ArkTS Standard Library Classes**
1. `FindClass`: Locate the class under `arkcompiler/runtime_core/static_core/plugins/ets/stdlib`. The file will declare the package, usually `std.core` or `escompat`, and the mangling will be `std.core.<ClassName>` or `escompat.<ClassName>`
2. `Class_FindMethod`: Identify the target constructor by its mangling.
3. `Object_New`: Call this function to create an instance.

> **Note**: The following types **cannot** be created using `Object_New` in ANI:
- Interface types
- Abstract classes
- String (`ani_string`) — must use dedicated ANI creation functions
- `FixedArray<T>` types — must use dedicated ANI array creation functions

## 6 Interfaces and classes

Interfaces cannot be directly instantiated in ANI. You must implement them in a class (class implements interface) before they can be instantiated.

All fields in interfaces are automatically treated as properties. When a class implements an interface, the inherited members also become properties.
```ts
interface PointI {
    x: int // property - getter and setter will be generated for it
    y: int // property - getter and setter will be generated for it
}
class Point implements PointI {
    x: int // property - getter and setter will be generated for it
    y: int // property - getter and setter will be generated for it
    z: int // field - no getters or setters by default
}
```

```cpp
ani_class clsPointI; ani_method ctorPointI; // assume initialized
ani_class clsPoint; ani_method ctorPoint;   // assume initialized
ani_object objPointI; ani_object objPoint;
env->Object_New(clsPointI, ctorPointI, &objPointI); // fail
env->Object_New(clsPoint, ctorPoint, &objPoint);    // success
```

- Creating interface objects fails.  
- Creating class objects succeeds.

In ANI, class creation does not depend on interfaces, but interface objects require class implementations.
In managed ArkTS code, interface objects can be created via _object literal_ expression:

```ts
let p: PointI = { x: 1, y: 1 };
```

Frontend will automatically generate class implementing `PointI` interface.
However, objects of this class can be accessed using getters and setters, which are generated automatically for the interface.

### 6.1 property & field

- **Property**: Declared with `get/set` methods
- **Field**: Attributes without `get/set` methods
- All properties in an interface become properties in the implementing class.

> **Note:** `Class_FindField` cannot be used for properties which are not backed by a field

```ts
interface PointI {
    x: int // property
    y: int // property
}

class Point implements PointI {
    x: int // property
    y: int // property
    z: int // field
}
```

### 6.2 Accessing Properties

#### 6.2.1 Accessing and Setting Properties

| Function Name                  | Action | Description                      |
| ------------------------------ | ------ | -------------------------------- |
| `Object_GetPropertyByName_XXX` | get    | Retrieve property as a primitive |
| `Object_SetPropertyByName_XXX` | set    | Set property using a primitive   |

**Example:**

```ts
interface Person {
    name: string;
    age: int;
}

class PersonInner implements Person {
    name: string = "";
    age: int = 2;
}

native function modifyPerson(person: Person): void
```

```cpp
void ModifyPersonImpl(ani_env *env, ani_object person)
{
    static constexpr std::string_view name = "Goose";
    ani_string nameValue {};
    env->String_NewUTF8(name.data(), name.size(), &nameValue);
    ani_int ageValue = 42;

    env->Object_SetPropertyByName_Int(person_obj, "age", ageValue);
    env->Object_SetPropertyByName_Ref(person_obj, "name", nameValue);

    ani_int ageValueRet = 0;
    ani_ref nameValueRet {};
    env->Object_GetPropertyByName_Int(person_obj, "age", &ageValueRet);
    env->Object_GetPropertyByName_Ref(person_obj, "name", &nameValueRet);
}
```

#### 6.2.2 Accessing and Setting Fields

| Function Name                   | Action | Description                     |
| ------------------------------ | ------ | ------------------------------- |
| `Object_GetFieldByName_<Type>`    | get    | Retrieve field as a primitive  |
| `Object_SetFieldByName_<Type>`    | set    | Set field using a primitive    |

**Example:**

```ts
class Person {
    name: string = "";
    age: int = 2;
    thisIsField: int = 3;
}

native function modifyPerson(person: Person): void
```

```cpp
void ModifyPersonImpl(ani_env *env, ani_object person)
{
    static constexpr std::string_view name = "Goose";
    ani_string nameValue {};
    env->String_NewUTF8(name.data(), name.size(), &nameValue);
    ani_int ageValue = 42;

    env->Object_SetFieldByName_Int(person_obj, "age", ageValue);
    env->Object_SetFieldByName_Ref(person_obj, "name", nameValue);

    ani_int ageValueRet = 0;
    ani_ref nameStringRet {};
    env->Object_GetFieldByName_Int(person_obj, "age", &ageValueRet);
    env->Object_GetFieldByName_Ref(person_obj, "name", &nameStringRet);
}
```

#### 6.2.3 Accessing Static Fields

| Function Name                    | Action | Description                 |
| -------------------------------- | ------ | --------------------------- |
| `Class_GetStaticFieldByName_<Type>` | get    | Retrieve static field value |
| `Class_SetStaticFieldByName_<Type>` | set    | Set static field value      |

### 6.3 Calling Methods

Use `Object_CallMethod_<Type>` where XXX indicates the return type.

**Example:**

```ts
// example.ets
class Foo {
    native nativeFunc(): void;
    managedFunc(): void {
        console.println("Print in managedFunc");
    }
}
```

```cpp
static void NativeFuncImpl(ani_env *env, ani_object obj) {
    ani_method managedFunc {};
    ani_type result {};

    static constexpr const char *className = "example.Foo";
    ani_class cls {};
    if (ANI_OK != env->FindClass(className, &cls)) {
        std::cerr << "Not found '" << className << "'" << std::endl;
        return;
    }
    if (ANI_OK != env->Class_FindMethod(cls, "managedFunc", ":", &managedFunc)) {
        std::cerr << "Class_FindMethod Failed" << std::endl;
        return;
    }
    std::cout << "Print in Native Func" << std::endl;
    env->Object_CallMethod_Void(obj, managedFunc);
}
```

### 6.4 Optional Methods as Optional Parameters

ArkTS does not support optional methods directly. Instead, optional function parameters can be used.

**Example:**

```ts
// example.ets
class OptionalClass {
    fn?: (a: double, b: double) => double = (a: double, b: double) => a + b;
}
native function callOptionalFn(opt: OptionalClass, a: double, b: double): double

let opt = new OptionalClass();
console.log(opt.fn1(1.0, 2.0));
console.log(callOptionalFn(opt, 1.0, 2.0));
```

```cpp
ani_double CallOptionalFnImpl(ani_env *env, ani_object opt, ani_double val1, ani_double val2)
{
    ani_ref fnRef {};
    env->Object_GetFieldByName_Ref(opt, "fn", &fnRef);

    // Note: functional objects always accept and return boxed primitives
    std::array<ani_ref, 2> args = {createDouble(env, val1), createDouble(env, val2)};
    ani_ref fnReturnVal {};
    env->FunctionalObject_Call(static_cast<ani_fn_object>(fnRef), args.size(), args.data(), &fnReturnVal);

    ani_double result {};
    env->Object_CallMethodByName_Double(static_cast<ani_object>(fnReturnVal), "unboxed", ":d", &result);
    return result;
}
```

### 6.5 wrap & unwrap

Example: [ani_wrap_native_ptr.ets](https://gitee.com/ironrain/ani_cookbook/blob/master/ani_wrap_native_ptr/ani_wrap_native_ptr.ets)

## 7 Callback Function / Lambda Function Objects

Function object and callback example:  
[ani_fn_object/ani_fn_object.ets · ironrain/ani_cookbook](https://gitee.com/ironrain/ani_cookbook/blob/master/ani_fn_object/ani_fn_object.ets)

```cpp
ani_status FunctionalObject_Call(ani_env *env, ani_fn_object fn, ani_size argc, ani_ref *argv, ani_ref *result)
```

This function expects the arguments to be passed as an array of `ani_ref`.  
Note that functional objects always accept and return boxed primitives. It means that if the arguments are primitive types such as `int` or `double`, they need to be converted into boxed types (`Int`, `Double`, etc.), then stored in an array and passed as a pointer.

**Example:**

```cpp
ani_object CreateDouble(ani_double doubleVal) { ... } // returns a Double instance, see Section 4.1.2 for implementation
```

```cpp
std::vector<ani_ref> vec;
vec.push_back(CreateDouble(ani_double(2)));
vec.push_back(CreateDouble(ani_double(4)));

ani_ref result {};
env->FunctionalObject_Call(show_every, vec.size(), vec.data(), &result);
```

## 8 Asynchronous Execution

Asynchronous example:  
[ani_async_wrapper/ani_async_wrapper.ets · ironrain/ani_cookbook](https://gitee.com/ironrain/ani_cookbook/blob/master/ani_async_wrapper/ani_async_wrapper.ets)

> [! Warning] **Potential Issue**
> Throwing an exception inside an asynchronous context may cause the program to freeze and not terminate properly.
> If an execution timeout is configured, it may eventually crash automatically.
> Try appending `.catch` after `.then` and rejecting the object to see if that resolves the issue.


## 9 Lifecycle Management

### 9.1 References Lifecycle

All objects created on the C++ native side are _local references_. It means that they are invalidated once they leave their scope, and even if stored in a global C++ object, they may still be reclaimed.
**The following example shows possible error when local reference is saved in a global native variable:**

```cpp
ani_object g_obj;
void NativeFuncImpl(ani_env* env, ani_object param) {
    ani_object newObj {};
    if (env->Object_New(cls, ctor, &newObj) != ANI_OK) {
        std::cerr << "Failed to create object" << std::endl;
        return;
    }
    g_obj = newObj; // Local reference leakage, will cause UB
}
```

For creating global references which will live between calls to native functions you can use `GlobalReference_Create`:

```cpp
ani_object g_obj;
void OnEnterImpl(ani_env *env, ani_object param) {
    ani_object newObj {};
    if (env->Object_New(cls, ctor, &newObj) != ANI_OK) {
        std::cerr << "Failed to create object" << std::endl;
        return;
    }
    if (env->GlobalReference_Create(newObj, &g_obj) != ANI_OK) {
        std::cerr << "Failed to create global reference" << std::endl;
    }
}
void OnExitImpl(ani_env *env) {
    env->GlobalReference_Delete(g_obj);
}
```

**Notes:**
- `ani_ref` returned by `GlobalReference_Create` is considered the same as the original object.
- You must use `GlobalReference_Delete` to remove the previously created global references and prevent memory exhaustions.

### 9.2 VM and env Lifecycle

- `ani_vm` is created at app startup and lives as long as the app does.
- Each `ani_env` is tied to a coroutine in one-to-one relationship. It is guaranteed that `ani_env` is valid during native function call.

**An `ani_env` can only be used in the thread it was created in.**  
When the coroutine ends, the `ani_env` is destroyed and becomes a dangling pointer.
`
#### Possible Alternative: use `AttachCurrentThread`

From `env`, get the `vm`:
```cpp
ani_vm *vm = nullptr;
env->GetVM(&vm);
```

In another thread:

1. Call `AttachCurrentThread` to make thread managed:

```cpp
ani_env *env = nullptr;
ani_options aniArgs {0, nullptr};
auto status = vm_->AttachCurrentThread(&aniArgs, ANI_VERSION_1, &env);
// use `env` as regular
```

Or specify interop mode for the thread:

```cpp
ani_env *env {nullptr};
ani_option interopEnabled {"--interop=enable", nullptr};
ani_options aniArgs {1, &interopEnabled};
auto status = vm->AttachCurrentThread(&aniArgs, ANI_VERSION_1, &env);
// use `env` as regular with ability to call to JS
```

2. `GetEnv` if thread is already attached to VM:

```cpp
ani_env *env;
auto status = vm->GetEnv(ANI_VERSION_1, &env);
```

3. Detach the thread after everything was finished:

```cpp
env->DetachCurrentThread();
```

> Note that only threads which were previously attached via `AttachCurrentThread` can be detached.

## 10 Multithreading

ANI provides functions dedicated to `Promise` type management:
```cpp
ani_status Promise_New(ani_env *env, ani_resolver *result_resolver, ani_object *result_promise);
ani_status PromiseResolver_Resolve(ani_env *env, ani_resolver resolver, ani_ref resolution);
ani_status PromiseResolver_Reject(ani_env *env, ani_resolver resolver, ani_error rejection);
```

Aside from them, users have the following ways to use multithreading in their programs:
- Create native thread and call `AttachCurrentThread` in it to communicate with managed ArkTS.
- Use APIs provided by language - e.g. [taskpool](https://gitee.com/openharmony/arkcompiler_runtime_core/blob/OpenHarmony_feature_20250328/static_core/plugins/ets/stdlib/escompat/taskpool.ets).

**Note that `ani_env` cannot be used across threads**. Capturing `ani_env` in a lambda or thread function will lead to null pointer exceptions.
See Section 9 (Lifecycle Management) for important details.

### Key Advice

- When defining a lambda to be executed on another thread, **capture `ani_vm` instead of `ani_env`**.
- Refer to Section 9.2 for proper usage of `AttachCurrentThread` and `GetEnv`.

## 11 Variable-Length Arrays: Array<T> and T[]

Both `Array<T>` and `T[]` denote the identical type which is equal to `escompat.Array` class.
It can be either created and managed like any other regular object or operated with special functions like `Array_New` or `Array_Set`.
Note that generic type parameter which represents element type is erased, so there is only one `ani_array` type on ANI level.

**Example:**

```cpp
ani_array CreateEscompatArray(const std::vector<ani_double> &numbers)
{
    // Create Array<T>
    ani_array array;
    env->Array_New(numbers.size(), g_undefinedRef, &array);
    // Populate array
    ani_size index = 0;
    for (auto num : numbers) {
        ani_object boxedNumber;
        env->Object_New(doubleClass, doubleCtor, &boxedNumber, num);
        env->Array_Set(array, index, boxedNumber);
        index++;
    }
    return array;
}
```

## 12 Fixed-Length Arrays

Fixed arrays are special types for which element type is not erased - it means that `FixedArray<int>` and `FixedArray<double>` are incompatible types both in language and bytecode.
Creating and accessing fixed arrays can be done via `FixedArray_*` functions group. For example, the following APIs can be used for `FixedArray<double>`:

```cpp
ani_status FixedArray_New_Double(ani_env *env, ani_size length, ani_fixedarray_double *result);
ani_status FixedArray_GetRegion_Double(ani_env *env, ani_fixedarray_double array, ani_size offset, ani_size length, ani_double *native_buffer);
ani_status FixedArray_SetRegion_Double(ani_env *env, ani_fixedarray_double array, ani_size offset, ani_size length, const ani_double *native_buffer);
```

**Example:**

```cpp
ani_fixedarray_double CreateFixedArray(const std::vector<ani_double> &numbers)
{
    // Create Array<T>
    ani_fixedarray_double array;
    env->FixedArray_New_Double(numbers.size(), &array);
    // Populate array
    env->FixedArray_SetRegion_Double(array, 0, numbers.size(), numbers.data());
    return array;
}
```

## 13 ArrayBuffer

The `ArrayBuffer` type supports two main interfaces: `CreateArrayBuffer` and `ArrayBuffer_GetInfo`.

**Example:**

```ts
loadLibrary("libraryName");

native function handleData(buffer: ArrayBuffer): void

function main() {
    const buffer = new ArrayBuffer(4);
    const uint8View = new Uint8Array(buffer);

    uint8View[0] = 1;
    uint8View[1] = 2;
    uint8View[2] = 0;

    console.log(uint8View);
    handleData(buffer); // Outputs: 1 + 2*256 = 513
    console.log("1*1 + 2*256 = 513");
}
```

```cpp
// Not ani_array
static void HandleDataImpl(ani_env *env, ani_object obj, ani_arraybuffer arraybuffer) {
    void *resultData;
    ani_size resultSize;
    env->ArrayBuffer_GetInfo(arraybuffer, &resultData, &resultSize);
    std::cout << *static_cast<uint32_t*>(resultData) << std::endl;
}
```

Full example: [ani_arraybuffer.cpp](https://gitee.com/ironrain/ani_cookbook/blob/master/ani_arraybuffer/ani_arraybuffer.cpp)

## 14 Enum

The following table describes how managed entities are mapped on ANI types:

| Identifier    | ANI Type       | Mangling Name         |
| ------------- | -------------- | --------------------- |
| `COLOR`       | `ani_enum`     | `E{moduleName.COLOR}` |
| `COLOR.Blue`  | `ani_enum_item`| `C{std.core.Object}`  |

## 15 Error

### 15.1 Throwing Errors

Base class: `Error`  
Mangling: `C{escompat.Error}`

To throw a custom error, inherit from this base class.

> Note: A system-declared `BussinessError` may cause binding conflicts with native constructors.

**Example:**

```cpp
void ThrowError(ani_env *env)
{
    static constexpr std::string_view message = "This will show message!";

    ani_class errCls;
    const char* className = "escompat.Error";
    env->FindClass(className, &errCls);
    ani_method errCtor {};
    env->Class_FindMethod(errCls, "<ctor>", "C{std.core.String}C{escompat.ErrorOptions}:", &errCtor);

    ani_string resultString {};
    env->String_NewUTF8(message.data(), message.size(), &resultString);
    ani_ref undefinedRef {};
    env->GetUndefined(&undefinedRef);

    ani_object errObj {};
    env->Object_New(errCls, errCtor, &errObj, resultString, undefinedRef);
    env->ThrowError(static_cast<ani_error>(errObj));
}
```

### 15.2 Catching Errors

1. Synchronous:
```ts
try {
  nativeThrowError();
} catch (e: Error) {
  console.log(e.message);
}
```

2. Asynchronous: Use `.catch()`

## 16 String

### Convert `std::string` → `ani_string`

```cpp
std::optional<ani_string> ANIUtils_StdStringToANIString(ani_env *env, std::string str) {
    ani_string result_string{};
    if (env->String_NewUTF8(str.c_str(), str.size(), &result_string) != ANI_OK) {
        return {};
    }
    return result_string;
}
```

### Convert `ani_string` → `std::string`

```cpp
std::string ANIUtils_ANIStringToStdString(ani_env *env, ani_string ani_str) {
    ani_size sz {};
    env->String_GetUTF8Size(ani_str, &sz);

    std::string result(sz + 1, 0);
    env->String_GetUTF8(ani_str, result.data(), result.size(), &sz);
    result.resize(sz);
    return result;
}
```

## 17 BigInt

```ts
// example.ets
function native testBigInt(num: bigint): void

function main() {
    loadLibrary("libraryName")
    let n: bigint = 11223344n;
    testBigInt(n);
}
```

```cpp
static void TestBigIntImpl(ani_env *env, ani_object num) {
    static constexpr const char* className = "escompat.BigInt";
    ani_class bigIntCls;
    env->FindClass(className, &bigIntCls);
    ani_method getLongMethod;
    env->Class_FindMethod(bigIntCls, "getLong", ":l", &getLongMethod);

    ani_long longnum;
    env->Object_CallMethod_Long(num, getLongMethod, &longnum);

    std::cout << "num value is: '" << longnum << "'" << std::endl;
}

ANI_EXPORT ani_status ANI_Constructor(ani_vm *vm, uint32_t *result) {
    ani_env *env;
    vm->GetEnv(ANI_VERSION_1, &env);

    ani_module mod;
    env->FindModule("example", &mod);

    ani_native_function fn {"testBigInt", "C{escompat.BigInt}:", reinterpret_cast<void *>(TestBigIntImpl)},
    env->Module_BindNativeFunctions(mod, &fn, 1);
    *result = ANI_VERSION_1;
    return ANI_OK;
}
```

## 18 Usage of Other Container Classes

1. Use `FindClass` to locate the target container class by name.
2. Use `Class_FindMethod` + `Object_CallMethod` or `Object_CallMethodByName` to call built-in methods.
3. Convert argument/return types as needed. For complex types, extract primitives via method calls.

### 18.1 Record: `escompat.Record`

| Function     | Signature                               |      Description   |
|--------------| ----------------------------------------|--------------------|
| `<ctor>`     | `C{std.core.Object}:`                   | Constructor        |
| `$_get`      | `C{std.core.Object}:C{std.core.Object}` | Get value by key   |
| `$_set`      | `C{std.core.Object}:`                   | Set key-value pair |
| `keys`       | `C{escompat.IterableIterator}`          | List keys          |

**Example:**

```ts
class PersonInfo {
    name: string = "";
    age: number = 0;
}

native callWithRecord(entry: Record<string, PersonInfo>): void;
```

```cpp
void CallWithRecordImpl(ani_env *env, ani_object object, ani_object record) {
    ani_class recordCls;
    env->FindClass("escompat.Record", &recordCls);
    ani_method getter;
    // Signature can be omitted if there are not overloads
    env->Class_FindIndexableGetter(recordCls, nullptr, &getter);

    static constexpr std::string_view name = "Chloe";
    ani_string aniName;
    env->String_NewUTF8(name.data(), name.length(), &aniName);
    ani_ref person;
    env->Object_CallMethod_Ref(record, getter, &person, aniName);

    ani_ref personName;
    env->Object_GetFieldByName_Ref(static_cast<ani_object>(person), "name", &personName);
    ani_double personAge;
    env->Object_GetFieldByName_Double(static_cast<ani_object>(person), "age", &personAge);
}
```

### 18.2 Tuple


**Example：** 
```ts
let a = [3.14, 2.71, 1.61, 0.59, 10.0];

native callWithTuple(tuple:[double, double, double, double, double]):void;
```

```cpp
void callWithTupleImpl(ani_env *env, ani_tuple_value tuple) {
    ani_double result = 0.0;
    env_->TupleValue_GetItem_Double(tuple, 0U, &result);  // result = 3.14
}
``` 

## 19 Error Code Analysis

```cpp
typedef enum {
    ANI_OK,
    ANI_ERROR,
    ANI_INVALID_ARGS,
    ANI_INVALID_TYPE,
    ANI_INVALID_DESCRIPTOR,
    ANI_INCORRECT_REF,
    ANI_PENDING_ERROR,
    ANI_NOT_FOUND,
    ANI_ALREADY_BINDED,
    ANI_OUT_OF_REF,
    ANI_OUT_OF_MEMORY,
    ANI_OUT_OF_RANGE,
    ANI_BUFFER_TO_SMALL,
    ANI_INVALID_VERSION,
    ANI_AMBIGUOUS,
} ani_status;
```

| Enum                     | Value | Description               | Notes                             |
| ------------------------ | ----- | ------------------------- | --------------------------------- |
| `ANI_OK`                 | 0     | Success                   |                                   |
| `ANI_ERROR`              | 1     | General error             | Needs further investigation       |
| `ANI_INVALID_ARGS`       | 2     | Invalid arguments         | Likely due to null pointers       |
| `ANI_INVALID_TYPE`       | 3     | Invalid type              | Return type mismatch              |
| `ANI_INVALID_DESCRIPTOR` | 4     | Invalid descriptor        | Mangling issue                    |
| `ANI_INCORRECT_REF`      | 5     | Incorrect reference       |                                   |
| `ANI_PENDING_ERROR`      | 6     | Exception thrown in ArkTS | ArkTS-level error                 |
| `ANI_NOT_FOUND`          | 7     | Not found                 | FindXXX failed                    |
| `ANI_ALREADY_BINDED`     | 8     | Already bound             | Repeated native binding           |
| `ANI_OUT_OF_REF`         | 9     | Out of reference          | Array out of bounds               |
| `ANI_OUT_OF_MEMORY`      | 10    | Out of memory             |                                   |
| `ANI_OUT_OF_RANGE`       | 11    | Out of range              |                                   |
| `ANI_BUFFER_TO_SMALL`    | 12    | Buffer too small          |                                   |
| `ANI_INVALID_VERSION`    | 13    | Invalid version           | Common in VM creation             |
| `ANI_AMBIGUOUS`          | 14    | Ambiguous                 | Avoid using nullptr for signature |

### 19.1 Error Code 2: `ANI_INVALID_ARGS`

This indicates one of your arguments is an illegal `nullptr`.  
Example:
```cpp
Object_CallMethodByName_Boolean(nullptr, ...);
```

### 19.2 Error Code 6: `ANI_PENDING_ERROR`

This means the ArkTS runtime threw an error.  
Use the following to capture and describe the error:

```cpp
// Code that causes error...
ani_boolean errorExists;
env->ExistUnhandledError(&errorExists);
assert(true);

std::ostringstream buffer;
std::streambuf *oldStderr = std::cerr.rdbuf(buffer.rdbuf());
ani_status status = env->DescribeError();
std::cerr.rdbuf(oldStderr);
std::string output = buffer.str();
// Log captured `output`
```

### 19.3 Error Code 7: `ANI_NOT_FOUND`

Ensure `.d.ets` and `.ets` files are exactly consistent. Otherwise, native methods may always fail on-device.

```ts
// .d.ets
class A {
    foo(i: int): void // mismatch
}

// .ets
class A {
    foo(): void // mismatch
}
```

### 19.4 Error Code 14: `ANI_AMBIGUOUS`

Occurs when overloads exist and `nullptr` is used for mangling:

```cpp
// .ets
function foo(i: int): void
function foo(d: number): void

// .cpp
FindMethod(cls, "foo", nullptr, &method); // ERROR
FindMethod(cls, "foo", "D:V", &method);   // OK
```

## 20 Frequently Asked Questions (FAQ)

- **BussinessError cannot be created or behaves abnormally**  
  Check for `BussinessError$partial`. The system may include a built-in `BussinessError` causing conflict in the ABC. Contact the frontend and stdlib maintainers.

- **Program crashes after `Object_New`**  
  Typically due to argument type mismatches. Never use `nullptr` as a signature when finding constructors.

- **Declaration and implementation mismatch**  
  Misalignment between `.d.ets` and `.ets` causes fields or methods to be unrecognized.

- **`ani_boolean` does not print properly**  
  It's defined as `uint8_t`, not `bool`. Cast to `int` before output.

- **How to convert `ani_int`/`ani_double` to `ani_ref`?**  
  Box them to `ani_object`, then cast to `ani_ref`. See section 3.3.

- **How to register a destructor for native cleanup on ArkTS GC?**  
  Currently not supported automatically. Must trigger manually via GC in ArkTS.

- **Why do two different functions in ArkTS give the same address in native?**  
  Native function arguments use fixed-pointer slots internally. Their addresses are reused.

- **How to compare two ArkTS function arguments in native?**  
  Use `GlobalReference_Create` to preserve `ani_ref` and compare with `Reference_StrictEquals`.

- **`Reference_StrictEquals` returns true for different instances?**  
  For primitive wrappers like `String`, comparison is by content. For custom classes, it's by address.

- **Does `String_GetUTF8SubString` truncate characters when length is insufficient?**  
  Yes. UTF-8 substrings are truncated if the byte range doesn't cover a full character.

- **Why does `Object_New` return `ANI_INVALID_TYPE`?**  
  Ensure you match constructor argument types exactly (e.g., use `ani_long` for `long` arguments).

- **How to write `resolve` and `reject` for a `Promise<void>` function?**  
  Not supported. Change to a version with a return type.

- **How to execute `.abc` on device and test APIs?**  
  Build the runtime via GN, then execute via:
  ```
  export LD_LIBRARY_PATH=.;
  /path/to/ark --boot-panda-files=etsstdlib.abc --load-runtimes=ets run.abc run.ETSGLOBAL::main
  ```

- **Do constructors support optional parameters?**  
  Yes, through overloads. Bind each overload as a separate native constructor.

- **Why can't I retrieve optional parameters in `namespace` methods?**  
  When using `Namespace_BindNativeFunctions`, do not pass the class object as the second parameter.

- **Issue accessing union types in namespace-bound native**  
  Again, do not pass the class object as a second argument in `Namespace_BindNativeFunctions`.

- **Declared and passed arguments still result in `nullptr` in native**  
  Check for incorrect native binding in section 1.1.

- **Calling `Record.keys()` results in error code 14**  
  Add the correct signature `:Lescompat/IterableIterator;` to resolve ambiguity.
