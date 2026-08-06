# 基本操作符
<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

ArkTS提供丰富的操作符用于数据运算、逻辑判断和赋值操作。

## 赋值运算符

赋值运算符（=）将右侧的值赋给左侧的变量，支持链式赋值和复合赋值（+=、-=等）。

### 简单赋值 (=)

使用`=`将右侧的值赋给左侧的变量。赋值是引用语义——对对象类型的变量赋值后，新旧变量指向同一对象，修改其中一个会影响另一个。

<!-- @[basic_variable_assignment](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let value: number = 10;
let name: string = 'Alice';
let active: boolean = true;

// 重新赋值
value = 20;
name = 'Bob';
```

### 赋值与元组

ArkTS不支持元组解构赋值（如`let [a, b] = [1, 2]`），需逐个变量赋值。

<!-- @[ts_no_destructuring_assignment](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Operators.ts) -->

``` TypeScript
// 不支持解构赋值
let [a, b] = [1, 2];

// 正确做法：单独赋值
let arr: number[] = [1, 2];
let aVal: number = arr[0];
let bVal: number = arr[1];
```

### 赋值表达式的返回值

赋值表达式本身返回被赋的值，语法上支持链式赋值`a = b = 10`，但**不建议使用**，建议分开赋值以提高可读性。

<!-- @[chain_vs_separate_assignment](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let a: number;
let b: number;

// 反例：链式赋值
a = b = 10;

// 推荐：分开赋值
a = 10;
b = 10;
```

### 对象赋值

将对象赋值给变量传递的是引用而非副本——新旧变量指向同一对象，修改其中一个的属性会影响另一个。如需独立副本，须手动实现深拷贝。

<!-- @[object_property_and_reference_assignment](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
class Point {
  public x: number = 0;
  public y: number = 0;
}

let point: Point = new Point();
point.x = 10;       // 属性赋值
point.y = 20;

let another: Point = point;  // 引用赋值
another.x = 30;    // point.x也变为30
```

## 算术运算符

算术运算符包括加（+）、减（-）、乘（*）、除（/）、取余（%）以及递增递减（++/--）。

### 加法运算符 (+)

加法运算符执行数值相加或字符串拼接，返回相加或拼接结果。

<!-- @[addition_and_string_concatenation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let addA: number = 10;
let addB: number = 5;

let sum: number = addA + addB;    // 15

// 字符串拼接
let greeting: string = 'Hello' + ' World';
let message: string = 'Count: ' + 10;
```

### 减法运算符 (-)

减法运算符（`-`）计算两个数值操作数的差值。操作数必须为`number`类型，ArkTS不允许`number`与`string`等跨类型运算。

<!-- @[subtraction_and_negative_number](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let numberA: number = 10;
let numberB: number = 5;

let diff: number = numberA - numberB;   // 5
let negative: number = -10; // 负数表示
```

### 乘法运算符 (*)

乘法运算符（`*`）计算两个数值操作数的乘积。操作数必须为`number`类型，ArkTS不支持字符串重复（如Python的`'ab' * 3`），字符串重复需使用`repeat()`方法。

<!-- @[multiplication_operator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let mulA: number = 10;
let mulB: number = 5;

let product: number = mulA * mulB;  // 50

// 面积计算
let width: number = 5;
let height: number = 10;
let area: number = width * height;  // 50
```

### 除法运算符 (/)

除法运算符（/）计算两数商值，结果始终为浮点数。

<!-- @[division_operator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let divA: number = 10;
let divB: number = 4;

let quotient: number = divA / divB;  // 2.5

// 整数除法
let intDivision: number = Math.floor(10 / 4);  // 2

// 除以零
let zeroDiv: number = 10 / 0;   // Infinity
let negZeroDiv: number = -10 / 0;  // -Infinity
let zeroByZero: number = 0 / 0;  // NaN
```

### 取余运算符 (%)

取余运算符返回除法的余数，用于循环、周期计算。

<!-- @[modulo_operator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let modA: number = 10;
let modB: number = 3;

let remainder: number = modA % modB;  // 1

// 判断奇偶
let isEven: boolean = (modA % 2) === 0;
let isOdd: boolean = (modA % 2) !== 0;
```

### 一元负号运算符 (-)

一元负号（-）将数值取反，正变负、负变正。

<!-- @[unary_negation_operator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let negA: number = 5;
let negNegative: number = -negA;  // -5

let negB: number = -10;
let positive: number = -negB;  // 10
```

### 一元正号运算符 (+)

一元正号运算符将值转换为数值类型，用于类型转换。

<!-- @[unary_plus_operator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let plusA: number = 5;
let plus: number = +plusA;  // 5

// 用于显式转换（推荐使用Number.parseInt）
let strNum: number = Number.parseInt('42', 10);
```

### 指数运算符 (**)

指数运算符计算幂次，返回底数的指数次幂。

<!-- @[exponentiation_operator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let base: number = 2;
let exponent: number = 3;

let power: number = base ** exponent;  // 8 (2^3)

let square: number = 5 ** 2;   // 25
let cube: number = 3 ** 3;     // 27
```

## 复合赋值运算符

复合赋值运算符合并运算和赋值，简化代码编写。

<!-- @[compound_assignment_operators](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
// 加法赋值
let total: number = 100;
total += 50;
console.info(`${total}`);  // 150

// 字符串拼接赋值
let compoundMessage: string = 'Hello';
compoundMessage += ' World';
console.info(`${compoundMessage}`);  // Hello World

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
let compoundValue: number = 17;
compoundValue %= 5;
console.info(`${compoundValue}`);  // 2

// 指数赋值
let compoundBase: number = 2;
compoundBase **= 4;
console.info(`${compoundBase}`);  // 16
```

## 比较运算符

比较运算符判断值的关系，返回布尔结果。

### 等于运算符 (===)

严格相等（===）在值和类型都相同时返回true。

<!-- @[strict_equality_operator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
// 数值比较
let eqA: number = 5;
let eqB: number = 5;
console.info(`${eqA === eqB}`);     // true

// 不同值
let eqNum1: number = 5;
let eqNum2: number = 10;
console.info(`${eqNum1 === eqNum2}`); // false

// 对象比较引用
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
console.info(`${p1 === p2}`);  // false（不同对象）
```

### 不等于运算符 (!==)

严格不等（!==）在值或类型不同时返回true。

<!-- @[strict_inequality_operator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let neA: number = 5;
let neB: number = 3;
console.info(`${neA !== neB}`);     // true

let neNum1: number = 5;
let neNum2: number = 10;
console.info(`${neNum1 !== neNum2}`); // true
```

### 大于运算符 (>)

大于运算符（>）在左侧值大于右侧时返回true。

<!-- @[greater_than_operator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let gtA: number = 10;
let gtB: number = 5;

console.info(`${gtA > gtB}`);   // true
console.info(`${gtB > gtA}`);   // false
console.info(`${gtA > gtA}`);   // false

// 字符串比较Unicode码点
console.info(`${'gtB' > 'gtA'}`);     // true
console.info(`${'abc' > 'abb'}`); // true
```

### 小于运算符 (<)

小于运算符（<）在左侧值小于右侧时返回true。

<!-- @[less_than_operator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let ltA: number = 10;
let ltB: number = 5;

console.info(`${ltA < ltB}`);   // false
console.info(`${ltB < ltA}`);   // true
console.info(`${ltA < ltA}`);   // false
```

### 大于等于运算符 (>=)

大于等于（>=）在左侧值大于或等于右侧时返回true。

<!-- @[greater_than_or_equal_operator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let gteA: number = 10;
let gteB: number = 5;
let c: number = 10;

console.info(`${gteA >= gteB}`);  // true
console.info(`${gteA >= c}`);  // true
console.info(`${gteB >= gteA}`);  // false
```

### 小于等于运算符 (<=)

小于等于（<=）在左侧值小于或等于右侧时返回true。

<!-- @[less_than_or_equal_operator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let lteA: number = 10;
let lteB: number = 5;
let lteC: number = 10;

console.info(`${lteA <= lteB}`);  // false
console.info(`${lteA <= lteC}`);  // true
console.info(`${lteB <= lteA}`);  // true
```

### 比较元组

数组和元组没有内置的逐元素相等比较，`===`比较的是引用而非内容。手动比较时先判断长度相同，再逐索引比较每个元素。

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

## 三元条件运算符

三元条件运算符根据条件表达式的布尔值，从两个值中选择一个作为结果。它是if-else的简洁写法，适用于简单的条件赋值场景。

``` TypeScript
条件表达式 ? 真值 : 假值
```

<!-- @[ternary_conditional_operator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let age: number = 20;
let status: string = age >= 18 ? 'adult' : 'minor';

let score: number = 85;
let result: string = score >= 60 ? 'pass' : 'fail';

// 嵌套三元运算符
let grade: string = 
  score >= 90 ? 'A' :
  score >= 80 ? 'B' :
  score >= 70 ? 'C' :
  score >= 60 ? 'D' : 'F';

// 函数返回
function getStatus(code: number): string {
  return code === 200 ? 'OK' : 'Error';
}

// 条件赋值
let isAdmin: boolean = true;
let role: string = isAdmin ? 'admin' : 'user';
```

## 空值合并运算符

空值合并运算符 ?? 提供默认值，处理null和undefined。

<!-- @[nullish_coalescing_operator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let coalesceValue: string | null = null;
let coalesceResult: string = coalesceValue ?? 'default';
console.info(`${coalesceResult}`);  // "default"

let value2: string = 'hello';
let result2: string = value2 ?? 'default';  // "hello"

// 与 || 的区别
let count: number = 0;
let text: string = '';
let flag: boolean = false;

// || 替换falsy值
let withOr1: number = count || 10;     // 10（0是falsy）
let withOr2: string = text || 'default'; // 'default'

// ?? 只替换null/undefined
let withNullCoalesce1: number = count ?? 10;      // 0（保留0）
let withNullCoalesce2: string = text ?? 'default'; // ''（保留空字符串）

// 链式空值合并
let primary: string | null = null;
let secondary: string | null = null;
let fallback: string = 'default';

let result3: string = primary ?? secondary ?? fallback;
console.info(`${result3}`);  // "default"
```

## 区间判断模拟

区间判断检查值是否在范围内，用于范围验证。

### 闭区间判断

闭区间判断使用`>=`和`<=`检查值是否在指定范围内，包含两个边界值。

<!-- @[closed_range_check](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
function inClosedRange(checkValue: number, min: number, max: number): boolean {
  return checkValue >= min && checkValue <= max;
}

let checkValue: number = 50;
let inRange: boolean = inClosedRange(checkValue, 10, 100);  // true
```

### 半开区间判断

半开区间判断检查值是否在范围内，包含起始不含结束。

<!-- @[half_open_range_check](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
function inHalfOpenRange(checkValue2: number, min: number, max: number): boolean {
  return checkValue2 >= min && checkValue2 < max;
}

let checkValue2: number = 100;
let checkInRange: boolean = inHalfOpenRange(checkValue2, 10, 100);  // false
```

### 单侧区间判断

单侧区间判断检查值是否大于或小于某个边界。

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

## 逻辑运算符

逻辑运算符包括非（!）、与（&&）、或（||），对布尔值做逻辑运算并支持短路。

### 逻辑非运算符 (!)

逻辑非（!）将true变false、false变true。

<!-- @[logical_not_operator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let isA: boolean = true;
let isB: boolean = false;

console.info(`${!isA}`);  // false
console.info(`${!isB}`);  // true

// 双重否定转换为布尔值
let notValue: number = 5;
console.info(`${!!notValue}`);  // true（等同于Boolean(notValue))
```

### 逻辑与运算符 (&&)

逻辑与（&&）两侧均为true才返回true，左侧为false时短路跳过右侧。

<!-- @[logical_and_operator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let andA: boolean = true;
let andB: boolean = true;
let andC: boolean = false;

console.info(`${andA && andB}`);  // true
console.info(`${andA && andC}`);  // false

// 真值表
// true && true   → true
// true && false  → false
// false && true  → false
// false && false → false

// 条件检查
let andAge: number = 25;
let hasLicense: boolean = true;
let hasInsurance: boolean = true;

let canDrive: boolean = andAge >= 18 && hasLicense && hasInsurance;
```

### 逻辑或运算符 (||)

逻辑或（||）任一侧为true即返回true，左侧为true时短路跳过右侧。

<!-- @[logical_or_operator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let orA: boolean = true;
let orB: boolean = false;
let orC: boolean = false;

console.info(`${orA || orB}`);  // true
console.info(`${orB || orC}`);  // false

// 真值表
// true || true   → true
// true || false  → true
// false || true  → true
// false || false → false

// 任一条件满足
let orRole: string = 'admin';
let hasPermission: boolean = true;

let canAccess: boolean = orRole === 'admin' || hasPermission;
```

### 逻辑运算符的组合使用

逻辑运算符组合实现复杂条件，注意优先级和短路求值。

<!-- @[boolean_logic_combination](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let boolLogAge: number = 25;
let boolLogHasLicense: boolean = true;
let isGuest: boolean = false;

// 必须满足所有条件
let boolLogCanDrive: boolean = boolLogAge >= 18 && boolLogHasLicense;

// 任一条件满足
let hasAccess: boolean = isGuest || boolLogHasLicense;

// 复合条件
let canRentCar: boolean = boolLogAge >= 21 && (boolLogHasLicense || isGuest);

// 排除条件
let userStatus: string = 'active';
let isInactive: boolean = !(userStatus === 'active');

// 德摩根定律应用
let invalid: boolean = !(boolLogHasLicense && boolLogAge >= 18);
// 等价于
let invalid2: boolean = !boolLogHasLicense || boolLogAge < 18;
```

### 短路求值

逻辑与（&&）和逻辑或（||）在左侧已能决定结果时跳过右侧执行。

<!-- @[short_circuit_evaluation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
// && 短路：左边为false，右边不执行
function expensiveCheck(): boolean {
  console.info('执行复杂检查');
  return true;
}

let enabled: boolean = false;
let circuitResult: boolean = enabled && expensiveCheck();  // 不执行expensiveCheck

// || 短路：左边为true，右边不执行
function fallbackValue(): string {
  console.info('使用默认值');
  return 'default';
}

let circuitPrimary: string | null = 'circuitPrimary';
let circuitValue: string = circuitPrimary !== null ? circuitPrimary : fallbackValue();  // 不执行fallbackValue

// ?? 短路：左边不为null/undefined，右边不执行
function expensiveDefault(): string {
  console.info('执行昂贵默认值计算');
  return 'default';
}

let provided: string = 'text';
let circuitResult2: string = provided ?? expensiveDefault();  // 不执行expensiveDefault
```

## 运算符优先级

用括号显式标注运算优先级，避免依赖默认规则导致歧义。

<!-- @[parentheses_for_precedence](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

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

## 递增递减运算符

递增（++）和递减（--）对数值加1或减1，前置先变后用、后置先用后变。

<!-- @[increment_decrement_operators](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let decrCount: number = 5;

// 前置递增：先增加，再使用
let preInc: number = ++decrCount;  // decrCount=6, preInc=6

// 后置递增：先使用，再增加
let postInc: number = decrCount++; // decrCount=7, postInc=6

// 前置递减
let preDec: number = --decrCount;  // decrCount=6, preDec=6

// 后置递减
let postDec: number = decrCount--; // decrCount=5, postDec=6
```

## 可选链运算符

可选链运算符（?.）在属性可能为null/undefined时安全访问，避免运行时错误。

<!-- @[optional_chaining_operator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
class User {
  public profile: Profile | null = null;
}

class Profile {
  public nickname: string = '';
}

let user: User | null = new User();

// 安全访问属性链
let nickname: string | undefined = user?.profile?.nickname;
console.info(`${nickname}`);  // undefined

// 访问方法
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

// 访问数组元素
function getArr(): number[] | null {
  return null;
}
let arr: number[] | null = getArr();
let first: number | undefined = arr !== null ? arr[0] : undefined;

// 结合空值合并
let display: string = user?.profile?.nickname ?? 'Unknown';
```

## ArkTS限制

ArkTS支持松散相等（`==`），但不建议使用，推荐使用严格相等（`===`）避免隐式类型转换。

### 不建议使用松散相等

ArkTS支持`==`和`!=`松散相等，但不建议使用，推荐使用`===`和`!==`严格相等，避免隐式类型转换导致的潜在问题。

<!-- @[loose_equality_not_recommended](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let inputValue: string | null = null;
let itemCount: number = 0;
if (inputValue == null) { }
if (itemCount == 0) { }
```

推荐使用严格相等：

<!-- @[strict_equality_preferred](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Operators.ets) -->

``` TypeScript
let eqValue: string | null = null;
let eqCount: number = 0;
// 推荐：使用严格相等
if (eqValue === null) { }
if (eqCount === 0) { }
```

### 不支持解构赋值

ArkTS不支持解构赋值，需通过索引逐个取出元素并单独赋值。

<!-- @[ts_no_destructuring_supported](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Operators.ts) -->

``` TypeScript
// 不支持
let point = { x: 1, y: 2 };
let arr: number[] = [1, 2];
let [a1, b1] = [1, 2];
let {x, y} = point;

// 正确：单独赋值
let a2: number = arr[0] ?? 0;
let b2: number = arr[1] ?? 0;
```

### 类型必须匹配

ArkTS要求运算符两侧操作数类型一致或在编译期可确定地兼容，否则编译报错。例如`5 > '5'`因`number`与`string`类型不匹配而报错。此限制避免了JavaScript中隐式类型转换导致的运行时意外行为。

**错误示例**

<!-- @[ts_static_type_checking](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Operators.ts) -->

``` TypeScript
let num: number = 5;
num = 'text';  // 编译错误
```
