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


For details about how to use AppStorage on the UI, see [AppStorage: Application-wide UI State Storage](../../../quick-start/arkts-appstorage.md).


### link<sup>10+</sup>

static link&lt;T&gt;(propName: string): SubscribedAbstractProperty&lt;T&gt;

Establishes two-way data binding with the given attribute (specified by **propName**) in AppStorage. If the given attribute exists in AppStorage, the two-way bound data of the attribute in AppStorage is returned.

Any update of the data is synchronized back to AppStorage, which then synchronizes the update to all data and custom components bound to the attribute.

If the given attribute does not exist in AppStorage, **undefined** is returned.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description            |
| -------- | ------ | ---- | ---------------- |
| propName | string | Yes   | Attribute name in AppStorage.|

**Return value**

| Type                               | Description                                                        |
| ----------------------------------- | ------------------------------------------------------------ |
| SubscribedAbstractProperty&lt;T&gt; | Returns two-way bound data if specified attribute exists in AppStorage; returns **undefined** otherwise.|

**Example**
```ts
AppStorage.setOrCreate('PropA', 47);
let linkToPropA1: SubscribedAbstractProperty<number> = AppStorage.link('PropA');
let linkToPropA2: SubscribedAbstractProperty<number> = AppStorage.link('PropA'); // linkToPropA2.get() == 47
linkToPropA1.set(48); // Two-way synchronization: linkToPropA1.get() == linkToPropA2.get() == 48
```


### setAndLink<sup>10+</sup>

static setAndLink&lt;T&gt;(propName: string, defaultValue: T): SubscribedAbstractProperty&lt;T&gt;

Works in a way similar to the **link** API. If the given attribute exists in AppStorage, the two-way bound data of the attribute in AppStorage is returned. If the given attribute does not exist, it is created and initialized with **defaultValue** in AppStorage, and two-way bound data is returned. The value of **defaultValue** must be of the T type and cannot be **undefined** or **null**.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name      | Type  | Mandatory| Description                                                    |
| ------------ | ------ | ---- | ------------------------------------------------------------ |
| propName     | string | Yes  | Attribute name in AppStorage.                                      |
| defaultValue | T      | Yes  | Default value used to initialize the attribute with the specified attribute name in AppStorage. The value cannot be **undefined** or **null**.|

**Return value**

| Type                                 | Description                                      |
| ----------------------------------- | ---------------------------------------- |
| SubscribedAbstractProperty&lt;T&gt; | Instance of **SubscribedAbstractProperty&lt;T&gt;** and two-way bound data of the given attribute in AppStorage.|

**Example**
```ts
AppStorage.setOrCreate('PropA', 47);
let link1: SubscribedAbstractProperty<number> = AppStorage.setAndLink('PropB', 49); // Create PropB 49
let link2: SubscribedAbstractProperty<number> = AppStorage.setAndLink('PropA', 50); // PropA exists, remains 47
```


### prop<sup>10+</sup>

static prop&lt;T&gt;(propName: string): SubscribedAbstractProperty&lt;T&gt;

Establishes one-way data binding with the given attribute (specified by **propName**) in AppStorage. If the given attribute exists in AppStorage, the one-way bound data of the attribute in AppStorage is returned. If the given attribute does not exist in AppStorage, **undefined** is returned. Updates of the one-way bound data are not synchronized back to AppStorage.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description            |
| -------- | ------ | ---- | ---------------- |
| propName | string | Yes   | Attribute name in AppStorage.|

**Return value**

| Type                               | Description                                                        |
| ----------------------------------- | ------------------------------------------------------------ |
| SubscribedAbstractProperty&lt;T&gt; | Returns one-way bound data if specified attribute exists in AppStorage; returns **undefined** otherwise.|

**Example**

```ts
AppStorage.setOrCreate('PropA', 47);
let prop1: SubscribedAbstractProperty<number> = AppStorage.prop('PropA');
let prop2: SubscribedAbstractProperty<number> = AppStorage.prop('PropA');
prop1.set(1); // one-way sync: prop1.get()=1; but prop2.get() == 47
```


### setAndProp<sup>10+</sup>

static setAndProp&lt;T&gt;(propName: string, defaultValue: T): SubscribedAbstractProperty&lt;T&gt;

Works in a way similar to the **prop** API. If the given attribute exists in AppStorage, the one-way bound data of the attribute in AppStorage is returned. If the given attribute does not exist, it is created and initialized with **defaultValue** in AppStorage, and one-way bound data is returned. The value of **defaultValue** must be of the T type and cannot be **undefined** or **null**.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name      | Type  | Mandatory| Description                                                    |
| ------------ | ------ | ---- | ------------------------------------------------------------ |
| propName     | string | Yes  | Attribute name in AppStorage.                                      |
| defaultValue | T      | Yes  | Default value used to initialize the attribute with the specified attribute name in AppStorage. The value cannot be **undefined** or **null**.|

**Return value**

| Type                                 | Description                                     |
| ----------------------------------- | --------------------------------------- |
| SubscribedAbstractProperty&lt;T&gt; | Instance of **SubscribedAbstractProperty&lt;T&gt;**.|

**Example**
```ts
AppStorage.setOrCreate('PropA', 47);
let prop: SubscribedAbstractProperty<number> = AppStorage.setAndProp('PropB', 49); // PropA -> 47, PropB -> 49
```


### has<sup>10+</sup>

static has(propName: string): boolean

Checks whether the attribute with the specified attribute name exists in AppStorage.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description            |
| -------- | ------ | ---- | ---------------- |
| propName | string | Yes   | Attribute name in AppStorage.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | Returns **true** if the attribute with the specified attribute name exists in AppStorage; returns **false** otherwise.|

**Example**
```ts
AppStorage.has('simpleProp');
```


### get<sup>10+</sup>

static get&lt;T&gt;(propName: string): T | undefined

Obtains the attribute with the specified attribute name in AppStorage. If the attribute does not exist, **undefined** is returned.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description            |
| -------- | ------ | ---- | ---------------- |
| propName | string | Yes   | Attribute name in AppStorage.|

**Return value**

| Type                    | Description                                                       |
| ------------------------ | ----------------------------------------------------------- |
| T \| undefined | Returns the attribute with the specified attribute name in AppStorage; returns **undefined** if the attribute does not exist.|

**Example**
```ts
AppStorage.setOrCreate('PropA', 47);
let value: number = AppStorage.get('PropA') as number; // 47
```


### set<sup>10+</sup>

