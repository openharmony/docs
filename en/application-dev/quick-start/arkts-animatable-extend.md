# \@AnimatableExtend Decorator: Definition of Animatable Attributes

The @AnimatableExtend decorator is used to define an attribute method for the non-animatable attribute of a component. During animation execution, a frame-by-frame callback is used to change the value of the non-animatable attribute so that an animation effect can be applied to the attribute. Additionally, you can implement frame-by-frame layout effects by modifying the values of animatable properties in the per-frame callback function.

- Animatable attribute: If an attribute method is called before the **animation** attribute, and changing the value of this attribute can make the animation effect specified by the **animation** attribute take effect, then this attribute is called animatable attribute. For example, **height**, **width**, **backgroundColor**, **translate**, and **fontSize** (of the **Text** component) are all animatable attributes.

- Non-animatable attribute: If an attribute method is called before the **animation** attribute, and changing the value of this attribute cannot make the animation effect specified by the **animation** attribute take effect, then this attribute is called non-animatable attribute. For example, the **points** attribute of the **Polyline** component is a non-animatable attribute.

>  **NOTE**
>
>  This decorator is supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.
>
> This decorator can be used in atomic services since API version 11.

## Rules of Use


### Syntax


```ts
@AnimatableExtend(UIComponentName) function functionName(value: typeName) { 
  .propertyName(value)
}
```

- \@AnimatableExtend can be defined only globally.
- The parameter of the \@AnimatableExtend decorated function must be of the number type or a custom type that implements the **AnimatableArithmetic\<T\>** API.
- In the \@AnimatableExtend decorated function body, only the attribute methods of the component specified in brackets immediately following \@AnimatableExtend can be called.

### Available APIs
To perform animation when complex data types are involved, you must implement the addition, subtraction, multiplication, and equivalence judgment functions in the **AnimatableArithmetic\<T\>** API.
| Name| Input Parameter Type| Return Value Type | Description |
| -------- | --------  |--------   |--------  |
| plus | AnimatableArithmetic\<T\> | AnimatableArithmetic\<T\> | Addition function.|
| subtract | AnimatableArithmetic\<T\> | AnimatableArithmetic\<T\> | Subtraction function.|
| multiply | number | AnimatableArithmetic\<T\> | Multiplication function.|
| equals | AnimatableArithmetic\<T\> | boolean | Equivalence judgment function.|

## Example

The following example implements the frame-by-frame layout effects by changing the width of the **Text** component.


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


The following example implements a polyline animation effect. 


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
