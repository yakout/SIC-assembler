COPY     START   0x1000
FIRST    STL     ENDFIL
CLOOP    JSUB    RDREC
         LDA     *
         COMP    =c'ajdd'
test     equ     zero+1
test2    equ     *
         JEQ     ENDFIL
seCond   equ     first
         JSUB    WRREC
         J       CLOOP
         ltorg
ENDFIL   LDA     EOF
         STA     =x'4535'
test3    equ     *
         LDA     ENDFIL
         STA     =3
         org     EndFil
         JSUB    =x'45'
         LDL     =65
         RSUB
         ltorg
EOF      BYTE    C'EOF'
THREE    WORD    3
ZERO     WORD    0
RETADR   RESW    1
LENGTH   RESW    1
BUFFER   RESW    4096
RDREC    LDX     ZERO
         LDA     ZERO
RLOOP    TD      *
         org     eof
         org     0x1000
         JEQ     RLOOP
         RD      INPUT
         COMP    ZERO
         JEQ     *
         STCH    BUFFER,X
         org
         TIX     =3
         JLT     RLOOP
EXIT     STX     =45
         RSUB
INPUT    BYTE    X'F1'
MAXLEN   WORD    4096
WRREC    LDX     ZERO
WLOOP    TD      OUTPUT
         JEQ     =34
         LDCH    BUFFER,X
         WD      OUTPUT
         TIX     LENGTH
         JLT     WLOOP
         RSUB
OUTPUT   BYTE    X'05'
         END     FIRST