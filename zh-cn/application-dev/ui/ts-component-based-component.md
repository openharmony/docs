# @Component

@Component装饰的struct表示该结构体具有组件化能力，能够成为一个独立的组件，这种类型的组件也称为自定义组件，在build方法里描述UI结构。自定义组件具有以下特点：


- 可组合：允许开发人员组合使用内置组件、其他组件、公共属性和方法；

- 可重用：自定义组件可以被其他组件重用，并作为不同的实例在不同的父组件或容器中使用；

- 生命周期：生命周期的回调方法可以在组件中配置，用于业务逻辑处理；

- 数据驱动更新：由状态变量的数据驱动，实现UI自动更新。


对组件化的深入描述，请参考[深入理解组件化](ts-a-deep-dive-into-component.md)。


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - 自定义组件必须定义build方法。
> 
> - 自定义组件禁止自定义构造函数。


如下代码定义了MyComponent组件：


```
@Component
struct MyComponent {
    build() {
        Column() {
            Text('my component')
                .fontColor(Color.Red)
        }.alignItems(HorizontalAlign.Center) // center align Text inside Column
    }
}
```


MyComponent的build方法会在初始渲染时执行，此外，当组件中的状态发生变化时，build方法将再次执行。


以下代码使用了MyComponent组件：


```
@Component
struct ParentComponent {
    build() {
        Column() {
            MyComponent()
            Text('we use component')
                .fontSize(20)
        }
    }
}
```


可以多次使用MyComponent，并在不同的组件中进行重用：


```
@Component
struct ParentComponent {
    build() {
        Row() {
            Column() {
                MyComponent()
                Text('first column')
                    .fontSize(20)
            }
            Column() {
                MyComponent()
                Text('second column')
                    .fontSize(20)
            }
        }
    }

    private aboutToAppear() {
        console.log('ParentComponent: Just created, about to become rendered first time.')
    }

    private aboutToDisappear() {
        console.log('ParentComponent: About to be removed from the UI.')
    }
}
```
