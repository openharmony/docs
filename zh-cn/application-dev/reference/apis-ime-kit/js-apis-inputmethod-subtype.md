# @ohos.InputMethodSubtype (输入法子类型)
<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @codexu62-->
<!--Designer: @andeszhang-->
<!--Tester: @murphy84-->
<!--Adviser: @zhang_yixin13-->

@ohos.InputMethodSubtype模块提供输入法子类型的属性数据定义，支持描述输入法在不同语言或模式下的子类型信息。

本模块是输入法框架的子类型数据模块，定义了`InputMethodSubtype`接口，用于描述输入法的一种具体输入模式或语言——如中文键盘、英文键盘、大写模式键盘等，每个子类型代表输入法在特定语言或模式下的形态。

本模块提供输入法子类型的属性描述能力。通过`InputMethodSubtype`可获取子类型的标识（`id`、`name`）、语言和区域（`locale`、`language`）、显示标签（`label`）、模式（`mode`：大写/小写）、图标等属性，用于输入法子类型的识别、展示和切换。

当需要查询、展示或切换输入法的不同语言/模式子类型时使用本模块。典型场景包括：系统设置应用展示输入法子类型列表供用户选择、输入法应用根据子类型信息切换语言或模式、应用获取当前输入法子类型信息等。

> **说明：**
>
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

`InputMethodSubtype`是纯数据定义模块，其对象由系统框架创建和返回，开发者不可自行构造。典型跨模块使用流程：

1. 编辑框应用侧（`@ohos.inputMethod`模块）：通过`InputMethodSetting.listInputMethodSubtype()`查询输入法子类型列表，通过`inputMethod.switchCurrentInputMethodSubtype()`切换到指定子类型。
2. 输入法应用侧（`@ohos.inputMethodEngine`模块）：通过`InputMethodAbility.on('setSubtype')`监听子类型切换事件，回调参数为`InputMethodSubtype`对象，据此调整键盘布局和语言。

本模块的核心开放能力由以下关键接口承载：

| Interface | 说明 |
|---|---|
| InputMethodSubtype | 输入法子类型属性接口，描述输入法的一种具体语言或模式形态。必填属性包括：`name`（所属应用包名）、`id`（子类型ID）、`locale`（区域）、`language`（语言）；可选属性包括：`label`（标签）、`labelId`（标签资源号）、`mode`（大写/小写模式）、`icon`（图标）、`iconId`（图标ID）、`extra`（额外信息）。 |

本模块为纯数据定义模块，`InputMethodSubtype`作为子类型描述数据需与其他模块的API组合使用。典型组合场景为：在`@ohos.inputMethod`模块中，通过`InputMethodSetting`查询和切换子类型；在`@ohos.inputMethodEngine`模块中，通过`InputMethodAbility`监听子类型切换事件。

```javascript
// 以下为阐述调用逻辑的伪代码

// 1. 查询输入法子类型列表（@ohos.inputMethod模块组合）
let setting = inputMethod.getSetting();
let subtypes = setting.listInputMethodSubtype(inputMethodProperty);

// 2. 切换到指定子类型
inputMethod.switchCurrentInputMethodSubtype(targetSubtype);

// 3. 输入法应用侧监听子类型切换（@ohos.inputMethodEngine模块组合）
// let ability = inputMethodEngine.getInputMethodAbility();
// ability.on('setSubtype', (subtype) => {
//   // subtype为InputMethodSubtype实例，根据其language/locale/mode调整键盘
//   let lang = subtype.language;   // 如 'zh' 或 'en'
//   let mode = subtype.mode;       // 如 'upper' 或 'lower'
// });
```

> **说明：**
>
> `InputMethodSubtype`对象由系统框架创建和返回，开发者通过其他模块的查询接口获取，不可自行构造。

## 导入模块

```ts
import { InputMethodSubtype } from '@kit.IMEKit';
```

## InputMethodSubtype

输入法子类型属性。用于描述输入法的一种具体语言或模式形态，每个子类型代表输入法在特定语言或模式下的形态（如中文键盘、英文键盘、大写模式键盘等）。`InputMethodSubtype`对象由系统框架创建和返回，开发者不可自行构造。

