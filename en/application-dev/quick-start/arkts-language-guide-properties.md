# Properties

<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=c25b60c237b212cfc232b5aee67d2c42ba90278a translatedAt=2026-08-13T09:03:36.381Z pushedAt=2026-08-13T13:32:52.759Z -->

Properties are components of a class, used to store data and define how the data is accessed. ArkTS provides multiple property types and access control mechanisms.

## Property Classification and Basic Concepts

A property is a member of a class that stores data. Properties are classified into instance properties (independent for each instance) and static properties (shared by all instances), and support read-only, computed, and access control.

### Definition and Purpose of Properties

A property is declared in the form `modifier name: type = initial value`. It can be initialized at the declaration site or in the constructor, and is accessed through `instance.property name`. Optional properties are marked with `?`, and read-only properties with `readonly`.

<!-- @[property_definition_basics](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Properties.ets) -->

``` TypeScript
class Person {
  // Property definition: stores data
  public name: string;         // Name property
  public age: number;          // Age property
  public email?: string;       // Optional property
  
  constructor(name: string, age: number) {
    this.name = name;
    this.age = age;
  }
  
  // Purpose of properties: encapsulate data and provide access interfaces.
  getInfo(): string {
    return `${this.name}, ${this.age} years old`;
  }
}

let person: Person = new Person('Alice', 25);
console.info(`${person.name}`);  // 'Alice'
console.info(`${person.age.toString()}`);   // 25

// Properties are used to store state.
class Counter {
  public count: number = 0;  // Stores the count state.
  
  increment(): void {
    this.count++;  // Manages state through the property.
  }
  
  getCount(): number {
    return this.count;
  }
}

let counter: Counter = new Counter();
counter.increment();
console.info(`${counter.getCount().toString()}`);  // 1
```

### Differences Between Instance Properties and Static Properties

Instance properties and static properties are the two types of class properties. They differ significantly in how they are accessed (instance properties are accessed through a class instance, while static properties are accessed directly through the class name) and in their lifecycle (instance properties exist as long as the instance exists, while static properties exist when the class is loaded).

<!-- @[instance_vs_static_properties](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Properties.ets) -->

``` TypeScript
class Configuration {
  // Instance property: owned independently by each instance
  public name: string;
  public value: number;
  
  // Static property: shared by all instances
  public static version: string = '1.0.0';
  public static instanceCount: number = 0;
  
  constructor(name: string, value: number) {
    this.name = name;
    this.value = value;
    Configuration.instanceCount++;
  }
  
  // Instance method accesses the instance property
  getInfo(): string {
    return `${this.name}: ${this.value}`;
  }
  
  // Static methods access static properties.
  static getVersion(): string {
    return Configuration.version;
  }
  
  static getInstanceCount(): number {
    return Configuration.instanceCount;
  }
}

let config1: Configuration = new Configuration('A', 10);
let config2: Configuration = new Configuration('B', 20);

// Instance properties are independent.
console.info(`${config1.name}`);  // 'A'
console.info(`${config2.name}`);  // 'B'

// Static properties are shared.
console.info(`${Configuration.version}`);       // '1.0.0'
console.info(`${Configuration.instanceCount}`); // 2

// Instances access instance properties through this.
// Static members access static properties through the class name.
```

## Stored Properties

A stored property allocates a field on an instance or a class to hold a data value. It is classified into instance stored properties and static stored properties, and serves as the primary carrier of object state.

### Declaring and Initializing Instance Stored Properties

An instance stored property is the most basic property type in a class. It directly stores the data value of an object and must be initialized at declaration or in the constructor.

<!-- @[property_initialization_methods](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Properties.ets) -->

``` TypeScript
class User {
  // Initialize at declaration
  public id: number = 0;
  public name: string = '';
  public active: boolean = true;
  
  // Initialize in the constructor
  constructor(id?: number, name?: string) {
    if (id !== undefined) {
      this.id = id;
    }
    if (name !== undefined) {
      this.name = name;
    }
  }
  
  // Deferred initialization
  public email: string | null = null;
  
  setEmail(email: string): void {
    this.email = email;  // Deferred assignment
  }
}

let user1: User = new User();
console.info(`${user1.id}`);    // 0
console.info(`${user1.name}`);  // ''

let user2: User = new User(1, 'Alice');
console.info(`${user2.id}`);    // 1
console.info(`${user2.name}`);  // 'Alice'

// Deferred initialization
user2.setEmail('alice@example.com');
console.info(`${user2.email}`);  // 'alice@example.com'
```

