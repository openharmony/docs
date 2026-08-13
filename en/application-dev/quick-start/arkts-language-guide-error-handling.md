# Error Handling

<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=c25b60c237b212cfc232b5aee67d2c42ba90278a translatedAt=2026-08-13T08:58:06.303Z pushedAt=2026-08-13T12:56:46.961Z -->

Error handling is an important part of program development. A sound error handling mechanism improves the robustness and maintainability of a program. ArkTS is based on TypeScript and inherits the error handling mechanism of JavaScript, on top of which it provides more comprehensive type support.

## Basic Concepts of Error Handling

ArkTS catches runtime exceptions through try-catch-finally and actively throws `Error` objects through throw, ensuring that programs can still handle exceptions gracefully.

### Definition and Classification of Errors

An error is an abnormal situation that occurs during program execution. Errors are classified into syntax errors, runtime errors, and logic errors, each requiring a different handling approach.

<!-- @[ts_basic_error_types](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/ErrorHandling.ts) -->

``` TypeScript
// Compile-time type error: number has no toUpperCase method
let num: number = 10;
num.toUpperCase();

// Compile-time name error: the variable is not declared
console.info(`${undefinedVariable}`);

// Runtime range error: actively thrown by business validation
function readAt(values: number[], index: number): number {
  if (index < 0 || index >= values.length) {
    throw new RangeError('Array index out of range');
  }
  return values[index] ?? 0;
}

let readAtValues: number[] = [1, 2, 3];
try {
  readAt(readAtValues, 3);
} catch (error) {
  console.error(`Failed to read: ${(error as Error).message}`);
}
```

### Core Goals of Error Handling

The goal of error handling is to catch exceptions, provide recovery mechanisms, and convey error information, thereby ensuring program robustness and availability. The basic principles are: catch only the exceptions that can be handled (do not catch all exceptions), record error information for traceability, provide a reasonable recovery mechanism or fallback plan, and do not ignore exceptions in the catch block.

<!-- @[divide_with_error_handling](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandling.ets) -->

``` TypeScript
function divide(a: number, b: number): number {
  if (b === 0) {
    throw new Error('The divisor cannot be zero');
  }
  return a / b;
}

try {
  let result: number = divide(10, 0);
  console.info(`${result}`);
} catch (error) {
  console.error(`Calculation failed: ${(error as Error).message}`);
  // Provide a default value to implement fault tolerance.
  let fallbackResult: number = 0;
  console.info(`Using default value: ${fallbackResult}`);
}
```

### Common Approaches to Error Handling in TypeScript

Common approaches to error handling in TypeScript include try-catch, returning error information, and asynchronous error handling.

<!-- @[error_handling_patterns](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandlingPatterns.ets) -->

``` TypeScript
// Approach 1: Catch exceptions with try-catch
function tryCatchExample(): void {
  try {
    // Code that may throw an error
    let data: Object = JSON.parse('invalid json');
  } catch (error) {
    console.error(`Parsing failed: ${(error as Error).message}`);
  }
}

// Option 2: Return error information (functional style).
function parseJSON(jsonStr: string): [Object | null, Error | null] {
  try {
    let data: Object = JSON.parse(jsonStr) as Object;
    return [data, null];
  } catch (error) {
    return [null, error as Error];
  }
}

// Option 3: Asynchronous error handling.
async function asyncErrorHandling(): Promise<void> {
  try {
    let response = await http.createHttp().request('EXAMPLE_API_URL');
    let data = response.result;
  } catch (error) {
    console.error(`Request failed: ${(error as Error).message}`);
  }
}
```

## Creating and Using Error Objects

Create an error object through `new Error(message)`. The object can carry properties such as `name`, `message`, and `stack`. In the `catch` block, use `instanceof` to distinguish error types and read the details.

### Using the Native Error Class

JavaScript provides the native `Error` class as the base class of all error objects. It is the fundamental type for error handling and provides a standard error information structure.

<!-- @[error_object_properties](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandling.ets) -->

``` TypeScript
// Create a basic error object.
let error1: Error = new Error('This is an error');
let error2: Error = new Error(); // Optional error message.

// Properties of the Error object.
console.info(`${error1.name}`);      // 'Error'
console.info(`${error1.message}`);   // 'This is an error'
console.info(`${error1.stack ?? 'No stack information'}` information'}`);     // Error stack information.

// Throw an error.
function validateAge(age: number): void {
  if (age < 0 || age > 150) {
    throw new Error('Age must be between 0 and 150');
  }
}

try {
  validateAge(-5);
} catch (error) {
  console.error((error as Error).message);
}
```

### Native Error Types

JavaScript provides multiple native error types, each corresponding to a specific error scenario, which facilitates precise identification and handling of errors.

<!-- @[built_in_error_types](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandling.ets) -->

``` TypeScript
// TypeError: Type error
function typeErrorExample(): void {
  let num: number = 10;
  throw new TypeError('Expected a string, but got a number');
}

