# Web

The \<Web> component can be used to display web pages. For details, see [Web API](../reference/arkui-ts/ts-basic-components-web.md).

## Creating a Component

Create a \<Web> component in the .ets file under main/ets/MainAbility/pages. Then, in the created component, use src to specify the web page URI to be referenced, and bind a controller to the component to call the component APIs.

  ```
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController();
    build() {
      Column() {
        Web({ src: 'https://www.example.com', controller: this.controller })
      }
    }
  }
  ```

## Setting Styles and Attributes

When using the \<Web> component, you need to specify the styles and attributes. The sample code is as follows.

```
// xxx.ets
@Entry
@Component
struct WebComponent {
  fileAccess: boolean = true;
  controller: WebController = new WebController();
  build() {
    Column() {
      Text('Hello world!')
        .fontSize(20)
      Web({ src: 'https://www.example.com', controller: this.controller })
        // Set the height and padding.
        .height(500)
        .padding(20)
        // Set the file access permission and script execution permission.
        .fileAccess(this.fileAccess)
        .javaScriptAccess(true)
      Text('End')
        .fontSize(20)
    }
  }
}
```
## Adding Events and Methods

Add the onProgressChange event for the \<Web> component, which is triggered when the loading progress changes and returns the progress value in its callback. Assign the progress value to the \<Progress> component to control the status of the component. When the progress reaches 100%, the \<Progress> component is hidden, and the web page loading is complete.

```
// xxx.ets
@Entry
@Component
struct WebComponent {
  @State progress: number = 0;
  @State hideProgress: boolean = true;
  fileAccess: boolean = true;
  controller: WebController = new WebController();
  build() {
    Column() {
      Text('Hello world!')
        .fontSize(20)
      Progress({value: this.progress, total: 100})
        .color('#0000ff')
        .visibility(this.hideProgress ? Visibility.None : Visibility.Visible)
      Web({ src: 'https://www.example.com', controller: this.controller })
        .fileAccess(this.fileAccess)
        .javaScriptAccess(true)
        .height(500)
        .padding(20)
        // Add an onProgressChange event.
        .onProgressChange(e => {
          this.progress = e.newProgress;
          // When the progress reaches 100%, the progress bar disappears.
          if (this.progress === 100) {
            this.hideProgress = true;
          } else {
            this.hideProgress = false;
          }
        })
      Text('End')
        .fontSize(20)
    }
  }
}
```
Add the runJavaScript method to the onPageEnd event. The onPageEnd event is triggered when the web page finishes loading. In this case, the runJavaScript method can be used to execute JavaScript scripts in the HTML file. In the sample code below, when the web page finishes loading, the onPageEnd event is triggered to call the test method in the HTML file and print information on the console.

```
// xxx.ets
@Entry
@Component
struct WebComponent {
  @State progress: number = 0;
  @State hideProgress: boolean = true;
  fileAccess: boolean = true;
  // Define the controller for the \<Web> component.
  controller: WebController = new WebController();
  build() {
    Column() {
      Text('Hello world!')
        .fontSize(20)
      Progress({value: this.progress, total: 100})
        .color('#0000ff')
        .visibility(this.hideProgress ? Visibility.None : Visibility.Visible)
      // Initialize the \<Web> component and bind it to the controller.
      Web({ src: $rawfile('index.html'), controller: this.controller })
        .fileAccess(this.fileAccess)
        .javaScriptAccess(true)
        .height(500)
        .padding(20)
        .onProgressChange(e => {
          this.progress = e.newProgress;
          if (this.progress === 100) {
            this.hideProgress = true;
          } else {
            this.hideProgress = false;
          }
        })
        .onPageEnd(e => {
          // test() is defined in index.html.
          this.controller.runJavaScript({ script: 'test()' });
          console.info('url: ', e.url);
        })
      Text('End')
        .fontSize(20)
    }
  }
}
```

Create an HTML file in main/resources/rawfile.

```
<!-- index.html -->
<!DOCTYPE html>
<html>
<meta charset="utf-8">
<body>
    Hello world!
</body>
<script type="text/javascript">
  function test() {
      console.info('Ark Web Component');
  }
</script>
</html>
```
## Scenario Example

In this example, you'll implement a \<Web> component where videos can be played dynamically. Embed a video resource into an HTML page, and then use the \<Web> component controller to invoke the onActive and onInactive methods to activate and pause page rendering, respectively. When the page is hidden, the \<Web> component stops rendering and the video playback pauses. When the page is displayed, the \<Web> component is activated and the video playback resumes.

  ```
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController();
    build() {
      Column() {
        Web({ src: $rawfile('index.html'), controller: this.controller })
        .fileAccess(true)
      }
    }

    onPageHide() {
      // Invoked when the page is hidden.
      this.controller.onInactive();
    }

    onPageShow() {
      // Invoked when the page is displayed.
      this.controller.onActive();
    }
  }
  ```

  ```
  <!-- index.html -->
  <!DOCTYPE html>
  <html>
  <meta charset="utf-8">
  <body>
      <video width="320" height="240" controls="controls" muted="muted" autoplay="autoplay">
          <!-- The test.mp4 video file is stored in main/resources/rawfile. -->
          <source src="test.mp4" type="video/mp4">
      </video>
  </body>
  </html>
  ```
