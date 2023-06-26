# arkui子系统ChangeLog

## cl.arkui.1 stack组件alignContent属性和通用属性align生效顺序。

**说明**
属性之间的处理原则：如果功能相同，属性按覆盖处理即后设置的生效。alignContent和align功能相同，都是子组件在stack容器组件的对齐方式。

**示例：**
```ts
// xxx.ets
@Entry
@Component
struct StackExample {
  build() {
    Stack({alignContent:Alignment.Start}){
      Text("Stack's child").backgroundColor(Color.Brown).height("100").width(100)
    }
    .width(300).height(300)
    .backgroundColor(Color.Pink)
    .align(Alignment.Center)
    .alignContent(Alignment.TopEnd)
  }
}
```

api9：子组件按照通用属性align布局

![stack](figures/api9.png)


api10及以后：子组件按照后设置的alignContent布局

![stack](figures/api10_and_later.png)

**变更影响**

alignContent和align都设置时，api9版本及以前是align生效，api10及以后是后设置的生效。
