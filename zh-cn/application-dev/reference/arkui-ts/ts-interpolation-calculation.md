# 插值计算

> **说明：**
> 从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 导入模块

```js
import curves from '@ohos.curves'
```


## 权限

无


## curves.init

init(curve?: Curve): Object


插值曲线的初始化函数，可以根据入参创建一个插值曲线对象。


- 参数
  | 参数名   | 类型    | 必填   | 默认值    | 说明    |
  | ----- | ----- | ---- | ------ | ----- |
  | curve | Curve | 否    | Linear | 曲线对象。 |

- 返回值<br>
  曲线对象Object。


## curves.steps

steps(count: number, end: boolean): Object


构造阶梯曲线对象。


- 参数
  | 参数名   | 类型      | 必填   | 默认值  | 说明                                       |
  | ----- | ------- | ---- | ---- | ---------------------------------------- |
  | count | number  | 是    | -    | 阶梯的数量，需要为正整数。                            |
  | end   | boolean | 是    | true | 在每个间隔的起点或是终点发生阶跃变化&nbsp;，默认值为true，即在终点发生阶跃变化。 |

- 返回值<br>
  曲线对象Object。


## curves.cubicBezier

cubicBezier(x1: number, y1: number, x2: number, y2: number): Object


构造三阶贝塞尔曲线对象，曲线的值必须处于0-1之间。


- 参数
  | 参数名  | 类型     | 必填   | 说明             |
  | ---- | ------ | ---- | -------------- |
  | x1   | number | 是    | 确定贝塞尔曲线第一点横坐标。 |
  | y1   | number | 是    | 确定贝塞尔曲线第一点纵坐标。 |
  | x2   | number | 是    | 确定贝塞尔曲线第二点横坐标。 |
  | y2   | number | 是    | 确定贝塞尔曲线第二点纵坐标。 |

- 返回值<br>
  曲线对象Object。


## curves.spring

spring(velocity: number, mass: number, stiffness: number, damping: number): Object


构造弹簧曲线对象。


- 参数
  | 参数名       | 类型     | 必填   | 说明    |
  | --------- | ------ | ---- | ----- |
  | velocity  | number | 是    | 初始速度。 |
  | mass      | number | 是    | 质量。   |
  | stiffness | number | 是    | 刚度。   |
  | damping   | number | 是    | 阻尼。   |

- 返回值<br>
  曲线对象Object。


## 示例

```ts
import Curves from '@ohos.curves'
let curve1 = Curves.init() // 创建一个默认线性插值曲线
let curve2 = Curves.init(Curve.EaseIn) // 创建一个默认先慢后快插值曲线
let curve3 = Curves.spring(100, 1, 228, 30) // 创建一个弹簧插值曲线
let curve3 = Curves.cubicBezier(0.1, 0.0, 0.1, 1.0) // 创建一个三阶贝塞尔曲线
```


曲线对象只能通过上面的接口创建。
| 接口名称                                     | 功能描述                                     |
| ---------------------------------------- | ---------------------------------------- |
| interpolate(time:&nbsp;number):&nbsp;number | 插值曲线的插值计算函数，可以通过传入的归一化时间参数返回当前的插值。<br/>time:&nbsp;当前的归一化时间参数，有效值范围0到1。<br/>返回归一化time时间点对应的曲线插值。 |


- 示例
  ```ts
  import Curves from '@ohos.curves'
  let curve = Curves.init(Curve.EaseIn) // 创建一个默认先慢后快插值曲线
  let value: number = curve.interpolate(0.5) // 计算得到时间到一半时的插值
  ```


## 整体示例

```ts
// xxx.ets
import Curves from '@ohos.curves'
@Entry
@Component
struct ImageComponent {
  @State widthSize: number = 200
  @State heightSize: number = 200
  build() {
    Column() {
      Text()
        .margin({top:100})
        .width(this.widthSize)
        .height(this.heightSize)
        .backgroundColor(Color.Red)
        .onClick(()=> {
          let curve = Curves.cubicBezier(0.25, 0.1, 0.25, 1.0);
        })
        .animation({duration: 2000 , curve: Curves.spring(0.25, 0.1, 0.25, 1.0)})
    }.width("100%").height("100%")
  }
}
```

![zh-cn_image_0000001174104410](figures/zh-cn_image_0000001174104410.gif)
