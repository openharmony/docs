# 枚举
<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

枚举（Enum）是定义一组命名常量的类型。枚举使代码更清晰、更易维护，避免使用魔术数字或字符串。

## 枚举的基本声明

枚举通过`enum`关键字声明，包含数值枚举和字符串枚举两种形式。数值枚举的成员从0开始自增，也可显式指定初始值；字符串枚举的每个成员必须显式赋值。

### 枚举的语法格式

使用`enum`关键字后跟枚举名，在花括号内声明成员。成员命名使用PascalCase，无初始值的数值枚举成员从0开始自增。

``` TypeScript
enum EnumName {
  Member1,
  Member2,
  Member3
}
```

数值枚举是成员值为数字类型的枚举，默认从0开始自动递增，也可以手动指定初始值。

字符串枚举是成员值为字符串类型的枚举，必须为每个成员显式赋值，不支持自动递增和反向映射。

枚举提供类型安全与可读性：编译期拒绝非法成员值，语义化命名替代魔术数字，相关常量集中定义便于维护，DevEco Studio可提供成员智能提示。

<!-- @[basic_enum_declaration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Enums.ets) -->

``` TypeScript
// 基本枚举声明
enum Direction {
  Up,
  Down,
  Left,
  Right
}

// 使用枚举
let dir: Direction = Direction.Up;
let moveDir: Direction = Direction.Down;

console.info(`${dir}`);   // 0
console.info(`${moveDir}`);  // 1

// 枚举比较
if (dir === Direction.Up) {
  console.info('向上移动');
}

// 枚举作为函数参数
function declarationMove(direction: Direction): void {
  switch (direction) {
    case Direction.Up:
      console.info('向上');
      break;
    case Direction.Down:
      console.info('向下');
      break;
    case Direction.Left:
      console.info('向左');
      break;
    case Direction.Right:
      console.info('向右');
      break;
  }
}

declarationMove(Direction.Up);  // 向上

// 枚举作为返回值
function getDefaultDirection(): Direction {
  return Direction.Right;
}

let defaultDir: Direction = getDefaultDirection();
```

### 枚举成员的命名规范

枚举成员应使用PascalCase命名，避免缩写，名称需语义化地表达其所代表的含义。

<!-- @[enum_naming_conventions](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Enums.ets) -->

``` TypeScript
// 枚举名：PascalCase
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

// 避免缩写，使用完整单词
enum Color {
  Red,        // 推荐
  Green,
  Blue
}

// 反例
enum Clr {
  R,    // 反例：缩写
  G,
  B
}

// 语义化命名
enum PaymentStatus {
  Pending,     // 待支付
  Processing,  // 处理中
  Completed,   // 已完成
  Failed,      // 失败
  Cancelled    // 已取消
}

// 使用enum作为类型
function updateStatus(status: PaymentStatus): void {
  console.info(`状态更新为: ${status}`);
}

updateStatus(PaymentStatus.Completed);
```

### 无值枚举的定义与使用

无值枚举的成员不带初始值，从0开始自动递增。

<!-- @[numeric_enum_auto_increment](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Enums.ets) -->

``` TypeScript
// 无值枚举（默认数值枚举）
enum Size {
  Small,   // 0
  Medium,  // 1
  Large    // 2
}

let size: Size = Size.Small;
console.info(`${size}`);  // 0

// 数值枚举自动递增
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

// 使用数值枚举
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

## 带原始值的枚举

枚举成员可关联数值或字符串作为原始值，用于序列化、持久化或与外部接口对接。

### 原始值的类型约束（字符串、数值等）

枚举成员可关联字符串或数值作为原始值，但同一枚举中所有成员的原始值类型必须保持一致，混用字符串与数值会导致编译错误。

通过枚举名访问成员值，数值枚举支持反向映射（成员名↔值），字符串枚举仅支持正向映射。

<!-- @[ts_string_and_numeric_enum](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Enums.ts) -->

``` TypeScript
// 字符串枚举
enum Status {
  Pending = 'pending',
  Active = 'active',
  Completed = 'completed',
  Failed = 'failed'
}

let status: Status = Status.Pending;
console.info(`${status}`);  // 'pending'

// 数值枚举（显式值）
enum Priority {
  Low = 1,
  Medium = 2,
  High = 3,
  Critical = 10
}

let priority: Priority = Priority.High;
console.info(`${priority.toString()}`);  // 3

