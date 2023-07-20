# ArkUI Subsystem Changelog

## cl.arkui.1 Support for the undefined Parameter by Universal Events

Added support for passing **undefined** as a parameter for universal events (click, touch, show/hide, key, focus, mouse, and component area change events).

**Example**

```ts
// xxx.ets
@Entry
@Component
struct Example {
  build() {
    Button("test")
    .onClick(()=>{
      console.log("click");
    })
    .onClick(undefined)
  }
}
```

**Change Impact**

If the event callback parameter is **undefined**, the system will not respond to the configured event callback.


**Key API/Component Changes**

N/A

**Adaptation Guide**

If the event parameter is set to **undefined**, the event is disabled. Set the parameter based on the use case.


## cl.arkui.2 Initialization Requirement Change of @Prop/@BuilderParam Decorated Variables

**Example**

```ts
// xxx.ets
@Entry
@Component
struct Parent {
  @State message: string = 'Parent'
  build() {
    Column() {
      Child() // Compile time error.
    }
  }
}

@Component
struct Child {
  @Prop message: string
  build() {
    Column() {
      
    }
  }
}
```

**Change Impact**

If the @Prop or @BuilderParam decorated variable is not initialized locally or initialized from its parent component, a compile time error will occur.


**Key API/Component Changes**

N/A

**Adaptation Guide**

Assign an initial value to the @Prop or @BuilderParam decorated variable or pass the value from the parent component.


## cl.arkui.3 Initial Value Requirement Change of @BuilderParam Decorated Variables

**Example**

```ts
// xxx.ets
@Builder
function builderFunction() {
  Text('Hello Builder')
}

function normal () {

}

@Component
struct Index {
  @BuilderParam builderParam: ()=>void = builderFunction
  @BuilderParam builderParam2: ()=>void = normal // Compile time error.
  build() {
    Column() {

    }
  }
}
```

**Change Impact**

If the initial value of the @BuilderParam decorated variable is not an @Builder method, the compilation will fail.


**Key API/Component Changes**

N/A

**Adaptation Guide**

Pass in an @Builder method as the initial value of the @BuilderParam variable.

## cl.arkui.4 Type Change of the searchButton Attribute of the \<Search> Component from SearchButtonOption to SearchButtonOptions

**Change Impact**

If the **SearchButtonOption** type is explicitly used, the compilation will fail.

**Key API/Component Changes**

The type **SearchButtonOption** of the **searchButton** attribute is changed to **SearchButtonOptions**.

**Adaptation Guide**

Change **SearchButtonOption** to **SearchButtonOptions**.
