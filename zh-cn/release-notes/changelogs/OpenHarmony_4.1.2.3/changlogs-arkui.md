#  arkui子系统ChangeLog

## 系统组件父子校验

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

## Scroll组件中currentOffset接口的返回值由any变更为OffsetResult

**变更影响**

API version 10前 ，currentOffset接口的返回值为any，不利于在IDE中开发代码时自动提示。

API version 11及以后，currentOffset接口的返回值为OffsetResult。