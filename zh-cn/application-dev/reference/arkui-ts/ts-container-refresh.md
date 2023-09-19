# Refresh

 可以进行页面下拉操作并显示刷新动效的容器组件。 

>  **说明：**
>
>  该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
>  当设置自定义组件时，自定义组件的高度限制在64vp之内。

## 子组件

支持单个子组件。

## 接口

Refresh\(value: \{ refreshing: boolean, offset?:  number&nbsp;|&nbsp;string , friction?: number | string, builder?: Custombuilder\}\)

**参数：**

| 参数         | 参数名                                      | 必填   | 参数描述                                     |
| ---------- | ---------------------------------------- | ---- | ---------------------------------------- |
| refreshing | boolean                                  | 是    | 当前组件是否正在刷新。<br/>该参数支持[$$](../../quick-start/arkts-two-way-sync.md)双向绑定变量。 |
| offset     | string&nbsp;\|&nbsp;number               | 否    | 下拉起点距离组件顶部的距离。<br/>默认值：16，单位vp <br/>**说明：**<br/>offset取值范围[0vp,64vp]。大于64vp按照64vp处理。不支持百分比，不支持负数 |
| friction   | number&nbsp;\|&nbsp;string               | 否    | 下拉摩擦系数，取值范围为0到100。<br/>默认值：62<br/>-&nbsp;0表示下拉刷新容器不跟随手势下拉而下拉。<br/>-&nbsp;100表示下拉刷新容器紧紧跟随手势下拉而下拉。<br/>-&nbsp;数值越大，下拉刷新容器跟随手势下拉的反应越灵敏。 |
| builder    | [CustomBuilder](ts-types.md#custombuilder8)<sup>10+</sup> | 否    | 下拉时，自定义刷新样式的组件。                          |

## 属性

支持[通用属性](ts-universal-attributes-size.md)。

## 事件

除支持[通用事件](ts-universal-events-click.md)外，还支持以下事件：


| 名称                                       | 描述                                     |
| ---------------------------------------- | -------------------------------------- |
| onStateChange(callback: (state: [RefreshStatus](#refreshstatus枚举说明)) => void) | 当前刷新状态变更时，触发回调。<br/>-&nbsp;state：刷新状态。 |
| onRefreshing(callback: () => void)       | 进入刷新状态时触发回调。                           |

## RefreshStatus枚举说明

| 名称       | 描述                   |
| -------- | -------------------- |
| Inactive | 默认未下拉状态。             |
| Drag     | 下拉中，下拉距离小于刷新距离。      |
| OverDrag | 下拉中，下拉距离超过刷新距离。      |
| Refresh  | 下拉结束，回弹至刷新距离，进入刷新状态。 |
| Done     | 刷新结束，返回初始状态（顶部）。     |


## 示例

```ts
// xxx.ets
@Entry
@Component
struct RefreshExample {
  @State isRefreshing: boolean = false
  @State counter: number = 0

  build() {
    Column() {
      Refresh({ refreshing: $$this.isRefreshing, offset: 120, friction: 100 }) {
        Text('Pull Down and refresh: ' + this.counter)
          .fontSize(30)
          .margin(10)
      }
      .onStateChange((refreshStatus: RefreshStatus) => {
        console.info('Refresh onStatueChange state is ' + refreshStatus)
      })
      .onRefreshing(() => {
        setTimeout(() => {
          this.counter++
          this.isRefreshing = false
        }, 1000)
        console.log('onRefreshing test')
      })
    }
  }
}
```

![](figures/refresh.gif)
