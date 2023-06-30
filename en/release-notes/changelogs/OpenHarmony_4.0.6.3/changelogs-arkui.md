# ArkUI Subsystem Changelog
Fixed the issue where the layout of child components in the [\<Stack>](../../../application-dev/reference/arkui-ts/ts-container-stack.md) container does not follow the **alignContent** settings when the child components do not fit in the container.

Example:

```ts
@Entry
@Component
struct StackExample {
  build() {
    Stack({alignContent:Alignment.TopEnd}){
      Text('First child, show in bottom')
        .width(200).height(200).backgroundColor(0xd2cab3).margin(10)
    }.width(150).height(150).backgroundColor(Color.Pink).margin(100)
  }
}
```
Before: Child components are not arranged based on **alignContent:Alignment.TopEnd**.

![stack](figures/stack_before.jpg)

After: Child components are arranged based on **alignContent:Alignment.TopEnd**.

![stack](figures/stack_after.jpg)


**Change Impact**

The previous workaround – setting the **Offset** or **translate** attribute – needs to be removed.

**Adaptation Guide**

Remove the **Offset** and **translate** settings for the child components and use **alignContent** for layout.
