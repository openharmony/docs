# 方法
<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

方法是类的行为定义。ArkTS支持实例方法、静态方法、方法重载等特性。

## 方法的基础概念与分类

方法是类中定义的函数，描述对象的行为，通过this访问实例属性，分为实例方法、静态方法和构造函数。

### 方法的定义与作用

方法将操作逻辑封装在类中，通过`this`访问实例状态，为外部代码提供操作接口、实现复用并隐藏实现细节。

<!-- @[method_definition_basic](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Methods.ets) -->

``` TypeScript
class Calculator {
  public value: number = 0;
  
  // 方法定义：执行操作
  add(n: number): void {
    this.value += n;
  }
  
  // 方法定义：计算结果
  getValue(): number {
    return this.value;
  }
  
  // 方法的作用：封装行为逻辑
  reset(): void {
    this.value = 0;
  }
}

let calc: Calculator = new Calculator();
calc.add(10);          // 执行操作
console.info(`${calc.getValue().toString()}`);  // 10，计算结果
calc.reset();           // 重置状态
console.info(`${calc.getValue().toString()}`);  // 0
```

### 实例方法与静态方法的核心区别

实例方法通过this访问实例属性，需通过实例调用；静态方法属于类本身，通过类名调用，不依赖实例。

<!-- @[ts_instance_vs_static_methods](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Methods.ts) -->

``` TypeScript
class MathOperations {
  // 实例方法：通过实例调用，访问实例属性
  public instanceValue: number = 0;

  addInstanceValue(n: number): void {
    this.instanceValue += n;  // 使用this
  }

  getInstanceValue(): number {
    return this.instanceValue;  // 访问实例属性
  }

  // 静态方法：通过类名调用，访问静态属性
  static add(a: number, b: number): number {
    return a + b;  // 不使用this
  }

  static multiply(a: number, b: number): number {
    return a * b;
  }

  public static description: string = 'Math Operations';

  static getDescription(): string {
    return MathOperations.description;  // 通过类名访问
  }
}

let math: MathOperations = new MathOperations();

// 实例方法：通过实例调用
math.addInstanceValue(10);
console.info(`${math.getInstanceValue()}`);  // 10

// 静态方法：通过类名调用
console.info(`${MathOperations.add(5, 3)}`);    // 8
console.info(`${MathOperations.multiply(4, 7)}`); // 28

// 静态方法无法访问实例属性
let result = MathOperations.getInstanceValue();  // 编译错误
```

### 方法与独立函数的关联与差异

方法依附于类，可通过`this`访问实例状态和私有成员；独立函数不依附类，无法访问实例状态。方法支持访问修饰符控制可见性。

<!-- @[standalone_function_vs_method](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Methods.ets) -->

``` TypeScript
// 独立函数：不依附于类
function standaloneAdd(a: number, b: number): number {
  return a + b;
}

// 类方法：依附于类，可访问类内部状态
class Accumulator {
  private total: number = 0;
  
  // 方法：可访问私有状态
  add(n: number): void {
    this.total += n;
  }
  
  getTotal(): number {
    return this.total;
  }
  
  // 方法优势：封装和状态管理
  reset(): void {
    this.total = 0;
  }
}

// 差异对比
console.info(`${standaloneAdd(1, 2).toString()}`);  // 3，无状态

let acc: Accumulator = new Accumulator();
acc.add(10);
acc.add(20);
console.info(`${acc.getTotal().toString()}`);  // 30，有状态管理

// 方法可以访问私有数据，函数不能
// 独立函数无法访问acc.total（私有）
```

## 实例方法

实例方法定义对象的行为，通过实例调用执行操作。

### 方法参数与返回值的概念

方法参数接收调用方传入的数据，返回值将计算结果回传给调用方，二者共同定义方法的输入输出契约。

### 实例方法的声明语法

实例方法声明定义了方法的名称、参数列表、返回类型和访问修饰符，通过类的实例对象调用。

<!-- @[instance_method_declaration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Methods.ets) -->

``` TypeScript
class Student {
  public name: string;
  public age: number;
  
  constructor(name: string, age: number) {
    this.name = name;
    this.age = age;
  }
  
  // 实例方法声明
  study(): void {
    console.info(`${this.name} is studying`);
  }
  
  // 带参数的实例方法
  studyFor(subject: string): void {
    console.info(`${this.name} is studying ${subject}`);
  }
  
  // 带返回值的实例方法
  getInfo(): string {
    return `${this.name}, ${this.age} years old`;
  }
  
  // 带默认参数的方法
  greet(greeting: string = 'Hello'): string {
    return `${greeting}, I'm ${this.name}`;
  }
}

let student: Student = new Student('Alice', 20);

// 调用实例方法
student.study();               // 'Alice is studying'
student.studyFor('Math');       // 'Alice is studying Math'
console.info(`${student.getInfo()}`); // 'Alice, 20 years old'
console.info(`${student.greet()}`);   // 'Hello, I'm Alice'
console.info(`${student.greet('Hi')}`); // 'Hi, I'm Alice'
```

### 方法的调用方式

实例方法通过实例对象调用（`obj.method()`），静态方法通过类名调用（`ClassName.method()`），两者在`this`绑定和成员访问上存在差异。

### 实例方法的调用方式（通过类的实例对象）

通过`实例.方法名()`调用实例方法，方法体内`this`指向当前实例，可访问实例属性和其他实例方法。

<!-- @[instance_method_on_separate_instances](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Methods.ets) -->

``` TypeScript
class Logger {
  private logs: string[] = [];
  
