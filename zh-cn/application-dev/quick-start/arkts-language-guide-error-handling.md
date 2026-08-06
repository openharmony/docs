# 错误处理
<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

错误处理是程序开发中的重要环节，良好的错误处理机制能够提高程序的健壮性和可维护性。ArkTS基于TypeScript，继承了JavaScript的错误处理机制，并在此基础上提供了更完善的类型支持。

## 错误处理的基础概念

ArkTS通过try-catch-finally捕获运行时异常，通过throw主动抛出Error对象，确保程序在异常情况下仍能优雅处理。

### 错误的定义与分类

错误是程序运行过程中发生的异常情况，分为语法错误、运行时错误和逻辑错误等类型，需要不同的处理方式。

<!-- @[ts_basic_error_types](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/ErrorHandling.ts) -->

``` TypeScript
// 编译期类型错误：number没有toUpperCase方法
let num: number = 10;
num.toUpperCase();

// 编译期名称错误：变量未声明
console.info(`${undefinedVariable}`);

// 运行期范围错误：由业务校验主动抛出
function readAt(values: number[], index: number): number {
  if (index < 0 || index >= values.length) {
    throw new RangeError('数组索引超出范围');
  }
  return values[index] ?? 0;
}

let readAtValues: number[] = [1, 2, 3];
try {
  readAt(readAtValues, 3);
} catch (error) {
  console.error(`读取失败: ${(error as Error).message}`);
}
```

### 错误处理的核心目标

错误处理的目标是捕获异常、提供恢复机制、传递错误信息，确保程序的健壮性和可用性。基本原则是：只捕获能处理的异常（不要捕获所有异常），记录错误信息便于追踪，提供合理的恢复机制或降级方案，不要在catch块中忽略异常。

<!-- @[divide_with_error_handling](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandling.ets) -->

``` TypeScript
function divide(a: number, b: number): number {
  if (b === 0) {
    throw new Error('除数不能为零');
  }
  return a / b;
}

try {
  let result: number = divide(10, 0);
  console.info(`${result}`);
} catch (error) {
  console.error(`计算失败: ${(error as Error).message}`);
  // 提供默认值，实现容错
  let fallbackResult: number = 0;
  console.info(`使用默认值: ${fallbackResult}`);
}
```

### TypeScript错误处理的常用方案

TypeScript错误处理的常用方案包括try-catch、返回错误信息、异步错误处理等多种方式。

<!-- @[error_handling_patterns](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandlingPatterns.ets) -->

``` TypeScript
// 方案1: try-catch捕获异常
function tryCatchExample(): void {
  try {
    // 可能出错的代码
    let data: Object = JSON.parse('invalid json');
  } catch (error) {
    console.error(`解析失败: ${(error as Error).message}`);
  }
}

// 方案2: 返回错误信息（函数式风格）
function parseJSON(jsonStr: string): [Object | null, Error | null] {
  try {
    let data: Object = JSON.parse(jsonStr) as Object;
    return [data, null];
  } catch (error) {
    return [null, error as Error];
  }
}

// 方案3: 异步错误处理
async function asyncErrorHandling(): Promise<void> {
  try {
    let response = await http.createHttp().request('EXAMPLE_API_URL');
    let data = response.result;
  } catch (error) {
    console.error(`请求失败: ${(error as Error).message}`);
  }
}
```

## 错误对象的创建与使用

通过`new Error(message)`创建错误对象，可携带name、message、stack等属性，catch块中通过`instanceof`区分错误类型并读取详情。

### 原生Error类的使用

JavaScript提供了原生的`Error`类作为所有错误对象的基类，是错误处理的基础类型，提供标准的错误信息结构。

<!-- @[error_object_properties](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandling.ets) -->

