# Ark Native Interface 应用实践手册
## 参考索引
| 名称 | 资源链接 | 主要用途 | 定位 |
| ---- | ---- | ---- | ---- |
| ANI快速入门指南（本文档） | **[ani-usage-scenarios.md](https://gitee.com/openharmony/arkcompiler_runtime_core/tree/OpenHarmony_feature_20250328/static_core/plugins/ets/runtime/ani/docs/ani_scenario.md)** | 综合的ANI文档；解决大多数问题 | 初学者指南，必读参考资料 |
| NAPI到ANI迁移示例 | **[napi2ani.md](https://gitee.com/openharmony/arkcompiler_runtime_core/tree/OpenHarmony_feature_20250328/static_core/plugins/ets/runtime/ani/docs/napi2ani.md)** | 展示从NAPI到ANI函数的正确迁移，以确保兼容性 | 用于未知映射的参考指南 |
| ANI用法示例（ani_cookbook） | **[ani_cookbook](https://gitee.com/ironrain/ani_cookbook)** | 提供从简单到高级用例的即用型函数示例 | 实用的烹饪书和入门工具包 |
| ANI接口测试套件 | **[ani/tests测试文件夹](https://gitee.com/openharmony/arkcompiler_runtime_core/tree/OpenHarmony_feature_20250328/static_core/plugins/ets/tests/ani/tests)** | 验证ANI函数及其正确性；始终保持功能可用 | 用于验证API用法的参考资料 |
| ani.h头文件 | **[ani.h](https://gitee.com/openharmony/arkcompiler_runtime_core/blob/OpenHarmony_feature_20241108/static_core/plugins/ets/runtime/ani/ani.h)** | 核心定义文件，包括函数声明、类型和继承关系 | 所有定义的来源 |

## 使用建议
在进行NAPI到ANI的迁移任务时，请遵循以下步骤：
1. **理解ANI规范**：阅读`ani.h`头文件，了解参数类型、返回值约定以及所有`ani_*`类型的用法。这是正确迁移的基础。
2. **研究迁移示例**：参考`napi2ani.md`获取实际的映射示例。观察结构、参数处理和错误处理策略。
3. **实践与验证**：在自己的开发环境中克隆并运行`ani_cookbook`中的示例。通过实践验证加深理解，并熟悉ANI API。

# ANI场景文档
## 1. 使用`loadLibrary`
### 1.1 native函数绑定
绑定native函数的过程涉及几个关键步骤：
1. 在`.ets`文件中声明native函数和方法。
2. 在托管代码中调用`loadLibrary("libraryName")`：
    - 可以在静态块或任何别的入口点（例如`main`函数）中完成，确保native library在调用任何native函数之前被加载，并将所有的native function绑定到其实现。
    - `libraryName`是原生库的名称，例如对于库`libexample.z.so`，名称为`example.z`。
3. 在native library中实现入口函数`ani_status ANI_Constructor(ani_vm* vm, uint32_t* result)`。
    - 函数必须以默认可见性声明（即`__attribute__((visibility("default")))`）。
    - 当通过`loadLibrary`加载native library时，会自动调用此函数。
4. 在`ANI_Constructor`中，根据绑定位置使用以下ANI API：`Class_BindNativeMethods`、`Namespace_BindNativeFunctions`或`Module_BindNativeFunctions`将ArkTS侧定义的native function/methods与c++定义实现绑定。参考[类方法的绑定](#112-绑定类中的方法)。
5. 在native函数定义中，根据函数作用域提供正确的额外参数：

| 绑定位置 | 绑定函数 | 必需参数 | 描述 |
| ---- | ---- | ---- | ---- |
| 类（非静态） | `Class_BindNativeMethods` | `ani_env`, `ani_object` | 对类的实例进行操作。 |
| 类（静态） | `Class_BindNativeMethods` | `ani_env`, `ani_class` | 对类本身进行操作。 |
| 命名空间 | `Namespace_BindNativeFunctions` | `ani_env` | 无需对象引用。 |
| 模块 | `Module_BindNativeFunctions` | `ani_env` | 无需对象引用。 |

**注意**：C++中的native函数签名必须将这些参数作为前导参数：
```cpp
// 实例方法绑定
void nativeInstanceMethod(ani_env* env, ani_object obj, ...);
// 静态方法绑定
void nativeStaticMethod(ani_env* env, ani_class cls, ...);
// 命名空间或模块绑定
void nativeNamespaceFunction(ani_env* env, ...);
```
#### 重要注意事项
- 传递给native函数的参数的生命周期与native函数绑定。**不要**在参数作用域之外存储native函数参数，底层内存将被释放。请参阅[生命周期管理](#9-lifecycle-management)。
- `ani_env`: 通过native函数接收的参数，仅在当前native调用中有效。**不要**在native函数调用作用域之外存储`ani_env`或者传递给新线程使用。
- native函数不能在`interface`块内声明。

---
### 1.1.1 类名、标识符和符号查找
使用`ark_disasm`工具检查`.abc`文件，以确定类名和符号名。
请参考[反汇编ABC文件](#116-disassembling-abc-files)获取`ark_disasm`工具。
示例反汇编结果：
```ts
.record example.Foo <ets.extends=std.core.Object, access.record=public>
```
在签名中对应的类名是`C{example.Foo}`，用于`FindClass`的类名是`example.Foo`。

---
### 1.1.2 绑定类中的方法

下面的代码展示如何将ArkTS中声明的native function与对应的C++实现绑定。
为了保证在使用`Class_BindNativeMethods`的时候有正确的函数签名，可以先对 ABC 文件进行反汇编。

**ArkTS代码**：
```ts
class PasteData {
    static { loadLibrary("libraryName") }
    native getRecordCount(a: int): int;
}
```
**反汇编的ABC代码**：
```ts
.function i32 example.PasteData.getRecordCount(example.PasteData a0, i32 a1) <native, access.function=public>
```

**C++实现**：
```cpp
static ani_int getRecordCount(ani_env* env, ani_object object, ani_int a);
```

**绑定代码**：
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

> 使用`reinterpret_cast<void*>`消除c++函数的类型。
---

### 1.1.3 绑定命名空间中的方法
**ArkTS代码**：
```ts
namespace PasteData {
    loadLibrary("libraryName")
    native function getRecordCount(a: int): int;
}
```
**反汇编的ABC代码**：
```ts
.function i32 example.PasteData.getRecordCount(i32 a0) <native, static, access.function=public>
```
**C++实现**：
```cpp
static ani_int getRecordCount(ani_env* env, ani_int a);
```
**绑定代码**：
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
> **重要提示**：namespace和modules中声明的native function，对应的c++实现只需要一个额外的`ani_env*`, 不要添加额外的`ani_object`或者`ani_class`。

---
### 1.1.4 绑定模块中的函数
**ArkTS代码**：
```ts
loadLibrary("libraryName")

enum COLORINT { REDINT = 5 }
native function processEnumInt(color: COLORINT): void;
```
**反汇编的ABC代码**：
```ts
.function void example.ETSGLOBAL.processEnumInt(example.COLORINT a0) <native, static, access.function=public>
```

**C++实现**：
```cpp
static void processEnumInt(ani_env* env, ani_enum_item enumItem);
```

**绑定代码**：
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

> **重要提示**：只能通过`FindModule`找到对应的module。必须使用`Module_BindNativeFunctions`绑定模块函数。

---

### 1.1.5 函数绑定中的特殊场景

- **重载函数**：如果存在重载的native函数，必须显式绑定每个变体：

```ts
native function foo(): void
native function foo(arg: string): void
```

这需要绑定两个函数：
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
- 可选参数**不会**创建重载。

```ts
function foo(a: int, b: int = 3): void
```

在字节码中仅包含一个函数

```ts
.function void example.foo(i32 a0, std.core.Int a1)
```

---
### 1.1.6 反汇编ABC文件
要反汇编`.abc`文件，请使用`ark_disasm`二进制文件，它在以下仓库的常规项目构建过程中生成：
- [`arkcompiler_runtime_core`](https://gitee.com/openharmony/arkcompiler_runtime_core/tree/OpenHarmony_feature_20241108/)
- [`arkcompiler_ets_frontend`](https://gitee.com/openharmony/arkcompiler_ets_frontend/tree/OpenHarmony_feature_20241108/)

**构建说明**：[遵循本指南](https://gitee.com/JianfeiLee/arkcompiler_runtime_core/wikis/下载和编译运行ArkTS演进版本代码)

**用法**：

```bash
./out/bin/ark_disasm yourabcfile.abc dumpfile.txt
```

> 如果反汇编失败，请检查工具和运行时之间的版本是否匹配。

### 1.2 类加载失败诊断

`FindClass`失败时可能会返回错误码`ANI_PENDING_ERROR`，意味着在加载对应class的时候抛出了error。这种情况通常是由于使用了损坏的或不兼容的 ABC 文件所导致：
* 使用了旧版本的 ABC 文件与较新的 etsstdlib.abc 不兼容。
* 运行时新版本包含了不兼容的改动，需要重新编译托管代码。

通常会抛出`LinkerUnresolvedClassError`异常，在托管代码的堆栈跟踪中可见：
```ts
at std.core.LinkerUnresolvedClassError.<ctor> (<unknown>:36)
```

类加载过程中可能抛出的全部错误，可以参考：
[RuntimeLinkerErrors.ets](https://gitee.com/openharmony/arkcompiler_runtime_core/blob/OpenHarmony_feature_20250328/static_core/plugins/ets/stdlib/std/core/RuntimeLinkerErrors.ets).

#### 1.2.1 LinkerUnresolvedClassError故障排查
---
##### 1.2.1.1 不正确的`loadLibrary`用法

ArkTS 1.2使用模块和类的延迟初始化。在实践中，这意味着静态块和 top 级语句仅在第一次访问作为类或模块一部分定义的实体之前执行。考虑以下示例：

```ts
loadLibrary("libraryName")
// 模块中唯一导出的实体
export function foo(): void {
    fooImpl(12)
}
native function fooImpl(arg: int): void
```
这里`loadLibrary`作为 top 级语句添加，因此它将在第一次调用`foo`或`fooImpl`之前执行。

##### 1.2.1.2 设备缺少ABC加载

1. 检查程序的进程，以确定在执行期间是否加载了ABC模块。如果没有，请继续执行步骤2：
```
cat /proc/pid/maps | grep abc
```

2. 检查所需的ABC模块是否存在于`/system/framework`路径下。如果存在，请执行步骤3。
3. 检查所需的ABC模块加载路径是否存在于`/system/framework/bootpath.json`中。如果不存在，请添加路径：

```
hdc file recv /system/framework/bootpath.json ./
hdc file send bootpath.json /system/framework/bootpath.json
```

> **注意:**：修改此文件需要重启设备！

4. 如果`bootpath.json`缺少ABC模块加载路径，可能是由于模块打包期间缺少配置。在`generate_abc`下的`build.gn`中添加`is_boot_abc="True"`。

----

### 2. 名称修饰符（Mangling）规则

_Mangling_ 是一种对函数签名进行编码的方法，通过参数和返回类型来区分重载函数。其格式如下：

```
<参数类型>:<返回类型>
```

### 示例

- `toInt(num: number): int` → `d:i`
- `toInt(str: string): int` → `C{std.core.String}:i`

使用方式如下：

```cpp
Object_CallMethodByName_Int(obj, "toInt", "d:i", &result);
Object_CallMethodByName_Int(obj, "toInt", "C{std.core.String}:i", &result);
```

---

### 类型Mangling参考

| ArkTS 类型 | 修饰代码 | ANI 类型 |
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

注意：`number`在ArkTS中是`double`的别名

#### 对象类型

| ArkTS Class Type            | Mangling                    | 说明                                                              |
|-----------------------------|-----------------------------|-------------------------------------------------------------------|
| `class CustomCls`           | `C{example.CustomCls}`      | 以 `C` 开头, 路径用点分隔                                           |
| `interface CustomIface`     | `C{example.CustomIface}`    | 以 `C` 开头, 路径用点分隔                                           |
| `string`                    | `C{std.core.String}`        | 标准库类型                                                         |
| `bigint`                    | `C{escompat.BigInt}`        | `escompat` 包中的标准库类型                                         |
| `Array`                     | `C{escompat.Array}`         | `escompat` 包中的标准库类型                                         |
| `()=>void`                  | `C{std.core.Function0}`     | 根据所需参数数量确定的函数对象                                       |
| `(...args: double[])=>void` | `C{std.core.FunctionR0}`    | 带有剩余参数、根据所需参数数量确定的函数对象                          |

#### 数组类型

据ArkTS 规范的`3.16.1 Resizeble Array Types`的描述，`T[]`和`Array<T>`表示的是相同的类型。因此，它们在底层都会被等价转换为`C{escompat.Array}`

```ts
function foo(a: string[], b: Array<Int>): void  // "C{escompat.Array}C{escompat.Array}:"
```

#### 固定数组类型

| ArkTS 数组 | Mangling |
|-------------------------------|-------------------------|
| `FixedArray<int>`             | `A{i}`                  |
| `FixedArray<FixedArray<int>>` | `A{A{i}}`               |
| `FixedArray<String>`          | `A{C{std.core.String}}` |

#### 特殊类型

| 特殊值 | Mangling | 说明 |
|----------------|-----------------------|----------------------|
| `null`         | `C{std.core.Object}`  | Use `GetNull()`      |
| `undefined`    | `C{std.core.Object}`  | Use `GetUndefined()` |

---

### 主要Mangling规则

1. **分隔参数和返回类型**
    - 使用 `:` 来分隔参数和返回类型，例如 `dd:i`（两个双精度浮点数，返回整数）。

2. **无参数的 `void` 返回类型**
    - 无参数：`:`
    - 如果没有参数，参数部分可以省略，但返回类型是必需的。

3. **对象格式**
    - 格式：`C{<模块>.<类>}`
    - 如果没有显式声明模块名，默认模块名是文件名。

4. **数组格式**
    - 一维数组：`A{元素类型}`
    - 多维数组：每增加一维就嵌套一个 `A`，例如 `A{A{I}}`

5. **泛型类型**
    - 映射到类型约束。默认类型约束是 `Object | null | undefined`，在签名中对应 `C{std.core.Object}`
    - 不会直接影响Mangling

6. **联合类型**
    - 映射到 _最小上界_ 类型：

```ts
function foo(a: string | number): void // "C{std.core.Object}:"
interface I {}
class C implements I {}
function foo(a: C | I): void    // "C{hello_ani.I}:"
```

7. **可选参数（装箱）**
    - 可选的基本类型会变成装箱对象：
        - `arg?: int` → `C{std.core.Int}`
        - `arg?: double` → `C{std.core.Double}`
    - 非基本类型的可选类型保持不变

8. **函数作为参数**
    - 使用 `C{std.core.FunctionN}`，其中 `N` 是参数数量
    - 使用 `C{std.core.FunctionRN}`，其中 `R` 表示函数带有剩余参数

---

### Mangled的签名示例

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

## 3 类型定义

### 3.1 原生（native）类型/基本类型

```cpp
// ETS基本类型的运行时类型
typedef uint8_t  ani_boolean;  // 布尔型（1字节） ETS声明：boolean
typedef uint16_t ani_char;     // 字符型（2字节） ETS声明：char
typedef int8_t   ani_byte;     // 字节型（1字节） ETS声明：byte
typedef int16_t  ani_short;    // 短整型（2字节） ETS声明：short
typedef int32_t  ani_int;      // 整型（4字节）   ETS声明：int
typedef int64_t  ani_long;     // 长整型（8字节） ETS声明：long
typedef float    ani_float;    // 单精度浮点型    ETS声明：float
typedef double   ani_double;   // 双精度浮点型    ETS声明：double/number
```

`number` 是 `double` 类型的别名。

> 由于 `ani_boolean` 是 `uint8_t` 而非 `bool`，所以不能直接使用 `cout` 或别的 C++ 流 API 进行打印。在输出之前，需要将其转换为 `int` 类型。

### 3.2 扩展类型

| 类型定义 | 描述 | 补充说明 |
| ------------------- | ------------------------- | ----------------------------------------------- |
| `ani_ref`           | ani`object`的基类型        |                                                 |
| `ani_object`        | 任何非基本类型             | 不包括像 `ani_int` 这样的基本类型                 |
| `ani_error`         | `Error`                   |                                                 |
| `ani_fn_object`     | `Function/()=>void`       |                                                 |
| `ani_arraybuffer`   | `ArrayBuffer`             |                                                 |
| `ani_string`        | `string`                  |                                                 |
| `ani_fixedarray`    | `FixedArray<T>`           | 所有fixed array的基类型                          |
| `ani_array`         | `T[]`                     | 等价于`Array<T>`                                 |


如果函数参数期望的是 `ani_ref` 或 `ani_object`，需要传递一个 `ani_int` 类型的值，则需要将其装箱为 `ani_ref`。请参阅[4.1节](#41-boxing--unboxing)。

### 3.3 类型转换

如果以下继承链上的类型存在父子关系，则可以使用 `static_cast` 进行转换。此链之外的类型不能转换为 `ani_ref` 或 `ani_object`。一个典型的例子是 `ani_method`。

然而，这种转换必须确保该类型在 ETS 运行时层是可用的。例如，将一个 `ani_string` 转换为 `ani_ref` 后，再尝试将其当作 `ani_array` 使用，将会导致运行时崩溃。

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
例如 `auto str = static_cast<ani_string>(string_ref);`

- 如何将 `ani_int` / `ani_double` 等基本类型转换为 `ani_ref`？

请参考[第4.1节](#41-boxing--unboxing)中的“装箱”过程。

### 3.4 类型识别：Object_InstanceOf

参数中的 `ani_object` 代表所有类型。如果存在像 `A | B` 这样的联合类型参数，则必须使用 `Object_InstanceOf` 来识别实际类型。

```ts
type DataType = string | ArrayBuffer | FixedArray<int> | FixedArray<string>
native function handleData(data: DataType): void  

function main(){
    loadLibrary("libraryName")
    handleData("hello")                 // 将会输出 "Object is String; content: hello"
    handleData(new ArrayBuffer(1024))   // 将会输出 "Object is ArraryBuffer; length: 1024"
    handleData(new FixedArray<int>())   // 将会输出 "Object is FixedArray"
}
```

```cpp
static void handleData_union(ani_env *env, ani_object obj, ani_object union_obj){
    // 注意：在生产代码中，通过`GlobalReference_Create`将FindClass找到的类缓存会大大提高效率
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
        std::cout << "Object is ArraryBuffer; length: " << length << std::endl;
        return; 
    }

    ani_boolean isIntArray = ANI_FALSE;
    env->Object_InstanceOf(union_obj, fixedArrayIntClass, &isIntArray);
    ani_boolean isStringArray = ANI_FALSE;
    env->Object_InstanceOf(union_obj, fixedArrayStringClass, &isStringArray);
    assert(isIntArray || isStringArray);
    std::cout << "Object is FixedArray"<< std::endl;
    return;
}
```

## 4 参数处理

### 4.1 基本类型

- 从语言层面来看，ArkTS 1.2 仅包含基本类型的装箱版本。
- 从运行时角度来看，当基本类型被指定为非泛型参数、返回值或字段类型时，会使用基本类型进行优化。

#### 4.1.1 装箱类型

| ANI 基本类型 | 装箱类 | Mangling  | 绑定/ANI 类型 | 说明 |
| ------------------ | ----------- | --------------------- | ---------------- | ------------------- |
|   `ani_boolean`    | `Boolean`   | `C{std.core.Boolean}` | `ani_object`     | Boxed boolean       |
|   `ani_byte`       | `Byte`      | `C{std.core.Byte}`    | `ani_object`     | Boxed byte          |
|   `ani_char`       | `Char`      | `C{std.core.Char}`    | `ani_object`     | Boxed char          |
|   `ani_short`      | `Short`     | `C{std.core.Short}`   | `ani_object`     | Boxed short         |
|   `ani_int`        | `Int`       | `C{std.core.Int}`     | `ani_object`     | Boxed int           |
|   `ani_long`       | `Long`      | `C{std.core.Long}`    | `ani_object`     | Boxed long          |
|   `ani_float`      | `Float`     | `C{std.core.Float}`   | `ani_object`     | Boxed float         |
|   `ani_double`     | `Double`    | `C{std.core.Double}`  | `ani_object`     | Boxed double        |
|   `ani_number`     | `Double`    | `C{std.core.Double}`  | `ani_object`     | double的别名         |
|         -          | `Void`      | `C{std.core.Void}`    | `ani_object`     | 通常无意义           |


可以参考[第5.1节](#51-querying-methods-of-standard-classes)来查询这些装箱类型及其对应模块的方法。

如果函数参数的名称修饰（mangling）是 `C{std.core.Object}`，则它只接受类实例。例如，`Array<T>` 方法 `$_set(i: int, val: T): void` 的Mangling为 `iC{std.core.Object}:`，其中第二个参数必须是类实例。

在这种情况下，基本类型的值（如 `int` 或 `double`）需要进行装箱（转换为 `Int` 或 `Double`）。根据第3.3节，得到的 `ani_object` 也可以转换为 `ani_ref` 以满足函数要求。

同样，`A{C{std.core.Object}}` 表示类实例的固定数组。

#### 4.1.2 装箱

目的：
1. 满足函数参数类型要求。
2. 将基本类型的值转换为类实例（例如，将 `ani_int` 转换为 `ani_ref`）。

在托管代码中，对于可选参数，装箱操作会自动进行。省略可选基本类型的值默认为 `undefined`。在原生（native）代码中，必须显式传递参数。

- 创建一个装箱对象：
```cpp
ani_object createDouble(ani_env *env)
{
    // 注意：在生产代码中，通过`GlobalReference_Create`将FindClass找到的类缓存会大大提高效率
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

你可以通过 `Class_FindMethod` 的 `signature` 参数来选择所需的构造函数重载版本。

#### 4.1.3 拆箱

使用 `unboxed` 来提取基本类型的值：
```cpp
Object_CallMethodByName_Double(boxed_double_obj, "unboxed", ":d", &unboxed_value)
```

`Double` 由装箱对象的返回类型决定。Mangling `:d` 表示返回一个 `double` 类型的值。

示例：
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

### 4.2 泛型参数

- 除了`FixedArray`外，所有泛型类型在运行时都会被擦除
- 在字节码中，类型参数会被编译为其类型约束。
- 默认的类型约束是 `Object | null | undefined`。
- 基本类型作为类型参数使用时总是会被装箱。

| ArkTS 类型 | 示例 | Mangling | 绑定/ANI 类型 | 补充说明 |
| -------------------- | ----------------- | --------------------------------------- | -------------------- | ----------------------------------- |
| `(a: T, b: R): void` | `f(1, "str")`     | `C{std.core.Object}C{std.core.Object}:` | `ani_object`         |                                     |
| `Array<T>`           | `Array<int>`      | `C{escompat.Array}`                     | `ani_object`         |                                     |
| `FixedArray<T>`      | `FixedArray<int>` | `A{i}`                                  | `ani_fixedarray_int` | Reified (非擦除) 类型参数             |

### 4.3 联合类型

联合类型会被编译为组件的 _最小上界_，在 ANI 中对应 `ani_object`。最常见的情况是该类型为 `C{std.core.Object}`，但并非总是如此：如公共Interface为最小上界，类型为`C{some_module.I}`

```ts
interface I {}
class C implements I {}
function foo(arg: C | I): void  // Signature: "C{some_module.I}:"
```

> 可选参数 `arg?: T` 始终等同于 `arg: T | undefined`，可以在ArkTS 语言规范`第4.8.4 Optional Parameters`中查看

由于联合类型用引用表示，基本类型的值必须装箱后才能作为联合类型的一部分使用。

| ETS 类型 | Mangling | 绑定/ANI 类型 | 补充说明 |
| -------------------- | -------------------- | ---------------- | ---------------------- |
| `a: double | string` | `C{std.core.Object}` | `ani_object`     | 基本类型需要装箱        |

**参数处理**：

使用 `Object_InstanceOf` 来确定参数的实际类型并进行相应处理。请参阅[3.4 类型识别：Object_InstanceOf](#3.4-Type-Identification:-Object_InstanceOf)

### 4.4 可选参数

**Mangling**：
1. 像 `int`、`double` 这样的基本类型会被装箱为 `Int`、`Double` 等。
2. 非基本类型保留其原始的Mangling。
3. 所有可选参数都被视为包含 `undefined` 的联合类型（请参阅ArkTS 语言规范 `第4.8.4 可选参数`）。
4. 对于带有可选参数的构造函数，`.abc` 文件中存在重载构造函数。

| ETS 类型 | Mangling | 绑定/ANI 类型 | 补充说明 |
| ------------------- | ---------------------- | ------------------ | ---------- |
| `a: int`            | `i`                    | `ani_int`          |            |
| `a?: int`           | `C{std.core.Int}`      | `ani_object`       | 装箱       |
| `a: Int`            | `C{std.core.Int}`      | `ani_object`       |            |
| `a?: Int`           | `C{std.core.Int}`      | `ani_object`       |            |
| `a?: customCls`     | `C{example.CustomCls}` | `ani_object`       |            |
| `a?: string \| int` | `C{std.core.Object}`   | `ani_object`       | 联合类型    |

**参数处理**：

如果参数是包含 `undefined` 类型的联合类型，在原生（native）代码中访问该参数之前，必须检查它是否为 `undefined`：


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

### 4.5 默认参数

与可选参数的情况类似：
1. 基本类型会自动装箱。
2. 非基本类型保留原始的Mangling。

```ts
// 签名："zC{std.core.Boolean}:"
function foo(a: boolean, b: boolean = false): void {}
```

### 4.6 可变/剩余 参数

可变参数是 ArkTS 中的语法糖，它将参数收集到一个数组中。

```ts
// 签名："iA{i}:"
function foo(a: int, ...b: int[]): void
```

## 5. 对象创建

### 5.1 查询标准类的方法

在 [stdlib](https://gitee.com/openharmony/arkcompiler_runtime_core/blob/OpenHarmony_feature_20250328/static_core/plugins/ets/stdlib/) 路径下查找所需的标准库函数。如果不确定要查询哪个类，可以反汇编 `etsstdlib.abc` 文件来确认类名和编译后的签名。

#### 示例1：ArrayBuffer

在 [ArrayBuffer.ets](https://gitee.com/openharmony/arkcompiler_runtime_core/tree/OpenHarmony_feature_20250328/static_core/plugins/ets/stdlib/escompat/ArrayBuffer.ets) 中找到 “class ArrayBuffer” 与对应的`constructor`。

代码片段：
```ts
export class ArrayBuffer extends Buffer
{
    public constructor(length: int, maxByteLength?: int)
    public constructor(length: number, maxByteLength?: number)
    public static isView(obj: Object): boolean
    get byteLength(): number 
}
```

从上述代码片段中，可以发现：
1. 有两个构造函数。ANI识别的函数名为 `<ctor>`。第一个构造函数的mangling可以写成 `iC{std.core.Int}:`。**切勿使用`nullptr`代替构造函数签名** - 重载的methods需要通过函数签名进行区分。
2. 名为 `isView` 的方法，参数为 `Object`，返回类型为 `boolean`。它的mangling是 `C{std.core.Object}:z`。
3. 一个 `byteLength` 属性。


### 5.2 查询非标准类的方法
一个典型的例子是 枚举（enums）。ArkTS 前端在编译过程中会为枚举生成特殊的类来支持其功能。

这些枚举类中生成的方法和字段属于实现细节（implementation-defined），因此不推荐直接访问它们，以避免因版本变化或内部结构调整导致程序出错。

相反，ArkTS 提供了专门的 ANI 接口来安全地操作枚举，例如：

- `Enum_GetEnumItemByName`：通过名称获取枚举
- `EnumItem_GetValue_String`：获取枚举项的字符串值

### 5.3 创建类实例
1. 使用 `FindClass` 定位类。
2. 使用 `Class_FindMethod`，通过正确的mangling查找所需的构造函数。
3. 使用 `Object_New` 创建对象。

#### 示例
```ts
// 文件名: example.ets
// 模块名: example
// 默认情况下，模块名等于文件名

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

1. FindClass：
```cpp
ani_class cls {};
env->FindClass("example.Point", &cls);
```

2. Class_FindMethod：
```cpp
ani_method ctor1 {};
env->Class_FindMethod(cls, "<ctor>", "ii:", &ctor1);
ani_method ctor2 {};
env->Class_FindMethod(cls, "<ctor>", "dd:", &ctor2);
```

- mangling `ii:` 与 `constructor(x: int, y: int)` 匹配；
- mangling `dd:` 与 `constructor(x: double, y: double)` 匹配。

**永远不要使用nullptr代替构造函数签名**。这样做会使native代码容易出错，因为如果在托管代码中添加新的重载，原本依赖特定签名的native调用可能会意外失效或行为异常。

3. Object_New：
```cpp
ani_object obj1 {};
env->Object_New(cls, ctor1, &obj1, static_cast<ani_int>(1), static_cast<ani_int>(2));
ani_object obj2 {};
env->Object_New(cls, ctor2, &obj2, static_cast<ani_double>(1), static_cast<ani_double>(2));
```

在这里：
- `obj1` 是使用 `constructor(x: int, y: int)` 创建的。
- `obj2` 是使用 `constructor(x: double, y: double)` 创建的。

#### 创建ArkTS标准库类的实例
1. `FindClass`：在 `arkcompiler/runtime_core/static_core/plugins/ets/stdlib` 下定位类。文件会声明包名，通常是 `std.core` 或 `escompat`，mangling将是 `std.core.<ClassName>` 或 `escompat.<ClassName>`。
2. `Class_FindMethod`：通过mangling识别目标构造函数。
3. `Object_New`：调用此函数创建实例。

> **注意**：在ANI中，以下类型**不能**使用 `Object_New` 创建：
- 接口类型
- 抽象类
- 字符串 (`ani_string`) —— 必须使用专门的ANI创建函数
- `FixedArray<T>` 类型 —— 必须使用专门的ANI数组创建函数

## 6. 接口和类
在ANI中，接口不能直接实例化。必须在类中实现它们（类实现接口）后才能使用。
接口中的所有字段都会自动被视为属性(property)。当一个类实现一个接口时，继承的成员也会变成属性。

```ts
interface PointI {
    x: int // property - 默认生成 getter & setter
    y: int // property - 默认生成 getter & setter
}
class Point implements PointI {
    x: int // property - 默认生成 getter & setter
    y: int // property - 默认生成 getter & setter
    z: int // field    - 无默认的 getter & setter
}
```

```cpp
ani_class clsPointI; ani_method ctorPointI; // 假设已初始化
ani_class clsPoint; ani_method ctorPoint;   // 假设已初始化
ani_object objPointI; ani_object objPoint;
env->Object_New(clsPointI, ctorPointI, &objPointI); // 失败
env->Object_New(clsPoint, ctorPoint, &objPoint);    // 成功
```

- 创建接口对象会失败
- 创建类对象会成功。
在ANI中，类的创建不依赖于接口，但接口对象需要类的实现。
在ArkTS代码中，接口对象可以通过对象字面量( _object literal_ )表达式创建：

```ts
let p: PointI = { x: 1, y: 1 };
```

前端会自动生成一个实现了 PointI 接口的类。
不过，该类的对象属性访问实际上是通过编译器自动生成的 `getter` 和 `setter` 方法实现的，而不是直接访问字段。

### 6.1 属性和字段

- **属性**：带有 `get/set` 方法声明。
- **字段**：没有 `get/set` 方法的属性。
- 接口中的所有属性在实现类中都会变成属性。

> **在ANI中不要混淆属性和字段函数！**
例如：
- `Class_FindField` 不能用于属性。
- `Object_GetPropertyByName_Boolean` 不能用于字段。

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

### 6.2 访问属性
#### 6.2.1 访问和设置属性
| 函数名 | 操作 | 描述 |
| --- | --- | --- |
| `Object_GetPropertyByName_<Type>` | get | 以原始类型检索属性 |
| `Object_SetPropertyByName_<Type>` | set | 使用原始类型设置属性 |

如果属性是引用类型，则使用 `_Ref` 后缀。

**示例:**

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

#### 6.2.2 访问和设置字段

| 函数名 | 操作 | 描述 |
| --- | --- | --- |
| `Object_GetFieldByName_<Type>` | 获取 | 以原始类型检索字段 |
| `Object_SetFieldByName_<Type>` | 设置 | 使用原始类型设置字段 |

**示例:**

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

#### 6.2.3 访问静态字段
| 函数名 | 操作 | 描述 |
| --- | --- | --- |
| `Class_GetStaticFieldByName_<Type>` | 获取 | 检索静态字段值 |
| `Class_SetStaticFieldByName_<Type>` | 设置 | 设置静态字段值 |

### 6.3 调用方法

使用 `Object_CallMethod_<Type>`，其中`<Type>`表示返回类型。

**示例:**

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
### 6.4 可选方法作为可选参数

ArkTS 1.2 不直接支持可选方法，可使用可选函数参数代替。

**示例:**
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

### 6.5 包装与解包

示例：[ani_wrap_native_ptr.ets](https://gitee.com/ironrain/ani_cookbook/blob/master/ani_wrap_native_ptr/ani_wrap_native_ptr.ets)

## 7 回调函数/ Lambda 函数对象

函数对象和回调示例：[ani_fn_object/ani_fn_object.ets · ironrain/ani_cookbook](https://gitee.com/ironrain/ani_cookbook/blob/master/ani_fn_object/ani_fn_object.ets)
```cpp
ani_status FunctionalObject_Call(ani_env *env, ani_fn_object fn, ani_size argc, ani_ref *argv, ani_ref *result)
```

此函数要求参数以 `ani_ref` 数组形式传入。
注意：函数对象（`functional object`）始终接受并返回装箱（boxed）的基本类型。这意味着如果你的参数是基本类型，例如`int`或者`double`，需要先将它们转换为对应的装箱类型（如`Int`,`Double`）,然后将这些对象传入数组中，并作为指针出传入。

**示例:**

```cpp
ani_object createDouble(ani_double doubleVal) { ... } // 返回一个 Double 实例，实现见第 4.1.2 节
```

```cpp
std::vector<ani_ref> vec;
vec.push_back(createDouble(ani_double(2)));
vec.push_back(createDouble(ani_double(4)));

ani_ref result {};
env->FunctionalObject_Call(show_every, ani_size(2), vec.data(), &result);
```

## 8 异步执行
异步示例：[ani_async_wrapper/ani_async_wrapper.ets · ironrain/ani_cookbook](https://gitee.com/ironrain/ani_cookbook/blob/master/ani_async_wrapper/ani_async_wrapper.ets)
> [! Warning] **潜在问题**
> 在异步上下文中抛出异常可能会导致程序冻结且无法正常终止。
> 若配置了执行超时，最终可能会自动崩溃。
> 尝试在 `.then` 之后添加 `.catch` 并拒绝该对象，看是否能解决问题。


## 9 生命周期管理

### 9.1 References生命周期

所有在 C++ native 侧创建的对象都是局部引用（_local references_）。这意味着：
- 它们的生命周期仅在当前调用上下文中有效；
- 一旦退出当前 native 调用，它们可能会被垃圾回收器回收；
- 即使你将这些引用存储到全局 C++ 对象中，也不能保证其在下次使用时仍然有效。
**以下示例展示了将局部引用（_local reference_）错误地保存到全局变量中可能导致的问题：**

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
如果你需要创建在多次 native 函数调用之间持久存在的全局引用，可以使用`GlobalReference_Create`：

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

**注意**
- `GlobalReference_Create`返回的`ani_ref`被认为与原先的object相同。
- 当`global reference`不再被使用时，必须使用`GlobalReference_Delete`删除。避免内存耗尽。

### 9.2 VM 和 env 生命周期
- `ani_vm` 在应用启动时创建，其生命周期与应用相同。
- 每个 `ani_env` 与协程一一对应。在 native 函数调用期间，可以保证 `ani_env` 是有效的。

**`ani_env` 只能在其创建的线程中使用。**
当协程结束时，`ani_env` 会被销毁，成为悬空指针。

#### 解决方案：使用 `AttachCurrentThread`

从 `env` 获取 `vm`：
```cpp
ani_vm *vm = nullptr;
env_->GetVM(&vm);
```

在另一个线程中：
1. `AttachCurrentThread`（使用后必须分离）：
```cpp
ani_env *env = nullptr;
ani_options aniArgs {0, nullptr};
auto status = vm_->AttachCurrentThread(&aniArgs, ANI_VERSION_1, &env);
// env 可正常使用，用于 native 调用 ArkTS 对象
```

对于interop模式：

```cpp
ani_env *env {nullptr};
ani_option interopEnabled {"--interop=enable", nullptr};
ani_options aniArgs {1, &interopEnabled};
auto status = vm->AttachCurrentThread(&aniArgs, ANI_VERSION_1, &env);
// env 可用于 JS ↔ ArkTS 互操作的线程
```

2. 若线程已附加到 VM，则使用 `GetEnv`：
```cpp
ani_env *env;
auto status = vm->GetEnv(ANI_VERSION_1, &env);
```

3. 线程结束时主动分离
```cpp
env->DetachCurrentThread();
```

> 注意：只有通过`AttachCurrentThread`绑定的线程才可以`detach`

## 10 多线程

在 ArkTS 的 ANI（Ark Native Interface）中，Promise 类型的创建与管理有专门的接口支持，用于在 native 层与异步 JS/ArkTS 场景交互。
```cpp
ani_status Promise_New(ani_env *env, ani_resolver *result_resolver, ani_object *result_promise);
ani_status PromiseResolver_Resolve(ani_env *env, ani_resolver resolver, ani_ref resolution);
ani_status PromiseResolver_Reject(ani_env *env, ani_resolver resolver, ani_error rejection);
```

除此之外用户可以通过以下两种方式在程序中使用多线程与 ArkTS 协作：
- 自行创建一个 native 线程，在线程内调用 `AttachCurrentThread` 附加到 ArkTS 虚拟机，获得 ani_env；
- 使用语言层 API - e.g. [taskpool](https://gitee.com/openharmony/arkcompiler_runtime_core/blob/OpenHarmony_feature_20250328/static_core/plugins/ets/stdlib/escompat/taskpool.ets).

**注意：`ani_env` 无法跨线程使用**。在lambda 或者 thread function中捕获`ani_env`会导致空指针异常。
参考[第九章](#9-生命周期管理)

### 建议
- 定义一个在其他线程上执行的lambda表达式时，**捕获`ani_vm`而不是`ani_env`**。
- 参考[9.2章节](#92-vm-和-env-生命周期)正确使用`AttachCurrenThread`和`GetEnv`。

## 11 可变长度数组：Array<T> 和 T[]

`Array<T>`和`T[]`在ArkTS中是相同类型，它们在编译后都对应为标准库中的`escompat.Array`类。
这些数组对象可以像普通对象一样通过类实例化、方法调用进行管理。
同时也可以使用ANI层提供的专用函数进行操作：
- `Array_New`：创建一个新数组
- `Array_Set` / `Array_Get`：设置或读取数组中的值
- `Array_Push` / `Array_Pop`

注意：泛型参数会在编译后被擦除，所以在ani层，所有的泛型数组都是统一的`ani_array`类型。

**示例:**

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

## 12 定长数组

定长数组是一种特殊类型，其元素类型在编译阶段不会被擦除 - 意味着`FixedArray<int>`和`FixedArray<double>`在字节码和语言层面是不兼容的。编译器会为不同的元素生成不同的底层结构，因此在native层需要使用**类型匹配的API进行操作**
如 `FixedArray_*`系列API


```cpp
ani_status FixedArray_New_Double(ani_env *env, ani_size length, ani_fixedarray_double *result);
ani_status FixedArray_GetRegion_Double(ani_env *env, ani_fixedarray_double array, ani_size offset, ani_size length, ani_double *native_buffer);
ani_status FixedArray_SetRegion_Double(ani_env *env, ani_fixedarray_double array, ani_size offset, ani_size length, const ani_double *native_buffer);
```
**示例:**

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
`ArrayBuffer` 类型支持两个主要接口：`CreateArrayBuffer` 和 `ArrayBuffer_GetInfo`。

**示例:**

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
// 不是 ani_array
static void HandleDataImpl(ani_env *env, ani_object obj, ani_arraybuffer arraybuffer) {
    void *resultData;
    ani_size resultSize;
    env->ArrayBuffer_GetInfo(arraybuffer, &resultData, &resultSize);
    std::cout << *static_cast<uint32_t*>(resultData) << std::endl;
}
```

完整示例：[ani_arraybuffer.cpp](https://gitee.com/ironrain/ani_cookbook/blob/master/ani_arraybuffer/ani_arraybuffer.cpp)

## 14 枚举
枚举声明属于类（自 3 月 15 日之后），相关方法均可用。

| 标识符 | ANI 类型 | Mangling  |
| ------------- | -------------- | --------------------- |
| `COLOR`       | `ani_enum`     | `E{moduleName.COLOR}` |
| `COLOR.Blue`  | `ani_enum_item`| `C{std.core.Object}`  |

示例：[ani_enum.cpp](https://gitee.com/ironrain/ani_cookbook/blob/master/ani_enum/ani_enum.cpp)

## 15 错误处理 Exception

### 15.1 抛出异常
基类：`Error`
Mangling：`C{escompat.Error}`

若要抛出自定义错误，需继承该基类。

> 注意：系统声明的 `BussinessError` 可能会与 native 构造函数产生绑定冲突。

**示例：**

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

### 15.2 捕获异常

1. 同步情况：
```ts
try {
  nativeThrowError();
} catch (e: Error) {
  console.log(e.message);
}
```

2. 异步情况：使用 `.catch()`

## 16 字符串 String

### 将 `std::string` 转换为 `ani_string`
```cpp
std::optional<ani_string> ANIUtils_StdStringToANIString(ani_env *env, std::string str) {
    ani_string result_string{};
    if (env->String_NewUTF8(str.c_str(), str.size(), &result_string) != ANI_OK) {
        return {};
    }
    return result_string;
}
```

### 将 `ani_string` 转换为 `std::string`
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

## 17 大整数（BigInt）

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

## 18 其余容器类的使用
1. 运用 `FindClass` 依据名称定位目标容器类。
2. 借助 `Class_FindMethod` + `Object_CallMethod` 或者 `Object_CallMethodByName` 来调用内置方法。
3. 按需转换参数和返回值类型。对于复杂类型，可通过方法调用提取基本类型。

### 18.1 Record ：`Lescompat/Record;`

| 函数 | 签名 | 描述 |
|--------------| ----------------------------------------|--------------------|
| `<ctor>`     | `C{std.core.Object}:`                   | Constructor        |
| `$_get`      | `C{std.core.Object}:C{std.core.Object}` | Get value by key   |
| `$_set`      | `C{std.core.Object}:`                   | Set key-value pair |
| `keys`       | `C{escompat.IterableIterator}`          | List keys          |

**示例：** 
```ts
class PersonInfo {
    name: string = "";
    age: number = 0;
}

native callWithRecord(entry: Record<string, PersonInfo>): void;
```

```cpp
void CallWithRecordImpl(ani_env *env, ani_object record) {
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


### 18.3 元组（Tuple）

**示例：** 
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
## 19 错误码分析
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

| 枚举 | 值 | 描述 | 注意事项 |
| ------------------------ | ----- | ------------------------- | --------------------------------- |
| `ANI_OK`                 | 0     | 成功                       |                                   |
| `ANI_ERROR`              | 1     | 通用Error                  | 需要进一步调查                      |
| `ANI_INVALID_ARGS`       | 2     | 无效参数                   | 参数中可能存在空指针                |
| `ANI_INVALID_TYPE`       | 3     | 类型无效                   |  返回值不匹配                       |
| `ANI_INVALID_DESCRIPTOR` | 4     | 描述符无效                 | Mangling 问题                     |
| `ANI_INCORRECT_REF`      | 5     | 引用不正确                 |                                   |
| `ANI_PENDING_ERROR`      | 6     | ArkTS 中抛出异常           | ArkTS-level error                 |
| `ANI_NOT_FOUND`          | 7     | 未找到                     | FindXXX failed                    |
| `ANI_ALREADY_BINDED`     | 8     | 已绑定                     | 重复的 native 绑定                 |
| `ANI_OUT_OF_REF`         | 9     | 引用超出范围               | 数组越界                           |
| `ANI_OUT_OF_MEMORY`      | 10    | 内存不足                   |                                   |
| `ANI_OUT_OF_RANGE`       | 11    | 超出范围                   |                                   |
| `ANI_BUFFER_TO_SMALL`    | 12    |  缓冲区过小                |                                   |
| `ANI_INVALID_VERSION`    | 13    | 版本无效                   | 常见于 VM 创建时                   |
| `ANI_AMBIGUOUS`          | 14    | 存在歧义                   | 避免在签名中使用 nullptr            |

### 19.1 错误码 2：`ANI_INVALID_ARGS`
这表明的某个参数是非法的 `nullptr`。
示例：
```cpp
Object_CallMethodByName_Boolean(nullptr, ...);
```

### 19.2 错误码 6：`ANI_PENDING_ERROR`
这意味着 ArkTS 运行时抛出了异常。
可使用以下代码捕获并描述该异常：

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


### 19.3 错误码 7：`ANI_NOT_FOUND`
要确保 `.d.ets` 和 `.ets` 文件完全一致。否则，native 方法在设备上可能总是失败。
```ts
// .d.ets 文件
class A {
    foo(i: int): void // 不匹配
}

// .ets 文件
class A {
    foo(): void // 不匹配
}
```

### 19.4 错误码 14：`ANI_AMBIGUOUS`

当存在重载且在 mangling 中使用 `nullptr` 时会出现此错误：

```cpp
// .ets 文件
function foo(i: int): void
function foo(d: number): void

// .cpp 文件
FindMethod(cls, "foo", nullptr, &method); // 错误
FindMethod(cls, "foo", "d:", &method);   // 正确
```

## 20. 常见问题解答（FAQ）
- **BussinessError无法创建或行为异常**：检查是否存在`BussinessError$partial`。系统可能包含内置的`BussinessError`，这会在ABC文件中引发冲突。请联系前端和标准库的维护人员。
- **`Object_New`后程序崩溃**：通常是由于参数类型不匹配。在查找构造函数时，绝不要使用`nullptr`作为签名。
- **声明和实现不匹配**：`.d.ets`和`.ets`文件之间的不一致会导致字段或方法无法识别。
- **`ani_boolean`无法正确打印**：它被定义为`uint8_t`，而不是`bool`。在输出前需要将其转换为`int`。
- **如何将`ani_int`/`ani_double`转换为`ani_ref`？**：先将它们装箱为`ani_object`，然后再转换为`ani_ref`。详见3.3节。
- **如何在ETS垃圾回收（GC）时为native清理注册析构函数？**：目前不支持自动注册。必须在ETS中通过垃圾回收手动触发。
- **为什么ETS中的两个不同函数在native中具有相同的地址？**：native函数参数在内部使用固定指针槽。它们的地址会被复用。
- **如何在native中比较两个ETS函数参数？**：使用`GlobalReference_Create`保留`ani_ref`，并通过`Reference_StrictEquals`进行比较。
- **`Reference_StrictEquals`对不同实例返回`true`？**：对于像`String`这样的基本类型包装器，比较是基于内容的。对于自定义类，则是基于地址进行比较。
- **`String_GetUTF8SubString`在长度不足时会截断字符吗？**：会的。如果字节范围未覆盖完整字符，UTF - 8子字符串将被截断。
- **为什么`Object_New`返回`ANI_INVALID_TYPE`？**：确保精确匹配构造函数的参数类型（例如，对于`long`类型的参数，使用`ani_long`）。
- **如何为`Promise<void>`函数编写`resolve`和`reject`？**：不支持这种操作。请更改为有返回类型的版本。
- **如何在设备上执行`.abc`文件并测试API？**：通过GN构建运行时，然后通过以下命令执行：
```
export LD_LIBRARY_PATH=.;
/path/to/ark --boot-panda-files=etsstdlib.abc --load-runtimes=ets run.abc run.ETSGLOBAL::main
```
- **构造函数支持可选参数吗？**：支持，通过重载实现。将每个重载绑定为一个单独的native构造函数。
- **为什么无法在命名空间方法中检索可选参数？**：使用`Namespace_BindNativeFunctions`时，不要将类对象作为第二个参数传递。
- **在命名空间绑定的native代码中访问联合类型时出现问题**：同样，在`Namespace_BindNativeFunctions`中，不要将类对象作为第二个参数传递。
- **声明并传递的参数在native中仍然为`nullptr`**：请检查1.1节中的native绑定是否有误。
- **调用`Record.keys()`导致错误代码14**：添加正确的签名`:Lescompat/IterableIterator;`以解决歧义。
