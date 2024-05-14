# 属性字符串
## 概述

属性字符串可用于Text和RichEditor组件中灵活设置样式。具体用法可参考[StyledString](../reference/apis-arkui/arkui-ts/ts-universal-styled-string.md#属性字符串)。

- 创建StyledString和MutableStyledString

```ts
@Entry
@Component
struct styled_string_demo1 {
  styledString1: StyledString = new StyledString("运动45分钟");
  mutableStyledString1: MutableStyledString = new MutableStyledString("运动35分钟");
  controller1: TextController = new TextController();
  controller2: TextController = new TextController();

  async onPageShow() {
    this.controller1.setStyledString(this.styledString1)
    this.controller2.setStyledString(this.mutableStyledString1)
  }

  build() {
    Column() {
      // 显示属性字符串
      Text(undefined, { controller: this.controller1 })
      Text(undefined, { controller: this.controller2 })
    }
    .width('100%')
  }
}
```

## 设置文本样式

可通过TextStyle、TextShadowStyle、DecorationStyle、BaselineOffsetStyle、LineHeightStyle、LetterSpacingStyle设置文本的各类样式。

- 创建TextStyle

```ts
// xxx.ets
@Entry
@Component
struct styled_string_demo2 {
  mutableStyledString: MutableStyledString = new MutableStyledString("运动35分钟", [
  {
    start: 0,
    length: 3,
    styledKey: StyledStringKey.FONT,
    styledValue: new TextStyle({ fontColor: Color.Pink })
  }
  ]);
  controller: TextController = new TextController();

  async onPageShow() {
    this.controller.setStyledString(this.mutableStyledString)
  }

  build() {
    Column() {
      // 显示属性字符串
      Text(undefined, { controller: this.controller })
    }
    .width('100%')
  }
}
```

- 创建TextShadowStyle

```ts
// xxx.ets
@Entry
@Component
struct styled_string_demo3 {
  mutableStyledString: MutableStyledString = new MutableStyledString("运动35分钟", [
  {
    start: 0,
    length: 3,
    styledKey: StyledStringKey.TEXT_SHADOW,
    styledValue: new TextShadowStyle({
      radius: 5,
      type: ShadowType.COLOR,
      color: Color.Red,
      offsetX: 10,
      offsetY: 10
    })
  }
  ]);
  controller: TextController = new TextController();

  async onPageShow() {
    this.controller.setStyledString(this.mutableStyledString)
  }

  build() {
    Column() {
      // 显示属性字符串
      Text(undefined, { controller: this.controller })
    }
    .width('100%')
  }
}
```

- 创建DecorationStyle

```ts
// xxx.ets
@Entry
@Component
struct styled_string_demo4 {
  mutableStyledString: MutableStyledString = new MutableStyledString("运动35分钟", [
  {
    start: 0,
    length: 3,
    styledKey: StyledStringKey.DECORATION,
    styledValue: new DecorationStyle({type: TextDecorationType.LineThrough, color: Color.Red})
  }
  ]);
  controller: TextController = new TextController();

  async onPageShow() {
    this.controller.setStyledString(this.mutableStyledString)
  }

  build() {
    Column() {
      // 显示属性字符串
      Text(undefined, { controller: this.controller })
    }
    .width('100%')
  }
}
```

- 创建BaselineOffsetStyle

```ts
import { LengthMetrics, LengthUnit } from '@ohos.arkui.node'
// xxx.ets
@Entry
@Component
struct styled_string_demo5 {
  mutableStyledString: MutableStyledString = new MutableStyledString("运动35分钟", [
    {
      start: 0,
      length: 3,
      styledKey: StyledStringKey.BASELINE_OFFSET,
      styledValue: new BaselineOffsetStyle(LengthMetrics.px(20))
    }
  ]);
  controller: TextController = new TextController();

  async onPageShow() {
    this.controller.setStyledString(this.mutableStyledString)
  }

  build() {
    Column() {
      // 显示属性字符串
      Text(undefined, { controller: this.controller })
    }
    .width('100%')
  }
}
```

- 创建LineHeightStyle

```ts
import { LengthMetrics, LengthUnit } from '@ohos.arkui.node'
// xxx.ets
@Entry
@Component
struct styled_string_demo6 {
  mutableStyledString: MutableStyledString = new MutableStyledString("运动35分钟\n顶顶顶\n得到", [
    {
      start: 8,
      length: 3,
      styledKey: StyledStringKey.LINE_HEIGHT,
      styledValue: new LineHeightStyle(LengthMetrics.vp(50))
    }
  ]);
  controller: TextController = new TextController();

  async onPageShow() {
    this.controller.setStyledString(this.mutableStyledString)
  }

  build() {
    Column() {
      // 显示属性字符串
      Text(undefined, { controller: this.controller })
    }
    .width('100%')
    .margin({ top: 10 })
  }
}
```

- 创建LetterSpacingStyle

```ts
import { LengthMetrics, LengthUnit } from '@ohos.arkui.node'
// xxx.ets
@Entry
@Component
struct styled_string_demo7 {
  mutableStyledString: MutableStyledString = new MutableStyledString("运动35分钟", [
    {
      start: 0,
      length: 2,
      styledKey: StyledStringKey.LETTER_SPACING,
      styledValue: new LetterSpacingStyle(new LengthMetrics(20, LengthUnit.VP))
    }
  ]);
  controller: TextController = new TextController();

  async onPageShow() {
    this.controller.setStyledString(this.mutableStyledString)
  }

  build() {
    Column() {
      // 显示属性字符串
      Text(undefined, { controller: this.controller })
    }
    .width('100%')
  }
}
```

## 设置段落样式

可通过ParagraphStyle设置段落样式布局。

- 创建ParagraphStyle

  ```ts
  
  ```

## 使用事件

可通过GestureStyle设置onClick、onLongPress事件来响应操作。


- 创建GestureStyle

  ```ts
  
  ```



## 使用图片

可通过ImageAttachment来绑定图片。

- 创建ImageAttachment

```ts

```

## 使用自定义绘制

可通过CustomSpan来实现自定义绘制。

- 创建CustomSpan

```ts

```