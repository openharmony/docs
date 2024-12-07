# Adaptation Cases

In this document, various use cases are presented to provide suggestions on adapting TS code to ArkTS for compliance with ArkTS syntax rules. Each chapter is named after an ArkTS syntax rule. Each use case provides the TS code before adaptation and the ArkTS code after adaptation.

## arkts-identifiers-as-prop-names

**Before adaptation**

```typescript
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

```typescript
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

```typescript
function printObj(obj: any) {
  console.log(obj);
}

printObj('abc');
```

**After adaptation**

```typescript
function printObj(obj: string) {
  console.log(obj);
}

printObj('abc');
```

### Marking JSON.parse Return Value Type

**Before adaptation**

```typescript
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

```typescript
class A {
  v: number = 0
  s: string = ''
  
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

```typescript
function printProperties(obj: any) {
  console.log(obj.name);
  console.log(obj.value);
}
```

**After adaptation**

```typescript
function printProperties(obj: Record<string, Object>) {
  console.log(obj.name as string);
  console.log(obj.value as string);
}
```

## arkts-no-call-signature

Use the function type instead.

**Before adaptation**

```typescript
interface I {
  (value: string): void;
}

function foo(fn: I) {
  fn('abc');
}

foo((value: string) => {
  console.log(value);
})
```


**After adaptation**

```typescript
type I = (value: string) => void

function foo(fn: I) {
  fn('abc');
}

foo((value: string) => {
  console.log(value);
})
```

## arkts-no-ctor-signatures-type

**Before adaptation**

```typescript
class Controller {
  value: string = ''

  constructor(value: string) {
    this.value = value;
  }
}

type ControllerConstructor = {
  new (value: string): Controller;
}

class Menu {
  controller: ControllerConstructor = Controller
  createController() {
    if (this.controller) {
      return new this.controller(123);
    }
    return null;
  }
}

let t = new Menu();
console.log(t.createController()!.value);
```

**After adaptation**

```typescript
class Controller {
  value: string = ''

  constructor(value: string) {
    this.value = value;
  }
}

type ControllerConstructor = () => Controller;

class Menu {
  controller: ControllerConstructor = () => {
    return new Controller('abc');
  }

  createController() {
    if (this.controller) {
      return this.controller();
    }
    return null;
  }
}

let t: Menu = new Menu();
console.log(t.createController()!.value);
```

## arkts-no-indexed-signatures

Use the **Record** type instead.

**Before adaptation**

```typescript
function foo(data: { [key: string]: string }) {
  data['a'] = 'a';
  data['b'] = 'b';
  data['c'] = 'c';
}
```

**After adaptation**

```typescript
function foo(data: Record<string, string>) {
  data['a'] = 'a';
  data['b'] = 'b';
  data['c'] = 'c';
}
```

## arkts-no-typing-with-this

**Before adaptation**

```typescript
class C {
  getInstance(): this {
    return this;
  }
}
```

**After adaptation**

```typescript
class C {
  getInstance(): C {
    return this;
  }
}
```

## arkts-no-ctor-prop-decls

**Before adaptation**

```typescript
class Person {
  constructor(readonly name: string) {}

  getName(): string {
    return this.name;
  }
}
```

**After adaptation**

```typescript
class Person {
  name: string
  constructor(name: string) {
    this.name = name;
  }

  getName(): string {
    return this.name;
  }
}
```

## arkts-no-ctor-signatures-iface

**Before adaptation**

```typescript
class Controller {
  value: string = ''

  constructor(value: string) {
    this.value = value;
  }
}

interface ControllerConstructor {
  new (value: string): Controller;
}

class Menu {
  controller: ControllerConstructor = Controller
  createController() {
    if (this.controller) {
      return new this.controller('abc');
    }
    return null;
  }
}

let t = new Menu();
console.log(t.createController()!.value);
```

**After adaptation**

```typescript
class Controller {
  value: string = ''

  constructor(value: string) {
    this.value = value;
  }
}

type ControllerConstructor = () => Controller;

class Menu {
  controller: ControllerConstructor = () => {
    return new Controller('abc');
  }

  createController() {
    if (this.controller) {
      return this.controller();
    }
    return null;
  }
}

let t: Menu = new Menu();
console.log(t.createController()!.value);
```

## arkts-no-props-by-index

Use the **Record** type to access object attributes.

**Before adaptation**

```typescript
import { router } from '@kit.ArkUI';
let params: Object = router.getParams();
let funNum: number = params['funNum'];
let target: string = params['target'];
```

**After adaptation**

```typescript
import { router } from '@kit.ArkUI';
let params = router.getParams() as Record<string, string | number>;
let funNum: number = params.funNum as number;
let target: string = params.target as string;
```

## arkts-no-inferred-generic-params

**Before adaptation**

```typescript
class A {
  str: string = ''
}
class B extends A {}
class C extends A {}

let arr: Array<A> = [];

let originMenusMap:Map<string, C> = new Map(arr.map(item => [item.str, (item instanceof C) ? item: null]));
```

**After adaptation**

```typescript
class A {
  str: string = ''
}
class B extends A {}
class C extends A {}

let arr: Array<A> = [];

let originMenusMap: Map<string, C | null> = new Map<string, C | null>(arr.map<[string, C | null]>(item => [item.str, (item instanceof C) ? item: null]));
```

**Reason for change**

**(item instanceof C) ? item: null** needs to be declared as type **C | null**. This is because the compiler cannot deduce the generic type parameter of **map**, and explicit type annotation is required.

## arkts-no-regexp-literals

**Before adaptation**

```typescript
let regex: RegExp = /\s*/g;
```

**After adaptation**

```typescript
let regexp: RegExp = new RegExp('\\s*','g');
```

**Reason for change**

To include a flag in a regular expression, use it as a parameter of **new RegExp()**.

## arkts-no-untyped-obj-literals

### Specifying Object Literal Type for Type Imports

**Before adaptation**

```typescript
const area = {
  pixels: new ArrayBuffer(8),
  offset: 0,
  stride: 8,
  region: { size: { height: 1,width:2 }, x: 0, y: 0 }
}
```

**After adaptation**

```typescript
import { image } from '@kit.ImageKit';

const area: image.PositionArea = {
  pixels: new ArrayBuffer(8),
  offset: 0,
  stride: 8,
  region: { size: { height: 1, width: 2 }, x: 0, y: 0 }
}
```

### Using a Class for Object Literal Type Annotation Only When the Class Constructor Have No Parameters

**Before adaptation**

```typescript
class Test {
  value: number = 1

  constructor(value: number) {
    this.value = value;
  }
}

let t: Test = { value: 2 };
```

**After adaptation: mode 1**

```typescript
// Remove the constructor.
class Test {
  value: number = 1
}

let t: Test = { value: 2 };
```

**After adaptation: mode 2**
```typescript
// Use new.
class Test {
  value: number = 1
  
  constructor(value: number) {
    this.value = value;
  }
}

let t: Test = new Test(2);
```

**Reason for change**

```typescript
class C {
  value: number = 1
  
  constructor(n: number) {
    if (n < 0) {
      throw new Error('Negative');
    }
    this.value = n;
  }
}

let s: C = new C(-2); 	// An exception is thrown.
let t: C = { value: -2 };	// Not supported by ArkTS.
```

In the preceding example, if **C** is allowed to be used to specify the object literal type, the variable **t** in the code will cause ambiguity of behavior. In light of this, ArkTS does not allow for object literal type annotation that may cause this issue.

### Using an Identifier as the Object Literal Key When Specifying the Object Literal Type with a Class or Interface

**Before adaptation**

```typescript
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

```typescript
class Test {
  value: number = 0
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

### If **Record** is used to specify the object literal type, a string must be used as the key of the object literal.

**Before adaptation**

```typescript
let obj: Record<string, number | string> = {
  value: 123,
  name: 'abc'
}
```

**After adaptation**

```typescript
let obj: Record<string, number | string> = {
  'value': 123,
  'name': 'abc'
}
```

### Including Index Signature in the Function Parameter Type

**Before adaptation**

```typescript
function foo(obj: { [key: string]: string}): string {
  if (obj != undefined && obj != null) {
    return obj.value1 + obj.value2;
  }
  return '';
}
```

**After adaptation**

```typescript
function foo(obj: Record<string, string>): string {
  if (obj != undefined && obj != null) {
    return obj.value1 + obj.value2;
  }
  return '';
}
```

### Including Object Literals in Actual Parameters of Functions

**Before adaptation**

```typescript
(fn) => {
  fn({ value: 123, name:'' });
}
```

**After adaptation**

```typescript
class T {
  value: number = 0
  name: string = ''
}

(fn: (v: T) => void) => {
  fn({ value: 123, name: '' });
}
```

### Including Methods in Classes or Interfaces

**Before adaptation**

```typescript
interface T {
  foo(value: number): number
}

let t:T = { foo: (value) => { return value } };
```

**After adaptation: mode 1**

```typescript
interface T {
  foo: (value: number) => number
}

let t:T = { foo: (value) => { return value } };
```

**After adaptation: mode 2**

```typescript
class T {
  foo: (value: number) => number = (value: number) => {
    return value;
  }
}

let t:T = new T();
```

**Reason for change**

The methods declared in a class or interface should be shared by all instances of the class. In ArkTS, object literals cannot be used to rewrite instance methods. ArkTS supports attributes of the function type.

### export default Object

**Before adaptation**

```typescript
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

```typescript
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

```typescript
// test.d.ets
declare namespace test {
  interface I {
    id: string;
    type: number;
  }

  function foo(name: string, option: I): void;
}

export default test;

// app.ets
import { test } from 'test';

let option = { id: '', type: 0 };
test.foo('', option);
```

**After adaptation**

```typescript
// test.d.ets
declare namespace test {
  interface I {
    id: string;
    type: number;
  }

  function foo(name: string, option: I): void;
}

export default test;

// app.ets
import { test } from 'test';

let option: test.I = { id: '', type: 0 };
test.foo('', option);
```

**Reason for change**

The object literal lacks a type. According to the analysis of **test.foo**, the **option** type comes from the declaration file. Therefore, you only need to import the type.
In **test.d.ets**, **I** is defined in the namespace. Therefore, to import the type in the .ets file, import the namespace and then obtain the target type based on the name.

### Passing Parameters from the Object Literal to the Object Type

**Before adaptation**

```typescript
function emit(event: string, ...args: Object[]): void {}

emit('', {
  'action': 11,
  'outers': false
});
```

**After adaptation**

```typescript
function emit(event: string, ...args: Object[]): void {}

let emitArg: Record<string, number | boolean> = {
   'action': 11,
   'outers': false
}

emit('', emitArg);
```

## arkts-no-obj-literals-as-types

**Before adaptation**

```typescript
type Person = { name: string, age: number }
```

**After adaptation**

```typescript
interface Person {
  name: string,
  age: number
}
```

## arkts-no-noninferrable-arr-literals

**Before adaptation**

```typescript
let permissionList = [
  {name: 'Device information', value: 'Used to analyze the battery life, call, Internet access, and SIM card issues of the device.'},
  {name: 'Microphone', value: 'Used to add voice when reporting an issue.'},
  {"name: 'Storage', value: 'Used to add local file attachments when reporting an issue.'}
]
```

**After adaptation**

Declare the type for the object literal.

```typescript
class PermissionItem {
  name?: string
  value?: string
}

let permissionList: PermissionItem[] = [
  {name: 'Device information', value: 'Used to analyze the battery life, call, Internet access, and SIM card issues of the device.'},
  {name: 'Microphone', value: 'Used to add voice when reporting an issue.'},
  {"name: 'Storage', value: 'Used to add local file attachments when reporting an issue.'}
]
```

## arkts-no-method-reassignment

**Before adaptation**

```typescript
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

```typescript
class C {
  add: (left: number, right: number) => number = 
    (left: number, right: number) => {
      return left + right;
    }
}

function sub(left: number, right: number): number {
  return left - right;
}

let c1 = new C();
c1.add = sub;
```

## arkts-no-polymorphic-unops

**Before adaptation**

```typescript
let a = +'5';
let b = -'5';
let c = ~'5';
let d = +'string';
```

**After adaptation**

```typescript
let a = Number.parseInt('5');
let b = -Number.parseInt('5');
let c = ~Number.parseInt('5');
let d = new Number('string');
```

## arkts-no-type-query

**Before adaptation**

```typescript
// module1.ts
class C {
  value: number = 0
}

export let c = new C()

// module2.ts
import { c } from './module1'
let t: typeof c = { value: 123 };
```

**After adaptation**

```typescript
// module1.ts
class C {
  value: number = 0
}

export { C }

// module2.ts
import { C } from './module1'
let t: C = { value: 123 };
```

## arkts-no-in

### Using Object.keys to Determine Whether an Attribute Exists

**Before adaptation**

```typescript
function test(str: string, obj: Record<string, Object>) {
  return str in obj;
}
```

**After adaptation**

```typescript
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

**Before adaptation**

```typescript
let map = new Map<string, string>([['a', 'a'], ['b', 'b']]);
for (let [key, value] of map) {
  console.log(key);
  console.log(value);
}
```

**After adaptation**

Use arrays.

```typescript
let map = new Map<string, string>([['a', 'a'], ['b', 'b']]);
for (let arr of map) {
  let key = arr[0];
  let value = arr[1];
  console.log(key);
  console.log(value);
}
```

## arkts-no-types-in-catch

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

```typescript
import { BusinessError } from '@kit.BasicServicesKit'

try {
  // ...
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(e.message, e.code);
}
```

## arkts-no-for-in

**Before adaptation**

```typescript
interface Person {
  [name: string]: string
}
let p: Person = {
  name: 'tom',
  age: '18'
};

for (let t in p) {
  console.log(p[t]);  // log: "tom", "18" 
}
```

**After adaptation**

```typescript
let p: Record<string, string> = {
  'name': 'tom',
  'age': '18'
};

for (let ele of Object.entries(p)) {
  console.log(ele[1]);  // log: "tom", "18" 
}
```

## arkts-no-mapped-types

**Before adaptation**

```typescript
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

```typescript
class C {
  a: number = 0
  b: number = 0
  c: number = 0
}

type OptionsFlags = Record<keyof C, string>
```

## arkts-limited-throw

**Before adaptation**

```typescript
import { BusinessError } from '@kit.BasicServicesKit'

function ThrowError(error: BusinessError) {
  throw error;
}
```

**After adaptation**

```typescript
import { BusinessError } from '@kit.BasicServicesKit'

function ThrowError(error: BusinessError) {
  throw error as Error;
}
```

**Reason for change**

The type of the value in the **throw** statement must be **Error** or its inheritance class. If the inheritance class is a generic, an error is reported during compilation. You are advised to use **as** to convert the type to **Error**.

## arkts-no-standalone-this

### Using this in a Function

**Before adaptation**

```typescript
function foo() {
  console.log(this.value);
}

let obj = { value: 'abc' };
foo.apply(obj);
```

**After adaptation: mode 1**

Use the method of a class. If the method is used by multiple classes, consider using the inheritance mechanism.

```typescript
class Test {
  value: string = ''
  constructor (value: string) {
    this.value = value
  }
  
