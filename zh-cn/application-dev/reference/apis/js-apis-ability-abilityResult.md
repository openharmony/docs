# AbilityResult<sup>7+</sup>

表示ability拉起、销毁之后返回的结果码和数据。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityBase

| 名称        | 读写属性 | 类型                 | 必填 | 描述                                                         |
| ----------- | -------- | -------------------- | ---- | ------------------------------------------------------------ |
| resultCode    | 只读     | number               | 否   | 表示ability拉起、销毁之后返回的结果码。                                |
| want   | 只读     | Want               | 否   | 表示ability销毁之后返回的数据。 |

**示例：**
  ```js
  let want = {
    bundleName: 'com.example.mydocapplication',
    abilityName: 'MainAbility',
  };
  this.context.startAbilityForResult(want, (error, data) => {
      let resultCode = data.resultCode;
      let want = data.want;
  });
  ```