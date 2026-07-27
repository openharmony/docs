# 继承
<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

继承是面向对象编程的核心特性，允许子类复用和扩展父类的属性和方法。ArkTS支持单继承，通过extends关键字实现。

## 继承的基础概念

继承让子类复用父类的属性和方法，通过extends关键字建立类型层次，是面向对象编程实现代码复用和多态的核心机制。

### 继承的定义与核心作用

继承通过`extends`关键字建立父子类层次，子类复用父类成员并可扩展或重写，实现多态。

<!-- @[extends_syntax](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Inheritance.ets) -->

``` TypeScript
class Parent {
  // 父类成员
}

class Child extends Parent {
  // 子类成员
}
```

继承让子类复用父类成员以减少重复代码、随父类修改自动同步提升可维护性、通过重写实现多态，并建立清晰的类型层次。

<!-- @[basic_inheritance_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Inheritance.ets) -->

``` TypeScript
// 父类（基类）
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

// 子类（派生类）继承父类
class Dog extends Animal {
  public breed: string;
  
  constructor(name: string, breed: string) {
    super(name);  // 调用父类构造函数
    this.breed = breed;
  }
  
  // 继承父类方法，可以重写
  speak(): void {
    console.info(`${this.name} barks`);
  }
  
  // 新增方法
  fetch(): void {
    console.info(`${this.name} fetches the ball`);
  }
}

let dog: Dog = new Dog('Max', 'Labrador');
dog.speak();   // 'Max barks'（重写方法）
dog.move();    // 'Max moves'（继承方法）
dog.fetch();   // 'Max fetches the ball'（新增方法）
```

继承的作用体现在子类复用父类属性方法、扩展新成员以及通过重写实现多态。

### 基类与派生类的关系

基类（父类）提供通用成员供复用，派生类（子类）在继承的基础上特化扩展，通过`extends`关键字建立层次关系。

<!-- @[base_and_derived_class](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Inheritance.ets) -->

``` TypeScript
// 基类（Base Class）：被继承的类
class Vehicle {
  public brand: string;
  
  constructor(brand: string) {
    this.brand = brand;
  }
  
  start(): void {
    console.info(`${this.brand} vehicle starting`);
  }
}

// 派生类（Derived Class）：继承基类的类
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

// 基类和派生类关系：
// - 基类提供通用属性和方法
// - 派生类继承并特化基类
// - 派生类可以创建多个，形成继承树
```

### 单继承特性

ArkTS只支持单继承，一个子类只能通过`extends`继承一个父类，不支持多继承（如`class C extends A, B`会编译报错）。限制为单继承的原因是：多继承会引入菱形继承问题——当两个父类定义了同名方法时，子类无法确定继承哪一个，导致歧义。若需要复用多个类型的行为，使用`implements`实现多个接口替代多继承，接口只定义契约不包含实现，不会产生冲突。

<!-- @[ts_single_inheritance_limitation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Inheritance.ts) -->

``` TypeScript
// ArkTS只支持单继承：一个子类只能有一个父类
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

// 不能同时继承ParentB
class ErrorChild extends ParentA, ParentB {}  // 编译错误

// 单继承：只能继承一个父类
class Child extends ParentA {
  // 可以继承ParentA
  methodA(): void {
    super.methodA();
    console.info(`Child overrides Method A`);
  }
}

let child: Child = new Child();
child.methodA();  // 'Method A', 'Child overrides Method A'
```

需要组合多个类型的行为时，可以通过实现多个接口来替代多继承。

<!-- @[interface_multi_implementation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Inheritance.ets) -->

``` TypeScript
// 多继承的替代方案：接口实现
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

ArkTS与TypeScript均只支持单类继承（一个子类只能有一个父类）。TypeScript可通过mixins模式在运行时向类混入多个行为，ArkTS对动态混入和对象布局有更严格的静态约束，需借助接口实现或组合模式复用多个能力。

### 继承与代码复用的关联

通过继承复用父类的属性和方法，避免在多个子类中重复编写相同逻辑。

<!-- @[inheritance_code_reuse](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Inheritance.ets) -->

``` TypeScript
// 不使用继承：重复代码
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
    console.info(`${this.name} is eating`);  // 重复代码
  }
  
  sleep(): void {
    console.info(`${this.name} is sleeping`);  // 重复代码
  }
  
  meow(): void {
    console.info(`${this.name} is meowing`);
  }
}

// 使用继承：代码复用
class ReuseAnimal {
  public name: string;
  public age: number;
  
  constructor(name: string, age: number) {
    this.name = name;
    this.age = age;
  }
  
  // 公共方法：子类复用
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
  
  // 特有方法
  bark(): void {
    console.info(`${this.name} is barking`);
  }
}

class Cat extends ReuseAnimal {
  constructor(name: string, age: number) {
    super(name, age);
  }
  
