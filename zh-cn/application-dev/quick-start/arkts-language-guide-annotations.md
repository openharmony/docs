# 注解
<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao; @cy917474985-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

注解（Annotation）是ArkTS的语言特性，通过添加元数据来改变应用声明的语义。本章介绍注解的声明、使用、导入导出及源码态注解等内容。

## 注解的基础概念

### 注解的定义与作用

注解通过`@interface`声明，以`@`前缀使用，为类和方法等声明添加元信息。注解不是TypeScript中的特性，只能在`.ets/.d.ets`文件中使用。

### 注解的声明与使用

注解的声明使用`@interface`关键字，使用时以`@`为前缀。

<!-- @[annotation_statement](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/IntroductionToArkTS/entry/src/main/ets/pages/Annotation.ets) -->

``` TypeScript
// 注解的声明：
@interface ClassAuthor {
  authorName: string;
}

// 注解的使用：
@ClassAuthor({authorName: "Bob"})
class MyClass {
  // ...
}
```

- 使用`@interface`声明注解。
- 注解`ClassAuthor`需要将元信息添加到类声明中。
- 注解必须放置在声明之前。
- 注解可以包含上述示例中所示的参数。

对于要使用的注解，其名称必须以符号`@`（例如：@MyAnno）为前缀。

``` TypeScript
ClassAuthor({authorName: "Bob"}) // 编译错误：注解需要'@'为前缀
```

如果在使用位置无法访问注解名称，则会发生编译错误。

注解声明可以导出并在其他文件中使用。

多个注解可以应用于同一个声明（注解间的先后顺序不影响使用）。

<!-- @[annotation_statement_multiple](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/IntroductionToArkTS/entry/src/main/ets/pages/Annotation.ets) -->

``` TypeScript
@MyAnno()
@ClassAuthor({authorName: "John Smith"})
class MyClass1 {
  // ...
}
```

