# Enums

<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=c25b60c237b212cfc232b5aee67d2c42ba90278a translatedAt=2026-08-13T08:57:17.197Z pushedAt=2026-08-13T15:15:10.613Z -->

An enum is a type that defines a set of named constants. Enums make code clearer and easier to maintain by avoiding magic numbers or strings.

## Basic Declaration of Enum

An enum is declared using the `enum` keyword and comes in two forms: numeric enum and string enum. Members of a numeric enum increment from 0, and an initial value can also be explicitly specified. Each member of a string enum must be explicitly assigned a value.

### Enum Syntax

Use the `enum` keyword followed by the enum name, and declare members within curly braces. Members are named in PascalCase. Numeric enum members without an initializer start from 0 and increment automatically.

``` TypeScript
enum EnumName {
  Member1,
  Member2,
  Member3
}
```

A numeric enum is an enum whose member values are of the number type. By default, its members start from 0 and increment automatically, but you can also specify an initial value manually.

A string enum is an enum whose member values are of the string type. You must explicitly assign a value to each member. Automatic increment and reverse mapping are not supported.

Enums provide type safety and readability: illegal member values are rejected at compile time, semantic names replace magic numbers, related constants are defined together for easier maintenance, and DevEco Studio can provide member suggestions.

<!-- @[basic_enum_declaration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Enums.ets) -->

``` TypeScript
// Basic enum declaration
enum Direction {
  Up,
  Down,
  Left,
  Right
}

// Use the enum
let dir: Direction = Direction.Up;
let moveDir: Direction = Direction.Down;

console.info(`${dir}`);   // 0
console.info(`${moveDir}`);  // 1

// Compare enums
if (dir === Direction.Up) {
  console.info('Move up');
}

// Enum as a function parameter
function declarationMove(direction: Direction): void {
  switch (direction) {
    case Direction.Up:
      console.info('Up');
      break;
    case Direction.Down:
      console.info('Down');
      break;
    case Direction.Left:
      console.info('Left');
      break;
    case Direction.Right:
      console.info('Right');
      break;
  }
}

declarationMove(Direction.Up);  // Up

// Enum as a return value.
function getDefaultDirection(): Direction {
  return Direction.Right;
}

let defaultDir: Direction = getDefaultDirection();
```

### Naming Conventions for Enum Members

Enum members should be named in PascalCase, avoid abbreviations, and use semantically meaningful names that clearly express their meaning.

<!-- @[enum_naming_conventions](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Enums.ets) -->

``` TypeScript
// Enum name: PascalCase
enum UserRole {
  Admin,      // PascalCase
  Moderator,
  RegularUser
}

enum HttpStatus {
  OK,
  NotFound,
  InternalServerError
}

// Avoid abbreviations; use complete words.
enum Color {
  Red,        // Recommended
  Green,
  Blue
}

// Counterexample
enum Clr {
  R,    // Counterexample: abbreviation
  G,
  B
}

// Semantic naming
enum PaymentStatus {
  Pending,     // Pending payment
  Processing,  // Processing
  Completed,   // Completed.
  Failed,      // Failed.
  Cancelled    // Cancelled.
}

// Use enum as a type.
function updateStatus(status: PaymentStatus): void {
  console.info(`Status updated to: ${status}`);
}

updateStatus(PaymentStatus.Completed);
```

### Definition and Use of Enums Without Initializers

Members of an enum without initializers carry no initial value and are automatically incremented starting from 0.

<!-- @[numeric_enum_auto_increment](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Enums.ets) -->

``` TypeScript
// Enum without initializers (default numeric enum)
enum Size {
  Small,   // 0
  Medium,  // 1
  Large    // 2
}

let size: Size = Size.Small;
console.info(`${size}`);  // 0

// Numeric enum auto-increment
enum Level {
  Low,     // 0
  Medium,  // 1
  High,    // 2
  Critical // 3
}

console.info(`${Level.Low}`);      // 0
console.info(`${Level.Medium}`);   // 1
console.info(`${Level.High}`);     // 2
console.info(`${Level.Critical}`); // 3

// Use a numeric enum
function getPriority(level: Level): number {
  let priority: number;
  switch (level) {
    case Level.Low:
      priority = 1;
      break;
    case Level.Medium:
      priority = 5;
      break;
    case Level.High:
      priority = 10;
      break;
    case Level.Critical:
      priority = 100;
      break;
    default:
      priority = 0;
  }
  return priority;
}

getPriority(Level.High);  // 10
```