  foo() {
    console.log(this.value);
  }
}

let obj: Test = new Test('abc');
obj.foo();
```

**After adaptation: mode 2**

Passing this as a Parameter

```typescript
function foo(obj: Test) {
  console.log(obj.value);
}

class Test {
  value: string = ''
}

let obj: Test = { value: 'abc' };
foo(obj);
```

**After adaptation: mode 3**

Pass the attribute as a parameter.
```typescript
function foo(value: string) {
  console.log(value);
}

class Test {
  value: string = ''
}

let obj: Test = { value: 'abc' };
foo(obj.value);
```

### Using this in the Static Method of a Class

**Before adaptation**

```typescript
class Test {
  static value: number = 123
  static foo(): number {
    return this.value
  }
}
```

**After adaptation**

```typescript
class Test {
  static value: number = 123
  static foo(): number {
    return Test.value
  }
}
```

## arkts-no-spread

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

let t: test.I = test.foo();
t.type = 0;
```

**Reason for change**

In ArkTS, the object layout is determined at compile time. To assign all attributes of an object to another object, you can use the attribute-by-attribute assignment statement. In this example, the type of the source object s the same as that of the target object. In this case, you can reconstruct the code by changing the object attribute.

## arkts-no-ctor-signatures-funcs

Declare attributes within a class, not on a constructor.

**Before adaptation**

```typescript
class Controller {
  value: string = ''
  constructor(value: string) {
    this.value = value
  }
}

type ControllerConstructor = new (value: string) => Controller;

class Menu {
  controller: ControllerConstructor = Controller
  createController() {
    if (this.controller) {
      return new this.controller('abc');
    }
    return null;
  }
}

let t = new Menu()
console.log(t.createController()!.value)
```

**After adaptation**

```typescript
class Controller {
  value: string = ''
  constructor(value: string) {
    this.value = value;
  }
}

type ControllerConstructor = () => Controller;

class Menu {
  controller: ControllerConstructor = () => { return new Controller('abc') }
  createController() {
    if (this.controller) {
      return this.controller();
    }
    return null;
  }
}

let t: Menu = new Menu();
console.log(t.createController()!.value);
```

## arkts-no-globalthis

ArkTS does not support **globalThis** for two reasons:<br>(1) A static type cannot be added for **globalThis**. As a result, the attributes of **globalThis** can be accessed only through search, which causes extra performance overhead.<br>(2) Type annotation is not available for attributes of **globalThis**. As a result, the security and performance of operations on these attributes cannot be ensured. Therefore, ArkTS does not support **globalThis**.

1. You are advised to transfer data between modules based on the service logic and import/export syntax.

2. If necessary, you can construct a singleton object to implement the function of a global object. (Note: The singleton object cannot be defined in a HAR file, which packs two copies in different HAP files and therefore cannot implement singleton objects.)

Construct a singleton object.

```typescript
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

```typescript

// file1.ts

export class Test {
  value: string = '';
  foo(): void {
    globalThis.value = this.value;
  }
}

// file2.ts

globalThis.value;

```

**After adaptation**

```typescript

// file1.ts

import { GlobalContext } from '../GlobalContext'

export class Test {
  value: string = '';
  foo(): void {
    GlobalContext.getContext().setObject('value', this.value);
  }
}

// file2.ts

import { GlobalContext } from '../GlobalContext'

GlobalContext.getContext().getObject('value');
```

## arkts-no-func-apply-bind-call

### Using Interfaces in the Standard Library

**Before adaptation**

```typescript
let arr: number[] = [1, 2, 3, 4];
let str = String.fromCharCode.apply(null, Array.from(arr));
```

**After adaptation**

```typescript
let arr: number[] = [1, 2, 3, 4];
let str = String.fromCharCode(...Array.from(arr));
```

### Using bind in Method Definitions

**Before adaptation**

```typescript
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
    console.log(this.value);
  }
}
```

**After adaptation: mode 1**

```typescript
class A {
  value: string = ''
  foo: Function = () => {}
}

