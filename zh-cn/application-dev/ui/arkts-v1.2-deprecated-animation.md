# 动效类接口

以下接口在ArkTS1.1中已标记为废弃，并在ArkTS1.2中不再支持。

## Animator

### create
ArkTS1.1接口声明：[static create(options: AnimatorOptions): AnimatorResult](../reference/apis-arkui/js-apis-animator.md#createdeprecated)

替代的ArkTS1.2接口声明：[createAnimator(options: AnimatorOptions): AnimatorResult](../reference/apis-arkui/js-apis-arkui-UIContext.md#createanimator)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
Animator.create({duration: 1500, easing: "friction", delay: 0, fill: "forwards", direction: "normal", iterations: 3, begin: 200.0, end: 400.0})
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().createAnimator({duration: 1500, easing: "friction", delay: 0, fill: "forwards", direction: "normal", iterations: 3, begin: 200.0, end: 400.0})
```


### createAnimator
ArkTS1.1接口声明：[static createAnimator(options: AnimatorOptions): AnimatorResult](../reference/apis-arkui/js-apis-animator.md#createanimatordeprecated)

替代的ArkTS1.2接口声明：[createAnimator(options: AnimatorOptions): AnimatorResult](../reference/apis-arkui/js-apis-arkui-UIContext.md#createanimator)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
Animator.createAnimator({duration: 1500, easing: "friction", delay: 0, fill: "forwards", direction: "normal", iterations: 3, begin: 200.0, end: 400.0})
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().createAnimator({duration: 1500, easing: "friction", delay: 0, fill: "forwards", direction: "normal", iterations: 3, begin: 200.0, end: 400.0})
```


### animateTo
ArkTS1.1接口声明：[declare function animateTo(value: AnimateParam, event: () => void): void](../reference/apis-arkui/arkui-ts/ts-explicit-animation.md#animatetodeprecated)

替代的ArkTS1.2接口声明：[animateTo(value: AnimateParam, event: () => void): void](../reference/apis-arkui/js-apis-arkui-UIContext.md#animateto)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
animateTo({ duration: 0 }, ()=>{})
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().animateTo({ duration: 0 }, ()=>{})
```


## AnimatorResult

### update
ArkTS1.1接口声明：[update(options: AnimatorOptions): void](../reference/apis-arkui/js-apis-animator.md#updatedeprecated)

替代的ArkTS1.2接口声明：[reset(options: AnimatorOptions): void](../reference/apis-arkui/js-apis-animator.md#reset9)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
let animatorResult: AnimatorResult = Animator.createAnimator({duration: 1500, easing: "friction", delay: 0, fill: "forwards", direction: "normal", iterations: 3, begin: 200.0, end: 400.0})
animatorResult.update({duration: 500, easing: "friction", delay: 1, fill: "forwards", direction: "normal", iterations: 3, begin: 200.0, end: 400.0})
```

ArkTS1.2

<!--code_no_check-->
```ts
let animatorResult: AnimatorResult = this.getUIContext().createAnimator({duration: 1500, easing: "friction", delay: 0, fill: "forwards", direction: "normal", iterations: 3, begin: 200.0, end: 400.0})
animatorResult.reset({duration: 500, easing: "friction", delay: 1, fill: "forwards", direction: "normal", iterations: 3, begin: 200.0, end: 400.0})
```


### onrepeat
ArkTS1.1接口声明：[onrepeat: () => void](../reference/apis-arkui/js-apis-animator.md#onrepeatdeprecated)

替代的ArkTS1.2接口声明：[onRepeat: () => void](../reference/apis-arkui/js-apis-animator.md#onrepeat12)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
let animatorResult: AnimatorResult = Animator.createAnimator({duration: 1500, easing: "friction", delay: 0, fill: "forwards", direction: "normal", iterations: 3, begin: 200.0, end: 400.0})
animatorResult.onrepeat = ()=>{
    console.log("onrepeat");
}
```

ArkTS1.2

<!--code_no_check-->
```ts
let animatorResult: AnimatorResult = this.getUIContext().createAnimator({duration: 1500, easing: "friction", delay: 0, fill: "forwards", direction: "normal", iterations: 3, begin: 200.0, end: 400.0})
animatorResult.onRepeat = ()=>{
    console.log("onRepeat");
}
```


### oncancel
ArkTS1.1接口声明：[oncancel: () => void](../reference/apis-arkui/js-apis-animator.md#oncanceldeprecated)

替代的ArkTS1.2接口声明：[onCancel: () => void](../reference/apis-arkui/js-apis-animator.md#oncancel12)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
let animatorResult: AnimatorResult = Animator.createAnimator({duration: 1500, easing: "friction", delay: 0, fill: "forwards", direction: "normal", iterations: 3, begin: 200.0, end: 400.0})
animatorResult.oncancel = ()=>{
    console.log("oncancel");
}
```

ArkTS1.2

<!--code_no_check-->
```ts
let animatorResult: AnimatorResult = this.getUIContext().createAnimator({duration: 1500, easing: "friction", delay: 0, fill: "forwards", direction: "normal", iterations: 3, begin: 200.0, end: 400.0})
animatorResult.onCancel = ()=>{
    console.log("onCancel");
}
```


### onfinish
ArkTS1.1接口声明：[onfinish: () => void](../reference/apis-arkui/js-apis-animator.md#onfinishdeprecated)

替代的ArkTS1.2接口声明：[onFinish: () => void](../reference/apis-arkui/js-apis-animator.md#onfinish12)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
let animatorResult: AnimatorResult = Animator.createAnimator({duration: 1500, easing: "friction", delay: 0, fill: "forwards", direction: "normal", iterations: 3, begin: 200.0, end: 400.0})
animatorResult.onfinish = ()=>{
    console.log("onfinish");
}
```

ArkTS1.2

<!--code_no_check-->
```ts
let animatorResult: AnimatorResult = this.getUIContext().createAnimator({duration: 1500, easing: "friction", delay: 0, fill: "forwards", direction: "normal", iterations: 3, begin: 200.0, end: 400.0})
animatorResult.onFinish = ()=>{
    console.log("onFinish");
}
```


### onframe
ArkTS1.1接口声明：[onframe: (progress: number) => void](../reference/apis-arkui/js-apis-animator.md#onframedeprecated)

替代的ArkTS1.2接口声明：[onFrame: (progress: number) => void](../reference/apis-arkui/js-apis-animator.md#onframe12)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
let animatorResult: AnimatorResult = Animator.createAnimator({duration: 1500, easing: "friction", delay: 0, fill: "forwards", direction: "normal", iterations: 3, begin: 200.0, end: 400.0})
animatorResult.onframe = (progress: number)=>{
    console.log("onframe");
}
```

ArkTS1.2

<!--code_no_check-->
```ts
let animatorResult: AnimatorResult = this.getUIContext().createAnimator({duration: 1500, easing: "friction", delay: 0, fill: "forwards", direction: "normal", iterations: 3, begin: 200.0, end: 400.0})
animatorResult.onFrame = (progress: number)=>{
    console.log("onFrame");
}
```


## curves

### cubicBezier
ArkTS1.1接口声明：[function cubicBezier(x1: number, y1: number, x2: number, y2: number): string](../reference/apis-arkui/js-apis-curve.md#curvescubicbezierdeprecated)

替代的ArkTS1.2接口声明：[function cubicBezierCurve(x1: number, y1: number, x2: number, y2: number): ICurve](../reference/apis-arkui/js-apis-curve.md#curvescubicbeziercurve9)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
let a: string = curves.cubicBezier(0.42, 0.0, 0.58, 1.0)
```

ArkTS1.2

<!--code_no_check-->
```ts
let a: ICurve = curves.cubicBezierCurve(0.42, 0.0, 0.58, 1.0)
```


### steps
ArkTS1.1接口声明：[function steps(count: number, end: boolean): string](../reference/apis-arkui/js-apis-curve.md#curvesstepsdeprecated)

替代的ArkTS1.2接口声明：[function stepsCurve(count: number, end: boolean): ICurve](../reference/apis-arkui/js-apis-curve.md#curvesstepscurve9)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
let a: string = curves.steps(1, false)
```

ArkTS1.2

<!--code_no_check-->
```ts
let a: ICurve = curves.stepsCurve(1, false)
```


### spring
ArkTS1.1接口声明：[function spring(velocity: number, mass: number, stiffness: number, damping: number): string](../reference/apis-arkui/js-apis-curve.md#curvesspringdeprecated)

替代的ArkTS1.2接口声明：[function springCurve(velocity: number, mass: number, stiffness: number, damping: number): ICurve](../reference/apis-arkui/js-apis-curve.md#curvesspringcurve9)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
let a: string = curves.spring(1, 1, 1, 1)
```

ArkTS1.2

<!--code_no_check-->
```ts
let a: ICurve = curves.springCurve(1, 1, 1, 1)
```


### init
ArkTS1.1接口声明：[function init(curve?: Curve): string](../reference/apis-arkui/js-apis-curve.md#curvesinitdeprecated)

替代的ArkTS1.2接口声明： [function initCurve(curve?: Curve): ICurve](../reference/apis-arkui/js-apis-curve.md#curvesinitcurve9)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
let a: string = curves.init(Curve.EaseIn)
```

ArkTS1.2

<!--code_no_check-->
```ts
let a: ICurve = curves.initCurve(Curve.EaseIn)
```


## TransitionOptions

### TransitionOptions
ArkTS1.1接口声明：[declare interface TransitionOptions](../reference/apis-arkui/arkui-ts/ts-transition-animation-component.md#transitionoptionsdeprecated)

替代的ArkTS1.2接口声明：[declare class TransitionEffect<Type extends keyof TransitionEffects = keyof TransitionEffects, Effect extends TransitionEffects[Type] = TransitionEffects[Type]>](../reference/apis-arkui/arkui-ts/ts-transition-animation-component.md#transitioneffect10对象说明)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
transition({opacity: 0})
```

ArkTS1.2

<!--code_no_check-->
```ts
transition(TransitionEffect.opacity(0))
```


### opacity
ArkTS1.1接口声明：[opacity?: number](../reference/apis-arkui/arkui-ts/ts-transition-animation-component.md#transitionoptionsdeprecated)

替代的ArkTS1.2接口声明：[static opacity(alpha: number): TransitionEffect<"opacity">](../reference/apis-arkui/arkui-ts/ts-transition-animation-component.md#transitioneffect10对象说明)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
transition({opacity: 0})
```

ArkTS1.2

<!--code_no_check-->
```ts
transition(TransitionEffect.opacity(0))
```


### rotate
ArkTS1.1接口声明：[rotate?: RotateOptions](../reference/apis-arkui/arkui-ts/ts-transition-animation-component.md#transitionoptionsdeprecated)

替代的ArkTS1.2接口声明：[static rotate(options: RotateOptions): TransitionEffect<"rotate">](../reference/apis-arkui/arkui-ts/ts-transition-animation-component.md#transitioneffect10对象说明)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
transition({rotate: {x: 1, y: 1} as RotateOptions})
```

ArkTS1.2

<!--code_no_check-->
```ts
transition(TransitionEffect.rotate({x: 1, y: 1} as RotateOptions))
```


### scale
ArkTS1.1接口声明：[scale?: ScaleOptions](../reference/apis-arkui/arkui-ts/ts-transition-animation-component.md#transitionoptionsdeprecated)

替代的ArkTS1.2接口声明：[static scale(options: ScaleOptions): TransitionEffect<"scale">](../reference/apis-arkui/arkui-ts/ts-transition-animation-component.md#transitioneffect10对象说明)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
transition({scale: {x: 1, y: 1} as ScaleOptions})
```

ArkTS1.2

<!--code_no_check-->
```ts
transition(TransitionEffect.scale({x: 1, y: 1} as ScaleOptions))
```


### translate
ArkTS1.1接口声明：[translate?: TranslateOptions](../reference/apis-arkui/arkui-ts/ts-transition-animation-component.md#transitionoptionsdeprecated)

替代的ArkTS1.2接口声明：[static translate(options: TranslateOptions): TransitionEffect<"translate">](../reference/apis-arkui/arkui-ts/ts-transition-animation-component.md#transitioneffect10对象说明)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
transition({translate: {x: 1, y: 1} as TranslateOptions})
```

ArkTS1.2

<!--code_no_check-->
```ts
transition(TransitionEffect.translate({x: 1, y: 1} as TranslateOptions))
```


### type
ArkTS1.1接口声明：[type?: TransitionType](../reference/apis-arkui/arkui-ts/ts-appendix-enums.md#transitiontype)

替代的ArkTS1.2接口声明：[static asymmetric(appear: TransitionEffect, disappear: TransitionEffect): TransitionEffect<"asymmetric">](../reference/apis-arkui/arkui-ts/ts-transition-animation-component.md#transitioneffect10对象说明)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
transition({type: TransitionType.Insert, opacity: 0})
```

ArkTS1.2

<!--code_no_check-->
```ts
transition(TransitionEffect.asymmetric(TransitionEffect.opacity(0), TransitionEffect.IDENTITY))
```