## Enums with Initializers

Enum members can be associated with numeric or string values as initializers, for serialization, persistence, or interfacing with external systems.

### Initializer Type Constraints (String, Numeric, and Others)

An enum member can be associated with a string or a number as its initializer, but all members in the same enum must use the same initializer type. Mixing strings and numbers causes a compilation error.

Access a member value through the enum name. A numeric enum supports reverse mapping (member name ↔ value), while a string enum supports only forward mapping.

<!-- @[ts_string_and_numeric_enum](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Enums.ts) -->

``` TypeScript
// String enum
enum Status {
  Pending = 'pending',
  Active = 'active',
  Completed = 'completed',
  Failed = 'failed'
}

let status: Status = Status.Pending;
console.info(`${status}`);  // 'pending'

// Numeric enum (explicit values)
enum Priority {
  Low = 1,
  Medium = 2,
  High = 3,
  Critical = 10
}

let priority: Priority = Priority.High;
console.info(`${priority.toString()}`);  // 3

// ArkTS does not use mixed enums: members in the same enum must keep the same initializer type.
enum Mixed {
  No = 0,
  Yes = 'YES'  // Compilation error: the member initializer types are inconsistent.
}
```

### Automatic Assignment of Initializers (Numeric Auto-Increment and String Same-Name)

Automatic assignment of initializers means that, in a numeric enum, members without an explicit initializer automatically receive an incremented numeric value, starting from 0 or continuing to increment from the previous explicit value.

<!-- @[enum_auto_increment_rules](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Enums.ets) -->

``` TypeScript
// Numeric enum auto-increment.
enum AutoNumberEnum {
  First,    // 0 (automatic)
  Second,   // 1 (automatic)
  Third,    // 2 (automatic)
  Custom = 10,
  Fourth,   // 11 (continues from Custom)
  Fifth     // 12
}

console.info(`${AutoNumberEnum.First}`);    // 0
console.info(`${AutoNumberEnum.Second}`);   // 1
console.info(`${AutoNumberEnum.Third}`);    // 2
console.info(`${AutoNumberEnum.Custom}`);   // 10
console.info(`${AutoNumberEnum.Fourth}`);   // 11
console.info(`${AutoNumberEnum.Fifth}`);    // 12

// A string enum must be explicitly initialized.
enum AutoStringEnum {
  A = 'A',
  B = 'B',
  C = 'C'
}
```

### Bidirectional Mapping Between Initializers and Enum Members

Bidirectional mapping between initializers and enum members means that you can obtain the initializer through an enum member, and also obtain the enum member name through the initializer.

<!-- @[enum_bidirectional_mapping](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Enums.ets) -->

``` TypeScript
// Numeric enums support bidirectional mapping.
enum BiNumberEnum {
  Zero,
  One,
  Two
}

let biEnumName: string = BiNumberEnum[0];   // 'Zero'
let biValue: number = BiNumberEnum.One;     // 1

console.info(`${biEnumName}`);   // Zero
console.info(`${biValue}`);      // 1

// String enums do not support reverse mapping.
enum BiStringEnum {
  A = 'A',
  B = 'B'
}

let biA: BiStringEnum = BiStringEnum.A;  // 'A'

// Example of bidirectional mapping.
enum BiUserRole {
  Admin = 100,
  Moderator = 200,
  User = 300
}

let biRole: BiUserRole = BiUserRole.Admin;     // 100
let biRoleName: string = BiUserRole[100];      // 'Admin'

function getBiRoleName(roleId: number): string | undefined {
  return BiUserRole[roleId];
}

console.info(`${getBiRoleName(100)}`);  // Admin
console.info(`${getBiRoleName(200)}`);  // Moderator
```

### Initializing Enums with Initializers

To look up the corresponding enum member from an externally passed string or number, you typically use a switch to match each initializer one by one and return the corresponding member, returning undefined when there is no match. This implements reverse initialization from an initializer to an enum.

<!-- @[parse_enum_from_value](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Enums.ets) -->

