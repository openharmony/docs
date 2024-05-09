#  ArkUI Subsystem Changelog

## cl.arkui.1 System Component Parent-Child Verification

Since API version 11, if the parent component of the following components is not as expected, a compilation error is reported: \<Blank>, \<FlowItem>, \<GridItem>, \<GridCol>, \<ListItem>, \<ListItemGroup>, \<Option>, \<Span>, \<StepperItem>, and \<TabContent>

**Example**

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

**Change Impact**

The parent component of the following components must be within **if**, **ForEach**, **LazyForEach**, or a method decorated by @Builder: \<Blank>, \<FlowItem>, \<GridItem>, \<GridCol>, \<ListItem>, \<ListItemGroup>, \<Option>, \<Span>, \<StepperItem>, and \<TabContent>. Otherwise, an error is reported during compilation.

```
// ArkTS:ERROR The 'Blank' component can only be nested in the 'Row,Column,Flex' parent component.
Button(){
      Blank()
    }
```

**Key API/Component Changes**

N/A

**Adaptation Guide**

For details, see [\<Blank>](../../../application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-blank.md), [\<FlowItem>](../../../application-dev/reference/apis-arkui/arkui-ts/ts-container-flowitem.md), [\<GridItem>](../../../application-dev/reference/apis-arkui/arkui-ts/ts-container-griditem.md), [\<GridCol>](../../../application-dev/reference/apis-arkui/arkui-ts/ts-container-gridcol.md), [\<ListItem>](../../../application-dev/reference/apis-arkui/arkui-ts/ts-container-listitem.md), [\<ListItemGroup>](../../../application-dev/reference/apis-arkui/arkui-ts/ts-container-listitemgroup.md), \<Option>, [\<Span>](../../../application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-span.md), [\<StepperItem>](../../../application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-stepperitem.md), and [\<TabContent>](../../../application-dev/reference/apis-arkui/arkui-ts/ts-container-tabcontent.md).

## cl.arkui.2 Change of constraintSize Effectiveness for the \<Flex> Component in wrap Mode

Since API version 11, the **constraintSize** attribute takes effect on the cross axis when the **\<Flex>** component is in wrap mode.

**Example**

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
          Text ('Seize the day').height (50).backgroundColor (Color.Gray)
          Text ('Seize the day and').height (50).backgroundColor (Color.Gray)
          Text('Seize the day and make every moment count').height(50).backgroundColor(Color.Gray)
          Text ('Seize the moment and make every').height (50).backgroundColor (Color.Gray)
          Text ('Seize the day and').height (50).backgroundColor (Color.Gray)
          Text('Seize the day and make every moment count').height(50).backgroundColor(Color.Gray)
          Text('Seize the day and make every moment count').height(50).backgroundColor(Color.Gray)
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

**Change Impact**

Before the change, the height of the **\<Flex>** component is 200, which is not restricted by **maxHeight** in **constraintSize**. After the change, **constraintSize** settings take effect, with the minimum height of 50 and the maximum height of 150. The maximum and minimum width constraints take effect in the same way.

**Adaptation Guide**

If **wrap** is used and **constraintSize** is set on the **\<Flex>** component in previous versions, the settings should take effect. If the constraint is not required, remove **constraintSize** or adjust the constraint value.

## cl.arkui.3 Change in the currentOffset API of the \<Scroll> Component

**Access Level**

Public

**Reason for Change**

The original return value **any** of the **currentOffset** API is inconvenient for intelligent code completion.

**Change Impact**

This change is a non-compatible change. The return value of the **currentOffset** API is changed from **any** to **OffsetResult**.

**API Level**

11

**Change Since**

OpenHarmony SDK 4.1.2.3

**Key API/Component Changes**

In versions earlier than API version 10, the return value of the **currentOffset** API is **any**.
```
currentOffset();
```

Since API version 11, the return value of the **currentOffset** API is **OffsetResult**.
```
currentOffset() : OffsetResult;
```

**Adaptation Guide**

N/A
