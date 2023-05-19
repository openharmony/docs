# State Management with Application-level Variables


The state management module provides data storage, persistent data management, UIAbility data storage, and environment state required by applications.


>**NOTE**
>
>The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


The meanings of T and S in this topic are as follows:


| Type  | Description                                    |
| ---- | -------------------------------------- |
| T    | Class, number, boolean, string, and arras of these types.|
| S    | number, boolean, string.                |


## AppStorage


### Link

static Link(propName: string): any

Establishes two-way data binding with the given attribute (specified by **propName**) in AppStorage. If the given attribute exists in AppStorage, the two-way bound data of the attribute in AppStorage is returned.

Any update of the data is synchronized back to AppStorage, which then synchronizes the update to all data and custom components bound to the attribute.

If the given attribute does not exist in AppStorage, **undefined** is returned.

**Parameters**

| Name     | Type    | Mandatory  | Description            |
| -------- | ------ | ---- | ---------------- |
| propName | string | Yes   | Attribute name in AppStorage.|

**Return value**

| Type  | Description                                      |
| ---- | ---------------------------------------- |
| any  | Returns two-way bound data if specified attribute exists in AppStorage; returns **undefined** otherwise.|


```ts
AppStorage.SetOrCreate('PropA', 47);
let linkToPropA1 = AppStorage.Link('PropA');
let linkToPropA2 = AppStorage.Link('PropA'); // linkToPropA2.get() == 47
linkToPropA1.set(48); // Two-way synchronization: linkToPropA1.get() == linkToPropA2.get() == 48
```


### SetAndLink

static SetAndLink&lt;T&gt;(propName: string, defaultValue: T): SubscribedAbstractProperty&lt;T&gt;

Works in a way similar to the **Link** API. If the given attribute exists in AppStorage, the two-way bound data of the attribute in AppStorage is returned. If the given attribute does not exist, it is created and initialized with **defaultValue** in AppStorage, and two-way bound data is returned.

**Parameters**

| Name         | Type    | Mandatory  | Description                                    |
| ------------ | ------ | ---- | ---------------------------------------- |
| propName     | string | Yes   | Attribute name in AppStorage.                        |
| defaultValue | T      | Yes   | Default value used to initialize the attribute with the specified attribute name in AppStorage.|

**Return value**

| Type                                 | Description                                      |
| ----------------------------------- | ---------------------------------------- |
| SubscribedAbstractProperty&lt;T&gt; | Instance of **SubscribedAbstractProperty&lt;T&gt;** and two-way bound data of the given attribute in AppStorage|


```ts
AppStorage.SetOrCreate('PropA', 47);
let link1: SubscribedAbstractProperty<number> = AppStorage.SetAndLink('PropB', 49); // Create PropB 49
let link2: SubscribedAbstractProperty<number> = AppStorage.SetAndLink('PropA', 50); // PropA exists, remains 47
```


### Prop

static Prop(propName: string): any

Establishes one-way data binding with the given attribute (specified by **propName**) in AppStorage. If the given attribute exists in AppStorage, the one-way bound data of the attribute in AppStorage is returned. If the given attribute does not exist in AppStorage, **undefined** is returned. Updates of the one-way bound data are not synchronized back to AppStorage.

>**NOTE**
> Prop supports only simple types.

**Parameters**

| Name     | Type    | Mandatory  | Description            |
| -------- | ------ | ---- | ---------------- |
| propName | string | Yes   | Attribute name in AppStorage.|

**Return value**

| Type  | Description                                      |
| ---- | ---------------------------------------- |
| any  | Returns one-way bound data if specified attribute exists in AppStorage; returns **undefined** otherwise.|


```ts
AppStorage.SetOrCreate('PropA', 47);
let prop1 = AppStorage.Prop('PropA');
let prop2 = AppStorage.Prop('PropA');
prop1.set(1); // one-way sync: prop1.get()=1; but prop2.get() == 47
```


### SetAndProp

static SetAndProp&lt;S&gt;(propName: string, defaultValue: S): SubscribedAbstractProperty&lt;S&gt;

Works in a way similar to the **Prop** API. If the given attribute exists in AppStorage, the one-way bound data of the attribute in AppStorage is returned. If the given attribute does not exist, it is created and initialized with **defaultValue** in AppStorage, and one-way bound data is returned.

**Parameters**

