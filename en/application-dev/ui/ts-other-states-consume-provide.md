# @Consume and @Provide<a name="EN-US_TOPIC_0000001177510803"></a>

As the data provider,  **Provide**  can update the data of child nodes and trigger page rendering. After  **Consume**  detects that the  **Provide**  data is updated, it will initiate re-rendering of the current view.

**Table  1**  @Provide

<a name="table657684923115"></a>
<table><thead align="left"><tr id="row15576204917311"><th class="cellrowborder" valign="top" width="11.76%" id="mcps1.2.3.1.1"><p id="p1432545513219"><a name="p1432545513219"></a><a name="p1432545513219"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="88.24%" id="mcps1.2.3.1.2"><p id="p35771495314"><a name="p35771495314"></a><a name="p35771495314"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row17577164993114"><td class="cellrowborder" valign="top" width="11.76%" headers="mcps1.2.3.1.1 "><p id="p175774498318"><a name="p175774498318"></a><a name="p175774498318"></a>Decorator parameters</p>
</td>
<td class="cellrowborder" valign="top" width="88.24%" headers="mcps1.2.3.1.2 "><p id="p1057724983115"><a name="p1057724983115"></a><a name="p1057724983115"></a>Alias: a constant of the string type. If an alias is specified, implement the data update for this alias. If there is no alias, use the variable name as the alias. <strong id="b6361102517296"><a name="b6361102517296"></a><a name="b6361102517296"></a>@Provide("<em id="i111131278293"><a name="i111131278293"></a><a name="i111131278293"></a>alias</em>")</strong> is recommended.</p>
</td>
</tr>
<tr id="row176181053377"><td class="cellrowborder" valign="top" width="11.76%" headers="mcps1.2.3.1.1 "><p id="p1261945143714"><a name="p1261945143714"></a><a name="p1261945143714"></a>Synchronization mechanism</p>
</td>
<td class="cellrowborder" valign="top" width="88.24%" headers="mcps1.2.3.1.2 "><p id="p361955173715"><a name="p361955173715"></a><a name="p361955173715"></a>The <strong id="b180161543014"><a name="b180161543014"></a><a name="b180161543014"></a>@Provide</strong> decorated variable is similar to the <strong id="b1520118579306"><a name="b1520118579306"></a><a name="b1520118579306"></a>@state</strong> variable. You can modify the variable to re-render the page. You can also modify the <strong id="b5329423183117"><a name="b5329423183117"></a><a name="b5329423183117"></a>@Consume</strong> decorated variable to modify the <strong id="b137201734193116"><a name="b137201734193116"></a><a name="b137201734193116"></a>@State</strong> decorated variable reversely.</p>
</td>
</tr>
<tr id="row103140354219"><td class="cellrowborder" valign="top" width="11.76%" headers="mcps1.2.3.1.1 "><p id="p531412324219"><a name="p531412324219"></a><a name="p531412324219"></a>Initial value</p>
</td>
<td class="cellrowborder" valign="top" width="88.24%" headers="mcps1.2.3.1.2 "><p id="p331412394220"><a name="p331412394220"></a><a name="p331412394220"></a>The initial value must be set.</p>
</td>
</tr>
<tr id="row171522344211"><td class="cellrowborder" valign="top" width="11.76%" headers="mcps1.2.3.1.1 "><p id="p22941739134411"><a name="p22941739134411"></a><a name="p22941739134411"></a>Page re-rendering scenarios</p>
</td>
<td class="cellrowborder" valign="top" width="88.24%" headers="mcps1.2.3.1.2 "><p id="p61513237423"><a name="p61513237423"></a><a name="p61513237423"></a>1. Primitive types: boolean, string, and number</p>
<p id="p118613561460"><a name="p118613561460"></a><a name="p118613561460"></a>2. <strong id="b464654743215"><a name="b464654743215"></a><a name="b464654743215"></a>@observed</strong>: used to modify the attributes of the <strong id="b8138554192417"><a name="b8138554192417"></a><a name="b8138554192417"></a>@observed</strong> decorated class.</p>
<p id="p232173614475"><a name="p232173614475"></a><a name="p232173614475"></a>3. Array: Add, delete, or update elements in an array.</p>
</td>
</tr>
</tbody>
</table>

**Table  2**  @Consume

<a name="table11965192012493"></a>
<table><thead align="left"><tr id="row1796552012496"><th class="cellrowborder" valign="top" width="11.76%" id="mcps1.2.3.1.1"><p id="p7965182054914"><a name="p7965182054914"></a><a name="p7965182054914"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="88.24%" id="mcps1.2.3.1.2"><p id="p2965220174910"><a name="p2965220174910"></a><a name="p2965220174910"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1965182013493"><td class="cellrowborder" valign="top" width="11.76%" headers="mcps1.2.3.1.1 "><p id="p1496582020496"><a name="p1496582020496"></a><a name="p1496582020496"></a>Initial value</p>
</td>
<td class="cellrowborder" valign="top" width="88.24%" headers="mcps1.2.3.1.2 "><p id="p15965132044919"><a name="p15965132044919"></a><a name="p15965132044919"></a>No default value can be set.</p>
</td>
</tr>
</tbody>
</table>

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>To avoid infinite loops caused by circular reference, exercise caution when using  **@Provide**  and  **@Consume**.

The description of other attributes is the same as that of  **@Provide**.

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

