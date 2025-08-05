# 组件介绍
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @fenglinbailu-->
<!--SE: @lanshouren-->
<!--TSE: @liuli0427-->

组件（Component）是构建页面的核心，每个组件通过对数据和方法的简单封装，实现独立的可视、可交互功能单元。组件之间相互独立，随取随用，也可以在需求相同的地方重复使用。


开发者还可以通过组件间合理的搭配定义满足业务需求的新组件，减少开发量，自定义组件的开发方法请参见[自定义组件](ui-js-custom-components.md)。


## 组件分类

根据组件的功能，可以分为以下六大类：

| 组件类型 | 主要组件 |
| -------- | -------- |
| 容器组件 | [badge](../reference/apis-arkui/arkui-js/js-components-container-badge.md)、[dialog](../reference/apis-arkui/arkui-js/js-components-container-dialog.md)、[div](../reference/apis-arkui/arkui-js/js-components-container-div.md)、[form](../reference/apis-arkui/arkui-js/js-components-container-form.md)、[list](../reference/apis-arkui/arkui-js/js-components-container-list.md)、[list-item](../reference/apis-arkui/arkui-js/js-components-container-list-item.md)、[list-item-group](../reference/apis-arkui/arkui-js/js-components-container-list-item-group.md)、[panel](../reference/apis-arkui/arkui-js/js-components-container-panel.md)、[popup](../reference/apis-arkui/arkui-js/js-components-container-popup.md)、[refresh](../reference/apis-arkui/arkui-js/js-components-container-refresh.md)、[stack](../reference/apis-arkui/arkui-js/js-components-container-stack.md)、[stepper](../reference/apis-arkui/arkui-js/js-components-container-stepper.md)、[stepper-item](../reference/apis-arkui/arkui-js/js-components-container-stepper-item.md)、[swiper](../reference/apis-arkui/arkui-js/js-components-container-swiper.md)、[tabs](../reference/apis-arkui/arkui-js/js-components-container-tabs.md)、[tab-bar](../reference/apis-arkui/arkui-js/js-components-container-tab-bar.md)、[tab-content](../reference/apis-arkui/arkui-js/js-components-container-tab-content.md) |
| 基础组件 | [button](../reference/apis-arkui/arkui-js/js-components-basic-button.md)、[chart](../reference/apis-arkui/arkui-js/js-components-basic-chart.md)、[divider](../reference/apis-arkui/arkui-js/js-components-basic-divider.md)、[image](../reference/apis-arkui/arkui-js/js-components-basic-image.md)、[image-animator](../reference/apis-arkui/arkui-js/js-components-basic-image-animator.md)、[input](../reference/apis-arkui/arkui-js/js-components-basic-input.md)、[label](../reference/apis-arkui/arkui-js/js-components-basic-label.md)、[marquee](../reference/apis-arkui/arkui-js/js-components-basic-marquee.md)、[menu](../reference/apis-arkui/arkui-js/js-components-basic-menu.md)、[option](../reference/apis-arkui/arkui-js/js-components-basic-option.md)、[picker](../reference/apis-arkui/arkui-js/js-components-basic-picker.md)、[picker-view](../reference/apis-arkui/arkui-js/js-components-basic-picker-view.md)、[piece](../reference/apis-arkui/arkui-js/js-components-basic-piece.md)、[progress](../reference/apis-arkui/arkui-js/js-components-basic-progress.md)、[qrcode](../reference/apis-arkui/arkui-js/js-components-basic-qrcode.md)、[rating](../reference/apis-arkui/arkui-js/js-components-basic-rating.md)、[richtext](../reference/apis-arkui/arkui-js/js-components-basic-richtext.md)、[search](../reference/apis-arkui/arkui-js/js-components-basic-search.md)、[select](../reference/apis-arkui/arkui-js/js-components-basic-select.md)、[slider](../reference/apis-arkui/arkui-js/js-components-basic-slider.md)、[span](../reference/apis-arkui/arkui-js/js-components-basic-span.md)、[switch](../reference/apis-arkui/arkui-js/js-components-basic-switch.md)、[text](../reference/apis-arkui/arkui-js/js-components-basic-text.md)、[textarea](../reference/apis-arkui/arkui-js/js-components-basic-textarea.md)、[toolbar](../reference/apis-arkui/arkui-js/js-components-basic-toolbar.md)、[toolbar-item](../reference/apis-arkui/arkui-js/js-components-basic-toolbar-item.md)、[toggle](../reference/apis-arkui/arkui-js/js-components-basic-toggle.md) |
| 媒体组件 | [video](../reference/apis-arkui/arkui-js/js-components-media-video.md) |
| 画布组件 | [canvas](../reference/apis-arkui/arkui-js/js-components-canvas-canvas.md) |
| 栅格组件 | [grid-container](../reference/apis-arkui/arkui-js/js-components-grid-container.md)、[grid-row](../reference/apis-arkui/arkui-js/js-components-grid-row.md)、[grid-col](../reference/apis-arkui/arkui-js/js-components-grid-col.md) |
| svg组件 | [svg](../reference/apis-arkui/arkui-js/js-components-svg.md)、[rect](../reference/apis-arkui/arkui-js/js-components-svg-rect.md)、[circle](../reference/apis-arkui/arkui-js/js-components-svg-circle.md)、[ellipse](../reference/apis-arkui/arkui-js/js-components-svg-ellipse.md)、[path](../reference/apis-arkui/arkui-js/js-components-svg-path.md)、[line](../reference/apis-arkui/arkui-js/js-components-svg-line.md)、[polyline](../reference/apis-arkui/arkui-js/js-components-svg-polyline.md)、[polygon](../reference/apis-arkui/arkui-js/js-components-svg-polygon.md)、[text](../reference/apis-arkui/arkui-js/js-components-svg-text.md)、[tspan](../reference/apis-arkui/arkui-js/js-components-svg-tspan.md)、[textPath](../reference/apis-arkui/arkui-js/js-components-svg-textpath.md)、[animate](../reference/apis-arkui/arkui-js/js-components-svg-animate.md)、[animateMotion](../reference/apis-arkui/arkui-js/js-components-svg-animatemotion.md)、[animateTransform](../reference/apis-arkui/arkui-js/js-components-svg-animatetransform.md) |



## 相关实例

针对组件开发，有以下相关实例可供参考：

- [rating组件的使用（JS）（API9）](https://gitee.com/openharmony/codelabs/tree/master/JSUI/RatingApplication)

- [简易视频播放器（JS）（API9）](https://gitee.com/openharmony/codelabs/tree/master/Media/VideoOpenHarmony)

- [购物应用（JS）（API9）](https://gitee.com/openharmony/codelabs/tree/master/JSUI/ShoppingSample)

- [图片常见操作（JS）（API9）](https://gitee.com/openharmony/codelabs/tree/master/Media/ImageOperation)