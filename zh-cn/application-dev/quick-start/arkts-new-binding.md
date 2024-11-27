# !!语法：双向绑定
在状态管理V1中使用[$$](./arkts-two-way-sync.md)用于内置组件双向绑定。
在状态管理V2中，提供了归一处理，提供`!!`语法糖作为统一处理双向绑定语法。


>**说明：**
>
>`!!`语法从API version 12开始支持。
>

## 概述

`!!`双向绑定语法，是一个语法糖方便开发者实现数据双向绑定，用于初始化子组件的\@Param和\@Event。其中\@Event方法名需要声明为“$”+ \@Param属性名，详见[使用场景](#使用场景)。

- 如果父组件使用了`!!`双向绑定语法，则表明父组件的变化会同步给子组件，子组件的变化也会同步给父组件。
- 如果父组件没有使用`!!`，则父组件发生的变化是单向的。


## 使用限制
`!!`双向绑定语法不支持多层父子组件传递。


## 使用场景

### 自定义组件间双向绑定
1. Index中构造Star子组件，双向绑定父子组件中的value，初始化子组件的`@Param value`和`@Event $value`
- 双向绑定语法糖可视为：

    ```
    Star({ value: this.value, $value: (val: number) => { this.value = val }})
    ```
2. 点击改变Index中的Button，改变value，父组件Index和子组件Star中Text更新。
3. 点击改变子组件Star中的Button，调用`this.$value(10)`，父组件Index和子组件Star中Text更新。

```ts
@Entry
@ComponentV2
struct Index {
  @Local value: number = 0;

  build() {
    Column() {
      Text(`${this.value}`)
      Button(`change value`).onClick(() => {
        this.value++;
      })
      Star({ value: this.value!! })
    }
  }
}


@ComponentV2
struct Star {
  @Param value: number = 0;
  @Event $value: (val: number) => void = (val: number) => {};

  build() {
    Column() {
      Text(`${this.value}`)
      Button(`change value `).onClick(() => {
        this.$value(10);
      })
    }
  }
}
```