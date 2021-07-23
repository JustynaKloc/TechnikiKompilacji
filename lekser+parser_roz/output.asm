        jump.i  #lab0                   ;jump.i  lab0
mul:
        enter.i #4                      ;enter.i 4
        mul.i   #2,*BP+12,BP-4          ;mul.i   2,a,$t0
        mov.i   BP-4,*BP+8              ;mov.i   $t0,mul
        leave                           ;leave   
        return                          ;return  
sum:
        enter.i #4                      ;enter.i 4
        add.i   *BP+16,*BP+12,BP-4      ;add.i   a,b,$t1
        mov.i   BP-4,*BP+8              ;mov.i   $t1,sum
        leave                           ;leave   
        return                          ;return  
lab0:
        mov.i   #1,24                   ;mov.i   1,$t2
        push.i  #24                     ;push.i  &$t2
        mov.i   #2,28                   ;mov.i   2,$t3
        push.i  #28                     ;push.i  &$t3
        push.i  #32                     ;push.i  &$t4
        call.i  #sum                    ;call.i  &sum
        incsp.i #12                     ;incsp.i 12
        mov.i   #3,36                   ;mov.i   3,$t5
        push.i  #36                     ;push.i  &$t5
        mov.i   #4,40                   ;mov.i   4,$t6
        push.i  #40                     ;push.i  &$t6
        push.i  #44                     ;push.i  &$t7
        call.i  #sum                    ;call.i  &sum
        incsp.i #12                     ;incsp.i 12
        push.i  #32                     ;push.i  &$t4
        push.i  #44                     ;push.i  &$t7
        push.i  #48                     ;push.i  &$t8
        call.i  #sum                    ;call.i  &sum
        incsp.i #12                     ;incsp.i 12
        mov.i   48,0                    ;mov.i   $t8,x
        write.i 0                       ;write.i x
        exit                            ;exit    
