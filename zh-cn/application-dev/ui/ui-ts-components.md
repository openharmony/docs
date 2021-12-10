# 初识Component

在自定义组件之前，需要先了解什么是[组件和装饰器](#组件和装饰器)，并进行初始化组件。然后通过[修改组件属性和构造参数](#修改组件属性和构造参数)，实现一个自定义组件。


## 组件和装饰器

在声明式UI中，所有的页面都是由组件构成。组件的数据结构为struct，装饰器[@Component](../reference/arkui-ts/ts-component-based-component.md)是组件化的标志。用@Component修饰的struct表示这个结构体有了组件化的能力。

自定义组件的声明方式为：

```
@Component
struct MyComponent {}
```

在IDE创建工程模板中，MyComponent就是一个可以居中显示文字的自定义组件。开发者可以在Component的build方法里描述自己的UI结构，但需要遵循Builder的接口约束。

```
interface Builder {
    build: () => void
}
```

[@Entry](../reference/arkui-ts/ts-component-based-entry.md)修饰的Component表示该Component是页面的总入口，也可以理解为页面的根节点。值得注意的是，一个页面有且仅能有一个@Entry，只有被@Entry修饰的组件或者其子组件，才会在页面上显示。

@Component和@Entry都是基础且十分重要的装饰器。简单地理解，装饰器就是某一种修饰，给被装饰的对象赋予某一种能力，比如@Entry就是页面入口的能力，@Component就是组件化能力。

在了解了组件和装饰器这两个重要概念后，接下来可以开始开发健康饮食应用。


## 修改组件属性和构造参数

开发者创建系统组件时，会显示其默认样式。开发者可以通过更改组件的属性样式来改变组件的视图显示。

1. 修改Text组件的fontSize属性来更改组件的字体大小，将字体大小设置为26，fontWeight字体的粗细为500。fontWeight支持两种设置方式：
   1. number类型的取值范围为100到900，默认为400，取值越大，字体越粗。
   2. fontWeight为内置枚举类型，取值支持Lighter、Normal、Bold、Bolder。

   属性方法要紧随组件，通过“.”运算符连接，也可以通过链式调用的方式配置组件的多个属性。

   ```
   @Entry
   @Component
   struct MyComponent {
       build() {
           Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
               Text('Hello World')
                   .fontSize(26)
                   .fontWeight(500)
           }
           .width('100%')
           .height('100%')
       }
   }
   ```

   ![zh-cn_image_0000001168728272](figures/zh-cn_image_0000001168728272.png)

2. 修改Text组件的显示内容“Hello World”为“Tomato”，通过修改Text组件的构造参数来实现。
   ```
   @Entry
   @Component
   struct MyComponent {
       build() {
           Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
               Text('Tomato')
                   .fontSize(26)
                   .fontWeight(500)
           }
           .width('100%')
           .height('100%')
       }
   }
   ```

   ![zh-cn_image_0000001168888224](figures/zh-cn_image_0000001168888224.png)
