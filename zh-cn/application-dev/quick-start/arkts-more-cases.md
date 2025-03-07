# 适配指导案例

本文通过更多应用场景中的案例，提供在ArkTS语法规则下将TS代码适配成ArkTS代码的建议。各章以ArkTS语法规则英文名称命名，每个案例提供适配前的TS代码和适配后的ArkTS代码。

## arkts-identifiers-as-prop-names

**应用代码**

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

**建议改法**

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

### 按照业务逻辑，将代码中的`any, unknown`改为具体的类型

```typescript
function printObj(obj: any) {
  console.log(obj);
}

printObj('abc');
```

**建议改法**

```typescript
function printObj(obj: string) {
  console.log(obj);
}

printObj('abc');
```

### 标注JSON.parse返回值类型

**应用代码**

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

**建议改法**

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

### 使用Record类型

**应用代码**

```typescript
function printProperties(obj: any) {
  console.log(obj.name);
  console.log(obj.value);
}
```

**建议改法**

```typescript
function printProperties(obj: Record<string, Object>) {
  console.log(obj.name as string);
  console.log(obj.value as string);
}
```

## arkts-no-call-signature

使用函数类型来替代。

**应用代码**

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


**建议改法**

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

**应用代码**

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

**建议改法**

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

使用Record类型来替代。

**应用代码**

```typescript
function foo(data: { [key: string]: string }) {
  data['a'] = 'a';
  data['b'] = 'b';
  data['c'] = 'c';
}
```

**建议改法**

```typescript
function foo(data: Record<string, string>) {
  data['a'] = 'a';
  data['b'] = 'b';
  data['c'] = 'c';
}
```

## arkts-no-typing-with-this

**应用代码**

```typescript
class C {
  getInstance(): this {
    return this;
  }
}
```

**建议改法**

```typescript
class C {
  getInstance(): C {
    return this;
  }
}
```

## arkts-no-ctor-prop-decls

**应用代码**

```typescript
class Person {
  constructor(readonly name: string) {}

  getName(): string {
    return this.name;
  }
}
```

**建议改法**

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

**应用代码**

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

**建议改法**

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

可以转换成Record类型，用来访问对象的属性。

**应用代码**

```typescript
import { router } from '@kit.ArkUI';
let params: Object = router.getParams();
let funNum: number = params['funNum'];
let target: string = params['target'];
```

**建议改法**

```typescript
import { router } from '@kit.ArkUI';
let params = router.getParams() as Record<string, string | number>;
let funNum: number = params.funNum as number;
let target: string = params.target as string;
```

## arkts-no-inferred-generic-params

**应用代码**

```typescript
class A {
  str: string = ''
}
class B extends A {}
class C extends A {}

let arr: Array<A> = [];

let originMenusMap:Map<string, C> = new Map(arr.map(item => [item.str, (item instanceof C) ? item: null]));
```

**建议改法**

```typescript
class A {
  str: string = ''
}
class B extends A {}
class C extends A {}

let arr: Array<A> = [];

let originMenusMap: Map<string, C | null> = new Map<string, C | null>(arr.map<[string, C | null]>(item => [item.str, (item instanceof C) ? item: null]));
```

**原因**

`(item instanceof C) ? item: null` 需要声明类型为`C | null`，由于编译器无法推导出`map`的泛型类型参数，需要显式标注。

## arkts-no-regexp-literals

**应用代码**

```typescript
let regex: RegExp = /\s*/g;
```

**建议改法**

```typescript
let regexp: RegExp = new RegExp('\\s*','g');
```

**原因**

如果正则表达式中使用了标志符，需要将其作为`new RegExp()`的参数。

## arkts-no-untyped-obj-literals

### 从SDK中导入类型，标注object literal类型

**应用代码**

```typescript
const area = {
  pixels: new ArrayBuffer(8),
  offset: 0,
  stride: 8,
  region: { size: { height: 1,width:2 }, x: 0, y: 0 }
}
```

**建议改法**

```typescript
import { image } from '@kit.ImageKit';

const area: image.PositionArea = {
  pixels: new ArrayBuffer(8),
  offset: 0,
  stride: 8,
  region: { size: { height: 1, width: 2 }, x: 0, y: 0 }
}
```

### 用class为object literal标注类型，需要class的构造函数无参数

**应用代码**

```typescript
class Test {
  value: number = 1

  constructor(value: number) {
    this.value = value;
  }
}

let t: Test = { value: 2 };
```

