set terminal png size 1024,1024
set output './plots/bif-random.png'

set pointsize 0.01
set xrange [3:4]
plot "./out/bif-random.dat" u 1:2 w p ls 1 notitle