// RangeError: Range error
function rangeErrorExample(): void {
  throw new RangeError('Array index out of range');
}

// ReferenceError: reference error
function referenceErrorExample(): void {
  throw new ReferenceError('Variable is not defined');
}

// SyntaxError: syntax error
function syntaxErrorExample(): void {
  throw new SyntaxError('JSON string format is incorrect');
}

// URIError: URI error
function uriErrorExample(): void {
  throw new URIError('URI encoding error');
}
```

### Custom Error Classes

By inheriting from the `Error` class, you can create custom error classes that carry business information and context for fine-grained management.

<!-- @[custom_error_classes](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandling.ets) -->

``` TypeScript
// Custom business error class
class UserBusinessError extends Error {
  public code: number;
  public timestamp: Date;
  
  constructor(code: number, message: string) {
    super(message);
    this.name = 'BusinessError';
    this.code = code;
    this.timestamp = new Date();
  }
  
  public toString(): string {
    return `${this.name} [${this.code}]: ${this.message} at ${this.timestamp.toISOString()}`;
  }
}

// Custom validation error class
class UserValidationError extends Error {
  public field: string;
  public value: string | number | boolean;
  
  constructor(field: string, value: string | number | boolean, message: string) {
    super(message);
    this.name = 'ValidationError';
    this.field = field;
    this.value = value;
  }
}

// Use a custom error
function validateUser(username: string, age: number): void {
  if (username.length < 3) {
    throw new UserValidationError('username', username, 'Username must be at least 3 characters long');
  }
  
  if (age < 18) {
    throw new UserBusinessError(1001, 'User must be at least 18 years old');
  }
}

try {
  validateUser('ab', 16);
} catch (error) {
  if (error instanceof UserValidationError) {
    console.error(`Field validation failed: ${error.field}, value: ${error.value}, reason: ${error.message}`);
  } else if (error instanceof UserBusinessError) {
    console.error(`Business error: ${error.code}, ${error.message}`);
  }
}
```

### Concepts and Mechanisms of Error Propagation

Error propagation refers to the process in which an error object, after being created and thrown at the current location, is passed upward along the call stack until it is caught by the nearest try-catch block; if it is never caught, the program terminates.

### Encapsulating Error Information

A custom error class inherits from Error and extends it with fields such as code, details, context, and timestamp, encapsulating the error code, context, stack, and other information together. It also provides methods such as toErrorInfo to output a structured error object, facilitating unified handling and logging at the upper layer.

<!-- @[detailed_error_class](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandling.ets) -->

``` TypeScript
interface ErrorInfo {
  code: number;           // Error code
  message: string;         // Error description
  details?: string;        // Details
  stack?: string;          // Stack information.
  timestamp: Date;         // Time when the error occurred.
  context?: Map<string, string>; // Error context.
}

class DetailedError extends Error {
  public code: number;
  public details: string;
  public context: Map<string, string>;
  public timestamp: Date;
  
  constructor(
    code: number,
    message: string,
    details: string = '',
    context: Map<string, string> = new Map<string, string>()
  ) {
    super(message);
    this.name = 'DetailedError';
    this.code = code;
    this.details = details;
    this.context = context;
    this.timestamp = new Date();
  }
  
  public toErrorInfo(): ErrorInfo {
    return {
      code: this.code,
      message: this.message,
      details: this.details,
      stack: this.stack,
      timestamp: this.timestamp,
      context: this.context
    };
  }
}

// Usage example.
function processData(data: string): void {
  if (data.length === 0) {
    let context: Map<string, string> = new Map<string, string>();
    context.set('functionName', 'processData');
    context.set('inputParam', 'data');
    throw new DetailedError(
      1002,
      'Data is empty',
      'The processData function requires non-empty input data.',
      context
    );
  }
}

try {
  processData('');
} catch (error) {
  if (error instanceof DetailedError) {
    let errorInfo: ErrorInfo = error.toErrorInfo();
    console.error(`Error code: ${errorInfo.code}`);
    console.error(`Error message: ${errorInfo.message}`);
    console.error(`Details: ${errorInfo.details ?? ''}`);
    console.error(`Context: ${errorInfo.context ? errorInfo.context.size : 0} item(s)`);
  }
}
```

## try-catch-finally Exception Catching

The try block wraps code that may throw an exception, the catch block catches and handles the exception, and the finally block executes regardless of whether an exception occurs, and is commonly used for resource cleanup.

### Basic Syntax Structure

The try-catch-finally statement consists of three blocks: the `try` block wraps the code that may throw an exception, the `catch` block catches and handles the exception, and the `finally` block executes regardless of whether an exception occurs (commonly used for resource cleanup). At least one of `catch` and `finally` must be present.

<!-- @[try_catch_finally_syntax](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandling.ets) -->

``` TypeScript
try {
  // Code that may throw an exception.
} catch (error) {
  // Exception handling code.
} finally {
  // Code that executes regardless of whether an exception occurs (optional).
}
```

<!-- @[try_catch_finally_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandling.ets) -->

``` TypeScript
function divideNumbers(a: number, b: number): number {
  if (b === 0) {
    throw new Error('Divisor cannot be zero.');
  }
  return a / b;
}

