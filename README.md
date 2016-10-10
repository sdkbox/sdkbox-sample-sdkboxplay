# sdkbox-sample-sdkboxplay

## Getting Started

Run setup script and it will automatically download it's dependencies

~~~bash
./setup
~~~

If the setup script runs correctly the folder structure should look like this

~~~
+-- sdkbox-cocos2d-x-binary
+-- sdkbox-sample-iap
| +-- cpp
| +-- lua
| \-- js
~~~

SDKBOX samples uses shared cocos2d-x binary to reduce download

## Documentation
For more information, check out the [SDKBOX play plugin](http://docs.sdkbox.com/en/plugins/sdkboxplay/)

### Test IAP for android

* To test Android IAP you need to opt-in as an alpha tester [here](https://play.google.com/apps/testing/com.sdkbox.gpg)

## Run

Compile in release mode:

`cocos run -p android -m release`