### Static Stored Properties

A static stored property is declared with the `static` keyword. It belongs to the class itself rather than to an instance, and all instances share the same static property value.

<!-- @[ts_static_storage_properties](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Properties.ts) -->

``` TypeScript
class Constants {
  // Static stored property
  public static readonly MAX_VALUE: number = 100;
  public static readonly MIN_VALUE: number = 0;
  public static DEFAULT_TIMEOUT: number = 5000;

  // Static property can be modified
  public static counter: number = 0;

  static increment(): void {
    Constants.counter++;
  }
}

// Access a static property through the class name
console.info(`${Constants.MAX_VALUE}`);  // 100
console.info(`${Constants.MIN_VALUE}`);  // 0
console.info(`${Constants.DEFAULT_TIMEOUT}`);  // 5000

// A non-read-only static property can be modified.
Constants.increment();
console.info(`${Constants.counter}`);  // 1

// An instance cannot access a static property.
let constants: Constants = new Constants();
console.info(`${constants.MAX_VALUE}`);  // Compilation error.
```

### Read-only Stored Property (readonly Modifier)

A read-only property is a property that cannot be modified. It ensures that the property remains unchanged after creation, improving code safety. A read-only property is declared with the `readonly` modifier. It can be assigned only at declaration or in the constructor, and cannot be modified afterward.

<!-- @[ts_readonly_instance_properties](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Properties.ts) -->

``` TypeScript
class ImmutablePoint {
  // readonly read-only property
  public readonly x: number;
  public readonly y: number;

  constructor(x: number, y: number) {
    this.x = x;  // Can be assigned in the constructor.
    this.y = y;
  }

  // Read-only property cannot be modified.
  move(dx: number, dy: number): void {
    this.x += dx;  // Compilation error
    this.y += dy;  // Compilation error
  }

  // Returns a new instance instead of modifying
  translate(dx: number, dy: number): ImmutablePoint {
    return new ImmutablePoint(this.x + dx, this.y + dy);
  }
}

let point: ImmutablePoint = new ImmutablePoint(10, 20);
console.info(`${point.x}`);  // 10
console.info(`${point.y}`);  // 20

// Read-only properties cannot be modified
point.x = 15;  // Compilation error

// Return a new instance.
let newPoint: ImmutablePoint = point.translate(5, 5);
console.info(`${newPoint.x}`);  // 15
console.info(`${newPoint.y}`);  // 25

// The original instance remains unchanged.
console.info(`${point.x}`);  // 10
```

Combining `readonly` with `static` allows you to define class-level immutable constants.

<!-- @[ts_static_readonly_constants](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Properties.ts) -->

``` TypeScript
// Combine readonly with static.
class AppConfig {
  public static readonly APP_NAME: string = 'MyApp';
  public static readonly VERSION: string = '1.0.0';
}

console.info(`${AppConfig.APP_NAME}`);   // 'MyApp'
console.info(`${AppConfig.VERSION}`);    // '1.0.0'

AppConfig.APP_NAME = 'NewApp';  // Compilation error.
```

### Access Control for Stored Properties