// Complete try-catch-finally structure.
function calculateExample(): void {
  console.info('Start calculation.');
  
  try {
    let result: number = divideNumbers(10, 0);
    console.info(`Calculation result: ${result}`);
  } catch (error) {
    console.error(`Error caught: ${(error as Error).message}`);
  } finally {
    console.info('Calculation finished (executed regardless of success or failure)');
  }
}

calculateExample();
// Output:
// Calculation started
// Error caught: divisor cannot be zero
// Calculation finished (executed regardless of success or failure)
```

### Catching Specific Error Types

Use `instanceof` in the `catch` block to determine the error type, and perform different handling logic such as retry and logging for `NetworkError`, `DatabaseError`, and other error types respectively.

<!-- @[error_type_discrimination](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandling.ets) -->

``` TypeScript
class NetworkError extends Error {
  constructor(message: string) {
    super(message);
    this.name = 'NetworkError';
  }
}

class DatabaseError extends Error {
  constructor(message: string) {
    super(message);
    this.name = 'DatabaseError';
  }
}

function fetchData(source: string): string {
  if (source === 'network') {
    throw new NetworkError('Network connection failed');
  } else if (source === 'database') {
    throw new DatabaseError('Database query failed');
  } else {
    throw new Error('Unknown error');
  }
}

function handleFetchData(source: string): void {
  try {
    let data = fetchData(source);
    console.info(`Data fetched successfully: ${data}`);
  } catch (error) {
    // Use instanceof to determine the error type.
    if (error instanceof NetworkError) {
      console.error(`Network error: ${error.message}`);
      // Execute the network error handling logic.
      retryNetworkRequest();
    } else if (error instanceof DatabaseError) {
      console.error(`Database error: ${error.message}`);
      // Execute database error handling logic.
      logDatabaseError(error);
    } else {
      console.error(`Unknown error: ${(error as Error).message}`);
    }
  }
}

function retryNetworkRequest(): void {
  console.info('Retrying network request...');
}

function logDatabaseError(error: DatabaseError): void {
  console.info(`Logging database error: ${error.message}`);
}

handleFetchData('network');  // Network error: network connection failed
handleFetchData('database'); // Database error: Database query failed
handleFetchData('other');    // Unknown error: Unknown error
```

### Execution Characteristics of the finally Block

The finally block always executes regardless of whether the try block throws an exception or whether the catch block catches it. It is commonly used for cleanup tasks such as releasing resources and closing connections. Even if a return statement is used in the try block, the finally block still runs before the function returns.

<!-- @[resource_cleanup_finally](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandling.ets) -->

``` TypeScript
class DemoResource {
  public name: string;
  
  constructor(name: string) {
    this.name = name;
    console.info(`${name} resource created`);
  }
  
  public use(): void {
    console.info(`${this.name} resource in use`);
    throw new Error('An error occurred while using the resource');
  }
  
  public cleanup(): void {
    console.info(`${this.name} resource cleaned up`);
  }
}

function useResource(): void {
  let resource: DemoResource | null = null;
  
  try {
    resource = new DemoResource('Database connection');
    resource.use();
  } catch (error) {
    console.error('Error caught:', (error as Error).message);
  } finally {
    // Ensure the resource is cleaned up
    if (resource) {
      resource.cleanup();
    }
  }
}

useResource();
// Output:
// Database connection resource created
// Database connection resource in use
// Error caught: an error occurred while using the resource
// Database connection resource cleaned up
```

In addition to resource cleanup, the finally block has another noteworthy feature: even if a return statement is used in the try block, the finally block still executes before the function returns.

<!-- @[finally_with_return](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandling.ets) -->

``` TypeScript
function testFinally(): string {
  try {
    console.info('try block');
    return 'return from try';
  } catch (error) {
    console.info('catch block');
    return 'return from catch';
  } finally {
    console.info('finally block');
    // Do not use return in the finally block, as it overrides the return value of try/catch.
  }
}

let result: string = testFinally();
console.info(`Return value: ${result}`);
// Output:
// try block
// finally block
// Return value: return from try
```

### When to Use Nested try-catch

Nested try-catch is an error handling approach that uses try-catch inside a try-catch block to handle errors at different levels in a layered manner.

<!-- @[ts_nested_try_catch](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/ErrorHandling.ts) -->

``` TypeScript
function nestedErrorHandling(): void {
  try {
    console.info(`Outer try`);

    try {
      console.info(`Inner try`);
      throw new Error('Inner error');
    } catch (innerError) {
      console.info(`Inner catch: ${(innerError as Error).message}`);
      // Decide whether to throw the error to the upper layer.
      throw innerError; // Pass the error to the outer layer.
    }

    console.info(`Outer try continues`);
  } catch (outerError) {
    console.info(`Outer catch: ${(outerError as Error).message}`);
  }
}

