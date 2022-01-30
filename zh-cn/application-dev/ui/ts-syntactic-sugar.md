# 语法糖<a name="ZH-CN_TOPIC_0000001157228877"></a>

## 装饰器<a name="section13198556135015"></a>

装饰器**@Decorator**不仅可以装饰类或结构体，还可以装饰类的属性。多个装饰器可以叠加到目标元素，定义在同一行上或者在多行上，推荐定义在多行上。

如下示例为**@Component**和**@State**的使用，被**@Component**装饰的元素具备了组件化的含义，使用**@State**装饰的变量具备了状态数据的含义。

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

### 支持的装饰器列表<a name="section1475891613511"></a>

<a name="table1571mcpsimp"></a>
<table><thead align="left"><tr id="row1577mcpsimp"><th class="cellrowborder" valign="top" width="13.16%" id="mcps1.1.4.1.1"><p id="p1579mcpsimp"><a name="p1579mcpsimp"></a><a name="p1579mcpsimp"></a>装饰器</p>
</th>
<th class="cellrowborder" valign="top" width="23.96%" id="mcps1.1.4.1.2"><p id="p1581mcpsimp"><a name="p1581mcpsimp"></a><a name="p1581mcpsimp"></a>装饰内容</p>
</th>
<th class="cellrowborder" valign="top" width="62.88%" id="mcps1.1.4.1.3"><p id="p1583mcpsimp"><a name="p1583mcpsimp"></a><a name="p1583mcpsimp"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1584mcpsimp"><td class="cellrowborder" valign="top" width="13.16%" headers="mcps1.1.4.1.1 "><p id="p1586mcpsimp"><a name="p1586mcpsimp"></a><a name="p1586mcpsimp"></a>@Component</p>
</td>
<td class="cellrowborder" valign="top" width="23.96%" headers="mcps1.1.4.1.2 "><p id="p1588mcpsimp"><a name="p1588mcpsimp"></a><a name="p1588mcpsimp"></a>struct</p>
</td>
<td class="cellrowborder" valign="top" width="62.88%" headers="mcps1.1.4.1.3 "><p id="p1590mcpsimp"><a name="p1590mcpsimp"></a><a name="p1590mcpsimp"></a>结构体在装饰后具有基于组件的能力，需要实现<strong id="b13779163015367"><a name="b13779163015367"></a><a name="b13779163015367"></a>build</strong>方法来更新UI。</p>
</td>
</tr>
<tr id="row1591mcpsimp"><td class="cellrowborder" valign="top" width="13.16%" headers="mcps1.1.4.1.1 "><p id="p1593mcpsimp"><a name="p1593mcpsimp"></a><a name="p1593mcpsimp"></a>@Entry</p>
</td>
<td class="cellrowborder" valign="top" width="23.96%" headers="mcps1.1.4.1.2 "><p id="p12728164243518"><a name="p12728164243518"></a><a name="p12728164243518"></a>struct</p>
</td>
<td class="cellrowborder" valign="top" width="62.88%" headers="mcps1.1.4.1.3 "><p id="p1597mcpsimp"><a name="p1597mcpsimp"></a><a name="p1597mcpsimp"></a>组件被装饰后作为页面的入口，页面加载时将被渲染显示。</p>
</td>
</tr>
<tr id="row10791418503"><td class="cellrowborder" valign="top" width="13.16%" headers="mcps1.1.4.1.1 "><p id="p98020181405"><a name="p98020181405"></a><a name="p98020181405"></a>@Preview</p>
</td>
<td class="cellrowborder" valign="top" width="23.96%" headers="mcps1.1.4.1.2 "><p id="p5801518604"><a name="p5801518604"></a><a name="p5801518604"></a>struct</p>
</td>
<td class="cellrowborder" valign="top" width="62.88%" headers="mcps1.1.4.1.3 "><p id="p7801818809"><a name="p7801818809"></a><a name="p7801818809"></a>用@Preview装饰的自定义组件可以在DevEco Studio的预览器上进行预览，加载页面时，将创建并呈现@Preview装饰的自定义组件。</p>
</td>
</tr>
<tr id="row19327202219012"><td class="cellrowborder" valign="top" width="13.16%" headers="mcps1.1.4.1.1 "><p id="p1832718220010"><a name="p1832718220010"></a><a name="p1832718220010"></a>@Builder</p>
</td>
<td class="cellrowborder" valign="top" width="23.96%" headers="mcps1.1.4.1.2 "><p id="p16327822905"><a name="p16327822905"></a><a name="p16327822905"></a>方法</p>
</td>
<td class="cellrowborder" valign="top" width="62.88%" headers="mcps1.1.4.1.3 "><p id="p1332716221004"><a name="p1332716221004"></a><a name="p1332716221004"></a>@Builder装饰的方法用于定义组件的声明式UI描述，在一个自定义组件内快速生成多个布局内容。</p>
</td>
</tr>
<tr id="row1661312252019"><td class="cellrowborder" valign="top" width="13.16%" headers="mcps1.1.4.1.1 "><p id="p9613725607"><a name="p9613725607"></a><a name="p9613725607"></a>@Extend</p>
</td>
<td class="cellrowborder" valign="top" width="23.96%" headers="mcps1.1.4.1.2 "><p id="p186139258015"><a name="p186139258015"></a><a name="p186139258015"></a>方法</p>
</td>
<td class="cellrowborder" valign="top" width="62.88%" headers="mcps1.1.4.1.3 "><p id="p261310256013"><a name="p261310256013"></a><a name="p261310256013"></a>@Extend装饰器将新的属性函数添加到内置组件上，通过@Extend装饰器可以快速定义并复用组件的自定义样式。</p>
</td>
</tr>
<tr id="row16899855108"><td class="cellrowborder" valign="top" width="13.16%" headers="mcps1.1.4.1.1 "><p id="p4899555802"><a name="p4899555802"></a><a name="p4899555802"></a>@CustomDialog</p>
</td>
<td class="cellrowborder" valign="top" width="23.96%" headers="mcps1.1.4.1.2 "><p id="p108998557015"><a name="p108998557015"></a><a name="p108998557015"></a>struct</p>
</td>
<td class="cellrowborder" valign="top" width="62.88%" headers="mcps1.1.4.1.3 "><p id="p189915557019"><a name="p189915557019"></a><a name="p189915557019"></a>@CustomDialog装饰器用于装饰自定义弹窗。</p>
</td>
</tr>
<tr id="row1598mcpsimp"><td class="cellrowborder" valign="top" width="13.16%" headers="mcps1.1.4.1.1 "><p id="p1600mcpsimp"><a name="p1600mcpsimp"></a><a name="p1600mcpsimp"></a>@State</p>
</td>
<td class="cellrowborder" valign="top" width="23.96%" headers="mcps1.1.4.1.2 "><p id="p1602mcpsimp"><a name="p1602mcpsimp"></a><a name="p1602mcpsimp"></a>基本数据类型，类，数组</p>
</td>
<td class="cellrowborder" valign="top" width="62.88%" headers="mcps1.1.4.1.3 "><p id="p1604mcpsimp"><a name="p1604mcpsimp"></a><a name="p1604mcpsimp"></a>修饰的状态数据被修改时会触发组件的<strong id="b20907141011376"><a name="b20907141011376"></a><a name="b20907141011376"></a>build</strong>方法进行UI界面更新。</p>
</td>
</tr>
<tr id="row1605mcpsimp"><td class="cellrowborder" valign="top" width="13.16%" headers="mcps1.1.4.1.1 "><p id="p1607mcpsimp"><a name="p1607mcpsimp"></a><a name="p1607mcpsimp"></a>@Prop</p>
</td>
<td class="cellrowborder" valign="top" width="23.96%" headers="mcps1.1.4.1.2 "><p id="p1609mcpsimp"><a name="p1609mcpsimp"></a><a name="p1609mcpsimp"></a>基本数据类型</p>
</td>
<td class="cellrowborder" valign="top" width="62.88%" headers="mcps1.1.4.1.3 "><p id="p1611mcpsimp"><a name="p1611mcpsimp"></a><a name="p1611mcpsimp"></a>修改后的状态数据用于在父组件和子组件之间建立单向数据依赖关系。修改父组件关联数据时，更新当前组件的UI。</p>
</td>
</tr>
<tr id="row1612mcpsimp"><td class="cellrowborder" valign="top" width="13.16%" headers="mcps1.1.4.1.1 "><p id="p1614mcpsimp"><a name="p1614mcpsimp"></a><a name="p1614mcpsimp"></a>@Link</p>
</td>
<td class="cellrowborder" valign="top" width="23.96%" headers="mcps1.1.4.1.2 "><p id="p1616mcpsimp"><a name="p1616mcpsimp"></a><a name="p1616mcpsimp"></a>基本数据类型，类，数组</p>
</td>
<td class="cellrowborder" valign="top" width="62.88%" headers="mcps1.1.4.1.3 "><p id="p1618mcpsimp"><a name="p1618mcpsimp"></a><a name="p1618mcpsimp"></a>父子组件之间的双向数据绑定，父组件的内部状态数据作为数据源，任何一方所做的修改都会反映给另一方。</p>
</td>
</tr>
<tr id="row139690521423"><td class="cellrowborder" valign="top" width="13.16%" headers="mcps1.1.4.1.1 "><p id="p11969452623"><a name="p11969452623"></a><a name="p11969452623"></a>@Observed</p>
</td>
<td class="cellrowborder" valign="top" width="23.96%" headers="mcps1.1.4.1.2 "><p id="p1396919525211"><a name="p1396919525211"></a><a name="p1396919525211"></a>类</p>
</td>
<td class="cellrowborder" valign="top" width="62.88%" headers="mcps1.1.4.1.3 "><p id="p49690521127"><a name="p49690521127"></a><a name="p49690521127"></a>@Observed应用于类，表示该类中的数据变更被UI页面管理。</p>
</td>
</tr>
<tr id="row778085615217"><td class="cellrowborder" valign="top" width="13.16%" headers="mcps1.1.4.1.1 "><p id="p3780556329"><a name="p3780556329"></a><a name="p3780556329"></a>@ObjectLink</p>
</td>
<td class="cellrowborder" valign="top" width="23.96%" headers="mcps1.1.4.1.2 "><p id="p1578015569213"><a name="p1578015569213"></a><a name="p1578015569213"></a>被@Observed所装饰类的对象</p>
</td>
<td class="cellrowborder" valign="top" width="62.88%" headers="mcps1.1.4.1.3 "><p id="p1178119564216"><a name="p1178119564216"></a><a name="p1178119564216"></a>@ObjectLink应用于被@Observed所装饰类的对象。</p>
</td>
</tr>
<tr id="row151181913836"><td class="cellrowborder" valign="top" width="13.16%" headers="mcps1.1.4.1.1 "><p id="p5118813338"><a name="p5118813338"></a><a name="p5118813338"></a>@Consume</p>
</td>
<td class="cellrowborder" valign="top" width="23.96%" headers="mcps1.1.4.1.2 "><p id="p142241420971"><a name="p142241420971"></a><a name="p142241420971"></a>基本数据类型，类，数组</p>
</td>
<td class="cellrowborder" valign="top" width="62.88%" headers="mcps1.1.4.1.3 "><p id="p211815133320"><a name="p211815133320"></a><a name="p211815133320"></a>Provide作为数据的提供方，可以更新其子孙节点的数据，并触发页面渲染。</p>
</td>
</tr>
<tr id="row1255819257319"><td class="cellrowborder" valign="top" width="13.16%" headers="mcps1.1.4.1.1 "><p id="p755820251310"><a name="p755820251310"></a><a name="p755820251310"></a>@Provide</p>
</td>
<td class="cellrowborder" valign="top" width="23.96%" headers="mcps1.1.4.1.2 "><p id="p15911121377"><a name="p15911121377"></a><a name="p15911121377"></a>基本数据类型，类，数组</p>
</td>
<td class="cellrowborder" valign="top" width="62.88%" headers="mcps1.1.4.1.3 "><p id="p125584259319"><a name="p125584259319"></a><a name="p125584259319"></a>Consume在感知到Provide数据的更新后，会触发当前view的重新渲染。</p>
</td>
</tr>
<tr id="row894833814311"><td class="cellrowborder" valign="top" width="13.16%" headers="mcps1.1.4.1.1 "><p id="p13949938639"><a name="p13949938639"></a><a name="p13949938639"></a>@Watch</p>
</td>
<td class="cellrowborder" valign="top" width="23.96%" headers="mcps1.1.4.1.2 "><p id="p109491038731"><a name="p109491038731"></a><a name="p109491038731"></a>被@State, @Prop, @Link, @ObjectLink, @Provide, @Consume, @StorageProp， @StorageLink中任意一个装饰的变量</p>
</td>
<td class="cellrowborder" valign="top" width="62.88%" headers="mcps1.1.4.1.3 "><p id="p494917381732"><a name="p494917381732"></a><a name="p494917381732"></a>@Watch用于监听状态变量的变化，应用可以注册回调方法。</p>
</td>
</tr>
</tbody>
</table>