``` TypeScript
// 创建基本的错误对象
let error1: Error = new Error('这是一个错误');
let error2: Error = new Error(); // 可选的错误信息

// Error对象的属性
console.info(`${error1.name}`);      // 'Error'
console.info(`${error1.message}`);   // '这是一个错误'
console.info(`${error1.stack ?? '无堆栈信息'}`);     // 错误堆栈信息

// 抛出错误
function validateAge(age: number): void {
  if (age < 0 || age > 150) {
    throw new Error('年龄必须在 0 到 150 之间');
  }
}

try {
  validateAge(-5);
} catch (error) {
  console.error((error as Error).message);
}
```

### 原生错误类型

JavaScript提供了多种原生错误类型，每种类型对应特定的错误场景，便于精确识别和处理错误。

<!-- @[built_in_error_types](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandling.ets) -->

``` TypeScript
// TypeError: 类型错误
function typeErrorExample(): void {
  let num: number = 10;
  throw new TypeError('期望字符串，但得到数字');
}

// RangeError: 范围错误
function rangeErrorExample(): void {
  throw new RangeError('数组索引超出范围');
}

// ReferenceError: 引用错误
function referenceErrorExample(): void {
  throw new ReferenceError('变量未定义');
}

// SyntaxError: 语法错误
function syntaxErrorExample(): void {
  throw new SyntaxError('JSON 字符串格式不正确');
}

// URIError: URI错误
function uriErrorExample(): void {
  throw new URIError('URI 编码错误');
}
```

### 自定义错误类

通过继承`Error`类创建自定义错误类，可携带业务信息和上下文，实现精细管理。

<!-- @[custom_error_classes](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandling.ets) -->

``` TypeScript
// 自定义业务错误类
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

// 自定义验证错误类
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

// 使用自定义错误
function validateUser(username: string, age: number): void {
  if (username.length < 3) {
    throw new UserValidationError('username', username, '用户名长度至少为3个字符');
  }
  
  if (age < 18) {
    throw new UserBusinessError(1001, '用户年龄必须满18岁');
  }
}

try {
  validateUser('ab', 16);
} catch (error) {
  if (error instanceof UserValidationError) {
    console.error(`字段验证失败: ${error.field}, 值: ${error.value}, 原因: ${error.message}`);
  } else if (error instanceof UserBusinessError) {
    console.error(`业务错误: ${error.code}, ${error.message}`);
  }
}
```

### 错误传播的概念与机制

错误传播是指错误对象在当前位置创建并抛出后，沿调用栈向上传递，直至被最近的try-catch捕获；若始终未被捕获，则程序终止。

### 错误信息的封装

自定义错误类继承 Error 并扩展 code、details、context、timestamp 等字段，将错误码、上下文、堆栈等信息一并封装，并提供 toErrorInfo 等方法输出结构化错误对象，便于上层统一处理与日志记录。

<!-- @[detailed_error_class](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandling.ets) -->

``` TypeScript
interface ErrorInfo {
  code: number;           // 错误码
  message: string;         // 错误描述
  details?: string;        // 详细信息
  stack?: string;          // 堆栈信息
  timestamp: Date;         // 错误发生时间
  context?: Map<string, string>; // 错误上下文
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

// 使用示例
function processData(data: string): void {
  if (data.length === 0) {
    let context: Map<string, string> = new Map<string, string>();
    context.set('functionName', 'processData');
    context.set('inputParam', 'data');
    throw new DetailedError(
      1002,
      '数据为空',
      'processData 函数要求输入数据不能为空',
      context
    );
  }
}

try {
  processData('');
} catch (error) {
  if (error instanceof DetailedError) {
    let errorInfo: ErrorInfo = error.toErrorInfo();
    console.error(`错误码: ${errorInfo.code}`);
    console.error(`错误信息: ${errorInfo.message}`);
    console.error(`详细信息: ${errorInfo.details ?? ''}`);
    console.error(`上下文: ${errorInfo.context ? errorInfo.context.size : 0} 项`);
  }
}
```

## try-catch-finally异常捕获

try块包裹可能抛出异常的代码，catch块捕获并处理异常，finally块无论是否异常都会执行，常用于资源清理。

### 基本语法结构

