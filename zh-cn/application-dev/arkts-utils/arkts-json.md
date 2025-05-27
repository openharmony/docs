# JSON扩展库

该库扩展了原生JSON功能，提供了额外的错误处理、循环引用检测、BigInt处理以及对不同输入类型的严格检查。代码中底层依赖于原生JSON.parse和JSON.stringify，但在此基础上加入了多种自定义逻辑并提供额外的has和remove接口，具体可见[@arkts.json](../reference/apis-arkts/js-apis-json.md)。

## parse

parse(text: string, reviver?: Transformer, options?: ParseOptions): Object | null

解析JSON字符串，支持BigInt模式。

**与原生的区别：**

| 特性	| 原生parse	 | 本库parse |
| -------- | -------- | -------- |
| BigInt支持	| 不支持（抛出TypeError） |支持（通过parseBigInt扩展）|
| 参数校验	| 弱校验 |强校验（抛出BusinessError） |
| 错误信息	| 原生错误（如SyntaxError） |	自定义BusinessError |
| reviver参数	| 支持 | 支持，但强制类型检查 |

## stringify

stringify(value: Object, replacer?: (number | string)[] | null, space?: string | number): string

将对象转换为JSON字符串，支持BigInt模式。

**与原生的区别：**

| 特性	| 原生stringify | 本库stringify |
| -------- | -------- | -------- |
| BigInt支持 | 不支持（抛出TypeError）| 支持（通过stringifyBigInt扩展） |
| 循环引用检测 | 抛出TypeError | 检测并抛出BusinessError |
| 参数校验 | 弱校验	| 强校验（replacer 必须是函数或数组） |
| 错误信息 | 原生错误	| 自定义BusinessError |

## has

has(obj: object, property: string): boolean

检查对象是否包含指定的属性，确保传入的值是一个对象，并且属性键是有效的字符串。

**与原生的区别：**

| 特性| 原生方式（obj.hasOwnProperty） | 本库has |
| -------- | -------- | -------- |
| 参数校验 | 无校验（可能误用） | 强制检查obj是普通对象，property是非空字符串 |
| 错误处理 | 可能静默失败 | 抛出BusinessError |

## remove

remove(obj: object, property: string): void

从对象中删除指定的属性。

| 特性 | 原生方式（delete obj.key） | 本库remove |
| -------- | -------- | -------- | 
| 参数校验 | 无校验（可能误删） | 强制检查obj是普通对象，property是非空字符串 |
| 错误处理 | 可能静默失败 | 抛出BusinessError |

**总结：**

| 功能 | 原生JSON | 本库 |
| ----- | ----- | -----| 
| 严格参数校验 | 不支持 |	支持 |
| 循环引用检测 | 不支持 |	支持 |
| BigInt处理 | 不支持 |	支持 |
| 增强的错误处理（BusinessError） | 不支持 | 支持 |
| 额外方法（has/remove） | 不支持 | 支持 |

**适用场景：**

- 需要处理BigInt的JSON解析或序列化。

- 需要更严格的参数校验和错误处理。

- 需要检测循环引用。

- 需要安全的对象操作（has/remove）。

该库适用于需要增强JSON功能的场景，特别是在处理BigInt和严格的参数校验时。