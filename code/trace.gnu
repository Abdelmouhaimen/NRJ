set xlabel 'N'
set ylabel 'Energie (J)'
set grid
set logscale x 2
set logscale y
set format y '%h'

plot 'energyAddition_per_N' using 1:2 with linespoints title 'blaz', 'energyAddition_per_N' using 1:3 with linespoints title 'zfp', 'energyAddition_per_N' using 1:4 with linespoints title 'no compression'

plot 'energyMultiplication_per_N' using 1:2 with linespoints title 'blaz', 'energyMultiplication_per_N' using 1:3 with linespoints title 'zfp', 'energyMultiplication_per_N' using 1:4 with linespoints title 'no compression'


plot 'energyMultiplyByC_per_N' using 1:2 with linespoints title 'blaz', 'energyMultiplyByC_per_N' using 1:3 with linespoints title 'zfp', 'energyMultiplyByC_per_N' using 1:4 with linespoints title 'no compression'
