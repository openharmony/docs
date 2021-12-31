# 持久化数据管理

**PersistentStorage**用于管理应用持久化数据。此对象可以将特定标记的持久化数据链接到AppStorage中，并由AppStorage接口访问对应持久化数据，或者通过@StorageLink修饰器来访问对应key的变量。


## PersistentStorage接口

| 方法 | 参数说明 | 返回值 | 定义 |
| -------- | -------- | -------- | -------- |
| PersistProp | key&nbsp;:&nbsp;string<br/>defaultValue:&nbsp;T | void | 关联命名的属性在AppStorage变为持久化数据。赋值覆盖顺序<br/>首先&nbsp;如果此属性在AppStorage中存在，并且将Persistent中的数据复写为AppStorage中的属性值。<br/>其次Persistent中有此命名的属性，使用Persistent中的属性值。<br/>最后&nbsp;以上条件不满足使用defaultValue，不支持null和undefined。 |
| DeleteProp | key:&nbsp;string | void | 取消双向数据绑定，该属性值将从持久存储中删除。 |
| PersistProps | keys:&nbsp;{<br/>key:&nbsp;string,<br/>defaultValue:&nbsp;any<br/>}[] | void | 关联多个命名的属性绑定。 |
| Keys | void | Array&lt;string&gt; | 返回所有持久化属性的标记。 |

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - PersistProp接口使用时，需要保证输入对应的key应当在Appstorage存在。
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
