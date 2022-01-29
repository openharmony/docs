# Instantiating a struct Without the new Keyword<a name="EN-US_TOPIC_0000001110788984"></a>

You can omit the  **new**  keyword when instantiating a  **struct**.

```
// Definition
@Component
struct MyComponent {
    build() {
    }
}

// Use
Column() {
    MyComponent()
}

// Equivalent to
new Column() {
    new MyComponent()
}
```