// ArkTS不使用混合枚举：同一个枚举中的成员应保持同一原始值类型
enum Mixed {
  No = 0,
  Yes = 'YES'  // 编译错误：成员初始值类型不一致
}
```

### 原始值的自动赋值（数值自增、字符串同名）

原始值的自动赋值是指在数值枚举中，未显式赋值的成员会自动获得递增的数值，从0开始或从上一个显式值继续递增。

<!-- @[enum_auto_increment_rules](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Enums.ets) -->

``` TypeScript
// 数值枚举自动递增
enum AutoNumberEnum {
  First,    // 0（自动）
  Second,   // 1（自动）
  Third,    // 2（自动）
  Custom = 10,
  Fourth,   // 11（从Custom继续）
  Fifth     // 12
}

console.info(`${AutoNumberEnum.First}`);    // 0
console.info(`${AutoNumberEnum.Second}`);   // 1
console.info(`${AutoNumberEnum.Third}`);    // 2
console.info(`${AutoNumberEnum.Custom}`);   // 10
console.info(`${AutoNumberEnum.Fourth}`);   // 11
console.info(`${AutoNumberEnum.Fifth}`);    // 12

// 字符串枚举必须显式赋值
enum AutoStringEnum {
  A = 'A',
  B = 'B',
  C = 'C'
}
```

### 原始值与枚举成员的双向映射

原始值与枚举成员的双向映射是指可以通过枚举成员获取原始值，也可以通过原始值获取枚举成员名称。

<!-- @[enum_bidirectional_mapping](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Enums.ets) -->

``` TypeScript
// 数值枚举支持双向映射
enum BiNumberEnum {
  Zero,
  One,
  Two
}

let biEnumName: string = BiNumberEnum[0];   // 'Zero'
let biValue: number = BiNumberEnum.One;     // 1

console.info(`${biEnumName}`);   // Zero
console.info(`${biValue}`);      // 1

// 字符串枚举不支持反向映射
enum BiStringEnum {
  A = 'A',
  B = 'B'
}

let biA: BiStringEnum = BiStringEnum.A;  // 'A'

// 双向映射示例
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

### 原始值枚举的初始化

从外部传入的字符串或数值反查对应枚举成员：通常用switch逐个匹配原始值并返回相应成员，无匹配时返回undefined，实现原始值到枚举的反向初始化。

<!-- @[parse_enum_from_value](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Enums.ets) -->

``` TypeScript
// 从字符串创建枚举值
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

// 从数值创建枚举值
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

## 关联值模式模拟

TypeScript/ArkTS不支持带关联值的枚举（如Swift的enum）。如需表达类似“不同状态携带不同数据”的模式，可以使用对象或接口模拟。

### 使用接口联合声明关联数据

通过接口联合为不同枚举值关联各自的数据结构。

<!-- @[simulated_associated_values](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Enums.ets) -->

``` TypeScript
// TypeScript不支持关联值枚举
// ArkTS中使用接口联合模拟不同结果形态

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
    console.info(`成功，值: ${result.value}`);
  } else {
    console.info(`失败，错误: ${(result as FailureResult).error}`);
  }
}

processResult(successResult);
processResult(failureResult);

// 也可以使用更明确的判别字段
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

### 不同状态的数据类型定义

为不同状态定义各自的接口，通过联合类型组合。

<!-- @[discriminated_union_message_types](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Enums.ets) -->

``` TypeScript
// 不同类型的关联值
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

// 处理不同类型消息
function handleMessage(message: Message): void {
  switch (message.kind) {
    case 'text':
      console.info(`文本: ${message.content}`);
      break;
    case 'image':
      console.info(`图片: ${message.url} (${message.imageWidth}x${message.imageHeight})`);
      break;
    case 'video':
      console.info(`视频: ${message.url} (${message.duration}s)`);
      break;
  }
}

handleMessage(textMessage);
handleMessage(imageMessage);
```

### 关联数据的读取

通过判别字段（如success/type/kind）区分不同形态的对象，在switch分支中访问对应字段的数据。

<!-- @[extract_associated_values](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Enums.ets) -->

``` TypeScript
// TypeScript支持：let { value } = result;
// ArkTS需要单独提取

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
    return result.value;  // 直接访问
  }
  return undefined;
}

function getError(result: ExtractResult): string | undefined {
  if (result.success === false) {
    return (result as ExtractFailureResult).error;  // 直接访问
  }
  return undefined;
}

let result: ExtractResult = { success: true, value: 42 };

let value: number | undefined = getValue(result);
if (value !== undefined) {
  console.info(`${value.toString()}`);
}
```

