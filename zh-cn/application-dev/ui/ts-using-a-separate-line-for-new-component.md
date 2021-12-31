# 组件创建使用独立一行



**每行代码末尾可以省略分号";"**


```
Column() {
    Image('icon.png')
    Text('text')
}
```


等同于：


```
Column() {
    Image('icon.png');
    Text('text');
}
```


**每行只允许创建一个组件。if, else, else if, ForEach语句单独一行。**


无效示例：


```
Column() {
    Image('icon.png') Text('text') // invalid, creation of two components in same line
}

if (this.condi) {Image('icon.png')} // invalid, if and creation a components in same line
```


**内置容器组件、if和ForEach项生成器函数必须在单个子项的情况下使用封闭括号"{}"。**


无效示例：


```
if (this.condi)
Image('icon.png'), // invalid, missing {}
else
    Text('text');
```


```
ForEach(this.arr,
    (item) => Image('icon.png'), // invalid, missing {}
    (item) => item.id.toString()
}
```
