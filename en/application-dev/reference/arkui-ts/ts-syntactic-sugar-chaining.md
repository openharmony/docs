# Chaining<a name="EN-US_TOPIC_0000001110788988"></a>

You can configure the UI structure and its attributes and events using method chaining: calling the methods by separating them with a \(dot.\)

```
Column() {
    Image('1.jpg')
        .alt('error.jpg')
        .width(100)
        .height(100)
}.padding(10)
```

