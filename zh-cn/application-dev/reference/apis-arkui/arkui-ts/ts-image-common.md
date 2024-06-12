# 图像类型定义

>**说明：**
>
>本模块首批接口从API version 12开始支持，后续版本的新增接口，采用上角标单独标记接口的起始版本。

## ImageAnalyzerConfig<sup>12+</sup>

图像AI分析配置项。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

| 名称     | 类型                | 必填   | 说明                   |
| ------ | ----------------- | ---- | -------------------- |
| types | [ImageAnalyzerType[]](#imageanalyzertype12) | 是 | 图像AI分析类型。

## ImageAnalyzerType<sup>12+</sup>

图像AI分析类型。

| 名称     | 描述           |
| -------- | -------------- |
| SUBJECT | 主体识别功能。 |
| TEXT | 文字识别功能。 |
