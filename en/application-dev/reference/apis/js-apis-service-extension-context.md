# ServiceExtensionContext

> ![icon-note.gif](public_sys-resources/icon-note.gif) **Note:**
> The initial APIs of this module are supported since API 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


Implements the context that provides the capabilities and APIs of **ServiceExtension**. This class is inherited from **ExtensionContext**.


## startAbility


startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void;


Starts an ability. This method uses a callback to return the result.


- Parameters
  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | want | [Want](js-apis-featureAbility.md#Want)| Yes| Information about the ability to start, such as the ability name and bundle name.| 
  | callback | AsyncCallback&lt;void&gt; | No| Callback used to return the result indicating whether the method is successfully called.| 

- Example
  ```
  let want = {
      "bundleName": "com.example.myapp",
      "abilityName": "com.example.myapp.MyAbility"
  };
  this.context.startAbility(want, (err) => {
      console.log('startAbility result:' + JSON.stringfy(err);
  }  
  ```


## startAbility

startAbility(want: Want): Promise&lt;void&gt;;

Starts an ability. This method uses a promise to return the result.

- Parameters
  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | want | [Want](js-apis-featureAbility.md#Want)| Yes| Information about the ability to start, such as the ability name and bundle name.| 

- Return value
  | Type| Description| 
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return the result indicating whether the method is successfully called.| 

- Example
  ```
  let want = {
      "bundleName": "com.example.myapp",
      "abilityName": "com.example.myapp.MyAbility"
  };
  this.context.startAbility(want).then((data) => {
      console.log('success:' + JSON.stringfy(data));
  )).catch((error) => {
      console.log('failed:' + JSON.stringfy(error));
  });
  ```


## terminateSelf

terminateSelf(callback: AsyncCallback&lt;void&gt;): void;

Terminates this ability. This method uses a callback to return the result.

- Parameters
  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | No| Callback used to return the result indicating whether the method is successfully called.| 

- Example
  ```
  this.context.terminateSelf((err) => {
      console.log('terminateSelf result:' + JSON.stringfy(err);
  }
  ```


## terminateSelf

terminateSelf(): Promise&lt;void&gt;;

Terminates this ability. This method uses a promise to return the result.

- Return value
  | Type| Description| 
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return the result indicating whether the method is successfully called.| 

- Example
  ```
  this.context.terminateSelf(want).then((data) => {
      console.log('success:' + JSON.stringfy(data));
  )).catch((error) => {
      console.log('failed:' + JSON.stringfy(error));
  });
  ```


## connectAbility

connectAbility(want: Want, options: ConnectOptions): number;

Connects this ability to a Service ability.

- Parameters
  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | want | [Want](js-apis-featureAbility.md#Want)| Yes| Information about the ability to connect to, such as the ability name and bundle name.| 
  | options | [ConnectOptions](#connectoptions) | Yes| Callback used to return the information indicating that the connection is successful, interrupted, or failed.| 

- Return value
  | Type| Description| 
  | -------- | -------- |
  | number | A number, based on which the connection will be interrupted.| 

- Example
  ```
  let want = {
      "bundleName": "com.example.myapp",
      "abilityName": "com.example.myapp.MyAbility"
  };
  let options = {
      onConnect: function(elementName, proxy) {}
      onDisConnect: function(elementName) {}
      onFailed: function(code) {}
  }
  let connection = this.context.connectAbility(want,options);
  ```


## disconnectAbility

disconnectAbility(connection: number, callback:AsyncCallback&lt;void&gt;): void;

Disconnects this ability from the Service ability. This method uses a callback to return the result.

- Parameters
  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | connection | number | Yes| Number returned after **connectAbility** is called.| 
  | callback | AsyncCallback&lt;void&gt; | No| Callback used to return the result indicating whether the method is successfully called.| 

- Example
  ```
  this.context.disconnectAbility(connection, (err) => { // connection is the return value of connectAbility.
      console.log('terminateSelf result:' + JSON.stringfy(err);
  }
  ```


## disconnectAbility

disconnectAbility(connection: number): Promise&lt;void&gt;;

Disconnects this ability from the Service ability. This method uses a promise to return the result.

- Parameters
  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | connection | number | Yes| Number returned after **connectAbility** is called.| 

- Return value
  | Type| Description| 
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return the result indicating whether the method is successfully called.| 

- Example
  ```
  this.context.disconnectAbility(connection).then((data) => { // connection is the return value of connectAbility.
      console.log('success:' + JSON.stringfy(data));
  )).catch((error) => {
      console.log('failed:' + JSON.stringfy(error));
  });
  ```


## ConnectOptions

Defines the **ConnectOptions** data structure.

| Name| Description| 
| -------- | -------- |
| onConnect(elementName:ElementName,&nbsp;remote:IRemoteObject) | Called when this ability is connected to a Service ability.| 
| onDisconnect(elementName:ElementName) | Called when the peer service is abnormal or killed.| 
| onFailed(code:&nbsp;number) | Called when the connection fails.| 
