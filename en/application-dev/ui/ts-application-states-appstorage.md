# AppStorage


AppStorage is a singleton object in an application, which is created by the UI framework when the application is started and destroyed when the application exits. It is used to provide central storage for changing state attributes of an application. AppStorage contains all the state attributes that need to be accessed throughout the application. The AppStorage retains all attributes and their values as long as the application remains running, and the attribute values can be accessed through unique key values.


The UI component can synchronize the application state data with the AppStorage through the decorators. The application service logic can also be implemented by accessing the AppStorage through APIs.


The selection state attribute of the AppStorage can be synchronized with different data sources or data sinks. These data sources and data sinks can be local or remote devices and provide different functions, such as data persistence. Such data sources and data sinks can be implemented independently of the UI in the service logic.


By default, the attributes in the AppStorage are changeable. If needed, AppStorage can also use immutable (read-only) attributes.


## AppStorage APIs

| Name | Type | Return Value | Definition |
| -------- | -------- | -------- | -------- |
| SetAndLink | key: string,<br/>defaultValue: T | @Link | Works in a way similar to the Link API. If the current key is stored in the AppStorage, the value corresponding to the key is returned. If the key has not been created, a Link instance corresponding to the default value is created and returned. |
| Set | key: string,<br/>newValue: T | void | Replaces the value of a saved key. |
| Link | key: string | @Link | Returns two-way binding to this attribute if there is data with a given key. This means that attribute changes made by a variable or component will be synchronized to the AppStorage, and attribute changes made through the AppStorage will be synchronized to the variable or component. If the attribute with this key does not exist or is read-only, undefined is returned. |
| SetAndProp | propName: string,<br/>defaultValue: S | @Prop | Works in a way similar to the Prop API. If the current key is stored in the AppStorage, the value corresponding to the key is returned. If the key has not been created, a Prop instance corresponding to the default value is created and returned. |
| Prop | key: string | @Prop | Returns one-way binding to an attribute with a given key if the attribute exists. This means that attribute changes made through the AppStorage will be synchronized to the variable or component, but attribute changes made by the variable or component will be synchronized to the AppStorage. The variable returned by this method is an immutable one, which is applicable both to the variable and immutable state attributes. If the attribute with the specified key does not exist, undefined is returned.<br/>> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**:<br/>> The attribute value used in the prop method must be of a simple type. |
| SetOrCreate | key: string,<br/>newValue: T | boolean | If an attribute that has the same name as the specified key exists: replaces the value of the attribute and returns true when the attribute can be modified; retains the original value of the attribute and returns false otherwise.<br/>If an attribute that has the same name as the specified key does not exist: creates an attribute whose key is key and value is newValue. The values null and undefined are not supported. |
| Get | key: string | T or undefined | Obtains the value of the specified key. |
| Has | propName: string | boolean | Checks whether the attribute corresponding to the specified key value exists. |
| Keys | void | array&lt;string&gt; | Returns an array of strings containing all keys. |
| Delete | key: string | boolean | Deletes the key-value pair for the specified key. Returns true if the key-value pair exists and is successfully deleted; returns false otherwise. |
| Clear | void | boolean | Deletes all attributes. If any of the attributes is being referenced by a state variable, false is returned. |
| IsMutable | key: string | boolean | Specifies whether the attribute exists and can be changed. |


## Synchronization Between AppStorage and Components

In [Managing Component States](ts-component-states-state.md), we have defined how to synchronize the state variables of child components with the @State decorated variables in the parent component or ancestor component, including @Prop, @Link, and @Consume.

In this section, we'll describe how to synchronize component variables with the AppStorage through the @StorageLink and @StorageProp decorators.


### @StorageLink Decorator

Two-way data binding can be established between components and the AppStorage through state variables decorated by @StorageLink(_key_). Wherein, key is the attribute key value in the AppStorage. When a component containing the @StorageLink decorated variable is created, the variable is initialized using the value in the AppStorage. Changes made to this variable in the component will be first synchronized to the AppStorage, and then to other bound instances, such as PersistentStorage or other bound UI components.


### @StorageProp Decorator

One-way data binding can be established between components and the AppStorage through state variables decorated by @StorageProp(_key_). Wherein, key is the attribute key value in the AppStorage. When a component containing the @StorageProp decorated variable is created, the variable is initialized using the value in the AppStorage. Changes made to the value in the AppStorage will cause the bound UI component to update the state.


## Example


```
let varA = AppStorage.Link('varA')
let envLang = AppStorage.Prop('languageCode')

@Entry
@Component
struct ComponentA {
  @StorageLink('varA') varA: number = 2
  @StorageProp('languageCode') lang: string = 'en'
  private label: string = 'count'

  aboutToAppear() {
    this.label = (this.lang === 'en') ? 'Number' : 'Count'
  }

  build() {
    Row({ space: 20 }) {

      Button(`${this.label}: ${this.varA}`)
        .onClick(() => {
          AppStorage.Set<number>('varA', AppStorage.Get<number>('varA') + 1)
        })
      Button(`lang: ${this.lang}`)
        .onClick(() => {
          if (this.lang === 'zh') {
            AppStorage.Set<string>('languageCode', 'en')
          } else {
            AppStorage.Set<string>('languageCode', 'en')
          }
          this.label = (this.lang === 'en') ? 'Number' : 'Count'
        })
    }
  }
}
```

Each time the user clicks the **Count** button, the value of **this.varA** will increase by 1. This variable is synchronized with varA in the AppStorage. Each time the user clicks the language icon, the value of **languageCode** in the AppStorage will be changed, and the change will be synchronized to the **this.lang** variable.
