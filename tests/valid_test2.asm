COPY     StArT   0x1000             this is just a comment
FIRST    STL     RETADR
CLOOP    JSUB    RDREC
         LDA     LENGTH
         COMP    =0
         JEQ     ENDFIL
         JSuB    WRREC
         J       CLOOP
ENDFIL   LDA     =C'EOF'
         STA     BUFFER
         LDA     =3
         sta     LENGTH
         JSuB    WRREC
         LDL     RETADR
         RSUB
         LTORG
RETADR   RESW    1
FUCK     EQU     *
FUCK1    EQU     FUCK
LENGTH   RESW    1
BUFFER   RESB    4096
RDREC    LDx     =0
         LDA     =0
RLOOP    TD      =X'F1'
         JEQ     RLOOP
         RD      =X'F1'
         COMP    =0
         JEQ     EXIT
         STCH    BUFFER,X
         TIX     =4096
         JLT     RLOOP
EXIT     STX     LENGTH
         RSUB
WRREC    LDX     =0
WLOOP    TD      OUTPUT
         JEQ     WLOOP
         LDCH    BUFFER,X
         WD      OUTPUT
         TIX     LENGTH
         JLT     WLOOP
         RSUB
OUTPUT   BYTE    X'05'
         END     COPY
         END     COPY