# Generics

<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=c25b60c237b212cfc232b5aee67d2c42ba90278a translatedAt=2026-08-13T08:58:56.022Z pushedAt=2026-08-13T15:16:10.387Z -->

Generics are a powerful type system feature in TypeScript/ArkTS that allow type parameters to be used when defining functions, classes, and interfaces, enabling code reuse and type safety.

## Basic Concepts of Generics

Generics make types parameters, allowing a single piece of code to work with multiple types while maintaining compile-time type safety. They are the core mechanism for building reusable data structures and utility functions.

### Definition and Core Value of Generics

Generics parameterize types so that a single piece of code works with multiple types while preserving compile-time type safety. The compiler checks the type arguments at call sites and then erases them, combining reusability, type inference, and zero runtime overhead.

<!-- @[generics_introduction](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
// Without generics: write a function for each type.
function identityNumber(arg: number): number {
  return arg;
}

function identityString(arg: string): string {
  return arg;
}

// With generics: one function works for all types.
function identity<T>(arg: T): T {
  return arg;
}

let num: number = identity<number>(42);
let str: string = identity<string>('Hello');
let bool: boolean = identity<boolean>(true);

console.info(`${num}`);   // 42
console.info(`${str}`);   // Hello
console.info(`${bool}`);  // true
```

### Problems Solved by Generics

Using the Object type results in the loss of specific type information. Generics reuse logic while preserving the original type of the passed-in value.

<!-- @[ts_generics_vs_object](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Generics.ts) -->

``` TypeScript
// Using the Object type loses specific type information.
function identityObject(arg: Object): Object {
  return arg;
}

let result1 = identityObject(42);
// The type of result1 is Object, so it cannot be used directly as a number.

// Use generics to preserve type information.
function identityGeneric<T>(arg: T): T {
  return arg;
}

let result2 = identityGeneric(42);
// The type of result2 is automatically inferred as number.
result2.toUpperCase(); // Compilation error: type error message.
```

Generics also apply to data structures, avoiding the need to define a class repeatedly for each element type.

<!-- @[generic_stack_class](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
// Without generics: create a data structure for each type.
class NumberStack {
  private items: number[] = [];
  
  push(item: number): void {
    this.items.push(item);
  }
  
  pop(): number | undefined {
    return this.items.pop();
  }
}

class StringStack {
  private items: string[] = [];
  
  push(item: string): void {
    this.items.push(item);
  }
  
  pop(): string | undefined {
    return this.items.pop();
  }
}

// With generics: one data structure works for all types.
class Stack<T> {
  private items: T[] = [];
  
  push(item: T): void {
    this.items.push(item);
  }
  
  pop(): T | undefined {
    return this.items.pop();
  }
}

let numberStack: Stack<number> = new Stack<number>();
let stringStack: Stack<string> = new Stack<string>();

numberStack.push(1);
numberStack.push(2);
console.info(`${numberStack.pop()}`); // 2

stringStack.push('Hello');
stringStack.push('World');
console.info(`${stringStack.pop()}`); // World
```

### Working Principles of Generics

Generics use the type parameter `<T>` as a placeholder. The concrete type is not bound at definition time; instead, it is specified at the call site or inferred by the compiler.

<!-- @[generic_function_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
// Generic definition
function genericIdentity<T>(arg: T): T {
  return arg;
}

// Specify the concrete type when using it.
let genericOutput1 = genericIdentity<string>('Hello');
// Equivalent to:
function genericIdentityString(arg: string): string {
  return arg;
}

let genericOutput2 = genericIdentity<number>(42);
// Equivalent to:
function genericIdentityNumber(arg: number): number {
  return arg;
}

// Type is inferred automatically.
let genericOutput3 = genericIdentity('ArkTS');  // T is automatically inferred as string.
```

## Generic Functions

Generic functions support multiple type parameters, enabling reusable type-safe code.

### Declaring Generic Functions

Declare a type parameter with `<T>` after the function name, and use it in the parameters and return value.

<!-- @[generic_function_declarations](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
// Basic generic function declaration
function declarationsIdentity<T>(arg: T): T {
  return arg;
}

// Generic function in arrow function form
const identityArrow = <T>(arg: T): T => arg;

// Generic function using a type alias
type IdentityFunction = <T>(arg: T) => T;
let identityAlias: IdentityFunction = declarationsIdentity;

console.info(`${declarationsIdentity<number>(42)}`);       // 42
console.info(`${identityArrow<string>('Hello')}`); // Hello
console.info(`${identityAlias<boolean>(true)}`);   // true
```

### Type Parameter Naming Conventions

Type parameters are typically named with uppercase letters. Common conventions include `T` (Type), `U`, `K` (Key), `V` (Value), and `E` (Element).

<!-- @[multi_type_parameter_class](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
// Example using different naming conventions
class Pair<T, U> {
  public first: T;
  public second: U;

  constructor(first: T, second: U) {
    this.first = first;
    this.second = second;
  }
}

interface Person {
  name: string;
  age: number;
  email: string;
}

let personInfo: Pair<string, number> = new Pair<string, number>('Alice', 25);

console.info(`${personInfo.first}`);  // Alice
console.info(`${personInfo.second}`); // 25
```

### Calling Generic Functions

When calling a generic function, you can explicitly specify the type parameter, or omit it and let the compiler infer it from the arguments.

<!-- @[generic_type_inference](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
function genericIdentityInferred<T>(arg: T): T {
  return arg;
}

// Explicitly specify the type parameter.
let result1: string = genericIdentityInferred<string>('Hello');
console.info(`${result1}`);

// The type parameter is inferred automatically.
let result2: string = genericIdentityInferred('World');
console.info(`${result2}`);

// Generic function with multiple type parameters.
function createPair<T, U>(first: T, second: U): [T, U] {
  return [first, second];
}

let pair1: [string, number] = createPair<string, number>('Age', 25);
let pair2: [string, number] = createPair('Height', 180); // Automatically inferred as [string, number].

console.info(`${pair1[0]}: ${pair1[1]}`); // Age: 25
console.info(`${pair2[0]}: ${pair2[1]}`); // Height: 180
```

### Generic Functions with Multiple Type Parameters

A function can declare multiple type parameters (for example, `<T, U>`), each serving as an independent placeholder that supports expressing relationships between different types.

<!-- @[multi_type_parameter_function](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
// Basic usage of multiple type parameters.
function swap<T, U>(a: T, b: U): [U, T] {
  return [b, a];
}

let swapped: [string, number] = swap(1, 'Hello');
console.info(`${swapped[0]}, ${swapped[1]}`); // Hello, 1

// Complex usage of multiple type parameters: use an explicit structure to store two values of different types.
interface PairValue<T, U> {
  left: T;
  right: U;
}

function combineValues<T, U>(left: T, right: U): PairValue<T, U> {
  return {
    left: left,
    right: right
  };
}

interface Name {
  name: string;
}

interface Age {
  age: number;
}

let nameObj: Name = { name: 'Alice' };
let ageObj: Age = { age: 25 };

let combinedObj: PairValue<Name, Age> = combineValues<Name, Age>(nameObj, ageObj);
console.info(`${combinedObj.left.name}`);
console.info(`${combinedObj.right.age}`);

// Create a mapping function using type parameters.
function mapArray<T, R>(arr: T[], mapper: (item: T) => R): R[] {
  let result: R[] = [];
  for (let item of arr) {
    result.push(mapper(item));
  }
  return result;
}

let numbers: number[] = [1, 2, 3, 4, 5];
let doubled: number[] = mapArray<number, number>(numbers, (n: number): number => n * 2);
console.info(`${doubled.join(', ')}`); // 2, 4, 6, 8, 10

let strings: string[] = ['a', 'b', 'c'];
let uppercased: string[] = mapArray<string, string>(strings, (s: string): string => s.toUpperCase());
console.info(`${uppercased.join(', ')}`); // A, B, C
```

## Generic Classes

Generic classes create type-safe classes that support multiple data types.

### Declaring Generic Classes

Declare a type parameter with `<T>` after the class name, and use it in the class properties and methods.

<!-- @[generic_class_basic](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
// Basic generic class declaration
class Container<T> {
  private value: T;
  
  constructor(initialValue: T) {
    this.value = initialValue;
  }
  
  public getValue(): T {
    return this.value;
  }
  
  public setValue(newValue: T): void {
    this.value = newValue;
  }
}

let numberContainer: Container<number> = new Container<number>(42);
console.info(`${numberContainer.getValue()}`); // 42
numberContainer.setValue(100);
console.info(`${numberContainer.getValue()}`); // 100

let stringContainer: Container<string> = new Container<string>('Hello');
console.info(`${stringContainer.getValue()}`); // Hello
stringContainer.setValue('World');
console.info(`${stringContainer.getValue()}`); // World
```

### Instantiating a Generic Class

When instantiating a generic class, specify the type parameter through `new ClassName<Type>(...)`. If the type is consistent, it can be omitted and inferred by the compiler.

<!-- @[generic_class_instantiation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
class GciContainer<T> {
  private value: T;

  constructor(value: T) {
    this.value = value;
  }

  getValue(): T {
    return this.value;
  }
}

// Explicitly specify the type parameter for instantiation.
let gciContainer1: GciContainer<number> = new GciContainer<number>(10);

// Automatically infer the type parameter for instantiation.
let gciContainer2: GciContainer<string> = new GciContainer<string>('hello');

// The type parameter can be omitted (inferred by the compiler).
let gciContainer3: GciContainer<boolean> = new GciContainer<boolean>(true);

console.info(`${gciContainer1.getValue()}`); // 10
console.info(`${gciContainer2.getValue()}`); // hello
console.info(`${gciContainer3.getValue()}`); // true
```

### Properties and Methods in Generic Classes

The properties and methods of a generic class can use type parameters to implement type-safe containers and operations. For example, `add(item: T)` of `GenericCollection<T>` ensures that only elements of type `T` can be added, and the return value of `get(index: number): T` is automatically inferred as type `T` without type assertion.

<!-- @[generic_collection_class](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
class GenericCollection<T> {
  // Generic property.
  private items: T[] = [];
  public count: number = 0;
  
  // Generic method.
  public add(item: T): void {
    this.items.push(item);
    this.count++;
  }
  
  public remove(item: T): boolean {
    let index = this.items.indexOf(item);
    if (index > -1) {
      this.items.splice(index, 1);
      this.count--;
      return true;
    }
    return false;
  }
  
  public get(index: number): T | undefined {
    return this.items[index];
  }
  
  public getAll(): T[] {
    return this.items;
  }
  
  // Generic method returning a generic type.
  public filter(predicate: (item: T) => boolean): GenericCollection<T> {
    let filtered = new GenericCollection<T>();
    this.items.forEach((item: T): void => {
      if (predicate(item)) {
        filtered.add(item);
      }
    });
    return filtered;
  }
}

let collection: GenericCollection<number> = new GenericCollection<number>();
collection.add(1);
collection.add(2);
collection.add(3);
collection.add(4);
collection.add(5);

console.info(`${collection.count}`); // 5
console.info(`${collection.get(0)}`); // 1

let evenNumbers: GenericCollection<number> = collection.filter((n: number): boolean => n % 2 === 0);
console.info(`${evenNumbers.getAll().join(', ')}`); // 2, 4
```

### Generic Classes with Multiple Type Parameters

A generic class can declare multiple type parameters (for example, `<K, V>`), which is commonly used in structures such as key-value pairs that require multiple types to work together.

<!-- @[multi_type_parameter_generic_class](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
// Generic class with multiple type parameters.
class ParamPair<K, V> {
  private key: K;
  private value: V;
  
  constructor(key: K, value: V) {
    this.key = key;
    this.value = value;
  }
  
  public getKey(): K {
    return this.key;
  }
  
  public getValue(): V {
    return this.value;
  }
  
  public setKey(newKey: K): void {
    this.key = newKey;
  }
  
  public setValue(newValue: V): void {
    this.value = newValue;
  }
  
  public toString(): string {
    return `(${this.key}: ${this.value})`;
  }
}

let paramPair1: ParamPair<string, number> = new ParamPair<string, number>('Age', 25);
console.info(`${paramPair1.toString()}`); // (Age: 25)

let paramPair2: ParamPair<number, string> = new ParamPair<number, string>(1, 'One');
console.info(`${paramPair2.toString()}`); // (1: One)

// Complex generic class with multiple type parameters.
class Triple<A, B, C> {
  private first: A;
  private second: B;
  private third: C;
  
  constructor(first: A, second: B, third: C) {
    this.first = first;
    this.second = second;
    this.third = third;
  }
  
  public getFirst(): A {
    return this.first;
  }
  
  public getSecond(): B {
    return this.second;
  }
  
  public getThird(): C {
    return this.third;
  }
  
  public toArray(): [A, B, C] {
    return [this.first, this.second, this.third];
  }
}

let triple: Triple<string, number, boolean> = new Triple<string, number, boolean>('Hello', 42, true);
let tripleValues: [string, number, boolean] = triple.toArray();
console.info(`${tripleValues[0]}, ${tripleValues[1]}, ${tripleValues[2]}`); // Hello,42,true
```

ArkTS supports tuple types (for example, `[A, B, C]`) as return types and variable types, with elements accessed by index (`tuple[0]`). However, it does not support tuple destructuring syntax (for example, `let [a, b, c] = tuple`); you must extract elements one by one through indexing.

## Generic Interfaces

A generic interface introduces type parameters into the contract definition, allowing a single interface to adapt to multiple data types. It is commonly used for abstractions such as callbacks and repositories.

### Declaring Generic Interfaces

Declare a type parameter with `<T>` after the interface name, and use it in member signatures.

<!-- @[generic_interface_basic](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
// Basic generic interface declaration
interface GenericIdentity {
  invoke<T>(arg: T): T;
}

class GenericIdentityImpl implements GenericIdentity {
  public invoke<T>(arg: T): T {
    return arg;
  }
}

// Generic interface as a function type
let myIdentity: GenericIdentity = new GenericIdentityImpl();

console.info(`${myIdentity.invoke<string>('Hello')}`); // Hello

// Generic parameter as an interface parameter
interface GenericIdentityFunction<T> {
  invoke(arg: T): T;
}

class NumberIdentityFunction implements GenericIdentityFunction<number> {
  public invoke(arg: number): number {
    return arg;
  }
}

let myIdentityFunction: GenericIdentityFunction<number> = new NumberIdentityFunction();

console.info(`${myIdentityFunction.invoke(42)}`); // 42
```

### Generic Interface as a Function Type Constraint

Use a generic interface to describe a callback or function signature so that the type parameters of the callback remain consistent with the concrete implementation.

<!-- @[generic_interface_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
// Define a function type with a generic interface.
interface Callback<T> {
  invoke(result: T): void;
}

interface AsyncCallback<T> {
  invoke(result: T): Promise<void>;
}

// Constrain a function type with a generic interface.
function processData<T>(data: T, callback: Callback<T>): void {
  callback.invoke(data);
}

class StringCallback implements Callback<string> {
  public invoke(result: string): void {
    console.info(`Processed: ${result}`);
  }
}

class NumberCallback implements Callback<number> {
  public invoke(result: number): void {
    console.info(`Processed: ${result}`);
  }
}

processData<string>('Hello', new StringCallback());

processData<number>(42, new NumberCallback());

// Use a generic interface in an asynchronous function.
async function processAsyncData<T>(data: T, callback: AsyncCallback<T>): Promise<void> {
  await callback.invoke(data);
}

class AsyncStringCallback implements AsyncCallback<string> {
  public async invoke(result: string): Promise<void> {
    console.info(`Async processed: ${result}`);
  }
}

processAsyncData<string>('Hello', new AsyncStringCallback());
```

### Generic Interface as a Class Implementation Constraint

When a class implements a generic interface, it must specify concrete type parameters, which uniformly constrain the method signatures and entity types exposed by the class.

<!-- @[generic_interface_repository](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
interface Repository<T> {
  findById(id: number): T | null;
  findAll(): T[];
  save(entity: T): void;
  delete(id: number): void;
}

interface User {
  id: number;
  name: string;
  email: string;
}

class UserRepository implements Repository<User> {
  private users: User[] = [];
  
  public findById(id: number): User | null {
    return this.users.find((user: User): boolean => user.id === id) ?? null;
  }
  
  public findAll(): User[] {
    return [...this.users];
  }
  
  public save(entity: User): void {
    let existing: User | null = this.findById(entity.id);
    if (existing !== null) {
      let index = this.users.indexOf(existing);
      this.users[index] = entity;
    } else {
      this.users.push(entity);
    }
  }
  
  public delete(id: number): void {
    this.users = this.users.filter((user: User): boolean => user.id !== id);
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

### Default Type Parameters of Generic Interfaces

A generic interface uses its default type parameter when no type is specified, which simplifies the call.

<!-- @[generic_interface_default_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
// Default type parameters of a generic interface
interface ApiResponse<T = string> {
  data: T;
  status: number;
  message: string;
}

// Use the default type.
let response1: ApiResponse = {
  data: 'OK',
  status: 200,
  message: 'Success'
};

// Specify a concrete type.
let response2: ApiResponse<string> = {
  data: 'Hello',
  status: 200,
  message: 'Success'
};

console.info(`${response1.data}`);
console.info(`${response2.data}`);

// Default values for multiple type parameters.
interface DefaultPair<T = string, U = number> {
  first: T;
  second: U;
}

let defaultPair1: DefaultPair = { first: 'Hello', second: 42 };
let defaultPair2: DefaultPair<number> = { first: 100, second: 200 };
let pair3: DefaultPair<number, string> = { first: 100, second: 'Hello' };

console.info(`${defaultPair1}`);
console.info(`${defaultPair2}`);
console.info(`${pair3}`);
```

## Generic Type Constraints

Constraints are imposed on type parameters via `extends`, restricting them to interfaces or structures they must satisfy, thereby striking a balance between flexibility and type safety in generics.

### Basic Type Constraints

Use `<T extends SomeInterface>` to constrain a type parameter to a specific structure (such as the `length` property). A compilation error is reported if the constraint is not satisfied.

<!-- @[ts_generic_constraint_length](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Generics.ts) -->

``` TypeScript
// Constrain the generic parameter to have the length property.
interface Lengthwise {
  length: number;
}

function getLength<T extends Lengthwise>(arg: T): number {
  return arg.length;
}

class LengthSample implements Lengthwise {
  public length: number;

  constructor(length: number) {
    this.length = length;
  }
}

console.info(`${getLength('Hello')}`);        // 5
console.info(`${getLength([1, 2, 3])}`);      // 3
console.info(`${getLength(new LengthSample(10))}`); // 10

// Compilation error: the number type has no length property.
console.info(`${getLength(42)}`);
```

### Constraining to a Specific Interface or Class

Constrain a type parameter to an interface or class to ensure that the methods defined by that interface can be called within the generic function.

<!-- @[ts_generic_constraint_serializable](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Generics.ts) -->

``` TypeScript
interface Serializable {
  serialize(): string;
}

class User implements Serializable {
  public name: string;
  public age: number;

  constructor(name: string, age: number) {
    this.name = name;
    this.age = age;
  }

  public serialize(): string {
    return JSON.stringify({ name: this.name, age: this.age });
  }
}

class Product implements Serializable {
  public id: number;
  public title: string;

  constructor(id: number, title: string) {
    this.id = id;
    this.title = title;
  }

  public serialize(): string {
    return JSON.stringify({ id: this.id, title: this.title });
  }
}

// Constrain the generic parameter to implement the Serializable interface.
function saveToStorage<T extends Serializable>(entity: T): void {
  let serialized = entity.serialize();
  console.info(`Saving: ${serialized}`);
}

let user = new User('Alice', 25);
let product = new Product(1, 'Laptop');

saveToStorage(user);    // Saving: {"name":"Alice","age":25}
saveToStorage(product); // Saving: {"id":1,"title":"Laptop"}

// Compilation error: the number type has no serialize method.
saveToStorage(42);
```

### Constraining Specific Properties

Define the required set of properties through an interface to constrain the type parameter to have all these properties. Multiple interface constraints can be combined.

<!-- @[generic_constraint_property](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
interface HasId {
  id: number;
}

interface HasName {
  name: string;
}

// Constrain the generic parameter to include the id property.
function findById<T extends HasId>(items: T[], id: number): T | null {
  for (let item of items) {
    if (item.id === id) {
      return item;
    }
  }
  return null;
}

// Constrain the generic parameter to include the name property.
function findByName<T extends HasName>(items: T[], name: string): T | null {
  for (let item of items) {
    if (item.name === name) {
      return item;
    }
  }
  return null;
}

interface ConstraintUser {
  id: number;
  name: string;
  email: string;
}

let users: ConstraintUser[] = [
  { id: 1, name: 'Alice', email: 'alice@example.com' },
  { id: 2, name: 'Bob', email: 'bob@example.com' },
  { id: 3, name: 'Charlie', email: 'charlie@example.com' }
];

let userById: ConstraintUser | null = findById<ConstraintUser>(users, 1);
let userByName: ConstraintUser | null = findByName<ConstraintUser>(users, 'Bob');
console.info(`${userById ? userById.name : ''}`);    // Alice
console.info(`${userByName ? userByName.id : 0}`); // 2
```

### Combining Multiple Constraints

TypeScript commonly uses intersection types to combine multiple constraints. In ArkTS, declare a named interface that inherits from multiple interfaces first, and then constrain the type parameter to that interface.

<!-- @[generic_constraint_multiple](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
interface MultipleHasId {
  id: number;
}

interface MultipleHasName {
  name: string;
}

interface HasTimestamp {
  createdAt: Date;
  updatedAt: Date;
}

interface NamedEntity extends MultipleHasId, MultipleHasName {}

interface AuditedEntity extends MultipleHasId, MultipleHasName, HasTimestamp {}

// Combining multiple constraints
function findEntity<T extends NamedEntity>(items: T[], id: number, name: string): T | null {
  return items.find(item => item.id === id && item.name === name) || null;
}

// Triple constraint
function logEntity<T extends AuditedEntity>(entity: T): void {
  console.info(`ID: ${entity.id}, Name: ${entity.name}, Created: ${entity.createdAt}`);
}

interface MultipleUser extends MultipleHasId, MultipleHasName, HasTimestamp {
  email: string;
}

let user: MultipleUser = {
  id: 1,
  name: 'Alice',
  email: 'alice@example.com',
  createdAt: new Date('2024-01-01'),
  updatedAt: new Date('2024-01-02')
};

logEntity(user);
```

## TypeScript Generic Utility Types Comparison

TypeScript provides generic utility types such as `Partial<T>`, `Required<T>`, `Readonly<T>`, `Pick<T, K>`, `Omit<T, K>`, and `Record<K, T>` for transforming existing types at the type level. ArkTS provides limited support for utility types such as `Partial<T>`, `Required<T>`, `Readonly<T>`, and `Record<K, T>`. For complex type transformations such as `Pick<T, K>` and `Omit<T, K>`, ordinary tutorials prefer explicit interfaces, classes, or generic constraints to express business structures.

### Using Explicit Interfaces Instead of Pick and Omit

ArkTS does not support `Pick<T,K>` and `Omit<T,K>`. For details, see [TypeScript to ArkTS Migration Guide](typescript-to-arkts-migration-guide.md#some-utility-types-are-not-supported). Use explicitly defined interfaces to express the required subset of properties instead.

<!-- @[related_interfaces](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
interface Product {
  id: number;
  title: string;
  description: string;
  price: number;
  stock: number;
  category: string;
}

interface ProductSummary {
  id: number;
  title: string;
  price: number;
}

interface CreateProductRequest {
  title: string;
  description: string;
  price: number;
  stock: number;
  category: string;
}

let summary: ProductSummary = {
  id: 1,
  title: 'Laptop',
  price: 999
};

let createRequest: CreateProductRequest = {
  title: 'Smartphone',
  description: 'High-end smartphone',
  price: 599,
  stock: 100,
  category: 'Electronics'
};
```

This approach is more direct than type transformation and also facilitates API documentation and code review.

### Using Map or a Class Instead of a Complex Record

Use `Map` or a class instead of a complex `Record` type to obtain clearer type constraints.

<!-- @[generic_map](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
interface MenuItem {
  label: string;
  path: string;
  icon?: string;
}

let menu: Map<string, MenuItem> = new Map<string, MenuItem>();
menu.set('home', { label: 'Home', path: '/', icon: 'home-icon' });
menu.set('contact', { label: 'Contact', path: '/contact' });

let home: MenuItem | undefined = menu.get('home');
if (home !== undefined) {
  console.info(`${home.label}`);
}
```

If the field set is fixed, using an interface is clearer than a dynamic dictionary.

### Using readonly Fields Instead of Readonly

Use the `readonly` modifier to mark class properties as read-only, replacing `Readonly<T>` to enforce immutable field constraints.

<!-- @[readonly_user](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
class ReadonlyUser {
  public readonly id: number;
  public readonly name: string;

  constructor(id: number, name: string) {
    this.id = id;
    this.name = name;
  }
}

let userUser: ReadonlyUser = new ReadonlyUser(1, 'Alice');
console.info(`${userUser.name}`);
```

### Using Optional Fields Instead of Partial

Use the `?` modifier to define optional properties, replacing `Partial<T>` to express the object structure of a partial update.

<!-- @[partial_update_request](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
interface UpdateUserRequest {
  name?: string;
  email?: string;
  age?: number;
}

function updateUser(id: number, request: UpdateUserRequest): void {
  console.info(`Update user ${id}`);
  if (request.name !== undefined) {
    console.info(`${request.name}`);
  }
}
```

## Advanced Boundaries of Generics

Generic constraints restrict the type range through `extends` and support nested and recursive constraints. ArkTS generic constraint behavior is basically consistent with TypeScript, supporting `extends` constraints, multi-parameter constraints, and usage where a constrained type parameter references other type parameters.

### Conditional Types, Mapped Types, and infer

Conditional types, mapped types, and infer are advanced type tools in TypeScript and are not used as regular syntax in ArkTS.

<!-- @[ts_utility_types_note](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Generics.ts) -->

``` TypeScript
// TypeScript syntax, not used as regular syntax in ArkTS.
type Nullable<T> = T | null;
type ReadonlyProps<T> = { readonly [P in keyof T]: T[P] };
type ElementType<T> = T extends Array<infer Item> ? Item : T;
```

### Boundaries of Generic Type Inference

The compiler infers type parameters from arguments, but when multiple candidates or union types exist, the inference may be imprecise and requires explicit specification.

<!-- @[generic_first_element](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
function first<T>(items: T[]): T | undefined {
  return items.length > 0 ? items[0] : undefined;
}

let names: string[] = ['Alice', 'Bob'];
let firstName: string | undefined = first<string>(names);
```

### Default Values of Generic Parameters

When not specified, generic parameters use their default types, reducing the type parameters required at call sites.

<!-- @[generic_default_type_parameter](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
// Default values of generic parameters
interface ParamApiResponse<T = string, E = Error> {
  data: T;
  error?: E;
  status: number;
}

class CustomError extends Error {
  public code: number;
  
  constructor(message: string) {
    super(message);
    this.code = 404;
  }
}

// Use the default type parameters.
let paramResponse1: ParamApiResponse = {
  data: 'Hello',
  status: 200
};

// Specify some type parameters.
let paramResponse2: ParamApiResponse<string> = {
  data: 'Hello',
  status: 200
};

// Specify all type parameters.
let response3: ParamApiResponse<string, CustomError> = {
  data: 'Hello',
  error: new CustomError('Not found'),
  status: 404
};

console.info(`${paramResponse1.data}`);
console.info(`${paramResponse2.data}`);
console.info(`${response3.error?.message}`);
```

### Combining Generics with Nested Types

Generics can be combined with nested types to build recursive data structures such as trees and linked lists.

<!-- @[generic_nested_types](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
// Generic nested type: tree.
interface TsTree<T> {
  value: T;
  children?: TsTree<T>[];
}

let tsLeaf4: TsTree<number> = { value: 4 };
let tsLeaf5: TsTree<number> = { value: 5 };
let tsBranch3: TsTree<number> = { value: 3, children: [tsLeaf4, tsLeaf5] };
let tsBranch2: TsTree<number> = { value: 2 };
let tsNumberTree: TsTree<number> = {
  value: 1,
  children: [tsBranch2, tsBranch3]
};

console.info(`${tsNumberTree.value}`); // 1
console.info(`${tsNumberTree.children?.[0].value}`); // 2

// Generic nested type: linked list.
interface TsListNode<T> {
  value: T;
  next?: TsListNode<T>;
}

let tsThird: TsListNode<string> = { value: 'third' };
let tsSecond: TsListNode<string> = { value: 'second', next: tsThird };
let tsFirst: TsListNode<string> = { value: 'first', next: tsSecond };

let tsCurrent: TsListNode<string> | undefined = tsFirst;
while (tsCurrent !== undefined) {
  console.info(`${tsCurrent.value}`); // first, second, third
  tsCurrent = tsCurrent.next;
}
```

## keyof Type Operator

`keyof` is a TypeScript type operator used to obtain the union of all property names of an object type. ArkTS provides limited support for it. In regular business code, prefer explicit type declarations.

**TypeScript Comparison**

<!-- @[ts_keyof_operator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Generics.ts) -->

``` TypeScript
// TypeScript comparison syntax; not used as regular syntax in ArkTS
interface KeyofPointType {
  x: number;
  y: number;
}
type P = keyof KeyofPointType;  // "x" | "y"

function getProperty<T, K extends keyof T>(obj: T, key: K) {
  return obj[key];
}
```

In ArkTS, prefer explicit property names and type annotations instead of `keyof`.

<!-- @[keyof_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
interface KeyofPoint {
  x: number;
  y: number;
}

function keyofGetX(p: KeyofPoint): number {
  return p.x;
}

function keyofGetY(p: KeyofPoint): number {
  return p.y;
}

let keyofPt: KeyofPoint = { x: 10, y: 20 };
console.info(`${keyofGetX(keyofPt).toString()}`);  // 10
console.info(`${keyofGetY(keyofPt).toString()}`);  // 20
```

## typeof Type Operator

In TypeScript, `typeof` is used in a type context to obtain the type of a runtime value. In ArkTS, it is not used as a regular type operation; explicitly declare the type instead.

**TypeScript Comparison**

<!-- @[ts_typeof_operator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Generics.ts) -->

``` TypeScript
// TypeScript comparison syntax; not used as regular syntax in ArkTS.
let tsConfig = { url: 'EXAMPLE_API_URL', timeout: 5000 };
type TsConfig = typeof tsConfig; // { url: string; timeout: number; }
```

In ArkTS, prefer explicitly declaring the type with an interface.

<!-- @[typeof_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
interface TypeofConfig {
  url: string;
  timeout: number;
}

let typeofConfig: TypeofConfig = {
  url: 'EXAMPLE_CONFIG_URL',
  timeout: 5000
};

console.info(`${typeofConfig.url}`);
console.info(`${typeofConfig.timeout.toString()}`);
```

## Indexed Access Types

Indexed access types use the `T[K]` syntax to obtain the type of a specific property from an existing type. ArkTS does not support indexed access types; use explicit type declarations instead.

**TypeScript Comparison**

<!-- @[ts_indexed_access](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Generics.ts) -->

``` TypeScript
// Variance annotations: covariant out, contravariant in, invariant in out.
type IndexedPerson = { name: string; age: number; alive: boolean };
type IndexedName = IndexedPerson['name'];   // string
type IndexedAge = IndexedPerson['age'];     // number
```

In ArkTS, use the property type directly.

<!-- @[indexed_access_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
interface IndexedAccessPerson {
  name: string;
  age: number;
  alive: boolean;
}

let iaPersonName: string = 'Alice';
let iaPersonAge: number = 30;
let iaPersonAlive: boolean = true;

console.info(`${iaPersonName}`);
console.info(`${iaPersonAge.toString()}`);
console.info(`${iaPersonAlive.toString()}`);
```

## Conditional Types

A conditional type takes the form `T extends U ? X : Y`, which is similar to an if statement at the type level. ArkTS does not support conditional types; use function overloads or union types instead.

**TypeScript Comparison**

<!-- @[ts_conditional_types](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Generics.ts) -->

``` TypeScript
// Variance annotations: covariant out, contravariant in, invariant in out
type IsString<T> = T extends string ? true : false;
type CondA = IsString<string>;   // true
type CondB = IsString<number>;   // false

// infer keyword
type GetReturn<T> = T extends (...args: never[]) => infer R ? R : never;
type CondR = GetReturn<() => string>;  // string

// Distributive conditional type.
type ToArray<T> = T extends unknown ? T[] : never;
type CondResult = ToArray<string | number>;  // string[] | number[]
```

In ArkTS, use function overloading or union types instead of conditional types.

<!-- @[conditional_type_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
function formatCondValue(value: string): string;
function formatCondValue(value: number): string;
function formatCondValue(value: string | number): string {
  if (typeof value === 'string') {
    return value.toUpperCase();
  }
  return value.toFixed(2);
}

let condS: string = formatCondValue('hello');
let condN: string = formatCondValue(42);
console.info(`${condS}`);  // HELLO
console.info(`${condN}`);  // 42.00
```

## Mapped Types

A mapped type creates a new type by iterating over each property of an existing type, with the syntax `{ [P in keyof T]: ... }`. ArkTS does not support mapped types; use explicit interface declarations instead.

**TypeScript Comparison**

<!-- @[ts_mapped_types](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Generics.ts) -->

``` TypeScript
// Variance annotations: covariant out, contravariant in, invariant in out
type MappedReadonly<T> = { readonly [P in keyof T]: T[P] };
type MappedPartial<T> = { [P in keyof T]?: T[P] };

// Key remapping
type MappedGetters<T> = {
  [P in keyof T as `get${Capitalize<string & P>}`]: () => T[P]
};
```

In ArkTS, use explicit declarations instead of mapped types.

<!-- @[mapped_type_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
interface MappedReadonlyUser {
  readonly id: number;
  readonly name: string;
}

interface MappedPartialUser {
  name?: string;
  age?: number;
  email?: string;
}

interface MappedUserGetters {
  getName(): string;
  getAge(): number;
}

class MappedUser implements MappedUserGetters {
  public name: string = '';
  public age: number = 0;

  getName(): string {
    return this.name;
  }

  getAge(): number {
    return this.age;
  }
}
```

## Variance Annotations

Variance describes how the subtyping relationship of generic type parameters propagates to the generic type itself. Covariance (`out`) means the subtyping relationship preserves its direction—`Producer<Cat>` is a subtype of `Producer<Animal>`. Contravariance (`in`) means the direction is reversed—`Consumer<Animal>` is a subtype of `Consumer<Cat>`. Invariance (`in out`) means there is no subtyping relationship. ArkTS supports the `in`/`out`/`in out` variance annotation syntax. The compiler can usually infer the variance relationship automatically, and manual annotations are used only in a very small number of recursive type scenarios.

<!-- @[variance_annotations](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
interface VaConsumer<in T> { consume: (arg: T) => void; }
interface VaProducer<out T> { make(): T; }
interface VaProducerConsumer<in out T> { consume: (arg: T) => void; make(): T; }
```

In ArkTS, variance annotations are processed by the compiler. Manual annotation is usually unnecessary because the compiler infers the variance relationship automatically.

## More Utility Type Comparisons

TypeScript also provides utility types such as `Exclude`, `Extract`, `NonNullable`, `Parameters`, and `ReturnType`, which require explicit alternatives in ArkTS.

**Exclude and Extract**

<!-- @[ts_exclude_extract](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Generics.ts) -->

``` TypeScript
// TypeScript equivalent syntax, not used as regular syntax in ArkTS.
type AllTypes = 'a' | 'b' | 'c';
type Excluded = Exclude<AllTypes, 'c'>;      // 'a' | 'b'
type Extracted = Extract<AllTypes, 'a' | 'x'>; // 'a'
```

In ArkTS, declare the union type directly.

<!-- @[exclude_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
type ExcludeAllTypes = 'a' | 'b' | 'c';
type ExcludeFiltered = 'a' | 'b';

let excludeValue: ExcludeFiltered = 'a';
console.info(`${excludeValue}`);
```

**NonNullable**

<!-- @[ts_nonnullable](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Generics.ts) -->

``` TypeScript
// TypeScript equivalent; not used as regular syntax in ArkTS.
type NullableType = string | null | undefined;
type NonNullType = NonNullable<NullableType>;  // string
```

In ArkTS, use a non-nullable type directly.

<!-- @[nonnullable_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
let nnValue: string = 'hello';
console.info(`${nnValue}`);
```

**Parameters and ReturnType**

<!-- @[ts_parameters_returntype](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Generics.ts) -->

``` TypeScript
// TypeScript equivalent; not used as regular syntax in ArkTS.
function prFunction(s: string): number { return s.length; }
type PRParams = Parameters<typeof prFunction>;   // [string]
type PRReturn = ReturnType<typeof prFunction>;   // number
```

In ArkTS, explicitly declare the parameter and return value types.

<!-- @[params_return_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
function prArkFunc(s: string): number {
  return s.length;
}

let prParam: string = 'hello';
let prResult: number = prArkFunc(prParam);
console.info(`${prResult.toString()}`);  // 5
```

**Awaited**

<!-- @[ts_awaited](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Generics.ts) -->

``` TypeScript
// TypeScript equivalent, not used as regular syntax in ArkTS.
type AwaitedType = Awaited<Promise<string>>;  // string
```

In ArkTS, directly use the unwrapped type.

<!-- @[awaited_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
async function awaitedGetData(): Promise<string> {
  return 'hello';
}

async function awaitedMain(): Promise<void> {
  let data: string = await awaitedGetData();
  console.info(`${data}`);  // hello
}

awaitedMain();
```

**ConstructorParameters and InstanceType**

<!-- @[ts_ctor_params_instance_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Generics.ts) -->

``` TypeScript
// TypeScript equivalent, not used as regular syntax in ArkTS
class CpPoint {
  constructor(public x: number, public y: number) {}
}
type CpCtorParams = ConstructorParameters<typeof CpPoint>; // [number, number]
type CpInstance = InstanceType<typeof CpPoint>;             // CpPoint
```

In ArkTS, explicitly declare the constructor parameter types and the instance type.

<!-- @[ctor_params_instance_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
class CpaPoint {
  public x: number;
  public y: number;

  constructor(x: number, y: number) {
    this.x = x;
    this.y = y;
  }
}

let cpaParams: number[] = [3, 4];
let cpaInstance: CpaPoint = new CpaPoint(cpaParams[0], cpaParams[1]);
console.info(`${cpaInstance.x}, ${cpaInstance.y}`); // 3, 4
```

**String manipulation types (Uppercase/Lowercase/Capitalize/Uncapitalize)**

<!-- @[ts_string_utils](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Generics.ts) -->

``` TypeScript
// TypeScript equivalent, not used as regular syntax in ArkTS
type Upper = Uppercase<'hello'>;   // 'HELLO'
type Lower = Lowercase<'WORLD'>;   // 'world'
type Cap = Capitalize<'foo'>;      // 'Foo'
type Uncap = Uncapitalize<'Bar'>;  // 'bar'
```

In ArkTS, use string methods directly to handle case conversion.

<!-- @[string_method_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
let smUpperStr: string = 'hello'.toUpperCase();
let smLowerStr: string = 'WORLD'.toLowerCase();
console.info(`${smUpperStr}`); // HELLO
console.info(`${smLowerStr}`); // world
```

**ThisType**

In TypeScript, `ThisType<T>` marks the contextual type of `this` and is often used to specify the type of `this` in object literals. ArkTS does not use `ThisType`; instead, it clarifies the target of `this` through classes and methods.

<!-- @[ts_thistype_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Generics.ts) -->

``` TypeScript
// TypeScript equivalent (not supported in ArkTS)
interface MyContext {
  name: string;
}
const obj: ThisType<MyContext> = {
  greet() {
    return this.name;
  }
};
```

ArkTS alternative: use a class to explicitly bind `this`.

<!-- @[thistype_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
class ThContext {
  public name: string;

  constructor(name: string) {
    this.name = name;
  }

  greet(): string {
    return this.name;
  }
}

let thCtx: ThContext = new ThContext('Alice');
console.info(`${thCtx.greet()}`); // Alice
```

## When to Use

Generics are commonly used for general-purpose data structures, utility functions, and network request wrappers.

### Generic Data Structures

Generic data structures such as stacks and queues apply to elements of any type.

<!-- @[generic_data_structures](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
// Generic stack data structure.
class StructuresStack<T> {
  private items: T[] = [];
  
  push(item: T): void {
    this.items.push(item);
  }
  
  pop(): T | undefined {
    return this.items.pop();
  }
  
  peek(): T | undefined {
    return this.items[this.items.length - 1];
  }
  
  isEmpty(): boolean {
    return this.items.length === 0;
  }
  
  size(): number {
    return this.items.length;
  }
  
  clear(): void {
    this.items = [];
  }
}

let structuresNumberStack = new StructuresStack<number>();
structuresNumberStack.push(1);
structuresNumberStack.push(2);
structuresNumberStack.push(3);

console.info(`${structuresNumberStack.pop()}`);    // 3
console.info(`${structuresNumberStack.peek()}`);   // 2
console.info(`${structuresNumberStack.size()}`);   // 2

// Generic queue data structure.
class Queue<T> {
  private items: T[] = [];
  
  enqueue(item: T): void {
    this.items.push(item);
  }
  
  dequeue(): T | undefined {
    return this.items.shift();
  }
  
  front(): T | undefined {
    return this.items[0];
  }
  
  isEmpty(): boolean {
    return this.items.length === 0;
  }
  
  size(): number {
    return this.items.length;
  }
}

let stringQueue = new Queue<string>();
stringQueue.enqueue('First');
stringQueue.enqueue('Second');
stringQueue.enqueue('Third');

console.info(`${stringQueue.dequeue()}`); // First
console.info(`${stringQueue.front()}`);   // Second
console.info(`${stringQueue.size()}`);    // 2

// Generic linked list data structure.
class LinkedListNode<T> {
  public value: T;
  public next: LinkedListNode<T> | null = null;
  
  constructor(value: T) {
    this.value = value;
  }
}

class LinkedList<T> {
  private head: LinkedListNode<T> | null = null;
  private tail: LinkedListNode<T> | null = null;
  private length: number = 0;
  
  append(value: T): void {
    let newNode = new LinkedListNode(value);
    
    if (!this.head) {
      this.head = newNode;
      this.tail = newNode;
    } else {
      this.tail!.next = newNode;
      this.tail = newNode;
    }
    
    this.length++;
  }
  
  prepend(value: T): void {
    let newNode = new LinkedListNode(value);
    newNode.next = this.head;
    this.head = newNode;
    
    if (!this.tail) {
      this.tail = newNode;
    }
    
    this.length++;
  }
  
  insert(index: number, value: T): void {
    if (index === 0) {
      this.prepend(value);
      return;
    }
    
    if (index >= this.length) {
      this.append(value);
      return;
    }
    
    let newNode = new LinkedListNode(value);
    let prevNode = this.getNodeAt(index - 1);
    
    if (prevNode) {
      newNode.next = prevNode.next;
      prevNode.next = newNode;
      this.length++;
    }
  }
  
  remove(index: number): T | null {
    if (index < 0 || index >= this.length) {
      return null;
    }
    
    if (index === 0) {
      let removedNode = this.head;
      this.head = this.head?.next || null;
      this.length--;
      return removedNode?.value || null;
    }
    
    let prevNode = this.getNodeAt(index - 1);
    if (prevNode && prevNode.next) {
      let removedNode = prevNode.next;
      prevNode.next = removedNode.next;
      this.length--;
      return removedNode.value;
    }
    
    return null;
  }
  
  get(index: number): T | null {
    let node = this.getNodeAt(index);
    return node?.value || null;
  }
  
  private getNodeAt(index: number): LinkedListNode<T> | null {
    if (index < 0 || index >= this.length) {
      return null;
    }
    
    let current = this.head;
    for (let i = 0; i < index; i++) {
      current = current?.next || null;
    }
    
    return current;
  }
  
  size(): number {
    return this.length;
  }
  
  isEmpty(): boolean {
    return this.length === 0;
  }
}

let linkedList = new LinkedList<number>();
linkedList.append(1);
linkedList.append(2);
linkedList.append(3);
linkedList.prepend(0);

console.info(`${linkedList.get(0)}`); // 0
console.info(`${linkedList.get(2)}`); // 2
console.info(`${linkedList.size()}`); // 4

linkedList.remove(1);
console.info(`${linkedList.size()}`); // 3
```

### Generic Utility Functions

Generic utility functions such as map and filter apply to collection operations of any type.

<!-- @[generic_array_utilities](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
// Generic array utility function
function utilitiesFirst<T>(arr: T[]): T | undefined {
  return arr[0];
}

function last<T>(arr: T[]): T | undefined {
  return arr[arr.length - 1];
}

function shuffle<T>(arr: T[]): T[] {
  let result = [...arr];
  for (let i = result.length - 1; i > 0; i--) {
    let j = Math.floor(Math.random() * (i + 1));
    let temp: T = result[i];
    result[i] = result[j];
    result[j] = temp;
  }
  return result;
}

function unique<T>(arr: T[]): T[] {
  return Array.from(new Set(arr));
}

let utilitiesNumbers: number[] = [1, 2, 3, 4, 5, 3, 2];
let utilitiesStrings: string[] = ['a', 'b', 'c', 'b', 'a'];

let firstResult: number | undefined = utilitiesFirst(utilitiesNumbers);
console.info(`${firstResult}`);  // 1

let lastResult: string | undefined = last(utilitiesStrings);
console.info(`${lastResult}`);  // a

let shuffled: number[] = shuffle(utilitiesNumbers);
console.info(`${shuffled.join(', ')}`);  // Randomly shuffle

let uniqueNumbers: number[] = unique(utilitiesNumbers);
console.info(`${uniqueNumbers.join(', ')}`);  // 1, 2, 3, 4, 5

let uniqueStrings: string[] = unique(utilitiesStrings);
console.info(`${uniqueStrings.join(', ')}`);  // a, b, c

interface UtilitiesUser {
  id: number;
  name: string;
  email: string;
}

let utilitiesUser: UtilitiesUser = {
  id: 1,
  name: 'Alice',
  email: 'alice@example.com'
};

// In ArkTS, prefer explicit property access and avoid relying on keyof and indexed access types
function renameUser(target: UtilitiesUser, newName: string): void {
  target.name = newName;
}

console.info(`${utilitiesUser.name}`);  // Alice
renameUser(utilitiesUser, 'Bob');
console.info(`${utilitiesUser.name}`);  // Bob
```

### Component Encapsulation

Generic components describe structures such as props and render through type parameters, allowing the same component to adapt to multiple data types without losing type safety.

<!-- @[generic_ui_components](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
// Generic list component.
interface ListComponentProps<T> {
  items: T[];
  renderItem: (item: T, index: number) => string;
  onItemClick?: (item: T, index: number) => void;
}

class ListComponent<T> {
  private props: ListComponentProps<T>;
  
  constructor(props: ListComponentProps<T>) {
    this.props = props;
  }
  
  render(): string {
    let itemsHtml = this.props.items.map((item, index) =>
      this.props.renderItem(item, index)
    ).join('');
    
    return `<ul>${itemsHtml}</ul>`;
  }
  
  handleClick(index: number): void {
    if (this.props.onItemClick) {
      this.props.onItemClick(this.props.items[index], index);
    }
  }
}

interface ComponentsUser {
  id: number;
  name: string;
  email: string;
}

let componentsUsers: ComponentsUser[] = [
  { id: 1, name: 'Alice', email: 'alice@example.com' },
  { id: 2, name: 'Bob', email: 'bob@example.com' },
  { id: 3, name: 'Charlie', email: 'charlie@example.com' }
];

let userList = new ListComponent<ComponentsUser>({
  items: componentsUsers,
  renderItem: (user) => `<li>${user.name} (${user.email})</li>`,
  onItemClick: (user) => console.info(`Clicked: ${user.name}`)
});

console.info(`${userList.render()}`);

// Generic table component.
interface TableColumn<T> {
  header: string;
  getValue: (row: T) => string;
}

interface TableComponentProps<T> {
  columns: TableColumn<T>[];
  data: T[];
}

class TableComponent<T> {
  private props: TableComponentProps<T>;
  
  constructor(props: TableComponentProps<T>) {
    this.props = props;
  }
  
  render(): string {
    let headerHtml = this.props.columns.map(col =>
      `<th>${col.header}</th>`
    ).join('');
    
    let bodyHtml = this.props.data.map(row => {
      let cells = this.props.columns.map(col => {
        return `<td>${col.getValue(row)}</td>`;
      }).join('');
      return `<tr>${cells}</tr>`;
    }).join('');
    
    return `<table><thead><tr>${headerHtml}</tr></thead><tbody>${bodyHtml}</tbody></table>`;
  }
}

let userTable = new TableComponent<ComponentsUser>({
  columns: [
    { header: 'ID', getValue: (row: ComponentsUser): string => row.id.toString() },
    { header: 'Name', getValue: (row: ComponentsUser): string => row.name },
    { header: 'Email', getValue: (row: ComponentsUser): string => row.email }
  ],
  data: componentsUsers
});

console.info(`${userTable.render()}`);
```

### Encapsulating API Requests

Use generics to encapsulate network requests and uniformly handle the request and response types of different APIs.

<!-- @[generic_api_client](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Generics.ets) -->

``` TypeScript
interface ClientApiResponse<T> {
  data: T;
  status: number;
  message: string;
}

class ApiClient {
  private baseUrl: string;

  constructor(baseUrl: string) {
    this.baseUrl = baseUrl;
  }

  async get<T>(endpoint: string): Promise<ClientApiResponse<T>> {
    let url: string = `${this.baseUrl}${endpoint}`;
    let result: string = await this.mockRequest(url);
    let data: T = JSON.parse(result) as T;
    return { data: data, status: 200, message: 'Success' };
  }

  async post<T, U>(endpoint: string, body: T): Promise<ClientApiResponse<U>> {
    let url: string = `${this.baseUrl}${endpoint}`;
    let result: string = await this.mockRequest(url);
    let data: U = JSON.parse(result) as U;
    return { data: data, status: 200, message: 'Success' };
  }

  private mockRequest(url: string): Promise<string> {
    return new Promise<string>((resolve: (value: string) => void): void => {
      setTimeout(() => {
        resolve(JSON.stringify({ id: 1, name: 'Alice', email: 'alice@example.com' }));
      }, 100);
    });
  }
}

interface ClientUser {
  id: number;
  name: string;
  email: string;
}

interface CreateUserRequest {
  name: string;
  email: string;
}

let gacClient: ApiClient = new ApiClient('EXAMPLE_API_URL');

async function gacFetchUser(id: number): Promise<void> {
  try {
    let response: ClientApiResponse<ClientUser> = await gacClient.get<ClientUser>(`/users/${id}`);
    console.info(`${response.data.name}`); // Alice
  } catch (error) {
    console.error(`Error: ${(error as Error).message}`);
  }
}

async function gacCreateUser(name: string, email: string): Promise<void> {
  try {
    let request: CreateUserRequest = { name: name, email: email };
    let response: ClientApiResponse<ClientUser> = await gacClient.post<CreateUserRequest, ClientUser>('/users', request);
    console.info(`${response.data.id}`); // 1
  } catch (error) {
    console.error(`Error: ${(error as Error).message}`);
  }
}

gacFetchUser(1);
gacCreateUser('Alice', 'alice@example.com');
```