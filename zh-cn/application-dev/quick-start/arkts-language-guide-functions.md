# 函数
<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

ArkTS提供丰富的函数特性，包括参数、返回值、类型定义、重载、高阶函数等。

## 函数的声明与调用

函数通过`function`关键字声明，包含函数名、参数列表、返回类型和函数体，通过函数名加括号调用。

### 函数的基本语法结构

ArkTS函数通过`function`关键字声明，支持类型标注的参数和返回值、可选/默认/剩余参数、函数类型、重载和高阶函数等特性。

函数的作用体现在四个方面：将重复逻辑封装为函数以避免代码冗余，将复杂操作封装为函数以提供清晰接口，将大任务分解为多个小函数以便管理和测试，隐藏实现细节只暴露必要接口。由此带来的好处是提高复用性（一次编写多处调用）、增强可读性（函数名直观表达功能）、易于维护（修改一处所有调用点生效）以及便于测试（独立函数更易单独测试调试）。

``` TypeScript
function functionName(parameters: parameterTypes): returnType {
  // 函数体
  return returnValue;
}
```

<!-- @[function_declaration_basic](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
// 基本函数声明
function add(a: number, b: number): number {
  return a + b;
}

// 函数调用
let result: number = add(1, 2);

// 无返回值函数
function logMessage(message: string): void {
  console.info(`${message}`);
}

logMessage('Hello, ArkTS');

// 简单计算函数
function multiply(x: number, y: number): number {
  return x * y;
}

let product: number = multiply(5, 3);  // 15

// 复杂逻辑函数
function calculateArea(width: number, height: number): number {
  let area: number = width * height;
  return area;
}

let area: number = calculateArea(10, 20);  // 200
```

ArkTS要求函数参数和返回值显式标注类型。在上下文类型推断的场景中（如回调函数参数），编译器可根据函数签名自动推断参数类型，此时可省略回调参数的类型标注。返回类型为`void`的函数可省略`return`，或使用`return;`提前退出。

### 函数名与参数命名规范

函数名使用camelCase动词短语（如calculateTotal、validateInput），应描述"做什么"而非"怎么做"；参数名使用描述性名词，避免缩写和无意义命名。

<!-- @[function_naming_conventions](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
// 函数名：动词或动词短语，camelCase
function calculateTotal() {}
function validateInput() {}
function processData() {}
function fetchUserInfo() {}

// 参数名：名词，camelCase，描述性
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

// 避免无意义命名
// 反例：function f(a, b) {}
// 推荐：function calculateSum(firstValue: number, secondValue: number) {}
```

命名是约定而非编译约束：`function f(a, b)`能编译通过，但会降低可读性。ArkTS中函数和参数用camelCase，类型（如`Point`）用PascalCase。

### 函数的调用方式

函数支持直接调用、链式调用、嵌套调用和条件调用。链式调用从内向外执行，函数返回值作为外层调用的参数；嵌套调用在函数内部调用其他函数，适合组合复杂逻辑。

<!-- @[function_invocation_methods](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
// 直接调用
function sayHello(): void {
  console.info('Hello');
}

sayHello();

// 带参数调用
function invokeGreet(name: string): void {
  console.info(`Hello, ${name}`);
}

invokeGreet('Alice');

// 带返回值调用
function invokeAdd(a: number, b: number): number {
  return a + b;
}

let sum: number = invokeAdd(1, 2);

// 链式调用
function double(x: number): number {
  return x * 2;
}

let invokeResult: number = double(double(5));  // 20

// 嵌套调用
function square(x: number): number {
  return x * x;
}

function sumOfSquares(a: number, b: number): number {
  return square(a) + square(b);
}

let squaresSum: number = sumOfSquares(3, 4);  // 25

// 条件调用
function invokeProcessData(data: string | null): void {
  if (data !== null) {
    processValidData(data);
  }
}

function processValidData(data: string): void {
  console.info(`${data}`);
}
```

嵌套与链式调用的求值顺序为由内向外：`double(double(5))`先求`double(5)`得10，再求`double(10)`得20。链式调用要求内层函数的返回类型与外层函数的参数类型匹配，类型不一致会在编译期报错。条件调用将"是否调用"与"调用什么"解耦，是后续可选链调用（`?.()`）的基础模式。

### 函数的返回值处理

函数通过`return`语句返回结果，返回类型由声明决定；无返回值时使用`void`。

<!-- @[function_return_values](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
// 单一返回值
function getMax(a: number, b: number): number {
  return a > b ? a : b;
}

let max: number = getMax(10, 20);

// 无返回值
function logInfo(info: string): void {
  console.info(`${info}`);
  // 无return或return;
}

// 提前返回
function validateAge(age: number): boolean {
  if (age < 0) {
    return false;
  }
  if (age > 150) {
    return false;
  }
  return true;
}

// 多路径返回
function classifyNumber(value: number): string {
  if (value > 0) {
    return 'positive';
  }
  if (value < 0) {
    return 'negative';
  }
  return 'zero';
}

// 返回对象
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

// 返回数组
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

## 函数的参数

函数参数包括形参（声明中的参数名和类型）和实参（调用时传入的值），ArkTS支持可选参数、默认参数和剩余参数。

### 形参和实参的对应关系

形参是函数声明中的参数名，实参是调用时传入的值，按位置一一对应。

<!-- @[parameters_formal_and_actual](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
interface FormalPoint {
  x: number;
  y: number;
}

// 形参（形式参数）：函数定义时的参数
function addNumbers(a: number, b: number): number {
  return a + b;
}

// 实参（实际参数）：函数调用时传入的值
let paramsResult: number = addNumbers(1, 2);
console.info(`${paramsResult}`); // 3

// 参数数量必须匹配
// addNumbers(1);        // 编译错误：缺少参数
// addNumbers(1, 2, 3);  // 编译错误：参数过多

// 参数类型必须匹配
function greetUser(name: string): string {
  return `Hello, ${name}`;
}

let greeting: string = greetUser('Alice');
console.info(`${greeting}`); // Hello, Alice
// greetUser(123);  // 编译错误：类型不匹配

// 参数顺序必须匹配
function createPoint(x: number, y: number): FormalPoint {
  return { x: x, y: y };
}

let fpPoint: FormalPoint = createPoint(10, 20);
console.info(`${fpPoint.x}, ${fpPoint.y}`); // 10, 20
```

### 可选参数

可选参数使用`?`标记，表示调用时可以省略该参数。在类型层面，可选参数的类型为`T | undefined`——传入时为`T`，省略时为`undefined`。因此函数体内访问可选参数前须检查`!== undefined`，或使用空值合并`??`提供默认值。注意：可选参数必须排在必选参数之后。

<!-- @[optional_parameters](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
// 可选参数
function paramsGreet(name: string, title?: string): string {
  if (title !== undefined) {
    return `Hello, ${title} ${name}`;
  }
  return `Hello, ${name}`;
}

paramsGreet('Alice');           // "Hello, Alice"
paramsGreet('Alice', 'Dr.');    // "Hello, Dr. Alice"

// 可选参数必须在必需参数之后
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

// 检查可选参数
function processConfig(config: Config): void {
  if (config.timeout !== undefined) {
    console.info(`超时: ${config.timeout}`);
  }
  if (config.retries !== undefined) {
    console.info(`重试次数: ${config.retries}`);
  }
}

interface Config {
  timeout?: number;
  retries?: number;
}
```

### 默认参数值

为参数指定默认值，调用时若未传入该参数则使用默认值，可与可选参数混用。

<!-- @[default_parameters](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
// 默认参数
function paramsGreet2(name: string, greeting: string = 'Hello'): string {
  return `${greeting}, ${name}`;
}

paramsGreet2('Alice');              // "Hello, Alice"
paramsGreet2('Alice', 'Hi');        // "Hi, Alice"

// 默认参数可以与可选参数混用
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

// 默认值可以是表达式
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

// 默认值使用其他参数
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

### 剩余参数（可变参数）

使用`...`语法将不定数量的参数收集为数组，实现参数数量可变的函数。

<!-- @[rest_parameters](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
// 剩余参数
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

// 剩余参数与普通参数结合
function greetAll(greeting: string, ...names: string[]): string {
  let result: string = '';
  for (let name of names) {
    result += `${greeting}, ${name}\n`;
  }
  return result;
}

greetAll('Hello', 'Alice', 'Bob', 'Charlie');

// 剩余参数必须是最后一个参数
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

// 剩余参数类型
function concatenate(...strings: string[]): string {
  return strings.join('');
}

concatenate('a', 'b', 'c');  // "abc"

// 剩余参数用于转发
function logAll(...messages: string[]): void {
  for (let message of messages) {
    console.info(`${message}`);
  }
}
```

### 解构参数对照（结合元组、对象）

TypeScript支持解构参数将元组或对象成员直接提取为参数（如`function foo({x, y}: Point)`）。ArkTS不支持解构参数，需要通过接口类型参数接收后手动提取属性。

<!-- @[parameter_destructuring_limitation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
// ArkTS不支持解构参数，需通过接口类型参数接收后手动提取

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

// 使用接口替代解构
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

## 函数的返回值

本节介绍void函数、单返回值、多返回值（元组）和可选返回值（T | undefined）等不同返回模式。

### 无返回值函数（void类型）

void函数不返回值，用于执行操作但不产生结果。

<!-- @[void_type_functions](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
// void类型函数
function log(message: string): void {
  console.info(`${message}`);
}

function notify(message: string): void {
  alert(message);
}

function alert(message: string): void {
  console.info(`Alert: ${message}`);
}

// void函数可以提前返回
function process(data: string | null): void {
  if (data === null) {
    return;  // 提前退出
  }
  console.info(`${data}`);
}

// void函数可以省略return
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

### 单返回值函数

函数通过`return`返回单个值，返回类型可为基本类型、对象或数组。

<!-- @[return_types](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
// 返回基本类型
function typesAdd(a: number, b: number): number {
  return a + b;
}

function concat(a: string, b: string): string {
  return a + b;
}

function isPositive(value: number): boolean {
  return value > 0;
}

// 返回对象
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

// 返回数组
function getNumbers(): number[] {
  return [1, 2, 3, 4, 5];
}

// 返回类实例
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

### 多返回值函数（使用元组承载）

通过数组或元组类型返回多个值，调用方按索引逐个获取各返回项。

<!-- @[multiple_return_values](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
// 使用数组承载多个返回值
function divideWithRemainder(a: number, b: number): number[] {
  let quotient: number = Math.floor(a / b);
  let remainder: number = a % b;
  return [quotient, remainder];
}

let valsResult: number[] = divideWithRemainder(10, 3);
let quotient: number = valsResult[0];  // 3
let remainder: number = valsResult[1]; // 1

// 使用元组类型
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

// 返回结果和状态
function tryParseInt(str: string): [number, boolean] {
  let parsed: number = Number.parseInt(str, 10);
  let success: boolean = !Number.isNaN(parsed);
  return [parsed, success];
}

let parsed: [number, boolean] = tryParseInt('42');
let value: number = parsed[0];     // 42
let success: boolean = parsed[1];  // true

// 返回数据和错误
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

### 可选返回值函数（T | undefined类型）

返回类型为T | undefined的函数，表示结果可能不存在。

<!-- @[optional_return_values](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
interface OrvUser {
  id: number;
  name: string;
  active: boolean;
}

// 返回可能为undefined
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

// 查找函数
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

// 获取元素
function getElement(arr: string[], index: number): string | undefined {
  if (index < 0 || index >= arr.length) {
    return undefined;
  }
  return arr[index];
}

let element: string | undefined = getElement(['a', 'b', 'c'], 1);
console.info(`${element}`); // b

// 返回null或值
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

## 函数类型

使用`(params) => returnType`形式描述函数的参数与返回值签名，可作为变量、参数和属性的类型。

### 函数类型的定义与匹配规则

函数类型赋值时需满足参数兼容和返回值兼容，参数类型可按子类型方向协变。

<!-- @[ts_function_types](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Functions.ts) -->

``` TypeScript
// 函数类型定义
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

// 函数类型必须匹配参数和返回值
type GreetingFunction = (name: string) => string;

let greet: GreetingFunction = (name: string): string => {
  return `Hello, ${name}`;
};

// 不匹配的类型会编译错误
let invalid: MathOperation = (a: string) => a; // 编译错误
```

### 函数类型作为参数

将函数作为参数（回调函数）传递，可实现自定义的比较器、过滤器、事件处理器等灵活逻辑。

<!-- @[functions_as_parameters](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
// 函数作为参数
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

// 回调函数
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

// 条件判断函数
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

### 函数类型作为返回值

函数可以作为返回值，用于创建闭包（捕获外层变量）、工厂函数（按参数生成不同行为）和延迟执行的策略模式。

<!-- @[functions_returning_functions](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
type RetMathOperation = (a: number, b: number) => number;

// 返回函数
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

// 创建器函数
function createMultiplier(factor: number): (n: number) => number {
  return (n: number): number => n * factor;
}

let functionsDouble: (n: number) => number = createMultiplier(2);
let triple: (n: number) => number = createMultiplier(3);

console.info(`${functionsDouble(5)}`); // 10
console.info(`${triple(5)}`); // 15

// 创建比较器
function createComparator(ascending: boolean): (a: number, b: number) => number {
  if (ascending) {
    return (a: number, b: number): number => a - b;
  }
  return (a: number, b: number): number => b - a;
}

let ascComparator: (a: number, b: number) => number = createComparator(true);
let descComparator: (a: number, b: number) => number = createComparator(false);
```

### 类型别名简化函数类型

用type为复杂函数类型起别名，简化签名书写。

<!-- @[function_type_aliases](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
// 使用类型别名
type Callback = (result: string) => void;
type Predicate = (value: number) => boolean;
type Transformer = (input: string) => string;
type Comparator = (a: number, b: number) => number;

// 简化复杂函数类型
type EventHandler = (event: Event) => void;

interface Event {
  type: string;
  data: string | number | boolean;
}

function addEventListener(handler: EventHandler): void {
  // 注册事件处理器
}

// 使用泛型函数类型
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

## 闭包与箭头函数

闭包是函数与其词法环境的组合。ArkTS不使用局部函数声明来构造闭包，但局部箭头函数仍然可以捕获外层作用域中的变量和参数。

### 闭包的形成

内层箭头函数捕获外层作用域的变量，即使外层函数已返回，捕获的变量仍保留状态。

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
在上例中，`increment`捕获了`createCounter`中的`count`。即使`createCounter`已经返回，`counter`仍然可以继续读取并更新这个状态。

### 捕获外层参数

闭包可捕获外层函数的参数，返回的函数持续引用该参数并据此处理后续调用。

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
闭包适合保存少量配置或状态。若状态较多、生命周期复杂，优先使用类来表达。

### 箭头函数的简写规则

箭头函数支持表达式体简写：单表达式可省略`return`和花括号，常用于回调。

<!-- @[arrow_function_syntax](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
let arrowAdd: (a: number, b: number) => number = (a: number, b: number): number => {
  return a + b;
};

let subtract: (a: number, b: number) => number = (a: number, b: number): number => a - b;
let doubleValue: (value: number) => number = (value: number): number => value * 2;
let arrowGreet: () => string = (): string => 'Hello';
```

箭头函数最常见的用途是作为数组方法的回调，其简洁的语法在高阶函数调用中尤为实用。

<!-- @[arrow_function_array_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
let numbers: number[] = [1, 2, 3, 4, 5];
let callbackDoubled: number[] = numbers.map((value: number): number => {
  return value * 2;
});
```

### 箭头函数中的this

箭头函数不绑定自己的`this`，而是捕获外层作用域的`this`，适合在类方法中作回调。

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
独立函数体内不应依赖`this`；需要实例状态时，使用类方法或显式参数传递。

## 局部辅助函数

TypeScript允许在函数内部声明局部函数，也允许使用`function`表达式。ArkTS对这两类写法做了收紧：局部函数声明不支持，函数表达式也应避免使用，应改为带显式函数类型的箭头函数。

### 局部辅助函数

TypeScript的嵌套函数声明在ArkTS中不支持，需改用带显式函数类型的箭头函数表达式替代。

**TypeScript对照**

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

ArkTS不支持上述嵌套函数声明，需将局部函数改写为带显式函数类型的箭头函数表达式：

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

### 局部辅助逻辑

局部函数封装辅助逻辑，限制作用域提高内聚性。

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
这种写法保留了局部可读性，同时符合ArkTS对函数声明位置的要求。

## 函数的重载

函数重载允许同一函数名根据不同参数类型或数量提供多个调用签名，编译器根据传入参数自动匹配对应的签名。重载解决的问题是：当函数需要对不同类型执行相似但类型不同的操作时，避免使用`any`丢失类型安全。注意：实现签名对外不可见，调用方只能使用已声明的重载签名。当参数类型不同但逻辑相同时，优先使用联合类型而非重载。

### 函数重载的声明方式

函数重载先写多个签名（仅参数和返回值类型），最后用一个实现签名覆盖。

<!-- @[function_overloading](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
// 重载签名
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

// 不同参数类型的重载
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

// 多参数重载
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

### 重载签名与实现签名的匹配

通过多个签名声明同一函数的不同调用形式，实现签名必须兼容所有重载签名。

<!-- @[overload_signatures](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
// 实现签名必须兼容所有重载签名
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

// 重载顺序：更具体的类型先声明
function sigConvert(value: string): number;
function sigConvert(value: number): string;
function sigConvert(value: string | number): string | number {
  if (typeof value === 'string') {
    return Number.parseInt(value, 10);
  }
  return value.toString();
}

// 重载与联合类型
function sigFormat(input: string): string;
function sigFormat(input: number): string;
function sigFormat(input: string | number): string {
  if (typeof input === 'string') {
    return input.toUpperCase();
  }
  return input.toFixed(2);
}
```

### 函数重载的类型约束

重载签名之间必须类型兼容，实现签名需统一处理所有情况，调用方只能按已声明的签名调用。优先使用联合类型而非重载。

<!-- @[overload_type_constraints](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
interface OverloadData {
  id: number;
  type: string;
  name?: string;
}

// 重载签名必须类型兼容，实现签名统一处理所有情况
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

// 返回类型不同的重载
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

## 高阶函数

高阶函数是接受函数作为参数或返回函数的函数，常用于抽象遍历、过滤、映射等集合操作。

### 高阶函数的定义

高阶函数接受函数作为参数或返回函数作为结果，可将遍历、过滤、映射等集合操作抽象为可复用的通用逻辑。

<!-- @[higher_order_functions](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
// 接受函数作为参数
function applyOperation(
  a: number,
  b: number,
  operation: (x: number, y: number) => number
): number {
  return operation(a, b);
}

applyOperation(5, 3, (x, y) => x + y);  // 8
applyOperation(5, 3, (x, y) => x * y);  // 15

// 返回函数
function createGreeter(greeting: string): (name: string) => string {
  return (name: string): string => `${greeting}, ${name}`;
}

let functionsSayHello: (name: string) => string = createGreeter('Hello');
let sayHi: (name: string) => string = createGreeter('Hi');

functionsSayHello('Alice');  // "Hello, Alice"
sayHi('Bob');       // "Hi, Bob"

// 既接受又返回函数
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

### 常用高阶函数（map、filter、reduce）

`map`对每个元素变换生成新数组，`filter`按条件筛选元素，`reduce`将数组归约为单个值。

<!-- @[array_higher_order_methods](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
// map：映射每个元素
let orderNumbers: number[] = [1, 2, 3, 4, 5];

let orderDoubled: number[] = orderNumbers.map((n: number): number => n * 2);
console.info(`${orderDoubled.join(', ')}`);  // 2, 4, 6, 8, 10

let squared: number[] = orderNumbers.map((n: number): number => n * n);
console.info(`${squared.join(', ')}`);  // 1, 4, 9, 16, 25

let strings: string[] = orderNumbers.map((n: number): string => `Item ${n}`);
console.info(`${strings.join(', ')}`);  // Item 1, Item 2, Item 3, Item 4, Item 5

// filter：过滤元素
let orderEvens: number[] = orderNumbers.filter((n: number): boolean => n % 2 === 0);
console.info(`${orderEvens.join(', ')}`);  // 2, 4

let greaterThan3: number[] = orderNumbers.filter((n: number): boolean => n > 3);
console.info(`${greaterThan3.join(', ')}`);  // 4, 5

// reduce：归约数组
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

// 组合使用
let orderResult: number[] = orderNumbers
  .filter((n: number): boolean => n % 2 === 0)
  .map((n: number): number => n * 2);
console.info(`${orderResult.join(', ')}`);  // 4, 8
```

### 自定义高阶函数的实现

封装通用的遍历、过滤逻辑为高阶函数，通过回调参数实现灵活扩展。

<!-- @[custom_array_methods](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
// 自定义map
function customMap<T, R>(arr: T[], mapper: (item: T) => R): R[] {
  let result: R[] = [];
  for (let item of arr) {
    result.push(mapper(item));
  }
  return result;
}

// 自定义filter
function customFilter<T>(arr: T[], predicate: (item: T) => boolean): T[] {
  let result: T[] = [];
  for (let item of arr) {
    if (predicate(item)) {
      result.push(item);
    }
  }
  return result;
}

// 自定义reduce
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

// 自定义forEach
function customForEach<T>(arr: T[], consumer: (item: T) => void): void {
  for (let item of arr) {
    consumer(item);
  }
}

// 自定义find
function customFind<T>(arr: T[], predicate: (item: T) => boolean): T | undefined {
  for (let item of arr) {
    if (predicate(item)) {
      return item;
    }
  }
  return undefined;
}
```

## 函数的可选链调用

可选链调用（?.()）在函数可能为undefined时安全调用，避免运行时错误。

### 函数的可选调用语法（func?.()）

func?.()在func不为undefined时才执行调用，否则返回undefined。

<!-- @[ts_optional_chaining_function_call](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Functions.ts) -->

``` TypeScript
// 可选调用函数
let callback: (() => void) | null = null;

callback?.();  // 不执行（callback为null）

callback = () => console.info(`Called`);
callback?.();  // 执行，输出 "Called"

// 方法可选调用
let service: Service | null = null;

service?.processData?.();  // 不执行

interface Service {
  processData?: () => void;
}

service = { processData: () => console.info(`Processing`) };
service?.processData?.();  // 执行

// 回调可选调用
function triggerEvent(callback?: () => void): void {
  callback?.();  // 安全调用
}

triggerEvent();  // 无回调，不执行
triggerEvent(() => console.info(`Event triggered`));  // 执行回调

// 对象方法可选调用
let handler: { onClick?: () => void } | null = null;

handler?.onClick?.();  // 不执行

handler = { onClick: () => console.info(`Clicked`) };
handler?.onClick?.();  // 执行
```

### 可选链调用的使用场景

可选链调用用于回调可能未注册、事件处理器可能未绑定的场景。

<!-- @[ts_optional_chaining_use_cases](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Functions.ts) -->

``` TypeScript
// 事件处理器
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

// 配置回调
interface Config {
  onSuccess?: (data: string) => void;
  onError?: (error: Error) => void;
}

function processWithCallbacks(config: Config): void {
  let result: string = 'data';
  config.onSuccess?.(result);

  // 或错误情况
  let error: Error = new Error('Failed');
  config.onError?.(error);
}

// 可选链式调用
interface Chain {
  next?: Chain;
  execute?: () => void;
}

let chain: Chain | null = { next: { execute: () => console.info(`Executed`) } };

chain?.next?.execute?.();  // 执行

// API响应处理
interface APIResponseData {
  items?: string[];
}

interface APIResponse {
  data?: APIResponseData;
  callback?: () => void;
}

let response: APIResponse | null = null;

response?.callback?.();  // 不执行
response?.data?.items?.forEach?.(item => console.info(`${item}`));
```

## 调用签名

调用签名用于描述可调用的对象（既有属性又可像函数一样调用）。语法使用`:`而非`=>`。

**TypeScript对照**

<!-- @[ts_call_signature](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Functions.ts) -->

``` TypeScript
// TypeScript对照写法，ArkTS中用接口分离属性和方法
type DescribableFunction = {
  description: string;
  (someArg: number): boolean;
};
```

ArkTS中使用接口分离属性和方法。

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

## 构造签名

构造签名描述可用`new`调用的函数，在调用签名前加`new`关键字。

**TypeScript对照**

<!-- @[ts_construct_signature](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Functions.ts) -->

``` TypeScript
// TypeScript构造签名，ArkTS不支持（arkts-no-ctor-signatures-type）
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

ArkTS不支持构造函数类型（`arkts-no-ctor-signatures-funcs`），详见[从TypeScript到ArkTS的适配规则](typescript-to-arkts-migration-guide.md#不支持构造函数类型)，使用工厂模式替代。

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

## 回调中的可选参数

TypeScript中回调函数类型不应使用可选参数，因为可选参数意味着"可能不传该参数调用"，而回调的调用方通常会传入所有参数。少参数的函数可赋给多参数的函数类型（参数逆变）。

<!-- @[callback_no_optional_params](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
// 回调参数全部为必选
type CbCallback = (value: string, index: number) => void;

let cbNames: string[] = ['Alice', 'Bob'];
cbNames.forEach((value: string, index: number) => {
  console.info(`${index}: ${value}`);
});

// 少参数的回调可赋给多参数类型
type UnaryCallback = (value: string) => void;
let cbSimple: CbCallback = (value: string): void => {
  console.info(`${value}`);
};
```

> **说明：**
> 
> 在回调函数类型中不要使用可选参数（`?`），否则调用方可能不传该参数，导致回调内部访问`undefined`。

## Function类型

TypeScript有全局`Function`类型，接受任意函数。`Function`类型调用返回`any`，不安全。需要接受任意函数时，使用`() => void`替代。

<!-- @[function_type_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
// 不建议：使用Function类型
let ftFn: Function = (x: number): number => x * 2;
console.info(`${ftFn(10)}`); // 20

// 建议：使用具体函数类型
let ftSafeFn: (x: number) => number = (x: number): number => x * 2;
console.info(`${ftSafeFn(10)}`); // 20

// 需要接受任意函数时使用 () => void
function ftRunCallback(cb: () => void): void {
  cb();
}

ftRunCallback((): void => console.info('executed'));
```

## void返回类型的赋值兼容性

`void`返回类型的函数类型有一个特殊规则：返回值为`void`的函数类型可接受返回任意值的函数实现。返回值会被忽略。此设计允许返回值的函数（如`push`返回`number`）用于期望`void`回调的场景。

<!-- @[void_return_compatibility](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Functions.ets) -->

``` TypeScript
type VcCallback = () => void;

// 返回number的函数可赋给void返回类型
let vcCb: VcCallback = (): number => {
  console.info('side effect');
  return 42;
};

vcCb(); // 打印side effect，返回值42被忽略
```

此规则仅适用于返回值类型为`void`时，不适用于其他返回类型。常用于事件处理、回调注册等不需要返回值的场景。
