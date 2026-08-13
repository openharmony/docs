# Initialization

<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=e25164b4c5d2db315865d228475dc21473dba5fb translatedAt=2026-08-13T09:00:38.512Z pushedAt=2026-08-13T13:17:50.460Z -->

ArkTS sets the initial state of an object when it is created through mechanisms such as constructors, property initializers, and static initialization blocks, ensuring that the object is in a usable state after creation.

## Basic Concepts of Initialization

Initialization sets the initial values of properties when an object is created, ensuring that the object is in a usable state through constructors and default values. It is the first line of defense for type safety.

### Definition and Purpose of Initialization

Initialization sets valid initial values for properties when an object is created, through mechanisms such as default values, constructors, initialization order, and static initialization.

<!-- @[basic_constructor_initialization](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
class Person {
  public name: string;
  public age: number;
  
  // Constructor: initializes the object.
  constructor(name: string, age: number) {
    this.name = name;  // Initialize the name property.
    this.age = age;    // Initialize the age property.
  }
  
  getInfo(): string {
    return `${this.name}, ${this.age} years old`;
  }
}

let person: Person = new Person('Alice', 25);
console.info(`${person.getInfo()}`);  // 'Alice, 25 years old'
```

The purposes of initialization include setting the initial state of an object, allocating and initializing properties, preparing the resources required for use, and validating the initial parameters.

### Concept and Core Responsibilities of a Constructor

A constructor is a special method of a class that is used to initialize objects and is an important part of the object lifecycle.

``` TypeScript
class ClassName {
  constructor(parameters) {
    // Initialization code
  }
}
```

<!-- @[constructor_responsibilities](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
class DatabaseConnection {
  private connection: string;
  private connected: boolean;
  private timeout: number;
  
  // Constructor responsibilities
  constructor(connectionString: string, timeout: number = 5000) {
    // 1. Property initialization
    this.connection = connectionString;
    this.timeout = timeout;
    this.connected = false;
    
    // 2. Validate parameters.
    if (connectionString.length === 0) {
      throw new Error('Connection string cannot be empty');
    }
    
    // 3. Prepare resources.
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

Summary of constructor responsibilities: A constructor is responsible for initializing all properties, validating parameter validity, preparing necessary resources, and setting the initial state.

### Timing and Methods of Property Initialization

There are three timings for property initialization: initialization at declaration (`public name = 'default'`), assignment in the constructor body, and deferred assignment (an optional property marked with `?` is assigned before use). The timing depends on the source of the value: a fixed default value is initialized at declaration, a dynamic value is assigned in the constructor, and a value determined at runtime uses deferred assignment through an optional property.

### Instance Creation and Initialization Process

When an instance is created with `new`, the following steps are executed in sequence: field default value initialization and assignment in the constructor body. Finally, all properties of the object are in a valid state.

<!-- @[initialization_flow](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
class Order {
  public id: number;
  public items: string[];
  public total: number;
  public status: string;
  public createdAt: Date;
  
  constructor(id: number) {
    // Initialization process:
    
    // 1. Property initialization
    this.id = id;
    this.items = [];
    this.total = 0;
    this.status = 'pending';
    
    // 2. Calculate the initial value
    this.createdAt = new Date();
    
    // 3. Verify the initial state.
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

// Creation process:
// new Order(1) -> constructor call -> property initialization -> state setting -> instance return
let order: Order = new Order(1);
order.addItem('Item A', 100);
order.addItem('Item B', 200);
order.complete();
```

## Declaring and Using Constructors

A constructor is declared with the `constructor` keyword and is automatically invoked when an instance is created with `new`. It is used to initialize properties and set the initial state.

### Purpose and Use Scenarios of Default Values

Assign initial values directly to property declarations or constructor parameters. When no value is provided when creating an instance or calling a function, the preset value is used to avoid `undefined`.

### Default Constructor (Parameterless Constructor)

A default constructor is a parameterless constructor that the compiler automatically generates when no constructor is defined.

<!-- @[default_constructor](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
class SimpleClass {
  public value: number = 10;
  public name: string = 'default';
  
  // No constructor: the compiler automatically generates a default constructor
  // constructor() {}  // Automatically generated
}

let simple: SimpleClass = new SimpleClass();
console.info(`${simple.value.toString()}`);  // 10
console.info(`${simple.name}`);   // 'default'

class DefaultConstructor {
  public x: number = 0;
  public y: number = 0;
  
  // Explicit parameterless constructor
  constructor() {
    console.info('Default constructor called');
  }
  
  getValues(): string {
    return `${this.x}, ${this.y}`;
  }
}

let defaultObj: DefaultConstructor = new DefaultConstructor();
console.info(`${defaultObj.getValues()}`);  // '0, 0'

// Default constructor:
// No parameters
// Automatically initializes properties to default values
// Automatically generated by the compiler (if not defined)
```

### Custom Constructor (Parameterized Constructor)

A custom constructor is a parameterized constructor that receives initial values through parameters for initialization.

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

// Custom constructor:
// Define parameters to receive initial values.
// Assign the parameters to properties.
// Validation logic can be added.
```

### Constructor Access Control (public/private and Other Modifiers)

Use the public/private/protected modifiers to control the instantiation permission of a constructor: a private constructor is often used for the singleton pattern, and a protected constructor allows only subclasses to instantiate the class.

<!-- @[constructor_access_modifiers](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
class PublicConstructor {
  public value: number;
  
  // public constructor (default)
  public constructor(value: number) {
    this.value = value;
  }
}

let publicObj: PublicConstructor = new PublicConstructor(10);

class PrivateConstructor {
  private static instance: PrivateConstructor;
  
  // private constructor: singleton pattern
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
  
  // protected constructor: accessible to subclasses
  protected constructor(value: number) {
    this.value = value;
  }
}

class ChildOfProtected extends ProtectedConstructor {
  public constructor(value: number) {
    super(value);  // A subclass can call a protected constructor.
  }
}

let child: ChildOfProtected = new ChildOfProtected(20);
```

### Syntax for Instantiating an Object

Use the `new` keyword to call the constructor and complete instantiation: allocate memory -> call the constructor to initialize properties -> return the instance reference.

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

// Instantiate with the new keyword.
let product1: Product = new Product(1, 'Product A');
let product2: Product = new Product(2, 'Product B');

console.info(`${product1.name}`);  // 'Product A'
console.info(`${product2.name}`);  // 'Product B'

// Instantiation process:
// 1. The new keyword creates an object.
// 2. Call the constructor.
// 3. Return the new instance.

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

## Constructor Overloading

Constructor overloading supports multiple initialization approaches, allowing flexible object creation.

### Declaration Rules for Constructor Overloading (Same Name, Different Parameters)

By declaring multiple constructor signatures with different parameter lists, objects can be initialized with different parameter combinations, and the compiler automatically matches the corresponding signature based on the passed arguments.

<!-- @[constructor_overloading](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
class OverloadPoint {
  public x: number;
  public y: number;
  
  // Constructor overload signature
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
      // Parse from hexadecimal.
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

### How to Call Overloaded Constructors

Based on the number and types of the arguments passed in, the compiler automatically matches the most appropriate constructor signature and invokes the corresponding initialization logic.

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

### When to Use Constructor Overloading

Constructor overloading is used to support multiple initialization approaches, such as initialization with default values, partial parameter initialization, and full parameter initialization. Design overloads with clear naming and logical hierarchy based on the types and number of parameters.

<!-- @[static_factory_methods_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
// Use case: multiple initialization approaches
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

// Use a static factory method instead of complex overloading
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

## Constructors in Inheritance

A subclass constructor must first call the superclass constructor through `super()` to complete initialization of the superclass part, and then initialize the subclass's own properties.

### Default Behavior of Subclass Constructors

When a subclass constructor does not explicitly call the superclass constructor, if the superclass has a parameterless constructor, the compiler automatically generates code that calls the superclass parameterless constructor; if the superclass has only parameterized constructors, a compilation error occurs.

<!-- @[inheriting_parent_constructor](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
class Parent {
  public value: number;
  
  constructor(value: number) {
    this.value = value;
  }
}

class Child extends Parent {
  // The subclass has no constructor: it automatically inherits the superclass constructor.
  // Generated by the compiler:
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
  
  // Parameterless constructor
  constructor() {
    console.info('Parent constructor');
  }
}

class EmptyChild extends EmptyParent {
  // Automatically call the superclass no-argument constructor.
  public age: number = 20;
}

let emptyChild: EmptyChild = new EmptyChild();
```

### Rules for Calling the Superclass Constructor with super()

A subclass constructor must call the superclass constructor through `super()`, and `super()` must be the first statement in the constructor body, executed before any access to `this`.

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
    super(brand);  // super() must be called first.
    this.model = model;
    console.info(`Car constructor`);
  }

  getInfo(): string {
    return `${this.brand} ${this.model}`;
  }
}

let car: Car = new Car('Toyota', 'Camry');
// Output: 'Vehicle constructor', 'Car constructor'

// super() rules:
// 1. The subclass constructor must call super().
// 2. super() must be on the first line.
// 3. The super() parameters must match the superclass constructor.

class InvalidChild extends Vehicle {
  public model: string;

  constructor(brand: string, model: string) {
    this.model = model;  // Compilation error: super() is not called.

    super(brand);  // Must be before accessing this.

    this.model = model;  // Correct
  }
}
```

### Scenarios and Timing for Mandatory super() Calls

When the parent class defines a constructor, the subclass constructor must explicitly call `super()` and must do so before using `this`.

<!-- @[ts_super_call_scenarios](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Initialization.ts) -->

``` TypeScript
// Scenarios where super() must be called:

// 1. The parent class has a constructor (with or without parameters)
class RequiredParent {
  public name: string;

  constructor(name: string) {
    this.name = name;
  }
}

class RequiredChild extends RequiredParent {
  public age: number;

  constructor(name: string, age: number) {
    super(name);  // Mandatory
    this.age = age;
  }
}

// 2. All inherited subclasses (unless the parent class has no explicit constructor)
class ImplicitParent {
  public value: number = 10;
  // No explicit constructor
}

class ImplicitChild extends ImplicitParent {
  public extra: number = 20;

  constructor() {
    super();  // Automatically called (can be omitted)
  }
}

// Call timing: must be before accessing this
class TimingParent {
  constructor() {}
}

class TimingChild extends TimingParent {
  public value: number;

  constructor() {
    console.info(`${this.value}`);  // Compilation error

    super();  // Must be called first.

    this.value = 10;  // Correct.
    console.info(`${this.value}`);  // Correct.
  }
}
```

### Passing Parameters Between Subclass and Superclass Constructors

A subclass constructor forwards parameters to the superclass constructor through `super(...)`.

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
    super(name, age, email);  // Pass all superclass parameters.
    this.phone = phone;
  }
  
  getInfo(): string {
    return `${this.name}, ${this.age}, ${this.email}, ${this.phone}`;
  }
}

let superChild: MultiParamChild = new MultiParamChild('Alice', 25, 'alice@example.com', '123-456');

// Parameter handling:
class FlexibleParent {
  public value: number;
  
  constructor(value: number = 10) {
    this.value = value;
  }
}

class FlexibleChild extends FlexibleParent {
  public extra: number;
  
  constructor(value?: number, extra?: number) {
    super(value ?? 10);  // Pass the processed parameters.
    this.extra = extra ?? 0;
  }
}

// Pass parameters after transformation.
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
    super(id);  // Pass after transformation.
    this.name = name;
  }
}
```

## Property Initialization

Property initialization assigns initial values to ensure that the object is in a valid state when it is created.

### Initialization Order and Dependencies

Initialization is performed in the following order: field default value assignment → field initializer (the expression on the right side of `=`) → constructor body assignment. Understanding this order helps avoid referencing uninitialized fields in initializers.

### Direct Initialization of Instance Properties (Initialization at Declaration)

Initialization at declaration for instance properties assigns values at the property declaration, ensuring that the property has an initial value.

<!-- @[declaration_time_initialization](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
class DirectInitialization {
  // Initialize directly at declaration.
  public name: string = 'default';
  public age: number = 0;
  public active: boolean = true;
  
  // Initialize the array.
  public items: string[] = [];
  
  // Initialize the object.
  public config: Map<string, string> = new Map();
  
  // Union type initialization.
  public value: number | string = 0;
  
  constructor() {
    // The property has been initialized at declaration.
  }
}

let direct: DirectInitialization = new DirectInitialization();
console.info(`${direct.name}`);    // 'default'
console.info(`${direct.age}`);     // 0
console.info(`${direct.active}`); // true
```

The advantage of initialization at declaration is that it ensures the property has an initial value, reduces constructor code, and makes type inference more explicit.

### Property Initialization in the Constructor

Property initialization in the constructor assigns values to properties within the constructor, which is suitable for initialization that requires parameters or dynamic computation.

<!-- @[constructor_body_initialization](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
class ConstructorInitialization {
  public name: string;
  public age: number;
  public email: string;
  
  constructor(name: string, age: number, email: string) {
    // Initialization in the constructor
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

// Initialization in the constructor:
// 1. Receive external parameters
// 2. Dynamically calculate the initial value.
// 3. Add validation logic.

class ValidatedInitialization {
  public value: number;
  
  constructor(value: number) {
    // Initialize after validation.
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
    this.calculated = base * 2;  // Calculate initialization.
  }
}
```

### Requirements for Properties That Must Be Initialized

The ArkTS compiler enforces property initialization checks by default (equivalent to the `strictPropertyInitialization` option in TypeScript, but this option cannot be disabled in ArkTS). All non-optional properties must be assigned a value at declaration or in the constructor; otherwise, a compilation error is reported. There are two ways to meet this requirement: initialization at declaration and assignment in the constructor. Optional properties (`?`) do not require initialization.

### Initialization of Optional Properties (? Modifier, Allowing Uninitialized)

Declare an optional property with the `?` modifier. When creating an object, the property may be left uninitialized. When accessing it, handle `undefined` or provide a default value with `??`.

<!-- @[optional_properties_initialization](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
class OptionalProperties {
  public name: string;          // Required property.
  public age?: number;          // Optional property.
  public email?: string;        // Optional property.
  public phone?: string;        // Optional property
  
  constructor(name: string) {
    this.name = name;
    // Optional properties do not need initialization.
  }
  
  setAge(age: number): void {
    this.age = age;  // Optional property is initialized later.
  }
  
  getAge(): number {
    return this.age ?? 0;  // Handle the uninitialized case.
  }
  
  hasAge(): boolean {
    return this.age !== undefined;  // Check whether it is initialized.
  }
}

let optional: OptionalProperties = new OptionalProperties('Alice');
console.info(`${optional.hasAge()}`);  // false

optional.setAge(25);
console.info(`${optional.hasAge()}`);  // true
console.info(`${optional.getAge()}`);  // 25
```

Optional property characteristics: it may be left uninitialized, its assignment may be deferred, and `undefined` must be checked before use.

### Initialization Check and Compiler Verification

The compiler checks property initialization to ensure that all required properties have initial values after the object is created.

### Initialization Restrictions for Readonly Properties (Assignment Only at Declaration or in the Constructor)

A readonly property is assigned at declaration or in the constructor to keep it immutable.

<!-- @[ts_readonly_initialization_rules](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Initialization.ts) -->

``` TypeScript
class ReadOnlyProperties {
  // readonly property: initialization at declaration
  public readonly constant1: number = 100;

  // readonly property: assignment in the constructor
  public readonly constant2: number;

  // readonly + optional
  public readonly optionalConstant?: number;

  constructor(value: number) {
    this.constant2 = value;  // Can be assigned in the constructor.
    this.optionalConstant = value * 2;
  }

  // Cannot modify the readonly property in a method.
  modifyConstant(): void {
    this.constant2 = 200;  // Compilation error.
  }
}

let readOnly: ReadOnlyProperties = new ReadOnlyProperties(50);
console.info(`${readOnly.constant1}`);         // 100
console.info(`${readOnly.constant2}`);         // 50
console.info(`${readOnly.optionalConstant}`);  // 100
```

readonly property restriction: It can be assigned only at declaration or in the constructor, and cannot be modified elsewhere.

<!-- @[immutable_object_pattern](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
class ImmutablePoint {
  public readonly x: number;
  public readonly y: number;

  constructor(x: number, y: number) {
    this.x = x;
    this.y = y;
    // After construction, x and y cannot be modified.
  }

  translate(dx: number, dy: number): ImmutablePoint {
    return new ImmutablePoint(this.x + dx, this.y + dy);
  }
}
```

## Initialization Order

When both the base class and the derived class have field initialization, the execution order is: base class fields → base class constructor → derived class fields → derived class constructor. In addition, the static initialization block (`static { }`) is executed when the class is first loaded, before all instance field initialization and constructor calls; static fields are initialized in declaration order, and static initialization blocks are interleaved among static fields and executed in order.

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
// Output:
// Base static block (the static initialization block is executed when the class is loaded, before instance creation)
// Derived static block
// Base constructor: name = base (derived class fields are not initialized yet)
// Derived constructor: name = derived
```

The `this.name` seen in the base class constructor is the base class's own value `'base'`, because the field initialization of the derived class is executed only after the base class constructor.

## Static Factory Methods Instead of Convenience Constructors

Use static factory methods to encapsulate object creation logic, replacing multiple convenience constructors.

### Wrapping Factory Methods Based on the Primary Constructor

Wrap static factory methods on top of the primary constructor to provide named construction entry points.

<!-- @[static_factory_methods](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
class FactoryUser {
  public id: number;
  public name: string;
  public email: string;
  public role: string;
  
  // Primary constructor
  constructor(id: number, name: string, email: string, role: string) {
    this.id = id;
    this.name = name;
    this.email = email;
    this.role = role;
  }
  
  // Static factory method: encapsulates common construction scenarios.
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

Advantages of static factories: they can simplify parameters, provide default values, and quickly create objects for specific scenarios.

### Static Factory Replacing this() Call

ArkTS does not support the `this()` call. Use a static factory method instead of convenient construction.

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
  
  // Use a static factory method instead of constructor overloading.
  static createDefault(): FactoryConfiguration {
    return new FactoryConfiguration('EXAMPLE_API_URL', 5000, false);
  }
  
  static createWithUrl(apiUrl: string): FactoryConfiguration {
    // Call the default configuration and modify some parameters.
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

### When to Use Static Factories (Simplify Instantiation Parameters)

Static factories provide named, simplified construction entry points when there are many parameters.

<!-- @[static_factory_use_cases](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
class CasesPoint {
  public x: number;
  public y: number;
  
  constructor(x: number, y: number) {
    this.x = x;
    this.y = y;
  }
  
  // Static factory scenarios:
  
  // 1. Create the origin.
  static origin(): CasesPoint {
    return new CasesPoint(0, 0);
  }
  
  // 2. Create an equal point.
  static equal(value: number): CasesPoint {
    return new CasesPoint(value, value);
  }
  
  // 3. Parse from a string.
  static fromString(str: string): CasesPoint {
    let parts: string[] = str.split(',');
    return new CasesPoint(
      Number.parseInt(parts[0], 10),
      Number.parseInt(parts[1], 10)
    );
  }
  
  // 4. Create from an array.
  static fromArray(arr: number[]): CasesPoint {
    return new CasesPoint(arr[0], arr[1]);
  }
}

let origin: CasesPoint = CasesPoint.origin();
let equal: CasesPoint = CasesPoint.equal(10);
let fromStr: CasesPoint = CasesPoint.fromString('5,10');
let fromArr: CasesPoint = CasesPoint.fromArray([3, 4]);
```

When to use: common preset values, parameter simplification, and data conversion.

## Static Initialization and Code Blocks

Static properties are initialized at declaration, and static initialization blocks execute initialization logic when the class is loaded.

### Initialization of Static Properties (Initialization at Declaration)

Static properties are class-level properties that are directly assigned at declaration.

<!-- @[static_properties_initialization](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
class StaticProperties {
  // Initialize a static property at declaration.
  public static appName: string = 'MyApp';
  public static version: number = 1.0;
  public static maxConnections: number = 100;
  
  // Static readonly property.
  public static readonly PI: number = 3.14159;
  public static readonly MAX_VALUE: number = 1000;
  
  // Static private property.
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

### Execution Timing of Static Code Blocks (static {})

A static code block is a block of code executed when the class is loaded, used to initialize static members that require multiple lines of code or conditional checks. ArkTS supports the static block syntax but does not support the `#` private identifier; use the `private` modifier instead.

<!-- @[static_initialization_function](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
class StaticInitialization {
  public static config: Map<string, string>;
  public static initialized: boolean;
  
  // Static initialization function.
  private static initialize(): void {
    StaticInitialization.config = new Map();
    StaticInitialization.config.set('apiUrl', 'EXAMPLE_API_URL');
    StaticInitialization.config.set('timeout', '5000');
    StaticInitialization.initialized = true;
    console.info('Static initialized');
  }
  
  // Ensure static initialization is executed.
  static getConfig(): Map<string, string> {
    if (!StaticInitialization.initialized) {
      StaticInitialization.initialize();
    }
    return StaticInitialization.config;
  }
}

let config: Map<string, string> = StaticInitialization.getConfig();
console.info(`${config.get('apiUrl')}`);  // EXAMPLE_API_URL

// Static initialization timing:
// Executed when the class is first used.
// Executed before any instance is created.
```

In addition to manually managing the initialization state, ArkTS also supports static code blocks (`static { }`), which are automatically executed when the class is loaded and complete initialization without explicit invocation.

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

### Purpose of Static Initialization (Global Resource Initialization and Configuration Loading)

Static initialization blocks and static fields are executed when the class is first accessed, and are used for class-level one-time setup such as loading global configuration and initializing static resource pools.

<!-- @[global_config_static_initialization](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
class GlobalConfig {
  private static initialized: boolean = false;
  private static settings: Map<string, string | number | boolean> = new Map();
  
  // Static initialization: load global configuration.
  static ensureInitialized(): void {
    if (!GlobalConfig.initialized) {
      GlobalConfig.loadSettings();
      GlobalConfig.initialized = true;
    }
  }
  
  private static loadSettings(): void {
    // Simulate configuration loading.
    GlobalConfig.settings.set('apiUrl', 'EXAMPLE_API_URL');
    GlobalConfig.settings.set('timeout', 5000);
    GlobalConfig.settings.set('debug', false);
    GlobalConfig.settings.set('maxRetries', 3);
    console.info('Global configuration loaded');
  }
  
  // Access global configuration.
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

// Use the global configuration.
console.info(`${GlobalConfig.get('apiUrl')}`);      // 'EXAMPLE_API_URL'
console.info(`${GlobalConfig.get('timeout')}`);     // 5000
console.info(`${GlobalConfig.get('debug')}`);       // false

GlobalConfig.set('customKey', 'customValue');
console.info(`${GlobalConfig.get('customKey')}`);   // 'customValue'
```

## Safety Checks for Initialization

The compiler checks uninitialized properties and reports errors to ensure that object properties have values before they are used.

### TypeScript Type Checking Restrictions on Uninitialized Properties

The compiler reports errors or warnings for uninitialized properties: `strictPropertyInitialization` requires all properties to be assigned before the constructor ends; otherwise, compilation fails.

<!-- @[ts_required_properties_initialization](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Initialization.ts) -->

``` TypeScript
class StrictInitialization {
  // Required property: must be initialized.
  public name: string;  // Compilation warning: not initialized.
  public age: number;   // Compilation warning: not initialized.
  
  constructor() {
    // name and age are not initialized
    // TypeScript will issue a warning
  }
  
  // Correct approach: initialize all properties
  correctConstructor(name: string, age: number) {
    this.name = name;
    this.age = age;
  }
}

class ProperInitialization {
  // Initialize at declaration
  public name: string = '';
  public age: number = 0;
  
  constructor() {
    // Properties are already initialized
  }
}

class OptionalInitialization {
  // Optional property: may be left uninitialized.
  public name?: string;
  public age?: number;
  
  constructor() {
    // Optional properties may be left uninitialized.
  }
  
  initialize(name: string, age: number): void {
    this.name = name;
    this.age = age;
  }
}
```

### Initialization Techniques to Avoid undefined Exceptions

Avoid undefined exceptions by ensuring that properties have values and by using safe access approaches such as optional chaining (`?.`) and nullish coalescing (`??`).

<!-- @[safe_initialization_techniques](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Initialization.ets) -->

``` TypeScript
class SafeInitialization {
  public name: string;
  public age: number;
  public email?: string;
  
  constructor(name: string, age: number) {
    // Ensure required property initialization.
    this.name = name ?? 'default';
    this.age = age ?? 0;
    
    // Handle optional properties with caution.
    if (this.email === undefined) {
      console.info('Email not initialized');
    }
  }
  
  // Safe access technique.
  getEmail(): string {
    return this.email ?? '';
  }
  
  hasEmail(): boolean {
    return this.email !== undefined && this.email.length > 0;
  }
  
  safeProcess(): void {
    // Access after checking.
    if (this.name !== undefined) {
      console.info(`${this.name}`);
    }
    
    // Use nullish coalescing.
    let safeAge: number = this.age ?? 0;
    
    // Use optional chaining (object property).
    let emailLength: number | undefined = this.email?.length;
  }
}
```

### Handling Initialization Uncertainty with Optional Chaining (?.)

Use optional chaining (`?.`) to safely access properties that may not be initialized, avoiding runtime undefined errors.

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
    // Optional properties may not be initialized.
  }
  
  // Use optional chaining for safe access.
  safeAccess(): void {
    // Access the property through optional chaining.
    let nameLength: number | undefined = this.name?.length;
    
    // Access a nested object with optional chaining.
    let nickname: string | undefined = this.profile?.nickname;
    let avatar: string | undefined = this.profile?.avatar;
    
    // Optional chaining + nullish coalescing.
    let displayName: string = this.name ?? 'Unknown';
    let displayNickname: string = this.profile?.nickname ?? 'Guest';
  }
  
  // Safe method.
  getProfileInfo(): string {
    if (this.profile !== undefined) {
      let nickname: string = this.profile.nickname ?? 'No nickname';
      let avatar: string = this.profile.avatar ?? 'No avatar';
      return `Nickname: ${nickname}, Avatar: ${avatar}`;
    }
    return 'No profile';
  }
  
  // Optional chaining check.
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

## declare Field Declaration

When redeclaring a more precise type for an inherited field in a subclass, use `declare` to avoid overwriting the superclass value at runtime.

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