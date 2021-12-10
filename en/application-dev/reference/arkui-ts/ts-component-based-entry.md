# @Entry<a name="EN-US_TOPIC_0000001110788998"></a>

The custom component decorated by  **@Entry**  functions as the default entry component of the respective page. When the page is loaded, the custom component decorated by  **@Entry**  is created and displayed first.

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>A source file can contain at most one custom component decorated by  **@Entry**.

## Example<a name="section0615954173414"></a>

Sample code for using  **@Entry**:

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

