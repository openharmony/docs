# 触摸测试控制
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @HelloCrease-->

设置组件的触摸测试类型。在ArkUI开发框架中，处理触屏事件时，会在触屏事件触发前进行按压点与组件区域的触摸测试，以收集需响应触屏事件的组件。基于测试结果，框架会分发相应的触屏事件。hitTestBehavior属性用于设置不同的触摸测试响应模式，影响触摸测试收集结果及后续触屏事件分发。具体影响参考[HitTestMode](./ts-appendix-enums.md#hittestmode9)枚举说明。

>  **说明：**
>  - 从API version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>  - 当Stack组件中有多个节点触摸区域重叠时，如两个节点，默认只会对显示在最上层的节点做触摸测试，若需要显示在下层的节点触发触摸测试，请给显示在上层的节点设置hitTestBehavior为HitTestMode.Transparent。

## hitTestBehavior

hitTestBehavior(value: HitTestMode): T

设置组件的触摸测试类型。如果组件不设置hitTestBehavior，其默认触摸测试类型为HitTestMode.Default。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名            | 类型     | 必填                             | 说明                               |
| -------------------- | -------- | ---------------------------------------- | ---------------------------------------- |
| value | [HitTestMode](./ts-appendix-enums.md#hittestmode9) | 是 | 设置当前组件的触摸测试类型。|

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回当前组件。 |

## 示例

### 示例1（触摸测试类型为Block和Transparent的触摸测试效果）

该示例通过设置不同的HitTestMode值演示了Block和Transparent的触摸测试效果。

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

### 示例2（触摸测试类型为BLOCK_HIERARCHY时的触摸测试效果）

该示例演示了设置触摸测试类型为BLOCK_HIERARCHY时的触摸测试效果。

```ts
// xxx.ets
@Entry
@Component
struct BlockHierarchy {
  build() {
    // outer stack
    Stack() {
      Stack() {
        Button('outer button')
          .onTouch((event) => {
            console.info('HitTestMode outer button touched type: ' + (event as TouchEvent).type);
          })
          .width(200)
          .height(200)
          .backgroundColor('#D5D5D5')
        // inner stack
        Stack() {
          Button()
            .id('button150')
            .backgroundColor('#F7F7F7')
            .width(150)
            .height(150)
            .onTouch((event) => {
              console.info('HitTestMode button150 touched type: ' + (event as TouchEvent).type);
            })
            .hitTestBehavior(HitTestMode.Transparent)
          Button()
            .id('button100')
            .backgroundColor('#707070')
            .width(100)
            .height(100)
            .onTouch((event) => {
              console.info('HitTestMode button100 touched type: ' + (event as TouchEvent).type);
            })
            .hitTestBehavior(HitTestMode.Transparent)
          Button()
            .id('button050')
            .backgroundColor('#D5D5D5')
            .width(50)
            .height(50)
            .onTouch((event) => {
              console.info('HitTestMode button050 touched type: ' + (event as TouchEvent).type);
            })
            .hitTestBehavior(HitTestMode.Transparent)
        }
        .width("100%").height("100%")
        // 设置触摸测试模式，自身和子节点响应触摸测试，阻止所有优先级较低的兄弟节点和父节点参与触摸测试
        .hitTestBehavior(HitTestMode.BLOCK_HIERARCHY)
        .onTouch((event) => {
          console.info('HitTestMode stack touched type: ' + (event as TouchEvent).type);
        })

        Text('Transparent')
          .hitTestBehavior(HitTestMode.Transparent)
          .width("100%").height("100%")
          .onTouch((event) => {
            console.info('HitTestMode text touched type: ' + (event as TouchEvent).type);
          })
      }.width(300).height(300)
      .borderWidth(2)
      .onTouch((event) => {
        console.info('HitTestMode father stack touched type: ' + (event as TouchEvent).type);
      })
    }.width(500).height(500)
    .borderWidth(2)
    .onTouch((event) => {
      console.info('HitTestMode grandfather stack touched type: ' + (event as TouchEvent).type);
    })
  }
}
```

### 示例3（触摸测试类型为BLOCK_DESCENDANTS时的触摸测试效果）

该示例演示了设置触摸测试类型为BLOCK_DESCENDANTS时的触摸测试效果。

```ts
// xxx.ets
@Entry
@Component
struct BlockDescendants {
  build() {
    // outer stack
    Stack() {
      Stack() {
        Button('outer button')
          .onTouch((event) => {
            console.info('HitTestMode outer button touched type: ' + (event as TouchEvent).type);
          })
          .width(200)
          .height(200)
          .backgroundColor('#D5D5D5')
        // inner stack
        Stack() {
          Button('inner button')
            .width(100)
            .height(100)
            .onTouch((event) => {
              console.info('HitTestMode inner button touched type: ' + (event as TouchEvent).type);
            })
        }
        .width("100%").height("100%")
        // 设置触摸测试模式，自身不响应触摸测试，并且所有的后代（孩子，孙子等）也不响应触摸测试
        .hitTestBehavior(HitTestMode.BLOCK_DESCENDANTS)
        .onTouch((event) => {
          console.info('HitTestMode stack touched type: ' + (event as TouchEvent).type);
        })

        Text('Transparent')
          .hitTestBehavior(HitTestMode.Transparent)
          .width("100%").height("100%")
          .onTouch((event) => {
            console.info('HitTestMode text touched type: ' + (event as TouchEvent).type);
          })
      }.width(300).height(300)
      .borderWidth(2)
      .onTouch((event) => {
        console.info('HitTestMode father stack touched type: ' + (event as TouchEvent).type);
      })
    }.width(500).height(500)
    .borderWidth(2)
    .onTouch((event) => {
      console.info('HitTestMode grandfather stack touched type: ' + (event as TouchEvent).type);
    })
  }
}
```