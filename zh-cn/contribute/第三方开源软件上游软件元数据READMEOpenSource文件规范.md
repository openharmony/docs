# README.OpenSource 文件规范

## 目的

为更好追溯第三方开源软件的原始上游信息，特在[《第三方开源软件引入指导》](https://gitee.com/openharmony/docs/blob/master/zh-cn/contribute/%E7%AC%AC%E4%B8%89%E6%96%B9%E5%BC%80%E6%BA%90%E8%BD%AF%E4%BB%B6%E5%BC%95%E5%85%A5%E6%8C%87%E5%AF%BC.md)》中对相关信息进行了要求 “新引入的开源软件必须在其根目录提供README.OpenSource文件，在该文件中准确描述其软件名、许可证、许可文件位置、版本、对应版本的上游社区地址、软件的维护Owner、功能描述以及引入的原因。” 但社区开发者常见问题是对于README.OpenSource 写作要求和规范并不清晰，对于其中多License情况，多开源软件情况等场景如何规范填写并不清晰，因此，本文旨在规范化README.OpenSource文件的写作要求，并将相关要求基线化，在工程能力成熟后，README.OpenSource文件可按照本规范，在选型引入时，自动基于引入的信息由IT系统生成此文件。

## 范围

本指导适用于所有参与OpenHarmony社区的贡献者、特别是当引入第三方开源软件到OpenHarmony项目中。

## 本文的改进和修订说明

1. 本文档由OpenHarmony 合规SIG主导起草和维护。本文档的最新版本总可以在 [这里](https://gitee.com/openharmony/docs/blob/)找到。
2. 任何对于本文中涉及的规则的增加，修改，删除都必须被追踪，请进入该追踪系统 。
3. 最终规则经过社区充分的讨论后，由PMC评审定稿。


## 术语和缩略语
1. 开源合规术语与缩略语参考，见[这里]()

## README.OpenSource 字段规则说明
README.OpenSource 样例

```
[
    {
        "Name": "linux",                   # 上游开源软件名全称
        "License": "GPL-2.0+",             # 上游开源软件中包含的许可证信息
        "License File": "COPYING",         # 许可所在文件
        "Version Number": "5.10.93",       # 借鉴时该软件的版本
        "Owner": "xxx@xxx.com",            # 借鉴软件引入及拥有人邮箱
        "Upstream URL": "https://git.kernel.org/pub/scm/linux/kernel/git/stable/linux.git/log/?h=linux-5.10.y",   # 借鉴软件开源地址链接
        "Description": "linux kernel 5.10" # 对借鉴的开源软件模块的描述
    }
]
```

1. **Name** :在本代码仓中*包含源码*的上游开源软件全称。 假设A软件依赖B软件，若通过将B软件源码放置在本仓库中，来满足A对B的依赖关系，即A*包含依赖*B， 则A、B软件均需要声明； 若B软件已在OpenHarmony组织下建立其专属代码仓，仅在编译构建时通过GN指定其他代码仓目录进行依赖，不是以*源码形式*存放在本代码仓库的，即A开源软件*编译依赖*B软件，则不用在此处声明。
2. **License** : 上游开源软件中包含的许可证信息此处不可随意填写，需使用SPDX Identitifer简写，由于存在多许可证的情况，此处使用的许可