  // 实例方法
  log(message: string): void {
    this.logs.push(message);
    console.info(`Logged: ${message}`);
  }
  
  // 实例方法
  getLogs(): string[] {
    return [...this.logs];
  }
  
  // 实例方法
  clear(): void {
    this.logs = [];
    console.info('Logs cleared');
  }
}

// 创建实例
let logger1: Logger = new Logger();
let logger2: Logger = new Logger();

// 每个实例独立调用方法
logger1.log('Error in module A');
logger1.log('Warning in module B');
logger2.log('Info from module C');

console.info(`${logger1.getLogs().join(', ')}`);  // Error in module A, Warning in module B
console.info(`${logger2.getLogs().join(', ')}`);  // Info from module C

// 方法作用于特定实例
logger1.clear();
console.info(`${logger1.getLogs().length}`);  // 0
console.info(`${logger2.getLogs().join(', ')}`);  // Info from module C
```

### 实例方法中this的指向规则与绑定问题

实例方法中的this关键字指向当前对象实例，但在特定场景下可能丢失绑定。

<!-- @[this_binding_and_arrow_function](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Methods.ets) -->

``` TypeScript
class Counter {
  public count: number = 0;

  // 实例方法：this指向实例
  increment(): void {
    this.count++;
    console.info(`${this.count}`);
  }

  // 返回方法引用：可能丢失this
  getIncrementMethod(): () => void {
    return this.increment;  // 方法引用
  }

  // 使用箭头函数保持this
  getSafeIncrementMethod(): () => void {
    return () => {
      this.count++;  // 箭头函数保持this
      console.info(`${this.count}`);
    };
  }
}

let counter: Counter = new Counter();

// 正常调用：this正确
counter.increment();  // 1

// 方法引用调用：this可能丢失
let method: () => void = counter.getIncrementMethod();
try {
  method();  // 可能丢失this，取决于调用方式
} catch (e) {
  console.info('this丢失');
}

// 安全方法引用：this保持
let safeMethod: () => void = counter.getSafeIncrementMethod();
safeMethod();  // 2，this正确

// 解决方案：绑定this
class Button {
  private onClickHandler: () => void;

  constructor() {
    // 箭头函数绑定this
    this.onClickHandler = () => {
      this.handleClick();
    };
  }

  private handleClick(): void {
    console.info(`Button clicked`);
  }

  getHandler(): () => void {
    return this.onClickHandler;
  }
}
```

### 方法的访问控制与概念

访问控制通过`public`/`private`/`protected`修饰符限制方法的可访问范围，目的是封装内部实现细节，只暴露稳定的公共接口，降低模块间的耦合度。`public`方法构成类的对外API，`private`/`protected`方法仅供内部或子类使用。

### 实例方法的访问控制（public/private/protected修饰符）

通过public、private、protected修饰符限制方法的可访问范围：public方法类内外均可调用，private方法仅类内部可见，protected方法可被子类访问。

<!-- @[ts_method_access_modifiers](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Methods.ts) -->

``` TypeScript
class Service {
  // public：公开方法
  public start(): void {
    console.info(`Service started`);
    this.initialize();
  }

  // private：私有方法，仅类内部
  private initialize(): void {
    console.info(`Initializing...`);
    this.loadConfig();
  }

  // protected：受保护方法，子类可访问
  protected loadConfig(): void {
    console.info(`Loading configuration`);
  }

  // 公开方法调用私有方法
  public stop(): void {
    this.cleanup();
    console.info(`Service stopped`);
  }

  private cleanup(): void {
    console.info(`Cleaning up resources`);
  }
}

let service: Service = new Service();

// public方法可调用
service.start();  // Service started, Initializing..., Loading config
service.stop();   // Cleaning up..., Service stopped

// private方法不可访问
service.initialize();  // 编译错误

// protected方法不可访问
service.loadConfig();  // 编译错误

// 子类访问protected方法
class CustomService extends Service {
  configure(): void {
    this.loadConfig();  // 可访问protected
  }
}
```

## 静态方法

静态方法属于类本身，通过类名直接调用，不依赖实例。

### 静态方法的声明

静态方法是属于类本身而非实例的方法，通过static关键字声明。

<!-- @[ts_static_method_declaration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Methods.ts) -->

``` TypeScript
class Utility {
  // 静态属性
  public static version: string = '1.0.0';

  // 静态方法声明
  static clamp(value: number, min: number, max: number): number {
    return Math.max(min, Math.min(max, value));
  }

  static formatCurrency(amount: number): string {
    return '$' + amount.toFixed(2);
  }

  static generateId(): string {
    return `ID-${Date.now()}`;
  }

  // 静态方法访问静态属性
  static getVersion(): string {
    return Utility.version;
  }

  // 静态方法不能访问实例属性
  static getInstanceValue(): number {
    return this.instanceValue;  // 编译错误
  }
}

// 静态方法通过类名调用
console.info(`${Utility.clamp(15, 0, 10)}`);      // 10
console.info(`${Utility.formatCurrency(123.456)}`); // $123.46
console.info(`${Utility.generateId()}`);          // ID-1234567890
console.info(`${Utility.getVersion()}`);           // 1.0.0