> **注意**
>
> 应用开发中，在[release模式下构建](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-hvigor-build-har#section19788284410)源码HAR，并同时[开启混淆](../../application-dev/arkts-utils/source-obfuscation.md)时，由于编译产物为JS文件，而在JS中没有注解的实现机制，因此会在编译过程中被移除，导致无法通过注解实现AOP插桩。
>
> 为避免因此引起的功能异常，禁止在JS HAR(编译产物中存在JS的HAR包)中使用注解。
>
> 如果需要在release模式并且开启混淆的情况下构建含有注解的HAR包，可以构建[字节码HAR](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-hvigor-build-har#section16598338112415)。

## 用户自定义注解

**从API version 20及之后版本，支持用户自定义注解。**

### 注解的声明规则

用户自定义注解的定义与`interface`的定义类似，其中的`interface`关键字以符号`@`为前缀。

注解字段仅限于下面列举的类型：

* number
* boolean
* string
* 枚举
* 以上类型的数组

> **说明：**
> 
> - 如果使用其他类型用作注解字段的类型，则会发生编译错误。
> - 注解字段类型不支持bigint。

注解字段的默认值必须使用常量表达式来指定。常量表达式的场景如下所示：

* 数字字面量
* 布尔字面量
* 字符串字面量
* 枚举值（需要在编译时确定值）
* 以上常量组成的数组

> **说明：**
> 
> 如果枚举值不能在编译时确定，会编译报错。

``` TypeScript
// a.ts
export enum X {
  x = foo(); // x不是编译时能确定的常量
}

// b.ets
import {X} from './a';

@interface Position {
  data: number = X.x; // 编译错误：注解字段的默认值必须使用常量表达式
}
```

注解必须定义在顶层作用域（top-level），否则会出现编译报错。

注解的名称不能与注解定义所在作用域内可见的其他实体名称相同，否则会出现编译报错。

注解不支持TypeScript中的合并，否则会出现编译报错。

``` TypeScript
namespace ns {
  @interface MetaInfo { // 编译错误：注解必须定义在顶层作用域
    // ...
  }
}

@interface Position {
  // ...
}

class Position { // 编译错误：注解的名称不能与注解定义所在作用域内可见的其他实体名称相同
  // ...
}

@interface ClassAuthor {
  name: string;
}

@interface ClassAuthor { // 编译错误：注解的名称不能与注解定义所在作用域内可见的其他实体名称相同
  data: string;
}
```

注解不是类型，把注解当类型使用时会出现编译报错（例如：对注解使用类型别名）。

``` TypeScript
@interface Position {}
type Pos = Position; // 编译错误：注解不是类型
```

注解不支持在类的getter和setter方法中添加，若添加注解会编译报错。

``` TypeScript
@interface ClassAuthor {
  authorName: string;
}

@ClassAuthor({authorName: 'John Smith'})
class MyClass {
  private _name: string = 'Bob';

  @ClassAuthor({authorName: 'John Smith'}) // 编译错误：注解不支持在类的getter和setter方法添加
  get name() {
    return this._name;
  }

  @ClassAuthor({authorName: 'John Smith'}) // 编译错误：注解不支持在类的getter和setter方法添加
  set name(authorName: string) {
    this._name = authorName;
  }
}
```

### 注解的使用方式

当前仅允许对`class declarations`和`method declarations`使用注解，对类和方法可以同时使用同一个注解。

<!-- @[annotation_usages_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/IntroductionToArkTS/entry/src/main/ets/pages/Annotation.ets) -->

``` TypeScript
@ClassPreamble({authorName: "John", revision: 2})
class C1 {
  // ...
}


@ClassPreamble({authorName: "Bob"}) // revision的默认值为1
class C2 {
  // ...
}

@MyAnno() // 对类和方法可以同时使用同一个注解
class C3 {
  @MyAnno()
  foo() {}
  @MyAnno()
  static bar() {}
}
```

注解声明示例如下：

<!-- @[annotation_statement_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/IntroductionToArkTS/entry/src/main/ets/pages/Annotation.ets) -->

``` TypeScript
@interface ClassPreamble {
  authorName: string;
  revision: number = 1;
}
@interface MyAnno {}
```

注解中的字段顺序不影响使用。

<!-- @[annotation_field_order](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/IntroductionToArkTS/entry/src/main/ets/pages/Annotation.ets) -->

``` TypeScript
@ClassPreamble1({authorName: "John", revision: 2})
// ...
// the same as:
@ClassPreamble1({revision: 2, authorName: "John"})
```

使用注解时，必须给所有没有默认值的字段赋值，否则会发生编译错误。

> **说明：**
> 
> 赋值应当与注解声明的类型一致，所赋的值与注解字段默认值的要求一样，只能使用常量表达式。

``` TypeScript
@ClassPreamble() // 编译错误：authorName字段未定义
class C1 {
  // ...
}
```

如果注解中定义了数组类型的字段，则使用数组字面量来设置该字段的值。

<!-- @[annotation_array](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/IntroductionToArkTS/entry/src/main/ets/pages/Annotation.ets) -->

``` TypeScript
@interface ClassPreamble2 {
  authorName: string;
  revision: number = 1;
  reviewers: string[];
}

@ClassPreamble2(
{
  authorName: "Alice",
  reviewers: ["Bob", "Clara"]
}
)
class C0 {
  // ...
}
```

如果不需要定义注解字段，可以省略注解名称后的括号。

<!-- @[annotation_omit](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/IntroductionToArkTS/entry/src/main/ets/pages/Annotation.ets) -->

``` TypeScript
@MyAnno
class C4 {
  // ...
}
```

## 注解的导入与导出

注解也可以被导入导出。针对导出，当前仅支持在定义时的导出，即`export @interface`的形式。

<!-- @[annotation_export](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/IntroductionToArkTS/entry/src/main/ets/pages/Annotation.ets) -->

``` TypeScript
export @interface MyAnno1 {}
```

针对导入，当前仅支持`import {}`和`import * as`两种方式。

<!-- @[annotation_export_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/IntroductionToArkTS/entry/src/main/ets/pages/MyAnno.ets) -->

``` TypeScript
// MyAnno.ets
export @interface MyAnno2 {}
export @interface ClassAuthor2 {}
```

<!-- @[annotation_export_example_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/IntroductionToArkTS/entry/src/main/ets/pages/Annotation.ets) -->

``` TypeScript
// Annotation.ets
import { MyAnno2 } from './MyAnno';
import * as ns from './MyAnno';
// ...
@MyAnno2
@ns.ClassAuthor2
class C {
  // ...
}
```

- 不允许在import中对注解进行重命名。

``` TypeScript
import { MyAnno as Anno } from './a'; // 编译错误：不允许在import中对注解进行重命名
```

不允许对注解使用任何其他形式的import/export，这会导致编译报错。

- 由于注解不是类型，因此禁止使用`type`符号进行导入和导出。

``` TypeScript
import type { MyAnno } from './a'; // 编译错误：注解不允许使用'type'符号进行导入和导出
```

- 如果仅从模块导入注解，则不会触发模块的副作用。

<!-- @[annotation_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/IntroductionToArkTS/entry/src/main/ets/pages/MyAnno.ets) -->

``` TypeScript
// MyAnno.ets
export @interface Anno {}

export @interface ClassAuthor1 {}

console.info('hello');
```

<!-- @[annotation_import_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/IntroductionToArkTS/entry/src/main/ets/pages/Annotation.ets) -->

``` TypeScript
// Annotation.ets
import { MyAnno2 } from './MyAnno';
import * as ns from './MyAnno';
// 仅引用了Anno注解，不会导致MyAnno.ets的console.info执行
class X {
  // ...
}
```

## .d.ets文件中的注解

注解可以出现在.d.ets文件中。可以在.d.ets文件中用环境声明（ambient declaration）来声明注解。

``` TypeScript
ambientAnnotationDeclaration:
  'declare' userDefinedAnnotationDeclaration
  ;
```

<!-- @[annotation_export_dts](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/IntroductionToArkTS/entry/src/main/ets/pages/NameAnno.d.ets) -->

``` TypeScript
// NameAnno.d.ets
export declare @interface ClassAuthor3 {}
```

上述声明中：
- 不会引入新的注解定义，而是提供注解的类型信息。
- 注解需定义在其他源代码文件中。
- 注解的环境声明和实现需要完全一致，包括字段的类型和默认值。

<!-- @[annotation_name](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/IntroductionToArkTS/entry/src/main/ets/pages/NameAnno.d.ets) -->

``` TypeScript
// NameAnno.d.ets
export declare @interface NameAnno{name: string = ""}
```

<!-- @[annotation_interface](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/IntroductionToArkTS/entry/src/main/ets/pages/MyAnno.ets) -->

``` TypeScript
// MyAnno.ets
export @interface NameAnno{name: string = ""} // ok
```

环境声明的注解和class类似，也可以被import使用。

<!-- @[annotation_anno](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/IntroductionToArkTS/entry/src/main/ets/pages/NameAnno.d.ets) -->

``` TypeScript
// NameAnno.d.ets
export declare @interface MyAnno {}
```

<!-- @[annotation_class](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/IntroductionToArkTS/entry/src/main/ets/pages/ImportMyAnno.ets) -->

``` TypeScript
// ImportMyAnno.ets
import { MyAnno } from './NameAnno';

@MyAnno
class C {
  // ...
}
```

### 编译器自动生成的.d.ets文件

当编译器根据ets代码自动生成.d.ets文件时，存在以下2种情况。

1. 当注解定义被导出时，源代码中的注解定义会在.d.ets文件中保留。

   <!-- @[annotation_autoGenerate_dts](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/IntroductionToArkTS/entry/src/main/ets/pages/MyAnno.ets) -->

   ``` TypeScript
   // MyAnno.ets
   export @interface ClassAuthor5 {}

   @interface MethodAnno { // 没导出
     data: number;
   }
   ```

   <!-- @[annotation_export_dts](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/IntroductionToArkTS/entry/src/main/ets/pages/NameAnno.d.ets) -->

   ``` TypeScript
   // NameAnno.d.ets
   export declare @interface ClassAuthor3 {}
   ```

2. 当下面所有条件成立时，源代码中实体的注解实例会在.d.ets文件中保留。

  - 2.1 注解的定义被导出（import的注解也算作被导出）。
  - 2.2 如果实体是类，则类被导出。
  - 2.3 如果实体是方法，则类被导出，并且方法不是私有方法。

   <!-- @[annotation_export_autoGenerate_dts](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/IntroductionToArkTS/entry/src/main/ets/pages/MyAnno.ets) -->

   ``` TypeScript
   // MyAnno.ets
   import { ClassAuthor4 } from './Author';

   export @interface MethodAnno4 {
     data: number = 0;
   }

   @ClassAuthor4
   class MyClass {
     @MethodAnno4({data: 123})
     foo() {}

     @MethodAnno4({data: 456})
     private bar() {}
   }
   ```

   <!-- @[annotation_export_autoGenerate_dts](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/IntroductionToArkTS/entry/src/main/ets/pages/NameAnno.d.ets) -->

   ``` TypeScript
   // NameAnno.d.ets 编译器生成的声明文件
   import { ClassAuthor4 } from './Author';

   export declare @interface MethodAnno4 {
     data: number = 0;
   }

   @ClassAuthor4
   export declare class MyClass {
     @MethodAnno4({data: 123})
     foo(): void;

     bar; // 私有方法不保留注解
   }
   ```

### 开发者生成的.d.ets文件

开发者生成的.d.ets文件中的注解信息不会自动应用到实现的源代码中。

<!-- @[annotation_developerGenerate_dts](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/IntroductionToArkTS/entry/src/main/ets/pages/NameAnno.d.ets) -->

``` TypeScript
// NameAnno.d.ets 开发者生成的声明文件
@interface ClassAuthor6 {}

@ClassAuthor6 // 声明文件中有注解
class C {
  // ...
}
```

<!-- @[annotation_developerGenerate_dts](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/IntroductionToArkTS/entry/src/main/ets/pages/MyAnno.ets) -->

``` TypeScript
// MyAnno.ets 开发者对声明文件实现的源代码
@interface ClassAuthor6 {}

// 实现文件中没有注解
class C {
  // ...
}
```

在最终编译产物中，class C没有注解。

## 重复注解与继承

同一个实体不能重复使用同一注解，否则会导致编译错误。

``` TypeScript
@MyAnno({name: "123", value: 456})
@MyAnno({name: "321", value: 654}) // 编译错误：不允许重复注解
class C {
  // ...
}
```

子类不会继承基类的注解，也不会继承基类方法的注解。

## 注解与抽象类、抽象方法

不支持对抽象类或抽象方法使用注解，否则将导致编译错误。

``` TypeScript
@MyAnno // 编译错误：不允许在抽象类和抽象方法上使用注解
abstract class C {
  @MyAnno
  abstract foo(): void; // 编译错误：不允许在抽象类和抽象方法上使用注解
}
```

## 源码态注解

从API version 24开始，支持用户自定义源码态注解。

源码态注解为一类特殊形式的注解。源码态注解的生命周期只在编译期，不会影响编译产物。

开发者可以通过使用ArkTS提供的[Retention](../reference/apis-arkts/js-apis-arkts-lang.md#retention24)接口来构造自定义源码态注解。源码态注解有更广的使用范围，支持在以下声明上使用：

- 类
- 类成员（除构造函数外）
- 变量声明
- 接口
- 接口成员
- 注解
- 函数
- 命名空间
- 类型别名
- 枚举

源码态注解的声明和使用示例如下所示：

<!-- @[annotation_source_retention_annotation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/IntroductionToArkTS/entry/src/main/ets/pages/SourceRetentionAnnotation.ets) -->

``` TypeScript
import { Retention, RetentionPolicy } from '@kit.ArkTS';

// 构造用户自定义源码态注解
@Retention({policy: RetentionPolicy.SOURCE})
@interface SourceAnnotation {}
// 源码态注解可以在类和类成员上使用
@SourceAnnotation
class C {
  @SourceAnnotation
  private name_: string = '';
  @SourceAnnotation
  get name(): string {
    return this.name_;
  }
}
// 源码态注解可以在变量声明上使用
@SourceAnnotation
let a = 1;
// 源码态注解可以在接口和接口成员上使用
@SourceAnnotation
interface I {
  @SourceAnnotation
  foo(): void
}
// 源码态注解可以在注解上使用
@SourceAnnotation
@interface Anno {}
// 源码态注解可以在函数上使用
@SourceAnnotation
function func () {}
// 源码态注解可以在命名空间上使用
@SourceAnnotation
namespace ns {}
// 源码态注解可以在类型别名上使用
@SourceAnnotation
type A = number;
// 源码态注解可以在枚举上使用
@SourceAnnotation
enum ColorSet { RED, GREEN, BLUE }
```

## ArkTS限制

### 注解仅在.ets/.d.ets文件中可用

注解不是TypeScript中的特性，只能在`.ets/.d.ets`文件中使用。在`.ts`文件中无法声明或使用注解。

### 注解不是类型

注解不能作为类型使用，不能对注解使用类型别名，否则会出现编译报错。

### 注解不支持在getter和setter上使用

注解不支持在类的getter和setter方法中添加，若添加注解会编译报错。

### 不允许重复注解

同一个实体不能重复使用同一注解，否则会导致编译错误。

### 注解不能用于抽象类和抽象方法

不支持对抽象类或抽象方法使用注解，否则将导致编译错误。

### 子类不继承注解

子类不会继承基类的注解，也不会继承基类方法的注解。