- 含义/功能：描述输入法子类型的标识、语言、区域、模式等属性信息。必填属性（`name`、`id`、`locale`、`language`）用于唯一标识和描述子类型的基本特征；可选属性（`label`、`mode`、`icon`等）提供额外的展示和功能信息。
- 使用场景：当需要查询、展示或切换输入法的不同语言/模式子类型时使用。例如：系统设置应用展示输入法子类型列表供用户选择、输入法应用根据子类型信息切换语言或模式、应用获取当前输入法子类型信息等。
- 使用后效果：获取到`InputMethodSubtype`对象后，可读取其属性值用于子类型识别、列表展示、语言/模式切换等操作。`InputMethodSubtype`对象本身为只读数据，不支持修改。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| label | string | 是 | 是 | 输入法子类型的标签。用于在UI界面展示子类型的名称，如"中文（简体）"、"English"等。 |
| labelId<sup>10+</sup> | number | 是 | 是 | 输入法子类型的标签资源号。用于通过资源ID加载标签文本，支持多语言场景下的标签国际化显示。 |
| name | string | 是 | 否 | 输入法子类型所属应用的包名。与输入法应用在module.json5中配置的bundleName保持一致，用于标识该子类型属于哪个输入法应用。 |
| id | string | 是 | 否 | 输入法子类型的id。与输入法应用在module.json5中配置的subtype id保持一致，用于在同输入法应用内唯一标识一个子类型。 |
| mode | 'upper' \| 'lower' | 是 | 是 | 输入法子类型的模式，包括upper（大写）和lower（小写）。用于描述键盘的大小写状态模式。 |
| locale | string | 是 | 否 | 输入法子类型的区域。遵循ICU Locale格式，如'zh-CN'表示中文（简体，中国）、'en-US'表示英文（美国）。用于标识子类型的语言和地区。 |
| language | string | 是 | 否 | 输入法子类型的语言，如'zh'（中文）、'en'（英文）。用于标识子类型的语言，是locale的子集。 |
| icon | string | 是 | 是 | 输入法子类型的图标，可以通过iconId查询获取。 |
| iconId | number | 是 | 是 | 输入法子类型的图标id。用于通过资源ID加载子类型图标。 |
| extra | object | 否 | 是 | 输入法子类型的其他信息。<br/>说明：<br/>- 从API version 10开始为非必填参数。|

### 参数使用建议

name参数：
- 含义/功能：输入法子类型所属应用的包名，用于标识该子类型属于哪个输入法应用。
- 取值范围：与输入法应用在module.json5中配置的bundleName保持一致的字符串。
- 注意事项：name必须与输入法应用的bundleName严格一致（包括大小写），否则系统无法正确匹配子类型与输入法应用。开发者可通过查看输入法应用的module.json5配置文件获取正确的包名。

id参数：
- 含义/功能：输入法子类型的id，用于在同一输入法应用内唯一标识一个子类型。
- 取值范围：与输入法应用在module.json5中配置的subtype id保持一致的字符串。
- 相关参数间的配合/制约关系：`name`和`id`共同唯一标识一个输入法子类型。`name`标识所属输入法应用，`id`标识该应用内的具体子类型。切换子类型时（如通过`switchCurrentInputMethodSubtype`），需同时提供`name`和`id`匹配的`InputMethodSubtype`对象。

locale参数：
- 含义/功能：输入法子类型的区域标识，遵循ICU Locale格式。
- 取值范围：ICU Locale格式的字符串，常见格式为'语言代码-国家代码'，如'zh-CN'、'en-US'、'ja-JP'等。语言代码遵循ISO 639标准（两字母小写代码），国家代码遵循ISO 3166标准（两字母大写代码）。
- 格式样例：'zh-CN'（中文简体，中国）、'en-US'（英文，美国）、'zh-TW'（中文繁体，台湾）、'ja-JP'（日文，日本）。

language参数：
- 含义/功能：输入法子类型的语言标识，是locale的语言代码部分。
- 取值范围：ISO 639标准的语言代码字符串，如'zh'（中文）、'en'（英文）、'ja'（日文）等。
- 相关参数间的配合/制约关系：`language`与`locale`存在关联——`language`是`locale`的语言代码部分。例如locale为'zh-CN'时，language通常为'zh'。两者应保持一致，language不应与locale中的语言代码矛盾。

mode参数：
- 含义/功能：输入法子类型的模式，描述键盘的大小写状态。
- 使用场景：可选参数。不填写时，输入法应用使用默认模式。当需要指定键盘的大写或小写模式时填写，如密码输入场景下指定'lower'模式。
- 使用后效果：设置'upper'时，输入法应用据此将键盘切换为大写模式；设置'lower'时切换为小写模式。
- 取值范围：'upper'（大写）或'lower'（小写）。

label参数：
- 含义/功能：输入法子类型的标签，用于在UI界面展示子类型名称。
- 使用场景：可选参数。不填写时，系统可能使用子类型的language或locale作为默认显示名称。当需要在设置页面或切换列表中展示更具可读性的子类型名称时填写。
- 相关参数间的配合/制约关系：`label`与`labelId`存在关联——两者均用于子类型的标签显示。`label`为直接的文本标签，`labelId`为资源ID标签，支持多语言国际化。如果同时设置，优先使用`labelId`加载的国际化文本。

labelId参数：
- 含义/功能：输入法子类型的标签资源号，用于通过资源ID加载标签文本。
- 使用场景：可选参数。当需要支持多语言场景下子类型标签的国际化显示时使用，比`label`更适合多语言环境。
- 取值范围：number类型的资源ID值。

icon和iconId参数：
- 规格限制：当前不可通过这两个参数获取或显示子类型图标。

extra参数：
- 规格限制：从API version 10开始为非必填参数。
