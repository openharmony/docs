# advanced.Counter
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @xieziang-->
<!--Designer: @youzhi92-->
<!--Tester: @TerryTsao-->
<!--Adviser: @HelloCrease-->

Counter组件用于精确调节数值。

>  **说明：**
>
>  该组件从API Version 11开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
>  如果Counter设置[通用属性](ts-component-general-attributes.md)和[通用事件](ts-component-general-events.md)，编译工具链会额外生成节点__Common__，并将通用属性或通用事件挂载在__Common__上，而不是直接应用到Counter本身。这可能导致开发者设置的通用属性或通用事件的效果不生效或不符合预期，因此，不建议Counter设置通用属性和通用事件。

## 导入模块

```
import { CounterType, CounterComponent, CounterOptions, DateData } from '@kit.ArkUI';
```

## 子组件

无

## CounterComponent

CounterComponent({&nbsp;options:&nbsp;CounterOptions&nbsp;})

定义Counter。

**装饰器类型：**@Component

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数**：

| 名称   | 类型                              | 必填 | 装饰器类型 | 说明                    |
| ------- | --------------------------------- | ---- | ---------- | ----------------------- |
| options | [CounterOptions](#counteroptions) | 是   | @Prop      | 定义Counter组件的类型。 |

## CounterOptions

CounterOptions定义Counter类型及样式。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称        | 类型       | 必填 | 说明                            |
| ----------- | ---------- | ---- | ------------------------------- |
| type | [CounterType](#countertype) | 是   | 指定当前Counter的类型。 |
| direction<sup>12+</sup> | [Direction](ts-appendix-enums.md#direction) | 否 | 布局方向。<br/>默认值：Direction.Auto |
| numberOptions | [NumberStyleOptions](#numberstyleoptions) | 否    | 列表型和紧凑型Counter的式样。<br>默认值：显示计数器为0的列表型或紧凑型Counter。 |
| inlineOptions | [InlineStyleOptions](#inlinestyleoptions) | 否 | 普通数字内联调节型Counter的式样。<br>默认值：显示计数器为0的普通数字内联调节型Counter。 |
| dateOptions | [DateStyleOptions](#datestyleoptions) | 否 | 日期型内联型Counter的式样。<br>默认值：显示0001/01/01的日期型内联型Counter。 |

选择不同的Counter类型，需要选择对应的Counter样式。

| counter类型             | counter式样        |
| ----------------------- | ------------------ |
| CounterType.LIST        | NumberStyleOptions |
| CounterType.COMPACT     | NumberStyleOptions |
| CounterType.INLINE      | InlineStyleOptions |
| CounterType.INLINE_DATE | DateStyleOptions   |

## CounterType

CounterType指定Counter类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称        | 值   | 说明                        |
| ----------- | ---- | --------------------------- |
| LIST        | 0    | 列表型Counter。             |
| COMPACT     | 1    | 紧凑型Counter。             |
| INLINE      | 2    | 普通数字内联调节型Counter。 |
| INLINE_DATE | 3    | 日期型内联型Counter。       |

## CommonOptions

CommonOptions定义了Counter的共通属性和事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称            | 类型                      | 必填 | 说明                                                         |
| --------------- | ------------------------- | ---- | ------------------------------------------------------------ |
| focusable       | boolean                   | 否   | 设置Counter是否可获焦。<br/>**说明：** <br/>该属性对列表型和紧凑型Counter生效。<br/>默认值：true<br/>true：Counter可获焦；false：Counter不可获焦。 |
| step            | number                    | 否   | 设置Counter的步长。<br/>取值范围：大于等于1的整数。<br/>默认值：1 |
| onHoverIncrease | (isHover: boolean) => void | 否   | 鼠标进入或退出Counter组件的增加按钮时触发该回调。<br/>isHover：表示鼠标是否悬浮在组件上，鼠标进入时为true，退出时为false。<br>默认值：不触发鼠标进入或退出Counter组件的增加按钮时的回调。 |
| onHoverDecrease | (isHover: boolean) => void | 否   | 鼠标进入或退出Counter组件的减小按钮时触发该回调。<br/>isHover：表示鼠标是否悬浮在组件上，进入时为true，离开时为false。<br>默认值：不触发鼠标进入或退出Counter组件的减小按钮时的回调。 |

## InlineStyleOptions

InlineStyleOptions定义了数值内联型Counter的属性和事件。

继承于[CommonOptions](#commonoptions)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称      | 类型                   | 必填 | 说明                                                   |
| --------- | ---------------------- | ---- | ------------------------------------------------------ |
| value     | number                 | 否   | 设置Counter的初始值。<br/>默认值：0<br>取值范围：[0, 999] |
| min       | number                 | 否   | 设置Counter的最小值。<br/>默认值：0<br>取值范围：(-∞, +∞) |
| max       | number                 | 否   | 设置Counter的最大值。<br/>默认值：999<br>取值范围：(-∞, +∞) |
| textWidth | number                 | 否   | 设置数值文本的宽度。<br/>默认值：自适应文本宽度。<br/>取值范围：[0, +∞)<br/>单位：vp |
| onChange  | (value: number) => void | 否   | 数值改变时，返回当前值。<br/>value：当前显示的数值。<br>默认值：数值改变时，不返回值。 |

## NumberStyleOptions

NumberStyleOptions定义了列表型和紧凑型Counter的属性和事件。

继承于[InlineStyleOptions](#inlinestyleoptions)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称            | 类型                                   | 必填 | 说明                                                         |
| --------------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| label           | [ResourceStr](ts-types.md#resourcestr) | 否   | 设置Counter的说明文本。<br>默认值：' '                       |
| onFocusIncrease | () => void                             | 否   | 当前Counter组件的增加按钮获取焦点时触发的回调。<br>默认值：不触发增加按钮获取焦点时的回调。 |
| onFocusDecrease | () => void                             | 否   | 当前Counter组件的减小按钮获取焦点时触发的回调。<br>默认值：不触发减少按钮获取焦点时的回调。 |
| onBlurIncrease  | () => void                             | 否   | 当前Counter组件的增加按钮失去焦点时触发的回调。<br>默认值：不触发增加按钮失去焦点时的回调。 |
| onBlurDecrease  | () => void                             | 否   | 当前Counter组件的减小按钮失去焦点时触发的回调。<br>默认值：不触发减少按钮失去焦点时的回调。 |

## DateStyleOptions

DateStyleOptions定义日期内联型Counter的属性和事件。

继承于[CommonOptions](#commonoptions)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称         | 类型                                | 必填 | 说明                                                      |
| ------------ | ----------------------------------- | ---- | --------------------------------------------------------- |
| year         | number                              | 否   | 设置日期内联型初始年份。<br/>默认值：1<br/>取值范围：[1, 5000] |
| month        | number                              | 否   | 设置日期内联型初始月份。<br/>默认值：1<br/>取值范围：[1, 12] |
| day          | number                              | 否   | 设置日期内联型初始日。<br/>默认值：1<br/>取值范围：[1, 31] |
| onDateChange | (date: [DateData](#datedata)) => void | 否   | 当日期改变时，返回当前日期。<br/>date：当前显示的日期值。 |

## DateData

DateData定义了日期通用属性和方法，包括年、月、日。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称  | 类型   | 只读 | 可选 | 说明                                                         |
| ----- | ------ | ---- | ---- | ------------------------------------------------------------ |
| year  | number | 否   | 否   | 设置日期内联型初始年份。<br/>默认值：1<br/>取值范围：[1, 5000] |
| month | number | 否   | 否   | 设置日期内联型初始月份。<br/>默认值：1<br/>取值范围：[1, 12] |
| day   | number | 否   | 否   | 设置日期内联型初始日。<br/>默认值：1<br/>取值范围：[1, 31]   |

### constructor

constructor(year: number, month: number, day: number)

DateData的构造函数用于初始化日期对象。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---------- | ------ |  ------ | ---------------------------- |
| year       | number |  是 | 设置日期内联型初始年份。     |
| month      | number |  是 | 设置日期内联型初始月份。     |
| day        | number |  是 | 设置日期内联型初始日。       |

### toString

toString(): string

以字符串格式返回当前日期值。格式为’YYYY-MM-DD'。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 当前日期值。 |

## 示例

### 示例1（列表型Counter）

该示例通过设置`type`为`CounterType.LIST`和配置`numberOptions`，实现了列表型Counter。

```ts
import { CounterType, CounterComponent } from '@kit.ArkUI';

@Entry
@Component
struct ListCounterExample {
  build() {
    Column() {
      //列表型Counter
      CounterComponent({
        options: {
          type: CounterType.LIST,
          numberOptions: {
            label: "价格",
            min: 0,
            value: 5,
            max: 10
          }
        }
      })
    }
  }
}
```

![listcounter](figures/listcounter.gif)

### 示例2（紧凑型Counter）

该示例通过设置`type`为`CounterType.COMPACT`和`numberOptions`，实现紧凑型Counter。

```ts
import { CounterType, CounterComponent } from '@kit.ArkUI';

@Entry
@Component
struct CompactCounterExample {
  build() {
    Column() {
      //紧凑型Counter
      CounterComponent({
        options: {
          type: CounterType.COMPACT,
          numberOptions: {
            label: "数量",
            value: 10,
            min: 0,
            max: 100,
            step: 10
          }
        }
      })
    }
  }
}
```

![compactcounter](figures/compactcounter.gif)

### 示例3（数值内联型Counter）

设置`type`为`CounterType.INLINE`和`inlineOptions`，实现数值内联型Counter。

```ts
import { CounterType, CounterComponent } from '@kit.ArkUI';

@Entry
@Component
struct NumberStyleExample {
  build() {
    Column() {
      //数值内联型Counter
      CounterComponent({
        options: {
          type: CounterType.INLINE,
          inlineOptions: {
            value: 100,
            min: 10,
            step: 2,
            max: 1000,
            textWidth: 100,
            onChange: (value: number) => {
              console.info('onCounterChange Counter: ' + value.toString());
            }
          }
        }
      })
    }
  }
}
```

![numberstyle](figures/numberstyle.gif)

### 示例4（日期内联型Counter）

设置`type`为`CounterType.INLINE_DATE`和`dateOptions`，实现日期内联型Counter。

```ts
import { CounterType, CounterComponent, DateData } from '@kit.ArkUI';

@Entry
@Component
struct DataStyleExample {
  build() {
    Column() {
      //日期内联型counter
      CounterComponent({
        options: {
          type: CounterType.INLINE_DATE,
          dateOptions: {
            year: 2016,
            onDateChange: (date: DateData) => {
              console.info('onDateChange Date: ' + date.toString());
            }
          }
        }
      })
    }
  }
}
```

![datestyle](figures/datestyle.gif)

### 示例5（镜像布局展示）

设置direction属性，实现列表型、紧凑型、数字内联型、日期内联型Counter的镜像布局。

```ts
import { CounterType, CounterComponent, DateData } from '@kit.ArkUI';

@Entry
@Component
struct CounterPage {
  @State currentDirection: Direction = Direction.Rtl

  build() {
    Column({}) {

      //列表型Counter
      CounterComponent({
        options: {
          direction: this.currentDirection,
          type: CounterType.LIST,
          numberOptions: {
            label: "价格",
            min: 0,
            value: 5,
            max: 10,
          }
        }
      })
        .width('80%')

      //数值型Counter
      CounterComponent({
        options: {
          direction: this.currentDirection,
          type: CounterType.COMPACT,
          numberOptions: {
            label: "数量",
            value: 10,
            min: 0,
            max: 100,
            step: 10
          }
        }
      }).margin({ top: 20 })

      //数值内联型Counter
      CounterComponent({
        options: {
          type: CounterType.INLINE,
          direction: this.currentDirection,
          inlineOptions: {
            value: 100,
            min: 10,
            step: 2,
            max: 1000,
            textWidth: 100,
            onChange: (value: number) => {
              console.info('onCounterChange Counter: ' + value.toString());
            }
          }
        }
      }).margin({ top: 20 })
      //日期内联型counter
      CounterComponent({
        options: {
          direction: this.currentDirection,
          type: CounterType.INLINE_DATE,
          dateOptions: {
            year: 2024,
            onDateChange: (date: DateData) => {
              console.info('onDateChange Date: ' + date.toString());
            }
          }
        }
      }).margin({ top: 20 })
    }
    .width('100%')
    .height('100%')
    .justifyContent(FlexAlign.Center)
    .alignItems(HorizontalAlign.Center)
  }
}
```

![datestyle](figures/counter_direction.png)
