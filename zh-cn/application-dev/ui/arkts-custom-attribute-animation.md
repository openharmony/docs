# 自定义属性动画


属性动画是可动画属性的参数值发生变化时，引起UI上产生的连续视觉效果。当参数值发生连续变化，且设置到可以引起UI发生变化的属性接口上时，就可以实现属性动画。


ArkUI提供[@AnimatableExtend](../quick-start/arkts-animatable-extend.md)装饰器，用于自定义可动画属性接口。由于参数的数据类型必须具备一定程度的连续性，自定义可动画属性接口的参数类型仅支持number类型和实现[AnimtableArithmetic\<T>](../quick-start/arkts-animatable-extend.md)接口的自定义类型。通过自定义可动画属性接口和可动画数据类型，在使用animateTo或animation执行动画时，通过逐帧回调函数修改不可动画属性接口的值，能够让不可动画属性接口实现动画效果。


## 使用number数据类型和\@AnimatableExtend装饰器改变字体大小


```ts
// 第一步：使用@AnimatableExtend装饰器，自定义可动画属性接口
@AnimatableExtend(Text) function animatableFontSize(size: number) {
  .fontSize(size) // 调用系统属性接口
}

@Entry
@Component
struct AnimatablePropertyExample {
  @State fontSize: number = 20;

  build() {
    Column() {
      Text("AnimatableProperty")
        .animatableFontSize(this.fontSize) // 第二步：将自定义可动画属性接口设置到组件上
        .animation({ duration: 1000, curve: "ease" }) // 第三步:为自定义可动画属性接口绑定动画
      Button("Play")
        .onClick(() => {
          this.fontSize = this.fontSize == 20 ? 36 : 20; // 第四步：改变自定义可动画属性的参数，产生动画
        })
    }.width("100%")
    .padding(10)
  }
}
```



![zh-cn_image_0000001600119626](figures/zh-cn_image_0000001600119626.gif)


## 使用自定义数据类型和\@AnimatableExtend装饰器改变折线


