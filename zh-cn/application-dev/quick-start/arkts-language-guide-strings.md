# 字符串
<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

字符串是表示文本数据的基本类型。ArkTS提供丰富的字符串操作方法，支持模板字符串、Unicode处理等功能。

## 字符串字面量

字符串字面量是表示文本数据的基本方式。ArkTS支持三种字符串字面量形式：单引号、双引号和模板字符串，用于表示文本内容（如用户输入、消息、配置值）、定义标识符和名称（如文件路径、API端点）、构建输出信息（如日志、错误消息）以及存储和传递文本数据。

### 字符串声明

字符串可以使用单引号、双引号或反引号声明，推荐使用单引号保持风格一致。

<!-- @[string_literal_types](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let single: string = 'Hello';
let double: string = "World";
let template: string = `ArkTS`;
```

单引号是最常用形式，双引号与单引号功能完全相同（推荐单引号），双引号主要用于JSON数据或包含单引号的字符串；模板字符串（反引号）支持插值和多行等更多功能。

### 多行字符串字面量

模板字符串（反引号）天然支持多行文本，无需使用转义字符，适合用于存储长文本（如邮件内容、HTML片段）、编写代码片段（如SQL查询）以及格式化报表与文档输出。

<!-- @[multiline_string](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let multiLine: string = `Line 1
Line 2
Line 3`;

let paragraph: string = `这是一段
跨越多行的
文本内容`;
```

反引号内的换行、缩进和空格都会被保留，格式与显示效果一致，便于阅读和维护。

### 字符串字面量的特殊字符

特殊字符需要使用转义符表示，包括换行符`\n`、制表符`\t`、引号等。

<!-- @[escape_characters](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let newline: string = 'Line1\nLine2';
let tab: string = 'Column1\tColumn2';
let quote: string = 'It\'s a test';
let backslash: string = 'Path: C:\\Users';
let mixed: string = 'Hello\n\tWorld';
```

### 模板字符串

模板字符串（反引号）能够保留原始格式（换行、空格），便于在字符串中嵌入多行代码并保持可读性。

<!-- @[template_string_escape](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
// 模板字符串保留换行和空格
let code: string = `
function hello() {
  console.info('Hello');
}
`;

// 转义反引号和 $
let escaped: string = `Price: \$100`;
let backtick: string = `Use \`backticks\``;
```

在模板字符串中，`${}`会触发插值表达式，需转义`$`或使用反引号包裹以避免意外插值；反引号需转义以避免提前终止字符串。

## 字符串的可变性

字符串是不可变的，所有修改操作都会返回新字符串。

### 声明可变字符串

使用`let`声明可以重新赋值的字符串变量，适用于动态构建内容、运行时更新状态、处理消息以及接收用户输入等场景。

<!-- @[string_reassignment](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let message: string = 'Hello';
message = 'Hello, World';  // 重新赋值

let text: string = '';
text += 'Part 1';
text += ' Part 2';
```

重新赋值和`+=`拼接都会创建新的字符串对象，字符串对象本身不可变。

### 声明不可变字符串

使用`const`声明字符串常量，确保字符串值不被重新赋值。适用于配置常量（如应用名称、版本号）、固定消息、API端点等不变信息。推荐使用大写命名（如`const APP_NAME`），集中定义并添加类型注解，便于管理。

<!-- @[ts_string_constant](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Strings.ts) -->

``` TypeScript
const APP_NAME: string = 'MyApp';
const VERSION: string = '1.0.0';

APP_NAME = 'NewApp';  // 编译错误：不能重新赋值
```

### 字符串不可变性

字符串创建后不能被修改，所有操作都会返回新字符串，这是字符串的核心特性。

<!-- @[ts_string_immutability](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Strings.ts) -->

``` TypeScript
let original: string = 'Hello';

// 方法返回新字符串
let modified: string = original.toUpperCase();
console.info(`${original}`);  // "Hello"（原字符串不变）
console.info(`${modified}`);  // "HELLO"

// 不能直接修改字符串内容
original[0] = 'J';  // 无效操作
```

## 字符

ArkTS没有独立的字符类型，单字符使用string表示。

### 遍历字符串中的字符

可以通过索引或for-of循环逐个访问字符串中的每个字符。

<!-- @[string_iteration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let iterText: string = 'Hello';

// 使用for...of遍历字符
for (let char of iterText) {
  console.info(`${char}`);
}

// 使用for循环遍历
for (let i: number = 0; i < iterText.length; i++) {
  let char: string = iterText[i];
  console.info(`${char}`);
}

// 使用split转换为数组
let chars: string[] = iterText.split('');
for (let char of chars) {
  console.info(`${char}`);
}
```

### 单个字符的表示与使用

字符可以使用Unicode转义或直接使用单字符字符串表示。

<!-- @[character_access](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let accessText: string = 'Hello';

// 获取单个字符
let firstChar: string = accessText.charAt(0);   // 'H'
let secondChar: string = accessText.charAt(1);   // 'e'

// 字符编码
let accessCode: number = accessText.charCodeAt(0);     // 72（'H' 的Unicode）
let codePoint: number = accessText.codePointAt(0) ?? 0; // 72

// 从编码创建字符
let charFromCode: string = String.fromCharCode(72);  // 'H'
```

## 字符串拼接

字符串拼接通过+运算符或模板字面量（`...${}...`）实现。

### 字符串与字符串拼接

字符串可以使用+运算符或拼接方法组合成新字符串。

<!-- @[string_concatenation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let firstName: string = 'John';
let lastName: string = 'Doe';

// 使用 + 运算符
let fullName: string = firstName + ' ' + lastName;  // "John Doe"

// 使用concat方法
let combined: string = firstName.concat(' ', lastName);  // "John Doe"

// 使用join方法
let parts: string[] = [firstName, lastName];
let joined: string = parts.join(' ');  // "John Doe"
```

### 字符串与字符拼接

字符串和字符拼接时，字符会被自动转换为字符串形式。

<!-- @[string_append](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let appendText: string = 'Hello';
let char: string = '!';

let result: string = appendText + char;  // "Hello!"

// 多字符拼接
let appendChars: string[] = ['a', 'b', 'c'];
let combinedChars: string = appendChars.join('');  // "abc"
```

### 拼接赋值操作

拼接赋值运算符+=将右侧字符串追加到左侧变量，简化拼接代码。

<!-- @[compound_assignment_concat](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let compoundMessage: string = '';

// 使用 += 赋值拼接
compoundMessage += 'Hello';
compoundMessage += ' ';
compoundMessage += 'World';
console.info(`${compoundMessage}`);  // "Hello World"

// 使用复合赋值
let compoundText: string = 'Part 1';
compoundText += ' Part 2';  // "Part 1 Part 2"
```

## 字符串插值

模板字符串使用`${}`插入变量和表达式。

### 基本插值用法

模板字符串使用${}嵌入表达式，表达式结果自动转换为字符串。

<!-- @[template_interpolation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let name: string = 'Alice';
let age: number = 25;

// 变量插值
let interpMessage: string = `Hello, ${name}`;
console.info(`${interpMessage}`);  // "Hello, Alice"

// 表达式插值
let info: string = `Name: ${name}, Age: ${age}`;
let nextAge: string = `Next year: ${age + 1}`;

// 对象属性插值
interface User {
  name: string;
  email: string;
}

let user: User = { name: 'Bob', email: 'bob@example.com' };
let profile: string = `User: ${user.name} (${user.email})`;
```

### 插值表达式的限制

插值表达式必须是有效的表达式，不能包含未转义的反引号或$符号。

<!-- @[ts_template_expressions](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Strings.ts) -->

``` TypeScript
// 支持的表达式类型
let a: number = 10;
let b: number = 20;

let arithmetic: string = `${a + b}`;         // "30"
let comparison: string = `${a > b}`;         // "false"
let logical: string = `${a > 0 && b > 0}`;   // "true"
let functionCall: string = `${Math.max(a, b)}`; // "20"

// 支持三元运算符
let result: string = `${a > b ? 'greater' : 'less'}`;  // "less"

// 不支持复杂语句
let invalid: string = `${if (a > b) { 'yes' }}`;  // 编译错误

// 嵌套模板字符串
let outer: string = `Outer: ${`Inner: ${a}`}`;  // "Outer: Inner: 10"
```

## 字符串的Unicode表示

Unicode编码表示国际化字符，支持多种编码形式。

### Unicode标量值

Unicode标量值是有效的Unicode编码点范围，排除代理项代码点。

<!-- @[unicode_representation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
// Unicode字符表示
let unicode1: string = 'A';               // 直接字符
let unicode2: string = '\u0041';          // Unicode转义（'A'）
let unicode3: string = '\x41';            // ASCII转义（'A'）

// Unicode码点
let emoji: string = '\u{1F600}';          // 😀（emoji）
let chinese: string = '\u{4E2D}';         // 中

// 获取字符的Unicode码点
let unicodeReprCodePoint: number = 'A'.codePointAt(0) ?? 0;  // 65
let emojiCode: number = '😀'.codePointAt(0) ?? 0; // 128512

// 从码点创建字符
let fromCode: string = String.fromCodePoint(65);      // 'A'
let fromEmoji: string = String.fromCodePoint(128512); // '😀'
```

### 不同Unicode表示形式的转换

在字符串、Unicode码点数组和Unicode转义序列三种表示形式之间相互转换，使用codePointAt和fromCodePoint方法。

<!-- @[unicode_codepoint_conversion](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let unicodeText: string = 'Hello';

// 字符串转为Unicode码点数组
let codePoints: number[] = [];
for (let char of unicodeText) {
  codePoints.push(char.codePointAt(0) ?? 0);
}
console.info(`${codePoints.join(', ')}`);  // 72, 101, 108, 108, 111

// Unicode码点转为字符串
let reconstructed: string = '';
for (let code of codePoints) {
  reconstructed += String.fromCodePoint(code);
}
console.info(`${reconstructed}`);  // "Hello"

// Unicode转义形式
let unicodeEscaped: string = '';
for (let char of unicodeText) {
  let code: number = char.codePointAt(0) ?? 0;
  unicodeEscaped += `\\u${code.toString(16).padStart(4, '0')}`;
}
console.info(`${unicodeEscaped}`);  // "\u0048\u0065\u006c\u006c\u006f"
```

## 字符串长度

字符串length属性返回UTF-16代码单元数量，注意代理项对的影响。

### 计算字符串的长度

字符串length属性返回UTF-16代码单元数量，代理项对占两个单元。

<!-- @[string_length](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let lengthText: string = 'Hello';
let length: number = lengthText.length;  // 5

let empty: string = '';
let emptyLength: number = empty.length;  // 0

let space: string = '   ';
let spaceLength: number = space.length;  // 3

// 多行字符串长度包含换行符
let lengthMultiLine: string = `Line1
Line2`;
let multiLength: number = lengthMultiLine.length;  // 11（含 \n）
```

### 长度计算的注意事项

计算包含复杂Unicode字符的字符串长度时，需考虑代理项对的影响。

<!-- @[multibyte_length](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
// 普通ASCII字符
let ascii: string = 'Hello';
console.info(`${ascii.length.toString()}`);  // 5

// 中文字符（每个字符长度为1）
let multibyteChinese: string = '你好世界';
console.info(`${multibyteChinese.length.toString()}`);  // 4

// Emoji字符（部分multibyteEmoji长度可能为2）
let multibyteEmoji: string = '😀';
console.info(`${multibyteEmoji.length.toString()}`);  // 2（surrogate pair）

// 组合字符
let multibyteCombined: string = 'é';  // e + combining accent
console.info(`${multibyteCombined.length.toString()}`);  // 可能为2

// 正确统计字符数（使用迭代）
function countCharacters(text: string): number {
  let count: number = 0;
  for (let char of text) {
    count++;
  }
  return count;
}

console.info(`${countCharacters('😀').toString()}`);  // 1（正确统计）
```

## 字符串索引

字符串可通过索引或`charAt`访问指定位置字符，`indexOf`/`lastIndexOf`定位子串位置。

### 访问字符串的单个字符

charAt和索引访问获取单个字符，charCodeAt获取字符编码。

<!-- @[string_indexing](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let indexText: string = 'Hello World';

// 索引访问
let first: string = indexText[0];           // 'H'
let fifth: string = indexText[4];           // 'o'
let last: string = indexText[indexText.length - 1];  // 'd'

// charAt方法
let second: string = indexText.charAt(1);   // 'e'

// 越界访问
let outOfBounds: string | undefined = indexText[100];  // undefined
let outOfBounds2: string = indexText.charAt(100);      // ''（空字符串）
```

### 索引的获取与偏移

indexOf查找子字符串位置，lastIndexOf从后向前查找。

<!-- @[string_search](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let searchText: string = 'Hello World';

// 查找字符位置
let indexOfO: number = searchText.indexOf('o');      // 4
let indexOfWorld: number = searchText.indexOf('World'); // 6
let lastIndexOfO: number = searchText.lastIndexOf('o'); // 7

// 从指定位置开始查找
let indexOfO2: number = searchText.indexOf('o', 5);   // 7（从索引5开始）

// 查找不存在
let notFound: number = searchText.indexOf('xyz');    // -1

// 索引偏移计算
let nextIndex: number = indexOfO + 1;          // 5
let prevIndex: number = indexOfO - 1;          // 3
```

## 子字符串

子字符串操作提取、查找、替换文本片段。

### 获取子字符串

substring和slice方法提取字符串片段，split分割为数组。**两者的关键区别**：`substring`会自动调整参数顺序（如`substring(5, 0)`等价于`substring(0, 5)`），负数参数被视为0；`slice`不调整参数顺序，支持负索引（从末尾开始计数）。

<!-- @[substring_extraction](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let extractText: string = 'Hello World';

// substring方法
let sub1: string = extractText.substring(0, 5);    // "Hello"
let sub2: string = extractText.substring(6);       // "World"
let sub3: string = extractText.substring(6, 11);   // "World"

// slice方法
let slice1: string = extractText.slice(0, 5);      // "Hello"
let slice2: string = extractText.slice(-5);        // "World"（负索引）
let slice3: string = extractText.slice(6, -1);     // "Worl"

// substring vs slice
// substring自动调整参数顺序，负数视为0；slice不调整参数顺序，支持负索引
let subNeg: string = extractText.substring(-2, 3);  // "Hel"（-2被视为0）
let reversed: string = extractText.substring(5, 0);  // "Hello"（自动调整）
let reversedSlice: string = extractText.slice(5, 0);  // ""（不调整）
```

### 子字符串的生命周期与转换

子字符串是新字符串，与原字符串独立存在，修改子字符串不影响原字符串。

<!-- @[substring_operations](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let original: string = 'Hello World';

// 子字符串是新字符串，独立存在
let sub: string = original.substring(0, 5);
sub = sub.toUpperCase();  // 修改子字符串不影响原字符串
console.info(`${original}`);  // "Hello World"

// 子字符串转数组
let substrParts: string[] = sub.split('');
console.info(`[${substrParts.join(', ')}]`);  // H, e, l, l, o

// 子字符串拼接
let newString: string = sub + ' ArkTS';  // "Hello ArkTS"

// 子字符串替换
let replaced: string = original.replace(sub, 'Hi');  // "Hi World"
```

## 字符串比较

字符串比较判断相等性和排序关系，支持本地化比较。

### 字符串等值比较

使用===比较字符串的值和类型，避免==的隐式转换。

<!-- @[string_comparison](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let str1: string = 'Hello';
let str2: string = 'Hello';
let str3: string = 'World';

// 严格相等比较
console.info(`${str1 === str2}`);  // true
console.info(`${str1 === str3}`);  // false
console.info(`${str1 !== str3}`);  // true

// 大小写敏感比较
let upper: string = 'HELLO';
console.info(`${str1 === upper}`);  // false（大小写不同）

// 忽略大小写比较
let equalIgnoreCase: boolean = 
  str1.toLowerCase() === upper.toLowerCase();  // true
```

### 前缀比较

startsWith方法检查字符串是否以指定文本开头，用于格式验证。

<!-- @[starts_with_check](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let startsWithText: string = 'Hello World';

// startsWith方法
let startsWithHello: boolean = startsWithText.startsWith('Hello');  // true
let startsWithWorld: boolean = startsWithText.startsWith('World');  // false

// 从指定位置开始检查
let startsWithWorld2: boolean = startsWithText.startsWith('World', 6);  // true

// 手动前缀检查
function hasPrefix(text: string, prefix: string): boolean {
  return text.indexOf(prefix) === 0;
}
```

### 后缀比较

endsWith()判断字符串是否以指定子串结尾。

<!-- @[ends_with_check](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let endsWithText: string = 'Hello World';

// endsWith方法
let endsWithWorld: boolean = endsWithText.endsWith('World');  // true
let endsWithHello: boolean = endsWithText.endsWith('Hello');  // false

// 检查指定长度内的后缀
let endsWithOrld: boolean = endsWithText.endsWith('orld', 11);  // true

// 手动后缀检查
function hasSuffix(text: string, suffix: string): boolean {
  let startPos: number = text.length - suffix.length;
  return startPos >= 0 && text.indexOf(suffix, startPos) === startPos;
}
```

## 字符串的大小写转换

通过toUpperCase()和toLowerCase()转换字符串大小写。注意：通过索引访问字符串（如`text[0]`）返回的是`string`类型，可直接调用字符串方法。

### 转换为全大写

toUpperCase方法将字符串所有字符转换为大写形式。

<!-- @[to_uppercase](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let upperText: string = 'Hello World';

let upperUpper: string = upperText.toUpperCase();  // "HELLO WORLD"

// 部分大写
let firstUpper: string = upperText[0].toUpperCase() + upperText.substring(1);  // "Hello World"

// 每个单词首字母大写
function capitalizeWords(upperText: string): string {
  let words: string[] = upperText.split(' ');
  let capitalized: string[] = words.map((word: string): string => {
    return word[0].toUpperCase() + word.substring(1).toLowerCase();
  });
  return capitalized.join(' ');
}

let upperResult: string = capitalizeWords('hello world');  // "Hello World"
```

### 转换为全小写

toLowerCase()将字符串中的大写字母转换为小写。

<!-- @[to_lowercase](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let lowerText: string = 'Hello World';

let lower: string = lowerText.toLowerCase();  // "hello world"

// 部分小写
let lowerMixed: string = lowerText[0] + lowerText.substring(1).toLowerCase();  // "Hello world"

// 判断是否为小写
function isLowerCase(lowerText: string): boolean {
  return lowerText === lowerText.toLowerCase();
}

console.info(`${isLowerCase('hello')}`);  // true
console.info(`${isLowerCase('Hello')}`);  // false
```

## 字符串常用方法

字符串方法包括查找、截取、替换和分割等操作。

### 查找方法

查找方法用于定位子字符串或字符在字符串中的位置。

<!-- @[string_search_methods](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let searchText2: string = 'Hello World';

// indexOf：查找位置
let pos: number = searchText2.indexOf('World');      // 6
let lastPos: number = searchText2.lastIndexOf('o');  // 7

// includes：是否包含
let hasWorld: boolean = searchText2.includes('World'); // true

// startsWith：是否以指定字符串开头
let startsHello: boolean = searchText2.startsWith('Hello'); // true

// endsWith：是否以指定字符串结尾
let endsWorld: boolean = searchText2.endsWith('World'); // true
```

### 提取方法

提取方法用于从字符串中获取指定范围的子字符串。

<!-- @[string_slice_split](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let sliceText: string = 'Hello World';

// slice：截取
let slice: string = sliceText.slice(0, 5);        // "Hello"

// substring：截取
let substring: string = sliceText.substring(7);    // "World"

// split：分割为数组
let split: string[] = sliceText.split(' ');
console.info(`[${split.join(', ')}]`);  // Hello, World
let splitAll: string[] = sliceText.split('');
console.info(`[${splitAll.join(', ')}]`);  // H, e, l, l, o,  , W, o, r, l, d
```

### 修改方法

修改方法用于改变字符串内容，如替换、切割、拼接等。

<!-- @[string_common_methods](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let commonMethodsText: string = 'Hello World';

// replace：替换
let commonMethodsReplaced: string = commonMethodsText.replace('World', 'ArkTS');  // "Hello ArkTS"

// replaceAll：替换所有（ES2021，ArkTS支持）
let multiple: string = 'aa bb aa';
let allReplaced: string = multiple.replaceAll('aa', 'xx');  // "xx bb xx"

// trim：去除首尾空格
let trimmed: string = '  Hello ArkTS  '.trim();  // "Hello ArkTS"

// trimStart：去除开头空格
let trimStart: string = '  Hello ArkTS  '.trimStart();  // "Hello ArkTS  "

// trimEnd：去除结尾空格
let trimEnd: string = '  Hello ArkTS  '.trimEnd();  // "  Hello ArkTS"

// padStart：左侧填充
let padded: string = '5'.padStart(3, '0');  // "005"

// padEnd：右侧填充
let paddedEnd: string = '5'.padEnd(3, '0'); // "500"

// repeat：重复
let repeated: string = 'ab'.repeat(3);      // "ababab"
```

### 其他方法

字符串还提供charAt、charCodeAt、concat、localeCompare、toString、valueOf等实用方法。

<!-- @[string_utility_methods](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let utilityText: string = 'Hello';

// charAt：获取指定位置字符
let utilityChar: string = utilityText.charAt(0);  // 'H'

// charCodeAt：获取字符编码
let utilityCode: number = utilityText.charCodeAt(0);  // 72

// concat：连接字符串
let concatenated: string = 'Hello'.concat(' ', 'World');  // "Hello World"

// localeCompare：本地化比较
let comparison: number = 'a'.localeCompare('b');  // -1（a < b）

// toString：转为字符串
let numStr: string = (42).toString();  // "42"
let boolStr: string = (true).toString();  // "true"

// valueOf：获取原始值
let value: string = 'test'.valueOf();  // "test"
```

## 字符串与正则表达式

正则表达式用于字符串的匹配、查找和替换，通过RegExp对象创建。

<!-- @[string_regex](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
// match：匹配正则
let regexText: string = 'The quick brown fox';
let matches: RegExpMatchArray | null = regexText.match(/quick/);

// search：查找匹配位置
let regexPos: number = regexText.search(/brown/);  // 10

// replace：正则替换
let regexReplaced: string = regexText.replace(/fox/, 'cat');  // "The quick brown cat"

// split：正则分割
let regexParts: string[] = 'a1b2c3'.split(/\d/);
console.info(`[${regexParts.join(', ')}]`);  // a, b, c, 

// matchAll：全局匹配（ES2020，ArkTS支持）
let allMatches: IterableIterator<RegExpMatchArray> = regexText.matchAll(/\w+/g);
```

## Unicode字符处理

字符串中的字符可能由多个UTF-16编码单元组成（如emoji），使用`codePointAt`和`fromCodePoint`处理完整Unicode码点。

<!-- @[unicode_handling](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let unicodeEmoji: string = '🎉';
let unicodeCode: number | undefined = unicodeEmoji.codePointAt(0);
if (unicodeCode !== undefined) {
  console.info(`${unicodeCode.toString()}`);  // 129395
}

let unicodeChar: string = String.fromCodePoint(128516);
console.info(`${unicodeChar}`);  // 😄

// 按Unicode码点遍历（而非UTF-16编码单元）
let unicodeText2: string = 'a🎉b';
for (let uc of unicodeText2) {
  console.info(`${uc}`);  // 依次输出: a, 🎉, b
}
```

## 字符串填充与重复

`padStart`和`padEnd`用于在字符串开头或末尾填充到指定长度，`repeat`用于重复字符串。

<!-- @[string_pad_repeat](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
// padStart：在开头填充
let prS1: string = '5'.padStart(3, '0');
console.info(`${prS1}`);  // 005

let prS2: string = 'hi'.padStart(5, '-');
console.info(`${prS2}`);  // ---hi

// padEnd：在末尾填充
let prS3: string = 'hi'.padEnd(5, '-');
console.info(`${prS3}`);  // hi---

// repeat：重复字符串
let prS4: string = 'ab'.repeat(3);
console.info(`${prS4}`);  // ababab
```

## at方法与负索引访问

`at`方法支持负索引访问字符串字符，比方括号`[]`更灵活。

**TypeScript对照**

<!-- @[ts_string_at](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Strings.ts) -->

``` TypeScript
// TypeScript对照写法（ES2022），ArkTS中用charAt替代
let tsAtWord: string = 'hello';
console.info(`${tsAtWord.at(0)}`);   // 'h'
console.info(`${tsAtWord.at(-1)}`);  // 'o'（最后一个字符）
```

ArkTS不支持`at`方法，使用`charAt`和手动计算替代。

<!-- @[at_method_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let atWord: string = 'hello';
console.info(`${atWord.charAt(0)}`);              // h
console.info(`${atWord.charAt(atWord.length - 1)}`);  // o
console.info(`${atWord.charAt(10)}`);             // （空字符串，越界）
```

## 模板字面量类型

模板字面量类型在TypeScript中用于在类型层面拼接字符串字面量。ArkTS不支持此特性。

**TypeScript对照**

<!-- @[ts_template_literal_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Strings.ts) -->

``` TypeScript
// TypeScript对照写法，ArkTS中不支持
type TltWorld = 'world';
type TltGreeting = `hello ${TltWorld}`;  // 'hello world'

// 联合展开
type TltLocale = `${'en' | 'ja'}_${'welcome' | 'bye'}`;
// 'en_welcome' | 'en_bye' | 'ja_welcome' | 'ja_bye'

// 内置字符串操作类型
type TltUpper = Uppercase<'hello'>;      // 'HELLO'
type TltLower = Lowercase<'HELLO'>;      // 'hello'
type TltCap = Capitalize<'hello'>;       // 'Hello'
type TltUncap = Uncapitalize<'Hello'>;   // 'hello'
```

ArkTS不支持模板字面量类型，使用普通字符串常量、枚举或联合类型替代，通过运行时字符串拼接实现动态字符串。

<!-- @[template_literal_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
enum TltEventType {
  Click = 'click',
  Hover = 'hover',
  Focus = 'focus'
}

function tltHandleEvent(type: TltEventType, callback: () => void): void {
  console.info(`Handling ${type}`);
  callback();
}

tltHandleEvent(TltEventType.Click, (): void => {
  console.info('Clicked!');
});
```