static set&lt;T&gt;(propName: string, newValue: T): boolean

Sets the value for the attribute with the specified attribute name in AppStorage. If the value of **newValue** is the same as the value of the attribute with the specified attribute name, that is, no value needs to be assigned, the state variable will not instruct the UI to update the value of attribute.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description                  |
| -------- | ------ | ---- | ---------------------- |
| propName | string | Yes   | Attribute name in AppStorage.      |
| newValue | T      | Yes   | Attribute value, which cannot be **undefined** or **null**.|

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **true** if the operation is successful; return **false** if the attribute with the specified attribute name does not exist in AppStorage, or the value to set is **undefined** or **null**.  |

**Example**
```ts
AppStorage.setOrCreate('PropA', 48);
let res: boolean = AppStorage.set('PropA', 47) // true
let res1: boolean = AppStorage.set('PropB', 47) // false
```


### setOrCreate<sup>10+</sup>

static setOrCreate&lt;T&gt;(propName: string, newValue: T): void

Sets a new value for the attribute with the specified attribute name in AppStorage or, if the attribute does not exist, creates one with the specified attribute name and the set value.
If the new value is the same as the existing value of the attribute with the specified attribute name, the state variable will not instruct the UI to update the value of the attribute. This **setOrCreate** method creates only one AppStorage key-value pair. To create multiple key-value pairs, call this method multiple times.

The value of **newValue** cannot be **undefined** or **null**.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description                  |
| -------- | ------ | ---- | ---------------------- |
| propName | string | Yes   | Attribute name in AppStorage.      |
| newValue | T      | Yes   | Attribute value, which cannot be **undefined** or **null**.|

**Example**
```ts
AppStorage.setOrCreate('simpleProp', 121);
```


### delete<sup>10+</sup>

static delete(propName: string): boolean

Deletes the attribute with the specified attribute name from AppStorage under the prerequisite that the attribute does not have a subscriber. If there is a subscriber, **false** is returned. If the deletion is successful, **true** is returned.

The subscribers of the attribute are attributes with the same name bound to APIs such as **link** and **prop**, **\@StorageLink('propName')**, and **\@StorageProp('propName')**. This means that if @StorageLink('propName') and @StorageProp('propName') are used in a custom component or if there is still a **SubscribedAbstractProperty** instance in sync with the attribute, the attribute cannot be deleted from AppStorage.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description            |
| -------- | ------ | ---- | ---------------- |
| propName | string | Yes   | Attribute name in AppStorage.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**
```ts
AppStorage.setOrCreate('PropA', 47);
AppStorage.link<number>('PropA');
let res: boolean = AppStorage.delete('PropA'); // false, PropA still has a subscriber

AppStorage.setOrCreate('PropB', 48);
let res1: boolean = AppStorage.delete('PropB'); // true, PropB is deleted from AppStorage successfully
```


### keys<sup>10+</sup>

static keys(): IterableIterator&lt;string&gt;

Obtains all attribute names in AppStorage.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                            | Description                |
| ------------------------------ | ------------------ |
| IterableIterator&lt;string&gt; | All attribute names in AppStorage.|

**Example**
```ts
AppStorage.setOrCreate('PropB', 48);
let keys: IterableIterator<string> = AppStorage.keys();
```


### clear<sup>10+</sup>

static clear(): boolean

Deletes all attributes from AppStorage under the prerequisite that none of the attributes has a subscriber. If any of the attributes has a subscriber, this API does not take effect and **false** is returned. If the deletion is successful, **true** is returned.

