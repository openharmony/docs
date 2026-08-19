# Inheritance

<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=e25164b4c5d2db315865d228475dc21473dba5fb translatedAt=2026-08-13T09:00:41.697Z pushedAt=2026-08-13T13:15:20.292Z -->

Inheritance is a core feature of object-oriented programming that allows a subclass to reuse and extend the properties and methods of its parent class. ArkTS supports single inheritance, which is implemented through the `extends` keyword.

## Basic Concepts of Inheritance

Inheritance allows a subclass to reuse the properties and methods of its parent class. It establishes a type hierarchy through the `extends` keyword and serves as the core mechanism for code reuse and polymorphism in object-oriented programming.

### Definition and Core Purpose of Inheritance

Inheritance establishes a parent-child class hierarchy through the `extends` keyword. A child class reuses the members of its parent class and can extend or override them to achieve polymorphism.

<!-- @[extends_syntax](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Inheritance.ets) -->

``` TypeScript
class Parent {
  // Parent class members
}

class Child extends Parent {
  // Child class members
}
```

Inheritance allows a child class to reuse parent class members to reduce duplicate code, automatically synchronize with parent class modifications to improve maintainability, achieve polymorphism through overriding, and establish a clear type hierarchy.

<!-- @[basic_inheritance_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Inheritance.ets) -->

``` TypeScript
// Base class (parent class).
class Animal {
  public name: string;
  
  constructor(name: string) {
    this.name = name;
  }
  
  speak(): void {
    console.info(`${this.name} makes a sound`);
  }
  
  move(): void {
    console.info(`${this.name} moves`);
  }
}

// Child class (derived class) inherits from the base class.
class Dog extends Animal {
  public breed: string;
  
  constructor(name: string, breed: string) {
    super(name);  // Call the parent class constructor.
    this.breed = breed;
  }
  
  // Inherit the parent class method, which can be overridden.
  speak(): void {
    console.info(`${this.name} barks`);
  }
  
  // Add a new method.
  fetch(): void {
    console.info(`${this.name} fetches the ball`);
  }
}

let dog: Dog = new Dog('Max', 'Labrador');
dog.speak();   // 'Max barks' (overridden method)
dog.move();    // 'Max moves' (inherited method)
dog.fetch();   // 'Max fetches the ball' (newly added method)
```

Inheritance enables a child class to reuse the properties and methods of its parent class, extend new members, and achieve polymorphism through overriding.

### Relationship Between Base Class and Derived Class

A base class (parent class) provides common members for reuse, while a derived class (child class) specializes and extends on the basis of inheritance. The hierarchical relationship is established through the `extends` keyword.

<!-- @[base_and_derived_class](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Inheritance.ets) -->

``` TypeScript
// Base class: the class that is inherited.
class Vehicle {
  public brand: string;
  
  constructor(brand: string) {
    this.brand = brand;
  }
  
  start(): void {
    console.info(`${this.brand} vehicle starting`);
  }
}

// Derived class: the class that inherits from the base class.
class Car extends Vehicle {
  public model: string;
  
  constructor(brand: string, model: string) {
    super(brand);
    this.model = model;
  }
  
  getInfo(): string {
    return `${this.brand} ${this.model}`;
  }
}

class Motorcycle extends Vehicle {
  public type: string;
  
  constructor(brand: string, type: string) {
    super(brand);
    this.type = type;
  }
  
  getInfo(): string {
    return `${this.brand} ${this.type} motorcycle`;
  }
}

let car: Car = new Car('Toyota', 'Camry');
let motorcycle: Motorcycle = new Motorcycle('Honda', 'sport');

console.info(`${car.getInfo()}`);        // 'Toyota Camry'
console.info(`${motorcycle.getInfo()}`); // 'Honda sport motorcycle'

// Relationship between the base class and the derived class:
// - The base class provides common properties and methods.
// - The derived class inherits from and specializes the base class.
// - Multiple derived classes can be created to form an inheritance tree.
```

### Single Inheritance

ArkTS supports only single inheritance. A child class can inherit from only one parent class through `extends`, and multiple inheritance (for example, `class C extends A, B`) causes a compilation error. Single inheritance is enforced because multiple inheritance introduces the diamond inheritance problem: when two parent classes define methods with the same name, the child class cannot determine which one to inherit, resulting in ambiguity. If you need to reuse the behavior of multiple types, use `implements` to implement multiple interfaces instead of multiple inheritance. Interfaces define only contracts without implementations, so no conflicts arise.

<!-- @[ts_single_inheritance_limitation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Inheritance.ts) -->

``` TypeScript
// ArkTS supports only single inheritance: a child class can have only one parent class.
class ParentA {
  methodA(): void {
    console.info(`Method A`);
  }
}

class ParentB {
  methodB(): void {
    console.info(`Method B`);
  }
}

// Cannot inherit ParentB at the same time.
class ErrorChild extends ParentA, ParentB {}  // Compilation error.

// Single inheritance: a class can inherit from only one parent class.
class Child extends ParentA {
  // Can inherit from ParentA.
  methodA(): void {
    super.methodA();
    console.info(`Child overrides Method A`);
  }
}

let child: Child = new Child();
child.methodA();  // 'Method A', 'Child overrides Method A'
```

When you need to combine behaviors from multiple types, you can implement multiple interfaces as an alternative to multiple inheritance.

<!-- @[interface_multi_implementation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Inheritance.ets) -->

``` TypeScript
// Alternative to multiple inheritance: interface implementation.
interface IFeatureA {
  methodA(): void;
}

interface IFeatureB {
  methodB(): void;
}

class MultiFeature implements IFeatureA, IFeatureB {
  methodA(): void {
    console.info(`Feature A`);
  }

  methodB(): void {
    console.info(`Feature B`);
  }
}

let multi: MultiFeature = new MultiFeature();
multi.methodA();
multi.methodB();
```

Both ArkTS and TypeScript support only single class inheritance (a child class can have only one parent class). TypeScript can mix multiple behaviors into a class at runtime through the mixins pattern, whereas ArkTS imposes stricter static constraints on dynamic mixing and object layout, requiring interface implementation or the composition pattern to reuse multiple capabilities.

### Inheritance and Code Reuse

Reuse the properties and methods of the parent class through inheritance to avoid writing the same logic repeatedly in multiple child classes.

<!-- @[inheritance_code_reuse](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Inheritance.ets) -->

