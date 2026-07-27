# 属性
<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

属性是类的组成部分，用于存储数据和定义访问方式。ArkTS提供多种属性类型和访问控制机制。

## 属性的分类与基础概念

属性是类中存储数据的成员，分为实例属性（每个实例独立）和静态属性（所有实例共享），支持只读、计算和访问控制。

### 属性的定义与作用

属性以 `修饰符 名称: 类型 = 初始值` 形式声明，可在声明处或构造函数中初始化，通过 `实例.属性名` 访问；可选属性用 `?`、只读属性用 `readonly` 标记。

<!-- @[property_definition_basics](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Properties.ets) -->

``` TypeScript
class Person {
  // 属性定义：存储数据
  public name: string;         // 姓名属性
  public age: number;          // 年龄属性
  public email?: string;       // 可选属性
  
  constructor(name: string, age: number) {
    this.name = name;
    this.age = age;
  }
  
  // 属性的作用：封装数据，提供访问接口
  getInfo(): string {
    return `${this.name}, ${this.age} years old`;
  }
}

let person: Person = new Person('Alice', 25);
console.info(`${person.name}`);  // 'Alice'
console.info(`${person.age.toString()}`);   // 25

// 属性用于存储状态
class Counter {
  public count: number = 0;  // 存储计数状态
  
  increment(): void {
    this.count++;  // 通过属性管理状态
  }
  
  getCount(): number {
    return this.count;
  }
}

let counter: Counter = new Counter();
counter.increment();
console.info(`${counter.getCount().toString()}`);  // 1
```

### 实例属性与静态属性的区别

实例属性和静态属性是类的两种属性类型，它们在访问方式（实例属性需要通过类实例访问，而静态属性直接通过类名访问）和生命周期（实例属性随着实例的创建而存在，静态属性在类加载时就存在）上有明显区别。

<!-- @[instance_vs_static_properties](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Properties.ets) -->

``` TypeScript
class Configuration {
  // 实例属性：每个实例独立拥有
  public name: string;
  public value: number;
  
  // 静态属性：所有实例共享
  public static version: string = '1.0.0';
  public static instanceCount: number = 0;
  
  constructor(name: string, value: number) {
    this.name = name;
    this.value = value;
    Configuration.instanceCount++;
  }
  
  // 实例方法访问实例属性
  getInfo(): string {
    return `${this.name}: ${this.value}`;
  }
  
  // 静态方法访问静态属性
  static getVersion(): string {
    return Configuration.version;
  }
  
  static getInstanceCount(): number {
    return Configuration.instanceCount;
  }
}

let config1: Configuration = new Configuration('A', 10);
let config2: Configuration = new Configuration('B', 20);

// 实例属性独立
console.info(`${config1.name}`);  // 'A'
console.info(`${config2.name}`);  // 'B'

// 静态属性共享
console.info(`${Configuration.version}`);       // '1.0.0'
console.info(`${Configuration.instanceCount}`); // 2

// 实例通过this访问实例属性
// 静态通过类名访问静态属性
```

## 存储属性

存储属性在实例或类上分配字段保存数据值，分为实例存储属性与静态存储属性，是对象状态的主要载体。

### 实例存储属性的声明与初始化

实例存储属性是类中最基础的属性类型，直接存储对象的数据值，需要在声明或构造函数中完成初始化。

<!-- @[property_initialization_methods](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Properties.ets) -->

``` TypeScript
class User {
  // 声明时初始化
  public id: number = 0;
  public name: string = '';
  public active: boolean = true;
  
  // 构造函数中初始化
  constructor(id?: number, name?: string) {
    if (id !== undefined) {
      this.id = id;
    }
    if (name !== undefined) {
      this.name = name;
    }
  }
  
  // 延迟初始化
  public email: string | null = null;
  
  setEmail(email: string): void {
    this.email = email;  // 延迟赋值
  }
}

let user1: User = new User();
console.info(`${user1.id}`);    // 0
console.info(`${user1.name}`);  // ''

let user2: User = new User(1, 'Alice');
console.info(`${user2.id}`);    // 1
console.info(`${user2.name}`);  // 'Alice'

// 延迟初始化
user2.setEmail('alice@example.com');
console.info(`${user2.email}`);  // 'alice@example.com'
```

