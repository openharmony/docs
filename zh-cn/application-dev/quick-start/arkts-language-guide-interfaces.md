# 接口
<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

接口是TypeScript/ArkTS中定义对象结构的重要方式。接口定义了一组属性和方法的契约，用于约束对象的形状，实现代码的解耦和复用。

## 接口的基础概念

接口定义对象的结构契约——规定属性名、类型和可选性，不包含实现，用于类型约束和代码解耦。

### 接口的定义与核心作用

接口为对象定义结构契约——规定属性名、类型和可选性，类通过implements实现接口，确保实例具备所需成员。

接口在编译期约束对象结构、通过统一契约解耦模块依赖、支持多个类复用同一类型定义，是TypeScript/ArkTS实现松耦合与类型安全的核心机制。

<!-- @[simple_interface_definition](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
// 定义一个简单的接口
interface User {
  id: number;
  name: string;
  email: string;
}

// 使用接口约束对象
let user: User = {
  id: 1,
  name: 'Alice',
  email: 'alice@example.com'
};

console.info(user.name); // Alice
```

### 接口与协议的关系

接口可以作为协议，定义一组必须实现的方法和属性，使不同实现类可以以统一的方式被调用。

<!-- @[interface_as_protocol](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
// 接口定义协议
interface PaymentProtocol {
  // 必须实现的方法
  processPayment(amount: number): boolean;
  refundPayment(transactionId: string): boolean;
  
  // 必须包含的属性
  currency: string;
}

// 类实现接口协议
class CreditCardPayment implements PaymentProtocol {
  public currency: string = 'USD';
  
  public processPayment(amount: number): boolean {
    console.info('Processing credit card payment: $' + amount);
    return true;
  }
  
  public refundPayment(transactionId: string): boolean {
    console.info(`Refunding transaction: ${transactionId}`);
    return true;
  }
}

class PayPalPayment implements PaymentProtocol {
  public currency: string = 'EUR';
  
  public processPayment(amount: number): boolean {
    console.info(`Processing PayPal payment: €${amount}`);
    return true;
  }
  
  public refundPayment(transactionId: string): boolean {
    console.info(`Refunding PayPal transaction: ${transactionId}`);
    return true;
  }
}

// 使用接口类型
function makePayment(payment: PaymentProtocol, amount: number): void {
  if (payment.processPayment(amount)) {
    console.info('Payment successful');
  }
}

let creditCard = new CreditCardPayment();
let paypal = new PayPalPayment();

makePayment(creditCard, 100); // Processing credit card payment: $100
makePayment(paypal, 50);      // Processing PayPal payment: €50
```

### 接口的设计目标

接口设计遵循单一职责、接口隔离、依赖倒置等原则，避免定义过于庞大的接口。

单一职责要求每个接口只定义一组相关成员，接口隔离避免强迫实现者提供不需要的方法，依赖倒置让高层模块依赖抽象而非具体实现，命名应清晰表达用途。

<!-- @[interface_segregation_principle](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
// 好的设计：单一职责
interface Reader {
  read(): string;
}

interface Writer {
  write(data: string): void;
}

// 好的设计：接口隔离
interface ReadOnlyRepository<T> {
  findById(id: number): T | null;
  findAll(): T[];
}

interface WriteOnlyRepository<T> {
  save(entity: T): void;
  delete(id: number): void;
}

interface Repository<T> extends ReadOnlyRepository<T>, WriteOnlyRepository<T> {
  // 继承读写接口，提供完整功能
}

// 不好的设计：接口过于庞大（违反接口隔离原则）
interface BadRepository<T> {
  findById(id: number): T | null;
  findAll(): T[];
  save(entity: T): void;
  delete(id: number): void;
  batchInsert(entities: T[]): void;
  batchDelete(ids: number[]): void;
  // ... 更多方法
}
```

## 接口的声明与实现

interface关键字声明接口结构，类通过implements实现接口契约。

### 接口的声明语法

通过`interface`关键字声明接口，定义属性（名：类型）、方法签名和索引签名，描述对象的结构契约。

<!-- @[basic_interface_declaration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
// 基本接口声明
interface Point {
  x: number;
  y: number;
}

let point: Point = {
  x: 10,
  y: 20
};

console.info(`Point: (${point.x}, ${point.y})`);
```

### 接口的成员定义

接口的成员包括属性、方法和索引签名。

**属性类型**

接口属性包括必选属性、可选属性（`?`）和只读属性（`readonly`）。

<!-- @[ts_interface_property_types](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Interfaces.ts) -->

``` TypeScript
interface Product {
    // 必选属性
  id: number;
  name: string;
  price: number;

  // 可选属性（使用 ?）
  description?: string;
  stock?: number;

  // 只读属性（使用readonly）
  readonly createdAt: Date;
}

let product: Product = {
  id: 1,
  name: 'Laptop',
  price: 999,
  createdAt: new Date()
};

// 可以访问可选属性
if (product.description) {
    console.info(`${product.description}`);
}

// 只读属性不能修改
product.createdAt = new Date(); // 编译错误
```

**方法声明**

接口方法包括无参方法、带参方法和可选方法（`?`），类通过`implements`实现接口方法。

<!-- @[interface_method_declaration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
interface Calculator {
    // 方法声明（无参数）
  reset(): void;
  
  // 方法声明（带参数）
  add(a: number, b: number): number;
  subtract(a: number, b: number): number;
  
  // 可选方法
  logResult?(): void;
}

class BasicCalculator implements Calculator {
  private result: number = 0;
  
  public reset(): void {
    this.result = 0;
    console.info('Calculator reset');
  }
  
  public add(a: number, b: number): number {
    this.result = a + b;
    return this.result;
  }
  
  public subtract(a: number, b: number): number {
    this.result = a - b;
    return this.result;
  }
  
  // 可选方法可以不实现
  public logResult(): void {
    console.info(`Result: ${this.result}`);
  }
}

let calculator: BasicCalculator = new BasicCalculator();
let sum: number = calculator.add(10, 5);
console.info(`${sum}`); // 15
```

**索引签名**

索引签名允许用动态键访问属性，ArkTS不支持（`arkts-no-indexed-signatures`），使用`Map`替代。

**TypeScript对照**

<!-- @[ts_index_signature](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Interfaces.ts) -->

``` TypeScript
// 数字索引签名
interface NumberArray {
  [index: number]: number;
  length: number;
}

let numArray: NumberArray = [1, 2, 3, 4, 5];
console.info(`${numArray[0]}`); // 1

// 字符串索引签名
interface StringDictionary {
  [key: string]: string | number;
  name: string; // 必须符合索引签名类型
  age: number;  // 必须符合索引签名类型
}

let person: StringDictionary = {
  name: 'Alice',
  age: 25,
  city: 'New York',  // 动态属性
  country: 'USA'     // 动态属性
};

console.info(`${person.city}`); // New York

// 同时使用两种索引签名
interface MixedDictionary {
  [key: string]: string | number;
  [index: number]: string;
  length: number;
}

let mixed: MixedDictionary = {
  length: 3,
  0: 'First',
  1: 'Second',
  2: 'Third',
  key1: 'Value1',
  key2: 'Value2'
};

console.info(`${mixed[1]}`);    // Second
console.info(`${mixed.key1}`);  // Value1
```

ArkTS中使用`Map`替代索引签名，实现动态键值存储：

<!-- @[map_replaces_index_signature](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
// ArkTS替代方案：使用Map
let dictMap: Map<string, string | number> = new Map();
dictMap.set('name', 'Alice');
dictMap.set('age', 25);
dictMap.set('city', 'New York');

console.info(`${dictMap.get('city')}`);  // New York
```

### 类实现接口

类通过implements关键字实现接口，必须提供接口中所有成员的具体实现，不同类可以实现同一接口提供不同行为。

<!-- @[class_implements_interface](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
interface Logger {
  log(message: string): void;
  error(message: string): void;
  warn(message: string): void;
}

class ConsoleLogger implements Logger {
  public log(message: string): void {
    console.info(`[LOG] ${message}`);
  }
  
  public error(message: string): void {
    console.error(`[ERROR] ${message}`);
  }
  
  public warn(message: string): void {
    console.info(`[WARN] ${message}`);
  }
}

class FileLogger implements Logger {
  private fileName: string;
  
  constructor(fileName: string) {
    this.fileName = fileName;
  }
  
  public log(message: string): void {
    // 模拟写入文件
    console.info(`Writing to ${this.fileName}: [LOG] ${message}`);
  }
  
  public error(message: string): void {
    console.info(`Writing to ${this.fileName}: [ERROR] ${message}`);
  }
  
  public warn(message: string): void {
    console.info(`Writing to ${this.fileName}: [WARN] ${message}`);
  }
}

let consoleLogger = new ConsoleLogger();
let fileLogger = new FileLogger('app.log');

consoleLogger.log('Application started');
// [LOG] Application started

fileLogger.error('Connection failed');
// Writing to app.log: [ERROR] Connection failed
```

### 接口的继承

接口可以通过extends继承其他接口，形成多级层次结构，子接口包含父接口的全部成员并可以添加新成员。

<!-- @[interface_multi_level_inheritance](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
interface Animal {
  name: string;
  age: number;
}

interface Pet extends Animal {
  owner: string;
}

interface Dog extends Pet {
  breed: string;
  bark(): void;
}

class DemoDog implements Dog {
  public name: string;
  public age: number;
  public owner: string;
  public breed: string;

  constructor(name: string, age: number, owner: string, breed: string) {
    this.name = name;
    this.age = age;
    this.owner = owner;
    this.breed = breed;
  }

  public bark(): void {
    console.info(`${this.name} barks: Woof! Woof!`);
  }
}

let myDog: Dog = new DemoDog('Buddy', 3, 'Alice', 'Golden Retriever');

myDog.bark(); // Buddy barks: Woof! Woof!
```

## 接口的继承与组合

接口通过extends单继承和多继承复用类型定义，通过交叉类型（&）组合多个接口。

### 接口的单继承

接口使用extends继承单个父接口，子接口在父接口成员基础上添加新成员，对象需同时满足父子接口的结构。

<!-- @[interface_inheritance_object_literal](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
interface Vehicle {
  brand: string;
  year: number;
}

interface Car extends Vehicle {
  model: string;
  doors: number;
}

let myCar: Car = {
  brand: 'Toyota',
  year: 2020,
  model: 'Camry',
  doors: 4
};

console.info(`${myCar.brand} ${myCar.model} (${myCar.year})`);
```

### 接口的多继承

接口可以extends多个父接口，组合多个类型契约。

<!-- @[interface_multiple_inheritance](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
interface MiSerializable {
  serialize(): string;
}

interface MiCloneable {
  clone(): Object;
}

interface MiComparable {
  compareTo(other: Object): number;
}

interface MiEntity extends MiSerializable, MiCloneable, MiComparable {
  id: number;
  createdAt: Date;
}

class MiUserEntity implements MiEntity {
  public id: number;
  public createdAt: Date;
  public name: string;

  constructor(id: number, name: string) {
    this.id = id;
    this.name = name;
    this.createdAt = new Date();
  }

  public serialize(): string {
    return JSON.stringify({
      id: this.id,
      name: this.name,
      createdAt: this.createdAt
    });
  }

  public clone(): Object {
    let cloned: MiUserEntity = new MiUserEntity(this.id, this.name);
    cloned.createdAt = new Date(this.createdAt);
    return cloned;
  }

  public compareTo(other: Object): number {
    let otherUser: MiUserEntity = other as MiUserEntity;
    return this.id - otherUser.id;
  }
}

let miUser1: MiUserEntity = new MiUserEntity(1, 'Alice');
let miUser2: MiUserEntity = new MiUserEntity(2, 'Bob');

console.info(`${miUser1.serialize()}`);
console.info(`${miUser1.compareTo(miUser2)}`); // -1
let miCloned: Object = miUser1.clone();
let miClonedUser: MiUserEntity = miCloned as MiUserEntity;
console.info(`${miClonedUser.name}`); // Alice
```

### 接口组合类型

交叉类型（`&`）组合多个接口，形成满足所有约束的复合类型。ArkTS不支持交叉类型（`arkts-no-intersection-types`），使用接口多继承替代，详见[从TypeScript到ArkTS的适配规则](typescript-to-arkts-migration-guide.md#使用继承而非intersection-type)。

**TypeScript对照**

<!-- @[ts_interface_composition](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Interfaces.ts) -->

``` TypeScript
interface Nameable {
  name: string;
}

interface Ageable {
  age: number;
}

interface Emailable {
  email: string;
}

// 使用交叉类型组合接口
type Person = Nameable & Ageable & Emailable;

let composePerson: Person = {
  name: 'Alice',
  age: 25,
  email: 'alice@example.com'
};

console.info(`${composePerson.name}`); // Alice

// 另一种方式：使用接口继承
interface Employee extends Nameable, Ageable, Emailable {
  department: string;
  salary: number;
}

let employee: Employee = {
  name: 'Bob',
  age: 30,
  email: 'bob@company.com',
  department: 'Engineering',
  salary: 50000
};

console.info(`${employee.name} works in ${employee.department}`);
```

### 接口继承的约束规则

接口继承时可以添加新成员和覆盖同名方法（保持签名一致），但不能修改父接口成员的类型，否则会编译错误。

<!-- @[ts_interface_inheritance_rules](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Interfaces.ts) -->

``` TypeScript
interface Base {
  method(): void;
}

interface Derived extends Base {
  // 可以添加新方法
  newMethod(): void;

  // 可以覆盖父接口的方法（保持相同签名）
  method(): void;

  // 不能修改方法的返回类型（编译错误）
  method(): string;
}

// 接口继承时的属性约束
interface Colorable {
  color: string;
}

interface Sized {
  size: number;
}

interface Shape extends Colorable, Sized {
  // 可以添加新属性
  area(): number;

  // 不能重新定义父接口的属性
  color: number; // 编译错误：类型不匹配
}
```

## 接口的可选成员

可选成员使用?标记，实现时可以省略。

### 基于optional修饰符的可选成员

可选成员使用`?`标记，声明时置于成员名后，实现对象可省略该成员。

<!-- @[optional_properties_methods](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
interface Configuration {
  // 必选属性
  apiUrl: string;
  
  // 可选属性（使用 ?）
  timeout?: number;
  retries?: number;
  debugMode?: boolean;
  
  // 可选方法
  logError?: (error: Error) => void;
  validateResponse?: (response: HttpResponse) => boolean;
}

interface HttpResponse {
  status: number;
  body: string;
}

let config1: Configuration = {
  apiUrl: 'EXAMPLE_API_URL'
};

let config2: Configuration = {
  apiUrl: 'EXAMPLE_API_URL',
  timeout: 5000,
  retries: 3,
  debugMode: true
};

// 使用可选成员
if (config2.timeout) {
  console.info(`Timeout: ${config2.timeout}ms`);
}

if (config2.logError) {
  config2.logError(new Error('Test error'));
}
```

### 可选属性与可选方法的声明

可选属性（?）和方法表示成员可能不存在，访问前需要检查。

<!-- @[optional_members_implementation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
interface Service {
  // 必选方法
  initialize(): void;
  shutdown(): void;
  
  // 可选方法
  preInitialize?(): void;
  postShutdown?(): void;
  
  // 必选属性
  name: string;
  
  // 可选属性
  version?: string;
  description?: string;
}

class BasicService implements Service {
  public name: string;
  
  constructor(name: string) {
    this.name = name;
  }
  
  public initialize(): void {
    console.info(`${this.name} initialized`);
  }
  
  public shutdown(): void {
    console.info(`${this.name} shutdown`);
  }
  
  // 可选方法可以不实现
}

class AdvancedService implements Service {
  public name: string;
  public version: string;
  public description: string;
  
  constructor(name: string, version: string, description: string) {
    this.name = name;
    this.version = version;
    this.description = description;
  }
  
  public initialize(): void {
    console.info(`${this.name} v${this.version} initialized`);
  }
  
  public shutdown(): void {
    console.info(`${this.name} shutdown`);
  }
  
  public preInitialize(): void {
    console.info(`${this.name} pre-initialization`);
  }
  
  public postShutdown(): void {
    console.info(`${this.name} post-shutdown cleanup`);
  }
}

let basicService = new BasicService('BasicService');
let advancedService = new AdvancedService('AdvancedService', '1.0', 'Advanced service with all features');

basicService.initialize();
advancedService.preInitialize();
advancedService.initialize();
advancedService.shutdown();
advancedService.postShutdown();
```

### 可选成员的调用注意事项

调用可选成员前需检查是否存在，避免访问undefined。

<!-- @[using_optional_members](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
interface OptionalInterface {
  requiredMethod(): void;
  optionalMethod?(): void;
  requiredProperty: string;
  optionalProperty?: number;
}

function useOptionalInterface(obj: OptionalInterface): void {
  // 必选成员可以直接调用
  obj.requiredMethod();
  console.info(`${obj.requiredProperty}`);
  
  // 可选方法需要先检查是否存在
  if (obj.optionalMethod) {
    obj.optionalMethod();
  }
  
  // 可选属性需要先检查是否存在
  if (obj.optionalProperty !== undefined) {
    console.info(`${obj.optionalProperty}`);
  }
  
  // 使用可选链（?.）
  obj.optionalMethod?.();
  console.info(`${obj.optionalProperty?.toFixed(2)}`);
  
  // 使用空值合并（??）
  let value: number = obj.optionalProperty ?? 0;
  console.info(`${value}`);
}
```

### 替代方案：使用接口扩展实现可选成员

通过让扩展接口继承基础接口并添加可选成员，可以为不同实现者提供按需提供可选能力的灵活方案。

<!-- @[extending_interface_with_optionals](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
// 基础接口（必选成员）
interface BaseInterface {
  requiredMethod(): void;
  requiredProperty: string;
}

// 扩展接口（包含可选成员）
interface ExtendedInterface extends BaseInterface {
    optionalMethod?(): void;
    optionalProperty?: number;
}

class BaseInterfaceImpl implements BaseInterface {
  public requiredProperty: string = 'Required value';

  public requiredMethod(): void {
    console.info('Required method');
  }
}

class ExtendedInterfaceImpl implements ExtendedInterface {
  public requiredProperty: string = 'Required value';
  public optionalProperty: number = 42;

  public requiredMethod(): void {
    console.info('Required method');
  }

  public optionalMethod(): void {
    console.info('Optional method');
  }
}

// 使用基础接口
let baseObj: BaseInterface = new BaseInterfaceImpl();

// 使用扩展接口（可以选择是否提供可选成员）
let extendedObj: ExtendedInterface = new ExtendedInterfaceImpl();

// 让扩展接口继承基础接口
function processObject(obj: BaseInterface): void {
  obj.requiredMethod();
  console.info(`${obj.requiredProperty}`);
  
  // 如果传入扩展接口对象，可以先转换为扩展接口再检查可选成员
  let extended: ExtendedInterface = obj as ExtendedInterface;
  if (extended.optionalMethod !== undefined) {
    extended.optionalMethod();
  }
}

processObject(baseObj);
processObject(extendedObj);
```

## 带泛型约束的接口

泛型接口通过`<T>`引入类型参数，可搭配`extends`约束类型范围，使一份接口适配多种数据类型。

### 泛型接口的声明

在接口名后用`<T>`声明类型参数，使接口适用于多种类型。

<!-- @[generic_interface](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
// 泛型接口
interface Container<T> {
  value: T;
  getValue(): T;
  setValue(value: T): void;
}

class NumberContainer implements Container<number> {
  public value: number;
  
  constructor(initialValue: number) {
    this.value = initialValue;
  }
  
  public getValue(): number {
    return this.value;
  }
  
  public setValue(value: number): void {
    this.value = value;
  }
}

class StringContainer implements Container<string> {
  public value: string;
  
  constructor(initialValue: string) {
    this.value = initialValue;
  }
  
  public getValue(): string {
    return this.value;
  }
  
  public setValue(value: string): void {
    this.value = value;
  }
}

let numContainer = new NumberContainer(42);
let strContainer = new StringContainer('Hello');

console.info(`${numContainer.getValue().toString()}`); // 42
console.info(`${strContainer.getValue()}`); // Hello
```

### 泛型参数的约束

通过`<T extends SomeType>`约束泛型参数必须满足特定接口，使泛型接口能够安全访问约束类型的成员。

<!-- @[generic_constraint_interface](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
interface Lengthwise {
  length: number;
}

// 泛型约束：T必须具有length属性
interface LengthContainer<T extends Lengthwise> {
  value: T;
  getLength(): number;
}

class ArrayContainer<T extends Lengthwise> implements LengthContainer<T> {
  public value: T;
  
  constructor(value: T) {
    this.value = value;
  }
  
  public getLength(): number {
    return this.value.length;
  }
}

let stringContainer = new ArrayContainer('Hello, ArkTS!');
let arrayContainer = new ArrayContainer([1, 2, 3, 4, 5]);

console.info(`${stringContainer.getLength()}`); // 13
console.info(`${arrayContainer.getLength()}`);  // 5
```

### 泛型接口的实现

类通过指定具体类型参数实现泛型接口（如`implements Repository<User>`），为接口中所有方法提供具体实现。

<!-- @[generic_repository_interface](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
interface RepoRepository<T> {
  findById(id: number): T | null;
  findAll(): T[];
  save(entity: T): void;
  delete(id: number): void;
}

interface RepoUser {
  id: number;
  name: string;
  email: string;
}

class UserRepository implements RepoRepository<RepoUser> {
  private users: RepoUser[] = [];
  
  public findById(id: number): RepoUser | null {
    return this.users.find((user: RepoUser): boolean => user.id === id) ?? null;
  }
  
  public findAll(): RepoUser[] {
    return this.users;
  }
  
  public save(entity: RepoUser): void {
    let existingUser: RepoUser | null = this.findById(entity.id);
    if (existingUser !== null) {
      // 更新现有用户
      let index = this.users.indexOf(existingUser);
      this.users[index] = entity;
    } else {
      // 添加新用户
      this.users.push(entity);
    }
  }
  
  public delete(id: number): void {
    this.users = this.users.filter((user: RepoUser): boolean => user.id !== id);
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

### 泛型接口的使用场景

泛型接口常用于通用数据结构（Collection）、转换器（Mapper/Filter/Reducer）和回调契约（Callback）等场景。

<!-- @[generic_interface_use_cases](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
// 使用场景1: 通用数据结构
interface Collection<T> {
  add(item: T): void;
  remove(item: T): void;
  contains(item: T): boolean;
  size(): number;
}

// 使用场景2: 通用工具接口
interface Mapper<T, U> {
  map(input: T): U;
}

interface Filter<T> {
  filter(predicate: (item: T) => boolean): T[];
}

interface Reducer<T, U> {
  reduce(accumulator: (prev: U, current: T) => U, initial: U): U;
}

// 使用场景3: 通用回调接口
interface Callback<T> {
  onSuccess(result: T): void;
  onError(error: Error): void;
}

interface AsyncCallback<T> {
  onSuccess(result: T): Promise<void>;
  onError(error: Error): Promise<void>;
}
```

## 接口与类的结合

类通过implements实现接口，接口定义契约、类提供实现。

### 类实现单个接口

类使用implements关键字实现单个接口，必须提供接口中所有成员的具体实现。

<!-- @[single_interface_implementation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
interface Drawable {
  draw(): void;
}

class Circle implements Drawable {
  private radius: number;
  
  constructor(radius: number) {
    this.radius = radius;
  }
  
  public draw(): void {
    console.info(`Drawing a circle with radius ${this.radius}`);
  }
}

let circle = new Circle(5);
circle.draw(); // Drawing a circle with radius 5
```

### 类实现多个接口

类通过逗号分隔实现多个接口（如`implements A, B, C`），必须提供所有接口的成员实现。

<!-- @[multiple_interface_implementation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
interface Printable {
  print(): void;
}

interface Saveable {
  save(): void;
}

interface Loadable {
  load(): void;
}

class Document implements Printable, Saveable, Loadable {
  private title: string;
  private content: string;
  
  constructor(title: string, content: string) {
    this.title = title;
    this.content = content;
  }
  
  public print(): void {
    console.info(`Printing: ${this.title}`);
    console.info(`${this.content}`);
  }
  
  public save(): void {
    console.info(`Saving: ${this.title}`);
  }
  
  public load(): void {
    console.info(`Loading: ${this.title}`);
  }
}

let document = new Document('My Document', 'This is the content.');
document.print();
document.save();
document.load();
```

### 继承类同时实现接口

类可以同时使用extends继承父类和implements实现接口，既复用父类代码又满足接口契约。

<!-- @[class_inheritance_with_interface](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
class BaseEntity {
  public id: number;
  public createdAt: Date;
  
  constructor(id: number) {
    this.id = id;
    this.createdAt = new Date();
  }
  
  public getInfo(): string {
    return `ID: ${this.id}, Created: ${this.createdAt}`;
  }
}

interface Named {
  name: string;
  getName(): string;
}

interface Active {
  active: boolean;
  activate(): void;
  deactivate(): void;
}

class InterfaceUser extends BaseEntity implements Named, Active {
  public name: string;
  public active: boolean;
  
  constructor(id: number, name: string) {
    super(id);
    this.name = name;
    this.active = false;
  }
  
  public getName(): string {
    return this.name;
  }
  
  public activate(): void {
    this.active = true;
    console.info(`${this.name} activated`);
  }
  
  public deactivate(): void {
    this.active = false;
    console.info(`${this.name} deactivated`);
  }
}

let interfaceUser = new InterfaceUser(1, 'Alice');
console.info(`${interfaceUser.getInfo()}`);  // ID: 1, Created: ...
console.info(`${interfaceUser.getName()}`);  // Alice
interfaceUser.activate();
interfaceUser.deactivate();
```

### 接口作为类的类型约束

接口可用作泛型参数的约束（如`<T extends Comparable<T>>`），限制类型参数必须实现指定接口，从而在泛型代码中安全调用接口成员。

<!-- @[comparable_equatable_interface](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
interface EquatableComparable<T> {
  compareTo(other: T): number;
}

interface Equatable<T> {
  equals(other: T): boolean;
}

class NumericValue implements EquatableComparable<NumericValue>, Equatable<NumericValue> {
  public value: number;
  
  constructor(value: number) {
    this.value = value;
  }
  
  public compareTo(other: NumericValue): number {
    return this.value - other.value;
  }
  
  public equals(other: NumericValue): boolean {
    return this.value === other.value;
  }
}

let num1 = new NumericValue(10);
let num2 = new NumericValue(20);
let num3 = new NumericValue(10);

console.info(`${num1.compareTo(num2)}`); // -10
console.info(`${num1.equals(num2)}`);    // false
console.info(`${num1.equals(num3)}`);    // true

// 使用接口类型约束
function findMax<T extends EquatableComparable<T>>(items: T[]): T | null {
  if (items.length === 0) {
    return null;
  }
  
  let max: T = items[0] as T;
  for (let i = 1; i < items.length; i++) {
    let current: T = items[i] as T;
    if (current.compareTo(max) > 0) {
      max = current;
    }
  }
  return max;
}

let values: NumericValue[] = [new NumericValue(5), new NumericValue(15), new NumericValue(10)];
let maxValue = findMax(values);
console.info(`${maxValue ? maxValue.value : 0}`); // 15
```

## 接口作为类型使用

接口可以作为变量的类型注解，约束对象的结构。

### 接口作为变量类型

接口名可直接作为变量的类型注解，赋值时对象字面量必须包含所有必选成员且类型匹配，多余属性会被编译器拒绝。

<!-- @[interface_object_literal_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
interface LiteralPoint {
  x: number;
  y: number;
}

let literalPoint: LiteralPoint = { x: 10, y: 20 };

interface Color {
  red: number;
  green: number;
  blue: number;
}

let color: Color = { red: 255, green: 128, blue: 0 };

console.info(`LiteralPoint: (${literalPoint.x}, ${literalPoint.y})`);
console.info(`Color: RGB(${color.red}, ${color.green}, ${color.blue})`);
```

### 接口作为函数参数/返回值类型

接口作为函数参数和返回值类型，约束输入输出的结构。

<!-- @[interface_function_types](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
interface TypesUser {
  id: number;
  name: string;
  email: string;
}

interface CreateUserRequest {
  name: string;
  email: string;
}

interface ApiResponse<T> {
  success: boolean;
  data?: T;
  error?: string;
}

// 接口作为参数类型
function createUser(request: CreateUserRequest): TypesUser {
  return {
    id: Math.floor(Math.random() * 1000),
    name: request.name,
    email: request.email
  };
}

// 接口作为返回值类型
function getUser(id: number): ApiResponse<TypesUser> {
  if (id > 0) {
    return {
      success: true,
      data: {
        id: id,
        name: 'Alice',
        email: 'alice@example.com'
      }
    };
  } else {
    return {
      success: false,
      error: 'Invalid user ID'
    };
  }
}

let newUser: TypesUser = createUser({ name: 'Bob', email: 'bob@example.com' });
console.info(`${newUser}`);

let response: ApiResponse<TypesUser> = getUser(1);
if (response.success && response.data !== undefined) {
    console.info(`${response.data.name}`);
}
```

### 接口类型的多态特性

接口类型变量可以指向任何实现该接口的类实例，调用同名方法时执行各自实现，实现运行时多态。

<!-- @[interface_polymorphism](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
interface PolyAnimal {
  name: string;
  speak(): void;
}

class PolyDog implements PolyAnimal {
  public name: string;
  
  constructor(name: string) {
    this.name = name;
  }
  
  public speak(): void {
    console.info(`${this.name} barks: Woof! Woof!`);
  }
}

class Cat implements PolyAnimal {
  public name: string;
  
  constructor(name: string) {
    this.name = name;
  }
  
  public speak(): void {
    console.info(`${this.name} meows: Meow!`);
  }
}

class Cow implements PolyAnimal {
  public name: string;
  
  constructor(name: string) {
    this.name = name;
  }
  
  public speak(): void {
    console.info(`${this.name} moos: Moo!`);
  }
}

// 使用接口类型实现多态
function makeAnimalSpeak(animal: PolyAnimal): void {
  animal.speak();
}

let dog = new PolyDog('Buddy');
let cat = new Cat('Whiskers');
let cow = new Cow('Daisy');

makeAnimalSpeak(dog); // Buddy barks: Woof! Woof!
makeAnimalSpeak(cat); // Whiskers meows: Meow!
makeAnimalSpeak(cow); // Daisy moos: Moo!

// 使用接口类型的数组
let animals: PolyAnimal[] = [dog, cat, cow];

animals.forEach(animal => {
    animal.speak();
});
```

### 接口类型与具体类型的转换

接口类型变量可以通过instanceof判断具体类型后使用as断言转换回子类型，以访问实现类特有的成员。

<!-- @[interface_type_casting](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
interface CastingVehicle {
  brand: string;
  model: string;
}

class CastingCar implements CastingVehicle {
  public brand: string;
  public model: string;
  public doors: number;
  
  constructor(brand: string, model: string, doors: number) {
    this.brand = brand;
    this.model = model;
    this.doors = doors;
  }
  
  public drive(): void {
    console.info(`Driving ${this.brand} ${this.model}`);
  }
}

class Motorcycle implements CastingVehicle {
  public brand: string;
  public model: string;
  public type: string;
  
  constructor(brand: string, model: string, type: string) {
    this.brand = brand;
    this.model = model;
    this.type = type;
  }
  
  public ride(): void {
    console.info(`Riding ${this.brand} ${this.model} (${this.type})`);
  }
}

// 接口类型转换为具体类型（需要类型检查）
function processVehicle(vehicle: CastingVehicle): void {
  console.info(`${vehicle.brand} ${vehicle.model}`);
  
  // 使用instanceof检查类型
  if (vehicle instanceof CastingCar) {
    let car = vehicle as CastingCar;
    console.info(`Doors: ${car.doors}`);
    car.drive();
  } else if (vehicle instanceof Motorcycle) {
    let motorcycle = vehicle as Motorcycle;
    console.info(`Type: ${motorcycle.type}`);
    motorcycle.ride();
  }
}

let car: CastingCar = new CastingCar('Toyota', 'Camry', 4);
let motorcycle: Motorcycle = new Motorcycle('Harley-Davidson', 'Street 750', 'Cruiser');

processVehicle(car);
processVehicle(motorcycle);
```

## 多余属性检查

对象字面量赋值给接口类型时，ArkTS检查是否存在接口未定义的属性，帮助发现拼写错误。

<!-- @[excess_property_check](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
interface SquareConfig {
  color?: string;
  width?: number;
}

interface EpSquareResult {
  color: string;
  area: number;
}

function createSquare(config: SquareConfig): EpSquareResult {
  return {
    color: config.color || 'red',
    area: config.width ? config.width * config.width : 20
  };
}

// 正确
let epSquare1 = createSquare({ color: 'blue', width: 100 });
```

传入`{ colour: 'red', width: 100 }`（拼写错误`colour`）会触发编译错误。

**TypeScript对照**

<!-- @[ts_excess_property_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Interfaces.ts) -->

``` TypeScript
// TypeScript对照写法，演示多余属性检查的编译错误
interface TsSquareConfig {
  color?: string;
  width?: number;
}

function tsCreateSquare(config: TsSquareConfig): { color: string; area: number } {
  return {
    color: config.color || 'red',
    area: config.width ? config.width * config.width : 20
  };
}

let tsEpSquare2 = tsCreateSquare({ colour: 'red', width: 100 });
// 编译错误：'colour' does not exist in type 'SquareConfig'
```

绕过多余属性检查的常用方法包括类型断言、添加索引签名或先赋值给中间变量。大多数多余属性错误是真正的bug，应优先修复。

## 接口的扩展

接口通过extends继承其他接口，复用和组合类型定义。

### 基于interface扩展的接口扩展

使用extends关键字让一个接口继承另一个接口的成员。

<!-- @[ts_interface_declaration_merging](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Interfaces.ts) -->

``` TypeScript
// 原始接口
interface MergingWindow {
  title: string;
}

// 扩展接口（添加新属性）
interface MergingWindow {
  size: { width: number; height: number };
}

// 再次扩展
interface MergingWindow {
  isOpen: boolean;
  open(): void;
  close(): void;
}

let myWindow: MergingWindow = {
  title: 'My MergingWindow',
  size: { width: 800, height: 600 },
  isOpen: false,
  open: () => console.info(`Opening window`),
  close: () => console.info(`Closing window`)
};

console.info(`${myWindow.title}`);
console.info(`${myWindow.size.width}`);
myWindow.open();
```

### 为接口添加默认方法实现

通过抽象类或装饰器模式为接口方法提供默认实现。

<!-- @[interface_default_implementation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
interface ImplementationLogger {
  log(message: string): void;
  error(message: string): void;
  warn(message: string): void;
}

// 提供默认实现的辅助类
class DefaultLogger implements ImplementationLogger {
  public log(message: string): void {
    console.info(`[LOG] ${message}`);
  }
  
  public error(message: string): void {
    console.error(`[ERROR] ${message}`);
  }
  
  public warn(message: string): void {
    console.info(`[WARN] ${message}`);
  }
}

// 自定义日志类可以继承默认实现
class CustomLogger extends DefaultLogger implements ImplementationLogger {
  private prefix: string;
  
  constructor(prefix: string) {
    super();
    this.prefix = prefix;
  }
  
  // 覆盖默认方法
  public log(message: string): void {
    console.info(`${this.prefix} [LOG] ${message}`);
  }
  
  // 其他方法使用默认实现
}

let customLogger = new CustomLogger('[MyApp]');
customLogger.log('Application started'); // [MyApp] [LOG] Application started
customLogger.error('Something went wrong'); // [ERROR] Something went wrong
```

### 接口扩展的使用场景

接口扩展用于按需组合类型，避免定义单一庞大的接口。

<!-- @[ts_extending_third_party_interface](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Interfaces.ts) -->

``` TypeScript
// 假设这是第三方库定义的接口
interface PartyThirdPartyConfig {
  apiUrl: string;
  apiKey: string;
}

// 为第三方接口扩展自定义属性
interface PartyThirdPartyConfig {
  customTimeout?: number;
  customRetryCount?: number;
}

let config: PartyThirdPartyConfig = {
  apiUrl: 'EXAMPLE_API_URL',
  apiKey: 'secret-key',
  customTimeout: 5000,
  customRetryCount: 3
};

console.info(`${config.customTimeout}`); // 5000
```

声明合并也可以跨模块进行，不同模块可分别向同一接口添加成员。

<!-- @[ts_module_interface_merging](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Interfaces.ts) -->

``` TypeScript
// 基础模块定义的接口
interface MergingBaseEntity {
  id: number;
}

// 用户模块扩展接口
interface MergingBaseEntity {
  userId?: number;
  userName?: string;
}

// 产品模块扩展接口
interface MergingBaseEntity {
  productId?: number;
  productName?: string;
}

// 实体可以包含来自不同模块的属性
let entity: MergingBaseEntity = {
  id: 100,
  userId: 1,
  userName: 'Alice',
  productId: 50,
  productName: 'Laptop'
};

console.info(`${entity.userName}`);
console.info(`${entity.productName}`);
```

## type与interface的区别

`type`和`interface`都可描述对象类型，但在扩展性、声明合并等方面存在差异。ArkTS不支持接口声明合并（`arkts-no-decl-merging`）和交叉类型（`arkts-no-intersection-types`），使用接口`extends`替代。

**TypeScript对照**

<!-- @[ts_type_vs_interface](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Interfaces.ts) -->

``` TypeScript
// type可描述联合类型和元组
type TvID = number | string;
type TvPair = [string, number];

// interface支持声明合并（ArkTS不支持，arkts-no-decl-merging）
interface TvWindow {
  title: string;
}
interface TvWindow {
  ts: string;
}

// interface支持扩展
interface TvAnimal {
  name: string;
}
interface TvDog extends TvAnimal {
  breed: string;
}

// type用交叉类型扩展（ArkTS不支持，arkts-no-intersection-types）
type TvAnimal2 = { name: string };
type TvDog2 = TvAnimal2 & { breed: string };
```

选择建议：优先使用`interface`描述对象结构，需要联合、元组或基本类型别名时使用`type`。

## implements的注意事项

`implements`子句用于检查类是否满足接口，但有几个重要限制。

**implements不改变类类型**——仅做检查，不会将接口的类型信息传递到类体中。

**implements不创建可选属性**——实现含可选属性的接口不会在实例上创建该属性。

**implements只检查实例侧**——静态成员不受`implements`检查。

<!-- @[implements_cautions](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
interface ImplCheckable {
  check(name: string): boolean;
}

class ImplNameChecker implements ImplCheckable {
  // 参数类型不会从接口自动推断，需显式标注
  check(s: string): boolean {
    return s.toLowerCase() === 'ok';
  }
}

interface ImplConfigA {
  x: number;
  y?: number;
}

class ImplC implements ImplConfigA {
  public x: number = 0;
  // y不是必须实现的，但实例上不存在y属性
}

let implC: ImplC = new ImplC();
console.info(`${implC.x.toString()}`);  // 0
```

`implC.y`在实例上不存在，访问会触发编译错误。

**TypeScript对照**

<!-- @[ts_implements_optional_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Interfaces.ts) -->

``` TypeScript
// TypeScript对照写法，演示implements不创建可选属性
interface TsImplConfigA {
  x: number;
  y?: number;
}

class TsImplC implements TsImplConfigA {
  public x: number = 0;
}

let tsImplC: TsImplC = new TsImplC();
tsImplC.y = 10;  // 编译错误：Property 'y' does not exist on type 'TsImplC'
```

## 抽象类与接口的对比

抽象类与接口都无法实例化。抽象类是类的抽象，用来捕捉子类的通用特性；接口是行为的抽象。在ArkTS语法中抽象类与接口的区别如下：

- 一个类只能继承一个抽象类，而一个类可以实现一个或多个接口。

<!-- @[bird_multiple_interface](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
abstract class AcAnimal {
  public name: string;

  constructor(name: string) {
    this.name = name;
  }

  abstract makeSound(): void;
}

interface AcCanFly {
  fly(): void;
}

interface AcCanSwim {
  swim(): void;
}

class AcBird extends AcAnimal implements AcCanFly, AcCanSwim {
  constructor(name: string) {
    super(name);
  }

  makeSound(): void {
    console.info(`${this.name} chirps`);
  }

  fly(): void {
    console.info(`${this.name} flies`);
  }

  swim(): void {
    console.info(`${this.name} swims`);
  }
}

let acBird: AcBird = new AcBird('Sparrow');
acBird.makeSound(); // Sparrow chirps
acBird.fly();       // Sparrow flies
acBird.swim();      // Sparrow swims
```

- 接口中不能含有静态代码块以及静态方法，而抽象类可以有静态代码块和静态方法。

<!-- @[abstract_vs_interface_static](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
abstract class AviAbstractClass {
  static staticMethod(): void { console.info('static'); }
  static { console.info('static initialization block'); }
}
```

- 抽象类里面可以有方法的实现，但是接口没有方法的实现，是完全抽象的。

抽象类可以有方法的实现，接口没有方法的实现。

<!-- @[abstract_vs_interface_method](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
abstract class AimAbstractClass {
  func(): void { console.info('func'); }
}
```

- 抽象类可以有构造函数，而接口不能有构造函数。

抽象类可以有构造函数，接口不能有构造函数。

<!-- @[abstract_vs_interface_constructor](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
abstract class AvicAbstractClass {
  constructor() {}
}
```

## 交叉类型

TypeScript支持交叉类型（`&`），将多个类型合并为一个，新类型包含所有成员。ArkTS中不使用交叉类型，推荐用接口多继承（`extends`）替代。

### 接口扩展与交叉类型对照

TypeScript中接口扩展和交叉类型都能组合多个类型，但行为不同：

- **接口扩展（`extends`）**：同名属性不兼容时编译报错。
- **交叉类型（`&`）**：同名属性不兼容时合并为`never`。

<!-- @[ts_intersection_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Interfaces.ts) -->

``` TypeScript
// TypeScript交叉类型写法，ArkTS不支持
interface TsColorful {
  color: string;
}

interface TsCircle {
  radius: number;
}

type TsColorfulCircle = TsColorful & TsCircle;

let tsCc: TsColorfulCircle = { color: 'red', radius: 10 };
console.info(`${tsCc.color}, ${tsCc.radius}`); // red, 10
```

ArkTS替代：接口多继承。

<!-- @[interface_extends_multiple](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
interface IfColorful {
  color: string;
}

interface IfCircle {
  radius: number;
}

interface IfColorfulCircle extends IfColorful, IfCircle {
}

let ifCc: IfColorfulCircle = { color: 'red', radius: 10 };
console.info(`${ifCc.color}, ${ifCc.radius}`); // red, 10
```

> **说明：**
> 
> ArkTS中优先使用接口多继承替代交叉类型。当需要组合多个接口约束时，声明一个继承多个接口的新接口即可。

## 声明合并

TypeScript支持同名声明的合并，将多个独立声明合并为一个定义。ArkTS支持命名空间与类、枚举的合并，但不支持接口声明合并和命名空间与函数的合并。

### 接口合并

**TypeScript对照**

<!-- @[ts_declaration_merging](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Interfaces.ts) -->

``` TypeScript
// TypeScript写法，ArkTS不支持接口声明合并
interface TsWindow {
  title: string;
}

interface TsWindow {
  count: number;
}

// 合并后 TsWindow 同时有 title 和 count
let tsWin: TsWindow = { title: 'Main', count: 3 };
console.info(`${tsWin.title}, ${tsWin.count}`); // Main, 3
```

ArkTS替代方式：在原接口定义中直接添加成员，或使用接口继承扩展。

<!-- @[interface_extends_base](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
interface IfBaseWindow {
  title: string;
}

interface IfExtendedWindow extends IfBaseWindow {
  count: number;
}

let ifWin: IfExtendedWindow = { title: 'Main', count: 3 };
console.info(`${ifWin.title}, ${ifWin.count}`); // Main, 3
```

### 命名空间合并

ArkTS支持命名空间与类、枚举的合并，用于扩展静态成员。命名空间与函数的合并不支持。
