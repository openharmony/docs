# @Consume和@Provide数据管理<a name="ZH-CN_TOPIC_0000001177510803"></a>

Provide作为数据的提供方，可以更新其子孙节点的数据，并触发页面渲染。Consume在感知到Provide数据的更新后，会触发当前view的重新渲染。

**表 1**  @Provide

<a name="table657684923115"></a>
<table><thead align="left"><tr id="row15576204917311"><th class="cellrowborder" valign="top" width="11.76%" id="mcps1.2.3.1.1"><p id="p1432545513219"><a name="p1432545513219"></a><a name="p1432545513219"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="88.24%" id="mcps1.2.3.1.2"><p id="p35771495314"><a name="p35771495314"></a><a name="p35771495314"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row17577164993114"><td class="cellrowborder" valign="top" width="11.76%" headers="mcps1.2.3.1.1 "><p id="p175774498318"><a name="p175774498318"></a><a name="p175774498318"></a>装饰器参数</p>
</td>
<td class="cellrowborder" valign="top" width="88.24%" headers="mcps1.2.3.1.2 "><p id="p1057724983115"><a name="p1057724983115"></a><a name="p1057724983115"></a>是一个string类型的常量，用于给装饰的变量起别名。如果规定别名，则提供对应别名的数据更新。如果没有，则使用变量名作为别名。推荐使用@Provide("alias")这种形式。</p>
</td>
</tr>
<tr id="row176181053377"><td class="cellrowborder" valign="top" width="11.76%" headers="mcps1.2.3.1.1 "><p id="p1261945143714"><a name="p1261945143714"></a><a name="p1261945143714"></a>同步机制</p>
</td>
<td class="cellrowborder" valign="top" width="88.24%" headers="mcps1.2.3.1.2 "><p id="p361955173715"><a name="p361955173715"></a><a name="p361955173715"></a>@Provide的变量类似@state，可以修改对应变量进行页面重新渲染。也可以修改@Consume装饰的变量，反向修改@State变量。</p>
</td>
</tr>
<tr id="row103140354219"><td class="cellrowborder" valign="top" width="11.76%" headers="mcps1.2.3.1.1 "><p id="p531412324219"><a name="p531412324219"></a><a name="p531412324219"></a>初始值</p>
</td>
<td class="cellrowborder" valign="top" width="88.24%" headers="mcps1.2.3.1.2 "><p id="p331412394220"><a name="p331412394220"></a><a name="p331412394220"></a>必须制定初始值。</p>
</td>
</tr>
<tr id="row171522344211"><td class="cellrowborder" valign="top" width="11.76%" headers="mcps1.2.3.1.1 "><p id="p22941739134411"><a name="p22941739134411"></a><a name="p22941739134411"></a>页面重渲染场景</p>
</td>
<td class="cellrowborder" valign="top" width="88.24%" headers="mcps1.2.3.1.2 "><p id="p1175614313217"><a name="p1175614313217"></a><a name="p1175614313217"></a>触发页面渲染的修改：</p>
<a name="ul140620253219"></a><a name="ul140620253219"></a><ul id="ul140620253219"><li>基础类型（boolean，string，number）的改变；</li><li>@Observed class类型变量及其属性的修改；</li><li>添加，删除，更新数组中的元素。</li></ul>
</td>
</tr>
</tbody>
</table>

**表 2**  @Consume

<a name="table11965192012493"></a>
<table><thead align="left"><tr id="row1796552012496"><th class="cellrowborder" valign="top" width="11.76%" id="mcps1.2.3.1.1"><p id="p7965182054914"><a name="p7965182054914"></a><a name="p7965182054914"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="88.24%" id="mcps1.2.3.1.2"><p id="p2965220174910"><a name="p2965220174910"></a><a name="p2965220174910"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1965182013493"><td class="cellrowborder" valign="top" width="11.76%" headers="mcps1.2.3.1.1 "><p id="p1496582020496"><a name="p1496582020496"></a><a name="p1496582020496"></a>初始值</p>
</td>
<td class="cellrowborder" valign="top" width="88.24%" headers="mcps1.2.3.1.2 "><p id="p15965132044919"><a name="p15965132044919"></a><a name="p15965132044919"></a>不可设置默认值。</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>使用@Provide 和@Consume时避免循环引用导致死循环。

其他属性说明与Provide一致。

```
@Entry
@Component
struct CompA {
    @Provide("reviewVote") reviewVotes : number = 0;

    build() {
        Column() {
            CompB()
            Button() {
                Text(`${this.reviewVotes}`)
                    .fontSize(30)
            }
            .onClick(() => {
                this.reviewVotes += 1;
            })
        }
    }
}

@Component
struct CompB {
    build() {
        Column() {
            CompC()
        }
    }
}

@Component
struct CompC {
    @Consume("reviewVote") reviewVotes : number;
    build() {
        Column() {
            Button() {
                Text(`${this.reviewVotes}`)
                    .fontSize(30)
            }
            .onClick(() => {
                this.reviewVotes += 1;
            })
        }
    }
}
```

