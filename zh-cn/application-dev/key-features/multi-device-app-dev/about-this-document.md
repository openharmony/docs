# 前言


本指导的目的是快速及全面地指导读者使用OpenHarmony提供的“一次开发，多端部署”（本指导中简称“一多”）能力开发多设备应用。在应用开发前，开发者应尽可能全面考虑应用支持多设备的情况，避免在后期加入新的类型设备时需要对应用架构进行大幅调整。


## 本指导面向的读者

本指导适合开发OpenHarmony应用的UX设计师、应用开发人员，本指导书统称为“应用开发者”。这两者是根据开发角色不同而进行的区分。对于个人或者规模较小的应用，两者可能是同一个个体，但应当从角色上加以区分。


## 如何阅读本指导

应用在需求明确后，开发过程大致分为：应用设计（包含界面UX设计、业务功能设计）- 工程设计和创建 - 功能代码实现。本指导也是基于这个流程进行的内容编排。

阅读本文档时，应尽量按照章节顺序进行阅读。如果区分开发角色，那么UX设计师可以仅阅读第3章，而开发人员可以从第4章开始阅读。但无论何种角色，我们强烈建议阅读第2章。

本文档各章节简介如下：

- 第1章[前言](about-this-document.md)说明本指导面向的读者、如何阅读本指导等，指引读者更好地阅读。

- 第2章[简介](introduction.md)简短介绍了“一多”的背景、定义、目标、以及用于指导后续开发的一些基础知识。

- 第3章[应用UX设计](design-principles.md)介绍了应用UX设计理念。主要阐述了应用设计之初UX设计的原则和要点。该章节主要面向应用的UX设计师。
  
  UX设计原则应该考虑多设备的“差异性” 、“一致性”、“灵活性”、“兼容性”。

  UX设计要点则从6个方面阐述如何进行多设备应用设计，分别是“自适应应用架构”、“响应式界面布局”、“交互归一”、“视觉参数化”、“多态控件”、“针对性优化”。

  最后，给出设计自检表，用于检查应用UX设计是否合理。

- 第4章[IDE使用](ide-usage.md)介绍了从工程角度如何开始开发应用，这非常有用，让读者可以直接上手创建多设备应用的工程，是后面学习“一多”能力的上手基础。

- 第5章[一多能力的页面开发介绍](layout-intro.md)、第6章[一多能力的功能开发介绍](development-intro.md)介绍了OpenHarmony提供的“一多”能力，其中每个能力都提供了代码示例和UX效果，让读者可以快速学习“一多”能力。

- 第7章提供了两个案例应用，阐述了从应用设计到开发这一过程中如何实践前面章节介绍的设计思路或“一多”能力，让读者可以整体上掌握“一多”在应用开发过程中的知识。

- 第8章[常见问题](faqs.md)提供了常见问题（FAQ），方便读者查阅。

本指导在介绍过程中还包括一些“说明”。这些“说明”，表示例外情况或者额外信息的补充。
