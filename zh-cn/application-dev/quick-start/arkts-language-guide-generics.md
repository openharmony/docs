# 泛型
<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

泛型是TypeScript/ArkTS中强大的类型系统特性，允许在定义函数、类、接口时使用类型参数，实现代码的复用和类型安全。

## 泛型的基础概念

泛型让类型成为参数，使一份代码适用于多种类型且保持编译期类型安全，是构建可复用数据结构和工具函数的核心机制。

### 泛型的定义与核心价值

泛型让类型参数化，一份代码适用于多种类型且保持编译期类型安全，编译器在调用处检查类型参数后将其擦除，兼顾复用性、类型推断与零运行时开销。

<!-- @[generics_introduction](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
// 不使用泛型：需要为每种类型编写函数
function identityNumber(arg: number): number {
  return arg;
}

function identityString(arg: string): string {
  return arg;
}

// 使用泛型：一个函数适用于所有类型
function identity<T>(arg: T): T {
  return arg;
}

let num: number = identity<number>(42);
let str: string = identity<string>('Hello');
let bool: boolean = identity<boolean>(true);

console.info(`${num}`);   // 42
console.info(`${str}`);   // Hello
console.info(`${bool}`);  // true
```

### 泛型解决的问题

使用`Object`类型会丢失具体类型信息，泛型在复用逻辑的同时保留传入值的原始类型。

<!-- @[ts_generics_vs_object](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Generics.ts) -->

``` TypeScript
// 使用Object类型会丢失具体类型信息
function identityObject(arg: Object): Object {
  return arg;
}

let result1 = identityObject(42);
// result1的类型是Object，无法直接作为number使用

// 使用泛型保留类型信息
function identityGeneric<T>(arg: T): T {
  return arg;
}

let result2 = identityGeneric(42);
// result2的类型自动推断为number
result2.toUpperCase(); // 编译错误：类型错误提示
```

泛型同样适用于数据结构，避免为每种元素类型重复定义类。

<!-- @[generic_stack_class](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
// 不使用泛型：为每种类型创建数据结构
class NumberStack {
  private items: number[] = [];
  
  push(item: number): void {
    this.items.push(item);
  }
  
  pop(): number | undefined {
    return this.items.pop();
  }
}

class StringStack {
  private items: string[] = [];
  
  push(item: string): void {
    this.items.push(item);
  }
  
  pop(): string | undefined {
    return this.items.pop();
  }
}

// 使用泛型：一个数据结构适用于所有类型
class Stack<T> {
  private items: T[] = [];
  
  push(item: T): void {
    this.items.push(item);
  }
  
  pop(): T | undefined {
    return this.items.pop();
  }
}

let numberStack: Stack<number> = new Stack<number>();
let stringStack: Stack<string> = new Stack<string>();

numberStack.push(1);
numberStack.push(2);
console.info(`${numberStack.pop()}`); // 2

stringStack.push('Hello');
stringStack.push('World');
console.info(`${stringStack.pop()}`); // World
```

### 泛型的工作原理

泛型通过类型参数`<T>`占位，定义时不绑定具体类型，调用时再指定或由编译器推断。

<!-- @[generic_function_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
// 泛型定义
function genericIdentity<T>(arg: T): T {
  return arg;
}

// 使用时指定具体类型
let genericOutput1 = genericIdentity<string>('Hello');
// 等价于：
function genericIdentityString(arg: string): string {
  return arg;
}

let genericOutput2 = genericIdentity<number>(42);
// 等价于：
function genericIdentityNumber(arg: number): number {
  return arg;
}

// 类型自动推断
let genericOutput3 = genericIdentity('ArkTS');  // 自动推断T为string
```

## 泛型函数

泛型函数支持多种类型参数，实现可复用的类型安全代码。

### 泛型函数的声明语法

在函数名后用`<T>`声明类型参数，在参数和返回值中使用该参数。

<!-- @[generic_function_declarations](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
// 基本泛型函数声明
function declarationsIdentity<T>(arg: T): T {
  return arg;
}

// 箭头函数形式的泛型函数
const identityArrow = <T>(arg: T): T => arg;

// 使用类型别名的泛型函数
type IdentityFunction = <T>(arg: T) => T;
let identityAlias: IdentityFunction = declarationsIdentity;

console.info(`${declarationsIdentity<number>(42)}`);       // 42
console.info(`${identityArrow<string>('Hello')}`); // Hello
console.info(`${identityAlias<boolean>(true)}`);   // true
```

### 类型参数的命名规范

类型参数通常使用大写字母命名，常见约定如`T`（Type）、`U`、`K`（Key）、`V`（Value）、`E`（Element）。

<!-- @[multi_type_parameter_class](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
// 使用不同命名规范的示例
class Pair<T, U> {
  public first: T;
  public second: U;

  constructor(first: T, second: U) {
    this.first = first;
    this.second = second;
  }
}

interface Person {
  name: string;
  age: number;
  email: string;
}

let personInfo: Pair<string, number> = new Pair<string, number>('Alice', 25);

console.info(`${personInfo.first}`);  // Alice
console.info(`${personInfo.second}`); // 25
```

### 泛型函数的调用方式

调用泛型函数时可显式指定类型参数，也可省略由编译器根据实参自动推断。

<!-- @[generic_type_inference](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
function genericIdentityInferred<T>(arg: T): T {
  return arg;
}

// 显式指定类型参数
let result1: string = genericIdentityInferred<string>('Hello');
console.info(`${result1}`);

// 类型参数自动推断
let result2: string = genericIdentityInferred('World');
console.info(`${result2}`);

// 多类型参数的泛型函数
function createPair<T, U>(first: T, second: U): [T, U] {
  return [first, second];
}

let pair1: [string, number] = createPair<string, number>('Age', 25);
let pair2: [string, number] = createPair('Height', 180); // 自动推断为 [string, number]

console.info(`${pair1[0]}: ${pair1[1]}`); // Age: 25
console.info(`${pair2[0]}: ${pair2[1]}`); // Height: 180
```

### 多类型参数的泛型函数

函数可声明多个类型参数（如`<T, U>`），各自独立占位，支持不同类型间的关系表达。

<!-- @[multi_type_parameter_function](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
// 多类型参数的基本用法
function swap<T, U>(a: T, b: U): [U, T] {
  return [b, a];
}

let swapped: [string, number] = swap(1, 'Hello');
console.info(`${swapped[0]}, ${swapped[1]}`); // Hello, 1

// 多类型参数的复杂用法：用显式结构保存两个不同类型的值
interface PairValue<T, U> {
  left: T;
  right: U;
}

function combineValues<T, U>(left: T, right: U): PairValue<T, U> {
  return {
    left: left,
    right: right
  };
}

interface Name {
  name: string;
}

interface Age {
  age: number;
}

let nameObj: Name = { name: 'Alice' };
let ageObj: Age = { age: 25 };

let combinedObj: PairValue<Name, Age> = combineValues<Name, Age>(nameObj, ageObj);
console.info(`${combinedObj.left.name}`);
console.info(`${combinedObj.right.age}`);

// 使用类型参数创建映射函数
function mapArray<T, R>(arr: T[], mapper: (item: T) => R): R[] {
  let result: R[] = [];
  for (let item of arr) {
    result.push(mapper(item));
  }
  return result;
}

let numbers: number[] = [1, 2, 3, 4, 5];
let doubled: number[] = mapArray<number, number>(numbers, (n: number): number => n * 2);
console.info(`${doubled.join(', ')}`); // 2, 4, 6, 8, 10

let strings: string[] = ['a', 'b', 'c'];
let uppercased: string[] = mapArray<string, string>(strings, (s: string): string => s.toUpperCase());
console.info(`${uppercased.join(', ')}`); // A, B, C
```

## 泛型类

泛型类创建类型安全的类，支持多种数据类型。

### 泛型类的声明语法

在类名后用`<T>`声明类型参数，在类的属性和方法中使用。

<!-- @[generic_class_basic](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
// 基本泛型类声明
class Container<T> {
  private value: T;
  
  constructor(initialValue: T) {
    this.value = initialValue;
  }
  
  public getValue(): T {
    return this.value;
  }
  
  public setValue(newValue: T): void {
    this.value = newValue;
  }
}

let numberContainer: Container<number> = new Container<number>(42);
console.info(`${numberContainer.getValue()}`); // 42
numberContainer.setValue(100);
console.info(`${numberContainer.getValue()}`); // 100

let stringContainer: Container<string> = new Container<string>('Hello');
console.info(`${stringContainer.getValue()}`); // Hello
stringContainer.setValue('World');
console.info(`${stringContainer.getValue()}`); // World
```

### 泛型类的实例化

实例化泛型类时通过`new ClassName<Type>(...)`指定类型参数，类型一致时可省略由编译器推断。

<!-- @[generic_class_instantiation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
class GciContainer<T> {
  private value: T;

  constructor(value: T) {
    this.value = value;
  }

  getValue(): T {
    return this.value;
  }
}

// 显式指定类型参数实例化
let gciContainer1: GciContainer<number> = new GciContainer<number>(10);

// 类型参数自动推断实例化
let gciContainer2: GciContainer<string> = new GciContainer<string>('hello');

// 类型参数可以省略（编译器推断）
let gciContainer3: GciContainer<boolean> = new GciContainer<boolean>(true);

console.info(`${gciContainer1.getValue()}`); // 10
console.info(`${gciContainer2.getValue()}`); // hello
console.info(`${gciContainer3.getValue()}`); // true
```

### 泛型类中的属性与方法

泛型类的属性和方法可以使用类型参数，实现类型安全的容器和操作。例如`GenericCollection<T>`的`add(item: T)`确保只能添加`T`类型元素，`get(index: number): T`返回值自动推断为`T`类型，无需类型断言。

<!-- @[generic_collection_class](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
class GenericCollection<T> {
  // 泛型属性
  private items: T[] = [];
  public count: number = 0;
  
  // 泛型方法
  public add(item: T): void {
    this.items.push(item);
    this.count++;
  }
  
  public remove(item: T): boolean {
    let index = this.items.indexOf(item);
    if (index > -1) {
      this.items.splice(index, 1);
      this.count--;
      return true;
    }
    return false;
  }
  
  public get(index: number): T | undefined {
    return this.items[index];
  }
  
  public getAll(): T[] {
    return this.items;
  }
  
  // 泛型方法返回泛型类型
  public filter(predicate: (item: T) => boolean): GenericCollection<T> {
    let filtered = new GenericCollection<T>();
    this.items.forEach((item: T): void => {
      if (predicate(item)) {
        filtered.add(item);
      }
    });
    return filtered;
  }
}

let collection: GenericCollection<number> = new GenericCollection<number>();
collection.add(1);
collection.add(2);
collection.add(3);
collection.add(4);
collection.add(5);

console.info(`${collection.count}`); // 5
console.info(`${collection.get(0)}`); // 1

let evenNumbers: GenericCollection<number> = collection.filter((n: number): boolean => n % 2 === 0);
console.info(`${evenNumbers.getAll().join(', ')}`); // 2, 4
```

### 多类型参数的泛型类

泛型类可声明多个类型参数（如`<K, V>`），常用于键值对等需要多种类型协作的结构。

<!-- @[multi_type_parameter_generic_class](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
// 多类型参数的泛型类
class ParamPair<K, V> {
  private key: K;
  private value: V;
  
  constructor(key: K, value: V) {
    this.key = key;
    this.value = value;
  }
  
  public getKey(): K {
    return this.key;
  }
  
  public getValue(): V {
    return this.value;
  }
  
  public setKey(newKey: K): void {
    this.key = newKey;
  }
  
  public setValue(newValue: V): void {
    this.value = newValue;
  }
  
  public toString(): string {
    return `(${this.key}: ${this.value})`;
  }
}

let paramPair1: ParamPair<string, number> = new ParamPair<string, number>('Age', 25);
console.info(`${paramPair1.toString()}`); // (Age: 25)

let paramPair2: ParamPair<number, string> = new ParamPair<number, string>(1, 'One');
console.info(`${paramPair2.toString()}`); // (1: One)

// 多类型参数的复杂泛型类
class Triple<A, B, C> {
  private first: A;
  private second: B;
  private third: C;
  
  constructor(first: A, second: B, third: C) {
    this.first = first;
    this.second = second;
    this.third = third;
  }
  
  public getFirst(): A {
    return this.first;
  }
  
  public getSecond(): B {
    return this.second;
  }
  
  public getThird(): C {
    return this.third;
  }
  
  public toArray(): [A, B, C] {
    return [this.first, this.second, this.third];
  }
}

let triple: Triple<string, number, boolean> = new Triple<string, number, boolean>('Hello', 42, true);
let tripleValues: [string, number, boolean] = triple.toArray();
console.info(`${tripleValues[0]}, ${tripleValues[1]}, ${tripleValues[2]}`); // Hello,42,true
```

ArkTS支持元组类型（如`[A, B, C]`）作为返回类型和变量类型，元素通过索引访问（`tuple[0]`）；但不支持元组解构语法（如`let [a, b, c] = tuple`），需通过索引逐个提取。

## 泛型接口

泛型接口将类型参数引入契约定义，使一份接口可适配多种数据类型，常用于回调、仓库等抽象。

### 泛型接口的声明语法

在接口名后用`<T>`声明类型参数，在成员签名中使用。

<!-- @[generic_interface_basic](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
// 基本泛型接口声明
interface GenericIdentity {
  invoke<T>(arg: T): T;
}

class GenericIdentityImpl implements GenericIdentity {
  public invoke<T>(arg: T): T {
    return arg;
  }
}

// 泛型接口作为函数类型
let myIdentity: GenericIdentity = new GenericIdentityImpl();

console.info(`${myIdentity.invoke<string>('Hello')}`); // Hello

// 泛型参数作为接口参数
interface GenericIdentityFunction<T> {
  invoke(arg: T): T;
}

class NumberIdentityFunction implements GenericIdentityFunction<number> {
  public invoke(arg: number): number {
    return arg;
  }
}

let myIdentityFunction: GenericIdentityFunction<number> = new NumberIdentityFunction();

console.info(`${myIdentityFunction.invoke(42)}`); // 42
```

### 泛型接口作为函数类型约束

用泛型接口描述回调或函数签名，使回调的类型参数与具体实现保持一致。

<!-- @[generic_interface_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
// 泛型接口定义函数类型
interface Callback<T> {
  invoke(result: T): void;
}

interface AsyncCallback<T> {
  invoke(result: T): Promise<void>;
}

// 使用泛型接口约束函数类型
function processData<T>(data: T, callback: Callback<T>): void {
  callback.invoke(data);
}

class StringCallback implements Callback<string> {
  public invoke(result: string): void {
    console.info(`Processed: ${result}`);
  }
}

class NumberCallback implements Callback<number> {
  public invoke(result: number): void {
    console.info(`Processed: ${result}`);
  }
}

processData<string>('Hello', new StringCallback());

processData<number>(42, new NumberCallback());

// 异步函数使用泛型接口
async function processAsyncData<T>(data: T, callback: AsyncCallback<T>): Promise<void> {
  await callback.invoke(data);
}

class AsyncStringCallback implements AsyncCallback<string> {
  public async invoke(result: string): Promise<void> {
    console.info(`Async processed: ${result}`);
  }
}

processAsyncData<string>('Hello', new AsyncStringCallback());
```

### 泛型接口作为类的实现约束

类实现泛型接口时需指定具体类型参数，统一约束该类对外暴露的方法签名与实体类型。

<!-- @[generic_interface_repository](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
interface Repository<T> {
  findById(id: number): T | null;
  findAll(): T[];
  save(entity: T): void;
  delete(id: number): void;
}

interface User {
  id: number;
  name: string;
  email: string;
}

class UserRepository implements Repository<User> {
  private users: User[] = [];
  
  public findById(id: number): User | null {
    return this.users.find((user: User): boolean => user.id === id) ?? null;
  }
  
  public findAll(): User[] {
    return [...this.users];
  }
  
  public save(entity: User): void {
    let existing: User | null = this.findById(entity.id);
    if (existing !== null) {
      let index = this.users.indexOf(existing);
      this.users[index] = entity;
    } else {
      this.users.push(entity);
    }
  }
  
  public delete(id: number): void {
    this.users = this.users.filter((user: User): boolean => user.id !== id);
  }
}

let userRepo = new UserRepository();

userRepo.save({ id: 1, name: 'Alice', email: 'alice@example.com' });
userRepo.save({ id: 2, name: 'Bob', email: 'bob@example.com' });

console.info(`${userRepo.findAll().length}`); // 2
console.info(`${userRepo.findById(1)?.name}`); // Alice

userRepo.delete(1);
console.info(`${userRepo.findAll().length}`); // 1
```

### 泛型接口的默认类型参数

泛型接口的默认类型参数在未指定时使用默认类型，简化调用。

<!-- @[generic_interface_default_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
// 泛型接口的默认类型参数
interface ApiResponse<T = string> {
  data: T;
  status: number;
  message: string;
}

// 使用默认类型
let response1: ApiResponse = {
  data: 'OK',
  status: 200,
  message: 'Success'
};

// 指定具体类型
let response2: ApiResponse<string> = {
  data: 'Hello',
  status: 200,
  message: 'Success'
};

console.info(`${response1.data}`);
console.info(`${response2.data}`);

// 多类型参数的默认值
interface DefaultPair<T = string, U = number> {
  first: T;
  second: U;
}

let defaultPair1: DefaultPair = { first: 'Hello', second: 42 };
let defaultPair2: DefaultPair<number> = { first: 100, second: 200 };
let pair3: DefaultPair<number, string> = { first: 100, second: 'Hello' };

console.info(`${defaultPair1}`);
console.info(`${defaultPair2}`);
console.info(`${pair3}`);
```

## 泛型类型约束

通过`extends`对类型参数施加约束，限定其必须满足的接口或结构，使泛型在灵活性与类型安全间取得平衡。

### 基础类型约束

用`<T extends SomeInterface>`约束类型参数必须具备特定结构（如`length`属性），不满足则编译报错。

<!-- @[ts_generic_constraint_length](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Generics.ts) -->

``` TypeScript
// 约束泛型参数必须具有length属性
interface Lengthwise {
  length: number;
}

function getLength<T extends Lengthwise>(arg: T): number {
  return arg.length;
}

class LengthSample implements Lengthwise {
  public length: number;

  constructor(length: number) {
    this.length = length;
  }
}

console.info(`${getLength('Hello')}`);        // 5
console.info(`${getLength([1, 2, 3])}`);      // 3
console.info(`${getLength(new LengthSample(10))}`); // 10

// 编译错误：number类型没有length属性
console.info(`${getLength(42)}`);
```

### 约束为特定接口/类

将类型参数约束为某个接口或类，确保泛型函数内可调用该接口定义的方法。

<!-- @[ts_generic_constraint_serializable](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Generics.ts) -->

``` TypeScript
interface Serializable {
  serialize(): string;
}

class User implements Serializable {
  public name: string;
  public age: number;

  constructor(name: string, age: number) {
    this.name = name;
    this.age = age;
  }

  public serialize(): string {
    return JSON.stringify({ name: this.name, age: this.age });
  }
}

class Product implements Serializable {
  public id: number;
  public title: string;

  constructor(id: number, title: string) {
    this.id = id;
    this.title = title;
  }

  public serialize(): string {
    return JSON.stringify({ id: this.id, title: this.title });
  }
}

// 约束泛型参数必须实现Serializable接口
function saveToStorage<T extends Serializable>(entity: T): void {
  let serialized = entity.serialize();
  console.info(`Saving: ${serialized}`);
}

let user = new User('Alice', 25);
let product = new Product(1, 'Laptop');

saveToStorage(user);    // Saving: {"name":"Alice","age":25}
saveToStorage(product); // Saving: {"id":1,"title":"Laptop"}

// 编译错误：number类型没有serialize方法
saveToStorage(42);
```

### 约束包含特定属性

通过接口定义所需属性集合，约束类型参数必须同时拥有这些属性，可叠加多个接口约束。

<!-- @[generic_constraint_property](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
interface HasId {
  id: number;
}

interface HasName {
  name: string;
}

// 约束泛型参数必须包含id属性
function findById<T extends HasId>(items: T[], id: number): T | null {
  for (let item of items) {
    if (item.id === id) {
      return item;
    }
  }
  return null;
}

// 约束泛型参数必须包含name属性
function findByName<T extends HasName>(items: T[], name: string): T | null {
  for (let item of items) {
    if (item.name === name) {
      return item;
    }
  }
  return null;
}

interface ConstraintUser {
  id: number;
  name: string;
  email: string;
}

let users: ConstraintUser[] = [
  { id: 1, name: 'Alice', email: 'alice@example.com' },
  { id: 2, name: 'Bob', email: 'bob@example.com' },
  { id: 3, name: 'Charlie', email: 'charlie@example.com' }
];

let userById: ConstraintUser | null = findById<ConstraintUser>(users, 1);
let userByName: ConstraintUser | null = findByName<ConstraintUser>(users, 'Bob');
console.info(`${userById ? userById.name : ''}`);    // Alice
console.info(`${userByName ? userByName.id : 0}`); // 2
```

### 多约束条件的组合

TypeScript常用交叉类型组合多个约束。ArkTS中优先声明一个继承多个接口的具名接口，再把泛型参数约束到该接口。

<!-- @[generic_constraint_multiple](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
interface MultipleHasId {
  id: number;
}

interface MultipleHasName {
  name: string;
}

interface HasTimestamp {
  createdAt: Date;
  updatedAt: Date;
}

interface NamedEntity extends MultipleHasId, MultipleHasName {}

interface AuditedEntity extends MultipleHasId, MultipleHasName, HasTimestamp {}

// 多约束条件的组合
function findEntity<T extends NamedEntity>(items: T[], id: number, name: string): T | null {
  return items.find(item => item.id === id && item.name === name) || null;
}

// 三重约束
function logEntity<T extends AuditedEntity>(entity: T): void {
  console.info(`ID: ${entity.id}, Name: ${entity.name}, Created: ${entity.createdAt}`);
}

interface MultipleUser extends MultipleHasId, MultipleHasName, HasTimestamp {
  email: string;
}

let user: MultipleUser = {
  id: 1,
  name: 'Alice',
  email: 'alice@example.com',
  createdAt: new Date('2024-01-01'),
  updatedAt: new Date('2024-01-02')
};

logEntity(user);
```

## TypeScript泛型工具类型对照

TypeScript提供了`Partial<T>`、`Required<T>`、`Readonly<T>`、`Pick<T, K>`、`Omit<T, K>`、`Record<K, T>`等泛型工具类型，用于在类型层面对已有类型做变换。ArkTS对`Partial<T>`、`Required<T>`、`Readonly<T>`、`Record<K, T>`等工具类型有限制支持；对`Pick<T, K>`、`Omit<T, K>`等复杂类型变换，普通教程中优先使用显式接口、类或泛型约束表达业务结构。

### 使用显式接口替代Pick和Omit

ArkTS不支持`Pick<T,K>`和`Omit<T,K>`，详见[从TypeScript到ArkTS的适配规则](typescript-to-arkts-migration-guide.md#不支持一些utility类型)，改用显式定义的接口表达所需的属性子集。

<!-- @[related_interfaces](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
interface Product {
  id: number;
  title: string;
  description: string;
  price: number;
  stock: number;
  category: string;
}

interface ProductSummary {
  id: number;
  title: string;
  price: number;
}

interface CreateProductRequest {
  title: string;
  description: string;
  price: number;
  stock: number;
  category: string;
}

let summary: ProductSummary = {
  id: 1,
  title: 'Laptop',
  price: 999
};

let createRequest: CreateProductRequest = {
  title: 'Smartphone',
  description: 'High-end smartphone',
  price: 599,
  stock: 100,
  category: 'Electronics'
};
```
这种写法比类型变换更直接，也更便于API文档和代码审查。

### 使用Map或类替代复杂Record

使用Map或类替代复杂Record类型，获得更清晰的类型约束。

<!-- @[generic_map](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
interface MenuItem {
  label: string;
  path: string;
  icon?: string;
}

let menu: Map<string, MenuItem> = new Map<string, MenuItem>();
menu.set('home', { label: 'Home', path: '/', icon: 'home-icon' });
menu.set('contact', { label: 'Contact', path: '/contact' });

let home: MenuItem | undefined = menu.get('home');
if (home !== undefined) {
  console.info(`${home.label}`);
}
```
如果字段集合固定，使用接口比动态字典更清晰。

### 使用readonly字段替代Readonly

用`readonly`修饰符标记类属性为只读，替代`Readonly<T>`实现不可变字段约束。

<!-- @[readonly_user](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
class ReadonlyUser {
  public readonly id: number;
  public readonly name: string;

  constructor(id: number, name: string) {
    this.id = id;
    this.name = name;
  }
}

let userUser: ReadonlyUser = new ReadonlyUser(1, 'Alice');
console.info(`${userUser.name}`);
```

### 使用可选字段替代Partial

用`?`修饰符定义可选属性，替代`Partial<T>`表达部分更新的对象结构。

<!-- @[partial_update_request](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
interface UpdateUserRequest {
  name?: string;
  email?: string;
  age?: number;
}

function updateUser(id: number, request: UpdateUserRequest): void {
  console.info(`Update user ${id}`);
  if (request.name !== undefined) {
    console.info(`${request.name}`);
  }
}
```

## 泛型的高级边界

泛型约束通过extends限制类型范围，支持嵌套和递归约束。ArkTS的泛型约束行为与TypeScript基本一致，支持`extends`约束、多参数约束和约束类型参数引用其他类型参数等用法。

### 条件类型、映射类型与infer

条件类型、映射类型和infer是TypeScript的高级类型工具，ArkTS中不作为常规语法使用。

<!-- @[ts_utility_types_note](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Generics.ts) -->

``` TypeScript
// TypeScript写法，ArkTS中不作为常规语法使用
type Nullable<T> = T | null;
type ReadonlyProps<T> = { readonly [P in keyof T]: T[P] };
type ElementType<T> = T extends Array<infer Item> ? Item : T;
```

### 泛型类型推断的边界

编译器根据实参推断类型参数，但当存在多个候选或联合类型时推断可能不够精确，需要显式指定。

<!-- @[generic_first_element](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
function first<T>(items: T[]): T | undefined {
  return items.length > 0 ? items[0] : undefined;
}

let names: string[] = ['Alice', 'Bob'];
let firstName: string | undefined = first<string>(names);
```

### 泛型参数的默认值

泛型参数默认值在未指定时使用默认类型，减少调用时的类型参数。

<!-- @[generic_default_type_parameter](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
// 泛型参数默认值
interface ParamApiResponse<T = string, E = Error> {
  data: T;
  error?: E;
  status: number;
}

class CustomError extends Error {
  public code: number;
  
  constructor(message: string) {
    super(message);
    this.code = 404;
  }
}

// 使用默认类型参数
let paramResponse1: ParamApiResponse = {
  data: 'Hello',
  status: 200
};

// 指定部分类型参数
let paramResponse2: ParamApiResponse<string> = {
  data: 'Hello',
  status: 200
};

// 指定所有类型参数
let response3: ParamApiResponse<string, CustomError> = {
  data: 'Hello',
  error: new CustomError('Not found'),
  status: 404
};

console.info(`${paramResponse1.data}`);
console.info(`${paramResponse2.data}`);
console.info(`${response3.error?.message}`);
```

### 泛型与嵌套类型的结合

泛型与嵌套类型结合，构建递归数据结构如树和链表。

<!-- @[generic_nested_types](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
// 泛型嵌套类型：树
interface TsTree<T> {
  value: T;
  children?: TsTree<T>[];
}

let tsLeaf4: TsTree<number> = { value: 4 };
let tsLeaf5: TsTree<number> = { value: 5 };
let tsBranch3: TsTree<number> = { value: 3, children: [tsLeaf4, tsLeaf5] };
let tsBranch2: TsTree<number> = { value: 2 };
let tsNumberTree: TsTree<number> = {
  value: 1,
  children: [tsBranch2, tsBranch3]
};

console.info(`${tsNumberTree.value}`); // 1
console.info(`${tsNumberTree.children?.[0].value}`); // 2

// 泛型嵌套类型：链表
interface TsListNode<T> {
  value: T;
  next?: TsListNode<T>;
}

let tsThird: TsListNode<string> = { value: 'third' };
let tsSecond: TsListNode<string> = { value: 'second', next: tsThird };
let tsFirst: TsListNode<string> = { value: 'first', next: tsSecond };

let tsCurrent: TsListNode<string> | undefined = tsFirst;
while (tsCurrent !== undefined) {
  console.info(`${tsCurrent.value}`); // first, second, third
  tsCurrent = tsCurrent.next;
}
```

## keyof类型操作符

`keyof`是TypeScript的类型操作符，用于获取对象类型的所有属性名联合。ArkTS中有限支持，普通业务代码优先使用显式类型声明。

**TypeScript对照**

<!-- @[ts_keyof_operator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Generics.ts) -->

``` TypeScript
// TypeScript对照写法，ArkTS中不作为常规语法使用
interface KeyofPointType {
  x: number;
  y: number;
}
type P = keyof KeyofPointType;  // "x" | "y"

function getProperty<T, K extends keyof T>(obj: T, key: K) {
  return obj[key];
}
```

ArkTS中优先使用显式属性名和类型标注替代`keyof`。

<!-- @[keyof_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
interface KeyofPoint {
  x: number;
  y: number;
}

function keyofGetX(p: KeyofPoint): number {
  return p.x;
}

function keyofGetY(p: KeyofPoint): number {
  return p.y;
}

let keyofPt: KeyofPoint = { x: 10, y: 20 };
console.info(`${keyofGetX(keyofPt).toString()}`);  // 10
console.info(`${keyofGetY(keyofPt).toString()}`);  // 20
```

## typeof类型操作符

`typeof`在TypeScript类型上下文中用于从运行时值获取其类型。ArkTS中不作为常规类型操作使用，优先显式声明类型。

**TypeScript对照**

<!-- @[ts_typeof_operator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Generics.ts) -->

``` TypeScript
// TypeScript对照写法，ArkTS中不作为常规语法使用
let tsConfig = { url: 'EXAMPLE_API_URL', timeout: 5000 };
type TsConfig = typeof tsConfig; // { url: string; timeout: number; }
```

ArkTS中优先使用interface显式声明。

<!-- @[typeof_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
interface TypeofConfig {
  url: string;
  timeout: number;
}

let typeofConfig: TypeofConfig = {
  url: 'EXAMPLE_CONFIG_URL',
  timeout: 5000
};

console.info(`${typeofConfig.url}`);
console.info(`${typeofConfig.timeout.toString()}`);
```

## 索引访问类型

索引访问类型使用`T[K]`语法从已有类型中获取特定属性的类型。ArkTS不支持索引访问类型，优先使用显式类型声明。

**TypeScript对照**

<!-- @[ts_indexed_access](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Generics.ts) -->

``` TypeScript
// 变型标注：协变out、逆变in、不变in out
type IndexedPerson = { name: string; age: number; alive: boolean };
type IndexedName = IndexedPerson['name'];   // string
type IndexedAge = IndexedPerson['age'];     // number
```

ArkTS中直接使用属性类型。

<!-- @[indexed_access_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
interface IndexedAccessPerson {
  name: string;
  age: number;
  alive: boolean;
}

let iaPersonName: string = 'Alice';
let iaPersonAge: number = 30;
let iaPersonAlive: boolean = true;

console.info(`${iaPersonName}`);
console.info(`${iaPersonAge.toString()}`);
console.info(`${iaPersonAlive.toString()}`);
```

## 条件类型

条件类型形式为`T extends U ? X : Y`，类似类型层面的if语句。ArkTS不支持条件类型，优先使用函数重载或联合类型替代。

**TypeScript对照**

<!-- @[ts_conditional_types](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Generics.ts) -->

``` TypeScript
// 变型标注：协变out、逆变in、不变in out
type IsString<T> = T extends string ? true : false;
type CondA = IsString<string>;   // true
type CondB = IsString<number>;   // false

// infer关键字
type GetReturn<T> = T extends (...args: never[]) => infer R ? R : never;
type CondR = GetReturn<() => string>;  // string

// 分配性条件类型
type ToArray<T> = T extends unknown ? T[] : never;
type CondResult = ToArray<string | number>;  // string[] | number[]
```

ArkTS中使用函数重载或联合类型替代条件类型。

<!-- @[conditional_type_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
function formatCondValue(value: string): string;
function formatCondValue(value: number): string;
function formatCondValue(value: string | number): string {
  if (typeof value === 'string') {
    return value.toUpperCase();
  }
  return value.toFixed(2);
}

let condS: string = formatCondValue('hello');
let condN: string = formatCondValue(42);
console.info(`${condS}`);  // HELLO
console.info(`${condN}`);  // 42.00
```

## 映射类型

映射类型基于已有类型遍历每个属性生成新类型，语法为`{ [P in keyof T]: ... }`。ArkTS不支持映射类型，优先使用显式接口声明。

**TypeScript对照**

<!-- @[ts_mapped_types](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Generics.ts) -->

``` TypeScript
// 变型标注：协变out、逆变in、不变in out
type MappedReadonly<T> = { readonly [P in keyof T]: T[P] };
type MappedPartial<T> = { [P in keyof T]?: T[P] };

// 键重映射
type MappedGetters<T> = {
  [P in keyof T as `get${Capitalize<string & P>}`]: () => T[P]
};
```

ArkTS中显式声明替代映射类型。

<!-- @[mapped_type_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
interface MappedReadonlyUser {
  readonly id: number;
  readonly name: string;
}

interface MappedPartialUser {
  name?: string;
  age?: number;
  email?: string;
}

interface MappedUserGetters {
  getName(): string;
  getAge(): number;
}

class MappedUser implements MappedUserGetters {
  public name: string = '';
  public age: number = 0;

  getName(): string {
    return this.name;
  }

  getAge(): number {
    return this.age;
  }
}
```

## 变型标注

变型描述泛型类型参数的子类型关系如何传递到泛型类型本身。协变（`out`）表示子类型关系保持方向——`Producer<Cat>`是`Producer<Animal>`的子类型；逆变（`in`）表示方向反转——`Consumer<Animal>`是`Consumer<Cat>`的子类型；不变（`in out`）表示无子类型关系。ArkTS支持`in`/`out`/`in out`变型标注语法，编译器通常能自动推断变型关系，手动标注仅用于极少数循环类型场景。

<!-- @[variance_annotations](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
interface VaConsumer<in T> { consume: (arg: T) => void; }
interface VaProducer<out T> { make(): T; }
interface VaProducerConsumer<in out T> { consume: (arg: T) => void; make(): T; }
```

ArkTS中变型标注会被编译器处理，通常无需手动标注，编译器会自动推断变型关系。

## 更多实用类型对照

TypeScript还提供`Exclude`、`Extract`、`NonNullable`、`Parameters`、`ReturnType`等实用类型，ArkTS中需显式替代。

**Exclude与Extract**

<!-- @[ts_exclude_extract](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Generics.ts) -->

``` TypeScript
// TypeScript对照写法，ArkTS中不作为常规语法使用
type AllTypes = 'a' | 'b' | 'c';
type Excluded = Exclude<AllTypes, 'c'>;      // 'a' | 'b'
type Extracted = Extract<AllTypes, 'a' | 'x'>; // 'a'
```

ArkTS中直接声明联合类型。

<!-- @[exclude_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
type ExcludeAllTypes = 'a' | 'b' | 'c';
type ExcludeFiltered = 'a' | 'b';

let excludeValue: ExcludeFiltered = 'a';
console.info(`${excludeValue}`);
```

**NonNullable**

<!-- @[ts_nonnullable](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Generics.ts) -->

``` TypeScript
// TypeScript对照写法，ArkTS中不作为常规语法使用
type NullableType = string | null | undefined;
type NonNullType = NonNullable<NullableType>;  // string
```

ArkTS中直接使用非空类型。

<!-- @[nonnullable_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
let nnValue: string = 'hello';
console.info(`${nnValue}`);
```

**Parameters与ReturnType**

<!-- @[ts_parameters_returntype](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Generics.ts) -->

``` TypeScript
// TypeScript对照写法，ArkTS中不作为常规语法使用
function prFunction(s: string): number { return s.length; }
type PRParams = Parameters<typeof prFunction>;   // [string]
type PRReturn = ReturnType<typeof prFunction>;   // number
```

ArkTS中显式声明参数和返回值类型。

<!-- @[params_return_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
function prArkFunc(s: string): number {
  return s.length;
}

let prParam: string = 'hello';
let prResult: number = prArkFunc(prParam);
console.info(`${prResult.toString()}`);  // 5
```

**Awaited**

<!-- @[ts_awaited](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Generics.ts) -->

``` TypeScript
// TypeScript对照写法，ArkTS中不作为常规语法使用
type AwaitedType = Awaited<Promise<string>>;  // string
```

ArkTS中直接使用解包后的类型。

<!-- @[awaited_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
async function awaitedGetData(): Promise<string> {
  return 'hello';
}

async function awaitedMain(): Promise<void> {
  let data: string = await awaitedGetData();
  console.info(`${data}`);  // hello
}

awaitedMain();
```

**ConstructorParameters与InstanceType**

<!-- @[ts_ctor_params_instance_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Generics.ts) -->

``` TypeScript
// TypeScript对照写法，ArkTS中不作为常规语法使用
class CpPoint {
  constructor(public x: number, public y: number) {}
}
type CpCtorParams = ConstructorParameters<typeof CpPoint>; // [number, number]
type CpInstance = InstanceType<typeof CpPoint>;             // CpPoint
```

ArkTS中显式声明构造函数参数类型和实例类型。

<!-- @[ctor_params_instance_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
class CpaPoint {
  public x: number;
  public y: number;

  constructor(x: number, y: number) {
    this.x = x;
    this.y = y;
  }
}

let cpaParams: number[] = [3, 4];
let cpaInstance: CpaPoint = new CpaPoint(cpaParams[0], cpaParams[1]);
console.info(`${cpaInstance.x}, ${cpaInstance.y}`); // 3, 4
```

**字符串操作类型（Uppercase/Lowercase/Capitalize/Uncapitalize）**

<!-- @[ts_string_utils](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Generics.ts) -->

``` TypeScript
// TypeScript对照写法，ArkTS中不作为常规语法使用
type Upper = Uppercase<'hello'>;   // 'HELLO'
type Lower = Lowercase<'WORLD'>;   // 'world'
type Cap = Capitalize<'foo'>;      // 'Foo'
type Uncap = Uncapitalize<'Bar'>;  // 'bar'
```

ArkTS中直接使用字符串方法处理大小写转换。

<!-- @[string_method_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
let smUpperStr: string = 'hello'.toUpperCase();
let smLowerStr: string = 'WORLD'.toLowerCase();
console.info(`${smUpperStr}`); // HELLO
console.info(`${smLowerStr}`); // world
```

**ThisType**

TypeScript的`ThisType<T>`用于标记`this`的上下文类型，常在对象字面量中指定`this`类型。ArkTS中不使用`ThisType`，通过类和方法明确`this`的指向。

<!-- @[ts_thistype_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Generics.ts) -->

``` TypeScript
// TypeScript对照写法（ArkTS不支持）
interface MyContext {
  name: string;
}
const obj: ThisType<MyContext> = {
  greet() {
    return this.name;
  }
};
```

ArkTS替代：使用类明确`this`绑定。

<!-- @[thistype_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
class ThContext {
  public name: string;

  constructor(name: string) {
    this.name = name;
  }

  greet(): string {
    return this.name;
  }
}

let thCtx: ThContext = new ThContext('Alice');
console.info(`${thCtx.greet()}`); // Alice
```

## 泛型的使用场景

泛型常用于通用数据结构、工具函数和网络请求封装。

### 通用数据结构

泛型数据结构如栈、队列适用于任意元素类型。

<!-- @[generic_data_structures](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
// 通用栈数据结构
class StructuresStack<T> {
  private items: T[] = [];
  
  push(item: T): void {
    this.items.push(item);
  }
  
  pop(): T | undefined {
    return this.items.pop();
  }
  
  peek(): T | undefined {
    return this.items[this.items.length - 1];
  }
  
  isEmpty(): boolean {
    return this.items.length === 0;
  }
  
  size(): number {
    return this.items.length;
  }
  
  clear(): void {
    this.items = [];
  }
}

let structuresNumberStack = new StructuresStack<number>();
structuresNumberStack.push(1);
structuresNumberStack.push(2);
structuresNumberStack.push(3);

console.info(`${structuresNumberStack.pop()}`);    // 3
console.info(`${structuresNumberStack.peek()}`);   // 2
console.info(`${structuresNumberStack.size()}`);   // 2

// 通用队列数据结构
class Queue<T> {
  private items: T[] = [];
  
  enqueue(item: T): void {
    this.items.push(item);
  }
  
  dequeue(): T | undefined {
    return this.items.shift();
  }
  
  front(): T | undefined {
    return this.items[0];
  }
  
  isEmpty(): boolean {
    return this.items.length === 0;
  }
  
  size(): number {
    return this.items.length;
  }
}

let stringQueue = new Queue<string>();
stringQueue.enqueue('First');
stringQueue.enqueue('Second');
stringQueue.enqueue('Third');

console.info(`${stringQueue.dequeue()}`); // First
console.info(`${stringQueue.front()}`);   // Second
console.info(`${stringQueue.size()}`);    // 2

// 通用链表数据结构
class LinkedListNode<T> {
  public value: T;
  public next: LinkedListNode<T> | null = null;
  
  constructor(value: T) {
    this.value = value;
  }
}

class LinkedList<T> {
  private head: LinkedListNode<T> | null = null;
  private tail: LinkedListNode<T> | null = null;
  private length: number = 0;
  
  append(value: T): void {
    let newNode = new LinkedListNode(value);
    
    if (!this.head) {
      this.head = newNode;
      this.tail = newNode;
    } else {
      this.tail!.next = newNode;
      this.tail = newNode;
    }
    
    this.length++;
  }
  
  prepend(value: T): void {
    let newNode = new LinkedListNode(value);
    newNode.next = this.head;
    this.head = newNode;
    
    if (!this.tail) {
      this.tail = newNode;
    }
    
    this.length++;
  }
  
  insert(index: number, value: T): void {
    if (index === 0) {
      this.prepend(value);
      return;
    }
    
    if (index >= this.length) {
      this.append(value);
      return;
    }
    
    let newNode = new LinkedListNode(value);
    let prevNode = this.getNodeAt(index - 1);
    
    if (prevNode) {
      newNode.next = prevNode.next;
      prevNode.next = newNode;
      this.length++;
    }
  }
  
  remove(index: number): T | null {
    if (index < 0 || index >= this.length) {
      return null;
    }
    
    if (index === 0) {
      let removedNode = this.head;
      this.head = this.head?.next || null;
      this.length--;
      return removedNode?.value || null;
    }
    
    let prevNode = this.getNodeAt(index - 1);
    if (prevNode && prevNode.next) {
      let removedNode = prevNode.next;
      prevNode.next = removedNode.next;
      this.length--;
      return removedNode.value;
    }
    
    return null;
  }
  
  get(index: number): T | null {
    let node = this.getNodeAt(index);
    return node?.value || null;
  }
  
  private getNodeAt(index: number): LinkedListNode<T> | null {
    if (index < 0 || index >= this.length) {
      return null;
    }
    
    let current = this.head;
    for (let i = 0; i < index; i++) {
      current = current?.next || null;
    }
    
    return current;
  }
  
  size(): number {
    return this.length;
  }
  
  isEmpty(): boolean {
    return this.length === 0;
  }
}

let linkedList = new LinkedList<number>();
linkedList.append(1);
linkedList.append(2);
linkedList.append(3);
linkedList.prepend(0);

console.info(`${linkedList.get(0)}`); // 0
console.info(`${linkedList.get(2)}`); // 2
console.info(`${linkedList.size()}`); // 4

linkedList.remove(1);
console.info(`${linkedList.size()}`); // 3
```

### 通用工具函数

泛型工具函数如map、filter适用于任意类型的集合操作。

<!-- @[generic_array_utilities](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
// 通用数组工具函数
function utilitiesFirst<T>(arr: T[]): T | undefined {
  return arr[0];
}

function last<T>(arr: T[]): T | undefined {
  return arr[arr.length - 1];
}

function shuffle<T>(arr: T[]): T[] {
  let result = [...arr];
  for (let i = result.length - 1; i > 0; i--) {
    let j = Math.floor(Math.random() * (i + 1));
    let temp: T = result[i];
    result[i] = result[j];
    result[j] = temp;
  }
  return result;
}

function unique<T>(arr: T[]): T[] {
  return Array.from(new Set(arr));
}

let utilitiesNumbers: number[] = [1, 2, 3, 4, 5, 3, 2];
let utilitiesStrings: string[] = ['a', 'b', 'c', 'b', 'a'];

let firstResult: number | undefined = utilitiesFirst(utilitiesNumbers);
console.info(`${firstResult}`);  // 1

let lastResult: string | undefined = last(utilitiesStrings);
console.info(`${lastResult}`);  // a

let shuffled: number[] = shuffle(utilitiesNumbers);
console.info(`${shuffled.join(', ')}`);  // 随机打乱

let uniqueNumbers: number[] = unique(utilitiesNumbers);
console.info(`${uniqueNumbers.join(', ')}`);  // 1, 2, 3, 4, 5

let uniqueStrings: string[] = unique(utilitiesStrings);
console.info(`${uniqueStrings.join(', ')}`);  // a, b, c

interface UtilitiesUser {
  id: number;
  name: string;
  email: string;
}

let utilitiesUser: UtilitiesUser = {
  id: 1,
  name: 'Alice',
  email: 'alice@example.com'
};

// ArkTS中优先使用明确的属性访问，避免依赖keyof和索引访问类型
function renameUser(target: UtilitiesUser, newName: string): void {
  target.name = newName;
}

console.info(`${utilitiesUser.name}`);  // Alice
renameUser(utilitiesUser, 'Bob');
console.info(`${utilitiesUser.name}`);  // Bob
```

### 组件封装

泛型组件通过类型参数描述props、render等结构，使同一组件适配多种数据类型而不失去类型安全。

<!-- @[generic_ui_components](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
// 通用列表组件
interface ListComponentProps<T> {
  items: T[];
  renderItem: (item: T, index: number) => string;
  onItemClick?: (item: T, index: number) => void;
}

class ListComponent<T> {
  private props: ListComponentProps<T>;
  
  constructor(props: ListComponentProps<T>) {
    this.props = props;
  }
  
  render(): string {
    let itemsHtml = this.props.items.map((item, index) =>
      this.props.renderItem(item, index)
    ).join('');
    
    return `<ul>${itemsHtml}</ul>`;
  }
  
  handleClick(index: number): void {
    if (this.props.onItemClick) {
      this.props.onItemClick(this.props.items[index], index);
    }
  }
}

interface ComponentsUser {
  id: number;
  name: string;
  email: string;
}

let componentsUsers: ComponentsUser[] = [
  { id: 1, name: 'Alice', email: 'alice@example.com' },
  { id: 2, name: 'Bob', email: 'bob@example.com' },
  { id: 3, name: 'Charlie', email: 'charlie@example.com' }
];

let userList = new ListComponent<ComponentsUser>({
  items: componentsUsers,
  renderItem: (user) => `<li>${user.name} (${user.email})</li>`,
  onItemClick: (user) => console.info(`Clicked: ${user.name}`)
});

console.info(`${userList.render()}`);

// 通用表格组件
interface TableColumn<T> {
  header: string;
  getValue: (row: T) => string;
}

interface TableComponentProps<T> {
  columns: TableColumn<T>[];
  data: T[];
}

class TableComponent<T> {
  private props: TableComponentProps<T>;
  
  constructor(props: TableComponentProps<T>) {
    this.props = props;
  }
  
  render(): string {
    let headerHtml = this.props.columns.map(col =>
      `<th>${col.header}</th>`
    ).join('');
    
    let bodyHtml = this.props.data.map(row => {
      let cells = this.props.columns.map(col => {
        return `<td>${col.getValue(row)}</td>`;
      }).join('');
      return `<tr>${cells}</tr>`;
    }).join('');
    
    return `<table><thead><tr>${headerHtml}</tr></thead><tbody>${bodyHtml}</tbody></table>`;
  }
}

let userTable = new TableComponent<ComponentsUser>({
  columns: [
    { header: 'ID', getValue: (row: ComponentsUser): string => row.id.toString() },
    { header: 'Name', getValue: (row: ComponentsUser): string => row.name },
    { header: 'Email', getValue: (row: ComponentsUser): string => row.email }
  ],
  data: componentsUsers
});

console.info(`${userTable.render()}`);
```

### 接口请求封装

泛型封装网络请求，统一处理不同接口的请求和响应类型。

<!-- @[generic_api_client](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
interface ClientApiResponse<T> {
  data: T;
  status: number;
  message: string;
}

class ApiClient {
  private baseUrl: string;

  constructor(baseUrl: string) {
    this.baseUrl = baseUrl;
  }

  async get<T>(endpoint: string): Promise<ClientApiResponse<T>> {
    let url: string = `${this.baseUrl}${endpoint}`;
    let result: string = await this.mockRequest(url);
    let data: T = JSON.parse(result) as T;
    return { data: data, status: 200, message: 'Success' };
  }

  async post<T, U>(endpoint: string, body: T): Promise<ClientApiResponse<U>> {
    let url: string = `${this.baseUrl}${endpoint}`;
    let result: string = await this.mockRequest(url);
    let data: U = JSON.parse(result) as U;
    return { data: data, status: 200, message: 'Success' };
  }

  private mockRequest(url: string): Promise<string> {
    return new Promise<string>((resolve: (value: string) => void): void => {
      setTimeout(() => {
        resolve(JSON.stringify({ id: 1, name: 'Alice', email: 'alice@example.com' }));
      }, 100);
    });
  }
}

interface ClientUser {
  id: number;
  name: string;
  email: string;
}

interface CreateUserRequest {
  name: string;
  email: string;
}

let gacClient: ApiClient = new ApiClient('EXAMPLE_API_URL');

async function gacFetchUser(id: number): Promise<void> {
  try {
    let response: ClientApiResponse<ClientUser> = await gacClient.get<ClientUser>(`/users/${id}`);
    console.info(`${response.data.name}`); // Alice
  } catch (error) {
    console.error(`Error: ${(error as Error).message}`);
  }
}

async function gacCreateUser(name: string, email: string): Promise<void> {
  try {
    let request: CreateUserRequest = { name: name, email: email };
    let response: ClientApiResponse<ClientUser> = await gacClient.post<CreateUserRequest, ClientUser>('/users', request);
    console.info(`${response.data.id}`); // 1
  } catch (error) {
    console.error(`Error: ${(error as Error).message}`);
  }
}

gacFetchUser(1);
gacCreateUser('Alice', 'alice@example.com');
```
