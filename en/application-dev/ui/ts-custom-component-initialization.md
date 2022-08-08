# Initialization of Custom Components' Member Variables


The member variables of a component can be initialized in either of the following ways:


- Local initialization. For example:
    
  ```ts
  @State counter: Counter = new Counter()
  ```

- Initialization using constructor parameters. For example:
    
  ```ts
  MyComponent({counter: $myCounter})
  ```


The allowed method depends on the decorator of the state variable, as shown in the following table.


  | Decorator Type | Local Initialization | Initialization Using Constructor Parameters | 
| -------- | -------- | -------- |
| @State | Mandatory | Optional | 
| @Prop | Forbidden | Mandatory | 
| @Link | Forbidden | Mandatory | 
| @StorageLink | Mandatory | Forbidden | 
| @StorageProp | Mandatory | Forbidden | 
| @Provide | Mandatory | Optional | 
| @Consume | Forbidden | Forbidden | 
| @ObjectLink | Forbidden | Mandatory | 
| Normal member variable | Recommended | Optional | 


As indicated by the preceding table:


- The @State decorated variables need to be initialized locally. The initial value can be overwritten by the constructor parameter.

- The @Prop and @Link decorated variables must be initialized only by constructor parameters.


Comply with the following rules when using constructors to initialize member variables:


  | From the Variable in the Parent Component (Below) to the Variable in the Child Component (Right) | @State | @Link | @Prop | Normal Variable | 
| -------- | -------- | -------- | -------- | -------- |
| @State | Not allowed | Allowed | Allowed | Allowed | 
| @Link | Not allowed | Allowed | Not recommended | Allowed | 
| @Prop | Not allowed | Not allowed | Allowed | Allowed | 
| @StorageLink | Not allowed | Allowed | Not allowed | Allowed | 
| @StorageProp | Not allowed | Not allowed | Not allowed | Allowed | 
| Normal variable | Allowed | Not allowed | Not allowed | Allowed | 


As indicated by the preceding table:


- The normal variables of the parent component can be used to initialize the @State decorated variables of the child component, but not the @Link or @Prop decorated variables.

- The @State decorated variable of the parent component can be used to initialize the @Prop, @Link (using $), or normal variables of the child component, but not the @State decorated variables of the child component.

- The @Link decorated variables of the parent component can be used to initialize the @Link decorated or normal variables of the child component. However, initializing the @State decorated members of the child component can result in a syntax error. In addition, initializing the @Prop decorated variables is not recommended.

- The @Prop decorated variables of the parent component can be used to initialize the normal variables or @Prop decorated variables of the child component, but not the @State or @Link decorated variables.

- Passing @StorageLink and @StorageProp from the parent component to the child component is prohibited.

- In addition to the preceding rules, the TypeScript strong type rules need to be followed.


## Example

  
```ts
// xxx.ets
class ClassA {
  public a:number
  constructor(a: number) {
    this.a = a
  }
}
@Entry
@Component
struct Parent {
  @State parentState: ClassA = new ClassA(1)
  
  build() {
    Column() {
      Flex({ justifyContent: FlexAlign.Start, alignItems: ItemAlign.Center }) {
        CompA({ aState: new ClassA(2), aLink: $parentState })
      }
      Flex({ justifyContent: FlexAlign.Start, alignItems: ItemAlign.Center }) {
        CompA({ aLink: $parentState })
      }
      Flex({ justifyContent: FlexAlign.Start, alignItems: ItemAlign.Center }) {
        CompA({ aState: new ClassA(3), aLink: $parentState })
      }
    }
  }
}

@Component
struct CompA {
  @State aState: any = false
  @Link aLink: ClassA
  
  build() {
    Column() {
      CompB({ bLink: $aLink, bProp: this.aState })
      CompB({ bLink: $aState, bProp: false })
    }
  }
}

@Component
struct CompB {
  @Link bLink: ClassA
  @Prop bProp: boolean
  
  build() {
    Flex({ justifyContent: FlexAlign.Start, alignItems: ItemAlign.Center }) {
      Text(JSON.stringify(this.bLink.a)).fontSize(30)
      Text(JSON.stringify(this.bProp)).fontSize(30).fontColor(Color.Red)
     }.margin(10)
  }
}
```
