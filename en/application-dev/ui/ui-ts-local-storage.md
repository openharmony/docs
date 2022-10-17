# LocalStorage

> **NOTE**
>
> This component is supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.

**LocalStorage** is a storage unit in an application. Its lifecycle is determined by the ability to which it is bound. **LocalStorage** provides storage for variable and non-variable state attributes within the scope of an application. The variable and non-variable state attributes work together to build an application UI, including the UI of abilities.

Application layer: Multiple **LocalStorage** instances can be created for an application. Each ability of an application corresponds to a **LocalStorage** instance.

Ability: An application can have multiple abilities. Only one **LocalStorage** instance can be allocated to the child components of an ability. Once allocated a **LocalStorage** instance, the child components have access to objects stored in the **LocalStorage**.

A component can access only one **LocalStorage** instance, and a **LocalStorage** instance can be allocated to multiple components.

## @LocalStorageLink Decorator

Two-way data binding can be established between a component and the **LocalStorage** through the component's state variable decorated by **@LocalStorageLink(*key*)**. Wherein, **key** is the attribute key value in the **LocalStorage**. When a component that contains a **@LocalStorageLink** decorated state variable is created, the state variable is initialized with the value predefined in the **LocalStorage**. If no initial value is assigned in the **LocalStorage**, the state variable will use the value defined by **@LocalStorageLink**. Changes made to this variable in the component will be first synchronized to the **LocalStorage**, and then to other components of the bound ability.

## @LocalStorageProp Decorator

One-way data binding can be established between a component and the **LocalStorage** through the component's state variable decorated by **@LocalStorageProp(*key*)**. Wherein, **key** is the attribute key value in the **LocalStorage**. When a component that contains a **@LocalStorageProp** decorated state variable is created, the state variable is initialized with the value predefined in the **LocalStorage**. Changes made to the value in the **LocalStorage** will cause all UI components of the bound ability to update the state.

> **NOTE**
>
> If a **LocalStorage** instance has initial values assigned when being created, these values will be used for the **@LocalStorageLink** and **@LocalStorageProp** decorated state variables in the component. Otherwise, the initial values assigned for **@LocalStorageLink** and **@LocalStorageProp** will be used instead.

## LocalStorage

### constructor  

constructor(initializingProperties?: Object)

Creates and initializes a **LocalStorage** instance.

**Parameters**

| Name                   | Type    |  Mandatory | Default Value | Description                                    |
| ---------------------- | ------ | :--: | ---- | ---------------------------------------- |
| initializingProperties | Object |  No  | -    | Object attributes and their values returned by **object.keys(obj)**.|



### GetShared

static GetShared(): LocalStorage

Obtains the current shared **LocalStorage** object.

This API can be used only in the stage model.

**Return value**