// 实例无法直接调用静态方法
let utility: Utility = new Utility();
utility.clamp(5, 0, 10);  // 编译错误
```

### 静态方法的调用方式（通过类名直接调用）

静态方法通过类名直接调用，不需要创建实例对象。

<!-- @[ts_static_method_usage_patterns](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Methods.ts) -->

``` TypeScript
class Database {
  private static connectionCount: number = 0;

  // 静态方法：管理连接
  static connect(): void {
    Database.connectionCount++;
    console.info(`Connected. Total: ${Database.connectionCount}`);
  }

  static disconnect(): void {
    if (Database.connectionCount > 0) {
      Database.connectionCount--;
    }
    console.info(`Disconnected. Total: ${Database.connectionCount}`);
  }

  static getConnectionCount(): number {
    return Database.connectionCount;
  }

  // 静态工厂方法
  static createConnection(): Database {
    Database.connect();
    return new Database();
  }
}

// 通过类名调用静态方法
Database.connect();      // Connected. Total: 1
Database.connect();      // Connected. Total: 2
console.info(`${Database.getConnectionCount()}`);  // 2

Database.disconnect();   // Disconnected. Total: 1
console.info(`${Database.getConnectionCount()}`);  // 1

// 静态工厂方法
let db1: Database = Database.createConnection();
let db2: Database = Database.createConnection();
console.info(`${Database.getConnectionCount()}`);  // 3

// 实例无法调用静态方法
db1.connect();  // 编译错误
```

### 静态方法的特性（无this绑定、与类生命周期关联）

静态方法具有两个主要特性：无法访问实例this绑定，以及直接与类（而非实例）的生命周期关联。静态初始化块（`static { }`）从API version 12开始支持。

<!-- @[static_properties_and_initialization](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Methods.ets) -->

``` TypeScript
class Configuration {
  // 静态属性：类级别数据
  private static settings: Map<string, string> = new Map();
  
  // 静态初始化（类加载时执行）
  static {
    Configuration.settings.set('apiUrl', 'EXAMPLE_API_URL');
    Configuration.settings.set('timeout', '5000');
    console.info('Configuration initialized');
  }
  
  // 静态方法：无this，访问静态属性
  static get(key: string): string | undefined {
    return Configuration.settings.get(key);
  }
  
  static set(key: string, value: string): void {
    Configuration.settings.set(key, value);
  }
  
  static getAll(): Map<string, string> {
    return new Map(Configuration.settings);
  }
  
  // 静态方法在类生命周期内
  static reset(): void {
    Configuration.settings.clear();
    console.info('Configuration reset');
  }
}

// 类加载时静态初始化执行
console.info(`${Configuration.get('apiUrl')}`);     // EXAMPLE_API_URL
console.info(`${Configuration.get('timeout')}`);    // 5000

Configuration.set('debug', 'true');
console.info(`${Configuration.get('debug')}`);      // true

Configuration.reset();
console.info(`${Configuration.get('apiUrl')}`);     // undefined
```

### 静态方法的典型使用场景

静态方法常用于工厂方法、单例模式和工具函数。

<!-- @[static_factory_singleton_utility](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Methods.ets) -->

``` TypeScript
// 1. 工厂方法
class User {
  private id: number;
  private name: string;

  private constructor(id: number, name: string) {
    this.id = id;
    this.name = name;
  }
  
  // 静态工厂方法
  static create(id: number, name: string): User {
    return new User(id, name);
  }
  
  static createGuest(): User {
    return new User(0, 'Guest');
  }
  
  static createAdmin(id: number): User {
    return new User(id, 'Admin');
  }
  
  getInfo(): string {
    return `User ${this.id}: ${this.name}`;
  }
}

let admin: User = User.createAdmin(1);
let guest: User = User.createGuest();
console.info(`${admin.getInfo()}`);   // User 1: Admin
console.info(`${guest.getInfo()}`);   // User 0: Guest

// 2. 单例模式
class Singleton {
  private static instance: Singleton | undefined = undefined;
  
  private constructor() {}
  
  static getInstance(): Singleton {
    if (Singleton.instance === undefined) {
      Singleton.instance = new Singleton();
    }
    return Singleton.instance;
  }
  
  doSomething(): void {
    console.info('Singleton working');
  }
}

let s1: Singleton = Singleton.getInstance();
let s2: Singleton = Singleton.getInstance();
console.info(`${(s1 === s2).toString()}`);  // true，同一实例

// 3. 工具方法
class ArrayUtils {
  static isEmpty<T>(arr: T[]): boolean {
    return arr.length === 0;
  }
  
  static first<T>(arr: T[]): T | undefined {
    return arr[0];
  }
  
  static last<T>(arr: T[]): T | undefined {
    return arr[arr.length - 1];
  }
  
  static flatten<T>(arr: T[][]): T[] {
    let result: T[] = [];
    for (let sub of arr) {
      for (let item of sub) {
        result.push(item);
      }
    }
    return result;
  }
}
```

## 方法的参数特性

方法参数支持可选、默认、剩余等多种形式，灵活接收输入。

### 方法参数的类型标注与默认值设置

方法参数通过`: 类型`标注数据类型，通过`= 默认值`提供初始值，ArkTS支持可选参数（`?`）和剩余参数（`...rest`）。

<!-- @[method_parameters_and_defaults](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Methods.ets) -->

``` TypeScript
class EmailSender {
  // 参数类型标注
  send(to: string, subject: string, body: string): void {
    console.info(`Sending to ${to}: ${subject}`);
  }
  
