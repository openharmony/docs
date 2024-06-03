# 高级组件接口说明模板

## 总体写作说明

|      | 说明项             | 细则                                                         |
| ---- | ------------------ | ------------------------------------------------------------ |
| 1    | 客户化写作基本要求 | **写作中，请变身开发者，对于开发者使用该组件时所需的使用场景、参数选取原则、开发建议/经验、示例等信息进行清晰描述，达到指导开发者顺利使用本组件进行开发的目标。** |
| 3    | 上传路径           | markdown文件：docs/zh-cn/application-dev/reference/apis-xxx-kit/<br>图片路径：docs/zh-cn/application-dev/reference/apis-xxx-kit/figures，并在markdown文件中通过路径\![]\(figures/xxx.jpg)或\![]\(figures/xxx.png)引用。 |
| 4    | 文件命名           | 一个d.ets对应一个高级组件文档，文件名称应与d.ts名称保持一致，将链接符号.变更为-<br/>示例：<br/>ohos-arkui-advanced-Chip.md |
| 5    | 目录修改           | 新增文件，需要修改对应的Readme，即`docs/zh-cn/application-dev/reference/apis-xxx-kit/Readme-CN.md`。 |
| 6    | 文档结构           | - 模块说明<br/>- 起始版本说明<br/>- 导入模块/使用说明<br/>-子组件<br>- 接口（属性、常量、方法、枚举、自定义类型）  <br>描述顺序和代码保持一致，如果某些接口具有逻辑顺序，请注意排列。 |
| 11   | 示例代码语言       | 所有的示例代码采用代码块的样式，并标记开发语言为ts，且在示例代码最开始添加注释`// xxx.ets` |
| 12   | 链接写法           | 格式：[链接文字]\(链接内容)<br/>跨文件夹链接：[指南]\(\.\./../xxx/xxx.md)，一个`../`表示上移一层文件夹。<br/>页面内链接：[接口A<sup>7+</sup>]\(#xxxa7)，页面内链接和需要链接到的标题保持一致，全小写无特殊符号（-除外）无标签。 |

## d.ets标签与文档字段的对应关系

以下字段，除版本说明外，均需下沉到每一个接口中。

如果是属性、interface表格，字段全表统一无差异，可统一写在表格上方；如果有一个不一致，需全部拆开，写到每一行的“说明”里。

| d.ts的标签                     | 含义     | 文档字段                                                     |
| ------------------------------ | -------- | ------------------------------------------------------------ |
| @since                         | 版本说明 | 1. 每个模块要有起始版本说明，使用引用语法“>”对接口的起始版本进行说明。接口没有标记的，默认与模块同一个起始版本。<br/>2. 已有模块新增接口使用\<sup>标签标记对应版本号。写法：`<sup>版本号+</sup>`<br/> 例如`<sup>7+</sup>`<br/> 示例：API 6已有的模块，在API 7新增了一个属性字段，则在属性后加标记，即newAttribute<sup>7+</sup>。<br/>如果新增了一个方法，则在方法标题后增加标记，即 getSimIccId<sup>7+</sup>，interface、class、枚举等同理。 |
| @deprecated                    | 废弃说明 | 废弃内容不能直接删去，上标标注(deprecated)，起始版本和废弃版本均使用引用语法“>”说明。若无替代接口，需给出替代方案说明。<br/>示例：abandonmentMethod<sup>(deprecated) </sup><br/>> 从API version 4 开始支持，从API version 7 开始废弃，建议使用[newMethod]\(#newmethod)替代。 |
| @FAModelOnly / @StageModelOnly | 模型约束 | **模型约束：** 此接口仅可在FA模型下使用。 <br/ >**模型约束：** 此接口仅可在Stage模型下使用。 |
| @form                          | 卡片能力 | **卡片能力：** 从API version x开始，该接口支持在ArkTS卡片中使用。 |
| @systemapi                     | 系统接口 | **系统接口：** 此接口为系统接口。                            |
| @syscap                        | 系统能力 | **系统能力**：SystemCapability.xxx.xxx                       |
| @permission                    | 权限     | 1. 如果仅涉及一个权限，格式：<br/>    **需要权限：** ohos.permission.xxxx   <br/>2. 如果该接口涉及多个权限，则采用“和、或”进行分割，格式：<br/>    **需要权限：** ohos.permission.A 和 ohos.permission.B<br/>    **需要权限：** ohos.permission.A 或 ohos.permission.B |
| @extends                       | 继承     | 带有该标签或实际存在extends关系但未带该标签时，在相关描述处应明确说明“xxx继承自xxx（提供链接）。” |

下面进入具体每个组件接口的写作。

***

# 文档标题

> *写作说明*
>
> 1. **文档标题**：作为文档标题，要求使用中文短语概括本组件功能；但如果部分概念使用英文更便于开发者理解，可以直接使用。如Button、Slider等。
> 2. **标题层级**：文档标题为一级标题，使用`# `；其他字段如function、class、interface、enum、type为二级标题，使用`## `；class下的属性、function为三级标题，使用`### `。
> 3. **起始版本说明**：使用markdown的引用语法“>”对接口的起始版本进行说明，说明后需要换行。<br/>版本说明统一放在模块描述之后。一个模块只会有一个起始版本。<br/>采用标准句式：“本模块首批接口从API version x开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。”x需要修改为对应的版本号。

模块描述。此处对该模块的定义、功能、使用场景、使用建议进行描述，采用如下固定句式。

（模块介绍，可选）xxx是xxx。

（功能描述，必选）提供xxx能力，包括xxx、xxx等。——当模块名不够语义化时，推荐此句式。

或 xxx组件/方法，用于xxx、xxx。——当模块名已经表达了清晰的语义时，推荐此句式。

（使用场景，可选）当需要xxx时，使用本模块xxx方法/本组件。

（使用建议或注意事项，可选）本模块可与xxx联合使用，以提升开发效率……。

**举例：**  @ohos.arkui.advanced.EditableTitleBar (编辑页面标题栏)

编辑型标题栏，适用于多选界面或者内容的编辑界面，一般采取左叉右勾的形式。

## 导入模块

> *写作说明*
>
> 1. 必选。根据实际情况填写导入模块。采用代码段的样式，给出import语句。
>

```js
import { EditableTitleBar } from "@ohos.arkui.advanced.EditableTitleBar"
```

## 子组件

> *写作说明*
>
> 1. 若子组件在使用时存在约束限制，需在此说明。

示例：可以包含子组件，子组件为xxxx。


## 属性

> *写作说明*
>
> 1. 必选，须说明是否支持通用属性（提供链接）。

示例：

不支持通用属性。

## 事件

> *写作说明*
>
> 1. 必选，须说明是否支持通用事件（提供链接）。

示例：

不支持通用事件。

## 结构体

> *写作说明*
>
>  1. 可选，如果没有可删除。如果有多个，请分多个二级内容描述，并使用“##”自行新建二级标题。
>   2. 写作要求同[API接口中方法](js-template.md#方法)说明。
>  3. 二级标题名为struct的名称。
>  4. 若struct或其参数被装饰器修饰，则需要说明"装饰器类型"。

示例：

ComposeListItem({contentItem?: ContentItem, operateItem?: OperateItem})

**装饰器类型：**\@Component


**参数：**


| 名称        | 类型                        | 必填 | 装饰器类型 | 说明                   |
| ----------- | --------------------------- | ---- | ---------- | ---------------------- |
| contentItem | [ContentItem](#contentitem) | 否   | \@Prop     | 定义左侧以及中间元素。 |
| operateItem | [OperateItem](#operateitem) | 否   | \@Prop     | 定义右侧元素。         |

## 方法

> *写作说明*
>
> 1. 可选，如果没有可删除。写作要求同[API接口中方法](js-template.md#方法)说明。
> 2. 无需体现示例代码。


## Class

> *写作说明*
>
> 1. 可选，如果没有可删除。如果有多个，请分多个二级内容描述，并使用“##”自行新建二级标题。
> 2. 二级标题名为class、interface的名称。
> 3. 如果该API中，既有属性，又有方法，需要先进行属性的写作，并使用“###”三级标题。 如果该API中，只有属性，那么不需要新建三级标题，直接使用表格陈列属性。

### 属性

> *写作说明*
>
> 1. 可选，如果没有可删除。写作要求同[API接口中属性](js-template.md#属性)说明。

### Class中的方法

> *写作说明*
>
> 1. 可选，如果没有可删除。写作要求同[API接口中方法](js-template.md#方法)说明。

## 枚举

> *写作说明*
>
> 1. 可选，如果没有可删除。写作要求同[API接口中枚举](js-template.md#枚举)说明。

## Type

> *写作说明*
>
> 1. 可选，如果没有可删除。写作要求同[API接口中Type](js-template.md#type)说明。

## 示例

此处说明该示例的应用效果。

> *写作说明*
>
> 1. 必选，以二级/三级标题的形式体现，需要示例代码和示例图。
> 2. 若该组件/模块功能复杂，则按照功能点划分，按照三级标题的形式分块呈现示例代码和示例图。
>
> ```tsx
> // 必选项。
> 
> // 所有的示例代码需要进行自检。
> // 不能出现缺符号、变量前后不一致等低错。
> // 所有的使用到的变量要进行声明。
> // 所有示例代码均需要添加语言标记。
> 
> // 不允许直接写参数名，必须是可使用、易替代的实际用例。如果非用户自定义填写，需通过注释进行说明。
> // 例如：var result = xxx.createExample(parameterOne); // parameterOne由扫描自动获取
> 
> // 示例图布局清晰，配色简洁大方，图片有版权。
> 
> // 注释要精简、突出要点。需提供注释的典型场景还有：
> // 1. 当代码不能说明变量命名的具体含义，或不能说明代码逻辑时，必须提供注释。
> // 2. 涉及到复杂算法或特殊语法时，必须提供注释。
> ```

示例：

```ts
// xxx.ets
@Entry
@Component
struct CheckboxExample {
  build() {
    Row() {
      // 生成一个多选框，默认选中，点击可显示多选框状态
      Checkbox({name: 'checkbox1',  group: 'checkboxGroup'})
        .select(true)
        .selectedColor(0xed6f21)
        .onChange((value: boolean) => {
          console.info('Checkbox1 change is'+ value)
        })
      // 生成一个多选框，默认不选中，点击可显示多选框状态
      Checkbox({name: 'checkbox2',  group: 'checkboxGroup'})
        .select(false)
        .selectedColor(0x39a2db)
        .onChange((value: boolean) => {
          console.info('Checkbox2 change is'+ value)
        })
    }
  }
}
```
<!--no_check-->