**建议改法1**

```typescript
// 去除构造函数
class Test {
  value: number = 1
}

let t: Test = { value: 2 };
```

**建议改法2**
```typescript
// 使用new
class Test {
  value: number = 1
  
  constructor(value: number) {
    this.value = value;
  }
}

let t: Test = new Test(2);
```

**原因**

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

let s: C = new C(-2); 	//抛出异常
let t: C = { value: -2 };	//ArkTS不支持
```

例如在上面的例子中，如果允许使用`C`来标注object literal的类型，那么上述代码中的变量`t`会导致行为的二义性。ArkTS禁止通过object literal来绕过这一行为。

### 用class/interface为object literal标注类型，需要使用identifier作为object literal的key

**应用代码**

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

**建议改法**

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

### 使用Record为object literal标注类型，需要使用字符串作为object literal的key

**应用代码**

```typescript
let obj: Record<string, number | string> = {
  value: 123,
  name: 'abc'
}
```

**建议改法**

```typescript
let obj: Record<string, number | string> = {
  'value': 123,
  'name': 'abc'
}
```

### 函数参数类型包含index signature

**应用代码**

```typescript
function foo(obj: { [key: string]: string}): string {
  if (obj != undefined && obj != null) {
    return obj.value1 + obj.value2;
  }
  return '';
}
```

**建议改法**

```typescript
function foo(obj: Record<string, string>): string {
  if (obj != undefined && obj != null) {
    return obj.value1 + obj.value2;
  }
  return '';
}
```

### 函数实参使用了object literal

**应用代码**

```typescript
(fn) => {
  fn({ value: 123, name:'' });
}
```

**建议改法**

```typescript
class T {
  value: number = 0
  name: string = ''
}

(fn: (v: T) => void) => {
  fn({ value: 123, name: '' });
}
```

### class/interface 中包含方法

**应用代码**

```typescript
interface T {
  foo(value: number): number
}

let t:T = { foo: (value) => { return value } };
```

**建议改法1**

```typescript
interface T {
  foo: (value: number) => number
}

let t:T = { foo: (value) => { return value } };
```

**建议改法2**

```typescript
class T {
  foo: (value: number) => number = (value: number) => {
    return value;
  }
}

let t:T = new T();
```

**原因**

class/interface中声明的方法应该被所有class的实例共享。ArkTS不支持通过object literal改写实例方法。ArkTS支持函数类型的属性。

### export default对象

**应用代码**

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

**建议改法**

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

### 通过导入namespace获取类型

**应用代码**

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

**建议改法**

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

**原因**

对象字面量缺少类型，根据`test.foo`分析可以得知，`option`的类型来源于声明文件，那么只需要将类型导入即可。
注意到在`test.d.ets`中，`I`是定义在namespace中的，所以在ets文件中，先导入namespace，再通过名称获取相应的类型。

### object literal传参给Object类型

**应用代码**

```typescript
function emit(event: string, ...args: Object[]): void {}

emit('', {
  'action': 11,
  'outers': false
});
```

**建议改法**

```typescript
function emit(event: string, ...args: Object[]): void {}

let emitArg: Record<string, number | boolean> = {
   'action': 11,
   'outers': false
}

emit('', emitArg);
```

## arkts-no-obj-literals-as-types

**应用代码**

```typescript
type Person = { name: string, age: number }
```

**建议改法**

```typescript
interface Person {
  name: string,
  age: number
}
```

## arkts-no-noninferrable-arr-literals

**应用代码**

```typescript
let permissionList = [
  { name: '设备信息', value: '用于分析设备的续航、通话、上网、SIM卡故障等' },
  { name: '麦克风', value: '用于反馈问题单时增加语音' },
  { name: '存储', value: '用于反馈问题单时增加本地文件附件' }
]
```

**建议改法**

为对象字面量声明类型

```typescript
class PermissionItem {
  name?: string
  value?: string
}

