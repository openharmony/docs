# Basic Concepts


The eTS-based declarative development paradigm provides a wide array of basic components, which can be combined and extended in a declarative manner to describe the UI of an application. It also provides basic data binding and event processing mechanisms to help you implement the application interaction logic.


## HelloWorld Example


```
// An example of displaying Hello World. After you click the button, Hello UI is displayed.
@Entry
@Component
struct Hello {
    @State myText: string = 'World'
    build() {
        Column() {
            Text('Hello')
                .fontSize(30)
            Text(this.myText)
                .fontSize(32)
            Divider()
            Button() {
                Text('Click me')
                .fontColor(Color.Red)
            }.onClick(() => {
                this.myText = 'UI'
            })
            .width(500)
            .height(200)
        }
    }
}
```


## Basic Concepts

The preceding sample code shows the structure of a simple page. It involves the following basic concepts:

- Decorator: a special kind of declaration that can be applied to classes, structures, methods, and variables. In the sample code, **@Entry**, **@Component**, and **@State** are decorators.

- Custom component: a reusable UI unit, which can be combined with other components. In the sample code, struct Hello decorated by **@Component** is a custom component.

- UI description: declaratively describes the UI structure. In the sample code, the block of code in the build() method provides the UI description.

- Built-in component: the default basic or layout component preset in the framework. You can directly invoke these components, such as **\<Column>**, **\<Text>**, **\<Divider>**, and **\<Button>** components in the sample code.

- Attribute method: a method used to configure component attributes, such as **fontSize()**, **width()**, **height()**, and **color()**.

- Event method: a method used to add the component response logic to an event. In the sample code, the **onClick** method is added for the Button component for defining the click response logic.
