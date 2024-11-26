# ArkUI子系统Changelog

## cl.arkui.1 @ComponentV2自定义组件冻结变更

**访问级别**

公开接口

**变更原因**

当@ComponentV2装饰的子组件设置freezeWhenInactive为true时，父组件没有设置，则子组件的组件冻结功能不生效。

为了确保组件冻结功能生效，需要修改当子组件设置freezeWhenInactive为true，无论父组件是否设置，子组件的组件冻结功能应生效。

**变更影响**

该变更为不兼容变更。

变更前：仅子组件开启了组件冻结，父组件没有开启组件冻结，不会对子组件开启冻结功能。

变更后：仅子组件开启了组件冻结，父组件没有开启组件冻结，子组件会启用组件冻结功能。

**起始API Level**

API 12

**变更发生版本**

从OpenHarmony SDK 5.0.0.56开始。

**变更的接口/组件**

@ComponentV2的freezeWhenInactive接口。

**适配指导**

当子组件使用了组件冻结，父组件没有使用组件冻结的情况下，当组件处于inactive时，子组件组件冻结功能生效。示例如下：

页面A：

```ts
import { router } from '@kit.ArkUI';

@ObservedV2
export class Book {
  @Trace name: string = "100";

  constructor(page: string) {
    this.name = page;
  }
}

export let book: Book = new Book("Pilgrimage to the West");

@Entry
@ComponentV2
export struct FirstTest {
  build() {
    Column() {
      Child()
    }
  }
}

@ComponentV2({ freezeWhenInactive: true })
export struct Child {
  @Local bookTest: Book = new Book("A Midsummer Night’s Dream");

  @Monitor("book.name")
  onMessageChange(monitor: IMonitor) {
    console.log(`The book name change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }

  textUpdate(): number{
    console.log("The text is update");
    return 50;
  }

  build() {
    Column() {
      Text(`The Monitor book name is  ${this.bookTest.name}`).fontSize(50)
      Text(`The text book name is  ${book.name}`).fontSize(this.textUpdate())
      Button('go to next page').fontSize(30)
        .onClick(() => {
          router.pushUrl({ url: 'pages/Page' });
          setTimeout(function() {
            this.book = new Book("Jane Austen oPride and Prejudice");
          }, 1000);
        })
    }
  }
}
```

页面B：

```ts
import { router } from '@kit.ArkUI';
import { book } from './Index';

@Entry
@ComponentV2
struct SecondTest {
  build() {
    Column() {
      Text(`This is the page`).fontSize(50)
      Button('Back')
        .onClick(() => {
          router.back();
        })
      Button('Change the book name')
        .onClick(() => {
          book.name = "The Old Man and the Sea";
        })
    }
  }
}
```


在上面的用例中，页面A的子组件Child，开启了组件冻结功能，当点击Button跳转到页面B的时候，修改状态变量bookTest，因为Child组件开启了组件冻结，状态变量将不响应更新，即@Monitor不会调用，状态变量关联的节点不会刷新。同理，修改状态变量book，也不会触发刷新。

如果开发者不关注freezeWhenInactive的功能，只是加了这个标签，会发现变更前页面还会刷新，也会有对应的回调，变更后，就不回调了。如果还想触发回调，建议不使用组件冻结功能。示例如下：


页面A：

```ts
import { router } from '@kit.ArkUI';

@ObservedV2
export class Book {
  @Trace name: string = "100";

  constructor(page: string) {
    this.name = page;
  }
}

export let book: Book = new Book("Pilgrimage to the West");

@Entry
@ComponentV2
export struct FirstTest {
  build() {
    Column() {
      Child()
    }
  }
}

@ComponentV2
export struct Child {
  @Local book: Book = new Book("A Midsummer Night’s Dream");

