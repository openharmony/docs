# struct对象



组件可以基于**struct**实现，组件不能有继承关系，**struct**可以比**class**更加快速的创建和销毁。


```
@Component
struct MyComponent {
    @State data: string = ''

    build() {
    }
}
```
