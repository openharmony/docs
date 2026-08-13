# Type Conversion

<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=c25b60c237b212cfc232b5aee67d2c42ba90278a translatedAt=2026-08-13T09:04:26.991Z pushedAt=2026-08-13T13:42:29.434Z -->

Type conversion is an important concept in the ArkTS type system. Through type conversion, you can safely handle data of different types in the type system and achieve flexible conversion between types.

## Basic Concepts of Type Conversion

ArkTS handles types in its type system through the following mechanisms: type guards (`typeof`, `instanceof`) narrow types through runtime checks and are the safest way to narrow types; type assertions (`as`) tell the compiler the type of a value, take effect only at compile time, and do not change the runtime type; data conversion (such as `Number()` and `String()`) performs actual data type conversion at runtime.

### Definition and Purpose of Type Conversion

Type conversion converts a value from one type to another. In ArkTS, it is mainly used for type narrowing (narrowing a union type to a specific type), type assertion (telling the compiler the specific type of a value), and assisting type inference.

<!-- @[ts_type_conversion_purpose](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/TypeConversion.ts) -->

``` TypeScript
function getTcpValue(): string | number {
  return 'Hello, ArkTS';
}

let tcpValue: string | number = getTcpValue();

// Without type conversion, string methods cannot be accessed.
tcpValue.toUpperCase(); // Compilation error: toUpperCase does not exist on type string | number.

// After narrowing with a type guard, string methods can be accessed.
if (typeof tcpValue === 'string') {
  let strLength: number = tcpValue.length;
  console.info(`${strLength}`); // 13
}
```

### Classification of Type Conversion

Type conversion is classified by direction into upcast (from a subclass to a superclass, implicit and safe) and downcast (from a superclass to a subclass, requiring an explicit assertion and type checking).