``` TypeScript
// Create an enum value from a string.
function parseStatus(statusStr: string): Status | undefined {
  switch (statusStr) {
    case 'pending':
      return Status.Pending;
    case 'active':
      return Status.Active;
    case 'completed':
      return Status.Completed;
    case 'failed':
      return Status.Failed;
    default:
      return undefined;
  }
}

enum Status {
  Pending = 'pending',
  Active = 'active',
  Completed = 'completed',
  Failed = 'failed'
}

let parsed: Status | undefined = parseStatus('active');
if (parsed !== undefined) {
  console.info(`${parsed}`);  // active
}

// Create an enum value from a number.
function getPriorityByValue(value: number): Priority | undefined {
  switch (value) {
    case 1:
      return Priority.Low;
    case 2:
      return Priority.Medium;
    case 3:
      return Priority.High;
    case 10:
      return Priority.Critical;
    default:
      return undefined;
  }
}

enum Priority {
  Low = 1,
  Medium = 2,
  High = 3,
  Critical = 10
}

let priority: Priority | undefined = getPriorityByValue(3);
if (priority !== undefined) {
  console.info(`${priority.toString()}`);
}
```

## Simulating Associated Value Patterns

TypeScript/ArkTS do not support enums with associated values (such as Swift's enum). To express a pattern where "different states carry different data", you can simulate it using objects or interfaces.

### Declaring Associated Data with Interface Unions

Associate respective data structures with different enum values through interface unions.

<!-- @[simulated_associated_values](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Enums.ets) -->

``` TypeScript
// TypeScript does not support enums with associated values.
// ArkTS uses interface unions to simulate different result shapes.

interface SuccessResult {
  success: true;
  value: number;
}

interface FailureResult {
  success: false;
  error: string;
}

type Result = SuccessResult | FailureResult;

let successResult: Result = { success: true, value: 42 };
let failureResult: Result = { success: false, error: 'Failed' };

function processResult(result: Result): void {
  if (result.success) {
    console.info(`Success, value: ${result.value}`);
  } else {
    console.info(`Failure, error: ${(result as FailureResult).error}`);
  }
}

processResult(successResult);
processResult(failureResult);

// Alternatively, use a more explicit discriminant field.
interface OperationSuccessResult {
  type: 'success';
  value: number;
}

interface OperationFailureResult {
  type: 'failure';
  error: string;
}

type OperationResult = OperationSuccessResult | OperationFailureResult;

let success: OperationResult = { type: 'success', value: 100 };
let failure: OperationResult = { type: 'failure', error: 'Error' };
```

### Defining Data Types for Different States

Define a separate interface for each state and combine them through a union type.

<!-- @[discriminated_union_message_types](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Enums.ets) -->

``` TypeScript
// Associated values of different types.
interface TextMessage {
  kind: 'text';
  content: string;
}

interface ImageMessage {
  kind: 'image';
  url: string;
  imageWidth: number;
  imageHeight: number;
}

interface VideoMessage {
  kind: 'video';
  url: string;
  duration: number;
}

type Message = TextMessage | ImageMessage | VideoMessage;

let textMessage: Message = { 
  kind: 'text', 
  content: 'Hello' 
};

let imageMessage: Message = { 
  kind: 'image', 
  url: 'EXAMPLE_IMAGE_URL',
  imageWidth: 800,
  imageHeight: 600
};

let videoMessage: Message = { 
  kind: 'video', 
  url: 'EXAMPLE_VIDEO_URL',
  duration: 120
};

// Handle messages of different types.
function handleMessage(message: Message): void {
  switch (message.kind) {
    case 'text':
      console.info(`Text: ${message.content}`);
      break;
    case 'image':
      console.info(`Image: ${message.url} (${message.imageWidth}x${message.imageHeight})`);
      break;
    case 'video':
      console.info(`Video: ${message.url} (${message.duration}s)`);
      break;
  }
}

handleMessage(textMessage);
handleMessage(imageMessage);
```

### Reading Associated Data

Use a discriminant field (such as success/type/kind) to distinguish objects of different shapes, and access the data of the corresponding field in the switch branch.

<!-- @[extract_associated_values](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Enums.ets) -->

``` TypeScript
// TypeScript supports: let { value } = result;
// ArkTS requires extracting it separately.

interface ExtractSuccessResult {
  success: true;
  value: number;
}

interface ExtractFailureResult {
  success: false;
  error: string;
}

type ExtractResult = ExtractSuccessResult | ExtractFailureResult;

function getValue(result: ExtractResult): number | undefined {
  if (result.success) {
    return result.value;  // Access it directly.
  }
  return undefined;
}

function getError(result: ExtractResult): string | undefined {
  if (result.success === false) {
    return (result as ExtractFailureResult).error;  // Access directly.
  }
  return undefined;
}

let result: ExtractResult = { success: true, value: 42 };

let value: number | undefined = getValue(result);
if (value !== undefined) {
  console.info(`${value.toString()}`);
}
```

### Handling Associated Data with switch Statements

Use switch to match enum values and access the corresponding associated data in each branch.

<!-- @[shape_area_calculation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Enums.ets) -->

``` TypeScript
interface DocCircleShape {
  kind: 'circle';
  radius: number;
}

interface DocRectangleShape {
  kind: 'rectangle';
  rectWidth: number;
  rectHeight: number;
}

interface DocTriangleShape {
  kind: 'triangle';
  base: number;
  height: number;
}

type DocShape = DocCircleShape | DocRectangleShape | DocTriangleShape;

function calculateArea(shape: DocShape): number {
  switch (shape.kind) {
    case 'circle':
      return Math.PI * shape.radius * shape.radius;
    case 'rectangle':
      return shape.rectWidth * shape.rectHeight;
    case 'triangle':
      return 0.5 * shape.base * shape.height;
    default:
      return 0;
  }
}

let circle: DocShape = { kind: 'circle', radius: 5 };
let rectangle: DocShape = { kind: 'rectangle', rectWidth: 10, rectHeight: 20 };
let triangle: DocShape = { kind: 'triangle', base: 8, height: 6 };

console.info(`${calculateArea(circle)}`);      // ~78.54
console.info(`${calculateArea(rectangle)}`);    // 200
console.info(`${calculateArea(triangle)}`);     // 24
```

## Enum Iterability

Native enums in TypeScript and ArkTS do not support iteration, which must be implemented manually.

### Implementing the Iterable Interface

Native enums are not iterable. By manually maintaining an array that returns all members, you can use for...of to iterate over all values or names of an enum.

<!-- @[iterate_enum_values](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Enums.ets) -->

``` TypeScript
// Manually create an array of enum values.
enum ValsDirection {
  Up,
  Down,
  Left,
  Right
}

function getDirectionValues(): ValsDirection[] {
  return [ValsDirection.Up, ValsDirection.Down, ValsDirection.Left, ValsDirection.Right];
}

function getDirectionNames(): string[] {
  return ['Up', 'Down', 'Left', 'Right'];
}

// Iterate over all enum values.
for (let dir of getDirectionValues()) {
  console.info(`${dir.toString()}`);
}

// Iterate over a string enum.
enum ValsStatus {
  Pending = 'pending',
  Active = 'active',
  Completed = 'completed'
}

function getStatusValues(): ValsStatus[] {
  return [ValsStatus.Pending, ValsStatus.Active, ValsStatus.Completed];
}

for (let status of getStatusValues()) {
  console.info(`${status}`);
}
```

### Iterating Over All Enum Members

Obtain all members by manually maintaining an array of enum members.

<!-- @[enum_member_list](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Enums.ets) -->

``` TypeScript
enum ListNumberEnum {
  First,
  Second,
  Third
}

interface ListEnumMember {
  name: string;
  value: number;
}

function getAllEnumMembers(): ListEnumMember[] {
  return [
    { name: 'First', value: ListNumberEnum.First },
    { name: 'Second', value: ListNumberEnum.Second },
    { name: 'Third', value: ListNumberEnum.Third }
  ];
}

let elmMembers: ListEnumMember[] = getAllEnumMembers();
for (let member of elmMembers) {
  console.info(`${member.name}: ${member.value}`);
}

// Manually define the enum member list.
enum ListColorEnum {
  Red,
  Green,
  Blue
}

const LIST_COLOR_VALUES: ListColorEnum[] = [ListColorEnum.Red, ListColorEnum.Green, ListColorEnum.Blue];
const LIST_COLOR_NAMES: string[] = ['Red', 'Green', 'Blue'];

for (let i = 0; i < LIST_COLOR_VALUES.length; i++) {
  console.info(`${LIST_COLOR_NAMES[i]}: ${LIST_COLOR_VALUES[i]}`);
}
```

### Obtaining the Enum Member List

Use a constant array to list all enum members. Based on this array, you can obtain the number of members, verify whether a value is a valid enum value, or determine whether a value falls within the allowed range.

<!-- @[enum_value_validation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Enums.ets) -->

``` TypeScript
// Use a constant array.
enum LogLevel {
  Debug,
  Info,
  Warning,
  Error
}

const ALL_LOG_LEVELS: LogLevel[] = [
  LogLevel.Debug,
  LogLevel.Info,
  LogLevel.Warning,
  LogLevel.Error
];

// Obtain the number of enum members.
function getEnumCount(): number {
  return ALL_LOG_LEVELS.length;
}

// Check whether the value is a valid enum value.
function isValidLogLevel(level: number): boolean {
  for (let validLevel of ALL_LOG_LEVELS) {
    if (validLevel === level) {
      return true;
    }
  }
  return false;
}

isValidLogLevel(LogLevel.Info);   // true
isValidLogLevel(99);              // false

// Check whether the enum value is within the range.
function isLogLevelInRange(level: LogLevel): boolean {
  return level >= LogLevel.Debug && level <= LogLevel.Error;
}

isLogLevelInRange(LogLevel.Warning);  // true
```

## Extending Enums

TypeScript does not support directly inheriting an existing enum, but you can append static members to an enum through namespace merging. ArkTS supports merging namespaces with enums, so you can extend an enum directly in this way.

### Extending an Enum with a Namespace

Use a namespace to add static methods to an enum and extend it.

<!-- @[namespace_extension](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Enums.ets) -->

``` TypeScript
enum NsColor {
  Red,
  Green,
  Blue
}

namespace NsColor {
  export function getName(color: NsColor): string {
    switch (color) {
      case NsColor.Red:
        return 'Red';
      case NsColor.Green:
        return 'Green';
      case NsColor.Blue:
        return 'Blue';
      default:
        return 'Unknown';
    }
  }
}

let nsName: string = NsColor.getName(NsColor.Red);
console.info(`${nsName}`); // Red
```

### Adding Enum Behavior with a Static Helper Class

An enum itself cannot define methods. You can centralize related behavior in a static helper class: take an enum member as the input and use a switch statement to return additional information such as the display name or color code, thereby separating data from logic.

<!-- @[enum_helper_class](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Enums.ets) -->

``` TypeScript
enum HelperColor {
  Red,
  Green,
  Blue
}

class ColorHelper {
  static getName(color: HelperColor): string {
    switch (color) {
      case HelperColor.Red:
        return 'Red';
      case HelperColor.Green:
        return 'Green';
      case HelperColor.Blue:
        return 'Blue';
      default:
        return 'unknown';
    }
  }

  static getHex(color: HelperColor): string {
    switch (color) {
      case HelperColor.Red:
        return '#FF0000';
      case HelperColor.Green:
        return '#00FF00';
      case HelperColor.Blue:
        return '#0000FF';
      default:
        return '#000000';
    }
  }
}

let red: HelperColor = HelperColor.Red;
let name: string = ColorHelper.getName(red);
let hex: string = ColorHelper.getHex(red);
```

### Encapsulating Enum Properties with a Class

Associate additional properties and methods with enum values through a class.

<!-- @[complex_enum_values](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Enums.ets) -->

``` TypeScript
interface PriorityInfo {
  value: number;
  label: string;
  weight: number;
}

class PriorityLevel {
  public static readonly LOW: PriorityInfo = { value: 1, label: 'Low', weight: 10 };
  public static readonly MEDIUM: PriorityInfo = { value: 2, label: 'Medium', weight: 50 };
  public static readonly HIGH: PriorityInfo = { value: 3, label: 'High', weight: 100 };

  static getAll(): PriorityInfo[] {
    return [
      PriorityLevel.LOW,
      PriorityLevel.MEDIUM,
      PriorityLevel.HIGH
    ];
  }
}

let allPriorities: PriorityInfo[] = PriorityLevel.getAll();
```

### When to Use Enum Extensions

Enums are suitable for representing the finite state set of a state machine and an error code system. Combined with `switch`, they enable exhaustive branch handling to ensure that all cases are covered.

<!-- @[state_machine_and_error_code](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Enums.ets) -->

``` TypeScript
enum State {
  Idle,
  Running,
  Paused,
  Stopped
}

class StateMachine {
  static canTransition(from: State, to: State): boolean {
    switch (from) {
      case State.Idle:
        return to === State.Running;
      case State.Running:
        return to === State.Paused || to === State.Stopped;
      case State.Paused:
        return to === State.Running || to === State.Stopped;
      case State.Stopped:
        return to === State.Idle;
      default:
        return false;
    }
  }

  static transition(from: State, to: State): State {
    if (StateMachine.canTransition(from, to)) {
      return to;
    }
    return from;
  }
}

let newState: State = StateMachine.transition(State.Idle, State.Running);
console.info(`${newState}`);

enum ErrorCode {
  Unknown = 0,
  InvalidInput = 100,
  NotFound = 404,
  Unauthorized = 401,
  ServerError = 500
}

class ErrorCodeHelper {
  static getMessage(code: ErrorCode): string {
    switch (code) {
      case ErrorCode.Unknown:
        return 'Unknown error';
      case ErrorCode.InvalidInput:
        return 'Invalid input';
      case ErrorCode.NotFound:
        return 'Resource not found';
      case ErrorCode.Unauthorized:
        return 'Unauthorized access';
      case ErrorCode.ServerError:
        return 'Server error';
      default:
        return 'Error';
    }
  }

  static isServerError(code: ErrorCode): boolean {
    return code >= 500;
  }

  static isClientError(code: ErrorCode): boolean {
    return code >= 400 && code < 500;
  }
}

let message: string = ErrorCodeHelper.getMessage(ErrorCode.NotFound);
let isServer: boolean = ErrorCodeHelper.isServerError(ErrorCode.ServerError);
```

## Enum Type Inference and Type Safety

Enum types enable the compiler to reject values that are not enum members at compile time, and, when combined with `switch`, support exhaustiveness checking.

### Type Uniqueness of Enum Members

All members in the same enum must have the same type (all numeric or all string).

<!-- @[ts_enum_member_types](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Enums.ts) -->

``` TypeScript
// Enum members are unique types.
enum Direction {
  Up,
  Down,
  Left,
  Right
}

let up: Direction.Up = Direction.Up;  // Type Direction.Up
let down: Direction.Down = Direction.Down;

// Members of different types are not interchangeable.
up = down;  // Compilation error: type mismatch.

// Use enum values as a union type.
type HorizontalDirection = Direction.Left | Direction.Right;
type VerticalDirection = Direction.Up | Direction.Down;

function moveHorizontal(dir: HorizontalDirection): void {
  console.info(`Horizontal movement: ${dir}`);
}

moveHorizontal(Direction.Left);
moveHorizontal(Direction.Up);  // Compilation error: type mismatch.
```

### Enum as Function Parameter/Return Value Type Constraint

When an enum type is used as a function parameter or return value type, the compiler rejects any value that is not a member of that enum. Combined with `switch`, this enables exhaustive branch handling. When used as an object property type, it can impose a union constraint on a group of related configuration fields.

<!-- @[ts_enum_as_type_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Enums.ts) -->

``` TypeScript
// Enum as a parameter
function setTheme(theme: Theme): void {
  switch (theme) {
    case Theme.Light:
      console.info(`Light theme`);
      break;
    case Theme.Dark:
      console.info(`Dark theme`);
      break;
    case Theme.Auto:
      console.info(`Auto theme`);
      break;
  }
}

enum Theme {
  Light,
  Dark,
  Auto
}

setTheme(Theme.Dark);
setTheme('dark');  // Compilation error: must be of the Theme type.

// Enum as a return value.
function getDefaultTheme(): Theme {
  return Theme.Auto;
}

let defaultTheme: Theme = getDefaultTheme();

// Enum as an object property type.
interface UserSettings {
  theme: Theme;
  language: Language;
  fontSize: FontSize;
}

enum Language {
  English,
  Chinese,
  Japanese
}

enum FontSize {
  Small,
  Medium,
  Large
}

let settings: UserSettings = {
  theme: Theme.Light,
  language: Language.Chinese,
  fontSize: FontSize.Medium
};

// Enum as an array element type.
let themes: Theme[] = [Theme.Light, Theme.Dark, Theme.Auto];
let languages: Language[] = [Language.English, Language.Chinese];
```

### Using Enums Instead of Magic Strings

Use enums instead of magic strings/numbers to improve code readability and maintainability.

<!-- @[replace_magic_strings_numbers](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Enums.ets) -->

``` TypeScript
// Counterexample: using magic strings
function getStatusLabel(status: string): string {
  if (status === 'pending') {
    return 'Pending';
  } else if (status === 'active') {
    return 'Active';
  } else if (status === 'completed') {
    return 'Completed';
  }
  return 'Unknown';
}

// Recommended: use an enum
function getStatusLabelEnum(status: NumsStatus): string {
  switch (status) {
    case NumsStatus.Pending:
      return 'Pending';
    case NumsStatus.Active:
      return 'Active';
    case NumsStatus.Completed:
      return 'Completed';
    default:
      return 'Unknown';
  }
}

enum NumsStatus {
  Pending = 'pending',
  Active = 'active',
  Completed = 'completed'
}

// Counterexample: Use a magic number.
function getErrorCode(code: number): string {
  if (code === 404) {
    return 'Not Found';
  } else if (code === 401) {
    return 'Unauthorized';
  }
  return 'Unknown';
}

// Recommended: Use an enum.
function getErrorCodeEnum(code: NumsErrorCode): string {
  switch (code) {
    case NumsErrorCode.NotFound:
      return 'Not Found';
    case NumsErrorCode.Unauthorized:
      return 'Unauthorized';
    default:
      return 'Unknown';
  }
}

enum NumsErrorCode {
  NotFound = 404,
  Unauthorized = 401
}

// Use an enum instead of a constant.
// Counterexample
const STATUS_PENDING = 'pending';
const STATUS_ACTIVE = 'active';
const STATUS_COMPLETED = 'completed';

// Recommended
enum OrderStatus {
  Pending = 'pending',
  Active = 'active',
  Completed = 'completed'
}
```

## Union Enums and Enum Member Types

When all members of an enum are literal members, the enum members themselves can also be used as types, and the enum becomes a union type of all its members.

<!-- @[union_enum_member_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Enums.ets) -->

``` TypeScript
enum ShapeKind {
  Circle,
  Square
}

interface UeCircle {
  kind: ShapeKind.Circle;  // Accepts only Circle members.
  radius: number;
}

interface UeSquare {
  kind: ShapeKind.Square;  // Accepts only Square members.
  sideLength: number;
}

let ueCircle: UeCircle = { kind: ShapeKind.Circle, radius: 10 };
console.info(`${ueCircle.radius.toString()}`);  // 10
```

Assigning `ShapeKind.Square` to a property of type `kind: ShapeKind.Circle` triggers a compilation error.

**TypeScript comparison**

<!-- @[ts_enum_member_type_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Enums.ts) -->

``` TypeScript
// TypeScript comparison, demonstrating that enum member types are incompatible
enum TsShapeKind {
  Circle,
  Square
}

interface TsUeCircle {
  kind: TsShapeKind.Circle;
  radius: number;
}

let tsUeBad: TsUeCircle = { kind: TsShapeKind.Square, radius: 10 };
// Compilation error: Type 'TsShapeKind.Square' is not assignable to type 'TsShapeKind.Circle'
```

After an enum becomes a union type, TypeScript can detect impossible comparisons, helping you find logic errors.

## const enum

A `const enum` inlines its member values at compile time and does not generate a runtime enum object. ArkTS supports `const enum`. However, note that there is a version dependency risk when sharing it across projects (through `.d.ts` files): the member values of a `const enum` are inlined into the consumer's code at compile time. If the source definition of the `const enum` changes, the consumer must recompile to obtain the new values. It is recommended to use `const enum` within a project and use a regular enum when sharing across projects.

<!-- @[const_enum_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Enums.ets) -->

``` TypeScript
const enum CeConstDirection {
  Up,
  Down
}

let cedDir: CeConstDirection = CeConstDirection.Up;
console.info(`${cedDir}`); // 0
```

Using a regular enum instead of a `const enum` avoids the cross-project pitfalls:

<!-- @[const_enum_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Enums.ets) -->

``` TypeScript
enum CeDirection {
  Up = 0,
  Down = 1
}

let ceD: CeDirection = CeDirection.Up;
console.info(`${ceD}`);  // 0
```

## Runtime and Compile-Time Enums

An enum is a real runtime object and can be passed as a parameter. You can use `keyof typeof` to obtain a string union type of all keys of the enum.

**TypeScript comparison**

<!-- @[ts_enum_keyof_typeof](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Enums.ts) -->

``` TypeScript
// TypeScript comparison approach; in ArkTS, manually maintain the key array.
enum TsLogLevel {
  ERROR,
  WARN,
  INFO,
  DEBUG
}
type TsLogLevelStrings = keyof typeof TsLogLevel;
// 'ERROR' | 'WARN' | 'INFO' | 'DEBUG'
```

In ArkTS, manually maintain the enum key array.

<!-- @[enum_keyof_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Enums.ets) -->

``` TypeScript
enum EkLogLevel {
  ERROR,
  WARN,
  INFO,
  DEBUG
}

const ekLogLevelKeys: string[] = ['ERROR', 'WARN', 'INFO', 'DEBUG'];

function ekPrintImportant(key: string, message: string): void {
  let num: number = EkLogLevel[key];
  if (num <= EkLogLevel.WARN) {
    console.info(`[${key}] ${message}`);
  }
}

ekPrintImportant('ERROR', 'System error');
```

## Comparison Between Objects and Enums

You can use an `as const` object as an alternative to an enum to keep the code consistent with TypeScript.

**TypeScript Comparison**

<!-- @[ts_object_vs_enum](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Enums.ts) -->

``` TypeScript
// TypeScript comparison
const TsODirection = {
  Up: 0,
  Down: 1,
  Left: 2,
  Right: 3
} as const;

type TsDirection = typeof TsODirection[keyof typeof TsODirection];
```

In ArkTS, use an enum or explicit constants instead.

<!-- @[object_vs_enum_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Enums.ets) -->

``` TypeScript
enum OvDirection {
  Up = 0,
  Down = 1,
  Left = 2,
  Right = 3
}

function ovRun(dir: OvDirection): void {
  console.info(`Running ${dir}`);
}

ovRun(OvDirection.Right);  // Running 3
```

The advantage of an enum is that it provides built-in type safety and supports reverse mapping (for numeric enums). The advantage of the object approach is that it stays consistent with TypeScript syntax.

## Heterogeneous Enum

TypeScript supports heterogeneous enums, that is, enums mixing numeric and string values. ArkTS does not support heterogeneous enums (`arkts-no-enum-mixed-types`). For details, see [TypeScript to ArkTS Cookbook](typescript-to-arkts-migration-guide.md#enumeration-members-can-be-initialized-only-with-compile-time-expressions-of-the-same-type). When values of different types are required, split them into multiple enums.

**TypeScript comparison**

<!-- @[ts_heterogeneous_enum](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Enums.ts) -->

``` TypeScript
// TypeScript heterogeneous enum, not supported by ArkTS
enum MixedResult {
  No = 0,
  Yes = 'YES'
}

console.info(`${MixedResult.No}`);   // 0
console.info(`${MixedResult.Yes}`);  // YES
```

Recommended approach in ArkTS: split into independent enums by value type.

<!-- @[split_heterogeneous_enum](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Enums.ets) -->

``` TypeScript
enum HeNumericResult {
  No = 0,
  Yes = 1
}

enum HeStringResult {
  No = 'NO',
  Yes = 'YES'
}
```

## Computed Members and Constant Members

TypeScript enum members are classified into constant members and computed members. Constant members have their values determined at compile time, while computed members are evaluated at runtime.

### Constant Members

An enum member is a constant member in the following cases:

- It is the first member and has no initializer, in which case its value is `0`.

- It has no initializer and the preceding member is a numeric constant, in which case its value is the preceding member's value `+1`.

- It is initialized with a constant enum expression (a literal, a reference to an existing constant member, a unary operator applied to a constant, or a binary operator).

<!-- @[constant_enum_members](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Enums.ets) -->

``` TypeScript
enum ConstExampleEnum {
  A,        // Constant: 0
  B = 1,    // Constant: literal
  C = ConstExampleEnum.A + ConstExampleEnum.B // Constant: constant expression
}
```

### Computed Members

Computed members are evaluated at runtime. A member without an initializer that follows a computed member causes an error (its value cannot be determined).

**TypeScript comparison**

<!-- @[ts_computed_enum_member](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Enums.ts) -->

``` TypeScript
// TypeScript computed member syntax
enum ComputedExample {
  Length = 'hello'.length, // Computed member, with a value of 5
  Next,                    // Compilation error: a member without an initializer cannot follow a computed member.
}
```

> **NOTE**
> 
> In ArkTS, enum members should use constant values (literals or references to existing members) and avoid computed members to ensure that values are determined at compile time.

## Ambient enum

`declare enum` declares an existing enum (ambient enum) without generating runtime code. It is used in declaration files to describe the type of an external enum. Type declarations for external modules can also be generated automatically by the compiler.

<!-- @[ambient_enum](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Enums.ets) -->

``` TypeScript
declare enum AmbientExternalEnum {
  A = 1,
  B,
  C
}

let ambValue: AmbientExternalEnum = AmbientExternalEnum.A;
console.info(`${ambValue}`); // 1
```

The difference between an ambient enum and a regular enum is that members without an initializer are always treated as computed members, and the compiler does not perform constant inference.