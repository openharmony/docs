# LocalStorage: UI State Storage


LocalStorage provides storage for the page-level UI state. The parameters of the LocalStorage type accepted through the \@Entry decorator share the same LocalStorage instance on the page. LocalStorage also allows for state sharing between pages within a UIAbility.


This topic describes only the LocalStorage application scenarios and related decorators: \@LocalStorageProp and \@LocalStorageLink.


> **NOTE**
>
> LocalStorage is supported since API version 9.


## Overview

LocalStorage is an in-memory "database" that ArkTS provides for storing state variables that are required to build pages of the application UI.

- An application can create multiple LocalStorage instances. These instances can be shared on a page or, by using the **GetShared** API from the UIAbility, across pages in a UIAbility.

- The root node of a component tree, that is, the \@Component decorated by \@Entry, can be assigned to a LocalStorage instance. All child instances of this custom component automatically gain access to the same LocalStorage instance.

- An \@Component decorated component has access to at most one LocalStorage instance and to [AppStorage](arkts-appstorage.md). A component not decorated with \@Entry cannot be assigned a LocalStorage instance. It can only accept a LocalStorage instance passed from its parent component through \@Entry. A LocalStorage instance can be assigned to multiple components in the component tree.

- All attributes in LocalStorage are mutable.

The application determines the lifecycle of a LocalStorage object. The JS Engine will garbage collect a LocalStorage object when the application releases the last reference to it, which includes deleting the last custom component.

LocalStorage provides two decorators based on the synchronization type of the component decorated with \@Component:

