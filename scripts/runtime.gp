reset

set xlabel 'prefix'
set ylabel 'time (sec)'
set title 'perfomance comparison'
set terminal png font " Times_New_Roman,10 "
set output 'runtime.png'

stat 'bench_cpy.txt' using 2 name 'CPY'
stat 'bench_ref.txt' using 2 name 'REF'


plot [0:700][0:0.0004]\
'bench_cpy.txt' using 1:2 with points title 'cpy',\
CPY_mean lt 1,\
'bench_ref.txt' using 1:2 with points title 'ref',\
REF_mean lt 2