Stored properties can be restricted in their accessible scope using the `public`, `private`, and `protected` modifiers, all of which can be combined with `readonly`. For details and examples of access control, see [Access Control of Properties](#access-control-of-properties).

<!-- @[ts_property_access_modifiers](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Properties.ts) -->

``` TypeScript
class BankAccount {
  // public: public access
  public accountNumber: string;

  // private: private access
  private balance: number;

  // protected: protected access
  protected ownerName: string;

  // readonly + private
  private readonly createdAt: Date;

  constructor(accountNumber: string, ownerName: string) {
    this.accountNumber = accountNumber;
    this.ownerName = ownerName;
    this.balance = 0;
    this.createdAt = new Date();
  }

  // Public method accesses the private property.
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

  // Protected method.
  protected setOwnerName(name: string): void {
    this.ownerName = name;
  }
}

let account: BankAccount = new BankAccount('ACC-001', 'Alice');

// Public: accessible.
console.info(`${account.accountNumber}`);  // 'ACC-001'

// Private: inaccessible.
console.info(`${account.balance}`);  // Compilation error.

// protected is inaccessible
console.info(`${account.ownerName}`);  // Compilation error

// Access the private property through a public method
account.deposit(100);
console.info(`${account.getBalance()}`);  // 100

// The subclass accesses the protected property
class PremiumAccount extends BankAccount {
  updateOwner(newOwner: string): void {
    this.setOwnerName(newOwner);  // The subclass can access the protected method
  }
}
```

## Computed Property

A computed property controls the read and assignment logic of a property through getters and setters.

### Concept and Purpose of getter/setter

Getters and setters are accessors of a computed property. They control the read and write behavior of the property and serve as the core syntax for implementing computed properties.

### Syntax of Computed Properties (get/set Accessors)

Use the `get` keyword to define a read accessor and the `set` keyword to define a write accessor. They are accessed like ordinary properties, but the values are dynamically evaluated through methods under the hood.

<!-- @[getter_setter_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Properties.ets) -->

``` TypeScript
class Circle {
  private _radius: number = 0;
  
  // getter: Obtains the computed value.
  get radius(): number {
    return this._radius;
  }
  
  // setter: Sets the value and validates it.
  set radius(value: number) {
    if (value >= 0) {
      this._radius = value;
    }
  }
  
  // computed property: Calculated based on other properties.
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

// Set through the setter.
circle.radius = 5;
console.info(`${circle.radius}`);      // 5

// The computed property updates automatically.
console.info(`${circle.area}`);        // ~78.54
console.info(`${circle.diameter}`);    // 10
console.info(`${circle.circumference}`); // ~31.42

// The setter has validation logic.
circle.radius = -5;  // Invalid, not set.
console.info(`${circle.radius}`);      // 5 (original value retained)
```

### Read-only Computed Property (Getter Only)

A read-only computed property provides only a getter and no setter. The property can only be read but not written, which ensures secure property access.

<!-- @[ts_readonly_computed_properties](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Properties.ts) -->

``` TypeScript
class Rectangle {
  public width: number = 0;
  public height: number = 0;

  // Read-only computed property: getter only
  get area(): number {
    return this.width * this.height;
  }

  get perimeter(): number {
    return 2 * (this.width + this.height);
  }

  // No setter; area cannot be set directly
  // set area(value: number) { }  // Not provided
}

let rect: Rectangle = new Rectangle();
rect.width = 10;
rect.height = 20;

console.info(`${rect.area}`);       // 200
console.info(`${rect.perimeter}`);  // 60

// Cannot set a computed property.
rect.area = 100;  // Compilation error

// Affect the computed property by modifying the source property.
rect.width = 5;
console.info(`${rect.area}`);  // 100 (automatically updated)
```

### Differences Between Computed Properties and Stored Properties

A stored property allocates a field to store its value, while a computed property does not allocate a field and instead evaluates its value dynamically through a getter on each access. Computed properties are suitable for derived data, such as a full name composed of a first name and a last name.

<!-- @[stored_vs_computed_properties](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Properties.ets) -->

``` TypeScript
class Temperature {
  // Stored property: stores the value directly.
  public celsius: number = 0;
  
  // Computed property: calculated based on the stored property.
  get fahrenheit(): number {
    return this.celsius * 9 / 5 + 32;
  }
  
  set fahrenheit(value: number) {
    this.celsius = (value - 32) * 5 / 9;
  }
  
  // Stored property: requires storage space.
  // Computed property: requires no storage space and is computed dynamically
  
  // Stored property: assigned directly
  // Computed property: accessed through getter/setter
}

let temp: Temperature = new Temperature();

// Set the stored property
temp.celsius = 25;
console.info(`${temp.celsius}`);      // 25
console.info(`${temp.fahrenheit}`);   // 77

// Set the computed property, which affects the stored property
temp.fahrenheit = 100;
console.info(`${temp.celsius}`);      // ~37.78
console.info(`${temp.fahrenheit}`);   // 100
```

### When to Use Computed Properties

Computed properties have several typical use cases, such as data composition, format conversion, validation control, and derived calculation.

<!-- @[computed_property_combination](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Properties.ets) -->

``` TypeScript
class ComboUser {
  public firstName: string = '';
  public lastName: string = '';
  
  // Computed property: combines multiple properties
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

// Computed property for validation and conversion
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

## Property Observer (Simulated Implementation)

A property observer monitors property changes and executes custom logic before and after setting.

### Simulating Property Observation in TypeScript

TypeScript/ArkTS has no native property observer. To simulate property change observation, compare the old and new values in the getter/setter and trigger a listener.

<!-- @[property_observer_simulation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Properties.ets) -->

``` TypeScript
// TypeScript/ArkTS has no native property observer
// Simulate it through getter/setter

class ObservableValue {
  private _value: number = 0;
  private _listeners: ((value: number) => void)[] = [];
  
  get value(): number {
    return this._value;
  }
  
  set value(newValue: number) {
    let oldValue: number = this._value;
    this._value = newValue;
    
    // Trigger the listener
    if (oldValue !== newValue) {
      this.notifyListeners(newValue);
    }
  }
  
  // Add a listener.
  addListener(listener: (value: number) => void): void {
    this._listeners.push(listener);
  }
  
  // Remove a listener.
  removeListener(listener: (value: number) => void): void {
    let index: number = this._listeners.indexOf(listener);
    if (index >= 0) {
      this._listeners.splice(index, 1);
    }
  }
  
  // Notify all listeners.
  private notifyListeners(value: number): void {
    for (let listener of this._listeners) {
      listener(value);
    }
  }
}

let observable: ObservableValue = new ObservableValue();

// Add a listener.
observable.addListener((value: number): void => {
  console.info(`Value changed to ${value}`);
});

// Set the value to trigger listeners.
observable.value = 10;  // Output: Value changed to 10
observable.value = 20;  // Output: Value changed to 20
observable.value = 20;  // No output (same value)
```

### Implementing Property Change Detection Based on get/set

Compare the old and new values in the setter, and execute custom logic (such as logging or notification) only when the value changes, thereby implementing on-demand detection of property changes.

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
  
  // Manually trigger change detection.
  checkChange(): void {
    console.info(`Current value: ${this._data}`);
  }
}

let watched: WatchedProperty = new WatchedProperty();
watched.data = 'Hello';  // Output: Property changed from '' to 'Hello'
watched.data = 'Hello';  // No output (same value)
watched.data = 'World';  // Output: Property changed from 'Hello' to 'World'

// Triggered during batch updates.
class BatchUpdate {
  private _items: string[] = [];
  
  get items(): string[] {
    return [...this._items];  // Return a copy.
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

### Implementing Property Observation Based on Decorators

The ArkTS decorator system differs from the experimental decorators in TypeScript. Property observation does not wrap the `get`/`set` descriptors with decorators; instead, it implements the observer pattern manually by comparing the old and new values in the `set` method and triggering the callback. For details, see [decorators](arkts-language-guide-classes.md#decorators).

<!-- @[manual_property_observation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Properties.ets) -->

``` TypeScript
// Property observer: compares the old and new values in the set method and triggers the callback.

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
observed.value = 10;  // Output: Value: 0 -> 10
observed.value = 20;  // Output: Value: 10 -> 20
```

## Comparison Between Static and Instance Properties

For the differences between static and instance properties, see [Differences Between Instance Properties and Static Properties](#differences-between-instance-properties-and-static-properties). The following comparison examples further illustrate how they differ in terms of sharing and independence.

### Example of Comparing Static and Instance Properties

A static property is accessed through the class name and is shared by all instances, while an instance property is accessed through an instance and is held independently by each instance.

<!-- @[instance_static_comparison](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Properties.ets) -->

``` TypeScript
class Comparison {
  // Instance property
  public instanceValue: number = 0;
  
  // Static property
  public static staticValue: number = 0;
  
  // Instance method
  getInstanceValue(): number {
    return this.instanceValue;  // via this
  }
  
  setInstanceValue(value: number): void {
    this.instanceValue = value;
  }
  
  // static method
  static getStaticValue(): number {
    return Comparison.staticValue;  // via the class name
  }
  
  static setStaticValue(value: number): void {
    Comparison.staticValue = value;
  }
  
  // mixed use
  static compare(): string {
    return `Static: ${Comparison.staticValue}, Instance: N/A in static`;
  }
  
  getComparison(): string {
    return `Static: ${Comparison.staticValue}, Instance: ${this.instanceValue}`;
  }
}

let comp1: Comparison = new Comparison();
let comp2: Comparison = new Comparison();

// instance properties are independent
comp1.setInstanceValue(10);
comp2.setInstanceValue(20);

console.info(`${comp1.getInstanceValue()}`);   // 10
console.info(`${comp2.getInstanceValue()}`);   // 20

// Static properties are shared.
Comparison.setStaticValue(100);
console.info(`${Comparison.getStaticValue()}`);  // 100

// All instances see the same static property.
console.info(`${comp1.getComparison()}`);  // Static: 100, Instance: 10
console.info(`${comp2.getComparison()}`);  // Static: 100, Instance: 20
```

### Accessing Static Properties (Direct Access via the Class Name)

Static properties are accessed directly through `ClassName.propertyName` without creating an instance. An instance object cannot access static properties.

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

// Access static properties through the class name.
console.info(`${MathConstants.PI}`);                      // 3.14159
console.info(`${MathConstants.E}`);                       // 2.71828
console.info(`${MathConstants.GOLDEN_RATIO}`);            // 1.61803

// Use static properties in static methods.
let area: number = MathConstants.calculateCircleArea(5);
console.info(`${area}`);  // ~78.54

// Instances cannot access static properties.
let mathConstants: MathConstants = new MathConstants();
console.info(`${mathConstants.PI}`);  // Compilation error
```

### Accessing Instance Properties (Through an Instance Object)

An instance property is accessed through `instance object.property name`. Each instance has its own copy of the property, and the class name cannot directly access an instance property.

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

  // Instance method accesses an instance property.
  getInfo(): string {
    return `${this.name}, ${this.age} years old, grade ${this.grade}`;
  }

  // Instance method modifies an instance property.
  setGrade(newGrade: string): void {
    this.grade = newGrade;
  }
}

