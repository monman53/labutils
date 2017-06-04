#!/bin/bash

gnuplot -e "set logscale xy; set xl 'ε'; set yl 'N'; plot '$1' with p pt 6; pause -1"
