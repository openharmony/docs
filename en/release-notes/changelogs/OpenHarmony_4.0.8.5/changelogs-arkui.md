# ArkUI Subsystem Changelog

## cl.arkui.1 Change in the Priority of alignContent and align Attributes for \<Stack>

Changed the priority of **alignContent** and **align** as follows:

API version 9 and earlier: The universal attribute **align** prevails.

API version 10 and later: The last set attribute prevails.

When two attributes provide the same functions, the last set attribute takes effect. This rule applies to **alignContent** and **align**, both of which set the alignment mode when used for the **\<Stack>** component.

**Example**

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

API version 9 and earlier: Child components are arranged based on the universal attribute **align**.

![stack](figures/api9.png)


API version 10 and later: Child components are arranged based on the **alignContent** attribute, which is set at a later time than **align**.

![stack](figures/api10_and_later.png)

**Change Impact**

When both **alignContent** and **align** attributes are set, the last set attribute prevails.
