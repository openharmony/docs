# @ohos.inputMethod.ExtraConfig (输入法扩展信息)
<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @codexu62-->
<!--Designer: @andeszhang-->
<!--Tester: @murphy1984-->
<!--Adviser: @zhang_yixin13-->

@ohos.inputMethod.ExtraConfig模块提供输入法扩展信息的数据定义，支持ArkUI编辑框在拉起输入法时传递自定义配置信息给输入法应用。

本模块是输入法框架的扩展信息数据模块，定义了`InputMethodExtraConfig`接口和`CustomValueType`联合类型，用于承载编辑框应用向输入法应用传递的自定义键值对配置数据。

本模块提供编辑框应用向输入法应用传递个性化配置的能力。编辑框应用可将用户的输入习惯、快捷键设置、主题颜色、输入模式偏好等自定义信息以键值对形式封装，在绑定输入法时一并传递给输入法应用，使输入法应用据此提供个性化体验。信息总长度不超过32KB。

当编辑框应用需要向输入法应用传递额外的配置信息以定制输入行为时使用本模块。典型场景包括：聊天应用希望输入法默认展示表情面板、搜索应用希望输入法使用特定输入模式、笔记应用希望配置输入法的快捷键行为等。

> **说明：**
>
>本模块首批接口从API version 22开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


本模块定义了输入法扩展信息的数据结构，用于编辑框应用向输入法应用传递自定义配置。`InputMethodExtraConfig`作为数据类型需与`@ohos.inputMethod`模块的API组合使用——在`InputMethodController.attach()`方法中，通过`TextConfig`的`extraConfig`属性将扩展信息传递给输入法应用。输入法应用侧通过`@ohos.inputMethodEngine`模块的`InputClient`获取并处理这些扩展信息，据此调整输入行为（如切换输入模式、更改主题等），实现编辑框应用与输入法应用之间的个性化配置协同。

典型使用流程：编辑框应用构造`InputMethodExtraConfig` → 注入`TextConfig.extraConfig` → 通过`attach()`传递 → 输入法应用通过`InputClient`接收 → 输入法应用据此调整行为。

本模块定义了以下关键Interface和数据类型：

| Interface/类型 | 说明 |
|---|---|
| InputMethodExtraConfig | 输入法扩展信息接口，包含`customSettings`属性，用于储存自定义键值对。这些键值对可以是任何与输入法相关的配置信息（如用户输入习惯、快捷键设置、主题颜色等），将在输入法应用绑定时加载，以提供个性化用户体验。信息总长度不超过32KB。 |
| CustomValueType | 扩展信息值的联合类型，支持`number`、`string`、`boolean`三种值类型，接口参数具体类型根据其功能而定。 |

本模块为纯数据定义模块，`InputMethodExtraConfig`作为数据类型需与其他模块的API组合使用。典型组合为：在`@ohos.inputMethod`模块的`InputMethodController.attach()`方法中，通过`TextConfig`将`InputMethodExtraConfig`传递给输入法应用。

```javascript
// 以下为阐述调用逻辑的伪代码

// 1. 构造输入法扩展信息
let extraConfig = {
  customSettings: {
    'inputMode': 'chat',
    'showEmojiPanel': true,
    'themeColor': 'dark',
    'autoCapitalize': false
  }
};

// 2. 将扩展信息注入TextConfig
let textConfig = {
  inputAttribute: { textInputType: 0, enterKeyType: 0 },
  cursorInfo: { left: 100, top: 200, width: 2, height: 20 },
  extraConfig: extraConfig
};

// 3. 绑定输入法时传递扩展信息
let controller = inputMethod.getController();
controller.attach(true, textConfig);
```

## 导入模块

```ts
import { InputMethodExtraConfig, CustomValueType } from '@kit.IMEKit';
```

## CustomValueType<sup>22+</sup> 

type CustomValueType = number | string | boolean

表示扩展信息值的类型，接口参数具体类型根据其功能而定。开发者可根据配置项的含义选择合适的值类型：数值型配置（如字号大小、权重系数等）使用number；文本型配置（如输入模式名称、主题标识等）使用string；开关型配置（如是否启用某功能、是否展示某面板等）使用boolean。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 类型    | 说明                 |
| ------- | -------------------- |
| number  | 表示值类型为数字。   |
| string  | 表示值类型为字符串。 |
| boolean | 表示值类型为布尔值。 |

