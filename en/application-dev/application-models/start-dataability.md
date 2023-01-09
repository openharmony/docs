# Starting a DataAbility


When a DataAbility is started, a **DataAbilityHelper** object is obtained. The sample code for starting a DataAbility is as follows:

```ts
// Different from the URI defined in the config.json file, the URI passed in the parameter has an extra slash (/), three slashes in total.
import featureAbility from '@ohos.ability.featureAbility'

let urivar = "dataability:///com.ix.DataAbility"
let DAHelper = featureAbility.acquireDataAbilityHelper(urivar);
```
