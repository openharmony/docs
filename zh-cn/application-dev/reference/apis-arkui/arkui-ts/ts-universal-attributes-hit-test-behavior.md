# 触摸测试控制

设置组件的触摸测试类型。ArkUI开发框架在处理触屏事件时，会在触屏事件触发前，进行按压点和组件区域的触摸测试来收集需要响应触屏事件的组件，然后基于触摸测试结果分发相应的触屏事件。hitTestBehavior属性可以设置不同的触摸测试响应模式，影响组件的触摸测试收集结果，最终影响后续的触屏事件分发，具体影响参考[HitTestMode](#hittestmode枚举说明)枚举说明。

>  **说明：**
>  - 从API Version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>  - 当Stack组件中有多个节点触摸区域重叠时，如两个节点，默认只会对显示在最上层的节点做触摸测试，若需要显示在下层的节点触发触摸测试，请给显示在上层的节点设置hitTestBehavior为HitTestMode.Transparent。

## hitTestBehavior

hitTestBehavior(value: HitTestMode)

设置组件的触摸测试类型。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名            | 类型     | 必填                             | 说明                               |
| -------------------- | -------- | ---------------------------------------- | ---------------------------------------- |
| value | [HitTestMode](#hittestmode枚举说明) | 是 | 设置当前组件的触摸测试类型。<br>默认值： HitTestMode.Default |

## HitTestMode枚举说明

| 名称          | 枚举值    | 描述                                       |
| ------------| ---------|----------------------------------- |
| Default     | 0 |默认触摸测试效果，自身和子节点都响应触摸测试，但会阻塞兄弟节点的触摸测试。不会影响祖先节点的触摸测试。 |
| Block       | 1 |自身响应触摸测试，阻塞子节点和兄弟节点的触摸测试。会阻塞祖先节点的触摸测试。 |
| Transparent | 2 |自身和子节点都响应触摸测试，不会阻塞兄弟节点的触摸测试。不会影响祖先节点的触摸测试。 |
| None        | 3 |自身不响应触摸测试，不会阻塞子节点和兄弟节点的触摸测试。不会影响祖先节点的触摸测试。 |


## 示例

Text组件设置hitTestBehavior为HitTestMode.Transparent，不会阻塞内层Stack的触摸测试，因此Text和内层Stack的onTouch事件都会触发。  
内层Stack设置hitTestBehavior为HitTestMode.Block，会阻塞子节点和外层Button进行触摸测试，因此内层Button和外层Button组件不会响应onTouch事件。

```ts
// xxx.ets
@Entry
@Component
struct HitTestBehaviorExample {
  build() {
    // outer stack
    Stack() {
      Button('outer button')
        .onTouch((event) => {
          console.info('outer button touched type: ' + (event as TouchEvent).type)
        })
      // inner stack
      Stack() {
        Button('inner button')
          .onTouch((event) => {
            console.info('inner button touched type: ' + (event as TouchEvent).type)
          })
      }
      .width("100%").height("100%")
      .hitTestBehavior(HitTestMode.Block)
      .onTouch((event) => {
        console.info('stack touched type: ' + (event as TouchEvent).type)
      })

      Text('Transparent')
        .hitTestBehavior(HitTestMode.Transparent)
        .width("100%").height("100%")
        .onTouch((event) => {
          console.info('text touched type: ' + (event as TouchEvent).type)
        })
    }.width(300).height(300)
  }
}
```