  // 默认参数值
  sendTemplate(to: string, template: string = 'default'): void {
    console.info(`Template ${template} to ${to}`);
  }
  
  // 多个默认参数
  sendWithOptions(
    to: string,
    subject: string = 'No Subject',
    priority: string = 'normal',
    cc: string | undefined = undefined
  ): void {
    console.info(`To: ${to}, Subject: ${subject}, Priority: ${priority}`);
    if (cc !== undefined) {
      console.info(`CC: ${cc}`);
    }
  }
}

let sender: EmailSender = new EmailSender();

sender.send('alice@example.com', 'Hello', 'Body content');
sender.sendTemplate('bob@example.com');           // default template
sender.sendTemplate('bob@example.com', 'custom');  // custom template

sender.sendWithOptions('test@example.com');  // 使用所有默认值
sender.sendWithOptions('test@example.com', 'Important');
sender.sendWithOptions('test@example.com', 'Important', 'high', 'admin@example.com');
```

### 剩余参数（... 扩展语法）的使用方式

剩余参数使用`...`语法将多个同名参数收集为数组，允许方法接收不定数量的参数，常与普通参数混合使用。

<!-- @[rest_parameters](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Methods.ets) -->

``` TypeScript
class NumberProcessor {
  // 剩余参数：收集多个参数
  sum(...values: number[]): number {
    let total: number = 0;
    for (let value of values) {
      total += value;
    }
    return total;
  }
  
  // 混合参数：普通参数 + 剩余参数
  process(base: number, ...modifiers: number[]): number {
    let result: number = base;
    for (let modifier of modifiers) {
      result += modifier;
    }
    return result;
  }
  
  // 剩余参数类型
  join(separator: string, ...parts: string[]): string {
    return parts.join(separator);
  }
}

let processor: NumberProcessor = new NumberProcessor();

console.info(`${processor.sum(1, 2, 3, 4).toString()}`);       // 10
console.info(`${processor.sum(10).toString()}`);              // 10
console.info(`${processor.sum().toString()}`);                // 0

console.info(`${processor.process(100, 10, 20).toString()}`);  // 130
console.info(`${processor.process(50).toString()}`);           // 50

console.info(`${processor.join('-', 'a', 'b', 'c')}`);  // 'a-b-c'
```

### 解构参数的替代写法

TypeScript支持在方法参数中直接解构对象（如`move({x, y}: Point, dx: number)`）。ArkTS不支持解构参数，需通过接口类型参数接收后手动提取属性。

<!-- @[object_parameters](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Methods.ets) -->

``` TypeScript
// ArkTS不支持解构参数，需通过接口类型参数接收后手动提取

class PointOperations {
  move(point: Point, dx: number, dy: number): Point {
    let x: number = point.x;  // 手动提取
    let y: number = point.y;
    return { x: x + dx, y: y + dy };
  }
  
  processOptions(options: Options): string {
    let timeout: number = options.timeout;
    let retries: number = options.retries;
    let verbose: boolean = options.verbose;
    
    return `Timeout: ${timeout}, Retries: ${retries}, Verbose: ${verbose}`;
  }
}

interface Point {
  x: number;
  y: number;
}

interface Options {
  timeout: number;
  retries: number;
  verbose: boolean;
}

let ops: PointOperations = new PointOperations();
let result: Point = ops.move({ x: 10, y: 20 }, 5, 3);
console.info(JSON.stringify(result));  // {"x":15,"y":23}

console.info(ops.processOptions({ timeout: 5000, retries: 3, verbose: true }));
```

### 可选参数的声明（? 修饰符）与传参规则

可选参数使用 ? 修饰符声明，表示参数可以省略不传。

<!-- @[optional_parameters](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Methods.ets) -->

``` TypeScript
class DocumentGenerator {
  // 可选参数：使用 ? 修饰
  generate(title: string, author?: string): string {
    if (author !== undefined) {
      return `Title: ${title}, Author: ${author}`;
    }
    return `Title: ${title}`;
  }
  
  // 多个可选参数
  createReport(
    title: string,
    subtitle?: string,
    author?: string,
    date?: string
  ): string {
    let report: string = `Title: ${title}`;
    if (subtitle !== undefined) {
      report += `, Subtitle: ${subtitle}`;
    }
    if (author !== undefined) {
      report += `, Author: ${author}`;
    }
    if (date !== undefined) {
      report += `, Date: ${date}`;
    }
    return report;
  }
  
  // 可选参数必须在必需参数之后
  format(text: string, prefix?: string, suffix?: string): string {
    let result: string = text;
    if (prefix !== undefined) {
      result = prefix + result;
    }
    if (suffix !== undefined) {
      result = result + suffix;
    }
    return result;
  }
}

let generator: DocumentGenerator = new DocumentGenerator();

console.info(`${generator.generate('Report')}`);              // Title: Report
console.info(`${generator.generate('Report', 'Alice')}`);     // Title: Report, Author: Alice

console.info(`${generator.createReport('Annual Report')}`);  // Title: Annual Report
console.info(`${generator.createReport('Annual Report', '2023 Summary')}`);  // Title + Subtitle
console.info(`${generator.createReport('Annual Report', '2023 Summary', 'Bob', '2023-01-01')}`);

