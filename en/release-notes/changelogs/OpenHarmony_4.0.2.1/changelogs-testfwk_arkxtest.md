# Test Subsystem ChangeLog

## cl.testfwk_arkxtest.1 API Name Change of Rect

The definition of **Rect**, an enumeration type that indicates the component bound information, is changed since version 4.0.2.1.

## Change Impacts

This change affects the **Rect** API provided by **@ohos.uitest**. If you have used the **Rect** API of **@ohos.uitest-api9** during test case development, adaptation is required so that the compilation can be successful in the SDK environment of the new version.

## Key API/Component Changes

### Rect<sup>9+</sup>

Before change

| Name   | Value  | Description                     |
| ------- | ---- | ------------------------- |
| leftX   | 1    | X-coordinate of the upper left corner of the component bounds.|
| topY    | 2    | Y-coordinate of the upper left corner of the component bounds.|
| rightX  | 3    | X-coordinate of the lower right corner of the component bounds.|
| bottomY | 4    | Y-coordinate of the lower right corner of the component bounds.|

After change

| Name  | Value  | Description                     |
| ------ | ---- | ------------------------- |
| left   | 1    | X-coordinate of the upper left corner of the component bounds.|
| top    | 2    | Y-coordinate of the upper left corner of the component bounds.|
| right  | 3    | X-coordinate of the lower right corner of the component bounds.|
| bottom | 4    | Y-coordinate of the lower right corner of the component bounds.|

## Adaptation Guide

### Adaptation to the API Name Change

You can replace the class name according to the following rules:

- `leftX-->left`
- `topY-->top`
- `rightX-->right`
- `bottomY-->bottom`
