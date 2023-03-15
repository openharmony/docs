# ArkUI子系统LocalStorage类接口ChangeLog

## cl.LocalStorage.1 get接口返回类型变更

**变更影响**

返回类型从get<T>(propName: string): T变更为get<T>(propName: string): T | undefined
应用不需要进行适配。 

## cl.LocalStorage.2 setOrCreate参数newValue变成必选
**变更影响**

原接口声明：
```js
setOrCreate<T>(propName: string, newValue?: T): boolean
```
现接口声明：
```js
setOrCreate<T>(propName: string, newValue: T): boolean
```
第二个参数newValue变为必选。
如果应用调用这个接口没有指定newValue参数，在替换新的sdk后会编译不过，需要手动指定newValue。

**适配指导**

```js
let storage = new LocalStorage();
storage.setOrCreate('propA', 'hello');
```
## cl.LocalStorage.3 link参数和返回类型变更
**变更影响**

原接口声明：
```js
link<T>(propName: string, linkUser?: T, subscribersName?: string): T
```
现接口声明：
```js
link<T>(propName: string): SubscribedAbstractProperty<T>
```
1. link第二三个参数为框架内部调用，不应对外开发，所以将接口变更为一个参数；
2. 返回类型T变更为SubscribedAbstractProperty；

**适配指导**

```js
let storage = new LocalStorage({"PropA": "47"});
let linA = storage.link("PropA");
linA.set(50);
```

## cl.LocalStorage.4 setAndLink参数和返回类型变更
**变更影响**

原接口声明：
```js
setAndLink<T>(propName: string, defaultValue: T, linkUser?: T, subscribersName?: string): T
```
现接口声明：
```js
setAndLink<T>(propName: string, defaultValue: T): SubscribedAbstractProperty<T>
```
1. setAndLink第三四个参数为框架内部调用，不应对外开发，所以将接口变更为2个参数；
2. 返回类型T变更为SubscribedAbstractProperty；

**适配指导**

```js
let storage = new LocalStorage({"PropA": "47"});
let linA = storage.setAndLink("PropA", "48")
linA.set(50);
```

## cl.LocalStorage.5 prop参数和返回类型变更
**变更影响**

原接口声明：
```js
prop<T>(propName: string, propUser?: T, subscribersName?: string): T
```
现接口声明：
```js
prop<S>(propName: string): SubscribedAbstractProperty<S>
```
1. prop第二三个参数为框架内部调用，不应对外开发，所以将接口变更为1个参数；
2. 返回类型T变更为SubscribedAbstractProperty；

**适配指导**

```js
let storage = new LocalStorage({"PropA": "47"});
let propA = storage.prop("PropA");
propA.set(51); // one-way sync
```

## cl.LocalStorage.6 setAndProp参数和返回类型变更
**变更影响**

原接口声明：
```js
setAndProp<T>(propName: string, defaultValue: T, propUser?: T, subscribersName?: string): T
```
现接口声明：
```js
setAndProp<S>(propName: string, defaultValue: S): SubscribedAbstractProperty<S>
```
1. setAndProp第三四个参数为框架内部调用，不应对外开发，所以将接口变更为2个参数；
2. 返回类型T变更为SubscribedAbstractProperty；

**适配指导**

```js
let storage = new LocalStorage({"PropA": "47"});
let propA = storage.setAndProp("PropA", "48");
propA.set(51); // one-way sync
```