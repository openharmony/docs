# Exporting a Key (ArkTS)


This topic walks you through on how to export the public key of a persistently stored asymmetric key. Currently, HUKS supports export of the ECC, RSA, Ed25519, X25519, and SM2 public keys.
>**NOTE**<br>
> The mini-system devices support export of only the RSA public keys.


## How to Develop

1. Set the key alias (**keyAlias**), which cannot exceed 64 bytes.

2. Use [exportKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksexportkeyitem9) to export the key based on the specified **keyAlias** and **options**.
   **options** is a reserved parameter and is left empty currently.

3. In the [HuksReturnResult](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksreturnresult9) object returned, the public key is in the **outData** field in the DER format defined in X.509. For details about the format, see [Public Key Material Format](huks-concepts.md#public-key-material-format).

```ts
import { huks } from '@kit.UniversalKeystoreKit';

/* 1. Set the key alias. */
let keyAlias = 'keyAlias';
/* Leave options empty. */
let emptyOptions: huks.HuksOptions = {
  properties: []
};
try {
  /* 2. Export the key. */
  huks.exportKeyItem(keyAlias, emptyOptions, (error, data) => {
    if (error) {
      console.error(`callback: exportKeyItem failed, ` + error);
    } else {
      console.info(`callback: exportKeyItem success, data = ${JSON.stringify(data)}`);
    }
  });
} catch (error) {
  console.error(`callback: exportKeyItem input arg invalid, ` + JSON.stringify(error));
}
```
