| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Added|NA|Module name: ohos.arkui.componentSnapshot<br>Class name: componentSnapshot|@ohos.arkui.componentSnapshot.d.ts|
|Added|NA|Module name: ohos.arkui.componentSnapshot<br>Class name: componentSnapshot<br>Method or attribute name: function get(id: string, callback: AsyncCallback\<image.PixelMap>): void;|@ohos.arkui.componentSnapshot.d.ts|
|Added|NA|Module name: ohos.arkui.componentSnapshot<br>Class name: componentSnapshot<br>Method or attribute name: function get(id: string): Promise\<image.PixelMap>;|@ohos.arkui.componentSnapshot.d.ts|
|Added|NA|Module name: ohos.arkui.componentSnapshot<br>Class name: componentSnapshot<br>Method or attribute name: function createFromBuilder(builder: CustomBuilder, callback: AsyncCallback\<image.PixelMap>): void;|@ohos.arkui.componentSnapshot.d.ts|
|Added|NA|Module name: ohos.arkui.componentSnapshot<br>Class name: componentSnapshot<br>Method or attribute name: function createFromBuilder(builder: CustomBuilder): Promise\<image.PixelMap>;|@ohos.arkui.componentSnapshot.d.ts|
|Added|NA|Module name: ohos.arkui.drawableDescriptor<br>Class name: DrawableDescriptor|@ohos.arkui.drawableDescriptor.d.ts|
|Added|NA|Module name: ohos.arkui.drawableDescriptor<br>Class name: DrawableDescriptor<br>Method or attribute name: constructor();|@ohos.arkui.drawableDescriptor.d.ts|
|Added|NA|Module name: ohos.arkui.drawableDescriptor<br>Class name: DrawableDescriptor<br>Method or attribute name: getPixelMap(): image.PixelMap;|@ohos.arkui.drawableDescriptor.d.ts|
|Added|NA|Module name: ohos.arkui.drawableDescriptor<br>Class name: LayeredDrawableDescriptor|@ohos.arkui.drawableDescriptor.d.ts|
|Added|NA|Module name: ohos.arkui.drawableDescriptor<br>Class name: LayeredDrawableDescriptor<br>Method or attribute name: getForeground(): DrawableDescriptor;|@ohos.arkui.drawableDescriptor.d.ts|
|Added|NA|Module name: ohos.arkui.drawableDescriptor<br>Class name: LayeredDrawableDescriptor<br>Method or attribute name: getBackground(): DrawableDescriptor;|@ohos.arkui.drawableDescriptor.d.ts|
|Added|NA|Module name: ohos.arkui.drawableDescriptor<br>Class name: LayeredDrawableDescriptor<br>Method or attribute name: getMask(): DrawableDescriptor;|@ohos.arkui.drawableDescriptor.d.ts|
|Added|NA|Class name: curves<br>Method or attribute name: function interpolatingSpring(velocity: number, mass: number, stiffness: number, damping: number): ICurve;|@ohos.curves.d.ts|
|Added|NA|Class name: MeasureOptions<br>Method or attribute name: textContent: string \| Resource;|@ohos.measure.d.ts|
|Added|NA|Class name: MeasureOptions<br>Method or attribute name: constraintWidth?: number \| string \| Resource;|@ohos.measure.d.ts|
|Added|NA|Class name: MeasureOptions<br>Method or attribute name: textAlign?: number \| TextAlign;|@ohos.measure.d.ts|
|Added|NA|Class name: MeasureOptions<br>Method or attribute name: overflow?: number \| TextOverflow;|@ohos.measure.d.ts|
|Added|NA|Class name: MeasureOptions<br>Method or attribute name: maxLines?: number;|@ohos.measure.d.ts|
|Added|NA|Class name: MeasureOptions<br>Method or attribute name: lineHeight?: number \| string \| Resource;|@ohos.measure.d.ts|
|Added|NA|Class name: MeasureOptions<br>Method or attribute name: baselineOffset?: number \| string;|@ohos.measure.d.ts|
|Added|NA|Class name: MeasureOptions<br>Method or attribute name: textCase?: number \| TextCase;|@ohos.measure.d.ts|
|Added|NA|Module name: ohos.measure<br>Class name: MeasureText<br>Method or attribute name: static measureTextSize(options: MeasureOptions): SizeOptions;|@ohos.measure.d.ts|
|Added|NA|Class name: MeasureText<br>Method or attribute name: static measureTextSize(options: MeasureOptions): SizeOptions;|@ohos.measure.d.ts|
|Added|NA|Module name: ohos.uiAppearance<br>Class name: uiAppearance|@ohos.uiAppearance.d.ts|
|Added|NA|Module name: ohos.uiAppearance<br>Class name: DarkMode|@ohos.uiAppearance.d.ts|
|Added|NA|Module name: ohos.uiAppearance<br>Class name: DarkMode<br>Method or attribute name: ALWAYS_DARK = 0|@ohos.uiAppearance.d.ts|
|Added|NA|Module name: ohos.uiAppearance<br>Class name: DarkMode<br>Method or attribute name: ALWAYS_LIGHT = 1|@ohos.uiAppearance.d.ts|
|Added|NA|Module name: ohos.uiAppearance<br>Class name: uiAppearance<br>Method or attribute name: function setDarkMode(mode: DarkMode, callback: AsyncCallback\<void>): void;|@ohos.uiAppearance.d.ts|
|Added|NA|Module name: ohos.uiAppearance<br>Class name: uiAppearance<br>Method or attribute name: function setDarkMode(mode: DarkMode): Promise\<void>;|@ohos.uiAppearance.d.ts|
|Added|NA|Module name: ohos.uiAppearance<br>Class name: uiAppearance<br>Method or attribute name: function getDarkMode(): DarkMode;|@ohos.uiAppearance.d.ts|
|Added|NA|Class name: AlertDialogParamWithConfirm<br>Method or attribute name: confirm?: {<br>    /**<br>     * Text content of the confirmation button.<br>     * @since 7<br>     */<br>    /**<br>     * Text content of the confirmation button.<br>     * @crossplatform<br>     * @since 10<br>     */<br>    value: ResourceStr;<br><br>    /**<br>     * Text color of the confirmation button.<br>     * @since 7<br>     */<br>    /**<br>     * Text color of the confirmation button.<br>     * @crossplatform<br>     * @since 10<br>     */<br>    fontColor?: ResourceColor;<br><br>    /**<br>     * Background color of the confirmation button.<br>     * @since 7<br>     */<br>    /**<br>     * Background color of the confirmation button.<br>     * @crossplatform<br>     * @since 10<br>     */<br>    backgroundColor?: ResourceColor;<br><br>    /**<br>     * Method executed by the callback.<br>     * @since 7<br>     */<br>    /**<br>     * Method executed by the callback.<br>     * @crossplatform<br>     * @since 10<br>     */<br>    action: () => void;<br>  };|alert_dialog.d.ts|
|Added|NA|Class name: AlertDialogParamWithButtons<br>Method or attribute name: primaryButton: {<br>    /**<br>     * Text content of the confirmation button.<br>     * @since 7<br>     */<br>    /**<br>     * Text content of the confirmation button.<br>     * @crossplatform<br>     * @since 10<br>     */<br>    value: ResourceStr;<br><br>    /**<br>     * Text color of the confirmation button.<br>     * @since 7<br>     */<br>    /**<br>     * Text color of the confirmation button.<br>     * @crossplatform<br>     * @since 10<br>     */<br>    fontColor?: ResourceColor;<br><br>    /**<br>     * Background color of the confirmation button.<br>     * @since 7<br>     */<br>    /**<br>     * Background color of the confirmation button.<br>     * @crossplatform<br>     * @since 10<br>     */<br>    backgroundColor?: ResourceColor;<br><br>    /**<br>     * Method executed by the callback.<br>     * @since 7<br>     */<br>    /**<br>     * Method executed by the callback.<br>     * @crossplatform<br>     * @since 10<br>     */<br>    action: () => void;<br>  };|alert_dialog.d.ts|
|Added|NA|Class name: AlertDialogParamWithButtons<br>Method or attribute name: secondaryButton: {<br>    /**<br>     * Text content of the confirmation button.<br>     * @since 7<br>     */<br>    /**<br>     * Text content of the confirmation button.<br>     *  @crossplatform<br>     * @since 10<br>     */<br>    value: ResourceStr;<br><br>    /**<br>     * Text color of the confirmation button.<br>     * @since 7<br>     */<br>    /**<br>     * Text color of the confirmation button.<br>     * @crossplatform<br>     * @since 10<br>     */<br>    fontColor?: ResourceColor;<br><br>    /**<br>     * Background color of the confirmation button.<br>     * @since 7<br>     */<br>    /**<br>     * Background color of the confirmation button.<br>     * @crossplatform<br>     * @since 10<br>     */<br>    backgroundColor?: ResourceColor;<br><br>    /**<br>     * Method executed by the callback.<br>     * @since 7<br>     */<br>    /**<br>     * Method executed by the callback.<br>     * @crossplatform<br>     * @since 10<br>     */<br>    action: () => void;<br>  };|alert_dialog.d.ts|
|Added|NA|Class name: AlphabetIndexerAttribute<br>Method or attribute name: popupSelectedColor(value: ResourceColor): AlphabetIndexerAttribute;|alphabet_indexer.d.ts|
|Added|NA|Class name: AlphabetIndexerAttribute<br>Method or attribute name: popupUnselectedColor(value: ResourceColor): AlphabetIndexerAttribute;|alphabet_indexer.d.ts|
|Added|NA|Class name: AlphabetIndexerAttribute<br>Method or attribute name: popupItemBackgroundColor(value: ResourceColor): AlphabetIndexerAttribute;|alphabet_indexer.d.ts|
|Added|NA|Class name: AlphabetIndexerAttribute<br>Method or attribute name: popupItemFont(value: Font): AlphabetIndexerAttribute;|alphabet_indexer.d.ts|
|Added|NA|Module name: badge<br>Class name: BadgeStyle<br>Method or attribute name: borderColor?: ResourceColor;|badge.d.ts|
|Added|NA|Module name: badge<br>Class name: BadgeStyle<br>Method or attribute name: borderWidth?: Length;|badge.d.ts|
|Added|NA|Module name: badge<br>Class name: BadgeStyle<br>Method or attribute name: fontWeight?: number \| FontWeight \| string;|badge.d.ts|
|Added|NA|Module name: button<br>Class name: LabelStyle|button.d.ts|
|Added|NA|Module name: button<br>Class name: LabelStyle<br>Method or attribute name: overflow?: TextOverflow;|button.d.ts|
|Added|NA|Module name: button<br>Class name: LabelStyle<br>Method or attribute name: maxLines?: number;|button.d.ts|
|Added|NA|Module name: button<br>Class name: LabelStyle<br>Method or attribute name: minFontSize?: number \| ResourceStr;|button.d.ts|
|Added|NA|Module name: button<br>Class name: LabelStyle<br>Method or attribute name: maxFontSize?: number \| ResourceStr;|button.d.ts|
|Added|NA|Module name: button<br>Class name: LabelStyle<br>Method or attribute name: heightAdaptivePolicy?: TextHeightAdaptivePolicy;|button.d.ts|
|Added|NA|Module name: button<br>Class name: LabelStyle<br>Method or attribute name: font?: Font;|button.d.ts|
|Added|NA|Module name: button<br>Class name: ButtonAttribute<br>Method or attribute name: labelStyle(value: LabelStyle): ButtonAttribute;|button.d.ts|
|Added|NA|Module name: canvas<br>Class name: CanvasPattern|canvas.d.ts|
|Added|NA|Module name: canvas<br>Class name: CanvasPattern<br>Method or attribute name: setTransform(transform?: Matrix2D): void;|canvas.d.ts|
|Added|NA|Class name: CanvasRenderer<br>Method or attribute name: fillStyle: string \| number \| CanvasGradient \| CanvasPattern;|canvas.d.ts|
|Added|NA|Class name: CanvasRenderer<br>Method or attribute name: strokeStyle: string \| number \| CanvasGradient \| CanvasPattern;|canvas.d.ts|
|Added|NA|Class name: CanvasRenderer<br>Method or attribute name: createConicGradient(<br>    startAngle: number,<br>    x: number,<br>    y: number<br>  ): CanvasGradient;|canvas.d.ts|
|Added|NA|Class name: CanvasRenderer<br>Method or attribute name: putImageData(imagedata: ImageData, dx: number \| string, dy: number \| string): void;|canvas.d.ts|
|Added|NA|Class name: CanvasRenderer<br>Method or attribute name: putImageData(<br>    imagedata: ImageData,<br>    dx: number \| string,<br>    dy: number \| string,<br>    dirtyX: number \| string,<br>    dirtyY: number \| string,<br>    dirtyWidth: number \| string,<br>    dirtyHeight: number \| string<br>  ): void;|canvas.d.ts|
|Added|NA|Module name: canvas<br>Class name: OffscreenCanvas<br>Method or attribute name: getContext(contextType: "2d", option?: RenderingContextSettings): OffscreenCanvasRenderingContext2D;|canvas.d.ts|
|Added|NA|Class name: OffscreenCanvas<br>Method or attribute name: getContext(contextType: "2d", option?: RenderingContextSettings): OffscreenCanvasRenderingContext2D;|canvas.d.ts|
|Added|NA|Module name: checkbox<br>Class name: CheckboxAttribute<br>Method or attribute name: unselectedColor(value: ResourceColor): CheckboxAttribute;|checkbox.d.ts|
|Added|NA|Module name: checkbox<br>Class name: CheckboxAttribute<br>Method or attribute name: mark(value: MarkStyle): CheckboxAttribute;|checkbox.d.ts|
|Added|NA|Module name: checkboxgroup<br>Class name: CheckboxGroupAttribute<br>Method or attribute name: unselectedColor(value: ResourceColor): CheckboxGroupAttribute;|checkboxgroup.d.ts|
|Added|NA|Module name: checkboxgroup<br>Class name: CheckboxGroupAttribute<br>Method or attribute name: mark(value: MarkStyle): CheckboxGroupAttribute;|checkboxgroup.d.ts|
|Added|NA|Class name: global<br>Method or attribute name: declare const AnimatableExtend: MethodDecorator & ((value: Object) => MethodDecorator);|common.d.ts|
|Added|NA|Module name: common<br>Class name: AnimatableArithmetic|common.d.ts|
|Added|NA|Module name: common<br>Class name: AnimatableArithmetic<br>Method or attribute name: plus(rhs: AnimatableArithmetic\<T>): AnimatableArithmetic\<T>;|common.d.ts|
|Added|NA|Class name: AnimatableArithmetic<br>Method or attribute name: plus(rhs: AnimatableArithmetic\<T>): AnimatableArithmetic\<T>;|common.d.ts|
|Added|NA|Module name: common<br>Class name: AnimatableArithmetic<br>Method or attribute name: subtract(rhs: AnimatableArithmetic\<T>): AnimatableArithmetic\<T>;|common.d.ts|
|Added|NA|Module name: common<br>Class name: AnimatableArithmetic<br>Method or attribute name: multiply(scale: number): AnimatableArithmetic\<T>;|common.d.ts|
|Added|NA|Module name: common<br>Class name: AnimatableArithmetic<br>Method or attribute name: equals(rhs: AnimatableArithmetic\<T>): boolean;|common.d.ts|
|Added|NA|Class name: global<br>Method or attribute name: declare const Recycle: ClassDecorator;|common.d.ts|
|Added|NA|Module name: common<br>Class name: TransitionEdge|common.d.ts|
|Added|NA|Module name: common<br>Class name: TransitionEdge<br>Method or attribute name: TOP|common.d.ts|
|Added|NA|Module name: common<br>Class name: TransitionEdge<br>Method or attribute name: BOTTOM|common.d.ts|
|Added|NA|Module name: common<br>Class name: TransitionEdge<br>Method or attribute name: START|common.d.ts|
|Added|NA|Module name: common<br>Class name: TransitionEdge<br>Method or attribute name: END|common.d.ts|
|Added|NA|Module name: common<br>Class name: TransitionEffect|common.d.ts|
|Added|NA|Module name: common<br>Class name: TransitionEffect<br>Method or attribute name: static readonly IDENTITY: TransitionEffect\<"identity">;|common.d.ts|
|Added|NA|Module name: common<br>Class name: TransitionEffect<br>Method or attribute name: static readonly OPACITY: TransitionEffect\<"opacity">;|common.d.ts|
|Added|NA|Module name: common<br>Class name: TransitionEffect<br>Method or attribute name: static readonly SLIDE: TransitionEffect\<<br>    "asymmetric",<br>    {<br>      appear: TransitionEffect\<"move", TransitionEdge>;<br>      disappear: TransitionEffect\<"move", TransitionEdge>;<br>    }<br>  >;|common.d.ts|
|Added|NA|Module name: common<br>Class name: TransitionEffect<br>Method or attribute name: static readonly SLIDE_SWITCH: TransitionEffect\<"slideSwitch">;|common.d.ts|
|Added|NA|Module name: common<br>Class name: TransitionEffect<br>Method or attribute name: static translate(options: TranslateOptions): TransitionEffect\<"translate">;|common.d.ts|
|Added|NA|Module name: common<br>Class name: TransitionEffect<br>Method or attribute name: static rotate(options: RotateOptions): TransitionEffect\<"rotate">;|common.d.ts|
|Added|NA|Module name: common<br>Class name: TransitionEffect<br>Method or attribute name: static scale(options: ScaleOptions): TransitionEffect\<"scale">;|common.d.ts|
|Added|NA|Module name: common<br>Class name: TransitionEffect<br>Method or attribute name: static opacity(alpha: number): TransitionEffect\<"opacity">;|common.d.ts|
|Added|NA|Module name: common<br>Class name: TransitionEffect<br>Method or attribute name: static move(edge: TransitionEdge): TransitionEffect\<"move">;|common.d.ts|
|Added|NA|Module name: common<br>Class name: TransitionEffect<br>Method or attribute name: static asymmetric(<br>    appear: TransitionEffect,<br>    disappear: TransitionEffect<br>  ): TransitionEffect\<"asymmetric">;|common.d.ts|
|Added|NA|Module name: common<br>Class name: TransitionEffect<br>Method or attribute name: constructor(type: Type, effect: Effect);|common.d.ts|
|Added|NA|Module name: common<br>Class name: TransitionEffect<br>Method or attribute name: animation(value: AnimateParam): TransitionEffect;|common.d.ts|
|Added|NA|Module name: common<br>Class name: TransitionEffect<br>Method or attribute name: combine(transitionEffect: TransitionEffect): TransitionEffect;|common.d.ts|
|Added|NA|Class name: SourceTool<br>Method or attribute name: Finger|common.d.ts|
|Added|NA|Class name: SourceTool<br>Method or attribute name: Pen|common.d.ts|
|Added|NA|Class name: BlurStyle<br>Method or attribute name: BackgroundThin|common.d.ts|
|Added|NA|Class name: BlurStyle<br>Method or attribute name: BackgroundRegular|common.d.ts|
|Added|NA|Class name: BlurStyle<br>Method or attribute name: BackgroundThick|common.d.ts|
|Added|NA|Class name: BlurStyle<br>Method or attribute name: BackgroundUltraThick|common.d.ts|
|Added|NA|Class name: BlurStyle<br>Method or attribute name: BACKGROUND_THIN|common.d.ts|
|Added|NA|Class name: BlurStyle<br>Method or attribute name: BACKGROUND_REGULAR|common.d.ts|
|Added|NA|Class name: BlurStyle<br>Method or attribute name: BACKGROUND_THICK|common.d.ts|
|Added|NA|Class name: BlurStyle<br>Method or attribute name: BACKGROUND_ULTRA_THICK|common.d.ts|
|Added|NA|Module name: common<br>Class name: ThemeColorMode|common.d.ts|
|Added|NA|Module name: common<br>Class name: ThemeColorMode<br>Method or attribute name: System|common.d.ts|
|Added|NA|Module name: common<br>Class name: ThemeColorMode<br>Method or attribute name: Light|common.d.ts|
|Added|NA|Module name: common<br>Class name: ThemeColorMode<br>Method or attribute name: Dark|common.d.ts|
|Added|NA|Module name: common<br>Class name: ThemeColorMode<br>Method or attribute name: SYSTEM|common.d.ts|
|Added|NA|Module name: common<br>Class name: ThemeColorMode<br>Method or attribute name: LIGHT|common.d.ts|
|Added|NA|Module name: common<br>Class name: ThemeColorMode<br>Method or attribute name: DARK|common.d.ts|
|Added|NA|Module name: common<br>Class name: AdaptiveColor|common.d.ts|
|Added|NA|Module name: common<br>Class name: AdaptiveColor<br>Method or attribute name: Default|common.d.ts|
|Added|NA|Module name: common<br>Class name: AdaptiveColor<br>Method or attribute name: Average|common.d.ts|
|Added|NA|Module name: common<br>Class name: AdaptiveColor<br>Method or attribute name: DEFAULT|common.d.ts|
|Added|NA|Module name: common<br>Class name: AdaptiveColor<br>Method or attribute name: AVERAGE|common.d.ts|
|Added|NA|Module name: common<br>Class name: ModalTransition|common.d.ts|
|Added|NA|Module name: common<br>Class name: ModalTransition<br>Method or attribute name: Default|common.d.ts|
|Added|NA|Module name: common<br>Class name: ModalTransition<br>Method or attribute name: None|common.d.ts|
|Added|NA|Module name: common<br>Class name: ModalTransition<br>Method or attribute name: Alpha|common.d.ts|
|Added|NA|Module name: common<br>Class name: ModalTransition<br>Method or attribute name: DEFAULT|common.d.ts|
|Added|NA|Module name: common<br>Class name: ModalTransition<br>Method or attribute name: NONE|common.d.ts|
|Added|NA|Module name: common<br>Class name: ModalTransition<br>Method or attribute name: ALPHA|common.d.ts|
|Added|NA|Module name: common<br>Class name: BackgroundBlurStyleOptions|common.d.ts|
|Added|NA|Module name: common<br>Class name: BackgroundBlurStyleOptions<br>Method or attribute name: colorMode?: ThemeColorMode;|common.d.ts|
|Added|NA|Class name: BackgroundBlurStyleOptions<br>Method or attribute name: colorMode?: ThemeColorMode;|common.d.ts|
|Added|NA|Module name: common<br>Class name: BackgroundBlurStyleOptions<br>Method or attribute name: adaptiveColor?: AdaptiveColor;|common.d.ts|
|Added|NA|Class name: BackgroundBlurStyleOptions<br>Method or attribute name: adaptiveColor?: AdaptiveColor;|common.d.ts|
|Added|NA|Module name: common<br>Class name: BackgroundBlurStyleOptions<br>Method or attribute name: scale?: number;|common.d.ts|
|Added|NA|Class name: BackgroundBlurStyleOptions<br>Method or attribute name: scale?: number;|common.d.ts|
|Added|NA|Module name: common<br>Class name: PickerTextStyle|common.d.ts|
|Added|NA|Class name: PickerTextStyle<br>Method or attribute name: |common.d.ts|
|Added|NA|Module name: common<br>Class name: PickerTextStyle<br>Method or attribute name: color?: ResourceColor;|common.d.ts|
|Added|NA|Module name: common<br>Class name: PickerTextStyle<br>Method or attribute name: font?: Font;|common.d.ts|
|Added|NA|Module name: common<br>Class name: ShadowType|common.d.ts|
|Added|NA|Module name: common<br>Class name: ShadowType<br>Method or attribute name: COLOR|common.d.ts|
|Added|NA|Module name: common<br>Class name: ShadowType<br>Method or attribute name: BLUR|common.d.ts|
|Added|NA|Module name: common<br>Class name: ShadowOptions|common.d.ts|
|Added|NA|Module name: common<br>Class name: ShadowOptions<br>Method or attribute name: radius: number \| Resource;|common.d.ts|
|Added|NA|Module name: common<br>Class name: ShadowOptions<br>Method or attribute name: type?: ShadowType;|common.d.ts|
|Added|NA|Module name: common<br>Class name: ShadowOptions<br>Method or attribute name: color?: Color \| string \| Resource;|common.d.ts|
|Added|NA|Module name: common<br>Class name: ShadowOptions<br>Method or attribute name: offsetX?: number \| Resource;|common.d.ts|
|Added|NA|Module name: common<br>Class name: ShadowOptions<br>Method or attribute name: offsetY?: number \| Resource;|common.d.ts|
|Added|NA|Module name: common<br>Class name: ShadowStyle|common.d.ts|
|Added|NA|Module name: common<br>Class name: ShadowStyle<br>Method or attribute name: OuterDefaultXS|common.d.ts|
|Added|NA|Module name: common<br>Class name: ShadowStyle<br>Method or attribute name: OuterDefaultSM|common.d.ts|
|Added|NA|Module name: common<br>Class name: ShadowStyle<br>Method or attribute name: OuterDefaultMD|common.d.ts|
|Added|NA|Module name: common<br>Class name: ShadowStyle<br>Method or attribute name: OuterDefaultLG|common.d.ts|
|Added|NA|Module name: common<br>Class name: ShadowStyle<br>Method or attribute name: OuterFloatingSM|common.d.ts|
|Added|NA|Module name: common<br>Class name: ShadowStyle<br>Method or attribute name: OuterFloatingMD|common.d.ts|
|Added|NA|Module name: common<br>Class name: ShadowStyle<br>Method or attribute name: OUTER_DEFAULT_XS|common.d.ts|
|Added|NA|Module name: common<br>Class name: ShadowStyle<br>Method or attribute name: OUTER_DEFAULT_SM|common.d.ts|
|Added|NA|Module name: common<br>Class name: ShadowStyle<br>Method or attribute name: OUTER_DEFAULT_MD|common.d.ts|
|Added|NA|Module name: common<br>Class name: ShadowStyle<br>Method or attribute name: OUTER_DEFAULT_LG|common.d.ts|
|Added|NA|Module name: common<br>Class name: ShadowStyle<br>Method or attribute name: OUTER_FLOATING_SM|common.d.ts|
|Added|NA|Module name: common<br>Class name: ShadowStyle<br>Method or attribute name: OUTER_FLOATING_MD|common.d.ts|
|Added|NA|Module name: common<br>Class name: SheetSize|common.d.ts|
|Added|NA|Module name: common<br>Class name: SheetSize<br>Method or attribute name: MEDIUM|common.d.ts|
|Added|NA|Module name: common<br>Class name: SheetSize<br>Method or attribute name: LARGE|common.d.ts|
|Added|NA|Module name: common<br>Class name: DragBehavior|common.d.ts|
|Added|NA|Module name: common<br>Class name: DragBehavior<br>Method or attribute name: COPY|common.d.ts|
|Added|NA|Module name: common<br>Class name: DragBehavior<br>Method or attribute name: MOVE|common.d.ts|
|Added|NA|Module name: common<br>Class name: DragRet|common.d.ts|
|Added|NA|Module name: common<br>Class name: DragRet<br>Method or attribute name: DRAG_SUCCESS|common.d.ts|
|Added|NA|Module name: common<br>Class name: DragRet<br>Method or attribute name: DRAG_FAILED|common.d.ts|
|Added|NA|Module name: common<br>Class name: DragRet<br>Method or attribute name: DRAG_CANCELED|common.d.ts|
|Added|NA|Module name: common<br>Class name: DragRet<br>Method or attribute name: DROP_ENABLED|common.d.ts|
|Added|NA|Class name: DragEvent<br>Method or attribute name: dragBehavior: DragBehavior;|common.d.ts|
|Added|NA|Class name: DragEvent<br>Method or attribute name: useCustomDropAnimation: boolean;|common.d.ts|
|Added|NA|Class name: DragEvent<br>Method or attribute name: setData(unifiedData: UnifiedData): void;|common.d.ts|
|Added|NA|Class name: DragEvent<br>Method or attribute name: getData(): UnifiedData;|common.d.ts|
|Added|NA|Class name: DragEvent<br>Method or attribute name: getSummary(): Summary;|common.d.ts|
|Added|NA|Class name: DragEvent<br>Method or attribute name: setResult(dragRet: DragRet): void;|common.d.ts|
|Added|NA|Class name: DragEvent<br>Method or attribute name: getResult(): DragRet;|common.d.ts|
|Added|NA|Class name: DragEvent<br>Method or attribute name: getPreviewRect(): Rectangle;|common.d.ts|
|Added|NA|Module name: common<br>Class name: SheetStyle|common.d.ts|
|Added|NA|Module name: common<br>Class name: SheetStyle<br>Method or attribute name: height?: SheetSize \| Length;|common.d.ts|
|Added|NA|Module name: common<br>Class name: SheetStyle<br>Method or attribute name: dragBar?: boolean;|common.d.ts|
|Added|NA|Module name: common<br>Class name: PopupMessageOptions|common.d.ts|
|Added|NA|Module name: common<br>Class name: PopupMessageOptions<br>Method or attribute name: textColor?: ResourceColor;|common.d.ts|
|Added|NA|Module name: common<br>Class name: PopupMessageOptions<br>Method or attribute name: font?: Font;|common.d.ts|
|Added|NA|Class name: PopupOptions<br>Method or attribute name: placement?: Placement;|common.d.ts|
|Added|NA|Class name: PopupOptions<br>Method or attribute name: primaryButton?: {<br>    /**<br>     * Button text value<br>     * @since 7<br>     */<br>    /**<br>     * Button text value<br>     * @crossplatform<br>     * @since 10<br>     */<br>    value: string;<br><br>    /**<br>     * action<br>     * @since 7<br>     */<br>    /**<br>     * action<br>     * @crossplatform<br>     * @since 10<br>     */<br>    action: () => void;<br>  };|common.d.ts|
|Added|NA|Class name: PopupOptions<br>Method or attribute name: secondaryButton?: {<br>    /**<br>     * Button text value<br>     * @since 7<br>     */<br>    /**<br>     * Button text value<br>     * @crossplatform<br>     * @since 10<br>     */<br>    value: string;<br><br>    /**<br>     * action<br>     * @since 7<br>     */<br>    /**<br>     * action<br>     * @crossplatform<br>     * @since 10<br>     */<br>    action: () => void;<br>  };|common.d.ts|
|Added|NA|Class name: PopupOptions<br>Method or attribute name: mask?: boolean \| { color: ResourceColor };|common.d.ts|
|Added|NA|Class name: PopupOptions<br>Method or attribute name: messageOptions?: PopupMessageOptions|common.d.ts|
|Added|NA|Class name: PopupOptions<br>Method or attribute name: targetSpace?: Length|common.d.ts|
|Added|NA|Class name: CustomPopupOptions<br>Method or attribute name: mask?: boolean \| { color: ResourceColor };|common.d.ts|
|Added|NA|Class name: CustomPopupOptions<br>Method or attribute name: targetSpace?: Length|common.d.ts|
|Added|NA|Module name: common<br>Class name: ContextMenuOptions|common.d.ts|
|Added|NA|Module name: common<br>Class name: ContextMenuOptions<br>Method or attribute name: offset?: Position;|common.d.ts|
|Added|NA|Module name: common<br>Class name: ContextMenuOptions<br>Method or attribute name: placement?: Placement;|common.d.ts|
|Added|NA|Module name: common<br>Class name: ContextMenuOptions<br>Method or attribute name: onAppear?: () => void;|common.d.ts|
|Added|NA|Module name: common<br>Class name: ContextMenuOptions<br>Method or attribute name: onDisappear?: () => void;|common.d.ts|
|Added|NA|Module name: common<br>Class name: MenuOptions|common.d.ts|
|Added|NA|Module name: common<br>Class name: MenuOptions<br>Method or attribute name: title?: ResourceStr;|common.d.ts|
|Added|NA|Module name: common<br>Class name: ProgressMask|common.d.ts|
|Added|NA|Module name: common<br>Class name: ProgressMask<br>Method or attribute name: constructor(value: number, total: number, color: ResourceColor);|common.d.ts|
|Added|NA|Module name: common<br>Class name: ProgressMask<br>Method or attribute name: updateProgress(value: number): void;|common.d.ts|
|Added|NA|Module name: common<br>Class name: ProgressMask<br>Method or attribute name: updateColor(value: ResourceColor): void;|common.d.ts|
|Added|NA|Module name: common<br>Class name: PixelStretchEffectOptions|common.d.ts|
|Added|NA|Module name: common<br>Class name: PixelStretchEffectOptions<br>Method or attribute name: top?: Length;|common.d.ts|
|Added|NA|Module name: common<br>Class name: PixelStretchEffectOptions<br>Method or attribute name: bottom?: Length;|common.d.ts|
|Added|NA|Module name: common<br>Class name: PixelStretchEffectOptions<br>Method or attribute name: left?: Length;|common.d.ts|
|Added|NA|Module name: common<br>Class name: PixelStretchEffectOptions<br>Method or attribute name: right?: Length;|common.d.ts|
|Added|NA|Class name: CommonMethod<br>Method or attribute name: foregroundColor(value: ResourceColor \| ColoringStrategy): T;|common.d.ts|
|Added|NA|Class name: CommonMethod<br>Method or attribute name: onDragEnd(event: (event: DragEvent, extraParams?: string) => void): T;|common.d.ts|
|Added|NA|Class name: CommonMethod<br>Method or attribute name: allowDrop(value: Array\<UnifiedDataType>): T;|common.d.ts|
|Added|NA|Class name: CommonMethod<br>Method or attribute name: draggable(value: boolean): T;|common.d.ts|
|Added|NA|Class name: CommonMethod<br>Method or attribute name: bindContentCover(isShow: boolean, builder: CustomBuilder, type?: ModalTransition): T;|common.d.ts|
|Added|NA|Class name: CommonMethod<br>Method or attribute name: bindSheet(isShow: boolean, builder: CustomBuilder, style?: SheetStyle): T;|common.d.ts|
|Added|NA|Class name: CommonMethod<br>Method or attribute name: sphericalEffect(value: number): T;|common.d.ts|
|Added|NA|Class name: CommonMethod<br>Method or attribute name: lightUpEffect(value: number): T;|common.d.ts|
|Added|NA|Class name: CommonMethod<br>Method or attribute name: pixelStretchEffect(options: PixelStretchEffectOptions): T;|common.d.ts|
|Added|NA|Class name: CommonMethod<br>Method or attribute name: keyboardShortcut(value: string \| FunctionKey, keys: Array\<ModifierKey>, action?: () => void): T;|common.d.ts|
|Added|NA|Class name: CustomComponent<br>Method or attribute name: onRecycle?(params: { [key: string]: unknown }): void;|common.d.ts|
|Added|NA|Class name: SubscribedAbstractProperty<br>Method or attribute name: abstract aboutToBeDeleted(): void;|common_ts_ets_api.d.ts|
|Added|NA|Module name: counter<br>Class name: CounterAttribute<br>Method or attribute name: enableDec(value: boolean): CounterAttribute;|counter.d.ts|
|Added|NA|Module name: counter<br>Class name: CounterAttribute<br>Method or attribute name: enableInc(value: boolean): CounterAttribute;|counter.d.ts|
|Added|NA|Class name: CustomDialogControllerOptions<br>Method or attribute name: maskColor?: ResourceColor;|custom_dialog_controller.d.ts|
|Added|NA|Class name: CustomDialogControllerOptions<br>Method or attribute name: openAnimation?: AnimateParam;|custom_dialog_controller.d.ts|
|Added|NA|Class name: CustomDialogControllerOptions<br>Method or attribute name: closeAnimation?: AnimateParam;|custom_dialog_controller.d.ts|
|Added|NA|Class name: CustomDialogControllerOptions<br>Method or attribute name: showInSubWindow?: boolean;|custom_dialog_controller.d.ts|
|Added|NA|Module name: data_panel<br>Class name: LinearGradient|data_panel.d.ts|
|Added|NA|Module name: data_panel<br>Class name: LinearGradient<br>Method or attribute name: constructor(colorStops: ColorStop[]);|data_panel.d.ts|
|Added|NA|Module name: data_panel<br>Class name: DataPanelShadowOption|data_panel.d.ts|
|Added|NA|Module name: data_panel<br>Class name: DataPanelShadowOption<br>Method or attribute name: radius?: number \| Resource;|data_panel.d.ts|
|Added|NA|Module name: data_panel<br>Class name: DataPanelShadowOption<br>Method or attribute name: colors?: Array\<ResourceColor \| LinearGradient>;|data_panel.d.ts|
|Added|NA|Module name: data_panel<br>Class name: DataPanelShadowOption<br>Method or attribute name: offsetX?: number \| Resource;|data_panel.d.ts|
|Added|NA|Module name: data_panel<br>Class name: DataPanelShadowOption<br>Method or attribute name: offsetY?: number \| Resource;|data_panel.d.ts|
|Added|NA|Module name: data_panel<br>Class name: DataPanelAttribute<br>Method or attribute name: valueColors(value: Array\<ResourceColor \| LinearGradient>): DataPanelAttribute;|data_panel.d.ts|
|Added|NA|Module name: data_panel<br>Class name: DataPanelAttribute<br>Method or attribute name: trackBackgroundColor(value: ResourceColor): DataPanelAttribute;|data_panel.d.ts|
|Added|NA|Module name: data_panel<br>Class name: DataPanelAttribute<br>Method or attribute name: strokeWidth(value: Length): DataPanelAttribute;|data_panel.d.ts|
|Added|NA|Module name: data_panel<br>Class name: DataPanelAttribute<br>Method or attribute name: trackShadow(value: DataPanelShadowOption): DataPanelAttribute;|data_panel.d.ts|
|Added|NA|Class name: DatePickerAttribute<br>Method or attribute name: disappearTextStyle(value: PickerTextStyle): DatePickerAttribute;|date_picker.d.ts|
|Added|NA|Class name: DatePickerAttribute<br>Method or attribute name: textStyle(value: PickerTextStyle): DatePickerAttribute;|date_picker.d.ts|
|Added|NA|Class name: DatePickerAttribute<br>Method or attribute name: selectedTextStyle(value: PickerTextStyle): DatePickerAttribute;|date_picker.d.ts|
|Added|NA|Class name: DatePickerDialogOptions<br>Method or attribute name: showTime?: boolean;|date_picker.d.ts|
|Added|NA|Class name: DatePickerDialogOptions<br>Method or attribute name: useMilitaryTime?: boolean;|date_picker.d.ts|
|Added|NA|Class name: DatePickerDialogOptions<br>Method or attribute name: disappearTextStyle?: PickerTextStyle;|date_picker.d.ts|
|Added|NA|Class name: DatePickerDialogOptions<br>Method or attribute name: textStyle?: PickerTextStyle;|date_picker.d.ts|
|Added|NA|Class name: DatePickerDialogOptions<br>Method or attribute name: selectedTextStyle?: PickerTextStyle;|date_picker.d.ts|
|Added|NA|Module name: enums<br>Class name: ColoringStrategy|enums.d.ts|
|Added|NA|Module name: enums<br>Class name: ColoringStrategy<br>Method or attribute name: INVERT = "invert"|enums.d.ts|
|Added|NA|Module name: enums<br>Class name: TextAlign<br>Method or attribute name: Justify|enums.d.ts|
|Added|NA|Module name: enums<br>Class name: TextAlign<br>Method or attribute name: JUSTIFY|enums.d.ts|
|Added|NA|Module name: enums<br>Class name: TextOverflow<br>Method or attribute name: Marquee|enums.d.ts|
|Added|NA|Module name: enums<br>Class name: TextOverflow<br>Method or attribute name: MARQUEE|enums.d.ts|
|Added|NA|Module name: enums<br>Class name: TextHeightAdaptivePolicy|enums.d.ts|
|Added|NA|Module name: enums<br>Class name: TextHeightAdaptivePolicy<br>Method or attribute name: MAX_LINES_FIRST|enums.d.ts|
|Added|NA|Module name: enums<br>Class name: TextHeightAdaptivePolicy<br>Method or attribute name: MIN_FONT_SIZE_FIRST|enums.d.ts|
|Added|NA|Module name: enums<br>Class name: TextHeightAdaptivePolicy<br>Method or attribute name: LAYOUT_CONSTRAINT_FIRST|enums.d.ts|
|Added|NA|Module name: enums<br>Class name: ModifierKey|enums.d.ts|
|Added|NA|Module name: enums<br>Class name: ModifierKey<br>Method or attribute name: CTRL|enums.d.ts|
|Added|NA|Module name: enums<br>Class name: ModifierKey<br>Method or attribute name: SHIFT|enums.d.ts|
|Added|NA|Module name: enums<br>Class name: ModifierKey<br>Method or attribute name: ALT|enums.d.ts|
|Added|NA|Module name: enums<br>Class name: FunctionKey|enums.d.ts|
|Added|NA|Module name: enums<br>Class name: FunctionKey<br>Method or attribute name: ESC|enums.d.ts|
|Added|NA|Module name: enums<br>Class name: FunctionKey<br>Method or attribute name: F1|enums.d.ts|
|Added|NA|Module name: enums<br>Class name: FunctionKey<br>Method or attribute name: F2|enums.d.ts|
|Added|NA|Module name: enums<br>Class name: FunctionKey<br>Method or attribute name: F3|enums.d.ts|
|Added|NA|Module name: enums<br>Class name: FunctionKey<br>Method or attribute name: F4|enums.d.ts|
|Added|NA|Module name: enums<br>Class name: FunctionKey<br>Method or attribute name: F5|enums.d.ts|
|Added|NA|Module name: enums<br>Class name: FunctionKey<br>Method or attribute name: F6|enums.d.ts|
|Added|NA|Module name: enums<br>Class name: FunctionKey<br>Method or attribute name: F7|enums.d.ts|
|Added|NA|Module name: enums<br>Class name: FunctionKey<br>Method or attribute name: F8|enums.d.ts|
|Added|NA|Module name: enums<br>Class name: FunctionKey<br>Method or attribute name: F9|enums.d.ts|
|Added|NA|Module name: enums<br>Class name: FunctionKey<br>Method or attribute name: F10|enums.d.ts|
|Added|NA|Module name: enums<br>Class name: FunctionKey<br>Method or attribute name: F11|enums.d.ts|
|Added|NA|Module name: enums<br>Class name: FunctionKey<br>Method or attribute name: F12|enums.d.ts|
|Added|NA|Module name: enums<br>Class name: ImageSpanAlignment|enums.d.ts|
|Added|NA|Module name: enums<br>Class name: ImageSpanAlignment<br>Method or attribute name: BASELINE|enums.d.ts|
|Added|NA|Module name: enums<br>Class name: ImageSpanAlignment<br>Method or attribute name: BOTTOM|enums.d.ts|
|Added|NA|Module name: enums<br>Class name: ImageSpanAlignment<br>Method or attribute name: CENTER|enums.d.ts|
|Added|NA|Module name: enums<br>Class name: ImageSpanAlignment<br>Method or attribute name: TOP|enums.d.ts|
|Added|NA|Module name: form_component<br>Class name: FormComponentAttribute<br>Method or attribute name: onLoad(callback: () => void): FormComponentAttribute;|form_component.d.ts|
|Added|NA|Class name: GridAttribute<br>Method or attribute name: edgeEffect(value: EdgeEffect): GridAttribute;|grid.d.ts|
|Added|NA|Class name: GridRowAttribute<br>Method or attribute name: alignItems(value: ItemAlign): GridRowAttribute;|grid_row.d.ts|
|Added|NA|Class name: ImageAttribute<br>Method or attribute name: onError(callback: (event?: {<br>    /**<br>     * Component width.<br>     * @form<br>     * @crossplatform<br>     * @since 10<br>     */<br>    componentWidth: number;<br><br>    /**<br>     * Component height.<br>     * @form<br>     * @crossplatform<br>     * @since 10<br>     */<br>    componentHeight: number<br>  }) => void): ImageAttribute;|image.d.ts|
|Added|NA|Class name: ImageAttribute<br>Method or attribute name: onError(callback: (event?: {<br>    /**<br>     * Component width.<br>     * @form<br>     * @crossplatform<br>     * @since 10<br>     */<br>    componentWidth: number;<br><br>    /**<br>     * Component height.<br>     * @form<br>     * @crossplatform<br>     * @since 10<br>     */<br>    componentHeight: number;<br><br>    /**<br>     * Message.<br>     * @form<br>     * @crossplatform<br>     * @since 10<br>     */<br>    message: string<br>  }) => void): ImageAttribute;|image.d.ts|
|Added|NA|Module name: image_span<br>Class name: ImageSpanInterface|image_span.d.ts|
|Added|NA|Module name: image_span<br>Class name: ImageSpanInterface<br>Method or attribute name: (value: ResourceStr \| PixelMap): ImageSpanAttribute;|image_span.d.ts|
|Added|NA|Module name: image_span<br>Class name: ImageSpanAttribute|image_span.d.ts|
|Added|NA|Module name: image_span<br>Class name: ImageSpanAttribute<br>Method or attribute name: verticalAlign(value: ImageSpanAlignment): ImageSpanAttribute;|image_span.d.ts|
|Added|NA|Module name: image_span<br>Class name: ImageSpanAttribute<br>Method or attribute name: objectFit(value: ImageFit): ImageSpanAttribute;|image_span.d.ts|
|Added|NA|Module name: image_span<br>Class name: global<br>Method or attribute name: declare const ImageSpan: ImageSpanInterface;|image_span.d.ts|
|Added|NA|Module name: image_span<br>Class name: global<br>Method or attribute name: declare const ImageSpanInstance: ImageSpanAttribute;|image_span.d.ts|
|Added|NA|Module name: list<br>Class name: ChainEdgeEffect|list.d.ts|
|Added|NA|Module name: list<br>Class name: ChainEdgeEffect<br>Method or attribute name: DEFAULT|list.d.ts|
|Added|NA|Module name: list<br>Class name: ChainEdgeEffect<br>Method or attribute name: STRETCH|list.d.ts|
|Added|NA|Module name: list<br>Class name: ChainAnimationOptions|list.d.ts|
|Added|NA|Module name: list<br>Class name: ChainAnimationOptions<br>Method or attribute name: minSpace: Length;|list.d.ts|
|Added|NA|Module name: list<br>Class name: ChainAnimationOptions<br>Method or attribute name: maxSpace: Length;|list.d.ts|
|Added|NA|Module name: list<br>Class name: ChainAnimationOptions<br>Method or attribute name: conductivity?: number;|list.d.ts|
|Added|NA|Module name: list<br>Class name: ChainAnimationOptions<br>Method or attribute name: intensity?: number;|list.d.ts|
|Added|NA|Module name: list<br>Class name: ChainAnimationOptions<br>Method or attribute name: edgeEffect?: ChainEdgeEffect;|list.d.ts|
|Added|NA|Class name: ListAttribute<br>Method or attribute name: chainAnimationOptions(value: ChainAnimationOptions): ListAttribute;|list.d.ts|
|Added|NA|Module name: matrix2d<br>Class name: Matrix2D|matrix2d.d.ts|
|Added|NA|Module name: matrix2d<br>Class name: Matrix2D<br>Method or attribute name: scaleX?: number;|matrix2d.d.ts|
|Added|NA|Module name: matrix2d<br>Class name: Matrix2D<br>Method or attribute name: rotateY?: number;|matrix2d.d.ts|
|Added|NA|Module name: matrix2d<br>Class name: Matrix2D<br>Method or attribute name: rotateX?: number;|matrix2d.d.ts|
|Added|NA|Module name: matrix2d<br>Class name: Matrix2D<br>Method or attribute name: scaleY?: number;|matrix2d.d.ts|
|Added|NA|Module name: matrix2d<br>Class name: Matrix2D<br>Method or attribute name: translateX?: number;|matrix2d.d.ts|
|Added|NA|Module name: matrix2d<br>Class name: Matrix2D<br>Method or attribute name: translateY?: number;|matrix2d.d.ts|
|Added|NA|Module name: matrix2d<br>Class name: Matrix2D<br>Method or attribute name: identity(): Matrix2D;|matrix2d.d.ts|
|Added|NA|Module name: matrix2d<br>Class name: Matrix2D<br>Method or attribute name: invert(): Matrix2D;|matrix2d.d.ts|
|Added|NA|Module name: matrix2d<br>Class name: Matrix2D<br>Method or attribute name: multiply(other?: Matrix2D): Matrix2D;|matrix2d.d.ts|
|Added|NA|Module name: matrix2d<br>Class name: Matrix2D<br>Method or attribute name: rotate(rx?: number, ry?: number): Matrix2D;|matrix2d.d.ts|
|Added|NA|Module name: matrix2d<br>Class name: Matrix2D<br>Method or attribute name: rotate(degree: number, rx?: number, ry?: number): Matrix2D;|matrix2d.d.ts|
|Added|NA|Module name: matrix2d<br>Class name: Matrix2D<br>Method or attribute name: translate(tx?: number, ty?: number): Matrix2D;|matrix2d.d.ts|
|Added|NA|Module name: matrix2d<br>Class name: Matrix2D<br>Method or attribute name: scale(sx?: number, sy?: number): Matrix2D;|matrix2d.d.ts|
|Added|NA|Module name: matrix2d<br>Class name: Matrix2D<br>Method or attribute name: constructor();|matrix2d.d.ts|
|Added|NA|Class name: MenuAttribute<br>Method or attribute name: font(value: Font): MenuAttribute;|menu.d.ts|
|Added|NA|Class name: MenuAttribute<br>Method or attribute name: fontColor(value: ResourceColor): MenuAttribute;|menu.d.ts|
|Added|NA|Class name: MenuItemAttribute<br>Method or attribute name: contentFont(value: Font): MenuItemAttribute;|menu_item.d.ts|
|Added|NA|Class name: MenuItemAttribute<br>Method or attribute name: contentFontColor(value: ResourceColor): MenuItemAttribute;|menu_item.d.ts|
|Added|NA|Class name: MenuItemAttribute<br>Method or attribute name: labelFont(value: Font): MenuItemAttribute;|menu_item.d.ts|
|Added|NA|Class name: MenuItemAttribute<br>Method or attribute name: labelFontColor(value: ResourceColor): MenuItemAttribute;|menu_item.d.ts|
|Added|NA|Module name: navigation<br>Class name: NavPathInfo|navigation.d.ts|
|Added|NA|Module name: navigation<br>Class name: NavPathInfo<br>Method or attribute name: constructor(name: string, param: unknown);|navigation.d.ts|
|Added|NA|Module name: navigation<br>Class name: NavPathInfo<br>Method or attribute name: name: string;|navigation.d.ts|
|Added|NA|Module name: navigation<br>Class name: NavPathInfo<br>Method or attribute name: param?: unknown;|navigation.d.ts|
|Added|NA|Module name: navigation<br>Class name: NavPathStack|navigation.d.ts|
|Added|NA|Module name: navigation<br>Class name: NavPathStack<br>Method or attribute name: constructor();|navigation.d.ts|
|Added|NA|Module name: navigation<br>Class name: NavPathStack<br>Method or attribute name: push(info: NavPathInfo): void;|navigation.d.ts|
|Added|NA|Module name: navigation<br>Class name: NavPathStack<br>Method or attribute name: pushName(name: string, param: unknown): void;|navigation.d.ts|
|Added|NA|Module name: navigation<br>Class name: NavPathStack<br>Method or attribute name: pop(): NavPathInfo \| undefined;|navigation.d.ts|
|Added|NA|Module name: navigation<br>Class name: NavPathStack<br>Method or attribute name: popTo(name: string): number;|navigation.d.ts|
|Added|NA|Module name: navigation<br>Class name: NavPathStack<br>Method or attribute name: popToIndex(index: number): void;|navigation.d.ts|
|Added|NA|Module name: navigation<br>Class name: NavPathStack<br>Method or attribute name: moveToTop(name: string): number;|navigation.d.ts|
|Added|NA|Module name: navigation<br>Class name: NavPathStack<br>Method or attribute name: moveIndexToTop(index: number): void;|navigation.d.ts|
|Added|NA|Module name: navigation<br>Class name: NavPathStack<br>Method or attribute name: clear(): void;|navigation.d.ts|
|Added|NA|Module name: navigation<br>Class name: NavPathStack<br>Method or attribute name: getAllPathName(): Array\<string>;|navigation.d.ts|
|Added|NA|Module name: navigation<br>Class name: NavPathStack<br>Method or attribute name: getParamByIndex(index: number): unknown \| undefined;|navigation.d.ts|
|Added|NA|Module name: navigation<br>Class name: NavPathStack<br>Method or attribute name: getParamByName(name: string): Array\<unknown>;|navigation.d.ts|
|Added|NA|Module name: navigation<br>Class name: NavPathStack<br>Method or attribute name: getIndexByName(name: string): Array\<number>;|navigation.d.ts|
|Added|NA|Module name: navigation<br>Class name: NavPathStack<br>Method or attribute name: size(): number;|navigation.d.ts|
|Added|NA|Class name: NavigationInterface<br>Method or attribute name: (pathInfos: NavPathStack): NavigationAttribute;|navigation.d.ts|
|Added|NA|Class name: NavigationAttribute<br>Method or attribute name: navDestination(builder: (name: string, param: unknown) => void): NavigationAttribute;|navigation.d.ts|
|Added|NA|Class name: NavDestinationAttribute<br>Method or attribute name: onShown(callback: (param: unknown) => void): NavDestinationAttribute;|nav_destination.d.ts|
|Added|NA|Class name: NavDestinationAttribute<br>Method or attribute name: onHidden(callback: () => void): NavDestinationAttribute;|nav_destination.d.ts|
|Added|NA|Class name: NavDestinationAttribute<br>Method or attribute name: onBackPressed(callback: () => boolean): NavDestinationAttribute;|nav_destination.d.ts|
|Added|NA|Module name: nav_router<br>Class name: RouteInfo|nav_router.d.ts|
|Added|NA|Module name: nav_router<br>Class name: RouteInfo<br>Method or attribute name: name: string;|nav_router.d.ts|
|Added|NA|Module name: nav_router<br>Class name: RouteInfo<br>Method or attribute name: param?: unknown;|nav_router.d.ts|
|Added|NA|Class name: NavRouterInterface<br>Method or attribute name: (value: RouteInfo): NavRouterAttribute;|nav_router.d.ts|
|Added|NA|Module name: nav_router<br>Class name: NavRouteMode|nav_router.d.ts|
|Added|NA|Module name: nav_router<br>Class name: NavRouteMode<br>Method or attribute name: PUSH_WITH_RECREATE|nav_router.d.ts|
|Added|NA|Module name: nav_router<br>Class name: NavRouteMode<br>Method or attribute name: PUSH|nav_router.d.ts|
|Added|NA|Module name: nav_router<br>Class name: NavRouteMode<br>Method or attribute name: REPLACE|nav_router.d.ts|
|Added|NA|Class name: NavRouterAttribute<br>Method or attribute name: mode(mode: NavRouteMode): NavRouterAttribute;|nav_router.d.ts|
|Added|NA|Module name: radio<br>Class name: RadioStyle|radio.d.ts|
|Added|NA|Module name: radio<br>Class name: RadioStyle<br>Method or attribute name: checkedBackgroundColor?: ResourceColor;|radio.d.ts|
|Added|NA|Module name: radio<br>Class name: RadioStyle<br>Method or attribute name: uncheckedBorderColor?: ResourceColor;|radio.d.ts|
|Added|NA|Module name: radio<br>Class name: RadioStyle<br>Method or attribute name: indicatorColor?: ResourceColor;|radio.d.ts|
|Added|NA|Module name: radio<br>Class name: RadioAttribute<br>Method or attribute name: radioStyle(value?: RadioStyle): RadioAttribute;|radio.d.ts|
|Added|NA|Module name: refresh<br>Class name: RefreshOptions|refresh.d.ts|
|Added|NA|Module name: refresh<br>Class name: RefreshOptions<br>Method or attribute name: refreshing: boolean;|refresh.d.ts|
|Added|NA|Module name: refresh<br>Class name: RefreshOptions<br>Method or attribute name: offset?: number \| string;|refresh.d.ts|
|Added|NA|Module name: refresh<br>Class name: RefreshOptions<br>Method or attribute name: friction?: number \| string;|refresh.d.ts|
|Added|NA|Module name: refresh<br>Class name: RefreshOptions<br>Method or attribute name: builder?: CustomBuilder;|refresh.d.ts|
|Added|NA|Module name: search<br>Class name: CancelButtonStyle|search.d.ts|
|Added|NA|Module name: search<br>Class name: CancelButtonStyle<br>Method or attribute name: CONSTANT|search.d.ts|
|Added|NA|Module name: search<br>Class name: CancelButtonStyle<br>Method or attribute name: INVISIBLE|search.d.ts|
|Added|NA|Module name: search<br>Class name: CancelButtonStyle<br>Method or attribute name: INPUT|search.d.ts|
|Added|NA|Module name: search<br>Class name: IconOptions|search.d.ts|
|Added|NA|Module name: search<br>Class name: IconOptions<br>Method or attribute name: size?: Length;|search.d.ts|
|Added|NA|Module name: search<br>Class name: IconOptions<br>Method or attribute name: color?: ResourceColor;|search.d.ts|
|Added|NA|Module name: search<br>Class name: IconOptions<br>Method or attribute name: src?: ResourceStr;|search.d.ts|
|Added|NA|Module name: search<br>Class name: CaretStyle|search.d.ts|
|Added|NA|Module name: search<br>Class name: CaretStyle<br>Method or attribute name: width?: Length,|search.d.ts|
|Added|NA|Module name: search<br>Class name: CaretStyle<br>Method or attribute name: color?: ResourceColor,|search.d.ts|
|Added|NA|Module name: search<br>Class name: SearchButtonOption|search.d.ts|
|Added|NA|Module name: search<br>Class name: SearchButtonOption<br>Method or attribute name: fontSize?: Length;|search.d.ts|
|Added|NA|Module name: search<br>Class name: SearchButtonOption<br>Method or attribute name: fontColor?: ResourceColor;|search.d.ts|
|Added|NA|Class name: SearchAttribute<br>Method or attribute name: fontColor(value: ResourceColor): SearchAttribute;|search.d.ts|
|Added|NA|Class name: SearchAttribute<br>Method or attribute name: searchIcon(value: IconOptions): SearchAttribute;|search.d.ts|
|Added|NA|Class name: SearchAttribute<br>Method or attribute name: cancelButton(value: { style?: CancelButtonStyle, icon?: IconOptions }): SearchAttribute;|search.d.ts|
|Added|NA|Class name: SearchAttribute<br>Method or attribute name: caretStyle(value: CaretStyle): SearchAttribute;|search.d.ts|
|Added|NA|Class name: SearchAttribute<br>Method or attribute name: enableKeyboardOnFocus(value: boolean): SearchAttribute;|search.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: SecLocationButtonLayoutDirection|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: SecLocationButtonLayoutDirection<br>Method or attribute name: HORIZONTAL = 0|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: SecLocationButtonLayoutDirection<br>Method or attribute name: VERTICAL = 1|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: SecLocationButtonLayoutOrder|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: SecLocationButtonLayoutOrder<br>Method or attribute name: ICON_FIRST = 0|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: SecLocationButtonLayoutOrder<br>Method or attribute name: TEXT_FIRST = 1|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: LocationIconStyle|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: LocationIconStyle<br>Method or attribute name: FULL_FILLED = 0|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: LocationIconStyle<br>Method or attribute name: LINES = 1|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: LocationDescription|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: LocationDescription<br>Method or attribute name: CURRENT_LOCATION = 0|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: LocationDescription<br>Method or attribute name: ADD_LOCATION = 1|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: LocationDescription<br>Method or attribute name: SELECT_LOCATION = 2|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: LocationDescription<br>Method or attribute name: SHARE_LOCATION = 3|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: LocationDescription<br>Method or attribute name: SEND_LOCATION = 4|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: LocationDescription<br>Method or attribute name: LOCATING = 5|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: LocationDescription<br>Method or attribute name: LOCATION = 6|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: LocationDescription<br>Method or attribute name: SEND_CURRENT_LOCATION = 7|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: LocationDescription<br>Method or attribute name: RELOCATION = 8|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: LocationDescription<br>Method or attribute name: PUNCH_IN = 9|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: LocationDescription<br>Method or attribute name: CURRENT_POSITION = 10|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: BackgroundButtonType|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: BackgroundButtonType<br>Method or attribute name: CAPSULE_BACKGROUND = 0|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: BackgroundButtonType<br>Method or attribute name: CIRCLE_BACKGROUND = 1|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: BackgroundButtonType<br>Method or attribute name: NORMAL_BACKGROUND = 2|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: SecLocationButtonOptions|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: SecLocationButtonOptions<br>Method or attribute name: icon?: LocationIconStyle;|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: SecLocationButtonOptions<br>Method or attribute name: text?: LocationDescription;|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: SecLocationButtonOptions<br>Method or attribute name: background?: BackgroundButtonType;|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: SecLocationButtonOnClickResult|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: SecLocationButtonOnClickResult<br>Method or attribute name: LOCATION_BUTTON_CLICK_SUCCESS = 0|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: SecLocationButtonOnClickResult<br>Method or attribute name: LOCATION_BUTTON_CLICK_GRANT_FAILED = 1|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: SecLocationButtonInterface|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: SecLocationButtonInterface<br>Method or attribute name: (): SecLocationButtonAttribute;|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: SecLocationButtonInterface<br>Method or attribute name: (option: SecLocationButtonOptions): SecLocationButtonAttribute;|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: SecLocationButtonAttribute|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: SecLocationButtonAttribute<br>Method or attribute name: iconSize(value: Length): SecLocationButtonAttribute;|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: SecLocationButtonAttribute<br>Method or attribute name: layoutDirection(value: SecLocationButtonLayoutDirection): SecLocationButtonAttribute;|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: SecLocationButtonAttribute<br>Method or attribute name: layoutOrder(value: SecLocationButtonLayoutOrder): SecLocationButtonAttribute;|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: SecLocationButtonAttribute<br>Method or attribute name: position(value: Position): SecLocationButtonAttribute;|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: SecLocationButtonAttribute<br>Method or attribute name: markAnchor(value: Position): SecLocationButtonAttribute;|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: SecLocationButtonAttribute<br>Method or attribute name: offset(value: Position): SecLocationButtonAttribute;|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: SecLocationButtonAttribute<br>Method or attribute name: fontSize(value: Length): SecLocationButtonAttribute;|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: SecLocationButtonAttribute<br>Method or attribute name: fontStyle(value: FontStyle): SecLocationButtonAttribute;|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: SecLocationButtonAttribute<br>Method or attribute name: fontWeight(value: number \| FontWeight \| string): SecLocationButtonAttribute;|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: SecLocationButtonAttribute<br>Method or attribute name: fontFamily(value: string \| Resource): SecLocationButtonAttribute;|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: SecLocationButtonAttribute<br>Method or attribute name: fontColor(value: ResourceColor): SecLocationButtonAttribute;|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: SecLocationButtonAttribute<br>Method or attribute name: iconColor(value: ResourceColor): SecLocationButtonAttribute;|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: SecLocationButtonAttribute<br>Method or attribute name: backgroundColor(value: ResourceColor): SecLocationButtonAttribute;|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: SecLocationButtonAttribute<br>Method or attribute name: borderStyle(value: BorderStyle): SecLocationButtonAttribute;|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: SecLocationButtonAttribute<br>Method or attribute name: borderWidth(value: Length): SecLocationButtonAttribute;|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: SecLocationButtonAttribute<br>Method or attribute name: borderColor(value: ResourceColor): SecLocationButtonAttribute;|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: SecLocationButtonAttribute<br>Method or attribute name: borderRadius(value: Length): SecLocationButtonAttribute;|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: SecLocationButtonAttribute<br>Method or attribute name: backgroundPadding(value: Padding \| Length): SecLocationButtonAttribute;|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: SecLocationButtonAttribute<br>Method or attribute name: textIconPadding(value: Length): SecLocationButtonAttribute;|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: SecLocationButtonAttribute<br>Method or attribute name: onClick(event: (result: SecLocationButtonOnClickResult, event?: ClickEvent) => void): SecLocationButtonAttribute;|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: global<br>Method or attribute name: declare const SecLocationButton: SecLocationButtonInterface;|sec_location_button.d.ts|
|Added|NA|Module name: sec_location_button<br>Class name: global<br>Method or attribute name: declare const SecLocationButtonInstance: SecLocationButtonAttribute;|sec_location_button.d.ts|
|Added|NA|Module name: select<br>Class name: ArrowPosition|select.d.ts|
|Added|NA|Module name: select<br>Class name: ArrowPosition<br>Method or attribute name: END = 0|select.d.ts|
|Added|NA|Module name: select<br>Class name: ArrowPosition<br>Method or attribute name: START = 1|select.d.ts|
|Added|NA|Class name: SelectAttribute<br>Method or attribute name: space(value: Length): SelectAttribute;|select.d.ts|
|Added|NA|Class name: SelectAttribute<br>Method or attribute name: arrowPosition(value: ArrowPosition): SelectAttribute;|select.d.ts|
|Added|NA|Module name: sidebar<br>Class name: DividerStyle|sidebar.d.ts|
|Added|NA|Module name: sidebar<br>Class name: DividerStyle<br>Method or attribute name: strokeWidth: Length;|sidebar.d.ts|
|Added|NA|Module name: sidebar<br>Class name: DividerStyle<br>Method or attribute name: color?: ResourceColor;|sidebar.d.ts|
|Added|NA|Module name: sidebar<br>Class name: DividerStyle<br>Method or attribute name: startMargin?: Length;|sidebar.d.ts|
|Added|NA|Module name: sidebar<br>Class name: DividerStyle<br>Method or attribute name: endMargin?: Length;|sidebar.d.ts|
|Added|NA|Class name: SideBarContainerAttribute<br>Method or attribute name: divider(value: DividerStyle \| null): SideBarContainerAttribute;|sidebar.d.ts|
|Added|NA|Module name: slider<br>Class name: SliderBlockType|slider.d.ts|
|Added|NA|Module name: slider<br>Class name: SliderBlockType<br>Method or attribute name: DEFAULT|slider.d.ts|
|Added|NA|Module name: slider<br>Class name: SliderBlockType<br>Method or attribute name: IMAGE|slider.d.ts|
|Added|NA|Module name: slider<br>Class name: SliderBlockType<br>Method or attribute name: SHAPE|slider.d.ts|
|Added|NA|Module name: slider<br>Class name: SliderBlockStyle|slider.d.ts|
|Added|NA|Module name: slider<br>Class name: SliderBlockStyle<br>Method or attribute name: type: SliderBlockType;|slider.d.ts|
|Added|NA|Module name: slider<br>Class name: SliderBlockStyle<br>Method or attribute name: image?: ResourceStr;|slider.d.ts|
|Added|NA|Module name: slider<br>Class name: SliderBlockStyle<br>Method or attribute name: shape?: CircleAttribute \| EllipseAttribute \| PathAttribute \| RectAttribute;|slider.d.ts|
|Added|NA|Module name: slider<br>Class name: SliderAttribute<br>Method or attribute name: blockBorderColor(value: ResourceColor): SliderAttribute;|slider.d.ts|
|Added|NA|Module name: slider<br>Class name: SliderAttribute<br>Method or attribute name: blockBorderWidth(value: Length): SliderAttribute;|slider.d.ts|
|Added|NA|Module name: slider<br>Class name: SliderAttribute<br>Method or attribute name: stepColor(value: ResourceColor): SliderAttribute;|slider.d.ts|
|Added|NA|Module name: slider<br>Class name: SliderAttribute<br>Method or attribute name: trackBorderRadius(value: Length): SliderAttribute;|slider.d.ts|
|Added|NA|Module name: slider<br>Class name: SliderAttribute<br>Method or attribute name: blockSize(value: SizeOptions): SliderAttribute;|slider.d.ts|
|Added|NA|Module name: slider<br>Class name: SliderAttribute<br>Method or attribute name: blockStyle(value: SliderBlockStyle): SliderAttribute;|slider.d.ts|
|Added|NA|Module name: slider<br>Class name: SliderAttribute<br>Method or attribute name: stepSize(value: Length): SliderAttribute;|slider.d.ts|
|Added|NA|Module name: swiper<br>Class name: Indicator|swiper.d.ts|
|Added|NA|Module name: swiper<br>Class name: Indicator<br>Method or attribute name: left(value: Length): T;|swiper.d.ts|
|Added|NA|Module name: swiper<br>Class name: Indicator<br>Method or attribute name: top(value: Length): T;|swiper.d.ts|
|Added|NA|Module name: swiper<br>Class name: Indicator<br>Method or attribute name: right(value: Length): T;|swiper.d.ts|
|Added|NA|Module name: swiper<br>Class name: Indicator<br>Method or attribute name: bottom(value: Length): T;|swiper.d.ts|
|Added|NA|Module name: swiper<br>Class name: Indicator<br>Method or attribute name: static dot(): DotIndicator;|swiper.d.ts|
|Added|NA|Module name: swiper<br>Class name: Indicator<br>Method or attribute name: static digit(): DigitIndicator;|swiper.d.ts|
|Added|NA|Module name: swiper<br>Class name: DotIndicator|swiper.d.ts|
|Added|NA|Module name: swiper<br>Class name: DotIndicator<br>Method or attribute name: constructor();|swiper.d.ts|
|Added|NA|Module name: swiper<br>Class name: DotIndicator<br>Method or attribute name: itemWidth(value: Length): DotIndicator;|swiper.d.ts|
|Added|NA|Module name: swiper<br>Class name: DotIndicator<br>Method or attribute name: itemHeight(value: Length): DotIndicator;|swiper.d.ts|
|Added|NA|Module name: swiper<br>Class name: DotIndicator<br>Method or attribute name: selectedItemWidth(value: Length): DotIndicator;|swiper.d.ts|
|Added|NA|Module name: swiper<br>Class name: DotIndicator<br>Method or attribute name: selectedItemHeight(value: Length): DotIndicator;|swiper.d.ts|
|Added|NA|Module name: swiper<br>Class name: DotIndicator<br>Method or attribute name: mask(value: boolean): DotIndicator;|swiper.d.ts|
|Added|NA|Module name: swiper<br>Class name: DotIndicator<br>Method or attribute name: color(value: ResourceColor): DotIndicator;|swiper.d.ts|
|Added|NA|Module name: swiper<br>Class name: DotIndicator<br>Method or attribute name: selectedColor(value: ResourceColor): DotIndicator;|swiper.d.ts|
|Added|NA|Module name: swiper<br>Class name: DigitIndicator|swiper.d.ts|
|Added|NA|Module name: swiper<br>Class name: DigitIndicator<br>Method or attribute name: constructor();|swiper.d.ts|
|Added|NA|Module name: swiper<br>Class name: DigitIndicator<br>Method or attribute name: fontColor(value: ResourceColor): DigitIndicator;|swiper.d.ts|
|Added|NA|Module name: swiper<br>Class name: DigitIndicator<br>Method or attribute name: selectedFontColor(value: ResourceColor): DigitIndicator;|swiper.d.ts|
|Added|NA|Module name: swiper<br>Class name: DigitIndicator<br>Method or attribute name: digitFont(value: Font): DigitIndicator;|swiper.d.ts|
|Added|NA|Module name: swiper<br>Class name: DigitIndicator<br>Method or attribute name: selectedDigitFont(value: Font): DigitIndicator;|swiper.d.ts|
|Added|NA|Class name: SwiperDisplayMode<br>Method or attribute name: STRETCH|swiper.d.ts|
|Added|NA|Class name: SwiperDisplayMode<br>Method or attribute name: AUTO_LINEAR|swiper.d.ts|
|Added|NA|Class name: SwiperAttribute<br>Method or attribute name: prevMargin(value: Length): SwiperAttribute;|swiper.d.ts|
|Added|NA|Class name: SwiperAttribute<br>Method or attribute name: nextMargin(value: Length): SwiperAttribute;|swiper.d.ts|
|Added|NA|Module name: tabs<br>Class name: DividerStyle|tabs.d.ts|
|Added|NA|Module name: tabs<br>Class name: DividerStyle<br>Method or attribute name: strokeWidth: Length;|tabs.d.ts|
|Added|NA|Module name: tabs<br>Class name: DividerStyle<br>Method or attribute name: color?: ResourceColor;|tabs.d.ts|
|Added|NA|Module name: tabs<br>Class name: DividerStyle<br>Method or attribute name: startMargin?: Length;|tabs.d.ts|
|Added|NA|Module name: tabs<br>Class name: DividerStyle<br>Method or attribute name: endMargin?: Length;|tabs.d.ts|
|Added|NA|Class name: TabsAttribute<br>Method or attribute name: fadingEdge(value: boolean): TabsAttribute;|tabs.d.ts|
|Added|NA|Class name: TabsAttribute<br>Method or attribute name: divider(value: DividerStyle \| null): TabsAttribute;|tabs.d.ts|
|Added|NA|Module name: tab_content<br>Class name: SelectedMode|tab_content.d.ts|
|Added|NA|Module name: tab_content<br>Class name: SelectedMode<br>Method or attribute name: INDICATOR|tab_content.d.ts|
|Added|NA|Module name: tab_content<br>Class name: SelectedMode<br>Method or attribute name: BOARD|tab_content.d.ts|
|Added|NA|Module name: tab_content<br>Class name: IndicatorStyle|tab_content.d.ts|
|Added|NA|Module name: tab_content<br>Class name: IndicatorStyle<br>Method or attribute name: color?: ResourceColor;|tab_content.d.ts|
|Added|NA|Module name: tab_content<br>Class name: IndicatorStyle<br>Method or attribute name: height?: Length;|tab_content.d.ts|
|Added|NA|Module name: tab_content<br>Class name: IndicatorStyle<br>Method or attribute name: width?: Length;|tab_content.d.ts|
|Added|NA|Module name: tab_content<br>Class name: IndicatorStyle<br>Method or attribute name: borderRadius?: Length;|tab_content.d.ts|
|Added|NA|Module name: tab_content<br>Class name: IndicatorStyle<br>Method or attribute name: marginTop?: Length;|tab_content.d.ts|
|Added|NA|Module name: tab_content<br>Class name: BoardStyle|tab_content.d.ts|
|Added|NA|Module name: tab_content<br>Class name: BoardStyle<br>Method or attribute name: borderRadius?: Length;|tab_content.d.ts|
|Added|NA|Module name: tab_content<br>Class name: LabelStyle|tab_content.d.ts|
|Added|NA|Module name: tab_content<br>Class name: LabelStyle<br>Method or attribute name: overflow?: TextOverflow;|tab_content.d.ts|
|Added|NA|Module name: tab_content<br>Class name: LabelStyle<br>Method or attribute name: maxLines?: number;|tab_content.d.ts|
|Added|NA|Module name: tab_content<br>Class name: LabelStyle<br>Method or attribute name: minFontSize?: number \| ResourceStr;|tab_content.d.ts|
|Added|NA|Module name: tab_content<br>Class name: LabelStyle<br>Method or attribute name: maxFontSize?: number \| ResourceStr;|tab_content.d.ts|
|Added|NA|Module name: tab_content<br>Class name: LabelStyle<br>Method or attribute name: heightAdaptivePolicy?: TextHeightAdaptivePolicy;|tab_content.d.ts|
|Added|NA|Module name: tab_content<br>Class name: LabelStyle<br>Method or attribute name: font?: Font;|tab_content.d.ts|
|Added|NA|Class name: SubTabBarStyle<br>Method or attribute name: static of(content: ResourceStr): SubTabBarStyle;|tab_content.d.ts|
|Added|NA|Class name: SubTabBarStyle<br>Method or attribute name: selectedMode(value: SelectedMode): SubTabBarStyle;|tab_content.d.ts|
|Added|NA|Class name: SubTabBarStyle<br>Method or attribute name: board(value: BoardStyle): SubTabBarStyle;|tab_content.d.ts|
|Added|NA|Class name: SubTabBarStyle<br>Method or attribute name: labelStyle(value: LabelStyle): SubTabBarStyle;|tab_content.d.ts|
|Added|NA|Class name: BottomTabBarStyle<br>Method or attribute name: static of(icon: ResourceStr, text: ResourceStr): BottomTabBarStyle;|tab_content.d.ts|
|Added|NA|Class name: TextAttribute<br>Method or attribute name: draggable(value: boolean): TextAttribute;|text.d.ts|
|Added|NA|Class name: TextAttribute<br>Method or attribute name: textShadow(value: ShadowOptions): TextAttribute;|text.d.ts|
|Added|NA|Class name: TextAttribute<br>Method or attribute name: heightAdaptivePolicy(value: TextHeightAdaptivePolicy): TextAttribute;|text.d.ts|
|Added|NA|Class name: TextAttribute<br>Method or attribute name: textIndent(value: Length): TextAttribute;|text.d.ts|
|Added|NA|Class name: TextAreaController<br>Method or attribute name: setTextSelection(selectionStart: number, selectionEnd: number): void;|text_area.d.ts|
|Added|NA|Class name: TextAreaAttribute<br>Method or attribute name: onEditChange(callback: (isEditing: boolean) => void): TextAreaAttribute;|text_area.d.ts|
|Added|NA|Class name: TextAreaAttribute<br>Method or attribute name: enableKeyboardOnFocus(value: boolean): TextAreaInterface;|text_area.d.ts|
|Added|NA|Class name: TextInputController<br>Method or attribute name: setTextSelection(selectionStart: number, selectionEnd: number): void;|text_input.d.ts|
|Added|NA|Module name: text_input<br>Class name: CaretStyle|text_input.d.ts|
|Added|NA|Module name: text_input<br>Class name: CaretStyle<br>Method or attribute name: width?: Length;|text_input.d.ts|
|Added|NA|Class name: TextInputAttribute<br>Method or attribute name: caretStyle(value: CaretStyle): TextInputAttribute;|text_input.d.ts|
|Added|NA|Class name: TextInputAttribute<br>Method or attribute name: selectedBackgroundColor(value: ResourceColor): TextInputAttribute;|text_input.d.ts|
|Added|NA|Class name: TextInputAttribute<br>Method or attribute name: caretPosition(value: number): TextInputAttribute;|text_input.d.ts|
|Added|NA|Class name: TextInputAttribute<br>Method or attribute name: enableKeyboardOnFocus(value: boolean): TextInputAttribute;|text_input.d.ts|
|Added|NA|Module name: text_picker<br>Class name: TextPickerRangeContent|text_picker.d.ts|
|Added|NA|Module name: text_picker<br>Class name: TextPickerRangeContent<br>Method or attribute name: icon: string \| Resource;|text_picker.d.ts|
|Added|NA|Module name: text_picker<br>Class name: TextPickerRangeContent<br>Method or attribute name: text?: string \| Resource;|text_picker.d.ts|
|Added|NA|Class name: TextPickerOptions<br>Method or attribute name: range: string[] \| Resource \| TextPickerRangeContent[];|text_picker.d.ts|
|Added|NA|Class name: TextPickerAttribute<br>Method or attribute name: disappearTextStyle(value: PickerTextStyle): TextPickerAttribute;|text_picker.d.ts|
|Added|NA|Class name: TextPickerAttribute<br>Method or attribute name: textStyle(value: PickerTextStyle): TextPickerAttribute;|text_picker.d.ts|
|Added|NA|Class name: TextPickerAttribute<br>Method or attribute name: selectedTextStyle(value: PickerTextStyle): TextPickerAttribute;|text_picker.d.ts|
|Added|NA|Class name: TextPickerDialogOptions<br>Method or attribute name: disappearTextStyle?: PickerTextStyle;|text_picker.d.ts|
|Added|NA|Class name: TextPickerDialogOptions<br>Method or attribute name: textStyle?: PickerTextStyle;|text_picker.d.ts|
|Added|NA|Class name: TextPickerDialogOptions<br>Method or attribute name: selectedTextStyle?: PickerTextStyle;|text_picker.d.ts|
|Added|NA|Class name: TimePickerAttribute<br>Method or attribute name: disappearTextStyle(value: PickerTextStyle): TimePickerAttribute;|time_picker.d.ts|
|Added|NA|Class name: TimePickerAttribute<br>Method or attribute name: textStyle(value: PickerTextStyle): TimePickerAttribute;|time_picker.d.ts|
|Added|NA|Class name: TimePickerAttribute<br>Method or attribute name: selectedTextStyle(value: PickerTextStyle): TimePickerAttribute;|time_picker.d.ts|
|Added|NA|Class name: TimePickerDialogOptions<br>Method or attribute name: disappearTextStyle?: PickerTextStyle;|time_picker.d.ts|
|Added|NA|Class name: TimePickerDialogOptions<br>Method or attribute name: textStyle?: PickerTextStyle;|time_picker.d.ts|
|Added|NA|Class name: TimePickerDialogOptions<br>Method or attribute name: selectedTextStyle?: PickerTextStyle;|time_picker.d.ts|
|Added|NA|Module name: units<br>Class name: MarkStyle|units.d.ts|
|Added|NA|Module name: units<br>Class name: MarkStyle<br>Method or attribute name: strokeColor?: ResourceColor;|units.d.ts|
|Added|NA|Module name: units<br>Class name: MarkStyle<br>Method or attribute name: size?: Length;|units.d.ts|
|Added|NA|Module name: units<br>Class name: MarkStyle<br>Method or attribute name: strokeWidth?: Length;|units.d.ts|
|Added|NA|Module name: web<br>Class name: WebMediaOptions|web.d.ts|
|Added|NA|Module name: web<br>Class name: WebMediaOptions<br>Method or attribute name: resumeInterval?: number;|web.d.ts|
|Added|NA|Module name: web<br>Class name: WebMediaOptions<br>Method or attribute name: audioExclusive?: boolean;|web.d.ts|
|Added|NA|Class name: ClientAuthenticationHandler<br>Method or attribute name: confirm(authUri: string): void;|web.d.ts|
|Added|NA|Class name: WebAttribute<br>Method or attribute name: mediaOptions(options: WebMediaOptions): WebAttribute;|web.d.ts|
|Added|NA|Class name: WebAttribute<br>Method or attribute name: allowWindowOpenMethod(flag: boolean): WebAttribute;|web.d.ts|
|Added|NA|Class name: WebAttribute<br>Method or attribute name: onAudioStateChanged(callback: (event: { playing: boolean }) => void): WebAttribute;|web.d.ts|
|Added|NA|Class name: WebAttribute<br>Method or attribute name: onFirstContentfulPaint(callback: (event?: { navigationStartTick: number,<br>    firstContentfulPaintMs: number }) => void): WebAttribute;|web.d.ts|
|Added|NA|Class name: WebAttribute<br>Method or attribute name: onLoadIntercept(callback: (event: { data: WebResourceRequest }) => boolean): WebAttribute;|web.d.ts|
|Deleted|Module name: common<br>Class name: SourceTool<br>Method or attribute name: FINGER|NA|common.d.ts|
|Deleted|Module name: common<br>Class name: SourceTool<br>Method or attribute name: PEN|NA|common.d.ts|
|Access level changed|Class name: BlurStyle<br>Access level: system API|Class name: BlurStyle<br>Access level: public API|common.d.ts|
|Access level changed|Class name: SubscribedAbstractProperty<br>Method or attribute name: info(): string;<br>Access level: system API|Class name: SubscribedAbstractProperty<br>Method or attribute name: info(): string;<br>Access level: public API|common_ts_ets_api.d.ts|
|Deprecated version changed|Class name: ShowToastOptions<br>Deprecated version: N/A|Class name: ShowToastOptions<br>Deprecated version: 8<br>Substitute API: ohos.prompt |@system.prompt.d.ts|
|Deprecated version changed|Class name: TransitionOptions<br>Deprecated version: N/A|Class name: TransitionOptions<br>Deprecated version: 10<br>Substitute API: TransitionEffect |common.d.ts|
|Deprecated version changed|Class name: PopupOptions<br>Method or attribute name: placementOnTop?: boolean;<br>Deprecated version: N/A|Class name: PopupOptions<br>Method or attribute name: placementOnTop?: boolean;<br>Deprecated version: 10<br>Substitute API: PopupOptions#placement|common.d.ts|
|Deprecated version changed|Class name: CustomPopupOptions<br>Method or attribute name: maskColor?: Color \| string \| Resource \| number;<br>Deprecated version: N/A|Class name: CustomPopupOptions<br>Method or attribute name: maskColor?: Color \| string \| Resource \| number;<br>Deprecated version: 10<br>Substitute API: CustomPopupOptions#mask|common.d.ts|
|Deprecated version changed|Class name: CommonMethod<br>Method or attribute name: useSizeType(value: {<br>    xs?: number \| { span: number; offset: number };<br>    sm?: number \| { span: number; offset: number };<br>    md?: number \| { span: number; offset: number };<br>    lg?: number \| { span: number; offset: number };<br>  }): T;<br>Deprecated version: N/A|Class name: CommonMethod<br>Method or attribute name: useSizeType(value: {<br>    xs?: number \| { span: number; offset: number };<br>    sm?: number \| { span: number; offset: number };<br>    md?: number \| { span: number; offset: number };<br>    lg?: number \| { span: number; offset: number };<br>  }): T;<br>Deprecated version: 9<br>Substitute API: grid_col/[GridColColumnOption] and grid_row/[GridRowColumnOption]|common.d.ts|
|Deprecated version changed|Class name: SizeType<br>Deprecated version: N/A|Class name: SizeType<br>Deprecated version: 9<br>Substitute API: grid_col/[GridColColumnOption] and grid_row/[GridRowColumnOption]|grid_container.d.ts|
|Deprecated version changed|Class name: GridContainerOptions<br>Deprecated version: N/A|Class name: GridContainerOptions<br>Deprecated version: 9<br>Substitute API: grid_col/[GridColOptions] and grid_row/[GridRowOptions]|grid_container.d.ts|
|Deprecated version changed|Class name: GridContainerOptions<br>Method or attribute name: columns?: number \| "auto";<br>Deprecated version: N/A|Class name: GridContainerOptions<br>Method or attribute name: columns?: number \| "auto";<br>Deprecated version: 9<br>Substitute API: N/A|grid_container.d.ts|
|Deprecated version changed|Class name: GridContainerOptions<br>Method or attribute name: sizeType?: SizeType;<br>Deprecated version: N/A|Class name: GridContainerOptions<br>Method or attribute name: sizeType?: SizeType;<br>Deprecated version: 9<br>Substitute API: N/A|grid_container.d.ts|
|Deprecated version changed|Class name: GridContainerOptions<br>Method or attribute name: gutter?: number \| string;<br>Deprecated version: N/A|Class name: GridContainerOptions<br>Method or attribute name: gutter?: number \| string;<br>Deprecated version: 9<br>Substitute API: N/A|grid_container.d.ts|
|Deprecated version changed|Class name: GridContainerOptions<br>Method or attribute name: margin?: number \| string;<br>Deprecated version: N/A|Class name: GridContainerOptions<br>Method or attribute name: margin?: number \| string;<br>Deprecated version: 9<br>Substitute API: N/A|grid_container.d.ts|
|Deprecated version changed|Class name: GridContainerInterface<br>Deprecated version: N/A|Class name: GridContainerInterface<br>Deprecated version: 9<br>Substitute API: grid_col/[GridColInterface] and grid_row/[GridRowInterface]|grid_container.d.ts|
|Deprecated version changed|Class name: GridContainerInterface<br>Method or attribute name: (value?: GridContainerOptions): GridContainerAttribute;<br>Deprecated version: N/A|Class name: GridContainerInterface<br>Method or attribute name: (value?: GridContainerOptions): GridContainerAttribute;<br>Deprecated version: 9<br>Substitute API: N/A|grid_container.d.ts|
|Deprecated version changed|Class name: GridContainerAttribute<br>Deprecated version: N/A|Class name: GridContainerAttribute<br>Deprecated version: 9<br>Substitute API: grid_col/[GridColAttribute] and grid_row/[GridRowAttribute]|grid_container.d.ts|
|Deprecated version changed|Class name: ImageAttribute<br>Method or attribute name: draggable(value: boolean): ImageAttribute;<br>Deprecated version: N/A|Class name: ImageAttribute<br>Method or attribute name: draggable(value: boolean): ImageAttribute;<br>Deprecated version: 10<br>Substitute API: common.CommonMethod#draggable|image.d.ts|
|Deprecated version changed|Class name: Sticky<br>Deprecated version: N/A|Class name: Sticky<br>Deprecated version: 9<br>Substitute API: list/StickyStyle |list_item.d.ts|
|Deprecated version changed|Class name: ListItemAttribute<br>Method or attribute name: sticky(value: Sticky): ListItemAttribute;<br>Deprecated version: N/A|Class name: ListItemAttribute<br>Method or attribute name: sticky(value: Sticky): ListItemAttribute;<br>Deprecated version: 9<br>Substitute API: list/List#sticky|list_item.d.ts|
|Deprecated version changed|Class name: MenuAttribute<br>Method or attribute name: fontSize(value: Length): MenuAttribute;<br>Deprecated version: N/A|Class name: MenuAttribute<br>Method or attribute name: fontSize(value: Length): MenuAttribute;<br>Deprecated version: 10<br>Substitute API: font   |menu.d.ts|
|Deprecated version changed|Class name: SwiperDisplayMode<br>Method or attribute name: Stretch<br>Deprecated version: N/A|Class name: SwiperDisplayMode<br>Method or attribute name: Stretch<br>Deprecated version: 10<br>Substitute API: SwiperDisplayMode#STRETCH|swiper.d.ts|
|Deprecated version changed|Class name: SwiperDisplayMode<br>Method or attribute name: AutoLinear<br>Deprecated version: N/A|Class name: SwiperDisplayMode<br>Method or attribute name: AutoLinear<br>Deprecated version: 10<br>Substitute API: SwiperDisplayMode#AUTO_LINEAR|swiper.d.ts|
|Deprecated version changed|Class name: IndicatorStyle<br>Deprecated version: N/A|Class name: IndicatorStyle<br>Deprecated version: 10<br>Substitute API: N/A|swiper.d.ts|
|Deprecated version changed|Class name: SwiperAttribute<br>Method or attribute name: indicatorStyle(value?: IndicatorStyle): SwiperAttribute;<br>Deprecated version: N/A|Class name: SwiperAttribute<br>Method or attribute name: indicatorStyle(value?: IndicatorStyle): SwiperAttribute;<br>Deprecated version: 10<br>Substitute API: N/A|swiper.d.ts|
|Deprecated version changed|Class name: TextPickerAttribute<br>Method or attribute name: onAccept(callback: (value: string, index: number) => void): TextPickerAttribute;<br>Deprecated version: N/A|Class name: TextPickerAttribute<br>Method or attribute name: onAccept(callback: (value: string, index: number) => void): TextPickerAttribute;<br>Deprecated version: 10<br>Substitute API: N/A|text_picker.d.ts|
|Deprecated version changed|Class name: TextPickerAttribute<br>Method or attribute name: onCancel(callback: () => void): TextPickerAttribute;<br>Deprecated version: N/A|Class name: TextPickerAttribute<br>Method or attribute name: onCancel(callback: () => void): TextPickerAttribute;<br>Deprecated version: 10<br>Substitute API: N/A|text_picker.d.ts|
|Deprecated version changed|Class name: WebAttribute<br>Method or attribute name: onUrlLoadIntercept(callback: (event?: { data: string \| WebResourceRequest }) => boolean): WebAttribute;<br>Deprecated version: N/A|Class name: WebAttribute<br>Method or attribute name: onUrlLoadIntercept(callback: (event?: { data: string \| WebResourceRequest }) => boolean): WebAttribute;<br>Deprecated version: 10<br>Substitute API: ohos.web.WebAttribute#onLoadIntercept|web.d.ts|
|Function changed|Class name: AlphabetIndexerAttribute<br>Method or attribute name: alignStyle(value: IndexerAlign): AlphabetIndexerAttribute;<br>|Class name: AlphabetIndexerAttribute<br>Method or attribute name: alignStyle(value: IndexerAlign, offset?: Length): AlphabetIndexerAttribute;<br>|alphabet_indexer.d.ts|
|Function changed|Class name: CommonMethod<br>Method or attribute name: backgroundBlurStyle(value: BlurStyle): T;<br>|Class name: CommonMethod<br>Method or attribute name: backgroundBlurStyle(value: BlurStyle, options?: BackgroundBlurStyleOptions): T;<br>|common.d.ts|
|Function changed|Class name: CommonMethod<br>Method or attribute name: borderStyle(value: BorderStyle): T;<br>|Class name: CommonMethod<br>Method or attribute name: borderStyle(value: BorderStyle \| EdgeStyles): T;<br>|common.d.ts|
|Function changed|Class name: CommonMethod<br>Method or attribute name: borderWidth(value: EdgeWidths): T;<br>|Class name: CommonMethod<br>Method or attribute name: borderWidth(value: Length \| EdgeWidths): T;<br>|common.d.ts|
|Function changed|Class name: CommonMethod<br>Method or attribute name: borderColor(value: ResourceColor): T;<br>|Class name: CommonMethod<br>Method or attribute name: borderColor(value: ResourceColor \| EdgeColors): T;<br>|common.d.ts|
|Function changed|Class name: CommonMethod<br>Method or attribute name: borderRadius(value: BorderRadiuses): T;<br>|Class name: CommonMethod<br>Method or attribute name: borderRadius(value: Length \| BorderRadiuses): T;<br>|common.d.ts|
|Function changed|Class name: CommonMethod<br>Method or attribute name: transition(value: TransitionOptions): T;<br>|Class name: CommonMethod<br>Method or attribute name: transition(value: TransitionOptions \| TransitionEffect): T;<br>|common.d.ts|
|Function changed|Class name: CommonMethod<br>Method or attribute name: shadow(value: {<br>    radius: number \| Resource;<br>    color?: Color \| string \| Resource;<br>    offsetX?: number \| Resource;<br>    offsetY?: number \| Resource;<br>  }): T;<br>|Class name: CommonMethod<br>Method or attribute name: shadow(value: ShadowOptions \| ShadowStyle): T;<br>|common.d.ts|
|Function changed|Class name: CommonMethod<br>Method or attribute name: mask(value: CircleAttribute \| EllipseAttribute \| PathAttribute \| RectAttribute): T;<br>|Class name: CommonMethod<br>Method or attribute name: mask(value: CircleAttribute \| EllipseAttribute \| PathAttribute \| RectAttribute \| ProgressMask): T;<br>|common.d.ts|
|Function changed|Class name: CommonMethod<br>Method or attribute name: bindMenu(content: { value: string; action: () => void }[] \| CustomBuilder): T;<br>|Class name: CommonMethod<br>Method or attribute name: bindMenu(content: { value: ResourceStr; icon?: ResourceStr; action: () => void }[] \| CustomBuilder, options?: MenuOptions): T;<br>|common.d.ts|
|Function changed|Class name: CommonMethod<br>Method or attribute name: bindContextMenu(content: CustomBuilder, responseType: ResponseType): T;<br>|Class name: CommonMethod<br>Method or attribute name: bindContextMenu(content: CustomBuilder, responseType: ResponseType, options?: ContextMenuOptions): T;<br>|common.d.ts|
|Function changed|Class name: ImageInterface<br>Method or attribute name: (src: string \| PixelMap \| Resource): ImageAttribute;<br>|Class name: ImageInterface<br>Method or attribute name: (src: PixelMap \| ResourceStr \| DrawableDescriptor): ImageAttribute;<br>|image.d.ts|
|Function changed|Class name: MenuItemAttribute<br>Method or attribute name: selectIcon(value: boolean): MenuItemAttribute;<br>|Class name: MenuItemAttribute<br>Method or attribute name: selectIcon(value: boolean \| ResourceStr): MenuItemAttribute;<br>|menu_item.d.ts|
|Function changed|Class name: NavigationAttribute<br>Method or attribute name: title(value: string \| CustomBuilder \| NavigationCommonTitle \| NavigationCustomTitle): NavigationAttribute;<br>|Class name: NavigationAttribute<br>Method or attribute name: title(value: ResourceStr \| CustomBuilder \| NavigationCommonTitle \| NavigationCustomTitle): NavigationAttribute;<br>|navigation.d.ts|
|Function changed|Class name: RefreshInterface<br>Method or attribute name: (value: { refreshing: boolean; offset?: number \| string; friction?: number \| string }): RefreshAttribute;<br>|Class name: RefreshInterface<br>Method or attribute name: (value: RefreshOptions): RefreshAttribute;<br>|refresh.d.ts|
|Function changed|Class name: Scroller<br>Method or attribute name: scrollToIndex(value: number);<br>|Class name: Scroller<br>Method or attribute name: scrollToIndex(value: number, smooth?:boolean);<br>|scroll.d.ts|
|Function changed|Class name: SearchAttribute<br>Method or attribute name: searchButton(value: string): SearchAttribute;<br>|Class name: SearchAttribute<br>Method or attribute name: searchButton(value: string, option?: SearchButtonOption): SearchAttribute;<br>|search.d.ts|
|Function changed|Class name: SwiperAttribute<br>Method or attribute name: indicator(value: boolean): SwiperAttribute;<br>|Class name: SwiperAttribute<br>Method or attribute name: indicator(value: DotIndicator \| DigitIndicator \| boolean): SwiperAttribute;<br>|swiper.d.ts|
|Function changed|Class name: SwiperAttribute<br>Method or attribute name: curve(value: Curve \| string): SwiperAttribute;<br>|Class name: SwiperAttribute<br>Method or attribute name: curve(value: Curve \| string \| ICurve): SwiperAttribute;<br>|swiper.d.ts|
