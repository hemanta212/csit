
# Table of Contents

1.  [REGISTERS](#orgb6f194b)
2.  [Memory](#org4461baa)
3.  [Commands](#org533d759)
    1.  [MOV](#org462954e)
    2.  [MVI](#org4453613)
    3.  [ADD/ADI](#org6ffe950)
    4.  [SUB/SUI](#org7c74515)
    5.  [STA](#org69a7ec0)
    6.  [LDA](#orga59471b)
    7.  [INR](#orge791b87)
    8.  [DCR](#org8e3501b)
    9.  [OUT](#orgf2cc72e)
    10. [LXI](#orgcf635e5)
    11. [FLags](#org2d56e7e)
    12. [Program Adder](#org31aa1e7)
        1.  [SIMPLE](#org60ff617)
        2.  [Memory dynamic](#orgd1ad0ba)
4.  [INX/DCX](#orgf5e11dd)
5.  [RRC/RAR](#org9464684)
6.  [CMP/CPI](#org1cd399f)


<a id="orgb6f194b"></a>

# REGISTERS


<a id="org4461baa"></a>

# Memory

<table border="2" cellspacing="0" cellpadding="6" rules="groups" frame="hsides">


<colgroup>
<col  class="org-left" />

<col  class="org-left" />
</colgroup>
<tbody>
<tr>
<td class="org-left">Address</td>
<td class="org-left">data</td>
</tr>


<tr>
<td class="org-left">0234H</td>
<td class="org-left">23H</td>
</tr>


<tr>
<td class="org-left">4456H</td>
<td class="org-left">33H</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>
</tbody>
</table>


<a id="org533d759"></a>

# Commands


<a id="org462954e"></a>

## MOV

    rm -rf /tmp/8085-session1

    inspect

    Registers:
    	A: 0x00
    	B: 0x00
    	C: 0x00
    	D: 0x00
    	E: 0x00
    	H: 0x00
    	L: 0x00
    	M: 0x00

    Memory:
    	0x0000: 0x33
    	0x0001: 0x9A
    	0x000A: 0x2B
    	0x000B: 0x34

    Flags:
    	carry: 0
    	auxillary_carry: 0
    	zero: 0
    	sign: 0


<a id="org4453613"></a>

## MVI

    MVI A 03H

    A -> 03H

    inspect

    Registers:
    	A: 0x03
    	B: 0x00
    	C: 0x00
    	D: 0x00
    	E: 0x00
    	H: 0x00
    	L: 0x00
    	M: 0x00

    Memory:
    	0x0000: 0x33
    	0x0001: 0x9A
    	0x000A: 0x2B
    	0x000B: 0x34

    Flags:
    	carry: 0
    	auxillary_carry: 0
    	zero: 0
    	sign: 0

    MOV B A
    MOV C A

    B -> 03H [From A]
    C -> 03H [From A]


<a id="org6ffe950"></a>

## ADD/ADI

    inspect

    Registers:
    	A: 0x03
    	B: 0x03
    	C: 0x03
    	D: 0x00
    	E: 0x00
    	H: 0x00
    	L: 0x00
    	M: 0x00

    Memory:
    	0x0000: 0x33
    	0x0001: 0x9A
    	0x000A: 0x2B
    	0x000B: 0x34

    Flags:
    	carry: 0
    	auxillary_carry: 0
    	zero: 0
    	sign: 0

    ADD B

    A -> 03H + 03H -> 6H


<a id="org7c74515"></a>

## SUB/SUI


<a id="org69a7ec0"></a>

## STA

    inspect

    Registers:
    	A: 0x6
    	B: 0x03
    	C: 0x03
    	D: 0x00
    	E: 0x00
    	H: 0x00
    	L: 0x00
    	M: 0x00

    Memory:
    	0x0000: 0x33
    	0x0001: 0x9A
    	0x000A: 0x2B
    	0x000B: 0x34

    Flags:
    	carry: 0
    	auxillary_carry: 0
    	zero: 0
    	sign: 0

    STA 3344H

    3344H -> 6H


<a id="orga59471b"></a>

## LDA

    inspect

    Registers:
    	A: 0x6
    	B: 0x03
    	C: 0x03
    	D: 0x00
    	E: 0x00
    	H: 0x00
    	L: 0x00
    	M: 0x00

    Memory:
    	0x0000: 0x33
    	0x0001: 0x9A
    	0x000A: 0x2B
    	0x000B: 0x34
    	0x3344: 0x6

    Flags:
    	carry: 0
    	auxillary_carry: 0
    	zero: 0
    	sign: 0

    LDA 0001H

    A -> 9AH [From 0001H]


<a id="orge791b87"></a>

## INR

Increment Register

    INR A

    A -> 9AH + 1H -> 9BH


<a id="org8e3501b"></a>

## DCR


<a id="orgf2cc72e"></a>

## OUT

    OUT PORT0
    OUT PORT1


<a id="orgcf635e5"></a>

## LXI

    LXI H 3344H

    H -> 0x33
    L -> 0x44

    inspect

    MVI A 05
    STA 1264H

    A -> 05H
    1264H -> 05H


<a id="org2d56e7e"></a>

## FLags

Flags are one bit stuff that stores the status of **lastest** execution

<table border="2" cellspacing="0" cellpadding="6" rules="groups" frame="hsides">


<colgroup>
<col  class="org-left" />

<col  class="org-left" />
</colgroup>
<tbody>
<tr>
<td class="org-left">flags</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-left">Z</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-left">C</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-left">aux c</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-left">par</td>
<td class="org-left">&#xa0;</td>
</tr>
</tbody>
</table>

    MVI A 04
    STA 1260H

    A -> 04H
    1260H -> 04H

    MVI A 00H
    LDA 1260H

    A -> 00H
    A -> 04H [From 1260H]


<a id="org31aa1e7"></a>

## Program Adder


<a id="org60ff617"></a>

### SIMPLE

    inspect

    Registers:
    	A: 0x04
    	B: 0x03
    	C: 0x03
    	D: 0x00
    	E: 0x00
    	H: 0x33
    	L: 0x44
    	M: 0x6

    Memory:
    	0x0000: 0x33
    	0x0001: 0x9A
    	0x000A: 0x2B
    	0x000B: 0x34
    	0x3344: 0x6
    	0x1264: 0x05
    	0x1260: 0x04

    Flags:
    	carry: 0
    	auxillary_carry: 0
    	zero: 0
    	sign: 0

    MVI A 00H
    MVI B 05H
    FIRST: ADI 01
           DCR B
           JNZ FIRST

    A -> 00H
    B -> 05H
    A -> 00H + 01H -> 1H
    B -> 05H - 1H -> 4H
    A -> 1H + 01H -> 2H
    B -> 4H - 1H -> 3H
    A -> 2H + 01H -> 3H
    B -> 3H - 1H -> 2H
    A -> 3H + 01H -> 4H
    B -> 2H - 1H -> 1H
    A -> 4H + 01H -> 5H
    B -> 1H - 1H -> 0H

    inspect

    Registers:
            A: 0x5
            B: 0x0
            C: 0x03
            D: 0x00
            E: 0x00
            H: 0x33
            L: 0x44
            M: 0x6

    Memory:
            0x0000: 0x33
            0x0001: 0x9A
            0x000A: 0x2B
            0x000B: 0x34
            0x3344: 0x6
            0x1264: 0x05
            0x1260: 0x04

    Flags:
            carry: 0
            auxillary_carry: 0
            zero: 0
            sign: 0


<a id="orgd1ad0ba"></a>

### Memory dynamic

-   Wap to add five bytes of memory and store it in some other memory

    MVI A 00H
    MVI B 05H
    LXI H 1260H
    FIRST: ADD M
           INR L
           DCR B
           JNZ FIRST

    A -> 00H
    B -> 05H
    H -> 0x12
    L -> 0x60
    A -> 00H + 04H -> 4H
    L -> 60H + 1H -> 61H
    B -> 05H - 1H -> 4H
    A -> 4H + 04H -> 8H
    L -> 61H + 1H -> 62H
    B -> 4H - 1H -> 3H
    A -> 8H + 04H -> CH
    L -> 62H + 1H -> 63H
    B -> 3H - 1H -> 2H
    A -> CH + 04H -> 10H
    L -> 63H + 1H -> 64H
    B -> 2H - 1H -> 1H
    A -> 10H + 04H -> 14H
    L -> 64H + 1H -> 65H
    B -> 1H - 1H -> 0H

    A -> 02H
    C -> 04H
    A -> 02H - 04H -> 2H
    FLAGS: CY->1, S->1, Z->0

-   Wap to add five bytes of memory and store it in some other memory

    MVI B 04H
    LXI H 1260H
    MOV C M
    LXI H 1261H
    BACK: MOV A M
                 SUB C
                 JNC NEXT
                 MOV C A
    NEXT: INX H
                 DCR B
                 JNZ BACK

    B -> 04H
    H -> 0x12
    L -> 0x60
    C -> 04H [From M]
    H -> 0x12
    L -> 0x61
    A -> 00H [From M]
    A -> 00H - 04H -> 4H
    FLAGS: CY->1, S->1, Z->0
    C -> 4H [From A]
    B -> 04H - 1H -> 3H
    A -> 00H [From M]
    A -> 00H - 4H -> 4H
    FLAGS: CY->1, S->1, Z->0
    C -> 4H [From A]
    B -> 3H - 1H -> 2H
    A -> 00H [From M]
    A -> 00H - 4H -> 4H
    FLAGS: CY->1, S->1, Z->0
    C -> 4H [From A]
    B -> 2H - 1H -> 1H
    A -> 00H [From M]
    A -> 00H - 4H -> 4H
    FLAGS: CY->1, S->1, Z->0
    C -> 4H [From A]
    B -> 1H - 1H -> 0H


<a id="orgf5e11dd"></a>

# INX/DCX


<a id="org9464684"></a>

# RRC/RAR


<a id="org1cd399f"></a>

# CMP/CPI

CMP B
CPI 05  A > B, no carry
              A < B : carry
              A == B : no carry, zero flag
