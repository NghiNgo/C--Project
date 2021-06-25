# About Traffic Control Management

The project source code consists of two cpp files( main.cpp and caliberate.cpp) and a user defined header file(caleberate.h). The main.cpp file in the source code integrates all files and makes do the designed task of the project.

In Traffic Control Management System, the major function of user defined header file is to make the system capture the video of the traffic lanes and to analyze them. The caliberate.cpp receives the analyzed data of running traffic and it takes the appropriate decision for traffic control.

The application detects traffic by using opencv. The algorithm provides necessary traffic information required for analysis and decision making in traffic management. The major information to be detected and analyzed for traffic management by this application are:

- Average movement of vehicles

- Percentage of area covered by vehicles on the road

This software analyses the traffic for each lane decides to divide the traffic based on type of vehicle. In order to reduce traffic congestion, the small vehicles are moved in one lane and heavier vehicle vehicles are moved in other.

Before the installation of application in road, it needs to be tested. In road, the application first captures video of running traffic and analyzes, but while testing on computer the video file may not present. So, follow the steps given below:-

- Place a video file in same directory of executable file.

- Rename the video file as “traffic.avi”

- Build and Run the code.

- In “Draw Polygon” Window choose four points.

After performing these steps, the Traffic Control Management application separates the lanes for respective type of vehicles as per algorithm embedded in the code. Finally, you will see a console output of separated lane as shown below.

The conventional way of controlling traffic at junctions and other sectors of urban road is growing ineffective with the passage of time due to increase in the number of vehicles on road. At a busy junction, it is really a very complex task for a single traffic police to pass all the vehicles safely.