# @Consume和@Provide数据管理



Provide作为数据的提供方，可以更新其子孙节点的数据，并触发页面渲染。Consume在感知到Provide数据的更新后，会触发当前view的重新渲染。


**表1** @Provide

| 类型 | 说明 |
| -------- | -------- |
| 装饰器参数 | 别名：是一个string类型的常量。如果规定别名，则提供对应别名的数据更新。如果没有，则使用变量名作为别名。推荐使用@Provide("alias")这种形式。 |
| 同步机制 | @Provide的变量类似@state，可以修改对应变量进行页面重新渲染。也可以修改@Consume装饰的变量，反向修改@State变量。 |
| 初始值 | 必须制定初始值 |
| 页面重渲染场景 | 1.&nbsp;基础类型&nbsp;boolean，string，number<br/>2.&nbsp;observed&nbsp;class，修改其中的属性<br/>3.&nbsp;Array：添加，删除，更新数组中的元素 |


**表2** @Consume

| 类型 | 说明 |
| -------- | -------- |
| 初始值 | 不可设置默认值 |


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 使用@Provide 和@Consume时避免循环引用导致死循环。


其他属性说明与Provide一致。


```
@Entry
@Component
struct CompA {
    @Provide("reviewVote") reviewVotes : number = 0;

    build() {
        Column() {
            CompB()
            Button() {
                Text(`${this.reviewVotes}`)
                    .fontSize(30)
            }
            .onClick(() => {
                this.reviewVotes += 1;
            })
        }
    }
}

@Component
struct CompB {
    build() {
        Column() {
            CompC()
        }
    }
}

@Component
struct CompC {
    @Consume("reviewVote") reviewVotes : number;
    build() {
        Column() {
            Button() {
                Text(`${this.reviewVotes}`)
                    .fontSize(30)
            }
            .onClick(() => {
                this.reviewVotes += 1;
            })
        }
    }
}
```