``` TypeScript
// Without inheritance: duplicate code
class DogWithoutInheritance {
  public name: string;
  public age: number;
  
  constructor(name: string, age: number) {
    this.name = name;
    this.age = age;
  }
  
  eat(): void {
    console.info(`${this.name} is eating`);
  }
  
  sleep(): void {
    console.info(`${this.name} is sleeping`);
  }
  
  bark(): void {
    console.info(`${this.name} is barking`);
  }
}

class CatWithoutInheritance {
  public name: string;
  public age: number;
  
  constructor(name: string, age: number) {
    this.name = name;
    this.age = age;
  }
  
  eat(): void {
    console.info(`${this.name} is eating`);  // Duplicate code
  }
  
  sleep(): void {
    console.info(`${this.name} is sleeping`);  // Duplicate code
  }
  
  meow(): void {
    console.info(`${this.name} is meowing`);
  }
}

// Use inheritance for code reuse.
class ReuseAnimal {
  public name: string;
  public age: number;
  
  constructor(name: string, age: number) {
    this.name = name;
    this.age = age;
  }
  
  // Public method reused by subclasses.
  eat(): void {
    console.info(`${this.name} is eating`);
  }
  
  sleep(): void {
    console.info(`${this.name} is sleeping`);
  }
}

class ReuseDog extends ReuseAnimal {
  constructor(name: string, age: number) {
    super(name, age);
  }
  
  // Specific method.
  bark(): void {
    console.info(`${this.name} is barking`);
  }
}

class Cat extends ReuseAnimal {
  constructor(name: string, age: number) {
    super(name, age);
  }
  
  // Specific method.
  meow(): void {
    console.info(`${this.name} is meowing`);
  }
}

let reuseDog: ReuseDog = new ReuseDog('Max', 3);
let cat: Cat = new Cat('Whiskers', 2);

reuseDog.eat();    // Reuse the parent class method.
reuseDog.sleep();  // Reuse the parent class method.
reuseDog.bark();   // Subclass-specific method.

cat.eat();    // Reuse the parent class method.
cat.sleep();  // Reuse the parent class method.
cat.meow();   // Subclass-specific method.
```

## Class Inheritance Syntax

A class declares an inheritance relationship through the `extends` keyword. The child class obtains the non-private members of the parent class and can extend or override them.

### Declaring Inheritance

Use the `extends` keyword to declare an inheritance relationship. The child class automatically inherits the public and protected members of the parent class, and can add new members or override existing ones.

<!-- @[extends_keyword_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Inheritance.ets) -->

``` TypeScript
// Define the base class.
class Shape {
  public color: string;
  
  constructor(color: string) {
    this.color = color;
  }
  
  draw(): void {
    console.info(`Drawing a ${this.color} shape`);
  }
  
  getArea(): number {
    return 0;
  }
}

// Declare the child class inheritance using the extends keyword.
class Circle extends Shape {
  public radius: number;
  
  constructor(color: string, radius: number) {
    super(color);  // Must call the parent class constructor.
    this.radius = radius;
  }
  
  // Override the parent class method.
  draw(): void {
    console.info(`Drawing a ${this.color} circle with radius ${this.radius}`);
  }
  
  getArea(): number {
    return Math.PI * this.radius * this.radius;
  }
}

class Rectangle extends Shape {
  public width: number;
  public height: number;
  
  constructor(color: string, width: number, height: number) {
    super(color);
    this.width = width;
    this.height = height;
  }
  
  draw(): void {
    console.info(`Drawing a ${this.color} rectangle ${this.width}x${this.height}`);
  }
  
  getArea(): number {
    return this.width * this.height;
  }
}

let circle: Circle = new Circle('red', 5);
let rectangle: Rectangle = new Rectangle('blue', 10, 20);

circle.draw();
console.info(`${circle.getArea()}`);

rectangle.draw();
console.info(`${rectangle.getArea()}`);
```

### Defining a Subclass and Its Relationship with the Parent Class

A subclass instance contains both the members of the parent class and its own members. You can access the constructor, methods, and properties of the parent class through the `super` keyword.

<!-- @[parent_child_relation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Inheritance.ets) -->

``` TypeScript
class Employee {
  // Parent class property.
  public name: string;
  public id: number;
  
  constructor(name: string, id: number) {
    this.name = name;
    this.id = id;
  }
  
  // Parent class method.
  work(): void {
    console.info(`${this.name} is working`);
  }
  
  getInfo(): string {
    return `Employee ${this.id}: ${this.name}`;
  }
}

class Manager extends Employee {
  // New property added in the subclass.
  public department: string;
  public teamSize: number;
  
  constructor(name: string, id: number, department: string, teamSize: number) {
    super(name, id);  // Associate with the parent class constructor.
    this.department = department;
    this.teamSize = teamSize;
  }
  
  // Add a new method to the child class.
  manage(): void {
    console.info(`${this.name} manages ${this.teamSize} people in ${this.department}`);
  }
  
  // Override the parent class method.
  getInfo(): string {
    return `Manager ${this.id}: ${this.name}, ${this.department} department`;
  }
  
  // Call the parent class method.
  getEmployeeInfo(): string {
    return super.getInfo();  // Call the parent class method through super.
  }
}

let manager: Manager = new Manager('Alice', 1, 'Engineering', 10);

// Associate the parent class properties and methods.
console.info(`${manager.name}`);       // 'Alice' (inherited from the parent class)
console.info(`${manager.id}`);          // 1 (inherited from the parent class)
manager.work();                    // 'Alice is working' (inherited from the parent class method)
console.info(`${manager.getInfo()}`);   // 'Manager 1: Alice, Engineering department' (overridden)
console.info(`${manager.getEmployeeInfo()}`);  // 'Employee 1: Alice' (parent class method)

// Subclass-specific properties and methods
console.info(`${manager.department}`);  // 'Engineering'
console.info(`${manager.teamSize}`);    // 10
manager.manage();                  // 'Alice manages 10 people in Engineering'
```

### Characteristics and Use Cases of Empty Child Classes

An empty child class is a child class that adds no new members. Its uses include: type marking (for example, `class RegularUser extends User` and `class PremiumUser extends User` distinguish user levels by type), reserving an inheritance position for future extension, and performing runtime distinction through `instanceof` without modifying the parent class.

<!-- @[empty_child_class](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Inheritance.ets) -->

``` TypeScript
class Base {
  public value: number = 10;
  
  getValue(): number {
    return this.value;
  }
  
  increment(): void {
    this.value++;
  }
}

// Empty child class: no new properties or methods
class EmptyChild extends Base {
  // The empty child class inherits all parent class functionality
}

let empty: EmptyChild = new EmptyChild();

// The empty child class fully inherits the parent class
console.info(`${empty.getValue()}`);  // 10
empty.increment();
console.info(`${empty.getValue()}`);  // 11

// Use cases for empty subclasses:
// 1. Type marker: distinguish different categories
class User {
  public name: string;
  constructor(name: string) {
    this.name = name;
  }
}

class RegularUser extends User {}
class PremiumUser extends User {}

let regular: RegularUser = new RegularUser('Bob');
let premium: PremiumUser = new PremiumUser('Alice');

// Distinguish user categories by type
function getServiceLevel(user: User): string {
  if (user instanceof PremiumUser) {
    return 'Premium service';
  }
  return 'Regular service';
}

console.info(`${getServiceLevel(regular)}`);   // 'Regular service'
console.info(`${getServiceLevel(premium)}`);   // 'Premium service'

// 2. Reserved for future extension
class FutureFeature extends Base {
  // Reserved subclass for adding features in the future
}
```