let student1: Student = new Student('Alice', 15, 'A');
let student2: Student = new Student('Bob', 16, 'B');

// Instance property is accessed through an instance.
console.info(`${student1.name}`);   // 'Alice'
console.info(`${student2.name}`);   // 'Bob'

// Instance properties are independent.
student1.setGrade('A+');
console.info(`${student1.grade}`);  // 'A+'
console.info(`${student2.grade}`);  // 'B' (unaffected)

// Instance properties cannot be accessed through the class name.
console.info(`${Student.grade}`);  // Compilation error: instance properties cannot be accessed through the class name.
```

### Lifecycle of Static Properties (Bound to the Class)

Static properties are created when the class is loaded and are shared by all instances, making them suitable for global state management.

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

// Static properties are initialized when the class is loaded.
console.info(`${ApplicationState.startTime}`);       // Initialization time
console.info(`${ApplicationState.sessionActive}`);   // false

// Application startup
ApplicationState.initialize();
ApplicationState.addUser();  // User count: 1
ApplicationState.addUser();  // User count: 2

console.info(`${ApplicationState.getElapsedTime()}`);  // Elapsed time

// Static properties are shared globally.
// No matter how many instances are created, there is only one copy of a static property.
```

## Access Control of Properties

`public`, `private`, and `protected` control the access scope, while `readonly` controls writability. These two orthogonal dimensions combine to cover common encapsulation requirements. For example, `public readonly` means read-only externally, and `private readonly` means read-only internally.

