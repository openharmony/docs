| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|模块名: ohos.arkui.componentSnapshot<br>类名: componentSnapshot|@ohos.arkui.componentSnapshot.d.ts|
|新增|NA|模块名: ohos.arkui.componentSnapshot<br>类名: componentSnapshot<br>方法 or 属性: function get(id: string, callback: AsyncCallback\<image.PixelMap>): void;|@ohos.arkui.componentSnapshot.d.ts|
|新增|NA|模块名: ohos.arkui.componentSnapshot<br>类名: componentSnapshot<br>方法 or 属性: function get(id: string): Promise\<image.PixelMap>;|@ohos.arkui.componentSnapshot.d.ts|
|新增|NA|模块名: ohos.arkui.componentSnapshot<br>类名: componentSnapshot<br>方法 or 属性: function createFromBuilder(builder: CustomBuilder, callback: AsyncCallback\<image.PixelMap>): void;|@ohos.arkui.componentSnapshot.d.ts|
|新增|NA|模块名: ohos.arkui.componentSnapshot<br>类名: componentSnapshot<br>方法 or 属性: function createFromBuilder(builder: CustomBuilder): Promise\<image.PixelMap>;|@ohos.arkui.componentSnapshot.d.ts|
|新增|NA|模块名: ohos.arkui.drawableDescriptor<br>类名: DrawableDescriptor|@ohos.arkui.drawableDescriptor.d.ts|
|新增|NA|模块名: ohos.arkui.drawableDescriptor<br>类名: DrawableDescriptor<br>方法 or 属性: constructor();|@ohos.arkui.drawableDescriptor.d.ts|
|新增|NA|模块名: ohos.arkui.drawableDescriptor<br>类名: DrawableDescriptor<br>方法 or 属性: getPixelMap(): image.PixelMap;|@ohos.arkui.drawableDescriptor.d.ts|
|新增|NA|模块名: ohos.arkui.drawableDescriptor<br>类名: LayeredDrawableDescriptor|@ohos.arkui.drawableDescriptor.d.ts|
|新增|NA|模块名: ohos.arkui.drawableDescriptor<br>类名: LayeredDrawableDescriptor<br>方法 or 属性: getForeground(): DrawableDescriptor;|@ohos.arkui.drawableDescriptor.d.ts|
|新增|NA|模块名: ohos.arkui.drawableDescriptor<br>类名: LayeredDrawableDescriptor<br>方法 or 属性: getBackground(): DrawableDescriptor;|@ohos.arkui.drawableDescriptor.d.ts|
|新增|NA|模块名: ohos.arkui.drawableDescriptor<br>类名: LayeredDrawableDescriptor<br>方法 or 属性: getMask(): DrawableDescriptor;|@ohos.arkui.drawableDescriptor.d.ts|
|新增|NA|类名：curves<br>方法or属性：function interpolatingSpring(velocity: number, mass: number, stiffness: number, damping: number): ICurve;|@ohos.curves.d.ts|
|新增|NA|类名：MeasureOptions<br>方法or属性：textContent: string \| Resource;|@ohos.measure.d.ts|
|新增|NA|类名：MeasureOptions<br>方法or属性：constraintWidth?: number \| string \| Resource;|@ohos.measure.d.ts|
|新增|NA|类名：MeasureOptions<br>方法or属性：textAlign?: number \| TextAlign;|@ohos.measure.d.ts|
|新增|NA|类名：MeasureOptions<br>方法or属性：overflow?: number \| TextOverflow;|@ohos.measure.d.ts|
|新增|NA|类名：MeasureOptions<br>方法or属性：maxLines?: number;|@ohos.measure.d.ts|
|新增|NA|类名：MeasureOptions<br>方法or属性：lineHeight?: number \| string \| Resource;|@ohos.measure.d.ts|
|新增|NA|类名：MeasureOptions<br>方法or属性：baselineOffset?: number \| string;|@ohos.measure.d.ts|
|新增|NA|类名：MeasureOptions<br>方法or属性：textCase?: number \| TextCase;|@ohos.measure.d.ts|
|新增|NA|模块名: ohos.measure<br>类名: MeasureText<br>方法 or 属性：static measureTextSize(options: MeasureOptions): SizeOptions;|@ohos.measure.d.ts|
|新增|NA|类名：MeasureText<br>方法or属性：static measureTextSize(options: MeasureOptions): SizeOptions;|@ohos.measure.d.ts|
|新增|NA|模块名: ohos.uiAppearance<br>类名: uiAppearance|@ohos.uiAppearance.d.ts|
|新增|NA|模块名: ohos.uiAppearance<br>类名: DarkMode|@ohos.uiAppearance.d.ts|
|新增|NA|模块名: ohos.uiAppearance<br>类名: DarkMode<br>方法 or 属性: ALWAYS_DARK = 0|@ohos.uiAppearance.d.ts|
|新增|NA|模块名: ohos.uiAppearance<br>类名: DarkMode<br>方法 or 属性: ALWAYS_LIGHT = 1|@ohos.uiAppearance.d.ts|
|新增|NA|模块名: ohos.uiAppearance<br>类名: uiAppearance<br>方法 or 属性: function setDarkMode(mode: DarkMode, callback: AsyncCallback\<void>): void;|@ohos.uiAppearance.d.ts|
|新增|NA|模块名: ohos.uiAppearance<br>类名: uiAppearance<br>方法 or 属性: function setDarkMode(mode: DarkMode): Promise\<void>;|@ohos.uiAppearance.d.ts|
|新增|NA|模块名: ohos.uiAppearance<br>类名: uiAppearance<br>方法 or 属性: function getDarkMode(): DarkMode;|@ohos.uiAppearance.d.ts|
|新增|NA|类名：AlertDialogParamWithConfirm<br>方法or属性：confirm?: {<br>    /**<br>     * Text content of the confirmation button.<br>     * @since 7<br>     */<br>    /**<br>     * Text content of the confirmation button.<br>     * @crossplatform<br>     * @since 10<br>     */<br>    value: ResourceStr;<br><br>    /**<br>     * Text color of the confirmation button.<br>     * @since 7<br>     */<br>    /**<br>     * Text color of the confirmation button.<br>     * @crossplatform<br>     * @since 10<br>     */<br>    fontColor?: ResourceColor;<br><br>    /**<br>     * Background color of the confirmation button.<br>     * @since 7<br>     */<br>    /**<br>     * Background color of the confirmation button.<br>     * @crossplatform<br>     * @since 10<br>     */<br>    backgroundColor?: ResourceColor;<br><br>    /**<br>     * Method executed by the callback.<br>     * @since 7<br>     */<br>    /**<br>     * Method executed by the callback.<br>     * @crossplatform<br>     * @since 10<br>     */<br>    action: () => void;<br>  };|alert_dialog.d.ts|
|新增|NA|类名：AlertDialogParamWithButtons<br>方法or属性：primaryButton: {<br>    /**<br>     * Text content of the confirmation button.<br>     * @since 7<br>     */<br>    /**<br>     * Text content of the confirmation button.<br>     * @crossplatform<br>     * @since 10<br>     */<br>    value: ResourceStr;<br><br>    /**<br>     * Text color of the confirmation button.<br>     * @since 7<br>     */<br>    /**<br>     * Text color of the confirmation button.<br>     * @crossplatform<br>     * @since 10<br>     */<br>    fontColor?: ResourceColor;<br><br>    /**<br>     * Background color of the confirmation button.<br>     * @since 7<br>     */<br>    /**<br>     * Background color of the confirmation button.<br>     * @crossplatform<br>     * @since 10<br>     */<br>    backgroundColor?: ResourceColor;<br><br>    /**<br>     * Method executed by the callback.<br>     * @since 7<br>     */<br>    /**<br>     * Method executed by the callback.<br>     * @crossplatform<br>     * @since 10<br>     */<br>    action: () => void;<br>  };|alert_dialog.d.ts|
|新增|NA|类名：AlertDialogParamWithButtons<br>方法or属性：secondaryButton: {<br>    /**<br>     * Text content of the confirmation button.<br>     * @since 7<br>     */<br>    /**<br>     * Text content of the confirmation button.<br>     *  @crossplatform<br>     * @since 10<br>     */<br>    value: ResourceStr;<br><br>    /**<br>     * Text color of the confirmation button.<br>     * @since 7<br>     */<br>    /**<br>     * Text color of the confirmation button.<br>     * @crossplatform<br>     * @since 10<br>     */<br>    fontColor?: ResourceColor;<br><br>    /**<br>     * Background color of the confirmation button.<br>     * @since 7<br>     */<br>    /**<br>     * Background color of the confirmation button.<br>     * @crossplatform<br>     * @since 10<br>     */<br>    backgroundColor?: ResourceColor;<br><br>    /**<br>     * Method executed by the callback.<br>     * @since 7<br>     */<br>    /**<br>     * Method executed by the callback.<br>     * @crossplatform<br>     * @since 10<br>     */<br>    action: () => void;<br>  };|alert_dialog.d.ts|
|新增|NA|类名：AlphabetIndexerAttribute<br>方法or属性：popupSelectedColor(value: ResourceColor): AlphabetIndexerAttribute;|alphabet_indexer.d.ts|
|新增|NA|类名：AlphabetIndexerAttribute<br>方法or属性：popupUnselectedColor(value: ResourceColor): AlphabetIndexerAttribute;|alphabet_indexer.d.ts|
|新增|NA|类名：AlphabetIndexerAttribute<br>方法or属性：popupItemBackgroundColor(value: ResourceColor): AlphabetIndexerAttribute;|alphabet_indexer.d.ts|
|新增|NA|类名：AlphabetIndexerAttribute<br>方法or属性：popupItemFont(value: Font): AlphabetIndexerAttribute;|alphabet_indexer.d.ts|
|新增|NA|模块名: badge<br>类名: BadgeStyle<br>方法 or 属性: borderColor?: ResourceColor;|badge.d.ts|
|新增|NA|模块名: badge<br>类名: BadgeStyle<br>方法 or 属性: borderWidth?: Length;|badge.d.ts|
|新增|NA|模块名: badge<br>类名: BadgeStyle<br>方法 or 属性: fontWeight?: number \| FontWeight \| string;|badge.d.ts|
|新增|NA|模块名: button<br>类名: LabelStyle|button.d.ts|
|新增|NA|模块名: button<br>类名: LabelStyle<br>方法 or 属性: overflow?: TextOverflow;|button.d.ts|
|新增|NA|模块名: button<br>类名: LabelStyle<br>方法 or 属性: maxLines?: number;|button.d.ts|
|新增|NA|模块名: button<br>类名: LabelStyle<br>方法 or 属性: minFontSize?: number \| ResourceStr;|button.d.ts|
|新增|NA|模块名: button<br>类名: LabelStyle<br>方法 or 属性: maxFontSize?: number \| ResourceStr;|button.d.ts|
|新增|NA|模块名: button<br>类名: LabelStyle<br>方法 or 属性: heightAdaptivePolicy?: TextHeightAdaptivePolicy;|button.d.ts|
|新增|NA|模块名: button<br>类名: LabelStyle<br>方法 or 属性: font?: Font;|button.d.ts|
|新增|NA|模块名: button<br>类名: ButtonAttribute<br>方法 or 属性: labelStyle(value: LabelStyle): ButtonAttribute;|button.d.ts|
|新增|NA|模块名: canvas<br>类名: CanvasPattern|canvas.d.ts|
|新增|NA|模块名: canvas<br>类名: CanvasPattern<br>方法 or 属性：setTransform(transform?: Matrix2D): void;|canvas.d.ts|
|新增|NA|类名：CanvasRenderer<br>方法or属性：fillStyle: string \| number \| CanvasGradient \| CanvasPattern;|canvas.d.ts|
|新增|NA|类名：CanvasRenderer<br>方法or属性：strokeStyle: string \| number \| CanvasGradient \| CanvasPattern;|canvas.d.ts|
|新增|NA|类名：CanvasRenderer<br>方法or属性：createConicGradient(<br>    startAngle: number,<br>    x: number,<br>    y: number<br>  ): CanvasGradient;|canvas.d.ts|
|新增|NA|类名：CanvasRenderer<br>方法or属性：putImageData(imagedata: ImageData, dx: number \| string, dy: number \| string): void;|canvas.d.ts|
|新增|NA|类名：CanvasRenderer<br>方法or属性：putImageData(<br>    imagedata: ImageData,<br>    dx: number \| string,<br>    dy: number \| string,<br>    dirtyX: number \| string,<br>    dirtyY: number \| string,<br>    dirtyWidth: number \| string,<br>    dirtyHeight: number \| string<br>  ): void;|canvas.d.ts|
|新增|NA|模块名: canvas<br>类名: OffscreenCanvas<br>方法 or 属性：getContext(contextType: "2d", option?: RenderingContextSettings): OffscreenCanvasRenderingContext2D;|canvas.d.ts|
|新增|NA|类名：OffscreenCanvas<br>方法or属性：getContext(contextType: "2d", option?: RenderingContextSettings): OffscreenCanvasRenderingContext2D;|canvas.d.ts|
|新增|NA|模块名: checkbox<br>类名: CheckboxAttribute<br>方法 or 属性: unselectedColor(value: ResourceColor): CheckboxAttribute;|checkbox.d.ts|
|新增|NA|模块名: checkbox<br>类名: CheckboxAttribute<br>方法 or 属性: mark(value: MarkStyle): CheckboxAttribute;|checkbox.d.ts|
|新增|NA|模块名: checkboxgroup<br>类名: CheckboxGroupAttribute<br>方法 or 属性: unselectedColor(value: ResourceColor): CheckboxGroupAttribute;|checkboxgroup.d.ts|
|新增|NA|模块名: checkboxgroup<br>类名: CheckboxGroupAttribute<br>方法 or 属性: mark(value: MarkStyle): CheckboxGroupAttribute;|checkboxgroup.d.ts|
|新增|NA|类名：global<br>方法or属性：declare const AnimatableExtend: MethodDecorator & ((value: Object) => MethodDecorator);|common.d.ts|
|新增|NA|模块名: common<br>类名: AnimatableArithmetic|common.d.ts|
|新增|NA|模块名: common<br>类名: AnimatableArithmetic<br>方法 or 属性：plus(rhs: AnimatableArithmetic\<T>): AnimatableArithmetic\<T>;|common.d.ts|
|新增|NA|类名：AnimatableArithmetic<br>方法or属性：plus(rhs: AnimatableArithmetic\<T>): AnimatableArithmetic\<T>;|common.d.ts|
|新增|NA|模块名: common<br>类名: AnimatableArithmetic<br>方法 or 属性：subtract(rhs: AnimatableArithmetic\<T>): AnimatableArithmetic\<T>;|common.d.ts|
|新增|NA|类名：AnimatableArithmetic<br>方法or属性：subtract(rhs: AnimatableArithmetic\<T>): AnimatableArithmetic\<T>;|common.d.ts|
|新增|NA|模块名: common<br>类名: AnimatableArithmetic<br>方法 or 属性：multiply(scale: number): AnimatableArithmetic\<T>;|common.d.ts|
|新增|NA|类名：AnimatableArithmetic<br>方法or属性：multiply(scale: number): AnimatableArithmetic\<T>;|common.d.ts|
|新增|NA|模块名: common<br>类名: AnimatableArithmetic<br>方法 or 属性：equals(rhs: AnimatableArithmetic\<T>): boolean;|common.d.ts|
|新增|NA|类名：AnimatableArithmetic<br>方法or属性：equals(rhs: AnimatableArithmetic\<T>): boolean;|common.d.ts|
|新增|NA|类名：global<br>方法or属性：declare const Recycle: ClassDecorator;|common.d.ts|
|新增|NA|模块名: common<br>类名: TransitionEdge|common.d.ts|
|新增|NA|模块名: common<br>类名: TransitionEdge<br>方法 or 属性：TOP|common.d.ts|
|新增|NA|模块名: common<br>类名: TransitionEdge<br>方法 or 属性：BOTTOM|common.d.ts|
|新增|NA|模块名: common<br>类名: TransitionEdge<br>方法 or 属性：START|common.d.ts|
|新增|NA|模块名: common<br>类名: TransitionEdge<br>方法 or 属性：END|common.d.ts|
|新增|NA|模块名: common<br>类名: TransitionEffect|common.d.ts|
|新增|NA|模块名: common<br>类名: TransitionEffect<br>方法 or 属性：static readonly IDENTITY: TransitionEffect\<"identity">;|common.d.ts|
|新增|NA|模块名: common<br>类名: TransitionEffect<br>方法 or 属性：static readonly OPACITY: TransitionEffect\<"opacity">;|common.d.ts|
|新增|NA|模块名: common<br>类名: TransitionEffect<br>方法 or 属性：static readonly SLIDE: TransitionEffect\<<br>    "asymmetric",<br>    {<br>      appear: TransitionEffect\<"move", TransitionEdge>;<br>      disappear: TransitionEffect\<"move", TransitionEdge>;<br>    }<br>  >;|common.d.ts|
|新增|NA|模块名: common<br>类名: TransitionEffect<br>方法 or 属性：static readonly SLIDE_SWITCH: TransitionEffect\<"slideSwitch">;|common.d.ts|
|新增|NA|模块名: common<br>类名: TransitionEffect<br>方法 or 属性：static translate(options: TranslateOptions): TransitionEffect\<"translate">;|common.d.ts|
|新增|NA|模块名: common<br>类名: TransitionEffect<br>方法 or 属性：static rotate(options: RotateOptions): TransitionEffect\<"rotate">;|common.d.ts|
|新增|NA|模块名: common<br>类名: TransitionEffect<br>方法 or 属性：static scale(options: ScaleOptions): TransitionEffect\<"scale">;|common.d.ts|
|新增|NA|模块名: common<br>类名: TransitionEffect<br>方法 or 属性：static opacity(alpha: number): TransitionEffect\<"opacity">;|common.d.ts|
|新增|NA|模块名: common<br>类名: TransitionEffect<br>方法 or 属性：static move(edge: TransitionEdge): TransitionEffect\<"move">;|common.d.ts|
|新增|NA|模块名: common<br>类名: TransitionEffect<br>方法 or 属性：static asymmetric(<br>    appear: TransitionEffect,<br>    disappear: TransitionEffect<br>  ): TransitionEffect\<"asymmetric">;|common.d.ts|
|新增|NA|模块名: common<br>类名: TransitionEffect<br>方法 or 属性：constructor(type: Type, effect: Effect);|common.d.ts|
|新增|NA|模块名: common<br>类名: TransitionEffect<br>方法 or 属性：animation(value: AnimateParam): TransitionEffect;|common.d.ts|
|新增|NA|模块名: common<br>类名: TransitionEffect<br>方法 or 属性：combine(transitionEffect: TransitionEffect): TransitionEffect;|common.d.ts|
|新增|NA|类名：SourceTool<br>方法or属性：Finger|common.d.ts|
|新增|NA|类名：SourceTool<br>方法or属性：Pen|common.d.ts|
|新增|NA|类名：BlurStyle<br>方法or属性：BackgroundThin|common.d.ts|
|新增|NA|类名：BlurStyle<br>方法or属性：BackgroundRegular|common.d.ts|
|新增|NA|类名：BlurStyle<br>方法or属性：BackgroundThick|common.d.ts|
|新增|NA|类名：BlurStyle<br>方法or属性：BackgroundUltraThick|common.d.ts|
|新增|NA|类名：BlurStyle<br>方法or属性：BACKGROUND_THIN|common.d.ts|
|新增|NA|类名：BlurStyle<br>方法or属性：BACKGROUND_REGULAR|common.d.ts|
|新增|NA|类名：BlurStyle<br>方法or属性：BACKGROUND_THICK|common.d.ts|
|新增|NA|类名：BlurStyle<br>方法or属性：BACKGROUND_ULTRA_THICK|common.d.ts|
|新增|NA|模块名: common<br>类名: ThemeColorMode|common.d.ts|
|新增|NA|模块名: common<br>类名: ThemeColorMode<br>方法 or 属性：System|common.d.ts|
|新增|NA|模块名: common<br>类名: ThemeColorMode<br>方法 or 属性：Light|common.d.ts|
|新增|NA|模块名: common<br>类名: ThemeColorMode<br>方法 or 属性：Dark|common.d.ts|
|新增|NA|模块名: common<br>类名: ThemeColorMode<br>方法 or 属性：SYSTEM|common.d.ts|
|新增|NA|模块名: common<br>类名: ThemeColorMode<br>方法 or 属性：LIGHT|common.d.ts|
|新增|NA|模块名: common<br>类名: ThemeColorMode<br>方法 or 属性：DARK|common.d.ts|
|新增|NA|模块名: common<br>类名: AdaptiveColor|common.d.ts|
|新增|NA|模块名: common<br>类名: AdaptiveColor<br>方法 or 属性：Default|common.d.ts|
|新增|NA|模块名: common<br>类名: AdaptiveColor<br>方法 or 属性：Average|common.d.ts|
|新增|NA|模块名: common<br>类名: AdaptiveColor<br>方法 or 属性：DEFAULT|common.d.ts|
|新增|NA|模块名: common<br>类名: AdaptiveColor<br>方法 or 属性：AVERAGE|common.d.ts|
|新增|NA|模块名: common<br>类名: ModalTransition|common.d.ts|
|新增|NA|模块名: common<br>类名: ModalTransition<br>方法 or 属性：Default|common.d.ts|
|新增|NA|模块名: common<br>类名: ModalTransition<br>方法 or 属性：None|common.d.ts|
|新增|NA|模块名: common<br>类名: ModalTransition<br>方法 or 属性：Alpha|common.d.ts|
|新增|NA|模块名: common<br>类名: ModalTransition<br>方法 or 属性：DEFAULT|common.d.ts|
|新增|NA|模块名: common<br>类名: ModalTransition<br>方法 or 属性：NONE|common.d.ts|
|新增|NA|模块名: common<br>类名: ModalTransition<br>方法 or 属性：ALPHA|common.d.ts|
|新增|NA|模块名: common<br>类名: BackgroundBlurStyleOptions|common.d.ts|
|新增|NA|模块名: common<br>类名: BackgroundBlurStyleOptions<br>方法 or 属性：colorMode?: ThemeColorMode;|common.d.ts|
|新增|NA|类名：BackgroundBlurStyleOptions<br>方法or属性：colorMode?: ThemeColorMode;|common.d.ts|
|新增|NA|模块名: common<br>类名: BackgroundBlurStyleOptions<br>方法 or 属性：adaptiveColor?: AdaptiveColor;|common.d.ts|
|新增|NA|类名：BackgroundBlurStyleOptions<br>方法or属性：adaptiveColor?: AdaptiveColor;|common.d.ts|
|新增|NA|模块名: common<br>类名: BackgroundBlurStyleOptions<br>方法 or 属性：scale?: number;|common.d.ts|
|新增|NA|类名：BackgroundBlurStyleOptions<br>方法or属性：scale?: number;|common.d.ts|
|新增|NA|模块名: common<br>类名: PickerTextStyle|common.d.ts|
|新增|NA|类名：PickerTextStyle<br>方法or属性：|common.d.ts|
|新增|NA|模块名: common<br>类名: PickerTextStyle<br>方法 or 属性：color?: ResourceColor;|common.d.ts|
|新增|NA|模块名: common<br>类名: PickerTextStyle<br>方法 or 属性：font?: Font;|common.d.ts|
|新增|NA|模块名: common<br>类名: ShadowType|common.d.ts|
|新增|NA|模块名: common<br>类名: ShadowType<br>方法 or 属性：COLOR|common.d.ts|
|新增|NA|模块名: common<br>类名: ShadowType<br>方法 or 属性：BLUR|common.d.ts|
|新增|NA|模块名: common<br>类名: ShadowOptions|common.d.ts|
|新增|NA|模块名: common<br>类名: ShadowOptions<br>方法 or 属性：radius: number \| Resource;|common.d.ts|
|新增|NA|模块名: common<br>类名: ShadowOptions<br>方法 or 属性：type?: ShadowType;|common.d.ts|
|新增|NA|模块名: common<br>类名: ShadowOptions<br>方法 or 属性：color?: Color \| string \| Resource;|common.d.ts|
|新增|NA|模块名: common<br>类名: ShadowOptions<br>方法 or 属性：offsetX?: number \| Resource;|common.d.ts|
|新增|NA|模块名: common<br>类名: ShadowOptions<br>方法 or 属性：offsetY?: number \| Resource;|common.d.ts|
|新增|NA|模块名: common<br>类名: ShadowStyle|common.d.ts|
|新增|NA|模块名: common<br>类名: ShadowStyle<br>方法 or 属性：OuterDefaultXS|common.d.ts|
|新增|NA|模块名: common<br>类名: ShadowStyle<br>方法 or 属性：OuterDefaultSM|common.d.ts|
|新增|NA|模块名: common<br>类名: ShadowStyle<br>方法 or 属性：OuterDefaultMD|common.d.ts|
|新增|NA|模块名: common<br>类名: ShadowStyle<br>方法 or 属性：OuterDefaultLG|common.d.ts|
|新增|NA|模块名: common<br>类名: ShadowStyle<br>方法 or 属性：OuterFloatingSM|common.d.ts|
|新增|NA|模块名: common<br>类名: ShadowStyle<br>方法 or 属性：OuterFloatingMD|common.d.ts|
|新增|NA|模块名: common<br>类名: ShadowStyle<br>方法 or 属性：OUTER_DEFAULT_XS|common.d.ts|
|新增|NA|模块名: common<br>类名: ShadowStyle<br>方法 or 属性：OUTER_DEFAULT_SM|common.d.ts|
|新增|NA|模块名: common<br>类名: ShadowStyle<br>方法 or 属性：OUTER_DEFAULT_MD|common.d.ts|
|新增|NA|模块名: common<br>类名: ShadowStyle<br>方法 or 属性：OUTER_DEFAULT_LG|common.d.ts|
|新增|NA|模块名: common<br>类名: ShadowStyle<br>方法 or 属性：OUTER_FLOATING_SM|common.d.ts|
|新增|NA|模块名: common<br>类名: ShadowStyle<br>方法 or 属性：OUTER_FLOATING_MD|common.d.ts|
|新增|NA|模块名: common<br>类名: SheetSize|common.d.ts|
|新增|NA|模块名: common<br>类名: SheetSize<br>方法 or 属性：MEDIUM|common.d.ts|
|新增|NA|模块名: common<br>类名: SheetSize<br>方法 or 属性：LARGE|common.d.ts|
|新增|NA|模块名: common<br>类名: DragBehavior|common.d.ts|
|新增|NA|模块名: common<br>类名: DragBehavior<br>方法 or 属性：COPY|common.d.ts|
|新增|NA|模块名: common<br>类名: DragBehavior<br>方法 or 属性：MOVE|common.d.ts|
|新增|NA|模块名: common<br>类名: DragRet|common.d.ts|
|新增|NA|模块名: common<br>类名: DragRet<br>方法 or 属性：DRAG_SUCCESS|common.d.ts|
|新增|NA|模块名: common<br>类名: DragRet<br>方法 or 属性：DRAG_FAILED|common.d.ts|
|新增|NA|模块名: common<br>类名: DragRet<br>方法 or 属性：DRAG_CANCELED|common.d.ts|
|新增|NA|模块名: common<br>类名: DragRet<br>方法 or 属性：DROP_ENABLED|common.d.ts|
|新增|NA|类名：DragEvent<br>方法or属性：dragBehavior: DragBehavior;|common.d.ts|
|新增|NA|类名：DragEvent<br>方法or属性：useCustomDropAnimation: boolean;|common.d.ts|
|新增|NA|类名：DragEvent<br>方法or属性：setData(unifiedData: UnifiedData): void;|common.d.ts|
|新增|NA|类名：DragEvent<br>方法or属性：getData(): UnifiedData;|common.d.ts|
|新增|NA|类名：DragEvent<br>方法or属性：getSummary(): Summary;|common.d.ts|
|新增|NA|类名：DragEvent<br>方法or属性：setResult(dragRet: DragRet): void;|common.d.ts|
|新增|NA|类名：DragEvent<br>方法or属性：getResult(): DragRet;|common.d.ts|
|新增|NA|类名：DragEvent<br>方法or属性：getPreviewRect(): Rectangle;|common.d.ts|
|新增|NA|模块名: common<br>类名: SheetStyle|common.d.ts|
|新增|NA|模块名: common<br>类名: SheetStyle<br>方法 or 属性：height?: SheetSize \| Length;|common.d.ts|
|新增|NA|模块名: common<br>类名: SheetStyle<br>方法 or 属性：dragBar?: boolean;|common.d.ts|
|新增|NA|模块名: common<br>类名: PopupMessageOptions|common.d.ts|
|新增|NA|模块名: common<br>类名: PopupMessageOptions<br>方法 or 属性：textColor?: ResourceColor;|common.d.ts|
|新增|NA|模块名: common<br>类名: PopupMessageOptions<br>方法 or 属性：font?: Font;|common.d.ts|
|新增|NA|类名：PopupOptions<br>方法or属性：placement?: Placement;|common.d.ts|
|新增|NA|类名：PopupOptions<br>方法or属性：primaryButton?: {<br>    /**<br>     * Button text value<br>     * @since 7<br>     */<br>    /**<br>     * Button text value<br>     * @crossplatform<br>     * @since 10<br>     */<br>    value: string;<br><br>    /**<br>     * action<br>     * @since 7<br>     */<br>    /**<br>     * action<br>     * @crossplatform<br>     * @since 10<br>     */<br>    action: () => void;<br>  };|common.d.ts|
|新增|NA|类名：PopupOptions<br>方法or属性：secondaryButton?: {<br>    /**<br>     * Button text value<br>     * @since 7<br>     */<br>    /**<br>     * Button text value<br>     * @crossplatform<br>     * @since 10<br>     */<br>    value: string;<br><br>    /**<br>     * action<br>     * @since 7<br>     */<br>    /**<br>     * action<br>     * @crossplatform<br>     * @since 10<br>     */<br>    action: () => void;<br>  };|common.d.ts|
|新增|NA|类名：PopupOptions<br>方法or属性：mask?: boolean \| { color: ResourceColor };|common.d.ts|
|新增|NA|类名：PopupOptions<br>方法or属性：messageOptions?: PopupMessageOptions|common.d.ts|
|新增|NA|类名：PopupOptions<br>方法or属性：targetSpace?: Length|common.d.ts|
|新增|NA|类名：CustomPopupOptions<br>方法or属性：mask?: boolean \| { color: ResourceColor };|common.d.ts|
|新增|NA|类名：CustomPopupOptions<br>方法or属性：targetSpace?: Length|common.d.ts|
|新增|NA|模块名: common<br>类名: ContextMenuOptions|common.d.ts|
|新增|NA|模块名: common<br>类名: ContextMenuOptions<br>方法 or 属性：offset?: Position;|common.d.ts|
|新增|NA|模块名: common<br>类名: ContextMenuOptions<br>方法 or 属性：placement?: Placement;|common.d.ts|
|新增|NA|模块名: common<br>类名: ContextMenuOptions<br>方法 or 属性：onAppear?: () => void;|common.d.ts|
|新增|NA|模块名: common<br>类名: ContextMenuOptions<br>方法 or 属性：onDisappear?: () => void;|common.d.ts|
|新增|NA|模块名: common<br>类名: MenuOptions|common.d.ts|
|新增|NA|模块名: common<br>类名: MenuOptions<br>方法 or 属性：title?: ResourceStr;|common.d.ts|
|新增|NA|模块名: common<br>类名: ProgressMask|common.d.ts|
|新增|NA|模块名: common<br>类名: ProgressMask<br>方法 or 属性：constructor(value: number, total: number, color: ResourceColor);|common.d.ts|
|新增|NA|模块名: common<br>类名: ProgressMask<br>方法 or 属性：updateProgress(value: number): void;|common.d.ts|
|新增|NA|模块名: common<br>类名: ProgressMask<br>方法 or 属性：updateColor(value: ResourceColor): void;|common.d.ts|
|新增|NA|模块名: common<br>类名: PixelStretchEffectOptions|common.d.ts|
|新增|NA|模块名: common<br>类名: PixelStretchEffectOptions<br>方法 or 属性：top?: Length;|common.d.ts|
|新增|NA|模块名: common<br>类名: PixelStretchEffectOptions<br>方法 or 属性：bottom?: Length;|common.d.ts|
|新增|NA|模块名: common<br>类名: PixelStretchEffectOptions<br>方法 or 属性：left?: Length;|common.d.ts|
|新增|NA|模块名: common<br>类名: PixelStretchEffectOptions<br>方法 or 属性：right?: Length;|common.d.ts|
|新增|NA|类名：CommonMethod<br>方法or属性：foregroundColor(value: ResourceColor \| ColoringStrategy): T;|common.d.ts|
|新增|NA|类名：CommonMethod<br>方法or属性：onDragEnd(event: (event: DragEvent, extraParams?: string) => void): T;|common.d.ts|
|新增|NA|类名：CommonMethod<br>方法or属性：allowDrop(value: Array\<UnifiedDataType>): T;|common.d.ts|
|新增|NA|类名：CommonMethod<br>方法or属性：draggable(value: boolean): T;|common.d.ts|
|新增|NA|类名：CommonMethod<br>方法or属性：bindContentCover(isShow: boolean, builder: CustomBuilder, type?: ModalTransition): T;|common.d.ts|
|新增|NA|类名：CommonMethod<br>方法or属性：bindSheet(isShow: boolean, builder: CustomBuilder, style?: SheetStyle): T;|common.d.ts|
|新增|NA|类名：CommonMethod<br>方法or属性：sphericalEffect(value: number): T;|common.d.ts|
|新增|NA|类名：CommonMethod<br>方法or属性：lightUpEffect(value: number): T;|common.d.ts|
|新增|NA|类名：CommonMethod<br>方法or属性：pixelStretchEffect(options: PixelStretchEffectOptions): T;|common.d.ts|
|新增|NA|类名：CommonMethod<br>方法or属性：keyboardShortcut(value: string \| FunctionKey, keys: Array\<ModifierKey>, action?: () => void): T;|common.d.ts|
|新增|NA|类名：CustomComponent<br>方法or属性：onRecycle?(params: { [key: string]: unknown }): void;|common.d.ts|
|新增|NA|类名：SubscribedAbstractProperty<br>方法or属性：abstract aboutToBeDeleted(): void;|common_ts_ets_api.d.ts|
|新增|NA|模块名: counter<br>类名: CounterAttribute<br>方法 or 属性: enableDec(value: boolean): CounterAttribute;|counter.d.ts|
|新增|NA|模块名: counter<br>类名: CounterAttribute<br>方法 or 属性: enableInc(value: boolean): CounterAttribute;|counter.d.ts|
|新增|NA|类名：CustomDialogControllerOptions<br>方法or属性：maskColor?: ResourceColor;|custom_dialog_controller.d.ts|
|新增|NA|类名：CustomDialogControllerOptions<br>方法or属性：openAnimation?: AnimateParam;|custom_dialog_controller.d.ts|
|新增|NA|类名：CustomDialogControllerOptions<br>方法or属性：closeAnimation?: AnimateParam;|custom_dialog_controller.d.ts|
|新增|NA|类名：CustomDialogControllerOptions<br>方法or属性：showInSubWindow?: boolean;|custom_dialog_controller.d.ts|
|新增|NA|模块名: data_panel<br>类名: LinearGradient|data_panel.d.ts|
|新增|NA|模块名: data_panel<br>类名: LinearGradient<br>方法 or 属性: constructor(colorStops: ColorStop[]);|data_panel.d.ts|
|新增|NA|模块名: data_panel<br>类名: DataPanelShadowOption|data_panel.d.ts|
|新增|NA|模块名: data_panel<br>类名: DataPanelShadowOption<br>方法 or 属性: radius?: number \| Resource;|data_panel.d.ts|
|新增|NA|模块名: data_panel<br>类名: DataPanelShadowOption<br>方法 or 属性: colors?: Array\<ResourceColor \| LinearGradient>;|data_panel.d.ts|
|新增|NA|模块名: data_panel<br>类名: DataPanelShadowOption<br>方法 or 属性: offsetX?: number \| Resource;|data_panel.d.ts|
|新增|NA|模块名: data_panel<br>类名: DataPanelShadowOption<br>方法 or 属性: offsetY?: number \| Resource;|data_panel.d.ts|
|新增|NA|模块名: data_panel<br>类名: DataPanelAttribute<br>方法 or 属性: valueColors(value: Array\<ResourceColor \| LinearGradient>): DataPanelAttribute;|data_panel.d.ts|
|新增|NA|模块名: data_panel<br>类名: DataPanelAttribute<br>方法 or 属性: trackBackgroundColor(value: ResourceColor): DataPanelAttribute;|data_panel.d.ts|
|新增|NA|模块名: data_panel<br>类名: DataPanelAttribute<br>方法 or 属性: strokeWidth(value: Length): DataPanelAttribute;|data_panel.d.ts|
|新增|NA|模块名: data_panel<br>类名: DataPanelAttribute<br>方法 or 属性: trackShadow(value: DataPanelShadowOption): DataPanelAttribute;|data_panel.d.ts|
|新增|NA|类名：DatePickerAttribute<br>方法or属性：disappearTextStyle(value: PickerTextStyle): DatePickerAttribute;|date_picker.d.ts|
|新增|NA|类名：DatePickerAttribute<br>方法or属性：textStyle(value: PickerTextStyle): DatePickerAttribute;|date_picker.d.ts|
|新增|NA|类名：DatePickerAttribute<br>方法or属性：selectedTextStyle(value: PickerTextStyle): DatePickerAttribute;|date_picker.d.ts|
|新增|NA|类名：DatePickerDialogOptions<br>方法or属性：showTime?: boolean;|date_picker.d.ts|
|新增|NA|类名：DatePickerDialogOptions<br>方法or属性：useMilitaryTime?: boolean;|date_picker.d.ts|
|新增|NA|类名：DatePickerDialogOptions<br>方法or属性：disappearTextStyle?: PickerTextStyle;|date_picker.d.ts|
|新增|NA|类名：DatePickerDialogOptions<br>方法or属性：textStyle?: PickerTextStyle;|date_picker.d.ts|
|新增|NA|类名：DatePickerDialogOptions<br>方法or属性：selectedTextStyle?: PickerTextStyle;|date_picker.d.ts|
|新增|NA|模块名: enums<br>类名: ColoringStrategy|enums.d.ts|
|新增|NA|模块名: enums<br>类名: ColoringStrategy<br>方法 or 属性：INVERT = "invert"|enums.d.ts|
|新增|NA|模块名: enums<br>类名: TextAlign<br>方法 or 属性：Justify|enums.d.ts|
|新增|NA|模块名: enums<br>类名: TextAlign<br>方法 or 属性：JUSTIFY|enums.d.ts|
|新增|NA|模块名: enums<br>类名: TextOverflow<br>方法 or 属性：Marquee|enums.d.ts|
|新增|NA|模块名: enums<br>类名: TextOverflow<br>方法 or 属性：MARQUEE|enums.d.ts|
|新增|NA|模块名: enums<br>类名: TextHeightAdaptivePolicy|enums.d.ts|
|新增|NA|模块名: enums<br>类名: TextHeightAdaptivePolicy<br>方法 or 属性：MAX_LINES_FIRST|enums.d.ts|
|新增|NA|模块名: enums<br>类名: TextHeightAdaptivePolicy<br>方法 or 属性：MIN_FONT_SIZE_FIRST|enums.d.ts|
|新增|NA|模块名: enums<br>类名: TextHeightAdaptivePolicy<br>方法 or 属性：LAYOUT_CONSTRAINT_FIRST|enums.d.ts|
|新增|NA|模块名: enums<br>类名: ModifierKey|enums.d.ts|
|新增|NA|模块名: enums<br>类名: ModifierKey<br>方法 or 属性：CTRL|enums.d.ts|
|新增|NA|模块名: enums<br>类名: ModifierKey<br>方法 or 属性：SHIFT|enums.d.ts|
|新增|NA|模块名: enums<br>类名: ModifierKey<br>方法 or 属性：ALT|enums.d.ts|
|新增|NA|模块名: enums<br>类名: FunctionKey|enums.d.ts|
|新增|NA|模块名: enums<br>类名: FunctionKey<br>方法 or 属性：ESC|enums.d.ts|
|新增|NA|模块名: enums<br>类名: FunctionKey<br>方法 or 属性：F1|enums.d.ts|
|新增|NA|模块名: enums<br>类名: FunctionKey<br>方法 or 属性：F2|enums.d.ts|
|新增|NA|模块名: enums<br>类名: FunctionKey<br>方法 or 属性：F3|enums.d.ts|
|新增|NA|模块名: enums<br>类名: FunctionKey<br>方法 or 属性：F4|enums.d.ts|
|新增|NA|模块名: enums<br>类名: FunctionKey<br>方法 or 属性：F5|enums.d.ts|
|新增|NA|模块名: enums<br>类名: FunctionKey<br>方法 or 属性：F6|enums.d.ts|
|新增|NA|模块名: enums<br>类名: FunctionKey<br>方法 or 属性：F7|enums.d.ts|
|新增|NA|模块名: enums<br>类名: FunctionKey<br>方法 or 属性：F8|enums.d.ts|
|新增|NA|模块名: enums<br>类名: FunctionKey<br>方法 or 属性：F9|enums.d.ts|
|新增|NA|模块名: enums<br>类名: FunctionKey<br>方法 or 属性：F10|enums.d.ts|
|新增|NA|模块名: enums<br>类名: FunctionKey<br>方法 or 属性：F11|enums.d.ts|
|新增|NA|模块名: enums<br>类名: FunctionKey<br>方法 or 属性：F12|enums.d.ts|
|新增|NA|模块名: enums<br>类名: ImageSpanAlignment|enums.d.ts|
|新增|NA|模块名: enums<br>类名: ImageSpanAlignment<br>方法 or 属性：BASELINE|enums.d.ts|
|新增|NA|模块名: enums<br>类名: ImageSpanAlignment<br>方法 or 属性：BOTTOM|enums.d.ts|
|新增|NA|模块名: enums<br>类名: ImageSpanAlignment<br>方法 or 属性：CENTER|enums.d.ts|
|新增|NA|模块名: enums<br>类名: ImageSpanAlignment<br>方法 or 属性：TOP|enums.d.ts|
|新增|NA|模块名: form_component<br>类名: FormComponentAttribute<br>方法 or 属性: onLoad(callback: () => void): FormComponentAttribute;|form_component.d.ts|
|新增|NA|类名：GridAttribute<br>方法or属性：edgeEffect(value: EdgeEffect): GridAttribute;|grid.d.ts|
|新增|NA|类名：GridRowAttribute<br>方法or属性：alignItems(value: ItemAlign): GridRowAttribute;|grid_row.d.ts|
|新增|NA|类名：ImageAttribute<br>方法or属性：onError(callback: (event?: {<br>    /**<br>     * Component width.<br>     * @form<br>     * @crossplatform<br>     * @since 10<br>     */<br>    componentWidth: number;<br><br>    /**<br>     * Component height.<br>     * @form<br>     * @crossplatform<br>     * @since 10<br>     */<br>    componentHeight: number<br>  }) => void): ImageAttribute;|image.d.ts|
|新增|NA|类名：ImageAttribute<br>方法or属性：onError(callback: (event?: {<br>    /**<br>     * Component width.<br>     * @form<br>     * @crossplatform<br>     * @since 10<br>     */<br>    componentWidth: number;<br><br>    /**<br>     * Component height.<br>     * @form<br>     * @crossplatform<br>     * @since 10<br>     */<br>    componentHeight: number;<br><br>    /**<br>     * Message.<br>     * @form<br>     * @crossplatform<br>     * @since 10<br>     */<br>    message: string<br>  }) => void): ImageAttribute;|image.d.ts|
|新增|NA|模块名: image_span<br>类名: ImageSpanInterface|image_span.d.ts|
|新增|NA|模块名: image_span<br>类名: ImageSpanInterface<br>方法 or 属性: (value: ResourceStr \| PixelMap): ImageSpanAttribute;|image_span.d.ts|
|新增|NA|模块名: image_span<br>类名: ImageSpanAttribute|image_span.d.ts|
|新增|NA|模块名: image_span<br>类名: ImageSpanAttribute<br>方法 or 属性: verticalAlign(value: ImageSpanAlignment): ImageSpanAttribute;|image_span.d.ts|
|新增|NA|模块名: image_span<br>类名: ImageSpanAttribute<br>方法 or 属性: objectFit(value: ImageFit): ImageSpanAttribute;|image_span.d.ts|
|新增|NA|模块名: image_span<br>类名: global<br>方法 or 属性: declare const ImageSpan: ImageSpanInterface;|image_span.d.ts|
|新增|NA|模块名: image_span<br>类名: global<br>方法 or 属性: declare const ImageSpanInstance: ImageSpanAttribute;|image_span.d.ts|
|新增|NA|模块名: list<br>类名: ChainEdgeEffect|list.d.ts|
|新增|NA|模块名: list<br>类名: ChainEdgeEffect<br>方法 or 属性：DEFAULT|list.d.ts|
|新增|NA|模块名: list<br>类名: ChainEdgeEffect<br>方法 or 属性：STRETCH|list.d.ts|
|新增|NA|模块名: list<br>类名: ChainAnimationOptions|list.d.ts|
|新增|NA|模块名: list<br>类名: ChainAnimationOptions<br>方法 or 属性：minSpace: Length;|list.d.ts|
|新增|NA|模块名: list<br>类名: ChainAnimationOptions<br>方法 or 属性：maxSpace: Length;|list.d.ts|
|新增|NA|模块名: list<br>类名: ChainAnimationOptions<br>方法 or 属性：conductivity?: number;|list.d.ts|
|新增|NA|模块名: list<br>类名: ChainAnimationOptions<br>方法 or 属性：intensity?: number;|list.d.ts|
|新增|NA|模块名: list<br>类名: ChainAnimationOptions<br>方法 or 属性：edgeEffect?: ChainEdgeEffect;|list.d.ts|
|新增|NA|类名：ListAttribute<br>方法or属性：chainAnimationOptions(value: ChainAnimationOptions): ListAttribute;|list.d.ts|
|新增|NA|模块名: matrix2d<br>类名: Matrix2D|matrix2d.d.ts|
|新增|NA|模块名: matrix2d<br>类名: Matrix2D<br>方法 or 属性: scaleX?: number;|matrix2d.d.ts|
|新增|NA|模块名: matrix2d<br>类名: Matrix2D<br>方法 or 属性: rotateY?: number;|matrix2d.d.ts|
|新增|NA|模块名: matrix2d<br>类名: Matrix2D<br>方法 or 属性: rotateX?: number;|matrix2d.d.ts|
|新增|NA|模块名: matrix2d<br>类名: Matrix2D<br>方法 or 属性: scaleY?: number;|matrix2d.d.ts|
|新增|NA|模块名: matrix2d<br>类名: Matrix2D<br>方法 or 属性: translateX?: number;|matrix2d.d.ts|
|新增|NA|模块名: matrix2d<br>类名: Matrix2D<br>方法 or 属性: translateY?: number;|matrix2d.d.ts|
|新增|NA|模块名: matrix2d<br>类名: Matrix2D<br>方法 or 属性: identity(): Matrix2D;|matrix2d.d.ts|
|新增|NA|模块名: matrix2d<br>类名: Matrix2D<br>方法 or 属性: invert(): Matrix2D;|matrix2d.d.ts|
|新增|NA|模块名: matrix2d<br>类名: Matrix2D<br>方法 or 属性: multiply(other?: Matrix2D): Matrix2D;|matrix2d.d.ts|
|新增|NA|模块名: matrix2d<br>类名: Matrix2D<br>方法 or 属性: rotate(rx?: number, ry?: number): Matrix2D;|matrix2d.d.ts|
|新增|NA|模块名: matrix2d<br>类名: Matrix2D<br>方法 or 属性: rotate(degree: number, rx?: number, ry?: number): Matrix2D;|matrix2d.d.ts|
|新增|NA|模块名: matrix2d<br>类名: Matrix2D<br>方法 or 属性: translate(tx?: number, ty?: number): Matrix2D;|matrix2d.d.ts|
|新增|NA|模块名: matrix2d<br>类名: Matrix2D<br>方法 or 属性: scale(sx?: number, sy?: number): Matrix2D;|matrix2d.d.ts|
|新增|NA|模块名: matrix2d<br>类名: Matrix2D<br>方法 or 属性: constructor();|matrix2d.d.ts|
|新增|NA|类名：MenuAttribute<br>方法or属性：font(value: Font): MenuAttribute;|menu.d.ts|
|新增|NA|类名：MenuAttribute<br>方法or属性：fontColor(value: ResourceColor): MenuAttribute;|menu.d.ts|
|新增|NA|类名：MenuItemAttribute<br>方法or属性：contentFont(value: Font): MenuItemAttribute;|menu_item.d.ts|
|新增|NA|类名：MenuItemAttribute<br>方法or属性：contentFontColor(value: ResourceColor): MenuItemAttribute;|menu_item.d.ts|
|新增|NA|类名：MenuItemAttribute<br>方法or属性：labelFont(value: Font): MenuItemAttribute;|menu_item.d.ts|
|新增|NA|类名：MenuItemAttribute<br>方法or属性：labelFontColor(value: ResourceColor): MenuItemAttribute;|menu_item.d.ts|
|新增|NA|模块名: navigation<br>类名: NavPathInfo|navigation.d.ts|
|新增|NA|模块名: navigation<br>类名: NavPathInfo<br>方法 or 属性：constructor(name: string, param: unknown);|navigation.d.ts|
|新增|NA|模块名: navigation<br>类名: NavPathInfo<br>方法 or 属性：name: string;|navigation.d.ts|
|新增|NA|模块名: navigation<br>类名: NavPathInfo<br>方法 or 属性：param?: unknown;|navigation.d.ts|
|新增|NA|模块名: navigation<br>类名: NavPathStack|navigation.d.ts|
|新增|NA|模块名: navigation<br>类名: NavPathStack<br>方法 or 属性：constructor();|navigation.d.ts|
|新增|NA|模块名: navigation<br>类名: NavPathStack<br>方法 or 属性：push(info: NavPathInfo): void;|navigation.d.ts|
|新增|NA|模块名: navigation<br>类名: NavPathStack<br>方法 or 属性：pushName(name: string, param: unknown): void;|navigation.d.ts|
|新增|NA|模块名: navigation<br>类名: NavPathStack<br>方法 or 属性：pop(): NavPathInfo \| undefined;|navigation.d.ts|
|新增|NA|模块名: navigation<br>类名: NavPathStack<br>方法 or 属性：popTo(name: string): number;|navigation.d.ts|
|新增|NA|模块名: navigation<br>类名: NavPathStack<br>方法 or 属性：popToIndex(index: number): void;|navigation.d.ts|
|新增|NA|模块名: navigation<br>类名: NavPathStack<br>方法 or 属性：moveToTop(name: string): number;|navigation.d.ts|
|新增|NA|模块名: navigation<br>类名: NavPathStack<br>方法 or 属性：moveIndexToTop(index: number): void;|navigation.d.ts|
|新增|NA|模块名: navigation<br>类名: NavPathStack<br>方法 or 属性：clear(): void;|navigation.d.ts|
|新增|NA|模块名: navigation<br>类名: NavPathStack<br>方法 or 属性：getAllPathName(): Array\<string>;|navigation.d.ts|
|新增|NA|模块名: navigation<br>类名: NavPathStack<br>方法 or 属性：getParamByIndex(index: number): unknown \| undefined;|navigation.d.ts|
|新增|NA|模块名: navigation<br>类名: NavPathStack<br>方法 or 属性：getParamByName(name: string): Array\<unknown>;|navigation.d.ts|
|新增|NA|模块名: navigation<br>类名: NavPathStack<br>方法 or 属性：getIndexByName(name: string): Array\<number>;|navigation.d.ts|
|新增|NA|模块名: navigation<br>类名: NavPathStack<br>方法 or 属性：size(): number;|navigation.d.ts|
|新增|NA|类名：NavigationInterface<br>方法or属性：(pathInfos: NavPathStack): NavigationAttribute;|navigation.d.ts|
|新增|NA|类名：NavigationAttribute<br>方法or属性：navDestination(builder: (name: string, param: unknown) => void): NavigationAttribute;|navigation.d.ts|
|新增|NA|类名：NavDestinationAttribute<br>方法or属性：onShown(callback: (param: unknown) => void): NavDestinationAttribute;|nav_destination.d.ts|
|新增|NA|类名：NavDestinationAttribute<br>方法or属性：onHidden(callback: () => void): NavDestinationAttribute;|nav_destination.d.ts|
|新增|NA|类名：NavDestinationAttribute<br>方法or属性：onBackPressed(callback: () => boolean): NavDestinationAttribute;|nav_destination.d.ts|
|新增|NA|模块名: nav_router<br>类名: RouteInfo|nav_router.d.ts|
|新增|NA|模块名: nav_router<br>类名: RouteInfo<br>方法 or 属性：name: string;|nav_router.d.ts|
|新增|NA|模块名: nav_router<br>类名: RouteInfo<br>方法 or 属性：param?: unknown;|nav_router.d.ts|
|新增|NA|类名：NavRouterInterface<br>方法or属性：(value: RouteInfo): NavRouterAttribute;|nav_router.d.ts|
|新增|NA|模块名: nav_router<br>类名: NavRouteMode|nav_router.d.ts|
|新增|NA|模块名: nav_router<br>类名: NavRouteMode<br>方法 or 属性：PUSH_WITH_RECREATE|nav_router.d.ts|
|新增|NA|模块名: nav_router<br>类名: NavRouteMode<br>方法 or 属性：PUSH|nav_router.d.ts|
|新增|NA|模块名: nav_router<br>类名: NavRouteMode<br>方法 or 属性：REPLACE|nav_router.d.ts|
|新增|NA|类名：NavRouterAttribute<br>方法or属性：mode(mode: NavRouteMode): NavRouterAttribute;|nav_router.d.ts|
|新增|NA|模块名: radio<br>类名: RadioStyle|radio.d.ts|
|新增|NA|模块名: radio<br>类名: RadioStyle<br>方法 or 属性: checkedBackgroundColor?: ResourceColor;|radio.d.ts|
|新增|NA|模块名: radio<br>类名: RadioStyle<br>方法 or 属性: uncheckedBorderColor?: ResourceColor;|radio.d.ts|
|新增|NA|模块名: radio<br>类名: RadioStyle<br>方法 or 属性: indicatorColor?: ResourceColor;|radio.d.ts|
|新增|NA|模块名: radio<br>类名: RadioAttribute<br>方法 or 属性: radioStyle(value?: RadioStyle): RadioAttribute;|radio.d.ts|
|新增|NA|模块名: refresh<br>类名: RefreshOptions|refresh.d.ts|
|新增|NA|模块名: refresh<br>类名: RefreshOptions<br>方法 or 属性：refreshing: boolean;|refresh.d.ts|
|新增|NA|模块名: refresh<br>类名: RefreshOptions<br>方法 or 属性：offset?: number \| string;|refresh.d.ts|
|新增|NA|模块名: refresh<br>类名: RefreshOptions<br>方法 or 属性：friction?: number \| string;|refresh.d.ts|
|新增|NA|模块名: refresh<br>类名: RefreshOptions<br>方法 or 属性：builder?: CustomBuilder;|refresh.d.ts|
|新增|NA|模块名: search<br>类名: CancelButtonStyle|search.d.ts|
|新增|NA|模块名: search<br>类名: CancelButtonStyle<br>方法 or 属性：CONSTANT|search.d.ts|
|新增|NA|模块名: search<br>类名: CancelButtonStyle<br>方法 or 属性：INVISIBLE|search.d.ts|
|新增|NA|模块名: search<br>类名: CancelButtonStyle<br>方法 or 属性：INPUT|search.d.ts|
|新增|NA|模块名: search<br>类名: IconOptions|search.d.ts|
|新增|NA|模块名: search<br>类名: IconOptions<br>方法 or 属性：size?: Length;|search.d.ts|
|新增|NA|模块名: search<br>类名: IconOptions<br>方法 or 属性：color?: ResourceColor;|search.d.ts|
|新增|NA|模块名: search<br>类名: IconOptions<br>方法 or 属性：src?: ResourceStr;|search.d.ts|
|新增|NA|模块名: search<br>类名: CaretStyle|search.d.ts|
|新增|NA|模块名: search<br>类名: CaretStyle<br>方法 or 属性：width?: Length,|search.d.ts|
|新增|NA|模块名: search<br>类名: CaretStyle<br>方法 or 属性：color?: ResourceColor,|search.d.ts|
|新增|NA|模块名: search<br>类名: SearchButtonOption|search.d.ts|
|新增|NA|模块名: search<br>类名: SearchButtonOption<br>方法 or 属性：fontSize?: Length;|search.d.ts|
|新增|NA|模块名: search<br>类名: SearchButtonOption<br>方法 or 属性：fontColor?: ResourceColor;|search.d.ts|
|新增|NA|类名：SearchAttribute<br>方法or属性：fontColor(value: ResourceColor): SearchAttribute;|search.d.ts|
|新增|NA|类名：SearchAttribute<br>方法or属性：searchIcon(value: IconOptions): SearchAttribute;|search.d.ts|
|新增|NA|类名：SearchAttribute<br>方法or属性：cancelButton(value: { style?: CancelButtonStyle, icon?: IconOptions }): SearchAttribute;|search.d.ts|
|新增|NA|类名：SearchAttribute<br>方法or属性：caretStyle(value: CaretStyle): SearchAttribute;|search.d.ts|
|新增|NA|类名：SearchAttribute<br>方法or属性：enableKeyboardOnFocus(value: boolean): SearchAttribute;|search.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: SecLocationButtonLayoutDirection|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: SecLocationButtonLayoutDirection<br>方法 or 属性: HORIZONTAL = 0|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: SecLocationButtonLayoutDirection<br>方法 or 属性: VERTICAL = 1|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: SecLocationButtonLayoutOrder|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: SecLocationButtonLayoutOrder<br>方法 or 属性: ICON_FIRST = 0|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: SecLocationButtonLayoutOrder<br>方法 or 属性: TEXT_FIRST = 1|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: LocationIconStyle|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: LocationIconStyle<br>方法 or 属性: FULL_FILLED = 0|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: LocationIconStyle<br>方法 or 属性: LINES = 1|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: LocationDescription|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: LocationDescription<br>方法 or 属性: CURRENT_LOCATION = 0|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: LocationDescription<br>方法 or 属性: ADD_LOCATION = 1|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: LocationDescription<br>方法 or 属性: SELECT_LOCATION = 2|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: LocationDescription<br>方法 or 属性: SHARE_LOCATION = 3|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: LocationDescription<br>方法 or 属性: SEND_LOCATION = 4|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: LocationDescription<br>方法 or 属性: LOCATING = 5|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: LocationDescription<br>方法 or 属性: LOCATION = 6|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: LocationDescription<br>方法 or 属性: SEND_CURRENT_LOCATION = 7|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: LocationDescription<br>方法 or 属性: RELOCATION = 8|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: LocationDescription<br>方法 or 属性: PUNCH_IN = 9|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: LocationDescription<br>方法 or 属性: CURRENT_POSITION = 10|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: BackgroundButtonType|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: BackgroundButtonType<br>方法 or 属性: CAPSULE_BACKGROUND = 0|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: BackgroundButtonType<br>方法 or 属性: CIRCLE_BACKGROUND = 1|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: BackgroundButtonType<br>方法 or 属性: NORMAL_BACKGROUND = 2|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: SecLocationButtonOptions|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: SecLocationButtonOptions<br>方法 or 属性: icon?: LocationIconStyle;|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: SecLocationButtonOptions<br>方法 or 属性: text?: LocationDescription;|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: SecLocationButtonOptions<br>方法 or 属性: background?: BackgroundButtonType;|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: SecLocationButtonOnClickResult|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: SecLocationButtonOnClickResult<br>方法 or 属性: LOCATION_BUTTON_CLICK_SUCCESS = 0|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: SecLocationButtonOnClickResult<br>方法 or 属性: LOCATION_BUTTON_CLICK_GRANT_FAILED = 1|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: SecLocationButtonInterface|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: SecLocationButtonInterface<br>方法 or 属性: (): SecLocationButtonAttribute;|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: SecLocationButtonInterface<br>方法 or 属性: (option: SecLocationButtonOptions): SecLocationButtonAttribute;|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: SecLocationButtonAttribute|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: SecLocationButtonAttribute<br>方法 or 属性: iconSize(value: Length): SecLocationButtonAttribute;|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: SecLocationButtonAttribute<br>方法 or 属性: layoutDirection(value: SecLocationButtonLayoutDirection): SecLocationButtonAttribute;|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: SecLocationButtonAttribute<br>方法 or 属性: layoutOrder(value: SecLocationButtonLayoutOrder): SecLocationButtonAttribute;|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: SecLocationButtonAttribute<br>方法 or 属性: position(value: Position): SecLocationButtonAttribute;|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: SecLocationButtonAttribute<br>方法 or 属性: markAnchor(value: Position): SecLocationButtonAttribute;|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: SecLocationButtonAttribute<br>方法 or 属性: offset(value: Position): SecLocationButtonAttribute;|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: SecLocationButtonAttribute<br>方法 or 属性: fontSize(value: Length): SecLocationButtonAttribute;|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: SecLocationButtonAttribute<br>方法 or 属性: fontStyle(value: FontStyle): SecLocationButtonAttribute;|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: SecLocationButtonAttribute<br>方法 or 属性: fontWeight(value: number \| FontWeight \| string): SecLocationButtonAttribute;|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: SecLocationButtonAttribute<br>方法 or 属性: fontFamily(value: string \| Resource): SecLocationButtonAttribute;|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: SecLocationButtonAttribute<br>方法 or 属性: fontColor(value: ResourceColor): SecLocationButtonAttribute;|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: SecLocationButtonAttribute<br>方法 or 属性: iconColor(value: ResourceColor): SecLocationButtonAttribute;|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: SecLocationButtonAttribute<br>方法 or 属性: backgroundColor(value: ResourceColor): SecLocationButtonAttribute;|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: SecLocationButtonAttribute<br>方法 or 属性: borderStyle(value: BorderStyle): SecLocationButtonAttribute;|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: SecLocationButtonAttribute<br>方法 or 属性: borderWidth(value: Length): SecLocationButtonAttribute;|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: SecLocationButtonAttribute<br>方法 or 属性: borderColor(value: ResourceColor): SecLocationButtonAttribute;|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: SecLocationButtonAttribute<br>方法 or 属性: borderRadius(value: Length): SecLocationButtonAttribute;|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: SecLocationButtonAttribute<br>方法 or 属性: backgroundPadding(value: Padding \| Length): SecLocationButtonAttribute;|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: SecLocationButtonAttribute<br>方法 or 属性: textIconPadding(value: Length): SecLocationButtonAttribute;|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: SecLocationButtonAttribute<br>方法 or 属性: onClick(event: (result: SecLocationButtonOnClickResult, event?: ClickEvent) => void): SecLocationButtonAttribute;|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: global<br>方法 or 属性: declare const SecLocationButton: SecLocationButtonInterface;|sec_location_button.d.ts|
|新增|NA|模块名: sec_location_button<br>类名: global<br>方法 or 属性: declare const SecLocationButtonInstance: SecLocationButtonAttribute;|sec_location_button.d.ts|
|新增|NA|模块名: select<br>类名: ArrowPosition|select.d.ts|
|新增|NA|模块名: select<br>类名: ArrowPosition<br>方法 or 属性：END = 0|select.d.ts|
|新增|NA|模块名: select<br>类名: ArrowPosition<br>方法 or 属性：START = 1|select.d.ts|
|新增|NA|类名：SelectAttribute<br>方法or属性：space(value: Length): SelectAttribute;|select.d.ts|
|新增|NA|类名：SelectAttribute<br>方法or属性：arrowPosition(value: ArrowPosition): SelectAttribute;|select.d.ts|
|新增|NA|模块名: sidebar<br>类名: DividerStyle|sidebar.d.ts|
|新增|NA|模块名: sidebar<br>类名: DividerStyle<br>方法 or 属性：strokeWidth: Length;|sidebar.d.ts|
|新增|NA|模块名: sidebar<br>类名: DividerStyle<br>方法 or 属性：color?: ResourceColor;|sidebar.d.ts|
|新增|NA|模块名: sidebar<br>类名: DividerStyle<br>方法 or 属性：startMargin?: Length;|sidebar.d.ts|
|新增|NA|模块名: sidebar<br>类名: DividerStyle<br>方法 or 属性：endMargin?: Length;|sidebar.d.ts|
|新增|NA|类名：SideBarContainerAttribute<br>方法or属性：divider(value: DividerStyle \| null): SideBarContainerAttribute;|sidebar.d.ts|
|新增|NA|模块名: slider<br>类名: SliderBlockType|slider.d.ts|
|新增|NA|模块名: slider<br>类名: SliderBlockType<br>方法 or 属性: DEFAULT|slider.d.ts|
|新增|NA|模块名: slider<br>类名: SliderBlockType<br>方法 or 属性: IMAGE|slider.d.ts|
|新增|NA|模块名: slider<br>类名: SliderBlockType<br>方法 or 属性: SHAPE|slider.d.ts|
|新增|NA|模块名: slider<br>类名: SliderBlockStyle|slider.d.ts|
|新增|NA|模块名: slider<br>类名: SliderBlockStyle<br>方法 or 属性: type: SliderBlockType;|slider.d.ts|
|新增|NA|模块名: slider<br>类名: SliderBlockStyle<br>方法 or 属性: image?: ResourceStr;|slider.d.ts|
|新增|NA|模块名: slider<br>类名: SliderBlockStyle<br>方法 or 属性: shape?: CircleAttribute \| EllipseAttribute \| PathAttribute \| RectAttribute;|slider.d.ts|
|新增|NA|模块名: slider<br>类名: SliderAttribute<br>方法 or 属性: blockBorderColor(value: ResourceColor): SliderAttribute;|slider.d.ts|
|新增|NA|模块名: slider<br>类名: SliderAttribute<br>方法 or 属性: blockBorderWidth(value: Length): SliderAttribute;|slider.d.ts|
|新增|NA|模块名: slider<br>类名: SliderAttribute<br>方法 or 属性: stepColor(value: ResourceColor): SliderAttribute;|slider.d.ts|
|新增|NA|模块名: slider<br>类名: SliderAttribute<br>方法 or 属性: trackBorderRadius(value: Length): SliderAttribute;|slider.d.ts|
|新增|NA|模块名: slider<br>类名: SliderAttribute<br>方法 or 属性: blockSize(value: SizeOptions): SliderAttribute;|slider.d.ts|
|新增|NA|模块名: slider<br>类名: SliderAttribute<br>方法 or 属性: blockStyle(value: SliderBlockStyle): SliderAttribute;|slider.d.ts|
|新增|NA|模块名: slider<br>类名: SliderAttribute<br>方法 or 属性: stepSize(value: Length): SliderAttribute;|slider.d.ts|
|新增|NA|模块名: swiper<br>类名: Indicator|swiper.d.ts|
|新增|NA|模块名: swiper<br>类名: Indicator<br>方法 or 属性：left(value: Length): T;|swiper.d.ts|
|新增|NA|模块名: swiper<br>类名: Indicator<br>方法 or 属性：top(value: Length): T;|swiper.d.ts|
|新增|NA|模块名: swiper<br>类名: Indicator<br>方法 or 属性：right(value: Length): T;|swiper.d.ts|
|新增|NA|模块名: swiper<br>类名: Indicator<br>方法 or 属性：bottom(value: Length): T;|swiper.d.ts|
|新增|NA|模块名: swiper<br>类名: Indicator<br>方法 or 属性：static dot(): DotIndicator;|swiper.d.ts|
|新增|NA|模块名: swiper<br>类名: Indicator<br>方法 or 属性：static digit(): DigitIndicator;|swiper.d.ts|
|新增|NA|模块名: swiper<br>类名: DotIndicator|swiper.d.ts|
|新增|NA|模块名: swiper<br>类名: DotIndicator<br>方法 or 属性：constructor();|swiper.d.ts|
|新增|NA|模块名: swiper<br>类名: DotIndicator<br>方法 or 属性：itemWidth(value: Length): DotIndicator;|swiper.d.ts|
|新增|NA|模块名: swiper<br>类名: DotIndicator<br>方法 or 属性：itemHeight(value: Length): DotIndicator;|swiper.d.ts|
|新增|NA|模块名: swiper<br>类名: DotIndicator<br>方法 or 属性：selectedItemWidth(value: Length): DotIndicator;|swiper.d.ts|
|新增|NA|模块名: swiper<br>类名: DotIndicator<br>方法 or 属性：selectedItemHeight(value: Length): DotIndicator;|swiper.d.ts|
|新增|NA|模块名: swiper<br>类名: DotIndicator<br>方法 or 属性：mask(value: boolean): DotIndicator;|swiper.d.ts|
|新增|NA|模块名: swiper<br>类名: DotIndicator<br>方法 or 属性：color(value: ResourceColor): DotIndicator;|swiper.d.ts|
|新增|NA|模块名: swiper<br>类名: DotIndicator<br>方法 or 属性：selectedColor(value: ResourceColor): DotIndicator;|swiper.d.ts|
|新增|NA|模块名: swiper<br>类名: DigitIndicator|swiper.d.ts|
|新增|NA|模块名: swiper<br>类名: DigitIndicator<br>方法 or 属性：constructor();|swiper.d.ts|
|新增|NA|模块名: swiper<br>类名: DigitIndicator<br>方法 or 属性：fontColor(value: ResourceColor): DigitIndicator;|swiper.d.ts|
|新增|NA|模块名: swiper<br>类名: DigitIndicator<br>方法 or 属性：selectedFontColor(value: ResourceColor): DigitIndicator;|swiper.d.ts|
|新增|NA|模块名: swiper<br>类名: DigitIndicator<br>方法 or 属性：digitFont(value: Font): DigitIndicator;|swiper.d.ts|
|新增|NA|模块名: swiper<br>类名: DigitIndicator<br>方法 or 属性：selectedDigitFont(value: Font): DigitIndicator;|swiper.d.ts|
|新增|NA|类名：SwiperDisplayMode<br>方法or属性：STRETCH|swiper.d.ts|
|新增|NA|类名：SwiperDisplayMode<br>方法or属性：AUTO_LINEAR|swiper.d.ts|
|新增|NA|类名：SwiperAttribute<br>方法or属性：prevMargin(value: Length): SwiperAttribute;|swiper.d.ts|
|新增|NA|类名：SwiperAttribute<br>方法or属性：nextMargin(value: Length): SwiperAttribute;|swiper.d.ts|
|新增|NA|模块名: tabs<br>类名: DividerStyle|tabs.d.ts|
|新增|NA|模块名: tabs<br>类名: DividerStyle<br>方法 or 属性：strokeWidth: Length;|tabs.d.ts|
|新增|NA|模块名: tabs<br>类名: DividerStyle<br>方法 or 属性：color?: ResourceColor;|tabs.d.ts|
|新增|NA|模块名: tabs<br>类名: DividerStyle<br>方法 or 属性：startMargin?: Length;|tabs.d.ts|
|新增|NA|模块名: tabs<br>类名: DividerStyle<br>方法 or 属性：endMargin?: Length;|tabs.d.ts|
|新增|NA|类名：TabsAttribute<br>方法or属性：fadingEdge(value: boolean): TabsAttribute;|tabs.d.ts|
|新增|NA|类名：TabsAttribute<br>方法or属性：divider(value: DividerStyle \| null): TabsAttribute;|tabs.d.ts|
|新增|NA|模块名: tab_content<br>类名: SelectedMode|tab_content.d.ts|
|新增|NA|模块名: tab_content<br>类名: SelectedMode<br>方法 or 属性：INDICATOR|tab_content.d.ts|
|新增|NA|模块名: tab_content<br>类名: SelectedMode<br>方法 or 属性：BOARD|tab_content.d.ts|
|新增|NA|模块名: tab_content<br>类名: IndicatorStyle|tab_content.d.ts|
|新增|NA|模块名: tab_content<br>类名: IndicatorStyle<br>方法 or 属性：color?: ResourceColor;|tab_content.d.ts|
|新增|NA|模块名: tab_content<br>类名: IndicatorStyle<br>方法 or 属性：height?: Length;|tab_content.d.ts|
|新增|NA|模块名: tab_content<br>类名: IndicatorStyle<br>方法 or 属性：width?: Length;|tab_content.d.ts|
|新增|NA|模块名: tab_content<br>类名: IndicatorStyle<br>方法 or 属性：borderRadius?: Length;|tab_content.d.ts|
|新增|NA|模块名: tab_content<br>类名: IndicatorStyle<br>方法 or 属性：marginTop?: Length;|tab_content.d.ts|
|新增|NA|模块名: tab_content<br>类名: BoardStyle|tab_content.d.ts|
|新增|NA|模块名: tab_content<br>类名: BoardStyle<br>方法 or 属性：borderRadius?: Length;|tab_content.d.ts|
|新增|NA|模块名: tab_content<br>类名: LabelStyle|tab_content.d.ts|
|新增|NA|模块名: tab_content<br>类名: LabelStyle<br>方法 or 属性：overflow?: TextOverflow;|tab_content.d.ts|
|新增|NA|模块名: tab_content<br>类名: LabelStyle<br>方法 or 属性：maxLines?: number;|tab_content.d.ts|
|新增|NA|模块名: tab_content<br>类名: LabelStyle<br>方法 or 属性：minFontSize?: number \| ResourceStr;|tab_content.d.ts|
|新增|NA|模块名: tab_content<br>类名: LabelStyle<br>方法 or 属性：maxFontSize?: number \| ResourceStr;|tab_content.d.ts|
|新增|NA|模块名: tab_content<br>类名: LabelStyle<br>方法 or 属性：heightAdaptivePolicy?: TextHeightAdaptivePolicy;|tab_content.d.ts|
|新增|NA|模块名: tab_content<br>类名: LabelStyle<br>方法 or 属性：font?: Font;|tab_content.d.ts|
|新增|NA|类名：SubTabBarStyle<br>方法or属性：static of(content: ResourceStr): SubTabBarStyle;|tab_content.d.ts|
|新增|NA|类名：SubTabBarStyle<br>方法or属性：selectedMode(value: SelectedMode): SubTabBarStyle;|tab_content.d.ts|
|新增|NA|类名：SubTabBarStyle<br>方法or属性：board(value: BoardStyle): SubTabBarStyle;|tab_content.d.ts|
|新增|NA|类名：SubTabBarStyle<br>方法or属性：labelStyle(value: LabelStyle): SubTabBarStyle;|tab_content.d.ts|
|新增|NA|类名：BottomTabBarStyle<br>方法or属性：static of(icon: ResourceStr, text: ResourceStr): BottomTabBarStyle;|tab_content.d.ts|
|新增|NA|类名：TextAttribute<br>方法or属性：draggable(value: boolean): TextAttribute;|text.d.ts|
|新增|NA|类名：TextAttribute<br>方法or属性：textShadow(value: ShadowOptions): TextAttribute;|text.d.ts|
|新增|NA|类名：TextAttribute<br>方法or属性：heightAdaptivePolicy(value: TextHeightAdaptivePolicy): TextAttribute;|text.d.ts|
|新增|NA|类名：TextAttribute<br>方法or属性：textIndent(value: Length): TextAttribute;|text.d.ts|
|新增|NA|类名：TextAreaController<br>方法or属性：setTextSelection(selectionStart: number, selectionEnd: number): void;|text_area.d.ts|
|新增|NA|类名：TextAreaAttribute<br>方法or属性：onEditChange(callback: (isEditing: boolean) => void): TextAreaAttribute;|text_area.d.ts|
|新增|NA|类名：TextAreaAttribute<br>方法or属性：enableKeyboardOnFocus(value: boolean): TextAreaInterface;|text_area.d.ts|
|新增|NA|类名：TextInputController<br>方法or属性：setTextSelection(selectionStart: number, selectionEnd: number): void;|text_input.d.ts|
|新增|NA|模块名: text_input<br>类名: CaretStyle|text_input.d.ts|
|新增|NA|模块名: text_input<br>类名: CaretStyle<br>方法 or 属性：width?: Length;|text_input.d.ts|
|新增|NA|类名：TextInputAttribute<br>方法or属性：caretStyle(value: CaretStyle): TextInputAttribute;|text_input.d.ts|
|新增|NA|类名：TextInputAttribute<br>方法or属性：selectedBackgroundColor(value: ResourceColor): TextInputAttribute;|text_input.d.ts|
|新增|NA|类名：TextInputAttribute<br>方法or属性：caretPosition(value: number): TextInputAttribute;|text_input.d.ts|
|新增|NA|类名：TextInputAttribute<br>方法or属性：enableKeyboardOnFocus(value: boolean): TextInputAttribute;|text_input.d.ts|
|新增|NA|模块名: text_picker<br>类名: TextPickerRangeContent|text_picker.d.ts|
|新增|NA|模块名: text_picker<br>类名: TextPickerRangeContent<br>方法 or 属性：icon: string \| Resource;|text_picker.d.ts|
|新增|NA|模块名: text_picker<br>类名: TextPickerRangeContent<br>方法 or 属性：text?: string \| Resource;|text_picker.d.ts|
|新增|NA|类名：TextPickerOptions<br>方法or属性：range: string[] \| Resource \| TextPickerRangeContent[];|text_picker.d.ts|
|新增|NA|类名：TextPickerAttribute<br>方法or属性：disappearTextStyle(value: PickerTextStyle): TextPickerAttribute;|text_picker.d.ts|
|新增|NA|类名：TextPickerAttribute<br>方法or属性：textStyle(value: PickerTextStyle): TextPickerAttribute;|text_picker.d.ts|
|新增|NA|类名：TextPickerAttribute<br>方法or属性：selectedTextStyle(value: PickerTextStyle): TextPickerAttribute;|text_picker.d.ts|
|新增|NA|类名：TextPickerDialogOptions<br>方法or属性：disappearTextStyle?: PickerTextStyle;|text_picker.d.ts|
|新增|NA|类名：TextPickerDialogOptions<br>方法or属性：textStyle?: PickerTextStyle;|text_picker.d.ts|
|新增|NA|类名：TextPickerDialogOptions<br>方法or属性：selectedTextStyle?: PickerTextStyle;|text_picker.d.ts|
|新增|NA|类名：TimePickerAttribute<br>方法or属性：disappearTextStyle(value: PickerTextStyle): TimePickerAttribute;|time_picker.d.ts|
|新增|NA|类名：TimePickerAttribute<br>方法or属性：textStyle(value: PickerTextStyle): TimePickerAttribute;|time_picker.d.ts|
|新增|NA|类名：TimePickerAttribute<br>方法or属性：selectedTextStyle(value: PickerTextStyle): TimePickerAttribute;|time_picker.d.ts|
|新增|NA|类名：TimePickerDialogOptions<br>方法or属性：disappearTextStyle?: PickerTextStyle;|time_picker.d.ts|
|新增|NA|类名：TimePickerDialogOptions<br>方法or属性：textStyle?: PickerTextStyle;|time_picker.d.ts|
|新增|NA|类名：TimePickerDialogOptions<br>方法or属性：selectedTextStyle?: PickerTextStyle;|time_picker.d.ts|
|新增|NA|模块名: units<br>类名: MarkStyle|units.d.ts|
|新增|NA|模块名: units<br>类名: MarkStyle<br>方法 or 属性：strokeColor?: ResourceColor;|units.d.ts|
|新增|NA|模块名: units<br>类名: MarkStyle<br>方法 or 属性：size?: Length;|units.d.ts|
|新增|NA|模块名: units<br>类名: MarkStyle<br>方法 or 属性：strokeWidth?: Length;|units.d.ts|
|新增|NA|模块名: web<br>类名: WebMediaOptions|web.d.ts|
|新增|NA|模块名: web<br>类名: WebMediaOptions<br>方法 or 属性：resumeInterval?: number;|web.d.ts|
|新增|NA|模块名: web<br>类名: WebMediaOptions<br>方法 or 属性：audioExclusive?: boolean;|web.d.ts|
|新增|NA|类名：ClientAuthenticationHandler<br>方法or属性：confirm(authUri: string): void;|web.d.ts|
|新增|NA|类名：WebAttribute<br>方法or属性：mediaOptions(options: WebMediaOptions): WebAttribute;|web.d.ts|
|新增|NA|类名：WebAttribute<br>方法or属性：allowWindowOpenMethod(flag: boolean): WebAttribute;|web.d.ts|
|新增|NA|类名：WebAttribute<br>方法or属性：onAudioStateChanged(callback: (event: { playing: boolean }) => void): WebAttribute;|web.d.ts|
|新增|NA|类名：WebAttribute<br>方法or属性：onFirstContentfulPaint(callback: (event?: { navigationStartTick: number,<br>    firstContentfulPaintMs: number }) => void): WebAttribute;|web.d.ts|
|新增|NA|类名：WebAttribute<br>方法or属性：onLoadIntercept(callback: (event: { data: WebResourceRequest }) => boolean): WebAttribute;|web.d.ts|
|删除|模块名：common<br>类名:SourceTool<br>方法 or 属性:FINGER|NA|common.d.ts|
|删除|模块名：common<br>类名:SourceTool<br>方法 or 属性:PEN|NA|common.d.ts|
|访问级别有变化|类名：BlurStyle<br>访问级别：系统API|类名：BlurStyle<br>访问级别：公开API|common.d.ts|
|访问级别有变化|类名：SubscribedAbstractProperty<br>方法 or 属性：info(): string;<br>访问级别：系统API|类名：SubscribedAbstractProperty<br>方法 or 属性：info(): string;<br>访问级别：公开API|common_ts_ets_api.d.ts|
|废弃版本有变化|类名：ShowToastOptions<br>废弃版本：N/A|类名：ShowToastOptions<br>废弃版本：8<br>代替接口：ohos.prompt |@system.prompt.d.ts|
|废弃版本有变化|类名：TransitionOptions<br>废弃版本：N/A|类名：TransitionOptions<br>废弃版本：10<br>代替接口：TransitionEffect |common.d.ts|
|废弃版本有变化|类名：PopupOptions<br>方法 or 属性：placementOnTop?: boolean;<br>废弃版本：N/A|类名：PopupOptions<br>方法 or 属性：placementOnTop?: boolean;<br>废弃版本：10<br>代替接口：PopupOptions|common.d.ts|
|废弃版本有变化|类名：CustomPopupOptions<br>方法 or 属性：maskColor?: Color \| string \| Resource \| number;<br>废弃版本：N/A|类名：CustomPopupOptions<br>方法 or 属性：maskColor?: Color \| string \| Resource \| number;<br>废弃版本：10<br>代替接口：CustomPopupOptions|common.d.ts|
|废弃版本有变化|类名：CommonMethod<br>方法 or 属性：useSizeType(value: {<br>    xs?: number \| { span: number; offset: number };<br>    sm?: number \| { span: number; offset: number };<br>    md?: number \| { span: number; offset: number };<br>    lg?: number \| { span: number; offset: number };<br>  }): T;<br>废弃版本：N/A|类名：CommonMethod<br>方法 or 属性：useSizeType(value: {<br>    xs?: number \| { span: number; offset: number };<br>    sm?: number \| { span: number; offset: number };<br>    md?: number \| { span: number; offset: number };<br>    lg?: number \| { span: number; offset: number };<br>  }): T;<br>废弃版本：9<br>代替接口：grid_col/|common.d.ts|
|废弃版本有变化|类名：SizeType<br>废弃版本：N/A|类名：SizeType<br>废弃版本：9<br>代替接口：grid_col/|grid_container.d.ts|
|废弃版本有变化|类名：GridContainerOptions<br>废弃版本：N/A|类名：GridContainerOptions<br>废弃版本：9<br>代替接口：grid_col/|grid_container.d.ts|
|废弃版本有变化|类名：GridContainerOptions<br>方法 or 属性：columns?: number \| "auto";<br>废弃版本：N/A|类名：GridContainerOptions<br>方法 or 属性：columns?: number \| "auto";<br>废弃版本：9<br>代替接口：N/A|grid_container.d.ts|
|废弃版本有变化|类名：GridContainerOptions<br>方法 or 属性：sizeType?: SizeType;<br>废弃版本：N/A|类名：GridContainerOptions<br>方法 or 属性：sizeType?: SizeType;<br>废弃版本：9<br>代替接口：N/A|grid_container.d.ts|
|废弃版本有变化|类名：GridContainerOptions<br>方法 or 属性：gutter?: number \| string;<br>废弃版本：N/A|类名：GridContainerOptions<br>方法 or 属性：gutter?: number \| string;<br>废弃版本：9<br>代替接口：N/A|grid_container.d.ts|
|废弃版本有变化|类名：GridContainerOptions<br>方法 or 属性：margin?: number \| string;<br>废弃版本：N/A|类名：GridContainerOptions<br>方法 or 属性：margin?: number \| string;<br>废弃版本：9<br>代替接口：N/A|grid_container.d.ts|
|废弃版本有变化|类名：GridContainerInterface<br>废弃版本：N/A|类名：GridContainerInterface<br>废弃版本：9<br>代替接口：grid_col/|grid_container.d.ts|
|废弃版本有变化|类名：GridContainerInterface<br>方法 or 属性：(value?: GridContainerOptions): GridContainerAttribute;<br>废弃版本：N/A|类名：GridContainerInterface<br>方法 or 属性：(value?: GridContainerOptions): GridContainerAttribute;<br>废弃版本：9<br>代替接口：N/A|grid_container.d.ts|
|废弃版本有变化|类名：GridContainerAttribute<br>废弃版本：N/A|类名：GridContainerAttribute<br>废弃版本：9<br>代替接口：grid_col/|grid_container.d.ts|
|废弃版本有变化|类名：ImageAttribute<br>方法 or 属性：draggable(value: boolean): ImageAttribute;<br>废弃版本：N/A|类名：ImageAttribute<br>方法 or 属性：draggable(value: boolean): ImageAttribute;<br>废弃版本：10<br>代替接口：common.CommonMethod|image.d.ts|
|废弃版本有变化|类名：Sticky<br>废弃版本：N/A|类名：Sticky<br>废弃版本：9<br>代替接口：list/StickyStyle |list_item.d.ts|
|废弃版本有变化|类名：ListItemAttribute<br>方法 or 属性：sticky(value: Sticky): ListItemAttribute;<br>废弃版本：N/A|类名：ListItemAttribute<br>方法 or 属性：sticky(value: Sticky): ListItemAttribute;<br>废弃版本：9<br>代替接口：list/List|list_item.d.ts|
|废弃版本有变化|类名：MenuAttribute<br>方法 or 属性：fontSize(value: Length): MenuAttribute;<br>废弃版本：N/A|类名：MenuAttribute<br>方法 or 属性：fontSize(value: Length): MenuAttribute;<br>废弃版本：10<br>代替接口：font   |menu.d.ts|
|废弃版本有变化|类名：SwiperDisplayMode<br>方法 or 属性：Stretch<br>废弃版本：N/A|类名：SwiperDisplayMode<br>方法 or 属性：Stretch<br>废弃版本：10<br>代替接口：SwiperDisplayMode|swiper.d.ts|
|废弃版本有变化|类名：SwiperDisplayMode<br>方法 or 属性：AutoLinear<br>废弃版本：N/A|类名：SwiperDisplayMode<br>方法 or 属性：AutoLinear<br>废弃版本：10<br>代替接口：SwiperDisplayMode|swiper.d.ts|
|废弃版本有变化|类名：IndicatorStyle<br>废弃版本：N/A|类名：IndicatorStyle<br>废弃版本：10<br>代替接口：N/A|swiper.d.ts|
|废弃版本有变化|类名：SwiperAttribute<br>方法 or 属性：indicatorStyle(value?: IndicatorStyle): SwiperAttribute;<br>废弃版本：N/A|类名：SwiperAttribute<br>方法 or 属性：indicatorStyle(value?: IndicatorStyle): SwiperAttribute;<br>废弃版本：10<br>代替接口：N/A|swiper.d.ts|
|废弃版本有变化|类名：TextPickerAttribute<br>方法 or 属性：onAccept(callback: (value: string, index: number) => void): TextPickerAttribute;<br>废弃版本：N/A|类名：TextPickerAttribute<br>方法 or 属性：onAccept(callback: (value: string, index: number) => void): TextPickerAttribute;<br>废弃版本：10<br>代替接口：N/A|text_picker.d.ts|
|废弃版本有变化|类名：TextPickerAttribute<br>方法 or 属性：onCancel(callback: () => void): TextPickerAttribute;<br>废弃版本：N/A|类名：TextPickerAttribute<br>方法 or 属性：onCancel(callback: () => void): TextPickerAttribute;<br>废弃版本：10<br>代替接口：N/A|text_picker.d.ts|
|废弃版本有变化|类名：WebAttribute<br>方法 or 属性：onUrlLoadIntercept(callback: (event?: { data: string \| WebResourceRequest }) => boolean): WebAttribute;<br>废弃版本：N/A|类名：WebAttribute<br>方法 or 属性：onUrlLoadIntercept(callback: (event?: { data: string \| WebResourceRequest }) => boolean): WebAttribute;<br>废弃版本：10<br>代替接口：ohos.web.WebAttribute|web.d.ts|
|起始版本有变化|类名：<br>方法 or 属性： function setInterval(handler: Function \| string, delay: number, ...arguments: any[]): number;<br>起始版本：7|类名：<br>方法 or 属性： function setInterval(handler: Function \| string, delay: number, ...arguments: any[]): number;<br>起始版本：10|global.d.ts|
|起始版本有变化|类名：<br>方法 or 属性： function setTimeout(handler: Function \| string, delay?: number, ...arguments: any[]): number;<br>起始版本：7|类名：<br>方法 or 属性： function setTimeout(handler: Function \| string, delay?: number, ...arguments: any[]): number;<br>起始版本：10|global.d.ts|
|起始版本有变化|类名：<br>方法 or 属性： function clearInterval(intervalID?: number): void;<br>起始版本：7|类名：<br>方法 or 属性： function clearInterval(intervalID?: number): void;<br>起始版本：10|global.d.ts|
|起始版本有变化|类名：<br>方法 or 属性： function clearTimeout(timeoutID?: number): void;<br>起始版本：7|类名：<br>方法 or 属性： function clearTimeout(timeoutID?: number): void;<br>起始版本：10|global.d.ts|
|起始版本有变化|类名：<br>方法 or 属性： function canIUse(syscap: string): boolean;<br>起始版本：8|类名：<br>方法 or 属性： function canIUse(syscap: string): boolean;<br>起始版本：10|global.d.ts|
|起始版本有变化|类名：<br>方法 or 属性： function getInspectorByKey(id: string): string;<br>起始版本：9|类名：<br>方法 or 属性： function getInspectorByKey(id: string): string;<br>起始版本：10|global.d.ts|
|起始版本有变化|类名：<br>方法 or 属性： function getInspectorTree(): Object;<br>起始版本：9|类名：<br>方法 or 属性： function getInspectorTree(): Object;<br>起始版本：10|global.d.ts|
|起始版本有变化|类名：<br>方法 or 属性： function sendEventByKey(id: string, action: number, params: string): boolean;<br>起始版本：9|类名：<br>方法 or 属性： function sendEventByKey(id: string, action: number, params: string): boolean;<br>起始版本：10|global.d.ts|
|起始版本有变化|类名：<br>方法 or 属性： function sendTouchEvent(event: TouchObject): boolean;<br>起始版本：9|类名：<br>方法 or 属性： function sendTouchEvent(event: TouchObject): boolean;<br>起始版本：10|global.d.ts|
|起始版本有变化|类名：<br>方法 or 属性： function sendKeyEvent(event: KeyEvent): boolean;<br>起始版本：9|类名：<br>方法 or 属性： function sendKeyEvent(event: KeyEvent): boolean;<br>起始版本：10|global.d.ts|
|起始版本有变化|类名：<br>方法 or 属性： function sendMouseEvent(event: MouseEvent): boolean;<br>起始版本：9|类名：<br>方法 or 属性： function sendMouseEvent(event: MouseEvent): boolean;<br>起始版本：10|global.d.ts|
|起始版本有变化|类名：AnimatorOptions<br>起始版本：6|类名：AnimatorOptions<br>起始版本：10|@ohos.animator.d.ts|
|起始版本有变化|类名：AnimatorOptions<br>方法 or 属性：duration: number;<br>起始版本：6|类名：AnimatorOptions<br>方法 or 属性：duration: number;<br>起始版本：10|@ohos.animator.d.ts|
|起始版本有变化|类名：AnimatorOptions<br>方法 or 属性：easing: string;<br>起始版本：6|类名：AnimatorOptions<br>方法 or 属性：easing: string;<br>起始版本：10|@ohos.animator.d.ts|
|起始版本有变化|类名：AnimatorOptions<br>方法 or 属性：delay: number;<br>起始版本：6|类名：AnimatorOptions<br>方法 or 属性：delay: number;<br>起始版本：10|@ohos.animator.d.ts|
|起始版本有变化|类名：AnimatorOptions<br>方法 or 属性：fill: "none" \| "forwards" \| "backwards" \| "both";<br>起始版本：6|类名：AnimatorOptions<br>方法 or 属性：fill: "none" \| "forwards" \| "backwards" \| "both";<br>起始版本：10|@ohos.animator.d.ts|
|起始版本有变化|类名：AnimatorOptions<br>方法 or 属性：direction: "normal" \| "reverse" \| "alternate" \| "alternate-reverse";<br>起始版本：6|类名：AnimatorOptions<br>方法 or 属性：direction: "normal" \| "reverse" \| "alternate" \| "alternate-reverse";<br>起始版本：10|@ohos.animator.d.ts|
|起始版本有变化|类名：AnimatorOptions<br>方法 or 属性：iterations: number;<br>起始版本：6|类名：AnimatorOptions<br>方法 or 属性：iterations: number;<br>起始版本：10|@ohos.animator.d.ts|
|起始版本有变化|类名：AnimatorOptions<br>方法 or 属性：begin: number;<br>起始版本：6|类名：AnimatorOptions<br>方法 or 属性：begin: number;<br>起始版本：10|@ohos.animator.d.ts|
|起始版本有变化|类名：AnimatorOptions<br>方法 or 属性：end: number;<br>起始版本：6|类名：AnimatorOptions<br>方法 or 属性：end: number;<br>起始版本：10|@ohos.animator.d.ts|
|起始版本有变化|类名：AnimatorResult<br>起始版本：6|类名：AnimatorResult<br>起始版本：10|@ohos.animator.d.ts|
|起始版本有变化|类名：AnimatorResult<br>方法 or 属性：reset(options: AnimatorOptions): void;<br>起始版本：9|类名：AnimatorResult<br>方法 or 属性：reset(options: AnimatorOptions): void;<br>起始版本：10|@ohos.animator.d.ts|
|起始版本有变化|类名：AnimatorResult<br>方法 or 属性：play(): void;<br>起始版本：6|类名：AnimatorResult<br>方法 or 属性：play(): void;<br>起始版本：10|@ohos.animator.d.ts|
|起始版本有变化|类名：AnimatorResult<br>方法 or 属性：finish(): void;<br>起始版本：6|类名：AnimatorResult<br>方法 or 属性：finish(): void;<br>起始版本：10|@ohos.animator.d.ts|
|起始版本有变化|类名：AnimatorResult<br>方法 or 属性：pause(): void;<br>起始版本：6|类名：AnimatorResult<br>方法 or 属性：pause(): void;<br>起始版本：10|@ohos.animator.d.ts|
|起始版本有变化|类名：AnimatorResult<br>方法 or 属性：cancel(): void;<br>起始版本：6|类名：AnimatorResult<br>方法 or 属性：cancel(): void;<br>起始版本：10|@ohos.animator.d.ts|
|起始版本有变化|类名：AnimatorResult<br>方法 or 属性：reverse(): void;<br>起始版本：6|类名：AnimatorResult<br>方法 or 属性：reverse(): void;<br>起始版本：10|@ohos.animator.d.ts|
|起始版本有变化|类名：AnimatorResult<br>方法 or 属性：onframe: (progress: number) => void;<br>起始版本：6|类名：AnimatorResult<br>方法 or 属性：onframe: (progress: number) => void;<br>起始版本：10|@ohos.animator.d.ts|
|起始版本有变化|类名：AnimatorResult<br>方法 or 属性：onfinish: () => void;<br>起始版本：6|类名：AnimatorResult<br>方法 or 属性：onfinish: () => void;<br>起始版本：10|@ohos.animator.d.ts|
|起始版本有变化|类名：AnimatorResult<br>方法 or 属性：oncancel: () => void;<br>起始版本：6|类名：AnimatorResult<br>方法 or 属性：oncancel: () => void;<br>起始版本：10|@ohos.animator.d.ts|
|起始版本有变化|类名：AnimatorResult<br>方法 or 属性：onrepeat: () => void;<br>起始版本：6|类名：AnimatorResult<br>方法 or 属性：onrepeat: () => void;<br>起始版本：10|@ohos.animator.d.ts|
|起始版本有变化|类名：Animator<br>起始版本：6|类名：Animator<br>起始版本：10|@ohos.animator.d.ts|
|起始版本有变化|类名：Animator<br>方法 or 属性：static create(options: AnimatorOptions): AnimatorResult;<br>起始版本：9|类名：Animator<br>方法 or 属性：static create(options: AnimatorOptions): AnimatorResult;<br>起始版本：10|@ohos.animator.d.ts|
|起始版本有变化|类名：curves<br>起始版本：7|类名：curves<br>起始版本：10|@ohos.curves.d.ts|
|起始版本有变化|类名：Curve<br>起始版本：7|类名：Curve<br>起始版本：10|@ohos.curves.d.ts|
|起始版本有变化|类名：ICurve<br>起始版本：9|类名：ICurve<br>起始版本：10|@ohos.curves.d.ts|
|起始版本有变化|类名：curves<br>方法 or 属性：function initCurve(curve?: Curve): ICurve;<br>起始版本：9|类名：curves<br>方法 or 属性：function initCurve(curve?: Curve): ICurve;<br>起始版本：10|@ohos.curves.d.ts|
|起始版本有变化|类名：curves<br>方法 or 属性：function stepsCurve(count: number, end: boolean): ICurve;<br>起始版本：9|类名：curves<br>方法 or 属性：function stepsCurve(count: number, end: boolean): ICurve;<br>起始版本：10|@ohos.curves.d.ts|
|起始版本有变化|类名：curves<br>方法 or 属性：function cubicBezierCurve(x1: number, y1: number, x2: number, y2: number): ICurve;<br>起始版本：9|类名：curves<br>方法 or 属性：function cubicBezierCurve(x1: number, y1: number, x2: number, y2: number): ICurve;<br>起始版本：10|@ohos.curves.d.ts|
|起始版本有变化|类名：curves<br>方法 or 属性：function springCurve(velocity: number, mass: number, stiffness: number, damping: number): ICurve;<br>起始版本：9|类名：curves<br>方法 or 属性：function springCurve(velocity: number, mass: number, stiffness: number, damping: number): ICurve;<br>起始版本：10|@ohos.curves.d.ts|
|起始版本有变化|类名：curves<br>方法 or 属性：function springMotion(response?: number, dampingFraction?: number, overlapDuration?: number): ICurve;<br>起始版本：9|类名：curves<br>方法 or 属性：function springMotion(response?: number, dampingFraction?: number, overlapDuration?: number): ICurve;<br>起始版本：10|@ohos.curves.d.ts|
|起始版本有变化|类名：curves<br>方法 or 属性：function responsiveSpringMotion(response?: number, dampingFraction?: number, overlapDuration?: number): ICurve;<br>起始版本：9|类名：curves<br>方法 or 属性：function responsiveSpringMotion(response?: number, dampingFraction?: number, overlapDuration?: number): ICurve;<br>起始版本：10|@ohos.curves.d.ts|
|起始版本有变化|类名：matrix4<br>起始版本：7|类名：matrix4<br>起始版本：10|@ohos.matrix4.d.ts|
|起始版本有变化|类名：TranslateOption<br>起始版本：7|类名：TranslateOption<br>起始版本：10|@ohos.matrix4.d.ts|
|起始版本有变化|类名：TranslateOption<br>方法 or 属性：x?: number;<br>起始版本：7|类名：TranslateOption<br>方法 or 属性：x?: number;<br>起始版本：10|@ohos.matrix4.d.ts|
|起始版本有变化|类名：TranslateOption<br>方法 or 属性：y?: number;<br>起始版本：7|类名：TranslateOption<br>方法 or 属性：y?: number;<br>起始版本：10|@ohos.matrix4.d.ts|
|起始版本有变化|类名：TranslateOption<br>方法 or 属性：z?: number;<br>起始版本：7|类名：TranslateOption<br>方法 or 属性：z?: number;<br>起始版本：10|@ohos.matrix4.d.ts|
|起始版本有变化|类名：ScaleOption<br>起始版本：7|类名：ScaleOption<br>起始版本：10|@ohos.matrix4.d.ts|
|起始版本有变化|类名：ScaleOption<br>方法 or 属性：x?: number;<br>起始版本：7|类名：ScaleOption<br>方法 or 属性：x?: number;<br>起始版本：10|@ohos.matrix4.d.ts|
|起始版本有变化|类名：ScaleOption<br>方法 or 属性：y?: number;<br>起始版本：7|类名：ScaleOption<br>方法 or 属性：y?: number;<br>起始版本：10|@ohos.matrix4.d.ts|
|起始版本有变化|类名：ScaleOption<br>方法 or 属性：z?: number;<br>起始版本：7|类名：ScaleOption<br>方法 or 属性：z?: number;<br>起始版本：10|@ohos.matrix4.d.ts|
|起始版本有变化|类名：ScaleOption<br>方法 or 属性：centerX?: number;<br>起始版本：7|类名：ScaleOption<br>方法 or 属性：centerX?: number;<br>起始版本：10|@ohos.matrix4.d.ts|
|起始版本有变化|类名：ScaleOption<br>方法 or 属性：centerY?: number;<br>起始版本：7|类名：ScaleOption<br>方法 or 属性：centerY?: number;<br>起始版本：10|@ohos.matrix4.d.ts|
|起始版本有变化|类名：RotateOption<br>起始版本：7|类名：RotateOption<br>起始版本：10|@ohos.matrix4.d.ts|
|起始版本有变化|类名：RotateOption<br>方法 or 属性：x?: number;<br>起始版本：7|类名：RotateOption<br>方法 or 属性：x?: number;<br>起始版本：10|@ohos.matrix4.d.ts|
|起始版本有变化|类名：RotateOption<br>方法 or 属性：y?: number;<br>起始版本：7|类名：RotateOption<br>方法 or 属性：y?: number;<br>起始版本：10|@ohos.matrix4.d.ts|
|起始版本有变化|类名：RotateOption<br>方法 or 属性：z?: number;<br>起始版本：7|类名：RotateOption<br>方法 or 属性：z?: number;<br>起始版本：10|@ohos.matrix4.d.ts|
|起始版本有变化|类名：RotateOption<br>方法 or 属性：centerX?: number;<br>起始版本：7|类名：RotateOption<br>方法 or 属性：centerX?: number;<br>起始版本：10|@ohos.matrix4.d.ts|
|起始版本有变化|类名：RotateOption<br>方法 or 属性：centerY?: number;<br>起始版本：7|类名：RotateOption<br>方法 or 属性：centerY?: number;<br>起始版本：10|@ohos.matrix4.d.ts|
|起始版本有变化|类名：RotateOption<br>方法 or 属性：angle?: number;<br>起始版本：7|类名：RotateOption<br>方法 or 属性：angle?: number;<br>起始版本：10|@ohos.matrix4.d.ts|
|起始版本有变化|类名：Matrix4Transit<br>起始版本：7|类名：Matrix4Transit<br>起始版本：10|@ohos.matrix4.d.ts|
|起始版本有变化|类名：Matrix4Transit<br>方法 or 属性：copy(): Matrix4Transit;<br>起始版本：7|类名：Matrix4Transit<br>方法 or 属性：copy(): Matrix4Transit;<br>起始版本：10|@ohos.matrix4.d.ts|
|起始版本有变化|类名：Matrix4Transit<br>方法 or 属性：invert(): Matrix4Transit;<br>起始版本：7|类名：Matrix4Transit<br>方法 or 属性：invert(): Matrix4Transit;<br>起始版本：10|@ohos.matrix4.d.ts|
|起始版本有变化|类名：Matrix4Transit<br>方法 or 属性：combine(options: Matrix4Transit): Matrix4Transit;<br>起始版本：7|类名：Matrix4Transit<br>方法 or 属性：combine(options: Matrix4Transit): Matrix4Transit;<br>起始版本：10|@ohos.matrix4.d.ts|
|起始版本有变化|类名：Matrix4Transit<br>方法 or 属性：translate(options: TranslateOption): Matrix4Transit;<br>起始版本：7|类名：Matrix4Transit<br>方法 or 属性：translate(options: TranslateOption): Matrix4Transit;<br>起始版本：10|@ohos.matrix4.d.ts|
|起始版本有变化|类名：Matrix4Transit<br>方法 or 属性：scale(options: ScaleOption): Matrix4Transit;<br>起始版本：7|类名：Matrix4Transit<br>方法 or 属性：scale(options: ScaleOption): Matrix4Transit;<br>起始版本：10|@ohos.matrix4.d.ts|
|起始版本有变化|类名：Matrix4Transit<br>方法 or 属性：rotate(options: RotateOption): Matrix4Transit;<br>起始版本：7|类名：Matrix4Transit<br>方法 or 属性：rotate(options: RotateOption): Matrix4Transit;<br>起始版本：10|@ohos.matrix4.d.ts|
|起始版本有变化|类名：Matrix4Transit<br>方法 or 属性：transformPoint(options: [number, number]): [number, number];<br>起始版本：7|类名：Matrix4Transit<br>方法 or 属性：transformPoint(options: [number, number]): [number, number];<br>起始版本：10|@ohos.matrix4.d.ts|
|起始版本有变化|类名：matrix4<br>方法 or 属性：function identity(): Matrix4Transit;<br>起始版本：7|类名：matrix4<br>方法 or 属性：function identity(): Matrix4Transit;<br>起始版本：10|@ohos.matrix4.d.ts|
|起始版本有变化|类名：matrix4<br>方法 or 属性：function copy(): Matrix4Transit;<br>起始版本：7|类名：matrix4<br>方法 or 属性：function copy(): Matrix4Transit;<br>起始版本：10|@ohos.matrix4.d.ts|
|起始版本有变化|类名：matrix4<br>方法 or 属性：function invert(): Matrix4Transit;<br>起始版本：7|类名：matrix4<br>方法 or 属性：function invert(): Matrix4Transit;<br>起始版本：10|@ohos.matrix4.d.ts|
|起始版本有变化|类名：matrix4<br>方法 or 属性：function combine(options: Matrix4Transit): Matrix4Transit;<br>起始版本：7|类名：matrix4<br>方法 or 属性：function combine(options: Matrix4Transit): Matrix4Transit;<br>起始版本：10|@ohos.matrix4.d.ts|
|起始版本有变化|类名：matrix4<br>方法 or 属性：function translate(options: TranslateOption): Matrix4Transit;<br>起始版本：7|类名：matrix4<br>方法 or 属性：function translate(options: TranslateOption): Matrix4Transit;<br>起始版本：10|@ohos.matrix4.d.ts|
|起始版本有变化|类名：matrix4<br>方法 or 属性：function scale(options: ScaleOption): Matrix4Transit;<br>起始版本：7|类名：matrix4<br>方法 or 属性：function scale(options: ScaleOption): Matrix4Transit;<br>起始版本：10|@ohos.matrix4.d.ts|
|起始版本有变化|类名：matrix4<br>方法 or 属性：function rotate(options: RotateOption): Matrix4Transit;<br>起始版本：7|类名：matrix4<br>方法 or 属性：function rotate(options: RotateOption): Matrix4Transit;<br>起始版本：10|@ohos.matrix4.d.ts|
|起始版本有变化|类名：matrix4<br>方法 or 属性：function transformPoint(options: [number, number]): [number, number];<br>起始版本：7|类名：matrix4<br>方法 or 属性：function transformPoint(options: [number, number]): [number, number];<br>起始版本：10|@ohos.matrix4.d.ts|
|起始版本有变化|类名：mediaquery<br>起始版本：7|类名：mediaquery<br>起始版本：10|@ohos.mediaquery.d.ts|
|起始版本有变化|类名：MediaQueryResult<br>方法 or 属性：readonly matches: boolean;<br>起始版本：7|类名：MediaQueryResult<br>方法 or 属性：readonly matches: boolean;<br>起始版本：10|@ohos.mediaquery.d.ts|
|起始版本有变化|类名：MediaQueryResult<br>方法 or 属性：readonly media: string;<br>起始版本：7|类名：MediaQueryResult<br>方法 or 属性：readonly media: string;<br>起始版本：10|@ohos.mediaquery.d.ts|
|起始版本有变化|类名：MediaQueryListener<br>方法 or 属性：on(type: 'change', callback: Callback\<MediaQueryResult>): void;<br>起始版本：7|类名：MediaQueryListener<br>方法 or 属性：on(type: 'change', callback: Callback\<MediaQueryResult>): void;<br>起始版本：10|@ohos.mediaquery.d.ts|
|起始版本有变化|类名：MediaQueryListener<br>方法 or 属性：off(type: 'change', callback?: Callback\<MediaQueryResult>): void;<br>起始版本：7|类名：MediaQueryListener<br>方法 or 属性：off(type: 'change', callback?: Callback\<MediaQueryResult>): void;<br>起始版本：10|@ohos.mediaquery.d.ts|
|起始版本有变化|类名：mediaquery<br>方法 or 属性：function matchMediaSync(condition: string): MediaQueryListener;<br>起始版本：7|类名：mediaquery<br>方法 or 属性：function matchMediaSync(condition: string): MediaQueryListener;<br>起始版本：10|@ohos.mediaquery.d.ts|
|起始版本有变化|类名：promptAction<br>起始版本：9|类名：promptAction<br>起始版本：10|@ohos.promptAction.d.ts|
|起始版本有变化|类名：ShowToastOptions<br>起始版本：9|类名：ShowToastOptions<br>起始版本：10|@ohos.promptAction.d.ts|
|起始版本有变化|类名：ShowToastOptions<br>方法 or 属性：message: string \| Resource;<br>起始版本：9|类名：ShowToastOptions<br>方法 or 属性：message: string \| Resource;<br>起始版本：10|@ohos.promptAction.d.ts|
|起始版本有变化|类名：ShowToastOptions<br>方法 or 属性：duration?: number;<br>起始版本：9|类名：ShowToastOptions<br>方法 or 属性：duration?: number;<br>起始版本：10|@ohos.promptAction.d.ts|
|起始版本有变化|类名：ShowToastOptions<br>方法 or 属性：bottom?: string \| number;<br>起始版本：9|类名：ShowToastOptions<br>方法 or 属性：bottom?: string \| number;<br>起始版本：10|@ohos.promptAction.d.ts|
|起始版本有变化|类名：Button<br>起始版本：9|类名：Button<br>起始版本：10|@ohos.promptAction.d.ts|
|起始版本有变化|类名：Button<br>方法 or 属性：text: string \| Resource;<br>起始版本：9|类名：Button<br>方法 or 属性：text: string \| Resource;<br>起始版本：10|@ohos.promptAction.d.ts|
|起始版本有变化|类名：Button<br>方法 or 属性：color: string \| Resource;<br>起始版本：9|类名：Button<br>方法 or 属性：color: string \| Resource;<br>起始版本：10|@ohos.promptAction.d.ts|
|起始版本有变化|类名：ShowDialogSuccessResponse<br>起始版本：9|类名：ShowDialogSuccessResponse<br>起始版本：10|@ohos.promptAction.d.ts|
|起始版本有变化|类名：ShowDialogSuccessResponse<br>方法 or 属性：index: number;<br>起始版本：9|类名：ShowDialogSuccessResponse<br>方法 or 属性：index: number;<br>起始版本：10|@ohos.promptAction.d.ts|
|起始版本有变化|类名：ShowDialogOptions<br>起始版本：9|类名：ShowDialogOptions<br>起始版本：10|@ohos.promptAction.d.ts|
|起始版本有变化|类名：ShowDialogOptions<br>方法 or 属性：title?: string \| Resource;<br>起始版本：9|类名：ShowDialogOptions<br>方法 or 属性：title?: string \| Resource;<br>起始版本：10|@ohos.promptAction.d.ts|
|起始版本有变化|类名：ShowDialogOptions<br>方法 or 属性：message?: string \| Resource;<br>起始版本：9|类名：ShowDialogOptions<br>方法 or 属性：message?: string \| Resource;<br>起始版本：10|@ohos.promptAction.d.ts|
|起始版本有变化|类名：ShowDialogOptions<br>方法 or 属性：buttons?: [Button, Button?, Button?];<br>起始版本：9|类名：ShowDialogOptions<br>方法 or 属性：buttons?: [Button, Button?, Button?];<br>起始版本：10|@ohos.promptAction.d.ts|
|起始版本有变化|类名：ActionMenuSuccessResponse<br>起始版本：9|类名：ActionMenuSuccessResponse<br>起始版本：10|@ohos.promptAction.d.ts|
|起始版本有变化|类名：ActionMenuSuccessResponse<br>方法 or 属性：index: number;<br>起始版本：9|类名：ActionMenuSuccessResponse<br>方法 or 属性：index: number;<br>起始版本：10|@ohos.promptAction.d.ts|
|起始版本有变化|类名：ActionMenuOptions<br>起始版本：9|类名：ActionMenuOptions<br>起始版本：10|@ohos.promptAction.d.ts|
|起始版本有变化|类名：ActionMenuOptions<br>方法 or 属性：title?: string \| Resource;<br>起始版本：9|类名：ActionMenuOptions<br>方法 or 属性：title?: string \| Resource;<br>起始版本：10|@ohos.promptAction.d.ts|
|起始版本有变化|类名：ActionMenuOptions<br>方法 or 属性：buttons: [Button, Button?, Button?, Button?, Button?, Button?];<br>起始版本：9|类名：ActionMenuOptions<br>方法 or 属性：buttons: [Button, Button?, Button?, Button?, Button?, Button?];<br>起始版本：10|@ohos.promptAction.d.ts|
|起始版本有变化|类名：promptAction<br>方法 or 属性：function showDialog(options: ShowDialogOptions): Promise\<ShowDialogSuccessResponse>;<br>起始版本：9|类名：promptAction<br>方法 or 属性：function showDialog(options: ShowDialogOptions): Promise\<ShowDialogSuccessResponse>;<br>起始版本：10|@ohos.promptAction.d.ts|
|起始版本有变化|类名：promptAction<br>方法 or 属性：function showActionMenu(options: ActionMenuOptions): Promise\<ActionMenuSuccessResponse>;<br>起始版本：9|类名：promptAction<br>方法 or 属性：function showActionMenu(options: ActionMenuOptions): Promise\<ActionMenuSuccessResponse>;<br>起始版本：10|@ohos.promptAction.d.ts|
|起始版本有变化|类名：SheetInfo<br>起始版本：8|类名：SheetInfo<br>起始版本：10|action_sheet.d.ts|
|起始版本有变化|类名：SheetInfo<br>方法 or 属性：title: string \| Resource;<br>起始版本：8|类名：SheetInfo<br>方法 or 属性：title: string \| Resource;<br>起始版本：10|action_sheet.d.ts|
|起始版本有变化|类名：SheetInfo<br>方法 or 属性：icon?: string \| Resource;<br>起始版本：8|类名：SheetInfo<br>方法 or 属性：icon?: string \| Resource;<br>起始版本：10|action_sheet.d.ts|
|起始版本有变化|类名：SheetInfo<br>方法 or 属性：action: () => void;<br>起始版本：8|类名：SheetInfo<br>方法 or 属性：action: () => void;<br>起始版本：10|action_sheet.d.ts|
|起始版本有变化|类名：ActionSheet<br>起始版本：8|类名：ActionSheet<br>起始版本：10|action_sheet.d.ts|
|起始版本有变化|类名：DialogAlignment<br>起始版本：7|类名：DialogAlignment<br>起始版本：10|alert_dialog.d.ts|
|起始版本有变化|类名：DialogAlignment<br>方法 or 属性：Top<br>起始版本：7|类名：DialogAlignment<br>方法 or 属性：Top<br>起始版本：10|alert_dialog.d.ts|
|起始版本有变化|类名：DialogAlignment<br>方法 or 属性：Center<br>起始版本：7|类名：DialogAlignment<br>方法 or 属性：Center<br>起始版本：10|alert_dialog.d.ts|
|起始版本有变化|类名：DialogAlignment<br>方法 or 属性：Bottom<br>起始版本：7|类名：DialogAlignment<br>方法 or 属性：Bottom<br>起始版本：10|alert_dialog.d.ts|
|起始版本有变化|类名：DialogAlignment<br>方法 or 属性：Default<br>起始版本：7|类名：DialogAlignment<br>方法 or 属性：Default<br>起始版本：10|alert_dialog.d.ts|
|起始版本有变化|类名：DialogAlignment<br>方法 or 属性：TopStart<br>起始版本：8|类名：DialogAlignment<br>方法 or 属性：TopStart<br>起始版本：10|alert_dialog.d.ts|
|起始版本有变化|类名：DialogAlignment<br>方法 or 属性：TopEnd<br>起始版本：8|类名：DialogAlignment<br>方法 or 属性：TopEnd<br>起始版本：10|alert_dialog.d.ts|
|起始版本有变化|类名：DialogAlignment<br>方法 or 属性：CenterStart<br>起始版本：8|类名：DialogAlignment<br>方法 or 属性：CenterStart<br>起始版本：10|alert_dialog.d.ts|
|起始版本有变化|类名：DialogAlignment<br>方法 or 属性：CenterEnd<br>起始版本：8|类名：DialogAlignment<br>方法 or 属性：CenterEnd<br>起始版本：10|alert_dialog.d.ts|
|起始版本有变化|类名：DialogAlignment<br>方法 or 属性：BottomStart<br>起始版本：8|类名：DialogAlignment<br>方法 or 属性：BottomStart<br>起始版本：10|alert_dialog.d.ts|
|起始版本有变化|类名：DialogAlignment<br>方法 or 属性：BottomEnd<br>起始版本：8|类名：DialogAlignment<br>方法 or 属性：BottomEnd<br>起始版本：10|alert_dialog.d.ts|
|起始版本有变化|类名：AlertDialogParam<br>起始版本：7|类名：AlertDialogParam<br>起始版本：10|alert_dialog.d.ts|
|起始版本有变化|类名：AlertDialogParam<br>方法 or 属性：title?: ResourceStr;<br>起始版本：7|类名：AlertDialogParam<br>方法 or 属性：title?: ResourceStr;<br>起始版本：10|alert_dialog.d.ts|
|起始版本有变化|类名：AlertDialogParam<br>方法 or 属性：message: ResourceStr;<br>起始版本：7|类名：AlertDialogParam<br>方法 or 属性：message: ResourceStr;<br>起始版本：10|alert_dialog.d.ts|
|起始版本有变化|类名：AlertDialogParam<br>方法 or 属性：autoCancel?: boolean;<br>起始版本：7|类名：AlertDialogParam<br>方法 or 属性：autoCancel?: boolean;<br>起始版本：10|alert_dialog.d.ts|
|起始版本有变化|类名：AlertDialogParam<br>方法 or 属性：cancel?: () => void;<br>起始版本：7|类名：AlertDialogParam<br>方法 or 属性：cancel?: () => void;<br>起始版本：10|alert_dialog.d.ts|
|起始版本有变化|类名：AlertDialogParam<br>方法 or 属性：alignment?: DialogAlignment;<br>起始版本：7|类名：AlertDialogParam<br>方法 or 属性：alignment?: DialogAlignment;<br>起始版本：10|alert_dialog.d.ts|
|起始版本有变化|类名：AlertDialogParam<br>方法 or 属性：offset?: Offset;<br>起始版本：7|类名：AlertDialogParam<br>方法 or 属性：offset?: Offset;<br>起始版本：10|alert_dialog.d.ts|
|起始版本有变化|类名：AlertDialogParam<br>方法 or 属性：gridCount?: number;<br>起始版本：7|类名：AlertDialogParam<br>方法 or 属性：gridCount?: number;<br>起始版本：10|alert_dialog.d.ts|
|起始版本有变化|类名：AlertDialogParamWithConfirm<br>起始版本：7|类名：AlertDialogParamWithConfirm<br>起始版本：10|alert_dialog.d.ts|
|起始版本有变化|类名：AlertDialogParamWithButtons<br>起始版本：7|类名：AlertDialogParamWithButtons<br>起始版本：10|alert_dialog.d.ts|
|起始版本有变化|类名：AlertDialog<br>起始版本：7|类名：AlertDialog<br>起始版本：10|alert_dialog.d.ts|
|起始版本有变化|类名：AlertDialog<br>方法 or 属性：static show(value: AlertDialogParamWithConfirm \| AlertDialogParamWithButtons);<br>起始版本：7|类名：AlertDialog<br>方法 or 属性：static show(value: AlertDialogParamWithConfirm \| AlertDialogParamWithButtons);<br>起始版本：10|alert_dialog.d.ts|
|起始版本有变化|类名：IndexerAlign<br>起始版本：7|类名：IndexerAlign<br>起始版本：10|alphabet_indexer.d.ts|
|起始版本有变化|类名：IndexerAlign<br>方法 or 属性：Left<br>起始版本：7|类名：IndexerAlign<br>方法 or 属性：Left<br>起始版本：10|alphabet_indexer.d.ts|
|起始版本有变化|类名：IndexerAlign<br>方法 or 属性：Right<br>起始版本：7|类名：IndexerAlign<br>方法 or 属性：Right<br>起始版本：10|alphabet_indexer.d.ts|
|起始版本有变化|类名：AlphabetIndexerInterface<br>起始版本：7|类名：AlphabetIndexerInterface<br>起始版本：10|alphabet_indexer.d.ts|
|起始版本有变化|类名：AlphabetIndexerInterface<br>方法 or 属性：(value: { arrayValue: Array\<string>; selected: number }): AlphabetIndexerAttribute;<br>起始版本：7|类名：AlphabetIndexerInterface<br>方法 or 属性：(value: { arrayValue: Array\<string>; selected: number }): AlphabetIndexerAttribute;<br>起始版本：10|alphabet_indexer.d.ts|
|起始版本有变化|类名：AlphabetIndexerAttribute<br>起始版本：7|类名：AlphabetIndexerAttribute<br>起始版本：10|alphabet_indexer.d.ts|
|起始版本有变化|类名：AlphabetIndexerAttribute<br>方法 or 属性：color(value: ResourceColor): AlphabetIndexerAttribute;<br>起始版本：7|类名：AlphabetIndexerAttribute<br>方法 or 属性：color(value: ResourceColor): AlphabetIndexerAttribute;<br>起始版本：10|alphabet_indexer.d.ts|
|起始版本有变化|类名：AlphabetIndexerAttribute<br>方法 or 属性：selectedColor(value: ResourceColor): AlphabetIndexerAttribute;<br>起始版本：7|类名：AlphabetIndexerAttribute<br>方法 or 属性：selectedColor(value: ResourceColor): AlphabetIndexerAttribute;<br>起始版本：10|alphabet_indexer.d.ts|
|起始版本有变化|类名：AlphabetIndexerAttribute<br>方法 or 属性：popupColor(value: ResourceColor): AlphabetIndexerAttribute;<br>起始版本：7|类名：AlphabetIndexerAttribute<br>方法 or 属性：popupColor(value: ResourceColor): AlphabetIndexerAttribute;<br>起始版本：10|alphabet_indexer.d.ts|
|起始版本有变化|类名：AlphabetIndexerAttribute<br>方法 or 属性：selectedBackgroundColor(value: ResourceColor): AlphabetIndexerAttribute;<br>起始版本：7|类名：AlphabetIndexerAttribute<br>方法 or 属性：selectedBackgroundColor(value: ResourceColor): AlphabetIndexerAttribute;<br>起始版本：10|alphabet_indexer.d.ts|
|起始版本有变化|类名：AlphabetIndexerAttribute<br>方法 or 属性：popupBackground(value: ResourceColor): AlphabetIndexerAttribute;<br>起始版本：7|类名：AlphabetIndexerAttribute<br>方法 or 属性：popupBackground(value: ResourceColor): AlphabetIndexerAttribute;<br>起始版本：10|alphabet_indexer.d.ts|
|起始版本有变化|类名：AlphabetIndexerAttribute<br>方法 or 属性：usingPopup(value: boolean): AlphabetIndexerAttribute;<br>起始版本：7|类名：AlphabetIndexerAttribute<br>方法 or 属性：usingPopup(value: boolean): AlphabetIndexerAttribute;<br>起始版本：10|alphabet_indexer.d.ts|
|起始版本有变化|类名：AlphabetIndexerAttribute<br>方法 or 属性：selectedFont(value: Font): AlphabetIndexerAttribute;<br>起始版本：7|类名：AlphabetIndexerAttribute<br>方法 or 属性：selectedFont(value: Font): AlphabetIndexerAttribute;<br>起始版本：10|alphabet_indexer.d.ts|
|起始版本有变化|类名：AlphabetIndexerAttribute<br>方法 or 属性：popupFont(value: Font): AlphabetIndexerAttribute;<br>起始版本：7|类名：AlphabetIndexerAttribute<br>方法 or 属性：popupFont(value: Font): AlphabetIndexerAttribute;<br>起始版本：10|alphabet_indexer.d.ts|
|起始版本有变化|类名：AlphabetIndexerAttribute<br>方法 or 属性：itemSize(value: string \| number): AlphabetIndexerAttribute;<br>起始版本：7|类名：AlphabetIndexerAttribute<br>方法 or 属性：itemSize(value: string \| number): AlphabetIndexerAttribute;<br>起始版本：10|alphabet_indexer.d.ts|
|起始版本有变化|类名：AlphabetIndexerAttribute<br>方法 or 属性：font(value: Font): AlphabetIndexerAttribute;<br>起始版本：7|类名：AlphabetIndexerAttribute<br>方法 or 属性：font(value: Font): AlphabetIndexerAttribute;<br>起始版本：10|alphabet_indexer.d.ts|
|起始版本有变化|类名：AlphabetIndexerAttribute<br>方法 or 属性：onSelect(callback: (index: number) => void): AlphabetIndexerAttribute;<br>起始版本：8|类名：AlphabetIndexerAttribute<br>方法 or 属性：onSelect(callback: (index: number) => void): AlphabetIndexerAttribute;<br>起始版本：10|alphabet_indexer.d.ts|
|起始版本有变化|类名：AlphabetIndexerAttribute<br>方法 or 属性：onRequestPopupData(callback: (index: number) => Array\<string>): AlphabetIndexerAttribute;<br>起始版本：8|类名：AlphabetIndexerAttribute<br>方法 or 属性：onRequestPopupData(callback: (index: number) => Array\<string>): AlphabetIndexerAttribute;<br>起始版本：10|alphabet_indexer.d.ts|
|起始版本有变化|类名：AlphabetIndexerAttribute<br>方法 or 属性：onPopupSelect(callback: (index: number) => void): AlphabetIndexerAttribute;<br>起始版本：8|类名：AlphabetIndexerAttribute<br>方法 or 属性：onPopupSelect(callback: (index: number) => void): AlphabetIndexerAttribute;<br>起始版本：10|alphabet_indexer.d.ts|
|起始版本有变化|类名：AlphabetIndexerAttribute<br>方法 or 属性：selected(index: number): AlphabetIndexerAttribute;<br>起始版本：8|类名：AlphabetIndexerAttribute<br>方法 or 属性：selected(index: number): AlphabetIndexerAttribute;<br>起始版本：10|alphabet_indexer.d.ts|
|起始版本有变化|类名：AlphabetIndexerAttribute<br>方法 or 属性：popupPosition(value: Position): AlphabetIndexerAttribute;<br>起始版本：8|类名：AlphabetIndexerAttribute<br>方法 or 属性：popupPosition(value: Position): AlphabetIndexerAttribute;<br>起始版本：10|alphabet_indexer.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const AlphabetIndexer: AlphabetIndexerInterface;<br>起始版本：7|类名：global<br>方法 or 属性：declare const AlphabetIndexer: AlphabetIndexerInterface;<br>起始版本：10|alphabet_indexer.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const AlphabetIndexerInstance: AlphabetIndexerAttribute;<br>起始版本：7|类名：global<br>方法 or 属性：declare const AlphabetIndexerInstance: AlphabetIndexerAttribute;<br>起始版本：10|alphabet_indexer.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const AnimatorInstance: AnimatorAttribute;<br>起始版本：7|类名：global<br>方法 or 属性：declare const AnimatorInstance: AnimatorAttribute;<br>起始版本：9|animator.d.ts|
|起始版本有变化|类名：CalendarDay<br>起始版本：7|类名：CalendarDay<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CalendarDay<br>方法 or 属性：index: number;<br>起始版本：7|类名：CalendarDay<br>方法 or 属性：index: number;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CalendarDay<br>方法 or 属性：lunarMonth: string;<br>起始版本：7|类名：CalendarDay<br>方法 or 属性：lunarMonth: string;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CalendarDay<br>方法 or 属性：lunarDay: string;<br>起始版本：7|类名：CalendarDay<br>方法 or 属性：lunarDay: string;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CalendarDay<br>方法 or 属性：dayMark: string;<br>起始版本：7|类名：CalendarDay<br>方法 or 属性：dayMark: string;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CalendarDay<br>方法 or 属性：dayMarkValue: string;<br>起始版本：7|类名：CalendarDay<br>方法 or 属性：dayMarkValue: string;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CalendarDay<br>方法 or 属性：year: number;<br>起始版本：7|类名：CalendarDay<br>方法 or 属性：year: number;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CalendarDay<br>方法 or 属性：month: number;<br>起始版本：7|类名：CalendarDay<br>方法 or 属性：month: number;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CalendarDay<br>方法 or 属性：day: number;<br>起始版本：7|类名：CalendarDay<br>方法 or 属性：day: number;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CalendarDay<br>方法 or 属性：isFirstOfLunar: boolean;<br>起始版本：7|类名：CalendarDay<br>方法 or 属性：isFirstOfLunar: boolean;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CalendarDay<br>方法 or 属性：hasSchedule: boolean;<br>起始版本：7|类名：CalendarDay<br>方法 or 属性：hasSchedule: boolean;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CalendarDay<br>方法 or 属性：markLunarDay: boolean;<br>起始版本：7|类名：CalendarDay<br>方法 or 属性：markLunarDay: boolean;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：MonthData<br>起始版本：7|类名：MonthData<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：MonthData<br>方法 or 属性：year: number;<br>起始版本：7|类名：MonthData<br>方法 or 属性：year: number;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：MonthData<br>方法 or 属性：month: number;<br>起始版本：7|类名：MonthData<br>方法 or 属性：month: number;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：MonthData<br>方法 or 属性：data: CalendarDay[];<br>起始版本：7|类名：MonthData<br>方法 or 属性：data: CalendarDay[];<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CurrentDayStyle<br>起始版本：7|类名：CurrentDayStyle<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CurrentDayStyle<br>方法 or 属性：dayColor?: ResourceColor;<br>起始版本：7|类名：CurrentDayStyle<br>方法 or 属性：dayColor?: ResourceColor;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CurrentDayStyle<br>方法 or 属性：lunarColor?: ResourceColor;<br>起始版本：7|类名：CurrentDayStyle<br>方法 or 属性：lunarColor?: ResourceColor;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CurrentDayStyle<br>方法 or 属性：markLunarColor?: ResourceColor;<br>起始版本：7|类名：CurrentDayStyle<br>方法 or 属性：markLunarColor?: ResourceColor;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CurrentDayStyle<br>方法 or 属性：dayFontSize?: number;<br>起始版本：7|类名：CurrentDayStyle<br>方法 or 属性：dayFontSize?: number;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CurrentDayStyle<br>方法 or 属性：lunarDayFontSize?: number;<br>起始版本：7|类名：CurrentDayStyle<br>方法 or 属性：lunarDayFontSize?: number;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CurrentDayStyle<br>方法 or 属性：dayHeight?: number;<br>起始版本：7|类名：CurrentDayStyle<br>方法 or 属性：dayHeight?: number;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CurrentDayStyle<br>方法 or 属性：dayWidth?: number;<br>起始版本：7|类名：CurrentDayStyle<br>方法 or 属性：dayWidth?: number;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CurrentDayStyle<br>方法 or 属性：gregorianCalendarHeight?: number;<br>起始版本：7|类名：CurrentDayStyle<br>方法 or 属性：gregorianCalendarHeight?: number;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CurrentDayStyle<br>方法 or 属性：dayYAxisOffset?: number;<br>起始版本：7|类名：CurrentDayStyle<br>方法 or 属性：dayYAxisOffset?: number;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CurrentDayStyle<br>方法 or 属性：lunarDayYAxisOffset?: number;<br>起始版本：7|类名：CurrentDayStyle<br>方法 or 属性：lunarDayYAxisOffset?: number;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CurrentDayStyle<br>方法 or 属性：underscoreXAxisOffset?: number;<br>起始版本：7|类名：CurrentDayStyle<br>方法 or 属性：underscoreXAxisOffset?: number;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CurrentDayStyle<br>方法 or 属性：underscoreYAxisOffset?: number;<br>起始版本：7|类名：CurrentDayStyle<br>方法 or 属性：underscoreYAxisOffset?: number;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CurrentDayStyle<br>方法 or 属性：scheduleMarkerXAxisOffset?: number;<br>起始版本：7|类名：CurrentDayStyle<br>方法 or 属性：scheduleMarkerXAxisOffset?: number;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CurrentDayStyle<br>方法 or 属性：scheduleMarkerYAxisOffset?: number;<br>起始版本：7|类名：CurrentDayStyle<br>方法 or 属性：scheduleMarkerYAxisOffset?: number;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CurrentDayStyle<br>方法 or 属性：colSpace?: number;<br>起始版本：7|类名：CurrentDayStyle<br>方法 or 属性：colSpace?: number;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CurrentDayStyle<br>方法 or 属性：dailyFiveRowSpace?: number;<br>起始版本：7|类名：CurrentDayStyle<br>方法 or 属性：dailyFiveRowSpace?: number;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CurrentDayStyle<br>方法 or 属性：dailySixRowSpace?: number;<br>起始版本：7|类名：CurrentDayStyle<br>方法 or 属性：dailySixRowSpace?: number;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CurrentDayStyle<br>方法 or 属性：lunarHeight?: number;<br>起始版本：7|类名：CurrentDayStyle<br>方法 or 属性：lunarHeight?: number;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CurrentDayStyle<br>方法 or 属性：underscoreWidth?: number;<br>起始版本：7|类名：CurrentDayStyle<br>方法 or 属性：underscoreWidth?: number;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CurrentDayStyle<br>方法 or 属性：underscoreLength?: number;<br>起始版本：7|类名：CurrentDayStyle<br>方法 or 属性：underscoreLength?: number;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CurrentDayStyle<br>方法 or 属性：scheduleMarkerRadius?: number;<br>起始版本：7|类名：CurrentDayStyle<br>方法 or 属性：scheduleMarkerRadius?: number;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CurrentDayStyle<br>方法 or 属性：boundaryRowOffset?: number;<br>起始版本：7|类名：CurrentDayStyle<br>方法 or 属性：boundaryRowOffset?: number;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CurrentDayStyle<br>方法 or 属性：boundaryColOffset?: number;<br>起始版本：7|类名：CurrentDayStyle<br>方法 or 属性：boundaryColOffset?: number;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：NonCurrentDayStyle<br>起始版本：7|类名：NonCurrentDayStyle<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：NonCurrentDayStyle<br>方法 or 属性：nonCurrentMonthDayColor?: ResourceColor;<br>起始版本：7|类名：NonCurrentDayStyle<br>方法 or 属性：nonCurrentMonthDayColor?: ResourceColor;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：NonCurrentDayStyle<br>方法 or 属性：nonCurrentMonthLunarColor?: ResourceColor;<br>起始版本：7|类名：NonCurrentDayStyle<br>方法 or 属性：nonCurrentMonthLunarColor?: ResourceColor;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：NonCurrentDayStyle<br>方法 or 属性：nonCurrentMonthWorkDayMarkColor?: ResourceColor;<br>起始版本：7|类名：NonCurrentDayStyle<br>方法 or 属性：nonCurrentMonthWorkDayMarkColor?: ResourceColor;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：NonCurrentDayStyle<br>方法 or 属性：nonCurrentMonthOffDayMarkColor?: ResourceColor;<br>起始版本：7|类名：NonCurrentDayStyle<br>方法 or 属性：nonCurrentMonthOffDayMarkColor?: ResourceColor;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：TodayStyle<br>起始版本：7|类名：TodayStyle<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：TodayStyle<br>方法 or 属性：focusedDayColor?: ResourceColor;<br>起始版本：7|类名：TodayStyle<br>方法 or 属性：focusedDayColor?: ResourceColor;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：TodayStyle<br>方法 or 属性：focusedLunarColor?: ResourceColor;<br>起始版本：7|类名：TodayStyle<br>方法 or 属性：focusedLunarColor?: ResourceColor;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：TodayStyle<br>方法 or 属性：focusedAreaBackgroundColor?: ResourceColor;<br>起始版本：7|类名：TodayStyle<br>方法 or 属性：focusedAreaBackgroundColor?: ResourceColor;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：TodayStyle<br>方法 or 属性：focusedAreaRadius?: number;<br>起始版本：7|类名：TodayStyle<br>方法 or 属性：focusedAreaRadius?: number;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：WeekStyle<br>起始版本：7|类名：WeekStyle<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：WeekStyle<br>方法 or 属性：weekColor?: ResourceColor;<br>起始版本：7|类名：WeekStyle<br>方法 or 属性：weekColor?: ResourceColor;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：WeekStyle<br>方法 or 属性：weekendDayColor?: ResourceColor;<br>起始版本：7|类名：WeekStyle<br>方法 or 属性：weekendDayColor?: ResourceColor;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：WeekStyle<br>方法 or 属性：weekendLunarColor?: ResourceColor;<br>起始版本：7|类名：WeekStyle<br>方法 or 属性：weekendLunarColor?: ResourceColor;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：WeekStyle<br>方法 or 属性：weekFontSize?: number;<br>起始版本：7|类名：WeekStyle<br>方法 or 属性：weekFontSize?: number;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：WeekStyle<br>方法 or 属性：weekHeight?: number;<br>起始版本：7|类名：WeekStyle<br>方法 or 属性：weekHeight?: number;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：WeekStyle<br>方法 or 属性：weekWidth?: number;<br>起始版本：7|类名：WeekStyle<br>方法 or 属性：weekWidth?: number;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：WeekStyle<br>方法 or 属性：weekAndDayRowSpace?: number;<br>起始版本：7|类名：WeekStyle<br>方法 or 属性：weekAndDayRowSpace?: number;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：WorkStateStyle<br>起始版本：7|类名：WorkStateStyle<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：WorkStateStyle<br>方法 or 属性：workDayMarkColor?: ResourceColor;<br>起始版本：7|类名：WorkStateStyle<br>方法 or 属性：workDayMarkColor?: ResourceColor;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：WorkStateStyle<br>方法 or 属性：offDayMarkColor?: ResourceColor;<br>起始版本：7|类名：WorkStateStyle<br>方法 or 属性：offDayMarkColor?: ResourceColor;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：WorkStateStyle<br>方法 or 属性：workDayMarkSize?: number;<br>起始版本：7|类名：WorkStateStyle<br>方法 or 属性：workDayMarkSize?: number;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：WorkStateStyle<br>方法 or 属性：offDayMarkSize?: number;<br>起始版本：7|类名：WorkStateStyle<br>方法 or 属性：offDayMarkSize?: number;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：WorkStateStyle<br>方法 or 属性：workStateWidth?: number;<br>起始版本：7|类名：WorkStateStyle<br>方法 or 属性：workStateWidth?: number;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：WorkStateStyle<br>方法 or 属性：workStateHorizontalMovingDistance?: number;<br>起始版本：7|类名：WorkStateStyle<br>方法 or 属性：workStateHorizontalMovingDistance?: number;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：WorkStateStyle<br>方法 or 属性：workStateVerticalMovingDistance?: number;<br>起始版本：7|类名：WorkStateStyle<br>方法 or 属性：workStateVerticalMovingDistance?: number;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CalendarController<br>起始版本：7|类名：CalendarController<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CalendarController<br>方法 or 属性：constructor();<br>起始版本：7|类名：CalendarController<br>方法 or 属性：constructor();<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CalendarController<br>方法 or 属性：backToToday();<br>起始版本：7|类名：CalendarController<br>方法 or 属性：backToToday();<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CalendarController<br>方法 or 属性：goTo(value: { year: number; month: number; day: number });<br>起始版本：7|类名：CalendarController<br>方法 or 属性：goTo(value: { year: number; month: number; day: number });<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CalendarInterface<br>起始版本：7|类名：CalendarInterface<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CalendarInterface<br>方法 or 属性：(value: {<br>    date: { year: number; month: number; day: number };<br>    currentData: MonthData;<br>    preData: MonthData;<br>    nextData: MonthData;<br>    controller?: CalendarController;<br>  }): CalendarAttribute;<br>起始版本：7|类名：CalendarInterface<br>方法 or 属性：(value: {<br>    date: { year: number; month: number; day: number };<br>    currentData: MonthData;<br>    preData: MonthData;<br>    nextData: MonthData;<br>    controller?: CalendarController;<br>  }): CalendarAttribute;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CalendarAttribute<br>起始版本：7|类名：CalendarAttribute<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CalendarAttribute<br>方法 or 属性：showLunar(value: boolean): CalendarAttribute;<br>起始版本：7|类名：CalendarAttribute<br>方法 or 属性：showLunar(value: boolean): CalendarAttribute;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CalendarAttribute<br>方法 or 属性：showHoliday(value: boolean): CalendarAttribute;<br>起始版本：7|类名：CalendarAttribute<br>方法 or 属性：showHoliday(value: boolean): CalendarAttribute;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CalendarAttribute<br>方法 or 属性：needSlide(value: boolean): CalendarAttribute;<br>起始版本：7|类名：CalendarAttribute<br>方法 or 属性：needSlide(value: boolean): CalendarAttribute;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CalendarAttribute<br>方法 or 属性：startOfWeek(value: number): CalendarAttribute;<br>起始版本：7|类名：CalendarAttribute<br>方法 or 属性：startOfWeek(value: number): CalendarAttribute;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CalendarAttribute<br>方法 or 属性：offDays(value: number): CalendarAttribute;<br>起始版本：7|类名：CalendarAttribute<br>方法 or 属性：offDays(value: number): CalendarAttribute;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CalendarAttribute<br>方法 or 属性：direction(value: Axis): CalendarAttribute;<br>起始版本：7|类名：CalendarAttribute<br>方法 or 属性：direction(value: Axis): CalendarAttribute;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CalendarAttribute<br>方法 or 属性：currentDayStyle(value: CurrentDayStyle): CalendarAttribute;<br>起始版本：7|类名：CalendarAttribute<br>方法 or 属性：currentDayStyle(value: CurrentDayStyle): CalendarAttribute;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CalendarAttribute<br>方法 or 属性：nonCurrentDayStyle(value: NonCurrentDayStyle): CalendarAttribute;<br>起始版本：7|类名：CalendarAttribute<br>方法 or 属性：nonCurrentDayStyle(value: NonCurrentDayStyle): CalendarAttribute;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CalendarAttribute<br>方法 or 属性：todayStyle(value: TodayStyle): CalendarAttribute;<br>起始版本：7|类名：CalendarAttribute<br>方法 or 属性：todayStyle(value: TodayStyle): CalendarAttribute;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CalendarAttribute<br>方法 or 属性：weekStyle(value: WeekStyle): CalendarAttribute;<br>起始版本：7|类名：CalendarAttribute<br>方法 or 属性：weekStyle(value: WeekStyle): CalendarAttribute;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CalendarAttribute<br>方法 or 属性：workStateStyle(value: WorkStateStyle): CalendarAttribute;<br>起始版本：7|类名：CalendarAttribute<br>方法 or 属性：workStateStyle(value: WorkStateStyle): CalendarAttribute;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CalendarAttribute<br>方法 or 属性：onSelectChange(event: (event: { year: number; month: number; day: number }) => void): CalendarAttribute;<br>起始版本：7|类名：CalendarAttribute<br>方法 or 属性：onSelectChange(event: (event: { year: number; month: number; day: number }) => void): CalendarAttribute;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：CalendarAttribute<br>方法 or 属性：onRequestData(<br>    event: (event: {<br>      year: number;<br>      month: number;<br>      currentYear: number;<br>      currentMonth: number;<br>      monthState: number;<br>    }) => void,<br>  ): CalendarAttribute;<br>起始版本：7|类名：CalendarAttribute<br>方法 or 属性：onRequestData(<br>    event: (event: {<br>      year: number;<br>      month: number;<br>      currentYear: number;<br>      currentMonth: number;<br>      monthState: number;<br>    }) => void,<br>  ): CalendarAttribute;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const Calendar: CalendarInterface;<br>起始版本：7|类名：global<br>方法 or 属性：declare const Calendar: CalendarInterface;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const CalendarInstance: CalendarAttribute;<br>起始版本：7|类名：global<br>方法 or 属性：declare const CalendarInstance: CalendarAttribute;<br>起始版本：10|calendar.d.ts|
|起始版本有变化|类名：ImageBitmap<br>方法 or 属性：constructor(data: PixelMap);<br>起始版本：8|类名：ImageBitmap<br>方法 or 属性：constructor(data: PixelMap);<br>起始版本：10|canvas.d.ts|
|起始版本有变化|类名：CanvasRenderer<br>方法 or 属性：getPixelMap(sx: number, sy: number, sw: number, sh: number): PixelMap;<br>起始版本：8|类名：CanvasRenderer<br>方法 or 属性：getPixelMap(sx: number, sy: number, sw: number, sh: number): PixelMap;<br>起始版本：10|canvas.d.ts|
|起始版本有变化|类名：CanvasRenderer<br>方法 or 属性：setPixelMap(value?: PixelMap): void;<br>起始版本：8|类名：CanvasRenderer<br>方法 or 属性：setPixelMap(value?: PixelMap): void;<br>起始版本：10|canvas.d.ts|
|起始版本有变化|类名：ColumnSplitInterface<br>起始版本：7|类名：ColumnSplitInterface<br>起始版本：10|column_split.d.ts|
|起始版本有变化|类名：ColumnSplitInterface<br>方法 or 属性：(): ColumnSplitAttribute;<br>起始版本：7|类名：ColumnSplitInterface<br>方法 or 属性：(): ColumnSplitAttribute;<br>起始版本：10|column_split.d.ts|
|起始版本有变化|类名：ColumnSplitAttribute<br>起始版本：7|类名：ColumnSplitAttribute<br>起始版本：10|column_split.d.ts|
|起始版本有变化|类名：ColumnSplitAttribute<br>方法 or 属性：resizeable(value: boolean): ColumnSplitAttribute;<br>起始版本：7|类名：ColumnSplitAttribute<br>方法 or 属性：resizeable(value: boolean): ColumnSplitAttribute;<br>起始版本：10|column_split.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const ColumnSplitInstance: ColumnSplitAttribute;<br>起始版本：7|类名：global<br>方法 or 属性：declare const ColumnSplitInstance: ColumnSplitAttribute;<br>起始版本：10|column_split.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const ColumnSplit: ColumnSplitInterface;<br>起始版本：7|类名：global<br>方法 or 属性：declare const ColumnSplit: ColumnSplitInterface;<br>起始版本：10|column_split.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const StorageProp: (value: string) => PropertyDecorator;<br>起始版本：7|类名：global<br>方法 or 属性：declare const StorageProp: (value: string) => PropertyDecorator;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const StorageLink: (value: string) => PropertyDecorator;<br>起始版本：7|类名：global<br>方法 or 属性：declare const StorageLink: (value: string) => PropertyDecorator;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const Concurrent: MethodDecorator;<br>起始版本：9|类名：global<br>方法 or 属性：declare const Concurrent: MethodDecorator;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const CustomDialog: ClassDecorator;<br>起始版本：7|类名：global<br>方法 or 属性：declare const CustomDialog: ClassDecorator;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const LocalStorageLink: (value: string) => PropertyDecorator;<br>起始版本：9|类名：global<br>方法 or 属性：declare const LocalStorageLink: (value: string) => PropertyDecorator;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const LocalStorageProp: (value: string) => PropertyDecorator;<br>起始版本：9|类名：global<br>方法 or 属性：declare const LocalStorageProp: (value: string) => PropertyDecorator;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：<br>方法 or 属性：function getContext(component?: Object): Context;<br>起始版本：9|类名：<br>方法 or 属性：function getContext(component?: Object): Context;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：<br>方法 or 属性：function postCardAction(component: Object, action: Object): void;<br>起始版本：9|类名：<br>方法 or 属性：function postCardAction(component: Object, action: Object): void;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：AnimateParam<br>方法 or 属性：tempo?: number;<br>起始版本：7|类名：AnimateParam<br>方法 or 属性：tempo?: number;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：AnimateParam<br>方法 or 属性：delay?: number;<br>起始版本：7|类名：AnimateParam<br>方法 or 属性：delay?: number;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：AnimateParam<br>方法 or 属性：iterations?: number;<br>起始版本：7|类名：AnimateParam<br>方法 or 属性：iterations?: number;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：ICurve<br>起始版本：9|类名：ICurve<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：MotionPathOptions<br>起始版本：7|类名：MotionPathOptions<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：MotionPathOptions<br>方法 or 属性：path: string;<br>起始版本：7|类名：MotionPathOptions<br>方法 or 属性：path: string;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：MotionPathOptions<br>方法 or 属性：from?: number;<br>起始版本：7|类名：MotionPathOptions<br>方法 or 属性：from?: number;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：MotionPathOptions<br>方法 or 属性：to?: number;<br>起始版本：7|类名：MotionPathOptions<br>方法 or 属性：to?: number;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：MotionPathOptions<br>方法 or 属性：rotatable?: boolean;<br>起始版本：7|类名：MotionPathOptions<br>方法 or 属性：rotatable?: boolean;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：sharedTransitionOptions<br>起始版本：7|类名：sharedTransitionOptions<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：sharedTransitionOptions<br>方法 or 属性：duration?: number;<br>起始版本：7|类名：sharedTransitionOptions<br>方法 or 属性：duration?: number;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：sharedTransitionOptions<br>方法 or 属性：curve?: Curve \| string;<br>起始版本：7|类名：sharedTransitionOptions<br>方法 or 属性：curve?: Curve \| string;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：sharedTransitionOptions<br>方法 or 属性：delay?: number;<br>起始版本：7|类名：sharedTransitionOptions<br>方法 or 属性：delay?: number;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：sharedTransitionOptions<br>方法 or 属性：motionPath?: MotionPathOptions;<br>起始版本：7|类名：sharedTransitionOptions<br>方法 or 属性：motionPath?: MotionPathOptions;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：sharedTransitionOptions<br>方法 or 属性：zIndex?: number;<br>起始版本：7|类名：sharedTransitionOptions<br>方法 or 属性：zIndex?: number;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：sharedTransitionOptions<br>方法 or 属性：type?: SharedTransitionEffectType;<br>起始版本：7|类名：sharedTransitionOptions<br>方法 or 属性：type?: SharedTransitionEffectType;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：AlignRuleOption<br>起始版本：9|类名：AlignRuleOption<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：AlignRuleOption<br>方法 or 属性：left?: { anchor: string, align: HorizontalAlign };<br>起始版本：9|类名：AlignRuleOption<br>方法 or 属性：left?: { anchor: string, align: HorizontalAlign };<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：AlignRuleOption<br>方法 or 属性：right?: { anchor: string, align: HorizontalAlign };<br>起始版本：9|类名：AlignRuleOption<br>方法 or 属性：right?: { anchor: string, align: HorizontalAlign };<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：AlignRuleOption<br>方法 or 属性：middle?: { anchor: string, align: HorizontalAlign };<br>起始版本：9|类名：AlignRuleOption<br>方法 or 属性：middle?: { anchor: string, align: HorizontalAlign };<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：AlignRuleOption<br>方法 or 属性：top?: { anchor: string, align: VerticalAlign };<br>起始版本：9|类名：AlignRuleOption<br>方法 or 属性：top?: { anchor: string, align: VerticalAlign };<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：AlignRuleOption<br>方法 or 属性：bottom?: { anchor: string, align: VerticalAlign };<br>起始版本：9|类名：AlignRuleOption<br>方法 or 属性：bottom?: { anchor: string, align: VerticalAlign };<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：AlignRuleOption<br>方法 or 属性：center?: { anchor: string, align: VerticalAlign };<br>起始版本：9|类名：AlignRuleOption<br>方法 or 属性：center?: { anchor: string, align: VerticalAlign };<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：TransitionOptions<br>起始版本：9|类名：TransitionOptions<br>起始版本：7|common.d.ts|
|起始版本有变化|类名：TransitionOptions<br>方法 or 属性：type?: TransitionType;<br>起始版本：9|类名：TransitionOptions<br>方法 or 属性：type?: TransitionType;<br>起始版本：7|common.d.ts|
|起始版本有变化|类名：TransitionOptions<br>方法 or 属性：opacity?: number;<br>起始版本：9|类名：TransitionOptions<br>方法 or 属性：opacity?: number;<br>起始版本：7|common.d.ts|
|起始版本有变化|类名：TransitionOptions<br>方法 or 属性：translate?: TranslateOptions;<br>起始版本：9|类名：TransitionOptions<br>方法 or 属性：translate?: TranslateOptions;<br>起始版本：7|common.d.ts|
|起始版本有变化|类名：TransitionOptions<br>方法 or 属性：scale?: ScaleOptions;<br>起始版本：9|类名：TransitionOptions<br>方法 or 属性：scale?: ScaleOptions;<br>起始版本：7|common.d.ts|
|起始版本有变化|类名：TransitionOptions<br>方法 or 属性：rotate?: RotateOptions;<br>起始版本：9|类名：TransitionOptions<br>方法 or 属性：rotate?: RotateOptions;<br>起始版本：7|common.d.ts|
|起始版本有变化|类名：ItemDragInfo<br>起始版本：8|类名：ItemDragInfo<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：ItemDragInfo<br>方法 or 属性：x: number;<br>起始版本：8|类名：ItemDragInfo<br>方法 or 属性：x: number;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：ItemDragInfo<br>方法 or 属性：y: number;<br>起始版本：8|类名：ItemDragInfo<br>方法 or 属性：y: number;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：DragItemInfo<br>起始版本：8|类名：DragItemInfo<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：DragItemInfo<br>方法 or 属性：pixelMap?: PixelMap;<br>起始版本：8|类名：DragItemInfo<br>方法 or 属性：pixelMap?: PixelMap;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：DragItemInfo<br>方法 or 属性：builder?: CustomBuilder;<br>起始版本：8|类名：DragItemInfo<br>方法 or 属性：builder?: CustomBuilder;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：DragItemInfo<br>方法 or 属性：extraInfo?: string;<br>起始版本：8|类名：DragItemInfo<br>方法 or 属性：extraInfo?: string;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：focusControl<br>方法 or 属性：function requestFocus(value: string): boolean;<br>起始版本：9|类名：focusControl<br>方法 or 属性：function requestFocus(value: string): boolean;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：SourceType<br>起始版本：8|类名：SourceType<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：SourceType<br>方法 or 属性：Unknown<br>起始版本：8|类名：SourceType<br>方法 or 属性：Unknown<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：SourceType<br>方法 or 属性：Mouse<br>起始版本：8|类名：SourceType<br>方法 or 属性：Mouse<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：SourceType<br>方法 or 属性：TouchScreen<br>起始版本：8|类名：SourceType<br>方法 or 属性：TouchScreen<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：SourceTool<br>起始版本：9|类名：SourceTool<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：SourceTool<br>方法 or 属性：Unknown<br>起始版本：9|类名：SourceTool<br>方法 or 属性：Unknown<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：RepeatMode<br>起始版本：9|类名：RepeatMode<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：RepeatMode<br>方法 or 属性：Repeat<br>起始版本：9|类名：RepeatMode<br>方法 or 属性：Repeat<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：RepeatMode<br>方法 or 属性：Stretch<br>起始版本：9|类名：RepeatMode<br>方法 or 属性：Stretch<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：RepeatMode<br>方法 or 属性：Round<br>起始版本：9|类名：RepeatMode<br>方法 or 属性：Round<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：RepeatMode<br>方法 or 属性：Space<br>起始版本：9|类名：RepeatMode<br>方法 or 属性：Space<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：BlurStyle<br>起始版本：9|类名：BlurStyle<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：BlurStyle<br>方法 or 属性：Thin<br>起始版本：9|类名：BlurStyle<br>方法 or 属性：Thin<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：BlurStyle<br>方法 or 属性：Regular<br>起始版本：9|类名：BlurStyle<br>方法 or 属性：Regular<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：BlurStyle<br>方法 or 属性：Thick<br>起始版本：9|类名：BlurStyle<br>方法 or 属性：Thick<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：BaseEvent<br>方法 or 属性：pressure: number;<br>起始版本：9|类名：BaseEvent<br>方法 or 属性：pressure: number;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：BaseEvent<br>方法 or 属性：tiltX: number;<br>起始版本：9|类名：BaseEvent<br>方法 or 属性：tiltX: number;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：BaseEvent<br>方法 or 属性：tiltY: number;<br>起始版本：9|类名：BaseEvent<br>方法 or 属性：tiltY: number;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：BaseEvent<br>方法 or 属性：sourceTool: SourceTool;<br>起始版本：9|类名：BaseEvent<br>方法 or 属性：sourceTool: SourceTool;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：BorderImageOption<br>起始版本：9|类名：BorderImageOption<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：BorderImageOption<br>方法 or 属性：slice?: Length \| EdgeWidths,<br>起始版本：9|类名：BorderImageOption<br>方法 or 属性：slice?: Length \| EdgeWidths,<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：BorderImageOption<br>方法 or 属性：repeat?: RepeatMode,<br>起始版本：9|类名：BorderImageOption<br>方法 or 属性：repeat?: RepeatMode,<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：BorderImageOption<br>方法 or 属性：source?: string \| Resource \| LinearGradient,<br>起始版本：9|类名：BorderImageOption<br>方法 or 属性：source?: string \| Resource \| LinearGradient,<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：BorderImageOption<br>方法 or 属性：width?: Length \| EdgeWidths,<br>起始版本：9|类名：BorderImageOption<br>方法 or 属性：width?: Length \| EdgeWidths,<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：BorderImageOption<br>方法 or 属性：outset?: Length \| EdgeWidths,<br>起始版本：9|类名：BorderImageOption<br>方法 or 属性：outset?: Length \| EdgeWidths,<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：BorderImageOption<br>方法 or 属性：fill?: boolean<br>起始版本：9|类名：BorderImageOption<br>方法 or 属性：fill?: boolean<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：MouseEvent<br>起始版本：8|类名：MouseEvent<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：MouseEvent<br>方法 or 属性：button: MouseButton;<br>起始版本：8|类名：MouseEvent<br>方法 or 属性：button: MouseButton;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：MouseEvent<br>方法 or 属性：action: MouseAction;<br>起始版本：8|类名：MouseEvent<br>方法 or 属性：action: MouseAction;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：MouseEvent<br>方法 or 属性：screenX: number;<br>起始版本：8|类名：MouseEvent<br>方法 or 属性：screenX: number;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：MouseEvent<br>方法 or 属性：screenY: number;<br>起始版本：8|类名：MouseEvent<br>方法 or 属性：screenY: number;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：MouseEvent<br>方法 or 属性：x: number;<br>起始版本：8|类名：MouseEvent<br>方法 or 属性：x: number;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：MouseEvent<br>方法 or 属性：y: number;<br>起始版本：8|类名：MouseEvent<br>方法 or 属性：y: number;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：MouseEvent<br>方法 or 属性：stopPropagation?: () => void;<br>起始版本：8|类名：MouseEvent<br>方法 or 属性：stopPropagation?: () => void;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：TouchObject<br>起始版本：7|类名：TouchObject<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：TouchObject<br>方法 or 属性：type: TouchType;<br>起始版本：7|类名：TouchObject<br>方法 or 属性：type: TouchType;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：TouchObject<br>方法 or 属性：id: number;<br>起始版本：7|类名：TouchObject<br>方法 or 属性：id: number;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：TouchObject<br>方法 or 属性：screenX: number;<br>起始版本：7|类名：TouchObject<br>方法 or 属性：screenX: number;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：TouchObject<br>方法 or 属性：screenY: number;<br>起始版本：7|类名：TouchObject<br>方法 or 属性：screenY: number;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：TouchObject<br>方法 or 属性：x: number;<br>起始版本：7|类名：TouchObject<br>方法 or 属性：x: number;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：TouchObject<br>方法 or 属性：y: number;<br>起始版本：7|类名：TouchObject<br>方法 or 属性：y: number;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：TouchEvent<br>起始版本：7|类名：TouchEvent<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：TouchEvent<br>方法 or 属性：type: TouchType;<br>起始版本：7|类名：TouchEvent<br>方法 or 属性：type: TouchType;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：TouchEvent<br>方法 or 属性：touches: TouchObject[];<br>起始版本：7|类名：TouchEvent<br>方法 or 属性：touches: TouchObject[];<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：TouchEvent<br>方法 or 属性：changedTouches: TouchObject[];<br>起始版本：7|类名：TouchEvent<br>方法 or 属性：changedTouches: TouchObject[];<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：TouchEvent<br>方法 or 属性：stopPropagation?: () => void;<br>起始版本：7|类名：TouchEvent<br>方法 or 属性：stopPropagation?: () => void;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：DragEvent<br>起始版本：7|类名：DragEvent<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：DragEvent<br>方法 or 属性：getX(): number;<br>起始版本：7|类名：DragEvent<br>方法 or 属性：getX(): number;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：DragEvent<br>方法 or 属性：getY(): number;<br>起始版本：7|类名：DragEvent<br>方法 or 属性：getY(): number;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：KeyEvent<br>起始版本：7|类名：KeyEvent<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：KeyEvent<br>方法 or 属性：type: KeyType;<br>起始版本：7|类名：KeyEvent<br>方法 or 属性：type: KeyType;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：KeyEvent<br>方法 or 属性：keyCode: number;<br>起始版本：7|类名：KeyEvent<br>方法 or 属性：keyCode: number;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：KeyEvent<br>方法 or 属性：keyText: string;<br>起始版本：7|类名：KeyEvent<br>方法 or 属性：keyText: string;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：KeyEvent<br>方法 or 属性：keySource: KeySource;<br>起始版本：7|类名：KeyEvent<br>方法 or 属性：keySource: KeySource;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：KeyEvent<br>方法 or 属性：deviceId: number;<br>起始版本：7|类名：KeyEvent<br>方法 or 属性：deviceId: number;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：KeyEvent<br>方法 or 属性：metaKey: number;<br>起始版本：7|类名：KeyEvent<br>方法 or 属性：metaKey: number;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：KeyEvent<br>方法 or 属性：timestamp: number;<br>起始版本：7|类名：KeyEvent<br>方法 or 属性：timestamp: number;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：KeyEvent<br>方法 or 属性：stopPropagation?: () => void;<br>起始版本：7|类名：KeyEvent<br>方法 or 属性：stopPropagation?: () => void;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：PopupOptions<br>起始版本：7|类名：PopupOptions<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：PopupOptions<br>方法 or 属性：message: string;<br>起始版本：7|类名：PopupOptions<br>方法 or 属性：message: string;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：PopupOptions<br>方法 or 属性：arrowOffset?: Length;<br>起始版本：9|类名：PopupOptions<br>方法 or 属性：arrowOffset?: Length;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：PopupOptions<br>方法 or 属性：showInSubWindow?: boolean;<br>起始版本：9|类名：PopupOptions<br>方法 or 属性：showInSubWindow?: boolean;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CustomPopupOptions<br>起始版本：8|类名：CustomPopupOptions<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CustomPopupOptions<br>方法 or 属性：builder: CustomBuilder;<br>起始版本：8|类名：CustomPopupOptions<br>方法 or 属性：builder: CustomBuilder;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CustomPopupOptions<br>方法 or 属性：placement?: Placement;<br>起始版本：8|类名：CustomPopupOptions<br>方法 or 属性：placement?: Placement;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CustomPopupOptions<br>方法 or 属性：popupColor?: Color \| string \| Resource \| number;<br>起始版本：8|类名：CustomPopupOptions<br>方法 or 属性：popupColor?: Color \| string \| Resource \| number;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CustomPopupOptions<br>方法 or 属性：enableArrow?: boolean;<br>起始版本：8|类名：CustomPopupOptions<br>方法 or 属性：enableArrow?: boolean;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CustomPopupOptions<br>方法 or 属性：autoCancel?: boolean;<br>起始版本：8|类名：CustomPopupOptions<br>方法 or 属性：autoCancel?: boolean;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CustomPopupOptions<br>方法 or 属性：arrowOffset?: Length;<br>起始版本：9|类名：CustomPopupOptions<br>方法 or 属性：arrowOffset?: Length;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CustomPopupOptions<br>方法 or 属性：showInSubWindow?: boolean;<br>起始版本：9|类名：CustomPopupOptions<br>方法 or 属性：showInSubWindow?: boolean;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CommonMethod<br>方法 or 属性：hitTestBehavior(value: HitTestMode): T;<br>起始版本：9|类名：CommonMethod<br>方法 or 属性：hitTestBehavior(value: HitTestMode): T;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CommonMethod<br>方法 or 属性：borderImage(value: BorderImageOption): T;<br>起始版本：9|类名：CommonMethod<br>方法 or 属性：borderImage(value: BorderImageOption): T;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CommonMethod<br>方法 or 属性：onHover(event: (isHover?: boolean) => void): T;<br>起始版本：8|类名：CommonMethod<br>方法 or 属性：onHover(event: (isHover?: boolean) => void): T;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CommonMethod<br>方法 or 属性：hoverEffect(value: HoverEffect): T;<br>起始版本：8|类名：CommonMethod<br>方法 or 属性：hoverEffect(value: HoverEffect): T;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CommonMethod<br>方法 or 属性：onMouse(event: (event?: MouseEvent) => void): T;<br>起始版本：8|类名：CommonMethod<br>方法 or 属性：onMouse(event: (event?: MouseEvent) => void): T;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CommonMethod<br>方法 or 属性：onTouch(event: (event?: TouchEvent) => void): T;<br>起始版本：7|类名：CommonMethod<br>方法 or 属性：onTouch(event: (event?: TouchEvent) => void): T;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CommonMethod<br>方法 or 属性：onKeyEvent(event: (event?: KeyEvent) => void): T;<br>起始版本：7|类名：CommonMethod<br>方法 or 属性：onKeyEvent(event: (event?: KeyEvent) => void): T;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CommonMethod<br>方法 or 属性：focusable(value: boolean): T;<br>起始版本：8|类名：CommonMethod<br>方法 or 属性：focusable(value: boolean): T;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CommonMethod<br>方法 or 属性：onFocus(event: () => void): T;<br>起始版本：8|类名：CommonMethod<br>方法 or 属性：onFocus(event: () => void): T;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CommonMethod<br>方法 or 属性：onBlur(event: () => void): T;<br>起始版本：8|类名：CommonMethod<br>方法 or 属性：onBlur(event: () => void): T;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CommonMethod<br>方法 or 属性：tabIndex(index: number): T;<br>起始版本：9|类名：CommonMethod<br>方法 or 属性：tabIndex(index: number): T;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CommonMethod<br>方法 or 属性：defaultFocus(value: boolean): T;<br>起始版本：9|类名：CommonMethod<br>方法 or 属性：defaultFocus(value: boolean): T;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CommonMethod<br>方法 or 属性：groupDefaultFocus(value: boolean): T;<br>起始版本：9|类名：CommonMethod<br>方法 or 属性：groupDefaultFocus(value: boolean): T;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CommonMethod<br>方法 or 属性：focusOnTouch(value: boolean): T;<br>起始版本：9|类名：CommonMethod<br>方法 or 属性：focusOnTouch(value: boolean): T;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CommonMethod<br>方法 or 属性：gesture(gesture: GestureType, mask?: GestureMask): T;<br>起始版本：7|类名：CommonMethod<br>方法 or 属性：gesture(gesture: GestureType, mask?: GestureMask): T;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CommonMethod<br>方法 or 属性：priorityGesture(gesture: GestureType, mask?: GestureMask): T;<br>起始版本：7|类名：CommonMethod<br>方法 or 属性：priorityGesture(gesture: GestureType, mask?: GestureMask): T;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CommonMethod<br>方法 or 属性：parallelGesture(gesture: GestureType, mask?: GestureMask): T;<br>起始版本：7|类名：CommonMethod<br>方法 or 属性：parallelGesture(gesture: GestureType, mask?: GestureMask): T;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CommonMethod<br>方法 or 属性：gridSpan(value: number): T;<br>起始版本：7|类名：CommonMethod<br>方法 or 属性：gridSpan(value: number): T;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CommonMethod<br>方法 or 属性：gridOffset(value: number): T;<br>起始版本：7|类名：CommonMethod<br>方法 or 属性：gridOffset(value: number): T;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CommonMethod<br>方法 or 属性：transform(value: object): T;<br>起始版本：7|类名：CommonMethod<br>方法 or 属性：transform(value: object): T;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CommonMethod<br>方法 or 属性：onAreaChange(event: (oldValue: Area, newValue: Area) => void): T;<br>起始版本：8|类名：CommonMethod<br>方法 or 属性：onAreaChange(event: (oldValue: Area, newValue: Area) => void): T;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CommonMethod<br>方法 or 属性：sharedTransition(id: string, options?: sharedTransitionOptions): T;<br>起始版本：7|类名：CommonMethod<br>方法 or 属性：sharedTransition(id: string, options?: sharedTransitionOptions): T;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CommonMethod<br>方法 or 属性：alignRules(value: AlignRuleOption): T;<br>起始版本：9|类名：CommonMethod<br>方法 or 属性：alignRules(value: AlignRuleOption): T;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CommonMethod<br>方法 or 属性：onDragStart(event: (event?: DragEvent, extraParams?: string) => CustomBuilder \| DragItemInfo): T;<br>起始版本：8|类名：CommonMethod<br>方法 or 属性：onDragStart(event: (event?: DragEvent, extraParams?: string) => CustomBuilder \| DragItemInfo): T;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CommonMethod<br>方法 or 属性：onDragEnter(event: (event?: DragEvent, extraParams?: string) => void): T;<br>起始版本：8|类名：CommonMethod<br>方法 or 属性：onDragEnter(event: (event?: DragEvent, extraParams?: string) => void): T;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CommonMethod<br>方法 or 属性：onDragMove(event: (event?: DragEvent, extraParams?: string) => void): T;<br>起始版本：8|类名：CommonMethod<br>方法 or 属性：onDragMove(event: (event?: DragEvent, extraParams?: string) => void): T;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CommonMethod<br>方法 or 属性：onDragLeave(event: (event?: DragEvent, extraParams?: string) => void): T;<br>起始版本：8|类名：CommonMethod<br>方法 or 属性：onDragLeave(event: (event?: DragEvent, extraParams?: string) => void): T;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CommonMethod<br>方法 or 属性：onDrop(event: (event?: DragEvent, extraParams?: string) => void): T;<br>起始版本：8|类名：CommonMethod<br>方法 or 属性：onDrop(event: (event?: DragEvent, extraParams?: string) => void): T;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CommonMethod<br>方法 or 属性：motionPath(value: MotionPathOptions): T;<br>起始版本：7|类名：CommonMethod<br>方法 or 属性：motionPath(value: MotionPathOptions): T;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CommonMethod<br>方法 or 属性：geometryTransition(id: string): T;<br>起始版本：7|类名：CommonMethod<br>方法 or 属性：geometryTransition(id: string): T;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CommonMethod<br>方法 or 属性：onVisibleAreaChange(ratios: Array\<number>, event: (isVisible: boolean, currentRatio: number) => void): T;<br>起始版本：9|类名：CommonMethod<br>方法 or 属性：onVisibleAreaChange(ratios: Array\<number>, event: (isVisible: boolean, currentRatio: number) => void): T;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：LinearGradient<br>起始版本：9|类名：LinearGradient<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：LayoutBorderInfo<br>起始版本：9|类名：LayoutBorderInfo<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：LayoutBorderInfo<br>方法 or 属性：borderWidth: EdgeWidths,<br>起始版本：9|类名：LayoutBorderInfo<br>方法 or 属性：borderWidth: EdgeWidths,<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：LayoutBorderInfo<br>方法 or 属性：margin: Margin,<br>起始版本：9|类名：LayoutBorderInfo<br>方法 or 属性：margin: Margin,<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：LayoutBorderInfo<br>方法 or 属性：padding: Padding,<br>起始版本：9|类名：LayoutBorderInfo<br>方法 or 属性：padding: Padding,<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：LayoutInfo<br>起始版本：9|类名：LayoutInfo<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：LayoutInfo<br>方法 or 属性：position: Position,<br>起始版本：9|类名：LayoutInfo<br>方法 or 属性：position: Position,<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：LayoutInfo<br>方法 or 属性：constraint: ConstraintSizeOptions,<br>起始版本：9|类名：LayoutInfo<br>方法 or 属性：constraint: ConstraintSizeOptions,<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：LayoutChild<br>起始版本：9|类名：LayoutChild<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：LayoutChild<br>方法 or 属性：name: string,<br>起始版本：9|类名：LayoutChild<br>方法 or 属性：name: string,<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：LayoutChild<br>方法 or 属性：id: string,<br>起始版本：9|类名：LayoutChild<br>方法 or 属性：id: string,<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：LayoutChild<br>方法 or 属性：constraint: ConstraintSizeOptions,<br>起始版本：9|类名：LayoutChild<br>方法 or 属性：constraint: ConstraintSizeOptions,<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：LayoutChild<br>方法 or 属性：borderInfo: LayoutBorderInfo,<br>起始版本：9|类名：LayoutChild<br>方法 or 属性：borderInfo: LayoutBorderInfo,<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：LayoutChild<br>方法 or 属性：position: Position,<br>起始版本：9|类名：LayoutChild<br>方法 or 属性：position: Position,<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：LayoutChild<br>方法 or 属性：measure(childConstraint: ConstraintSizeOptions),<br>起始版本：9|类名：LayoutChild<br>方法 or 属性：measure(childConstraint: ConstraintSizeOptions),<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：LayoutChild<br>方法 or 属性：layout(childLayoutInfo: LayoutInfo)<br>起始版本：9|类名：LayoutChild<br>方法 or 属性：layout(childLayoutInfo: LayoutInfo)<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CustomComponent<br>方法 or 属性：onLayout?(children: Array\<LayoutChild>, constraint: ConstraintSizeOptions): void;<br>起始版本：9|类名：CustomComponent<br>方法 or 属性：onLayout?(children: Array\<LayoutChild>, constraint: ConstraintSizeOptions): void;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CustomComponent<br>方法 or 属性：onMeasure?(children: Array\<LayoutChild>, constraint: ConstraintSizeOptions): void;<br>起始版本：9|类名：CustomComponent<br>方法 or 属性：onMeasure?(children: Array\<LayoutChild>, constraint: ConstraintSizeOptions): void;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CustomComponent<br>方法 or 属性：onPageShow?(): void;<br>起始版本：7|类名：CustomComponent<br>方法 or 属性：onPageShow?(): void;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CustomComponent<br>方法 or 属性：onPageHide?(): void;<br>起始版本：7|类名：CustomComponent<br>方法 or 属性：onPageHide?(): void;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CustomComponent<br>方法 or 属性：onBackPress?(): void;<br>起始版本：7|类名：CustomComponent<br>方法 or 属性：onBackPress?(): void;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：CustomComponent<br>方法 or 属性：pageTransition?(): void;<br>起始版本：9|类名：CustomComponent<br>方法 or 属性：pageTransition?(): void;<br>起始版本：10|common.d.ts|
|起始版本有变化|类名：AppStorage<br>起始版本：7|类名：AppStorage<br>起始版本：10|common_ts_ets_api.d.ts|
|起始版本有变化|类名：AppStorage<br>方法 or 属性：static Link(propName: string): any;<br>起始版本：7|类名：AppStorage<br>方法 or 属性：static Link(propName: string): any;<br>起始版本：10|common_ts_ets_api.d.ts|
|起始版本有变化|类名：AppStorage<br>方法 or 属性：static SetAndLink\<T>(propName: string, defaultValue: T): SubscribedAbstractProperty\<T>;<br>起始版本：7|类名：AppStorage<br>方法 or 属性：static SetAndLink\<T>(propName: string, defaultValue: T): SubscribedAbstractProperty\<T>;<br>起始版本：10|common_ts_ets_api.d.ts|
|起始版本有变化|类名：AppStorage<br>方法 or 属性：static Prop(propName: string): any;<br>起始版本：7|类名：AppStorage<br>方法 or 属性：static Prop(propName: string): any;<br>起始版本：10|common_ts_ets_api.d.ts|
|起始版本有变化|类名：AppStorage<br>方法 or 属性：static SetAndProp\<S>(propName: string, defaultValue: S): SubscribedAbstractProperty\<S>;<br>起始版本：7|类名：AppStorage<br>方法 or 属性：static SetAndProp\<S>(propName: string, defaultValue: S): SubscribedAbstractProperty\<S>;<br>起始版本：10|common_ts_ets_api.d.ts|
|起始版本有变化|类名：AppStorage<br>方法 or 属性：static Has(propName: string): boolean;<br>起始版本：7|类名：AppStorage<br>方法 or 属性：static Has(propName: string): boolean;<br>起始版本：10|common_ts_ets_api.d.ts|
|起始版本有变化|类名：AppStorage<br>方法 or 属性：static Get\<T>(propName: string): T \| undefined;<br>起始版本：7|类名：AppStorage<br>方法 or 属性：static Get\<T>(propName: string): T \| undefined;<br>起始版本：10|common_ts_ets_api.d.ts|
|起始版本有变化|类名：AppStorage<br>方法 or 属性：static Set\<T>(propName: string, newValue: T): boolean;<br>起始版本：7|类名：AppStorage<br>方法 or 属性：static Set\<T>(propName: string, newValue: T): boolean;<br>起始版本：10|common_ts_ets_api.d.ts|
|起始版本有变化|类名：AppStorage<br>方法 or 属性：static SetOrCreate\<T>(propName: string, newValue: T): void;<br>起始版本：7|类名：AppStorage<br>方法 or 属性：static SetOrCreate\<T>(propName: string, newValue: T): void;<br>起始版本：10|common_ts_ets_api.d.ts|
|起始版本有变化|类名：AppStorage<br>方法 or 属性：static Delete(propName: string): boolean;<br>起始版本：7|类名：AppStorage<br>方法 or 属性：static Delete(propName: string): boolean;<br>起始版本：10|common_ts_ets_api.d.ts|
|起始版本有变化|类名：AppStorage<br>方法 or 属性：static Keys(): IterableIterator\<string>;<br>起始版本：7|类名：AppStorage<br>方法 or 属性：static Keys(): IterableIterator\<string>;<br>起始版本：10|common_ts_ets_api.d.ts|
|起始版本有变化|类名：AppStorage<br>方法 or 属性：static Clear(): boolean;<br>起始版本：9|类名：AppStorage<br>方法 or 属性：static Clear(): boolean;<br>起始版本：10|common_ts_ets_api.d.ts|
|起始版本有变化|类名：AppStorage<br>方法 or 属性：static IsMutable(propName: string): boolean;<br>起始版本：7|类名：AppStorage<br>方法 or 属性：static IsMutable(propName: string): boolean;<br>起始版本：10|common_ts_ets_api.d.ts|
|起始版本有变化|类名：AppStorage<br>方法 or 属性：static Size(): number;<br>起始版本：7|类名：AppStorage<br>方法 or 属性：static Size(): number;<br>起始版本：10|common_ts_ets_api.d.ts|
|起始版本有变化|类名：SubscribedAbstractProperty<br>方法 or 属性：info(): string;<br>起始版本：7|类名：SubscribedAbstractProperty<br>方法 or 属性：info(): string;<br>起始版本：10|common_ts_ets_api.d.ts|
|起始版本有变化|类名：SubscribedAbstractProperty<br>方法 or 属性：abstract get(): T;<br>起始版本：9|类名：SubscribedAbstractProperty<br>方法 or 属性：abstract get(): T;<br>起始版本：10|common_ts_ets_api.d.ts|
|起始版本有变化|类名：SubscribedAbstractProperty<br>方法 or 属性：abstract set(newValue: T): void;<br>起始版本：9|类名：SubscribedAbstractProperty<br>方法 or 属性：abstract set(newValue: T): void;<br>起始版本：10|common_ts_ets_api.d.ts|
|起始版本有变化|类名：Environment<br>起始版本：7|类名：Environment<br>起始版本：10|common_ts_ets_api.d.ts|
|起始版本有变化|类名：Environment<br>方法 or 属性：static EnvProp\<S>(key: string, value: S): boolean;<br>起始版本：7|类名：Environment<br>方法 or 属性：static EnvProp\<S>(key: string, value: S): boolean;<br>起始版本：10|common_ts_ets_api.d.ts|
|起始版本有变化|类名：Environment<br>方法 or 属性：static EnvProps(<br>    props: {<br>      key: string;<br>      defaultValue: any;<br>    }[],<br>  ): void;<br>起始版本：7|类名：Environment<br>方法 or 属性：static EnvProps(<br>    props: {<br>      key: string;<br>      defaultValue: any;<br>    }[],<br>  ): void;<br>起始版本：10|common_ts_ets_api.d.ts|
|起始版本有变化|类名：Environment<br>方法 or 属性：static Keys(): Array\<string>;<br>起始版本：7|类名：Environment<br>方法 or 属性：static Keys(): Array\<string>;<br>起始版本：10|common_ts_ets_api.d.ts|
|起始版本有变化|类名：PersistentStorage<br>起始版本：7|类名：PersistentStorage<br>起始版本：10|common_ts_ets_api.d.ts|
|起始版本有变化|类名：PersistentStorage<br>方法 or 属性：static PersistProp\<T>(key: string, defaultValue: T): void;<br>起始版本：7|类名：PersistentStorage<br>方法 or 属性：static PersistProp\<T>(key: string, defaultValue: T): void;<br>起始版本：10|common_ts_ets_api.d.ts|
|起始版本有变化|类名：PersistentStorage<br>方法 or 属性：static DeleteProp(key: string): void;<br>起始版本：7|类名：PersistentStorage<br>方法 or 属性：static DeleteProp(key: string): void;<br>起始版本：10|common_ts_ets_api.d.ts|
|起始版本有变化|类名：PersistentStorage<br>方法 or 属性：static PersistProps(<br>    properties: {<br>      key: string;<br>      defaultValue: any;<br>    }[],<br>  ): void;<br>起始版本：7|类名：PersistentStorage<br>方法 or 属性：static PersistProps(<br>    properties: {<br>      key: string;<br>      defaultValue: any;<br>    }[],<br>  ): void;<br>起始版本：10|common_ts_ets_api.d.ts|
|起始版本有变化|类名：PersistentStorage<br>方法 or 属性：static Keys(): Array\<string>;<br>起始版本：7|类名：PersistentStorage<br>方法 or 属性：static Keys(): Array\<string>;<br>起始版本：10|common_ts_ets_api.d.ts|
|起始版本有变化|类名：LocalStorage<br>起始版本：9|类名：LocalStorage<br>起始版本：10|common_ts_ets_api.d.ts|
|起始版本有变化|类名：LocalStorage<br>方法 or 属性：constructor(initializingProperties?: Object);<br>起始版本：9|类名：LocalStorage<br>方法 or 属性：constructor(initializingProperties?: Object);<br>起始版本：10|common_ts_ets_api.d.ts|
|起始版本有变化|类名：LocalStorage<br>方法 or 属性：static GetShared(): LocalStorage;<br>起始版本：9|类名：LocalStorage<br>方法 or 属性：static GetShared(): LocalStorage;<br>起始版本：10|common_ts_ets_api.d.ts|
|起始版本有变化|类名：LocalStorage<br>方法 or 属性：has(propName: string): boolean;<br>起始版本：9|类名：LocalStorage<br>方法 or 属性：has(propName: string): boolean;<br>起始版本：10|common_ts_ets_api.d.ts|
|起始版本有变化|类名：LocalStorage<br>方法 or 属性：keys(): IterableIterator\<string>;<br>起始版本：9|类名：LocalStorage<br>方法 or 属性：keys(): IterableIterator\<string>;<br>起始版本：10|common_ts_ets_api.d.ts|
|起始版本有变化|类名：LocalStorage<br>方法 or 属性：size(): number;<br>起始版本：9|类名：LocalStorage<br>方法 or 属性：size(): number;<br>起始版本：10|common_ts_ets_api.d.ts|
|起始版本有变化|类名：LocalStorage<br>方法 or 属性：get\<T>(propName: string): T \| undefined;<br>起始版本：9|类名：LocalStorage<br>方法 or 属性：get\<T>(propName: string): T \| undefined;<br>起始版本：10|common_ts_ets_api.d.ts|
|起始版本有变化|类名：LocalStorage<br>方法 or 属性：set\<T>(propName: string, newValue: T): boolean;<br>起始版本：9|类名：LocalStorage<br>方法 or 属性：set\<T>(propName: string, newValue: T): boolean;<br>起始版本：10|common_ts_ets_api.d.ts|
|起始版本有变化|类名：LocalStorage<br>方法 or 属性：setOrCreate\<T>(propName: string, newValue: T): boolean;<br>起始版本：9|类名：LocalStorage<br>方法 or 属性：setOrCreate\<T>(propName: string, newValue: T): boolean;<br>起始版本：10|common_ts_ets_api.d.ts|
|起始版本有变化|类名：LocalStorage<br>方法 or 属性：link\<T>(propName: string): SubscribedAbstractProperty\<T>;<br>起始版本：9|类名：LocalStorage<br>方法 or 属性：link\<T>(propName: string): SubscribedAbstractProperty\<T>;<br>起始版本：10|common_ts_ets_api.d.ts|
|起始版本有变化|类名：LocalStorage<br>方法 or 属性：setAndLink\<T>(propName: string, defaultValue: T): SubscribedAbstractProperty\<T>;<br>起始版本：9|类名：LocalStorage<br>方法 or 属性：setAndLink\<T>(propName: string, defaultValue: T): SubscribedAbstractProperty\<T>;<br>起始版本：10|common_ts_ets_api.d.ts|
|起始版本有变化|类名：LocalStorage<br>方法 or 属性：prop\<S>(propName: string): SubscribedAbstractProperty\<S>;<br>起始版本：9|类名：LocalStorage<br>方法 or 属性：prop\<S>(propName: string): SubscribedAbstractProperty\<S>;<br>起始版本：10|common_ts_ets_api.d.ts|
|起始版本有变化|类名：LocalStorage<br>方法 or 属性：setAndProp\<S>(propName: string, defaultValue: S): SubscribedAbstractProperty\<S>;<br>起始版本：9|类名：LocalStorage<br>方法 or 属性：setAndProp\<S>(propName: string, defaultValue: S): SubscribedAbstractProperty\<S>;<br>起始版本：10|common_ts_ets_api.d.ts|
|起始版本有变化|类名：LocalStorage<br>方法 or 属性：delete(propName: string): boolean;<br>起始版本：9|类名：LocalStorage<br>方法 or 属性：delete(propName: string): boolean;<br>起始版本：10|common_ts_ets_api.d.ts|
|起始版本有变化|类名：LocalStorage<br>方法 or 属性：clear(): boolean;<br>起始版本：9|类名：LocalStorage<br>方法 or 属性：clear(): boolean;<br>起始版本：10|common_ts_ets_api.d.ts|
|起始版本有变化|类名：ContextMenu<br>起始版本：8|类名：ContextMenu<br>起始版本：10|context_menu.d.ts|
|起始版本有变化|类名：ContextMenu<br>方法 or 属性：static close();<br>起始版本：8|类名：ContextMenu<br>方法 or 属性：static close();<br>起始版本：10|context_menu.d.ts|
|起始版本有变化|类名：CustomDialogControllerOptions<br>起始版本：7|类名：CustomDialogControllerOptions<br>起始版本：10|custom_dialog_controller.d.ts|
|起始版本有变化|类名：CustomDialogControllerOptions<br>方法 or 属性：builder: any;<br>起始版本：7|类名：CustomDialogControllerOptions<br>方法 or 属性：builder: any;<br>起始版本：10|custom_dialog_controller.d.ts|
|起始版本有变化|类名：CustomDialogControllerOptions<br>方法 or 属性：cancel?: () => void;<br>起始版本：7|类名：CustomDialogControllerOptions<br>方法 or 属性：cancel?: () => void;<br>起始版本：10|custom_dialog_controller.d.ts|
|起始版本有变化|类名：CustomDialogControllerOptions<br>方法 or 属性：autoCancel?: boolean;<br>起始版本：7|类名：CustomDialogControllerOptions<br>方法 or 属性：autoCancel?: boolean;<br>起始版本：10|custom_dialog_controller.d.ts|
|起始版本有变化|类名：CustomDialogControllerOptions<br>方法 or 属性：alignment?: DialogAlignment;<br>起始版本：7|类名：CustomDialogControllerOptions<br>方法 or 属性：alignment?: DialogAlignment;<br>起始版本：10|custom_dialog_controller.d.ts|
|起始版本有变化|类名：CustomDialogControllerOptions<br>方法 or 属性：offset?: Offset;<br>起始版本：7|类名：CustomDialogControllerOptions<br>方法 or 属性：offset?: Offset;<br>起始版本：10|custom_dialog_controller.d.ts|
|起始版本有变化|类名：CustomDialogControllerOptions<br>方法 or 属性：customStyle?: boolean;<br>起始版本：7|类名：CustomDialogControllerOptions<br>方法 or 属性：customStyle?: boolean;<br>起始版本：10|custom_dialog_controller.d.ts|
|起始版本有变化|类名：CustomDialogControllerOptions<br>方法 or 属性：gridCount?: number;<br>起始版本：8|类名：CustomDialogControllerOptions<br>方法 or 属性：gridCount?: number;<br>起始版本：10|custom_dialog_controller.d.ts|
|起始版本有变化|类名：CustomDialogController<br>起始版本：7|类名：CustomDialogController<br>起始版本：10|custom_dialog_controller.d.ts|
|起始版本有变化|类名：CustomDialogController<br>方法 or 属性：constructor(value: CustomDialogControllerOptions);<br>起始版本：7|类名：CustomDialogController<br>方法 or 属性：constructor(value: CustomDialogControllerOptions);<br>起始版本：10|custom_dialog_controller.d.ts|
|起始版本有变化|类名：CustomDialogController<br>方法 or 属性：open();<br>起始版本：7|类名：CustomDialogController<br>方法 or 属性：open();<br>起始版本：10|custom_dialog_controller.d.ts|
|起始版本有变化|类名：CustomDialogController<br>方法 or 属性：close();<br>起始版本：7|类名：CustomDialogController<br>方法 or 属性：close();<br>起始版本：10|custom_dialog_controller.d.ts|
|起始版本有变化|类名：DatePickerResult<br>起始版本：8|类名：DatePickerResult<br>起始版本：10|date_picker.d.ts|
|起始版本有变化|类名：DatePickerResult<br>方法 or 属性：year?: number;<br>起始版本：8|类名：DatePickerResult<br>方法 or 属性：year?: number;<br>起始版本：10|date_picker.d.ts|
|起始版本有变化|类名：DatePickerResult<br>方法 or 属性：month?: number;<br>起始版本：8|类名：DatePickerResult<br>方法 or 属性：month?: number;<br>起始版本：10|date_picker.d.ts|
|起始版本有变化|类名：DatePickerResult<br>方法 or 属性：day?: number;<br>起始版本：8|类名：DatePickerResult<br>方法 or 属性：day?: number;<br>起始版本：10|date_picker.d.ts|
|起始版本有变化|类名：DatePickerOptions<br>起始版本：8|类名：DatePickerOptions<br>起始版本：10|date_picker.d.ts|
|起始版本有变化|类名：DatePickerOptions<br>方法 or 属性：start?: Date;<br>起始版本：8|类名：DatePickerOptions<br>方法 or 属性：start?: Date;<br>起始版本：10|date_picker.d.ts|
|起始版本有变化|类名：DatePickerOptions<br>方法 or 属性：end?: Date;<br>起始版本：8|类名：DatePickerOptions<br>方法 or 属性：end?: Date;<br>起始版本：10|date_picker.d.ts|
|起始版本有变化|类名：DatePickerOptions<br>方法 or 属性：selected?: Date;<br>起始版本：8|类名：DatePickerOptions<br>方法 or 属性：selected?: Date;<br>起始版本：10|date_picker.d.ts|
|起始版本有变化|类名：DatePickerInterface<br>起始版本：8|类名：DatePickerInterface<br>起始版本：10|date_picker.d.ts|
|起始版本有变化|类名：DatePickerInterface<br>方法 or 属性：(options?: DatePickerOptions): DatePickerAttribute;<br>起始版本：8|类名：DatePickerInterface<br>方法 or 属性：(options?: DatePickerOptions): DatePickerAttribute;<br>起始版本：10|date_picker.d.ts|
|起始版本有变化|类名：DatePickerAttribute<br>起始版本：8|类名：DatePickerAttribute<br>起始版本：10|date_picker.d.ts|
|起始版本有变化|类名：DatePickerAttribute<br>方法 or 属性：lunar(value: boolean): DatePickerAttribute;<br>起始版本：8|类名：DatePickerAttribute<br>方法 or 属性：lunar(value: boolean): DatePickerAttribute;<br>起始版本：10|date_picker.d.ts|
|起始版本有变化|类名：DatePickerAttribute<br>方法 or 属性：onChange(callback: (value: DatePickerResult) => void): DatePickerAttribute;<br>起始版本：8|类名：DatePickerAttribute<br>方法 or 属性：onChange(callback: (value: DatePickerResult) => void): DatePickerAttribute;<br>起始版本：10|date_picker.d.ts|
|起始版本有变化|类名：DatePickerDialogOptions<br>起始版本：8|类名：DatePickerDialogOptions<br>起始版本：10|date_picker.d.ts|
|起始版本有变化|类名：DatePickerDialogOptions<br>方法 or 属性：lunar?: boolean;<br>起始版本：8|类名：DatePickerDialogOptions<br>方法 or 属性：lunar?: boolean;<br>起始版本：10|date_picker.d.ts|
|起始版本有变化|类名：DatePickerDialogOptions<br>方法 or 属性：onAccept?: (value: DatePickerResult) => void;<br>起始版本：8|类名：DatePickerDialogOptions<br>方法 or 属性：onAccept?: (value: DatePickerResult) => void;<br>起始版本：10|date_picker.d.ts|
|起始版本有变化|类名：DatePickerDialogOptions<br>方法 or 属性：onCancel?: () => void;<br>起始版本：8|类名：DatePickerDialogOptions<br>方法 or 属性：onCancel?: () => void;<br>起始版本：10|date_picker.d.ts|
|起始版本有变化|类名：DatePickerDialogOptions<br>方法 or 属性：onChange?: (value: DatePickerResult) => void;<br>起始版本：8|类名：DatePickerDialogOptions<br>方法 or 属性：onChange?: (value: DatePickerResult) => void;<br>起始版本：10|date_picker.d.ts|
|起始版本有变化|类名：DatePickerDialog<br>起始版本：8|类名：DatePickerDialog<br>起始版本：10|date_picker.d.ts|
|起始版本有变化|类名：DatePickerDialog<br>方法 or 属性：static show(options?: DatePickerDialogOptions);<br>起始版本：8|类名：DatePickerDialog<br>方法 or 属性：static show(options?: DatePickerDialogOptions);<br>起始版本：10|date_picker.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const DatePicker: DatePickerInterface;<br>起始版本：8|类名：global<br>方法 or 属性：declare const DatePicker: DatePickerInterface;<br>起始版本：10|date_picker.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const DatePickerInstance: DatePickerAttribute;<br>起始版本：8|类名：global<br>方法 or 属性：declare const DatePickerInstance: DatePickerAttribute;<br>起始版本：10|date_picker.d.ts|
|起始版本有变化|类名：Color<br>方法 or 属性：Transparent<br>起始版本：9|类名：Color<br>方法 or 属性：Transparent<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：TouchType<br>起始版本：7|类名：TouchType<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：TouchType<br>方法 or 属性：Down<br>起始版本：7|类名：TouchType<br>方法 or 属性：Down<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：TouchType<br>方法 or 属性：Up<br>起始版本：7|类名：TouchType<br>方法 or 属性：Up<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：TouchType<br>方法 or 属性：Move<br>起始版本：7|类名：TouchType<br>方法 or 属性：Move<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：TouchType<br>方法 or 属性：Cancel<br>起始版本：7|类名：TouchType<br>方法 or 属性：Cancel<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：MouseButton<br>起始版本：8|类名：MouseButton<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：MouseButton<br>方法 or 属性：Left<br>起始版本：8|类名：MouseButton<br>方法 or 属性：Left<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：MouseButton<br>方法 or 属性：Right<br>起始版本：8|类名：MouseButton<br>方法 or 属性：Right<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：MouseButton<br>方法 or 属性：Middle<br>起始版本：8|类名：MouseButton<br>方法 or 属性：Middle<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：MouseButton<br>方法 or 属性：Back<br>起始版本：8|类名：MouseButton<br>方法 or 属性：Back<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：MouseButton<br>方法 or 属性：Forward<br>起始版本：8|类名：MouseButton<br>方法 or 属性：Forward<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：MouseButton<br>方法 or 属性：None<br>起始版本：8|类名：MouseButton<br>方法 or 属性：None<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：MouseAction<br>起始版本：8|类名：MouseAction<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：MouseAction<br>方法 or 属性：Press<br>起始版本：8|类名：MouseAction<br>方法 or 属性：Press<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：MouseAction<br>方法 or 属性：Release<br>起始版本：8|类名：MouseAction<br>方法 or 属性：Release<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：MouseAction<br>方法 or 属性：Move<br>起始版本：8|类名：MouseAction<br>方法 or 属性：Move<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：MouseAction<br>方法 or 属性：Hover<br>起始版本：8|类名：MouseAction<br>方法 or 属性：Hover<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：AnimationStatus<br>起始版本：7|类名：AnimationStatus<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：AnimationStatus<br>方法 or 属性：Initial<br>起始版本：7|类名：AnimationStatus<br>方法 or 属性：Initial<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：AnimationStatus<br>方法 or 属性：Running<br>起始版本：7|类名：AnimationStatus<br>方法 or 属性：Running<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：AnimationStatus<br>方法 or 属性：Paused<br>起始版本：7|类名：AnimationStatus<br>方法 or 属性：Paused<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：AnimationStatus<br>方法 or 属性：Stopped<br>起始版本：7|类名：AnimationStatus<br>方法 or 属性：Stopped<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：FillMode<br>起始版本：7|类名：FillMode<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：FillMode<br>方法 or 属性：None<br>起始版本：7|类名：FillMode<br>方法 or 属性：None<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：FillMode<br>方法 or 属性：Forwards<br>起始版本：7|类名：FillMode<br>方法 or 属性：Forwards<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：FillMode<br>方法 or 属性：Backwards<br>起始版本：7|类名：FillMode<br>方法 or 属性：Backwards<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：FillMode<br>方法 or 属性：Both<br>起始版本：7|类名：FillMode<br>方法 or 属性：Both<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：KeyType<br>起始版本：7|类名：KeyType<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：KeyType<br>方法 or 属性：Down<br>起始版本：7|类名：KeyType<br>方法 or 属性：Down<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：KeyType<br>方法 or 属性：Up<br>起始版本：7|类名：KeyType<br>方法 or 属性：Up<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：KeySource<br>起始版本：7|类名：KeySource<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：KeySource<br>方法 or 属性：Unknown<br>起始版本：7|类名：KeySource<br>方法 or 属性：Unknown<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：KeySource<br>方法 or 属性：Keyboard<br>起始版本：7|类名：KeySource<br>方法 or 属性：Keyboard<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：Edge<br>起始版本：7|类名：Edge<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：Edge<br>方法 or 属性：Top<br>起始版本：7|类名：Edge<br>方法 or 属性：Top<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：Edge<br>方法 or 属性：Bottom<br>起始版本：7|类名：Edge<br>方法 or 属性：Bottom<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：Edge<br>方法 or 属性：Start<br>起始版本：7|类名：Edge<br>方法 or 属性：Start<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：Edge<br>方法 or 属性：End<br>起始版本：7|类名：Edge<br>方法 or 属性：End<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：Week<br>起始版本：7|类名：Week<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：Week<br>方法 or 属性：Mon<br>起始版本：7|类名：Week<br>方法 or 属性：Mon<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：Week<br>方法 or 属性：Tue<br>起始版本：7|类名：Week<br>方法 or 属性：Tue<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：Week<br>方法 or 属性：Wed<br>起始版本：7|类名：Week<br>方法 or 属性：Wed<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：Week<br>方法 or 属性：Thur<br>起始版本：7|类名：Week<br>方法 or 属性：Thur<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：Week<br>方法 or 属性：Fri<br>起始版本：7|类名：Week<br>方法 or 属性：Fri<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：Week<br>方法 or 属性：Sat<br>起始版本：7|类名：Week<br>方法 or 属性：Sat<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：Week<br>方法 or 属性：Sun<br>起始版本：7|类名：Week<br>方法 or 属性：Sun<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：RelateType<br>起始版本：7|类名：RelateType<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：RelateType<br>方法 or 属性：FILL<br>起始版本：7|类名：RelateType<br>方法 or 属性：FILL<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：RelateType<br>方法 or 属性：FIT<br>起始版本：7|类名：RelateType<br>方法 or 属性：FIT<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：SharedTransitionEffectType<br>起始版本：7|类名：SharedTransitionEffectType<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：SharedTransitionEffectType<br>方法 or 属性：Static<br>起始版本：7|类名：SharedTransitionEffectType<br>方法 or 属性：Static<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：SharedTransitionEffectType<br>方法 or 属性：Exchange<br>起始版本：7|类名：SharedTransitionEffectType<br>方法 or 属性：Exchange<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：ResponseType<br>起始版本：8|类名：ResponseType<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：ResponseType<br>方法 or 属性：RightClick<br>起始版本：8|类名：ResponseType<br>方法 or 属性：RightClick<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：ResponseType<br>方法 or 属性：LongPress<br>起始版本：8|类名：ResponseType<br>方法 or 属性：LongPress<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：HoverEffect<br>起始版本：8|类名：HoverEffect<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：HoverEffect<br>方法 or 属性：Auto<br>起始版本：8|类名：HoverEffect<br>方法 or 属性：Auto<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：HoverEffect<br>方法 or 属性：Scale<br>起始版本：8|类名：HoverEffect<br>方法 or 属性：Scale<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：HoverEffect<br>方法 or 属性：Highlight<br>起始版本：8|类名：HoverEffect<br>方法 or 属性：Highlight<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：HoverEffect<br>方法 or 属性：None<br>起始版本：8|类名：HoverEffect<br>方法 or 属性：None<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：Placement<br>起始版本：8|类名：Placement<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：Placement<br>方法 or 属性：Left<br>起始版本：8|类名：Placement<br>方法 or 属性：Left<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：Placement<br>方法 or 属性：Right<br>起始版本：8|类名：Placement<br>方法 or 属性：Right<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：Placement<br>方法 or 属性：Top<br>起始版本：8|类名：Placement<br>方法 or 属性：Top<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：Placement<br>方法 or 属性：Bottom<br>起始版本：8|类名：Placement<br>方法 or 属性：Bottom<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：Placement<br>方法 or 属性：TopLeft<br>起始版本：8|类名：Placement<br>方法 or 属性：TopLeft<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：Placement<br>方法 or 属性：TopRight<br>起始版本：8|类名：Placement<br>方法 or 属性：TopRight<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：Placement<br>方法 or 属性：BottomLeft<br>起始版本：8|类名：Placement<br>方法 or 属性：BottomLeft<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：Placement<br>方法 or 属性：BottomRight<br>起始版本：8|类名：Placement<br>方法 or 属性：BottomRight<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：Placement<br>方法 or 属性：LeftTop<br>起始版本：9|类名：Placement<br>方法 or 属性：LeftTop<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：Placement<br>方法 or 属性：LeftBottom<br>起始版本：9|类名：Placement<br>方法 or 属性：LeftBottom<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：Placement<br>方法 or 属性：RightTop<br>起始版本：9|类名：Placement<br>方法 or 属性：RightTop<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：Placement<br>方法 or 属性：RightBottom<br>起始版本：9|类名：Placement<br>方法 or 属性：RightBottom<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：CopyOptions<br>起始版本：9|类名：CopyOptions<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：CopyOptions<br>方法 or 属性：None = 0<br>起始版本：9|类名：CopyOptions<br>方法 or 属性：None = 0<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：CopyOptions<br>方法 or 属性：InApp = 1<br>起始版本：9|类名：CopyOptions<br>方法 or 属性：InApp = 1<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：CopyOptions<br>方法 or 属性：LocalDevice = 2<br>起始版本：9|类名：CopyOptions<br>方法 or 属性：LocalDevice = 2<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：HitTestMode<br>起始版本：9|类名：HitTestMode<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：HitTestMode<br>方法 or 属性：Default<br>起始版本：9|类名：HitTestMode<br>方法 or 属性：Default<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：HitTestMode<br>方法 or 属性：Block<br>起始版本：9|类名：HitTestMode<br>方法 or 属性：Block<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：HitTestMode<br>方法 or 属性：Transparent<br>起始版本：9|类名：HitTestMode<br>方法 or 属性：Transparent<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：HitTestMode<br>方法 or 属性：None<br>起始版本：9|类名：HitTestMode<br>方法 or 属性：None<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：TitleHeight<br>起始版本：9|类名：TitleHeight<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：TitleHeight<br>方法 or 属性：MainOnly<br>起始版本：9|类名：TitleHeight<br>方法 or 属性：MainOnly<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：TitleHeight<br>方法 or 属性：MainWithSub<br>起始版本：9|类名：TitleHeight<br>方法 or 属性：MainWithSub<br>起始版本：10|enums.d.ts|
|起始版本有变化|类名：FlowItemInterface<br>起始版本：9|类名：FlowItemInterface<br>起始版本：10|flow_item.d.ts|
|起始版本有变化|类名：FlowItemInterface<br>方法 or 属性：(): FlowItemAttribute;<br>起始版本：9|类名：FlowItemInterface<br>方法 or 属性：(): FlowItemAttribute;<br>起始版本：10|flow_item.d.ts|
|起始版本有变化|类名：FlowItemAttribute<br>起始版本：9|类名：FlowItemAttribute<br>起始版本：10|flow_item.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const FlowItem: FlowItemInterface<br>起始版本：9|类名：global<br>方法 or 属性：declare const FlowItem: FlowItemInterface<br>起始版本：10|flow_item.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const FlowItemInstance: FlowItemAttribute;<br>起始版本：9|类名：global<br>方法 or 属性：declare const FlowItemInstance: FlowItemAttribute;<br>起始版本：10|flow_item.d.ts|
|起始版本有变化|类名：PanDirection<br>起始版本：7|类名：PanDirection<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：PanDirection<br>方法 or 属性：None<br>起始版本：7|类名：PanDirection<br>方法 or 属性：None<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：PanDirection<br>方法 or 属性：Horizontal<br>起始版本：7|类名：PanDirection<br>方法 or 属性：Horizontal<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：PanDirection<br>方法 or 属性：Left<br>起始版本：7|类名：PanDirection<br>方法 or 属性：Left<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：PanDirection<br>方法 or 属性：Right<br>起始版本：7|类名：PanDirection<br>方法 or 属性：Right<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：PanDirection<br>方法 or 属性：Vertical<br>起始版本：7|类名：PanDirection<br>方法 or 属性：Vertical<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：PanDirection<br>方法 or 属性：Up<br>起始版本：7|类名：PanDirection<br>方法 or 属性：Up<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：PanDirection<br>方法 or 属性：Down<br>起始版本：7|类名：PanDirection<br>方法 or 属性：Down<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：PanDirection<br>方法 or 属性：All<br>起始版本：7|类名：PanDirection<br>方法 or 属性：All<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：SwipeDirection<br>起始版本：8|类名：SwipeDirection<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：SwipeDirection<br>方法 or 属性：None<br>起始版本：8|类名：SwipeDirection<br>方法 or 属性：None<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：SwipeDirection<br>方法 or 属性：Horizontal<br>起始版本：8|类名：SwipeDirection<br>方法 or 属性：Horizontal<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：SwipeDirection<br>方法 or 属性：Vertical<br>起始版本：8|类名：SwipeDirection<br>方法 or 属性：Vertical<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：SwipeDirection<br>方法 or 属性：All<br>起始版本：8|类名：SwipeDirection<br>方法 or 属性：All<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：GestureMode<br>起始版本：7|类名：GestureMode<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：GestureMode<br>方法 or 属性：Sequence<br>起始版本：7|类名：GestureMode<br>方法 or 属性：Sequence<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：GestureMode<br>方法 or 属性：Parallel<br>起始版本：7|类名：GestureMode<br>方法 or 属性：Parallel<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：GestureMode<br>方法 or 属性：Exclusive<br>起始版本：7|类名：GestureMode<br>方法 or 属性：Exclusive<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：GestureMask<br>起始版本：7|类名：GestureMask<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：GestureMask<br>方法 or 属性：Normal<br>起始版本：7|类名：GestureMask<br>方法 or 属性：Normal<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：GestureMask<br>方法 or 属性：IgnoreInternal<br>起始版本：7|类名：GestureMask<br>方法 or 属性：IgnoreInternal<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：FingerInfo<br>起始版本：8|类名：FingerInfo<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：FingerInfo<br>方法 or 属性：id: number;<br>起始版本：8|类名：FingerInfo<br>方法 or 属性：id: number;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：FingerInfo<br>方法 or 属性：globalX: number;<br>起始版本：8|类名：FingerInfo<br>方法 or 属性：globalX: number;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：FingerInfo<br>方法 or 属性：globalY: number;<br>起始版本：8|类名：FingerInfo<br>方法 or 属性：globalY: number;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：FingerInfo<br>方法 or 属性：localX: number;<br>起始版本：8|类名：FingerInfo<br>方法 or 属性：localX: number;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：FingerInfo<br>方法 or 属性：localY: number;<br>起始版本：8|类名：FingerInfo<br>方法 or 属性：localY: number;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：GestureEvent<br>起始版本：7|类名：GestureEvent<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：GestureEvent<br>方法 or 属性：repeat: boolean;<br>起始版本：7|类名：GestureEvent<br>方法 or 属性：repeat: boolean;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：GestureEvent<br>方法 or 属性：fingerList: FingerInfo[];<br>起始版本：8|类名：GestureEvent<br>方法 or 属性：fingerList: FingerInfo[];<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：GestureEvent<br>方法 or 属性：offsetX: number;<br>起始版本：7|类名：GestureEvent<br>方法 or 属性：offsetX: number;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：GestureEvent<br>方法 or 属性：offsetY: number;<br>起始版本：7|类名：GestureEvent<br>方法 or 属性：offsetY: number;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：GestureEvent<br>方法 or 属性：angle: number;<br>起始版本：7|类名：GestureEvent<br>方法 or 属性：angle: number;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：GestureEvent<br>方法 or 属性：speed: number;<br>起始版本：8|类名：GestureEvent<br>方法 or 属性：speed: number;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：GestureEvent<br>方法 or 属性：scale: number;<br>起始版本：7|类名：GestureEvent<br>方法 or 属性：scale: number;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：GestureEvent<br>方法 or 属性：pinchCenterX: number;<br>起始版本：7|类名：GestureEvent<br>方法 or 属性：pinchCenterX: number;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：GestureEvent<br>方法 or 属性：pinchCenterY: number;<br>起始版本：7|类名：GestureEvent<br>方法 or 属性：pinchCenterY: number;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：TapGestureInterface<br>起始版本：7|类名：TapGestureInterface<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：TapGestureInterface<br>方法 or 属性：(value?: { count?: number; fingers?: number }): TapGestureInterface;<br>起始版本：7|类名：TapGestureInterface<br>方法 or 属性：(value?: { count?: number; fingers?: number }): TapGestureInterface;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：TapGestureInterface<br>方法 or 属性：onAction(event: (event?: GestureEvent) => void): TapGestureInterface;<br>起始版本：7|类名：TapGestureInterface<br>方法 or 属性：onAction(event: (event?: GestureEvent) => void): TapGestureInterface;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：LongPressGestureInterface<br>起始版本：7|类名：LongPressGestureInterface<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：LongPressGestureInterface<br>方法 or 属性：(value?: { fingers?: number; repeat?: boolean; duration?: number }): LongPressGestureInterface;<br>起始版本：7|类名：LongPressGestureInterface<br>方法 or 属性：(value?: { fingers?: number; repeat?: boolean; duration?: number }): LongPressGestureInterface;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：LongPressGestureInterface<br>方法 or 属性：onAction(event: (event?: GestureEvent) => void): LongPressGestureInterface;<br>起始版本：7|类名：LongPressGestureInterface<br>方法 or 属性：onAction(event: (event?: GestureEvent) => void): LongPressGestureInterface;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：LongPressGestureInterface<br>方法 or 属性：onActionEnd(event: (event?: GestureEvent) => void): LongPressGestureInterface;<br>起始版本：7|类名：LongPressGestureInterface<br>方法 or 属性：onActionEnd(event: (event?: GestureEvent) => void): LongPressGestureInterface;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：LongPressGestureInterface<br>方法 or 属性：onActionCancel(event: () => void): LongPressGestureInterface;<br>起始版本：7|类名：LongPressGestureInterface<br>方法 or 属性：onActionCancel(event: () => void): LongPressGestureInterface;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：PanGestureOptions<br>起始版本：7|类名：PanGestureOptions<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：PanGestureOptions<br>方法 or 属性：constructor(value?: { fingers?: number; direction?: PanDirection; distance?: number });<br>起始版本：7|类名：PanGestureOptions<br>方法 or 属性：constructor(value?: { fingers?: number; direction?: PanDirection; distance?: number });<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：PanGestureOptions<br>方法 or 属性：setDirection(value: PanDirection);<br>起始版本：7|类名：PanGestureOptions<br>方法 or 属性：setDirection(value: PanDirection);<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：PanGestureOptions<br>方法 or 属性：setDistance(value: number);<br>起始版本：7|类名：PanGestureOptions<br>方法 or 属性：setDistance(value: number);<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：PanGestureOptions<br>方法 or 属性：setFingers(value: number);<br>起始版本：7|类名：PanGestureOptions<br>方法 or 属性：setFingers(value: number);<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：PanGestureInterface<br>起始版本：7|类名：PanGestureInterface<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：PanGestureInterface<br>方法 or 属性：(value?: { fingers?: number; direction?: PanDirection; distance?: number } \| PanGestureOptions): PanGestureInterface;<br>起始版本：7|类名：PanGestureInterface<br>方法 or 属性：(value?: { fingers?: number; direction?: PanDirection; distance?: number } \| PanGestureOptions): PanGestureInterface;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：PanGestureInterface<br>方法 or 属性：onActionStart(event: (event?: GestureEvent) => void): PanGestureInterface;<br>起始版本：7|类名：PanGestureInterface<br>方法 or 属性：onActionStart(event: (event?: GestureEvent) => void): PanGestureInterface;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：PanGestureInterface<br>方法 or 属性：onActionUpdate(event: (event?: GestureEvent) => void): PanGestureInterface;<br>起始版本：7|类名：PanGestureInterface<br>方法 or 属性：onActionUpdate(event: (event?: GestureEvent) => void): PanGestureInterface;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：PanGestureInterface<br>方法 or 属性：onActionEnd(event: (event?: GestureEvent) => void): PanGestureInterface;<br>起始版本：7|类名：PanGestureInterface<br>方法 or 属性：onActionEnd(event: (event?: GestureEvent) => void): PanGestureInterface;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：PanGestureInterface<br>方法 or 属性：onActionCancel(event: () => void): PanGestureInterface;<br>起始版本：7|类名：PanGestureInterface<br>方法 or 属性：onActionCancel(event: () => void): PanGestureInterface;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：SwipeGestureInterface<br>起始版本：8|类名：SwipeGestureInterface<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：SwipeGestureInterface<br>方法 or 属性：(value?: { fingers?: number; direction?: SwipeDirection; speed?: number }): SwipeGestureInterface;<br>起始版本：8|类名：SwipeGestureInterface<br>方法 or 属性：(value?: { fingers?: number; direction?: SwipeDirection; speed?: number }): SwipeGestureInterface;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：SwipeGestureInterface<br>方法 or 属性：onAction(event: (event?: GestureEvent) => void): SwipeGestureInterface;<br>起始版本：8|类名：SwipeGestureInterface<br>方法 or 属性：onAction(event: (event?: GestureEvent) => void): SwipeGestureInterface;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：PinchGestureInterface<br>起始版本：7|类名：PinchGestureInterface<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：PinchGestureInterface<br>方法 or 属性：(value?: { fingers?: number; distance?: number }): PinchGestureInterface;<br>起始版本：7|类名：PinchGestureInterface<br>方法 or 属性：(value?: { fingers?: number; distance?: number }): PinchGestureInterface;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：PinchGestureInterface<br>方法 or 属性：onActionStart(event: (event?: GestureEvent) => void): PinchGestureInterface;<br>起始版本：7|类名：PinchGestureInterface<br>方法 or 属性：onActionStart(event: (event?: GestureEvent) => void): PinchGestureInterface;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：PinchGestureInterface<br>方法 or 属性：onActionUpdate(event: (event?: GestureEvent) => void): PinchGestureInterface;<br>起始版本：7|类名：PinchGestureInterface<br>方法 or 属性：onActionUpdate(event: (event?: GestureEvent) => void): PinchGestureInterface;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：PinchGestureInterface<br>方法 or 属性：onActionEnd(event: (event?: GestureEvent) => void): PinchGestureInterface;<br>起始版本：7|类名：PinchGestureInterface<br>方法 or 属性：onActionEnd(event: (event?: GestureEvent) => void): PinchGestureInterface;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：PinchGestureInterface<br>方法 or 属性：onActionCancel(event: () => void): PinchGestureInterface;<br>起始版本：7|类名：PinchGestureInterface<br>方法 or 属性：onActionCancel(event: () => void): PinchGestureInterface;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：RotationGestureInterface<br>起始版本：7|类名：RotationGestureInterface<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：RotationGestureInterface<br>方法 or 属性：(value?: { fingers?: number; angle?: number }): RotationGestureInterface;<br>起始版本：7|类名：RotationGestureInterface<br>方法 or 属性：(value?: { fingers?: number; angle?: number }): RotationGestureInterface;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：RotationGestureInterface<br>方法 or 属性：onActionStart(event: (event?: GestureEvent) => void): RotationGestureInterface;<br>起始版本：7|类名：RotationGestureInterface<br>方法 or 属性：onActionStart(event: (event?: GestureEvent) => void): RotationGestureInterface;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：RotationGestureInterface<br>方法 or 属性：onActionUpdate(event: (event?: GestureEvent) => void): RotationGestureInterface;<br>起始版本：7|类名：RotationGestureInterface<br>方法 or 属性：onActionUpdate(event: (event?: GestureEvent) => void): RotationGestureInterface;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：RotationGestureInterface<br>方法 or 属性：onActionEnd(event: (event?: GestureEvent) => void): RotationGestureInterface;<br>起始版本：7|类名：RotationGestureInterface<br>方法 or 属性：onActionEnd(event: (event?: GestureEvent) => void): RotationGestureInterface;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：RotationGestureInterface<br>方法 or 属性：onActionCancel(event: () => void): RotationGestureInterface;<br>起始版本：7|类名：RotationGestureInterface<br>方法 or 属性：onActionCancel(event: () => void): RotationGestureInterface;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：GestureGroupInterface<br>起始版本：7|类名：GestureGroupInterface<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：GestureGroupInterface<br>方法 or 属性：(mode: GestureMode, ...gesture: GestureType[]): GestureGroupInterface;<br>起始版本：7|类名：GestureGroupInterface<br>方法 or 属性：(mode: GestureMode, ...gesture: GestureType[]): GestureGroupInterface;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：GestureGroupInterface<br>方法 or 属性：onCancel(event: () => void): GestureGroupInterface;<br>起始版本：7|类名：GestureGroupInterface<br>方法 or 属性：onCancel(event: () => void): GestureGroupInterface;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const TapGesture: TapGestureInterface;<br>起始版本：7|类名：global<br>方法 or 属性：declare const TapGesture: TapGestureInterface;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const LongPressGesture: LongPressGestureInterface;<br>起始版本：7|类名：global<br>方法 or 属性：declare const LongPressGesture: LongPressGestureInterface;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const PanGesture: PanGestureInterface;<br>起始版本：7|类名：global<br>方法 or 属性：declare const PanGesture: PanGestureInterface;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const SwipeGesture: SwipeGestureInterface;<br>起始版本：7|类名：global<br>方法 or 属性：declare const SwipeGesture: SwipeGestureInterface;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const PinchGesture: PinchGestureInterface;<br>起始版本：7|类名：global<br>方法 or 属性：declare const PinchGesture: PinchGestureInterface;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const RotationGesture: RotationGestureInterface;<br>起始版本：7|类名：global<br>方法 or 属性：declare const RotationGesture: RotationGestureInterface;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const GestureGroup: GestureGroupInterface;<br>起始版本：7|类名：global<br>方法 or 属性：declare const GestureGroup: GestureGroupInterface;<br>起始版本：10|gesture.d.ts|
|起始版本有变化|类名：GridInterface<br>起始版本：7|类名：GridInterface<br>起始版本：10|grid.d.ts|
|起始版本有变化|类名：GridInterface<br>方法 or 属性：(scroller?: Scroller): GridAttribute;<br>起始版本：7|类名：GridInterface<br>方法 or 属性：(scroller?: Scroller): GridAttribute;<br>起始版本：10|grid.d.ts|
|起始版本有变化|类名：GridDirection<br>起始版本：8|类名：GridDirection<br>起始版本：10|grid.d.ts|
|起始版本有变化|类名：GridDirection<br>方法 or 属性：Row<br>起始版本：8|类名：GridDirection<br>方法 or 属性：Row<br>起始版本：10|grid.d.ts|
|起始版本有变化|类名：GridDirection<br>方法 or 属性：Column<br>起始版本：8|类名：GridDirection<br>方法 or 属性：Column<br>起始版本：10|grid.d.ts|
|起始版本有变化|类名：GridDirection<br>方法 or 属性：RowReverse<br>起始版本：8|类名：GridDirection<br>方法 or 属性：RowReverse<br>起始版本：10|grid.d.ts|
|起始版本有变化|类名：GridDirection<br>方法 or 属性：ColumnReverse<br>起始版本：8|类名：GridDirection<br>方法 or 属性：ColumnReverse<br>起始版本：10|grid.d.ts|
|起始版本有变化|类名：GridAttribute<br>起始版本：7|类名：GridAttribute<br>起始版本：10|grid.d.ts|
|起始版本有变化|类名：GridAttribute<br>方法 or 属性：columnsTemplate(value: string): GridAttribute;<br>起始版本：7|类名：GridAttribute<br>方法 or 属性：columnsTemplate(value: string): GridAttribute;<br>起始版本：10|grid.d.ts|
|起始版本有变化|类名：GridAttribute<br>方法 or 属性：rowsTemplate(value: string): GridAttribute;<br>起始版本：7|类名：GridAttribute<br>方法 or 属性：rowsTemplate(value: string): GridAttribute;<br>起始版本：10|grid.d.ts|
|起始版本有变化|类名：GridAttribute<br>方法 or 属性：columnsGap(value: Length): GridAttribute;<br>起始版本：7|类名：GridAttribute<br>方法 or 属性：columnsGap(value: Length): GridAttribute;<br>起始版本：10|grid.d.ts|
|起始版本有变化|类名：GridAttribute<br>方法 or 属性：rowsGap(value: Length): GridAttribute;<br>起始版本：7|类名：GridAttribute<br>方法 or 属性：rowsGap(value: Length): GridAttribute;<br>起始版本：10|grid.d.ts|
|起始版本有变化|类名：GridAttribute<br>方法 or 属性：scrollBarWidth(value: number \| string): GridAttribute;<br>起始版本：7|类名：GridAttribute<br>方法 or 属性：scrollBarWidth(value: number \| string): GridAttribute;<br>起始版本：10|grid.d.ts|
|起始版本有变化|类名：GridAttribute<br>方法 or 属性：scrollBarColor(value: Color \| number \| string): GridAttribute;<br>起始版本：7|类名：GridAttribute<br>方法 or 属性：scrollBarColor(value: Color \| number \| string): GridAttribute;<br>起始版本：10|grid.d.ts|
|起始版本有变化|类名：GridAttribute<br>方法 or 属性：scrollBar(value: BarState): GridAttribute;<br>起始版本：7|类名：GridAttribute<br>方法 or 属性：scrollBar(value: BarState): GridAttribute;<br>起始版本：10|grid.d.ts|
|起始版本有变化|类名：GridAttribute<br>方法 or 属性：onScrollIndex(event: (first: number) => void): GridAttribute;<br>起始版本：7|类名：GridAttribute<br>方法 or 属性：onScrollIndex(event: (first: number) => void): GridAttribute;<br>起始版本：10|grid.d.ts|
|起始版本有变化|类名：GridAttribute<br>方法 or 属性：cachedCount(value: number): GridAttribute;<br>起始版本：7|类名：GridAttribute<br>方法 or 属性：cachedCount(value: number): GridAttribute;<br>起始版本：10|grid.d.ts|
|起始版本有变化|类名：GridAttribute<br>方法 or 属性：editMode(value: boolean): GridAttribute;<br>起始版本：8|类名：GridAttribute<br>方法 or 属性：editMode(value: boolean): GridAttribute;<br>起始版本：10|grid.d.ts|
|起始版本有变化|类名：GridAttribute<br>方法 or 属性：multiSelectable(value: boolean): GridAttribute;<br>起始版本：8|类名：GridAttribute<br>方法 or 属性：multiSelectable(value: boolean): GridAttribute;<br>起始版本：10|grid.d.ts|
|起始版本有变化|类名：GridAttribute<br>方法 or 属性：maxCount(value: number): GridAttribute;<br>起始版本：8|类名：GridAttribute<br>方法 or 属性：maxCount(value: number): GridAttribute;<br>起始版本：10|grid.d.ts|
|起始版本有变化|类名：GridAttribute<br>方法 or 属性：minCount(value: number): GridAttribute;<br>起始版本：8|类名：GridAttribute<br>方法 or 属性：minCount(value: number): GridAttribute;<br>起始版本：10|grid.d.ts|
|起始版本有变化|类名：GridAttribute<br>方法 or 属性：cellLength(value: number): GridAttribute;<br>起始版本：8|类名：GridAttribute<br>方法 or 属性：cellLength(value: number): GridAttribute;<br>起始版本：10|grid.d.ts|
|起始版本有变化|类名：GridAttribute<br>方法 or 属性：layoutDirection(value: GridDirection): GridAttribute;<br>起始版本：8|类名：GridAttribute<br>方法 or 属性：layoutDirection(value: GridDirection): GridAttribute;<br>起始版本：10|grid.d.ts|
|起始版本有变化|类名：GridAttribute<br>方法 or 属性：supportAnimation(value: boolean): GridAttribute;<br>起始版本：8|类名：GridAttribute<br>方法 or 属性：supportAnimation(value: boolean): GridAttribute;<br>起始版本：10|grid.d.ts|
|起始版本有变化|类名：GridAttribute<br>方法 or 属性：onItemDragStart(event: (event: ItemDragInfo, itemIndex: number) => (() => any) \| void): GridAttribute;<br>起始版本：8|类名：GridAttribute<br>方法 or 属性：onItemDragStart(event: (event: ItemDragInfo, itemIndex: number) => (() => any) \| void): GridAttribute;<br>起始版本：10|grid.d.ts|
|起始版本有变化|类名：GridAttribute<br>方法 or 属性：onItemDragEnter(event: (event: ItemDragInfo) => void): GridAttribute;<br>起始版本：8|类名：GridAttribute<br>方法 or 属性：onItemDragEnter(event: (event: ItemDragInfo) => void): GridAttribute;<br>起始版本：10|grid.d.ts|
|起始版本有变化|类名：GridAttribute<br>方法 or 属性：onItemDragMove(event: (event: ItemDragInfo, itemIndex: number, insertIndex: number) => void): GridAttribute;<br>起始版本：8|类名：GridAttribute<br>方法 or 属性：onItemDragMove(event: (event: ItemDragInfo, itemIndex: number, insertIndex: number) => void): GridAttribute;<br>起始版本：10|grid.d.ts|
|起始版本有变化|类名：GridAttribute<br>方法 or 属性：onItemDragLeave(event: (event: ItemDragInfo, itemIndex: number) => void): GridAttribute;<br>起始版本：8|类名：GridAttribute<br>方法 or 属性：onItemDragLeave(event: (event: ItemDragInfo, itemIndex: number) => void): GridAttribute;<br>起始版本：10|grid.d.ts|
|起始版本有变化|类名：GridAttribute<br>方法 or 属性：onItemDrop(<br>    event: (event: ItemDragInfo, itemIndex: number, insertIndex: number, isSuccess: boolean) => void,<br>  ): GridAttribute;<br>起始版本：8|类名：GridAttribute<br>方法 or 属性：onItemDrop(<br>    event: (event: ItemDragInfo, itemIndex: number, insertIndex: number, isSuccess: boolean) => void,<br>  ): GridAttribute;<br>起始版本：10|grid.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const Grid: GridInterface;<br>起始版本：7|类名：global<br>方法 or 属性：declare const Grid: GridInterface;<br>起始版本：10|grid.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const GridInstance: GridAttribute;<br>起始版本：7|类名：global<br>方法 or 属性：declare const GridInstance: GridAttribute;<br>起始版本：10|grid.d.ts|
|起始版本有变化|类名：GridItemInterface<br>起始版本：7|类名：GridItemInterface<br>起始版本：10|gridItem.d.ts|
|起始版本有变化|类名：GridItemInterface<br>方法 or 属性：(): GridItemAttribute;<br>起始版本：7|类名：GridItemInterface<br>方法 or 属性：(): GridItemAttribute;<br>起始版本：10|gridItem.d.ts|
|起始版本有变化|类名：GridItemAttribute<br>起始版本：7|类名：GridItemAttribute<br>起始版本：10|gridItem.d.ts|
|起始版本有变化|类名：GridItemAttribute<br>方法 or 属性：rowStart(value: number): GridItemAttribute;<br>起始版本：7|类名：GridItemAttribute<br>方法 or 属性：rowStart(value: number): GridItemAttribute;<br>起始版本：10|gridItem.d.ts|
|起始版本有变化|类名：GridItemAttribute<br>方法 or 属性：rowEnd(value: number): GridItemAttribute;<br>起始版本：7|类名：GridItemAttribute<br>方法 or 属性：rowEnd(value: number): GridItemAttribute;<br>起始版本：10|gridItem.d.ts|
|起始版本有变化|类名：GridItemAttribute<br>方法 or 属性：columnStart(value: number): GridItemAttribute;<br>起始版本：7|类名：GridItemAttribute<br>方法 or 属性：columnStart(value: number): GridItemAttribute;<br>起始版本：10|gridItem.d.ts|
|起始版本有变化|类名：GridItemAttribute<br>方法 or 属性：columnEnd(value: number): GridItemAttribute;<br>起始版本：7|类名：GridItemAttribute<br>方法 or 属性：columnEnd(value: number): GridItemAttribute;<br>起始版本：10|gridItem.d.ts|
|起始版本有变化|类名：GridItemAttribute<br>方法 or 属性：selectable(value: boolean): GridItemAttribute;<br>起始版本：8|类名：GridItemAttribute<br>方法 or 属性：selectable(value: boolean): GridItemAttribute;<br>起始版本：10|gridItem.d.ts|
|起始版本有变化|类名：GridItemAttribute<br>方法 or 属性：onSelect(event: (isSelected: boolean) => void): GridItemAttribute;<br>起始版本：8|类名：GridItemAttribute<br>方法 or 属性：onSelect(event: (isSelected: boolean) => void): GridItemAttribute;<br>起始版本：10|gridItem.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const GridItem: GridItemInterface<br>起始版本：7|类名：global<br>方法 or 属性：declare const GridItem: GridItemInterface<br>起始版本：10|gridItem.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const GridItemInstance: GridItemAttribute;<br>起始版本：7|类名：global<br>方法 or 属性：declare const GridItemInstance: GridItemAttribute;<br>起始版本：10|gridItem.d.ts|
|起始版本有变化|类名：GridColColumnOption<br>起始版本：9|类名：GridColColumnOption<br>起始版本：10|grid_col.d.ts|
|起始版本有变化|类名：GridColColumnOption<br>方法 or 属性：xs?: number,<br>起始版本：9|类名：GridColColumnOption<br>方法 or 属性：xs?: number,<br>起始版本：10|grid_col.d.ts|
|起始版本有变化|类名：GridColColumnOption<br>方法 or 属性：sm?: number,<br>起始版本：9|类名：GridColColumnOption<br>方法 or 属性：sm?: number,<br>起始版本：10|grid_col.d.ts|
|起始版本有变化|类名：GridColColumnOption<br>方法 or 属性：md?: number,<br>起始版本：9|类名：GridColColumnOption<br>方法 or 属性：md?: number,<br>起始版本：10|grid_col.d.ts|
|起始版本有变化|类名：GridColColumnOption<br>方法 or 属性：lg?: number,<br>起始版本：9|类名：GridColColumnOption<br>方法 or 属性：lg?: number,<br>起始版本：10|grid_col.d.ts|
|起始版本有变化|类名：GridColColumnOption<br>方法 or 属性：xl?: number,<br>起始版本：9|类名：GridColColumnOption<br>方法 or 属性：xl?: number,<br>起始版本：10|grid_col.d.ts|
|起始版本有变化|类名：GridColColumnOption<br>方法 or 属性：xxl?: number,<br>起始版本：9|类名：GridColColumnOption<br>方法 or 属性：xxl?: number,<br>起始版本：10|grid_col.d.ts|
|起始版本有变化|类名：GridColOptions<br>起始版本：9|类名：GridColOptions<br>起始版本：10|grid_col.d.ts|
|起始版本有变化|类名：GridColOptions<br>方法 or 属性：span?: number \| GridColColumnOption;<br>起始版本：9|类名：GridColOptions<br>方法 or 属性：span?: number \| GridColColumnOption;<br>起始版本：10|grid_col.d.ts|
|起始版本有变化|类名：GridColOptions<br>方法 or 属性：offset?: number \| GridColColumnOption;<br>起始版本：9|类名：GridColOptions<br>方法 or 属性：offset?: number \| GridColColumnOption;<br>起始版本：10|grid_col.d.ts|
|起始版本有变化|类名：GridColOptions<br>方法 or 属性：order?: number \| GridColColumnOption;<br>起始版本：9|类名：GridColOptions<br>方法 or 属性：order?: number \| GridColColumnOption;<br>起始版本：10|grid_col.d.ts|
|起始版本有变化|类名：GridColInterface<br>起始版本：9|类名：GridColInterface<br>起始版本：10|grid_col.d.ts|
|起始版本有变化|类名：GridColInterface<br>方法 or 属性：(option?: GridColOptions): GridColAttribute;<br>起始版本：9|类名：GridColInterface<br>方法 or 属性：(option?: GridColOptions): GridColAttribute;<br>起始版本：10|grid_col.d.ts|
|起始版本有变化|类名：GridColAttribute<br>方法 or 属性：span(value: number \| GridColColumnOption): GridColAttribute;<br>起始版本：9|类名：GridColAttribute<br>方法 or 属性：span(value: number \| GridColColumnOption): GridColAttribute;<br>起始版本：10|grid_col.d.ts|
|起始版本有变化|类名：GridColAttribute<br>方法 or 属性：gridColOffset(value: number \| GridColColumnOption): GridColAttribute;<br>起始版本：9|类名：GridColAttribute<br>方法 or 属性：gridColOffset(value: number \| GridColColumnOption): GridColAttribute;<br>起始版本：10|grid_col.d.ts|
|起始版本有变化|类名：GridColAttribute<br>方法 or 属性：order(value: number \| GridColColumnOption): GridColAttribute;<br>起始版本：9|类名：GridColAttribute<br>方法 or 属性：order(value: number \| GridColColumnOption): GridColAttribute;<br>起始版本：10|grid_col.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const GridCol: GridColInterface<br>起始版本：9|类名：global<br>方法 or 属性：declare const GridCol: GridColInterface<br>起始版本：10|grid_col.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const GridColInstance: GridColAttribute;<br>起始版本：9|类名：global<br>方法 or 属性：declare const GridColInstance: GridColAttribute;<br>起始版本：10|grid_col.d.ts|
|起始版本有变化|类名：GridRowSizeOption<br>起始版本：9|类名：GridRowSizeOption<br>起始版本：10|grid_row.d.ts|
|起始版本有变化|类名：GridRowSizeOption<br>方法 or 属性：xs?: Length,<br>起始版本：9|类名：GridRowSizeOption<br>方法 or 属性：xs?: Length,<br>起始版本：10|grid_row.d.ts|
|起始版本有变化|类名：GridRowSizeOption<br>方法 or 属性：sm?: Length,<br>起始版本：9|类名：GridRowSizeOption<br>方法 or 属性：sm?: Length,<br>起始版本：10|grid_row.d.ts|
|起始版本有变化|类名：GridRowSizeOption<br>方法 or 属性：md?: Length,<br>起始版本：9|类名：GridRowSizeOption<br>方法 or 属性：md?: Length,<br>起始版本：10|grid_row.d.ts|
|起始版本有变化|类名：GridRowSizeOption<br>方法 or 属性：lg?: Length,<br>起始版本：9|类名：GridRowSizeOption<br>方法 or 属性：lg?: Length,<br>起始版本：10|grid_row.d.ts|
|起始版本有变化|类名：GridRowSizeOption<br>方法 or 属性：xl?: Length,<br>起始版本：9|类名：GridRowSizeOption<br>方法 or 属性：xl?: Length,<br>起始版本：10|grid_row.d.ts|
|起始版本有变化|类名：GridRowSizeOption<br>方法 or 属性：xxl?: Length,<br>起始版本：9|类名：GridRowSizeOption<br>方法 or 属性：xxl?: Length,<br>起始版本：10|grid_row.d.ts|
|起始版本有变化|类名：GridRowColumnOption<br>起始版本：9|类名：GridRowColumnOption<br>起始版本：10|grid_row.d.ts|
|起始版本有变化|类名：GridRowColumnOption<br>方法 or 属性：xs?: number,<br>起始版本：9|类名：GridRowColumnOption<br>方法 or 属性：xs?: number,<br>起始版本：10|grid_row.d.ts|
|起始版本有变化|类名：GridRowColumnOption<br>方法 or 属性：sm?: number,<br>起始版本：9|类名：GridRowColumnOption<br>方法 or 属性：sm?: number,<br>起始版本：10|grid_row.d.ts|
|起始版本有变化|类名：GridRowColumnOption<br>方法 or 属性：md?: number,<br>起始版本：9|类名：GridRowColumnOption<br>方法 or 属性：md?: number,<br>起始版本：10|grid_row.d.ts|
|起始版本有变化|类名：GridRowColumnOption<br>方法 or 属性：lg?: number,<br>起始版本：9|类名：GridRowColumnOption<br>方法 or 属性：lg?: number,<br>起始版本：10|grid_row.d.ts|
|起始版本有变化|类名：GridRowColumnOption<br>方法 or 属性：xl?: number,<br>起始版本：9|类名：GridRowColumnOption<br>方法 or 属性：xl?: number,<br>起始版本：10|grid_row.d.ts|
|起始版本有变化|类名：GridRowColumnOption<br>方法 or 属性：xxl?: number,<br>起始版本：9|类名：GridRowColumnOption<br>方法 or 属性：xxl?: number,<br>起始版本：10|grid_row.d.ts|
|起始版本有变化|类名：GutterOption<br>起始版本：9|类名：GutterOption<br>起始版本：10|grid_row.d.ts|
|起始版本有变化|类名：GutterOption<br>方法 or 属性：x?: Length \| GridRowSizeOption,<br>起始版本：9|类名：GutterOption<br>方法 or 属性：x?: Length \| GridRowSizeOption,<br>起始版本：10|grid_row.d.ts|
|起始版本有变化|类名：GutterOption<br>方法 or 属性：y?: Length \| GridRowSizeOption<br>起始版本：9|类名：GutterOption<br>方法 or 属性：y?: Length \| GridRowSizeOption<br>起始版本：10|grid_row.d.ts|
|起始版本有变化|类名：BreakpointsReference<br>起始版本：9|类名：BreakpointsReference<br>起始版本：10|grid_row.d.ts|
|起始版本有变化|类名：BreakpointsReference<br>方法 or 属性：WindowSize<br>起始版本：9|类名：BreakpointsReference<br>方法 or 属性：WindowSize<br>起始版本：10|grid_row.d.ts|
|起始版本有变化|类名：BreakpointsReference<br>方法 or 属性：ComponentSize<br>起始版本：9|类名：BreakpointsReference<br>方法 or 属性：ComponentSize<br>起始版本：10|grid_row.d.ts|
|起始版本有变化|类名：GridRowDirection<br>起始版本：9|类名：GridRowDirection<br>起始版本：10|grid_row.d.ts|
|起始版本有变化|类名：GridRowDirection<br>方法 or 属性：Row<br>起始版本：9|类名：GridRowDirection<br>方法 or 属性：Row<br>起始版本：10|grid_row.d.ts|
|起始版本有变化|类名：GridRowDirection<br>方法 or 属性：RowReverse<br>起始版本：9|类名：GridRowDirection<br>方法 or 属性：RowReverse<br>起始版本：10|grid_row.d.ts|
|起始版本有变化|类名：BreakPoints<br>起始版本：9|类名：BreakPoints<br>起始版本：10|grid_row.d.ts|
|起始版本有变化|类名：BreakPoints<br>方法 or 属性：value?: Array\<string>,<br>起始版本：9|类名：BreakPoints<br>方法 or 属性：value?: Array\<string>,<br>起始版本：10|grid_row.d.ts|
|起始版本有变化|类名：BreakPoints<br>方法 or 属性：reference?: BreakpointsReference,<br>起始版本：9|类名：BreakPoints<br>方法 or 属性：reference?: BreakpointsReference,<br>起始版本：10|grid_row.d.ts|
|起始版本有变化|类名：GridRowOptions<br>起始版本：9|类名：GridRowOptions<br>起始版本：10|grid_row.d.ts|
|起始版本有变化|类名：GridRowOptions<br>方法 or 属性：gutter?: Length \| GutterOption;<br>起始版本：9|类名：GridRowOptions<br>方法 or 属性：gutter?: Length \| GutterOption;<br>起始版本：10|grid_row.d.ts|
|起始版本有变化|类名：GridRowOptions<br>方法 or 属性：columns?: number \| GridRowColumnOption;<br>起始版本：9|类名：GridRowOptions<br>方法 or 属性：columns?: number \| GridRowColumnOption;<br>起始版本：10|grid_row.d.ts|
|起始版本有变化|类名：GridRowOptions<br>方法 or 属性：breakpoints?: BreakPoints;<br>起始版本：9|类名：GridRowOptions<br>方法 or 属性：breakpoints?: BreakPoints;<br>起始版本：10|grid_row.d.ts|
|起始版本有变化|类名：GridRowOptions<br>方法 or 属性：direction?: GridRowDirection;<br>起始版本：9|类名：GridRowOptions<br>方法 or 属性：direction?: GridRowDirection;<br>起始版本：10|grid_row.d.ts|
|起始版本有变化|类名：GridRowInterface<br>起始版本：9|类名：GridRowInterface<br>起始版本：10|grid_row.d.ts|
|起始版本有变化|类名：GridRowInterface<br>方法 or 属性：(option?: GridRowOptions): GridRowAttribute;<br>起始版本：9|类名：GridRowInterface<br>方法 or 属性：(option?: GridRowOptions): GridRowAttribute;<br>起始版本：10|grid_row.d.ts|
|起始版本有变化|类名：GridRowAttribute<br>方法 or 属性：onBreakpointChange(callback: (breakpoints: string) => void): GridRowAttribute;<br>起始版本：9|类名：GridRowAttribute<br>方法 or 属性：onBreakpointChange(callback: (breakpoints: string) => void): GridRowAttribute;<br>起始版本：10|grid_row.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const GridRow: GridRowInterface;<br>起始版本：9|类名：global<br>方法 or 属性：declare const GridRow: GridRowInterface;<br>起始版本：10|grid_row.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const GridRowInstance: GridRowAttribute;<br>起始版本：9|类名：global<br>方法 or 属性：declare const GridRowInstance: GridRowAttribute;<br>起始版本：10|grid_row.d.ts|
|起始版本有变化|类名：ImageAttribute<br>方法 or 属性：colorFilter(value: ColorFilter): ImageAttribute;<br>起始版本：9|类名：ImageAttribute<br>方法 or 属性：colorFilter(value: ColorFilter): ImageAttribute;<br>起始版本：10|image.d.ts|
|起始版本有变化|类名：ImageAttribute<br>方法 or 属性：copyOption(value: CopyOptions): ImageAttribute;<br>起始版本：9|类名：ImageAttribute<br>方法 or 属性：copyOption(value: CopyOptions): ImageAttribute;<br>起始版本：10|image.d.ts|
|起始版本有变化|类名：ImageAnimatorInterface<br>起始版本：7|类名：ImageAnimatorInterface<br>起始版本：10|image_animator.d.ts|
|起始版本有变化|类名：ImageAnimatorInterface<br>方法 or 属性：(): ImageAnimatorAttribute;<br>起始版本：7|类名：ImageAnimatorInterface<br>方法 or 属性：(): ImageAnimatorAttribute;<br>起始版本：10|image_animator.d.ts|
|起始版本有变化|类名：ImageFrameInfo<br>起始版本：7|类名：ImageFrameInfo<br>起始版本：10|image_animator.d.ts|
|起始版本有变化|类名：ImageFrameInfo<br>方法 or 属性：width?: number \| string;<br>起始版本：7|类名：ImageFrameInfo<br>方法 or 属性：width?: number \| string;<br>起始版本：10|image_animator.d.ts|
|起始版本有变化|类名：ImageFrameInfo<br>方法 or 属性：height?: number \| string;<br>起始版本：7|类名：ImageFrameInfo<br>方法 or 属性：height?: number \| string;<br>起始版本：10|image_animator.d.ts|
|起始版本有变化|类名：ImageFrameInfo<br>方法 or 属性：top?: number \| string;<br>起始版本：7|类名：ImageFrameInfo<br>方法 or 属性：top?: number \| string;<br>起始版本：10|image_animator.d.ts|
|起始版本有变化|类名：ImageFrameInfo<br>方法 or 属性：left?: number \| string;<br>起始版本：7|类名：ImageFrameInfo<br>方法 or 属性：left?: number \| string;<br>起始版本：10|image_animator.d.ts|
|起始版本有变化|类名：ImageFrameInfo<br>方法 or 属性：duration?: number;<br>起始版本：7|类名：ImageFrameInfo<br>方法 or 属性：duration?: number;<br>起始版本：10|image_animator.d.ts|
|起始版本有变化|类名：ImageAnimatorAttribute<br>起始版本：7|类名：ImageAnimatorAttribute<br>起始版本：10|image_animator.d.ts|
|起始版本有变化|类名：ImageAnimatorAttribute<br>方法 or 属性：images(value: Array\<ImageFrameInfo>): ImageAnimatorAttribute;<br>起始版本：7|类名：ImageAnimatorAttribute<br>方法 or 属性：images(value: Array\<ImageFrameInfo>): ImageAnimatorAttribute;<br>起始版本：10|image_animator.d.ts|
|起始版本有变化|类名：ImageAnimatorAttribute<br>方法 or 属性：state(value: AnimationStatus): ImageAnimatorAttribute;<br>起始版本：7|类名：ImageAnimatorAttribute<br>方法 or 属性：state(value: AnimationStatus): ImageAnimatorAttribute;<br>起始版本：10|image_animator.d.ts|
|起始版本有变化|类名：ImageAnimatorAttribute<br>方法 or 属性：duration(value: number): ImageAnimatorAttribute;<br>起始版本：7|类名：ImageAnimatorAttribute<br>方法 or 属性：duration(value: number): ImageAnimatorAttribute;<br>起始版本：10|image_animator.d.ts|
|起始版本有变化|类名：ImageAnimatorAttribute<br>方法 or 属性：reverse(value: boolean): ImageAnimatorAttribute;<br>起始版本：7|类名：ImageAnimatorAttribute<br>方法 or 属性：reverse(value: boolean): ImageAnimatorAttribute;<br>起始版本：10|image_animator.d.ts|
|起始版本有变化|类名：ImageAnimatorAttribute<br>方法 or 属性：fixedSize(value: boolean): ImageAnimatorAttribute;<br>起始版本：7|类名：ImageAnimatorAttribute<br>方法 or 属性：fixedSize(value: boolean): ImageAnimatorAttribute;<br>起始版本：10|image_animator.d.ts|
|起始版本有变化|类名：ImageAnimatorAttribute<br>方法 or 属性：fillMode(value: FillMode): ImageAnimatorAttribute;<br>起始版本：7|类名：ImageAnimatorAttribute<br>方法 or 属性：fillMode(value: FillMode): ImageAnimatorAttribute;<br>起始版本：10|image_animator.d.ts|
|起始版本有变化|类名：ImageAnimatorAttribute<br>方法 or 属性：iterations(value: number): ImageAnimatorAttribute;<br>起始版本：7|类名：ImageAnimatorAttribute<br>方法 or 属性：iterations(value: number): ImageAnimatorAttribute;<br>起始版本：10|image_animator.d.ts|
|起始版本有变化|类名：ImageAnimatorAttribute<br>方法 or 属性：onStart(event: () => void): ImageAnimatorAttribute;<br>起始版本：7|类名：ImageAnimatorAttribute<br>方法 or 属性：onStart(event: () => void): ImageAnimatorAttribute;<br>起始版本：10|image_animator.d.ts|
|起始版本有变化|类名：ImageAnimatorAttribute<br>方法 or 属性：onPause(event: () => void): ImageAnimatorAttribute;<br>起始版本：7|类名：ImageAnimatorAttribute<br>方法 or 属性：onPause(event: () => void): ImageAnimatorAttribute;<br>起始版本：10|image_animator.d.ts|
|起始版本有变化|类名：ImageAnimatorAttribute<br>方法 or 属性：onRepeat(event: () => void): ImageAnimatorAttribute;<br>起始版本：7|类名：ImageAnimatorAttribute<br>方法 or 属性：onRepeat(event: () => void): ImageAnimatorAttribute;<br>起始版本：10|image_animator.d.ts|
|起始版本有变化|类名：ImageAnimatorAttribute<br>方法 or 属性：onCancel(event: () => void): ImageAnimatorAttribute;<br>起始版本：7|类名：ImageAnimatorAttribute<br>方法 or 属性：onCancel(event: () => void): ImageAnimatorAttribute;<br>起始版本：10|image_animator.d.ts|
|起始版本有变化|类名：ImageAnimatorAttribute<br>方法 or 属性：onFinish(event: () => void): ImageAnimatorAttribute;<br>起始版本：7|类名：ImageAnimatorAttribute<br>方法 or 属性：onFinish(event: () => void): ImageAnimatorAttribute;<br>起始版本：10|image_animator.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const ImageAnimator: ImageAnimatorInterface;<br>起始版本：7|类名：global<br>方法 or 属性：declare const ImageAnimator: ImageAnimatorInterface;<br>起始版本：10|image_animator.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const ImageAnimatorInstance: ImageAnimatorAttribute;<br>起始版本：7|类名：global<br>方法 or 属性：declare const ImageAnimatorInstance: ImageAnimatorAttribute;<br>起始版本：10|image_animator.d.ts|
|起始版本有变化|类名：DataChangeListener<br>起始版本：7|类名：DataChangeListener<br>起始版本：10|lazy_for_each.d.ts|
|起始版本有变化|类名：DataChangeListener<br>方法 or 属性：onDataReloaded(): void;<br>起始版本：7|类名：DataChangeListener<br>方法 or 属性：onDataReloaded(): void;<br>起始版本：10|lazy_for_each.d.ts|
|起始版本有变化|类名：DataChangeListener<br>方法 or 属性：onDataAdd(index: number): void;<br>起始版本：8|类名：DataChangeListener<br>方法 or 属性：onDataAdd(index: number): void;<br>起始版本：10|lazy_for_each.d.ts|
|起始版本有变化|类名：DataChangeListener<br>方法 or 属性：onDataMove(from: number, to: number): void;<br>起始版本：8|类名：DataChangeListener<br>方法 or 属性：onDataMove(from: number, to: number): void;<br>起始版本：10|lazy_for_each.d.ts|
|起始版本有变化|类名：DataChangeListener<br>方法 or 属性：onDataDelete(index: number): void;<br>起始版本：8|类名：DataChangeListener<br>方法 or 属性：onDataDelete(index: number): void;<br>起始版本：10|lazy_for_each.d.ts|
|起始版本有变化|类名：DataChangeListener<br>方法 or 属性：onDataChange(index: number): void;<br>起始版本：8|类名：DataChangeListener<br>方法 or 属性：onDataChange(index: number): void;<br>起始版本：10|lazy_for_each.d.ts|
|起始版本有变化|类名：IDataSource<br>起始版本：7|类名：IDataSource<br>起始版本：10|lazy_for_each.d.ts|
|起始版本有变化|类名：IDataSource<br>方法 or 属性：totalCount(): number;<br>起始版本：7|类名：IDataSource<br>方法 or 属性：totalCount(): number;<br>起始版本：10|lazy_for_each.d.ts|
|起始版本有变化|类名：IDataSource<br>方法 or 属性：getData(index: number): any;<br>起始版本：7|类名：IDataSource<br>方法 or 属性：getData(index: number): any;<br>起始版本：10|lazy_for_each.d.ts|
|起始版本有变化|类名：IDataSource<br>方法 or 属性：registerDataChangeListener(listener: DataChangeListener): void;<br>起始版本：7|类名：IDataSource<br>方法 or 属性：registerDataChangeListener(listener: DataChangeListener): void;<br>起始版本：10|lazy_for_each.d.ts|
|起始版本有变化|类名：IDataSource<br>方法 or 属性：unregisterDataChangeListener(listener: DataChangeListener): void;<br>起始版本：7|类名：IDataSource<br>方法 or 属性：unregisterDataChangeListener(listener: DataChangeListener): void;<br>起始版本：10|lazy_for_each.d.ts|
|起始版本有变化|类名：LazyForEachInterface<br>起始版本：7|类名：LazyForEachInterface<br>起始版本：10|lazy_for_each.d.ts|
|起始版本有变化|类名：LazyForEachInterface<br>方法 or 属性：(<br>    dataSource: IDataSource,<br>    itemGenerator: (item: any, index?: number) => void,<br>    keyGenerator?: (item: any, index?: number) => string,<br>  ): LazyForEachInterface;<br>起始版本：7|类名：LazyForEachInterface<br>方法 or 属性：(<br>    dataSource: IDataSource,<br>    itemGenerator: (item: any, index?: number) => void,<br>    keyGenerator?: (item: any, index?: number) => string,<br>  ): LazyForEachInterface;<br>起始版本：10|lazy_for_each.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const LazyForEach: LazyForEachInterface;<br>起始版本：7|类名：global<br>方法 or 属性：declare const LazyForEach: LazyForEachInterface;<br>起始版本：10|lazy_for_each.d.ts|
|起始版本有变化|类名：ListItemAlign<br>起始版本：9|类名：ListItemAlign<br>起始版本：10|list.d.ts|
|起始版本有变化|类名：ListItemAlign<br>方法 or 属性：Start<br>起始版本：9|类名：ListItemAlign<br>方法 or 属性：Start<br>起始版本：10|list.d.ts|
|起始版本有变化|类名：ListItemAlign<br>方法 or 属性：Center<br>起始版本：9|类名：ListItemAlign<br>方法 or 属性：Center<br>起始版本：10|list.d.ts|
|起始版本有变化|类名：ListItemAlign<br>方法 or 属性：End<br>起始版本：9|类名：ListItemAlign<br>方法 or 属性：End<br>起始版本：10|list.d.ts|
|起始版本有变化|类名：StickyStyle<br>起始版本：9|类名：StickyStyle<br>起始版本：10|list.d.ts|
|起始版本有变化|类名：StickyStyle<br>方法 or 属性：None = 0<br>起始版本：9|类名：StickyStyle<br>方法 or 属性：None = 0<br>起始版本：10|list.d.ts|
|起始版本有变化|类名：StickyStyle<br>方法 or 属性：Header = 1<br>起始版本：9|类名：StickyStyle<br>方法 or 属性：Header = 1<br>起始版本：10|list.d.ts|
|起始版本有变化|类名：StickyStyle<br>方法 or 属性：Footer = 2<br>起始版本：9|类名：StickyStyle<br>方法 or 属性：Footer = 2<br>起始版本：10|list.d.ts|
|起始版本有变化|类名：ListAttribute<br>方法 or 属性：lanes(value: number \| LengthConstrain): ListAttribute;<br>起始版本：9|类名：ListAttribute<br>方法 or 属性：lanes(value: number \| LengthConstrain): ListAttribute;<br>起始版本：10|list.d.ts|
|起始版本有变化|类名：ListAttribute<br>方法 or 属性：alignListItem(value: ListItemAlign): ListAttribute;<br>起始版本：9|类名：ListAttribute<br>方法 or 属性：alignListItem(value: ListItemAlign): ListAttribute;<br>起始版本：10|list.d.ts|
|起始版本有变化|类名：ListAttribute<br>方法 or 属性：sticky(value: StickyStyle): ListAttribute;<br>起始版本：9|类名：ListAttribute<br>方法 or 属性：sticky(value: StickyStyle): ListAttribute;<br>起始版本：10|list.d.ts|
|起始版本有变化|类名：ListAttribute<br>方法 or 属性：onScrollStart(event: () => void): ListAttribute;<br>起始版本：9|类名：ListAttribute<br>方法 or 属性：onScrollStart(event: () => void): ListAttribute;<br>起始版本：10|list.d.ts|
|起始版本有变化|类名：ListAttribute<br>方法 or 属性：onItemMove(event: (from: number, to: number) => boolean): ListAttribute;<br>起始版本：7|类名：ListAttribute<br>方法 or 属性：onItemMove(event: (from: number, to: number) => boolean): ListAttribute;<br>起始版本：10|list.d.ts|
|起始版本有变化|类名：ListAttribute<br>方法 or 属性：onItemDragStart(event: (event: ItemDragInfo, itemIndex: number) => ((() => any) \| void)): ListAttribute;<br>起始版本：8|类名：ListAttribute<br>方法 or 属性：onItemDragStart(event: (event: ItemDragInfo, itemIndex: number) => ((() => any) \| void)): ListAttribute;<br>起始版本：10|list.d.ts|
|起始版本有变化|类名：ListAttribute<br>方法 or 属性：onItemDragEnter(event: (event: ItemDragInfo) => void): ListAttribute;<br>起始版本：8|类名：ListAttribute<br>方法 or 属性：onItemDragEnter(event: (event: ItemDragInfo) => void): ListAttribute;<br>起始版本：10|list.d.ts|
|起始版本有变化|类名：ListAttribute<br>方法 or 属性：onItemDragMove(event: (event: ItemDragInfo, itemIndex: number, insertIndex: number) => void): ListAttribute;<br>起始版本：8|类名：ListAttribute<br>方法 or 属性：onItemDragMove(event: (event: ItemDragInfo, itemIndex: number, insertIndex: number) => void): ListAttribute;<br>起始版本：10|list.d.ts|
|起始版本有变化|类名：ListAttribute<br>方法 or 属性：onItemDragLeave(event: (event: ItemDragInfo, itemIndex: number) => void): ListAttribute;<br>起始版本：8|类名：ListAttribute<br>方法 or 属性：onItemDragLeave(event: (event: ItemDragInfo, itemIndex: number) => void): ListAttribute;<br>起始版本：10|list.d.ts|
|起始版本有变化|类名：ListAttribute<br>方法 or 属性：onItemDrop(event: (event: ItemDragInfo, itemIndex: number, insertIndex: number, isSuccess: boolean) => void): ListAttribute;<br>起始版本：8|类名：ListAttribute<br>方法 or 属性：onItemDrop(event: (event: ItemDragInfo, itemIndex: number, insertIndex: number, isSuccess: boolean) => void): ListAttribute;<br>起始版本：10|list.d.ts|
|起始版本有变化|类名：ListAttribute<br>方法 or 属性：onScrollFrameBegin(event: (offset: number, state: ScrollState) => { offsetRemain: number }): ListAttribute;<br>起始版本：9|类名：ListAttribute<br>方法 or 属性：onScrollFrameBegin(event: (offset: number, state: ScrollState) => { offsetRemain: number }): ListAttribute;<br>起始版本：10|list.d.ts|
|起始版本有变化|类名：SwipeEdgeEffect<br>起始版本：9|类名：SwipeEdgeEffect<br>起始版本：10|list_item.d.ts|
|起始版本有变化|类名：SwipeEdgeEffect<br>方法 or 属性：Spring<br>起始版本：9|类名：SwipeEdgeEffect<br>方法 or 属性：Spring<br>起始版本：10|list_item.d.ts|
|起始版本有变化|类名：SwipeEdgeEffect<br>方法 or 属性：None<br>起始版本：9|类名：SwipeEdgeEffect<br>方法 or 属性：None<br>起始版本：10|list_item.d.ts|
|起始版本有变化|类名：SwipeActionOptions<br>起始版本：9|类名：SwipeActionOptions<br>起始版本：10|list_item.d.ts|
|起始版本有变化|类名：SwipeActionOptions<br>方法 or 属性：start?: CustomBuilder;<br>起始版本：9|类名：SwipeActionOptions<br>方法 or 属性：start?: CustomBuilder;<br>起始版本：10|list_item.d.ts|
|起始版本有变化|类名：SwipeActionOptions<br>方法 or 属性：end?: CustomBuilder;<br>起始版本：9|类名：SwipeActionOptions<br>方法 or 属性：end?: CustomBuilder;<br>起始版本：10|list_item.d.ts|
|起始版本有变化|类名：SwipeActionOptions<br>方法 or 属性：edgeEffect?: SwipeEdgeEffect;<br>起始版本：9|类名：SwipeActionOptions<br>方法 or 属性：edgeEffect?: SwipeEdgeEffect;<br>起始版本：10|list_item.d.ts|
|起始版本有变化|类名：ListItemAttribute<br>方法 or 属性：selectable(value: boolean): ListItemAttribute;<br>起始版本：8|类名：ListItemAttribute<br>方法 or 属性：selectable(value: boolean): ListItemAttribute;<br>起始版本：9|list_item.d.ts|
|起始版本有变化|类名：ListItemAttribute<br>方法 or 属性：swipeAction(value: SwipeActionOptions): ListItemAttribute;<br>起始版本：9|类名：ListItemAttribute<br>方法 or 属性：swipeAction(value: SwipeActionOptions): ListItemAttribute;<br>起始版本：10|list_item.d.ts|
|起始版本有变化|类名：ListItemGroupOptions<br>起始版本：9|类名：ListItemGroupOptions<br>起始版本：10|list_item_group.d.ts|
|起始版本有变化|类名：ListItemGroupOptions<br>方法 or 属性：header?: CustomBuilder;<br>起始版本：9|类名：ListItemGroupOptions<br>方法 or 属性：header?: CustomBuilder;<br>起始版本：10|list_item_group.d.ts|
|起始版本有变化|类名：ListItemGroupOptions<br>方法 or 属性：footer?: CustomBuilder;<br>起始版本：9|类名：ListItemGroupOptions<br>方法 or 属性：footer?: CustomBuilder;<br>起始版本：10|list_item_group.d.ts|
|起始版本有变化|类名：ListItemGroupOptions<br>方法 or 属性：space?: number \| string;<br>起始版本：9|类名：ListItemGroupOptions<br>方法 or 属性：space?: number \| string;<br>起始版本：10|list_item_group.d.ts|
|起始版本有变化|类名：ListItemGroupInterface<br>起始版本：9|类名：ListItemGroupInterface<br>起始版本：10|list_item_group.d.ts|
|起始版本有变化|类名：ListItemGroupInterface<br>方法 or 属性：(options?: ListItemGroupOptions): ListItemGroupAttribute;<br>起始版本：9|类名：ListItemGroupInterface<br>方法 or 属性：(options?: ListItemGroupOptions): ListItemGroupAttribute;<br>起始版本：10|list_item_group.d.ts|
|起始版本有变化|类名：ListItemGroupAttribute<br>起始版本：9|类名：ListItemGroupAttribute<br>起始版本：10|list_item_group.d.ts|
|起始版本有变化|类名：ListItemGroupAttribute<br>方法 or 属性：divider(<br>    value: {<br>      strokeWidth: Length;<br>      color?: ResourceColor;<br>      startMargin?: Length;<br>      endMargin?: Length;<br>    } \| null,<br>  ): ListItemGroupAttribute;<br>起始版本：9|类名：ListItemGroupAttribute<br>方法 or 属性：divider(<br>    value: {<br>      strokeWidth: Length;<br>      color?: ResourceColor;<br>      startMargin?: Length;<br>      endMargin?: Length;<br>    } \| null,<br>  ): ListItemGroupAttribute;<br>起始版本：10|list_item_group.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const ListItemGroupInstance: ListItemGroupAttribute;<br>起始版本：9|类名：global<br>方法 or 属性：declare const ListItemGroupInstance: ListItemGroupAttribute;<br>起始版本：10|list_item_group.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const ListItemGroup: ListItemGroupInterface;<br>起始版本：9|类名：global<br>方法 or 属性：declare const ListItemGroup: ListItemGroupInterface;<br>起始版本：10|list_item_group.d.ts|
|起始版本有变化|类名：MenuInterface<br>起始版本：9|类名：MenuInterface<br>起始版本：10|menu.d.ts|
|起始版本有变化|类名：MenuInterface<br>方法 or 属性：(): MenuAttribute;<br>起始版本：9|类名：MenuInterface<br>方法 or 属性：(): MenuAttribute;<br>起始版本：10|menu.d.ts|
|起始版本有变化|类名：MenuAttribute<br>起始版本：9|类名：MenuAttribute<br>起始版本：10|menu.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const Menu: MenuInterface;<br>起始版本：9|类名：global<br>方法 or 属性：declare const Menu: MenuInterface;<br>起始版本：10|menu.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const MenuInstance: MenuAttribute;<br>起始版本：9|类名：global<br>方法 or 属性：declare const MenuInstance: MenuAttribute;<br>起始版本：10|menu.d.ts|
|起始版本有变化|类名：MenuItemOptions<br>起始版本：9|类名：MenuItemOptions<br>起始版本：10|menu_item.d.ts|
|起始版本有变化|类名：MenuItemOptions<br>方法 or 属性：startIcon?: ResourceStr;<br>起始版本：9|类名：MenuItemOptions<br>方法 or 属性：startIcon?: ResourceStr;<br>起始版本：10|menu_item.d.ts|
|起始版本有变化|类名：MenuItemOptions<br>方法 or 属性：content?: ResourceStr;<br>起始版本：9|类名：MenuItemOptions<br>方法 or 属性：content?: ResourceStr;<br>起始版本：10|menu_item.d.ts|
|起始版本有变化|类名：MenuItemOptions<br>方法 or 属性：endIcon?: ResourceStr;<br>起始版本：9|类名：MenuItemOptions<br>方法 or 属性：endIcon?: ResourceStr;<br>起始版本：10|menu_item.d.ts|
|起始版本有变化|类名：MenuItemOptions<br>方法 or 属性：labelInfo?: ResourceStr;<br>起始版本：9|类名：MenuItemOptions<br>方法 or 属性：labelInfo?: ResourceStr;<br>起始版本：10|menu_item.d.ts|
|起始版本有变化|类名：MenuItemOptions<br>方法 or 属性：builder?: CustomBuilder;<br>起始版本：9|类名：MenuItemOptions<br>方法 or 属性：builder?: CustomBuilder;<br>起始版本：10|menu_item.d.ts|
|起始版本有变化|类名：MenuItemInterface<br>起始版本：9|类名：MenuItemInterface<br>起始版本：10|menu_item.d.ts|
|起始版本有变化|类名：MenuItemInterface<br>方法 or 属性：(value?: MenuItemOptions \| CustomBuilder): MenuItemAttribute;<br>起始版本：9|类名：MenuItemInterface<br>方法 or 属性：(value?: MenuItemOptions \| CustomBuilder): MenuItemAttribute;<br>起始版本：10|menu_item.d.ts|
|起始版本有变化|类名：MenuItemAttribute<br>起始版本：9|类名：MenuItemAttribute<br>起始版本：10|menu_item.d.ts|
|起始版本有变化|类名：MenuItemAttribute<br>方法 or 属性：selected(value: boolean): MenuItemAttribute;<br>起始版本：9|类名：MenuItemAttribute<br>方法 or 属性：selected(value: boolean): MenuItemAttribute;<br>起始版本：10|menu_item.d.ts|
|起始版本有变化|类名：MenuItemAttribute<br>方法 or 属性：onChange(callback: (selected: boolean) => void): MenuItemAttribute;<br>起始版本：9|类名：MenuItemAttribute<br>方法 or 属性：onChange(callback: (selected: boolean) => void): MenuItemAttribute;<br>起始版本：10|menu_item.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const MenuItem: MenuItemInterface;<br>起始版本：9|类名：global<br>方法 or 属性：declare const MenuItem: MenuItemInterface;<br>起始版本：10|menu_item.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const MenuItemInstance: MenuItemAttribute;<br>起始版本：9|类名：global<br>方法 or 属性：declare const MenuItemInstance: MenuItemAttribute;<br>起始版本：10|menu_item.d.ts|
|起始版本有变化|类名：MenuItemGroupOptions<br>起始版本：9|类名：MenuItemGroupOptions<br>起始版本：10|menu_item_group.d.ts|
|起始版本有变化|类名：MenuItemGroupOptions<br>方法 or 属性：header?: ResourceStr \| CustomBuilder;<br>起始版本：9|类名：MenuItemGroupOptions<br>方法 or 属性：header?: ResourceStr \| CustomBuilder;<br>起始版本：10|menu_item_group.d.ts|
|起始版本有变化|类名：MenuItemGroupOptions<br>方法 or 属性：footer?: ResourceStr \| CustomBuilder;<br>起始版本：9|类名：MenuItemGroupOptions<br>方法 or 属性：footer?: ResourceStr \| CustomBuilder;<br>起始版本：10|menu_item_group.d.ts|
|起始版本有变化|类名：MenuItemGroupInterface<br>起始版本：9|类名：MenuItemGroupInterface<br>起始版本：10|menu_item_group.d.ts|
|起始版本有变化|类名：MenuItemGroupInterface<br>方法 or 属性：(value?: MenuItemGroupOptions): MenuItemGroupAttribute;<br>起始版本：9|类名：MenuItemGroupInterface<br>方法 or 属性：(value?: MenuItemGroupOptions): MenuItemGroupAttribute;<br>起始版本：10|menu_item_group.d.ts|
|起始版本有变化|类名：MenuItemGroupAttribute<br>起始版本：9|类名：MenuItemGroupAttribute<br>起始版本：10|menu_item_group.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const MenuItemGroup: MenuItemGroupInterface;<br>起始版本：9|类名：global<br>方法 or 属性：declare const MenuItemGroup: MenuItemGroupInterface;<br>起始版本：10|menu_item_group.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const MenuItemGroupInstance: MenuItemGroupAttribute;<br>起始版本：9|类名：global<br>方法 or 属性：declare const MenuItemGroupInstance: MenuItemGroupAttribute;<br>起始版本：10|menu_item_group.d.ts|
|起始版本有变化|类名：NavigationCommonTitle<br>起始版本：9|类名：NavigationCommonTitle<br>起始版本：10|navigation.d.ts|
|起始版本有变化|类名：NavigationCommonTitle<br>方法 or 属性：main: string;<br>起始版本：9|类名：NavigationCommonTitle<br>方法 or 属性：main: string;<br>起始版本：10|navigation.d.ts|
|起始版本有变化|类名：NavigationCommonTitle<br>方法 or 属性：sub: string;<br>起始版本：9|类名：NavigationCommonTitle<br>方法 or 属性：sub: string;<br>起始版本：10|navigation.d.ts|
|起始版本有变化|类名：NavigationCustomTitle<br>起始版本：9|类名：NavigationCustomTitle<br>起始版本：10|navigation.d.ts|
|起始版本有变化|类名：NavigationCustomTitle<br>方法 or 属性：builder: CustomBuilder;<br>起始版本：9|类名：NavigationCustomTitle<br>方法 or 属性：builder: CustomBuilder;<br>起始版本：10|navigation.d.ts|
|起始版本有变化|类名：NavigationCustomTitle<br>方法 or 属性：height: TitleHeight \| Length;<br>起始版本：9|类名：NavigationCustomTitle<br>方法 or 属性：height: TitleHeight \| Length;<br>起始版本：10|navigation.d.ts|
|起始版本有变化|类名：NavigationMode<br>起始版本：9|类名：NavigationMode<br>起始版本：10|navigation.d.ts|
|起始版本有变化|类名：NavigationMode<br>方法 or 属性：Stack<br>起始版本：9|类名：NavigationMode<br>方法 or 属性：Stack<br>起始版本：10|navigation.d.ts|
|起始版本有变化|类名：NavigationMode<br>方法 or 属性：Split<br>起始版本：9|类名：NavigationMode<br>方法 or 属性：Split<br>起始版本：10|navigation.d.ts|
|起始版本有变化|类名：NavigationMode<br>方法 or 属性：Auto<br>起始版本：9|类名：NavigationMode<br>方法 or 属性：Auto<br>起始版本：10|navigation.d.ts|
|起始版本有变化|类名：NavBarPosition<br>起始版本：9|类名：NavBarPosition<br>起始版本：10|navigation.d.ts|
|起始版本有变化|类名：NavBarPosition<br>方法 or 属性：Start<br>起始版本：9|类名：NavBarPosition<br>方法 or 属性：Start<br>起始版本：10|navigation.d.ts|
|起始版本有变化|类名：NavBarPosition<br>方法 or 属性：End<br>起始版本：9|类名：NavBarPosition<br>方法 or 属性：End<br>起始版本：10|navigation.d.ts|
|起始版本有变化|类名：NavigationTitleMode<br>起始版本：8|类名：NavigationTitleMode<br>起始版本：10|navigation.d.ts|
|起始版本有变化|类名：NavigationTitleMode<br>方法 or 属性：Free = 0<br>起始版本：8|类名：NavigationTitleMode<br>方法 or 属性：Free = 0<br>起始版本：10|navigation.d.ts|
|起始版本有变化|类名：NavigationTitleMode<br>方法 or 属性：Full<br>起始版本：8|类名：NavigationTitleMode<br>方法 or 属性：Full<br>起始版本：10|navigation.d.ts|
|起始版本有变化|类名：NavigationTitleMode<br>方法 or 属性：Mini<br>起始版本：8|类名：NavigationTitleMode<br>方法 or 属性：Mini<br>起始版本：10|navigation.d.ts|
|起始版本有变化|类名：NavigationMenuItem<br>方法 or 属性：value: string;<br>起始版本：8|类名：NavigationMenuItem<br>方法 or 属性：value: string;<br>起始版本：10|navigation.d.ts|
|起始版本有变化|类名：NavigationMenuItem<br>方法 or 属性：icon?: string;<br>起始版本：8|类名：NavigationMenuItem<br>方法 or 属性：icon?: string;<br>起始版本：10|navigation.d.ts|
|起始版本有变化|类名：NavigationMenuItem<br>方法 or 属性：action?: () => void;<br>起始版本：8|类名：NavigationMenuItem<br>方法 or 属性：action?: () => void;<br>起始版本：10|navigation.d.ts|
|起始版本有变化|类名：NavigationInterface<br>起始版本：8|类名：NavigationInterface<br>起始版本：10|navigation.d.ts|
|起始版本有变化|类名：NavigationInterface<br>方法 or 属性：(): NavigationAttribute;<br>起始版本：8|类名：NavigationInterface<br>方法 or 属性：(): NavigationAttribute;<br>起始版本：10|navigation.d.ts|
|起始版本有变化|类名：NavigationAttribute<br>起始版本：8|类名：NavigationAttribute<br>起始版本：10|navigation.d.ts|
|起始版本有变化|类名：NavigationAttribute<br>方法 or 属性：navBarWidth(value: Length): NavigationAttribute;<br>起始版本：9|类名：NavigationAttribute<br>方法 or 属性：navBarWidth(value: Length): NavigationAttribute;<br>起始版本：10|navigation.d.ts|
|起始版本有变化|类名：NavigationAttribute<br>方法 or 属性：navBarPosition(value: NavBarPosition): NavigationAttribute;<br>起始版本：9|类名：NavigationAttribute<br>方法 or 属性：navBarPosition(value: NavBarPosition): NavigationAttribute;<br>起始版本：10|navigation.d.ts|
|起始版本有变化|类名：NavigationAttribute<br>方法 or 属性：mode(value: NavigationMode): NavigationAttribute;<br>起始版本：9|类名：NavigationAttribute<br>方法 or 属性：mode(value: NavigationMode): NavigationAttribute;<br>起始版本：10|navigation.d.ts|
|起始版本有变化|类名：NavigationAttribute<br>方法 or 属性：backButtonIcon(value: string \| PixelMap \| Resource): NavigationAttribute;<br>起始版本：9|类名：NavigationAttribute<br>方法 or 属性：backButtonIcon(value: string \| PixelMap \| Resource): NavigationAttribute;<br>起始版本：10|navigation.d.ts|
|起始版本有变化|类名：NavigationAttribute<br>方法 or 属性：hideNavBar(value: boolean): NavigationAttribute;<br>起始版本：9|类名：NavigationAttribute<br>方法 or 属性：hideNavBar(value: boolean): NavigationAttribute;<br>起始版本：10|navigation.d.ts|
|起始版本有变化|类名：NavigationAttribute<br>方法 or 属性：hideTitleBar(value: boolean): NavigationAttribute;<br>起始版本：8|类名：NavigationAttribute<br>方法 or 属性：hideTitleBar(value: boolean): NavigationAttribute;<br>起始版本：10|navigation.d.ts|
|起始版本有变化|类名：NavigationAttribute<br>方法 or 属性：hideBackButton(value: boolean): NavigationAttribute;<br>起始版本：8|类名：NavigationAttribute<br>方法 or 属性：hideBackButton(value: boolean): NavigationAttribute;<br>起始版本：10|navigation.d.ts|
|起始版本有变化|类名：NavigationAttribute<br>方法 or 属性：titleMode(value: NavigationTitleMode): NavigationAttribute;<br>起始版本：8|类名：NavigationAttribute<br>方法 or 属性：titleMode(value: NavigationTitleMode): NavigationAttribute;<br>起始版本：10|navigation.d.ts|
|起始版本有变化|类名：NavigationAttribute<br>方法 or 属性：menus(value: Array\<NavigationMenuItem> \| CustomBuilder): NavigationAttribute;<br>起始版本：8|类名：NavigationAttribute<br>方法 or 属性：menus(value: Array\<NavigationMenuItem> \| CustomBuilder): NavigationAttribute;<br>起始版本：10|navigation.d.ts|
|起始版本有变化|类名：NavigationAttribute<br>方法 or 属性：toolBar(value: object \| CustomBuilder): NavigationAttribute;<br>起始版本：8|类名：NavigationAttribute<br>方法 or 属性：toolBar(value: object \| CustomBuilder): NavigationAttribute;<br>起始版本：10|navigation.d.ts|
|起始版本有变化|类名：NavigationAttribute<br>方法 or 属性：hideToolBar(value: boolean): NavigationAttribute;<br>起始版本：8|类名：NavigationAttribute<br>方法 or 属性：hideToolBar(value: boolean): NavigationAttribute;<br>起始版本：10|navigation.d.ts|
|起始版本有变化|类名：NavigationAttribute<br>方法 or 属性：onTitleModeChange(callback: (titleMode: NavigationTitleMode) => void): NavigationAttribute;<br>起始版本：8|类名：NavigationAttribute<br>方法 or 属性：onTitleModeChange(callback: (titleMode: NavigationTitleMode) => void): NavigationAttribute;<br>起始版本：10|navigation.d.ts|
|起始版本有变化|类名：NavigationAttribute<br>方法 or 属性：onNavBarStateChange(callback: (isVisible: boolean) => void): NavigationAttribute;<br>起始版本：9|类名：NavigationAttribute<br>方法 or 属性：onNavBarStateChange(callback: (isVisible: boolean) => void): NavigationAttribute;<br>起始版本：10|navigation.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const Navigation: NavigationInterface;<br>起始版本：8|类名：global<br>方法 or 属性：declare const Navigation: NavigationInterface;<br>起始版本：10|navigation.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const NavigationInstance: NavigationAttribute;<br>起始版本：8|类名：global<br>方法 or 属性：declare const NavigationInstance: NavigationAttribute;<br>起始版本：10|navigation.d.ts|
|起始版本有变化|类名：NavigationType<br>起始版本：7|类名：NavigationType<br>起始版本：10|navigator.d.ts|
|起始版本有变化|类名：NavigationType<br>方法 or 属性：Push<br>起始版本：7|类名：NavigationType<br>方法 or 属性：Push<br>起始版本：10|navigator.d.ts|
|起始版本有变化|类名：NavigationType<br>方法 or 属性：Back<br>起始版本：7|类名：NavigationType<br>方法 or 属性：Back<br>起始版本：10|navigator.d.ts|
|起始版本有变化|类名：NavigationType<br>方法 or 属性：Replace<br>起始版本：7|类名：NavigationType<br>方法 or 属性：Replace<br>起始版本：10|navigator.d.ts|
|起始版本有变化|类名：NavigatorInterface<br>起始版本：7|类名：NavigatorInterface<br>起始版本：10|navigator.d.ts|
|起始版本有变化|类名：NavigatorInterface<br>方法 or 属性：(value?: { target: string; type?: NavigationType }): NavigatorAttribute;<br>起始版本：7|类名：NavigatorInterface<br>方法 or 属性：(value?: { target: string; type?: NavigationType }): NavigatorAttribute;<br>起始版本：10|navigator.d.ts|
|起始版本有变化|类名：NavigatorInterface<br>方法 or 属性：(): NavigatorAttribute;<br>起始版本：7|类名：NavigatorInterface<br>方法 or 属性：(): NavigatorAttribute;<br>起始版本：10|navigator.d.ts|
|起始版本有变化|类名：NavigatorAttribute<br>起始版本：7|类名：NavigatorAttribute<br>起始版本：10|navigator.d.ts|
|起始版本有变化|类名：NavigatorAttribute<br>方法 or 属性：active(value: boolean): NavigatorAttribute;<br>起始版本：7|类名：NavigatorAttribute<br>方法 or 属性：active(value: boolean): NavigatorAttribute;<br>起始版本：10|navigator.d.ts|
|起始版本有变化|类名：NavigatorAttribute<br>方法 or 属性：type(value: NavigationType): NavigatorAttribute;<br>起始版本：7|类名：NavigatorAttribute<br>方法 or 属性：type(value: NavigationType): NavigatorAttribute;<br>起始版本：10|navigator.d.ts|
|起始版本有变化|类名：NavigatorAttribute<br>方法 or 属性：target(value: string): NavigatorAttribute;<br>起始版本：7|类名：NavigatorAttribute<br>方法 or 属性：target(value: string): NavigatorAttribute;<br>起始版本：10|navigator.d.ts|
|起始版本有变化|类名：NavigatorAttribute<br>方法 or 属性：params(value: object): NavigatorAttribute;<br>起始版本：7|类名：NavigatorAttribute<br>方法 or 属性：params(value: object): NavigatorAttribute;<br>起始版本：10|navigator.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const Navigator: NavigatorInterface;<br>起始版本：7|类名：global<br>方法 or 属性：declare const Navigator: NavigatorInterface;<br>起始版本：10|navigator.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const NavigatorInstance: NavigatorAttribute;<br>起始版本：7|类名：global<br>方法 or 属性：declare const NavigatorInstance: NavigatorAttribute;<br>起始版本：10|navigator.d.ts|
|起始版本有变化|类名：NavDestinationCommonTitle<br>起始版本：9|类名：NavDestinationCommonTitle<br>起始版本：10|nav_destination.d.ts|
|起始版本有变化|类名：NavDestinationCommonTitle<br>方法 or 属性：main: string;<br>起始版本：9|类名：NavDestinationCommonTitle<br>方法 or 属性：main: string;<br>起始版本：10|nav_destination.d.ts|
|起始版本有变化|类名：NavDestinationCommonTitle<br>方法 or 属性：sub: string;<br>起始版本：9|类名：NavDestinationCommonTitle<br>方法 or 属性：sub: string;<br>起始版本：10|nav_destination.d.ts|
|起始版本有变化|类名：NavDestinationCustomTitle<br>起始版本：9|类名：NavDestinationCustomTitle<br>起始版本：10|nav_destination.d.ts|
|起始版本有变化|类名：NavDestinationCustomTitle<br>方法 or 属性：builder: CustomBuilder;<br>起始版本：9|类名：NavDestinationCustomTitle<br>方法 or 属性：builder: CustomBuilder;<br>起始版本：10|nav_destination.d.ts|
|起始版本有变化|类名：NavDestinationCustomTitle<br>方法 or 属性：height: TitleHeight \| Length;<br>起始版本：9|类名：NavDestinationCustomTitle<br>方法 or 属性：height: TitleHeight \| Length;<br>起始版本：10|nav_destination.d.ts|
|起始版本有变化|类名：NavDestinationInterface<br>起始版本：9|类名：NavDestinationInterface<br>起始版本：10|nav_destination.d.ts|
|起始版本有变化|类名：NavDestinationInterface<br>方法 or 属性：(): NavDestinationAttribute;<br>起始版本：9|类名：NavDestinationInterface<br>方法 or 属性：(): NavDestinationAttribute;<br>起始版本：10|nav_destination.d.ts|
|起始版本有变化|类名：NavDestinationAttribute<br>起始版本：9|类名：NavDestinationAttribute<br>起始版本：10|nav_destination.d.ts|
|起始版本有变化|类名：NavDestinationAttribute<br>方法 or 属性：title(value: string \| CustomBuilder \| NavDestinationCommonTitle \| NavDestinationCustomTitle): NavDestinationAttribute;<br>起始版本：9|类名：NavDestinationAttribute<br>方法 or 属性：title(value: string \| CustomBuilder \| NavDestinationCommonTitle \| NavDestinationCustomTitle): NavDestinationAttribute;<br>起始版本：10|nav_destination.d.ts|
|起始版本有变化|类名：NavDestinationAttribute<br>方法 or 属性：hideTitleBar(value: boolean): NavDestinationAttribute;<br>起始版本：9|类名：NavDestinationAttribute<br>方法 or 属性：hideTitleBar(value: boolean): NavDestinationAttribute;<br>起始版本：10|nav_destination.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const NavDestination: NavDestinationInterface;<br>起始版本：9|类名：global<br>方法 or 属性：declare const NavDestination: NavDestinationInterface;<br>起始版本：10|nav_destination.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const NavDestinationInstance: NavDestinationAttribute;<br>起始版本：9|类名：global<br>方法 or 属性：declare const NavDestinationInstance: NavDestinationAttribute;<br>起始版本：10|nav_destination.d.ts|
|起始版本有变化|类名：NavRouterInterface<br>起始版本：9|类名：NavRouterInterface<br>起始版本：10|nav_router.d.ts|
|起始版本有变化|类名：NavRouterInterface<br>方法 or 属性：(): NavRouterAttribute;<br>起始版本：9|类名：NavRouterInterface<br>方法 or 属性：(): NavRouterAttribute;<br>起始版本：10|nav_router.d.ts|
|起始版本有变化|类名：NavRouterAttribute<br>起始版本：9|类名：NavRouterAttribute<br>起始版本：10|nav_router.d.ts|
|起始版本有变化|类名：NavRouterAttribute<br>方法 or 属性：onStateChange(callback: (isActivated: boolean) => void): NavRouterAttribute;<br>起始版本：9|类名：NavRouterAttribute<br>方法 or 属性：onStateChange(callback: (isActivated: boolean) => void): NavRouterAttribute;<br>起始版本：10|nav_router.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const NavRouter: NavRouterInterface;<br>起始版本：9|类名：global<br>方法 or 属性：declare const NavRouter: NavRouterInterface;<br>起始版本：10|nav_router.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const NavRouterInstance: NavRouterAttribute;<br>起始版本：9|类名：global<br>方法 or 属性：declare const NavRouterInstance: NavRouterAttribute;<br>起始版本：10|nav_router.d.ts|
|起始版本有变化|类名：RouteType<br>起始版本：7|类名：RouteType<br>起始版本：10|page_transition.d.ts|
|起始版本有变化|类名：RouteType<br>方法 or 属性：None<br>起始版本：7|类名：RouteType<br>方法 or 属性：None<br>起始版本：10|page_transition.d.ts|
|起始版本有变化|类名：RouteType<br>方法 or 属性：Push<br>起始版本：7|类名：RouteType<br>方法 or 属性：Push<br>起始版本：10|page_transition.d.ts|
|起始版本有变化|类名：RouteType<br>方法 or 属性：Pop<br>起始版本：7|类名：RouteType<br>方法 or 属性：Pop<br>起始版本：10|page_transition.d.ts|
|起始版本有变化|类名：SlideEffect<br>起始版本：7|类名：SlideEffect<br>起始版本：10|page_transition.d.ts|
|起始版本有变化|类名：SlideEffect<br>方法 or 属性：Left<br>起始版本：7|类名：SlideEffect<br>方法 or 属性：Left<br>起始版本：10|page_transition.d.ts|
|起始版本有变化|类名：SlideEffect<br>方法 or 属性：Right<br>起始版本：7|类名：SlideEffect<br>方法 or 属性：Right<br>起始版本：10|page_transition.d.ts|
|起始版本有变化|类名：SlideEffect<br>方法 or 属性：Top<br>起始版本：7|类名：SlideEffect<br>方法 or 属性：Top<br>起始版本：10|page_transition.d.ts|
|起始版本有变化|类名：SlideEffect<br>方法 or 属性：Bottom<br>起始版本：7|类名：SlideEffect<br>方法 or 属性：Bottom<br>起始版本：10|page_transition.d.ts|
|起始版本有变化|类名：CommonTransition<br>起始版本：7|类名：CommonTransition<br>起始版本：10|page_transition.d.ts|
|起始版本有变化|类名：CommonTransition<br>方法 or 属性：constructor();<br>起始版本：7|类名：CommonTransition<br>方法 or 属性：constructor();<br>起始版本：10|page_transition.d.ts|
|起始版本有变化|类名：CommonTransition<br>方法 or 属性：slide(value: SlideEffect): T;<br>起始版本：7|类名：CommonTransition<br>方法 or 属性：slide(value: SlideEffect): T;<br>起始版本：10|page_transition.d.ts|
|起始版本有变化|类名：CommonTransition<br>方法 or 属性：translate(value: { x?: number \| string; y?: number \| string; z?: number \| string }): T;<br>起始版本：7|类名：CommonTransition<br>方法 or 属性：translate(value: { x?: number \| string; y?: number \| string; z?: number \| string }): T;<br>起始版本：10|page_transition.d.ts|
|起始版本有变化|类名：CommonTransition<br>方法 or 属性：scale(value: { x?: number; y?: number; z?: number; centerX?: number \| string; centerY?: number \| string }): T;<br>起始版本：7|类名：CommonTransition<br>方法 or 属性：scale(value: { x?: number; y?: number; z?: number; centerX?: number \| string; centerY?: number \| string }): T;<br>起始版本：10|page_transition.d.ts|
|起始版本有变化|类名：CommonTransition<br>方法 or 属性：opacity(value: number): T;<br>起始版本：7|类名：CommonTransition<br>方法 or 属性：opacity(value: number): T;<br>起始版本：10|page_transition.d.ts|
|起始版本有变化|类名：PageTransitionEnterInterface<br>起始版本：7|类名：PageTransitionEnterInterface<br>起始版本：10|page_transition.d.ts|
|起始版本有变化|类名：PageTransitionEnterInterface<br>方法 or 属性：(value: { type?: RouteType; duration?: number; curve?: Curve \| string; delay?: number }): PageTransitionEnterInterface;<br>起始版本：7|类名：PageTransitionEnterInterface<br>方法 or 属性：(value: { type?: RouteType; duration?: number; curve?: Curve \| string; delay?: number }): PageTransitionEnterInterface;<br>起始版本：10|page_transition.d.ts|
|起始版本有变化|类名：PageTransitionEnterInterface<br>方法 or 属性：onEnter(event: (type?: RouteType, progress?: number) => void): PageTransitionEnterInterface;<br>起始版本：7|类名：PageTransitionEnterInterface<br>方法 or 属性：onEnter(event: (type?: RouteType, progress?: number) => void): PageTransitionEnterInterface;<br>起始版本：10|page_transition.d.ts|
|起始版本有变化|类名：PageTransitionExitInterface<br>起始版本：7|类名：PageTransitionExitInterface<br>起始版本：10|page_transition.d.ts|
|起始版本有变化|类名：PageTransitionExitInterface<br>方法 or 属性：(value: { type?: RouteType; duration?: number; curve?: Curve \| string; delay?: number }): PageTransitionExitInterface;<br>起始版本：7|类名：PageTransitionExitInterface<br>方法 or 属性：(value: { type?: RouteType; duration?: number; curve?: Curve \| string; delay?: number }): PageTransitionExitInterface;<br>起始版本：10|page_transition.d.ts|
|起始版本有变化|类名：PageTransitionExitInterface<br>方法 or 属性：onExit(event: (type?: RouteType, progress?: number) => void): PageTransitionExitInterface;<br>起始版本：7|类名：PageTransitionExitInterface<br>方法 or 属性：onExit(event: (type?: RouteType, progress?: number) => void): PageTransitionExitInterface;<br>起始版本：10|page_transition.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const PageTransitionEnter: PageTransitionEnterInterface;<br>起始版本：7|类名：global<br>方法 or 属性：declare const PageTransitionEnter: PageTransitionEnterInterface;<br>起始版本：10|page_transition.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const PageTransitionExit: PageTransitionExitInterface;<br>起始版本：7|类名：global<br>方法 or 属性：declare const PageTransitionExit: PageTransitionExitInterface;<br>起始版本：10|page_transition.d.ts|
|起始版本有变化|类名：PanelMode<br>起始版本：7|类名：PanelMode<br>起始版本：10|panel.d.ts|
|起始版本有变化|类名：PanelMode<br>方法 or 属性：Mini<br>起始版本：7|类名：PanelMode<br>方法 or 属性：Mini<br>起始版本：10|panel.d.ts|
|起始版本有变化|类名：PanelMode<br>方法 or 属性：Half<br>起始版本：7|类名：PanelMode<br>方法 or 属性：Half<br>起始版本：10|panel.d.ts|
|起始版本有变化|类名：PanelMode<br>方法 or 属性：Full<br>起始版本：7|类名：PanelMode<br>方法 or 属性：Full<br>起始版本：10|panel.d.ts|
|起始版本有变化|类名：PanelType<br>起始版本：7|类名：PanelType<br>起始版本：10|panel.d.ts|
|起始版本有变化|类名：PanelType<br>方法 or 属性：Minibar<br>起始版本：7|类名：PanelType<br>方法 or 属性：Minibar<br>起始版本：10|panel.d.ts|
|起始版本有变化|类名：PanelType<br>方法 or 属性：Foldable<br>起始版本：7|类名：PanelType<br>方法 or 属性：Foldable<br>起始版本：10|panel.d.ts|
|起始版本有变化|类名：PanelType<br>方法 or 属性：Temporary<br>起始版本：7|类名：PanelType<br>方法 or 属性：Temporary<br>起始版本：10|panel.d.ts|
|起始版本有变化|类名：PanelInterface<br>起始版本：7|类名：PanelInterface<br>起始版本：10|panel.d.ts|
|起始版本有变化|类名：PanelInterface<br>方法 or 属性：(show: boolean): PanelAttribute;<br>起始版本：7|类名：PanelInterface<br>方法 or 属性：(show: boolean): PanelAttribute;<br>起始版本：10|panel.d.ts|
|起始版本有变化|类名：PanelAttribute<br>起始版本：7|类名：PanelAttribute<br>起始版本：10|panel.d.ts|
|起始版本有变化|类名：PanelAttribute<br>方法 or 属性：mode(value: PanelMode): PanelAttribute;<br>起始版本：7|类名：PanelAttribute<br>方法 or 属性：mode(value: PanelMode): PanelAttribute;<br>起始版本：10|panel.d.ts|
|起始版本有变化|类名：PanelAttribute<br>方法 or 属性：type(value: PanelType): PanelAttribute;<br>起始版本：7|类名：PanelAttribute<br>方法 or 属性：type(value: PanelType): PanelAttribute;<br>起始版本：10|panel.d.ts|
|起始版本有变化|类名：PanelAttribute<br>方法 or 属性：dragBar(value: boolean): PanelAttribute;<br>起始版本：7|类名：PanelAttribute<br>方法 or 属性：dragBar(value: boolean): PanelAttribute;<br>起始版本：10|panel.d.ts|
|起始版本有变化|类名：PanelAttribute<br>方法 or 属性：fullHeight(value: number \| string): PanelAttribute;<br>起始版本：7|类名：PanelAttribute<br>方法 or 属性：fullHeight(value: number \| string): PanelAttribute;<br>起始版本：10|panel.d.ts|
|起始版本有变化|类名：PanelAttribute<br>方法 or 属性：halfHeight(value: number \| string): PanelAttribute;<br>起始版本：7|类名：PanelAttribute<br>方法 or 属性：halfHeight(value: number \| string): PanelAttribute;<br>起始版本：10|panel.d.ts|
|起始版本有变化|类名：PanelAttribute<br>方法 or 属性：miniHeight(value: number \| string): PanelAttribute;<br>起始版本：7|类名：PanelAttribute<br>方法 or 属性：miniHeight(value: number \| string): PanelAttribute;<br>起始版本：10|panel.d.ts|
|起始版本有变化|类名：PanelAttribute<br>方法 or 属性：show(value: boolean): PanelAttribute;<br>起始版本：7|类名：PanelAttribute<br>方法 or 属性：show(value: boolean): PanelAttribute;<br>起始版本：10|panel.d.ts|
|起始版本有变化|类名：PanelAttribute<br>方法 or 属性：backgroundMask(color: ResourceColor): PanelAttribute;<br>起始版本：9|类名：PanelAttribute<br>方法 or 属性：backgroundMask(color: ResourceColor): PanelAttribute;<br>起始版本：10|panel.d.ts|
|起始版本有变化|类名：PanelAttribute<br>方法 or 属性：onChange(<br>    event: (<br>      /**<br>       * Width of content area.<br>       * @since 7<br>       */<br>      width: number,<br><br>      /**<br>       * Height of content area.<br>       * @since 7<br>       */<br>      height: number,<br><br>      /**<br>       * Initial state.<br>       * @since 7<br>       */<br>      mode: PanelMode,<br>    ) => void,<br>  ): PanelAttribute;<br>起始版本：7|类名：PanelAttribute<br>方法 or 属性：onChange(<br>    event: (<br>      /**<br>       * Width of content area.<br>       * @since 7<br>       */<br>      width: number,<br><br>      /**<br>       * Height of content area.<br>       * @since 7<br>       */<br>      height: number,<br><br>      /**<br>       * Initial state.<br>       * @since 7<br>       */<br>      mode: PanelMode,<br>    ) => void,<br>  ): PanelAttribute;<br>起始版本：10|panel.d.ts|
|起始版本有变化|类名：PanelAttribute<br>方法 or 属性：onHeightChange(callback: (value: number) => void): PanelAttribute;<br>起始版本：9|类名：PanelAttribute<br>方法 or 属性：onHeightChange(callback: (value: number) => void): PanelAttribute;<br>起始版本：10|panel.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const Panel: PanelInterface;<br>起始版本：7|类名：global<br>方法 or 属性：declare const Panel: PanelInterface;<br>起始版本：10|panel.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const PanelInstance: PanelAttribute;<br>起始版本：7|类名：global<br>方法 or 属性：declare const PanelInstance: PanelAttribute;<br>起始版本：10|panel.d.ts|
|起始版本有变化|类名：PatternLockController<br>起始版本：9|类名：PatternLockController<br>起始版本：10|pattern_lock.d.ts|
|起始版本有变化|类名：PatternLockController<br>方法 or 属性：constructor();<br>起始版本：N/A|类名：PatternLockController<br>方法 or 属性：constructor();<br>起始版本：10|pattern_lock.d.ts|
|起始版本有变化|类名：PatternLockController<br>方法 or 属性：reset();<br>起始版本：N/A|类名：PatternLockController<br>方法 or 属性：reset();<br>起始版本：10|pattern_lock.d.ts|
|起始版本有变化|类名：PatternLockInterface<br>起始版本：9|类名：PatternLockInterface<br>起始版本：10|pattern_lock.d.ts|
|起始版本有变化|类名：PatternLockAttribute<br>起始版本：9|类名：PatternLockAttribute<br>起始版本：10|pattern_lock.d.ts|
|起始版本有变化|类名：PatternLockAttribute<br>方法 or 属性：sideLength(value: Length): PatternLockAttribute;<br>起始版本：9|类名：PatternLockAttribute<br>方法 or 属性：sideLength(value: Length): PatternLockAttribute;<br>起始版本：10|pattern_lock.d.ts|
|起始版本有变化|类名：PatternLockAttribute<br>方法 or 属性：circleRadius(value: Length): PatternLockAttribute;<br>起始版本：9|类名：PatternLockAttribute<br>方法 or 属性：circleRadius(value: Length): PatternLockAttribute;<br>起始版本：10|pattern_lock.d.ts|
|起始版本有变化|类名：PatternLockAttribute<br>方法 or 属性：backgroundColor(value: ResourceColor): PatternLockAttribute;<br>起始版本：9|类名：PatternLockAttribute<br>方法 or 属性：backgroundColor(value: ResourceColor): PatternLockAttribute;<br>起始版本：10|pattern_lock.d.ts|
|起始版本有变化|类名：PatternLockAttribute<br>方法 or 属性：regularColor(value: ResourceColor): PatternLockAttribute;<br>起始版本：9|类名：PatternLockAttribute<br>方法 or 属性：regularColor(value: ResourceColor): PatternLockAttribute;<br>起始版本：10|pattern_lock.d.ts|
|起始版本有变化|类名：PatternLockAttribute<br>方法 or 属性：selectedColor(value: ResourceColor): PatternLockAttribute;<br>起始版本：9|类名：PatternLockAttribute<br>方法 or 属性：selectedColor(value: ResourceColor): PatternLockAttribute;<br>起始版本：10|pattern_lock.d.ts|
|起始版本有变化|类名：PatternLockAttribute<br>方法 or 属性：activeColor(value: ResourceColor): PatternLockAttribute;<br>起始版本：9|类名：PatternLockAttribute<br>方法 or 属性：activeColor(value: ResourceColor): PatternLockAttribute;<br>起始版本：10|pattern_lock.d.ts|
|起始版本有变化|类名：PatternLockAttribute<br>方法 or 属性：pathColor(value: ResourceColor): PatternLockAttribute;<br>起始版本：9|类名：PatternLockAttribute<br>方法 or 属性：pathColor(value: ResourceColor): PatternLockAttribute;<br>起始版本：10|pattern_lock.d.ts|
|起始版本有变化|类名：PatternLockAttribute<br>方法 or 属性：pathStrokeWidth(value: number \| string): PatternLockAttribute;<br>起始版本：9|类名：PatternLockAttribute<br>方法 or 属性：pathStrokeWidth(value: number \| string): PatternLockAttribute;<br>起始版本：10|pattern_lock.d.ts|
|起始版本有变化|类名：PatternLockAttribute<br>方法 or 属性：onPatternComplete(callback: (input: Array\<number>) => void): PatternLockAttribute;<br>起始版本：9|类名：PatternLockAttribute<br>方法 or 属性：onPatternComplete(callback: (input: Array\<number>) => void): PatternLockAttribute;<br>起始版本：10|pattern_lock.d.ts|
|起始版本有变化|类名：PatternLockAttribute<br>方法 or 属性：autoReset(value: boolean): PatternLockAttribute;<br>起始版本：9|类名：PatternLockAttribute<br>方法 or 属性：autoReset(value: boolean): PatternLockAttribute;<br>起始版本：10|pattern_lock.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const PatternLock: PatternLockInterface;<br>起始版本：9|类名：global<br>方法 or 属性：declare const PatternLock: PatternLockInterface;<br>起始版本：10|pattern_lock.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const PatternLockInstance: PatternLockAttribute;<br>起始版本：9|类名：global<br>方法 or 属性：declare const PatternLockInstance: PatternLockAttribute;<br>起始版本：10|pattern_lock.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const Rect: RectInterface;<br>起始版本：9|类名：global<br>方法 or 属性：declare const Rect: RectInterface;<br>起始版本：10|rect.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const RectInstance: RectAttribute;<br>起始版本：9|类名：global<br>方法 or 属性：declare const RectInstance: RectAttribute;<br>起始版本：10|rect.d.ts|
|起始版本有变化|类名：RefreshStatus<br>起始版本：8|类名：RefreshStatus<br>起始版本：10|refresh.d.ts|
|起始版本有变化|类名：RefreshStatus<br>方法 or 属性：Inactive<br>起始版本：8|类名：RefreshStatus<br>方法 or 属性：Inactive<br>起始版本：10|refresh.d.ts|
|起始版本有变化|类名：RefreshStatus<br>方法 or 属性：Drag<br>起始版本：8|类名：RefreshStatus<br>方法 or 属性：Drag<br>起始版本：10|refresh.d.ts|
|起始版本有变化|类名：RefreshStatus<br>方法 or 属性：OverDrag<br>起始版本：8|类名：RefreshStatus<br>方法 or 属性：OverDrag<br>起始版本：10|refresh.d.ts|
|起始版本有变化|类名：RefreshStatus<br>方法 or 属性：Refresh<br>起始版本：8|类名：RefreshStatus<br>方法 or 属性：Refresh<br>起始版本：10|refresh.d.ts|
|起始版本有变化|类名：RefreshStatus<br>方法 or 属性：Done<br>起始版本：8|类名：RefreshStatus<br>方法 or 属性：Done<br>起始版本：10|refresh.d.ts|
|起始版本有变化|类名：RefreshInterface<br>起始版本：8|类名：RefreshInterface<br>起始版本：10|refresh.d.ts|
|起始版本有变化|类名：RefreshAttribute<br>起始版本：8|类名：RefreshAttribute<br>起始版本：10|refresh.d.ts|
|起始版本有变化|类名：RefreshAttribute<br>方法 or 属性：onStateChange(callback: (state: RefreshStatus) => void): RefreshAttribute;<br>起始版本：8|类名：RefreshAttribute<br>方法 or 属性：onStateChange(callback: (state: RefreshStatus) => void): RefreshAttribute;<br>起始版本：10|refresh.d.ts|
|起始版本有变化|类名：RefreshAttribute<br>方法 or 属性：onRefreshing(callback: () => void): RefreshAttribute;<br>起始版本：8|类名：RefreshAttribute<br>方法 or 属性：onRefreshing(callback: () => void): RefreshAttribute;<br>起始版本：10|refresh.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const Refresh: RefreshInterface;<br>起始版本：8|类名：global<br>方法 or 属性：declare const Refresh: RefreshInterface;<br>起始版本：10|refresh.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const RefreshInstance: RefreshAttribute;<br>起始版本：8|类名：global<br>方法 or 属性：declare const RefreshInstance: RefreshAttribute;<br>起始版本：10|refresh.d.ts|
|起始版本有变化|类名：RelativeContainerInterface<br>起始版本：9|类名：RelativeContainerInterface<br>起始版本：10|relative_container.d.ts|
|起始版本有变化|类名：RelativeContainerAttribute<br>起始版本：9|类名：RelativeContainerAttribute<br>起始版本：10|relative_container.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const RelativeContainerInstance: RelativeContainerAttribute;<br>起始版本：9|类名：global<br>方法 or 属性：declare const RelativeContainerInstance: RelativeContainerAttribute;<br>起始版本：10|relative_container.d.ts|
|起始版本有变化|类名：RowSplitInterface<br>起始版本：7|类名：RowSplitInterface<br>起始版本：10|row_split.d.ts|
|起始版本有变化|类名：RowSplitInterface<br>方法 or 属性：(): RowSplitAttribute;<br>起始版本：7|类名：RowSplitInterface<br>方法 or 属性：(): RowSplitAttribute;<br>起始版本：10|row_split.d.ts|
|起始版本有变化|类名：RowSplitAttribute<br>起始版本：7|类名：RowSplitAttribute<br>起始版本：10|row_split.d.ts|
|起始版本有变化|类名：RowSplitAttribute<br>方法 or 属性：resizeable(value: boolean): RowSplitAttribute;<br>起始版本：7|类名：RowSplitAttribute<br>方法 or 属性：resizeable(value: boolean): RowSplitAttribute;<br>起始版本：10|row_split.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const RowSplit: RowSplitInterface;<br>起始版本：7|类名：global<br>方法 or 属性：declare const RowSplit: RowSplitInterface;<br>起始版本：10|row_split.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const RowSplitInstance: RowSplitAttribute;<br>起始版本：7|类名：global<br>方法 or 属性：declare const RowSplitInstance: RowSplitAttribute;<br>起始版本：10|row_split.d.ts|
|起始版本有变化|类名：ScrollDirection<br>起始版本：7|类名：ScrollDirection<br>起始版本：10|scroll.d.ts|
|起始版本有变化|类名：ScrollDirection<br>方法 or 属性：Vertical<br>起始版本：7|类名：ScrollDirection<br>方法 or 属性：Vertical<br>起始版本：10|scroll.d.ts|
|起始版本有变化|类名：ScrollDirection<br>方法 or 属性：Horizontal<br>起始版本：7|类名：ScrollDirection<br>方法 or 属性：Horizontal<br>起始版本：10|scroll.d.ts|
|起始版本有变化|类名：ScrollDirection<br>方法 or 属性：None<br>起始版本：7|类名：ScrollDirection<br>方法 or 属性：None<br>起始版本：10|scroll.d.ts|
|起始版本有变化|类名：Scroller<br>起始版本：7|类名：Scroller<br>起始版本：10|scroll.d.ts|
|起始版本有变化|类名：Scroller<br>方法 or 属性：constructor();<br>起始版本：7|类名：Scroller<br>方法 or 属性：constructor();<br>起始版本：10|scroll.d.ts|
|起始版本有变化|类名：Scroller<br>方法 or 属性：scrollEdge(value: Edge);<br>起始版本：7|类名：Scroller<br>方法 or 属性：scrollEdge(value: Edge);<br>起始版本：10|scroll.d.ts|
|起始版本有变化|类名：Scroller<br>方法 or 属性：scrollPage(value: { next: boolean });<br>起始版本：9|类名：Scroller<br>方法 or 属性：scrollPage(value: { next: boolean });<br>起始版本：10|scroll.d.ts|
|起始版本有变化|类名：Scroller<br>方法 or 属性：currentOffset();<br>起始版本：7|类名：Scroller<br>方法 or 属性：currentOffset();<br>起始版本：10|scroll.d.ts|
|起始版本有变化|类名：Scroller<br>方法 or 属性：scrollBy(dx: Length, dy: Length);<br>起始版本：9|类名：Scroller<br>方法 or 属性：scrollBy(dx: Length, dy: Length);<br>起始版本：10|scroll.d.ts|
|起始版本有变化|类名：ScrollInterface<br>起始版本：7|类名：ScrollInterface<br>起始版本：10|scroll.d.ts|
|起始版本有变化|类名：ScrollInterface<br>方法 or 属性：(scroller?: Scroller): ScrollAttribute;<br>起始版本：7|类名：ScrollInterface<br>方法 or 属性：(scroller?: Scroller): ScrollAttribute;<br>起始版本：10|scroll.d.ts|
|起始版本有变化|类名：ScrollAttribute<br>起始版本：7|类名：ScrollAttribute<br>起始版本：10|scroll.d.ts|
|起始版本有变化|类名：ScrollAttribute<br>方法 or 属性：scrollable(value: ScrollDirection): ScrollAttribute;<br>起始版本：7|类名：ScrollAttribute<br>方法 or 属性：scrollable(value: ScrollDirection): ScrollAttribute;<br>起始版本：10|scroll.d.ts|
|起始版本有变化|类名：ScrollAttribute<br>方法 or 属性：onScroll(event: (xOffset: number, yOffset: number) => void): ScrollAttribute;<br>起始版本：7|类名：ScrollAttribute<br>方法 or 属性：onScroll(event: (xOffset: number, yOffset: number) => void): ScrollAttribute;<br>起始版本：10|scroll.d.ts|
|起始版本有变化|类名：ScrollAttribute<br>方法 or 属性：onScrollEdge(event: (side: Edge) => void): ScrollAttribute;<br>起始版本：7|类名：ScrollAttribute<br>方法 or 属性：onScrollEdge(event: (side: Edge) => void): ScrollAttribute;<br>起始版本：10|scroll.d.ts|
|起始版本有变化|类名：ScrollAttribute<br>方法 or 属性：onScrollStart(event: () => void): ScrollAttribute;<br>起始版本：9|类名：ScrollAttribute<br>方法 or 属性：onScrollStart(event: () => void): ScrollAttribute;<br>起始版本：10|scroll.d.ts|
|起始版本有变化|类名：ScrollAttribute<br>方法 or 属性：onScrollStop(event: () => void): ScrollAttribute;<br>起始版本：9|类名：ScrollAttribute<br>方法 or 属性：onScrollStop(event: () => void): ScrollAttribute;<br>起始版本：10|scroll.d.ts|
|起始版本有变化|类名：ScrollAttribute<br>方法 or 属性：scrollBar(barState: BarState): ScrollAttribute;<br>起始版本：7|类名：ScrollAttribute<br>方法 or 属性：scrollBar(barState: BarState): ScrollAttribute;<br>起始版本：10|scroll.d.ts|
|起始版本有变化|类名：ScrollAttribute<br>方法 or 属性：scrollBarColor(color: Color \| number \| string): ScrollAttribute;<br>起始版本：7|类名：ScrollAttribute<br>方法 or 属性：scrollBarColor(color: Color \| number \| string): ScrollAttribute;<br>起始版本：10|scroll.d.ts|
|起始版本有变化|类名：ScrollAttribute<br>方法 or 属性：scrollBarWidth(value: number \| string): ScrollAttribute;<br>起始版本：7|类名：ScrollAttribute<br>方法 or 属性：scrollBarWidth(value: number \| string): ScrollAttribute;<br>起始版本：10|scroll.d.ts|
|起始版本有变化|类名：ScrollAttribute<br>方法 or 属性：edgeEffect(edgeEffect: EdgeEffect): ScrollAttribute;<br>起始版本：7|类名：ScrollAttribute<br>方法 or 属性：edgeEffect(edgeEffect: EdgeEffect): ScrollAttribute;<br>起始版本：10|scroll.d.ts|
|起始版本有变化|类名：ScrollAttribute<br>方法 or 属性：onScrollFrameBegin(event: (offset: number, state: ScrollState) => { offsetRemain: number }): ScrollAttribute;<br>起始版本：9|类名：ScrollAttribute<br>方法 or 属性：onScrollFrameBegin(event: (offset: number, state: ScrollState) => { offsetRemain: number }): ScrollAttribute;<br>起始版本：10|scroll.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const Scroll: ScrollInterface;<br>起始版本：7|类名：global<br>方法 or 属性：declare const Scroll: ScrollInterface;<br>起始版本：10|scroll.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const ScrollInstance: ScrollAttribute;<br>起始版本：7|类名：global<br>方法 or 属性：declare const ScrollInstance: ScrollAttribute;<br>起始版本：10|scroll.d.ts|
|起始版本有变化|类名：ScrollBarDirection<br>起始版本：8|类名：ScrollBarDirection<br>起始版本：10|scroll_bar.d.ts|
|起始版本有变化|类名：ScrollBarDirection<br>方法 or 属性：Vertical<br>起始版本：8|类名：ScrollBarDirection<br>方法 or 属性：Vertical<br>起始版本：10|scroll_bar.d.ts|
|起始版本有变化|类名：ScrollBarDirection<br>方法 or 属性：Horizontal<br>起始版本：8|类名：ScrollBarDirection<br>方法 or 属性：Horizontal<br>起始版本：10|scroll_bar.d.ts|
|起始版本有变化|类名：ScrollBarOptions<br>起始版本：8|类名：ScrollBarOptions<br>起始版本：10|scroll_bar.d.ts|
|起始版本有变化|类名：ScrollBarOptions<br>方法 or 属性：scroller: Scroller;<br>起始版本：8|类名：ScrollBarOptions<br>方法 or 属性：scroller: Scroller;<br>起始版本：10|scroll_bar.d.ts|
|起始版本有变化|类名：ScrollBarOptions<br>方法 or 属性：direction?: ScrollBarDirection;<br>起始版本：8|类名：ScrollBarOptions<br>方法 or 属性：direction?: ScrollBarDirection;<br>起始版本：10|scroll_bar.d.ts|
|起始版本有变化|类名：ScrollBarOptions<br>方法 or 属性：state?: BarState;<br>起始版本：8|类名：ScrollBarOptions<br>方法 or 属性：state?: BarState;<br>起始版本：10|scroll_bar.d.ts|
|起始版本有变化|类名：ScrollBarInterface<br>起始版本：8|类名：ScrollBarInterface<br>起始版本：10|scroll_bar.d.ts|
|起始版本有变化|类名：ScrollBarInterface<br>方法 or 属性：(value: ScrollBarOptions): ScrollBarAttribute;<br>起始版本：8|类名：ScrollBarInterface<br>方法 or 属性：(value: ScrollBarOptions): ScrollBarAttribute;<br>起始版本：10|scroll_bar.d.ts|
|起始版本有变化|类名：ScrollBarAttribute<br>起始版本：8|类名：ScrollBarAttribute<br>起始版本：10|scroll_bar.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const ScrollBar: ScrollBarInterface;<br>起始版本：8|类名：global<br>方法 or 属性：declare const ScrollBar: ScrollBarInterface;<br>起始版本：10|scroll_bar.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const ScrollBarInstance: ScrollBarAttribute;<br>起始版本：8|类名：global<br>方法 or 属性：declare const ScrollBarInstance: ScrollBarAttribute;<br>起始版本：10|scroll_bar.d.ts|
|起始版本有变化|类名：SearchController<br>起始版本：8|类名：SearchController<br>起始版本：10|search.d.ts|
|起始版本有变化|类名：SearchController<br>方法 or 属性：constructor();<br>起始版本：8|类名：SearchController<br>方法 or 属性：constructor();<br>起始版本：10|search.d.ts|
|起始版本有变化|类名：SearchController<br>方法 or 属性：caretPosition(value: number): void;<br>起始版本：8|类名：SearchController<br>方法 or 属性：caretPosition(value: number): void;<br>起始版本：10|search.d.ts|
|起始版本有变化|类名：SearchInterface<br>起始版本：8|类名：SearchInterface<br>起始版本：10|search.d.ts|
|起始版本有变化|类名：SearchAttribute<br>起始版本：8|类名：SearchAttribute<br>起始版本：10|search.d.ts|
|起始版本有变化|类名：SearchAttribute<br>方法 or 属性：placeholderColor(value: ResourceColor): SearchAttribute;<br>起始版本：8|类名：SearchAttribute<br>方法 or 属性：placeholderColor(value: ResourceColor): SearchAttribute;<br>起始版本：10|search.d.ts|
|起始版本有变化|类名：SearchAttribute<br>方法 or 属性：placeholderFont(value?: Font): SearchAttribute;<br>起始版本：8|类名：SearchAttribute<br>方法 or 属性：placeholderFont(value?: Font): SearchAttribute;<br>起始版本：10|search.d.ts|
|起始版本有变化|类名：SearchAttribute<br>方法 or 属性：textFont(value?: Font): SearchAttribute;<br>起始版本：8|类名：SearchAttribute<br>方法 or 属性：textFont(value?: Font): SearchAttribute;<br>起始版本：10|search.d.ts|
|起始版本有变化|类名：SearchAttribute<br>方法 or 属性：onSubmit(callback: (value: string) => void): SearchAttribute;<br>起始版本：8|类名：SearchAttribute<br>方法 or 属性：onSubmit(callback: (value: string) => void): SearchAttribute;<br>起始版本：10|search.d.ts|
|起始版本有变化|类名：SearchAttribute<br>方法 or 属性：onChange(callback: (value: string) => void): SearchAttribute;<br>起始版本：8|类名：SearchAttribute<br>方法 or 属性：onChange(callback: (value: string) => void): SearchAttribute;<br>起始版本：10|search.d.ts|
|起始版本有变化|类名：SearchAttribute<br>方法 or 属性：onCopy(callback: (value: string) => void): SearchAttribute;<br>起始版本：8|类名：SearchAttribute<br>方法 or 属性：onCopy(callback: (value: string) => void): SearchAttribute;<br>起始版本：10|search.d.ts|
|起始版本有变化|类名：SearchAttribute<br>方法 or 属性：onCut(callback: (value: string) => void): SearchAttribute;<br>起始版本：8|类名：SearchAttribute<br>方法 or 属性：onCut(callback: (value: string) => void): SearchAttribute;<br>起始版本：10|search.d.ts|
|起始版本有变化|类名：SearchAttribute<br>方法 or 属性：onPaste(callback: (value: string) => void): SearchAttribute;<br>起始版本：8|类名：SearchAttribute<br>方法 or 属性：onPaste(callback: (value: string) => void): SearchAttribute;<br>起始版本：10|search.d.ts|
|起始版本有变化|类名：SearchAttribute<br>方法 or 属性：copyOption(value: CopyOptions): SearchAttribute;<br>起始版本：9|类名：SearchAttribute<br>方法 or 属性：copyOption(value: CopyOptions): SearchAttribute;<br>起始版本：10|search.d.ts|
|起始版本有变化|类名：SearchAttribute<br>方法 or 属性：textAlign(value: TextAlign): SearchAttribute;<br>起始版本：9|类名：SearchAttribute<br>方法 or 属性：textAlign(value: TextAlign): SearchAttribute;<br>起始版本：10|search.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const Search: SearchInterface;<br>起始版本：8|类名：global<br>方法 or 属性：declare const Search: SearchInterface;<br>起始版本：10|search.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const SearchInstance: SearchAttribute;<br>起始版本：8|类名：global<br>方法 or 属性：declare const SearchInstance: SearchAttribute;<br>起始版本：10|search.d.ts|
|起始版本有变化|类名：SelectOption<br>起始版本：8|类名：SelectOption<br>起始版本：10|select.d.ts|
|起始版本有变化|类名：SelectOption<br>方法 or 属性：value: ResourceStr;<br>起始版本：8|类名：SelectOption<br>方法 or 属性：value: ResourceStr;<br>起始版本：10|select.d.ts|
|起始版本有变化|类名：SelectOption<br>方法 or 属性：icon?: ResourceStr;<br>起始版本：8|类名：SelectOption<br>方法 or 属性：icon?: ResourceStr;<br>起始版本：10|select.d.ts|
|起始版本有变化|类名：SelectInterface<br>起始版本：8|类名：SelectInterface<br>起始版本：10|select.d.ts|
|起始版本有变化|类名：SelectInterface<br>方法 or 属性：(options: Array\<SelectOption>): SelectAttribute;<br>起始版本：8|类名：SelectInterface<br>方法 or 属性：(options: Array\<SelectOption>): SelectAttribute;<br>起始版本：10|select.d.ts|
|起始版本有变化|类名：SelectAttribute<br>起始版本：8|类名：SelectAttribute<br>起始版本：10|select.d.ts|
|起始版本有变化|类名：SelectAttribute<br>方法 or 属性：selected(value: number): SelectAttribute;<br>起始版本：8|类名：SelectAttribute<br>方法 or 属性：selected(value: number): SelectAttribute;<br>起始版本：10|select.d.ts|
|起始版本有变化|类名：SelectAttribute<br>方法 or 属性：value(value: string): SelectAttribute;<br>起始版本：8|类名：SelectAttribute<br>方法 or 属性：value(value: string): SelectAttribute;<br>起始版本：10|select.d.ts|
|起始版本有变化|类名：SelectAttribute<br>方法 or 属性：font(value: Font): SelectAttribute;<br>起始版本：8|类名：SelectAttribute<br>方法 or 属性：font(value: Font): SelectAttribute;<br>起始版本：10|select.d.ts|
|起始版本有变化|类名：SelectAttribute<br>方法 or 属性：fontColor(value: ResourceColor): SelectAttribute;<br>起始版本：8|类名：SelectAttribute<br>方法 or 属性：fontColor(value: ResourceColor): SelectAttribute;<br>起始版本：10|select.d.ts|
|起始版本有变化|类名：SelectAttribute<br>方法 or 属性：selectedOptionBgColor(value: ResourceColor): SelectAttribute;<br>起始版本：8|类名：SelectAttribute<br>方法 or 属性：selectedOptionBgColor(value: ResourceColor): SelectAttribute;<br>起始版本：10|select.d.ts|
|起始版本有变化|类名：SelectAttribute<br>方法 or 属性：selectedOptionFont(value: Font): SelectAttribute;<br>起始版本：8|类名：SelectAttribute<br>方法 or 属性：selectedOptionFont(value: Font): SelectAttribute;<br>起始版本：10|select.d.ts|
|起始版本有变化|类名：SelectAttribute<br>方法 or 属性：selectedOptionFontColor(value: ResourceColor): SelectAttribute;<br>起始版本：8|类名：SelectAttribute<br>方法 or 属性：selectedOptionFontColor(value: ResourceColor): SelectAttribute;<br>起始版本：10|select.d.ts|
|起始版本有变化|类名：SelectAttribute<br>方法 or 属性：optionBgColor(value: ResourceColor): SelectAttribute;<br>起始版本：8|类名：SelectAttribute<br>方法 or 属性：optionBgColor(value: ResourceColor): SelectAttribute;<br>起始版本：10|select.d.ts|
|起始版本有变化|类名：SelectAttribute<br>方法 or 属性：optionFont(value: Font): SelectAttribute;<br>起始版本：8|类名：SelectAttribute<br>方法 or 属性：optionFont(value: Font): SelectAttribute;<br>起始版本：10|select.d.ts|
|起始版本有变化|类名：SelectAttribute<br>方法 or 属性：optionFontColor(value: ResourceColor): SelectAttribute;<br>起始版本：8|类名：SelectAttribute<br>方法 or 属性：optionFontColor(value: ResourceColor): SelectAttribute;<br>起始版本：10|select.d.ts|
|起始版本有变化|类名：SelectAttribute<br>方法 or 属性：onSelect(callback: (index: number, value?: string) => void): SelectAttribute;<br>起始版本：8|类名：SelectAttribute<br>方法 or 属性：onSelect(callback: (index: number, value?: string) => void): SelectAttribute;<br>起始版本：10|select.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const Select: SelectInterface;<br>起始版本：8|类名：global<br>方法 or 属性：declare const Select: SelectInterface;<br>起始版本：10|select.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const SelectInstance: SelectAttribute;<br>起始版本：8|类名：global<br>方法 or 属性：declare const SelectInstance: SelectAttribute;<br>起始版本：10|select.d.ts|
|起始版本有变化|类名：ShapeInterface<br>方法 or 属性：new (value?: PixelMap): ShapeAttribute;<br>起始版本：7|类名：ShapeInterface<br>方法 or 属性：new (value?: PixelMap): ShapeAttribute;<br>起始版本：10|shape.d.ts|
|起始版本有变化|类名：ShapeInterface<br>方法 or 属性：(value: PixelMap): ShapeAttribute;<br>起始版本：7|类名：ShapeInterface<br>方法 or 属性：(value: PixelMap): ShapeAttribute;<br>起始版本：10|shape.d.ts|
|起始版本有变化|类名：SideBarContainerType<br>起始版本：8|类名：SideBarContainerType<br>起始版本：10|sidebar.d.ts|
|起始版本有变化|类名：SideBarContainerType<br>方法 or 属性：Embed<br>起始版本：8|类名：SideBarContainerType<br>方法 or 属性：Embed<br>起始版本：10|sidebar.d.ts|
|起始版本有变化|类名：SideBarContainerType<br>方法 or 属性：Overlay<br>起始版本：8|类名：SideBarContainerType<br>方法 or 属性：Overlay<br>起始版本：10|sidebar.d.ts|
|起始版本有变化|类名：SideBarPosition<br>起始版本：9|类名：SideBarPosition<br>起始版本：10|sidebar.d.ts|
|起始版本有变化|类名：SideBarPosition<br>方法 or 属性：Start<br>起始版本：9|类名：SideBarPosition<br>方法 or 属性：Start<br>起始版本：10|sidebar.d.ts|
|起始版本有变化|类名：SideBarPosition<br>方法 or 属性：End<br>起始版本：9|类名：SideBarPosition<br>方法 or 属性：End<br>起始版本：10|sidebar.d.ts|
|起始版本有变化|类名：ButtonStyle<br>起始版本：8|类名：ButtonStyle<br>起始版本：10|sidebar.d.ts|
|起始版本有变化|类名：ButtonStyle<br>方法 or 属性：left?: number;<br>起始版本：8|类名：ButtonStyle<br>方法 or 属性：left?: number;<br>起始版本：10|sidebar.d.ts|
|起始版本有变化|类名：ButtonStyle<br>方法 or 属性：top?: number;<br>起始版本：8|类名：ButtonStyle<br>方法 or 属性：top?: number;<br>起始版本：10|sidebar.d.ts|
|起始版本有变化|类名：ButtonStyle<br>方法 or 属性：width?: number;<br>起始版本：8|类名：ButtonStyle<br>方法 or 属性：width?: number;<br>起始版本：10|sidebar.d.ts|
|起始版本有变化|类名：ButtonStyle<br>方法 or 属性：height?: number;<br>起始版本：8|类名：ButtonStyle<br>方法 or 属性：height?: number;<br>起始版本：10|sidebar.d.ts|
|起始版本有变化|类名：SideBarContainerInterface<br>起始版本：8|类名：SideBarContainerInterface<br>起始版本：10|sidebar.d.ts|
|起始版本有变化|类名：SideBarContainerInterface<br>方法 or 属性：(type?: SideBarContainerType): SideBarContainerAttribute;<br>起始版本：8|类名：SideBarContainerInterface<br>方法 or 属性：(type?: SideBarContainerType): SideBarContainerAttribute;<br>起始版本：10|sidebar.d.ts|
|起始版本有变化|类名：SideBarContainerAttribute<br>起始版本：8|类名：SideBarContainerAttribute<br>起始版本：10|sidebar.d.ts|
|起始版本有变化|类名：SideBarContainerAttribute<br>方法 or 属性：showSideBar(value: boolean): SideBarContainerAttribute;<br>起始版本：8|类名：SideBarContainerAttribute<br>方法 or 属性：showSideBar(value: boolean): SideBarContainerAttribute;<br>起始版本：10|sidebar.d.ts|
|起始版本有变化|类名：SideBarContainerAttribute<br>方法 or 属性：controlButton(value: ButtonStyle): SideBarContainerAttribute;<br>起始版本：8|类名：SideBarContainerAttribute<br>方法 or 属性：controlButton(value: ButtonStyle): SideBarContainerAttribute;<br>起始版本：10|sidebar.d.ts|
|起始版本有变化|类名：SideBarContainerAttribute<br>方法 or 属性：showControlButton(value: boolean): SideBarContainerAttribute;<br>起始版本：8|类名：SideBarContainerAttribute<br>方法 or 属性：showControlButton(value: boolean): SideBarContainerAttribute;<br>起始版本：10|sidebar.d.ts|
|起始版本有变化|类名：SideBarContainerAttribute<br>方法 or 属性：onChange(callback: (value: boolean) => void): SideBarContainerAttribute;<br>起始版本：8|类名：SideBarContainerAttribute<br>方法 or 属性：onChange(callback: (value: boolean) => void): SideBarContainerAttribute;<br>起始版本：10|sidebar.d.ts|
|起始版本有变化|类名：SideBarContainerAttribute<br>方法 or 属性：sideBarWidth(value: number): SideBarContainerAttribute;<br>起始版本：8|类名：SideBarContainerAttribute<br>方法 or 属性：sideBarWidth(value: number): SideBarContainerAttribute;<br>起始版本：10|sidebar.d.ts|
|起始版本有变化|类名：SideBarContainerAttribute<br>方法 or 属性：minSideBarWidth(value: number): SideBarContainerAttribute;<br>起始版本：8|类名：SideBarContainerAttribute<br>方法 or 属性：minSideBarWidth(value: number): SideBarContainerAttribute;<br>起始版本：10|sidebar.d.ts|
|起始版本有变化|类名：SideBarContainerAttribute<br>方法 or 属性：maxSideBarWidth(value: number): SideBarContainerAttribute;<br>起始版本：8|类名：SideBarContainerAttribute<br>方法 or 属性：maxSideBarWidth(value: number): SideBarContainerAttribute;<br>起始版本：10|sidebar.d.ts|
|起始版本有变化|类名：SideBarContainerAttribute<br>方法 or 属性：sideBarWidth(value: Length): SideBarContainerAttribute;<br>起始版本：9|类名：SideBarContainerAttribute<br>方法 or 属性：sideBarWidth(value: Length): SideBarContainerAttribute;<br>起始版本：10|sidebar.d.ts|
|起始版本有变化|类名：SideBarContainerAttribute<br>方法 or 属性：minSideBarWidth(value: Length): SideBarContainerAttribute;<br>起始版本：9|类名：SideBarContainerAttribute<br>方法 or 属性：minSideBarWidth(value: Length): SideBarContainerAttribute;<br>起始版本：10|sidebar.d.ts|
|起始版本有变化|类名：SideBarContainerAttribute<br>方法 or 属性：maxSideBarWidth(value: Length): SideBarContainerAttribute;<br>起始版本：9|类名：SideBarContainerAttribute<br>方法 or 属性：maxSideBarWidth(value: Length): SideBarContainerAttribute;<br>起始版本：10|sidebar.d.ts|
|起始版本有变化|类名：SideBarContainerAttribute<br>方法 or 属性：autoHide(value: boolean): SideBarContainerAttribute;<br>起始版本：9|类名：SideBarContainerAttribute<br>方法 or 属性：autoHide(value: boolean): SideBarContainerAttribute;<br>起始版本：10|sidebar.d.ts|
|起始版本有变化|类名：SideBarContainerAttribute<br>方法 or 属性：sideBarPosition(value: SideBarPosition): SideBarContainerAttribute;<br>起始版本：9|类名：SideBarContainerAttribute<br>方法 or 属性：sideBarPosition(value: SideBarPosition): SideBarContainerAttribute;<br>起始版本：10|sidebar.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const SideBarContainer: SideBarContainerInterface;<br>起始版本：8|类名：global<br>方法 or 属性：declare const SideBarContainer: SideBarContainerInterface;<br>起始版本：10|sidebar.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const SideBarContainerInstance: SideBarContainerAttribute;<br>起始版本：8|类名：global<br>方法 or 属性：declare const SideBarContainerInstance: SideBarContainerAttribute;<br>起始版本：10|sidebar.d.ts|
|起始版本有变化|类名：ColorMode<br>起始版本：7|类名：ColorMode<br>起始版本：10|state_management.d.ts|
|起始版本有变化|类名：ColorMode<br>方法 or 属性：LIGHT = 0<br>起始版本：7|类名：ColorMode<br>方法 or 属性：LIGHT = 0<br>起始版本：10|state_management.d.ts|
|起始版本有变化|类名：ColorMode<br>方法 or 属性：DARK<br>起始版本：7|类名：ColorMode<br>方法 or 属性：DARK<br>起始版本：10|state_management.d.ts|
|起始版本有变化|类名：LayoutDirection<br>起始版本：7|类名：LayoutDirection<br>起始版本：10|state_management.d.ts|
|起始版本有变化|类名：LayoutDirection<br>方法 or 属性：LTR<br>起始版本：7|类名：LayoutDirection<br>方法 or 属性：LTR<br>起始版本：10|state_management.d.ts|
|起始版本有变化|类名：LayoutDirection<br>方法 or 属性：RTL<br>起始版本：7|类名：LayoutDirection<br>方法 or 属性：RTL<br>起始版本：10|state_management.d.ts|
|起始版本有变化|类名：LayoutDirection<br>方法 or 属性：Auto<br>起始版本：8|类名：LayoutDirection<br>方法 or 属性：Auto<br>起始版本：10|state_management.d.ts|
|起始版本有变化|类名：StepperInterface<br>起始版本：8|类名：StepperInterface<br>起始版本：10|stepper.d.ts|
|起始版本有变化|类名：StepperInterface<br>方法 or 属性：(value?: { index?: number }): StepperAttribute;<br>起始版本：8|类名：StepperInterface<br>方法 or 属性：(value?: { index?: number }): StepperAttribute;<br>起始版本：10|stepper.d.ts|
|起始版本有变化|类名：StepperAttribute<br>起始版本：8|类名：StepperAttribute<br>起始版本：10|stepper.d.ts|
|起始版本有变化|类名：StepperAttribute<br>方法 or 属性：onFinish(callback: () => void): StepperAttribute;<br>起始版本：8|类名：StepperAttribute<br>方法 or 属性：onFinish(callback: () => void): StepperAttribute;<br>起始版本：10|stepper.d.ts|
|起始版本有变化|类名：StepperAttribute<br>方法 or 属性：onSkip(callback: () => void): StepperAttribute;<br>起始版本：8|类名：StepperAttribute<br>方法 or 属性：onSkip(callback: () => void): StepperAttribute;<br>起始版本：10|stepper.d.ts|
|起始版本有变化|类名：StepperAttribute<br>方法 or 属性：onChange(callback: (prevIndex?: number, index?: number) => void): StepperAttribute;<br>起始版本：8|类名：StepperAttribute<br>方法 or 属性：onChange(callback: (prevIndex?: number, index?: number) => void): StepperAttribute;<br>起始版本：10|stepper.d.ts|
|起始版本有变化|类名：StepperAttribute<br>方法 or 属性：onNext(callback: (index?: number, pendingIndex?: number) => void): StepperAttribute;<br>起始版本：8|类名：StepperAttribute<br>方法 or 属性：onNext(callback: (index?: number, pendingIndex?: number) => void): StepperAttribute;<br>起始版本：10|stepper.d.ts|
|起始版本有变化|类名：StepperAttribute<br>方法 or 属性：onPrevious(callback: (index?: number, pendingIndex?: number) => void): StepperAttribute;<br>起始版本：8|类名：StepperAttribute<br>方法 or 属性：onPrevious(callback: (index?: number, pendingIndex?: number) => void): StepperAttribute;<br>起始版本：10|stepper.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const Stepper: StepperInterface;<br>起始版本：8|类名：global<br>方法 or 属性：declare const Stepper: StepperInterface;<br>起始版本：10|stepper.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const StepperInstance: StepperAttribute;<br>起始版本：8|类名：global<br>方法 or 属性：declare const StepperInstance: StepperAttribute;<br>起始版本：10|stepper.d.ts|
|起始版本有变化|类名：ItemState<br>起始版本：8|类名：ItemState<br>起始版本：10|stepper_item.d.ts|
|起始版本有变化|类名：ItemState<br>方法 or 属性：Normal<br>起始版本：8|类名：ItemState<br>方法 or 属性：Normal<br>起始版本：10|stepper_item.d.ts|
|起始版本有变化|类名：ItemState<br>方法 or 属性：Disabled<br>起始版本：8|类名：ItemState<br>方法 or 属性：Disabled<br>起始版本：10|stepper_item.d.ts|
|起始版本有变化|类名：ItemState<br>方法 or 属性：Waiting<br>起始版本：8|类名：ItemState<br>方法 or 属性：Waiting<br>起始版本：10|stepper_item.d.ts|
|起始版本有变化|类名：ItemState<br>方法 or 属性：Skip<br>起始版本：8|类名：ItemState<br>方法 or 属性：Skip<br>起始版本：10|stepper_item.d.ts|
|起始版本有变化|类名：StepperItemInterface<br>起始版本：8|类名：StepperItemInterface<br>起始版本：10|stepper_item.d.ts|
|起始版本有变化|类名：StepperItemInterface<br>方法 or 属性：(): StepperItemAttribute;<br>起始版本：8|类名：StepperItemInterface<br>方法 or 属性：(): StepperItemAttribute;<br>起始版本：10|stepper_item.d.ts|
|起始版本有变化|类名：StepperItemAttribute<br>起始版本：8|类名：StepperItemAttribute<br>起始版本：10|stepper_item.d.ts|
|起始版本有变化|类名：StepperItemAttribute<br>方法 or 属性：prevLabel(value: string): StepperItemAttribute;<br>起始版本：8|类名：StepperItemAttribute<br>方法 or 属性：prevLabel(value: string): StepperItemAttribute;<br>起始版本：10|stepper_item.d.ts|
|起始版本有变化|类名：StepperItemAttribute<br>方法 or 属性：nextLabel(value: string): StepperItemAttribute;<br>起始版本：8|类名：StepperItemAttribute<br>方法 or 属性：nextLabel(value: string): StepperItemAttribute;<br>起始版本：10|stepper_item.d.ts|
|起始版本有变化|类名：StepperItemAttribute<br>方法 or 属性：status(value?: ItemState): StepperItemAttribute;<br>起始版本：8|类名：StepperItemAttribute<br>方法 or 属性：status(value?: ItemState): StepperItemAttribute;<br>起始版本：10|stepper_item.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const StepperItemInstance: StepperItemAttribute;<br>起始版本：8|类名：global<br>方法 or 属性：declare const StepperItemInstance: StepperItemAttribute;<br>起始版本：10|stepper_item.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const StepperItem: StepperItemInterface;<br>起始版本：8|类名：global<br>方法 or 属性：declare const StepperItem: StepperItemInterface;<br>起始版本：10|stepper_item.d.ts|
|起始版本有变化|类名：SwiperController<br>起始版本：7|类名：SwiperController<br>起始版本：10|swiper.d.ts|
|起始版本有变化|类名：SwiperController<br>方法 or 属性：constructor();<br>起始版本：7|类名：SwiperController<br>方法 or 属性：constructor();<br>起始版本：10|swiper.d.ts|
|起始版本有变化|类名：SwiperController<br>方法 or 属性：showNext();<br>起始版本：7|类名：SwiperController<br>方法 or 属性：showNext();<br>起始版本：10|swiper.d.ts|
|起始版本有变化|类名：SwiperController<br>方法 or 属性：showPrevious();<br>起始版本：7|类名：SwiperController<br>方法 or 属性：showPrevious();<br>起始版本：10|swiper.d.ts|
|起始版本有变化|类名：SwiperController<br>方法 or 属性：finishAnimation(callback?: () => void);<br>起始版本：7|类名：SwiperController<br>方法 or 属性：finishAnimation(callback?: () => void);<br>起始版本：10|swiper.d.ts|
|起始版本有变化|类名：SwiperDisplayMode<br>起始版本：7|类名：SwiperDisplayMode<br>起始版本：10|swiper.d.ts|
|起始版本有变化|类名：SwiperDisplayMode<br>方法 or 属性：Stretch<br>起始版本：7|类名：SwiperDisplayMode<br>方法 or 属性：Stretch<br>起始版本：10|swiper.d.ts|
|起始版本有变化|类名：SwiperDisplayMode<br>方法 or 属性：AutoLinear<br>起始版本：7|类名：SwiperDisplayMode<br>方法 or 属性：AutoLinear<br>起始版本：10|swiper.d.ts|
|起始版本有变化|类名：SwiperInterface<br>起始版本：7|类名：SwiperInterface<br>起始版本：10|swiper.d.ts|
|起始版本有变化|类名：SwiperInterface<br>方法 or 属性：(controller?: SwiperController): SwiperAttribute;<br>起始版本：7|类名：SwiperInterface<br>方法 or 属性：(controller?: SwiperController): SwiperAttribute;<br>起始版本：10|swiper.d.ts|
|起始版本有变化|类名：SwiperAttribute<br>起始版本：7|类名：SwiperAttribute<br>起始版本：10|swiper.d.ts|
|起始版本有变化|类名：SwiperAttribute<br>方法 or 属性：index(value: number): SwiperAttribute;<br>起始版本：7|类名：SwiperAttribute<br>方法 or 属性：index(value: number): SwiperAttribute;<br>起始版本：10|swiper.d.ts|
|起始版本有变化|类名：SwiperAttribute<br>方法 or 属性：autoPlay(value: boolean): SwiperAttribute;<br>起始版本：7|类名：SwiperAttribute<br>方法 or 属性：autoPlay(value: boolean): SwiperAttribute;<br>起始版本：10|swiper.d.ts|
|起始版本有变化|类名：SwiperAttribute<br>方法 or 属性：interval(value: number): SwiperAttribute;<br>起始版本：7|类名：SwiperAttribute<br>方法 or 属性：interval(value: number): SwiperAttribute;<br>起始版本：10|swiper.d.ts|
|起始版本有变化|类名：SwiperAttribute<br>方法 or 属性：loop(value: boolean): SwiperAttribute;<br>起始版本：7|类名：SwiperAttribute<br>方法 or 属性：loop(value: boolean): SwiperAttribute;<br>起始版本：10|swiper.d.ts|
|起始版本有变化|类名：SwiperAttribute<br>方法 or 属性：duration(value: number): SwiperAttribute;<br>起始版本：7|类名：SwiperAttribute<br>方法 or 属性：duration(value: number): SwiperAttribute;<br>起始版本：10|swiper.d.ts|
|起始版本有变化|类名：SwiperAttribute<br>方法 or 属性：vertical(value: boolean): SwiperAttribute;<br>起始版本：7|类名：SwiperAttribute<br>方法 or 属性：vertical(value: boolean): SwiperAttribute;<br>起始版本：10|swiper.d.ts|
|起始版本有变化|类名：SwiperAttribute<br>方法 or 属性：itemSpace(value: number \| string): SwiperAttribute;<br>起始版本：7|类名：SwiperAttribute<br>方法 or 属性：itemSpace(value: number \| string): SwiperAttribute;<br>起始版本：10|swiper.d.ts|
|起始版本有变化|类名：SwiperAttribute<br>方法 or 属性：displayMode(value: SwiperDisplayMode): SwiperAttribute;<br>起始版本：7|类名：SwiperAttribute<br>方法 or 属性：displayMode(value: SwiperDisplayMode): SwiperAttribute;<br>起始版本：10|swiper.d.ts|
|起始版本有变化|类名：SwiperAttribute<br>方法 or 属性：cachedCount(value: number): SwiperAttribute;<br>起始版本：8|类名：SwiperAttribute<br>方法 or 属性：cachedCount(value: number): SwiperAttribute;<br>起始版本：10|swiper.d.ts|
|起始版本有变化|类名：SwiperAttribute<br>方法 or 属性：displayCount(value: number \| string): SwiperAttribute;<br>起始版本：8|类名：SwiperAttribute<br>方法 or 属性：displayCount(value: number \| string): SwiperAttribute;<br>起始版本：10|swiper.d.ts|
|起始版本有变化|类名：SwiperAttribute<br>方法 or 属性：effectMode(value: EdgeEffect): SwiperAttribute;<br>起始版本：8|类名：SwiperAttribute<br>方法 or 属性：effectMode(value: EdgeEffect): SwiperAttribute;<br>起始版本：10|swiper.d.ts|
|起始版本有变化|类名：SwiperAttribute<br>方法 or 属性：disableSwipe(value: boolean): SwiperAttribute;<br>起始版本：8|类名：SwiperAttribute<br>方法 or 属性：disableSwipe(value: boolean): SwiperAttribute;<br>起始版本：10|swiper.d.ts|
|起始版本有变化|类名：SwiperAttribute<br>方法 or 属性：onChange(event: (index: number) => void): SwiperAttribute;<br>起始版本：7|类名：SwiperAttribute<br>方法 or 属性：onChange(event: (index: number) => void): SwiperAttribute;<br>起始版本：10|swiper.d.ts|
|起始版本有变化|类名：SwiperAttribute<br>方法 or 属性：onAnimationStart(event: (index: number) => void): SwiperAttribute;<br>起始版本：9|类名：SwiperAttribute<br>方法 or 属性：onAnimationStart(event: (index: number) => void): SwiperAttribute;<br>起始版本：10|swiper.d.ts|
|起始版本有变化|类名：SwiperAttribute<br>方法 or 属性：onAnimationEnd(event: (index: number) => void): SwiperAttribute;<br>起始版本：9|类名：SwiperAttribute<br>方法 or 属性：onAnimationEnd(event: (index: number) => void): SwiperAttribute;<br>起始版本：10|swiper.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const Swiper: SwiperInterface;<br>起始版本：7|类名：global<br>方法 or 属性：declare const Swiper: SwiperInterface;<br>起始版本：10|swiper.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const SwiperInstance: SwiperAttribute;<br>起始版本：7|类名：global<br>方法 or 属性：declare const SwiperInstance: SwiperAttribute;<br>起始版本：10|swiper.d.ts|
|起始版本有变化|类名：BarMode<br>起始版本：7|类名：BarMode<br>起始版本：10|tabs.d.ts|
|起始版本有变化|类名：BarMode<br>方法 or 属性：Scrollable<br>起始版本：7|类名：BarMode<br>方法 or 属性：Scrollable<br>起始版本：10|tabs.d.ts|
|起始版本有变化|类名：BarMode<br>方法 or 属性：Fixed<br>起始版本：7|类名：BarMode<br>方法 or 属性：Fixed<br>起始版本：10|tabs.d.ts|
|起始版本有变化|类名：BarPosition<br>起始版本：7|类名：BarPosition<br>起始版本：10|tabs.d.ts|
|起始版本有变化|类名：BarPosition<br>方法 or 属性：Start<br>起始版本：7|类名：BarPosition<br>方法 or 属性：Start<br>起始版本：10|tabs.d.ts|
|起始版本有变化|类名：BarPosition<br>方法 or 属性：End<br>起始版本：7|类名：BarPosition<br>方法 or 属性：End<br>起始版本：10|tabs.d.ts|
|起始版本有变化|类名：TabsController<br>起始版本：7|类名：TabsController<br>起始版本：10|tabs.d.ts|
|起始版本有变化|类名：TabsController<br>方法 or 属性：constructor();<br>起始版本：7|类名：TabsController<br>方法 or 属性：constructor();<br>起始版本：10|tabs.d.ts|
|起始版本有变化|类名：TabsController<br>方法 or 属性：changeIndex(value: number): void;<br>起始版本：7|类名：TabsController<br>方法 or 属性：changeIndex(value: number): void;<br>起始版本：10|tabs.d.ts|
|起始版本有变化|类名：TabsInterface<br>起始版本：7|类名：TabsInterface<br>起始版本：10|tabs.d.ts|
|起始版本有变化|类名：TabsInterface<br>方法 or 属性：(value?: { barPosition?: BarPosition; index?: number; controller?: TabsController }): TabsAttribute;<br>起始版本：7|类名：TabsInterface<br>方法 or 属性：(value?: { barPosition?: BarPosition; index?: number; controller?: TabsController }): TabsAttribute;<br>起始版本：10|tabs.d.ts|
|起始版本有变化|类名：TabsAttribute<br>起始版本：7|类名：TabsAttribute<br>起始版本：10|tabs.d.ts|
|起始版本有变化|类名：TabsAttribute<br>方法 or 属性：vertical(value: boolean): TabsAttribute;<br>起始版本：7|类名：TabsAttribute<br>方法 or 属性：vertical(value: boolean): TabsAttribute;<br>起始版本：10|tabs.d.ts|
|起始版本有变化|类名：TabsAttribute<br>方法 or 属性：barPosition(value: BarPosition): TabsAttribute;<br>起始版本：9|类名：TabsAttribute<br>方法 or 属性：barPosition(value: BarPosition): TabsAttribute;<br>起始版本：10|tabs.d.ts|
|起始版本有变化|类名：TabsAttribute<br>方法 or 属性：scrollable(value: boolean): TabsAttribute;<br>起始版本：7|类名：TabsAttribute<br>方法 or 属性：scrollable(value: boolean): TabsAttribute;<br>起始版本：10|tabs.d.ts|
|起始版本有变化|类名：TabsAttribute<br>方法 or 属性：barMode(value: BarMode): TabsAttribute;<br>起始版本：7|类名：TabsAttribute<br>方法 or 属性：barMode(value: BarMode): TabsAttribute;<br>起始版本：10|tabs.d.ts|
|起始版本有变化|类名：TabsAttribute<br>方法 or 属性：barWidth(value: Length): TabsAttribute;<br>起始版本：8|类名：TabsAttribute<br>方法 or 属性：barWidth(value: Length): TabsAttribute;<br>起始版本：10|tabs.d.ts|
|起始版本有变化|类名：TabsAttribute<br>方法 or 属性：barHeight(value: Length): TabsAttribute;<br>起始版本：8|类名：TabsAttribute<br>方法 or 属性：barHeight(value: Length): TabsAttribute;<br>起始版本：10|tabs.d.ts|
|起始版本有变化|类名：TabsAttribute<br>方法 or 属性：animationDuration(value: number): TabsAttribute;<br>起始版本：7|类名：TabsAttribute<br>方法 or 属性：animationDuration(value: number): TabsAttribute;<br>起始版本：10|tabs.d.ts|
|起始版本有变化|类名：TabsAttribute<br>方法 or 属性：onChange(event: (index: number) => void): TabsAttribute;<br>起始版本：7|类名：TabsAttribute<br>方法 or 属性：onChange(event: (index: number) => void): TabsAttribute;<br>起始版本：10|tabs.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const Tabs: TabsInterface;<br>起始版本：7|类名：global<br>方法 or 属性：declare const Tabs: TabsInterface;<br>起始版本：10|tabs.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const TabsInstance: TabsAttribute;<br>起始版本：7|类名：global<br>方法 or 属性：declare const TabsInstance: TabsAttribute;<br>起始版本：10|tabs.d.ts|
|起始版本有变化|类名：SubTabBarStyle<br>起始版本：9|类名：SubTabBarStyle<br>起始版本：10|tab_content.d.ts|
|起始版本有变化|类名：BottomTabBarStyle<br>起始版本：9|类名：BottomTabBarStyle<br>起始版本：10|tab_content.d.ts|
|起始版本有变化|类名：TabContentInterface<br>起始版本：7|类名：TabContentInterface<br>起始版本：10|tab_content.d.ts|
|起始版本有变化|类名：TabContentInterface<br>方法 or 属性：(): TabContentAttribute;<br>起始版本：7|类名：TabContentInterface<br>方法 or 属性：(): TabContentAttribute;<br>起始版本：10|tab_content.d.ts|
|起始版本有变化|类名：TabContentAttribute<br>起始版本：7|类名：TabContentAttribute<br>起始版本：10|tab_content.d.ts|
|起始版本有变化|类名：TabContentAttribute<br>方法 or 属性：tabBar(value: SubTabBarStyle \| BottomTabBarStyle): TabContentAttribute;<br>起始版本：9|类名：TabContentAttribute<br>方法 or 属性：tabBar(value: SubTabBarStyle \| BottomTabBarStyle): TabContentAttribute;<br>起始版本：10|tab_content.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const TabContent: TabContentInterface;<br>起始版本：7|类名：global<br>方法 or 属性：declare const TabContent: TabContentInterface;<br>起始版本：10|tab_content.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const TabContentInstance: TabContentAttribute;<br>起始版本：7|类名：global<br>方法 or 属性：declare const TabContentInstance: TabContentAttribute;<br>起始版本：10|tab_content.d.ts|
|起始版本有变化|类名：TextAttribute<br>方法 or 属性：copyOption(value: CopyOptions): TextAttribute;<br>起始版本：9|类名：TextAttribute<br>方法 or 属性：copyOption(value: CopyOptions): TextAttribute;<br>起始版本：10|text.d.ts|
|起始版本有变化|类名：TextAreaController<br>起始版本：8|类名：TextAreaController<br>起始版本：10|text_area.d.ts|
|起始版本有变化|类名：TextAreaController<br>方法 or 属性：constructor();<br>起始版本：8|类名：TextAreaController<br>方法 or 属性：constructor();<br>起始版本：10|text_area.d.ts|
|起始版本有变化|类名：TextAreaController<br>方法 or 属性：caretPosition(value: number): void;<br>起始版本：8|类名：TextAreaController<br>方法 or 属性：caretPosition(value: number): void;<br>起始版本：10|text_area.d.ts|
|起始版本有变化|类名：TextAreaOptions<br>起始版本：7|类名：TextAreaOptions<br>起始版本：10|text_area.d.ts|
|起始版本有变化|类名：TextAreaOptions<br>方法 or 属性：placeholder?: ResourceStr;<br>起始版本：7|类名：TextAreaOptions<br>方法 or 属性：placeholder?: ResourceStr;<br>起始版本：10|text_area.d.ts|
|起始版本有变化|类名：TextAreaOptions<br>方法 or 属性：text?: ResourceStr;<br>起始版本：7|类名：TextAreaOptions<br>方法 or 属性：text?: ResourceStr;<br>起始版本：10|text_area.d.ts|
|起始版本有变化|类名：TextAreaOptions<br>方法 or 属性：controller?: TextAreaController;<br>起始版本：8|类名：TextAreaOptions<br>方法 or 属性：controller?: TextAreaController;<br>起始版本：10|text_area.d.ts|
|起始版本有变化|类名：TextAreaInterface<br>起始版本：7|类名：TextAreaInterface<br>起始版本：10|text_area.d.ts|
|起始版本有变化|类名：TextAreaInterface<br>方法 or 属性：(value?: TextAreaOptions): TextAreaAttribute;<br>起始版本：7|类名：TextAreaInterface<br>方法 or 属性：(value?: TextAreaOptions): TextAreaAttribute;<br>起始版本：10|text_area.d.ts|
|起始版本有变化|类名：TextAreaAttribute<br>起始版本：7|类名：TextAreaAttribute<br>起始版本：10|text_area.d.ts|
|起始版本有变化|类名：TextAreaAttribute<br>方法 or 属性：placeholderColor(value: ResourceColor): TextAreaAttribute;<br>起始版本：7|类名：TextAreaAttribute<br>方法 or 属性：placeholderColor(value: ResourceColor): TextAreaAttribute;<br>起始版本：10|text_area.d.ts|
|起始版本有变化|类名：TextAreaAttribute<br>方法 or 属性：placeholderFont(value: Font): TextAreaAttribute;<br>起始版本：7|类名：TextAreaAttribute<br>方法 or 属性：placeholderFont(value: Font): TextAreaAttribute;<br>起始版本：10|text_area.d.ts|
|起始版本有变化|类名：TextAreaAttribute<br>方法 or 属性：textAlign(value: TextAlign): TextAreaAttribute;<br>起始版本：7|类名：TextAreaAttribute<br>方法 or 属性：textAlign(value: TextAlign): TextAreaAttribute;<br>起始版本：10|text_area.d.ts|
|起始版本有变化|类名：TextAreaAttribute<br>方法 or 属性：caretColor(value: ResourceColor): TextAreaAttribute;<br>起始版本：7|类名：TextAreaAttribute<br>方法 or 属性：caretColor(value: ResourceColor): TextAreaAttribute;<br>起始版本：10|text_area.d.ts|
|起始版本有变化|类名：TextAreaAttribute<br>方法 or 属性：fontColor(value: ResourceColor): TextAreaAttribute;<br>起始版本：7|类名：TextAreaAttribute<br>方法 or 属性：fontColor(value: ResourceColor): TextAreaAttribute;<br>起始版本：10|text_area.d.ts|
|起始版本有变化|类名：TextAreaAttribute<br>方法 or 属性：fontSize(value: Length): TextAreaAttribute;<br>起始版本：7|类名：TextAreaAttribute<br>方法 or 属性：fontSize(value: Length): TextAreaAttribute;<br>起始版本：10|text_area.d.ts|
|起始版本有变化|类名：TextAreaAttribute<br>方法 or 属性：fontStyle(value: FontStyle): TextAreaAttribute;<br>起始版本：7|类名：TextAreaAttribute<br>方法 or 属性：fontStyle(value: FontStyle): TextAreaAttribute;<br>起始版本：10|text_area.d.ts|
|起始版本有变化|类名：TextAreaAttribute<br>方法 or 属性：fontWeight(value: number \| FontWeight \| string): TextAreaAttribute;<br>起始版本：7|类名：TextAreaAttribute<br>方法 or 属性：fontWeight(value: number \| FontWeight \| string): TextAreaAttribute;<br>起始版本：10|text_area.d.ts|
|起始版本有变化|类名：TextAreaAttribute<br>方法 or 属性：fontFamily(value: ResourceStr): TextAreaAttribute;<br>起始版本：7|类名：TextAreaAttribute<br>方法 or 属性：fontFamily(value: ResourceStr): TextAreaAttribute;<br>起始版本：10|text_area.d.ts|
|起始版本有变化|类名：TextAreaAttribute<br>方法 or 属性：inputFilter(value: ResourceStr, error?: (value: string) => void): TextAreaAttribute;<br>起始版本：8|类名：TextAreaAttribute<br>方法 or 属性：inputFilter(value: ResourceStr, error?: (value: string) => void): TextAreaAttribute;<br>起始版本：10|text_area.d.ts|
|起始版本有变化|类名：TextAreaAttribute<br>方法 or 属性：onChange(callback: (value: string) => void): TextAreaAttribute;<br>起始版本：7|类名：TextAreaAttribute<br>方法 or 属性：onChange(callback: (value: string) => void): TextAreaAttribute;<br>起始版本：10|text_area.d.ts|
|起始版本有变化|类名：TextAreaAttribute<br>方法 or 属性：onCopy(callback: (value: string) => void): TextAreaAttribute;<br>起始版本：7|类名：TextAreaAttribute<br>方法 or 属性：onCopy(callback: (value: string) => void): TextAreaAttribute;<br>起始版本：10|text_area.d.ts|
|起始版本有变化|类名：TextAreaAttribute<br>方法 or 属性：onCut(callback: (value: string) => void): TextAreaAttribute;<br>起始版本：7|类名：TextAreaAttribute<br>方法 or 属性：onCut(callback: (value: string) => void): TextAreaAttribute;<br>起始版本：10|text_area.d.ts|
|起始版本有变化|类名：TextAreaAttribute<br>方法 or 属性：onPaste(callback: (value: string) => void): TextAreaAttribute;<br>起始版本：7|类名：TextAreaAttribute<br>方法 or 属性：onPaste(callback: (value: string) => void): TextAreaAttribute;<br>起始版本：10|text_area.d.ts|
|起始版本有变化|类名：TextAreaAttribute<br>方法 or 属性：copyOption(value: CopyOptions): TextAreaAttribute;<br>起始版本：9|类名：TextAreaAttribute<br>方法 or 属性：copyOption(value: CopyOptions): TextAreaAttribute;<br>起始版本：10|text_area.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const TextArea: TextAreaInterface;<br>起始版本：7|类名：global<br>方法 or 属性：declare const TextArea: TextAreaInterface;<br>起始版本：10|text_area.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const TextAreaInstance: TextAreaAttribute;<br>起始版本：7|类名：global<br>方法 or 属性：declare const TextAreaInstance: TextAreaAttribute;<br>起始版本：10|text_area.d.ts|
|起始版本有变化|类名：TextClockController<br>起始版本：8|类名：TextClockController<br>起始版本：10|text_clock.d.ts|
|起始版本有变化|类名：TextClockController<br>方法 or 属性：constructor();<br>起始版本：8|类名：TextClockController<br>方法 or 属性：constructor();<br>起始版本：10|text_clock.d.ts|
|起始版本有变化|类名：TextClockController<br>方法 or 属性：start();<br>起始版本：8|类名：TextClockController<br>方法 or 属性：start();<br>起始版本：10|text_clock.d.ts|
|起始版本有变化|类名：TextClockController<br>方法 or 属性：stop();<br>起始版本：8|类名：TextClockController<br>方法 or 属性：stop();<br>起始版本：10|text_clock.d.ts|
|起始版本有变化|类名：TextClockInterface<br>起始版本：8|类名：TextClockInterface<br>起始版本：10|text_clock.d.ts|
|起始版本有变化|类名：TextClockInterface<br>方法 or 属性：(options?: { timeZoneOffset?: number; controller?: TextClockController }): TextClockAttribute;<br>起始版本：8|类名：TextClockInterface<br>方法 or 属性：(options?: { timeZoneOffset?: number; controller?: TextClockController }): TextClockAttribute;<br>起始版本：10|text_clock.d.ts|
|起始版本有变化|类名：TextClockAttribute<br>方法 or 属性：format(value: string): TextClockAttribute;<br>起始版本：8|类名：TextClockAttribute<br>方法 or 属性：format(value: string): TextClockAttribute;<br>起始版本：10|text_clock.d.ts|
|起始版本有变化|类名：TextClockAttribute<br>方法 or 属性：onDateChange(event: (value: number) => void): TextClockAttribute;<br>起始版本：8|类名：TextClockAttribute<br>方法 or 属性：onDateChange(event: (value: number) => void): TextClockAttribute;<br>起始版本：10|text_clock.d.ts|
|起始版本有变化|类名：TextClockAttribute<br>方法 or 属性：fontColor(value: ResourceColor): TextClockAttribute;<br>起始版本：8|类名：TextClockAttribute<br>方法 or 属性：fontColor(value: ResourceColor): TextClockAttribute;<br>起始版本：10|text_clock.d.ts|
|起始版本有变化|类名：TextClockAttribute<br>方法 or 属性：fontSize(value: Length): TextClockAttribute;<br>起始版本：8|类名：TextClockAttribute<br>方法 or 属性：fontSize(value: Length): TextClockAttribute;<br>起始版本：10|text_clock.d.ts|
|起始版本有变化|类名：TextClockAttribute<br>方法 or 属性：fontStyle(value: FontStyle): TextClockAttribute;<br>起始版本：8|类名：TextClockAttribute<br>方法 or 属性：fontStyle(value: FontStyle): TextClockAttribute;<br>起始版本：10|text_clock.d.ts|
|起始版本有变化|类名：TextClockAttribute<br>方法 or 属性：fontWeight(value: number \| FontWeight \| string): TextClockAttribute;<br>起始版本：8|类名：TextClockAttribute<br>方法 or 属性：fontWeight(value: number \| FontWeight \| string): TextClockAttribute;<br>起始版本：10|text_clock.d.ts|
|起始版本有变化|类名：TextClockAttribute<br>方法 or 属性：fontFamily(value: ResourceStr): TextClockAttribute;<br>起始版本：8|类名：TextClockAttribute<br>方法 or 属性：fontFamily(value: ResourceStr): TextClockAttribute;<br>起始版本：10|text_clock.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const TextClock: TextClockInterface;<br>起始版本：8|类名：global<br>方法 or 属性：declare const TextClock: TextClockInterface;<br>起始版本：10|text_clock.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const TextClockInstance: TextClockAttribute;<br>起始版本：8|类名：global<br>方法 or 属性：declare const TextClockInstance: TextClockAttribute;<br>起始版本：10|text_clock.d.ts|
|起始版本有变化|类名：InputType<br>起始版本：7|类名：InputType<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：InputType<br>方法 or 属性：Normal<br>起始版本：7|类名：InputType<br>方法 or 属性：Normal<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：InputType<br>方法 or 属性：Number<br>起始版本：7|类名：InputType<br>方法 or 属性：Number<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：InputType<br>方法 or 属性：PhoneNumber<br>起始版本：9|类名：InputType<br>方法 or 属性：PhoneNumber<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：InputType<br>方法 or 属性：Email<br>起始版本：7|类名：InputType<br>方法 or 属性：Email<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：InputType<br>方法 or 属性：Password<br>起始版本：7|类名：InputType<br>方法 or 属性：Password<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：EnterKeyType<br>起始版本：7|类名：EnterKeyType<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：EnterKeyType<br>方法 or 属性：Go<br>起始版本：7|类名：EnterKeyType<br>方法 or 属性：Go<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：EnterKeyType<br>方法 or 属性：Search<br>起始版本：7|类名：EnterKeyType<br>方法 or 属性：Search<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：EnterKeyType<br>方法 or 属性：Send<br>起始版本：7|类名：EnterKeyType<br>方法 or 属性：Send<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：EnterKeyType<br>方法 or 属性：Next<br>起始版本：7|类名：EnterKeyType<br>方法 or 属性：Next<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：EnterKeyType<br>方法 or 属性：Done<br>起始版本：7|类名：EnterKeyType<br>方法 or 属性：Done<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：TextInputController<br>起始版本：8|类名：TextInputController<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：TextInputController<br>方法 or 属性：constructor();<br>起始版本：8|类名：TextInputController<br>方法 or 属性：constructor();<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：TextInputController<br>方法 or 属性：caretPosition(value: number): void;<br>起始版本：8|类名：TextInputController<br>方法 or 属性：caretPosition(value: number): void;<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：TextInputOptions<br>起始版本：7|类名：TextInputOptions<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：TextInputOptions<br>方法 or 属性：placeholder?: ResourceStr;<br>起始版本：7|类名：TextInputOptions<br>方法 or 属性：placeholder?: ResourceStr;<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：TextInputOptions<br>方法 or 属性：text?: ResourceStr;<br>起始版本：7|类名：TextInputOptions<br>方法 or 属性：text?: ResourceStr;<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：TextInputOptions<br>方法 or 属性：controller?: TextInputController;<br>起始版本：8|类名：TextInputOptions<br>方法 or 属性：controller?: TextInputController;<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：TextInputStyle<br>起始版本：9|类名：TextInputStyle<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：TextInputStyle<br>方法 or 属性：Default<br>起始版本：9|类名：TextInputStyle<br>方法 or 属性：Default<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：TextInputStyle<br>方法 or 属性：Inline<br>起始版本：9|类名：TextInputStyle<br>方法 or 属性：Inline<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：TextInputInterface<br>起始版本：7|类名：TextInputInterface<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：TextInputInterface<br>方法 or 属性：(value?: TextInputOptions): TextInputAttribute;<br>起始版本：7|类名：TextInputInterface<br>方法 or 属性：(value?: TextInputOptions): TextInputAttribute;<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：TextInputAttribute<br>起始版本：7|类名：TextInputAttribute<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：TextInputAttribute<br>方法 or 属性：type(value: InputType): TextInputAttribute;<br>起始版本：7|类名：TextInputAttribute<br>方法 or 属性：type(value: InputType): TextInputAttribute;<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：TextInputAttribute<br>方法 or 属性：placeholderColor(value: ResourceColor): TextInputAttribute;<br>起始版本：7|类名：TextInputAttribute<br>方法 or 属性：placeholderColor(value: ResourceColor): TextInputAttribute;<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：TextInputAttribute<br>方法 or 属性：placeholderFont(value?: Font): TextInputAttribute;<br>起始版本：7|类名：TextInputAttribute<br>方法 or 属性：placeholderFont(value?: Font): TextInputAttribute;<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：TextInputAttribute<br>方法 or 属性：enterKeyType(value: EnterKeyType): TextInputAttribute;<br>起始版本：7|类名：TextInputAttribute<br>方法 or 属性：enterKeyType(value: EnterKeyType): TextInputAttribute;<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：TextInputAttribute<br>方法 or 属性：caretColor(value: ResourceColor): TextInputAttribute;<br>起始版本：7|类名：TextInputAttribute<br>方法 or 属性：caretColor(value: ResourceColor): TextInputAttribute;<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：TextInputAttribute<br>方法 or 属性：onEditChange(callback: (isEditing: boolean) => void): TextInputAttribute;<br>起始版本：8|类名：TextInputAttribute<br>方法 or 属性：onEditChange(callback: (isEditing: boolean) => void): TextInputAttribute;<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：TextInputAttribute<br>方法 or 属性：onSubmit(callback: (enterKey: EnterKeyType) => void): TextInputAttribute;<br>起始版本：7|类名：TextInputAttribute<br>方法 or 属性：onSubmit(callback: (enterKey: EnterKeyType) => void): TextInputAttribute;<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：TextInputAttribute<br>方法 or 属性：onChange(callback: (value: string) => void): TextInputAttribute;<br>起始版本：7|类名：TextInputAttribute<br>方法 or 属性：onChange(callback: (value: string) => void): TextInputAttribute;<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：TextInputAttribute<br>方法 or 属性：maxLength(value: number): TextInputAttribute;<br>起始版本：7|类名：TextInputAttribute<br>方法 or 属性：maxLength(value: number): TextInputAttribute;<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：TextInputAttribute<br>方法 or 属性：fontColor(value: ResourceColor): TextInputAttribute;<br>起始版本：7|类名：TextInputAttribute<br>方法 or 属性：fontColor(value: ResourceColor): TextInputAttribute;<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：TextInputAttribute<br>方法 or 属性：fontSize(value: Length): TextInputAttribute;<br>起始版本：7|类名：TextInputAttribute<br>方法 or 属性：fontSize(value: Length): TextInputAttribute;<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：TextInputAttribute<br>方法 or 属性：fontStyle(value: FontStyle): TextInputAttribute;<br>起始版本：7|类名：TextInputAttribute<br>方法 or 属性：fontStyle(value: FontStyle): TextInputAttribute;<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：TextInputAttribute<br>方法 or 属性：fontWeight(value: number \| FontWeight \| string): TextInputAttribute;<br>起始版本：7|类名：TextInputAttribute<br>方法 or 属性：fontWeight(value: number \| FontWeight \| string): TextInputAttribute;<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：TextInputAttribute<br>方法 or 属性：fontFamily(value: ResourceStr): TextInputAttribute;<br>起始版本：7|类名：TextInputAttribute<br>方法 or 属性：fontFamily(value: ResourceStr): TextInputAttribute;<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：TextInputAttribute<br>方法 or 属性：inputFilter(value: ResourceStr, error?: (value: string) => void): TextInputAttribute;<br>起始版本：8|类名：TextInputAttribute<br>方法 or 属性：inputFilter(value: ResourceStr, error?: (value: string) => void): TextInputAttribute;<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：TextInputAttribute<br>方法 or 属性：onCopy(callback: (value: string) => void): TextInputAttribute;<br>起始版本：8|类名：TextInputAttribute<br>方法 or 属性：onCopy(callback: (value: string) => void): TextInputAttribute;<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：TextInputAttribute<br>方法 or 属性：onCut(callback: (value: string) => void): TextInputAttribute;<br>起始版本：8|类名：TextInputAttribute<br>方法 or 属性：onCut(callback: (value: string) => void): TextInputAttribute;<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：TextInputAttribute<br>方法 or 属性：onPaste(callback: (value: string) => void): TextInputAttribute;<br>起始版本：8|类名：TextInputAttribute<br>方法 or 属性：onPaste(callback: (value: string) => void): TextInputAttribute;<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：TextInputAttribute<br>方法 or 属性：copyOption(value: CopyOptions): TextInputAttribute;<br>起始版本：9|类名：TextInputAttribute<br>方法 or 属性：copyOption(value: CopyOptions): TextInputAttribute;<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：TextInputAttribute<br>方法 or 属性：showPasswordIcon(value: boolean): TextInputAttribute;<br>起始版本：9|类名：TextInputAttribute<br>方法 or 属性：showPasswordIcon(value: boolean): TextInputAttribute;<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：TextInputAttribute<br>方法 or 属性：textAlign(value: TextAlign): TextInputAttribute;<br>起始版本：9|类名：TextInputAttribute<br>方法 or 属性：textAlign(value: TextAlign): TextInputAttribute;<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：TextInputAttribute<br>方法 or 属性：style(value: TextInputStyle): TextInputAttribute;<br>起始版本：9|类名：TextInputAttribute<br>方法 or 属性：style(value: TextInputStyle): TextInputAttribute;<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const TextInput: TextInputInterface;<br>起始版本：7|类名：global<br>方法 or 属性：declare const TextInput: TextInputInterface;<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const TextInputInstance: TextInputAttribute;<br>起始版本：7|类名：global<br>方法 or 属性：declare const TextInputInstance: TextInputAttribute;<br>起始版本：10|text_input.d.ts|
|起始版本有变化|类名：TextPickerOptions<br>起始版本：8|类名：TextPickerOptions<br>起始版本：10|text_picker.d.ts|
|起始版本有变化|类名：TextPickerOptions<br>方法 or 属性：value?: string;<br>起始版本：N/A|类名：TextPickerOptions<br>方法 or 属性：value?: string;<br>起始版本：10|text_picker.d.ts|
|起始版本有变化|类名：TextPickerOptions<br>方法 or 属性：selected?: number;<br>起始版本：N/A|类名：TextPickerOptions<br>方法 or 属性：selected?: number;<br>起始版本：10|text_picker.d.ts|
|起始版本有变化|类名：TextPickerInterface<br>起始版本：8|类名：TextPickerInterface<br>起始版本：10|text_picker.d.ts|
|起始版本有变化|类名：TextPickerInterface<br>方法 or 属性：(options?: TextPickerOptions): TextPickerAttribute;<br>起始版本：8|类名：TextPickerInterface<br>方法 or 属性：(options?: TextPickerOptions): TextPickerAttribute;<br>起始版本：10|text_picker.d.ts|
|起始版本有变化|类名：TextPickerAttribute<br>起始版本：8|类名：TextPickerAttribute<br>起始版本：10|text_picker.d.ts|
|起始版本有变化|类名：TextPickerAttribute<br>方法 or 属性：defaultPickerItemHeight(value: number \| string): TextPickerAttribute;<br>起始版本：8|类名：TextPickerAttribute<br>方法 or 属性：defaultPickerItemHeight(value: number \| string): TextPickerAttribute;<br>起始版本：10|text_picker.d.ts|
|起始版本有变化|类名：TextPickerAttribute<br>方法 or 属性：onChange(callback: (value: string, index: number) => void): TextPickerAttribute;<br>起始版本：8|类名：TextPickerAttribute<br>方法 or 属性：onChange(callback: (value: string, index: number) => void): TextPickerAttribute;<br>起始版本：10|text_picker.d.ts|
|起始版本有变化|类名：TextPickerResult<br>起始版本：8|类名：TextPickerResult<br>起始版本：10|text_picker.d.ts|
|起始版本有变化|类名：TextPickerResult<br>方法 or 属性：value: string;<br>起始版本：8|类名：TextPickerResult<br>方法 or 属性：value: string;<br>起始版本：10|text_picker.d.ts|
|起始版本有变化|类名：TextPickerResult<br>方法 or 属性：index: number;<br>起始版本：8|类名：TextPickerResult<br>方法 or 属性：index: number;<br>起始版本：10|text_picker.d.ts|
|起始版本有变化|类名：TextPickerDialogOptions<br>起始版本：8|类名：TextPickerDialogOptions<br>起始版本：10|text_picker.d.ts|
|起始版本有变化|类名：TextPickerDialogOptions<br>方法 or 属性：defaultPickerItemHeight?: number \| string;<br>起始版本：8|类名：TextPickerDialogOptions<br>方法 or 属性：defaultPickerItemHeight?: number \| string;<br>起始版本：10|text_picker.d.ts|
|起始版本有变化|类名：TextPickerDialogOptions<br>方法 or 属性：onAccept?: (value: TextPickerResult) => void;<br>起始版本：8|类名：TextPickerDialogOptions<br>方法 or 属性：onAccept?: (value: TextPickerResult) => void;<br>起始版本：10|text_picker.d.ts|
|起始版本有变化|类名：TextPickerDialogOptions<br>方法 or 属性：onCancel?: () => void;<br>起始版本：8|类名：TextPickerDialogOptions<br>方法 or 属性：onCancel?: () => void;<br>起始版本：10|text_picker.d.ts|
|起始版本有变化|类名：TextPickerDialogOptions<br>方法 or 属性：onChange?: (value: TextPickerResult) => void;<br>起始版本：8|类名：TextPickerDialogOptions<br>方法 or 属性：onChange?: (value: TextPickerResult) => void;<br>起始版本：10|text_picker.d.ts|
|起始版本有变化|类名：TextPickerDialog<br>起始版本：8|类名：TextPickerDialog<br>起始版本：10|text_picker.d.ts|
|起始版本有变化|类名：TextPickerDialog<br>方法 or 属性：static show(options?: TextPickerDialogOptions);<br>起始版本：8|类名：TextPickerDialog<br>方法 or 属性：static show(options?: TextPickerDialogOptions);<br>起始版本：10|text_picker.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const TextPicker: TextPickerInterface;<br>起始版本：8|类名：global<br>方法 or 属性：declare const TextPicker: TextPickerInterface;<br>起始版本：10|text_picker.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const TextPickerInstance: TextPickerAttribute;<br>起始版本：8|类名：global<br>方法 or 属性：declare const TextPickerInstance: TextPickerAttribute;<br>起始版本：10|text_picker.d.ts|
|起始版本有变化|类名：TextTimerController<br>起始版本：8|类名：TextTimerController<br>起始版本：10|text_timer.d.ts|
|起始版本有变化|类名：TextTimerController<br>方法 or 属性：constructor();<br>起始版本：8|类名：TextTimerController<br>方法 or 属性：constructor();<br>起始版本：10|text_timer.d.ts|
|起始版本有变化|类名：TextTimerController<br>方法 or 属性：start();<br>起始版本：8|类名：TextTimerController<br>方法 or 属性：start();<br>起始版本：10|text_timer.d.ts|
|起始版本有变化|类名：TextTimerController<br>方法 or 属性：pause();<br>起始版本：8|类名：TextTimerController<br>方法 or 属性：pause();<br>起始版本：10|text_timer.d.ts|
|起始版本有变化|类名：TextTimerController<br>方法 or 属性：reset();<br>起始版本：8|类名：TextTimerController<br>方法 or 属性：reset();<br>起始版本：10|text_timer.d.ts|
|起始版本有变化|类名：TextTimerOptions<br>起始版本：8|类名：TextTimerOptions<br>起始版本：10|text_timer.d.ts|
|起始版本有变化|类名：TextTimerOptions<br>方法 or 属性：isCountDown?: boolean;<br>起始版本：8|类名：TextTimerOptions<br>方法 or 属性：isCountDown?: boolean;<br>起始版本：10|text_timer.d.ts|
|起始版本有变化|类名：TextTimerOptions<br>方法 or 属性：count?: number;<br>起始版本：8|类名：TextTimerOptions<br>方法 or 属性：count?: number;<br>起始版本：10|text_timer.d.ts|
|起始版本有变化|类名：TextTimerOptions<br>方法 or 属性：controller?: TextTimerController;<br>起始版本：8|类名：TextTimerOptions<br>方法 or 属性：controller?: TextTimerController;<br>起始版本：10|text_timer.d.ts|
|起始版本有变化|类名：TextTimerInterface<br>起始版本：8|类名：TextTimerInterface<br>起始版本：10|text_timer.d.ts|
|起始版本有变化|类名：TextTimerInterface<br>方法 or 属性：(options?: TextTimerOptions): TextTimerAttribute;<br>起始版本：8|类名：TextTimerInterface<br>方法 or 属性：(options?: TextTimerOptions): TextTimerAttribute;<br>起始版本：10|text_timer.d.ts|
|起始版本有变化|类名：TextTimerAttribute<br>起始版本：8|类名：TextTimerAttribute<br>起始版本：10|text_timer.d.ts|
|起始版本有变化|类名：TextTimerAttribute<br>方法 or 属性：format(value: string): TextTimerAttribute;<br>起始版本：8|类名：TextTimerAttribute<br>方法 or 属性：format(value: string): TextTimerAttribute;<br>起始版本：10|text_timer.d.ts|
|起始版本有变化|类名：TextTimerAttribute<br>方法 or 属性：fontColor(value: ResourceColor): TextTimerAttribute;<br>起始版本：8|类名：TextTimerAttribute<br>方法 or 属性：fontColor(value: ResourceColor): TextTimerAttribute;<br>起始版本：10|text_timer.d.ts|
|起始版本有变化|类名：TextTimerAttribute<br>方法 or 属性：fontSize(value: Length): TextTimerAttribute;<br>起始版本：8|类名：TextTimerAttribute<br>方法 or 属性：fontSize(value: Length): TextTimerAttribute;<br>起始版本：10|text_timer.d.ts|
|起始版本有变化|类名：TextTimerAttribute<br>方法 or 属性：fontStyle(value: FontStyle): TextTimerAttribute;<br>起始版本：8|类名：TextTimerAttribute<br>方法 or 属性：fontStyle(value: FontStyle): TextTimerAttribute;<br>起始版本：10|text_timer.d.ts|
|起始版本有变化|类名：TextTimerAttribute<br>方法 or 属性：fontWeight(value: number \| FontWeight \| string): TextTimerAttribute;<br>起始版本：8|类名：TextTimerAttribute<br>方法 or 属性：fontWeight(value: number \| FontWeight \| string): TextTimerAttribute;<br>起始版本：10|text_timer.d.ts|
|起始版本有变化|类名：TextTimerAttribute<br>方法 or 属性：fontFamily(value: ResourceStr): TextTimerAttribute;<br>起始版本：8|类名：TextTimerAttribute<br>方法 or 属性：fontFamily(value: ResourceStr): TextTimerAttribute;<br>起始版本：10|text_timer.d.ts|
|起始版本有变化|类名：TextTimerAttribute<br>方法 or 属性：onTimer(event: (utc: number, elapsedTime: number) => void): TextTimerAttribute;<br>起始版本：8|类名：TextTimerAttribute<br>方法 or 属性：onTimer(event: (utc: number, elapsedTime: number) => void): TextTimerAttribute;<br>起始版本：10|text_timer.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const TextTimer: TextTimerInterface;<br>起始版本：8|类名：global<br>方法 or 属性：declare const TextTimer: TextTimerInterface;<br>起始版本：10|text_timer.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const TextTimerInstance: TextTimerAttribute;<br>起始版本：8|类名：global<br>方法 or 属性：declare const TextTimerInstance: TextTimerAttribute;<br>起始版本：10|text_timer.d.ts|
|起始版本有变化|类名：TimePickerResult<br>起始版本：8|类名：TimePickerResult<br>起始版本：10|time_picker.d.ts|
|起始版本有变化|类名：TimePickerResult<br>方法 or 属性：hour?: number;<br>起始版本：8|类名：TimePickerResult<br>方法 or 属性：hour?: number;<br>起始版本：10|time_picker.d.ts|
|起始版本有变化|类名：TimePickerResult<br>方法 or 属性：minute?: number;<br>起始版本：8|类名：TimePickerResult<br>方法 or 属性：minute?: number;<br>起始版本：10|time_picker.d.ts|
|起始版本有变化|类名：TimePickerOptions<br>起始版本：8|类名：TimePickerOptions<br>起始版本：10|time_picker.d.ts|
|起始版本有变化|类名：TimePickerOptions<br>方法 or 属性：selected?: Date;<br>起始版本：N/A|类名：TimePickerOptions<br>方法 or 属性：selected?: Date;<br>起始版本：10|time_picker.d.ts|
|起始版本有变化|类名：TimePickerInterface<br>起始版本：8|类名：TimePickerInterface<br>起始版本：10|time_picker.d.ts|
|起始版本有变化|类名：TimePickerInterface<br>方法 or 属性：(options?: TimePickerOptions): TimePickerAttribute;<br>起始版本：8|类名：TimePickerInterface<br>方法 or 属性：(options?: TimePickerOptions): TimePickerAttribute;<br>起始版本：10|time_picker.d.ts|
|起始版本有变化|类名：TimePickerAttribute<br>起始版本：8|类名：TimePickerAttribute<br>起始版本：10|time_picker.d.ts|
|起始版本有变化|类名：TimePickerAttribute<br>方法 or 属性：useMilitaryTime(value: boolean): TimePickerAttribute;<br>起始版本：8|类名：TimePickerAttribute<br>方法 or 属性：useMilitaryTime(value: boolean): TimePickerAttribute;<br>起始版本：10|time_picker.d.ts|
|起始版本有变化|类名：TimePickerAttribute<br>方法 or 属性：onChange(callback: (value: TimePickerResult) => void): TimePickerAttribute;<br>起始版本：8|类名：TimePickerAttribute<br>方法 or 属性：onChange(callback: (value: TimePickerResult) => void): TimePickerAttribute;<br>起始版本：10|time_picker.d.ts|
|起始版本有变化|类名：TimePickerDialogOptions<br>起始版本：8|类名：TimePickerDialogOptions<br>起始版本：10|time_picker.d.ts|
|起始版本有变化|类名：TimePickerDialogOptions<br>方法 or 属性：useMilitaryTime?: boolean;<br>起始版本：8|类名：TimePickerDialogOptions<br>方法 or 属性：useMilitaryTime?: boolean;<br>起始版本：10|time_picker.d.ts|
|起始版本有变化|类名：TimePickerDialogOptions<br>方法 or 属性：onAccept?: (value: TimePickerResult) => void;<br>起始版本：8|类名：TimePickerDialogOptions<br>方法 or 属性：onAccept?: (value: TimePickerResult) => void;<br>起始版本：10|time_picker.d.ts|
|起始版本有变化|类名：TimePickerDialogOptions<br>方法 or 属性：onCancel?: () => void;<br>起始版本：8|类名：TimePickerDialogOptions<br>方法 or 属性：onCancel?: () => void;<br>起始版本：10|time_picker.d.ts|
|起始版本有变化|类名：TimePickerDialogOptions<br>方法 or 属性：onChange?: (value: TimePickerResult) => void;<br>起始版本：8|类名：TimePickerDialogOptions<br>方法 or 属性：onChange?: (value: TimePickerResult) => void;<br>起始版本：10|time_picker.d.ts|
|起始版本有变化|类名：TimePickerDialog<br>起始版本：8|类名：TimePickerDialog<br>起始版本：10|time_picker.d.ts|
|起始版本有变化|类名：TimePickerDialog<br>方法 or 属性：static show(options?: TimePickerDialogOptions);<br>起始版本：8|类名：TimePickerDialog<br>方法 or 属性：static show(options?: TimePickerDialogOptions);<br>起始版本：10|time_picker.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const TimePicker: TimePickerInterface;<br>起始版本：8|类名：global<br>方法 or 属性：declare const TimePicker: TimePickerInterface;<br>起始版本：10|time_picker.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const TimePickerInstance: TimePickerAttribute;<br>起始版本：8|类名：global<br>方法 or 属性：declare const TimePickerInstance: TimePickerAttribute;<br>起始版本：10|time_picker.d.ts|
|起始版本有变化|类名：Resource<br>方法 or 属性：readonly bundleName: string;<br>起始版本：9|类名：Resource<br>方法 or 属性：readonly bundleName: string;<br>起始版本：10|units.d.ts|
|起始版本有变化|类名：Resource<br>方法 or 属性：readonly moduleName: string;<br>起始版本：9|类名：Resource<br>方法 or 属性：readonly moduleName: string;<br>起始版本：10|units.d.ts|
|起始版本有变化|类名：Font<br>起始版本：7|类名：Font<br>起始版本：10|units.d.ts|
|起始版本有变化|类名：Font<br>方法 or 属性：size?: Length;<br>起始版本：N/A|类名：Font<br>方法 or 属性：size?: Length;<br>起始版本：10|units.d.ts|
|起始版本有变化|类名：Font<br>方法 or 属性：weight?: FontWeight \| number \| string;<br>起始版本：N/A|类名：Font<br>方法 or 属性：weight?: FontWeight \| number \| string;<br>起始版本：10|units.d.ts|
|起始版本有变化|类名：Font<br>方法 or 属性：family?: string \| Resource;<br>起始版本：N/A|类名：Font<br>方法 or 属性：family?: string \| Resource;<br>起始版本：10|units.d.ts|
|起始版本有变化|类名：Font<br>方法 or 属性：style?: FontStyle;<br>起始版本：N/A|类名：Font<br>方法 or 属性：style?: FontStyle;<br>起始版本：10|units.d.ts|
|起始版本有变化|类名：ColorFilter<br>起始版本：9|类名：ColorFilter<br>起始版本：10|units.d.ts|
|起始版本有变化|类名：ColorFilter<br>方法 or 属性：constructor(value: number[]);<br>起始版本：9|类名：ColorFilter<br>方法 or 属性：constructor(value: number[]);<br>起始版本：10|units.d.ts|
|起始版本有变化|类名：SeekMode<br>起始版本：8|类名：SeekMode<br>起始版本：10|video.d.ts|
|起始版本有变化|类名：SeekMode<br>方法 or 属性：PreviousKeyframe<br>起始版本：8|类名：SeekMode<br>方法 or 属性：PreviousKeyframe<br>起始版本：10|video.d.ts|
|起始版本有变化|类名：SeekMode<br>方法 or 属性：NextKeyframe<br>起始版本：8|类名：SeekMode<br>方法 or 属性：NextKeyframe<br>起始版本：10|video.d.ts|
|起始版本有变化|类名：SeekMode<br>方法 or 属性：ClosestKeyframe<br>起始版本：8|类名：SeekMode<br>方法 or 属性：ClosestKeyframe<br>起始版本：10|video.d.ts|
|起始版本有变化|类名：SeekMode<br>方法 or 属性：Accurate<br>起始版本：8|类名：SeekMode<br>方法 or 属性：Accurate<br>起始版本：10|video.d.ts|
|起始版本有变化|类名：PlaybackSpeed<br>起始版本：8|类名：PlaybackSpeed<br>起始版本：10|video.d.ts|
|起始版本有变化|类名：PlaybackSpeed<br>方法 or 属性：Speed_Forward_0_75_X<br>起始版本：8|类名：PlaybackSpeed<br>方法 or 属性：Speed_Forward_0_75_X<br>起始版本：10|video.d.ts|
|起始版本有变化|类名：PlaybackSpeed<br>方法 or 属性：Speed_Forward_1_00_X<br>起始版本：8|类名：PlaybackSpeed<br>方法 or 属性：Speed_Forward_1_00_X<br>起始版本：10|video.d.ts|
|起始版本有变化|类名：PlaybackSpeed<br>方法 or 属性：Speed_Forward_1_25_X<br>起始版本：8|类名：PlaybackSpeed<br>方法 or 属性：Speed_Forward_1_25_X<br>起始版本：10|video.d.ts|
|起始版本有变化|类名：PlaybackSpeed<br>方法 or 属性：Speed_Forward_1_75_X<br>起始版本：8|类名：PlaybackSpeed<br>方法 or 属性：Speed_Forward_1_75_X<br>起始版本：10|video.d.ts|
|起始版本有变化|类名：PlaybackSpeed<br>方法 or 属性：Speed_Forward_2_00_X<br>起始版本：8|类名：PlaybackSpeed<br>方法 or 属性：Speed_Forward_2_00_X<br>起始版本：10|video.d.ts|
|起始版本有变化|类名：VideoOptions<br>起始版本：7|类名：VideoOptions<br>起始版本：10|video.d.ts|
|起始版本有变化|类名：VideoOptions<br>方法 or 属性：src?: string \| Resource;<br>起始版本：7|类名：VideoOptions<br>方法 or 属性：src?: string \| Resource;<br>起始版本：10|video.d.ts|
|起始版本有变化|类名：VideoOptions<br>方法 or 属性：currentProgressRate?: number \| string \| PlaybackSpeed;<br>起始版本：7|类名：VideoOptions<br>方法 or 属性：currentProgressRate?: number \| string \| PlaybackSpeed;<br>起始版本：10|video.d.ts|
|起始版本有变化|类名：VideoOptions<br>方法 or 属性：previewUri?: string \| PixelMap \| Resource;<br>起始版本：7|类名：VideoOptions<br>方法 or 属性：previewUri?: string \| PixelMap \| Resource;<br>起始版本：10|video.d.ts|
|起始版本有变化|类名：VideoOptions<br>方法 or 属性：controller?: VideoController;<br>起始版本：7|类名：VideoOptions<br>方法 or 属性：controller?: VideoController;<br>起始版本：10|video.d.ts|
|起始版本有变化|类名：VideoController<br>起始版本：7|类名：VideoController<br>起始版本：10|video.d.ts|
|起始版本有变化|类名：VideoController<br>方法 or 属性：constructor();<br>起始版本：7|类名：VideoController<br>方法 or 属性：constructor();<br>起始版本：10|video.d.ts|
|起始版本有变化|类名：VideoController<br>方法 or 属性：start();<br>起始版本：7|类名：VideoController<br>方法 or 属性：start();<br>起始版本：10|video.d.ts|
|起始版本有变化|类名：VideoController<br>方法 or 属性：pause();<br>起始版本：7|类名：VideoController<br>方法 or 属性：pause();<br>起始版本：10|video.d.ts|
|起始版本有变化|类名：VideoController<br>方法 or 属性：stop();<br>起始版本：7|类名：VideoController<br>方法 or 属性：stop();<br>起始版本：10|video.d.ts|
|起始版本有变化|类名：VideoController<br>方法 or 属性：setCurrentTime(value: number);<br>起始版本：7|类名：VideoController<br>方法 or 属性：setCurrentTime(value: number);<br>起始版本：10|video.d.ts|
|起始版本有变化|类名：VideoController<br>方法 or 属性：requestFullscreen(value: boolean);<br>起始版本：7|类名：VideoController<br>方法 or 属性：requestFullscreen(value: boolean);<br>起始版本：10|video.d.ts|
|起始版本有变化|类名：VideoController<br>方法 or 属性：exitFullscreen();<br>起始版本：7|类名：VideoController<br>方法 or 属性：exitFullscreen();<br>起始版本：10|video.d.ts|
|起始版本有变化|类名：VideoController<br>方法 or 属性：setCurrentTime(value: number, seekMode: SeekMode);<br>起始版本：8|类名：VideoController<br>方法 or 属性：setCurrentTime(value: number, seekMode: SeekMode);<br>起始版本：10|video.d.ts|
|起始版本有变化|类名：VideoInterface<br>起始版本：7|类名：VideoInterface<br>起始版本：10|video.d.ts|
|起始版本有变化|类名：VideoInterface<br>方法 or 属性：(value: VideoOptions): VideoAttribute;<br>起始版本：7|类名：VideoInterface<br>方法 or 属性：(value: VideoOptions): VideoAttribute;<br>起始版本：10|video.d.ts|
|起始版本有变化|类名：VideoAttribute<br>起始版本：7|类名：VideoAttribute<br>起始版本：10|video.d.ts|
|起始版本有变化|类名：VideoAttribute<br>方法 or 属性：muted(value: boolean): VideoAttribute;<br>起始版本：7|类名：VideoAttribute<br>方法 or 属性：muted(value: boolean): VideoAttribute;<br>起始版本：10|video.d.ts|
|起始版本有变化|类名：VideoAttribute<br>方法 or 属性：autoPlay(value: boolean): VideoAttribute;<br>起始版本：7|类名：VideoAttribute<br>方法 or 属性：autoPlay(value: boolean): VideoAttribute;<br>起始版本：10|video.d.ts|
|起始版本有变化|类名：VideoAttribute<br>方法 or 属性：controls(value: boolean): VideoAttribute;<br>起始版本：7|类名：VideoAttribute<br>方法 or 属性：controls(value: boolean): VideoAttribute;<br>起始版本：10|video.d.ts|
|起始版本有变化|类名：VideoAttribute<br>方法 or 属性：loop(value: boolean): VideoAttribute;<br>起始版本：6|类名：VideoAttribute<br>方法 or 属性：loop(value: boolean): VideoAttribute;<br>起始版本：10|video.d.ts|
|起始版本有变化|类名：VideoAttribute<br>方法 or 属性：objectFit(value: ImageFit): VideoAttribute;<br>起始版本：7|类名：VideoAttribute<br>方法 or 属性：objectFit(value: ImageFit): VideoAttribute;<br>起始版本：10|video.d.ts|
|起始版本有变化|类名：VideoAttribute<br>方法 or 属性：onStart(event: () => void): VideoAttribute;<br>起始版本：7|类名：VideoAttribute<br>方法 or 属性：onStart(event: () => void): VideoAttribute;<br>起始版本：10|video.d.ts|
|起始版本有变化|类名：VideoAttribute<br>方法 or 属性：onPause(event: () => void): VideoAttribute;<br>起始版本：7|类名：VideoAttribute<br>方法 or 属性：onPause(event: () => void): VideoAttribute;<br>起始版本：10|video.d.ts|
|起始版本有变化|类名：VideoAttribute<br>方法 or 属性：onFinish(event: () => void): VideoAttribute;<br>起始版本：7|类名：VideoAttribute<br>方法 or 属性：onFinish(event: () => void): VideoAttribute;<br>起始版本：10|video.d.ts|
|起始版本有变化|类名：VideoAttribute<br>方法 or 属性：onError(event: () => void): VideoAttribute;<br>起始版本：7|类名：VideoAttribute<br>方法 or 属性：onError(event: () => void): VideoAttribute;<br>起始版本：10|video.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const Video: VideoInterface;<br>起始版本：7|类名：global<br>方法 or 属性：declare const Video: VideoInterface;<br>起始版本：10|video.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const VideoInstance: VideoAttribute;<br>起始版本：7|类名：global<br>方法 or 属性：declare const VideoInstance: VideoAttribute;<br>起始版本：10|video.d.ts|
|起始版本有变化|类名：WaterFlowOptions<br>起始版本：9|类名：WaterFlowOptions<br>起始版本：10|water_flow.d.ts|
|起始版本有变化|类名：WaterFlowOptions<br>方法 or 属性：footer?: CustomBuilder;<br>起始版本：9|类名：WaterFlowOptions<br>方法 or 属性：footer?: CustomBuilder;<br>起始版本：10|water_flow.d.ts|
|起始版本有变化|类名：WaterFlowOptions<br>方法 or 属性：scroller?: Scroller;<br>起始版本：9|类名：WaterFlowOptions<br>方法 or 属性：scroller?: Scroller;<br>起始版本：10|water_flow.d.ts|
|起始版本有变化|类名：WaterFlowInterface<br>起始版本：9|类名：WaterFlowInterface<br>起始版本：10|water_flow.d.ts|
|起始版本有变化|类名：WaterFlowInterface<br>方法 or 属性：(options?: WaterFlowOptions): WaterFlowAttribute;<br>起始版本：9|类名：WaterFlowInterface<br>方法 or 属性：(options?: WaterFlowOptions): WaterFlowAttribute;<br>起始版本：10|water_flow.d.ts|
|起始版本有变化|类名：WaterFlowAttribute<br>起始版本：9|类名：WaterFlowAttribute<br>起始版本：10|water_flow.d.ts|
|起始版本有变化|类名：WaterFlowAttribute<br>方法 or 属性：columnsTemplate(value: string): WaterFlowAttribute;<br>起始版本：9|类名：WaterFlowAttribute<br>方法 or 属性：columnsTemplate(value: string): WaterFlowAttribute;<br>起始版本：10|water_flow.d.ts|
|起始版本有变化|类名：WaterFlowAttribute<br>方法 or 属性：itemConstraintSize(value: ConstraintSizeOptions): WaterFlowAttribute;<br>起始版本：9|类名：WaterFlowAttribute<br>方法 or 属性：itemConstraintSize(value: ConstraintSizeOptions): WaterFlowAttribute;<br>起始版本：10|water_flow.d.ts|
|起始版本有变化|类名：WaterFlowAttribute<br>方法 or 属性：rowsTemplate(value: string): WaterFlowAttribute;<br>起始版本：9|类名：WaterFlowAttribute<br>方法 or 属性：rowsTemplate(value: string): WaterFlowAttribute;<br>起始版本：10|water_flow.d.ts|
|起始版本有变化|类名：WaterFlowAttribute<br>方法 or 属性：columnsGap(value: Length): WaterFlowAttribute;<br>起始版本：9|类名：WaterFlowAttribute<br>方法 or 属性：columnsGap(value: Length): WaterFlowAttribute;<br>起始版本：10|water_flow.d.ts|
|起始版本有变化|类名：WaterFlowAttribute<br>方法 or 属性：rowsGap(value: Length): WaterFlowAttribute;<br>起始版本：9|类名：WaterFlowAttribute<br>方法 or 属性：rowsGap(value: Length): WaterFlowAttribute;<br>起始版本：10|water_flow.d.ts|
|起始版本有变化|类名：WaterFlowAttribute<br>方法 or 属性：layoutDirection(value: FlexDirection): WaterFlowAttribute;<br>起始版本：9|类名：WaterFlowAttribute<br>方法 or 属性：layoutDirection(value: FlexDirection): WaterFlowAttribute;<br>起始版本：10|water_flow.d.ts|
|起始版本有变化|类名：WaterFlowAttribute<br>方法 or 属性：onReachStart(event: () => void): WaterFlowAttribute;<br>起始版本：9|类名：WaterFlowAttribute<br>方法 or 属性：onReachStart(event: () => void): WaterFlowAttribute;<br>起始版本：10|water_flow.d.ts|
|起始版本有变化|类名：WaterFlowAttribute<br>方法 or 属性：onReachEnd(event: () => void): WaterFlowAttribute;<br>起始版本：9|类名：WaterFlowAttribute<br>方法 or 属性：onReachEnd(event: () => void): WaterFlowAttribute;<br>起始版本：10|water_flow.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const WaterFlow: WaterFlowInterface;<br>起始版本：9|类名：global<br>方法 or 属性：declare const WaterFlow: WaterFlowInterface;<br>起始版本：10|water_flow.d.ts|
|起始版本有变化|类名：global<br>方法 or 属性：declare const WaterFlowInstance: WaterFlowAttribute;<br>起始版本：9|类名：global<br>方法 or 属性：declare const WaterFlowInstance: WaterFlowAttribute;<br>起始版本：10|water_flow.d.ts|
|函数有变化|类名：ActionSheet<br>方法 or 属性：static show(value: {<br><br>    /**<br><br>     * Title Properties<br><br>     * @since 8<br><br>     */<br><br>    title: string \| Resource;<br><br><br><br>    /**<br><br>     * message Properties<br><br>     * @since 8<br><br>     */<br><br>    message: string \| Resource;<br><br><br><br>    /**<br><br>     * Invoke the commit function.<br><br>     * @since 8<br><br>     */<br><br>    confirm?: {<br><br>      /**<br><br>       * Text content of the confirmation button.<br><br>       * @since 8<br><br>       */<br><br>      value: string \| Resource;<br><br><br><br>      /**<br><br>       * Method executed by the callback.<br><br>       * @since 8<br><br>       */<br><br>      action: () => void;<br><br>    };<br><br><br><br>    /**<br><br>     * Execute Cancel Function.<br><br>     * @since 8<br><br>     */<br><br>    cancel?: () => void;<br><br><br><br>    /**<br><br>     * The Array of sheets<br><br>     * @since 8<br><br>     */<br><br>    sheets: Array\<SheetInfo>;<br><br><br><br>    /**<br><br>     * Allows users to click the mask layer to exit.<br><br>     * @since 8<br><br>     */<br><br>    autoCancel?: boolean;<br><br><br><br>    /**<br><br>     * Alignment in the vertical direction.<br><br>     * @since 8<br><br>     */<br><br>    alignment?: DialogAlignment;<br><br><br><br>    /**<br><br>     * Offset of the pop-up window relative to the alignment position.<br><br>     * @since 8<br><br>     */<br><br>    offset?: { dx: number \| string \| Resource; dy: number \| string \| Resource };<br><br>  });<br>|类名：ActionSheet<br>方法 or 属性：static show(value: {<br>    /**<br>     * Title Properties<br>     * @since 8<br>     */<br>    /**<br>     * Title Properties<br>     * @crossplatform<br>     * @since 10<br>     */<br>    title: string \| Resource;<br><br>    /**<br>     * message Properties<br>     * @since 8<br>     */<br>     /**<br>     * message Properties<br>     * @crossplatform<br>     * @since 10<br>     */<br>    message: string \| Resource;<br><br>    /**<br>     * Invoke the commit function.<br>     * @since 8<br>     */<br>    /**<br>     * Invoke the commit function.<br>     * @crossplatform<br>     * @since 10<br>     */<br>    confirm?: {<br>      /**<br>       * Text content of the confirmation button.<br>       * @since 8<br>       */<br>      /**<br>       * Text content of the confirmation button.<br>       * @crossplatform<br>       * @since 10<br>       */<br>      value: string \| Resource;<br><br>      /**<br>       * Method executed by the callback.<br>       * @since 8<br>       */<br>      /**<br>       * Method executed by the callback.<br>       * @crossplatform<br>       * @since 10<br>       */<br>      action: () => void;<br>    };<br><br>    /**<br>     * Execute Cancel Function.<br>     * @since 8<br>     */<br>    /**<br>     * Execute Cancel Function.<br>     * @crossplatform<br>     * @since 10<br>     */<br>    cancel?: () => void;<br><br>    /**<br>     * The Array of sheets<br>     * @since 8<br>     */<br>    /**<br>     * The Array of sheets<br>     * @crossplatform<br>     * @since 10<br>     */<br>    sheets: Array\<SheetInfo>;<br><br>    /**<br>     * Allows users to click the mask layer to exit.<br>     * @since 8<br>     */<br>    /**<br>     * Allows users to click the mask layer to exit.<br>     * @crossplatform<br>     * @since 10<br>     */<br>    autoCancel?: boolean;<br><br>    /**<br>     * Alignment in the vertical direction.<br>     * @since 8<br>     */<br>    /**<br>     * Alignment in the vertical direction.<br>     * @crossplatform<br>     * @since 10<br>     */<br>    alignment?: DialogAlignment;<br><br>    /**<br>     * Offset of the pop-up window relative to the alignment position.<br>     * @since 8<br>     */<br>    /**<br>     * Offset of the pop-up window relative to the alignment position.<br>     * @crossplatform<br>     * @since 10<br>     */<br>    offset?: { dx: number \| string \| Resource; dy: number \| string \| Resource };<br>  });<br>|action_sheet.d.ts|
|函数有变化|类名：AlphabetIndexerAttribute<br>方法 or 属性：alignStyle(value: IndexerAlign): AlphabetIndexerAttribute;<br>|类名：AlphabetIndexerAttribute<br>方法 or 属性：alignStyle(value: IndexerAlign, offset?: Length): AlphabetIndexerAttribute;<br>|alphabet_indexer.d.ts|
|函数有变化|类名：PopupOptions<br>方法 or 属性：onStateChange?: (event: { isVisible: boolean }) => void;<br>|类名：PopupOptions<br>方法 or 属性：onStateChange?: (event: {<br>    /**<br>     * is Visible.<br>     * @crossplatform<br>     * @since 10<br>     */<br>    isVisible: boolean<br>  }) => void;<br>|common.d.ts|
|函数有变化|类名：CustomPopupOptions<br>方法 or 属性：onStateChange?: (event: { isVisible: boolean }) => void;<br>|类名：CustomPopupOptions<br>方法 or 属性：onStateChange?: (event: {<br>    /**<br>     * is Visible.<br>     * @crossplatform<br>     * @since 10<br>     */<br>    isVisible: boolean<br>  }) => void;<br>|common.d.ts|
|函数有变化|类名：CommonMethod<br>方法 or 属性：backgroundBlurStyle(value: BlurStyle): T;<br>|类名：CommonMethod<br>方法 or 属性：backgroundBlurStyle(value: BlurStyle, options?: BackgroundBlurStyleOptions): T;<br>|common.d.ts|
|函数有变化|类名：CommonMethod<br>方法 or 属性：borderStyle(value: BorderStyle): T;<br>|类名：CommonMethod<br>方法 or 属性：borderStyle(value: BorderStyle \| EdgeStyles): T;<br>|common.d.ts|
|函数有变化|类名：CommonMethod<br>方法 or 属性：borderStyle(value: EdgeStyles): T;<br>|类名：CommonMethod<br>方法 or 属性：borderStyle(value: BorderStyle \| EdgeStyles): T;<br>|common.d.ts|
|函数有变化|类名：CommonMethod<br>方法 or 属性：borderWidth(value: Length): T;<br>|类名：CommonMethod<br>方法 or 属性：borderWidth(value: Length \| EdgeWidths): T;<br>|common.d.ts|
|函数有变化|类名：CommonMethod<br>方法 or 属性：borderWidth(value: EdgeWidths): T;<br>|类名：CommonMethod<br>方法 or 属性：borderWidth(value: Length \| EdgeWidths): T;<br>|common.d.ts|
|函数有变化|类名：CommonMethod<br>方法 or 属性：borderColor(value: ResourceColor): T;<br>|类名：CommonMethod<br>方法 or 属性：borderColor(value: ResourceColor \| EdgeColors): T;<br>|common.d.ts|
|函数有变化|类名：CommonMethod<br>方法 or 属性：borderColor(value: EdgeColors): T;<br>|类名：CommonMethod<br>方法 or 属性：borderColor(value: ResourceColor \| EdgeColors): T;<br>|common.d.ts|
|函数有变化|类名：CommonMethod<br>方法 or 属性：borderRadius(value: Length): T;<br>|类名：CommonMethod<br>方法 or 属性：borderRadius(value: Length \| BorderRadiuses): T;<br>|common.d.ts|
|函数有变化|类名：CommonMethod<br>方法 or 属性：borderRadius(value: BorderRadiuses): T;<br>|类名：CommonMethod<br>方法 or 属性：borderRadius(value: Length \| BorderRadiuses): T;<br>|common.d.ts|
|函数有变化|类名：CommonMethod<br>方法 or 属性：transition(value: TransitionOptions): T;<br>|类名：CommonMethod<br>方法 or 属性：transition(value: TransitionOptions \| TransitionEffect): T;<br>|common.d.ts|
|函数有变化|类名：CommonMethod<br>方法 or 属性：shadow(value: {<br>    radius: number \| Resource;<br>    color?: Color \| string \| Resource;<br>    offsetX?: number \| Resource;<br>    offsetY?: number \| Resource;<br>  }): T;<br>|类名：CommonMethod<br>方法 or 属性：shadow(value: ShadowOptions \| ShadowStyle): T;<br>|common.d.ts|
|函数有变化|类名：CommonMethod<br>方法 or 属性：mask(value: CircleAttribute \| EllipseAttribute \| PathAttribute \| RectAttribute): T;<br>|类名：CommonMethod<br>方法 or 属性：mask(value: CircleAttribute \| EllipseAttribute \| PathAttribute \| RectAttribute \| ProgressMask): T;<br>|common.d.ts|
|函数有变化|类名：CommonMethod<br>方法 or 属性：bindMenu(content: { value: string; action: () => void }[] \| CustomBuilder): T;<br>|类名：CommonMethod<br>方法 or 属性：bindMenu(content: { value: ResourceStr; icon?: ResourceStr; action: () => void }[] \| CustomBuilder, options?: MenuOptions): T;<br>|common.d.ts|
|函数有变化|类名：CommonMethod<br>方法 or 属性：bindContextMenu(content: CustomBuilder, responseType: ResponseType): T;<br>|类名：CommonMethod<br>方法 or 属性：bindContextMenu(content: CustomBuilder, responseType: ResponseType, options?: ContextMenuOptions): T;<br>|common.d.ts|
|函数有变化|类名：ImageInterface<br>方法 or 属性：(src: string \| PixelMap \| Resource): ImageAttribute;<br>|类名：ImageInterface<br>方法 or 属性：(src: PixelMap \| ResourceStr \| DrawableDescriptor): ImageAttribute;<br>|image.d.ts|
|函数有变化|类名：MenuItemAttribute<br>方法 or 属性：selectIcon(value: boolean): MenuItemAttribute;<br>|类名：MenuItemAttribute<br>方法 or 属性：selectIcon(value: boolean \| ResourceStr): MenuItemAttribute;<br>|menu_item.d.ts|
|函数有变化|类名：NavigationAttribute<br>方法 or 属性：title(value: string \| CustomBuilder \| NavigationCommonTitle \| NavigationCustomTitle): NavigationAttribute;<br>|类名：NavigationAttribute<br>方法 or 属性：title(value: ResourceStr \| CustomBuilder \| NavigationCommonTitle \| NavigationCustomTitle): NavigationAttribute;<br>|navigation.d.ts|
|函数有变化|类名：RefreshInterface<br>方法 or 属性：(value: { refreshing: boolean; offset?: number \| string; friction?: number \| string }): RefreshAttribute;<br>|类名：RefreshInterface<br>方法 or 属性：(value: RefreshOptions): RefreshAttribute;<br>|refresh.d.ts|
|函数有变化|类名：Scroller<br>方法 or 属性：scrollTo(value: {<br>    xOffset: number \| string;<br>    yOffset: number \| string;<br>    animation?: { duration: number; curve: Curve };<br>  });<br>|类名：Scroller<br>方法 or 属性：scrollTo(value: {<br>    /**<br>     * The X-axis offset.<br>     * @crossplatform<br>     * @since 10<br>     */<br>    xOffset: number \| string;<br><br>    /**<br>     * The Y-axis offset.<br>     * @crossplatform<br>     * @since 10<br>     */<br>    yOffset: number \| string;<br><br>    /**<br>     * Descriptive animation.<br>     * @crossplatform<br>     * @since 10<br>     */<br>    animation?: { duration: number; curve: Curve };<br>  });<br>|scroll.d.ts|
|函数有变化|类名：Scroller<br>方法 or 属性：scrollToIndex(value: number);<br>|类名：Scroller<br>方法 or 属性：scrollToIndex(value: number, smooth?:boolean);<br>|scroll.d.ts|
|函数有变化|类名：SearchInterface<br>方法 or 属性：(options?: { value?: string;<br>      placeholder?: string;<br>      icon?: string;<br>      controller?: SearchController<br>  }): SearchAttribute;<br>|类名：SearchInterface<br>方法 or 属性：(options?: {<br>    /**<br>     * Text input in the search text box<br>     * @type { string }<br>     * @since 8<br>     */<br>    value?: string;<br><br>    /**<br>     * Text displayed when there is no input<br>     * @type { string }<br>     * @since 8<br>     */<br>    /**<br>     * Text displayed when there is no input<br>     * @type { ResourceStr }<br>     * @since 10<br>     */<br>    placeholder?: ResourceStr;<br><br>    /**<br>     * Path to the search icon<br>     * @type { string }<br>     * @since 8<br>     */<br>    icon?: string;<br><br>    /**<br>     * Controller of the \<Search> component<br>     * @type { SearchController }<br>     * @since 8<br>     */<br>    controller?: SearchController<br>  }): SearchAttribute;<br>|search.d.ts|
|函数有变化|类名：SearchAttribute<br>方法 or 属性：searchButton(value: string): SearchAttribute;<br>|类名：SearchAttribute<br>方法 or 属性：searchButton(value: string, option?: SearchButtonOption): SearchAttribute;<br>|search.d.ts|
|函数有变化|类名：SwiperAttribute<br>方法 or 属性：indicator(value: boolean): SwiperAttribute;<br>|类名：SwiperAttribute<br>方法 or 属性：indicator(value: DotIndicator \| DigitIndicator \| boolean): SwiperAttribute;<br>|swiper.d.ts|
|函数有变化|类名：SwiperAttribute<br>方法 or 属性：curve(value: Curve \| string): SwiperAttribute;<br>|类名：SwiperAttribute<br>方法 or 属性：curve(value: Curve \| string \| ICurve): SwiperAttribute;<br>|swiper.d.ts|
|函数有变化|类名：SubTabBarStyle<br>方法 or 属性：constructor(content: string \| Resource);<br>|类名：SubTabBarStyle<br>方法 or 属性：constructor(content: ResourceStr);<br>|tab_content.d.ts|
|函数有变化|类名：BottomTabBarStyle<br>方法 or 属性：constructor(icon: string \| Resource, text: string \| Resource);<br>|类名：BottomTabBarStyle<br>方法 or 属性：constructor(icon: ResourceStr, text: ResourceStr);<br>|tab_content.d.ts|
|函数有变化|类名：VideoAttribute<br>方法 or 属性：onFullscreenChange(callback: (event?: { fullscreen: boolean }) => void): VideoAttribute;<br>|类名：VideoAttribute<br>方法 or 属性：onFullscreenChange(callback: (event?: {<br>    /**<br>     * Play the flag in full screen.<br>     * @crossplatform<br>     * @since 10<br>     */<br>    fullscreen: boolean<br>  }) => void): VideoAttribute;<br>|video.d.ts|
|函数有变化|类名：VideoAttribute<br>方法 or 属性：onPrepared(callback: (event?: { duration: number }) => void): VideoAttribute;<br>|类名：VideoAttribute<br>方法 or 属性：onPrepared(callback: (event?: {<br>    /**<br>     * Playback duration.<br>     * @crossplatform<br>     * @since 10<br>     */<br>    duration: number<br>  }) => void): VideoAttribute;<br>|video.d.ts|
|函数有变化|类名：VideoAttribute<br>方法 or 属性：onSeeking(callback: (event?: { time: number }) => void): VideoAttribute;<br>|类名：VideoAttribute<br>方法 or 属性：onSeeking(callback: (event?: {<br>    /**<br>     * Play time.<br>     * @crossplatform<br>     * @since 10<br>     */<br>    time: number<br>  }) => void): VideoAttribute;<br>|video.d.ts|
|函数有变化|类名：VideoAttribute<br>方法 or 属性：onSeeked(callback: (event?: { time: number }) => void): VideoAttribute;<br>|类名：VideoAttribute<br>方法 or 属性：onSeeked(callback: (event?: {<br>    /**<br>     * Play time.<br>     * @crossplatform<br>     * @since 10<br>     */<br>    time: number<br>  }) => void): VideoAttribute;<br>|video.d.ts|
|函数有变化|类名：VideoAttribute<br>方法 or 属性：onUpdate(callback: (event?: { time: number }) => void): VideoAttribute;<br>|类名：VideoAttribute<br>方法 or 属性：onUpdate(callback: (event?: {<br>    /**<br>     * Play time.<br>     * @crossplatform<br>     * @since 10<br>     */<br>    time: number<br>  }) => void): VideoAttribute;<br>|video.d.ts|