<!-- @[class_upcast_downcast_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
class Animal {
  public name: string;
  
  constructor(name: string) {
    this.name = name;
  }
  
  public speak(): void {
    console.info(`${this.name} makes a sound`);
  }
}

class Dog extends Animal {
  public breed: string;
  
  constructor(name: string, breed: string) {
    super(name);
    this.breed = breed;
  }
  
  public bark(): void {
    console.info(`${this.name} barks: Woof! Woof!`);
  }
}

// Upcast (implicit)
let dog: Dog = new Dog('Buddy', 'Golden Retriever');
let animal: Animal = dog; // Automatic conversion

// Downcast (explicit, requires type checking)
let pet: Animal = new Dog('Max', 'Labrador');
if (pet instanceof Dog) {
  let myDog: Dog = pet; // Type safety
  myDog.bark();
}
```

### Core Principles of Type Conversion

Type conversion should prefer explicit union types combined with type guards, and avoid directly asserting broad types (such as Object), to ensure runtime type safety.

<!-- @[union_type_guard_vs_assertion](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
// Counterexample: assert directly after using a broad type.
let broadTypeValue: Object = 'Hello';
let broadTypeLength: number = (broadTypeValue as string).length; // Missing runtime check.

// Recommended: use an explicit union type + type guard.
let unionTypeValue: string | number = 'Hello';

// Type-safe conversion.
if (typeof unionTypeValue === 'string') {
  let unionTypeLength: number = unionTypeValue.length; // The compiler knows that unionTypeValue is of the string type.
  console.info(`${unionTypeLength}`);
}
```

## Type Assertion

A type assertion is a way to tell the compiler "I know what type this value is." It provides type information at compile time but does not perform type checking at runtime. Type assertion is a flexible feature of the ArkTS type system.

The `as` keyword is the recommended type assertion syntax in ArkTS. It is used to assert the type of a value as another type.

### Angle Bracket Syntax

The angle bracket syntax (`<T>`value) performs a type assertion to tell the compiler the type of the value.

**TypeScript Comparison**

<!-- @[ts_typescript_angle_bracket_assertion_not_used](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/TypeConversion.ts) -->

``` TypeScript
// TypeScript comparison syntax, not used in ArkTS:
let value: Object = 'hello';
let length: number = (<string>value).length;
```

### as Keyword Syntax

The `as` keyword (`value as Type`) performs a type assertion, telling the compiler to treat the value as the specified type.

<!-- @[as_keyword_type_assertion](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
let assertValueObj: Object = 'Hello, ArkTS';

// Use the as keyword to perform a type assertion.
if (typeof assertValueObj === 'string') {
  let assertLength: number = (assertValueObj as string).length;
  console.info(`${assertLength}`); // 13
}

// Assert as a union type.
let mixedValue: Object = 42;
let numValue: number | string = mixedValue as number | string;

// Assert as a custom type.
interface AssertUser {
  id: number;
  name: string;
  email: string;
}

let userData: AssertUser = {
  id: 1,
  name: 'Alice',
  email: 'alice@example.com'
};

let assertUser: AssertUser = userData as AssertUser;
console.info(`${assertUser.name}`); // Alice
```

### Restrictions on Type Assertion

Type assertion takes effect only at compile time and does not change the runtime type. You cannot directly assert between unrelated types; you must first go through `unknown` or a runtime conversion.

<!-- @[ts_assertion_runtime_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/TypeConversion.ts) -->

``` TypeScript
let runtimeTypeValue: Object = 123;

// Type assertion does not convert a number to a string.
let assertedString: string = runtimeTypeValue as string;

console.info(`${typeof assertedString}`); // "number" (the runtime type is still number)
assertedString.toUpperCase(); // Runtime error: toUpperCase is not a function
```

A type assertion cannot be used directly between unrelated types. You need to distinguish between reasonable and unreasonable assertion scenarios:

<!-- @[ts_reasonable_vs_unreasonable_assertion](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/TypeConversion.ts) -->

``` TypeScript
// Unreasonable: assert string as number.
let unreasonableStr: string = '123';
let unreasonableNum: number = unreasonableStr as number; // Compilation error.

// Reasonable approach: convert first, then assert.
let num: number = Number(unreasonableStr);

// Double assertion (TypeScript comparison, not used in ArkTS).
let unreasonableValue: string = 'Hello';
let unreasonableUnsafeNum: number = unreasonableValue as unknown as number;
```

Type assertion and type conversion are fundamentally different: an assertion takes effect only at compile time, whereas a conversion is performed at runtime. Note that in the following example, `as number` only tells the compiler the type; at runtime `assertedNum` is still a string, and using it directly as a number causes a runtime error:

<!-- @[type_assertion_vs_type_conversion](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
// Type assertion: takes effect only at compile time.
let value1: Object = '123';
let assertedNum: number = value1 as number;
console.info(`${typeof assertedNum}`); // "string" (the runtime type is unchanged)

// Type conversion: performs the conversion at runtime.
let value2: string = '123';
let convertedNum: number = Number(value2);
console.info(`${typeof convertedNum}`); // "number" (the runtime type has changed)
```

### Reasonable Use Cases for Type Assertion

Type assertion is suitable for scenarios where you need to inform the compiler of a specific type, such as safe narrowing after type checking and assertions on external data structures (for example, DOM elements and API response parsing). Note: After a type guard such as `typeof` has narrowed the type, the `as` assertion is redundant and can be omitted.

<!-- @[type_assertion_with_type_check](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
function processValue(value: string | number | boolean): void {
  // Perform type checking before using a type assertion.
  if (typeof value === 'string') {
    let strValue: string = value as string; // The assertion is safe at this point.
    console.info(`${strValue.toUpperCase()}`);
  } else if (typeof value === 'number') {
    let numValue: number = value as number;
    console.info(`${numValue.toFixed(2)}`);
  }
}
```

For external objects such as DOM elements, you can use `as` to assert them as a specific structure after type checking.

<!-- @[ts_dom_element_type_assertion](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/TypeConversion.ts) -->

``` TypeScript
// Obtain the DOM element (browser environment).
interface HTMLInputElement {
  value: string;
}

interface MockDocument {
  getElementById: (id: string) => HTMLInputElement;
}

let mockDoc: MockDocument = {
  getElementById: (id: string): HTMLInputElement => {
    let element: HTMLInputElement = { value: '' };
    return element;
  }
};
let inputElement = mockDoc.getElementById('username') as HTMLInputElement;
inputElement.value = 'Alice';

// Or use optional chaining.
let element = mockDoc.getElementById('password') as HTMLInputElement | null;
if (element) {
  console.info(`${element.value}`);
}
```

When parsing API response JSON, you can use `as` to assert the parsed result as a predefined response interface type.

<!-- @[ts_api_response_type_assertion](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/TypeConversion.ts) -->

``` TypeScript
interface ApiResponse {
  code: number;
  message: string;
  data: UserData;
}

interface UserData {
  id: number;
  name: string;
}

function parseApiResponse(jsonStr: string): ApiResponse {
  return JSON.parse(jsonStr) as ApiResponse;
}

let jsonResponse = '{"code":200,"message":"success","data":{"id":1,"name":"Alice"}}';
let response: ApiResponse = parseApiResponse(jsonResponse);
console.info(`${response.message}`); // success
```

## Type Guard

A type guard is an expression that checks a type at runtime and narrows the type range at compile time. Compared with a type assertion, a type guard is safer because it performs an actual check at runtime.

The `typeof` type guard uses the `typeof` operator to check primitive types and is the most commonly used type guard.

### typeof Type Guard

Used to determine primitive types: `string`, `number`, `boolean`, `symbol`, `undefined`, `function`, and `object`.

<!-- @[typeof_type_guard](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
function typeGuardProcessValue(value: string | number | boolean): void {
  if (typeof value === 'string') {
    // The compiler knows that value is of the string type.
    console.info(`String length: ${value.length}`);
    console.info(`Uppercase: ${value.toUpperCase()}`);
  } else if (typeof value === 'number') {
    // The compiler knows that value is of type number.
    console.info(`Number: ${value.toFixed(2)}`);
    console.info(`Square: ${value * value}`);
  } else if (typeof value === 'boolean') {
    // The compiler knows that value is of type boolean.
    console.info(`Boolean: ${value ? 'true' : 'false'}`alse'}`);
  }
}

