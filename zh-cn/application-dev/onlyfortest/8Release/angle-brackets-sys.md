# 尖括号转义正常场景-系统

## 尖括号存在转义字符

### 场景1

connectDfs(networkId: string, listeners: DfsListeners): Promise&lt;void&gt;

### 场景2

connectDfs(networkId: string, listeners: DfsListeners): Promise\<void>\;

### 场景3

connectDfs(networkId: string, listeners: DfsListeners): Promise\<void>;

## 尖括号内容包含在行内code中

执行命令`ps -s <pid> -T`命令 

## 尖括号内容包含在code块中

```ts
async function getCurrentAudioRendererInfoArray(): Promise<void> {
    ...
}
```

## 尖括号内容为html中的标签，验证门禁检查功能

<strong>加粗</strong>

<b>加粗</b>

<text>文本</text>

a<sup>2+</sup>

<p>段落</p>

123<br>456<br/>789
