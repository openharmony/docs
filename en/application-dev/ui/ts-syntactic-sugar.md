# About Syntactic Sugar


## Decorators

A decorator @Decorator can decorate a class, structure, or class attribute. Multiple decorators can be applied to the same target element and defined on a single line or multiple lines. It is recommended that the decorators be defined on multiple lines.

In the example below, the elements decorated by @Component take on the form of a component, and the variables decorated by @State can be used to represent states.


```
@Component
struct MyComponent {
    @State count: number = 0
}
```

Multiple decorators can be defined on a single line, as shown below:


```
@Entry @Component struct MyComponent {
}
```

However, you are advised to define the decorators on multiple lines, as shown below:


```
@Entry
@Component
struct MyComponent {
}
```


### Supported Decorators

  | Decorator | Decorates... | Description | 
| -------- | -------- | -------- |
| @Component | struct | The decorated structure has the component-based capability. The build method must be implemented to update the UI. | 
| @Entry | struct | The decorated component is used as the entry of a page. The component is rendered and displayed when the page is loaded. | 
| @Preview | struct | Custom components decorated by @Preview can be previewed in the Previewer of DevEco Studio. When the page is loaded, the custom components decorated by @Preview are created and displayed. | 
| @Builder | Methods | In the decorated method, you can use the declarative UI description to quickly generate multiple layouts in a custom component. | 
| @Extend | Methods | This decorator adds new attribute functions to a preset component, allowing you to quickly define and reuse the custom style of the component. | 
| @CustomDialog | struct | This decorator is used to decorate custom pop-up dialog boxes. | 
| @State | Primitive data types, classes, and arrays | If the decorated state data is modified, the build method of the component will be called to update the UI. | 
| @Prop | Primitive data types | This decorator is used to establish one-way data binding between the parent and child components. When the data associated with the parent component is modified, the UI of the current component is updated. | 
| @Link | Primitive data types, classes, and arrays | This decorator is used to establish two-way data binding between the parent and child components. The internal state data of the parent component is used as the data source. Any changes made to one component will be reflected to the other. | 
| @Observed | Classes | This decorator is used to indicate that the data changes in the class will be managed by the UI page. | 
| @ObjectLink | Objects of @Observed decorated classes | When the decorated state variable is modified, the parent and sibling components that have the state variable will be notified for UI re-rendering. | 
| @Consume | Primitive data types, classes, and arrays | When the @Consume decorated variable detects the update of the @Provide decorated variable, the re-rendering of the current custom component is triggered. | 
| @Provide | Primitive data types, classes, and arrays | As the data provider, @Provide can update the data of child nodes and trigger page rendering. | 
| @Watch | Variables decorated by @State, @Prop, @Link, @ObjectLink, @Provide, @Consume, @StorageProp, or @StorageLink | This decorator is used to listen for the changes of the state variables. The application can register a callback method through @Watch. | 


## Chain Call

You can configure the UI structure and its attributes and events and separate them with a dot(.) to implement chain call.


```
Column() {
    Image('1.jpg')
        .alt('error.jpg')
        .width(100)
        .height(100)
}.padding(10)
```


## struct

Components can be implemented based on structs. Components cannot inherit from each other. The structs implemented components can be created and destroyed more quickly than class implemented components.


```
@Component
struct MyComponent {
    @State data: string = ''

    build() {
    }
}
```


## Instantiating a struct Without the new Keyword

You can omit the new keyword when instantiating a struct.


```
// Definition
@Component
struct MyComponent {
    build() {
    }
}

// Use
Column() {
    MyComponent()
}

// Equivalent to
new Column() {
    new MyComponent()
}
```


## Restrictions on Using TypeScript in Generators

TypeScript has the following restrictions on generators:

- Expressions can be used only in character strings (${expression}), if conditions, ForEach parameters, and component parameters.

- No expressions should cause any application state variables (@State, @Link, and @Prop) to change. Otherwise, undefined and potentially unstable framework behavior may occur.

- The generator function cannot contain local variables.

None of the above restrictions apply to anonymous function implementations of event-handling functions (such as onClick)

Incorrect:


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

$$ supports two-way binding for simple variables and @State, @Link, and @Prop decorated variables.

Currently, $$ supports only the rendering between the show parameter of the bindPopup attribute and the @State decorated variable, and the checked attribute of the <Radio> component.

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

