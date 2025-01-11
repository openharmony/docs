# SubHeaderV2


子标题，用于列表项顶部，将该组列表划分为一个区块，子标题名称用来概括该区块内容。也可以用于内容项顶部，子标题名称用来概括该区块内容。


> **说明：**
>
> 该组件从API Version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 导入模块

```ts
import { SubHeader } from '@kit.ArkUI'
```


## 子组件

无

## 属性

支持[通用属性](ts-universal-attributes-size.md)。

> **说明：**
>
> 不支持设置文本相关。

## SubHeader

SubHeaderV2({
icon?: SubHeaderV2IconType,
title?: SubHeaderV2Title,
select?: SubHeaderV2Select,
operationType?: SubHeaderV2OperationType,
operationItems?: SubHeaderV2OperationItem
})

**装饰器类型：** @ComponentV2

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 必填 | 装饰器类型 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| icon| [SubHeaderV2IconType](#SubHeaderV2IconType) | 否 | @Param | 图标设置项。 |
| title| [SubHeaderV2Title](#SubHeaderV2Title) | 否 | @Param| 标题设置项。 |
| select| [SubHeaderV2Select](#SubHeaderV2Select) | 否 | @Param | select内容以及事件。 |
| operationType | [SubHeaderV2OperationType](#SubHeaderV2OperationType) | 否 | @Param| 操作区元素样式。<br />默认值：OperationType.BUTTON|
| operationItems | [SubHeaderV2OperationItem](#SubHeaderV2OperationItem)[] | 否 | @Param| 操作区的设置项。 |
| titleBuilder | SubHeaderV2TitleBuilder | 否 | @BuildParam| 自定义标题区内容。 |

## SubHeaderV2IconType

图标内容的联合类型。

**元服务API：** 从API version 16开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                        | 说明                             |
| ----------------------------- | ---------------------------------- |
| ResourceStr                 | 资源类型，用于定义普通图标       |
| SymbolGlyphModifier | Symbol类型，用于定义Symbol图标。 |

## SubHeaderV2Title

**装饰器类型：** @ObservedV2

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 必填 | 装饰器类型 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| primaryTitle|  [ResourceStr](ts-types.md#resourcestr)  | 否 | @Trace |  标题内容。 |
| secondaryTitle|  [ResourceStr](ts-types.md#resourcestr)  | 否 | @Trace |  副标题内容。 |
| primaryTitleModifier|  [TextModifier](ts-universal-attributes-attribute-modifier.md)  | 否 | @Trace |  设置标题文本属性，如设置标题颜色、字体大小、字重等。 |
| secondaryTitleModifier|   [TextModifier](ts-universal-attributes-attribute-modifier.md)  | 否 | @Trace | 设置副标题文本属性，如设置标题颜色、字体大小、字重等。 |

### constructor

constructor(options: SubHeaderV2TitleOptions)

构造函数。

**元服务API：** 从API version 16开始，该接口支持在元服务中使用。

**参数：**

| 名称    | 参数类型             | 必填 | 说明             |
| --------- | ---------------------- | ------ | ------------------ |
| options | SubHeaderV2TitleOptions | 是   | 标题内容信息。 |

## SubHeaderV2TitleOptions

用于构建SubHeaderV2Title对象。

**原子化服务API：** 从API version 16开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 属性 | 类型 | 必填  | 描述    |
| -------- | -------- | -------- | -------- |
| primaryTitle|  [ResourceStr](ts-types.md#resourcestr)  | 否 |  标题内容。 |
| secondaryTitle|  [ResourceStr](ts-types.md#resourcestr)  | 否 |  副标题内容。 |
| primaryTitleModifier|  [TextModifier](ts-universal-attributes-attribute-modifier.md)  | 否 |  设置标题文本属性，如设置标题颜色、字体大小、字重等。 |
| secondaryTitleModifier|   [TextModifier](ts-universal-attributes-attribute-modifier.md)  | 否 | 设置副标题文本属性，如设置标题颜色、字体大小、字重等。 |

## SubHeaderV2Select

**装饰器类型：** @ObservedV2

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 必填 | 装饰器类型| 说明 |
| -------- | -------- | -------- | -------- | -------- |
| options | [SelectOption](ts-basic-components-select.md#selectoption对象说明)[] | 是 | @Trace | 下拉选项内容。 |
| selectedIndex | number | 否 |@Trace |  设置下拉菜单初始选项的索引。<br />第一项的索引为0。<br />当不设置selected属性时，<br />默认选择值为-1，菜单项不选中。 |
| selectedContent | string | 否 | @Trace | 设置下拉按钮本身的文本内容。 |
| onSelect | SubHeaderV2SelectOnSelect | 否 | @Trace | 下拉菜单选中某一项的回调。 |

### constructor

constructor(options: SubHeaderV2SelectOptions)

构造函数。

**元服务API：** 从API version 16开始，该接口支持在元服务中使用。

**参数：**

| 名称    | 参数类型             | 必填 | 说明             |
| --------- | ---------------------- | ------ | ------------------ |
| options | SubHeaderV2SelectOptions | 是   | 下拉选项信息。 |

## SubHeaderV2SelectOptions

用于构建SubHeaderV2Select对象。

**原子化服务API：** 从API version 16开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 属性 | 类型 | 必填  | 描述    |
| -------- | -------- | -------- | -------- | 
| options | [SelectOption](ts-basic-components-select.md#selectoption对象说明)[] | 是 | 下拉选项内容。 |
| selectedIndex | number | 否 |  设置下拉菜单初始选项的索引。<br />第一项的索引为0。<br />当不设置selected属性时，<br />默认选择值为-1，菜单项不选中。 |
| selectedContent | string | 否 | 设置下拉按钮本身的文本内容。 |
| onSelect | SubHeaderV2SelectOnSelect  | 否 | 下拉菜单选中某一项的回调。 |

## SubHeaderV2SelectOnSelect

下拉菜单选中某一项的回调类型。

type SubHeaderV2SelectOnSelect= (selectIndex: number, selectContent?: string) => void;

**原子化服务API：** 从API version 16开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

|名称|类型                             | 说明                                          |
| ------------------------------- |-------------------------------- | --------------------------------------------- |
| SubHeaderV2SelectOnSelect | (selectedIndex: number, selectedContent?: string) => void; |  下拉菜单选中某一项的回调类型。<br> -index： 表示选中项的索引。<br> -value： 表示选中项的值。 |

## SubHeaderV2OperationType

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| TEXT_ARROW |  0  | 文本按钮（带右箭头）。 |
| BUTTON |  1  |  文本按钮（不带右箭头）。 |
| ICON_GROUP |  2  |  图标按钮（最多支持配置三张图标）。 |
| LOADING |  3  |  加载动画。 |

## SubHeaderV2OperationItemType

操作区元素内容的联合类型。

**元服务API：** 从API version 16开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                        | 说明                             |
| ----------------------------- | ---------------------------------- |
| ResourceStr                 | 字符串类型用于定义文本显示或普通图标；资源类型，用于定义普通图标       |
| SymbolGlyphModifier | Symbol类型，用于定义Symbol图标。 |

## SubHeaderV2OperationItem

**装饰器类型：** @ObservedV2

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 必填 | 装饰器类型 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| content |  [SubHeaderV2OperationItemType](#SubHeaderV2OperationItemType)  | 是 | @Trace | 操作区元素内容。 |
| action | SubHeaderV2OperationItemAction | 否 | @Trace | 操作区事件。 |
| accessibilityText |[ResourceStr](https://wiki.huawei.com/domains/80077/wiki/140885/ts-types.md#resourcestr) | 否 |@Trace | 子标题右侧icon图标无障碍描述。|
| accessibilityLevel |[string](https://wiki.huawei.com/domains/80077/wiki/140885/ts-types.md#resourcestr) | 否 |@Trace | 子标题右侧icon图标无障碍重要性。<br>默认值: “yes”。  | 
| accessibilityDescription|[ResourceStr](https://wiki.huawei.com/domains/80077/wiki/140885/ts-types.md#resourcestr) | 否 |@Trace | 子标题右侧icon图标无障碍说明，用于为用户进一步说明当前组件。<br>默认值：“单指双击即可执行”。 |

### constructor

constructor(options: SubHeaderV2OperationItemOptions)

构造函数。

**元服务API：** 从API version 16开始，该接口支持在元服务中使用。

**参数：**

| 名称    | 参数类型             | 必填 | 说明             |
| --------- | ---------------------- | ------ | ------------------ |
| options | SubHeaderV2OperationItemOptions| 是   | 下拉选项信息。 |

## SubHeaderV2OperationItemAction

操作区的设置项的回调事件类型。

type SubHeaderV2OperationItemAction = () => void;

**原子化服务API：** 从API version 16开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

|名称|类型                             | 说明                                          |
| ------------------------------- |-------------------------------- | --------------------------------------------- |
| SubHeaderV2OperationItemAction | () => void; |  操作区的设置项的回调事件类型。 |

## SubHeaderV2OperationItemOptions

用于构建SubHeaderV2OperationItem对象。

**原子化服务API：** 从API version 16开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 属性 | 类型 | 必填  | 描述    |
| -------- | -------- | -------- | -------- |
| value |  [SubHeaderV2IconType](#SubHeaderV2IconType)  | 是 | 文本内容。 |
| action | SubHeaderV2OperationItemAction | 否 | 事件。 |
| accessibilityText |[ResourceStr](https://wiki.huawei.com/domains/80077/wiki/140885/ts-types.md#resourcestr) | 否 | 子标题右侧icon图标无障碍描述。|
| accessibilityLevel |[string](https://wiki.huawei.com/domains/80077/wiki/140885/ts-types.md#resourcestr) | 否 |子标题右侧icon图标无障碍重要性。<br>默认值: “yes”。  | 
| accessibilityDescription|[ResourceStr](https://wiki.huawei.com/domains/80077/wiki/140885/ts-types.md#resourcestr) | 否 | 子标题右侧icon图标无障碍说明，用于为用户进一步说明当前组件。<br>默认值：“单指双击即可执行”。 |

## SubHeaderV2TitleBuilder

自定义标题区内容的回调事件类型。

type SubHeaderV2TitleBuilder= () => void;

**原子化服务API：** 从API version 16开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

|名称|类型                             | 说明                                          |
| ------------------------------- |-------------------------------- | --------------------------------------------- |
| SubHeaderV2TitleBuilder| () => void; |  自定义标题区内容的回调事件类型。 |

## 事件
支持[通用事件](ts-universal-events-click.md)

## 示例
### 示例1（效率型子标题）
该示例主要演示子标题左侧为icon、secondaryTitle，右侧operationType为按钮类型。

```ts
import
  SubHeaderV2OperationType,
  SubHeaderV2,
  SubHeaderV2Title,
  SubHeaderV2OperationItem,
  promptAction
} from '@kit.ArkUI'
import { TextModifier } from '@ohos.arkui.modifier'

@Entry
@ComponentV2
struct SubHeaderExample {
  @Local selectText: string = "TTTTT"
  @Local selectIndex: number = 2
  @Local flag: boolean = true;
  @Local index: number = 1;
  @Local primaryTitle: ResourceStr = '一级标题';
  @Local secondaryTitle: ResourceStr = '二级标题';
  @Local subHeaderIcon: Resource = $r('sys.media.ohos_ic_public_web');
  @Local title: SubHeaderV2Title = new SubHeaderV2Title({ primaryTitle: '一级标题' });
  @Local primaryModifier: TextModifier = new TextModifier().fontColor(Color.Red);
  @Local secondaryModifier: TextModifier = new TextModifier().fontColor(Color.Red);
  @Local subHeaderOperationType: SubHeaderV2OperationType = SubHeaderV2OperationType.BUTTON;
  @Local operationItems: SubHeaderV2OperationItem[] = [];

  aboutToAppear(): void {
    this.title = new SubHeaderV2Title({
      primaryTitle: this.primaryTitle,
      secondaryTitle: this.secondaryTitle,
    });
    this.operationItems = [new SubHeaderV2OperationItem({
      content: '操作',
      action: () => {
        promptAction.showToast({ message: 'demo2' })
      }
    })]
  }

  build() {
    Column() {
      Column() {
        SubHeaderV2({
          icon: this.subHeaderIcon,
          title: this.title,
          operationType: this.subHeaderOperationType,
          operationItems: this.operationItems
        });
      }
    }
  }
}
```

![子标题1](figures/zh-cn_image_subheader_example01.png)

### 示例2（双行文本内容型子标题）
该示例主要演示子标题左侧为primaryTitle、secondaryTitle，右侧operationType类型为TEXT_ARROW。

```ts
import {
  SubHeaderV2OperationType,
  SubHeaderV2,
  SubHeaderV2Title,
  SubHeaderV2OperationItem,
  promptAction
} from '@kit.ArkUI'
import { TextModifier } from '@ohos.arkui.modifier'

@Entry
@ComponentV2
struct SubHeaderExample {
  @Local title: SubHeaderV2Title = new SubHeaderV2Title({ primaryTitle: '一级标题', secondaryTitle: '二级标题' });
  @Local primaryModifier: TextModifier = new TextModifier().fontColor(Color.Red);
  @Local secondaryModifier: TextModifier = new TextModifier().fontColor(Color.Red);
  @Local subHeaderOperationType: SubHeaderV2OperationType = SubHeaderV2OperationType.TEXT_ARROW;
  @Local operationItems: SubHeaderV2OperationItem[] = [];

  aboutToAppear(): void {
    this.title = new SubHeaderV2Title({
      primaryTitle: '一级标题',
      secondaryTitle: '二级标题'
    });
    this.operationItems = [new SubHeaderV2OperationItem({
      content: '更多',
      action: () => {
        promptAction.showToast({ message: 'demo2' })
      }
    })]
  }

  build() {
    Column() {
      Column() {
        SubHeaderV2({
          title: this.title,
          operationType: this.subHeaderOperationType,
          operationItems: this.operationItems
        });
      }
    }
  }
}
```

![子标题2](figures/zh-cn_image_subheader_example02.png)

### 示例3（spinner型内容型子标题）
该示例主要演示子标题左侧为select，右侧operationType类型为ICON_GROUP。

```ts
import {
  SubHeaderV2,
  SubHeaderV2OperationType,
  SubHeaderV2OperationItem,
  SubHeaderV2Title,
  SubHeaderV2Select,
  promptAction
} from '@kit.ArkUI'
import { TextModifier } from '@ohos.arkui.modifier'

@Entry
@ComponentV2
struct SubHeaderExample {
  @Local selectedValue: string = 'aaa';
  @Local selectedIndex: number = 0;
  @Local title: SubHeaderV2Title = new SubHeaderV2Title({ primaryTitle: '一级标题', secondaryTitle: '二级标题' });
  @Local operationItems: SubHeaderV2OperationItem[] = [];
  @Local select: SubHeaderV2Select =
    new SubHeaderV2Select({ options: [{ value: 'aaa' }, { value: 'bbb' }, { value: 'ccc' }] });

  aboutToAppear(): void {

    this.title = new SubHeaderV2Title({
      primaryTitle: '一级标题',
      secondaryTitle: '二级标题'
    });

    this.selectedValue = 'selectDemo';
    this.select = new SubHeaderV2Select({
      options: [{ value: 'aaa' }, { value: 'bbb' }, { value: 'ccc' }],
      selectedContent: this.selectedValue,
      selectedIndex: this.selectedIndex,
      onSelect: (index: number, value?: string) => {
        promptAction.showToast({ message: 'selectdemo' })
      }
    })

    this.operationItems = [
      new SubHeaderV2OperationItem({
        content: $r('sys.media.ohos_ic_public_web'),
        action: () => {
          promptAction.showToast({ message: 'demo2' })
        }
      }),
      new SubHeaderV2OperationItem({
        content: $r('sys.media.ohos_ic_public_web'),
        action: () => {
          promptAction.showToast({ message: 'demo2' })
        }
      }),
      new SubHeaderV2OperationItem({
        content: $r('sys.media.ohos_ic_public_web'),
        action: () => {
          promptAction.showToast({ message: 'demo2' })
        }
      })]
  }

  build() {
    Column() {
      Column() {
        SubHeaderV2({
          select: this.select,
          operationType: SubHeaderV2OperationType.ICON_GROUP,
          operationItems: this.operationItems
        })
      }
    }
  }
}
```

![子标题5](figures/zh-cn_image_subheader_example03.png)

### 示例4（设置左侧symbol图标）
该示例主要演示子标题左侧icon设置symbol图标。

```ts
import {
  SubHeaderV2,
  SubHeaderV2OperationType,
  SubHeaderV2OperationItem,
  SubHeaderV2Title }
  from '@kit.ArkUI'
import { promptAction,SymbolGlyphModifier } from '@kit.ArkUI'

@Entry
@ComponentV2
struct SubHeaderExample {
  @Local icon: SymbolGlyphModifier = new SymbolGlyphModifier($r('sys.symbol.ohos_wifi'));

  aboutToAppear(): void {
    this.icon = new SymbolGlyphModifier($r('sys.symbol.ohos_wifi')).fontSize(24);
    this.icon.effectStrategy(SymbolEffectStrategy.HIERARCHICAL)
  }

  build() {
    Column() {
      SubHeaderV2({
        icon: this.icon,
        title: new SubHeaderV2Title({ secondaryTitle: '标题' }),
        operationType: SubHeaderV2OperationType.BUTTON,
        operationItems: [new SubHeaderV2OperationItem({
          content: '操作',
          action: () => {
            promptAction.showToast({ message: 'demo' })
          }
        })]
      })
    }
  }
}
```

![子标题4](figures/zh-cn_image_subheader_example04.gif)

### 示例5（设置右侧symbol图标）
该示例主要演示子标题operationType设置为OperationType.ICON_GROUP，operationItem的value设置为symbol图标。

```ts
import {
  SubHeaderV2,
  SubHeaderV2OperationType,
  SubHeaderV2OperationItem,
  SubHeaderV2Title,
  SubHeaderV2Select,
  promptAction,
  SymbolGlyphModifier
} from '@kit.ArkUI'


@Entry
@ComponentV2
struct SubHeaderExample {
  @Local icon: SymbolGlyphModifier = new SymbolGlyphModifier($r('sys.symbol.ohos_wifi'));
  @Local selectedValue: string = 'aaa';
  @Local selectedIndex: number = 2;
  @Local title: SubHeaderV2Title = new SubHeaderV2Title({ primaryTitle: '一级标题', secondaryTitle: '二级标题' });
  @Local operationItem: SubHeaderV2OperationItem[] = [];
  @Local select: SubHeaderV2Select =
    new SubHeaderV2Select({ options: [{ value: 'aaa' }, { value: 'bbb' }, { value: 'ccc' }] });

  aboutToAppear(): void {
    this.icon = new SymbolGlyphModifier($r('sys.symbol.ohos_wifi'));
    this.icon.effectStrategy(SymbolEffectStrategy.HIERARCHICAL);

    this.selectedValue = 'selectDemo';
    this.selectedIndex = 2;
    this.title = new SubHeaderV2Title({
      primaryTitle: '一级标题',
      secondaryTitle: '二级标题'
    });
    this.select = new SubHeaderV2Select({
      options: [{ value: 'aaa' }, { value: 'bbb' }, { value: 'ccc' }],
      selectedContent: this.selectedValue,
      selectedIndex: this.selectedIndex,
      onSelect: (index: number, value?: string) => {
        promptAction.showToast({ message: 'demo' })
      }
    })

    this.operationItem = [
      new SubHeaderV2OperationItem({
        content: new SymbolGlyphModifier($r('sys.symbol.ohos_lungs')).fontWeight(FontWeight.Lighter),
        action: () => {
          promptAction.showToast({ message: 'demo1' })
        }
      }),
      new SubHeaderV2OperationItem({
        content: new SymbolGlyphModifier($r('sys.symbol.ohos_lungs'))
          .renderingStrategy(SymbolRenderingStrategy.MULTIPLE_COLOR)
          .fontColor([Color.Blue, Color.Grey, Color.Green])
      ,
        action: () => {
          promptAction.showToast({ message: 'demo2' })
        }
      }),
      new SubHeaderV2OperationItem({
        content: new SymbolGlyphModifier($r('sys.symbol.ohos_lungs'))
          .renderingStrategy(SymbolRenderingStrategy.MULTIPLE_OPACITY)
          .fontColor([Color.Blue, Color.Grey, Color.Green])
      ,
        action: () => {
          promptAction.showToast({ message: 'demo3' })
        }
      })]
  }

  build() {
    Column() {
      SubHeaderV2({
        select: this.select,
        operationType: SubHeaderV2OperationType.ICON_GROUP,
        operationItems: this.operationItem
      })
    }
  }
}
```

![子标题5](figures/zh-cn_image_subheader_example05.png)

### 示例6（自定义标题内容）
 该示例主要演示SubHeader设置titleBuilder自定义标题内容的效果。

```ts
import
  SubHeaderV2,
  SubHeaderV2OperationType,
  SubHeaderV2OperationItem,
  SubHeaderV2Title,
  SubHeaderV2Select,
  promptAction,
  SymbolGlyphModifier
} from '@kit.ArkUI'


@Entry
@ComponentV2
struct SubHeaderExample {
  @Local icon: SymbolGlyphModifier = new SymbolGlyphModifier($r('sys.symbol.ohos_wifi'));
  @Local selectedValue: string = 'aaa';
  @Local selectedIndex: number = 2;
  @Local title: SubHeaderV2Title = new SubHeaderV2Title({ primaryTitle: '一级标题', secondaryTitle: '二级标题' });
  @Local operationItem: SubHeaderV2OperationItem[] = [];
  @Local select: SubHeaderV2Select =
    new SubHeaderV2Select({ options: [{ value: 'aaa' }, { value: 'bbb' }, { value: 'ccc' }] });

  aboutToAppear(): void {
    this.icon = new SymbolGlyphModifier($r('sys.symbol.ohos_wifi'));
    this.icon.effectStrategy(SymbolEffectStrategy.HIERARCHICAL);

    this.selectedValue = 'selectDemo';
    this.selectedIndex = 2;
    this.title = new SubHeaderV2Title({
      primaryTitle: '一级标题',
      secondaryTitle: '二级标题'
    });
    this.select = new SubHeaderV2Select({
      options: [{ value: 'aaa' }, { value: 'bbb' }, { value: 'ccc' }],
      selectedContent: this.selectedValue,
      selectedIndex: this.selectedIndex,
      onSelect: (index: number, value?: string) => {
        promptAction.showToast({ message: 'demo' })
      }
    })

    this.operationItem = [
      new SubHeaderV2OperationItem({
        content: new SymbolGlyphModifier($r('sys.symbol.ohos_lungs')).fontWeight(FontWeight.Lighter),
        action: () => {
          promptAction.showToast({ message: 'demo1' })
        }
      }),
      new SubHeaderV2OperationItem({
        content: new SymbolGlyphModifier($r('sys.symbol.ohos_lungs'))
          .renderingStrategy(SymbolRenderingStrategy.MULTIPLE_COLOR)
          .fontColor([Color.Blue, Color.Grey, Color.Green])
      ,
        action: () => {
          promptAction.showToast({ message: 'demo2' })
        }
      }),
      new SubHeaderV2OperationItem({
        content: new SymbolGlyphModifier($r('sys.symbol.ohos_lungs'))
          .renderingStrategy(SymbolRenderingStrategy.MULTIPLE_OPACITY)
          .fontColor([Color.Blue, Color.Grey, Color.Green])
      ,
        action: () => {
          promptAction.showToast({ message: 'demo3' })
        }
      })]
  }

  build() {
    Column() {
      SubHeaderV2({
        select: this.select,
        operationType: SubHeaderV2OperationType.ICON_GROUP,
        operationItems: this.operationItem
      })
    }
  }
}
```

![子标题6](figures/zh-cn_image_subheader_example06.png)

### 示例7（自定义标题样式）
该示例主要演示SubHeader设置标题和副标题字体样式。

```ts
import { promptAction, OperationType, SubHeader, LengthMetrics, TextModifier } from '@kit.ArkUI';

@Entry
@Component
struct SubHeaderExample {
  @State primaryModifier: TextModifier = new TextModifier().fontColor(Color.Red);
  @State secondaryModifier: TextModifier = new TextModifier().fontColor(Color.Red);

  build() {
    Column() {
      SubHeader({
        primaryTitle: 'primaryTitle',
        secondaryTitle: 'secondaryTitle',
        primaryTitleModifier: this.primaryModifier,
        secondaryTitleModifier: this.secondaryModifier,
        operationType: OperationType.TEXT_ARROW,
        operationItem: [{
          value: '更多信息',
          action: () => {
            promptAction.showToast({ message: 'demo'})
          }
        }],
        contentMargin: { start: LengthMetrics.vp(20), end: LengthMetrics.vp(20) },
        contentPadding: { start: LengthMetrics.vp(20), end: LengthMetrics.vp(20) }
      })
    }
  }
}
```

![子标题7](figures/zh-cn_image_subheader_example07.png)


### 示例8（右侧按钮自定义播报）
该示例通过设置subheader的右侧按钮属性accessibilityText、accessibilityDescription、accessibilityLevel自定义屏幕朗读播报文本。
```ts
import {
  SubHeaderV2OperationType,
  SubHeaderV2,
  SubHeaderV2Title,
  SubHeaderV2OperationItem,
  SubHeaderV2IconType,
  SubHeaderV2Select,
  promptAction
} from '@kit.ArkUI'

@Entry
@ComponentV2
struct SubHeaderExample {
  @Local index: number = 1;
  @Local primaryTitle: ResourceStr = '一级标题';
  @Local secondaryTitle: ResourceStr = '二级标题';
  @Local subHeaderIcon: SubHeaderV2IconType | undefined = $r('app.media.startIcon');
  @Local title: SubHeaderV2Title = new SubHeaderV2Title({ primaryTitle: '一级标题' });
  @Local title2: SubHeaderV2Title = new SubHeaderV2Title({ primaryTitle: '一级标题', secondaryTitle: '二级标题' });
  @Local subHeaderOperationType: SubHeaderV2OperationType = SubHeaderV2OperationType.BUTTON;
  @Local subHeaderOperationType2: SubHeaderV2OperationType = SubHeaderV2OperationType.TEXT_ARROW;
  @Local subHeaderOperationType3: SubHeaderV2OperationType = SubHeaderV2OperationType.ICON_GROUP;
  @Local operationItems: SubHeaderV2OperationItem[] = [];
  @Local selectedValue: string | undefined = 'selectDemo';
  @Local selectedIndex: number = 0;
  @Local select: SubHeaderV2Select =
    new SubHeaderV2Select({ options: [{ value: 'aaa' }, { value: 'bbb' }, { value: 'ccc' }] });

  aboutToAppear(): void {
    this.select = new SubHeaderV2Select({ options: [] });
    this.title = new SubHeaderV2Title({
      primaryTitle: this.primaryTitle,
      secondaryTitle: this.secondaryTitle,
    });
    this.operationItems = [new SubHeaderV2OperationItem({
      content: '操作',
      action: () => {
        promptAction.showToast({ message: 'demo2' })
      }
    })]
  }

  build() {
    Column() {
      Column() {
        SubHeaderV2({
          icon: this.subHeaderIcon,
          title: this.title,
          select: this.select,
          operationType: this.subHeaderOperationType,
          operationItems: this.operationItems
        });
        SubHeaderV2({
          title: this.title2,
          select: this.select,
          operationType: this.subHeaderOperationType2,
          operationItems: this.operationItems
        });
        SubHeaderV2({
          select: new SubHeaderV2Select({
            options: [{ value: 'aaa' }, { value: 'bbb' }, { value: 'ccc' }],
            selectedIndex: this.selectedIndex,
            selectedContent: this.selectedValue,
            onSelect: (index: number, value?: string) => {
              this.selectedIndex = index;
              this.selectedValue = value;
              promptAction.showToast({ message: this.selectedValue })
            }
          }),
          operationType: this.subHeaderOperationType3,
          operationItems: [new SubHeaderV2OperationItem({
            content: $r('app.media.app_icon'),
            accessibilityText: '图标1',
            accessibilityLevel: 'yes',
          }), new SubHeaderV2OperationItem({
            content: $r('app.media.app_icon'),
            accessibilityText: '图标2',
            accessibilityLevel: 'no',
          }), new SubHeaderV2OperationItem({
            content: $r('app.media.app_icon'),
            accessibilityText: '图标3',
            accessibilityDescription: '点击操作图标3',
          })]
        });
      }.height('60%')
    }
  }
}
```
![/zh-cn_image_subheader_example08](figures/zh-cn_image_subheader_example08.png)