nestedErrorHandling();
// Output:
// Outer try
// Inner try
// Inner catch: inner error
// Outer try continues
```

## Throwing Errors (throw Statement)

The throw statement throws an Error object, interrupts the execution of the current function, and transfers control to the nearest try-catch block in the call stack.

### Throwing Native Error Instances

Use the `throw` keyword to throw an `Error` object or an instance of its subclass, which interrupts the execution of the current function and transfers control to the nearest `catch` block in the call stack. ArkTS should throw objects of the `Error` hierarchy, and avoid throwing non-Error values such as strings or numbers.

<!-- @[email_validation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandling.ets) -->

``` TypeScript
function validateEmail(email: string): void {
  let emailRegex: RegExp = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
  
  if (!email) {
    throw new Error('Email address cannot be empty');
  }
  
  if (!emailRegex.test(email)) {
    throw new Error(`Invalid email address: ${email}`);
  }
}

try {
  validateEmail('invalid-email');
} catch (error) {
  console.error(`Validation failed: ${(error as Error).message}`);
}
```

### Throwing Custom Error Instances

Create a custom error class (such as AppError) by inheriting from Error, and extend business fields such as code and field so that the catch block can distinguish errors by business semantics.

<!-- @[custom_error_with_code](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandling.ets) -->

``` TypeScript
class AppError extends Error {
  public code: number;
  
  constructor(code: number, message: string) {
    super(message);
    this.name = 'AppError';
    this.code = code;
  }
}

function withdrawMoney(balance: number, amount: number): number {
  if (amount <= 0) {
    throw new AppError(1001, 'Withdrawal amount must be greater than zero');
  }
  
  if (amount > balance) {
    throw new AppError(1002, 'Insufficient balance');
  }
  
  return balance - amount;
}

try {
  let newBalance: number = withdrawMoney(100, 200);
  console.info(`Withdrawal successful, balance: ${newBalance}`);
} catch (error) {
  if (error instanceof AppError) {
    console.error(`Error code: ${error.code}, error message: ${error.message}`);
    // Execute different logic based on the error code.
    if (error.code === 1002) {
      console.info('Suggestion: Deposit money or apply for a loan first.');
    }
  }
}
```

### Restrictions on Throwing Non-Error Values

TypeScript allows throwing values of any type, but in ArkTS you should throw objects of the `Error` hierarchy to prevent callers from being unable to reliably read error information and the stack.

**TypeScript comparison**

<!-- @[ts_throw_non_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/ErrorHandling.ts) -->

``` TypeScript
// TypeScript allows throwing any type, while ArkTS can only throw Error
throw 'Something went wrong';
```

**TypeScript comparison**

<!-- @[ts_throw_best_practices](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/ErrorHandling.ts) -->

``` TypeScript
// TypeScript comparison; do not write this in ArkTS:
function badExample1(): void {
  throw 'This is a string error';
}

function badExample2(): void {
  throw 404;
}

function badExample3(): void {
  throw { code: 1001, message: 'Custom error object' };
}

// Correct approach: always throw an Error instance
function goodExample(): void {
  throw new Error('This is a standard error');
}

try {
  goodExample();
} catch (error) {
  if (error instanceof Error) {
    console.error(`Error object: ${error.message}`);
  } else {
    console.error('Unknown type error');
  }
}
```

### Declaring and Hinting Errors Thrown in Functions

Use the JSDoc `@throws` tag to annotate the error types that a function may throw.

<!-- @[function_throws_documentation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandling.ets) -->

``` TypeScript
/**
 * Division operation.
 * @param a Dividend.
 * @param b Divisor.
 * @returns Quotient.
 * @throws {Error} Throws an error when the divisor is zero.*/
function documentationDivide(a: number, b: number): number {
  if (b === 0) {
    throw new Error('The divisor cannot be zero.');
  }
  return a / b;
}

/**
 * Parse a JSON string.
 * @param jsonStr JSON string.
 * @returns Parsed object.
 * @throws {SyntaxError} Throws an error when the JSON format is invalid.*/
function documentationParseJSON(jsonStr: string): Object {
  try {
    return JSON.parse(jsonStr) as Object;
  } catch (error) {
    throw new SyntaxError('Incorrect JSON string format');
  }
}
```

## Error Declaration and Handling Conventions for Functions

Function error declaration conventions specify how exceptions are handled and clarify the error propagation path, enabling callers to understand the errors a function may produce and write handling logic accordingly. Common conventions include: using JSDoc `@throws` to annotate the error types that may be thrown, returning a `Result<T>` object (containing `data` and `error` fields) instead of throwing exceptions, and using error codes to distinguish different error scenarios.

### Returning Error Information in Function Return Values

Use an explicit result object to return data and errors instead of exception handling. This provides a structured way to return error information and data.

<!-- @[result_type_pattern](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandling.ets) -->

``` TypeScript
interface Result<T> {
  data: T | null;
  error: Error | null;
}