### 静态存储属性

静态存储属性使用static关键字声明，属于类本身而非实例，所有实例共享同一个静态属性值。

<!-- @[ts_static_storage_properties](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Properties.ts) -->

``` TypeScript
class Constants {
  // 静态存储属性
  public static readonly MAX_VALUE: number = 100;
  public static readonly MIN_VALUE: number = 0;
  public static DEFAULT_TIMEOUT: number = 5000;

  // 静态属性可修改
  public static counter: number = 0;

  static increment(): void {
    Constants.counter++;
  }
}

// 静态属性通过类名访问
console.info(`${Constants.MAX_VALUE}`);  // 100
console.info(`${Constants.MIN_VALUE}`);  // 0
console.info(`${Constants.DEFAULT_TIMEOUT}`);  // 5000

// 非只读静态属性可修改
Constants.increment();
console.info(`${Constants.counter}`);  // 1

// 实例无法访问静态属性
let constants: Constants = new Constants();
console.info(`${constants.MAX_VALUE}`);  // 编译错误
```

### 只读存储属性（readonly修饰符）

只读属性是不可修改的属性，确保属性在创建后保持不变，提高代码安全性。只读属性使用`readonly`修饰符声明，属性只能在声明时或构造函数中赋值，之后不可修改。

<!-- @[ts_readonly_instance_properties](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Properties.ts) -->

``` TypeScript
class ImmutablePoint {
  // readonly只读属性
  public readonly x: number;
  public readonly y: number;

  constructor(x: number, y: number) {
    this.x = x;  // 构造函数中可赋值
    this.y = y;
  }

  // 只读属性不可修改
  move(dx: number, dy: number): void {
    this.x += dx;  // 编译错误
    this.y += dy;  // 编译错误
  }

  // 返回新实例而非修改
  translate(dx: number, dy: number): ImmutablePoint {
    return new ImmutablePoint(this.x + dx, this.y + dy);
  }
}

let point: ImmutablePoint = new ImmutablePoint(10, 20);
console.info(`${point.x}`);  // 10
console.info(`${point.y}`);  // 20

// 只读属性不可修改
point.x = 15;  // 编译错误

// 返回新实例
let newPoint: ImmutablePoint = point.translate(5, 5);
console.info(`${newPoint.x}`);  // 15
console.info(`${newPoint.y}`);  // 25

// 原实例不变
console.info(`${point.x}`);  // 10
```

将`readonly`与`static`结合，可以定义类级别不可变的常量。

<!-- @[ts_static_readonly_constants](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Properties.ts) -->

``` TypeScript
// readonly与static结合
class AppConfig {
  public static readonly APP_NAME: string = 'MyApp';
  public static readonly VERSION: string = '1.0.0';
}

console.info(`${AppConfig.APP_NAME}`);   // 'MyApp'
console.info(`${AppConfig.VERSION}`);    // '1.0.0'

AppConfig.APP_NAME = 'NewApp';  // 编译错误
```

### 存储属性的访问控制

