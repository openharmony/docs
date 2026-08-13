# Basic Operators

<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=e25164b4c5d2db315865d228475dc21473dba5fb translatedAt=2026-08-13T08:54:23.281Z pushedAt=2026-08-13T12:06:55.152Z -->

ArkTS provides a rich set of operators for data operations, logical judgment, and assignment operations.

## Assignment Operators

The assignment operator (=) assigns the value on the right to the variable on the left, and supports chained assignment and compound assignment (+=, -=, and so on).

### Simple Assignment (=)

Use `=` to assign the value on the right to the variable on the left. Assignment follows reference semantics: after assigning an object-type variable, the old and new variables point to the same object, and modifying one affects the other.

<!-- @[basic_variable_assignment](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let value: number = 10;
let name: string = 'Alice';
let active: boolean = true;

// Reassign the value.
value = 20;
name = 'Bob';
```

### Assignment and Tuples

ArkTS does not support tuple destructuring assignment (for example, `let [a, b] = [1, 2]`). Assign each variable individually.

<!-- @[ts_no_destructuring_assignment](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Operators.ts) -->

``` TypeScript
// Destructuring assignment is not supported.
let [a, b] = [1, 2];

// Correct approach: assign variables individually.
let arr: number[] = [1, 2];
let aVal: number = arr[0];
let bVal: number = arr[1];
```

### Return Value of an Assignment Expression

An assignment expression returns the assigned value. Chained assignment such as `a = b = 10` is syntactically supported, but it is **not recommended**. Assign values separately to improve readability.

<!-- @[chain_vs_separate_assignment](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let a: number;
let b: number;

// Counterexample: chained assignment
a = b = 10;

// Recommended: assign separately
a = 10;
b = 10;
```

### Object Assignment

Assigning an object to a variable passes a reference rather than a copy—the new and old variables point to the same object, and modifying a property of one affects the other. To obtain an independent copy, you must implement a deep copy manually.

<!-- @[object_property_and_reference_assignment](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
class Point {
  public x: number = 0;
  public y: number = 0;
}

let point: Point = new Point();
point.x = 10;       // Property assignment
point.y = 20;

let another: Point = point;  // Reference assignment
another.x = 30;    // point.x also becomes 30
```

## Arithmetic Operators

Arithmetic operators include addition (+), subtraction (-), multiplication (*), division (/), remainder (%), and increment/decrement (++/--).

### Addition Operator (+)

The addition operator performs numeric addition or string concatenation and returns the sum or concatenation result.

<!-- @[addition_and_string_concatenation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let addA: number = 10;
let addB: number = 5;

let sum: number = addA + addB;    // 15

// String concatenation
let greeting: string = 'Hello' + ' World';
let message: string = 'Count: ' + 10;
```

### Subtraction Operator (-)

The subtraction operator (`-`) computes the difference between two numeric operands. The operands must be of the `number` type, and ArkTS does not allow cross-type operations such as between `number` and `string`.

<!-- @[subtraction_and_negative_number](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let numberA: number = 10;
let numberB: number = 5;

let diff: number = numberA - numberB;   // 5
let negative: number = -10; // Represent a negative number.
```

### Multiplication Operator (*)

The multiplication operator (`*`) computes the product of two numeric operands. The operands must be of the `number` type. ArkTS does not support string repetition (such as `'ab' * 3` in Python); use the `repeat()` method for string repetition.

<!-- @[multiplication_operator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let mulA: number = 10;
let mulB: number = 5;

let product: number = mulA * mulB;  // 50

// Calculate the area.
let width: number = 5;
let height: number = 10;
let area: number = width * height;  // 50
```

### Division Operator (/)

The division operator (/) calculates the quotient of two numbers, and the result is always a floating-point number.

<!-- @[division_operator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let divA: number = 10;
let divB: number = 4;

let quotient: number = divA / divB;  // 2.5

// Integer division.
let intDivision: number = Math.floor(10 / 4);  // 2

// Division by zero.
let zeroDiv: number = 10 / 0;   // Infinity
let negZeroDiv: number = -10 / 0;  // -Infinity
let zeroByZero: number = 0 / 0;  // NaN
```

### Remainder Operator (%)

The remainder operator returns the remainder of a division and is used for loops and periodic calculations.

<!-- @[modulo_operator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let modA: number = 10;
let modB: number = 3;

let remainder: number = modA % modB;  // 1

// Determine whether the number is even or odd.
let isEven: boolean = (modA % 2) === 0;
let isOdd: boolean = (modA % 2) !== 0;
```

### Unary Negation Operator (-)

The unary negation operator (-) negates a numeric value, turning a positive value into a negative one and vice versa.

<!-- @[unary_negation_operator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let negA: number = 5;
let negNegative: number = -negA;  // -5

let negB: number = -10;
let positive: number = -negB;  // 10
```

### Unary Plus Operator (+)

The unary plus operator converts a value to the numeric type and is used for type conversion.

<!-- @[unary_plus_operator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let plusA: number = 5;
let plus: number = +plusA;  // 5

// Used for explicit conversion (Number.parseInt is recommended).
let strNum: number = Number.parseInt('42', 10);
```

### Exponentiation Operator (**)

The exponentiation operator calculates a power and returns the base raised to the power of the exponent.

<!-- @[exponentiation_operator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let base: number = 2;
let exponent: number = 3;

let power: number = base ** exponent;  // 8 (2^3)

let square: number = 5 ** 2;   // 25
let cube: number = 3 ** 3;     // 27
```

## Compound Assignment Operators

Compound assignment operators combine an operation and an assignment to simplify code.

<!-- @[compound_assignment_operators](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
// Addition assignment
let total: number = 100;
total += 50;
console.info(`${total}`);  // 150

// String concatenation assignment
let compoundMessage: string = 'Hello';
compoundMessage += ' World';
console.info(`${compoundMessage}`);  // Hello World

// Subtraction assignment
let balance: number = 1000;
balance -= 200;
console.info(`${balance}`);  // 800

// multiplication assignment
let price: number = 10;
price *= 2;
console.info(`${price}`);  // 20

// division assignment
let amount: number = 100;
amount /= 4;
console.info(`${amount}`);  // 25

// modulo assignment
let compoundValue: number = 17;
compoundValue %= 5;
console.info(`${compoundValue}`);  // 2

// exponentiation assignment
let compoundBase: number = 2;
compoundBase **= 4;
console.info(`${compoundBase}`);  // 16
```

## Comparison Operators

Comparison operators determine the relationship between values and return a Boolean result.

### Equality Operator (===)

Strict equality (===) returns true when both the value and the type are the same.

<!-- @[strict_equality_operator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
// Numeric comparison
let eqA: number = 5;
let eqB: number = 5;
console.info(`${eqA === eqB}`);     // true

// Different values
let eqNum1: number = 5;
let eqNum2: number = 10;
console.info(`${eqNum1 === eqNum2}`); // false

// Compare object references
class EqPoint {
  public x: number;
  public y: number;
  constructor(x: number, y: number) {
    this.x = x;
    this.y = y;
  }
}

let p1: EqPoint = new EqPoint(1, 2);
let p2: EqPoint = new EqPoint(1, 2);
console.info(`${p1 === p2}`);  // false (different objects)
```

### Not Equal Operator (!==)

Strict inequality (!==) returns true when the values or types differ.

<!-- @[strict_inequality_operator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let neA: number = 5;
let neB: number = 3;
console.info(`${neA !== neB}`);     // true

let neNum1: number = 5;
let neNum2: number = 10;
console.info(`${neNum1 !== neNum2}`); // true
```

### Greater Than Operator (>)

The greater than operator (>) returns true when the value on the left is greater than the value on the right.

<!-- @[greater_than_operator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let gtA: number = 10;
let gtB: number = 5;

console.info(`${gtA > gtB}`);   // true
console.info(`${gtB > gtA}`);   // false
console.info(`${gtA > gtA}`);   // false

// Compare strings by Unicode code points.
console.info(`${'gtB' > 'gtA'}`);     // true
console.info(`${'abc' > 'abb'}`); // true
```

### Less-Than Operator (<)

The less-than operator (<) returns true when the value on the left is less than the value on the right.

<!-- @[less_than_operator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let ltA: number = 10;
let ltB: number = 5;

console.info(`${ltA < ltB}`);   // false
console.info(`${ltB < ltA}`);   // true
console.info(`${ltA < ltA}`);   // false
```

### Greater Than or Equal To Operator (>=)

The greater than or equal to operator (>=) returns true when the value on the left is greater than or equal to the value on the right.

<!-- @[greater_than_or_equal_operator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let gteA: number = 10;
let gteB: number = 5;
let c: number = 10;

console.info(`${gteA >= gteB}`);  // true
console.info(`${gteA >= c}`);  // true
console.info(`${gteB >= gteA}`);  // false
```

### Less Than or Equal To Operator (<=)

The less than or equal to (<=) operator returns true when the value on the left is less than or equal to the value on the right.

<!-- @[less_than_or_equal_operator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let lteA: number = 10;
let lteB: number = 5;
let lteC: number = 10;

console.info(`${lteA <= lteB}`);  // false
console.info(`${lteA <= lteC}`);  // true
console.info(`${lteB <= lteA}`);  // true
```

### Comparing Tuples

Arrays and tuples do not have built-in element-wise equality comparison; `===` compares references rather than contents. When comparing manually, first check that the lengths are equal, and then compare each element by index.

<!-- @[tuple_comparison](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
function compareTuples(a: number[], b: number[]): boolean {
  if (a.length !== b.length) {
    return false;
  }
  for (let i: number = 0; i < a.length; i++) {
    if (a[i] !== b[i]) {
      return false;
    }
  }
  return true;
}

let tuple1: number[] = [1, 2];
let tuple2: number[] = [1, 2];
console.info(`${compareTuples(tuple1, tuple2)}`);  // true
```

## Ternary Conditional Operator

The ternary conditional operator selects one of two values as the result based on the Boolean value of a conditional expression. It is a concise form of if-else and is suitable for simple conditional assignment scenarios.

``` TypeScript
condition ? true value : false value
```

<!-- @[ternary_conditional_operator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let age: number = 20;
let status: string = age >= 18 ? 'adult' : 'minor';

let score: number = 85;
let result: string = score >= 60 ? 'pass' : 'fail';

// Nested ternary operator
let grade: string = 
  score >= 90 ? 'A' :
  score >= 80 ? 'B' :
  score >= 70 ? 'C' :
  score >= 60 ? 'D' : 'F';

// Function return
function getStatus(code: number): string {
  return code === 200 ? 'OK' : 'Error';
}

// Conditional assignment
let isAdmin: boolean = true;
let role: string = isAdmin ? 'admin' : 'user';
```

## Nullish Coalescing Operator

The nullish coalescing operator ?? provides a default value and handles null and undefined.

<!-- @[nullish_coalescing_operator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let coalesceValue: string | null = null;
let coalesceResult: string = coalesceValue ?? 'default';
console.info(`${coalesceResult}`);  // "default"

let value2: string = 'hello';
let result2: string = value2 ?? 'default';  // "hello"

// Difference from ||
let count: number = 0;
let text: string = '';
let flag: boolean = false;

// || replaces falsy values
let withOr1: number = count || 10;     // 10 (0 is falsy)
let withOr2: string = text || 'default'; // 'default'

// ?? replaces only null/undefined
let withNullCoalesce1: number = count ?? 10;      // 0 (0 is retained)
let withNullCoalesce2: string = text ?? 'default'; // '' (empty string is retained)

// Chained nullish coalescing
let primary: string | null = null;
let secondary: string | null = null;
let fallback: string = 'default';

let result3: string = primary ?? secondary ?? fallback;
console.info(`${result3}`);  // "default"
```

## Simulating Range Checks

A range check determines whether a value falls within a range, and is used for range validation.

### Closed Interval Check

A closed interval check uses `>=` and `<=` to check whether a value is within a specified range, including both boundary values.

<!-- @[closed_range_check](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
function inClosedRange(checkValue: number, min: number, max: number): boolean {
  return checkValue >= min && checkValue <= max;
}

let checkValue: number = 50;
let inRange: boolean = inClosedRange(checkValue, 10, 100);  // true
```

### Half-Open Interval Check

A half-open interval check determines whether a value falls within a range that includes the start but excludes the end.

<!-- @[half_open_range_check](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
function inHalfOpenRange(checkValue2: number, min: number, max: number): boolean {
  return checkValue2 >= min && checkValue2 < max;
}

let checkValue2: number = 100;
let checkInRange: boolean = inHalfOpenRange(checkValue2, 10, 100);  // false
```

### One-Sided Range Check

A one-sided range check checks whether a value is greater than or less than a boundary.

<!-- @[single_boundary_check](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
function aboveMin(checkValue3: number, min: number): boolean {
  return checkValue3 >= min;
}

function belowMax(checkValue3: number, max: number): boolean {
  return checkValue3 <= max;
}

let checkValue3: number = 150;
let isAbove: boolean = aboveMin(checkValue3, 100);  // true
let isBelow: boolean = belowMax(checkValue3, 200);  // true
```

## Logical Operators

Logical operators include NOT (!), AND (&&), and OR (||). They perform logical operations on Boolean values and support short-circuit evaluation.

### Logical NOT Operator (!)

The logical NOT operator (!) converts `true` to `false` and `false` to `true`.

<!-- @[logical_not_operator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let isA: boolean = true;
let isB: boolean = false;

console.info(`${!isA}`);  // false
console.info(`${!isB}`);  // true

// Convert double negation to a Boolean value.
let notValue: number = 5;
console.info(`${!!notValue}`);  // true (equivalent to Boolean(notValue))
```

### Logical AND Operator (&&)

The logical AND (&&) returns true only when both operands are true. When the left operand is false, the right operand is skipped due to short-circuit evaluation.

<!-- @[logical_and_operator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let andA: boolean = true;
let andB: boolean = true;
let andC: boolean = false;

console.info(`${andA && andB}`);  // true
console.info(`${andA && andC}`);  // false

// Truth table
// true && true   → true
// true && false  → false
// false && true  → false
// false && false → false

// Condition check
let andAge: number = 25;
let hasLicense: boolean = true;
let hasInsurance: boolean = true;

let canDrive: boolean = andAge >= 18 && hasLicense && hasInsurance;
```

### Logical OR Operator (||)

The logical OR (||) returns true if either side is true, and short-circuits to skip the right side when the left side is true.

<!-- @[logical_or_operator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let orA: boolean = true;
let orB: boolean = false;
let orC: boolean = false;

console.info(`${orA || orB}`);  // true
console.info(`${orB || orC}`);  // false

// Truth table
// true || true   → true
// true || false  → true
// false || true  → true
// false || false → false

// Either condition is met.
let orRole: string = 'admin';
let hasPermission: boolean = true;

let canAccess: boolean = orRole === 'admin' || hasPermission;
```

### Combining Logical Operators

Logical operators can be combined to implement complex conditions. Pay attention to precedence and short-circuit evaluation.

<!-- @[boolean_logic_combination](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let boolLogAge: number = 25;
let boolLogHasLicense: boolean = true;
let isGuest: boolean = false;

// All conditions must be met.
let boolLogCanDrive: boolean = boolLogAge >= 18 && boolLogHasLicense;

// Any condition is met.
let hasAccess: boolean = isGuest || boolLogHasLicense;

// Compound condition.
let canRentCar: boolean = boolLogAge >= 21 && (boolLogHasLicense || isGuest);

// Exclusion condition
let userStatus: string = 'active';
let isInactive: boolean = !(userStatus === 'active');

// Apply De Morgan's law
let invalid: boolean = !(boolLogHasLicense && boolLogAge >= 18);
// Equivalent to
let invalid2: boolean = !boolLogHasLicense || boolLogAge < 18;
```

### Short-Circuit Evaluation

The logical AND (&&) and logical OR (||) operators skip the evaluation of the right-hand side when the left-hand side already determines the result.

<!-- @[short_circuit_evaluation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
// && short-circuit: the right side is not executed when the left side is false.
function expensiveCheck(): boolean {
  console.info('Performing complex check');
  return true;
}

let enabled: boolean = false;
let circuitResult: boolean = enabled && expensiveCheck();  // expensiveCheck is not executed.

// || short-circuit: if the left side is true, the right side is not evaluated.
function fallbackValue(): string {
  console.info('Use the default value.');
  return 'default';
}

let circuitPrimary: string | null = 'circuitPrimary';
let circuitValue: string = circuitPrimary !== null ? circuitPrimary : fallbackValue();  // fallbackValue is not executed.

// ?? short-circuit: if the left side is not null/undefined, the right side is not evaluated.
function expensiveDefault(): string {
  console.info('Perform the expensive default value calculation.');
  return 'default';
}

let provided: string = 'text';
let circuitResult2: string = provided ?? expensiveDefault();  // expensiveDefault is not executed.
```

## Operator Precedence

Use parentheses to explicitly indicate the operation precedence and avoid ambiguity caused by relying on default rules.

<!-- @[parentheses_for_precedence](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let precA: number = 5;
let precB: number = 3;
let precC: number = 10;
let precD: number = 2;
let precInput: string | null = 'hello';
// Use parentheses to clarify the precedence.
let precResult: number = (precA + precB) * (precC - precD);
let valid: boolean = (precA > precB) && (precC < precD);
let precValue: string = (precInput ?? 'default') + ' suffix';
```

## Increment and Decrement Operators

The increment (++) and decrement (--) operators add 1 to or subtract 1 from a numeric value. The prefix form changes the value before use, while the postfix form uses the value before changing it.

<!-- @[increment_decrement_operators](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let decrCount: number = 5;

// Pre-increment: increment first, then use.
let preInc: number = ++decrCount;  // decrCount=6, preInc=6

// Post-increment: use first, then increment.
let postInc: number = decrCount++; // decrCount=7, postInc=6

// Pre-decrement
let preDec: number = --decrCount;  // decrCount=6, preDec=6

// Postfix decrement.
let postDec: number = decrCount--; // decrCount=5, postDec=6
```

## Optional Chaining Operator

The optional chaining operator (?. ) safely accesses a property when it may be null/undefined, avoiding runtime errors.

<!-- @[optional_chaining_operator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
class User {
  public profile: Profile | null = null;
}

class Profile {
  public nickname: string = '';
}

let user: User | null = new User();

// Safely access a property chain.
let nickname: string | undefined = user?.profile?.nickname;
console.info(`${nickname}`);  // undefined

// Access a method.
class Service {
  public getData(): string {
    return 'data';
  }
}
function getService(): Service | null {
  return null;
}
let service: Service | null = getService();
let data: string | null | undefined = service?.getData();

// Access an array element.
function getArr(): number[] | null {
  return null;
}
let arr: number[] | null = getArr();
let first: number | undefined = arr !== null ? arr[0] : undefined;

// Combined with nullish coalescing
let display: string = user?.profile?.nickname ?? 'Unknown';
```

## ArkTS Constraints

ArkTS supports loose equality (`==`), but its use is not recommended. Use strict equality (`===`) instead to avoid implicit type conversion.

### Discouraged Use of Loose Equality

ArkTS supports loose equality with `==` and `!=`, but their use is discouraged. Use strict equality with `===` and `!==` instead to avoid potential issues caused by implicit type conversion.

<!-- @[loose_equality_not_recommended](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let inputValue: string | null = null;
let itemCount: number = 0;
if (inputValue == null) { }
if (itemCount == 0) { }
```

Use strict equality:

<!-- @[strict_equality_preferred](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let eqValue: string | null = null;
let eqCount: number = 0;
// Recommended: use strict equality.
if (eqValue === null) { }
if (eqCount === 0) { }
```

### Destructuring Assignment Not Supported

ArkTS does not support destructuring assignment. You need to retrieve elements one by one by index and assign them separately.

<!-- @[ts_no_destructuring_supported](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Operators.ts) -->

``` TypeScript
// Not supported
let point = { x: 1, y: 2 };
let arr: number[] = [1, 2];
let [a1, b1] = [1, 2];
let {x, y} = point;

// Correct: assign separately
let a2: number = arr[0] ?? 0;
let b2: number = arr[1] ?? 0;
```

### Types Must Match

ArkTS requires that the operands on both sides of an operator have the same type or be deterministically compatible at compile time; otherwise, a compilation error is reported. For example, `5 > '5'` reports an error because the `number` and `string` types do not match. This restriction avoids the unexpected runtime behavior caused by implicit type conversion in JavaScript.

**Example (incorrect)**

<!-- @[ts_static_type_checking](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Operators.ts) -->

``` TypeScript
let num: number = 5;
num = 'text';  // Compilation error.
```