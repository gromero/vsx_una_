vsx_una_: vsx_una_.c
	gcc -O0 -g vsx_una_.c -o vsx_una
	gcc -O0 -g vsx_una_.c -DFP -DVEC -o vsx_una_FP_VEC

clean:
	rm -fr *.o vsx_una vsx_una_FP_VEC
