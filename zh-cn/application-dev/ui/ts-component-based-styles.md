# @Styles



@Styles装饰器将新的属性函数添加到基本组件上，如Text、Column、Button等。当前@Styles仅支持通用属性。通过@Styles装饰器可以快速定义并复用组件的自定义样式。

@Styles可以定义在组件内或组件外，在组件外定义时需带上function关键字，组件内定义时不需要。


```
@Styles function globalFancy() {
  .backgroundColor(Color.Red)
}

@Entry
@Component
struct FancyUse {
  @Styles componentFancy() {
    .backgroundColor(Color.Blue)
  }
  build() {
    Column({ space: 10 }) {
      Text("Fancy")
        .globalFancy()
        .width(100)
        .height(100)
        .fontSize(30)
      Text("Fancy")
        .componentFancy()
        .width(100)
        .height(100)
        .fontSize(30)
    }
  }
}
```

@Styles还可以在[StateStyles](../reference/arkui-ts/ts-universal-attributes-polymorphic-style.md)属性内部使用，在组件处于不同的状态时赋予相应的属性。

在StateStyles内可以直接调用组件外定义的Styles，但需要通过this关键字调用组件内定义的Styles。

```
@Styles function globalFancy() {
  .width(100)
  .height(100)
}

@Entry
@Component
struct FancyUse {
  @Styles componentFancy() {
    .width(50)
    .height(50)
  }
  build() {
    Row({ space: 10 }) {
      Button() {
      	Text("Fancy")
      }
      .stateStyles({
      	normal: {
      	  .width(80)
      	  .height(80)
      	},
      	disabled: this.componentFancy,
      	pressed: globalFancy
      })
    }
  }
}
```

