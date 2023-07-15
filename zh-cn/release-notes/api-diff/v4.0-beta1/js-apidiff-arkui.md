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
|新增|NA|模块名: common<br>类名: AnimatableArithmetic<br>方法 or 属性：multiply(scale: number): AnimatableArithmetic\<T>;|common.d.ts|
|新增|NA|模块名: common<br>类名: AnimatableArithmetic<br>方法 or 属性：equals(rhs: AnimatableArithmetic\<T>): boolean;|common.d.ts|
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
|废弃版本有变化|类名：PopupOptions<br>方法 or 属性：placementOnTop?: boolean;<br>废弃版本：N/A|类名：PopupOptions<br>方法 or 属性：placementOnTop?: boolean;<br>废弃版本：10<br>代替接口：PopupOptions#placement|common.d.ts|
|废弃版本有变化|类名：CustomPopupOptions<br>方法 or 属性：maskColor?: Color \| string \| Resource \| number;<br>废弃版本：N/A|类名：CustomPopupOptions<br>方法 or 属性：maskColor?: Color \| string \| Resource \| number;<br>废弃版本：10<br>代替接口：CustomPopupOptions#mask|common.d.ts|
|废弃版本有变化|类名：CommonMethod<br>方法 or 属性：useSizeType(value: {<br>    xs?: number \| { span: number; offset: number };<br>    sm?: number \| { span: number; offset: number };<br>    md?: number \| { span: number; offset: number };<br>    lg?: number \| { span: number; offset: number };<br>  }): T;<br>废弃版本：N/A|类名：CommonMethod<br>方法 or 属性：useSizeType(value: {<br>    xs?: number \| { span: number; offset: number };<br>    sm?: number \| { span: number; offset: number };<br>    md?: number \| { span: number; offset: number };<br>    lg?: number \| { span: number; offset: number };<br>  }): T;<br>废弃版本：9<br>代替接口：grid_col/[GridColColumnOption] and grid_row/[GridRowColumnOption]|common.d.ts|
|废弃版本有变化|类名：SizeType<br>废弃版本：N/A|类名：SizeType<br>废弃版本：9<br>代替接口：grid_col/[GridColColumnOption] and grid_row/[GridRowColumnOption]|grid_container.d.ts|
|废弃版本有变化|类名：GridContainerOptions<br>废弃版本：N/A|类名：GridContainerOptions<br>废弃版本：9<br>代替接口：grid_col/[GridColOptions] and grid_row/[GridRowOptions]|grid_container.d.ts|
|废弃版本有变化|类名：GridContainerOptions<br>方法 or 属性：columns?: number \| "auto";<br>废弃版本：N/A|类名：GridContainerOptions<br>方法 or 属性：columns?: number \| "auto";<br>废弃版本：9<br>代替接口：N/A|grid_container.d.ts|
|废弃版本有变化|类名：GridContainerOptions<br>方法 or 属性：sizeType?: SizeType;<br>废弃版本：N/A|类名：GridContainerOptions<br>方法 or 属性：sizeType?: SizeType;<br>废弃版本：9<br>代替接口：N/A|grid_container.d.ts|
|废弃版本有变化|类名：GridContainerOptions<br>方法 or 属性：gutter?: number \| string;<br>废弃版本：N/A|类名：GridContainerOptions<br>方法 or 属性：gutter?: number \| string;<br>废弃版本：9<br>代替接口：N/A|grid_container.d.ts|
|废弃版本有变化|类名：GridContainerOptions<br>方法 or 属性：margin?: number \| string;<br>废弃版本：N/A|类名：GridContainerOptions<br>方法 or 属性：margin?: number \| string;<br>废弃版本：9<br>代替接口：N/A|grid_container.d.ts|
|废弃版本有变化|类名：GridContainerInterface<br>废弃版本：N/A|类名：GridContainerInterface<br>废弃版本：9<br>代替接口：grid_col/[GridColInterface] and grid_row/[GridRowInterface]|grid_container.d.ts|
|废弃版本有变化|类名：GridContainerInterface<br>方法 or 属性：(value?: GridContainerOptions): GridContainerAttribute;<br>废弃版本：N/A|类名：GridContainerInterface<br>方法 or 属性：(value?: GridContainerOptions): GridContainerAttribute;<br>废弃版本：9<br>代替接口：N/A|grid_container.d.ts|
|废弃版本有变化|类名：GridContainerAttribute<br>废弃版本：N/A|类名：GridContainerAttribute<br>废弃版本：9<br>代替接口：grid_col/[GridColAttribute] and grid_row/[GridRowAttribute]|grid_container.d.ts|
|废弃版本有变化|类名：ImageAttribute<br>方法 or 属性：draggable(value: boolean): ImageAttribute;<br>废弃版本：N/A|类名：ImageAttribute<br>方法 or 属性：draggable(value: boolean): ImageAttribute;<br>废弃版本：10<br>代替接口：common.CommonMethod#draggable|image.d.ts|
|废弃版本有变化|类名：Sticky<br>废弃版本：N/A|类名：Sticky<br>废弃版本：9<br>代替接口：list/StickyStyle |list_item.d.ts|
|废弃版本有变化|类名：ListItemAttribute<br>方法 or 属性：sticky(value: Sticky): ListItemAttribute;<br>废弃版本：N/A|类名：ListItemAttribute<br>方法 or 属性：sticky(value: Sticky): ListItemAttribute;<br>废弃版本：9<br>代替接口：list/List#sticky|list_item.d.ts|
|废弃版本有变化|类名：MenuAttribute<br>方法 or 属性：fontSize(value: Length): MenuAttribute;<br>废弃版本：N/A|类名：MenuAttribute<br>方法 or 属性：fontSize(value: Length): MenuAttribute;<br>废弃版本：10<br>代替接口：font   |menu.d.ts|
|废弃版本有变化|类名：SwiperDisplayMode<br>方法 or 属性：Stretch<br>废弃版本：N/A|类名：SwiperDisplayMode<br>方法 or 属性：Stretch<br>废弃版本：10<br>代替接口：SwiperDisplayMode#STRETCH|swiper.d.ts|
|废弃版本有变化|类名：SwiperDisplayMode<br>方法 or 属性：AutoLinear<br>废弃版本：N/A|类名：SwiperDisplayMode<br>方法 or 属性：AutoLinear<br>废弃版本：10<br>代替接口：SwiperDisplayMode#AUTO_LINEAR|swiper.d.ts|
|废弃版本有变化|类名：IndicatorStyle<br>废弃版本：N/A|类名：IndicatorStyle<br>废弃版本：10<br>代替接口：N/A|swiper.d.ts|
|废弃版本有变化|类名：SwiperAttribute<br>方法 or 属性：indicatorStyle(value?: IndicatorStyle): SwiperAttribute;<br>废弃版本：N/A|类名：SwiperAttribute<br>方法 or 属性：indicatorStyle(value?: IndicatorStyle): SwiperAttribute;<br>废弃版本：10<br>代替接口：N/A|swiper.d.ts|
|废弃版本有变化|类名：TextPickerAttribute<br>方法 or 属性：onAccept(callback: (value: string, index: number) => void): TextPickerAttribute;<br>废弃版本：N/A|类名：TextPickerAttribute<br>方法 or 属性：onAccept(callback: (value: string, index: number) => void): TextPickerAttribute;<br>废弃版本：10<br>代替接口：N/A|text_picker.d.ts|
|废弃版本有变化|类名：TextPickerAttribute<br>方法 or 属性：onCancel(callback: () => void): TextPickerAttribute;<br>废弃版本：N/A|类名：TextPickerAttribute<br>方法 or 属性：onCancel(callback: () => void): TextPickerAttribute;<br>废弃版本：10<br>代替接口：N/A|text_picker.d.ts|
|废弃版本有变化|类名：WebAttribute<br>方法 or 属性：onUrlLoadIntercept(callback: (event?: { data: string \| WebResourceRequest }) => boolean): WebAttribute;<br>废弃版本：N/A|类名：WebAttribute<br>方法 or 属性：onUrlLoadIntercept(callback: (event?: { data: string \| WebResourceRequest }) => boolean): WebAttribute;<br>废弃版本：10<br>代替接口：ohos.web.WebAttribute#onLoadIntercept|web.d.ts|
|函数有变化|类名：AlphabetIndexerAttribute<br>方法 or 属性：alignStyle(value: IndexerAlign): AlphabetIndexerAttribute;<br>|类名：AlphabetIndexerAttribute<br>方法 or 属性：alignStyle(value: IndexerAlign, offset?: Length): AlphabetIndexerAttribute;<br>|alphabet_indexer.d.ts|
|函数有变化|类名：CommonMethod<br>方法 or 属性：backgroundBlurStyle(value: BlurStyle): T;<br>|类名：CommonMethod<br>方法 or 属性：backgroundBlurStyle(value: BlurStyle, options?: BackgroundBlurStyleOptions): T;<br>|common.d.ts|
|函数有变化|类名：CommonMethod<br>方法 or 属性：borderStyle(value: BorderStyle): T;<br>|类名：CommonMethod<br>方法 or 属性：borderStyle(value: BorderStyle \| EdgeStyles): T;<br>|common.d.ts|
|函数有变化|类名：CommonMethod<br>方法 or 属性：borderWidth(value: EdgeWidths): T;<br>|类名：CommonMethod<br>方法 or 属性：borderWidth(value: Length \| EdgeWidths): T;<br>|common.d.ts|
|函数有变化|类名：CommonMethod<br>方法 or 属性：borderColor(value: ResourceColor): T;<br>|类名：CommonMethod<br>方法 or 属性：borderColor(value: ResourceColor \| EdgeColors): T;<br>|common.d.ts|
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
|函数有变化|类名：Scroller<br>方法 or 属性：scrollToIndex(value: number);<br>|类名：Scroller<br>方法 or 属性：scrollToIndex(value: number, smooth?:boolean);<br>|scroll.d.ts|
|函数有变化|类名：SearchAttribute<br>方法 or 属性：searchButton(value: string): SearchAttribute;<br>|类名：SearchAttribute<br>方法 or 属性：searchButton(value: string, option?: SearchButtonOption): SearchAttribute;<br>|search.d.ts|
|函数有变化|类名：SwiperAttribute<br>方法 or 属性：indicator(value: boolean): SwiperAttribute;<br>|类名：SwiperAttribute<br>方法 or 属性：indicator(value: DotIndicator \| DigitIndicator \| boolean): SwiperAttribute;<br>|swiper.d.ts|
|函数有变化|类名：SwiperAttribute<br>方法 or 属性：curve(value: Curve \| string): SwiperAttribute;<br>|类名：SwiperAttribute<br>方法 or 属性：curve(value: Curve \| string \| ICurve): SwiperAttribute;<br>|swiper.d.ts|
