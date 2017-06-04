#!/bin/bash

gnuplot -e "set xl 'R';
            set yl 'Density';
            set zl 'Dimension';
            splot '$1';
            pause -1"

# gnuplot -e "set xl 'log(R_g)';
#             set yl 'log(N)';
            # f(x)=a*x+b;
            # fit [] [1.3:] f(x) '$1' via a, b;
            # plot '$1' with p pt 6, f(x);
