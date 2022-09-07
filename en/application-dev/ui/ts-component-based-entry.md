# @Entry


The custom component decorated by @Entry functions as the default entry component of the respective page. When the page is loaded, the custom component decorated by @Entry is created and displayed first.


> **NOTE**
>
> A source file can contain at most one custom component decorated by @Entry.


Example of using @Entry:

```ts
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
