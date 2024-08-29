# Angle bracket escape normal scenario

## Angle brackets contain escape characters.

### Scene 1

connectDfs(networkId: string, listeners: DfsListeners): Promise&lt;void&gt;

### Scene 2

connectDfs(networkId: string, listeners: DfsListeners): Promise\<void>\;

### Scene 3

connectDfs(networkId: string, listeners: DfsListeners): Promise\<void>;

## The content in angle brackets is contained in the inline code.

Run the`ps -s <pid> -T` command. 

## The content in angle brackets is contained in the code block.

```ts
async function getCurrentAudioRendererInfoArray(): Promise<void> {
    ...
}
```

## The content in the angle brackets is the tag in the HTML file,Verify the access control check function.

<strong>Bold</strong>

<b>bold</b>

<text>Text</text>

a<sup>2+</sup>

<p>Paragraphs</p>

123<br>456<br/>789