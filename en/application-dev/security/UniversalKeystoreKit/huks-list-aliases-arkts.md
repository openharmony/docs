# Querying Key Aliases


This topic walks you through on how to query key aliases.


## How to Develop

1. Initialize the key property set.

   Set the tag for querying the key aliases. The tag can only be **HUKS_TAG_AUTH_STORAGE_LEVEL**.

2. Use [listAliases](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukslistaliases12) to query the key aliases.

```ts
/*
 * The following example uses promise-based APIs to query key aliases.
 */
import { huks } from '@kit.UniversalKeystoreKit'

async function testListAliases() {
  /* 1. Initialize the key property set. */
  let queryProperties: Array<huks.HuksParam> = [
    {
      tag: huks.HuksTag.HUKS_TAG_AUTH_STORAGE_LEVEL,
      value: huks.HuksAuthStorageLevel.HUKS_AUTH_STORAGE_LEVEL_DE
    }
  ];
  let queryOptions: huks.HuksOptions = {
    properties: queryProperties
  };

  try {
    /* 2. Query key aliases. */
    let result: huks.HuksListAliasesReturnResult = await huks.listAliases(queryOptions);
    console.info(`promise: listAliases success`);
  } catch (error) {
    console.error(`promise: listAliases fail`);
  }
}
```