console.info(`${generator.format('Hello')}`);                // 'Hello'
console.info(`${generator.format('Hello', '[')}`);            // '[Hello'
console.info(`${generator.format('Hello', '[', ']')}`);       // '[Hello]'
```

## 方法重载

方法重载提供多个签名，根据参数类型选择不同实现。

### 方法重载的概念与实现

方法重载允许同一方法名根据不同参数类型或数量提供多个调用签名，编译器根据传入参数自动匹配。实现时先声明多个重载签名，再用一个实现签名覆盖所有情况。注意：实现签名对外不可见，调用方只能使用已声明的重载签名。

### 方法重载的声明规则（同名不同参）

方法重载通过声明多个同名但参数不同的签名，最后用一个兼容所有签名的实现签名统一处理，调用时按参数类型匹配对应签名。

<!-- @[method_overload_signatures](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Methods.ets) -->

``` TypeScript
class DataParser {
  // 重载签名
  parse(data: string): string[];
  parse(data: number): string;
  parse(data: string | number): string | string[] {
    if (typeof data === 'string') {
      return data.split(',');
    }
    return data.toString();
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
  
  // 不同返回类型重载
  convert(input: string): number;
  convert(input: number): string;
  convert(input: string | number): string | number {
    if (typeof input === 'string') {
      return Number.parseInt(input, 10);
    }
    return input.toString();
  }
}

let parser: DataParser = new DataParser();

console.info(`${parser.parse('a,b,c').join(', ')}`);     // a, b, c
console.info(`${parser.parse(123)}`);          // '123'

console.info(`${parser.format(3.14159)}`);      // '3.14159'
console.info(`${parser.format(3.14159, 2)}`);   // '3.14'

console.info(`${parser.convert('42').toString()}`);        // 42
console.info(`${parser.convert(100)}`);         // '100'
```

### 重载签名与实现签名的匹配要求

重载的实现签名必须兼容所有重载签名的参数和返回类型，调用时按签名顺序匹配最具体的重载。

<!-- @[method_overload_implementation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Methods.ets) -->

``` TypeScript
class ImplementationCalculator {
  // 重载签名：定义公共接口
  calculate(a: number, b: number): number;
  calculate(a: string, b: string): string;
  
  // 实现签名：必须兼容所有重载
  calculate(a: number | string, b: number | string): number | string {
    if (typeof a === 'number' && typeof b === 'number') {
      return a + b;
    }
    if (typeof a === 'string' && typeof b === 'string') {
      return a + b;
    }
    // 处理不匹配情况
    return 0;
  }
  
  // 参数数量不同的重载
  process(value: number): number;
  process(value: number, multiplier: number): number;
  
  process(value: number, multiplier?: number): number {
    if (multiplier !== undefined) {
      return value * multiplier;
    }
    return value;
  }
}

let implementationCalc: ImplementationCalculator = new ImplementationCalculator();

console.info(`${implementationCalc.calculate(5, 3)}`);       // 8
console.info(`${implementationCalc.calculate('a', 'b')}`);   // 'ab'

console.info(`${implementationCalc.process(10)}`);            // 10
console.info(`${implementationCalc.process(10, 2)}`);         // 20
```

### 方法重载的使用限制与注意事项

ArkTS中方法重载通过多个签名声明实现，需注意签名与实现的兼容性。

<!-- @[overload_rules](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Methods.ets) -->

``` TypeScript
class OverloadExample {
  // 重载必须类型兼容
  method(x: number): string;
  method(x: string): number;
  method(x: number | string): string | number {
    if (typeof x === 'number') {
      return `Number: ${x}`;
    }
    return x.length;
  }
  
  // 不能仅用可选参数区分重载
  // method(a: number): void;
  // method(a: number, b?: number): void;  // 冲突
  
  // 重载顺序：更具体的类型先声明
  handle(value: string): string;      // 更具体
  handle(value: number): number;      // 更具体
  handle(value: string | number): string | number {  // 实现签名
    if (typeof value === 'string') {
      return value.toUpperCase();
    }
    return value * 2;
  }
}

let example: OverloadExample = new OverloadExample();

console.info(`${example.method(10)}`);    // 'Number: 10'
console.info(`${example.method('test')}`); // 4

console.info(`${example.handle('hello')}`);  // 'HELLO'
console.info(`${example.handle(5)}`);        // 10
```

### 方法重载的替代方案

方法重载应控制签名数量，过多时改用可选参数或联合类型。

<!-- @[overload_alternatives](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Methods.ets) -->

``` TypeScript
class SafeConverter {
  // 使用静态方法替代重载（更清晰）
  static toNumberFromString(value: string): number | null {
    let result: number = Number.parseInt(value, 10);
    return Number.isNaN(result) ? null : result;
  }
  
  static toNumberFromNumber(value: number): number {
    return value;
  }
  
  // 或使用联合类型和类型守卫
  convert(value: string | number): number | null {
    if (typeof value === 'string') {
      let result: number = Number.parseInt(value, 10);
      return Number.isNaN(result) ? null : result;
    }
    return value;
  }
  
  // 为不同场景提供不同方法名
  fromString(str: string): number | null {
    let result: number = Number.parseInt(str, 10);
    return Number.isNaN(result) ? null : result;
  }
  
