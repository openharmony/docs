# 无构造参数配置



组件的接口定义不包含必选构造参数，组件后面的“**()**”中不需要配置任何内容。


例如，以下**Divider**组件不包含构造参数：


```
Column() {
    Text('item 1')
    Divider() // No parameter configuration of the divider component
    Text('item 2')
}
```
