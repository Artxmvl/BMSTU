#!/bin/bash
echo "type your massege:"
read massage
echo "$massege" | nc localhost 8888
