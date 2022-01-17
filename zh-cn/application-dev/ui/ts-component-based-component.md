# @Component

**@Component** 装饰的**struct**表示该结构体具有组件化能力，能够成为一个独立的组件，这种类型的组件也称为自定义组件。


该组件可以组合其他组件，它通过实现**build**方法来描述UI结构，其必须符合**Builder**的接口约束，该接口定义如下：


```
interface Builder {
    build: () => void
}
```


用户定义的组件具有以下特点：


- **可组合**：允许开发人员组合使用内置组件和其他组件，以及公共属性和方法；

- **可重用**：可以被其他组件重用，并作为不同的实例在不同的父组件或容器中使用；

- **有生命周期**：生命周期的回调方法可以在组件中配置，用于业务逻辑处理；

- **数据驱动更新**：可以由状态数据驱动，实现UI自动更新。


组件生命周期主要包括**aboutToAppear**和**aboutToDisappear**回调函数，有关规范，请参见“[组件生命周期回调函数](../ui/ts-custom-component-lifecycle-callbacks.md)”章节。


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - 组件必须遵循上述**Builder**接口约束，其他组件在内部的**build**方法中以声明式方式进行组合，在组件的第一次创建和更新场景中都会调用**build**方法。
> 
> - 组件禁止自定义构造函数。


## 示例

如下代码定义了**MyComponent**组件**：**

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

**MyComponent**的**build**方法会在初始渲染时执行，此外，当组件中的状态发生变化时，**build**方法将再次执行。

以下代码使用了**MyComponent**组件：

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

可以多次嵌入**MyComponent**，并嵌入到不同的组件中进行重用：

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
