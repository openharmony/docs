# ArkUI Subsystem LocalStorage Class ChangeLog 

## cl.LocalStorage.1 Return Type Change of the get API

Changed the return type from **get\<T>(propName: string): T** to **get\<T>(propName: string): T | undefined**.

**Change Impact**


None

## cl.LocalStorage.2 Mandatory/Optional Change of the newValue Parameter in setOrCreate
**Change Impact**

API declaration before change:
```js
setOrCreate<T>(propName: string, newValue?: T): boolean
```
API declaration after change:
```js
setOrCreate<T>(propName: string, newValue: T): boolean
```
The **newValue** parameter becomes mandatory.
If it is not specified when an application calls the API, the build will fail after the SDK is replaced.

**Adaptation Guide**

```js
let storage = new LocalStorage();
storage.setOrCreate('propA', 'hello');
```
## cl.LocalStorage.3 link Parameter and Return Type Changes
**Change Impact**

API declaration before change:
```js
link<T>(propName: string, linkUser?: T, subscribersName?: string): T
```
API declaration after change:
```js
link<T>(propName: string): SubscribedAbstractProperty<T>
```
1. The second and third parameters of the **link** API are reserved for internal use by the framework. Therefore, the API is changed to contain only one parameter.
2. The return type **T** is changed to **SubscribedAbstractProperty**.

**Adaptation Guide**

```js
let storage = new LocalStorage({"PropA": "47"});
let linA = storage.link("PropA");
linA.set(50);
```

## cl.LocalStorage.4 setAndLink Parameter and Return Type Changes
**Change Impact**

API declaration before change:
```js
setAndLink<T>(propName: string, defaultValue: T, linkUser?: T, subscribersName?: string): T
```
API declaration after change:
```js
setAndLink<T>(propName: string, defaultValue: T): SubscribedAbstractProperty<T>
```
1. The third and fourth parameters of the **setAndLink** API are reserved for internal use by the framework. Therefore, the API is changed to contain two parameters.
2. The return type **T** is changed to **SubscribedAbstractProperty**.

**Adaptation Guide**

```js
let storage = new LocalStorage({"PropA": "47"});
let linA = storage.setAndLink("PropA", "48")
linA.set(50);
```

## cl.LocalStorage.5 prop Parameter and Return Type Changes
**Change Impact**

API declaration before change:
```js
prop<T>(propName: string, propUser?: T, subscribersName?: string): T
```
API declaration after change:
```js
prop<S>(propName: string): SubscribedAbstractProperty<S>
```
1. The second and third parameters of the **prop** API are reserved for internal use by the framework. Therefore, the API is changed to contain only one parameter.
2. The return type **T** is changed to **SubscribedAbstractProperty**.

**Adaptation Guide**

```js
let storage = new LocalStorage({"PropA": "47"});
let propA = storage.prop("PropA");
propA.set(51); // one-way sync
```

## cl.LocalStorage.6 setAndProp Parameter and Return Type Changes
**Change Impact**

API declaration before change:
```js
setAndProp<T>(propName: string, defaultValue: T, propUser?: T, subscribersName?: string): T
```
API declaration after change:
```js
setAndProp<S>(propName: string, defaultValue: S): SubscribedAbstractProperty<S>
```
1. The third and fourth parameters of the **setAndProp** API are reserved for internal use by the framework. Therefore, the API is changed to contain two parameters.
2. The return type **T** is changed to **SubscribedAbstractProperty**.

**Adaptation Guide**

```js
let storage = new LocalStorage({"PropA": "47"});
let propA = storage.setAndProp("PropA", "48");
propA.set(51); // one-way sync
```
