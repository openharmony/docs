# State Management with Application-level Variables

The state management module provides APIs for data storage, persistent data management, Ability data storage, and environment status required by applications. The APIs for Ability data storage are supported since API version 9.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## AppStorage

### Link

Link(propName: string): any

Establishes two-way data binding between an attribute and this **LocalStorage** instance.

**Parameters**

| Name  | Type  | Mandatory| Description              |
| -------- | ------ | --- | --------------------- |
| propName | string | Yes  | Name of the target attribute.|

**Return value**

| Type | Description                                                        |
| ----- | ------------------------------------------------------------ |
| @Link | Returns two-way binding to this attribute if there is data with a given key. This means that attribute changes made by a variable or component will be synchronized to the **AppStorage**, and attribute changes made through the **AppStorage** will be synchronized to the variable or component.|

```ts
let simple = AppStorage.Link('simpleProp')
```

### SetAndLink

SetAndLink\<T>(propName: string, defaultValue: T): SubscribedAbstractProperty\<T>

Works in a way similar to the **Link** API. If the current key is stored in the **AppStorage**, the value corresponding to the key is returned. If the key has not been created, a **Link** instance corresponding to the default value is created and returned.

**Parameters**

| Name      | Type  | Mandatory| Description            |
| ------------ | ------ | --- | -------------------- |
| propName     | string | Yes  | Target key. |
| defaultValue | T      | Yes  | Default value to set.|

**Return value**

| Type | Description                                                        |
| ----- | ------------------------------------------------------------ |
| @Link | Returns the value corresponding to the key if the current key is stored in the **AppStorage**; creates and returns a **Link** instance corresponding to the default value if the key has not been created.|

```ts
let simple = AppStorage.SetAndLink('simpleProp', 121)
```

### Prop

Prop(propName: string): any

Establishes one-way data binding with an attribute to update its status.

**Parameters**

| Name  | Type  | Mandatory| Description           |
| -------- | ------ | --- | ------------------- |
| propName | string |  Yes | Target key.|

**Return value**

| Type | Description                                                        |
| ----- | ------------------------------------------------------------ |
| @Prop | Returns one-way binding to an attribute with a given key if the attribute exists. This means that attribute changes made through the **AppStorage** will be synchronized to the variable or component, but attribute changes made by the variable or component will be synchronized to the **AppStorage**. The variable returned by this method is an immutable one, which is applicable both to the variable and immutable state attributes. If the attribute with the specified key does not exist, **undefined** is returned.|

```ts
let simple = AppStorage.Prop('simpleProp')
```

### SetAndProp

SetAndProp\<S>(propName: string, defaultValue: S): SubscribedAbstractProperty\<S>;

Works in a way similar to the **Prop** API. If the current key is stored in the **AppStorage**, the value corresponding to the key is returned. If the key has not been created, a **Prop** instance corresponding to the default value is created and returned.

**Parameters**

| Name      | Type  | Mandatory| Description                   |
| ------------ | ------ | --- | --------------------------- |
| propName     | string |  Yes | Key in the key-value pair to be saved.|
| defaultValue | S      |  Yes | Default value to set.             |

**Return value**

| Type | Description                                                        |
| ----- | ------------------------------------------------------------ |
| @Prop | Returns the value corresponding to the key if the current key is stored in the **AppStorage**; creates and returns a **Prop** instance corresponding to the default value otherwise. |

```ts
let simple = AppStorage.SetAndProp('simpleProp', 121)
```

### Has

Has(propName: string): boolean

Checks whether the attribute corresponding to the specified key exists.

**Parameters**

| Name  | Type  | Mandatory| Description      |
| -------- | ------ | --- | -------------- |
| propName | string | Yes  | Key of the attribute.|

**Return value**

| Type   | Description                      |
| ------- | -------------------------- |
| boolean | Returns whether the attribute exists.|

```ts
let simple = AppStorage.Has('simpleProp')
```

### Get

Get\<T>(propName: string): T | undefined

