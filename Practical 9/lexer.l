%{
#include "parser.tab.h"  // Include the header generated by bison
%}

%%
i      return I;
b      return B;
t      return T;
a      return A;
e      return e;
[ \t\n] ; // Ignore whitespace
.      return yytext[0]; // Return any other character
%%

int yywrap() { return 1; }