## InputMethodExtraConfig

输入法扩展信息。用于编辑框应用向输入法应用传递自定义键值对配置数据，实现编辑框应用对输入法行为的个性化定制。

- 含义/功能：定义编辑框应用传递给输入法应用的自定义配置键值对，以`Record<string, CustomValueType>`形式存储。键（key）为配置项名称，值（value）为配置项内容，值类型支持number、string、boolean三种。
- 使用场景：当编辑框应用需要向输入法应用传递额外的个性化配置信息以定制输入行为时使用。例如：聊天应用希望输入法默认展示表情面板、搜索应用希望输入法使用特定输入模式、笔记应用希望配置输入法的快捷键行为等。
- 使用后效果：设置的扩展信息将在输入法应用与编辑框绑定时加载并传递给输入法应用，输入法应用可据此调整输入行为，提供个性化用户体验。若未设置扩展信息，输入法应用将使用默认配置。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 名称   |类型    |只读    |可选    |说明    |
|---------|----------|----------|--------|--------|
| customSettings<sup>22+</sup>  |Record&lt;string, [CustomValueType](#customvaluetype22)&gt;    | 否   | 否    |输入法扩展信息，用于储存自定义的键值对。这些键值对可以是任何与输入法相关的配置信息。例如用户的输入习惯、快捷键设置、主题颜色等。这些设置信息将在输入法应用绑定时加载，以提供个性化的用户体验。|

customSettings参数使用建议：

- 取值范围：键（key）为任意非空字符串；值（value）的类型为[CustomValueType](#customvaluetype22)，即number、string或boolean。同一个键只能对应一个值。
- 规格限制：信息的总长度不超过32KB。当总长度超过32KB时，超出部分的信息将不被传递。开发者可通过计算所有键值对的JSON序列化长度来判断是否超出限制。
- 生效机制：扩展信息在编辑框应用通过`@ohos.inputMethod`模块的`InputMethodController.attach()`绑定输入法时生效，随`TextConfig.extraConfig`属性一并传递给输入法应用。未调用`attach()`或`TextConfig`中未设置`extraConfig`时，扩展信息不会被传递。
- 注意事项：
  - 前提条件：需先构造`InputMethodExtraConfig`对象并注入`TextConfig.extraConfig`属性，再通过`InputMethodController.attach()`传递。
  - 开发建议：键名建议采用有意义的命名规范（如'inputMode'、'showEmojiPanel'），便于输入法应用解析和使用；避免使用过于简短或无意义的键名（如'a'、'x1'），以免降低可读性和可维护性。
  - 开发建议：键名应避免与输入法框架内部使用的键名冲突。建议使用应用专属前缀（如'com.example.chat.inputMode'）以防止命名冲突。
- 相关接口间的配合/制约关系：`customSettings`需配合`@ohos.inputMethod`模块的`TextConfig.extraConfig`属性使用——将`InputMethodExtraConfig`对象赋值给`TextConfig.extraConfig`，再通过`InputMethodController.attach()`传递。输入法应用侧通过`@ohos.inputMethodEngine`模块的`InputClient`接收并处理该配置。

**示例：**

```ts
import { InputMethodExtraConfig } from '@kit.IMEKit';

// 构造输入法扩展信息
let extraConfig: InputMethodExtraConfig = {
  customSettings: {
    'inputMode': 'chat',
    'showEmojiPanel': true,
    'themeColor': 'dark',
    'autoCapitalize': false,
    'fontSize': 16
  }
};

// 将扩展信息注入TextConfig（配合@ohos.inputMethod模块使用）
let textConfig = {
  inputAttribute: { textInputType: 0, enterKeyType: 0 },
  cursorInfo: { left: 100, top: 200, width: 2, height: 20 },
  extraConfig: extraConfig
};

// 通过attach传递给输入法应用
let controller = inputMethod.getController();
controller.attach(true, textConfig);
```
