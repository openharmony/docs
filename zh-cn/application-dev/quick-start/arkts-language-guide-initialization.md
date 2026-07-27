# 初始化
<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

ArkTS通过构造函数、属性初始化器、静态初始化块等机制在对象创建时设置初始状态，确保对象创建后处于可用状态。

## 初始化的基础概念

初始化在对象创建时设置属性的初始值，通过构造函数和默认值确保对象处于可用状态，是类型安全的第一道保障。

### 初始化的定义与作用

初始化通过默认值、构造函数、初始化顺序和静态初始化等机制，在对象创建时为属性设置有效初值。

<!-- @[basic_constructor_initialization](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
class Person {
  public name: string;
  public age: number;
  
  // 构造函数：初始化作用
  constructor(name: string, age: number) {
    this.name = name;  // 初始化name属性
    this.age = age;    // 初始化age属性
  }
  
  getInfo(): string {
    return `${this.name}, ${this.age} years old`;
  }
}

let person: Person = new Person('Alice', 25);
console.info(`${person.getInfo()}`);  // 'Alice, 25 years old'
```

初始化的作用包括设置对象初始状态、分配并初始化属性、准备使用所需资源以及验证初始参数有效性。

### 构造函数的概念与核心职责

构造函数是类的特殊方法，用于初始化对象，是对象生命周期的重要组成部分。

``` TypeScript
class ClassName {
  constructor(parameters) {
    // 初始化代码
  }
}
```
<!-- @[constructor_responsibilities](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
class DatabaseConnection {
  private connection: string;
  private connected: boolean;
  private timeout: number;
  
  // 构造函数职责
  constructor(connectionString: string, timeout: number = 5000) {
    // 1. 属性初始化
    this.connection = connectionString;
    this.timeout = timeout;
    this.connected = false;
    
    // 2. 参数验证
    if (connectionString.length === 0) {
      throw new Error('Connection string cannot be empty');
    }
    
    // 3. 资源准备
    this.prepareConnection();
  }
  
  private prepareConnection(): void {
    console.info('Preparing connection resources');
  }
  
  connect(): void {
    this.connected = true;
    console.info(`Connected to ${this.connection}`);
  }
  
  disconnect(): void {
    this.connected = false;
    console.info('Disconnected');
  }
}

let db: DatabaseConnection = new DatabaseConnection('localhost:5432', 3000);
db.connect();
```

构造函数职责总结：构造函数负责初始化所有属性、验证参数有效性、准备必要资源并设置初始状态。

### 属性初始化的时机与方式

属性初始化的时机有三种：声明时赋值（`public name = 'default'`）、构造函数体内赋值、延迟赋值（可选属性通过`?`标记后在使用前赋值）。选择时机取决于值的来源——固定默认值在声明时赋值，动态值在构造函数中赋值，运行时确定的值用可选属性延迟赋值。

### 实例创建与初始化的关联流程

`new`创建实例时依次执行：字段默认值初始化、构造函数体内赋值，最终对象所有属性处于有效状态。

<!-- @[initialization_flow](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
class Order {
  public id: number;
  public items: string[];
  public total: number;
  public status: string;
  public createdAt: Date;
  
  constructor(id: number) {
    // 初始化流程：
    
    // 1. 属性初始化
    this.id = id;
    this.items = [];
    this.total = 0;
    this.status = 'pending';
    
    // 2. 计算初始值
    this.createdAt = new Date();
    
    // 3. 验证初始状态
    if (id <= 0) {
      throw new Error('Invalid order ID');
    }
    
    console.info(`Order ${this.id} created`);
  }
  
  addItem(item: string, price: number): void {
    this.items.push(item);
    this.total += price;
    this.status = 'processing';
  }
  
  complete(): void {
    this.status = 'completed';
    console.info(`Order ${this.id} completed with total ${this.total}`);
  }
}

// 创建流程：
// new Order(1) -> 构造函数调用 -> 属性初始化 -> 状态设置 -> 实例返回
let order: Order = new Order(1);
order.addItem('Item A', 100);
order.addItem('Item B', 200);
order.complete();
```

## 构造函数的声明与使用

构造函数通过`constructor`关键字声明，在`new`创建实例时自动调用，用于初始化属性和设置初始状态。

### 默认值的作用与使用场景

在属性声明或构造函数参数上直接赋予初始值，当创建实例或调用函数未提供该值时使用预设值，避免undefined。

### 默认构造函数（无参构造）

默认构造函数是无参数的构造函数，在未定义构造函数时编译器自动生成。

<!-- @[default_constructor](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
class SimpleClass {
  public value: number = 10;
  public name: string = 'default';
  
  // 无构造函数：编译器自动生成默认构造函数
  // constructor() {}  // 自动生成
}

let simple: SimpleClass = new SimpleClass();
console.info(`${simple.value.toString()}`);  // 10
console.info(`${simple.name}`);   // 'default'

class DefaultConstructor {
  public x: number = 0;
  public y: number = 0;
  
  // 显式无参构造函数
  constructor() {
    console.info('Default constructor called');
  }
  
  getValues(): string {
    return `${this.x}, ${this.y}`;
  }
}

let defaultObj: DefaultConstructor = new DefaultConstructor();
console.info(`${defaultObj.getValues()}`);  // '0, 0'

// 默认构造函数：
// 无参数
// 自动初始化属性为默认值
// 编译器自动生成（如果未定义）
```

### 自定义构造函数（带参数构造）

自定义构造函数是带参数的构造函数，通过参数接收初始值进行初始化。

<!-- @[custom_constructor_with_parameters](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
class Point {
  public x: number;
  public y: number;
  
  constructor(x: number, y: number) {
    this.x = x;
    this.y = y;
  }
  
  getCoordinates(): string {
    return `${this.x}, ${this.y}`;
  }
}

let point: Point = new Point(10, 20);
console.info(`${point.getCoordinates()}`);  // '10, 20'

class User {
  public id: number;
  public name: string;
  public email: string;
  
  constructor(id: number, name: string, email: string) {
    this.id = id;
    this.name = name;
    this.email = email;
  }
  
  validate(): boolean {
    return this.id > 0 && this.name.length > 0;
  }
}

let user: User = new User(1, 'Alice', 'alice@example.com');
console.info(`${user.validate()}`);  // true

// 自定义构造函数：
// 定义参数接收初始值
// 参数赋值给属性
// 可添加验证逻辑
```

### 构造函数的访问控制（public/private等修饰符）

通过public/private/protected修饰构造函数控制实例化权限：private构造函数常用于单例模式，protected用于只允许子类实例化。

<!-- @[constructor_access_modifiers](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
class PublicConstructor {
  public value: number;
  
  // public构造函数（默认）
  public constructor(value: number) {
    this.value = value;
  }
}

let publicObj: PublicConstructor = new PublicConstructor(10);

class PrivateConstructor {
  private static instance: PrivateConstructor;
  
  // private构造函数：单例模式
  private constructor() {
    console.info('Private constructor');
  }
  
  static getInstance(): PrivateConstructor {
    if (PrivateConstructor.instance === undefined) {
      PrivateConstructor.instance = new PrivateConstructor();
    }
    return PrivateConstructor.instance;
  }
}

let singleton: PrivateConstructor = PrivateConstructor.getInstance();

class ProtectedConstructor {
  protected value: number;
  
  // protected构造函数：子类可访问
  protected constructor(value: number) {
    this.value = value;
  }
}

class ChildOfProtected extends ProtectedConstructor {
  public constructor(value: number) {
    super(value);  // 子类可调用protected构造函数
  }
}

let child: ChildOfProtected = new ChildOfProtected(20);
```

### 实例化对象的语法

使用`new`关键字调用构造函数完成实例化：分配内存→调用构造函数初始化属性→返回实例引用。

<!-- @[instantiation_with_new_keyword](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
class Product {
  public id: number;
  public name: string;
  
  constructor(id: number, name: string) {
    this.id = id;
    this.name = name;
  }
}

// new关键字实例化
let product1: Product = new Product(1, 'Product A');
let product2: Product = new Product(2, 'Product B');

console.info(`${product1.name}`);  // 'Product A'
console.info(`${product2.name}`);  // 'Product B'

// 实例化过程：
// 1. new关键字创建对象
// 2. 调用构造函数
// 3. 返回新实例

class ComplexObject {
  public data: Map<string, string>;
  
  constructor() {
    this.data = new Map();
    this.data.set('key', 'value');
  }
  
  getData(): Map<string, string> {
    return this.data;
  }
}

let complex: ComplexObject = new ComplexObject();
console.info(`${complex.getData().get('key')}`);  // 'value'
```

## 构造函数的重载

构造函数重载支持多种初始化方式，灵活创建对象。

### 构造器重载的声明规则（同名不同参）

通过声明多个参数列表不同的构造函数签名，使对象可以按不同的参数组合初始化，编译器根据传入参数自动匹配对应签名。

<!-- @[constructor_overloading](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
class OverloadPoint {
  public x: number;
  public y: number;
  
  // 构造函数重载签名
  constructor();
  constructor(x: number);
  constructor(x: number, y: number);
  constructor(x?: number, y?: number) {
    this.x = x ?? 0;
    this.y = y ?? 0;
  }
}

let point1: OverloadPoint = new OverloadPoint();
let point2: OverloadPoint = new OverloadPoint(10);
let point3: OverloadPoint = new OverloadPoint(10, 20);

console.info(`${point1.x} ${point1.y}`);  // 0, 0
console.info(`${point2.x} ${point2.y}`);  // 10, 0
console.info(`${point3.x} ${point3.y}`);  // 10, 20

class Color {
  public red: number;
  public green: number;
  public blue: number;
  
  constructor(hex: string);
  constructor(r: number, g: number, b: number);
  constructor(rOrHex: number | string, g?: number, b?: number) {
    if (typeof rOrHex === 'string') {
      // 从十六进制解析
      this.red = Number.parseInt(rOrHex.substring(1, 3), 16);
      this.green = Number.parseInt(rOrHex.substring(3, 5), 16);
      this.blue = Number.parseInt(rOrHex.substring(5, 7), 16);
    } else {
      this.red = rOrHex;
      this.green = g ?? 0;
      this.blue = b ?? 0;
    }
  }
}

let color1: Color = new Color('#FF0000');
let color2: Color = new Color(255, 128, 0);
```

### 重载构造函数的调用方式

根据传入参数的数量和类型，编译器自动匹配最合适的构造函数签名，调用对应的初始化逻辑。

<!-- @[overload_call_selection](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
class Size {
  public width: number;
  public height: number;
  
  constructor();
  constructor(size: number);
  constructor(width: number, height: number);
  constructor(width?: number, height?: number) {
    if (width === undefined) {
      this.width = 100;
      this.height = 100;
    } else if (height === undefined) {
      this.width = width;
      this.height = width;
    } else {
      this.width = width;
      this.height = height;
    }
  }
  
  getArea(): number {
    return this.width * this.height;
  }
}

let size1: Size = new Size();         // 100x100
let size2: Size = new Size(50);       // 50x50
let size3: Size = new Size(10, 20);   // 10x20

console.info(`${size1.getArea()}`);  // 10000
console.info(`${size2.getArea()}`);  // 2500
console.info(`${size3.getArea()}`);  // 200
```

### 构造器重载的使用场景

构造函数重载的使用场景包括提供默认值初始化、部分参数初始化和全参数初始化等方式，根据参数类型和数量设计具有明确命名和逻辑层次的重载方案。

<!-- @[static_factory_methods_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
// 使用场景：多种初始化方式
class Configuration {
  public apiUrl: string;
  public timeout: number;
  public debug: boolean;
  
  constructor();
  constructor(apiUrl: string);
  constructor(apiUrl: string, timeout: number);
  constructor(apiUrl: string, timeout: number, debug: boolean);
  constructor(apiUrl?: string, timeout?: number, debug?: boolean) {
    this.apiUrl = apiUrl ?? 'EXAMPLE_API_URL';
    this.timeout = timeout ?? 5000;
    this.debug = debug ?? false;
  }
}

let config1: Configuration = new Configuration();
let config2: Configuration = new Configuration('EXAMPLE_API_URL');
let config3: Configuration = new Configuration('EXAMPLE_API_URL', 3000);
let config4: Configuration = new Configuration('EXAMPLE_API_URL', 3000, true);

// 使用静态工厂方法替代复杂重载
class ConfigFactory {
  public apiUrl: string;
  public timeout: number;
  
  private constructor(apiUrl: string, timeout: number) {
    this.apiUrl = apiUrl;
    this.timeout = timeout;
  }
  
  static createDefault(): ConfigFactory {
    return new ConfigFactory('EXAMPLE_API_URL', 5000);
  }
  
  static createWithUrl(apiUrl: string): ConfigFactory {
    return new ConfigFactory(apiUrl, 5000);
  }
  
  static createCustom(apiUrl: string, timeout: number): ConfigFactory {
    return new ConfigFactory(apiUrl, timeout);
  }
}

let defaultConfig: ConfigFactory = ConfigFactory.createDefault();
let urlConfig: ConfigFactory = ConfigFactory.createWithUrl('EXAMPLE_API_URL');
let customConfig: ConfigFactory = ConfigFactory.createCustom('EXAMPLE_API_URL', 3000);
```

## 继承中的构造函数

子类构造函数必须先通过`super()`调用父类构造函数完成父类部分初始化，再初始化子类自身属性。

### 子类构造函数的默认行为

当子类构造函数未显式调用父类构造函数时，编译器会自动生成调用父类无参构造函数的代码。

<!-- @[inheriting_parent_constructor](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
class Parent {
  public value: number;
  
  constructor(value: number) {
    this.value = value;
  }
}

class Child extends Parent {
  // 子类无构造函数：自动继承父类构造函数
  // 编译器生成：
  // constructor(value: number) {
  //   super(value);
  // }
  
  getValue(): number {
    return this.value;
  }
}

let ctorChild: Child = new Child(10);
console.info(`${ctorChild.getValue().toString()}`);  // 10

class EmptyParent {
  public name: string = 'parent';
  
  // 无参数构造函数
  constructor() {
    console.info('Parent constructor');
  }
}

class EmptyChild extends EmptyParent {
  // 自动调用父类无参构造函数
  public age: number = 20;
}

let emptyChild: EmptyChild = new EmptyChild();
```

### super() 调用父类构造函数的规则

子类构造函数必须通过`super()`调用父类构造函数，且`super()`必须是构造函数体的第一条语句，在`this`访问之前执行。

<!-- @[ts_super_call_rules](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Initialization.ts) -->

``` TypeScript
class Vehicle {
  public brand: string;

  constructor(brand: string) {
    this.brand = brand;
    console.info(`Vehicle constructor`);
  }
}

class Car extends Vehicle {
  public model: string;

  constructor(brand: string, model: string) {
    super(brand);  // 必须先调用super()
    this.model = model;
    console.info(`Car constructor`);
  }

  getInfo(): string {
    return `${this.brand} ${this.model}`;
  }
}

let car: Car = new Car('Toyota', 'Camry');
// 输出：'Vehicle constructor', 'Car constructor'

// super() 规则：
// 1. 子类构造函数必须调用super()
// 2. super() 必须在第一行
// 3. super() 参数匹配父类构造函数

class InvalidChild extends Vehicle {
  public model: string;

  constructor(brand: string, model: string) {
    this.model = model;  // 编译错误：super() 未调用

    super(brand);  // 必须在访问this之前

    this.model = model;  // 正确
  }
}
```

### 必须调用super() 的场景与时机

当父类定义了构造函数时，子类构造函数必须显式调用`super()`且必须在使用`this`之前执行。

<!-- @[ts_super_call_scenarios](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Initialization.ts) -->

``` TypeScript
// 必须调用super() 的场景：

// 1. 父类有构造函数（无论是否有参数）
class RequiredParent {
  public name: string;

  constructor(name: string) {
    this.name = name;
  }
}

class RequiredChild extends RequiredParent {
  public age: number;

  constructor(name: string, age: number) {
    super(name);  // 必须
    this.age = age;
  }
}

// 2. 所有继承子类（除非父类无显式构造函数）
class ImplicitParent {
  public value: number = 10;
  // 无显式构造函数
}

class ImplicitChild extends ImplicitParent {
  public extra: number = 20;

  constructor() {
    super();  // 自动调用（可省略）
  }
}

// 调用时机：必须在访问this之前
class TimingParent {
  constructor() {}
}

class TimingChild extends TimingParent {
  public value: number;

  constructor() {
    console.info(`${this.value}`);  // 编译错误

    super();  // 必须先调用

    this.value = 10;  // 正确
    console.info(`${this.value}`);  // 正确
  }
}
```

### 子类构造函数与父类构造函数的参数传递

子类构造函数通过super(...)将参数转发给父类构造函数。

<!-- @[passing_parameters_to_super](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
class MultiParamParent {
  public name: string;
  public age: number;
  public email: string;
  
  constructor(name: string, age: number, email: string) {
    this.name = name;
    this.age = age;
    this.email = email;
  }
}

class MultiParamChild extends MultiParamParent {
  public phone: string;
  
  constructor(name: string, age: number, email: string, phone: string) {
    super(name, age, email);  // 传递所有父类参数
    this.phone = phone;
  }
  
  getInfo(): string {
    return `${this.name}, ${this.age}, ${this.email}, ${this.phone}`;
  }
}

let superChild: MultiParamChild = new MultiParamChild('Alice', 25, 'alice@example.com', '123-456');

// 参数处理方式：
class FlexibleParent {
  public value: number;
  
  constructor(value: number = 10) {
    this.value = value;
  }
}

class FlexibleChild extends FlexibleParent {
  public extra: number;
  
  constructor(value?: number, extra?: number) {
    super(value ?? 10);  // 传递处理后的参数
    this.extra = extra ?? 0;
  }
}

// 参数转换传递
class TransformedParent {
  public id: number;
  
  constructor(id: number) {
    this.id = id;
  }
}

class TransformedChild extends TransformedParent {
  public name: string;
  
  constructor(idString: string, name: string) {
    let id: number = Number.parseInt(idString, 10);
    super(id);  // 转换后传递
    this.name = name;
  }
}
```

## 属性的初始化

属性初始化赋予初始值，确保对象创建时状态有效。

### 初始化顺序与依赖关系

初始化按以下顺序执行：字段默认值赋值→字段初始化器（`=`右侧表达式）→构造函数体赋值。理解此顺序可避免在初始化器中引用未初始化字段。

### 实例属性的直接初始化（声明时赋值）

实例属性的声明时初始化是在属性声明处赋值，确保属性有初始值。

<!-- @[declaration_time_initialization](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
class DirectInitialization {
  // 声明时直接初始化
  public name: string = 'default';
  public age: number = 0;
  public active: boolean = true;
  
  // 数组初始化
  public items: string[] = [];
  
  // 对象初始化
  public config: Map<string, string> = new Map();
  
  // 联合类型初始化
  public value: number | string = 0;
  
  constructor() {
    // 属性已在声明时初始化
  }
}

let direct: DirectInitialization = new DirectInitialization();
console.info(`${direct.name}`);    // 'default'
console.info(`${direct.age}`);     // 0
console.info(`${direct.active}`); // true
```

声明时初始化的优势在于确保属性有初始值、减少构造函数代码并使类型推断更明确。

### 构造函数内的属性初始化

构造函数内属性初始化是在构造函数中为属性赋值，适合需要参数或动态计算的初始化。

<!-- @[constructor_body_initialization](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
class ConstructorInitialization {
  public name: string;
  public age: number;
  public email: string;
  
  constructor(name: string, age: number, email: string) {
    // 构造函数内初始化
    this.name = name;
    this.age = age;
    this.email = email;
  }
  
  constructorDefault() {
    this.name = 'default';
    this.age = 0;
    this.email = '';
  }
}

let constructorInit: ConstructorInitialization = new ConstructorInitialization('Alice', 25, 'alice@example.com');

// 构造函数内初始化：
// 1. 接收外部参数
// 2. 动态计算初始值
// 3. 添加验证逻辑

class ValidatedInitialization {
  public value: number;
  
  constructor(value: number) {
    // 验证后初始化
    if (value < 0) {
      throw new Error('Value must be positive');
    }
    this.value = value;
  }
}

class CalculatedInitialization {
  public base: number;
  public calculated: number;
  
  constructor(base: number) {
    this.base = base;
    this.calculated = base * 2;  // 计算初始化
  }
}
```

### 必须初始化的属性要求

ArkTS编译器默认强制执行属性初始化检查（等效于TypeScript的`strictPropertyInitialization`选项，但ArkTS中不可关闭），所有非可选属性必须在声明时或构造函数中被赋值，否则编译报错。满足要求的方式有两种：声明时赋初值、构造函数中赋值。可选属性（`?`）不要求初始化。

### 可选属性的初始化（? 修饰符，允许未初始化）

用`?`修饰符声明可选属性，创建对象时可不初始化，访问时需处理`undefined`或用`??`提供默认值。

<!-- @[optional_properties_initialization](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
class OptionalProperties {
  public name: string;          // 必需属性
  public age?: number;          // 可选属性
  public email?: string;        // 可选属性
  public phone?: string;        // 可选属性
  
  constructor(name: string) {
    this.name = name;
    // 可选属性不需要初始化
  }
  
  setAge(age: number): void {
    this.age = age;  // 可选属性延迟初始化
  }
  
  getAge(): number {
    return this.age ?? 0;  // 处理未初始化情况
  }
  
  hasAge(): boolean {
    return this.age !== undefined;  // 检查是否初始化
  }
}

let optional: OptionalProperties = new OptionalProperties('Alice');
console.info(`${optional.hasAge()}`);  // false

optional.setAge(25);
console.info(`${optional.hasAge()}`);  // true
console.info(`${optional.getAge()}`);  // 25
```

可选属性特点：可不初始化、可延迟赋值，使用时需检查undefined。

### 初始化检查与编译器验证

编译器会对属性初始化进行检查，确保对象创建后所有必须属性都有初始值。

### 只读属性的初始化限制（只能在声明或构造函数中赋值）

只读属性在声明或构造函数中赋值以保持不可变。

<!-- @[ts_readonly_initialization_rules](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Initialization.ts) -->

``` TypeScript
class ReadOnlyProperties {
  // readonly属性：声明时赋值
  public readonly constant1: number = 100;

  // readonly属性：构造函数中赋值
  public readonly constant2: number;

  // readonly + 可选
  public readonly optionalConstant?: number;

  constructor(value: number) {
    this.constant2 = value;  // 构造函数中可赋值
    this.optionalConstant = value * 2;
  }

  // 方法中不能修改readonly属性
  modifyConstant(): void {
    this.constant2 = 200;  // 编译错误
  }
}

let readOnly: ReadOnlyProperties = new ReadOnlyProperties(50);
console.info(`${readOnly.constant1}`);         // 100
console.info(`${readOnly.constant2}`);         // 50
console.info(`${readOnly.optionalConstant}`);  // 100
```

readonly属性限制：仅可在声明时或构造函数中赋值，其他地方不可修改。

<!-- @[immutable_object_pattern](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
class ImmutablePoint {
  public readonly x: number;
  public readonly y: number;

  constructor(x: number, y: number) {
    this.x = x;
    this.y = y;
    // 构造后x, y不可修改
  }

  translate(dx: number, dy: number): ImmutablePoint {
    return new ImmutablePoint(this.x + dx, this.y + dy);
  }
}
```

## 初始化顺序

当基类和派生类都有字段初始化时，执行顺序为：基类字段 → 基类构造函数 → 派生类字段 → 派生类构造函数。此外，静态初始化块（`static { }`）在类首次被加载时执行，先于所有实例字段初始化和构造函数调用；静态字段的初始化按声明顺序执行，静态初始化块穿插在静态字段之间按顺序执行。

<!-- @[init_order](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
class IoBase {
  public static baseStatic: number = 10;
  public name: string = 'base';

  static {
    console.info('Base static block');
  }

  constructor() {
    console.info(`Base constructor: name = ${this.name}`);
  }
}

class IoDerived extends IoBase {
  public static derivedStatic: number = 20;
  public name: string = 'derived';

  static {
    console.info('Derived static block');
  }

  constructor() {
    super();
    console.info(`Derived constructor: name = ${this.name}`);
  }
}

let ioD: IoDerived = new IoDerived();
// 输出：
// Base static block（类加载时执行静态初始化块，先于实例创建）
// Derived static block
// Base constructor: name = base（派生类字段尚未初始化）
// Derived constructor: name = derived
```

基类构造函数中看到的`this.name`是基类自己的值`'base'`，因为派生类的字段初始化在基类构造函数之后才执行。
## 静态工厂替代便捷构造

用static工厂方法封装对象创建逻辑，替代多个便捷构造函数。

### 基于主构造函数封装工厂方法

在主构造函数基础上封装static工厂方法，提供命名构造入口。

<!-- @[static_factory_methods](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
class FactoryUser {
  public id: number;
  public name: string;
  public email: string;
  public role: string;
  
  // 主构造函数
  constructor(id: number, name: string, email: string, role: string) {
    this.id = id;
    this.name = name;
    this.email = email;
    this.role = role;
  }
  
  // 静态工厂方法：封装常用构造场景
  static createGuest(): FactoryUser {
    return new FactoryUser(0, 'Guest', 'guest@example.com', 'guest');
  }
  
  static createAdmin(id: number, name: string, email: string): FactoryUser {
    return new FactoryUser(id, name, email, 'admin');
  }
  
  static createDefaultUser(name: string): FactoryUser {
    return new FactoryUser(1, name, `${name.toLowerCase()}@example.com`, 'user');
  }
}

let guest: FactoryUser = FactoryUser.createGuest();
let admin: FactoryUser = FactoryUser.createAdmin(1, 'Alice', 'alice@example.com');
let defaultUser: FactoryUser = FactoryUser.createDefaultUser('Bob');
```

静态工厂优势：可简化参数、提供默认值并针对特定场景快速创建对象。

### 静态工厂替代this() 调用

ArkTS不支持this()调用，使用static工厂方法替代便捷构造。

<!-- @[private_constructor_with_factory](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
class FactoryConfiguration {
  public apiUrl: string;
  public timeout: number;
  public debug: boolean;
  
  private constructor(apiUrl: string, timeout: number, debug: boolean) {
    this.apiUrl = apiUrl;
    this.timeout = timeout;
    this.debug = debug;
  }
  
  // 静态工厂方法替代构造函数重载
  static createDefault(): FactoryConfiguration {
    return new FactoryConfiguration('EXAMPLE_API_URL', 5000, false);
  }
  
  static createWithUrl(apiUrl: string): FactoryConfiguration {
    // 调用默认配置，修改部分参数
    let factoryDefaultConfig: FactoryConfiguration = FactoryConfiguration.createDefault();
    return new FactoryConfiguration(apiUrl, factoryDefaultConfig.timeout, factoryDefaultConfig.debug);
  }
  
  static createDebug(): FactoryConfiguration {
    return new FactoryConfiguration('EXAMPLE_API_URL', 5000, true);
  }
  
  static copy(config: FactoryConfiguration): FactoryConfiguration {
    return new FactoryConfiguration(config.apiUrl, config.timeout, config.debug);
  }
}

let factoryDefaultConfig: FactoryConfiguration = FactoryConfiguration.createDefault();
let factoryUrlConfig: FactoryConfiguration = FactoryConfiguration.createWithUrl('EXAMPLE_API_URL');
let debugConfig: FactoryConfiguration = FactoryConfiguration.createDebug();
let copiedConfig: FactoryConfiguration = FactoryConfiguration.copy(factoryDefaultConfig);
```

### 静态工厂的使用场景（简化实例化参数）

静态工厂在参数较多时提供命名的简化构造入口。

<!-- @[static_factory_use_cases](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
class CasesPoint {
  public x: number;
  public y: number;
  
  constructor(x: number, y: number) {
    this.x = x;
    this.y = y;
  }
  
  // 静态工厂场景：
  
  // 1. 创建原点
  static origin(): CasesPoint {
    return new CasesPoint(0, 0);
  }
  
  // 2. 创建等值点
  static equal(value: number): CasesPoint {
    return new CasesPoint(value, value);
  }
  
  // 3. 从字符串解析
  static fromString(str: string): CasesPoint {
    let parts: string[] = str.split(',');
    return new CasesPoint(
      Number.parseInt(parts[0], 10),
      Number.parseInt(parts[1], 10)
    );
  }
  
  // 4. 从数组创建
  static fromArray(arr: number[]): CasesPoint {
    return new CasesPoint(arr[0], arr[1]);
  }
}

let origin: CasesPoint = CasesPoint.origin();
let equal: CasesPoint = CasesPoint.equal(10);
let fromStr: CasesPoint = CasesPoint.fromString('5,10');
let fromArr: CasesPoint = CasesPoint.fromArray([3, 4]);
```

使用场景：常用预设值、参数简化和数据转换。

## 静态初始化与代码块

静态属性在声明时赋值，静态初始化块在类加载时执行初始化逻辑。

### 静态属性的初始化（声明时赋值）

静态属性是在声明时直接赋值的类级别属性。

<!-- @[static_properties_initialization](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
class StaticProperties {
  // 静态属性声明时初始化
  public static appName: string = 'MyApp';
  public static version: number = 1.0;
  public static maxConnections: number = 100;
  
  // 静态只读属性
  public static readonly PI: number = 3.14159;
  public static readonly MAX_VALUE: number = 1000;
  
  // 静态私有属性
  private static counter: number = 0;
  
  static getCounter(): number {
    return StaticProperties.counter;
  }
  
  static incrementCounter(): void {
    StaticProperties.counter++;
  }
}

console.info(`${StaticProperties.appName}`);       // 'MyApp'
console.info(`${StaticProperties.version}`);       // 1.0
console.info(`${StaticProperties.maxConnections}`); // 100
console.info(`${StaticProperties.PI}`);            // 3.14159
```

### 静态代码块（static {}）的执行时机

静态代码块是类加载时执行的代码块，用于初始化需要多行代码或条件判断的静态成员。ArkTS支持静态块语法，不支持`#`私有标识符，使用`private`修饰符替代。

<!-- @[static_initialization_function](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
class StaticInitialization {
  public static config: Map<string, string>;
  public static initialized: boolean;
  
  // 静态初始化函数
  private static initialize(): void {
    StaticInitialization.config = new Map();
    StaticInitialization.config.set('apiUrl', 'EXAMPLE_API_URL');
    StaticInitialization.config.set('timeout', '5000');
    StaticInitialization.initialized = true;
    console.info('Static initialized');
  }
  
  // 确保静态初始化执行
  static getConfig(): Map<string, string> {
    if (!StaticInitialization.initialized) {
      StaticInitialization.initialize();
    }
    return StaticInitialization.config;
  }
}

let config: Map<string, string> = StaticInitialization.getConfig();
console.info(`${config.get('apiUrl')}`);  // EXAMPLE_API_URL

// 静态初始化时机：
// 类首次使用时执行
// 在任何实例创建前执行
```

除了手动管理初始化状态，ArkTS还支持静态代码块（`static { }`），它在类加载时自动执行，无需显式调用即可完成初始化。

<!-- @[static_block_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
class StaticBlockConfig {
  private static count: number = 0;

  static {
    try {
      let data: string[] = ['a', 'b', 'c'];
      StaticBlockConfig.count = data.length;
    } catch (e) {
      StaticBlockConfig.count = 0;
    }
  }

  static getCount(): number {
    return StaticBlockConfig.count;
  }
}

console.info(`${StaticBlockConfig.getCount()}`); // 3
```

### 静态初始化的作用（全局资源初始化、配置加载）

静态初始化块和静态字段在类首次被访问时执行，用于加载全局配置、初始化静态资源池等类级别的一次性设置。

<!-- @[global_config_static_initialization](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
class GlobalConfig {
  private static initialized: boolean = false;
  private static settings: Map<string, string | number | boolean> = new Map();
  
  // 静态初始化：全局配置加载
  static ensureInitialized(): void {
    if (!GlobalConfig.initialized) {
      GlobalConfig.loadSettings();
      GlobalConfig.initialized = true;
    }
  }
  
  private static loadSettings(): void {
    // 模拟配置加载
    GlobalConfig.settings.set('apiUrl', 'EXAMPLE_API_URL');
    GlobalConfig.settings.set('timeout', 5000);
    GlobalConfig.settings.set('debug', false);
    GlobalConfig.settings.set('maxRetries', 3);
    console.info('Global configuration loaded');
  }
  
  // 全局配置访问
  static get(key: string): string | number | boolean | undefined {
    GlobalConfig.ensureInitialized();
    return GlobalConfig.settings.get(key);
  }
  
  static set(key: string, value: string | number | boolean): void {
    GlobalConfig.ensureInitialized();
    GlobalConfig.settings.set(key, value);
  }
  
  static reset(): void {
    GlobalConfig.settings.clear();
    GlobalConfig.initialized = false;
  }
}

// 使用全局配置
console.info(`${GlobalConfig.get('apiUrl')}`);      // 'EXAMPLE_API_URL'
console.info(`${GlobalConfig.get('timeout')}`);     // 5000
console.info(`${GlobalConfig.get('debug')}`);       // false

GlobalConfig.set('customKey', 'customValue');
console.info(`${GlobalConfig.get('customKey')}`);   // 'customValue'
```

## 初始化的安全检查

编译器检查未初始化的属性并报错，确保对象属性在使用前有值。

### TypeScript类型检查对未初始化属性的限制

编译器对未初始化的属性报错或警告：`strictPropertyInitialization`要求所有属性在构造函数结束前被赋值，否则编译失败。

<!-- @[ts_required_properties_initialization](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Initialization.ts) -->

``` TypeScript
class StrictInitialization {
  // 必需属性：必须初始化
  public name: string;  // 编译警告：未初始化
  public age: number;   // 编译警告：未初始化
  
  constructor() {
    // 未初始化name和age
    // TypeScript会提示警告
  }
  
  // 正确做法：初始化所有属性
  correctConstructor(name: string, age: number) {
    this.name = name;
    this.age = age;
  }
}

class ProperInitialization {
  // 声明时初始化
  public name: string = '';
  public age: number = 0;
  
  constructor() {
    // 属性已初始化
  }
}

class OptionalInitialization {
  // 可选属性：可不初始化
  public name?: string;
  public age?: number;
  
  constructor() {
    // 可选属性允许未初始化
  }
  
  initialize(name: string, age: number): void {
    this.name = name;
    this.age = age;
  }
}
```

### 避免undefined异常的初始化技巧

通过确保属性有值、使用可选链（`?.`）和空值合并（`??`）等安全访问方式，避免undefined异常。

<!-- @[safe_initialization_techniques](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
class SafeInitialization {
  public name: string;
  public age: number;
  public email?: string;
  
  constructor(name: string, age: number) {
    // 确保必需属性初始化
    this.name = name ?? 'default';
    this.age = age ?? 0;
    
    // 可选属性谨慎处理
    if (this.email === undefined) {
      console.info('Email not initialized');
    }
  }
  
  // 安全访问技巧
  getEmail(): string {
    return this.email ?? '';
  }
  
  hasEmail(): boolean {
    return this.email !== undefined && this.email.length > 0;
  }
  
  safeProcess(): void {
    // 检查后访问
    if (this.name !== undefined) {
      console.info(`${this.name}`);
    }
    
    // 使用空值合并
    let safeAge: number = this.age ?? 0;
    
    // 使用可选链（对象属性）
    let emailLength: number | undefined = this.email?.length;
  }
}
```

### 结合可选链（?.）处理初始化不确定性

使用可选链（`?.`）安全访问可能未初始化的属性，避免运行时undefined错误。

<!-- @[optional_chaining_safe_access](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
interface OptionalProfile {
  nickname?: string;
  avatar?: string;
}

class OptionalChainExample {
  public name?: string;
  public age?: number;
  public profile?: OptionalProfile;
  
  constructor() {
    // 可选属性可不初始化
  }
  
  // 使用可选链安全访问
  safeAccess(): void {
    // 可选链访问属性
    let nameLength: number | undefined = this.name?.length;
    
    // 可选链访问嵌套对象
    let nickname: string | undefined = this.profile?.nickname;
    let avatar: string | undefined = this.profile?.avatar;
    
    // 可选链 + 空值合并
    let displayName: string = this.name ?? 'Unknown';
    let displayNickname: string = this.profile?.nickname ?? 'Guest';
  }
  
  // 安全方法
  getProfileInfo(): string {
    if (this.profile !== undefined) {
      let nickname: string = this.profile.nickname ?? 'No nickname';
      let avatar: string = this.profile.avatar ?? 'No avatar';
      return `Nickname: ${nickname}, Avatar: ${avatar}`;
    }
    return 'No profile';
  }
  
  // 可选链检查
  checkInitialization(): void {
    if (this.name !== undefined) {
      console.info(`Name: ${this.name}`);
    }
    
    if (this.profile?.nickname !== undefined) {
      console.info(`Nickname: ${this.profile.nickname}`);
    }
  }
}
```

## declare字段声明

子类中重新声明继承字段的更精确类型时，使用`declare`避免运行时覆盖父类值。

<!-- @[declare_field_init](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
interface DfiAnimal {
  dateOfBirth: Date;
}

interface DfiDog extends DfiAnimal {
  breed: string;
}

class DfiAnimalHouse {
  public resident: DfiAnimal;

  constructor(animal: DfiAnimal) {
    this.resident = animal;
  }
}

class DfiDogHouse extends DfiAnimalHouse {
  public declare resident: DfiDog;

  constructor(dog: DfiDog) {
    super(dog);
  }
}

let dfiDog: DfiDog = { dateOfBirth: new Date(), breed: 'Labrador' };
let dfiHouse: DfiDogHouse = new DfiDogHouse(dfiDog);
console.info(`${dfiHouse.resident.breed}`);  // Labrador
```

