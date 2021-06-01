# Adding Title and Paragraph Text<a name="EN-US_TOPIC_0000001063749052"></a>

The  **<text\>**  component is most commonly used to display text in title and paragraph areas. You can set attributes and styles for a  **<text\>**  component and add the text to be displayed between the  **<text\>**  and  **</text\>**  tags. The following is an example of adding title and paragraph text on a page:

```
<!-- xxx.hml -->
<div class="container">
  <text class="title-text">{{headTitle}}</text>
  <text class="paragraph-text">{{paragraphFirst}}</text>
  <text class="paragraph-text">{{paragraphSecond}}</text>
</div>
```

```
/* xxx.css */
.container {
  flex-direction: column;
  margin-top: 20px;
  margin-left: 30px;
}
.title-text {
  color: #1a1a1a;
  font-size: 50px;
  margin-top: 40px;
  margin-bottom: 20px;
}
.paragraph-text {
  color: #000000;
  font-size: 35px;
  line-height: 60px;
}
```

```
// xxx.js
export default {
  data: {
    headTitle: 'Capture the Beauty in This Moment',
    paragraphFirst: 'Capture the beauty of light during the transition and fusion of ice and water. At the instant of movement and stillness, softness and rigidity, force and beauty, condensing moving moments.',
    paragraphSecond: 'Reflecting the purity of nature, the innovative design upgrades your visual entertainment and ergonomic comfort. Effortlessly capture what you see and let it speak for what you feel.',
  },
}
```

