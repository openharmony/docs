# 集合类型
<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

集合类型用于存储多个数据项。ArkTS提供多种集合类型，包括数组、元组、Set、Map等，每种类型有其特定的用途和特性。ArkTS集合主要按结构与可变性两个维度划分：结构上区分数组 Array、集合 Set、字典（Map），可变性上区分可变集合与只读集合（如 ReadonlyArray）。理解各类型在有序性、唯一性、键值映射等方面的差异，是选型的前提。

## 可变集合与只读集合

集合按修改权限分为可变和只读两种，可变集合支持增删改，只读集合仅允许读取。

<!-- @[ts_mutable_and_readonly_collections](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Collections.ts) -->

``` TypeScript
// 可变集合
let mutableArray: number[] = [1, 2, 3];
mutableArray.push(4);  // 可以添加

let mutableSet: Set<number> = new Set([1, 2]);
mutableSet.add(3);     // 可以添加

let mutableMap: Map<string, number> = new Map();
mutableMap.set('key', 10);  // 可以添加

// 只读集合（使用ReadonlyArray）
let readonlyArray: ReadonlyArray<number> = [1, 2, 3];
readonlyArray.push(4);  // 编译错误：不可修改
```

## 数组（Array）

数组是存储有序元素集合的最常用数据结构。数组中的元素按索引排列，索引从0开始，可以动态添加和删除元素。

数组常用于存储有序的数据列表（如用户列表、商品列表、日志记录）、表示序列数据（如时间序列、事件流）、处理批量数据（如批量操作、批量转换、批量查询）或作为栈或队列使用（如任务队列、历史记录）。其核心特性包括：元素按插入顺序存储且索引从0开始（有序性）、可动态添加、删除、修改元素（可变性）、所有元素必须为相同类型或联合类型（类型约束）、长度可随时改变（动态长度）。

### 数组的声明与初始化

数组可以通过字面量或构造函数创建，声明时指定元素类型以确保类型安全。