### 结合switch语句处理关联数据

用switch匹配枚举值，在各分支中访问对应的关联数据。

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

## 枚举的可迭代性

TypeScript/ArkTS原生枚举不支持迭代，需要手动实现。

### 实现Iterable接口

原生枚举不可迭代，通过手动维护一个返回全部成员的数组，即可用for...of遍历枚举的全部值或名称。

<!-- @[iterate_enum_values](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Enums.ets) -->

``` TypeScript
// 手动创建枚举值数组
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

// 遍历所有枚举值
for (let dir of getDirectionValues()) {
  console.info(`${dir.toString()}`);
}

// 遍历字符串枚举
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

### 遍历枚举的所有成员

通过手动维护枚举成员数组获取全部成员。

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

// 手动定义枚举成员列表
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

### 枚举成员列表的获取

用一个常量数组列举全部枚举成员，即可在此基础上获取成员数量、校验某值是否为合法枚举值，或判断取值是否落在允许范围内。

<!-- @[enum_value_validation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Enums.ets) -->

``` TypeScript
// 使用常量数组
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

// 获取枚举数量
function getEnumCount(): number {
  return ALL_LOG_LEVELS.length;
}

// 检查是否为有效枚举值
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

// 枚举值范围检查
function isLogLevelInRange(level: LogLevel): boolean {
  return level >= LogLevel.Debug && level <= LogLevel.Error;
}

isLogLevelInRange(LogLevel.Warning);  // true
```

## 枚举的扩展

TypeScript不支持直接继承已有枚举，但可以通过命名空间合并给枚举追加静态成员。ArkTS支持命名空间与枚举的合并，可直接使用此方式扩展枚举。

### 使用命名空间扩展枚举

使用命名空间为枚举添加静态方法，实现枚举扩展。

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
        return '红色';
      case NsColor.Green:
        return '绿色';
      case NsColor.Blue:
        return '蓝色';
      default:
        return '未知';
    }
  }
}

let nsName: string = NsColor.getName(NsColor.Red);
console.info(`${nsName}`); // 红色
```

### 使用静态辅助类添加枚举行为

枚举本身不能定义方法，可将相关行为集中到一个静态辅助类中：以枚举成员为入参，用switch分发返回显示名称、颜色码等附加信息，使数据与逻辑分离。

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
        return '红色';
      case HelperColor.Green:
        return '绿色';
      case HelperColor.Blue:
        return '蓝色';
      default:
        return '未知';
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

### 使用类封装枚举属性

通过类为枚举值关联额外的属性和方法。

<!-- @[complex_enum_values](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Enums.ets) -->

``` TypeScript
interface PriorityInfo {
  value: number;
  label: string;
  weight: number;
}

class PriorityLevel {
  public static readonly LOW: PriorityInfo = { value: 1, label: '低', weight: 10 };
  public static readonly MEDIUM: PriorityInfo = { value: 2, label: '中', weight: 50 };
  public static readonly HIGH: PriorityInfo = { value: 3, label: '高', weight: 100 };

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

### 枚举扩展的使用场景

枚举适合表示状态机的有限状态集和错误码体系，配合switch可实现穷尽性分支处理，确保所有情况都被覆盖。

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
        return '未知错误';
      case ErrorCode.InvalidInput:
        return '输入无效';
      case ErrorCode.NotFound:
        return '资源未找到';
      case ErrorCode.Unauthorized:
        return '未授权访问';
      case ErrorCode.ServerError:
        return '服务器错误';
      default:
        return '错误';
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

## 枚举的类型推断与类型安全

枚举类型使编译器在编译期拒绝非枚举成员的值传入，配合switch可实现穷尽性检查。

### 枚举成员的类型唯一性

同一枚举中所有成员的类型必须一致（全部数值或全部字符串）。

<!-- @[ts_enum_member_types](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Enums.ts) -->

``` TypeScript
// 枚举成员是唯一类型
enum Direction {
  Up,
  Down,
  Left,
  Right
}

let up: Direction.Up = Direction.Up;  // Direction.Up类型
let down: Direction.Down = Direction.Down;

// 不同成员不能互换
up = down;  // 编译错误：类型不匹配

// 枚举值作为联合类型
type HorizontalDirection = Direction.Left | Direction.Right;
type VerticalDirection = Direction.Up | Direction.Down;

function moveHorizontal(dir: HorizontalDirection): void {
  console.info(`水平移动: ${dir}`);
}

