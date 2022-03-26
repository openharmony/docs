# 持久化数据管理

方舟开发框架通过PersistentStorage类提供了一些静态方法用来管理应用持久化数据，可以将特定标记的持久化数据链接到AppStorage中，并由AppStorage接口访问对应持久化数据，或者通过@StorageLink装饰器来访问对应key的变量。


| 方法 | 参数说明 | 返回值 | 定义 | 
| -------- | -------- | -------- | -------- |
| PersistProp | key&nbsp;:&nbsp;string<br/>defaultValue:&nbsp;T | void | 关联命名的属性在AppStorage变为持久化数据，赋值覆盖顺序如下：<br/>-&nbsp;首先，如果该属性存在于AppStorage，将Persistent中的数据复写为AppStorage中的属性值。<br/>-&nbsp;其次，Persistent中有此命名的属性，使用Persistent中的属性值。<br/>-&nbsp;最后，以上条件均不满足，则使用defaultValue，不支持null和undefined。 | 
| DeleteProp | key:&nbsp;string | void | 取消双向数据绑定，该属性值将从持久存储中删除。 | 
| PersistProps | keys:&nbsp;{<br/>key:&nbsp;string,<br/>defaultValue:&nbsp;any<br/>}[] | void | 关联多个命名的属性绑定。 | 
| Keys | void | Array&lt;string&gt; | 返回所有持久化属性的标记。 | 


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - PersistProp接口使用时，需要保证输入对应的key应当在AppStorage存在。
> 
> - DeleteProp接口使用时，只能对本次启动已经link过的数据生效。


```
PersistentStorage.PersistProp("highScore", "0");

@Entry
@Component
struct PersistentComponent {
    @StorageLink('highScore') highScore: string = '0'
    @State currentScore: number = 0
    build() {
        Column() {
            if (this.currentScore === Number(this.highScore)) {
                Text(`new highScore : ${this.highScore}`)
            }
            Button() {
                Text(`goal!, currentScore : ${this.currentScore}`)
                    .fontSize(10)
            }.onClick(() => {
                this.currentScore++
                if (this.currentScore > Number(this.highScore)) {
                    this.highScore = this.currentScore.toString()
                }
            })
        }
    }
}
```
