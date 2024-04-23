| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：WindowExtensionAbility<br>方法or属性：context: WindowExtensionContext;|@ohos.application.WindowExtensionAbility.d.ts|
|新增|NA|类名：Window<br>方法or属性：bindDialogTarget(requestInfo: dialogRequest.RequestInfo, deathCallback: Callback\<void>): Promise\<void>;|@ohos.window.d.ts|
|新增|NA|类名：Window<br>方法or属性：bindDialogTarget(requestInfo: dialogRequest.RequestInfo, deathCallback: Callback\<void>, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|新增|NA|模块名: WindowExtensionContext<br>类名: WindowExtensionContext|WindowExtensionContext.d.ts|
|新增|NA|模块名: WindowExtensionContext<br>类名: WindowExtensionContext<br>方法 or 属性: startAbility(want: Want, options: StartOptions, callback: AsyncCallback\<void>): void;|WindowExtensionContext.d.ts|
|新增|NA|模块名: WindowExtensionContext<br>类名: WindowExtensionContext<br>方法 or 属性: startAbility(want: Want, options?: StartOptions): Promise\<void>;|WindowExtensionContext.d.ts|
|删除|模块名：ohos.window<br>类名:Window<br>方法 or 属性:on(type: 'dialogTargetTouch', callback: Callback\<void>): void;|NA|@ohos.window.d.ts|
|删除|模块名：ohos.window<br>类名:Window<br>方法 or 属性:off(type: 'dialogTargetTouch', callback?: Callback\<void>): void;|NA|@ohos.window.d.ts|
|访问级别有变化|类名：WindowAnimationFinishedCallback<br>方法 or 属性：onAnimationFinish(): void;<br>访问级别：公开API|类名：WindowAnimationFinishedCallback<br>方法 or 属性：onAnimationFinish(): void;<br>访问级别：系统API|@ohos.animation.windowAnimationManager.d.ts|
|访问级别有变化|类名：WindowType<br>方法 or 属性：TYPE_FLOAT_CAMERA<br>访问级别：公开API|类名：WindowType<br>方法 or 属性：TYPE_FLOAT_CAMERA<br>访问级别：系统API|@ohos.window.d.ts|
|起始版本有变化|类名：RRect<br>方法 or 属性：left: number;<br>起始版本：N/A|类名：RRect<br>方法 or 属性：left: number;<br>起始版本：9|@ohos.animation.windowAnimationManager.d.ts|
|起始版本有变化|类名：RRect<br>方法 or 属性：top: number;<br>起始版本：N/A|类名：RRect<br>方法 or 属性：top: number;<br>起始版本：9|@ohos.animation.windowAnimationManager.d.ts|
|起始版本有变化|类名：RRect<br>方法 or 属性：width: number;<br>起始版本：N/A|类名：RRect<br>方法 or 属性：width: number;<br>起始版本：9|@ohos.animation.windowAnimationManager.d.ts|
|起始版本有变化|类名：RRect<br>方法 or 属性：height: number;<br>起始版本：N/A|类名：RRect<br>方法 or 属性：height: number;<br>起始版本：9|@ohos.animation.windowAnimationManager.d.ts|
|起始版本有变化|类名：RRect<br>方法 or 属性：radius: number;<br>起始版本：N/A|类名：RRect<br>方法 or 属性：radius: number;<br>起始版本：9|@ohos.animation.windowAnimationManager.d.ts|
|起始版本有变化|类名：WindowAnimationTarget<br>方法 or 属性：readonly bundleName: string;<br>起始版本：N/A|类名：WindowAnimationTarget<br>方法 or 属性：readonly bundleName: string;<br>起始版本：9|@ohos.animation.windowAnimationManager.d.ts|
|起始版本有变化|类名：WindowAnimationTarget<br>方法 or 属性：readonly abilityName: string;<br>起始版本：N/A|类名：WindowAnimationTarget<br>方法 or 属性：readonly abilityName: string;<br>起始版本：9|@ohos.animation.windowAnimationManager.d.ts|
|起始版本有变化|类名：WindowAnimationTarget<br>方法 or 属性：readonly windowBounds: RRect;<br>起始版本：N/A|类名：WindowAnimationTarget<br>方法 or 属性：readonly windowBounds: RRect;<br>起始版本：9|@ohos.animation.windowAnimationManager.d.ts|
|起始版本有变化|类名：WindowAnimationTarget<br>方法 or 属性：readonly missionId: number;<br>起始版本：N/A|类名：WindowAnimationTarget<br>方法 or 属性：readonly missionId: number;<br>起始版本：9|@ohos.animation.windowAnimationManager.d.ts|
|起始版本有变化|类名：WindowAnimationFinishedCallback<br>方法 or 属性：onAnimationFinish(): void;<br>起始版本：N/A|类名：WindowAnimationFinishedCallback<br>方法 or 属性：onAnimationFinish(): void;<br>起始版本：9|@ohos.animation.windowAnimationManager.d.ts|
|起始版本有变化|类名：Rect<br>方法 or 属性：left: number;<br>起始版本：N/A|类名：Rect<br>方法 or 属性：left: number;<br>起始版本：9|@ohos.display.d.ts|
|起始版本有变化|类名：Rect<br>方法 or 属性：top: number;<br>起始版本：N/A|类名：Rect<br>方法 or 属性：top: number;<br>起始版本：9|@ohos.display.d.ts|
|起始版本有变化|类名：Rect<br>方法 or 属性：width: number;<br>起始版本：N/A|类名：Rect<br>方法 or 属性：width: number;<br>起始版本：9|@ohos.display.d.ts|
|起始版本有变化|类名：Rect<br>方法 or 属性：height: number;<br>起始版本：N/A|类名：Rect<br>方法 or 属性：height: number;<br>起始版本：9|@ohos.display.d.ts|
|起始版本有变化|类名：WaterfallDisplayAreaRects<br>方法 or 属性：readonly left: Rect;<br>起始版本：N/A|类名：WaterfallDisplayAreaRects<br>方法 or 属性：readonly left: Rect;<br>起始版本：9|@ohos.display.d.ts|
|起始版本有变化|类名：WaterfallDisplayAreaRects<br>方法 or 属性：readonly right: Rect;<br>起始版本：N/A|类名：WaterfallDisplayAreaRects<br>方法 or 属性：readonly right: Rect;<br>起始版本：9|@ohos.display.d.ts|
|起始版本有变化|类名：WaterfallDisplayAreaRects<br>方法 or 属性：readonly top: Rect;<br>起始版本：N/A|类名：WaterfallDisplayAreaRects<br>方法 or 属性：readonly top: Rect;<br>起始版本：9|@ohos.display.d.ts|
|起始版本有变化|类名：WaterfallDisplayAreaRects<br>方法 or 属性：readonly bottom: Rect;<br>起始版本：N/A|类名：WaterfallDisplayAreaRects<br>方法 or 属性：readonly bottom: Rect;<br>起始版本：9|@ohos.display.d.ts|
|起始版本有变化|类名：CutoutInfo<br>方法 or 属性：readonly boundingRects: Array\<Rect>;<br>起始版本：N/A|类名：CutoutInfo<br>方法 or 属性：readonly boundingRects: Array\<Rect>;<br>起始版本：9|@ohos.display.d.ts|
|起始版本有变化|类名：CutoutInfo<br>方法 or 属性：readonly waterfallDisplayAreaRects: WaterfallDisplayAreaRects;<br>起始版本：N/A|类名：CutoutInfo<br>方法 or 属性：readonly waterfallDisplayAreaRects: WaterfallDisplayAreaRects;<br>起始版本：9|@ohos.display.d.ts|
|起始版本有变化|类名：ScaleOptions<br>方法 or 属性：x?: number;<br>起始版本：N/A|类名：ScaleOptions<br>方法 or 属性：x?: number;<br>起始版本：9|@ohos.window.d.ts|
|起始版本有变化|类名：ScaleOptions<br>方法 or 属性：y?: number;<br>起始版本：N/A|类名：ScaleOptions<br>方法 or 属性：y?: number;<br>起始版本：9|@ohos.window.d.ts|
|起始版本有变化|类名：ScaleOptions<br>方法 or 属性：pivotX?: number;<br>起始版本：N/A|类名：ScaleOptions<br>方法 or 属性：pivotX?: number;<br>起始版本：9|@ohos.window.d.ts|
|起始版本有变化|类名：ScaleOptions<br>方法 or 属性：pivotY?: number;<br>起始版本：N/A|类名：ScaleOptions<br>方法 or 属性：pivotY?: number;<br>起始版本：9|@ohos.window.d.ts|
|起始版本有变化|类名：RotateOptions<br>方法 or 属性：x?: number;<br>起始版本：N/A|类名：RotateOptions<br>方法 or 属性：x?: number;<br>起始版本：9|@ohos.window.d.ts|
|起始版本有变化|类名：RotateOptions<br>方法 or 属性：y?: number;<br>起始版本：N/A|类名：RotateOptions<br>方法 or 属性：y?: number;<br>起始版本：9|@ohos.window.d.ts|
|起始版本有变化|类名：RotateOptions<br>方法 or 属性：z?: number;<br>起始版本：N/A|类名：RotateOptions<br>方法 or 属性：z?: number;<br>起始版本：9|@ohos.window.d.ts|
|起始版本有变化|类名：RotateOptions<br>方法 or 属性：pivotX?: number;<br>起始版本：N/A|类名：RotateOptions<br>方法 or 属性：pivotX?: number;<br>起始版本：9|@ohos.window.d.ts|
|起始版本有变化|类名：RotateOptions<br>方法 or 属性：pivotY?: number;<br>起始版本：N/A|类名：RotateOptions<br>方法 or 属性：pivotY?: number;<br>起始版本：9|@ohos.window.d.ts|
|起始版本有变化|类名：TranslateOptions<br>方法 or 属性：x?: number;<br>起始版本：N/A|类名：TranslateOptions<br>方法 or 属性：x?: number;<br>起始版本：9|@ohos.window.d.ts|
|起始版本有变化|类名：TranslateOptions<br>方法 or 属性：y?: number;<br>起始版本：N/A|类名：TranslateOptions<br>方法 or 属性：y?: number;<br>起始版本：9|@ohos.window.d.ts|
|起始版本有变化|类名：TranslateOptions<br>方法 or 属性：z?: number;<br>起始版本：N/A|类名：TranslateOptions<br>方法 or 属性：z?: number;<br>起始版本：9|@ohos.window.d.ts|
|起始版本有变化|类名：TransitionContext<br>方法 or 属性：toWindow: Window<br>起始版本：N/A|类名：TransitionContext<br>方法 or 属性：toWindow: Window<br>起始版本：9|@ohos.window.d.ts|
|起始版本有变化|类名：TransitionContext<br>方法 or 属性：completeTransition(isCompleted: boolean): void;<br>起始版本：N/A|类名：TransitionContext<br>方法 or 属性：completeTransition(isCompleted: boolean): void;<br>起始版本：9|@ohos.window.d.ts|
|起始版本有变化|类名：TransitionController<br>方法 or 属性：animationForShown(context: TransitionContext): void;<br>起始版本：N/A|类名：TransitionController<br>方法 or 属性：animationForShown(context: TransitionContext): void;<br>起始版本：9|@ohos.window.d.ts|
|起始版本有变化|类名：TransitionController<br>方法 or 属性：animationForHidden(context: TransitionContext): void;<br>起始版本：N/A|类名：TransitionController<br>方法 or 属性：animationForHidden(context: TransitionContext): void;<br>起始版本：9|@ohos.window.d.ts|
|起始版本有变化|类名：Configuration<br>方法 or 属性：name: string<br>起始版本：N/A|类名：Configuration<br>方法 or 属性：name: string<br>起始版本：9|@ohos.window.d.ts|
|起始版本有变化|类名：Configuration<br>方法 or 属性：windowType: WindowType<br>起始版本：N/A|类名：Configuration<br>方法 or 属性：windowType: WindowType<br>起始版本：9|@ohos.window.d.ts|
|起始版本有变化|类名：Configuration<br>方法 or 属性：ctx?: BaseContext<br>起始版本：N/A|类名：Configuration<br>方法 or 属性：ctx?: BaseContext<br>起始版本：9|@ohos.window.d.ts|
|起始版本有变化|类名：Configuration<br>方法 or 属性：displayId?: number<br>起始版本：N/A|类名：Configuration<br>方法 or 属性：displayId?: number<br>起始版本：9|@ohos.window.d.ts|
|起始版本有变化|类名：Configuration<br>方法 or 属性：parentId?: number<br>起始版本：N/A|类名：Configuration<br>方法 or 属性：parentId?: number<br>起始版本：9|@ohos.window.d.ts|
|起始版本有变化|类名：Orientation<br>方法 or 属性：UNSPECIFIED = 0<br>起始版本：N/A|类名：Orientation<br>方法 or 属性：UNSPECIFIED = 0<br>起始版本：9|@ohos.window.d.ts|
|起始版本有变化|类名：Orientation<br>方法 or 属性：PORTRAIT = 1<br>起始版本：N/A|类名：Orientation<br>方法 or 属性：PORTRAIT = 1<br>起始版本：9|@ohos.window.d.ts|
|起始版本有变化|类名：Orientation<br>方法 or 属性：LANDSCAPE = 2<br>起始版本：N/A|类名：Orientation<br>方法 or 属性：LANDSCAPE = 2<br>起始版本：9|@ohos.window.d.ts|
|起始版本有变化|类名：Orientation<br>方法 or 属性：PORTRAIT_INVERTED = 3<br>起始版本：N/A|类名：Orientation<br>方法 or 属性：PORTRAIT_INVERTED = 3<br>起始版本：9|@ohos.window.d.ts|
|起始版本有变化|类名：Orientation<br>方法 or 属性：LANDSCAPE_INVERTED = 4<br>起始版本：N/A|类名：Orientation<br>方法 or 属性：LANDSCAPE_INVERTED = 4<br>起始版本：9|@ohos.window.d.ts|
|起始版本有变化|类名：Orientation<br>方法 or 属性：AUTO_ROTATION = 5<br>起始版本：N/A|类名：Orientation<br>方法 or 属性：AUTO_ROTATION = 5<br>起始版本：9|@ohos.window.d.ts|
|起始版本有变化|类名：Orientation<br>方法 or 属性：AUTO_ROTATION_PORTRAIT = 6<br>起始版本：N/A|类名：Orientation<br>方法 or 属性：AUTO_ROTATION_PORTRAIT = 6<br>起始版本：9|@ohos.window.d.ts|
|起始版本有变化|类名：Orientation<br>方法 or 属性：AUTO_ROTATION_LANDSCAPE = 7<br>起始版本：N/A|类名：Orientation<br>方法 or 属性：AUTO_ROTATION_LANDSCAPE = 7<br>起始版本：9|@ohos.window.d.ts|
|起始版本有变化|类名：Orientation<br>方法 or 属性：AUTO_ROTATION_RESTRICTED = 8<br>起始版本：N/A|类名：Orientation<br>方法 or 属性：AUTO_ROTATION_RESTRICTED = 8<br>起始版本：9|@ohos.window.d.ts|
|起始版本有变化|类名：Orientation<br>方法 or 属性：AUTO_ROTATION_PORTRAIT_RESTRICTED = 9<br>起始版本：N/A|类名：Orientation<br>方法 or 属性：AUTO_ROTATION_PORTRAIT_RESTRICTED = 9<br>起始版本：9|@ohos.window.d.ts|
|起始版本有变化|类名：Orientation<br>方法 or 属性：AUTO_ROTATION_LANDSCAPE_RESTRICTED = 10<br>起始版本：N/A|类名：Orientation<br>方法 or 属性：AUTO_ROTATION_LANDSCAPE_RESTRICTED = 10<br>起始版本：9|@ohos.window.d.ts|
|起始版本有变化|类名：Orientation<br>方法 or 属性：LOCKED = 11<br>起始版本：N/A|类名：Orientation<br>方法 or 属性：LOCKED = 11<br>起始版本：9|@ohos.window.d.ts|
|起始版本有变化|类名：BlurStyle<br>方法 or 属性：OFF<br>起始版本：N/A|类名：BlurStyle<br>方法 or 属性：OFF<br>起始版本：9|@ohos.window.d.ts|
|起始版本有变化|类名：BlurStyle<br>方法 or 属性：THIN<br>起始版本：N/A|类名：BlurStyle<br>方法 or 属性：THIN<br>起始版本：9|@ohos.window.d.ts|
|起始版本有变化|类名：BlurStyle<br>方法 or 属性：REGULAR<br>起始版本：N/A|类名：BlurStyle<br>方法 or 属性：REGULAR<br>起始版本：9|@ohos.window.d.ts|
|起始版本有变化|类名：BlurStyle<br>方法 or 属性：THICK<br>起始版本：N/A|类名：BlurStyle<br>方法 or 属性：THICK<br>起始版本：9|@ohos.window.d.ts|
|起始版本有变化|类名：WindowStageEventType<br>方法 or 属性：SHOWN = 1<br>起始版本：N/A|类名：WindowStageEventType<br>方法 or 属性：SHOWN = 1<br>起始版本：9|@ohos.window.d.ts|
|起始版本有变化|类名：WindowStageEventType<br>方法 or 属性：ACTIVE<br>起始版本：N/A|类名：WindowStageEventType<br>方法 or 属性：ACTIVE<br>起始版本：9|@ohos.window.d.ts|
|起始版本有变化|类名：WindowStageEventType<br>方法 or 属性：INACTIVE<br>起始版本：N/A|类名：WindowStageEventType<br>方法 or 属性：INACTIVE<br>起始版本：9|@ohos.window.d.ts|
|起始版本有变化|类名：WindowStageEventType<br>方法 or 属性：HIDDEN<br>起始版本：N/A|类名：WindowStageEventType<br>方法 or 属性：HIDDEN<br>起始版本：9|@ohos.window.d.ts|
|删除(权限)|类名：WindowType<br>方法 or 属性：TYPE_FLOAT_CAMERA<br>权限:ohos.permission.SYSTEM_FLOAT_WINDOW|类名：WindowType<br>方法 or 属性：TYPE_FLOAT_CAMERA<br>权限:N/A|@ohos.window.d.ts|