## 链式调用<a name="section25027489512"></a>

允许开发者以“.”链式调用的方式配置UI结构及其属性、事件等。

```
Column() {
    Image('1.jpg')
        .alt('error.jpg')
        .width(100)
        .height(100)
}.padding(10)
```

## struct对象<a name="section194461959175118"></a>

组件可以基于**struct**实现，组件不能有继承关系，**struct**可以比**class**更加快速的创建和销毁。

```
@Component
struct MyComponent {
    @State data: string = ''

    build() {
    }
}
```

## 在实例化过程中省略"new"<a name="section1042572913525"></a>

对于**struct**的实例化，可以省略**new**。

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

## 生成器函数内使用TS语言的限制<a name="section8871946125215"></a>

TS语言的使用在生成器函数中存在一定的限制：

-   表达式仅允许在字符串\($\{expression\}\)、if条件、ForEach的参数和组件的参数中使用；
-   这些表达式中的任何一个都不能导致任何应用程序状态变量（@State、@Link、@Prop）的改变，否则会导致未定义和潜在不稳定的框架行为；
-   生成器函数内部不能有局部变量。

上述限制都不适用于事件处理函数（例如**onClick**）的匿名函数实现，它们也不适用于UI组件描述外的其余部分。

非法示例：

```
build() {
    let a: number = 1 // invalid: variable declaration not allowed
    Column() {
        Text('Hello ${this.myName.toUpperCase()}') // ok.
        ForEach(this.arr.reverse(), ..., ...) // invalid: Array.reverse modifies the @State array varible in place
    }
    buildSpecial()  // invalid: no function calls
    Text(this.calcTextValue()) // this function call is ok.
}
```