  fromNumber(num: number): number {
    return num;
  }
}

let converter: SafeConverter = new SafeConverter();

console.info(`${SafeConverter.toNumberFromString('123')}`);  // 123
console.info(`${SafeConverter.toNumberFromNumber(456)}`);    // 456

console.info(`${converter.convert('42')}`);        // 42
console.info(`${converter.convert(100)}`);         // 100

console.info(`${converter.fromString('abc')}`);    // null
console.info(`${converter.fromNumber(200)}`);      // 200
```

## 继承中的方法

子类自动继承父类的public和protected方法，可重写父类方法，通过`super.方法名()`调用父类原始实现。

### 子类对父类实例方法与静态方法的继承规则

子类继承父类的实例方法和静态方法：实例方法通过实例对象调用，`this`指向子类实例；静态方法通过子类类名调用，无法访问实例状态。

<!-- @[ts_method_inheritance](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Methods.ts) -->

``` TypeScript
class Parent {
  // 实例方法：继承
  greet(): void {
    console.info(`Hello from Parent`);
  }

  // 静态方法：继承
  static getDescription(): string {
    return 'Parent class';
  }

  // protected方法：子类可访问
  protected internalMethod(): void {
    console.info(`Internal method`);
  }
}

class Child extends Parent {
  // 继承父类的实例方法
  callParentGreet(): void {
    this.greet();  // 继承的实例方法
  }

  // 继承父类的静态方法
  static getParentDescription(): string {
    return Parent.getDescription();  // 继承的静态方法
  }

  // 访问父类的protected方法
  callInternal(): void {
    this.internalMethod();  // 可访问
  }
}

let child: Child = new Child();

child.greet();              // 'Hello from Parent'（继承）
child.callParentGreet();    // 'Hello from Parent'
console.info(`${Parent.getDescription()}`);  // 'Parent class'
console.info(`${Child.getDescription()}`);   // 'Parent class'（继承）
child.callInternal();       // 'Internal method'

// 注意：静态方法不能通过实例访问
child.getDescription();  // 编译错误
```

### 方法重写的语法

方法重写是子类重新定义父类方法实现的过程，用于修改或扩展父类行为。

<!-- @[method_override](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Methods.ets) -->

``` TypeScript
class Animal {
  speak(): string {
    return 'Animal speaks';
  }
  
  move(): void {
    console.info('Animal moves');
  }
}

class Dog extends Animal {
  // 重写方法（TypeScript中override可选）
  speak(): string {
    return 'Dog barks';
  }
  
  // 重写并扩展父类方法
  move(): void {
    console.info('Dog runs');
  }
}

class Cat extends Animal {
  speak(): string {
    return 'Cat meows';
  }
  
  move(): void {
    console.info('Cat walks');
  }
}

let dog: Dog = new Dog();
let cat: Cat = new Cat();

console.info(`${dog.speak()}`);  // 'Dog barks'
console.info(`${cat.speak()}`);  // 'Cat meows'

dog.move();  // 'Dog runs'
cat.move();  // 'Cat walks'

// 父类引用指向子类实例
let animal: Animal = new Dog();
console.info(`${animal.speak()}`);  // 'Dog barks'（动态绑定）
```

### 重写方法的访问权限限制

重写方法不能降低父类方法的访问权限，只能保持或提升权限。

<!-- @[ts_override_access_modifiers](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Methods.ts) -->

``` TypeScript
class Base {
  // public方法
  public publicMethod(): void {
    console.info(`Base public`);
  }

  // protected方法
  protected protectedMethod(): void {
    console.info(`Base protected`);
  }

  // private方法（不能重写）
  private privateMethod(): void {
    console.info(`Base private`);
  }

  protected loweredPublicMethod(): void {}
}

class Derived extends Base {
  // 重写public方法：保持public
  public publicMethod(): void {
    console.info(`Derived public`);
  }

  // 重写protected方法：可保持protected或改为public
  public protectedMethod(): void {
    console.info(`Derived public (was protected)`);
  }

  // 不能重写private方法
  private privateMethod(): void {}  // 编译错误

  // 不能降低访问权限
  private loweredPublicMethod(): void {}  // 编译错误：不能从protected改为private

  callProtected(): void {
    this.protectedMethod();  // 可访问父类protected
  }
}

let derived: Derived = new Derived();
derived.publicMethod();        // 'Derived public'
derived.protectedMethod();     // 'Derived public (was protected)'
derived.callProtected();       // 'Base protected'
```

### 通过super关键字调用父类方法

super关键字用于在子类方法中调用父类的同名方法，实现方法扩展和功能复用。

<!-- @[super_keyword_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Methods.ets) -->

``` TypeScript
class Vehicle {
  start(): void {
    console.info('Vehicle starting...');
  }
  
  stop(): void {
    console.info('Vehicle stopped');
  }
  
  getInfo(): string {
    return 'Vehicle info';
  }
}

class Car extends Vehicle {
  start(): void {
    super.start();  // 调用父类方法
    console.info('Car engine started');
  }
  
  stop(): void {
    console.info('Car engine off');
    super.stop();  // 调用父类方法
  }
  
  getInfo(): string {
    return `${super.getInfo()}, Car model: Tesla`;  // 扩展父类返回值
  }
  
