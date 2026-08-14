# Classes

<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=c25b60c237b212cfc232b5aee67d2c42ba90278a translatedAt=2026-08-13T08:55:19.902Z pushedAt=2026-08-13T12:30:02.128Z -->

Classes are a core concept of object-oriented programming, used to encapsulate data and behavior. ArkTS provides full class support, including properties, methods, constructors, inheritance, access control, abstract classes, and other features.

## Basic Concepts

A class is the basic construct of object-oriented programming. It encapsulates data (properties) and behavior (methods), and initializes instances through a constructor.

### Class Definition Syntax

Use the `class` keyword to define a class, and declare properties, constructors, and methods within the braces.

<!-- @[class_basic_definition](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
// Basic class definition
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

// Create an instance
let person: Person = new Person('Alice', 25);
console.info(`${person.greet()}`);

// Empty class
class EmptyClass {
}

let empty: EmptyClass = new EmptyClass();

// Class as a type
function processPerson(person: Person): void {
  console.info(`${person.name}`);
}

processPerson(person);
```

### Core Components of a Class (Properties, Methods, and Construction Logic)

Properties store state, the constructor initializes properties, and methods encapsulate behavior. Together, they form the core structure of a class.

<!-- @[class_properties_methods_constructor](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
class User {
  // Property
  public id: number;
  public name: string;
  public email: string;
  private password: string;
  
  // Constructor
  constructor(id: number, name: string, email: string) {
    this.id = id;
    this.name = name;
    this.email = email;
    this.password = '';
  }
  
  // Method
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

## Class Properties

Class properties describe the state of an object. They are divided into instance properties and static properties, and support default values, read-only properties, and computed properties.

### Stored Properties (Instance Properties and Static Properties)

Stored properties are divided into instance properties (held independently by each instance) and static properties (shared by all instances and accessed through the class name).

<!-- @[static_properties](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
class Counter {
  // Instance property.
  public count: number = 0;
  
  // Static property.
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

// Access the static property through the class name.
console.info(`${Counter.totalInstances.toString()}`);

// Instance properties are accessed through instances.
counter1.increment();
console.info(`${counter1.count.toString()}`);  // 1
console.info(`${counter2.count.toString()}`);  // 0
```

### Computed Properties

A class supports defining computed properties through the `get`/`set` keywords to execute custom logic during read and write operations. For details, see [Property - Computed Property](arkts-language-guide-properties.md).

### Access Control of Properties (public/private/protected)

public, private, and protected control the visibility of class members outside the class and in subclasses.

<!-- @[ts_access_modifiers](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Classes.ts) -->

``` TypeScript
class BankAccount {
  // public: accessible from anywhere
  public accountNumber: string;
  
  // private: accessible only within the class
  private balance: number;
  
  // protected: accessible within the class and its subclasses
  protected ownerName: string;
  
  constructor(accountNumber: string, ownerName: string) {
    this.accountNumber = accountNumber;
    this.ownerName = ownerName;
    this.balance = 0;
  }
  
  // Public method accesses a private property.
  deposit(amount: number): void {
    if (amount > 0) {
      this.balance += amount;
    }
  }
  
  getBalance(): number {
    return this.balance;
  }
  
  // protected method
  protected updateOwner(name: string): void {
    this.ownerName = name;
  }
}

let account: BankAccount = new BankAccount('123', 'Alice');

// public is accessible
console.info(`${account.accountNumber}`);

// private is not accessible
console.info(`${account.balance}`);  // Compilation error

// protected is inaccessible
console.info(`${account.ownerName}`);  // Compilation error

// Access through a method
account.deposit(100);
console.info(`${account.getBalance()}`);  // 100
```

### Declaring Read-Only Properties

A property declared with the `readonly` keyword can be assigned only at its declaration or in the constructor, and cannot be modified afterward.

<!-- @[ts_readonly_properties](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Classes.ts) -->

``` TypeScript
class Configuration {
  // readonly read-only property
  readonly appName: string = 'MyApp';
  readonly version: string;
  
  constructor(version: string) {
    this.version = version;  // Assignable in the constructor.
  }
}

let config: Configuration = new Configuration('1.0.0');

console.info(`${config.appName}`);  // 'MyApp'
console.info(`${config.version}`);   // '1.0.0'

// Read-only property cannot be modified.
config.appName = 'NewApp';  // Compilation error
config.version = '2.0.0';  // Compilation error

// Combine readonly with private
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

## Class Methods

Class methods define object behavior, including instance methods, static methods, and method overloading.

### Defining and Calling Instance Methods

An instance method accesses instance properties through `this` and is called through an object instance.

<!-- @[instance_methods](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
class Calculator {
  public value: number = 0;
  
  // Instance method
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

// Method chaining (return this)
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

### Static Methods

A method declared with the `static` keyword belongs to the class itself. It is called by the class name without instantiation.

<!-- @[ts_static_methods](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Classes.ts) -->

``` TypeScript
class MathUtils {
  // Static method
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

// Call a static method by the class name.
console.info(`${MathUtils.add(1, 2)}`);      // 3
console.info(`${MathUtils.multiply(3, 4)}`); // 12
console.info(`${MathUtils.max(5, 10)}`);     // 10

// Creating an instance does not affect static methods.
let utils: MathUtils = new MathUtils();
utils.add(1, 2);  // Compilation error: an instance cannot call a static method.

// A static method cannot access instance properties.
class StaticExample {
  public instanceValue: number = 10;
  public static staticValue: number = 20;
  
  static getStaticValue(): number {
    return StaticExample.staticValue;  // Can access static properties.
  }
  
  static getInstanceValue(): number {
    return this.instanceValue;  // Compilation error: cannot access instance properties.
  }
}
```

### Method Overloading

Method overloading provides multiple type signatures for the same method name and dispatches the corresponding implementation based on the types of the passed arguments. ArkTS overloading takes the form of multiple overload signatures plus one implementation signature: overload signatures take effect only at compile time for type checking, while the implementation signature is not visible externally, so callers can use only the declared overload signatures. The implementation signature must be compatible with all overload signatures, and the function body uses runtime checks such as `typeof` to distinguish the logic for different argument types.

<!-- @[method_overloading](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
class DataProcessor {
  // Method overload signature
  process(data: string): string;
  process(data: number): number;
  process(data: string | number): string | number {
    if (typeof data === 'string') {
      return data.toUpperCase();
    }
    return data * 2;
  }
  
  // Multi-argument overload
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

## Class Construction and Initialization

A constructor initializes properties when an instance is created with `new`, and supports default parameter values and overloading.

### Class Constructors (Constructor Overloading and Default Parameter Values)

An ArkTS class can have only one constructor implementation, but it supports declaring multiple overload signatures (similar to method overloading). In practice, multiple creation approaches are often provided through optional parameters or static factory methods.

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

In addition to optional parameters, static factory methods are another common pattern for providing multiple creation approaches. They express different construction intents through named methods.

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

### Constructor of a Derived Class

A subclass constructor must call the parent class constructor through `super()` to ensure that the parent class properties are initialized first. For details, see [Inheritance - Constructors in Inheritance](arkts-language-guide-inheritance.md).

### Initialization of Optional Properties

An optional property (?) may be `undefined`, so check it or provide a default value before use.

<!-- @[optional_properties](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
class UserProfile {
  public name: string;
  public age?: number;          // Optional property
  public email?: string;
  public bio?: string;
  
  constructor(name: string) {
    this.name = name;
    // Optional properties do not need to be initialized.
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

// Check before accessing an optional property.
if (profile.email !== undefined) {
  console.info(`${profile.email}`);
}

// Use optional chaining.
let bio: string | undefined = profile.bio;
console.info(`${bio}`);  // undefined
```

## Access Control of Classes

Access modifiers control the accessibility of properties and protect internal data.

### Classification of Access Modifiers

public, private, protected, and readonly can be used individually or in combination to control visibility and writability inside the class, in subclasses, and outside the class.

<!-- @[ts_access_modifiers_summary](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Classes.ts) -->

``` TypeScript
class Example {
  // public: public, accessible anywhere
  public publicProperty: string = 'public';
  
  // private: private, accessible only inside the class
  private privateProperty: string = 'private';
  
  // protected: protected, accessible in the class and its subclasses
  protected protectedProperty: string = 'protected';
  
  // readonly: read-only, cannot be modified after initialization.
  readonly readonlyProperty: string = 'readonly';
  
  // Used in combination.
  private readonly privateReadonly: string = 'private readonly';
  protected readonly protectedReadonly: string = 'protected readonly';
  
  public publicMethod(): void {
    // Can access all properties.
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

// public is accessible.
console.info(`${example.publicProperty}`);
example.publicMethod();

// private is not accessible.
console.info(`${example.privateProperty}`);  // Compilation error.
example.privateMethod();                // Compilation error.

// protected is inaccessible.
console.info(`${example.protectedProperty}`);  // Compilation error.
example.protectedMethod();                // Compilation error.

// readonly is readable but not writable
console.info(`${example.readonlyProperty}`);
example.readonlyProperty = 'new';  // Compilation error.
```

### Scope of Different Access Modifiers

`public` is visible within the class, in subclasses, and outside the class; `private` is visible only within the class; `protected` is visible within the class and in subclasses, but not outside the class.

<!-- @[ts_access_modifiers_inheritance](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Classes.ts) -->

``` TypeScript
class Base {
  public publicValue: number = 1;
  private privateValue: number = 2;
  protected protectedValue: number = 3;
  
  testAccess(): void {
    // All members are accessible within the class.
    console.info(`${this.publicValue}`);
    console.info(`${this.privateValue}`);
    console.info(`${this.protectedValue}`);
  }
}

class Derived extends Base {
  testDerivedAccess(): void {
    // Subclasses can access public and protected members.
    console.info(`${this.publicValue}`);
    console.info(`${this.privateValue}`);  // Compilation error.
    console.info(`${this.protectedValue}`);
  }
}

// External access
let base: Base = new Base();
console.info(`${base.publicValue}`);  // 1 (public accessible)
console.info(`${base.privateValue}`);   // Compilation error
console.info(`${base.protectedValue}`); // Compilation error

let derived: Derived = new Derived();
console.info(`${derived.publicValue}`);  // 1 (public accessible)
```

### Encapsulation Example of Access Control

Properties are private by default, and external access is controlled through public getters and setters.

<!-- @[encapsulation_practice](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
// Encapsulate the internal state and expose the public interface.
class BankAccount {
  private balance: number = 0;
  private accountNumber: string;
  
  constructor(accountNumber: string) {
    this.accountNumber = accountNumber;
  }
  
  // Expose the read interface.
  getBalance(): number {
    return this.balance;
  }
  
  getAccountNumber(): string {
    return this.accountNumber;
  }
  
  // Expose the operation interface.
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

// Use protected for subclass use.
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
    this.logs.push(`${timestamp}: ${message}`);  // protected is accessible.
  }
}

// Use readonly to protect immutable data.
class Configuration {
  public readonly appName: string;
  public readonly maxConnections: number;
  
  constructor(appName: string, maxConnections: number) {
    this.appName = appName;
    this.maxConnections = maxConnections;
  }
}
```

## Class Inheritance

Through the `extends` keyword, a subclass inherits the properties and methods of its parent class, calls `super()` in the constructor to reuse the parent class initialization logic, and can override or add methods to extend the parent class behavior.

### Class Inheritance Syntax

Use the `extends` keyword to let a subclass inherit the properties and methods of its parent class.

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

// Inheritance chain
let chainRect: ChainRectangle = new ChainRectangle('blue', 10, 20);
chainRect.draw();
```

### Method Overriding

A subclass redefines a method of the parent class to implement polymorphism. The `override` keyword marks an overridden method, so that the compiler reports an error when the parent class method is renamed or deleted, preventing the overriding method from being accidentally decoupled from the parent class method. In ArkTS, `override` is an optional keyword. It is recommended that you explicitly mark `override` when overriding a parent class method, so that the compiler can check whether a method with the same name exists in the parent class.

<!-- @[method_override](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
class Base {
  method(): void {
    console.info('Base method');
  }
}

class Derived extends Base {
  // TypeScript uses override to mark the method (optional)
  method(): void {
    console.info('Derived method');
  }
}

let derived: Derived = new Derived();
derived.method();  // 'Derived method'

// Override a method with a return value
class OverrideCalculator {
  calculate(a: number, b: number): number {
    return a + b;
  }
}

class AdvancedCalculator extends OverrideCalculator {
  calculate(a: number, b: number): number {
    return a * b;  // Change the calculation logic
  }
}

let overrideCalc: OverrideCalculator = new AdvancedCalculator();
console.info(`${overrideCalc.calculate(3, 4)}`);  // 12

// Keep the signature consistent when overriding.
class Logger {
  log(message: string): void {
    console.info(`${message}`);
  }
}

class FileLogger extends Logger {
  log(message: string): void {  // The parameter and return types must remain consistent.
    // Write to a file.
    console.info(`[File] ${message}`);
  }
}
```

### Calling the Parent Class Method

In a subclass constructor, `super()` must be the first statement. In a method, call the parent class implementation through `super.method()`.

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
    super.process();  // Call the parent class method.
    console.info('Child processing');
  }
}

let child: Child = new Child();
console.info(`${child.greetWithParent()}`);  
// 'Hello from Parent and Hello from Child'

child.process();
// Output: Parent processing, Child processing

// super in the constructor
class KwBase {
  protected value: number;
  
  constructor(value: number) {
    this.value = value;
  }
}

class Extended extends KwBase {
  public multiplier: number;
  
  constructor(value: number, multiplier: number) {
    super(value);  // Call super first.
    this.multiplier = multiplier;
  }
  
  getCalculated(): number {
    return this.value * this.multiplier;
  }
}
```

### Inheritance Constraints (Single Inheritance)

ArkTS supports only single inheritance. A subclass can extend only one parent class.

**Example (incorrect)**

<!-- @[ts_single_inheritance_limitation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Classes.ts) -->

``` TypeScript
// TypeScript/ArkTS support only single inheritance
class A {
  methodA(): void {}
}

class B {
  methodB(): void {}
}

class CMulti extends A, B {}  // Compilation error: multiple inheritance is not supported
```

Although multiple inheritance is not supported, a class can implement multiple interfaces to combine multiple behavior contracts.

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

When you need to reuse the implementation logic of multiple classes, you can merge them into a base class and then derive subclasses through single inheritance.

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

## Reference Semantics of Classes

Instances of a class are reference types; assignment and parameter passing pass references rather than copies.

### Reference Semantics of Classes (Memory Behavior of Assignment and Copy)

Assigning a class instance or passing it as a parameter passes a reference. Modifying the object pointed to by any variable affects all references. A deep copy must be implemented manually.

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
let person2: CopyPerson = person1;  // Reference assignment, pointing to the same object.

person2.name = 'Bob';
console.info(`${person1.name}`);  // 'Bob' (person1 is also modified)

// A deep copy must be implemented manually.
function copyPerson(source: CopyPerson): CopyPerson {
  return new CopyPerson(source.name, source.age);
}

let person3: CopyPerson = copyPerson(person1);
person3.name = 'Charlie';
console.info(`${person1.name}`);  // 'Bob' (does not affect person1)
console.info(`${person3.name}`);  // 'Charlie'

// Implement the copy method.
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

### Reference Comparison (===/!==)

The `===` operator compares whether two references point to the same object, not whether their contents are identical.

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

// Reference comparison
console.info(`${p1 === p2}`);  // false (different objects)
console.info(`${p1 === p3}`);  // true (same reference)

// A custom method is required for content comparison.
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

### When to Use Classes

A class is suitable for scenarios where data and its operations need to be encapsulated together and where reuse and inheritance are required. An interface is suitable for describing only the shape of a data structure. An object literal is suitable for one-off, simple data organization.

<!-- @[class_vs_interface](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
// Use a class: for scenarios that require encapsulating data and behavior.
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

// Use an interface: for scenarios that only require a data structure.
interface Product {
  id: number;
  name: string;
  price: number;
}

let product: Product = { id: 1, name: 'Item', price: 100 };

// Class vs. object literal
// Class: reusable, with methods, and inheritable.
// Object literal: simple data for one-time use.
```

## Prototype and Inheritance Chain of Classes

The prototype chain is the underlying mechanism of TypeScript inheritance. Class inheritance implements method lookup and type determination through the prototype chain.

### Prototype Object

The `prototype` object stores methods shared by all instances. ArkTS automatically maintains the prototype chain through `class extends` and does not support directly manipulating the `prototype` property.

**TypeScript comparison**

<!-- @[ts_prototype_methods](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Classes.ts) -->

``` TypeScript
// TypeScript comparison. ArkTS does not support assigning to prototype.
class ProtoVehicle {
  public brand: string;
  public speed: number = 0;

  constructor(brand: string) {
    this.brand = brand;
  }

  // Declare the method, with the implementation provided by prototype.
  getInfo(): string {
    return '';
  }
}

// TypeScript supports extending methods through prototype assignment, but ArkTS does not.
ProtoVehicle.prototype.getInfo = function(): string {
  return `${this.brand} - ${this.speed}km/h`;
};

let protoVehicle: ProtoVehicle = new ProtoVehicle('Toyota');
protoVehicle.speed = 60;
console.info(`${protoVehicle.getInfo()}`); // Toyota - 60km/h
```

### Prototype Chain Lookup Mechanism

When accessing an instance member, the engine looks it up level by level along the prototype chain, starting from the instance itself: it first matches the member in the instance's own definition; if no match is found, it searches the parent class and then the grandparent class in turn until a match is found. A member with the same name in a derived class overrides the member in the parent class.

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

// Prototype chain lookup
pcChild.methodA();  // GrandParent (inherited)
pcChild.methodB();  // Parent (inherited)
pcChild.methodC();  // Child (itself)

// Method overriding
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

### Relationship Between Prototype Inheritance and Class Inheritance

Class inheritance is implemented through the prototype chain at the underlying level, and the `instanceof` check matches level by level along the prototype chain.

<!-- @[prototype_inheritance](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Classes.ets) -->

``` TypeScript
// Class inheritance is essentially prototype inheritance.
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

console.info(`${protoDerived.value.toString()}`);         // 10 (inherited property)
console.info(`${protoDerived.getValue().toString()}`);    // 10 (inherited method)
console.info(`${protoDerived.getCalculated().toString()}`); // 20 (own method)

// instanceof checks the prototype chain
console.info(`${(protoDerived instanceof ProtoDerived).toString()}`);  // true
console.info(`${(protoDerived instanceof ProtoBase).toString()}`);     // true
console.info(`${(protoDerived instanceof Object).toString()}`);   // true
```

## Nested Types

Nested types are used to group auxiliary types that serve only a specific outer type, reducing the number of global names. Neither TypeScript nor ArkTS supports declaring a class inside a class; auxiliary types should be declared at the module level alongside the main class.

### Type Grouping

Declare the auxiliary class alongside the main class in the same module, and reflect the ownership relationship through naming.

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

### Referencing the Outer Instance

When a helper class needs to access the instance data of the outer class, pass the reference through the constructor.

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

## Decorators

ArkTS supports class decorators, method decorators, accessor decorators, property decorators, and parameter decorators. Decorator implementations must follow the ArkTS syntax rules: use arrow functions instead of function expressions, explicitly annotate types, and avoid a standalone `this`. The `@Component`, `@Entry`, and state decorators in ArkUI, as well as `@Sendable` and `@Concurrent` in concurrency scenarios, are dedicated decorators defined by the framework or the concurrency model.

### Class Decorator

A class decorator modifies a class declaration through a function and executes the decoration logic when the class is created.

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
// Console output: Class DecoService created
```

### Decorator Factory

A decorator factory returns a decorator function and can accept parameters for configuration.

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
// Console output: Created DecoFactoryService
```

### Method Decorator

A method decorator receives three parameters: `target`, `propertyKey`, and `descriptor`. It can read or modify the method descriptor.

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

### Accessor Decorator

An accessor decorator is used to decorate `get`/`set` accessors. Its parameters are the same as those of a method decorator.

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

### Property Decorator

A property decorator receives two parameters, `target` and `propertyKey`, and is commonly used for marking or injection.

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

### Parameter Decorator

A parameter decorator receives three parameters: `target`, `propertyKey`, and `parameterIndex`. It is commonly used for parameter validation marking.

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

### Implementing Cross-Cutting Logic Through Inheritance or Composition

An alternative to decorators is to implement cross-cutting logic through base class inheritance (injecting logic such as logging into the parent class constructor or methods) or composition (holding a functional object and delegating calls to it).

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

### Implementing Property Listening with Accessors

Use getter/setter accessors to listen for property changes: set the actual field to `private`, and add validation or side-effect logic in the setter.

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

## ES Private Fields and Runtime this

### ES Private Fields (#field)

TypeScript supports private fields prefixed with `#`, providing members that are also private at runtime. Unlike the `private` keyword, `#field` remains private after compilation. In ArkTS, use the `private` modifier instead.

**TypeScript Comparison**

<!-- @[ts_private_fields](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Classes.ts) -->

``` TypeScript
// TypeScript comparison; in ArkTS, use the private modifier instead.
class TsDog {
  #barkAmount: number = 0;
  public personality: string = 'happy';

  bark(): void {
    this.#barkAmount++;
  }
}
```

In ArkTS, use the `private` modifier.

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

`private` is a compile-time check (soft private), while `#field` is also private at runtime (hard private). ArkTS uses the `private` modifier.

### this at Runtime

In TypeScript, the value of `this` depends on how the function is called. When a class method is assigned to a variable and then called, `this` may lose its binding.

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

// Assign the method to a variable and call it; this may lose its binding.
let thisG = thisEx.getName;
```

When a method is assigned to a variable and then called, `this` loses its binding, and calling it directly causes a runtime error.

**TypeScript comparison**

<!-- @[ts_runtime_this_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Classes.ts) -->

``` TypeScript
// TypeScript counterpart, demonstrating the runtime error caused by losing `this`.
class TsThisExample {
  public name: string = 'MyClass';

  getName(): string {
    return this.name;
  }
}

let tsThisEx: TsThisExample = new TsThisExample();
console.info(`${tsThisEx.getName()}`);  // MyClass

let tsThisG = tsThisEx.getName;
tsThisG();  // Runtime error: Cannot read property 'name' of undefined
```

Use an arrow function property to bind `this`, fixing the `this` reference at creation time.

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
arrowH();  // handler (this is correctly bound)
```

An arrow function property has a separate function copy for each instance, and cannot call base class methods through `super`.

### this Parameter Annotation

A method can declare a `this` parameter to statically enforce the type of the calling context. It is erased at compile time and does not affect runtime.

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

### Constructor Signature

You can obtain the instance type from the class itself through `InstanceType<typeof T>`. In ArkTS, use the class name directly as the instance type.

**TypeScript Comparison**

<!-- @[ts_constructor_signature](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Classes.ts) -->

``` TypeScript
// TypeScript comparison; in ArkTS, use the class name directly.
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

### Static Block

A static block (`static { }`) is executed once when the class is loaded. It is suitable for encapsulating static initialization logic that requires error handling, and it can directly access private static fields.

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

You can also use a static method to implement the same initialization logic, controlling the initialization timing through an explicit call:

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

## Relationships Between Classes

In TypeScript, type compatibility between classes is based on structural typing (duck typing): classes with the same structure can substitute for each other even without an explicit inheritance relationship. **ArkTS does not support structural typing**, and assignment between classes requires an explicit inheritance or `implements` relationship.

**TypeScript Comparison**

<!-- @[ts_structural_typing](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Classes.ts) -->

``` TypeScript
// TypeScript structural typing, not supported in ArkTS
class TsRelPoint1 {
  public x: number = 0;
  public y: number = 0;
}

class TsRelPoint2 {
  public x: number = 0;
  public y: number = 0;
}

// Structurally identical, mutually assignable (not supported in ArkTS)
let tsRelP1: TsRelPoint1 = new TsRelPoint2();
let tsRelP2: TsRelPoint2 = new TsRelPoint1();
console.info(`${tsRelP1.x}`);
```

A subtype relationship also does not require explicit inheritance: a class that has all members of a parent class is a subtype of that parent class.

**TypeScript comparison**

<!-- @[ts_structural_subtype](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Classes.ts) -->

``` TypeScript
// TypeScript structural subtyping, not supported in ArkTS
class TsRelPerson {
  public name: string = '';
  public age: number = 0;
}

class TsRelEmployee {
  public name: string = '';
  public age: number = 0;
  public salary: number = 0;
}

// Employee has all members of Person and is a subtype (not supported in ArkTS)
let tsRelP: TsRelPerson = new TsRelEmployee();
console.info(`${tsRelP.name}`);
```

In ArkTS, explicit inheritance is required to achieve assignment compatibility between classes. An empty class has no members, so avoid defining empty classes.

## this Type

The `this` type uses `this` in a method's return value so that the method returns the current instance type, supporting chained calls. When a subclass calls an inherited method, the subclass type is returned. **ArkTS does not support `this` as a type annotation**; use an explicit class name as the return type instead.

**TypeScript comparison**

<!-- @[ts_this_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Classes.ts) -->

``` TypeScript
// TypeScript syntax; ArkTS does not support this as a return type.
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

ArkTS alternative: Use an explicit class name as the return type to implement chained calls.

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

> **NOTE**
> 
> Using `this` as a parameter type (for example, `sameAs(other: this)`) is also not supported. Use an explicit class name as the parameter type instead.

## Parameter Properties

TypeScript supports adding an access modifier (`public`, `private`, `protected`, or `readonly`) before a constructor parameter, and the compiler automatically declares and assigns the corresponding property. **ArkTS does not support the parameter property syntax**.

<!-- @[ts_parameter_properties](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Classes.ts) -->

``` TypeScript
// TypeScript syntax; ArkTS does not support constructor parameter properties
class TsPoint {
  constructor(public x: number, public y: number) {}
}

let tsPt: TsPoint = new TsPoint(3, 4);
console.info(`${tsPt.x}, ${tsPt.y}`); // 3, 4
```

ArkTS alternative: explicitly declare the property and assign it in the constructor.

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

## Class Expressions

TypeScript supports class expressions, which assign a class to a variable, allow the class name to be omitted, and also support generics. **ArkTS does not support class expressions**.

**TypeScript Comparison**

<!-- @[ts_class_expression](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Classes.ts) -->

``` TypeScript
// TypeScript syntax; ArkTS does not support class expressions.
const someClass = class<T> {
  content: T;
  constructor(content: T) {
    this.content = content;
  }
};

let tsInstance = new someClass<string>('hello');
console.info(`${tsInstance.content}`); // hello
```

ArkTS alternative: use a class declaration.

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

The Mixin pattern combines the behaviors of multiple classes through functions, enabling code reuse in languages that do not support multiple inheritance. In TypeScript, Mixins can be implemented through generic functions. **ArkTS does not support the Mixin pattern**. When you need to combine behaviors, use interface implementation or the composition pattern instead.

### TypeScript Mixin Comparison

**TypeScript Comparison**

<!-- @[ts_mixins](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Classes.ts) -->

``` TypeScript
// TypeScript syntax; ArkTS does not support the Mixin pattern.
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

### ArkTS Alternative: Composition Pattern

You can achieve a similar effect through composition (holding instances of other classes within a class), which is more flexible than inheritance.

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

### ArkTS Alternative: Interface Implementation

Define interfaces and have a class implement multiple interfaces to combine multiple behaviors.

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