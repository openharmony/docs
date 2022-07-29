# 自定义组件链式调用

> **说明：**该写法从API version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。 

@Component组件链式调用可以实现同一组件不同样式显示的效果。

> **说明：**在自定义组件使用链式写法时不能使用尾随闭包（ 在初始化自定义组件时，组件名称紧跟一个大括号“{}”形成尾随闭包场景（Index(){}`）。开发者可把尾随闭包看做一个容器，向其填充内容，如在闭包内增加组件（`{Column(){Text("content")}` ）。

```
@Entry
@Component
struct Index {
@State bannerValue: string = 'Hello,world';
build() {
  Column() {
    Chind1({ChindBannerValue:$bannerValue})
    .height(60)
    .width(250)
    .border({width:5, color:0x317AF7, radius:10, style: BorderStyle.Dotted})
    Chind2({ChindBannerValue:$bannerValue});
  }
} 
}

@Component
struct Chind1{
  @Link ChindBannerValue: string;
  build() {
    Column() {
      Text(this.ChindBannerValue)
      .fontSize(30)
    }
  }
}

@Component
struct Chind2{
  @Link ChindBannerValue: string;
  build() {
    Text(this.ChindBannerValue)
    .fontSize(30)
  }
}
```