try-catch-finally由三个块组成：`try`块包裹可能抛出异常的代码，`catch`块捕获并处理异常，`finally`块无论是否发生异常都会执行（常用于资源清理）。三者中`catch`和`finally`至少出现一个。

<!-- @[try_catch_finally_syntax](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandling.ets) -->

``` TypeScript
try {
  // 可能抛出异常的代码
} catch (error) {
  // 异常处理代码
} finally {
  // 无论是否发生异常都会执行的代码（可选）
}
```
<!-- @[try_catch_finally_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandling.ets) -->

``` TypeScript
function divideNumbers(a: number, b: number): number {
  if (b === 0) {
    throw new Error('除数不能为零');
  }
  return a / b;
}

// 完整的try-catch-finally结构
function calculateExample(): void {
  console.info('开始计算');
  
  try {
    let result: number = divideNumbers(10, 0);
    console.info(`计算结果: ${result}`);
  } catch (error) {
    console.error(`捕获到错误: ${(error as Error).message}`);
  } finally {
    console.info('计算结束（无论成功与否都会执行）');
  }
}

calculateExample();
// 输出:
// 开始计算
// 捕获到错误: 除数不能为零
// 计算结束（无论成功与否都会执行）
```

### 捕获特定类型的错误

在catch块中用`instanceof`判断错误类型，针对NetworkError、DatabaseError等分别执行重试、日志等不同处理逻辑。

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
    throw new NetworkError('网络连接失败');
  } else if (source === 'database') {
    throw new DatabaseError('数据库查询失败');
  } else {
    throw new Error('未知错误');
  }
}

function handleFetchData(source: string): void {
  try {
    let data = fetchData(source);
    console.info(`数据获取成功: ${data}`);
  } catch (error) {
    // 使用instanceof判断错误类型
    if (error instanceof NetworkError) {
      console.error(`网络错误: ${error.message}`);
      // 执行网络错误处理逻辑
      retryNetworkRequest();
    } else if (error instanceof DatabaseError) {
      console.error(`数据库错误: ${error.message}`);
      // 执行数据库错误处理逻辑
      logDatabaseError(error);
    } else {
      console.error(`未知错误: ${(error as Error).message}`);
    }
  }
}

function retryNetworkRequest(): void {
  console.info('重试网络请求...');
}

function logDatabaseError(error: DatabaseError): void {
  console.info(`记录数据库错误: ${error.message}`);
}

handleFetchData('network');  // 网络错误: 网络连接失败
handleFetchData('database'); // 数据库错误: 数据库查询失败
handleFetchData('other');    // 未知错误: 未知错误
```

### finally块的执行特性

无论try块是否抛出异常、catch是否捕获，finally块都会执行，常用于释放资源、关闭连接等收尾工作；即便try中return，finally也会在返回前运行。

<!-- @[resource_cleanup_finally](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandling.ets) -->

``` TypeScript
class DemoResource {
  public name: string;
  
  constructor(name: string) {
    this.name = name;
    console.info(`${name} 资源已创建`);
  }
  
  public use(): void {
    console.info(`${this.name} 资源正在使用`);
    throw new Error('使用资源时发生错误');
  }
  
  public cleanup(): void {
    console.info(`${this.name} 资源已清理`);
  }
}

function useResource(): void {
  let resource: DemoResource | null = null;
  
  try {
    resource = new DemoResource('数据库连接');
    resource.use();
  } catch (error) {
    console.error('捕获错误:', (error as Error).message);
  } finally {
    // 确保资源被清理
    if (resource) {
      resource.cleanup();
    }
  }
}

useResource();
// 输出:
// 数据库连接 资源已创建
// 数据库连接 资源正在使用
// 捕获错误: 使用资源时发生错误
// 数据库连接 资源已清理
```

除了资源清理，finally块还有一个值得注意的特性：即使try块中使用了return，finally仍会在函数返回前执行。

<!-- @[finally_with_return](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandling.ets) -->

``` TypeScript
function testFinally(): string {
  try {
    console.info('try 块');
    return 'return from try';
  } catch (error) {
    console.info('catch 块');
    return 'return from catch';
  } finally {
    console.info('finally 块');
    // finally块中不要使用return，会覆盖try/catch的返回值
  }
}

