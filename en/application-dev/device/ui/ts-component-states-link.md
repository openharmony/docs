# @Link


Two-way binding can be established between the @Link decorated variable and the @State decorated variable of the parent component. The @Link data has the following features:


- Support for multiple types: The value of the @Link decorated variable can be of the same type as the @State decorated variable; that is, the value can be of the following types: class, number, string, boolean, or arrays of these types.

- Private: Data is accessed only within the component.

- Single data source: The variable of the parent component for initializing the @Link decorated variable must be the @State decorated variable.

- Two-way binding: When a child component changes the @Link decorated variable, the @State decorated variable of its parent component is also changed.

- Support for initialization with the variable reference passed to the @Link decorated variable: When creating a new instance of the component, you must use the naming parameter to initialize all @Link decorated variables. The @Link decorated variable can be initialized by using the reference of the @State or @Link decorated variable. Wherein, the @State decorated variable can be referenced using the '$' operator.


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**:
> The @Link decorated variable cannot be initialized within the component.


## Simple Type Example


```
@Entry
@Component
struct Player {
    @State isPlaying: boolean = false
    build() {
        Column() {
            PlayButton({buttonPlaying: $isPlaying})
            Text(`Player is ${this.isPlaying? '':'not'} playing`)
        }
    }
}

@Component
struct PlayButton {
    @Link buttonPlaying: boolean
    build() {
        Column() {
            Button() {
                Image(this.buttonPlaying? 'play.png' : 'pause.png')
            }.onClick(() => {
                this.buttonPlaying = !this.buttonPlaying
            })
        }
    }
}
```

The @Link semantics are derived from the '$' operator. In other words, $isPlaying is the two-way binding of the internal state this.isPlaying. When you click PlayButton, the &lt;Image&gt; and &lt;Text&gt; components of PlayButton are refreshed at the same time.


## Complex Type Example


```
@Entry
@Component
struct Parent {
    @State arr: number[] = [1, 2, 3]
    build() {
        Column() {
            Child({items: $arr})
            ForEach(this.arr,
                item => Text(`${item}`),
                item => item.toString())
        }
    }
}

@Component
struct Child {
    @Link items: number[]
    build() {
        Column() {
            Button() {
                Text('Button1: push')
            }.onClick(() => {
                this.items.push(100)
            })
            Button() {
                Text('Button2: replace whole item')
            }.onClick(() => {
                this.items = [100, 200, 300]
            })
        }
    }
}
```

In the example above, click Button1 and Button2 to change the list of text items displayed in the parent component.


## Example of Using @Link, @State, and @Prop Together


```
@Entry
@Component
struct ParentView {
    @State counter: number = 0
    build() {
        Column() {
            ChildA({counterVal: this.counter})  // pass by value
            ChildB({counterRef: $counter})      // $ creates a Reference that can be bound to counterRef
        }
    }
}

@Component
struct ChildA {
    @Prop counterVal: number
    build() {
        Button() {
            Text(`ChildA: (${this.counterVal}) + 1`)
        }.onClick(() => {this.counterVal+= 1})
    }
}

@Component
struct ChildB {
    @Link counterRef: number
    build() {
        Button() {
            Text(`ChildB: (${this.counterRef}) + 1`)
        }.onClick(() => {this.counterRef+= 1})
    }
}
```

In the preceding example, ParentView contains two child components: ChildA and ChildB. They are initialized by the state variable counter of ParentView.

- ChildB uses @Link to establish two-way state binding. When the value of the counterRef state variable is changed in ChildB, the change is synchronized to ParentView and ChildA.

- ChildA uses @Prop to establish one-way state binding from ParentView to itself. When ChildA changes the state, it is re-rendered, but the change is not updated to ParentView or ChildB.
