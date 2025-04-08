# ArkUI子系统Changelog

## cl.arkui.1 带标题栏窗口应用内菜单弹出位置变更

**访问级别**

公开接口

**变更原因**

对于带标题栏窗口使用非子窗的Menu组件场景，菜单默认弹出位置调整，UX体验更佳。


**变更影响**

此变更不涉及应用适配。

变更前：带标题栏窗口应用内弹出菜单位置偏移4vp，菜单没有和按钮对齐。

变更后：带标题栏窗口应用内弹出菜单位置正确，菜单和按钮对齐。

| 变更前 | 变更后 |
|---------|---------|
|  ![变更前](figures/menu-item-4vp-before.png)       |  ![变更后](figures/menu-item-4vp-after.png)       |

**起始API Level**

API 11

**变更发生版本**

从OpenHarmony SDK 5.1.0.45开始。

**变更的接口/组件**

Menu组件。

**适配指导**

Menu UX默认效果变更，无需适配，但应注意变更后的默认效果是否符合开发者预期，如不符合则应自定义修改效果控制变量以达到预期。

## cl.arkui.2 Repeat VirtualScroll 支持二级缓存冻结

**访问级别**

公开接口

**变更原因**

开发者使用Repeat VirtualScroll，进入二级缓存（复用池）中的组件是为了通过更新其各项属性后作为新组件使用，在更新成为新组件之前不应该被刷新。

**变更影响**

此变更不涉及应用适配。

变更前：启用组件冻结，状态变量改动会触发二级缓存中的组件刷新，并执行@Monitor对应方法。 

变更后：启用组件冻结，状态变量改动不会触发二级缓存中的组件刷新，不执行@Monitor对应方法。

举例说明，执行以下用例：

```ts
@Entry
@ComponentV2
struct RepeatVirtualScrollDemo {
  @Local simpleList: Array<string> = [];
  @Local bgColor: Color = Color.Pink;

  aboutToAppear(): void {
    for (let i = 0; i < 7; i++) {
      this.simpleList.push(`item${i}`);
    }
  }

  build() {
    Column() {
      Row() {
        Button(`Reduce length to 5`)
          .onClick(() => {
            this.simpleList = this.simpleList.slice(0, 5);
          })
        Button(`Change bgColor`)
          .onClick(() => {
            this.bgColor = this.bgColor == Color.Pink ? Color.Blue : Color.Pink;
          })
      }

      List() {
        Repeat(this.simpleList)
          .each((obj: RepeatItem<string>) => {
          })
          .key((item: string, index: number) => item)
          .virtualScroll({ totalCount: this.simpleList.length })
          .templateId(() => `a`)
          .template(`a`, (ri) => {
            ChildComponent({
              message: ri.item,
              bgColor: this.bgColor
            })
          }, { cachedCount: 2 })
      }
      .cachedCount(0)
      .height(500)
    }
    .height(`100%`)
  }
}

@ComponentV2({ freezeWhenInactive: true })
struct ChildComponent {
  @Param @Require message: string;
  @Param @Require bgColor: Color;
  // 支持后二级缓存中的组件不刷新，不会打印相应日志
  @Monitor(`bgColor`)
  onMessageChange(monitor: IMonitor) {
    monitor.dirty.forEach((path: string) => {
      console.log(`repeat---${path} change from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`)
    })
  }

  build() {
    Text(`[a]: ${this.message}`)
      .fontSize(50)
      .backgroundColor(this.bgColor)
  }
}
```

**起始API Level**

12

**变更发生版本**

从OpenHarmony 5.1.0.45 版本开始。

**变更的接口/组件**

Repeat freezeWhenInactive。

**适配指导**

展示效果不变，@Monitor监听属性变化执行方法次数会减少。如果需要刷新缓存中的数据，可以关闭组件冻结。

```ts
// 关闭组件冻结，freezeWhenInactive设置为false
@ComponentV2({ freezeWhenInactive: false })
struct ChildComponent {
  @Param @Require message: string;
  @Param @Require bgColor: Color;
  // 关闭冻结后，二级缓存中的组件会刷新，并打印相应日志
  @Monitor(`bgColor`)
  onMessageChange(monitor: IMonitor) {
    monitor.dirty.forEach((path: string) => {
      console.log(`repeat---${path} change from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`)
    })
  }

  build() {
    Text(`[a]: ${this.message}`)
      .fontSize(50)
      .backgroundColor(this.bgColor)
  }
}
```

在API version 18中，同时优化了组件冻结以下功能特性的行为表现：