Obtains the value of the specified key.

**Parameters**

| Name  | Type  | Mandatory| Description           |
| -------- | ------ | ---- | ------------------- |
| propName | string | Yes  | Key of the value to obtain.|

**Return value**

| Type              | Description                      |
| ------------------ | -------------------------- |
| boolean or undefined| Returns whether the value of the attribute exists.|

```ts
let simple = AppStorage.Get('simpleProp')
```

### Set

Set\<T>(propName: string, newValue: T): boolean

Replaces the value of a saved key.

**Parameters**

| Name  | Type  | Mandatory| Description         |
| -------- | ------ | --- | ----------------- |
| propName | string | Yes  | Key of the value to set. |
| newValue | T      | Yes  | Value to set.|

**Return value**

| Type   | Description                                                 |
| ------- | ----------------------------------------------------- |
| boolean | Returns **true** and the value if the key exists; returns **false** otherwise.|

```ts
let simple = AppStorage.Set('simpleProp', 121);
```

### SetOrCreate

SetOrCreate\<T>(propName: string, newValue: T): void

Creates or updates the value of the specified key.

**Parameters**

| Name  | Type  | Mandatory| Description                 |
| -------- | ------ | --- | ------------------------- |
| propName | string | Yes  | Key to set.  |
| newValue | T      | Yes  | Value to be updated or created.|

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Updates the value of the attribute and returns **true** if an attribute that has the same name as the specified key exists; creates an attribute with the specified value as its default value and returns **false** otherwise. **undefined** and **null** are not allowed to return **true**.|

```ts
let simple = AppStorage.SetOrCreate('simpleProp', 121)
```

### Delete

Delete(propName: string): boolean

Deletes the key-value pair that matches the specified key.

**Parameters**

| Name  | Type  | Mandatory| Description             |
| -------- | ------ | --- | --------------------- |
| propName | string | Yes  | Key of the target key-value pair.|

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **true** if the key-value pair exists and is successfully deleted; returns **false** otherwise.|

```ts
let simple = AppStorage.Delete('simpleProp')
```

### keys

keys(): IterableIterator\<string>

Searches for all keys.

**Return value**

| Type          | Description                        |
| -------------- | ---------------------------- |
| array\<string> | Returns an array of strings containing all keys.|

```ts
let simple = AppStorage.Keys()
```

### staticClear

staticClear(): boolean

Deletes all attributes.

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **true** if all attributes are deleted; returns **false** if any of the attributes is being referenced by a state variable.|

```ts
let simple = AppStorage.staticClear()
```

### IsMutable

IsMutable(propName: string): boolean

Checks whether an attribute exists and can be changed.

**Parameters**

| Name  | Type  | Mandatory| Description             |
| -------- | ------ | :--- | --------------------- |
| propName | string | Yes  | Key of the target attribute.|

**Return value**

| Type   | Description                                |
| ------- | ------------------------------------ |
| boolean | Returns whether the attribute exists and can be changed.|

```ts
let simple = AppStorage.IsMutable('simpleProp')
```

### Size

Size(): number

Checks the number of existing key-value pairs.

**Return value**

| Type  | Description              |
| ------ | ------------------ |
| number | Returns the number of key-value pairs.|

```ts
let simple = AppStorage.Size()
```

## LocalStorage<sup>9+</sup>

### constructor<sup>9+</sup>

constructor(initializingProperties?: Object)

Creates and initializes a **LocalStorage** object.

**Parameters**

| Name                | Type  | Mandatory| Description                                                    |
| ---------------------- | ------ | ---- | ------------------------------------------------------------ |
| initializingProperties | Object | No  | All object attributes and their values returned by **object.keys(obj)**.|

```ts
this.storage = new LocalStorage()
```

### GetShared<sup>9+</sup>

static GetShared(): LocalStorage

Obtains the **LocalStorage** object being shared.

This API can be used only in the stage model.

**Return value**