An empty child class does not need to explicitly declare a constructor. When an instance is created, the parent class constructor is implicitly called (equivalent to automatically generating `constructor(...args) { super(...args); }`).

### Inheritance Chain and Multi-level Inheritance

An inheritance chain refers to the multi-level inheritance relationship from a base class to a derived class. For example, `GrandParent → Parent → Child` forms a three-level inheritance chain, in which each level inherits the `public` and `protected` members of its parent class and can add its own members. An inheritance chain propagates code reuse across multiple levels, but an excessively deep chain increases the difficulty of understanding and the overhead of lookup.

### Inheritance Hierarchy

Inheritance can form a multi-level structure, where a child class inherits members from its ancestor chain level by level. It is recommended to keep the hierarchy within three levels to control complexity.

<!-- @[multi_level_inheritance](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Inheritance.ets) -->

``` TypeScript
// Inheritance hierarchy: multi-level inheritance
class GrandParent {
  methodGrandParent(): void {
    console.info('GrandParent method');
  }
}

class MultiLevelParent extends GrandParent {
  methodParent(): void {
    console.info('MultiLevelParent method');
  }
  
  methodGrandParent(): void {
    console.info('MultiLevelParent overrides GrandParent');
    super.methodGrandParent();  // Call the parent class method.
  }
}

class MultiLevelChild extends MultiLevelParent {
  methodChild(): void {
    console.info('MultiLevelChild method');
  }
  
  methodParent(): void {
    console.info('MultiLevelChild overrides MultiLevelParent');
    super.methodParent();  // Call the parent class method.
  }
}

let multiLevelChild: MultiLevelChild = new MultiLevelChild();

multiLevelChild.methodChild();           // 'MultiLevelChild method'
multiLevelChild.methodParent();          // 'MultiLevelChild overrides MultiLevelParent', 'MultiLevelParent method'
multiLevelChild.methodGrandParent();     // 'MultiLevelParent overrides GrandParent', 'GrandParent method'

// Inheritance chain lookup: from child class to parent class.
// MultiLevelChild.methodChild() -> MultiLevelChild itself
// MultiLevelChild.methodParent() -> MultiLevelChild override -> MultiLevelParent method
// MultiLevelChild.methodGrandParent() -> MultiLevelParent override -> GrandParent method

// Inheritance hierarchy limit: avoid overly deep inheritance.
// Recommended: no more than 3 levels of inheritance.
// Counterexample: excessive inheritance depth increases complexity.
```

## Inheriting Parent Class Members

A child class inherits the properties and methods of its parent class based on access modifiers. `public` and `protected` members are accessible to the child class, while `private` members are not inherited.

### Inheriting Instance Properties and Methods from the Parent Class

Inheriting instance properties and methods from the parent class is the core capability of the inheritance mechanism. The access modifiers determine what can be inherited and the access permissions.

<!-- @[ts_access_modifier_inheritance](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Inheritance.ts) -->

``` TypeScript
class Parent {
  // Instance property.
  public publicValue: string = 'public';
  protected protectedValue: string = 'protected';

  // Instance method.
  public publicMethod(): void {
    console.info(`Public method`);
  }

  protected protectedMethod(): void {
    console.info(`Protected method`);
  }

  private privateMethod(): void {
    console.info(`Private method`);
  }

  // Public method that accesses the private method.
  callPrivate(): void {
    this.privateMethod();
  }
}

class AccessChildTest extends Parent {
  // Inherit public properties and methods.
  testPublic(): void {
    console.info(`${this.publicValue}`);    // Accessible.
    this.publicMethod();               // Accessible.
  }

  // Inherit protected properties and methods.
  testProtected(): void {
    console.info(`${this.protectedValue}`); // Accessible.
    this.protectedMethod();            // Accessible.
  }

  // Cannot inherit private properties and methods.
  testPrivate(): void {
    this.privateMethod();  // Compilation error.
    this.callPrivate();       // Access through a public method.
  }
}

let accessChild: AccessChildTest = new AccessChildTest();

accessChild.testPublic();     // 'public', 'Public method'
accessChild.testProtected();  // 'protected', 'Protected method'
accessChild.testPrivate();    // 'Private method'
```

`public` members are fully inherited and accessible to both subclasses and external code. `protected` members are inherited but accessible only to subclasses, not to external code. `private` members are not inherited; subclasses cannot access them directly and can only invoke them indirectly through `public` methods provided by the parent class.

### Inheriting Static Properties and Methods from the Parent Class

A child class inherits the static properties and methods of its parent class and accesses the inherited static members through the class name.

<!-- @[static_member_inheritance](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Inheritance.ets) -->

``` TypeScript
class MemberBase {
  // Static property.
  public static staticValue: number = 100;
  
  // Static method.
  public static staticMethod(): void {
    console.info('Static method');
  }
  
  public static getStaticValue(): number {
    return MemberBase.staticValue;
  }
}

class Derived extends MemberBase {
  // Inherit the static method.
  callStaticMethod(): void {
    MemberBase.staticMethod();    // Call through the parent class name.
    Derived.staticMethod(); // Call through the child class name (inherited).
  }
  
  // Inherit static properties.
  getInheritedStaticValue(): number {
    return Derived.getStaticValue();  // Inherited static method.
  }
  
  // Child class static method.
  static childStaticMethod(): void {
    console.info('Child static method');
    Derived.staticMethod();  // Call the inherited static method.
  }
}

// Static methods are called by class name.
MemberBase.staticMethod();           // 'Static method'
Derived.staticMethod();        // 'Static method' (inherited)
Derived.childStaticMethod();   // 'Child static method', 'Static method'

console.info(`${MemberBase.staticValue}`);       // 100
console.info(`${Derived.staticValue}`);    // 100 (inherited)

let derived: Derived = new Derived();
derived.callStaticMethod();           // 'Static method', 'Static method'
console.info(`${derived.getInheritedStaticValue()}`);  // 100

// Static member inheritance rules:
// Static properties and methods are accessed through the class name.
// A child class inherits the static members of its parent class.
// A child class can add its own static members.
```

### Access Rules for Inherited Members

A subclass can access the public and protected members of its parent class, but cannot directly access private members. Access modifiers control the visibility of members along the inheritance chain.

<!-- @[ts_access_permission_rules](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Inheritance.ts) -->

