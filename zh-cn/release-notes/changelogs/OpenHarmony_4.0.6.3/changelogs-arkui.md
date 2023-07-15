# ArkUI子系统ChangeLog
修复问题：[Stack](../../../application-dev/reference/arkui-ts/ts-container-stack.md)设置alignContent，在子组件超出父组件的场景中，子组件未按照alignContent布局
示例：
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
修复前：子组件未能按照alignContent:Alignment.TopEnd布局
![stack](figures/stack_before.jpg)

修复后：子组件可以按照alignContent:Alignment.TopEnd布局
![stack](figures/stack_after.jpg)


**变更影响**

1. 如果应用中有子组件大小大于父组件Stack的场景，需要应用进行适配。
2. 应用之前可能采用的规避方案：给子组件设置Offset或者translate

**适配指导**

  去掉之前给子组件设置的Offset或者translate，使用alignContent实际布局方式进行布局。