  // 特有方法
  meow(): void {
    console.info(`${this.name} is meowing`);
  }
}

let reuseDog: ReuseDog = new ReuseDog('Max', 3);
let cat: Cat = new Cat('Whiskers', 2);

reuseDog.eat();    // 复用父类方法
reuseDog.sleep();  // 复用父类方法
reuseDog.bark();   // 子类特有方法

cat.eat();    // 复用父类方法
cat.sleep();  // 复用父类方法
cat.meow();   // 子类特有方法
```

## 类的继承语法

类通过`extends`关键字声明继承关系，子类获得父类的非私有成员并可扩展或重写。

### 继承的声明方式

通过`extends`关键字声明继承关系，子类自动获得父类的public和protected成员，可在子类中新增或重写成员。

<!-- @[extends_keyword_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Inheritance.ets) -->

``` TypeScript
// 基类定义
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

// 子类继承声明：使用extends关键字
class Circle extends Shape {
  public radius: number;
  
  constructor(color: string, radius: number) {
    super(color);  // 必须调用父类构造函数
    this.radius = radius;
  }
  
  // 重写父类方法
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

### 子类的定义与父类的关联

子类实例同时包含父类和自身的成员，通过`super`关键字可访问父类的构造函数、方法和属性。

<!-- @[parent_child_relation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Inheritance.ets) -->

``` TypeScript
class Employee {
  // 父类属性
  public name: string;
  public id: number;
  
  constructor(name: string, id: number) {
    this.name = name;
    this.id = id;
  }
  
  // 父类方法
  work(): void {
    console.info(`${this.name} is working`);
  }
  
  getInfo(): string {
    return `Employee ${this.id}: ${this.name}`;
  }
}

class Manager extends Employee {
  // 子类新增属性
  public department: string;
  public teamSize: number;
  
  constructor(name: string, id: number, department: string, teamSize: number) {
    super(name, id);  // 关联父类构造函数
    this.department = department;
    this.teamSize = teamSize;
  }
  
  // 子类新增方法
  manage(): void {
    console.info(`${this.name} manages ${this.teamSize} people in ${this.department}`);
  }
  
  // 重写父类方法
  getInfo(): string {
    return `Manager ${this.id}: ${this.name}, ${this.department} department`;
  }
  
  // 调用父类方法
  getEmployeeInfo(): string {
    return super.getInfo();  // 通过super调用父类方法
  }
}

let manager: Manager = new Manager('Alice', 1, 'Engineering', 10);

// 关联父类属性和方法
console.info(`${manager.name}`);       // 'Alice'（继承父类属性）
console.info(`${manager.id}`);          // 1（继承父类属性）
manager.work();                    // 'Alice is working'（继承父类方法）
console.info(`${manager.getInfo()}`);   // 'Manager 1: Alice, Engineering department'（重写）
console.info(`${manager.getEmployeeInfo()}`);  // 'Employee 1: Alice'（父类方法）

// 子类特有属性和方法
console.info(`${manager.department}`);  // 'Engineering'
console.info(`${manager.teamSize}`);    // 10
manager.manage();                  // 'Alice manages 10 people in Engineering'
```

### 空子类的特性与使用场景

空子类是不添加新成员的子类，用途包括：类型标记（如`class RegularUser extends User`和`class PremiumUser extends User`通过类型区分用户等级）、为未来扩展预留继承位置、在不修改父类的前提下通过`instanceof`做运行时区分。

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

// 空子类：无新增属性和方法
class EmptyChild extends Base {
  // 空子类继承所有父类功能
}

let empty: EmptyChild = new EmptyChild();

// 空子类完全继承父类
console.info(`${empty.getValue()}`);  // 10
empty.increment();
console.info(`${empty.getValue()}`);  // 11

// 空子类使用场景：
// 1. 类型标记：区分不同类别
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

// 通过类型区分用户类别
function getServiceLevel(user: User): string {
  if (user instanceof PremiumUser) {
    return 'Premium service';
  }
  return 'Regular service';
}

console.info(`${getServiceLevel(regular)}`);   // 'Regular service'
console.info(`${getServiceLevel(premium)}`);   // 'Premium service'

// 2. 未来扩展预留
class FutureFeature extends Base {
  // 预留子类，未来可添加功能
}
```

空子类无需显式声明构造函数，创建实例时隐式调用父类构造函数（等价于自动生成`constructor(...args) { super(...args); }`）。

### 继承链与多级继承的概念

继承链是指类之间从基类到派生类的多层继承关系。例如`GrandParent → Parent → Child`构成三级继承链，每层继承父类的`public`和`protected`成员并可添加自己的成员。继承链使代码复用在多个层级间传递，但层数过深会增加理解难度和查找性能开销。

### 继承的层级结构

继承可形成多层结构，子类逐级继承祖先链上的成员，建议层级不超过3层以控制复杂度。

<!-- @[multi_level_inheritance](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Inheritance.ets) -->

``` TypeScript
// 继承层级：多层继承
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
    super.methodGrandParent();  // 调用父类方法
  }
}

