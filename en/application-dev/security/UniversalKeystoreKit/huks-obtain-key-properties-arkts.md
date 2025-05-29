# Obtaining Key Properties (ArkTS)


This topic describes how to obtain properties of a key. Before the operation, ensure that the key exists in HUKS.
>**NOTE**<br>
> The mini-system devices do not support the operation for obtaining key properties.

## How to Develop

1. Set the key alias (**keyAlias**), which cannot exceed 128 bytes.

2. Use [getKeyItemProperties](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksgetkeyitemproperties9) to obtain the properties of the key based on **keyAlias** and **options**. 
   **options** is a reserved parameter and is left empty currently.

3. You can find the key properties in the **properties** field in the [HuksReturnResult](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksreturnresult9) object.

```ts
import { huks } from '@kit.UniversalKeystoreKit';

/* 1. Set the key alias. */
let keyAlias = 'keyAlias';
/* Leave options empty. */
let emptyOptions: huks.HuksOptions = {
  properties: []
};
try {
  /* 2. Obtain key properties. */
  huks.getKeyItemProperties(keyAlias, emptyOptions, (error, data) => {
    if (error) {
      console.error(`callback: getKeyItemProperties failed, ` + JSON.stringify(error));
    } else {
      console.info(`callback: getKeyItemProperties success, data = ${JSON.stringify(data)}`);
    }
  });
} catch (error) {
  console.error(`callback: getKeyItemProperties input arg invalid, ` + JSON.stringify(error));
}
```