- 在组件冻结开启之后，明确了节点解冻的范围，子组件的非屏上节点不会再被父组件解冻，例子可见[Navigation和TabContent的混用](../../../application-dev/quick-start/arkts-custom-components-freeze.md#navigation和tabcontent的混用)。

- 在状态管理V2组件冻结从父组件激活冻结状态的场景中，如果仅子组件开启了冻结，父组件未开启冻结，子组件也能冻结。例子可见[仅子组件开启组件冻结](../../../application-dev/quick-start/arkts-custom-components-freezeV2.md#仅子组件开启组件冻结)。

## cl.arkui.3 ImageSpan组件borderRadius边框圆角属性Modifier设置变更

**访问级别**

公开接口

**变更原因**

ImageSpan组件的borderRadius边框圆角属性通过Modifier设置不生效，边框实际不显示圆角效果。

**变更影响**

此变更不涉及应用适配。

| 变更前                                                                                           | 变更后                                                                                    |
| ----------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------ |
| ImageSpan组件borderRadius边框圆角属性通过Modifier设置不生效。<br>![imageSpan-border-radius-before](figures/imageSpan-border-radius-before.png)| ImageSpan组件borderRadius边框圆角属性通过Modifier设置生效。<br>![imageSpan-border-radius-after](figures/imageSpan-border-radius-after.png) |

**起始API Level**

ImageSpanModifier ： 12

**变更发生版本**

从OpenHarmony SDK 5.1.0.45开始。

**变更的接口/组件**

ImageSpanModifier接口的borderRadius属性

**适配指导**

无需应用适配，变更后ImageSpan组件的borderRadius边框圆角在Modifier接口设置生效，效果与开发者实际设置的圆角值显示一致。

## cl.arkui.4 Search组件回车键类型为EnterKeyType.NEW_LINE（换行）时onSubmit回调中执行keepEditableState()函数，参数缺省时的行为变更

**访问级别**

公开接口

**变更原因**

开发者通过Search组件的onSubmit接口设置自定义提交事件，并在keepEditableState()函数中配置是否收起键盘。当回车键类型设置为EnterKeyType.NEW_LINE（换行）时，无论是否设置keepEditableState()接口，用户点击输入法软键盘上的换行按钮或按下回车键，键盘均不会收起。

**变更影响**

此变更不涉及应用适配。

变更前：回车键类型为EnterKeyType.NEW_LINE（换行），不设置keepEditableState()接口，用户点击输入法软键盘上的换行按钮或按下回车键，Search组件保持编辑态。

变更后：回车键类型为EnterKeyType.NEW_LINE（换行），不设置keepEditableState()接口，用户点击输入法软键盘上的换行按钮或按下回车键，Search组件退出编辑态。

**起始API Level**

12

**变更发生版本**

从OpenHarmony 5.1.0.45 版本开始。

**变更的接口/组件**

onSubmit事件keepEditableState()接口

**适配指导**

使用Search组件onSubmit接口设置自定义提交事件。触发onSubmit时，如果回车键类型为EnterKeyType.NEW_LINE（换行）且未设置keepEditableState()接口，键盘退出编辑态。举例说明：

```ts
import { SymbolGlyphModifier } from '@kit.ArkUI'

@Entry
@Component
struct EnterKeyTypeIsNewLineDemo {
  mySearchController: SearchController = new SearchController()

  build() {
    Column() {
      Text('Search').fontSize(25).fontColor(Color.Blue)
      Search({ value: '', placeholder: 'Type to search ...', controller: this.mySearchController })
        .searchIcon(new SymbolGlyphModifier($r('sys.symbol.magnifyingglass')).fontColor([Color.Red]))
        .searchButton('SEARCH')
        // 回车键类型设置为EnterKeyType.NEW_LINE（换行）
        .enterKeyType(EnterKeyType.NEW_LINE)
        .onSubmit((value: string, event?: SubmitEvent) => {
          // 设置键盘保持编辑态，否则，默认情况键盘退出编辑态
          event?.keepEditableState()
        })
    }.width('100%').margin({ top: 100 })
  }
}
```

## cl.arkui.5 TextInput/TextArea组件border属性dashGap、dashWidth参数Modifier设置变更

**访问级别**

公开接口

**变更原因**

TextInput/TextArea组件的border属性中，虚线参数dashGap和dashWidth通过Modifier设置后未生效。当前TextInput/TextArea组件的实际虚线边框显示为默认效果，而非Modifier设置的值。

**变更影响**

此变更不涉及应用适配。

| 变更前                                                                                           | 变更后                                                                                      |
| ----------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------- |
| TextInput/TextArea组件的border属性中，虚线参数dashGap和dashWidth通过Modifier设置后未生效。![textInput-textArea-border-dash-before](figures/textInput-textArea-border-dash-before.png)| TextInput/TextArea组件的border属性中，虚线参数dashGap和dashWidth通过Modifier设置后生效。![textInput-textArea-border-dash-after](figures/textInput-textArea-border-dash-after.png) |

**起始API Level**

TextInputModifier ：12

TextAreaModifier ：12

**变更发生版本**

从OpenHarmony SDK 5.1.0.45开始。

**变更的接口/组件**

TextInputModifier、TextAreaModifier接口的border属性dashGap、dashWidth参数

**适配指导**

无需应用适配，变更后TextInput/TextArea组件的border属性虚线参数dashGap、dashWidth通过Modifier设置生效，显示虚线边框间距和长度效果与开发者设置值一致。