``` TypeScript
class AccessBase {
  public publicProp: string = 'public';
  protected protectedProp: string = 'protected';
  private privateProp: string = 'private';

  public publicMethod(): void {}
  protected protectedMethod(): void {}
  private privateMethod(): void {}

  // Access all properties.
  accessAll(): void {
    console.info(`${this.publicProp}`);
    console.info(`${this.protectedProp}`);
    console.info(`${this.privateProp}`);
    this.publicMethod();
    this.protectedMethod();
    this.privateMethod();
  }
}

class AccessChild extends AccessBase {
  // Subclass access rules.
  testAccess(): void {
    // public: accessible.
    console.info(`${this.publicProp}`);
    this.publicMethod();

    // protected: accessible.
    console.info(`${this.protectedProp}`);
    this.protectedMethod();

    // private: inaccessible.
    console.info(`${this.privateProp}`);  // Compilation error.
    this.privateMethod();           // Compilation error.
  }

  // Access private members through a public method of the parent class.
  usePrivate(): void {
    this.accessAll();  // Call the parent class method.
  }
}

// External access rules
let permChild: AccessChild = new AccessChild();

// public: accessible externally
console.info(`${permChild.publicProp}`);    // 'public'
permChild.publicMethod();

// protected: not accessible externally
console.info(`${permChild.protectedProp}`);  // Compilation error
permChild.protectedMethod();           // Compilation error.

// private: inaccessible from outside.
console.info(`${permChild.privateProp}`);   // Compilation error.

// Access permission summary:
// public: unrestricted access.
// protected: accessible within the class and its subclasses
// private: accessible only within the class
```

### Parent Class Members Inaccessible to the Child Class

The parent class members inaccessible to the child class are mainly private members, which protect the internal implementation of the parent class through encapsulation.

<!-- @[ts_private_member_restriction](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Inheritance.ts) -->

``` TypeScript
class SecretBase {
  private secretKey: string = 'secret';
  private privateKey: number = 123;

  private privateMethod(): void {
    console.info(`Private method in base`);
  }

  // Use internal logic in the private method.
  private internalProcess(): void {
    console.info(`Internal processing`);
  }

  // Access private members through the public interface.
  getSecretKey(): string {
    return this.secretKey;
  }

  setSecretKey(key: string): void {
    if (key.length > 5) {
      this.secretKey = key;
    }
  }
}

class SecretChild extends SecretBase {
  // Cannot access the private members of the parent class.
  attemptAccess(): void {
    console.info(`${this.secretKey}`);      // Compilation error.
    console.info(`${this.privateKey}`);     // Compilation error.
    this.privateMethod();              // Compilation error.
    this.internalProcess();            // Compilation error.

    // Access through the public interface.
    console.info(`${this.getSecretKey()}`);  // Accessible.
  }

  // Cannot override the parent class private method.
  privateMethod(): void {}  // Compilation error.

  // Can define a private method with the same name (independent).
  private childPrivateKey: number = 456;  // The child class's own private property.
}

let secret: SecretChild = new SecretChild();
console.info(`${secret.getSecretKey()}`);  // secret
secret.setSecretKey('newsecretkey');
console.info(`${secret.getSecretKey()}`);  // newsecretkey
```

## Overriding Parent Class Methods

A child class redefines a parent class method to implement polymorphism. When overriding, the method signature must be consistent with that of the parent class, and the access level must not be more restrictive.

### Concepts of Method Overriding and Property Overriding

Method overriding means that a child class provides a brand-new implementation of a method with the same name, while property overriding means that a child class redefines a property of the parent class. When overriding, you can call the original implementation of the parent class through `super`. The `override` keyword marks an overridden method so that the compiler reports an error when the parent class method is renamed or deleted; its use is recommended.

### Syntax of Method Overriding

Method overriding requires that the child class method have the same signature as the parent class method, and that the access modifier not be more restrictive.

<!-- @[method_override](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Inheritance.ets) -->

``` TypeScript
class Communicator {
  sendMessage(message: string): void {
    console.info(`Sending: ${message}`);
  }
  
  formatMessage(content: string): string {
    return content;
  }
}

class EmailCommunicator extends Communicator {
  // Override the parent class method: same signature.
  sendMessage(message: string): void {
    console.info(`Sending email: ${message}`);
  }
  
  // Override and extend.
  formatMessage(content: string): string {
    let formatted: string = super.formatMessage(content);  // Call the parent class method.
    return `[Email] ${formatted}`;
  }
  
  // Add a new method.
  sendHtmlEmail(html: string): void {
    let formatted: string = this.formatMessage(html);
    this.sendMessage(formatted);
  }
}

let email: EmailCommunicator = new EmailCommunicator();

email.sendMessage('Hello');            // 'Sending email: Hello'
console.info(`${email.formatMessage('Test')}`); // '[Email] Test'
email.sendHtmlEmail('<p>Content</p>');
```

Method overriding rules: The child class method must have the same name as the parent class method, the same parameter types and count, the same or a compatible return type, and an access level that is not more restrictive.

### Matching Rules for Parameters and Return Values of Overridden Methods

The parameters and return value of an overridden method must match those of the parent class method to ensure type safety.

<!-- @[ts_method_signature_match](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Inheritance.ts) -->

``` TypeScript
class NumberProcessor {
  process(value: number): number {
    return value * 2;
  }

  convert(input: string): number {
    return Number.parseInt(input, 10);
  }
}

class AdvancedProcessor extends NumberProcessor {
  // Parameters and return values must match exactly.
  process(value: number): number {
    return value * 3;  // The return value types are the same.
  }

  // The return values are compatible (the child class return type can be a subtype of the parent class return type).
  convert(input: string): number {
    let result: number = super.convert(input);
    return result * 10;
  }

  // Cannot change the parameter type.
  process(value: string): number {}  // Compilation error.

  // Cannot change the number of parameters.
  process(value: number, extra: number): number {}  // Compilation error.

  // Cannot change the return type to an incompatible type.
  process(value: number): string {}  // Compilation error.
}

let processor: AdvancedProcessor = new AdvancedProcessor();

console.info(`${processor.process(5).toString()}`);      // 15
console.info(`${processor.convert('10').toString()}`);   // 100

// The parent class reference points to a child class instance.
let baseProcessor: NumberProcessor = new AdvancedProcessor();
console.info(`${baseProcessor.process(5).toString()}`);  // 15 (calls the overridden method in the child class)
```

### Access Permission Rules for Overridden Methods

The access permission of a method in a child class must not be lower than that of the corresponding method in the parent class.

<!-- @[ts_override_access_permission](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Inheritance.ts) -->

``` TypeScript
class AccessParent {
  // public method
  public publicMethod(): void {
    console.info(`Parent public`);
  }

  // protected method
  protected protectedMethod(): void {
    console.info(`Parent protected`);
  }

  // public method (demonstrates lowering the access permission)
  public loweredAccessMethod(): void {}

  // private method (invisible to subclasses and cannot be overridden)
  private privateMethod(): void {}
}

class OverrideAccessChild extends AccessParent {
  // Override the public method: it must remain public.
  public publicMethod(): void {
    console.info(`Child public`);
  }

  // Override the protected method: it can remain protected or be changed to public.
  public protectedMethod(): void {
    console.info(`Child public (was protected)`);
  }

  // Do not lower the access level.
  protected loweredAccessMethod(): void {}  // Compilation error: cannot change from public to protected.

  // Cannot override a private method (because it is inaccessible).
  privateMethod(): void {}  // Compilation error: the parent class method is not visible.
}

let overrideChild: OverrideAccessChild = new OverrideAccessChild();

overrideChild.publicMethod();     // 'Child public'
overrideChild.protectedMethod();  // 'Child public (was protected)'
```

