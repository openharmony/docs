# web子系统ChangeLog

OpenHarmony 3.2.10.7 版本相较于OpenHarmony 之前的版本，web的API变更如下。

## cl.web.1 HitTestTypeV9命名变更

枚举类HitTestTypeV9由于命名规范问题，名称变更为WebHitTestType。

**变更影响**

枚举类HitTestTypeV9，以及使用HitTestTypeV9作为参数或返回值的接口，在3.2.10.7版本及后续版本中无法继续正常使用。

**关键的接口/组件变更**

- 涉及接口

  enum HitTestTypeV9

- 变更前：

  ```ts
  enum HitTestTypeV9
  ```

- 变更后：

  ```ts
  enum WebHitTestType
  ```

**适配指导**

请使用WebHitTestType替换HitTestTypeV9。

## cl.web.2 HeaderV9命名变更

结构体HeaderV9由于命名规范问题，名称变更为WebHeader。

**变更影响**

结构体HeaderV9，以及使用HeaderV9作为参数或返回值的接口，在3.2.10.7版本及后续版本中无法继续正常使用。

**关键的接口/组件变更**

- 涉及接口

  interface HeaderV9

- 变更前：

  ```ts
  interface HeaderV9
  ```

- 变更后：

  ```ts
  interface WebHeader
  ```

**适配指导**

请使用WebHeader替换HeaderV9。

## cl.web.3 HitTestValue结构体成员类型变更

结构体HitTestValue中的成员变量HitTestTypeV9由于命名规范问题，名称变更为WebHitTestType。

**变更影响**

结构体HitTestValue，以及使用HitTestValue作为参数或返回值的接口，在3.2.10.7版本及后续版本中无法继续正常使用。

**关键的接口/组件变更**

- 涉及接口

  interface HitTestValue

- 变更前：

  ```ts
  interface HitTestValue {

    /**
      * Get the hit test type.
      *
      * @since 9
      */
    type: HitTestTypeV9;

    /**
      * Get the hit test extra data.
      *
      * @since 9
      */
    extra: string;
  }
  ```

- 变更后：

  ```ts
  interface HitTestValue {

    /**
      * Get the hit test type.
      *
      * @since 9
      */
    type: WebHitTestType;

    /**
      * Get the hit test extra data.
      *
      * @since 9
      */
    extra: string;
  }
  ```

**适配指导**

请使用WebHitTestType替换HitTestTypeV9。

## cl.web.4 loadUrl参数类型变更

loadUrl接口中的参数headers，由于其类型的命名规范问题，类型变更为WebHeader。

**变更影响**

loadUrl接口若使用了headers参数，则在3.2.10.7版本及后续版本中无法继续正常使用。

**关键的接口/组件变更**

- 涉及接口

  loadUrl(url: string | Resource, headers?: Array<HeaderV9>): void

- 变更前：

  ```ts
  loadUrl(url: string | Resource, headers?: Array<HeaderV9>): void
  ```

- 变更后：

  ```ts
  loadUrl(url: string | Resource, headers?: Array<WebHeader>): void
  ```

**适配指导**

在loadUrl中设置headers参数时，请使用WebHeader类型替换HeaderV9类型。

## cl.web.5 getHitTest返回值类型变更

getHitTest接口中的返回值,由于其类型的命名规范问题，变更为WebHitTest。

**变更影响**

getHitTest接口，在3.2.10.7版本及后续版本中无法继续正常使用。

**关键的接口/组件变更**

- 涉及接口

  getHitTest(): HitTestTypeV9

- 变更前：

  ```ts
  getHitTest(): HitTestTypeV9
  ```

- 变更后：

  ```ts
  getHitTest(): WebHitTestType
  ```

**适配指导**

在使用getHitTest接口的返回值时，请使用WebHitTestType类型替换HitTestTypeV9类型。