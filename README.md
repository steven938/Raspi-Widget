
Widget for weather, stocks, and news. Made with passion using QT and C++.

## Project Update - Stage 4

We also made the following changes to user stories
- One feature, the display of 24-hour weather, was not implemented because we were unable to get the API to work with both daily and hourly weather. 
- The user story for Weather that involved selecting a specific time period to view was modified because the Weather API only allows us to get 5 days of data after the present 

Some usage instructions:
- When searching for weather: for cities that share names (e.g. London Canada vs London England), use the country code for the "less significant city" (e.g. London, CA)




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