let result: string = testFinally();
console.info(`返回值: ${result}`);
// 输出:
// try块
// finally块
// 返回值: return from try
```

### 嵌套try-catch的使用场景

嵌套try-catch是在try-catch块内部再使用try-catch的错误处理方式，用于分层处理不同层次的错误。

<!-- @[ts_nested_try_catch](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/ErrorHandling.ts) -->

``` TypeScript
function nestedErrorHandling(): void {
  try {
    console.info(`外层 try`);

    try {
      console.info(`内层 try`);
      throw new Error('内层错误');
    } catch (innerError) {
      console.info(`内层 catch: ${(innerError as Error).message}`);
      // 决定是否向上层抛出错误
      throw innerError; // 将错误传递到外层
    }

    console.info(`外层 try 继续`);
  } catch (outerError) {
    console.info(`外层 catch: ${(outerError as Error).message}`);
  }
}

nestedErrorHandling();
// 输出:
// 外层try
// 内层try
// 内层catch: 内层错误
// 外层try继续
```

## 抛出错误（throw语句）

throw语句抛出Error对象，中断当前函数执行并将控制权转移到调用栈中最近的try-catch块。

### 抛出原生Error实例

使用`throw`关键字抛出`Error`对象或其子类实例，中断当前函数执行并将控制权转移到调用栈中最近的`catch`块。ArkTS应抛出`Error`体系对象，避免抛出字符串或数字等非Error值。

<!-- @[email_validation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandling.ets) -->

``` TypeScript
function validateEmail(email: string): void {
  let emailRegex: RegExp = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
  
  if (!email) {
    throw new Error('邮箱地址不能为空');
  }
  
  if (!emailRegex.test(email)) {
    throw new Error(`无效的邮箱地址: ${email}`);
  }
}

try {
  validateEmail('invalid-email');
} catch (error) {
  console.error(`验证失败: ${(error as Error).message}`);
}
```

### 抛出自定义错误实例

继承Error创建自定义错误类（如AppError），扩展code、field等业务字段，使catch块能按业务语义区分错误。

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
    throw new AppError(1001, '取款金额必须大于零');
  }
  
  if (amount > balance) {
    throw new AppError(1002, '余额不足');
  }
  
  return balance - amount;
}

try {
  let newBalance: number = withdrawMoney(100, 200);
  console.info(`取款成功，余额: ${newBalance}`);
} catch (error) {
  if (error instanceof AppError) {
    console.error(`错误码: ${error.code}, 错误信息: ${error.message}`);
    // 根据错误码执行不同逻辑
    if (error.code === 1002) {
      console.info('建议: 请先存款或申请贷款');
    }
  }
}
```

### 抛出非Error值的限制

TypeScript允许抛出任意类型的值，但ArkTS中应抛出`Error`体系对象，避免调用方无法稳定读取错误信息和堆栈。

**TypeScript对照**

<!-- @[ts_throw_non_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/ErrorHandling.ts) -->

``` TypeScript
// TypeScript允许抛出任意类型，ArkTS只能抛出Error
throw 'Something went wrong';
```

**TypeScript对照**

<!-- @[ts_throw_best_practices](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/ErrorHandling.ts) -->

``` TypeScript
// TypeScript对照写法，ArkTS中不要这样写：
function badExample1(): void {
  throw '这是一个字符串错误';
}

function badExample2(): void {
  throw 404;
}

function badExample3(): void {
  throw { code: 1001, message: '自定义错误对象' };
}

// 正确做法：始终抛出Error实例
function goodExample(): void {
  throw new Error('这是一个标准错误');
}

try {
  goodExample();
} catch (error) {
  if (error instanceof Error) {
    console.error(`Error 对象: ${error.message}`);
  } else {
    console.error('未知类型错误');
  }
}
```