let permissionList: PermissionItem[] = [
  { name: '设备信息', value: '用于分析设备的续航、通话、上网、SIM卡故障等' },
  { name: '麦克风', value: '用于反馈问题单时增加语音' },
  { name: '存储', value: '用于反馈问题单时增加本地文件附件' }
]
```

## arkts-no-method-reassignment

**应用代码**

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

**建议改法**

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

**应用代码**

```typescript
let a = +'5';
let b = -'5';
let c = ~'5';
let d = +'string';
```

**建议改法**

```typescript
let a = Number.parseInt('5');
let b = -Number.parseInt('5');
let c = ~Number.parseInt('5');
let d = new Number('string');
```

## arkts-no-type-query

**应用代码**

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

**建议改法**

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

### 使用Object.keys判断属性是否存在

**应用代码**

```typescript
function test(str: string, obj: Record<string, Object>) {
  return str in obj;
}
```

**建议改法**

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

**应用代码**

```typescript
let map = new Map<string, string>([['a', 'a'], ['b', 'b']]);
for (let [key, value] of map) {
  console.log(key);
  console.log(value);
}
```

**建议改法**

使用数组

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

**应用代码**

```typescript
import { BusinessError } from '@kit.BasicServicesKit'

try {
  // ...
} catch (e: BusinessError) {
  console.error(e.message, e.code);
}
```

**建议改法**

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

**应用代码**

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

**建议改法**

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

**应用代码**

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

**建议改法**

```typescript
class C {
  a: number = 0
  b: number = 0
  c: number = 0
}

type OptionsFlags = Record<keyof C, string>
```

## arkts-limited-throw

**应用代码**

```typescript
import { BusinessError } from '@kit.BasicServicesKit'

function ThrowError(error: BusinessError) {
  throw error;
}
```

**建议改法**

```typescript
import { BusinessError } from '@kit.BasicServicesKit'

function ThrowError(error: BusinessError) {
  throw error as Error;
}
```

**原因**

`throw`语句中值的类型必须为`Error`或者其继承类，如果继承类是一个泛型，会有编译期报错。建议使用`as`将类型转换为`Error`。

## arkts-no-standalone-this

### 函数内使用this

**应用代码**

```typescript
function foo() {
  console.log(this.value);
}

let obj = { value: 'abc' };
foo.apply(obj);
```

**建议改法1**

使用类的方法实现,如果该方法被多个类使用,可以考虑采用继承的机制

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

**建议改法2**

将this作为参数传入

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

**建议改法3**

将属性作为参数传入
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

### class的静态方法内使用this

**应用代码**

```typescript
class Test {
  static value: number = 123
  static foo(): number {
    return this.value
  }
}
```

**建议改法**

```typescript
class Test {
  static value: number = 123
  static foo(): number {
    return Test.value
  }
}
```

## arkts-no-spread

**应用代码**

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

**建议改法**

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

**原因**

ArkTS中，对象布局在编译期是确定的。如果需要将一个对象的所有属性展开赋值给另一个对象可以通过逐个属性赋值语句完成。在本例中，需要展开的对象和赋值的目标对象类型恰好相同，可以通过改变该对象属性的方式重构代码。

## arkts-no-ctor-signatures-funcs

在class内声明属性，而不是在构造函数上。

**应用代码**

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

**建议改法**

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

由于无法为globalThis添加静态类型，只能通过查找的方式访问globalThis的属性，造成额外的性能开销。另外，无法为globalThis的属性标记类型，无法保证对这些属性操作的安全和高性能。因此ArkTS不支持globalThis。

1. 建议按照业务逻辑根据`import/export`语法实现数据在不同模块的传递。

2. 必要情况下，可以通过构造的**单例对象**来实现全局对象的功能。(**说明：** 不能在har中定义单例对象，har在打包时会在不同的hap中打包两份，无法实现单例。)

**构造单例对象**

```typescript
// 构造单例对象
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

**应用代码**

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

**建议改法**

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

### 使用标准库中接口

**应用代码**

```typescript
let arr: number[] = [1, 2, 3, 4];
let str = String.fromCharCode.apply(null, Array.from(arr));
```

**建议改法**

```typescript
let arr: number[] = [1, 2, 3, 4];
let str = String.fromCharCode(...Array.from(arr));
```

### bind定义方法

**应用代码**

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

**建议改法1**

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

**建议改法2**

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

### 使用apply

**应用代码**

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

**建议改法**

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

**应用代码**

```typescript
let entries = new Map([
  ['foo', 123],
  ['bar', 456]
]);

let obj = Object.fromEntries(entries);
```

**建议改法**

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

### 使用`Number`的属性和方法

ArkTS不允许使用全局对象的属性和方法： `Infinity, NaN, isFinite, isNaN, parseFloat, parseInt`

可以使用`Number`的属性和方法： `Infinity, NaN, isFinite, isNaN, parseFloat, parseInt`

