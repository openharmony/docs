# Function-with-Receiver：定义扩展组件样式（ArkTS-ST）

在前文的示例中，可以使用[applyStyles](arkts-apply-styles.md)用于样式的重用，在applyStyles的基础上，我们提供了Function-with-Receiver，用于扩展原生组件样式。


> **说明：**
>
> 本模块仅适用于ArkTS-ST。

## 装饰器使用说明


### 语法

如果是拓展Text组件样式，用户声明Function-with-Reciever函数的第一个入参需要名称为this，类型是TextAttribute。

```ts
function functionName(this: TextAttribute, ...): this { ... }
```

### 使用规则

- 和applyStyles不同，Function-with-Receiver支持封装指定组件的私有属性、私有事件和自身定义的全局方法。

  ```ts
  // Function-with-Receiver可以支持Text的私有属性fontColor
  function fancy (this: TextAttribute): this {
    this.fontColor(Color.Red);
    return this;
  }
  // superFancyText可以调用预定义的fancy
  function superFancyText(this: TextAttribute, size: number): this {
      this.fontSize(size);
      this.fancy();
      return this;
  }
  ```

- 和applyStyles不同，Function-with-Receiver方法支持参数，开发者可以在调用时传递参数，调用遵循TS方法传值调用。

  ```ts
  import { Color, Component, Entry, Row, Text, TextAttribute } from '@ohos.arkui.component';

  function fancy (this: TextAttribute, fontSize: number): this {
    this.fontColor(Color.Red);
    this.fontSize(fontSize);
    return this;
  }

  @Entry
  @Component
  struct FancyUse {
    build() {
      Row() {
        Text('Fancy')
          .fancy(16)
        Text('Fancy')
          .fancy(24)
      }
    }
  }
  ```

- Function-with-Receiver的返回值声明为this，可以用于链式调用。

  ```ts
  import { Color, Component, Entry, Row, Text, TextAttribute } from '@ohos.arkui.component';

  function fancySize (this: TextAttribute, fontSize: number): this {
    this.fontSize(fontSize);
    return this;
  }

  function fancyColor (this: TextAttribute): this {
    this.fontColor(Color.Red);
    return this;
  }

  @Entry
  @Component
  struct FancyUse {
    build() {
      Row() {
        Text('Fancy')
          .fancySize(16)
          .fancyColor() // 链式调用Function-with-Receiver
          .onClick((e) => { }) // 链式调用Text组件其他方法
      }
    }
  }
  ```

- Function-with-Receiver方法的参数可以为function，作为Event事件的句柄。

  ```ts
  import { ClickEvent, Color, Component, Entry, Row, Text, TextAttribute } from '@ohos.arkui.component';
  import { State } from '@ohos.arkui.stateManagement';

  function makeMeClick(this: TextAttribute, onClick: (e: ClickEvent) => void): this {
    this.backgroundColor(Color.Blue);
    this.onClick(onClick);
    return this;
  }

  @Entry
  @Component
  struct FancyUse {
    @State label: string = 'Hello World';

    onClickHandler() {
      this.label = 'Hello ArkUI';
    }

    build() {
      Row() {
        Text(`${this.label}`)
          .makeMeClick((e: ClickEvent) => { 
            this.onClickHandler();
          })
      }
    }
  }
  ```

- Function-with-Receiver的参数可以为[状态变量](arkts-state-management-overview.md)，当状态变量改变时，UI可以正常的被刷新渲染。

  ```ts
  import { ClickEvent, Color, Component, Entry, Row, Text, TextAttribute } from '@ohos.arkui.component';
  import { State } from '@ohos.arkui.stateManagement';

  function fancy (this: TextAttribute, fontSize: number): this {
    this.fontColor(Color.Red);
    this.fontSize(fontSize);
    return this;
  }

  @Entry
  @Component
  struct FancyUse {
    @State fontSizeValue: number = 20;
    build() {
      Row() {
        Text('Fancy')
          .fancy(this.fontSizeValue)
          .onClick((e: ClickEvent) => {
            this.fontSizeValue = 30;
          })
      }
    }
  }
  ```


## 限制条件

> **说明：**
>
> ArkTS-ST去除了扩展组件样式方法只能在当前文件内使用，不支持export的限制。

- 和applyStyles不同，Function-with-Receiver仅支持在全局定义，不支持在组件内部定义。

## 使用场景

以下示例声明了3个Text组件，每个Text组件均设置了fontStyle、fontWeight和backgroundColor样式。


```ts
import { Color, Component, Entry, FontStyle, Row, Text } from '@ohos.arkui.component';
import { State } from '@ohos.arkui.stateManagement';

@Entry
@Component
struct FancyUse {
  @State label: string = 'Hello World';

  build() {
    Row() {
      Text(`${this.label}`)
        .fontStyle(FontStyle.Italic)
        .fontWeight(100)
        .backgroundColor(Color.Blue)
      Text(`${this.label}`)
        .fontStyle(FontStyle.Italic)
        .fontWeight(200)
        .backgroundColor(Color.Pink)
      Text(`${this.label}`)
        .fontStyle(FontStyle.Italic)
        .fontWeight(300)
        .backgroundColor(Color.Orange)
    }.margin('20%')
  }
}
```

Function-with-Receiver将样式组合复用，使得代码更加简洁，增强可读性，示例如下。


```ts
import { Color, Component, FontStyle, Entry, Row, Text, TextAttribute } from '@ohos.arkui.component';
import { State } from '@ohos.arkui.stateManagement';

function fancyText(this: TextAttribute, weightValue: number, color: Color): this {
  this.fontStyle(FontStyle.Italic);
  this.fontWeight(weightValue);
  this.backgroundColor(color);
  return this;
}

@Entry
@Component
struct FancyUse {
  @State label: string = 'Hello World';

  build() {
    Row() {
      Text(`${this.label}`)
        .fancyText(100, Color.Blue)
      Text(`${this.label}`)
        .fancyText(200, Color.Pink)
      Text(`${this.label}`)
        .fancyText(300, Color.Orange)
    }.margin('20%')
  }
}
```