class MultiLevelChild extends MultiLevelParent {
  methodChild(): void {
    console.info('MultiLevelChild method');
  }
  
  methodParent(): void {
    console.info('MultiLevelChild overrides MultiLevelParent');
    super.methodParent();  // 调用父类方法
  }
}

let multiLevelChild: MultiLevelChild = new MultiLevelChild();

multiLevelChild.methodChild();           // 'MultiLevelChild method'
multiLevelChild.methodParent();          // 'MultiLevelChild overrides MultiLevelParent', 'MultiLevelParent method'
multiLevelChild.methodGrandParent();     // 'MultiLevelParent overrides GrandParent', 'GrandParent method'

// 继承链查找：从子类到父类
// MultiLevelChild.methodChild() -> MultiLevelChild自身
// MultiLevelChild.methodParent() -> MultiLevelChild重写 -> MultiLevelParent方法
// MultiLevelChild.methodGrandParent() -> MultiLevelParent重写 -> GrandParent方法

// 继承层级限制：避免过深继承
// 推荐：不超过3层继承
// 反例：继承层级过深，增加复杂度
```

## 子类对父类成员的继承

子类按访问修饰符继承父类的属性与方法，`public`和`protected`成员可被子类访问，`private`成员不可继承。

### 子类继承父类的实例属性与方法

子类继承父类的实例属性和方法是继承机制的核心功能，根据访问修饰符决定可继承的内容及访问权限。

<!-- @[ts_access_modifier_inheritance](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Inheritance.ts) -->

``` TypeScript
class Parent {
  // 实例属性
  public publicValue: string = 'public';
  protected protectedValue: string = 'protected';

  // 实例方法
  public publicMethod(): void {
    console.info(`Public method`);
  }

  protected protectedMethod(): void {
    console.info(`Protected method`);
  }

  private privateMethod(): void {
    console.info(`Private method`);
  }

  // 访问私有方法的公开方法
  callPrivate(): void {
    this.privateMethod();
  }
}

class AccessChildTest extends Parent {
  // 继承public属性和方法
  testPublic(): void {
    console.info(`${this.publicValue}`);    // 可访问
    this.publicMethod();               // 可访问
  }

  // 继承protected属性和方法
  testProtected(): void {
    console.info(`${this.protectedValue}`); // 可访问
    this.protectedMethod();            // 可访问
  }

  // 无法继承private属性和方法
  testPrivate(): void {
    this.privateMethod();  // 编译错误
    this.callPrivate();       // 通过公开方法访问
  }
}

let accessChild: AccessChildTest = new AccessChildTest();

accessChild.testPublic();     // 'public', 'Public method'
accessChild.testProtected();  // 'protected', 'Protected method'
accessChild.testPrivate();    // 'Private method'
```

`public`成员完全继承，子类和外部均可访问；`protected`成员继承但仅子类可访问，外部不可访问；`private`成员不继承，子类无法直接访问，只能通过父类提供的`public`方法间接调用。

### 子类继承父类的静态属性与方法

子类继承父类的静态属性和方法，通过类名访问继承的静态成员。

<!-- @[static_member_inheritance](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Inheritance.ets) -->

``` TypeScript
class MemberBase {
  // 静态属性
  public static staticValue: number = 100;
  
  // 静态方法
  public static staticMethod(): void {
    console.info('Static method');
  }
  
  public static getStaticValue(): number {
    return MemberBase.staticValue;
  }
}

class Derived extends MemberBase {
  // 继承静态方法
  callStaticMethod(): void {
    MemberBase.staticMethod();    // 通过父类名调用
    Derived.staticMethod(); // 通过子类名调用（继承）
  }
  
  // 继承静态属性
  getInheritedStaticValue(): number {
    return Derived.getStaticValue();  // 继承的静态方法
  }
  
  // 子类静态方法
  static childStaticMethod(): void {
    console.info('Child static method');
    Derived.staticMethod();  // 调用继承的静态方法
  }
}

// 静态方法通过类名调用
MemberBase.staticMethod();           // 'Static method'
Derived.staticMethod();        // 'Static method'（继承）
Derived.childStaticMethod();   // 'Child static method', 'Static method'

console.info(`${MemberBase.staticValue}`);       // 100
console.info(`${Derived.staticValue}`);    // 100（继承）

let derived: Derived = new Derived();
derived.callStaticMethod();           // 'Static method', 'Static method'
console.info(`${derived.getInheritedStaticValue()}`);  // 100

