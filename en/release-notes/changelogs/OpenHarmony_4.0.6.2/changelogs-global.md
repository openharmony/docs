# Globalization Subsystem Changelog

## cl.resourceManager.1 Addition of getStringSync and getStringByNameSync APIs

Added the **getStringSync** and **getStringByNameSync** APIs and error codes to obtain and format strings.

| Bundle Name | API |
| --------------- | ---------------------------------------------------- |
| ohos.resourceManager.d.ts | getStringSync(resId: number, ...args: Array<string \| number>): string; |
| ohos.resourceManager.d.ts | getStringSync(resource: Resource, ...args: Array<string \| number>): string; |
| ohos.resourceManager.d.ts | getStringByNameSync(resName: string, ...args: Array<string \| number>): string; |

**Change Impact**

In versions earlier than 4.0.6.2, only the values of string resources can be directly obtained. In 4.0.6.2 or later, the values of string resources can be formatted based on the input arguments for enhanced query.

The following error codes are added:

9001007 If the resource obtained by resId formatting error.

9001008 If the resource obtained by resName formatting error.

**Sample Code**

The following uses **getStringSync** as an example. Before the change, only example 1 is supported. After the change, both example 1 and example 2 are supported.
```
Example 1:
try {
  this.context.resourceManager.getStringSync($r('app.string.test').id);
} catch (error) {
  console.error(`getStringSync failed, error code: ${error.code}, message: ${error.message}.`)
}
Example 2:
try {
  this.context.resourceManager.getStringSync($r('app.string.test').id, "format string", 787, 98.78);
} catch (error) {
  console.error(`getStringSync failed, error code: ${error.code}, message: ${error.message}.`)
}
```

**Adaptation Guide**
For details, see the API reference.

[API Reference](../../../application-dev/reference/apis/js-apis-resource-manager.md)

[Error Codes](../../../application-dev/reference/errorcodes/errorcode-resource-manager.md)