### 函数内抛出错误的声明与提示

通过JSDoc的@throws标注函数可能抛出的错误类型。

<!-- @[function_throws_documentation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandling.ets) -->

``` TypeScript
/**
 * 除法运算
 * @param a 被除数
 * @param b 除数
 * @returns 商
 * @throws {Error} 当除数为零时抛出错误
 */
function documentationDivide(a: number, b: number): number {
  if (b === 0) {
    throw new Error('除数不能为零');
  }
  return a / b;
}

/**
 * 解析JSON字符串
 * @param jsonStr JSON字符串
 * @returns 解析后的对象
 * @throws {SyntaxError} 当JSON格式不正确时抛出错误
 */
function documentationParseJSON(jsonStr: string): Object {
  try {
    return JSON.parse(jsonStr) as Object;
  } catch (error) {
    throw new SyntaxError('JSON 字符串格式不正确');
  }
}
```

## 函数的错误声明与处理约定

函数错误声明约定异常处理方式，明确错误传播路径，使调用方了解函数可能产生的错误并据此编写处理逻辑。常见约定包括：JSDoc `@throws`标注可能抛出的错误类型、返回`Result<T>`类型对象（含`data`和`error`字段）替代异常抛出、使用错误码区分不同错误场景。

### 函数返回值包含错误信息

使用显式结果对象返回数据和错误，避免使用异常处理，这样可以提供结构化的错误信息和数据返回方式。

<!-- @[result_type_pattern](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandling.ets) -->

``` TypeScript
interface Result<T> {
  data: T | null;
  error: Error | null;
}

// 函数返回数据与错误
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
    console.error('解析失败:', parseResult.error.message);
} else {
    console.info(`解析成功: ${parseResult.data}`);
}

// 另一个示例
function patternDivideNumbers(a: number, b: number): Result<number> {
  if (b === 0) {
    return {
      data: null,
      error: new Error('除数不能为零')
    };
  }
  return {
    data: a / b,
    error: null
  };
}

let divideResult: Result<number> = patternDivideNumbers(10, 2);
if (divideResult.error !== null) {
    console.error('计算失败:', divideResult.error.message);
} else {
    console.info(`计算结果: ${divideResult.data}`);
}
```

### 结合可选链与空值合并处理潜在错误

用可选链?.安全访问可能为null或undefined的深层属性，避免运行时抛错；用空值合并??在链路结果为nullish时提供默认值。二者结合可在不写try-catch的前提下优雅处理缺失数据。

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
  // 使用可选链和空值合并
  return user?.email ?? '未设置邮箱';
}

function getAvatar(user: ErrorHandlingUser | null): string {
  return user?.profile?.avatar ?? 'default-avatar.png';
}

// 示例
let errorUser1: ErrorHandlingUser = { id: 1, name: 'Alice' };
let errorUser2: ErrorHandlingUser = { id: 2, name: 'Bob', email: 'bob@example.com' };
let errorUser3: ErrorHandlingUser = {
  id: 3,
  name: 'Charlie',
  profile: { avatar: 'charlie.png', bio: 'Developer' }
};

console.info(`${getUserEmail(errorUser1)}`); // '未设置邮箱'
console.info(`${getUserEmail(errorUser2)}`); // 'bob@example.com'
console.info(`${getAvatar(errorUser1)}`);    // 'default-avatar.png'
console.info(`${getAvatar(errorUser3)}`);    // 'charlie.png'
```

### 异步函数的错误处理

异步函数的错误处理可以使用async/await结合try-catch或Promise.catch() 来实现。

<!-- @[async_await_error_handling](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandling.ets) -->

``` TypeScript
async function fetchUserData(userId: number): Promise<string> {
  try {
    if (userId <= 0) {
      throw new Error(`无效的用户ID: ${userId}`);
    }
    return `用户${userId}的数据`;
  } catch (error) {
    console.error(`获取用户数据失败: ${(error as Error).message}`);
    throw new Error((error as Error).message);
  }
}

