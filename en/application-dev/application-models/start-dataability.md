# Starting a DataAbility


When a DataAbility is started, a **DataAbilityHelper** object is obtained. The sample code for starting a DataAbility is as follows:

```ts
import featureAbility from '@ohos.ability.featureAbility';
import ability from '@ohos.ability.ability';

let uri: string = 'dataability:///com.samples.famodelabilitydevelop.DataAbility';
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(uri);
```
