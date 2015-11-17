#!/bin/bash

# User right bug in Raspbian, 
# this script is a quickfix for now...

echo 17 > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio17/direction 
chown :gpio /sys/class/gpio/gpio17/*
chmod g+w /sys/class/gpio/gpio17/*