An overriding method cannot reduce the access level: a `public` method must remain `public` after being overridden; a `protected` method can remain `protected` or be changed to `public` after being overridden; a `private` method cannot be overridden (because it is inaccessible to the child class).

## Calling Parent Class Members

A child class calls the constructor, methods, and properties of its parent class through the `super` keyword.

### Purpose and Concept of the super Keyword

The `super` keyword is used in a child class to call the constructor (`super()`), instance methods (`super.method()`), and properties of the parent class. It is the key to reusing parent class logic when overriding methods.

### Calling Parent Class Instance Methods Through the super Keyword

Use `super.methodName()` to call a parent class instance method. This is often used in an overriding method to reuse the parent class logic before adding subclass-specific behavior.

<!-- @[super_call_parent_method](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Inheritance.ets) -->

``` TypeScript
class Worker {
  work(): void {
    console.info('Worker working');
  }
  
  rest(): void {
    console.info('Worker resting');
  }
  
  report(): string {
    return 'Worker report';
  }
}

class ParentManager extends Worker {
  // Override and call the parent class method.
  work(): void {
    super.work();  // Call the parent class work method.
    console.info('ParentManager managing');
  }
  
  // Completely override.
  rest(): void {
    console.info('ParentManager taking break');
    // Do not call super.rest().
  }
  
  // Extend the parent class return value.
  report(): string {
    let baseReport: string = super.report();
    return `${baseReport}, ParentManager report`;
  }
  
  // Combine the calls.
  fullDay(): void {
    super.work();
    this.work();
    super.rest();
    this.rest();
  }
}

let parentManager: ParentManager = new ParentManager();

parentManager.work();   // 'Worker working', 'ParentManager managing'
parentManager.rest();   // 'ParentManager taking break'
console.info(`${parentManager.report()}`);  // 'Worker report, ParentManager report'
parentManager.fullDay();

// super call rules:
// super.methodName() calls the parent class instance method.
// Must be used in a child class instance method.
// Can be called at any position in the overriding method.
```

### Calling the Parent Class Constructor Through the super Keyword

Call the parent class constructor through `super()` to initialize the parent class portion of the child class instance. The `super()` call must be placed on the first line of the child class constructor.

<!-- @[super_call_constructor](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Inheritance.ets) -->

``` TypeScript
class Person {
  public name: string;
  public age: number;
  
  constructor(name: string, age: number) {
    this.name = name;
    this.age = age;
    console.info('Person constructor');
  }
}

class Student extends Person {
  public grade: string;
  
  constructor(name: string, age: number, grade: string) {
    super(name, age);  // The parent class constructor must be called first.
    this.grade = grade;
    console.info('Student constructor');
  }
}

let student: Student = new Student('Alice', 20, 'A');
// Output: 'Person constructor', 'Student constructor'

class CtorEmployee extends Person {
  public department: string;
  
  constructor(name: string, age: number, department: string) {
    super(name, age);  // Pass parameters to the parent class constructor.
    this.department = department;
  }
  
  getInfo(): string {
    return `${this.name}, ${this.age}, ${this.department}`;
  }
}

let employee: CtorEmployee = new CtorEmployee('Bob', 30, 'Engineering');
console.info(`${employee.getInfo()}`);  // 'Bob, 30, Engineering'

// Rules for calling super():
// The subclass constructor must call super().
// super() must be on the first line of the subclass constructor.
// super() passes arguments to the parent class constructor.
```

### Calling Parent Class Static Members from Child Class Static Methods

A child class static method can call parent class static members through the class name or the `super` keyword.

<!-- @[static_method_call](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Inheritance.ets) -->

``` TypeScript
class StaticBase {
  public static baseValue: number = 10;

  static baseMethod(): void {
    console.info(`Base static method`);
  }

  static getValue(): number {
    return StaticBase.baseValue;
  }
}

class StaticChild extends StaticBase {
  public static childValue: number = 20;

  // Call a parent class static method from a child class static method.
  static combinedMethod(): void {
    StaticBase.baseMethod();   // Call through the parent class name.
    StaticChild.baseMethod();  // Call through the child class name (inherited).
  }

  // Access the parent class static property in a child class static method.
  static getTotalValue(): number {
    return StaticBase.baseValue + StaticChild.childValue;
  }

  // Call the inherited static method.
  static getInheritedValue(): number {
    return StaticChild.getValue();  // Inherited static method.
  }

  // In a static method, call the parent class static method via super.
  static callViaSuper(): void {
    super.baseMethod();  // Call the parent class static method via super.
  }
}

StaticChild.combinedMethod();       // 'Base static method', 'Base static method'
console.info(`${StaticChild.getTotalValue()}`);       // 30
console.info(`${StaticChild.getInheritedValue()}`);   // 10
StaticChild.callViaSuper();         // 'Base static method'

// Rules for calling static methods:
// Call static members through the class name.
// The subclass name can call inherited static members.
// Static methods of the parent class can be called through super.
```

### Usage Scenarios and Restrictions of the super Keyword

The usage scenarios of `super` include: calling the parent class constructor (`super()`), calling a parent class method (`super.method()`), and calling a parent class static method in a static method (`super.staticMethod()`). The restrictions include: `super()` must be the first statement in the constructor, and parent class properties cannot be directly accessed through `super` (use `this` instead).

<!-- @[ts_super_usage_limitation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Inheritance.ts) -->

``` TypeScript
class SuperBase {
  public value: number = 10;

  method(): void {
    console.info(`Base method`);
  }

  static staticMethod(): void {
    console.info(`Base static method`);
  }
}

class SuperChild extends SuperBase {
  public value: number = 20;

  method(): void {
    // Call the parent class method with super.
    super.method();  // Correct

    // super cannot directly access the parent class instance property.
    console.info(`${super.value}`);  // undefined at runtime; use this instead

    // Use this or the parent class name to access the property
    console.info(`${this.value}`);          // 20 (child class property)
    console.info(`${SuperChild.prototype.value}`); // Counterexample: parent class property
  }

  anotherMethod(): void {
    // super can only call methods
    super.method();

    // Cannot be used in other scenarios.
    let base: SuperBase = super;  // Compilation error.
    return super;  // Compilation error.
  }

  static childStaticMethod(): void {
    // Call the parent class static method using super in a static method.
    super.staticMethod();

    // You can also call it using the class name.
    SuperBase.staticMethod();
  }

  constructor() {
    super();  // Call the parent class constructor with super() in the constructor.
  }
}
```

