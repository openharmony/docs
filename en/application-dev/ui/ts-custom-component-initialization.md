# Initialization of Custom Components' Member Variables


The member variables of a component can be initialized in either of the following ways:


- Local initialization. For example:
    
  ```
  @State counter: Counter = new Counter()
  ```

- Initialization using constructor parameters. For example:
    
  ```
  MyComponent(counter: $myCounter)
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

  
```
@Entry
@Component
struct Parent {
    @State parentState: ClassA = new ClassA()
    build() {
        Row() {
            CompA({aState: new ClassA, aLink: $parentState}) // valid
            CompA({aLink: $parentState})   // valid
            CompA()                 // invalid, @Link aLink remains uninitialized
            CompA({aLink: new ClassA}) // invalid, @Link aLink must be a reference ($) to either @State or @Link variable
        }
    }
}

@Component
struct CompA {
    @State aState: boolean = false   // must initialize locally
    @Link aLink: ClassA              // must not initialize locally

    build() {
        Row() {
            CompB({bLink: $aLink,         // valid init a @Link with reference of another @Link,
                bProp: this.aState})    // valid init a @Prop with value of a @State
            CompB({aLink: $aState,  // invalid: type mismatch expected ref to ClassA, provided reference to boolean
                bProp: false})           // valid init a @Prop by constants value
        }
    }
}

@Component
struct CompB {
    @Link bLink: ClassA = new ClassA()       // invalid, must not initialize locally
    @Prop bProp: boolean = false      // invalid must not initialize locally

    build() {
        ...
    }
}
```
