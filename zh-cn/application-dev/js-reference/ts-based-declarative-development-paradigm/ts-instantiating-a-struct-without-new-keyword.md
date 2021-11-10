# 在实例化过程中省略"new"<a name="ZH-CN_TOPIC_0000001110788984"></a>

对于**struct**的实例化，可以省略**new**。

```
// 定义
@Component
struct MyComponent {
    build() {
    }
}

// 使用
Column() {
    MyComponent()
}

// 等价于
new Column() {
    new MyComponent()
}
```