| Name         | Type    | Mandatory  | Description                                    |
| ------------ | ------ | ---- | ---------------------------------------- |
| propName     | string | Yes   | Attribute name in AppStorage.                        |
| defaultValue | S      | Yes   | Default value used to initialize the attribute with the specified attribute name in AppStorage.|

**Return value**

| Type                                 | Description                                     |
| ----------------------------------- | --------------------------------------- |
| SubscribedAbstractProperty&lt;S&gt; | Instance of **SubscribedAbstractProperty&lt;S&gt;**.|


```ts
AppStorage.SetOrCreate('PropA', 47);
let prop: SubscribedAbstractProperty<number> = AppStorage.SetAndProp('PropB', 49); // PropA -> 47, PropB -> 49
```


### Has

static Has(propName: string): boolean

Checks whether the attribute with the specified attribute name exists in AppStorage.

**Parameters**

| Name     | Type    | Mandatory  | Description            |
| -------- | ------ | ---- | ---------------- |
| propName | string | Yes   | Attribute name in AppStorage.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | Returns **true** if the attribute with the specified attribute name exists in AppStorage; returns **false** otherwise.|


```ts
AppStorage.Has('simpleProp');
```


### Get

static Get&lt;T&gt;(propName: string): T | undefined

Obtains the attribute with the specified attribute name in AppStorage. If the attribute does not exist, **undefined** is returned.

**Parameters**

| Name     | Type    | Mandatory  | Description            |
| -------- | ------ | ---- | ---------------- |
| propName | string | Yes   | Attribute name in AppStorage.|

**Return value**

| Type                      | Description                                      |
| ------------------------ | ---------------------------------------- |
| T&nbsp;\|&nbsp;undefined | Returns the attribute with the specified attribute name in AppStorage; returns **undefined** if the attribute does not exist.|


```ts
AppStorage.SetOrCreate('PropA', 47);
let value: number = AppStorage.Get('PropA'); // 47
```


### Set

static Set&lt;T&gt;(propName: string, newValue: T): boolean

Sets the value for the attribute with the specified attribute name in AppStorage.

**Parameters**

| Name     | Type    | Mandatory  | Description                  |
| -------- | ------ | ---- | ---------------------- |
| propName | string | Yes   | Attribute name in AppStorage.      |
| newValue | T      | Yes   | Attribute value, which cannot be **undefined** or **null**.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | Returns **true** if the operation is successful; return **false** if the attribute with the specified attribute name does not exist in AppStorage, or the value to set is **undefined** or **null**.  |


```ts
AppStorage.SetOrCreate('PropA', 48);
let res: boolean = AppStorage.Set('PropA', 47) // true
let res1: boolean = AppStorage.Set('PropB', 47) // false
```


### SetOrCreate

static SetOrCreate&lt;T&gt;(propName: string, newValue: T): void

Sets a new value for the attribute with the specified attribute name in AppStorage or, if the attribute does not exist, creates one with the specified attribute name and default value.

**Parameters**

| Name     | Type    | Mandatory  | Description                  |
| -------- | ------ | ---- | ---------------------- |
| propName | string | Yes   | Attribute name in AppStorage.      |
| newValue | T      | Yes   | Attribute value, which cannot be **undefined** or **null**.|


```ts
AppStorage.SetOrCreate('simpleProp', 121);
```


### Delete

static Delete(propName: string): boolean

Deletes the attribute with the specified attribute name from AppStorage

under the prerequisite that the attribute does not have a subscriber. If there is a subscriber, **false** is returned. If the deletion is successful, **true** is returned.

The subscribers of the attribute are attributes with the same name bound to APIs such as **Link** and **Prop**, **\@StorageLink('propName')**, and **\@StorageProp('propName')**. This means that if **\@StorageLink('propName')** and **\@StorageProp('propName')** are used in a custom component or if there is still a **SubscribedAbstractProperty** instance in sync with the attribute, the attribute cannot be deleted from AppStorage.

**Parameters**

| Name     | Type    | Mandatory  | Description            |
| -------- | ------ | ---- | ---------------- |
| propName | string | Yes   | Attribute name in AppStorage.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|


```ts
AppStorage.SetOrCreate('PropA', 47);
AppStorage.Link('PropA');
let res: boolean = AppStorage.Delete('PropA'); // false, PropA still has a subscriber

AppStorage.SetOrCreate('PropB', 48);
let res1: boolean = AppStorage.Delete('PropB'); // true, PropB is deleted from AppStorage successfully
```


### Keys