async function aehMain(): Promise<void> {
  try {
    let user: string = await fetchUserData(1);
    console.info(`用户信息: ${user}`);
  } catch (error) {
    console.error(`主流程错误: ${(error as Error).message}`);
  }
}

aehMain();
```

## 异步代码的错误处理

async函数中用try-catch包裹await表达式捕获Promise rejection。

### async/await结合try-catch捕获异步错误

async/await结合try-catch是处理异步错误的标准方式，提供清晰的异步错误处理流程。

<!-- @[promise_try_catch](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandling.ets) -->

``` TypeScript
async function asyncOperation(): Promise<string> {
  // 模拟异步操作
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      let success = Math.random() > 0.5;
      if (success) {
        resolve('操作成功');
      } else {
        reject(new Error('操作失败'));
      }
    }, 1000);
  });
}

// 使用try-catch捕获异步错误
async function handleAsyncOperation(): Promise<void> {
  try {
    let result = await asyncOperation();
    console.info(`结果: ${result}`);
    } catch (error) {
    console.error('捕获异步错误:', (error as Error).message);
  }
}

handleAsyncOperation();
```

### Promise的.catch() 链式捕获错误

Promise的.catch()方法是链式捕获Promise错误的方式，提供Promise链的错误处理机制。

<!-- @[promise_catch_finally_chain](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandling.ets) -->

``` TypeScript
// 使用Promise.catch() 捕获错误
function promiseErrorOperation(): Promise<string> {
  return Promise.resolve('success');
}

function promiseCatchExample(): void {
  promiseErrorOperation()
    .then((result: string): string => {
      console.info(`成功: ${result}`);
      return result.toUpperCase();
    })
    .then((upperResult: string): void => {
      console.info(`转换后: ${upperResult}`);
    })
    .catch((error: Error): void => {
      console.error(`捕获错误: ${error.message}`);
    })
    .finally((): void => {
      console.info('操作结束');
    });
}

promiseCatchExample();
```

### 多个异步操作的错误处理

Promise.all中任一任务失败则整体进入catch，可逐个catch独立处理。

<!-- @[promise_all_error_handling](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/PromiseAllErrorHandling.ets) -->

``` TypeScript
import http from '@ohos.net.http';

async function parallelErrorHandling(): Promise<void> {
  try {
    // 并行执行多个异步操作
    let results = await Promise.all([
      http.createHttp().request('EXAMPLE_API_URL/users'),
      http.createHttp().request('EXAMPLE_API_URL/posts'),
      http.createHttp().request('EXAMPLE_API_URL/comments')
    ]);
    
    let usersRes = results[0];
    let postsRes = results[1];
    let commentsRes = results[2];
    console.info(`所有请求成功: ${usersRes.responseCode}, ${postsRes.responseCode}, ${commentsRes.responseCode}`);
  } catch (error) {
    console.error(`至少一个请求失败: ${(error as Error).message}`);
  }
}

// 使用Promise.allSettled获取所有结果（无论成功或失败）
async function allSettledExample(): Promise<void> {
  let results = await Promise.allSettled([
    Promise.resolve('成功1'),
    Promise.reject(new Error('失败1')),
    Promise.resolve('成功2')
  ]);
  
  results.forEach((result, index) => {
    if (result.status === 'fulfilled') {
      console.info(`第${index + 1}个成功: ${result.value}`);
    } else {
      console.error(`第${index + 1}个失败:`, result.reason);
    }
  });
}

allSettledExample();
// 输出:
// 第1个成功: 成功1
// 第2个失败: 失败1
// 第3个成功: 成功2
```

与并行执行不同，串行异步操作中每一步依赖前一步的结果，错误处理需要记录已完成步骤以便排查和恢复。

<!-- @[serial_async_error_handling](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandling.ets) -->

``` TypeScript
function serialAsyncOperation(stepName: string): Promise<string> {
  return Promise.resolve(`${stepName}完成`);
}

