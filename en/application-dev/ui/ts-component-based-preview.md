# @Preview


You can use @Preview to decorate a custom component so that it can be previewed in DevEco Studio. This component is created and displayed when the page where it is located is loaded.


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br>
> In a source file, at most one custom component can be decorated by @Preview.


Example of using @Preview:


```
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
