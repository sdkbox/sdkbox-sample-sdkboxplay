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

### Test Opt-in

* To test on Android you need to opt-in as an alpha tester [here](https://play.google.com/apps/testing/com.sdkbox.gpg)

SDKBOX samples uses shared cocos2d-x binary to reduce download

## Documentation
For more information, check out the [SDKBOX play plugin](http://docs.sdkbox.com/en/plugins/sdkboxplay/)

## Run

Compile in release mode:

`cocos run -p android -m release`
