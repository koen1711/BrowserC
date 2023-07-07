# Browser in C++


- [Browser in C++](#browser-in-c)
  - [Dependencies](#dependencies)
  - [Building](#building)
  - [Using the WPE port](#using-the-wpe-port)


## Dependencies
---

This Browser aims to make it very clear which libraries you need and how to install them by with each library adding them for you with your build of extern/


## Building
---

You should be good by just running cmake --build . and you are good to go!

It should be noted that is expected that you have basic knowledge of CMake and C++ while working on this browser,
if you don't have this knowledge you could find yourself running into walls by,
for example not knowing how pointers work and mismatching the problem to the right solution.


## Using the WPE port
---

By default, we use the GTK+ port of WebKit, of course you can change this.
You would have to figure that out on your owm if you want to find that.

Installing Webkit:
`sudo apt install libwebkit2gtk-4.0-37`