For details about the subscriber, see [delete](#delete10).

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**
```ts
AppStorage.setOrCreate('PropA', 47);
let res: boolean = AppStorage.clear(); // true, there are no subscribers
```


### size<sup>10+</sup>

static size(): number

Obtains the number of attributes in AppStorage.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description                 |
| ------ | ------------------- |
| number | Number of attributes in AppStorage.|

**Example**
```ts
AppStorage.setOrCreate('PropB', 48);
let res: number = AppStorage.size(); // 1
```


### Link<sup>(deprecated)</sup>

static Link(propName: string): any

Establishes two-way data binding with the given attribute (specified by **propName**) in AppStorage. If the given attribute exists in AppStorage, the two-way bound data of the attribute in AppStorage is returned.

Any update of the data is synchronized back to AppStorage, which then synchronizes the update to all data and custom components bound to the attribute.

If the given attribute does not exist in AppStorage, **undefined** is returned.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 10. You are advised to use [link10+](#link10) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description            |
| -------- | ------ | ---- | ---------------- |
| propName | string | Yes   | Attribute name in AppStorage.|

**Return value**

| Type                            | Description                                                        |
| -------------------------------- | ------------------------------------------------------------ |
| any | Returns two-way bound data if specified attribute exists in AppStorage; returns **undefined** otherwise.|

**Example**
```ts
AppStorage.SetOrCreate('PropA', 47);
let linkToPropA1: SubscribedAbstractProperty<number> = AppStorage.Link('PropA');
let linkToPropA2: SubscribedAbstractProperty<number> = AppStorage.Link('PropA'); // linkToPropA2.get() == 47
linkToPropA1.set(48); // Two-way synchronization: linkToPropA1.get() == linkToPropA2.get() == 48
```

### SetAndLink<sup>(deprecated)</sup>

static SetAndLink&lt;T&gt;(propName: string, defaultValue: T): SubscribedAbstractProperty&lt;T&gt;

Works in a way similar to the **Link** API. If the given attribute exists in AppStorage, the two-way bound data of the attribute in AppStorage is returned. If the given attribute does not exist, it is created and initialized with **defaultValue** in AppStorage, and two-way bound data is returned. The value of **defaultValue** must be of the T type and cannot be **undefined** or **null**.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 10. You are advised to use [setAndLink10+](#setandlink10) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name      | Type  | Mandatory| Description                                                    |
| ------------ | ------ | ---- | ------------------------------------------------------------ |
| propName     | string | Yes  | Attribute name in AppStorage.                                      |
| defaultValue | T      | Yes  | Default value used to initialize the attribute with the specified attribute name in AppStorage. The value cannot be **undefined** or **null**.|

**Return value**

| Type                                 | Description                                      |
| ----------------------------------- | ---------------------------------------- |
| SubscribedAbstractProperty&lt;T&gt; | Instance of **SubscribedAbstractProperty&lt;T&gt;** and two-way bound data of the given attribute in AppStorage.|

**Example**
```ts
AppStorage.SetOrCreate('PropA', 47);
let link1: SubscribedAbstractProperty<number> = AppStorage.SetAndLink('PropB', 49); // Create PropB 49
let link2: SubscribedAbstractProperty<number> = AppStorage.SetAndLink('PropA', 50); // PropA exists, remains 47
```


### Prop<sup>(deprecated)</sup>

static Prop(propName: string): any

Establishes one-way data binding with the given attribute (specified by **propName**) in AppStorage. If the given attribute exists in AppStorage, the one-way bound data of the attribute in AppStorage is returned. If the given attribute does not exist in AppStorage, **undefined** is returned. Updates of the one-way bound data are not synchronized back to AppStorage.

> **NOTE**
>
> Prop supports only simple types.
>
> This API is supported since API version 7 and deprecated since API version 10. You are advised to use [prop10+](#prop10) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description            |
| -------- | ------ | ---- | ---------------- |
| propName | string | Yes   | Attribute name in AppStorage.|

**Return value**

| Type                            | Description                                                        |
| -------------------------------- | ------------------------------------------------------------ |
| any | Returns one-way bound data if specified attribute exists in AppStorage; returns **undefined** otherwise.|

**Example**
```ts
AppStorage.SetOrCreate('PropA', 47);
let prop1: SubscribedAbstractProperty<number> = AppStorage.Prop('PropA');
let prop2: SubscribedAbstractProperty<number> = AppStorage.Prop('PropA');
prop1.set(1); // one-way sync: prop1.get()=1; but prop2.get() == 47
```

### SetAndProp<sup>(deprecated)</sup>

static SetAndProp&lt;S&gt;(propName: string, defaultValue: S): SubscribedAbstractProperty&lt;S&gt;

Works in a way similar to the **Prop** API. If the given attribute exists in AppStorage, the one-way bound data of the attribute in AppStorage is returned. If the given attribute does not exist, it is created and initialized with **defaultValue** in AppStorage, and one-way bound data is returned. The value of **defaultValue** must be of the S type and cannot be **undefined** or **null**.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 10. You are advised to use [setAndProp10+](#setandprop10) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name      | Type  | Mandatory| Description                                                    |
| ------------ | ------ | ---- | ------------------------------------------------------------ |
| propName     | string | Yes  | Attribute name in AppStorage.                                      |
| defaultValue | S      | Yes  | Default value used to initialize the attribute with the specified attribute name in AppStorage. The value cannot be **undefined** or **null**.|

**Return value**

| Type                                 | Description                                     |
| ----------------------------------- | --------------------------------------- |
| SubscribedAbstractProperty&lt;S&gt; | Instance of **SubscribedAbstractProperty&lt;S&gt;**.|

**Example**
```ts
AppStorage.SetOrCreate('PropA', 47);
let prop: SubscribedAbstractProperty<number> = AppStorage.SetAndProp('PropB', 49); // PropA -> 47, PropB -> 49
```

### Has<sup>(deprecated)</sup>

static Has(propName: string): boolean

Checks whether the attribute with the specified attribute name exists in AppStorage.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 10. You are advised to use [has10+](#has10) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description            |
| -------- | ------ | ---- | ---------------- |
| propName | string | Yes   | Attribute name in AppStorage.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | Returns **true** if the attribute with the specified attribute name exists in AppStorage; returns **false** otherwise.|

**Example**
```ts
AppStorage.Has('simpleProp');
```

### Get<sup>(deprecated)</sup>

static Get&lt;T&gt;(propName: string): T | undefined

Obtains the attribute with the specified attribute name in AppStorage. If the attribute does not exist, **undefined** is returned.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 10. You are advised to use [get10+](#get10) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description            |
| -------- | ------ | ---- | ---------------- |
| propName | string | Yes   | Attribute name in AppStorage.|

**Return value**

| Type                    | Description                                                        |
| ------------------------ | ------------------------------------------------------------ |
| T \| undefined | Returns the attribute with the specified attribute name in AppStorage; returns **undefined** if the attribute does not exist.|

**Example**
```ts
AppStorage.SetOrCreate('PropA', 47);
let value: number = AppStorage.Get('PropA') as number; // 47
```

### Set<sup>(deprecated)</sup>

static Set&lt;T&gt;(propName: string, newValue: T): boolean

Sets the value for the attribute with the specified attribute name in AppStorage.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 10. You are advised to use [set10+](#set10) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description                  |
| -------- | ------ | ---- | ---------------------- |
| propName | string | Yes   | Attribute name in AppStorage.      |
| newValue | T      | Yes   | Attribute value, which cannot be **undefined** or **null**.|

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **true** if the operation is successful; return **false** if the attribute with the specified attribute name does not exist in AppStorage, or the value to set is **undefined** or **null**.  |

**Example**
```ts
AppStorage.SetOrCreate('PropA', 48);
let res: boolean = AppStorage.Set('PropA', 47) // true
let res1: boolean = AppStorage.Set('PropB', 47) // false
```

### SetOrCreate<sup>(deprecated)</sup>

static SetOrCreate&lt;T&gt;(propName: string, newValue: T): void

Sets a new value for the attribute with the specified attribute name in AppStorage or, if the attribute does not exist, creates one with the specified attribute name and default value.

The value of **newValue** cannot be **undefined** or **null**.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 10. You are advised to use [setOrCreate10+](#setorcreate10) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description                  |
| -------- | ------ | ---- | ---------------------- |
| propName | string | Yes   | Attribute name in AppStorage.      |
| newValue | T      | Yes   | Attribute value, which cannot be **undefined** or **null**.|

**Example**
```ts
AppStorage.SetOrCreate('simpleProp', 121);
```

### Delete<sup>(deprecated)</sup>

static Delete(propName: string): boolean

Deletes the attribute with the specified attribute name from AppStorage under the prerequisite that the attribute does not have a subscriber. If there is a subscriber, **false** is returned. If the deletion is successful, **true** is returned.

The subscribers of the attribute are attributes with the same name bound to APIs such as **Link** and **Prop**, **\@StorageLink('propName')**, and **\@StorageProp('propName')**. This means that if @StorageLink('propName') and @StorageProp('propName') are used in a custom component or if there is still a **SubscribedAbstractProperty** instance in sync with the attribute, the attribute cannot be deleted from AppStorage.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 10. You are advised to use [delete10+](#delete10) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description            |
| -------- | ------ | ---- | ---------------- |
| propName | string | Yes   | Attribute name in AppStorage.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**
```ts
AppStorage.SetOrCreate('PropA', 47);
AppStorage.Link('PropA');
let res: boolean = AppStorage.Delete('PropA'); // false, PropA still has a subscriber

AppStorage.SetOrCreate('PropB', 48);
let res1: boolean = AppStorage.Delete('PropB'); // true, PropB is deleted from AppStorage successfully
```

### Keys<sup>(deprecated)</sup>

static Keys(): IterableIterator&lt;string&gt;

Obtains all attribute names in AppStorage.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 10. You are advised to use [keys10+](#keys10) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                            | Description                |
| ------------------------------ | ------------------ |
| IterableIterator&lt;string&gt; | All attribute names in AppStorage.|

**Example**
```ts
AppStorage.SetOrCreate('PropB', 48);
let keys: IterableIterator<string> = AppStorage.Keys();
```


### staticClear<sup>(deprecated)</sup>

static staticClear(): boolean

Deletes all attributes.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [clear10+](#clear10) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type     | Description                               |
| ------- | --------------------------------- |
| boolean | Returns **true** if all attributes are deleted; returns **false** if any of the attributes is being referenced by a state variable.|

**Example**
```ts
let simple = AppStorage.staticClear();
```


### Clear<sup>(deprecated)</sup>

static Clear(): boolean

Deletes all attributes from AppStorage under the prerequisite that none of the attributes has a subscriber. If any of the attributes has a subscriber, this API does not take effect and **false** is returned. If the deletion is successful, **true** is returned.

For details about the subscriber, see [delete](#delete10).

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 10. You are advised to use [clear10+](#clear10) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**
```typescript
AppStorage.SetOrCreate('PropA', 47);
let res: boolean = AppStorage.Clear(); // true, there are no subscribers
```


### IsMutable<sup>(deprecated)</sup>

static IsMutable(propName: string): boolean

Checks whether the given attribute in AppStorage name is mutable.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 10.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description            |
| -------- | ------ | ---- | ---------------- |
| propName | string | Yes   | Attribute name in AppStorage.|

**Return value**

| Type     | Description                              |
| ------- | -------------------------------- |
| boolean | Whether the given attribute in AppStorage name is mutable.|

**Example**
```ts
AppStorage.SetOrCreate('PropA', 47);
let res: boolean = AppStorage.IsMutable('simpleProp');
```


### Size<sup>(deprecated)</sup>

static Size(): number

Obtains the number of attributes in AppStorage.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 10. You are advised to use [size10+](#size10) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description                 |
| ------ | ------------------- |
| number | Number of attributes in AppStorage.|

**Example**
```ts
AppStorage.SetOrCreate('PropB', 48);
let res: number = AppStorage.Size(); // 1
```


## LocalStorage<sup>9+</sup>


For details about how to use LocalStorage on the UI, see [LocalStorage: UI State Storage](../../../quick-start/arkts-localstorage.md).


### constructor<sup>9+</sup>

constructor(initializingProperties?: Object)

Creates a **LocalStorage** instance and initializes it using the attributes and values returned by **Object.keys(initializingProperties)**.

> **NOTE**
>
> This API can be used in ArkTS widgets since API version 9.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name                   | Type    | Mandatory  | Description                                    |
| ---------------------- | ------ | ---- | ---------------------------------------- |
| initializingProperties | Object | No   | Attributes and values used to initialize the **LocalStorage** instance. The value cannot be **undefined**.|

**Example**
```ts
let para: Record<string, number> = { 'PropA': 47 };
let storage: LocalStorage = new LocalStorage(para);
```


### getShared<sup>10+</sup>

static getShared(): LocalStorage

Obtains the **LocalStorage** instance shared by the current stage.

> **NOTE**
>
> This API can be used in ArkTS widgets since API version 9.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Model restriction**: This API can be used only in the stage model.

**Return value**

| Type                            | Description               |
| ------------------------------ | ----------------- |
| [LocalStorage](#localstorage9) | **LocalStorage** instance.|

**Example**
For details about how to use **getShared**, see [Sharing a LocalStorage Instance from UIAbility to One or More Pages](../../../quick-start/arkts-localstorage.md#example-of-sharing-a-localstorage-instance-from-uiability-to-one-or-more-pages).


### has<sup>9+</sup>

has(propName: string): boolean

Checks whether the attribute with the specified attribute name exists in LocalStorage.

> **NOTE**
>
> This API can be used in ArkTS widgets since API version 9.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description              |
| -------- | ------ | ---- | ------------------ |
| propName | string | Yes   | Attribute name in LocalStorage.|

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **true** if the attribute with the specified attribute name exists in LocalStorage; returns **false** otherwise.|

**Example**
```ts
let para: Record<string, number> = { 'PropA': 47 };
let storage: LocalStorage = new LocalStorage(para);
storage.has('PropA'); // true
```


### get<sup>9+</sup>

get&lt;T&gt;(propName: string): T | undefined

Obtains the attribute with the specified attribute name in LocalStorage.

> **NOTE**
>
> This API can be used in ArkTS widgets since API version 9.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description              |
| -------- | ------ | ---- | ------------------ |
| propName | string | Yes   | Attribute name in LocalStorage.|

**Return value**

| Type                    | Description                                                        |
| ------------------------ | ------------------------------------------------------------ |
| T \| undefined | Returns the attribute with the specified attribute name in LocalStorage; returns **undefined** if the attribute does not exist.|

**Example**
```ts
let para: Record<string, number> = { 'PropA': 47 };
let storage: LocalStorage = new LocalStorage(para);
let value: number = storage.get('PropA') as number; // 47
```


### set<sup>9+</sup>

set&lt;T&gt;(propName: string, newValue: T): boolean

Sets a value for the attribute with the specified attribute name in LocalStorage. If the value of **newValue** is the same as the value of the attribute with the specified attribute name, that is, no value needs to be assigned, the state variable will not instruct the UI to update the value of attribute.

> **NOTE**
>
> This API can be used in ArkTS widgets since API version 9.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description                   |
| -------- | ------ | ---- | ----------------------- |
| propName | string | Yes   | Attribute name in LocalStorage.     |
| newValue | T      | Yes   | Attribute value, which cannot be **undefined** or **null**.|

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **true** if the operation is successful; return **false** if the attribute with the specified attribute name does not exist in LocalStorage, or the value to set is **undefined** or **null**.  |

**Example**

```ts
let para: Record<string, number> = { 'PropA': 47 };
let storage: LocalStorage = new LocalStorage(para);
let res: boolean = storage.set('PropA', 47); // true
let res1: boolean = storage.set('PropB', 47); // false
```


### setOrCreate<sup>9+</sup>

setOrCreate&lt;T&gt;(propName: string, newValue: T): boolean

Sets a new value for the attribute with the specified attribute name in LocalStorage or, if the attribute does not exist, creates one with the specified attribute name and the set value.
If the new value is the same as the existing value of the attribute with the specified attribute name, the state variable will not instruct the UI to update the value of the attribute. This **setOrCreate** method creates only one LocalStorage key-value pair. To create multiple key-value pairs, call this method multiple times.

> **NOTE**
>
> This API can be used in ArkTS widgets since API version 9.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description                   |
| -------- | ------ | ---- | ----------------------- |
| propName | string | Yes   | Attribute name in LocalStorage.     |
| newValue | T      | Yes   | Attribute value, which cannot be **undefined** or **null**.|

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **false** if **newValue** is set to **undefined** or **null**.<br>Updates the target attribute with the new value and returns **true** if the attribute exists in LocalStorage.<br>Creates an attribute with the specified attribute name and default value if the attribute does not exist in LocalStorage.|

**Example**

```ts
let para: Record<string, number> = { 'PropA': 47 };
let storage: LocalStorage = new LocalStorage(para);
let res: boolean = storage.setOrCreate('PropA', 121); // true
let res1: boolean = storage.setOrCreate('PropB', 111); // true
let res2: boolean = storage.setOrCreate('PropB', null); // false
```


### link<sup>9+</sup>

link&lt;T&gt;(propName: string): SubscribedAbstractProperty&lt;T&gt;

Establishes two-way data binding with the given attribute in this **LocalStorage** instance. If the given attribute exists, the two-way bound data of the attribute in LocalStorage is returned.

Any update of the data is synchronized back to LocalStorage, which then synchronizes the update to all data and custom components bound to the attribute.

If the given attribute does not exist in LocalStorage, **undefined** is returned.

> **NOTE**
>
> This API can be used in ArkTS widgets since API version 9.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description              |
| -------- | ------ | ---- | ------------------ |
| propName | string | Yes   | Attribute name in LocalStorage.|

**Return value**

| Type                               | Description                                                        |
| ----------------------------------- | ------------------------------------------------------------ |
| SubscribedAbstractProperty&lt;T&gt; | Returns the **SubscribedAbstractProperty&lt;T&gt;** instance if the given attribute exists in LocalStorage; returns undefined otherwise.|

**Example**
```ts
let para: Record<string, number> = { 'PropA': 47 };
let storage: LocalStorage = new LocalStorage(para);
let linkToPropA1: SubscribedAbstractProperty<number> = storage.link('PropA');
let linkToPropA2: SubscribedAbstractProperty<number> = storage.link('PropA'); // linkToPropA2.get() == 47
linkToPropA1.set(48); // Two-way synchronization: linkToPropA1.get() == linkToPropA2.get() == 48
```


### setAndLink<sup>9+</sup>

setAndLink&lt;T&gt;(propName: string, defaultValue: T): SubscribedAbstractProperty&lt;T&gt;

Works in a way similar to the **link** API. If the given attribute exists in LocalStorage, the two-way bound data of the attribute in AppStorage is returned. If the given attribute does not exist, it is created and initialized with **defaultValue** in LocalStorage, and two-way bound data is returned. The value of **defaultValue** must be of the T type and cannot be **undefined** or **null**.

> **NOTE**
>
> This API can be used in ArkTS widgets since API version 9.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name      | Type  | Mandatory| Description                                                    |
| ------------ | ------ | ---- | ------------------------------------------------------------ |
| propName     | string | Yes  | Attribute name in LocalStorage.                                    |
| defaultValue | T      | Yes  | Default value used to initialize the attribute with the specified attribute name in LocalStorage. The value cannot be **undefined** or **null**.|

**Return value**

| Type                               | Description                                                        |
| ----------------------------------- | ------------------------------------------------------------ |
| SubscribedAbstractProperty&lt;T&gt; | Instance of **SubscribedAbstractProperty&lt;T&gt;** and two-way bound data of the given attribute in LocalStorage.|

**Example**
```ts
let para: Record<string, number> = { 'PropA': 47 };
let storage: LocalStorage = new LocalStorage(para);
let link1: SubscribedAbstractProperty<number> = storage.setAndLink('PropB', 49); // Create PropB 49
let link2: SubscribedAbstractProperty<number> = storage.setAndLink('PropA', 50); // PropA exists, remains 47
```


### prop<sup>9+</sup>

prop&lt;S&gt;(propName: string): SubscribedAbstractProperty&lt;S&gt;

Establishes one-way data binding with the given attribute in this **LocalStorage** instance. If the given attribute exists, the one-way bound data of the attribute in LocalStorage is returned. If the given attribute does not exist in LocalStorage, **undefined** is returned. Updates of the one-way bound data are not synchronized back to LocalStorage.

> **NOTE**
>
> This API can be used in ArkTS widgets since API version 9.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description              |
| -------- | ------ | ---- | ------------------ |
| propName | string | Yes   | Attribute name in LocalStorage.|

**Return value**

| Type                               | Description                                                        |
| ----------------------------------- | ------------------------------------------------------------ |
| SubscribedAbstractProperty&lt;S&gt; | Returns the **SubscribedAbstractProperty&lt;S&gt;** instance if the given attribute exists in LocalStorage; returns **undefined** otherwise.|

**Example**
```ts
let para: Record<string, number> = { 'PropA': 47 };
let storage: LocalStorage = new LocalStorage(para);
let prop1: SubscribedAbstractProperty<number> = storage.prop('PropA');
let prop2: SubscribedAbstractProperty<number> = storage.prop('PropA');
prop1.set(1); // one-way sync: prop1.get()=1; but prop2.get() == 47
```


### setAndProp<sup>9+</sup>

setAndProp&lt;S&gt;(propName: string, defaultValue: S): SubscribedAbstractProperty&lt;S&gt;

Works in a way similar to the **prop** API. If the given attribute exists in LocalStorage, the one-way bound data of the attribute in LocalStorage is returned. If the given attribute does not exist, it is created and initialized with **defaultValue** in LocalStorage, and one-way bound data is returned. The value of **defaultValue** must be of the S type and cannot be **undefined** or **null**.

> **NOTE**
>
> This API can be used in ArkTS widgets since API version 9.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name      | Type  | Mandatory| Description                                                    |
| ------------ | ------ | ---- | ------------------------------------------------------------ |
| propName     | string | Yes  | Attribute name in LocalStorage.                                    |
| defaultValue | S      | Yes  | Default value used to initialize the attribute with the specified attribute name in LocalStorage. The value cannot be **undefined** or **null**.|

**Return value**

| Type                               | Description                                                        |
| ----------------------------------- | ------------------------------------------------------------ |
| SubscribedAbstractProperty&lt;S&gt; | Instance of **SubscribedAbstractProperty&lt;S&gt;** and one-way bound data of the given attribute in LocalStorage.|

**Example**

```ts
let para: Record<string, number> = { 'PropA': 47 };
let storage: LocalStorage = new LocalStorage(para);
let prop: SubscribedAbstractProperty<number> = storage.setAndProp('PropB', 49); // PropA -> 47, PropB -> 49
```


### delete<sup>9+</sup>

delete(propName: string): boolean

Deletes the attribute with the specified attribute name from LocalStorage under the prerequisite that the attribute does not have a subscriber. If there is a subscriber, **false** is returned. If the deletion is successful, **true** is returned.

The subscribers of the attribute are attributes with the same name bound to APIs such as **link** and **prop**, and **\@StorageLink('propName')** and **\@StorageProp('propName')**. This means that if **@StorageLink('propName')** and **@StorageProp('propName')** are used in a custom component or if there is still a **SubscribedAbstractProperty** instance in sync with the attribute, the attribute cannot be deleted from LocalStorage.

> **NOTE**
>
> This API can be used in ArkTS widgets since API version 9.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description              |
| -------- | ------ | ---- | ------------------ |
| propName | string | Yes   | Attribute name in LocalStorage.|

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**
```ts
let para: Record<string, number> = { 'PropA': 47 };
let storage: LocalStorage = new LocalStorage(para);
storage.link<number>('PropA');
let res: boolean = storage.delete('PropA'); // false, PropA still has a subscriber
let res1: boolean = storage.delete('PropB'); // false, PropB is not in storage
storage.setOrCreate('PropB', 48);
let res2: boolean = storage.delete('PropB'); // true, PropB is deleted from storage successfully
```


### keys<sup>9+</sup>

keys(): IterableIterator&lt;string&gt;

Obtains all attribute names in LocalStorage.

> **NOTE**
>
> This API can be used in ArkTS widgets since API version 9.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                            | Description                  |
| ------------------------------ | -------------------- |
| IterableIterator&lt;string&gt; | All attribute names in LocalStorage.|

**Example**
```ts
let para: Record<string, number> = { 'PropA': 47 };
let storage: LocalStorage = new LocalStorage(para);
let keys: IterableIterator<string> = storage.keys();
```


### size<sup>9+</sup>

size(): number

Obtains the number of attributes in LocalStorage.

> **NOTE**
>
> This API can be used in ArkTS widgets since API version 9.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type  | Description                        |
| ------ | ---------------------------- |
| number | Number of attributes in LocalStorage.|

**Example**
```ts
let para: Record<string, number> = { 'PropA': 47 };
let storage: LocalStorage = new LocalStorage(para);
let res: number = storage.size(); // 1
```


### clear<sup>9+</sup>

clear(): boolean

Deletes all attributes from LocalStorage under the prerequisite that none of the attributes has a subscriber. If any of the attributes has a subscriber, this API does not take effect and **false** is returned. If the deletion is successful, **true** is returned.

For details about the subscriber, see [delete](#delete9).

> **NOTE**
>
> This API can be used in ArkTS widgets since API version 9.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**


| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|


**Example**
```ts
let para: Record<string, number> = { 'PropA': 47 };
let storage: LocalStorage = new LocalStorage(para);
let res: boolean = storage.clear(); // true, there are no subscribers
```


### GetShared<sup>(deprecated)</sup>

static GetShared(): LocalStorage

Obtains the **LocalStorage** instance shared by the current stage.

> **NOTE**
>
> This API can be used in ArkTS widgets since API version 9.
>
> This API is deprecated since API version 10. You are advised to use [getShared10+](#getshared10) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Model restriction**: This API can be used only in the stage model.

**Return value**

| Type                            | Description               |
| ------------------------------ | ----------------- |
| [LocalStorage](#localstorage9) | **LocalStorage** instance.|

**Example**
```ts
let storage: LocalStorage = LocalStorage.GetShared();
```


## SubscribedAbstractProperty


### get<sup>9+</sup>

abstract get(): T

Obtains attribute data synchronized from AppStorage or LocalStorage.

> **NOTE**
>
> This API can be used in ArkTS widgets since API version 9.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type  | Description                             |
| ---- | ------------------------------- |
| T    | Attribute data synchronized from AppStorage or LocalStorage.|

**Example**
```ts
AppStorage.setOrCreate('PropA', 47); 
let prop1: SubscribedAbstractProperty<number> = AppStorage.prop('PropA');    
prop1.get(); //  prop1.get()=47
```


### set<sup>9+</sup>

abstract set(newValue: T): void

Sets the attribute data synchronized from AppStorage or LocalStorage. The value of **newValue** must be of the T type and cannot be **undefined** or **null**.

> **NOTE**
>
> This API can be used in ArkTS widgets since API version 9.

**System capability**: SystemCapability.ArkUI.ArkUI.Full


**Parameters**


| Name  | Type| Mandatory| Description                             |
| -------- | ---- | ---- | ------------------------------------- |
| newValue | T    | Yes  | Data to set. The value cannot be **undefined** or **null**.|


**Example**
```ts
AppStorage.setOrCreate('PropA', 47);
let prop1: SubscribedAbstractProperty<number> = AppStorage.prop('PropA');
prop1.set(1); //  prop1.get()=1
```

### aboutToBeDeleted<sup>10+</sup>

abstract aboutToBeDeleted(): void

Cancels one-way or two-way synchronization between the **SubscribedAbstractProperty** instance and AppStorage or LocalStorage, and invalidates the instance. After this API is called, the **SubscribedAbstractProperty** instance cannot be used to call the setter or getter.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**
```ts
AppStorage.setOrCreate('PropA', 47);
let link = AppStorage.setAndLink('PropB', 49); // PropA -> 47, PropB -> 49
link.aboutToBeDeleted();
```


## PersistentStorage


For details about how to use PersistentStorage on the UI, see [PersistentStorage: Application State Persistence](../../../quick-start/arkts-persiststorage.md).

### PersistPropsOptions

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name      | Type                                 | Mandatory| Description                                                    |
| ------------ | ------------------------------------- | ---- | ------------------------------------------------------------ |
| key          | string                                | Yes  | Attribute name.                                                    |
| defaultValue | number \| string \| boolean \| Object | Yes  | Default value used to initialize the created attribute when the corresponding attribute is not found in PersistentStorage and AppStorage. The value cannot be **undefined** or **null**.|


### persistProp<sup>10+</sup>

static persistProp&lt;T&gt;(key: string, defaultValue: T): void

Persists the attribute with the specified key in AppStorage to a file. This API is usually called before access to AppStorage.

The sequence of determining the type and value of an attribute is as follows:

1. If the PersistentStorage file contains the attribute with the specified key, an attribute with the key as the name is created in AppStorage and initialized with the attribute of the key found in PersistentStorage.

2. If the attribute with the specified key is not found in the PersistentStorage file, AppStorage is searched for the attribute corresponding to the key. If the matching attribute is found, it is persisted.

3. If no matching attribute is found in AppStorage, it is created in AppStorage, initialized with the value of **defaultValue**, and persisted.

According to the preceding initialization process, if AppStorage contains the matching attribute, the value of this attribute is used to overwrite the value in the PersistentStorage file. Because AppStorage stores data in the memory, the attribute value becomes nonpersistent.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name      | Type  | Mandatory| Description                                                    |
| ------------ | ------ | ---- | ------------------------------------------------------------ |
| key          | string | Yes  | Attribute name.                                                    |
| defaultValue | T      | Yes  | Default value used to initialize the created attribute. The value cannot be **undefined** or **null**.|


**Example**


For details about how to use persistProp, see [Accessing PersistentStorage Initialized Attribute from AppStorage](../../../quick-start/arkts-persiststorage.md#accessing-persistentstorage-initialized-attribute-from-appstorage).


### deleteProp<sup>10+</sup>

static deleteProp(key: string): void

Performs the reverse operation of **persistProp**. Specifically, this API deletes the attribute corresponding to the specified key from PersistentStorage. Subsequent AppStorage operations do not affect data in PersistentStorage.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type    | Mandatory  | Description                   |
| ---- | ------ | ---- | ----------------------- |
| key  | string | Yes   | Attribute name in PersistentStorage.|

**Example**
```ts
PersistentStorage.deleteProp('highScore');
```


### persistProps<sup>10+</sup>

static persistProps(props: PersistPropsOptions[]): void

Works in a way similar to the **persistProp** API, with the difference that it allows for persistence in batches and is therefore ideal for initialization during application startup.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name       | Type                                      | Mandatory  | Description                                    |
| ---------- | ---------------------------------------- | ---- | ---------------------------------------- |
| props | [PersistPropsOptions](#persistpropsoptions)[] | Yes| Array of persistent attributes.|

**Example**
```ts
PersistentStorage.persistProps([{ key: 'highScore', defaultValue: '0' }, { key: 'wightScore', defaultValue: '1' }]);
```


### keys<sup>10+</sup>

static keys(): Array&lt;string&gt;

Obtains an array of keys for all persistent attributes.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type               | Description                              |
| ------------------- | ---------------------------------- |
| Array&lt;string&gt; | Array of keys of all persistent attributes.|

**Example**
```ts
let keys: Array<string> = PersistentStorage.keys();
```


### PersistProp<sup>(deprecated)</sup>

static PersistProp&lt;T&gt;(key: string, defaultValue: T): void

Persists the attribute with the specified key in AppStorage to a file. This API is usually called before access to AppStorage.

The sequence of determining the type and value of an attribute is as follows:

1. If the PersistentStorage file contains the attribute with the specified key, an attribute with the key as the name is created in AppStorage and initialized with the attribute of the key found in PersistentStorage.

2. If the attribute with the specified key is not found in the PersistentStorage file, AppStorage is searched for the attribute corresponding to the key. If the matching attribute is found, it is persisted.

3. If no matching attribute is found in AppStorage, it is created in AppStorage, initialized with the value of **defaultValue**, and persisted.

According to the preceding initialization process, if AppStorage contains the matching attribute, the value of this attribute is used to overwrite the value in the PersistentStorage file. Because AppStorage stores data in the memory, the attribute value becomes nonpersistent.


> **NOTE**
>
> This API is deprecated since API version 10. You are advised to use [persistProp10+](#persistprop10) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name      | Type  | Mandatory| Description                                                    |
| ------------ | ------ | ---- | ------------------------------------------------------------ |
| key          | string | Yes  | Attribute name.                                                    |
| defaultValue | T      | Yes  | Default value used to initialize the created attribute. The value cannot be **undefined** or **null**.|


**Example**


```ts
PersistentStorage.PersistProp('highScore', '0');
```


### DeleteProp<sup>(deprecated)</sup>

static DeleteProp(key: string): void

Performs the reverse operation of **PersistProp**. Specifically, this API deletes the attribute corresponding to the specified key from PersistentStorage. Subsequent AppStorage operations do not affect data in PersistentStorage.


> **NOTE**
>
> This API is deprecated since API version 10. You are advised to use [deleteProp10+](#deleteprop10) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type    | Mandatory  | Description                   |
| ---- | ------ | ---- | ----------------------- |
| key  | string | Yes   | Attribute name in PersistentStorage.|

**Example**
```ts
PersistentStorage.DeleteProp('highScore');
```


### PersistProps<sup>(deprecated)</sup>

static PersistProps(properties: {key: string, defaultValue: any;}[]): void

Works in a way similar to the **PersistProp** API, with the difference that it allows for persistence in batches and is therefore ideal for initialization during application startup.

> **NOTE**
>
> This API is deprecated since API version 10. You are advised to use [persistProps10+](#persistprops10) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                              | Mandatory| Description                                                    |
| ---------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| properties | {key: string, defaultValue: any}[] | Yes  | Array of attributes to persist.<br>**key**: attribute name.<br>**defaultValue**: default value. The rules are the same as those of **PersistProp**.|

**Example**

```ts
PersistentStorage.PersistProps([{ key: 'highScore', defaultValue: '0' }, { key: 'wightScore', defaultValue: '1' }]);
```


### Keys<sup>(deprecated)</sup>

static Keys(): Array&lt;string&gt;

Obtains an array of keys for all persistent attributes.

> **NOTE**
>
> This API is deprecated since API version 10. You are advised to use [keys10+](#keys10-1) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type               | Description                              |
| ------------------- | ---------------------------------- |
| Array&lt;string&gt; | Array of keys of all persistent attributes.|

**Example**
```ts
let keys: Array<string> = PersistentStorage.Keys();
```


## Environment


For details about how to use Environment, see [Environment: Device Environment Query](../../../quick-start/arkts-environment.md).

### EnvPropsOptions

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name      | Type                       | Mandatory| Description                                                    |
| ------------ | --------------------------- | ---- | ------------------------------------------------------------ |
| key          | string                      | Yes  | Environment variable name. For details about the value range, see [Built-in Environment Variables](#built-in-environment-variables).|
| defaultValue | number \| string \| boolean | Yes  | Default value used if the value of the environment variable key is not found in AppStorage.|


### envProp<sup>10+</sup>

static envProp&lt;S&gt;(key: string, value: S): boolean

Saves the built-in environment variable key in environment to AppStorage. If the value of the environment variable key is not found in AppStorage, the default value is used. If the value is successfully saved, **true** is returned. If the value of the environment variable key is found in AppStorage, **false** is returned.

You are advised to call this API when the application is started.

It is incorrect to use AppStorage to read environment variables without invoking **envProp** first.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                                    |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| key    | string | Yes  | Environment variable name. For details about the value range, see [Built-in Environment Variables](#built-in-environment-variables).|
| value  | S      | Yes  | Default value used if the value of the environment variable key is not found in AppStorage.|

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **false** if the attribute corresponding to the key exists in AppStorage; creates an attribute with the key and the default value and returns **true** otherwise.|

**Example**


For details about how to use **envProp**, see [Accessing Environment Parameters from UI](../../../quick-start/arkts-environment.md#accessing-environment-parameters-from-ui).


### envProps<sup>10+</sup>

static envProps(props: EnvPropsOptions[]): void

Works in a way similar to the [envProp](#envprop10) API, with the difference that it allows for initialization of multiple attributes in batches. You are advised to call this API during application startup to save system environment variables to AppStorage in batches.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                         | Mandatory| Description                            |
| ------ | --------------------------------------------- | ---- | ------------------------------------ |
| props  | [EnvPropsOptions](#envpropsoptions)[] | Yes  | Array of key-value pairs consisting of system environment variables and default values.|

**Example**
```ts
Environment.envProps([{ key: 'accessibilityEnabled', defaultValue: 'default' }, {
  key: 'languageCode',
  defaultValue: 'en'
}, { key: 'prop', defaultValue: 'hhhh' }]);
```


### keys<sup>10+</sup>

static keys(): Array&lt;string&gt;

Array of keys of environment variables.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                 | Description         |
| ------------------- | ----------- |
| Array&lt;string&gt; | Returns an array of associated system attributes.|

**Example**
```ts
Environment.envProps([{ key: 'accessibilityEnabled', defaultValue: 'default' }, {
  key: 'languageCode',
  defaultValue: 'en'
}, { key: 'prop', defaultValue: 'hhhh' }]);

let keys: Array<string> = Environment.keys(); // accessibilityEnabled, languageCode, prop
```


### EnvProp<sup>(deprecated)</sup>

static EnvProp&lt;S&gt;(key: string, value: S): boolean

Saves the built-in environment variable key in environment to AppStorage. If the value of the environment variable key is not found in AppStorage, the default value is used. If the value is successfully saved, **true** is returned. If the value of the environment variable key is found in AppStorage, **false** is returned.

You are advised to call this API when the application is started.

It is incorrect to use AppStorage to read environment variables without invoking **EnvProp** first.

> **NOTE**
>
> This API is deprecated since API version 10. You are advised to use [envProp10+](#envprop10) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                                    |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| key    | string | Yes  | Environment variable name. For details about the value range, see [Built-in Environment Variables](#built-in-environment-variables).|
| value  | S      | Yes  | Default value used if the value of the environment variable key is not found in AppStorage.|

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **false** if the attribute corresponding to the key exists in AppStorage; creates an attribute with the key and the default value and returns **true** otherwise.|

**Example**


```ts
Environment.EnvProp('accessibilityEnabled', 'default');
```


### EnvProps<sup>(deprecated)</sup>

static EnvProps(props: {key: string; defaultValue: any;}[]): void

Works in a way similar to the [EnvProp](#envpropdeprecated) API, with the difference that it allows for initialization of multiple attributes in batches. You are advised to call this API during application startup to save system environment variables to AppStorage in batches.

> **NOTE**
>
> This API is deprecated since API version 10. You are advised to use [envProps10+](#envprops10) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                             | Mandatory| Description                            |
| ------ | ------------------------------------------------- | ---- | ------------------------------------ |
| props  | {key: string, defaultValue: any}[] | Yes  | Array of key-value pairs consisting of system environment variables and default values.|

**Example**
```ts
Environment.EnvProps([{ key: 'accessibilityEnabled', defaultValue: 'default' }, {
  key: 'languageCode',
  defaultValue: 'en'
}, { key: 'prop', defaultValue: 'hhhh' }]);
```


### Keys<sup>(deprecated)</sup>

static Keys(): Array&lt;string&gt;

Array of keys of environment variables.

> **NOTE**
>
> This API is deprecated since API version 10. You are advised to use [keys10+](#keys10-2) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                 | Description         |
| ------------------- | ----------- |
| Array&lt;string&gt; | Returns an array of associated system attributes.|

**Example**

```ts
Environment.EnvProps([{ key: 'accessibilityEnabled', defaultValue: 'default' }, {
  key: 'languageCode',
  defaultValue: 'en'
}, { key: 'prop', defaultValue: 'hhhh' }]);

let keys: Array<string> = Environment.Keys(); // accessibilityEnabled, languageCode, prop
```


## Built-in Environment Variables

| key                  | Type           | Description                                                        |
| -------------------- | --------------- | ------------------------------------------------------------ |
| accessibilityEnabled | string          | Whether to enable accessibility. If there is no value of **accessibilityEnabled** in the environment variables, the default value passed through APIs such as **envProp** and **envProps** is added to AppStorage.|
| colorMode            | ColorMode       | Color mode. The options are as follows:<br>- **ColorMode.LIGHT**: light mode.<br>- **ColorMode.DARK**: dark mode.|
| fontScale            | number          | Font scale.                                              |
| fontWeightScale      | number          | Font weight scale.                                                  |
| layoutDirection      | LayoutDirection | Layout direction. The options are as follows:<br>- **LayoutDirection.LTR**: from left to right.<br>- **LayoutDirection.RTL**: from right to left.|
| languageCode         | string          | Current system language. The value is in lowercase, for example, **zh**.                            |
