set xlabel 'N'
set ylabel 'Energie (J)'
set grid
set logscale x 2
set logscale y
set format y '%h'
plot 'energyAddition_per_N' using 1:2 with linespoints title 'blaz', 'energyAddition_per_N' using 1:3 with linespoints title 'zfp'

plot 'energyMultiplication_per_N' using 1:2 with linespoints title 'blaz', 'energyMultiplication_per_N' using 1:3 with linespoints title 'zfp'
