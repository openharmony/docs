# 控制语句
<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

控制语句用于控制程序的执行流程。ArkTS提供分支语句、循环语句和跳转语句，实现复杂的逻辑控制。

## 分支语句

分支语句根据条件选择不同的执行路径。

### if语句

if语句在条件为true时执行对应代码块，可搭配else if和else处理多分支场景。

<!-- @[basic_if_statement](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
let score: number = 85;

if (score >= 60) {
  console.info('通过');
}

let age: number = 25;
if (age >= 18) {
  console.info('成年人');
}

let enabled: boolean = true;
if (enabled) {
  startService();
}

function startService(): void {
  console.info('服务已启动');
}
```

当需要处理多个互斥条件时，可以使用`else if`串联多个判断分支：

<!-- @[if_else_if_chain](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
let chainScore: number = 85;

if (chainScore >= 90) {
  console.info('优秀');
} else if (chainScore >= 80) {
  console.info('良好');
} else if (chainScore >= 60) {
  console.info('及格');
} else {
  console.info('不及格');
}

let chainAge: number = 25;

if (chainAge < 13) {
  console.info('儿童');
} else if (chainAge < 18) {
  console.info('青少年');
} else if (chainAge < 60) {
  console.info('成年人');
} else {
  console.info('老年人');
}

// 多条件组合
let role: string = 'admin';
let hasPermission: boolean = true;

if (role === 'admin') {
  console.info('管理员权限');
} else if (role === 'user' && hasPermission) {
  console.info('用户权限');
} else {
  console.info('无权限');
}
```

对于只需满足条件即执行、无需处理其他分支的简单场景，可省略`else`部分：

<!-- @[simple_condition_check](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
let value: number = 10;

// 只检查条件，无需else
if (value > 0) {
  console.info('正数');
}

// else分支为空可省略
if (value < 0) {
  console.info('负数');
} else {
  // 空分支可以省略
}

// 简洁写法
if (value !== 0) {
  console.info('非零');
}
```

### switch语句

switch语句根据表达式的值匹配多个case分支，适合离散值的多分支选择，比多个else if更清晰。

``` TypeScript
switch (expression) {
  case value1:
    // 执行代码
    break;
  case value2:
    // 执行代码
    break;
  default:
    // 默认执行代码
    break;
}
```

下面通过日期和状态匹配的具体示例展示`switch`的基本用法：

<!-- @[switch_basic_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
let day: number = 3;

switch (day) {
  case 1:
    console.info('星期一');
    break;
  case 2:
    console.info('星期二');
    break;
  case 3:
    console.info('星期三');
    break;
  case 4:
    console.info('星期四');
    break;
  case 5:
    console.info('星期五');
    break;
  case 6:
    console.info('星期六');
    break;
  case 7:
    console.info('星期日');
    break;
  default:
    console.info('无效日期');
}

let status: string = 'active';

switch (status) {
  case 'active':
    console.info('激活状态');
    break;
  case 'inactive':
    console.info('未激活状态');
    break;
  case 'pending':
    console.info('待处理状态');
    break;
  default:
    console.info('未知状态');
}
```

多个`case`标签可以共享同一段执行逻辑，实现值的分组匹配：

<!-- @[switch_case_fallthrough](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
let fallValue: number = 5;

// TypeScript不支持：case 1, 2, 3:
// 需要分开写

switch (fallValue) {
  case 1:
  case 2:
  case 3:
    console.info('小数值');
    break;
  case 4:
  case 5:
  case 6:
    console.info('中等数值');
    break;
  default:
    console.info('大数值');
}

let color: string = 'red';

switch (color) {
  case 'red':
  case 'yellow':
  case 'orange':
    console.info('暖色调');
    break;
  case 'blue':
  case 'green':
  case 'purple':
    console.info('冷色调');
    break;
  default:
    console.info('其他颜色');
}
```

对于范围判断，`switch`和`if...else if`各有适用场景，以下示例对比两种写法：

<!-- @[switch_vs_if_range](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
let rangeScore: number = 85;

// 使用if实现范围匹配
if (rangeScore >= 90 && rangeScore <= 100) {
  console.info('A级');
} else if (rangeScore >= 80 && rangeScore < 90) {
  console.info('B级');
} else if (rangeScore >= 70 && rangeScore < 80) {
  console.info('C级');
} else if (rangeScore >= 60 && rangeScore < 70) {
  console.info('D级');
} else {
  console.info('F级');
}

// 使用switch映射
let grade: number = Math.floor(rangeScore / 10);

switch (grade) {
  case 10:
  case 9:
    console.info('A级');
    break;
  case 8:
    console.info('B级');
    break;
  case 7:
    console.info('C级');
    break;
  case 6:
    console.info('D级');
    break;
  default:
    console.info('F级');
}
```

switch也可结合`typeof`或判别字段处理联合类型，在`case`分支内安全使用收窄后的类型。

<!-- @[switch_typeof_matching](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
let stmValue: number | string | boolean = 'text';

switch (typeof stmValue) {
  case 'number':
    console.info(`数值: ${stmValue}`);
    break;
  case 'string':
    console.info(`字符串: ${stmValue}`);
    break;
  case 'boolean':
    console.info(`布尔值: ${stmValue}`);
    break;
  default:
    console.info('未知类型');
}
```

使用枚举作为判别字段，配合统一接口，可在switch中按枚举值分支处理。

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
    console.info(`圆形面积: ${Math.PI * semShape.radius * semShape.radius}`);
    break;
  case ShapeKind.Rectangle:
    console.info(`矩形面积: ${semShape.width * semShape.height}`);
    break;
  case ShapeKind.Triangle:
    console.info(`三角形面积: ${0.5 * semShape.base * semShape.height}`);
    break;
}
```

`switch`的`default`分支用于捕获所有未匹配的情况，适合处理未知命令等场景：

<!-- @[switch_default_handling](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
let command: string = 'unknown';

switch (command) {
  case 'start':
    console.info('启动');
    break;
  case 'stop':
    console.info('停止');
    break;
  case 'restart':
    console.info('重启');
    break;
  default:
    console.info('未知命令');
    handleUnknown(command);
}

function handleUnknown(cmd: string): void {
  console.info(`处理未知命令: ${cmd}`);
}
```

`break`语句控制`switch`是否继续向下穿透，省略`break`会触发贯穿执行：

<!-- @[switch_break_fallthrough](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
let fallValue2: number = 1;

switch (fallValue2) {
  case 1:
    console.info('匹配 1');
    break;  // 必须有break，否则继续执行下一个case
  case 2:
    console.info('匹配 2');
    break;
  default:
    console.info('默认');
}

// 没有break会继续执行
switch (fallValue2) {
  case 1:
    console.info('一');
    // 没有break，继续执行case 2
  case 2:
    console.info('二');
    break;
  default:
    console.info('默认');
}
// 输出：一、二
```

## 循环语句

循环语句在条件满足时重复执行代码块，ArkTS提供for、for...of、while、do...while等多种循环形式。

### for...of循环

for...of遍历可迭代对象的元素，语法简洁、通用性强、类型安全，且不会遍历原型链属性。

<!-- @[for_of_iteration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
// 遍历数组
let numbers: number[] = [1, 2, 3, 4, 5];
for (let num of numbers) {
  console.info(`${num}`);
}

// 遍历字符串
let text: string = 'Hello';
for (let char of text) {
  console.info(`${char}`);
}

// 遍历Set
let set: Set<number> = new Set<number>();
set.add(1);
set.add(2);
set.add(3);
for (let value of set) {
  console.info(`${value}`);
}

// 遍历Map
let map: Map<string, number> = new Map<string, number>();
map.set('a', 1);
map.set('b', 2);
map.set('c', 3);

for (let key of map.keys()) {
  let mapValue: number | undefined = map.get(key);
  if (mapValue !== undefined) {
    console.info(`键: ${key}, 值: ${mapValue}`);
  }
}

// 遍历Map的值
for (let value of map.values()) {
  console.info(`${value}`);
}

// 遍历Map的键
for (let key of map.keys()) {
  console.info(`${key}`);
}
```

遍历`Map`的键值对时，ArkTS不支持解构语法，需通过索引单独提取`entry`中的键和值：

<!-- @[for_of_key_value_pairs](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
// TypeScript支持：for (let [key, value] of pairsMap)
// ArkTS需要单独提取

let pairsMap: Map<string, number> = new Map([
  ['a', 1],
  ['b', 2]
]);

for (let entry of pairsMap) {
  let key: string = entry[0];
  let value: number = entry[1];
  console.info(`${key}: ${value}`);
}

// 数组遍历（不需要解构）
let pairs: number[][] = [[1, 2], [3, 4], [5, 6]];
for (let pair of pairs) {
  let first: number = pair[0];
  let second: number = pair[1];
  console.info(`${first}, ${second}`);
}
```

### for...in循环

`for...in`遍历对象的**属性键名**（包括继承的可枚举属性），与`for...of`遍历**值**不同。`for...in`的遍历顺序不保证固定，且遍历数组时返回的是字符串索引（如`"0"`而非`0`），容易导致类型和逻辑错误。ArkTS不支持`for...in`（`arkts-no-for-in`），详见[从TypeScript到ArkTS的适配规则](typescript-to-arkts-migration-guide.md#不支持for--in)，遍历数组应使用`for...of`或`forEach`，遍历对象键名应使用`Object.keys()`。

**TypeScript对照**

<!-- @[ts_for_in_loop](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Control.ts) -->

``` TypeScript
// TypeScript对照写法（ArkTS不支持for...in）
// for...in遍历对象返回属性键名
let finObj: Record<string, number> = { 'a': 1, 'b': 2, 'c': 3 };
for (let key in finObj) {
  console.info(`${key}: ${finObj[key]}`); // a: 1, b: 2, c: 3
}

// for...in遍历数组返回字符串索引（"0"而非0）
let finArr: number[] = [10, 20, 30];
for (let index in finArr) {
  console.info(`${index}`); // "0", "1", "2"（字符串索引，非数值）
}
```

> **说明：**
> 
> `for...in`返回的是键名（字符串），`for...of`返回的是值。遍历数组应使用`for...of`或`forEach`，遍历对象键名应使用`Object.keys()`。

### for循环（传统计数式）

传统for循环使用计数器控制循环，由初始化、条件判断和迭代三部分组成。

执行流程为：先执行初始化表达式（仅一次），再判断条件表达式（为true则继续、为false则退出），然后执行循环体，执行迭代表达式后回到条件判断循环。

<!-- @[traditional_for_loop](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
// 基本结构
for (let i: number = 0; i < 5; i++) {
  console.info(`${i}`);
}

// 初始化：let i = 0
// 条件：i < 5
// 增量：i++

// 倒序循环
for (let i: number = 5; i >= 0; i--) {
  console.info(`${i}`);
}

// 步长为2
for (let i: number = 0; i < 10; i += 2) {
  console.info(`${i}`);
}

// 遍历数组索引
let arr: number[] = [10, 20, 30, 40, 50];
for (let i: number = 0; i < arr.length; i++) {
  console.info(`索引 ${i}: ${arr[i] ?? 0}`);
}

// 多变量循环
for (let i: number = 0, j = 10; i < j; i++, j--) {
  console.info(`i=${i}, j=${j}`);
}
```

借助计数器变量，`for`循环还可以实现指定范围的遍历：

<!-- @[iterate_range_numbers](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
// 遍历指定范围
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

// 遍历范围内的奇数
for (let i: number = 1; i <= 20; i += 2) {
  console.info(`${i}`);
}

// 遍历范围内的偶数
for (let i: number = 2; i <= 20; i += 2) {
  console.info(`${i}`);
}
```

### while循环

while循环先判断条件，再执行循环体，是基于条件控制的循环语句。

``` TypeScript
while (condition) {
  // 循环体代码
  // 注意：需要在循环体内更新条件变量
}
```

`while`适合循环次数在编译时无法确定、基于特定条件（如队列非空）、等待条件满足（如轮询）或需动态调整循环条件的场景。

<!-- @[while_loop_basic](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
// 基本结构
let count: number = 0;
while (count < 5) {
  console.info(`${count.toString()}`);
  count++;
}

// 条件为false时跳过循环体
let loopValue: number = 10;
while (loopValue < 5) {
  console.info(`${loopValue.toString()}`);  // 不执行
  loopValue++;
}

// 处理数据直到条件满足
let data: string | null = 'data';
while (data !== null) {
  console.info(`${data}`);
  data = getNextData();
}

function getNextData(): string | null {
  // 返回数据或null
  return null;
}

// 累加直到满足条件
let sum: number = 0;
let i: number = 1;
while (sum < 100) {
  sum += i;
  i++;
}
console.info(`累加到 ${sum}`);
```

### do...while循环

do...while循环先执行循环体，再判断条件，适用于用户输入验证（至少询问一次）、资源获取（至少尝试一次）、状态检查等需要先执行再判断的场景。执行流程为：先执行循环体，再判断条件表达式，条件为true则继续执行，为false则退出循环。

<!-- @[do_while_loop](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
// 基本结构：至少执行一次
let loopCount: number = 0;
do {
  console.info(`${loopCount.toString()}`);
  loopCount++;
} while (loopCount < 5);

// 即使条件初始为false也执行一次
let loopValue2: number = 10;
do {
  console.info(`${loopValue2.toString()}`);  // 执行一次，输出10
  loopValue2++;
} while (loopValue2 < 5);

// 用户输入验证
let input: string = '';
do {
  input = getInput();
} while (input.length === 0);

function getInput(): string {
  return 'valid input';
}

// 重试逻辑
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

## 跳转语句

跳转语句用于改变循环或函数的执行流程。

### break语句

break用于跳出循环或switch，立即终止当前循环或分支的执行。

break常用于查找元素后终止、条件满足时退出、遇到错误时跳出以及提前结束无意义循环以优化性能。

<!-- @[break_statement](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
// 跳出for循环
for (let i: number = 0; i < 10; i++) {
  if (i === 5) {
    break;  // 跳出循环
  }
  console.info(`${i.toString()}`);
}
// 输出：0, 1, 2, 3, 4

// 跳出while循环
let breakCount: number = 0;
while (breakCount < 10) {
  if (breakCount === 5) {
    break;
  }
  console.info(`${breakCount.toString()}`);
  breakCount++;
}

// 查找元素后跳出
let breakNumbers: number[] = [1, 2, 3, 4, 5];
for (let num of breakNumbers) {
  if (num === 3) {
    console.info('找到 3');
    break;
  }
}
```

在`switch`语句中，`break`同样用于终止当前分支的执行：

<!-- @[break_in_switch](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
let switchValue: number = 2;

switch (switchValue) {
  case 1:
    console.info('一');
    break;  // 跳出switch
  case 2:
    console.info('二');
    break;  // 必须有break
  case 3:
    console.info('三');
    break;
  default:
    console.info('默认');
}
```

嵌套循环中，带标签的`break`可以直接跳出外层循环：

<!-- @[nested_loop_break](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
// 带标签的break：跳出外层循环
outerLoop: for (let i: number = 0; i < 10; i++) {
  for (let j: number = 0; j < 10; j++) {
    if (i + j === 15) {
      console.info(`找到: i=${i}, j=${j}`);
      break outerLoop;
    }
  }
}
```

### continue语句

continue用于跳过当前迭代，继续下一次循环，是循环控制的重要语句。

continue常用于过滤无效数据、满足条件时跳过、避免执行不必要代码以优化性能，以及替代复杂if-else嵌套以简化逻辑。

<!-- @[continue_statement](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
// 跳过偶数
for (let i: number = 0; i < 10; i++) {
  if (i % 2 === 0) {
    continue;  // 跳过偶数
  }
  console.info(`${i.toString()}`);
}
// 输出：1, 3, 5, 7, 9

// 跳过特定值
let continueNumbers: number[] = [1, 2, 3, 4, 5];
for (let num of continueNumbers) {
  if (num === 3) {
    continue;  // 跳过3
  }
  console.info(`${num.toString()}`);
}
// 输出：1, 2, 4, 5

// 过滤无效数据
let continueData: (string | null)[] = ['valid', '', 'valid', null, 'valid'];
for (let item of continueData) {
  if (item === '' || item === null) {
    continue;  // 跳过空值
  }
  processItem(item);
}

function processItem(item: string): void {
  console.info(`处理: ${item}`);
}
```

类似地，`continue`也支持标签语法，用于跳过外层循环的当前迭代：

<!-- @[nested_loop_continue](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
// 带标签的continue：跳过外层循环当前迭代
outerLoop: for (let i: number = 0; i < 5; i++) {
  for (let j: number = 0; j < 5; j++) {
    if (j === 2) {
      continue outerLoop;
    }
    console.info(`i=${i}, j=${j}`);
  }
}
```

### return语句（函数内控制流程）

return用于从函数返回，立即终止函数执行并将控制权交还给调用者，同时返回指定的值。return后的代码不会执行。常用于返回计算结果、参数无效时提前退出、根据条件返回不同结果、以及遇到错误时返回错误信息。

<!-- @[return_statement](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
// 基本返回
function add(a: number, b: number): number {
  return a + b;
}

let result: number = add(1, 2);

// 无返回值函数
function log(message: string): void {
  console.info(`${message}`);
  return;  // 可省略
}

// 条件返回
function classify(value: number): string {
  if (value > 0) {
    return 'positive';
  } else if (value < 0) {
    return 'negative';
  }
  return 'zero';
}

// 提前返回
function validate(input: string): boolean {
  if (input.length === 0) {
    return false;  // 提前返回
  }
  if (input.length > 100) {
    return false;
  }
  return true;
}

// 返回复杂类型
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

## 提前退出（函数内流程控制）

提前退出是指在函数入口处校验前置条件，不满足时直接return退出，避免深层嵌套，使主流程保持平坦。

### 条件return提前终止函数执行

在函数入口处对前置条件（参数合法性、权限、状态）做校验，不满足时直接return退出，避免层层嵌套，使主流程逻辑保持平坦清晰。

<!-- @[early_exit_pattern](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
// 参数验证后提前退出
function processData(data: string | null | undefined): void {
  if (data === null || data === undefined) {
    console.info('数据无效');
    return;  // 提前退出
  }
  
  // 正常处理
  console.info(`处理: ${data}`);
}

// 权限检查后提前退出
function accessResource(user: PatternUser): void {
  if (!user.hasPermission) {
    console.info('无权限');
    return;
  }
  
  // 有权限的处理
  loadResource();
}

function loadResource(): void {
  console.info('加载资源');
}

interface PatternUser {
  hasPermission: boolean;
}

// 错误处理后提前退出
function safeDivide(a: number, b: number): number | null {
  if (b === 0) {
    console.info('除数不能为零');
    return null;  // 提前退出，返回null
  }
  
  return a / b;
}

// 边界检查后提前退出
function getArrayElement(arr: number[], index: number): number | null {
  if (index < 0 || index >= arr.length) {
    return null;  // 提前退出
  }
  
  return arr[index];
}
```

### 结合可选值判断的提前退出

在可选值为null/undefined时提前return，避免深层嵌套。

<!-- @[null_undefined_check](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
// 处理可选参数
function greet(name: string | null): string {
  if (name === null) {
    return 'Hello, Guest';  // 提前退出
  }
  
  return `Hello, ${name}`;
}

// 处理可选链结果
function processConfig(config: Config | null): void {
  if (config === null) {
    console.info('配置不存在');
    return;
  }
  
  if (config.value === undefined) {
    console.info('配置值未定义');
    return;
  }
  
  console.info(`配置值: ${config.value}`);
}

interface Config {
  value: number | undefined;
}

// 多层空值检查
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

## 检测API可用性

在HarmonyOS多版本、多设备场景下，部分API可能仅在特定版本或设备上可用。运行时检测API可用性可确保代码向后兼容——新API存在时使用新实现，不存在时回退到兼容实现。

### 运行时环境检测

通过typeof检测对象方法是否存在，判断当前运行时环境。

<!-- @[check_object_method_existence](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
// 检测全局对象
function checkEnvironment(): void {
  if (typeof console !== 'undefined') {
    console.info('console 可用');
  }
  
  if (typeof setTimeout !== 'undefined') {
    console.info('setTimeout 可用');
  }
}

class OptionalWorker {
  public methodName?: () => void;
}

// 检测方法存在
function safeCall(): void {
  let obj: OptionalWorker = new OptionalWorker();
  
  if (obj.methodName !== undefined) {
    obj.methodName();
  } else {
    console.info('方法不存在');
  }
}

// ArkTS中使用类型检查
interface Feature {
  newMethod?(): void;
}

function useFeature(feature: Feature): void {
  if (feature.newMethod !== undefined) {
    feature.newMethod();
  } else {
    console.info('使用旧方法');
    fallbackMethod();
  }
}

function fallbackMethod(): void {
  console.info('备用方法');
}
```

### 特性兼容性判断

运行时通过版本号或功能开关判断当前环境是否支持某特性，据此在新实现与兼容的旧实现之间分支选择，从而保证向后兼容。

<!-- @[version_feature_platform_check](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Control.ets) -->

``` TypeScript
// 版本检查
function checkVersion(): void {
  const MIN_VERSION: number = 2;
  let currentVersion: number = getCurrentVersion();
  
  if (currentVersion < MIN_VERSION) {
    console.info('版本过低，使用兼容方案');
    useLegacyImplementation();
  } else {
    useNewImplementation();
  }
}

function getCurrentVersion(): number {
  return 3;
}

function useLegacyImplementation(): void {
  console.info('使用旧实现');
}

function useNewImplementation(): void {
  console.info('使用新实现');
}

// 功能开关
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
  console.info('新方式处理');
}

function processOldWay(): void {
  console.info('旧方式处理');
}

// 平台检测
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
  console.info('移动端配置');
}

function configureForDesktop(): void {
  console.info('桌面端配置');
}

function configureForWeb(): void {
  console.info('Web端配置');
}

function useDefaultConfig(): void {
  console.info('默认配置');
}
```