  // 额外方法
  accelerate(): void {
    console.info('Car accelerating');
  }
}

let car: Car = new Car();

car.start();  // Vehicle starting..., Car engine started
car.stop();   // Car engine off, Vehicle stopped
console.info(`${car.getInfo()}`);  // 'Vehicle info, Car model: Tesla'
```

### 子类重写父类方法的冲突处理

子类重写父类方法时，可以通过完全重写或调用`super.方法名()`并添加新逻辑来处理方法冲突。

<!-- @[override_and_extend](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Methods.ets) -->

``` TypeScript
class ExtendLogger {
  log(message: string): void {
    console.info(`[LOG] ${message}`);
  }
}

class DetailedLogger extends ExtendLogger {
  // 重写方法，改变行为
  log(message: string): void {
    console.info(`[DETAIL] ${message}`);
    console.info(`Timestamp: ${new Date().toISOString()}`);
  }
  
  // 保留父类方法并添加新行为
  logWithParent(message: string): void {
    super.log(message);  // 父类方法
    console.info(`Additional info for ${message}`);
  }
  
  // 新方法，不冲突
  logError(error: string): void {
    this.log(`ERROR: ${error}`);
  }
}

let detailed: DetailedLogger = new DetailedLogger();

detailed.log('test');           // [DETAIL] test, Timestamp: ...
detailed.logWithParent('test'); // [LOG] test, Additional info...
detailed.logError('failed');    // [DETAIL] ERROR: failed

// 父类引用
let logger: ExtendLogger = new DetailedLogger();
logger.log('test');  // [DETAIL] test（调用子类重写方法）
```

## 方法的特殊写法与技巧

方法支持箭头函数属性绑定`this`和链式调用等技巧。

### 箭头函数属性作为回调方法（解决this指向丢失问题）

箭头函数方法通过箭头函数语法声明实例方法，自动绑定this到实例对象。

<!-- @[arrow_function_methods](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Methods.ets) -->

``` TypeScript
class Timer {
  private seconds: number = 0;
  
  // 普通方法：this可能丢失
  start(): void {
    mockSetInterval(() => {
      this.tick();  // 箭头函数保持this
    }, 1000);
  }
  
  // 箭头函数方法：this永不丢失
  public tick = (): void => {
    this.seconds++;
    console.info(`${this.seconds}`);
  }
  
  // 箭头函数方法适合作为回调
  public getHandler = (): () => void => {
    return () => {
      console.info(`Timer at ${this.seconds}`);
    };
  }
  
  getSeconds(): number {
    return this.seconds;
  }
}

function mockSetInterval(callback: () => void, ms: number): void {
  callback();
}

let timer: Timer = new Timer();
timer.start();       // 1
timer.tick();        // 2

let handler: () => void = timer.getHandler();
handler();           // 'Timer at 2'

// 箭头函数方法的限制
// 不能使用super
// 不能作为构造函数
// 没有arguments对象
```

### 方法的链式调用实现方案

方法返回this实现链式调用，常用于Builder模式和字符串拼接。

<!-- @[method_chaining](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Methods.ets) -->

``` TypeScript
class StringBuilder {
  private buffer: string = '';
  
  // 链式调用：返回this
  append(text: string): StringBuilder {
    this.buffer += text;
    return this;
  }
  
  prepend(text: string): StringBuilder {
    this.buffer = text + this.buffer;
    return this;
  }
  
  uppercase(): StringBuilder {
    this.buffer = this.buffer.toUpperCase();
    return this;
  }
  
  lowercase(): StringBuilder {
    this.buffer = this.buffer.toLowerCase();
    return this;
  }
  
  // 终结方法：返回结果
  build(): string {
    return this.buffer;
  }
  
  toString(): string {
    return this.buffer;
  }
}

// 链式调用
let chainResult: string = new StringBuilder()
  .append('hello')
  .append(' ')
  .append('world')
  .uppercase()
  .build();

console.info(`${chainResult}`);  // 'HELLO WORLD'

let result2: string = new StringBuilder()
  .prepend('Start: ')
  .append('End')
  .build();

console.info(`${result2}`);  // 'Start: End'
```

### 方法作为参数传递时的this绑定

方法作为参数传递时，需要确保this绑定正确，避免调用时丢失this指向。

<!-- @[method_as_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Methods.ets) -->

``` TypeScript
class EventHandler {
  private name: string;

  constructor(name: string) {
    this.name = name;
  }

  // 普通方法：传递时this可能丢失
  handleClick(): void {
    console.info(`${this.name} clicked`);
  }

  // 箭头函数方法：this保持
  public handleSafeClick = (): void => {
    console.info(`${this.name} safe clicked`);
  }

  // 返回安全回调：用箭头函数包装实例方法
  getClickHandler(): () => void {
    return (): void => {
      this.handleClick();
    };
  }
}

// 模拟事件系统
function mockAddEventListener(callbackHandler: () => void): void {
  callbackHandler();
}

let callbackHandler: EventHandler = new EventHandler('Button');

// 直接传递：this可能丢失
let callbackMethod: () => void = callbackHandler.handleClick;
try {
  callbackMethod();  // 可能丢失this，取决于调用方式
} catch (e) {
  console.info('this丢失');
}

// 使用箭头函数方法
mockAddEventListener(callbackHandler.handleSafeClick);  // 'Button safe clicked'

// 使用显式包装方法
mockAddEventListener(callbackHandler.getClickHandler());  // 'Button clicked'
```

### 可选链调用方法（instance?.method()）

可选链调用使用 ?. 安全地调用可能为null或undefined的对象方法。

<!-- @[optional_chaining_methods](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Methods.ets) -->

``` TypeScript
class OptionalService {
  private available: boolean = true;
  
