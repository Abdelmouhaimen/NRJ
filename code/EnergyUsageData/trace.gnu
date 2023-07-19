set xlabel 'Number of operations'
set ylabel 'Energie (J)'
set grid
set logscale x 2
set logscale y
set format y '%h'

plot 'energyAddition_per_N' using 1:2 with linespoints title 'blaz', 'energyAddition_per_N' using 1:3 with linespoints title 'zfp', 'energyAddition_per_N' using 1:4 with linespoints title 'no compression'

plot 'energyMultiplication_per_N' using 1:2 with linespoints title 'blaz', 'energyMultiplication_per_N' using 1:3 with linespoints title 'zfp', 'energyMultiplication_per_N' using 1:4 with linespoints title 'no compression'

plot 'energyMultiplyByC_per_N' using 1:2 with linespoints title 'blaz', 'energyMultiplyByC_per_N' using 1:3 with linespoints title 'zfp', 'energyMultiplyByC_per_N' using 1:4 with linespoints title 'no compression'

plot 'energyDot_per_N' using 1:2 with linespoints title 'blaz', 'energyDot_per_N' using 1:3 with linespoints title 'zfp', 'energyDot_per_N' using 1:4 with linespoints title 'no compression'




plot 'energyAddition_per_N_Values.txt' using 1:2:3 with yerrorlines title 'blaz', 'energyAddition_per_N_Values.txt' using 1:4:5 with yerrorlines title 'zfp', 'energyAddition_per_N_Values.txt' using 1:6:7 with yerrorlines title 'no compression'

plot 'energyMultiplication_per_N_Values.txt' using 1:2:3 with yerrorlines title 'blaz', 'energyMultiplication_per_N_Values.txt' using 1:4:5 with yerrorlines title 'zfp', 'energyMultiplication_per_N_Values.txt' using 1:6:7 with yerrorlines title 'no compression'

plot 'energyMultiplyByC_per_N_Values.txt' using 1:2:3 with yerrorlines title 'blaz', 'energyMultiplyByC_per_N_Values.txt' using 1:4:5 with yerrorlines title 'zfp', 'energyMultiplyByC_per_N_Values.txt' using 1:6:7 with yerrorlines title 'no compression'

plot 'energyDot_per_N_Values.txt' using 1:2:3 with yerrorlines title 'blaz', 'energyDot_per_N_Values.txt' using 1:4:5 with yerrorlines title 'zfp', 'energyDot_per_N_Values.txt' using 1:6:7 with yerrorlines title 'no compression'


plot 'energyChainedAdditions_per_N.txt' using 1:2:3 with yerrorlines title 'blaz', 'energyChainedAdditions_per_N.txt' using 1:4:5 with yerrorlines title 'zfp', 'energyChainedAdditions_per_N.txt' using 1:6:7 with yerrorlines title 'no compression'

plot 'energyChainedAdditionsMultiplications_per_N.txt' using 1:2:3 with yerrorlines title 'blaz', 'energyChainedAdditionsMultiplications_per_N.txt' using 1:4:5 with yerrorlines title 'zfp', 'energyChainedAdditionsMultiplications_per_N.txt' using 1:6:7 with yerrorlines title 'no compression'

