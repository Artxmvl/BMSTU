#!/bin/bash
ps
echo "number of processes: $(($(ps | wc -l) - 1))"