| Type                         | Description                  |
| ----------------------------- | ---------------------- |
| [LocalStorage](#localstorage) | **LocalStorage** object.|

```ts
let storage = LocalStorage.GetShared()
```

### has<sup>9+</sup>

has(propName: string): boolean

Checks whether the **LocalStorage** contains the specified attribute.

**Parameters**

| Name  | Type  | Mandatory| Description      |
| -------- | ------ | --- | -------------- |
| propName | string | Yes  | Key of the attribute.|

**Return value**

| Type   | Description                      |
| ------- | -------------------------- |
| boolean | Returns whether the attribute exists.|

```ts
this.storage = new LocalStorage()
this.storage.has('storageSimpleProp')
```

### get<sup>9+</sup>

get\<T>(propName: string): T

Obtains the value of the specified key.

**Parameters**

| Name  | Type  | Mandatory| Description           |
| -------- | ------ | --- | ------------------- |
| propName | string | Yes  | Key of the value to obtain.|

**Return value**

| Type          | Description                                                   |
| -------------- | ------------------------------------------------------- |
| T \| undefined | Returns the value of the specified key if it exists; returns **undefined** otherwise.|

```ts
this.storage = new LocalStorage()
let simpleValue = this.storage.get('storageSimpleProp')
```

### set<sup>9+</sup>

set\<T>(propName: string, newValue: T): boolean

Sets a new value for the specified key.

**Parameters**

| Name  | Type  | Mandatory| Description         |
| -------- | ------ | --- | ----------------- |
| propName | string | Yes  | Key to set.  |
| newValue | T      | Yes  | Value to set.|

**Return value**

| Type   | Description                                                 |
| ------- | ----------------------------------------------------- |
| boolean | Returns **true** if the specified key exists and the value is set; returns **false** otherwise.|

```ts
this.storage = new LocalStorage()
this.storage.set('storageSimpleProp', 121)
```

### setOrCreate<sup>9+</sup>

setOrCreate\<T>(propName: string, newValue: T): boolean

Creates or updates the value of the specified key.

**Parameters**

| Name  | Type  | Mandatory| Description               |
| -------- | ------ | :--- | ----------------------- |
| propName | string | Yes  | Key of the value to create or update.  |
| newValue | T      | Yes  | Value to be updated or created.|

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Updates the value of the attribute and returns **true** if an attribute that has the same name as the specified key exists; creates an attribute with the specified value as its default value and returns false otherwise. **undefined** and **null** are not allowed.|

```ts
this.storage = new LocalStorage()
this.storage.setOrCreate('storageSimpleProp', 121)
```

### link<sup>9+</sup>

link\<T>(propName: string): T

Establishes two-way data binding between an attribute and this **LocalStorage** instance.

**Parameters**

| Name  | Type  | Mandatory| Description              |
| -------- | ------ | --- | ---------------------- |
| propName | string | Yes  | Name of the target attribute.|

**Return value**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| T    | Returns two-way binding to this attribute if there is data with a given key. This means that attribute changes made by a variable or component will be synchronized to the **LocalStorage**, and attribute changes made through the **LocalStorage** will be synchronized to the variable or component. returns **undefined** if the attribute with the given key does not exist.|

```ts
this.storage = new LocalStorage()
let localStorage = this.storage.link('storageSimpleProp')
```

### setAndLink<sup>9+</sup>

setAndLink\<T>(propName: string, defaultValue: T): T

Works in a way similar to the **Link** API.

**Parameters**

| Name      | Type  | Mandatory| Description            |
| ------------ | ------ | --- | -------------------- |
| propName     | string | Yes  | Target key. |
| defaultValue | T      | Yes  | Default value to set.|

**Return value**

| Type                                | Description                                                        |
| ------------------------------------ | ------------------------------------------------------------ |
| @Link | Returns the value corresponding to the key if the current key is stored in the **LocalStorage**; creates and returns a **Link** instance corresponding to the default value if the key has not been created.|

```ts
this.storage = new LocalStorage()
let localStorage = this.storage.setAndLink('storageSimpleProp', 121)
```

### prop<sup>9+</sup>

prop\<T>(propName: string): T

Establishes one-way data binding with an attribute to update its status.

**Parameters**

| Name  | Type  | Mandatory| Description               |
| -------- | ------ | --- | ----------------------- |
| propName | string | Yes  | Key of the attribute.|

**Return value**

| Type                                | Description                                                        |
| ------------------------------------ | ------------------------------------------------------------ |
| @Prop | Returns one-way binding to an attribute with a given key if the attribute exists; returns **undefined** otherwise. This means that attribute changes made through the **LocalStorage** will be synchronized to the variable or component, but attribute changes made by the variable or component will be synchronized to the **LocalStorage**. This API returns immutable variables and is applicable to mutable and immutable state variables. |

```ts
this.storage = new LocalStorage()
let localStorage = this.storage.prop('storageSimpleProp')
```

### setAndProp<sup>9+</sup>

setAndProp\<T>(propName: string, defaultValue: T): T

Works in a way similar to the **Prop** API.

**Parameters**

| Name      | Type  | Mandatory| Description                 |
| ------------ | ------ | --- | ------------------------- |
| propName     | string | Yes  | Key of the target key-value pair.|
| defaultValue | T      | Yes  | Default value to set.           |

**Return value**

| Type                                | Description                                                        |
| ------------------------------------ | ------------------------------------------------------------ |
| @Prop | Returns the value corresponding to the given key if the key is stored in the **LocalStorage**; creates and returns a **Prop** instance corresponding to the default value if the key has not been created.|

```ts
this.storage = new LocalStorage()
let localStorage = this.storage.setAndProp('storageSimpleProp', 121)
```

### delete<sup>9+</sup>

delete(propName: string): boolean

Deletes the key-value pair that matches the specified key.

**Parameters**

| Name  | Type  | Mandatory| Description             |
| -------- | ------ | :--- | --------------------- |
| propName | string | Yes  | Key of the target key-value pair.|

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **true** if the key-value pair exists and is successfully deleted; returns **false** if the key-value pair does not exist, fails to be deleted, or is being referenced by a state varaiable.|

```ts
this.storage = new LocalStorage()
this.storage.delete('storageSimpleProp')
```

### keys<sup>9+</sup>

keys(): IterableIterator\<string>

Searches for all keys.

**Return value**

| Type          | Description                                  |
| -------------- | -------------------------------------- |
| array\<string> | Returns an array of strings containing all keys that are not serializable.|

```ts
this.storage = new LocalStorage()
let simple = this.storage.keys()
```

### size<sup>9+</sup>

size(): number

Obtains the number of existing key-value pairs.

**Return value**

| Type  | Description              |
| ------ | ------------------ |
| number | Returns the number of key-value pairs.|

```ts
this.storage = new LocalStorage()
let simple = this.storage.size()
```

### Clear<sup>9+</sup>

clear(): boolean

Deletes all attributes.

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **true** if all attributes are deleted; returns **false** if any of the attributes is being referenced by a state variable.|

```ts
this.storage = new LocalStorage()
let simple = this.storage.clear()
```

## PersistentStorage

### constructor

constructor(appStorage: AppStorage, storage: Storage)

Creates a **persistentstorage** object.

**Parameters**

| Name    | Type      | Mandatory| Description                        |
| ---------- | ---------- | --- | -------------------------------- |
| appStorage | AppStorage | Yes  | Singleton object that saves all attributes and attribute values.|
| storage    | Storage    | Yes  | **Storage** object.               |

```ts
this.persistentstorage = new PersistentStorage(AppStorage,Storage)
```

### PersistProp

PersistProp(key:string,defaultValue:T): void

Changes the attribute that matches the specified key to persistent data in the **AppStorage**.

**Parameters**

| Name      | Type  | Mandatory| Description               |
| ------------ | ------ | --- | ----------------------- |
| key          | string | Yes  | Key of the target attribute.  |
| defaultValue | T      | Yes  | Value of the target attribute.|

```ts
PersistentStorage.PersistProp('highScore', '0')
```

### DeleteProp

DeleteProp(key: string): void

Cancels two-way binding. The value of this attribute will be deleted from the persistent storage.

**Parameters**

| Name| Type  | Mandatory| Description             |
| ------ | ------ | --- | --------------------- |
| key    | string | Yes  | Key of the target attribute.|

```ts
PersistentStorage.DeleteProp('highScore')
```

### PersistProps

PersistProps(properties: {key: string, defaultValue: any}[]): void;

Changes the attributes that match the specified keys to persistent data in the **AppStorage**.

**Parameters**

| Name| Type                              | Mandatory| Description          |
| ------ | ---------------------------------- | -- | ------------------ |
| key    | {key: string, defaultValue: any}[] |  Yes | Keys of the target attributes.|

```ts
PersistentStorage.PersistProps([{key: 'highScore', defaultValue: '0'},{key: 'wightScore',defaultValue: '1'}])
```

### Keys

Keys(): Array\<string>

Returns the flags of all persistent attributes.

**Return value**

| Type         | Description                      |
| ------------- | -------------------------- |
| Array\<string> | Returns the flags of all persistent attributes.|

```ts
let simple = PersistentStorage.Keys()
```

> **NOTE**
>
> - When using **PersistProp**, ensure that the input key exists in the **AppStorage**.
>
> - **DeleteProp** takes effect only for the data that has been linked during the current startup.

## Environment

### constructor

Creates an **Environment** object.

```ts
let simple = new Environment()
```

### EnvProp

EnvProp\<S>(key: string, value: S): boolean

Binds this system attribute to the **AppStorage**. You are advised to use this API during application startup. If the attribute already exists in the **AppStorage**, **false** is returned. Do not use the variables in the **AppStorage**. Instead, call this API to bind environment variables.

**Parameters**

| Name| Type  | Mandatory| Description       |
| ------ | ------ | --- | --------------- |
| key    | string | Yes  | Key of the target attribute. For details, see **Built-in environment variables**. |
| value  | S      | Yes  | Value of the target attribute.|

**Return value**

| Type   | Description                              |
| ------- | ---------------------------------- |
| boolean | Returns whether the attribute exists in the **AppStorage**.|

**Built-in environment variables**

| key          |       Type   |      Description           |
| ------------ | ------------- | ------------------- |
| accessibilityEnabled | string | Whether to enable accessibility.           |
| colorMode | ColorMode | Color mode. The options are as follows:<br>- **ColorMode.LIGHT**: light mode.<br>- **ColorMode.DARK**: dark mode.  |
| fontScale | number | Font scale.           |
| fontWeightScale | number | Font weight scale.           |
| layoutDirection | LayoutDirection | Layout direction. The options are as follows:<br>- **LayoutDirection.LTR**: The direction is from left to right.<br>- **LayoutDirection.RTL**: The direction is from right to left.  |
| languageCode | string |     Current system language. The value is in lowercase, for example, **zh**.           |

```ts
Environment.EnvProp('accessibilityEnabled', 'default')
```

### EnvProps

EnvProps(props: {key: string, defaultValue: any}[]): void

Associates this system item array with the **AppStorage**.

**Parameters**

| Name| Type                              | Mandatory| Description          |
| ------ | ---------------------------------- | --- | ------------------ |
| key    | {key: string, defaultValue: any}[] | Yes  | Keys of the target attributes.|

```ts
Environment.EnvProps([{key: 'accessibilityEnabled', defaultValue: 'default'},{key: 'accessibilityUnEnabled', defaultValue: 'undefault'}])
```

### Keys

Keys(): Array\<string>

Returns an array of associated system attributes.

**Return value**

| Type         | Description                  |
| ------------- | ---------------------- |
| Array\<string> | Returns an array of associated system attributes.|

```ts
let simple = Environment.Keys()
```
