# Context (FA Model)


There is only one context in the FA model. All capabilities in the context are provided through methods. The context uses these methods to extend the capabilities of the **featureAbility** class.


## Available APIs

To use the context in the FA model, first import the **featureAbility** module.


```ts
import featureAbility from "@ohos.ability.featureAbility";
```

Then, call **getContext()** to obtain the **Context** object:


```ts
import featureAbility from "@ohos.ability.featureAbility";

let context = featureAbility.getContext()
```

For details about the APIs, see [API Reference](../reference/apis/js-apis-inner-app-context.md).


## How to Develop

1. Query bundle information.
   
   ```ts
    import featureAbility from '@ohos.ability.featureAbility'

    class Entry {
      onCreate() {
        // Obtain the context and call related APIs.
        let context = featureAbility.getContext();
        context.getBundleName((data, bundleName)=>{
          console.info("ability bundleName:" + bundleName)
        });
        console.info('Application onCreate')
      }
      onDestroy() {
        console.info('Application onDestroy')
      }
    }

    export default new Entry()
   ```
   
2. Set the display orientation of the **featureAbility**.
   
   ```ts
    import featureAbility from '@ohos.ability.featureAbility'
    import bundle from '@ohos.bundle';

    class Entry {
      onCreate() {
        // Obtain the context and call related APIs.
        let context = featureAbility.getContext();
        context.setDisplayOrientation(bundle.DisplayOrientation.LANDSCAPE).then(() => {
          console.info("Set display orientation.")
        })
        console.info('Application onCreate')
      }
      onDestroy() {
        console.info('Application onDestroy')
      }
    }

    export default new Entry();
   ```