// Return data and errors from a function
function parseJSONSafe(jsonStr: string): Result<Object> {
  try {
    let data: Object = JSON.parse(jsonStr) as Object;
    return {
      data: data,
      error: null
    };
  } catch (error) {
    return {
      data: null,
      error: error as Error
    };
  }
}

let parseResult: Result<Object> = parseJSONSafe('{"name": "Alice"}');

if (parseResult.error !== null) {
    console.error('Parsing failed:', parseResult.error.message);
} else {
    console.info(`Parsing succeeded: ${parseResult.data}`);
}

// Another example.
function patternDivideNumbers(a: number, b: number): Result<number> {
  if (b === 0) {
    return {
      data: null,
      error: new Error('The divisor cannot be zero.')
    };
  }
  return {
    data: a / b,
    error: null
  };
}

let divideResult: Result<number> = patternDivideNumbers(10, 2);
if (divideResult.error !== null) {
    console.error('Calculation failed:', divideResult.error.message);
} else {
    console.info(`Calculation result: ${divideResult.data}`);
}
```

### Combining Optional Chaining and Nullish Coalescing to Handle Potential Errors

Use optional chaining `?.` to safely access deep properties that may be `null` or `undefined`, avoiding runtime errors. Use nullish coalescing `??` to provide a default value when the chain result is nullish. Combining the two allows you to gracefully handle missing data without writing try-catch.

<!-- @[optional_chaining_nullish_coalescing](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandling.ets) -->

``` TypeScript
interface ErrorHandlingUserProfile {
  avatar?: string;
  bio?: string;
}

interface ErrorHandlingUser {
  id: number;
  name: string;
  email?: string;
  profile?: ErrorHandlingUserProfile;
}

function getUserEmail(user: ErrorHandlingUser | null): string {
  // Use optional chaining and nullish coalescing.
  return user?.email ?? 'No email set';
}

function getAvatar(user: ErrorHandlingUser | null): string {
  return user?.profile?.avatar ?? 'default-avatar.png';
}

// Example
let errorUser1: ErrorHandlingUser = { id: 1, name: 'Alice' };
let errorUser2: ErrorHandlingUser = { id: 2, name: 'Bob', email: 'bob@example.com' };
let errorUser3: ErrorHandlingUser = {
  id: 3,
  name: 'Charlie',
  profile: { avatar: 'charlie.png', bio: 'Developer' }
};

console.info(`${getUserEmail(errorUser1)}`); // 'No email set'
console.info(`${getUserEmail(errorUser2)}`); // 'bob@example.com'
console.info(`${getAvatar(errorUser1)}`);    // 'default-avatar.png'
console.info(`${getAvatar(errorUser3)}`);    // 'charlie.png'
```

### Error Handling in Async Functions

Error handling in async functions can be implemented using async/await combined with try-catch or Promise.catch().

<!-- @[async_await_error_handling](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandling.ets) -->

``` TypeScript
async function fetchUserData(userId: number): Promise<string> {
  try {
    if (userId <= 0) {
      throw new Error(`Invalid user ID: ${userId}`);
    }
    return `Data of user ${userId}`;
  } catch (error) {
    console.error(`Failed to obtain user data: ${(error as Error).message}`);
    throw new Error((error as Error).message);
  }
}

async function aehMain(): Promise<void> {
  try {
    let user: string = await fetchUserData(1);
    console.info(`User information: ${user}`);
  } catch (error) {
    console.error(`Main process error: ${(error as Error).message}`);
  }
}

aehMain();
```

## Error Handling in Asynchronous Code

In an async function, wrap the await expression in try-catch to catch a Promise rejection.

### Catching Async Errors with async/await and try-catch

Combining async/await with try-catch is the standard way to handle asynchronous errors, providing a clear flow for asynchronous error handling.

<!-- @[promise_try_catch](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandling.ets) -->

``` TypeScript
async function asyncOperation(): Promise<string> {
  // Simulate an asynchronous operation
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      let success = Math.random() > 0.5;
      if (success) {
        resolve('Operation succeeded');
      } else {
        reject(new Error('Operation failed'));
      }
    }, 1000);
  });
}

// Use try-catch to catch asynchronous errors.
async function handleAsyncOperation(): Promise<void> {
  try {
    let result = await asyncOperation();
    console.info(`Result: ${result}`);
    } catch (error) {
    console.error('Caught asynchronous error:', (error as Error).message);
  }
}

handleAsyncOperation();
```

### Chained Error Catching with Promise.catch()

The `Promise.catch()` method is a way to catch Promise errors in a chain, providing an error handling mechanism for Promise chains.

<!-- @[promise_catch_finally_chain](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandling.ets) -->

``` TypeScript
// Use Promise.catch() to catch errors.
function promiseErrorOperation(): Promise<string> {
  return Promise.resolve('success');
}

