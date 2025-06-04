# State Management with Application-level Variables


The state management module provides data storage, persistent data management, UIAbility data storage, and environment state required by applications.


>**NOTE**
>
>The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


T and S in this topic represent the types as described below.


| Type  | Description                                    |
| ---- | -------------------------------------- |
| T    | Class, number, boolean, string, and arrays of these types.|
| S    | number, boolean, string.                |


## AppStorage

For details about how to use AppStorage, see [AppStorage: Storing Application-wide UI State](../../../ui/state-management/arkts-appstorage.md).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### ref<sup>12+</sup>

static ref\<T\>(propName: string): AbstractProperty\<T\> | undefined

Returns a reference to the data corresponding to **propName** in [AppStorage](../../../ui/state-management/arkts-appstorage.md). If the provided **propName** does not exist, this API returns **undefined**.

This API is similar to [link](#link10) but does not require manually releasing the returned variable of the [AbstractProperty](#abstractproperty) type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type  | Mandatory| Description              |
| -------- | ------ | ---- | ---------------------- |
| propName | string | Yes  | Property name in AppStorage.|

**Return value**

| Type                                  | Description                                                        |
| -------------------------------------- | ------------------------------------------------------------ |
| [AbstractProperty&lt;T&gt;](#abstractproperty) \| undefined | A reference to the property in AppStorage, or **undefined** if the property does not exist.|

**Example**

```ts
AppStorage.setOrCreate('PropA', 47);
let refToPropA1: AbstractProperty<number> | undefined = AppStorage.ref('PropA');
let refToPropA2: AbstractProperty<number> | undefined = AppStorage.ref('PropA'); // refToPropA2.get() == 47
refToPropA1?.set(48); // Synchronously updates AppStorage: refToPropA1.get() == refToPropA2.get() == 48.
```

### setAndRef<sup>12+</sup>

static setAndRef&lt;T&gt;(propName: string, defaultValue: T): AbstractProperty&lt;T&gt;

Similar to the [ref](#ref12) API, returns a reference to the data corresponding to **propName** in [AppStorage](../../../ui/state-management/arkts-appstorage.md). If **propName** does not exist, this API creates and initializes the property in AppStorage using **defaultValue** and returns its reference. **defaultValue** must be of the **T** type and can be **null** or **undefined**.

This API is similar to [setAndLink](#setandlink10) but does not require manually releasing the returned variable of the [AbstractProperty](#abstractproperty) type.

> **NOTE**
>
> Since API version 12, AppStorage supports [Map](../../../ui/state-management/arkts-appstorage.md#decorating-variables-of-the-map-type), [Set](../../../ui/state-management/arkts-appstorage.md#decorating-variables-of-the-set-type), [Date](../../../ui/state-management/arkts-appstorage.md#decorating-variables-of-the-date-type), **null**, **undefined**, and [union](../../../ui/state-management/arkts-appstorage.md#union-type) types.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name      | Type  | Mandatory| Description                                                    |
| ------------ | ------ | ---- | ------------------------------------------------------------ |
| propName     | string | Yes  | Property name in AppStorage.                                      |
| defaultValue | T      | Yes  | Default value used to initialize **propName** in AppStorage if it does not exist. The value can be **null** or **undefined**.|

**Return value**

| Type                     | Description                                                        |
| ------------------------- | ------------------------------------------------------------ |
| [AbstractProperty&lt;T&gt;](#abstractproperty) | Instance of **AbstractProperty&lt;T&gt;**, which is a reference to the property in AppStorage corresponding to **propName**.|

**Example**

```ts
AppStorage.setOrCreate('PropA', 47);
let ref1: AbstractProperty<number> = AppStorage.setAndRef('PropB', 49); // Create PropB 49
let ref2: AbstractProperty<number> = AppStorage.setAndRef('PropA', 50); // PropA exists, remains 47
```


### link<sup>10+</sup>

static link&lt;T&gt;(propName: string): SubscribedAbstractProperty&lt;T&gt;

Establishes a two-way data binding with the property corresponding to **propName** in [AppStorage](../../../ui/state-management/arkts-appstorage.md). If the given property exists in AppStorage, the two-way bound data of the property in AppStorage is returned.

Any update of the data is synchronized back to AppStorage, which then synchronizes the update to all data and custom components bound to the property.

If the given property does not exist in AppStorage, **undefined** is returned.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description            |
| -------- | ------ | ---- | ---------------- |
| propName | string | Yes   | Property name in AppStorage.|

**Return value**

| Type                               | Description                                                        |
| ----------------------------------- | ------------------------------------------------------------ |
| [SubscribedAbstractProperty&lt;T&gt;](#subscribedabstractproperty) | Two-way bound data of the specified property in AppStorage, or **undefined** if the property does not exist.|

**Example**
```ts
AppStorage.setOrCreate('PropA', 47);
let linkToPropA1: SubscribedAbstractProperty<number> = AppStorage.link('PropA');
let linkToPropA2: SubscribedAbstractProperty<number> = AppStorage.link('PropA'); // linkToPropA2.get() == 47
linkToPropA1.set(48); // Two-way synchronization: linkToPropA1.get() == linkToPropA2.get() == 48
```


### setAndLink<sup>10+</sup>

static setAndLink&lt;T&gt;(propName: string, defaultValue: T): SubscribedAbstractProperty&lt;T&gt;

Similar to the [link](#link10) API, establishes a two-way data binding with the property corresponding to **propName** in [AppStorage](../../../ui/state-management/arkts-appstorage.md). If the given property exists in AppStorage, this API returns the two-way bound data for the property. If the given property does not exist, this API creates and initializes the property in AppStorage using **defaultValue** and returns its two-way bound data. The value of **defaultValue** must be of the **T** type. Since API version 12, it can be **null** or **undefined**.

> **NOTE**
>
> Since API version 12, AppStorage supports [Map](../../../ui/state-management/arkts-appstorage.md#decorating-variables-of-the-map-type), [Set](../../../ui/state-management/arkts-appstorage.md#decorating-variables-of-the-set-type), [Date](../../../ui/state-management/arkts-appstorage.md#decorating-variables-of-the-date-type), **null**, **undefined**, and [union](../../../ui/state-management/arkts-appstorage.md#union-type) types.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name      | Type  | Mandatory| Description                                                    |
| ------------ | ------ | ---- | ------------------------------------------------------------ |
| propName     | string | Yes  | Property name in AppStorage.                                      |
| defaultValue | T      | Yes  | Default value used to initialize **propName** in AppStorage if it does not exist. Since API version 12, **defaultValue** can be **null** or **undefined**.|

**Return value**

| Type                                 | Description                                      |
| ----------------------------------- | ---------------------------------------- |
| [SubscribedAbstractProperty&lt;T&gt;](#subscribedabstractproperty) | Instance of **SubscribedAbstractProperty&lt;T&gt;** and two-way bound data of the given property in AppStorage.|

**Example**
```ts
AppStorage.setOrCreate('PropA', 47);
let link1: SubscribedAbstractProperty<number> = AppStorage.setAndLink('PropB', 49); // Create PropB 49
let link2: SubscribedAbstractProperty<number> = AppStorage.setAndLink('PropA', 50); // PropA exists, remains 47
```


### prop<sup>10+</sup>

static prop&lt;T&gt;(propName: string): SubscribedAbstractProperty&lt;T&gt;

Establishes a one-way data binding with the property corresponding to **propName** in [AppStorage](../../../ui/state-management/arkts-appstorage.md). If the given property exists in AppStorage, the one-way bound data of the property in AppStorage is returned. If the given property does not exist in AppStorage, **undefined** is returned. Updates of the one-way bound data are not synchronized back to AppStorage.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description            |
| -------- | ------ | ---- | ---------------- |
| propName | string | Yes   | Property name in AppStorage.|

**Return value**

| Type                               | Description                                                        |
| ----------------------------------- | ------------------------------------------------------------ |
| [SubscribedAbstractProperty&lt;T&gt;](#subscribedabstractproperty) | One-way bound data of the specified property in AppStorage, or **undefined** if the property does not exist.|

**Example**

```ts
AppStorage.setOrCreate('PropA', 47);
let prop1: SubscribedAbstractProperty<number> = AppStorage.prop('PropA');
let prop2: SubscribedAbstractProperty<number> = AppStorage.prop('PropA');
prop1.set(1); // one-way sync: prop1.get()=1; but prop2.get() == 47
```


### setAndProp<sup>10+</sup>

static setAndProp&lt;T&gt;(propName: string, defaultValue: T): SubscribedAbstractProperty&lt;T&gt;

Similar to the [prop](#prop10) API, establishes a one-way data binding with the property corresponding to **propName** in [AppStorage](../../../ui/state-management/arkts-appstorage.md). If the given property exists in AppStorage, this API returns the one-way bound data for the property. If the given property does not exist, this API creates and initializes the property in AppStorage using **defaultValue** and returns its one-way bound data. The value of **defaultValue** must be of the **T** type. Since API version 12, it can be **null** or **undefined**.

> **NOTE**
>
> Since API version 12, AppStorage supports [Map](../../../ui/state-management/arkts-appstorage.md#decorating-variables-of-the-map-type), [Set](../../../ui/state-management/arkts-appstorage.md#decorating-variables-of-the-set-type), [Date](../../../ui/state-management/arkts-appstorage.md#decorating-variables-of-the-date-type), **null**, **undefined**, and [union](../../../ui/state-management/arkts-appstorage.md#union-type) types.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name      | Type  | Mandatory| Description                                                    |
| ------------ | ------ | ---- | ------------------------------------------------------------ |
| propName     | string | Yes  | Property name in AppStorage.                                      |
| defaultValue | T      | Yes  | Default value used to initialize **propName** in AppStorage if it does not exist. Since API version 12, **defaultValue** can be **null** or **undefined**.|

**Return value**

| Type                                 | Description                                     |
| ----------------------------------- | --------------------------------------- |
| [SubscribedAbstractProperty&lt;T&gt;](#subscribedabstractproperty) | Instance of **SubscribedAbstractProperty&lt;T&gt;**.|

**Example**
```ts
AppStorage.setOrCreate('PropA', 47);
let prop: SubscribedAbstractProperty<number> = AppStorage.setAndProp('PropB', 49); // PropA -> 47, PropB -> 49
```


### has<sup>10+</sup>

static has(propName: string): boolean

Checks whether the property corresponding to **propName** exists in [AppStorage](../../../ui/state-management/arkts-appstorage.md).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description            |
| -------- | ------ | ---- | ---------------- |
| propName | string | Yes   | Property name in AppStorage.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | Returns **true** if the property exists in AppStorage; returns **false** otherwise.|

**Example**
```ts
AppStorage.has('simpleProp');
```


### get<sup>10+</sup>

static get&lt;T&gt;(propName: string): T | undefined

Obtains the value of the property corresponding to **propName** from [AppStorage](../../../ui/state-management/arkts-appstorage.md). If the property does not exist, this API returns **undefined**.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description            |
| -------- | ------ | ---- | ---------------- |
| propName | string | Yes   | Property name in AppStorage.|

**Return value**

| Type                    | Description                                                       |
| ------------------------ | ----------------------------------------------------------- |
| T \| undefined | Value of the property corresponding to **propName** in AppStorage, or **undefined** if it does not exist.|

**Example**
```ts
AppStorage.setOrCreate('PropA', 47);
let value: number = AppStorage.get('PropA') as number; // 47
```


### set<sup>10+</sup>

static set&lt;T&gt;(propName: string, newValue: T): boolean

Sets the value of the property corresponding to **propName** in [AppStorage](../../../ui/state-management/arkts-appstorage.md). If the value of **newValue** is the same as the current value of the property, no assignment is performed, and the state variable does not instruct the UI to update the value of the property. Since API version 12, **newValue** can be **null** or **undefined**.

> **NOTE**
>
> Since API version 12, AppStorage supports [Map](../../../ui/state-management/arkts-appstorage.md#decorating-variables-of-the-map-type), [Set](../../../ui/state-management/arkts-appstorage.md#decorating-variables-of-the-set-type), [Date](../../../ui/state-management/arkts-appstorage.md#decorating-variables-of-the-date-type), **null**, **undefined**, and [union](../../../ui/state-management/arkts-appstorage.md#union-type) types.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description                  |
| -------- | ------ | ---- | ---------------------- |
| propName | string | Yes   | Property name in AppStorage.      |
| newValue | T      | Yes   | Property value. Since API version 12, the value can be **null** or **undefined**.|

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **false** if the property corresponding to **propName** does not exist in AppStorage or if the assignment fails. Returns **true** if the assignment is successful.|

**Example**
```ts
AppStorage.setOrCreate('PropA', 48);
let res: boolean = AppStorage.set('PropA', 47) // true
let res1: boolean = AppStorage.set('PropB', 47) // false
```


### setOrCreate<sup>10+</sup>

static setOrCreate&lt;T&gt;(propName: string, newValue: T): void

Sets the value of the property corresponding to **propName** in [AppStorage](../../../ui/state-management/arkts-appstorage.md) to a new value, if the property exists and the new value is different from the current value. If the new value is the same as the current value of the property, no assignment is performed, and the state variable does not instruct the UI to update the value of the property.
If the property does not exist, this API creates it with the value of **newValue**. This **setOrCreate** API can create only one AppStorage key-value pair each time. To create multiple key-value pairs, call this API multiple times. Since API version 12, **newValue** can be **null** or **undefined**.

> **NOTE**
>
> Since API version 12, AppStorage supports [Map](../../../ui/state-management/arkts-appstorage.md#decorating-variables-of-the-map-type), [Set](../../../ui/state-management/arkts-appstorage.md#decorating-variables-of-the-set-type), [Date](../../../ui/state-management/arkts-appstorage.md#decorating-variables-of-the-date-type), **null**, **undefined**, and [union](../../../ui/state-management/arkts-appstorage.md#union-type) types.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description                  |
| -------- | ------ | ---- | ---------------------- |
| propName | string | Yes   | Property name in AppStorage.      |
| newValue | T      | Yes   | Property value. Since API version 12, the value can be **null** or **undefined**.|

**Example**
```ts
AppStorage.setOrCreate('simpleProp', 121);
```


### delete<sup>10+</sup>

static delete(propName: string): boolean

Deletes the property corresponding to **propName** from [AppStorage](../../../ui/state-management/arkts-appstorage.md).

The deletion is only successful if the property has no subscribers. If there is a subscriber, the deletion fails and **false** is returned. If the deletion is successful, **true** is returned.

The property subscribers include the following:

1. Variables decorated by [\@StorageLink](../../../ui/state-management/arkts-appstorage.md#storagelink) or [\@StorageProp](../../../ui/state-management/arkts-appstorage.md#storageprop)

2. Instances of [SubscribedAbstractProperty](#subscribedabstractproperty) returned by [link](#link10), [prop](#prop10), [setAndLink](#setandlink10), or [setAndProp](#setandprop10)

To delete these subscribers:

1. Remove the custom component containing @StorageLink or @StorageProp. For details, see [Custom Component Deletion](../../../ui/state-management/arkts-page-custom-components-lifecycle.md#custom-component-deletion).

2. Call the [aboutToBeDeleted](#abouttobedeleted10) API on instances of **SubscribedAbstractProperty** returned by **link**, **prop**, **setAndLink**, or **setAndProp**.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description            |
| -------- | ------ | ---- | ---------------- |
| propName | string | Yes   | Property name in AppStorage.|

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

Obtains all property names in [AppStorage](../../../ui/state-management/arkts-appstorage.md).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                            | Description                |
| ------------------------------ | ------------------ |
| IterableIterator&lt;string&gt; | All property names in AppStorage.|

**Example**
```ts
AppStorage.setOrCreate('PropB', 48);
let keys: IterableIterator<string> = AppStorage.keys();
```


### clear<sup>10+</sup>

static clear(): boolean

Deletes all properties from [AppStorage](../../../ui/state-management/arkts-appstorage.md). The deletion is only successful if none of the properties in AppStorage have any subscribers. If there are subscribers, this API does not take effect and **false** is returned. If the deletion is successful, **true** is returned.

For details about the subscriber, see [delete](#delete10).

**Atomic service API**: This API can be used in atomic services since API version 11.

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

Obtains the number of properties in [AppStorage](../../../ui/state-management/arkts-appstorage.md).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description                 |
| ------ | ------------------- |
| number | Number of properties in AppStorage.|

**Example**
```ts
AppStorage.setOrCreate('PropB', 48);
let res: number = AppStorage.size(); // 1
```


### Link<sup>(deprecated)</sup>

static Link(propName: string): any

Establishes a two-way data binding with the property corresponding to **propName** in [AppStorage](../../../ui/state-management/arkts-appstorage.md). If the given property exists in AppStorage, the two-way bound data of the property in AppStorage is returned.

Any update of the data is synchronized back to AppStorage, which then synchronizes the update to all data and custom components bound to the property.

If the given property does not exist in AppStorage, **undefined** is returned.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 10. You are advised to use [link10+](#link10) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description            |
| -------- | ------ | ---- | ---------------- |
| propName | string | Yes   | Property name in AppStorage.|

**Return value**

| Type                            | Description                                                        |
| -------------------------------- | ------------------------------------------------------------ |
| any | Two-way bound data of the specified property in AppStorage, or **undefined** if the property does not exist.|

**Example**
```ts
AppStorage.SetOrCreate('PropA', 47);
let linkToPropA1: SubscribedAbstractProperty<number> = AppStorage.Link('PropA');
let linkToPropA2: SubscribedAbstractProperty<number> = AppStorage.Link('PropA'); // linkToPropA2.get() == 47
linkToPropA1.set(48); // Two-way synchronization: linkToPropA1.get() == linkToPropA2.get() == 48
```

### SetAndLink<sup>(deprecated)</sup>

static SetAndLink&lt;T&gt;(propName: string, defaultValue: T): SubscribedAbstractProperty&lt;T&gt;

Similar to the [Link](#linkdeprecated) API, establishes a two-way data binding with the property corresponding to **propName** in [AppStorage](../../../ui/state-management/arkts-appstorage.md). If the given property exists in AppStorage, this API returns the two-way bound data for the property. If the given property does not exist, this API creates and initializes the property in AppStorage using **defaultValue** and returns its two-way bound data. The value of **defaultValue** must be of the **T** type and cannot be **null** or **undefined**.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 10. You are advised to use [setAndLink10+](#setandlink10) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name      | Type  | Mandatory| Description                                                    |
| ------------ | ------ | ---- | ------------------------------------------------------------ |
| propName     | string | Yes  | Property name in AppStorage.                                      |
| defaultValue | T      | Yes  | Default value used to initialize **propName** in AppStorage if it does not exist. The value cannot be **null** or **undefined**.|

**Return value**

| Type                                 | Description                                      |
| ----------------------------------- | ---------------------------------------- |
| [SubscribedAbstractProperty&lt;T&gt;](#subscribedabstractproperty) | Instance of **SubscribedAbstractProperty&lt;T&gt;** and two-way bound data of the given property in AppStorage.|

**Example**
```ts
AppStorage.SetOrCreate('PropA', 47);
let link1: SubscribedAbstractProperty<number> = AppStorage.SetAndLink('PropB', 49); // Create PropB 49
let link2: SubscribedAbstractProperty<number> = AppStorage.SetAndLink('PropA', 50); // PropA exists, remains 47
```


### Prop<sup>(deprecated)</sup>

static Prop(propName: string): any

Establishes a one-way data binding with the property corresponding to **propName** in [AppStorage](../../../ui/state-management/arkts-appstorage.md). If the given property exists in AppStorage, the one-way bound data of the property in AppStorage is returned. If the given property does not exist in AppStorage, **undefined** is returned. Updates of the one-way bound data are not synchronized back to AppStorage.

> **NOTE**
>
> **Prop** supports only simple types.
>
> This API is supported since API version 7 and deprecated since API version 10. You are advised to use [prop10+](#prop10) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description            |
| -------- | ------ | ---- | ---------------- |
| propName | string | Yes   | Property name in AppStorage.|

**Return value**

| Type                            | Description                                                        |
| -------------------------------- | ------------------------------------------------------------ |
| any | One-way bound data of the specified property in AppStorage, or **undefined** if the property does not exist.|

**Example**
```ts
AppStorage.SetOrCreate('PropA', 47);
let prop1: SubscribedAbstractProperty<number> = AppStorage.Prop('PropA');
let prop2: SubscribedAbstractProperty<number> = AppStorage.Prop('PropA');
prop1.set(1); // one-way sync: prop1.get()=1; but prop2.get() == 47
```

### SetAndProp<sup>(deprecated)</sup>

static SetAndProp&lt;S&gt;(propName: string, defaultValue: S): SubscribedAbstractProperty&lt;S&gt;

Similar to the [Prop](#propdeprecated) API, establishes a one-way data binding with the property corresponding to **propName** in [AppStorage](../../../ui/state-management/arkts-appstorage.md). If the given property exists in AppStorage, this API returns the one-way bound data for the property. If the given property does not exist, this API creates and initializes the property in AppStorage using **defaultValue** and returns its one-way bound data. The value of **defaultValue** must be of the **S** type and cannot be **null** or **undefined**.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 10. You are advised to use [setAndProp10+](#setandprop10) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name      | Type  | Mandatory| Description                                                    |
| ------------ | ------ | ---- | ------------------------------------------------------------ |
| propName     | string | Yes  | Property name in AppStorage.                                      |
| defaultValue | S      | Yes  | Default value used to initialize **propName** in AppStorage if it does not exist. The value cannot be **null** or **undefined**.|

**Return value**

| Type                                 | Description                                     |
| ----------------------------------- | --------------------------------------- |
| [SubscribedAbstractProperty&lt;S&gt;](#subscribedabstractproperty) | Instance of **SubscribedAbstractProperty&lt;S&gt;**.|

**Example**
```ts
AppStorage.SetOrCreate('PropA', 47);
let prop: SubscribedAbstractProperty<number> = AppStorage.SetAndProp('PropB', 49); // PropA -> 47, PropB -> 49
```

### Has<sup>(deprecated)</sup>

static Has(propName: string): boolean

Checks whether the property corresponding to **propName** exists in [AppStorage](../../../ui/state-management/arkts-appstorage.md).

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 10. You are advised to use [has10+](#has10) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description            |
| -------- | ------ | ---- | ---------------- |
| propName | string | Yes   | Property name in AppStorage.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | Returns **true** if the property exists in AppStorage; returns **false** otherwise.|

**Example**
```ts
AppStorage.Has('simpleProp');
```

### Get<sup>(deprecated)</sup>

static Get&lt;T&gt;(propName: string): T | undefined

Obtains the value of the property corresponding to **propName** from [AppStorage](../../../ui/state-management/arkts-appstorage.md). If the property does not exist, this API returns **undefined**.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 10. You are advised to use [get10+](#get10) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description            |
| -------- | ------ | ---- | ---------------- |
| propName | string | Yes   | Property name in AppStorage.|

**Return value**

| Type                    | Description                                                        |
| ------------------------ | ------------------------------------------------------------ |
| T \| undefined | Value of the property corresponding to **propName** in AppStorage, or **undefined** if it does not exist.|

**Example**
```ts
AppStorage.SetOrCreate('PropA', 47);
let value: number = AppStorage.Get('PropA') as number; // 47
```

### Set<sup>(deprecated)</sup>

static Set&lt;T&gt;(propName: string, newValue: T): boolean

Sets the value of the property corresponding to **propName** in [AppStorage](../../../ui/state-management/arkts-appstorage.md).

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 10. You are advised to use [set10+](#set10) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type  | Mandatory| Description                       |
| -------- | ------ | ---- | ------------------------------- |
| propName | string | Yes  | Property name in AppStorage.         |
| newValue | T      | Yes  | Property value, which cannot be **null** or **undefined**.|

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **true** if the operation is successful; returns **false** if the property corresponding to **propName** does not exist in AppStorage, or the value to set is **undefined** or **null**.  |

**Example**
```ts
AppStorage.SetOrCreate('PropA', 48);
let res: boolean = AppStorage.Set('PropA', 47) // true
let res1: boolean = AppStorage.Set('PropB', 47) // false
```

### SetOrCreate<sup>(deprecated)</sup>

static SetOrCreate&lt;T&gt;(propName: string, newValue: T): void

Sets the value of the property corresponding to **propName** in [AppStorage](../../../ui/state-management/arkts-appstorage.md) to a new value, if the property exists. If the property does not exist, this API creates it with the value of **newValue**.

The value of **newValue** cannot be **null** or **undefined**.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 10. You are advised to use [setOrCreate10+](#setorcreate10) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type  | Mandatory| Description                       |
| -------- | ------ | ---- | ------------------------------- |
| propName | string | Yes  | Property name in AppStorage.         |
| newValue | T      | Yes  | Property value, which cannot be **null** or **undefined**.|

**Example**
```ts
AppStorage.SetOrCreate('simpleProp', 121);
```

### Delete<sup>(deprecated)</sup>

static Delete(propName: string): boolean

Deletes the property corresponding to **propName** from [AppStorage](../../../ui/state-management/arkts-appstorage.md).

The deletion is only successful if the property has no subscribers. If there is a subscriber, the deletion fails and **false** is returned. If the deletion is successful, **true** is returned.

Subscribers include properties bound using [Link](#linkdeprecated) and [Prop](#propdeprecated) APIs, as well as those decorated with [\@StorageLink('propName')](../../../ui/state-management/arkts-appstorage.md#storagelink) and [\@StorageProp('propName')](../../../ui/state-management/arkts-appstorage.md#storageprop). This means that if @StorageLink('propName') and @StorageProp('propName') are used in a custom component or if there is still a **SubscribedAbstractProperty** instance in a synchronization relationship with the property, the property cannot be deleted from AppStorage.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 10. You are advised to use [delete10+](#delete10) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description            |
| -------- | ------ | ---- | ---------------- |
| propName | string | Yes   | Property name in AppStorage.|

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

Obtains all property names in [AppStorage](../../../ui/state-management/arkts-appstorage.md).

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 10. You are advised to use [keys10+](#keys10) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                            | Description                |
| ------------------------------ | ------------------ |
| IterableIterator&lt;string&gt; | All property names in AppStorage.|

**Example**
```ts
AppStorage.SetOrCreate('PropB', 48);
let keys: IterableIterator<string> = AppStorage.Keys();
```


### staticClear<sup>(deprecated)</sup>

static staticClear(): boolean

Deletes all properties.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [clear10+](#clear10) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type     | Description                               |
| ------- | --------------------------------- |
| boolean | Returns **true** if all properties are deleted; returns **false** if any of the properties is being referenced by a state variable.|

**Example**
```ts
let simple = AppStorage.staticClear();
```


### Clear<sup>(deprecated)</sup>

static Clear(): boolean

Deletes all properties from [AppStorage](../../../ui/state-management/arkts-appstorage.md). The deletion is only successful if none of the properties in AppStorage have any subscribers. If there are subscribers, this API does not take effect and **false** is returned. If the deletion is successful, **true** is returned.

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

Checks whether the property corresponding to **propName** in [AppStorage](../../../ui/state-management/arkts-appstorage.md) is mutable.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 10.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description            |
| -------- | ------ | ---- | ---------------- |
| propName | string | Yes   | Property name in AppStorage.|

**Return value**

| Type     | Description                              |
| ------- | -------------------------------- |
| boolean | Whether the property corresponding to **propName** is mutable.|

**Example**
```ts
AppStorage.SetOrCreate('PropA', 47);
let res: boolean = AppStorage.IsMutable('simpleProp');
```


### Size<sup>(deprecated)</sup>

static Size(): number

Obtains the number of properties in [AppStorage](../../../ui/state-management/arkts-appstorage.md).

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 10. You are advised to use [size10+](#size10) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description                 |
| ------ | ------------------- |
| number | Number of properties in AppStorage.|

**Example**
```ts
AppStorage.SetOrCreate('PropB', 48);
let res: number = AppStorage.Size(); // 1
```


## LocalStorage<sup>9+</sup>


For details about how to use LocalStorage on the UI, see [LocalStorage: UI State Storage](../../../ui/state-management/arkts-localstorage.md).

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### constructor<sup>9+</sup>

constructor(initializingProperties?: Object)

Creates a [LocalStorage](../../../ui/state-management/arkts-localstorage.md) instance and initializes it using the properties and values returned by **Object.keys(initializingProperties)**.

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name                   | Type    | Mandatory  | Description                                    |
| ---------------------- | ------ | ---- | ---------------------------------------- |
| initializingProperties | Object | No   | Properties and values used to initialize the **LocalStorage** instance. The value cannot be **undefined**.|

**Example**
```ts
let para: Record<string, number> = { 'PropA': 47 };
let storage: LocalStorage = new LocalStorage(para);
```


### getShared<sup>10+</sup>

static getShared(): LocalStorage

Obtains the [LocalStorage](../../../ui/state-management/arkts-localstorage.md) instance shared across the current stage.

**Widget capability**: This API can be used in ArkTS widgets since API version 10.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Model restriction**: This API can be used only in the stage model.

**Return value**

| Type                            | Description               |
| ------------------------------ | ----------------- |
| [LocalStorage](#localstorage9) | **LocalStorage** instance.|

**Example**
For details about how to use the **getShared** API, see [Example of Sharing a LocalStorage Instance from UIAbility to One or More Pages](../../../ui/state-management/arkts-localstorage.md#example-of-sharing-a-localstorage-instance-from-uiability-to-one-or-more-pages).


### has<sup>9+</sup>

has(propName: string): boolean

Checks whether the property corresponding to **propName** exists in [LocalStorage](../../../ui/state-management/arkts-localstorage.md).

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description              |
| -------- | ------ | ---- | ------------------ |
| propName | string | Yes   | Property name in LocalStorage.|

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **true** if the property exists in LocalStorage; returns **false** otherwise.|

**Example**
```ts
let para: Record<string, number> = { 'PropA': 47 };
let storage: LocalStorage = new LocalStorage(para);
storage.has('PropA'); // true
```


### get<sup>9+</sup>

get&lt;T&gt;(propName: string): T | undefined

Obtains the value of the property corresponding to **propName** from [LocalStorage](../../../ui/state-management/arkts-localstorage.md).

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description              |
| -------- | ------ | ---- | ------------------ |
| propName | string | Yes   | Property name in LocalStorage.|

**Return value**

| Type                    | Description                                                        |
| ------------------------ | ------------------------------------------------------------ |
| T \| undefined | Value of the property corresponding to **propName** in LocalStorage, or **undefined** if it does not exist.|

**Example**
```ts
let para: Record<string, number> = { 'PropA': 47 };
let storage: LocalStorage = new LocalStorage(para);
let value: number = storage.get('PropA') as number; // 47
```


### set<sup>9+</sup>

set&lt;T&gt;(propName: string, newValue: T): boolean

Sets the value of the property corresponding to **propName** in [LocalStorage](../../../ui/state-management/arkts-localstorage.md). If the value of **newValue** is the same as the current value of the property, no assignment is performed, and the state variable does not instruct the UI to update the value of the property. Since API version 12, **newValue** can be **null** or **undefined**.

> **NOTE**
> 
> Since API version 12, LocalStorage supports [Map](../../../ui/state-management/arkts-localstorage.md#decorating-variables-of-the-map-type), [Set](../../../ui/state-management/arkts-localstorage.md#decorating-variables-of-the-set-type), [Date](../../../ui/state-management/arkts-localstorage.md#decorating-variables-of-the-date-type), **null**, **undefined**, and [union](../../../ui/state-management/arkts-localstorage.md#union-type) types.

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description                   |
| -------- | ------ | ---- | ----------------------- |
| propName | string | Yes   | Property name in LocalStorage.     |
| newValue | T      | Yes   | Property value. Since API version 12, the value can be **null** or **undefined**.|

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **true** if the operation is successful; returns **false** if the property corresponding to **propName** does not exist in LocalStorage.  |

**Example**

```ts
let para: Record<string, number> = { 'PropA': 47 };
let storage: LocalStorage = new LocalStorage(para);
let res: boolean = storage.set('PropA', 47); // true
let res1: boolean = storage.set('PropB', 47); // false
```


### setOrCreate<sup>9+</sup>

setOrCreate&lt;T&gt;(propName: string, newValue: T): boolean

Sets the value of the property corresponding to **propName** in [LocalStorage](../../../ui/state-management/arkts-localstorage.md) to a new value, if the property exists and the new value is different from the current value. If the new value is the same as the current value of the property, no assignment is performed, and the state variable does not instruct the UI to update the value of the property.
If the property does not exist, this API creates it with the value of **newValue**. This **setOrCreate** method creates only one LocalStorage key-value pair. To create multiple key-value pairs, call this method multiple times. Since API version 12, **newValue** can be **null** or **undefined**.

> **NOTE**
> 
> Since API version 12, LocalStorage supports [Map](../../../ui/state-management/arkts-localstorage.md#decorating-variables-of-the-map-type), [Set](../../../ui/state-management/arkts-localstorage.md#decorating-variables-of-the-set-type), [Date](../../../ui/state-management/arkts-localstorage.md#decorating-variables-of-the-date-type), **null**, **undefined**, and [union](../../../ui/state-management/arkts-localstorage.md#union-type) types.

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description                   |
| -------- | ------ | ---- | ----------------------- |
| propName | string | Yes   | Property name in LocalStorage.     |
| newValue | T      | Yes   | Property value. Since API version 12, the value can be **null** or **undefined**.|

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **true** if the property corresponding to **propName** exists and its value is updated to the value of **newValue**,<br>or if **propName** is created with the value of **newValue**.|

**Example**

```ts
let para: Record<string, number> = { 'PropA': 47 };
let storage: LocalStorage = new LocalStorage(para);
let res: boolean = storage.setOrCreate('PropA', 121); // true
let res1: boolean = storage.setOrCreate('PropB', 111); // true
let res2: boolean = storage.setOrCreate('PropB', null); // true (API version 12 and later) or false (API version 11 and earlier)
```

### ref<sup>12+</sup>

public ref\<T\>(propName: string): AbstractProperty\<T\> | undefined

Returns a reference to the data corresponding to **propName** in [LocalStorage](../../../ui/state-management/arkts-localstorage.md). If the provided **propName** does not exist, this API returns **undefined**.

This API is similar to [link](#link9) but does not require manually releasing the returned variable of the [AbstractProperty](#abstractproperty) type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type  | Mandatory| Description                |
| -------- | ------ | ---- | ------------------------ |
| propName | string | Yes  | Property name in LocalStorage.|

**Return value**

| Type                                  | Description                                                        |
| -------------------------------------- | ------------------------------------------------------------ |
| [AbstractProperty&lt;T&gt;](#abstractproperty) \| undefined | A reference to the property in LocalStorage, or **undefined** if the property does not exist.|

**Example**

```ts
let para: Record<string, number> = { 'PropA': 47 };
let storage: LocalStorage = new LocalStorage(para);
let refToPropA1: AbstractProperty<number> | undefined = storage.ref('PropA');
let refToPropA2: AbstractProperty<number> | undefined = storage.ref('PropA'); // refToPropA2.get() == 47
refToPropA1?.set(48); // refToPropA1.get() == refToPropA2.get() == 48
```

### setAndRef<sup>12+</sup>

public setAndRef&lt;T&gt;(propName: string, defaultValue: T): AbstractProperty&lt;T&gt;

Similar to the [ref](#ref12-1) API, returns a reference to the data corresponding to **propName** in [LocalStorage](../../../ui/state-management/arkts-localstorage.md). If **propName** does not exist, this API creates and initializes the property in LocalStorage using **defaultValue** and returns its reference. **defaultValue** must be of the **T** type and can be **null** or **undefined**.

This API is similar to [setAndLink](#setandlink9) but does not require manually releasing the returned variable of the [AbstractProperty](#abstractproperty) type.

> **NOTE**
>
> Since API version 12, LocalStorage supports [Map](../../../ui/state-management/arkts-localstorage.md#decorating-variables-of-the-map-type), [Set](../../../ui/state-management/arkts-localstorage.md#decorating-variables-of-the-set-type), [Date](../../../ui/state-management/arkts-localstorage.md#decorating-variables-of-the-date-type), **null**, **undefined**, and [union](../../../ui/state-management/arkts-localstorage.md#union-type) types.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name      | Type  | Mandatory| Description                                                    |
| ------------ | ------ | ---- | ------------------------------------------------------------ |
| propName     | string | Yes  | Property name in LocalStorage.                                    |
| defaultValue | T      | Yes  | Default value used to initialize **propName** in LocalStorage if it does not exist. The value can be **null** or **undefined**.|

**Return value**

| Type                     | Description                                                        |
| ------------------------- | ------------------------------------------------------------ |
| [AbstractProperty&lt;T&gt;](#abstractproperty) | Instance of **AbstractProperty&lt;T&gt;**, which is a reference to the property in LocalStorage corresponding to **propName**.|

**Example**

```ts
let para: Record<string, number> = { 'PropA': 47 };
let storage: LocalStorage = new LocalStorage(para);
let ref1: AbstractProperty<number> = storage.setAndRef('PropB', 49); // Create PropB 49
let ref2: AbstractProperty<number> = storage.setAndRef('PropA', 50); // PropA exists, remains 47
```

### link<sup>9+</sup>

link&lt;T&gt;(propName: string): SubscribedAbstractProperty&lt;T&gt;

Establishes a two-way data binding with the property corresponding to **propName** in [LocalStorage](../../../ui/state-management/arkts-localstorage.md). If the given property exists in LocalStorage, this API returns the two-way bound data for the property.

Any update of the data is synchronized back to LocalStorage, which then synchronizes the update to all data and custom components bound to the property.

If the given property does not exist in LocalStorage, **undefined** is returned.

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description              |
| -------- | ------ | ---- | ------------------ |
| propName | string | Yes   | Property name in LocalStorage.|

**Return value**

| Type                               | Description                                                        |
| ----------------------------------- | ------------------------------------------------------------ |
| [SubscribedAbstractProperty&lt;T&gt;](#subscribedabstractproperty) | Returns the **SubscribedAbstractProperty&lt;T&gt;** instance if the given property exists in LocalStorage; returns undefined otherwise.|

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

Similar to the [link](#link9) API, establishes a two-way data binding with the property corresponding to **propName** in [LocalStorage](../../../ui/state-management/arkts-localstorage.md). If the given property exists in LocalStorage, this API returns the two-way bound data for the property. If the given property does not exist, this API creates and initializes the property in LocalStorage using **defaultValue** and returns its two-way bound data. The value of **defaultValue** must be of the **T** type. Since API version 12, it can be **null** or **undefined**.

> **NOTE**
> 
> Since API version 12, LocalStorage supports [Map](../../../ui/state-management/arkts-localstorage.md#decorating-variables-of-the-map-type), [Set](../../../ui/state-management/arkts-localstorage.md#decorating-variables-of-the-set-type), [Date](../../../ui/state-management/arkts-localstorage.md#decorating-variables-of-the-date-type), **null**, **undefined**, and [union](../../../ui/state-management/arkts-localstorage.md#union-type) types.

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name      | Type  | Mandatory| Description                                                    |
| ------------ | ------ | ---- | ------------------------------------------------------------ |
| propName     | string | Yes  | Property name in LocalStorage.                                    |
| defaultValue | T      | Yes  | Default value used to initialize **propName** in LocalStorage if it does not exist. Since API version 12, **defaultValue** can be **null** or **undefined**.|

**Return value**

| Type                               | Description                                                        |
| ----------------------------------- | ------------------------------------------------------------ |
| [SubscribedAbstractProperty&lt;T&gt;](#subscribedabstractproperty) | Instance of **SubscribedAbstractProperty&lt;T&gt;** and two-way bound data of the given property in LocalStorage.|

**Example**
```ts
let para: Record<string, number> = { 'PropA': 47 };
let storage: LocalStorage = new LocalStorage(para);
let link1: SubscribedAbstractProperty<number> = storage.setAndLink('PropB', 49); // Create PropB 49
let link2: SubscribedAbstractProperty<number> = storage.setAndLink('PropA', 50); // PropA exists, remains 47
```


### prop<sup>9+</sup>

prop&lt;S&gt;(propName: string): SubscribedAbstractProperty&lt;S&gt;

Establishes a one-way data binding with the property corresponding to **propName** in [LocalStorage](../../../ui/state-management/arkts-localstorage.md). If the given property exists in LocalStorage, this API returns the two-way bound data for the property. If the given property does not exist in LocalStorage, **undefined** is returned. Updates of the one-way bound data are not synchronized back to LocalStorage.

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description              |
| -------- | ------ | ---- | ------------------ |
| propName | string | Yes   | Property name in LocalStorage.|

**Return value**

| Type                               | Description                                                        |
| ----------------------------------- | ------------------------------------------------------------ |
| [SubscribedAbstractProperty&lt;S&gt;](#subscribedabstractproperty) | Instance of **SubscribedAbstractProperty&lt;S&gt;** and one-way bound data of the given property in LocalStorage, or **undefined** if the provided **propName** does not exist in LocalStorage.|

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

Similar to the [prop](#prop9) API, establishes a one-way data binding with the property corresponding to **propName** in [LocalStorage](../../../ui/state-management/arkts-localstorage.md). If the given property exists in LocalStorage, this API returns the one-way bound data for the property. If the given property does not exist, this API creates and initializes the property in LocalStorage using **defaultValue** and returns its one-way bound data. The value of **defaultValue** must be of the **S** type. Since API version 12, it can be **null** or **undefined**.

> **NOTE**
> 
> Since API version 12, LocalStorage supports [Map](../../../ui/state-management/arkts-localstorage.md#decorating-variables-of-the-map-type), [Set](../../../ui/state-management/arkts-localstorage.md#decorating-variables-of-the-set-type), [Date](../../../ui/state-management/arkts-localstorage.md#decorating-variables-of-the-date-type), **null**, **undefined**, and [union](../../../ui/state-management/arkts-localstorage.md#union-type) types.

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name      | Type  | Mandatory| Description                                                    |
| ------------ | ------ | ---- | ------------------------------------------------------------ |
| propName     | string | Yes  | Property name in LocalStorage.                                    |
| defaultValue | S      | Yes  | Default value used to initialize **propName** in LocalStorage if it does not exist. Since API version 12, **defaultValue** can be **null** or **undefined**.|

**Return value**

| Type                               | Description                                                        |
| ----------------------------------- | ------------------------------------------------------------ |
| [SubscribedAbstractProperty&lt;S&gt;](#subscribedabstractproperty) | Instance of **SubscribedAbstractProperty&lt;S&gt;** and one-way bound data of the given property in LocalStorage.|

**Example**

```ts
let para: Record<string, number> = { 'PropA': 47 };
let storage: LocalStorage = new LocalStorage(para);
let prop: SubscribedAbstractProperty<number> = storage.setAndProp('PropB', 49); // PropA -> 47, PropB -> 49
```


### delete<sup>9+</sup>

delete(propName: string): boolean

Deletes the property corresponding to **propName** from [LocalStorage](../../../ui/state-management/arkts-localstorage.md). The deletion is only successful if the property has no subscribers. If there is a subscriber, the deletion fails and **false** is returned. If the deletion is successful, **true** is returned.

The property subscribers include the following:

1. Variables decorated by [\@LocalStorageLink](../../../ui/state-management/arkts-localstorage.md#localstoragelink) or [\@LocalStorageProp](../../../ui/state-management/arkts-localstorage.md#localstorageprop)

2. Instances of [SubscribedAbstractProperty](#subscribedabstractproperty) returned by [link](#link9), [prop](#prop9), [setAndLink](#setandlink9), or [setAndProp](#setandprop9)

To delete these subscribers:

1. Remove the custom component containing \@LocalStorageLink or \@LocalStorageProp. For details, see [Custom Component Deletion](../../../ui/state-management/arkts-page-custom-components-lifecycle.md#custom-component-deletion).

2. Call the [aboutToBeDeleted](#abouttobedeleted10) API on instances of **SubscribedAbstractProperty** returned by **link**, **prop**, **setAndLink**, or **setAndProp**.

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description              |
| -------- | ------ | ---- | ------------------ |
| propName | string | Yes   | Property name in LocalStorage.|

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

Obtains all property names in [LocalStorage](../../../ui/state-management/arkts-localstorage.md).

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                            | Description                  |
| ------------------------------ | -------------------- |
| IterableIterator&lt;string&gt; | All property names in LocalStorage.|

**Example**
```ts
let para: Record<string, number> = { 'PropA': 47 };
let storage: LocalStorage = new LocalStorage(para);
let keys: IterableIterator<string> = storage.keys();
```


### size<sup>9+</sup>

size(): number

Obtains the number of properties in [LocalStorage](../../../ui/state-management/arkts-localstorage.md).

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type  | Description                        |
| ------ | ---------------------------- |
| number | Number of properties in LocalStorage.|

**Example**
```ts
let para: Record<string, number> = { 'PropA': 47 };
let storage: LocalStorage = new LocalStorage(para);
let res: number = storage.size(); // 1
```


### clear<sup>9+</sup>

clear(): boolean

Deletes all properties from [LocalStorage](../../../ui/state-management/arkts-localstorage.md). The deletion is only successful if none of the properties in LocalStorage have any subscribers. If there are subscribers, this API does not take effect and **false** is returned. If the deletion is successful, **true** is returned.

For details about the subscriber, see [delete](#delete9).

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

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

Obtains the [LocalStorage](../../../ui/state-management/arkts-localstorage.md) instance shared across the current stage.

> **NOTE**
> 
> This API is deprecated since API version 10. You are advised to use [getShared10+](#getshared10) instead.

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

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

## AbstractProperty

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### get<sup>12+</sup>

get(): T

Obtains data of the referenced property from [AppStorage](../../../ui/state-management/arkts-appstorage.md) or [LocalStorage](../../../ui/state-management/arkts-localstorage.md).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type| Description                                       |
| ---- | ------------------------------------------- |
| T    | Data of the referenced property in AppStorage or LocalStorage.|

**Example**

```ts
AppStorage.setOrCreate('PropA', 47);
let ref1: AbstractProperty<number> | undefined = AppStorage.ref('PropA');
ref1?.get(); //  ref1.get()=47
```


### set<sup>12+</sup>

set(newValue: T): void

Updates the data of the referenced property in [AppStorage](../../../ui/state-management/arkts-appstorage.md) or [LocalStorage](../../../ui/state-management/arkts-localstorage.md). The value of **newValue** must be of the **T** type and can be **null** or **undefined**.

> **NOTE**
>
> Since API version 12, AppStorage and LocalStorage support the Map, Set, Date types, as well as **null**, **undefined**, and union types.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full


**Parameters**


| Name  | Type| Mandatory| Description                             |
| -------- | ---- | ---- | ------------------------------------- |
| newValue | T    | Yes  | New data to update. The value can be **null** or **undefined**.|


**Example**

```ts
AppStorage.setOrCreate('PropA', 47);
let ref1: AbstractProperty<number> | undefined = AppStorage.ref('PropA');
ref1?.set(1); //  ref1.get()=1
let a: Map<string, number> = new Map([['1', 0]]);
let ref2 = AppStorage.setAndRef('MapA', a);
ref2.set(a);
let b: Set<string> = new Set('1');
let ref3 = AppStorage.setAndRef('SetB', b);
ref3.set(b);
let c: Date = new Date('2024');
let ref4 = AppStorage.setAndRef('DateC', c);
ref4.set(c);
ref2.set(null);
ref3.set(undefined);
```

### info<sup>12+</sup>

info(): string

Reads the property name of the referenced property in [AppStorage](../../../ui/state-management/arkts-appstorage.md) or [LocalStorage](../../../ui/state-management/arkts-localstorage.md).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type  | Description                                         |
| ------ | --------------------------------------------- |
| string | Property name of the referenced property in AppStorage or LocalStorage.|

**Example**

```ts
AppStorage.setOrCreate('PropA', 47);
let ref1: AbstractProperty<number> | undefined = AppStorage.ref('PropA');
ref1?.info(); //  ref1.info()='PropA'
```

## SubscribedAbstractProperty

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### get<sup>9+</sup>

abstract get(): T

Reads the data of the synchronized property from [AppStorage](../../../ui/state-management/arkts-appstorage.md) or [LocalStorage](../../../ui/state-management/arkts-localstorage.md).

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type  | Description                             |
| ---- | ------------------------------- |
| T    | Data of the synchronized property in AppStorage or LocalStorage.|

**Example**
```ts
AppStorage.setOrCreate('PropA', 47); 
let prop1: SubscribedAbstractProperty<number> = AppStorage.prop('PropA');    
prop1.get(); //  prop1.get()=47
```


### set<sup>9+</sup>

abstract set(newValue: T): void

Sets the data of the synchronized property in [AppStorage](../../../ui/state-management/arkts-appstorage.md) or [LocalStorage](../../../ui/state-management/arkts-localstorage.md). The value of **newValue** must be of the **T** type. Since API version 12, it can be **null** or **undefined**.

> **NOTE**
> 
>Since API version 12, AppStorage and LocalStorage support the Map, Set, Date types, as well as **null**, **undefined**, and union types.

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full


**Parameters**


| Name  | Type| Mandatory| Description                                                 |
| -------- | ---- | ---- | --------------------------------------------------------- |
| newValue | T    | Yes  | Data to set. Since API version 12, the value can be **null** or **undefined**.|


**Example**
```ts
AppStorage.setOrCreate('PropA', 47);
let prop1: SubscribedAbstractProperty<number> = AppStorage.prop('PropA');
prop1.set(1); //  prop1.get()=1
// Since API version 12, the Map, Set, Date types, as well as null, undefined, and union types are supported.
let a: Map<string, number> = new Map([['1', 0]]);
let prop2 = AppStorage.setAndProp('MapA', a);
prop2.set(a);
let b: Set<string> = new Set('1');
let prop3 = AppStorage.setAndProp('SetB', b);
prop3.set(b);
let c: Date = new Date('2024');
let prop4 = AppStorage.setAndProp('DateC', c);
prop4.set(c);
prop2.set(null);
prop3.set(undefined);
```

### aboutToBeDeleted<sup>10+</sup>

abstract aboutToBeDeleted(): void

Cancels the synchronization relationship between the [SubscribedAbstractProperty](#subscribedabstractproperty) instance and [AppStorage](../../../ui/state-management/arkts-appstorage.md) or [LocalStorage](../../../ui/state-management/arkts-localstorage.md), whether it is a one-way or two-way binding. After **aboutToBeDeleted** is called, the **SubscribedAbstractProperty** instance is invalidated, meaning it can no longer be used to call the [set](#set9-1) or [get](#get9-1) API.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**
```ts
AppStorage.setOrCreate('PropA', 47);
let link = AppStorage.setAndLink('PropB', 49); // PropA -> 47, PropB -> 49
link.aboutToBeDeleted();
```

### info

info(): string;

Property name.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

|Type  |Description    |
|---------|-------------|
|string    |Property name.   |


## PersistentStorage

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

For details about how to use PersistentStorage on the UI, see [PersistentStorage: Persisting Application State](../../../ui/state-management/arkts-persiststorage.md).

> **NOTE**
>
> Since API version 12, PersistentStorage supports **null** and **undefined**.

### PersistPropsOptions

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name      | Type                                 | Mandatory| Description                                                    |
| ------------ | ------------------------------------- | ---- | ------------------------------------------------------------ |
| key          | string                                | Yes  | Property name.                                                    |
| defaultValue | number \| string \| boolean \| Object | Yes  | Default value used to initialize the property when it does not exist in PersistentStorage and AppStorage. Since API version 12, **defaultValue** can be **null** or **undefined**.|


### persistProp<sup>10+</sup>

static persistProp&lt;T&gt;(key: string, defaultValue: T): void

Persists the property corresponding to **key** from [AppStorage](../../../ui/state-management/arkts-appstorage.md) to a file. This API is usually called before access to AppStorage.

The order for determining the type and value of a property is as follows:

1. If the property with the specified key is found in the [PersistentStorage](../../../ui/state-management/arkts-persiststorage.md) file, the corresponding property is created in AppStorage and initialized with the value found in PersistentStorage.

2. If the property with the specified key is not found in the PersistentStorage file, AppStorage is searched for the property. If the property is found, it is persisted.

3. If no matching property is found in AppStorage, it is created in AppStorage, initialized with the value of **defaultValue**, and persisted.

According to the preceding initialization process, if the property exists in AppStorage, its value will be used, overriding the value in the PersistentStorage file. Because AppStorage stores data in the memory, the property value becomes nonpersistent.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name      | Type  | Mandatory| Description                                                    |
| ------------ | ------ | ---- | ------------------------------------------------------------ |
| key          | string | Yes  | Property name.                                                    |
| defaultValue | T      | Yes  | Default value used for initialization if the specified **key** is not found in PersistentStorage and AppStorage. Since API version 12, the value can be **null** or **undefined**.|


**Example**


For details about how to use persistProp, see [Accessing PersistentStorage Initialized Attribute from AppStorage](../../../ui/state-management/arkts-persiststorage.md#accessing-persistentstorage-initialized-attribute-from-appstorage).


### deleteProp<sup>10+</sup>

static deleteProp(key: string): void

Performs the reverse operation of [persistProp](#persistprop10). Specifically, this API deletes the property corresponding to the specified **key** from [PersistentStorage](../../../ui/state-management/arkts-persiststorage.md). Subsequent operations on [AppStorage](../../../ui/state-management/arkts-appstorage.md) do not affect data in PersistentStorage. This operation removes the corresponding key from the persistence file. To persist the property again, you can call the [persistProp](#persistprop10) API.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type    | Mandatory  | Description                   |
| ---- | ------ | ---- | ----------------------- |
| key  | string | Yes   | Property name in PersistentStorage.|

**Example**
```ts
PersistentStorage.deleteProp('highScore');
```


### persistProps<sup>10+</sup>

static persistProps(props: PersistPropsOptions[]): void

Persists multiple properties. This API is similar to [persistProp](#persistprop10), but allows multiple properties to be persisted at once, making it suitable for initializing during application startup.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name       | Type                                      | Mandatory  | Description                                    |
| ---------- | ---------------------------------------- | ---- | ---------------------------------------- |
| props | [PersistPropsOptions](#persistpropsoptions)[] | Yes| Array of properties to persist.|

**Example**
```ts
PersistentStorage.persistProps([{ key: 'highScore', defaultValue: '0' }, { key: 'wightScore', defaultValue: '1' }]);
```


### keys<sup>10+</sup>

static keys(): Array&lt;string&gt;

Returns an array of all persisted property names.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type               | Description                              |
| ------------------- | ---------------------------------- |
| Array&lt;string&gt; | Array of all persisted property names.|

**Example**
```ts
let keys: Array<string> = PersistentStorage.keys();
```


### PersistProp<sup>(deprecated)</sup>

static PersistProp&lt;T&gt;(key: string, defaultValue: T): void

Persists the property corresponding to **key** from [AppStorage](../../../ui/state-management/arkts-appstorage.md) to a file. This API is usually called before access to AppStorage.

The order for determining the type and value of a property is as follows:

1. If the property with the specified key is found in the [PersistentStorage](../../../ui/state-management/arkts-persiststorage.md) file, the corresponding property is created in AppStorage and initialized with the value found in PersistentStorage.

2. If the property with the specified key is not found in the PersistentStorage file, AppStorage is searched for the property. If the property is found, it is persisted.

3. If no matching property is found in AppStorage, it is created in AppStorage, initialized with the value of **defaultValue**, and persisted.

According to the preceding initialization process, if the property exists in AppStorage, its value will be used, overriding the value in the PersistentStorage file. Because AppStorage stores data in the memory, the property value becomes nonpersistent.


> **NOTE**
>
> This API is deprecated since API version 10. You are advised to use [persistProp10+](#persistprop10) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name      | Type  | Mandatory| Description                                                    |
| ------------ | ------ | ---- | ------------------------------------------------------------ |
| key          | string | Yes  | Property name.                                                    |
| defaultValue | T      | Yes  | Default value used for initialization if the specified **key** is not found in PersistentStorage and AppStorage. The value cannot be **null** or **undefined**.|


**Example**


```ts
PersistentStorage.PersistProp('highScore', '0');
```


### DeleteProp<sup>(deprecated)</sup>

static DeleteProp(key: string): void

Performs the reverse operation of [PersistProp](#persistpropdeprecated). Specifically, this API deletes the property corresponding to the specified key from [PersistentStorage](../../../ui/state-management/arkts-persiststorage.md). Subsequent operations on [AppStorage](../../../ui/state-management/arkts-appstorage.md) do not affect data in PersistentStorage.


> **NOTE**
>
> This API is deprecated since API version 10. You are advised to use [deleteProp10+](#deleteprop10) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type    | Mandatory  | Description                   |
| ---- | ------ | ---- | ----------------------- |
| key  | string | Yes   | Property name in PersistentStorage.|

**Example**
```ts
PersistentStorage.DeleteProp('highScore');
```


### PersistProps<sup>(deprecated)</sup>

static PersistProps(properties: {key: string, defaultValue: any;}[]): void

Persists multiple properties. This API is similar to [PersistProp](#persistpropdeprecated), but allows multiple properties to be persisted at once, making it suitable for initializing during application startup.

> **NOTE**
>
> This API is deprecated since API version 10. You are advised to use [persistProps10+](#persistprops10) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                              | Mandatory| Description                                                    |
| ---------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| properties | {key: string, defaultValue: any}[] | Yes  | Array of properties to persist.<br>**key**: property name.<br>**defaultValue**: default value. The rules are the same as those of **PersistProp**.|

**Example**

```ts
PersistentStorage.PersistProps([{ key: 'highScore', defaultValue: '0' }, { key: 'wightScore', defaultValue: '1' }]);
```


### Keys<sup>(deprecated)</sup>

static Keys(): Array&lt;string&gt;

Returns an array of all persisted property names.

> **NOTE**
>
> This API is deprecated since API version 10. You are advised to use [keys10+](#keys10-1) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type               | Description                              |
| ------------------- | ---------------------------------- |
| Array&lt;string&gt; | Array of all persisted property names.|

**Example**
```ts
let keys: Array<string> = PersistentStorage.Keys();
```


## Environment

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

For details about how to use environment parameters, see [Environment: Device Environment Query](../../../ui/state-management/arkts-environment.md).

### EnvPropsOptions

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name      | Type                       | Mandatory| Description                                                    |
| ------------ | --------------------------- | ---- | ------------------------------------------------------------ |
| key          | string                      | Yes  | Environment variable name. For details about the value range, see [Built-in Environment Variables](#built-in-environment-variables).|
| defaultValue | number \| string \| boolean | Yes  | Default value used if the value of the specified environment variable key is not found in AppStorage.|


### envProp<sup>10+</sup>

static envProp&lt;S&gt;(key: string, value: S): boolean

Stores the built-in environment variable key from [Environment](../../../ui/state-management/arkts-environment.md) into [AppStorage](../../../ui/state-management/arkts-appstorage.md). If the value of the environment variable key is not found in AppStorage, the default value is used and stored in AppStorage. If the value is successfully stored, **true** is returned. If the value of the environment variable key already exists in AppStorage, **false** is returned.

You are advised to call this API when the application is started.

It is incorrect to use AppStorage to read environment variables without calling **envProp** first.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                                    |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| key    | string | Yes  | Environment variable name. For details about the value range, see [Built-in Environment Variables](#built-in-environment-variables).|
| value  | S      | Yes  | Default value used if the value of the environment variable key is not found in AppStorage.|

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **false** if the property corresponding to the key exists in AppStorage; creates a property with the key and the default value and returns **true** otherwise.|

**Example**


For details about how to use **envProp**, see [Accessing Environment Parameters from UI](../../../ui/state-management/arkts-environment.md#accessing-environment-parameters-from-ui).


### envProps<sup>10+</sup>

static envProps(props: EnvPropsOptions[]): void

Works in a way similar to the [envProp](#envprop10) API, with the difference that it allows for initialization of multiple properties in batches. It is recommended that this API be called during application startup to store system environment variables to [AppStorage](../../../ui/state-management/arkts-appstorage.md) in batches.

**Atomic service API**: This API can be used in atomic services since API version 11.

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

Returns an array of keys of environment variables.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                 | Description         |
| ------------------- | ----------- |
| Array&lt;string&gt; | Array of associated system properties.|

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

Stores the built-in environment variable key from [Environment](../../../ui/state-management/arkts-environment.md) into [AppStorage](../../../ui/state-management/arkts-appstorage.md). If the value of the environment variable key is not found in AppStorage, the default value is used and stored in AppStorage. If the value is successfully stored, **true** is returned. If the value of the environment variable key already exists in AppStorage, **false** is returned.

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
| boolean | Returns **false** if the property corresponding to the key exists in AppStorage; creates a property with the key and the default value and returns **true** otherwise.|

**Example**


```ts
Environment.EnvProp('accessibilityEnabled', 'default');
```


### EnvProps<sup>(deprecated)</sup>

static EnvProps(props: {key: string; defaultValue: any;}[]): void

Works in a way similar to the [EnvProp](#envpropdeprecated) API, with the difference that it allows for initialization of multiple properties in batches. It is recommended that this API be called during application startup to store system environment variables to [AppStorage](../../../ui/state-management/arkts-appstorage.md) in batches.

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
| Array&lt;string&gt; | Array of associated system properties.|

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
| layoutDirection      | LayoutDirection | Layout direction. The options are as follows:<br>- **LayoutDirection.LTR**: from left to right.<br>- **LayoutDirection.RTL**: from right to left.<br>- **Auto**: follows the system settings.|
| languageCode         | string          | Current system language. The value is in lowercase, for example, **zh**.                            |