Summary of `super` usage scenarios: `super()` calls the parent class constructor in a constructor, `super.method()` calls a parent class method in an instance method, and `super.staticMethod()` calls a parent class static method in a static method. Accessing a parent class instance property directly through `super` yields `undefined` at runtime; use `this` instead.

## Constructors in Inheritance

A subclass constructor must first call `super()` to complete the initialization of the parent class, and then initialize its own attributes. The construction order follows the inheritance chain from top to bottom.

### Default Behavior of Subclass Constructors

By default, the compiler automatically generates code that calls the parent class constructor in a subclass constructor.

<!-- @[auto_constructor_call](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Inheritance.ets) -->

``` TypeScript
class SimpleParent {
  public value: number = 10;
  
  // The parent class has a constructor.
  constructor(value: number) {
    this.value = value;
  }
}

class SimpleChild extends SimpleParent {
  // The child class has no constructor: the parent class constructor is called automatically.
  // The compiler automatically generates:
  // constructor(value: number) {
  //   super(value);
  // }
  
  getInfo(): string {
    return `Value: ${this.value}`;
  }
}

let callChild: SimpleChild = new SimpleChild(20);
console.info(`${callChild.getInfo()}`);  // 'Value: 20'

class EmptyParent {
  public name: string = 'default';
}

class CallEmptyChild extends EmptyParent {
  // The parent class has a parameterless constructor: the child class does not need to explicitly call super().
  // The compiler automatically generates a default constructor.
  
  // The child class can add its own constructor.
  constructor(name: string) {
    super();
    this.name = name;
  }
}

let callEmpty: CallEmptyChild = new CallEmptyChild('custom');
console.info(`${callEmpty.name}`);  // 'custom'
```

### Rules for Calling super() in a Subclass Constructor

A subclass constructor must call `super()` before any other operations to ensure that the parent class portion is properly initialized.

<!-- @[super_call_rules](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Inheritance.ets) -->

``` TypeScript
class RequiredParent {
  public name: string;
  
  constructor(name: string) {
    this.name = name;
  }
}

class RequiredChild extends RequiredParent {
  public age: number;
  
  constructor(name: string, age: number) {
    // Must call super(), and it must be on the first line.
    super(name);
    this.age = age;
  }
}

let rulesChild: RequiredChild = new RequiredChild('Alice', 25);

class OptionalParent {
  public value: number = 0;
  
  // Constructor with a default parameter.
  constructor(value?: number) {
    if (value !== undefined) {
      this.value = value;
    }
  }
}

class OptionalChild extends OptionalParent {
  public extra: string;
  
  constructor(value?: number, extra?: string) {
    super(value);  // Pass the optional parameter.
    this.extra = extra ?? 'default';
  }
}

let child1: OptionalChild = new OptionalChild();
let child2: OptionalChild = new OptionalChild(10);
let child3: OptionalChild = new OptionalChild(10, 'custom');
```

`super()` call rule: A subclass constructor must call `super()`, which must be the first statement in the constructor, and the arguments must match the parent class constructor signature.

### Scenarios and Timing for Calling super()

When the parent class has a constructor, the child class constructor must call `super()` as its first statement (before accessing `this`). The arguments of `super()` must match the parent class constructor. If the child class does not define a constructor, the compiler automatically generates a default `super()` call.

<!-- @[ts_super_mandatory_call](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Inheritance.ts) -->

``` TypeScript
// Scenarios where super() must be called:

// 1. The parent class has a constructor (no default constructor).
class StrictParent {
  public id: number;

  constructor(id: number) {
    this.id = id;
  }
}

class StrictChild extends StrictParent {
  // super(id) must be called.
  constructor(id: number, name: string) {
    super(id);  // Must be called.
    this.name = name;
  }

  public name: string;
}

// 2. The parent class constructor has required parameters.
class ParameterParent {
  constructor(required: string) {}
}

class ParameterChild extends ParameterParent {
  constructor(required: string, optional?: string) {
    super(required);  // Must pass the required parameters.
  }
}

// 3. All child class constructors must explicitly call super().
class BaseClass {
  // No-parameter constructor.
  constructor() {}
}

class DerivedClass extends BaseClass {
  constructor() {
    super();  // Even if the parent class has no parameters, it must be called explicitly.
  }
}

// Call timing:
// super() must be called before accessing this.
class TimingChild extends StrictParent {
  public name: string;

  constructor(id: number, name: string) {
    console.info(`${this.name}`);  // Compilation error: super() is not called.

    super(id);  // super() must be called first.

    // After super(), this can be accessed.
    this.name = name;
    console.info(`${this.name}`);  // Correct.
  }
}
```

### Passing Parameters Between Child Class and Parent Class Constructors

A child class constructor passes parameters to the parent class constructor for initialization through a `super()` call.

<!-- @[constructor_parameter_passing](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Inheritance.ets) -->

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
    super(name, age, email);  // Pass parameters to the parent class constructor.
    this.phone = phone;
  }
}

let passChild: MultiParamChild = new MultiParamChild('Alice', 25, 'alice@example.com', '123-456');

// Parameter passing:
class FlexibleParent {
  public config: Map<string, string>;
  
  constructor(config: Map<string, string>) {
    this.config = config;
  }
}

class FlexibleChild extends FlexibleParent {
  public name: string;
  
  constructor(name: string, config?: Map<string, string>) {
    // Handle the optional parameter.
    let finalConfig: Map<string, string> = config ?? new Map();
    super(finalConfig);
    this.name = name;
  }
}

let passChild1: FlexibleChild = new FlexibleChild('Test');
let passChild2: FlexibleChild = new FlexibleChild('Test', new Map([['key', 'value']]));

// Pass default parameters.
class DefaultValueParent {
  public value: number;
  
  constructor(value: number = 10) {
    this.value = value;
  }
}

class DefaultValueChild extends DefaultValueParent {
  public extra: number;
  
  constructor(value?: number, extra?: number) {
    super(value ?? 10);  // Pass the default value.
    this.extra = extra ?? 0;
  }
}
```

## Inheritance and Prototype Chain

Class inheritance is implemented through the prototype chain. An instance searches for properties and methods level by level upward along `__proto__`.

### Underlying Prototype Chain Implementation of TypeScript Class Inheritance

TypeScript class inheritance is implemented based on the prototype chain. An instance looks up inherited properties and methods level by level through `__proto__`.

<!-- @[prototype_chain_inheritance](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Inheritance.ets) -->

``` TypeScript
class PrototypeBase {
  methodA(): void {
    console.info('Base methodA');
  }
  
  methodB(): void {
    console.info('Base methodB');
  }
}

class PrototypeChild extends PrototypeBase {
  methodC(): void {
    console.info('Child methodC');
  }
  
  methodA(): void {
    console.info('Child overrides methodA');
  }
}

let chainChild: PrototypeChild = new PrototypeChild();

// Prototype chain structure:
// chainChild -> PrototypeChild.prototype -> PrototypeBase.prototype -> Object.prototype

