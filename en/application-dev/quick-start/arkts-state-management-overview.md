# State Management Overview


In previous examples, most of the pages built are static pages, which are delivered to the end user without having to be processed. If you are building dynamic, interactive pages, you need to master state management.


  **Figure 1** State managed UI 

![Video_2023-03-06_152548](figures/Video_2023-03-06_152548.gif)


In the preceding example, the interaction between the user and the application triggers an update in the text state, which in turn triggers re-rendering of the UI. As a result, the **Hello World** text changes to **Hello ArkUI**.


In the declarative UI framework, the UI is the execution result of the application state. You build a UI model in which the state of the application when running is a parameter. When the parameter is changed, the UI as the return result is updated accordingly. This process of UI re-rendering caused by state changes during application running is called the state management mechanism in ArkUI.


Custom components have variables. A variable must be decorated by a decorator whenever the re-rendering of the UI depends on this variable. Otherwise, the UI is rendered only at initialization and will not be updated. The following figure shows the relationship between the state and view (UI).


![en-us_image_0000001562352677](figures/en-us_image_0000001562352677.png)


- View (UI): UI rendering, which generally refers to the UI description in the **build** method of a custom component and the **\@Builder** decorated method.

- State: data decorated by a decorator. State data is changed by invoking the event method of the component. The change of the state data triggers the re-rendering of the UI.


## Basic Concepts

- State variable: a variable decorated by the state decorator. Its change will trigger the re-rendering of the UI.

- Regular variable: a variable that has no state and is usually used for auxiliary calculation. Its change will not trigger the re-rendering of the UI.

- Data source/Synchronization source: original source of a state variable, which can be synchronized to different state data. Generally, it is the data passed from the parent component to the child component.

- Named parameter mechanism: a mechanism where the parent component passes state variables to the child component by specifying parameters. It is the primary means of passing synchronization parameters from the parent component to the child component. Example: CompA: ({ aProp: this.aProp }).

- Initialization from the parent component: a process where the parent component uses the named parameter mechanism to pass specified parameters to the child component. The default value used in local initialization is overwritten by the value passed from the parent component. Example:

  ```ts
  @Component
  struct MyComponent {
    @State count: number = 0;
    private increaseBy: number = 1;

    build() {
    }
  }

  @Component
  struct Parent {
    build() {
      Column() {
        // Initialization from the parent component: The named parameter specified here will overwrite the default value defined locally.
        MyComponent({ count: 1, increaseBy: 2 })
      }
    }
  }
  ```

- Subnode initialization: a capability to pass state variables to the child component to initialize the corresponding state variables therein. The example is the same as above.

- Local initialization: a process where a value is assigned to a variable in its declaration as the default value for initialization. Example: \@State count: number = 0.


## Decorator Overview

ArkUI provides a diverse array of decorators. By using these decorators, state variables can not only observe changes within a component, but also pass the changes between different component levels (for example, between parent and child components or grandparent and grandchild components) or globally. According to the scope of the state variable, decorators can be roughly classified into the following types:


- Decorators for managing the state owned by a component: implement state management at the component level by allowing for observation of state changes within a component and changes at different component levels. The observation is limited to state changes on the same component tree, that is, on the same page.

- Decorators for managing the state owned by an application: implement state management at the component level by allowing for observation of state changes on different pages or even different UIAbility components.


According to the data transfer mode and synchronization type, decorators can also be classified into the following types:


- Decorators that allow for one-way (read-only) transfer

- Decorators that allow for two-way (mutable) transfer


The following figure illustrates the decorators. For details, see [Component State Management](arkts-state.md) and [Application State Management](arkts-application-state-management-overview.md). You can use these decorators at your disposal to implement linkage between data and the UI.


![en-us_image_0000001502704640](figures/en-us_image_0000001502704640.png)


In the preceding figure, the decorators in the Components area are used for state management at the component level, while others are used for state management at the application level. You can use \@StorageLink/\@LocalStorageLink and \@StorageProp/\@LocalStorageProp to implement two-way and one-way synchronization of the application and component state. In the preceding figure, the data synchronization direction is indicated by the arrow direction: single-headed arrow for one-way synchronization and double-headed arrow for two-way sync.


Decorators for [managing the state owned by a component](arkts-state.md):


- \@State: An \@State decorated variable holds the state owned by the owning component. It can be the source of one- or two-way synchronization with child components. When the variable changes, the dependent component will be updated. 

- \@Prop: An \@Prop decorated variable can create one-way synchronization with a variable of its parent component. \@Prop decorated variables are mutable, but changes are not synchronized to the parent component.

- \@Link: An \@Link decorated variable creates two-way synchronization with a variable of its parent component. When the @Link decorated variable has its value changed, its source is updated as well; when the source updates, the @Link decorated variable will do as well.

- \@Provide/\@Consume: Variables decorated by \@Provide/\@Consume are used for data synchronization across component levels. The components can be bound to the variables through aliases or attribute names. Data does not need to be passed through the named parameter mechanism.

- \@Observed: \@Observed is a class decorator. In scenarios involving multiple levels of nested objects or arrays in a class, the class must be decorated with the @Observed decorator. Note that decorating a class with \@Observed alone has no effect. Combined use with \@ObjectLink for two-way synchronization or with \@Prop for one-way synchronization is required.

- \@ObjectLink: An \@ObjectLink decorated variable, when used with an \@Observed decorated class of the parent component, is for two-way data synchronization in scenarios involving multiple levels of nested objects or arrays in the class.

> **NOTE**
>
> Only [\@Observed/\@ObjectLink](arkts-observed-and-objectlink.md) can observe changes of nested attributes. Other decorators can only observe changes of attributes at the first layer. For details, see the "Observed Changes and Behavior" part in each decorator section.


Decorators for [managing the state owned by an application](arkts-state.md):


- AppStorage: a special LocalStorage singleton instance. It is an application-wide database bound to the application process and can be linked to components through the [@StorageProp](arkts-appstorage.md#storageprop) and [@StorageLink](arkts-appstorage.md#storagelink) decorators.

- AppStorage is the hub for application state. Data that needs to interact with components (UI) is stored in AppStorage, including PersistentStorage and Environment data. The UI accesses the data through the decorators or APIs provided by AppStorage.

- LocalStorage: an in-memory "database" for the application state declared by the application and typically used to share state across pages. It can be linked to the UI through the [@LocalStorageProp](arkts-localstorage.md#localstorageprop) and [@LocalStorageLink](arkts-localstorage.md#localstoragelink) decorators.


### Other State Management Features

\@Watch: listens for the changes of the state variables.


$$ operator: provides TS variable references for built-in components so that the variables are synchronized with the internal state of built-in components.