- [@LocalStorageProp](#localstorageprop): \@LocalStorageProp creates a one-way data synchronization from the named attribute in LocalStorage to the \@LocalStorageProp decorated variable.

- [@LocalStorageLink](#localstoragelink): \@LocalStorageLink creates a two-way data synchronization with the named attribute in the \@Component's LocalStorage.


## Restrictions

- Once created, the type of a named attribute cannot be changed. Subsequent calls to **Set** must set a value of same type.
- LocalStorage provides page-level storage. The [GetShared](../reference/arkui-ts/ts-state-management.md#getshared9) API can only obtain the LocalStorage instance transferred through [windowStage.loadContent](../reference/apis/js-apis-window.md#loadcontent9) in the current stage. Otherwise, **undefined** is returned. Example: [Sharing a LocalStorage Instance from UIAbility to One or More Pages](#sharing-a-localstorage-instance-from-uiability-to-one-or-more-pages).


## \@LocalStorageProp

As mentioned above, if you want to establish a binding between LocalStorage and a custom component, you need to use the \@LocalStorageProp and \@LocalStorageLink decorators. Use \@LocalStorageProp(key) or \@LocalStorageLink(key) to decorate variables in the component. **key** identifies the attribute in LocalStorage.


When a custom component is initialized, the \@LocalStorageProp(key)/\@LocalStorageLink(key) decorated variable is initialized with the value of the attribute with the given key in LocalStorage. Local initialization is mandatory. If an attribute with the given key is missing from LocalStorage, it will be added with the stated initializing value. (Whether the attribute with the given key exists in LocalStorage depends on the application logic.)


> **NOTE**
>
> Since API version 9, this decorator is supported in ArkTS widgets.


By decorating a variable with \@LocalStorageProp(key), a one-way data synchronization is established with the attribute with the given key in LocalStorage. A local change can be made, but it will not be synchronized to LocalStorage. An update to the attribute with the given key in LocalStorage will overwrite local changes.


### Rules of Use

| \@LocalStorageProp Decorator| Description                                      |
| ----------------------- | ---------------------------------------- |
| Decorator parameters                  | **key**: constant string, mandatory (note, the string is quoted)                 |
| Allowed variable types              | Object, class, string, number, Boolean, enum, and array of these types. For details about the scenarios of nested objects, see [Observed Changes and Behavior](#observed-changes-and-behavior).<br>The type must be specified and must be the same as the corresponding attribute in LocalStorage. **any** is not supported. The **undefined** and **null** values are not allowed.|
| Synchronization type                   | One-way: from the attribute in LocalStorage to the component variable. The component variable can be changed locally, but an update from LocalStorage will overwrite local changes.|
| Initial value for the decorated variable              | Mandatory. It is used as the default value for initialization if the attribute does not exist in LocalStorage.|


### Variable Transfer/Access Rules

| Transfer/Access     | Description                                      |
| ---------- | ---------------------------------------- |
| Initialization and update from the parent component| Forbidden.|
| Subnode initialization    | Supported; can be used to initialize an \@State, \@Link, \@Prop, or \@Provide decorated variable in the child component.|
| Access | None.                                      |

  **Figure 1** \@LocalStorageProp initialization rule 

![en-us_image_0000001501936014](figures/en-us_image_0000001501936014.png)


### Observed Changes and Behavior

**Observed Changes**


- When the decorated variable is of the Boolean, string, or number type, its value change can be observed.

- When the decorated variable is of the class or Object type, its value change and value changes of all its attributes, that is, the attributes that **Object.keys(observedObject)** returns.

- When the decorated variable is of the array type, the addition, deletion, and updates of array items can be observed.


**Framework Behavior**


- When the value change of the \@LocalStorageProp(key) decorated variable is observed, the change is not synchronized to the attribute with the give key value in LocalStorage.

- The value change of the \@LocalStorageProp(key) decorated variable only applies to the private member variables of the current component, but not other variables bound to the key.

- When the data decorated by \@LocalStorageProp(key) is a state variable, the change of the data is not synchronized to LocalStorage, but the owning custom component is re-rendered.

- When the attribute with the given key in LocalStorage is updated, the change is synchronized to all the \@LocalStorageProp(key) decorated data, and the local changes of the data are overwritten.


## \@LocalStorageLink

\@LocalStorageLink is required if you need to synchronize the changes of the state variables in a custom component back to LocalStorage.

\@LocalStorageLink(key) creates a two-way data synchronization with the attribute with the given key in LocalStorage.

1. If a local change occurs, it is synchronized to LocalStorage.

2. Changes in LocalStorage are synchronized to all attributes with the given key, including one-way bound variables (\@LocalStorageProp decorated variables and one-way bound variables created through \@Prop) and two-way bound variables (\@LocalStorageLink decorated variables and two-way bound variables created through \@Link).


### Rules of Use

| \@LocalStorageLink Decorator| Description                                      |
| ----------------------- | ---------------------------------------- |
| Decorator parameters                  | **key**: constant string, mandatory (note, the string is quoted)                 |
| Allowed variable types              | Object, class, string, number, Boolean, enum, and array of these types. For details about the scenarios of nested objects, see [Observed Changes and Behavior](#observed-changes-and-behavior).<br>The type must be specified and must be the same as the corresponding attribute in LocalStorage. **any** is not supported. The **undefined** and **null** values are not allowed.|
| Synchronization type                   | Two-way: from the attribute in LocalStorage to the custom component variable and back|
| Initial value for the decorated variable              | Mandatory. It is used as the default value for initialization if the attribute does not exist in LocalStorage.|


### Variable Transfer/Access Rules

| Transfer/Access     | Description                                      |
| ---------- | ---------------------------------------- |
| Initialization and update from the parent component| Forbidden.|
| Subnode initialization    | Supported; can be used to initialize an \@State, \@Link, \@Prop, or \@Provide decorated variable in the child component.|
| Access | None.                                      |


  **Figure 2** \@LocalStorageLink initialization rule 


![en-us_image_0000001552855957](figures/en-us_image_0000001552855957.png)


### Observed Changes and Behavior

**Observed Changes**


- When the decorated variable is of the Boolean, string, or number type, its value change can be observed.

- When the decorated variable is of the class or Object type, its value change and value changes of all its attributes, that is, the attributes that **Object.keys(observedObject)** returns.

- When the decorated variable is of the array type, the addition, deletion, and updates of array items can be observed.


**Framework Behavior**


1. When the value change of the \@LocalStorageLink(key) decorated variable is observed, the change is synchronized to the attribute with the give key value in LocalStorage.

2. Once the attribute with the given key in LocalStorage is updated, all the data (including \@LocalStorageLink and \@LocalStorageProp decorated variables) bound to the attribute key is changed synchronously.

3. When the data decorated by \@LocalStorageProp(key) is a state variable, the change of the data is synchronized to LocalStorage, and the owning custom component is re-rendered.


## Application Scenarios


### Example of Using LocalStorage in Application Logic


```ts
let storage = new LocalStorage({ 'PropA': 47 }); // Create a new instance and initialize it with the given object.
let propA = storage.get('PropA') // propA == 47
let link1 = storage.link('PropA'); // link1.get() == 47
let link2 = storage.link('PropA'); // link2.get() == 47
let prop = storage.prop('PropA'); // prop.get() = 47
link1.set(48); // two-way sync: link1.get() == link2.get() == prop.get() == 48
prop.set(1); // one-way sync: prop.get()=1; but link1.get() == link2.get() == 48
link1.set(49); // two-way sync: link1.get() == link2.get() == prop.get() == 49
```


### Example for Using LocalStorage from Inside the UI

The two decorators \@LocalStorageProp and \@LocalStorageLink can work together to obtain the state variable stored in a LocalStorage instance in the UI component.

This example uses \@LocalStorage as an example to show how to:

- Use the **build** function to create a LocalStorage instance named **storage**.

- Use the \@Entry decorator to add **storage** to the top-level component **CompA**.

- Use \@LocalStorageLink to create a two-way data synchronization with the given attribute in LocalStorage.

  ```ts
  // Create a new instance and initialize it with the given object.
  let storage = new LocalStorage({ 'PropA': 47 });

  @Component
  struct Child {
    // @LocalStorageLink creates a two-way data synchronization with the ProA attribute in LocalStorage.
    @LocalStorageLink('PropA') storLink2: number = 1;

    build() {
      Button(`Child from LocalStorage ${this.storLink2}`)
        // The changes will be synchronized to ProA in LocalStorage and with Parent.storLink1.
        .onClick(() => this.storLink2 += 1)
    }
  }
  // Make LocalStorage accessible from the @Component decorated component.
  @Entry(storage)
  @Component
  struct CompA {
    // @LocalStorageLink creates a two-way data synchronization with the ProA attribute in LocalStorage.
    @LocalStorageLink('PropA') storLink1: number = 1;

    build() {
      Column({ space: 15 }) {
        Button(`Parent from LocalStorage ${this.storLink1}`) // initial value from LocalStorage will be 47, because 'PropA' initialized already
          .onClick(() => this.storLink1 += 1)
        // The @Component decorated child component automatically obtains access to the CompA LocalStorage instance.
        Child()
      }
    }
  }
  ```


### Simple Example of Using \@LocalStorageProp with LocalStorage

In this example, the **CompA** and **Child** components create local data that is one-way synced with the PropA attribute in the LocalStorage instance **storage**.

- The change of **this.storProp1** in **CompA** takes effect only in **CompA** and is not synchronized to **storage**.

- In the **Child** component, the value of **storProp2** bound to **Text** is still 47.

  ```ts
  // Create a new instance and initialize it with the given object.
  let storage = new LocalStorage({ 'PropA': 47 });
  // Make LocalStorage accessible from the @Component decorated component.
  @Entry(storage)
  @Component
  struct CompA {
    // @LocalStorageProp creates a one-way data synchronization with the ProA attribute in LocalStorage.
    @LocalStorageProp('PropA') storProp1: number = 1;

    build() {
      Column({ space: 15 }) {
        // The initial value is 47. After the button is clicked, the value is incremented by 1. The change takes effect only in storProp1 in the current component and is not synchronized to LocalStorage.
        Button(`Parent from LocalStorage ${this.storProp1}`)
          .onClick(() => this.storProp1 += 1)
        Child()
      }
    }
  }

  @Component
  struct Child {
    // @LocalStorageProp creates a one-way data synchronization with the ProA attribute in LocalStorage.
    @LocalStorageProp('PropA') storProp2: number = 2;

    build() {
      Column({ space: 15 }) {
        // When CompA changes, the current storProp2 does not change, and 47 is displayed.
        Text(`Parent from LocalStorage ${this.storProp2}`)
      }
    }
  }
  ```


### Simple Example of Using \@LocalStorageLink and LocalStorage

This example shows how to create a two-way data synchronization between an \@LocalStorageLink decorated variable and LocalStorage.


```ts
// Create a LocalStorage instance.
let storage = new LocalStorage({ 'PropA': 47 });
// Invoke the link9+ API to create a two-way data synchronization with PropA. linkToPropA is a global variable.
let linkToPropA = storage.link('PropA');

@Entry(storage)
@Component
struct CompA {

  // @LocalStorageLink('PropA') creates a two-way synchronization with PropA in the CompA custom component. The initial value is 47, because PropA has been set to 47 during LocalStorage construction.
  @LocalStorageLink('PropA') storLink: number = 1;

  build() {
    Column() {
      Text(`incr @LocalStorageLink variable`)
        // Clicking incr @LocalStorageLink variable increases the value of this.storLink by 1. The change is synchronized back to the storage. The global variable linkToPropA also changes.

        .onClick(() => this.storLink += 1)

      // Avoid using the global variable linkToPropA.get() in the component. Doing so may cause errors due to different lifecycles.
      Text(`@LocalStorageLink: ${this.storLink} - linkToPropA: ${linkToPropA.get()}`)
    }
  }
}
```


### State Variable Synchronization Between Sibling Nodes

This example shows how to use \@LocalStorageLink to create a two-way synchronization for the state between sibling nodes.

Check the changes in the **Parent** custom component.

1. Clicking **playCount ${this.playCount} dec by 1** decreases the value of **this.playCount** by 1. This change is synchronized to LocalStorage and to the components bound to **playCountLink** in the **Child** component.

2. Click **countStorage ${this.playCount} incr by 1** to call the **set** API in LocalStorage to update the attributes corresponding to **countStorage** in LocalStorage. The components bound to** playCountLink** in the **Child** component are updated synchronously.

3. The **playCount in LocalStorage for debug ${storage.get&lt;number&gt;('countStorage')}** **\<Text>** component is not updated synchronously, because **storage.get<number>('countStorage')** returns a regular variable. The update of a regular variable does not cause the **\<Text>** component to be re-rendered.

Changes in the **Child** custom component:

1. The update of **playCountLink** is synchronized to LocalStorage, and the parent and sibling child custom components are re-rendered accordingly.

   ```ts
   let storage = new LocalStorage({ countStorage: 1 });

   @Component
   struct Child {
     // Name the child component instance.
     label: string = 'no name';
     // Two-way synchronization with countStorage in LocalStorage.
     @LocalStorageLink('countStorage') playCountLink: number = 0;

     build() {
       Row() {
         Text(this.label)
           .width(50).height(60).fontSize(12)
         Text(`playCountLink ${this.playCountLink}: inc by 1`)
           .onClick(() => {
             this.playCountLink += 1;
           })
           .width(200).height(60).fontSize(12)
       }.width(300).height(60)
     }
   }

   @Entry(storage)
   @Component
   struct Parent {
     @LocalStorageLink('countStorage') playCount: number = 0;

     build() {
       Column() {
         Row() {
           Text('Parent')
             .width(50).height(60).fontSize(12)
           Text(`playCount ${this.playCount} dec by 1`)
             .onClick(() => {
               this.playCount -= 1;
             })
             .width(250).height(60).fontSize(12)
         }.width(300).height(60)

         Row() {
           Text('LocalStorage')
             .width(50).height(60).fontSize(12)
           Text(`countStorage ${this.playCount} incr by 1`)
             .onClick(() => {
               storage.set<number>('countStorage', 1 + storage.get<number>('countStorage'));
             })
             .width(250).height(60).fontSize(12)
         }.width(300).height(60)

         Child({ label: 'ChildA' })
         Child({ label: 'ChildB' })

         Text(`playCount in LocalStorage for debug ${storage.get<number>('countStorage')}`)
           .width(300).height(60).fontSize(12)
       }
     }
   }
   ```


### Sharing a LocalStorage Instance from UIAbility to One or More Pages

In the preceding examples, the LocalStorage instance is shared only in an \@Entry decorated component and its owning child component (a page). To enable a LocalStorage instance to be shared across pages, you can create a LocalStorage instance in the owning UIAbility and call windowStage.[loadContent](../reference/apis/js-apis-window.md#loadcontent9).


```ts
// EntryAbility.ts
import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.window';

export default class EntryAbility extends UIAbility {
  storage: LocalStorage = new LocalStorage({
    'PropA': 47
  });

  onWindowStageCreate(windowStage: window.WindowStage) {
    windowStage.loadContent('pages/Index', this.storage);
  }
}
```

On the page, call the **GetShared** API to obtain the LocalStorage instance shared through **loadContent**.


```ts
// Use the GetShared API to obtain the Storage instance shared by stage.
let storage = LocalStorage.GetShared()

@Entry(storage)
@Component
struct CompA {
  // can access LocalStorage instance using 
  // @LocalStorageLink/Prop decorated variables
  @LocalStorageLink('PropA') varA: number = 1;

  build() {
    Column() {
      Text(`${this.varA}`).fontSize(50)
    }
  }
}
```


> **NOTE**
>
> It is good practice to always create a LocalStorage instance with meaningful default values, which serve as a backup when execution exceptions occur and are also useful for unit testing of pages.

<!--no_check-->