// Method lookup:
chainChild.methodA();  // PrototypeChild.prototype (overridden)
chainChild.methodB();  // PrototypeBase.prototype (inherited)
chainChild.methodC();  // PrototypeChild.prototype (own)

// Prototype chain verification:
class ChainAnimal {
  public species: string = 'animal';
  
  speak(): void {
    console.info('ChainAnimal speaks');
  }
}

class ChainDog extends ChainAnimal {
  public breed: string = 'chainDog';
  
  speak(): void {
    console.info('ChainDog barks');
  }
}

let chainDog: ChainDog = new ChainDog();

// Prototype chain inheritance relationship:
console.info(`${chainDog instanceof ChainDog}`);      // true
console.info(`${chainDog instanceof ChainAnimal}`);   // true
console.info(`${chainDog instanceof Object}`);   // true
```

Prototype chain lookup mechanism: first look up the instance's own properties and methods; if not found, look up the prototype chain level by level until `Object.prototype`.

### Prototype Chain Lookup Mechanism and Access to Inherited Members

Member lookup proceeds level by level along the prototype chain, starting from the instance itself: it first checks the instance's own properties, then the parent class prototype if not found, and continues upward until `Object.prototype`.

<!-- @[prototype_chain_lookup](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Inheritance.ets) -->

``` TypeScript
class ChainBase {
  public value: number = 10;
  
  baseMethod(): void {
    console.info('Base method');
  }
}

class ChainMiddle extends ChainBase {
  public middleValue: number = 20;
  
  middleMethod(): void {
    console.info('Middle method');
  }
  
  baseMethod(): void {
    console.info('Middle overrides base');
  }
}

class ChainTop extends ChainMiddle {
  public topValue: number = 30;
  
  topMethod(): void {
    console.info('Top method');
  }
  
  middleMethod(): void {
    console.info('Top overrides middle');
  }
}

let top: ChainTop = new ChainTop();

// Prototype chain lookup:
console.info(`${top.topValue}`);      // 30 (own)
console.info(`${top.middleValue}`);   // 20 (inherited from ChainMiddle)
console.info(`${top.value}`);         // 10 (inherited from ChainBase)

top.topMethod();                 // 'Top method' (its own)
top.middleMethod();              // 'Top overrides middle' (overridden)
top.baseMethod();                // 'Middle overrides base' (inherited and overridden)

// Lookup order:
// 1. ChainTop itself -> topMethod, topValue
// 2. ChainMiddle prototype -> middleMethod (overridden), middleValue
// 3. ChainBase prototype -> baseMethod (overridden), value
// 4. Object.prototype

// Method override verification:
class LookupGrandParent {
  method(): string {
    return 'LookupGrandParent';
  }
}

class LookupParent extends LookupGrandParent {
  method(): string {
    return 'LookupParent';
  }
}

class LookupChild extends LookupParent {
  method(): string {
    return 'LookupChild';
  }
  
  callGrandParent(): string {
    // Cannot directly call LookupGrandParent.method()
    // Counterexample: can only be found manually through the prototype chain.
    return 'Direct call not supported';
  }
}
```

### Relationship Between Prototype Inheritance and Class Inheritance

Prototype inheritance and class inheritance are two inheritance approaches. Class inheritance is syntactic sugar for prototype inheritance. The `extends` keyword implements prototype chain inheritance, the `super` keyword calls the parent class constructor and methods, and class methods are defined on the prototype. ArkTS does not support prototype assignment and `function` expressions. Use `class extends` to implement inheritance, and verify the prototype chain relationship with `instanceof`.

<!-- @[class_inheritance_essence](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Inheritance.ets) -->

``` TypeScript
class ProtoAnimalClass {
  public name: string;

  constructor(name: string) {
    this.name = name;
  }

  speak(): void {
    console.info(`${this.name} speaks`);
  }
}

class ProtoDogClass extends ProtoAnimalClass {
  public breed: string;

  constructor(name: string, breed: string) {
    super(name);
    this.breed = breed;
  }

  bark(): void {
    console.info(`${this.name} barks`);
  }
}

let protoDog: ProtoDogClass = new ProtoDogClass('Max', 'Labrador');
protoDog.speak();   // Max speaks
protoDog.bark();    // Max barks

// Verify the prototype chain relationship of class inheritance with instanceof.
console.info(`${protoDog instanceof ProtoDogClass}`); // true
console.info(`${protoDog instanceof ProtoAnimalClass}`); // true
```

**TypeScript Comparison**

<!-- @[ts_class_inheritance_essence](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Inheritance.ts) -->

``` TypeScript
// Prototype inheritance (traditional approach). ArkTS does not support prototype assignment and function expressions.
function animalProto(name: string) {
  this.name = name;
}

animalProto.prototype.speak = function(): void {
  console.info(`${this.name} speaks`);
};

function dogProto(name: string, breed: string) {
  animalProto.call(this, name);
  this.breed = breed;
}

dogProto.prototype = Object.create(animalProto.prototype);
dogProto.prototype.constructor = dogProto;

dogProto.prototype.bark = function(): void {
  console.info(`${this.name} barks`);
};

let dogProtoInstance = new dogProto('Max', 'Labrador');
dogProtoInstance.speak();
dogProtoInstance.bark();
```

### Level Limit and Performance Impact of the Inheritance Chain

It is recommended that the inheritance chain have no more than three levels. An excessively deep inheritance chain increases the difficulty of understanding and the overhead of member lookup. For complex scenarios, consider using the composition pattern instead of deep inheritance.

<!-- @[inheritance_depth_limit](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Inheritance.ets) -->

``` TypeScript
// Recommended level: no more than 3 levels

// Reasonable level
class Level1 {
  baseMethod(): void {}
}

class Level2 extends Level1 {
  middleMethod(): void {}
}

class Level3 extends Level2 {
  topMethod(): void {}
}

let obj: Level3 = new Level3();
obj.baseMethod();    // 3-level lookup
obj.middleMethod();  // 2-level lookup
obj.topMethod();     // 1-level lookup

// Counterexample: excessive depth
class Deep1 { method1(): void {} }
class Deep2 extends Deep1 { method2(): void {} }
class Deep3 extends Deep2 { method3(): void {} }
class Deep4 extends Deep3 { method4(): void {} }
class Deep5 extends Deep4 { method5(): void {} }
class Deep6 extends Deep5 { method6(): void {} }
class Deep7 extends Deep6 { method7(): void {} }

let deep: Deep7 = new Deep7();
deep.method1();  // 7-level lookup (performance impact)

// Performance impact:
// 1. Increased method lookup time
// 2. Increased instantiation overhead
// 3. Increased memory usage

// Alternative: composition over inheritance
class Feature1 { feature1(): void {} }
class Feature2 { feature2(): void {} }
class CombinedFeatures {
  private f1: Feature1 = new Feature1();
  private f2: Feature2 = new Feature2();
  
