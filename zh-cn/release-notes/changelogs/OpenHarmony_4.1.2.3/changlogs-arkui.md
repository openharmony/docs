#  arkui子系统ChangeLog

## cl.arkui.1 系统组件父子校验

从API version11开始，当`Blank`，`FlowItem`，`GridItem`，`GridCol`，`ListItem`，`ListItemGroup`，`Option`，`Span`，`StepperItem`，`TabContent`组件的父组件不是限定组件时，编译报错。

**示例：**

```
@Entry
@Component
struct Index {
  build() {
    Button(){
      Blank()
    }
  }
}
```

**变更影响**

如果`Blank`，`FlowItem`，`GridItem`，`GridCol`，`ListItem`，`ListItemGroup`，`Span`，`StepperItem`，`TabContent`组件的父组件没有写在限定的组件中，编译报错 。父组件为`if`组件，`ForEach`组件，`LazyForEach`组件， `@Builder`修饰的方法中，编译不会报错。

```
// ArkTS:ERROR The 'Blank' component can only be nested in the 'Row,Column,Flex' parent component.
Button(){
      Blank()
    }
```

**关键的接口/组件变更**

不涉及。

**适配指导**

请查阅[Blank组件](../../../application-dev/reference/arkui-ts/ts-basic-components-blank.md)，[FlowItem组件](../../../application-dev/reference/arkui-ts/ts-container-flowitem.md)，[GridItem组件](../../../application-dev/reference/arkui-ts/ts-container-griditem.md)，[GridCol组件](../../../application-dev/reference/arkui-ts/ts-container-gridcol.md)，[ListItem组件](../../../application-dev/reference/arkui-ts/ts-container-listitem.md)，[ListItemGroup组件](../../../application-dev/reference/arkui-ts/ts-container-listitemgroup.md)，[Span组件](../../../application-dev/reference/arkui-ts/ts-basic-components-span.md)，[StepperItem组件](../../../application-dev/reference/arkui-ts/ts-basic-components-stepperitem.md)，[TabContent组件](../../../application-dev/reference/arkui-ts/ts-container-tabcontent.md)文档进行适配。

## cl.arkui.2 Flex组件wrap模式尺寸约束属性constraintSize生效变更

从API version 11开始，当Flex组件wrap模式下使用属性constraintSize可以正常对交叉轴约束生效。

**示例：**

```
@Entry
@Component
struct ClipExample1 {
  @State message: string = 'Hello World'
  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
        Flex({wrap:FlexWrap.Wrap}) {
          Text('1').height(50).backgroundColor(Color.Gray)
          Text('天天向上').height(50).backgroundColor(Color.Gray)
          Text('天天向上向上').height(50).backgroundColor(Color.Gray)
          Text('天天向上向上天天向上向上').height(50).backgroundColor(Color.Gray)
          Text('1天天向上向上').height(50).backgroundColor(Color.Gray)
          Text('1天天向上向上').height(50).backgroundColor(Color.Gray)
          Text('天天向上向上天天向上向上').height(50).backgroundColor(Color.Gray)
          Text('天天向上向上天天向上向上').height(50).backgroundColor(Color.Gray)
          Text('1').height(50).backgroundColor(Color.Gray)
          Text('1').height(50).backgroundColor(Color.Gray)
          Text('1').height(50).backgroundColor(Color.Gray)
        }
        .clip(true)
        .backgroundColor(Color.Orange)
        .constraintSize({
          minHeight: 50,
          maxHeight: 150
        })
      }
      .width('100%')
    }.height('100%').width(300)
  }
}
```

**变更影响**

变更前示例中Flex组件实际高度为200，没有受constraintSize中maxHeight约束，变更后constraintSize约束能正常生效，最小高度为50，最大高度为150，最大最小宽度约束同理可正常生效。

**适配指导**

若之前使用了wrap并且设置了constraintSize并未对Flex容器大小约束成功，API version 11及以上版本会正常生效，应用若不想要该约束则将constraintSize移除或调整约束数值。

## cl.arkui.3 Scroll组件currentOffset接口变更

**访问级别**

公开接口。

**变更原因**

currentOffset接口的返回值为any，不利于代码开发时的自动提示。

**变更影响**

该变更为非兼容性变更，Scroll组件中currentOffset接口的返回值由any变更为OffsetResult。

**API Level**

11

**变更发生版本**

从OpenHarmony SDK 4.1.2.3开始。

**变更的接口/组件**

API version 10前 ，currentOffset接口的返回值为any：
```
currentOffset();
```

API version 11及以后，currentOffset接口的返回值为OffsetResult：
```
currentOffset() : OffsetResult;
```

**适配指导**

不涉及
