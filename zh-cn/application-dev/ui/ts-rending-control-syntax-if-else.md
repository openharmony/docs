# 条件渲染

使用if/else进行条件渲染。


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - if条件语句可以使用状态变量。
> 
> - 使用if可以使子组件的渲染依赖条件语句。
> 
> - 必须在容器组件内使用。
> 
> - 某些容器组件限制子组件的类型或数量。将if放置在这些组件内时，这些限制将应用于if和else语句内创建的组件。例如，Grid组件的子组件仅支持GridItem组件，在Grid组件内使用if时，则if条件语句内仅允许使用GridItem组件。


## 示例

使用if条件语句：

```
Column() {
    if (this.count > 0) {
        Text('count is positive')
    }
}
```


使用if、else if、else条件语句：


```
Column() {
    if (this.count < 0) {
        Text('count is negative')
    } else if (this.count % 2 === 0) {
        Divider()
        Text('even')
    } else {
        Divider()
        Text('odd')
    }
}
```
