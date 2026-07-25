# 方舟字节码函数命名规则

<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @jokerxd-liu; @zmw1-->
<!--Designer: @huyunhui1; @oatuwwutao-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

## 概述
本文介绍方舟字节码文件中[Method](arkts-bytecode-file-format.md#method)的`name_off`字段指向的字符串的命名规则，该命名规则从方舟字节码文件版本`12.0.4.0`开始生效。
## 入口函数
模块加载时被执行的函数，名称固定为`func_main_0`。
## 非入口函数
其他函数在字节码文件中的名称结构如下：
```ts
#前缀#原函数名
```
下面的章节将会详细介绍[前缀](#前缀)和[原函数名](#原函数名)。
### 前缀
前缀由一个或多个作用域层级和函数自身的作用域标签依次拼接组成。每个作用域层级包含三部分：作用域标签、作用域名称和重名序号（可选）。结构如下：

```text
作用域标签1  作用域名称1  [重名序号]  ...  作用域标签n  作用域名称n  [重名序号]  函数作用域标签
```

其中：
- 各部分直接拼接，无分隔符。
- `[]`表示其中的内容可以为空。仅当出现重名作用域时才需要重名序号，否则省略。
- 最后的"函数作用域标签"是本函数所对应的标签，不包含作用域名称和重名序号。
 
**作用域标签**
 
作用域标签表示作用域的类型。作用域和对应的作用域标签如下表所示，其他的作用域不会被记录进函数名中：
| 作用域 | 作用域标签 | 说明 |
| --- | --- | --- |
| class | `~` | `class`关键字定义的作用域。 |
| 实例函数 | `>` | 类的实例成员函数定义的作用域。 |
| 静态函数 | `<` | 类的静态成员函数定义的作用域。 |
| 构造函数 | `=` | 类的构造函数定义的作用域。 |
| 普通函数 | `*` | 除了以上类型的其它所有函数定义的作用域。 |
| namespace/module | `&` | `namespace`或`module`关键字定义的作用域。 |
| enum | `%` | `enum`关键字定义的作用域。 |
 
**作用域名称**
 
源代码中定义作用域时所使用的名称。匿名则为空字符串。为了降低字节码体积，方舟编译器会对较长的作用域名称进行优化，此时作用域名称以`@十六进制数字`的形式体现。这个数字代表作用域名称的字符串在一个字符串数组中的索引：在方舟字节码文件中源代码对应的[Class](arkts-bytecode-file-format.md#class)中有一个名为`scopeNames`的[field](arkts-bytecode-file-format.md#field), 这个field的值是指向一个[LiteralArray](arkts-bytecode-file-format.md#literalarray)的偏移，这个LiteralArray存储的是一个字符串数组。十六进制数字就是代表作用域名称在这个数组中的索引。原函数名不进行索引转换。

例子：
<!-- @[scope_name](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTSCompilationToolchain/ArkBytecode/FundamentalsAndNamingConventions/entry/src/main/ets/pages/ScopeName.ts) -->    

``` TypeScript
// ScopeName.ts
function longFuncName() { // longFuncName的函数名为"#*#longFuncName"，其中"longFuncName"是原函数名，不会转换为索引
  function A() { } // A的函数名"#*@0*#A"，其中"@0"表示在其对应LiteralArray中，索引为0的字符串，此时这个字符串是"longFuncName"。即这个函数原本的名称为"#*longFuncName*#A"
  function B() { } // B的函数名"#*@0*#B"
}
```
**重名序号**
 
如果源码中相同作用域下出现了同名的实体，同名的名称后会加上重名序号，重名序号以`^十六进制数字`的形式表示。出现重名时，第一个不编号（即重名序号为空），从第二个开始编号，编号从`1`开始。

例子：
<!-- @[renaming_index](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTSCompilationToolchain/ArkBytecode/FundamentalsAndNamingConventions/entry/src/main/ets/pages/Index.ets) --> 

``` TypeScript
namespace A {
  function bar() { } // bar的函数名为"#&A*#bar"
}

namespace A {
  function foo() { } // foo的函数名为"#&A^1*#foo"，其中"^1" 为重名序号
}
```
### 原函数名
原函数名代表函数在源代码中的名字，匿名函数的名称为空字符串。同样的，如果源码中相同作用域下出现了同名的函数，重名的名称后面会加上重名序号（包括匿名函数）。

<!-- @[original_function_name](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTSCompilationToolchain/ArkBytecode/FundamentalsAndNamingConventions/entry/src/main/ets/pages/Index.ets) --> 

``` TypeScript
function foo() {}; // 原函数名为"foo"
() => { }; // 原函数名为""
() => { }; // 原函数名为"^1"
```

 
**特殊情况**
 
1. 如果匿名函数被赋值给一个变量，该变量名即为函数名。例如：
   <!-- @[special_function_variable](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTSCompilationToolchain/ArkBytecode/FundamentalsAndNamingConventions/entry/src/main/ets/pages/Index.ets) --> 
   
   ``` TypeScript
   let a = () => {} // 原函数名为"a"
   ```

2. 如果匿名函数在对象字面量中定义并且被赋值给了一个字面量属性：
* 如果属性名中不包含`\`和`.`，则其原函数名即为该属性名。
   <!-- @[special_without_slash_period](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTSCompilationToolchain/ArkBytecode/FundamentalsAndNamingConventions/entry/src/main/ets/pages/DuplicateName.ts) -->  
   
   ``` TypeScript
   // DuplicateName.ts
   let B = {
     b : () => {} // 原函数名为"b"
   }
   ```

* 如果属性名包含`\`或`.`，为防止二义性，其原函数名会按照匿名函数命名。
   <!-- @[special_with_slash_period](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTSCompilationToolchain/ArkBytecode/FundamentalsAndNamingConventions/entry/src/main/ets/pages/OriginalFuncName.ts) -->  

   ``` TypeScript
   // OriginalFuncName.ts
   let a = {
     "a.b#c^2": () => {}, // 原函数名为""
     "x\\y#": () => {} // 原函数名为"^1"
   }
   ```

**开发者应尽量避免使用除字母、数字、下划线以外的字符命名函数，以免出现二义性。**
## 示例
<!-- @[avoid_use](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTSCompilationToolchain/ArkBytecode/FundamentalsAndNamingConventions/entry/src/main/ets/pages/Index.ets) --> 

``` TypeScript
namespace A { // namespace在字节码中的函数名为"#&#A"
  class B { // 构造函数在字节码中的函数名为"#&A~B=#B"
    m() { // 函数m在字节码中的函数名为"#&A~B>#m"
      return () => {} // 匿名函数在字节码中的函数名为"#&A~B>m*#"
    }
    static s() {} // 静态函数s在字节码中的函数名为"#&A~B<#s"
  }
  enum E { // enum在字节码中的函数名为"#&A%#E"

  }
}
```