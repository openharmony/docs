# 高级运算符
<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

ArkTS提供丰富的高级运算符用于位运算、类型判断、对象操作等场景。ArkTS的高级运算符包括位运算符（按位与、或、异或、取反、左移、右移）、可选链（?.）、空值合并（??）、展开运算符（...），用于处理位级操作、安全访问和集合展开等复杂场景。

## 高级运算符的基础概念

ArkTS的高级运算符包括位运算、可选链（?.）、空值合并（??）和展开/剩余运算符（...），用于处理更复杂的逻辑表达式。

### 高级运算符与基础运算符的区别

与基础运算符（算术、比较、逻辑、赋值）不同，高级运算符处理位级操作、空值安全访问、集合展开和条件求值等场景，在复杂数据结构和异步编程中广泛使用。

<!-- @[operator_basics_and_advanced](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
// 基础运算符
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

// 高级运算符
let flags: number = 0b1010 & 0b1100;
let extracted: string = obj?.name ?? 'unknown';
let copied: number[] = [...values];
```

### 运算符的优先级与结合性

运算符的优先级决定了表达式中运算的执行顺序，结合性决定了相同优先级运算符的计算方向。

<!-- @[operator_precedence](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
// 优先级从高到低示例
let result: number = 2 + 3 * 4;        // 14（先乘后加）
let boolA: boolean = true;
let boolB: boolean = false;
let boolC: boolean = true;
let result2: boolean = boolA || boolB && boolC;    // 先 && 后 ||
let textA: boolean = true;
let textB: string = 'yes';
let textC: string | null = null;
let textD: string = 'fallback';
let result3: string = textA ? textB : (textC ?? textD);  // 先 ?? 后 ?:

// 结合性：左结合（从左到右）
let value: number = 10 - 5 - 2;
console.info(`${value}`);  // 3

// 结合性：右结合（从右到左）
let textE: string = 'other';
let result4: string = textA ? textB : (boolC ? textD : textE);
console.info(`${result4}`);  // yes
```

## 位运算符

位运算符直接操作整数的二进制位，常用于权限标志位管理、数据压缩、加密解密和性能敏感的数学计算。例如，用按位OR组合权限（`READ | WRITE`）、用按位AND检查权限（`flags & READ`）、用按位XOR切换标志（`flags ^ TOGGLE`）。位运算在底层开发和系统编程中广泛使用，日常业务逻辑中较少直接使用。

### 按位与 (&)

按位与运算符对两个整数的每一位执行逻辑与操作，仅当对应位都为1时结果为1。

<!-- @[bitwise_and](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
let a: number = 5;   // 二进制0101
let b: number = 3;   // 二进制0011
let bitAndResult: number = a & b;  // 二进制0001，十进制1

// 使用场景：检查标志位
const READ: number = 0b001;
const WRITE: number = 0b010;
const EXECUTE: number = 0b100;

let permission: number = 0b110;  // 可写可执行

let canRead: boolean = (permission & READ) !== 0;
let canWrite: boolean = (permission & WRITE) !== 0;
let canExecute: boolean = (permission & EXECUTE) !== 0;

console.info(`读取: ${canRead}`);      // false
console.info(`写入: ${canWrite}`);     // true
console.info(`执行: ${canExecute}`);   // true

// 清除标志位
permission = permission & ~WRITE;  // 清除写入权限
```

### 按位或 (|)

按位或运算符对两个整数的每一位执行逻辑或操作，只要对应位有1则结果为1。

<!-- @[bitwise_or](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
let bitOrA: number = 5;   // 二进制: 0101
let bitOrB: number = 3;   // 二进制: 0011
let bitOrResult: number = bitOrA | bitOrB;  // 二进制: 0111 (十进制: 7)

// 使用场景：设置标志位
const BOLD: number = 0b001;
const ITALIC: number = 0b010;
const UNDERLINE: number = 0b100;

let style: number = 0;
style = style | BOLD | ITALIC;  // 设置加粗和斜体

// 组合多个标志
let fullStyle: number = BOLD | ITALIC | UNDERLINE;  // 0b111
```

### 按位异或 (^)

按位异或运算符对两个整数的每一位执行异或操作，对应位不同时结果为1。

<!-- @[bitwise_xor](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
let bitXorA: number = 5;   // 二进制: 0101
let bitXorB: number = 3;   // 二进制: 0011
let bitXorResult: number = bitXorA ^ bitXorB;  // 二进制: 0110 (十进制: 6)

// 使用场景：切换标志位
let bitXorFlags: number = 0b101;
bitXorFlags = bitXorFlags ^ 0b001;  // 切换第0位: 0b100
bitXorFlags = bitXorFlags ^ 0b001;  // 再次切换第0位: 0b101

// 简单加密
let data: number = 42;
let key: number = 123;
let encrypted: number = data ^ key;
let decrypted: number = encrypted ^ key;
console.info(`${decrypted === data}`);  // true
```

### 按位非 (~)

按位非运算符对整数的每一位执行取反操作，将0变为1、将1变为0。

<!-- @[bitwise_not](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
let bitNotA: number = 5;   // 二进制: 0101
let bitNotResult: number = ~bitNotA;  // 二进制: ...11111010 (十进制: -6)

// 公式: ~x = -(x + 1)
console.info(`${~5}`);   // -6
console.info(`${~(-6)}`); // 5

// 使用场景：清除标志位
const FLAG: number = 0b010;
let bitNotValue: number = 0b111;
bitNotValue = bitNotValue & ~FLAG;  // 清除第1位: 0b101
```

### 左移运算符 (<<)

左移运算符将整数的二进制位向左移动指定位数，相当于乘以2的幂次。

<!-- @[left_shift](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
let lshiftA: number = 5;   // 二进制: 0101
let lshiftResult: number = lshiftA << 2;  // 二进制: 010100 (十进制: 20)

// 左移n位相当于乘以2^n
console.info(`${5 << 1}`);  // 10 (5 * 2)
console.info(`${5 << 2}`);  // 20 (5 * 4)
console.info(`${5 << 3}`);  // 40 (5 * 8)

// 使用场景：快速乘法
let base: number = 10;
let doubled: number = base << 1;   // 20
let quadrupled: number = base << 2;  // 40
```

### 右移运算符 (>>)

右移运算符将整数的二进制位向右移动指定位数，相当于除以2的幂次。

<!-- @[right_shift](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
let rshiftA: number = 20;  // 二进制010100
let rshiftResult: number = rshiftA >> 2;  // 二进制0101，十进制5

// 右移n位相当于除以2^n（向下取整）
console.info(`${20 >> 1}`);  // 10
console.info(`${20 >> 2}`);  // 5
console.info(`${20 >> 3}`);  // 2

// 负数右移
let neg: number = -20;
console.info(`${neg >> 2}`);  // -5

// 使用场景：快速除法
let total: number = 100;
let half: number = total >> 1;  // 50
let quarter: number = total >> 2;  // 25
```

### 无符号右移运算符 (>>>)

无符号右移运算符将整数二进制位向右移动，左侧补零。与`>>`的区别：`>>`保留符号位（负数左侧补1），`>>>`无论正负左侧都补零。常见用途是通过`>>> 0`将浮点数转换为32位无符号整数。

<!-- @[unsigned_right_shift](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
let rshiftA2: number = 20;  // 二进制: 010100
let rshiftResult2: number = rshiftA2 >>> 2;  // 二进制: 0101 (十进制: 5)

// 对正数与 >> 效果相同
console.info(`${20 >> 2}`);   // 5
console.info(`${20 >>> 2}`);  // 5

// 对负数的处理不同
let rshiftNeg: number = -20;  // 二进制: ...11101100
console.info(`${rshiftNeg >> 2}`);    // -5（保留符号位）
console.info(`${rshiftNeg >>> 2}`);   // 1073741819（符号位变成0）

// 使用场景：转换为无符号整数
function toUnsigned(value: number): number {
  return value >>> 0;
}
```

## 复合赋值运算符

复合赋值运算符将运算和赋值合并为一个操作。

### 复合赋值的语法格式

复合赋值运算符将二元运算与赋值合并为单步操作，等价于`x = x op y`的简写。算术类支持`+=`、`-=`、`*=`、`/=`、`%=`、`**=`，位运算类支持`&=`、`|=`、`^=`、`<<=`、`>>=`、`>>>=`。

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

### 位运算复合赋值

位运算复合赋值包括`&=`（按位与赋值）、`|=`（按位或赋值）、`^=`（按位异或赋值）、`<<=`（左移赋值）、`>>=`（右移赋值）、`>>>=`（无符号右移赋值），将位运算结果直接赋值给左操作数。

<!-- @[compound_assignment_bitwise](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
let compoundFlags: number = 0b1010;

// 按位与赋值
compoundFlags &= 0b1100;  // compoundFlags = compoundFlags & 0b1100 = 0b1000

// 按位或赋值
compoundFlags |= 0b0011;  // compoundFlags = compoundFlags | 0b0011 = 0b1011

// 按位异或赋值
compoundFlags ^= 0b0001;  // compoundFlags = compoundFlags ^ 0b0001 = 0b1010

// 左移赋值
let compoundValue: number = 5;
compoundValue <<= 2;  // compoundValue = compoundValue << 2 = 20

// 右移赋值
compoundValue >>= 1;  // compoundValue = compoundValue >> 1 = 10

// 无符号右移赋值
compoundValue >>>= 1;  // compoundValue = compoundValue >>> 1 = 5
```

### 算术运算复合赋值

算术运算复合赋值包括`+=`、`-=`、`*=`、`/=`、`%=`、`**=`，将算术运算结果直接赋值给左操作数。

<!-- @[compound_assignment_arithmetic](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
// 加法赋值
let compoundTotal: number = 100;
compoundTotal += 50;
console.info(`${compoundTotal}`);  // 150

// 减法赋值
let balance: number = 1000;
balance -= 200;
console.info(`${balance}`);  // 800

// 乘法赋值
let price: number = 10;
price *= 2;
console.info(`${price}`);  // 20

// 除法赋值
let amount: number = 100;
amount /= 4;
console.info(`${amount}`);  // 25

// 取模赋值
let compoundValue2: number = 17;
compoundValue2 %= 5;
console.info(`${compoundValue2}`);  // 2

// 指数赋值
let compoundBase: number = 2;
compoundBase **= 4;
console.info(`${compoundBase}`);  // 16
```

### 复合赋值的运算顺序

复合赋值先计算右侧表达式，再将结果赋值给左侧变量。

<!-- @[compound_assignment_precedence](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
// 复合赋值是右结合的
let capA: number = 10;
capA += 5;  // 先计算右侧表达式，再赋值

// 复合表达式
let capB: number = 5;
capA += capB * 2;  // a = a + (b * 2) = 10 + 10 = 20

// 反例：链式复合赋值
let capX: number = 10;
let capY: number = 20;
capX += capY += 5;  // 混淆，反例
```

## 比较运算符与类型判断

比较运算符判断值的关系，返回布尔结果。

### 严格相等与非严格相等

严格相等（===）比较值和类型，非严格相等（==）会进行类型转换，ArkTS推荐使用严格相等。

<!-- @[ts_strict_equality](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/AdvancedOperators.ts) -->

``` TypeScript
// 严格相等 (===)：比较值和类型
let strictA: number = 5;
let strictB: string = '5';

console.info(`${strictA === 5}`);    // true
console.info(`${strictA === strictB}`);    // 编译错误：number和string类型不同
console.info(`${strictA === '5'}`);  // 编译错误：number和string类型不同

// 非严格相等 (==) 会进行类型转换后比较，不建议使用
console.info(`${strictA == strictB}`);  // true（隐式转换，不建议）

// 严格不等 (!==)
console.info(`${strictA !== strictB}`);    // 编译错误：number和string类型不同

// 反例：非严格不等 (!=)
console.info(`${strictA != strictB}`);  // TypeScript对照写法

// 推荐实践：始终使用严格相等
function compareValues(x: number | string, y: number | string): boolean {
  if (typeof x === typeof y) {
    return x === y;
  }
  return false;
}
```

### 对象引用比较

`===` 比较两个引用是否指向同一对象，不比较内容是否相同。

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

// 引用比较：比较内存地址
console.info(`${p1 === p2}`);  // false（不同对象）
console.info(`${p1 === p3}`);  // true（同一引用）

// 值比较：需要自定义方法
function pointsEqual(p1: Point, p2: Point): boolean {
  return p1.x === p2.x && p1.y === p2.y;
}

console.info(`${pointsEqual(p1, p2)}`);  // true

// 数组比较
let arr1: number[] = [1, 2, 3];
let arr2: number[] = [1, 2, 3];
let arr3: number[] = arr1;

console.info(`${arr1 === arr2}`);  // false
console.info(`${arr1 === arr3}`);  // true
```

### 类型守卫结合比较运算符

类型守卫使用typeof、instanceof等运算符在运行时检查类型，缩小类型范围。

<!-- @[type_guards](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
// typeof类型守卫
function process(value: number | string): string {
  if (typeof value === 'number') {
    return `Number: ${value}`;
  } else {
    return `String: ${value}`;
  }
}

// instanceof类型守卫
class Animal {
  public name: string = '';
}

class Dog extends Animal {
  public breed: string = '';
}

let pet: Animal = new Dog();

if (pet instanceof Dog) {
  console.info(`${pet.breed}`);  // 类型为Dog
}

// 判别字段类型守卫
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

### 比较运算符的返回值特性

比较运算符始终返回布尔值，可用于条件表达式和逻辑运算。

<!-- @[ts_comparison_operators](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/AdvancedOperators.ts) -->

``` TypeScript
// 比较运算符返回布尔值
let cmpResult: boolean = 5 > 3;  // true

// 可用于条件表达式
let cmpA: number = 10;
let cmpB: number = 20;
let cmpMax: number = cmpA > cmpB ? cmpA : cmpB;

// 链式比较（需要分开写）
// 不支持：if (1 < x < 10)
// 正确写法：
let cmpX: number = 5;
if (1 < cmpX && cmpX < 10) {
  // x在 (1, 10) 区间
}

// 比较不同类型
let cmpNum: number = 5;
let str: string = '5';
cmpNum > str;  // 编译错误，类型不匹配
```

## 逻辑运算符的高级用法

逻辑运算符支持短路求值——左侧结果已能决定整体值时跳过右侧执行，常用于条件守卫和空值保护。

### 逻辑与短路求值

逻辑与（&&）在左侧为false时跳过右侧执行，用于条件守卫和避免空引用。

<!-- @[logical_and_short_circuit](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
// && 短路：左侧为false时，右侧不执行
function expensiveOperation(): boolean {
  console.info('执行昂贵操作');
  return true;
}

let enabled: boolean = false;
let andResult: boolean = enabled && expensiveOperation();  // 不执行expensiveOperation

// 使用场景：条件执行
interface Profile {
  name: string;
}

interface User {
  profile?: Profile;
}

function getUserName(user: User | null): string {
  return user?.profile?.name ?? 'Unknown';
}

// 使用场景：前置条件检查
function processArray(arr: number[] | null): number {
  if (arr !== null && arr.length > 0) {
    return arr[0] ?? -1;
  }
  return -1;
}

// 使用场景：权限检查
function canAccess(user: User | null, requiredRole: string): boolean {
  return user !== null && user.profile !== undefined && user.profile.name !== '';
}
```

### 逻辑或短路求值

逻辑或（||）在左侧为true时跳过右侧执行，用于提供默认值。

<!-- @[logical_or_short_circuit](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
// || 短路：左侧为true时，右侧不执行
function getDefault(): string {
  console.info('获取默认值');
  return 'default';
}

let provided: string = 'provided';
let orValue: string = provided || getDefault();  // 不执行getDefault

// 使用场景：提供默认值（处理falsy值）
let count: number = 0;
let displayCount: number = count || 10;  // 10（注意：0是falsy）

// 使用场景：多条件检查
let hasPermission: boolean = true;
let isOwner: boolean = false;
let canEdit: boolean = hasPermission || isOwner;

// 使用场景：配置回退
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

### 逻辑非的类型转换

逻辑非（!）先将操作数转换为布尔值再取反：0、''、null、undefined转为true，其余转为false。

<!-- @[logical_not](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
// 逻辑非将值转换为布尔值后取反
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

// 双重否定：转换为布尔值
console.info(`${!!value1}`);  // true
console.info(`${!!value2}`);  // false
console.info(`${!!value3}`);  // false

// 等价于Boolean()
console.info(`${Boolean(value1)}`);  // true

// 使用场景：条件判断
function processValue(value: string | null): void {
  if (!value) {
    console.info('值为空');
    return;
  }
  console.info(`处理值: ${value}`);
}
```

### 逻辑运算符的嵌套优先级

逻辑与（&&）优先级高于逻辑或（||），复杂表达式建议使用括号明确优先级。

<!-- @[logical_operator_precedence](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
// && 优先级高于 ||
let logOpA: boolean = true;
let logOpB: boolean = false;
let c: boolean = false;

let logOpResult: boolean = logOpA || logOpB && c;  // 等价于: logOpA || (logOpB && c)
console.info(`${logOpResult}`);  // true

// 使用括号明确优先级
let logOpResult2: boolean = (logOpA || logOpB) && c;  // false

// 复杂逻辑表达式
let logOpHasPermission: boolean = true;
let isAuthenticated: boolean = false;
let isAdmin: boolean = true;

// 推荐：使用括号和换行提高可读性
let logOpCanAccess: boolean = 
  isAuthenticated && (
    logOpHasPermission || isAdmin
  );

// 德摩根定律应用
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

## 三元条件运算符

三元条件运算符（condition ? a : b）在单行中完成条件赋值，替代简单的if-else。

### 三元运算符的语法结构

三元运算符根据条件选择两个值中的一个，语法为condition ? value1 : value2。

<!-- @[ts_ternary_operator_basics](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/AdvancedOperators.ts) -->

``` TypeScript
let age: number = 20;
let status: string = age >= 18 ? 'adult' : 'minor';

let score: number = 85;
let result: string = score >= 60 ? 'pass' : 'fail';

// 返回值类型必须一致
let value: number = 10;
let output: string = value > 5 ? 'greater' : 'less';  // 正确
let wrong: string = value > 5 ? 10 : 'less';  // 编译错误

// 函数调用
function getName(): string {
  return 'Alice';
}

function getDefaultName(): string {
  return 'Unknown';
}

let user: string | null = null;
let displayName: string = user !== null ? user : getDefaultName();
```

### 三元运算符的嵌套使用

三元运算符可以嵌套处理多分支选择，但嵌套过深会降低可读性。

<!-- @[nested_ternary](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
let score: number = 85;

// 嵌套三元运算符
let grade: string = 
  score >= 90 ? 'A' :
  score >= 80 ? 'B' :
  score >= 70 ? 'C' :
  score >= 60 ? 'D' : 'F';

console.info(`成绩等级: ${grade}`);  // B

// 更复杂的嵌套
let age: number = 25;
let hasLicense: boolean = true;
let hasInsurance: boolean = false;

let canDrive: string = 
  age < 18 ? 'underage' :
  !hasLicense ? 'no license' :
  !hasInsurance ? 'no insurance' :
  'can drive';

// 反例：多层嵌套（影响可读性）
let status: string = 
  age < 13 ? 'child' :
  age < 20 ? 'teenager' :
  age < 30 ? 'young adult' :
  age < 50 ? 'adult' :
  age < 65 ? 'middle-aged' : 'senior';
```

### 三元运算符与if-else的等价转换

三元运算符`condition ? a : b`可以改写为if-else语句，适用于简单的条件赋值场景。

<!-- @[ternary_vs_if_else](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
// 三元运算符
let elseA: number = 10;
let elseB: number = 20;
let max: number = elseA > elseB ? elseA : elseB;

// 等价的if-else
let max2: number;
if (elseA > elseB) {
  max2 = elseA;
} else {
  max2 = elseB;
}

// 复杂条件
let elseScore: number = 75;
let elseGrade: string = elseScore >= 60 ? 'pass' : 'fail';

// 等价的if-else
let grade2: string;
if (elseScore >= 60) {
  grade2 = 'pass';
} else {
  grade2 = 'fail';
}

// 多分支选择
let elseValue: number = 85;
let category: string = 
  elseValue >= 90 ? 'excellent' :
  elseValue >= 70 ? 'good' :
  elseValue >= 50 ? 'average' : 'poor';

// 等价的if-else if-else
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

### 三元运算符的可读性优化

复杂的三元表达式应使用辅助函数或if-else替代，提高代码可读性。

<!-- @[ternary_best_practices](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
let scoreA: number = 10;
let scoreB: number = 5;
let scoreC: number = 8;
let applicantAge: number = 20;
let hasDrivingLicense: boolean = true;

// 反例：过于复杂的嵌套
let maxScoreTernary: number = scoreA > scoreB
  ? (scoreA > scoreC ? scoreA : scoreC)
  : (scoreB > scoreC ? scoreB : scoreC);

// 推荐：使用if-else提高可读性
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

// 推荐：使用辅助函数
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

// 推荐：格式化三元运算符
let licenseStatus: string =
  applicantAge >= 18 && hasDrivingLicense ? 'eligible' :
  applicantAge >= 18 ? 'no license' :
  'underage';

// 反例：一行过长
let compactLicenseStatus: string = applicantAge >= 18 && hasDrivingLicense
  ? 'eligible' : applicantAge >= 18 ? 'no license' : 'underage';
```

## 展开与剩余运算符

展开运算符（...）将数组或对象拆解为独立元素用于合并与复制，剩余运算符将多个参数收集为数组。

### 数组展开运算符

数组展开运算符（...）将数组元素展开为独立元素，用于复制、合并和传参。

<!-- @[spread_operator_array](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
// 展开数组元素
let spreadArr1: number[] = [1, 2, 3];
let spreadArr2: number[] = [4, 5, 6];

// 合并数组
let merged: number[] = [...spreadArr1, ...spreadArr2];
console.info(`${merged.join(', ')}`);  // 1, 2, 3, 4, 5, 6

// 在任意位置插入
let inserted: number[] = [0, ...spreadArr1, 4];
console.info(`${inserted.join(', ')}`);  // 0, 1, 2, 3, 4

// 复制数组
let spreadCopied: number[] = [...spreadArr1];
console.info(`${spreadCopied.join(', ')}`);  // 1, 2, 3

// 作为函数参数：被展开数组应传给剩余参数
function spreadSum(...values: number[]): number {
  let spreadTotal: number = 0;
  for (let value of values) {
    spreadTotal += value;
  }
  return spreadTotal;
}

let numbers: number[] = [1, 2, 3];
let spreadTotal: number = spreadSum(...numbers);  // 6

// 展开与数组方法结合
let spreadMax: number = Math.max(...spreadArr1);  // 3
let min: number = Math.min(...spreadArr2);  // 4
```

### 对象展开对照与显式复制

TypeScript支持对象展开，例如`{ ...source }`、`{ ...defaults, ...override }`。ArkTS对对象字面量和展开语法更严格，普通业务对象的拷贝与合并优先使用显式构造或赋值。

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

### 剩余参数运算符

剩余参数运算符（...）将多个参数收集为数组，用于处理不定数量的参数。

<!-- @[rest_parameters](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
// 函数参数中的剩余参数
function sumAll(...numbers: number[]): number {
  let total: number = 0;
  for (const num of numbers) {
    total += num;
  }
  return total;
}

console.info(`${sumAll(1, 2, 3, 4, 5)}`);  // 15

// 与固定参数结合
function greet(greeting: string, ...names: string[]): string {
  return `${greeting}, ${names.join(', ')}!`;
}

console.info(`${greet('Hello', 'Alice', 'Bob', 'Charlie')}`);  // Hello, Alice, Bob, Charlie!

// 数组解构中的剩余元素
let arr: number[] = [1, 2, 3, 4, 5];
// ArkTS不支持解构赋值，需要手动提取
let first: number = arr[0] ?? 0;
let rest: number[] = arr.slice(1);
console.info(`${first}`);  // 1
console.info(`${rest.join(', ')}`);   // 2, 3, 4, 5

// 函数参数收集
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

### 剩余属性对照与显式复制

ArkTS不支持对象剩余属性解构，需显式复制每个属性。

<!-- @[object_rest_properties](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
interface RequestUser {
  id: number;
  name: string;
  email: string;
  age: number;
}

// 对象解构中的剩余属性
let user: RequestUser = {
  id: 1,
  name: 'Alice',
  email: 'alice@example.com',
  age: 30
};

// ArkTS不支持解构赋值，需要手动提取
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

// 函数参数提取部分属性
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

### 展开运算符的深拷贝与浅拷贝

展开运算符创建浅拷贝，嵌套对象仍共享引用，深拷贝需手动处理嵌套层级。

<!-- @[shallow_vs_deep_copy](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
// 浅拷贝
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

console.info(`${obj1.a}`);    // 1（基本类型，独立）
console.info(`${obj1.b.c}`);  // 20（引用类型，共享）

// 面向已声明类型实现深拷贝
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
console.info(`${obj3.b.c}`);  // 2（独立，不受影响）
```

## 运算符的重载（模拟实现）

TypeScript和ArkTS均不支持运算符重载，通过命名方法（如add、sub）模拟运算符行为。

### 无原生运算符重载

不支持运算符重载，可通过命名方法模拟运算符行为。

<!-- @[ts_operator_overloading_not_supported](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/AdvancedOperators.ts) -->

``` TypeScript
// 不支持运算符重载
class Vector {
  public x: number = 0;
  public y: number = 0;

  constructor(x: number = 0, y: number = 0) {
    this.x = x;
    this.y = y;
  }

  // 不支持operator+（编译错误：TS不支持运算符重载）
  operator+(other: Vector): Vector {
    return new Vector(this.x + other.x, this.y + other.y);
  }
}
```

### 基于命名方法模拟运算符行为

通过命名方法（如add、sub）模拟运算符行为，在Vector类中实现向量运算。

<!-- @[simulated_operator_overloading](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
class Vector {
  public x: number = 0;
  public y: number = 0;

  constructor(x: number = 0, y: number = 0) {
    this.x = x;
    this.y = y;
  }

  // 模拟加法运算符
  add(other: Vector): Vector {
    return new Vector(this.x + other.x, this.y + other.y);
  }

  // 模拟减法运算符
  subtract(other: Vector): Vector {
    return new Vector(this.x - other.x, this.y - other.y);
  }

  // 模拟乘法运算符（标量乘法）
  multiply(scalar: number): Vector {
    return new Vector(this.x * scalar, this.y * scalar);
  }

  // 模拟点积运算符
  dot(other: Vector): number {
    return this.x * other.x + this.y * other.y;
  }

  // 模拟相等运算符
  equals(other: Vector): boolean {
    return this.x === other.x && this.y === other.y;
  }

  // 模拟比较运算符
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

// 使用模拟运算符
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

### 模拟加法/减法重载的示例

通过命名方法（如add、sub）在Complex类中模拟复数的加减运算。

<!-- @[complex_number_operators](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
class Complex {
  public real: number = 0;
  public imag: number = 0;

  constructor(real: number = 0, imag: number = 0) {
    this.real = real;
    this.imag = imag;
  }

  // 模拟加法
  add(other: Complex): Complex {
    return new Complex(
      this.real + other.real,
      this.imag + other.imag
    );
  }

  // 模拟减法
  subtract(other: Complex): Complex {
    return new Complex(
      this.real - other.real,
      this.imag - other.imag
    );
  }

  // 模拟乘法
  multiply(other: Complex): Complex {
    return new Complex(
      this.real * other.real - this.imag * other.imag,
      this.real * other.imag + this.imag * other.real
    );
  }

  // 模拟除法
  divide(other: Complex): Complex {
    let denominator: number = other.real * other.real + other.imag * other.imag;
    return new Complex(
      (this.real * other.real + this.imag * other.imag) / denominator,
      (this.imag * other.real - this.real * other.imag) / denominator
    );
  }

  // 模拟一元负号
  negate(): Complex {
    return new Complex(-this.real, -this.imag);
  }

  // 模拟相等
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

### 运算符重载的使用场景限制

运算符重载模拟适用于数学计算类，复杂业务逻辑建议使用明确的方法名。

<!-- @[operator_overloading_use_cases](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
// 场景1：数学计算类（推荐）
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
    // 矩阵乘法实现
    let result: Matrix = new Matrix(this.rows, this.cols);
    // ... 实现细节
    return result;
  }
}

// 场景2：自定义类型比较（推荐）
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

// 场景3：链式调用（推荐）
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

// 反例：复杂业务逻辑场景
// 对于复杂业务逻辑，建议使用明确的方法名而不是模拟运算符
```

## 运算符优先级表

运算符优先级决定表达式中运算的执行顺序。ArkTS中常见运算符优先级从高到低为：括号`()` → 成员访问`.`/`[]` → 一元`!`/`-`/`++`/`--` → 算术`*`/`/`/`%` → 算术`+`/`-` → 位移`<<`/`>>`/`>>>` → 比较`>`/`<`/`>=`/`<=` → 相等`===`/`!==` → 按位`&` → 按位`^` → 按位`|` → 逻辑`&&` → 逻辑`||` → 空值合并`??` → 三元`?:` → 赋值`=`/`+=`等。复杂表达式建议使用括号明确优先级，避免依赖默认规则导致歧义。

<!-- @[parentheses_for_precedence](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
let precA: number = 5;
let precB: number = 3;
let precC: number = 10;
let precD: number = 2;
let precInput: string | null = 'hello';
// 使用括号明确优先级
let precResult: number = (precA + precB) * (precC - precD);
let valid: boolean = (precA > precB) && (precC < precD);
let precValue: string = (precInput ?? 'default') + ' suffix';
```

## ArkTS限制

ArkTS限制解构赋值和部分动态特性，需使用单独赋值或索引访问替代。

### 不支持解构赋值

ArkTS不支持解构赋值（如`let {a, b} = obj`），需逐个属性显式赋值。

<!-- @[ts_destructuring_not_supported](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/AdvancedOperators.ts) -->

``` TypeScript
interface Point {
  pointX: number;
  pointY: number;
}

let point: Point = { pointX: 10, pointY: 20 };

// 不支持
let [destA, destB] = [1, 2];
let {pointX, pointY} = point;

// 正确：单独赋值
let arr: number[] = [1, 2];
let destAVal: number = arr[0];
let destBVal: number = arr[1];

let destX: number = point.pointX;
let destY: number = point.pointY;
```

### 不建议使用松散相等

ArkTS支持松散相等（`==`和`!=`），但不建议使用，因为会进行隐式类型转换，可能导致难以发现的bug。推荐使用严格相等（`===`和`!==`）。

<!-- @[strict_equality_best_practices](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
let strictValue: number | null = 5;
if (strictValue == 5) { }
if (strictValue != null) { }

let equalityValue: number | null = 5;

// 推荐使用严格相等
if (equalityValue === 5) { }
if (equalityValue !== null) { }
```

### 类型必须匹配

ArkTS要求运算符两侧操作数类型必须一致或在编译期可确定地兼容，否则编译报错。例如`5 > '5'`因`number`与`string`类型不匹配而报错，`true + 1`因`boolean`与`number`不兼容而报错。此限制避免了JavaScript中隐式类型转换导致的运行时意外行为。

**错误示例**

<!-- @[ts_type_safe_operations](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/AdvancedOperators.ts) -->

``` TypeScript
let num: number = 5;
num = 'text';  // 编译错误

// 运算符操作数类型必须兼容
let typeSafeA: number = 5;
let typeSafeB: string = '5';
let typeSafeResult: boolean = typeSafeA > typeSafeB;  // 编译错误
```

## as const断言

`as const`断言将对象属性推断为字面量类型，而非宽泛类型。确保属性值不可变且类型精确。

**TypeScript对照**

<!-- @[ts_as_const](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/AdvancedOperators.ts) -->

``` TypeScript
// TypeScript对照写法，ArkTS中用显式类型标注替代
const tsConfig = {
  url: 'EXAMPLE_API_URL',
  method: 'GET'
} as const;
// tsConfig.method 类型为 'GET'（字面量）

const tsArgs = [8, 5] as const;
// tsArgs 类型为 readonly [8, 5]（元组）
```

ArkTS中使用显式类型标注替代`as const`。

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

`acConfig`的`method`属性为`readonly`，对其赋值会触发编译错误。

**TypeScript对照**

<!-- @[ts_as_const_readonly_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/AdvancedOperators.ts) -->

``` TypeScript
// TypeScript对照写法，演示readonly赋值的编译错误
interface TsReadonlyConfig {
  readonly method: string;
}

let tsReadonlyConfig: TsReadonlyConfig = {
  method: 'GET'
};

tsReadonlyConfig.method = 'POST';  // 编译错误：Cannot assign to 'method' because it is a read-only property
```

使用枚举`AcHttpMethod`可提供类型安全的字符串字面量集合。

<!-- @[as_const_enum_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AdvancedOperators.ets) -->

``` TypeScript
// 使用枚举替代字符串字面量
enum AcHttpMethod {
  GET = 'GET',
  POST = 'POST'
}

let acMethod: AcHttpMethod = AcHttpMethod.GET;
console.info(`${acMethod}`);  // GET
```

## satisfies操作符

`satisfies`操作符检查值是否满足指定类型，但不收窄类型。与`as`不同，`satisfies`做真实类型检查而非断言。

**TypeScript对照**

<!-- @[ts_satisfies](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/AdvancedOperators.ts) -->

``` TypeScript
// TypeScript对照写法（TS 4.9+），ArkTS中用显式类型替代
type StColors = 'red' | 'green' | 'blue';

const stRgb = {
  red: '#FF0000',
  green: '#00FF00',
  blue: '#0000FF'
} satisfies Record<StColors, string>;
```

ArkTS中使用显式类型标注和接口替代`satisfies`。

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

`as`与`satisfies`的区别：`as`是断言不检查，`satisfies`做真实类型检查但不收窄类型。ArkTS中使用显式类型标注实现同等安全性。
