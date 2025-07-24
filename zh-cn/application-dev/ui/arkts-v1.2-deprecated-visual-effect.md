# 视效类接口

以下接口在ArkTS1.1中已标记为废弃，并在ArkTS1.2中不再支持。

## CommonMethod

### clip
ArkTS1.1接口声明：[clip(value: boolean | CircleAttribute | EllipseAttribute | PathAttribute | RectAttribute): T](../reference/apis-arkui/arkui-ts/ts-universal-attributes-sharp-clipping.md#clipdeprecated)

替代的ArkTS1.2接口声明：[clipShape(value: CircleShape | EllipseShape | PathShape | RectShape): T](../reference/apis-arkui/arkui-ts/ts-universal-attributes-sharp-clipping.md#clipshape12)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
Text().clip(new Rect({width: 100, height: 100}))
```

ArkTS1.2

<!--code_no_check-->
```ts
Text().clipShape(new Rect({width: 100, height: 100}))
```


### mask
ArkTS1.1接口声明：[mask(value: CircleAttribute | EllipseAttribute | PathAttribute | RectAttribute | ProgressMask): T](../reference/apis-arkui/arkui-ts/ts-universal-attributes-sharp-clipping.md#maskdeprecated)

替代的ArkTS1.2接口声明：[maskShape(value: CircleShape | EllipseShape | PathShape | RectShape): T](../reference/apis-arkui/arkui-ts/ts-universal-attributes-sharp-clipping.md#maskshape12)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
Text().mask(new Rect({width: 100, height: 100}))
```

ArkTS1.2

<!--code_no_check-->
```ts
Text().maskShape(new Rect({width: 100, height: 100}))
```


## matrix4

### invert

ArkTS1.1接口声明：[function invert(): Matrix4Transit](../reference/apis-arkui/js-apis-matrix4.md#matrix4invertdeprecated)

替代的ArkTS1.2接口声明：[invert(): Matrix4Transit](../reference/apis-arkui/js-apis-matrix4.md#invert)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
let m = matrix4.invert()
```

ArkTS1.2

<!--code_no_check-->
```ts
let m = matrix4.identity().invert()
```


### scale

ArkTS1.1接口声明：[function scale(options: ScaleOption): Matrix4Transit](../reference/apis-arkui/js-apis-matrix4.md#matrix4scaledeprecated)

替代的ArkTS1.2接口声明：[scale(options: ScaleOption): Matrix4Transit](../reference/apis-arkui/js-apis-matrix4.md#scale)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
let m = matrix4.scale({x: 1, y: 1})
```

ArkTS1.2

<!--code_no_check-->
```ts
let m = matrix4.identity().scale({x: 1, y: 1})
```


### rotate

ArkTS1.1接口声明：[function rotate(options: RotateOption): Matrix4Transit](../reference/apis-arkui/js-apis-matrix4.md#matrix4rotatedeprecated)

替代的ArkTS1.2接口声明：[rotate(options: RotateOption): Matrix4Transit](../reference/apis-arkui/js-apis-matrix4.md#scale)

适配方法如下：

<!--code_no_check-->
```ts
let m = matrix4.rotate({x: 1, y: 1})
```

<!--code_no_check-->
```ts
let m = matrix4.identity().rotate({x: 1, y: 1})
```


### translate

ArkTS1.1接口声明：[function translate(options: TranslateOption): Matrix4Transit](../reference/apis-arkui/js-apis-matrix4.md#matrix4translatedeprecated)

替代的ArkTS1.2接口声明：[translate(options: TranslateOption): Matrix4Transit](../reference/apis-arkui/js-apis-matrix4.md#translate)

适配方法如下：

<!--code_no_check-->
```ts
let m = matrix4.translate({x: 1, y: 1})
```

<!--code_no_check-->
```ts
let m = matrix4.identity().translate({x: 1, y: 1})
```


### transformPoint

ArkTS1.1接口声明：[function transformPoint(options: [number, number]): [number, number]](../reference/apis-arkui/js-apis-matrix4.md#matrix4transformpointdeprecated)

替代的ArkTS1.2接口声明：[transformPoint(options: [number, number]): [number, number]](../reference/apis-arkui/js-apis-matrix4.md#transformpoint)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
let m = matrix4.transformPoint([1, 1])
```

ArkTS1.2

<!--code_no_check-->
```ts
let m = matrix4.identity().transformPoint([1, 1])
```


### combine

ArkTS1.1接口声明：[function combine(options: Matrix4Transit): Matrix4Transit](../reference/apis-arkui/js-apis-matrix4.md#matrix4combinedeprecated)

替代的ArkTS1.2接口声明：[combine(options: Matrix4Transit): Matrix4Transit](../reference/apis-arkui/js-apis-matrix4.md#combine)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
let m = matrix4.combine(matrix4.scale({x: 1, y: 1}))
```

ArkTS1.2

<!--code_no_check-->
```ts
let m = matrix4.identity().combine(matrix4.identity().scale({x: 1, y: 1}))
```


### copy
ArkTS1.1接口声明：[function copy(): Matrix4Transit](../reference/apis-arkui/js-apis-matrix4.md#matrix4copydeprecated)

替代的ArkTS1.2接口声明：[copy(): Matrix4Transit](../reference/apis-arkui/js-apis-matrix4.md#copy)

适配方法如下：

<!--code_no_check-->
```ts
let m = matrix4.copy()
```

ArkTS1.2

<!--code_no_check-->
```ts
let m = matrix4.identity().copy()
```