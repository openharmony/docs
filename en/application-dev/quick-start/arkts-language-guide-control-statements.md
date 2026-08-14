# Control Statements

<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=c25b60c237b212cfc232b5aee67d2c42ba90278a translatedAt=2026-08-13T08:55:36.383Z pushedAt=2026-08-13T12:47:57.808Z -->

Control statements control the execution flow of a program. ArkTS provides branch statements, loop statements, and jump statements to implement complex logic control.

## Branch Statements

Branch statements select different execution paths based on conditions.

### if Statement

The `if` statement executes the corresponding code block when the condition is true. It can be used with `else if` and `else` to handle multi-branch scenarios.

<!-- @[basic_if_statement](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
let score: number = 85;

if (score >= 60) {
  console.info('Passed');
}

let age: number = 25;
if (age >= 18) {
  console.info('Adult');
}

let enabled: boolean = true;
if (enabled) {
  startService();
}

function startService(): void {
  console.info('Service started');
}
```

When multiple mutually exclusive conditions need to be handled, use `else if` to chain multiple judgment branches:

<!-- @[if_else_if_chain](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
let chainScore: number = 85;

if (chainScore >= 90) {
  console.info('Excellent');
} else if (chainScore >= 80) {
  console.info('Good');
} else if (chainScore >= 60) {
  console.info('Pass');
} else {
  console.info('Fail');
}

let chainAge: number = 25;

if (chainAge < 13) {
  console.info('Child');
} else if (chainAge < 18) {
  console.info('Teenager');
} else if (chainAge < 60) {
  console.info('Adult');
} else {
  console.info('Senior');
}

// Combine multiple conditions
let role: string = 'admin';
let hasPermission: boolean = true;

if (role === 'admin') {
  console.info('Administrator permission');
} else if (role === 'user' && hasPermission) {
  console.info('User permission');
} else {
  console.info('No permission');
}
```

For simple scenarios where you only need to execute when the condition is met and do not need to handle other branches, you can omit the `else` part:

<!-- @[simple_condition_check](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
let value: number = 10;

// Only check the condition; no else needed.
if (value > 0) {
  console.info('Positive number');
}

// The else branch can be omitted if empty.
if (value < 0) {
  console.info('Negative number');
} else {
  // The empty branch can be omitted.
}

// Concise form.
if (value !== 0) {
  console.info('non-zero');
}
```

### switch Statement

The switch statement matches multiple case branches based on the value of an expression. It is suitable for multi-branch selection of discrete values and is clearer than multiple else if statements.

``` TypeScript
switch (expression) {
  case value1:
    // Execute the code.
    break;
  case value2:
    // Execute the code.
    break;
  default:
    // Execute the default code.
    break;
}
```

The following example shows the basic usage of `switch` through date and status matching:

<!-- @[switch_basic_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
let day: number = 3;

switch (day) {
  case 1:
    console.info('Monday');
    break;
  case 2:
    console.info('Tuesday');
    break;
  case 3:
    console.info('Wednesday');
    break;
  case 4:
    console.info('Thursday');
    break;
  case 5:
    console.info('Friday');
    break;
  case 6:
    console.info('Saturday');
    break;
  case 7:
    console.info('Sunday');
    break;
  default:
    console.info('Invalid date');
}

let status: string = 'active';

switch (status) {
  case 'active':
    console.info('Active state');
    break;
  case 'inactive':
    console.info('Inactive state');
    break;
  case 'pending':
    console.info('Pending state');
    break;
  default:
    console.info('Unknown state');
}
```

Multiple `case` labels can share the same block of execution logic to group values for matching:

<!-- @[switch_case_fallthrough](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
let fallValue: number = 5;

// TypeScript does not support: case 1, 2, 3:
Write them separately.
// Write them separately.

switch (fallValue) {
  case 1:
  case 2:
  case 3:
    console.info('Small value');
    break;
  case 4:
  case 5:
  case 6:
    console.info('Medium value');
    break;
  default:
    console.info('Large value');
}

let color: string = 'red';

switch (color) {
  case 'red':
  case 'yellow':
  case 'orange':
    console.info('Warm tone');
    break;
  case 'blue':
  case 'green':
  case 'purple':
    console.info('Cool tone');
    break;
  default:
    console.info('Other colors');
}
```

For range checks, `switch` and `if...else if` each have their applicable scenarios. The following example compares the two approaches:

<!-- @[switch_vs_if_range](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
let rangeScore: number = 85;

// Use if to implement range matching.
if (rangeScore >= 90 && rangeScore <= 100) {
  console.info('Grade A');
} else if (rangeScore >= 80 && rangeScore < 90) {
  console.info('Grade B');
} else if (rangeScore >= 70 && rangeScore < 80) {
  console.info('Grade C');
} else if (rangeScore >= 60 && rangeScore < 70) {
  console.info('Grade D');
} else {
  console.info('Grade F');
}

// Use switch mapping.
let grade: number = Math.floor(rangeScore / 10);

switch (grade) {
  case 10:
  case 9:
    console.info('Grade A');
    break;
  case 8:
    console.info('Grade B');
    break;
  case 7:
    console.info('Grade C');
    break;
  case 6:
    console.info('Grade D');
    break;
  default:
    console.info('Grade F');
}
```

switch can also be used with `typeof` or a discriminant field to handle union types, safely using the narrowed type within each `case` branch.

<!-- @[switch_typeof_matching](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
let stmValue: number | string | boolean = 'text';

switch (typeof stmValue) {
  case 'number':
    console.info(`Number: ${stmValue}`);
    break;
  case 'string':
    console.info(`String: ${stmValue}`);
    break;
  case 'boolean':
    console.info(`Boolean: ${stmValue}`);
    break;
  default:
    console.info('Unknown type');
}
```

Use an enum as the discriminant field, together with a unified interface, to branch by enum value in a `switch` statement.

<!-- @[switch_enum_matching](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
enum ShapeKind {
  Circle,
  Rectangle,
  Triangle
}

interface ShapeInfo {
  kind: ShapeKind;
  radius: number;
  width: number;
  height: number;
  base: number;
}

let semShape: ShapeInfo = { kind: ShapeKind.Circle, radius: 5, width: 0, height: 0, base: 0 };

switch (semShape.kind) {
  case ShapeKind.Circle:
    console.info(`Circle area: ${Math.PI * semShape.radius * semShape.radius}`);
    break;
  case ShapeKind.Rectangle:
    console.info(`Rectangle area: ${semShape.width * semShape.height}`);
    break;
  case ShapeKind.Triangle:
    console.info(`Triangle area: ${0.5 * semShape.base * semShape.height}`);
    break;
}
```

The `default` branch of `switch` is used to catch all unmatched cases, which is suitable for scenarios such as handling unknown commands:

<!-- @[switch_default_handling](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
let command: string = 'unknown';

switch (command) {
  case 'start':
    console.info('Start');
    break;
  case 'stop':
    console.info('Stop');
    break;
  case 'restart':
    console.info('Restart');
    break;
  default:
    console.info('Unknown command');
    handleUnknown(command);
}

function handleUnknown(cmd: string): void {
  console.info(`Handling unknown command: ${cmd}`);
}
```

The `break` statement controls whether `switch` falls through to the next case. Omitting `break` triggers fallthrough:

<!-- @[switch_break_fallthrough](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
let fallValue2: number = 1;

switch (fallValue2) {
  case 1:
    console.info('Match 1');
    break;  // A break is required; otherwise, execution falls through to the next case.
  case 2:
    console.info('Match 2');
    break;
  default:
    console.info('Default');
}

// Without break, execution continues.
switch (fallValue2) {
  case 1:
    console.info('One');
    // Without break, execution continues to case 2.
  case 2:
    console.info('Two');
    break;
  default:
    console.info('Default');
}
// Output: one, two.
```

## Loop Statements

A loop statement repeatedly executes a code block while the condition holds true. ArkTS provides several loop forms, including for, for...of, while, and do...while.

### for...of Loop

The for...of statement iterates over the elements of an iterable object. It features concise syntax, strong versatility, and type safety, and it does not iterate over properties on the prototype chain.

<!-- @[for_of_iteration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
// Iterate over the array.
let numbers: number[] = [1, 2, 3, 4, 5];
for (let num of numbers) {
  console.info(`${num}`);
}

// Iterate over the string.
let text: string = 'Hello';
for (let char of text) {
  console.info(`${char}`);
}

// Iterate over the Set.
let set: Set<number> = new Set<number>();
set.add(1);
set.add(2);
set.add(3);
for (let value of set) {
  console.info(`${value}`);
}

// Iterate over the Map.
let map: Map<string, number> = new Map<string, number>();
map.set('a', 1);
map.set('b', 2);
map.set('c', 3);

for (let key of map.keys()) {
  let mapValue: number | undefined = map.get(key);
  if (mapValue !== undefined) {
    console.info(`Key: ${key}, Value: ${mapValue}`);
  }
}

// Iterate over the values of the Map.
for (let value of map.values()) {
  console.info(`${value}`);
}

// Iterate over the keys of the Map.
for (let key of map.keys()) {
  console.info(`${key}`);
}
```

When iterating over the key-value pairs of `Map`, ArkTS does not support destructuring syntax. You need to extract the key and value from `entry` separately by index:

<!-- @[for_of_key_value_pairs](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
// TypeScript supports: for (let [key, value] of pairsMap)
// ArkTS requires separate extraction.

let pairsMap: Map<string, number> = new Map([
  ['a', 1],
  ['b', 2]
]);

for (let entry of pairsMap) {
  let key: string = entry[0];
  let value: number = entry[1];
  console.info(`${key}: ${value}`);
}

// Array iteration (no destructuring required).
let pairs: number[][] = [[1, 2], [3, 4], [5, 6]];
for (let pair of pairs) {
  let first: number = pair[0];
  let second: number = pair[1];
  console.info(`${first}, ${second}`);
}
```

### for...in Loop

`for...in` iterates over the **property keys** of an object (including inherited enumerable properties), unlike `for...of`, which iterates over **values**. The iteration order of `for...in` is not guaranteed to be fixed, and when iterating over an array it returns string indices (such as `"0"` instead of `0`), which can easily lead to type and logic errors. ArkTS does not support `for...in` (`arkts-no-for-in`). For details, see [TypeScript to ArkTS Cookbook](typescript-to-arkts-migration-guide.md#for--in-is-not-supported). To iterate over an array, use `for...of` or `forEach`; to iterate over object keys, use `Object.keys()`.

**TypeScript Comparison**

<!-- @[ts_for_in_loop](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Control.ts) -->

``` TypeScript
// TypeScript equivalent (ArkTS does not support for...in)
// for...in iterates over an object and returns its property keys
let finObj: Record<string, number> = { 'a': 1, 'b': 2, 'c': 3 };
for (let key in finObj) {
  console.info(`${key}: ${finObj[key]}`); // a: 1, b: 2, c: 3
}

// for...in iterates over an array and returns string indexes ("0" instead of 0)
let finArr: number[] = [10, 20, 30];
for (let index in finArr) {
  console.info(`${index}`); // "0", "1", "2" (string indexes, not numeric values)
}
```

> **NOTE**
> 
> `for...in` returns the key names (strings), while `for...of` returns the values. To iterate over an array, use `for...of` or `forEach`. To iterate over the key names of an object, use `Object.keys()`.

### for Loop (Traditional Counter-Based)

The traditional `for` loop uses a counter to control the loop and consists of three parts: initialization, condition evaluation, and iteration.

The execution flow is as follows: first, the initialization expression is executed (only once); then the condition expression is evaluated (the loop continues if it is `true` and exits if it is `false`); then the loop body is executed; and after the iteration expression is executed, the flow returns to the condition evaluation.

<!-- @[traditional_for_loop](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
// Basic structure
for (let i: number = 0; i < 5; i++) {
  console.info(`${i}`);
}

// Initialization: let i = 0
// Condition: i < 5
// Increment: i++

// Reverse loop
for (let i: number = 5; i >= 0; i--) {
  console.info(`${i}`);
}

// Step of 2
for (let i: number = 0; i < 10; i += 2) {
  console.info(`${i}`);
}

// Iterate over array indices
let arr: number[] = [10, 20, 30, 40, 50];
for (let i: number = 0; i < arr.length; i++) {
  console.info(`Index ${i}: ${arr[i] ?? 0}`);
}

// Multi-variable loop
for (let i: number = 0, j = 10; i < j; i++, j--) {
  console.info(`i=${i}, j=${j}`);
}
```

With a counter variable, a `for` loop can also iterate over a specified range:

<!-- @[iterate_range_numbers](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
// Iterate over a specified range
function range(start: number, end: number): number[] {
  let result: number[] = [];
  for (let i: number = start; i < end; i++) {
    result.push(i);
  }
  return result;
}

let numsNumbers: number[] = range(1, 10);
for (let num of numsNumbers) {
  console.info(`${num}`);
}

// Iterate over odd numbers in the range
for (let i: number = 1; i <= 20; i += 2) {
  console.info(`${i}`);
}

// Iterate over even numbers in the range.
for (let i: number = 2; i <= 20; i += 2) {
  console.info(`${i}`);
}
```

### while Loop

A `while` loop evaluates the condition first and then executes the loop body. It is a condition-controlled loop statement.

``` TypeScript
while (condition) {
  // Loop body code.
  // Note: Update the condition variable inside the loop body.
}
```

`while` is suitable for scenarios where the number of iterations cannot be determined at compile time, where iteration is based on a specific condition (such as a non-empty queue), where a condition is awaited (such as polling), or where the loop condition needs to be adjusted dynamically.

<!-- @[while_loop_basic](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
// Basic structure
let count: number = 0;
while (count < 5) {
  console.info(`${count.toString()}`);
  count++;
}

// Skip the loop body when the condition is false.
let loopValue: number = 10;
while (loopValue < 5) {
  console.info(`${loopValue.toString()}`);  // Not executed.
  loopValue++;
}

// Process data until the condition is met.
let data: string | null = 'data';
while (data !== null) {
  console.info(`${data}`);
  data = getNextData();
}

function getNextData(): string | null {
  // Return data or null.
  return null;
}

// Accumulate until the condition is met.
let sum: number = 0;
let i: number = 1;
while (sum < 100) {
  sum += i;
  i++;
}
console.info(`Accumulated to ${sum}`);
```

### do...while Loop

The do...while loop executes the loop body first and then re-evaluates the condition. It is suitable for scenarios that require execution before evaluation, such as user input validation (asking at least once), resource acquisition (attempting at least once), and status checking. The execution flow is as follows: the loop body is executed first, then the condition expression is evaluated. If the condition is true, execution continues; if it is false, the loop exits.

<!-- @[do_while_loop](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
// Basic structure: execute at least once.
let loopCount: number = 0;
do {
  console.info(`${loopCount.toString()}`);
  loopCount++;
} while (loopCount < 5);

// Execute once even if the condition is initially false.
let loopValue2: number = 10;
do {
  console.info(`${loopValue2.toString()}`);  // Execute once and output 10.
  loopValue2++;
} while (loopValue2 < 5);

// Validate user input.
let input: string = '';
do {
  input = getInput();
} while (input.length === 0);

function getInput(): string {
  return 'valid input';
}

// Retry logic.
let success: boolean = false;
let attempts: number = 0;
do {
  success = tryConnect();
  attempts++;
} while (!success && attempts < 3);

function tryConnect(): boolean {
  return true;
}
```

## Jump Statements

Jump statements are used to alter the execution flow of a loop or a function.

### break Statement

`break` is used to exit a loop or a `switch` statement, immediately terminating the execution of the current loop or branch.

`break` is commonly used to terminate a loop after an element is found, exit when a condition is met, break out when an error occurs, and end meaningless loops early to optimize performance.

<!-- @[break_statement](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
// Exit the for loop.
for (let i: number = 0; i < 10; i++) {
  if (i === 5) {
    break;  // Exit the loop.
  }
  console.info(`${i.toString()}`);
}
// Output: 0, 1, 2, 3, 4

// Exit the while loop.
let breakCount: number = 0;
while (breakCount < 10) {
  if (breakCount === 5) {
    break;
  }
  console.info(`${breakCount.toString()}`);
  breakCount++;
}

// Exit after finding the element.
let breakNumbers: number[] = [1, 2, 3, 4, 5];
for (let num of breakNumbers) {
  if (num === 3) {
    console.info('Found 3');
    break;
  }
}
```

In a `switch` statement, `break` is also used to terminate the execution of the current branch:

<!-- @[break_in_switch](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
let switchValue: number = 2;

switch (switchValue) {
  case 1:
    console.info('One');
    break;  // Exit the switch
  case 2:
    console.info('Two');
    break;  // A break is required
  case 3:
    console.info('Three');
    break;
  default:
    console.info('Default');
}
```

In nested loops, a labeled `break` can directly exit the outer loop:

<!-- @[nested_loop_break](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
// Labeled break: exit the outer loop.
outerLoop: for (let i: number = 0; i < 10; i++) {
  for (let j: number = 0; j < 10; j++) {
    if (i + j === 15) {
      console.info(`Found: i=${i}, j=${j}`);
      break outerLoop;
    }
  }
}
```

### continue Statement

`continue` skips the current iteration and proceeds to the next one. It is an important statement for loop control.

`continue` is commonly used to filter invalid data, skip when a condition is met, avoid executing unnecessary code to optimize performance, and replace complex if-else nesting to simplify logic.

<!-- @[continue_statement](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
// Skip even numbers.
for (let i: number = 0; i < 10; i++) {
  if (i % 2 === 0) {
    continue;  // Skip even numbers.
  }
  console.info(`${i.toString()}`);
}
// Output: 1, 3, 5, 7, 9

// Skip specific values.
let continueNumbers: number[] = [1, 2, 3, 4, 5];
for (let num of continueNumbers) {
  if (num === 3) {
    continue;  // Skip 3.
  }
  console.info(`${num.toString()}`);
}
// Output: 1, 2, 4, 5

// Filter invalid data.
let continueData: (string | null)[] = ['valid', '', 'valid', null, 'valid'];
for (let item of continueData) {
  if (item === '' || item === null) {
    continue;  // Skip null values.
  }
  processItem(item);
}

function processItem(item: string): void {
  console.info(`Processing: ${item}`);
}
```

Similarly, `continue` also supports the label syntax, which is used to skip the current iteration of the outer loop:

<!-- @[nested_loop_continue](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
// Labeled continue: skip the current iteration of the outer loop.
outerLoop: for (let i: number = 0; i < 5; i++) {
  for (let j: number = 0; j < 5; j++) {
    if (j === 2) {
      continue outerLoop;
    }
    console.info(`i=${i}, j=${j}`);
  }
}
```

### return Statement (Control Flow Within a Function)

The `return` statement returns from a function, immediately terminating the function execution and handing control back to the caller while returning the specified value. Code after `return` is not executed. It is commonly used to return a computation result, exit early when a parameter is invalid, return different results based on conditions, and return error information when an error occurs.

<!-- @[return_statement](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
// Basic return
function add(a: number, b: number): number {
  return a + b;
}

let result: number = add(1, 2);

// Function with no return value
function log(message: string): void {
  console.info(`${message}`);
  return;  // Can be omitted
}

// Conditional return
function classify(value: number): string {
  if (value > 0) {
    return 'positive';
  } else if (value < 0) {
    return 'negative';
  }
  return 'zero';
}

// Early return
function validate(input: string): boolean {
  if (input.length === 0) {
    return false;  // Early return
  }
  if (input.length > 100) {
    return false;
  }
  return true;
}

// Return a complex type
function getUser(id: number): User | null {
  if (id <= 0) {
    return null;
  }
  return { id: id, name: 'User' };
}

interface User {
  id: number;
  name: string;
}
```

## Early Exit (Flow Control Within a Function)

Early exit means validating preconditions at the function entry and returning directly when they are not met, thereby avoiding deep nesting and keeping the main flow flat.

### Conditional return to Terminate Function Execution Early

At the function entry, validate the preconditions (parameter validity, permissions, and state). If they are not met, return directly to exit, avoiding deep nesting and keeping the main flow flat and clear.

<!-- @[early_exit_pattern](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
// Exit early after parameter validation.
function processData(data: string | null | undefined): void {
  if (data === null || data === undefined) {
    console.info('Invalid data.');
    return;  // Exit early.
  }
  
  // Normal processing.
  console.info(`Processing: ${data}`);
}

// Exit early after permission check.
function accessResource(user: PatternUser): void {
  if (!user.hasPermission) {
    console.info('No permission');
    return;
  }
  
  // Handle when permission is granted.
  loadResource();
}

function loadResource(): void {
  console.info('Loading resources');
}

interface PatternUser {
  hasPermission: boolean;
}

// Early exit after error handling
function safeDivide(a: number, b: number): number | null {
  if (b === 0) {
    console.info('The divisor cannot be zero');
    return null;  // Early exit, return null
  }
  
  return a / b;
}

// Early exit after boundary check
function getArrayElement(arr: number[], index: number): number | null {
  if (index < 0 || index >= arr.length) {
    return null;  // early exit
  }
  
  return arr[index];
}
```

### Early Exit Combined with Optional Value Checks

Return early when an optional value is null/undefined to avoid deep nesting.

<!-- @[null_undefined_check](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
// Handle optional parameters.
function greet(name: string | null): string {
  if (name === null) {
    return 'Hello, Guest';  // Early exit.
  }
  
  return `Hello, ${name}`;
}

// Handle optional chaining results.
function processConfig(config: Config | null): void {
  if (config === null) {
    console.info('Configuration does not exist');
    return;
  }
  
  if (config.value === undefined) {
    console.info('Configuration value is undefined');
    return;
  }
  
  console.info(`Configuration value: ${config.value}`);
}

interface Config {
  value: number | undefined;
}

// Multi-level null check
function deepProcess(data: Data | null): void {
  if (data === null) {
    return;
  }
  
  if (data.inner === null) {
    return;
  }
  
  if (data.inner.value === null) {
    return;
  }
  
  console.info(`${data.inner.value}`);
}

interface Data {
  inner: Inner | null;
}

interface Inner {
  value: string | null;
}
```

## Detecting API Availability

In HarmonyOS multi-version and multi-device scenarios, some APIs may be available only on specific versions or devices. Detecting API availability at runtime ensures backward compatibility: use the new implementation when the new API is available, and fall back to the compatible implementation when it is not.

### Runtime Environment Detection

Determine the current runtime environment by checking whether object methods exist using `typeof`.

<!-- @[check_object_method_existence](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
// Check the global object.
function checkEnvironment(): void {
  if (typeof console !== 'undefined') {
    console.info('console available');
  }
  
  if (typeof setTimeout !== 'undefined') {
    console.info('setTimeout available');
  }
}

class OptionalWorker {
  public methodName?: () => void;
}

// Check whether the method exists.
function safeCall(): void {
  let obj: OptionalWorker = new OptionalWorker();
  
  if (obj.methodName !== undefined) {
    obj.methodName();
  } else {
    console.info('The method does not exist.');
  }
}

// Use type checking in ArkTS.
interface Feature {
  newMethod?(): void;
}

function useFeature(feature: Feature): void {
  if (feature.newMethod !== undefined) {
    feature.newMethod();
  } else {
    console.info('Use the legacy method.');
    fallbackMethod();
  }
}

function fallbackMethod(): void {
  console.info('Fallback method.');
}
```

### Feature Compatibility Check

At runtime, determine whether the current environment supports a feature based on the version number or a feature flag, and branch between the new implementation and the compatible legacy implementation accordingly to ensure backward compatibility.

<!-- @[version_feature_platform_check](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
// Check the version.
function checkVersion(): void {
  const MIN_VERSION: number = 2;
  let currentVersion: number = getCurrentVersion();
  
  if (currentVersion < MIN_VERSION) {
    console.info('// The version is too old; use the compatible solution.');
    useLegacyImplementation();
  } else {
    useNewImplementation();
  }
}

function getCurrentVersion(): number {
  return 3;
}

function useLegacyImplementation(): void {
  console.info('// Use the legacy implementation.');
}

function useNewImplementation(): void {
  console.info('Use the new implementation');
}

// Feature switch
function processWithOptions(options: ProcessOptions): void {
  if (options.useNewFeature) {
    processNewWay();
  } else {
    processOldWay();
  }
}

interface ProcessOptions {
  useNewFeature: boolean;
}

function processNewWay(): void {
  console.info('Process in the new way');
}

function processOldWay(): void {
  console.info('Process in the old way');
}

// Platform detection
function detectPlatform(): string {
  let platform: string = getPlatform();
  
  switch (platform) {
    case 'mobile':
      configureForMobile();
      break;
    case 'desktop':
      configureForDesktop();
      break;
    case 'web':
      configureForWeb();
      break;
    default:
      useDefaultConfig();
  }
  
  return platform;
}

function getPlatform(): string {
  return 'mobile';
}

function configureForMobile(): void {
  console.info('Mobile configuration');
}

function configureForDesktop(): void {
  console.info('Desktop configuration');
}

function configureForWeb(): void {
  console.info('Web configuration');
}

function useDefaultConfig(): void {
  console.info('Default configuration');
}
```