moveHorizontal(Direction.Left);
moveHorizontal(Direction.Up);  // 编译错误：类型不匹配
```

### 枚举作为函数参数/返回值的类型约束

将枚举类型用作函数参数或返回值类型时，编译器会拒绝任何非该枚举成员的值传入，配合switch可穷尽分支处理；用作对象属性类型时，可对一组相关配置字段做联合约束。

<!-- @[ts_enum_as_type_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Enums.ts) -->

``` TypeScript
// 枚举作为参数
function setTheme(theme: Theme): void {
  switch (theme) {
    case Theme.Light:
      console.info(`浅色主题`);
      break;
    case Theme.Dark:
      console.info(`深色主题`);
      break;
    case Theme.Auto:
      console.info(`自动主题`);
      break;
  }
}

enum Theme {
  Light,
  Dark,
  Auto
}

setTheme(Theme.Dark);
setTheme('dark');  // 编译错误：必须是Theme类型

// 枚举作为返回值
function getDefaultTheme(): Theme {
  return Theme.Auto;
}

let defaultTheme: Theme = getDefaultTheme();

// 枚举作为对象属性类型
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

// 枚举作为数组元素类型
let themes: Theme[] = [Theme.Light, Theme.Dark, Theme.Auto];
let languages: Language[] = [Language.English, Language.Chinese];
```

### 使用枚举替代魔术字符串

使用枚举替代魔术字符串/数值，提升代码可读性和可维护性。

<!-- @[replace_magic_strings_numbers](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Enums.ets) -->

``` TypeScript
// 反例：使用魔术字符串
function getStatusLabel(status: string): string {
  if (status === 'pending') {
    return '待处理';
  } else if (status === 'active') {
    return '激活';
  } else if (status === 'completed') {
    return '已完成';
  }
  return '未知';
}

// 推荐：使用枚举
function getStatusLabelEnum(status: NumsStatus): string {
  switch (status) {
    case NumsStatus.Pending:
      return '待处理';
    case NumsStatus.Active:
      return '激活';
    case NumsStatus.Completed:
      return '已完成';
    default:
      return '未知';
  }
}

enum NumsStatus {
  Pending = 'pending',
  Active = 'active',
  Completed = 'completed'
}

// 反例：使用魔术数值
function getErrorCode(code: number): string {
  if (code === 404) {
    return 'Not Found';
  } else if (code === 401) {
    return 'Unauthorized';
  }
  return 'Unknown';
}

// 推荐：使用枚举
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

// 枚举替代常量
// 反例
const STATUS_PENDING = 'pending';
const STATUS_ACTIVE = 'active';
const STATUS_COMPLETED = 'completed';

// 推荐
enum OrderStatus {
  Pending = 'pending',
  Active = 'active',
  Completed = 'completed'
}
```

## 联合枚举与枚举成员类型

当枚举所有成员都是字面量成员时，枚举成员本身也可作为类型使用，枚举成为其所有成员的联合类型。

<!-- @[union_enum_member_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Enums.ets) -->

``` TypeScript
enum ShapeKind {
  Circle,
  Square
}

interface UeCircle {
  kind: ShapeKind.Circle;  // 仅接受Circle成员
  radius: number;
}

interface UeSquare {
  kind: ShapeKind.Square;  // 仅接受Square成员
  sideLength: number;
}

let ueCircle: UeCircle = { kind: ShapeKind.Circle, radius: 10 };
console.info(`${ueCircle.radius.toString()}`);  // 10
```

将`ShapeKind.Square`赋值给`kind: ShapeKind.Circle`类型的属性会触发编译错误。

**TypeScript对照**

<!-- @[ts_enum_member_type_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Enums.ts) -->

``` TypeScript
// TypeScript对照写法，演示枚举成员类型不兼容
enum TsShapeKind {
  Circle,
  Square
}

interface TsUeCircle {
  kind: TsShapeKind.Circle;
  radius: number;
}

let tsUeBad: TsUeCircle = { kind: TsShapeKind.Square, radius: 10 };
// 编译错误：Type 'TsShapeKind.Square' is not assignable to type 'TsShapeKind.Circle'
```

枚举成为联合类型后，TypeScript能检测不可能的比较，帮助发现逻辑错误。

## const enum

`const enum`在编译时内联成员值，不生成运行时枚举对象。ArkTS支持`const enum`。但需注意：在跨项目共享时（通过`.d.ts`文件）存在版本依赖风险——`const enum`的成员值在编译时被内联到消费方的代码中，若`const enum`源定义变更，消费方需重新编译才能获取新值。推荐项目内部使用`const enum`，跨项目共享时使用普通枚举。

<!-- @[const_enum_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Enums.ets) -->

``` TypeScript
const enum CeConstDirection {
  Up,
  Down
}