  feature1(): void {
    this.f1.feature1();
  }
  
  feature2(): void {
    this.f2.feature2();
  }
}
```

### Concept and Implementation of Polymorphism

Polymorphism is a core feature of object-oriented programming. It allows different subclasses to provide different implementations of the same method, so that calling the method through a parent class reference produces different behaviors.

<!-- @[polymorphism_concept](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Inheritance.ets) -->

``` TypeScript
// Polymorphism example: different subclasses implement the same method differently.
class ConceptShape {
  // Parent class method.
  draw(): void {
    console.info('Drawing shape');
  }

  getArea(): number {
    return 0;
  }
}

class ConceptCircle extends ConceptShape {
  public radius: number;

  constructor(radius: number) {
    super();
    this.radius = radius;
  }

  // Overridden method: polymorphic implementation.
  draw(): void {
    console.info(`Drawing circle with radius ${this.radius}`);
  }

  getArea(): number {
    return Math.PI * this.radius * this.radius;
  }
}

class ConceptRectangle extends ConceptShape {
  public width: number;
  public height: number;

  constructor(width: number, height: number) {
    super();
    this.width = width;
    this.height = height;
  }

  // Override the method to implement polymorphism.
  draw(): void {
    console.info(`Drawing rectangle ${this.width}x${this.height}`);
  }

  getArea(): number {
    return this.width * this.height;
  }
}

// Polymorphism: a parent class reference points to a child class instance.
let shapes: ConceptShape[] = [
  new ConceptCircle(5),
  new ConceptRectangle(10, 20),
  new ConceptCircle(3)
];

// Call through the unified interface to exhibit different behaviors.
for (let shape of shapes) {
  shape.draw();
  console.info(`Area: ${shape.getArea()}`);
}
```

The advantage of polymorphism is that all child classes are handled through a unified interface, new types do not affect existing code, and each child class can customize its own behavior.

### Concepts and Purposes of Abstract Classes

An abstract class is a class that cannot be instantiated. It is used to define a common template and contract for its subclasses.

<!-- @[ts_abstract_class_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Inheritance.ts) -->

``` TypeScript
// Abstract class definition: cannot be instantiated, can only be inherited.
abstract class Animal {
  public name: string;

  constructor(name: string) {
    this.name = name;
  }

  // Abstract method: must be implemented by subclasses.
  abstract speak(): void;

  // Concrete method: can be inherited by subclasses.
  move(): void {
    console.info(`${this.name} is moving`);
  }

  // Concrete method: provides a default implementation.
  sleep(): void {
    console.info(`${this.name} is sleeping`);
  }
}

// Subclass implements the abstract class.
class Dog extends Animal {
  public breed: string;

  constructor(name: string, breed: string) {
    super(name);
    this.breed = breed;
  }

  // Implement the abstract method.
  speak(): void {
    console.info(`${this.name} barks`);
  }

  // Override the concrete method.
  move(): void {
    console.info(`${this.name} runs`);
  }
}

class Cat extends Animal {
  public color: string;

  constructor(name: string, color: string) {
    super(name);
    this.color = color;
  }

  // Implement the abstract method.
  speak(): void {
    console.info(`${this.name} meows`);
  }
}

// Cannot instantiate an abstract class.
let animal: Animal = new Animal('Test');  // Compilation error.

// Use it through a subclass.
let dog: Dog = new Dog('Max', 'Labrador');
let cat: Cat = new Cat('Whiskers', 'Orange');

dog.speak();  // Max barks (implemented method)
dog.move();   // Max runs (overridden method)
dog.sleep();  // Max is sleeping (inherited method)

cat.speak();  // Whiskers meows (implemented method)
cat.move();   // Whiskers is moving (inherited method)
cat.sleep();  // Whiskers is sleeping (inherited method)
```

Purpose of an abstract class: to define a common template, force subclasses to implement abstract methods (such as `speak()`), and provide default implementations through concrete methods (such as `move()` and `sleep()`).

## implements Clause and Notes

The `implements` clause checks whether a class satisfies an interface contract. Unlike `extends`, `implements` performs type checking only and does not inherit implementations.

<!-- @[implements_clause](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Inheritance.ets) -->

``` TypeScript
interface InhComparable {
  compareTo(other: Object): number;
}

class InhProduct implements InhComparable {
  public price: number;

  constructor(price: number) {
    this.price = price;
  }

  compareTo(other: Object): number {
    if (other instanceof InhProduct) {
      return this.price - other.price;
    }
    return 0;
  }
}

class InhDiscountedProduct extends InhProduct implements InhComparable {
  public discount: number;

  constructor(price: number, discount: number) {
    super(price);
    this.discount = discount;
  }

  getFinalPrice(): number {
    return this.price * (1 - this.discount);
  }
}
```

`implements` does not change the class type, does not create optional properties, and checks only the instance side. You can use `extends` and `implements` together.

## Inheriting Built-in Types

When inheriting built-in types such as Error and Array under the ES5 target, you may encounter prototype chain issues that require manual fixing.

**TypeScript Comparison**

<!-- @[ts_inherit_builtin_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Inheritance.ts) -->

``` TypeScript
// TypeScript comparison, demonstrating how to fix the prototype chain when inheriting Error
class InhAppError extends Error {
  public code: number;

  constructor(message: string, code: number) {
    super(message);
    this.code = code;

    // Fix the prototype chain (required when the target is ES5)
    Object.setPrototypeOf(this, InhAppError.prototype);
  }

  getInfo(): string {
    return `[${this.code}] ${this.message}`;
  }
}

let inhError: InhAppError = new InhAppError('Not found', 404);
console.info(`${inhError.getInfo()}`);  // [404] Not found
console.info(`${(inhError instanceof InhAppError).toString()}`);  // true
console.info(`${(inhError instanceof Error).toString()}`);  // true
```

ArkTS does not support `Object.setPrototypeOf` and prototype operations. When inheriting built-in types, prefer composition over inheritance.

## Relationships Between Classes

In TypeScript, type compatibility between classes is based on structural typing (duck typing). Classes with the same structure can substitute for each other even without an explicit inheritance relationship. **ArkTS does not support structural typing.** Assignment between classes requires an explicit inheritance or `implements` relationship.

**TypeScript Comparison**

<!-- @[ts_class_structural_relation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Inheritance.ts) -->

``` TypeScript
class InhPoint1 {
  public x: number = 0;
  public y: number = 0;
}

class InhPoint2 {
  public x: number = 0;
  public y: number = 0;
}

// Structurally identical, can be assigned to each other
let inhP1: InhPoint1 = new InhPoint2();
let inhP2: InhPoint2 = new InhPoint1();
console.info(`${inhP1.x.toString()}`);
```

A subtype relationship does not require explicit inheritance — a class that has all members of a parent class automatically becomes a subtype. An empty class has no members and, in a structural type system, is a supertype of any type. Avoid defining empty classes.