存储属性可通过 `public`、`private`、`protected` 修饰符限制可访问范围，三者均可与 `readonly` 组合使用。访问控制的详细说明和示例见[属性的访问控制](#属性的访问控制)章节。

<!-- @[ts_property_access_modifiers](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Properties.ts) -->

``` TypeScript
class BankAccount {
  // public：公开访问
  public accountNumber: string;

  // private：私有访问
  private balance: number;

  // protected：受保护访问
  protected ownerName: string;

  // readonly + private
  private readonly createdAt: Date;

  constructor(accountNumber: string, ownerName: string) {
    this.accountNumber = accountNumber;
    this.ownerName = ownerName;
    this.balance = 0;
    this.createdAt = new Date();
  }

  // 公开方法访问私有属性
  getBalance(): number {
    return this.balance;
  }

  deposit(amount: number): void {
    if (amount > 0) {
      this.balance += amount;
    }
  }

  withdraw(amount: number): boolean {
    if (amount > 0 && this.balance >= amount) {
      this.balance -= amount;
      return true;
    }
    return false;
  }

  // protected方法
  protected setOwnerName(name: string): void {
    this.ownerName = name;
  }
}

let account: BankAccount = new BankAccount('ACC-001', 'Alice');

// public可访问
console.info(`${account.accountNumber}`);  // 'ACC-001'

// private不可访问
console.info(`${account.balance}`);  // 编译错误

// protected不可访问
console.info(`${account.ownerName}`);  // 编译错误

// 通过公开方法访问私有属性
account.deposit(100);
console.info(`${account.getBalance()}`);  // 100

// 子类访问protected属性
class PremiumAccount extends BankAccount {
  updateOwner(newOwner: string): void {
    this.setOwnerName(newOwner);  // 子类可访问protected方法
  }
}
```

## 计算属性

计算属性通过getter和setter控制属性的读取和赋值逻辑。

### getter/setter的概念与作用

getter和setter是计算属性的访问器，用于控制属性的读取和写入行为，也是实现计算属性的核心语法。

### 计算属性的语法（get/set访问器）

使用`get`关键字定义读取访问器，`set`关键字定义写入访问器，访问时像普通属性一样使用，但底层通过方法动态求值。

<!-- @[getter_setter_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Properties.ets) -->

``` TypeScript
class Circle {
  private _radius: number = 0;
  
  // getter：获取计算值
  get radius(): number {
    return this._radius;
  }
  
  // setter：设置值并验证
  set radius(value: number) {
    if (value >= 0) {
      this._radius = value;
    }
  }
  
  // 计算属性：基于其他属性计算
  get area(): number {
    return Math.PI * this._radius * this._radius;
  }
  
  get diameter(): number {
    return this._radius * 2;
  }
  
  get circumference(): number {
    return 2 * Math.PI * this._radius;
  }
}

let circle: Circle = new Circle();

// 通过setter设置
circle.radius = 5;
console.info(`${circle.radius}`);      // 5

// 计算属性自动更新
console.info(`${circle.area}`);        // ~78.54
console.info(`${circle.diameter}`);    // 10
console.info(`${circle.circumference}`); // ~31.42

// setter有验证逻辑
circle.radius = -5;  // 无效，不设置
console.info(`${circle.radius}`);      // 5（保持原值）
```

### 只读计算属性（仅get方法）

只读计算属性只提供getter方法，没有setter方法，属性只能读取不能写入，提供安全的属性访问。

<!-- @[ts_readonly_computed_properties](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Properties.ts) -->

``` TypeScript
class Rectangle {
  public width: number = 0;
  public height: number = 0;

  // 只读计算属性：仅有getter
  get area(): number {
    return this.width * this.height;
  }

  get perimeter(): number {
    return 2 * (this.width + this.height);
  }

  // 无setter，不可直接设置area
  // set area(value: number) { }  // 不提供
}

let rect: Rectangle = new Rectangle();
rect.width = 10;
rect.height = 20;

console.info(`${rect.area}`);       // 200
console.info(`${rect.perimeter}`);  // 60

// 不可设置计算属性
rect.area = 100;  // 编译错误

// 通过修改源属性影响计算属性
rect.width = 5;
console.info(`${rect.area}`);  // 100（自动更新）
```

### 计算属性与存储属性的区别

存储属性分配字段保存值，计算属性不分配字段，每次访问时通过getter动态求值；计算属性适合派生数据（如全名由姓+名拼接）。

<!-- @[stored_vs_computed_properties](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Properties.ets) -->

``` TypeScript
class Temperature {
  // 存储属性：直接存储值
  public celsius: number = 0;
  
  // 计算属性：基于存储属性计算
  get fahrenheit(): number {
    return this.celsius * 9 / 5 + 32;
  }
  
  set fahrenheit(value: number) {
    this.celsius = (value - 32) * 5 / 9;
  }
  
  // 存储属性：需要存储空间
  // 计算属性：无需存储空间，动态计算
  
  // 存储属性：直接赋值
  // 计算属性：通过getter/setter
}

let temp: Temperature = new Temperature();

// 设置存储属性
temp.celsius = 25;
console.info(`${temp.celsius}`);      // 25
console.info(`${temp.fahrenheit}`);   // 77

// 设置计算属性，影响存储属性
temp.fahrenheit = 100;
console.info(`${temp.celsius}`);      // ~37.78
console.info(`${temp.fahrenheit}`);   // 100
```

### 计算属性的使用场景

计算属性有多种典型使用场景，例如数据组合、格式转换、验证控制和派生计算。

<!-- @[computed_property_combination](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Properties.ets) -->

``` TypeScript
class ComboUser {
  public firstName: string = '';
  public lastName: string = '';
  
  // 计算属性：组合多个属性
  get fullName(): string {
    return `${this.firstName} ${this.lastName}`;
  }
  
  set fullName(value: string) {
    let parts: string[] = value.split(' ');
    this.firstName = parts[0] ?? '';
    this.lastName = parts[1] ?? '';
  }
}

let user: ComboUser = new ComboUser();
user.firstName = 'John';
user.lastName = 'Doe';

console.info(`${user.fullName}`);  // 'John Doe'

user.fullName = 'Jane Smith';
console.info(`${user.firstName}`);  // 'Jane'
console.info(`${user.lastName}`);   // 'Smith'

// 计算属性用于验证和转换
class Product {
  public price: number = 0;
  
  get formattedPrice(): string {
    return '$' + this.price.toFixed(2);
  }
  
  get priceInCents(): number {
    return Math.round(this.price * 100);
  }
}

let product: Product = new Product();
product.price = 19.99;

console.info(`${product.formattedPrice}`);  // '$19.99'
console.info(`${product.priceInCents}`);    // 1999
```

## 属性观察器（模拟实现）

属性观察器监控属性变化，在设置前后执行自定义逻辑。

### TypeScript中模拟属性监听的方案

TypeScript/ArkTS没有原生属性观察器，需通过在getter/setter中比较新旧值并触发监听器来模拟属性变化监听。

<!-- @[property_observer_simulation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Properties.ets) -->

``` TypeScript
// TypeScript/ArkTS无原生属性观察器
// 通过getter/setter模拟

class ObservableValue {
  private _value: number = 0;
  private _listeners: ((value: number) => void)[] = [];
  
  get value(): number {
    return this._value;
  }
  
  set value(newValue: number) {
    let oldValue: number = this._value;
    this._value = newValue;
    
    // 触发监听器
    if (oldValue !== newValue) {
      this.notifyListeners(newValue);
    }
  }
  
  // 添加监听器
  addListener(listener: (value: number) => void): void {
    this._listeners.push(listener);
  }
  
  // 移除监听器
  removeListener(listener: (value: number) => void): void {
    let index: number = this._listeners.indexOf(listener);
    if (index >= 0) {
      this._listeners.splice(index, 1);
    }
  }
  
  // 通知所有监听器
  private notifyListeners(value: number): void {
    for (let listener of this._listeners) {
      listener(value);
    }
  }
}

let observable: ObservableValue = new ObservableValue();

// 添加监听器
observable.addListener((value: number): void => {
  console.info(`Value changed to ${value}`);
});

// 设置值，触发监听器
observable.value = 10;  // 输出: Value changed to 10
observable.value = 20;  // 输出: Value changed to 20
observable.value = 20;  // 不输出（值相同）
```

### 基于get/set实现属性变更检测

在setter中比较新旧值，仅在值变化时执行自定义逻辑（如日志、通知），实现属性变更的按需检测。

<!-- @[property_change_detection](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Properties.ets) -->

``` TypeScript
class WatchedProperty {
  private _data: string = '';
  
  get data(): string {
    return this._data;
  }
  
  set data(value: string) {
    if (this._data !== value) {
      console.info(`Property changed from '${this._data}' to '${value}'`);
      this._data = value;
    }
  }
  
  // 手动触发变更检测
  checkChange(): void {
    console.info(`Current value: ${this._data}`);
  }
}

let watched: WatchedProperty = new WatchedProperty();
watched.data = 'Hello';  // 输出: Property changed from '' to 'Hello'
watched.data = 'Hello';  // 不输出（值相同）
watched.data = 'World';  // 输出: Property changed from 'Hello' to 'World'

// 批量更新时触发
class BatchUpdate {
  private _items: string[] = [];
  
  get items(): string[] {
    return [...this._items];  // 返回副本
  }
  
  set items(value: string[]) {
    let oldLength: number = this._items.length;
    this._items = [...value];
    
    if (oldLength !== this._items.length) {
      console.info(`Items count changed from ${oldLength} to ${this._items.length}`);
    }
  }
  
  addItem(item: string): void {
    this._items.push(item);
    console.info(`Added item: ${item}`);
  }
}
```

### 基于装饰器（Decorator）实现属性观察

ArkTS的装饰器体系与TypeScript实验性装饰器不同，属性观察不使用装饰器包装`get`/`set`描述符，而是通过手动实现观察者模式：在`set`方法中比较新旧值并触发回调。详见[装饰器](arkts-language-guide-classes.md#装饰器)。

<!-- @[manual_property_observation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Properties.ets) -->

``` TypeScript
// 属性观察者：在set方法中比较新旧值并触发回调

class PropertyObserver {
  private propertyName: string;
  private callback: (oldValue: string | number | boolean, newValue: string | number | boolean) => void;
  
  constructor(
    propertyName: string,
    callback: (oldValue: string | number | boolean, newValue: string | number | boolean) => void
  ) {
    this.propertyName = propertyName;
    this.callback = callback;
  }
  
  notify(oldValue: string | number | boolean, newValue: string | number | boolean): void {
    if (oldValue !== newValue) {
      this.callback(oldValue, newValue);
    }
  }
}

class ObservedClass {
  private _value: number = 0;
  private observer: PropertyObserver;
  
  constructor() {
    this.observer = new PropertyObserver('value', 
      (oldValue: string | number | boolean, newValue: string | number | boolean): void => {
        console.info(`Value: ${oldValue} -> ${newValue}`);
      }
    );
  }
  
  get value(): number {
    return this._value;
  }
  
  set value(newValue: number) {
    let oldValue: number = this._value;
    this._value = newValue;
    this.observer.notify(oldValue, newValue);
  }
}

let observed: ObservedClass = new ObservedClass();
observed.value = 10;  // 输出: Value: 0 -> 10
observed.value = 20;  // 输出: Value: 10 -> 20
```

## 静态属性与实例属性的对比

静态属性与实例属性的区别见[实例属性与静态属性的区别](#实例属性与静态属性的区别)章节。以下通过对比示例进一步展示两者在共享和独立方面的差异。

### 静态属性与实例属性的对比示例

静态属性通过类名访问，所有实例共享同一份；实例属性通过实例访问，每个实例独立持有。

<!-- @[instance_static_comparison](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Properties.ets) -->

``` TypeScript
class Comparison {
  // 实例属性
  public instanceValue: number = 0;
  
  // 静态属性
  public static staticValue: number = 0;
  
  // 实例方法
  getInstanceValue(): number {
    return this.instanceValue;  // 通过this
  }
  
  setInstanceValue(value: number): void {
    this.instanceValue = value;
  }
  
  // 静态方法
  static getStaticValue(): number {
    return Comparison.staticValue;  // 通过类名
  }
  
  static setStaticValue(value: number): void {
    Comparison.staticValue = value;
  }
  
  // 混合使用
  static compare(): string {
    return `Static: ${Comparison.staticValue}, Instance: N/A in static`;
  }
  
  getComparison(): string {
    return `Static: ${Comparison.staticValue}, Instance: ${this.instanceValue}`;
  }
}

let comp1: Comparison = new Comparison();
let comp2: Comparison = new Comparison();

// 实例属性独立
comp1.setInstanceValue(10);
comp2.setInstanceValue(20);

console.info(`${comp1.getInstanceValue()}`);   // 10
console.info(`${comp2.getInstanceValue()}`);   // 20

// 静态属性共享
Comparison.setStaticValue(100);
console.info(`${Comparison.getStaticValue()}`);  // 100

// 所有实例看到相同的静态属性
console.info(`${comp1.getComparison()}`);  // Static: 100, Instance: 10
console.info(`${comp2.getComparison()}`);  // Static: 100, Instance: 20
```

### 静态属性的访问方式（类名直接访问）

静态属性通过`类名.属性名`直接访问，无需创建实例，实例对象无法访问静态属性。

<!-- @[ts_static_constants_class](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Properties.ts) -->

``` TypeScript
class MathConstants {
  public static readonly PI: number = 3.14159;
  public static readonly E: number = 2.71828;
  public static readonly GOLDEN_RATIO: number = 1.61803;

  static calculateCircleArea(radius: number): number {
    return MathConstants.PI * radius * radius;
  }

  static calculateCircleCircumference(radius: number): number {
    return 2 * MathConstants.PI * radius;
  }
}

// 静态属性通过类名访问
console.info(`${MathConstants.PI}`);                      // 3.14159
console.info(`${MathConstants.E}`);                       // 2.71828
console.info(`${MathConstants.GOLDEN_RATIO}`);            // 1.61803

// 静态方法使用静态属性
let area: number = MathConstants.calculateCircleArea(5);
console.info(`${area}`);  // ~78.54

// 实例无法访问静态属性
let mathConstants: MathConstants = new MathConstants();
console.info(`${mathConstants.PI}`);  // 编译错误
```

### 实例属性的访问方式（实例对象访问）

实例属性通过`实例对象.属性名`访问，每个实例拥有独立的属性副本，类名无法直接访问实例属性。

<!-- @[ts_instance_property_independence](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Properties.ts) -->

``` TypeScript
class Student {
  public name: string;
  public age: number;
  public grade: string;

  constructor(name: string, age: number, grade: string) {
    this.name = name;
    this.age = age;
    this.grade = grade;
  }

  // 实例方法访问实例属性
  getInfo(): string {
    return `${this.name}, ${this.age} years old, grade ${this.grade}`;
  }

  // 实例方法修改实例属性
  setGrade(newGrade: string): void {
    this.grade = newGrade;
  }
}

let student1: Student = new Student('Alice', 15, 'A');
let student2: Student = new Student('Bob', 16, 'B');

// 实例属性通过实例访问
console.info(`${student1.name}`);   // 'Alice'
console.info(`${student2.name}`);   // 'Bob'

// 实例属性独立
student1.setGrade('A+');
console.info(`${student1.grade}`);  // 'A+'
console.info(`${student2.grade}`);  // 'B'（不受影响）

// 类名无法访问实例属性
console.info(`${Student.grade}`);  // 编译错误：实例属性无法通过类名访问
```

### 静态属性的生命周期（与类绑定）

静态属性在类加载时创建，所有实例共享，适合全局状态管理。

<!-- @[application_state_management](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Properties.ets) -->

``` TypeScript
class ApplicationState {
  public static startTime: Date = new Date();
  public static userCount: number = 0;
  public static sessionActive: boolean = false;
  
  static initialize(): void {
    ApplicationState.startTime = new Date();
    ApplicationState.userCount = 0;
    ApplicationState.sessionActive = true;
    console.info(`Application initialized at ${ApplicationState.startTime.toString()}`);
  }
  
  static addUser(): void {
    ApplicationState.userCount++;
    console.info(`User count: ${ApplicationState.userCount}`);
  }
  
  static getElapsedTime(): number {
    let now: Date = new Date();
    return now.getTime() - ApplicationState.startTime.getTime();
  }
  
  static shutdown(): void {
    ApplicationState.sessionActive = false;
    console.info('Application shutdown');
  }
}

// 静态属性随类加载而初始化
console.info(`${ApplicationState.startTime}`);       // 初始化时间
console.info(`${ApplicationState.sessionActive}`);   // false

// 应用启动
ApplicationState.initialize();
ApplicationState.addUser();  // User count: 1
ApplicationState.addUser();  // User count: 2

console.info(`${ApplicationState.getElapsedTime()}`);  // 运行时间

// 静态属性全局共享
// 无论创建多少实例，静态属性只有一个副本
```

## 属性的访问控制

`public`、`private`、`protected` 控制访问范围，`readonly` 控制可写性，二者正交组合覆盖常见封装需求，如 `public readonly` 表示外部只读、`private readonly` 表示内部只读。

### 属性访问控制示例

readonly可与访问修饰符组合使用，如`public readonly`表示外部只读、`private readonly`表示内部只读。

<!-- @[ts_access_modifier_combination](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Properties.ts) -->

``` TypeScript
class SecureData {
  // public：完全公开
  public id: number;

  // private：仅类内部
  private secretKey: string;

  // protected：类及子类
  protected internalData: string;

  // readonly：只读
  public readonly createdAt: Date;

  // 组合修饰符
  private readonly immutableSecret: string;
  protected readonly protectedReadOnly: string;

  constructor(id: number, secret: string) {
    this.id = id;
    this.secretKey = secret;
    this.internalData = 'internal';
    this.createdAt = new Date();
    this.immutableSecret = secret;
    this.protectedReadOnly = 'protected';
  }

  // 公开访问私有属性的方法
  getSecretKey(): string {
    return this.secretKey;
  }

  // 验证后修改私有属性
  updateSecretKey(newKey: string, token: string): boolean {
    if (token === 'valid') {
      this.secretKey = newKey;
      return true;
    }
    return false;
  }

  // protected方法
  protected getInternalData(): string {
    return this.internalData;
  }
}

let secure: SecureData = new SecureData(1, 'secret123');

// public可访问
console.info(`${secure.id}`);         // 1

// private不可直接访问
console.info(`${secure.secretKey}`);  // 编译错误

// 通过公开方法访问
console.info(`${secure.getSecretKey()}`);  // 'secret123'

// protected不可直接访问
console.info(`${secure.internalData}`);  // 编译错误

// readonly可读不可写
console.info(`${secure.createdAt}`);
secure.createdAt = new Date();  // 编译错误

// 子类访问protected属性
class ExtendedSecure extends SecureData {
  getProtectedData(): string {
    return this.getInternalData();  // 可访问protected方法
  }

  getProtectedProperty(): string {
    return this.protectedReadOnly;  // 可访问protected属性
  }
}
```

## 继承中的属性

子类自动继承父类的public和protected属性，private属性不可继承，子类可重写父类属性。

### 继承中的属性示例

子类自动继承父类的 `public` 和 `protected` 属性，`private` 属性不可继承；子类可声明同名属性隐藏父类属性，但无法改变父类成员的访问级别。

<!-- @[ts_property_inheritance](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Properties.ts) -->

``` TypeScript
class Parent {
  public publicProp: string = 'public';
  protected protectedProp: string = 'protected';
  private privateProp: string = 'private';

  getPrivateProp(): string {
    return this.privateProp;
  }
}

class Child extends Parent {
  // 新增属性
  public childProp: string = 'child';

  // 继承public属性
  getPublicFromParent(): string {
    return this.publicProp;  // 可访问
  }

  // 继承protected属性
  getProtectedFromParent(): string {
    return this.protectedProp;  // 可访问
  }

  // 无法继承private属性
  getPrivateFromParent(): string {
    return this.privateProp;  // 编译错误
  }

  // 通过父类公开方法访问私有属性
  getParentPrivate(): string {
    return this.getPrivateProp();  // 可访问
  }

  // 重写父类属性（隐藏）
  public publicProp: string = 'child override';

  testOverride(): void {
    console.info(`${this.publicProp}`);  // 'child override'
  }
}

let child: Child = new Child();

console.info(`${child.publicProp}`);           // 'child override'
console.info(`${child.getProtectedFromParent()}`); // 'protected'（继承）
console.info(`${child.childProp}`);            // 'child'
console.info(`${child.getParentPrivate()}`);   // 'private'

// 属性继承总结：
// public：完全继承，可重写
// protected：继承，子类可访问
// private：不继承，子类不可直接访问
```

## 索引签名

ArkTS不支持索引签名（`arkts-no-indexed-signatures`）和索引访问字段（`arkts-no-props-by-index`），详见[从TypeScript到ArkTS的适配规则](typescript-to-arkts-migration-guide.md#不支持index-signature)，使用`Map`替代。

**TypeScript对照**

<!-- @[ts_index_signature_in_class](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Properties.ts) -->

``` TypeScript
class TsIsStringBooleanMap {
  [key: string]: boolean | ((s: string) => boolean);

  check(s: string): boolean {
    return (this[s] as boolean);
  }
}

let tsIsMap: TsIsStringBooleanMap = new TsIsStringBooleanMap();
tsIsMap['isActive'] = true;
tsIsMap['isDeleted'] = false;

console.info(`${tsIsMap['isActive']}`);   // true
console.info(`${tsIsMap['isDeleted']}`);  // false
```

ArkTS中使用`Map`替代类上的索引签名。

<!-- @[index_signature_map_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Properties.ets) -->

``` TypeScript
class IsConfigManager {
  private values: Map<string, string> = new Map<string, string>();

  set(key: string, value: string): void {
    this.values.set(key, value);
  }

  get(key: string): string | undefined {
    return this.values.get(key);
  }
}

let isConfig: IsConfigManager = new IsConfigManager();
isConfig.set('appName', 'MyApp');

let isAppName: string | undefined = isConfig.get('appName');
if (isAppName !== undefined) {
  console.info(`${isAppName}`);  // MyApp
}
```

## declare仅类型字段声明

子类中重新声明继承字段的更精确类型时，使用`declare`避免运行时覆盖父类值。若不使用`declare`，子类字段的初始化器会在构造时执行，覆盖父类构造函数已设置的值，可能导致数据丢失或类型不一致。

<!-- @[declare_field](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Properties.ets) -->

``` TypeScript
interface DclAnimal {
  dateOfBirth: Date;
}

interface DclDog extends DclAnimal {
  breed: string;
}

class DclAnimalHouse {
  public resident: DclAnimal;

  constructor(animal: DclAnimal) {
    this.resident = animal;
  }
}

class DclDogHouse extends DclAnimalHouse {
  // declare：不生成运行时代码，仅修正类型
  public declare resident: DclDog;

  constructor(dog: DclDog) {
    super(dog);
  }
}

let dclDog: DclDog = { dateOfBirth: new Date(), breed: 'Labrador' };
let dclHouse: DclDogHouse = new DclDogHouse(dclDog);
console.info(`${dclHouse.resident.breed}`);  // Labrador
```

`declare`字段不会生成运行时代码，只用于确保类型正确。不加`declare`时，子类字段初始化会在父类构造函数之后覆盖父类的值。
