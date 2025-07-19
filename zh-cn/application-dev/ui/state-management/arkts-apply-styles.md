# applyStyles：定义组件重用样式（ArkTS-ST）

如果每个组件的样式都需要单独设置，在开发过程中会出现大量代码在进行重复样式设置，虽然可以复制粘贴，但为了代码简洁性和后续方便维护，我们推出了可以提炼公共样式进行复用的方法applyStyles。


方法applyStyles将多条样式设置提炼成一个Styles方法，直接在组件声明的位置调用。通过applyStyles可以快速定义并复用自定义样式。

> **说明：**
>
> 本模块仅适用于ArkTS-ST。

## 导入模块

```ts
import { applyStyles } from '@ohos.arkui.component';
```

### 语法

```ts
function applyStyles<T extends CommoMethod>(this: T, styleMethod: (instance: CommonMethod) => void): T;
```

## 使用说明

- 首先定义入参为CommonMethod并且无返回值的方法来设置想要复用的组件属性，该方法后续称为Styles方法。然后在声明组件时通过调用applyStyles传入Styles方法，施加属性到该UI组件上。

- 当前applyStyles仅支持[通用属性](../../reference/apis-arkui/arkui-ts/ts-component-general-attributes.md)和[通用事件](../../reference/apis-arkui/arkui-ts/ts-component-general-events.md)。

- Styles方法可以定义在组件内或全局，在全局定义时需在方法名前面添加function关键字，组件内定义时则不需要添加function关键字。请参考用例[组件内Styles方法和全局Styles方法的用法](#组件内styles方法和全局styles方法的用法)。

- 定义在组件内的Styles方法可以通过this访问组件的常量和状态变量，并可以在Styles方法里通过事件来改变状态变量的值，示例如下：

  ```ts
  import { ClickEvent, Color, Component, CommonMethod } from '@ohos.arkui.component';
  import { State } from '@ohos.arkui.stateManagement';

  @Component
  struct FancyUse {
    @State heightValue: number = 100;
    // 声明Styles方法
    fancy(instance: CommonMethod) {
      instance.height(this.heightValue);
      instance.backgroundColor(Color.Yellow);
      instance.onClick((e: ClickEvent) => {
        this.heightValue = 200;
      });
    }
  }
  ```

## 限制条件

> **说明：**
>
> ArkTS-ST去除了Styles方法只能在当前文件内使用，不支持export的限制。
> ArkTS-ST去除了不能在Styles方法中使用逻辑组件的限制。


- Styles方法不能有参数，编译期会报错。

  ```ts
  // 错误写法： Styles方法不支持参数，编译期报错
  function globalFancy (instance: CommonMethod, value: number) {
    instance.width(value);
  }

  // 正确写法
  function globalFancy (instance: CommonMethod) {
    instance.widthhan'shulue);
  }
  ```

## 使用场景

### 组件内Styles方法和全局Styles方法的用法

```ts
import { ClickEvent, Color, Column, CommonMethod, Component, Entry, Text, applyStyles } from '@ohos.arkui.component';
import { State } from '@ohos.arkui.stateManagement';

// 定义在全局的Styles方法
function globalFancy  (instance: CommonMethod) {
  instance.width(150);
  instance.height(100);
  instance.backgroundColor(Color.Pink);
}

@Entry
@Component
struct FancyUse {
  @State heightValue: number = 100;
  // 定义在组件内的Styles方法
  fancy(instance: CommonMethod) {
    instance.width(200);
    instance.height(this.heightValue);
    instance.backgroundColor(Color.Yellow);
    instance.onClick((e: ClickEvent) => {
      this.heightValue = 200;
    });
  }

  build() {
    Column() {
      // 使用全局的Styles方法
      Text('FancyA')
        .applyStyles(globalFancy)
        .fontSize(30)
      // 使用组件内的Styles方法
      Text('FancyB')
        .applyStyles(this.fancy)
        .fontSize(30)
    }
  }
}
```
