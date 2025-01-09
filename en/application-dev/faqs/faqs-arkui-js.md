# ArkUI Development (JS)


## Does the \<input> component support center alignment? (API version 9)

Applicable to: FA model

**Symptom**

The **text-align** style does not work for the **\<input>** component.

**Solution**

The **text-align** style works for the **\<text>** component, but not for the **\<input>** component.

**Reference**

[input](../reference/apis-arkui/arkui-js/js-components-basic-input.md) and [text](../reference/apis-arkui/arkui-js/js-components-basic-text.md)


## How do I determine whether a value exists in a JS object? (API version 9)

**Solution**

Use Object.values(object name).indexOf(value to be checked). If **-1** is returned, the corresponding value is not included. Otherwise, the corresponding value is included.


## Why can't array variables be used to control component attributes? (API version 8)

Currently, the web-like development paradigm does not listen for the modification of elements in an array. Therefore, the page refresh can be triggered only when the array object is modified, but not when an element in the array is modified. In the following example, the **test1\(\)** statement, which assigns values to the entire array, will disable the related **Button** component; in contrast, the **test2\(\)** statement, which assigns a value to an element in the array, will not disable the **Button** component. In addition to **test1\(\)**, you can also use the method of modifying the array, for example, **splice\(\)**, to trigger the page refresh.

```
test1() {this.isDisabled = [true, true, true, true, true]; // This statement disables the <button> component.
test2() {this.isDisabled[0] = true; // This statement does not work for the <button> component.
```

## What is the latest TS version compatible with JS development? Will new features of TS and JS be introduced in the future? (API version 11)

The latest TS version working with API version 11 is TS 4.9.5, with support for ECMAScript 2017. TS and JS versions will be continuously upgraded.
