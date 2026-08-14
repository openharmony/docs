# Interfaces

<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=e25164b4c5d2db315865d228475dc21473dba5fb translatedAt=2026-08-13T09:01:27.006Z pushedAt=2026-08-13T15:16:39.681Z -->

Interfaces are an important way to define the structure of objects in TypeScript/ArkTS. An interface defines a contract of a set of properties and methods, which constrains the shape of an object and enables code decoupling and reuse.

## Basic Concepts of Interfaces

An interface defines the structural contract of an object, specifying property names, types, and optionality without containing implementations. It is used for type constraints and code decoupling.

### Interface Definition and Core Purpose

An interface defines a structural contract for objects—specifying property names, types, and optionality. A class implements an interface to ensure that its instances have the required members.

Interfaces constrain object structures at compile time, decouple module dependencies through unified contracts, and allow multiple classes to reuse the same type definition. They are the core mechanism by which TypeScript/ArkTS achieves loose coupling and type safety.

<!-- @[simple_interface_definition](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
// Define a simple interface.
interface User {
  id: number;
  name: string;
  email: string;
}

// Use an interface to constrain an object.
let user: User = {
  id: 1,
  name: 'Alice',
  email: 'alice@example.com'
};

console.info(user.name); // Alice
```

### Relationship Between Interfaces and Protocols

An interface can serve as a protocol that defines a set of methods and properties that must be implemented, allowing different implementation classes to be invoked in a unified manner.

<!-- @[interface_as_protocol](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
// Define a protocol with an interface.
interface PaymentProtocol {
  // Method that must be implemented.
  processPayment(amount: number): boolean;
  refundPayment(transactionId: string): boolean;
  
  // Property that must be included.
  currency: string;
}

// The class implements the interface protocol.
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

// Use the interface type.
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

### Interface Design Goals

Interface design follows principles such as the Single Responsibility Principle, Interface Segregation Principle, and Dependency Inversion Principle, avoiding overly large interfaces.

The Single Responsibility Principle requires each interface to define only one set of related members; the Interface Segregation Principle avoids forcing implementers to provide methods they do not need; the Dependency Inversion Principle lets high-level modules depend on abstractions rather than concrete implementations; and naming should clearly express the purpose.

<!-- @[interface_segregation_principle](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
// Good design: single responsibility
interface Reader {
  read(): string;
}

interface Writer {
  write(data: string): void;
}

// Good design: interface segregation
interface ReadOnlyRepository<T> {
  findById(id: number): T | null;
  findAll(): T[];
}

interface WriteOnlyRepository<T> {
  save(entity: T): void;
  delete(id: number): void;
}

interface Repository<T> extends ReadOnlyRepository<T>, WriteOnlyRepository<T> {
  // Inherit the read and write interfaces to provide complete functionality.
}

// Poor design: the interface is too large (violates the Interface Segregation Principle).
interface BadRepository<T> {
  findById(id: number): T | null;
  findAll(): T[];
  save(entity: T): void;
  delete(id: number): void;
  batchInsert(entities: T[]): void;
  batchDelete(ids: number[]): void;
  // ... more methods
}
```

## Interface Declaration and Implementation

The `interface` keyword declares the interface structure, and a class implements the interface contract through `implements`.

### Interface Declaration Syntax

Use the `interface` keyword to declare an interface, defining properties (name: type), method signatures, and index signatures to describe the structural contract of an object.

<!-- @[basic_interface_declaration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
// Basic interface declaration
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

### Defining Interface Members

Interface members include properties, methods, and index signatures.

**Property Types**

Interface properties include required properties, optional properties (`?`), and readonly properties (`readonly`).

<!-- @[ts_interface_property_types](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Interfaces.ts) -->

``` TypeScript
interface Product {
    // Required property
  id: number;
  name: string;
  price: number;

  // Optional property (use ?)
  description?: string;
  stock?: number;

  // Readonly property (use readonly)
  readonly createdAt: Date;
}

let product: Product = {
  id: 1,
  name: 'Laptop',
  price: 999,
  createdAt: new Date()
};

// Access the optional property.
if (product.description) {
    console.info(`${product.description}`);
}

// The readonly property cannot be modified.
product.createdAt = new Date(); // Compilation error.
```

**Method declaration**

Interface methods include methods without parameters, methods with parameters, and optional methods (`?`). A class implements interface methods through `implements`.

<!-- @[interface_method_declaration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
interface Calculator {
    // Method declaration (no parameters)
  reset(): void;
  
  // Method declaration (with parameters)
  add(a: number, b: number): number;
  subtract(a: number, b: number): number;
  
  // Optional method
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
  
  // Optional methods can be left unimplemented.
  public logResult(): void {
    console.info(`Result: ${this.result}`);
  }
}

let calculator: BasicCalculator = new BasicCalculator();
let sum: number = calculator.add(10, 5);
console.info(`${sum}`); // 15
```

**Index Signature**

Index signatures allow accessing properties with dynamic keys. ArkTS does not support them (`arkts-no-indexed-signatures`); use `Map` instead.

**TypeScript comparison**

<!-- @[ts_index_signature](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Interfaces.ts) -->

``` TypeScript
// Numeric index signature
interface NumberArray {
  [index: number]: number;
  length: number;
}

let numArray: NumberArray = [1, 2, 3, 4, 5];
console.info(`${numArray[0]}`); // 1

// String index signature.
interface StringDictionary {
  [key: string]: string | number;
  name: string; // Must conform to the index signature type.
  age: number;  // Must conform to the index signature type.
}

let person: StringDictionary = {
  name: 'Alice',
  age: 25,
  city: 'New York',  // Dynamic property.
  country: 'USA'     // Dynamic property.
};

console.info(`${person.city}`); // New York

// Use both index signature types.
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

In ArkTS, use `Map` instead of index signatures to implement dynamic key-value storage:

<!-- @[map_replaces_index_signature](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
// ArkTS alternative: use Map.
let dictMap: Map<string, string | number> = new Map();
dictMap.set('name', 'Alice');
dictMap.set('age', 25);
dictMap.set('city', 'New York');

console.info(`${dictMap.get('city')}`);  // New York
```

### Implementing an Interface with a Class

A class implements an interface using the `implements` keyword and must provide concrete implementations of all members in the interface. Different classes can implement the same interface to provide different behaviors.

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
    // Simulate writing to a file.
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

### Interface Inheritance

An interface can inherit from other interfaces through `extends`, forming a multi-level hierarchy. A child interface contains all members of its parent interface and can add new members.

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

## Interface Inheritance and Composition

Interfaces reuse type definitions through single and multiple inheritance via `extends`, and combine multiple interfaces through intersection types (&).

### Single Inheritance of Interfaces

An interface uses `extends` to inherit a single parent interface. The child interface adds new members on top of the parent interface's members, and an object must satisfy the structures of both the parent and child interfaces.

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

### Multiple Interface Inheritance

An interface can extend multiple parent interfaces to combine multiple type contracts.

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

### Interface Composition Type

An intersection type (`&`) combines multiple interfaces into a composite type that satisfies all constraints. ArkTS does not support intersection types (`arkts-no-intersection-types`). Use interface multiple inheritance instead. For details, see [TypeScript to ArkTS Cookbook](typescript-to-arkts-migration-guide.md#use-inheritance-instead-of-intersection-types).

**TypeScript comparison**

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

// Combine interfaces using an intersection type
type Person = Nameable & Ageable & Emailable;

let composePerson: Person = {
  name: 'Alice',
  age: 25,
  email: 'alice@example.com'
};

console.info(`${composePerson.name}`); // Alice

// Alternative approach: use interface inheritance
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

### Constraints on Interface Inheritance

When an interface inherits another interface, it can add new members and override methods with the same name (keeping the signature consistent), but it cannot change the type of a member inherited from the parent interface; otherwise, a compilation error occurs.

<!-- @[ts_interface_inheritance_rules](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Interfaces.ts) -->

``` TypeScript
interface Base {
  method(): void;
}

interface Derived extends Base {
  // Add new methods.
  newMethod(): void;

  // Override the parent interface method (keeping the same signature).
  method(): void;

  // Do not change the method return type (compilation error).
  method(): string;
}

// Property constraints during interface inheritance
interface Colorable {
  color: string;
}

interface Sized {
  size: number;
}

interface Shape extends Colorable, Sized {
  // You can add new properties.
  area(): number;

  // You cannot redefine properties of the parent interface.
  color: number; // Compilation error: type mismatch.
}
```

## Optional Members of an Interface

Optional members are marked with `?` and can be omitted during implementation.

### Optional Members Based on the optional Modifier

An optional member is marked with `?`, which is placed after the member name in the declaration. The implementing object can omit this member.

<!-- @[optional_properties_methods](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
interface Configuration {
  // Required property.
  apiUrl: string;
  
  // Optional property (using ?).
  timeout?: number;
  retries?: number;
  debugMode?: boolean;
  
  // Optional method.
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

// Use the optional member.
if (config2.timeout) {
  console.info(`Timeout: ${config2.timeout}ms`);
}

if (config2.logError) {
  config2.logError(new Error('Test error'));
}
```

### Declaring Optional Properties and Methods

Optional properties (`?`) and methods indicate that the members may not exist, so check them before access.

<!-- @[optional_members_implementation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
interface Service {
  // Required method
  initialize(): void;
  shutdown(): void;
  
  // Optional method
  preInitialize?(): void;
  postShutdown?(): void;
  
  // Required property
  name: string;
  
  // Optional property.
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
  
  // Optional methods do not need to be implemented.
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

### Calling Notes for Optional Members

Before calling an optional member, check whether it exists to avoid accessing undefined.

<!-- @[using_optional_members](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
interface OptionalInterface {
  requiredMethod(): void;
  optionalMethod?(): void;
  requiredProperty: string;
  optionalProperty?: number;
}

function useOptionalInterface(obj: OptionalInterface): void {
  // Required members can be called directly.
  obj.requiredMethod();
  console.info(`${obj.requiredProperty}`);
  
  // Check whether the optional method exists before calling it.
  if (obj.optionalMethod) {
    obj.optionalMethod();
  }
  
  // Check whether the optional property exists before accessing it.
  if (obj.optionalProperty !== undefined) {
    console.info(`${obj.optionalProperty}`);
  }
  
  // Use the optional chaining operator (?.).
  obj.optionalMethod?.();
  console.info(`${obj.optionalProperty?.toFixed(2)}`);
  
  // Use the nullish coalescing operator (??).
  let value: number = obj.optionalProperty ?? 0;
  console.info(`${value}`);
}
```

### Alternative: Use Interface Extension to Implement Optional Members

By having an extended interface inherit a base interface and add optional members, you can provide a flexible approach that allows different implementers to offer optional capabilities on demand.

<!-- @[extending_interface_with_optionals](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
// Base interface (required members)
interface BaseInterface {
  requiredMethod(): void;
  requiredProperty: string;
}

// Extended interface (with optional members)
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

// Use the base interface
let baseObj: BaseInterface = new BaseInterfaceImpl();

// Use the extended interface (you can choose whether to provide the optional member).
let extendedObj: ExtendedInterface = new ExtendedInterfaceImpl();

// Make the extended interface inherit the base interface.
function processObject(obj: BaseInterface): void {
  obj.requiredMethod();
  console.info(`${obj.requiredProperty}`);
  
  // If an extended interface object is passed in, cast it to the extended interface first and then check the optional member.
  let extended: ExtendedInterface = obj as ExtendedInterface;
  if (extended.optionalMethod !== undefined) {
    extended.optionalMethod();
  }
}

processObject(baseObj);
processObject(extendedObj);
```

## Interfaces with Generic Constraints

A generic interface introduces a type parameter through `<T>` and can use `extends` to constrain the type range, allowing a single interface to adapt to multiple data types.

### Declaring a Generic Interface

Declare a type parameter with `<T>` after the interface name to make the interface applicable to multiple types.

<!-- @[generic_interface](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
// Generic interface
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

### Constraints on Generic Parameters

By constraining a generic parameter with `<T extends SomeType>` to satisfy a specific interface, a generic interface can safely access the members of the constrained type.

<!-- @[generic_constraint_interface](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
interface Lengthwise {
  length: number;
}

// Generic constraint: T must have the length property.
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

### Implementing a Generic Interface

A class implements a generic interface by specifying concrete type arguments (for example, `implements Repository<User>`) and providing concrete implementations for all methods in the interface.

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
      // Update the existing user.
      let index = this.users.indexOf(existingUser);
      this.users[index] = entity;
    } else {
      // Add the new user.
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

### When to Use Generic Interfaces

Generic interfaces are commonly used in scenarios such as generic data structures (Collection), transformers (Mapper/Filter/Reducer), and callback contracts (Callback).

<!-- @[generic_interface_use_cases](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
// Use case 1: Generic data structure
interface Collection<T> {
  add(item: T): void;
  remove(item: T): void;
  contains(item: T): boolean;
  size(): number;
}

// Use case 2: Generic utility interface
interface Mapper<T, U> {
  map(input: T): U;
}

interface Filter<T> {
  filter(predicate: (item: T) => boolean): T[];
}

interface Reducer<T, U> {
  reduce(accumulator: (prev: U, current: T) => U, initial: U): U;
}

// Use case 3: Generic callback interface
interface Callback<T> {
  onSuccess(result: T): void;
  onError(error: Error): void;
}

interface AsyncCallback<T> {
  onSuccess(result: T): Promise<void>;
  onError(error: Error): Promise<void>;
}
```

## Combining Interfaces with Classes

A class implements an interface through `implements`. The interface defines the contract, and the class provides the implementation.

### Implementing a Single Interface

A class uses the `implements` keyword to implement a single interface and must provide concrete implementations of all members of the interface.

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

### Implementing Multiple Interfaces

A class implements multiple interfaces separated by commas (for example, `implements A, B, C`) and must provide implementations for all members of the interfaces.

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

### Inheriting a Class and Implementing Interfaces

A class can use `extends` to inherit from a parent class and `implements` to implement interfaces at the same time, reusing the parent class code while satisfying the interface contract.

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

### Interfaces as Type Constraints for Classes

An interface can be used as a constraint on a generic parameter (for example, `<T extends Comparable<T>>`), restricting the type parameter to types that implement the specified interface, so that interface members can be safely called in generic code.

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

// Use an interface type as a constraint.
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

## Using Interfaces as Types

An interface can be used as a type annotation for a variable to constrain the structure of an object.

### Interface as a Variable Type

An interface name can be used directly as a type annotation for a variable. During assignment, the object literal must contain all required members with matching types, and excess properties are rejected by the compiler.

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

### Interface as Function Parameter/Return Value Type

An interface used as a function parameter and return value type constrains the structure of the input and output.

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

// Use the interface as a parameter type.
function createUser(request: CreateUserRequest): TypesUser {
  return {
    id: Math.floor(Math.random() * 1000),
    name: request.name,
    email: request.email
  };
}

// Use the interface as a return value type.
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

### Polymorphism of Interface Types

A variable of an interface type can point to an instance of any class that implements the interface. When a method with the same name is called, the respective implementation is executed, achieving runtime polymorphism.

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

// Use an interface type to implement polymorphism.
function makeAnimalSpeak(animal: PolyAnimal): void {
  animal.speak();
}

let dog = new PolyDog('Buddy');
let cat = new Cat('Whiskers');
let cow = new Cow('Daisy');

makeAnimalSpeak(dog); // Buddy barks: Woof! Woof!
makeAnimalSpeak(cat); // Whiskers meows: Meow!
makeAnimalSpeak(cow); // Daisy moos: Moo!

// Use an array of interface types.
let animals: PolyAnimal[] = [dog, cat, cow];

animals.forEach(animal => {
    animal.speak();
});
```

### Converting an Interface Type to a Concrete Type

A variable of an interface type can be converted back to a subtype using an `as` assertion after the concrete type is determined with `instanceof`, so that members specific to the implementing class can be accessed.

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

// Convert an interface type to a concrete type (type check required).
function processVehicle(vehicle: CastingVehicle): void {
  console.info(`${vehicle.brand} ${vehicle.model}`);
  
  // Use instanceof to check the type.
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

## Excess Property Checks

When an object literal is assigned to an interface type, ArkTS checks whether it contains properties that are not defined in the interface, which helps detect spelling errors.

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

// Correct
let epSquare1 = createSquare({ color: 'blue', width: 100 });
```

Passing `{ colour: 'red', width: 100 }` (with the misspelled `colour`) triggers a compilation error.

**TypeScript comparison**

<!-- @[ts_excess_property_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Interfaces.ts) -->

``` TypeScript
// TypeScript comparison that demonstrates the compilation error of excess property checking.
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
// Compilation error: 'colour' does not exist in type 'TsSquareConfig'
```

Common ways to bypass excess property checking include type assertion, adding an index signature, or assigning to an intermediate variable first. Most excess property errors are actual bugs and should be fixed first.

## Interface Extension

An interface inherits from other interfaces through `extends` to reuse and combine type definitions.

### Interface Extension Based on interface Extension

Use the `extends` keyword to let one interface inherit the members of another interface.

<!-- @[ts_interface_declaration_merging](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Interfaces.ts) -->

``` TypeScript
// Original interface
interface MergingWindow {
  title: string;
}

// Extended interface (adds a new property)
interface MergingWindow {
  size: { width: number; height: number };
}

// Extended again
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

### Adding Default Method Implementations to Interfaces

Provide default implementations for interface methods through abstract classes or the decorator pattern.

<!-- @[interface_default_implementation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
interface ImplementationLogger {
  log(message: string): void;
  error(message: string): void;
  warn(message: string): void;
}

// A helper class that provides a default implementation.
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

// A custom logger class can inherit the default implementation.
class CustomLogger extends DefaultLogger implements ImplementationLogger {
  private prefix: string;
  
  constructor(prefix: string) {
    super();
    this.prefix = prefix;
  }
  
  // Override the default method.
  public log(message: string): void {
    console.info(`${this.prefix} [LOG] ${message}`);
  }
  
  // Other methods use the default implementation.
}

let customLogger = new CustomLogger('[MyApp]');
customLogger.log('Application started'); // [MyApp] [LOG] Application started
customLogger.error('Something went wrong'); // [ERROR] Something went wrong
```

### When to Use Interface Extension

Interface extension is used to combine types on demand, avoiding the definition of a single large interface.

<!-- @[ts_extending_third_party_interface](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Interfaces.ts) -->

``` TypeScript
// Assume this is an interface defined by a third-party library.
interface PartyThirdPartyConfig {
  apiUrl: string;
  apiKey: string;
}

// Extend the third-party interface with custom properties.
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

Declaration merging can also be performed across modules, where different modules can add members to the same interface separately.

<!-- @[ts_module_interface_merging](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Interfaces.ts) -->

``` TypeScript
// Interface defined by the base module.
interface MergingBaseEntity {
  id: number;
}

// Interface extended by the user module.
interface MergingBaseEntity {
  userId?: number;
  userName?: string;
}

// Interface extended by the product module.
interface MergingBaseEntity {
  productId?: number;
  productName?: string;
}

// An entity can contain properties from different modules.
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

## Differences Between type and interface

Both `type` and `interface` can describe object types, but they differ in extensibility and declaration merging. ArkTS does not support interface declaration merging (`arkts-no-decl-merging`) or intersection types (`arkts-no-intersection-types`); use interface `extends` instead.

**TypeScript comparison**

<!-- @[ts_type_vs_interface](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Interfaces.ts) -->

``` TypeScript
// type can describe union types and tuples
type TvID = number | string;
type TvPair = [string, number];

// interface supports declaration merging (not supported in ArkTS, arkts-no-decl-merging)
interface TvWindow {
  title: string;
}
interface TvWindow {
  ts: string;
}

// interface supports extension.
interface TvAnimal {
  name: string;
}
interface TvDog extends TvAnimal {
  breed: string;
}

// type is extended with an intersection type (not supported in ArkTS, arkts-no-intersection-types).
type TvAnimal2 = { name: string };
type TvDog2 = TvAnimal2 & { breed: string };
```

Recommendation: Prefer `interface` to describe object structures, and use `type` when you need union types, tuples, or primitive type aliases.

## Notes on implements

The `implements` clause checks whether a class satisfies an interface, but it has several important limitations.

**`implements` does not change the class type** — it only performs the check and does not propagate the interface's type information into the class body.

**`implements` does not create optional properties** — implementing an interface that contains optional properties does not create those properties on the instance.

**`implements` checks only the instance side** — static members are not subject to the `implements` check.

<!-- @[implements_cautions](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
interface ImplCheckable {
  check(name: string): boolean;
}

class ImplNameChecker implements ImplCheckable {
  // Parameter types are not inferred from the interface automatically; they must be annotated explicitly.
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
  // y does not have to be implemented, but the y property does not exist on the instance.
}

let implC: ImplC = new ImplC();
console.info(`${implC.x.toString()}`);  // 0
```

`implC.y` does not exist on the instance, and accessing it triggers a compilation error.

**TypeScript comparison**

<!-- @[ts_implements_optional_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Interfaces.ts) -->

``` TypeScript
// TypeScript comparison, demonstrating that implements does not create optional properties.
interface TsImplConfigA {
  x: number;
  y?: number;
}

class TsImplC implements TsImplConfigA {
  public x: number = 0;
}

let tsImplC: TsImplC = new TsImplC();
tsImplC.y = 10;  // Compilation error: Property 'y' does not exist on type 'TsImplC'
```

## Comparison Between Abstract Classes and Interfaces

Neither abstract classes nor interfaces can be instantiated. An abstract class is an abstraction of a class, used to capture the common characteristics of subclasses; an interface is an abstraction of behavior. In ArkTS syntax, the differences between abstract classes and interfaces are as follows:

- A class can inherit from only one abstract class, whereas a class can implement one or more interfaces.

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

- An interface cannot contain static code blocks or static methods, whereas an abstract class can contain static code blocks and static methods.

<!-- @[abstract_vs_interface_static](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
abstract class AviAbstractClass {
  static staticMethod(): void { console.info('static'); }
  static { console.info('static initialization block'); }
}
```

- An abstract class can have method implementations, but an interface has no method implementations and is completely abstract.

An abstract class can have method implementations, while an interface cannot.

<!-- @[abstract_vs_interface_method](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
abstract class AimAbstractClass {
  func(): void { console.info('func'); }
}
```

- An abstract class can have a constructor, while an interface cannot.

An abstract class can have a constructor, while an interface cannot.

<!-- @[abstract_vs_interface_constructor](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Interfaces.ets) -->

``` TypeScript
abstract class AvicAbstractClass {
  constructor() {}
}
```

## Intersection Type

TypeScript supports intersection types (`&`), which combine multiple types into one so that the new type contains all members. ArkTS does not use intersection types; instead, it recommends using interface multiple inheritance (`extends`) as a replacement.

### Interface Extension vs. Intersection Type

In TypeScript, both interface extension and intersection types can combine multiple types, but they behave differently:

- **Interface extension (`extends`)**: A compilation error is reported when properties with the same name are incompatible.

- **Intersection type (`&`)**: When properties with the same name are incompatible, they are merged into `never`.

<!-- @[ts_intersection_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Interfaces.ts) -->

``` TypeScript
// TypeScript intersection type syntax, not supported in ArkTS.
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

ArkTS alternative: interface multiple inheritance.

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

> **NOTE**
>
> In ArkTS, prefer interface multiple inheritance over intersection types. When you need to combine multiple interface constraints, declare a new interface that inherits from multiple interfaces.

## Declaration Merging

TypeScript supports merging declarations with the same name, combining multiple independent declarations into a single definition. ArkTS supports merging namespaces with classes and enums, but does not support interface declaration merging or merging namespaces with functions.

### Interface Merging

**TypeScript comparison**

<!-- @[ts_declaration_merging](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Interfaces.ts) -->

``` TypeScript
// TypeScript syntax. ArkTS does not support interface declaration merging.
interface TsWindow {
  title: string;
}

interface TsWindow {
  count: number;
}

// After merging, TsWindow has both title and count.
let tsWin: TsWindow = { title: 'Main', count: 3 };
console.info(`${tsWin.title}, ${tsWin.count}`); // Main, 3
```

ArkTS alternative: add members directly to the original interface definition, or use interface inheritance to extend it.

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

### Namespace Merging

ArkTS supports merging namespaces with classes and enums to extend static members. Merging namespaces with functions is not supported.