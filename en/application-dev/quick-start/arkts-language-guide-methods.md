# Methods

<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=c25b60c237b212cfc232b5aee67d2c42ba90278a translatedAt=2026-08-13T09:01:15.096Z pushedAt=2026-08-13T15:19:46.621Z -->

Methods define the behavior of a class. ArkTS supports instance methods, static methods, method overloading, and other features.

## Basic Concepts and Classification of Methods

A method is a function defined in a class that describes the behavior of an object. It accesses instance properties through `this` and is classified into instance methods, static methods, and constructors.

### Definition and Purpose of Methods

Methods encapsulate operation logic within a class, access instance state through `this`, and provide external code with an operation interface, enabling reuse while hiding implementation details.

<!-- @[method_definition_basic](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Methods.ets) -->

``` TypeScript
class Calculator {
  public value: number = 0;
  
  // Method definition: perform an operation.
  add(n: number): void {
    this.value += n;
  }
  
  // Method definition: compute the result.
  getValue(): number {
    return this.value;
  }
  
  // Purpose of a method: encapsulate behavior logic.
  reset(): void {
    this.value = 0;
  }
}

let calc: Calculator = new Calculator();
calc.add(10);          // Perform the operation.
console.info(`${calc.getValue().toString()}`);  // 10, the calculation result.
calc.reset();           // Reset the state.
console.info(`${calc.getValue().toString()}`);  // 0
```

### Core Differences Between Instance Methods and Static Methods

An instance method accesses instance properties through `this` and must be called through an instance. A static method belongs to the class itself, is called through the class name, and does not depend on an instance.

<!-- @[ts_instance_vs_static_methods](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Methods.ts) -->

``` TypeScript
class MathOperations {
  // Instance method: called through an instance and accesses instance properties.
  public instanceValue: number = 0;

  addInstanceValue(n: number): void {
    this.instanceValue += n;  // Use this.
  }

  getInstanceValue(): number {
    return this.instanceValue;  // Access the instance property.
  }

  // Static method: called by the class name, accesses static properties.
  static add(a: number, b: number): number {
    return a + b;  // Does not use this.
  }

  static multiply(a: number, b: number): number {
    return a * b;
  }

  public static description: string = 'Math Operations';

  static getDescription(): string {
    return MathOperations.description;  // Accessed by the class name.
  }
}

let math: MathOperations = new MathOperations();

// Instance method: called through an instance.
math.addInstanceValue(10);
console.info(`${math.getInstanceValue()}`);  // 10

// Static method: called by the class name.
console.info(`${MathOperations.add(5, 3)}`);    // 8
console.info(`${MathOperations.multiply(4, 7)}`); // 28

// A static method cannot access instance properties.
let result = MathOperations.getInstanceValue();  // Compilation error.
```

### Relationship and Differences Between Methods and Standalone Functions

A method is attached to a class and can access instance state and private members through `this`; a standalone function is not attached to a class and cannot access instance state. Methods support access modifiers to control visibility.

<!-- @[standalone_function_vs_method](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Methods.ets) -->

``` TypeScript
// Standalone function: not attached to a class
function standaloneAdd(a: number, b: number): number {
  return a + b;
}

// Class method: attached to a class and can access the class's internal state
class Accumulator {
  private total: number = 0;
  
  // Method: can access private state
  add(n: number): void {
    this.total += n;
  }
  
  getTotal(): number {
    return this.total;
  }
  
  // Method advantages: encapsulation and state management
  reset(): void {
    this.total = 0;
  }
}

// Comparison of differences
console.info(`${standaloneAdd(1, 2).toString()}`);  // 3, stateless

let acc: Accumulator = new Accumulator();
acc.add(10);
acc.add(20);
console.info(`${acc.getTotal().toString()}`);  // 30, with state management

// Methods can access private data, but functions cannot
// A standalone function cannot access acc.total (private).
```

## Instance Method

An instance method defines the behavior of an object and is invoked through an instance to perform operations.

### Method Parameters and Return Values

Method parameters receive data passed in by the caller, and return values pass computation results back to the caller. Together, they define the input/output contract of a method.

