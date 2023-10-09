# AppStorage: Application-wide UI State Storage


AppStorage provides the central storage for mutable application UI state attributes. It is bound to the application process and is created by the UI framework at application startup.


Unlike LocalStorage, which is usually used for page-level state sharing, AppStorage enables application-wide UI state sharing. AppStorage is equivalent to the hub of the entire application. [PersistentStorage](arkts-persiststorage.md) and [Environment](arkts-environment.md) data is passed first to AppStorage and then from AppStorage to the UI component.


This topic describes only the AppStorage application scenarios and related decorators: \@StorageProp and \@StorageLink.


## Overview

AppStorage is a singleton object that is created at application startup. Its purpose is to provide the central storage for mutable application UI state attributes. AppStorage retains all those attributes and their values as long as the application remains running. Attributes are accessed using a unique key string value.

UI components synchronize application state attributes with the AppStorage. Implementation of application business logic can access AppStorage as well.

Selected state attributes of AppStorage can be synced with different data sources or data sinks. Those data sources and sinks can be on a local or remote device, and have different capabilities, such as data persistence (see [PersistentStorage](arkts-persiststorage.md)). These data sources and sinks are implemented in the business logic, separate from the UI. Link those AppStorage attributes to [@StorageProp](#storageprop) and [@StorageLink](#storagelink) whose values should be kept until application re-start.


## \@StorageProp

As mentioned above, if you want to establish a binding between AppStorage and a custom component, you'll need the \@StorageProp and \@StorageLink decorators. Use \@StorageProp(key) or \@StorageLink(key) to decorate variables in the component, where **key** identifies the attribute in AppStorage.

When a custom component is initialized, the \@StorageProp(key)/\@StorageLink(key) decorated variable is initialized with the value of the attribute with the given key in AppStorage. Whether the attribute with the given key exists in AppStorage depends on the application logic. This means that the attribute with the given key may be missing from AppStorage. In light of this, local initialization is mandatory for the \@StorageProp(key)/\@StorageLink(key) decorated variable.

By decorating a variable with \@StorageProp(key), a one-way data synchronization is established with the attribute with the given key in AppStorage. A local change can be made, but it will not be synchronized to AppStorage. An update to the attribute with the given key in AppStorage will overwrite local changes.


### Rules of Use

| \@StorageProp Decorator| Description                                      |
| ------------------ | ---------------------------------------- |
| Decorator parameters             | **key**: constant string, mandatory (note, the string is quoted)                 |
| Allowed variable types         | Object, class, string, number, Boolean, enum, and array of these types. For details about the scenarios of nested objects, see [Observed Changes and Behavior](#observed-changes-and-behavior).<br>The type must be specified. Whenever possible, use the same type as that of the corresponding attribute in AppStorage. Otherwise, implicit type conversion occurs, causing application behavior exceptions. **any** is not supported. The **undefined** and **null** values are not allowed.|
| Synchronization type              | One-way: from the attribute in AppStorage to the component variable.<br>The component variable can be changed locally, but an update from AppStorage will overwrite local changes.|
| Initial value for the decorated variable         | Mandatory. It is used as the default value for initialization if the attribute does not exist in AppStorage.|


### Variable Transfer/Access Rules

| Transfer/Access     | Description                                      |
| ---------- | ---------------------------------------- |
| Initialization and update from the parent component| Forbidden.|
| Subnode initialization    | Supported; can be used to initialize an \@State, \@Link, \@Prop, or \@Provide decorated variable in the child component.|
| Access | Not supported.                                      |


  **Figure 1** \@StorageProp initialization rule 


![en-us_image_0000001552978157](figures/en-us_image_0000001552978157.png)


### Observed Changes and Behavior

**Observed Changes**


- When the decorated variable is of the Boolean, string, or number type, its value change can be observed.

- When the decorated variable is of the class or Object type, its value change and value changes of all its attributes, that is, the attributes that **Object.keys(observedObject)** returns.

- When the decorated variable is of the array type, the addition, deletion, and updates of array items can be observed.


**Framework Behavior**


- When the value change of the \@StorageProp(key) decorated variable is observed, the change is not synchronized to the attribute with the give key value in AppStorage.

- The value change of the \@StorageProp(key) decorated variable only applies to the private member variables of the current component, but not other variables bound to the key.

- When the data decorated by \@StorageProp(key) is a state variable, the change of the data is not synchronized to AppStorage, but the owning custom component is re-rendered.

- When the attribute with the given key in AppStorage is updated, the change is synchronized to all the \@StorageProp(key) decorated data, and the local changes of the data are overwritten.


## \@StorageLink

\@StorageLink(key) creates a two-way data synchronization with the attribute with the given key in AppStorage.

1. If a local change occurs, it is synchronized to AppStorage.

2. Changes in AppStorage are synchronized to all attributes with the given key, including one-way bound variables (\@StorageProp decorated variables and one-way bound variables created through \@Prop), two-way bound variables (\@StorageLink decorated variables and two-way bound variables created through \@Link), and other instances (such as PersistentStorage).


### Rules of Use

| \@StorageLink Decorator| Description                                      |
| ------------------ | ---------------------------------------- |
| Decorator parameters             | **key**: constant string, mandatory (note, the string is quoted)                 |
| Allowed variable types         | Object, class, string, number, Boolean, enum, and array of these types. For details about the scenarios of nested objects, see [Observed Changes and Behavior](#observed-changes-and-behavior).<br>The type must be specified. Whenever possible, use the same type as that of the corresponding attribute in AppStorage. Otherwise, implicit type conversion occurs, causing application behavior exceptions. **any** is not supported. The **undefined** and **null** values are not allowed.|
| Synchronization type              | Two-way: from the attribute in AppStorage to the custom component variable and back|
| Initial value for the decorated variable         | Mandatory. It is used as the default value for initialization if the attribute does not exist in AppStorage.|


### Variable Transfer/Access Rules

| Transfer/Access     | Description                                      |
| ---------- | ---------------------------------------- |
| Initialization and update from the parent component| Forbidden.                                     |
| Subnode initialization    | Supported; can be used to initialize a regular variable or \@State, \@Link, \@Prop, or \@Provide decorated variable in the child component.|
| Access | Not supported.                                      |


  **Figure 2** \@StorageLink initialization rule 


![en-us_image_0000001501938718](figures/en-us_image_0000001501938718.png)


### Observed Changes and Behavior

**Observed Changes**


- When the decorated variable is of the Boolean, string, or number type, its value change can be observed.

- When the decorated variable is of the class or Object type, its value change and value changes of all its attributes, that is, the attributes that **Object.keys(observedObject)** returns.

- When the decorated variable is of the array type, the addition, deletion, and updates of array items can be observed.


**Framework Behavior**


1. When the value change of the \@StorageLink(key) decorated variable is observed, the change is synchronized to the attribute with the give key value in AppStorage.

2. Once the attribute with the given key in AppStorage is updated, all the data (including \@StorageLink and \@StorageProp decorated variables) bound to the attribute key is changed synchronously.

3. When the data decorated by \@StorageLink(key) is a state variable, the change of the data is synchronized to AppStorage, and the owning custom component is re-rendered.


## Application Scenarios


### Example of Using AppStorage and LocalStorage from Application Logic

Since AppStorage is a singleton, its APIs are all static ones. How these APIs work resembles the non-static APIs of LocalStorage.


```ts
AppStorage.setOrCreate('PropA', 47);

let storage: LocalStorage = new LocalStorage();
storage['PropA'] = 17;
let propA: number | undefined = AppStorage.get('PropA') // propA in AppStorage == 47, propA in LocalStorage == 17
let link1: SubscribedAbstractProperty<number> = AppStorage.link('PropA'); // link1.get() == 47
let link2: SubscribedAbstractProperty<number> = AppStorage.link('PropA'); // link2.get() == 47
let prop: SubscribedAbstractProperty<number> = AppStorage.prop('PropA'); // prop.get() == 47

link1.set(48); // two-way sync: link1.get() == link2.get() == prop.get() == 48
prop.set(1); // one-way sync: prop.get() == 1; but link1.get() == link2.get() == 48
link1.set(49); // two-way sync: link1.get() == link2.get() == prop.get() == 49

storage.get<number>('PropA') // == 17
storage.set('PropA', 101);
storage.get<number>('PropA') // == 101

AppStorage.get<number>('PropA') // == 49
link1.get() // == 49
link2.get() // == 49
prop.get() // == 49
```


### Example of Using AppStorage and LocalStorage from Inside the UI

\@StorageLink works together with the AppStorage in the same way as \@LocalStorageLink works together with LocalStorage. It creates two-way data synchronization with an attribute in AppStorage.


```ts
AppStorage.setOrCreate('PropA', 47);
let storage = new LocalStorage();
storage['PropA'] = 48;

@Entry(storage)
@Component
struct CompA {
  @StorageLink('PropA') storLink: number = 1;
  @LocalStorageLink('PropA') localStorLink: number = 1;

  build() {
    Column({ space: 20 }) {
      Text(`From AppStorage ${this.storLink}`)
        .onClick(() => this.storLink += 1)

      Text(`From LocalStorage ${this.localStorLink}`)
        .onClick(() => this.localStorLink += 1)
    }
  }
}
```

### Unrecommended: Using @StorageLink to Implement Event Notification

Compared with the common mechanism for event notification, the two-way synchronization mechanism of @StorageLink and AppStorage is far less cost efficient and therefore not recommended. This is because AppStorage stores UI-related data, and its changes will cause costly UI refresh.

In the following example, any tap event in the **TapImage** component will trigger a change of the **tapIndex** attribute. As @StorageLink establishes a two-way data synchronization with AppStorage, the local change is synchronized to AppStorage. As a result, all custom components owning the **tapIndex** attribute bound to AppStorage are notified to refresh the UI.  


```ts
// xxx.ets
class ViewData {
  title: string;
  uri: Resource;
  color: Color = Color.Black;

  constructor(title: string, uri: Resource) {
    this.title = title;
    this.uri = uri
  }
}

@Entry
@Component
struct Gallery2 {
  dataList: Array<ViewData> = [new ViewData('flower', $r('app.media.icon')), new ViewData('OMG', $r('app.media.icon')), new ViewData('OMG', $r('app.media.icon'))]
  scroller: Scroller = new Scroller()

  build() {
    Column() {
      Grid(this.scroller) {
        ForEach(this.dataList, (item: ViewData, index?: number) => {
          GridItem() {
            TapImage({
              uri: item.uri,
              index: index
            })
          }.aspectRatio(1)

        }, (item: ViewData, index?: number) => {
          return JSON.stringify(item) + index;
        })
      }.columnsTemplate('1fr 1fr')
    }

  }
}

@Component
export struct TapImage {
  @StorageLink('tapIndex') @Watch('onTapIndexChange') tapIndex: number = -1;
  @State tapColor: Color = Color.Black;
  private index: number = 0;
  private uri: Resource = {
    id: 0,
    type: 0,
    moduleName: "",
    bundleName: ""
  };

  // Check whether the component is selected.
  onTapIndexChange() {
    if (this.tapIndex >= 0 && this.index === this.tapIndex) {
      console.info(`tapindex: ${this.tapIndex}, index: ${this.index}, red`)
      this.tapColor = Color.Red;
    } else {
      console.info(`tapindex: ${this.tapIndex}, index: ${this.index}, black`)
      this.tapColor = Color.Black;
    }
  }

  build() {
    Column() {
      Image(this.uri)
        .objectFit(ImageFit.Cover)
        .onClick(() => {
          this.tapIndex = this.index;
        })
        .border({ width: 5, style: BorderStyle.Dotted, color: this.tapColor })
    }

  }
}
```

To implement event notification with less overhead and higher code readability, use **emit** instead, with which you can subscribe to an event and receive event callback.


```ts
// xxx.ets
import emitter from '@ohos.events.emitter';

let NextID: number = 0;

class ViewData {
  title: string;
  uri: Resource;
  color: Color = Color.Black;
  id: number;

  constructor(title: string, uri: Resource) {
    this.title = title;
    this.uri = uri
    this.id = NextID++;
  }
}

@Entry
@Component
struct Gallery2 {
  dataList: Array<ViewData> = [new ViewData('flower', $r('app.media.icon')), new ViewData('OMG', $r('app.media.icon')), new ViewData('OMG', $r('app.media.icon'))]
  scroller: Scroller = new Scroller()
  private preIndex: number = -1

  build() {
    Column() {
      Grid(this.scroller) {
        ForEach(this.dataList, (item: ViewData) => {
          GridItem() {
            TapImage({
              uri: item.uri,
              index: item.id
            })
          }.aspectRatio(1)
          .onClick(() => {
            if (this.preIndex === item.id) {
              return
            }
            let innerEvent: emitter.InnerEvent = { eventId: item.id }
            // Selected: from black to red
            let eventData: emitter.EventData = {
              data: {
                "colorTag": 1
              }
            }
            emitter.emit(innerEvent, eventData)

            if (this.preIndex != -1) {
              console.info(`preIndex: ${this.preIndex}, index: ${item.id}, black`)
              let innerEvent: emitter.InnerEvent = { eventId: this.preIndex }
              // Deselected: from red to black
              let eventData: emitter.EventData = {
                data: {
                  "colorTag": 0
                }
              }
              emitter.emit(innerEvent, eventData)
            }
            this.preIndex = item.id
          })
        }, (item: ViewData) => JSON.stringify(item))
      }.columnsTemplate('1fr 1fr')
    }

  }
}

@Component
export struct TapImage {
  @State tapColor: Color = Color.Black;
  private index: number = 0;
  private uri: Resource = {
    id: 0,
    type: 0,
    moduleName: "",
    bundleName: ""
  };

  onTapIndexChange(colorTag: emitter.EventData) {
    if (colorTag.data != null) {
      this.tapColor = colorTag.data.colorTag ? Color.Red : Color.Black
    }
  }

  aboutToAppear() {
    // Define the event ID.
    let innerEvent: emitter.InnerEvent = { eventId: this.index }
    emitter.on(innerEvent, data => {
    this.onTapIndexChange(data)
    })
  }

  build() {
    Column() {
      Image(this.uri)
        .objectFit(ImageFit.Cover)
        .border({ width: 5, style: BorderStyle.Dotted, color: this.tapColor })
    }
  }
}
```

The preceding notification logic is simple. It can be simplified into a ternary expression as follows:

```
// xxx.ets
class ViewData {
  title: string;
  uri: Resource;
  color: Color = Color.Black;

  constructor(title: string, uri: Resource) {
    this.title = title;
    this.uri = uri
  }
}

@Entry
@Component
struct Gallery2 {
  dataList: Array<ViewData> = [new ViewData('flower', $r('app.media.icon')), new ViewData('OMG', $r('app.media.icon')), new ViewData('OMG', $r('app.media.icon'))]
  scroller: Scroller = new Scroller()

  build() {
    Column() {
      Grid(this.scroller) {
        ForEach(this.dataList, (item: ViewData, index?: number) => {
          GridItem() {
            TapImage({
              uri: item.uri,
              index: index
            })
          }.aspectRatio(1)

        }, (item: ViewData, index?: number) => {
          return JSON.stringify(item) + index;
        })
      }.columnsTemplate('1fr 1fr')
    }

  }
}

@Component
export struct TapImage {
  @StorageLink('tapIndex') tapIndex: number = -1;
  @State tapColor: Color = Color.Black;
  private index: number = 0;
  private uri: Resource = {
    id: 0,
    type: 0,
    moduleName: "",
    bundleName: ""
  };

  build() {
    Column() {
      Image(this.uri)
        .objectFit(ImageFit.Cover)
        .onClick(() => {
          this.tapIndex = this.index;
        })
        .border({
          width: 5,
          style: BorderStyle.Dotted,
          color: (this.tapIndex >= 0 && this.index === this.tapIndex) ? Color.Red : Color.Black
        })
    }
  }
}
```



## Restrictions

When using AppStorage together with [PersistentStorage](arkts-persiststorage.md) and [Environment](arkts-environment.md), pay attention to the following:

- A call to **PersistentStorage.persistProp()** after creating the attribute in AppStorage uses the type and value in AppStorage and overwrites any attribute with the same name in PersistentStorage. In light of this, the opposite order of calls is recommended. For an example of incorrect usage, see [Accessing Attribute in AppStorage Before PersistentStorage](arkts-persiststorage.md#accessing-attribute-in-appstorage-before-persistentstorage).

- A call to **Environment.envProp()** after creating the attribute in AppStorage will fail. This is because AppStorage already has an attribute with the same name, and the environment variable will not be written into AppStorage. Therefore, you are advised not to use the preset environment variable name in AppStorage.

- Changes to the variables decorated by state decorators will cause UI re-render. If the changes are for message communication, rather than for UI re-render, the emitter mode is recommended. For the example, see [Unrecommended: Using @StorageLink to Implement Event Notification](#unrecommended-using-storagelink-to-implement-event-notification).
<!--no_check-->