typeGuardProcessValue('Hello');  // String length: 5, uppercase: HELLO
typeGuardProcessValue(42);       // Number: 42.00, square: 1764
typeGuardProcessValue(true);     // Boolean: true
```

### instanceof Type Guard

The `instanceof` operator checks whether an object is an instance of a class (matching level by level along the prototype chain), and implements type narrowing in the `if` branch. Within that branch, TypeScript narrows the object type to the target class type, so that members specific to that class can be accessed safely.

<!-- @[instanceof_type_guard](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
class TypeGuardDog {
  public name: string;
  
  constructor(name: string) {
    this.name = name;
  }
  
  public bark(): void {
    console.info(`${this.name} barks: Woof!`);
  }
}

class Cat {
  public name: string;
  
  constructor(name: string) {
    this.name = name;
  }
  
  public meow(): void {
    console.info(`${this.name} meows: Meow!`);
  }
}

function makeSound(pet: TypeGuardDog | Cat): void {
  console.info(`Pet name: ${pet.name}`);
  
  if (pet instanceof TypeGuardDog) {
    // The compiler knows that pet is of the TypeGuardDog type.
    pet.bark();
  } else if (pet instanceof Cat) {
    // The compiler knows that pet is of the Cat type.
    pet.meow();
  }
}

let myDog = new TypeGuardDog('Buddy');
let myCat = new Cat('Whiskers');

makeSound(myDog); // Pet name: Buddy, Buddy barks: Woof!
makeSound(myCat); // Pet name: Whiskers, Whiskers meows: Meow!
```

### in Type Guard