// 静态成员继承规则：
// 静态属性和方法通过类名访问
// 子类继承父类的静态成员
// 子类可以添加自己的静态成员
```

### 继承成员的访问权限规则

子类可访问父类的public和protected成员，private成员不可直接访问；通过访问修饰符控制成员在继承链中的可见性。

<!-- @[ts_access_permission_rules](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Inheritance.ts) -->

``` TypeScript
class AccessBase {
  public publicProp: string = 'public';
  protected protectedProp: string = 'protected';
  private privateProp: string = 'private';

  public publicMethod(): void {}
  protected protectedMethod(): void {}
  private privateMethod(): void {}

  // 访问所有属性
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
  // 子类访问规则
  testAccess(): void {
    // public：可访问
    console.info(`${this.publicProp}`);
    this.publicMethod();

    // protected：可访问
    console.info(`${this.protectedProp}`);
    this.protectedMethod();

    // private：不可访问
    console.info(`${this.privateProp}`);  // 编译错误
    this.privateMethod();           // 编译错误
  }

  // 通过父类公开方法访问私有成员
  usePrivate(): void {
    this.accessAll();  // 调用父类方法
  }
}

// 外部访问规则
let permChild: AccessChild = new AccessChild();

// public：外部可访问
console.info(`${permChild.publicProp}`);    // 'public'
permChild.publicMethod();

// protected：外部不可访问
console.info(`${permChild.protectedProp}`);  // 编译错误
permChild.protectedMethod();           // 编译错误

// private：外部不可访问
console.info(`${permChild.privateProp}`);   // 编译错误

// 访问权限总结：
// public：无限制访问
// protected：类及子类访问
// private：仅类内部访问
```

### 子类无法访问的父类成员

子类无法访问的父类成员主要是private成员，通过封装保护父类的内部实现。

<!-- @[ts_private_member_restriction](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Inheritance.ts) -->

``` TypeScript
class SecretBase {
  private secretKey: string = 'secret';
  private privateKey: number = 123;

  private privateMethod(): void {
    console.info(`Private method in base`);
  }

  // 私有方法使用内部逻辑
  private internalProcess(): void {
    console.info(`Internal processing`);
  }

  // 公开接口访问私有成员
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
  // 无法访问父类私有成员
  attemptAccess(): void {
    console.info(`${this.secretKey}`);      // 编译错误
    console.info(`${this.privateKey}`);     // 编译错误
    this.privateMethod();              // 编译错误
    this.internalProcess();            // 编译错误

    // 通过公开接口访问
    console.info(`${this.getSecretKey()}`);  // 可访问
  }

  // 无法重写父类私有方法
  privateMethod(): void {}  // 编译错误

  // 可以定义同名私有方法（独立）
  private childPrivateKey: number = 456;  // 子类自己的私有属性
}

let secret: SecretChild = new SecretChild();
console.info(`${secret.getSecretKey()}`);  // secret
secret.setSecretKey('newsecretkey');
console.info(`${secret.getSecretKey()}`);  // newsecretkey
```

## 子类对父类方法的重写

子类重新定义父类方法实现多态，重写时方法签名须与父类一致且访问权限不能更严格。

### 方法重写与属性覆盖的概念

方法重写指子类提供同名方法的全新实现，属性覆盖指子类重新定义父类属性。重写时可通过`super`调用父类原始实现。`override`关键字标记被重写的方法，使编译器在父类方法被重命名或删除时报错，推荐使用。

### 方法重写的语法

方法重写规则要求子类与父类方法签名一致且访问修饰符不能更严格。

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
  // 重写父类方法：相同签名
  sendMessage(message: string): void {
    console.info(`Sending email: ${message}`);
  }
  
  // 重写并扩展
  formatMessage(content: string): string {
    let formatted: string = super.formatMessage(content);  // 调用父类方法
    return `[Email] ${formatted}`;
  }
  
  // 新增方法
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

方法重写规则：要求子类与父类方法名相同、参数类型与数量一致、返回类型相同或兼容，且访问权限不能更严格。

### 重写方法的参数与返回值匹配规则

重写方法的参数和返回值必须与父类方法保持匹配，确保类型安全。

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
  // 参数和返回值必须完全匹配
  process(value: number): number {
    return value * 3;  // 返回值类型相同
  }

  // 返回值兼容（子类返回类型可以是父类返回值的子类型）
  convert(input: string): number {
    let result: number = super.convert(input);
    return result * 10;
  }

  // 不能改变参数类型
  process(value: string): number {}  // 编译错误

  // 不能改变参数数量
  process(value: number, extra: number): number {}  // 编译错误

  // 不能改变返回类型为不兼容类型
  process(value: number): string {}  // 编译错误
}

let processor: AdvancedProcessor = new AdvancedProcessor();

console.info(`${processor.process(5).toString()}`);      // 15
console.info(`${processor.convert('10').toString()}`);   // 100

// 父类引用指向子类实例
let baseProcessor: NumberProcessor = new AdvancedProcessor();
console.info(`${baseProcessor.process(5).toString()}`);  // 15（调用子类重写方法）
```

