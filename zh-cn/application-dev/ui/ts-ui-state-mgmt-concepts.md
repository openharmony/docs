# 基本概念

在声明式UI编程范式中，UI是应用程序状态的函数，开发人员通过修改当前应用程序状态来更新相应的UI界面。如下图所示，开发框架提供了多种应用程序状态管理的能力。


![](figures/CoreSpec_figures_state-mgmt-overview.png)


## 状态变量装饰器

- @State：组件拥有的状态属性，当@State装饰的变量更改时，组件会重新渲染更新UI。

- @Link：组件依赖于其父组件拥有的某些状态属性，当任何一个组件中的数据更新时，另一个组件的状态都会更新，父子组件重新渲染。

- @Prop：原理类似@Link，但是子组件所做的更改不会同步到父组件上，属于单向传递。
> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 状态变量名称不能使用id，如@Prop id:number 。


## 应用程序状态数据

AppStorage是整个UI应用程序状态的中心“数据库”，UI框架会针对应用程序创建单例AppStorage对象，并提供相应的装饰器和接口供应用程序使用。

- @StorageLink：@StorageLink(name)的原理类似于@Consume(name)，不同的是，该给定名称的链接对象是从AppStorage中获得的，在UI组件和AppStorage之间建立双向绑定同步数据。

- @StorageProp：@StorageProp(name)将UI组件属性与AppStorage进行单向同步，AppStorage中值的更改会更新组件中的属性，但UI组件无法更改AppStorage中的属性值。

- AppStorage还提供用于业务逻辑实现的API，用于添加、读取、修改和删除应用程序的状态属性，此API所做的更改会导致修改的状态数据同步到UI组件上进行UI更新。

