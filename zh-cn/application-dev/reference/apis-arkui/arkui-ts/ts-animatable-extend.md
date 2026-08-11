# @AnimatableExtend：定义可动画属性
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hehongyang3-->
<!--Designer: @hehongyang3-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->

@AnimatableExtend装饰器用于自定义可动画的属性方法，该装饰器内定义的函数需要配合[animation](ts-animatorproperty.md#animation)属性使用，且必须在animation属性前调用，改变该属性值时才能使animation属性的动画效果生效。在动画过程中该函数会被逐帧调用，直到动画结束。该装饰器的常见用途有：

1. 使不可动画属性变为可动画属性，自定义数据运算规则使得属性能进行插值运算（即在动画起始值与终止值之间，按一定规则计算每一帧的中间值），再由动画驱动属性从起点值逐渐过渡到终点值。

2. 使属性逐帧变化，实现逐帧布局的效果。

- 可动画属性：属性方法在animation属性前调用时，改变该属性的值可使animation属性的动画效果生效，产生动画过渡效果。例如height、width、backgroundColor、translate属性，以及Text组件的fontSize属性等。

- 不可动画属性：属性方法在animation属性前调用时，改变该属性的值不能使animation属性的动画效果生效，属性突变无动画过渡效果。例如Polyline组件的points属性等。

>  **说明：**
>
> - 该装饰器从API version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本模块接口仅可在Stage模型下使用。
>
> - 使用@AnimatableExtend装饰的属性方法时，该方法需在同一组件的animation属性之前调用，动画过渡效果才能生效。

## 语法

```ts
@AnimatableExtend(UIComponentName) function functionName(value: typeName) { 
  .propertyName(value)
}
```

- \@AnimatableExtend仅支持定义在全局，不支持在组件内部定义。
- \@AnimatableExtend定义的函数参数类型必须为number类型或者实现 AnimatableArithmetic\<T\>接口的自定义类型。
- \@AnimatableExtend定义的函数体内只能调用\@AnimatableExtend括号内组件的属性方法。
- \@AnimatableExtend定义的函数必须在animation属性之前调用，才能使动画效果生效。若在animation属性之后调用或未配合animation属性使用，属性值变化时不会有动画过渡效果，而是直接突变到目标值。

## AnimatableArithmetic\<T\>

该接口定义非number数据类型的动画运算规则。对非number类型的数据（如数组、结构体、颜色等）做动画，需要实现AnimatableArithmetic\<T\>接口中加法、减法、乘法和判断相等函数，使得该数据能参与动画的插值运算和识别该数据是否发生改变。即定义它们为实现了AnimatableArithmetic\<T\>接口的类型。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### plus

plus(rhs: AnimatableArithmetic\<T\>): AnimatableArithmetic\<T\>

定义该数据类型的加法运算规则。需与AnimatableArithmetic\<T\>接口的其他方法一同实现，才能使自定义数据类型参与动画的插值运算。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型                                | 必填 | 说明                                    |
| ----- | --------------------------------- | ---- | ------------------------------------- |
| rhs | [AnimatableArithmetic\<T\>](#animatablearithmetict) | 是    | 与自身进行加法运算的另一个数据对象，应与当前对象为相同的具体类型实例。                           |

**返回值：**

| 类型                                       | 说明      |
| ---------------------------------------- | ------- |
| [AnimatableArithmetic\<T\>](#animatablearithmetict) | 加法运算的结果，用于动画插值过程中计算两个数据之间的中间值。  |

### subtract

subtract(rhs: AnimatableArithmetic\<T\>): AnimatableArithmetic\<T\>

定义该数据类型的减法运算规则，在动画插值运算中用于计算起始值与目标值之间的差值，差值将作为乘法运算的输入。需与AnimatableArithmetic\<T\>接口的其他方法一同实现，才能使自定义数据类型参与动画的插值运算。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型                                | 必填 | 说明                                    |
| ----- | --------------------------------- | ---- | ------------------------------------- |
| rhs | [AnimatableArithmetic\<T\>](#animatablearithmetict) | 是    | 与自身进行减法运算的另一个数据对象，应与当前对象为相同的具体类型实例。                           |

**返回值：**

| 类型                                       | 说明      |
| ---------------------------------------- | ------- |
| [AnimatableArithmetic\<T\>](#animatablearithmetict) | 减法运算的结果，用于动画插值过程中计算数据差值以得到中间帧数据。  |

### multiply

multiply(scale: number): AnimatableArithmetic\<T\>

定义该数据类型的乘法运算规则，在动画插值运算中用于按动画进度比例（0到1之间）对差值进行缩放，缩放后的差值将通过plus运算加到起始值上。需与AnimatableArithmetic\<T\>接口的其他方法一同实现，才能使自定义数据类型参与动画的插值运算。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型                                | 必填 | 说明                                    |
| ----- | --------------------------------- | ---- | ------------------------------------- |
| scale | number | 是    | 乘法运算的系数，取值范围为[0, +∞)，动画插值时典型取值范围为[0, 1]。                           |

**返回值：**

| 类型                                       | 说明      |
| ---------------------------------------- | ------- |
| [AnimatableArithmetic\<T\>](#animatablearithmetict) | 乘法运算的结果，用于动画插值过程中按系数缩放数据以计算中间帧数据。  |

### equals

equals(rhs: AnimatableArithmetic\<T\>): boolean

定义该数据类型的相等判断规则，在动画过程中用于识别数据是否发生改变，若当前值与目标值相等则不再触发动画过渡。需与AnimatableArithmetic\<T\>接口的其他方法一同实现，才能使自定义数据类型参与动画的插值运算。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型                                | 必填 | 说明                                    |
| ----- | --------------------------------- | ---- | ------------------------------------- |
| rhs | [AnimatableArithmetic\<T\>](#animatablearithmetict) | 是    | 与当前对象判断是否相等的另一个数据对象。                          |

**返回值：**

| 类型                                       | 说明      |
| ---------------------------------------- | ------- |
| boolean | 是否相等。返回true表示相等，返回false表示不相等。  |

## 示例

### 示例1（逐帧布局的效果）

以下示例通过改变Text组件宽度实现逐帧布局的效果。

```ts
@AnimatableExtend(Text)
function animatableWidth(width: number) {
  .width(width)
}

@Entry
@Component
struct AnimatablePropertyExample {
  @State textWidth: number = 80;

  build() {
    Column() {
      Text("AnimatableProperty")
        .animatableWidth(this.textWidth)
        .animation({ duration: 2000, curve: Curve.Ease })
      Button("Play")
        .onClick(() => {
          this.textWidth = this.textWidth === 80 ? 160 : 80;
        })
    }.width("100%")
    .padding(10)
  }
}
```

![animatableExtend](figures/AnimatableProperty.gif)

### 示例2（折线的动画效果）

以下示例实现折线的动画效果。

```ts
class Point {
  x: number
  y: number

  constructor(x: number, y: number) {
    this.x = x;
    this.y = y;
  }

  plus(rhs: Point): Point {
    return new Point(this.x + rhs.x, this.y + rhs.y);
  }

  subtract(rhs: Point): Point {
    return new Point(this.x - rhs.x, this.y - rhs.y);
  }

  multiply(scale: number): Point {
    return new Point(this.x * scale, this.y * scale);
  }

  equals(rhs: Point): boolean {
    return this.x === rhs.x && this.y === rhs.y;
  }
}

// PointVector实现了AnimatableArithmetic<T>接口
class PointVector extends Array<Point> implements AnimatableArithmetic<PointVector> {
  constructor(value: Array<Point>) {
    super();
    value.forEach(point => this.push(point));
  }

  plus(rhs: PointVector): PointVector {
    let result = new PointVector([]);
    const len = Math.min(this.length, rhs.length);
    for (let i = 0; i < len; i++) {
      result.push((this as Array<Point>)[i].plus((rhs as Array<Point>)[i]));
    }
    return result;
  }

  subtract(rhs: PointVector): PointVector {
    let result = new PointVector([]);
    const len = Math.min(this.length, rhs.length);
    for (let i = 0; i < len; i++) {
      result.push((this as Array<Point>)[i].subtract((rhs as Array<Point>)[i]));
    }
    return result;
  }

  multiply(scale: number): PointVector {
    let result = new PointVector([]);
    for (let i = 0; i < this.length; i++) {
      result.push((this as Array<Point>)[i].multiply(scale));
    }
    return result;
  }

  equals(rhs: PointVector): boolean {
    if (this.length !== rhs.length) {
      return false;
    }
    for (let i = 0; i < this.length; i++) {
      if (!(this as Array<Point>)[i].equals((rhs as Array<Point>)[i])) {
        return false;
      }
    }
    return true;
  }

  get(): Array<Object[]> {
    let result: Array<Object[]> = [];
    this.forEach(point => result.push([point.x, point.y]));
    return result;
  }
}

@AnimatableExtend(Polyline)
function animatablePoints(points: PointVector) {
  // 将PointVector转换为Polyline的points属性所需的数组格式
  .points(points.get())
}

@Entry
@Component
struct AnimatablePropertyExample {
  @State points: PointVector = new PointVector([
    new Point(50, Math.random() * 200),
    new Point(100, Math.random() * 200),
    new Point(150, Math.random() * 200),
    new Point(200, Math.random() * 200),
    new Point(250, Math.random() * 200),
  ])

  build() {
    Column() {
      Polyline()
        .animatablePoints(this.points)
        .animation({ duration: 1000, curve: Curve.Ease }) // 设置动画参数
        .size({ height: 220, width: 300 })
        .fill(Color.Green)
        .stroke(Color.Red)
        .backgroundColor('#eeaacc')
      Button("Play")
        .onClick(() => {
          // points是实现了可动画协议的数据类型，points在动画过程中可按照定义的运算规则、动画参数从之前的PointVector变为新的PointVector数据，产生每一帧的PointVector数据，进而产生动画
          this.points = new PointVector([
            new Point(50, Math.random() * 200),
            new Point(100, Math.random() * 200),
            new Point(150, Math.random() * 200),
            new Point(200, Math.random() * 200),
            new Point(250, Math.random() * 200),
          ]);
        })
    }.width("100%")
    .padding(10)
  }
}
```
![image](figures/animatable-points.gif)
