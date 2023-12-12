# Robotics Programming and Applications Overview

Dr Narsimlu Kemsaram

Multi-Robot systems
## Table of Contents
1. [Introduction to Robotics](#introduciton-to-robotics)
2. [Robotics in Action](#robotics-in-action)
3. Introduction to Arduino
4. Robotics Programming with Mona Robot
5. Simple Concurrent Programming: Robot Sensing and Control
   

## Introduciton to Robotics
### What is a robot??
A goal-oriented machine that can sense, plan, and act autonomously.

### Sensors and algorithms
sensors: camera Lidar etc
camer - limited vision
lidar more suround vision
algorithms: mapping, path planning, control
hardware: arduino, raspberry pi, jetson nano
correct hardware needed as required processing power and capabilities, amount of i/o
software:
compnonets for robotics:
 * framework
 * platform
 * language
 * simulator
### Framework
#### ROS - Robot Operating System
![ROS](ros.png)
collection of tools, libraries and documentations
ros is more a framework or middleware plus a developer community

2007 - Stanford AI lab (ROS1)
2013 -  managed by Open-Source Robotics Foundation (OSRF)
Present - Standard for Robot Programming
2020 -  ROS2 to adapt new changes in community improving ros 1
not backwards compatiable

ROS 2 distribution
different distributions used for various programs, need to consider distribution used when utliising ros

### Platform for Robotics
Most developers/embedded developers use ubuntu as it can be run on many processors.

### Language 
robotics requre a versatile, efficient and easy to use language:

c++ - compiler
> most common

python - editor

>can be directly used

matlab
>supporst ros network bit is mostly used for computation and is best used by researchers

are the most popular prog languages used in robotics
### Simulations
Gazebo and webots

You can visualise how the robots move and interact with other robots.

## Robotics in Action
* [Autonomous Ground Vehicles (AGVs)](#agvs)
* [Unmanned Arial Vehicles (UAVs)](#uavs)
* Mars Exploration rovers (MERs)
* [Robotics in Medical](#medical-applications)

### AGVs
Utilise a mix of cameras and lidar to map the position of other vehicles. Aslo using the software to follow the car infront without veering.

Paper - A stereo perception framework for autonomous vehicles - 2020 iee vehicular tech conference

### UAVs
Paper - An onboard perception framework for Multi-UAV Systems

detection of other drones in proximity using camera

### swarm robots 
acoustic self actuate multimodal bots for tangible tabletop interactions.
allows for non - physical interactions

### Medical Applications


## Intro to Arduiono
github monarobot

Monda robot is easily adaptable and has a low learning curve