let cedDir: CeConstDirection = CeConstDirection.Up;
console.info(`${cedDir}`); // 0
```

使用普通枚举替代`const enum`，可避免跨项目陷阱：

<!-- @[const_enum_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Enums.ets) -->

``` TypeScript
enum CeDirection {
  Up = 0,
  Down = 1
}

let ceD: CeDirection = CeDirection.Up;
console.info(`${ceD}`);  // 0
```

## 运行时与编译期的枚举

枚举是真实的运行时对象，可作为参数传递。使用`keyof typeof`可获取枚举所有键的字符串联合类型。

**TypeScript对照**

<!-- @[ts_enum_keyof_typeof](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Enums.ts) -->

``` TypeScript
// TypeScript对照写法，ArkTS中手动维护键数组
enum TsLogLevel {
  ERROR,
  WARN,
  INFO,
  DEBUG
}
type TsLogLevelStrings = keyof typeof TsLogLevel;
// 'ERROR' | 'WARN' | 'INFO' | 'DEBUG'
```

ArkTS中手动维护枚举键数组。

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

## 对象与枚举的对比

使用`as const`对象可替代枚举，保持代码与TypeScript状态一致。

**TypeScript对照**

<!-- @[ts_object_vs_enum](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Enums.ts) -->

``` TypeScript
// TypeScript对照写法
const TsODirection = {
  Up: 0,
  Down: 1,
  Left: 2,
  Right: 3
} as const;

type TsDirection = typeof TsODirection[keyof typeof TsODirection];
```

ArkTS中使用枚举或显式常量替代。

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

枚举的优点在于自带类型安全且支持反向映射（数值枚举）。对象方式的优点是与TypeScript语法保持一致。

## 异构枚举

TypeScript支持异构枚举，即数值和字符串混合的枚举。ArkTS不支持异构枚举（`arkts-no-enum-mixed-types`），详见[从TypeScript到ArkTS的适配规则](typescript-to-arkts-migration-guide.md#只能使用类型相同的编译时表达式初始化枚举成员)，需要不同类型的值时应拆分为多个枚举。

**TypeScript对照**

<!-- @[ts_heterogeneous_enum](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Enums.ts) -->

``` TypeScript
// TypeScript异构枚举，ArkTS不支持
enum MixedResult {
  No = 0,
  Yes = 'YES'
}

console.info(`${MixedResult.No}`);   // 0
console.info(`${MixedResult.Yes}`);  // YES
```

ArkTS推荐做法：按值类型拆分为独立枚举。

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

## 计算成员与常量成员

TypeScript枚举成员分为常量成员和计算成员。常量成员在编译期确定值，计算成员在运行时求值。

### 常量成员

以下情况为常量成员：
- 首个无初始化值，值为`0`。
- 无初始化值且前一成员为数值常量，值为前一成员`+1`。
- 用常量枚举表达式（字面量、引用已有常量成员、一元运算符作用于常量、二元运算符）初始化。

<!-- @[constant_enum_members](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Enums.ets) -->

``` TypeScript
enum ConstExampleEnum {
  A,        // 常量：0
  B = 1,    // 常量：字面量
  C = ConstExampleEnum.A + ConstExampleEnum.B // 常量：常量表达式
}
```

### 计算成员

计算成员在运行时求值，计算成员后的无初始化值成员会报错（无法确定值）。

**TypeScript对照**

<!-- @[ts_computed_enum_member](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Enums.ts) -->

``` TypeScript
// TypeScript计算成员写法
enum ComputedExample {
  Length = 'hello'.length, // 计算成员，值为5
  Next,                    // 编译错误：计算成员后不能有无初始化值成员
}
```

> **说明：**
> 
> ArkTS中枚举成员应使用常量值（字面量或已有成员引用），避免使用计算成员，确保编译期确定值。

## Ambient enum

`declare enum`声明已存在的枚举（Ambient enum），不生成运行时代码，用于声明文件中描述外部枚举的类型。外部模块的类型声明也可由编译器自动生成。

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

Ambient enum与普通枚举的区别：无初始化值的成员始终被视为计算成员，编译器不进行常量推断。