### Declaration Syntax of Instance Methods

An instance method declaration defines the method name, parameter list, return type, and access modifier. The method is invoked through an instance object of the class.

<!-- @[instance_method_declaration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Methods.ets) -->

``` TypeScript
class Student {
  public name: string;
  public age: number;
  
  constructor(name: string, age: number) {
    this.name = name;
    this.age = age;
  }
  
  // Instance method declaration
  study(): void {
    console.info(`${this.name} is studying`);
  }
  
  // Instance method with parameters
  studyFor(subject: string): void {
    console.info(`${this.name} is studying ${subject}`);
  }
  
  // Instance method with a return value
  getInfo(): string {
    return `${this.name}, ${this.age} years old`;
  }
  
  // Method with a default parameter.
  greet(greeting: string = 'Hello'): string {
    return `${greeting}, I'm ${this.name}`;
  }
}

let student: Student = new Student('Alice', 20);

// Call the instance method.
student.study();               // 'Alice is studying'
student.studyFor('Math');       // 'Alice is studying Math'
console.info(`${student.getInfo()}`); // 'Alice, 20 years old'
console.info(`${student.greet()}`);   // 'Hello, I'm Alice'
console.info(`${student.greet('Hi')}`); // 'Hi, I'm Alice'
```

### Method Invocation

Instance methods are invoked through an instance object (`obj.method()`), while static methods are invoked through the class name (`ClassName.method()`). The two differ in `this` binding and member access.

### Calling an Instance Method (Through an Instance Object)

Call an instance method through `instance.methodName()`. Inside the method body, `this` points to the current instance, allowing access to instance properties and other instance methods.

<!-- @[instance_method_on_separate_instances](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Methods.ets) -->

``` TypeScript
class Logger {
  private logs: string[] = [];
  
  // Instance method
  log(message: string): void {
    this.logs.push(message);
    console.info(`Logged: ${message}`);
  }
  
  // Instance method
  getLogs(): string[] {
    return [...this.logs];
  }
  
  // Instance method
  clear(): void {
    this.logs = [];
    console.info('Logs cleared');
  }
}

// Create an instance.
let logger1: Logger = new Logger();
let logger2: Logger = new Logger();

// Call the method independently on each instance.
logger1.log('Error in module A');
logger1.log('Warning in module B');
logger2.log('Info from module C');

console.info(`${logger1.getLogs().join(', ')}`);  // Error in module A, Warning in module B
console.info(`${logger2.getLogs().join(', ')}`);  // Info from module C

// The method acts on a specific instance.
logger1.clear();
console.info(`${logger1.getLogs().length}`);  // 0
console.info(`${logger2.getLogs().join(', ')}`);  // Info from module C
```

### Rules and Binding Issues of `this` in Instance Methods

In an instance method, the `this` keyword points to the current object instance, but its binding may be lost in certain scenarios.

<!-- @[this_binding_and_arrow_function](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Methods.ets) -->

``` TypeScript
class Counter {
  public count: number = 0;

  // Instance method: `this` points to the instance
  increment(): void {
    this.count++;
    console.info(`${this.count}`);
  }

  // Return a method reference: `this` may be lost
  getIncrementMethod(): () => void {
    return this.increment;  // Method reference
  }

  // Use an arrow function to preserve this.
  getSafeIncrementMethod(): () => void {
    return () => {
      this.count++;  // The arrow function preserves this.
      console.info(`${this.count}`);
    };
  }
}

let counter: Counter = new Counter();

// Normal call: this is correct.
counter.increment();  // 1

// Method reference call: this may be lost.
let method: () => void = counter.getIncrementMethod();
try {
  method();  // this may be lost, depending on how it is called.
} catch (e) {
  console.info('this is lost');
}

// Safe method reference: this is retained
let safeMethod: () => void = counter.getSafeIncrementMethod();
safeMethod();  // 2, this is correct

// Solution: bind this
class Button {
  private onClickHandler: () => void;

