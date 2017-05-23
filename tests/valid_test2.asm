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
         LDA     =X'F1'
         sta     LENGTH
         JSuB    WRREC
         LDL     RETADR
         ORG     =x'1000'
         ORG     *
         ORG     endfil-6
         org     *
         RSUB
         LTORG
. THIS IS FUCNKING COMMENT IGNORE IT.
RETADR   RESW    1
BLAH     EQU     RETADR-1
BLAH1    EQU     *
BLAH2    EQU     0x1000
BLAH3    EQU     blah2
BLAH4    EQU     blah3
LENGTH   RESW    1
BUFFER   RESB    4096
RDREC    LDx     =0
         LDA     =0
RLOOP    TD      =X'F1'
         JEQ     RLOOP
         RD      =X'F1'
         COMP    *
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
.this will start execution from second statment
         END     CLOOP               