static Keys(): IterableIterator&lt;string&gt;

Obtains all attribute names in AppStorage.

**Return value**

| Type                            | Description                |
| ------------------------------ | ------------------ |
| IterableIterator&lt;string&gt; | All attribute names in AppStorage.|


```ts
AppStorage.SetOrCreate('PropB', 48);
let keys: IterableIterator<string> = AppStorage.Keys();
```


### staticClear

static staticClear(): boolean

Deletes all attributes.

This API is deprecated since API version 9. You are advised to use [Clear9+](#clear9) instead.

**Return value**

| Type     | Description                               |
| ------- | --------------------------------- |
| boolean | Returns **true** if all attributes are deleted; returns **false** if any of the attributes is being referenced by a state variable.|


```ts
let simple = AppStorage.staticClear();
```


### Clear<sup>9+</sup>

static Clear(): boolean

Deletes all attributes from AppStorage under the prerequisite that none of the attributes has a subscriber. If any of the attributes has a subscriber, **false** is returned. If the deletion is successful, **true** is returned.

For details about the subscriber, see [Delete](#delete).

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|


```typescript
AppStorage.SetOrCreate('PropA', 47);
let res: boolean = AppStorage.Clear(); // true, there are no subscribers
```


### IsMutable

static IsMutable(propName: string): boolean

Checks whether the given attribute in AppStorage name is mutable.

**Parameters**

| Name     | Type    | Mandatory  | Description            |
| -------- | ------ | ---- | ---------------- |
| propName | string | Yes   | Attribute name in AppStorage.|

**Return value**

| Type     | Description                              |
| ------- | -------------------------------- |
| boolean | Whether the given attribute in AppStorage name is mutable.|


```ts
AppStorage.SetOrCreate('PropA', 47);
let res: boolean = AppStorage.IsMutable('simpleProp');
```


### Size

static Size(): number

Obtains the number of attributes in AppStorage.

**Return value**

| Type    | Description                 |
| ------ | ------------------- |
| number | Number of attributes in AppStorage.|


```ts
AppStorage.SetOrCreate('PropB', 48);
let res: number = AppStorage.Size(); // 1
```


## LocalStorage<sup>9+</sup>


### constructor<sup>9+</sup>

constructor(initializingProperties?: Object)

Creates a **LocalStorage** instance and initializes it using the attributes and values returned by **Object.keys(initializingProperties)**.

Since API version 9, this API is supported in ArkTS widgets.

**Parameters**

| Name                   | Type    | Mandatory  | Description                                    |
| ---------------------- | ------ | ---- | ---------------------------------------- |
| initializingProperties | Object | No   | Attributes and values used to initialize the **LocalStorage** instance. The value cannot be **undefined**.|


```ts
let storage: LocalStorage = new LocalStorage({ 'PropA': 47 });
```


### GetShared<sup>9+</sup>

static GetShared(): LocalStorage

Obtains the **LocalStorage** instance shared by the current stage.

Since API version 9, this API is supported in ArkTS widgets.

**Model restriction**: This API can be used only in the stage model.

**Return value**

| Type                            | Description               |
| ------------------------------ | ----------------- |
| [LocalStorage](#localstorage9) | **LocalStorage** instance.|


```ts
let storage: LocalStorage = LocalStorage.GetShared();
```


### has<sup>9+</sup>

has(propName: string): boolean

Checks whether the attribute with the specified attribute name exists in LocalStorage.

Since API version 9, this API is supported in ArkTS widgets.

**Parameters**

| Name     | Type    | Mandatory  | Description              |
| -------- | ------ | ---- | ------------------ |
| propName | string | Yes   | Attribute name in LocalStorage.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | Returns **true** if the target attribute exists in AppStorage; returns **false** otherwise.|


```
let storage: LocalStorage = new LocalStorage({ 'PropA': 47 });
storage.has('PropA'); // true
```


### get<sup>9+</sup>

get&lt;T&gt;(propName: string): T | undefined

Obtains the attribute with the specified attribute name in LocalStorage.

Since API version 9, this API is supported in ArkTS widgets.

**Parameters**

| Name     | Type    | Mandatory  | Description              |
| -------- | ------ | ---- | ------------------ |
| propName | string | Yes   | Attribute name in LocalStorage.|

**Return value**

| Type                      | Description                                      |
| ------------------------ | ---------------------------------------- |
| T&nbsp;\|&nbsp;undefined | Returns the attribute with the specified attribute name in LocalStorage; returns **undefined** if the attribute does not exist.|


```ts
let storage: LocalStorage = new LocalStorage({ 'PropA': 47 });
let value: number = storage.get('PropA'); // 47
```


### set<sup>9+</sup>

set&lt;T&gt;(propName: string, newValue: T): boolean

Sets the value for the attribute with the specified attribute name in LocalStorage.

Since API version 9, this API is supported in ArkTS widgets.

**Parameters**

| Name     | Type    | Mandatory  | Description                   |
| -------- | ------ | ---- | ----------------------- |
| propName | string | Yes   | Attribute name in LocalStorage.     |
| newValue | T      | Yes   | Attribute value, which cannot be **undefined** or **null**.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | Returns **true** if the operation is successful; return **false** if the attribute with the specified attribute name does not exist in LocalStorage, or the value to set is **undefined** or **null**.  |


```ts
let storage: LocalStorage = new LocalStorage({ 'PropA': 47 });
let res: boolean = storage.set('PropA', 47); // true
let res1: boolean = storage.set('PropB', 47); // false
```


### setOrCreate<sup>9+</sup>

setOrCreate&lt;T&gt;(propName: string, newValue: T): boolean

Sets a new value for the attribute with the specified attribute name in LocalStorage or, if the attribute does not exist, creates one with the specified attribute name and default value.

Since API version 9, this API is supported in ArkTS widgets.

**Parameters**

| Name     | Type    | Mandatory  | Description                   |
| -------- | ------ | ---- | ----------------------- |
| propName | string | Yes   | Attribute name in LocalStorage.     |
| newValue | T      | Yes   | Attribute value, which cannot be **undefined** or **null**.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | Returns **false** if **newValue** is set to **undefined** or **null**.<br>Updates the target attribute with the new value and returns **true** if the attribute exists in LocalStorage.<br>Creates an attribute with the specified attribute name and default value if the attribute does not exist in LocalStorage.|


```ts
let storage: LocalStorage = new LocalStorage({ 'PropA': 47 });
let res: boolean =storage.setOrCreate('PropA', 121); // true
let res1: boolean =storage.setOrCreate('PropB', 111); // true
let res2: boolean =storage.setOrCreate('PropB', undefined); // false
```


### link<sup>9+</sup>

link&lt;T&gt;(propName: string): SubscribedAbstractProperty&lt;T&gt;

Establishes two-way data binding with the given attribute in this **LocalStorage** instance. If the given attribute exists, the two-way bound data of the attribute in LocalStorage is returned.

Any update of the data is synchronized back to LocalStorage, which then synchronizes the update to all data and custom components bound to the attribute.

If the given attribute does not exist in LocalStorage, **undefined** is returned.

Since API version 9, this API is supported in ArkTS widgets.

**Parameters**

| Name     | Type    | Mandatory  | Description              |
| -------- | ------ | ---- | ------------------ |
| propName | string | Yes   | Attribute name in LocalStorage.|

**Return value**

| Type                                 | Description                                      |
| ----------------------------------- | ---------------------------------------- |
| SubscribedAbstractProperty&lt;T&gt; | Returns the **SubscribedAbstractProperty<T>** instance if the given attribute exists in AppStorage; returns **undefined** otherwise.|


```ts
let storage: LocalStorage = new LocalStorage({ 'PropA': 47 });
let linkToPropA1: SubscribedAbstractProperty<number> = storage.link('PropA');
let linkToPropA2: SubscribedAbstractProperty<number> = storage.link('PropA'); // linkToPropA2.get() == 47
linkToPropA1.set(48); // Two-way synchronization: linkToPropA1.get() == linkToPropA2.get() == 48
```


### setAndLink<sup>9+</sup>

setAndLink&lt;T&gt;(propName: string, defaultValue: T): SubscribedAbstractProperty&lt;T&gt;

Works in a way similar to the **Link** API. If the given attribute exists in LocalStorage, the two-way bound data of the attribute in LocalStorage is returned. If the given attribute does not exist, it is created and initialized with **defaultValue** in LocalStorage, and two-way bound data is returned.

Since API version 9, this API is supported in ArkTS widgets.

**Parameters**

| Name         | Type    | Mandatory  | Description                                    |
| ------------ | ------ | ---- | ---------------------------------------- |
| propName     | string | Yes   | Attribute name in LocalStorage.                      |
| defaultValue | T      | Yes   | Default value used to initialize the attribute with the specified attribute name in LocalStorage.|

**Return value**

| Type                                 | Description                                      |
| ----------------------------------- | ---------------------------------------- |
| SubscribedAbstractProperty&lt;T&gt; | Returns the **SubscribedAbstractProperty&lt;T&gt;** instance if the given attribute exists in LocalStorage; returns **undefined** otherwise.|


```ts
let storage: LocalStorage = new LocalStorage({ 'PropA': 47 });
let link1: SubscribedAbstractProperty<number> = storage.setAndLink('PropB', 49); // Create PropB 49
var link2: SubscribedAbstractProperty<number> = storage.setAndLink('PropA', 50); // PropA exists, remains 47
```


### prop<sup>9+</sup>

prop&lt;S&gt;(propName: string): SubscribedAbstractProperty&lt;S&gt;

Establishes one-way data binding with the given attribute in this **LocalStorage** instance. If the given attribute exists, the one-way bound data of the attribute in LocalStorage is returned. If the given attribute does not exist in LocalStorage, **undefined** is returned. Updates of the one-way bound data are not synchronized back to LocalStorage.

Since API version 9, this API is supported in ArkTS widgets.

**Parameters**

| Name     | Type    | Mandatory  | Description              |
| -------- | ------ | ---- | ------------------ |
| propName | string | Yes   | Attribute name in LocalStorage.|

**Return value**

| Type                                 | Description                                      |
| ----------------------------------- | ---------------------------------------- |
| SubscribedAbstractProperty&lt;S&gt; | Returns the **SubscribedAbstractProperty&lt;S&gt;** instance if the given attribute exists in LocalStorage; returns **undefined** otherwise.|


```ts
let storage: LocalStorage = new LocalStorage({ 'PropA': 47 });
let prop1: SubscribedAbstractProperty<number> = storage.prop('PropA');
let prop2: SubscribedAbstractProperty<number> = storage.prop('PropA');
prop1.set(1); // one-way sync: prop1.get()=1; but prop2.get() == 47
```


### setAndProp<sup>9+</sup>

setAndProp&lt;S&gt;(propName: string, defaultValue: S): SubscribedAbstractProperty&lt;S&gt;

Establishes one-way data binding with the given attribute in this **LocalStorage** instance. If the given attribute exists, the one-way bound data of the attribute in LocalStorage is returned. If the given attribute does not exist, it is created and initialized with **defaultValue** in LocalStorage, and one-way bound data is returned.

Since API version 9, this API is supported in ArkTS widgets.

**Parameters**

| Name         | Type    | Mandatory  | Description                                    |
| ------------ | ------ | ---- | ---------------------------------------- |
| propName     | string | Yes   | Attribute name in LocalStorage.                      |
| defaultValue | S      | Yes   | Default value used to initialize the attribute with the specified attribute name in LocalStorage.|

**Return value**

| Type                                 | Description                                      |
| ----------------------------------- | ---------------------------------------- |
| SubscribedAbstractProperty&lt;S&gt; | Instance of **SubscribedAbstractProperty&lt;T&gt;** and one-way bound data of the given attribute in LocalStorage.|


```ts
let storage: LocalStorage = new LocalStorage({ 'PropA': 47 });
let prop: SubscribedAbstractProperty<number> = storage.setAndProp('PropB', 49); // PropA -> 47, PropB -> 49
```


### delete<sup>9+</sup>

delete(propName: string): boolean

Deletes the attribute with the specified attribute name from LocalStorage under the prerequisite that the attribute does not have a subscriber. If the deletion is successful, **true** is returned.

The subscribers of the attribute are attributes with the same name bound to the **Link** and **Prop** APIs, **\@LocalStorageLink('propName')**, and **\@LocalStorageProp('propName')**. This means that if **\@LocalStorageLink('propName')** and **\@LocalStorageProp('propName')** are used in a custom component or if there is still a **SubscribedAbstractProperty** instance (return type of the **link** and **prop** APIs) in sync with the attribute, the attribute cannot be deleted from LocalStorage.

Since API version 9, this API is supported in ArkTS widgets.

**Parameters**

| Name     | Type    | Mandatory  | Description              |
| -------- | ------ | ---- | ------------------ |
| propName | string | Yes   | Attribute name in LocalStorage.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|


```ts
let storage: LocalStorage = new LocalStorage({ 'PropA': 47 });
storage.link('PropA');
let res: boolean = storage.delete('PropA'); // false, PropA still has a subscriber
let res1: boolean = storage.delete('PropB'); // false, PropB is not in storage
storage.setOrCreate('PropB', 48);
let res2: boolean = storage.delete('PropB'); // true, PropB is deleted from storage successfully
```


### keys<sup>9+</sup>

keys(): IterableIterator&lt;string&gt;

Obtains all attribute names in LocalStorage.

Since API version 9, this API is supported in ArkTS widgets.

**Return value**

| Type                            | Description                  |
| ------------------------------ | -------------------- |
| IterableIterator&lt;string&gt; | All attribute names in LocalStorage.|


```ts
let storage: LocalStorage = new LocalStorage({ 'PropA': 47 });
let keys: IterableIterator<string> = storage.keys();
```


### size<sup>9+</sup>

size(): number

Obtains the number of attributes in LocalStorage.

Since API version 9, this API is supported in ArkTS widgets.

**Return value**

| Type    | Description       |
| ------ | --------- |
| number | Number of attributes in LocalStorage.|


```ts
let storage: LocalStorage = new LocalStorage({ 'PropA': 47 });
let res: number = storage.size(); // 1
```


### clear<sup>9+</sup>

clear(): boolean


Deletes all attributes from LocalStorage under the prerequisite that none of the attributes has a subscriber. If any of the attributes has a subscriber, **false** is returned. If the deletion is successful, **true** is returned.

Since API version 9, this API is supported in ArkTS widgets.

**Return value**


| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|



```ts
let storage: LocalStorage = new LocalStorage({ 'PropA': 47 });
let res: boolean = storage.clear(); // true, there are no subscribers
```


## SubscribedAbstractProperty


### get<sup>9+</sup>

abstract get(): T

Obtains attribute data synchronized from AppStorage or LocalStorage.

Since API version 9, this API is supported in ArkTS widgets.

**Return value**

| Type  | Description                             |
| ---- | ------------------------------- |
| T    | Attribute data synchronized from AppStorage or LocalStorage.|


```ts
AppStorage.SetOrCreate('PropA', 47); 
let prop1 = AppStorage.Prop('PropA');    
prop1.get(); //  prop1.get()=47
```


### set<sup>9+</sup>

abstract set(newValue: T): void

Sets the attribute data synchronized from AppStorage or LocalStorage.

Since API version 9, this API is supported in ArkTS widgets.


**Parameters**


| Name     | Type  | Mandatory  | Description   |
| -------- | ---- | ---- | ------- |
| newValue | T    | Yes   | Data to set.|



```
AppStorage.SetOrCreate('PropA', 47);
let prop1 = AppStorage.Prop('PropA');
prop1.set(1); //  prop1.get()=1
```

## PersistentStorage


### PersistProp

static PersistProp&lt;T&gt;(key: string, defaultValue: T): void

Persists the attribute with the specified key in AppStorage to a file. This API is usually called before access to AppStorage.

The sequence of determining the type and value of an attribute is as follows:

1. If the PersistentStorage file contains the attribute with the specified key, an attribute with the key as the name is created in AppStorage and initialized with the attribute of the key found in PersistentStorage.

2. If the attribute with the specified key is not found in the PersistentStorage file, AppStorage is searched for the attribute corresponding to the key. If the matching attribute is found, it is persisted.

3. If no matching attribute is found in AppStorage, it is created in AppStorage, initialized with the value of **defaultValue**, and persisted.

According to the preceding initialization process, if AppStorage contains the matching attribute, the value of this attribute is used to overwrite the value in the PersistentStorage file. Because AppStorage stores data in the memory, the attribute value becomes impersistent.

**Parameters**

| Name         | Type    | Mandatory  | Description                                    |
| ------------ | ------ | ---- | ---------------------------------------- |
| key          | string | Yes   | Attribute name.                                    |
| defaultValue | T      | Yes   | Default value used to initialize the created attribute. The value cannot be **undefined** or **null**.|


**Example:**



```ts
PersistentStorage.PersistProp('highScore', '0');
```


### DeleteProp

static DeleteProp(key: string): void

Performs the reverse operation of **PersistProp**. Specifically, this API deletes the attribute corresponding to the key from PersistentStorage. Subsequent AppStorage operations do not affect data in PersistentStorage.

**Parameters**

| Name | Type    | Mandatory  | Description                   |
| ---- | ------ | ---- | ----------------------- |
| key  | string | Yes   | Attribute name in PersistentStorage.|


```ts
PersistentStorage.DeleteProp('highScore');
```


### PersistProps

static PersistProps(properties: {key: string, defaultValue: any;}[]): void

Works in a way similar to the **PersistProp** API, with the difference that it allows for persistence in batches and is therefore ideal for initialization during application startup.

**Parameters**

| Name       | Type                                      | Mandatory  | Description                                    |
| ---------- | ---------------------------------------- | ---- | ---------------------------------------- |
| properties | {key:&nbsp;string,&nbsp;defaultValue:&nbsp;any}[] | Yes   | Array of attributes to persist.<br>**key**: attribute name.<br>**defaultValue**: default value. The rules are the same as those of **PersistProp**.|


```ts
PersistentStorage.PersistProps([{ key: 'highScore', defaultValue: '0' }, { key: 'wightScore', defaultValue: '1' }]);
```


### Keys

static Keys(): Array&lt;string&gt;

Obtains an array of keys for all persistent attributes.

**Return value**

| Type                 | Description               |
| ------------------- | ----------------- |
| Array&lt;string&gt; | Array of keys of all persistent attributes.|


```ts
let keys: Array<string> = PersistentStorage.Keys();
```


## Environment


### EnvProp

static EnvProp&lt;S&gt;(key: string, value: S): boolean

Saves the built-in environment variable key in environment to AppStorage. If the value of the environment variable key is not found in AppStorage, the default value is used. If the value is successfully saved, **true** is returned. If the value of the environment variable key is found in AppStorage, **false** is returned.

You are advised to call this API when the application is started.

It is incorrect to use AppStorage to read environment variables without invoking **EnvProp**.

**Parameters**

| Name  | Type    | Mandatory  | Description                                   |
| ----- | ------ | ---- | --------------------------------------- |
| key   | string | Yes   | Environment variable name. For details about the value range, see [Built-in Environment Variables](#built-in-environment-variables).   |
| value | S      | Yes   | Default value used if the value of the environment variable key is not found in AppStorage.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | Returns **false** if the attribute corresponding to the key exists in AppStorage; returns **false** otherwise.|

**Example:**


```ts
Environment.EnvProp('accessibilityEnabled', 'default');
```


### Built-in Environment Variables

| key                  | Type             | Description                                      |
| -------------------- | --------------- | ---------------------------------------- |
| accessibilityEnabled | string          | Whether to enable accessibility.                            |
| colorMode            | ColorMode       | Color mode. The options are as follows:<br>- **ColorMode.LIGHT**: light mode.<br>- **ColorMode.DARK**: dark mode.|
| fontScale            | number          | Font scale.                                 |
| fontWeightScale      | number          | Font weight scale.                                   |
| layoutDirection      | LayoutDirection | Layout direction. The options are as follows:<br>- **LayoutDirection.LTR**: from left to right.<br>- **LayoutDirection.RTL**: from right to left.|
| languageCode         | string          | Current system language. The value is in lowercase, for example, **zh**.                       |


### EnvProps

static EnvProps(props: {key: string; defaultValue: any;}[]): void

Works in a way similar to the **EnvProp** API, with the difference that it allows for initialization of multiple attributes in batches. You are advised to call this API during application startup to save system environment variables to AppStorage in batches.

**Parameters**

| Name  | Type                                      | Mandatory  | Description              |
| ----- | ---------------------------------------- | ---- | ------------------ |
| props | {key:&nbsp;string,&nbsp;defaultValue:&nbsp;any}[] | Yes   | Array of key-value pairs consisting of system environment variables and default values.|


```ts
Environment.EnvProps([{ key: 'accessibilityEnabled', defaultValue: 'default' }, {
  key: 'languageCode',
  defaultValue: 'en'
}, { key: 'prop', defaultValue: 'hhhh' }]);
```


### Keys

static Keys(): Array&lt;string&gt;

Array of keys of environment variables.

**Return value**

| Type                 | Description         |
| ------------------- | ----------- |
| Array&lt;string&gt; | Returns an array of associated system attributes.|


```ts
Environment.EnvProps([{ key: 'accessibilityEnabled', defaultValue: 'default' }, {
  key: 'languageCode',
  defaultValue: 'en'
}, { key: 'prop', defaultValue: 'hhhh' }]);

let keys: Array<string> = Environment.Keys(); // accessibilityEnabled, languageCode, prop
```