function promiseCatchExample(): void {
  promiseErrorOperation()
    .then((result: string): string => {
      console.info(`Success: ${result}`);
      return result.toUpperCase();
    })
    .then((upperResult: string): void => {
      console.info(`After conversion: ${upperResult}`);
    })
    .catch((error: Error): void => {
      console.error(`Caught error: ${error.message}`);
    })
    .finally((): void => {
      console.info('Operation ended');
    });
}

promiseCatchExample();
```

### Error Handling for Multiple Asynchronous Operations

In `Promise.all`, if any task fails, the whole operation enters `catch`. You can handle each task independently with its own `catch`.

<!-- @[promise_all_error_handling](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/PromiseAllErrorHandling.ets) -->

``` TypeScript
import http from '@ohos.net.http';

async function parallelErrorHandling(): Promise<void> {
  try {
    // Execute multiple asynchronous operations in parallel.
    let results = await Promise.all([
      http.createHttp().request('EXAMPLE_API_URL/users'),
      http.createHttp().request('EXAMPLE_API_URL/posts'),
      http.createHttp().request('EXAMPLE_API_URL/comments')
    ]);
    
    let usersRes = results[0];
    let postsRes = results[1];
    let commentsRes = results[2];
    console.info(`All requests succeeded: ${usersRes.responseCode}, ${postsRes.responseCode}, ${commentsRes.responseCode}`);
  } catch (error) {
    console.error(`At least one request failed: ${(error as Error).message}`);
  }
}

// Use Promise.allSettled to obtain all results (whether successful or failed).
async function allSettledExample(): Promise<void> {
  let results = await Promise.allSettled([
    Promise.resolve('Success 1'),
    Promise.reject(new Error('Failure 1')),
    Promise.resolve('Success 2')
  ]);
  
  results.forEach((result, index) => {
    if (result.status === 'fulfilled') {
      console.info(`The ${index + 1}th success: ${result.value}`);
    } else {
      console.error(`The ${index + 1}th failed:`, result.reason);
    }
  });
}

allSettledExample();
// Output:
// The 1st succeeded: Success 1
// The 2nd failed: Failure 1
// The 3rd succeeded: Success 2
```

Unlike parallel execution, in serial asynchronous operations each step depends on the result of the previous step, so error handling needs to record the completed steps for troubleshooting and recovery.

<!-- @[serial_async_error_handling](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandling.ets) -->

``` TypeScript
function serialAsyncOperation(stepName: string): Promise<string> {
  return Promise.resolve(`${stepName} completed`);
}

async function serialErrorHandling(): Promise<void> {
  let stepResults: string[] = [];
  
  try {
    // First step
    let step1: string = await serialAsyncOperation('First step');
    stepResults.push(step1);
    
    // Second step (depends on the first step)
    let step2: string = await serialAsyncOperation('Step 2');
    stepResults.push(step2);
    
    // Step 3 (depends on Step 2)
    let step3: string = await serialAsyncOperation('Step 3');
    stepResults.push(step3);
    
    console.info(`All steps succeeded: ${stepResults.join(', ')}`);
  } catch (error) {
    console.error(`Step execution failed: ${(error as Error).message}`);
    console.info(`Completed steps: ${stepResults.join(', ')}`);
  }
}

serialErrorHandling();
```

### Listening for Global Asynchronous Errors

Capture unhandled promise rejections through the `unhandledRejection` event.

<!-- @[unhandled_rejection_handler](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/UnhandledRejectionHandler.ets) -->

``` TypeScript
import errorManager from '@ohos.app.ability.errorManager';

// Listen for unhandled promise rejections.
errorManager.on('unhandledRejection', (reason: Error, promise: Promise<Object>) => {
  console.error(`Unhandled promise rejection: ${reason.message}`);
});

// Example: Trigger global error handling.
async function triggerUnhandledRejection(): Promise<void> {
  // This error is not handled by try-catch or .catch().
  await Promise.reject(new Error('Uncaught Promise error'));
}

triggerUnhandledRejection(); // A runtime error occurs, triggering the global error listener.
```

## Error Recovery and Fallback Strategies

After catching an error, return a default value or execute fallback logic to ensure that the caller obtains a valid result.

### Returning Default Values After Catching Errors

Return a default value in the catch block to ensure that the function always returns a valid result.

<!-- @[fallback_default_values](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandling.ets) -->

``` TypeScript
interface FallbackData {
  name: string;
}

function safeParseJSON(jsonStr: string, defaultValue: FallbackData | null = null): FallbackData | null {
  try {
    let parsed: Object = JSON.parse(jsonStr);
    return parsed as FallbackData;
  } catch (error) {
    console.info(`JSON parsing failed, using default value: ${(error as Error).message}`);
    return defaultValue;
  }
}

let fbData1: FallbackData | null = safeParseJSON('{"name": "Alice"}', { name: 'Unknown' });
console.info(`${JSON.stringify(fbData1)}`);  // {"name":"Alice"}

