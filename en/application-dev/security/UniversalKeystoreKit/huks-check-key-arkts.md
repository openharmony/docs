# Checking a Key (ArkTS)


Check whether a key exists.


## How to Develop

1. Set the key alias (**keyAlias**), which cannot exceed 128 bytes.

2. Initialize the key property set. You can specify [HuksTag](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukstag) of the key to check. To check a single key, leave this parameter empty.

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