**应用代码**

```typescript
NaN;
isFinite(123);
parseInt('123');
```

**建议改法**

```typescript
Number.NaN;
Number.isFinite(123);
Number.parseInt('123');
```

## arkts-strict-typing(StrictModeError)

### strictPropertyInitialization

**应用代码**

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

**建议改法**

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

**应用代码**

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

**建议改法**

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

### 严格属性初始化检查

在class中，如果一个属性没有初始化，且没有在构造函数中被赋值，那么ArkTS将报错。

**建议改法**

1.一般情况下，**建议按照业务逻辑**在声明时初始化属性，或者在构造函数中为属性赋值。如：

```typescript
//code with error
class Test {
  value: number
  flag: boolean
}

//方式一，在声明时初始化
class Test {
  value: number = 0
  flag: boolean = false
}

//方式二，在构造函数中赋值
class Test {
  value: number
  flag: boolean
  constructor(value: number, flag: boolean) {
    this.value = value;
    this.flag = flag;
  }
}
```

2.对于对象类型（包括函数类型）`A`，如果不确定如何初始化，建议按照以下方式之一进行初始化

​	方式(i)  `prop: A | null = null`

​	方式(ii) `prop?: A`

​	方式三(iii) `prop： A | undefined = undefined`

- 从性能角度来说，`null`类型只用在编译期的类型检查中，对虚拟机的性能无影响。而`undefined | A`被视为联合类型，运行时可能有额外的开销。
- 从代码可读性、简洁性的角度来说，`prop?:A`是`prop： A | undefined = undefined`的语法糖，**推荐使用可选属性的写法**

### 严格函数类型检查

**应用代码**

```typescript
function foo(fn: (value?: string) => void, value: string): void {}

foo((value: string) => {}, ''); //error
```

**建议改法**

```typescript
function foo(fn: (value?: string) => void, value: string): void {}

foo((value?: string) => {}, '');
```

**原因**

例如，在以下的例子中，如果编译期不开启严格函数类型的检查，那么该段代码可以编译通过，但是在运行时会产生非预期的行为。具体来看，在`foo`的函数体中，一个`undefined`被传入`fn`（这是可以的，因为`fn`可以接受`undefined`），但是在代码第6行`foo`的调用点，传入的`(value： string) => { console.log(value.toUpperCase()) }`的函数实现中，始终将参数`value`当做string类型，允许其调用`toUpperCase`方法。如果不开启严格函数类型的检查，那么这段代码在运行时，会出现在`undefined`上无法找到属性的错误。

```typescript
function foo(fn: (value?: string) => void, value: string): void {
  let v: string | undefined = undefined;
  fn(v);
}

foo((value: string) => { console.log(value.toUpperCase()) }, ''); // Cannot read properties of undefined (reading 'toUpperCase')
```

为了避免运行时的非预期行为，如果在编译时开启了严格类型检查，这段代码将编译不通过，从而可以提醒开发者修改代码，保证程序安全。

### 严格空值检查

**应用代码**

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

**建议改法**

在编写代码时，建议减少可空类型的使用。如果对变量、属性标记了可空类型，那么在使用它们之间，需要进行空值的判断，根据是否为空值处理不同的逻辑。

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

**原因**

在第一段代码中，如果编译期不开启严格空值检查，那么该段代码可以编译通过，但是在运行时会产生非预期的行为。这是因为`t`的属性`value`为`undefined`（这是因为`value?: string`是`value: string | undefined = undefined`的语法糖），在第11行调用`printValue`方法时，由于在该方法体内未对`this.value`的值进行空值检查，而直接按照`string`类型访问其属性，这就导致了运行时的错误。为了避免运行时的非预期行为，如果在编译时开起来严格空值检查，这段代码将编译不通过从而可以提醒开发者修改代码（如按照第二段代码的方式），保证程序安全。

### 函数返回类型不匹配

**应用代码**

```typescript
class Test {
  handleClick: (action: string, externInfo?: string) => void | null = null;
}
```

**建议改法**

在这种写法下，函数返回类型被解析为 `void | undefined`，需要添加括号用来区分union类型。

```typescript
class Test {
  handleClick: ((action: string, externInfo?: string) => void) | null = null;
}
```

### '***' is of type 'unknown'

**应用代码**

```typescript
try {
  
} catch (error) {
  console.log(error.message);
}
```

**建议改法**

