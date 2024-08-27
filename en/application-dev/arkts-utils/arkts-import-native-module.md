# Importing a Native Module

In ECMAScript 6.0 (ES6) module design, the community uses the **import** syntax to load the content exported from other files (the ECMA specification defines the syntax specifications).
To help you easily use this feature to import the content exported from the native module (.so), ArkTS performs adaptation and provides several import methods.

## Direct Import
Export the content from the **index.d.ts** file of a native module, and then import the content to the file.

### Named Import
```ts
// index.d.ts corresponding to libentry.so
export const add: (a: number, b: number) => number;
```
```ts
// test.ets
import { add } from 'libentry.so'
add(2, 3);
```

### Default Import
```ts
// index.d.ts corresponding to libentry.so
export const add: (a: number, b: number) => number;
```
```ts
// test.ets
import add from 'libentry.so'
add.add(2, 3);
```

### Namespace Import
```ts
// index.d.ts corresponding to libentry.so
export const add: (a: number, b: number) => number;
```
```ts
// test.ets
import * as add from 'libentry.so'
add.add(2, 3);
```

## Indirect Import

### Converting to Named Variables Before Export and Import
```ts
// test1.ets
import hilog from '@ohos.hilog'
export { hilog }
```
```ts
// test2.ets
import { hilog } from './test1'
hilog.info(0x000, 'testTag', '%{public}s', 'test');
```

### Converting to Namespaces Before Export and Import
```ts
// index.d.ts corresponding to libentry.so
export const add: (a: number, b: number) => number;
```
```ts
// test1.ets
export * from 'libentry.so'
```
```ts
// test2.ets
import { add } from './test1'
add(2, 3);
```
Note: Namespaces cannot be used simultaneously during the export and import of native modules. 
**Negative example:** 
```ts
// test1.ets
export * from 'libentry.so'
```
```ts
// test2.ets
import * as add from 'file1'
// The add object cannot be obtained.
```

## Dynamic Import

### Direct Import
```ts
// index.d.ts corresponding to libentry.so
export const add: (a: number, b: number) => number;
```
```ts
// test.ets
import('libentry.so').then((ns:ESObject) => {
    ns.default.add(2, 3);
})
```
### Indirect Import
```ts
// test1.ets
import add from 'libentry.so'
export { add }

// test2.ets
import('./test1').then((ns:ESObject) => {
    ns.add.add(2, 3);
})
```

**Note**: When dynamic loading is not supported, a file must be exported using the namespace. 
**Negative example:** 
```ts
// test1.ets
export * from 'libentry.so'
```
```ts
// test2.ets
import('./test1').then((ns:ESObject) => {
    // The ns object cannot be obtained.
})
```