TypeScript supports using `'prop' in obj` to determine whether an object contains a specified property and to complete type narrowing. ArkTS does not support the `in` operator for type narrowing (`arkts-no-in`). For details, see [TypeScript to ArkTS Cookbook](typescript-to-arkts-migration-guide.md#in-operator-is-not-supported). It is recommended to add a stable discriminant field to the union type.

**TypeScript Comparison**

<!-- @[ts_discriminated_union_instead_of_in_operator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/TypeConversion.ts) -->

``` TypeScript
interface Bird {
  kind: 'bird';
  fly: () => void;
  layEggs: () => void;
}

interface Fish {
  kind: 'fish';
  swim: () => void;
  layEggs: () => void;
}

let birdOrFish: Bird | Fish = {
  kind: 'bird',
  fly: () => console.info(`Flying`),
  layEggs: () => console.info(`Laying eggs`)
};

// TypeScript comparison, not used in ArkTS:
if ('fly' in birdOrFish) {
    birdOrFish.fly();
}

function move(animal: Bird | Fish): void {
  switch (animal.kind) {
    case 'bird':
      animal.fly();
      break;
    case 'fish':
      animal.swim();
      break;
  }

  // layEggs exists in both interfaces.
  animal.layEggs();
}

let bird: Bird = {
  kind: 'bird',
  fly: () => console.info(`Flying high`),
  layEggs: () => console.info(`Laying eggs in nest`)
};

let fish: Fish = {
  kind: 'fish',
  swim: () => console.info(`Swimming deep`),
  layEggs: () => console.info(`Laying eggs in water`)
};

move(bird); // Flying high, Laying eggs in nest
move(fish); // Swimming deep, Laying eggs in water
```

### Concept and Approaches of Type Narrowing

Type narrowing means that, within the scope of a type guard (such as `typeof` or `instanceof`), the compiler automatically narrows a union type to a specific type.

The process is as follows: first define a union type or a broad type, then use a type guard to check the type. Within the guard branch, you can access type-specific members, and the compiler automatically narrows the type range.

<!-- @[type_narrowing_concept](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
type StringOrNumber = string | number;

function narrowProcessValue(value: StringOrNumber): string {
  // Narrowing with typeof: within the branch, value is narrowed to a specific type.
  if (typeof value === 'string') {
    return value.toUpperCase();  // value: string
  } else {
    return value.toFixed(2);     // value: number
  }
}
```

### Custom Type Predicate Functions and Discriminated Unions

TypeScript can declare a type predicate in the `value is Type` format. ArkTS does not use the `is` type predicate; when the judgment logic needs to be encapsulated, the helper function returns `boolean`, and access to type-specific members is still completed through the branch where the type discrimination condition resides.

<!-- @[discriminated_union_vehicle_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
interface Car {
  type: 'car';
  drive: () => void;
}

interface Boat {
  type: 'boat';
  sail: () => void;
}

interface Plane {
  type: 'plane';
  fly: () => void;
}

type Vehicle = Car | Boat | Plane;

function isCarKind(vehicle: Vehicle): boolean {
  return vehicle.type === 'car';
}

function isBoatKind(vehicle: Vehicle): boolean {
  return vehicle.type === 'boat';
}

function isPlaneKind(vehicle: Vehicle): boolean {
  return vehicle.type === 'plane';
}

function operateVehicle(vehicle: Vehicle): void {
  switch (vehicle.type) {
    case 'car':
      vehicle.drive();
      break;
    case 'boat':
      vehicle.sail();
      break;
    case 'plane':
      vehicle.fly();
      break;
  }
}

let car: Car = { type: 'car', drive: () => console.info('Driving on road') };
let boat: Boat = { type: 'boat', sail: () => console.info('Sailing on water') };
let plane: Plane = { type: 'plane', fly: () => console.info('Flying in sky') };

operateVehicle(car);   // Driving on road
operateVehicle(boat);  // Sailing on water
operateVehicle(plane); // Flying in sky

console.info(`${isCarKind(car)}`);
console.info(`${isBoatKind(boat)}`);
console.info(`${isPlaneKind(plane)}`);
```

The same discriminated union pattern also applies to distinguishing types of business domain models such as user roles:

<!-- @[discriminated_union_user_role](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
interface RegularUser {
  role: 'regular';
  id: number;
  name: string;
  email: string;
}

interface AdminUser {
  role: 'admin';
  id: number;
  name: string;
  email: string;
  adminLevel: number;
  permissions: string[];
}

type RoleUser = RegularUser | AdminUser;

function processUser(user: RoleUser): void {
  console.info(`RoleUser: ${user.name} (${user.email})`);

  switch (user.role) {
    case 'admin':
      console.info(`Admin Level: ${user.adminLevel}`);
      console.info(`Permissions: ${user.permissions.join(', ')}`);
      break;
    case 'regular':
      console.info('Regular user');
      break;
  }
}

let regularUser: RegularUser = {
  role: 'regular',
  id: 1,
  name: 'Alice',
  email: 'alice@example.com'
};

let adminUser: AdminUser = {
  role: 'admin',
  id: 2,
  name: 'Bob',
  email: 'bob@example.com',
  adminLevel: 5,
  permissions: ['read', 'write', 'delete']
};

processUser(regularUser);
// RoleUser: Alice (alice@example.com)
// Regular user

processUser(adminUser);
// RoleUser: Bob (bob@example.com)
// Admin Level: 5
// Permissions: read, write, delete
```

### Truthiness Narrowing

In a conditional expression, falsy values (`0`, `NaN`, `""`, `null`, `undefined`) are excluded, and the variable is narrowed to a non-falsy type.

<!-- @[truthiness_narrowing](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
function processTruthyValue(value: string | null | undefined): void {
  if (value) {
    console.info(`${value.toUpperCase()}`);
  } else {
    console.info('null value');
  }
}

processTruthyValue('hello');
processTruthyValue(null);
```

`Boolean(x)` or `!!x` converts any value to a boolean for truthiness checking.

### Equality Narrowing

After comparison using `===` or `!==`, the compiler narrows the type in the corresponding branch. `== null` can exclude both `null` and `undefined` at the same time.

<!-- @[equality_narrowing](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
function compareNarrowing(value: string | number | null | undefined): void {
  if (value === 'hello') {
    console.info(`${value.toUpperCase()}`);
  } else if (value === null) {
    console.info('null');
  } else if (value === undefined) {
    console.info('undefined');
  } else {
    console.info(`${value}`);
  }
}

function checkNull(value: string | null | undefined): void {
  if (value == null) {
    console.info('Empty');
  } else {
    console.info(`${value.toUpperCase()}`);
  }
}
```

### Assignment Narrowing

After a variable is assigned, the compiler narrows the type of the variable on the left based on the type of the value on the right. Narrowing is based on the declared type and does not widen to a broader type.

<!-- @[assignment_narrowing](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
let anAssignedValue: string | number = 'hello';
console.info(`${anAssignedValue.toUpperCase()}`); // The compiler knows the value is a string here.
anAssignedValue = 42;
console.info(`${anAssignedValue}`); // The compiler knows the value is a number here.
```

### Control Flow Analysis

The compiler tracks type changes along control flows such as `if`/`else`, `switch`, loops, and ternary expressions. Types in unreachable branches are excluded, and the union type is taken after branches merge.

<!-- @[control_flow_analysis](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
function flowAnalysis(value: string | number): void {
  if (typeof value === 'string') {
    console.info(`${value.length}`);
  } else {
    console.info(`${value}`);
  }
}
```

In loops and conditional assignments, control flow analysis also tracks type changes correctly:

<!-- @[type_inference_union](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
let tiuResult: string | number;
if (Math.random() > 0.5) {
  tiuResult = 'success';
} else {
  tiuResult = 0;
}
console.info(`${tiuResult}`); // string | number
```

### Type Predicate

TypeScript supports the `parameterName is Type` syntax to declare a type predicate function, which automatically narrows the type in an `if` branch. **ArkTS does not support the `is` type predicate syntax**.

<!-- @[ts_type_predicate](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/TypeConversion.ts) -->

``` TypeScript
// TypeScript syntax; ArkTS does not support the is type predicate
function isString(value: unknown): value is string {
  return typeof value === 'string';
}

let tsVal: unknown = 'hello';
if (isString(tsVal)) {
  console.info(`${tsVal.toUpperCase()}`); // HELLO
}
```

ArkTS alternative: use `typeof` or `instanceof` to narrow the type directly at the call site, or use a discriminated union.

<!-- @[typeof_narrowing_process](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
function processWithTypeof(value: string | number): void {
  if (typeof value === 'string') {
    console.info(`${value.toUpperCase()}`);
  } else {
    console.info(`${value.toFixed(2)}`);
  }
}
```

## Upcast (Implicit Conversion)

An upcast refers to assigning a subclass instance to a superclass type variable, which is a type-safe implicit conversion.

### Assigning a Subclass Instance to a Superclass Type Variable

A subclass instance can be directly assigned to a superclass type variable (implicit upcast). After the conversion, only members defined in the superclass can be called, and subclass-specific members cannot be accessed.

<!-- @[ts_upcast_subclass_to_parent](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/TypeConversion.ts) -->

``` TypeScript
class Animal {
  public name: string;

  constructor(name: string) {
    this.name = name;
  }

  public speak(): void {
    console.info(`${this.name} makes a sound`);
  }
}

class Dog extends Animal {
  public breed: string;

  constructor(name: string, breed: string) {
    super(name);
    this.breed = breed;
  }

  public bark(): void {
    console.info(`${this.name} barks: Woof! Woof!`);
  }
}

class Cat extends Animal {
  public color: string;

  constructor(name: string, color: string) {
    super(name);
    this.color = color;
  }

  public meow(): void {
    console.info(`${this.name} meows: Meow!`);
  }
}

// Upcast: assign a subclass instance to a superclass type variable.
let dog: Dog = new Dog('Buddy', 'Golden Retriever');
let animal: Animal = dog; // Implicit conversion, type safe.

// You can call superclass methods.
animal.speak(); // Buddy makes a sound

// Cannot call subclass-specific methods.
animal.bark(); // Compilation error.
```

### Assigning an Interface Implementation Class to an Interface Type Variable

An instance of an interface implementation class can be assigned to an interface type variable (implicit upcast). After the conversion, only the members defined by the interface can be called, and methods specific to the implementation class cannot be accessed.

<!-- @[ts_upcast_to_interface](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/TypeConversion.ts) -->

``` TypeScript
interface IShape {
  getArea(): number;
  getPerimeter(): number;
}

class Rectangle implements IShape {
  private width: number;
  private height: number;

  constructor(width: number, height: number) {
    this.width = width;
    this.height = height;
  }

  public getArea(): number {
    return this.width * this.height;
  }

  public getPerimeter(): number {
    return 2 * (this.width + this.height);
  }

  // Method specific to Rectangle.
  public getDiagonal(): number {
    return Math.sqrt(this.width ** 2 + this.height ** 2);
  }
}

class Circle implements IShape {
  private radius: number;

  constructor(radius: number) {
    this.radius = radius;
  }

  public getArea(): number {
    return Math.PI * this.radius ** 2;
  }

  public getPerimeter(): number {
    return 2 * Math.PI * this.radius;
  }

  // Method specific to Circle.
  public getDiameter(): number {
    return 2 * this.radius;
  }
}

// Upcast: assign an implementation class to an interface type variable.
let rectangle: Rectangle = new Rectangle(3, 4);
let shape: IShape = rectangle; // Implicit conversion.

console.info(`Area: ${shape.getArea()}`);         // 12
console.info(`Perimeter: ${shape.getPerimeter()}`);    // 14

// Cannot call methods specific to the implementation class.
shape.getDiagonal(); // Compilation error.
```

### Automatic and Safe Upcasting

Converting a subclass to a superclass type is automatic and type-safe, because a subclass object contains all members of the superclass.

<!-- @[upcast_automatic_implicit_safe](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
class SafeVehicle {
  public brand: string;
  
  constructor(brand: string) {
    this.brand = brand;
  }
  
  public move(): void {
    console.info(`${this.brand} vehicle is moving`);
  }
}

class SafeCar extends SafeVehicle {
  public model: string;
  
  constructor(brand: string, model: string) {
    super(brand);
    this.model = model;
  }
  
  public drive(): void {
    console.info(`${this.brand} ${this.model} is driving`);
  }
}

// Upcasting is automatic and implicit.
let safeCar: SafeCar = new SafeCar('Toyota', 'Camry');
let vehicle: SafeVehicle = safeCar; // Automatic conversion.

// Upcasting is type-safe.
// A subclass object necessarily contains all members of its superclass.
vehicle.move(); // Toyota vehicle is moving
console.info(`${vehicle.brand}`); // Toyota

// Upcast of a function parameter.
function startVehicle(vehicle: SafeVehicle): void {
  vehicle.move();
}

let myCar: SafeCar = new SafeCar('Honda', 'Civic');
startVehicle(myCar); // Automatic upcast.
```

### Restrictions on Member Access After Upcast

After an upcast, a variable of the superclass type can only call members declared in the superclass. Members specific to the subclass can be accessed only after a downcast.

<!-- @[ts_upcast_access_parent_members_only](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/TypeConversion.ts) -->

``` TypeScript
class Parent {
  public parentMethod(): void {
    console.info(`Parent method`);
  }
}

class Child extends Parent {
  public childMethod(): void {
    console.info(`Child method`);
  }
}

let child: Child = new Child();
let parent: Parent = child; // Upcast

// Only superclass members can be accessed.
parent.parentMethod(); // Correct.
parent.childMethod(); // Compilation error.

// To access subclass members, perform a downcast (type assertion).
if (parent instanceof Child) {
  let childAgain: Child = parent as Child;
  childAgain.childMethod(); // Correct.
}
```

## Downcast (Explicit Conversion)

A downcast converts a superclass type variable to a subclass type, which requires an explicit conversion and type checking.

### Converting a Superclass Type Variable to a Subclass Type

To convert a superclass type variable to a subclass type, use an explicit assertion with `as`. Check the actual type with `instanceof` first to avoid a runtime conversion failure.

<!-- @[downcast_with_instanceof_check](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
class Animal2 {
  public name: string;

  constructor(name: string) {
    this.name = name;
  }

  public speak(): void {
    console.info(`${this.name} makes a sound`);
  }
}

class Dog2 extends Animal2 {
  public breed: string;

  constructor(name: string, breed: string) {
    super(name);
    this.breed = breed;
  }

  public bark(): void {
    console.info(`${this.name} barks: Woof!`);
  }
}

class Cat2 extends Animal2 {
  public color: string;

  constructor(name: string, color: string) {
    super(name);
    this.color = color;
  }

  public meow(): void {
    console.info(`${this.name} meows: Meow!`);
  }
}

// Downcast.
let downcastAnimal: Animal2 = new Dog2('Buddy', 'Golden Retriever');

// Unsafe downcast (may cause a runtime error).
let downcastDog: Dog2 = downcastAnimal as Dog2; // Compilation succeeds, but the type should be checked first.

// Safe downcast: use instanceof to check.
if (downcastAnimal instanceof Dog2) {
  let dcDog: Dog2 = downcastAnimal; // Automatically inferred after the type guard.
  dcDog.bark();
}

// Incorrect example: downcast fails.
let catAnimal: Animal2 = new Cat2('Whiskers', 'White');
if (catAnimal instanceof Dog2) {
  let dcCatDog: Dog2 = catAnimal;
  dcCatDog.bark();
} else {
  console.info(`This animal is not a dog`);
}
```

### Safe Downcast with Type Guards

First use `instanceof` to determine the actual type of the object, and then assign it to a subclass variable within the guard branch to avoid runtime conversion failures.

<!-- @[safe_downcast_with_type_guard](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
interface CastShape {
  type: string;
  getArea(): number;
}

class CastRectangle implements CastShape {
  public type: string = 'rectangle';
  private width: number;
  private height: number;
  
  constructor(width: number, height: number) {
    this.width = width;
    this.height = height;
  }
  
  public getArea(): number {
    return this.width * this.height;
  }
  
  public getDiagonal(): number {
    return Math.sqrt(this.width ** 2 + this.height ** 2);
  }
}

class CastCircle implements CastShape {
  public type: string = 'circle';
  private radius: number;
  
  constructor(radius: number) {
    this.radius = radius;
  }
  
  public getArea(): number {
    return Math.PI * this.radius ** 2;
  }
  
  public getDiameter(): number {
    return 2 * this.radius;
  }
}

function processShape(shape: CastShape): void {
  console.info(`Shape type: ${shape.type}`);
  console.info(`Area: ${shape.getArea()}`);
  
  // Use a type guard to perform a safe downcast.
  if (shape instanceof CastRectangle) {
    let rect: CastRectangle = shape;
    console.info(`Diagonal: ${rect.getDiagonal()}`);
  } else if (shape instanceof CastCircle) {
    let circle: CastCircle = shape;
    console.info(`Diameter: ${circle.getDiameter()}`);
  }
}

let rectangle: CastShape = new CastRectangle(3, 4);
let circle: CastShape = new CastCircle(5);

processShape(rectangle);
// Shape type: rectangle
// Area: 12
// Diagonal: 5

processShape(circle);
// Shape type: circle
// Area: 78.53981633974483
// Diameter: 10
```

### Handling Downcast Failures

A downcast may fail: when you use the `as` assertion, the code compiles but a runtime type mismatch does not throw an exception; instead, it produces unsafe behavior. By checking with `instanceof` before the `as` conversion, you can gracefully handle the failed conversion in the `else` branch. It is recommended that you always use the `instanceof` guard before the conversion.

<!-- @[safe_downcast_function](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
class Base {
  public baseMethod(): void {
    console.info('Base method');
  }
}

class Derived extends Base {
  public derivedMethod(): void {
    console.info('Derived method');
  }
}

function safeDowncast(obj: Base): void {
  // Use instanceof to check and avoid runtime errors.
  if (obj instanceof Derived) {
    let derived: Derived = obj;
    derived.derivedMethod();
  } else {
    console.info('Downcast failed: object is not an instance of Derived');
  }
}

let base: Base = new Base();
let derived: Base = new Derived();

safeDowncast(base);    // Downcast failed
safeDowncast(derived); // Derived method
```

### Downcasting a Union Type (Type Narrowing)

Use the `typeof` type guard to narrow a union type to a specific subtype.

<!-- @[typeof_type_guard_narrowing](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
type StringOrNumberNarrow = string | number;

function typeGuardProcessValue2(value: StringOrNumberNarrow): void {
  // Use the typeof type guard to narrow the type.
  if (typeof value === 'string') {
    // The type of value is narrowed to string here.
    console.info(`String value: ${value}`);
    console.info(`Length: ${value.length}`);
    console.info(`Uppercase: ${value.toUpperCase()}`);
  } else {
    // The type of value is narrowed to number here.
    console.info(`Number value: ${value}`);
    console.info(`Fixed: ${value.toFixed(2)}`);
    console.info(`Square: ${value * value}`);
  }
}

typeGuardProcessValue2('Hello'); // String value: Hello, Length: 5, Uppercase: HELLO
typeGuardProcessValue2(42);      // Number value: 42, Fixed: 42.00, Square: 1764
```

## Type Conversion and Union Types

Union types support multiple type conversions, which require type guards to ensure safety.

### Type Narrowing of Union Types

Narrow a union type to a specific member type through a discriminant property.

<!-- @[discriminated_union_animal_speed](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
interface Bird {
  type: 'bird';
  flyingSpeed: number;
}

interface Horse {
  type: 'horse';
  runningSpeed: number;
}

type SpeedAnimal = Bird | Horse;

function getAnimalSpeed(animal: SpeedAnimal): number {
  switch (animal.type) {
    case 'bird':
      return animal.flyingSpeed;
    case 'horse':
      return animal.runningSpeed;
  }
  return 0;
}

// Use a discriminated union (Discriminated Union)
function getAnimalSpeedV2(animal: SpeedAnimal): number {
  switch (animal.type) {
    case 'bird':
      return animal.flyingSpeed;
    case 'horse':
      return animal.runningSpeed;
  }
  return 0;
}

let bird: Bird = { type: 'bird', flyingSpeed: 100 };
let horse: Horse = { type: 'horse', runningSpeed: 50 };

console.info(`${getAnimalSpeed(bird)}`);   // 100
console.info(`${getAnimalSpeed(horse)}`);  // 50
console.info(`${getAnimalSpeedV2(bird)}`); // 100
console.info(`${getAnimalSpeedV2(horse)}`); // 50
```

### Union Type Conversion with switch Statements

By matching the discriminant property (such as `kind`) of a union type in a `switch` statement, the compiler automatically narrows the type to the corresponding member type in each branch, allowing safe access to its exclusive properties.

<!-- @[discriminated_union_shape_area](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
interface SwitchCircle {
  kind: 'areaCircle';
  radius: number;
}

interface SwitchSquare {
  kind: 'square';
  sideLength: number;
}

interface SwitchRectangle {
  kind: 'areaRectangle';
  width: number;
  height: number;
}

type SwitchShape = SwitchCircle | SwitchSquare | SwitchRectangle;

function getArea(shape: SwitchShape): number {
  switch (shape.kind) {
    case 'areaCircle':
      // The compiler knows that shape is of type Circle.
      return Math.PI * shape.radius ** 2;
    case 'square':
      // The compiler knows that shape is of type Square.
      return shape.sideLength ** 2;
    case 'areaRectangle':
      // The compiler knows that shape is of type Rectangle.
      return shape.width * shape.height;
  }
  return 0;
}

let areaCircle: SwitchCircle = { kind: 'areaCircle', radius: 5 };
let square: SwitchSquare = { kind: 'square', sideLength: 4 };
let areaRectangle: SwitchRectangle = { kind: 'areaRectangle', width: 3, height: 6 };

console.info(`area：${getArea(areaCircle)}`);     // area: 78.53981633974483
console.info(`area：${getArea(square)}`);     // area: 16
console.info(`area：${getArea(areaRectangle)}`);  // area: 18
```

### Conversion Handling for Optional Types (T | undefined)

An optional type (T | undefined) is narrowed to a concrete type through conditional checks, optional chaining (?.), or nullish coalescing (??), avoiding direct access to undefined values.

<!-- @[optional_property_type_guard](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
interface OptUser {
  id: number;
  name: string;
  email?: string; // Optional property.
}

function getUserEmail(user: OptUser): string {
  // Method 1: Use optional chaining and nullish coalescing.
  return user.email ?? 'No email set';
}

function processUserEmail(user: OptUser): void {
  // Method 2: Use conditional checks for type narrowing.
  if (user.email !== undefined) {
    // At this point, user.email is of the string type.
    console.info(`Email: ${user.email}`);
    console.info(`Email length: ${user.email.length}`);
  } else {
    console.info(`Email not provided`);
  }
}

// Use the non-null assertion (!) when you are certain the value exists.
// Counterexample: a runtime error occurs if email does not exist.
function getEmailLength(user: OptUser): number {
  return user.email!.length;
}

// Recommended: check before use.
function getEmailLength2(user: OptUser): number {
  if (user.email) {
    return user.email.length;
  }
  return 0;
}

let optUser1: OptUser = { id: 1, name: 'Alice', email: 'alice@example.com' };
let optUser2: OptUser = { id: 2, name: 'Bob' };

console.info(`${getUserEmail(optUser1)}`); // alice@example.com
console.info(`${getUserEmail(optUser2)}`); // Email not set.

processUserEmail(optUser1);
processUserEmail(optUser2);
```

### Comprehensive Example of Type Conversion

Combining discriminated unions, type guards, and switch statements, this example demonstrates the complete flow of type narrowing and safe data access in API response handling.

<!-- @[union_type_api_response_handling](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
// Define a union type.
type Result<T> = Success<T> | Failure;

interface Success<T> {
  status: 'success';
  data: T;
}

interface Failure {
  status: 'failure';
  error: string;
}

// Function that handles a union type.
function handleResult<T>(result: Result<T>): void {
  switch (result.status) {
    case 'success':
      // The compiler knows that result is of type Success<T>.
      console.info(`Success: ${result.data}`);
      break;
    case 'failure':
      // The compiler knows that result is of the Failure type.
      console.error(`Error: ${result.error}`);
      break;
  }
}

// Another example: handle an API response.
interface UserData {
  id: number;
  name: string;
}
interface UnionTypeApiResponse {
  code: number;
  data?: UserData;
  message?: string;
}

function processApiResponse(response: UnionTypeApiResponse): void {
  if (response.code === 200) {
    // Use a type guard to ensure that data exists.
    if (response.data !== undefined) {
      console.info(`Data received: ${response.data.name}`);
    } else {
      console.info('Success but no data');
    }
  } else {
    // Use nullish coalescing to handle the optional message.
    const errorMsg = response.message ?? 'Unknown error';
    console.error(`Error ${response.code}: ${errorMsg}`);
  }
}

// Usage example.
let successResult: Result<string> = {
  status: 'success',
  data: 'Hello, ArkTS!'
};

let failureResult: Result<string> = {
  status: 'failure',
  error: 'Network error'
};

handleResult<string>(successResult); // Success: Hello, ArkTS!
handleResult<string>(failureResult); // Error: Network error

let apiSuccess: UnionTypeApiResponse = {
  code: 200,
  data: { id: 1, name: 'Alice' }
};

let apiError: UnionTypeApiResponse = {
  code: 404,
  message: 'Not found'
};

processApiResponse(apiSuccess); // Data received: { id: 1, name: 'Alice' }
processApiResponse(apiError);   // Error 404: Not found
```

## Exhaustiveness Checking

Exhaustiveness checking ensures that all possible values of a union type or enum are handled. By using the `never` type, you can detect missed cases in the `default` branch of a `switch` statement.

<!-- @[exhaustiveness_check](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
interface EcCircle {
  kind: 'circle';
  radius: number;
}

interface EcSquare {
  kind: 'square';
  sideLength: number;
}

type EcShape = EcCircle | EcSquare;

function getEcArea(shape: EcShape): number {
  switch (shape.kind) {
    case 'circle':
      return Math.PI * shape.radius * shape.radius;
    case 'square':
      return shape.sideLength * shape.sideLength;
    default:
      // If Triangle is added but not handled, a compilation error occurs here.
      const _exhaustiveCheck: never = shape;
      return _exhaustiveCheck;
  }
}

let ecCircle: EcCircle = { kind: 'circle', radius: 5 };
let ecSquare: EcSquare = { kind: 'square', sideLength: 4 };

console.info(`${getEcArea(ecCircle).toString()}`);
console.info(`${getEcArea(ecSquare).toString()}`);
```

The `never` type can only be assigned `never` itself. When the type of `shape` contains unhandled members, assigning it to `never` triggers a compilation error, thereby detecting the omission at compile time.

The `never` type represents a value that never exists. In type narrowing, when all possibilities have been excluded, the remaining type becomes `never`.

<!-- @[never_narrowing](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
function processNvValue(value: string | number): void {
  if (typeof value === 'string') {
    console.info(`${value.toUpperCase()}`);
  } else if (typeof value === 'number') {
    console.info(`${value.toFixed(2)}`);
  } else {
    // The type of value is never (all possibilities have been excluded).
    const _check: never = value;
    console.info(`Unexpected: ${_check}`);
  }
}

processNvValue('hello');  // HELLO
processNvValue(42);       // 42.00
```

## Type Compatibility

Type compatibility determines whether a value of one type can be assigned to a variable of another type. ArkTS does not support structural typing (duck typing); type compatibility is based on explicit inheritance and `implements` relationships — types can be assigned to each other only when an explicit parent-child inheritance or interface implementation relationship exists.

### Structural Typing

Two types can be assigned to each other as long as their structures (properties and methods) are compatible, without requiring an explicit inheritance relationship. **ArkTS does not support structural typing (duck typing)**; type compatibility is based on explicit inheritance and `implements` relationships.

<!-- @[ts_structural_typing](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/TypeConversion.ts) -->

``` TypeScript
// TypeScript structural typing, which ArkTS does not support
interface TsNamed {
  name: string;
}

class TsPerson {
  public name: string = '';
  public age: number = 0;
}

// TsPerson does not declare implements TsNamed, but is structurally compatible and can be assigned directly
let tsNamedItem: TsNamed = new TsPerson();
console.info(`${tsNamedItem.name}`);
```

In ArkTS, explicit `implements` is required to achieve interface compatibility:

<!-- @[structural_typing_explicit](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
interface StNamed {
  name: string;
}

class StPerson implements StNamed {
  public name: string;
  public age: number;

  constructor(name: string, age: number) {
    this.name = name;
    this.age = age;
  }
}

let stNamedItem: StNamed = new StPerson('Alice', 25);
console.info(`${stNamedItem.name}`); // Alice
```

### Function Compatibility

Function compatibility checks the number and types of parameters and the return value type. The number of parameters of the target function must be less than or equal to that of the source function (fewer is allowed, more is not), the parameter types must be compatible, and the return value type must be compatible (covariant).

<!-- @[function_compatibility](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
// A function with fewer parameters can be assigned to a function type with more parameters.
type FcGreeter = (name: string) => string;
let fcGreeter: FcGreeter = (name: string): string => `Hello, ${name}`;

type FcBinaryOp = (a: number, b: number) => number;
let fcUnary: FcBinaryOp = (a: number): number => a * 2; // Has one fewer parameter and is compatible for assignment.
```

### Enum Compatibility

Different enums are incompatible with each other and cannot be assigned to one another. Numeric enums are compatible with `number`, while string enums are not compatible with `string`.

**TypeScript comparison**

<!-- @[ts_enum_compatibility](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/TypeConversion.ts) -->

``` TypeScript
// Different enums are incompatible with each other.
enum EcColor { Red, Green, Blue }
enum EcStatus { Active, Inactive }

let ecC: EcColor = EcColor.Red;
let ecS: EcStatus = ecC; // Compilation error: different enums are incompatible.

let ecN: number = ecC; // A numeric enum is compatible with number.
console.info(`${ecN}`); // 0
```

### Class Compatibility

Compatibility between classes is based on the comparison of instance member structures, ignoring `static` members. `private` and `protected` members must originate from the same declaration. **ArkTS does not support structural typing comparison**; different classes must have an explicit inheritance relationship before they can be assigned to each other.

<!-- @[ts_class_compatibility](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/TypeConversion.ts) -->

``` TypeScript
// TypeScript class compatibility (structural comparison), which ArkTS does not support
class TsAnimalClass {
  public name: string = '';
}

class TsDeviceClass {
  public name: string = '';
}

// Classes with the same structure can be assigned to each other without an inheritance relationship
let tsA: TsAnimalClass = new TsDeviceClass();
console.info(`${tsA.name}`);
```

### Generic Compatibility

A generic type parameter affects compatibility only when it participates in the member structure. If the generic parameter is not used in any member, it does not affect compatibility.

<!-- @[generic_type_compatibility](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
interface Empty<T> {
  value: T;
}

let strContainer: Empty<string> = { value: 'hello' };
let numContainer: Empty<number> = { value: 42 };
// strContainer and numContainer are incompatible because T participates in the member structure.
```