```typescript
import { BusinessError } from '@kit.BasicServicesKit'

try {
  
} catch (error) {
  console.log((error as BusinessError).message);
}
```

### Type '*** | null' is not assignable to type '\*\*\*'

**应用代码**

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

**建议改法1**

修改变量`a`的类型：`let a: A | null = foo()`。

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
  // 非空分支
} else {
  // 处理null
}
```

**建议改法2**

如果可以断定此处调用`foo`一定返回非空值，可以使用非空断言`!`。

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

**应用代码**

```typescript
interface A {
  foo?: () => void
}

let a:A = { foo: () => {} };
a.foo();
```

**建议改法1**

```typescript
interface A {
  foo: () => void
}
let a: A = { foo: () => {} };
a.foo();
```

**建议改法2**

```typescript
interface A {
  foo?: () => void
}

let a: A = { foo: () => {} };
if (a.foo) {
  a.foo();
}
```

**原因**

在原先代码的定义中，foo是可选属性，有可能为undefined，对undefined的调用会导致报错。建议按照业务逻辑判断是否需要为可选属性。如果确实需要，那么在访问到该属性后需要进行空值检查。

### Variable '***' is used before being assigned

**应用代码**

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

**建议改法**

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

**原因**

对于primitive types，可以根据业务逻辑赋值，例如0，''，false。

对于对象类型，可以将类型修改为和null的联合类型，并赋值null，使用时需要进行非空检查。

### Function lacks ending return statement and return type does not include 'undefined'.

**应用代码**

```typescript
function foo(a: number): number {
  if (a > 0) {
    return a;
  }
}
```

**建议改法1** 

根据业务逻辑，在else分支中返回合适的数值

**建议改法2**

```typescript
function foo(a: number): number | undefined {
  if (a > 0) {
    return a;
  }
  return
}
```

## arkts-strict-typing-required

**应用代码**

```typescript
// @ts-nocheck
var a: any = 123;
```

**建议改法**

```typescript
let a: number = 123;
```

**原因**

ArkTS不支持通过注释的方式绕过严格类型检查。首先将注释（`// @ts-nocheck`或者`// @ts-ignore`）删去，再根据报错信息修改其他代码。

## Importing ArkTS files to JS and TS files is not allowed

## arkts-no-tsdeps

不允许.ts、.js文件`import`.ets文件源码。

**建议改法**

方式1.将.ts文件的后缀修改成ets，按照ArkTS语法规则适配代码。

方式2.将.ets文件中被.ts文件依赖的代码单独抽取到.ts文件中。

## arkts-no-special-imports

**应用代码**

```typescript
import type {A, B, C, D } from '***'
```


**建议改法**

```typescript
import {A, B, C, D } from '***'
```

## arkts-no-classes-as-obj

### 使用class构造实例

**应用代码**

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

**建议改法**

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

### 访问静态属性

**应用代码**

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

**建议改法**

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

改用动态import

**应用代码**

```typescript
import 'module'
```

**建议改法**

```typescript
import('module')
```

## arkts-no-func-props

**应用代码**

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

**建议改法**

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

**应用代码**

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

**建议改法**

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

## 拷贝

### 浅拷贝

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

### 深拷贝

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

## 状态管理使用典型场景

### Struct组件外使用状态变量

由于struct和class不同，不建议把this作为参数传递到struct外部使用，避免引起实例引用无法释放的情况，导致内存泄露。建议将状态变量对象传递到struct外面使用，通过修改对象的属性，来触发UI刷新。

**不推荐用法**

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
      this.controller.setItem(this); // 不建议把this作为参数传递到struct外部使用
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

**推荐用法**

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

### Struct支持联合类型的方案

下面这段代码有arkts-no-any-unknown的报错，由于struct不支持泛型，建议使用联合类型，实现自定义组件类似泛型的功能。

**不推荐用法**

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
  arrayList: any[]; // struct不支持泛型，有arkts-no-any-unknown报错
  @BuilderParam closer: (data: any) => void = this.componentCloser; // struct不支持泛型，有arkts-no-any-unknown报错

  @Builder
  componentCloser() {
  }

  build() {
    Column() {
      ForEach(this.arrayList, (item: any) => { // struct不支持泛型，有arkts-no-any-unknown报错
        Row() {
          this.closer(item)
        }.width('100%').height(200).backgroundColor('#eee')
      })
    }
  }
}
```

**推荐用法**

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