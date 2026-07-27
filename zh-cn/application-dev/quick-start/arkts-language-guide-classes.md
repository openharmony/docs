# 类
<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

类是面向对象编程的核心概念，用于封装数据和行为。ArkTS提供完整的类支持，包括属性、方法、构造函数、继承、访问控制、抽象类等特性。

## 类的基础概念

类是面向对象编程的基本构造，封装数据（属性）和行为（方法），通过构造函数初始化实例。

### 类的定义语法

使用class关键字定义类，在花括号内声明属性、构造函数和方法。

<!-- @[class_basic_definition](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
// 基本类定义
class Person {
  public name: string;
  public age: number;
  
  constructor(name: string, age: number) {
    this.name = name;
    this.age = age;
  }
  
  greet(): string {
    return `Hello, I'm ${this.name}`;
  }
}

// 创建实例
let person: Person = new Person('Alice', 25);
console.info(`${person.greet()}`);

// 空类
class EmptyClass {
}

let empty: EmptyClass = new EmptyClass();

// 类作为类型
function processPerson(person: Person): void {
  console.info(`${person.name}`);
}

processPerson(person);
```

### 类的核心组成（属性、方法、构造逻辑）

属性存储状态，构造函数初始化属性，方法封装行为，三者协同构成类的核心结构。

<!-- @[class_properties_methods_constructor](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
class User {
  // 属性
  public id: number;
  public name: string;
  public email: string;
  private password: string;
  
  // 构造函数
  constructor(id: number, name: string, email: string) {
    this.id = id;
    this.name = name;
    this.email = email;
    this.password = '';
  }
  
  // 方法
  getInfo(): string {
    return `User ${this.id}: ${this.name} (${this.email})`;
  }
  
  setPassword(password: string): void {
    this.password = password;
  }
  
  validate(): boolean {
    return this.id > 0 && this.name.length > 0;
  }
}

let user: User = new User(1, 'Alice', 'alice@example.com');
console.info(`${user.getInfo()}`);
```

## 类的属性

类的属性描述对象状态，分为实例属性和静态属性，支持默认值、只读和计算属性。

### 存储属性（实例属性、静态属性）

存储属性分为实例属性（每个实例独立持有）和静态属性（所有实例共享，通过类名访问）。

<!-- @[static_properties](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
class Counter {
  // 实例属性
  public count: number = 0;
  
  // 静态属性
  public static totalInstances: number = 0;
  
  constructor() {
    Counter.totalInstances++;
  }
  
  increment(): void {
    this.count++;
  }
}

let counter1: Counter = new Counter();
let counter2: Counter = new Counter();

console.info(`${counter1.count.toString()}`);  // 0
console.info(`${Counter.totalInstances.toString()}`);  // 2

// 静态属性通过类名访问
console.info(`${Counter.totalInstances.toString()}`);

// 实例属性通过实例访问
counter1.increment();
console.info(`${counter1.count.toString()}`);  // 1
console.info(`${counter2.count.toString()}`);  // 0
```

### 计算属性

类支持通过`get`/`set`关键字定义计算属性，在读写时执行自定义逻辑。详细用法见[属性——计算属性](arkts-language-guide-properties.md)。

### 属性的访问控制（public/private/protected）

public、private、protected控制类成员在类外和子类中的可见性。

<!-- @[ts_access_modifiers](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Classes.ts) -->

``` TypeScript
class BankAccount {
  // public：公开访问
  public accountNumber: string;
  
  // private：私有，仅类内部访问
  private balance: number;
  
  // protected：受保护，类及子类访问
  protected ownerName: string;
  
  constructor(accountNumber: string, ownerName: string) {
    this.accountNumber = accountNumber;
    this.ownerName = ownerName;
    this.balance = 0;
  }
  
  // 公开方法访问私有属性
  deposit(amount: number): void {
    if (amount > 0) {
      this.balance += amount;
    }
  }
  
  getBalance(): number {
    return this.balance;
  }
  
  // protected方法
  protected updateOwner(name: string): void {
    this.ownerName = name;
  }
}

let account: BankAccount = new BankAccount('123', 'Alice');

// public可访问
console.info(`${account.accountNumber}`);

// private不可访问
console.info(`${account.balance}`);  // 编译错误

// protected不可访问
console.info(`${account.ownerName}`);  // 编译错误

// 通过方法访问
account.deposit(100);
console.info(`${account.getBalance()}`);  // 100
```

### 只读属性的声明方式

readonly关键字声明的属性只能在声明处或构造函数中赋值，此后不可修改。

<!-- @[ts_readonly_properties](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Classes.ts) -->

``` TypeScript
class Configuration {
  // readonly只读属性
  readonly appName: string = 'MyApp';
  readonly version: string;
  
  constructor(version: string) {
    this.version = version;  // 构造函数中可赋值
  }
}

let config: Configuration = new Configuration('1.0.0');

console.info(`${config.appName}`);  // 'MyApp'
console.info(`${config.version}`);   // '1.0.0'

// 只读属性不可修改
config.appName = 'NewApp';  // 编译错误
config.version = '2.0.0';  // 编译错误

// readonly与private结合
class Constants {
  private readonly MAX_VALUE: number = 100;
  private readonly MIN_VALUE: number = 0;
  
  getMax(): number {
    return this.MAX_VALUE;
  }
  
  getMin(): number {
    return this.MIN_VALUE;
  }
}
```

## 类的方法

类的方法定义对象行为，包括实例方法、静态方法和方法重载。

### 实例方法的定义与调用

实例方法通过this访问实例属性，通过对象实例调用。

<!-- @[instance_methods](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
class Calculator {
  public value: number = 0;
  
  // 实例方法
  add(n: number): void {
    this.value += n;
  }
  
  subtract(n: number): void {
    this.value -= n;
  }
  
  multiply(n: number): void {
    this.value *= n;
  }
  
  divide(n: number): void {
    if (n !== 0) {
      this.value /= n;
    }
  }
  
  getValue(): number {
    return this.value;
  }
  
  reset(): void {
    this.value = 0;
  }
}

let calc: Calculator = new Calculator();
calc.add(10);
calc.multiply(2);
console.info(`${calc.getValue().toString()}`);  // 20

// 方法链式调用（需返回this）
class Builder {
  private data: string = '';
  
  add(text: string): Builder {
    this.data += text;
    return this;
  }
  
  addLine(text: string): Builder {
    this.data += text + '\n';
    return this;
  }
  
  build(): string {
    return this.data;
  }
}

let result: string = new Builder()
  .add('Hello')
  .add(' ')
  .add('World')
  .build();
console.info(`${result}`);  // 'Hello World'
```

### 静态方法

static关键字声明的方法属于类本身，通过类名调用，无需实例化。

<!-- @[ts_static_methods](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Classes.ts) -->

``` TypeScript
class MathUtils {
  // 静态方法
  static add(a: number, b: number): number {
    return a + b;
  }
  
  static multiply(a: number, b: number): number {
    return a * b;
  }
  
  static max(a: number, b: number): number {
    return a > b ? a : b;
  }
  
  static min(a: number, b: number): number {
    return a < b ? a : b;
  }
}

// 静态方法通过类名调用
console.info(`${MathUtils.add(1, 2)}`);      // 3
console.info(`${MathUtils.multiply(3, 4)}`); // 12
console.info(`${MathUtils.max(5, 10)}`);     // 10

// 创建实例不影响静态方法
let utils: MathUtils = new MathUtils();
utils.add(1, 2);  // 编译错误：实例不能调用静态方法

// 静态方法无法访问实例属性
class StaticExample {
  public instanceValue: number = 10;
  public static staticValue: number = 20;
  
  static getStaticValue(): number {
    return StaticExample.staticValue;  // 可访问静态属性
  }
  
  static getInstanceValue(): number {
    return this.instanceValue;  // 编译错误：无法访问实例属性
  }
}
```

### 方法的重载

方法重载为同一方法名提供多个类型签名，根据传入参数类型分发对应实现。ArkTS的重载采用多个重载签名加一个实现签名的形式：重载签名仅在编译期生效用于类型检查，实现签名对外不可见，调用方只能使用已声明的重载签名；实现签名须兼容所有重载签名，在函数体内通过`typeof`等运行时检查区分不同参数类型的逻辑。

<!-- @[method_overloading](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
class DataProcessor {
  // 方法重载签名
  process(data: string): string;
  process(data: number): number;
  process(data: string | number): string | number {
    if (typeof data === 'string') {
      return data.toUpperCase();
    }
    return data * 2;
  }
  
  // 多参数重载
  format(value: number): string;
  format(value: number, precision: number): string;
  format(value: number, precision?: number): string {
    if (precision !== undefined) {
      return value.toFixed(precision);
    }
    return value.toString();
  }
}

let processor: DataProcessor = new DataProcessor();

console.info(`${processor.process('hello')}`);  // 'HELLO'
console.info(`${processor.process(5)}`);        // 10

console.info(`${processor.format(3.14159)}`);       // '3.14159'
console.info(`${processor.format(3.14159, 2)}`);    // '3.14'
```

## 类的构造与初始化

构造函数在new时初始化属性，支持参数默认值和重载。

### 类的构造函数（构造器重载、参数默认值）

ArkTS类只能有一个构造函数实现体，但支持声明多个重载签名（与方法重载同理）。实际开发中常通过可选参数或静态工厂方法提供多种创建方式。

<!-- @[constructor_optional_params](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
class OptionalCtorPoint {
  public x: number;
  public y: number;

  constructor(x: number, y: number) {
    this.x = x;
    this.y = y;
  }

  static create(x?: number, y?: number): OptionalCtorPoint {
    return new OptionalCtorPoint(x ?? 0, y ?? 0);
  }
}

let ctorPoint1: OptionalCtorPoint = new OptionalCtorPoint(10, 20);
let ctorPoint2: OptionalCtorPoint = OptionalCtorPoint.create();
let ctorPoint3: OptionalCtorPoint = OptionalCtorPoint.create(5);
```

除了可选参数，静态工厂方法是另一种提供多种创建方式的常见模式，它通过命名方法表达不同的构造意图。

<!-- @[static_factory_methods](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
class ColorValue {
  public red: number;
  public green: number;
  public blue: number;

  constructor(red: number, green: number, blue: number) {
    this.red = red;
    this.green = green;
    this.blue = blue;
  }

  static fromRGB(r: number, g: number, b: number): ColorValue {
    return new ColorValue(r, g, b);
  }

  static fromHex(hex: string): ColorValue {
    let r: number = Number.parseInt(hex.substring(1, 3), 16);
    let g: number = Number.parseInt(hex.substring(3, 5), 16);
    let b: number = Number.parseInt(hex.substring(5, 7), 16);
    return new ColorValue(r, g, b);
  }

  static fromName(name: string): ColorValue {
    switch (name) {
      case 'red':
        return new ColorValue(255, 0, 0);
      case 'green':
        return new ColorValue(0, 255, 0);
      case 'blue':
        return new ColorValue(0, 0, 255);
      default:
        return new ColorValue(0, 0, 0);
    }
  }
}

let cvColor1: ColorValue = ColorValue.fromRGB(255, 128, 0);
let cvColor2: ColorValue = ColorValue.fromHex('#FF8000');
let cvColor3: ColorValue = ColorValue.fromName('red');
```

### 继承类的构造函数

子类构造函数必须通过`super()`调用父类构造函数，确保父类属性先初始化。详细用法见[继承——继承中的构造函数](arkts-language-guide-inheritance.md)。

### 可选属性的初始化处理

可选属性（?）可能为undefined，使用前需检查或提供默认值。

<!-- @[optional_properties](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
class UserProfile {
  public name: string;
  public age?: number;          // 可选属性
  public email?: string;
  public bio?: string;
  
  constructor(name: string) {
    this.name = name;
    // 可选属性不必须初始化
  }
  
  setAge(age: number): void {
    this.age = age;
  }
  
  setEmail(email: string): void {
    this.email = email;
  }
  
  getAge(): number {
    return this.age ?? 0;
  }
  
  hasEmail(): boolean {
    return this.email !== undefined;
  }
}

let profile: UserProfile = new UserProfile('Alice');
profile.setAge(25);
console.info(`${profile.getAge()}`);  // 25

// 可选属性访问需要检查
if (profile.email !== undefined) {
  console.info(`${profile.email}`);
}

// 使用可选链
let bio: string | undefined = profile.bio;
console.info(`${bio}`);  // undefined
```

## 类的访问控制

访问修饰符控制属性的可访问性，保护内部数据。

### 访问修饰符的分类

public、private、protected、readonly可单独或组合使用，分别控制类内、子类和类外的可见性与可写性。

<!-- @[ts_access_modifiers_summary](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Classes.ts) -->

``` TypeScript
class Example {
  // public：公开，任何地方可访问
  public publicProperty: string = 'public';
  
  // private：私有，仅类内部可访问
  private privateProperty: string = 'private';
  
  // protected：受保护，类及子类可访问
  protected protectedProperty: string = 'protected';
  
  // readonly：只读，初始化后不可修改
  readonly readonlyProperty: string = 'readonly';
  
  // 组合使用
  private readonly privateReadonly: string = 'private readonly';
  protected readonly protectedReadonly: string = 'protected readonly';
  
  public publicMethod(): void {
    // 可访问所有属性
    console.info(`${this.publicProperty}`);
    console.info(`${this.privateProperty}`);
    console.info(`${this.protectedProperty}`);
  }
  
  private privateMethod(): void {
    console.info(`Private method`);
  }
  
  protected protectedMethod(): void {
    console.info(`Protected method`);
  }
}

let example: Example = new Example();

// public可访问
console.info(`${example.publicProperty}`);
example.publicMethod();

// private不可访问
console.info(`${example.privateProperty}`);  // 编译错误
example.privateMethod();                // 编译错误

// protected不可访问
console.info(`${example.protectedProperty}`);  // 编译错误
example.protectedMethod();                // 编译错误

// readonly可读不可写
console.info(`${example.readonlyProperty}`);
example.readonlyProperty = 'new';  // 编译错误
```

### 不同访问修饰符的作用域

public在类内、子类和类外均可见；private仅在类内可见；protected在类内及子类可见，类外不可见。

<!-- @[ts_access_modifiers_inheritance](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Classes.ts) -->

``` TypeScript
class Base {
  public publicValue: number = 1;
  private privateValue: number = 2;
  protected protectedValue: number = 3;
  
  testAccess(): void {
    // 类内部可访问所有
    console.info(`${this.publicValue}`);
    console.info(`${this.privateValue}`);
    console.info(`${this.protectedValue}`);
  }
}

class Derived extends Base {
  testDerivedAccess(): void {
    // 子类可访问public和protected
    console.info(`${this.publicValue}`);
    console.info(`${this.privateValue}`);  // 编译错误
    console.info(`${this.protectedValue}`);
  }
}

// 外部访问
let base: Base = new Base();
console.info(`${base.publicValue}`);  // 1（public可访问）
console.info(`${base.privateValue}`);   // 编译错误
console.info(`${base.protectedValue}`); // 编译错误

let derived: Derived = new Derived();
console.info(`${derived.publicValue}`);  // 1（public可访问）
```

### 访问控制的封装示例

属性默认private，通过public的getter/setter控制外部访问。

<!-- @[encapsulation_practice](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
// 封装内部状态，公开接口
class BankAccount {
  private balance: number = 0;
  private accountNumber: string;
  
  constructor(accountNumber: string) {
    this.accountNumber = accountNumber;
  }
  
  // 公开读取接口
  getBalance(): number {
    return this.balance;
  }
  
  getAccountNumber(): string {
    return this.accountNumber;
  }
  
  // 公开操作接口
  deposit(amount: number): boolean {
    if (amount > 0) {
      this.balance += amount;
      return true;
    }
    return false;
  }
  
  withdraw(amount: number): boolean {
    if (amount > 0 && this.balance >= amount) {
      this.balance -= amount;
      return true;
    }
    return false;
  }
}

let account: BankAccount = new BankAccount('ACC-001');
account.deposit(100);
account.withdraw(50);
console.info(`${account.getBalance()}`);  // 50

// 使用protected供子类使用
class BestLogger {
  protected logs: string[] = [];
  
  log(message: string): void {
    this.logs.push(message);
  }
  
  getLogs(): string[] {
    return [...this.logs];
  }
}

class AdvancedLogger extends BestLogger {
  logWithTimestamp(message: string): void {
    let timestamp: string = new Date().toISOString();
    this.logs.push(`${timestamp}: ${message}`);  // 可访问protected
  }
}

// 使用readonly保护不变数据
class Configuration {
  public readonly appName: string;
  public readonly maxConnections: number;
  
  constructor(appName: string, maxConnections: number) {
    this.appName = appName;
    this.maxConnections = maxConnections;
  }
}
```

## 类的继承

通过extends关键字，子类继承父类的属性与方法，在构造函数中调用super()复用父类初始化逻辑，并可覆盖或新增方法以扩展父类行为。

### 类的继承语法

使用extends关键字让子类继承父类的属性和方法。

<!-- @[inheritance_chain](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
class Shape {
  public color: string;
  
  constructor(color: string) {
    this.color = color;
  }
  
  draw(): void {
    console.info(`Drawing shape with color ${this.color}`);
  }
}

class ChainCircle extends Shape {
  public radius: number;
  
  constructor(color: string, radius: number) {
    super(color);
    this.radius = radius;
  }
  
  draw(): void {
    console.info(`Drawing chainCircle with radius ${this.radius}`);
  }
  
  getArea(): number {
    return Math.PI * this.radius * this.radius;
  }
}

let chainCircle: ChainCircle = new ChainCircle('red', 5);
chainCircle.draw();

class ChainRectangle extends Shape {
  public width: number;
  public height: number;
  
  constructor(color: string, width: number, height: number) {
    super(color);
    this.width = width;
    this.height = height;
  }
  
  draw(): void {
    console.info(`Drawing rectangle ${this.width}x${this.height}`);
  }
}

// 继承链
let chainRect: ChainRectangle = new ChainRectangle('blue', 10, 20);
chainRect.draw();
```

### 方法重写

子类重新定义父类方法实现多态。`override`关键字标记被重写的方法，使编译器在父类方法被重命名或删除时发出错误提示，避免重写方法与父类方法意外脱钩。ArkTS中`override`为可选关键字，推荐在重写父类方法时显式标注`override`，以便编译器检查父类是否存在同名方法。

<!-- @[method_override](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
class Base {
  method(): void {
    console.info('Base method');
  }
}

class Derived extends Base {
  // TypeScript使用override标记（可选）
  method(): void {
    console.info('Derived method');
  }
}

let derived: Derived = new Derived();
derived.method();  // 'Derived method'

// 重写带返回值的方法
class OverrideCalculator {
  calculate(a: number, b: number): number {
    return a + b;
  }
}

class AdvancedCalculator extends OverrideCalculator {
  calculate(a: number, b: number): number {
    return a * b;  // 改变计算逻辑
  }
}

let overrideCalc: OverrideCalculator = new AdvancedCalculator();
console.info(`${overrideCalc.calculate(3, 4)}`);  // 12

// 重写时保持签名一致
class Logger {
  log(message: string): void {
    console.info(`${message}`);
  }
}

class FileLogger extends Logger {
  log(message: string): void {  // 必须保持参数和返回类型一致
    // 写入文件
    console.info(`[File] ${message}`);
  }
}
```

### 父类方法的调用

子类构造函数中`super()`必须是第一条语句，方法中通过`super.method()`调用父类实现。

<!-- @[super_keyword](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
class Parent {
  greet(): string {
    return 'Hello from Parent';
  }
  
  process(): void {
    console.info('Parent processing');
  }
}

class Child extends Parent {
  greet(): string {
    return 'Hello from Child';
  }
  
  greetWithParent(): string {
    return `${super.greet()} and ${this.greet()}`;
  }
  
  process(): void {
    super.process();  // 调用父类方法
    console.info('Child processing');
  }
}

let child: Child = new Child();
console.info(`${child.greetWithParent()}`);  
// 'Hello from Parent and Hello from Child'

child.process();
// 输出：Parent processing, Child processing

// super在构造函数中
class KwBase {
  protected value: number;
  
  constructor(value: number) {
    this.value = value;
  }
}

class Extended extends KwBase {
  public multiplier: number;
  
  constructor(value: number, multiplier: number) {
    super(value);  // 必须先调用super
    this.multiplier = multiplier;
  }
  
  getCalculated(): number {
    return this.value * this.multiplier;
  }
}
```

### 继承的限制（单继承特性）

ArkTS只支持单继承，一个子类只能extends一个父类。

**错误示例**

<!-- @[ts_single_inheritance_limitation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Classes.ts) -->

``` TypeScript
// TypeScript/ArkTS只支持单继承
class A {
  methodA(): void {}
}

class B {
  methodB(): void {}
}

class CMulti extends A, B {}  // 编译错误：不支持多继承
```

虽然不支持多继承，但一个类可以实现多个接口，从而组合多种行为契约。

<!-- @[interface_multi_implementation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
interface MultiIA {
  methodA(): void;
}

interface MultiIB {
  methodB(): void;
}

class MultiC implements MultiIA, MultiIB {
  methodA(): void {}
  methodB(): void {}
}
```

当需要复用多个类的实现逻辑时，可将它们合并到一个基类中，再通过单继承派生子类。

<!-- @[single_inheritance_combination](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
class CombinedBase {
  aMethod(): void {
    console.info('A method');
  }

  bMethod(): void {
    console.info('B method');
  }
}

class SingleDerived extends CombinedBase {
  cMethod(): void {
    console.info('C method');
  }
}

let siObj: SingleDerived = new SingleDerived();
siObj.aMethod();
siObj.bMethod();
siObj.cMethod();
```

## 类的引用语义

类的实例是引用类型，赋值和传参传递引用而非副本。

### 类的引用语义（赋值与拷贝的内存表现）

类实例赋值和传参传递的是引用，修改任一变量指向的对象会影响所有引用；深拷贝需手动实现。

<!-- @[object_reference_copy](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
class CopyPerson {
  public name: string;
  public age: number;
  
  constructor(name: string, age: number) {
    this.name = name;
    this.age = age;
  }
}

let person1: CopyPerson = new CopyPerson('Alice', 25);
let person2: CopyPerson = person1;  // 引用赋值，指向同一对象

person2.name = 'Bob';
console.info(`${person1.name}`);  // 'Bob'（person1也被修改）

// 深拷贝需要手动实现
function copyPerson(source: CopyPerson): CopyPerson {
  return new CopyPerson(source.name, source.age);
}

let person3: CopyPerson = copyPerson(person1);
person3.name = 'Charlie';
console.info(`${person1.name}`);  // 'Bob'（不影响person1）
console.info(`${person3.name}`);  // 'Charlie'

// 实现拷贝方法
class CopyUser {
  public id: number;
  public name: string;
  
  constructor(id: number, name: string) {
    this.id = id;
    this.name = name;
  }
  
  copy(): CopyUser {
    return new CopyUser(this.id, this.name);
  }
}

let user1: CopyUser = new CopyUser(1, 'Alice');
let user2: CopyUser = user1.copy();
```

### 引用比较（===/!==）

===比较两个引用是否指向同一对象，不比较内容是否相同。

<!-- @[object_comparison](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
class Point {
  public x: number;
  public y: number;
  
  constructor(x: number, y: number) {
    this.x = x;
    this.y = y;
  }
}

let p1: Point = new Point(1, 2);
let p2: Point = new Point(1, 2);
let p3: Point = p1;

// 引用比较
console.info(`${p1 === p2}`);  // false（不同对象）
console.info(`${p1 === p3}`);  // true（同一引用）

// 内容比较需自定义方法
class PointWithEquals {
  public x: number;
  public y: number;
  
  constructor(x: number, y: number) {
    this.x = x;
    this.y = y;
  }
  
  equals(other: PointWithEquals): boolean {
    return this.x === other.x && this.y === other.y;
  }
}

let pe1: PointWithEquals = new PointWithEquals(1, 2);
let pe2: PointWithEquals = new PointWithEquals(1, 2);

console.info(`${pe1 === pe2}`);      // false
console.info(`${pe1.equals(pe2)}`);  // true
```

### 类的使用场景选择

类适合封装数据连同其操作行为、且需要复用与继承的场景；接口适合仅描述数据结构形状；对象字面量适合一次性、简单的数据组织。

<!-- @[class_vs_interface](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
// 使用类：需要封装数据和行为的场景
class Order {
  public id: number;
  public items: string[];
  public total: number;
  
  constructor(id: number) {
    this.id = id;
    this.items = [];
    this.total = 0;
  }
  
  addItem(item: string, price: number): void {
    this.items.push(item);
    this.total += price;
  }
  
  removeItem(item: string, price: number): void {
    let index: number = this.items.indexOf(item);
    if (index >= 0) {
      this.items.splice(index, 1);
      this.total -= price;
    }
  }
  
  getTotal(): number {
    return this.total;
  }
}

// 使用接口：只需数据结构的场景
interface Product {
  id: number;
  name: string;
  price: number;
}

let product: Product = { id: 1, name: 'Item', price: 100 };

// 类vs对象字面量
// 类：可复用、有方法、可继承
// 对象字面量：简单数据、一次性使用
```

## 类的原型与继承链

原型链是TypeScript继承的底层机制，类继承通过原型链实现方法查找和类型判断。

### 原型对象的概念

prototype对象存放所有实例共享的方法。ArkTS通过`class extends`自动维护原型链，不支持直接操作`prototype`属性。

**TypeScript对照**

<!-- @[ts_prototype_methods](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Classes.ts) -->

``` TypeScript
// TypeScript对照写法，ArkTS不支持prototype赋值
class ProtoVehicle {
  public brand: string;
  public speed: number = 0;

  constructor(brand: string) {
    this.brand = brand;
  }

  // 声明方法，实现由prototype提供
  getInfo(): string {
    return '';
  }
}

// TypeScript支持通过prototype赋值扩展方法，ArkTS不支持
ProtoVehicle.prototype.getInfo = function(): string {
  return `${this.brand} - ${this.speed}km/h`;
};

let protoVehicle: ProtoVehicle = new ProtoVehicle('Toyota');
protoVehicle.speed = 60;
console.info(`${protoVehicle.getInfo()}`); // Toyota - 60km/h
```

### 原型链的查找机制

访问实例成员时，引擎沿原型链从实例自身逐级向上查找：先在自身定义中匹配，未命中则依次查找父类、祖父类，直至命中为止；子类同名成员会覆盖父类成员。

<!-- @[prototype_chain](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
class PcGrandParent {
  methodA(): void {
    console.info('GrandParent A');
  }
}

class PcParent extends PcGrandParent {
  methodB(): void {
    console.info('Parent B');
  }
}

class PcChild extends PcParent {
  methodC(): void {
    console.info('Child C');
  }
}

let pcChild: PcChild = new PcChild();

// 原型链查找
pcChild.methodA();  // GrandParent（继承）
pcChild.methodB();  // Parent（继承）
pcChild.methodC();  // Child（自身）

// 方法覆盖
class PcParent2 {
  method(): void {
    console.info('Parent method');
  }
}

class PcChild2 extends PcParent2 {
  method(): void {
    console.info('Child method');
    super.method();
  }
}

let pcChild2: PcChild2 = new PcChild2();
pcChild2.method();
```

### 原型继承与类继承的关系

类继承在底层通过原型链实现，`instanceof`检查沿原型链逐级匹配。

<!-- @[prototype_inheritance](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
// 类继承本质是原型继承
class ProtoBase {
  public value: number = 10;
  
  getValue(): number {
    return this.value;
  }
}

class ProtoDerived extends ProtoBase {
  public multiplier: number = 2;
  
  getCalculated(): number {
    return this.getValue() * this.multiplier;
  }
}

let protoDerived: ProtoDerived = new ProtoDerived();

console.info(`${protoDerived.value.toString()}`);         // 10（继承属性）
console.info(`${protoDerived.getValue().toString()}`);    // 10（继承方法）
console.info(`${protoDerived.getCalculated().toString()}`); // 20（自身方法）

// instanceof检查原型链
console.info(`${(protoDerived instanceof ProtoDerived).toString()}`);  // true
console.info(`${(protoDerived instanceof ProtoBase).toString()}`);     // true
console.info(`${(protoDerived instanceof Object).toString()}`);   // true
```

## 嵌套类型

嵌套类型用于把只服务于某个外部类型的辅助类型收束在一起，减少全局命名数量。TypeScript和ArkTS都不支持在类内部声明类，辅助类型应在模块级别与主类并列声明。

### 类型分组

将辅助类与主类放在同一模块中并列声明，通过命名体现归属关系。

<!-- @[nested_type_grouping](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
class ProcessorResult {
  public success: boolean = false;
  public data: string = '';
  public error: string = '';

  isSuccess(): boolean {
    return this.success;
  }
}

class NestedDataProcessor {
  process(input: string): ProcessorResult {
    let result: ProcessorResult = new ProcessorResult();
    if (input.length > 0) {
      result.success = true;
      result.data = input.trim();
    } else {
      result.error = 'Empty input';
    }
    return result;
  }
}

let ntProcessor: NestedDataProcessor = new NestedDataProcessor();
let ntResult: ProcessorResult = ntProcessor.process('hello');
console.info(`${ntResult.isSuccess()}`); // true
```

### 外部实例引用

辅助类需要访问外部类的实例数据时，通过构造函数传入引用。

<!-- @[nested_type_external_instance](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
class GroupSnapshot {
  private ownerValue: number;

  constructor(ownerValue: number) {
    this.ownerValue = ownerValue;
  }

  read(): number {
    return this.ownerValue;
  }
}

class CounterGroup {
  public value: number = 0;

  createSnapshot(): GroupSnapshot {
    return new GroupSnapshot(this.value);
  }
}

let neGroup: CounterGroup = new CounterGroup();
neGroup.value = 10;
let neSnapshot: GroupSnapshot = neGroup.createSnapshot();
console.info(`${neSnapshot.read()}`); // 10
```

## 装饰器

ArkTS支持类装饰器、方法装饰器、访问器装饰器、属性装饰器和参数装饰器。装饰器实现需遵循ArkTS语法规则：使用箭头函数替代函数表达式、显式标注类型、避免独立`this`。ArkUI的`@Component`、`@Entry`、状态装饰器，以及并发场景中的`@Sendable`、`@Concurrent`属于框架或并发模型定义的专用装饰器。

### 类装饰器

类装饰器通过函数修饰类声明，在类创建时执行装饰逻辑。

<!-- @[class_decorator_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
function logged(constructor: Function): void {
  console.info(`Class ${constructor.name} created`);
}

@logged
class DecoService {
  public name: string = 'default';
}

let decoService: DecoService = new DecoService();
// 控制台输出：Class DecoService created
```

### 装饰器工厂

装饰器工厂返回一个装饰器函数，可接收参数进行配置。

<!-- @[decorator_factory_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
function format(prefix: string): (constructor: Function) => void {
  return (constructor: Function): void => {
    console.info(`${prefix} ${constructor.name}`);
  };
}

@format('Created')
class DecoFactoryService {
  public id: number = 0;
}

let decoFactoryService: DecoFactoryService = new DecoFactoryService();
// 控制台输出：Created DecoFactoryService
```

### 方法装饰器

方法装饰器接收`target`、`propertyKey`和`descriptor`三个参数，可读取或修改方法描述符。

<!-- @[method_decorator_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
function logMethod(target: Object, propertyKey: string, descriptor: PropertyDescriptor): void {
  console.info(`Method ${propertyKey} decorated`);
}

class DecoCalculator {
  @logMethod
  add(a: number, b: number): number {
    return a + b;
  }
}

let decoCalc: DecoCalculator = new DecoCalculator();
console.info(`${decoCalc.add(1, 2)}`); // 3
```

### 访问器装饰器

访问器装饰器用于修饰`get`/`set`访问器，参数与方法装饰器相同。

<!-- @[accessor_decorator_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
function logAccessor(target: Object, propertyKey: string, descriptor: PropertyDescriptor): void {
  console.info(`Accessor ${propertyKey} decorated`);
}

class DecoCounter {
  private _count: number = 0;

  @logAccessor
  get count(): number {
    return this._count;
  }

  set count(value: number) {
    this._count = value;
  }
}

let decoCounter: DecoCounter = new DecoCounter();
decoCounter.count = 5;
console.info(`${decoCounter.count}`); // 5
```

### 属性装饰器

属性装饰器接收`target`和`propertyKey`两个参数，常用于标记或注入。

<!-- @[property_decorator_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
function logProperty(target: Object, propertyKey: string): void {
  console.info(`Property ${propertyKey} decorated`);
}

class DecoConfig {
  @logProperty
  public name: string = 'default';
}

let decoConfig: DecoConfig = new DecoConfig();
console.info(`${decoConfig.name}`); // default
```

### 参数装饰器

参数装饰器接收`target`、`propertyKey`和`parameterIndex`三个参数，常用于参数验证标记。

<!-- @[parameter_decorator_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
function logParam(target: Object, propertyKey: string, parameterIndex: number): void {
  console.info(`Param ${parameterIndex} of ${propertyKey} decorated`);
}

class DecoProcessor {
  process(@logParam input: string): string {
    return input.toUpperCase();
  }
}

let decoProc: DecoProcessor = new DecoProcessor();
console.info(`${decoProc.process('hello')}`); // HELLO
```

### 使用继承或组合实现横切逻辑

装饰器之外的另一种选择是通过基类继承（在父类构造函数或方法中注入日志等逻辑）或组合（持有一个功能对象并委托调用）实现横切逻辑。

<!-- @[base_class_pattern](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
class LoggedBase {
  private className: string;

  constructor(className: string) {
    this.className = className;
    console.info(`Creating ${className}`);
  }

  protected log(methodName: string): void {
    console.info(`Calling ${this.className}.${methodName}`);
  }
}

class UserService extends LoggedBase {
  constructor() {
    super('UserService');
  }

  getData(): string {
    this.log('getData');
    return 'data';
  }
}

let service: UserService = new UserService();
console.info(`${service.getData()}`);
```

### 使用访问器实现属性监听

通过get/set访问器实现属性变更监听：将真实字段设为private，在setter中加入校验或副作用逻辑。

<!-- @[observable_property](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
class ObservableCounter {
  private value: number = 0;

  get count(): number {
    return this.value;
  }

  set count(newValue: number) {
    if (this.value !== newValue) {
      this.value = newValue;
      console.info(`Counter changed to ${newValue}`);
    }
  }
}

let counter: ObservableCounter = new ObservableCounter();
counter.count = 1;
```

## ES私有字段与运行时this

### ES私有字段（#field）

TypeScript支持`#`前缀的私有字段，提供运行时也私有的成员。与`private`关键字不同，`#field`在编译后仍保持私有。ArkTS中使用`private`修饰符替代。

**TypeScript对照**

<!-- @[ts_private_fields](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Classes.ts) -->

``` TypeScript
// TypeScript对照写法，ArkTS中使用private修饰符替代
class TsDog {
  #barkAmount: number = 0;
  public personality: string = 'happy';

  bark(): void {
    this.#barkAmount++;
  }
}
```

ArkTS中使用`private`修饰符。

<!-- @[private_field_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
class PrivateFieldDog {
  private barkAmount: number = 0;
  public personality: string = 'happy';

  bark(): void {
    this.barkAmount++;
  }

  getBarkCount(): number {
    return this.barkAmount;
  }
}

let pfDog: PrivateFieldDog = new PrivateFieldDog();
pfDog.bark();
pfDog.bark();
console.info(`${pfDog.getBarkCount().toString()}`);  // 2
```

`private`为编译期检查（软私有），`#field`为运行时也私有（硬私有）。ArkTS使用`private`修饰符。

### 运行时的this

TypeScript中`this`的值取决于函数调用方式。将类方法赋值给变量后调用，`this`可能丢失绑定。

<!-- @[runtime_this_issue](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
class ThisExample {
  public name: string = 'MyClass';

  getName(): string {
    return this.name;
  }
}

let thisEx: ThisExample = new ThisExample();
console.info(`${thisEx.getName()}`);  // MyClass

// 赋值给变量后调用，this可能丢失
let thisG = thisEx.getName;
```

将方法赋值给变量后调用，`this`会丢失绑定，直接调用会产生运行时错误。

**TypeScript对照**

<!-- @[ts_runtime_this_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Classes.ts) -->

``` TypeScript
// TypeScript对照写法，演示this丢失的运行时错误
class TsThisExample {
  public name: string = 'MyClass';

  getName(): string {
    return this.name;
  }
}

let tsThisEx: TsThisExample = new TsThisExample();
console.info(`${tsThisEx.getName()}`);  // MyClass

let tsThisG = tsThisEx.getName;
tsThisG();  // 运行时错误：Cannot read property 'name' of undefined
```

使用箭头函数属性绑定`this`，在创建时固定`this`指向。

<!-- @[arrow_function_this](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
class ArrowThisHandler {
  private name: string = 'handler';

  public handle = (): void => {
    console.info(`${this.name}`);
  };
}

let arrowHandler: ArrowThisHandler = new ArrowThisHandler();
let arrowH = arrowHandler.handle;
arrowH();  // handler（this正确绑定）
```

箭头函数属性每个实例都有一份函数副本，无法通过`super`调用基类方法。

### this参数标注

方法可声明`this`参数，静态强制调用上下文的类型。编译时擦除，不影响运行时。

<!-- @[this_parameter_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
class ThisCounter {
  public count: number = 0;
  increment(this: ThisCounter): void {
    this.count++;
  }
}

let thisCounter: ThisCounter = new ThisCounter();
thisCounter.increment();
console.info(`${thisCounter.count}`); // 1
```

### 构造签名

通过`InstanceType<typeof T>`可从类本身获取实例类型。ArkTS中直接使用类名作为实例类型。

**TypeScript对照**

<!-- @[ts_constructor_signature](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Classes.ts) -->

``` TypeScript
// TypeScript对照写法，ArkTS中直接使用类名
class TsCtorPoint {
  public x: number;
  public y: number;
  constructor(x: number, y: number) {
    this.x = x;
    this.y = y;
  }
}
type TsCtorPointInstance = InstanceType<typeof TsCtorPoint>;
```

<!-- @[ctor_signature_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
class CtorPoint {
  public x: number;
  public y: number;

  constructor(x: number, y: number) {
    this.x = x;
    this.y = y;
  }
}

function moveCtorRight(point: CtorPoint): void {
  point.x += 5;
}

let ctorP: CtorPoint = new CtorPoint(3, 4);
moveCtorRight(ctorP);
console.info(`${ctorP.x.toString()}`);  // 8
```

### 静态块

静态块（`static { }`）在类加载时执行一次，适合封装需要错误处理的静态初始化逻辑，可直接访问私有静态字段。

<!-- @[static_block](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
class TsStaticConfig {
  private static count: number = 0;

  static {
    try {
      let data: string[] = ['a', 'b', 'c'];
      TsStaticConfig.count = data.length;
    } catch (e) {
      TsStaticConfig.count = 0;
    }
  }
}
```

也可以使用静态方法实现相同的初始化逻辑，通过显式调用控制初始化时机：

<!-- @[static_block_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
class StaticBlockConfig {
  private static count: number = 0;
  private static initialized: boolean = false;

  static initialize(): void {
    if (StaticBlockConfig.initialized) {
      return;
    }
    try {
      let data: string[] = ['a', 'b', 'c'];
      StaticBlockConfig.count = data.length;
      StaticBlockConfig.initialized = true;
    } catch (e) {
      StaticBlockConfig.count = 0;
      StaticBlockConfig.initialized = true;
    }
  }

  static getCount(): number {
    return StaticBlockConfig.count;
  }
}

StaticBlockConfig.initialize();
console.info(`${StaticBlockConfig.getCount().toString()}`);  // 3
```

## 类之间的关系

TypeScript中类之间的类型兼容性基于结构类型（鸭子类型），结构相同的类可互相替代，即使没有显式继承关系。**ArkTS不支持结构类型**，类之间的赋值必须有显式继承或`implements`关系。

**TypeScript对照**

<!-- @[ts_structural_typing](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Classes.ts) -->

``` TypeScript
// TypeScript结构类型，ArkTS不支持
class TsRelPoint1 {
  public x: number = 0;
  public y: number = 0;
}

class TsRelPoint2 {
  public x: number = 0;
  public y: number = 0;
}

// 结构相同，可互相赋值（ArkTS不支持）
let tsRelP1: TsRelPoint1 = new TsRelPoint2();
let tsRelP2: TsRelPoint2 = new TsRelPoint1();
console.info(`${tsRelP1.x}`);
```

子类型关系也无需显式继承，有父类所有成员的类是父类的子类型。

**TypeScript对照**

<!-- @[ts_structural_subtype](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Classes.ts) -->

``` TypeScript
// TypeScript结构子类型，ArkTS不支持
class TsRelPerson {
  public name: string = '';
  public age: number = 0;
}

class TsRelEmployee {
  public name: string = '';
  public age: number = 0;
  public salary: number = 0;
}

// Employee有Person的所有成员，是子类型（ArkTS不支持）
let tsRelP: TsRelPerson = new TsRelEmployee();
console.info(`${tsRelP.name}`);
```

ArkTS中需要显式继承才能实现类之间的赋值兼容。空类没有成员，应避免定义空类。

## this类型

`this`类型在方法返回值中使用`this`，使方法返回当前实例类型，支持链式调用。子类调用继承的方法时返回子类类型。**ArkTS不支持`this`作为类型标注**，使用显式类名作为返回类型替代。

**TypeScript对照**

<!-- @[ts_this_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Classes.ts) -->

``` TypeScript
// TypeScript写法，ArkTS不支持this作为返回类型
class TsStringBuilder {
  public parts: string[] = [];

  append(text: string): this {
    this.parts.push(text);
    return this;
  }

  toString(): string {
    return this.parts.join('');
  }
}

let tsSb: TsStringBuilder = new TsStringBuilder();
let tsResult: string = tsSb.append('Hello').append(', ').append('World').toString();
console.info(`${tsResult}`); // Hello, World
```

ArkTS替代方式：使用显式类名作为返回类型实现链式调用。

<!-- @[string_builder_explicit_return](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
class StringBuilder {
  public parts: string[] = [];

  append(text: string): StringBuilder {
    this.parts.push(text);
    return this;
  }

  toString(): string {
    return this.parts.join('');
  }
}

let sb: StringBuilder = new StringBuilder();
let sbResult: string = sb.append('Hello').append(', ').append('World').toString();
console.info(`${sbResult}`); // Hello, World
```

> **说明：**
> 
> `this`作为参数类型（如`sameAs(other: this)`）同样不支持，使用显式类名作为参数类型替代。

## 参数属性

TypeScript支持在构造函数参数前添加访问修饰符（`public`、`private`、`protected`、`readonly`），编译器自动声明并赋值对应属性。**ArkTS不支持参数属性语法**。

<!-- @[ts_parameter_properties](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Classes.ts) -->

``` TypeScript
// TypeScript写法，ArkTS不支持构造函数参数属性
class TsPoint {
  constructor(public x: number, public y: number) {}
}

let tsPt: TsPoint = new TsPoint(3, 4);
console.info(`${tsPt.x}, ${tsPt.y}`); // 3, 4
```

ArkTS替代方式：显式声明属性并在构造函数中赋值。

<!-- @[explicit_property_declaration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
class ExplicitPoint {
  public x: number;
  public y: number;

  constructor(x: number, y: number) {
    this.x = x;
    this.y = y;
  }
}

let epPoint: ExplicitPoint = new ExplicitPoint(3, 4);
console.info(`${epPoint.x}, ${epPoint.y}`); // 3, 4
```

## 类表达式

TypeScript支持类表达式，将类赋值给变量，可省略类名，也支持泛型。**ArkTS不支持类表达式**。

**TypeScript对照**

<!-- @[ts_class_expression](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Classes.ts) -->

``` TypeScript
// TypeScript写法，ArkTS不支持类表达式
const someClass = class<T> {
  content: T;
  constructor(content: T) {
    this.content = content;
  }
};

let tsInstance = new someClass<string>('hello');
console.info(`${tsInstance.content}`); // hello
```

ArkTS替代：使用类声明。

<!-- @[class_declaration_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
class DeclaredClass<T> {
  public content: T;

  constructor(content: T) {
    this.content = content;
  }
}

let dcInstance: DeclaredClass<string> = new DeclaredClass('hello');
console.info(`${dcInstance.content}`); // hello
```

## Mixins

Mixin模式通过函数组合多个类的行为，在不支持多继承的语言中实现代码复用。TypeScript中可通过泛型函数实现Mixin。**ArkTS不支持Mixin模式**，需要组合行为时使用接口实现或组合模式替代。

### TypeScript Mixin对照

**TypeScript对照**

<!-- @[ts_mixins](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Classes.ts) -->

``` TypeScript
// TypeScript写法，ArkTS不支持Mixin模式
class TsBaseWidget {
  public id: number = 0;
}

function Scoped(Base: typeof TsBaseWidget) {
  return class extends Base {
    public scope: string = 'local';
  };
}

let ScopedWidget = Scoped(TsBaseWidget);
let tsWidget = new ScopedWidget();
console.info(`${tsWidget.scope}`); // local
```

### ArkTS替代：组合模式

通过组合（在一个类中持有其他类的实例）实现类似效果，比继承更灵活。

<!-- @[mixin_composition_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
interface MixinLoggable {
  log(message: string): void;
}

class MixinConsoleLogger implements MixinLoggable {
  log(message: string): void {
    console.info(`[LOG] ${message}`);
  }
}

class MixinService {
  public logger: MixinLoggable;

  constructor(logger: MixinLoggable) {
    this.logger = logger;
  }

  processData(data: string): void {
    this.logger.log(`Processing: ${data}`);
  }
}

let mixinService: MixinService = new MixinService(new MixinConsoleLogger());
mixinService.processData('test'); // [LOG] Processing: test
```

### ArkTS替代：接口实现

通过定义接口并让类实现多个接口，组合多种行为。

<!-- @[mixin_interface_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
interface MixinDisposable {
  dispose(): void;
}

interface MixinSerializable {
  serialize(): string;
}

class MixinResource implements MixinDisposable, MixinSerializable {
  public name: string;

  constructor(name: string) {
    this.name = name;
  }

  dispose(): void {
    console.info(`Disposing ${this.name}`);
  }

  serialize(): string {
    return JSON.stringify(this.name);
  }
}

let mixinResource: MixinResource = new MixinResource('config');
console.info(`${mixinResource.serialize()}`); // "config"
mixinResource.dispose(); // Disposing config
```