### 重写方法的访问权限规则

子类方法的访问权限必须不低于父类方法。

<!-- @[override_access_permission](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Inheritance.ets) -->

``` TypeScript
class AccessParent {
  // public方法
  public publicMethod(): void {
    console.info(`Parent public`);
  }

  // protected方法
  protected protectedMethod(): void {
    console.info(`Parent protected`);
  }
}

class OverrideAccessChild extends AccessParent {
  // 重写public方法：必须保持public
  public publicMethod(): void {
    console.info(`Child public`);
  }

  // 重写protected方法：可保持protected或改为public
  public protectedMethod(): void {
    console.info(`Child public (was protected)`);
  }

  // 不能降低访问权限
  protected loweredAccessMethod(): void {}  // 编译错误：不能从public改为protected

  // 不能重写private方法（因为无法访问）
  privateMethod(): void {}  // 编译错误：父类方法不可见
}

let overrideChild: OverrideAccessChild = new OverrideAccessChild();

overrideChild.publicMethod();     // 'Child public'
overrideChild.protectedMethod();  // 'Child public (was protected)'
```

重写方法不能降低访问权限：`public`方法重写后必须保持`public`；`protected`方法重写后可保持`protected`或改为`public`；`private`方法不能重写（子类无法访问）。

## 父类成员的调用

子类通过super关键字调用父类的构造函数、方法和属性。

### super关键字的用途与概念

`super`关键字用于在子类中调用父类的构造函数（`super()`）、实例方法（`super.method()`）和属性，是方法重写时复用父类逻辑的关键。

### 通过super关键字调用父类的实例方法

使用`super.方法名()`调用父类实例方法，常在重写方法中复用父类逻辑后再添加子类特有行为。

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
  // 重写并调用父类方法
  work(): void {
    super.work();  // 调用父类work方法
    console.info('ParentManager managing');
  }
  
  // 完全重写
  rest(): void {
    console.info('ParentManager taking break');
    // 不调用super.rest()
  }
  
  // 扩展父类返回值
  report(): string {
    let baseReport: string = super.report();
    return `${baseReport}, ParentManager report`;
  }
  
  // 组合调用
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

// super调用规则：
// super.methodName() 调用父类实例方法
// 必须在子类实例方法中使用
// 可以在重写方法的任何位置调用
```

### 通过super关键字调用父类的构造函数

通过`super()`调用父类构造函数，用于初始化子类实例中的父类部分，必须放在子类构造函数的第一行。

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
    super(name, age);  // 必须先调用父类构造函数
    this.grade = grade;
    console.info('Student constructor');
  }
}

let student: Student = new Student('Alice', 20, 'A');
// 输出：'Person constructor', 'Student constructor'

class CtorEmployee extends Person {
  public department: string;
  
  constructor(name: string, age: number, department: string) {
    super(name, age);  // 传递参数给父类构造函数
    this.department = department;
  }
  
  getInfo(): string {
    return `${this.name}, ${this.age}, ${this.department}`;
  }
}

let employee: CtorEmployee = new CtorEmployee('Bob', 30, 'Engineering');
console.info(`${employee.getInfo()}`);  // 'Bob, 30, Engineering'

// super() 调用规则：
// 子类构造函数必须调用super()
// super() 必须在子类构造函数第一行
// super() 传递参数给父类构造函数
```

### 子类静态方法中调用父类静态成员

子类静态方法通过类名调用父类静态成员，不能使用super关键字。

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

  // 子类静态方法调用父类静态方法
  static combinedMethod(): void {
    StaticBase.baseMethod();   // 通过父类名调用
    StaticChild.baseMethod();  // 通过子类名调用（继承）
  }

  // 子类静态方法访问父类静态属性
  static getTotalValue(): number {
    return StaticBase.baseValue + StaticChild.childValue;
  }

  // 调用继承的静态方法
  static getInheritedValue(): number {
    return StaticChild.getValue();  // 继承的静态方法
  }

  // 注意：静态方法中不能使用super
  static invalidMethod(): void {
    super.baseMethod();  // 编译错误：super不能用于静态方法
  }
}

StaticChild.combinedMethod();       // 'Base static method', 'Base static method'
console.info(`${StaticChild.getTotalValue()}`);       // 30
console.info(`${StaticChild.getInheritedValue()}`);   // 10

