# @Link<a name="EN-US_TOPIC_0000001110948894"></a>

Bidirectional data binding can be established between the  **@Link**  annotated variable and the  **@State**  annotated variable of the parent component.

-   **Support for multiple types**: The value of the  **@Link**  annotated variable is the same as that of the  **@State**  annotated variable, that is, class, number, string, boolean, or arrays of these types.
-   **Private**: Data is accessed only within the component.
-   **Single data source**: The variable of the parent component for initializing the  **@Link**  annotated variable must be the  **@State**  annotated variable.
-   **Bidirectional communication**: When a child component changes the  **@Link**  annotated variable, the  **@State**  annotated variable of its parent component is also changed.
-   **Requiring the variable reference to the @Link annotated variable**: When creating a new instance of the component, you must use the naming parameter to initialize all  **@Link**  annotated variables. The  **@Link**  annotated variable can be initialized by using the reference of the  **@State**  or  **@Link**  annotated variable. The  **@State**  annotated variable can be referenced using the '**$**' operator.

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>The  **@Link**  annotated variable cannot be initialized within the component.

## Simple Type Example<a name="section19793192619582"></a>

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

The  **@Link**  semantics are derived from the '**$**' operator. In other words,  **$isPlaying**  is a bidirectional data binding of the internal state of  **this.isPlaying**. When you click  **PlayButton**, the  **<Image\>**  and  **<Text\>**  components of  **PlayButton**  are refreshed at the same time.

## Complex Type Example<a name="section2921131712010"></a>

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

In the example above, click  **Button 1**  and  **Button 2**  to change the list of text items displayed in the parent component.

## Example of Using @Link, @State, and @Prop Together<a name="section17490315415"></a>

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

In the preceding example,  **ParentView**  contains two child components:  **ChildA**  and  **ChildB**. The state variable counter of  **ParentView**  initializes  **ChildA**  and  **ChildB**.

-   **ChildB**  uses  **@Link**  to establish bidirectional binding. When the value of the  **counterRef**  state variable is changed in  **ChildB**, the change is synchronized to  **ParentView**  and  **ChildA**.
-   **ChildA**  uses  **@Prop**  to establish a unidirectional state binding from  **ParentView**  to itself. When  **ChildA**  changes the state, it is re-rendered, but the change is not communicated to  **ParentView**  or  **ChildB**.