```ts
declare type Point = number[];

// 定义可动画属性接口的参数类型，实现AnimtableArithmetic<T>接口中加法、减法、乘法和判断相等函数
class PointClass extends Array<number> {
  constructor(value: Point) {
    super(value[0], value[1])
  }

  add(rhs: PointClass): PointClass {
    let result: Point = new Array<number>() as Point;
    for (let i = 0; i < 2; i++) {
      result.push(rhs[i] + this[i])
    }
    return new PointClass(result);
  }

  subtract(rhs: PointClass): PointClass {
    let result: Point = new Array<number>() as Point;
    for (let i = 0; i < 2; i++) {
      result.push(this[i] - rhs[i]);
    }
    return new PointClass(result);
  }

  multiply(scale: number): PointClass {
    let result: Point = new Array<number>() as Point;
    for (let i = 0; i < 2; i++) {
      result.push(this[i] * scale)
    }
    return new PointClass(result);
  }
}

// 定义可动画属性接口的参数类型，实现AnimtableArithmetic<T>接口中加法、减法、乘法和判断相等函数
// 模板T支持嵌套实现AnimtableArithmetic<T>的类型
class PointVector extends Array<PointClass> implements AnimatableArithmetic<Array<Point>> {
  constructor(initialValue: Array<Point>) {
    super();
    if (initialValue.length) {
      initialValue.forEach((p:Point) => this.push(new PointClass(p)))
    }
  }

  // implement the IAnimatableArithmetic interface
  plus(rhs: PointVector): PointVector {
    let result = new PointVector([]);
    const len = Math.min(this.length, rhs.length)
    for (let i = 0; i < len; i++) {
      result.push(this[i].add(rhs[i]))
    }
    return result;
  }

  subtract(rhs: PointVector): PointVector {
    let result = new PointVector([]);
    const len = Math.min(this.length, rhs.length)
    for (let i = 0; i < len; i++) {
      result.push(this[i].subtract(rhs[i]))
    }
    return result;
  }

  multiply(scale: number): PointVector {
    let result = new PointVector([]);
    for (let i = 0; i < this.length; i++) {
      result.push(this[i].multiply(scale))
    }
    return result;
  }

  equals(rhs: PointVector): boolean {
    if (this.length !== rhs.length) {
      return false;
    }
    for (let index = 0, size = this.length; index < size; ++index) {
      if (this[index][0] !== rhs[index][0] || this[index][1] !== rhs[index][1]) {
        return false;
      }
    }
    return true;
  }
}

function randomInt(min:number, max:number) {
  return Math.floor(Math.random() * (max - min) + min);
}

// 自定义可动画属性接口
@AnimatableExtend(Polyline) function animatablePoints(points: PointVector) {
  .points(points)
}

// 自定义可动画属性接口
@AnimatableExtend(Text) function animatableFontSize(size: number) {
  .fontSize(size)
}

@Entry
@Component
struct AnimatedShape {
  @State pointVec1: PointVector = new PointVector([
    [50, randomInt(0, 200)],
    [100, randomInt(0, 200)],
    [150, randomInt(0, 200)],
    [250, randomInt(0, 200)],
    [350, randomInt(0, 200)]
  ]);
  @State pointVec2: PointVector = new PointVector([
    [70, randomInt(0, 200)],
    [120, randomInt(0, 200)],
    [180, randomInt(0, 200)],
    [220, randomInt(0, 200)],
    [320, randomInt(0, 200)]
  ]);
  @State color: Color = Color.Green;
  @State fontSize: number = 20.0;
  @State polyline1Vec: PointVector = this.pointVec1;
  @State polyline2Vec: PointVector = this.pointVec2;

  build() {
    Column() {
      Text("AnimatableExtend test")
        .width(400)
        .height(30)
        .margin(1)
        .fontSize(25)
        .textAlign(TextAlign.Center)
        .backgroundColor("#ffee44")
        .border({ width: '1vp', color: "#88ff00", radius: 20, style: BorderStyle.Solid })

      Polyline()
        .width(400)
        .height(240)
        .backgroundColor("#eeaacc")
        .fill(this.color)
        .stroke(Color.Red)
        .animatablePoints(this.polyline1Vec)
        .animation({ duration: 2000, delay: 0, curve: Curve.Ease })

      Polyline()
        .width(400)
        .height(240)
        .backgroundColor("#bbffcc")
        .fill(this.color)
        .stroke(Color.Red)
        .animatablePoints(this.polyline2Vec)
        .animation({ duration: 2000, delay: 0, curve: Curve.Ease })

      Text("Animatable Fontsize")

        .animatableFontSize(this.fontSize)
        .animation({ duration: 2000, delay: 0, curve: Curve.Ease })
        .width(400)
        .height(150)
        .margin(5)
        .textAlign(TextAlign.Center)
        .backgroundColor("#ffddcc")
        .border({ width: '2vp', color: "#88ff00", radius: 20, style: BorderStyle.Solid })
        .onClick(() => {
          console.log("Text onClick()")
        })

      Row() {
        Button("Polyline1 default")
          .width(100).height(60)
          .margin({ left: 5, right: 5 })
          .padding(10)
          .onClick(() => {

            if (this.polyline1Vec.equals(this.pointVec1)) {
              this.polyline1Vec = this.pointVec2;
            } else {
              this.polyline1Vec = this.pointVec1;
            }
          })

        Button("Polyline2 ANIM")
          .width(100).height(60)
          .onClick(() => {
            if (this.polyline2Vec.equals(this.pointVec1)) {
              this.polyline2Vec = this.pointVec2;
            } else {
              this.polyline2Vec = this.pointVec1;
            }
          })

        Button("FontSize")
          .width(100).height(60)
          .margin({ left: 5, right: 5 })
          .onClick(() => {
            this.fontSize = (this.fontSize == 20.0) ? 40.0 : 20.0;
          })
      }
      .alignItems(VerticalAlign.Center)
      .margin(5)

    }
    .width('100%')
    .alignItems(HorizontalAlign.Center)
  }
}
```


![zh-cn_image_0000001592669598](figures/zh-cn_image_0000001592669598.gif)

## 相关实例

针对自定义属性动画开发，有以下相关实例可供参考：

- [自定义下拉刷新动画（ArkTS）（API9）](https://gitee.com/openharmony/codelabs/tree/master/ETSUI/AnimateRefresh)