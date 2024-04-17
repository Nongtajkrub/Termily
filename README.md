# Termily

**This project is currently still in the testing phase. Right now, it is just a showcase of what Termily can do. I do not recommend using it in a reading project.**

Hello! This is my own C library designed for making games run on the terminal. The current version is 0.02. The latest release was on April 17, 2024. Termily is not cross-platform and can only be used on Windows. There are numerous planned features for the future, including performance updates.

You can contact me at my email, sunanborthwic@gmail.com, or on my [instragram](https://www.instagram.com/nongtajkrub/)

## Set up

First, you need to download the latest version of Termily. You can do this on the [realease page](https://github.com/Nongtajkrub/Termily/releases/tag/0.02-pre_alpha). Go ahead and download the file called termily.rar. After downloading, make a new folder, put the downloaded file into the folder, and then extract the downloaded file. After extracting the file, your folder structure should now be similar to this. 

Folder  
│  
├───termily.rar  
├───Termily  
└───termily.h  

You can now just delete the termily.rar file you downloaded.

Folder  
│  
├───Termily  
└───termily.h  

You can add your own structure file, for example, main.c or app.c.

Folder  
│  
├───Termily  
├───main.c  
└───termily.h  

Then you can program your game in your source file. For a guide on how to use Termily, please visit our [Wiki page](https://github.com/Nongtajkrub/Termily/wiki) (_Wiki page is being work on_).

## Compiling your game

To compile your game, you will also need to compile other source files in the Termily library (_this will change the feature_). Before compiling, make sure that you are in the main directory of your project. For this example, I will use the GCC compiler, but you can also use other compilers.

```
gcc Termily/Graphic/graphic.c Termily/Actor/actor.c Termily/Key/key.c Termily/Mouse/mouse.c Termily/Sound/sound.c (your main c file) -o (your exe name)
```
