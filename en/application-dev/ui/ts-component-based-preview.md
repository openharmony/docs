# @Preview

You can use **@Preview** to decorate a custom component so that it can be previewed in real time in DevEco Studio. This component is created and displayed when the page where it is located is loaded. Dynamic pictures and dynamic preview are not yet supported.


> **NOTE**
>
> In a source file, at most 10 custom components can be decorated by **@Preview**. For details, see [@Preview](https://developer.harmonyos.com/en/docs/documentation/doc-guides/ohos-previewing-app-service-0000001218760596#section146052489820).


Example of using **@Preview**:


```ts
// xxx.ets
@Entry
@Component
struct MyComponent {
  build() {
    Column() {
      Row() {
        Text('Hello World!')
          .fontSize("50lpx")
          .fontWeight(FontWeight.Bold)
      }
      Row() {
        Component1()
      }
      Row() {
        Component2()
      }
    }
  }
}

@Preview
@Component
struct Component1 {
  build() {
    Column() {
      Row() {
        Text('Hello Component1')
          .fontSize("50lpx")
          .fontWeight(FontWeight.Bold)
      }
    }
  }
}

@Component
struct Component2 {
  build() {
    Column() {
      Row() {
        Text('Hello Component2')
          .fontSize("50lpx")
          .fontWeight(FontWeight.Bold)
      }
    }
  }
}
```