class Test {
  value: string = '1234'
  obj: A = {
    value: this.value,
    foo: (): void => this.foo()
  }
  
  foo() {
    console.log(this.value);
  }
}
```

**After adaptation: mode 2**

```typescript
class A {
  value: string = ''
  foo: Function = () => {}
}

class Test {
  value: string = '1234'
  foo: () => void = () => {
    console.log(this.value);
  }
  obj: A = {
    value: this.value,
    foo: this.foo
  }
}
```

### Using apply

**Before adaptation**

```typescript
class A {
  value: string;
  constructor (value: string) {
    this.value = value;
  }

  foo() {
    console.log(this.value);
  }
}

let a1 = new A('1');
let a2 = new A('2');

a1.foo();
a1.foo.apply(a2);
```

**After adaptation**

```typescript
class A {
  value: string;
  constructor (value: string) {
    this.value = value;
  }

  foo() {
    this.fooApply(this);
  }

  fooApply(a: A) {
    console.log(a.value);
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

```typescript
let entries = new Map([
  ['foo', 123],
  ['bar', 456]
]);

let obj = Object.fromEntries(entries);
```

**After adaptation**

```typescript
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

### Using Attributes and Methods of Number

ArkTS does not allow the use of the following attributes and methods for global objects: **Infinity**, **NaN**, **isFinite**, **isNaN**, **parseFloat**, and **parseInt**

You can use them for **Number**.

**Before adaptation**

```typescript
NaN;
isFinite(123);
parseInt('123');
```

**After adaptation**

```typescript
Number.NaN;
Number.isFinite(123);
Number.parseInt('123');
```

## arkts-strict-typing(StrictModeError)

### strictPropertyInitialization

**Before adaptation**

```typescript
interface I {
  name:string
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

```typescript
interface I {
  name:string
}

class A {}

class Test {
  a: number;
  b: string;
  c: boolean;
  d: I = { name:'abc' };
  e: A | null = null;
  constructor(a:number, b:string, c:boolean) {
    this.a = a;
    this.b = b;
    this.c = c;
  }
}

```
### Type `*** | null` is not assignable to type `***`

**Before adaptation**

```typescript
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

```typescript
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

### Strict Attribute Initialization Check

In a class, if an attribute is not initialized and is not assigned a value in the constructor, ArkTS reports an error.

**After adaptation**

1. Whenever possible, initialize attributes during declaration based on service logic or assign values to the attributes in constructors. Example:

```typescript
//code with error
class Test {
  value: number
  flag: boolean
}

// Method 1: Initialize attributes during declaration.
class Test {
  value: number = 0
  flag: boolean = false
}

// Method 2: Assign values to attributes in the constructor.
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

​	Mode (i): **prop: A | null = null**

​	Mode (ii): **prop?:A**

​	Mode 3 (iii): **prop: A | undefined = undefined**

- From the perspective of performance, the **null** type is used only for type check during compilation and has no impact on VM performance. In contrast, **undefined | A** is treated as a union type and may result in additional overhead at run time.
- In terms of code readability and simplicity, **prop?:A** is the syntax sugar of **prop: A | undefined = undefined**. You are advised to use optional attributes.

### Strict Function Type Check

**Before adaptation**

```typescript
function foo(fn: (value?: string) => void, value: string): void {}

foo((value: string) => {}, ''); //error
```

**After adaptation**

```typescript
function foo(fn: (value?: string) => void, value: string): void {}

foo((value?: string) => {}, '');
```

**Reason for change**

In the following example, if strict function type check is not enabled during compilation, the code can be compiled successfully, but unexpected behavior occurs at run time. Specifically, in the function body of **foo**, an **undefined** is passed in to **fn** (this is acceptable because **fn** can accept **undefined**). However, at the invoking point of **foo** in line 6 of the code, in the passed function implementation of **(value: string) => { console.log(value.toUpperCase()) }**, the **value** parameter is always of the string type and can call the **toUpperCase** method. If strict function type check is not enabled, an error indicating that the property cannot be found on **undefined** occurs at run time.

```typescript
function foo(fn: (value?: string) => void, value: string): void {
  let v: string | undefined = undefined;
  fn(v);
}

foo((value: string) => { console.log(value.toUpperCase()) }, ''); // Cannot read properties of undefined (reading 'toUpperCase')
```

If strict type check is enabled during compilation, the preceding issue can be detected at compile time.

### Strict Null Check

**Before adaptation**

```typescript
class Test {
  private value?: string
  
  public printValue () {
    console.log(this.value.toLowerCase());
  }
}

let t = new Test();
t.printValue();
```

**After adaptation**

When writing code, minimize the use of nullable types. If a variable or property is marked with a nullable type, a null check is required. Process the service logic based on whether the variable or property is null.

```typescript
class Test {
  private value?: string

  public printValue () {
    if (this.value) {
      console.log(this.value.toLowerCase());
    }
  }
}

let t = new Test();
t.printValue();
```

**Reason for change**

In the first code segment, if strict null check is not enabled during compilation, the code segment can be compiled successfully, but unexpected behavior occurs at run time. This is because the **value** property of **t** is **undefined** (**value?: string** is the syntax sugar of **value: string | undefined = undefined**), and when the **printValue** method is called in line 11, the property is directly accessed based on the string type, due to a lack of null check on the value of **this.value** in the method body. To avoid unexpected behavior at run time, enable strict null check during compilation.

### Function Return Type Mismatch

**Before adaptation**

```typescript
class Test {
  handleClick: (action: string, externInfo?: string) => void | null = null;
}
```

**After adaptation**

In the original code, the return type of the function is parsed as **void | undefined**. Add parentheses to distinguish the union type.

```typescript
class Test {
  handleClick: ((action: string, externInfo?: string) => void) | null = null;
}
```

### '***' is of type 'unknown'

**Before adaptation**

```typescript
try {
  
} catch (error) {
  console.log(error.message);
}
```

**After adaptation**

```typescript
import { BusinessError } from '@kit.BasicServicesKit'

try {
  
} catch (error) {
  console.log((error as BusinessError).message);
}
```

### Type '*** | null' is not assignable to type '\*\*\*'

**Before adaptation**

```typescript
class A {
  value: number
  constructor(value: number) {
    this.value = value;
  }
}

function foo(v: number): A | null {
  if (v > 0) {
    return new A(v);
  }
  return null;
}

let a: A = foo();
```

**After adaptation: mode 1**

Change the type of variable **a** to **let a: A | null = foo()**.

```typescript
class A {
  value: number
  constructor(value: number) {
    this.value = value;
  }
}

function foo(v: number): A | null {
  if (v > 0) {
    return new A(v);
  }
  return null;
}

let a: A | null = foo(123);

if (a != null) {
  // Non-empty branch
} else {
  // Process null.
}
```

**After adaptation: mode 2**

If you can determine that a non-null value is returned when **foo** is called, you can use a non-null assertion operator **!**.

```typescript
class A {
  value: number
  constructor(value: number) {
    this.value = value;
  }
}

function foo(v: number): A | null {
  if (v > 0) {
    return new A(v);
  }
  return null;
}

let a: A = foo(123)!;
```

### Cannot invoke an object which possibly 'undefined'

**Before adaptation**

```typescript
interface A {
  foo?: () => void
}

let a:A = { foo: () => {} };
a.foo();
```

**After adaptation: mode 1**

```typescript
interface A {
  foo: () => void
}
let a: A = { foo: () => {} };
a.foo();
```

**After adaptation: mode 2**

```typescript
interface A {
  foo?: () => void
}

let a: A = { foo: () => {} };
if (a.foo) {
  a.foo();
}
```

**Reason for change**

In the original code definition, **foo** is an optional property and may be **undefined**. If **undefined** is called, an error is reported. You are advised to determine whether a property is optional based on the service logic. If defining an optional property is necessary, a null check is required for accessing the property.

### Variable '***' is used before being assigned

**Before adaptation**

```typescript
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

```typescript
class Test {
  value: number = 0
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

For primitive types, a value can be assigned based on the service logic, for example, **0**, **''**, and **false**.

For the object type, you can change the type to a union type consisting of **null** and assign **null** to the type. In this case, when using the object type, you need to perform the non-null check.

### Function lacks ending return statement and return type does not include 'undefined'.

**Before adaptation**

```typescript
function foo(a: number): number {
  if (a > 0) {
    return a;
  }
}
```

**After adaptation: mode 1**

Return a proper value in the **else** branch based on the service logic.

**After adaptation: mode 2**

```typescript
function foo(a: number): number | undefined {
  if (a > 0) {
    return a;
  }
  return
}
```

## arkts-strict-typing-required

**Before adaptation**

```typescript
// @ts-nocheck
var a: any = 123;
```

**After adaptation**

```typescript
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

```typescript
class Controller {
  value: string = ''
  constructor(value: string) {
    this.value = value
  }
}

interface ControllerConstructor {
  new (value: string): Controller;
}

class Menu {
  controller: ControllerConstructor = Controller
  createController() {
    if (this.controller) {
      return new this.controller('abc');
    }
    return null;
  }
}

let t = new Menu();
console.log(t.createController()!.value);
```

**After adaptation**

```typescript
class Controller {
  value: string = ''
  constructor(value: string) {
    this.value = value
  }
}

type ControllerConstructor = () => Controller;

class Menu {
  controller: ControllerConstructor = () => { return new Controller('abc'); }
  createController() {
    if (this.controller) {
      return this.controller();
    }
    return null;
  }
}

let t: Menu = new Menu();
console.log(t.createController()!.value);
```

### Accessing Static Properties

**Before adaptation**

```typescript
class C1 {
  static value: string = 'abc'
}

class C2 {
  static value: string = 'def'
}

function getValue(obj: any) {
  return obj['value'];
}

console.log(getValue(C1));
console.log(getValue(C2));
```

**After adaptation**

```typescript
class C1 {
  static value: string = 'abc'
}

class C2 {
  static value: string = 'def'
}

function getC1Value(): string {
  return C1.value;
}

function getC2Value(): string {
  return C2.value;
}

console.log(getC1Value());
console.log(getC2Value());
```

## arkts-no-side-effects-imports

Use Dynamic Imports

**Before adaptation**

```typescript
import 'module'
```

**After adaptation**

```typescript
import('module')
```

## arkts-no-func-props

**Before adaptation**

```typescript
function foo(value: number): void {
  console.log(value.toString());
}

foo.add = (left: number, right: number) => {
  return left + right;
}

foo.sub = (left: number, right: number) => {
  return left - right;
}
```

**After adaptation**

```typescript
class Foo {
  static foo(value: number): void {
    console.log(value.toString());
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

**Before adaptation**

```typescript
// lib.d.ts
declare function foo(): any;

// main.ets
let e0: ESObject = foo();

function f() {
  let e1 = foo();
  let e2: ESObject = 1;
  let e3: ESObject = {};
  let e4: ESObject = '';
}
```

**After adaptation**

```typescript
// lib.d.ts
declare function foo(): any;

// main.ets
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

```typescript
function shallowCopy(obj: object): object {
  let newObj = {};
  Object.assign(newObj, obj);
  return newObj;
}
```

**ArkTS**

```typescript
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

```typescript
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

```typescript
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

## Typical Application Scenarios of State Management

### Using State Variables Outside of Structs

The struct is different from the class. Therefore, avoid passing **this** as a parameter to the outside of the struct. Otherwise, the instance reference cannot be released and memory leakage may occur. You are advised to pass the state variable object outside the struct and modify the object properties to trigger UI re-render.

**Not recommended**

```typescript
export class MyComponentController {
  item: MyComponent = null;

  setItem(item: MyComponent) {
    this.item = item;
  }

  changeText(value: string) {
    this.item.value = value;
  }
}

@Component
export default struct MyComponent {
  public controller: MyComponentController = null;
  @State value: string = 'Hello World';

  build() {
    Column() {
      Text(this.value)
        .fontSize(50)
    }
  }

  aboutToAppear() {
    if (this.controller)
      this.controller.setItem(this); // You are not advised to pass this as a parameter to the outside struct.
  }
}

@Entry
@Component
struct ObjThisOldPage {
  controller = new MyComponentController();

  build() {
    Column() {
      MyComponent({ controller: this.controller })
      Button('change value').onClick(() => {
        this.controller.changeText('Text');
      })
    }
  }
}
```

**Recommended**

```typescript
class CC {
  value: string = '1';

  constructor(value: string) {
    this.value = value;
  }
}

export class MyComponentController {
  item: CC = new CC('1');

  setItem(item: CC) {
    this.item = item;
  }

  changeText(value: string) {
    this.item.value = value;
  }
}

@Component
export default struct MyComponent {
  public controller: MyComponentController | null = null;
  @State value: CC = new CC('Hello World');

  build() {
    Column() {
      Text(`${this.value.value}`)
        .fontSize(50)
    }
  }

  aboutToAppear() {
    if (this.controller)
      this.controller.setItem(this.value);
  }
}

@Entry
@Component
struct StyleExample {
  controller: MyComponentController = new MyComponentController();

  build() {
    Column() {
      MyComponent({ controller: this.controller })
      Button('change value').onClick(() => {
        this.controller.changeText('Text');
      })
    }
  }
}
```

### Using Union Types in Structs

The following code contains the arkts-no-any-unknown error. Because the struct does not support generics, you are advised to use the union type to implement generic-like functions of custom components.

**Not recommended**

```typescript
class Data {
  aa: number = 11;
}

@Entry
@Component
struct DatauionOldPage {
  @State array: Data[] = [new Data(), new Data(), new Data()];

  @Builder
  componentCloser(data: Data) {
    Text(data.aa + '').fontSize(50)
  }

  build() {
    Row() {
      Column() {
        ForEachCom({ arrayList: this.array, closer: this.componentCloser })
      }
      .width('100%')
    }
    .height('100%')
  }
}

@Component
export struct ForEachCom {
  arrayList: any[]; // The struct does not support generics. An arkts-no-any-unknown error is reported.
  @BuilderParam closer: (data: any) => void = this.componentCloser; // The struct does not support generics. An arkts-no-any-unknown error is reported.

  @Builder
  componentCloser() {
  }

  build() {
    Column() {
      ForEach(this.arrayList, (item: any) => { // The struct does not support generics. An arkts-no-any-unknown error is reported.
        Row() {
          this.closer(item)
        }.width('100%').height(200).backgroundColor('#eee')
      })
    }
  }
}
```

**Recommended**

```typescript
class Data {
  aa: number = 11;
}

class Model {
  aa: string = '11';
}

type UnionData = Data | Model;

@Entry
@Component
struct DatauionPage {
  array: UnionData[] = [new Data(), new Data(), new Data()];

  @Builder
  componentCloser(data: UnionData) {
    if (data instanceof Data) {
      Text(data.aa + '').fontSize(50)
    }
  }

  build() {
    Row() {
      Column() {
        ForEachCom({ arrayList: this.array, closer: this.componentCloser })
      }
      .width('100%')
    }
    .height('100%')
  }
}

@Component
export struct ForEachCom {
  arrayList: UnionData[] = [new Data(), new Data(), new Data()];
  @BuilderParam closer: (data: UnionData) => void = this.componentCloser;

  @Builder
  componentCloser() {
  }

  build() {
    Column() {
      ForEach(this.arrayList, (item: UnionData) => {
        Row() {
          this.closer(item)
        }.width('100%').height(200).backgroundColor('#eee')
      })
    }
  }
}
```