async function serialErrorHandling(): Promise<void> {
  let stepResults: string[] = [];
  
  try {
    // 第一步
    let step1: string = await serialAsyncOperation('第一步');
    stepResults.push(step1);
    
    // 第二步（依赖第一步）
    let step2: string = await serialAsyncOperation('第二步');
    stepResults.push(step2);
    
    // 第三步（依赖第二步）
    let step3: string = await serialAsyncOperation('第三步');
    stepResults.push(step3);
    
    console.info(`所有步骤成功: ${stepResults.join(', ')}`);
  } catch (error) {
    console.error(`步骤执行失败: ${(error as Error).message}`);
    console.info(`已完成的步骤: ${stepResults.join(', ')}`);
  }
}

serialErrorHandling();
```

### 全局异步错误的监听

通过`unhandledRejection`事件捕获未处理的Promise rejection。

<!-- @[unhandled_rejection_handler](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/UnhandledRejectionHandler.ets) -->

``` TypeScript
import errorManager from '@ohos.app.ability.errorManager';

// 监听未处理的Promise拒绝
errorManager.on('unhandledRejection', (reason: Error, promise: Promise<Object>) => {
  console.error(`未处理的 Promise 拒绝: ${reason.message}`);
});

// 示例：触发全局错误处理
async function triggerUnhandledRejection(): Promise<void> {
  // 这个错误没有try-catch或.catch() 处理
  await Promise.reject(new Error('未捕获的 Promise 错误'));
}

triggerUnhandledRejection(); // 运行时报错，将触发全局错误监听器
```

## 错误恢复与兜底策略

捕获错误后返回默认值或执行降级逻辑，确保调用方拿到有效结果。

### 捕获错误后的默认值返回

catch块中返回默认值，保证函数总有有效返回。

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
    console.info(`JSON解析失败，使用默认值: ${(error as Error).message}`);
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
    throw new Error('索引超出范围');
  } catch (error) {
    console.info(`数组访问失败，使用默认值: ${(error as Error).message}`);
    return defaultValue;
  }
}

let fbNumbers: number[] = [1, 2, 3];
console.info(`${safeArrayAccess(fbNumbers, 5, 0)}`); // 0（索引超出范围）
```

### 错误重试机制的实现

对可能间歇失败的异步操作封装重试逻辑：在循环中执行操作，失败时按固定间隔或指数退避等待后重试，达到最大次数仍失败则抛出累计错误，以提升调用的鲁棒性。

<!-- @[retry_with_backoff](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandling.ets) -->

``` TypeScript
interface RetryExampleOptions {
  maxRetries: number;      // 最大重试次数
  delay: number;           // 重试间隔（毫秒）
  backoff?: boolean;       // 是否使用指数退避
}

async function retryExampleAsyncOperation<T>(
  operation: () => Promise<T>,
  options: RetryExampleOptions
): Promise<T> {
  let lastError: Error | null = null;
  
  for (let attempt = 0; attempt <= options.maxRetries; attempt++) {
    try {
      let result = await operation();
      console.info(`操作成功（第${attempt + 1}次尝试）`);
      return result;
    } catch (error) {
      lastError = error as Error;
      console.info(`第${attempt + 1}次尝试失败: ${lastError.message}`);
      
      if (attempt < options.maxRetries) {
        // 计算等待时间
        let waitTime = options.delay;
        if (options.backoff) {
          waitTime = options.delay * Math.pow(2, attempt);
        }
        
        console.info(`等待 ${waitTime}ms 后重试...`);
        await new Promise<void>((resolve: () => void) => setTimeout(resolve, waitTime));
      }
    }
  }
  
  throw new Error(`重试${options.maxRetries}次后仍然失败: ${lastError ? lastError.message : '未知错误'}`);
}

// 使用示例
let retryAttemptCount: number = 0;

async function retryExampleUnstableOperation(): Promise<string> {
  retryAttemptCount++;
  if (retryAttemptCount < 2) {
    throw new Error('操作失败');
  }
  return '操作成功';
}

async function testRetry(): Promise<void> {
  try {
    let result: string = await retryExampleAsyncOperation<string>(
      retryExampleUnstableOperation,
      { maxRetries: 3, delay: 10, backoff: true }
    );
    console.info(`最终结果: ${result}`);
  } catch (error) {
    console.error(`所有重试均失败: ${(error as Error).message}`);
  }
}

testRetry();
```

