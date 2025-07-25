# 状态管理

ArkTS1.1中已废弃，并在ArkTS1.2中不再支持以下接口。

## AppStorage

### Clear

ArkTS1.1接口声明：[static Clear(): boolean](../reference/apis-arkui/arkui-ts/ts-state-management.md#cleardeprecated)

替代的ArkTS1.2接口声明：[static clear(): boolean](../reference/apis-arkui/arkui-ts/ts-state-management.md#clear10)

适配方法如下：

ArkTS1.1

```
let res: boolean = AppStorage.Clear();
```

ArkTS1.2

```
let res: boolean = AppStorage.clear();
```

### Delete

ArkTS1.1接口声明：[static Delete(propName: string): boolean](../reference/apis-arkui/arkui-ts/ts-state-management.md#deletedeprecated)

替代的ArkTS1.2接口声明：[static delete(propName: string): boolean](../reference/apis-arkui/arkui-ts/ts-state-management.md#delete10)

适配方法如下：

ArkTS1.1

```
let res: boolean = AppStorage.Delete('PropA');
```

ArkTS1.2

```
let res: boolean = AppStorage.delete('PropA');
```

### Get

ArkTS1.1接口声明：[static Get<T>(propName: string): T | undefined](../reference/apis-arkui/arkui-ts/ts-state-management.md#getdeprecated)

替代的ArkTS1.2接口声明：[static get<T>(propName: string): T | undefined](../reference/apis-arkui/arkui-ts/ts-state-management.md#get10)

适配方法如下：

ArkTS1.1

```ts
let value: number = AppStorage.Get('PropA') as number;
```

ArkTS1.2

```ts
let value: number = AppStorage.get<number>('PropA') as number;
```

### Has

ArkTS1.1接口声明：[static Has(propName: string): boolean](../reference/apis-arkui/arkui-ts/ts-state-management.md#hasdeprecated)

替代的ArkTS1.2接口声明：[static has(propName: string): boolean](../reference/apis-arkui/arkui-ts/ts-state-management.md#has10)

适配方法如下：

ArkTS1.1

```ts
AppStorage.Has('simpleProp');
```

ArkTS1.2

```ts
AppStorage.has('simpleProp');
```

### IsMutable

ArkTS1.1接口声明：[static IsMutable(propName: string): boolean](../reference/apis-arkui/arkui-ts/ts-state-management.md#ismutabledeprecated)，返回值恒为true。

ArkTS1.2未提供该接口。

适配方法如下：

ArkTS1.1

```ts
let mutable: boolean = AppStorage.IsMutable('simpleProp'); // 返回值恒为true
```

ArkTS1.2

```ts
let mutable: boolean = true;
```

### Keys

ArkTS1.1接口声明：[static Keys(): IterableIterator<string>](../reference/apis-arkui/arkui-ts/ts-state-management.md#keysdeprecated)

替代的ArkTS1.2接口声明：[static keys(): IterableIterator<string>](../reference/apis-arkui/arkui-ts/ts-state-management.md#keys10)

适配方法如下：

ArkTS1.1

```ts
let keys: IterableIterator<string> = AppStorage.Keys();
```

ArkTS1.2

```ts
let keys: IterableIterator<string> = AppStorage.keys();
```

### Link

ArkTS1.1接口声明：[static Link(propName: string): any](../reference/apis-arkui/arkui-ts/ts-state-management.md#linkdeprecated)

替代的ArkTS1.2接口声明：[static link<T>(propName: string): SubscribedAbstractProperty<T>](../reference/apis-arkui/arkui-ts/ts-state-management.md#link10)

适配方法如下：

ArkTS1.1

```ts
let linkToPropA1: SubscribedAbstractProperty<number> = AppStorage.Link('PropA');
```

ArkTS1.2

```ts
let linkToPropA1: SubscribedAbstractProperty<number> = AppStorage.link<number>('PropA');
```

### Set

ArkTS1.1接口声明：[static Set<T>(propName: string, newValue: T): boolean](../reference/apis-arkui/arkui-ts/ts-state-management.md#setdeprecated)

替代的ArkTS1.2接口声明：[static set<T>(propName: string, newValue: T): boolean](../reference/apis-arkui/arkui-ts/ts-state-management.md#set10)

适配方法如下：

ArkTS1.1

```ts
let res: boolean = AppStorage.Set('PropA', 47);
```

ArkTS1.2

```ts
let res: boolean = AppStorage.set('PropA', 47);
```

### SetAndLink

ArkTS1.1接口声明：[static SetAndLink<T>(propName: string, defaultValue: T): SubscribedAbstractProperty<T>](../reference/apis-arkui/arkui-ts/ts-state-management.md#setandlinkdeprecated)

替代的ArkTS1.2接口声明：[static setAndLink<T>(propName: string, defaultValue: T): SubscribedAbstractProperty<T>](../reference/apis-arkui/arkui-ts/ts-state-management.md#setandlink10)

适配方法如下：

ArkTS1.1

```ts
let link: SubscribedAbstractProperty<number> = AppStorage.SetAndLink('PropA', 49);
```

ArkTS1.2

```ts
let link: SubscribedAbstractProperty<Int> = AppStorage.setAndLink('PropA', 49);
```

### SetAndProp

ArkTS1.1接口声明：[static SetAndProp<T>(propName: string, defaultValue: T): SubscribedAbstractProperty<T>](../reference/apis-arkui/arkui-ts/ts-state-management.md#setandpropdeprecated)

ArkTS1.2未默认提供类的深拷贝能力，在无需使用深拷贝的场景，可以使用setAndRef替代。

替代的ArkTS1.2接口声明：[static setAndRef<T>(propName: string, defaultValue: T): SubscribedAbstractProperty<T>](../reference/apis-arkui/arkui-ts/ts-state-management.md#setandref12)

适配方法如下：

ArkTS1.1

```ts
let prop: SubscribedAbstractProperty<number> = AppStorage.SetAndProp('PropA', 49);
```

ArkTS1.2

```ts
let ref: AbstractProperty<Int> = AppStorage.setAndRef('PropA', 49);
```

### SetOrCreate

ArkTS1.1接口声明：[static SetOrCreate<T>(propName: string, newValue: T): void](../reference/apis-arkui/arkui-ts/ts-state-management.md#setorcreatedeprecated)

替代的ArkTS1.2接口声明：[static setOrCreate<T>(propName: string, newValue: T): void](../reference/apis-arkui/arkui-ts/ts-state-management.md#setorcreate10)

适配方法如下：

ArkTS1.1

```ts
AppStorage.SetOrCreate('simpleProp', 121);
```

ArkTS1.2

```ts
AppStorage.setOrCreate('simpleProp', 121);
```

### Prop

ArkTS1.1接口声明：[static Prop(propName: string): any](../reference/apis-arkui/arkui-ts/ts-state-management.md#propdeprecated)

ArkTS1.2未默认提供类的深拷贝能力，在无需使用深拷贝的场景，可以使用ref替代。

替代的ArkTS1.2接口声明：[static ref<T>(propName: string): AbstractProperty<T> | undefined](../reference/apis-arkui/arkui-ts/ts-state-management.md#ref12)

适配方法如下：

ArkTS1.1

```ts
let prop: SubscribedAbstractProperty<number> = AppStorage.Prop('PropA');
prop.set(48);
```

ArkTS1.2

```ts
let ref: AbstractProperty<number> | undefined = AppStorage.ref<number>('PropA');
ref?.set(48);
```

### Size

ArkTS1.1接口声明：[static Size(): number](../reference/apis-arkui/arkui-ts/ts-state-management.md#sizedeprecated)

替代的ArkTS1.2接口声明：[static size(): number](../reference/apis-arkui/arkui-ts/ts-state-management.md#size10)

适配方法如下：

ArkTS1.1

```ts
let res: number = AppStorage.Size();
```

ArkTS1.2

```ts
let res: number = AppStorage.size();
```

### staticClear

ArkTS1.1接口声明：[static staticClear(): boolean](../reference/apis-arkui/arkui-ts/ts-state-management.md#staticcleardeprecated)

替代的ArkTS1.2接口声明：[static clear(): boolean](../reference/apis-arkui/arkui-ts/ts-state-management.md#clear10)

适配方法如下：

ArkTS1.1

```ts
let res = AppStorage.staticClear();
```

ArkTS1.2

```ts
let res = AppStorage.clear();
```

## Environment

### EnvProp

ArkTS1.1接口声明：[static EnvProp<T>(key: string, value: T): boolean](../reference/apis-arkui/arkui-ts/ts-state-management.md#envpropdeprecated)

替代的ArkTS1.2接口声明：[static envProp<T>(key: string, value: T): boolean](../reference/apis-arkui/arkui-ts/ts-state-management.md#envprop10)

适配方法如下：

ArkTS1.1

```ts
Environment.EnvProp('accessibilityEnabled', 'default');
```

ArkTS1.2

```ts
Environment.envProp('accessibilityEnabled', 'default');
```

### EnvProps

ArkTS1.1接口声明：[static EnvProps<T>(props: {key: string; defaultValue: any; }[]): void](../reference/apis-arkui/arkui-ts/ts-state-management.md#envpropsdeprecated)

替代的ArkTS1.2接口声明：[static envProps<T>(props: EnvPropsOptions[]): void](../reference/apis-arkui/arkui-ts/ts-state-management.md#envprops10)

适配方法如下：

ArkTS1.1

```ts
Environment.EnvProps([
    { key: 'accessibilityEnabled', defaultValue: 'default' },
    { key: 'languageCode', defaultValue: 'en' },
    { key: 'prop', defaultValue: 'hhhh' }
]);
```

ArkTS1.2

```ts
Environment.envProps([
    { key: 'accessibilityEnabled', defaultValue: 'default' },
    { key: 'languageCode', defaultValue: 'en' },
    { key: 'prop', defaultValue: 'hhhh' }
]);
```

### Keys

ArkTS1.1接口声明：[static Keys(): Array<string>](../reference/apis-arkui/arkui-ts/ts-state-management.md#keysdeprecated)

替代的ArkTS1.2接口声明：[static keys(): Array<string>](../reference/apis-arkui/arkui-ts/ts-state-management.md#keys10)

适配方法如下：

ArkTS1.1

```ts
let keys: Array<string> = Environment.Keys();
```

ArkTS1.2

```ts
let keys: Array<string> = Environment.keys();
```

## LocalStorage 

### GetShared

ArkTS1.1接口声明：[static GetShared(): LocalStorage](../reference/apis-arkui/arkui-ts/ts-state-management.md#getshareddeprecated-1)

ArkTS1.2中，可以通过使用UIContext中的getSharedLocalStorage来获取当前stage共享的LocalStorage实例。

替代的ArkTS1.2接口声明：[getSharedLocalStorage(): LocalStorage | undefined](../reference/apis-arkui/js-apis-arkui-UIContext.md#getsharedlocalstorage12)

适配方法如下：

ArkTS1.1

```ts
let storage: LocalStorage = LocalStorage.GetShared();
```

ArkTS1.2

```ts
struct SharedLocalStorage {
    localStorage: LocalStorage | undefined = this.getUIContext().getSharedLocalStorage();
}
```

### getShared

ArkTS1.1接口声明：[static getShared(): LocalStorage](../reference/apis-arkui/arkui-ts/ts-state-management.md#getshareddeprecated)

ArkTS1.2中，可以通过使用UIContext中的getSharedLocalStorage来获取当前stage共享的LocalStorage实例。

替代的ArkTS1.2接口声明：[getSharedLocalStorage(): LocalStorage | undefined](../reference/apis-arkui/js-apis-arkui-UIContext.md#getsharedlocalstorage12)

适配方法如下：

ArkTS1.1

```ts
let storage: LocalStorage = LocalStorage.getShared();
```

ArkTS1.2

```ts
struct SharedLocalStorage {
    localStorage: LocalStorage | undefined = this.getUIContext().getSharedLocalStorage();
}
```

## PersistentStorage

### DeleteProp

ArkTS1.1接口声明：[static DeleteProp(key: string): void](../reference/apis-arkui/arkui-ts/ts-state-management.md#deletepropdeprecated)

替代的ArkTS1.2接口声明：[static deleteProp(key: string): void](../reference/apis-arkui/arkui-ts/ts-state-management.md#deleteprop10)

适配方法如下：

ArkTS1.1

```ts
PersistentStorage.DeleteProp('highScore');
```

ArkTS1.2

```ts
PersistentStorage.deleteProp('highScore');
```

### Keys

ArkTS1.1接口声明：[static Keys(): Array<string>](../reference/apis-arkui/arkui-ts/ts-state-management.md#keysdeprecated-1)

替代的ArkTS1.2接口声明：[static keys(): Array<string>](../reference/apis-arkui/arkui-ts/ts-state-management.md#keys10-1)

适配方法如下：

ArkTS1.1

```ts
let keys: Array<string> = PersistentStorage.Keys();
```

ArkTS1.2

```ts
let keys: Array<string> = PersistentStorage.keys();
```

### PersistProp

ArkTS1.1接口声明：[static PersistProp<T>(key: string, defaultValue: T): void](../reference/apis-arkui/arkui-ts/ts-state-management.md#persistpropdeprecated)

替代的ArkTS1.2接口声明：[static persistProp<T>(key: string, defaultValue: T): void](../reference/apis-arkui/arkui-ts/ts-state-management.md#persistprop10)

适配方法如下：

ArkTS1.1

```ts
PersistentStorage.PersistProp('highScore', '0');
```

ArkTS1.2

```ts
PersistentStorage.persistProp('highScore', '0');
```

### PersistProps

ArkTS1.1接口声明：[static PersistProps(properties: {key: string; defaultValue: any;}[])](../reference/apis-arkui/arkui-ts/ts-state-management.md#persistpropsdeprecated)

替代的ArkTS1.2接口声明：[static persistProp<T>(key: string, defaultValue: T): void](../reference/apis-arkui/arkui-ts/ts-state-management.md#persistprop10)

适配方法如下：

ArkTS1.1

```ts
PersistentStorage.PersistProps([
    { key: 'highScore', defaultValue: '0' },
    { key: 'wightScore', defaultValue: '1' }
]);
```

ArkTS1.2

```ts
PersistentStorage.persistProp('highScore', '0');
PersistentStorage.persistProp('wightScore', '1');
```