  process(): void {
    if (this.available) {
      console.info('Processing...');
    }
  }
  
  getData(): string | null {
    return this.available ? 'data' : null;
  }
}

function createOptionalService(available: boolean): OptionalService | null {
  return available ? new OptionalService() : null;
}

let service1: OptionalService | null = createOptionalService(true);
let service2: OptionalService | null = createOptionalService(false);

// 可选链调用方法
service1?.process();  // 'Processing...'
service2?.process();  // 不执行

// 可选链调用并获取返回值
let data1: string | null | undefined = service1?.getData();
console.info(`${data1}`);  // 'data'

let data2: string | null | undefined = service2?.getData();
console.info(`${data2}`);  // undefined

// 结合空值合并
let chainResult2: string = service1?.getData() ?? 'default';
console.info(`${chainResult2}`);  // 'data'

let chainResult22: string = service2?.getData() ?? 'default';
console.info(`${chainResult22}`);  // 'default'

// 可选链的链式调用
class Chain {
  public next?: Chain;
  
  execute(): void {
    console.info('Executed');
  }
}

let chain: Chain | null = new Chain();
chain?.next?.execute();  // 不执行（next未定义）
```

## this参数标注

在方法签名中添加`this`参数，可在编译期强制调用方使用正确的上下文。`this`参数在编译后被擦除，不影响运行时。注意：`this`作为参数名标注是ArkTS支持的，但`this`作为类型（如返回类型`: this`或参数类型`other: this`）不支持。

<!-- @[this_parameter_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Methods.ets) -->

``` TypeScript
class TpThisCounter {
  public count: number = 0;
  increment(this: TpThisCounter): void {
    this.count++;
  }
}

let tpThisCounter: TpThisCounter = new TpThisCounter();
tpThisCounter.increment();
console.info(`${tpThisCounter.count}`); // 1
```

## this is Type类型守卫

方法可返回`this is Type`类型谓词，在if分支中收窄类型。ArkTS中用`instanceof`替代。

**TypeScript对照**

<!-- @[ts_this_type_guard](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Methods.ts) -->

``` TypeScript
// TypeScript的this is T类型守卫，ArkTS不支持（arkts-no-is）
class TsFileSystemObject {
  isFile(): this is TsFileRep {
    return this instanceof TsFileRep;
  }
}

class TsFileRep extends TsFileSystemObject {
  public content: string = '';
}

let tsFsObj: TsFileSystemObject = new TsFileRep();
if (tsFsObj.isFile()) {
  console.info(`${tsFsObj.content}`); // TypeScript通过类型守卫收窄为TsFileRep
}
```

ArkTS中使用`instanceof`替代。

<!-- @[this_guard_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Methods.ets) -->

``` TypeScript
class TgFileSystemObject {
  public path: string;

  constructor(path: string) {
    this.path = path;
  }
}

class TgFileRep extends TgFileSystemObject {
  public content: string = '';

  constructor(path: string) {
    super(path);
  }
}

class TgDirectory extends TgFileSystemObject {
  public children: TgFileSystemObject[] = [];

  constructor(path: string) {
    super(path);
  }
}

function tgProcess(fso: TgFileSystemObject): void {
  if (fso instanceof TgFileRep) {
    console.info(`File: ${fso.content}`);
  } else if (fso instanceof TgDirectory) {
    console.info(`Directory: ${fso.children.length} children`);
  }
}

let tgFile: TgFileRep = new TgFileRep('/readme.txt');
tgFile.content = 'Hello';
tgProcess(tgFile);  // File: Hello
```

## this关键字的使用限制

关键字`this`只能在类的实例方法中使用。

`this`的指向为调用实例方法的对象或正在构造的对象。

ArkTS对`this`有以下使用限制：

- 不支持`this`类型
- 不支持在函数和类的静态方法中使用`this`

**TypeScript对照**

<!-- @[ts_this_usage_limitation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Methods.ts) -->

``` TypeScript
class TsThisLimitA {
  public n: number = 0;
  f1(arg1: this) {} // 编译错误：不支持this类型（arkts-no-typing-with-this）
  static f2(arg1: number): void {
    this.n = arg1;  // 编译错误：不支持在静态方法中使用this
  }
}

function foo(arg1: number) {
  this.n = arg1;    // 编译错误：不支持在函数中使用this
}
```

## 特殊静态成员名称

类本身是函数，不能使用与`Function`原型冲突的静态成员名称。`name`、`length`、`call`等不能用作静态属性名。

**TypeScript对照**

<!-- @[ts_special_static_names](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Methods.ts) -->

``` TypeScript
class TsSsnConfig {
  static version: string = '1.0';

  static name: string = 'Config';  // 编译错误：与Function.name冲突
  static length: number = 0;       // 编译错误：与Function.length冲突

  static getConfigName(): string {
    return 'Config';
  }
}

console.info(`${TsSsnConfig.version}`);
console.info(`${TsSsnConfig.getConfigName()}`);
```

TypeScript和JavaScript没有C#中的`static class`语法。单例对象或顶层函数即可实现相同效果。
