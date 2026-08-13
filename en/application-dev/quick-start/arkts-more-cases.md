# Adaptation Cases

<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao; @cy917474985-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=e25164b4c5d2db315865d228475dc21473dba5fb translatedAt=2026-08-13T09:03:36.267Z pushedAt=2026-08-13T13:45:41.513Z -->

In this topic, specific use cases are presented to provide suggestions on adapting TS code to ArkTS for compliance with ArkTS syntax rules. Each chapter is named after an ArkTS syntax rule. Each use case provides the TS code before adaptation and the ArkTS code after adaptation.

## arkts-identifiers-as-prop-names

If the property name is a valid identifier (that is, special characters and spaces are excluded, and does not start with a digit), it can be used directly without quotes.

**Before adaptation**

<!-- @[ts_identifiers_as_prop_names](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->     

``` TypeScript
interface W {
  bundleName: string
  action: string
  entities: string[]
}

let wantInfo: W = {
  'bundleName': 'com.huawei.hmos.browser',
  'action': 'ohos.want.action.viewData',
  'entities': ['entity.system.browsable']
}
```

**After adaptation**

<!-- @[identifiers_as_prop_names](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/BasicAdaptation.ets) -->     

``` TypeScript
interface W {
  bundleName: string
  action: string
  entities: string[]
}

let wantInfo: W = {
  bundleName: 'com.huawei.hmos.browser',
  action: 'ohos.want.action.viewData',
  entities: ['entity.system.browsable']
}
```

## arkts-no-any-unknown

### Changing any and unknown to Specific Types

<!-- @[ts_no_any_unknown](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->      

``` TypeScript
function printObj(obj: any) {
  console.info(obj);
}

printObj('abc'); // abc
```

**After adaptation**

<!-- @[no_any_unknown](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/BasicAdaptation.ets) -->       

``` TypeScript
function printObj(obj: string) {
  console.info(obj);
  // ...
}

printObj('abc'); // abc
```

### Marking JSON.parse Return Value Type

**Before adaptation**

<!-- @[ts_json_parser](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->     

``` TypeScript
class A {
  v: number = 0
  s: string = ''

  foo(str: string) {
    let tmpStr = JSON.parse(str);
    if (tmpStr.add != undefined) {
      this.v = tmpStr.v;
      this.s = tmpStr.s;
    }
  }
}
```

**After adaptation**

<!-- @[json_parser](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/BasicAdaptation.ets) -->     

``` TypeScript
class A {
  public v: number = 0
  public s: string = ''

  foo(str: string) {
    let tmpStr: Record<string, Object> = JSON.parse(str);
    if (tmpStr.add != undefined) {
      this.v = tmpStr.v as number;
      this.s = tmpStr.s as string;
    }
  }
}
```

### Using Record Type

**Before adaptation**

<!-- @[ts_record_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->     

``` TypeScript
function printProperties(obj: any) {
  console.info(obj.name);
  console.info(obj.value);
}
```

**After adaptation**

<!-- @[record_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/BasicAdaptation.ets) -->     

``` TypeScript
function printProperties(obj: Record<string, Object>) {
  console.info(obj.name as string);
  console.info(obj.value as string);
  // ...
}
```

## arkts-no-call-signature

Use the function type instead.

**Before adaptation**

<!-- @[ts_no_call_signature](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->      

``` TypeScript
interface I {
  (value: string): void;
}

function foo(fn: I) {
  fn('abc');
}

foo((value: string) => {
  console.info(value);
})
```

**After adaptation**

<!-- @[no_call_signature](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/BasicAdaptation.ets) -->    

``` TypeScript
type I = (value: string) => void

function foo(fn: I) {
  fn('abc');
}
// ...
  foo((value: string) => {
    console.info(value);
    // ...
  })
```

## arkts-no-ctor-signatures-type

Use the factory function (**() => Instance**) instead of the constructor signature.

**Before adaptation**

<!-- @[ts_no_ctor_signatures_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->    

``` TypeScript
class Controller {
  value: string = ''

  constructor(value: string) {
    this.value = value;
  }
}

type ControllerConstructor = {
  new (value: string): Controller;
}

class TestMenu {
  controller: ControllerConstructor = Controller
  createController() {
    if (this.controller) {
      return new this.controller('123');
    }
    return null;
  }
}

let t = new TestMenu();
console.info(t.createController()!.value);
```

**After adaptation**

<!-- @[no_ctor_signatures_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/BasicAdaptation.ets) -->    

``` TypeScript
class Controller {
  public value: string = ''

  constructor(value: string) {
    this.value = value;
  }
}

type ControllerConstructor = () => Controller;

class TestMenu {
  public controller: ControllerConstructor = () => {
    return new Controller('abc');
  }

  createController() {
    if (this.controller) {
      return this.controller();
    }
    return null;
  }
}
// ...
  let t: TestMenu = new TestMenu();
  console.info(t.createController()!.value);
```

## arkts-no-indexed-signatures

Use the **Record** type instead.

**Before adaptation**

<!-- @[ts_no_indexed_signatures](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->    

``` TypeScript
function foo1(data: { [key: string]: string }) {
  data['a'] = 'a';
  data['b'] = 'b';
  data['c'] = 'c';
}
```

**After adaptation**

<!-- @[no_indexed_signatures](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/BasicAdaptation.ets) -->    

``` TypeScript
function foo1(data: Record<string, string>) {
  data['a'] = 'a';
  data['b'] = 'b';
  data['c'] = 'c';
}
```

## arkts-no-typing-with-this

Use a specific type instead of **this**.

**Before adaptation**

<!-- @[ts_no_typing_with_this](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->    

``` TypeScript
class C {
  getInstance(): this {
    return this;
  }
}
```

**After adaptation**

<!-- @[no_typing_with_this](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/BasicAdaptation.ets) -->    

``` TypeScript
class C {
  getInstance(): C {
    return this;
  }
}
```

## arkts-no-ctor-prop-decls

Declare class properties explicitly and manually assign values to the constructor.

**Before adaptation**

<!-- @[ts_no_ctor_prop_decls](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->    

``` TypeScript
class Person {
  constructor(readonly name: string) {}

  getName(): string {
    return this.name;
  }
}
```

**After adaptation**

<!-- @[no_ctor_prop_decls](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/BasicAdaptation.ets) -->    

``` TypeScript
class Person {
  public name: string
  constructor(name: string) {
    this.name = name;
  }

  getName(): string {
    return this.name;
  }
}
```

## arkts-no-ctor-signatures-iface

Use type to define factory functions or common function types.

**Before adaptation**

<!-- @[ts_no_ctor_signatures_iface](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->    

``` TypeScript
class Controller {
  value: string = ''

  constructor(value: string) {
    this.value = value;
  }
}

interface ControllerConstructor {
  new (value: string): Controller;
}

class TestMenu {
  controller: ControllerConstructor = Controller
  createController() {
    if (this.controller) {
      return new this.controller('abc');
    }
    return null;
  }
}

let t = new TestMenu();
console.info(t.createController()!.value);
```

**After adaptation**

<!-- @[no_ctor_signatures_iface](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/BasicAdaptation.ets) -->    

``` TypeScript
class Controller {
  public value: string = ''

  constructor(value: string) {
    this.value = value;
  }
}

type ControllerConstructor = () => Controller;

class TestMenu {
  public controller: ControllerConstructor = () => {
    return new Controller('abc');
  }

  createController() {
    if (this.controller) {
      return this.controller();
    }
    return null;
  }
}

let t: TestMenu = new TestMenu();
console.info(t.createController()!.value);
```

## arkts-no-props-by-index

Use the **Record** type to access object properties.

**Before adaptation**

<!-- @[ts_no_props_by_index](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->    

``` TypeScript
function foo2(params: Object) {
  let funNum: number = params['funNum'];
  let target: string = params['target'];
}
```

**After adaptation**

<!-- @[no_props_by_index](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/BasicAdaptation.ets) -->    

``` TypeScript
function foo2(params: Record<string, string | number>) {
  let funNum: number = params['funNum'] as number;
  let target: string = params['target'] as string;
}
```

## arkts-no-inferred-generic-params

Explicitly specify the generic parameter types, such as **Map\<string, T\>** and **.map\<T\>()**, for all generic invocations.

**Before adaptation**

<!-- @[ts_no_inferred_generic_params](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->    

``` TypeScript
class A {
  str: string = ''
}
class B extends A {}
class C extends A {}

let arr: Array<A> = [];

let originMenusMap:Map<string, C> = new Map(arr.map(item => [item.str, (item instanceof C) ? item: null]));
```

**After adaptation**

<!-- @[no_inferred_generic_params](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/BasicAdaptation.ets) -->    

``` TypeScript
class A {
  public str: string = ''
}
class B extends A {}
class C extends A {}

let arr: A[] = [];

let originMenusMap: Map<string, C | null> = new Map<string, C | null>
(arr.map<[string, C | null]>(item => [item.str, (item instanceof C) ? item: null]));
```

**Reason for change**

**(item instanceof C) ? item: null** needs to be declared as type **C | null**. This is because the compiler cannot deduce the generic type parameter of **map**, and explicit type annotation is required.

## arkts-no-regexp-literals

Use **new RegExp(pattern, flags)** instead of the **RegExp** literal.

**Before adaptation**

<!-- @[ts_no_regexp_literals](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->    

``` TypeScript
let regex: RegExp = /\s*/g;
```

**After adaptation**

<!-- @[no_regexp_literals](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/BasicAdaptation.ets) -->    

``` TypeScript
let regexp: RegExp = new RegExp('\\s*','g');
```

**Reason for change**

To include a flag in a regular expression, use it as a parameter of **new RegExp()**.

## arkts-no-untyped-obj-literals

### Specifying Object Literal Type for Type Imports

**Before adaptation**

<!-- @[ts_no_obj_literals_as_types](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->    

``` TypeScript
const area = { // No type is specified, so it is inconvenient for maintenance.
  pixels: new ArrayBuffer(8),
  offset: 0,
  stride: 8,
  region: { size: { height: 1,width:2 }, x: 0, y: 0 }
}
```

**After adaptation**

<!-- @[specifying_object_literal_type_for_type_imports](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/ArkTsNoUntypedObjLiterals.ets) -->    

``` TypeScript
import { image } from '@kit.ImageKit';
// ...
const area: image.PositionArea = { // Type is specified.
  pixels: new ArrayBuffer(8),
  offset: 0,
  stride: 8,
  region: { size: { height: 1, width: 2 }, x: 0, y: 0 }
}
```

### Using a Class for Object Literal Type Annotation Only When the Class Constructor Has No Parameters

**Before adaptation**

<!-- @[ts_no_structural_typing_one](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->    

``` TypeScript
class Test {
  value: number = 1
  // There is a constructor.
  constructor(value: number) {
    this.value = value;
  }
}

let t: Test = { value: 2 };
```

**After adaptation: mode 1**

<!-- @[remove_the_constructor](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/ArkTsNoUntypedObjLiterals.ets) -->    

``` TypeScript
// Remove the constructor.
class Test {
  public value: number = 1
}

let t: Test = { value: 2 };
```

**After adaptation: mode 2**

<!-- @[use_new](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/ArkTsNoUntypedObjLiterals.ets) -->    

``` TypeScript
// Use new.
class Test {
  public value: number = 1

  constructor(value: number) {
    this.value = value;
  }
}

let t: Test = new Test(2);
```

**Reason for change**

<!-- @[ts_no_structural_typing_two](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->    

``` TypeScript
class C {
  value: number = 1

  constructor(n: number) {
    if (n < 0) {
      throw new Error('Negative');
    }
    this.value = n;
  }
}

let s: C = new C(-2);   // An exception is thrown.
let t: C = { value: -2 }; // Not supported by ArkTS.
```

In the preceding example, if **C** can be used to specify the object literal type, the variable **t** in the code will cause ambiguity of behavior. In light of this, ArkTS does not allow for object literal type annotation that may cause this issue.

### Using an Identifier as the Object Literal Key When Specifying the Object Literal Type with a Class or Interface

**Before adaptation**

<!-- @[ts_no_nonInferrable_arr_literals](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->    

``` TypeScript
class Test {
  value: number = 0
}

let arr: Test[] = [
  {
    'value': 1
  },
  {
    'value': 2
  },
  {
    'value': 3
  }
]
```

**After adaptation**

<!-- @[using_an_identifier_as_the_object](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/ArkTsNoUntypedObjLiterals.ets) -->  

``` TypeScript
class Test {
  public value: number = 0
}
let arr: Test[] = [
  {
    value: 1
  },
  {
    value: 2
  },
  {
    value: 3
  }
]
```

### Using a String as the Object Literal Key When Specifying the Object Literal Type with a Record

**Before adaptation**

<!-- @[ts_record_type_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->  

``` TypeScript
let obj: Record<string, number | string> = {
  value: 123,
  name: 'abc'
}
```

**After adaptation**

<!-- @[using_a_string_as_the_object](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/ArkTsNoUntypedObjLiterals.ets) -->  

``` TypeScript
let obj: Record<string, number | string> = {
  'value': 123,
  'name': 'abc'
}
```

### Including Index Signature in the Function Parameter Type

**Before adaptation**

<!-- @[ts_index_signature_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->  

``` TypeScript
function foo3(obj: { [key: string]: string}): string {
  if (obj != undefined && obj != null) {
    return obj.value1 + obj.value2;
  }
  return '';
}
```

**After adaptation**

<!-- @[include_index_signature](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/ArkTsNoUntypedObjLiterals.ets) -->  

``` TypeScript
function foo(obj: Record<string, string>): string {
  if (obj != undefined && obj != null) {
    return obj.value1 + obj.value2;
  }
  return '';
}
```

### Including Object Literals in Actual Parameters of Functions

**Before adaptation**

<!-- @[ts_anonymous_function](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->  

``` TypeScript
(fn) => {
  fn({ value: 123, name:'' });
}
```

**After adaptation**

<!-- @[include_object_literals](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/ArkTsNoUntypedObjLiterals.ets) -->  

``` TypeScript
class T {
  public value: number = 0
  public name: string = ''
}

(fn: (v: T) => void) => {
  fn({ value: 123, name: '' });
}
```

### Including Methods in Classes or Interfaces

**Before adaptation**

<!-- @[ts_interface_method_signature](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->  

``` TypeScript
interface T {
  foo(value: number): number
}

let t:T = { foo: (value) => { return value } };
```

**After adaptation: mode 1**

<!-- @[include_method](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/ArkTsNoUntypedObjLiterals.ets) -->  

``` TypeScript
interface T {
  foo: (value: number) => number
}

let t:T = { foo: (value) => { return value } };
```

**After adaptation: mode 2**

<!-- @[include_method_two](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/ArkTsNoUntypedObjLiterals.ets) -->  

``` TypeScript
class T {
  public foo: (value: number) => number = (value: number) => {
    return value;
  }
}

let t:T = new T();
```

**Reason for change**

The methods declared in a class or interface should be shared by all instances of the class. In ArkTS, object literals cannot be used to rewrite instance methods. ArkTS supports properties of the function type.

### export default Object

**Before adaptation**

<!-- @[ts_export_default](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->  

``` TypeScript
export default {
  onCreate() {
    // ...
  },
  onDestroy() {
    // ...
  }
}
```

**After adaptation**

<!-- @[export_default_object](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/ArkTsNoUntypedObjLiterals.ets) -->  

``` TypeScript
class Test {
  onCreate() {
    // ...
  }
  onDestroy() {
    // ...
  }
}

export default new Test()
```

### Obtaining the Type by Importing a Namespace

**Before adaptation**

<!-- @[ts_namespace_dts](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/test.d.ts) -->  

``` TypeScript
// test.d.ets
declare namespace test {
  interface I {
    id: string;
    type: number;
  }

  function foo(name: string, option: I): void;
}

export default test;
```

<!-- @[ts_namespace_app](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/app.ets) -->  

``` TypeScript
// app.ets
import test from './test';

let option = { id: '', type: 0 };
test.foo('', option);
```

**After adaptation**

<!-- @[no_spread_dts](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/test1.d.ets) -->  

``` TypeScript
// test.d.ets
declare namespace Test {
  interface I {
    id: string;
    type: number;
  }

  function foo(name: string, option: I): void;
  function foo(): I;
}

export default Test;
```

<!-- @[ts_namespace_app](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/app.ets) -->  

``` TypeScript
// app.ets
import test from './test';

let option = { id: '', type: 0 };
test.foo('', option);
```

**Reason for change**

The object literal lacks a type. According to the analysis of **test.foo**, the **option** type comes from the declaration file. Therefore, you only need to import the type.

In **test.d.ets**, **I** is defined in **namespace**. Import **namespace** to the .ets file and then obtain the corresponding type by name.

### Passing Parameters from the Object Literal to the Object Type

**Before adaptation**

<!-- @[ts_rest_params](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->  

``` TypeScript
function emit(event: string, ...args: Object[]): void {}

emit('', {
  'action': 11,
  'outers': false
});
```

**After adaptation**

<!-- @[passing_parameters](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/ArkTsNoUntypedObjLiterals.ets) -->  

``` TypeScript
function emit(event: string, ...args: Object[]): void {}

let emitArg: Record<string, number | boolean> = {
  'action': 11,
  'outers': false
}

emit('', emitArg);
```

## arkts-no-obj-literals-as-types

Use **interface** to explicitly define the structure type.

**Before adaptation**

<!-- @[ts_type_alias](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->  

``` TypeScript
type Person = { name: string, age: number }
```

**After adaptation**

<!-- @[no_obj_literals_as_types](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/BasicAdaptation.ets) -->  

``` TypeScript
interface Person {
  name: string,
  age: number
}
```

## arkts-no-noninferrable-arr-literals

Explicitly declare the type of array elements (using **interface** or **class**) and add type annotations to array variables.

**Before adaptation**

<!-- @[ts_array_literal_inference](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->  

``` TypeScript
let permissionList = [
  {name: 'Device information', value: 'Used to analyze the battery life, call, Internet access, and SIM card issues of the device.'},
  {name: 'Microphone', value: 'Used to add voice for issue reporting.'},
  {"name: 'Storage', value: 'Used to add local file attachments for issue reporting.'}
]
```

**After adaptation**

Declare the type for the object literal.

<!-- @[no_nonInferrable_arr_literals](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/BasicAdaptation.ets) -->  

``` TypeScript
class PermissionItem {
  public name?: string
  public value?: string
}

let permissionList: PermissionItem[] = [
  {name: 'Device information', value: 'Used to analyze the battery life, call, Internet access, and SIM card issues of the device.'},
  {name: 'Microphone', value: 'Used to add voice for issue reporting.'},
  {"name: 'Storage', value: 'Used to add local file attachments for issue reporting.'}
]
```

## arkts-no-method-reassignment

Use class fields of the function type instead of prototype methods.

**Before adaptation**

<!-- @[ts_no_method_reassignment](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->  

``` TypeScript
class C {
  add(left: number, right: number): number {
    return left + right;
  }
}

function sub(left: number, right: number): number {
  return left - right;
}

let c1 = new C();
c1.add = sub;
```

**After adaptation**

<!-- @[no_method_reassignment](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/BasicAdaptation.ets) -->  

``` TypeScript
class C3 {
  public add: (left: number, right: number) => number =
    (left: number, right: number) => {
      return left + right;
    }
}

function sub(left: number, right: number): number {
  return left - right;
}

let c1 = new C3();
c1.add = sub;
```

## arkts-no-polymorphic-unops

Use explicit conversion functions such as **Number.parseInt()** and **new Number()**.

**Before adaptation**

<!-- @[ts_no_polymorphic](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->  

``` TypeScript
let a = +'5'; // Implicit conversion using operators.
let b = -'5';
let c = ~'5';
let d = +'string';
```

**After adaptation**

<!-- @[no_polymorphic](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/BasicAdaptation.ets) -->  

``` TypeScript
let a = Number.parseInt('5'); // Use Number.parseInt for explicit conversion.
let b = -Number.parseInt('5');
let c = ~Number.parseInt('5');
let d = new Number('123');
```

## arkts-no-type-query

Use **class**, **interface**, or type aliases instead of **typeof** to avoid inferring types based on variables.

**Before adaptation**

<!-- @[ts_module_one](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/module1.ts) -->  

``` TypeScript
// module1.ts
class C {
  value: number = 0
}

export let c = new C()
```

<!-- @[ts_module_two](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/module2.ts) -->  

``` TypeScript
// module2.ts
import { c } from './module1'
let t: typeof c = { value: 123 };
```

**After adaptation**

<!-- @[no_type_query_one](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/module1.ets) -->  

``` TypeScript
// module1.ets
class C {
  public value: number = 0
}

export { C }
```

<!-- @[no_type_query_two](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/module2.ets) -->  

``` TypeScript
// module2.ets
import { C } from './module1'
let t: C = { value: 123 };
```

## arkts-no-in

### Using Object.keys to Determine Whether a Property Exists

**Before adaptation**

<!-- @[ts_object_keys](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->  

``` TypeScript
function test(str: string, obj: Record<string, Object>) {
  return str in obj;
}
```

**After adaptation**

<!-- @[object_keys](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/BasicAdaptation.ets) -->  

``` TypeScript
function test(str: string, obj: Record<string, Object>) {
  for (let i of Object.keys(obj)) {
    if (i == str) {
      return true;
    }
  }
  return false;
}
```

## arkts-no-destruct-assignment

Use index access or manual assignment instead of destructuring assignment.

**Before adaptation**

<!-- @[ts_no_destruct_assignment](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->  

``` TypeScript
let map = new Map<string, string>([['a', 'a'], ['b', 'b']]);
for (let [key, value] of map) {
  console.info(key);
  console.info(value);
}
```

**After adaptation**

Use arrays.

<!-- @[no_destruct_assignment](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/BasicAdaptation.ets) -->  

``` TypeScript
let map = new Map<string, string>([['a', 'a'], ['b', 'b']]);
// ...
for (let arr of map) {
  let key = arr[0];
  let value = arr[1];
  console.info(key);
  console.info(value);
  // ...
}
```

## arkts-no-types-in-catch

Use the untyped **catch (error)** and then handle the error using type assertion.

**Before adaptation**

```typescript
import { BusinessError } from '@kit.BasicServicesKit'

try {
  // ...
} catch (e: BusinessError) {
  console.error(e.message, e.code);
}
```

**After adaptation**

<!-- @[no_types_in_catch](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/BasicAdaptation.ets) -->  

``` TypeScript
import { BusinessError } from '@kit.BasicServicesKit'
// ...
try {
  // ...
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(e.message, e.code);
}
```

## arkts-no-for-in

Use **Object.entries(obj)** with **for...of** instead of **for...in**.

**Before adaptation**

<!-- @[ts_no_for_in](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->  

``` TypeScript
interface Person {
  [name: string]: string
}
let p: Person = {
  name: 'tom',
  age: '18'
};

for (let t in p) {
  console.info(p[t]);  // info: "tom", "18"
}
```

**After adaptation**

<!-- @[no_for_in](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/BasicAdaptation.ets) -->  

``` TypeScript
let p: Record<string, string> = {
  'name': 'tom',
  'age': '18'
};
// ...
for (let ele of Object.entries(p)) {
  console.info(ele[1]); // info: "tom", "18"
  // ...
}
```

## arkts-no-mapped-types

Use **Record\<K, T\>** instead of the mapped type.

**Before adaptation**

<!-- @[ts_no_mapped_types](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->  

``` TypeScript
class C {
  a: number = 0
  b: number = 0
  c: number = 0
}
type OptionsFlags = {
  [Property in keyof C]: string
}
```

**After adaptation**

<!-- @[no_mapped_types](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/BasicAdaptation.ets) -->  

``` TypeScript
class C {
  public a: number = 0
  public b: number = 0
  public c: number = 0
}

type OptionsFlags = Record<keyof C, string>
```

## arkts-limited-throw

Convert an object to **Error**, or create an **Error** instance and throw it.

**Before adaptation**

<!-- @[ts_limited_throw](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->  

``` TypeScript
import { BusinessError } from '@kit.BasicServicesKit'

function ThrowError(error: BusinessError) {
  throw error;
}
```

**After adaptation**

<!-- @[limited_throw](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/BasicAdaptation.ets) -->  

``` TypeScript
import { BusinessError } from '@kit.BasicServicesKit'

function throwError(error: BusinessError) {
  throw error as Error;
}
```

**Reason for change**

The type of the value in the **throw** statement must be **Error** or its inheritance class. If the inheritance class is a generic, an error is reported during compilation. You are advised to use **as** to convert the type to **Error**.

## arkts-no-standalone-this

### Using this in a Function

**Before adaptation**

<!-- @[ts_no_standalone_this](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->  

``` TypeScript
function foo4() {
  console.info(this.value);
}

let obj = { value: 'abc' };
foo4.apply(obj);
```

**After adaptation: mode 1**

Implement it by using a class method. If the method is used by multiple classes, consider using an inheritance mechanism.

<!-- @[no_standalone_this_one](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/BasicAdaptation.ets) -->  

``` TypeScript
class Test {
  public value: string = ''
  constructor (value: string) {
    this.value = value
  }

  foo() {
    console.info(this.value);
    // ...
  }
}

let obj: Test = new Test('abc');
obj.foo();
```

**After adaptation: mode 2**

Pass in **this** as a parameter.

<!-- @[no_standalone_this_two](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/BasicAdaptation.ets) -->  

``` TypeScript
function foo3(obj: Test) {
  console.info(obj.value);
  // ...
}
// ...
class Test {
  public value: string = ''
}
let obj1: Test = { value: 'abc' };
foo3(obj1);
```

**After adaptation: mode 3**

Pass in a property as a parameter.

<!-- @[no_standalone_this_three](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/BasicAdaptation.ets) -->  

``` TypeScript
function foo5(value: string) {
  console.info(value);
}

class Test1 {
  value: string = ''
}

let obj2: Test1 = { value: 'abc' };
foo5(obj2.value);
```

### Using this in the Static Method of a Class

**Before adaptation**

<!-- @[ts_class_static_function_this](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->  

``` TypeScript
class Test {
  static value: number = 123
  static foo(): number {
    return this.value
  }
}
```

**After adaptation**

<!-- @[class_static_function_this](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/BasicAdaptation.ets) -->  

``` TypeScript
class Test {
  public static value: number = 123
  public static foo(): number {
    return Test.value
  }
}
```

## arkts-no-spread

Use **Object.assign()**, manual assignment, or array methods instead of the spread operator.

**Before adaptation**

```typescript
// test.d.ets
declare namespace test {
  interface I {
    id: string;
    type: number;
  }

  function foo(): I;
}

export default test

// app.ets
import test from 'test';

let t: test.I = {
  ...test.foo(),
  type: 0
}
```

**After adaptation**

<!-- @[obtaining_the_type_dts](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/test.d.ets) -->  

``` TypeScript
// test.d.ets
declare namespace Test {
  interface I {
    id: string;
    type: number;
  }

  function foo(name: string, option: I): void;
  function foo(): I;
}

export default Test;
```

<!-- @[no_spread_ets](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/app.ets) -->  

``` TypeScript
// app.ets
import test from './test';

let t: test.I = test.foo();
t.type = 0;
```

**Reason for change**

In ArkTS, the object layout is determined at compile time. To assign all properties of an object to another object, you can use the property-by-property assignment statement. In this example, the type of the source object is the same as that of the target object. In this case, you can reconstruct the code by changing the object property.

## arkts-no-ctor-signatures-funcs

Declare properties within a class, not on a constructor.

**Before adaptation**

<!-- @[ts_no_ctor_signatures_funcs](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->  

``` TypeScript
class Controller {
  value: string = ''
  constructor(value: string) {
    this.value = value
  }
}

type ControllerConstructor = new (value: string) => Controller;

class TestMenu {
  controller: ControllerConstructor = Controller
  createController() {
    if (this.controller) {
      return new this.controller('abc');
    }
    return null;
  }
}

let t = new TestMenu();
console.info(t.createController()!.value);
```

**After adaptation**

<!-- @[no_ctor_signatures_funcs](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/BasicAdaptation.ets) -->  

``` TypeScript
class Controller {
  public value: string = ''
  constructor(value: string) {
    this.value = value;
  }
}

type ControllerConstructor = () => Controller;

class TestMenu {
  public controller: ControllerConstructor = () => { return new Controller('abc') }
  createController() {
    if (this.controller) {
      return this.controller();
    }
    return null;
  }
}

let t: TestMenu = new TestMenu();
console.info(t.createController()!.value);
```

## arkts-no-globalthis

ArkTS does not support **globalThis** for two reasons:<br> - A static type cannot be added to **globalThis**. As a result, the properties of **globalThis** can be accessed only through search, which causes extra performance overhead.<br> - Type annotation is not available for properties of **globalThis**. As a result, the security and performance of operations on these properties cannot be ensured.

> **NOTE**
>
> 1. You are advised to transfer data between modules based on the service logic and import/export syntax.
> 
> 2. If necessary, you can construct a singleton object to implement the function of a global object. (Do not define the singleton in a HAR as it will be duplicated into different HAPs during packaging, breaking the singleton guarantee.)

Construct a singleton object.

<!-- @[construct_a_singleton_object](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/GlobalContext.ets) -->  

``` TypeScript
// Construct a singleton object.
export class GlobalContext {
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}
```

**Before adaptation**

<!-- @[ts_file_one](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/file1.ts) -->  

``` TypeScript
// file1.ts

export class Test {
  value: string = '';
  foo(): void {
    globalThis.value = this.value;
  }
}
```

<!-- @[ts_file_two](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/file2.ts) -->  

``` TypeScript
// file2.ts

globalThis.value;
```

**After adaptation**

<!-- @[no_global_this_one](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/file1.ets) -->  

``` TypeScript
// file1.ets

import { GlobalContext } from './GlobalContext'

export class Test {
  public value: string = '';
  foo(): void {
    GlobalContext.getContext().setObject('value', this.value);
  }
}
```

<!-- @[no_global_this_two](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/file2.ets) -->  

``` TypeScript
// file2.ets

import { GlobalContext } from './GlobalContext'

GlobalContext.getContext().getObject('value');
```

## arkts-no-func-apply-bind-call

### Using Interfaces in the Standard Library

**Before adaptation**

<!-- @[ts_no_func_apply_bind_call](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->  

``` TypeScript
let arr: number[] = [1, 2, 3, 4];
let str = String.fromCharCode.apply(null, Array.from(arr));
```

**After adaptation**

<!-- @[no_func_apply_bind_call](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/BasicAdaptation.ets) -->  

``` TypeScript
let arr: number[] = [1, 2, 3, 4];
let str = String.fromCharCode(...Array.from(arr));
```

### Using bind in Method Definitions

**Before adaptation**

<!-- @[ts_bind_one](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->  

``` TypeScript
class A {
  value: string = ''
  foo: Function = () => {}
}

class Test {
  value: string = '1234'
  obj: A = {
    value: this.value,
    foo: this.foo.bind(this)
  }

  foo() {
    console.info(this.value);
  }
}
```

**After adaptation: mode 1**

<!-- @[bind_one](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/BasicAdaptation.ets) -->  

``` TypeScript
class A {
  public value: string = ''
  public foo: Function = () => {}
}

class Test {
  public value: string = '1234'
  public obj: A = {
    value: this.value,
    foo: (): void => this.foo()
  }

  foo() {
    console.info(this.value);
  }
}
```

**After adaptation: mode 2**

<!-- @[bind_two](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/BasicAdaptation.ets) -->  

``` TypeScript
class A {
  public value: string = ''
  public foo: Function = () => {}
}

class Test {
  public value: string = '1234'
  public foo: () => void = () => {
    console.info(this.value);
  }
  public obj: A = {
    value: this.value,
    foo: this.foo
  }
}
```

### Using apply

**Before adaptation**

<!-- @[ts_use_apply](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->  

``` TypeScript
class A {
  value: string;
  constructor (value: string) {
    this.value = value;
  }

  foo() {
    console.info(this.value);
  }
}

let a1 = new A('1');
let a2 = new A('2');

a1.foo();
a1.foo.apply(a2);
```

**After adaptation**

<!-- @[use_apply](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/BasicAdaptation.ets) -->  

``` TypeScript
class A {
  public value: string;
  constructor (value: string) {
    this.value = value;
  }

  foo() {
    this.fooApply(this);
  }

  fooApply(a: A) {
    console.info(a.value);
    // ...
  }
}

let a1 = new A('1');
let a2 = new A('2');

a1.foo();
a1.fooApply(a2);
```

## arkts-limited-stdlib

### `Object.fromEntries()`

**Before adaptation**

<!-- @[ts_use_limited_stdlib](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->  

``` TypeScript
let entries = new Map([
  ['foo', 123],
  ['bar', 456]
]);

let obj = Object.fromEntries(entries);
```

**After adaptation**

<!-- @[use_limited_stdlib](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/BasicAdaptation.ets) -->  

``` TypeScript
let entries = new Map([
  ['foo', 123],
  ['bar', 456]
]);

let obj: Record<string, Object> = {};
entries.forEach((value, key) => {
  if (key != undefined && key != null) {
    obj[key] = value;
  }
})
```

## Strict Mode Check (StrictModeError)

### strictPropertyInitialization

**Before adaptation**

<!-- @[ts_strict_typing_required](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->  

``` TypeScript
interface I {
  name: string;
}

class A {}

class Test {
  a: number;
  b: string;
  c: boolean;
  d: I;
  e: A;
}
```

**After adaptation**

<!-- @[strictProperty_initialization](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/StrictModeCheck.ets) -->  

``` TypeScript
interface I {
  name: string;
}

class A {}

class Test {
  public a: number;
  public b: string;
  public c: boolean;
  public d: I = { name:'abc' };
  public e: A | null = null;
  constructor(a:number, b:string, c:boolean) {
    this.a = a;
    this.b = b;
    this.c = c;
  }
}
```

### Type `*** | null` is not assignable to type `***`

**Before adaptation**

<!-- @[ts_null_undefined_check_one](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->  

``` TypeScript
class A {
  bar() {}
}
function foo(n: number) {
  if (n === 0) {
    return null;
  }
  return new A();
}
function getNumber() {
  return 5;
}
let a:A = foo(getNumber());
a.bar();
```

**After adaptation**

<!-- @[null_is_not_assignable_to_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/StrictModeCheck.ets) -->  

``` TypeScript
class A {
  bar() {}
}
function foo(n: number) {
  if (n === 0) {
    return null;
  }
  return new A();
}
function getNumber() {
  return 5;
}

let a: A | null = foo(getNumber());
a?.bar();
```

### Strict Property Initialization Check

In a class, if a property is not initialized and is not assigned a value in the constructor, ArkTS reports an error.

**After adaptation**

1. Whenever possible, initialize properties during declaration based on service logic or assign values to the properties in constructors. Example:

```typescript
// code with error
class Test {
  value: number
  flag: boolean
}

// Method 1: Initialize properties during declaration.
class Test {
  value: number = 0
  flag: boolean = false
}

// Method 2: Assign values to properties in the constructor.
class Test {
  value: number
  flag: boolean
  constructor(value: number, flag: boolean) {
    this.value = value;
    this.flag = flag;
  }
}
```

2. For object type (including function type) **A**, if you are not sure how to initialize it, you are advised to initialize it in one of the following ways:

​ Mode (i): **prop: A | null = null**

​ Mode (ii): **prop?:A**

Mode (iii): `prop: A | undefined = undefined`

- From the perspective of performance, the **null** type is used only for type check during compilation and has no impact on VM performance. In contrast, **undefined | A** is treated as a union type and may result in additional overhead at runtime.

- From the perspective of code readability and conciseness, `prop?:A` is syntactic sugar for `prop: A | undefined = undefined`. **The optional property syntax is recommended.**

### Strict Function Type Check

**Before adaptation**

```typescript
function foo(fn: (value?: string) => void, value: string): void {}

foo((value: string) => {}, ''); // error
```

**After adaptation**

<!-- @[strict_function_type_check](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/StrictModeCheck.ets) -->  

``` TypeScript
function foo1(fn: (value?: string) => void, value: string): void {}

foo1((value?: string) => {}, '');
```

**Reason for change**

In the following example, if strict function type check is not enabled during compilation, the code can be compiled successfully, but unexpected behavior occurs at runtime. Specifically, in the function body of **foo**, an **undefined** is passed in to **fn** (this is acceptable because **fn** can accept **undefined**). However, at the invoking point of **foo** in line 6 of the code, in the passed function implementation of **(value: string) => { console.info(value.toUpperCase()) }**, the **value** parameter is always of the string type and can call the **toUpperCase** method. If strict function type check is not enabled, an error indicating that the property cannot be found on **undefined** occurs at runtime.

```typescript
function foo(fn: (value?: string) => void, value: string): void {
  let v: string | undefined = undefined;
  fn(v);
}

foo((value: string) => { console.info(value.toUpperCase()) }, ''); // Cannot read properties of undefined (reading 'toUpperCase')
```

To avoid unexpected behavior during runtime, if strict type check is enabled, the preceding code cannot be compiled. You need to modify the code to ensure program security.

### Strict Null Check

**Before adaptation**

<!-- @[ts_null_undefined_check_two](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->  

``` TypeScript
class Test {
  private value?: string;

  public printValue () {
    console.info(this.value.toLowerCase());
  }
}

let t = new Test();
t.printValue();
```

**Cause of the runtime error**

If strict null check is not enabled during compilation, the code segment can be compiled successfully, but unexpected behavior occurs at runtime.

This is because the **value** property of **t** is **undefined**, and when the **printValue** method is called, the property is directly accessed based on the string type, due to a lack of null check on the value of **this.value** in the method body.

**After adaptation**

When writing code, minimize the use of nullable types. If a variable or property is marked with a nullable type, a null check is required. Process the service logic based on whether the variable or property is null.

<!-- @[strict_null_check](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/StrictModeCheck.ets) -->  

``` TypeScript
class Test {
  private value?: string;

  public printValue () {
    if (this.value) {
      console.info(this.value.toLowerCase());
    }
  }
}

let t = new Test();
t.printValue();
```

### Function Return Type Mismatch

**Before adaptation**

<!-- @[ts_null_undefined_check_three](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->  

``` TypeScript
class Test {
  handleClick: (action: string, externInfo?: string) => void | null = null;
}
```

**After adaptation**

In the original code, the return type of the function is parsed as **void | undefined**. Add parentheses to distinguish the union type.

<!-- @[function_return_type_mismatch](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/StrictModeCheck.ets) -->  

``` TypeScript
class Test {
  public handleClick: ((action: string, externInfo?: string) => void) | null = null;
}
```

### Type '*** | null' is not assignable to type '\*\*\*'

**Before adaptation**

<!-- @[ts_null_undefined_check_four](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->  

``` TypeScript
class A {
  value: number
  constructor(value: number) {
    this.value = value;
  }
}

function foo6(v: number): A | null {
  if (v > 0) {
    return new A(v);
  }
  return null;
}

let a1: A = foo6(1);
```

**After adaptation: mode 1**

Change the type of variable **a** to **let a: A | null = foo()**.

<!-- @[null_is_not_assignable_to_type1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/StrictModeCheck.ets) -->  

``` TypeScript
class A1 {
  value: number
  constructor(value: number) {
    this.value = value;
  }
}

function foo(v: number): A1 | null {
  if (v > 0) {
    return new A1(v);
  }
  return null;
}

let a: A1 | null = foo(123);

if (a != null) {
  // Non-empty branch
} else {
  // Process null.
}
```

**After adaptation: mode 2**

If you can determine that a non-null value is returned when **foo** is called, you can use a non-null assertion operator **!**.

<!-- @[null_is_not_assignable_to_type2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/StrictModeCheck.ets) -->  

``` TypeScript
class A2 {
  value: number
  constructor(value: number) {
    this.value = value;
  }
}

function foo(v: number): A2 | null {
  if (v > 0) {
    return new A2(v);
  }
  return null;
}

let a: A2 = foo(123)!;
```

### Cannot invoke an object which is possibly 'undefined'

**Before adaptation**

<!-- @[ts_null_undefined_check_five](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->  

``` TypeScript
interface A {
  foo?: () => void
}

let a:A = { foo: () => {} };
a.foo();
```

**After adaptation: mode 1**

<!-- @[cannot_invoke_an_object_one](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/StrictModeCheck.ets) -->  

``` TypeScript
interface A {
  foo: () => void
}
let a: A = { foo: () => {} };
a.foo();
```

**After adaptation: mode 2**

<!-- @[cannot_invoke_an_object_two](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/StrictModeCheck.ets) -->  

``` TypeScript
interface A {
  foo?: () => void
}

let a: A = { foo: () => {} };
if (a.foo) {
  a.foo();
}
```

**Reason for change**

In the original code definition, **foo** is an optional property and may be **undefined**. If **undefined** is called, an error is reported. You are advised to determine whether to set **foo** as an optional property based on the service logic. If defining an optional property is necessary, a null check is required for accessing the property.

### Variable '***' is used before being assigned

**Before adaptation**

<!-- @[ts_null_undefined_check_six](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->  

``` TypeScript
class Test {
  value: number = 0
}

let a: Test
try {
  a = { value: 1};
} catch (e) {
  a.value;
}
a.value;
```

**After adaptation**

<!-- @[is_used_before_being_assigned](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/StrictModeCheck.ets) -->  

``` TypeScript
class Test {
  public value: number = 0
}

let a: Test | null = null;
try {
  a = { value:1 };
} catch (e) {
  if (a) {
    a.value;
  }
}

if (a) {
  a.value;
}
```

**Reason for change**

For primitive types, a value such as **0**, **''**, or **false** can be assigned based on the service logic.

For object types, you can change the type to a union type consisting of **null** and assign **null** to the type. In this case, when using the object type, you need to perform the non-null check.

### Function lacks ending return statement and return type does not include 'undefined'.

**Before adaptation**

<!-- @[ts_function_return_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->  

``` TypeScript
function foo7(a: number): number {
  if (a > 0) {
    return a;
  }
}
```

**After adaptation: mode 1**

Return a proper value in the **else** branch based on the service logic.

**After adaptation: mode 2**

<!-- @[function_lacks_ending](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/StrictModeCheck.ets) -->  

``` TypeScript
function foo4(a: number): number | undefined {
  if (a > 0) {
    return a;
  }
  return
}
```

## arkts-strict-typing-required

Remove the @ts-nocheck comment and explicitly declare types for all variables.

**Before adaptation**

<!-- @[ts_ts_ignore](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->  

``` TypeScript
// @ts-ignore
var a: any = 123;
```

**After adaptation**

<!-- @[strict_typing_required](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/BasicAdaptation.ets) -->  

``` TypeScript
let a: number = 123;
```

**Reason for change**

ArkTS does not support the use of comments to bypass strict type checks. Delete the comment (**// @ts-nocheck** or **// @ts-ignore**), and then modify other code based on the error information.

## Importing ArkTS files to JS and TS files is not allowed

## arkts-no-tsdeps

In .ts and .js files, it is not allowed to import source code from an .ets file.

**After adaptation**

Mode 1: Change the file name extension of the .ts file to .ets and adapt the code based on the ArkTS syntax rules.

Mode 2: Extract the code that the .ts file depends on from the .ets file to the .ts file.

## arkts-no-special-imports

Use the regular **import { ... } from '...'** syntax to import types.  

**Before adaptation**

```typescript
import type {A, B, C, D } from '***'
```

**After adaptation**

```typescript
import {A, B, C, D } from '***'
```

## arkts-no-classes-as-obj

### Using Class to Construct an Instance

**Before adaptation**

<!-- @[ts_no_classes_as_obj](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->  

``` TypeScript
class Controller {
  value: string = ''
  constructor(value: string) {
    this.value = value
  }
}

interface ControllerConstructor {
  new (value: string): Controller;
}

class TestMenu {
  controller: ControllerConstructor = Controller
  createController() {
    if (this.controller) {
      return new this.controller('abc');
    }
    return null;
  }
}

let t = new TestMenu();
console.info(t.createController()!.value);
```

**After adaptation**

<!-- @[no_classes_as_obj](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/BasicAdaptation.ets) -->  

``` TypeScript
class Controller {
  public value: string = ''

  constructor(value: string) {
    this.value = value;
  }
}

type ControllerConstructor = () => Controller;

class TestMenu {
  public controller: ControllerConstructor = () => {
    return new Controller('abc');
  }

  createController() {
    if (this.controller) {
      return this.controller();
    }
    return null;
  }
}

let t: TestMenu = new TestMenu();
console.info(t.createController()!.value);
```

### Accessing Static Properties

**Before adaptation**

<!-- @[ts_static_attribute](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->  

``` TypeScript
class C1 {
  static value: string = 'abc'
}

class C2 {
  static value: string = 'def'
}

function getValue(obj: any) {
  return obj['value'];
}

console.info(getValue(C1));
console.info(getValue(C2));
```

**After adaptation**

<!-- @[static_attribute](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/BasicAdaptation.ets) -->  

``` TypeScript
class C1 {
  public static value: string = 'abc'
}

class C2 {
  public static value: string = 'def'
}

function getC1Value(): string {
  return C1.value;
}

function getC2Value(): string {
  return C2.value;
}

console.info(getC1Value());
console.info(getC2Value());
```

## arkts-no-side-effects-imports

Use dynamic imports.

**Before adaptation**

<!-- @[ts_import_module](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->  

``` TypeScript
import 'module'
```

**After adaptation**

```typescript
import('module')
```

## arkts-no-func-props

Use a **class** to organize multiple related functions.

**Before adaptation**

<!-- @[ts_no_func_props](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->  

``` TypeScript
function foo8(value: number): void {
  console.info(value.toString());
}

foo8.add = (left: number, right: number) => {
  return left + right;
}

foo8.sub = (left: number, right: number) => {
  return left - right;
}
```

**After adaptation**

<!-- @[no_func_props](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/BasicAdaptation.ets) -->  

``` TypeScript
class Foo {
  static foo(value: number): void {
    console.info(value.toString());
    // ...
  }

  static add(left: number, right: number): number {
    return left + right;
  }

  static sub(left: number, right: number): number {
    return left - right;
  }
}
```

## arkts-limited-esobj

Use specific types (such as **number**, **string**) or **interface** instead of the ambiguous **ESObject**.

**Before adaptation**

<!-- @[ts_test_a](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/testa.ts) -->  

``` TypeScript
// testa.ts
export function foo(): any {
  return null;
}
```

<!-- @[ts_main](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/main.ets) -->  

``` TypeScript
// main.ets
import {foo} from './testa'
let e0: ESObject = foo();

function f() {
  let e1 = foo();
  let e2: ESObject = 1;
  let e3: ESObject = {};
  let e4: ESObject = '';
}
```

**After adaptation**

<!-- @[ts_limited_es_obj](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/testa.ts) -->  

``` TypeScript
// testa.ts
export function foo(): any {
  return null;
}
```

<!-- @[ts_main_fix](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/main1.ets) -->  

``` TypeScript
// main.ets
import {foo} from './testa'
interface I {}

function f() {
  let e0: ESObject = foo();
  let e1: ESObject = foo();
  let e2: number = 1;
  let e3: I = {};
  let e4: string = '';
}
```

## Copy

### Shallow Copy

**TypeScript**

<!-- @[ts_shallow_copy](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->  

``` TypeScript
function shallowCopy(obj: object): object {
  let newObj = {};
  Object.assign(newObj, obj);
  return newObj;
}
```

**ArkTS**

<!-- @[shallow_copy](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/BasicAdaptation.ets) -->  

``` TypeScript
function shallowCopy(obj: object): object {
  let newObj: Record<string, Object> = {};
  for (let key of Object.keys(obj)) {
    newObj[key] = obj[key];
  }
  return newObj;
}
```

### Deep Copy

**TypeScript**

<!-- @[ts_deep_copy](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/tsPages/BasicAdaptation.ts) -->  

``` TypeScript
function deepCopy(obj: object): object {
  let newObj = Array.isArray(obj) ? [] : {};
  for (let key in obj) {
    if (typeof obj[key] === 'object') {
      newObj[key] = deepCopy(obj[key]);
    } else {
      newObj[key] = obj[key];
    }
  }
  return newObj;
}
```

**ArkTS**

<!-- @[deep_copy](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromTypeScriptToArkTS/AdaptationCases/entry/src/main/ets/pages/BasicAdaptation.ets) -->  

``` TypeScript
function deepCopy(obj: object): object {
  let newObj: Record<string, Object> | Object[] = Array.isArray(obj) ? [] : {};
  for (let key of Object.keys(obj)) {
    if (typeof obj[key] === 'object') {
      newObj[key] = deepCopy(obj[key]);
    } else {
      newObj[key] = obj[key];
    }
  }
  return newObj;
}
```