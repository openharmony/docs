# @Preview


Custom components decorated by @Preview can be previewed in the Previewer of DevEco Studio. When the page is loaded, the custom components decorated by @Preview are created and displayed.


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**:
> In a source file, at most one custom component can be decorated by @Preview.


Example of using @Preview:

```
// Display only Hello Component1 on the PC preview. The content under MyComponent is displayed on the real device.
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
