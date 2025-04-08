# Statically Loading Native Modules

In ECMAScript 6.0 (ES6) module design, the **import** syntax is used to load content exported by other files, as defined by the ECMAScript specification.

To help you easily import content exported from native modules (.so), ArkTS has adapted and supports the following methods:

## Direct Import
Export content from the **index.d.ts** file of a native module, and then import the content to the file.

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

### Export as Named Variables and Import
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

### Export as Namespaces and Import
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
> **NOTE**
> 
> Native modules do not support both export and import using namespaces simultaneously.

**Anti-example:**
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

> **NOTE**
> 
> Dynamic imports do not support exporting files using namespace exports.

**Anti-example:**
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
