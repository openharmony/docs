# ArkUI子系统Changelog

## cl.arkui.1 带标题栏窗口应用内菜单弹出位置变更

**访问级别**

公开接口

**变更原因**

对于带标题栏窗口使用非子窗的Menu组件场景，菜单默认弹出位置调整，UX体验更佳。


**变更影响**

该变更为不兼容变更。

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

## cl.arkui.2 MenuItem设置padding属性时默认布局行为变更

**访问级别**

公开接口

**变更原因**

优化MenuItem添加padding时布局效果，变更后效果更佳。

**变更影响**

该变更为不兼容变更。

变更前：MenuItem设置padding属性时，布局和预期不符合。

变更后：MenuItem设置padding属性时，布局符合预期。

```ts
@Entry
@Component
struct Index {
  @Builder
  MenuWithPadding() {
    Menu() {
      MenuItemGroup() {
        MenuItem({content:"top bottom padding is 20vp"})
          .padding({top:20, bottom: 20})
          .borderWidth(2)
          .borderColor(Color.Black)
        MenuItem({content:"top padding is 20vp"})
          .padding({top:20})
          .borderWidth(2)
          .borderColor(Color.Black)
        MenuItem({content:"bottom padding is 20vp"})
          .padding({bottom: 20})
          .borderWidth(2)
          .borderColor(Color.Black)
      }
    }
  }

  build() {
    Column() {
      Button("菜单")
        .bindMenu(this.MenuWithPadding)
    }
    .width('100%')
  }
}
```

| 变更前 | 变更后 |
|---------|---------|
|  ![变更前](figures/item-padding-before.png)       |  ![变更后](figures/item-padding-after.png)       |

**起始API Level**

API 7

**变更发生版本**

从OpenHarmony SDK 5.1.0.45 版本开始。

**变更的接口/组件**

MenuItem组件。

**适配指导**

MenuItem设置padding属性时默认布局效果变更，开发者无需适配。

## cl.arkui.3 DatePickerDialog和TimePickerDialog调用show()方法，参数缺省时的行为变更

**访问级别**

公开接口

**变更原因**

DatePickerDialog和TimePickerDialog调用show()方法，若参数缺省，无法弹出对话框。该参数为可选参数，会对开发者造成困惑。

**变更影响**

该变更为不兼容变更。

举例说明，执行以下用例：

```ts
@Entry
@Component
struct PickerDialogExample {
  build() {
    Column() {
      Button("DatePickerDialog")
        .onClick(() => {
          DatePickerDialog.show()
        })

      Button("TimePickerDialog")
        .margin(20)
        .onClick(() => {
          TimePickerDialog.show()
        })
    }
  }
}
```

变更前:  
DatePickerDialog.show()和TimePickerDialog.show()无法弹出日期选择器对话框。 

变更后:  
DatePickerDialog.show()和TimePickerDialog.show()可以弹出日期选择器对话框。

**起始API Level**

API 8

**变更发生版本**

从OpenHarmony 5.1.0.45开始。

**变更的接口/组件**

TimePickerDialog和DatePickerDialog组件。

**适配指导**

DatePickerDialog和TimePickerDialog调用show()方法，参数缺省时，可弹出默认样式的对话框。

## cl.arkui.4 Gauge设置第一个颜色占比过小时绘制效果更改

**访问级别**

公开接口

**变更原因**

Gauge设置第一个颜色占比过小时绘制效果不符合UX效果。

**变更影响**

该变更为不兼容变更。

| 变更前                                                                                                                     | 变更后                                                                                                                   |
| -------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------ |
| 设置第一个颜色占比过小时，第一个圆环未被正确裁切，出现逆时针向0的方向绘制的情况。<br>![gauge_before](figures/gauge_before.png)| 设置第一个颜色占比过小时，第一个圆环绘制正常，能被正常裁切。<br>![gauge_after](figures/gauge_after.png) |

**起始API Level**

11

**变更发生版本**

从OpenHarmony 5.1.0.45 版本开始。

**变更的接口/组件**

Gauge。

**适配指导**

展示效果变更，无需适配，但应注意变更后的效果是否符合开发者预期。

## cl.arkui.5 Repeat VirtualScroll 支持二级缓存冻结

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

## cl.arkui.5 通用属性backgroundEffect在modifier中radius参数单位修改

**访问级别**

公开接口

**变更原因**

 直接使用backgroundEffect时对应的模糊参数radius单位为vp。通过modifier或者CAPI使用时，单位为px。现将单位同一为vp。

**变更影响**

该变更为不兼容变更。

变更前：backgroundEffect通过modifier使用时单位为px。<br/>
![addComponentContent_before](figures/backgroundEffect_before.png)

变更后：backgroundEffect通过modifier使用时单位为vp。<br/>
![addComponentContent_after](figures//backgroundEffect_after.png)



**起始API Level**

API 12

**变更发生版本**

从OpenHarmony 5.1.0.45 版本开始。

**变更的接口/组件**

backgroundEffect

**适配指导**

在modifier中使用px2vp方法把radius参数转换为vp。

```ts

import { CommonModifier } from '@kit.ArkUI';

class ColumnModifier extends CommonModifier {
  public radius: number = 0;
  applyNormalAttribute(instance: CommonAttribute): void {
    instance.backgroundEffect({ radius: this.radius })
  }
}

@Entry
@Component
struct Index {
  @State testSize: number = 200;
  @State modifier:ColumnModifier = new ColumnModifier();
  onPageShow(): void {
    // 变更前
    // this.modifier.radius = 10;
    // 变更后适配
    this.modifier.radius = px2vp(10);
  }
  build() {
    Column() {
      Stack() {
        Image($r('app.media.test')).width(this.testSize).height(this.testSize)
        Column().width(this.testSize).height(this.testSize).attributeModifier(this.modifier)
      }.width('100%')
    }
  }
}
```
