/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_RULES_TAB_H_INCLUDED
# define YY_YY_RULES_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INTEGERSYM = 258,              /* INTEGERSYM  */
    REALSYM = 259,                 /* REALSYM  */
    STRINGSYM = 260,               /* STRINGSYM  */
    UNDEFIDENTSYM = 261,           /* UNDEFIDENTSYM  */
    VARIDENTSYM = 262,             /* VARIDENTSYM  */
    ATTRIDENTSYM = 263,            /* ATTRIDENTSYM  */
    CONSTIDENTSYM = 264,           /* CONSTIDENTSYM  */
    TAGIDENTSYM = 265,             /* TAGIDENTSYM  */
    CHECKIDENTSYM = 266,           /* CHECKIDENTSYM  */
    LOOKUPIDENTSYM = 267,          /* LOOKUPIDENTSYM  */
    LABELIDENTSYM = 268,           /* LABELIDENTSYM  */
    EDITIDENTSYM = 269,            /* EDITIDENTSYM  */
    HELPIDENTSYM = 270,            /* HELPIDENTSYM  */
    ACCEPTIDENTSYM = 271,          /* ACCEPTIDENTSYM  */
    RULEIDENTSYM = 272,            /* RULEIDENTSYM  */
    RULEELEMENTIDENTSYM = 273,     /* RULEELEMENTIDENTSYM  */
    UNDEFIDENTSYMAT = 274,         /* UNDEFIDENTSYMAT  */
    RULEIDENTSYMAT = 275,          /* RULEIDENTSYMAT  */
    FUNCIDENTSYM = 276,            /* FUNCIDENTSYM  */
    METHIDENTSYM = 277,            /* METHIDENTSYM  */
    ARROWSYM = 278,                /* ARROWSYM  */
    PROBSYM = 279,                 /* PROBSYM  */
    FORALLSYM = 280,               /* FORALLSYM  */
    EXISTSYM = 281,                /* EXISTSYM  */
    IFSYM = 282,                   /* IFSYM  */
    THENSYM = 283,                 /* THENSYM  */
    ELSESYM = 284,                 /* ELSESYM  */
    ENDSYM = 285,                  /* ENDSYM  */
    CONSTSYM = 286,                /* CONSTSYM  */
    GOTOSYM = 287,                 /* GOTOSYM  */
    MARKSYM = 288,                 /* MARKSYM  */
    CORRSYM = 289,                 /* CORRSYM  */
    JUMPSYM = 290,                 /* JUMPSYM  */
    INFOSYM = 291,                 /* INFOSYM  */
    CATEGORYSYM = 292,             /* CATEGORYSYM  */
    ACTIONSYM = 293,               /* ACTIONSYM  */
    DETECTSYM = 294,               /* DETECTSYM  */
    ACCEPTSYM = 295,               /* ACCEPTSYM  */
    LINKSYM = 296,                 /* LINKSYM  */
    ENDLEFTCONTEXTSYM = 297,       /* ENDLEFTCONTEXTSYM  */
    BEGINRIGHTCONTEXTSYM = 298,    /* BEGINRIGHTCONTEXTSYM  */
    ASSIGNSYM = 299,               /* ASSIGNSYM  */
    NESYM = 300,                   /* NESYM  */
    LESYM = 301,                   /* LESYM  */
    GESYM = 302,                   /* GESYM  */
    NEG = 303                      /* NEG  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 110 "rules.y"
 
  double real;
  int integer;
  IdEntry *identifier;
  MethodOrFunctionEntry *methodorfunction;
  GotoEntry *gotoentry;
  char *string;
  Expr *node;
  Rule *rule;
  RuleTerm *ruleTerm;
  Element *element;

#line 125 "rules.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_RULES_TAB_H_INCLUDED  */
