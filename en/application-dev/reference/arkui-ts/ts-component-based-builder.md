# @Builder<a name="EN-US_TOPIC_0000001134858596"></a>

The  **@Builder**  decorator defines a method for rendering custom components. It provides a method to work in a manner similar to the  [build](ts-function-build.md)  function. The syntax of the  **@Builder**  decorator is the same as that of the  **build**  function.

You can use the  **@Builder**  decorator to quickly generate multiple layouts within a custom component.

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