<!-- @[array_creation_methods](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
// 使用类型后缀 []
let numbers: number[] = [1, 2, 3, 4, 5];
let strings: string[] = ['a', 'b', 'c'];
let booleans: boolean[] = [true, false, true];

// 使用泛型Array
let numbers2: Array<number> = [1, 2, 3];
let strings2: Array<string> = ['hello', 'world'];

// 空数组
let empty: number[] = [];
let empty2: string[] = [];

// 联合类型数组
let mixed: (number | string)[] = [1, 'two', 3, 'four'];
let nullable: (number | null)[] = [1, null, 3];

// 使用扩展运算符创建
let original: number[] = [1, 2, 3];
let copy: number[] = [...original];
let extended: number[] = [...original, 4, 5];
```

`number[]`和`Array<number>`功能等价，推荐使用`number[]`形式（更简洁），`Array<T>`语法则适合需要强调泛型的场景。扩展运算符`...original`创建新数组，修改副本不影响原数组。

### 访问与修改数组元素

数组元素通过索引访问和修改，常用于读取值、更新数据、数据处理和运行时状态更新等场景。

<!-- @[array_element_access](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let arr: number[] = [10, 20, 30, 40, 50];

// 读取元素
let first: number = arr[0];   // 10
let second: number = arr[1];  // 20
let last: number = arr[arr.length - 1];  // 50

// 修改元素
arr[0] = 100;
arr[1] = 200;
console.info(`${arr.join(', ')}`);  // 100, 200, 30, 40, 50

// 越界访问
let outOfBounds: number | undefined = arr[10];
console.info(`${outOfBounds}`);  // undefined

// 安全访问
let index: number = 5;
if (index >= 0 && index < arr.length) {
  let safe: number = arr[index];
}
```

数组越界访问返回`undefined`而非抛出异常，因此访问不确定索引前应进行边界检查。

### 数组的遍历

数组遍历常用于数据处理、查找、统计和转换。选择方式时：只需值用`for...of`，需要索引用`for`循环，函数式处理用`forEach`，遍历中不要修改数组长度。

<!-- @[array_for_loop_iteration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let iterArr: number[] = [1, 2, 3, 4, 5];

for (let value of iterArr) {
  console.info(`${value}`);
}

// 获取索引和值
for (let i: number = 0; i < iterArr.length; i++) {
  console.info(`Index ${i}: ${iterArr[i]}`);
}
```

`forEach`方法以函数式风格遍历数组，对每个元素执行回调：

<!-- @[array_forEach_method](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let forEachArr: number[] = [1, 2, 3];

forEachArr.forEach((value: number, index: number): void => {
  console.info(`Index ${index}: ${value}`);
});
```

`forEach`不支持`break`，需要提前退出遍历时使用`for...of`或`for`循环。ArkTS中箭头函数参数必须显式标注类型，不能省略参数类型注解。

<!-- @[array_indexed_iteration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let iterArr2: number[] = [1, 2, 3];

for (let i: number = 0; i < iterArr2.length; i++) {
  console.info(`${iterArr2[i]}`);
}
```

### 数组的常用操作

数组提供push、pop、shift、splice等常用操作，用于增删改查元素。

<!-- @[array_add_elements](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let elemArr: number[] = [1, 2];

// push：末尾添加
elemArr.push(3);
elemArr.push(4, 5);  // 可添加多个
let newLength: number = elemArr.push(6);  // 返回新长度

// unshift：开头添加
elemArr.unshift(0);
elemArr.unshift(-1, -2);  // 可添加多个

console.info(`${elemArr.join(', ')}`);  // -1, -2, 0, 1, 2, 3, 4, 5, 6
```

删除元素使用pop、shift、splice等方法：

<!-- @[array_remove_elements](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let elemArr2: number[] = [1, 2, 3, 4, 5];

// pop：删除末尾
let elemLast: number | undefined = elemArr2.pop();  // 5
console.info(`${elemArr2.join(', ')}`);  // 1, 2, 3, 4

// shift：删除开头
let elemFirst: number | undefined = elemArr2.shift();  // 1
console.info(`${elemArr2.join(', ')}`);  // 2, 3, 4

// splice：删除指定位置
let removed: number[] = elemArr2.splice(1, 2);  // 删除索引1开始的2个元素
console.info(`${elemArr2.join(', ')}`);  // 2
console.info(`${removed.join(', ')}`);  // 3, 4
```

`concat`和`slice`方法用于拼接和截取数组，均返回新数组而不修改原数组：

<!-- @[array_concat_and_slice](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let arr1: number[] = [1, 2];
let arr2: number[] = [3, 4];

// concat：拼接数组
let combined: number[] = arr1.concat(arr2);
console.info(`${combined.join(', ')}`);  // 1, 2, 3, 4
let sliceExtended: number[] = arr1.concat(3, 4, [5, 6]);
console.info(`${sliceExtended.join(', ')}`);  // 1, 2, 3, 4, 5, 6

// slice：拆分/截取
let sliceArr: number[] = [1, 2, 3, 4, 5];
let sub: number[] = sliceArr.slice(1, 4);
console.info(`${sub.join(', ')}`);  // 2, 3, 4
let tail: number[] = sliceArr.slice(2);
console.info(`${tail.join(', ')}`);  // 3, 4, 5
let sliceCopy: number[] = sliceArr.slice();
console.info(`${sliceCopy.join(', ')}`);  // 1, 2, 3, 4, 5（拷贝）
```

数组的查找与过滤方法包括`indexOf`、`includes`、`find`和`filter`等：

<!-- @[array_search_and_filter](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let filterArr: number[] = [1, 2, 3, 2, 1];

// indexOf：查找索引
let filterIndex: number = filterArr.indexOf(2);  // 1（第一个匹配）
let lastIndex: number = filterArr.lastIndexOf(2);  // 3（最后一个匹配）
let notFound: number = filterArr.indexOf(10);  // -1

// includes：是否包含
let has2: boolean = filterArr.includes(2);  // true
let has10: boolean = filterArr.includes(10);  // false

// find：条件查找
let filterNumbers: number[] = [1, 5, 10, 15, 20];
let found: number | undefined = filterNumbers.find((value: number): boolean => {
  return value > 10;
});  // 15

let foundIndex: number = filterNumbers.findIndex((value: number): boolean => {
  return value > 10;
});  // 3

// filter：过滤
let allNumbers: number[] = [1, 2, 3, 4, 5, 6];
let evens: number[] = allNumbers.filter((value: number): boolean => {
  return value % 2 === 0;
});
console.info(`${evens.join(', ')}`);  // 2, 4, 6

let greaterThan3: number[] = allNumbers.filter((value: number): boolean => {
  return value > 3;
});
console.info(`${greaterThan3.join(', ')}`);  // 4, 5, 6
```

## 元组（Tuple）

元组是固定长度和类型的有序集合。元组与数组不同：元组的长度固定，每个位置的类型可以不同，而数组的长度可变，所有元素类型相同。

- 表示固定结构的数据（如坐标点`[x, y]`、RGB颜色`[r, g, b]`）。
- 返回多个值（如函数返回`[result, error]`）。
- 表示键值对（如`[key, value]`）。
- 定义特定位置有特定类型的数据（如`[id, name, age]`）。

### 元组的声明与初始化

元组通过明确指定每个位置的元素类型来声明，长度和类型序列固定。

<!-- @[tuple_basics](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
// TypeScript中的元组
let tuple: [number, string] = [1, 'hello'];
let coordinate: [number, number] = [10, 20];
let user: [number, string, boolean] = [1, 'Alice', true];

// 在ArkTS中，元组通常用数组表示
let pair: number[] = [1, 2];  // 两元素数组模拟元组
let triple: [number, string, boolean] = [1, 'text', true];  // 类型标注
```

上述类型标注中每个位置的类型可以不同，从而表达固定结构的数据。在ArkTS中，简单的固定长度数组可以替代元组的作用。

### 访问元组元素

元组元素通过索引访问，每个位置有明确的类型，编译器会据此进行类型检查；元组也常用于让函数返回多个相关值。

<!-- @[tuple_element_access](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
// 索引访问
let accessTuple: [number, string] = [1, 'hello'];
let num: number = accessTuple[0];    // 1
let str: string = accessTuple[1];    // 'hello'

// 访问数组形式的元组
let accessPair: number[] = [10, 20];
let accessFirst: number = accessPair[0];   // 10
let accessSecond: number = accessPair[1];  // 20

// 安全访问（带类型检查）
function getPairElement(arr: number[], index: number): number | undefined {
  if (arr.length === 2 && index >= 0 && index < 2) {
    return arr[index];
  }
  return undefined;
}
```

元组通过索引访问时，编译器保留每个位置的精确类型信息（如`tuple[0]`为`number`，`tuple[1]`为`string`）；而使用数组形式（如`number[]`）模拟元组时，类型信息不如真正的元组精确，访问时需要手动进行边界检查。

### 元组的只读特性

只读元组确保数据不被修改，适用于配置数据、常量坐标、函数参数保护等场景，编译器会强制检查修改操作。

<!-- @[ts_readonly_tuple](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Collections.ts) -->

``` TypeScript
// TypeScript中的只读元组
let readonlyTuple: readonly [number, string] = [1, 'hello'];
readonlyTuple[0] = 2;  // 编译错误

// ArkTS中使用ReadonlyArray模拟
let readonlyPair: ReadonlyArray<number> = [1, 2];
readonlyPair[0] = 3;  // 编译错误
```

TypeScript使用`readonly`关键字修饰元组，ArkTS不支持该语法，需使用`ReadonlyArray`实现等效的只读约束。只读检查在编译期完成，运行时无额外开销，适用于保护配置数据、函数参数等不可变场景。

### 元组与数组的区别

元组具有固定长度和类型序列，数组长度可变且元素类型统一。

<!-- @[tuple_vs_array](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
// 元组：固定长度和类型
let point: [number, number] = [10, 20];  // 只能有两个number

// 数组：可变长度，统一类型
let tupleNumbers: number[] = [1, 2, 3, 4, 5];  // 可添加更多number

// 元组表示固定结构
let userTuple: [number, string, boolean] = [1, 'Alice', true];
console.info(`${userTuple.join(', ')}`);  // 1, Alice, true

// 数组表示动态集合
let userIds: number[] = [1, 2, 3, 4, 5];
userIds.push(6);  // 可添加
```

## 集合（Set）

Set用于存储不重复元素的集合，适合去重、成员存在性检查等场景，与数组不同，Set中的元素唯一。

### Set的声明与初始化

Set用于存储唯一值的集合，通过构造函数创建并指定元素类型。

<!-- @[set_creation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
// 创建空Set
let emptySet: Set<number> = new Set();

// 从数组创建
let numbersSet: Set<number> = new Set([1, 2, 3, 4, 5]);

// 添加初始元素
let stringSet: Set<string> = new Set();
stringSet.add('a');
stringSet.add('b');
```

### Set的核心特性

Set保证元素唯一性，自动去重，提供高效的存在性检查。

<!-- @[set_uniqueness](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let set: Set<number> = new Set([1, 2, 2, 3, 3, 3]);
console.info(`${set.size}`);  // 3（去除重复）

// 添加重复元素无效
set.add(1);
console.info(`${set.size}`);  // 3（不变）

// 去除数组重复元素
let uniqueArr: number[] = [1, 2, 2, 3, 3, 3];
let unique: number[] = Array.from(new Set(uniqueArr));
console.info(`${unique.join(', ')}`);  // 1, 2, 3
```

### Set的常用操作

Set提供添加、删除、查找、遍历等基本操作，所有元素唯一不重复。

<!-- @[set_add_method](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let addSet: Set<number> = new Set();

addSet.add(1);
addSet.add(2);
addSet.add(3);

let addedSet: Set<number> = addSet.add(4);  // 返回Set本身
```

删除元素用delete方法，返回是否成功删除：

<!-- @[set_delete_method](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let delSet: Set<number> = new Set([1, 2, 3]);

let deleted: boolean = delSet.delete(2);  // true（成功删除）
let isRemoved: boolean = delSet.delete(10);  // false（不存在）

console.info(`${delSet.size}`);  // 2
```

使用`has`方法检查Set中是否存在某个元素：

<!-- @[set_has_method](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let hasSet: Set<number> = new Set([1, 2, 3]);

let has1: boolean = hasSet.has(1);  // true
let hasHas10: boolean = hasSet.has(10);  // false
```

遍历Set用for...of或forEach，也可通过values()、keys()获取迭代器：

<!-- @[set_iteration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let iterSet: Set<number> = new Set([1, 2, 3]);

// for...of遍历
for (let value of iterSet) {
  console.info(`${value}`);
}

// forEach方法
iterSet.forEach((value: number): void => {
  console.info(`${value}`);
});

// 获取所有值
let values: IterableIterator<number> = iterSet.values();
for (let value of values) {
  console.info(`${value}`);
}

// 获取所有键（Set中键等于值）
let keys: IterableIterator<number> = iterSet.keys();
for (let key of keys) {
  console.info(`${key}`);
}
```

Set与数组之间可以相互转换，利用Set的唯一性可实现数组去重：

<!-- @[set_array_conversion](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
// Set转数组
let convSet: Set<number> = new Set([1, 2, 3]);
let convArr: number[] = Array.from(convSet);
console.info(`${convArr.join(', ')}`);  // 1, 2, 3

// 数组转Set
let convNumbers: number[] = [1, 2, 2, 3];
let setFromArr: Set<number> = new Set(convNumbers);
console.info(`${Array.from(setFromArr).join(', ')}`);  // 1, 2, 3

// 去重
let duplicates: number[] = [1, 1, 2, 2, 3, 3];
let convUnique: number[] = Array.from(new Set(duplicates));
console.info(`${convUnique.join(', ')}`);  // 1, 2, 3
```

clear方法清空Set中所有元素：

<!-- @[set_clear_method](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let clearSet: Set<number> = new Set([1, 2, 3]);
clearSet.clear();
console.info(`${clearSet.size}`);  // 0
```

## 字典（Map）

Map是存储键值对的集合，键和值可以是任意类型。

### Map的声明与初始化

Map用于存储键值对的集合，通过构造函数创建并指定键和值的类型。

<!-- @[map_creation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
// 创建空Map
let emptyMap: Map<string, number> = new Map();

// 从数组创建（键值对数组）
let initMap: Map<string, number> = new Map([
  ['a', 1],
  ['b', 2],
  ['c', 3]
]);

// 添加初始键值对
let map: Map<string, number> = new Map();
map.set('one', 1);
map.set('two', 2);
```

### 键值对的访问、添加与删除

Map通过get、set、delete方法访问和修改键值对，支持动态数据管理。

<!-- @[map_basic_operations](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let opsMap: Map<string, number> = new Map();

// 添加键值对
opsMap.set('a', 1);
opsMap.set('b', 2);
opsMap.set('c', 3);

// 访问值
let valueA: number | undefined = opsMap.get('a');  // 1
let valueB: number | undefined = opsMap.get('b');  // 2
let opsNotFound: number | undefined = opsMap.get('x');  // undefined

// 判断键是否存在
let hasA: boolean = opsMap.has('a');  // true
let hasX: boolean = opsMap.has('x');  // false

// 删除键值对
let opsDeleted: boolean = opsMap.delete('b');  // true
let opsNotDeleted: boolean = opsMap.delete('x');  // false

// 更新值
opsMap.set('a', 10);  // 更新 'a' 的值

// 清空Map
opsMap.clear();
console.info(`${opsMap.size}`);  // 0
```

### Map的遍历

Map遍历使用forEach或for-of循环，可以遍历键、值或键值对。

<!-- @[map_iteration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let iterMap: Map<string, number> = new Map([
  ['a', 1],
  ['b', 2],
  ['c', 3]
]);

// forEach遍历
iterMap.forEach((value: number, key: string): void => {
  console.info(`${key}: ${value}`);
});

// for...of遍历entries
for (let entry of iterMap.entries()) {
  let key: string = entry[0];
  let value: number = entry[1];
  console.info(`${key}: ${value}`);
}

// for...of遍历键
for (let key of iterMap.keys()) {
  console.info(`${key}`);
}

// for...of遍历值
for (let value of iterMap.values()) {
  console.info(`${value}`);
}

// 不使用解构遍历，显式读取entry元素
for (let entry of iterMap.entries()) {
  let key: string = entry[0];
  let value: number = entry[1];
  console.info(`${key}: ${value}`);
}
```

### Map与普通对象的区别

Map键可以是任意类型，对象键只能是字符串，Map更适合动态键值存储。

<!-- @[map_vs_object](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
// Map：任意键类型
let objMap2: Map<number, string> = new Map();
objMap2.set(1, 'one');
objMap2.set(2, 'two');

class KeyObject {
  public id: number;

  constructor(id: number) {
    this.id = id;
  }
}

let objMap: Map<KeyObject, string> = new Map();
let keyObj: KeyObject = new KeyObject(1);
objMap.set(keyObj, 'value');

// Record：适合表达字符串键值对象
let obj: Record<string, number> = {};
obj['key1'] = 1;
obj['key2'] = 2;

let objValue: number | undefined = obj['key1'];
if (objValue !== undefined) {
  console.info(`${objValue}`);
}

// Map：保持顺序
let orderedMap: Map<string, number> = new Map();
orderedMap.set('a', 1);
orderedMap.set('b', 2);
orderedMap.set('c', 3);
console.info(`${Array.from(orderedMap.keys()).join(', ')}`);  // a, b, c（保持顺序）

// Map：直接获取大小
console.info(`${orderedMap.size}`);  // 3

// Object：需要计算大小
let objSize: number = Object.keys(obj).length;
```

## 只读集合类型

只读集合类型禁止修改操作，适合传递不变数据。

### 只读数组（ReadonlyArray）

ReadonlyArray提供只读接口，禁止push、pop等修改操作。

<!-- @[ts_readonly_array_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Collections.ts) -->

``` TypeScript
let readonlyArr: ReadonlyArray<number> = [1, 2, 3];

// 不可修改
readonlyArr.push(4);      // 编译错误
readonlyArr[0] = 10;      // 编译错误
readonlyArr.pop();        // 编译错误

// 可以读取
let first: number = readonlyArr[0];  // 1
let length: number = readonlyArr.length;  // 3

// 可以遍历
for (let value of readonlyArr) {
  console.info(`${value}`);
}

// 创建只读数组
let mutable: number[] = [1, 2, 3];
let readonly: ReadonlyArray<number> = mutable;  // 转为只读

// 类型别名
type ReadOnlyNumbers = ReadonlyArray<number>;
let nums: ReadOnlyNumbers = [1, 2, 3];
```

### 只读Map与只读Set

只读集合通过`ReadonlyMap`或`ReadonlySet`类型声明，防止意外修改。`ReadonlyMap`和`ReadonlySet`为ArkTS内置只读接口。

<!-- @[readonly_map_set_interfaces](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
interface ReadonlyMap<K, V> {
  get(key: K): V | undefined;
  has(key: K): boolean;
  size: number;
  forEach(callback: (value: V, key: K) => void): void;
}

interface ReadonlySet<T> {
  has(value: T): boolean;
  size: number;
  forEach(callback: (value: T) => void): void;
}

// 使用时返回只读接口
function getReadOnlyMap(): ReadonlyMap<string, number> {
  let map: Map<string, number> = new Map();
  map.set('a', 1);
  return map;  // 返回只读视图
}
```

### 只读集合的使用场景

只读集合适用于配置数据、常量列表等不应被修改的场景。

<!-- @[readonly_collection_scenarios](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
// 配置数据：只读，防止意外修改
const CONFIG: ReadonlyArray<string> = ['api', 'db', 'cache'];

// 函数参数：只读，保护原始数据
function processItems(items: ReadonlyArray<number>): number {
  let sum: number = 0;
  for (let item of items) {
    sum += item;
  }
  return sum;
}

let scenariosNumbers: number[] = [1, 2, 3];
processItems(scenariosNumbers);  // 传入只读视图

// 返回只读结果：防止外部修改
function getConstants(): ReadonlyArray<string> {
  return ['CONST_A', 'CONST_B'];
}
```

## 集合的遍历与迭代器

集合遍历使用for-of、forEach和迭代器接口逐个访问元素。

### for...of循环遍历

for-of循环遍历可迭代对象，语法简洁，直接获取元素值。

<!-- @[for_of_iteration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
// 数组
let iterArr3: number[] = [1, 2, 3];
for (let value of iterArr3) {
  console.info(`${value}`);
}

// Set
let iterSet2: Set<number> = new Set([1, 2, 3]);
for (let value of iterSet2) {
  console.info(`${value}`);
}

// Map
let iterMap2: Map<string, number> = new Map([['a', 1], ['b', 2]]);
for (let entry of iterMap2) {
  console.info(`${entry[0]}: ${entry[1]}`);  // a: 1, b: 2
}

// 字符串
let text: string = 'Hello';
for (let char of text) {
  console.info(`${char}`);
}
```

### 迭代器接口（Iterator）的使用

迭代器通过next()方法按需取值，支持手动控制遍历节奏。

<!-- @[iterator_manual_traversal](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
// 获取迭代器
let traverseArr: number[] = [1, 2, 3];
let iterator: IterableIterator<number> = traverseArr.values();

// 手动遍历
let result: IteratorResult<number> = iterator.next();
while (!result.done) {
  console.info(`${result.value}`);
  result = iterator.next();
}

// Set迭代器
let traverseSet: Set<string> = new Set(['a', 'b', 'c']);
let setIterator: IterableIterator<string> = traverseSet.values();

console.info(`${JSON.stringify(setIterator.next())}`);  // {"value":"a","done":false}
console.info(`${JSON.stringify(setIterator.next())}`);  // {"value":"b","done":false}
console.info(`${JSON.stringify(setIterator.next())}`);  // {"value":"c","done":false}
console.info(`${JSON.stringify(setIterator.next())}`);  // {"value":undefined,"done":true}

// Map迭代器
let traverseMap: Map<string, number> = new Map([['x', 10], ['y', 20]]);
let mapIterator: IterableIterator<[string, number]> = traverseMap.entries();

console.info(`${JSON.stringify(mapIterator.next())}`);  // {"value":["x",10],"done":false}
```

### 集合的解构赋值

ArkTS不支持集合的解构赋值，需通过索引或迭代器逐个访问元素。

**TypeScript对照**

<!-- @[ts_destructuring_alternatives](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Collections.ts) -->

``` TypeScript
// 数组解构
let [a, b] = [1, 2];

// 正确做法：单独赋值
let arr: number[] = [1, 2];
let aVal: number = arr[0];
let bVal: number = arr[1];

// Map解构
let map: Map<string, number> = new Map([['key', 10]]);
let [mapKey, mapValue] = map.entries().next().value;

// 正确做法：单独赋值
let entry: [string, number] | undefined = Array.from(map.entries())[0];
if (entry !== undefined) {
  let entryKey: string = entry[0];
  let entryValue: number = entry[1];
}

// Set解构
let [setFirst, setSecond] = new Set([1, 2]);

// 正确做法：单独赋值
let set: Set<number> = new Set([1, 2]);
let values: number[] = Array.from(set);
let firstVal: number = values[0];
let secondVal: number = values[1];
```

## 使用流程

1. 判断数据关系：有序列表用`Array`，唯一值集合用`Set`，键值索引用`Map`，固定长度且位置与类型对应的数据结构优先使用明确接口或元组。
2. 明确元素类型：声明数组元素、Set元素、Map键和值的具体类型，不使用`any`或`unknown`接收集合内容。
3. 确认可变边界：函数只读取集合时使用`ReadonlyArray`；需要写入时只在创建者或专门负责更新的函数中修改。
4. 选择访问方式：数组索引、`find`、`Map.get`等可能返回`undefined`的访问结果必须先判断再使用。
5. 选择遍历方式：只读值用`for...of`，需要索引用`for`或带类型标注的`forEach`，遍历`Map`时显式读取`entry[0]`和`entry[1]`。
6. 检查ArkTS限制：不要使用解构赋值遍历集合，不要把对象键作为普通对象索引，不要把可变集合直接暴露给不该修改它的调用方。

## 反模式

下面这些写法在TypeScript中常见，但迁移到ArkTS或编写长期维护代码时容易出错。

反模式一：忽略可能为`undefined`的读取结果。

<!-- @[ts_map_safe_access](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Collections.ts) -->

``` TypeScript
let scores: Map<string, number> = new Map();
scores.set('Alice', 95);

// 反例：Map.get可能返回undefined
let aliceScore: number = scores.get('Alice');

// 推荐：先判断再使用
let aliceScoreSafe: number | undefined = scores.get('Alice');
if (aliceScoreSafe !== undefined) {
  console.info(`${aliceScoreSafe}`);
}
```

反模式二：用数组承担唯一集合职责。

<!-- @[unique_collection_with_set](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
// 反例：每次插入都手动includes，容易遗漏去重逻辑
let ids: number[] = [];
if (!ids.includes(1001)) {
  ids.push(1001);
}

// 推荐：唯一性由Set表达
let uniqueIds: Set<number> = new Set();
uniqueIds.add(1001);
uniqueIds.add(1001);
console.info(`${uniqueIds.size}`);  // 1
```

反模式三：用解构遍历`Map`。

**TypeScript对照**

<!-- @[ts_map_entry_iteration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Collections.ts) -->

``` TypeScript
let userScores: Map<string, number> = new Map([['Alice', 95], ['Bob', 88]]);

// TypeScript对照写法，ArkTS不使用解构：
for (let [name, score] of userScores) {
  console.info(`${name}: ${score}`);
}

// 推荐：显式读取entry
for (let entry of userScores.entries()) {
  let name: string = entry[0];
  let score: number = entry[1];
  console.info(`${name}: ${score}`);
}
```
反模式四：用普通对象保存对象键。

普通对象（`Record<string, T>`）的键只能是字符串，用对象作键需手动调用`toString()`转换，丢失对象身份，不同对象转换后可能产生相同的字符串键导致覆盖。

<!-- @[object_key_with_record](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
// 用普通对象保存对象键，需手动调用toString()转换
class RecordCacheKey {
  public id: number;

  constructor(id: number) {
    this.id = id;
  }

  toString(): string {
    return `key-${this.id}`;
  }
}

let recordKey: RecordCacheKey = new RecordCacheKey(1);
let recordCache: Record<string, string> = {};
recordCache[recordKey.toString()] = 'value';
console.info(`${recordCache[recordKey.toString()]}`); // value
```

推荐做法：使用`Map`保存对象键，保留对象身份，无需手动转换。

<!-- @[object_key_with_map](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
class CacheKey {
  public id: number;

  constructor(id: number) {
    this.id = id;
  }
}

let key: CacheKey = new CacheKey(1);

let cache: Map<CacheKey, string> = new Map();
cache.set(key, 'value');
console.info(`${cache.get(key)!}`); // value
```

反模式五：修改只应读取的入参。

<!-- @[readonly_array_parameter](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
// 反例：调用方传入的数组会被修改
function appendDefault(items: string[]): void {
  items.push('default');
}

// 推荐：只读场景声明为ReadonlyArray
function countItems(items: ReadonlyArray<string>): number {
  return items.length;
}
```

## 数组高级方法

数组提供`map`（映射）、`filter`（过滤）、`reduce`（归约）、`sort`/`reverse`（排序）、`flat`/`flatMap`（展平）等函数式方法，支持链式组合实现"筛选→变换→汇总"的数据处理管道。这些方法返回新数组（`sort`/`reverse`除外），不修改原数组。

### map：映射每个元素

`map`对数组每个元素执行变换，返回新数组。

<!-- @[array_map](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let amNumbers: number[] = [1, 2, 3, 4, 5];

let amDoubled: number[] = amNumbers.map((n: number): number => n * 2);
console.info(`${amDoubled.join(', ')}`);  // 2, 4, 6, 8, 10

let amStrings: string[] = amNumbers.map((n: number): string => `Item ${n}`);
console.info(`${amStrings.join(', ')}`);  // Item 1, Item 2, Item 3, Item 4, Item 5
```

### filter：过滤元素

`filter`方法对数组每个元素执行判断函数，返回所有满足条件的元素组成的新数组，原数组不变。常用于数据筛选，如从用户列表中筛选活跃用户、从商品列表中筛选在售商品。

<!-- @[array_filter](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let afNumbers: number[] = [1, 2, 3, 4, 5, 6];

let afEvens: number[] = afNumbers.filter((n: number): boolean => n % 2 === 0);
console.info(`${afEvens.join(', ')}`);  // 2, 4, 6
```

### reduce：归约数组

`reduce`将数组归约为单个值，需提供初始值。

<!-- @[array_reduce](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let arNumbers: number[] = [1, 2, 3, 4, 5];

let arSum: number = arNumbers.reduce((acc: number, n: number): number => acc + n, 0);
console.info(`${arSum.toString()}`);  // 15

let arProduct: number = arNumbers.reduce((acc: number, n: number): number => acc * n, 1);
console.info(`${arProduct.toString()}`);  // 120
```

### sort与reverse：排序

`sort`方法对数组元素原地排序，可传入比较函数自定义排序规则；`reverse`方法将数组元素顺序反转。两者都修改原数组，若需保留原数组，先调用`slice()`创建副本再排序。

<!-- @[array_sort](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let asNumbers: number[] = [3, 1, 4, 1, 5, 9, 2, 6];

let asAscending: number[] = [...asNumbers].sort((a: number, b: number): number => a - b);
console.info(`${asAscending.join(', ')}`);  // 1, 1, 2, 3, 4, 5, 6, 9

let asDescending: number[] = [...asNumbers].sort((a: number, b: number): number => b - a);
console.info(`${asDescending.join(', ')}`);  // 9, 6, 5, 4, 3, 2, 1, 1

let asReversed: number[] = [...asNumbers].reverse();
console.info(`${asReversed.join(', ')}`);  // 6, 2, 9, 5, 1, 4, 1, 3
```

### 组合使用map、filter、reduce

`map`、`filter`、`reduce`可通过链式调用组合使用，实现"筛选→变换→汇总"的数据处理管道。例如：先`filter`筛选有效数据，再`map`提取关键字段，最后`reduce`计算汇总值。链式调用时每一步返回新数组，不影响原始数据。

<!-- @[array_chain](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
interface AcProduct {
  name: string;
  price: number;
  category: string;
}

let acProducts: AcProduct[] = [
  { name: 'Laptop', price: 999, category: 'Electronics' },
  { name: 'Mouse', price: 25, category: 'Electronics' },
  { name: 'Book', price: 15, category: 'Books' },
  { name: 'Keyboard', price: 75, category: 'Electronics' }
];

let acTotal: number = acProducts
  .filter((p) => p.category === 'Electronics')
  .map((p) => p.price)
  .reduce((acc: number, price: number) => acc + price, 0);

console.info(`Electronics total: ${acTotal}`);  // 1099
```

### flat与flatMap

`flat()`将嵌套数组展平为一维数组，可指定展平深度。`flatMap()`先对每个元素执行映射函数，再将结果展平一级，等价于`map()`后再`flat()`，常用于将嵌套结构转换并展平。两者也可使用`reduce`和展开运算符手动实现相同效果。

<!-- @[flat_flatmap_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let ffnNested: number[][] = [[1, 2], [3, 4], [5, 6]];

// flat：将二维数组展平为一维
let ffnFlat: number[] = ffnNested.flat();
console.info(`${ffnFlat.join(', ')}`); // 1, 2, 3, 4, 5, 6

// flatMap：对每个元素映射后展平一级
let ffnWords: string[] = ['hello world', 'foo bar'];
let ffnFlatMapped: string[] = ffnWords.flatMap((s: string): string[] => s.split(' '));
console.info(`${ffnFlatMapped.join(', ')}`); // hello, world, foo, bar

// reduce和展开运算符替代flat
let ffnFlatReduce: number[] = ffnNested.reduce((acc: number[], arr: number[]): number[] => {
  return [...acc, ...arr];
}, []);
console.info(`${ffnFlatReduce.join(', ')}`); // 1, 2, 3, 4, 5, 6
```

## 迭代器手动遍历

通过`values()`获取迭代器，使用`next()`方法手动控制遍历节奏。

<!-- @[iterator_manual](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let imArr: number[] = [10, 20, 30];
let imIter: IterableIterator<number> = imArr.values();

let imResult: IteratorResult<number> = imIter.next();
while (!imResult.done) {
  console.info(`${imResult.value.toString()}`);
  imResult = imIter.next();
}
// 输出: 10, 20, 30

// Set迭代器
let imSet: Set<string> = new Set<string>();
imSet.add('a');
imSet.add('b');
let imSetIter: IterableIterator<string> = imSet.values();
let imSetResult: IteratorResult<string> = imSetIter.next();
while (!imSetResult.done) {
  console.info(`${imSetResult.value}`);
  imSetResult = imSetIter.next();
}
// 输出: a, b

// Map迭代器
let imMap: Map<string, number> = new Map<string, number>();
imMap.set('x', 10);
imMap.set('y', 20);
let imMapIter: IterableIterator<[string, number]> = imMap.entries();
let imMapResult: IteratorResult<[string, number]> = imMapIter.next();
while (!imMapResult.done) {
  let entry: [string, number] = imMapResult.value;
  console.info(`${entry[0]}: ${entry[1]}`);
  imMapResult = imMapIter.next();
}
// 输出: x: 10, y: 20
```
