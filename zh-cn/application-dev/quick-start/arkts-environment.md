# Environment：设备环境查询


开发者如果需要应用程序运行的设备的环境参数，以此来作出不同的场景判断，比如多语言，暗黑模式等，需要用到Environment设备环境查询。


Environment是ArkUI框架在应用程序启动时创建的单例对象。它为AppStorage提供了一系列描述应用程序运行状态的属性。Environment的所有属性都是不可变的（即应用不可写入），所有的属性都是简单类型。


## 使用场景


### 从UI中访问Environment参数

- 使用Environment.EnvProp将设备运行的环境变量存入AppStorage中：

  ```ts
  // 将设备的语言code存入AppStorage，默认值为en
  // 后续设备的语言设置切换，都将同步到AppStorage中
  Environment.EnvProp('languageCode', 'en');
  ```

- 可以使用\@StorageProp链接到Component中。Component会根据设备运行环境的变化而更新：

  ```ts
  @StorageProp('languageCode') lang : string = 'en';
  ```

设备环境到Component的更新链：Environment --&gt; AppStorage --&gt;Component。

> **说明：**
>
> \@StorageProp关联的环境参数可以在本地更改，但不能同步回AppStorage中，因为应用对环境变量参数是不可写的，只能在Environment中查询。


```ts
// 将设备languageCode存入AppStorage中
Environment.EnvProp('languageCode', 'en');
let enable = AppStorage.Get('languageCode');

@Entry
@Component
struct Index {
  @StorageProp('languageCode') languageCode: string = 'en';

  build() {
    Row() {
      Column() {
        // 输出当前设备的languageCode
        Text(this.languageCode)
      }
    }
  }
}
```


### 应用逻辑使用Environment


```ts
// 使用Environment.EnvProp将设备运行languageCode存入AppStorage中；
Environment.EnvProp('languageCode', 'en');
// 从AppStorage获取单向绑定的languageCode的变量
const lang: SubscribedAbstractProperty<string> = AppStorage.Prop('languageCode');

if (lang.get() === 'zh') {
  console.info('你好');
} else {
  console.info('Hello!');
}
```
