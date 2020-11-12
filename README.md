# Group 32 Project: Habari

Widget for weather, stocks, and news. Made with passion using QT and C++.

## Project Update - Stage 3
For this stage, we emphasized getting the overall structure of the app finished, as well as implementing functionality for viewing Weather data.
We changed the number of story points for several of our user stories, as we found that implementing a GUI in QT and similar tasks took longer than expected, and others took shorter than expected. 
We also made the following changes to user stories
- Added a story giving a SPIKE to figuring out charting in QT - this is essential for displaying stock information
- Merged our stories on navigating to the home back and navigating the previous page into one: we found that these are essentially identical. 



## Building

#### Raspberry Pi
To build this application, please run the following commands. We have included an executable file, but in the case that it does not work (generally due to hardware non-compatibility) the following commands will build our app from source:
```
sudo apt-get update
sudo apt-get install qt5-default
sudo apt install libqt5charts5 libqt5charts5-dev
qmake
make
```
## Running
To run our app, run:
````
./3307_App
````
