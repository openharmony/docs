# Functions

<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=c25b60c237b212cfc232b5aee67d2c42ba90278a translatedAt=2026-08-13T08:58:09.458Z pushedAt=2026-08-13T13:02:35.825Z -->

ArkTS provides rich function features, including parameters, return values, type definitions, overloads, higher-order functions, and more.

## Declaring and Calling Functions

A function is declared with the `function` keyword and consists of a function name, a parameter list, a return type, and a function body. It is called by using the function name followed by parentheses.

### Basic Syntax of Functions

ArkTS functions are declared with the `function` keyword and support typed parameters and return values, optional/default/rest parameters, function types, overloading, and higher-order functions.

Functions serve four purposes: encapsulating repeated logic to avoid code redundancy, encapsulating complex operations to provide clear interfaces, decomposing large tasks into smaller functions for easier management and testing, and hiding implementation details while exposing only the necessary interfaces. The resulting benefits are improved reusability (write once, call from multiple places), enhanced readability (function names intuitively convey their purpose), easier maintenance (a change in one place takes effect at all call sites), and easier testing (independent functions are simpler to test and debug in isolation).

``` TypeScript
function functionName(parameters: parameterTypes): returnType {
  // Function body.
  return returnValue;
}
```

<!-- @[function_declaration_basic](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
// Basic function declaration.
function add(a: number, b: number): number {
  return a + b;
}

// Call the function.
let result: number = add(1, 2);

// Function with no return value.
function logMessage(message: string): void {
  console.info(`${message}`);
}

logMessage('Hello, ArkTS');

// Simple calculation function.
function multiply(x: number, y: number): number {
  return x * y;
}

let product: number = multiply(5, 3);  // 15

// Complex logic function.
function calculateArea(width: number, height: number): number {
  let area: number = width * height;
  return area;
}

let area: number = calculateArea(10, 20);  // 200
```

ArkTS requires explicit type annotations for function parameters and return values. In contextual type inference scenarios (such as callback function parameters), the compiler can infer parameter types from the function signature, in which case the type annotations of the callback parameters can be omitted. A function whose return type is `void` can omit `return`, or use `return;` to exit early.

### Function and Parameter Naming Conventions

Use camelCase verb phrases for function names (for example, `calculateTotal` and `validateInput`) to describe "what to do" rather than "how to do it". Use descriptive nouns for parameter names, and avoid abbreviations and meaningless names.

<!-- @[function_naming_conventions](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
// Function name: a verb or verb phrase in camelCase.
function calculateTotal() {}
function validateInput() {}
function processData() {}
function fetchUserInfo() {}

// Parameter name: a descriptive noun in camelCase.
function greet(userName: string): string {
  return `Hello, ${userName}`;
}

function calculateDistance(startPoint: Point, endPoint: Point): number {
  return Math.sqrt(
    Math.pow(endPoint.x - startPoint.x, 2) +
    Math.pow(endPoint.y - startPoint.y, 2)
  );
}

interface Point {
  x: number;
  y: number;
}

// Avoid meaningless names.
// Counterexample: function f(a, b) {}
// Recommended: function calculateSum(firstValue: number, secondValue: number) {}
```

Naming is a convention rather than a compilation constraint: `function f(a, b)` compiles successfully but reduces readability. In ArkTS, functions and parameters use camelCase, while types (such as `Point`) use PascalCase.

### How to Call Functions

Functions support direct calls, chained calls, nested calls, and conditional calls. A chained call executes from the inside out, with the return value of a function used as the argument of the outer call. A nested call invokes other functions inside a function, which is suitable for composing complex logic.

<!-- @[function_invocation_methods](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
// Direct call
function sayHello(): void {
  console.info('Hello');
}

sayHello();

// Call with parameters
function invokeGreet(name: string): void {
  console.info(`Hello, ${name}`);
}

invokeGreet('Alice');

// Call with a return value
function invokeAdd(a: number, b: number): number {
  return a + b;
}

let sum: number = invokeAdd(1, 2);

// Chained call.
function double(x: number): number {
  return x * 2;
}

let invokeResult: number = double(double(5));  // 20

// Nested call.
function square(x: number): number {
  return x * x;
}

function sumOfSquares(a: number, b: number): number {
  return square(a) + square(b);
}

let squaresSum: number = sumOfSquares(3, 4);  // 25

// Conditional call.
function invokeProcessData(data: string | null): void {
  if (data !== null) {
    processValidData(data);
  }
}

function processValidData(data: string): void {
  console.info(`${data}`);
}
```

The evaluation order of nested and chained calls is from the inside out: in `double(double(5))`, `double(5)` is evaluated first to obtain 10, and then `double(10)` is evaluated to obtain 20. A chained call requires the return type of the inner function to match the parameter type of the outer function; a type mismatch is reported at compile time. A conditional call decouples "whether to call" from "what to call", and serves as the underlying pattern for the subsequent optional chaining call (`?.()`).

### Handling Function Return Values

A function returns a result through the `return` statement, and the return type is determined by the declaration. Use `void` when there is no return value.

<!-- @[function_return_values](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
// Single return value
function getMax(a: number, b: number): number {
  return a > b ? a : b;
}

let max: number = getMax(10, 20);

// No return value
function logInfo(info: string): void {
  console.info(`${info}`);
  // No return or return;
}

// Early return
function validateAge(age: number): boolean {
  if (age < 0) {
    return false;
  }
  if (age > 150) {
    return false;
  }
  return true;
}

// Multiple return paths
function classifyNumber(value: number): string {
  if (value > 0) {
    return 'positive';
  }
  if (value < 0) {
    return 'negative';
  }
  return 'zero';
}

// Return an object
function createUser(id: number, name: string): User {
  return {
    id: id,
    name: name,
    active: true
  };
}

interface User {
  id: number;
  name: string;
  active: boolean;
}

let user: User = createUser(1, 'Alice');

// Return an array
function createRange(start: number, end: number): number[] {
  let result: number[] = [];
  for (let i: number = start; i <= end; i++) {
    result.push(i);
  }
  return result;
}

let range: number[] = createRange(1, 5);
console.info(`${range.join(', ')}`);  // 1, 2, 3, 4, 5
```

## Function Parameters

Function parameters include formal parameters (the parameter names and types in the declaration) and actual arguments (the values passed in a call). ArkTS supports optional parameters, default parameters, and rest parameters.

### Correspondence Between Formal Parameters and Actual Arguments

Formal parameters are the parameter names in a function declaration, while actual arguments are the values passed in at the call site, matched one-to-one by position.

<!-- @[parameters_formal_and_actual](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
interface FormalPoint {
  x: number;
  y: number;
}

// Formal parameters: parameters defined in the function declaration.
function addNumbers(a: number, b: number): number {
  return a + b;
}

// Actual arguments: values passed in when the function is called.
let paramsResult: number = addNumbers(1, 2);
console.info(`${paramsResult}`); // 3

// The number of parameters must match.
// addNumbers(1);        // Compilation error: missing argument.
// addNumbers(1, 2, 3);  // Compilation error: too many arguments.

// Parameter types must match.
function greetUser(name: string): string {
  return `Hello, ${name}`;
}

let greeting: string = greetUser('Alice');
console.info(`${greeting}`); // Hello, Alice
// greetUser(123);  // Compilation error: type mismatch.

// Parameter order must match.
function createPoint(x: number, y: number): FormalPoint {
  return { x: x, y: y };
}

let fpPoint: FormalPoint = createPoint(10, 20);
console.info(`${fpPoint.x}, ${fpPoint.y}`); // 10, 20
```

### Optional Parameter

An optional parameter is marked with `?`, indicating that it can be omitted when the function is called. At the type level, the type of an optional parameter is `T | undefined`: it is `T` when passed in and `undefined` when omitted. Therefore, before accessing an optional parameter in the function body, you must check `!== undefined`, or use nullish coalescing `??` to provide a default value. Note: An optional parameter must come after required parameters.

<!-- @[optional_parameters](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
// Optional parameter.
function paramsGreet(name: string, title?: string): string {
  if (title !== undefined) {
    return `Hello, ${title} ${name}`;
  }
  return `Hello, ${name}`;
}

paramsGreet('Alice');           // "Hello, Alice"
paramsGreet('Alice', 'Dr.');    // "Hello, Dr. Alice"

// Optional parameters must come after required parameters.
function buildMessage(
  content: string,
  prefix?: string,
  suffix?: string
): string {
  let result: string = content;
  if (prefix !== undefined) {
    result = prefix + result;
  }
  if (suffix !== undefined) {
    result = result + suffix;
  }
  return result;
}

buildMessage('Hello');           // "Hello"
buildMessage('Hello', '[');      // "[Hello"
buildMessage('Hello', '[', ']'); // "[Hello]"

// Check the optional parameter.
function processConfig(config: Config): void {
  if (config.timeout !== undefined) {
    console.info(`Timeout: ${config.timeout}`);
  }
  if (config.retries !== undefined) {
    console.info(`Retry count: ${config.retries}`);
  }
}

interface Config {
  timeout?: number;
  retries?: number;
}
```

### Default Parameter Values

Specify a default value for a parameter. When the parameter is not passed during a call, the default value is used. Default parameters can be mixed with optional parameters.

<!-- @[default_parameters](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
// Default parameter
function paramsGreet2(name: string, greeting: string = 'Hello'): string {
  return `${greeting}, ${name}`;
}

paramsGreet2('Alice');              // "Hello, Alice"
paramsGreet2('Alice', 'Hi');        // "Hi, Alice"

// Default parameters can be mixed with optional parameters
function createMessage(
  content: string,
  prefix: string = '[INFO]',
  suffix?: string
): string {
  let message: string = `${prefix} ${content}`;
  if (suffix !== undefined) {
    message = message + suffix;
  }
  return message;
}

createMessage('Hello');           // "[INFO] Hello"
createMessage('Hello', '[WARN]'); // "[WARN] Hello"
createMessage('Hello', '[WARN]', '!'); // "[WARN] Hello!"

// The default value can be an expression
function createTimer(
  interval: number = 1000,
  callback: () => void = () => {}
): Timer {
  return {
    interval: interval,
    callback: callback,
    start: () => {}
  };
}

interface Timer {
  interval: number;
  callback: () => void;
  start: () => void;
}

// Use other parameters as the default value.
function calculatePrice(
  basePrice: number,
  taxRate: number = 0.1,
  discount: number = basePrice * 0.05
): number {
  return basePrice + basePrice * taxRate - discount;
}

calculatePrice(100);      // 100 + 10 - 5 = 105
calculatePrice(100, 0.2); // 100 + 20 - 5 = 115
```

### Rest Parameters (Variable Parameters)

Use the `...` syntax to collect a variable number of arguments into an array, implementing a function that accepts a variable number of parameters.

<!-- @[rest_parameters](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
// Rest parameters
function restSum(...values: number[]): number {
  let total: number = 0;
  for (let value of values) {
    total += value;
  }
  return total;
}

restSum(1);           // 1
restSum(1, 2);        // 3
restSum(1, 2, 3);     // 6
restSum(1, 2, 3, 4);  // 10

// Combine rest parameters with regular parameters
function greetAll(greeting: string, ...names: string[]): string {
  let result: string = '';
  for (let name of names) {
    result += `${greeting}, ${name}\n`;
  }
  return result;
}

greetAll('Hello', 'Alice', 'Bob', 'Charlie');

// Rest parameters must be the last parameter
function buildArray(first: number, ...rest: number[]): number[] {
  let result: number[] = [first];
  for (let value of rest) {
    result.push(value);
  }
  return result;
}

let single: number[] = buildArray(1);
console.info(`${single.join(', ')}`);  // 1
let multiple: number[] = buildArray(1, 2, 3, 4);
console.info(`${multiple.join(', ')}`);  // 1, 2, 3, 4

// Rest parameter type
function concatenate(...strings: string[]): string {
  return strings.join('');
}

concatenate('a', 'b', 'c');  // "abc"

// Rest parameter used for forwarding
function logAll(...messages: string[]): void {
  for (let message of messages) {
    console.info(`${message}`);
  }
}
```

### Destructuring Parameter Comparison (Tuples and Objects)

TypeScript supports destructuring parameters to extract tuple or object members directly as parameters (for example, `function foo({x, y}: Point)`). ArkTS does not support destructuring parameters. Instead, you need to receive them through an interface type parameter and extract the properties manually.

<!-- @[parameter_destructuring_limitation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
// ArkTS does not support destructuring parameters. Receive them through an interface type parameter and extract the properties manually.

interface PdPoint {
  x: number;
  y: number;
}

function processPoint(point: PdPoint): number {
  let x: number = point.x;
  let y: number = point.y;
  return x + y;
}

let pdPoint: PdPoint = { x: 10, y: 20 };
console.info(`${processPoint(pdPoint)}`); // 30

function processTuple(tuple: [number, string]): string {
  let id: number = tuple[0];
  let name: string = tuple[1];
  return `ID: ${id}, Name: ${name}`;
}

let tuple: [number, string] = [1, 'Alice'];
processTuple(tuple);

// Use an interface instead of destructuring.
interface Options {
  timeout: number;
  retries: number;
  verbose: boolean;
}

function configure(options: Options): void {
  let timeout: number = options.timeout;
  let retries: number = options.retries;
  let verbose: boolean = options.verbose;
  
  console.info(`Timeout: ${timeout}, Retries: ${retries}`);
}

configure({ timeout: 5000, retries: 3, verbose: true });
```

## Return Values of Functions

This section describes different return modes, including void functions, single return values, multiple return values (tuples), and optional return values (T | undefined).

### Functions with No Return Value (void Type)

A void function does not return a value. It is used to perform operations without producing a result.

<!-- @[void_type_functions](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
// Function of the void type.
function log(message: string): void {
  console.info(`${message}`);
}

function notify(message: string): void {
  alert(message);
}

function alert(message: string): void {
  console.info(`Alert: ${message}`);
}

// A void function can return early.
function process(data: string | null): void {
  if (data === null) {
    return;  // Exit early.
  }
  console.info(`${data}`);
}

// A void function can omit the return statement.
function initialize(): void {
  let config: FunctionsConfig = loadConfig();
  setupEnvironment(config);
}

function loadConfig(): FunctionsConfig {
  return { debug: false };
}

function setupEnvironment(config: FunctionsConfig): void {
  console.info('Environment setup');
}

interface FunctionsConfig {
  debug: boolean;
}
```

### Single Return Value Function

A function returns a single value through `return`, and the return type can be a primitive type, an object, or an array.

<!-- @[return_types](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
// Return a primitive type.
function typesAdd(a: number, b: number): number {
  return a + b;
}

function concat(a: string, b: string): string {
  return a + b;
}

function isPositive(value: number): boolean {
  return value > 0;
}

// Return an object.
function createConfig(): TypesConfig {
  return {
    apiUrl: 'EXAMPLE_API_URL',
    timeout: 5000,
    retries: 3
  };
}

interface TypesConfig {
  apiUrl: string;
  timeout: number;
  retries: number;
}

// Return an array.
function getNumbers(): number[] {
  return [1, 2, 3, 4, 5];
}

// Return a class instance.
function typesCreateUser(id: number): TypesUser {
  let user: TypesUser = new TypesUser();
  user.id = id;
  user.name = 'TypesUser';
  return user;
}

class TypesUser {
  public id: number = 0;
  public name: string = '';
}
```

### Functions Returning Multiple Values (Using Tuples)

Return multiple values through an array or tuple type, and the caller obtains each returned item by index.

<!-- @[multiple_return_values](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
// Use an array to carry multiple return values.
function divideWithRemainder(a: number, b: number): number[] {
  let quotient: number = Math.floor(a / b);
  let remainder: number = a % b;
  return [quotient, remainder];
}

let valsResult: number[] = divideWithRemainder(10, 3);
let quotient: number = valsResult[0];  // 3
let remainder: number = valsResult[1]; // 1

// Use a tuple type.
function minMax(arr: number[]): [number, number] {
  let min: number = arr[0];
  let max: number = arr[0];
  
  for (let value of arr) {
    if (value < min) {
      min = value;
    }
    if (value > max) {
      max = value;
    }
  }
  
  return [min, max];
}

let bounds: [number, number] = minMax([1, 5, 3, 9, 2]);
let minVal: number = bounds[0];  // 1
let maxVal: number = bounds[1];  // 9

// Return the result and status.
function tryParseInt(str: string): [number, boolean] {
  let parsed: number = Number.parseInt(str, 10);
  let success: boolean = !Number.isNaN(parsed);
  return [parsed, success];
}

let parsed: [number, boolean] = tryParseInt('42');
let value: number = parsed[0];     // 42
let success: boolean = parsed[1];  // true

// Return the data and error.
function fetchData(id: number): [Data | null, Error | null] {
  if (id <= 0) {
    return [null, new Error('Invalid ID')];
  }
  return [{ id: id, content: 'data' }, null];
}

interface Data {
  id: number;
  content: string;
}

let dataResult: [Data | null, Error | null] = fetchData(1);
let data: Data | null = dataResult[0];
let error: Error | null = dataResult[1];
```

### Optional Return Value Functions (T | undefined Type)

A function whose return type is `T | undefined` indicates that the result may not exist.

<!-- @[optional_return_values](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
interface OrvUser {
  id: number;
  name: string;
  active: boolean;
}

// Return may be undefined.
function findUser(id: number): OrvUser | undefined {
  if (id <= 0) {
    return undefined;
  }
  let users: OrvUser[] = [
    { id: 1, name: 'Alice', active: true },
    { id: 2, name: 'Bob', active: false }
  ];
  
  for (let valsUser of users) {
    if (valsUser.id === id) {
      return valsUser;
    }
  }
  return undefined;
}

let orvUser: OrvUser | undefined = findUser(1);
if (orvUser !== undefined) {
  console.info(`${orvUser.name}`);
} // Alice

// Find function.
function findFirst(arr: number[], predicate: (n: number) => boolean): number | undefined {
  for (let value of arr) {
    if (predicate(value)) {
      return value;
    }
  }
  return undefined;
}

let first: number | undefined = findFirst([1, 2, 3, 4], (n: number): boolean => n > 2);
console.info(`${first}`); // 3

// Obtain element.
function getElement(arr: string[], index: number): string | undefined {
  if (index < 0 || index >= arr.length) {
    return undefined;
  }
  return arr[index];
}

let element: string | undefined = getElement(['a', 'b', 'c'], 1);
console.info(`${element}`); // b

// Return null or a value.
function getConfigValue(key: string): string | null {
  let config: Map<string, string> = new Map<string, string>();
  config.set('apiUrl', 'EXAMPLE_API_URL');
  config.set('timeout', '5000');
  
  let value: string | undefined = config.get(key);
  if (value !== undefined) {
    return value;
  }
  return null;
}
```

## Function Type

Use the `(params) => returnType` form to describe the parameter and return value signature of a function. It can be used as the type of a variable, parameter, and property.

### Defining and Matching Function Types

When assigning a function type, both parameter compatibility and return value compatibility must be satisfied, and parameter types are covariant in the subtype direction.

<!-- @[ts_function_types](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Functions.ts) -->

``` TypeScript
// Define a function type.
type MathOperation = (a: number, b: number) => number;

let add: MathOperation = (a: number, b: number): number => {
  return a + b;
};

let subtract: MathOperation = (a: number, b: number): number => {
  return a - b;
};

let multiply: MathOperation = (a: number, b: number): number => {
  return a * b;
};

// A function type must match the parameters and return value.
type GreetingFunction = (name: string) => string;

let greet: GreetingFunction = (name: string): string => {
  return `Hello, ${name}`;
};

// A mismatched type causes a compilation error.
let invalid: MathOperation = (a: string) => a; // Compilation error.
```

### Function Type as a Parameter

Passing a function as a parameter (callback function) enables flexible logic such as custom comparators, filters, and event handlers.

<!-- @[functions_as_parameters](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
// Function as a parameter
type MathOperation = (a: number, b: number) => number;
function addNumbersOp(a: number, b: number): number {
  return a + b;
}
function subtractNumbers(a: number, b: number): number {
  return a - b;
}
function multiplyNumbersOp(a: number, b: number): number {
  return a * b;
}
function calculate(a: number, b: number, operation: MathOperation): number {
  return operation(a, b);
}

let paramsSum: number = calculate(10, 5, addNumbersOp);       // 15
let diff: number = calculate(10, 5, subtractNumbers); // 5
let prod: number = calculate(10, 5, multiplyNumbersOp); // 50
console.info(`${paramsSum}, ${diff}, ${prod}`); // 15, 5, 50

// Callback function
function paramsProcessData(
  data: string[],
  processor: (item: string) => string
): string[] {
  let result: string[] = [];
  for (let item of data) {
    result.push(processor(item));
  }
  return result;
}

let processed: string[] = paramsProcessData(
  ['hello', 'world'],
  (s: string): string => s.toUpperCase()
);
console.info(`${processed[0]}, ${processed[1]}`); // HELLO, WORLD

// Condition-checking function
function filterNumbers(
  numbers: number[],
  predicate: (n: number) => boolean
): number[] {
  let result: number[] = [];
  for (let num of numbers) {
    if (predicate(num)) {
      result.push(num);
    }
  }
  return result;
}

let evens: number[] = filterNumbers([1, 2, 3, 4, 5, 6], (n: number): boolean => n % 2 === 0);
console.info(`${evens.join(', ')}`); // 2, 4, 6
```

### Function Type as a Return Value

A function can be used as a return value to create closures (which capture outer variables), factory functions (which generate different behaviors based on parameters), and strategy patterns for deferred execution.

<!-- @[functions_returning_functions](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
type RetMathOperation = (a: number, b: number) => number;

// Return a function.
function getOperation(type: string): RetMathOperation {
  switch (type) {
    case 'add':
      return (a: number, b: number): number => a + b;
    case 'subtract':
      return (a: number, b: number): number => a - b;
    case 'multiply':
      return (a: number, b: number): number => a * b;
    default:
      return (a: number, b: number): number => 0;
  }
}

let frfOperation: RetMathOperation = getOperation('add');
let functionsResult: number = frfOperation(5, 3);
console.info(`${functionsResult}`); // 8

// Creator function.
function createMultiplier(factor: number): (n: number) => number {
  return (n: number): number => n * factor;
}

let functionsDouble: (n: number) => number = createMultiplier(2);
let triple: (n: number) => number = createMultiplier(3);

console.info(`${functionsDouble(5)}`); // 10
console.info(`${triple(5)}`); // 15

// Create a comparator.
function createComparator(ascending: boolean): (a: number, b: number) => number {
  if (ascending) {
    return (a: number, b: number): number => a - b;
  }
  return (a: number, b: number): number => b - a;
}

let ascComparator: (a: number, b: number) => number = createComparator(true);
let descComparator: (a: number, b: number) => number = createComparator(false);
```

### Type Alias to Simplify Function Types

Use `type` to create an alias for a complex function type, simplifying signature writing.

<!-- @[function_type_aliases](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
// Use a type alias.
type Callback = (result: string) => void;
type Predicate = (value: number) => boolean;
type Transformer = (input: string) => string;
type Comparator = (a: number, b: number) => number;

// Simplify complex function types.
type EventHandler = (event: Event) => void;

interface Event {
  type: string;
  data: string | number | boolean;
}

function addEventListener(handler: EventHandler): void {
  // Register the event handler.
}

// Use a generic function type.
type Mapper<T, R> = (value: T) => R;
type Filter<T> = (value: T) => boolean;
type Reducer<T, R> = (acc: R, value: T) => R;

function mapArray<T, R>(arr: T[], mapper: Mapper<T, R>): R[] {
  let result: R[] = [];
  for (let item of arr) {
    result.push(mapper(item));
  }
  return result;
}

let doubled: number[] = mapArray([1, 2, 3], (n: number): number => n * 2);
```

## Closures and Arrow Functions

A closure is a combination of a function and its lexical environment. ArkTS does not use local function declarations to construct closures, but local arrow functions can still capture variables and parameters in the outer scope.

### Closure Formation

An inner arrow function captures variables from the outer scope. Even after the outer function returns, the captured variables retain their state.

<!-- @[closure_counter](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
function createCounter(): () => number {
  let count: number = 0;

  let increment: () => number = (): number => {
    count++;
    return count;
  };

  return increment;
}

let counter: () => number = createCounter();
console.info(`${counter()}`);  // 1
console.info(`${counter()}`);  // 2
console.info(`${counter()}`);  // 3
```

In the preceding example, `increment` captures `count` in `createCounter`. Even after `createCounter` returns, `counter` can still read and update this state.

### Capturing Outer Parameters

A closure can capture the parameters of the outer function. The returned function keeps referencing these parameters and processes subsequent calls based on them.

<!-- @[closure_multiplier](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
function multiplierCreateMultiplier(factor: number): (value: number) => number {
  let multiply: (value: number) => number = (value: number): number => {
    return value * factor;
  };

  return multiply;
}

let multiplierDouble: (value: number) => number = multiplierCreateMultiplier(2);
console.info(`${multiplierDouble(5)}`);  // 10
```

Closures are suitable for holding a small amount of configuration or state. If there is more state or a complex lifecycle, prefer using a class to express it.

### Shorthand Rules for Arrow Functions

Arrow functions support expression body shorthand: for a single expression, you can omit `return` and the curly braces, which is commonly used in callbacks.

<!-- @[arrow_function_syntax](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
let arrowAdd: (a: number, b: number) => number = (a: number, b: number): number => {
  return a + b;
};

let subtract: (a: number, b: number) => number = (a: number, b: number): number => a - b;
let doubleValue: (value: number) => number = (value: number): number => value * 2;
let arrowGreet: () => string = (): string => 'Hello';
```

The most common use of arrow functions is as callbacks for array methods, and their concise syntax is especially useful in higher-order function calls.

<!-- @[arrow_function_array_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
let numbers: number[] = [1, 2, 3, 4, 5];
let callbackDoubled: number[] = numbers.map((value: number): number => {
  return value * 2;
});
```

### this in Arrow Functions

Arrow functions do not bind their own `this`; instead, they capture the `this` of the enclosing scope, making them suitable for use as callbacks in class methods.

<!-- @[arrow_function_this_binding](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
class BindingTimer {
  private seconds: number = 0;

  start(): void {
    setInterval((): void => {
      this.seconds++;
      console.info(`${this.seconds.toString()}`);
    }, 1000);
  }
}

function setInterval(callback: () => void, ms: number): void {
  callback();
}
```

A standalone function body should not rely on `this`. When instance state is required, use a class method or pass it as an explicit parameter.

## Local Helper Functions

TypeScript allows declaring local functions inside a function and using `function` expressions. ArkTS restricts both forms: local function declarations are not supported, and function expressions should also be avoided; use arrow functions with an explicit function type instead.

### Local Helper Function

Nested function declarations in TypeScript are not supported in ArkTS. Use an arrow function expression with an explicit function type instead.

**TypeScript Comparison**

<!-- @[ts_nested_function_declaration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Functions.ts) -->

``` TypeScript
function addNum(a: number, b: number): void {
  function logToConsole(message: string): void {
    console.info(`${message}`);
  }

  let result: number = a + b;
  logToConsole('result is ' + result);
}
```

ArkTS does not support the nested function declarations described above. Rewrite the local function as an arrow function expression with an explicit function type:

<!-- @[local_function_expression](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
function expressionAddNum(a: number, b: number): void {
  let logToConsole: (message: string) => void = (message: string): void => {
    console.info(`${message}`);
  };

  let result: number = a + b;
  logToConsole('result is ' + result);
}
```

### Local Helper Logic

A local function encapsulates helper logic and limits its scope to improve cohesion.

<!-- @[multiple_local_functions](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
function functionsProcessData(data: string[]): string {
  let clean: (item: string) => string = (item: string): string => {
    return item.trim();
  };

  let format: (item: string) => string = (item: string): string => {
    return `[${item}]`;
  };

  let cleaned: string[] = data.map(clean);
  let formatted: string[] = cleaned.map(format);
  return formatted.join(', ');
}
```

This approach preserves local readability while complying with ArkTS requirements on the position of function declarations.

## Function Overloads

Function overloading allows the same function name to provide multiple call signatures based on different parameter types or counts, and the compiler automatically matches the corresponding signature according to the arguments passed in. The problem that overloading solves is: when a function needs to perform similar but type-distinct operations on different types, it avoids using `any` and losing type safety. Note: The implementation signature is not visible externally, and callers can only use the declared overload signatures. When parameter types differ but the logic is the same, prefer union types over overloading.

### Declaring Function Overloads

To declare a function overload, write multiple signatures (parameter and return types only) first, and finally cover them with a single implementation signature.

<!-- @[function_overloading](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
// Overload signature.
function overloadGreet(name: string): string;
function overloadGreet(name: string, age: number): string;
function overloadGreet(name: string, age?: number): string {
  if (age !== undefined) {
    return `Hello, ${name} (${age} years old)`;
  }
  return `Hello, ${name}`;
}

overloadGreet('Alice');        // "Hello, Alice"
overloadGreet('Alice', 25);    // "Hello, Alice (25 years old)"

// Overload with different parameter types.
function overloadProcess(value: number): string;
function overloadProcess(value: string): number;
function overloadProcess(value: number | string): number | string {
  if (typeof value === 'number') {
    return `Number: ${value}`;
  }
  return value.length;
}

overloadProcess(42);     // "Number: 42"
overloadProcess('text'); // 4

// Overload with multiple parameters.
function overloadCreatePoint(x: number): OverloadPoint;
function overloadCreatePoint(x: number, y: number): OverloadPoint;
function overloadCreatePoint(x: number, y?: number): OverloadPoint {
  return {
    x: x,
    y: y !== undefined ? y : 0
  };
}

interface OverloadPoint {
  x: number;
  y: number;
}

let point1: OverloadPoint = overloadCreatePoint(10);
console.info(`${JSON.stringify(point1)}`);  // {"x":10,"y":0}
let point2: OverloadPoint = overloadCreatePoint(10, 20);
console.info(`${JSON.stringify(point2)}`);  // {"x":10,"y":20}
```

### Matching Overload Signatures with the Implementation Signature

When multiple signatures declare different call forms of the same function, the implementation signature must be compatible with all overload signatures.

<!-- @[overload_signatures](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
// The implementation signature must be compatible with all overload signatures.
interface NumberValue {
  value: number;
}

interface StringValue {
  value: string;
}

type NumericOrTextValue = NumberValue | StringValue;

function sigGetValue(obj: NumberValue): number;
function sigGetValue(obj: StringValue): string;
function sigGetValue(obj: NumericOrTextValue): number | string {
  return obj.value;
}

// Overload order: declare more specific types first.
function sigConvert(value: string): number;
function sigConvert(value: number): string;
function sigConvert(value: string | number): string | number {
  if (typeof value === 'string') {
    return Number.parseInt(value, 10);
  }
  return value.toString();
}

// Overloading and union types.
function sigFormat(input: string): string;
function sigFormat(input: number): string;
function sigFormat(input: string | number): string {
  if (typeof input === 'string') {
    return input.toUpperCase();
  }
  return input.toFixed(2);
}
```

### Type Constraints of Function Overloads

Overload signatures must be type-compatible with each other. The implementation signature must handle all cases uniformly, and callers can only call according to the declared signatures. Prefer union types over overloads.

<!-- @[overload_type_constraints](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
interface OverloadData {
  id: number;
  type: string;
  name?: string;
}

// Overload signatures must be type-compatible, and the implementation signature handles all cases uniformly.
function getData(id: number): OverloadData;
function getData(name: string): OverloadData;
function getData(idOrName: number | string): OverloadData {
  if (typeof idOrName === 'number') {
    return { id: idOrName, type: 'numeric' };
  }
  return { id: 0, type: 'named', name: idOrName };
}

let otcData1: OverloadData = getData(1);
let otcData2: OverloadData = getData('test');
console.info(`${otcData1.id}, ${otcData2.type}`); // 1, named

// Overloads with different return types.
function parseInput(input: string): number;
function parseInput(input: string, format: string): Date;
function parseInput(input: string, format?: string): number | Date {
  if (format !== undefined) {
    return new Date(input);
  }
  return Number.parseInt(input, 10);
}

let parsedNum: number = parseInput('42');
let parsedDate: Date = parseInput('2024-01-01', 'date');
console.info(`${parsedNum}`); // 42
```

## Higher-Order Functions

A higher-order function is a function that accepts functions as parameters or returns a function. It is commonly used to abstract collection operations such as traversal, filtering, and mapping.

### Definition of Higher-Order Functions

A higher-order function accepts a function as a parameter or returns a function as a result, abstracting collection operations such as traversal, filtering, and mapping into reusable generic logic.

<!-- @[higher_order_functions](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
// Accept a function as a parameter
function applyOperation(
  a: number,
  b: number,
  operation: (x: number, y: number) => number
): number {
  return operation(a, b);
}

applyOperation(5, 3, (x, y) => x + y);  // 8
applyOperation(5, 3, (x, y) => x * y);  // 15

// Return a function
function createGreeter(greeting: string): (name: string) => string {
  return (name: string): string => `${greeting}, ${name}`;
}

let functionsSayHello: (name: string) => string = createGreeter('Hello');
let sayHi: (name: string) => string = createGreeter('Hi');

functionsSayHello('Alice');  // "Hello, Alice"
sayHi('Bob');       // "Hi, Bob"

// Accept and return a function
function compose<T, U, V>(
  f: (x: U) => V,
  g: (x: T) => U
): (x: T) => V {
  return (x: T): V => f(g(x));
}

let functionsDouble2 = (n: number): number => n * 2;
let addOne = (n: number): number => n + 1;

let doubleThenAddOne = compose(addOne, functionsDouble2);
doubleThenAddOne(5);  // 11
```

### Common Higher-Order Functions (map, filter, reduce)

`map` transforms each element to generate a new array, `filter` filters elements by a condition, and `reduce` reduces an array to a single value.

<!-- @[array_higher_order_methods](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
// map: Map each element.
let orderNumbers: number[] = [1, 2, 3, 4, 5];

let orderDoubled: number[] = orderNumbers.map((n: number): number => n * 2);
console.info(`${orderDoubled.join(', ')}`);  // 2, 4, 6, 8, 10

let squared: number[] = orderNumbers.map((n: number): number => n * n);
console.info(`${squared.join(', ')}`);  // 1, 4, 9, 16, 25

let strings: string[] = orderNumbers.map((n: number): string => `Item ${n}`);
console.info(`${strings.join(', ')}`);  // Item 1, Item 2, Item 3, Item 4, Item 5

// filter: Filter elements.
let orderEvens: number[] = orderNumbers.filter((n: number): boolean => n % 2 === 0);
console.info(`${orderEvens.join(', ')}`);  // 2, 4

let greaterThan3: number[] = orderNumbers.filter((n: number): boolean => n > 3);
console.info(`${greaterThan3.join(', ')}`);  // 4, 5

// reduce: Reduce the array.
let orderSum: number = orderNumbers.reduce(
  (acc: number, n: number): number => acc + n,
  0
);
console.info(`${orderSum}`);  // 15

let orderProduct: number = orderNumbers.reduce(
  (acc: number, n: number): number => acc * n,
  1
);
console.info(`${orderProduct}`);  // 120

let orderMax: number = orderNumbers.reduce(
  (acc: number, n: number): number => acc > n ? acc : n,
  orderNumbers[0]
);
console.info(`${orderMax}`);  // 5

// Use in combination.
let orderResult: number[] = orderNumbers
  .filter((n: number): boolean => n % 2 === 0)
  .map((n: number): number => n * 2);
console.info(`${orderResult.join(', ')}`);  // 4, 8
```

### Implementing Custom Higher-Order Functions

Encapsulate common traversal and filtering logic into higher-order functions, and enable flexible extension through callback parameters.

<!-- @[custom_array_methods](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
// Custom map.
function customMap<T, R>(arr: T[], mapper: (item: T) => R): R[] {
  let result: R[] = [];
  for (let item of arr) {
    result.push(mapper(item));
  }
  return result;
}

// Custom filter.
function customFilter<T>(arr: T[], predicate: (item: T) => boolean): T[] {
  let result: T[] = [];
  for (let item of arr) {
    if (predicate(item)) {
      result.push(item);
    }
  }
  return result;
}

// Custom reduce.
function customReduce<T, R>(
  arr: T[],
  reducer: (acc: R, item: T) => R,
  initial: R
): R {
  let accumulator: R = initial;
  for (let item of arr) {
    accumulator = reducer(accumulator, item);
  }
  return accumulator;
}

// Custom forEach.
function customForEach<T>(arr: T[], consumer: (item: T) => void): void {
  for (let item of arr) {
    consumer(item);
  }
}

// Custom find.
function customFind<T>(arr: T[], predicate: (item: T) => boolean): T | undefined {
  for (let item of arr) {
    if (predicate(item)) {
      return item;
    }
  }
  return undefined;
}
```

## Optional Chaining Call of Functions

The optional chaining call (`?.()`) safely invokes a function that may be `undefined`, avoiding runtime errors.

### Optional Call Syntax for Functions (func?.())

func?.() performs the call only when func is not undefined; otherwise, it returns undefined.

<!-- @[ts_optional_chaining_function_call](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Functions.ts) -->

``` TypeScript
// Optionally call the function.
let callback: (() => void) | null = null;

callback?.();  // Not executed (callback is null).

callback = () => console.info(`Called`);
callback?.();  // Executed, outputting "Called".

// Optional method call.
let service: Service | null = null;

service?.processData?.();  // Not executed.

interface Service {
  processData?: () => void;
}

service = { processData: () => console.info(`Processing`) };
service?.processData?.();  // Executed.

// Optional callback call.
function triggerEvent(callback?: () => void): void {
  callback?.();  // Safe call.
}

triggerEvent();  // No callback, so nothing is executed.
triggerEvent(() => console.info(`Event triggered`));  // Execute the callback.

// Optional call on an object method.
let handler: { onClick?: () => void } | null = null;

handler?.onClick?.();  // Nothing is executed.

handler = { onClick: () => console.info(`Clicked`) };
handler?.onClick?.();  // Executed.
```

### When to Use Optional Chaining Calls

Optional chaining calls are used in scenarios where a callback may not be registered or an event handler may not be bound.

<!-- @[ts_optional_chaining_use_cases](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Functions.ts) -->

``` TypeScript
// Event handler
interface EventEmitter {
  emit?: (event: string) => void;
}

let emitter: EventEmitter | null = getEmitter();

function trigger(event: string): void {
  emitter?.emit?.(event);
}

function getEmitter(): EventEmitter | null {
  return null;
}

// Configure the callback
interface Config {
  onSuccess?: (data: string) => void;
  onError?: (error: Error) => void;
}

function processWithCallbacks(config: Config): void {
  let result: string = 'data';
  config.onSuccess?.(result);

  // or error case
  let error: Error = new Error('Failed');
  config.onError?.(error);
}

// Optional chaining call
interface Chain {
  next?: Chain;
  execute?: () => void;
}

let chain: Chain | null = { next: { execute: () => console.info(`Executed`) } };

chain?.next?.execute?.();  // Execute.

// API response handling
interface APIResponseData {
  items?: string[];
}

interface APIResponse {
  data?: APIResponseData;
  callback?: () => void;
}

let response: APIResponse | null = null;

response?.callback?.();  // Not executed.
response?.data?.items?.forEach?.(item => console.info(`${item}`));
```

## Call Signature

A call signature describes an object that is callable (it has properties and can also be called like a function). The syntax uses `:` instead of `=>`.

**TypeScript Comparison**

<!-- @[ts_call_signature](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Functions.ts) -->

``` TypeScript
// TypeScript comparison: in ArkTS, use an interface to separate properties and methods.
type DescribableFunction = {
  description: string;
  (someArg: number): boolean;
};
```

In ArkTS, use an interface to separate properties and methods.

<!-- @[call_signature_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
interface CsDescribableFunction {
  description: string;
  call(someArg: number): boolean;
}

class CsMyFunc implements CsDescribableFunction {
  public description: string = 'default description';

  call(someArg: number): boolean {
    return someArg > 3;
  }
}

function csDoSomething(fn: CsDescribableFunction): void {
  console.info(`${fn.description + ' returned ' + fn.call(6)}`);
}

let csFn: CsMyFunc = new CsMyFunc();
csDoSomething(csFn);  // default description returned true
```

## Construct Signatures

A construct signature describes a function that can be called with `new`. Add the `new` keyword before the call signature.

**TypeScript Comparison**

<!-- @[ts_construct_signature](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Functions.ts) -->

``` TypeScript
// TypeScript construct signature, not supported in ArkTS (arkts-no-ctor-signatures-type)
class SomeObject {
  public value: string;
  constructor(s: string) {
    this.value = s;
  }
}

type SomeConstructor = {
  new (s: string): SomeObject;
};

function createSomeInstance(ctor: SomeConstructor, s: string): SomeObject {
  return new ctor(s);
}

let someObj: SomeObject = createSomeInstance(SomeObject, 'hello');
console.info(`${someObj.value}`); // hello
```

ArkTS does not support constructor function types (`arkts-no-ctor-signatures-funcs`). For details, see [TypeScript to ArkTS Cookbook](typescript-to-arkts-migration-guide.md#constructor-function-types-are-not-supported). Use the factory pattern instead.

<!-- @[construct_signature_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
class CsaPoint {
  public x: number;
  public y: number;

  constructor(x: number, y: number) {
    this.x = x;
    this.y = y;
  }
}

interface CsaPointFactory {
  create(x: number, y: number): CsaPoint;
}

class CsaPointFactoryImpl implements CsaPointFactory {
  create(x: number, y: number): CsaPoint {
    return new CsaPoint(x, y);
  }
}

function createCsaPoint(factory: CsaPointFactory, x: number, y: number): CsaPoint {
  return factory.create(x, y);
}

let csaP: CsaPoint = createCsaPoint(new CsaPointFactoryImpl(), 3, 4);
console.info(`${csaP.x}, ${csaP.y}`); // 3, 4
```

## Optional Parameters in Callbacks

In TypeScript, optional parameters should not be used in callback function types, because an optional parameter implies that the function may be called without that parameter, whereas the caller of a callback usually passes all parameters. A function with fewer parameters can be assigned to a function type with more parameters (parameter contravariance).

<!-- @[callback_no_optional_params](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
// All callback parameters are required.
type CbCallback = (value: string, index: number) => void;

let cbNames: string[] = ['Alice', 'Bob'];
cbNames.forEach((value: string, index: number) => {
  console.info(`${index}: ${value}`);
});

// A callback with fewer parameters can be assigned to a type with more parameters.
type UnaryCallback = (value: string) => void;
let cbSimple: CbCallback = (value: string): void => {
  console.info(`${value}`);
};
```

> **NOTE**
> 
> Do not use optional parameters (`?`) in callback function types. Otherwise, the caller may not pass the parameter, causing the callback to access `undefined` internally.

## Function Type

TypeScript has a global `Function` type that accepts any function. Calling the `Function` type returns `any`, which is unsafe. When you need to accept any function, use `() => void` instead.

<!-- @[function_type_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
// Not recommended: Use the Function type.
let ftFn: Function = (x: number): number => x * 2;
console.info(`${ftFn(10)}`); // 20

// Recommended: Use a specific function type.
let ftSafeFn: (x: number) => number = (x: number): number => x * 2;
console.info(`${ftSafeFn(10)}`); // 20

// Use () => void when you need to accept any function.
function ftRunCallback(cb: () => void): void {
  cb();
}

ftRunCallback((): void => console.info('executed'));
```

## Assignment Compatibility of void Return Type

A function type with a `void` return type has a special rule: a function type whose return value is `void` can accept a function implementation that returns any value. The return value is ignored. This design allows a function that returns a value (for example, `push` returns `number`) to be used in scenarios where a `void` callback is expected.

<!-- @[void_return_compatibility](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
type VcCallback = () => void;

// A function returning number can be assigned to a void return type.
let vcCb: VcCallback = (): number => {
  console.info('side effect');
  return 42;
};

vcCb(); // Print the side effect; the return value 42 is ignored.
```

This rule applies only when the return value type is `void`, not to other return types. It is commonly used in scenarios that do not require a return value, such as event handling and callback registration.