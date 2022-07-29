# 自定义组件链式调用

> **说明：**该写法从API version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。 

自定义组件链式是赋予组件层通用属性的一种写法。实现同一个组件拥有不同的样式以及简单功能。

> **说明：**自定义组件链式调用暂不支持尾随闭包写法。



### 示例:

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
