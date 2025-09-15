# Naming Conventions for Ark Bytecode Functions

<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @huyunhui1; @oh-rgx1; @zmw1-->
<!--Designer: @ctw-ian; @hufeng20-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @foryourself-->

## Overview
This topic describes the naming conventions for the strings pointed to by the `name_off` field in [methods](arkts-bytecode-file-format.md#method) of bytecode files. These conventions apply to Ark bytecode files of version `12.0.4.0` or later.
## Entry Function
Function executed during module loading. The function name is fixed at **func_main_0**.
## Non-Entry Function
The naming structure for other functions in the bytecode file is as follows:
```ts
##prefix#original_function_name
```
The following sections describe the prefix and original function name in detail.
### Prefix
The prefix includes information about the scope where the function is defined, including:
* Scope tag
* Scope name
* Renaming index (if applicable)

The prefix structure is as follows:
```ts
<Scope tag 1><Scope name 1>[<Renaming index>]<Scope tag 2><Scope name 2><[Renaming index]>...<Scope tag n><Scope name n>[<Renaming index >]<Scope tag n+1>
```
Here, angle brackets (< >) are delimiters for readability and are not part of the actual prefix, and square brackets ([ ]) indicates optional elements. [\<Renaming index>] is only included if there are duplicate scope names and can be empty otherwise. The last scope tag corresponds to the function itself.
 
**Scope Tag**
 
Scope tags indicate the type of scope. The table below lists the scopes and their corresponding tags. Other scopes are not included in function names.
| Scope| Scope Tag| Description|
| --- | --- | --- |
| class | `~` | Scope defined by the **class** keywords.|
| Instance function| `>` | Scope defined by the instance member functions in a class.|
| Static function| `<` | Scope defined by the static functions in a class.|
| Constructor function| `=` | Scope defined by the constructors in a class.|
| Ordinary function| `*` | Scope defined by all functions except the preceding types.|
| namespace/module | `&` | Scope defined by the **namespace** or **module** keywords.|
| enum | `%` | Scope defined by the **enum** keywords.|
 
**Scope Name**
 
Scope names indicate the name used to define the scope in the source code. If the scope is anonymous, it is an empty string. To reduce the bytecode size, the Ark compiler optimizes longer scope names, representing them as @ followed by a hexadecimal number. This hexadecimal number is the index of the scope name in a string array. In the bytecode file, there is a [field](arkts-bytecode-file-format.md#field) named **scopeNames** in the [class](arkts-bytecode-file-format.md#class) corresponding to the source code. This **field** value points to an offset of a [LiteralArray](arkts-bytecode-file-format.md#literalarray) storing the string array. The hexadecimal number is the index of the scope name in this array. The original function name is not converted to an index.
Example:
```ts
// test1.ts
function longFuncName() {                  // The function name of longFuncName is "#*#longFuncName", where "longFuncName" is the original function name and will not be converted to an index.
    function A() { }                       // The function name of A is "#*@0*#A", where "@0" indicates the string whose index is 0 in the corresponding LiteralArray. In this case, the string is "longFuncName", which means that the original name of this function is "#*longFuncName*#A".
    function B() { }                       // The function name of B is "#*@0*#B".
}  
```
 
**Renaming Index**
 
If the source code contains entities with the same name in the same scope, a renaming index is appended to the duplicate names. The renaming index is represented as ^ followed by a hexadecimal number. For the first occurrence, no index is added (the renaming index is empty), and subsequent occurrences start from 1.

Example:
```ts
namespace A {
    function bar() { }                      // The function name of bar is "#&A*#bar".
}

namespace A {
    function foo() { }                      // The function name of foo is "#&A^1*#foo", where "^1" indicates the renaming index.
}
```
### Original Function Name
The original function name represents the name of the function in the source code. For anonymous functions, it is an empty string. Similarly, if there are duplicate function names in the same scope, a renaming index is appended to the duplicate names, including anonymous functions.

```ts
function foo() {};                           // The original function name is "foo".
() => { };                                   // The original function name is "".
() => { };                                   // The original function name is "^1".
```

 
**Special Cases**
 
1. If an anonymous function is assigned to a variable, the variable name is the function name. For example:
    ```ts
    let a = () => {}                            // The original function name is "a".
    ```
2. If an anonymous function is defined in an object literal and assigned to a literal property, the following cases are possible:
* If the property name does not contain a slash (`\`) or a period (`.`), the original function name is the property name.
    ```ts
    // test2.ts
    let B = {
        b : () => {}                            // The original function name is "b".
    }
    ```
* If the property name contains a slash (`\`) or a period (`.`), the original function name follows the naming convention for anonymous functions to avoid ambiguity.
    ```ts
    // test3.ts
    let a = {
        "a.b#c^2": () => {},                     // The original function name is "".
        "x\\y#": () => {}                       // The original function name is "^1".
    }
    ```

**You should avoid using characters other than letters, digits, and underscores (_) in function names to avoid ambiguity.**
## Examples
```ts
namespace A {                               // The function name of the namespace in bytecode is "#&#A".
    class B {                               // The function name of the constructor in bytecode is "#&A~B=#B".
        m() {                               // The function name of the function m in bytecode is "#&A~B>#m".
            return () => {}                 // The function name of the anonymous function in bytecode is "#&A~B>m*#".
        }
        static s() {}                       // The function name of the static function s in bytecode is "#&A~B<#s".
    }
    enum E {                                // The function name of the enum in bytecode is "#&A %#E".

    }
}
```