### 降级处理方案

异常发生时执行降级逻辑，保证系统基本功能正常运行。

<!-- @[service_fallback_pattern](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ErrorHandling.ets) -->

``` TypeScript
interface FallbackDataService {
  getData(): Promise<string>;
}

class PrimaryDataService implements FallbackDataService {
  async getData(): Promise<string> {
        // 模拟主服务可能失败
    throw new Error('主服务不可用');
  }
}

class SecondaryDataService implements FallbackDataService {
  async getData(): Promise<string> {
    return '备用服务数据';
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
      // 尝试使用主服务
      return await this.primaryService.getData();
    } catch (error) {
      console.info(`主服务失败，切换到备用服务: ${(error as Error).message}`);
      
      try {
        // 使用备用服务
        return await this.fallbackService.getData();
      } catch (fallbackError) {
        console.error(`备用服务也失败: ${(fallbackError as Error).message}`);
        // 返回默认数据
        return '默认数据';
      }
    }
  }
}

// 使用示例
async function runDataFetcherExample(): Promise<void> {
  let fetcher: ResilientDataFetcher = new ResilientDataFetcher();
  let data = await fetcher.fetchData();
  console.info(`获取的数据: ${data}`);
}

runDataFetcherExample();
```

### 综合示例：完整的错误处理流程

结合重试、超时、降级和日志，构建完整的API调用错误处理流程。

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
          console.info(`请求失败，第${attempt + 1}次重试...`);
          await this.delay(1000 * (attempt + 1));
        }
      }
    }

    throw new Error(`请求失败: ${lastError?.message}`);
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
          reject(new Error('网络错误'));
        } else {
          resolve(`数据来自${url}`);
        }
      }, 100);
    });
  }
}

async function retryFetchUserInfo(): Promise<void> {
  let client: ApiClient = new ApiClient('EXAMPLE_API_URL', { maxRetries: 2, timeout: 3000 });

  try {
    let user: string = await client.get('/users/1');
    console.info(`用户信息: ${user}`);
  } catch (error) {
    console.error(`获取用户信息失败: ${(error as Error).message}`);
    console.info('使用默认用户信息');
  }
}

retryFetchUserInfo();
```

## catch变量的类型

在`strict`模式下，`catch`子句中的变量类型为`unknown`，必须先进行类型检查才能访问错误属性。

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
    // error类型不能直接访问.message
    if (error instanceof Error) {
      console.info(`Error: ${error.message}`);
    } else {
      console.info(`Unknown error: ${error}`);
    }
  }
}

cuProcessData('abc');  // Error: Invalid number: abc
```

捕获特定类型的错误时，使用`instanceof`区分不同错误类型。

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
      console.info(`验证错误 [${error.field}]: ${error.message}`);
    } else if (error instanceof CsNetworkError) {
      console.info(`网络错误 [${error.statusCode}]: ${error.message}`);
    } else if (error instanceof Error) {
      console.info(`未知错误: ${error.message}`);
    } else {
      console.info(`未知异常: ${error}`);
    }
  }
}

csHandleRequest('');  // 验证错误 [url]: URL cannot be empty
csHandleRequest('EXAMPLE_API_URL');  // 网络错误 [500]: Server error
```

## 断言函数

断言函数在运行时检查条件，不满足时抛出异常。TypeScript中调用后可收窄类型。ArkTS中用if检查替代。

**TypeScript对照**

<!-- @[ts_assertion_functions](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/ErrorHandling.ts) -->

``` TypeScript
// TypeScript对照写法，ArkTS中用if检查替代
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

ArkTS中使用if检查和类型守卫函数替代。

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
