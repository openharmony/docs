# 链式调用<a name="ZH-CN_TOPIC_0000001110788988"></a>

允许开发者以“.”链式调用的方式配置UI结构及其属性、事件等。

```
Column() {
    Image('1.jpg')
        .alt('error.jpg')
        .width(100)
        .height(100)
}.padding(10)
```

