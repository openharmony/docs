# Annotations

<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao; @cy917474985-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=c25b60c237b212cfc232b5aee67d2c42ba90278a translatedAt=2026-08-13T08:51:39.319Z pushedAt=2026-08-13T12:23:33.536Z -->

Annotation is a language feature of ArkTS that changes the semantics of app declarations by adding metadata. This chapter describes the declaration, usage, import and export, and source-state annotations.

## Basic Concepts of Annotations

### Definition and Purpose of Annotations

Annotations are declared with `@interface` and used with the `@` prefix to add metadata to declarations such as classes and methods. Annotations are not a TypeScript feature and can only be used in `.ets` and `.d.ets` files.

### Declaring and Using Annotations

Annotations are declared with the `@interface` keyword and used with the `@` prefix.

<!-- @[annotation_statement](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/IntroductionToArkTS/entry/src/main/ets/pages/Annotation.ets) -->

``` TypeScript
// Declare an annotation.
@interface ClassAuthor {
  authorName: string;
}

// Use an annotation.
@ClassAuthor({authorName: "Bob"})
class MyClass {
  // ...
}
```

- Declare an annotation with `@interface`.

- The `ClassAuthor` annotation adds metadata to a class declaration.

- An annotation must be placed before the declaration.

- An annotation can contain parameters as shown in the preceding example.

To use an annotation, its name must be prefixed with the symbol `@` (for example, @MyAnno).

``` TypeScript
ClassAuthor({authorName: "Bob"}) // Compilation error: annotations must be prefixed with '@'
```

A compilation error occurs if the annotation name is not accessible at the usage location.

Annotation declarations can be exported and used in other files.

Multiple annotations can be applied to the same declaration (the order of annotations does not affect their usage).

<!-- @[annotation_statement_multiple](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/IntroductionToArkTS/entry/src/main/ets/pages/Annotation.ets) -->

``` TypeScript
@MyAnno()
@ClassAuthor({authorName: "John Smith"})
class MyClass1 {
  // ...
}
```

