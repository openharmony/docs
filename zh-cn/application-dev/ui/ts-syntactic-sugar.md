# 语法糖

## 装饰器


装饰器@Decorator不仅可以装饰类或结构体，还可以装饰类的属性。多个装饰器可以叠加到目标元素，定义在同一行上或者在多行上，推荐定义在多行上。


如下示例为@Component和@State的使用，被 @Component装饰的元素具备了组件化的含义，使用@State装饰的变量具备了状态数据的含义。


```
@Component
struct MyComponent {
    @State count: number = 0
}
```


装饰器定义在同一行上的描述如下：


```
@Entry @Component struct MyComponent {
}
```


但更推荐定义在多行上：


```
@Entry
@Component
struct MyComponent {
}
```


### 支持的装饰器列表

| 装饰器 | 装饰内容 | 说明 |
| -------- | -------- | -------- |
| @Component | struct | 结构体在装饰后具有基于组件的能力，需要实现build方法来更新UI。 |
| @Entry | struct | 组件被装饰后作为页面的入口，页面加载时将被渲染显示。 |
| @Preview | struct | 用@Preview装饰的自定义组件可以在DevEco&nbsp;Studio的预览器上进行预览，加载页面时，将创建并呈现@Preview装饰的自定义组件。 |
| @Builder | 方法 | 在@Builder装饰的方法用通过声明式UI描述，可以在一个自定义组件内快速生成多个布局内容。 |
| @Extend | 方法 | @Extend装饰器将新的属性函数添加到内置组件上，通过@Extend装饰器可以快速定义并复用组件的自定义样式。 |
| @CustomDialog | struct | @CustomDialog装饰器用于装饰自定义弹窗。 |
| @State | 基本数据类型，类，数组 | 修饰的状态数据被修改时会触发组件的build方法进行UI界面更新。 |
| @Prop | 基本数据类型 | 修改后的状态数据用于在父组件和子组件之间建立单向数据依赖关系。修改父组件关联数据时，更新当前组件的UI。 |
| @Link | 基本数据类型，类，数组 | 父子组件之间的双向数据绑定，父组件的内部状态数据作为数据源，任何一方所做的修改都会反映给另一方。 |
| @Observed | 类 | @Observed应用于类，表示该类中的数据变更被UI页面管理。 |
| @ObjectLink | 被@Observed所装饰类的对象 | 装饰的状态数据被修改时，在父组件或者其他兄弟组件内与它关联的状态数据所在的组件都会更新UI。 |
| @Consume | 基本数据类型，类，数组 | @Consume装饰的变量在感知到@Provide装饰的变量更新后，会触发当前自定义组件的重新渲染。 |
| @Provide | 基本数据类型，类，数组 | @Provide作为数据的提供方，可以更新其子孙节点的数据，并触发页面渲染。 |
| @Watch | 被@State,&nbsp;@Prop,&nbsp;@Link,&nbsp;@ObjectLink,&nbsp;@Provide,&nbsp;@Consume,&nbsp;@StorageProp，&nbsp;@StorageLink中任意一个装饰的变量 | @Watch用于监听状态变量的变化，应用可以注册回调方法。 |


## 链式调用

允许开发者以“.”链式调用的方式配置UI结构及其属性、事件等。

```
Column() {
    Image('1.jpg')
        .alt('error.jpg')
        .width(100)
        .height(100)
}.padding(10)
```


## struct对象

组件可以基于struct实现，组件不能有继承关系，struct可以比class更加快速的创建和销毁。

```
@Component
struct MyComponent {
    @State data: string = ''

    build() {
    }
}
```


## 在实例化过程中省略"new"

对于struct的实例化，可以省略new。

```
// 定义
@Component
struct MyComponent {
    build() {
    }
}

// 使用
Column() {
    MyComponent()
}

// 等价于
new Column() {
    new MyComponent()
}
```


## TS语言在生成器函数中的使用限制

TS语言的使用在生成器函数中存在一定的限制：

- 表达式仅允许在字符串(${expression})、if条件、ForEach的参数和组件的参数中使用；

- 这些表达式中的任何一个都不能导致任何应用程序状态变量（@State、@Link、@Prop）的改变，否则会导致未定义和潜在不稳定的框架行为；

- 生成器函数内部不能有局部变量。

上述限制都不适用于事件处理函数（例如onClick）的匿名函数实现。

非法示例：

```
build() {
    let a: number = 1 // invalid: variable declaration not allowed
    Column() {
        Text('Hello ${this.myName.toUpperCase()}') // ok.
        ForEach(this.arr.reverse(), ..., ...) // invalid: Array.reverse modifies the @State array variable in place
    }
    buildSpecial()  // invalid: no function calls
    Text(this.calcTextValue()) // this function call is ok.
}
```


## $$

$$支持变量双向绑定，支持简单变量、@State、@Link、@Prop等类型。

当前$$仅支持[bindPopup](../reference/arkui-ts/ts-universal-attributes-popup.md)属性的show参数和@State变量之间的渲染，以及Radio组件的checked属性。


```
@Entry
@Component
struct bindPopup {
	@State customPopup: boolean = false
	build() {
		Column() {
			Button(){
				Text('Popup')
			}
			.onClick(()=>{
				this.customPopup = !this.customPopup
			})
			.bindPopup(
				$$this.customPopup, {
					message: "showPopup"
				}
			)
		}
	}
}
```