### Property Access Control Example

`readonly` can be combined with access modifiers. For example, `public readonly` means read-only outside the class, and `private readonly` means read-only inside the class.

<!-- @[ts_access_modifier_combination](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Properties.ts) -->

``` TypeScript
class SecureData {
  // public: fully public
  public id: number;

  // private: only within the class
  private secretKey: string;

  // protected: the class and its subclasses
  protected internalData: string;

  // readonly: read-only
  public readonly createdAt: Date;

  // Combined modifiers
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

  // Method for publicly accessing a private property
  getSecretKey(): string {
    return this.secretKey;
  }

  // Modify a private property after verification
  updateSecretKey(newKey: string, token: string): boolean {
    if (token === 'valid') {
      this.secretKey = newKey;
      return true;
    }
    return false;
  }

  // protected method
  protected getInternalData(): string {
    return this.internalData;
  }
}

let secure: SecureData = new SecureData(1, 'secret123');

// public is accessible.
console.info(`${secure.id}`);         // 1

// private is not directly accessible.
console.info(`${secure.secretKey}`);  // Compilation error.

// Access through a public method.
console.info(`${secure.getSecretKey()}`);  // 'secret123'

// protected is not directly accessible.
console.info(`${secure.internalData}`);  // Compilation error.

// readonly is read-only and cannot be written.
console.info(`${secure.createdAt}`);
secure.createdAt = new Date();  // Compilation error.

// Subclass accesses the protected property.
class ExtendedSecure extends SecureData {
  getProtectedData(): string {
    return this.getInternalData();  // Can access the protected method.
  }

  getProtectedProperty(): string {
    return this.protectedReadOnly;  // Can access the protected property.
  }
}
```