| Type                           | Description               |
| ----------------------------- | ----------------- |
| [LocalStorage](#localstorage) | **LocalStorage** object.|



### has

has(propName: string): boolean

Checks whether the **LocalStorage** contains the specified attribute value.

**Parameters**

| Name     | Type    |  Mandatory | Default Value | Description   |
| -------- | ------ | :--: | ---- | ------- |
| propName | string |  Yes  | -    | Attribute value.|

**Return value**

| Type     | Description           |
| ------- | ------------- |
| boolean | Whether the attribute value is contained.|



### get

get\<T>(propName: string): T

Obtains the value corresponding to the given key.

**Parameters**

| Name     | Type    |  Mandatory | Default Value | Description       |
| -------- | ------ | :--: | ---- | ----------- |
| propName | string |  Yes  | -    | Key of the value to obtain.|

**Return value**

| Type            | Description                                      |
| -------------- | ---------------------------------------- |
| T \| undefined | Returns the value if it is found; returns **undefined** otherwise.|



### set

set\<T>(propName: string, newValue: T): boolean

Sets the value for the given key.

**Parameters**

| Name     | Type    |  Mandatory | Default Value | Description       |
| -------- | ------ | :--: | ---- | ----------- |
| propName | string |  Yes  | -    | Key of the value to set.  |
| newValue | T      |  Yes  | -    | Value to set.|

**Return value**

| Type     | Description                                 |
| ------- | ----------------------------------- |
| boolean | Returns **true** if the value is successfully set for the key; returns **false** otherwise.|



### setOrCreate

setOrCreate\<T>(propName: string, newValue: T): boolean

Creates or updates the value for the given key.

**Parameters**

| Name     | Type    |  Mandatory | Default Value | Description          |
| -------- | ------ | :--: | ---- | -------------- |
| propName | string |  Yes  | -    | Key of the value to create or update. |
| newValue | T      |  Yes  | -    | Value to create or update.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | Updates the value of the attribute and returns **true** if an attribute that has the same name as the specified key exists; creates an attribute with the specified value of the T type as its default value and returns **false** otherwise. **true** cannot be returned for **undefined** or **null**.|



### link

link\<T>(propName: string): T

Establishes two-way data binding between an attribute and this **LocalStorage** instance.

**Parameters**

| Name     | Type    |  Mandatory | Default Value | Description       |
| -------- | ------ | :--: | ---- | ----------- |
| propName | string |  Yes  | -    | Key of the target attribute.|

**Return value**

| Type  | Description                                      |
| ---- | ---------------------------------------- |
| T    | Returns the two-way data binding if an attribute that has the same name as the specified key exists; returns **undefined** otherwise.|



### setAndLink

setAndLink\<T>(propName: string, defaultValue: T): T

Establishes two-way data binding between an attribute and this **LocalStorage** instance. This API works in a way similar to the **link** API.

**Parameters**

| Name         | Type    |  Mandatory | Default Value | Description       |
| ------------ | ------ | :--: | ---- | ----------- |
| propName     | string |  Yes  | -    | Key of the target attribute.|
| defaultValue | T      |  Yes  | -    | Default value to set. |

**Return value**

| Type                                | Description                                                        |
| ------------------------------------ | ------------------------------------------------------------ |
| [@Link](ts-component-states-link.md) | Returns the value corresponding to the specified key if the key is stored in the **LocalStorage**; creates and returns a **Link** instance with the specified value as its default value otherwise.|



### prop

prop\<T>(propName: string): T

Establishes one-way data binding with an attribute to update its status.

**Parameters**

| Name     | Type    |  Mandatory | Default Value | Description         |
| -------- | ------ | :--: | ---- | ------------- |
| propName | string |  Yes  | -    | Key of the target attribute.|

**Return value**

| Type                                  | Description                                      |
| ------------------------------------ | ---------------------------------------- |
| [@Prop](ts-component-states-prop.md) | Returns one-way binding to an attribute with a given key if the attribute exists; returns **undefined** otherwise. This means that attribute changes made through the **LocalStorage** will be synchronized to the variable or component, but attribute changes made by the variable or component will not be synchronized to the **LocalStorage**. Note that the variables returned are immutable variables, which are applicable to mutable and immutable state variables. |



### setAndProp

setAndProp\<T>(propName: string, defaultValue: T): T

Sets up one-way data binding with the **localStorage**. This API works in a way similar to the **Prop** API.

**Parameters**

| Name         | Type    |  Mandatory | Default Value | Description           |
| ------------ | ------ | :--: | ---- | --------------- |
| propName     | string |  Yes  | -    | Key value in the key-value pair to be saved.|
| defaultValue | T      |  Yes  | -    | Default value to set.        |

**Return value**

| Type                                  | Description                                      |
| ------------------------------------ | ---------------------------------------- |
| [@Prop](ts-component-states-prop.md) | Returns the value corresponding to the specified key if the key is stored in the **LocalStorage**; creates and returns a **Prop** instance with the specified value as its default value otherwise.|



### delete

delete(propName: string): boolean

Deletes the key-value pair specified by key.

**Parameters**

| Name     | Type    |  Mandatory | Default Value | Description        |
| -------- | ------ | :--: | ---- | ------------ |
| propName | string |  Yes  | -    | Key value of the attribute to be deleted.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | Returns **true** if the key-value pair exists and is successfully deleted; returns **false** otherwise.|



### keys

keys(): IterableIterator\<string>

Searches for all keys.

**Return value**

| Type            | Description            |
| -------------- | -------------- |
| array\<string> | Returns an array of strings containing all keys.|



### size

size(): number

Number of existing key-value pairs.

**Return value**

| Type    | Description       |
| ------ | --------- |
| number | Number of key-value pairs.|



### Clear

clear(): boolean

Deletes all attributes.

**Return value**

| Type     | Description                               |
| ------- | --------------------------------- |
| boolean | Returns **true** if all attributes are deleted; returns **false** if any of the attributes is being referenced by a state variable.|

### Example 1 (Creating a LocalStorage in an Ability)

```ts
import Ability from '@ohos.application.Ability'
export default class MainAbility extends Ability {    
  storage : LocalStorage    
  onCreate() {    
    this.storage = new LocalStorage();
    this.storage.setOrCreate("storageSimpleProp",121);    
    console.log("[Demo MainAbility onCreate]"); 
  }  
  onDestroy() {    
    console.log("[Demo MainAbility onDestroy]")  
  }    
  onWindowStageCreate(windowStage) {
    windowStage.loadContent("pages/index",this.storage)    
  }    
  onWindowStageDestroy() {
    console.log("[Demo] MainAbility onWindoeStageDestroy") 
  }    
  onForeground() {
    console.log("[Demo] MainAbility onForeground")   
  }    
  onBackground() {
    console.log("[Demo] MainAbility onBackground")    
  }
}
```

The @Component decorated component obtains data.

```ts
let storage = LocalStorage.GetShared()
@Entry(storage)
@Component
struct LocalStorageComponent {
  @LocalStorageLink("storageSimpleProp") simpleVarName: number = 0
  build() {
    Column(){
      Text(this.simpleVarName.toString())
        .onClick(()=>{
          this.simpleVarName +=1;
        })
      Text(JSON.stringify(this.simpleVarName))
        .fontSize(50)
    }
    .height(500)
  }
}
```

### Example 2 (Defining LocalStorage on the Entry Page)

```ts
let storage = new LocalStorage({"PropA":47});
@Entry(storage)
@Component 
struct ComA {    
  @LocalStorageLink("PropA") storLink: number = 1;    
  build() {    
	Column() {        
	  Text(`Parent from LocalStorage ${ this.storLink }`)            				     
        .onClick(()=>this.storLink+=1)            
	  Child()    
 	}    
  }
}


@Component
struct Child{    
  @LocalStorageLink("PropA") storLink: number = 1;    
  build() {    
	Text(`Parent from LocalStorage ${ this.storLink }`)        
	  .onClick(()=>this.storLink+=1)    
  }
}
```