  constructor() {
    // Arrow function binds this
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

### Access Control and Concepts of Methods

Access control restricts the accessibility of methods through the `public`/`private`/`protected` modifiers, with the purpose of encapsulating internal implementation details, exposing only stable public interfaces, and reducing coupling between modules. `public` methods constitute the external API of a class, while `private`/`protected` methods are used only internally or by subclasses.

### Access Control of Instance Methods (public/private/protected Modifiers)

The `public`, `private`, and `protected` modifiers restrict the accessibility of methods: `public` methods can be called both inside and outside the class, `private` methods are visible only within the class, and `protected` methods can be accessed by subclasses.

<!-- @[ts_method_access_modifiers](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Methods.ts) -->

``` TypeScript
class Service {
  // public: public method
  public start(): void {
    console.info(`Service started`);
    this.initialize();
  }

  // private: private method, accessible only within the class
  private initialize(): void {
    console.info(`Initializing...`);
    this.loadConfig();
  }

  // protected: protected method, accessible to subclasses
  protected loadConfig(): void {
    console.info(`Loading configuration`);
  }

  // A public method calls a private method.
  public stop(): void {
    this.cleanup();
    console.info(`Service stopped`);
  }

  private cleanup(): void {
    console.info(`Cleaning up resources`);
  }
}

let service: Service = new Service();

// A public method can be called.
service.start();  // Service started, Initializing..., Loading config
service.stop();   // Cleaning up..., Service stopped

// A private method is inaccessible.
service.initialize();  // Compilation error.

// A protected method is inaccessible.
service.loadConfig();  // Compilation error

// Subclass accesses the protected method
class CustomService extends Service {
  configure(): void {
    this.loadConfig();  // Can access protected
  }
}
```

## Static Methods

A static method belongs to the class itself and is called directly through the class name, without depending on an instance.

### Declaring Static Methods

A static method belongs to the class itself rather than to an instance, and is declared with the `static` keyword.

<!-- @[ts_static_method_declaration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Methods.ts) -->

``` TypeScript
class Utility {
  // Static property
  public static version: string = '1.0.0';

  // Static method declaration
  static clamp(value: number, min: number, max: number): number {
    return Math.max(min, Math.min(max, value));
  }

  static formatCurrency(amount: number): string {
    return '$' + amount.toFixed(2);
  }

  static generateId(): string {
    return `ID-${Date.now()}`;
  }

  // Static method accesses a static property
  static getVersion(): string {
    return Utility.version;
  }

  // Static methods cannot access instance properties.
  static getInstanceValue(): number {
    return this.instanceValue;  // Compilation error.
  }
}

// Static methods are called by the class name.
console.info(`${Utility.clamp(15, 0, 10)}`);      // 10
console.info(`${Utility.formatCurrency(123.456)}`); // $123.46
console.info(`${Utility.generateId()}`);          // ID-1234567890
console.info(`${Utility.getVersion()}`);           // 1.0.0

// An instance cannot directly call a static method.
let utility: Utility = new Utility();
utility.clamp(5, 0, 10);  // Compilation error.
```

### Calling Static Methods (Directly by Class Name)

A static method is called directly by class name, without creating an instance object.

<!-- @[ts_static_method_usage_patterns](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Methods.ts) -->

``` TypeScript
class Database {
  private static connectionCount: number = 0;

  // Static method: manages connections.
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

  // Static factory method.
  static createConnection(): Database {
    Database.connect();
    return new Database();
  }
}

// Call the static method by class name.
Database.connect();      // Connected. Total: 1
Database.connect();      // Connected. Total: 2
console.info(`${Database.getConnectionCount()}`);  // 2

Database.disconnect();   // Disconnected. Total: 1
console.info(`${Database.getConnectionCount()}`);  // 1

// Static factory method
let db1: Database = Database.createConnection();
let db2: Database = Database.createConnection();
console.info(`${Database.getConnectionCount()}`);  // 3

// An instance cannot call a static method
db1.connect();  // Compilation error
```

### Characteristics of Static Methods (No this Binding, Associated with Class Lifecycle)

Static methods have two main characteristics: they cannot access the instance `this` binding, and they are directly associated with the lifecycle of the class (rather than the instance). Static initialization blocks (`static { }`) are supported from API version 12.

<!-- @[static_properties_and_initialization](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Methods.ets) -->

``` TypeScript
class Configuration {
  // Static property: class-level data.
  private static settings: Map<string, string> = new Map();
  
  // Static initialization (executed when the class is loaded).
  static {
    Configuration.settings.set('apiUrl', 'EXAMPLE_API_URL');
    Configuration.settings.set('timeout', '5000');
    console.info('Configuration initialized');
  }
  
  // Static method: no this, accesses static properties.
  static get(key: string): string | undefined {
    return Configuration.settings.get(key);
  }
  
  static set(key: string, value: string): void {
    Configuration.settings.set(key, value);
  }
  
  static getAll(): Map<string, string> {
    return new Map(Configuration.settings);
  }
  
  // Static methods exist throughout the class lifecycle.
  static reset(): void {
    Configuration.settings.clear();
    console.info('Configuration reset');
  }
}

// Static initialization is performed when the class is loaded.
console.info(`${Configuration.get('apiUrl')}`);     // EXAMPLE_API_URL
console.info(`${Configuration.get('timeout')}`);    // 5000

Configuration.set('debug', 'true');
console.info(`${Configuration.get('debug')}`);      // true

Configuration.reset();
console.info(`${Configuration.get('apiUrl')}`);     // undefined
```

### Typical Use Cases of Static Methods

Static methods are commonly used for factory methods, the singleton pattern, and utility functions.

<!-- @[static_factory_singleton_utility](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Methods.ets) -->

``` TypeScript
// 1. Factory method
class User {
  private id: number;
  private name: string;

  private constructor(id: number, name: string) {
    this.id = id;
    this.name = name;
  }
  
  // Static factory method
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

// 2. Singleton pattern
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
console.info(`${(s1 === s2).toString()}`);  // true, the same instance

// 3. Utility method
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

## Method Parameter Features

Method parameters support optional, default, and rest forms to receive input flexibly.

### Type Annotation and Default Value Settings for Method Parameters

Method parameters are annotated with data types using `: type` and provided with initial values using `= default value`. ArkTS supports optional parameters (`?`) and rest parameters (`...rest`).

<!-- @[method_parameters_and_defaults](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Methods.ets) -->

``` TypeScript
class EmailSender {
  // Annotate the parameter type.
  send(to: string, subject: string, body: string): void {
    console.info(`Sending to ${to}: ${subject}`);
  }
  
  // Set the default parameter value.
  sendTemplate(to: string, template: string = 'default'): void {
    console.info(`Template ${template} to ${to}`);
  }
  
  // Set multiple default parameters.
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

sender.sendWithOptions('test@example.com');  // Use all default values.
sender.sendWithOptions('test@example.com', 'Important');
sender.sendWithOptions('test@example.com', 'Important', 'high', 'admin@example.com');
```

### Using Rest Parameters (... Spread Syntax)

A rest parameter uses the `...` syntax to collect multiple parameters of the same name into an array, allowing a method to receive a variable number of parameters. It is often used together with regular parameters.

<!-- @[rest_parameters](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Methods.ets) -->

``` TypeScript
class NumberProcessor {
  // Rest parameter: collect multiple parameters.
  sum(...values: number[]): number {
    let total: number = 0;
    for (let value of values) {
      total += value;
    }
    return total;
  }
  
  // Mixed parameters: regular parameters + rest parameter.
  process(base: number, ...modifiers: number[]): number {
    let result: number = base;
    for (let modifier of modifiers) {
      result += modifier;
    }
    return result;
  }
  
  // Rest parameter type.
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

### Alternative to Destructuring Parameters

TypeScript supports destructuring objects directly in method parameters (for example, `move({x, y}: Point, dx: number)`). ArkTS does not support destructuring parameters; instead, receive the object through an interface type parameter and manually extract its properties.

<!-- @[object_parameters](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Methods.ets) -->

``` TypeScript
// ArkTS does not support destructuring parameters. Receive the object through an interface type parameter and manually extract its properties.

class PointOperations {
  move(point: Point, dx: number, dy: number): Point {
    let x: number = point.x;  // Manually extract.
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

### Declaring Optional Parameters (the ? Modifier) and Argument Passing Rules

An optional parameter is declared with the ? modifier, indicating that the argument can be omitted.

<!-- @[optional_parameters](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Methods.ets) -->

``` TypeScript
class DocumentGenerator {
  // Optional parameter: declared with ?
  generate(title: string, author?: string): string {
    if (author !== undefined) {
      return `Title: ${title}, Author: ${author}`;
    }
    return `Title: ${title}`;
  }
  
  // Multiple optional parameters
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
  
  // Optional parameters must follow required parameters
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

## Method Overloading

Method overloading provides multiple signatures and selects different implementations based on parameter types.

### Concept and Implementation of Method Overloading

Method overloading allows the same method name to provide multiple call signatures based on different parameter types or counts, and the compiler automatically matches the appropriate one according to the passed arguments. To implement it, first declare multiple overload signatures, and then use a single implementation signature to cover all cases. Note: The implementation signature is not visible externally; callers can only use the declared overload signatures.

### Declaration Rules for Method Overloading (Same Name, Different Parameters)

Method overloading declares multiple signatures with the same name but different parameters, and finally uses a single implementation signature compatible with all of them for unified handling. When a call is made, the corresponding signature is matched based on the parameter types.

<!-- @[method_overload_signatures](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Methods.ets) -->

``` TypeScript
class DataParser {
  // Overload signature
  parse(data: string): string[];
  parse(data: number): string;
  parse(data: string | number): string | string[] {
    if (typeof data === 'string') {
      return data.split(',');
    }
    return data.toString();
  }
  
  // Overload with multiple parameters
  format(value: number): string;
  format(value: number, precision: number): string;
  format(value: number, precision?: number): string {
    if (precision !== undefined) {
      return value.toFixed(precision);
    }
    return value.toString();
  }
  
  // Overload with different return types
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

### Matching Requirements Between Overload Signatures and the Implementation Signature

The implementation signature of an overload must be compatible with the parameters and return types of all overload signatures. When a call is made, the most specific overload is matched in signature order.

<!-- @[method_overload_implementation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Methods.ets) -->

``` TypeScript
class ImplementationCalculator {
  // Overload signature: defines the public interface.
  calculate(a: number, b: number): number;
  calculate(a: string, b: string): string;
  
  // Implementation signature: must be compatible with all overloads.
  calculate(a: number | string, b: number | string): number | string {
    if (typeof a === 'number' && typeof b === 'number') {
      return a + b;
    }
    if (typeof a === 'string' && typeof b === 'string') {
      return a + b;
    }
    // Handle the unmatched case.
    return 0;
  }
  
  // Overload with a different number of parameters
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

### Restrictions and Notes on Method Overloading

In ArkTS, method overloading is implemented through multiple signature declarations, and attention must be paid to the compatibility between signatures and the implementation.

<!-- @[overload_rules](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Methods.ets) -->

``` TypeScript
class OverloadExample {
  // Overloads must be type-compatible.
  method(x: number): string;
  method(x: string): number;
  method(x: number | string): string | number {
    if (typeof x === 'number') {
      return `Number: ${x}`;
    }
    return x.length;
  }
  
  // Overloads cannot be distinguished by optional parameters alone.
  // method(a: number): void;
  // method(a: number, b?: number): void;  // Conflict
  
  // Overload order: declare the more specific type first.
  handle(value: string): string;      // More specific
  handle(value: number): number;      // More specific
  handle(value: string | number): string | number {  // Implementation signature
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

### Alternatives to Method Overloading

The number of signatures in method overloading should be controlled. When there are too many, use optional parameters or union types instead.

<!-- @[overload_alternatives](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Methods.ets) -->

``` TypeScript
class SafeConverter {
  // Use a static method instead of overloading (clearer)
  static toNumberFromString(value: string): number | null {
    let result: number = Number.parseInt(value, 10);
    return Number.isNaN(result) ? null : result;
  }
  
  static toNumberFromNumber(value: number): number {
    return value;
  }
  
  // Or use union types and type guards
  convert(value: string | number): number | null {
    if (typeof value === 'string') {
      let result: number = Number.parseInt(value, 10);
      return Number.isNaN(result) ? null : result;
    }
    return value;
  }
  
  // Provide different method names for different scenarios
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

## Methods in Inheritance

A subclass automatically inherits the public and protected methods of its parent class, can override parent class methods, and calls the original parent class implementation through `super.methodName()`.

### Inheritance Rules for Parent Class Instance Methods and Static Methods in Subclasses

A subclass inherits the instance methods and static methods of its parent class: instance methods are called through an instance object, with `this` pointing to the subclass instance; static methods are called through the subclass class name and cannot access instance state.

<!-- @[ts_method_inheritance](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Methods.ts) -->

``` TypeScript
class Parent {
  // Instance method: inheritance
  greet(): void {
    console.info(`Hello from Parent`);
  }

  // Static method: inheritance
  static getDescription(): string {
    return 'Parent class';
  }

  // Protected method: accessible in subclasses
  protected internalMethod(): void {
    console.info(`Internal method`);
  }
}

class Child extends Parent {
  // Inherit the parent class instance method.
  callParentGreet(): void {
    this.greet();  // Inherited instance method.
  }

  // Inherit the parent class static method.
  static getParentDescription(): string {
    return Parent.getDescription();  // Inherited static method.
  }

  // Access the parent class protected method.
  callInternal(): void {
    this.internalMethod();  // Accessible
  }
}

let child: Child = new Child();

child.greet();              // 'Hello from Parent' (inherited)
child.callParentGreet();    // 'Hello from Parent'
console.info(`${Parent.getDescription()}`);  // 'Parent class'
console.info(`${Child.getDescription()}`);   // 'Parent class' (inherited)
child.callInternal();       // 'Internal method'

// Note: Static methods cannot be accessed through an instance.
child.getDescription();  // Compilation error.
```

### Syntax of Method Overriding

Method overriding is the process in which a subclass redefines the implementation of a parent class method to modify or extend the parent class behavior.

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
  // Override the method (the override keyword is optional in TypeScript).
  speak(): string {
    return 'Dog barks';
  }
  
  // Override and extend the parent class method.
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

// A parent class reference points to a subclass instance.
let animal: Animal = new Dog();
console.info(`${animal.speak()}`);  // 'Dog barks' (dynamic binding)
```

### Access Level Restrictions on Overriding Methods

An overriding method cannot reduce the access level of the parent class method; it can only maintain or raise the access level.

<!-- @[ts_override_access_modifiers](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Methods.ts) -->

``` TypeScript
class Base {
  // public method
  public publicMethod(): void {
    console.info(`Base public`);
  }

  // protected method
  protected protectedMethod(): void {
    console.info(`Base protected`);
  }

  // private method (cannot be overridden)
  private privateMethod(): void {
    console.info(`Base private`);
  }

  protected loweredPublicMethod(): void {}
}

class Derived extends Base {
  // Override the public method: keep it public.
  public publicMethod(): void {
    console.info(`Derived public`);
  }

  // Override the protected method: keep it protected or change it to public.
  public protectedMethod(): void {
    console.info(`Derived public (was protected)`);
  }

  // Cannot override a private method.
  private privateMethod(): void {}  // Compilation error.

  // Cannot lower the access level.
  private loweredPublicMethod(): void {}  // Compilation error: cannot change from protected to private.

  callProtected(): void {
    this.protectedMethod();  // The parent class protected member is accessible.
  }
}

let derived: Derived = new Derived();
derived.publicMethod();        // 'Derived public'
derived.protectedMethod();     // 'Derived public (was protected)'
derived.callProtected();       // 'Base protected'
```

### Calling a Parent Class Method with the super Keyword

The `super` keyword is used to call the method of the same name in the parent class from a subclass method, enabling method extension and function reuse.

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
    super.start();  // Call the parent class method.
    console.info('Car engine started');
  }
  
  stop(): void {
    console.info('Car engine off');
    super.stop();  // Call the parent class method.
  }
  
  getInfo(): string {
    return `${super.getInfo()}, Car model: Tesla`;  // Extend the parent class return value.
  }
  
  // Additional method.
  accelerate(): void {
    console.info('Car accelerating');
  }
}

let car: Car = new Car();

car.start();  // Vehicle starting..., Car engine started
car.stop();   // Car engine off, Vehicle stopped
console.info(`${car.getInfo()}`);  // 'Vehicle info, Car model: Tesla'
```

### Handling Conflicts When a Subclass Overrides a Parent Class Method

When a subclass overrides a parent class method, method conflicts can be handled by fully overriding the method or by calling `super.methodName()` and adding new logic.

<!-- @[override_and_extend](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Methods.ets) -->

``` TypeScript
class ExtendLogger {
  log(message: string): void {
    console.info(`[LOG] ${message}`);
  }
}

class DetailedLogger extends ExtendLogger {
  // Override the method to change its behavior.
  log(message: string): void {
    console.info(`[DETAIL] ${message}`);
    console.info(`Timestamp: ${new Date().toISOString()}`);
  }
  
  // Keep the parent class method and add new behavior.
  logWithParent(message: string): void {
    super.log(message);  // Parent class method.
    console.info(`Additional info for ${message}`);
  }
  
  // New method, no conflict.
  logError(error: string): void {
    this.log(`ERROR: ${error}`);
  }
}

let detailed: DetailedLogger = new DetailedLogger();

detailed.log('test');           // [DETAIL] test, Timestamp: ...
detailed.logWithParent('test'); // [LOG] test, Additional info...
detailed.logError('failed');    // [DETAIL] ERROR: failed

// Parent class reference.
let logger: ExtendLogger = new DetailedLogger();
logger.log('test');  // [DETAIL] test (calls the overridden method in the subclass)
```

## Special Method Writing Styles and Techniques

Methods support techniques such as binding `this` through arrow function properties and chaining.

### Arrow Function Property as a Callback Method (Resolving the Loss of this Binding)

An arrow function method declares an instance method using arrow function syntax, automatically binding `this` to the instance object.

<!-- @[arrow_function_methods](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Methods.ets) -->

``` TypeScript
class Timer {
  private seconds: number = 0;
  
  // Regular method: this may be lost.
  start(): void {
    mockSetInterval(() => {
      this.tick();  // The arrow function preserves this.
    }, 1000);
  }
  
  // Arrow function method: this is never lost.
  public tick = (): void => {
    this.seconds++;
    console.info(`${this.seconds}`);
  }
  
  // Arrow function methods are suitable for use as callbacks.
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

// Limitations of arrow function methods
// super cannot be used.
// Cannot be used as a constructor.
// There is no arguments object.
```

### Implementing Method Chaining

A method returns `this` to implement method chaining, which is commonly used in the Builder pattern and string concatenation.

<!-- @[method_chaining](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Methods.ets) -->

``` TypeScript
class StringBuilder {
  private buffer: string = '';
  
  // Chaining call: return this.
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
  
  // Terminal method: return the result.
  build(): string {
    return this.buffer;
  }
  
  toString(): string {
    return this.buffer;
  }
}

// Chaining call
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

### this Binding When a Method Is Passed as a Parameter

When a method is passed as a parameter, ensure that the `this` binding is correct to avoid losing the `this` reference when the method is called.

<!-- @[method_as_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Methods.ets) -->

``` TypeScript
class EventHandler {
  private name: string;

  constructor(name: string) {
    this.name = name;
  }

  // Regular method: `this` may be lost when passed.
  handleClick(): void {
    console.info(`${this.name} clicked`);
  }

  // Arrow function method: `this` is preserved.
  public handleSafeClick = (): void => {
    console.info(`${this.name} safe clicked`);
  }

  // Return a safe callback: wrap the instance method with an arrow function.
  getClickHandler(): () => void {
    return (): void => {
      this.handleClick();
    };
  }
}

// Simulate the event system.
function mockAddEventListener(callbackHandler: () => void): void {
  callbackHandler();
}

let callbackHandler: EventHandler = new EventHandler('Button');

// Direct passing: this may be lost.
let callbackMethod: () => void = callbackHandler.handleClick;
try {
  callbackMethod();  // this may be lost, depending on how it is called.
} catch (e) {
  console.info('this is lost');
}

// Use the arrow function method.
mockAddEventListener(callbackHandler.handleSafeClick);  // 'Button safe clicked'

// Use an explicit wrapper method.
mockAddEventListener(callbackHandler.getClickHandler());  // 'Button clicked'
```

### Optional Chaining Method Call (instance?.method())

Optional chaining uses ?. to safely call methods on objects that may be null or undefined.

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

// Call a method using optional chaining.
service1?.process();  // 'Processing...'
service2?.process();  // Not executed.

// Call a method using optional chaining and obtain the return value.
let data1: string | null | undefined = service1?.getData();
console.info(`${data1}`);  // 'data'

let data2: string | null | undefined = service2?.getData();
console.info(`${data2}`);  // undefined

// Combine with nullish coalescing.
let chainResult2: string = service1?.getData() ?? 'default';
console.info(`${chainResult2}`);  // 'data'

let chainResult22: string = service2?.getData() ?? 'default';
console.info(`${chainResult22}`);  // 'default'

// Chained calls with optional chaining.
class Chain {
  public next?: Chain;
  
  execute(): void {
    console.info('Executed');
  }
}

let chain: Chain | null = new Chain();
chain?.next?.execute();  // Not executed (next is undefined).
```

## this Parameter Annotation

Adding a `this` parameter to a method signature enforces the correct context for callers at compile time. The `this` parameter is erased after compilation and does not affect runtime behavior. Note: ArkTS supports `this` as a parameter name annotation, but does not support `this` as a type (for example, the return type `: this` or the parameter type `other: this`).

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

## this is Type Type Guard

A method can return a `this is Type` type predicate to narrow the type in an `if` branch. In ArkTS, use `instanceof` instead.

**TypeScript Comparison**

<!-- @[ts_this_type_guard](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Methods.ts) -->

``` TypeScript
// TypeScript's `this is T` type guard, which ArkTS does not support (arkts-no-is).
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
  console.info(`${tsFsObj.content}`); // TypeScript narrows the type to TsFileRep through the type guard.
}
```

In ArkTS, use `instanceof` instead.

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

## Restrictions on Using the this Keyword

The `this` keyword can be used only in instance methods of a class.

`this` refers to the object that calls the instance method or the object being constructed.

ArkTS imposes the following restrictions on the use of `this`:

- The `this` type is not supported.

- `this` is not supported in functions and static methods of classes.

**TypeScript comparison**

<!-- @[ts_this_usage_limitation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Methods.ts) -->

``` TypeScript
class TsThisLimitA {
  public n: number = 0;
  f1(arg1: this) {} // Compilation error: the this type is not supported (arkts-no-typing-with-this).
  static f2(arg1: number): void {
    this.n = arg1;  // Compilation error: this is not supported in static methods.
  }
}

function foo(arg1: number) {
  this.n = arg1;    // Compilation error: this is not supported in functions.
}
```

## Special Static Member Names

A class itself is a function, so static member names that conflict with the `Function` prototype cannot be used. Names such as `name`, `length`, and `call` cannot be used as static property names.

**TypeScript Comparison**

<!-- @[ts_special_static_names](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Methods.ts) -->

``` TypeScript
class TsSsnConfig {
  static version: string = '1.0';

  static name: string = 'Config';  // Compilation error: conflicts with Function.name.
  static length: number = 0;       // Compilation error: conflicts with Function.length.

  static getConfigName(): string {
    return 'Config';
  }
}

console.info(`${TsSsnConfig.version}`);
console.info(`${TsSsnConfig.getConfigName()}`);
```

TypeScript and JavaScript do not have the `static class` syntax found in C#. A singleton object or a top-level function can achieve the same effect.