> **NOTE**
>
> During app development, when a source HAR is built in [release mode](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-hvigor-build-har#section19788284410) with [obfuscation](../../application-dev/arkts-utils/source-obfuscation.md) enabled at the same time, the build output is a JS file. Since JS has no annotation implementation mechanism, annotations are removed during compilation, making it impossible to implement AOP instrumentation through annotations.
>
> To avoid functional exceptions caused by this, using annotations in a JS HAR (a HAR package whose build output contains JS) is prohibited.
>
> If you need to build a HAR package containing annotations in release mode with obfuscation enabled, you can build a [bytecode HAR](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-hvigor-build-har#section16598338112415).

## User-defined Annotations

**Since API version 20, user-defined annotations are supported.**

### Annotation Declaration Rules

The definition of a user-defined annotation is similar to that of an `interface`, except that the `interface` keyword is prefixed with `@`.

Annotation fields are limited to the following types:

* number

* boolean

* string

* enum

* arrays of the preceding types

> **NOTE**
> 
> - If any other type is used as the type of an annotation field, a compilation error occurs.
> - The `bigint` type is not supported for annotation fields.

The default value of an annotation field must be specified using a constant expression. The scenarios of constant expressions are as follows:

* Numeric literal

* Boolean literal

* String literal

* Enumeration value (the value must be determined at compile time)

* An array composed of the constants above

> **NOTE**
>
> A compilation error occurs if the value of an enum cannot be determined at compile time.

``` TypeScript
// a.ts
export enum X {
  x = foo(); // x is not a constant that can be determined at compile time.
}

// b.ets
import {X} from './a';

@interface Position {
  data: number = X.x; // Compilation error: the default value of an annotation field must use a constant expression.
}
```

An annotation must be defined in the top-level scope, otherwise a compilation error occurs.

The name of an annotation must not be the same as the name of any other entity visible in the scope where the annotation is defined, otherwise a compilation error occurs.

Annotations do not support merging in TypeScript; otherwise, a compilation error occurs.

``` TypeScript
namespace ns {
  @interface MetaInfo { // Compilation error: annotations must be defined in the top-level scope.
    // ...
  }
}

@interface Position {
  // ...
}

class Position { // Compilation error: the name of an annotation cannot be the same as that of any other entity visible in the scope where the annotation is defined.
  // ...
}

@interface ClassAuthor {
  name: string;
}

@interface ClassAuthor { // Compilation error: the name of an annotation cannot be the same as that of any other entity visible in the scope where the annotation is defined.
  data: string;
}
```

An annotation is not a type. Using an annotation as a type causes a compilation error (for example, using a type alias for an annotation).

``` TypeScript
@interface Position {}
type Pos = Position; // Compilation error: annotations are not types.
```

Annotations are not supported on getter and setter methods of a class. Adding an annotation to them causes a compilation error.

``` TypeScript
@interface ClassAuthor {
  authorName: string;
}

@ClassAuthor({authorName: 'John Smith'})
class MyClass {
  private _name: string = 'Bob';

  @ClassAuthor({authorName: 'John Smith'}) // Compilation error: annotations are not supported on getter and setter methods of a class.
  get name() {
    return this._name;
  }

  @ClassAuthor({authorName: 'John Smith'}) // Compilation error: annotations are not supported on getter and setter methods of a class.
  set name(authorName: string) {
    this._name = authorName;
  }
}
```

### Using Annotations

Currently, annotations can be used only on `class declarations` and `method declarations`. The same annotation can be used on both a class and a method.

<!-- @[annotation_usages_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/IntroductionToArkTS/entry/src/main/ets/pages/Annotation.ets) -->

``` TypeScript
@ClassPreamble({authorName: "John", revision: 2})
class C1 {
  // ...
}


@ClassPreamble({authorName: "Bob"}) // The default value of revision is 1.
class C2 {
  // ...
}

@MyAnno() // The same annotation can be used on both a class and a method.
class C3 {
  @MyAnno()
  foo() {}
  @MyAnno()
  static bar() {}
}
```

The following is an example of an annotation declaration:

<!-- @[annotation_statement_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/IntroductionToArkTS/entry/src/main/ets/pages/Annotation.ets) -->

``` TypeScript
@interface ClassPreamble {
  authorName: string;
  revision: number = 1;
}
@interface MyAnno {}
```

The order of fields in an annotation does not affect its use.

<!-- @[annotation_field_order](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/IntroductionToArkTS/entry/src/main/ets/pages/Annotation.ets) -->

``` TypeScript
@ClassPreamble1({authorName: "John", revision: 2})
// ...
// the same as:
@ClassPreamble1({revision: 2, authorName: "John"})
```

When using an annotation, you must assign values to all fields that have no default values; otherwise, a compilation error occurs.

> **NOTE**
> 
> The assigned value must match the type declared in the annotation. Like the default value of an annotation field, the assigned value can only be a constant expression.

``` TypeScript
@ClassPreamble() // Compilation error: the authorName field is not defined
class C1 {
  // ...
}
```

If an annotation defines a field of array type, use an array literal to set the value of the field.

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

If no annotation fields need to be defined, the parentheses after the annotation name can be omitted.

<!-- @[annotation_omit](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/IntroductionToArkTS/entry/src/main/ets/pages/Annotation.ets) -->

``` TypeScript
@MyAnno
class C4 {
  // ...
}
```

## Importing and Exporting Annotations

Annotations can also be imported and exported. For exporting, only exporting at the time of definition is currently supported, that is, in the form of `export @interface`.

<!-- @[annotation_export](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/IntroductionToArkTS/entry/src/main/ets/pages/Annotation.ets) -->

``` TypeScript
export @interface MyAnno1 {}
```

For importing, only `import {}` and `import * as` are currently supported.

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

- Renaming an annotation in an import is not allowed.

``` TypeScript
import { MyAnno as Anno } from './a'; // Compilation error: renaming an annotation in an import is not allowed.
```

No other forms of import/export are allowed for annotations; otherwise, a compilation error occurs.

- Because annotations are not types, importing and exporting them with the `type` symbol is not allowed.

``` TypeScript
import type { MyAnno } from './a'; // Compilation error: annotations cannot be imported or exported with the 'type' symbol
```

- If only annotations are imported from a module, the module's side effects are not triggered.

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
// Only the Anno annotation is referenced, so the console.info in MyAnno.ets is not executed
class X {
  // ...
}
```

## Annotations in .d.ets Files

Annotations can appear in .d.ets files. You can declare an annotation in a .d.ets file using an ambient declaration.

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

In the preceding declaration:

- It does not introduce a new annotation definition; instead, it provides the type information of the annotation.

- The annotation must be defined in another source code file.

- The ambient declaration and implementation of an annotation must be exactly the same, including the types and default values of fields.

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

Similar to a `class`, an annotation in an ambient declaration can also be imported and used.

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

### Compiler-Generated .d.ets Files

When the compiler automatically generates a .d.ets file based on the ets code, the following two cases exist.

1. When the annotation definition is exported, the annotation definition in the source code is retained in the .d.ets file.

   <!-- @[annotation_autoGenerate_dts](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/IntroductionToArkTS/entry/src/main/ets/pages/MyAnno.ets) -->

   ``` TypeScript
   // MyAnno.ets
   export @interface ClassAuthor5 {}

   @interface MethodAnno { // Not exported.
     data: number;
   }
   ```

   <!-- @[annotation_export_dts](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/IntroductionToArkTS/entry/src/main/ets/pages/NameAnno.d.ets) -->

   ``` TypeScript
   // NameAnno.d.ets
   export declare @interface ClassAuthor3 {}
   ```

2. When all of the following conditions are met, the annotation instances of entities in the source code are retained in the .d.ets file.

  - 2.1 The definition of the annotation is exported (annotations that are `import`ed are also considered exported).

  - 2.2 If the entity is a class, the class is exported.

  - 2.3 If the entity is a method, the class is exported and the method is not a private method.

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
   // NameAnno.d.ets: declaration file generated by the compiler.
   import { ClassAuthor4 } from './Author';

   export declare @interface MethodAnno4 {
     data: number = 0;
   }

   @ClassAuthor4
   export declare class MyClass {
     @MethodAnno4({data: 123})
     foo(): void;

     bar; // Annotations are not retained for private methods.
   }
   ```

### Developer-Generated .d.ets Files

Annotation information in developer-generated .d.ets files is not automatically applied to the source code of the implementation.

<!-- @[annotation_developerGenerate_dts](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/IntroductionToArkTS/entry/src/main/ets/pages/NameAnno.d.ets) -->

``` TypeScript
// NameAnno.d.ets Developer-generated declaration file
@interface ClassAuthor6 {}

@ClassAuthor6 // The declaration file contains an annotation.
class C {
  // ...
}
```

<!-- @[annotation_developerGenerate_dts](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/IntroductionToArkTS/entry/src/main/ets/pages/MyAnno.ets) -->

``` TypeScript
// MyAnno.ets Source code of the developer's implementation of the declaration file
@interface ClassAuthor6 {}

// No annotation in the implementation file.
class C {
  // ...
}
```

In the final compilation output, class C has no annotation.

## Duplicate Annotations and Inheritance

The same annotation cannot be used repeatedly on the same entity; otherwise, a compilation error occurs.

``` TypeScript
@MyAnno({name: "123", value: 456})
@MyAnno({name: "321", value: 654}) // Compilation error: duplicate annotations are not allowed.
class C {
  // ...
}
```

A subclass does not inherit the annotations of its base class, nor does it inherit the annotations of the base class methods.

## Annotations and Abstract Classes and Methods

Annotations are not supported on abstract classes or abstract methods; otherwise, a compilation error occurs.

``` TypeScript
@MyAnno // Compilation error: annotations are not allowed on abstract classes and abstract methods.
abstract class C {
  @MyAnno
  abstract foo(): void; // Compilation error: annotations are not allowed on abstract classes and abstract methods.
}
```

## Source-State Annotation

Starting from API version 24, you can define custom source-state annotations.

A source-state annotation is a special form of annotation. Its lifecycle exists only during compilation and does not affect the compilation output.

You can use the [Retention](../reference/apis-arkts/js-apis-arkts-lang.md#retention24) API provided by ArkTS to construct a custom source-state annotation. A source-state annotation has a broader scope of use and can be applied to the following declarations:

- Classes

- Class members (except constructors)

- Variable declarations

- Interfaces

- Interface members

- Annotations

- Functions

- Namespace

- Type alias

- Enum

The following shows how to declare and use a source-state annotation:

<!-- @[annotation_source_retention_annotation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/IntroductionToArkTS/entry/src/main/ets/pages/SourceRetentionAnnotation.ets) -->

``` TypeScript
import { Retention, RetentionPolicy } from '@kit.ArkTS';

// Construct a user-defined source-state annotation.
@Retention({policy: RetentionPolicy.SOURCE})
@interface SourceAnnotation {}
// A source-state annotation can be used on classes and class members.
@SourceAnnotation
class C {
  @SourceAnnotation
  private name_: string = '';
  @SourceAnnotation
  get name(): string {
    return this.name_;
  }
}
// A source-state annotation can be used on variable declarations.
@SourceAnnotation
let a = 1;
// A source-state annotation can be used on interfaces and interface members.
@SourceAnnotation
interface I {
  @SourceAnnotation
  foo(): void
}
// A source-state annotation can be used on annotations.
@SourceAnnotation
@interface Anno {}
// A source-state annotation can be used on functions.
@SourceAnnotation
function func () {}
// A source-state annotation can be used on a namespace.
@SourceAnnotation
namespace ns {}
// A source-state annotation can be used on a type alias.
@SourceAnnotation
type A = number;
// A source-state annotation can be used on an enum.
@SourceAnnotation
enum ColorSet { RED, GREEN, BLUE }
```

## ArkTS Constraints

### Annotations Are Available Only in .ets/.d.ets Files

Annotations are not a TypeScript feature and can be used only in `.ets/.d.ets` files. They cannot be declared or used in `.ts` files.

### Annotations Are Not Types

Annotations cannot be used as types, and type aliases cannot be applied to annotations. Otherwise, a compilation error occurs.

### Annotations Are Not Supported on Getters and Setters

Annotations cannot be added to getter and setter methods of a class. Adding an annotation causes a compilation error.

### Repeated Annotations Are Not Allowed

The same annotation cannot be applied repeatedly to the same entity; otherwise, a compilation error occurs.

### Annotations Cannot Be Used on Abstract Classes and Abstract Methods

Using annotations on abstract classes or abstract methods is not supported; otherwise, a compilation error occurs.

### Subclasses Do Not Inherit Annotations

A subclass does not inherit the annotations of its base class, nor the annotations of the base class methods.