let fbData2: FallbackData | null = safeParseJSON('invalid json', { name: 'Unknown' });
console.info(`${JSON.stringify(fbData2)}`);  // {"name":"Unknown"}

function safeArrayAccess<T>(arr: T[], index: number, defaultValue: T): T {
  try {
    if (index >= 0 && index < arr.length) {
      return arr[index];
    }
    throw new Error('Index out of range');
  } catch (error) {
    console.info(`Array access failed, using default value: ${(error as Error).message}`);
    return defaultValue;
  }
}

let fbNumbers: number[] = [1, 2, 3];
console.info(`${safeArrayAccess(fbNumbers, 5, 0)}`); // 0 (index out of range)
```

### Implementing the Error Retry Mechanism

Encapsulate retry logic for asynchronous operations that may fail intermittently: execute the operation in a loop, and on failure wait for a fixed interval or use exponential backoff before retrying. If the maximum number of attempts is reached and the operation still fails, throw the accumulated error to improve the robustness of the call.

<!-- @[retry_with_backoff](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandling.ets) -->

``` TypeScript
interface RetryExampleOptions {
  maxRetries: number;      // Maximum number of retries.
  delay: number;           // Retry interval (in milliseconds).
  backoff?: boolean;       // Whether to use exponential backoff.
}