  @Monitor("book.name")
  onMessageChange(monitor: IMonitor) {
    console.log(`The book name change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }

  build() {
    Column() {
      Text(`The Monitor book name is  ${this.book.name}`).fontSize(50)
      Text(`The text book name is  ${book.name}`).fontSize(50)
      Button('go to next page').fontSize(30)
        .onClick(() => {
          router.pushUrl({ url: 'pages/Page' });
          setTimeout(function() {
            this.book = new Book("Jane Austen oPride and Prejudice");
          }, 1000);

        })
    }
  }
}
```

页面B：

```ts
import { router } from '@kit.ArkUI';
import { book } from './Index';

@Entry
@ComponentV2
struct SecondTest {
  build() {
    Column() {
      Text(`This is the page`).fontSize(50)
      Button('Back')
        .onClick(() => {
          router.back();
        })
      Button('Change the book name')
        .onClick(() => {
          book.name = "The Old Man and the Sea";
        })
    }
  }
}
```

当子组件Child不使用组件冻结功能时，跳转到页面B，修改状态变量将响应更新，@Monitor被调用，状态变量关联的节点将会刷新。

## cl.arkui.2 当AttributeModifer的applyNormalAttribute方法中instance参数设置为资源类型数据时更新的行为发生变更

**访问级别**

公开接口

**变更原因**

当开发者使用资源文件作为AttributeModifer的applyNormalAttribute方法中instance对象的入参时，无法通过配置资源文件更新参数，该行为与系统资源的规格不一致。

**变更影响**

该变更为不兼容变更。

运行以下示例时:

```ts
class MyButtonModifier implements AttributeModifier<ButtonAttribute> {
  private color?: ResourceColor;
  private fontColor?: ResourceColor;

  constructor(color: ResourceColor, fontColor: ResourceColor) {
    this.color = color;
    this.fontColor = fontColor;
  }

  applyNormalAttribute(instance: ButtonAttribute): void {
    // instance为Button的属性对象，设置正常状态下属性值
    instance.backgroundColor(this.color)
      .fontColor(this.fontColor)
      .borderWidth(1)
  }
}

@Entry
@Component
struct attributeDemo {
  @State modifier: MyButtonModifier = new MyButtonModifier($r('app.color.backColor'), $r('app.color.fontColor'));

  build() {
    Row() {
      Column() {
        Button("Button")
          .attributeModifier(this.modifier)
      }.width("100%")
    }
    .height('100%')
    .backgroundColor(Color.White)
  }
}
```

```json
// src/main/resources/base/element/color.json
{
  "color": [
    {
      "name": "start_window_background",
      "value": "#FFFFFF"
    },
    {
      "name": "backColor",
      "value": "#000000"
    },
    {
      "name": "fontColor",
      "value": "#FFFFFF"
    }
  ]
}
```

```json
// src/main/resources/dark/element/color.json
{
  "color": [
    {
      "name": "start_window_background",
      "value": "#000000"
    },
    {
      "name": "backColor",
      "value": "#FFFFFF"
    },
    {
      "name": "fontColor",
      "value": "#000000"
    }
  ]
}
```

| 变更前                                                                                                                     | 变更后                                                                                                                   |
| -------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------ |
| 浅色模式拉起。使用资源文件作为入参，切换深浅色时，无法使用资源文件触发UI的更新。<br>![light_mode](figures/light_mode1.jpg) | 浅色模式拉起。使用资源文件作为入参，切换深浅色时，可以使用资源文件触发UI的更新。<br>![dark_mode](figures/dark_mode1.jpg) |
|                                                                                                                            |

**起始API Level**

API 11

**变更发生版本**

从OpenHarmony SDK 5.0.0.56开始。

**变更的接口/组件**

common.d.ts文件attributeModifier接口。

**适配指导**

默认行为变更，无需适配，但应注意变更后的行为是否对整体应用逻辑产生影响。

如不期望资源随配置文件更新可以将资源取出后使用。

```ts
class MyButtonModifier implements AttributeModifier<ButtonAttribute> {
  public  color?: ResourceColor;
  public fontColor?: ResourceColor;

  constructor(color: ResourceColor, fontColor: ResourceColor) {
    this.color = color;
    this.fontColor = fontColor;
  }

  applyNormalAttribute(instance: ButtonAttribute): void {
    // instance为Button的属性对象，设置正常状态下属性值
    instance.backgroundColor(this.color)
      .fontColor(this.fontColor)
      .borderWidth(1)
  }
}

@Entry
@Component
struct attributeDemo {
  @State modifier: MyButtonModifier = new MyButtonModifier($r('app.color.backColor'), $r('app.color.fontColor'));

  aboutToAppear(): void {
    // 解析获取资源文件。
    this.modifier.color = getContext().resourceManager.getColorSync($r('app.color.backColor').id);
    this.modifier.fontColor = getContext().resourceManager.getColorSync($r('app.color.fontColor').id);
  }

  build() {
    Row() {
      Column() {
        Button("Button")
          .attributeModifier(this.modifier)
      }.width("100%")
    }
    .height('100%')
    .backgroundColor(Color.White)
  }
}
```

浅色模式拉起：

切换深浅色时，UI不更新。

![light_mode](figures/light_mode1.jpg)

深色模式拉起：

切换深浅色时，UI不更新。

![dark_mode](figures/dark_mode1.jpg)
