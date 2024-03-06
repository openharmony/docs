# Starting a DataAbility


When a DataAbility is started, a **DataAbilityHelper** object is obtained. The sample code for starting a DataAbility is as follows:

```ts
import featureAbility from '@ohos.ability.featureAbility'
```
```ts
private uri = 'dataability:///com.samples.famodelabilitydevelop.DataAbility';
private DAHelper = featureAbility.acquireDataAbilityHelper(this.uri);
```
