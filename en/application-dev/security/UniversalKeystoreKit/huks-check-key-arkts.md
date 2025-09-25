# Checking a Key (ArkTS)

Check whether a key exists.

## How to Develop

1. Specify the key alias. For details about the naming rules, see [Key Generation Overview and Algorithm Specifications](huks-key-generation-overview.md).

2. Initialize the key property set to specify [the property tags of keys](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukstag). When a single key is queried, **TAG** can be empty.

3. Use [hasKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukshaskeyitem11) to check whether the key exists.

```ts
import { huks } from '@kit.UniversalKeystoreKit';

/* 1. Set the key alias. */
let keyAlias = 'test_key';
let isKeyExist: Boolean;
/* 2. Construct an empty object. */
let huksOptions: huks.HuksOptions = {
  properties: []
}
try {
  /* 3. Check whether the key exists. */
  huks.hasKeyItem(keyAlias, huksOptions, (error, data) => {
    if (error) {
      console.error(`callback: hasKeyItem failed, ` + JSON.stringify(error));
    } else {
      if (data !== null && data.valueOf() !== null) {
        isKeyExist = data.valueOf();
        console.info(`callback: hasKeyItem success, isKeyExist = ${isKeyExist}`);
      }
    }
  });
} catch (error) {
  console.error(`callback: hasKeyItem input arg invalid, ` + JSON.stringify(error));
}
```
