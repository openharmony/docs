# Advanced Operators

<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=e25164b4c5d2db315865d228475dc21473dba5fb translatedAt=2026-08-13T08:52:59.444Z pushedAt=2026-08-13T11:56:19.091Z -->

ArkTS provides a rich set of advanced operators for scenarios such as bitwise operations, type checking, and object operations. ArkTS advanced operators include bitwise operators (bitwise AND, OR, XOR, NOT, left shift, and right shift), optional chaining (?.), nullish coalescing (??), and the spread operator (...), which are used to handle complex scenarios such as bit-level operations, safe access, and collection spreading.

## Basic Concepts of Advanced Operators

The advanced operators in ArkTS include bitwise operations, optional chaining (?.), nullish coalescing (??), and spread/rest operators (...), which are used to handle more complex logical expressions.

### Differences Between Advanced and Basic Operators

Unlike basic operators (arithmetic, comparison, logical, and assignment), advanced operators handle scenarios such as bit-level operations, null-safe access, collection spreading, and conditional evaluation, and are widely used in complex data structures and asynchronous programming.

<!-- @[operator_basics_and_advanced](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
// Basic operators
let opA: number = 10;
let opB: number = 5;
let hasName: boolean = true;
let hasAge: boolean = true;
interface ObjData {
  name: string;
}
let obj: ObjData = { name: 'test' };
let values: number[] = [1, 2, 3];
let sum: number = 10 + 5;
let isEqual: boolean = opA === opB;
let isValid: boolean = hasName && hasAge;

// Advanced operators
let flags: number = 0b1010 & 0b1100;
let extracted: string = obj?.name ?? 'unknown';
let copied: number[] = [...values];
```

### Operator Precedence and Associativity

Operator precedence determines the order in which operations are evaluated in an expression, and associativity determines the evaluation direction of operators with the same precedence.

<!-- @[operator_precedence](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
// Example of precedence from high to low
let result: number = 2 + 3 * 4;        // 14 (multiplication before addition)
let boolA: boolean = true;
let boolB: boolean = false;
let boolC: boolean = true;
let result2: boolean = boolA || boolB && boolC;    // && before ||
let textA: boolean = true;
let textB: string = 'yes';
let textC: string | null = null;
let textD: string = 'fallback';
let result3: string = textA ? textB : (textC ?? textD);  // `??` is evaluated before `?:`.

// Associativity: left-associative (left to right).
let value: number = 10 - 5 - 2;
console.info(`${value}`);  // 3

// Associativity: right-associative (right to left).
let textE: string = 'other';
let result4: string = textA ? textB : (boolC ? textD : textE);
console.info(`${result4}`);  // yes
```

## Bitwise Operators

Bitwise operators directly manipulate the binary bits of integers and are commonly used for permission flag management, data compression, encryption and decryption, and performance-sensitive mathematical computation. For example, use bitwise OR to combine permissions (`READ | WRITE`), bitwise AND to check permissions (`flags & READ`), and bitwise XOR to toggle flags (`flags ^ TOGGLE`). Bitwise operations are widely used in low-level and system programming, but are rarely used directly in everyday business logic.

### Bitwise AND (&)

The bitwise AND operator performs a logical AND operation on each bit of two integers. The result is 1 only when both corresponding bits are 1.

<!-- @[bitwise_and](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
let a: number = 5;   // Binary 0101
let b: number = 3;   // Binary 0011
let bitAndResult: number = a & b;  // Binary 0001, decimal 1

// Use case: check flag bits.
const READ: number = 0b001;
const WRITE: number = 0b010;
const EXECUTE: number = 0b100;

let permission: number = 0b110;  // Writable and executable.

let canRead: boolean = (permission & READ) !== 0;
let canWrite: boolean = (permission & WRITE) !== 0;
let canExecute: boolean = (permission & EXECUTE) !== 0;

console.info(`Read: ${canRead}`);      // false
console.info(`Write: ${canWrite}`);     // true
console.info(`Execute: ${canExecute}`);   // true

// Clear the flag bit.
permission = permission & ~WRITE;  // Clear the write permission.
```

### Bitwise OR (|)

The bitwise OR operator performs a logical OR operation on each bit of two integers. If either corresponding bit is 1, the result bit is 1.

<!-- @[bitwise_or](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
let bitOrA: number = 5;   // Binary: 0101
let bitOrB: number = 3;   // Binary: 0011
let bitOrResult: number = bitOrA | bitOrB;  // Binary: 0111 (decimal: 7)

// Use case: set flag bits.
const BOLD: number = 0b001;
const ITALIC: number = 0b010;
const UNDERLINE: number = 0b100;

let style: number = 0;
style = style | BOLD | ITALIC;  // Set bold and italic.

// Combine multiple flags.
let fullStyle: number = BOLD | ITALIC | UNDERLINE;  // 0b111
```

### Bitwise XOR (^)

The bitwise XOR operator performs an XOR operation on each bit of two integers. The result is 1 when the corresponding bits differ.

<!-- @[bitwise_xor](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
let bitXorA: number = 5;   // Binary: 0101
let bitXorB: number = 3;   // Binary: 0011
let bitXorResult: number = bitXorA ^ bitXorB;  // Binary: 0110 (Decimal: 6)

// Use case: toggle a flag bit.
let bitXorFlags: number = 0b101;
bitXorFlags = bitXorFlags ^ 0b001;  // Toggle bit 0: 0b100.
bitXorFlags = bitXorFlags ^ 0b001;  // Toggle bit 0 again: 0b101.

// Simple encryption.
let data: number = 42;
let key: number = 123;
let encrypted: number = data ^ key;
let decrypted: number = encrypted ^ key;
console.info(`${decrypted === data}`);  // true
```

### Bitwise NOT (~)

The bitwise NOT operator inverts each bit of an integer, turning 0 into 1 and 1 into 0.

<!-- @[bitwise_not](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
let bitNotA: number = 5;   // Binary: 0101
let bitNotResult: number = ~bitNotA;  // Binary: ...11111010 (decimal: -6)

// Formula: ~x = -(x + 1)
console.info(`${~5}`);   // -6
console.info(`${~(-6)}`); // 5

// Use case: clear the flag bit.
const FLAG: number = 0b010;
let bitNotValue: number = 0b111;
bitNotValue = bitNotValue & ~FLAG;  // Clear bit 1: 0b101.
```

### Left Shift Operator (<<)

The left shift operator shifts the binary bits of an integer to the left by a specified number of positions, which is equivalent to multiplying by a power of 2.

<!-- @[left_shift](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
let lshiftA: number = 5;   // Binary: 0101
let lshiftResult: number = lshiftA << 2;  // Binary: 010100 (decimal: 20)

// Shifting left by n bits is equivalent to multiplying by 2^n
console.info(`${5 << 1}`);  // 10 (5 * 2)
console.info(`${5 << 2}`);  // 20 (5 * 4)
console.info(`${5 << 3}`);  // 40 (5 * 8)

// Use case: fast multiplication.
let base: number = 10;
let doubled: number = base << 1;   // 20
let quadrupled: number = base << 2;  // 40
```

### Right Shift Operator (>>)

The right shift operator shifts the binary bits of an integer to the right by a specified number of positions, which is equivalent to dividing by a power of 2.

<!-- @[right_shift](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
let rshiftA: number = 20;  // Binary 010100
let rshiftResult: number = rshiftA >> 2;  // Binary 0101, decimal 5

// Shifting right by n bits is equivalent to dividing by 2^n (rounded down).
console.info(`${20 >> 1}`);  // 10
console.info(`${20 >> 2}`);  // 5
console.info(`${20 >> 3}`);  // 2

// Right shift of a negative number.
let neg: number = -20;
console.info(`${neg >> 2}`);  // -5

// Use case: fast division.
let total: number = 100;
let half: number = total >> 1;  // 50
let quarter: number = total >> 2;  // 25
```

### Unsigned Right Shift Operator (>>>)

The unsigned right shift operator shifts the integer's binary bits to the right and pads zeros on the left. The difference from `>>` is that `>>` preserves the sign bit (padding 1s on the left for negative numbers), while `>>>` pads zeros on the left regardless of the sign. A common use is to convert a floating-point number to a 32-bit unsigned integer via `>>> 0`.

<!-- @[unsigned_right_shift](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
let rshiftA2: number = 20;  // Binary: 010100
let rshiftResult2: number = rshiftA2 >>> 2;  // Binary: 0101 (decimal: 5)

// Same as >> for positive numbers.
console.info(`${20 >> 2}`);   // 5
console.info(`${20 >>> 2}`);  // 5

// Handles negative numbers differently.
let rshiftNeg: number = -20;  // Binary: ...11101100
console.info(`${rshiftNeg >> 2}`);    // -5 (sign bit preserved)
console.info(`${rshiftNeg >>> 2}`);   // 1073741819 (sign bit becomes 0)

// Use case: convert to an unsigned integer.
function toUnsigned(value: number): number {
  return value >>> 0;
}
```

## Compound Assignment Operators

Compound assignment operators combine an operation and an assignment into a single operation.

### Syntax of Compound Assignment

A compound assignment operator combines a binary operation and an assignment into a single step, equivalent to the shorthand of `x = x op y`. Arithmetic operators support `+=`, `-=`, `*=`, `/=`, `%=`, and `**=`; bitwise operators support `&=`, `|=`, `^=`, `<<=`, `>>=`, and `>>>=`.

``` TypeScript
variable operator= expression
等价于: variable = variable operator expression
```

<!-- @[compound_assignment_basics](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
let compoundA: number = 10;
compoundA += 5;
console.info(`${compoundA}`);  // 15
compoundA -= 3;
console.info(`${compoundA}`);  // 12
compoundA *= 2;
console.info(`${compoundA}`);  // 24
compoundA /= 4;
console.info(`${compoundA}`);  // 6
```

### Bitwise Compound Assignment

Bitwise compound assignment includes `&=` (bitwise AND assignment), `|=` (bitwise OR assignment), `^=` (bitwise XOR assignment), `<<=` (left shift assignment), `>>=` (right shift assignment), and `>>>=` (unsigned right shift assignment). These operators assign the result of the bitwise operation directly to the left operand.

<!-- @[compound_assignment_bitwise](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
let compoundFlags: number = 0b1010;

// Bitwise AND assignment
compoundFlags &= 0b1100;  // compoundFlags = compoundFlags & 0b1100 = 0b1000

// Bitwise OR assignment
compoundFlags |= 0b0011;  // compoundFlags = compoundFlags | 0b0011 = 0b1011

// Bitwise XOR assignment
compoundFlags ^= 0b0001;  // compoundFlags = compoundFlags ^ 0b0001 = 0b1010

// Left shift assignment
let compoundValue: number = 5;
compoundValue <<= 2;  // compoundValue = compoundValue << 2 = 20

// Right shift assignment
compoundValue >>= 1;  // compoundValue = compoundValue >> 1 = 10

// Unsigned right shift assignment
compoundValue >>>= 1;  // compoundValue = compoundValue >>> 1 = 5
```

### Arithmetic Compound Assignment

Arithmetic compound assignment includes `+=`, `-=`, `*=`, `/=`, `%=`, and `**=`, which assign the result of an arithmetic operation directly to the left operand.

<!-- @[compound_assignment_arithmetic](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
// Addition assignment
let compoundTotal: number = 100;
compoundTotal += 50;
console.info(`${compoundTotal}`);  // 150

// Subtraction assignment
let balance: number = 1000;
balance -= 200;
console.info(`${balance}`);  // 800

// Multiplication assignment
let price: number = 10;
price *= 2;
console.info(`${price}`);  // 20

// Division assignment.
let amount: number = 100;
amount /= 4;
console.info(`${amount}`);  // 25

// Modulo assignment.
let compoundValue2: number = 17;
compoundValue2 %= 5;
console.info(`${compoundValue2}`);  // 2

// Exponentiation assignment.
let compoundBase: number = 2;
compoundBase **= 4;
console.info(`${compoundBase}`);  // 16
```

### Evaluation Order of Compound Assignment

Compound assignment evaluates the right-hand expression first and then assigns the result to the left-hand variable.

<!-- @[compound_assignment_precedence](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
// Compound assignment is right-associative.
let capA: number = 10;
capA += 5;  // Evaluate the right-hand expression first, then assign.

// Compound expression
let capB: number = 5;
capA += capB * 2;  // a = a + (b * 2) = 15 + 10 = 25

// Counterexample: chained compound assignment
let capX: number = 10;
let capY: number = 20;
capX += capY += 5;  // Confusing, counterexample
```

## Comparison Operators and Type Determination

Comparison operators determine the relationship between values and return a Boolean result.

### Strict Equality and Non-Strict Equality

Strict equality (===) compares both value and type, while non-strict equality (==) performs type conversion. ArkTS recommends using strict equality.

<!-- @[ts_strict_equality](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/AdvancedOperators.ts) -->

``` TypeScript
// Strict equality (===): compares value and type.
let strictA: number = 5;
let strictB: string = '5';

console.info(`${strictA === 5}`);    // true
console.info(`${strictA === strictB}`);    // Compilation error: number and string types differ.
console.info(`${strictA === '5'}`);  // Compilation error: number and string types differ.

// Non-strict equality (==) performs type conversion before comparison and is not recommended.
console.info(`${strictA == strictB}`);  // true (implicit conversion, not recommended)

// Strict inequality (!==)
console.info(`${strictA !== strictB}`);    // Compilation error: number and string types differ

// Counterexample: non-strict inequality (!=)
console.info(`${strictA != strictB}`);  // TypeScript equivalent

// Recommended practice: always use strict equality.
function compareValues(x: number | string, y: number | string): boolean {
  if (typeof x === typeof y) {
    return x === y;
  }
  return false;
}
```

### Object Reference Comparison

`===` compares whether two references point to the same object, not whether their contents are identical.

<!-- @[reference_comparison](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

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

// Reference comparison: compares memory addresses
console.info(`${p1 === p2}`);  // false (different objects)
console.info(`${p1 === p3}`);  // true (same reference)

// Value comparison: requires a custom method
function pointsEqual(p1: Point, p2: Point): boolean {
  return p1.x === p2.x && p1.y === p2.y;
}

console.info(`${pointsEqual(p1, p2)}`);  // true

// Array comparison
let arr1: number[] = [1, 2, 3];
let arr2: number[] = [1, 2, 3];
let arr3: number[] = arr1;

console.info(`${arr1 === arr2}`);  // false
console.info(`${arr1 === arr3}`);  // true
```

### Type Guards Combined with Comparison Operators

Type guards use operators such as `typeof` and `instanceof` to check types at runtime and narrow the type range.

<!-- @[type_guards](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
// typeof type guard
function process(value: number | string): string {
  if (typeof value === 'number') {
    return `Number: ${value}`;
  } else {
    return `String: ${value}`;
  }
}

// instanceof type guard
class Animal {
  public name: string = '';
}

class Dog extends Animal {
  public breed: string = '';
}

let pet: Animal = new Dog();

if (pet instanceof Dog) {
  console.info(`${pet.breed}`);  // Type is Dog
}

// Discriminated field type guard.
interface Car {
  kind: 'car';
  drive(): void;
}

interface Boat {
  kind: 'boat';
  sail(): void;
}

function move(vehicle: Car | Boat): void {
  if (vehicle.kind === 'car') {
    vehicle.drive();
  } else {
    vehicle.sail();
  }
}

interface OperatorSquare {
  kind: 'square';
  size: number;
}

interface OperatorRectangle {
  kind: 'rectangle';
  width: number;
  height: number;
}

type OperatorShape = OperatorSquare | OperatorRectangle;

function area(shape: OperatorShape): number {
  switch (shape.kind) {
    case 'square':
      return shape.size * shape.size;
    case 'rectangle':
      return shape.width * shape.height;
  }
}
```

### Return Value Characteristics of Comparison Operators

Comparison operators always return a Boolean value and can be used in conditional expressions and logical operations.

<!-- @[ts_comparison_operators](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/AdvancedOperators.ts) -->

``` TypeScript
// Comparison operators return a Boolean value.
let cmpResult: boolean = 5 > 3;  // true

// Can be used in conditional expressions.
let cmpA: number = 10;
let cmpB: number = 20;
let cmpMax: number = cmpA > cmpB ? cmpA : cmpB;

// Chained comparison (must be written separately).
// Not supported: if (1 < x < 10)
// Correct approach:
let cmpX: number = 5;
if (1 < cmpX && cmpX < 10) {
  // x is in the range (1, 10)
}

// Compare different types
let cmpNum: number = 5;
let str: string = '5';
cmpNum > str;  // Compilation error, type mismatch
```

## Advanced Usage of Logical Operators

Logical operators support short-circuit evaluation — when the left-hand side already determines the overall value, the right-hand side is skipped. This is commonly used for conditional guards and null-safety protection.

### Logical AND Short-Circuit Evaluation

The logical AND (&&) skips the right-side evaluation when the left side is false, and is used for condition guards and avoiding null references.

<!-- @[logical_and_short_circuit](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
// && short-circuit: when the left side is false, the right side is not executed
function expensiveOperation(): boolean {
  console.info('Execute the expensive operation');
  return true;
}

let enabled: boolean = false;
let andResult: boolean = enabled && expensiveOperation();  // expensiveOperation is not executed

// Use case: conditional execution
interface Profile {
  name: string;
}

interface User {
  profile?: Profile;
}

function getUserName(user: User | null): string {
  return user?.profile?.name ?? 'Unknown';
}

// Use case: precondition check
function processArray(arr: number[] | null): number {
  if (arr !== null && arr.length > 0) {
    return arr[0] ?? -1;
  }
  return -1;
}

// Use case: permission check
function canAccess(user: User | null, requiredRole: string): boolean {
  return user !== null && user.profile !== undefined && user.profile.name !== '';
}
```

### Logical OR Short-Circuit Evaluation

The logical OR (||) skips the right-side execution when the left side is true, and is used to provide default values.

<!-- @[logical_or_short_circuit](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
// || short-circuit: the right side is not executed when the left side is true.
function getDefault(): string {
  console.info('Obtain the default value.');
  return 'default';
}

let provided: string = 'provided';
let orValue: string = provided || getDefault();  // getDefault is not executed.

// Use case: provide a default value (handle falsy values).
let count: number = 0;
let displayCount: number = count || 10;  // 10 (note: 0 is falsy)

// Use case: check multiple conditions.
let hasPermission: boolean = true;
let isOwner: boolean = false;
let canEdit: boolean = hasPermission || isOwner;

// Use case: configuration fallback.
interface Config {
  host?: string;
  port?: number;
}

function connect(config: Config): void {
  let host: string = config.host || 'localhost';
  let port: number = config.port || 3306;
  console.info(`Connecting to ${host}:${port}`);
}
```

### Type Conversion by Logical NOT

The logical NOT (!) first converts the operand to a boolean and then negates it: 0, '', null, and undefined become true, and all other values become false.

<!-- @[logical_not](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
// Convert the value to a boolean and then negate it with logical NOT.
let value1: number = 5;
let value2: string = '';
let value3: number = 0;
let value4: string | null = null;
let value5: string | undefined = undefined;

console.info(`${!value1}`);  // false
console.info(`${!value2}`);  // true
console.info(`${!value3}`);  // true
console.info(`${!value4}`);  // true
console.info(`${!value5}`);  // true

// Double negation: convert to a boolean.
console.info(`${!!value1}`);  // true
console.info(`${!!value2}`);  // false
console.info(`${!!value3}`);  // false

// Equivalent to Boolean().
console.info(`${Boolean(value1)}`);  // true

// Use case: conditional judgment.
function processValue(value: string | null): void {
  if (!value) {
    console.info('Value is null');
    return;
  }
  console.info(`Processed value: ${value}`);
}
```

### Nesting and Precedence of Logical Operators

Logical AND (&&) has higher precedence than logical OR (||). For complex expressions, use parentheses to clarify the precedence.

<!-- @[logical_operator_precedence](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
// && has higher precedence than ||
let logOpA: boolean = true;
let logOpB: boolean = false;
let c: boolean = false;

let logOpResult: boolean = logOpA || logOpB && c;  // Equivalent to: logOpA || (logOpB && c)
console.info(`${logOpResult}`);  // true

// Use parentheses to clarify precedence
let logOpResult2: boolean = (logOpA || logOpB) && c;  // false

//  tags.
</analysis>

<translation>
<seg id="code:97:3">Complex logical expression
let logOpHasPermission: boolean = true;
let isAuthenticated: boolean = false;
let isAdmin: boolean = true;

// Recommended: use parentheses and line breaks to improve readability
let logOpCanAccess: boolean = 
  isAuthenticated && (
    logOpHasPermission || isAdmin
  );

// De Morgan's law application
let isInverseA: boolean = !logOpA;
let isInverseB: boolean = !logOpB;

// !(logOpA && logOpB) === (!logOpA || !logOpB)
let expr1: boolean = !(logOpA && logOpB);
let expr2: boolean = !logOpA || !logOpB;
console.info(`${expr1 === expr2}`);  // true

// !(logOpA || logOpB) === (!logOpA && !logOpB)
let expr3: boolean = !(logOpA || logOpB);
let expr4: boolean = !logOpA && !logOpB;
console.info(`${expr3 === expr4}`);  // true
```

## Ternary Conditional Operator

The ternary conditional operator (condition ? a : b) performs conditional assignment in a single line, replacing a simple if-else statement.

### Syntax of the Ternary Operator

The ternary operator selects one of two values based on a condition, with the syntax `condition ? value1 : value2`.

<!-- @[ts_ternary_operator_basics](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/AdvancedOperators.ts) -->

``` TypeScript
let age: number = 20;
let status: string = age >= 18 ? 'adult' : 'minor';

let score: number = 85;
let result: string = score >= 60 ? 'pass' : 'fail';

// The return value types must be consistent.
let value: number = 10;
let output: string = value > 5 ? 'greater' : 'less';  // Correct
let wrong: string = value > 5 ? 10 : 'less';  // Compilation error

// Function call
function getName(): string {
  return 'Alice';
}

function getDefaultName(): string {
  return 'Unknown';
}

let user: string | null = null;
let displayName: string = user !== null ? user : getDefaultName();
```

### Nesting Ternary Operators

Ternary operators can be nested to handle multi-branch selection, but excessive nesting reduces readability.

<!-- @[nested_ternary](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
let score: number = 85;

// Nested ternary operator
let grade: string = 
  score >= 90 ? 'A' :
  score >= 80 ? 'B' :
  score >= 70 ? 'C' :
  score >= 60 ? 'D' : 'F';

console.info(`Grade: ${grade}`);  // B

// More complex nesting
let age: number = 25;
let hasLicense: boolean = true;
let hasInsurance: boolean = false;

let canDrive: string = 
  age < 18 ? 'underage' :
  !hasLicense ? 'no license' :
  !hasInsurance ? 'no insurance' :
  'can drive';

// Counterexample: multi-level nesting (affects readability).
let status: string = 
  age < 13 ? 'child' :
  age < 20 ? 'teenager' :
  age < 30 ? 'young adult' :
  age < 50 ? 'adult' :
  age < 65 ? 'middle-aged' : 'senior';
```

### Equivalence Between the Ternary Operator and if-else

The ternary operator `condition ? a : b` can be rewritten as an if-else statement, which is suitable for simple conditional assignment scenarios.

<!-- @[ternary_vs_if_else](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
// Ternary operator
let elseA: number = 10;
let elseB: number = 20;
let max: number = elseA > elseB ? elseA : elseB;

// Equivalent if-else
let max2: number;
if (elseA > elseB) {
  max2 = elseA;
} else {
  max2 = elseB;
}

// Complex condition
let elseScore: number = 75;
let elseGrade: string = elseScore >= 60 ? 'pass' : 'fail';

// Equivalent if-else
let grade2: string;
if (elseScore >= 60) {
  grade2 = 'pass';
} else {
  grade2 = 'fail';
}

// Multiple branch selection
let elseValue: number = 85;
let category: string = 
  elseValue >= 90 ? 'excellent' :
  elseValue >= 70 ? 'good' :
  elseValue >= 50 ? 'average' : 'poor';

// Equivalent if-else if-else
let category2: string;
if (elseValue >= 90) {
  category2 = 'excellent';
} else if (elseValue >= 70) {
  category2 = 'good';
} else if (elseValue >= 50) {
  category2 = 'average';
} else {
  category2 = 'poor';
}
```

### Improving Ternary Operator Readability

For complex ternary expressions, use helper functions or if-else statements instead to improve code readability.

<!-- @[ternary_best_practices](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
let scoreA: number = 10;
let scoreB: number = 5;
let scoreC: number = 8;
let applicantAge: number = 20;
let hasDrivingLicense: boolean = true;

// Counterexample: overly complex nesting
let maxScoreTernary: number = scoreA > scoreB
  ? (scoreA > scoreC ? scoreA : scoreC)
  : (scoreB > scoreC ? scoreB : scoreC);

// Recommended: use if-else to improve readability
function getMaxScore(a: number, b: number, c: number): number {
  if (a > b && a > c) {
    return a;
  } else if (b > c) {
    return b;
  } else {
    return c;
  }
}

let maxScoreResult: number = getMaxScore(scoreA, scoreB, scoreC);

// Recommended: use a helper function
function convertScoreToGrade(score: number): string {
  if (score >= 90) {
    return 'A';
  }
  if (score >= 80) {
    return 'B';
  }
  if (score >= 70) {
    return 'C';
  }
  if (score >= 60) {
    return 'D';
  }
  return 'F';
}

// Recommended: format the ternary operator.
let licenseStatus: string =
  applicantAge >= 18 && hasDrivingLicense ? 'eligible' :
  applicantAge >= 18 ? 'no license' :
  'underage';

// Counterexample: the line is too long.
let compactLicenseStatus: string = applicantAge >= 18 && hasDrivingLicense
  ? 'eligible' : applicantAge >= 18 ? 'no license' : 'underage';
```

## Spread and Rest Operators

The spread operator (...) breaks an array or object into individual elements for merging and copying, while the rest operator collects multiple parameters into an array.

### Array Spread Operator

The spread operator (...) expands array elements into individual elements for copying, merging, and passing arguments.

<!-- @[spread_operator_array](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
// Spread array elements.
let spreadArr1: number[] = [1, 2, 3];
let spreadArr2: number[] = [4, 5, 6];

// Merge arrays.
let merged: number[] = [...spreadArr1, ...spreadArr2];
console.info(`${merged.join(', ')}`);  // 1, 2, 3, 4, 5, 6

// Insert at any position.
let inserted: number[] = [0, ...spreadArr1, 4];
console.info(`${inserted.join(', ')}`);  // 0, 1, 2, 3, 4

// Copy the array.
let spreadCopied: number[] = [...spreadArr1];
console.info(`${spreadCopied.join(', ')}`);  // 1, 2, 3

// As function arguments: the spread array should be passed to the rest parameter.
function spreadSum(...values: number[]): number {
  let spreadTotal: number = 0;
  for (let value of values) {
    spreadTotal += value;
  }
  return spreadTotal;
}

let numbers: number[] = [1, 2, 3];
let spreadTotal: number = spreadSum(...numbers);  // 6

// Combine spread with array methods.
let spreadMax: number = Math.max(...spreadArr1);  // 3
let min: number = Math.min(...spreadArr2);  // 4
```

### Object Spread Comparison and Explicit Copy

TypeScript supports object spread, for example, `{ ...source }` and `{ ...defaults, ...override }`. ArkTS is stricter about object literals and spread syntax. For copying and merging ordinary business objects, prefer explicit construction or assignment.

<!-- @[spread_operator_object](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
interface Person {
  name: string;
  age: number;
  city?: string;
}

function copyPerson(source: Person): Person {
  return {
    name: source.name,
    age: source.age,
    city: source.city
  };
}

function mergePerson(defaults: Person, override: Person): Person {
  return {
    name: override.name.length > 0 ? override.name : defaults.name,
    age: override.age,
    city: override.city !== undefined ? override.city : defaults.city
  };
}

let person: Person = { name: 'Alice', age: 30 };
let spreadCopied2: Person = copyPerson(person);
console.info(`${spreadCopied2.name}`);
```

### Rest Parameter Operator

The rest parameter operator (...) collects multiple parameters into an array and is used to handle a variable number of parameters.

<!-- @[rest_parameters](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
// Rest parameter in function parameters
function sumAll(...numbers: number[]): number {
  let total: number = 0;
  for (const num of numbers) {
    total += num;
  }
  return total;
}

console.info(`${sumAll(1, 2, 3, 4, 5)}`);  // 15

// Combined with fixed parameters
function greet(greeting: string, ...names: string[]): string {
  return `${greeting}, ${names.join(', ')}!`;
}

console.info(`${greet('Hello', 'Alice', 'Bob', 'Charlie')}`);  // Hello, Alice, Bob, Charlie!

// Rest element in array destructuring
let arr: number[] = [1, 2, 3, 4, 5];
// ArkTS does not support destructuring assignment. Extract it manually.
let first: number = arr[0] ?? 0;
let rest: number[] = arr.slice(1);
console.info(`${first}`);  // 1
console.info(`${rest.join(', ')}`);   // 2, 3, 4, 5

// Collect function parameters.
function restProcess(first: string, second: string, ...remaining: string[]): void {
  console.info(`First: ${first}`);
  console.info(`Second: ${second}`);
  console.info(`Remaining: ${remaining.join(', ')}`);
}

restProcess('a', 'b', 'c', 'd', 'e');
// First: a
// Second: b
// Remaining: c, d, e
```

### Rest Property Comparison and Explicit Copying

ArkTS does not support object rest property destructuring. You must explicitly copy each property.

<!-- @[object_rest_properties](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
interface RequestUser {
  id: number;
  name: string;
  email: string;
  age: number;
}

// Rest property in object destructuring
let user: RequestUser = {
  id: 1,
  name: 'Alice',
  email: 'alice@example.com',
  age: 30
};

// ArkTS does not support destructuring assignment; extract it manually.
let id: number = user.id;
let name: string = user.name;
interface UserRestInfo {
  email: string;
  age: number;
}

let objRestRest: UserRestInfo = {
  email: user.email,
  age: user.age
};

// Extract partial properties from function parameters
interface RequestOptions {
  timeout?: number;
  retries?: number;
  logLevel?: string;
}

function request(url: string, options: RequestOptions): void {
  let timeout: number = options.timeout ?? 5000;
  let retries: number = options.retries ?? 3;
  let logLevel: string = options.logLevel ?? 'info';
  
  console.info(`Request to ${url} with timeout=${timeout}, retries=${retries}`);
}
```

### Deep Copy and Shallow Copy of the Spread Operator

The spread operator creates a shallow copy, where nested objects still share references. A deep copy requires manually handling nested levels.

<!-- @[shallow_vs_deep_copy](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
// Shallow copy.
interface NestedNumber {
  c: number;
}

interface NumberBox {
  a: number;
  b: NestedNumber;
}

function copyNumberBox(source: NumberBox): NumberBox {
  return {
    a: source.a,
    b: source.b
  };
}

let obj1: NumberBox = {
  a: 1,
  b: { c: 2 }
};

let obj2: NumberBox = copyNumberBox(obj1);
obj2.a = 10;
obj2.b.c = 20;

console.info(`${obj1.a}`);    // 1 (primitive type, independent)
console.info(`${obj1.b.c}`);  // 20 (reference type, shared)

// Implement a deep copy for the declared type.
function cloneNumberBox(source: NumberBox): NumberBox {
  return {
    a: source.a,
    b: {
      c: source.b.c
    }
  };
}

let obj3: NumberBox = {
  a: 1,
  b: { c: 2 }
};

let obj4: NumberBox = cloneNumberBox(obj3);
obj4.b.c = 20;
console.info(`${obj3.b.c}`);  // 2 (independent, unaffected)
```

## Operator Overloading (Simulated Implementation)

Neither TypeScript nor ArkTS supports operator overloading. Named methods (such as add and sub) are used to simulate operator behavior.

### No Native Operator Overloading

Operator overloading is not supported. You can simulate operator behavior through named methods.

<!-- @[ts_operator_overloading_not_supported](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/AdvancedOperators.ts) -->

``` TypeScript
// Operator overloading is not supported.
class Vector {
  public x: number = 0;
  public y: number = 0;

  constructor(x: number = 0, y: number = 0) {
    this.x = x;
    this.y = y;
  }

  // operator+ is not supported (compilation error: TS does not support operator overloading).
  operator+(other: Vector): Vector {
    return new Vector(this.x + other.x, this.y + other.y);
  }
}
```

### Simulating Operator Behavior with Named Methods

Simulate operator behavior through named methods (such as add and sub) to implement vector operations in the Vector class.

<!-- @[simulated_operator_overloading](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
class Vector {
  public x: number = 0;
  public y: number = 0;

  constructor(x: number = 0, y: number = 0) {
    this.x = x;
    this.y = y;
  }

  // Simulate the addition operator.
  add(other: Vector): Vector {
    return new Vector(this.x + other.x, this.y + other.y);
  }

  // Simulate the subtraction operator.
  subtract(other: Vector): Vector {
    return new Vector(this.x - other.x, this.y - other.y);
  }

  // Simulate the multiplication operator (scalar multiplication).
  multiply(scalar: number): Vector {
    return new Vector(this.x * scalar, this.y * scalar);
  }

  // Simulate the dot product operator.
  dot(other: Vector): number {
    return this.x * other.x + this.y * other.y;
  }

  // Simulate the equality operator.
  equals(other: Vector): boolean {
    return this.x === other.x && this.y === other.y;
  }

  // Simulate the comparison operator.
  magnitude(): number {
    return Math.sqrt(this.x * this.x + this.y * this.y);
  }

  greaterThan(other: Vector): boolean {
    return this.magnitude() > other.magnitude();
  }

  toString(): string {
    return `Vector(${this.x}, ${this.y})`;
  }
}

// Use the simulated operator.
let v1: Vector = new Vector(1, 2);
let v2: Vector = new Vector(3, 4);

let simOpSum: Vector = v1.add(v2);
console.info(`${JSON.stringify(simOpSum)}`);  // {"x":4,"y":6}

let diff: Vector = v1.subtract(v2);
console.info(`${JSON.stringify(diff)}`);  // {"x":-2,"y":-2}

let scaled: Vector = v1.multiply(2);
console.info(`${JSON.stringify(scaled)}`);  // {"x":2,"y":4}

let dotProduct: number = v1.dot(v2);
console.info(`${dotProduct}`);  // 11

let simOpIsEqual: boolean = v1.equals(v2);
console.info(`${simOpIsEqual}`);  // false
```

### Example of Simulating Addition/Subtraction Overloading

Simulate addition and subtraction of complex numbers in the `Complex` class through named methods (such as `add` and `sub`).

<!-- @[complex_number_operators](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
class Complex {
  public real: number = 0;
  public imag: number = 0;

  constructor(real: number = 0, imag: number = 0) {
    this.real = real;
    this.imag = imag;
  }

  // Simulate addition.
  add(other: Complex): Complex {
    return new Complex(
      this.real + other.real,
      this.imag + other.imag
    );
  }

  // Simulate subtraction.
  subtract(other: Complex): Complex {
    return new Complex(
      this.real - other.real,
      this.imag - other.imag
    );
  }

  // Simulate multiplication.
  multiply(other: Complex): Complex {
    return new Complex(
      this.real * other.real - this.imag * other.imag,
      this.real * other.imag + this.imag * other.real
    );
  }

  // Simulate division.
  divide(other: Complex): Complex {
    let denominator: number = other.real * other.real + other.imag * other.imag;
    return new Complex(
      (this.real * other.real + this.imag * other.imag) / denominator,
      (this.imag * other.real - this.real * other.imag) / denominator
    );
  }

  // Simulate the unary minus.
  negate(): Complex {
    return new Complex(-this.real, -this.imag);
  }

  // Simulate equality.
  equals(other: Complex): boolean {
    return this.real === other.real && this.imag === other.imag;
  }

  toString(): string {
    if (this.imag >= 0) {
      return `${this.real} + ${this.imag}i`;
    } else {
      return `${this.real} - ${-this.imag}i`;
    }
  }
}

let c1: Complex = new Complex(3, 2);
let c2: Complex = new Complex(1, 7);

let complexNumSum: Complex = c1.add(c2);
console.info(`${JSON.stringify(complexNumSum)}`);  // {"real":4,"imag":9}

let complexNumDiff: Complex = c1.subtract(c2);
console.info(`${JSON.stringify(complexNumDiff)}`);  // {"real":2,"imag":-5}

let product: Complex = c1.multiply(c2);
console.info(`${JSON.stringify(product)}`);  // {"real":-11,"imag":23}
```

### Usage Scenario Restrictions for Operator Overloading

Operator overloading simulation is suitable for mathematical computation. For complex business logic, use explicit method names.

<!-- @[operator_overloading_use_cases](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
// Scenario 1: Mathematical computation (recommended)
class Matrix {
  private data: number[][] = [];
  private rows: number;
  private cols: number;

  constructor(rows: number, cols: number) {
    this.rows = rows;
    this.cols = cols;
    for (let i: number = 0; i < rows; i++) {
      let row: number[] = [];
      for (let j: number = 0; j < cols; j++) {
        row.push(0);
      }
      this.data.push(row);
    }
  }

  private getValue(row: number, col: number): number {
    let rowData: number[] | undefined = this.data[row];
    if (rowData === undefined) {
      return 0;
    }
    return rowData[col] ?? 0;
  }

  private setValue(row: number, col: number, value: number): void {
    let rowData: number[] | undefined = this.data[row];
    if (rowData !== undefined) {
      rowData[col] = value;
    }
  }

  add(other: Matrix): Matrix {
    let result: Matrix = new Matrix(this.rows, this.cols);
    for (let i: number = 0; i < this.rows; i++) {
      for (let j: number = 0; j < this.cols; j++) {
        result.setValue(i, j, this.getValue(i, j) + other.getValue(i, j));
      }
    }
    return result;
  }

  multiply(other: Matrix): Matrix {
    // Matrix multiplication implementation
    let result: Matrix = new Matrix(this.rows, this.cols);
    // ... Implementation details
    return result;
  }
}

// Scenario 2: Custom type comparison (recommended)
class Money {
  private amount: number;
  private currency: string;

  constructor(amount: number, currency: string) {
    this.amount = amount;
    this.currency = currency;
  }

  add(other: Money): Money {
    if (this.currency !== other.currency) {
      throw new Error('Currency mismatch');
    }
    return new Money(this.amount + other.amount, this.currency);
  }

  equals(other: Money): boolean {
    return this.amount === other.amount && this.currency === other.currency;
  }

  lessThan(other: Money): boolean {
    if (this.currency !== other.currency) {
      throw new Error('Currency mismatch');
    }
    return this.amount < other.amount;
  }
}

// Scenario 3: Chained calls (recommended)
class OperationStringBuilder {
  private parts: string[] = [];

  append(text: string): OperationStringBuilder {
    this.parts.push(text);
    return this;
  }

  toString(): string {
    return this.parts.join('');
  }
}

let operationResult: string = new OperationStringBuilder()
  .append('Hello')
  .append(' ')
  .append('World')
  .toString();

console.info(`${operationResult}`);

// Counterexample: Complex business logic scenario
// For complex business logic, use explicit method names instead of simulated operators.
```

## Operator Precedence Table

Operator precedence determines the order in which operations are evaluated in an expression. In ArkTS, common operators are listed in descending order of precedence as follows: parentheses `()` → member access `.`/`[]` → unary `!`/`-`/`++`/`--` → arithmetic `*`/`/`/`%` → arithmetic `+`/`-` → shift `<<`/`>>`/`>>>` → comparison `>`/`<`/`>=`/`<=` → equality `===`/`!==` → bitwise `&` → bitwise `^` → bitwise `|` → logical `&&` → logical `||` → nullish coalescing `??` → ternary `?:` → assignment `=`/`+=` and so on. For complex expressions, use parentheses to clarify precedence and avoid ambiguity caused by relying on default rules.

<!-- @[parentheses_for_precedence](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
let precA: number = 5;
let precB: number = 3;
let precC: number = 10;
let precD: number = 2;
let precInput: string | null = 'hello';
// Use parentheses to clarify precedence.
let precResult: number = (precA + precB) * (precC - precD);
let valid: boolean = (precA > precB) && (precC < precD);
let precValue: string = (precInput ?? 'default') + ' suffix';
```

## ArkTS Constraints

ArkTS restricts destructuring assignment and some dynamic features. Use separate assignment or index access instead.

### Destructuring Assignment Not Supported

ArkTS does not support destructuring assignment (for example, `let {a, b} = obj`). Assign each property explicitly.

<!-- @[ts_destructuring_not_supported](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/AdvancedOperators.ts) -->

``` TypeScript
interface Point {
  pointX: number;
  pointY: number;
}

let point: Point = { pointX: 10, pointY: 20 };

// Not supported
let [destA, destB] = [1, 2];
let {pointX, pointY} = point;

// Correct: assign separately
let arr: number[] = [1, 2];
let destAVal: number = arr[0];
let destBVal: number = arr[1];

let destX: number = point.pointX;
let destY: number = point.pointY;
```

### Loose Equality Not Recommended

ArkTS supports loose equality (`==` and `!=`), but it is not recommended because it performs implicit type conversion, which may lead to bugs that are hard to detect. Strict equality (`===` and `!==`) is recommended.

<!-- @[strict_equality_best_practices](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
let strictValue: number | null = 5;
if (strictValue == 5) { }
if (strictValue != null) { }

let equalityValue: number | null = 5;

// Use strict equality.
if (equalityValue === 5) { }
if (equalityValue !== null) { }
```

### Types Must Match

ArkTS requires that the operand types on both sides of an operator be identical or deterministically compatible at compile time; otherwise, a compilation error is reported. For example, `5 > '5'` reports an error because the `number` and `string` types do not match, and `true + 1` reports an error because `boolean` and `number` are incompatible. This restriction avoids the unexpected runtime behavior caused by implicit type conversion in JavaScript.

**Example (incorrect)**

<!-- @[ts_type_safe_operations](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/AdvancedOperators.ts) -->

``` TypeScript
let num: number = 5;
num = 'text';  // Compilation error.

// Operator operand types must be compatible.
let typeSafeA: number = 5;
let typeSafeB: string = '5';
let typeSafeResult: boolean = typeSafeA > typeSafeB;  // Compilation error.
```

## as const Assertion

The `as const` assertion infers object properties as literal types rather than broad types. It ensures that property values are immutable and their types are precise.

**TypeScript Comparison**

<!-- @[ts_as_const](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/AdvancedOperators.ts) -->

``` TypeScript
// TypeScript equivalent; in ArkTS, use an explicit type annotation instead.
const tsConfig = {
  url: 'EXAMPLE_API_URL',
  method: 'GET'
} as const;
// The type of tsConfig.method is 'GET' (literal).

const tsArgs = [8, 5] as const;
// The type of tsArgs is readonly [8, 5] (tuple).
```

In ArkTS, use an explicit type annotation instead of `as const`.

<!-- @[as_const_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
interface AcRequestConfig {
  readonly url: string;
  readonly method: 'GET' | 'POST';
}

let acConfig: AcRequestConfig = {
  url: 'EXAMPLE_API_URL',
  method: 'GET'
};

console.info(`${acConfig.method}`);  // GET
```

The `method` property of `acConfig` is `readonly`, and assigning a value to it triggers a compilation error.

**TypeScript comparison**

<!-- @[ts_as_const_readonly_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/AdvancedOperators.ts) -->

``` TypeScript
// TypeScript comparison, demonstrating the compilation error of assigning to a readonly property.
interface TsReadonlyConfig {
  readonly method: string;
}

let tsReadonlyConfig: TsReadonlyConfig = {
  method: 'GET'
};

tsReadonlyConfig.method = 'POST';  // Compilation error: Cannot assign to 'method' because it is a read-only property
```

Using the `AcHttpMethod` enum provides a type-safe set of string literals.

<!-- @[as_const_enum_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
// Use an enum instead of string literals
enum AcHttpMethod {
  GET = 'GET',
  POST = 'POST'
}

let acMethod: AcHttpMethod = AcHttpMethod.GET;
console.info(`${acMethod}`);  // GET
```

## satisfies Operator

The `satisfies` operator checks whether a value satisfies a specified type, but does not narrow the type. Unlike `as`, `satisfies` performs a real type check rather than an assertion.

**TypeScript Comparison**

<!-- @[ts_satisfies](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/AdvancedOperators.ts) -->

``` TypeScript
// TypeScript comparison (TS 4.9+); in ArkTS, use an explicit type instead
type StColors = 'red' | 'green' | 'blue';

const stRgb = {
  red: '#FF0000',
  green: '#00FF00',
  blue: '#0000FF'
} satisfies Record<StColors, string>;
```

In ArkTS, use explicit type annotations and interfaces instead of `satisfies`.

<!-- @[satisfies_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
interface SaColorMap {
  red: string;
  green: string;
  blue: string;
}

let saRgb: SaColorMap = {
  red: '#FF0000',
  green: '#00FF00',
  blue: '#0000FF'
};

console.info(`${saRgb.red}`);   // #FF0000
console.info(`${saRgb.green}`); // #00FF00
console.info(`${saRgb.blue}`);  // #0000FF
```

The difference between `as` and `satisfies`: `as` is an assertion that performs no checking, while `satisfies` performs real type checking but does not narrow the type. In ArkTS, use explicit type annotations to achieve equivalent safety.