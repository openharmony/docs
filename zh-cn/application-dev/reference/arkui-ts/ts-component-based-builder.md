# @Builder<a name="ZH-CN_TOPIC_0000001134858596"></a>

@Builder装饰器定义了一个如何渲染自定义组件的方法。此装饰器提供了一个修饰方法，其目的是和[build函数](ts-function-build.md)一致。@Builder装饰器装饰的方法的语法规范与build函数也保持一致。

通过@Builder装饰器可以在一个自定义组件内快速生成多个布局内容。

```
@Entry
@Component
struct CompA {
  size : number = 100;

  @Builder SquareText(label: string) {
    Text(label)
      .width(1 * this.size)
      .height(1 * this.size)
  }

  @Builder RowOfSquareTexts(label1: string, label2: string) {
    Row() {
      this.SquareText(label1)
      this.SquareText(label2)
    }
    .width(2 * this.size)
    .height(1 * this.size)
  }

  build() {
    Column() {
      Row() {
        this.SquareText("A")
        this.SquareText("B")
        // or as long as tsc is used
      }
      .width(2 * this.size)
      .height(1 * this.size)
      this.RowOfSquareTexts("C", "D")
    }
    .width(2 * this.size)
    .height(2 * this.size)
  }
}
```