## Properties in Inheritance

A subclass automatically inherits the public and protected properties of its parent class. Private properties are not inherited, and a subclass can override the properties of its parent class.

### Property Inheritance Example

A subclass automatically inherits the `public` and `protected` properties of its parent class, while `private` properties are not inherited. A subclass can declare a property with the same name to hide the parent class property, but it cannot change the access level of the parent class member.

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
  // New property
  public childProp: string = 'child';

  // Inherited public property
  getPublicFromParent(): string {
    return this.publicProp;  // Accessible
  }

  // Inherit the protected property.
  getProtectedFromParent(): string {
    return this.protectedProp;  // Accessible.
  }

  // Cannot inherit the private property.
  getPrivateFromParent(): string {
    return this.privateProp;  // Compilation error.
  }

  // Access the private property through the parent class's public method.
  getParentPrivate(): string {
    return this.getPrivateProp();  // Accessible
  }

  // Override the parent class property (hidden).
  public publicProp: string = 'child override';

  testOverride(): void {
    console.info(`${this.publicProp}`);  // 'child override'
  }
}

let child: Child = new Child();

console.info(`${child.publicProp}`);           // 'child override'
console.info(`${child.getProtectedFromParent()}`); // 'protected' (inherited)
console.info(`${child.childProp}`);            // 'child'
console.info(`${child.getParentPrivate()}`);   // 'private'

// Property inheritance summary:
// public: fully inherited and can be overridden
// protected: inherited, accessible in subclasses
// private: not inherited, not directly accessible in subclasses
```

## Index Signature

ArkTS does not support index signatures (`arkts-no-indexed-signatures`) or indexed access fields (`arkts-no-props-by-index`). For details, see [TypeScript to ArkTS Cookbook](typescript-to-arkts-migration-guide.md#indexed-signatures-are-not-supported). Use `Map` instead.

**TypeScript comparison**

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

In ArkTS, use `Map` instead of index signatures on classes.

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

## declare-Only Field Declaration

When redeclaring an inherited field with a more precise type in a subclass, use `declare` to avoid overriding the parent class value at runtime. Without `declare`, the initializer of the subclass field runs at construction time and overrides the value already set by the parent class constructor, which may cause data loss or type inconsistency.

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
  // declare: generates no runtime code and only corrects the type
  public declare resident: DclDog;

  constructor(dog: DclDog) {
    super(dog);
  }
}

let dclDog: DclDog = { dateOfBirth: new Date(), breed: 'Labrador' };
let dclHouse: DclDogHouse = new DclDogHouse(dclDog);
console.info(`${dclHouse.resident.breed}`);  // Labrador
```

A `declare` field generates no runtime code and is used only to ensure type correctness. Without `declare`, the subclass field initialization overrides the parent class value after the parent class constructor runs.