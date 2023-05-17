# Environment: Device Environment Query


You may want your application to behave differently based on the device environment where the application is running, for example, switching to dark mode or a specific language. In this case, you need Environment for device environment query.


Environment is a singleton object created by the ArkUI framework at application start. It provides a range of application state attributes to AppStorage that describe the device environment in which the application is running. Environment and its attributes are immutable. All property values are of simple type only.


## Application Scenarios


### Accessing Environment Parameters from UI

- Use **Environment.EnvProp** to save the environment variables of the device to AppStorage.

  ```ts
  // Save the language code of the device to AppStorage. The default value is en.
  // Whenever its value changes in the device environment, it will update its value in AppStorage.
  Environment.EnvProp('languageCode', 'en');
  ```

- To keep a component variable updated with changes in the device environment, this variable should be decorated with \@StorageProp.

  ```ts
  @StorageProp('languageCode') lang : string = 'en';
  ```

The chain of updates is as follows: Environment > AppStorage > Component.

> **NOTE**
> An \@StorageProp decorated variable can be locally modified, but the change will not be updated to AppStorage. This is because the environment variable parameters are read-only to the application.


```ts
// Save the device language code to AppStorage.
Environment.EnvProp('languageCode', 'en');
let enable = AppStorage.Get('languageCode');

@Entry
@Component
struct Index {
  @StorageProp('languageCode') languageCode: string = 'en';

  build() {
    Row() {
      Column() {
        // Output the current device language code.
        Text(this.languageCode)
      }
    }
  }
}
```


### Using Environment in Application Logic


```ts
// Use Environment.EnvProp to save the device language code to AppStorage.
Environment.EnvProp('languageCode', 'en');
// Obtain the one-way bound languageCode variable from AppStorage.
const lang: SubscribedAbstractProperty<string> = AppStorage.Prop('languageCode');

if (lang.get() === 'en') {
  console.info('Hi');
} else {
  console.info('Hello!');
}
```