// 静态方法调用规则：
// 通过类名调用静态成员
// 子类名可调用继承的静态成员
// 不能在静态方法中使用super
```

### super关键字的使用场景与限制

super的使用场景包括：调用父类构造函数（`super()`）、调用父类方法（`super.method()`）；限制包括：`super()`必须在构造函数第一行、不能在静态方法中使用、不能通过`super`直接访问父类属性（应使用`this`）。

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
    // super调用父类方法
    super.method();  // 正确

    // super不能直接访问父类实例属性
    console.info(`${super.value}`);  // 运行时为undefined，应使用this访问

    // 应使用this或父类名访问属性
    console.info(`${this.value}`);          // 20（子类属性）
    console.info(`${SuperChild.prototype.value}`); // 反例：父类属性
  }

  anotherMethod(): void {
    // super只能调用方法
    super.method();

    // 不能用于其他场景
    let base: SuperBase = super;  // 编译错误
    return super;  // 编译错误
  }

  static childStaticMethod(): void {
    // 静态方法中使用super调用父类静态方法
    super.staticMethod();

    // 也可使用类名调用
    SuperBase.staticMethod();
  }

  constructor() {
    super();  // 构造函数中使用super() 调用父类构造
  }
}
```

super使用场景总结：`super()`在构造函数中调用父类构造，`super.method()`在实例方法中调用父类方法，`super.staticMethod()`在静态方法中调用父类静态方法。通过`super`直接访问父类实例属性时运行时为`undefined`，应使用`this`访问。

## 继承中的构造函数

子类构造函数必须先调用`super()`完成父类初始化，再初始化自身属性，构造顺序沿继承链自上而下。

### 子类构造函数的默认行为

子类构造函数的默认行为是编译器自动生成调用父类构造函数的代码。

<!-- @[auto_constructor_call](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Inheritance.ets) -->

``` TypeScript
class SimpleParent {
  public value: number = 10;
  
  // 父类有构造函数
  constructor(value: number) {
    this.value = value;
  }
}

class SimpleChild extends SimpleParent {
  // 子类无构造函数：自动调用父类构造函数
  // 编译器自动生成：
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
  // 父类无参数构造函数：子类无需显式调用super()
  // 编译器自动生成默认构造函数
  
  // 子类可添加自己的构造函数
  constructor(name: string) {
    super();
    this.name = name;
  }
}

let callEmpty: CallEmptyChild = new CallEmptyChild('custom');
console.info(`${callEmpty.name}`);  // 'custom'
```

### 子类构造函数中super() 的调用规则

子类构造函数必须在任何其他操作之前调用super()，以确保父类部分正确初始化。

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
    // 必须调用super()，且必须在第一行
    super(name);
    this.age = age;
  }
}

let rulesChild: RequiredChild = new RequiredChild('Alice', 25);

class OptionalParent {
  public value: number = 0;
  
  // 默认参数构造函数
  constructor(value?: number) {
    if (value !== undefined) {
      this.value = value;
    }
  }
}

class OptionalChild extends OptionalParent {
  public extra: string;
  
  constructor(value?: number, extra?: string) {
    super(value);  // 传递可选参数
    this.extra = extra ?? 'default';
  }
}

let child1: OptionalChild = new OptionalChild();
let child2: OptionalChild = new OptionalChild(10);
let child3: OptionalChild = new OptionalChild(10, 'custom');
```

super() 调用规则：子类构造函数必须调用`super()`，且必须位于构造函数第一行，参数须匹配父类构造函数签名。

### 必须调用super() 的场景与时机

当父类有构造函数时，子类构造函数必须调用`super()`且必须是第一条语句（在访问`this`之前）。`super()`的参数须与父类构造函数匹配。若子类未定义构造函数，编译器自动生成默认`super()`调用。

<!-- @[ts_super_mandatory_call](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Inheritance.ts) -->

``` TypeScript
// 必须调用super() 的场景：

// 1. 父类有构造函数（无默认构造函数）
class StrictParent {
  public id: number;

  constructor(id: number) {
    this.id = id;
  }
}

class StrictChild extends StrictParent {
  // 必须调用super(id)
  constructor(id: number, name: string) {
    super(id);  // 必须调用
    this.name = name;
  }

  public name: string;
}

// 2. 父类构造函数有必需参数
class ParameterParent {
  constructor(required: string) {}
}

class ParameterChild extends ParameterParent {
  constructor(required: string, optional?: string) {
    super(required);  // 必须传递必需参数
  }
}

// 3. 所有子类构造函数都必须显式调用super()
class BaseClass {
  // 无参数构造函数
  constructor() {}
}

class DerivedClass extends BaseClass {
  constructor() {
    super();  // 即使父类无参数，也必须显式调用
  }
}

// 调用时机：
// super() 必须在访问this之前
class TimingChild extends StrictParent {
  public name: string;

