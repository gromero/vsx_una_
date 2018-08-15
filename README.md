Before refactor: FP + VEC enabled implies VSX enabled

```
~/git/vsx_una_$ make
gcc -O0 -g vsx_una_.c -o vsx_una
gcc -O0 -g vsx_una_.c -DFP -DVEC -o vsx_una_FP_VEC
~/git/vsx_una_$ ./vsx_una; ./vsx_una_FP_VEC 
fail
pass

$ uname -a
Linux gromero16 4.4.0-130-generic #156-Ubuntu SMP Thu Jun 14 08:51:21 UTC 2018 ppc64le ppc64le ppc64le GNU/Linux
```

After refactor: looks like that VSX never causes a Unavailable Exception:
```
~/git/vsx_una_$ ./vsx_una; ./vsx_una_FP_VEC
pass
pass
```
