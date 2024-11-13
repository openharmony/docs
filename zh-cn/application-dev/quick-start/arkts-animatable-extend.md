# \@AnimatableExtend装饰器：定义可动画属性

@AnimatableExtend装饰器用于自定义可动画的属性方法，在这个属性方法中修改组件不可动画的属性。在动画执行过程时，通过逐帧回调函数修改不可动画属性值，让不可动画属性也能实现动画效果。也可通过逐帧回调函数每帧修改可动画属性的值，实现逐帧布局的效果。

- 可动画属性：如果一个属性方法在animation属性前调用，改变这个属性的值可以生效animation属性的动画效果，这个属性称为可动画属性。比如height、width、backgroundColor、translate属性，Text组件的fontSize属性等。

- 不可动画属性：如果一个属性方法在animation属性前调用，改变这个属性的值不能生效animation属性的动画效果，这个属性称为不可动画属性。比如Polyline组件的points属性等。

>  **说明：**
>
>  该装饰器从API Version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> 从API version 11开始，该装饰器支持在原子化服务中使用。

## 装饰器使用说明


### 语法


```ts
@AnimatableExtend(UIComponentName) function functionName(value: typeName) { 
  .propertyName(value)
}
```

- \@AnimatableExtend仅支持定义在全局，不支持在组件内部定义。
- \@AnimatableExtend定义的函数参数类型必须为number类型或者实现 AnimatableArithmetic\<T\>接口的自定义类型。
- \@AnimatableExtend定义的函数体内只能调用\@AnimatableExtend括号内组件的属性方法。

### AnimatableArithmetic\<T\>接口说明
对复杂数据类型做动画，需要实现AnimatableArithmetic\<T\>接口中加法、减法、乘法和判断相等函数。
| 名称 | 入参类型 | 返回值类型 | 说明
| -------- | -------- |-------- |-------- |
| plus | AnimatableArithmetic\<T\> | AnimatableArithmetic\<T\> | 加法函数 |
| subtract | AnimatableArithmetic\<T\> | AnimatableArithmetic\<T\> | 减法函数 |
| multiply | number | AnimatableArithmetic\<T\> | 乘法函数 |
| equals | AnimatableArithmetic\<T\> | boolean | 相等判断函数 |

## 使用场景

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
          this.textWidth = this.textWidth == 80 ? 160 : 80;
        })
    }.width("100%")
    .padding(10)
  }
}
```
![image](figures/AnimatableProperty.gif)


以下示例实现折线的动画效果。  


```ts
class Point {
  x: number
  y: number

  constructor(x: number, y: number) {
    this.x = x
    this.y = y
  }
  plus(rhs: Point): Point {
    return new Point(this.x + rhs.x, this.y + rhs.y)
  }
  subtract(rhs: Point): Point {
    return new Point(this.x - rhs.x, this.y - rhs.y)
  }
  multiply(scale: number): Point {
    return new Point(this.x * scale, this.y * scale)
  }
  equals(rhs: Point): boolean {
    return this.x === rhs.x && this.y === rhs.y
  }
}

class PointVector extends Array<Point> implements AnimatableArithmetic<PointVector> {
  constructor(value: Array<Point>) {
    super();
    value.forEach(p => this.push(p))
  }
  plus(rhs: PointVector): PointVector {
    let result = new PointVector([])
    const len = Math.min(this.length, rhs.length)
    for (let i = 0; i < len; i++) {
      result.push((this as Array<Point>)[i].plus((rhs as Array<Point>)[i]))
    }
    return result
  }
  subtract(rhs: PointVector): PointVector {
    let result = new PointVector([])
    const len = Math.min(this.length, rhs.length)
    for (let i = 0; i < len; i++) {
      result.push((this as Array<Point>)[i].subtract((rhs as Array<Point>)[i]))
    }
    return result
  }
  multiply(scale: number): PointVector {
    let result = new PointVector([])
    for (let i = 0; i < this.length; i++) {
      result.push((this as Array<Point>)[i].multiply(scale))
    }
    return result
  }
  equals(rhs: PointVector): boolean {
    if (this.length != rhs.length) {
      return false
    }
    for (let i = 0; i < this.length; i++) {
      if (!(this as Array<Point>)[i].equals((rhs as Array<Point>)[i])) {
        return false
      }
    }
    return true
  }
  get(): Array<Object[]> {
    let result: Array<Object[]> = []
    this.forEach(p => result.push([p.x, p.y]))
    return result
  }
}

@AnimatableExtend(Polyline) function animatablePoints(points: PointVector) {
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
        .animation({duration: 1000, curve: Curve.Ease})
        .size({height:220, width:300})
        .fill(Color.Green)
        .stroke(Color.Red)
        .backgroundColor('#eeaacc')
      Button("Play")
        .onClick(() => {
          this.points = new PointVector([
            new Point(50, Math.random() * 200),
            new Point(100, Math.random() * 200),
            new Point(150, Math.random() * 200),
            new Point(200, Math.random() * 200),
            new Point(250, Math.random() * 200),
          ])
        })
    }.width("100%")
    .padding(10)
  }
}
```
![image](figures/animatable-points.gif)