  constructor(id: number, name: string) {
    console.info(`${this.name}`);  // 编译错误：super() 未调用

    super(id);  // 必须先调用super()

    // super() 后可访问this
    this.name = name;
    console.info(`${this.name}`);  // 正确
  }
}
```

### 子类构造函数与父类构造函数的参数传递

子类构造函数通过super()调用将参数传递给父类构造函数进行初始化。

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
    super(name, age, email);  // 传递参数给父类构造函数
    this.phone = phone;
  }
}

let passChild: MultiParamChild = new MultiParamChild('Alice', 25, 'alice@example.com', '123-456');

// 参数传递方式：
class FlexibleParent {
  public config: Map<string, string>;
  
  constructor(config: Map<string, string>) {
    this.config = config;
  }
}

class FlexibleChild extends FlexibleParent {
  public name: string;
  
  constructor(name: string, config?: Map<string, string>) {
    // 处理可选参数
    let finalConfig: Map<string, string> = config ?? new Map();
    super(finalConfig);
    this.name = name;
  }
}

let passChild1: FlexibleChild = new FlexibleChild('Test');
let passChild2: FlexibleChild = new FlexibleChild('Test', new Map([['key', 'value']]));

// 默认参数传递
class DefaultValueParent {
  public value: number;
  
  constructor(value: number = 10) {
    this.value = value;
  }
}

class DefaultValueChild extends DefaultValueParent {
  public extra: number;
  
  constructor(value?: number, extra?: number) {
    super(value ?? 10);  // 传递默认值
    this.extra = extra ?? 0;
  }
}
```

## 继承与原型链

类继承通过原型链实现，实例沿__proto__逐级向上查找属性和方法。

### TypeScript类继承的底层原型链实现

TypeScript类继承底层基于原型链，实例通过`__proto__`逐级向上查找继承的属性和方法。

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

// 原型链结构：
// chainChild -> PrototypeChild.prototype -> PrototypeBase.prototype -> Object.prototype

// 方法查找：
chainChild.methodA();  // PrototypeChild.prototype（重写）
chainChild.methodB();  // PrototypeBase.prototype（继承）
chainChild.methodC();  // PrototypeChild.prototype（自有）

// 原型链验证：
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

// 原型链继承关系：
console.info(`${chainDog instanceof ChainDog}`);      // true
console.info(`${chainDog instanceof ChainAnimal}`);   // true
console.info(`${chainDog instanceof Object}`);   // true
```

原型链查找机制：先查找实例自身属性和方法，未命中则逐级向上查找原型链，直到`Object.prototype`。

### 原型链的查找机制与继承成员的访问

成员查找沿原型链从自身向上一级级查找：先查实例自身属性，未命中则查父类原型，依次向上直到Object.prototype。

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

// 原型链查找：
console.info(`${top.topValue}`);      // 30（自身）
console.info(`${top.middleValue}`);   // 20（继承自ChainMiddle）
console.info(`${top.value}`);         // 10（继承自ChainBase）

top.topMethod();                 // 'Top method'（自身）
top.middleMethod();              // 'Top overrides middle'（重写）
top.baseMethod();                // 'Middle overrides base'（继承并重写）

// 查找顺序：
// 1. ChainTop自身 -> topMethod, topValue
// 2. ChainMiddle原型 -> middleMethod（重写），middleValue
// 3. ChainBase原型 -> baseMethod（重写），value
// 4. Object.prototype

// 方法覆盖验证：
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
    // 无法直接调用LookupGrandParent.method()
    // 反例：只能通过原型链手动查找
    return 'Direct call not supported';
  }
}
```

### 原型继承与类继承的关联

原型继承与类继承是两种继承方式，类继承是原型继承的语法糖。`extends`关键字实现原型链继承，`super`关键字调用父类构造函数和方法，类方法定义在原型上。ArkTS不支持原型赋值和`function`表达式，使用`class extends`实现继承，通过`instanceof`验证原型链关系。

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

// instanceof验证类继承的原型链关系
console.info(`${protoDog instanceof ProtoDogClass}`); // true
console.info(`${protoDog instanceof ProtoAnimalClass}`); // true
```

**TypeScript对照**

<!-- @[ts_class_inheritance_essence](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Inheritance.ts) -->

``` TypeScript
// 原型继承（传统方式），ArkTS不支持prototype赋值和function表达式
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

### 继承链的层级限制与性能影响

继承链建议不超过3层，过深的继承会增加理解难度和成员查找开销；复杂场景可考虑组合模式替代深层继承。

<!-- @[inheritance_depth_limit](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Inheritance.ets) -->

