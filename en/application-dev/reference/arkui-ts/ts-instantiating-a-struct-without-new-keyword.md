# Instantiating a struct Without the new Keyword<a name="EN-US_TOPIC_0000001110788984"></a>

For the instantiation of  **struct**, the  **new**  keyword can be omitted.

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

