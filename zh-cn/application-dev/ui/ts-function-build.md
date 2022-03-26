# build函数

build函数满足Builder构造器接口定义，用于定义组件的声明式UI描述。必须遵循上述Builder接口约束，在build方法中以声明式方式进行组合自定义组件或系统内置组件，在组件创建和更新场景中都会调用build方法。


```
interface Builder {
    build: () => void
}
```


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> build方法仅支持组合组件，使用渲染控制语法。
