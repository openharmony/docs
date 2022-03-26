# @Entry

用@Entry装饰的自定义组件用作页面的默认入口组件，加载页面时，将首先创建并呈现@Entry装饰的自定义组件。


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 在单个源文件中，最多可以使用@Entry装饰一个自定义组件。


@Entry的用法如下：


```
// Only MyComponent decorated by @Entry is rendered and displayed. "hello world" is displayed, but "goodbye" is not displayed.
@Entry
@Component
struct MyComponent {
    build() {
        Column() {
            Text('hello world')
                .fontColor(Color.Red)
        }
    }
}

@Component
struct HideComponent {
    build() {
        Column() {
            Text('goodbye')
                .fontColor(Color.Blue)
        }
    }
}
```
