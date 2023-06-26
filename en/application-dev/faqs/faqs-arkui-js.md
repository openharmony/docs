# ArkUI Development (JS)

## Why can't array variables be used to control component attributes?

Applicable to: OpenHarmony (DevEco Studio 3.0.0.993, API version 8)

Currently, the web-like development paradigm does not listen for the modification of elements in an array. Therefore, the page refresh can be triggered only when the array object is modified, but not when an element in the array is modified. In the following example, the **test1\(\)** statement, which assigns values to the entire array, will disable the related **\<Button>** component; in contrast, the **test2\(\)** statement, which assigns a value to an element in the array, will not disable the **\<Button>** component. In addition to **test1\(\)**, you can also use the method of modifying the array, for example, **splice\(\)**, to trigger the page refresh.

```
test1() {this.isDisabled = [true, true, true, true, true]; // This statement disables the <Button> component.
test2() {this.isDisabled[0] = true; // This statement does not work for the <Button> component.
```

## Does the \<input> component support center alignment?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9, FA model)

**Symptom**

The **text-align** style does not work for the **\<input>** component.

**Solution**

The **text-align** style works for the **\<text>** component, but not for the **\<input>** component.

**Reference**

[input](../reference/arkui-js/js-components-basic-input.md), [text](../reference/arkui-js/js-components-basic-text.md)


## How do I determine whether a value exists in a JS object?

Applicable to: OpenHarmony 3.2 Release (API version 9)

**Solution**

Use **Object.values\(*object name*\).indexOf\(*value to be checked*\)**. If **-1** is returned, the corresponding value is not included. Otherwise, the corresponding value is included.