``` TypeScript
// 推荐层级：不超过3层

// 合理层级
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
obj.baseMethod();    // 3层查找
obj.middleMethod();  // 2层查找
obj.topMethod();     // 1层查找

// 反例：过深层级
class Deep1 { method1(): void {} }
class Deep2 extends Deep1 { method2(): void {} }
class Deep3 extends Deep2 { method3(): void {} }
class Deep4 extends Deep3 { method4(): void {} }
class Deep5 extends Deep4 { method5(): void {} }
class Deep6 extends Deep5 { method6(): void {} }
class Deep7 extends Deep6 { method7(): void {} }

let deep: Deep7 = new Deep7();
deep.method1();  // 7层查找（性能影响）

// 性能影响：
// 1. 方法查找时间增加
// 2. 实例化开销增加
// 3. 内存占用增加

// 替代方案：组合优于继承
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

### 多态的概念与实现

多态是面向对象编程的核心特性，允许不同子类对同一方法有不同实现，通过父类引用调用时表现出不同行为。

<!-- @[polymorphism_concept](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Inheritance.ets) -->

``` TypeScript
// 多态示例：不同子类对同一方法的不同实现
class ConceptShape {
  // 父类方法
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

  // 重写方法：多态实现
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

  // 重写方法：多态实现
  draw(): void {
    console.info(`Drawing rectangle ${this.width}x${this.height}`);
  }

  getArea(): number {
    return this.width * this.height;
  }
}

// 多态：父类引用指向子类实例
let shapes: ConceptShape[] = [
  new ConceptCircle(5),
  new ConceptRectangle(10, 20),
  new ConceptCircle(3)
];

// 统一接口调用：表现出不同行为
for (let shape of shapes) {
  shape.draw();
  console.info(`Area: ${shape.getArea()}`);
}
```

多态优势在于用统一接口处理所有子类、新增类型不影响现有代码、每个子类可定制自身行为。

### 抽象类的概念与用途

抽象类是不能被实例化的类，用于定义子类的通用模板和契约。

<!-- @[ts_abstract_class_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Inheritance.ts) -->

``` TypeScript
// 抽象类定义：不能实例化，只能继承
abstract class Animal {
  public name: string;

  constructor(name: string) {
    this.name = name;
  }

  // 抽象方法：子类必须实现
  abstract speak(): void;

  // 具体方法：子类可继承
  move(): void {
    console.info(`${this.name} is moving`);
  }

  // 具体方法：提供默认实现
  sleep(): void {
    console.info(`${this.name} is sleeping`);
  }
}

// 子类实现抽象类
class Dog extends Animal {
  public breed: string;

  constructor(name: string, breed: string) {
    super(name);
    this.breed = breed;
  }

  // 实现抽象方法
  speak(): void {
    console.info(`${this.name} barks`);
  }

  // 重写具体方法
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

  // 实现抽象方法
  speak(): void {
    console.info(`${this.name} meows`);
  }
}

// 不能实例化抽象类
let animal: Animal = new Animal('Test');  // 编译错误

// 通过子类使用
let dog: Dog = new Dog('Max', 'Labrador');
let cat: Cat = new Cat('Whiskers', 'Orange');

dog.speak();  // Max barks（实现的方法）
dog.move();   // Max runs（重写的方法）
dog.sleep();  // Max is sleeping（继承的方法）

cat.speak();  // Whiskers meows（实现的方法）
cat.move();   // Whiskers is moving（继承的方法）
cat.sleep();  // Whiskers is sleeping（继承的方法）
```

抽象类作用：定义通用模板、强制子类实现抽象方法（如`speak()`），并可通过具体方法（如`move()`和`sleep()`）提供默认实现。

## implements子句与注意事项

`implements`子句用于检查类是否满足接口契约。与`extends`不同，`implements`仅做类型检查，不继承实现。

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

`implements`不改变类类型、不创建可选属性、只检查实例侧。可同时使用`extends`和`implements`。

## 继承内置类型

继承Error、Array等内置类型在ES5 target下可能遇到原型链问题，需要手动修复。

**TypeScript对照**

<!-- @[ts_inherit_builtin_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Inheritance.ts) -->

``` TypeScript
// TypeScript对照写法，演示继承Error时修复原型链
class InhAppError extends Error {
  public code: number;

  constructor(message: string, code: number) {
    super(message);
    this.code = code;

    // 修复原型链（target为ES5时需要）
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

ArkTS不支持`Object.setPrototypeOf`和prototype操作。继承内置类型时优先使用组合而非继承。

## 类之间的关系

TypeScript中类之间的类型兼容性基于结构类型（鸭子类型），结构相同的类可互相替代，即使没有显式继承关系。**ArkTS不支持结构类型**，类之间的赋值必须有显式继承或`implements`关系。

**TypeScript对照**

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

// 结构相同，可互相赋值
let inhP1: InhPoint1 = new InhPoint2();
let inhP2: InhPoint2 = new InhPoint1();
console.info(`${inhP1.x.toString()}`);
```

子类型关系无需显式继承——有父类所有成员的类自动成为子类型。空类没有成员，在结构类型系统中是任何类型的超类型，应避免定义空类。
