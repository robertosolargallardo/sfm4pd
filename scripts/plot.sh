for((t=0;t<$1;t++))
do
	zeros=$(echo "$t $1" | awk -F " " '{for(i=0;i<(length($2)-length($1)-1);i++) printf("%c","0")}')
	echo "set terminal png" > plot.gpi
	echo "set datafile separator ','" >> plot.gpi
	echo "set output 'positions_"$zeros$t".png'" >> plot.gpi
	echo "set xrange [-33.0416:-33.0171]" >> plot.gpi
	echo "set yrange [-71.6594:-71.6171]" >> plot.gpi
	echo "plot 'positions_"$t".txt' u 1:2" >> plot.gpi
	gnuplot plot.gpi
done
rm -f plot.gpi