async function retryExampleAsyncOperation<T>(
  operation: () => Promise<T>,
  options: RetryExampleOptions
): Promise<T> {
  let lastError: Error | null = null;
  
  for (let attempt = 0; attempt <= options.maxRetries; attempt++) {
    try {
      let result = await operation();
      console.info(`Operation succeeded (attempt ${attempt + 1})`);
      return result;
    } catch (error) {
      lastError = error as Error;
      console.info(`Attempt ${attempt + 1} failed: ${lastError.message}`);
      
      if (attempt < options.maxRetries) {
        // Calculate the wait time.
        let waitTime = options.delay;
        if (options.backoff) {
          waitTime = options.delay * Math.pow(2, attempt);
        }
        
        console.info(`Waiting ${waitTime}ms before retrying...`);
        await new Promise<void>((resolve: () => void) => setTimeout(resolve, waitTime));
      }
    }
  }
  
  throw new Error(`Retry failed after ${options.maxRetries} attempts: ${lastError ? lastError.message : 'unknown error'}` error'}`);
}

// Usage example
let retryAttemptCount: number = 0;

async function retryExampleUnstableOperation(): Promise<string> {
  retryAttemptCount++;
  if (retryAttemptCount < 2) {
    throw new Error('Operation failed');
  }
  return 'Operation succeeded';
}

async function testRetry(): Promise<void> {
  try {
    let result: string = await retryExampleAsyncOperation<string>(
      retryExampleUnstableOperation,
      { maxRetries: 3, delay: 10, backoff: true }
    );
    console.info(`Final result: ${result}`);
  } catch (error) {
    console.error(`All retries failed: ${(error as Error).message}`);
  }
}

testRetry();
```

### Degradation Handling

When an exception occurs, execute degradation logic to ensure that the basic functions of the system continue to run normally.

<!-- @[service_fallback_pattern](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandling.ets) -->

``` TypeScript
interface FallbackDataService {
  getData(): Promise<string>;
}

class PrimaryDataService implements FallbackDataService {
  async getData(): Promise<string> {
        // Simulate a possible failure of the primary service.
    throw new Error('Primary service unavailable');
  }
}

class SecondaryDataService implements FallbackDataService {
  async getData(): Promise<string> {
    return 'Backup service data';
  }
}

class ResilientDataFetcher {
  private primaryService: FallbackDataService;
  private fallbackService: FallbackDataService;
  
  constructor() {
    this.primaryService = new PrimaryDataService();
    this.fallbackService = new SecondaryDataService();
  }
  
  async fetchData(): Promise<string> {
    try {
      // Try to use the primary service.
      return await this.primaryService.getData();
    } catch (error) {
      console.info(`Primary service failed, switching to fallback service: ${(error as Error).message}`);
      
      try {
        // Use the fallback service.
        return await this.fallbackService.getData();
      } catch (fallbackError) {
        console.error(`Fallback service also failed: ${(fallbackError as Error).message}`);
        // Return the default data.
        return 'Default data';
      }
    }
  }
}

// Usage example
async function runDataFetcherExample(): Promise<void> {
  let fetcher: ResilientDataFetcher = new ResilientDataFetcher();
  let data = await fetcher.fetchData();
  console.info(`Data obtained: ${data}`);
}

runDataFetcherExample();
```

### Comprehensive Example: Complete Error Handling Flow

Combine retry, timeout, fallback, and logging to build a complete error handling flow for API calls.

<!-- @[api_client_with_retry](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandling.ets) -->

``` TypeScript
interface RetryConfig {
  maxRetries: number;
  timeout: number;
}

class ApiClient {
  private baseUrl: string;
  private maxRetries: number;
  private timeout: number;

  constructor(baseUrl: string, config?: RetryConfig) {
    this.baseUrl = baseUrl;
    this.maxRetries = config?.maxRetries ?? 3;
    this.timeout = config?.timeout ?? 5000;
  }

  async get(endpoint: string): Promise<string> {
    let url: string = `${this.baseUrl}${endpoint}`;
    let lastError: Error | null = null;

    for (let attempt: number = 0; attempt <= this.maxRetries; attempt++) {
      try {
        let result: string = await this.mockRequest(url);
        return result;
      } catch (error) {
        lastError = error as Error;

        if (attempt < this.maxRetries) {
          console.info(`Request failed, retry ${attempt + 1}...`);
          await this.delay(1000 * (attempt + 1));
        }
      }
    }

    throw new Error(`Request failed: ${lastError?.message}`);
  }

  private delay(ms: number): Promise<void> {
    return new Promise<void>((resolve: () => void): void => {
      setTimeout(() => resolve(), ms);
    });
  }

  private mockRequest(url: string): Promise<string> {
    return new Promise<string>((resolve: (value: string) => void, reject: (reason: Error) => void): void => {
      setTimeout(() => {
        if (url.includes('error')) {
          reject(new Error('Network error'));
        } else {
          resolve(`Data from ${url}`);
        }
      }, 100);
    });
  }
}

async function retryFetchUserInfo(): Promise<void> {
  let client: ApiClient = new ApiClient('EXAMPLE_API_URL', { maxRetries: 2, timeout: 3000 });

  try {
    let user: string = await client.get('/users/1');
    console.info(`User information: ${user}`);
  } catch (error) {
    console.error(`Failed to obtain user information: ${(error as Error).message}`);
    console.info('Using default user information');
  }
}

retryFetchUserInfo();
```

## Type of the catch Variable

In `strict` mode, the variable in a `catch` clause is of type `unknown`, so you must perform a type check before accessing error properties.

<!-- @[catch_unknown_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandling.ets) -->

``` TypeScript
function cuProcessData(data: string): void {
  try {
    let parsed: number = Number.parseInt(data, 10);
    if (Number.isNaN(parsed)) {
      throw new Error(`Invalid number: ${data}`);
    }
    console.info(`Parsed: ${parsed}`);
  } catch (error) {
    // The error type cannot directly access .message
    if (error instanceof Error) {
      console.info(`Error: ${error.message}`);
    } else {
      console.info(`Unknown error: ${error}`);
    }
  }
}

cuProcessData('abc');  // Error: Invalid number: abc
```

When catching errors of a specific type, use `instanceof` to distinguish between different error types.

<!-- @[catch_specific_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandling.ets) -->

``` TypeScript
class CsValidationError extends Error {
  public field: string;

  constructor(field: string, message: string) {
    super(message);
    this.field = field;
  }
}

class CsNetworkError extends Error {
  public statusCode: number;

  constructor(statusCode: number, message: string) {
    super(message);
    this.statusCode = statusCode;
  }
}

function csHandleRequest(url: string): void {
  try {
    if (url.length === 0) {
      throw new CsValidationError('url', 'URL cannot be empty');
    }
    throw new CsNetworkError(500, 'Server error');
  } catch (error) {
    if (error instanceof CsValidationError) {
      console.info(`Validation error [${error.field}]: ${error.message}`);
    } else if (error instanceof CsNetworkError) {
      console.info(`Network error [${error.statusCode}]: ${error.message}`);
    } else if (error instanceof Error) {
      console.info(`Unknown error: ${error.message}`);
    } else {
      console.info(`Unknown exception: ${error}`);
    }
  }
}

csHandleRequest('');  // Validation error [url]: URL cannot be empty
csHandleRequest('EXAMPLE_API_URL');  // Network error [500]: Server error
```

## Assertion Functions

An assertion function checks a condition at runtime and throws an exception when the condition is not met. In TypeScript, calling it narrows the type. In ArkTS, use an `if` check instead.

**TypeScript comparison**

<!-- @[ts_assertion_functions](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/ErrorHandling.ts) -->

``` TypeScript
// TypeScript comparison syntax; in ArkTS, use an if check instead
function assert(value: unknown): asserts value {
  if (value === undefined || value === null) {
    throw new Error('Value must be defined');
  }
}

function assertString(val: unknown): asserts val is string {
  if (typeof val !== 'string') {
    throw new Error('Expected string');
  }
}
```

In ArkTS, use an `if` check and a type guard function instead.

<!-- @[assertion_function_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandling.ets) -->

``` TypeScript
function afAssertDefined(value: string | null): string {
  if (value === null) {
    throw new Error('Value must be defined');
  }
  return value;
}

function afIsString(val: Object): boolean {
  return typeof val === 'string';
}

function afProcess(value: string | number): void {
  if (typeof value === 'string') {
    let v: string = afAssertDefined(value);
    console.info(`${v.toUpperCase()}`);
  } else {
    console.info(`${value.toString()}`);
  }
}

afProcess('hello');  // HELLO
afProcess(42);       // 42
```