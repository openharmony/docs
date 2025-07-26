# ArkTS Changelog

## cl.arkts.1 Fix for Array Content Exceptions When Redefining Arrays with Literals After Element Deletion

**Access Level**

Public API

**Reason for Change**

After an element is deleted from an array defined by a literal, the array content is abnormal when the literal is used to define the array again.

**Impact of the Change**

This change requires application adaptation.

Before the change, when an array defined by a literal has elements deleted and is redefined with the same literal, the new array contains the elements that remained after deletion.

After the change, when an array defined by a literal has elements deleted and is redefined with the same literal, the new array contains the elements as originally defined by the literal.

**Start API Level**

6

**Change Since**

OpenHarmony SDK 6.0.0.32

**Key API/Component Changes**

N/A

**Adaptation Guide**

Check for instances where arrays are defined using literals and elements are deleted without other modifications.

For example:

```typescript
for (let i = 0; i < 2; i++) {
    let arr = [0, 0]
    console.log(JSON.stringify(arr));
    delete arr[0];
}
```

Before the change, the output of this example is:

```
[0,0]
[null,0]
```

After the change, the output of this example is:

```
[0,0]
[0,0]
```

This change fixes the issue, ensuring that when an array defined by a literal has elements deleted and is redefined with the same literal, the new array contains the elements as originally defined by the literal.
