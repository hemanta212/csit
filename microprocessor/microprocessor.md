
# Table of Contents

1.  [REGISTERS](#org08c42e3)
2.  [Memory](#org746ca99)
3.  [Commands](#orgff3ac13)
    1.  [MOV](#org7fd4817)
    2.  [MVI](#org7f31044)
    3.  [ADD/ADI](#org687cfaa)
    4.  [SUB/SUI](#orgf7cd3fd)
    5.  [STA](#org9ae3518)
    6.  [LDA](#orgdafe1cd)
    7.  [INR](#org1b954cd)
    8.  [DCR](#orga5fc951)
    9.  [OUT](#org7b50bec)
    10. [LXI](#org8027d2d)
    11. [FLags](#orgf62ea52)
    12. [Program Adder](#org290b26a)
        1.  [SIMPLE](#org9a89fc9)
        2.  [Memory dynamic](#org2d29df3)
4.  [INX/DCX](#orgb2f5188)
5.  [RRC/RAR](#orgd908cf5)
6.  [CMP/CPI](#orge00e80f)


<a id="org08c42e3"></a>

# REGISTERS


<a id="org746ca99"></a>

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


<a id="orgff3ac13"></a>

# Commands


<a id="org7fd4817"></a>

## MOV

    inspect


<a id="org7f31044"></a>

## MVI

    MVI A 03H

    inspect

    MOV B A
    MOV C A


<a id="org687cfaa"></a>

## ADD/ADI

    inspect

    ADD B


<a id="orgf7cd3fd"></a>

## SUB/SUI


<a id="org9ae3518"></a>

## STA

    inspect

    STA 3344H


<a id="orgdafe1cd"></a>

## LDA

    inspect

    LDA 0001H


<a id="org1b954cd"></a>

## INR

Increment Register

    INR A


<a id="orga5fc951"></a>

## DCR


<a id="org7b50bec"></a>

## OUT

    OUT PORT0
    OUT PORT1


<a id="org8027d2d"></a>

## LXI

    LXI H 3344H

    inspect

    MVI A 05
    STA 1264H


<a id="orgf62ea52"></a>

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

    MVI A 00H
    LDA 1260H


<a id="org290b26a"></a>

## Program Adder


<a id="org9a89fc9"></a>

### SIMPLE

    inspect

    MVI A 00H
    MVI B 05H
    FIRST: ADI 01
           DCR B
           JNZ FIRST

    inspect


<a id="org2d29df3"></a>

### Memory dynamic

-   Wap to add five bytes of memory and store it in some other memory

        MVI A 00H
        MVI B 05H
        LXI H 1260H
        FIRST: ADD M
               INR L
               DCR B
               JNZ FIRST

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


<a id="orgb2f5188"></a>

# INX/DCX


<a id="orgd908cf5"></a>

# RRC/RAR


<a id="orge00e80f"></a>

# CMP/CPI

CMP B
CPI 05  A > B, no carry
              A < B : carry
              A == B : no carry, zero flag
