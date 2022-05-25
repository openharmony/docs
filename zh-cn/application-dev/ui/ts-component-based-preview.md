# @Preview

用@Preview装饰的自定义组件可以在DevEco Studio的预览器上进行预览，加载页面时，将创建并呈现@Preview装饰的自定义组件。


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 在单个源文件中，最多可以使用10个@Preview装饰自定义组件。


@Preview的用法如下：


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
